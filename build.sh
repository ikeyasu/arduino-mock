#!/bin/sh
set -eu

cd -- "$(dirname -- "$0")"
mkdir -p build
cd build

if [ "$OSTYPE" == "win32" -o "$OSTYPE" == "msys" ] ; then
    cmake -Dtest=ON .. -G "MSYS Makefiles";
else
    cmake -Dtest=ON .. -G "Unix Makefiles";
fi

make
ctest -V
