require 'conf.cocos2d.import-cocos2d-type'
require "conf.fairygui.import-fairygui-type"

local M = {}

M.NAME = "FAIRYGUI_CONV"
M.HEADER_PATH = "frameworks/libxgame/src/xgame/lua-bindings/lua_fairygui_conv.h"
M.SOURCE_PATH = "frameworks/libxgame/src/xgame/lua-bindings/lua_fairygui_conv.cpp"

M.HEADER_INCLUDES = [[
#include "xgame/xlua.h"
#include "FairyGUI.h"
]]

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_fairygui_conv.h"
]]

M.CONVS = {
    REG_CONV {
        CPPCLS = 'fairygui::Margin',
        DEF = [[
            float left;
            float top;
            float right;
            float bottom;
        ]]
    },
    REG_CONV {
        CPPCLS = 'fairygui::TweenValue',
        DEF = [[
            @option float x;
            @option float y;
            @option float z;
            @option float w;
            @option double d;
        ]]
    }
}

return M