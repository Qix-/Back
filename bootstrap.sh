#!/bin/bash

function die {
  echo -e "\n$*" >&2
  exit 1
}

# Make lua
make --directory=lib/lua generic \
  || die "Building lua failed!"

# Make levelDB
make --directory=lib/leveldb libleveldb.a \
  || die "Building LevelDB failed!"
