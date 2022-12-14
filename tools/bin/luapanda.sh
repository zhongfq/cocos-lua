#!/bin/bash

cd `dirname $0`
WORKDIR=`pwd`
$WORKDIR/../../build/mac-build/bin/hihikid/Debug/cclua.app/Contents/MacOS/cclua --workdir `realpath $WORKDIR/../../assets` --lua-debug luapanda
