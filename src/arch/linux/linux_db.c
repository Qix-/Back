/* Platform-specific database functions - linux */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/types.h>
#include <dirent.h>
#include "back.h"
#include "str.h"

static const size_t CWDSIZE = 2048;

char* back_db_find(char* dbname) {
  int dbnamelen = strlen(dbname);

  // Below, we account for the name of the database folder along with
  //  a new slash at the end (hence the -1)
  char cwdbuf[CWDSIZE];
  char* cwd = getcwd(cwdbuf, CWDSIZE - 1 - dbnamelen);
  if (!cwd) {
    BACK_ERR("could not determine current working directory (recovering)");
    return 0;
  }

  // Iterate up the path until we find one
  char pathbuf[CWDSIZE];
  while (1) {
    char* dbpath = strcpy(&pathbuf[0], cwd);

    // Only append a slash if we're not in root
    //  (since dirname and getcwd both leave off the slash)
    char inroot = strcmp(cwd, "/") == 0;
    if (!inroot) {
      dbpath = strcat(dbpath, "/");
    }

    dbpath = strcat(dbpath, dbname);

    // Try to open the directory
    DIR* dir = opendir(dbpath);
    if (dir) {
      closedir(dir);
      return strdup(dbpath);
    }

    if (inroot) {
      break;
    }

    cwd = dirname(cwd);
  }

  return 0;
}
