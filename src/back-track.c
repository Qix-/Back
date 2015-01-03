/* back-track - displays information about the build tree */

/*
   Things I want this subcommand to do, for instance,
   include tracking exactly what commands it takes
   to manually update a file (like generating a bash
   script to update a single file, etc.) or display
   all the rules that pertain to a file, etc.
*/

#include <stdio.h>
#include "back.h"

int back_track(UNUSED int argc, UNUSED char** argv) {
  BACK_ERR("subcommand 'track' not yet implemented");
  return -1;
}
