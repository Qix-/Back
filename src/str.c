#include <string.h>
#include <stdlib.h>
#include <libgen.h>

char* strdup(const char *str) {
  int n = strlen(str) + 1;
  char* dup = malloc(n);
  if (dup) {
    strcpy(dup, str);
  }
  return dup;
}

char* dirnamep(char* dir) {
  char* copy = strdup(dir);
  char* result = strdup(dirname(copy));
  free(copy);
  return result;
}

char* basenamep(char* dir) {
  char* copy = strdup(dir);
  char* result = strdup(basename(copy));
  free(copy);
  return result;
}
