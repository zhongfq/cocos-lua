local M = typemod 'spine'
local typeconf = M.typeconf

M.PARSER = {
    PATH = {
        'spine/spine-cocos2dx.h'
    },
    ARGS = {
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/cocos2d-x/cocos/editor-support',
        '-I../../frameworks/libxgame/src',
        '-DCC_DLL=',
        '-DEXPORT_DLL=',
    },
}

M.NAMESPACES = {"cocos2d", "cocos2d::experimental", "CocosDenshion"}
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
M.CHUNK = [[
]]

M.MAKE_LUACLS = function (cppname)
    if cppname == 'ResolutionPolicy' then
        return 'cc.' .. cppname
    else
        cppname = string.gsub(cppname, '^cocos2d::experimental::', 'cc.')
        cppname = string.gsub(cppname, "^cocos2d::", "cc.")
        cppname = string.gsub(cppname, "^CocosDenshion::", "cc.")
        cppname = string.gsub(cppname, "::", ".")
        cppname = string.gsub(cppname, "[ *]*$", '')
        return cppname
    end
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

return M