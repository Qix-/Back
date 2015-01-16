/* Architecture/platform specific functions - macosx */

/* Credit to Rafael Baptista
 * http://stackoverflow.com/a/16859693/510036
 */
static void getCpuid( unsigned int* p, unsigned int ax )
{
  __asm __volatile
  ( "movl %%ebx, %%esi\n\t"
    "cpuid\n\t"
    "xchgl %%ebx, %%esi"
    : "=a" (p[0]), "=S" (p[1]),
      "=c" (p[2]), "=d" (p[3])
    : "0" (ax)
  );
}

/* Credit to Rafael Baptista
 * http://stackoverflow.com/a/16859693/510036
 */
short back_get_system_uid(void) {
  unsigned int cpuinfo[4] = {0, 0, 0, 0};
  getCpuid(cpuinfo, 0);

  unsigned short hash = 0;
  unsigned int* ptr = &cpuinfo[0];
  for (unsigned int i = 0; i < 4; i++) {
    hash += (ptr[i] & 0xFFFF) + (ptr[i] >> 16);
  }

  return hash;
}
