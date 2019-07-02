local M = typemodule 'cocos2d'
local typeconf = M.typeconf

M.PARSER = {
    PATH = {
        'cocos2d.h',
        'audio/include/AudioEngine.h',
        'audio/include/SimpleAudioEngine.h',
        'vr/CCVRGenericRenderer.h',
        'vr/CCVRGenericHeadTracker.h',
        'lua-bindings/LuaComponent.h'
    },
    ARGS = {
        '-I../../frameworks/cocos2d-x/cocos',
        '-I../../frameworks/libxgame/src',
        '-DCC_DLL=',
        '-DEXPORT_DLL=',
    },
    BUILD = 'autoconf',
}

M.NAME = "cocos2d"
M.NAMESPACES = {"cocos2d", "cocos2d::experimental", "CocosDenshion"}
M.HEADER_PATH = "frameworks/libxgame/src/lua-bindings/lua_cocos2d.h"
M.SOURCE_PATH = "frameworks/libxgame/src/lua-bindings/lua_cocos2d.cpp"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaComponent.h"
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

M.EXCLUDE_TYPE 'cocos2d::Console *'
M.EXCLUDE_TYPE 'cocos2d::Font *'
M.EXCLUDE_TYPE 'cocos2d::FontDefinition'
M.EXCLUDE_TYPE 'cocos2d::FontLetterDefinition'
M.EXCLUDE_TYPE 'cocos2d::GroupCommandManager *'
M.EXCLUDE_TYPE 'cocos2d::Mat4 *'
M.EXCLUDE_TYPE 'cocos2d::MipmapInfo *'
M.EXCLUDE_TYPE 'cocos2d::PhysicsBody *'     -- TODO
M.EXCLUDE_TYPE 'cocos2d::PhysicsWorld *'    -- TDDO
M.EXCLUDE_TYPE 'cocos2d::Physics3DWorld *'  -- TDDO
M.EXCLUDE_TYPE 'cocos2d::NavMesh *'         -- TDDO
M.EXCLUDE_TYPE 'cocos2d::PolygonInfo'
M.EXCLUDE_TYPE 'cocos2d::RenderCommand *'
M.EXCLUDE_TYPE 'cocos2d::SEL_SCHEDULE'
M.EXCLUDE_TYPE 'cocos2d::V3F_C4B_T2F_Quad *'
M.EXCLUDE_TYPE 'cocos2d::V3F_C4B_T2F_Quad'
M.EXCLUDE_TYPE 'cocos2d::Vec2 *'
M.EXCLUDE_TYPE 'cocos2d::Vec4 *'
M.EXCLUDE_TYPE 'cocos2d::Tile *'
M.EXCLUDE_TYPE 'float *'
M.EXCLUDE_TYPE 'GLfloat *'
M.EXCLUDE_TYPE 'unsigned int *'
M.EXCLUDE_TYPE 'GLint *'
M.EXCLUDE_TYPE 'int *'

M.LUACLS = [[
function (cppname)
    return string.gsub(cppname, "^cocos2d::", "cc.")
end
]]

local UserDefault = typeconf 'cocos2d::UserDefault'
UserDefault.EXCLUDE 'setDelegate'

local Ref = typeconf 'cocos2d::Ref'
Ref.EXCLUDE 'retain'
Ref.EXCLUDE 'release'
Ref.EXCLUDE 'autorelease'
Ref.EXCLUDE '_ID'
Ref.EXCLUDE '_luaID'
Ref.EXCLUDE '_scriptObject'
Ref.EXCLUDE '_rooted'
Ref.FUNC('__gc', '{\n    return xlua_ccobjgc(L);\n}')

-- TODO: var field
typeconf 'cocos2d::Acceleration'

typeconf 'cocos2d::MATRIX_STACK_TYPE'

local Director = typeconf 'cocos2d::Director'
Director.EXCLUDE 'getCocos2dThreadId'
Director.ATTR('getRunningScene', {RET = '@ref(map scenes)'})
Director.ATTR('runWithScene', {ARG1 = '@ref(map scenes)'})
Director.ATTR('pushScene', {ARG1 = '@ref(map scenes)'})
Director.ATTR('replaceScene', {RET = '@unref(cmp scenes)', ARG1 = '@ref(map scenes)'})
Director.ATTR('popScene', {RET = '@unref(cmp scenes)'})
Director.ATTR('popToRootScene', {RET = '@unref(cmp scenes)'})
Director.ATTR('popToSceneStackLevel', {RET = '@unref(cmp scenes)'})
Director.ATTR('getOpenGLView', {RET = '@ref(single openGLView)'})
Director.ATTR('setOpenGLView', {ARG1 = '@ref(single openGLView)'})
Director.ATTR('getTextureCache', {RET = '@ref(single textureCache)'})
Director.ATTR('getNotificationNode', {RET = '@ref(single notificationNode)'})
Director.ATTR('setNotificationNode', {ARG1 = '@ref(single notificationNode)'})
Director.ATTR('convertToGL', {ARG1 = '@pack'})
Director.ATTR('convertToUI', {ARG1 = '@pack'})
Director.ATTR('getEventDispatcher', {RET = '@ref(single eventDispatcher)'})
Director.ATTR('setEventDispatcher', {ARG1 = '@ref(single eventDispatcher)'})
Director.ATTR('getScheduler', {RET = '@ref(single scheduler)'})
Director.ATTR('setScheduler', {ARG1 = '@ref(single scheduler)'})
Director.ATTR('getActionManager', {RET = '@ref(single actionManager)'})
Director.ATTR('setActionManager', {ARG1 = '@ref(single actionManager)'})
Director.ATTR('getRenderer', {RET = '@ref(single renderer)'})

local Scheduler = typeconf 'cocos2d::Scheduler'
Scheduler.EXCLUDE 'scheduleScriptFunc'
Scheduler.EXCLUDE 'unscheduleScriptEntry'
Scheduler.EXCLUDE 'performFunctionInCocosThread'
Scheduler.ENUM('PRIORITY_SYSTEM', 'cocos2d::Scheduler::PRIORITY_SYSTEM')
Scheduler.ENUM('PRIORITY_NON_SYSTEM_MIN', 'cocos2d::Scheduler::PRIORITY_NON_SYSTEM_MIN')
Scheduler.CHUNK = [[
template <typename T> bool doScheduleUpdate(lua_State *L, const char *cls)
{
    if (olua_is_cppobj(L, 2, cls)) {
        cocos2d::Scheduler *self = nullptr;
        lua_Integer arg2 = 0;
        bool arg3 = false;
        
        olua_to_cppobj(L, 1, (void **)&self, "cc.Scheduler");
        olua_check_int(L, 3, &arg2);
        olua_check_bool(L, 4, &arg3);
        
        T* arg1 = nullptr;
        olua_to_cppobj(L, 2, (void **)&arg1, cls);
        self->scheduleUpdate(arg1, (int)arg2, arg3);
        
        return true;
    }
    
    return false;
}]]
Scheduler.FUNC('new', [[
{
    auto obj = new cocos2d::Scheduler();
    obj->autorelease();
    return olua_push_cppobj<cocos2d::Scheduler>(L, obj, nullptr);
}
]])
Scheduler.CALLBACK('schedule', {
    FUNCS = {
        'void schedule(const std::function<void(float)>& callback, void *target, float interval, bool paused, const std::string& key)',
        'void schedule(const std::function<void(float)>& callback, void *target, float interval, unsigned int repeat, float delay, bool paused, const std::string& key)',
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    TAG_STORE = 2, -- 2th void *target
})
Scheduler.CALLBACK('unschedule', {
    FUNCS = {'void unschedule(const std::string& key, void *target)'},
    TAG_MAKER = 'makeScheduleCallbackTag(#1)',
    TAG_STORE = 2, -- 2th void *target
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    REMOVE = true,
})
Scheduler.CALLBACK('unscheduleAllForTarget', {
    FUNCS = {'void unscheduleAllForTarget(void *target)'},
    TAG_MAKER = 'makeScheduleCallbackTag("")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
    TAG_STORE = 1, -- 1th void *target
    REMOVE = true,
})
Scheduler.CALLBACK('unscheduleAll', {
    FUNCS = {'void unscheduleAll()'},
    TAG_MAKER = 'makeScheduleCallbackTag("")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
    REMOVE = true,
})
Scheduler.FUNC('scheduleUpdate', [[
{
    lua_settop(L, 4);
    
    if (doScheduleUpdate<cocos2d::Scheduler>(L, "cc.Scheduler") ||
        doScheduleUpdate<cocos2d::ActionManager>(L, "cc.ActionManager") ||
        doScheduleUpdate<cocos2d::Node>(L, "cc.Node") ||
        doScheduleUpdate<cocos2d::Action>(L, "cc.Action") ||
        doScheduleUpdate<cocos2d::Component>(L, "cc.Component") ||
        doScheduleUpdate<cocos2d::ActionManager>(L, "cc.ActionManager")) {
        return 0;
    }
    
    luaL_error(L, "unsupport type: %s", olua_typename(L, 2));

    return 0;
}]])

--
-- event & event listener
--
local EventDispatcher = typeconf 'cocos2d::EventDispatcher'
EventDispatcher.ATTR('addEventListenerWithSceneGraphPriority', {ARG1 = '@ref(map listeners 3)'})
EventDispatcher.ATTR('addEventListenerWithFixedPriority', {ARG1 = '@ref(map listeners)'})
EventDispatcher.ATTR('removeCustomEventListeners', {RET = '@unref(cmp listeners)'})
EventDispatcher.ATTR('removeEventListener', {RET = '@unref(cmp listeners)'})
EventDispatcher.ATTR('removeEventListenersForType', {RET = '@unref(cmp listeners)'})
EventDispatcher.ATTR('removeAllEventListeners', {RET = '@unref(cmp listeners)'})
EventDispatcher.CHUNK = [[
static void doRemoveEventListenersForTarget(lua_State *L, cocos2d::Node *target, bool recursive, const char *refname)
{
    if (olua_getobj(L, target)) {
        olua_unrefall(L, -1, refname);
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
EventDispatcher.FUNC('addCustomEventListener', [[
{
    lua_settop(L, 3);

    cocos2d::EventDispatcher *self = nullptr;
    std::string eventName;
    void *callback_store_obj = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventDispatcher");
    olua_check_std_string(L, 2, &eventName);
    
    cocos2d::EventListenerCustom *listener = new cocos2d::EventListenerCustom();
    listener->autorelease();
    olua_push_cppobj<cocos2d::EventListenerCustom>(L, listener, "cc.EventListenerCustom");
    callback_store_obj = listener;
    std::string func = olua_setcallback(L, callback_store_obj, eventName.c_str(), 3, OLUA_CALLBACK_TAG_NEW);
    listener->init(eventName, [callback_store_obj, func](cocos2d::EventCustom *event) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        size_t last = olua_push_objpool(L);
        olua_enable_objpool(L);
        olua_push_cppobj<cocos2d::EventCustom>(L, event, "cc.EventCustom");
        olua_disable_objpool(L);
        olua_callback(L, callback_store_obj, func.c_str(), 1);

        //pop stack value
        olua_pop_objpool(L, last);
        
        lua_settop(L, top);
    });
    
    // EventListenerCustom* EventDispatcher::addCustomEventListener(const std::string &eventName, const std::function<void(EventCustom*)>& callback)
    //  {
    //      EventListenerCustom *listener = EventListenerCustom::create(eventName, callback);
    //      addEventListenerWithFixedPriority(listener, 1);
    //      return listener;
    //  }
    self->addEventListenerWithFixedPriority(listener, 1);
    lua_pushvalue(L, 4);

    ${INJECT_AFTER}

    return 1;
}]])
EventDispatcher.INJECT('addCustomEventListener', {
    AFTER = [[
        olua_mapref(L, 1, "listeners", -1);
    ]]
})
EventDispatcher.INJECT('removeEventListenersForTarget', {
    BEFORE = [[
        bool recursive = false;
        cocos2d::Node *node = (cocos2d::Node *)olua_checkobj(L, 2, "cc.Node");
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

local EventListenerTouchOneByOne = typeconf 'cocos2d::EventListenerTouchOneByOne'
EventListenerTouchOneByOne.VAR('onTouchBegan', 'std::function<bool(@stack Touch*, @stack Event*)> onTouchBegan = nullptr')
EventListenerTouchOneByOne.VAR('onTouchMoved', 'std::function<void(@stack Touch*, @stack Event*)> onTouchMoved = nullptr')
EventListenerTouchOneByOne.VAR('onTouchEnded', 'std::function<void(@stack Touch*, @stack Event*)> onTouchEnded = nullptr')
EventListenerTouchOneByOne.VAR('onTouchCancelled', 'std::function<void(@stack Touch*, @stack Event*)> onTouchCancelled = nullptr')

local EventListenerTouchAllAtOnce = typeconf 'cocos2d::EventListenerTouchAllAtOnce'
EventListenerTouchAllAtOnce.VAR('onTouchesBegan', 'std::function<void(@stack const std::vector<Touch*>&, @stack Event*)> onTouchesBegan = nullptr')
EventListenerTouchAllAtOnce.VAR('onTouchesMoved', 'std::function<void(@stack const std::vector<Touch*>&, @stack Event*)> onTouchesMoved = nullptr')
EventListenerTouchAllAtOnce.VAR('onTouchesEnded', 'std::function<void(@stack const std::vector<Touch*>&, @stack Event*)> onTouchesEnded = nullptr')
EventListenerTouchAllAtOnce.VAR('onTouchesCancelled', 'std::function<void(@stack const std::vector<Touch*>&, @stack Event*)> onTouchesCancelled = nullptr')

local EventListenerCustom = typeconf 'cocos2d::EventListenerCustom'
EventListenerCustom.CALLBACK('create', {
    FUNCS = {'static EventListenerCustom* create(const std::string& eventName, const std::function<void(@stack EventCustom*)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("listener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_NEW',
    INIT_FUNC = 'init',
})

local EventListenerKeyboard = typeconf 'cocos2d::EventListenerKeyboard'
EventListenerKeyboard.VAR('onKeyPressed', 'std::function<void(EventKeyboard::KeyCode, @stack Event*)> onKeyPressed = nullptr')
EventListenerKeyboard.VAR('onKeyReleased', 'std::function<void(EventKeyboard::KeyCode, @stack Event*)> onKeyReleased = nullptr')

local EventListenerAcceleration = typeconf 'cocos2d::EventListenerAcceleration'
EventListenerAcceleration.CALLBACK('create', {
    FUNCS = {'static EventListenerAcceleration* create(const std::function<void(@stack Acceleration*, @stack Event*)>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("listener")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_NEW',
    INIT_FUNC = 'init',
})

local EventListenerFocus = typeconf 'cocos2d::EventListenerFocus'
EventListenerFocus.VAR('onFocusChanged', 'std::function<void(ui::Widget*, ui::Widget*)> onFocusChanged = nullptr')

local EventListenerMouse = typeconf 'cocos2d::EventListenerMouse'
EventListenerMouse.VAR('onMouseDown', 'std::function<void(@stack EventMouse* event)> onMouseDown = nullptr')
EventListenerMouse.VAR('onMouseUp', 'std::function<void(@stack EventMouse* event)> onMouseUp = nullptr')
EventListenerMouse.VAR('onMouseMove', 'std::function<void(@stack EventMouse* event)> onMouseMove = nullptr')
EventListenerMouse.VAR('onMouseScroll', 'std::function<void(@stack EventMouse* event)> onMouseScroll = nullptr')

typeconf 'cocos2d::Event::Type'
typeconf 'cocos2d::Event'

local EventCustom = typeconf 'cocos2d::EventCustom'
EventCustom.FUNC('new', [[
{
    lua_settop(L, 1);
    const char *event = olua_checkstring(L, 1);
    auto obj = new cocos2d::EventCustom(event);
    obj->autorelease();
    return olua_push_cppobj<cocos2d::EventCustom>(L, obj, nullptr);
}]])

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

local Touch = typeconf 'cocos2d::Touch'
Touch.FUNC('new', [[
{
    auto obj = new cocos2d::Touch();
    obj->autorelease();
    return olua_push_cppobj<cocos2d::Touch>(L, obj, nullptr);
}]])

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
        void *callback_store_obj = (void *)olua_getstoreobj(L, "cc.AudioEngine");
        for (auto id : ids) {
            std::string tag = makeAudioEngineFinishCallbackTag((lua_Integer)id);
            olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_CALLBACK_TAG_ENDWITH);
        }
    ]]
})
AudioEngine.CALLBACK('stop', {
    FUNCS = {'static void stop(int audioID)'},
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
    TAG_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
    REMOVE = true,
})
AudioEngine.CALLBACK('stopAll', {
    FUNCS = {'static void stopAll()'},
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
    TAG_MODE = "OLUA_CALLBACK_TAG_WILDCARD",
    REMOVE = true,
})
AudioEngine.CALLBACK('uncacheAll', {
    FUNCS = {'static void uncacheAll()'},
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
    TAG_MODE = "OLUA_CALLBACK_TAG_WILDCARD",
    REMOVE = true,
})
AudioEngine.CALLBACK('setFinishCallback', {
    FUNCS = {'static void setFinishCallback(int audioID, @nullable const std::function<void(int,const std::string&)>& callback)'},
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
    TAG_MODE = "OLUA_CALLBACK_TAG_REPLACE",
    CALLONCE = true,
})
AudioEngine.CALLBACK('preload', {
    FUNCS = {
        'static void preload(const std::string& filePath)',
        'static void preload(const std::string& filePath, std::function<void(bool isSuccess)> callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("preload")',
    TAG_MODE = "OLUA_CALLBACK_TAG_REPLACE",
    CALLONCE = true,
})

typeconf 'CocosDenshion::SimpleAudioEngine'

typeconf 'cocos2d::ApplicationProtocol::Platform'
typeconf 'cocos2d::LanguageType'
typeconf 'cocos2d::ApplicationProtocol'

local Application = typeconf 'cocos2d::Application'
Application.EXCLUDE 'setStartupScriptFilename'

local Device = typeconf 'cocos2d::Device'
Device.EXCLUDE 'getTextureDataForText'

local FileUtils = typeconf 'cocos2d::FileUtils'
FileUtils.EXCLUDE 'getContents'
FileUtils.EXCLUDE_PATTERN = function (fn, decl)
    return string.find(decl, 'std::function')
end
FileUtils.FUNC('getFileDataFromZip', [[
{
    lua_settop(L, 3);
    ssize_t size;
    cocos2d::FileUtils *self = (cocos2d::FileUtils *)olua_toobj(L, 1, "cc.FileUtils");
    std::string filePath = olua_checkstring(L, 2);
    std::string filename = olua_checkstring(L, 3);
    const unsigned char * data= self->getFileDataFromZip(filePath, filename, &size);
    if (data) {
        lua_pushlstring(L, (const char *)data, (size_t)size);
        lua_pushinteger(L, (lua_Integer)size);
        free((void *)data);
        return 2;
    } else {
        lua_pushnil(L);
    }
    return 1;
}]])
FileUtils.FUNC('listFilesRecursively', [[
{
    lua_settop(L, 2);
    cocos2d::FileUtils *self = (cocos2d::FileUtils *)olua_toobj(L, 1, "cc.FileUtils");
    std::vector<std::string> files;
    std::string dirPath = olua_checkstring(L, 2);
    self->listFilesRecursively(dirPath, &files);
    lua_createtable(L, (int)files.size(), 0);
    int num_eles = 1;
    for (const auto &it : files) {
        olua_push_std_string(L, it);
        lua_rawseti(L, -2, num_eles++);
    }
    return 1;
}]])
FileUtils.FUNC('getFullPathCache', [[
{
    lua_settop(L, 1);
    cocos2d::FileUtils *self = (cocos2d::FileUtils *)olua_toobj(L, 1, "cc.FileUtils");
    const std::unordered_map<std::string, std::string> paths  = self->getFullPathCache();
    lua_createtable(L, 0, 4);
    for (const auto &it : paths) {
        olua_push_std_string(L, it.first);
        olua_push_std_string(L, it.second);
        lua_rawset(L, -3);
    }
    return 1;
}]])

typeconf 'ResolutionPolicy'

local GLView = typeconf 'cocos2d::GLView'
GLView.EXCLUDE 'handleTouchesBegin'
GLView.EXCLUDE 'handleTouchesMove'
GLView.EXCLUDE 'handleTouchesEnd'
GLView.EXCLUDE 'handleTouchesCancel'
GLView.EXCLUDE 'getNSGLContext'
GLView.EXCLUDE 'getCocoaWindow'
GLView.ATTR('setVR', {ARG1 = '@ref(single vr)'})
GLView.ATTR('getVR', {RET = '@ref(single vr)'})

local GLViewImpl = typeconf 'cocos2d::GLViewImpl'
GLViewImpl.EXCLUDE 'create'
GLViewImpl.EXCLUDE 'createWithRect'
GLViewImpl.EXCLUDE 'createWithFullScreen'

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
    lua_settop(L, 0);
    lua_pushboolean(L, cocos2d::LuaImage::getPNGPremultipliedAlphaEnabled());
    return 1;
}]])

typeconf 'cocos2d::Renderer'

local GLProgram = typeconf 'cocos2d::GLProgram'
GLProgram.EXCLUDE 'getUniformFlags'

typeconf 'cocos2d::GLProgramCache'

local GLProgramState = typeconf 'cocos2d::GLProgramState'
GLProgramState.EXCLUDE 'setVertexAttribCallback'
GLProgramState.EXCLUDE 'setUniformCallback'
GLProgramState.ATTR('setGLProgram', {ARG1 = '@ref(single glProgram)'})
GLProgramState.ATTR('getGLProgram', {RET = '@ref(single glProgram)'})
GLProgramState.ATTR('setNodeBinding', {ARG1 = '@ref(single nodeBinding)'})
GLProgramState.ATTR('getNodeBinding', {RET = '@ref(single nodeBinding)'})

local TextureCache = typeconf 'cocos2d::TextureCache'
TextureCache.CHUNK = [[
static const std::string makeTextureCacheCallbackTag(const std::string &key)
{
    return "addImageAsync." + key;
}]]
TextureCache.CALLBACK('addImageAsync', {
    FUNCS = {
        'void addImageAsync(const std::string &filepath, const std::function<void(Texture2D*)>& callback)',
        'void addImageAsync(const std::string &path, const std::function<void(Texture2D*)>& callback, const std::string& callbackKey)',
    },
    TAG_MAKER = {'makeTextureCacheCallbackTag(#1)', 'makeTextureCacheCallbackTag(#-1)'},
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = true,
})
TextureCache.CALLBACK('unbindImageAsync', {
    FUNCS = {'void unbindImageAsync(const std::string &filename)'},
    TAG_MAKER = 'makeTextureCacheCallbackTag(#1)',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    REMOVE = true,
})
TextureCache.CALLBACK('unbindAllImageAsync', {
    FUNCS = {'void unbindAllImageAsync()'},
    TAG_MAKER = 'makeTextureCacheCallbackTag()',
    TAG_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
    REMOVE = true,
})

typeconf 'cocos2d::Texture2D::PixelFormat'
local Texture2D = typeconf 'cocos2d::Texture2D'
Texture2D.EXCLUDE 'getPixelFormatInfoMap'

typeconf 'cocos2d::TextureAtlas'
typeconf 'cocos2d::VRIHeadTracker'
typeconf 'cocos2d::VRIRenderer'
typeconf 'cocos2d::VRGenericRenderer'
typeconf 'cocos2d::VRGenericHeadTracker'
typeconf 'cocos2d::ActionManager'

-- actions
local Action = typeconf 'cocos2d::Action'
Action.EXCLUDE 'calculateAngles'
Action.EXCLUDE 'createWithVariableList'
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
Speed.ATTR('create', {ARG1 = '@ref(single innerAction)'})
Speed.ATTR('setInnerAction', {ARG1 = '@ref(single innerAction)'})
Speed.ATTR('getInnerAction', {RET = '@ref(single innerAction)'})

typeconf 'cocos2d::Follow'

local tweenfunc = typeconf 'cocos2d::tweenfunc'
tweenfunc.REG_LUATYPE = false
tweenfunc.TRIM = function (fn, decl)
    return string.gsub(decl, 'CC_DLL *', '')
end

typeconf 'cocos2d::ActionInterval'

local Sequence = typeconf 'cocos2d::Sequence'
Sequence.ATTR('createWithTwoActions', {ARG1 = '@ref(map autoref)', ARG2 = '@ref(map autoref)'})
Sequence.FUNC('create', [[
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    auto ret = new cocos2d::Sequence();
    ret->autorelease();
    olua_push_cppobj<cocos2d::Sequence>(L, ret, nullptr);

    for (int i = 1; i <= n; i++) {
        cocos2d::FiniteTimeAction *obj;
        olua_check_cppobj(L, i, (void **)&obj, "cc.FiniteTimeAction");
        actions.pushBack(obj);
        olua_mapref(L, -1, ".autoref", i);
    }

    ret->init(actions);
    
    return 1;
}]])

local Repeat = typeconf 'cocos2d::Repeat'
Repeat.ATTR('create', {ARG1 = '@ref(single innerAction)'})
Repeat.ATTR('setInnerAction', {ARG1 = '@ref(single innerAction)'})
Repeat.ATTR('getInnerAction', {RET = '@ref(single innerAction)'})

local RepeatForever = typeconf 'cocos2d::RepeatForever'
RepeatForever.ATTR('create', {ARG1 = '@ref(single innerAction)'})
RepeatForever.ATTR('setInnerAction', {ARG1 = '@ref(single innerAction)'})
RepeatForever.ATTR('getInnerAction', {RET = '@ref(single innerAction)'})

local Spawn = typeconf 'cocos2d::Spawn'
Spawn.ATTR('createWithTwoActions', {ARG1 = '@ref(map autoref)', ARG2 = '@ref(map autoref)'})
Spawn.FUNC('create', [[
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    auto ret = new cocos2d::Spawn();
    ret->autorelease();
    olua_push_cppobj<cocos2d::Spawn>(L, ret, nullptr);

    for (int i = 1; i <= n; i++) {
        cocos2d::FiniteTimeAction *obj;
        olua_check_cppobj(L, i, (void **)&obj, "cc.FiniteTimeAction");
        actions.pushBack(obj);
        olua_mapref(L, -1, ".autoref", i);
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
ReverseTime.ATTR('create', {ARG1 = '@ref(map autoref)'})

typeconf 'cocos2d::Animate'
typeconf 'cocos2d::TargetedAction'

local ActionFloat = typeconf 'cocos2d::ActionFloat'
ActionFloat.CALLBACK('create', {
    FUNCS = {'static ActionFloat* create(float duration, float from, float to, std::function<void(float value)> callback)'}, 
    TAG_MAKER = 'olua_makecallbacktag("ActionFloat")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_NEW',
    INIT_FUNC = 'initWithDuration'
})

typeconf 'cocos2d::ActionCamera'
typeconf 'cocos2d::OrbitCamera'

local ActionEase = typeconf 'cocos2d::ActionEase'
ActionEase.ATTR('getInnerAction', {RET = '@ref(single innerAction)'})

local function typeconfEase(name)
    local cls = typeconf(name)
    cls.ATTR('create', {ARG1 = '@ref(single innerAction)'})
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
CallFunc.CALLBACK('create', {
    FUNCS = {'static CallFunc * create(const std::function<void()>& func)'},
    TAG_MAKER = 'olua_makecallbacktag("CallFunc")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_NEW',
    INIT_FUNC = 'initWithFunction'
})

local Component = typeconf 'cocos2d::Component'
Component.ATTR('getOwner', {RET = '@ref(single owner)'})
Component.ATTR('setOwner', {ARG1 = '@ref(single owner)'})

local LuaComponent = typeconf 'cocos2d::LuaComponent'
LuaComponent.VAR('onUpdateCallback', '@nullable std::function<void(float)> onUpdateCallback')
LuaComponent.VAR('onEnterCallback', '@nullable std::function<void()> onEnterCallback')
LuaComponent.VAR('onExitCallback', '@nullable std::function<void()> onExitCallback')
LuaComponent.VAR('onAddCallback', '@nullable std::function<void()> onAddCallback')
LuaComponent.VAR('onRemoveCallback', '@nullable std::function<void()> onRemoveCallback')

-- node
local Node = typeconf 'cocos2d::Node'
Node.EXCLUDE 'enumerateChildren'
Node.EXCLUDE 'scheduleUpdateWithPriorityLua'
Node.EXCLUDE '_setLocalZOrder'
Node.ATTR('addChild', {ARG1 = '@ref(map children)'})
Node.ATTR('getChildByTag', {RET = '@ref(map children)'})
Node.ATTR('getChildByName', {RET = '@ref(map children)'})
Node.ATTR('getChildren', {RET = '@ref(map children)'})
Node.ATTR('removeFromParent', {RET = '@unref(map children parent)'})
Node.ATTR('removeFromParentAndCleanup', {RET = '@unref(map children parent)'})
Node.ATTR('removeChild', {ARG1 = '@unref(map children)'})
Node.ATTR('removeChildByTag', {RET = '@unref(cmp children)'})
Node.ATTR('removeChildByName', {RET = '@unref(cmp children)'})
Node.ATTR('removeAllChildren', {RET = '@unref(all children)'})
Node.ATTR('removeAllChildrenWithCleanup', {RET = '@unref(all children)'})
Node.ATTR('getGLProgram', {RET = '@ref(single glProgram)'})
Node.ATTR('setGLProgram', {ARG1 = '@ref(single glProgram)'})
Node.ATTR('getGLProgramState', {RET = '@ref(single glProgramState)'})
Node.ATTR('setGLProgramState', {ARG1 = '@ref(single glProgramState)'})
Node.ATTR('getEventDispatcher', {RET = '@ref(single eventDispatcher)'})
Node.ATTR('setEventDispatcher', {ARG1 = '@ref(single eventDispatcher)'})
Node.ATTR('getActionManager', {RET = '@ref(single actionManager)'})
Node.ATTR('setActionManager', {ARG1 = '@ref(single actionManager)'})
Node.ATTR('runAction', {RET = '@unref(cmp actions)', ARG1 = '@ref(map actions)'})
Node.ATTR('stopAllActions', {RET = '@unref(cmp actions)'})
Node.ATTR('stopAction', {RET = '@unref(cmp actions)'})
Node.ATTR('stopActionByTag', {RET = '@unref(cmp actions)'})
Node.ATTR('stopAllActionsByTag', {RET = '@unref(cmp actions)'})
Node.ATTR('stopActionsByFlags', {RET = '@unref(cmp actions)'})
Node.ATTR('getActionByTag', {RET = '@ref(map actions)'})
Node.ATTR('setScheduler', {ARG1 = '@ref(single scheduler)'})
Node.ATTR('getScheduler', {RET = '@ref(single scheduler)'})
Node.ATTR('convertToNodeSpace', {ARG1 = '@pack'})
Node.ATTR('convertToWorldSpace', {ARG1 = '@pack'})
Node.ATTR('convertToNodeSpaceAR', {ARG1 = '@pack'})
Node.ATTR('convertToWorldSpaceAR', {ARG1 = '@pack'})
Node.ATTR('getComponent', {RET = '@ref(map components)'})
Node.ATTR('addComponent', {ARG1 = '@ref(map components)'})
Node.ATTR('removeComponent', {RET = '@unref(cmp components)'})
Node.ATTR('removeAllComponents', {RET = '@unref(all components)'})
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
    lua_settop(L, 1);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    lua_pushnumber(L, self->getAnchorPoint().x);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Vec2 anchor = self->getAnchorPoint();
    anchor.x = olua_checknumber(L, 2);
    self->setAnchorPoint(anchor);
    return 0;
}]])
Node.PROP('anchorY', [[
{
    lua_settop(L, 1);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    lua_pushnumber(L, self->getAnchorPoint().y);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Vec2 anchor = self->getAnchorPoint();
    anchor.y = olua_checknumber(L, 2);
    self->setAnchorPoint(anchor);
    return 0;
}]])
Node.PROP('width', [[
{
    lua_settop(L, 1);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    lua_pushnumber(L, self->getContentSize().width);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Size size = self->getContentSize();
    size.width = olua_checknumber(L, 2);
    self->setContentSize(size);
    return 0;
}]])
Node.PROP('height', [[
{
    lua_settop(L, 1);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    lua_pushnumber(L, self->getContentSize().height);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Size size = self->getContentSize();
    size.height = olua_checknumber(L, 2);
    self->setContentSize(size);
    return 0;
}]])
Node.PROP('alpha', [[
{
    lua_settop(L, 1);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    lua_pushnumber(L, self->getOpacity() / 255.0f);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    self->setOpacity(olua_checknumber(L, 2) * 255.0f);
    return 0;
}]])
Node.CALLBACK('setOnEnterCallback', {
    FUNCS = {'void setOnEnterCallback(@nullable const std::function<void()>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("onEnterCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
Node.CALLBACK('getOnEnterCallback', {
    FUNCS = {'const std::function<void()>& getOnEnterCallback()'},
    TAG_MAKER = 'olua_makecallbacktag("onEnterCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
})
Node.CALLBACK('setOnExitCallback', {
    FUNCS = {'void setOnExitCallback(@nullable const std::function<void()>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("onExitCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
Node.CALLBACK('getOnExitCallback', {
    FUNCS = {'const std::function<void()>& getOnExitCallback()'},
    TAG_MAKER = 'olua_makecallbacktag("onExitCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
})
Node.CALLBACK('setOnEnterTransitionDidFinishCallback', {
    FUNCS = {'void setOnEnterTransitionDidFinishCallback(@nullable const std::function<void()>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("onEnterTransitionDidFinishCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
Node.CALLBACK('getOnEnterTransitionDidFinishCallback', {
    FUNCS = {'const std::function<void()>& getOnEnterTransitionDidFinishCallback()'},
    TAG_MAKER = 'olua_makecallbacktag("onEnterTransitionDidFinishCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
})
Node.CALLBACK('setOnExitTransitionDidStartCallback', {
    FUNCS = {'void setOnExitTransitionDidStartCallback(@nullable const std::function<void()>& callback)'},
    TAG_MAKER = 'olua_makecallbacktag("onExitTransitionDidStartCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
Node.CALLBACK('getOnExitTransitionDidStartCallback', {
    FUNCS = {'const std::function<void()>& getOnExitTransitionDidStartCallback()'},
    TAG_MAKER = 'olua_makecallbacktag("onExitTransitionDidStartCallback")',
    TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
})
Node.CALLBACK('scheduleOnce', {
    FUNCS = {'void scheduleOnce(const std::function<void(float)>& callback, float delay, const std::string &key)'},
    TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
    CALLONCE = true,
})
Node.CALLBACK('schedule', {
    FUNCS = {
        'void schedule(const std::function<void(float)>& callback, const std::string &key)',
        'void schedule(const std::function<void(float)>& callback, float interval, const std::string &key)',
        'void schedule(const std::function<void(float)>& callback, float interval, unsigned int repeat, float delay, const std::string &key)',
    },
    TAG_MAKER = "makeScheduleCallbackTag(#-1)",
    TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
})
Node.CALLBACK('unschedule', {
    FUNCS = {'void unschedule(const std::string &key)'},
    TAG_MAKER = "makeScheduleCallbackTag(#1)",
    TAG_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
    REMOVE = true,
})
Node.CALLBACK('unscheduleAllCallbacks', {
    FUNCS = {'void unscheduleAllCallbacks()'},
    TAG_MAKER = "makeScheduleCallbackTag()",
    TAG_MODE = "OLUA_CALLBACK_TAG_WILDCARD",
    REMOVE = true,
})
Node.INJECT({'removeFromParent', 'removeFromParentAndCleanup'}, {
    BEFORE = [[
        if (!self->getParent()) {
            return 0;
        }
        olua_push_cppobj<cocos2d::Node>(L, self->getParent(), "cc.Node");
        int parent = lua_gettop(L);
    ]]
})

typeconf 'cocos2d::AtlasNode'

local ProtectedNode = typeconf 'cocos2d::ProtectedNode'
ProtectedNode.ATTR('addProtectedChild', {ARG1 = '@ref(map protectedChildren)'})
ProtectedNode.ATTR('getProtectedChildByTag', {RET = '@ref(map protectedChildren)'})
ProtectedNode.ATTR('removeProtectedChild', {ARG1 = '@unref(map protectedChildren)'})
ProtectedNode.ATTR('removeProtectedChildByTag', {RET = '@unref(cmp protectedChildren)'})
ProtectedNode.ATTR('removeAllProtectedChildren', {RET= '@unref(all protectedChildren)'})
ProtectedNode.ATTR('removeAllProtectedChildrenWithCleanup', {RET = '@unref(all protectedChildren)'})

local DrawNode = typeconf 'cocos2d::DrawNode'
DrawNode.TRIM = function (fn, decl)
    return string.gsub(decl, 'DEFAULT_LINE_WIDTH', '2')
end

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
RenderTexture.CALLBACK('saveToFile', {
    FUNCS = {
        'bool saveToFile(const std::string& filename, bool isRGBA = true, std::function<void (RenderTexture*, const std::string&)> callback = nullptr)',
        'bool saveToFile(const std::string& filename, Image::Format format, bool isRGBA = true, std::function<void (RenderTexture*, const std::string&)> callback = nullptr)',
    },
    TAG_MAKER = 'olua_makecallbacktag("saveToFile")',
    TAG_MODE = "OLUA_CALLBACK_TAG_REPLACE",
    CALLONCE = true,
})

typeconf 'cocos2d::ProgressTimer::Type'
typeconf 'cocos2d::ProgressTimer'
typeconf 'cocos2d::AnimationFrame'
typeconf 'cocos2d::Animation'
typeconf 'cocos2d::SpriteFrame'
typeconf 'cocos2d::Sprite'

local SpriteBatchNode = typeconf 'cocos2d::SpriteBatchNode'
SpriteBatchNode.TRIM = function (fn, decl)
    return string.gsub(decl, 'DEFAULT_CAPACITY', '29')
end

typeconf 'cocos2d::SpriteFrameCache'
typeconf 'cocos2d::AnimationCache'

typeconf 'cocos2d::Scene'
typeconf 'cocos2d::Layer'
typeconf 'cocos2d::LayerColor'
typeconf 'cocos2d::LayerGradient'
typeconf 'cocos2d::LayerRadialGradient'

typeconf 'cocos2d::TransitionScene::Orientation'

local function typeconfTransition(name)
    local cls = typeconf(name)
    cls.ATTR('create', {ARG2 = '@ref(map autoref)'})
    cls.ATTR('easeActionWithAction', {ARG1 = '@ref(single action)'})
    cls.TRIM = function (fn, decl)
        return string.gsub(decl, 'Orientation ', 'TransitionScene::Orientation ')
    end
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
typeconf 'cocos2d::ActionCamera'
typeconf 'cocos2d::OrbitCamera'
typeconf 'cocos2d::GridBase'
typeconf 'cocos2d::Grid3D'
typeconf 'cocos2d::TiledGrid3D'
typeconf 'cocos2d::Grabber'
typeconf 'cocos2d::NodeGrid'
typeconf 'cocos2d::GridAction'
typeconf 'cocos2d::Grid3DAction'
typeconf 'cocos2d::TiledGrid3DAction'
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

return M