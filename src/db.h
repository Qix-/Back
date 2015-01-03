/* Back database functionality */
#ifndef BACK_DB_H__
#define BACK_DB_H__
#pragma once

typedef struct back_db back_db;

back_db* back_db_open(void);
void back_db_close(back_db*);

#endif
