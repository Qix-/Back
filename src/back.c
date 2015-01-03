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

  // Determine subcommand and forward execution
  if (strcmp(subcommand, "up") == 0) {
    return back_up(argc, argv);
  } else if(strcmp(subcommand, "bone") == 0) {
    return back_bone(argc, argv);
  } else if(strcmp(subcommand, "list") == 0) {
    return back_list(argc, argv);
  } else if(strcmp(subcommand, "pack") == 0) {
    return back_pack(argc, argv);
  } else if(strcmp(subcommand, "wash") == 0) {
    return back_wash(argc, argv);
  } else if(strcmp(subcommand, "spin") == 0) {
    return back_spin(argc, argv);
  } else if(strcmp(subcommand, "track") == 0) {
    return back_track(argc, argv);
  } else {
    BACK_ERRF("unknown subcommand '%s'", subcommand);
    return -1;
  }
}
