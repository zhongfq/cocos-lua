local olua = require "olua"
local autoconf = require "autoconf"
local M = autoconf.typemod 'cocos2d_studio'
local typeconf = M.typeconf
local typedef = M.typedef
local typeconv = M.typeconv

M.PATH = '../../frameworks/libxgame/src/lua-bindings'
M.INCLUDES = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "cocos2d.h"
#include "editor-support/cocostudio/CocoStudio.h"
]]
M.CHUNK = [[
static std::string makeFrameEndCallbackTag(lua_Integer index, const std::string &key)
{
    if (index < 0) {
        return "frameEnd.";
    } else {
        return "frameEnd." + std::to_string((int)index) + "." + key;
    }
}

static std::string makeFrameEndCallbackTag(cocostudio::timeline::ActionTimeline *self, const std::string &animationName)
{
    auto info = self->getAnimationInfo(animationName);
    return makeFrameEndCallbackTag((lua_Integer)info.endIndex, animationName);
}
]]

M.EXCLUDE_TYPE = require 'conf.exclude-type'
M.EXCLUDE_TYPE 'cocos2d::ObjectFactory::TInfo'
M.EXCLUDE_TYPE 'cocos2d::ObjectFactory::Instance *'
M.EXCLUDE_TYPE 'cocos2d::ObjectFactory::Instance'
M.EXCLUDE_TYPE 'cocostudio::DataReaderHelper::DataInfo *'
M.EXCLUDE_TYPE 'cocostudio::stExpCocoNode *'
M.EXCLUDE_TYPE 'flatbuffers::NodeTree *'
M.EXCLUDE_TYPE 'rapidjson::Value'
M.EXCLUDE_TYPE 'cocostudio::SEL_ParseEvent'

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, '^cocos2d::', 'cc.')
    cppname = string.gsub(cppname, '^cocostudio::', 'ccs.')
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

typeconv 'cocostudio::timeline::AnimationInfo'
    .EXCLUDE_FUNC 'clipEndCallBack'

typeconf "cocos2d::CSLoader"
    .CALLBACK {
        NAME = 'createNode',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_SCOPE = 'function',
    }
    .CALLBACK {
        NAME = 'createNodeWithVisibleSize',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_SCOPE = 'function',
    }


typeconf "cocostudio::MovementEventType"
typeconf "cocostudio::DisplayType"

typeconf "cocostudio::ActionFrame"
    .ATTR('getAction', {RET = '@addref(action |)'})

typeconf "cocostudio::ActionFadeFrame"
typeconf "cocostudio::ActionFrameEasing"
typeconf "cocostudio::ActionMoveFrame"
typeconf "cocostudio::ActionRotationFrame"
typeconf "cocostudio::ActionScaleFrame"
typeconf "cocostudio::ActionTintFrame"

typeconf "cocostudio::AnimationData"
typeconf "cocostudio::Armature"
typeconf "cocostudio::ProcessBase"
typeconf "cocostudio::ActionManagerEx"
typeconf "cocostudio::ActionNode"
typeconf "cocostudio::ActionObject"

local ArmatureAnimation = typeconf "cocostudio::ArmatureAnimation"
ArmatureAnimation.CALLBACK {
    NAME = 'setMovementEventCallFunc',
    NULLABLE = true,
}
ArmatureAnimation.CALLBACK {
    NAME = 'setFrameEventCallFunc',
    NULLABLE = true,
}

typeconf "cocostudio::ArmatureData"
typeconf "cocostudio::ArmatureDataManager"
typeconf "cocostudio::DisplayData"
typeconf "cocostudio::ArmatureDisplayData"
typeconf "cocostudio::ArmatureMovementDispatcher"
    .EXCLUDE_FUNC "*" --TODO

typeconf "cocostudio::BaseData"
typeconf "cocostudio::BaseTriggerAction"
typeconf "cocostudio::BaseTriggerCondition"
typeconf "cocostudio::BatchNode"
typeconf "cocostudio::Bone"
typeconf "cocostudio::BoneData"
typeconf "cocostudio::CocoLoader"
    .EXCLUDE_FUNC "*" --TODO

typeconf "cocostudio::ColliderBody"
typeconf "cocostudio::ColliderDetector"
typeconf "cocostudio::ColliderFilter"
typeconf "cocostudio::ComAttribute"
typeconf "cocostudio::ComAudio"
typeconf "cocostudio::ComController"
typeconf "cocostudio::ComRender"
typeconf "cocostudio::ContourData"
typeconf "cocostudio::DataReaderHelper"
typeconf "cocostudio::DecorativeDisplay"
typeconf "cocostudio::DisplayFactory"
typeconf "cocostudio::DisplayManager"
typeconf "cocostudio::FrameData"
-- typeconf "cocostudio::FrameEvent"

typeconf "cocostudio::GUIReader"
    .EXCLUDE_FUNC 'getParseCallBackMap'
    .EXCLUDE_FUNC 'getParseObjectMap'

typeconf "cocostudio::InputDelegate"
typeconf "cocostudio::MovementBoneData"
typeconf "cocostudio::MovementData"
-- typeconf "cocostudio::MovementEvent"
typeconf "cocostudio::ParticleDisplayData"
-- typeconf "cocostudio::RelativeData"
typeconf "cocostudio::SceneReader::AttachComponentType"

local SceneReader = typeconf "cocostudio::SceneReader"
SceneReader.CALLBACK {
    NAME = 'setTarget',
    NULLABLE = true,
}

typeconf "cocostudio::Skin"
typeconf "cocostudio::SpriteDisplayData"
typeconf "cocostudio::SpriteFrameCacheHelper"
typeconf "cocostudio::TextureData"
-- typeconf "cocostudio::TransformHelp"
typeconf "cocostudio::Tween"

typeconf "cocostudio::timeline::InnerActionType"

typeconf "cocostudio::timeline::Frame"
    .ATTR('setNode', {ARG1 = '@addref(node ^)'})
    .ATTR('getNode', {RET = '@addref(node ^)'})
    .ATTR('setTimeline', {ARG1 = '@addref(timeline ^)'})
    .ATTR('getTimeline', {RET = '@addref(timeline ^)'})

typeconf "cocostudio::timeline::AlphaFrame"
typeconf "cocostudio::timeline::AnchorPointFrame"
typeconf "cocostudio::timeline::BlendFuncFrame"
typeconf "cocostudio::timeline::ColorFrame"
typeconf "cocostudio::timeline::EventFrame"
typeconf "cocostudio::timeline::InnerActionFrame"
typeconf "cocostudio::timeline::PlayableFrame"
typeconf "cocostudio::timeline::PositionFrame"
typeconf "cocostudio::timeline::RotationFrame"
typeconf "cocostudio::timeline::SkewFrame"
typeconf "cocostudio::timeline::RotationSkewFrame"
typeconf "cocostudio::timeline::ScaleFrame"
typeconf "cocostudio::timeline::TextureFrame"
typeconf "cocostudio::timeline::VisibleFrame"
typeconf "cocostudio::timeline::ZOrderFrame"

typeconf "cocostudio::timeline::ActionTimelineCache"
typeconf "cocostudio::timeline::ActionTimelineData"

typeconf "cocostudio::timeline::ActionTimelineNode"
    .ATTR('setRoot', {ARG1 = '@addref(root ^)'})
    .ATTR('getRoot', {RET = '@addref(root ^)'})
    .ATTR('setActionTimeline', {ARG1 = '@addref(actionTimeline ^)'})
    .ATTR('getActionTimeline', {RET = '@addref(actionTimeline ^)'})

typeconf "cocostudio::timeline::BoneNode"
    .ATTR('getChildBones', {RET = '@addref(bones |)'})
    .ATTR('getAllSubBones', {RET = '@addref(subBones |)'})
    .ATTR('getRootSkeletonNode', {RET = '@addref(rootSkeletonNode ^)'})
    .ATTR('addSkin', {ARG1 = '@addref(skins |)'})
    .ATTR('getVisibleSkins', {RET = '@addref(skins |)'})
    .ATTR('getSkins', {RET = '@addref(skins |)'})
    .ATTR('getAllSubSkins', {RET = '@addref(subSkins |)'})

local SkeletonNode = typeconf "cocostudio::timeline::SkeletonNode"
SkeletonNode.ATTR('getBoneNode', {RET = '@addref(boneNodes |)'})
SkeletonNode.ATTR('getAllSubBonesMap', {RET = '@addref(boneNodes |)'})

typeconf "cocostudio::timeline::SkinNode"

typeconf "cocostudio::timeline::Timeline"
    .ATTR('getFrames', {RET = '@addref(frames |)'})
    .ATTR('addFrame', {ARG1 = '@addref(frames |)'})
    .ATTR('insertFrame', {ARG1 = '@addref(frames |)'})
    .ATTR('removeFrame', {ARG1 = '@delref(frames |)'})
    .ATTR('setNode', {ARG1 = '@addref(node ^)'})
    .ATTR('getNode', {RET = '@addref(node ^)'})
    .ATTR('setActionTimeline', {ARG1 = '@addref(actionTimeline ^)'})
    .ATTR('getActionTimeline', {RET = '@addref(actionTimeline ^)'})

local ActionTimeline = typeconf "cocostudio::timeline::ActionTimeline"
ActionTimeline.ATTR('addTimeline', {ARG1 = "@addref(timelines |)"})
ActionTimeline.ATTR('removeTimeline', {ARG1 = "@delref(timelines |)"})
ActionTimeline.ATTR('getTimelines', {RET = "@addref(timelines |)"})
ActionTimeline.CALLBACK {
    NAME = "setAnimationEndCallFunc",
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_MAKER = "makeFrameEndCallbackTag(#0, #1)",
}
ActionTimeline.CALLBACK {
    NAME = "setFrameEventCallFunc",
    TAG_MAKER = "frameEventCallFunc",
    TAG_MODE = 'OLUA_TAG_REPLACE',
    NULLABLE = true,
}
ActionTimeline.CALLBACK {
    NAME = 'clearFrameEventCallFunc',
    TAG_MAKER = "frameEventCallFunc",
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
}
ActionTimeline.CALLBACK {
    NAME = 'setLastFrameCallFunc',
    TAG_MAKER = 'lastFrameCallFunc',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    NULLABLE = true,
}
ActionTimeline.CALLBACK {
    NAME = 'clearLastFrameCallFunc',
    TAG_MAKER = "lastFrameCallFunc",
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
}
ActionTimeline.CALLBACK {
    NAME = 'addFrameEndCallFunc',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_MAKER = "makeFrameEndCallbackTag(#1, #2)",
}
ActionTimeline.CALLBACK {
    NAME = 'removeFrameEndCallFunc',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_MAKER = "makeFrameEndCallbackTag(#1, #2)",
}
ActionTimeline.CALLBACK {
    NAME = 'removeFrameEndCallFuncs',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_MAKER = 'makeFrameEndCallbackTag(#1, "")',
}
ActionTimeline.CALLBACK {
    NAME = 'clearFrameEndCallFuncs',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_MAKER = 'makeFrameEndCallbackTag(-1, "")',
}
ActionTimeline.INSERT('addAnimationInfo', {
    BEFORE = [[
        if (olua_getfield(L, 2, "clipEndCallBack") == LUA_TFUNCTION) {
            void *cb_store = (void *)self;
            std::string cb_tag = makeFrameEndCallbackTag(arg1.endIndex, arg1.name);
            std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), -1, OLUA_TAG_REPLACE);
            lua_Integer cb_ctx = olua_context(L);
            arg1.clipEndCallBack = [cb_store, cb_name, cb_ctx]() {
                lua_State *L = olua_mainthread(NULL);
                olua_checkhostthread();
    
                if (L != NULL && olua_context(L) == cb_ctx) {
                    int top = lua_gettop(L);
    
                    olua_callback(L, cb_store, cb_name.c_str(), 0);
    
                    lua_settop(L, top);
                }
            };
        }
    ]]
})
ActionTimeline.INSERT('removeAnimationInfo', {
    BEFORE = [[
        auto info = self->getAnimationInfo(arg1);
        std::string cb_tag = makeFrameEndCallbackTag(info.endIndex, arg1);
        void *cb_store = (void *)self;
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBSTARTWITH);
    ]]
})
ActionTimeline.INSERT('setFrameEventCallFunc', {
    CALLBACK_BEFORE = [[
        if (arg1->getTimeline() && arg1->getTimeline()->getActionTimeline()) {
            olua_push_cppobj<cocostudio::timeline::ActionTimeline>(L, arg1->getTimeline()->getActionTimeline());
            olua_push_cppobj<cocostudio::timeline::Timeline>(L, arg1->getTimeline());
            olua_push_cppobj<cocostudio::timeline::Frame>(L, arg1);
            olua_addref(L, -3, "timelines", -2, OLUA_MODE_MULTIPLE);
            olua_addref(L, -2, "frames", -1, OLUA_MODE_MULTIPLE);
            lua_pop(L, 3);
        }
    ]]
})

return M