local olua = require "olua"
local autoconf = require "autoconf"
local M = autoconf.typemod 'cocos2d'
local typeconf = M.typeconf
local include = M.include

M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "audio/include/AudioEngine.h"
#include "audio/include/SimpleAudioEngine.h"
#include "vr/CCVRGenericRenderer.h"
#include "vr/CCVRGenericHeadTracker.h"
]]
M.CHUNK = [[
static const std::string makeScheduleCallbackTag(const std::string &key)
{
    return "schedule." + key;
}]]

include('conf/lua-cocos2d-types.lua')

M.MAKE_LUACLS = function (cppname)
    if cppname == 'ResolutionPolicy' then
        return 'cc.' .. cppname
    else
        cppname = string.gsub(cppname, '^cocos2d::experimental::', 'cc.')
        cppname = string.gsub(cppname, '^cocos2d::network::', 'cc.')
        cppname = string.gsub(cppname, "^cocos2d::", "cc.")
        cppname = string.gsub(cppname, "^CocosDenshion::", "cc.")
        cppname = string.gsub(cppname, "::", ".")
        return cppname
    end
end

M.EXCLUDE_TYPE = require "conf.exclude-type"

M.EXCLUDE_PASS = function (cppcls, fn, decl)
    if cppcls == 'cocos2d::FileUtils' then
        return string.find(decl, 'std::function')
    end
end

typeconf 'cocos2d::UserDefault'
    .EXCLUDE 'setDelegate'

local Ref = typeconf 'cocos2d::Ref'
Ref.EXCLUDE 'retain'
Ref.EXCLUDE 'release'
Ref.EXCLUDE 'autorelease'
Ref.FUNC('__gc', '{\n    return xlua_ccobjgc(L);\n}')

typeconf 'cocos2d::Acceleration'
typeconf 'cocos2d::MATRIX_STACK_TYPE'
typeconf 'cocos2d::Director::Projection'

local Director = typeconf 'cocos2d::Director'
Director.EXCLUDE 'getCocos2dThreadId'
Director.ATTR('getRunningScene', {RET = '@addref(scenes |)'})
Director.ATTR('runWithScene', {ARG1 = '@addref(scenes |)'})
Director.ATTR('pushScene', {ARG1 = '@addref(scenes |)'})
Director.ATTR('replaceScene', {RET = '@delref(scenes ~)', ARG1 = '@addref(scenes |)'})
Director.ATTR('popScene', {RET = '@delref(scenes ~)'})
Director.ATTR('popToRootScene', {RET = '@delref(scenes ~)'})
Director.ATTR('popToSceneStackLevel', {RET = '@delref(scenes ~)'})
Director.ATTR('getOpenGLView', {RET = '@addref(openGLView ^)'})
Director.ATTR('setOpenGLView', {ARG1 = '@addref(openGLView ^)'})
Director.ATTR('getTextureCache', {RET = '@addref(textureCache ^)'})
Director.ATTR('getNotificationNode', {RET = '@addref(notificationNode ^)'})
Director.ATTR('setNotificationNode', {ARG1 = '@addref(notificationNode ^)'})
Director.ATTR('convertToGL', {ARG1 = '@pack'})
Director.ATTR('convertToUI', {ARG1 = '@pack'})
Director.ATTR('getEventDispatcher', {RET = '@addref(eventDispatcher ^)'})
Director.ATTR('setEventDispatcher', {ARG1 = '@addref(eventDispatcher ^)'})
Director.ATTR('getScheduler', {RET = '@addref(scheduler ^)'})
Director.ATTR('setScheduler', {ARG1 = '@addref(scheduler ^)'})
Director.ATTR('getActionManager', {RET = '@addref(actionManager ^)'})
Director.ATTR('setActionManager', {ARG1 = '@addref(actionManager ^)'})
Director.ATTR('getRenderer', {RET = '@addref(renderer ^)'})

local Scheduler = typeconf 'cocos2d::Scheduler'
Scheduler.EXCLUDE 'scheduleScriptFunc'
Scheduler.EXCLUDE 'unscheduleScriptEntry'
Scheduler.EXCLUDE 'performFunctionInCocosThread'
Scheduler.ENUM('PRIORITY_SYSTEM', 'cocos2d::Scheduler::PRIORITY_SYSTEM')
Scheduler.ENUM('PRIORITY_NON_SYSTEM_MIN', 'cocos2d::Scheduler::PRIORITY_NON_SYSTEM_MIN')
Scheduler.CHUNK = [[
template <typename T> bool doScheduleUpdate(lua_State *L)
{
    const char *cls = olua_getluatype<T>(L);
    if (olua_is_cppobj(L, 2, cls)) {
        auto self = olua_checkobj<cocos2d::Scheduler>(L, 1);
        auto target = olua_checkobj<T>(L, 2);
        lua_Integer priority = olua_checkinteger(L, 3);
        bool paused = olua_checkboolean(L, 4);
        self->scheduleUpdate(target, (int)priority, paused);
        return true;
    }
    
    return false;
}]]
Scheduler.CALLBACK {
    FUNCS = {
        'void schedule(const std::function<void(float)>& callback, void *target, float interval, bool paused, const std::string& key)',
        'void schedule(const std::function<void(float)>& callback, void *target, float interval, unsigned int repeat, float delay, bool paused, const std::string& key)',
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = 2, -- 2th void *target
}
Scheduler.CALLBACK {
    FUNCS = {'void unschedule(const std::string& key, void *target)'},
    TAG_MAKER = 'makeScheduleCallbackTag(#1)',
    TAG_STORE = 2, -- 2th void *target
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
}
Scheduler.CALLBACK {
    FUNCS = {'void unscheduleAllForTarget(void *target)'},
    TAG_MAKER = 'makeScheduleCallbackTag("")',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = 1, -- 1th void *target
}
Scheduler.CALLBACK {
    FUNCS = {'void unscheduleAll()'},
    TAG_MAKER = 'makeScheduleCallbackTag("")',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
}
Scheduler.FUNC('scheduleUpdate', [[
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
}]])

--
-- event & event listener
--
local EventDispatcher = typeconf 'cocos2d::EventDispatcher'
EventDispatcher.ATTR('addEventListenerWithSceneGraphPriority', {ARG1 = '@addref(listeners | 3)'})
EventDispatcher.ATTR('addEventListenerWithFixedPriority', {ARG1 = '@addref(listeners |)'})
EventDispatcher.ATTR('addCustomEventListener', {RET = '@addref(listeners |)'})
EventDispatcher.ATTR('removeCustomEventListeners', {RET = '@delref(listeners ~)'})
EventDispatcher.ATTR('removeEventListener', {RET = '@delref(listeners ~)'})
EventDispatcher.ATTR('removeEventListenersForType', {RET = '@delref(listeners ~)'})
EventDispatcher.ATTR('removeAllEventListeners', {RET = '@delref(listeners ~)'})
EventDispatcher.CALLBACK {
    NAME = 'addCustomEventListener',
    TAG_MAKER = '(#1)',
    TAG_STORE = 'return',
    TAG_MODE = 'OLUA_TAG_NEW',
}
EventDispatcher.CHUNK = [[
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
}]]
EventDispatcher.INJECT('removeEventListenersForTarget', {
    BEFORE = [[
        bool recursive = false;
        auto node = olua_checkobj<cocos2d::Node>(L, 2);
        if (lua_gettop(L) >= 3) {
            recursive = olua_toboolean(L, 3);
        }
        doRemoveEventListenersForTarget(L, node, recursive, "listeners");
    ]]
})

typeconf 'cocos2d::EventListener::Type'

local EventListener = typeconf 'cocos2d::EventListener'
EventListener.EXCLUDE 'init'
EventListener.PROP('available', 'bool checkAvailable()')

typeconf 'cocos2d::EventListenerTouchOneByOne'
typeconf 'cocos2d::EventListenerTouchAllAtOnce'

local EventListenerCustom = typeconf 'cocos2d::EventListenerCustom'
EventListenerCustom.CALLBACK {
    FUNCS = {'static EventListenerCustom* create(const std::string& eventName, const std::function<void(@local EventCustom*)>& callback)'},
    TAG_MAKER = 'listener',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = 'return',
}

typeconf 'cocos2d::EventListenerKeyboard'

local EventListenerAcceleration = typeconf 'cocos2d::EventListenerAcceleration'
EventListenerAcceleration.CALLBACK {
    FUNCS = {'static EventListenerAcceleration* create(const std::function<void(@local Acceleration*, @local Event*)>& callback)'},
    TAG_MAKER = 'listener',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = 'return',
}

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

local Controller = typeconf 'cocos2d::Controller'
Controller.EXCLUDE 'receiveExternalKeyEvent'

typeconf 'cocos2d::experimental::AudioProfile'
typeconf 'cocos2d::experimental::AudioEngine::AudioState'

local AudioEngine = typeconf 'cocos2d::experimental::AudioEngine'
AudioEngine.CHUNK = [[
NS_CC_BEGIN
class LuaAudioEngine : public cocos2d::experimental::AudioEngine
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
        sprintf(buf, "finishCallback.%d", (int)id);
        return std::string(buf);
    }
}]]
AudioEngine.INJECT('uncache', {
    BEFORE = [[
        std::string path = olua_checkstring(L, 1);
        std::list<int> ids = cocos2d::LuaAudioEngine::getAudioIDs(path);
        const char *cls = olua_getluatype<cocos2d::experimental::AudioEngine>(L);
        void *callback_store_obj = (void *)olua_pushclassobj(L, cls);
        for (auto id : ids) {
            std::string tag = makeAudioEngineFinishCallbackTag((lua_Integer)id);
            olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
        }
    ]]
})
AudioEngine.CALLBACK {
    FUNCS = {'static void stop(int audioID)'},
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
}
AudioEngine.CALLBACK {
    FUNCS = {'static void stopAll()'},
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
    TAG_MODE = "OLUA_TAG_SUBSTARTWITH",
}
AudioEngine.CALLBACK {
    FUNCS = {'static void uncacheAll()'},
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
    TAG_MODE = "OLUA_TAG_SUBSTARTWITH",
}
AudioEngine.CALLBACK {
    FUNCS = {'static void setFinishCallback(int audioID, @nullable const std::function<void(int,const std::string&)>& callback)'},
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
    TAG_MODE = "OLUA_TAG_REPLACE",
    TAG_SCOPE = 'once',
}
AudioEngine.CALLBACK {
    FUNCS = {
        'static void preload(const std::string& filePath)',
        'static void preload(const std::string& filePath, std::function<void(bool isSuccess)> callback)',
    },
    TAG_MAKER = 'preload',
    TAG_MODE = "OLUA_TAG_REPLACE",
    TAG_SCOPE = 'once',
}

typeconf 'CocosDenshion::SimpleAudioEngine'

typeconf 'cocos2d::ApplicationProtocol::Platform'
typeconf 'cocos2d::LanguageType'
typeconf 'cocos2d::ApplicationProtocol'

local Application = typeconf 'cocos2d::Application'
Application.EXCLUDE 'setStartupScriptFilename'
Application.EXCLUDE 'applicationScreenSizeChanged'

local Device = typeconf 'cocos2d::Device'
Device.EXCLUDE 'getTextureDataForText'

typeconf 'cocos2d::ResizableBuffer'
typeconf 'cocos2d::FileUtils::Status'

typeconf 'cocos2d::FileUtils'
    .ATTR('getFileDataFromZip', {RET = '@length(arg3)', ARG3 = '@out'})
    .ATTR('listFilesRecursively', {ARG2 = '@out'})

typeconf 'ResolutionPolicy'

local GLView = typeconf 'cocos2d::GLView'
GLView.EXCLUDE 'handleTouchesBegin'
GLView.EXCLUDE 'handleTouchesMove'
GLView.EXCLUDE 'handleTouchesEnd'
GLView.EXCLUDE 'handleTouchesCancel'
GLView.EXCLUDE 'getNSGLContext'
GLView.EXCLUDE 'getCocoaWindow'
GLView.EXCLUDE 'getEAGLView'
GLView.ATTR('setVR', {ARG1 = '@addref(vr ^)'})
GLView.ATTR('getVR', {RET = '@addref(vr ^)'})

local GLViewImpl = typeconf 'cocos2d::GLViewImpl'
GLViewImpl.EXCLUDE 'create'
GLViewImpl.EXCLUDE 'createWithRect'
GLViewImpl.EXCLUDE 'createWithFullScreen'
GLViewImpl.EXCLUDE 'createWithEAGLView'
GLViewImpl.EXCLUDE 'convertAttrs'

typeconf 'cocos2d::Image::Format'

local Image = typeconf 'cocos2d::Image'
Image.CHUNK = [[
NS_CC_BEGIN
class LuaImage : public cocos2d::Image {
public:
    static bool getPNGPremultipliedAlphaEnabled() { return PNG_PREMULTIPLIED_ALPHA_ENABLED; };
};
NS_CC_END
]]
Image.FUNC('getPNGPremultipliedAlphaEnabled', [[
{
    lua_pushboolean(L, cocos2d::LuaImage::getPNGPremultipliedAlphaEnabled());
    return 1;
}]])

typeconf 'cocos2d::Renderer'
typeconf 'cocos2d::VertexAttrib'
typeconf 'cocos2d::Uniform'

local GLProgram = typeconf 'cocos2d::GLProgram'
GLProgram.EXCLUDE 'getUniformFlags'

typeconf 'cocos2d::GLProgramCache'

local GLProgramState = typeconf 'cocos2d::GLProgramState'
GLProgramState.EXCLUDE 'setVertexAttribCallback'
GLProgramState.EXCLUDE 'setUniformCallback'
GLProgramState.ATTR('setGLProgram', {ARG1 = '@addref(glProgram ^)'})
GLProgramState.ATTR('getGLProgram', {RET = '@addref(glProgram ^)'})
GLProgramState.ATTR('setNodeBinding', {ARG1 = '@addref(nodeBinding ^)'})
GLProgramState.ATTR('getNodeBinding', {RET = '@addref(nodeBinding ^)'})

local TextureCache = typeconf 'cocos2d::TextureCache'
TextureCache.CHUNK = [[
static const std::string makeTextureCacheCallbackTag(const std::string &key)
{
    return "addImageAsync." + key;
}]]
TextureCache.CALLBACK {
    FUNCS = {
        'void addImageAsync(const std::string &filepath, const std::function<void(Texture2D*)>& callback)',
        'void addImageAsync(const std::string &path, const std::function<void(Texture2D*)>& callback, const std::string& callbackKey)',
    },
    TAG_MAKER = {'makeTextureCacheCallbackTag(#1)', 'makeTextureCacheCallbackTag(#-1)'},
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_SCOPE = 'once',
}
TextureCache.CALLBACK {
    FUNCS = {'void unbindImageAsync(const std::string &filename)'},
    TAG_MAKER = 'makeTextureCacheCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
}
TextureCache.CALLBACK {
    FUNCS = {'void unbindAllImageAsync()'},
    TAG_MAKER = 'makeTextureCacheCallbackTag("")',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
}

typeconf 'cocos2d::Texture2D::PixelFormat'
local Texture2D = typeconf 'cocos2d::Texture2D'
Texture2D.EXCLUDE 'getPixelFormatInfoMap'

typeconf 'cocos2d::TextureCube'

typeconf 'cocos2d::TextureAtlas'
typeconf 'cocos2d::VRIHeadTracker'
typeconf 'cocos2d::VRIRenderer'
typeconf 'cocos2d::VRGenericRenderer'
typeconf 'cocos2d::VRGenericHeadTracker'

typeconf 'cocos2d::network::WebSocket::ErrorCode'
typeconf 'cocos2d::network::WebSocket::State'
typeconf 'cocos2d::network::WebSocket::Delegate'

local WebSocket = typeconf 'cocos2d::network::WebSocket'
WebSocket.FUNC('init', [[
{
    std::vector<std::string> protocols;
    auto self = olua_toobj<cocos2d::network::WebSocket>(L, 1);
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

    olua_addref(L, 1, "delegate", 2, OLUA_MODE_SINGLE);

    return 1;
}]])

local LuaWebSocketDelegate = typeconf 'cocos2d::LuaWebSocketDelegate'
LuaWebSocketDelegate.MAKE_LUANAME = function (name)
    return string.gsub(name, 'Callback', '')
end

typeconf 'cocos2d::ActionManager'

-- actions
local Action = typeconf 'cocos2d::Action'
Action.EXCLUDE 'calculateAngles'
Action.EXCLUDE 'init'
Action.EXCLUDE 'initWithAction'
Action.EXCLUDE 'initWithAnimation'
Action.EXCLUDE 'initWithDuration'
Action.EXCLUDE 'initWithFlipX'
Action.EXCLUDE 'initWithFlipY'
Action.EXCLUDE 'initWithFunction'
Action.EXCLUDE 'initWithPosition'
Action.EXCLUDE 'initWithTwoActions'
Action.EXCLUDE 'setReverseAction'

typeconf 'cocos2d::FiniteTimeAction'

local Speed = typeconf 'cocos2d::Speed'
Speed.ATTR('create', {ARG1 = '@addref(innerAction ^)'})
Speed.ATTR('setInnerAction', {ARG1 = '@addref(innerAction ^)'})
Speed.ATTR('getInnerAction', {RET = '@addref(innerAction ^)'})

typeconf 'cocos2d::Follow'
typeconf 'cocos2d::tweenfunc'
typeconf 'cocos2d::ActionInterval'

local Sequence = typeconf 'cocos2d::Sequence'
Sequence.ATTR('createWithTwoActions', {ARG1 = '@addref(autoref |)', ARG2 = '@addref(autoref |)'})
Sequence.FUNC('create', [[
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    auto ret = new cocos2d::Sequence();
    ret->autorelease();
    olua_push_cppobj<cocos2d::Sequence>(L, ret);

    for (int i = 1; i <= n; i++) {
        auto obj = olua_checkobj<cocos2d::FiniteTimeAction>(L, i);
        actions.pushBack(obj);
        olua_addref(L, -1, ".autoref", i, OLUA_MODE_MULTIPLE);
    }

    ret->init(actions);
    
    return 1;
}]])

local Repeat = typeconf 'cocos2d::Repeat'
Repeat.ATTR('create', {ARG1 = '@addref(innerAction ^)'})
Repeat.ATTR('setInnerAction', {ARG1 = '@addref(innerAction ^)'})
Repeat.ATTR('getInnerAction', {RET = '@addref(innerAction ^)'})

local RepeatForever = typeconf 'cocos2d::RepeatForever'
RepeatForever.ATTR('create', {ARG1 = '@addref(innerAction ^)'})
RepeatForever.ATTR('setInnerAction', {ARG1 = '@addref(innerAction ^)'})
RepeatForever.ATTR('getInnerAction', {RET = '@addref(innerAction ^)'})

local Spawn = typeconf 'cocos2d::Spawn'
Spawn.ATTR('createWithTwoActions', {ARG1 = '@addref(autoref |)', ARG2 = '@addref(autoref |)'})
Spawn.FUNC('create', [[
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    auto ret = new cocos2d::Spawn();
    ret->autorelease();
    olua_push_cppobj<cocos2d::Spawn>(L, ret);

    for (int i = 1; i <= n; i++) {
        auto obj = olua_checkobj<cocos2d::FiniteTimeAction>(L, i);
        actions.pushBack(obj);
        olua_addref(L, -1, ".autoref", i, OLUA_MODE_MULTIPLE);
    }
    
    ret->init(actions);

    return 1;
}]])

typeconf 'cocos2d::RotateTo'
typeconf 'cocos2d::RotateBy'

local MoveBy = typeconf 'cocos2d::MoveBy'
MoveBy.ATTR('create', {ARG2 = '@pack'})

local MoveTo = typeconf 'cocos2d::MoveTo'
MoveTo.ATTR('create', {ARG2 = '@pack'})

typeconf 'cocos2d::SkewTo'
typeconf 'cocos2d::SkewBy'
typeconf 'cocos2d::ResizeTo'
typeconf 'cocos2d::ResizeBy'

local BezierBy = typeconf 'cocos2d::BezierBy'
BezierBy.ATTR('create', {ARG2 = '@pack'})

local BezierTo = typeconf 'cocos2d::BezierTo'
BezierTo.ATTR('create', {ARG2 = '@pack'})

local JumpBy =typeconf 'cocos2d::JumpBy'
JumpBy.ATTR('create', {ARG2 = '@pack'})

local JumpTo =typeconf 'cocos2d::JumpTo'
JumpTo.ATTR('create', {ARG2 = '@pack'})

typeconf 'cocos2d::ScaleTo'
typeconf 'cocos2d::ScaleBy'
typeconf 'cocos2d::Blink'
typeconf 'cocos2d::FadeTo'
typeconf 'cocos2d::FadeIn'
typeconf 'cocos2d::FadeOut'
typeconf 'cocos2d::TintTo'
typeconf 'cocos2d::TintBy'
typeconf 'cocos2d::DelayTime'

local ReverseTime = typeconf 'cocos2d::ReverseTime'
ReverseTime.ATTR('create', {ARG1 = '@addref(autoref |)'})

typeconf 'cocos2d::Animate'

local TargetedAction = typeconf 'cocos2d::TargetedAction'
TargetedAction.ATTR('create', {ARG2 = '@addref(autoref |)'})

local ActionFloat = typeconf 'cocos2d::ActionFloat'
ActionFloat.CALLBACK {
    FUNCS = {'static ActionFloat* create(float duration, float from, float to, std::function<void(float value)> callback)'},
    TAG_MAKER = 'ActionFloat',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = 'return',
}

typeconf 'cocos2d::ProgressTo'
typeconf 'cocos2d::ProgressFromTo'

local ActionEase = typeconf 'cocos2d::ActionEase'
ActionEase.ATTR('getInnerAction', {RET = '@addref(innerAction ^)'})

local function typeconfEase(name)
    local cls = typeconf(name)
    cls.ATTR('create', {ARG1 = '@addref(innerAction ^)'})
    return cls
end

typeconfEase 'cocos2d::EaseRateAction'
typeconfEase 'cocos2d::EaseExponentialIn'
typeconfEase 'cocos2d::EaseExponentialOut'
typeconfEase 'cocos2d::EaseExponentialInOut'
typeconfEase 'cocos2d::EaseSineIn'
typeconfEase 'cocos2d::EaseSineOut'
typeconfEase 'cocos2d::EaseSineInOut'
typeconfEase 'cocos2d::EaseBounceIn'
typeconfEase 'cocos2d::EaseBounceOut'
typeconfEase 'cocos2d::EaseBounceInOut'
typeconfEase 'cocos2d::EaseBackIn'
typeconfEase 'cocos2d::EaseBackOut'
typeconfEase 'cocos2d::EaseBackInOut'
typeconfEase 'cocos2d::EaseQuadraticActionIn'
typeconfEase 'cocos2d::EaseQuadraticActionOut'
typeconfEase 'cocos2d::EaseQuadraticActionInOut'
typeconfEase 'cocos2d::EaseQuarticActionIn'
typeconfEase 'cocos2d::EaseQuarticActionOut'
typeconfEase 'cocos2d::EaseQuarticActionInOut'
typeconfEase 'cocos2d::EaseQuinticActionIn'
typeconfEase 'cocos2d::EaseQuinticActionOut'
typeconfEase 'cocos2d::EaseQuinticActionInOut'
typeconfEase 'cocos2d::EaseCircleActionIn'
typeconfEase 'cocos2d::EaseCircleActionOut'
typeconfEase 'cocos2d::EaseCircleActionInOut'
typeconfEase 'cocos2d::EaseCubicActionIn'
typeconfEase 'cocos2d::EaseCubicActionOut'
typeconfEase 'cocos2d::EaseCubicActionInOut'
typeconfEase 'cocos2d::EaseIn'
typeconfEase 'cocos2d::EaseOut'
typeconfEase 'cocos2d::EaseInOut'
typeconfEase 'cocos2d::EaseElastic'
typeconfEase 'cocos2d::EaseElasticIn'
typeconfEase 'cocos2d::EaseElasticOut'
typeconfEase 'cocos2d::EaseElasticInOut'
typeconfEase 'cocos2d::EaseBezierAction'

local PointArray = typeconf 'cocos2d::PointArray'
PointArray.EXCLUDE 'getControlPoints' -- TODO
PointArray.EXCLUDE 'setControlPoints' -- TODO

typeconf 'cocos2d::CardinalSplineTo'
typeconf 'cocos2d::CardinalSplineBy'
typeconf 'cocos2d::CatmullRomTo'
typeconf 'cocos2d::CatmullRomBy'
typeconf "cocos2d::ActionInstant"
typeconf "cocos2d::Show"
typeconf "cocos2d::Hide"
typeconf "cocos2d::ToggleVisibility"
typeconf "cocos2d::RemoveSelf"
typeconf "cocos2d::FlipX"
typeconf "cocos2d::FlipY"
typeconf "cocos2d::Place"

local CallFunc = typeconf "cocos2d::CallFunc"
CallFunc.CALLBACK {
    FUNCS = {'static CallFunc * create(const std::function<void()>& func)'},
    TAG_MAKER = 'CallFunc',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = 'return',
}

local Component = typeconf 'cocos2d::Component'
Component.EXCLUDE 'onEnter'
Component.EXCLUDE 'onExit'
Component.EXCLUDE 'onAdd'
Component.EXCLUDE 'onRemove'
Component.ATTR('getOwner', {RET = '@addref(owner ^)'})
Component.ATTR('setOwner', {ARG1 = '@addref(owner ^)'})

local LuaComponent = typeconf 'cocos2d::LuaComponent'
LuaComponent.MAKE_LUANAME = function (name)
    return string.gsub(name, 'Callback', '')
end

-- node
local Node = typeconf 'cocos2d::Node'
Node.EXCLUDE 'enumerateChildren'
Node.EXCLUDE 'scheduleUpdateWithPriorityLua'
Node.EXCLUDE '_setLocalZOrder'
Node.ATTR('addChild', {ARG1 = '@addref(children |)'})
Node.ATTR('getChildByTag', {RET = '@addref(children |)'})
Node.ATTR('getChildByName', {RET = '@addref(children |)'})
Node.ATTR('getChildren', {RET = '@addref(children |)'})
Node.ATTR('removeFromParent', {RET = '@delref(children | parent)'})
Node.ATTR('removeFromParentAndCleanup', {RET = '@delref(children | parent)'})
Node.ATTR('removeChild', {ARG1 = '@delref(children |)'})
Node.ATTR('removeChildByTag', {RET = '@delref(children ~)'})
Node.ATTR('removeChildByName', {RET = '@delref(children ~)'})
Node.ATTR('removeAllChildren', {RET = '@delref(children *)'})
Node.ATTR('removeAllChildrenWithCleanup', {RET = '@delref(children *)'})
Node.ATTR('getGLProgram', {RET = '@addref(glProgram ^)'})
Node.ATTR('setGLProgram', {ARG1 = '@addref(glProgram ^)'})
Node.ATTR('getGLProgramState', {RET = '@addref(glProgramState ^)'})
Node.ATTR('setGLProgramState', {ARG1 = '@addref(glProgramState ^)'})
Node.ATTR('getEventDispatcher', {RET = '@addref(eventDispatcher ^)'})
Node.ATTR('setEventDispatcher', {ARG1 = '@addref(eventDispatcher ^)'})
Node.ATTR('getActionManager', {RET = '@addref(actionManager ^)'})
Node.ATTR('setActionManager', {ARG1 = '@addref(actionManager ^)'})
Node.ATTR('runAction', {RET = '@delref(actions ~)', ARG1 = '@addref(actions |)'})
Node.ATTR('stopAllActions', {RET = '@delref(actions ~)'})
Node.ATTR('stopAction', {RET = '@delref(actions ~)'})
Node.ATTR('stopActionByTag', {RET = '@delref(actions ~)'})
Node.ATTR('stopAllActionsByTag', {RET = '@delref(actions ~)'})
Node.ATTR('stopActionsByFlags', {RET = '@delref(actions ~)'})
Node.ATTR('getActionByTag', {RET = '@addref(actions |)'})
Node.ATTR('setScheduler', {ARG1 = '@addref(scheduler ^)'})
Node.ATTR('getScheduler', {RET = '@addref(scheduler ^)'})
Node.ATTR('convertToNodeSpace', {ARG1 = '@pack'})
Node.ATTR('convertToWorldSpace', {ARG1 = '@pack'})
Node.ATTR('convertToNodeSpaceAR', {ARG1 = '@pack'})
Node.ATTR('convertToWorldSpaceAR', {ARG1 = '@pack'})
Node.ATTR('getComponent', {RET = '@addref(components |)'})
Node.ATTR('addComponent', {ARG1 = '@addref(components |)'})
Node.ATTR('removeComponent', {RET = '@delref(components ~)'})
Node.ATTR('removeAllComponents', {RET = '@delref(components *)'})
Node.ATTR('setPhysicsBody', {ARG1 = '@addref(physicsBody ^)'})
Node.ATTR('getPhysicsBody', {RET = '@addref(physicsBody ^)'})
Node.CHUNK = [[
static cocos2d::Node *_find_ancestor(cocos2d::Node *node1, cocos2d::Node *node2)
{
    for (auto *p1 = node1; p1 != nullptr; p1 = p1->getParent()) {
        for (auto *p2 = node2; p2 != nullptr; p2 = p2->getParent()) {
            if (p1 == p2) {
                return p1;
            }
        }
    }
    return NULL;
}]]
Node.FUNC('getBounds', [[
{
    auto self = olua_checkobj<cocos2d::Node>(L, 1);
    auto target = olua_checkobj<cocos2d::Node>(L, 2);

    float left = luaL_checknumber(L, 3);
    float right = luaL_checknumber(L, 4);
    float top = luaL_checknumber(L, 5);
    float bottom = luaL_checknumber(L, 6);
    
    cocos2d::Vec3 p1(left, bottom, 0);
    cocos2d::Vec3 p2(right, top, 0);
    
    auto m = cocos2d::Mat4::IDENTITY;
    
    if (target == self->getParent()) {
        m = self->getNodeToParentTransform();
    } else if (target != self) {
        auto ancestor = _find_ancestor(target, self);
        if (!ancestor) {
            m = target->getWorldToNodeTransform() * self->getNodeToWorldTransform();
        } else if (target == ancestor) {
            m = self->getNodeToParentTransform(target);
        } else if (self == ancestor) {
            m = target->getNodeToParentTransform(self).getInversed();
        } else {
            m = target->getNodeToParentTransform(ancestor).getInversed() * self->getNodeToParentTransform(ancestor);
        }
    }
    
    m.transformPoint(&p1);
    m.transformPoint(&p2);
    
    left = MIN(p1.x, p2.x);
    right = MAX(p1.x, p2.x);
    top = MAX(p1.y, p2.y);
    bottom = MIN(p1.y, p2.y);
    
    lua_pushnumber(L, left);
    lua_pushnumber(L, right);
    lua_pushnumber(L, top);
    lua_pushnumber(L, bottom);
    
    return 4;
}
]])
Node.PROP('x', 'float getPositionX()', 'void setPositionX(float x)')
Node.PROP('y', 'float getPositionY()', 'void setPositionY(float y)')
Node.PROP('z', 'float getPositionZ()', 'void setPositionZ(float z)')
Node.PROP('anchorX', [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getAnchorPoint().x);
    return 1;
}
]], [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Vec2 anchor = self->getAnchorPoint();
    anchor.x = olua_checknumber(L, 2);
    self->setAnchorPoint(anchor);
    return 0;
}]])
Node.PROP('anchorY', [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getAnchorPoint().y);
    return 1;
}
]], [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Vec2 anchor = self->getAnchorPoint();
    anchor.y = olua_checknumber(L, 2);
    self->setAnchorPoint(anchor);
    return 0;
}]])
Node.PROP('width', [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getContentSize().width);
    return 1;
}
]], [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Size size = self->getContentSize();
    size.width = olua_checknumber(L, 2);
    self->setContentSize(size);
    return 0;
}]])
Node.PROP('height', [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getContentSize().height);
    return 1;
}
]], [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Size size = self->getContentSize();
    size.height = olua_checknumber(L, 2);
    self->setContentSize(size);
    return 0;
}]])
Node.PROP('alpha', [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getOpacity() / 255.0f);
    return 1;
}
]], [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    self->setOpacity(olua_checknumber(L, 2) * 255.0f);
    return 0;
}]])
Node.CALLBACK {
    FUNCS = {'void scheduleOnce(const std::function<void(float)>& callback, float delay, const std::string &key)'},
    TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_SCOPE = 'once',
}
Node.CALLBACK {
    FUNCS = {
        'void schedule(const std::function<void(float)>& callback, const std::string &key)',
        'void schedule(const std::function<void(float)>& callback, float interval, const std::string &key)',
        'void schedule(const std::function<void(float)>& callback, float interval, unsigned int repeat, float delay, const std::string &key)',
    },
    TAG_MAKER = "makeScheduleCallbackTag(#-1)",
    TAG_MODE = 'OLUA_TAG_REPLACE',
}
Node.CALLBACK {
    FUNCS = {'void unschedule(const std::string &key)'},
    TAG_MAKER = "makeScheduleCallbackTag(#1)",
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
}
Node.CALLBACK {
    FUNCS = {'void unscheduleAllCallbacks()'},
    TAG_MAKER = 'makeScheduleCallbackTag("")',
    TAG_MODE = "OLUA_TAG_SUBSTARTWITH",
}
Node.CALLBACK {NAME = 'setOnEnterCallback', NULLABLE = true}
Node.CALLBACK {NAME = 'getOnEnterCallback', NULLABLE = true}
Node.CALLBACK {NAME = 'setOnExitCallback', NULLABLE = true}
Node.CALLBACK {NAME = 'getOnExitCallback', NULLABLE = true}
Node.CALLBACK {NAME = 'setOnEnterTransitionDidFinishCallback', NULLABLE = true}
Node.CALLBACK {NAME = 'getOnEnterTransitionDidFinishCallback', NULLABLE = true}
Node.CALLBACK {NAME = 'setOnExitTransitionDidStartCallback', NULLABLE = true}
Node.CALLBACK {NAME = 'getOnExitTransitionDidStartCallback', NULLABLE = true}
Node.INJECT({'removeFromParent', 'removeFromParentAndCleanup'}, {
    BEFORE = [[
        if (!self->getParent()) {
            return 0;
        }
        olua_push_cppobj<cocos2d::Node>(L, self->getParent());
        int parent = lua_gettop(L);
    ]]
})

typeconf 'cocos2d::AtlasNode'

local ProtectedNode = typeconf 'cocos2d::ProtectedNode'
ProtectedNode.ATTR('addProtectedChild', {ARG1 = '@addref(protectedChildren |)'})
ProtectedNode.ATTR('getProtectedChildByTag', {RET = '@addref(protectedChildren |)'})
ProtectedNode.ATTR('removeProtectedChild', {ARG1 = '@delref(protectedChildren |)'})
ProtectedNode.ATTR('removeProtectedChildByTag', {RET = '@delref(protectedChildren ~)'})
ProtectedNode.ATTR('removeAllProtectedChildren', {RET= '@delref(protectedChildren *)'})
ProtectedNode.ATTR('removeAllProtectedChildrenWithCleanup', {RET = '@delref(protectedChildren *)'})

typeconf 'cocos2d::DrawNode'
typeconf 'cocos2d::TextHAlignment'
typeconf 'cocos2d::TextVAlignment'
typeconf 'cocos2d::GlyphCollection'
typeconf 'cocos2d::LabelEffect'
typeconf 'cocos2d::Label::LabelType'
typeconf 'cocos2d::Label::Overflow'
typeconf 'cocos2d::Label'
typeconf 'cocos2d::LabelAtlas'

local FontAtlas = typeconf 'cocos2d::FontAtlas'
FontAtlas.EXCLUDE 'getTextures'
FontAtlas.EXCLUDE 'prepareLetterDefinitions'

typeconf 'cocos2d::ClippingRectangleNode'

local RenderTexture = typeconf 'cocos2d::RenderTexture'
RenderTexture.CALLBACK {
    FUNCS = {
        'bool saveToFile(const std::string& filename, bool isRGBA = true, std::function<void (RenderTexture*, const std::string&)> callback = nullptr)',
        'bool saveToFile(const std::string& filename, Image::Format format, bool isRGBA = true, std::function<void (RenderTexture*, const std::string&)> callback = nullptr)',
    },
    TAG_MAKER = 'saveToFile',
    TAG_MODE = "OLUA_TAG_REPLACE",
    TAG_SCOPE = 'once',
}
RenderTexture.CALLBACK {
    FUNCS = {
        'bool saveToFileAsNonPMA(const std::string& fileName, Image::Format format, bool isRGBA, const std::function<void(RenderTexture*, const std::string&)>& callback)',
        'bool saveToFileAsNonPMA(const std::string& filename, bool isRGBA = true, const std::function<void(RenderTexture*, const std::string&)>& callback = nullptr)'
    },
    TAG_MAKER = 'saveToFile',
    TAG_MODE = "OLUA_TAG_REPLACE",
    TAG_SCOPE = 'once',
}
RenderTexture.ALIAS('begin', 'beginVisit')
RenderTexture.ALIAS('end', 'endVisit')

typeconf 'cocos2d::ProgressTimer::Type'
typeconf 'cocos2d::ProgressTimer'
typeconf 'cocos2d::AnimationFrame'
typeconf 'cocos2d::Animation'
typeconf 'cocos2d::SpriteFrame'
typeconf 'cocos2d::Sprite'

typeconf 'cocos2d::SpriteBatchNode'
typeconf 'cocos2d::SpriteFrameCache'
typeconf 'cocos2d::AnimationCache'

local Scene = typeconf 'cocos2d::Scene'
Scene.ATTR('getPhysicsWorld', {RET = '@addref(physicsWorld ^)'})
Scene.ATTR('getPhysics3DWorld', {RET = '@addref(physics3DWorld ^)'})

typeconf 'cocos2d::Layer'
typeconf 'cocos2d::LayerColor'
typeconf 'cocos2d::LayerGradient'
typeconf 'cocos2d::LayerRadialGradient'

typeconf 'cocos2d::TransitionScene::Orientation'

local function typeconfTransition(name)
    local cls = typeconf(name)
    cls.ATTR('create', {ARG2 = '@addref(autoref |)'})
    cls.ATTR('easeActionWithAction', {ARG1 = '@addref(action ^)'})
    return cls
end

local TransitionScene = typeconfTransition 'cocos2d::TransitionScene'
TransitionScene.EXCLUDE 'initWithDuration'

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

local Camera = typeconf 'cocos2d::Camera'
Camera.EXCLUDE 'isVisibleInFrustum'
Camera.EXCLUDE 'setFrameBufferObject'

typeconf 'cocos2d::CameraBackgroundBrush::BrushType'
typeconf 'cocos2d::CameraBackgroundBrush'
typeconf 'cocos2d::CameraBackgroundDepthBrush'
typeconf 'cocos2d::CameraBackgroundColorBrush'
typeconf 'cocos2d::CameraBackgroundSkyBoxBrush'

typeconf 'cocos2d::ActionCamera'
typeconf 'cocos2d::OrbitCamera'
typeconf 'cocos2d::GridBase'
typeconf 'cocos2d::Grid3D'
typeconf 'cocos2d::TiledGrid3D'
typeconf 'cocos2d::NodeGrid'
typeconf 'cocos2d::GridAction'
typeconf 'cocos2d::Grid3DAction'

local TiledGrid3DAction = typeconf 'cocos2d::TiledGrid3DAction'
TiledGrid3DAction.CHUNK = [[
NS_CC_BEGIN
TiledGrid3DAction* TiledGrid3DAction::create(float duration, const Size& gridSize)
{
    TiledGrid3DAction* ret = new TiledGrid3DAction();
    ret->autorelease();
    ret->initWithDuration(duration, gridSize);
    return ret;
}
NS_CC_END
]]

typeconf 'cocos2d::AccelDeccelAmplitude'
typeconf 'cocos2d::AccelAmplitude'
typeconf 'cocos2d::DeccelAmplitude'
typeconf 'cocos2d::StopGrid'
typeconf 'cocos2d::ReuseGrid'
typeconf 'cocos2d::Waves3D'
typeconf 'cocos2d::FlipX3D'
typeconf 'cocos2d::FlipY3D'
typeconf 'cocos2d::Lens3D'
typeconf 'cocos2d::Ripple3D'
typeconf 'cocos2d::Shaky3D'
typeconf 'cocos2d::Liquid'
typeconf 'cocos2d::Waves'
typeconf 'cocos2d::Twirl'
typeconf 'cocos2d::PageTurn3D'
typeconf 'cocos2d::ShakyTiles3D'
typeconf 'cocos2d::ShatteredTiles3D'
typeconf 'cocos2d::ShuffleTiles'
typeconf 'cocos2d::FadeOutTRTiles'
typeconf 'cocos2d::FadeOutBLTiles'
typeconf 'cocos2d::FadeOutUpTiles'
typeconf 'cocos2d::FadeOutDownTiles'
typeconf 'cocos2d::TurnOffTiles'
typeconf 'cocos2d::WavesTiles3D'
typeconf 'cocos2d::JumpTiles3D'
typeconf 'cocos2d::SplitRows'
typeconf 'cocos2d::SplitCols'

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


return M