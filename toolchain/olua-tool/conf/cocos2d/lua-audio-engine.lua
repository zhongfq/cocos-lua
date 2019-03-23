require "aux.olua-cls"
require "conf.cocos2d.import-cocos2d-type"

local M = {}

M.NAME = "audio_engine"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_audio_engine.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_audio_engine.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_cocos2d_ui.h"
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "olua/olua.hpp"
#include "cocos2d.h"
#include "audio/include/AudioEngine.h"
]]

M.STATIC_CHUNK = [[
]]

M.CLASSES = {
    include("conf/cocos2d/audio/cc.AudioEngine.lua"),
}

return M