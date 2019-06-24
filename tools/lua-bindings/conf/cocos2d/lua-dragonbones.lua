require "core.olua-cls"
require "conf.cocos2d.import-cocos2d-type"

local M = {}

M.NAME = "dragonbones"
M.HEADER_PATH = "frameworks/libxgame/src/lua-bindings/lua_dragonbones.h"
M.SOURCE_PATH = "frameworks/libxgame/src/lua-bindings/lua_dragonbones.cpp"

M.INCLUDES = [[
#include "lua-bindings/lua_dragonbones.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "cocos2d.h"
#include "CCDragonBonesHeaders.h"
]]

M.CLASSES = {
    include("conf/cocos2d/editor-support/dragonbones/db.dragonbones.lua"),
    include("conf/cocos2d/editor-support/dragonbones/db.Factory.lua"),
    include("conf/cocos2d/editor-support/dragonbones/db.ArmatureDisplay.lua"),
}

return M