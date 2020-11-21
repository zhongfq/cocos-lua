-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/cocos2d-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
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
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('COLOR', 'cocos2d::RenderTargetFlag::COLOR')
cls.enum('DEPTH', 'cocos2d::RenderTargetFlag::DEPTH')
cls.enum('STENCIL', 'cocos2d::RenderTargetFlag::STENCIL')
cls.enum('ALL', 'cocos2d::RenderTargetFlag::ALL')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ClearFlag'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::ClearFlag::NONE')
cls.enum('COLOR', 'cocos2d::ClearFlag::COLOR')
cls.enum('DEPTH', 'cocos2d::ClearFlag::DEPTH')
cls.enum('STENCIL', 'cocos2d::ClearFlag::STENCIL')
cls.enum('ALL', 'cocos2d::ClearFlag::ALL')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MATRIX_STACK_TYPE'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('MATRIX_STACK_MODELVIEW', 'cocos2d::MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW')
cls.enum('MATRIX_STACK_PROJECTION', 'cocos2d::MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION')
cls.enum('MATRIX_STACK_TEXTURE', 'cocos2d::MATRIX_STACK_TYPE::MATRIX_STACK_TEXTURE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Director::Projection'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('_2D', 'cocos2d::Director::Projection::_2D')
cls.enum('_3D', 'cocos2d::Director::Projection::_3D')
cls.enum('CUSTOM', 'cocos2d::Director::Projection::CUSTOM')
cls.enum('DEFAULT', 'cocos2d::Director::Projection::DEFAULT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::UserDefault'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'bool getBoolForKey(const char *key)', 'bool getBoolForKey(const char *key, bool defaultValue)')
cls.func(nil, 'int getIntegerForKey(const char *key)', 'int getIntegerForKey(const char *key, int defaultValue)')
cls.func(nil, 'float getFloatForKey(const char *key)', 'float getFloatForKey(const char *key, float defaultValue)')
cls.func(nil, 'double getDoubleForKey(const char *key)', 'double getDoubleForKey(const char *key, double defaultValue)')
cls.func(nil, 'std::string getStringForKey(const char *key)', 'std::string getStringForKey(const char *key, const std::string &defaultValue)')
cls.func(nil, 'cocos2d::Data getDataForKey(const char *key)', 'cocos2d::Data getDataForKey(const char *key, const cocos2d::Data &defaultValue)')
cls.func(nil, 'void setBoolForKey(const char *key, bool value)')
cls.func(nil, 'void setIntegerForKey(const char *key, int value)')
cls.func(nil, 'void setFloatForKey(const char *key, float value)')
cls.func(nil, 'void setDoubleForKey(const char *key, double value)')
cls.func(nil, 'void setStringForKey(const char *key, const std::string &value)')
cls.func(nil, 'void setDataForKey(const char *key, const cocos2d::Data &value)')
cls.func(nil, 'void flush()')
cls.func(nil, 'void deleteValueForKey(const char *key)')
cls.func(nil, 'static cocos2d::UserDefault *getInstance()')
cls.func(nil, 'static void destroyInstance()')
cls.func(nil, 'static const std::string &getXMLFilePath()')
cls.func(nil, 'static bool isXMLFileExist()')
cls.prop('instance', nil, nil)
cls.prop('xmlFilePath', nil, nil)
cls.prop('xmlFileExist', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Ref'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func('__gc', [[
    {
        return xlua_ccobjgc(L);
    }
]])
cls.func(nil, 'unsigned int getReferenceCount()')
cls.prop('referenceCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Console'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Console()')
cls.func(nil, 'bool listenOnTCP(int port)')
cls.func(nil, 'bool listenOnFileDescriptor(int fd)')
cls.func(nil, 'void stop()')
cls.func(nil, 'void delCommand(const std::string &cmdName)')
cls.func(nil, 'void delSubCommand(const std::string &cmdName, const std::string &subCmdName)')
cls.func(nil, 'void log(const char *buf)')
cls.func(nil, 'void setBindAddress(const std::string &address)')
cls.func(nil, 'bool isIpv6Server()')
cls.func(nil, 'char getCommandSeparator()')
cls.func(nil, 'void setCommandSeparator(char var)')
cls.prop('ipv6Server', nil, nil)
cls.prop('commandSeparator', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Acceleration'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.var('x', '@optional double x')
cls.var('y', '@optional double y')
cls.var('z', '@optional double z')
cls.var('timestamp', '@optional double timestamp')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Director'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Director *getInstance()')
cls.func(nil, 'Director()')
cls.func(nil, 'bool init()')
cls.func(nil, '@addref(scenes |) cocos2d::Scene *getRunningScene()')
cls.func(nil, 'float getAnimationInterval()')
cls.func(nil, 'void setAnimationInterval(float interval)')
cls.func(nil, 'bool isDisplayStats()')
cls.func(nil, 'void setDisplayStats(bool displayStats)')
cls.func(nil, 'float getSecondsPerFrame()')
cls.func(nil, '@addref(openGLView ^) cocos2d::GLView *getOpenGLView()')
cls.func(nil, 'void setOpenGLView(@addref(openGLView ^) cocos2d::GLView *openGLView)')
cls.func(nil, '@addref(textureCache ^) cocos2d::TextureCache *getTextureCache()')
cls.func(nil, 'bool isNextDeltaTimeZero()')
cls.func(nil, 'void setNextDeltaTimeZero(bool nextDeltaTimeZero)')
cls.func(nil, 'bool isPaused()')
cls.func(nil, 'unsigned int getTotalFrames()')
cls.func(nil, 'cocos2d::Director::Projection getProjection()')
cls.func(nil, 'void setProjection(cocos2d::Director::Projection projection)')
cls.func(nil, 'void setViewport()')
cls.func(nil, 'bool isSendCleanupToScene()')
cls.func(nil, '@addref(notificationNode ^) cocos2d::Node *getNotificationNode()')
cls.func(nil, 'void setNotificationNode(@addref(notificationNode ^) cocos2d::Node *node)')
cls.func(nil, 'const cocos2d::Size &getWinSize()')
cls.func(nil, 'cocos2d::Size getWinSizeInPixels()')
cls.func(nil, 'cocos2d::Size getVisibleSize()')
cls.func(nil, 'cocos2d::Vec2 getVisibleOrigin()')
cls.func(nil, 'cocos2d::Rect getSafeAreaRect()')
cls.func(nil, 'cocos2d::Vec2 convertToGL(@pack const cocos2d::Vec2 &point)')
cls.func(nil, 'cocos2d::Vec2 convertToUI(@pack const cocos2d::Vec2 &point)')
cls.func(nil, 'float getZEye()')
cls.func(nil, 'void runWithScene(@addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'void pushScene(@addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, '@delref(scenes ~) void popScene()')
cls.func(nil, '@delref(scenes ~) void popToRootScene()')
cls.func(nil, '@delref(scenes ~) void popToSceneStackLevel(int level)')
cls.func(nil, '@delref(scenes ~) void replaceScene(@addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'void end()')
cls.func(nil, 'void pause()')
cls.func(nil, 'void resume()')
cls.func(nil, 'void restart()')
cls.func(nil, 'void stopAnimation()')
cls.func(nil, 'void startAnimation()')
cls.func(nil, 'void drawScene()')
cls.func(nil, 'void purgeCachedData()')
cls.func(nil, 'void setDefaultValues()')
cls.func(nil, 'void setGLDefaultValues()')
cls.func(nil, 'void setClearColor(const cocos2d::Color4F &clearColor)')
cls.func(nil, 'void mainLoop()', 'void mainLoop(float dt)')
cls.func(nil, 'void setContentScaleFactor(float scaleFactor)')
cls.func(nil, 'float getContentScaleFactor()')
cls.func(nil, '@addref(scheduler ^) cocos2d::Scheduler *getScheduler()')
cls.func(nil, 'void setScheduler(@addref(scheduler ^) cocos2d::Scheduler *scheduler)')
cls.func(nil, '@addref(actionManager ^) cocos2d::ActionManager *getActionManager()')
cls.func(nil, 'void setActionManager(@addref(actionManager ^) cocos2d::ActionManager *actionManager)')
cls.func(nil, '@addref(eventDispatcher ^) cocos2d::EventDispatcher *getEventDispatcher()')
cls.func(nil, 'void setEventDispatcher(@addref(eventDispatcher ^) cocos2d::EventDispatcher *dispatcher)')
cls.func(nil, '@addref(renderer ^) cocos2d::Renderer *getRenderer()')
cls.func(nil, 'cocos2d::Console *getConsole()')
cls.func(nil, 'float getDeltaTime()')
cls.func(nil, 'float getFrameRate()')
cls.func(nil, 'void pushMatrix(cocos2d::MATRIX_STACK_TYPE type)')
cls.func(nil, 'void popMatrix(cocos2d::MATRIX_STACK_TYPE type)')
cls.func(nil, 'void loadIdentityMatrix(cocos2d::MATRIX_STACK_TYPE type)')
cls.func(nil, 'void loadMatrix(cocos2d::MATRIX_STACK_TYPE type, const cocos2d::Mat4 &mat)')
cls.func(nil, 'void multiplyMatrix(cocos2d::MATRIX_STACK_TYPE type, const cocos2d::Mat4 &mat)')
cls.func(nil, 'const cocos2d::Mat4 &getMatrix(cocos2d::MATRIX_STACK_TYPE type)')
cls.func(nil, 'void resetMatrixStack()')
cls.func(nil, 'bool isValid()')
cls.var('EVENT_BEFORE_SET_NEXT_SCENE', 'static const char *EVENT_BEFORE_SET_NEXT_SCENE')
cls.var('EVENT_AFTER_SET_NEXT_SCENE', 'static const char *EVENT_AFTER_SET_NEXT_SCENE')
cls.var('EVENT_PROJECTION_CHANGED', 'static const char *EVENT_PROJECTION_CHANGED')
cls.var('EVENT_BEFORE_UPDATE', 'static const char *EVENT_BEFORE_UPDATE')
cls.var('EVENT_AFTER_UPDATE', 'static const char *EVENT_AFTER_UPDATE')
cls.var('EVENT_RESET', 'static const char *EVENT_RESET')
cls.var('EVENT_AFTER_VISIT', 'static const char *EVENT_AFTER_VISIT')
cls.var('EVENT_AFTER_DRAW', 'static const char *EVENT_AFTER_DRAW')
cls.var('EVENT_BEFORE_DRAW', 'static const char *EVENT_BEFORE_DRAW')
cls.prop('instance', nil, nil)
cls.prop('runningScene', nil, nil)
cls.prop('animationInterval', nil, nil)
cls.prop('displayStats', nil, nil)
cls.prop('secondsPerFrame', nil, nil)
cls.prop('openGLView', nil, nil)
cls.prop('textureCache', nil, nil)
cls.prop('nextDeltaTimeZero', nil, nil)
cls.prop('paused', nil, nil)
cls.prop('totalFrames', nil, nil)
cls.prop('projection', nil, nil)
cls.prop('sendCleanupToScene', nil, nil)
cls.prop('notificationNode', nil, nil)
cls.prop('winSize', nil, nil)
cls.prop('winSizeInPixels', nil, nil)
cls.prop('visibleSize', nil, nil)
cls.prop('visibleOrigin', nil, nil)
cls.prop('safeAreaRect', nil, nil)
cls.prop('zEye', nil, nil)
cls.prop('contentScaleFactor', nil, nil)
cls.prop('scheduler', nil, nil)
cls.prop('actionManager', nil, nil)
cls.prop('eventDispatcher', nil, nil)
cls.prop('renderer', nil, nil)
cls.prop('console', nil, nil)
cls.prop('deltaTime', nil, nil)
cls.prop('frameRate', nil, nil)
cls.prop('valid', nil, nil)
cls.alias('end', 'exit')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Scheduler'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
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
cls.func('scheduleUpdate', [[
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
    }
]])
cls.func(nil, 'Scheduler()')
cls.func(nil, 'float getTimeScale()')
cls.func(nil, 'void setTimeScale(float timeScale)')
cls.func(nil, 'void update(float dt)')
cls.func(nil, 'void unscheduleUpdate(void *target)')
cls.func(nil, 'void unscheduleAllWithMinPriority(int minPriority)')
cls.func(nil, 'bool isScheduled(const std::string &key, const void *target)')
cls.func(nil, 'void pauseTarget(void *target)')
cls.func(nil, 'void resumeTarget(void *target)')
cls.func(nil, 'bool isTargetPaused(void *target)')
cls.func(nil, 'std::set<void *> pauseAllTargets()')
cls.func(nil, 'std::set<void *> pauseAllTargetsWithMinPriority(int minPriority)')
cls.func(nil, 'void resumeTargets(const std::set<void *> &targetsToResume)')
cls.func(nil, 'void removeAllFunctionsToBePerformedInCocosThread()')
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
cls.prop('timeScale', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventDispatcher'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
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
cls.func(nil, 'void addEventListenerWithSceneGraphPriority(@addref(listeners | 3) cocos2d::EventListener *listener, cocos2d::Node *node)')
cls.func(nil, 'void addEventListenerWithFixedPriority(@addref(listeners |) cocos2d::EventListener *listener, int fixedPriority)')
cls.func(nil, '@delref(listeners ~) void removeEventListener(@delref(listeners |) cocos2d::EventListener *listener)')
cls.func(nil, '@delref(listeners ~) void removeEventListenersForType(cocos2d::EventListener::Type listenerType)')
cls.func(nil, 'void removeEventListenersForTarget(cocos2d::Node *target, @optional bool recursive)')
cls.func(nil, '@delref(listeners ~) void removeCustomEventListeners(const std::string &customEventName)')
cls.func(nil, '@delref(listeners ~) void removeAllEventListeners()')
cls.func(nil, 'void pauseEventListenersForTarget(cocos2d::Node *target, @optional bool recursive)')
cls.func(nil, 'void resumeEventListenersForTarget(cocos2d::Node *target, @optional bool recursive)')
cls.func(nil, 'void setPriority(cocos2d::EventListener *listener, int fixedPriority)')
cls.func(nil, 'void setEnabled(bool isEnabled)')
cls.func(nil, 'bool isEnabled()')
cls.func(nil, 'void dispatchEvent(cocos2d::Event *event)')
cls.func(nil, 'void dispatchCustomEvent(const std::string &eventName, @optional void *optionalUserData)')
cls.func(nil, 'bool hasEventListener(const cocos2d::EventListener::ListenerID &listenerID)')
cls.func(nil, 'EventDispatcher()')
cls.callback {
    FUNCS =  {
        '@addref(listeners |) cocos2d::EventListenerCustom *addCustomEventListener(const std::string &eventName, @local const std::function<void (EventCustom *)> &callback)'
    },
    TAG_MAKER = '(#1)',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = "return",
    TAG_SCOPE = 'object',
}
cls.prop('enabled', nil, nil)
cls.insert('removeEventListenersForTarget', {
    BEFORE = [[
        bool recursive = false;
        auto node = olua_checkobj<cocos2d::Node>(L, 2);
        if (lua_gettop(L) >= 3) {
            recursive = olua_toboolean(L, 3);
        }
        doRemoveEventListenersForTarget(L, node, recursive, "listeners");
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListener::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('UNKNOWN', 'cocos2d::EventListener::Type::UNKNOWN')
cls.enum('TOUCH_ONE_BY_ONE', 'cocos2d::EventListener::Type::TOUCH_ONE_BY_ONE')
cls.enum('TOUCH_ALL_AT_ONCE', 'cocos2d::EventListener::Type::TOUCH_ALL_AT_ONCE')
cls.enum('KEYBOARD', 'cocos2d::EventListener::Type::KEYBOARD')
cls.enum('MOUSE', 'cocos2d::EventListener::Type::MOUSE')
cls.enum('ACCELERATION', 'cocos2d::EventListener::Type::ACCELERATION')
cls.enum('FOCUS', 'cocos2d::EventListener::Type::FOCUS')
cls.enum('GAME_CONTROLLER', 'cocos2d::EventListener::Type::GAME_CONTROLLER')
cls.enum('CUSTOM', 'cocos2d::EventListener::Type::CUSTOM')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListener'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'bool checkAvailable()')
cls.func(nil, 'cocos2d::EventListener *clone()')
cls.func(nil, 'void setEnabled(bool enabled)')
cls.func(nil, 'bool isEnabled()')
cls.prop('available', 'bool checkAvailable()', nil)
cls.prop('enabled', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerTouchOneByOne'
cls.SUPERCLS = 'cocos2d::EventListener'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('LISTENER_ID', 'cocos2d::EventListenerTouchOneByOne::LISTENER_ID', 'const std::string')
cls.func(nil, 'static cocos2d::EventListenerTouchOneByOne *create()')
cls.func(nil, 'void setSwallowTouches(bool needSwallow)')
cls.func(nil, 'bool isSwallowTouches()')
cls.func(nil, 'EventListenerTouchOneByOne()')
cls.var('onTouchBegan', '@nullable @local std::function<bool (Touch *, Event *)> onTouchBegan')
cls.var('onTouchMoved', '@nullable @local std::function<void (Touch *, Event *)> onTouchMoved')
cls.var('onTouchEnded', '@nullable @local std::function<void (Touch *, Event *)> onTouchEnded')
cls.var('onTouchCancelled', '@nullable @local std::function<void (Touch *, Event *)> onTouchCancelled')
cls.prop('swallowTouches', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerTouchAllAtOnce'
cls.SUPERCLS = 'cocos2d::EventListener'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('LISTENER_ID', 'cocos2d::EventListenerTouchAllAtOnce::LISTENER_ID', 'const std::string')
cls.func(nil, 'static cocos2d::EventListenerTouchAllAtOnce *create()')
cls.func(nil, 'EventListenerTouchAllAtOnce()')
cls.var('onTouchesBegan', '@nullable @local std::function<void (const std::vector<Touch *> &, Event *)> onTouchesBegan')
cls.var('onTouchesMoved', '@nullable @local std::function<void (const std::vector<Touch *> &, Event *)> onTouchesMoved')
cls.var('onTouchesEnded', '@nullable @local std::function<void (const std::vector<Touch *> &, Event *)> onTouchesEnded')
cls.var('onTouchesCancelled', '@nullable @local std::function<void (const std::vector<Touch *> &, Event *)> onTouchesCancelled')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerCustom'
cls.SUPERCLS = 'cocos2d::EventListener'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'EventListenerCustom()')
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
cls.SUPERCLS = 'cocos2d::EventListener'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('LISTENER_ID', 'cocos2d::EventListenerKeyboard::LISTENER_ID', 'const std::string')
cls.func(nil, 'static cocos2d::EventListenerKeyboard *create()')
cls.func(nil, 'EventListenerKeyboard()')
cls.var('onKeyPressed', '@nullable @local std::function<void (EventKeyboard::KeyCode, Event *)> onKeyPressed')
cls.var('onKeyReleased', '@nullable @local std::function<void (EventKeyboard::KeyCode, Event *)> onKeyReleased')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerAcceleration'
cls.SUPERCLS = 'cocos2d::EventListener'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('LISTENER_ID', 'cocos2d::EventListenerAcceleration::LISTENER_ID', 'const std::string')
cls.func(nil, 'EventListenerAcceleration()')
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
cls.SUPERCLS = 'cocos2d::EventListener'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('LISTENER_ID', 'cocos2d::EventListenerFocus::LISTENER_ID', 'const std::string')
cls.func(nil, 'static cocos2d::EventListenerFocus *create()')
cls.func(nil, 'EventListenerFocus()')
cls.var('onFocusChanged', '@nullable @local std::function<void (ui::Widget *, ui::Widget *)> onFocusChanged')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerMouse'
cls.SUPERCLS = 'cocos2d::EventListener'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('LISTENER_ID', 'cocos2d::EventListenerMouse::LISTENER_ID', 'const std::string')
cls.func(nil, 'static cocos2d::EventListenerMouse *create()')
cls.func(nil, 'EventListenerMouse()')
cls.var('onMouseDown', '@nullable @local std::function<void (EventMouse *)> onMouseDown')
cls.var('onMouseUp', '@nullable @local std::function<void (EventMouse *)> onMouseUp')
cls.var('onMouseMove', '@nullable @local std::function<void (EventMouse *)> onMouseMove')
cls.var('onMouseScroll', '@nullable @local std::function<void (EventMouse *)> onMouseScroll')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Event::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('TOUCH', 'cocos2d::Event::Type::TOUCH')
cls.enum('KEYBOARD', 'cocos2d::Event::Type::KEYBOARD')
cls.enum('ACCELERATION', 'cocos2d::Event::Type::ACCELERATION')
cls.enum('MOUSE', 'cocos2d::Event::Type::MOUSE')
cls.enum('FOCUS', 'cocos2d::Event::Type::FOCUS')
cls.enum('GAME_CONTROLLER', 'cocos2d::Event::Type::GAME_CONTROLLER')
cls.enum('CUSTOM', 'cocos2d::Event::Type::CUSTOM')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Event'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Event(cocos2d::Event::Type type)')
cls.func(nil, 'cocos2d::Event::Type getType()')
cls.func(nil, 'void stopPropagation()')
cls.func(nil, 'bool isStopped()')
cls.func(nil, 'cocos2d::Node *getCurrentTarget()')
cls.prop('type', nil, nil)
cls.prop('stopped', nil, nil)
cls.prop('currentTarget', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventCustom'
cls.SUPERCLS = 'cocos2d::Event'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'EventCustom(const std::string &eventName)')
cls.func(nil, 'void setUserData(void *data)')
cls.func(nil, 'void *getUserData()')
cls.func(nil, 'const std::string &getEventName()')
cls.prop('userData', nil, nil)
cls.prop('eventName', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventListenerController'
cls.SUPERCLS = 'cocos2d::EventListener'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('LISTENER_ID', 'cocos2d::EventListenerController::LISTENER_ID', 'const std::string')
cls.func(nil, 'static cocos2d::EventListenerController *create()')
cls.var('onConnected', '@nullable @local std::function<void (Controller *, Event *)> onConnected')
cls.var('onDisconnected', '@nullable @local std::function<void (Controller *, Event *)> onDisconnected')
cls.var('onKeyDown', '@nullable @local std::function<void (Controller *, int, Event *)> onKeyDown')
cls.var('onKeyUp', '@nullable @local std::function<void (Controller *, int, Event *)> onKeyUp')
cls.var('onKeyRepeat', '@nullable @local std::function<void (Controller *, int, Event *)> onKeyRepeat')
cls.var('onAxisEvent', '@nullable @local std::function<void (Controller *, int, Event *)> onAxisEvent')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventTouch::EventCode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('BEGAN', 'cocos2d::EventTouch::EventCode::BEGAN')
cls.enum('MOVED', 'cocos2d::EventTouch::EventCode::MOVED')
cls.enum('ENDED', 'cocos2d::EventTouch::EventCode::ENDED')
cls.enum('CANCELLED', 'cocos2d::EventTouch::EventCode::CANCELLED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventTouch'
cls.SUPERCLS = 'cocos2d::Event'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('MAX_TOUCHES', 'cocos2d::EventTouch::MAX_TOUCHES', 'const int')
cls.func(nil, 'EventTouch()')
cls.func(nil, 'cocos2d::EventTouch::EventCode getEventCode()')
cls.func(nil, 'const std::vector<Touch *> &getTouches()')
cls.func(nil, 'void setEventCode(cocos2d::EventTouch::EventCode eventCode)')
cls.func(nil, 'void setTouches(const std::vector<Touch *> &touches)')
cls.prop('eventCode', nil, nil)
cls.prop('touches', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventKeyboard'
cls.SUPERCLS = 'cocos2d::Event'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'EventKeyboard(cocos2d::EventKeyboard::KeyCode keyCode, bool isPressed)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventAcceleration'
cls.SUPERCLS = 'cocos2d::Event'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventFocus'
cls.SUPERCLS = 'cocos2d::Event'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'EventFocus(cocos2d::ui::Widget *widgetLoseFocus, cocos2d::ui::Widget *widgetGetFocus)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventMouse::MouseEventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('MOUSE_NONE', 'cocos2d::EventMouse::MouseEventType::MOUSE_NONE')
cls.enum('MOUSE_DOWN', 'cocos2d::EventMouse::MouseEventType::MOUSE_DOWN')
cls.enum('MOUSE_UP', 'cocos2d::EventMouse::MouseEventType::MOUSE_UP')
cls.enum('MOUSE_MOVE', 'cocos2d::EventMouse::MouseEventType::MOUSE_MOVE')
cls.enum('MOUSE_SCROLL', 'cocos2d::EventMouse::MouseEventType::MOUSE_SCROLL')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventMouse::MouseButton'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('BUTTON_UNSET', 'cocos2d::EventMouse::MouseButton::BUTTON_UNSET')
cls.enum('BUTTON_LEFT', 'cocos2d::EventMouse::MouseButton::BUTTON_LEFT')
cls.enum('BUTTON_RIGHT', 'cocos2d::EventMouse::MouseButton::BUTTON_RIGHT')
cls.enum('BUTTON_MIDDLE', 'cocos2d::EventMouse::MouseButton::BUTTON_MIDDLE')
cls.enum('BUTTON_4', 'cocos2d::EventMouse::MouseButton::BUTTON_4')
cls.enum('BUTTON_5', 'cocos2d::EventMouse::MouseButton::BUTTON_5')
cls.enum('BUTTON_6', 'cocos2d::EventMouse::MouseButton::BUTTON_6')
cls.enum('BUTTON_7', 'cocos2d::EventMouse::MouseButton::BUTTON_7')
cls.enum('BUTTON_8', 'cocos2d::EventMouse::MouseButton::BUTTON_8')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventMouse'
cls.SUPERCLS = 'cocos2d::Event'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'EventMouse(cocos2d::EventMouse::MouseEventType mouseEventCode)')
cls.func(nil, 'void setScrollData(float scrollX, float scrollY)')
cls.func(nil, 'float getScrollX()')
cls.func(nil, 'float getScrollY()')
cls.func(nil, 'void setCursorPosition(float x, float y)')
cls.func(nil, 'void setMouseButton(cocos2d::EventMouse::MouseButton button)')
cls.func(nil, 'cocos2d::EventMouse::MouseButton getMouseButton()')
cls.func(nil, 'float getCursorX()')
cls.func(nil, 'float getCursorY()')
cls.func(nil, 'cocos2d::Vec2 getLocation()')
cls.func(nil, 'cocos2d::Vec2 getPreviousLocation()')
cls.func(nil, 'cocos2d::Vec2 getStartLocation()')
cls.func(nil, 'cocos2d::Vec2 getDelta()')
cls.func(nil, 'cocos2d::Vec2 getLocationInView()')
cls.func(nil, 'cocos2d::Vec2 getPreviousLocationInView()')
cls.func(nil, 'cocos2d::Vec2 getStartLocationInView()')
cls.prop('scrollX', nil, nil)
cls.prop('scrollY', nil, nil)
cls.prop('mouseButton', nil, nil)
cls.prop('cursorX', nil, nil)
cls.prop('cursorY', nil, nil)
cls.prop('location', nil, nil)
cls.prop('previousLocation', nil, nil)
cls.prop('startLocation', nil, nil)
cls.prop('delta', nil, nil)
cls.prop('locationInView', nil, nil)
cls.prop('previousLocationInView', nil, nil)
cls.prop('startLocationInView', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventKeyboard::KeyCode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('KEY_NONE', 'cocos2d::EventKeyboard::KeyCode::KEY_NONE')
cls.enum('KEY_PAUSE', 'cocos2d::EventKeyboard::KeyCode::KEY_PAUSE')
cls.enum('KEY_SCROLL_LOCK', 'cocos2d::EventKeyboard::KeyCode::KEY_SCROLL_LOCK')
cls.enum('KEY_PRINT', 'cocos2d::EventKeyboard::KeyCode::KEY_PRINT')
cls.enum('KEY_SYSREQ', 'cocos2d::EventKeyboard::KeyCode::KEY_SYSREQ')
cls.enum('KEY_BREAK', 'cocos2d::EventKeyboard::KeyCode::KEY_BREAK')
cls.enum('KEY_ESCAPE', 'cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE')
cls.enum('KEY_BACK', 'cocos2d::EventKeyboard::KeyCode::KEY_BACK')
cls.enum('KEY_BACKSPACE', 'cocos2d::EventKeyboard::KeyCode::KEY_BACKSPACE')
cls.enum('KEY_TAB', 'cocos2d::EventKeyboard::KeyCode::KEY_TAB')
cls.enum('KEY_BACK_TAB', 'cocos2d::EventKeyboard::KeyCode::KEY_BACK_TAB')
cls.enum('KEY_RETURN', 'cocos2d::EventKeyboard::KeyCode::KEY_RETURN')
cls.enum('KEY_CAPS_LOCK', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPS_LOCK')
cls.enum('KEY_SHIFT', 'cocos2d::EventKeyboard::KeyCode::KEY_SHIFT')
cls.enum('KEY_LEFT_SHIFT', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_SHIFT')
cls.enum('KEY_RIGHT_SHIFT', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_SHIFT')
cls.enum('KEY_CTRL', 'cocos2d::EventKeyboard::KeyCode::KEY_CTRL')
cls.enum('KEY_LEFT_CTRL', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_CTRL')
cls.enum('KEY_RIGHT_CTRL', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_CTRL')
cls.enum('KEY_ALT', 'cocos2d::EventKeyboard::KeyCode::KEY_ALT')
cls.enum('KEY_LEFT_ALT', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ALT')
cls.enum('KEY_RIGHT_ALT', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ALT')
cls.enum('KEY_MENU', 'cocos2d::EventKeyboard::KeyCode::KEY_MENU')
cls.enum('KEY_HYPER', 'cocos2d::EventKeyboard::KeyCode::KEY_HYPER')
cls.enum('KEY_INSERT', 'cocos2d::EventKeyboard::KeyCode::KEY_INSERT')
cls.enum('KEY_HOME', 'cocos2d::EventKeyboard::KeyCode::KEY_HOME')
cls.enum('KEY_PG_UP', 'cocos2d::EventKeyboard::KeyCode::KEY_PG_UP')
cls.enum('KEY_DELETE', 'cocos2d::EventKeyboard::KeyCode::KEY_DELETE')
cls.enum('KEY_END', 'cocos2d::EventKeyboard::KeyCode::KEY_END')
cls.enum('KEY_PG_DOWN', 'cocos2d::EventKeyboard::KeyCode::KEY_PG_DOWN')
cls.enum('KEY_LEFT_ARROW', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW')
cls.enum('KEY_RIGHT_ARROW', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW')
cls.enum('KEY_UP_ARROW', 'cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW')
cls.enum('KEY_DOWN_ARROW', 'cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW')
cls.enum('KEY_NUM_LOCK', 'cocos2d::EventKeyboard::KeyCode::KEY_NUM_LOCK')
cls.enum('KEY_KP_PLUS', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_PLUS')
cls.enum('KEY_KP_MINUS', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_MINUS')
cls.enum('KEY_KP_MULTIPLY', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_MULTIPLY')
cls.enum('KEY_KP_DIVIDE', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_DIVIDE')
cls.enum('KEY_KP_ENTER', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_ENTER')
cls.enum('KEY_KP_HOME', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_HOME')
cls.enum('KEY_KP_UP', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_UP')
cls.enum('KEY_KP_PG_UP', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_PG_UP')
cls.enum('KEY_KP_LEFT', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_LEFT')
cls.enum('KEY_KP_FIVE', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_FIVE')
cls.enum('KEY_KP_RIGHT', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_RIGHT')
cls.enum('KEY_KP_END', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_END')
cls.enum('KEY_KP_DOWN', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_DOWN')
cls.enum('KEY_KP_PG_DOWN', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_PG_DOWN')
cls.enum('KEY_KP_INSERT', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_INSERT')
cls.enum('KEY_KP_DELETE', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_DELETE')
cls.enum('KEY_F1', 'cocos2d::EventKeyboard::KeyCode::KEY_F1')
cls.enum('KEY_F2', 'cocos2d::EventKeyboard::KeyCode::KEY_F2')
cls.enum('KEY_F3', 'cocos2d::EventKeyboard::KeyCode::KEY_F3')
cls.enum('KEY_F4', 'cocos2d::EventKeyboard::KeyCode::KEY_F4')
cls.enum('KEY_F5', 'cocos2d::EventKeyboard::KeyCode::KEY_F5')
cls.enum('KEY_F6', 'cocos2d::EventKeyboard::KeyCode::KEY_F6')
cls.enum('KEY_F7', 'cocos2d::EventKeyboard::KeyCode::KEY_F7')
cls.enum('KEY_F8', 'cocos2d::EventKeyboard::KeyCode::KEY_F8')
cls.enum('KEY_F9', 'cocos2d::EventKeyboard::KeyCode::KEY_F9')
cls.enum('KEY_F10', 'cocos2d::EventKeyboard::KeyCode::KEY_F10')
cls.enum('KEY_F11', 'cocos2d::EventKeyboard::KeyCode::KEY_F11')
cls.enum('KEY_F12', 'cocos2d::EventKeyboard::KeyCode::KEY_F12')
cls.enum('KEY_SPACE', 'cocos2d::EventKeyboard::KeyCode::KEY_SPACE')
cls.enum('KEY_EXCLAM', 'cocos2d::EventKeyboard::KeyCode::KEY_EXCLAM')
cls.enum('KEY_QUOTE', 'cocos2d::EventKeyboard::KeyCode::KEY_QUOTE')
cls.enum('KEY_NUMBER', 'cocos2d::EventKeyboard::KeyCode::KEY_NUMBER')
cls.enum('KEY_DOLLAR', 'cocos2d::EventKeyboard::KeyCode::KEY_DOLLAR')
cls.enum('KEY_PERCENT', 'cocos2d::EventKeyboard::KeyCode::KEY_PERCENT')
cls.enum('KEY_CIRCUMFLEX', 'cocos2d::EventKeyboard::KeyCode::KEY_CIRCUMFLEX')
cls.enum('KEY_AMPERSAND', 'cocos2d::EventKeyboard::KeyCode::KEY_AMPERSAND')
cls.enum('KEY_APOSTROPHE', 'cocos2d::EventKeyboard::KeyCode::KEY_APOSTROPHE')
cls.enum('KEY_LEFT_PARENTHESIS', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_PARENTHESIS')
cls.enum('KEY_RIGHT_PARENTHESIS', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_PARENTHESIS')
cls.enum('KEY_ASTERISK', 'cocos2d::EventKeyboard::KeyCode::KEY_ASTERISK')
cls.enum('KEY_PLUS', 'cocos2d::EventKeyboard::KeyCode::KEY_PLUS')
cls.enum('KEY_COMMA', 'cocos2d::EventKeyboard::KeyCode::KEY_COMMA')
cls.enum('KEY_MINUS', 'cocos2d::EventKeyboard::KeyCode::KEY_MINUS')
cls.enum('KEY_PERIOD', 'cocos2d::EventKeyboard::KeyCode::KEY_PERIOD')
cls.enum('KEY_SLASH', 'cocos2d::EventKeyboard::KeyCode::KEY_SLASH')
cls.enum('KEY_0', 'cocos2d::EventKeyboard::KeyCode::KEY_0')
cls.enum('KEY_1', 'cocos2d::EventKeyboard::KeyCode::KEY_1')
cls.enum('KEY_2', 'cocos2d::EventKeyboard::KeyCode::KEY_2')
cls.enum('KEY_3', 'cocos2d::EventKeyboard::KeyCode::KEY_3')
cls.enum('KEY_4', 'cocos2d::EventKeyboard::KeyCode::KEY_4')
cls.enum('KEY_5', 'cocos2d::EventKeyboard::KeyCode::KEY_5')
cls.enum('KEY_6', 'cocos2d::EventKeyboard::KeyCode::KEY_6')
cls.enum('KEY_7', 'cocos2d::EventKeyboard::KeyCode::KEY_7')
cls.enum('KEY_8', 'cocos2d::EventKeyboard::KeyCode::KEY_8')
cls.enum('KEY_9', 'cocos2d::EventKeyboard::KeyCode::KEY_9')
cls.enum('KEY_COLON', 'cocos2d::EventKeyboard::KeyCode::KEY_COLON')
cls.enum('KEY_SEMICOLON', 'cocos2d::EventKeyboard::KeyCode::KEY_SEMICOLON')
cls.enum('KEY_LESS_THAN', 'cocos2d::EventKeyboard::KeyCode::KEY_LESS_THAN')
cls.enum('KEY_EQUAL', 'cocos2d::EventKeyboard::KeyCode::KEY_EQUAL')
cls.enum('KEY_GREATER_THAN', 'cocos2d::EventKeyboard::KeyCode::KEY_GREATER_THAN')
cls.enum('KEY_QUESTION', 'cocos2d::EventKeyboard::KeyCode::KEY_QUESTION')
cls.enum('KEY_AT', 'cocos2d::EventKeyboard::KeyCode::KEY_AT')
cls.enum('KEY_CAPITAL_A', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_A')
cls.enum('KEY_CAPITAL_B', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_B')
cls.enum('KEY_CAPITAL_C', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_C')
cls.enum('KEY_CAPITAL_D', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_D')
cls.enum('KEY_CAPITAL_E', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_E')
cls.enum('KEY_CAPITAL_F', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_F')
cls.enum('KEY_CAPITAL_G', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_G')
cls.enum('KEY_CAPITAL_H', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_H')
cls.enum('KEY_CAPITAL_I', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_I')
cls.enum('KEY_CAPITAL_J', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_J')
cls.enum('KEY_CAPITAL_K', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_K')
cls.enum('KEY_CAPITAL_L', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_L')
cls.enum('KEY_CAPITAL_M', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_M')
cls.enum('KEY_CAPITAL_N', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_N')
cls.enum('KEY_CAPITAL_O', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_O')
cls.enum('KEY_CAPITAL_P', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_P')
cls.enum('KEY_CAPITAL_Q', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_Q')
cls.enum('KEY_CAPITAL_R', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_R')
cls.enum('KEY_CAPITAL_S', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_S')
cls.enum('KEY_CAPITAL_T', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_T')
cls.enum('KEY_CAPITAL_U', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_U')
cls.enum('KEY_CAPITAL_V', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_V')
cls.enum('KEY_CAPITAL_W', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_W')
cls.enum('KEY_CAPITAL_X', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_X')
cls.enum('KEY_CAPITAL_Y', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_Y')
cls.enum('KEY_CAPITAL_Z', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_Z')
cls.enum('KEY_LEFT_BRACKET', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_BRACKET')
cls.enum('KEY_BACK_SLASH', 'cocos2d::EventKeyboard::KeyCode::KEY_BACK_SLASH')
cls.enum('KEY_RIGHT_BRACKET', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_BRACKET')
cls.enum('KEY_UNDERSCORE', 'cocos2d::EventKeyboard::KeyCode::KEY_UNDERSCORE')
cls.enum('KEY_GRAVE', 'cocos2d::EventKeyboard::KeyCode::KEY_GRAVE')
cls.enum('KEY_A', 'cocos2d::EventKeyboard::KeyCode::KEY_A')
cls.enum('KEY_B', 'cocos2d::EventKeyboard::KeyCode::KEY_B')
cls.enum('KEY_C', 'cocos2d::EventKeyboard::KeyCode::KEY_C')
cls.enum('KEY_D', 'cocos2d::EventKeyboard::KeyCode::KEY_D')
cls.enum('KEY_E', 'cocos2d::EventKeyboard::KeyCode::KEY_E')
cls.enum('KEY_F', 'cocos2d::EventKeyboard::KeyCode::KEY_F')
cls.enum('KEY_G', 'cocos2d::EventKeyboard::KeyCode::KEY_G')
cls.enum('KEY_H', 'cocos2d::EventKeyboard::KeyCode::KEY_H')
cls.enum('KEY_I', 'cocos2d::EventKeyboard::KeyCode::KEY_I')
cls.enum('KEY_J', 'cocos2d::EventKeyboard::KeyCode::KEY_J')
cls.enum('KEY_K', 'cocos2d::EventKeyboard::KeyCode::KEY_K')
cls.enum('KEY_L', 'cocos2d::EventKeyboard::KeyCode::KEY_L')
cls.enum('KEY_M', 'cocos2d::EventKeyboard::KeyCode::KEY_M')
cls.enum('KEY_N', 'cocos2d::EventKeyboard::KeyCode::KEY_N')
cls.enum('KEY_O', 'cocos2d::EventKeyboard::KeyCode::KEY_O')
cls.enum('KEY_P', 'cocos2d::EventKeyboard::KeyCode::KEY_P')
cls.enum('KEY_Q', 'cocos2d::EventKeyboard::KeyCode::KEY_Q')
cls.enum('KEY_R', 'cocos2d::EventKeyboard::KeyCode::KEY_R')
cls.enum('KEY_S', 'cocos2d::EventKeyboard::KeyCode::KEY_S')
cls.enum('KEY_T', 'cocos2d::EventKeyboard::KeyCode::KEY_T')
cls.enum('KEY_U', 'cocos2d::EventKeyboard::KeyCode::KEY_U')
cls.enum('KEY_V', 'cocos2d::EventKeyboard::KeyCode::KEY_V')
cls.enum('KEY_W', 'cocos2d::EventKeyboard::KeyCode::KEY_W')
cls.enum('KEY_X', 'cocos2d::EventKeyboard::KeyCode::KEY_X')
cls.enum('KEY_Y', 'cocos2d::EventKeyboard::KeyCode::KEY_Y')
cls.enum('KEY_Z', 'cocos2d::EventKeyboard::KeyCode::KEY_Z')
cls.enum('KEY_LEFT_BRACE', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_BRACE')
cls.enum('KEY_BAR', 'cocos2d::EventKeyboard::KeyCode::KEY_BAR')
cls.enum('KEY_RIGHT_BRACE', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_BRACE')
cls.enum('KEY_TILDE', 'cocos2d::EventKeyboard::KeyCode::KEY_TILDE')
cls.enum('KEY_EURO', 'cocos2d::EventKeyboard::KeyCode::KEY_EURO')
cls.enum('KEY_POUND', 'cocos2d::EventKeyboard::KeyCode::KEY_POUND')
cls.enum('KEY_YEN', 'cocos2d::EventKeyboard::KeyCode::KEY_YEN')
cls.enum('KEY_MIDDLE_DOT', 'cocos2d::EventKeyboard::KeyCode::KEY_MIDDLE_DOT')
cls.enum('KEY_SEARCH', 'cocos2d::EventKeyboard::KeyCode::KEY_SEARCH')
cls.enum('KEY_DPAD_LEFT', 'cocos2d::EventKeyboard::KeyCode::KEY_DPAD_LEFT')
cls.enum('KEY_DPAD_RIGHT', 'cocos2d::EventKeyboard::KeyCode::KEY_DPAD_RIGHT')
cls.enum('KEY_DPAD_UP', 'cocos2d::EventKeyboard::KeyCode::KEY_DPAD_UP')
cls.enum('KEY_DPAD_DOWN', 'cocos2d::EventKeyboard::KeyCode::KEY_DPAD_DOWN')
cls.enum('KEY_DPAD_CENTER', 'cocos2d::EventKeyboard::KeyCode::KEY_DPAD_CENTER')
cls.enum('KEY_ENTER', 'cocos2d::EventKeyboard::KeyCode::KEY_ENTER')
cls.enum('KEY_PLAY', 'cocos2d::EventKeyboard::KeyCode::KEY_PLAY')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Touch::DispatchMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ALL_AT_ONCE', 'cocos2d::Touch::DispatchMode::ALL_AT_ONCE')
cls.enum('ONE_BY_ONE', 'cocos2d::Touch::DispatchMode::ONE_BY_ONE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventController::ControllerEventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('CONNECTION', 'cocos2d::EventController::ControllerEventType::CONNECTION')
cls.enum('BUTTON_STATUS_CHANGED', 'cocos2d::EventController::ControllerEventType::BUTTON_STATUS_CHANGED')
cls.enum('AXIS_STATUS_CHANGED', 'cocos2d::EventController::ControllerEventType::AXIS_STATUS_CHANGED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EventController'
cls.SUPERCLS = 'cocos2d::Event'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'EventController(cocos2d::EventController::ControllerEventType type, cocos2d::Controller *controller, int keyCode)', 'EventController(cocos2d::EventController::ControllerEventType type, cocos2d::Controller *controller, bool isConnected)')
cls.func(nil, 'cocos2d::EventController::ControllerEventType getControllerEventType()')
cls.func(nil, 'cocos2d::Controller *getController()')
cls.func(nil, 'int getKeyCode()')
cls.func(nil, 'void setKeyCode(int keyCode)')
cls.func(nil, 'void setConnectStatus(bool isConnected)')
cls.func(nil, 'bool isConnected()')
cls.prop('controllerEventType', nil, nil)
cls.prop('controller', nil, nil)
cls.prop('keyCode', nil, nil)
cls.prop('connected', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Touch'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Touch()')
cls.func(nil, 'cocos2d::Vec2 getLocation()')
cls.func(nil, 'cocos2d::Vec2 getPreviousLocation()')
cls.func(nil, 'cocos2d::Vec2 getStartLocation()')
cls.func(nil, 'cocos2d::Vec2 getDelta()')
cls.func(nil, 'cocos2d::Vec2 getLocationInView()')
cls.func(nil, 'cocos2d::Vec2 getPreviousLocationInView()')
cls.func(nil, 'cocos2d::Vec2 getStartLocationInView()')
cls.func(nil, 'void setTouchInfo(int id, float x, float y)', 'void setTouchInfo(int id, float x, float y, float force, float maxForce)')
cls.func(nil, 'int getID()')
cls.func(nil, 'float getCurrentForce()')
cls.func(nil, 'float getMaxForce()')
cls.prop('location', nil, nil)
cls.prop('previousLocation', nil, nil)
cls.prop('startLocation', nil, nil)
cls.prop('delta', nil, nil)
cls.prop('locationInView', nil, nil)
cls.prop('previousLocationInView', nil, nil)
cls.prop('startLocationInView', nil, nil)
cls.prop('id', nil, nil)
cls.prop('currentForce', nil, nil)
cls.prop('maxForce', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Controller::Key'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('KEY_NONE', 'cocos2d::Controller::Key::KEY_NONE')
cls.enum('JOYSTICK_LEFT_X', 'cocos2d::Controller::Key::JOYSTICK_LEFT_X')
cls.enum('JOYSTICK_LEFT_Y', 'cocos2d::Controller::Key::JOYSTICK_LEFT_Y')
cls.enum('JOYSTICK_RIGHT_X', 'cocos2d::Controller::Key::JOYSTICK_RIGHT_X')
cls.enum('JOYSTICK_RIGHT_Y', 'cocos2d::Controller::Key::JOYSTICK_RIGHT_Y')
cls.enum('BUTTON_A', 'cocos2d::Controller::Key::BUTTON_A')
cls.enum('BUTTON_B', 'cocos2d::Controller::Key::BUTTON_B')
cls.enum('BUTTON_C', 'cocos2d::Controller::Key::BUTTON_C')
cls.enum('BUTTON_X', 'cocos2d::Controller::Key::BUTTON_X')
cls.enum('BUTTON_Y', 'cocos2d::Controller::Key::BUTTON_Y')
cls.enum('BUTTON_Z', 'cocos2d::Controller::Key::BUTTON_Z')
cls.enum('BUTTON_DPAD_UP', 'cocos2d::Controller::Key::BUTTON_DPAD_UP')
cls.enum('BUTTON_DPAD_DOWN', 'cocos2d::Controller::Key::BUTTON_DPAD_DOWN')
cls.enum('BUTTON_DPAD_LEFT', 'cocos2d::Controller::Key::BUTTON_DPAD_LEFT')
cls.enum('BUTTON_DPAD_RIGHT', 'cocos2d::Controller::Key::BUTTON_DPAD_RIGHT')
cls.enum('BUTTON_DPAD_CENTER', 'cocos2d::Controller::Key::BUTTON_DPAD_CENTER')
cls.enum('BUTTON_LEFT_SHOULDER', 'cocos2d::Controller::Key::BUTTON_LEFT_SHOULDER')
cls.enum('BUTTON_RIGHT_SHOULDER', 'cocos2d::Controller::Key::BUTTON_RIGHT_SHOULDER')
cls.enum('AXIS_LEFT_TRIGGER', 'cocos2d::Controller::Key::AXIS_LEFT_TRIGGER')
cls.enum('AXIS_RIGHT_TRIGGER', 'cocos2d::Controller::Key::AXIS_RIGHT_TRIGGER')
cls.enum('BUTTON_LEFT_THUMBSTICK', 'cocos2d::Controller::Key::BUTTON_LEFT_THUMBSTICK')
cls.enum('BUTTON_RIGHT_THUMBSTICK', 'cocos2d::Controller::Key::BUTTON_RIGHT_THUMBSTICK')
cls.enum('BUTTON_START', 'cocos2d::Controller::Key::BUTTON_START')
cls.enum('BUTTON_SELECT', 'cocos2d::Controller::Key::BUTTON_SELECT')
cls.enum('BUTTON_PAUSE', 'cocos2d::Controller::Key::BUTTON_PAUSE')
cls.enum('KEY_MAX', 'cocos2d::Controller::Key::KEY_MAX')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Controller'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('TAG_UNSET', 'cocos2d::Controller::TAG_UNSET', 'const int')
cls.func(nil, 'static const std::vector<Controller *> &getAllController()')
cls.func(nil, 'static cocos2d::Controller *getControllerByTag(int tag)')
cls.func(nil, 'static cocos2d::Controller *getControllerByDeviceId(int deviceId)')
cls.func(nil, 'static void startDiscoveryController()')
cls.func(nil, 'static void stopDiscoveryController()')
cls.func(nil, 'const std::string &getDeviceName()')
cls.func(nil, 'int getDeviceId()')
cls.func(nil, 'bool isConnected()')
cls.func(nil, 'const cocos2d::Controller::KeyStatus &getKeyStatus(int keyCode)')
cls.func(nil, 'void setTag(int tag)')
cls.func(nil, 'int getTag()')
cls.prop('allController', nil, nil)
cls.prop('deviceName', nil, nil)
cls.prop('deviceId', nil, nil)
cls.prop('connected', nil, nil)
cls.prop('tag', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AudioProfile'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'AudioProfile()')
cls.var('name', 'std::string name')
cls.var('maxInstances', 'unsigned int maxInstances')
cls.var('minDelay', 'double minDelay')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AudioEngine::AudioState'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ERROR', 'cocos2d::AudioEngine::AudioState::ERROR')
cls.enum('INITIALIZING', 'cocos2d::AudioEngine::AudioState::INITIALIZING')
cls.enum('PLAYING', 'cocos2d::AudioEngine::AudioState::PLAYING')
cls.enum('PAUSED', 'cocos2d::AudioEngine::AudioState::PAUSED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AudioEngine'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
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
cls.func(nil, 'static bool lazyInit()')
cls.func(nil, 'static void end()')
cls.func(nil, 'static cocos2d::AudioProfile *getDefaultProfile()')
cls.func(nil, 'static int play2d(const std::string &filePath, @optional bool loop, @optional float volume, @optional const cocos2d::AudioProfile *profile)')
cls.func(nil, 'static void setLoop(int audioID, bool loop)')
cls.func(nil, 'static bool isLoop(int audioID)')
cls.func(nil, 'static void setVolume(int audioID, float volume)')
cls.func(nil, 'static float getVolume(int audioID)')
cls.func(nil, 'static void pause(int audioID)')
cls.func(nil, 'static void pauseAll()')
cls.func(nil, 'static void resume(int audioID)')
cls.func(nil, 'static void resumeAll()')
cls.func(nil, 'static bool setCurrentTime(int audioID, float sec)')
cls.func(nil, 'static float getCurrentTime(int audioID)')
cls.func(nil, 'static float getDuration(int audioID)')
cls.func(nil, 'static cocos2d::AudioEngine::AudioState getState(int audioID)')
cls.func(nil, 'static int getMaxAudioInstance()')
cls.func(nil, 'static bool setMaxAudioInstance(int maxInstances)')
cls.func(nil, 'static void uncache(const std::string &filePath)')
cls.func(nil, 'static cocos2d::AudioProfile *getProfile(int audioID)', 'static cocos2d::AudioProfile *getProfile(const std::string &profileName)')
cls.func(nil, 'static int getPlayingAudioCount()')
cls.func(nil, 'static void setEnabled(bool isEnabled)')
cls.func(nil, 'static bool isEnabled()')
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
cls.prop('defaultProfile', nil, nil)
cls.prop('maxAudioInstance', nil, nil)
cls.prop('playingAudioCount', nil, nil)
cls.prop('enabled', nil, nil)
cls.insert('uncache', {
    BEFORE = [[
        std::string path = olua_checkstring(L, 1);
        std::list<int> ids = cocos2d::LuaAudioEngine::getAudioIDs(path);
        void *cb_store = olua_pushclassobj<cocos2d::AudioEngine>(L);
        for (auto id : ids) {
            std::string tag = makeAudioEngineFinishCallbackTag((lua_Integer)id);
            olua_removecallback(L, cb_store, tag.c_str(), OLUA_TAG_SUBEQUAL);
        }
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ApplicationProtocol::Platform'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('OS_WINDOWS', 'cocos2d::ApplicationProtocol::Platform::OS_WINDOWS')
cls.enum('OS_LINUX', 'cocos2d::ApplicationProtocol::Platform::OS_LINUX')
cls.enum('OS_MAC', 'cocos2d::ApplicationProtocol::Platform::OS_MAC')
cls.enum('OS_ANDROID', 'cocos2d::ApplicationProtocol::Platform::OS_ANDROID')
cls.enum('OS_IPHONE', 'cocos2d::ApplicationProtocol::Platform::OS_IPHONE')
cls.enum('OS_IPAD', 'cocos2d::ApplicationProtocol::Platform::OS_IPAD')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LanguageType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ENGLISH', 'cocos2d::LanguageType::ENGLISH')
cls.enum('CHINESE', 'cocos2d::LanguageType::CHINESE')
cls.enum('FRENCH', 'cocos2d::LanguageType::FRENCH')
cls.enum('ITALIAN', 'cocos2d::LanguageType::ITALIAN')
cls.enum('GERMAN', 'cocos2d::LanguageType::GERMAN')
cls.enum('SPANISH', 'cocos2d::LanguageType::SPANISH')
cls.enum('DUTCH', 'cocos2d::LanguageType::DUTCH')
cls.enum('RUSSIAN', 'cocos2d::LanguageType::RUSSIAN')
cls.enum('KOREAN', 'cocos2d::LanguageType::KOREAN')
cls.enum('JAPANESE', 'cocos2d::LanguageType::JAPANESE')
cls.enum('HUNGARIAN', 'cocos2d::LanguageType::HUNGARIAN')
cls.enum('PORTUGUESE', 'cocos2d::LanguageType::PORTUGUESE')
cls.enum('ARABIC', 'cocos2d::LanguageType::ARABIC')
cls.enum('NORWEGIAN', 'cocos2d::LanguageType::NORWEGIAN')
cls.enum('POLISH', 'cocos2d::LanguageType::POLISH')
cls.enum('TURKISH', 'cocos2d::LanguageType::TURKISH')
cls.enum('UKRAINIAN', 'cocos2d::LanguageType::UKRAINIAN')
cls.enum('ROMANIAN', 'cocos2d::LanguageType::ROMANIAN')
cls.enum('BULGARIAN', 'cocos2d::LanguageType::BULGARIAN')
cls.enum('BELARUSIAN', 'cocos2d::LanguageType::BELARUSIAN')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ApplicationProtocol'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'bool applicationDidFinishLaunching()')
cls.func(nil, 'void applicationDidEnterBackground()')
cls.func(nil, 'void applicationWillEnterForeground()')
cls.func(nil, 'void setAnimationInterval(float interval)')
cls.func(nil, 'void initGLContextAttrs()')
cls.func(nil, 'cocos2d::LanguageType getCurrentLanguage()')
cls.func(nil, 'const char *getCurrentLanguageCode()')
cls.func(nil, 'cocos2d::ApplicationProtocol::Platform getTargetPlatform()')
cls.func(nil, 'std::string getVersion()')
cls.func(nil, 'bool openURL(const std::string &url)')
cls.prop('currentLanguage', nil, nil)
cls.prop('currentLanguageCode', nil, nil)
cls.prop('targetPlatform', nil, nil)
cls.prop('version', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Application'
cls.SUPERCLS = 'cocos2d::ApplicationProtocol'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'int run()')
cls.func(nil, 'static cocos2d::Application *getInstance()')
cls.prop('instance', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Device'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static int getDPI()')
cls.func(nil, 'static void setAccelerometerEnabled(bool isEnabled)')
cls.func(nil, 'static void setAccelerometerInterval(float interval)')
cls.func(nil, 'static void setKeepScreenOn(bool keepScreenOn)')
cls.func(nil, 'static void vibrate(float duration)')
cls.prop('dpi', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ResizableBuffer'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void resize(size_t size)')
cls.func(nil, 'void *buffer()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FileUtils::Status'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('OK', 'cocos2d::FileUtils::Status::OK')
cls.enum('NotExists', 'cocos2d::FileUtils::Status::NotExists')
cls.enum('OpenFailed', 'cocos2d::FileUtils::Status::OpenFailed')
cls.enum('ReadFailed', 'cocos2d::FileUtils::Status::ReadFailed')
cls.enum('NotInitialized', 'cocos2d::FileUtils::Status::NotInitialized')
cls.enum('TooLarge', 'cocos2d::FileUtils::Status::TooLarge')
cls.enum('ObtainSizeFailed', 'cocos2d::FileUtils::Status::ObtainSizeFailed')
cls.enum('NotRegularFileType', 'cocos2d::FileUtils::Status::NotRegularFileType')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FileUtils'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FileUtils *getInstance()')
cls.func(nil, 'static void destroyInstance()')
cls.func(nil, 'static void setDelegate(cocos2d::FileUtils *delegate)')
cls.func(nil, 'void purgeCachedEntries()')
cls.func(nil, 'cocos2d::FileUtils::Status getContents(const std::string &filename, cocos2d::ResizableBuffer *buffer)')
cls.func(nil, '@length(arg3) unsigned char *getFileDataFromZip(const std::string &zipFilePath, const std::string &filename, @out ssize_t *size)')
cls.func(nil, 'std::string fullPathForFilename(const std::string &filename)')
cls.func(nil, 'void loadFilenameLookupDictionaryFromFile(const std::string &filename)')
cls.func(nil, 'void setFilenameLookupDictionary(const cocos2d::ValueMap &filenameLookupDict)')
cls.func(nil, 'std::string fullPathFromRelativeFile(const std::string &filename, const std::string &relativeFile)')
cls.func(nil, 'void setSearchResolutionsOrder(const std::vector<std::string> &searchResolutionsOrder)')
cls.func(nil, 'void addSearchResolutionsOrder(const std::string &order, @optional const bool front)')
cls.func(nil, 'const std::vector<std::string> getSearchResolutionsOrder()')
cls.func(nil, 'void setSearchPaths(const std::vector<std::string> &searchPaths)')
cls.func(nil, 'const std::string getDefaultResourceRootPath()')
cls.func(nil, 'void setDefaultResourceRootPath(const std::string &path)')
cls.func(nil, 'void addSearchPath(const std::string &path, @optional const bool front)')
cls.func(nil, 'const std::vector<std::string> getSearchPaths()')
cls.func(nil, 'const std::vector<std::string> getOriginalSearchPaths()')
cls.func(nil, 'std::string getWritablePath()')
cls.func(nil, 'void setWritablePath(const std::string &writablePath)')
cls.func(nil, 'void setPopupNotify(bool notify)')
cls.func(nil, 'bool isPopupNotify()')
cls.func(nil, 'cocos2d::ValueMap getValueMapFromFile(const std::string &filename)')
cls.func(nil, 'cocos2d::ValueMap getValueMapFromData(const char *filedata, int filesize)')
cls.func(nil, 'bool writeToFile(const cocos2d::ValueMap &dict, const std::string &fullPath)')
cls.func(nil, 'std::string getSuitableFOpen(const std::string &filenameUtf8)')
cls.func(nil, 'cocos2d::ValueVector getValueVectorFromFile(const std::string &filename)')
cls.func(nil, 'std::string getFileExtension(const std::string &filePath)')
cls.func(nil, 'bool isAbsolutePath(const std::string &path)')
cls.func(nil, 'std::vector<std::string> listFiles(const std::string &dirPath)')
cls.func(nil, 'void listFilesRecursively(const std::string &dirPath, @out std::vector<std::string> *files)')
cls.func(nil, 'const std::unordered_map<std::string, std::string> getFullPathCache()')
cls.func(nil, 'std::string getNewFilename(const std::string &filename)')
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
cls.prop('instance', nil, nil)
cls.prop('searchResolutionsOrder', nil, nil)
cls.prop('defaultResourceRootPath', nil, nil)
cls.prop('searchPaths', nil, nil)
cls.prop('originalSearchPaths', nil, nil)
cls.prop('writablePath', nil, nil)
cls.prop('popupNotify', nil, nil)
cls.prop('fullPathCache', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'ResolutionPolicy'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('EXACT_FIT', 'ResolutionPolicy::EXACT_FIT')
cls.enum('NO_BORDER', 'ResolutionPolicy::NO_BORDER')
cls.enum('SHOW_ALL', 'ResolutionPolicy::SHOW_ALL')
cls.enum('FIXED_HEIGHT', 'ResolutionPolicy::FIXED_HEIGHT')
cls.enum('FIXED_WIDTH', 'ResolutionPolicy::FIXED_WIDTH')
cls.enum('UNKNOWN', 'ResolutionPolicy::UNKNOWN')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GLView'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void end()')
cls.func(nil, 'bool isOpenGLReady()')
cls.func(nil, 'void swapBuffers()')
cls.func(nil, 'void setIMEKeyboardState(bool open)')
cls.func(nil, 'bool windowShouldClose()')
cls.func(nil, 'static void setGLContextAttrs(GLContextAttrs &glContextAttrs)')
cls.func(nil, 'static GLContextAttrs getGLContextAttrs()')
cls.func(nil, 'void pollEvents()')
cls.func(nil, 'cocos2d::Size getFrameSize()')
cls.func(nil, 'void setFrameSize(float width, float height)')
cls.func(nil, 'void setFrameZoomFactor(float )')
cls.func(nil, 'float getFrameZoomFactor()')
cls.func(nil, 'void setCursorVisible(bool )')
cls.func(nil, 'int getRetinaFactor()')
cls.func(nil, 'bool setContentScaleFactor(float )')
cls.func(nil, 'float getContentScaleFactor()')
cls.func(nil, 'bool isRetinaDisplay()')
cls.func(nil, 'cocos2d::Size getVisibleSize()')
cls.func(nil, 'cocos2d::Vec2 getVisibleOrigin()')
cls.func(nil, 'cocos2d::Rect getVisibleRect()')
cls.func(nil, 'cocos2d::Rect getSafeAreaRect()')
cls.func(nil, 'void setDesignResolutionSize(float width, float height, ResolutionPolicy resolutionPolicy)')
cls.func(nil, 'const cocos2d::Size &getDesignResolutionSize()')
cls.func(nil, 'void setViewPortInPoints(float x, float y, float w, float h)')
cls.func(nil, 'void setScissorInPoints(float x, float y, float w, float h)')
cls.func(nil, 'bool isScissorEnabled()')
cls.func(nil, 'cocos2d::Rect getScissorRect()')
cls.func(nil, 'void setViewName(const std::string &viewname)')
cls.func(nil, 'const std::string &getViewName()')
cls.func(nil, 'void setIcon(const std::string &filename)', 'void setIcon(const std::vector<std::string> &filelist)')
cls.func(nil, 'void setDefaultIcon()')
cls.func(nil, 'const cocos2d::Rect &getViewPortRect()')
cls.func(nil, 'std::vector<Touch *> getAllTouches()')
cls.func(nil, 'float getScaleX()')
cls.func(nil, 'float getScaleY()')
cls.func(nil, 'ResolutionPolicy getResolutionPolicy()')
cls.func(nil, 'void renderScene(cocos2d::Scene *scene, cocos2d::Renderer *renderer)')
cls.prop('openGLReady', nil, nil)
cls.prop('glContextAttrs', nil, nil)
cls.prop('frameSize', nil, nil)
cls.prop('frameZoomFactor', nil, nil)
cls.prop('retinaFactor', nil, nil)
cls.prop('contentScaleFactor', nil, nil)
cls.prop('retinaDisplay', nil, nil)
cls.prop('visibleSize', nil, nil)
cls.prop('visibleOrigin', nil, nil)
cls.prop('visibleRect', nil, nil)
cls.prop('safeAreaRect', nil, nil)
cls.prop('designResolutionSize', nil, nil)
cls.prop('scissorEnabled', nil, nil)
cls.prop('scissorRect', nil, nil)
cls.prop('viewName', nil, nil)
cls.prop('viewPortRect', nil, nil)
cls.prop('allTouches', nil, nil)
cls.prop('scaleX', nil, nil)
cls.prop('scaleY', nil, nil)
cls.prop('resolutionPolicy', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GLViewImpl'
cls.SUPERCLS = 'cocos2d::GLView'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Image::Format'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('JPG', 'cocos2d::Image::Format::JPG')
cls.enum('PNG', 'cocos2d::Image::Format::PNG')
cls.enum('WEBP', 'cocos2d::Image::Format::WEBP')
cls.enum('PVR', 'cocos2d::Image::Format::PVR')
cls.enum('ETC', 'cocos2d::Image::Format::ETC')
cls.enum('S3TC', 'cocos2d::Image::Format::S3TC')
cls.enum('ATITC', 'cocos2d::Image::Format::ATITC')
cls.enum('TGA', 'cocos2d::Image::Format::TGA')
cls.enum('RAW_DATA', 'cocos2d::Image::Format::RAW_DATA')
cls.enum('UNKNOWN', 'cocos2d::Image::Format::UNKNOWN')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Image'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = [[
    NS_CC_BEGIN
    class LuaImage : public cocos2d::Image {
    public:
        static bool getPNGPremultipliedAlphaEnabled() { return PNG_PREMULTIPLIED_ALPHA_ENABLED; };
    };
    NS_CC_END
]]
cls.func('getPNGPremultipliedAlphaEnabled', [[
    {
        lua_pushboolean(L, cocos2d::LuaImage::getPNGPremultipliedAlphaEnabled());
        return 1;
    }
]])
cls.func(nil, 'Image()')
cls.func(nil, 'static void setPNGPremultipliedAlphaEnabled(bool enabled)')
cls.func(nil, 'static void setPVRImagesHavePremultipliedAlpha(bool haveAlphaPremultiplied)')
cls.func(nil, 'bool initWithImageFile(const std::string &path)')
cls.func(nil, 'bool initWithImageData(const unsigned char *data, ssize_t dataLen)')
cls.func(nil, 'bool initWithRawData(const unsigned char *data, ssize_t dataLen, int width, int height, int bitsPerComponent, @optional bool preMulti)')
cls.func(nil, 'unsigned char *getData()')
cls.func(nil, 'ssize_t getDataLen()')
cls.func(nil, 'cocos2d::Image::Format getFileType()')
cls.func(nil, 'cocos2d::backend::PixelFormat getPixelFormat()')
cls.func(nil, 'int getWidth()')
cls.func(nil, 'int getHeight()')
cls.func(nil, 'int getNumberOfMipmaps()')
cls.func(nil, 'bool hasPremultipliedAlpha()')
cls.func(nil, 'std::string getFilePath()')
cls.func(nil, 'int getBitPerPixel()')
cls.func(nil, 'bool hasAlpha()')
cls.func(nil, 'bool isCompressed()')
cls.func(nil, 'bool saveToFile(const std::string &filename, @optional bool isToRGB)')
cls.func(nil, 'void premultiplyAlpha()')
cls.func(nil, 'void reversePremultipliedAlpha()')
cls.prop('data', nil, nil)
cls.prop('dataLen', nil, nil)
cls.prop('fileType', nil, nil)
cls.prop('pixelFormat', nil, nil)
cls.prop('width', nil, nil)
cls.prop('height', nil, nil)
cls.prop('numberOfMipmaps', nil, nil)
cls.prop('filePath', nil, nil)
cls.prop('bitPerPixel', nil, nil)
cls.prop('compressed', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Properties::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::Properties::Type::NONE')
cls.enum('STRING', 'cocos2d::Properties::Type::STRING')
cls.enum('NUMBER', 'cocos2d::Properties::Type::NUMBER')
cls.enum('VECTOR2', 'cocos2d::Properties::Type::VECTOR2')
cls.enum('VECTOR3', 'cocos2d::Properties::Type::VECTOR3')
cls.enum('VECTOR4', 'cocos2d::Properties::Type::VECTOR4')
cls.enum('MATRIX', 'cocos2d::Properties::Type::MATRIX')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Properties'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Properties *createNonRefCounted(const std::string &url)')
cls.func(nil, 'const char *getNextProperty()')
cls.func(nil, 'cocos2d::Properties *getNextNamespace()')
cls.func(nil, 'void rewind()')
cls.func(nil, 'cocos2d::Properties *getNamespace(const char *id, @optional bool searchNames, @optional bool recurse)', 'const char *getNamespace()')
cls.func(nil, 'const char *getId()')
cls.func(nil, 'bool exists(const char *name)')
cls.func(nil, 'cocos2d::Properties::Type getType(@optional const char *name)')
cls.func(nil, 'const char *getString(@optional const char *name, @optional const char *defaultValue)')
cls.func(nil, 'bool setString(const char *name, const char *value)')
cls.func(nil, 'bool getBool(@optional const char *name, @optional bool defaultValue)')
cls.func(nil, 'int getInt(@optional const char *name)')
cls.func(nil, 'float getFloat(@optional const char *name)')
cls.func(nil, 'long getLong(@optional const char *name)')
cls.func(nil, 'bool getPath(const char *name, @out std::string *path)')
cls.func(nil, 'const char *getVariable(const char *name, @optional const char *defaultValue)')
cls.func(nil, 'void setVariable(const char *name, const char *value)')
cls.prop('nextProperty', nil, nil)
cls.prop('nextNamespace', nil, nil)
cls.prop('id', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Material'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Material *createWithFilename(const std::string &path)')
cls.func(nil, 'static cocos2d::Material *createWithProgramState(cocos2d::backend::ProgramState *programState)')
cls.func(nil, 'static cocos2d::Material *createWithProperties(cocos2d::Properties *materialProperties)')
cls.func(nil, 'void draw(cocos2d::MeshCommand *meshCommand, float globalZOrder, cocos2d::backend::Buffer *vertexBuffer, cocos2d::backend::Buffer *indexBuffer, cocos2d::CustomCommand::PrimitiveType primitive, cocos2d::CustomCommand::IndexFormat indexFormat, unsigned int indexCount, const cocos2d::Mat4 &modelView)')
cls.func(nil, 'std::string getName()')
cls.func(nil, 'void setName(const std::string &name)')
cls.func(nil, 'cocos2d::Technique *getTechniqueByName(const std::string &name)')
cls.func(nil, 'cocos2d::Technique *getTechniqueByIndex(ssize_t index)')
cls.func(nil, 'cocos2d::Technique *getTechnique()')
cls.func(nil, 'const Vector<cocos2d::Technique *> &getTechniques()')
cls.func(nil, 'ssize_t getTechniqueCount()')
cls.func(nil, 'void addTechnique(cocos2d::Technique *technique)')
cls.func(nil, 'void setTechnique(const std::string &techniqueName)')
cls.func(nil, 'cocos2d::Material *clone()')
cls.func(nil, 'cocos2d::RenderState *getRenderState()')
cls.prop('name', nil, nil)
cls.prop('technique', nil, nil)
cls.prop('techniques', nil, nil)
cls.prop('techniqueCount', nil, nil)
cls.prop('renderState', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Renderer'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('VBO_SIZE', 'cocos2d::Renderer::VBO_SIZE', 'const int')
cls.const('INDEX_VBO_SIZE', 'cocos2d::Renderer::INDEX_VBO_SIZE', 'const int')
cls.const('BATCH_TRIAGCOMMAND_RESERVED_SIZE', 'cocos2d::Renderer::BATCH_TRIAGCOMMAND_RESERVED_SIZE', 'const int')
cls.const('MATERIAL_ID_DO_NOT_BATCH', 'cocos2d::Renderer::MATERIAL_ID_DO_NOT_BATCH', 'const int')
cls.func(nil, 'Renderer()')
cls.func(nil, 'void init()')
cls.func(nil, 'void drawCommand(cocos2d::RenderCommand *command)')
cls.func(nil, 'void addCommand(cocos2d::RenderCommand *command)', 'void addCommand(cocos2d::RenderCommand *command, int renderQueueID)')
cls.func(nil, 'void pushGroup(int renderQueueID)')
cls.func(nil, 'void popGroup()')
cls.func(nil, 'int createRenderQueue()')
cls.func(nil, 'void render()')
cls.func(nil, 'void clean()')
cls.func(nil, 'ssize_t getDrawnBatches()')
cls.func(nil, 'void addDrawnBatches(ssize_t number)')
cls.func(nil, 'ssize_t getDrawnVertices()')
cls.func(nil, 'void addDrawnVertices(ssize_t number)')
cls.func(nil, 'void clearDrawStats()')
cls.func(nil, 'void setRenderTarget(cocos2d::RenderTargetFlag flags, cocos2d::Texture2D *colorAttachment, cocos2d::Texture2D *depthAttachment, cocos2d::Texture2D *stencilAttachment)')
cls.func(nil, 'void clear(cocos2d::ClearFlag flags, const cocos2d::Color4F &color, float depth, unsigned int stencil, float globalOrder)')
cls.func(nil, 'cocos2d::Texture2D *getColorAttachment()')
cls.func(nil, 'cocos2d::Texture2D *getDepthAttachment()')
cls.func(nil, 'cocos2d::Texture2D *getStencilAttachment()')
cls.func(nil, 'const cocos2d::Color4F &getClearColor()')
cls.func(nil, 'float getClearDepth()')
cls.func(nil, 'unsigned int getClearStencil()')
cls.func(nil, 'cocos2d::ClearFlag getClearFlag()')
cls.func(nil, 'cocos2d::RenderTargetFlag getRenderTargetFlag()')
cls.func(nil, 'void setDepthTest(bool value)')
cls.func(nil, 'void setDepthWrite(bool value)')
cls.func(nil, 'void setDepthCompareFunction(cocos2d::backend::CompareFunction func)')
cls.func(nil, 'bool getDepthTest()')
cls.func(nil, 'bool getDepthWrite()')
cls.func(nil, 'cocos2d::backend::CompareFunction getDepthCompareFunction()')
cls.func(nil, 'void setStencilTest(bool value)')
cls.func(nil, 'void setStencilCompareFunction(cocos2d::backend::CompareFunction func, unsigned int ref, unsigned int readMask)')
cls.func(nil, 'void setStencilOperation(cocos2d::backend::StencilOperation stencilFailureOp, cocos2d::backend::StencilOperation depthFailureOp, cocos2d::backend::StencilOperation stencilDepthPassOp)')
cls.func(nil, 'void setStencilWriteMask(unsigned int mask)')
cls.func(nil, 'bool getStencilTest()')
cls.func(nil, 'cocos2d::backend::StencilOperation getStencilFailureOperation()')
cls.func(nil, 'cocos2d::backend::StencilOperation getStencilPassDepthFailureOperation()')
cls.func(nil, 'cocos2d::backend::StencilOperation getStencilDepthPassOperation()')
cls.func(nil, 'cocos2d::backend::CompareFunction getStencilCompareFunction()')
cls.func(nil, 'unsigned int getStencilReadMask()')
cls.func(nil, 'unsigned int getStencilWriteMask()')
cls.func(nil, 'unsigned int getStencilReferenceValue()')
cls.func(nil, 'void setCullMode(cocos2d::CullMode mode)')
cls.func(nil, 'cocos2d::CullMode getCullMode()')
cls.func(nil, 'void setWinding(cocos2d::Winding winding)')
cls.func(nil, 'cocos2d::Winding getWinding()')
cls.func(nil, 'void setViewPort(int x, int y, unsigned int w, unsigned int h)')
cls.func(nil, 'const cocos2d::Viewport &getViewport()')
cls.func(nil, 'void setScissorTest(bool enabled)')
cls.func(nil, 'void setScissorRect(float x, float y, float width, float height)')
cls.func(nil, 'bool getScissorTest()')
cls.func(nil, 'const cocos2d::ScissorRect &getScissorRect()')
cls.func(nil, 'bool checkVisibility(const cocos2d::Mat4 &transform, const cocos2d::Size &size)')
cls.prop('drawnBatches', nil, nil)
cls.prop('drawnVertices', nil, nil)
cls.prop('colorAttachment', nil, nil)
cls.prop('depthAttachment', nil, nil)
cls.prop('stencilAttachment', nil, nil)
cls.prop('clearColor', nil, nil)
cls.prop('clearDepth', nil, nil)
cls.prop('clearStencil', nil, nil)
cls.prop('clearFlag', nil, nil)
cls.prop('renderTargetFlag', nil, nil)
cls.prop('depthTest', nil, nil)
cls.prop('depthWrite', nil, nil)
cls.prop('depthCompareFunction', nil, nil)
cls.prop('stencilTest', nil, nil)
cls.prop('stencilFailureOperation', nil, nil)
cls.prop('stencilPassDepthFailureOperation', nil, nil)
cls.prop('stencilDepthPassOperation', nil, nil)
cls.prop('stencilCompareFunction', nil, nil)
cls.prop('stencilReadMask', nil, nil)
cls.prop('stencilWriteMask', nil, nil)
cls.prop('stencilReferenceValue', nil, nil)
cls.prop('cullMode', nil, nil)
cls.prop('winding', nil, nil)
cls.prop('viewport', nil, nil)
cls.prop('scissorTest', nil, nil)
cls.prop('scissorRect', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RenderCommand::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('UNKNOWN_COMMAND', 'cocos2d::RenderCommand::Type::UNKNOWN_COMMAND')
cls.enum('QUAD_COMMAND', 'cocos2d::RenderCommand::Type::QUAD_COMMAND')
cls.enum('CUSTOM_COMMAND', 'cocos2d::RenderCommand::Type::CUSTOM_COMMAND')
cls.enum('GROUP_COMMAND', 'cocos2d::RenderCommand::Type::GROUP_COMMAND')
cls.enum('MESH_COMMAND', 'cocos2d::RenderCommand::Type::MESH_COMMAND')
cls.enum('TRIANGLES_COMMAND', 'cocos2d::RenderCommand::Type::TRIANGLES_COMMAND')
cls.enum('CALLBACK_COMMAND', 'cocos2d::RenderCommand::Type::CALLBACK_COMMAND')
cls.enum('CAPTURE_SCREEN_COMMAND', 'cocos2d::RenderCommand::Type::CAPTURE_SCREEN_COMMAND')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CustomCommand::DrawType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('ARRAY', 'cocos2d::CustomCommand::DrawType::ARRAY')
cls.enum('ELEMENT', 'cocos2d::CustomCommand::DrawType::ELEMENT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PipelineDescriptor'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.var('programState', '@optional cocos2d::backend::ProgramState *programState')
cls.var('blendDescriptor', 'cocos2d::backend::BlendDescriptor blendDescriptor')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Technique'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Pass'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RenderState'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RenderCommand'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void init(float globalZOrder, const cocos2d::Mat4 &modelViewTransform, unsigned int flags)')
cls.func(nil, 'float getGlobalOrder()')
cls.func(nil, 'cocos2d::RenderCommand::Type getType()')
cls.func(nil, 'bool isTransparent()')
cls.func(nil, 'void setTransparent(bool isTransparent)')
cls.func(nil, 'bool isSkipBatching()')
cls.func(nil, 'void setSkipBatching(bool value)')
cls.func(nil, 'bool is3D()')
cls.func(nil, 'void set3D(bool value)')
cls.func(nil, 'float getDepth()')
cls.func(nil, 'cocos2d::PipelineDescriptor &getPipelineDescriptor()')
cls.func(nil, 'const cocos2d::Mat4 &getMV()')
cls.prop('globalOrder', nil, nil)
cls.prop('type', nil, nil)
cls.prop('transparent', nil, nil)
cls.prop('skipBatching', nil, nil)
cls.prop('3D', nil, nil)
cls.prop('depth', nil, nil)
cls.prop('pipelineDescriptor', nil, nil)
cls.prop('mv', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CustomCommand'
cls.SUPERCLS = 'cocos2d::RenderCommand'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'CustomCommand()')
cls.func(nil, 'void init(float globalZOrder)', 'void init(float globalZOrder, const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'void createVertexBuffer(std::size_t vertexSize, std::size_t capacity, cocos2d::CustomCommand::BufferUsage usage)')
cls.func(nil, 'void createIndexBuffer(cocos2d::CustomCommand::IndexFormat format, std::size_t capacity, cocos2d::CustomCommand::BufferUsage usage)')
cls.func(nil, 'void updateVertexBuffer(void *data, std::size_t length)', 'void updateVertexBuffer(void *data, std::size_t offset, std::size_t length)')
cls.func(nil, 'void updateIndexBuffer(void *data, std::size_t length)', 'void updateIndexBuffer(void *data, std::size_t offset, std::size_t length)')
cls.func(nil, 'std::size_t getVertexCapacity()')
cls.func(nil, 'std::size_t getIndexCapacity()')
cls.func(nil, 'void setDrawType(cocos2d::CustomCommand::DrawType drawType)')
cls.func(nil, 'cocos2d::CustomCommand::DrawType getDrawType()')
cls.func(nil, 'void setPrimitiveType(cocos2d::CustomCommand::PrimitiveType primitiveType)')
cls.func(nil, 'cocos2d::CustomCommand::PrimitiveType getPrimitiveType()')
cls.func(nil, 'void setVertexBuffer(cocos2d::backend::Buffer *vertexBuffer)')
cls.func(nil, 'cocos2d::backend::Buffer *getVertexBuffer()')
cls.func(nil, 'void setIndexBuffer(cocos2d::backend::Buffer *indexBuffer, cocos2d::CustomCommand::IndexFormat indexFormat)')
cls.func(nil, 'cocos2d::backend::Buffer *getIndexBuffer()')
cls.func(nil, 'void setVertexDrawInfo(std::size_t start, std::size_t count)')
cls.func(nil, 'std::size_t getVertexDrawStart()')
cls.func(nil, 'std::size_t getVertexDrawCount()')
cls.func(nil, 'void setIndexDrawInfo(std::size_t start, std::size_t count)')
cls.func(nil, 'std::size_t getIndexDrawOffset()')
cls.func(nil, 'std::size_t getIndexDrawCount()')
cls.func(nil, 'void setLineWidth(float lineWidth)')
cls.func(nil, 'float getLineWidth()')
cls.func(nil, 'cocos2d::CustomCommand::IndexFormat getIndexFormat()')
cls.var('func', '@nullable @local std::function<void ()> func')
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
cls.prop('vertexCapacity', nil, nil)
cls.prop('indexCapacity', nil, nil)
cls.prop('drawType', nil, nil)
cls.prop('primitiveType', nil, nil)
cls.prop('vertexBuffer', nil, nil)
cls.prop('indexBuffer', nil, nil)
cls.prop('vertexDrawStart', nil, nil)
cls.prop('vertexDrawCount', nil, nil)
cls.prop('indexDrawOffset', nil, nil)
cls.prop('indexDrawCount', nil, nil)
cls.prop('lineWidth', nil, nil)
cls.prop('indexFormat', nil, nil)
cls.prop('beforeCallback', nil, nil)
cls.prop('afterCallback', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MeshCommand'
cls.SUPERCLS = 'cocos2d::CustomCommand'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'MeshCommand()')
cls.func(nil, 'void init(float globalZOrder, const cocos2d::Mat4 &transform)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextureCache'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = [[
    static const std::string makeTextureCacheCallbackTag(const std::string &key)
    {
        return "addImageAsync." + key;
    }
]]
cls.func(nil, 'static void setETC1AlphaFileSuffix(const std::string &suffix)')
cls.func(nil, 'static std::string getETC1AlphaFileSuffix()')
cls.func(nil, 'TextureCache()')
cls.func(nil, 'std::string getDescription()')
cls.func(nil, 'cocos2d::Texture2D *addImage(const std::string &filepath)', 'cocos2d::Texture2D *addImage(cocos2d::Image *image, const std::string &key)')
cls.func(nil, 'cocos2d::Texture2D *getTextureForKey(const std::string &key)')
cls.func(nil, 'bool reloadTexture(const std::string &fileName)')
cls.func(nil, 'void removeAllTextures()')
cls.func(nil, 'void removeUnusedTextures()')
cls.func(nil, 'void removeTexture(cocos2d::Texture2D *texture)')
cls.func(nil, 'void removeTextureForKey(const std::string &key)')
cls.func(nil, 'std::string getCachedTextureInfo()')
cls.func(nil, 'void waitForQuit()')
cls.func(nil, 'std::string getTextureFilePath(cocos2d::Texture2D *texture)')
cls.func(nil, 'void renameTextureWithKey(const std::string &srcName, const std::string &dstName)')
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
cls.prop('etC1AlphaFileSuffix', nil, nil)
cls.prop('description', nil, nil)
cls.prop('cachedTextureInfo', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Texture2D'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static void setDefaultAlphaPixelFormat(cocos2d::backend::PixelFormat format)')
cls.func(nil, 'static cocos2d::backend::PixelFormat getDefaultAlphaPixelFormat()')
cls.func(nil, 'Texture2D()')
cls.func(nil, 'bool initWithData(const void *data, ssize_t dataLen, cocos2d::backend::PixelFormat pixelFormat, int pixelsWide, int pixelsHigh, const cocos2d::Size &contentSize, @optional bool preMultipliedAlpha)', 'bool initWithData(const void *data, ssize_t dataLen, cocos2d::backend::PixelFormat pixelFormat, cocos2d::backend::PixelFormat renderFormat, int pixelsWide, int pixelsHigh, const cocos2d::Size &contentSize, @optional bool preMultipliedAlpha)')
cls.func(nil, 'bool updateWithData(void *data, int offsetX, int offsetY, int width, int height)')
cls.func(nil, 'void drawAtPoint(const cocos2d::Vec2 &point, float globalZOrder)')
cls.func(nil, 'void drawInRect(const cocos2d::Rect &rect, float globalZOrder)')
cls.func(nil, 'bool initWithImage(cocos2d::Image *image)', 'bool initWithImage(cocos2d::Image *image, cocos2d::backend::PixelFormat format)')
cls.func(nil, 'bool initWithString(const char *text, const std::string &fontName, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment, @optional bool enableWrap, @optional int overflow)')
cls.func(nil, 'bool initWithBackendTexture(cocos2d::backend::TextureBackend *texture, @optional bool preMultipliedAlpha)')
cls.func(nil, 'void setRenderTarget(bool renderTarget)')
cls.func(nil, 'bool isRenderTarget()')
cls.func(nil, 'void setTexParameters(const cocos2d::Texture2D::TexParams &params)')
cls.func(nil, 'void generateMipmap()')
cls.func(nil, 'void setAntiAliasTexParameters()')
cls.func(nil, 'void setAliasTexParameters()')
cls.func(nil, 'const char *getStringForFormat()')
cls.func(nil, 'unsigned int getBitsPerPixelForFormat()', 'unsigned int getBitsPerPixelForFormat(cocos2d::backend::PixelFormat format)')
cls.func(nil, 'const cocos2d::Size &getContentSizeInPixels()')
cls.func(nil, 'bool hasPremultipliedAlpha()')
cls.func(nil, 'bool hasMipmaps()')
cls.func(nil, 'cocos2d::backend::PixelFormat getPixelFormat()')
cls.func(nil, 'int getPixelsWide()')
cls.func(nil, 'int getPixelsHigh()')
cls.func(nil, 'cocos2d::backend::TextureBackend *getBackendTexture()')
cls.func(nil, 'float getMaxS()')
cls.func(nil, 'void setMaxS(float maxS)')
cls.func(nil, 'float getMaxT()')
cls.func(nil, 'void setMaxT(float maxT)')
cls.func(nil, 'cocos2d::Size getContentSize()')
cls.func(nil, 'std::string getPath()')
cls.func(nil, 'void setAlphaTexture(cocos2d::Texture2D *alphaTexture)')
cls.func(nil, 'cocos2d::Texture2D *getAlphaTexture()')
cls.func(nil, 'bool getAlphaTextureName()')
cls.func(nil, 'static const std::map<backend::PixelFormat, const PixelFormatInfo> &getPixelFormatInfoMap()')
cls.prop('defaultAlphaPixelFormat', nil, nil)
cls.prop('renderTarget', nil, nil)
cls.prop('stringForFormat', nil, nil)
cls.prop('contentSizeInPixels', nil, nil)
cls.prop('pixelFormat', nil, nil)
cls.prop('pixelsWide', nil, nil)
cls.prop('pixelsHigh', nil, nil)
cls.prop('backendTexture', nil, nil)
cls.prop('maxS', nil, nil)
cls.prop('maxT', nil, nil)
cls.prop('contentSize', nil, nil)
cls.prop('path', nil, nil)
cls.prop('alphaTexture', nil, nil)
cls.prop('alphaTextureName', nil, nil)
cls.prop('pixelFormatInfoMap', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextureCube'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TextureCube *create(const std::string &positive_x, const std::string &negative_x, const std::string &positive_y, const std::string &negative_y, const std::string &positive_z, const std::string &negative_z)')
cls.func(nil, 'void setTexParameters(const cocos2d::Texture2D::TexParams &)')
cls.func(nil, 'cocos2d::backend::TextureBackend *getBackendTexture()')
cls.func(nil, 'bool reloadTexture()')
cls.func(nil, 'TextureCube()')
cls.prop('backendTexture', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextureAtlas'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TextureAtlas *create(const std::string &file, ssize_t capacity)')
cls.func(nil, 'static cocos2d::TextureAtlas *createWithTexture(cocos2d::Texture2D *texture, ssize_t capacity)')
cls.func(nil, 'TextureAtlas()')
cls.func(nil, 'bool initWithFile(const std::string &file, ssize_t capacity)')
cls.func(nil, 'bool initWithTexture(cocos2d::Texture2D *texture, ssize_t capacity)')
cls.func(nil, 'void insertQuadFromIndex(ssize_t fromIndex, ssize_t newIndex)')
cls.func(nil, 'void removeQuadAtIndex(ssize_t index)')
cls.func(nil, 'void removeQuadsAtIndex(ssize_t index, ssize_t amount)')
cls.func(nil, 'void removeAllQuads()')
cls.func(nil, 'bool resizeCapacity(ssize_t capacity)')
cls.func(nil, 'void increaseTotalQuadsWith(ssize_t amount)')
cls.func(nil, 'void moveQuadsFromIndex(ssize_t oldIndex, ssize_t amount, ssize_t newIndex)', 'void moveQuadsFromIndex(ssize_t index, ssize_t newIndex)')
cls.func(nil, 'void fillWithEmptyQuadsFromIndex(ssize_t index, ssize_t amount)')
cls.func(nil, 'bool isDirty()')
cls.func(nil, 'void setDirty(bool bDirty)')
cls.func(nil, 'std::string getDescription()')
cls.func(nil, 'size_t getTotalQuads()')
cls.func(nil, 'size_t getCapacity()')
cls.func(nil, 'cocos2d::Texture2D *getTexture()')
cls.func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
cls.prop('dirty', nil, nil)
cls.prop('description', nil, nil)
cls.prop('totalQuads', nil, nil)
cls.prop('capacity', nil, nil)
cls.prop('texture', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::network::WebSocket::ErrorCode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('TIME_OUT', 'cocos2d::network::WebSocket::ErrorCode::TIME_OUT')
cls.enum('CONNECTION_FAILURE', 'cocos2d::network::WebSocket::ErrorCode::CONNECTION_FAILURE')
cls.enum('UNKNOWN', 'cocos2d::network::WebSocket::ErrorCode::UNKNOWN')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::network::WebSocket::State'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('CONNECTING', 'cocos2d::network::WebSocket::State::CONNECTING')
cls.enum('OPEN', 'cocos2d::network::WebSocket::State::OPEN')
cls.enum('CLOSING', 'cocos2d::network::WebSocket::State::CLOSING')
cls.enum('CLOSED', 'cocos2d::network::WebSocket::State::CLOSED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::network::WebSocket::Delegate'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void onOpen(cocos2d::network::WebSocket *ws)')
cls.func(nil, 'void onMessage(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::Data &data)')
cls.func(nil, 'void onClose(cocos2d::network::WebSocket *ws)')
cls.func(nil, 'void onError(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::ErrorCode &error)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::network::WebSocket'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func('init', [[
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
        olua_addref(L, 1, "delegate", 2, OLUA_MODE_SINGLE);

        return 0;
    }
]])
cls.func(nil, 'static void closeAllConnections()')
cls.func(nil, 'WebSocket()')
cls.func(nil, 'void send(const std::string &message)', 'void send(const unsigned char *binaryMsg, unsigned int len)')
cls.func(nil, 'void close()')
cls.func(nil, 'void closeAsync()')
cls.func(nil, 'cocos2d::network::WebSocket::State getReadyState()')
cls.func(nil, 'const std::string &getUrl()')
cls.func(nil, 'const std::string &getProtocol()')
cls.prop('readyState', nil, nil)
cls.prop('url', nil, nil)
cls.prop('protocol', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LuaWebSocketDelegate'
cls.SUPERCLS = 'cocos2d::network::WebSocket::Delegate'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'LuaWebSocketDelegate()')
cls.var('onOpen', '@nullable @local std::function<void (network::WebSocket *)> onOpenCallback')
cls.var('onMessage', '@nullable @local std::function<void (network::WebSocket *, const network::WebSocket::Data &)> onMessageCallback')
cls.var('onClose', '@nullable @local std::function<void (network::WebSocket *)> onCloseCallback')
cls.var('onError', '@nullable @local std::function<void (network::WebSocket *, const network::WebSocket::ErrorCode &)> onErrorCallback')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionManager'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'ActionManager()')
cls.func(nil, 'void addAction(cocos2d::Action *action, cocos2d::Node *target, bool paused)')
cls.func(nil, 'void removeAllActions()')
cls.func(nil, 'void removeAllActionsFromTarget(cocos2d::Node *target)')
cls.func(nil, 'void removeAction(cocos2d::Action *action)')
cls.func(nil, 'void removeActionByTag(int tag, cocos2d::Node *target)')
cls.func(nil, 'void removeAllActionsByTag(int tag, cocos2d::Node *target)')
cls.func(nil, 'void removeActionsByFlags(unsigned int flags, cocos2d::Node *target)')
cls.func(nil, 'cocos2d::Action *getActionByTag(int tag, const cocos2d::Node *target)')
cls.func(nil, 'ssize_t getNumberOfRunningActionsInTarget(const cocos2d::Node *target)')
cls.func(nil, 'ssize_t getNumberOfRunningActions()')
cls.func(nil, 'size_t getNumberOfRunningActionsInTargetByTag(const cocos2d::Node *target, int tag)')
cls.func(nil, 'void pauseTarget(cocos2d::Node *target)')
cls.func(nil, 'void resumeTarget(cocos2d::Node *target)')
cls.func(nil, 'Vector<cocos2d::Node *> pauseAllRunningActions()')
cls.func(nil, 'void resumeTargets(const Vector<cocos2d::Node *> &targetsToResume)')
cls.func(nil, 'void update(float dt)')
cls.prop('numberOfRunningActions', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Component'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Component *create()')
cls.func(nil, 'bool init()')
cls.func(nil, 'bool isEnabled()')
cls.func(nil, 'void setEnabled(bool enabled)')
cls.func(nil, 'const std::string &getName()')
cls.func(nil, 'void setName(const std::string &name)')
cls.func(nil, 'cocos2d::Node *getOwner()')
cls.func(nil, 'void setOwner(cocos2d::Node *owner)')
cls.func(nil, 'void update(float delta)')
cls.func(nil, 'bool serialize(void *r)')
cls.func(nil, 'void onEnter()')
cls.func(nil, 'void onExit()')
cls.func(nil, 'void onAdd()')
cls.func(nil, 'void onRemove()')
cls.func(nil, 'Component()')
cls.prop('enabled', nil, nil)
cls.prop('name', nil, nil)
cls.prop('owner', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LuaComponent'
cls.SUPERCLS = 'cocos2d::Component'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::LuaComponent *create()')
cls.func(nil, 'LuaComponent()')
cls.var('onUpdate', '@nullable @local std::function<void (float)> onUpdateCallback')
cls.var('onEnter', '@nullable @local std::function<void ()> onEnterCallback')
cls.var('onExit', '@nullable @local std::function<void ()> onExitCallback')
cls.var('onAdd', '@nullable @local std::function<void ()> onAddCallback')
cls.var('onRemove', '@nullable @local std::function<void ()> onRemoveCallback')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Node'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
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
cls.func('getBounds', [[
    {
        auto self = olua_checkobj<cocos2d::Node>(L, 1);
        auto target = olua_checkobj<cocos2d::Node>(L, 2);

        float left = (float)luaL_checknumber(L, 3);
        float right = (float)luaL_checknumber(L, 4);
        float top = (float)luaL_checknumber(L, 5);
        float bottom = (float)luaL_checknumber(L, 6);

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
cls.func(nil, 'static cocos2d::Node *create()')
cls.func(nil, 'static int getAttachedNodeCount()')
cls.func(nil, 'std::string getDescription()')
cls.func(nil, 'void setLocalZOrder(std::int32_t localZOrder)')
cls.func(nil, 'void updateOrderOfArrival()')
cls.func(nil, 'std::int32_t getLocalZOrder()')
cls.func(nil, 'void setGlobalZOrder(float globalZOrder)')
cls.func(nil, 'float getGlobalZOrder()')
cls.func(nil, 'void setScaleX(float scaleX)')
cls.func(nil, 'float getScaleX()')
cls.func(nil, 'void setScaleY(float scaleY)')
cls.func(nil, 'float getScaleY()')
cls.func(nil, 'void setScaleZ(float scaleZ)')
cls.func(nil, 'float getScaleZ()')
cls.func(nil, 'void setScale(float scale)', 'void setScale(float scaleX, float scaleY)')
cls.func(nil, 'float getScale()')
cls.func(nil, 'void setPosition(const cocos2d::Vec2 &position)', 'void setPosition(float x, float y)')
cls.func(nil, 'void setPositionNormalized(const cocos2d::Vec2 &position)')
cls.func(nil, 'void setNormalizedPosition(const cocos2d::Vec2 &position)')
cls.func(nil, 'const cocos2d::Vec2 &getPosition()')
cls.func(nil, 'const cocos2d::Vec2 &getPositionNormalized()')
cls.func(nil, 'const cocos2d::Vec2 &getNormalizedPosition()')
cls.func(nil, 'void setPositionX(float x)')
cls.func(nil, 'float getPositionX()')
cls.func(nil, 'void setPositionY(float y)')
cls.func(nil, 'float getPositionY()')
cls.func(nil, 'void setPosition3D(const cocos2d::Vec3 &position)')
cls.func(nil, 'cocos2d::Vec3 getPosition3D()')
cls.func(nil, 'void setPositionZ(float positionZ)')
cls.func(nil, 'float getPositionZ()')
cls.func(nil, 'void setSkewX(float skewX)')
cls.func(nil, 'float getSkewX()')
cls.func(nil, 'void setSkewY(float skewY)')
cls.func(nil, 'float getSkewY()')
cls.func(nil, 'void setAnchorPoint(const cocos2d::Vec2 &anchorPoint)')
cls.func(nil, 'const cocos2d::Vec2 &getAnchorPoint()')
cls.func(nil, 'const cocos2d::Vec2 &getAnchorPointInPoints()')
cls.func(nil, 'void setContentSize(const cocos2d::Size &contentSize)')
cls.func(nil, 'const cocos2d::Size &getContentSize()')
cls.func(nil, 'void setVisible(bool visible)')
cls.func(nil, 'bool isVisible()')
cls.func(nil, 'void setRotation(float rotation)')
cls.func(nil, 'float getRotation()')
cls.func(nil, 'void setRotation3D(const cocos2d::Vec3 &rotation)')
cls.func(nil, 'cocos2d::Vec3 getRotation3D()')
cls.func(nil, 'void setRotationQuat(const cocos2d::Quaternion &quat)')
cls.func(nil, 'cocos2d::Quaternion getRotationQuat()')
cls.func(nil, 'void setRotationSkewX(float rotationX)')
cls.func(nil, 'float getRotationSkewX()')
cls.func(nil, 'void setRotationSkewY(float rotationY)')
cls.func(nil, 'float getRotationSkewY()')
cls.func(nil, 'void setIgnoreAnchorPointForPosition(bool ignore)')
cls.func(nil, 'bool isIgnoreAnchorPointForPosition()')
cls.func(nil, 'void addChild(@addref(children |) cocos2d::Node *child)', 'void addChild(@addref(children |) cocos2d::Node *child, int localZOrder)', 'void addChild(@addref(children |) cocos2d::Node *child, int localZOrder, int tag)', 'void addChild(@addref(children |) cocos2d::Node *child, int localZOrder, const std::string &name)')
cls.func(nil, '@addref(children |) cocos2d::Node *getChildByTag(int tag)')
cls.func(nil, '@addref(children |) cocos2d::Node *getChildByName(const std::string &name)')
cls.func(nil, '@addref(children |) Vector<cocos2d::Node *> &getChildren()')
cls.func(nil, 'ssize_t getChildrenCount()')
cls.func(nil, 'void setParent(cocos2d::Node *parent)')
cls.func(nil, 'cocos2d::Node *getParent()')
cls.func(nil, '@delref(children | parent) void removeFromParent()')
cls.func(nil, '@delref(children | parent) void removeFromParentAndCleanup(bool cleanup)')
cls.func(nil, 'void removeChild(@delref(children |) cocos2d::Node *child, @optional bool cleanup)')
cls.func(nil, '@delref(children ~) void removeChildByTag(int tag, @optional bool cleanup)')
cls.func(nil, '@delref(children ~) void removeChildByName(const std::string &name, @optional bool cleanup)')
cls.func(nil, '@delref(children *) void removeAllChildren()')
cls.func(nil, '@delref(children *) void removeAllChildrenWithCleanup(bool cleanup)')
cls.func(nil, 'void reorderChild(cocos2d::Node *child, int localZOrder)')
cls.func(nil, 'void sortAllChildren()')
cls.func(nil, 'int getTag()')
cls.func(nil, 'void setTag(int tag)')
cls.func(nil, 'const std::string &getName()')
cls.func(nil, 'void setName(const std::string &name)')
cls.func(nil, 'void *getUserData()')
cls.func(nil, 'void setUserData(void *userData)')
cls.func(nil, 'cocos2d::Ref *getUserObject()')
cls.func(nil, 'void setUserObject(cocos2d::Ref *userObject)')
cls.func(nil, 'bool isRunning()')
cls.func(nil, 'void onEnter()')
cls.func(nil, 'void onEnterTransitionDidFinish()')
cls.func(nil, 'void onExit()')
cls.func(nil, 'void onExitTransitionDidStart()')
cls.func(nil, 'void cleanup()')
cls.func(nil, 'void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)', 'void draw()')
cls.func(nil, 'void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags)', 'void visit()')
cls.func(nil, 'cocos2d::Scene *getScene()')
cls.func(nil, 'cocos2d::Rect getBoundingBox()')
cls.func(nil, 'void setEventDispatcher(@addref(eventDispatcher ^) cocos2d::EventDispatcher *dispatcher)')
cls.func(nil, '@addref(eventDispatcher ^) cocos2d::EventDispatcher *getEventDispatcher()')
cls.func(nil, 'void setActionManager(@addref(actionManager ^) cocos2d::ActionManager *actionManager)')
cls.func(nil, '@addref(actionManager ^) cocos2d::ActionManager *getActionManager()')
cls.func(nil, '@delref(actions ~) cocos2d::Action *runAction(@addref(actions |) cocos2d::Action *action)')
cls.func(nil, '@delref(actions ~) void stopAllActions()')
cls.func(nil, '@delref(actions ~) void stopAction(cocos2d::Action *action)')
cls.func(nil, '@delref(actions ~) void stopActionByTag(int tag)')
cls.func(nil, '@delref(actions ~) void stopAllActionsByTag(int tag)')
cls.func(nil, '@delref(actions ~) void stopActionsByFlags(unsigned int flags)')
cls.func(nil, '@addref(actions |) cocos2d::Action *getActionByTag(int tag)')
cls.func(nil, 'ssize_t getNumberOfRunningActions()')
cls.func(nil, 'ssize_t getNumberOfRunningActionsByTag(int tag)')
cls.func(nil, 'void setScheduler(@addref(scheduler ^) cocos2d::Scheduler *scheduler)')
cls.func(nil, '@addref(scheduler ^) cocos2d::Scheduler *getScheduler()')
cls.func(nil, 'bool isScheduled(const std::string &key)')
cls.func(nil, 'void scheduleUpdate()')
cls.func(nil, 'void scheduleUpdateWithPriority(int priority)')
cls.func(nil, 'void unscheduleUpdate()')
cls.func(nil, 'void resume()')
cls.func(nil, 'void pause()')
cls.func(nil, 'void update(float delta)')
cls.func(nil, 'void updateTransform()')
cls.func(nil, 'const cocos2d::Mat4 &getNodeToParentTransform()', 'cocos2d::Mat4 getNodeToParentTransform(cocos2d::Node *ancestor)')
cls.func(nil, 'cocos2d::AffineTransform getNodeToParentAffineTransform()', 'cocos2d::AffineTransform getNodeToParentAffineTransform(cocos2d::Node *ancestor)')
cls.func(nil, 'void setNodeToParentTransform(const cocos2d::Mat4 &transform)')
cls.func(nil, 'const cocos2d::Mat4 &getParentToNodeTransform()')
cls.func(nil, 'cocos2d::AffineTransform getParentToNodeAffineTransform()')
cls.func(nil, 'cocos2d::Mat4 getNodeToWorldTransform()')
cls.func(nil, 'cocos2d::AffineTransform getNodeToWorldAffineTransform()')
cls.func(nil, 'cocos2d::Mat4 getWorldToNodeTransform()')
cls.func(nil, 'cocos2d::AffineTransform getWorldToNodeAffineTransform()')
cls.func(nil, 'cocos2d::Vec2 convertToNodeSpace(@pack const cocos2d::Vec2 &worldPoint)')
cls.func(nil, 'cocos2d::Vec2 convertToWorldSpace(@pack const cocos2d::Vec2 &nodePoint)')
cls.func(nil, 'cocos2d::Vec2 convertToNodeSpaceAR(@pack const cocos2d::Vec2 &worldPoint)')
cls.func(nil, 'cocos2d::Vec2 convertToWorldSpaceAR(@pack const cocos2d::Vec2 &nodePoint)')
cls.func(nil, 'cocos2d::Vec2 convertTouchToNodeSpace(cocos2d::Touch *touch)')
cls.func(nil, 'cocos2d::Vec2 convertTouchToNodeSpaceAR(cocos2d::Touch *touch)')
cls.func(nil, 'void setAdditionalTransform(const cocos2d::Mat4 &additionalTransform)', 'void setAdditionalTransform(const cocos2d::AffineTransform &additionalTransform)')
cls.func(nil, '@addref(components |) cocos2d::Component *getComponent(const std::string &name)')
cls.func(nil, 'bool addComponent(@addref(components |) cocos2d::Component *component)')
cls.func(nil, '@delref(components ~) bool removeComponent(const std::string &name)', '@delref(components ~) bool removeComponent(cocos2d::Component *component)')
cls.func(nil, '@delref(components *) void removeAllComponents()')
cls.func(nil, 'uint8_t getOpacity()')
cls.func(nil, 'uint8_t getDisplayedOpacity()')
cls.func(nil, 'void setOpacity(uint8_t opacity)')
cls.func(nil, 'void updateDisplayedOpacity(uint8_t parentOpacity)')
cls.func(nil, 'bool isCascadeOpacityEnabled()')
cls.func(nil, 'void setCascadeOpacityEnabled(bool cascadeOpacityEnabled)')
cls.func(nil, 'const cocos2d::Color3B &getColor()')
cls.func(nil, 'const cocos2d::Color3B &getDisplayedColor()')
cls.func(nil, 'void setColor(const cocos2d::Color3B &color)')
cls.func(nil, 'void updateDisplayedColor(const cocos2d::Color3B &parentColor)')
cls.func(nil, 'bool isCascadeColorEnabled()')
cls.func(nil, 'void setCascadeColorEnabled(bool cascadeColorEnabled)')
cls.func(nil, 'void setOpacityModifyRGB(bool value)')
cls.func(nil, 'bool isOpacityModifyRGB()')
cls.func(nil, 'unsigned short getCameraMask()')
cls.func(nil, 'void setCameraMask(unsigned short mask, @optional bool applyChildren)')
cls.func(nil, 'void setProgramState(@addref(programState ^) cocos2d::backend::ProgramState *programState)')
cls.func(nil, '@addref(programState ^) cocos2d::backend::ProgramState *getProgramState()')
cls.func(nil, 'Node()')
cls.func(nil, 'bool init()')
cls.func(nil, 'void setPhysicsBody(@addref(physicsBody ^) cocos2d::PhysicsBody *physicsBody)')
cls.func(nil, '@addref(physicsBody ^) cocos2d::PhysicsBody *getPhysicsBody()')
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
cls.callback {
    FUNCS =  {
        'void enumerateChildren(const std::string &name, @local std::function<bool (Node *)> callback)'
    },
    TAG_MAKER = 'enumerateChildren',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'function',
}
cls.prop('x', 'float getPositionX()', 'void setPositionX(float x)')
cls.prop('y', 'float getPositionY()', 'void setPositionY(float y)')
cls.prop('z', 'float getPositionZ()', 'void setPositionZ(float z)')
cls.prop('anchorX', [[
    {
        auto self = olua_toobj<cocos2d::Node>(L, 1);
        lua_pushnumber(L, self->getAnchorPoint().x);
        return 1;
    }
]], [[
    {
        auto self = olua_toobj<cocos2d::Node>(L, 1);
        cocos2d::Vec2 anchor = self->getAnchorPoint();
        anchor.x = (float)olua_checknumber(L, 2);
        self->setAnchorPoint(anchor);
        return 0;
    }
]])
cls.prop('anchorY', [[
    {
        auto self = olua_toobj<cocos2d::Node>(L, 1);
        lua_pushnumber(L, self->getAnchorPoint().y);
        return 1;
    }
]], [[
    {
        auto self = olua_toobj<cocos2d::Node>(L, 1);
        cocos2d::Vec2 anchor = self->getAnchorPoint();
        anchor.y = (float)olua_checknumber(L, 2);
        self->setAnchorPoint(anchor);
        return 0;
    }
]])
cls.prop('width', [[
    {
        auto self = olua_toobj<cocos2d::Node>(L, 1);
        lua_pushnumber(L, self->getContentSize().width);
        return 1;
    }
]], [[
    {
        auto self = olua_toobj<cocos2d::Node>(L, 1);
        cocos2d::Size size = self->getContentSize();
        size.width = (float)olua_checknumber(L, 2);
        self->setContentSize(size);
        return 0;
    }
]])
cls.prop('height', [[
    {
        auto self = olua_toobj<cocos2d::Node>(L, 1);
        lua_pushnumber(L, self->getContentSize().height);
        return 1;
    }
]], [[
    {
        auto self = olua_toobj<cocos2d::Node>(L, 1);
        cocos2d::Size size = self->getContentSize();
        size.height = (float)olua_checknumber(L, 2);
        self->setContentSize(size);
        return 0;
    }
]])
cls.prop('alpha', [[
    {
        auto self = olua_toobj<cocos2d::Node>(L, 1);
        lua_pushnumber(L, self->getOpacity() / 255.0f);
        return 1;
    }
]], [[
    {
        auto self = olua_toobj<cocos2d::Node>(L, 1);
        self->setOpacity((uint8_t)(olua_checknumber(L, 2) * 255.0f));
        return 0;
    }
]])
cls.prop('attachedNodeCount', nil, nil)
cls.prop('description', nil, nil)
cls.prop('localZOrder', nil, nil)
cls.prop('globalZOrder', nil, nil)
cls.prop('scaleX', nil, nil)
cls.prop('scaleY', nil, nil)
cls.prop('scaleZ', nil, nil)
cls.prop('scale', nil, nil)
cls.prop('position', nil, nil)
cls.prop('positionNormalized', nil, nil)
cls.prop('normalizedPosition', nil, nil)
cls.prop('positionX', nil, nil)
cls.prop('positionY', nil, nil)
cls.prop('position3D', nil, nil)
cls.prop('positionZ', nil, nil)
cls.prop('skewX', nil, nil)
cls.prop('skewY', nil, nil)
cls.prop('anchorPoint', nil, nil)
cls.prop('anchorPointInPoints', nil, nil)
cls.prop('contentSize', nil, nil)
cls.prop('visible', nil, nil)
cls.prop('rotation', nil, nil)
cls.prop('rotation3D', nil, nil)
cls.prop('rotationQuat', nil, nil)
cls.prop('rotationSkewX', nil, nil)
cls.prop('rotationSkewY', nil, nil)
cls.prop('ignoreAnchorPointForPosition', nil, nil)
cls.prop('children', nil, nil)
cls.prop('childrenCount', nil, nil)
cls.prop('parent', nil, nil)
cls.prop('tag', nil, nil)
cls.prop('name', nil, nil)
cls.prop('userData', nil, nil)
cls.prop('userObject', nil, nil)
cls.prop('running', nil, nil)
cls.prop('scene', nil, nil)
cls.prop('boundingBox', nil, nil)
cls.prop('eventDispatcher', nil, nil)
cls.prop('actionManager', nil, nil)
cls.prop('numberOfRunningActions', nil, nil)
cls.prop('scheduler', nil, nil)
cls.prop('parentToNodeTransform', nil, nil)
cls.prop('parentToNodeAffineTransform', nil, nil)
cls.prop('nodeToWorldTransform', nil, nil)
cls.prop('nodeToWorldAffineTransform', nil, nil)
cls.prop('worldToNodeTransform', nil, nil)
cls.prop('worldToNodeAffineTransform', nil, nil)
cls.prop('opacity', nil, nil)
cls.prop('displayedOpacity', nil, nil)
cls.prop('cascadeOpacityEnabled', nil, nil)
cls.prop('color', nil, nil)
cls.prop('displayedColor', nil, nil)
cls.prop('cascadeColorEnabled', nil, nil)
cls.prop('opacityModifyRGB', nil, nil)
cls.prop('onEnterCallback', nil, nil)
cls.prop('onExitCallback', nil, nil)
cls.prop('onEnterTransitionDidFinishCallback', nil, nil)
cls.prop('onExitTransitionDidStartCallback', nil, nil)
cls.prop('cameraMask', nil, nil)
cls.prop('programState', nil, nil)
cls.prop('physicsBody', nil, nil)
cls.insert('removeFromParent', {
    BEFORE = [[
        if (!self->getParent()) {
            return 0;
        }
        olua_push_cppobj<cocos2d::Node>(L, self->getParent());
        int parent = lua_gettop(L);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
cls.insert('removeFromParentAndCleanup', {
    BEFORE = [[
        if (!self->getParent()) {
            return 0;
        }
        olua_push_cppobj<cocos2d::Node>(L, self->getParent());
        int parent = lua_gettop(L);
    ]],
    AFTER = nil,
    CALLBACK_BEFORE = nil,
    CALLBACK_AFTER = nil,
})
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LuaTweenNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void updateTweenAction(float value, const std::string &key)')
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
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::AtlasNode *create(const std::string &filename, int tileWidth, int tileHeight, int itemsToRender)')
cls.func(nil, 'void updateAtlasValues()')
cls.func(nil, 'cocos2d::Texture2D *getTexture()')
cls.func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'void setTextureAtlas(cocos2d::TextureAtlas *textureAtlas)')
cls.func(nil, 'cocos2d::TextureAtlas *getTextureAtlas()')
cls.func(nil, 'void setQuadsToDraw(ssize_t quadsToDraw)')
cls.func(nil, 'size_t getQuadsToDraw()')
cls.func(nil, 'AtlasNode()')
cls.func(nil, 'bool initWithTileFile(const std::string &tile, int tileWidth, int tileHeight, int itemsToRender)')
cls.func(nil, 'bool initWithTexture(cocos2d::Texture2D *texture, int tileWidth, int tileHeight, int itemsToRender)')
cls.prop('texture', nil, nil)
cls.prop('blendFunc', nil, nil)
cls.prop('textureAtlas', nil, nil)
cls.prop('quadsToDraw', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::sImageTGA'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.var('status', 'int status')
cls.var('type', 'unsigned char type')
cls.var('pixelDepth', 'unsigned char pixelDepth')
cls.var('width', 'short width')
cls.var('height', 'short height')
cls.var('imageData', 'unsigned char *imageData')
cls.var('flipped', 'int flipped')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TileMapAtlas'
cls.SUPERCLS = 'cocos2d::AtlasNode'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TileMapAtlas *create(const std::string &tile, const std::string &mapFile, int tileWidth, int tileHeight)')
cls.func(nil, 'TileMapAtlas()')
cls.func(nil, 'bool initWithTileFile(const std::string &tile, const std::string &mapFile, int tileWidth, int tileHeight)')
cls.func(nil, 'cocos2d::Color3B getTileAt(const cocos2d::Vec2 &position)')
cls.func(nil, 'void setTile(const cocos2d::Color3B &tile, const cocos2d::Vec2 &position)')
cls.func(nil, 'void releaseMap()')
cls.func(nil, 'struct cocos2d::sImageTGA *getTGAInfo()')
cls.func(nil, 'void setTGAInfo(struct cocos2d::sImageTGA *TGAInfo)')
cls.prop('tgaInfo', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ClippingNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ClippingNode *create()', 'static cocos2d::ClippingNode *create(cocos2d::Node *stencil)')
cls.func(nil, 'cocos2d::Node *getStencil()')
cls.func(nil, 'void setStencil(cocos2d::Node *stencil)')
cls.func(nil, 'bool hasContent()')
cls.func(nil, 'float getAlphaThreshold()')
cls.func(nil, 'void setAlphaThreshold(float alphaThreshold)')
cls.func(nil, 'bool isInverted()')
cls.func(nil, 'void setInverted(bool inverted)')
cls.func(nil, 'ClippingNode()')
cls.func(nil, 'bool init(cocos2d::Node *stencil)')
cls.prop('stencil', nil, nil)
cls.prop('alphaThreshold', nil, nil)
cls.prop('inverted', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MotionStreak'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::MotionStreak *create(float timeToFade, float minSeg, float strokeWidth, const cocos2d::Color3B &strokeColor, const std::string &imagePath)', 'static cocos2d::MotionStreak *create(float timeToFade, float minSeg, float strokeWidth, const cocos2d::Color3B &strokeColor, cocos2d::Texture2D *texture)')
cls.func(nil, 'cocos2d::Texture2D *getTexture()')
cls.func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'void tintWithColor(const cocos2d::Color3B &colors)')
cls.func(nil, 'void reset()')
cls.func(nil, 'bool isFastMode()')
cls.func(nil, 'void setFastMode(bool bFastMode)')
cls.func(nil, 'float getStroke()')
cls.func(nil, 'void setStroke(float stroke)')
cls.func(nil, 'bool isStartingPositionInitialized()')
cls.func(nil, 'void setStartingPositionInitialized(bool bStartingPositionInitialized)')
cls.func(nil, 'MotionStreak()')
cls.func(nil, 'bool initWithFade(float fade, float minSeg, float stroke, const cocos2d::Color3B &color, const std::string &path)', 'bool initWithFade(float fade, float minSeg, float stroke, const cocos2d::Color3B &color, cocos2d::Texture2D *texture)')
cls.prop('texture', nil, nil)
cls.prop('blendFunc', nil, nil)
cls.prop('fastMode', nil, nil)
cls.prop('stroke', nil, nil)
cls.prop('startingPositionInitialized', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProtectedNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ProtectedNode *create()')
cls.func(nil, 'void addProtectedChild(@addref(protectedChildren |) cocos2d::Node *child)', 'void addProtectedChild(@addref(protectedChildren |) cocos2d::Node *child, int localZOrder)', 'void addProtectedChild(@addref(protectedChildren |) cocos2d::Node *child, int localZOrder, int tag)')
cls.func(nil, '@addref(protectedChildren |) cocos2d::Node *getProtectedChildByTag(int tag)')
cls.func(nil, 'void removeProtectedChild(@delref(protectedChildren |) cocos2d::Node *child, @optional bool cleanup)')
cls.func(nil, '@delref(protectedChildren ~) void removeProtectedChildByTag(int tag, @optional bool cleanup)')
cls.func(nil, '@delref(protectedChildren *) void removeAllProtectedChildren()')
cls.func(nil, '@delref(protectedChildren *) void removeAllProtectedChildrenWithCleanup(bool cleanup)')
cls.func(nil, 'void reorderProtectedChild(cocos2d::Node *child, int localZOrder)')
cls.func(nil, 'void sortAllProtectedChildren()')
cls.func(nil, 'void disableCascadeColor()')
cls.func(nil, 'void disableCascadeOpacity()')
cls.func(nil, 'ProtectedNode()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::DrawNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::DrawNode *create(@optional float defaultLineWidth)')
cls.func(nil, 'void drawPoint(const cocos2d::Vec2 &point, const float pointSize, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawLine(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &destination, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawRect(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &destination, const cocos2d::Color4F &color)', 'void drawRect(const cocos2d::Vec2 &p1, const cocos2d::Vec2 &p2, const cocos2d::Vec2 &p3, const cocos2d::Vec2 &p4, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, bool drawLineToCenter, float scaleX, float scaleY, const cocos2d::Color4F &color)', 'void drawCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, bool drawLineToCenter, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawQuadBezier(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &control, const cocos2d::Vec2 &destination, unsigned int segments, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawCubicBezier(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &control1, const cocos2d::Vec2 &control2, const cocos2d::Vec2 &destination, unsigned int segments, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawCardinalSpline(cocos2d::PointArray *config, float tension, unsigned int segments, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawCatmullRom(cocos2d::PointArray *points, unsigned int segments, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawDot(const cocos2d::Vec2 &pos, float radius, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawSolidRect(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &destination, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawSolidCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, float scaleX, float scaleY, const cocos2d::Color4F &color)', 'void drawSolidCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawSegment(const cocos2d::Vec2 &from, const cocos2d::Vec2 &to, float radius, const cocos2d::Color4F &color)')
cls.func(nil, 'void drawTriangle(const cocos2d::Vec2 &p1, const cocos2d::Vec2 &p2, const cocos2d::Vec2 &p3, const cocos2d::Color4F &color)')
cls.func(nil, 'void clear()')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'void setLineWidth(float lineWidth)')
cls.func(nil, 'float getLineWidth()')
cls.func(nil, 'void setIsolated(bool isolated)')
cls.func(nil, 'bool isIsolated()')
cls.func(nil, 'DrawNode(@optional float lineWidth)')
cls.prop('blendFunc', nil, nil)
cls.prop('lineWidth', nil, nil)
cls.prop('isolated', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParallaxNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParallaxNode *create()')
cls.func(nil, 'void addChild(cocos2d::Node *child, int z, const cocos2d::Vec2 &parallaxRatio, const cocos2d::Vec2 &positionOffset)')
cls.func(nil, 'ParallaxNode()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextHAlignment'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('LEFT', 'cocos2d::TextHAlignment::LEFT')
cls.enum('CENTER', 'cocos2d::TextHAlignment::CENTER')
cls.enum('RIGHT', 'cocos2d::TextHAlignment::RIGHT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextVAlignment'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('TOP', 'cocos2d::TextVAlignment::TOP')
cls.enum('CENTER', 'cocos2d::TextVAlignment::CENTER')
cls.enum('BOTTOM', 'cocos2d::TextVAlignment::BOTTOM')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GlyphCollection'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('DYNAMIC', 'cocos2d::GlyphCollection::DYNAMIC')
cls.enum('NEHE', 'cocos2d::GlyphCollection::NEHE')
cls.enum('ASCII', 'cocos2d::GlyphCollection::ASCII')
cls.enum('CUSTOM', 'cocos2d::GlyphCollection::CUSTOM')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LabelEffect'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NORMAL', 'cocos2d::LabelEffect::NORMAL')
cls.enum('OUTLINE', 'cocos2d::LabelEffect::OUTLINE')
cls.enum('SHADOW', 'cocos2d::LabelEffect::SHADOW')
cls.enum('GLOW', 'cocos2d::LabelEffect::GLOW')
cls.enum('ITALICS', 'cocos2d::LabelEffect::ITALICS')
cls.enum('BOLD', 'cocos2d::LabelEffect::BOLD')
cls.enum('UNDERLINE', 'cocos2d::LabelEffect::UNDERLINE')
cls.enum('STRIKETHROUGH', 'cocos2d::LabelEffect::STRIKETHROUGH')
cls.enum('ALL', 'cocos2d::LabelEffect::ALL')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Label::LabelType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('TTF', 'cocos2d::Label::LabelType::TTF')
cls.enum('BMFONT', 'cocos2d::Label::LabelType::BMFONT')
cls.enum('CHARMAP', 'cocos2d::Label::LabelType::CHARMAP')
cls.enum('STRING_TEXTURE', 'cocos2d::Label::LabelType::STRING_TEXTURE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Label::Overflow'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::Label::Overflow::NONE')
cls.enum('CLAMP', 'cocos2d::Label::Overflow::CLAMP')
cls.enum('SHRINK', 'cocos2d::Label::Overflow::SHRINK')
cls.enum('RESIZE_HEIGHT', 'cocos2d::Label::Overflow::RESIZE_HEIGHT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Label'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Label *create()')
cls.func(nil, 'static cocos2d::Label *createWithSystemFont(const std::string &text, const std::string &font, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)')
cls.func(nil, 'static cocos2d::Label *createWithTTF(const std::string &text, const std::string &fontFilePath, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)', 'static cocos2d::Label *createWithTTF(const cocos2d::TTFConfig &ttfConfig, const std::string &text, @optional cocos2d::TextHAlignment hAlignment, @optional int maxLineWidth)')
cls.func(nil, 'static cocos2d::Label *createWithBMFont(const std::string &bmfontPath, const std::string &text, @optional const cocos2d::TextHAlignment &hAlignment, @optional int maxLineWidth)', 'static cocos2d::Label *createWithBMFont(const std::string &bmfontPath, const std::string &text, const cocos2d::TextHAlignment &hAlignment, int maxLineWidth, const cocos2d::Rect &imageRect, bool imageRotated)', 'static cocos2d::Label *createWithBMFont(const std::string &bmfontPath, const std::string &text, const cocos2d::TextHAlignment &hAlignment, int maxLineWidth, const std::string &subTextureKey)')
cls.func(nil, 'static cocos2d::Label *createWithCharMap(const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)', 'static cocos2d::Label *createWithCharMap(cocos2d::Texture2D *texture, int itemWidth, int itemHeight, int startCharMap)', 'static cocos2d::Label *createWithCharMap(const std::string &plistFile)')
cls.func(nil, 'bool setTTFConfig(const cocos2d::TTFConfig &ttfConfig)')
cls.func(nil, 'const cocos2d::TTFConfig &getTTFConfig()')
cls.func(nil, 'bool setBMFontFilePath(const std::string &bmfontFilePath, @optional float fontSize)', 'bool setBMFontFilePath(const std::string &bmfontFilePath, const cocos2d::Rect &imageRect, bool imageRotated, @optional float fontSize)', 'bool setBMFontFilePath(const std::string &bmfontFilePath, const std::string &subTextureKey, @optional float fontSize)')
cls.func(nil, 'const std::string &getBMFontFilePath()')
cls.func(nil, 'bool setCharMap(const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)', 'bool setCharMap(cocos2d::Texture2D *texture, int itemWidth, int itemHeight, int startCharMap)', 'bool setCharMap(const std::string &plistFile)')
cls.func(nil, 'void setSystemFontName(const std::string &font)')
cls.func(nil, 'const std::string &getSystemFontName()')
cls.func(nil, 'void setSystemFontSize(float fontSize)')
cls.func(nil, 'float getSystemFontSize()')
cls.func(nil, 'void requestSystemFontRefresh()')
cls.func(nil, 'void setString(const std::string &text)')
cls.func(nil, 'const std::string &getString()')
cls.func(nil, 'int getStringNumLines()')
cls.func(nil, 'int getStringLength()')
cls.func(nil, 'void setTextColor(const cocos2d::Color4B &color)')
cls.func(nil, 'const cocos2d::Color4B &getTextColor()')
cls.func(nil, 'void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)')
cls.func(nil, 'void enableOutline(const cocos2d::Color4B &outlineColor, @optional int outlineSize)')
cls.func(nil, 'void enableGlow(const cocos2d::Color4B &glowColor)')
cls.func(nil, 'void enableItalics()')
cls.func(nil, 'void enableBold()')
cls.func(nil, 'void enableUnderline()')
cls.func(nil, 'void enableStrikethrough()')
cls.func(nil, 'void disableEffect()', 'void disableEffect(cocos2d::LabelEffect effect)')
cls.func(nil, 'bool isShadowEnabled()')
cls.func(nil, 'cocos2d::Size getShadowOffset()')
cls.func(nil, 'float getShadowBlurRadius()')
cls.func(nil, 'cocos2d::Color4F getShadowColor()')
cls.func(nil, 'float getOutlineSize()')
cls.func(nil, 'cocos2d::LabelEffect getLabelEffectType()')
cls.func(nil, 'cocos2d::Color4F getEffectColor()')
cls.func(nil, 'void setAlignment(cocos2d::TextHAlignment hAlignment)', 'void setAlignment(cocos2d::TextHAlignment hAlignment, cocos2d::TextVAlignment vAlignment)')
cls.func(nil, 'cocos2d::TextHAlignment getTextAlignment()')
cls.func(nil, 'void setHorizontalAlignment(cocos2d::TextHAlignment hAlignment)')
cls.func(nil, 'cocos2d::TextHAlignment getHorizontalAlignment()')
cls.func(nil, 'void setVerticalAlignment(cocos2d::TextVAlignment vAlignment)')
cls.func(nil, 'cocos2d::TextVAlignment getVerticalAlignment()')
cls.func(nil, 'void setLineBreakWithoutSpace(bool breakWithoutSpace)')
cls.func(nil, 'void setMaxLineWidth(float maxLineWidth)')
cls.func(nil, 'float getMaxLineWidth()')
cls.func(nil, 'void setBMFontSize(float fontSize)')
cls.func(nil, 'float getBMFontSize()')
cls.func(nil, 'void enableWrap(bool enable)')
cls.func(nil, 'bool isWrapEnabled()')
cls.func(nil, 'void setOverflow(cocos2d::Label::Overflow overflow)')
cls.func(nil, 'cocos2d::Label::Overflow getOverflow()')
cls.func(nil, 'void setWidth(float width)')
cls.func(nil, 'float getWidth()')
cls.func(nil, 'void setHeight(float height)')
cls.func(nil, 'float getHeight()')
cls.func(nil, 'void setDimensions(float width, float height)')
cls.func(nil, 'const cocos2d::Size &getDimensions()')
cls.func(nil, 'void updateContent()')
cls.func(nil, 'cocos2d::Sprite *getLetter(int lettetIndex)')
cls.func(nil, 'void setClipMarginEnabled(bool clipEnabled)')
cls.func(nil, 'bool isClipMarginEnabled()')
cls.func(nil, 'void setLineHeight(float height)')
cls.func(nil, 'float getLineHeight()')
cls.func(nil, 'void setLineSpacing(float height)')
cls.func(nil, 'float getLineSpacing()')
cls.func(nil, 'cocos2d::Label::LabelType getLabelType()')
cls.func(nil, 'float getRenderingFontSize()')
cls.func(nil, 'void setAdditionalKerning(float space)')
cls.func(nil, 'float getAdditionalKerning()')
cls.func(nil, 'cocos2d::FontAtlas *getFontAtlas()')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'Label(@optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)')
cls.func(nil, 'bool initWithTTF(const std::string &text, const std::string &fontFilePath, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)', 'bool initWithTTF(const cocos2d::TTFConfig &ttfConfig, const std::string &text, @optional cocos2d::TextHAlignment hAlignment, @optional int maxLineWidth)')
cls.prop('ttfConfig', nil, nil)
cls.prop('bmFontFilePath', nil, nil)
cls.prop('systemFontName', nil, nil)
cls.prop('systemFontSize', nil, nil)
cls.prop('string', nil, nil)
cls.prop('stringNumLines', nil, nil)
cls.prop('stringLength', nil, nil)
cls.prop('textColor', nil, nil)
cls.prop('shadowEnabled', nil, nil)
cls.prop('shadowOffset', nil, nil)
cls.prop('shadowBlurRadius', nil, nil)
cls.prop('shadowColor', nil, nil)
cls.prop('outlineSize', nil, nil)
cls.prop('labelEffectType', nil, nil)
cls.prop('effectColor', nil, nil)
cls.prop('textAlignment', nil, nil)
cls.prop('horizontalAlignment', nil, nil)
cls.prop('verticalAlignment', nil, nil)
cls.prop('maxLineWidth', nil, nil)
cls.prop('bmFontSize', nil, nil)
cls.prop('wrapEnabled', nil, nil)
cls.prop('overflow', nil, nil)
cls.prop('width', nil, nil)
cls.prop('height', nil, nil)
cls.prop('dimensions', nil, nil)
cls.prop('clipMarginEnabled', nil, nil)
cls.prop('lineHeight', nil, nil)
cls.prop('lineSpacing', nil, nil)
cls.prop('labelType', nil, nil)
cls.prop('renderingFontSize', nil, nil)
cls.prop('additionalKerning', nil, nil)
cls.prop('fontAtlas', nil, nil)
cls.prop('blendFunc', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LabelAtlas'
cls.SUPERCLS = 'cocos2d::AtlasNode'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::LabelAtlas *create()', 'static cocos2d::LabelAtlas *create(const std::string &string, const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)', 'static cocos2d::LabelAtlas *create(const std::string &string, const std::string &fntFile)')
cls.func(nil, 'bool initWithString(const std::string &string, const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)', 'bool initWithString(const std::string &string, const std::string &fntFile)', 'bool initWithString(const std::string &string, cocos2d::Texture2D *texture, int itemWidth, int itemHeight, int startCharMap)')
cls.func(nil, 'void setString(const std::string &label)')
cls.func(nil, 'const std::string &getString()')
cls.func(nil, 'LabelAtlas()')
cls.prop('string', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FontAtlas'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('CacheTextureWidth', 'cocos2d::FontAtlas::CacheTextureWidth', 'const int')
cls.const('CacheTextureHeight', 'cocos2d::FontAtlas::CacheTextureHeight', 'const int')
cls.func(nil, 'void addTexture(cocos2d::Texture2D *texture, int slot)')
cls.func(nil, 'float getLineHeight()')
cls.func(nil, 'void setLineHeight(float newHeight)')
cls.func(nil, 'std::string getFontName()')
cls.func(nil, 'cocos2d::Texture2D *getTexture(int slot)')
cls.func(nil, 'void listenRendererRecreated(cocos2d::EventCustom *event)')
cls.func(nil, 'void purgeTexturesAtlas()')
cls.func(nil, 'void setAntiAliasTexParameters()')
cls.func(nil, 'void setAliasTexParameters()')
cls.var('CMD_PURGE_FONTATLAS', 'static const char *CMD_PURGE_FONTATLAS')
cls.var('CMD_RESET_FONTATLAS', 'static const char *CMD_RESET_FONTATLAS')
cls.prop('lineHeight', nil, nil)
cls.prop('fontName', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ClippingRectangleNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ClippingRectangleNode *create(const cocos2d::Rect &clippingRegion)', 'static cocos2d::ClippingRectangleNode *create()')
cls.func(nil, 'const cocos2d::Rect &getClippingRegion()')
cls.func(nil, 'void setClippingRegion(const cocos2d::Rect &clippingRegion)')
cls.func(nil, 'bool isClippingEnabled()')
cls.func(nil, 'void setClippingEnabled(bool enabled)')
cls.prop('clippingRegion', nil, nil)
cls.prop('clippingEnabled', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RenderTexture'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::RenderTexture *create(int w, int h, cocos2d::backend::PixelFormat format, cocos2d::backend::PixelFormat depthStencilFormat)', 'static cocos2d::RenderTexture *create(int w, int h, cocos2d::backend::PixelFormat format)', 'static cocos2d::RenderTexture *create(int w, int h)')
cls.func(nil, 'void begin()')
cls.func(nil, 'void beginWithClear(float r, float g, float b, float a)', 'void beginWithClear(float r, float g, float b, float a, float depthValue)', 'void beginWithClear(float r, float g, float b, float a, float depthValue, int stencilValue)')
cls.func(nil, 'void end()')
cls.func(nil, 'void clear(float r, float g, float b, float a)')
cls.func(nil, 'void clearDepth(float depthValue)')
cls.func(nil, 'void clearStencil(int stencilValue)')
cls.func(nil, 'void listenToBackground(cocos2d::EventCustom *event)')
cls.func(nil, 'void listenToForeground(cocos2d::EventCustom *event)')
cls.func(nil, 'cocos2d::ClearFlag getClearFlags()')
cls.func(nil, 'void setClearFlags(cocos2d::ClearFlag clearFlags)')
cls.func(nil, 'const cocos2d::Color4F &getClearColor()')
cls.func(nil, 'void setClearColor(const cocos2d::Color4F &clearColor)')
cls.func(nil, 'float getClearDepth()')
cls.func(nil, 'void setClearDepth(float clearDepth)')
cls.func(nil, 'int getClearStencil()')
cls.func(nil, 'void setClearStencil(int clearStencil)')
cls.func(nil, 'bool isAutoDraw()')
cls.func(nil, 'void setAutoDraw(bool isAutoDraw)')
cls.func(nil, 'cocos2d::Sprite *getSprite()')
cls.func(nil, 'void setSprite(cocos2d::Sprite *sprite)')
cls.func(nil, 'void setKeepMatrix(bool keepMatrix)')
cls.func(nil, 'void setVirtualViewport(const cocos2d::Vec2 &rtBegin, const cocos2d::Rect &fullRect, const cocos2d::Rect &fullViewport)')
cls.func(nil, 'RenderTexture()')
cls.func(nil, 'bool initWithWidthAndHeight(int w, int h, cocos2d::backend::PixelFormat format)', 'bool initWithWidthAndHeight(int w, int h, cocos2d::backend::PixelFormat format, cocos2d::backend::PixelFormat depthStencilFormat)')
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
cls.prop('clearFlags', nil, nil)
cls.prop('clearColor', nil, nil)
cls.prop('clearDepth', nil, nil)
cls.prop('clearStencil', nil, nil)
cls.prop('autoDraw', nil, nil)
cls.prop('sprite', nil, nil)
cls.alias('begin', 'beginVisit')
cls.alias('end', 'endVisit')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProgressTimer::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('RADIAL', 'cocos2d::ProgressTimer::Type::RADIAL')
cls.enum('BAR', 'cocos2d::ProgressTimer::Type::BAR')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProgressTimer'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ProgressTimer *create(cocos2d::Sprite *sp)')
cls.func(nil, 'cocos2d::ProgressTimer::Type getType()')
cls.func(nil, 'float getPercentage()')
cls.func(nil, 'cocos2d::Sprite *getSprite()')
cls.func(nil, 'void setPercentage(float percentage)')
cls.func(nil, 'void setSprite(cocos2d::Sprite *sprite)')
cls.func(nil, 'void setType(cocos2d::ProgressTimer::Type type)')
cls.func(nil, 'bool isReverseDirection()')
cls.func(nil, 'void setReverseDirection(bool value)')
cls.func(nil, 'void setMidpoint(const cocos2d::Vec2 &point)')
cls.func(nil, 'cocos2d::Vec2 getMidpoint()')
cls.func(nil, 'void setBarChangeRate(const cocos2d::Vec2 &barChangeRate)')
cls.func(nil, 'cocos2d::Vec2 getBarChangeRate()')
cls.func(nil, 'ProgressTimer()')
cls.func(nil, 'bool initWithSprite(cocos2d::Sprite *sp)')
cls.prop('type', nil, nil)
cls.prop('percentage', nil, nil)
cls.prop('sprite', nil, nil)
cls.prop('reverseDirection', nil, nil)
cls.prop('midpoint', nil, nil)
cls.prop('barChangeRate', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AnimationFrame'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::AnimationFrame *create(cocos2d::SpriteFrame *spriteFrame, float delayUnits, const cocos2d::ValueMap &userInfo)')
cls.func(nil, 'cocos2d::SpriteFrame *getSpriteFrame()')
cls.func(nil, 'void setSpriteFrame(cocos2d::SpriteFrame *frame)')
cls.func(nil, 'float getDelayUnits()')
cls.func(nil, 'void setDelayUnits(float delayUnits)')
cls.func(nil, 'const cocos2d::ValueMap &getUserInfo()')
cls.func(nil, 'void setUserInfo(const cocos2d::ValueMap &userInfo)')
cls.func(nil, 'cocos2d::AnimationFrame *clone()')
cls.func(nil, 'AnimationFrame()')
cls.func(nil, 'bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, float delayUnits, const cocos2d::ValueMap &userInfo)')
cls.prop('spriteFrame', nil, nil)
cls.prop('delayUnits', nil, nil)
cls.prop('userInfo', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Animation'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Animation *create()', 'static cocos2d::Animation *create(const Vector<cocos2d::AnimationFrame *> &arrayOfAnimationFrameNames, float delayPerUnit, @optional unsigned int loops)')
cls.func(nil, 'static cocos2d::Animation *createWithSpriteFrames(const Vector<cocos2d::SpriteFrame *> &arrayOfSpriteFrameNames, @optional float delay, @optional unsigned int loops)')
cls.func(nil, 'void addSpriteFrame(cocos2d::SpriteFrame *frame)')
cls.func(nil, 'void addSpriteFrameWithFile(const std::string &filename)')
cls.func(nil, 'void addSpriteFrameWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect)')
cls.func(nil, 'float getTotalDelayUnits()')
cls.func(nil, 'void setDelayPerUnit(float delayPerUnit)')
cls.func(nil, 'float getDelayPerUnit()')
cls.func(nil, 'float getDuration()')
cls.func(nil, 'const Vector<cocos2d::AnimationFrame *> &getFrames()')
cls.func(nil, 'void setFrames(const Vector<cocos2d::AnimationFrame *> &frames)')
cls.func(nil, 'bool getRestoreOriginalFrame()')
cls.func(nil, 'void setRestoreOriginalFrame(bool restoreOriginalFrame)')
cls.func(nil, 'unsigned int getLoops()')
cls.func(nil, 'void setLoops(unsigned int loops)')
cls.func(nil, 'cocos2d::Animation *clone()')
cls.func(nil, 'Animation()')
cls.func(nil, 'bool init()')
cls.func(nil, 'bool initWithSpriteFrames(const Vector<cocos2d::SpriteFrame *> &arrayOfSpriteFrameNames, @optional float delay, @optional unsigned int loops)')
cls.func(nil, 'bool initWithAnimationFrames(const Vector<cocos2d::AnimationFrame *> &arrayOfAnimationFrameNames, float delayPerUnit, unsigned int loops)')
cls.prop('totalDelayUnits', nil, nil)
cls.prop('delayPerUnit', nil, nil)
cls.prop('duration', nil, nil)
cls.prop('frames', nil, nil)
cls.prop('restoreOriginalFrame', nil, nil)
cls.prop('loops', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SpriteFrame'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::SpriteFrame *create(const std::string &filename, const cocos2d::Rect &rect)', 'static cocos2d::SpriteFrame *create(const std::string &filename, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)')
cls.func(nil, 'static cocos2d::SpriteFrame *createWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect)', 'static cocos2d::SpriteFrame *createWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)')
cls.func(nil, 'const cocos2d::Rect &getRectInPixels()')
cls.func(nil, 'void setRectInPixels(const cocos2d::Rect &rectInPixels)')
cls.func(nil, 'bool isRotated()')
cls.func(nil, 'void setRotated(bool rotated)')
cls.func(nil, 'const cocos2d::Rect &getRect()')
cls.func(nil, 'void setRect(const cocos2d::Rect &rect)')
cls.func(nil, 'const cocos2d::Rect &getCenterRect()')
cls.func(nil, 'void setCenterRectInPixels(const cocos2d::Rect &centerRect)')
cls.func(nil, 'bool hasCenterRect()')
cls.func(nil, 'const cocos2d::Vec2 &getOffsetInPixels()')
cls.func(nil, 'void setOffsetInPixels(const cocos2d::Vec2 &offsetInPixels)')
cls.func(nil, 'const cocos2d::Size &getOriginalSizeInPixels()')
cls.func(nil, 'void setOriginalSizeInPixels(const cocos2d::Size &sizeInPixels)')
cls.func(nil, 'const cocos2d::Size &getOriginalSize()')
cls.func(nil, 'void setOriginalSize(const cocos2d::Size &sizeInPixels)')
cls.func(nil, 'cocos2d::Texture2D *getTexture()')
cls.func(nil, 'void setTexture(cocos2d::Texture2D *pobTexture)')
cls.func(nil, 'const cocos2d::Vec2 &getOffset()')
cls.func(nil, 'void setOffset(const cocos2d::Vec2 &offsets)')
cls.func(nil, 'const cocos2d::Vec2 &getAnchorPoint()')
cls.func(nil, 'void setAnchorPoint(const cocos2d::Vec2 &anchorPoint)')
cls.func(nil, 'bool hasAnchorPoint()')
cls.func(nil, 'cocos2d::SpriteFrame *clone()')
cls.func(nil, 'bool hasPolygonInfo()')
cls.func(nil, 'SpriteFrame()')
cls.func(nil, 'bool initWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect)', 'bool initWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)')
cls.func(nil, 'bool initWithTextureFilename(const std::string &filename, const cocos2d::Rect &rect)', 'bool initWithTextureFilename(const std::string &filename, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)')
cls.prop('rectInPixels', nil, nil)
cls.prop('rotated', nil, nil)
cls.prop('rect', nil, nil)
cls.prop('centerRect', nil, nil)
cls.prop('offsetInPixels', nil, nil)
cls.prop('originalSizeInPixels', nil, nil)
cls.prop('originalSize', nil, nil)
cls.prop('texture', nil, nil)
cls.prop('offset', nil, nil)
cls.prop('anchorPoint', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Sprite'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('INDEX_NOT_INITIALIZED', 'cocos2d::Sprite::INDEX_NOT_INITIALIZED', 'const int')
cls.func(nil, 'static cocos2d::Sprite *create()', 'static cocos2d::Sprite *create(const std::string &filename)', 'static cocos2d::Sprite *create(const std::string &filename, const cocos2d::Rect &rect)')
cls.func(nil, 'static cocos2d::Sprite *createWithTexture(cocos2d::Texture2D *texture)', 'static cocos2d::Sprite *createWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect &rect, @optional bool rotated)')
cls.func(nil, 'static cocos2d::Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)')
cls.func(nil, 'static cocos2d::Sprite *createWithSpriteFrameName(const std::string &spriteFrameName)')
cls.func(nil, 'cocos2d::SpriteBatchNode *getBatchNode()')
cls.func(nil, 'void setBatchNode(cocos2d::SpriteBatchNode *spriteBatchNode)')
cls.func(nil, 'void setTexture(const std::string &filename)', 'void setTexture(cocos2d::Texture2D *texture)')
cls.func(nil, 'cocos2d::Texture2D *getTexture()')
cls.func(nil, 'void setTextureRect(const cocos2d::Rect &rect)', 'void setTextureRect(const cocos2d::Rect &rect, bool rotated, const cocos2d::Size &untrimmedSize)')
cls.func(nil, 'void setVertexRect(const cocos2d::Rect &rect)')
cls.func(nil, 'void setCenterRectNormalized(const cocos2d::Rect &rect)')
cls.func(nil, 'cocos2d::Rect getCenterRectNormalized()')
cls.func(nil, 'void setCenterRect(const cocos2d::Rect &rect)')
cls.func(nil, 'cocos2d::Rect getCenterRect()')
cls.func(nil, 'void setSpriteFrame(const std::string &spriteFrameName)', 'void setSpriteFrame(cocos2d::SpriteFrame *newFrame)')
cls.func(nil, 'bool isFrameDisplayed(cocos2d::SpriteFrame *frame)')
cls.func(nil, 'cocos2d::SpriteFrame *getSpriteFrame()')
cls.func(nil, 'void setDisplayFrameWithAnimationName(const std::string &animationName, unsigned int frameIndex)')
cls.func(nil, 'bool isDirty()')
cls.func(nil, 'void setDirty(bool dirty)')
cls.func(nil, 'bool isTextureRectRotated()')
cls.func(nil, 'unsigned int getAtlasIndex()')
cls.func(nil, 'void setAtlasIndex(unsigned int atlasIndex)')
cls.func(nil, 'const cocos2d::Rect &getTextureRect()')
cls.func(nil, 'cocos2d::TextureAtlas *getTextureAtlas()')
cls.func(nil, 'void setTextureAtlas(cocos2d::TextureAtlas *textureAtlas)')
cls.func(nil, 'const cocos2d::Vec2 &getOffsetPosition()')
cls.func(nil, 'bool isFlippedX()')
cls.func(nil, 'void setFlippedX(bool flippedX)')
cls.func(nil, 'bool isFlippedY()')
cls.func(nil, 'void setFlippedY(bool flippedY)')
cls.func(nil, 'void setStretchEnabled(bool enabled)')
cls.func(nil, 'bool isStretchEnabled()')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'int getResourceType()')
cls.func(nil, 'const std::string &getResourceName()')
cls.func(nil, 'Sprite()')
cls.func(nil, 'bool initWithTexture(cocos2d::Texture2D *texture)', 'bool initWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect &rect)', 'bool initWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect &rect, bool rotated)')
cls.func(nil, 'bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)')
cls.func(nil, 'bool initWithSpriteFrameName(const std::string &spriteFrameName)')
cls.func(nil, 'bool initWithFile(const std::string &filename)', 'bool initWithFile(const std::string &filename, const cocos2d::Rect &rect)')
cls.func(nil, 'void setVertexLayout()')
cls.func(nil, 'void updateShaders(const char *vert, const char *frag)')
cls.prop('batchNode', nil, nil)
cls.prop('texture', nil, nil)
cls.prop('centerRectNormalized', nil, nil)
cls.prop('centerRect', nil, nil)
cls.prop('spriteFrame', nil, nil)
cls.prop('dirty', nil, nil)
cls.prop('textureRectRotated', nil, nil)
cls.prop('atlasIndex', nil, nil)
cls.prop('textureRect', nil, nil)
cls.prop('textureAtlas', nil, nil)
cls.prop('offsetPosition', nil, nil)
cls.prop('flippedX', nil, nil)
cls.prop('flippedY', nil, nil)
cls.prop('stretchEnabled', nil, nil)
cls.prop('blendFunc', nil, nil)
cls.prop('resourceType', nil, nil)
cls.prop('resourceName', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SpriteBatchNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::SpriteBatchNode *createWithTexture(cocos2d::Texture2D *tex, @optional ssize_t capacity)')
cls.func(nil, 'static cocos2d::SpriteBatchNode *create(const std::string &fileImage, @optional ssize_t capacity)')
cls.func(nil, 'cocos2d::TextureAtlas *getTextureAtlas()')
cls.func(nil, 'void setTextureAtlas(cocos2d::TextureAtlas *textureAtlas)')
cls.func(nil, 'const std::vector<Sprite *> &getDescendants()')
cls.func(nil, 'void increaseAtlasCapacity()')
cls.func(nil, 'void removeChildAtIndex(ssize_t index, bool doCleanup)')
cls.func(nil, 'void appendChild(cocos2d::Sprite *sprite)')
cls.func(nil, 'void removeSpriteFromAtlas(cocos2d::Sprite *sprite)')
cls.func(nil, 'ssize_t rebuildIndexInOrder(cocos2d::Sprite *parent, ssize_t index)')
cls.func(nil, 'ssize_t highestAtlasIndexInChild(cocos2d::Sprite *sprite)')
cls.func(nil, 'ssize_t lowestAtlasIndexInChild(cocos2d::Sprite *sprite)')
cls.func(nil, 'ssize_t atlasIndexForChild(cocos2d::Sprite *sprite, int z)')
cls.func(nil, 'void reorderBatch(bool reorder)')
cls.func(nil, 'cocos2d::Texture2D *getTexture()')
cls.func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'void insertQuadFromSprite(cocos2d::Sprite *sprite, ssize_t index)')
cls.func(nil, 'cocos2d::SpriteBatchNode *addSpriteWithoutQuad(cocos2d::Sprite *child, int z, int aTag)')
cls.func(nil, 'void reserveCapacity(ssize_t newCapacity)')
cls.func(nil, 'SpriteBatchNode()')
cls.func(nil, 'bool initWithTexture(cocos2d::Texture2D *tex, @optional ssize_t capacity)')
cls.func(nil, 'bool initWithFile(const std::string &fileImage, @optional ssize_t capacity)')
cls.prop('textureAtlas', nil, nil)
cls.prop('descendants', nil, nil)
cls.prop('texture', nil, nil)
cls.prop('blendFunc', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SpriteFrameCache'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::SpriteFrameCache *getInstance()')
cls.func(nil, 'static void destroyInstance()')
cls.func(nil, 'bool init()')
cls.func(nil, 'void addSpriteFramesWithFile(const std::string &plist)', 'void addSpriteFramesWithFile(const std::string &plist, const std::string &textureFileName)', 'void addSpriteFramesWithFile(const std::string &plist, cocos2d::Texture2D *texture)')
cls.func(nil, 'void addSpriteFramesWithFileContent(const std::string &plist_content, cocos2d::Texture2D *texture)')
cls.func(nil, 'void addSpriteFrame(cocos2d::SpriteFrame *frame, const std::string &frameName)')
cls.func(nil, 'bool isSpriteFramesWithFileLoaded(const std::string &plist)')
cls.func(nil, 'void removeSpriteFrames()')
cls.func(nil, 'void removeUnusedSpriteFrames()')
cls.func(nil, 'void removeSpriteFrameByName(const std::string &name)')
cls.func(nil, 'void removeSpriteFramesFromFile(const std::string &plist)')
cls.func(nil, 'void removeSpriteFramesFromFileContent(const std::string &plist_content)')
cls.func(nil, 'void removeSpriteFramesFromTexture(cocos2d::Texture2D *texture)')
cls.func(nil, 'cocos2d::SpriteFrame *getSpriteFrameByName(const std::string &name)')
cls.func(nil, 'bool reloadTexture(const std::string &plist)')
cls.prop('instance', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AnimationCache'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'AnimationCache()')
cls.func(nil, 'static cocos2d::AnimationCache *getInstance()')
cls.func(nil, 'static void destroyInstance()')
cls.func(nil, 'bool init()')
cls.func(nil, 'void addAnimation(cocos2d::Animation *animation, const std::string &name)')
cls.func(nil, 'void removeAnimation(const std::string &name)')
cls.func(nil, 'cocos2d::Animation *getAnimation(const std::string &name)')
cls.func(nil, 'void addAnimationsWithDictionary(const cocos2d::ValueMap &dictionary, const std::string &plist)')
cls.func(nil, 'void addAnimationsWithFile(const std::string &plist)')
cls.prop('instance', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Scene'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Scene *create()')
cls.func(nil, 'static cocos2d::Scene *createWithSize(const cocos2d::Size &size)')
cls.func(nil, 'const std::vector<Camera *> &getCameras()')
cls.func(nil, 'cocos2d::Camera *getDefaultCamera()')
cls.func(nil, 'const std::vector<BaseLight *> &getLights()')
cls.func(nil, 'Scene()')
cls.func(nil, 'bool initWithSize(const cocos2d::Size &size)')
cls.func(nil, 'void setCameraOrderDirty()')
cls.func(nil, 'void onProjectionChanged(cocos2d::EventCustom *event)')
cls.func(nil, '@addref(physicsWorld ^) cocos2d::PhysicsWorld *getPhysicsWorld()')
cls.func(nil, 'void setPhysics3DDebugCamera(cocos2d::Camera *camera)')
cls.func(nil, 'static cocos2d::Scene *createWithPhysics()')
cls.func(nil, 'bool initWithPhysics()')
cls.func(nil, 'void setNavMeshDebugCamera(cocos2d::Camera *camera)')
cls.func(nil, 'void stepPhysicsAndNavigation(float deltaTime)')
cls.prop('cameras', nil, nil)
cls.prop('defaultCamera', nil, nil)
cls.prop('lights', nil, nil)
cls.prop('physicsWorld', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Layer'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Layer *create()')
cls.func(nil, 'bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)')
cls.func(nil, 'void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)')
cls.func(nil, 'void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)')
cls.func(nil, 'void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event)')
cls.func(nil, 'void onTouchesBegan(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)')
cls.func(nil, 'void onTouchesMoved(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)')
cls.func(nil, 'void onTouchesEnded(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)')
cls.func(nil, 'void onTouchesCancelled(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)')
cls.func(nil, 'void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *unused_event)')
cls.func(nil, 'void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)')
cls.func(nil, 'void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)')
cls.func(nil, 'Layer()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LayerColor'
cls.SUPERCLS = 'cocos2d::Layer'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::LayerColor *create()', 'static cocos2d::LayerColor *create(const cocos2d::Color4B &color, float width, float height)', 'static cocos2d::LayerColor *create(const cocos2d::Color4B &color)')
cls.func(nil, 'void changeWidth(float w)')
cls.func(nil, 'void changeHeight(float h)')
cls.func(nil, 'void changeWidthAndHeight(float w, float h)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'LayerColor()')
cls.func(nil, 'bool initWithColor(const cocos2d::Color4B &color, float width, float height)', 'bool initWithColor(const cocos2d::Color4B &color)')
cls.prop('blendFunc', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LayerGradient'
cls.SUPERCLS = 'cocos2d::LayerColor'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::LayerGradient *create()', 'static cocos2d::LayerGradient *create(const cocos2d::Color4B &start, const cocos2d::Color4B &end)', 'static cocos2d::LayerGradient *create(const cocos2d::Color4B &start, const cocos2d::Color4B &end, const cocos2d::Vec2 &v)')
cls.func(nil, 'void setCompressedInterpolation(bool compressedInterpolation)')
cls.func(nil, 'bool isCompressedInterpolation()')
cls.func(nil, 'void setStartColor(const cocos2d::Color3B &startColor)')
cls.func(nil, 'const cocos2d::Color3B &getStartColor()')
cls.func(nil, 'void setEndColor(const cocos2d::Color3B &endColor)')
cls.func(nil, 'const cocos2d::Color3B &getEndColor()')
cls.func(nil, 'void setStartOpacity(uint8_t startOpacity)')
cls.func(nil, 'uint8_t getStartOpacity()')
cls.func(nil, 'void setEndOpacity(uint8_t endOpacity)')
cls.func(nil, 'uint8_t getEndOpacity()')
cls.func(nil, 'void setVector(const cocos2d::Vec2 &alongVector)')
cls.func(nil, 'const cocos2d::Vec2 &getVector()')
cls.func(nil, 'LayerGradient()')
cls.func(nil, 'bool initWithColor(const cocos2d::Color4B &start, const cocos2d::Color4B &end)', 'bool initWithColor(const cocos2d::Color4B &start, const cocos2d::Color4B &end, const cocos2d::Vec2 &v)')
cls.prop('compressedInterpolation', nil, nil)
cls.prop('startColor', nil, nil)
cls.prop('endColor', nil, nil)
cls.prop('startOpacity', nil, nil)
cls.prop('endOpacity', nil, nil)
cls.prop('vector', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LayerRadialGradient'
cls.SUPERCLS = 'cocos2d::Layer'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::LayerRadialGradient *create(const cocos2d::Color4B &startColor, const cocos2d::Color4B &endColor, float radius, const cocos2d::Vec2 &center, float expand)', 'static cocos2d::LayerRadialGradient *create()')
cls.func(nil, 'void setStartOpacity(uint8_t opacity)')
cls.func(nil, 'uint8_t getStartOpacity()')
cls.func(nil, 'void setEndOpacity(uint8_t opacity)')
cls.func(nil, 'uint8_t getEndOpacity()')
cls.func(nil, 'void setRadius(float radius)')
cls.func(nil, 'float getRadius()')
cls.func(nil, 'void setCenter(const cocos2d::Vec2 &center)')
cls.func(nil, 'cocos2d::Vec2 getCenter()')
cls.func(nil, 'void setExpand(float expand)')
cls.func(nil, 'float getExpand()')
cls.func(nil, 'void setStartColor(const cocos2d::Color3B &color)', 'void setStartColor(const cocos2d::Color4B &color)')
cls.func(nil, 'cocos2d::Color4B getStartColor()')
cls.func(nil, 'cocos2d::Color3B getStartColor3B()')
cls.func(nil, 'void setEndColor(const cocos2d::Color3B &color)', 'void setEndColor(const cocos2d::Color4B &color)')
cls.func(nil, 'cocos2d::Color4B getEndColor()')
cls.func(nil, 'cocos2d::Color3B getEndColor3B()')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'cocos2d::BlendFunc getBlendFunc()')
cls.func(nil, 'LayerRadialGradient()')
cls.func(nil, 'bool initWithColor(const cocos2d::Color4B &startColor, const cocos2d::Color4B &endColor, float radius, const cocos2d::Vec2 &center, float expand)')
cls.prop('startOpacity', nil, nil)
cls.prop('endOpacity', nil, nil)
cls.prop('radius', nil, nil)
cls.prop('center', nil, nil)
cls.prop('expand', nil, nil)
cls.prop('startColor', nil, nil)
cls.prop('startColor3B', nil, nil)
cls.prop('endColor', nil, nil)
cls.prop('endColor3B', nil, nil)
cls.prop('blendFunc', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LayerMultiplex'
cls.SUPERCLS = 'cocos2d::Layer'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::LayerMultiplex *create()')
cls.func(nil, 'static cocos2d::LayerMultiplex *createWithArray(const Vector<cocos2d::Layer *> &arrayOfLayers)')
cls.func(nil, 'static cocos2d::LayerMultiplex *createWithLayer(cocos2d::Layer *layer)')
cls.func(nil, 'void addLayer(cocos2d::Layer *layer)')
cls.func(nil, 'void switchTo(int n)', 'void switchTo(int n, bool cleanup)')
cls.func(nil, 'void switchToAndReleaseMe(int n)')
cls.func(nil, 'LayerMultiplex()')
cls.func(nil, 'bool initWithArray(const Vector<cocos2d::Layer *> &arrayOfLayers)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionScene::Orientation'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('LEFT_OVER', 'cocos2d::TransitionScene::Orientation::LEFT_OVER')
cls.enum('RIGHT_OVER', 'cocos2d::TransitionScene::Orientation::RIGHT_OVER')
cls.enum('UP_OVER', 'cocos2d::TransitionScene::Orientation::UP_OVER')
cls.enum('DOWN_OVER', 'cocos2d::TransitionScene::Orientation::DOWN_OVER')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionScene'
cls.SUPERCLS = 'cocos2d::Scene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionScene *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'void finish()')
cls.func(nil, 'void hideOutShowIn()')
cls.func(nil, 'cocos2d::Scene *getInScene()')
cls.func(nil, 'float getDuration()')
cls.func(nil, 'TransitionScene()')
cls.prop('inScene', nil, nil)
cls.prop('duration', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSceneOriented'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionSceneOriented *create(float t, @addref(scenes |) cocos2d::Scene *scene, cocos2d::TransitionScene::Orientation orientation)')
cls.func(nil, 'TransitionSceneOriented()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionRotoZoom'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionRotoZoom *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionRotoZoom()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionJumpZoom'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionJumpZoom *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionJumpZoom()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInL'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionMoveInL *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'cocos2d::ActionInterval *action()')
cls.func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
cls.func(nil, 'TransitionMoveInL()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInR'
cls.SUPERCLS = 'cocos2d::TransitionMoveInL'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionMoveInR *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionMoveInR()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInT'
cls.SUPERCLS = 'cocos2d::TransitionMoveInL'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionMoveInT *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionMoveInT()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionMoveInB'
cls.SUPERCLS = 'cocos2d::TransitionMoveInL'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionMoveInB *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionMoveInB()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInL'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionSlideInL *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
cls.func(nil, 'cocos2d::ActionInterval *action()')
cls.func(nil, 'TransitionSlideInL()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInR'
cls.SUPERCLS = 'cocos2d::TransitionSlideInL'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionSlideInR *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionSlideInR()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInB'
cls.SUPERCLS = 'cocos2d::TransitionSlideInL'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionSlideInB *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionSlideInB()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSlideInT'
cls.SUPERCLS = 'cocos2d::TransitionSlideInL'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionSlideInT *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionSlideInT()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionShrinkGrow'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionShrinkGrow *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
cls.func(nil, 'TransitionShrinkGrow()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFlipX'
cls.SUPERCLS = 'cocos2d::TransitionSceneOriented'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionFlipX *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionFlipX *create(float t, @addref(scenes |) cocos2d::Scene *s)')
cls.func(nil, 'TransitionFlipX()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFlipY'
cls.SUPERCLS = 'cocos2d::TransitionSceneOriented'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionFlipY *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionFlipY *create(float t, @addref(scenes |) cocos2d::Scene *s)')
cls.func(nil, 'TransitionFlipY()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFlipAngular'
cls.SUPERCLS = 'cocos2d::TransitionSceneOriented'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionFlipAngular *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionFlipAngular *create(float t, @addref(scenes |) cocos2d::Scene *s)')
cls.func(nil, 'TransitionFlipAngular()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionZoomFlipX'
cls.SUPERCLS = 'cocos2d::TransitionSceneOriented'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionZoomFlipX *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionZoomFlipX *create(float t, @addref(scenes |) cocos2d::Scene *s)')
cls.func(nil, 'TransitionZoomFlipX()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionZoomFlipY'
cls.SUPERCLS = 'cocos2d::TransitionSceneOriented'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionZoomFlipY *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionZoomFlipY *create(float t, @addref(scenes |) cocos2d::Scene *s)')
cls.func(nil, 'TransitionZoomFlipY()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionZoomFlipAngular'
cls.SUPERCLS = 'cocos2d::TransitionSceneOriented'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionZoomFlipAngular *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionZoomFlipAngular *create(float t, @addref(scenes |) cocos2d::Scene *s)')
cls.func(nil, 'TransitionZoomFlipAngular()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFade'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionFade *create(float duration, @addref(scenes |) cocos2d::Scene *scene, const cocos2d::Color3B &color)', 'static cocos2d::TransitionFade *create(float duration, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionFade()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionCrossFade'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionCrossFade *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionCrossFade()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionTurnOffTiles'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionTurnOffTiles *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
cls.func(nil, 'TransitionTurnOffTiles()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSplitCols'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionSplitCols *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'cocos2d::ActionInterval *action()')
cls.func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
cls.func(nil, 'TransitionSplitCols()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionSplitRows'
cls.SUPERCLS = 'cocos2d::TransitionSplitCols'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionSplitRows *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionSplitRows()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeTR'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionFadeTR *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'cocos2d::ActionInterval *actionWithSize(const cocos2d::Size &size)')
cls.func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
cls.func(nil, 'TransitionFadeTR()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeBL'
cls.SUPERCLS = 'cocos2d::TransitionFadeTR'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionFadeBL *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionFadeBL()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeUp'
cls.SUPERCLS = 'cocos2d::TransitionFadeTR'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionFadeUp *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionFadeUp()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionFadeDown'
cls.SUPERCLS = 'cocos2d::TransitionFadeTR'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionFadeDown *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionFadeDown()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionPageTurn'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionPageTurn *create(float t, @addref(scenes |) cocos2d::Scene *scene, bool backwards)')
cls.func(nil, 'cocos2d::ActionInterval *actionWithSize(const cocos2d::Size &vector)')
cls.func(nil, 'TransitionPageTurn()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgress'
cls.SUPERCLS = 'cocos2d::TransitionScene'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionProgress *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionProgress()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressRadialCCW'
cls.SUPERCLS = 'cocos2d::TransitionProgress'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionProgressRadialCCW *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionProgressRadialCCW()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressRadialCW'
cls.SUPERCLS = 'cocos2d::TransitionProgress'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionProgressRadialCW *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionProgressRadialCW()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressHorizontal'
cls.SUPERCLS = 'cocos2d::TransitionProgress'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionProgressHorizontal *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionProgressHorizontal()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressVertical'
cls.SUPERCLS = 'cocos2d::TransitionProgress'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionProgressVertical *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionProgressVertical()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressInOut'
cls.SUPERCLS = 'cocos2d::TransitionProgress'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionProgressInOut *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionProgressInOut()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TransitionProgressOutIn'
cls.SUPERCLS = 'cocos2d::TransitionProgress'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TransitionProgressOutIn *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
cls.func(nil, 'TransitionProgressOutIn()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextFieldDelegate'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF *sender)')
cls.func(nil, 'bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF *sender)')
cls.func(nil, 'bool onTextFieldInsertText(cocos2d::TextFieldTTF *sender, const char *text, size_t nLen)')
cls.func(nil, 'bool onTextFieldDeleteBackward(cocos2d::TextFieldTTF *sender, const char *delText, size_t nLen)')
cls.func(nil, 'bool onVisit(cocos2d::TextFieldTTF *sender, cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TextFieldTTF'
cls.SUPERCLS = 'cocos2d::Label'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'TextFieldTTF()')
cls.func(nil, 'static cocos2d::TextFieldTTF *textFieldWithPlaceHolder(const std::string &placeholder, const cocos2d::Size &dimensions, cocos2d::TextHAlignment alignment, const std::string &fontName, float fontSize)', 'static cocos2d::TextFieldTTF *textFieldWithPlaceHolder(const std::string &placeholder, const std::string &fontName, float fontSize)')
cls.func(nil, 'bool initWithPlaceHolder(const std::string &placeholder, const cocos2d::Size &dimensions, cocos2d::TextHAlignment alignment, const std::string &fontName, float fontSize)', 'bool initWithPlaceHolder(const std::string &placeholder, const std::string &fontName, float fontSize)')
cls.func(nil, 'bool attachWithIME()')
cls.func(nil, 'bool detachWithIME()')
cls.func(nil, 'cocos2d::TextFieldDelegate *getDelegate()')
cls.func(nil, 'void setDelegate(cocos2d::TextFieldDelegate *delegate)')
cls.func(nil, 'std::size_t getCharCount()')
cls.func(nil, 'const cocos2d::Color4B &getColorSpaceHolder()')
cls.func(nil, 'void setColorSpaceHolder(const cocos2d::Color3B &color)', 'void setColorSpaceHolder(const cocos2d::Color4B &color)')
cls.func(nil, 'void appendString(const std::string &text)')
cls.func(nil, 'void setPlaceHolder(const std::string &text)')
cls.func(nil, 'const std::string &getPlaceHolder()')
cls.func(nil, 'void setSecureTextEntry(bool value)')
cls.func(nil, 'void setPasswordTextStyle(const std::string &text)')
cls.func(nil, 'const std::string &getPasswordTextStyle()')
cls.func(nil, 'bool isSecureTextEntry()')
cls.func(nil, 'void setCursorEnabled(bool enabled)')
cls.func(nil, 'void setCursorChar(char cursor)')
cls.func(nil, 'void setCursorPosition(std::size_t cursorPosition)')
cls.func(nil, 'void setCursorFromPoint(const cocos2d::Vec2 &point, const cocos2d::Camera *camera)')
cls.prop('delegate', nil, nil)
cls.prop('charCount', nil, nil)
cls.prop('colorSpaceHolder', nil, nil)
cls.prop('placeHolder', nil, nil)
cls.prop('passwordTextStyle', nil, nil)
cls.prop('secureTextEntry', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LightType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('DIRECTIONAL', 'cocos2d::LightType::DIRECTIONAL')
cls.enum('POINT', 'cocos2d::LightType::POINT')
cls.enum('SPOT', 'cocos2d::LightType::SPOT')
cls.enum('AMBIENT', 'cocos2d::LightType::AMBIENT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::LightFlag'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('LIGHT0', 'cocos2d::LightFlag::LIGHT0')
cls.enum('LIGHT1', 'cocos2d::LightFlag::LIGHT1')
cls.enum('LIGHT2', 'cocos2d::LightFlag::LIGHT2')
cls.enum('LIGHT3', 'cocos2d::LightFlag::LIGHT3')
cls.enum('LIGHT4', 'cocos2d::LightFlag::LIGHT4')
cls.enum('LIGHT5', 'cocos2d::LightFlag::LIGHT5')
cls.enum('LIGHT6', 'cocos2d::LightFlag::LIGHT6')
cls.enum('LIGHT7', 'cocos2d::LightFlag::LIGHT7')
cls.enum('LIGHT8', 'cocos2d::LightFlag::LIGHT8')
cls.enum('LIGHT9', 'cocos2d::LightFlag::LIGHT9')
cls.enum('LIGHT10', 'cocos2d::LightFlag::LIGHT10')
cls.enum('LIGHT11', 'cocos2d::LightFlag::LIGHT11')
cls.enum('LIGHT12', 'cocos2d::LightFlag::LIGHT12')
cls.enum('LIGHT13', 'cocos2d::LightFlag::LIGHT13')
cls.enum('LIGHT14', 'cocos2d::LightFlag::LIGHT14')
cls.enum('LIGHT15', 'cocos2d::LightFlag::LIGHT15')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BaseLight'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'cocos2d::LightType getLightType()')
cls.func(nil, 'float getIntensity()')
cls.func(nil, 'void setIntensity(float intensity)')
cls.func(nil, 'cocos2d::LightFlag getLightFlag()')
cls.func(nil, 'void setLightFlag(cocos2d::LightFlag flag)')
cls.func(nil, 'void setEnabled(bool enabled)')
cls.func(nil, 'bool isEnabled()')
cls.prop('lightType', nil, nil)
cls.prop('intensity', nil, nil)
cls.prop('lightFlag', nil, nil)
cls.prop('enabled', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::DirectionLight'
cls.SUPERCLS = 'cocos2d::BaseLight'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::DirectionLight *create(const cocos2d::Vec3 &direction, const cocos2d::Color3B &color)')
cls.func(nil, 'void setDirection(const cocos2d::Vec3 &dir)')
cls.func(nil, 'cocos2d::Vec3 getDirection()')
cls.func(nil, 'cocos2d::Vec3 getDirectionInWorld()')
cls.func(nil, 'DirectionLight()')
cls.prop('direction', nil, nil)
cls.prop('directionInWorld', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PointLight'
cls.SUPERCLS = 'cocos2d::BaseLight'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PointLight *create(const cocos2d::Vec3 &position, const cocos2d::Color3B &color, float range)')
cls.func(nil, 'float getRange()')
cls.func(nil, 'void setRange(float range)')
cls.func(nil, 'PointLight()')
cls.prop('range', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SpotLight'
cls.SUPERCLS = 'cocos2d::BaseLight'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::SpotLight *create(const cocos2d::Vec3 &direction, const cocos2d::Vec3 &position, const cocos2d::Color3B &color, float innerAngle, float outerAngle, float range)')
cls.func(nil, 'void setDirection(const cocos2d::Vec3 &dir)')
cls.func(nil, 'cocos2d::Vec3 getDirection()')
cls.func(nil, 'cocos2d::Vec3 getDirectionInWorld()')
cls.func(nil, 'void setRange(float range)')
cls.func(nil, 'float getRange()')
cls.func(nil, 'void setInnerAngle(float angle)')
cls.func(nil, 'float getInnerAngle()')
cls.func(nil, 'float getCosInnerAngle()')
cls.func(nil, 'void setOuterAngle(float outerAngle)')
cls.func(nil, 'float getOuterAngle()')
cls.func(nil, 'float getCosOuterAngle()')
cls.func(nil, 'SpotLight()')
cls.prop('direction', nil, nil)
cls.prop('directionInWorld', nil, nil)
cls.prop('range', nil, nil)
cls.prop('innerAngle', nil, nil)
cls.prop('cosInnerAngle', nil, nil)
cls.prop('outerAngle', nil, nil)
cls.prop('cosOuterAngle', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AmbientLight'
cls.SUPERCLS = 'cocos2d::BaseLight'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::AmbientLight *create(const cocos2d::Color3B &color)')
cls.func(nil, 'AmbientLight()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraFlag'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('DEFAULT', 'cocos2d::CameraFlag::DEFAULT')
cls.enum('USER1', 'cocos2d::CameraFlag::USER1')
cls.enum('USER2', 'cocos2d::CameraFlag::USER2')
cls.enum('USER3', 'cocos2d::CameraFlag::USER3')
cls.enum('USER4', 'cocos2d::CameraFlag::USER4')
cls.enum('USER5', 'cocos2d::CameraFlag::USER5')
cls.enum('USER6', 'cocos2d::CameraFlag::USER6')
cls.enum('USER7', 'cocos2d::CameraFlag::USER7')
cls.enum('USER8', 'cocos2d::CameraFlag::USER8')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Camera::Type'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('PERSPECTIVE', 'cocos2d::Camera::Type::PERSPECTIVE')
cls.enum('ORTHOGRAPHIC', 'cocos2d::Camera::Type::ORTHOGRAPHIC')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Camera'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Camera *createPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)')
cls.func(nil, 'static cocos2d::Camera *createOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)')
cls.func(nil, 'static cocos2d::Camera *create()')
cls.func(nil, 'static const cocos2d::Camera *getVisitingCamera()')
cls.func(nil, 'static const cocos2d::Viewport &getDefaultViewport()')
cls.func(nil, 'static void setDefaultViewport(const cocos2d::Viewport &vp)')
cls.func(nil, 'static cocos2d::Camera *getDefaultCamera()')
cls.func(nil, 'cocos2d::Camera::Type getType()')
cls.func(nil, 'cocos2d::CameraFlag getCameraFlag()')
cls.func(nil, 'void setCameraFlag(cocos2d::CameraFlag flag)')
cls.func(nil, 'void lookAt(const cocos2d::Vec3 &target, @optional const cocos2d::Vec3 &up)')
cls.func(nil, 'const cocos2d::Mat4 &getProjectionMatrix()')
cls.func(nil, 'const cocos2d::Mat4 &getViewMatrix()')
cls.func(nil, 'const cocos2d::Mat4 &getViewProjectionMatrix()')
cls.func(nil, 'cocos2d::Vec2 project(const cocos2d::Vec3 &src)')
cls.func(nil, 'cocos2d::Vec2 projectGL(const cocos2d::Vec3 &src)')
cls.func(nil, 'cocos2d::Vec3 unproject(const cocos2d::Vec3 &src)')
cls.func(nil, 'cocos2d::Vec3 unprojectGL(const cocos2d::Vec3 &src)')
cls.func(nil, 'float getDepthInView(const cocos2d::Mat4 &transform)')
cls.func(nil, 'void setDepth(int8_t depth)')
cls.func(nil, 'int8_t getDepth()')
cls.func(nil, 'int getRenderOrder()')
cls.func(nil, 'float getFarPlane()')
cls.func(nil, 'float getNearPlane()')
cls.func(nil, 'void clearBackground()')
cls.func(nil, 'void apply()')
cls.func(nil, 'bool isViewProjectionUpdated()')
cls.func(nil, 'void setBackgroundBrush(cocos2d::CameraBackgroundBrush *clearBrush)')
cls.func(nil, 'cocos2d::CameraBackgroundBrush *getBackgroundBrush()')
cls.func(nil, 'bool isBrushValid()')
cls.func(nil, 'Camera()')
cls.func(nil, 'void setScene(cocos2d::Scene *scene)')
cls.func(nil, 'void setAdditionalProjection(const cocos2d::Mat4 &mat)')
cls.func(nil, 'bool initDefault()')
cls.func(nil, 'bool initPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)')
cls.func(nil, 'bool initOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)')
cls.func(nil, 'void applyViewport()')
cls.prop('visitingCamera', nil, nil)
cls.prop('defaultViewport', nil, nil)
cls.prop('defaultCamera', nil, nil)
cls.prop('type', nil, nil)
cls.prop('cameraFlag', nil, nil)
cls.prop('projectionMatrix', nil, nil)
cls.prop('viewMatrix', nil, nil)
cls.prop('viewProjectionMatrix', nil, nil)
cls.prop('depth', nil, nil)
cls.prop('renderOrder', nil, nil)
cls.prop('farPlane', nil, nil)
cls.prop('nearPlane', nil, nil)
cls.prop('viewProjectionUpdated', nil, nil)
cls.prop('backgroundBrush', nil, nil)
cls.prop('brushValid', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundBrush::BrushType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::CameraBackgroundBrush::BrushType::NONE')
cls.enum('DEPTH', 'cocos2d::CameraBackgroundBrush::BrushType::DEPTH')
cls.enum('COLOR', 'cocos2d::CameraBackgroundBrush::BrushType::COLOR')
cls.enum('SKYBOX', 'cocos2d::CameraBackgroundBrush::BrushType::SKYBOX')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundBrush'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'cocos2d::CameraBackgroundBrush::BrushType getBrushType()')
cls.func(nil, 'static cocos2d::CameraBackgroundBrush *createNoneBrush()')
cls.func(nil, 'static cocos2d::CameraBackgroundDepthBrush *createDepthBrush(@optional float depth)')
cls.func(nil, 'static cocos2d::CameraBackgroundColorBrush *createColorBrush(const cocos2d::Color4F &color, float depth)')
cls.func(nil, 'static cocos2d::CameraBackgroundSkyBoxBrush *createSkyboxBrush(const std::string &positive_x, const std::string &negative_x, const std::string &positive_y, const std::string &negative_y, const std::string &positive_z, const std::string &negative_z)')
cls.func(nil, 'void drawBackground(cocos2d::Camera *)')
cls.func(nil, 'bool isValid()')
cls.func(nil, 'CameraBackgroundBrush()')
cls.func(nil, 'bool init()')
cls.prop('brushType', nil, nil)
cls.prop('valid', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundDepthBrush'
cls.SUPERCLS = 'cocos2d::CameraBackgroundBrush'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::CameraBackgroundDepthBrush *create(float depth)')
cls.func(nil, 'void setDepth(float depth)')
cls.func(nil, 'CameraBackgroundDepthBrush()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundColorBrush'
cls.SUPERCLS = 'cocos2d::CameraBackgroundDepthBrush'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::CameraBackgroundColorBrush *create(const cocos2d::Color4F &color, float depth)')
cls.func(nil, 'void setColor(const cocos2d::Color4F &color)')
cls.func(nil, 'CameraBackgroundColorBrush()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CameraBackgroundSkyBoxBrush'
cls.SUPERCLS = 'cocos2d::CameraBackgroundBrush'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::CameraBackgroundSkyBoxBrush *create(const std::string &positive_x, const std::string &negative_x, const std::string &positive_y, const std::string &negative_y, const std::string &positive_z, const std::string &negative_z)', 'static cocos2d::CameraBackgroundSkyBoxBrush *create()')
cls.func(nil, 'void setTexture(cocos2d::TextureCube *texture)')
cls.func(nil, 'bool isActived()')
cls.func(nil, 'void setActived(bool actived)')
cls.func(nil, 'void setTextureValid(bool valid)')
cls.func(nil, 'CameraBackgroundSkyBoxBrush()')
cls.prop('actived', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleBatchNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleBatchNode *createWithTexture(cocos2d::Texture2D *tex, @optional int capacity)')
cls.func(nil, 'static cocos2d::ParticleBatchNode *create(const std::string &fileImage, @optional int capacity)')
cls.func(nil, 'void insertChild(cocos2d::ParticleSystem *system, int index)')
cls.func(nil, 'void removeChildAtIndex(int index, bool doCleanup)')
cls.func(nil, 'void disableParticle(int particleIndex)')
cls.func(nil, 'cocos2d::TextureAtlas *getTextureAtlas()')
cls.func(nil, 'void setTextureAtlas(cocos2d::TextureAtlas *atlas)')
cls.func(nil, 'cocos2d::Texture2D *getTexture()')
cls.func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'ParticleBatchNode()')
cls.func(nil, 'bool initWithTexture(cocos2d::Texture2D *tex, int capacity)')
cls.func(nil, 'bool initWithFile(const std::string &fileImage, int capacity)')
cls.prop('textureAtlas', nil, nil)
cls.prop('texture', nil, nil)
cls.prop('blendFunc', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSystem::Mode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('GRAVITY', 'cocos2d::ParticleSystem::Mode::GRAVITY')
cls.enum('RADIUS', 'cocos2d::ParticleSystem::Mode::RADIUS')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSystem::PositionType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('FREE', 'cocos2d::ParticleSystem::PositionType::FREE')
cls.enum('RELATIVE', 'cocos2d::ParticleSystem::PositionType::RELATIVE')
cls.enum('GROUPED', 'cocos2d::ParticleSystem::PositionType::GROUPED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSystem'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleSystem *create(const std::string &plistFile)')
cls.func(nil, 'static cocos2d::ParticleSystem *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'static Vector<cocos2d::ParticleSystem *> &getAllParticleSystems()')
cls.func(nil, 'void addParticles(int count)')
cls.func(nil, 'void stopSystem()')
cls.func(nil, 'void resetSystem()')
cls.func(nil, 'bool isFull()')
cls.func(nil, 'void updateParticleQuads()')
cls.func(nil, 'void postStep()')
cls.func(nil, 'void updateWithNoTime()')
cls.func(nil, 'bool isAutoRemoveOnFinish()')
cls.func(nil, 'void setAutoRemoveOnFinish(bool var)')
cls.func(nil, 'const cocos2d::Vec2 &getGravity()')
cls.func(nil, 'void setGravity(const cocos2d::Vec2 &g)')
cls.func(nil, 'float getSpeed()')
cls.func(nil, 'void setSpeed(float speed)')
cls.func(nil, 'float getSpeedVar()')
cls.func(nil, 'void setSpeedVar(float speed)')
cls.func(nil, 'float getTangentialAccel()')
cls.func(nil, 'void setTangentialAccel(float t)')
cls.func(nil, 'float getTangentialAccelVar()')
cls.func(nil, 'void setTangentialAccelVar(float t)')
cls.func(nil, 'float getRadialAccel()')
cls.func(nil, 'void setRadialAccel(float t)')
cls.func(nil, 'float getRadialAccelVar()')
cls.func(nil, 'void setRadialAccelVar(float t)')
cls.func(nil, 'bool getRotationIsDir()')
cls.func(nil, 'void setRotationIsDir(bool t)')
cls.func(nil, 'float getStartRadius()')
cls.func(nil, 'void setStartRadius(float startRadius)')
cls.func(nil, 'float getStartRadiusVar()')
cls.func(nil, 'void setStartRadiusVar(float startRadiusVar)')
cls.func(nil, 'float getEndRadius()')
cls.func(nil, 'void setEndRadius(float endRadius)')
cls.func(nil, 'float getEndRadiusVar()')
cls.func(nil, 'void setEndRadiusVar(float endRadiusVar)')
cls.func(nil, 'float getRotatePerSecond()')
cls.func(nil, 'void setRotatePerSecond(float degrees)')
cls.func(nil, 'float getRotatePerSecondVar()')
cls.func(nil, 'void setRotatePerSecondVar(float degrees)')
cls.func(nil, 'bool isActive()')
cls.func(nil, 'bool isBlendAdditive()')
cls.func(nil, 'void setBlendAdditive(bool value)')
cls.func(nil, 'cocos2d::ParticleBatchNode *getBatchNode()')
cls.func(nil, 'void setBatchNode(cocos2d::ParticleBatchNode *batchNode)')
cls.func(nil, 'int getAtlasIndex()')
cls.func(nil, 'void setAtlasIndex(int index)')
cls.func(nil, 'unsigned int getParticleCount()')
cls.func(nil, 'float getDuration()')
cls.func(nil, 'void setDuration(float duration)')
cls.func(nil, 'const cocos2d::Vec2 &getSourcePosition()')
cls.func(nil, 'void setSourcePosition(const cocos2d::Vec2 &pos)')
cls.func(nil, 'const cocos2d::Vec2 &getPosVar()')
cls.func(nil, 'void setPosVar(const cocos2d::Vec2 &pos)')
cls.func(nil, 'float getLife()')
cls.func(nil, 'void setLife(float life)')
cls.func(nil, 'float getLifeVar()')
cls.func(nil, 'void setLifeVar(float lifeVar)')
cls.func(nil, 'float getAngle()')
cls.func(nil, 'void setAngle(float angle)')
cls.func(nil, 'float getAngleVar()')
cls.func(nil, 'void setAngleVar(float angleVar)')
cls.func(nil, 'cocos2d::ParticleSystem::Mode getEmitterMode()')
cls.func(nil, 'void setEmitterMode(cocos2d::ParticleSystem::Mode mode)')
cls.func(nil, 'float getStartSize()')
cls.func(nil, 'void setStartSize(float startSize)')
cls.func(nil, 'float getStartSizeVar()')
cls.func(nil, 'void setStartSizeVar(float sizeVar)')
cls.func(nil, 'float getEndSize()')
cls.func(nil, 'void setEndSize(float endSize)')
cls.func(nil, 'float getEndSizeVar()')
cls.func(nil, 'void setEndSizeVar(float sizeVar)')
cls.func(nil, 'const cocos2d::Color4F &getStartColor()')
cls.func(nil, 'void setStartColor(const cocos2d::Color4F &color)')
cls.func(nil, 'const cocos2d::Color4F &getStartColorVar()')
cls.func(nil, 'void setStartColorVar(const cocos2d::Color4F &color)')
cls.func(nil, 'const cocos2d::Color4F &getEndColor()')
cls.func(nil, 'void setEndColor(const cocos2d::Color4F &color)')
cls.func(nil, 'const cocos2d::Color4F &getEndColorVar()')
cls.func(nil, 'void setEndColorVar(const cocos2d::Color4F &color)')
cls.func(nil, 'float getStartSpin()')
cls.func(nil, 'void setStartSpin(float spin)')
cls.func(nil, 'float getStartSpinVar()')
cls.func(nil, 'void setStartSpinVar(float pinVar)')
cls.func(nil, 'float getEndSpin()')
cls.func(nil, 'void setEndSpin(float endSpin)')
cls.func(nil, 'float getEndSpinVar()')
cls.func(nil, 'void setEndSpinVar(float endSpinVar)')
cls.func(nil, 'float getEmissionRate()')
cls.func(nil, 'void setEmissionRate(float rate)')
cls.func(nil, 'int getTotalParticles()')
cls.func(nil, 'void setTotalParticles(int totalParticles)')
cls.func(nil, 'cocos2d::ParticleSystem::PositionType getPositionType()')
cls.func(nil, 'void setPositionType(cocos2d::ParticleSystem::PositionType type)')
cls.func(nil, 'cocos2d::Texture2D *getTexture()')
cls.func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'const std::string &getResourceFile()')
cls.func(nil, 'void start()')
cls.func(nil, 'void stop()')
cls.func(nil, 'void setSourcePositionCompatible(bool sourcePositionCompatible)')
cls.func(nil, 'bool isSourcePositionCompatible()')
cls.func(nil, 'ParticleSystem()')
cls.func(nil, 'bool initWithFile(const std::string &plistFile)')
cls.func(nil, 'bool initWithDictionary(cocos2d::ValueMap &dictionary)', 'bool initWithDictionary(cocos2d::ValueMap &dictionary, const std::string &dirname)')
cls.func(nil, 'bool initWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'bool isPaused()')
cls.func(nil, 'void pauseEmissions()')
cls.func(nil, 'void resumeEmissions()')
cls.prop('allParticleSystems', nil, nil)
cls.prop('full', nil, nil)
cls.prop('autoRemoveOnFinish', nil, nil)
cls.prop('gravity', nil, nil)
cls.prop('speed', nil, nil)
cls.prop('speedVar', nil, nil)
cls.prop('tangentialAccel', nil, nil)
cls.prop('tangentialAccelVar', nil, nil)
cls.prop('radialAccel', nil, nil)
cls.prop('radialAccelVar', nil, nil)
cls.prop('rotationIsDir', nil, nil)
cls.prop('startRadius', nil, nil)
cls.prop('startRadiusVar', nil, nil)
cls.prop('endRadius', nil, nil)
cls.prop('endRadiusVar', nil, nil)
cls.prop('rotatePerSecond', nil, nil)
cls.prop('rotatePerSecondVar', nil, nil)
cls.prop('active', nil, nil)
cls.prop('blendAdditive', nil, nil)
cls.prop('batchNode', nil, nil)
cls.prop('atlasIndex', nil, nil)
cls.prop('particleCount', nil, nil)
cls.prop('duration', nil, nil)
cls.prop('sourcePosition', nil, nil)
cls.prop('posVar', nil, nil)
cls.prop('life', nil, nil)
cls.prop('lifeVar', nil, nil)
cls.prop('angle', nil, nil)
cls.prop('angleVar', nil, nil)
cls.prop('emitterMode', nil, nil)
cls.prop('startSize', nil, nil)
cls.prop('startSizeVar', nil, nil)
cls.prop('endSize', nil, nil)
cls.prop('endSizeVar', nil, nil)
cls.prop('startColor', nil, nil)
cls.prop('startColorVar', nil, nil)
cls.prop('endColor', nil, nil)
cls.prop('endColorVar', nil, nil)
cls.prop('startSpin', nil, nil)
cls.prop('startSpinVar', nil, nil)
cls.prop('endSpin', nil, nil)
cls.prop('endSpinVar', nil, nil)
cls.prop('emissionRate', nil, nil)
cls.prop('totalParticles', nil, nil)
cls.prop('positionType', nil, nil)
cls.prop('texture', nil, nil)
cls.prop('blendFunc', nil, nil)
cls.prop('resourceFile', nil, nil)
cls.prop('sourcePositionCompatible', nil, nil)
cls.prop('paused', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSystemQuad'
cls.SUPERCLS = 'cocos2d::ParticleSystem'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleSystemQuad *create()', 'static cocos2d::ParticleSystemQuad *create(const std::string &filename)', 'static cocos2d::ParticleSystemQuad *create(cocos2d::ValueMap &dictionary)')
cls.func(nil, 'static cocos2d::ParticleSystemQuad *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'void setDisplayFrame(cocos2d::SpriteFrame *spriteFrame)')
cls.func(nil, 'void setTextureWithRect(cocos2d::Texture2D *texture, const cocos2d::Rect &rect)')
cls.func(nil, 'void listenRendererRecreated(cocos2d::EventCustom *event)')
cls.func(nil, 'ParticleSystemQuad()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleExplosion'
cls.SUPERCLS = 'cocos2d::ParticleSystemQuad'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleExplosion *create()')
cls.func(nil, 'static cocos2d::ParticleExplosion *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'ParticleExplosion()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleFire'
cls.SUPERCLS = 'cocos2d::ParticleSystemQuad'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleFire *create()')
cls.func(nil, 'static cocos2d::ParticleFire *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'ParticleFire()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleFireworks'
cls.SUPERCLS = 'cocos2d::ParticleSystemQuad'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleFireworks *create()')
cls.func(nil, 'static cocos2d::ParticleFireworks *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'ParticleFireworks()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleFlower'
cls.SUPERCLS = 'cocos2d::ParticleSystemQuad'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleFlower *create()')
cls.func(nil, 'static cocos2d::ParticleFlower *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'ParticleFlower()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleGalaxy'
cls.SUPERCLS = 'cocos2d::ParticleSystemQuad'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleGalaxy *create()')
cls.func(nil, 'static cocos2d::ParticleGalaxy *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'ParticleGalaxy()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleMeteor'
cls.SUPERCLS = 'cocos2d::ParticleSystemQuad'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleMeteor *create()')
cls.func(nil, 'static cocos2d::ParticleMeteor *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'ParticleMeteor()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleRain'
cls.SUPERCLS = 'cocos2d::ParticleSystemQuad'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleRain *create()')
cls.func(nil, 'static cocos2d::ParticleRain *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'ParticleRain()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSmoke'
cls.SUPERCLS = 'cocos2d::ParticleSystemQuad'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleSmoke *create()')
cls.func(nil, 'static cocos2d::ParticleSmoke *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'ParticleSmoke()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSnow'
cls.SUPERCLS = 'cocos2d::ParticleSystemQuad'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleSnow *create()')
cls.func(nil, 'static cocos2d::ParticleSnow *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'ParticleSnow()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSpiral'
cls.SUPERCLS = 'cocos2d::ParticleSystemQuad'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleSpiral *create()')
cls.func(nil, 'static cocos2d::ParticleSpiral *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'ParticleSpiral()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ParticleSun'
cls.SUPERCLS = 'cocos2d::ParticleSystemQuad'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ParticleSun *create()')
cls.func(nil, 'static cocos2d::ParticleSun *createWithTotalParticles(int numberOfParticles)')
cls.func(nil, 'ParticleSun()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXTileFlags'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('kTMXTileHorizontalFlag', 'cocos2d::TMXTileFlags::kTMXTileHorizontalFlag')
cls.enum('kTMXTileVerticalFlag', 'cocos2d::TMXTileFlags::kTMXTileVerticalFlag')
cls.enum('kTMXTileDiagonalFlag', 'cocos2d::TMXTileFlags::kTMXTileDiagonalFlag')
cls.enum('kTMXFlipedAll', 'cocos2d::TMXTileFlags::kTMXFlipedAll')
cls.enum('kTMXFlippedMask', 'cocos2d::TMXTileFlags::kTMXFlippedMask')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXObjectGroup'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'TMXObjectGroup()')
cls.func(nil, 'const std::string &getGroupName()')
cls.func(nil, 'void setGroupName(const std::string &groupName)')
cls.func(nil, 'cocos2d::Value getProperty(const std::string &propertyName)')
cls.func(nil, 'cocos2d::ValueMap getObject(const std::string &objectName)')
cls.func(nil, 'const cocos2d::Vec2 &getPositionOffset()')
cls.func(nil, 'void setPositionOffset(const cocos2d::Vec2 &offset)')
cls.func(nil, 'const cocos2d::ValueMap &getProperties()')
cls.func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
cls.func(nil, 'const cocos2d::ValueVector &getObjects()')
cls.func(nil, 'void setObjects(const cocos2d::ValueVector &objects)')
cls.prop('groupName', nil, nil)
cls.prop('positionOffset', nil, nil)
cls.prop('properties', nil, nil)
cls.prop('objects', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXLayer'
cls.SUPERCLS = 'cocos2d::SpriteBatchNode'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TMXLayer *create(cocos2d::TMXTilesetInfo *tilesetInfo, cocos2d::TMXLayerInfo *layerInfo, cocos2d::TMXMapInfo *mapInfo)')
cls.func(nil, 'TMXLayer()')
cls.func(nil, 'bool initWithTilesetInfo(cocos2d::TMXTilesetInfo *tilesetInfo, cocos2d::TMXLayerInfo *layerInfo, cocos2d::TMXMapInfo *mapInfo)')
cls.func(nil, 'void releaseMap()')
cls.func(nil, 'cocos2d::Sprite *getTileAt(const cocos2d::Vec2 &tileCoordinate)')
cls.func(nil, 'uint32_t getTileGIDAt(const cocos2d::Vec2 &tileCoordinate, @out cocos2d::TMXTileFlags *flags)')
cls.func(nil, 'void setTileGID(uint32_t gid, const cocos2d::Vec2 &tileCoordinate)', 'void setTileGID(uint32_t gid, const cocos2d::Vec2 &tileCoordinate, cocos2d::TMXTileFlags flags)')
cls.func(nil, 'void removeTileAt(const cocos2d::Vec2 &tileCoordinate)')
cls.func(nil, 'cocos2d::Vec2 getPositionAt(const cocos2d::Vec2 &tileCoordinate)')
cls.func(nil, 'cocos2d::Value getProperty(const std::string &propertyName)')
cls.func(nil, 'void setupTiles()')
cls.func(nil, 'const std::string &getLayerName()')
cls.func(nil, 'void setLayerName(const std::string &layerName)')
cls.func(nil, 'const cocos2d::Size &getLayerSize()')
cls.func(nil, 'void setLayerSize(const cocos2d::Size &size)')
cls.func(nil, 'const cocos2d::Size &getMapTileSize()')
cls.func(nil, 'void setMapTileSize(const cocos2d::Size &size)')
cls.func(nil, 'cocos2d::TMXTilesetInfo *getTileSet()')
cls.func(nil, 'void setTileSet(cocos2d::TMXTilesetInfo *info)')
cls.func(nil, 'int getLayerOrientation()')
cls.func(nil, 'void setLayerOrientation(int orientation)')
cls.func(nil, 'const cocos2d::ValueMap &getProperties()')
cls.func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
cls.prop('layerName', nil, nil)
cls.prop('layerSize', nil, nil)
cls.prop('mapTileSize', nil, nil)
cls.prop('tileSet', nil, nil)
cls.prop('layerOrientation', nil, nil)
cls.prop('properties', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXLayerInfo'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'TMXLayerInfo()')
cls.func(nil, 'void setProperties(cocos2d::ValueMap properties)')
cls.func(nil, 'cocos2d::ValueMap &getProperties()')
cls.prop('properties', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXMapInfo'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TMXMapInfo *create(const std::string &tmxFile)')
cls.func(nil, 'static cocos2d::TMXMapInfo *createWithXML(const std::string &tmxString, const std::string &resourcePath)')
cls.func(nil, 'TMXMapInfo()')
cls.func(nil, 'bool initWithTMXFile(const std::string &tmxFile)')
cls.func(nil, 'bool initWithXML(const std::string &tmxString, const std::string &resourcePath)')
cls.func(nil, 'bool parseXMLFile(const std::string &xmlFilename)')
cls.func(nil, 'bool parseXMLString(const std::string &xmlString)')
cls.func(nil, 'cocos2d::ValueMapIntKey &getTileProperties()')
cls.func(nil, 'void setTileProperties(const cocos2d::ValueMapIntKey &tileProperties)')
cls.func(nil, 'int getOrientation()')
cls.func(nil, 'void setOrientation(int orientation)')
cls.func(nil, 'int getStaggerAxis()')
cls.func(nil, 'void setStaggerAxis(int staggerAxis)')
cls.func(nil, 'int getStaggerIndex()')
cls.func(nil, 'void setStaggerIndex(int staggerIndex)')
cls.func(nil, 'int getHexSideLength()')
cls.func(nil, 'void setHexSideLength(int hexSideLength)')
cls.func(nil, 'const cocos2d::Size &getMapSize()')
cls.func(nil, 'void setMapSize(const cocos2d::Size &mapSize)')
cls.func(nil, 'const cocos2d::Size &getTileSize()')
cls.func(nil, 'void setTileSize(const cocos2d::Size &tileSize)')
cls.func(nil, 'const Vector<cocos2d::TMXLayerInfo *> &getLayers()')
cls.func(nil, 'void setLayers(const Vector<cocos2d::TMXLayerInfo *> &layers)')
cls.func(nil, 'const Vector<cocos2d::TMXTilesetInfo *> &getTilesets()')
cls.func(nil, 'void setTilesets(const Vector<cocos2d::TMXTilesetInfo *> &tilesets)')
cls.func(nil, 'const Vector<cocos2d::TMXObjectGroup *> &getObjectGroups()')
cls.func(nil, 'void setObjectGroups(const Vector<cocos2d::TMXObjectGroup *> &groups)')
cls.func(nil, 'int getParentElement()')
cls.func(nil, 'void setParentElement(int element)')
cls.func(nil, 'int getParentGID()')
cls.func(nil, 'void setParentGID(int gid)')
cls.func(nil, 'int getLayerAttribs()')
cls.func(nil, 'void setLayerAttribs(int layerAttribs)')
cls.func(nil, 'bool isStoringCharacters()')
cls.func(nil, 'void setStoringCharacters(bool storingCharacters)')
cls.func(nil, 'const cocos2d::ValueMap &getProperties()')
cls.func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
cls.func(nil, 'void endElement(void *ctx, const char *name)')
cls.func(nil, 'void textHandler(void *ctx, const char *ch, size_t len)')
cls.func(nil, 'const std::string &getCurrentString()')
cls.func(nil, 'void setCurrentString(const std::string &currentString)')
cls.func(nil, 'const std::string &getTMXFileName()')
cls.func(nil, 'void setTMXFileName(const std::string &fileName)')
cls.func(nil, 'const std::string &getExternalTilesetFileName()')
cls.prop('tileProperties', nil, nil)
cls.prop('orientation', nil, nil)
cls.prop('staggerAxis', nil, nil)
cls.prop('staggerIndex', nil, nil)
cls.prop('hexSideLength', nil, nil)
cls.prop('mapSize', nil, nil)
cls.prop('tileSize', nil, nil)
cls.prop('layers', nil, nil)
cls.prop('tilesets', nil, nil)
cls.prop('objectGroups', nil, nil)
cls.prop('parentElement', nil, nil)
cls.prop('parentGID', nil, nil)
cls.prop('layerAttribs', nil, nil)
cls.prop('storingCharacters', nil, nil)
cls.prop('properties', nil, nil)
cls.prop('currentString', nil, nil)
cls.prop('tmxFileName', nil, nil)
cls.prop('externalTilesetFileName', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXTilesetInfo'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'TMXTilesetInfo()')
cls.func(nil, 'cocos2d::Rect getRectForGID(uint32_t gid)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TMXTiledMap'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TMXTiledMap *create(const std::string &tmxFile)')
cls.func(nil, 'static cocos2d::TMXTiledMap *createWithXML(const std::string &tmxString, const std::string &resourcePath)')
cls.func(nil, 'cocos2d::TMXLayer *getLayer(const std::string &layerName)')
cls.func(nil, 'cocos2d::TMXObjectGroup *getObjectGroup(const std::string &groupName)')
cls.func(nil, 'cocos2d::Value getProperty(const std::string &propertyName)')
cls.func(nil, 'cocos2d::Value getPropertiesForGID(int GID)')
cls.func(nil, 'const cocos2d::Size &getMapSize()')
cls.func(nil, 'void setMapSize(const cocos2d::Size &mapSize)')
cls.func(nil, 'const cocos2d::Size &getTileSize()')
cls.func(nil, 'void setTileSize(const cocos2d::Size &tileSize)')
cls.func(nil, 'int getMapOrientation()')
cls.func(nil, 'void setMapOrientation(int mapOrientation)')
cls.func(nil, 'const Vector<cocos2d::TMXObjectGroup *> &getObjectGroups()')
cls.func(nil, 'void setObjectGroups(const Vector<cocos2d::TMXObjectGroup *> &groups)')
cls.func(nil, 'cocos2d::ValueMap &getProperties()')
cls.func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
cls.func(nil, 'int getLayerNum()')
cls.func(nil, 'const std::string &getResourceFile()')
cls.func(nil, 'TMXTiledMap()')
cls.func(nil, 'bool initWithTMXFile(const std::string &tmxFile)')
cls.func(nil, 'bool initWithXML(const std::string &tmxString, const std::string &resourcePath)')
cls.prop('mapSize', nil, nil)
cls.prop('tileSize', nil, nil)
cls.prop('mapOrientation', nil, nil)
cls.prop('objectGroups', nil, nil)
cls.prop('properties', nil, nil)
cls.prop('layerNum', nil, nil)
cls.prop('resourceFile', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FastTMXTiledMap'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FastTMXTiledMap *create(const std::string &tmxFile)')
cls.func(nil, 'static cocos2d::FastTMXTiledMap *createWithXML(const std::string &tmxString, const std::string &resourcePath)')
cls.func(nil, 'cocos2d::FastTMXLayer *getLayer(const std::string &layerName)')
cls.func(nil, 'cocos2d::TMXObjectGroup *getObjectGroup(const std::string &groupName)')
cls.func(nil, 'cocos2d::Value getProperty(const std::string &propertyName)')
cls.func(nil, 'cocos2d::Value getPropertiesForGID(int GID)')
cls.func(nil, 'const cocos2d::Size &getMapSize()')
cls.func(nil, 'void setMapSize(const cocos2d::Size &mapSize)')
cls.func(nil, 'const cocos2d::Size &getTileSize()')
cls.func(nil, 'void setTileSize(const cocos2d::Size &tileSize)')
cls.func(nil, 'int getMapOrientation()')
cls.func(nil, 'void setMapOrientation(int mapOrientation)')
cls.func(nil, 'const Vector<cocos2d::TMXObjectGroup *> &getObjectGroups()')
cls.func(nil, 'void setObjectGroups(const Vector<cocos2d::TMXObjectGroup *> &groups)')
cls.func(nil, 'const cocos2d::ValueMap &getProperties()')
cls.func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
cls.prop('mapSize', nil, nil)
cls.prop('tileSize', nil, nil)
cls.prop('mapOrientation', nil, nil)
cls.prop('objectGroups', nil, nil)
cls.prop('properties', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FastTMXLayer'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('FAST_TMX_ORIENTATION_ORTHO', 'cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_ORTHO', 'const int')
cls.const('FAST_TMX_ORIENTATION_HEX', 'cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_HEX', 'const int')
cls.const('FAST_TMX_ORIENTATION_ISO', 'cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_ISO', 'const int')
cls.func(nil, 'static cocos2d::FastTMXLayer *create(cocos2d::TMXTilesetInfo *tilesetInfo, cocos2d::TMXLayerInfo *layerInfo, cocos2d::TMXMapInfo *mapInfo)')
cls.func(nil, 'FastTMXLayer()')
cls.func(nil, 'int getTileGIDAt(const cocos2d::Vec2 &tileCoordinate, @out cocos2d::TMXTileFlags *flags)')
cls.func(nil, 'void setTileGID(int gid, const cocos2d::Vec2 &tileCoordinate)', 'void setTileGID(int gid, const cocos2d::Vec2 &tileCoordinate, cocos2d::TMXTileFlags flags)')
cls.func(nil, 'void removeTileAt(const cocos2d::Vec2 &tileCoordinate)')
cls.func(nil, 'cocos2d::Vec2 getPositionAt(const cocos2d::Vec2 &tileCoordinate)')
cls.func(nil, 'cocos2d::Value getProperty(const std::string &propertyName)')
cls.func(nil, 'void setupTiles()')
cls.func(nil, 'const std::string &getLayerName()')
cls.func(nil, 'void setLayerName(const std::string &layerName)')
cls.func(nil, 'const cocos2d::Size &getLayerSize()')
cls.func(nil, 'void setLayerSize(const cocos2d::Size &size)')
cls.func(nil, 'const cocos2d::Size &getMapTileSize()')
cls.func(nil, 'void setMapTileSize(const cocos2d::Size &size)')
cls.func(nil, 'cocos2d::TMXTilesetInfo *getTileSet()')
cls.func(nil, 'void setTileSet(cocos2d::TMXTilesetInfo *info)')
cls.func(nil, 'int getLayerOrientation()')
cls.func(nil, 'void setLayerOrientation(int orientation)')
cls.func(nil, 'const cocos2d::ValueMap &getProperties()')
cls.func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
cls.func(nil, 'cocos2d::Sprite *getTileAt(const cocos2d::Vec2 &tileCoordinate)')
cls.func(nil, 'void setupTileSprite(cocos2d::Sprite *sprite, const cocos2d::Vec2 &pos, uint32_t gid)')
cls.prop('layerName', nil, nil)
cls.prop('layerSize', nil, nil)
cls.prop('mapTileSize', nil, nil)
cls.prop('tileSet', nil, nil)
cls.prop('layerOrientation', nil, nil)
cls.prop('properties', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NONE')
cls.enum('NODE_TO_AGENT', 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NODE_TO_AGENT')
cls.enum('AGENT_TO_NODE', 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::AGENT_TO_NODE')
cls.enum('NODE_AND_NODE', 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NODE_AND_NODE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NavMeshAgent'
cls.SUPERCLS = 'cocos2d::Component'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::NavMeshAgent *create(const cocos2d::NavMeshAgentParam &param)')
cls.func(nil, 'static const std::string &getNavMeshAgentComponentName()')
cls.func(nil, 'void setRadius(float radius)')
cls.func(nil, 'float getRadius()')
cls.func(nil, 'void setHeight(float height)')
cls.func(nil, 'float getHeight()')
cls.func(nil, 'void setMaxAcceleration(float maxAcceleration)')
cls.func(nil, 'float getMaxAcceleration()')
cls.func(nil, 'void setMaxSpeed(float maxSpeed)')
cls.func(nil, 'float getMaxSpeed()')
cls.func(nil, 'void setSeparationWeight(float weight)')
cls.func(nil, 'float getSeparationWeight()')
cls.func(nil, 'void setObstacleAvoidanceType(unsigned char type)')
cls.func(nil, 'unsigned char getObstacleAvoidanceType()')
cls.func(nil, 'cocos2d::Vec3 getCurrentVelocity()')
cls.func(nil, 'void pause()')
cls.func(nil, 'void resume()')
cls.func(nil, 'void stop()')
cls.func(nil, 'void setOrientationRefAxes(const cocos2d::Vec3 &rotRefAxes)')
cls.func(nil, 'void setAutoOrientation(bool isAuto)')
cls.func(nil, 'void setAutoTraverseOffMeshLink(bool isAuto)')
cls.func(nil, 'bool isOnOffMeshLink()')
cls.func(nil, 'void completeOffMeshLink()')
cls.func(nil, 'cocos2d::OffMeshLinkData getCurrentOffMeshLinkData()')
cls.func(nil, 'void setUserData(void *data)')
cls.func(nil, 'void *getUserData()')
cls.func(nil, 'void setSyncFlag(const cocos2d::NavMeshAgent::NavMeshAgentSyncFlag &flag)')
cls.func(nil, 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag getSyncFlag()')
cls.func(nil, 'void syncToAgent()')
cls.func(nil, 'void syncToNode()')
cls.func(nil, 'cocos2d::Vec3 getVelocity()')
cls.func(nil, 'NavMeshAgent()')
cls.callback {
    FUNCS =  {
        'void move(const cocos2d::Vec3 &destination, @local @optional const std::function<void (NavMeshAgent *, float)> &callback)'
    },
    TAG_MAKER = 'move',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('navMeshAgentComponentName', nil, nil)
cls.prop('radius', nil, nil)
cls.prop('height', nil, nil)
cls.prop('maxAcceleration', nil, nil)
cls.prop('maxSpeed', nil, nil)
cls.prop('separationWeight', nil, nil)
cls.prop('obstacleAvoidanceType', nil, nil)
cls.prop('currentVelocity', nil, nil)
cls.prop('onOffMeshLink', nil, nil)
cls.prop('currentOffMeshLinkData', nil, nil)
cls.prop('userData', nil, nil)
cls.prop('syncFlag', nil, nil)
cls.prop('velocity', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('NONE', 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NONE')
cls.enum('NODE_TO_OBSTACLE', 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NODE_TO_OBSTACLE')
cls.enum('OBSTACLE_TO_NODE', 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::OBSTACLE_TO_NODE')
cls.enum('NODE_AND_NODE', 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NODE_AND_NODE')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NavMeshObstacle'
cls.SUPERCLS = 'cocos2d::Component'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::NavMeshObstacle *create(float radius, float height)')
cls.func(nil, 'static const std::string &getNavMeshObstacleComponentName()')
cls.func(nil, 'void setRadius(float radius)')
cls.func(nil, 'float getRadius()')
cls.func(nil, 'void setHeight(float height)')
cls.func(nil, 'float getHeight()')
cls.func(nil, 'void setSyncFlag(const cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag &flag)')
cls.func(nil, 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag getSyncFlag()')
cls.func(nil, 'void syncToObstacle()')
cls.func(nil, 'void syncToNode()')
cls.func(nil, 'NavMeshObstacle()')
cls.func(nil, 'bool initWith(float radius, float height)')
cls.prop('navMeshObstacleComponentName', nil, nil)
cls.prop('radius', nil, nil)
cls.prop('height', nil, nil)
cls.prop('syncFlag', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NavMesh'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void update(float dt)')
cls.func(nil, 'void debugDraw(cocos2d::Renderer *renderer)')
cls.func(nil, 'void setDebugDrawEnable(bool enable)')
cls.func(nil, 'bool isDebugDrawEnabled()')
cls.func(nil, 'void addNavMeshAgent(cocos2d::NavMeshAgent *agent)')
cls.func(nil, 'void removeNavMeshAgent(cocos2d::NavMeshAgent *agent)')
cls.func(nil, 'void addNavMeshObstacle(cocos2d::NavMeshObstacle *obstacle)')
cls.func(nil, 'void removeNavMeshObstacle(cocos2d::NavMeshObstacle *obstacle)')
cls.func(nil, 'void findPath(const cocos2d::Vec3 &start, const cocos2d::Vec3 &end, std::vector<Vec3> &pathPoints)')
cls.func(nil, 'NavMesh()')
cls.prop('debugDrawEnabled', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

return M
