/* back-stamp - displays system and release information */

#include <stdio.h>
#include <leveldb/c.h>
#include <lua.h>
#include "back.h"
#include "arch.h"

int back_stamp(UNUSED int argc, UNUSED char** argv) {
  // Gather Information
  //  - CPUID
  short cpuid = back_get_system_uid();
  // - LevelDB version
  int ldb_major = leveldb_major_version();
  int ldb_minor = leveldb_minor_version();
  // - Lua Version
  const double lua_vsn = ((double) *(lua_version(0))) / 100.0;

  // Print
  BACK_LOGF("Back version: %s", BACK_VERSION);
  BACK_LOGF("CPU ID: %d", (int)cpuid);
  BACK_LOGF("LevelDB Version: %d.%d", ldb_major, ldb_minor);
  BACK_LOGF("Lua Version: %.02f", lua_vsn);
  BACK_LOG("");
  BACK_LOG("Copyright (C) 2015 JD Ballard (Qix). "
      "Released under the MIT license.");

  return 0;
}
