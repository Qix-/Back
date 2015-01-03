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
};

back_db* back_db_open(void) {
  // Try to find the database location
  char* dbname = back_db_find(BACK_DB_DIR);
  if (dbname == 0) {
    BACK_LOG("initializing database in " BACK_DB_DIR);
    dbname = strdup(BACK_DB_DIR);
  }

  back_db* db = malloc(sizeof(back_db));
  if (!db) {
    BACK_ERR("could not allocate database");
    goto dealloc_dbname;
  }

  leveldb_options_t* options = leveldb_options_create();
  leveldb_options_set_create_if_missing(options, 1);

  char* err = 0;
  db->ldb = leveldb_open(options, dbname, &err);
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
  free(dbname);
ret:
  return db;
}

void back_db_close(back_db* db) {
  leveldb_close(db->ldb);
  free(db);
}
