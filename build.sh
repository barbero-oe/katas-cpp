#!/bin/bash

if [ "$1" = "clean" ]; then
    rm -r build/
    mkdir build
fi

cd build
cmake ..
make