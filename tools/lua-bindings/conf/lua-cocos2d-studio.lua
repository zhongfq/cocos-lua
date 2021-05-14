module 'cocos2d_studio'

path = '../../frameworks/libxgame/src/lua-bindings'

headers = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "cocos2d.h"
#include "editor-support/cocostudio/CocoStudio.h"
]]

chunk = [[
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


make_luacls = function (cppname)
    cppname = string.gsub(cppname, '^cocos2d::', 'cc.')
    cppname = string.gsub(cppname, '^cocostudio::', 'ccs.')
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

include 'conf/exclude-type.lua'

exclude 'cocos2d::ObjectFactory::TInfo'
exclude 'cocos2d::ObjectFactory::Instance *'
exclude 'cocos2d::ObjectFactory::Instance'
exclude 'cocostudio::DataReaderHelper::DataInfo *'
exclude 'cocostudio::stExpCocoNode *'
exclude 'flatbuffers::NodeTree *'
exclude 'rapidjson::Value'
exclude 'cocostudio::SEL_ParseEvent'

typeconv 'cocostudio::timeline::AnimationInfo'
    .exclude 'clipEndCallBack'

typeconf "cocos2d::CSLoader"
    .callback {
        name = 'createNode',
        tag_mode = 'OLUA_TAG_NEW',
        tag_scope = 'function',
    }
    .callback {
        name = 'createNodeWithVisibleSize',
        tag_mode = 'OLUA_TAG_NEW',
        tag_scope = 'function',
    }

typeconf "cocostudio::MovementEventType"
typeconf "cocostudio::DisplayType"

typeconf "cocostudio::ActionFrame"
    .attr('getAction', {ret = '@addref(action |)'})

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

typeconf "cocostudio::ArmatureAnimation"
    .callback {
        name = 'setMovementEventCallFunc',
        nullable = true,
    }
    .callback {
        name = 'setFrameEventCallFunc',
        nullable = true,
    }

typeconf "cocostudio::ArmatureData"
typeconf "cocostudio::ArmatureDataManager"
typeconf "cocostudio::DisplayData"
typeconf "cocostudio::ArmatureDisplayData"
typeconf "cocostudio::ArmatureMovementDispatcher"
    .exclude "*" --TODO

typeconf "cocostudio::BaseData"
typeconf "cocostudio::BaseTriggerAction"
typeconf "cocostudio::BaseTriggerCondition"
typeconf "cocostudio::BatchNode"

typeconf "cocostudio::Bone"
    .attr('removeFromParent', {ret = '@delref(children | parent)'})
    .insert({'removeFromParent'}, {
        before = [[
            if (!self->getParent()) {
                return 0;
            }
            olua_push_cppobj<cocos2d::Node>(L, self->getParent());
            int parent = lua_gettop(L);
        ]]
    })

typeconf "cocostudio::BoneData"
typeconf "cocostudio::CocoLoader"
    .exclude "*" --TODO

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
    .exclude 'getParseCallBackMap'
    .exclude 'getParseObjectMap'

typeconf "cocostudio::InputDelegate"
typeconf "cocostudio::MovementBoneData"
typeconf "cocostudio::MovementData"
-- typeconf "cocostudio::MovementEvent"
typeconf "cocostudio::ParticleDisplayData"
-- typeconf "cocostudio::RelativeData"
typeconf "cocostudio::SceneReader::AttachComponentType"

typeconf "cocostudio::SceneReader"
    .callback {
        name = 'setTarget',
        nullable = true,
    }

typeconf "cocostudio::Skin"
typeconf "cocostudio::SpriteDisplayData"
typeconf "cocostudio::SpriteFrameCacheHelper"
typeconf "cocostudio::TextureData"
-- typeconf "cocostudio::TransformHelp"
typeconf "cocostudio::Tween"

typeconf "cocostudio::timeline::InnerActionType"

typeconf "cocostudio::timeline::Frame"
    .attr('setNode', {arg1 = '@addref(node ^)'})
    .attr('getNode', {ret = '@addref(node ^)'})
    .attr('setTimeline', {arg1 = '@addref(timeline ^)'})
    .attr('getTimeline', {ret = '@addref(timeline ^)'})

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
    .attr('setRoot', {arg1 = '@addref(root ^)'})
    .attr('getRoot', {ret = '@addref(root ^)'})
    .attr('setActionTimeline', {arg1 = '@addref(actionTimeline ^)'})
    .attr('getActionTimeline', {ret = '@addref(actionTimeline ^)'})

typeconf "cocostudio::timeline::BoneNode"
    .attr('getChildBones', {ret = '@addref(bones |)'})
    .attr('getAllSubBones', {ret = '@addref(subBones |)'})
    .attr('getRootSkeletonNode', {ret = '@addref(rootSkeletonNode ^)'})
    .attr('addSkin', {arg1 = '@addref(skins |)'})
    .attr('getVisibleSkins', {ret = '@addref(skins |)'})
    .attr('getSkins', {ret = '@addref(skins |)'})
    .attr('getAllSubSkins', {ret = '@addref(subSkins |)'})

typeconf "cocostudio::timeline::SkeletonNode"
    .attr('getBoneNode', {ret = '@addref(boneNodes |)'})
    .attr('getAllSubBonesMap', {ret = '@addref(boneNodes |)'})

typeconf "cocostudio::timeline::SkinNode"

typeconf "cocostudio::timeline::Timeline"
    .attr('getFrames', {ret = '@addref(frames |)'})
    .attr('addFrame', {arg1 = '@addref(frames |)'})
    .attr('insertFrame', {arg1 = '@addref(frames |)'})
    .attr('removeFrame', {arg1 = '@delref(frames |)'})
    .attr('setNode', {arg1 = '@addref(node ^)'})
    .attr('getNode', {ret = '@addref(node ^)'})
    .attr('setActionTimeline', {arg1 = '@addref(actionTimeline ^)'})
    .attr('getActionTimeline', {ret = '@addref(actionTimeline ^)'})

typeconf "cocostudio::timeline::ActionTimeline"
    .attr('addTimeline', {arg1 = "@addref(timelines |)"})
    .attr('removeTimeline', {arg1 = "@delref(timelines |)"})
    .attr('getTimelines', {ret = "@addref(timelines |)"})
    .callback {
        name = "setAnimationEndCallFunc",
        tag_mode = 'OLUA_TAG_REPLACE',
        tag_maker = "makeFrameEndCallbackTag(#0, #1)",
    }
    .callback {
        name = "setFrameEventCallFunc",
        tag_maker = "frameEventCallFunc",
        tag_mode = 'OLUA_TAG_REPLACE',
        nullable = true,
    }
    .callback {
        name = 'clearFrameEventCallFunc',
        tag_maker = "frameEventCallFunc",
        tag_mode = 'OLUA_TAG_SUBSTARTWITH',
    }
    .callback {
        name = 'setLastFrameCallFunc',
        tag_maker = 'lastFrameCallFunc',
        tag_mode = 'OLUA_TAG_REPLACE',
        nullable = true,
    }
    .callback {
        name = 'clearLastFrameCallFunc',
        tag_maker = "lastFrameCallFunc",
        tag_mode = 'OLUA_TAG_SUBSTARTWITH',
    }
    .callback {
        name = 'addFrameEndCallFunc',
        tag_mode = 'OLUA_TAG_REPLACE',
        tag_maker = "makeFrameEndCallbackTag(#1, #2)",
    }
    .callback {
        name = 'removeFrameEndCallFunc',
        tag_mode = 'OLUA_TAG_SUBSTARTWITH',
        tag_maker = "makeFrameEndCallbackTag(#1, #2)",
    }
    .callback {
        name = 'removeFrameEndCallFuncs',
        tag_mode = 'OLUA_TAG_SUBSTARTWITH',
        tag_maker = 'makeFrameEndCallbackTag(#1, "")',
    }
    .callback {
        name = 'clearFrameEndCallFuncs',
        tag_mode = 'OLUA_TAG_SUBSTARTWITH',
        tag_maker = 'makeFrameEndCallbackTag(-1, "")',
    }
    .insert('addAnimationInfo', {
        before = [[
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
    .insert('removeAnimationInfo', {
        before = [[
            auto info = self->getAnimationInfo(arg1);
            std::string cb_tag = makeFrameEndCallbackTag(info.endIndex, arg1);
            void *cb_store = (void *)self;
            olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBSTARTWITH);
        ]]
    })
    .insert('setFrameEventCallFunc', {
        callback_before = [[
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
