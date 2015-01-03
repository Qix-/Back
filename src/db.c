/* Back database functionality */

#include <stdlib.h>
#include <stdio.h>
#include <leveldb/c.h>
#include "back.h"
#include "db.h"

struct back_db {
  leveldb_t* ldb;
};

back_db* back_db_open(void) {
  back_db* db = malloc(sizeof(back_db));
  if (!db) {
    BACK_ERR("could not allocate database");
    goto ret;
  }

  leveldb_options_t* options = leveldb_options_create();
  leveldb_options_set_create_if_missing(options, 1);

  char* err = 0;
  db->ldb = leveldb_open(options, "testdb", &err);
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
