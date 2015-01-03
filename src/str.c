#include <string.h>
#include <stdlib.h>

char* strdup(const char *str) {
  int n = strlen(str) + 1;
  char* dup = malloc(n);
  if(dup) {
    strcpy(dup, str);
  }
  return dup;
}
