module 'cocos2d_studio'

output_dir '../../frameworks/cclua/src/lua-bindings'

api_dir"../../addons/cclua/cocos2d"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "editor-support/cocostudio/CocoStudio.h"
]]

codeblock[[
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

luaopen [[cclua::runtime::registerFeature("cocostudio", true);]]

luacls(function (cppname)
    cppname = string.gsub(cppname, '^cocos2d::', 'cc.')
    cppname = string.gsub(cppname, '^cocostudio::', 'ccs.')
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

exclude_type 'cocos2d::ObjectFactory::TInfo'
exclude_type 'cocos2d::ObjectFactory::Instance'
exclude_type 'cocostudio::DataReaderHelper::DataInfo'
exclude_type 'cocostudio::DataReaderHelper::_DataInfo'
exclude_type 'cocostudio::stExpCocoNode'
exclude_type 'flatbuffers::NodeTree'
exclude_type 'rapidjson::Value'
exclude_type 'cocostudio::SEL_ParseEvent'

typeconf 'cocostudio::timeline::AnimationInfo'

typeconf "cocos2d::CSLoader"
    .func 'createNode'
        .tag_mode 'new'
        .tag_scope 'invoker'
    .func 'createNodeWithVisibleSize'
        .tag_mode 'new'
        .tag_scope 'invoker'

typeconf "cocostudio::MovementEventType"
typeconf "cocostudio::DisplayType"

typeconf "cocostudio::ActionFrame"
    .func 'getAction'
        .ret '@addref(action |)'

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
    .func 'setMovementEventCallFunc' .arg1 '@nullable'
    .func 'setFrameEventCallFunc' .arg1 '@nullable'

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
    .func 'removeFromParent'
        .ret '@delref(children | parent)'
        .insert_before [[
            if (!self->getParent()) {
                return 0;
            }
            olua_pushobj<cocos2d::Node>(L, self->getParent());
            int parent = lua_gettop(L);
        ]]

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
    .func 'setTarget' .arg1 '@nullable'

typeconf "cocostudio::Skin"
typeconf "cocostudio::SpriteDisplayData"
typeconf "cocostudio::SpriteFrameCacheHelper"
typeconf "cocostudio::TextureData"
-- typeconf "cocostudio::TransformHelp"
typeconf "cocostudio::Tween"

typeconf "cocostudio::timeline::InnerActionType"

typeconf "cocostudio::timeline::Frame"
    .func 'setNode' .arg1 '@addref(^)'
    .func 'getNode' .ret '@addref(^)'
    .func 'setTimeline' .arg1 '@addref(^)'
    .func 'getTimeline' .ret '@addref(^)'

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
    .func 'setRoot' .arg1 '@addref(^)'
    .func 'getRoot' .ret '@addref(^)'
    .func 'setActionTimeline' .arg1 '@addref(^)'
    .func 'getActionTimeline' .ret '@addref(^)'

typeconf "cocostudio::timeline::BoneNode"
    .func 'getChildBones' .ret '@addref(bones |)'
    .func 'getAllSubBones' .ret '@addref(subBones |)'
    .func 'getRootSkeletonNode' .ret '@addref(rootSkeletonNode ^)'
    .func 'addSkin' .arg1 '@addref(skins |)'
    .func 'getVisibleSkins' .ret '@addref(skins |)'
    .func 'getSkins' .ret '@addref(skins |)'
    .func 'getAllSubSkins' .ret '@addref(subSkins |)'

typeconf "cocostudio::timeline::SkeletonNode"
    .func 'getBoneNode' .ret '@addref(boneNodes |)'
    .func 'getAllSubBonesMap' .ret '@addref(boneNodes |)'

typeconf "cocostudio::timeline::SkinNode"

typeconf "cocostudio::timeline::Timeline"
    .func 'getFrames' .ret '@addref(frames |)'
    .func 'addFrame' .arg1 '@addref(frames |)'
    .func 'insertFrame' .arg1 '@addref(frames |)'
    .func 'removeFrame' .arg1 '@delref(frames |)'
    .func 'setNode' .arg1 '@addref(^)'
    .func 'getNode' .ret '@addref(^)'
    .func 'setActionTimeline' .arg1 '@addref(^)'
    .func 'getActionTimeline' .ret '@addref(^)'

typeconf "cocostudio::timeline::ActionTimeline"
    .func 'addTimeline' .arg1 "@addref(timelines |)"
    .func 'removeTimeline' .arg1 "@delref(timelines |)"
    .func 'getTimelines' .ret "@addref(timelines |)"
    .func 'setAnimationEndCallFunc'
        .tag_mode 'replace'
        .tag_maker "makeFrameEndCallbackTag(#0, #1)"
    .func 'setFrameEventCallFunc'
        .tag_maker "frameEventCallFunc"
        .tag_mode 'replace'
        .arg1 '@nullable'
        .insert_cbefore [[
            if (arg1->getTimeline() && arg1->getTimeline()->getActionTimeline()) {
                olua_pushobj<cocostudio::timeline::ActionTimeline>(L, arg1->getTimeline()->getActionTimeline());
                olua_pushobj<cocostudio::timeline::Timeline>(L, arg1->getTimeline());
                olua_pushobj<cocostudio::timeline::Frame>(L, arg1);
                olua_addref(L, -3, "timelines", -2, OLUA_REF_MULTI);
                olua_addref(L, -2, "frames", -1, OLUA_REF_MULTI);
                lua_pop(L, 3);
            }
        ]]
    .func 'clearFrameEventCallFunc'
        .tag_maker "frameEventCallFunc"
        .tag_mode 'startwith'
    .func 'setLastFrameCallFunc'
        .tag_maker 'lastFrameCallFunc'
        .tag_mode 'replace'
        .arg1 '@nullable'
    .func 'clearLastFrameCallFunc'
        .tag_maker "lastFrameCallFunc"
        .tag_mode 'startwith'
    .func 'addFrameEndCallFunc'
        .tag_mode 'replace'
        .tag_maker "makeFrameEndCallbackTag(#1, #2)"
    .func 'removeFrameEndCallFunc'
        .tag_mode 'startwith'
        .tag_maker "makeFrameEndCallbackTag(#1, #2)"
    .func 'removeFrameEndCallFuncs'
        .tag_mode 'startwith'
        .tag_maker 'makeFrameEndCallbackTag(#1, "")'
    .func 'clearFrameEndCallFuncs'
        .tag_mode 'startwith'
        .tag_maker 'makeFrameEndCallbackTag(-1, "")'
    .func 'addAnimationInfo'
        .insert_before [[
            if (olua_getfield(L, 2, "clipEndCallBack") == LUA_TFUNCTION) {
                void *cb_store = (void *)self;
                std::string cb_tag = makeFrameEndCallbackTag(arg1.endIndex, arg1.name);
                std::string cb_name = olua_setcallback(L, cb_store, -1, cb_tag.c_str(), OLUA_TAG_REPLACE);
                olua_Context cb_ctx = olua_context(L);
                arg1.clipEndCallBack = [cb_store, cb_name, cb_ctx]() {
                    lua_State *L = olua_mainthread(NULL);
                    olua_checkhostthread();

                    if (olua_contextequal(L, cb_ctx)) {
                        int top = lua_gettop(L);

                        olua_callback(L, cb_store, cb_name.c_str(), 0);

                        lua_settop(L, top);
                    }
                };
            }
        ]]
    .func 'removeAnimationInfo'
        .insert_before [[
            auto info = self->getAnimationInfo(arg1);
            std::string cb_tag = makeFrameEndCallbackTag(info.endIndex, arg1);
            void *cb_store = (void *)self;
            olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_STARTWITH);
        ]]
