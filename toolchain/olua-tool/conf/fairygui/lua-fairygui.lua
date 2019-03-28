require "aux.olua-cls"
require "conf.cocos2d.import-cocos2d-type"
require "conf.fairygui.import-fairygui-type"

local M = {}

M.NAME = "fairygui"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_fairygui.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_fairygui.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_xgame.h"
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "olua/olua.hpp"
#include "FairyGUI.h"
]]

M.CLASSES = {
    include('conf/fairygui/fgui/event/fgui.UIEventDispatcher.lua'),
    include('conf/fairygui/fgui/event/fgui.EventContext.lua'),
}

return M