require "olua.olua-cls"
require "conf.cocos2d.import-cocos2d-type"

local M = {}

M.NAME = "spine"
M.HEADER_PATH = "frameworks/libxgame/src/lua-bindings/lua_spine.h"
M.SOURCE_PATH = "frameworks/libxgame/src/lua-bindings/lua_spine.cpp"

M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d_ui.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"
]]

M.CLASSES = {
    include("conf/cocos2d/editor-support/spine/sp.spine.lua"),
    include("conf/cocos2d/editor-support/spine/sp.SkeletonData.lua"),
    include("conf/cocos2d/editor-support/spine/sp.SkeletonRenderer.lua"),
    include("conf/cocos2d/editor-support/spine/sp.SkeletonAnimation.lua"),
}

return M