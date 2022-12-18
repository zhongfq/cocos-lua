#!/bin/bash

cd `dirname $0`
WORKDIR=`pwd`
$WORKDIR/../../build/mac-build/bin/cocoslua/Debug/cocoslua.app/Contents/MacOS/cocoslua --workdir `realpath $WORKDIR/../../assets` --lua-debug luapanda
