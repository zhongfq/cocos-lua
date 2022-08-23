loadfile('../lua/script/init.lua')('../lua')

-- parse cmd line args
local ARG_PLATFORM = "android" -- ios|android
local ARG_APP = 'com.hihikid.park'
local ARG_VERSION = "1.0.0"
local args = {...}
while #args > 0 do
    local c = table.remove(args, 1)
    if c == '--platform' then
        ARG_PLATFORM = assert(table.remove(args, 1), 'no platform')
    elseif c == '--app' then
        ARG_APP = assert(table.remove(args, 1), 'no app')
    elseif c == '--version' then
        ARG_VERSION = assert(table.remove(args, 1), 'no version')
    end
end

local toolset = require "toolset"

-- upload command
local UPLOAD = toolset.fullpath('../../frameworks/libxgame/src/bugly/dsymtool/buglyqq-upload-symbol.jar')

if ARG_PLATFORM == 'android' then
    local INPUT_SYMBOL_PATH = toolset.fullpath('../../runtime-src/proj.android/app/build/intermediates/cmake/release/obj')
    toolset.bash([[
        cd ../../build
        mkdir -p bugly && cd bugly

        java -jar ${UPLOAD} \
            -appid eed7537cdc \
            -appkey 96aa6e6e-3802-48c7-a459-dd8fdbd196d8 \
            -bundleid ${ARG_APP} \
            -version ${ARG_VERSION} \
            -platform Android \
            -inputSymbol ${INPUT_SYMBOL_PATH}/arm64-v8a
            # -inputMapping <mapping file>

        java -jar ${UPLOAD} \
            -appid eed7537cdc \
            -appkey 96aa6e6e-3802-48c7-a459-dd8fdbd196d8 \
            -bundleid ${ARG_APP} \
            -version ${ARG_VERSION} \
            -platform Android \
            -inputSymbol ${INPUT_SYMBOL_PATH}/armeabi-v7a
    ]])
else
    local INPUT_SYMBOL_PATH = toolset.fullpath('../../build/ios-archive/build/bin/hihikid/Release')
    toolset.bash([[
        cd ../../build
        mkdir -p bugly && cd bugly

        java -jar ${UPLOAD} \
            -appid 9179e917a0 \
            -appkey 762e8f0a-0419-48d7-9ef6-81e9338bcc94 \
            -bundleid ${ARG_APP} \
            -version ${ARG_VERSION} \
            -platform IOS \
            -inputSymbol ${INPUT_SYMBOL_PATH}
    ]])
end