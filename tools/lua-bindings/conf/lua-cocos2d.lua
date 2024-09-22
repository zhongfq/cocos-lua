module 'cocos2d'

output_dir '../../frameworks/cclua/src/lua-bindings'

api_dir"../../addons/cclua/cocos2d"

headers [[
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "audio/include/AudioEngine.h"
#include "cocos2d.h"
#include "base/TGAlib.h"
#include "ui/CocosGUI.h"
#include "navmesh/CCNavMesh.h"
]]

codeblock[[
static const std::string makeScheduleCallbackTag(const std::string &key)
{
    return "schedule." + key;
}]]

luacls(function (cppname)
    if cppname == 'ResolutionPolicy' then
        return 'cc.' .. cppname
    else
        cppname = string.gsub(cppname, "^cocos2d::network::", "cc.")
        cppname = string.gsub(cppname, "^cocos2d::", "cc.")
        cppname = string.gsub(cppname, "::", ".")
        return cppname
    end
end)

typeconf 'cocos2d::RenderTargetFlag'
typeconf 'cocos2d::ClearFlag'
typeconf 'cocos2d::MATRIX_STACK_TYPE'
typeconf 'cocos2d::Director::Projection'

typeconf 'cocos2d::UserDefault'
    .exclude 'setDelegate'

typeconf 'cocos2d::Ref'
    .exclude 'retain'
    .exclude 'release'
    .exclude 'autorelease'
    .func '__gc'
        .body [[
        {
            return cclua_ccobjgc(L);
        }]]

typeconf 'cocos2d::Clonable'
typeconf 'cocos2d::Console'
typeconf 'cocos2d::Acceleration'

typeconf 'cocos2d::Director'
    .exclude 'getCocos2dThreadId'
    .func 'getRunningScene' .ret '@addref(scenes |)'
    .func 'runWithScene' .arg1 '@addref(scenes |)'
    .func 'pushScene' .arg1 '@addref(scenes |)'
    .func 'replaceScene' .ret '@delref(scenes ~)' .arg1 '@addref(scenes |)'
    .func 'popScene' .ret '@delref(scenes ~)'
    .func 'popToRootScene' .ret '@delref(scenes ~)'
    .func 'popToSceneStackLevel' .ret '@delref(scenes ~)'
    .func 'getOpenGLView' .ret '@addref(^)'
    .func 'setOpenGLView' .arg1 '@addref(^)'
    .func 'getTextureCache' .ret '@addref(^)'
    .func 'getNotificationNode' .ret '@addref(^)'
    .func 'setNotificationNode' .arg1 '@addref(^)'
    .func 'convertToGL' .arg1 '@pack'
    .func 'convertToUI' .arg1 '@pack'
    .func 'getEventDispatcher' .ret '@addref(^)'
    .func 'setEventDispatcher' .arg1 '@addref(^)'
    .func 'getScheduler' .ret '@addref(^)'
    .func 'setScheduler' .arg1 '@addref(^)'
    .func 'getActionManager' .ret '@addref(^)'
    .func 'setActionManager' .arg1 '@addref(^)'
    .func 'getRenderer' .ret '@addref(^)'

typeconf 'cocos2d::ccSchedulerFunc'

typeconf 'cocos2d::Scheduler'
    .exclude 'performFunctionInCocosThread'
    .codeblock[[
        template <typename T> bool doScheduleUpdate(lua_State *L)
        {
            if (olua_isa<T>(L, 2)) {
                auto self = olua_checkobj<cocos2d::Scheduler>(L, 1);
                auto target = olua_checkobj<T>(L, 2);
                lua_Integer priority = olua_checkinteger(L, 3);
                bool paused = olua_checkbool(L, 4);
                self->scheduleUpdate(target, (int)priority, paused);
                return true;
            }

            return false;
        }
    ]]
    .func 'schedule'
        .tag_mode 'replace'
        .tag_maker 'makeScheduleCallbackTag(#-1)'
        .tag_store '2' -- 2th void *target
    .func 'unschedule'
        .tag_mode 'equal'
        .tag_maker 'makeScheduleCallbackTag(#1)'
        .tag_store '2' -- 2th void *target
    .func 'unscheduleAllForTarget'
        .tag_mode 'startwith'
        .tag_maker 'makeScheduleCallbackTag("")'
        .tag_store '1' -- 1th void *target
    .func 'unscheduleAll'
        .tag_maker 'makeScheduleCallbackTag("")'
        .tag_mode 'startwith'
    .func 'scheduleUpdate'
        .body [[
        {
            if (doScheduleUpdate<cocos2d::Scheduler>(L) ||
                doScheduleUpdate<cocos2d::ActionManager>(L) ||
                doScheduleUpdate<cocos2d::Node>(L) ||
                doScheduleUpdate<cocos2d::Action>(L) ||
                doScheduleUpdate<cocos2d::Component>(L) ||
                doScheduleUpdate<cocos2d::ActionManager>(L)) {
                return 0;
            }

            luaL_error(L, "unsupport type: %s", olua_typename(L, 2));

            return 0;
        }]]

--
-- event & event listener
--
typeconf 'cocos2d::EventDispatcher'
    .codeblock[[
        static int _olua_fun_cocos2d_EventDispatcher_addEventListenerWithFixedPriority(lua_State *L);

        static void doRemoveEventListenersForTarget(lua_State *L, cocos2d::Node *target, bool recursive, const char *refname)
        {
            if (olua_getrawobj(L, target)) {
                olua_delallrefs(L, -1, refname);
                lua_pop(L, 1);
            }
            if (recursive) {
                const auto &children = target->getChildren();
                for (const auto& child : children)
                {
                    doRemoveEventListenersForTarget(L, child, recursive, refname);
                }
            }
        }
    ]]
    .func 'addEventListenerWithSceneGraphPriority' .arg1 '@addref(listeners | 3)'
    .func 'addEventListenerWithFixedPriority' .arg1 '@addref(listeners |)'
    .func 'removeCustomEventListeners' .ret '@delref(listeners ~)'
    .func 'removeEventListener' .ret '@delref(listeners ~)' .arg1 '@delref(listeners |)'
    .func 'removeEventListenersForType' .ret '@delref(listeners ~)'
    .func 'removeAllEventListeners' .ret '@delref(listeners ~)'
    .func 'removeEventListenersForTarget'
        .insert_before [[
            bool recursive = false;
            auto node = olua_checkobj<cocos2d::Node>(L, 2);
            if (lua_gettop(L) >= 3) {
                recursive = olua_tobool(L, 3);
            }
            doRemoveEventListenersForTarget(L, node, recursive, "listeners");
        ]]
    .func 'addEventListener'
        .body [[
        {
            lua_settop(L, 2);
            olua_pushinteger(L, 1);
            return _olua_fun_cocos2d_EventDispatcher_addEventListenerWithFixedPriority(L);
        }]]
    .func 'addCustomEventListener'
        .ret '@addref(listeners |)'
        .tag_maker '(#1)'
        .tag_store '-1'
        .tag_mode 'new'

typeconf 'cocos2d::EventListener::Type'

typeconf 'cocos2d::EventListener'
    .exclude 'init'
    .prop 'available' .get 'bool checkAvailable()'

typeconf 'cocos2d::EventListenerTouchOneByOne::ccTouchBeganCallback'
typeconf 'cocos2d::EventListenerTouchOneByOne::ccTouchCallback'
typeconf 'cocos2d::EventListenerTouchOneByOne'
typeconf 'cocos2d::EventListenerTouchAllAtOnce::ccTouchesCallback'
typeconf 'cocos2d::EventListenerTouchAllAtOnce'

typeconf 'cocos2d::EventListenerCustom'
    .func 'create' .tag_store '-1' .tag_maker 'listener'

typeconf 'cocos2d::EventListenerKeyboard'

typeconf 'cocos2d::EventListenerAcceleration'
    .func 'create' .tag_store '-1' .tag_maker 'listener'

typeconf 'cocos2d::EventListenerFocus'
typeconf 'cocos2d::EventListenerMouse'
typeconf 'cocos2d::Event::Type'
typeconf 'cocos2d::Event'
typeconf 'cocos2d::EventCustom'
typeconf 'cocos2d::EventListenerController'
typeconf 'cocos2d::EventTouch::EventCode'
typeconf 'cocos2d::EventTouch'
typeconf 'cocos2d::EventKeyboard'
typeconf 'cocos2d::EventAcceleration'
typeconf 'cocos2d::EventFocus'
typeconf 'cocos2d::EventMouse::MouseEventType'
typeconf 'cocos2d::EventMouse::MouseButton'
typeconf 'cocos2d::EventMouse'
typeconf 'cocos2d::EventKeyboard::KeyCode'
typeconf 'cocos2d::Touch::DispatchMode'
typeconf 'cocos2d::EventController::ControllerEventType'
typeconf 'cocos2d::EventController'

typeconf 'cocos2d::Touch'
typeconf 'cocos2d::Controller::Key'

typeconf 'cocos2d::Controller'
    .exclude 'receiveExternalKeyEvent'

typeconf 'cocos2d::AudioProfile'
typeconf 'cocos2d::AudioEngine::AudioState'

typeconf 'cocos2d::AudioEngine'
    .codeblock[[
        NS_CC_BEGIN
        class LuaAudioEngine : public cocos2d::AudioEngine
        {
        public:
            static std::list<int> getAudioIDs(const std::string &path)
            {
                std::list<int> list;
                auto it = _audioPathIDMap.find(path);
                if (it != _audioPathIDMap.end()) {
                    list = it->second;
                }
                return list;
            }
        };
        NS_CC_END

        static const std::string makeAudioEngineFinishCallbackTag(lua_Integer id)
        {
            if (id < 0) {
                return "finishCallback.";
            } else {
                char buf[64];
                snprintf(buf, sizeof(buf), "finishCallback.%d", (int)id);
                return std::string(buf);
            }
        }
    ]]
    .func 'uncache'
        .insert_before [[
            std::string path = olua_checkstring(L, 1);
            std::list<int> ids = cocos2d::LuaAudioEngine::getAudioIDs(path);
            void *cb_store = olua_pushclassobj<cocos2d::AudioEngine>(L);
            for (auto id : ids) {
                std::string tag = makeAudioEngineFinishCallbackTag((lua_Integer)id);
                olua_removecallback(L, cb_store, tag.c_str(), OLUA_TAG_EQUAL);
            }
        ]]
    .func 'stop' .tag_mode 'equal' .tag_maker 'makeAudioEngineFinishCallbackTag(#1)'
    .func 'stopAll' .tag_mode "startwith" .tag_maker 'makeAudioEngineFinishCallbackTag(-1)'
    .func 'uncacheAll' .tag_mode "startwith" .tag_maker 'makeAudioEngineFinishCallbackTag(-1)'
    .func 'setFinishCallback'
        .arg2 '@nullable'
        .tag_maker 'makeAudioEngineFinishCallbackTag(#1)'
        .tag_scope 'once'
    .func 'preload' .tag_scope 'once'

typeconf 'cocos2d::ApplicationProtocol::Platform'
typeconf 'cocos2d::LanguageType'
typeconf 'cocos2d::ApplicationProtocol'

typeconf 'cocos2d::Application'
    .exclude 'setStartupScriptFilename'
    .exclude 'applicationScreenSizeChanged'

typeconf 'cocos2d::Device'
    .exclude 'getTextureDataForText'

typeconf 'cocos2d::ResizableBuffer'
typeconf 'cocos2d::FileUtils::Status'

typeconf 'cocos2d::FileUtils'
    .extend 'cocos2d::FileUtilsExtend'
    .func "getStringFromFile" .tag_scope 'once' .tag_mode 'new'
    .func "getDataFromFile" .tag_scope 'once' .tag_mode 'new'
    .func "writeStringToFile" .tag_scope 'once' .tag_mode 'new'
    .func "writeDataToFile" .tag_scope 'once' .tag_mode 'new'
    .func "writeValueMapToFile" .tag_scope 'once' .tag_mode 'new'
    .func "writeValueVectorToFile" .tag_scope 'once' .tag_mode 'new'
    .func "isFileExist" .tag_scope 'once' .tag_mode 'new'
    .func "isDirectoryExist" .tag_scope 'once' .tag_mode 'new'
    .func "createDirectory" .tag_scope 'once' .tag_mode 'new'
    .func "removeDirectory" .tag_scope 'once' .tag_mode 'new'
    .func "removeFile" .tag_scope 'once' .tag_mode 'new'
    .func "renameFile" .tag_scope 'once' .tag_mode 'new'
    .func "getFileSize" .tag_scope 'once' .tag_mode 'new'
    .func "listFilesAsync" .tag_scope 'once' .tag_mode 'new'
    .func "listFilesRecursivelyAsync" .tag_scope 'once' .tag_mode 'new'

typeconf 'ResolutionPolicy'
typeconf 'cocos2d::GLView'

typeconf 'cocos2d::GLViewImpl'
    .exclude 'create'
    .exclude 'createWithRect'
    .exclude 'createWithFullScreen'

typeconf 'cocos2d::Image::Format'

typeconf 'cocos2d::Image'
    .extend 'cocos2d::ImageExtend'

typeconf 'cocos2d::Properties::Type'
typeconf 'cocos2d::Properties'

typeconf 'cocos2d::Material'
typeconf 'cocos2d::Renderer'
typeconf 'cocos2d::RenderCommand::Type'
typeconf 'cocos2d::CustomCommand::DrawType'
typeconf 'cocos2d::PipelineDescriptor'
typeonly 'cocos2d::Technique'
typeonly 'cocos2d::Pass'
typeonly 'cocos2d::RenderState'
typeconf 'cocos2d::RenderCommand'
typeconf 'cocos2d::CustomCommand'
typeconf 'cocos2d::MeshCommand'
    .exclude 'listenRendererRecreated'

typeconf 'cocos2d::TextureCache'
    .codeblock[[
        static const std::string makeTextureCacheCallbackTag(const std::string &key)
        {
            return "addImageAsync." + key;
        }
    ]]
    .func 'addImageAsync'
        .tag_maker "makeTextureCacheCallbackTag(#1)"
        .tag_mode 'replace'
        .tag_scope 'once'
        .tag_usepool 'false'
    .func 'addImageAsync(const std::string &, const std::function<void (cocos2d::Texture2D *)> &, const std::string &)'
        .tag_maker "makeTextureCacheCallbackTag(#-1)"
        .tag_mode 'replace'
        .tag_scope 'once'
        .tag_usepool 'false'
    .func 'unbindImageAsync'
        .tag_maker 'makeTextureCacheCallbackTag(#1)'
        .tag_mode 'equal'
    .func 'unbindAllImageAsync'
        .tag_maker 'makeTextureCacheCallbackTag("")'
        .tag_mode 'startwith'

typeconf 'cocos2d::Texture2D'
typeconf 'cocos2d::TextureCube'
typeconf 'cocos2d::TextureAtlas'

typeconf 'cocos2d::network::WebSocket::ErrorCode'
typeconf 'cocos2d::network::WebSocket::State'
typeconf 'cocos2d::network::WebSocket::Delegate'

typeconf 'cocos2d::network::WebSocket'
    .func 'init'
        .body [[
        {
            std::vector<std::string> protocols;
            auto self =  olua_toobj<cocos2d::network::WebSocket>(L, 1);
            auto delegate = olua_checkobj<cocos2d::network::WebSocket::Delegate>(L, 2);
            std::string url = olua_tostring(L, 3);
            std::string cafile = olua_optstring(L, 5, "");

            if (!lua_isnil(L, 4)) {
                luaL_checktype(L, 4, LUA_TTABLE);
                int len = (int)lua_rawlen(L, 4);
                protocols.reserve(len);
                for (int i = 1; i <= len; i++) {
                    lua_rawgeti(L, 4, i);
                    protocols.push_back(olua_checkstring(L, -1));
                    lua_pop(L, 1);
                }
            }

            self->init(*delegate, url, protocols.size() > 0 ? &protocols : nullptr, cafile);
            olua_addref(L, 1, "delegate", 2, OLUA_REF_ALONE);

            return 0;
        }
    ]]

typeconf 'cocos2d::LuaWebSocketDelegate'
    .luaname(function (name)
        return string.gsub(name, 'Callback', '')
    end)

typeconf 'cocos2d::ActionManager'
typeconf 'cocos2d::Component'

typeconf 'cocos2d::LuaComponent'
    .luaname(function (name)
        return string.gsub(name, 'Callback', '')
    end)

-- node
local push_node_parent = [[
    if (!self->getParent()) {
        return 0;
    }
    olua_pushobj<cocos2d::Node>(L, self->getParent());
    int parent = lua_gettop(L);
]]

local check_node_parent = [[
    if (!self->getParent()) {
        luaL_error(L, "parent is nullptr");
    }
]]

typeconf 'cocos2d::Node'
    .extend 'cocos2d::NodeExtend'
    .exclude 'scheduleUpdateWithPriorityLua'
    .func 'addChild' .arg1 '@addref(children |)'
    .func 'getChildByTag' .ret '@addref(children |)'
    .func 'getChildByName' .ret '@addref(children |)'
    .func 'getChildren' .ret '@addref(children |)'
    .func 'removeFromParent' .ret '@delref(children | parent)' .insert_before(push_node_parent)
    .func 'removeFromParentAndCleanup' .ret '@delref(children | parent)' .insert_before(push_node_parent)
    .func 'removeChild' .arg1 '@delref(children |)'
    .func 'removeChildByTag' .ret '@delref(children ~)'
    .func 'removeChildByName' .ret '@delref(children ~)'
    .func 'removeAllChildren' .ret '@delref(children *)'
    .func 'removeAllChildrenWithCleanup' .ret '@delref(children *)'
    .func 'getProgramState' .ret '@addref(^)'
    .func 'setProgramState' .arg1 '@addref(^)'
    .func 'getEventDispatcher' .ret '@addref(^)'
    .func 'setEventDispatcher' .arg1 '@addref(^)'
    .func 'getActionManager' .ret '@addref(^)'
    .func 'setActionManager' .arg1 '@addref(^)'
    .func 'runAction' .ret '@delref(actions ~)' .arg1 '@addref(actions |)'
    .func 'stopAllActions' .ret '@delref(actions ~)'
    .func 'stopAction' .ret '@delref(actions ~)'
    .func 'stopActionByTag' .ret '@delref(actions ~)'
    .func 'stopAllActionsByTag' .ret '@delref(actions ~)'
    .func 'stopActionsByFlags' .ret '@delref(actions ~)'
    .func 'getActionByTag' .ret '@addref(actions |)'
    .func 'setScheduler' .arg1 '@addref(^)'
    .func 'getScheduler' .ret '@addref(^)'
    .func 'convertToNodeSpace' .arg1 '@pack'
    .func 'convertToWorldSpace' .arg1 '@pack'
    .func 'convertToNodeSpaceAR' .arg1 '@pack'
    .func 'convertToWorldSpaceAR' .arg1 '@pack'
    .func 'getComponent' .ret '@addref(components |)'
    .func 'addComponent' .arg1 '@addref(components |)'
    .func 'removeComponent' .ret '@delref(components ~)'
    .func 'removeAllComponents' .ret '@delref(components *)'
    .macro '#if CC_USE_PHYSICS'
    .func 'setPhysicsBody' .arg1 '@addref(^)'
    .func 'getPhysicsBody' .ret '@addref(^)'
    .macro '#endif'
    .func 'onEnter' .insert_before(check_node_parent)
    .func 'onExit' .insert_before(check_node_parent)
    .func 'getBounds' .ret '@unpack'
    .prop 'x' .get 'float getPositionX()' .set 'void setPositionX(float)'
    .prop 'y' .get 'float getPositionY()' .set 'void setPositionY(float)'
    .prop 'z' .get 'float getPositionZ()' .set 'void setPositionZ(float)'
    .func 'setOnEnterCallback' .arg1 '@nullable'
    .func 'getOnEnterCallback' .ret '@nullable'
    .func 'setOnExitCallback' .arg1 '@nullable'
    .func 'getOnExitCallback' .ret '@nullable'
    .func 'setOnEnterTransitionDidFinishCallback' .arg1 '@nullable'
    .func 'getOnEnterTransitionDidFinishCallback' .ret '@nullable'
    .func 'setOnExitTransitionDidStartCallback' .arg1 '@nullable'
    .func 'getOnExitTransitionDidStartCallback' .ret '@nullable'
    .func 'scheduleOnce'
        .tag_maker 'makeScheduleCallbackTag(#-1)'
        .tag_mode 'replace'
        .tag_scope 'once'
    .func 'schedule'
        .tag_maker "makeScheduleCallbackTag(#-1)"
        .tag_mode 'replace'
    .func 'unschedule'
        .tag_maker "makeScheduleCallbackTag(#1)"
        .tag_mode 'equal'
    .func 'unscheduleAllCallbacks'
        .tag_maker 'makeScheduleCallbackTag("")'
        .tag_mode "startwith"
    .func 'enumerateChildren'
        .tag_mode 'new'
        .tag_scope 'invoker'

typeconf 'cocos2d::BlendProtocol'
typeconf 'cocos2d::TextureProtocol'
typeconf 'cocos2d::AtlasNode'
typeconf 'cocos2d::sImageTGA'
typeconf 'cocos2d::TileMapAtlas'
typeconf 'cocos2d::ClippingNode'
typeconf 'cocos2d::MotionStreak'

typeconf 'cocos2d::ProtectedNode'
    .func 'addProtectedChild' .arg1 '@addref(protectedChildren |)'
    .func 'getProtectedChildByTag' .ret '@addref(protectedChildren |)'
    .func 'removeProtectedChild' .arg1 '@delref(protectedChildren |)'
    .func 'removeProtectedChildByTag' .ret '@delref(protectedChildren ~)'
    .func 'removeAllProtectedChildren' .ret '@delref(protectedChildren *)'
    .func 'removeAllProtectedChildrenWithCleanup' .ret '@delref(protectedChildren *)'

typeconf 'cocos2d::DrawNode'

typeconf 'cocos2d::ParallaxNode'
    .func 'addChild' .arg1 '@addref(children |)'

typeconf 'cocos2d::TextHAlignment'
typeconf 'cocos2d::TextVAlignment'
typeconf 'cocos2d::GlyphCollection'
typeconf 'cocos2d::LabelEffect'
typeconf 'cocos2d::Label::LabelType'
typeconf 'cocos2d::Label::Overflow'
typeconf 'cocos2d::LabelProtocol'
typeconf 'cocos2d::Label'
typeconf 'cocos2d::LabelAtlas'

typeconf 'cocos2d::FontAtlas'
    .exclude 'getTextures'
    .exclude 'prepareLetterDefinitions'

typeconf 'cocos2d::ClippingRectangleNode'

typeconf 'cocos2d::RenderTexture'
    .extend 'cocos2d::RenderTextureExtend'
    .func 'saveToFile'
        .tag_usepool 'false'
        .tag_scope 'once'
    .func 'saveToFileAsNonPMA'
        .tag_maker 'saveToFile'
        .tag_usepool 'false'
        .tag_scope 'once'
    .func 'newImage'
        .tag_mode 'new'
        .tag_usepool 'false'
        .tag_scope 'once'

typeconf 'cocos2d::ProgressTimer::Type'
typeconf 'cocos2d::ProgressTimer'
typeconf 'cocos2d::AnimationFrame'
typeconf 'cocos2d::Animation'
typeconf 'cocos2d::SpriteFrame'
typeconf 'cocos2d::Sprite'
typeconf 'cocos2d::SpriteBatchNode'
typeconf 'cocos2d::SpriteFrameCache'
typeconf 'cocos2d::AnimationCache'

typeconf 'cocos2d::Scene'
    .exclude 'initWithPhysics'
    .macro '#if CC_USE_PHYSICS'
    .func 'getPhysicsWorld' .ret '@addref(^)'
    .macro '#endif'
    .macro '#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION'
    .func 'getPhysics3DWorld' .ret '@addref(^)'
    .func 'setPhysics3DDebugCamera'
    .macro '#endif'
    .macro '#if (CC_USE_PHYSICS || (CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION))'
    .func 'createWithPhysics'
    .macro '#endif'
    .macro '#if CC_USE_NAVMESH'
    .func 'setNavMesh'
    .func 'getNavMesh'
    .func 'setNavMeshDebugCamera'
    .macro '#endif'
    .macro '#if (CC_USE_PHYSICS || (CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION) || CC_USE_NAVMESH)'
    .func 'stepPhysicsAndNavigation'
    .macro '#endif'

typeconf 'cocos2d::Layer'
typeconf 'cocos2d::LayerColor'
typeconf 'cocos2d::LayerGradient'
typeconf 'cocos2d::LayerRadialGradient'
typeconf 'cocos2d::LayerMultiplex'

typeconf 'cocos2d::TransitionScene::Orientation'

local function typeconfTransition(name)
    local cls = typeconf(name)
    cls.func 'create' .arg2 '@addref(scenes |)'
    cls.func 'easeActionWithAction' .arg1 '@addref(action ^)'
    return cls
end

typeconfTransition 'cocos2d::TransitionScene'
    .exclude 'initWithDuration'

typeconfTransition 'cocos2d::TransitionEaseScene'
typeconfTransition 'cocos2d::TransitionSceneOriented'
typeconfTransition 'cocos2d::TransitionRotoZoom'
typeconfTransition 'cocos2d::TransitionJumpZoom'
typeconfTransition 'cocos2d::TransitionMoveInL'
typeconfTransition 'cocos2d::TransitionMoveInR'
typeconfTransition 'cocos2d::TransitionMoveInT'
typeconfTransition 'cocos2d::TransitionMoveInB'
typeconfTransition 'cocos2d::TransitionSlideInL'
typeconfTransition 'cocos2d::TransitionSlideInR'
typeconfTransition 'cocos2d::TransitionSlideInB'
typeconfTransition 'cocos2d::TransitionSlideInT'
typeconfTransition 'cocos2d::TransitionShrinkGrow'
typeconfTransition 'cocos2d::TransitionFlipX'
typeconfTransition 'cocos2d::TransitionFlipY'
typeconfTransition 'cocos2d::TransitionFlipAngular'
typeconfTransition 'cocos2d::TransitionZoomFlipX'
typeconfTransition 'cocos2d::TransitionZoomFlipY'
typeconfTransition 'cocos2d::TransitionZoomFlipAngular'
typeconfTransition 'cocos2d::TransitionFade'
typeconfTransition 'cocos2d::TransitionCrossFade'
typeconfTransition 'cocos2d::TransitionTurnOffTiles'
typeconfTransition 'cocos2d::TransitionSplitCols'
typeconfTransition 'cocos2d::TransitionSplitRows'
typeconfTransition 'cocos2d::TransitionFadeTR'
typeconfTransition 'cocos2d::TransitionFadeBL'
typeconfTransition 'cocos2d::TransitionFadeUp'
typeconfTransition 'cocos2d::TransitionFadeDown'
typeconfTransition 'cocos2d::TransitionPageTurn'
typeconfTransition 'cocos2d::TransitionProgress'
typeconfTransition 'cocos2d::TransitionProgressRadialCCW'
typeconfTransition 'cocos2d::TransitionProgressRadialCW'
typeconfTransition 'cocos2d::TransitionProgressHorizontal'
typeconfTransition 'cocos2d::TransitionProgressVertical'
typeconfTransition 'cocos2d::TransitionProgressInOut'
typeconfTransition 'cocos2d::TransitionProgressOutIn'

typeconf 'cocos2d::IMEDelegate'
typeconf 'cocos2d::TextFieldDelegate'
typeconf 'cocos2d::TextFieldTTF'

typeconf 'cocos2d::LightType'
typeconf 'cocos2d::LightFlag'
typeconf 'cocos2d::BaseLight'
typeconf 'cocos2d::DirectionLight'
typeconf 'cocos2d::PointLight'
typeconf 'cocos2d::SpotLight'
typeconf 'cocos2d::AmbientLight'
typeconf 'cocos2d::CameraFlag'
typeconf 'cocos2d::Camera::Type'

typeconf 'cocos2d::Camera'
    .exclude 'isVisibleInFrustum'
    .exclude 'setFrameBufferObject'

typeconf 'cocos2d::CameraBackgroundBrush::BrushType'
typeconf 'cocos2d::CameraBackgroundBrush'
typeconf 'cocos2d::CameraBackgroundDepthBrush'
typeconf 'cocos2d::CameraBackgroundColorBrush'
typeconf 'cocos2d::CameraBackgroundSkyBoxBrush'

typeconf 'cocos2d::PlayableProtocol'
typeconf 'cocos2d::ParticleBatchNode'
typeconf 'cocos2d::ParticleSystem::Mode'
typeconf 'cocos2d::ParticleSystem::PositionType'
typeconf 'cocos2d::ParticleSystem'
typeconf 'cocos2d::ParticleSystemQuad'
typeconf 'cocos2d::ParticleExplosion'
typeconf 'cocos2d::ParticleFire'
typeconf 'cocos2d::ParticleFireworks'
typeconf 'cocos2d::ParticleFlower'
typeconf 'cocos2d::ParticleGalaxy'
typeconf 'cocos2d::ParticleMeteor'
typeconf 'cocos2d::ParticleRain'
typeconf 'cocos2d::ParticleSmoke'
typeconf 'cocos2d::ParticleSnow'
typeconf 'cocos2d::ParticleSpiral'
typeconf 'cocos2d::ParticleSun'

typeconf 'cocos2d::SAXDelegator'
typeconf 'cocos2d::TMXTileFlags'
typeconf 'cocos2d::TMXObjectGroup'

typeconf 'cocos2d::TMXLayer'

typeconf 'cocos2d::TMXLayerInfo'
typeconf 'cocos2d::TMXMapInfo'
typeconf 'cocos2d::TMXTilesetInfo'
typeconf 'cocos2d::TMXTiledMap'
typeconf 'cocos2d::FastTMXTiledMap'

typeconf 'cocos2d::FastTMXLayer'

macro '#if CC_USE_NAVMESH'
typeconf 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag'
typeconf 'cocos2d::NavMeshAgent'
typeconf 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag'
typeconf 'cocos2d::NavMeshObstacle'
typeconf 'cocos2d::NavMesh'
macro '#endif'