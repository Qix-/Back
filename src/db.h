/* Back database functionality */
#ifndef BACK_DB_H__
#define BACK_DB_H__
#pragma once

typedef struct back_db back_db;

back_db* back_db_open(void);
void back_db_close(back_db*);

/* PLATFORM DEPENDENT CALLS */
// returned string, if not null, must be freed by caller
char* back_db_find(char*);

#endif
