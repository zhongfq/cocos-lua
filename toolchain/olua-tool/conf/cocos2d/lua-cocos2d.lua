require "aux.olua-cls"
require "conf.cocos2d.import-cocos2d-type"

local M = {}

M.NAME = "cocos2d"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_cocos2d.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_cocos2d.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_cocos2d.h"
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "olua/olua.hpp"
#include "cocos2d.h"
]]

M.STATIC_CHUNK = [[
static const std::string makeScheduleCallbackTag(const std::string &key)
{
    return "schedule." + key;
}]]


function new_ccobj(cls)
    local CPPCLS = cls.CPPCLS
    local LUACLS = cls.LUACLS
    local new = format_snippet(([[
        {
            ${CPPCLS} *obj = new ${CPPCLS}();
            obj->autorelease();
            return olua_push_cppobj(L, obj, "${LUACLS}");
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
    include("conf/cocos2d/cc/cc.GLView.lua"),
    include("conf/cocos2d/cc/cc.GLProgram.lua"),
    include("conf/cocos2d/cc/cc.TextureCache.lua"),
    include("conf/cocos2d/cc/cc.Texture2D.lua"),
    include("conf/cocos2d/cc/cc.Image.lua"),
    include("conf/cocos2d/cc/cc.Node.lua"),
    include("conf/cocos2d/cc/cc.Camera.lua"),
    include("conf/cocos2d/cc/cc.Sprite.lua"),
    include("conf/cocos2d/cc/cc.Scene.lua"),
    include("conf/cocos2d/cc/cc.EventDispatcher.lua"),
    include("conf/cocos2d/cc/cc.EventListener.lua"),
    include("conf/cocos2d/cc/cc.Event.lua"),
    include("conf/cocos2d/cc/cc.Touch.lua"),
}

return M