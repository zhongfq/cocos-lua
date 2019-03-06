local M = {}

M.NAME = "CONV"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_conv.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_conv.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/xlua.h"
#include "tolua/tolua.hpp"
]]

M.CONVS = {
    REG_CONV {
        CPPCLS = 'cocos2d::experimental::Viewport',
        DEF = [[
            {
                float _left = left;
                float _bottom = bottom;
                float _width = width;
                float _height = height;
            }
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Vec2',
        DEF = [[
            {
                float x;
                float y;
            }
        ]],
    },
    REG_CONV {
        CPPCLS = 'cocos2d::Vec3',
        DEF = [[
            {
                float x;
                float y;
                float z;
            }
        ]],
    },
}

return M