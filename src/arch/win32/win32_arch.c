/* Architecture/platform specific functions - win32 */
#include <windows.h>
#include <intrin.h>

/* Credit to Rafael Baptista
 * http://stackoverflow.com/a/16859693/510036
 */
short back_get_system_uid(void) {
  int cpuinfo[4] = {0, 0, 0, 0};
  __cpuid(cpuinfo, 0);

  u16 hash = 0;
  u16* ptr = (u16*)(&cpuinfo[0]);
  for (u32 i = 0; i < 8; i++) {
     hash += ptr[i];
  }

  return (short) hash;
}
