/* Back database functionality */
#ifndef BACK_DB_H__
#define BACK_DB_H__
#pragma once

typedef struct back_db back_db;

/**
 * Opens (or creates) the Back database
 */
back_db* back_db_open(void);

/**
 * Closes the Back database
 */
void back_db_close(back_db*);

/**
 * Sets a key to a string value
 */
int back_db_set(back_db*, char*, char*);

/**
 * Sets a key to an int value
 */
int back_db_set_int(back_db*, char*, long int);

/**
 * Gets a string value by a key
 *  NOTE: malloc's the resulting string. Make sure to free!
 */
int back_db_get(back_db*, char*, char**);

/**
 * Gets a long value by a key
 */
int back_db_get_int(back_db*, char*, long int*, long int);

/**
 * Gets the path to the Back database folder
 *  NOTE: malloc's the resuting string (unless it's 0). Make sure to free.
 */
char* back_db_find(char*);

#endif
