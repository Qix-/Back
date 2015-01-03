/* Back database functionality */
#ifndef BACK_DB_H__
#define BACK_DB_H__
#pragma once

typedef struct back_db back_db;

back_db* back_db_open(void);
void back_db_close(back_db*);

int back_db_set(back_db*, char*, char*);
int back_db_set_int(back_db*, char*, long int);
// below function malloc's output string; remember to free
int back_db_get(back_db*, char*, char**);
int back_db_get_int(back_db*, char*, long int*, long int);

/* PLATFORM DEPENDENT CALLS */
// returned string, if not null, must be freed by caller
char* back_db_find(char*);

#endif
