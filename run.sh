#!/bin/bash
CLEAN=false
TEST=false
while [[ $# -gt 0 ]]; do
  case $1 in
    clean) CLEAN=true; shift ;;
    test) TEST=true; shift ;;
    *) echo "Unknown option [$1]"; exit ;;
  esac
done

if $CLEAN; then rm -rf build; fi
if [ ! -d build ]; then mkdir build; fi

cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make

if $TEST; then ctest; fi