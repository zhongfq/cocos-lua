#!/bin/bash

pushd `dirname $0` > /dev/null 2>&1

cd `dirname $1`
SCRIPT=`basename $1`
PATH="/usr/local/bin:${PATH}"

git pull # update workspace

shift # remove script
lua ${SCRIPT} $@
