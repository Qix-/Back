/*
 * BACK - another build system
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "back.h"

int main(int argc, char** argv) {
  // Resolve subcommand
  char* subcommand = "up";
  if (argc > 1) {
    subcommand = argv[1];
  }

  // Adjust arguments for passoff to subcommands
  argc -= 2;
  if (argc != 0) {
    argv = &argv[2];
  }

  int result = -1;
#ifdef WITH_TIMER
  long long time_start = back__clock();
#endif

  // Determine subcommand and forward execution
  if (strcmp(subcommand, "up") == 0) {
    result = back_up(argc, argv);
  } else if(strcmp(subcommand, "bone") == 0) {
    result = back_bone(argc, argv);
  } else if(strcmp(subcommand, "list") == 0) {
    result = back_list(argc, argv);
  } else if(strcmp(subcommand, "pack") == 0) {
    result = back_pack(argc, argv);
  } else if(strcmp(subcommand, "wash") == 0) {
    result = back_wash(argc, argv);
  } else if(strcmp(subcommand, "spin") == 0) {
    result = back_spin(argc, argv);
  } else if(strcmp(subcommand, "track") == 0) {
    result = back_track(argc, argv);
  } else {
    BACK_ERRF("unknown subcommand '%s'", subcommand);
    result = -1;
  }

#ifdef WITH_TIMER
  if (result == 0) {
    long long time_delta = back__clock() - time_start;
    BACK_LOGF("completed successfully in %.02f seconds",
        back__clock_secs(time_delta));
  }
#endif

  return result;
}
