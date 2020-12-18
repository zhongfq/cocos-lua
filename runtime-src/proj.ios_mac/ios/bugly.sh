#!bin/sh

pushd `dirname $0`

UPLOAD_SIMULATOR_SYMBOLS=0
UPLOAD_DEBUG_SYMBOLS=0
UPLOAD_ARCHIVE_ONLY=1

BUNDLE_IDENTIFIER=$1
BUGLY_APP_ID=$2
BUGLY_APP_KEY=$3

echo "bugly upload dSYM"
echo " BUNDLE_IDENTIFIER=${BUNDLE_IDENTIFIER}"
echo " BUGLY_APP_ID=${BUGLY_APP_ID}"
echo " BUGLY_APP_KEY=${BUGLY_APP_KEY}"

. ./../../../frameworks/libxgame/src/bugly/dsymtool/dSYMUpload.sh