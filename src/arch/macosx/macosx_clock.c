/* MacOSX implementation of the clock functionality */
/* Note that this will report bad results if your build takes more than
   72 minutes (according to the man page). */

#include <time.h>

long long back__clock(void) {
  return (long long) clock();
}

double back__clock_secs(long long delta) {
  return delta / CLOCKS_PER_SEC;
}
