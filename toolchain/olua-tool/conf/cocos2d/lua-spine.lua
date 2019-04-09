require "aux.olua-cls"
require "conf.cocos2d.import-cocos2d-type"

local M = {}

M.NAME = "spine"
M.HEADER_PATH = "frameworks/libxgame/src/xgame/lua-bindings/lua_spine.h"
M.SOURCE_PATH = "frameworks/libxgame/src/xgame/lua-bindings/lua_spine.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_cocos2d_ui.h"
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "olua/olua.hpp"
#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"
]]

M.STATIC_CHUNK = [[
]]

M.CLASSES = {
    include("conf/cocos2d/editor-support/spine/cc.spine.lua"),
    include("conf/cocos2d/editor-support/spine/cc.SkeletonRenderer.lua"),
    include("conf/cocos2d/editor-support/spine/cc.SkeletonAnimation.lua"),
}

return M