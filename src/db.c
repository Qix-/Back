/* Back database functionality */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <leveldb/c.h>
#include "back.h"
#include "db.h"
#include "str.h"

#define BACK_DB_DIR ".back"

struct back_db {
  leveldb_t* ldb;
  const char* rootpath;
  const char* dbpath;
};

back_db* back_db_open(void) {
  // Try to find the database location
  char* dbdir = back_db_find(BACK_DB_DIR);
  if (dbdir == 0) {
    BACK_LOG("initializing database in " BACK_DB_DIR);
    dbdir = strdup(BACK_DB_DIR);
  }

  char* basedir = dirnamep(dbdir);
  BACK_LOGF("based in %s", basedir);

  back_db* db = malloc(sizeof(back_db));
  if (!db) {
    BACK_ERR("could not allocate database");
    goto dealloc_dbname;
  }

  memset(db, 0, sizeof(back_db));

  db->rootpath = basedir;
  db->dbpath = strdup(dbdir); // The original is free'd by leveldb

  leveldb_options_t* options = leveldb_options_create();
  leveldb_options_set_create_if_missing(options, 1);

  char* err = 0;
  db->ldb = leveldb_open(options, dbdir, &err);
  leveldb_options_destroy(options);
  if (err) {
    BACK_ERRF("could not open database: %s", err);
    leveldb_free(err);
    goto dealloc_db;
  }

  goto ret;
dealloc_db:
  free(db);
dealloc_dbname:
  free(dbdir);
  free(basedir);
ret:
  return db;
}

void back_db_close(back_db* db) {
  leveldb_close(db->ldb);
  free((void*) db->rootpath);
  free((void*) db->dbpath);
  free(db);
}

int back_db_set(back_db* db, char* key, char* val) {
  char* err = 0;
  leveldb_writeoptions_t* woptions = leveldb_writeoptions_create();
  leveldb_put(
      db->ldb,
      woptions,
      key, strlen(key),
      val, strlen(val),
      &err);

  leveldb_writeoptions_destroy(woptions);

  if (err) {
    BACK_ERRF("could not set database value '%s': %s", key, err);
    leveldb_free(err);
    return 0;
  }

  return 1;
}

int back_db_set_int(back_db* db, char* key, long int i) {
  char buf[50]; // probably overkill, but w/e
  sprintf(&buf[0], "%ld", i);

  return back_db_set(
      db,
      key,
      &buf[0]
      );
}

int back_db_get(back_db* db, char* key, char** outstr) {
  size_t readlen = 0;
  char* err = 0;
  leveldb_readoptions_t* roptions = leveldb_readoptions_create();
  char* val = leveldb_get(
      db->ldb,
      roptions,
      key, strlen(key),
      &readlen,
      &err);

  leveldb_readoptions_destroy(roptions);

  if (err) {
    BACK_ERRF("could not read database value '%s': %s", key, err);
    leveldb_free(err);
    return 0;
  } else if (val == 0) {
    // Still successful, there's just nothing there :)
    *outstr = 0;
  } else {
    // Interestingly enough google doesn't believe in C-strings.
    val = realloc(val, readlen + 1);
    val[readlen] = 0;
    *outstr = val;
  }

  return 1;
}

int back_db_get_int(back_db* db, char* key, long int* outint,
    long int def) {
  char* str = 0;
  if (!back_db_get(db, key, &str)) {
    return 0;
  }

  if (!str) {
    *outint = def;
  } else {
    char* p = 0;
    *outint = strtol(str, &p, 10);
    free(str);
  }

  return 1;
}
