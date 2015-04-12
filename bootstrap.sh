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

# Make snappy
if [ ! -f lib/snappy/Makefile ]; then
  (cd lib/snappy && ./autogen.sh && ./configure) \
    || die "Configuring Snappy failed!"
fi
make --directory=lib/snappy $_clean all \
  || die "Building Snappy failed!"

# Link snappy
[ -d lib/snappy/bin ] || mkdir lib/snappy/bin
cp -r lib/snappy/.libs/* lib/snappy/bin/

# Make levelDB
make --directory=lib/leveldb $_clean libleveldb.a \
  || die "Building LevelDB failed!"
