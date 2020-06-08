-- AUTO BUILD, DON'T MODIFY!

require "autobuild.cocos2d-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "audio/include/AudioEngine.h"
#include "cocos2d.h"
#include "base/TGAlib.h"
#include "ui/CocosGUI.h"
#include "navmesh/CCNavMesh.h"
#include "xgame/xlua.h"
]]
M.CHUNK = [[
static const std::string makeScheduleCallbackTag(const std::string &key)
{
    return "schedule." + key;
}
]]

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'cocos2d::RenderTargetFlag'
cls.enums [[
    COLOR
    DEPTH
    STENCIL
    ALL
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ClearFlag'
cls.enums [[
    NONE
    COLOR
    DEPTH
    STENCIL
    ALL
]]
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

cls = typecls 'cocos2d::UserDefault'
cls.funcs [[
    bool getBoolForKey(const char *key)
    bool getBoolForKey(const char *key, bool defaultValue)
    int getIntegerForKey(const char *key)
    int getIntegerForKey(const char *key, int defaultValue)
    float getFloatForKey(const char *key)
    float getFloatForKey(const char *key, float defaultValue)
    double getDoubleForKey(const char *key)
    double getDoubleForKey(const char *key, double defaultValue)
    std::string getStringForKey(const char *key)
    std::string getStringForKey(const char *key, const std::string &defaultValue)
    cocos2d::Data getDataForKey(const char *key)
    cocos2d::Data getDataForKey(const char *key, const cocos2d::Data &defaultValue)
    void setBoolForKey(const char *key, bool value)
    void setIntegerForKey(const char *key, int value)
    void setFloatForKey(const char *key, float value)
    void setDoubleForKey(const char *key, double value)
    void setStringForKey(const char *key, const std::string &value)
    void setDataForKey(const char *key, const cocos2d::Data &value)
    void flush()
    void deleteValueForKey(const char *key)
    static cocos2d::UserDefault *getInstance()
    static void destroyInstance()
    static const std::string &getXMLFilePath()
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

cls = typecls 'cocos2d::Console'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    Console()
    bool listenOnTCP(int port)
    bool listenOnFileDescriptor(int fd)
    void stop()
    void delCommand(const std::string &cmdName)
    void delSubCommand(const std::string &cmdName, const std::string &subCmdName)
    void log(const char *buf)
    void setBindAddress(const std::string &address)
    bool isIpv6Server()
    char getCommandSeparator()
    void setCommandSeparator(char var)
]]
cls.props [[
    ipv6Server
    commandSeparator
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Acceleration'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
]]
cls.var('x', [[@optional double x]])
cls.var('y', [[@optional double y]])
cls.var('z', [[@optional double z]])
cls.var('timestamp', [[@optional double timestamp]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Director'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::Director *getInstance()
    Director()
    bool init()
    @addref(scenes |) cocos2d::Scene *getRunningScene()
    float getAnimationInterval()
    void setAnimationInterval(float interval)
    bool isDisplayStats()
    void setDisplayStats(bool displayStats)
    float getSecondsPerFrame()
    @addref(openGLView ^) cocos2d::GLView *getOpenGLView()
    void setOpenGLView(@addref(openGLView ^) cocos2d::GLView *openGLView)
    @addref(textureCache ^) cocos2d::TextureCache *getTextureCache()
    bool isNextDeltaTimeZero()
    void setNextDeltaTimeZero(bool nextDeltaTimeZero)
    bool isPaused()
    unsigned int getTotalFrames()
    cocos2d::Director::Projection getProjection()
    void setProjection(cocos2d::Director::Projection projection)
    void setViewport()
    bool isSendCleanupToScene()
    @addref(notificationNode ^) cocos2d::Node *getNotificationNode()
    void setNotificationNode(@addref(notificationNode ^) cocos2d::Node *node)
    const cocos2d::Size &getWinSize()
    cocos2d::Size getWinSizeInPixels()
    cocos2d::Size getVisibleSize()
    cocos2d::Vec2 getVisibleOrigin()
    cocos2d::Rect getSafeAreaRect()
    cocos2d::Vec2 convertToGL(@pack const cocos2d::Vec2 &point)
    cocos2d::Vec2 convertToUI(@pack const cocos2d::Vec2 &point)
    float getZEye()
    void runWithScene(@addref(scenes |) cocos2d::Scene *scene)
    void pushScene(@addref(scenes |) cocos2d::Scene *scene)
    @delref(scenes ~) void popScene()
    @delref(scenes ~) void popToRootScene()
    @delref(scenes ~) void popToSceneStackLevel(int level)
    @delref(scenes ~) void replaceScene(@addref(scenes |) cocos2d::Scene *scene)
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
    void setClearColor(const cocos2d::Color4F &clearColor)
    void mainLoop()
    void mainLoop(float dt)
    void setContentScaleFactor(float scaleFactor)
    float getContentScaleFactor()
    @addref(scheduler ^) cocos2d::Scheduler *getScheduler()
    void setScheduler(@addref(scheduler ^) cocos2d::Scheduler *scheduler)
    @addref(actionManager ^) cocos2d::ActionManager *getActionManager()
    void setActionManager(@addref(actionManager ^) cocos2d::ActionManager *actionManager)
    @addref(eventDispatcher ^) cocos2d::EventDispatcher *getEventDispatcher()
    void setEventDispatcher(@addref(eventDispatcher ^) cocos2d::EventDispatcher *dispatcher)
    @addref(renderer ^) cocos2d::Renderer *getRenderer()
    cocos2d::Console *getConsole()
    float getDeltaTime()
    float getFrameRate()
    void pushMatrix(cocos2d::MATRIX_STACK_TYPE type)
    void popMatrix(cocos2d::MATRIX_STACK_TYPE type)
    void loadIdentityMatrix(cocos2d::MATRIX_STACK_TYPE type)
    void loadMatrix(cocos2d::MATRIX_STACK_TYPE type, const cocos2d::Mat4 &mat)
    void multiplyMatrix(cocos2d::MATRIX_STACK_TYPE type, const cocos2d::Mat4 &mat)
    const cocos2d::Mat4 &getMatrix(cocos2d::MATRIX_STACK_TYPE type)
    void resetMatrixStack()
    bool isValid()
]]
cls.var('EVENT_BEFORE_SET_NEXT_SCENE', [[static const char *EVENT_BEFORE_SET_NEXT_SCENE]])
cls.var('EVENT_AFTER_SET_NEXT_SCENE', [[static const char *EVENT_AFTER_SET_NEXT_SCENE]])
cls.var('EVENT_PROJECTION_CHANGED', [[static const char *EVENT_PROJECTION_CHANGED]])
cls.var('EVENT_BEFORE_UPDATE', [[static const char *EVENT_BEFORE_UPDATE]])
cls.var('EVENT_AFTER_UPDATE', [[static const char *EVENT_AFTER_UPDATE]])
cls.var('EVENT_RESET', [[static const char *EVENT_RESET]])
cls.var('EVENT_AFTER_VISIT', [[static const char *EVENT_AFTER_VISIT]])
cls.var('EVENT_AFTER_DRAW', [[static const char *EVENT_AFTER_DRAW]])
cls.var('EVENT_BEFORE_DRAW', [[static const char *EVENT_BEFORE_DRAW]])
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
    contentScaleFactor
    scheduler
    actionManager
    eventDispatcher
    renderer
    console
    deltaTime
    frameRate
    valid
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Scheduler'
cls.SUPERCLS = "cocos2d::Ref"
cls.CHUNK = [[
template <typename T> bool doScheduleUpdate(lua_State *L)
{
    if (olua_isa<T>(L, 2)) {
        auto self = olua_checkobj<cocos2d::Scheduler>(L, 1);
        auto target = olua_checkobj<T>(L, 2);
        lua_Integer priority = olua_checkinteger(L, 3);
        bool paused = olua_checkboolean(L, 4);
        self->scheduleUpdate(target, (int)priority, paused);
        return true;
    }

    return false;
}
]]
cls.const('PRIORITY_SYSTEM', 'cocos2d::Scheduler::PRIORITY_SYSTEM', 'const int')
cls.const('PRIORITY_NON_SYSTEM_MIN', 'cocos2d::Scheduler::PRIORITY_NON_SYSTEM_MIN', 'const int')
cls.funcs [[
    Scheduler()
    float getTimeScale()
    void setTimeScale(float timeScale)
    void update(float dt)
    void unscheduleUpdate(void *target)
    void unscheduleAllWithMinPriority(int minPriority)
    bool isScheduled(const std::string &key, const void *target)
    void pauseTarget(void *target)
    void resumeTarget(void *target)
    bool isTargetPaused(void *target)
    std::set<void *> pauseAllTargets()
    std::set<void *> pauseAllTargetsWithMinPriority(int minPriority)
    void resumeTargets(const std::set<void *> &targetsToResume)
    void removeAllFunctionsToBePerformedInCocosThread()
]]
cls.func('scheduleUpdate', [[{
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
        'void schedule(@local const std::function<void (float)> &callback, void *target, float interval, unsigned int repeat, float delay, bool paused, const std::string &key)',
        'void schedule(@local const std::function<void (float)> &callback, void *target, float interval, bool paused, const std::string &key)'
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = 2,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void unschedule(const std::string &key, void *target)'
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = 2,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void unscheduleAllForTarget(void *target)'
    },
    TAG_MAKER = 'makeScheduleCallbackTag("")',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = 1,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void unscheduleAll()'
    },
    TAG_MAKER = 'makeScheduleCallbackTag("")',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
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
cls.funcs [[
    void addEventListenerWithSceneGraphPriority(@addref(listeners | 3) cocos2d::EventListener *listener, cocos2d::Node *node)
    void addEventListenerWithFixedPriority(@addref(listeners |) cocos2d::EventListener *listener, int fixedPriority)
    @delref(listeners ~) void removeEventListener(cocos2d::EventListener *listener)
    @delref(listeners ~) void removeEventListenersForType(cocos2d::EventListener::Type listenerType)
    void removeEventListenersForTarget(cocos2d::Node *target, @optional bool recursive)
    @delref(listeners ~) void removeCustomEventListeners(const std::string &customEventName)
    @delref(listeners ~) void removeAllEventListeners()
    void pauseEventListenersForTarget(cocos2d::Node *target, @optional bool recursive)
    void resumeEventListenersForTarget(cocos2d::Node *target, @optional bool recursive)
    void setPriority(cocos2d::EventListener *listener, int fixedPriority)
    void setEnabled(bool isEnabled)
    bool isEnabled()
    void dispatchEvent(cocos2d::Event *event)
    void dispatchCustomEvent(const std::string &eventName, @optional void *optionalUserData)
    bool hasEventListener(const cocos2d::EventListener::ListenerID &listenerID)
    EventDispatcher()
]]
cls.callback {
    FUNCS =  {
        '@addref(listeners |) cocos2d::EventListenerCustom *addCustomEventListener(const std::string &eventName, @local const std::function<void (EventCustom *)> &callback)'
    },
    TAG_MAKER = '(#1)',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = "return",
    TAG_SCOPE = 'object',
}
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
    cocos2d::EventListener *clone()
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
cls.const('LISTENER_ID', 'cocos2d::EventListenerTouchOneByOne::LISTENER_ID', 'const std::string')
cls.funcs [[
    static cocos2d::EventListenerTouchOneByOne *create()
    void setSwallowTouches(bool needSwallow)
    bool isSwallowTouches()
    EventListenerTouchOneByOne()
]]
cls.var('onTouchBegan', [[@nullable @local std::function<bool (Touch *, Event *)> onTouchBegan]])
cls.var('onTouchMoved', [[@nullable @local std::function<void (Touch *, Event *)> onTouchMoved]])
cls.var('onTouchEnded', [[@nullable @local std::function<void (Touch *, Event *)> onTouchEnded]])
cls.var('onTouchCancelled', [[@nullable @local std::function<void (Touch *, Event *)> onTouchCancelled]])
cls.props [[
    swallowTouches
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerTouchAllAtOnce'
cls.SUPERCLS = "cocos2d::EventListener"
cls.const('LISTENER_ID', 'cocos2d::EventListenerTouchAllAtOnce::LISTENER_ID', 'const std::string')
cls.funcs [[
    static cocos2d::EventListenerTouchAllAtOnce *create()
    EventListenerTouchAllAtOnce()
]]
cls.var('onTouchesBegan', [[@nullable @local std::function<void (const std::vector<Touch *> &, Event *)> onTouchesBegan]])
cls.var('onTouchesMoved', [[@nullable @local std::function<void (const std::vector<Touch *> &, Event *)> onTouchesMoved]])
cls.var('onTouchesEnded', [[@nullable @local std::function<void (const std::vector<Touch *> &, Event *)> onTouchesEnded]])
cls.var('onTouchesCancelled', [[@nullable @local std::function<void (const std::vector<Touch *> &, Event *)> onTouchesCancelled]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerCustom'
cls.SUPERCLS = "cocos2d::EventListener"
cls.funcs [[
    EventListenerCustom()
]]
cls.callback {
    FUNCS =  {
        'static cocos2d::EventListenerCustom *create(const std::string &eventName, @local const std::function<void (EventCustom *)> &callback)'
    },
    TAG_MAKER = 'listener',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = "return",
    TAG_SCOPE = 'object',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerKeyboard'
cls.SUPERCLS = "cocos2d::EventListener"
cls.const('LISTENER_ID', 'cocos2d::EventListenerKeyboard::LISTENER_ID', 'const std::string')
cls.funcs [[
    static cocos2d::EventListenerKeyboard *create()
    EventListenerKeyboard()
]]
cls.var('onKeyPressed', [[@nullable @local std::function<void (EventKeyboard::KeyCode, Event *)> onKeyPressed]])
cls.var('onKeyReleased', [[@nullable @local std::function<void (EventKeyboard::KeyCode, Event *)> onKeyReleased]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerAcceleration'
cls.SUPERCLS = "cocos2d::EventListener"
cls.const('LISTENER_ID', 'cocos2d::EventListenerAcceleration::LISTENER_ID', 'const std::string')
cls.funcs [[
    EventListenerAcceleration()
]]
cls.callback {
    FUNCS =  {
        'static cocos2d::EventListenerAcceleration *create(@local const std::function<void (Acceleration *, Event *)> &callback)'
    },
    TAG_MAKER = 'listener',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = "return",
    TAG_SCOPE = 'object',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerFocus'
cls.SUPERCLS = "cocos2d::EventListener"
cls.const('LISTENER_ID', 'cocos2d::EventListenerFocus::LISTENER_ID', 'const std::string')
cls.funcs [[
    static cocos2d::EventListenerFocus *create()
    EventListenerFocus()
]]
cls.var('onFocusChanged', [[@nullable @local std::function<void (ui::Widget *, ui::Widget *)> onFocusChanged]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerMouse'
cls.SUPERCLS = "cocos2d::EventListener"
cls.const('LISTENER_ID', 'cocos2d::EventListenerMouse::LISTENER_ID', 'const std::string')
cls.funcs [[
    static cocos2d::EventListenerMouse *create()
    EventListenerMouse()
]]
cls.var('onMouseDown', [[@nullable @local std::function<void (EventMouse *)> onMouseDown]])
cls.var('onMouseUp', [[@nullable @local std::function<void (EventMouse *)> onMouseUp]])
cls.var('onMouseMove', [[@nullable @local std::function<void (EventMouse *)> onMouseMove]])
cls.var('onMouseScroll', [[@nullable @local std::function<void (EventMouse *)> onMouseScroll]])
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
    Event(cocos2d::Event::Type type)
    cocos2d::Event::Type getType()
    void stopPropagation()
    bool isStopped()
    cocos2d::Node *getCurrentTarget()
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
    EventCustom(const std::string &eventName)
    void setUserData(void *data)
    void *getUserData()
    const std::string &getEventName()
]]
cls.props [[
    userData
    eventName
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerController'
cls.SUPERCLS = "cocos2d::EventListener"
cls.const('LISTENER_ID', 'cocos2d::EventListenerController::LISTENER_ID', 'const std::string')
cls.funcs [[
    static cocos2d::EventListenerController *create()
]]
cls.var('onConnected', [[@nullable @local std::function<void (Controller *, Event *)> onConnected]])
cls.var('onDisconnected', [[@nullable @local std::function<void (Controller *, Event *)> onDisconnected]])
cls.var('onKeyDown', [[@nullable @local std::function<void (Controller *, int, Event *)> onKeyDown]])
cls.var('onKeyUp', [[@nullable @local std::function<void (Controller *, int, Event *)> onKeyUp]])
cls.var('onKeyRepeat', [[@nullable @local std::function<void (Controller *, int, Event *)> onKeyRepeat]])
cls.var('onAxisEvent', [[@nullable @local std::function<void (Controller *, int, Event *)> onAxisEvent]])
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
cls.const('MAX_TOUCHES', 'cocos2d::EventTouch::MAX_TOUCHES', 'const int')
cls.funcs [[
    EventTouch()
    cocos2d::EventTouch::EventCode getEventCode()
    const std::vector<Touch *> &getTouches()
    void setEventCode(cocos2d::EventTouch::EventCode eventCode)
    void setTouches(const std::vector<Touch *> &touches)
]]
cls.props [[
    eventCode
    touches
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventKeyboard'
cls.SUPERCLS = "cocos2d::Event"
cls.funcs [[
    EventKeyboard(cocos2d::EventKeyboard::KeyCode keyCode, bool isPressed)
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
    EventFocus(cocos2d::ui::Widget *widgetLoseFocus, cocos2d::ui::Widget *widgetGetFocus)
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
    EventMouse(cocos2d::EventMouse::MouseEventType mouseEventCode)
    void setScrollData(float scrollX, float scrollY)
    float getScrollX()
    float getScrollY()
    void setCursorPosition(float x, float y)
    void setMouseButton(cocos2d::EventMouse::MouseButton button)
    cocos2d::EventMouse::MouseButton getMouseButton()
    float getCursorX()
    float getCursorY()
    cocos2d::Vec2 getLocation()
    cocos2d::Vec2 getPreviousLocation()
    cocos2d::Vec2 getStartLocation()
    cocos2d::Vec2 getDelta()
    cocos2d::Vec2 getLocationInView()
    cocos2d::Vec2 getPreviousLocationInView()
    cocos2d::Vec2 getStartLocationInView()
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
    EventController(cocos2d::EventController::ControllerEventType type, cocos2d::Controller *controller, int keyCode)
    EventController(cocos2d::EventController::ControllerEventType type, cocos2d::Controller *controller, bool isConnected)
    cocos2d::EventController::ControllerEventType getControllerEventType()
    cocos2d::Controller *getController()
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
    Touch()
    cocos2d::Vec2 getLocation()
    cocos2d::Vec2 getPreviousLocation()
    cocos2d::Vec2 getStartLocation()
    cocos2d::Vec2 getDelta()
    cocos2d::Vec2 getLocationInView()
    cocos2d::Vec2 getPreviousLocationInView()
    cocos2d::Vec2 getStartLocationInView()
    void setTouchInfo(int id, float x, float y)
    void setTouchInfo(int id, float x, float y, float force, float maxForce)
    int getID()
    float getCurrentForce()
    float getMaxForce()
]]
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
cls.const('TAG_UNSET', 'cocos2d::Controller::TAG_UNSET', 'const int')
cls.funcs [[
    static const std::vector<Controller *> &getAllController()
    static cocos2d::Controller *getControllerByTag(int tag)
    static cocos2d::Controller *getControllerByDeviceId(int deviceId)
    static void startDiscoveryController()
    static void stopDiscoveryController()
    const std::string &getDeviceName()
    int getDeviceId()
    bool isConnected()
    const cocos2d::Controller::KeyStatus &getKeyStatus(int keyCode)
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

cls = typecls 'cocos2d::AudioProfile'
cls.funcs [[
    AudioProfile()
]]
cls.var('name', [[std::string name]])
cls.var('maxInstances', [[unsigned int maxInstances]])
cls.var('minDelay', [[double minDelay]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AudioEngine::AudioState'
cls.enums [[
    ERROR
    INITIALIZING
    PLAYING
    PAUSED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AudioEngine'
cls.CHUNK = [[
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
        sprintf(buf, "finishCallback.%d", (int)id);
        return std::string(buf);
    }
}
]]
cls.const('INVALID_AUDIO_ID', 'cocos2d::AudioEngine::INVALID_AUDIO_ID', 'const int')
cls.const('TIME_UNKNOWN', 'cocos2d::AudioEngine::TIME_UNKNOWN', 'const float')
cls.funcs [[
    static bool lazyInit()
    static void end()
    static cocos2d::AudioProfile *getDefaultProfile()
    static int play2d(const std::string &filePath, @optional bool loop, @optional float volume, @optional const cocos2d::AudioProfile *profile)
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
    static cocos2d::AudioEngine::AudioState getState(int audioID)
    static int getMaxAudioInstance()
    static bool setMaxAudioInstance(int maxInstances)
    static void uncache(const std::string &filePath)
    static cocos2d::AudioProfile *getProfile(int audioID)
    static cocos2d::AudioProfile *getProfile(const std::string &profileName)
    static int getPlayingAudioCount()
    static void setEnabled(bool isEnabled)
    static bool isEnabled()
]]
cls.callback {
    FUNCS =  {
        'static void stop(int audioID)'
    },
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'static void stopAll()'
    },
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'static void uncacheAll()'
    },
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'static void setFinishCallback(int audioID, @nullable @local const std::function<void (int, const std::string &)> &callback)'
    },
    TAG_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'static void preload(const std::string &filePath)',
        'static void preload(const std::string &filePath, @local std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'preload',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.inject('uncache', {
    BEFORE = [[
        std::string path = olua_checkstring(L, 1);
        std::list<int> ids = cocos2d::LuaAudioEngine::getAudioIDs(path);
        void *self_obj = olua_pushclassobj<cocos2d::AudioEngine>(L);
        for (auto id : ids) {
            std::string tag = makeAudioEngineFinishCallbackTag((lua_Integer)id);
            olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);
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

cls = typecls 'cocos2d::ApplicationProtocol::Platform'
cls.enums [[
    OS_WINDOWS
    OS_LINUX
    OS_MAC
    OS_ANDROID
    OS_IPHONE
    OS_IPAD
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
    cocos2d::LanguageType getCurrentLanguage()
    const char *getCurrentLanguageCode()
    cocos2d::ApplicationProtocol::Platform getTargetPlatform()
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
    static cocos2d::Application *getInstance()
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

cls = typecls 'cocos2d::ResizableBuffer'
cls.funcs [[
    void resize(size_t size)
    void *buffer()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FileUtils::Status'
cls.enums [[
    OK
    NotExists
    OpenFailed
    ReadFailed
    NotInitialized
    TooLarge
    ObtainSizeFailed
    NotRegularFileType
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FileUtils'
cls.funcs [[
    static cocos2d::FileUtils *getInstance()
    static void destroyInstance()
    static void setDelegate(cocos2d::FileUtils *delegate)
    void purgeCachedEntries()
    cocos2d::FileUtils::Status getContents(const std::string &filename, cocos2d::ResizableBuffer *buffer)
    @length(arg3) unsigned char *getFileDataFromZip(const std::string &zipFilePath, const std::string &filename, @out ssize_t *size)
    std::string fullPathForFilename(const std::string &filename)
    void loadFilenameLookupDictionaryFromFile(const std::string &filename)
    void setFilenameLookupDictionary(const cocos2d::ValueMap &filenameLookupDict)
    std::string fullPathFromRelativeFile(const std::string &filename, const std::string &relativeFile)
    void setSearchResolutionsOrder(const std::vector<std::string> &searchResolutionsOrder)
    void addSearchResolutionsOrder(const std::string &order, @optional const bool front)
    const std::vector<std::string> getSearchResolutionsOrder()
    void setSearchPaths(const std::vector<std::string> &searchPaths)
    const std::string getDefaultResourceRootPath()
    void setDefaultResourceRootPath(const std::string &path)
    void addSearchPath(const std::string &path, @optional const bool front)
    const std::vector<std::string> getSearchPaths()
    const std::vector<std::string> getOriginalSearchPaths()
    std::string getWritablePath()
    void setWritablePath(const std::string &writablePath)
    void setPopupNotify(bool notify)
    bool isPopupNotify()
    cocos2d::ValueMap getValueMapFromFile(const std::string &filename)
    cocos2d::ValueMap getValueMapFromData(const char *filedata, int filesize)
    bool writeToFile(const cocos2d::ValueMap &dict, const std::string &fullPath)
    std::string getSuitableFOpen(const std::string &filenameUtf8)
    cocos2d::ValueVector getValueVectorFromFile(const std::string &filename)
    std::string getFileExtension(const std::string &filePath)
    bool isAbsolutePath(const std::string &path)
    std::vector<std::string> listFiles(const std::string &dirPath)
    void listFilesRecursively(const std::string &dirPath, @out std::vector<std::string> *files)
    const std::unordered_map<std::string, std::string> getFullPathCache()
    std::string getNewFilename(const std::string &filename)
]]
cls.callback {
    FUNCS =  {
        'std::string getStringFromFile(const std::string &filename)',
        'void getStringFromFile(const std::string &path, @local std::function<void (std::string)> callback)'
    },
    TAG_MAKER = 'StringFromFile',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'cocos2d::Data getDataFromFile(const std::string &filename)',
        'void getDataFromFile(const std::string &filename, @local std::function<void (Data)> callback)'
    },
    TAG_MAKER = 'DataFromFile',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'bool writeStringToFile(const std::string &dataStr, const std::string &fullPath)',
        'void writeStringToFile(std::string dataStr, const std::string &fullPath, @local std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'writeStringToFile',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'bool writeDataToFile(const cocos2d::Data &data, const std::string &fullPath)',
        'void writeDataToFile(cocos2d::Data data, const std::string &fullPath, @local std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'writeDataToFile',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'bool writeValueMapToFile(const cocos2d::ValueMap &dict, const std::string &fullPath)',
        'void writeValueMapToFile(cocos2d::ValueMap dict, const std::string &fullPath, @local std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'writeValueMapToFile',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'bool writeValueVectorToFile(const cocos2d::ValueVector &vecData, const std::string &fullPath)',
        'void writeValueVectorToFile(cocos2d::ValueVector vecData, const std::string &fullPath, @local std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'writeValueVectorToFile',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'bool isFileExist(const std::string &filename)',
        'void isFileExist(const std::string &filename, @local std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'isFileExist',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'bool isDirectoryExist(const std::string &dirPath)',
        'void isDirectoryExist(const std::string &fullPath, @local std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'isDirectoryExist',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'bool createDirectory(const std::string &dirPath)',
        'void createDirectory(const std::string &dirPath, @local std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'createDirectory',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'bool removeDirectory(const std::string &dirPath)',
        'void removeDirectory(const std::string &dirPath, @local std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'removeDirectory',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'bool removeFile(const std::string &filepath)',
        'void removeFile(const std::string &filepath, @local std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'removeFile',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'bool renameFile(const std::string &path, const std::string &oldname, const std::string &name)',
        'void renameFile(const std::string &path, const std::string &oldname, const std::string &name, @local std::function<void (bool)> callback)',
        'bool renameFile(const std::string &oldfullpath, const std::string &newfullpath)',
        'void renameFile(const std::string &oldfullpath, const std::string &newfullpath, @local std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'renameFile',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'long getFileSize(const std::string &filepath)',
        'void getFileSize(const std::string &filepath, @local std::function<void (long)> callback)'
    },
    TAG_MAKER = 'FileSize',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'void listFilesAsync(const std::string &dirPath, @local std::function<void (std::vector<std::string>)> callback)'
    },
    TAG_MAKER = 'listFilesAsync',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'void listFilesRecursivelyAsync(const std::string &dirPath, @local std::function<void (std::vector<std::string>)> callback)'
    },
    TAG_MAKER = 'listFilesRecursivelyAsync',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.props [[
    instance
    searchResolutionsOrder
    defaultResourceRootPath
    searchPaths
    originalSearchPaths
    writablePath
    popupNotify
    fullPathCache
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
    static void setGLContextAttrs(GLContextAttrs &glContextAttrs)
    static GLContextAttrs getGLContextAttrs()
    void pollEvents()
    cocos2d::Size getFrameSize()
    void setFrameSize(float width, float height)
    void setFrameZoomFactor(float )
    float getFrameZoomFactor()
    void setCursorVisible(bool )
    int getRetinaFactor()
    bool setContentScaleFactor(float )
    float getContentScaleFactor()
    bool isRetinaDisplay()
    cocos2d::Size getVisibleSize()
    cocos2d::Vec2 getVisibleOrigin()
    cocos2d::Rect getVisibleRect()
    cocos2d::Rect getSafeAreaRect()
    void setDesignResolutionSize(float width, float height, ResolutionPolicy resolutionPolicy)
    const cocos2d::Size &getDesignResolutionSize()
    void setViewPortInPoints(float x, float y, float w, float h)
    void setScissorInPoints(float x, float y, float w, float h)
    bool isScissorEnabled()
    cocos2d::Rect getScissorRect()
    void setViewName(const std::string &viewname)
    const std::string &getViewName()
    void setIcon(const std::string &filename)
    void setIcon(const std::vector<std::string> &filelist)
    void setDefaultIcon()
    const cocos2d::Rect &getViewPortRect()
    std::vector<Touch *> getAllTouches()
    float getScaleX()
    float getScaleY()
    ResolutionPolicy getResolutionPolicy()
    void renderScene(cocos2d::Scene *scene, cocos2d::Renderer *renderer)
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
    Image()
    static void setPNGPremultipliedAlphaEnabled(bool enabled)
    static void setPVRImagesHavePremultipliedAlpha(bool haveAlphaPremultiplied)
    bool initWithImageFile(const std::string &path)
    bool initWithImageData(const unsigned char *data, ssize_t dataLen)
    bool initWithRawData(const unsigned char *data, ssize_t dataLen, int width, int height, int bitsPerComponent, @optional bool preMulti)
    unsigned char *getData()
    ssize_t getDataLen()
    cocos2d::Image::Format getFileType()
    cocos2d::backend::PixelFormat getPixelFormat()
    int getWidth()
    int getHeight()
    int getNumberOfMipmaps()
    bool hasPremultipliedAlpha()
    std::string getFilePath()
    int getBitPerPixel()
    bool hasAlpha()
    bool isCompressed()
    bool saveToFile(const std::string &filename, @optional bool isToRGB)
    void premultiplyAlpha()
    void reversePremultipliedAlpha()
]]
cls.func('getPNGPremultipliedAlphaEnabled', [[{
    lua_pushboolean(L, cocos2d::LuaImage::getPNGPremultipliedAlphaEnabled());
    return 1;
}]])
cls.props [[
    data
    dataLen
    fileType
    pixelFormat
    width
    height
    numberOfMipmaps
    filePath
    bitPerPixel
    compressed
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Properties::Type'
cls.enums [[
    NONE
    STRING
    NUMBER
    VECTOR2
    VECTOR3
    VECTOR4
    MATRIX
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Properties'
cls.funcs [[
    static cocos2d::Properties *createNonRefCounted(const std::string &url)
    const char *getNextProperty()
    cocos2d::Properties *getNextNamespace()
    void rewind()
    cocos2d::Properties *getNamespace(const char *id, @optional bool searchNames, @optional bool recurse)
    const char *getNamespace()
    const char *getId()
    bool exists(const char *name)
    cocos2d::Properties::Type getType(@optional const char *name)
    const char *getString(@optional const char *name, @optional const char *defaultValue)
    bool setString(const char *name, const char *value)
    bool getBool(@optional const char *name, @optional bool defaultValue)
    int getInt(@optional const char *name)
    float getFloat(@optional const char *name)
    long getLong(@optional const char *name)
    bool getPath(const char *name, @out std::string *path)
    const char *getVariable(const char *name, @optional const char *defaultValue)
    void setVariable(const char *name, const char *value)
]]
cls.props [[
    nextProperty
    nextNamespace
    id
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Material'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::Material *createWithFilename(const std::string &path)
    static cocos2d::Material *createWithProgramState(cocos2d::backend::ProgramState *programState)
    static cocos2d::Material *createWithProperties(cocos2d::Properties *materialProperties)
    void draw(cocos2d::MeshCommand *meshCommand, float globalZOrder, cocos2d::backend::Buffer *vertexBuffer, cocos2d::backend::Buffer *indexBuffer, cocos2d::CustomCommand::PrimitiveType primitive, cocos2d::CustomCommand::IndexFormat indexFormat, unsigned int indexCount, const cocos2d::Mat4 &modelView)
    std::string getName()
    void setName(const std::string &name)
    cocos2d::Technique *getTechniqueByName(const std::string &name)
    cocos2d::Technique *getTechniqueByIndex(ssize_t index)
    cocos2d::Technique *getTechnique()
    const Vector<cocos2d::Technique *> &getTechniques()
    ssize_t getTechniqueCount()
    void addTechnique(cocos2d::Technique *technique)
    void setTechnique(const std::string &techniqueName)
    cocos2d::Material *clone()
    cocos2d::RenderState *getRenderState()
]]
cls.props [[
    name
    technique
    techniques
    techniqueCount
    renderState
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Renderer'
cls.const('VBO_SIZE', 'cocos2d::Renderer::VBO_SIZE', 'const int')
cls.const('INDEX_VBO_SIZE', 'cocos2d::Renderer::INDEX_VBO_SIZE', 'const int')
cls.const('BATCH_TRIAGCOMMAND_RESERVED_SIZE', 'cocos2d::Renderer::BATCH_TRIAGCOMMAND_RESERVED_SIZE', 'const int')
cls.const('MATERIAL_ID_DO_NOT_BATCH', 'cocos2d::Renderer::MATERIAL_ID_DO_NOT_BATCH', 'const int')
cls.funcs [[
    Renderer()
    void init()
    void drawCommand(cocos2d::RenderCommand *command)
    void addCommand(cocos2d::RenderCommand *command)
    void addCommand(cocos2d::RenderCommand *command, int renderQueueID)
    void pushGroup(int renderQueueID)
    void popGroup()
    int createRenderQueue()
    void render()
    void clean()
    ssize_t getDrawnBatches()
    void addDrawnBatches(ssize_t number)
    ssize_t getDrawnVertices()
    void addDrawnVertices(ssize_t number)
    void clearDrawStats()
    void setRenderTarget(cocos2d::RenderTargetFlag flags, cocos2d::Texture2D *colorAttachment, cocos2d::Texture2D *depthAttachment, cocos2d::Texture2D *stencilAttachment)
    void clear(cocos2d::ClearFlag flags, const cocos2d::Color4F &color, float depth, unsigned int stencil, float globalOrder)
    cocos2d::Texture2D *getColorAttachment()
    cocos2d::Texture2D *getDepthAttachment()
    cocos2d::Texture2D *getStencilAttachment()
    const cocos2d::Color4F &getClearColor()
    float getClearDepth()
    unsigned int getClearStencil()
    cocos2d::ClearFlag getClearFlag()
    cocos2d::RenderTargetFlag getRenderTargetFlag()
    void setDepthTest(bool value)
    void setDepthWrite(bool value)
    void setDepthCompareFunction(cocos2d::backend::CompareFunction func)
    bool getDepthTest()
    bool getDepthWrite()
    cocos2d::backend::CompareFunction getDepthCompareFunction()
    void setStencilTest(bool value)
    void setStencilCompareFunction(cocos2d::backend::CompareFunction func, unsigned int ref, unsigned int readMask)
    void setStencilOperation(cocos2d::backend::StencilOperation stencilFailureOp, cocos2d::backend::StencilOperation depthFailureOp, cocos2d::backend::StencilOperation stencilDepthPassOp)
    void setStencilWriteMask(unsigned int mask)
    bool getStencilTest()
    cocos2d::backend::StencilOperation getStencilFailureOperation()
    cocos2d::backend::StencilOperation getStencilPassDepthFailureOperation()
    cocos2d::backend::StencilOperation getStencilDepthPassOperation()
    cocos2d::backend::CompareFunction getStencilCompareFunction()
    unsigned int getStencilReadMask()
    unsigned int getStencilWriteMask()
    unsigned int getStencilReferenceValue()
    void setCullMode(cocos2d::CullMode mode)
    cocos2d::CullMode getCullMode()
    void setWinding(cocos2d::Winding winding)
    cocos2d::Winding getWinding()
    void setViewPort(int x, int y, unsigned int w, unsigned int h)
    const cocos2d::Viewport &getViewport()
    void setScissorTest(bool enabled)
    void setScissorRect(float x, float y, float width, float height)
    bool getScissorTest()
    const cocos2d::ScissorRect &getScissorRect()
    bool checkVisibility(const cocos2d::Mat4 &transform, const cocos2d::Size &size)
]]
cls.props [[
    drawnBatches
    drawnVertices
    colorAttachment
    depthAttachment
    stencilAttachment
    clearColor
    clearDepth
    clearStencil
    clearFlag
    renderTargetFlag
    depthTest
    depthWrite
    depthCompareFunction
    stencilTest
    stencilFailureOperation
    stencilPassDepthFailureOperation
    stencilDepthPassOperation
    stencilCompareFunction
    stencilReadMask
    stencilWriteMask
    stencilReferenceValue
    cullMode
    winding
    viewport
    scissorTest
    scissorRect
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RenderCommand::Type'
cls.enums [[
    UNKNOWN_COMMAND
    QUAD_COMMAND
    CUSTOM_COMMAND
    GROUP_COMMAND
    MESH_COMMAND
    TRIANGLES_COMMAND
    CALLBACK_COMMAND
    CAPTURE_SCREEN_COMMAND
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CustomCommand::DrawType'
cls.enums [[
    ARRAY
    ELEMENT
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PipelineDescriptor'
cls.funcs [[
]]
cls.var('programState', [[@optional cocos2d::backend::ProgramState *programState]])
cls.var('blendDescriptor', [[cocos2d::backend::BlendDescriptor blendDescriptor]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Technique'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Pass'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RenderState'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RenderCommand'
cls.funcs [[
    void init(float globalZOrder, const cocos2d::Mat4 &modelViewTransform, unsigned int flags)
    float getGlobalOrder()
    cocos2d::RenderCommand::Type getType()
    bool isTransparent()
    void setTransparent(bool isTransparent)
    bool isSkipBatching()
    void setSkipBatching(bool value)
    bool is3D()
    void set3D(bool value)
    float getDepth()
    cocos2d::PipelineDescriptor &getPipelineDescriptor()
    const cocos2d::Mat4 &getMV()
]]
cls.props [[
    globalOrder
    type
    transparent
    skipBatching
    3D
    depth
    pipelineDescriptor
    mv
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CustomCommand'
cls.SUPERCLS = "cocos2d::RenderCommand"
cls.funcs [[
    CustomCommand()
    void init(float globalZOrder)
    void init(float globalZOrder, const cocos2d::BlendFunc &blendFunc)
    void createVertexBuffer(std::size_t vertexSize, std::size_t capacity, cocos2d::CustomCommand::BufferUsage usage)
    void createIndexBuffer(cocos2d::CustomCommand::IndexFormat format, std::size_t capacity, cocos2d::CustomCommand::BufferUsage usage)
    void updateVertexBuffer(void *data, std::size_t length)
    void updateIndexBuffer(void *data, std::size_t length)
    void updateVertexBuffer(void *data, std::size_t offset, std::size_t length)
    void updateIndexBuffer(void *data, std::size_t offset, std::size_t length)
    std::size_t getVertexCapacity()
    std::size_t getIndexCapacity()
    void setDrawType(cocos2d::CustomCommand::DrawType drawType)
    cocos2d::CustomCommand::DrawType getDrawType()
    void setPrimitiveType(cocos2d::CustomCommand::PrimitiveType primitiveType)
    cocos2d::CustomCommand::PrimitiveType getPrimitiveType()
    void setVertexBuffer(cocos2d::backend::Buffer *vertexBuffer)
    cocos2d::backend::Buffer *getVertexBuffer()
    void setIndexBuffer(cocos2d::backend::Buffer *indexBuffer, cocos2d::CustomCommand::IndexFormat indexFormat)
    cocos2d::backend::Buffer *getIndexBuffer()
    void setVertexDrawInfo(std::size_t start, std::size_t count)
    std::size_t getVertexDrawStart()
    std::size_t getVertexDrawCount()
    void setIndexDrawInfo(std::size_t start, std::size_t count)
    std::size_t getIndexDrawOffset()
    std::size_t getIndexDrawCount()
    void setLineWidth(float lineWidth)
    float getLineWidth()
    cocos2d::CustomCommand::IndexFormat getIndexFormat()
]]
cls.var('func', [[@nullable @local std::function<void ()> func]])
cls.callback {
    FUNCS =  {
        'void setBeforeCallback(@local const std::function<void ()> &before)'
    },
    TAG_MAKER = 'BeforeCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setAfterCallback(@local const std::function<void ()> &after)'
    },
    TAG_MAKER = 'AfterCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        '@local const std::function<void ()> &getBeforeCallback()'
    },
    TAG_MAKER = 'BeforeCallback',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        '@local const std::function<void ()> &getAfterCallback()'
    },
    TAG_MAKER = 'AfterCallback',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    vertexCapacity
    indexCapacity
    drawType
    primitiveType
    vertexBuffer
    indexBuffer
    vertexDrawStart
    vertexDrawCount
    indexDrawOffset
    indexDrawCount
    lineWidth
    indexFormat
    beforeCallback
    afterCallback
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MeshCommand'
cls.SUPERCLS = "cocos2d::CustomCommand"
cls.funcs [[
    MeshCommand()
    void init(float globalZOrder, const cocos2d::Mat4 &transform)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextureCache'
cls.SUPERCLS = "cocos2d::Ref"
cls.CHUNK = [[
static const std::string makeTextureCacheCallbackTag(const std::string &key)
{
    return "addImageAsync." + key;
}
]]
cls.funcs [[
    static void setETC1AlphaFileSuffix(const std::string &suffix)
    static std::string getETC1AlphaFileSuffix()
    TextureCache()
    std::string getDescription()
    cocos2d::Texture2D *addImage(const std::string &filepath)
    cocos2d::Texture2D *addImage(cocos2d::Image *image, const std::string &key)
    cocos2d::Texture2D *getTextureForKey(const std::string &key)
    bool reloadTexture(const std::string &fileName)
    void removeAllTextures()
    void removeUnusedTextures()
    void removeTexture(cocos2d::Texture2D *texture)
    void removeTextureForKey(const std::string &key)
    std::string getCachedTextureInfo()
    void waitForQuit()
    std::string getTextureFilePath(cocos2d::Texture2D *texture)
    void renameTextureWithKey(const std::string &srcName, const std::string &dstName)
]]
cls.callback {
    FUNCS =  {
        'void addImageAsync(const std::string &filepath, const std::function<void (Texture2D *)> &callback)',
        'void addImageAsync(const std::string &path, const std::function<void (Texture2D *)> &callback, const std::string &callbackKey)'
    },
    TAG_MAKER = {'makeTextureCacheCallbackTag(#1)', 'makeTextureCacheCallbackTag(#-1)'},
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'void unbindImageAsync(const std::string &filename)'
    },
    TAG_MAKER = 'makeTextureCacheCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void unbindAllImageAsync()'
    },
    TAG_MAKER = 'makeTextureCacheCallbackTag("")',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    etC1AlphaFileSuffix
    description
    cachedTextureInfo
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Texture2D'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static void setDefaultAlphaPixelFormat(cocos2d::backend::PixelFormat format)
    static cocos2d::backend::PixelFormat getDefaultAlphaPixelFormat()
    Texture2D()
    bool initWithData(const void *data, ssize_t dataLen, cocos2d::backend::PixelFormat pixelFormat, int pixelsWide, int pixelsHigh, const cocos2d::Size &contentSize, @optional bool preMultipliedAlpha)
    bool initWithData(const void *data, ssize_t dataLen, cocos2d::backend::PixelFormat pixelFormat, cocos2d::backend::PixelFormat renderFormat, int pixelsWide, int pixelsHigh, const cocos2d::Size &contentSize, @optional bool preMultipliedAlpha)
    bool updateWithData(void *data, int offsetX, int offsetY, int width, int height)
    void drawAtPoint(const cocos2d::Vec2 &point, float globalZOrder)
    void drawInRect(const cocos2d::Rect &rect, float globalZOrder)
    bool initWithImage(cocos2d::Image *image)
    bool initWithImage(cocos2d::Image *image, cocos2d::backend::PixelFormat format)
    bool initWithString(const char *text, const std::string &fontName, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment, @optional bool enableWrap, @optional int overflow)
    bool initWithBackendTexture(cocos2d::backend::TextureBackend *texture, @optional bool preMultipliedAlpha)
    void setRenderTarget(bool renderTarget)
    bool isRenderTarget()
    void setTexParameters(const cocos2d::Texture2D::TexParams &params)
    void generateMipmap()
    void setAntiAliasTexParameters()
    void setAliasTexParameters()
    const char *getStringForFormat()
    unsigned int getBitsPerPixelForFormat()
    unsigned int getBitsPerPixelForFormat(cocos2d::backend::PixelFormat format)
    const cocos2d::Size &getContentSizeInPixels()
    bool hasPremultipliedAlpha()
    bool hasMipmaps()
    cocos2d::backend::PixelFormat getPixelFormat()
    int getPixelsWide()
    int getPixelsHigh()
    cocos2d::backend::TextureBackend *getBackendTexture()
    float getMaxS()
    void setMaxS(float maxS)
    float getMaxT()
    void setMaxT(float maxT)
    cocos2d::Size getContentSize()
    std::string getPath()
    void setAlphaTexture(cocos2d::Texture2D *alphaTexture)
    cocos2d::Texture2D *getAlphaTexture()
    bool getAlphaTextureName()
    static const std::map<backend::PixelFormat, const PixelFormatInfo> &getPixelFormatInfoMap()
]]
cls.props [[
    defaultAlphaPixelFormat
    renderTarget
    stringForFormat
    contentSizeInPixels
    pixelFormat
    pixelsWide
    pixelsHigh
    backendTexture
    maxS
    maxT
    contentSize
    path
    alphaTexture
    alphaTextureName
    pixelFormatInfoMap
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextureCube'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::TextureCube *create(const std::string &positive_x, const std::string &negative_x, const std::string &positive_y, const std::string &negative_y, const std::string &positive_z, const std::string &negative_z)
    void setTexParameters(const cocos2d::Texture2D::TexParams &)
    cocos2d::backend::TextureBackend *getBackendTexture()
    bool reloadTexture()
    TextureCube()
]]
cls.props [[
    backendTexture
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextureAtlas'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::TextureAtlas *create(const std::string &file, ssize_t capacity)
    static cocos2d::TextureAtlas *createWithTexture(cocos2d::Texture2D *texture, ssize_t capacity)
    TextureAtlas()
    bool initWithFile(const std::string &file, ssize_t capacity)
    bool initWithTexture(cocos2d::Texture2D *texture, ssize_t capacity)
    void insertQuadFromIndex(ssize_t fromIndex, ssize_t newIndex)
    void removeQuadAtIndex(ssize_t index)
    void removeQuadsAtIndex(ssize_t index, ssize_t amount)
    void removeAllQuads()
    bool resizeCapacity(ssize_t capacity)
    void increaseTotalQuadsWith(ssize_t amount)
    void moveQuadsFromIndex(ssize_t oldIndex, ssize_t amount, ssize_t newIndex)
    void moveQuadsFromIndex(ssize_t index, ssize_t newIndex)
    void fillWithEmptyQuadsFromIndex(ssize_t index, ssize_t amount)
    bool isDirty()
    void setDirty(bool bDirty)
    std::string getDescription()
    size_t getTotalQuads()
    size_t getCapacity()
    cocos2d::Texture2D *getTexture()
    void setTexture(cocos2d::Texture2D *texture)
]]
cls.props [[
    dirty
    description
    totalQuads
    capacity
    texture
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
    void onOpen(cocos2d::network::WebSocket *ws)
    void onMessage(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::Data &data)
    void onClose(cocos2d::network::WebSocket *ws)
    void onError(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::ErrorCode &error)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::network::WebSocket'
cls.funcs [[
    static void closeAllConnections()
    WebSocket()
    void send(const std::string &message)
    void send(const unsigned char *binaryMsg, unsigned int len)
    void close()
    void closeAsync()
    cocos2d::network::WebSocket::State getReadyState()
    const std::string &getUrl()
    const std::string &getProtocol()
]]
cls.func('init', [[{
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
    olua_addref(L, 1, "delegate", 2, OLUA_MODE_SINGLE);

    return 0;
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
    LuaWebSocketDelegate()
]]
cls.var('onOpen', [[@nullable @local std::function<void (network::WebSocket *)> onOpenCallback]])
cls.var('onMessage', [[@nullable @local std::function<void (network::WebSocket *, const network::WebSocket::Data &)> onMessageCallback]])
cls.var('onClose', [[@nullable @local std::function<void (network::WebSocket *)> onCloseCallback]])
cls.var('onError', [[@nullable @local std::function<void (network::WebSocket *, const network::WebSocket::ErrorCode &)> onErrorCallback]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionManager'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    ActionManager()
    void addAction(cocos2d::Action *action, cocos2d::Node *target, bool paused)
    void removeAllActions()
    void removeAllActionsFromTarget(cocos2d::Node *target)
    void removeAction(cocos2d::Action *action)
    void removeActionByTag(int tag, cocos2d::Node *target)
    void removeAllActionsByTag(int tag, cocos2d::Node *target)
    void removeActionsByFlags(unsigned int flags, cocos2d::Node *target)
    cocos2d::Action *getActionByTag(int tag, const cocos2d::Node *target)
    ssize_t getNumberOfRunningActionsInTarget(const cocos2d::Node *target)
    ssize_t getNumberOfRunningActions()
    size_t getNumberOfRunningActionsInTargetByTag(const cocos2d::Node *target, int tag)
    void pauseTarget(cocos2d::Node *target)
    void resumeTarget(cocos2d::Node *target)
    Vector<cocos2d::Node *> pauseAllRunningActions()
    void resumeTargets(const Vector<cocos2d::Node *> &targetsToResume)
    void update(float dt)
]]
cls.props [[
    numberOfRunningActions
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Component'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::Component *create()
    bool init()
    bool isEnabled()
    void setEnabled(bool enabled)
    const std::string &getName()
    void setName(const std::string &name)
    cocos2d::Node *getOwner()
    void setOwner(cocos2d::Node *owner)
    void update(float delta)
    bool serialize(void *r)
    void onEnter()
    void onExit()
    void onAdd()
    void onRemove()
    Component()
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
    static cocos2d::LuaComponent *create()
    LuaComponent()
]]
cls.var('onUpdate', [[@nullable @local std::function<void (float)> onUpdateCallback]])
cls.var('onEnter', [[@nullable @local std::function<void ()> onEnterCallback]])
cls.var('onExit', [[@nullable @local std::function<void ()> onExitCallback]])
cls.var('onAdd', [[@nullable @local std::function<void ()> onAddCallback]])
cls.var('onRemove', [[@nullable @local std::function<void ()> onRemoveCallback]])
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
}
]]
cls.const('INVALID_TAG', 'cocos2d::Node::INVALID_TAG', 'const int')
cls.funcs [[
    static cocos2d::Node *create()
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
    void setPosition(const cocos2d::Vec2 &position)
    void setPositionNormalized(const cocos2d::Vec2 &position)
    void setNormalizedPosition(const cocos2d::Vec2 &position)
    const cocos2d::Vec2 &getPosition()
    const cocos2d::Vec2 &getPositionNormalized()
    const cocos2d::Vec2 &getNormalizedPosition()
    void setPosition(float x, float y)
    void setPositionX(float x)
    float getPositionX()
    void setPositionY(float y)
    float getPositionY()
    void setPosition3D(const cocos2d::Vec3 &position)
    cocos2d::Vec3 getPosition3D()
    void setPositionZ(float positionZ)
    float getPositionZ()
    void setSkewX(float skewX)
    float getSkewX()
    void setSkewY(float skewY)
    float getSkewY()
    void setAnchorPoint(const cocos2d::Vec2 &anchorPoint)
    const cocos2d::Vec2 &getAnchorPoint()
    const cocos2d::Vec2 &getAnchorPointInPoints()
    void setContentSize(const cocos2d::Size &contentSize)
    const cocos2d::Size &getContentSize()
    void setVisible(bool visible)
    bool isVisible()
    void setRotation(float rotation)
    float getRotation()
    void setRotation3D(const cocos2d::Vec3 &rotation)
    cocos2d::Vec3 getRotation3D()
    void setRotationQuat(const cocos2d::Quaternion &quat)
    cocos2d::Quaternion getRotationQuat()
    void setRotationSkewX(float rotationX)
    float getRotationSkewX()
    void setRotationSkewY(float rotationY)
    float getRotationSkewY()
    void setIgnoreAnchorPointForPosition(bool ignore)
    bool isIgnoreAnchorPointForPosition()
    void addChild(@addref(children |) cocos2d::Node *child)
    void addChild(@addref(children |) cocos2d::Node *child, int localZOrder)
    void addChild(@addref(children |) cocos2d::Node *child, int localZOrder, int tag)
    void addChild(@addref(children |) cocos2d::Node *child, int localZOrder, const std::string &name)
    @addref(children |) cocos2d::Node *getChildByTag(int tag)
    @addref(children |) cocos2d::Node *getChildByName(const std::string &name)
    @addref(children |) Vector<cocos2d::Node *> &getChildren()
    ssize_t getChildrenCount()
    void setParent(cocos2d::Node *parent)
    cocos2d::Node *getParent()
    @delref(children | parent) void removeFromParent()
    @delref(children | parent) void removeFromParentAndCleanup(bool cleanup)
    void removeChild(@delref(children |) cocos2d::Node *child, @optional bool cleanup)
    @delref(children ~) void removeChildByTag(int tag, @optional bool cleanup)
    @delref(children ~) void removeChildByName(const std::string &name, @optional bool cleanup)
    @delref(children *) void removeAllChildren()
    @delref(children *) void removeAllChildrenWithCleanup(bool cleanup)
    void reorderChild(cocos2d::Node *child, int localZOrder)
    void sortAllChildren()
    int getTag()
    void setTag(int tag)
    const std::string &getName()
    void setName(const std::string &name)
    void *getUserData()
    void setUserData(void *userData)
    cocos2d::Ref *getUserObject()
    void setUserObject(cocos2d::Ref *userObject)
    bool isRunning()
    void onEnter()
    void onEnterTransitionDidFinish()
    void onExit()
    void onExitTransitionDidStart()
    void cleanup()
    void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
    void draw()
    void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags)
    void visit()
    cocos2d::Scene *getScene()
    cocos2d::Rect getBoundingBox()
    void setEventDispatcher(@addref(eventDispatcher ^) cocos2d::EventDispatcher *dispatcher)
    @addref(eventDispatcher ^) cocos2d::EventDispatcher *getEventDispatcher()
    void setActionManager(@addref(actionManager ^) cocos2d::ActionManager *actionManager)
    @addref(actionManager ^) cocos2d::ActionManager *getActionManager()
    @delref(actions ~) cocos2d::Action *runAction(@addref(actions |) cocos2d::Action *action)
    @delref(actions ~) void stopAllActions()
    @delref(actions ~) void stopAction(cocos2d::Action *action)
    @delref(actions ~) void stopActionByTag(int tag)
    @delref(actions ~) void stopAllActionsByTag(int tag)
    @delref(actions ~) void stopActionsByFlags(unsigned int flags)
    @addref(actions |) cocos2d::Action *getActionByTag(int tag)
    ssize_t getNumberOfRunningActions()
    ssize_t getNumberOfRunningActionsByTag(int tag)
    void setScheduler(@addref(scheduler ^) cocos2d::Scheduler *scheduler)
    @addref(scheduler ^) cocos2d::Scheduler *getScheduler()
    bool isScheduled(const std::string &key)
    void scheduleUpdate()
    void scheduleUpdateWithPriority(int priority)
    void unscheduleUpdate()
    void resume()
    void pause()
    void update(float delta)
    void updateTransform()
    const cocos2d::Mat4 &getNodeToParentTransform()
    cocos2d::AffineTransform getNodeToParentAffineTransform()
    cocos2d::Mat4 getNodeToParentTransform(cocos2d::Node *ancestor)
    cocos2d::AffineTransform getNodeToParentAffineTransform(cocos2d::Node *ancestor)
    void setNodeToParentTransform(const cocos2d::Mat4 &transform)
    const cocos2d::Mat4 &getParentToNodeTransform()
    cocos2d::AffineTransform getParentToNodeAffineTransform()
    cocos2d::Mat4 getNodeToWorldTransform()
    cocos2d::AffineTransform getNodeToWorldAffineTransform()
    cocos2d::Mat4 getWorldToNodeTransform()
    cocos2d::AffineTransform getWorldToNodeAffineTransform()
    cocos2d::Vec2 convertToNodeSpace(@pack const cocos2d::Vec2 &worldPoint)
    cocos2d::Vec2 convertToWorldSpace(@pack const cocos2d::Vec2 &nodePoint)
    cocos2d::Vec2 convertToNodeSpaceAR(@pack const cocos2d::Vec2 &worldPoint)
    cocos2d::Vec2 convertToWorldSpaceAR(@pack const cocos2d::Vec2 &nodePoint)
    cocos2d::Vec2 convertTouchToNodeSpace(cocos2d::Touch *touch)
    cocos2d::Vec2 convertTouchToNodeSpaceAR(cocos2d::Touch *touch)
    void setAdditionalTransform(const cocos2d::Mat4 &additionalTransform)
    void setAdditionalTransform(const cocos2d::AffineTransform &additionalTransform)
    @addref(components |) cocos2d::Component *getComponent(const std::string &name)
    bool addComponent(@addref(components |) cocos2d::Component *component)
    @delref(components ~) bool removeComponent(const std::string &name)
    @delref(components ~) bool removeComponent(cocos2d::Component *component)
    @delref(components *) void removeAllComponents()
    uint8_t getOpacity()
    uint8_t getDisplayedOpacity()
    void setOpacity(uint8_t opacity)
    void updateDisplayedOpacity(uint8_t parentOpacity)
    bool isCascadeOpacityEnabled()
    void setCascadeOpacityEnabled(bool cascadeOpacityEnabled)
    const cocos2d::Color3B &getColor()
    const cocos2d::Color3B &getDisplayedColor()
    void setColor(const cocos2d::Color3B &color)
    void updateDisplayedColor(const cocos2d::Color3B &parentColor)
    bool isCascadeColorEnabled()
    void setCascadeColorEnabled(bool cascadeColorEnabled)
    void setOpacityModifyRGB(bool value)
    bool isOpacityModifyRGB()
    unsigned short getCameraMask()
    void setCameraMask(unsigned short mask, @optional bool applyChildren)
    void setProgramState(@addref(programState ^) cocos2d::backend::ProgramState *programState)
    @addref(programState ^) cocos2d::backend::ProgramState *getProgramState()
    Node()
    bool init()
    void setPhysicsBody(@addref(physicsBody ^) cocos2d::PhysicsBody *physicsBody)
    @addref(physicsBody ^) cocos2d::PhysicsBody *getPhysicsBody()
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
}]])
cls.prop('x', 'float getPositionX()', 'void setPositionX(float x)')
cls.prop('y', 'float getPositionY()', 'void setPositionY(float y)')
cls.prop('z', 'float getPositionZ()', 'void setPositionZ(float z)')
cls.prop('anchorX', [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getAnchorPoint().x);
    return 1;
}]], [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Vec2 anchor = self->getAnchorPoint();
    anchor.x = olua_checknumber(L, 2);
    self->setAnchorPoint(anchor);
    return 0;
}]])
cls.prop('anchorY', [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getAnchorPoint().y);
    return 1;
}]], [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Vec2 anchor = self->getAnchorPoint();
    anchor.y = olua_checknumber(L, 2);
    self->setAnchorPoint(anchor);
    return 0;
}]])
cls.prop('width', [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getContentSize().width);
    return 1;
}]], [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Size size = self->getContentSize();
    size.width = olua_checknumber(L, 2);
    self->setContentSize(size);
    return 0;
}]])
cls.prop('height', [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getContentSize().height);
    return 1;
}]], [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    cocos2d::Size size = self->getContentSize();
    size.height = olua_checknumber(L, 2);
    self->setContentSize(size);
    return 0;
}]])
cls.prop('alpha', [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    lua_pushnumber(L, self->getOpacity() / 255.0f);
    return 1;
}]], [[
{
    auto self = olua_toobj<cocos2d::Node>(L, 1);
    self->setOpacity(olua_checknumber(L, 2) * 255.0f);
    return 0;
}]])
cls.callback {
    FUNCS =  {
        'void setOnEnterCallback(@nullable @local const std::function<void ()> &callback)'
    },
    TAG_MAKER = 'OnEnterCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        '@nullable @local const std::function<void ()> &getOnEnterCallback()'
    },
    TAG_MAKER = 'OnEnterCallback',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setOnExitCallback(@nullable @local const std::function<void ()> &callback)'
    },
    TAG_MAKER = 'OnExitCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        '@nullable @local const std::function<void ()> &getOnExitCallback()'
    },
    TAG_MAKER = 'OnExitCallback',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setOnEnterTransitionDidFinishCallback(@nullable @local const std::function<void ()> &callback)'
    },
    TAG_MAKER = 'OnEnterTransitionDidFinishCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        '@nullable @local const std::function<void ()> &getOnEnterTransitionDidFinishCallback()'
    },
    TAG_MAKER = 'OnEnterTransitionDidFinishCallback',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setOnExitTransitionDidStartCallback(@nullable @local const std::function<void ()> &callback)'
    },
    TAG_MAKER = 'OnExitTransitionDidStartCallback',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        '@nullable @local const std::function<void ()> &getOnExitTransitionDidStartCallback()'
    },
    TAG_MAKER = 'OnExitTransitionDidStartCallback',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void scheduleOnce(@local const std::function<void (float)> &callback, float delay, const std::string &key)'
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'void schedule(@local const std::function<void (float)> &callback, const std::string &key)',
        'void schedule(@local const std::function<void (float)> &callback, float interval, const std::string &key)',
        'void schedule(@local const std::function<void (float)> &callback, float interval, unsigned int repeat, float delay, const std::string &key)'
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void unschedule(const std::string &key)'
    },
    TAG_MAKER = 'makeScheduleCallbackTag(#1)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void unscheduleAllCallbacks()'
    },
    TAG_MAKER = 'makeScheduleCallbackTag("")',
    TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.inject('removeFromParent', {
    BEFORE = [[
        if (!self->getParent()) {
            return 0;
        }
        olua_push_cppobj<cocos2d::Node>(L, self->getParent());
        int parent = lua_gettop(L);
    ]],
})
cls.inject('removeFromParentAndCleanup', {
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
    programState
    physicsBody
    onEnterCallback
    onExitCallback
    onEnterTransitionDidFinishCallback
    onExitTransitionDidStartCallback
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LuaTweenNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    void updateTweenAction(float value, const std::string &key)
]]
cls.callback {
    FUNCS =  {
        'static cocos2d::LuaTweenNode *create(@local const std::function<void (float, const std::string &)> &callback)'
    },
    TAG_MAKER = 'ActionTween',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = "return",
    TAG_SCOPE = 'object',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AtlasNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::AtlasNode *create(const std::string &filename, int tileWidth, int tileHeight, int itemsToRender)
    void updateAtlasValues()
    cocos2d::Texture2D *getTexture()
    void setTexture(cocos2d::Texture2D *texture)
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    const cocos2d::BlendFunc &getBlendFunc()
    void setTextureAtlas(cocos2d::TextureAtlas *textureAtlas)
    cocos2d::TextureAtlas *getTextureAtlas()
    void setQuadsToDraw(ssize_t quadsToDraw)
    size_t getQuadsToDraw()
    AtlasNode()
    bool initWithTileFile(const std::string &tile, int tileWidth, int tileHeight, int itemsToRender)
    bool initWithTexture(cocos2d::Texture2D *texture, int tileWidth, int tileHeight, int itemsToRender)
]]
cls.props [[
    texture
    blendFunc
    textureAtlas
    quadsToDraw
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::sImageTGA'
cls.funcs [[
]]
cls.var('status', [[int status]])
cls.var('type', [[unsigned char type]])
cls.var('pixelDepth', [[unsigned char pixelDepth]])
cls.var('width', [[short width]])
cls.var('height', [[short height]])
cls.var('imageData', [[unsigned char *imageData]])
cls.var('flipped', [[int flipped]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TileMapAtlas'
cls.SUPERCLS = "cocos2d::AtlasNode"
cls.funcs [[
    static cocos2d::TileMapAtlas *create(const std::string &tile, const std::string &mapFile, int tileWidth, int tileHeight)
    TileMapAtlas()
    bool initWithTileFile(const std::string &tile, const std::string &mapFile, int tileWidth, int tileHeight)
    cocos2d::Color3B getTileAt(const cocos2d::Vec2 &position)
    void setTile(const cocos2d::Color3B &tile, const cocos2d::Vec2 &position)
    void releaseMap()
    struct cocos2d::sImageTGA *getTGAInfo()
    void setTGAInfo(struct cocos2d::sImageTGA *TGAInfo)
]]
cls.props [[
    tgaInfo
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ClippingNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::ClippingNode *create()
    static cocos2d::ClippingNode *create(cocos2d::Node *stencil)
    cocos2d::Node *getStencil()
    void setStencil(cocos2d::Node *stencil)
    bool hasContent()
    float getAlphaThreshold()
    void setAlphaThreshold(float alphaThreshold)
    bool isInverted()
    void setInverted(bool inverted)
    ClippingNode()
    bool init(cocos2d::Node *stencil)
]]
cls.props [[
    stencil
    alphaThreshold
    inverted
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MotionStreak'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::MotionStreak *create(float timeToFade, float minSeg, float strokeWidth, const cocos2d::Color3B &strokeColor, const std::string &imagePath)
    static cocos2d::MotionStreak *create(float timeToFade, float minSeg, float strokeWidth, const cocos2d::Color3B &strokeColor, cocos2d::Texture2D *texture)
    cocos2d::Texture2D *getTexture()
    void setTexture(cocos2d::Texture2D *texture)
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    const cocos2d::BlendFunc &getBlendFunc()
    void tintWithColor(const cocos2d::Color3B &colors)
    void reset()
    bool isFastMode()
    void setFastMode(bool bFastMode)
    float getStroke()
    void setStroke(float stroke)
    bool isStartingPositionInitialized()
    void setStartingPositionInitialized(bool bStartingPositionInitialized)
    MotionStreak()
    bool initWithFade(float fade, float minSeg, float stroke, const cocos2d::Color3B &color, const std::string &path)
    bool initWithFade(float fade, float minSeg, float stroke, const cocos2d::Color3B &color, cocos2d::Texture2D *texture)
]]
cls.props [[
    texture
    blendFunc
    fastMode
    stroke
    startingPositionInitialized
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProtectedNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::ProtectedNode *create()
    void addProtectedChild(@addref(protectedChildren |) cocos2d::Node *child)
    void addProtectedChild(@addref(protectedChildren |) cocos2d::Node *child, int localZOrder)
    void addProtectedChild(@addref(protectedChildren |) cocos2d::Node *child, int localZOrder, int tag)
    @addref(protectedChildren |) cocos2d::Node *getProtectedChildByTag(int tag)
    void removeProtectedChild(@delref(protectedChildren |) cocos2d::Node *child, @optional bool cleanup)
    @delref(protectedChildren ~) void removeProtectedChildByTag(int tag, @optional bool cleanup)
    @delref(protectedChildren *) void removeAllProtectedChildren()
    @delref(protectedChildren *) void removeAllProtectedChildrenWithCleanup(bool cleanup)
    void reorderProtectedChild(cocos2d::Node *child, int localZOrder)
    void sortAllProtectedChildren()
    void disableCascadeColor()
    void disableCascadeOpacity()
    ProtectedNode()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::DrawNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::DrawNode *create(@optional float defaultLineWidth)
    void drawPoint(const cocos2d::Vec2 &point, const float pointSize, const cocos2d::Color4F &color)
    void drawLine(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &destination, const cocos2d::Color4F &color)
    void drawRect(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &destination, const cocos2d::Color4F &color)
    void drawCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, bool drawLineToCenter, float scaleX, float scaleY, const cocos2d::Color4F &color)
    void drawCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, bool drawLineToCenter, const cocos2d::Color4F &color)
    void drawQuadBezier(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &control, const cocos2d::Vec2 &destination, unsigned int segments, const cocos2d::Color4F &color)
    void drawCubicBezier(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &control1, const cocos2d::Vec2 &control2, const cocos2d::Vec2 &destination, unsigned int segments, const cocos2d::Color4F &color)
    void drawCardinalSpline(cocos2d::PointArray *config, float tension, unsigned int segments, const cocos2d::Color4F &color)
    void drawCatmullRom(cocos2d::PointArray *points, unsigned int segments, const cocos2d::Color4F &color)
    void drawDot(const cocos2d::Vec2 &pos, float radius, const cocos2d::Color4F &color)
    void drawRect(const cocos2d::Vec2 &p1, const cocos2d::Vec2 &p2, const cocos2d::Vec2 &p3, const cocos2d::Vec2 &p4, const cocos2d::Color4F &color)
    void drawSolidRect(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &destination, const cocos2d::Color4F &color)
    void drawSolidCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, float scaleX, float scaleY, const cocos2d::Color4F &color)
    void drawSolidCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, const cocos2d::Color4F &color)
    void drawSegment(const cocos2d::Vec2 &from, const cocos2d::Vec2 &to, float radius, const cocos2d::Color4F &color)
    void drawTriangle(const cocos2d::Vec2 &p1, const cocos2d::Vec2 &p2, const cocos2d::Vec2 &p3, const cocos2d::Color4F &color)
    void clear()
    const cocos2d::BlendFunc &getBlendFunc()
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    void setLineWidth(float lineWidth)
    float getLineWidth()
    void setIsolated(bool isolated)
    bool isIsolated()
    DrawNode(@optional float lineWidth)
]]
cls.props [[
    blendFunc
    lineWidth
    isolated
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParallaxNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::ParallaxNode *create()
    void addChild(cocos2d::Node *child, int z, const cocos2d::Vec2 &parallaxRatio, const cocos2d::Vec2 &positionOffset)
    ParallaxNode()
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
    static cocos2d::Label *create()
    static cocos2d::Label *createWithSystemFont(const std::string &text, const std::string &font, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)
    static cocos2d::Label *createWithTTF(const std::string &text, const std::string &fontFilePath, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)
    static cocos2d::Label *createWithTTF(const cocos2d::TTFConfig &ttfConfig, const std::string &text, @optional cocos2d::TextHAlignment hAlignment, @optional int maxLineWidth)
    static cocos2d::Label *createWithBMFont(const std::string &bmfontPath, const std::string &text, @optional const cocos2d::TextHAlignment &hAlignment, @optional int maxLineWidth)
    static cocos2d::Label *createWithBMFont(const std::string &bmfontPath, const std::string &text, const cocos2d::TextHAlignment &hAlignment, int maxLineWidth, const cocos2d::Rect &imageRect, bool imageRotated)
    static cocos2d::Label *createWithBMFont(const std::string &bmfontPath, const std::string &text, const cocos2d::TextHAlignment &hAlignment, int maxLineWidth, const std::string &subTextureKey)
    static cocos2d::Label *createWithCharMap(const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)
    static cocos2d::Label *createWithCharMap(cocos2d::Texture2D *texture, int itemWidth, int itemHeight, int startCharMap)
    static cocos2d::Label *createWithCharMap(const std::string &plistFile)
    bool setTTFConfig(const cocos2d::TTFConfig &ttfConfig)
    const cocos2d::TTFConfig &getTTFConfig()
    bool setBMFontFilePath(const std::string &bmfontFilePath, @optional float fontSize)
    bool setBMFontFilePath(const std::string &bmfontFilePath, const cocos2d::Rect &imageRect, bool imageRotated, @optional float fontSize)
    bool setBMFontFilePath(const std::string &bmfontFilePath, const std::string &subTextureKey, @optional float fontSize)
    const std::string &getBMFontFilePath()
    bool setCharMap(const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)
    bool setCharMap(cocos2d::Texture2D *texture, int itemWidth, int itemHeight, int startCharMap)
    bool setCharMap(const std::string &plistFile)
    void setSystemFontName(const std::string &font)
    const std::string &getSystemFontName()
    void setSystemFontSize(float fontSize)
    float getSystemFontSize()
    void requestSystemFontRefresh()
    void setString(const std::string &text)
    const std::string &getString()
    int getStringNumLines()
    int getStringLength()
    void setTextColor(const cocos2d::Color4B &color)
    const cocos2d::Color4B &getTextColor()
    void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)
    void enableOutline(const cocos2d::Color4B &outlineColor, @optional int outlineSize)
    void enableGlow(const cocos2d::Color4B &glowColor)
    void enableItalics()
    void enableBold()
    void enableUnderline()
    void enableStrikethrough()
    void disableEffect()
    void disableEffect(cocos2d::LabelEffect effect)
    bool isShadowEnabled()
    cocos2d::Size getShadowOffset()
    float getShadowBlurRadius()
    cocos2d::Color4F getShadowColor()
    float getOutlineSize()
    cocos2d::LabelEffect getLabelEffectType()
    cocos2d::Color4F getEffectColor()
    void setAlignment(cocos2d::TextHAlignment hAlignment)
    cocos2d::TextHAlignment getTextAlignment()
    void setAlignment(cocos2d::TextHAlignment hAlignment, cocos2d::TextVAlignment vAlignment)
    void setHorizontalAlignment(cocos2d::TextHAlignment hAlignment)
    cocos2d::TextHAlignment getHorizontalAlignment()
    void setVerticalAlignment(cocos2d::TextVAlignment vAlignment)
    cocos2d::TextVAlignment getVerticalAlignment()
    void setLineBreakWithoutSpace(bool breakWithoutSpace)
    void setMaxLineWidth(float maxLineWidth)
    float getMaxLineWidth()
    void setBMFontSize(float fontSize)
    float getBMFontSize()
    void enableWrap(bool enable)
    bool isWrapEnabled()
    void setOverflow(cocos2d::Label::Overflow overflow)
    cocos2d::Label::Overflow getOverflow()
    void setWidth(float width)
    float getWidth()
    void setHeight(float height)
    float getHeight()
    void setDimensions(float width, float height)
    const cocos2d::Size &getDimensions()
    void updateContent()
    cocos2d::Sprite *getLetter(int lettetIndex)
    void setClipMarginEnabled(bool clipEnabled)
    bool isClipMarginEnabled()
    void setLineHeight(float height)
    float getLineHeight()
    void setLineSpacing(float height)
    float getLineSpacing()
    cocos2d::Label::LabelType getLabelType()
    float getRenderingFontSize()
    void setAdditionalKerning(float space)
    float getAdditionalKerning()
    cocos2d::FontAtlas *getFontAtlas()
    const cocos2d::BlendFunc &getBlendFunc()
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    Label(@optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)
    bool initWithTTF(const std::string &text, const std::string &fontFilePath, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)
    bool initWithTTF(const cocos2d::TTFConfig &ttfConfig, const std::string &text, @optional cocos2d::TextHAlignment hAlignment, @optional int maxLineWidth)
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
    static cocos2d::LabelAtlas *create()
    static cocos2d::LabelAtlas *create(const std::string &string, const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)
    static cocos2d::LabelAtlas *create(const std::string &string, const std::string &fntFile)
    bool initWithString(const std::string &string, const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)
    bool initWithString(const std::string &string, const std::string &fntFile)
    bool initWithString(const std::string &string, cocos2d::Texture2D *texture, int itemWidth, int itemHeight, int startCharMap)
    void setString(const std::string &label)
    const std::string &getString()
    LabelAtlas()
]]
cls.props [[
    string
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FontAtlas'
cls.SUPERCLS = "cocos2d::Ref"
cls.const('CacheTextureWidth', 'cocos2d::FontAtlas::CacheTextureWidth', 'const int')
cls.const('CacheTextureHeight', 'cocos2d::FontAtlas::CacheTextureHeight', 'const int')
cls.funcs [[
    void addTexture(cocos2d::Texture2D *texture, int slot)
    float getLineHeight()
    void setLineHeight(float newHeight)
    std::string getFontName()
    cocos2d::Texture2D *getTexture(int slot)
    void listenRendererRecreated(cocos2d::EventCustom *event)
    void purgeTexturesAtlas()
    void setAntiAliasTexParameters()
    void setAliasTexParameters()
]]
cls.var('CMD_PURGE_FONTATLAS', [[static const char *CMD_PURGE_FONTATLAS]])
cls.var('CMD_RESET_FONTATLAS', [[static const char *CMD_RESET_FONTATLAS]])
cls.props [[
    lineHeight
    fontName
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ClippingRectangleNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::ClippingRectangleNode *create(const cocos2d::Rect &clippingRegion)
    static cocos2d::ClippingRectangleNode *create()
    const cocos2d::Rect &getClippingRegion()
    void setClippingRegion(const cocos2d::Rect &clippingRegion)
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
    static cocos2d::RenderTexture *create(int w, int h, cocos2d::backend::PixelFormat format, cocos2d::backend::PixelFormat depthStencilFormat)
    static cocos2d::RenderTexture *create(int w, int h, cocos2d::backend::PixelFormat format)
    static cocos2d::RenderTexture *create(int w, int h)
    void begin()
    void beginWithClear(float r, float g, float b, float a)
    void beginWithClear(float r, float g, float b, float a, float depthValue)
    void beginWithClear(float r, float g, float b, float a, float depthValue, int stencilValue)
    void end()
    void clear(float r, float g, float b, float a)
    void clearDepth(float depthValue)
    void clearStencil(int stencilValue)
    void listenToBackground(cocos2d::EventCustom *event)
    void listenToForeground(cocos2d::EventCustom *event)
    cocos2d::ClearFlag getClearFlags()
    void setClearFlags(cocos2d::ClearFlag clearFlags)
    const cocos2d::Color4F &getClearColor()
    void setClearColor(const cocos2d::Color4F &clearColor)
    float getClearDepth()
    void setClearDepth(float clearDepth)
    int getClearStencil()
    void setClearStencil(int clearStencil)
    bool isAutoDraw()
    void setAutoDraw(bool isAutoDraw)
    cocos2d::Sprite *getSprite()
    void setSprite(cocos2d::Sprite *sprite)
    void setKeepMatrix(bool keepMatrix)
    void setVirtualViewport(const cocos2d::Vec2 &rtBegin, const cocos2d::Rect &fullRect, const cocos2d::Rect &fullViewport)
    RenderTexture()
    bool initWithWidthAndHeight(int w, int h, cocos2d::backend::PixelFormat format)
    bool initWithWidthAndHeight(int w, int h, cocos2d::backend::PixelFormat format, cocos2d::backend::PixelFormat depthStencilFormat)
]]
cls.callback {
    FUNCS =  {
        'bool saveToFile(const std::string &filename, @optional bool isRGBA, @optional std::function<void (RenderTexture *, const std::string &)> callback)',
        'bool saveToFile(const std::string &filename, cocos2d::Image::Format format, @optional bool isRGBA, @optional std::function<void (RenderTexture *, const std::string &)> callback)'
    },
    TAG_MAKER = 'saveToFile',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'bool saveToFileAsNonPMA(const std::string &filename, @optional bool isRGBA, @optional std::function<void (RenderTexture *, const std::string &)> callback)',
        'bool saveToFileAsNonPMA(const std::string &fileName, cocos2d::Image::Format format, bool isRGBA, std::function<void (RenderTexture *, const std::string &)> callback)'
    },
    TAG_MAKER = 'saveToFile',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'void newImage(std::function<void (Image *)> imageCallback, @optional bool flipImage)'
    },
    TAG_MAKER = 'newImage',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.alias('begin', 'beginVisit')
cls.alias('end', 'endVisit')
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
    static cocos2d::ProgressTimer *create(cocos2d::Sprite *sp)
    cocos2d::ProgressTimer::Type getType()
    float getPercentage()
    cocos2d::Sprite *getSprite()
    void setPercentage(float percentage)
    void setSprite(cocos2d::Sprite *sprite)
    void setType(cocos2d::ProgressTimer::Type type)
    bool isReverseDirection()
    void setReverseDirection(bool value)
    void setMidpoint(const cocos2d::Vec2 &point)
    cocos2d::Vec2 getMidpoint()
    void setBarChangeRate(const cocos2d::Vec2 &barChangeRate)
    cocos2d::Vec2 getBarChangeRate()
    ProgressTimer()
    bool initWithSprite(cocos2d::Sprite *sp)
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
    static cocos2d::AnimationFrame *create(cocos2d::SpriteFrame *spriteFrame, float delayUnits, const cocos2d::ValueMap &userInfo)
    cocos2d::SpriteFrame *getSpriteFrame()
    void setSpriteFrame(cocos2d::SpriteFrame *frame)
    float getDelayUnits()
    void setDelayUnits(float delayUnits)
    const cocos2d::ValueMap &getUserInfo()
    void setUserInfo(const cocos2d::ValueMap &userInfo)
    cocos2d::AnimationFrame *clone()
    AnimationFrame()
    bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, float delayUnits, const cocos2d::ValueMap &userInfo)
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
    static cocos2d::Animation *create()
    static cocos2d::Animation *createWithSpriteFrames(const Vector<cocos2d::SpriteFrame *> &arrayOfSpriteFrameNames, @optional float delay, @optional unsigned int loops)
    static cocos2d::Animation *create(const Vector<cocos2d::AnimationFrame *> &arrayOfAnimationFrameNames, float delayPerUnit, @optional unsigned int loops)
    void addSpriteFrame(cocos2d::SpriteFrame *frame)
    void addSpriteFrameWithFile(const std::string &filename)
    void addSpriteFrameWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect)
    float getTotalDelayUnits()
    void setDelayPerUnit(float delayPerUnit)
    float getDelayPerUnit()
    float getDuration()
    const Vector<cocos2d::AnimationFrame *> &getFrames()
    void setFrames(const Vector<cocos2d::AnimationFrame *> &frames)
    bool getRestoreOriginalFrame()
    void setRestoreOriginalFrame(bool restoreOriginalFrame)
    unsigned int getLoops()
    void setLoops(unsigned int loops)
    cocos2d::Animation *clone()
    Animation()
    bool init()
    bool initWithSpriteFrames(const Vector<cocos2d::SpriteFrame *> &arrayOfSpriteFrameNames, @optional float delay, @optional unsigned int loops)
    bool initWithAnimationFrames(const Vector<cocos2d::AnimationFrame *> &arrayOfAnimationFrameNames, float delayPerUnit, unsigned int loops)
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
    static cocos2d::SpriteFrame *create(const std::string &filename, const cocos2d::Rect &rect)
    static cocos2d::SpriteFrame *create(const std::string &filename, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)
    static cocos2d::SpriteFrame *createWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect)
    static cocos2d::SpriteFrame *createWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)
    const cocos2d::Rect &getRectInPixels()
    void setRectInPixels(const cocos2d::Rect &rectInPixels)
    bool isRotated()
    void setRotated(bool rotated)
    const cocos2d::Rect &getRect()
    void setRect(const cocos2d::Rect &rect)
    const cocos2d::Rect &getCenterRect()
    void setCenterRectInPixels(const cocos2d::Rect &centerRect)
    bool hasCenterRect()
    const cocos2d::Vec2 &getOffsetInPixels()
    void setOffsetInPixels(const cocos2d::Vec2 &offsetInPixels)
    const cocos2d::Size &getOriginalSizeInPixels()
    void setOriginalSizeInPixels(const cocos2d::Size &sizeInPixels)
    const cocos2d::Size &getOriginalSize()
    void setOriginalSize(const cocos2d::Size &sizeInPixels)
    cocos2d::Texture2D *getTexture()
    void setTexture(cocos2d::Texture2D *pobTexture)
    const cocos2d::Vec2 &getOffset()
    void setOffset(const cocos2d::Vec2 &offsets)
    const cocos2d::Vec2 &getAnchorPoint()
    void setAnchorPoint(const cocos2d::Vec2 &anchorPoint)
    bool hasAnchorPoint()
    cocos2d::SpriteFrame *clone()
    bool hasPolygonInfo()
    SpriteFrame()
    bool initWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect)
    bool initWithTextureFilename(const std::string &filename, const cocos2d::Rect &rect)
    bool initWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)
    bool initWithTextureFilename(const std::string &filename, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)
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
cls.const('INDEX_NOT_INITIALIZED', 'cocos2d::Sprite::INDEX_NOT_INITIALIZED', 'const int')
cls.funcs [[
    static cocos2d::Sprite *create()
    static cocos2d::Sprite *create(const std::string &filename)
    static cocos2d::Sprite *create(const std::string &filename, const cocos2d::Rect &rect)
    static cocos2d::Sprite *createWithTexture(cocos2d::Texture2D *texture)
    static cocos2d::Sprite *createWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect &rect, @optional bool rotated)
    static cocos2d::Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
    static cocos2d::Sprite *createWithSpriteFrameName(const std::string &spriteFrameName)
    cocos2d::SpriteBatchNode *getBatchNode()
    void setBatchNode(cocos2d::SpriteBatchNode *spriteBatchNode)
    void setTexture(const std::string &filename)
    void setTexture(cocos2d::Texture2D *texture)
    cocos2d::Texture2D *getTexture()
    void setTextureRect(const cocos2d::Rect &rect)
    void setTextureRect(const cocos2d::Rect &rect, bool rotated, const cocos2d::Size &untrimmedSize)
    void setVertexRect(const cocos2d::Rect &rect)
    void setCenterRectNormalized(const cocos2d::Rect &rect)
    cocos2d::Rect getCenterRectNormalized()
    void setCenterRect(const cocos2d::Rect &rect)
    cocos2d::Rect getCenterRect()
    void setSpriteFrame(const std::string &spriteFrameName)
    void setSpriteFrame(cocos2d::SpriteFrame *newFrame)
    bool isFrameDisplayed(cocos2d::SpriteFrame *frame)
    cocos2d::SpriteFrame *getSpriteFrame()
    void setDisplayFrameWithAnimationName(const std::string &animationName, unsigned int frameIndex)
    bool isDirty()
    void setDirty(bool dirty)
    bool isTextureRectRotated()
    unsigned int getAtlasIndex()
    void setAtlasIndex(unsigned int atlasIndex)
    const cocos2d::Rect &getTextureRect()
    cocos2d::TextureAtlas *getTextureAtlas()
    void setTextureAtlas(cocos2d::TextureAtlas *textureAtlas)
    const cocos2d::Vec2 &getOffsetPosition()
    bool isFlippedX()
    void setFlippedX(bool flippedX)
    bool isFlippedY()
    void setFlippedY(bool flippedY)
    void setStretchEnabled(bool enabled)
    bool isStretchEnabled()
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    const cocos2d::BlendFunc &getBlendFunc()
    int getResourceType()
    const std::string &getResourceName()
    Sprite()
    bool initWithTexture(cocos2d::Texture2D *texture)
    bool initWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect &rect)
    bool initWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect &rect, bool rotated)
    bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)
    bool initWithSpriteFrameName(const std::string &spriteFrameName)
    bool initWithFile(const std::string &filename)
    bool initWithFile(const std::string &filename, const cocos2d::Rect &rect)
    void setVertexLayout()
    void updateShaders(const char *vert, const char *frag)
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
    static cocos2d::SpriteBatchNode *createWithTexture(cocos2d::Texture2D *tex, @optional ssize_t capacity)
    static cocos2d::SpriteBatchNode *create(const std::string &fileImage, @optional ssize_t capacity)
    cocos2d::TextureAtlas *getTextureAtlas()
    void setTextureAtlas(cocos2d::TextureAtlas *textureAtlas)
    const std::vector<Sprite *> &getDescendants()
    void increaseAtlasCapacity()
    void removeChildAtIndex(ssize_t index, bool doCleanup)
    void appendChild(cocos2d::Sprite *sprite)
    void removeSpriteFromAtlas(cocos2d::Sprite *sprite)
    ssize_t rebuildIndexInOrder(cocos2d::Sprite *parent, ssize_t index)
    ssize_t highestAtlasIndexInChild(cocos2d::Sprite *sprite)
    ssize_t lowestAtlasIndexInChild(cocos2d::Sprite *sprite)
    ssize_t atlasIndexForChild(cocos2d::Sprite *sprite, int z)
    void reorderBatch(bool reorder)
    cocos2d::Texture2D *getTexture()
    void setTexture(cocos2d::Texture2D *texture)
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    const cocos2d::BlendFunc &getBlendFunc()
    void insertQuadFromSprite(cocos2d::Sprite *sprite, ssize_t index)
    cocos2d::SpriteBatchNode *addSpriteWithoutQuad(cocos2d::Sprite *child, int z, int aTag)
    void reserveCapacity(ssize_t newCapacity)
    SpriteBatchNode()
    bool initWithTexture(cocos2d::Texture2D *tex, @optional ssize_t capacity)
    bool initWithFile(const std::string &fileImage, @optional ssize_t capacity)
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
    static cocos2d::SpriteFrameCache *getInstance()
    static void destroyInstance()
    bool init()
    void addSpriteFramesWithFile(const std::string &plist)
    void addSpriteFramesWithFile(const std::string &plist, const std::string &textureFileName)
    void addSpriteFramesWithFile(const std::string &plist, cocos2d::Texture2D *texture)
    void addSpriteFramesWithFileContent(const std::string &plist_content, cocos2d::Texture2D *texture)
    void addSpriteFrame(cocos2d::SpriteFrame *frame, const std::string &frameName)
    bool isSpriteFramesWithFileLoaded(const std::string &plist)
    void removeSpriteFrames()
    void removeUnusedSpriteFrames()
    void removeSpriteFrameByName(const std::string &name)
    void removeSpriteFramesFromFile(const std::string &plist)
    void removeSpriteFramesFromFileContent(const std::string &plist_content)
    void removeSpriteFramesFromTexture(cocos2d::Texture2D *texture)
    cocos2d::SpriteFrame *getSpriteFrameByName(const std::string &name)
    bool reloadTexture(const std::string &plist)
]]
cls.props [[
    instance
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AnimationCache'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    AnimationCache()
    static cocos2d::AnimationCache *getInstance()
    static void destroyInstance()
    bool init()
    void addAnimation(cocos2d::Animation *animation, const std::string &name)
    void removeAnimation(const std::string &name)
    cocos2d::Animation *getAnimation(const std::string &name)
    void addAnimationsWithDictionary(const cocos2d::ValueMap &dictionary, const std::string &plist)
    void addAnimationsWithFile(const std::string &plist)
]]
cls.props [[
    instance
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Scene'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::Scene *create()
    static cocos2d::Scene *createWithSize(const cocos2d::Size &size)
    const std::vector<Camera *> &getCameras()
    cocos2d::Camera *getDefaultCamera()
    const std::vector<BaseLight *> &getLights()
    Scene()
    bool initWithSize(const cocos2d::Size &size)
    void setCameraOrderDirty()
    void onProjectionChanged(cocos2d::EventCustom *event)
    @addref(physicsWorld ^) cocos2d::PhysicsWorld *getPhysicsWorld()
    void setPhysics3DDebugCamera(cocos2d::Camera *camera)
    static cocos2d::Scene *createWithPhysics()
    bool initWithPhysics()
    void setNavMeshDebugCamera(cocos2d::Camera *camera)
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
    static cocos2d::Layer *create()
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
    void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event)
    void onTouchesBegan(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
    void onTouchesMoved(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
    void onTouchesEnded(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
    void onTouchesCancelled(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
    void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *unused_event)
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
    Layer()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LayerColor'
cls.SUPERCLS = "cocos2d::Layer"
cls.funcs [[
    static cocos2d::LayerColor *create()
    static cocos2d::LayerColor *create(const cocos2d::Color4B &color, float width, float height)
    static cocos2d::LayerColor *create(const cocos2d::Color4B &color)
    void changeWidth(float w)
    void changeHeight(float h)
    void changeWidthAndHeight(float w, float h)
    const cocos2d::BlendFunc &getBlendFunc()
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    LayerColor()
    bool initWithColor(const cocos2d::Color4B &color, float width, float height)
    bool initWithColor(const cocos2d::Color4B &color)
]]
cls.props [[
    blendFunc
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LayerGradient'
cls.SUPERCLS = "cocos2d::LayerColor"
cls.funcs [[
    static cocos2d::LayerGradient *create()
    static cocos2d::LayerGradient *create(const cocos2d::Color4B &start, const cocos2d::Color4B &end)
    static cocos2d::LayerGradient *create(const cocos2d::Color4B &start, const cocos2d::Color4B &end, const cocos2d::Vec2 &v)
    void setCompressedInterpolation(bool compressedInterpolation)
    bool isCompressedInterpolation()
    void setStartColor(const cocos2d::Color3B &startColor)
    const cocos2d::Color3B &getStartColor()
    void setEndColor(const cocos2d::Color3B &endColor)
    const cocos2d::Color3B &getEndColor()
    void setStartOpacity(uint8_t startOpacity)
    uint8_t getStartOpacity()
    void setEndOpacity(uint8_t endOpacity)
    uint8_t getEndOpacity()
    void setVector(const cocos2d::Vec2 &alongVector)
    const cocos2d::Vec2 &getVector()
    LayerGradient()
    bool initWithColor(const cocos2d::Color4B &start, const cocos2d::Color4B &end)
    bool initWithColor(const cocos2d::Color4B &start, const cocos2d::Color4B &end, const cocos2d::Vec2 &v)
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
    static cocos2d::LayerRadialGradient *create(const cocos2d::Color4B &startColor, const cocos2d::Color4B &endColor, float radius, const cocos2d::Vec2 &center, float expand)
    static cocos2d::LayerRadialGradient *create()
    void setStartOpacity(uint8_t opacity)
    uint8_t getStartOpacity()
    void setEndOpacity(uint8_t opacity)
    uint8_t getEndOpacity()
    void setRadius(float radius)
    float getRadius()
    void setCenter(const cocos2d::Vec2 &center)
    cocos2d::Vec2 getCenter()
    void setExpand(float expand)
    float getExpand()
    void setStartColor(const cocos2d::Color3B &color)
    void setStartColor(const cocos2d::Color4B &color)
    cocos2d::Color4B getStartColor()
    cocos2d::Color3B getStartColor3B()
    void setEndColor(const cocos2d::Color3B &color)
    void setEndColor(const cocos2d::Color4B &color)
    cocos2d::Color4B getEndColor()
    cocos2d::Color3B getEndColor3B()
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    cocos2d::BlendFunc getBlendFunc()
    LayerRadialGradient()
    bool initWithColor(const cocos2d::Color4B &startColor, const cocos2d::Color4B &endColor, float radius, const cocos2d::Vec2 &center, float expand)
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

cls = typecls 'cocos2d::LayerMultiplex'
cls.SUPERCLS = "cocos2d::Layer"
cls.funcs [[
    static cocos2d::LayerMultiplex *create()
    static cocos2d::LayerMultiplex *createWithArray(const Vector<cocos2d::Layer *> &arrayOfLayers)
    static cocos2d::LayerMultiplex *createWithLayer(cocos2d::Layer *layer)
    void addLayer(cocos2d::Layer *layer)
    void switchTo(int n)
    void switchTo(int n, bool cleanup)
    void switchToAndReleaseMe(int n)
    LayerMultiplex()
    bool initWithArray(const Vector<cocos2d::Layer *> &arrayOfLayers)
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
    static cocos2d::TransitionScene *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    void finish()
    void hideOutShowIn()
    cocos2d::Scene *getInScene()
    float getDuration()
    TransitionScene()
]]
cls.props [[
    inScene
    duration
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSceneOriented'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionSceneOriented *create(float t, @addref(autoref |) cocos2d::Scene *scene, cocos2d::TransitionScene::Orientation orientation)
    TransitionSceneOriented()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionRotoZoom'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionRotoZoom *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionRotoZoom()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionJumpZoom'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionJumpZoom *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionJumpZoom()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInL'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionMoveInL *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    cocos2d::ActionInterval *action()
    cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)
    TransitionMoveInL()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInR'
cls.SUPERCLS = "cocos2d::TransitionMoveInL"
cls.funcs [[
    static cocos2d::TransitionMoveInR *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionMoveInR()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInT'
cls.SUPERCLS = "cocos2d::TransitionMoveInL"
cls.funcs [[
    static cocos2d::TransitionMoveInT *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionMoveInT()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInB'
cls.SUPERCLS = "cocos2d::TransitionMoveInL"
cls.funcs [[
    static cocos2d::TransitionMoveInB *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionMoveInB()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInL'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionSlideInL *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)
    cocos2d::ActionInterval *action()
    TransitionSlideInL()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInR'
cls.SUPERCLS = "cocos2d::TransitionSlideInL"
cls.funcs [[
    static cocos2d::TransitionSlideInR *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionSlideInR()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInB'
cls.SUPERCLS = "cocos2d::TransitionSlideInL"
cls.funcs [[
    static cocos2d::TransitionSlideInB *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionSlideInB()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInT'
cls.SUPERCLS = "cocos2d::TransitionSlideInL"
cls.funcs [[
    static cocos2d::TransitionSlideInT *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionSlideInT()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionShrinkGrow'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionShrinkGrow *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)
    TransitionShrinkGrow()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFlipX'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static cocos2d::TransitionFlipX *create(float t, @addref(autoref |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)
    static cocos2d::TransitionFlipX *create(float t, @addref(autoref |) cocos2d::Scene *s)
    TransitionFlipX()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFlipY'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static cocos2d::TransitionFlipY *create(float t, @addref(autoref |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)
    static cocos2d::TransitionFlipY *create(float t, @addref(autoref |) cocos2d::Scene *s)
    TransitionFlipY()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFlipAngular'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static cocos2d::TransitionFlipAngular *create(float t, @addref(autoref |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)
    static cocos2d::TransitionFlipAngular *create(float t, @addref(autoref |) cocos2d::Scene *s)
    TransitionFlipAngular()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionZoomFlipX'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static cocos2d::TransitionZoomFlipX *create(float t, @addref(autoref |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)
    static cocos2d::TransitionZoomFlipX *create(float t, @addref(autoref |) cocos2d::Scene *s)
    TransitionZoomFlipX()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionZoomFlipY'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static cocos2d::TransitionZoomFlipY *create(float t, @addref(autoref |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)
    static cocos2d::TransitionZoomFlipY *create(float t, @addref(autoref |) cocos2d::Scene *s)
    TransitionZoomFlipY()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionZoomFlipAngular'
cls.SUPERCLS = "cocos2d::TransitionSceneOriented"
cls.funcs [[
    static cocos2d::TransitionZoomFlipAngular *create(float t, @addref(autoref |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)
    static cocos2d::TransitionZoomFlipAngular *create(float t, @addref(autoref |) cocos2d::Scene *s)
    TransitionZoomFlipAngular()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFade'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionFade *create(float duration, @addref(autoref |) cocos2d::Scene *scene, const cocos2d::Color3B &color)
    static cocos2d::TransitionFade *create(float duration, @addref(autoref |) cocos2d::Scene *scene)
    TransitionFade()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionCrossFade'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionCrossFade *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionCrossFade()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionTurnOffTiles'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionTurnOffTiles *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)
    TransitionTurnOffTiles()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSplitCols'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionSplitCols *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    cocos2d::ActionInterval *action()
    cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)
    TransitionSplitCols()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSplitRows'
cls.SUPERCLS = "cocos2d::TransitionSplitCols"
cls.funcs [[
    static cocos2d::TransitionSplitRows *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionSplitRows()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeTR'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionFadeTR *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    cocos2d::ActionInterval *actionWithSize(const cocos2d::Size &size)
    cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)
    TransitionFadeTR()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeBL'
cls.SUPERCLS = "cocos2d::TransitionFadeTR"
cls.funcs [[
    static cocos2d::TransitionFadeBL *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionFadeBL()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeUp'
cls.SUPERCLS = "cocos2d::TransitionFadeTR"
cls.funcs [[
    static cocos2d::TransitionFadeUp *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionFadeUp()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeDown'
cls.SUPERCLS = "cocos2d::TransitionFadeTR"
cls.funcs [[
    static cocos2d::TransitionFadeDown *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionFadeDown()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionPageTurn'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionPageTurn *create(float t, @addref(autoref |) cocos2d::Scene *scene, bool backwards)
    cocos2d::ActionInterval *actionWithSize(const cocos2d::Size &vector)
    TransitionPageTurn()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgress'
cls.SUPERCLS = "cocos2d::TransitionScene"
cls.funcs [[
    static cocos2d::TransitionProgress *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionProgress()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressRadialCCW'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static cocos2d::TransitionProgressRadialCCW *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionProgressRadialCCW()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressRadialCW'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static cocos2d::TransitionProgressRadialCW *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionProgressRadialCW()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressHorizontal'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static cocos2d::TransitionProgressHorizontal *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionProgressHorizontal()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressVertical'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static cocos2d::TransitionProgressVertical *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionProgressVertical()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressInOut'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static cocos2d::TransitionProgressInOut *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionProgressInOut()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressOutIn'
cls.SUPERCLS = "cocos2d::TransitionProgress"
cls.funcs [[
    static cocos2d::TransitionProgressOutIn *create(float t, @addref(autoref |) cocos2d::Scene *scene)
    TransitionProgressOutIn()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextFieldDelegate'
cls.funcs [[
    bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF *sender)
    bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF *sender)
    bool onTextFieldInsertText(cocos2d::TextFieldTTF *sender, const char *text, size_t nLen)
    bool onTextFieldDeleteBackward(cocos2d::TextFieldTTF *sender, const char *delText, size_t nLen)
    bool onVisit(cocos2d::TextFieldTTF *sender, cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextFieldTTF'
cls.SUPERCLS = "cocos2d::Label"
cls.funcs [[
    TextFieldTTF()
    static cocos2d::TextFieldTTF *textFieldWithPlaceHolder(const std::string &placeholder, const cocos2d::Size &dimensions, cocos2d::TextHAlignment alignment, const std::string &fontName, float fontSize)
    static cocos2d::TextFieldTTF *textFieldWithPlaceHolder(const std::string &placeholder, const std::string &fontName, float fontSize)
    bool initWithPlaceHolder(const std::string &placeholder, const cocos2d::Size &dimensions, cocos2d::TextHAlignment alignment, const std::string &fontName, float fontSize)
    bool initWithPlaceHolder(const std::string &placeholder, const std::string &fontName, float fontSize)
    bool attachWithIME()
    bool detachWithIME()
    cocos2d::TextFieldDelegate *getDelegate()
    void setDelegate(cocos2d::TextFieldDelegate *delegate)
    std::size_t getCharCount()
    const cocos2d::Color4B &getColorSpaceHolder()
    void setColorSpaceHolder(const cocos2d::Color3B &color)
    void setColorSpaceHolder(const cocos2d::Color4B &color)
    void appendString(const std::string &text)
    void setPlaceHolder(const std::string &text)
    const std::string &getPlaceHolder()
    void setSecureTextEntry(bool value)
    void setPasswordTextStyle(const std::string &text)
    const std::string &getPasswordTextStyle()
    bool isSecureTextEntry()
    void setCursorEnabled(bool enabled)
    void setCursorChar(char cursor)
    void setCursorPosition(std::size_t cursorPosition)
    void setCursorFromPoint(const cocos2d::Vec2 &point, const cocos2d::Camera *camera)
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
    cocos2d::LightType getLightType()
    float getIntensity()
    void setIntensity(float intensity)
    cocos2d::LightFlag getLightFlag()
    void setLightFlag(cocos2d::LightFlag flag)
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
    static cocos2d::DirectionLight *create(const cocos2d::Vec3 &direction, const cocos2d::Color3B &color)
    void setDirection(const cocos2d::Vec3 &dir)
    cocos2d::Vec3 getDirection()
    cocos2d::Vec3 getDirectionInWorld()
    DirectionLight()
]]
cls.props [[
    direction
    directionInWorld
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PointLight'
cls.SUPERCLS = "cocos2d::BaseLight"
cls.funcs [[
    static cocos2d::PointLight *create(const cocos2d::Vec3 &position, const cocos2d::Color3B &color, float range)
    float getRange()
    void setRange(float range)
    PointLight()
]]
cls.props [[
    range
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SpotLight'
cls.SUPERCLS = "cocos2d::BaseLight"
cls.funcs [[
    static cocos2d::SpotLight *create(const cocos2d::Vec3 &direction, const cocos2d::Vec3 &position, const cocos2d::Color3B &color, float innerAngle, float outerAngle, float range)
    void setDirection(const cocos2d::Vec3 &dir)
    cocos2d::Vec3 getDirection()
    cocos2d::Vec3 getDirectionInWorld()
    void setRange(float range)
    float getRange()
    void setInnerAngle(float angle)
    float getInnerAngle()
    float getCosInnerAngle()
    void setOuterAngle(float outerAngle)
    float getOuterAngle()
    float getCosOuterAngle()
    SpotLight()
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
    static cocos2d::AmbientLight *create(const cocos2d::Color3B &color)
    AmbientLight()
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
    static cocos2d::Camera *createPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
    static cocos2d::Camera *createOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)
    static cocos2d::Camera *create()
    static const cocos2d::Camera *getVisitingCamera()
    static const cocos2d::Viewport &getDefaultViewport()
    static void setDefaultViewport(const cocos2d::Viewport &vp)
    static cocos2d::Camera *getDefaultCamera()
    cocos2d::Camera::Type getType()
    cocos2d::CameraFlag getCameraFlag()
    void setCameraFlag(cocos2d::CameraFlag flag)
    void lookAt(const cocos2d::Vec3 &target, @optional const cocos2d::Vec3 &up)
    const cocos2d::Mat4 &getProjectionMatrix()
    const cocos2d::Mat4 &getViewMatrix()
    const cocos2d::Mat4 &getViewProjectionMatrix()
    cocos2d::Vec2 project(const cocos2d::Vec3 &src)
    cocos2d::Vec2 projectGL(const cocos2d::Vec3 &src)
    cocos2d::Vec3 unproject(const cocos2d::Vec3 &src)
    cocos2d::Vec3 unprojectGL(const cocos2d::Vec3 &src)
    float getDepthInView(const cocos2d::Mat4 &transform)
    void setDepth(int8_t depth)
    int8_t getDepth()
    int getRenderOrder()
    float getFarPlane()
    float getNearPlane()
    void clearBackground()
    void apply()
    bool isViewProjectionUpdated()
    void setBackgroundBrush(cocos2d::CameraBackgroundBrush *clearBrush)
    cocos2d::CameraBackgroundBrush *getBackgroundBrush()
    bool isBrushValid()
    Camera()
    void setScene(cocos2d::Scene *scene)
    void setAdditionalProjection(const cocos2d::Mat4 &mat)
    bool initDefault()
    bool initPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
    bool initOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)
    void applyViewport()
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
    cocos2d::CameraBackgroundBrush::BrushType getBrushType()
    static cocos2d::CameraBackgroundBrush *createNoneBrush()
    static cocos2d::CameraBackgroundDepthBrush *createDepthBrush(@optional float depth)
    static cocos2d::CameraBackgroundColorBrush *createColorBrush(const cocos2d::Color4F &color, float depth)
    static cocos2d::CameraBackgroundSkyBoxBrush *createSkyboxBrush(const std::string &positive_x, const std::string &negative_x, const std::string &positive_y, const std::string &negative_y, const std::string &positive_z, const std::string &negative_z)
    void drawBackground(cocos2d::Camera *)
    bool isValid()
    CameraBackgroundBrush()
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
    static cocos2d::CameraBackgroundDepthBrush *create(float depth)
    void setDepth(float depth)
    CameraBackgroundDepthBrush()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundColorBrush'
cls.SUPERCLS = "cocos2d::CameraBackgroundDepthBrush"
cls.funcs [[
    static cocos2d::CameraBackgroundColorBrush *create(const cocos2d::Color4F &color, float depth)
    void setColor(const cocos2d::Color4F &color)
    CameraBackgroundColorBrush()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundSkyBoxBrush'
cls.SUPERCLS = "cocos2d::CameraBackgroundBrush"
cls.funcs [[
    static cocos2d::CameraBackgroundSkyBoxBrush *create(const std::string &positive_x, const std::string &negative_x, const std::string &positive_y, const std::string &negative_y, const std::string &positive_z, const std::string &negative_z)
    static cocos2d::CameraBackgroundSkyBoxBrush *create()
    void setTexture(cocos2d::TextureCube *texture)
    bool isActived()
    void setActived(bool actived)
    void setTextureValid(bool valid)
    CameraBackgroundSkyBoxBrush()
]]
cls.props [[
    actived
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleBatchNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::ParticleBatchNode *createWithTexture(cocos2d::Texture2D *tex, @optional int capacity)
    static cocos2d::ParticleBatchNode *create(const std::string &fileImage, @optional int capacity)
    void insertChild(cocos2d::ParticleSystem *system, int index)
    void removeChildAtIndex(int index, bool doCleanup)
    void disableParticle(int particleIndex)
    cocos2d::TextureAtlas *getTextureAtlas()
    void setTextureAtlas(cocos2d::TextureAtlas *atlas)
    cocos2d::Texture2D *getTexture()
    void setTexture(cocos2d::Texture2D *texture)
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    const cocos2d::BlendFunc &getBlendFunc()
    ParticleBatchNode()
    bool initWithTexture(cocos2d::Texture2D *tex, int capacity)
    bool initWithFile(const std::string &fileImage, int capacity)
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
    static cocos2d::ParticleSystem *create(const std::string &plistFile)
    static cocos2d::ParticleSystem *createWithTotalParticles(int numberOfParticles)
    static Vector<cocos2d::ParticleSystem *> &getAllParticleSystems()
    void addParticles(int count)
    void stopSystem()
    void resetSystem()
    bool isFull()
    void updateParticleQuads()
    void postStep()
    void updateWithNoTime()
    bool isAutoRemoveOnFinish()
    void setAutoRemoveOnFinish(bool var)
    const cocos2d::Vec2 &getGravity()
    void setGravity(const cocos2d::Vec2 &g)
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
    cocos2d::ParticleBatchNode *getBatchNode()
    void setBatchNode(cocos2d::ParticleBatchNode *batchNode)
    int getAtlasIndex()
    void setAtlasIndex(int index)
    unsigned int getParticleCount()
    float getDuration()
    void setDuration(float duration)
    const cocos2d::Vec2 &getSourcePosition()
    void setSourcePosition(const cocos2d::Vec2 &pos)
    const cocos2d::Vec2 &getPosVar()
    void setPosVar(const cocos2d::Vec2 &pos)
    float getLife()
    void setLife(float life)
    float getLifeVar()
    void setLifeVar(float lifeVar)
    float getAngle()
    void setAngle(float angle)
    float getAngleVar()
    void setAngleVar(float angleVar)
    cocos2d::ParticleSystem::Mode getEmitterMode()
    void setEmitterMode(cocos2d::ParticleSystem::Mode mode)
    float getStartSize()
    void setStartSize(float startSize)
    float getStartSizeVar()
    void setStartSizeVar(float sizeVar)
    float getEndSize()
    void setEndSize(float endSize)
    float getEndSizeVar()
    void setEndSizeVar(float sizeVar)
    const cocos2d::Color4F &getStartColor()
    void setStartColor(const cocos2d::Color4F &color)
    const cocos2d::Color4F &getStartColorVar()
    void setStartColorVar(const cocos2d::Color4F &color)
    const cocos2d::Color4F &getEndColor()
    void setEndColor(const cocos2d::Color4F &color)
    const cocos2d::Color4F &getEndColorVar()
    void setEndColorVar(const cocos2d::Color4F &color)
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
    cocos2d::ParticleSystem::PositionType getPositionType()
    void setPositionType(cocos2d::ParticleSystem::PositionType type)
    cocos2d::Texture2D *getTexture()
    void setTexture(cocos2d::Texture2D *texture)
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    const cocos2d::BlendFunc &getBlendFunc()
    const std::string &getResourceFile()
    void start()
    void stop()
    void setSourcePositionCompatible(bool sourcePositionCompatible)
    bool isSourcePositionCompatible()
    ParticleSystem()
    bool initWithFile(const std::string &plistFile)
    bool initWithDictionary(cocos2d::ValueMap &dictionary)
    bool initWithDictionary(cocos2d::ValueMap &dictionary, const std::string &dirname)
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
    static cocos2d::ParticleSystemQuad *create()
    static cocos2d::ParticleSystemQuad *createWithTotalParticles(int numberOfParticles)
    static cocos2d::ParticleSystemQuad *create(const std::string &filename)
    static cocos2d::ParticleSystemQuad *create(cocos2d::ValueMap &dictionary)
    void setDisplayFrame(cocos2d::SpriteFrame *spriteFrame)
    void setTextureWithRect(cocos2d::Texture2D *texture, const cocos2d::Rect &rect)
    void listenRendererRecreated(cocos2d::EventCustom *event)
    ParticleSystemQuad()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleExplosion'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static cocos2d::ParticleExplosion *create()
    static cocos2d::ParticleExplosion *createWithTotalParticles(int numberOfParticles)
    ParticleExplosion()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleFire'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static cocos2d::ParticleFire *create()
    static cocos2d::ParticleFire *createWithTotalParticles(int numberOfParticles)
    ParticleFire()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleFireworks'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static cocos2d::ParticleFireworks *create()
    static cocos2d::ParticleFireworks *createWithTotalParticles(int numberOfParticles)
    ParticleFireworks()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleFlower'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static cocos2d::ParticleFlower *create()
    static cocos2d::ParticleFlower *createWithTotalParticles(int numberOfParticles)
    ParticleFlower()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleGalaxy'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static cocos2d::ParticleGalaxy *create()
    static cocos2d::ParticleGalaxy *createWithTotalParticles(int numberOfParticles)
    ParticleGalaxy()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleMeteor'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static cocos2d::ParticleMeteor *create()
    static cocos2d::ParticleMeteor *createWithTotalParticles(int numberOfParticles)
    ParticleMeteor()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleRain'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static cocos2d::ParticleRain *create()
    static cocos2d::ParticleRain *createWithTotalParticles(int numberOfParticles)
    ParticleRain()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSmoke'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static cocos2d::ParticleSmoke *create()
    static cocos2d::ParticleSmoke *createWithTotalParticles(int numberOfParticles)
    ParticleSmoke()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSnow'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static cocos2d::ParticleSnow *create()
    static cocos2d::ParticleSnow *createWithTotalParticles(int numberOfParticles)
    ParticleSnow()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSpiral'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static cocos2d::ParticleSpiral *create()
    static cocos2d::ParticleSpiral *createWithTotalParticles(int numberOfParticles)
    ParticleSpiral()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSun'
cls.SUPERCLS = "cocos2d::ParticleSystemQuad"
cls.funcs [[
    static cocos2d::ParticleSun *create()
    static cocos2d::ParticleSun *createWithTotalParticles(int numberOfParticles)
    ParticleSun()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXTileFlags'
cls.enums [[
    kTMXTileHorizontalFlag
    kTMXTileVerticalFlag
    kTMXTileDiagonalFlag
    kTMXFlipedAll
    kTMXFlippedMask
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXObjectGroup'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    TMXObjectGroup()
    const std::string &getGroupName()
    void setGroupName(const std::string &groupName)
    cocos2d::Value getProperty(const std::string &propertyName)
    cocos2d::ValueMap getObject(const std::string &objectName)
    const cocos2d::Vec2 &getPositionOffset()
    void setPositionOffset(const cocos2d::Vec2 &offset)
    const cocos2d::ValueMap &getProperties()
    void setProperties(const cocos2d::ValueMap &properties)
    const cocos2d::ValueVector &getObjects()
    void setObjects(const cocos2d::ValueVector &objects)
]]
cls.props [[
    groupName
    positionOffset
    properties
    objects
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXLayer'
cls.SUPERCLS = "cocos2d::SpriteBatchNode"
cls.funcs [[
    static cocos2d::TMXLayer *create(cocos2d::TMXTilesetInfo *tilesetInfo, cocos2d::TMXLayerInfo *layerInfo, cocos2d::TMXMapInfo *mapInfo)
    TMXLayer()
    bool initWithTilesetInfo(cocos2d::TMXTilesetInfo *tilesetInfo, cocos2d::TMXLayerInfo *layerInfo, cocos2d::TMXMapInfo *mapInfo)
    void releaseMap()
    cocos2d::Sprite *getTileAt(const cocos2d::Vec2 &tileCoordinate)
    uint32_t getTileGIDAt(const cocos2d::Vec2 &tileCoordinate, @out cocos2d::TMXTileFlags *flags)
    void setTileGID(uint32_t gid, const cocos2d::Vec2 &tileCoordinate)
    void setTileGID(uint32_t gid, const cocos2d::Vec2 &tileCoordinate, cocos2d::TMXTileFlags flags)
    void removeTileAt(const cocos2d::Vec2 &tileCoordinate)
    cocos2d::Vec2 getPositionAt(const cocos2d::Vec2 &tileCoordinate)
    cocos2d::Value getProperty(const std::string &propertyName)
    void setupTiles()
    const std::string &getLayerName()
    void setLayerName(const std::string &layerName)
    const cocos2d::Size &getLayerSize()
    void setLayerSize(const cocos2d::Size &size)
    const cocos2d::Size &getMapTileSize()
    void setMapTileSize(const cocos2d::Size &size)
    cocos2d::TMXTilesetInfo *getTileSet()
    void setTileSet(cocos2d::TMXTilesetInfo *info)
    int getLayerOrientation()
    void setLayerOrientation(int orientation)
    const cocos2d::ValueMap &getProperties()
    void setProperties(const cocos2d::ValueMap &properties)
]]
cls.props [[
    layerName
    layerSize
    mapTileSize
    tileSet
    layerOrientation
    properties
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXLayerInfo'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    TMXLayerInfo()
    void setProperties(cocos2d::ValueMap properties)
    cocos2d::ValueMap &getProperties()
]]
cls.props [[
    properties
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXMapInfo'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::TMXMapInfo *create(const std::string &tmxFile)
    static cocos2d::TMXMapInfo *createWithXML(const std::string &tmxString, const std::string &resourcePath)
    TMXMapInfo()
    bool initWithTMXFile(const std::string &tmxFile)
    bool initWithXML(const std::string &tmxString, const std::string &resourcePath)
    bool parseXMLFile(const std::string &xmlFilename)
    bool parseXMLString(const std::string &xmlString)
    cocos2d::ValueMapIntKey &getTileProperties()
    void setTileProperties(const cocos2d::ValueMapIntKey &tileProperties)
    int getOrientation()
    void setOrientation(int orientation)
    int getStaggerAxis()
    void setStaggerAxis(int staggerAxis)
    int getStaggerIndex()
    void setStaggerIndex(int staggerIndex)
    int getHexSideLength()
    void setHexSideLength(int hexSideLength)
    const cocos2d::Size &getMapSize()
    void setMapSize(const cocos2d::Size &mapSize)
    const cocos2d::Size &getTileSize()
    void setTileSize(const cocos2d::Size &tileSize)
    const Vector<cocos2d::TMXLayerInfo *> &getLayers()
    void setLayers(const Vector<cocos2d::TMXLayerInfo *> &layers)
    const Vector<cocos2d::TMXTilesetInfo *> &getTilesets()
    void setTilesets(const Vector<cocos2d::TMXTilesetInfo *> &tilesets)
    const Vector<cocos2d::TMXObjectGroup *> &getObjectGroups()
    void setObjectGroups(const Vector<cocos2d::TMXObjectGroup *> &groups)
    int getParentElement()
    void setParentElement(int element)
    int getParentGID()
    void setParentGID(int gid)
    int getLayerAttribs()
    void setLayerAttribs(int layerAttribs)
    bool isStoringCharacters()
    void setStoringCharacters(bool storingCharacters)
    const cocos2d::ValueMap &getProperties()
    void setProperties(const cocos2d::ValueMap &properties)
    void endElement(void *ctx, const char *name)
    void textHandler(void *ctx, const char *ch, size_t len)
    const std::string &getCurrentString()
    void setCurrentString(const std::string &currentString)
    const std::string &getTMXFileName()
    void setTMXFileName(const std::string &fileName)
    const std::string &getExternalTilesetFileName()
]]
cls.props [[
    tileProperties
    orientation
    staggerAxis
    staggerIndex
    hexSideLength
    mapSize
    tileSize
    layers
    tilesets
    objectGroups
    parentElement
    parentGID
    layerAttribs
    storingCharacters
    properties
    currentString
    tmxFileName
    externalTilesetFileName
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXTilesetInfo'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    TMXTilesetInfo()
    cocos2d::Rect getRectForGID(uint32_t gid)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXTiledMap'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::TMXTiledMap *create(const std::string &tmxFile)
    static cocos2d::TMXTiledMap *createWithXML(const std::string &tmxString, const std::string &resourcePath)
    cocos2d::TMXLayer *getLayer(const std::string &layerName)
    cocos2d::TMXObjectGroup *getObjectGroup(const std::string &groupName)
    cocos2d::Value getProperty(const std::string &propertyName)
    cocos2d::Value getPropertiesForGID(int GID)
    const cocos2d::Size &getMapSize()
    void setMapSize(const cocos2d::Size &mapSize)
    const cocos2d::Size &getTileSize()
    void setTileSize(const cocos2d::Size &tileSize)
    int getMapOrientation()
    void setMapOrientation(int mapOrientation)
    const Vector<cocos2d::TMXObjectGroup *> &getObjectGroups()
    void setObjectGroups(const Vector<cocos2d::TMXObjectGroup *> &groups)
    cocos2d::ValueMap &getProperties()
    void setProperties(const cocos2d::ValueMap &properties)
    int getLayerNum()
    const std::string &getResourceFile()
    TMXTiledMap()
    bool initWithTMXFile(const std::string &tmxFile)
    bool initWithXML(const std::string &tmxString, const std::string &resourcePath)
]]
cls.props [[
    mapSize
    tileSize
    mapOrientation
    objectGroups
    properties
    layerNum
    resourceFile
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FastTMXTiledMap'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::FastTMXTiledMap *create(const std::string &tmxFile)
    static cocos2d::FastTMXTiledMap *createWithXML(const std::string &tmxString, const std::string &resourcePath)
    cocos2d::FastTMXLayer *getLayer(const std::string &layerName)
    cocos2d::TMXObjectGroup *getObjectGroup(const std::string &groupName)
    cocos2d::Value getProperty(const std::string &propertyName)
    cocos2d::Value getPropertiesForGID(int GID)
    const cocos2d::Size &getMapSize()
    void setMapSize(const cocos2d::Size &mapSize)
    const cocos2d::Size &getTileSize()
    void setTileSize(const cocos2d::Size &tileSize)
    int getMapOrientation()
    void setMapOrientation(int mapOrientation)
    const Vector<cocos2d::TMXObjectGroup *> &getObjectGroups()
    void setObjectGroups(const Vector<cocos2d::TMXObjectGroup *> &groups)
    const cocos2d::ValueMap &getProperties()
    void setProperties(const cocos2d::ValueMap &properties)
]]
cls.props [[
    mapSize
    tileSize
    mapOrientation
    objectGroups
    properties
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FastTMXLayer'
cls.SUPERCLS = "cocos2d::Node"
cls.const('FAST_TMX_ORIENTATION_ORTHO', 'cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_ORTHO', 'const int')
cls.const('FAST_TMX_ORIENTATION_HEX', 'cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_HEX', 'const int')
cls.const('FAST_TMX_ORIENTATION_ISO', 'cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_ISO', 'const int')
cls.funcs [[
    static cocos2d::FastTMXLayer *create(cocos2d::TMXTilesetInfo *tilesetInfo, cocos2d::TMXLayerInfo *layerInfo, cocos2d::TMXMapInfo *mapInfo)
    FastTMXLayer()
    int getTileGIDAt(const cocos2d::Vec2 &tileCoordinate, @out cocos2d::TMXTileFlags *flags)
    void setTileGID(int gid, const cocos2d::Vec2 &tileCoordinate)
    void setTileGID(int gid, const cocos2d::Vec2 &tileCoordinate, cocos2d::TMXTileFlags flags)
    void removeTileAt(const cocos2d::Vec2 &tileCoordinate)
    cocos2d::Vec2 getPositionAt(const cocos2d::Vec2 &tileCoordinate)
    cocos2d::Value getProperty(const std::string &propertyName)
    void setupTiles()
    const std::string &getLayerName()
    void setLayerName(const std::string &layerName)
    const cocos2d::Size &getLayerSize()
    void setLayerSize(const cocos2d::Size &size)
    const cocos2d::Size &getMapTileSize()
    void setMapTileSize(const cocos2d::Size &size)
    cocos2d::TMXTilesetInfo *getTileSet()
    void setTileSet(cocos2d::TMXTilesetInfo *info)
    int getLayerOrientation()
    void setLayerOrientation(int orientation)
    const cocos2d::ValueMap &getProperties()
    void setProperties(const cocos2d::ValueMap &properties)
    cocos2d::Sprite *getTileAt(const cocos2d::Vec2 &tileCoordinate)
    void setupTileSprite(cocos2d::Sprite *sprite, const cocos2d::Vec2 &pos, uint32_t gid)
]]
cls.props [[
    layerName
    layerSize
    mapTileSize
    tileSet
    layerOrientation
    properties
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag'
cls.enums [[
    NONE
    NODE_TO_AGENT
    AGENT_TO_NODE
    NODE_AND_NODE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NavMeshAgent'
cls.SUPERCLS = "cocos2d::Component"
cls.funcs [[
    static cocos2d::NavMeshAgent *create(const cocos2d::NavMeshAgentParam &param)
    static const std::string &getNavMeshAgentComponentName()
    void setRadius(float radius)
    float getRadius()
    void setHeight(float height)
    float getHeight()
    void setMaxAcceleration(float maxAcceleration)
    float getMaxAcceleration()
    void setMaxSpeed(float maxSpeed)
    float getMaxSpeed()
    void setSeparationWeight(float weight)
    float getSeparationWeight()
    void setObstacleAvoidanceType(unsigned char type)
    unsigned char getObstacleAvoidanceType()
    cocos2d::Vec3 getCurrentVelocity()
    void pause()
    void resume()
    void stop()
    void setOrientationRefAxes(const cocos2d::Vec3 &rotRefAxes)
    void setAutoOrientation(bool isAuto)
    void setAutoTraverseOffMeshLink(bool isAuto)
    bool isOnOffMeshLink()
    void completeOffMeshLink()
    cocos2d::OffMeshLinkData getCurrentOffMeshLinkData()
    void setUserData(void *data)
    void *getUserData()
    void setSyncFlag(const cocos2d::NavMeshAgent::NavMeshAgentSyncFlag &flag)
    cocos2d::NavMeshAgent::NavMeshAgentSyncFlag getSyncFlag()
    void syncToAgent()
    void syncToNode()
    cocos2d::Vec3 getVelocity()
    NavMeshAgent()
]]
cls.callback {
    FUNCS =  {
        'void move(const cocos2d::Vec3 &destination, @local @optional const std::function<void (NavMeshAgent *, float)> &callback)'
    },
    TAG_MAKER = 'move',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.props [[
    navMeshAgentComponentName
    radius
    height
    maxAcceleration
    maxSpeed
    separationWeight
    obstacleAvoidanceType
    currentVelocity
    onOffMeshLink
    currentOffMeshLinkData
    userData
    syncFlag
    velocity
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag'
cls.enums [[
    NONE
    NODE_TO_OBSTACLE
    OBSTACLE_TO_NODE
    NODE_AND_NODE
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NavMeshObstacle'
cls.SUPERCLS = "cocos2d::Component"
cls.funcs [[
    static cocos2d::NavMeshObstacle *create(float radius, float height)
    static const std::string &getNavMeshObstacleComponentName()
    void setRadius(float radius)
    float getRadius()
    void setHeight(float height)
    float getHeight()
    void setSyncFlag(const cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag &flag)
    cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag getSyncFlag()
    void syncToObstacle()
    void syncToNode()
    NavMeshObstacle()
    bool initWith(float radius, float height)
]]
cls.props [[
    navMeshObstacleComponentName
    radius
    height
    syncFlag
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NavMesh'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    void update(float dt)
    void debugDraw(cocos2d::Renderer *renderer)
    void setDebugDrawEnable(bool enable)
    bool isDebugDrawEnabled()
    void addNavMeshAgent(cocos2d::NavMeshAgent *agent)
    void removeNavMeshAgent(cocos2d::NavMeshAgent *agent)
    void addNavMeshObstacle(cocos2d::NavMeshObstacle *obstacle)
    void removeNavMeshObstacle(cocos2d::NavMeshObstacle *obstacle)
    void findPath(const cocos2d::Vec3 &start, const cocos2d::Vec3 &end, std::vector<Vec3> &pathPoints)
    NavMesh()
]]
cls.props [[
    debugDrawEnabled
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
