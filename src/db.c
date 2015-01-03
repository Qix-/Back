/* Back database functionality */

#include <stdlib.h>
#include <stdio.h>
#include <leveldb/c.h>
#include "back.h"
#include "db.h"

#define BACK_DB_DIR ".back"

struct back_db {
  leveldb_t* ldb;
};

back_db* back_db_open(void) {
  // Try to find the database location
  char* dbname = back_db_find(BACK_DB_DIR);
  if (dbname == 0) {
    BACK_LOG("initializing database in " BACK_DB_DIR);
    dbname = BACK_DB_DIR;
  }

  back_db* db = malloc(sizeof(back_db));
  if (!db) {
    BACK_ERR("could not allocate database");
    goto ret;
  }

  leveldb_options_t* options = leveldb_options_create();
  leveldb_options_set_create_if_missing(options, 1);

  char* err = 0;
  db->ldb = leveldb_open(options, dbname, &err);
  if (err) {
    BACK_ERRF("could not open database: %s", err);
    leveldb_free(err);
    goto dealloc;
  }

  goto ret;
dealloc:
  free(db);
ret:
  return db;
}

void back_db_close(back_db* db) {
  leveldb_close(db->ldb);
  free(db);
}
