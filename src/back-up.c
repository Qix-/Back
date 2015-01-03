/* back-up - updates the build tree with any changes */

#include <stdio.h>
#include "back.h"
#include "db.h"

int back_up(UNUSED int argc, UNUSED char** argv) {
  // Open the database
  //  This will also create it if it doesn't exist.
  back_db* db = back_db_open();


  // Close the database
  back_db_close(db);
  return 0;
}
