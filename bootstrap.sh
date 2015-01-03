#!/bin/bash

function die {
  echo "$*" >&2
  exit 1
}

# Make lua
make --directory=lib/lua generic \
  || die "Building lua failed!"
