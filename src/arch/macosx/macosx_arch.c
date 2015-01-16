/* Architecture/platform specific functions - macosx */
#include <mach-o/arch.h>

/* Credit to Rafael Baptista
 * http://stackoverflow.com/a/16859693/510036
 */
short back_get_system_uid(void) {
  const NXArchInfo* info = NXGetLocalArchInfo();
  unsigned short val = 0;
  val += (unsigned short) info->cputype;
  val += (unsigned short) info->cpusubtype;
  return (short) val;
}
