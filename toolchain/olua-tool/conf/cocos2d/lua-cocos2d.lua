require "aux.olua-cls"
require "conf.cocos2d.import-cocos2d-type"

local M = {}

M.NAME = "cocos2d"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_cocos2d.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_cocos2d.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_cocos2d.h"
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/lua-bindings/lua_conv_manual.h"
#include "xgame/lua-bindings/LuaComponent.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "olua/olua.hpp"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "vr/CCVRGenericRenderer.h"
#include "vr/CCVRGenericHeadTracker.h"
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
            return olua_push_cppobj<${CPPCLS}>(L, obj, "${LUACLS}");
        }
    ]]))
    return new
end

M.CLASSES = {
    include("conf/cocos2d/cc/base/cc.UserDefault.lua"),
    include("conf/cocos2d/cc/base/cc.Ref.lua"),
    include("conf/cocos2d/cc/base/cc.Type.lua"),
    include("conf/cocos2d/cc/base/cc.Director.lua"),
    include("conf/cocos2d/cc/base/cc.Scheduler.lua"),
    include("conf/cocos2d/cc/base/cc.EventDispatcher.lua"),
    include("conf/cocos2d/cc/base/cc.EventListener.lua"),
    include("conf/cocos2d/cc/base/cc.Event.lua"),
    include("conf/cocos2d/cc/base/cc.EventKeyboard.KeyCode.lua"),
    include("conf/cocos2d/cc/base/cc.Touch.lua"),
    include("conf/cocos2d/cc/platform/cc.GLView.lua"),
    include("conf/cocos2d/cc/platform/cc.Image.lua"),
    include("conf/cocos2d/cc/renderer/cc.Renderer.lua"),
    include("conf/cocos2d/cc/renderer/cc.GLProgram.lua"),
    include("conf/cocos2d/cc/renderer/cc.GLProgramState.lua"),
    include("conf/cocos2d/cc/renderer/cc.TextureCache.lua"),
    include("conf/cocos2d/cc/renderer/cc.Texture2D.lua"),
    include("conf/cocos2d/cc/renderer/cc.TextureAtlas.lua"),
    include("conf/cocos2d/cc/vr/cc.vr.lua"),
    include("conf/cocos2d/cc/2d/actions/cc.ActionManager.lua"),
    include("conf/cocos2d/cc/2d/actions/cc.Action.lua"),
    include("conf/cocos2d/cc/2d/support/cc.Component.lua"),
    include("conf/cocos2d/cc/2d/base-nodes/cc.Node.lua"),
    include("conf/cocos2d/cc/2d/base-nodes/cc.AtlasNode.lua"),
    include("conf/cocos2d/cc/2d/base-nodes/cc.ProtectedNode.lua"),
    include("conf/cocos2d/cc/2d/label-nodes/cc.Label.lua"),
    include("conf/cocos2d/cc/2d/label-nodes/cc.LabelAtlas.lua"),
    include("conf/cocos2d/cc/2d/label-nodes/cc.FontAtlas.lua"),
    include("conf/cocos2d/cc/2d/sprite-nodes/cc.Animation.lua"),
    include("conf/cocos2d/cc/2d/sprite-nodes/cc.SpriteFrame.lua"),
    include("conf/cocos2d/cc/2d/sprite-nodes/cc.Sprite.lua"),
    include("conf/cocos2d/cc/2d/layers-scenes-transitions-nodes/cc.Scene.lua"),
    include("conf/cocos2d/cc/2d/cc.Light.lua"),
    include("conf/cocos2d/cc/2d/cc.Camera.lua"),
}

return M