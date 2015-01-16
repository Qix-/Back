#ifndef BACK_STR_H__
#define BACK_STR_H__
#pragma once

/* Duplicates a string (be sure to free) */
char* strdup(const char*);

/* Ensures a free-able dirname'd/basename'd string
   without modifying the original string */
char* dirnamep(char*);
char* basenamep(char*);

#endif
