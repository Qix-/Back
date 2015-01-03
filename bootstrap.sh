#!/bin/bash

function die {
  echo -e "\n$*" >&2
  exit 1
}

if [ "$1" == "-f" ]; then
  _clean="clean"
fi

# Make lua
make --directory=lib/lua $_clean generic \
  || die "Building lua failed!"

# Make levelDB
make --directory=lib/leveldb $_clean libleveldb.a \
  || die "Building LevelDB failed!"
