require "aux.tolua-cls"
require "conf.cocos2d.import-cocos2d-type"

local M = {}

M.NAME = "cocos2d"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_cocos2d.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_cocos2d.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_cocos2d.h"
#include "xgame/xlua-conv.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "tolua/tolua.hpp"
#include "cocos2d.h"
]]

function new_ccobj(cls)
    local CPPCLS = cls.CPPCLS
    local LUACLS = cls.LUACLS
    local new = format_snippet(([[
        {
            ${CPPCLS} *obj = new ${CPPCLS}();
            obj->autorelease();
            xluacv_push_ccobj(L, obj, "${LUACLS}");
            return 1;
        }
    ]]))
    return new
end

M.CLASSES = {
    include("conf/cocos2d/cc/cc.UserDefault.lua"),
    include("conf/cocos2d/cc/cc.Ref.lua"),
    include("conf/cocos2d/cc/cc.Director.lua"),
    include("conf/cocos2d/cc/cc.Scheduler.lua"),
    include("conf/cocos2d/cc/cc.ActionManager.lua"),
    include("conf/cocos2d/cc/cc.Node.lua"),
    include("conf/cocos2d/cc/cc.Sprite.lua"),
    include("conf/cocos2d/cc/cc.Scene.lua"),
}

return M