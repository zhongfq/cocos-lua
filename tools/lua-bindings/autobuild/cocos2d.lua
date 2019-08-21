-- AUTO BUILD, DON'T MODIFY!

require "autobuild.cocos2d-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

olua.nowarning(typeconv, typecls, cls)

M.NAME = "cocos2d"
M.HEADER_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_cocos2d.h"
M.SOURCE_PATH = "../../frameworks/libxgame/src/lua-bindings/lua_cocos2d.cpp"
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

M.CLASSES = {}

cls = typecls 'cocos2d::UserDefault'
cls.funcs [[
    bool getBoolForKey(const char* key)
    bool getBoolForKey(const char* key, bool defaultValue)
    int getIntegerForKey(const char* key)
    int getIntegerForKey(const char* key, int defaultValue)
    float getFloatForKey(const char* key)
    float getFloatForKey(const char* key, float defaultValue)
    double getDoubleForKey(const char* key)
    double getDoubleForKey(const char* key, double defaultValue)
    std::string getStringForKey(const char* key)
    std::string getStringForKey(const char* key, const std::string & defaultValue)
    Data getDataForKey(const char* key)
    Data getDataForKey(const char* key, const Data& defaultValue)
    void setBoolForKey(const char* key, bool value)
    void setIntegerForKey(const char* key, int value)
    void setFloatForKey(const char* key, float value)
    void setDoubleForKey(const char* key, double value)
    void setStringForKey(const char* key, const std::string & value)
    void setDataForKey(const char* key, const Data& value)
    void flush()
    void deleteValueForKey(const char* key)
    static UserDefault* getInstance()
    static void destroyInstance()
    static const std::string& getXMLFilePath()
    static bool isXMLFileExist()
]]
cls.props [[
    instance
    xmlFilePath
    xmlFileExist
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Ref'
cls.funcs [[
    unsigned int getReferenceCount()
]]
cls.func('__gc', [[{
    return xlua_ccobjgc(L);
}]])
cls.props [[
    referenceCount
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Acceleration'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
]]
cls.var('x', [[double x]])
cls.var('y', [[double y]])
cls.var('z', [[double z]])
cls.var('timestamp', [[double timestamp]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MATRIX_STACK_TYPE'
cls.enums [[
    MATRIX_STACK_MODELVIEW
    MATRIX_STACK_PROJECTION
    MATRIX_STACK_TEXTURE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Director::Projection'
cls.enums [[
    _2D
    _3D
    CUSTOM
    DEFAULT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Director'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static Director* getInstance()
    bool init()
    @ref(map scenes) Scene* getRunningScene()
    float getAnimationInterval()
    void setAnimationInterval(float interval)
    bool isDisplayStats()
    void setDisplayStats(bool displayStats)
    float getSecondsPerFrame()
    @ref(single openGLView) GLView* getOpenGLView()
    void setOpenGLView(@ref(single openGLView) GLView *openGLView)
    @ref(single textureCache) TextureCache* getTextureCache()
    bool isNextDeltaTimeZero()
    void setNextDeltaTimeZero(bool nextDeltaTimeZero)
    bool isPaused()
    unsigned int getTotalFrames()
    Projection getProjection()
    void setProjection(Projection projection)
    void setViewport()
    bool isSendCleanupToScene()
    @ref(single notificationNode) Node* getNotificationNode()
    void setNotificationNode(@ref(single notificationNode) Node *node)
    const Size& getWinSize()
    Size getWinSizeInPixels()
    Size getVisibleSize()
    Vec2 getVisibleOrigin()
    Rect getSafeAreaRect()
    Vec2 convertToGL(@pack const Vec2& point)
    Vec2 convertToUI(@pack const Vec2& point)
    float getZEye()
    void runWithScene(@ref(map scenes) Scene *scene)
    void pushScene(@ref(map scenes) Scene *scene)
    @unref(cmp scenes) void popScene()
    @unref(cmp scenes) void popToRootScene()
    @unref(cmp scenes) void popToSceneStackLevel(int level)
    @unref(cmp scenes) void replaceScene(@ref(map scenes) Scene *scene)
    void end()
    void pause()
    void resume()
    void restart()
    void stopAnimation()
    void startAnimation()
    void drawScene()
    void purgeCachedData()
    void setDefaultValues()
    void setGLDefaultValues()
    void setAlphaBlending(bool on)
    void setClearColor(const Color4F& clearColor)
    const Color4F& getClearColor()
    void setDepthTest(bool on)
    void mainLoop()
    void mainLoop(float dt)
    void setContentScaleFactor(float scaleFactor)
    float getContentScaleFactor()
    @ref(single scheduler) Scheduler* getScheduler()
    void setScheduler(@ref(single scheduler) Scheduler* scheduler)
    @ref(single actionManager) ActionManager* getActionManager()
    void setActionManager(@ref(single actionManager) ActionManager* actionManager)
    @ref(single eventDispatcher) EventDispatcher* getEventDispatcher()
    void setEventDispatcher(@ref(single eventDispatcher) EventDispatcher* dispatcher)
    @ref(single renderer) Renderer* getRenderer()
    float getDeltaTime()
    float getFrameRate()
    void pushMatrix(MATRIX_STACK_TYPE type)
    void pushProjectionMatrix(size_t index)
    void popMatrix(MATRIX_STACK_TYPE type)
    void popProjectionMatrix(size_t index)
    void loadIdentityMatrix(MATRIX_STACK_TYPE type)
    void loadProjectionIdentityMatrix(size_t index)
    void loadMatrix(MATRIX_STACK_TYPE type, const Mat4& mat)
    void loadProjectionMatrix(const Mat4& mat, size_t index)
    void multiplyMatrix(MATRIX_STACK_TYPE type, const Mat4& mat)
    void multiplyProjectionMatrix(const Mat4& mat, size_t index)
    const Mat4& getMatrix(MATRIX_STACK_TYPE type)
    const Mat4& getProjectionMatrix(size_t index)
    void resetMatrixStack()
    void initProjectionMatrixStack(size_t stackCount)
    size_t getProjectionMatrixStackSize()
    bool isValid()
]]
cls.props [[
    instance
    runningScene
    animationInterval
    displayStats
    secondsPerFrame
    openGLView
    textureCache
    nextDeltaTimeZero
    paused
    totalFrames
    projection
    sendCleanupToScene
    notificationNode
    winSize
    winSizeInPixels
    visibleSize
    visibleOrigin
    safeAreaRect
    zEye
    clearColor
    contentScaleFactor
    scheduler
    actionManager
    eventDispatcher
    renderer
    deltaTime
    frameRate
    projectionMatrixStackSize
    valid
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Scheduler'
cls.SUPERCLS = "cocos2d::Ref"
cls.CHUNK = [[
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
cls.funcs [[
    float getTimeScale()
    void setTimeScale(float timeScale)
    void update(float dt)
    void unscheduleUpdate(void *target)
    void unscheduleAllWithMinPriority(int minPriority)
    bool isScheduled(const std::string& key, const void *target)
    void pauseTarget(void *target)
    void resumeTarget(void *target)
    bool isTargetPaused(void *target)
    std::set<void*> pauseAllTargets()
    std::set<void*> pauseAllTargetsWithMinPriority(int minPriority)
    void resumeTargets(const std::set<void*>& targetsToResume)
    void removeAllFunctionsToBePerformedInCocosThread()
]]
cls.enum('PRIORITY_SYSTEM', 'cocos2d::Scheduler::PRIORITY_SYSTEM')
cls.enum('PRIORITY_NON_SYSTEM_MIN', 'cocos2d::Scheduler::PRIORITY_NON_SYSTEM_MIN')
cls.func('new', [[{
    auto obj = new cocos2d::Scheduler();
    obj->autorelease();
    return olua_push_cppobj<cocos2d::Scheduler>(L, obj);
}
]])
cls.func('scheduleUpdate', [[{
    lua_settop(L, 4);
    
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
cls.callback {
    FUNCS =  {
        'void schedule(const std::function<void(float)>& callback, void *target, float interval, bool paused, const std::string& key)',
        'void schedule(const std::function<void(float)>& callback, void *target, float interval, unsigned int repeat, float delay, bool paused, const std::string& key)',
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = 2,
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void unschedule(const std::string& key, void *target)',
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_EQUAL',
    TAG_STORE = 2,
    CALLONCE = false,
    REMOVE = true,
}
cls.callback {
    FUNCS =  {
        'void unscheduleAllForTarget(void *target)',
    },
    TAG_MAKER = 'makeScheduleCallbackTag("")',
    TAG_MODE = 'OLUA_TAG_STARTWITH',
    TAG_STORE = 1,
    CALLONCE = false,
    REMOVE = true,
}
cls.callback {
    FUNCS =  {
        'void unscheduleAll()',
    },
    TAG_MAKER = 'makeScheduleCallbackTag("")',
    TAG_MODE = 'OLUA_TAG_STARTWITH',
    CALLONCE = false,
    REMOVE = true,
}
cls.props [[
    timeScale
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventDispatcher'
cls.SUPERCLS = "cocos2d::Ref"
cls.CHUNK = [[
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
cls.funcs [[
    void addEventListenerWithSceneGraphPriority(@ref(map listeners 3) EventListener* listener, Node* node)
    void addEventListenerWithFixedPriority(@ref(map listeners) EventListener* listener, int fixedPriority)
    @unref(cmp listeners) void removeEventListener(EventListener* listener)
    @unref(cmp listeners) void removeEventListenersForType(EventListener::Type listenerType)
    void removeEventListenersForTarget(Node* target, bool recursive = false)
    @unref(cmp listeners) void removeCustomEventListeners(const std::string& customEventName)
    @unref(cmp listeners) void removeAllEventListeners()
    void pauseEventListenersForTarget(Node* target, bool recursive = false)
    void resumeEventListenersForTarget(Node* target, bool recursive = false)
    void setPriority(EventListener* listener, int fixedPriority)
    void setEnabled(bool isEnabled)
    bool isEnabled()
    void dispatchEvent(Event* event)
    void dispatchCustomEvent(const std::string &eventName, void *optionalUserData = nullptr)
    bool hasEventListener(const EventListener::ListenerID& listenerID)
]]
cls.func('addCustomEventListener', [[{
    lua_settop(L, 3);

    void *callback_store_obj = nullptr;
    auto self = olua_checkobj<cocos2d::EventDispatcher>(L, 1);
    std::string eventName = olua_checkstring(L, 2);
    auto listener = new cocos2d::EventListenerCustom();
    listener->autorelease();
    olua_push_cppobj<cocos2d::EventListenerCustom>(L, listener);
    callback_store_obj = listener;
    std::string func = olua_setcallback(L, callback_store_obj, eventName.c_str(), 3, OLUA_TAG_NEW);
    listener->init(eventName, [callback_store_obj, func](cocos2d::EventCustom *event) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        size_t last = olua_push_objpool(L);
        olua_enable_objpool(L);
        olua_push_cppobj<cocos2d::EventCustom>(L, event);
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

    olua_mapref(L, 1, "listeners", -1);

    return 1;
}]])
cls.inject('removeEventListenersForTarget', {
    BEFORE = [[
        bool recursive = false;
        auto node = olua_checkobj<cocos2d::Node>(L, 2);
        if (lua_gettop(L) >= 3) {
            recursive = olua_toboolean(L, 3);
        }
        doRemoveEventListenersForTarget(L, node, recursive, "listeners");
    ]],
})
cls.props [[
    enabled
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListener::Type'
cls.enums [[
    UNKNOWN
    TOUCH_ONE_BY_ONE
    TOUCH_ALL_AT_ONCE
    KEYBOARD
    MOUSE
    ACCELERATION
    FOCUS
    GAME_CONTROLLER
    CUSTOM
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListener'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    bool checkAvailable()
    EventListener* clone()
    void setEnabled(bool enabled)
    bool isEnabled()
]]
cls.prop('available', 'bool checkAvailable()')
cls.props [[
    enabled
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerTouchOneByOne'
cls.SUPERCLS = "cocos2d::EventListener"
cls.funcs [[
    static EventListenerTouchOneByOne* create()
    void setSwallowTouches(bool needSwallow)
    bool isSwallowTouches()
]]
cls.var('onTouchBegan', [[std::function<bool(@local Touch*, @local Event*)> onTouchBegan = nullptr]])
cls.var('onTouchMoved', [[std::function<void(@local Touch*, @local Event*)> onTouchMoved = nullptr]])
cls.var('onTouchEnded', [[std::function<void(@local Touch*, @local Event*)> onTouchEnded = nullptr]])
cls.var('onTouchCancelled', [[std::function<void(@local Touch*, @local Event*)> onTouchCancelled = nullptr]])
cls.props [[
    swallowTouches
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerTouchAllAtOnce'
cls.SUPERCLS = "cocos2d::EventListener"
cls.funcs [[
    static EventListenerTouchAllAtOnce* create()
]]
cls.var('onTouchesBegan', [[std::function<void(@local const std::vector<Touch*>&, @local Event*)> onTouchesBegan = nullptr]])
cls.var('onTouchesMoved', [[std::function<void(@local const std::vector<Touch*>&, @local Event*)> onTouchesMoved = nullptr]])
cls.var('onTouchesEnded', [[std::function<void(@local const std::vector<Touch*>&, @local Event*)> onTouchesEnded = nullptr]])
cls.var('onTouchesCancelled', [[std::function<void(@local const std::vector<Touch*>&, @local Event*)> onTouchesCancelled = nullptr]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerCustom'
cls.SUPERCLS = "cocos2d::EventListener"
cls.funcs [[
]]
cls.callback {
    FUNCS =  {
        'static EventListenerCustom* create(const std::string& eventName, const std::function<void(@local EventCustom*)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("listener")',
    TAG_MODE = 'OLUA_TAG_NEW',
    CPPFUNC = 'init',
    NEW = [[
        auto *self = new ${DECLTYPE}();
        auto *ret = self;
        self->autorelease();
        olua_push_cppobj<${DECLTYPE}>(L, self);
    ]],
    CALLONCE = false,
    REMOVE = false,
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerKeyboard'
cls.SUPERCLS = "cocos2d::EventListener"
cls.funcs [[
    static EventListenerKeyboard* create()
]]
cls.var('onKeyPressed', [[std::function<void(EventKeyboard::KeyCode, @local Event*)> onKeyPressed = nullptr]])
cls.var('onKeyReleased', [[std::function<void(EventKeyboard::KeyCode, @local Event*)> onKeyReleased = nullptr]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerAcceleration'
cls.SUPERCLS = "cocos2d::EventListener"
cls.funcs [[
]]
cls.callback {
    FUNCS =  {
        'static EventListenerAcceleration* create(const std::function<void(@local Acceleration*, @local Event*)>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("listener")',
    TAG_MODE = 'OLUA_TAG_NEW',
    CPPFUNC = 'init',
    NEW = [[
        auto *self = new ${DECLTYPE}();
        auto *ret = self;
        self->autorelease();
        olua_push_cppobj<${DECLTYPE}>(L, self);
    ]],
    CALLONCE = false,
    REMOVE = false,
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerFocus'
cls.SUPERCLS = "cocos2d::EventListener"
cls.funcs [[
    static EventListenerFocus* create()
]]
cls.var('onFocusChanged', [[std::function<void(ui::Widget*, ui::Widget*)> onFocusChanged = nullptr]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerMouse'
cls.SUPERCLS = "cocos2d::EventListener"
cls.funcs [[
    static EventListenerMouse* create()
]]
cls.var('onMouseDown', [[std::function<void(@local EventMouse* event)> onMouseDown = nullptr]])
cls.var('onMouseUp', [[std::function<void(@local EventMouse* event)> onMouseUp = nullptr]])
cls.var('onMouseMove', [[std::function<void(@local EventMouse* event)> onMouseMove = nullptr]])
cls.var('onMouseScroll', [[std::function<void(@local EventMouse* event)> onMouseScroll = nullptr]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Event::Type'
cls.enums [[
    TOUCH
    KEYBOARD
    ACCELERATION
    MOUSE
    FOCUS
    GAME_CONTROLLER
    CUSTOM
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Event'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    Type getType()
    void stopPropagation()
    bool isStopped()
    Node* getCurrentTarget()
]]
cls.props [[
    type
    stopped
    currentTarget
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventCustom'
cls.SUPERCLS = "cocos2d::Event"
cls.funcs [[
    void setUserData(void* data)
    void* getUserData()
    const std::string& getEventName()
]]
cls.func('new', [[{
    lua_settop(L, 1);
    const char *event = olua_checkstring(L, 1);
    auto obj = new cocos2d::EventCustom(event);
    obj->autorelease();
    return olua_push_cppobj<cocos2d::EventCustom>(L, obj);
}]])
cls.props [[
    userData
    eventName
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerController'
cls.SUPERCLS = "cocos2d::EventListener"
cls.funcs [[
    static EventListenerController* create()
]]
cls.var('onConnected', [[std::function<void(@local Controller*, @local Event*)> onConnected = nullptr]])
cls.var('onDisconnected', [[std::function<void(@local Controller*, @local Event*)> onDisconnected = nullptr]])
cls.var('onKeyDown', [[std::function<void(@local Controller*, int, @local Event*)> onKeyDown = nullptr]])
cls.var('onKeyUp', [[std::function<void(@local Controller*, int, @local Event*)> onKeyUp = nullptr]])
cls.var('onKeyRepeat', [[std::function<void(@local Controller*, int, @local Event*)> onKeyRepeat = nullptr]])
cls.var('onAxisEvent', [[std::function<void(@local Controller*, int, @local Event*)> onAxisEvent = nullptr]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventTouch::EventCode'
cls.enums [[
    BEGAN
    MOVED
    ENDED
    CANCELLED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventTouch'
cls.SUPERCLS = "cocos2d::Event"
cls.enums [[
    MAX_TOUCHES
]]
cls.funcs [[
    EventCode getEventCode()
    const std::vector<Touch*>& getTouches()
    void setEventCode(EventCode eventCode)
    void setTouches(const std::vector<Touch*>& touches)
]]
cls.props [[
    eventCode
    touches
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventKeyboard'
cls.SUPERCLS = "cocos2d::Event"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventAcceleration'
cls.SUPERCLS = "cocos2d::Event"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventFocus'
cls.SUPERCLS = "cocos2d::Event"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventMouse::MouseEventType'
cls.enums [[
    MOUSE_NONE
    MOUSE_DOWN
    MOUSE_UP
    MOUSE_MOVE
    MOUSE_SCROLL
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventMouse::MouseButton'
cls.enums [[
    BUTTON_UNSET
    BUTTON_LEFT
    BUTTON_RIGHT
    BUTTON_MIDDLE
    BUTTON_4
    BUTTON_5
    BUTTON_6
    BUTTON_7
    BUTTON_8
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventMouse'
cls.SUPERCLS = "cocos2d::Event"
cls.funcs [[
    void setScrollData(float scrollX, float scrollY)
    float getScrollX()
    float getScrollY()
    void setCursorPosition(float x, float y)
    void setMouseButton(MouseButton button)
    MouseButton getMouseButton()
    float getCursorX()
    float getCursorY()
    Vec2 getLocation()
    Vec2 getPreviousLocation()
    Vec2 getStartLocation()
    Vec2 getDelta()
    Vec2 getLocationInView()
    Vec2 getPreviousLocationInView()
    Vec2 getStartLocationInView()
]]
cls.props [[
    scrollX
    scrollY
    mouseButton
    cursorX
    cursorY
    location
    previousLocation
    startLocation
    delta
    locationInView
    previousLocationInView
    startLocationInView
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventKeyboard::KeyCode'
cls.enums [[
    KEY_NONE
    KEY_PAUSE
    KEY_SCROLL_LOCK
    KEY_PRINT
    KEY_SYSREQ
    KEY_BREAK
    KEY_ESCAPE
    KEY_BACK
    KEY_BACKSPACE
    KEY_TAB
    KEY_BACK_TAB
    KEY_RETURN
    KEY_CAPS_LOCK
    KEY_SHIFT
    KEY_LEFT_SHIFT
    KEY_RIGHT_SHIFT
    KEY_CTRL
    KEY_LEFT_CTRL
    KEY_RIGHT_CTRL
    KEY_ALT
    KEY_LEFT_ALT
    KEY_RIGHT_ALT
    KEY_MENU
    KEY_HYPER
    KEY_INSERT
    KEY_HOME
    KEY_PG_UP
    KEY_DELETE
    KEY_END
    KEY_PG_DOWN
    KEY_LEFT_ARROW
    KEY_RIGHT_ARROW
    KEY_UP_ARROW
    KEY_DOWN_ARROW
    KEY_NUM_LOCK
    KEY_KP_PLUS
    KEY_KP_MINUS
    KEY_KP_MULTIPLY
    KEY_KP_DIVIDE
    KEY_KP_ENTER
    KEY_KP_HOME
    KEY_KP_UP
    KEY_KP_PG_UP
    KEY_KP_LEFT
    KEY_KP_FIVE
    KEY_KP_RIGHT
    KEY_KP_END
    KEY_KP_DOWN
    KEY_KP_PG_DOWN
    KEY_KP_INSERT
    KEY_KP_DELETE
    KEY_F1
    KEY_F2
    KEY_F3
    KEY_F4
    KEY_F5
    KEY_F6
    KEY_F7
    KEY_F8
    KEY_F9
    KEY_F10
    KEY_F11
    KEY_F12
    KEY_SPACE
    KEY_EXCLAM
    KEY_QUOTE
    KEY_NUMBER
    KEY_DOLLAR
    KEY_PERCENT
    KEY_CIRCUMFLEX
    KEY_AMPERSAND
    KEY_APOSTROPHE
    KEY_LEFT_PARENTHESIS
    KEY_RIGHT_PARENTHESIS
    KEY_ASTERISK
    KEY_PLUS
    KEY_COMMA
    KEY_MINUS
    KEY_PERIOD
    KEY_SLASH
    KEY_0
    KEY_1
    KEY_2
    KEY_3
    KEY_4
    KEY_5
    KEY_6
    KEY_7
    KEY_8
    KEY_9
    KEY_COLON
    KEY_SEMICOLON
    KEY_LESS_THAN
    KEY_EQUAL
    KEY_GREATER_THAN
    KEY_QUESTION
    KEY_AT
    KEY_CAPITAL_A
    KEY_CAPITAL_B
    KEY_CAPITAL_C
    KEY_CAPITAL_D
    KEY_CAPITAL_E
    KEY_CAPITAL_F
    KEY_CAPITAL_G
    KEY_CAPITAL_H
    KEY_CAPITAL_I
    KEY_CAPITAL_J
    KEY_CAPITAL_K
    KEY_CAPITAL_L
    KEY_CAPITAL_M
    KEY_CAPITAL_N
    KEY_CAPITAL_O
    KEY_CAPITAL_P
    KEY_CAPITAL_Q
    KEY_CAPITAL_R
    KEY_CAPITAL_S
    KEY_CAPITAL_T
    KEY_CAPITAL_U
    KEY_CAPITAL_V
    KEY_CAPITAL_W
    KEY_CAPITAL_X
    KEY_CAPITAL_Y
    KEY_CAPITAL_Z
    KEY_LEFT_BRACKET
    KEY_BACK_SLASH
    KEY_RIGHT_BRACKET
    KEY_UNDERSCORE
    KEY_GRAVE
    KEY_A
    KEY_B
    KEY_C
    KEY_D
    KEY_E
    KEY_F
    KEY_G
    KEY_H
    KEY_I
    KEY_J
    KEY_K
    KEY_L
    KEY_M
    KEY_N
    KEY_O
    KEY_P
    KEY_Q
    KEY_R
    KEY_S
    KEY_T
    KEY_U
    KEY_V
    KEY_W
    KEY_X
    KEY_Y
    KEY_Z
    KEY_LEFT_BRACE
    KEY_BAR
    KEY_RIGHT_BRACE
    KEY_TILDE
    KEY_EURO
    KEY_POUND
    KEY_YEN
    KEY_MIDDLE_DOT
    KEY_SEARCH
    KEY_DPAD_LEFT
    KEY_DPAD_RIGHT
    KEY_DPAD_UP
    KEY_DPAD_DOWN
    KEY_DPAD_CENTER
    KEY_ENTER
    KEY_PLAY
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Touch::DispatchMode'
cls.enums [[
    ALL_AT_ONCE
    ONE_BY_ONE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventController::ControllerEventType'
cls.enums [[
    CONNECTION
    BUTTON_STATUS_CHANGED
    AXIS_STATUS_CHANGED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventController'
cls.SUPERCLS = "cocos2d::Event"
cls.funcs [[
    ControllerEventType getControllerEventType()
    Controller* getController()
    int getKeyCode()
    void setKeyCode(int keyCode)
    void setConnectStatus(bool isConnected)
    bool isConnected()
]]
cls.props [[
    controllerEventType
    controller
    keyCode
    connected
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Touch'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    Vec2 getLocation()
    Vec2 getPreviousLocation()
    Vec2 getStartLocation()
    Vec2 getDelta()
    Vec2 getLocationInView()
    Vec2 getPreviousLocationInView()
    Vec2 getStartLocationInView()
    void setTouchInfo(int id, float x, float y)
    void setTouchInfo(int id, float x, float y, float force, float maxForce)
    int getID()
    float getCurrentForce()
    float getMaxForce()
]]
cls.func('new', [[{
    auto obj = new cocos2d::Touch();
    obj->autorelease();
    return olua_push_cppobj<cocos2d::Touch>(L, obj);
}]])
cls.props [[
    location
    previousLocation
    startLocation
    delta
    locationInView
    previousLocationInView
    startLocationInView
    id
    currentForce
    maxForce
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Controller::Key'
cls.enums [[
    KEY_NONE
    JOYSTICK_LEFT_X
    JOYSTICK_LEFT_Y
    JOYSTICK_RIGHT_X
    JOYSTICK_RIGHT_Y
    BUTTON_A
    BUTTON_B
    BUTTON_C
    BUTTON_X
    BUTTON_Y
    BUTTON_Z
    BUTTON_DPAD_UP
    BUTTON_DPAD_DOWN
    BUTTON_DPAD_LEFT
    BUTTON_DPAD_RIGHT
    BUTTON_DPAD_CENTER
    BUTTON_LEFT_SHOULDER
    BUTTON_RIGHT_SHOULDER
    AXIS_LEFT_TRIGGER
    AXIS_RIGHT_TRIGGER
    BUTTON_LEFT_THUMBSTICK
    BUTTON_RIGHT_THUMBSTICK
    BUTTON_START
    BUTTON_SELECT
    BUTTON_PAUSE
    KEY_MAX
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Controller'
cls.funcs [[
    static const std::vector<Controller*>& getAllController()
    static Controller* getControllerByTag(int tag)
    static Controller* getControllerByDeviceId(int deviceId)
    static void startDiscoveryController()
    static void stopDiscoveryController()
    const std::string& getDeviceName()
    int getDeviceId()
    bool isConnected()
    const KeyStatus& getKeyStatus(int keyCode)
    void setTag(int tag)
    int getTag()
]]
cls.props [[
    allController
    deviceName
    deviceId
    connected
    tag
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::experimental::AudioProfile'
cls.funcs [[
]]
cls.var('name', [[std::string name]])
cls.var('maxInstances', [[unsigned int maxInstances]])
cls.var('minDelay', [[double minDelay]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::experimental::AudioEngine::AudioState'
cls.enums [[
    ERROR
    INITIALIZING
    PLAYING
    PAUSED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::experimental::AudioEngine'
cls.CHUNK = [[
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
cls.funcs [[
    static bool lazyInit()
    static void end()
    static AudioProfile* getDefaultProfile()
    static int play2d(const std::string& filePath, bool loop = false, float volume = 1.0f, const AudioProfile *profile = nullptr)
    static void setLoop(int audioID, bool loop)
    static bool isLoop(int audioID)
    static void setVolume(int audioID, float volume)
    static float getVolume(int audioID)
    static void pause(int audioID)
    static void pauseAll()
    static void resume(int audioID)
    static void resumeAll()
    static bool setCurrentTime(int audioID, float sec)
    static float getCurrentTime(int audioID)
    static float getDuration(int audioID)
    static AudioState getState(int audioID)
    static int getMaxAudioInstance()
    static bool setMaxAudioInstance(int maxInstances)
    static void uncache(const std::string& filePath)
    static AudioProfile* getProfile(int audioID)
    static AudioProfile* getProfile(const std::string &profileName)
    static int getPlayingAudioCount()
    static void setEnabled(bool isEnabled)
    static bool isEnabled()
]]
cls.callback {
    FUNCS =  {
        'static void stop(int audioID)',
    },
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_EQUAL',
    CALLONCE = false,
    REMOVE = true,
}
cls.callback {
    FUNCS =  {
        'static void stopAll()',
    },
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
    TAG_MODE = 'OLUA_TAG_STARTWITH',
    CALLONCE = false,
    REMOVE = true,
}
cls.callback {
    FUNCS =  {
        'static void uncacheAll()',
    },
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
    TAG_MODE = 'OLUA_TAG_STARTWITH',
    CALLONCE = false,
    REMOVE = true,
}
cls.callback {
    FUNCS =  {
        'static void setFinishCallback(int audioID, @nullable const std::function<void(int,const std::string&)>& callback)',
    },
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = true,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'static void preload(const std::string& filePath)',
        'static void preload(const std::string& filePath, std::function<void(bool isSuccess)> callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("preload")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = true,
    REMOVE = false,
}
cls.inject('uncache', {
    BEFORE = [[
        std::string path = olua_checkstring(L, 1);
        std::list<int> ids = cocos2d::LuaAudioEngine::getAudioIDs(path);
        const char *cls = olua_getluatype<cocos2d::experimental::AudioEngine>(L);
        void *callback_store_obj = (void *)olua_getstoreobj(L, cls);
        for (auto id : ids) {
            std::string tag = makeAudioEngineFinishCallbackTag((lua_Integer)id);
            olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_EQUAL);
        }
    ]],
})
cls.props [[
    defaultProfile
    maxAudioInstance
    playingAudioCount
    enabled
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'CocosDenshion::SimpleAudioEngine'
cls.funcs [[
    static SimpleAudioEngine* getInstance()
    static void end()
    void preloadBackgroundMusic(const char* filePath)
    void playBackgroundMusic(const char* filePath, bool loop = false)
    void stopBackgroundMusic(bool releaseData = false)
    void pauseBackgroundMusic()
    void resumeBackgroundMusic()
    void rewindBackgroundMusic()
    bool willPlayBackgroundMusic()
    bool isBackgroundMusicPlaying()
    float getBackgroundMusicVolume()
    void setBackgroundMusicVolume(float volume)
    float getEffectsVolume()
    void setEffectsVolume(float volume)
    unsigned int playEffect(const char* filePath, bool loop = false, float pitch = 1.0f, float pan = 0.0f, float gain = 1.0f)
    void pauseEffect(unsigned int soundId)
    void pauseAllEffects()
    void resumeEffect(unsigned int soundId)
    void resumeAllEffects()
    void stopEffect(unsigned int soundId)
    void stopAllEffects()
    void preloadEffect(const char* filePath)
    void unloadEffect(const char* filePath)
]]
cls.props [[
    instance
    backgroundMusicPlaying
    backgroundMusicVolume
    effectsVolume
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ApplicationProtocol::Platform'
cls.enums [[
    OS_WINDOWS
    OS_LINUX
    OS_MAC
    OS_ANDROID
    OS_IPHONE
    OS_IPAD
    OS_BLACKBERRY
    OS_NACL
    OS_EMSCRIPTEN
    OS_TIZEN
    OS_WINRT
    OS_WP8
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LanguageType'
cls.enums [[
    ENGLISH
    CHINESE
    FRENCH
    ITALIAN
    GERMAN
    SPANISH
    DUTCH
    RUSSIAN
    KOREAN
    JAPANESE
    HUNGARIAN
    PORTUGUESE
    ARABIC
    NORWEGIAN
    POLISH
    TURKISH
    UKRAINIAN
    ROMANIAN
    BULGARIAN
    BELARUSIAN
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ApplicationProtocol'
cls.funcs [[
    bool applicationDidFinishLaunching()
    void applicationDidEnterBackground()
    void applicationWillEnterForeground()
    void setAnimationInterval(float interval)
    void initGLContextAttrs()
    LanguageType getCurrentLanguage()
    const char * getCurrentLanguageCode()
    Platform getTargetPlatform()
    std::string getVersion()
    bool openURL(const std::string &url)
]]
cls.props [[
    currentLanguage
    currentLanguageCode
    targetPlatform
    version
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Application'
cls.SUPERCLS = "cocos2d::ApplicationProtocol"
cls.funcs [[
    int run()
    static Application* getInstance()
]]
cls.props [[
    instance
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Device'
cls.funcs [[
    static int getDPI()
    static void setAccelerometerEnabled(bool isEnabled)
    static void setAccelerometerInterval(float interval)
    static void setKeepScreenOn(bool keepScreenOn)
    static void vibrate(float duration)
]]
cls.props [[
    dpi
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FileUtils'
cls.funcs [[
    static FileUtils* getInstance()
    static void destroyInstance()
    static void setDelegate(FileUtils *delegate)
    void purgeCachedEntries()
    std::string getStringFromFile(const std::string& filename)
    Data getDataFromFile(const std::string& filename)
    std::string fullPathForFilename(const std::string &filename)
    void loadFilenameLookupDictionaryFromFile(const std::string &filename)
    void setFilenameLookupDictionary(const ValueMap& filenameLookupDict)
    std::string fullPathFromRelativeFile(const std::string &filename, const std::string &relativeFile)
    void setSearchResolutionsOrder(const std::vector<std::string>& searchResolutionsOrder)
    void addSearchResolutionsOrder(const std::string &order,const bool front=false)
    const std::vector<std::string> getSearchResolutionsOrder()
    void setSearchPaths(const std::vector<std::string>& searchPaths)
    const std::string getDefaultResourceRootPath()
    void setDefaultResourceRootPath(const std::string& path)
    void addSearchPath(const std::string & path, const bool front=false)
    const std::vector<std::string> getSearchPaths()
    const std::vector<std::string> getOriginalSearchPaths()
    std::string getWritablePath()
    void setWritablePath(const std::string& writablePath)
    void setPopupNotify(bool notify)
    bool isPopupNotify()
    ValueMap getValueMapFromFile(const std::string& filename)
    ValueMap getValueMapFromData(const char* filedata, int filesize)
    bool writeToFile(const ValueMap& dict, const std::string& fullPath)
    bool writeStringToFile(const std::string& dataStr, const std::string& fullPath)
    bool writeDataToFile(const Data& data, const std::string& fullPath)
    bool writeValueMapToFile(const ValueMap& dict, const std::string& fullPath)
    bool writeValueVectorToFile(const ValueVector& vecData, const std::string& fullPath)
    std::string getSuitableFOpen(const std::string& filenameUtf8)
    ValueVector getValueVectorFromFile(const std::string& filename)
    bool isFileExist(const std::string& filename)
    std::string getFileExtension(const std::string& filePath)
    bool isAbsolutePath(const std::string& path)
    bool isDirectoryExist(const std::string& dirPath)
    bool createDirectory(const std::string& dirPath)
    bool removeDirectory(const std::string& dirPath)
    bool removeFile(const std::string &filepath)
    bool renameFile(const std::string &path, const std::string &oldname, const std::string &name)
    bool renameFile(const std::string &oldfullpath, const std::string &newfullpath)
    long getFileSize(const std::string &filepath)
    std::vector<std::string> listFiles(const std::string& dirPath)
    std::string getNewFilename(const std::string &filename)
]]
cls.func('getFileDataFromZip', [[{
    lua_settop(L, 3);
    ssize_t size;
    auto self = olua_toobj<cocos2d::FileUtils>(L, 1);
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
cls.func('listFilesRecursively', [[{
    lua_settop(L, 2);
    auto self = olua_toobj<cocos2d::FileUtils>(L, 1);
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
cls.func('getFullPathCache', [[{
    lua_settop(L, 1);
    auto self = olua_toobj<cocos2d::FileUtils>(L, 1);
    const std::unordered_map<std::string, std::string> paths  = self->getFullPathCache();
    lua_createtable(L, 0, 4);
    for (const auto &it : paths) {
        olua_push_std_string(L, it.first);
        olua_push_std_string(L, it.second);
        lua_rawset(L, -3);
    }
    return 1;
}]])
cls.props [[
    instance
    searchResolutionsOrder
    defaultResourceRootPath
    searchPaths
    originalSearchPaths
    writablePath
    popupNotify
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'ResolutionPolicy'
cls.enums [[
    EXACT_FIT
    NO_BORDER
    SHOW_ALL
    FIXED_HEIGHT
    FIXED_WIDTH
    UNKNOWN
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GLView'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    void end()
    bool isOpenGLReady()
    void swapBuffers()
    void setIMEKeyboardState(bool open)
    bool windowShouldClose()
    static void setGLContextAttrs(GLContextAttrs& glContextAttrs)
    static GLContextAttrs getGLContextAttrs()
    void pollEvents()
    Size getFrameSize()
    void setFrameSize(float width, float height)
    void setFrameZoomFactor(float )
    float getFrameZoomFactor()
    void setCursor(const std::string& filename, Vec2 hotspot = Vec2::ANCHOR_TOP_LEFT)
    void setDefaultCursor()
    void setCursorVisible(bool )
    int getRetinaFactor()
    bool setContentScaleFactor(float )
    float getContentScaleFactor()
    bool isRetinaDisplay()
    Size getVisibleSize()
    Vec2 getVisibleOrigin()
    Rect getVisibleRect()
    Rect getSafeAreaRect()
    void setDesignResolutionSize(float width, float height, ResolutionPolicy resolutionPolicy)
    const Size& getDesignResolutionSize()
    void setViewPortInPoints(float x , float y , float w , float h)
    void setScissorInPoints(float x , float y , float w , float h)
    bool isScissorEnabled()
    Rect getScissorRect()
    void setViewName(const std::string& viewname)
    const std::string& getViewName()
    void setIcon(const std::string& filename)
    void setIcon(const std::vector<std::string>& filelist)
    void setDefaultIcon()
    const Rect& getViewPortRect()
    std::vector<Touch*> getAllTouches()
    float getScaleX()
    float getScaleY()
    ResolutionPolicy getResolutionPolicy()
    void renderScene(Scene* scene, Renderer* renderer)
    void setVR(@ref(single vr) VRIRenderer* vrrenderer)
    @ref(single vr) VRIRenderer* getVR()
]]
cls.props [[
    openGLReady
    glContextAttrs
    frameSize
    frameZoomFactor
    retinaFactor
    contentScaleFactor
    retinaDisplay
    visibleSize
    visibleOrigin
    visibleRect
    safeAreaRect
    designResolutionSize
    scissorEnabled
    scissorRect
    viewName
    viewPortRect
    allTouches
    scaleX
    scaleY
    resolutionPolicy
    vr
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GLViewImpl'
cls.SUPERCLS = "cocos2d::GLView"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Image::Format'
cls.enums [[
    JPG
    PNG
    TIFF
    WEBP
    PVR
    ETC
    S3TC
    ATITC
    TGA
    RAW_DATA
    UNKNOWN
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Image'
cls.SUPERCLS = "cocos2d::Ref"
cls.CHUNK = [[
NS_CC_BEGIN
class LuaImage : public cocos2d::Image {
public:
    static bool getPNGPremultipliedAlphaEnabled() { return PNG_PREMULTIPLIED_ALPHA_ENABLED; };
};
NS_CC_END
]]
cls.funcs [[
    static void setPNGPremultipliedAlphaEnabled(bool enabled)
    static void setPVRImagesHavePremultipliedAlpha(bool haveAlphaPremultiplied)
    bool initWithImageFile(const std::string& path)
    bool initWithImageData(const unsigned char * data, ssize_t dataLen)
    bool initWithRawData(const unsigned char * data, ssize_t dataLen, int width, int height, int bitsPerComponent, bool preMulti = false)
    unsigned char * getData()
    ssize_t getDataLen()
    Format getFileType()
    Texture2D::PixelFormat getRenderFormat()
    int getWidth()
    int getHeight()
    int getNumberOfMipmaps()
    bool hasPremultipliedAlpha()
    std::string getFilePath()
    int getBitPerPixel()
    bool hasAlpha()
    bool isCompressed()
    bool saveToFile(const std::string &filename, bool isToRGB = true)
]]
cls.func('getPNGPremultipliedAlphaEnabled', [[{
    lua_settop(L, 0);
    lua_pushboolean(L, cocos2d::LuaImage::getPNGPremultipliedAlphaEnabled());
    return 1;
}]])
cls.props [[
    data
    dataLen
    fileType
    renderFormat
    width
    height
    numberOfMipmaps
    filePath
    bitPerPixel
    compressed
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Renderer'
cls.enums [[
    VBO_SIZE
    BATCH_TRIAGCOMMAND_RESERVED_SIZE
    MATERIAL_ID_DO_NOT_BATCH
]]
cls.funcs [[
    void initGLView()
    void pushGroup(int renderQueueID)
    void popGroup()
    int createRenderQueue()
    void render()
    void clean()
    void clear()
    void setClearColor(const Color4F& clearColor)
    const Color4F& getClearColor()
    ssize_t getDrawnBatches()
    void addDrawnBatches(ssize_t number)
    ssize_t getDrawnVertices()
    void addDrawnVertices(ssize_t number)
    void clearDrawStats()
    void setDepthTest(bool enable)
    bool checkVisibility(const Mat4& transform, const Size& size)
]]
cls.props [[
    clearColor
    drawnBatches
    drawnVertices
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GLProgram'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static GLProgram* createWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray)
    bool initWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray)
    static GLProgram* createWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray, const std::string& compileTimeDefines)
    bool initWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray, const std::string& compileTimeDefines)
    static GLProgram* createWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray, const std::string& compileTimeHeaders, const std::string& compileTimeDefines)
    bool initWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray, const std::string& compileTimeHeaders, const std::string& compileTimeDefines)
    static GLProgram* createWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename)
    bool initWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename)
    static GLProgram* createWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename, const std::string& compileTimeDefines)
    bool initWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename, const std::string& compileTimeDefines)
    static GLProgram* createWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename, const std::string& compileTimeHeaders, const std::string& compileTimeDefines)
    bool initWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename, const std::string& compileTimeHeaders, const std::string& compileTimeDefines)
    Uniform* getUniform(const std::string& name)
    VertexAttrib* getVertexAttrib(const std::string& name)
    void bindAttribLocation(const std::string& attributeName, GLuint index)
    GLint getAttribLocation(const std::string& attributeName)
    GLint getUniformLocation(const std::string& attributeName)
    bool link()
    void use()
    void updateUniforms()
    GLint getUniformLocationForName(const char* name)
    void setUniformLocationWith1i(GLint location, GLint i1)
    void setUniformLocationWith2i(GLint location, GLint i1, GLint i2)
    void setUniformLocationWith3i(GLint location, GLint i1, GLint i2, GLint i3)
    void setUniformLocationWith4i(GLint location, GLint i1, GLint i2, GLint i3, GLint i4)
    void setUniformLocationWith1f(GLint location, GLfloat f1)
    void setUniformLocationWith2f(GLint location, GLfloat f1, GLfloat f2)
    void setUniformLocationWith3f(GLint location, GLfloat f1, GLfloat f2, GLfloat f3)
    void setUniformLocationWith4f(GLint location, GLfloat f1, GLfloat f2, GLfloat f3, GLfloat f4)
    void setUniformsForBuiltins(const Mat4 &modelView)
    void setUniformsForBuiltins()
    std::string getVertexShaderLog()
    std::string getFragmentShaderLog()
    std::string getProgramLog()
    void reset()
    GLuint getProgram()
]]
cls.props [[
    vertexShaderLog
    fragmentShaderLog
    programLog
    program
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GLProgramCache'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static GLProgramCache* getInstance()
    static void destroyInstance()
    void loadDefaultGLPrograms()
    void reloadDefaultGLPrograms()
    GLProgram * getGLProgram(const std::string &key)
    void addGLProgram(GLProgram* program, const std::string &key)
    void reloadDefaultGLProgramsRelativeToLights()
]]
cls.props [[
    instance
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GLProgramState'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static GLProgramState* create(GLProgram* glprogram)
    static GLProgramState* getOrCreateWithGLProgram(GLProgram* glprogram)
    static GLProgramState* getOrCreateWithGLProgramName(const std::string& glProgramName )
    static GLProgramState* getOrCreateWithGLProgramName(const std::string& glProgramName, Texture2D* texture)
    static GLProgramState* getOrCreateWithShaders(const std::string& vertexShader, const std::string& fragShader, const std::string& compileTimeDefines)
    GLProgramState* clone()
    void apply(const Mat4& modelView)
    void applyGLProgram(const Mat4& modelView)
    void applyAttributes(bool applyAttribFlags = true)
    void applyUniforms()
    void setGLProgram(@ref(single glProgram) GLProgram* glprogram)
    @ref(single glProgram) GLProgram* getGLProgram()
    uint32_t getVertexAttribsFlags()
    ssize_t getVertexAttribCount()
    void setVertexAttribPointer(const std::string& name, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid *pointer)
    ssize_t getUniformCount()
    void setUniformInt(const std::string& uniformName, int value)
    void setUniformFloat(const std::string& uniformName, float value)
    void setUniformVec2(const std::string& uniformName, const Vec2& value)
    void setUniformVec3(const std::string& uniformName, const Vec3& value)
    void setUniformVec4(const std::string& uniformName, const Vec4& value)
    void setUniformMat4(const std::string& uniformName, const Mat4& value)
    void setUniformTexture(const std::string& uniformName, Texture2D *texture)
    void setUniformInt(GLint uniformLocation, int value)
    void setUniformFloat(GLint uniformLocation, float value)
    void setUniformVec2(GLint uniformLocation, const Vec2& value)
    void setUniformVec3(GLint uniformLocation, const Vec3& value)
    void setUniformVec4(GLint uniformLocation, const Vec4& value)
    void setUniformMat4(GLint uniformLocation, const Mat4& value)
    void setUniformTexture(GLint uniformLocation, Texture2D *texture)
    @ref(single nodeBinding) Node* getNodeBinding()
    void setNodeBinding(@ref(single nodeBinding) Node* node)
    void applyAutoBinding(const std::string& uniformName, const std::string& autoBinding)
    void setParameterAutoBinding(const std::string& uniformName, const std::string& autoBinding)
]]
cls.props [[
    glProgram
    vertexAttribsFlags
    vertexAttribCount
    uniformCount
    nodeBinding
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextureCache'
cls.SUPERCLS = "cocos2d::Ref"
cls.CHUNK = [[
static const std::string makeTextureCacheCallbackTag(const std::string &key)
{
    return "addImageAsync." + key;
}]]
cls.funcs [[
    static void setETC1AlphaFileSuffix(const std::string& suffix)
    static std::string getETC1AlphaFileSuffix()
    std::string getDescription()
    Texture2D* addImage(const std::string &filepath)
    Texture2D* addImage(Image *image, const std::string &key)
    Texture2D* getTextureForKey(const std::string& key)
    bool reloadTexture(const std::string& fileName)
    void removeAllTextures()
    void removeUnusedTextures()
    void removeTexture(Texture2D* texture)
    void removeTextureForKey(const std::string &key)
    std::string getCachedTextureInfo()
    void waitForQuit()
    std::string getTextureFilePath(Texture2D* texture)
    void renameTextureWithKey(const std::string& srcName, const std::string& dstName)
]]
cls.callback {
    FUNCS =  {
        'void addImageAsync(const std::string &filepath, const std::function<void(Texture2D*)>& callback)',
        'void addImageAsync(const std::string &path, const std::function<void(Texture2D*)>& callback, const std::string& callbackKey)',
    },
    TAG_MAKER = {'makeTextureCacheCallbackTag(#1)', 'makeTextureCacheCallbackTag(#-1)'},
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = true,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void unbindImageAsync(const std::string &filename)',
    },
    TAG_MAKER = 'makeTextureCacheCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_EQUAL',
    CALLONCE = false,
    REMOVE = true,
}
cls.callback {
    FUNCS =  {
        'void unbindAllImageAsync()',
    },
    TAG_MAKER = 'makeTextureCacheCallbackTag("")',
    TAG_MODE = 'OLUA_TAG_STARTWITH',
    CALLONCE = false,
    REMOVE = true,
}
cls.props [[
    etC1AlphaFileSuffix
    description
    cachedTextureInfo
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Texture2D::PixelFormat'
cls.enums [[
    AUTO
    BGRA8888
    RGBA8888
    RGB888
    RGB565
    A8
    I8
    AI88
    RGBA4444
    RGB5A1
    PVRTC4
    PVRTC4A
    PVRTC2
    PVRTC2A
    ETC
    S3TC_DXT1
    S3TC_DXT3
    S3TC_DXT5
    ATC_RGB
    ATC_EXPLICIT_ALPHA
    ATC_INTERPOLATED_ALPHA
    DEFAULT
    NONE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Texture2D'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static void setDefaultAlphaPixelFormat(Texture2D::PixelFormat format)
    static Texture2D::PixelFormat getDefaultAlphaPixelFormat()
    std::string getDescription()
    void releaseGLTexture()
    bool initWithData(const void *data, ssize_t dataLen, Texture2D::PixelFormat pixelFormat, int pixelsWide, int pixelsHigh, const Size& contentSize)
    bool updateWithData(const void *data,int offsetX,int offsetY,int width,int height)
    void drawAtPoint(const Vec2& point)
    void drawInRect(const Rect& rect)
    bool initWithImage(Image * image)
    bool initWithImage(Image * image, PixelFormat format)
    bool initWithString(const char *text, const std::string &fontName, float fontSize, const Size& dimensions = Size(0, 0), TextHAlignment hAlignment = TextHAlignment::CENTER, TextVAlignment vAlignment = TextVAlignment::TOP, bool enableWrap = true, int overflow = 0)
    void setTexParameters(const TexParams& texParams)
    void setAntiAliasTexParameters()
    void setAliasTexParameters()
    void generateMipmap()
    const char* getStringForFormat()
    unsigned int getBitsPerPixelForFormat()
    unsigned int getBitsPerPixelForFormat(Texture2D::PixelFormat format)
    const Size& getContentSizeInPixels()
    bool hasPremultipliedAlpha()
    bool hasMipmaps()
    Texture2D::PixelFormat getPixelFormat()
    int getPixelsWide()
    int getPixelsHigh()
    GLuint getName()
    GLfloat getMaxS()
    void setMaxS(GLfloat maxS)
    GLfloat getMaxT()
    void setMaxT(GLfloat maxT)
    Size getContentSize()
    void setGLProgram(GLProgram* program)
    GLProgram* getGLProgram()
    std::string getPath()
    void setAlphaTexture(Texture2D* alphaTexture)
    Texture2D* getAlphaTexture()
    GLuint getAlphaTextureName()
]]
cls.props [[
    defaultAlphaPixelFormat
    description
    stringForFormat
    contentSizeInPixels
    pixelFormat
    pixelsWide
    pixelsHigh
    name
    maxS
    maxT
    contentSize
    glProgram
    path
    alphaTexture
    alphaTextureName
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextureCube'
cls.SUPERCLS = "cocos2d::Texture2D"
cls.funcs [[
    static TextureCube* create(const std::string& positive_x, const std::string& negative_x, const std::string& positive_y, const std::string& negative_y, const std::string& positive_z, const std::string& negative_z)
    bool reloadTexture()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextureAtlas'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static TextureAtlas* create(const std::string& file , ssize_t capacity)
    static TextureAtlas* createWithTexture(Texture2D *texture, ssize_t capacity)
    bool initWithFile(const std::string& file, ssize_t capacity)
    bool initWithTexture(Texture2D *texture, ssize_t capacity)
    void insertQuadFromIndex(ssize_t fromIndex, ssize_t newIndex)
    void removeQuadAtIndex(ssize_t index)
    void removeQuadsAtIndex(ssize_t index, ssize_t amount)
    void removeAllQuads()
    bool resizeCapacity(ssize_t capacity)
    void increaseTotalQuadsWith(ssize_t amount)
    void moveQuadsFromIndex(ssize_t oldIndex, ssize_t amount, ssize_t newIndex)
    void moveQuadsFromIndex(ssize_t index, ssize_t newIndex)
    void fillWithEmptyQuadsFromIndex(ssize_t index, ssize_t amount)
    void drawNumberOfQuads(ssize_t n)
    void drawNumberOfQuads(ssize_t numberOfQuads, ssize_t start)
    void drawQuads()
    void listenRendererRecreated(EventCustom* event)
    bool isDirty()
    void setDirty(bool bDirty)
    std::string getDescription()
    ssize_t getTotalQuads()
    ssize_t getCapacity()
    Texture2D* getTexture()
    void setTexture(Texture2D* texture)
]]
cls.props [[
    dirty
    description
    totalQuads
    capacity
    texture
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::VRIHeadTracker'
cls.funcs [[
    Vec3 getLocalPosition()
    Mat4 getLocalRotation()
]]
cls.props [[
    localPosition
    localRotation
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::VRIRenderer'
cls.funcs [[
    void setup(GLView* glview)
    void cleanup()
    void render(Scene* scene, Renderer* renderer)
    VRIHeadTracker* getHeadTracker()
]]
cls.props [[
    headTracker
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::VRGenericRenderer'
cls.SUPERCLS = "cocos2d::VRIRenderer"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::VRGenericHeadTracker'
cls.SUPERCLS = "cocos2d::VRIHeadTracker"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::network::WebSocket::ErrorCode'
cls.enums [[
    TIME_OUT
    CONNECTION_FAILURE
    UNKNOWN
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::network::WebSocket::State'
cls.enums [[
    CONNECTING
    OPEN
    CLOSING
    CLOSED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::network::WebSocket::Delegate'
cls.funcs [[
]]
cls.func('__gc', [[{
    auto self = olua_touserdata(L, 1, cocos2d::network::WebSocket::Delegate *);
    if (self) {
        *(void **)lua_touserdata(L, 1) = nullptr;
        delete self;
    }
    return 0;
}]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::network::WebSocket'
cls.funcs [[
    static void closeAllConnections()
    void send(const std::string& message)
    void send(const unsigned char* binaryMsg, unsigned int len)
    void close()
    void closeAsync()
    State getReadyState()
    const std::string& getUrl()
    const std::string& getProtocol()
]]
cls.func('__gc', [[{
    auto self = olua_touserdata(L, 1, cocos2d::network::WebSocket *);
    if (self) {
        *(void **)lua_touserdata(L, 1) = nullptr;
        delete self;
    }
    return 0;
}]])
cls.func('create', [[{
    lua_settop(L, 4);
    std::vector<std::string> protocols;
    auto self = new cocos2d::network::WebSocket();
    auto delegate = olua_checkobj<cocos2d::network::WebSocket::Delegate>(L, 1);
    std::string url = olua_tostring(L, 2);
    std::string cafile = olua_optstring(L, 4, "");
    
    if (not lua_isnil(L, 3)) {
        luaL_checktype(L, 3, LUA_TTABLE);
        int len = (int)lua_rawlen(L, 3);
        protocols.reserve(len);
        for (int i = 1; i <= len; i++) {
            lua_rawgeti(L, 3, i);
            protocols.push_back(olua_checkstring(L, -1));
            lua_pop(L, 1);
        }
    }
    
    self->init(*delegate, url, protocols.size() > 0 ? &protocols : nullptr, cafile);
    olua_push_cppobj<cocos2d::network::WebSocket>(L, self);
    olua_singleref(L, -1, "delegate", 1);

    return 1;
}]])
cls.props [[
    readyState
    url
    protocol
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LuaWebSocketDelegate'
cls.SUPERCLS = "cocos2d::network::WebSocket::Delegate"
cls.funcs [[
    static LuaWebSocketDelegate *create()
]]
cls.var('onOpen', [[@nullable std::function<void (network::WebSocket *)> onOpenCallback]])
cls.var('onMessage', [[@nullable std::function<void (network::WebSocket *, const network::WebSocket::Data &)> onMessageCallback]])
cls.var('onClose', [[@nullable std::function<void (network::WebSocket *)> onCloseCallback]])
cls.var('onError', [[@nullable std::function<void (network::WebSocket *, const network::WebSocket::ErrorCode &)> onErrorCallback]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionManager'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    void addAction(Action *action, Node *target, bool paused)
    void removeAllActions()
    void removeAllActionsFromTarget(Node *target)
    void removeAction(Action *action)
    void removeActionByTag(int tag, Node *target)
    void removeAllActionsByTag(int tag, Node *target)
    void removeActionsByFlags(unsigned int flags, Node *target)
    Action* getActionByTag(int tag, const Node *target)
    ssize_t getNumberOfRunningActionsInTarget(const Node *target)
    ssize_t getNumberOfRunningActions()
    size_t getNumberOfRunningActionsInTargetByTag(const Node *target, int tag)
    void pauseTarget(Node *target)
    void resumeTarget(Node *target)
    Vector<Node*> pauseAllRunningActions()
    void resumeTargets(const Vector<Node*>& targetsToResume)
    void update(float dt)
]]
cls.func('new', [[{
    auto obj = new cocos2d::ActionManager();
    obj->autorelease();
    return olua_push_cppobj<cocos2d::ActionManager>(L, obj);
}
]])
cls.props [[
    numberOfRunningActions
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Action'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    std::string description()
    Action* clone()
    Action* reverse()
    bool isDone()
    void startWithTarget(Node *target)
    void stop()
    void step(float dt)
    void update(float time)
    Node* getTarget()
    void setTarget(Node *target)
    Node* getOriginalTarget()
    void setOriginalTarget(Node *originalTarget)
    int getTag()
    void setTag(int tag)
    unsigned int getFlags()
    void setFlags(unsigned int flags)
]]
cls.props [[
    done
    target
    originalTarget
    tag
    flags
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FiniteTimeAction'
cls.SUPERCLS = "cocos2d::Action"
cls.funcs [[
    float getDuration()
    void setDuration(float duration)
]]
cls.props [[
    duration
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Speed'
cls.SUPERCLS = "cocos2d::Action"
cls.funcs [[
    static Speed* create(@ref(single innerAction) ActionInterval* action, float speed)
    float getSpeed()
    void setSpeed(float speed)
    void setInnerAction(@ref(single innerAction) ActionInterval *action)
    @ref(single innerAction) ActionInterval* getInnerAction()
]]
cls.props [[
    speed
    innerAction
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Follow'
cls.SUPERCLS = "cocos2d::Action"
cls.funcs [[
    static Follow* create(Node *followedNode, const Rect& rect = Rect::ZERO)
    static Follow* createWithOffset(Node* followedNode,float xOffset,float yOffset,const Rect& rect = Rect::ZERO)
    bool isBoundarySet()
    void setBoundarySet(bool value)
    bool initWithTarget(Node *followedNode, const Rect& rect = Rect::ZERO)
    bool initWithTargetAndOffset(Node *followedNode,float xOffset,float yOffset,const Rect& rect = Rect::ZERO)
]]
cls.props [[
    boundarySet
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::tweenfunc'
cls.REG_LUATYPE = false
cls.funcs [[
    static float easeIn(float time, float rate)
    static float easeOut(float time, float rate)
    static float easeInOut(float time, float rate)
    static float bezieratFunction( float a, float b, float c, float d, float t )
    static float quadraticIn(float time)
    static float quadraticOut(float time)
    static float quadraticInOut(float time)
    static float quadraticInOut(float time)
    static float linear(float time)
    static float sineEaseIn(float time)
    static float sineEaseOut(float time)
    static float sineEaseInOut(float time)
    static float quadEaseIn(float time)
    static float quadEaseOut(float time)
    static float quadEaseInOut(float time)
    static float cubicEaseIn(float time)
    static float cubicEaseOut(float time)
    static float cubicEaseInOut(float time)
    static float quartEaseIn(float time)
    static float quartEaseOut(float time)
    static float quartEaseInOut(float time)
    static float quintEaseIn(float time)
    static float quintEaseOut(float time)
    static float quintEaseInOut(float time)
    static float expoEaseIn(float time)
    static float expoEaseOut(float time)
    static float expoEaseInOut(float time)
    static float circEaseIn(float time)
    static float circEaseOut(float time)
    static float circEaseInOut(float time)
    static float elasticEaseIn(float time, float period)
    static float elasticEaseOut(float time, float period)
    static float elasticEaseInOut(float time, float period)
    static float backEaseIn(float time)
    static float backEaseOut(float time)
    static float backEaseInOut(float time)
    static float bounceEaseIn(float time)
    static float bounceEaseOut(float time)
    static float bounceEaseInOut(float time)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionInterval'
cls.SUPERCLS = "cocos2d::FiniteTimeAction"
cls.funcs [[
    float getElapsed()
    void setAmplitudeRate(float amp)
    float getAmplitudeRate()
]]
cls.props [[
    elapsed
    amplitudeRate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Sequence'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static Sequence* createWithTwoActions(@ref(map autoref) FiniteTimeAction *actionOne, @ref(map autoref) FiniteTimeAction *actionTwo)
]]
cls.func('create', [[{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    auto ret = new cocos2d::Sequence();
    ret->autorelease();
    olua_push_cppobj<cocos2d::Sequence>(L, ret);

    for (int i = 1; i <= n; i++) {
        auto obj = olua_checkobj<cocos2d::FiniteTimeAction>(L, i);
        actions.pushBack(obj);
        olua_mapref(L, -1, ".autoref", i);
    }

    ret->init(actions);
    
    return 1;
}]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Repeat'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static Repeat* create(@ref(single innerAction) FiniteTimeAction *action, unsigned int times)
    void setInnerAction(@ref(single innerAction) FiniteTimeAction *action)
    @ref(single innerAction) FiniteTimeAction* getInnerAction()
]]
cls.props [[
    innerAction
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RepeatForever'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static RepeatForever* create(@ref(single innerAction) ActionInterval *action)
    void setInnerAction(@ref(single innerAction) ActionInterval *action)
    @ref(single innerAction) ActionInterval* getInnerAction()
]]
cls.props [[
    innerAction
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Spawn'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static Spawn* createWithTwoActions(@ref(map autoref) FiniteTimeAction *action1, @ref(map autoref) FiniteTimeAction *action2)
]]
cls.func('create', [[{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    auto ret = new cocos2d::Spawn();
    ret->autorelease();
    olua_push_cppobj<cocos2d::Spawn>(L, ret);

    for (int i = 1; i <= n; i++) {
        auto obj = olua_checkobj<cocos2d::FiniteTimeAction>(L, i);
        actions.pushBack(obj);
        olua_mapref(L, -1, ".autoref", i);
    }
    
    ret->init(actions);

    return 1;
}]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RotateTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static RotateTo* create(float duration, float dstAngleX, float dstAngleY)
    static RotateTo* create(float duration, float dstAngle)
    static RotateTo* create(float duration, const Vec3& dstAngle3D)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RotateBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static RotateBy* create(float duration, float deltaAngle)
    static RotateBy* create(float duration, float deltaAngleZ_X, float deltaAngleZ_Y)
    static RotateBy* create(float duration, const Vec3& deltaAngle3D)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MoveBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static MoveBy* create(float duration, @pack const Vec2& deltaPosition)
    static MoveBy* create(float duration, @pack const Vec3& deltaPosition)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MoveTo'
cls.SUPERCLS = "cocos2d::MoveBy"
cls.funcs [[
    static MoveTo* create(float duration, @pack const Vec2& position)
    static MoveTo* create(float duration, @pack const Vec3& position)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SkewTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static SkewTo* create(float t, float sx, float sy)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SkewBy'
cls.SUPERCLS = "cocos2d::SkewTo"
cls.funcs [[
    static SkewBy* create(float t, float deltaSkewX, float deltaSkewY)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ResizeTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static ResizeTo* create(float duration, const cocos2d::Size& final_size)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ResizeBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static ResizeBy* create(float duration, const cocos2d::Size& deltaSize)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BezierBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static BezierBy* create(float t, @pack const ccBezierConfig& c)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BezierTo'
cls.SUPERCLS = "cocos2d::BezierBy"
cls.funcs [[
    static BezierTo* create(float t, @pack const ccBezierConfig& c)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::JumpBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static JumpBy* create(float duration, @pack const Vec2& position, float height, int jumps)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::JumpTo'
cls.SUPERCLS = "cocos2d::JumpBy"
cls.funcs [[
    static JumpTo* create(float duration, @pack const Vec2& position, float height, int jumps)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ScaleTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static ScaleTo* create(float duration, float s)
    static ScaleTo* create(float duration, float sx, float sy)
    static ScaleTo* create(float duration, float sx, float sy, float sz)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ScaleBy'
cls.SUPERCLS = "cocos2d::ScaleTo"
cls.funcs [[
    static ScaleBy* create(float duration, float s)
    static ScaleBy* create(float duration, float sx, float sy)
    static ScaleBy* create(float duration, float sx, float sy, float sz)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Blink'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static Blink* create(float duration, int blinks)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static FadeTo* create(float duration, GLubyte opacity)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeIn'
cls.SUPERCLS = "cocos2d::FadeTo"
cls.funcs [[
    static FadeIn* create(float d)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOut'
cls.SUPERCLS = "cocos2d::FadeTo"
cls.funcs [[
    static FadeOut* create(float d)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TintTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static TintTo* create(float duration, GLubyte red, GLubyte green, GLubyte blue)
    static TintTo* create(float duration, const Color3B& color)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TintBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static TintBy* create(float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::DelayTime'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static DelayTime* create(float d)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ReverseTime'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static ReverseTime* create(@ref(map autoref) FiniteTimeAction *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Animate'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static Animate* create(Animation *animation)
    void setAnimation( Animation* animation )
    Animation* getAnimation()
    int getCurrentFrameIndex()
]]
cls.props [[
    animation
    currentFrameIndex
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TargetedAction'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static TargetedAction* create(Node* target, @ref(map autoref) FiniteTimeAction* action)
    void setForcedTarget(Node* forcedTarget)
    Node* getForcedTarget()
    bool initWithTarget(Node* target, FiniteTimeAction* action)
]]
cls.props [[
    forcedTarget
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionFloat'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
]]
cls.callback {
    FUNCS =  {
        'static ActionFloat* create(float duration, float from, float to, std::function<void(float value)> callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("ActionFloat")',
    TAG_MODE = 'OLUA_TAG_NEW',
    CPPFUNC = 'initWithDuration',
    NEW = [[
        auto *self = new ${DECLTYPE}();
        auto *ret = self;
        self->autorelease();
        olua_push_cppobj<${DECLTYPE}>(L, self);
    ]],
    CALLONCE = false,
    REMOVE = false,
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProgressTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static ProgressTo* create(float duration, float percent)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProgressFromTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static ProgressFromTo* create(float duration, float fromPercentage, float toPercentage)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionEase'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    @ref(single innerAction) ActionInterval* getInnerAction()
]]
cls.props [[
    innerAction
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseRateAction'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static EaseRateAction* create(@ref(single innerAction) ActionInterval* action, float rate)
    void setRate(float rate)
    float getRate()
]]
cls.props [[
    rate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseExponentialIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseExponentialIn * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseExponentialOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseExponentialOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseExponentialInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseExponentialInOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseSineIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseSineIn * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseSineOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseSineOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseSineInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseSineInOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBounceIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBounceIn * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBounceOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBounceOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBounceInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBounceInOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBackIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBackIn * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBackOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBackOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBackInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBackInOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuadraticActionIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuadraticActionIn * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuadraticActionOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuadraticActionOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuadraticActionInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuadraticActionInOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuarticActionIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuarticActionIn * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuarticActionOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuarticActionOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuarticActionInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuarticActionInOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuinticActionIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuinticActionIn * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuinticActionOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuinticActionOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuinticActionInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuinticActionInOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCircleActionIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCircleActionIn * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCircleActionOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCircleActionOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCircleActionInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCircleActionInOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCubicActionIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCubicActionIn * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCubicActionOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCubicActionOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCubicActionInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCubicActionInOut * create(@ref(single innerAction) cocos2d::ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseIn'
cls.SUPERCLS = "cocos2d::EaseRateAction"
cls.funcs [[
    static cocos2d::EaseIn * create(@ref(single innerAction) cocos2d::ActionInterval * action, float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseOut'
cls.SUPERCLS = "cocos2d::EaseRateAction"
cls.funcs [[
    static cocos2d::EaseOut * create(@ref(single innerAction) cocos2d::ActionInterval * action, float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseInOut'
cls.SUPERCLS = "cocos2d::EaseRateAction"
cls.funcs [[
    static cocos2d::EaseInOut * create(@ref(single innerAction) cocos2d::ActionInterval * action, float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElastic'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    float getPeriod()
    void setPeriod(float fPeriod)
]]
cls.props [[
    period
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElasticIn'
cls.SUPERCLS = "cocos2d::EaseElastic"
cls.funcs [[
    static cocos2d::EaseElasticIn * create(@ref(single innerAction) cocos2d::ActionInterval * action, float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElasticOut'
cls.SUPERCLS = "cocos2d::EaseElastic"
cls.funcs [[
    static cocos2d::EaseElasticOut * create(@ref(single innerAction) cocos2d::ActionInterval * action, float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElasticInOut'
cls.SUPERCLS = "cocos2d::EaseElastic"
cls.funcs [[
    static cocos2d::EaseElasticInOut * create(@ref(single innerAction) cocos2d::ActionInterval * action, float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBezierAction'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static EaseBezierAction* create(@ref(single innerAction) cocos2d::ActionInterval* action)
    void setBezierParamer( float p0, float p1, float p2, float p3)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PointArray'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static PointArray* create(ssize_t capacity)
    bool initWithCapacity(ssize_t capacity)
    void addControlPoint(const Vec2& controlPoint)
    void insertControlPoint(const Vec2& controlPoint, ssize_t index)
    void replaceControlPoint(const Vec2& controlPoint, ssize_t index)
    const Vec2& getControlPointAtIndex(ssize_t index)
    void removeControlPointAtIndex(ssize_t index)
    ssize_t count()
    PointArray* reverse()
    void reverseInline()
    PointArray* clone()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CardinalSplineTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static CardinalSplineTo* create(float duration, PointArray* points, float tension)
    void updatePosition(const Vec2 &newPos)
    PointArray* getPoints()
    void setPoints(PointArray* points)
]]
cls.props [[
    points
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CardinalSplineBy'
cls.SUPERCLS = "cocos2d::CardinalSplineTo"
cls.funcs [[
    static CardinalSplineBy* create(float duration, PointArray* points, float tension)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CatmullRomTo'
cls.SUPERCLS = "cocos2d::CardinalSplineTo"
cls.funcs [[
    static CatmullRomTo* create(float dt, PointArray* points)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CatmullRomBy'
cls.SUPERCLS = "cocos2d::CardinalSplineBy"
cls.funcs [[
    static CatmullRomBy* create(float dt, PointArray* points)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionInstant'
cls.SUPERCLS = "cocos2d::FiniteTimeAction"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Show'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static Show * create()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Hide'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static Hide * create()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ToggleVisibility'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static ToggleVisibility * create()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RemoveSelf'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static RemoveSelf * create(bool isNeedCleanUp = true)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipX'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static FlipX * create(bool x)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipY'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static FlipY * create(bool y)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Place'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static Place * create(const Vec2& pos)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CallFunc'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    void execute()
    Ref* getTargetCallback()
    void setTargetCallback(Ref* sel)
]]
cls.callback {
    FUNCS =  {
        'static CallFunc * create(const std::function<void()>& func)',
    },
    TAG_MAKER = 'olua_makecallbacktag("CallFunc")',
    TAG_MODE = 'OLUA_TAG_NEW',
    CPPFUNC = 'initWithFunction',
    NEW = [[
        auto *self = new ${DECLTYPE}();
        auto *ret = self;
        self->autorelease();
        olua_push_cppobj<${DECLTYPE}>(L, self);
    ]],
    CALLONCE = false,
    REMOVE = false,
}
cls.props [[
    targetCallback
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Component'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static Component* create()
    bool init()
    bool isEnabled()
    void setEnabled(bool enabled)
    const std::string& getName()
    void setName(const std::string& name)
    @ref(single owner) Node* getOwner()
    void setOwner(@ref(single owner) Node *owner)
    void update(float delta)
    bool serialize(void* r)
]]
cls.props [[
    enabled
    name
    owner
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LuaComponent'
cls.SUPERCLS = "cocos2d::Component"
cls.funcs [[
    static LuaComponent* create()
]]
cls.var('onUpdate', [[@nullable std::function<void(float)> onUpdateCallback]])
cls.var('onEnter', [[@nullable std::function<void()> onEnterCallback]])
cls.var('onExit', [[@nullable std::function<void()> onExitCallback]])
cls.var('onAdd', [[@nullable std::function<void()> onAddCallback]])
cls.var('onRemove', [[@nullable std::function<void()> onRemoveCallback]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Node'
cls.SUPERCLS = "cocos2d::Ref"
cls.CHUNK = [[
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
cls.funcs [[
    static Node * create()
    static int getAttachedNodeCount()
    std::string getDescription()
    void setLocalZOrder(std::int32_t localZOrder)
    void updateOrderOfArrival()
    std::int32_t getLocalZOrder()
    void setGlobalZOrder(float globalZOrder)
    float getGlobalZOrder()
    void setScaleX(float scaleX)
    float getScaleX()
    void setScaleY(float scaleY)
    float getScaleY()
    void setScaleZ(float scaleZ)
    float getScaleZ()
    void setScale(float scale)
    float getScale()
    void setScale(float scaleX, float scaleY)
    void setPosition(const Vec2 &position)
    void setPositionNormalized(const Vec2 &position)
    void setNormalizedPosition(const Vec2 &position)
    const Vec2& getPosition()
    const Vec2& getPositionNormalized()
    const Vec2& getNormalizedPosition()
    void setPosition(float x, float y)
    void setPositionX(float x)
    float getPositionX(void)
    void setPositionY(float y)
    float getPositionY(void)
    void setPosition3D(const Vec3& position)
    Vec3 getPosition3D()
    void setPositionZ(float positionZ)
    float getPositionZ()
    void setSkewX(float skewX)
    float getSkewX()
    void setSkewY(float skewY)
    float getSkewY()
    void setAnchorPoint(const Vec2& anchorPoint)
    const Vec2& getAnchorPoint()
    const Vec2& getAnchorPointInPoints()
    void setContentSize(const Size& contentSize)
    const Size& getContentSize()
    void setVisible(bool visible)
    bool isVisible()
    void setRotation(float rotation)
    float getRotation()
    void setRotation3D(const Vec3& rotation)
    Vec3 getRotation3D()
    void setRotationQuat(const Quaternion& quat)
    Quaternion getRotationQuat()
    void setRotationSkewX(float rotationX)
    float getRotationSkewX()
    void setRotationSkewY(float rotationY)
    float getRotationSkewY()
    void setIgnoreAnchorPointForPosition(bool ignore)
    bool isIgnoreAnchorPointForPosition()
    void addChild(@ref(map children) Node * child)
    void addChild(@ref(map children) Node * child, int localZOrder)
    void addChild(@ref(map children) Node* child, int localZOrder, int tag)
    void addChild(@ref(map children) Node* child, int localZOrder, const std::string &name)
    @ref(map children) Node * getChildByTag(int tag)
    @ref(map children) Node* getChildByName(const std::string& name)
    @ref(map children) Vector<Node*>& getChildren()
    ssize_t getChildrenCount()
    void setParent(Node* parent)
    Node* getParent()
    @unref(map children parent) void removeFromParent()
    @unref(map children parent) void removeFromParentAndCleanup(bool cleanup)
    void removeChild(@unref(map children) Node* child, bool cleanup = true)
    @unref(cmp children) void removeChildByTag(int tag, bool cleanup = true)
    @unref(cmp children) void removeChildByName(const std::string &name, bool cleanup = true)
    @unref(all children) void removeAllChildren()
    @unref(all children) void removeAllChildrenWithCleanup(bool cleanup)
    void reorderChild(Node * child, int localZOrder)
    void sortAllChildren()
    int getTag()
    void setTag(int tag)
    const std::string& getName()
    void setName(const std::string& name)
    void* getUserData()
    void setUserData(void *userData)
    Ref* getUserObject()
    void setUserObject(Ref *userObject)
    @ref(single glProgram) GLProgram* getGLProgram()
    void setGLProgram(@ref(single glProgram) GLProgram *glprogram)
    @ref(single glProgramState) GLProgramState *getGLProgramState()
    void setGLProgramState(@ref(single glProgramState) GLProgramState *glProgramState)
    bool isRunning()
    void onEnter()
    void onEnterTransitionDidFinish()
    void onExit()
    void onExitTransitionDidStart()
    void cleanup()
    void draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
    void draw()
    void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)
    void visit()
    Scene* getScene()
    Rect getBoundingBox()
    void setEventDispatcher(@ref(single eventDispatcher) EventDispatcher* dispatcher)
    @ref(single eventDispatcher) EventDispatcher* getEventDispatcher()
    void setActionManager(@ref(single actionManager) ActionManager* actionManager)
    @ref(single actionManager) ActionManager* getActionManager()
    @unref(cmp actions) Action* runAction(@ref(map actions) Action* action)
    @unref(cmp actions) void stopAllActions()
    @unref(cmp actions) void stopAction(Action* action)
    @unref(cmp actions) void stopActionByTag(int tag)
    @unref(cmp actions) void stopAllActionsByTag(int tag)
    @unref(cmp actions) void stopActionsByFlags(unsigned int flags)
    @ref(map actions) Action* getActionByTag(int tag)
    ssize_t getNumberOfRunningActions()
    ssize_t getNumberOfRunningActionsByTag(int tag)
    void setScheduler(@ref(single scheduler) Scheduler* scheduler)
    @ref(single scheduler) Scheduler* getScheduler()
    bool isScheduled(const std::string &key)
    void scheduleUpdate(void)
    void scheduleUpdateWithPriority(int priority)
    void unscheduleUpdate(void)
    void resume(void)
    void pause(void)
    void update(float delta)
    void updateTransform()
    const Mat4& getNodeToParentTransform()
    AffineTransform getNodeToParentAffineTransform()
    Mat4 getNodeToParentTransform(Node* ancestor)
    AffineTransform getNodeToParentAffineTransform(Node* ancestor)
    void setNodeToParentTransform(const Mat4& transform)
    const Mat4& getParentToNodeTransform()
    AffineTransform getParentToNodeAffineTransform()
    Mat4 getNodeToWorldTransform()
    AffineTransform getNodeToWorldAffineTransform()
    Mat4 getWorldToNodeTransform()
    AffineTransform getWorldToNodeAffineTransform()
    Vec2 convertToNodeSpace(@pack const Vec2& worldPoint)
    Vec2 convertToWorldSpace(@pack const Vec2& nodePoint)
    Vec2 convertToNodeSpaceAR(@pack const Vec2& worldPoint)
    Vec2 convertToWorldSpaceAR(@pack const Vec2& nodePoint)
    Vec2 convertTouchToNodeSpace(Touch * touch)
    Vec2 convertTouchToNodeSpaceAR(Touch * touch)
    void setAdditionalTransform(const Mat4& additionalTransform)
    void setAdditionalTransform(const AffineTransform& additionalTransform)
    @ref(map components) Component* getComponent(const std::string& name)
    bool addComponent(@ref(map components) Component *component)
    @unref(cmp components) bool removeComponent(const std::string& name)
    @unref(cmp components) bool removeComponent(Component *component)
    @unref(all components) void removeAllComponents()
    GLubyte getOpacity()
    GLubyte getDisplayedOpacity()
    void setOpacity(GLubyte opacity)
    void updateDisplayedOpacity(GLubyte parentOpacity)
    bool isCascadeOpacityEnabled()
    void setCascadeOpacityEnabled(bool cascadeOpacityEnabled)
    const Color3B& getColor()
    const Color3B& getDisplayedColor()
    void setColor(const Color3B& color)
    void updateDisplayedColor(const Color3B& parentColor)
    bool isCascadeColorEnabled()
    void setCascadeColorEnabled(bool cascadeColorEnabled)
    void setOpacityModifyRGB(bool value)
    bool isOpacityModifyRGB()
    unsigned short getCameraMask()
    void setCameraMask(unsigned short mask, bool applyChildren = true)
    bool init()
    void setPhysicsBody(@ref(single physicsBody) PhysicsBody* physicsBody)
    @ref(single physicsBody) PhysicsBody* getPhysicsBody()
]]
cls.func('getBounds', [[{
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
cls.prop('x', 'float getPositionX()', 'void setPositionX(float x)')
cls.prop('y', 'float getPositionY()', 'void setPositionY(float y)')
cls.prop('z', 'float getPositionZ()', 'void setPositionZ(float z)')
cls.prop('anchorX', [[
{
    lua_settop(L, 1);
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getAnchorPoint().x);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Vec2 anchor = self->getAnchorPoint();
    anchor.x = olua_checknumber(L, 2);
    self->setAnchorPoint(anchor);
    return 0;
}]])
cls.prop('anchorY', [[
{
    lua_settop(L, 1);
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getAnchorPoint().y);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Vec2 anchor = self->getAnchorPoint();
    anchor.y = olua_checknumber(L, 2);
    self->setAnchorPoint(anchor);
    return 0;
}]])
cls.prop('width', [[
{
    lua_settop(L, 1);
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getContentSize().width);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Size size = self->getContentSize();
    size.width = olua_checknumber(L, 2);
    self->setContentSize(size);
    return 0;
}]])
cls.prop('height', [[
{
    lua_settop(L, 1);
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getContentSize().height);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Size size = self->getContentSize();
    size.height = olua_checknumber(L, 2);
    self->setContentSize(size);
    return 0;
}]])
cls.prop('alpha', [[
{
    lua_settop(L, 1);
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getOpacity() / 255.0f);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    self->setOpacity(olua_checknumber(L, 2) * 255.0f);
    return 0;
}]])
cls.callback {
    FUNCS =  {
        'void setOnEnterCallback(@nullable const std::function<void()>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onEnterCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'const std::function<void()>& getOnEnterCallback()',
    },
    TAG_MAKER = 'olua_makecallbacktag("onEnterCallback")',
    TAG_MODE = 'OLUA_TAG_EQUAL',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setOnExitCallback(@nullable const std::function<void()>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onExitCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'const std::function<void()>& getOnExitCallback()',
    },
    TAG_MAKER = 'olua_makecallbacktag("onExitCallback")',
    TAG_MODE = 'OLUA_TAG_EQUAL',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setOnEnterTransitionDidFinishCallback(@nullable const std::function<void()>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onEnterTransitionDidFinishCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'const std::function<void()>& getOnEnterTransitionDidFinishCallback()',
    },
    TAG_MAKER = 'olua_makecallbacktag("onEnterTransitionDidFinishCallback")',
    TAG_MODE = 'OLUA_TAG_EQUAL',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void setOnExitTransitionDidStartCallback(@nullable const std::function<void()>& callback)',
    },
    TAG_MAKER = 'olua_makecallbacktag("onExitTransitionDidStartCallback")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'const std::function<void()>& getOnExitTransitionDidStartCallback()',
    },
    TAG_MAKER = 'olua_makecallbacktag("onExitTransitionDidStartCallback")',
    TAG_MODE = 'OLUA_TAG_EQUAL',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void scheduleOnce(const std::function<void(float)>& callback, float delay, const std::string &key)',
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = true,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void schedule(const std::function<void(float)>& callback, const std::string &key)',
        'void schedule(const std::function<void(float)>& callback, float interval, const std::string &key)',
        'void schedule(const std::function<void(float)>& callback, float interval, unsigned int repeat, float delay, const std::string &key)',
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = false,
    REMOVE = false,
}
cls.callback {
    FUNCS =  {
        'void unschedule(const std::string &key)',
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_EQUAL',
    CALLONCE = false,
    REMOVE = true,
}
cls.callback {
    FUNCS =  {
        'void unscheduleAllCallbacks()',
    },
    TAG_MAKER = 'makeScheduleCallbackTag("")',
    TAG_MODE = 'OLUA_TAG_STARTWITH',
    CALLONCE = false,
    REMOVE = true,
}
cls.inject({'removeFromParent', 'removeFromParentAndCleanup'}, {
    BEFORE = [[
        if (!self->getParent()) {
            return 0;
        }
        olua_push_cppobj<cocos2d::Node>(L, self->getParent());
        int parent = lua_gettop(L);
    ]],
})
cls.props [[
    attachedNodeCount
    description
    localZOrder
    globalZOrder
    scaleX
    scaleY
    scaleZ
    scale
    position
    positionNormalized
    normalizedPosition
    positionX
    positionY
    position3D
    positionZ
    skewX
    skewY
    anchorPoint
    anchorPointInPoints
    contentSize
    visible
    rotation
    rotation3D
    rotationQuat
    rotationSkewX
    rotationSkewY
    ignoreAnchorPointForPosition
    children
    childrenCount
    parent
    tag
    name
    userData
    userObject
    glProgram
    glProgramState
    running
    scene
    boundingBox
    eventDispatcher
    actionManager
    numberOfRunningActions
    scheduler
    parentToNodeTransform
    parentToNodeAffineTransform
    nodeToWorldTransform
    nodeToWorldAffineTransform
    worldToNodeTransform
    worldToNodeAffineTransform
    opacity
    displayedOpacity
    cascadeOpacityEnabled
    color
    displayedColor
    cascadeColorEnabled
    opacityModifyRGB
    cameraMask
    physicsBody
    onEnterCallback
    onExitCallback
    onEnterTransitionDidFinishCallback
    onExitTransitionDidStartCallback
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AtlasNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static AtlasNode * create(const std::string& filename, int tileWidth, int tileHeight, int itemsToRender)
    void updateAtlasValues()
    void setTextureAtlas(TextureAtlas* textureAtlas)
    TextureAtlas* getTextureAtlas()
    void setQuadsToDraw(ssize_t quadsToDraw)
    ssize_t getQuadsToDraw()
    Texture2D* getTexture()
    void setTexture(Texture2D *texture)
    void setBlendFunc(const BlendFunc& blendFunc)
    const BlendFunc& getBlendFunc()
    bool initWithTileFile(const std::string& tile, int tileWidth, int tileHeight, int itemsToRender)
    bool initWithTexture(Texture2D* texture, int tileWidth, int tileHeight, int itemsToRender)
]]
cls.props [[
    textureAtlas
    quadsToDraw
    texture
    blendFunc
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProtectedNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static ProtectedNode * create(void)
    void addProtectedChild(@ref(map protectedChildren) Node * child)
    void addProtectedChild(@ref(map protectedChildren) Node * child, int localZOrder)
    void addProtectedChild(@ref(map protectedChildren) Node* child, int localZOrder, int tag)
    @ref(map protectedChildren) Node * getProtectedChildByTag(int tag)
    void removeProtectedChild(@unref(map protectedChildren) Node* child, bool cleanup = true)
    @unref(cmp protectedChildren) void removeProtectedChildByTag(int tag, bool cleanup = true)
    @unref(all protectedChildren) void removeAllProtectedChildren()
    @unref(all protectedChildren) void removeAllProtectedChildrenWithCleanup(bool cleanup)
    void reorderProtectedChild(Node * child, int localZOrder)
    void sortAllProtectedChildren()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::DrawNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static DrawNode* create(GLfloat defaultLineWidth = 2)
    void drawPoint(const Vec2& point, const float pointSize, const Color4F &color)
    void drawLine(const Vec2 &origin, const Vec2 &destination, const Color4F &color)
    void drawRect(const Vec2 &origin, const Vec2 &destination, const Color4F &color)
    void drawCircle( const Vec2& center, float radius, float angle, unsigned int segments, bool drawLineToCenter, float scaleX, float scaleY, const Color4F &color)
    void drawCircle(const Vec2 &center, float radius, float angle, unsigned int segments, bool drawLineToCenter, const Color4F &color)
    void drawQuadBezier(const Vec2 &origin, const Vec2 &control, const Vec2 &destination, unsigned int segments, const Color4F &color)
    void drawCubicBezier(const Vec2 &origin, const Vec2 &control1, const Vec2 &control2, const Vec2 &destination, unsigned int segments, const Color4F &color)
    void drawCardinalSpline(PointArray *config, float tension, unsigned int segments, const Color4F &color)
    void drawCatmullRom(PointArray *points, unsigned int segments, const Color4F &color)
    void drawDot(const Vec2 &pos, float radius, const Color4F &color)
    void drawRect(const Vec2 &p1, const Vec2 &p2, const Vec2 &p3, const Vec2& p4, const Color4F &color)
    void drawSolidRect(const Vec2 &origin, const Vec2 &destination, const Color4F &color)
    void drawSolidCircle(const Vec2& center, float radius, float angle, unsigned int segments, float scaleX, float scaleY, const Color4F &color)
    void drawSolidCircle(const Vec2& center, float radius, float angle, unsigned int segments, const Color4F& color)
    void drawSegment(const Vec2 &from, const Vec2 &to, float radius, const Color4F &color)
    void drawTriangle(const Vec2 &p1, const Vec2 &p2, const Vec2 &p3, const Color4F &color)
    void clear()
    const BlendFunc& getBlendFunc()
    void setBlendFunc(const BlendFunc &blendFunc)
    void onDraw(const Mat4 &transform, uint32_t flags)
    void onDrawGLLine(const Mat4 &transform, uint32_t flags)
    void onDrawGLPoint(const Mat4 &transform, uint32_t flags)
    void setLineWidth(GLfloat lineWidth)
    GLfloat getLineWidth()
    void setIsolated(bool isolated)
    bool isIsolated()
]]
cls.props [[
    blendFunc
    lineWidth
    isolated
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextHAlignment'
cls.enums [[
    LEFT
    CENTER
    RIGHT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextVAlignment'
cls.enums [[
    TOP
    CENTER
    BOTTOM
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GlyphCollection'
cls.enums [[
    DYNAMIC
    NEHE
    ASCII
    CUSTOM
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LabelEffect'
cls.enums [[
    NORMAL
    OUTLINE
    SHADOW
    GLOW
    ITALICS
    BOLD
    UNDERLINE
    STRIKETHROUGH
    ALL
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Label::LabelType'
cls.enums [[
    TTF
    BMFONT
    CHARMAP
    STRING_TEXTURE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Label::Overflow'
cls.enums [[
    NONE
    CLAMP
    SHRINK
    RESIZE_HEIGHT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Label'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static Label* create()
    static Label* createWithSystemFont(const std::string& text, const std::string& font, float fontSize, const Size& dimensions = Size::ZERO, TextHAlignment hAlignment = TextHAlignment::LEFT, TextVAlignment vAlignment = TextVAlignment::TOP)
    static Label * createWithTTF(const std::string& text, const std::string& fontFilePath, float fontSize, const Size& dimensions = Size::ZERO, TextHAlignment hAlignment = TextHAlignment::LEFT, TextVAlignment vAlignment = TextVAlignment::TOP)
    static Label* createWithTTF(const TTFConfig& ttfConfig, const std::string& text, TextHAlignment hAlignment = TextHAlignment::LEFT, int maxLineWidth = 0)
    static Label* createWithBMFont(const std::string& bmfontPath, const std::string& text, const TextHAlignment& hAlignment = TextHAlignment::LEFT, int maxLineWidth = 0, const Vec2& imageOffset = Vec2::ZERO)
    static Label * createWithCharMap(const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
    static Label * createWithCharMap(Texture2D* texture, int itemWidth, int itemHeight, int startCharMap)
    static Label * createWithCharMap(const std::string& plistFile)
    bool setTTFConfig(const TTFConfig& ttfConfig)
    const TTFConfig& getTTFConfig()
    bool setBMFontFilePath(const std::string& bmfontFilePath, const Vec2& imageOffset = Vec2::ZERO, float fontSize = 0)
    const std::string& getBMFontFilePath()
    bool setCharMap(const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
    bool setCharMap(Texture2D* texture, int itemWidth, int itemHeight, int startCharMap)
    bool setCharMap(const std::string& plistFile)
    void setSystemFontName(const std::string& font)
    const std::string& getSystemFontName()
    void setSystemFontSize(float fontSize)
    float getSystemFontSize()
    void requestSystemFontRefresh()
    void setString(const std::string& text)
    const std::string& getString()
    int getStringNumLines()
    int getStringLength()
    void setTextColor(const Color4B &color)
    const Color4B& getTextColor()
    void enableShadow(const Color4B& shadowColor = Color4B::BLACK,const Size &offset = Size(2,-2), int blurRadius = 0)
    void enableOutline(const Color4B& outlineColor,int outlineSize = -1)
    void enableGlow(const Color4B& glowColor)
    void enableItalics()
    void enableBold()
    void enableUnderline()
    void enableStrikethrough()
    void disableEffect()
    void disableEffect(LabelEffect effect)
    bool isShadowEnabled()
    Size getShadowOffset()
    float getShadowBlurRadius()
    Color4F getShadowColor()
    float getOutlineSize()
    LabelEffect getLabelEffectType()
    Color4F getEffectColor()
    void setAlignment(TextHAlignment hAlignment)
    TextHAlignment getTextAlignment()
    void setAlignment(TextHAlignment hAlignment,TextVAlignment vAlignment)
    void setHorizontalAlignment(TextHAlignment hAlignment)
    TextHAlignment getHorizontalAlignment()
    void setVerticalAlignment(TextVAlignment vAlignment)
    TextVAlignment getVerticalAlignment()
    void setLineBreakWithoutSpace(bool breakWithoutSpace)
    void setMaxLineWidth(float maxLineWidth)
    float getMaxLineWidth()
    void setBMFontSize(float fontSize)
    float getBMFontSize()
    void enableWrap(bool enable)
    bool isWrapEnabled()
    void setOverflow(Overflow overflow)
    Overflow getOverflow()
    void setWidth(float width)
    float getWidth()
    void setHeight(float height)
    float getHeight()
    void setDimensions(float width, float height)
    const Size& getDimensions()
    void updateContent()
    Sprite * getLetter(int lettetIndex)
    void setClipMarginEnabled(bool clipEnabled)
    bool isClipMarginEnabled()
    void setLineHeight(float height)
    float getLineHeight()
    void setLineSpacing(float height)
    float getLineSpacing()
    LabelType getLabelType()
    float getRenderingFontSize()
    void setAdditionalKerning(float space)
    float getAdditionalKerning()
    FontAtlas* getFontAtlas()
    const BlendFunc& getBlendFunc()
    void setBlendFunc(const BlendFunc &blendFunc)
    bool initWithTTF(const std::string& text, const std::string& fontFilePath, float fontSize, const Size& dimensions = Size::ZERO, TextHAlignment hAlignment = TextHAlignment::LEFT, TextVAlignment vAlignment = TextVAlignment::TOP)
    bool initWithTTF(const TTFConfig& ttfConfig, const std::string& text, TextHAlignment hAlignment = TextHAlignment::LEFT, int maxLineWidth = 0)
]]
cls.props [[
    ttfConfig
    bmFontFilePath
    systemFontName
    systemFontSize
    string
    stringNumLines
    stringLength
    textColor
    shadowEnabled
    shadowOffset
    shadowBlurRadius
    shadowColor
    outlineSize
    labelEffectType
    effectColor
    textAlignment
    horizontalAlignment
    verticalAlignment
    maxLineWidth
    bmFontSize
    wrapEnabled
    overflow
    width
    height
    dimensions
    clipMarginEnabled
    lineHeight
    lineSpacing
    labelType
    renderingFontSize
    additionalKerning
    fontAtlas
    blendFunc
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LabelAtlas'
cls.SUPERCLS = "cocos2d::AtlasNode"
cls.funcs [[
    static LabelAtlas* create()
    static LabelAtlas* create(const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
    static LabelAtlas* create(const std::string& string, const std::string& fntFile)
    bool initWithString(const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
    bool initWithString(const std::string& string, const std::string& fntFile)
    bool initWithString(const std::string& string, Texture2D* texture, int itemWidth, int itemHeight, int startCharMap)
    void setString(const std::string &label)
    const std::string& getString(void)
]]
cls.props [[
    string
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FontAtlas'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    void addTexture(Texture2D *texture, int slot)
    float getLineHeight()
    void setLineHeight(float newHeight)
    std::string getFontName()
    Texture2D* getTexture(int slot)
    void listenRendererRecreated(EventCustom *event)
    void purgeTexturesAtlas()
    void setAntiAliasTexParameters()
    void setAliasTexParameters()
]]
cls.props [[
    lineHeight
    fontName
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ClippingRectangleNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static ClippingRectangleNode* create(const Rect& clippingRegion)
    static ClippingRectangleNode* create()
    const Rect& getClippingRegion()
    void setClippingRegion(const Rect& clippingRegion)
    bool isClippingEnabled()
    void setClippingEnabled(bool enabled)
]]
cls.props [[
    clippingRegion
    clippingEnabled
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RenderTexture'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static RenderTexture * create(int w ,int h, Texture2D::PixelFormat format, GLuint depthStencilFormat)
    static RenderTexture * create(int w, int h, Texture2D::PixelFormat format)
    static RenderTexture * create(int w, int h)
    void begin()
    void beginWithClear(float r, float g, float b, float a)
    void beginWithClear(float r, float g, float b, float a, float depthValue)
    void beginWithClear(float r, float g, float b, float a, float depthValue, int stencilValue)
    void end()
    void clear(float r, float g, float b, float a)
    void clearDepth(float depthValue)
    void clearStencil(int stencilValue)
    Image* newImage(bool flipImage = true)
    void listenToBackground(EventCustom *event)
    void listenToForeground(EventCustom *event)
    unsigned int getClearFlags()
    void setClearFlags(unsigned int clearFlags)
    const Color4F& getClearColor()
    void setClearColor(const Color4F &clearColor)
    float getClearDepth()
    void setClearDepth(float clearDepth)
    int getClearStencil()
    void setClearStencil(int clearStencil)
    bool isAutoDraw()
    void setAutoDraw(bool isAutoDraw)
    Sprite* getSprite()
    void setSprite(Sprite* sprite)
    void setKeepMatrix(bool keepMatrix)
    void setVirtualViewport(const Vec2& rtBegin, const Rect& fullRect, const Rect& fullViewport)
    bool initWithWidthAndHeight(int w, int h, Texture2D::PixelFormat format)
    bool initWithWidthAndHeight(int w, int h, Texture2D::PixelFormat format, GLuint depthStencilFormat)
]]
cls.callback {
    FUNCS =  {
        'bool saveToFile(const std::string& filename, bool isRGBA = true, std::function<void (RenderTexture*, const std::string&)> callback = nullptr)',
        'bool saveToFile(const std::string& filename, Image::Format format, bool isRGBA = true, std::function<void (RenderTexture*, const std::string&)> callback = nullptr)',
    },
    TAG_MAKER = 'olua_makecallbacktag("saveToFile")',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    CALLONCE = true,
    REMOVE = false,
}
cls.props [[
    clearFlags
    clearColor
    clearDepth
    clearStencil
    autoDraw
    sprite
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProgressTimer::Type'
cls.enums [[
    RADIAL
    BAR
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProgressTimer'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static ProgressTimer* create(Sprite* sp)
    Type getType()
    float getPercentage()
    Sprite* getSprite()
    void setPercentage(float percentage)
    void setSprite(Sprite *sprite)
    void setType(Type type)
    bool isReverseDirection()
    void setReverseDirection(bool value)
    void setMidpoint(const Vec2& point)
    Vec2 getMidpoint()
    void setBarChangeRate(const Vec2& barChangeRate )
    Vec2 getBarChangeRate()
    bool initWithSprite(Sprite* sp)
]]
cls.props [[
    type
    percentage
    sprite
    reverseDirection
    midpoint
    barChangeRate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AnimationFrame'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static AnimationFrame* create(SpriteFrame* spriteFrame, float delayUnits, const ValueMap& userInfo)
    SpriteFrame* getSpriteFrame()
    void setSpriteFrame(SpriteFrame* frame)
    float getDelayUnits()
    void setDelayUnits(float delayUnits)
    const ValueMap& getUserInfo()
    void setUserInfo(const ValueMap& userInfo)
    AnimationFrame *clone()
    bool initWithSpriteFrame(SpriteFrame* spriteFrame, float delayUnits, const ValueMap& userInfo)
]]
cls.props [[
    spriteFrame
    delayUnits
    userInfo
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Animation'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static Animation* create(void)
    static Animation* createWithSpriteFrames(const Vector<SpriteFrame*>& arrayOfSpriteFrameNames, float delay = 0.0f, unsigned int loops = 1)
    static Animation* create(const Vector<AnimationFrame*>& arrayOfAnimationFrameNames, float delayPerUnit, unsigned int loops = 1)
    void addSpriteFrame(SpriteFrame *frame)
    void addSpriteFrameWithFile(const std::string& filename)
    void addSpriteFrameWithTexture(Texture2D* pobTexture, const Rect& rect)
    float getTotalDelayUnits()
    void setDelayPerUnit(float delayPerUnit)
    float getDelayPerUnit()
    float getDuration()
    const Vector<AnimationFrame*>& getFrames()
    void setFrames(const Vector<AnimationFrame*>& frames)
    bool getRestoreOriginalFrame()
    void setRestoreOriginalFrame(bool restoreOriginalFrame)
    unsigned int getLoops()
    void setLoops(unsigned int loops)
    Animation *clone()
    bool init()
    bool initWithSpriteFrames(const Vector<SpriteFrame*>& arrayOfSpriteFrameNames, float delay = 0.0f, unsigned int loops = 1)
    bool initWithAnimationFrames(const Vector<AnimationFrame*>& arrayOfAnimationFrameNames, float delayPerUnit, unsigned int loops)
]]
cls.props [[
    totalDelayUnits
    delayPerUnit
    duration
    frames
    restoreOriginalFrame
    loops
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SpriteFrame'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static SpriteFrame* create(const std::string& filename, const Rect& rect)
    static SpriteFrame* create(const std::string& filename, const Rect& rect, bool rotated, const Vec2& offset, const Size& originalSize)
    static SpriteFrame* createWithTexture(Texture2D* pobTexture, const Rect& rect)
    static SpriteFrame* createWithTexture(Texture2D* pobTexture, const Rect& rect, bool rotated, const Vec2& offset, const Size& originalSize)
    const Rect& getRectInPixels()
    void setRectInPixels(const Rect& rectInPixels)
    bool isRotated()
    void setRotated(bool rotated)
    const Rect& getRect()
    void setRect(const Rect& rect)
    const Rect& getCenterRect()
    void setCenterRectInPixels(const Rect& centerRect)
    bool hasCenterRect()
    const Vec2& getOffsetInPixels()
    void setOffsetInPixels(const Vec2& offsetInPixels)
    const Size& getOriginalSizeInPixels()
    void setOriginalSizeInPixels(const Size& sizeInPixels)
    const Size& getOriginalSize()
    void setOriginalSize(const Size& sizeInPixels)
    Texture2D* getTexture()
    void setTexture(Texture2D* pobTexture)
    const Vec2& getOffset()
    void setOffset(const Vec2& offsets)
    const Vec2& getAnchorPoint()
    void setAnchorPoint(const Vec2& anchorPoint)
    bool hasAnchorPoint()
    SpriteFrame *clone()
    bool hasPolygonInfo()
    bool initWithTexture(Texture2D* pobTexture, const Rect& rect)
    bool initWithTextureFilename(const std::string& filename, const Rect& rect)
    bool initWithTexture(Texture2D* pobTexture, const Rect& rect, bool rotated, const Vec2& offset, const Size& originalSize)
    bool initWithTextureFilename(const std::string& filename, const Rect& rect, bool rotated, const Vec2& offset, const Size& originalSize)
]]
cls.props [[
    rectInPixels
    rotated
    rect
    centerRect
    offsetInPixels
    originalSizeInPixels
    originalSize
    texture
    offset
    anchorPoint
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Sprite'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static Sprite* create()
    static Sprite* create(const std::string& filename)
    static Sprite* create(const std::string& filename, const Rect& rect)
    static Sprite* createWithTexture(Texture2D *texture)
    static Sprite* createWithTexture(Texture2D *texture, const Rect& rect, bool rotated=false)
    static Sprite* createWithSpriteFrame(SpriteFrame *spriteFrame)
    static Sprite* createWithSpriteFrameName(const std::string& spriteFrameName)
    SpriteBatchNode* getBatchNode()
    void setBatchNode(SpriteBatchNode *spriteBatchNode)
    void setTexture(const std::string &filename )
    void setTexture(Texture2D *texture)
    Texture2D* getTexture()
    void setTextureRect(const Rect& rect)
    void setTextureRect(const Rect& rect, bool rotated, const Size& untrimmedSize)
    void setVertexRect(const Rect& rect)
    void setCenterRectNormalized(const Rect& rect)
    Rect getCenterRectNormalized()
    void setCenterRect(const Rect& rect)
    Rect getCenterRect()
    void setSpriteFrame(const std::string &spriteFrameName)
    void setSpriteFrame(SpriteFrame* newFrame)
    bool isFrameDisplayed(SpriteFrame *frame)
    SpriteFrame* getSpriteFrame()
    void setDisplayFrameWithAnimationName(const std::string& animationName, ssize_t frameIndex)
    bool isDirty()
    void setDirty(bool dirty)
    bool isTextureRectRotated()
    ssize_t getAtlasIndex()
    void setAtlasIndex(ssize_t atlasIndex)
    const Rect& getTextureRect()
    TextureAtlas* getTextureAtlas()
    void setTextureAtlas(TextureAtlas *textureAtlas)
    const Vec2& getOffsetPosition()
    bool isFlippedX()
    void setFlippedX(bool flippedX)
    bool isFlippedY()
    void setFlippedY(bool flippedY)
    void setStretchEnabled(bool enabled)
    bool isStretchEnabled()
    void setBlendFunc(const BlendFunc &blendFunc)
    const BlendFunc& getBlendFunc()
    int getResourceType()
    const std::string& getResourceName()
    bool initWithTexture(Texture2D *texture)
    bool initWithTexture(Texture2D *texture, const Rect& rect)
    bool initWithTexture(Texture2D *texture, const Rect& rect, bool rotated)
    bool initWithSpriteFrame(SpriteFrame *spriteFrame)
    bool initWithSpriteFrameName(const std::string& spriteFrameName)
    bool initWithFile(const std::string& filename)
    bool initWithFile(const std::string& filename, const Rect& rect)
]]
cls.props [[
    batchNode
    texture
    centerRectNormalized
    centerRect
    spriteFrame
    dirty
    textureRectRotated
    atlasIndex
    textureRect
    textureAtlas
    offsetPosition
    flippedX
    flippedY
    stretchEnabled
    blendFunc
    resourceType
    resourceName
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SpriteBatchNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static SpriteBatchNode* createWithTexture(Texture2D* tex, ssize_t capacity = 29)
    static SpriteBatchNode* create(const std::string& fileImage, ssize_t capacity = 29)
    TextureAtlas* getTextureAtlas()
    void setTextureAtlas(TextureAtlas* textureAtlas)
    const std::vector<Sprite*>& getDescendants()
    void increaseAtlasCapacity()
    void removeChildAtIndex(ssize_t index, bool doCleanup)
    void appendChild(Sprite* sprite)
    void removeSpriteFromAtlas(Sprite *sprite)
    ssize_t rebuildIndexInOrder(Sprite *parent, ssize_t index)
    ssize_t highestAtlasIndexInChild(Sprite *sprite)
    ssize_t lowestAtlasIndexInChild(Sprite *sprite)
    ssize_t atlasIndexForChild(Sprite *sprite, int z)
    void reorderBatch(bool reorder)
    Texture2D* getTexture()
    void setTexture(Texture2D *texture)
    void setBlendFunc(const BlendFunc &blendFunc)
    const BlendFunc& getBlendFunc()
    void insertQuadFromSprite(Sprite *sprite, ssize_t index)
    SpriteBatchNode * addSpriteWithoutQuad(Sprite *child, int z, int aTag)
    void reserveCapacity(ssize_t newCapacity)
    bool initWithTexture(Texture2D *tex, ssize_t capacity = 29)
    bool initWithFile(const std::string& fileImage, ssize_t capacity = 29)
]]
cls.props [[
    textureAtlas
    descendants
    texture
    blendFunc
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SpriteFrameCache'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static SpriteFrameCache* getInstance()
    static void destroyInstance()
    bool init()
    void addSpriteFramesWithFile(const std::string& plist)
    void addSpriteFramesWithFile(const std::string& plist, const std::string& textureFileName)
    void addSpriteFramesWithFile(const std::string&plist, Texture2D *texture)
    void addSpriteFramesWithFileContent(const std::string& plist_content, Texture2D *texture)
    void addSpriteFrame(SpriteFrame *frame, const std::string& frameName)
    bool isSpriteFramesWithFileLoaded(const std::string& plist)
    void removeSpriteFrames()
    void removeUnusedSpriteFrames()
    void removeSpriteFrameByName(const std::string& name)
    void removeSpriteFramesFromFile(const std::string& plist)
    void removeSpriteFramesFromFileContent(const std::string& plist_content)
    void removeSpriteFramesFromTexture(Texture2D* texture)
    SpriteFrame* getSpriteFrameByName(const std::string& name)
    bool reloadTexture(const std::string& plist)
]]
cls.props [[
    instance
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AnimationCache'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static AnimationCache* getInstance()
    static void destroyInstance()
    bool init(void)
    void addAnimation(Animation *animation, const std::string& name)
    void removeAnimation(const std::string& name)
    Animation* getAnimation(const std::string& name)
    void addAnimationsWithDictionary(const ValueMap& dictionary,const std::string& plist)
    void addAnimationsWithFile(const std::string& plist)
]]
cls.props [[
    instance
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Scene'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static Scene *create()
    static Scene *createWithSize(const Size& size)
    const std::vector<Camera*>& getCameras()
    Camera* getDefaultCamera()
    const std::vector<BaseLight*>& getLights()
    bool initWithSize(const Size& size)
    void setCameraOrderDirty()
    void onProjectionChanged(EventCustom* event)
    @ref(single physicsWorld) PhysicsWorld* getPhysicsWorld()
    void setPhysics3DDebugCamera(Camera* camera)
    static Scene *createWithPhysics()
    bool initWithPhysics()
    void setNavMeshDebugCamera(Camera *camera)
    void stepPhysicsAndNavigation(float deltaTime)
]]
cls.props [[
    cameras
    defaultCamera
    lights
    physicsWorld
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Layer'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static Layer *create()
    bool onTouchBegan(Touch *touch, Event *unused_event)
    void onTouchMoved(Touch *touch, Event *unused_event)
    void onTouchEnded(Touch *touch, Event *unused_event)
    void onTouchCancelled(Touch *touch, Event *unused_event)
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
    void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
    void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
    void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
    void onAcceleration(Acceleration* acc, Event* unused_event)
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LayerColor'
cls.SUPERCLS = "cocos2d::Layer"
cls.funcs [[
    static LayerColor* create()
    static LayerColor * create(const Color4B& color, GLfloat width, GLfloat height)
    static LayerColor * create(const Color4B& color)
    void changeWidth(GLfloat w)
    void changeHeight(GLfloat h)
    void changeWidthAndHeight(GLfloat w ,GLfloat h)
    const BlendFunc& getBlendFunc()
    void setBlendFunc(const BlendFunc& blendFunc)
    bool initWithColor(const Color4B& color, GLfloat width, GLfloat height)
    bool initWithColor(const Color4B& color)
]]
cls.props [[
    blendFunc
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LayerGradient'
cls.SUPERCLS = "cocos2d::LayerColor"
cls.funcs [[
    static LayerGradient* create()
    static LayerGradient* create(const Color4B& start, const Color4B& end)
    static LayerGradient* create(const Color4B& start, const Color4B& end, const Vec2& v)
    void setCompressedInterpolation(bool compressedInterpolation)
    bool isCompressedInterpolation()
    void setStartColor( const Color3B& startColor )
    const Color3B& getStartColor()
    void setEndColor( const Color3B& endColor )
    const Color3B& getEndColor()
    void setStartOpacity( GLubyte startOpacity )
    GLubyte getStartOpacity()
    void setEndOpacity( GLubyte endOpacity )
    GLubyte getEndOpacity()
    void setVector(const Vec2& alongVector)
    const Vec2& getVector()
    bool initWithColor(const Color4B& start, const Color4B& end)
    bool initWithColor(const Color4B& start, const Color4B& end, const Vec2& v)
]]
cls.props [[
    compressedInterpolation
    startColor
    endColor
    startOpacity
    endOpacity
    vector
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LayerRadialGradient'
cls.SUPERCLS = "cocos2d::Layer"
cls.funcs [[
    static LayerRadialGradient* create(const Color4B& startColor, const Color4B& endColor, float radius, const Vec2& center, float expand)
    static LayerRadialGradient* create()
    void setStartOpacity(GLubyte opacity)
    GLubyte getStartOpacity()
    void setEndOpacity(GLubyte opacity)
    GLubyte getEndOpacity()
    void setRadius(float radius)
    float getRadius()
    void setCenter(const Vec2& center)
    Vec2 getCenter()
    void setExpand(float expand)
    float getExpand()
    void setStartColor(const Color3B& color)
    void setStartColor(const Color4B& color)
    Color4B getStartColor()
    Color3B getStartColor3B()
    void setEndColor(const Color3B& color)
    void setEndColor(const Color4B& color)
    Color4B getEndColor()
    Color3B getEndColor3B()
    void setBlendFunc(const BlendFunc& blendFunc)
    BlendFunc getBlendFunc()
    bool initWithColor(const Color4B& startColor, const Color4B& endColor, float radius, const Vec2& center, float expand)
]]
cls.props [[
    startOpacity
    endOpacity
    radius
    center
    expand
    startColor
    startColor3B
    endColor
    endColor3B
    blendFunc
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionScene::Orientation'
cls.enums [[
    LEFT_OVER
    RIGHT_OVER
    UP_OVER
    DOWN_OVER
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionScene'
cls.SUPERCLS = "cocos2d::Scene"
cls.funcs [[
    static TransitionScene * create(float t, @ref(map autoref) Scene *scene)
    void finish(void)
    void hideOutShowIn(void)
    Scene* getInScene()
    float getDuration()
]]
cls.props [[
    inScene
    duration
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSceneOriented'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionSceneOriented * create(float t, @ref(map autoref) Scene* scene, TransitionScene::Orientation orientation)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionRotoZoom'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionRotoZoom* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionJumpZoom'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionJumpZoom* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInL'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionMoveInL* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval* action(void)
    ActionInterval* easeActionWithAction(@ref(single action) ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInR'
cls.SUPERCLS = "cocos2d::TransitionMoveInL"
cls.funcs [[
    static TransitionMoveInR* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInT'
cls.SUPERCLS = "cocos2d::TransitionMoveInL"
cls.funcs [[
    static TransitionMoveInT* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInB'
cls.SUPERCLS = "cocos2d::TransitionMoveInL"
cls.funcs [[
    static TransitionMoveInB* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInL'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionSlideInL* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval* easeActionWithAction(@ref(single action) ActionInterval * action)
    ActionInterval* action(void)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInR'
cls.SUPERCLS = "cocos2d::TransitionSlideInL"
cls.funcs [[
    static TransitionSlideInR* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInB'
cls.SUPERCLS = "cocos2d::TransitionSlideInL"
cls.funcs [[
    static TransitionSlideInB* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInT'
cls.SUPERCLS = "cocos2d::TransitionSlideInL"
cls.funcs [[
    static TransitionSlideInT* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionShrinkGrow'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionShrinkGrow* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval* easeActionWithAction(@ref(single action) ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFlipX'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static TransitionFlipX* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionFlipX* create(float t, @ref(map autoref) Scene* s)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFlipY'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static TransitionFlipY* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionFlipY* create(float t, @ref(map autoref) Scene* s)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFlipAngular'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static TransitionFlipAngular* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionFlipAngular* create(float t, @ref(map autoref) Scene* s)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionZoomFlipX'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static TransitionZoomFlipX* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionZoomFlipX* create(float t, @ref(map autoref) Scene* s)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionZoomFlipY'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static TransitionZoomFlipY* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionZoomFlipY* create(float t, @ref(map autoref) Scene* s)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionZoomFlipAngular'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static TransitionZoomFlipAngular* create(float t, @ref(map autoref) Scene* s, TransitionScene::Orientation o)
    static TransitionZoomFlipAngular* create(float t, @ref(map autoref) Scene* s)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFade'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionFade* create(float duration, @ref(map autoref) Scene* scene, const Color3B& color)
    static TransitionFade* create(float duration, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionCrossFade'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionCrossFade* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionTurnOffTiles'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionTurnOffTiles* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval * easeActionWithAction(@ref(single action) ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSplitCols'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionSplitCols* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval* action()
    ActionInterval * easeActionWithAction(@ref(single action) ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSplitRows'
cls.SUPERCLS = "cocos2d::TransitionSplitCols"
cls.funcs [[
    static TransitionSplitRows* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeTR'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionFadeTR* create(float t, @ref(map autoref) Scene* scene)
    ActionInterval* actionWithSize(const Size& size)
    ActionInterval* easeActionWithAction(@ref(single action) ActionInterval * action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeBL'
cls.SUPERCLS = "cocos2d::TransitionFadeTR"
cls.funcs [[
    static TransitionFadeBL* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeUp'
cls.SUPERCLS = "cocos2d::TransitionFadeTR"
cls.funcs [[
    static TransitionFadeUp* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeDown'
cls.SUPERCLS = "cocos2d::TransitionFadeTR"
cls.funcs [[
    static TransitionFadeDown* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionPageTurn'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionPageTurn* create(float t, @ref(map autoref) Scene* scene, bool backwards)
    ActionInterval* actionWithSize(const Size& vector)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgress'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static TransitionProgress* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressRadialCCW'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static TransitionProgressRadialCCW* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressRadialCW'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static TransitionProgressRadialCW* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressHorizontal'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static TransitionProgressHorizontal* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressVertical'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static TransitionProgressVertical* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressInOut'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static TransitionProgressInOut* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressOutIn'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static TransitionProgressOutIn* create(float t, @ref(map autoref) Scene* scene)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextFieldDelegate'
cls.funcs [[
    bool onTextFieldAttachWithIME(TextFieldTTF* sender)
    bool onTextFieldDetachWithIME(TextFieldTTF* sender)
    bool onTextFieldInsertText(TextFieldTTF* sender, const char* text, size_t nLen)
    bool onTextFieldDeleteBackward(TextFieldTTF* sender, const char* delText, size_t nLen)
    bool onVisit(TextFieldTTF* sender, Renderer* renderer, const Mat4& transform, uint32_t flags)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextFieldTTF'
cls.SUPERCLS = "cocos2d::Label"
cls.funcs [[
    static TextFieldTTF * textFieldWithPlaceHolder(const std::string& placeholder, const Size& dimensions, TextHAlignment alignment, const std::string& fontName, float fontSize)
    static TextFieldTTF * textFieldWithPlaceHolder(const std::string& placeholder, const std::string& fontName, float fontSize)
    bool initWithPlaceHolder(const std::string& placeholder, const Size& dimensions, TextHAlignment alignment, const std::string& fontName, float fontSize)
    bool initWithPlaceHolder(const std::string& placeholder, const std::string& fontName, float fontSize)
    bool attachWithIME()
    bool detachWithIME()
    TextFieldDelegate* getDelegate()
    void setDelegate(TextFieldDelegate* delegate)
    std::size_t getCharCount()
    const Color4B& getColorSpaceHolder()
    void setColorSpaceHolder(const Color3B& color)
    void setColorSpaceHolder(const Color4B& color)
    void appendString(const std::string& text)
    void setPlaceHolder(const std::string& text)
    const std::string& getPlaceHolder()
    void setSecureTextEntry(bool value)
    void setPasswordTextStyle(const std::string& text)
    const std::string& getPasswordTextStyle()
    bool isSecureTextEntry()
    void setCursorEnabled(bool enabled)
    void setCursorChar(char cursor)
    void setCursorPosition(std::size_t cursorPosition)
    void setCursorFromPoint(const Vec2 &point, const Camera* camera)
]]
cls.props [[
    delegate
    charCount
    colorSpaceHolder
    placeHolder
    passwordTextStyle
    secureTextEntry
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LightType'
cls.enums [[
    DIRECTIONAL
    POINT
    SPOT
    AMBIENT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LightFlag'
cls.enums [[
    LIGHT0
    LIGHT1
    LIGHT2
    LIGHT3
    LIGHT4
    LIGHT5
    LIGHT6
    LIGHT7
    LIGHT8
    LIGHT9
    LIGHT10
    LIGHT11
    LIGHT12
    LIGHT13
    LIGHT14
    LIGHT15
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BaseLight'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    LightType getLightType()
    float getIntensity()
    void setIntensity(float intensity)
    LightFlag getLightFlag()
    void setLightFlag(LightFlag flag)
    void setEnabled(bool enabled)
    bool isEnabled()
]]
cls.props [[
    lightType
    intensity
    lightFlag
    enabled
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::DirectionLight'
cls.SUPERCLS = "cocos2d::BaseLight"
cls.funcs [[
    static DirectionLight* create(const Vec3 &direction, const Color3B &color)
    void setDirection(const Vec3 &dir)
    Vec3 getDirection()
    Vec3 getDirectionInWorld()
]]
cls.props [[
    direction
    directionInWorld
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PointLight'
cls.SUPERCLS = "cocos2d::BaseLight"
cls.funcs [[
    static PointLight* create(const Vec3 &position, const Color3B &color, float range)
    float getRange()
    void setRange(float range)
]]
cls.props [[
    range
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SpotLight'
cls.SUPERCLS = "cocos2d::BaseLight"
cls.funcs [[
    static SpotLight* create(const Vec3 &direction, const Vec3 &position, const Color3B &color, float innerAngle, float outerAngle, float range)
    void setDirection(const Vec3 &dir)
    Vec3 getDirection()
    Vec3 getDirectionInWorld()
    void setRange(float range)
    float getRange()
    void setInnerAngle(float angle)
    float getInnerAngle()
    float getCosInnerAngle()
    void setOuterAngle(float outerAngle)
    float getOuterAngle()
    float getCosOuterAngle()
]]
cls.props [[
    direction
    directionInWorld
    range
    innerAngle
    cosInnerAngle
    outerAngle
    cosOuterAngle
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AmbientLight'
cls.SUPERCLS = "cocos2d::BaseLight"
cls.funcs [[
    static AmbientLight* create(const Color3B &color)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraFlag'
cls.enums [[
    DEFAULT
    USER1
    USER2
    USER3
    USER4
    USER5
    USER6
    USER7
    USER8
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Camera::Type'
cls.enums [[
    PERSPECTIVE
    ORTHOGRAPHIC
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Camera'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static Camera* createPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
    static Camera* createOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)
    static Camera* create()
    static const Camera* getVisitingCamera()
    static const experimental::Viewport& getDefaultViewport()
    static void setDefaultViewport(const experimental::Viewport& vp)
    static Camera* getDefaultCamera()
    Camera::Type getType()
    CameraFlag getCameraFlag()
    void setCameraFlag(CameraFlag flag)
    void lookAt(const Vec3& target, const Vec3& up = Vec3::UNIT_Y)
    const Mat4& getProjectionMatrix()
    const Mat4& getViewMatrix()
    const Mat4& getViewProjectionMatrix()
    Vec2 project(const Vec3& src)
    Vec2 projectGL(const Vec3& src)
    Vec3 unproject(const Vec3& src)
    Vec3 unprojectGL(const Vec3& src)
    float getDepthInView(const Mat4& transform)
    void setDepth(int8_t depth)
    int8_t getDepth()
    int getRenderOrder()
    float getFarPlane()
    float getNearPlane()
    void clearBackground()
    void apply()
    void restore()
    void setViewport(const experimental::Viewport& vp)
    bool isViewProjectionUpdated()
    void setBackgroundBrush(CameraBackgroundBrush* clearBrush)
    CameraBackgroundBrush* getBackgroundBrush()
    bool isBrushValid()
    void setScene(Scene* scene)
    void setAdditionalProjection(const Mat4& mat)
    bool initDefault()
    bool initPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
    bool initOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)
    void applyFrameBufferObject()
    void applyViewport()
    void restoreFrameBufferObject()
    void restoreViewport()
]]
cls.props [[
    visitingCamera
    defaultViewport
    defaultCamera
    type
    cameraFlag
    projectionMatrix
    viewMatrix
    viewProjectionMatrix
    depth
    renderOrder
    farPlane
    nearPlane
    viewProjectionUpdated
    backgroundBrush
    brushValid
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundBrush::BrushType'
cls.enums [[
    NONE
    DEPTH
    COLOR
    SKYBOX
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundBrush'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    BrushType getBrushType()
    static CameraBackgroundBrush* createNoneBrush()
    static CameraBackgroundDepthBrush* createDepthBrush(float depth = 1.f)
    static CameraBackgroundColorBrush* createColorBrush(const Color4F& color, float depth)
    static CameraBackgroundSkyBoxBrush* createSkyboxBrush(const std::string& positive_x, const std::string& negative_x, const std::string& positive_y, const std::string& negative_y, const std::string& positive_z, const std::string& negative_z)
    void drawBackground(Camera* )
    bool isValid()
    bool init()
]]
cls.props [[
    brushType
    valid
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundDepthBrush'
cls.SUPERCLS = "cocos2d::CameraBackgroundBrush"
cls.funcs [[
    static CameraBackgroundDepthBrush* create(float depth)
    void setDepth(float depth)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundColorBrush'
cls.SUPERCLS = "cocos2d::CameraBackgroundDepthBrush"
cls.funcs [[
    static CameraBackgroundColorBrush* create(const Color4F& color, float depth)
    void setColor(const Color4F& color)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundSkyBoxBrush'
cls.SUPERCLS = "cocos2d::CameraBackgroundBrush"
cls.funcs [[
    static CameraBackgroundSkyBoxBrush* create(const std::string& positive_x, const std::string& negative_x, const std::string& positive_y, const std::string& negative_y, const std::string& positive_z, const std::string& negative_z)
    static CameraBackgroundSkyBoxBrush* create()
    void setTexture(TextureCube* texture)
    bool isActived()
    void setActived(bool actived)
    void setTextureValid(bool valid)
]]
cls.props [[
    actived
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionCamera'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    void setEye(const Vec3 &eye)
    void setEye(float x, float y, float z)
    const Vec3& getEye()
    void setCenter(const Vec3 &center)
    const Vec3& getCenter()
    void setUp(const Vec3 &up)
    const Vec3& getUp()
]]
cls.props [[
    eye
    center
    up
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::OrbitCamera'
cls.SUPERCLS = "cocos2d::ActionCamera"
cls.funcs [[
    static OrbitCamera* create(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GridBase'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static GridBase* create(const Size& gridSize, Texture2D *texture, bool flipped)
    static GridBase* create(const Size& gridSize)
    bool initWithSize(const Size& gridSize)
    bool initWithSize(const Size& gridSize, const Rect& rect)
    bool initWithSize(const Size& gridSize, Texture2D *texture, bool flipped)
    bool initWithSize(const Size& gridSize, Texture2D *texture, bool flipped, const Rect& rect)
    bool isActive()
    void setActive(bool active)
    int getReuseGrid()
    void setReuseGrid(int reuseGrid)
    const Size& getGridSize()
    void setGridSize(const Size& gridSize)
    const Vec2& getStep()
    void setStep(const Vec2& step)
    bool isTextureFlipped()
    void setTextureFlipped(bool flipped)
    void beforeDraw(void)
    void afterDraw(Node *target)
    void beforeBlit()
    void afterBlit()
    void blit(void)
    void reuse(void)
    void calculateVertexPoints(void)
    void set2DProjection(void)
    void setGridRect(const Rect& rect)
    const Rect& getGridRect()
]]
cls.props [[
    active
    reuseGrid
    gridSize
    step
    textureFlipped
    gridRect
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Grid3D'
cls.SUPERCLS = "cocos2d::GridBase"
cls.funcs [[
    static Grid3D* create(const Size& gridSize)
    static Grid3D* create(const Size& gridSize, const Rect& rect)
    static Grid3D* create(const Size& gridSize, Texture2D *texture, bool flipped)
    static Grid3D* create(const Size& gridSize, Texture2D *texture, bool flipped, const Rect& rect)
    Vec3 getVertex(const Vec2& pos)
    Vec3 getOriginalVertex(const Vec2& pos)
    void setVertex(const Vec2& pos, const Vec3& vertex)
    void setNeedDepthTestForBlit( bool neededDepthTest)
    bool getNeedDepthTestForBlit()
]]
cls.props [[
    needDepthTestForBlit
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TiledGrid3D'
cls.SUPERCLS = "cocos2d::GridBase"
cls.funcs [[
    static TiledGrid3D* create(const Size& gridSize)
    static TiledGrid3D* create(const Size& gridSize, const Rect& rect)
    static TiledGrid3D* create(const Size& gridSize, Texture2D *texture, bool flipped)
    static TiledGrid3D* create(const Size& gridSize, Texture2D *texture, bool flipped, const Rect& rect)
    Quad3 getTile(const Vec2& pos)
    Quad3 getOriginalTile(const Vec2& pos)
    void setTile(const Vec2& pos, const Quad3& coords)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NodeGrid'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static NodeGrid* create()
    static NodeGrid* create(const Rect& rect)
    GridBase* getGrid()
    void setGrid(GridBase *grid)
    void setTarget(Node *target)
    void setGridRect(const Rect& gridRect)
    const Rect& getGridRect()
]]
cls.props [[
    grid
    gridRect
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GridAction'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    GridBase* getGrid()
]]
cls.props [[
    grid
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Grid3DAction'
cls.SUPERCLS = "cocos2d::GridAction"
cls.funcs [[
    Vec3 getVertex(const Vec2& position)
    Vec3 getOriginalVertex(const Vec2& position)
    void setVertex(const Vec2& position, const Vec3& vertex)
    Rect getGridRect()
]]
cls.props [[
    gridRect
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TiledGrid3DAction'
cls.SUPERCLS = "cocos2d::GridAction"
cls.CHUNK = [[
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
cls.funcs [[
    static TiledGrid3DAction* create(float duration, const Size& gridSize)
    Quad3 getTile(const Vec2& position)
    Quad3 getOriginalTile(const Vec2& position)
    void setTile(const Vec2& position, const Quad3& coords)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AccelDeccelAmplitude'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static AccelDeccelAmplitude* create(Action *action, float duration)
    float getRate()
    void setRate(float rate)
]]
cls.props [[
    rate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AccelAmplitude'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static AccelAmplitude* create(Action *action, float duration)
    float getRate()
    void setRate(float rate)
]]
cls.props [[
    rate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::DeccelAmplitude'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static DeccelAmplitude* create(Action *action, float duration)
    float getRate()
    void setRate(float rate)
]]
cls.props [[
    rate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::StopGrid'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static StopGrid* create()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ReuseGrid'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static ReuseGrid* create(int times)
    bool initWithTimes(int times)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Waves3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static Waves3D* create(float duration, const Size& gridSize, unsigned int waves, float amplitude)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipX3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static FlipX3D* create(float duration)
    bool initWithSize(const Size& gridSize, float duration)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipY3D'
cls.SUPERCLS = "cocos2d::FlipX3D"
cls.funcs [[
    static FlipY3D* create(float duration)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Lens3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static Lens3D* create(float duration, const Size& gridSize, const Vec2& position, float radius)
    float getLensEffect()
    void setLensEffect(float lensEffect)
    void setConcave(bool concave)
    const Vec2& getPosition()
    void setPosition(const Vec2& position)
]]
cls.props [[
    lensEffect
    position
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Ripple3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static Ripple3D* create(float duration, const Size& gridSize, const Vec2& position, float radius, unsigned int waves, float amplitude)
    const Vec2& getPosition()
    void setPosition(const Vec2& position)
    float getAmplitude()
    void setAmplitude(float fAmplitude)
]]
cls.props [[
    position
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Shaky3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static Shaky3D* create(float initWithDuration, const Size& gridSize, int range, bool shakeZ)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Liquid'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static Liquid* create(float duration, const Size& gridSize, unsigned int waves, float amplitude)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Waves'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static Waves* create(float duration, const Size& gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Twirl'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static Twirl* create(float duration, const Size& gridSize, const Vec2& position, unsigned int twirls, float amplitude)
    const Vec2& getPosition()
    void setPosition(const Vec2& position)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    position
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PageTurn3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static PageTurn3D* create(float duration, const Size& gridSize)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ShakyTiles3D'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static ShakyTiles3D* create(float duration, const Size& gridSize, int range, bool shakeZ)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ShatteredTiles3D'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static ShatteredTiles3D* create(float duration, const Size& gridSize, int range, bool shatterZ)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ShuffleTiles'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static ShuffleTiles* create(float duration, const Size& gridSize, unsigned int seed)
    Size getDelta(const Size& pos)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutTRTiles'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static FadeOutTRTiles* create(float duration, const Size& gridSize)
    float testFunc(const Size& pos, float time)
    void turnOnTile(const Vec2& pos)
    void turnOffTile(const Vec2& pos)
    void transformTile(const Vec2& pos, float distance)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutBLTiles'
cls.SUPERCLS = "cocos2d::FadeOutTRTiles"
cls.funcs [[
    static FadeOutBLTiles* create(float duration, const Size& gridSize)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutUpTiles'
cls.SUPERCLS = "cocos2d::FadeOutTRTiles"
cls.funcs [[
    static FadeOutUpTiles* create(float duration, const Size& gridSize)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutDownTiles'
cls.SUPERCLS = "cocos2d::FadeOutUpTiles"
cls.funcs [[
    static FadeOutDownTiles* create(float duration, const Size& gridSize)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TurnOffTiles'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static TurnOffTiles* create(float duration, const Size& gridSize)
    static TurnOffTiles* create(float duration, const Size& gridSize, unsigned int seed)
    void turnOnTile(const Vec2& pos)
    void turnOffTile(const Vec2& pos)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::WavesTiles3D'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static WavesTiles3D* create(float duration, const Size& gridSize, unsigned int waves, float amplitude)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::JumpTiles3D'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static JumpTiles3D* create(float duration, const Size& gridSize, unsigned int numberOfJumps, float amplitude)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SplitRows'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static SplitRows* create(float duration, unsigned int rows)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SplitCols'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static SplitCols* create(float duration, unsigned int cols)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleBatchNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static ParticleBatchNode* createWithTexture(Texture2D *tex, int capacity = kParticleDefaultCapacity)
    static ParticleBatchNode* create(const std::string& fileImage, int capacity = kParticleDefaultCapacity)
    void insertChild(ParticleSystem* system, int index)
    void removeChildAtIndex(int index, bool doCleanup)
    void disableParticle(int particleIndex)
    TextureAtlas* getTextureAtlas()
    void setTextureAtlas(TextureAtlas* atlas)
    Texture2D* getTexture(void)
    void setTexture(Texture2D *texture)
    void setBlendFunc(const BlendFunc &blendFunc)
    const BlendFunc& getBlendFunc(void)
    bool initWithTexture(Texture2D *tex, int capacity)
    bool initWithFile(const std::string& fileImage, int capacity)
]]
cls.props [[
    textureAtlas
    texture
    blendFunc
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSystem::Mode'
cls.enums [[
    GRAVITY
    RADIUS
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSystem::PositionType'
cls.enums [[
    FREE
    RELATIVE
    GROUPED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSystem'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static ParticleSystem * create(const std::string& plistFile)
    static ParticleSystem* createWithTotalParticles(int numberOfParticles)
    static Vector<ParticleSystem*>& getAllParticleSystems()
    void addParticles(int count)
    void stopSystem()
    void resetSystem()
    bool isFull()
    void updateParticleQuads()
    void postStep()
    void updateWithNoTime()
    bool isAutoRemoveOnFinish()
    void setAutoRemoveOnFinish(bool var)
    const Vec2& getGravity()
    void setGravity(const Vec2& g)
    float getSpeed()
    void setSpeed(float speed)
    float getSpeedVar()
    void setSpeedVar(float speed)
    float getTangentialAccel()
    void setTangentialAccel(float t)
    float getTangentialAccelVar()
    void setTangentialAccelVar(float t)
    float getRadialAccel()
    void setRadialAccel(float t)
    float getRadialAccelVar()
    void setRadialAccelVar(float t)
    bool getRotationIsDir()
    void setRotationIsDir(bool t)
    float getStartRadius()
    void setStartRadius(float startRadius)
    float getStartRadiusVar()
    void setStartRadiusVar(float startRadiusVar)
    float getEndRadius()
    void setEndRadius(float endRadius)
    float getEndRadiusVar()
    void setEndRadiusVar(float endRadiusVar)
    float getRotatePerSecond()
    void setRotatePerSecond(float degrees)
    float getRotatePerSecondVar()
    void setRotatePerSecondVar(float degrees)
    bool isActive()
    bool isBlendAdditive()
    void setBlendAdditive(bool value)
    ParticleBatchNode* getBatchNode()
    void setBatchNode(ParticleBatchNode* batchNode)
    int getAtlasIndex()
    void setAtlasIndex(int index)
    unsigned int getParticleCount()
    float getDuration()
    void setDuration(float duration)
    const Vec2& getSourcePosition()
    void setSourcePosition(const Vec2& pos)
    const Vec2& getPosVar()
    void setPosVar(const Vec2& pos)
    float getLife()
    void setLife(float life)
    float getLifeVar()
    void setLifeVar(float lifeVar)
    float getAngle()
    void setAngle(float angle)
    float getAngleVar()
    void setAngleVar(float angleVar)
    Mode getEmitterMode()
    void setEmitterMode(Mode mode)
    float getStartSize()
    void setStartSize(float startSize)
    float getStartSizeVar()
    void setStartSizeVar(float sizeVar)
    float getEndSize()
    void setEndSize(float endSize)
    float getEndSizeVar()
    void setEndSizeVar(float sizeVar)
    const Color4F& getStartColor()
    void setStartColor(const Color4F& color)
    const Color4F& getStartColorVar()
    void setStartColorVar(const Color4F& color)
    const Color4F& getEndColor()
    void setEndColor(const Color4F& color)
    const Color4F& getEndColorVar()
    void setEndColorVar(const Color4F& color)
    float getStartSpin()
    void setStartSpin(float spin)
    float getStartSpinVar()
    void setStartSpinVar(float pinVar)
    float getEndSpin()
    void setEndSpin(float endSpin)
    float getEndSpinVar()
    void setEndSpinVar(float endSpinVar)
    float getEmissionRate()
    void setEmissionRate(float rate)
    int getTotalParticles()
    void setTotalParticles(int totalParticles)
    PositionType getPositionType()
    void setPositionType(PositionType type)
    Texture2D* getTexture()
    void setTexture(Texture2D *texture)
    void setBlendFunc(const BlendFunc &blendFunc)
    const BlendFunc &getBlendFunc()
    const std::string& getResourceFile()
    void start()
    void stop()
    void setSourcePositionCompatible(bool sourcePositionCompatible)
    bool isSourcePositionCompatible()
    bool initWithFile(const std::string& plistFile)
    bool initWithDictionary(ValueMap& dictionary)
    bool initWithDictionary(ValueMap& dictionary, const std::string& dirname)
    bool initWithTotalParticles(int numberOfParticles)
    bool isPaused()
    void pauseEmissions()
    void resumeEmissions()
]]
cls.props [[
    allParticleSystems
    full
    autoRemoveOnFinish
    gravity
    speed
    speedVar
    tangentialAccel
    tangentialAccelVar
    radialAccel
    radialAccelVar
    rotationIsDir
    startRadius
    startRadiusVar
    endRadius
    endRadiusVar
    rotatePerSecond
    rotatePerSecondVar
    active
    blendAdditive
    batchNode
    atlasIndex
    particleCount
    duration
    sourcePosition
    posVar
    life
    lifeVar
    angle
    angleVar
    emitterMode
    startSize
    startSizeVar
    endSize
    endSizeVar
    startColor
    startColorVar
    endColor
    endColorVar
    startSpin
    startSpinVar
    endSpin
    endSpinVar
    emissionRate
    totalParticles
    positionType
    texture
    blendFunc
    resourceFile
    sourcePositionCompatible
    paused
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSystemQuad'
cls.SUPERCLS = "cocos2d::ParticleSystem"
cls.funcs [[
    static ParticleSystemQuad * create()
    static ParticleSystemQuad * createWithTotalParticles(int numberOfParticles)
    static ParticleSystemQuad * create(const std::string& filename)
    static ParticleSystemQuad * create(ValueMap &dictionary)
    void setDisplayFrame(SpriteFrame *spriteFrame)
    void setTextureWithRect(Texture2D *texture, const Rect& rect)
    void listenRendererRecreated(EventCustom* event)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleExplosion'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static ParticleExplosion* create()
    static ParticleExplosion* createWithTotalParticles(int numberOfParticles)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleFire'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static ParticleFire* create()
    static ParticleFire* createWithTotalParticles(int numberOfParticles)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleFireworks'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static ParticleFireworks* create()
    static ParticleFireworks* createWithTotalParticles(int numberOfParticles)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleFlower'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static ParticleFlower* create()
    static ParticleFlower* createWithTotalParticles(int numberOfParticles)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleGalaxy'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static ParticleGalaxy* create()
    static ParticleGalaxy* createWithTotalParticles(int numberOfParticles)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleMeteor'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static ParticleMeteor * create()
    static ParticleMeteor* createWithTotalParticles(int numberOfParticles)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleRain'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static ParticleRain* create()
    static ParticleRain* createWithTotalParticles(int numberOfParticles)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSmoke'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static ParticleSmoke* create()
    static ParticleSmoke* createWithTotalParticles(int numberOfParticles)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSnow'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static ParticleSnow* create()
    static ParticleSnow* createWithTotalParticles(int numberOfParticles)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSpiral'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static ParticleSpiral* create()
    static ParticleSpiral* createWithTotalParticles(int numberOfParticles)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSun'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static ParticleSun* create()
    static ParticleSun* createWithTotalParticles(int numberOfParticles)
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
