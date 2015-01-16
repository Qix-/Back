/*
 * BACK - another build system
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "back.h"

#define CHECK_CMD(name) (strcmp(subcommand, #name) == 0) {                      \
  result = back_##name(argc, argv);                                             \
}

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
  long long time_start = back_clock();
#endif

  // Determine subcommand and forward execution
  if      CHECK_CMD(up)
  else if CHECK_CMD(bone)
  else if CHECK_CMD(list)
  else if CHECK_CMD(pack)
  else if CHECK_CMD(wash)
  else if CHECK_CMD(spin)
  else if CHECK_CMD(track)
  else {
    BACK_ERRF("unknown subcommand '%s'", subcommand);
    result = -1;
  }

#ifdef WITH_TIMER
  if (result == 0) {
    long long time_delta = back_clock() - time_start;
    BACK_LOGF("completed successfully in %.02f seconds",
        back_clock_secs(time_delta));
  }
#endif

  return result;
}
