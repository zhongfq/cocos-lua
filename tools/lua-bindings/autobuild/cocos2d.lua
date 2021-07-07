-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/cocos2d-types.lua"

NAME = "cocos2d"
PATH = "../../frameworks/libxgame/src/lua-bindings"
HEADERS = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "lua-bindings/LuaCocosAdapter.h"
    #include "audio/include/AudioEngine.h"
    #include "cocos2d.h"
    #include "base/TGAlib.h"
    #include "ui/CocosGUI.h"
    #include "navmesh/CCNavMesh.h"
    #include "cclua/xlua.h"
]]
CHUNK = [[
    static const std::string makeScheduleCallbackTag(const std::string &key)
    {
        return "schedule." + key;
    }
]]


typeconf 'cocos2d::RenderTargetFlag'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('COLOR', 'cocos2d::RenderTargetFlag::COLOR')
    .enum('DEPTH', 'cocos2d::RenderTargetFlag::DEPTH')
    .enum('STENCIL', 'cocos2d::RenderTargetFlag::STENCIL')
    .enum('ALL', 'cocos2d::RenderTargetFlag::ALL')

typeconf 'cocos2d::ClearFlag'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NONE', 'cocos2d::ClearFlag::NONE')
    .enum('COLOR', 'cocos2d::ClearFlag::COLOR')
    .enum('DEPTH', 'cocos2d::ClearFlag::DEPTH')
    .enum('STENCIL', 'cocos2d::ClearFlag::STENCIL')
    .enum('ALL', 'cocos2d::ClearFlag::ALL')

typeconf 'cocos2d::MATRIX_STACK_TYPE'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('MATRIX_STACK_MODELVIEW', 'cocos2d::MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW')
    .enum('MATRIX_STACK_PROJECTION', 'cocos2d::MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION')
    .enum('MATRIX_STACK_TEXTURE', 'cocos2d::MATRIX_STACK_TYPE::MATRIX_STACK_TEXTURE')

typeconf 'cocos2d::Director::Projection'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('_2D', 'cocos2d::Director::Projection::_2D')
    .enum('_3D', 'cocos2d::Director::Projection::_3D')
    .enum('CUSTOM', 'cocos2d::Director::Projection::CUSTOM')
    .enum('DEFAULT', 'cocos2d::Director::Projection::DEFAULT')

typeconf 'cocos2d::UserDefault'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'bool getBoolForKey(const char *key)', 'bool getBoolForKey(const char *key, bool defaultValue)')
    .func(nil, 'int getIntegerForKey(const char *key)', 'int getIntegerForKey(const char *key, int defaultValue)')
    .func(nil, 'float getFloatForKey(const char *key)', 'float getFloatForKey(const char *key, float defaultValue)')
    .func(nil, 'double getDoubleForKey(const char *key)', 'double getDoubleForKey(const char *key, double defaultValue)')
    .func(nil, 'std::string getStringForKey(const char *key)', 'std::string getStringForKey(const char *key, const std::string &defaultValue)')
    .func(nil, 'cocos2d::Data getDataForKey(const char *key)', 'cocos2d::Data getDataForKey(const char *key, const cocos2d::Data &defaultValue)')
    .func(nil, 'void setBoolForKey(const char *key, bool value)')
    .func(nil, 'void setIntegerForKey(const char *key, int value)')
    .func(nil, 'void setFloatForKey(const char *key, float value)')
    .func(nil, 'void setDoubleForKey(const char *key, double value)')
    .func(nil, 'void setStringForKey(const char *key, const std::string &value)')
    .func(nil, 'void setDataForKey(const char *key, const cocos2d::Data &value)')
    .func(nil, 'void flush()')
    .func(nil, 'void deleteValueForKey(const char *key)')
    .func(nil, 'static cocos2d::UserDefault *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'static const std::string &getXMLFilePath()')
    .func(nil, 'static bool isXMLFileExist()')
    .prop('instance', nil, nil)
    .prop('xmlFilePath', nil, nil)
    .prop('xmlFileExist', nil, nil)

typeconf 'cocos2d::Ref'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func('__gc', [[
        {
            return xlua_ccobjgc(L);
        }
    ]])
    .func(nil, 'unsigned int getReferenceCount()')
    .prop('referenceCount', nil, nil)

typeconf 'cocos2d::Console'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'Console()')
    .func(nil, 'bool listenOnTCP(int port)')
    .func(nil, 'bool listenOnFileDescriptor(int fd)')
    .func(nil, 'void stop()')
    .func(nil, 'void delCommand(const std::string &cmdName)')
    .func(nil, 'void delSubCommand(const std::string &cmdName, const std::string &subCmdName)')
    .func(nil, 'void log(const char *buf)')
    .func(nil, 'void setBindAddress(const std::string &address)')
    .func(nil, 'bool isIpv6Server()')
    .func(nil, 'char getCommandSeparator()')
    .func(nil, 'void setCommandSeparator(char var)')
    .prop('ipv6Server', nil, nil)
    .prop('commandSeparator', nil, nil)

typeconf 'cocos2d::Acceleration'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .var('x', '@optional double x')
    .var('y', '@optional double y')
    .var('z', '@optional double z')
    .var('timestamp', '@optional double timestamp')

typeconf 'cocos2d::Director'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Director *getInstance()')
    .func(nil, 'Director()')
    .func(nil, 'bool init()')
    .func(nil, '@addref(scenes |) cocos2d::Scene *getRunningScene()')
    .func(nil, 'float getAnimationInterval()')
    .func(nil, 'void setAnimationInterval(float interval)')
    .func(nil, 'bool isDisplayStats()')
    .func(nil, 'void setDisplayStats(bool displayStats)')
    .func(nil, 'float getSecondsPerFrame()')
    .func(nil, '@addref(openGLView ^) cocos2d::GLView *getOpenGLView()')
    .func(nil, 'void setOpenGLView(@addref(openGLView ^) cocos2d::GLView *openGLView)')
    .func(nil, '@addref(textureCache ^) cocos2d::TextureCache *getTextureCache()')
    .func(nil, 'bool isNextDeltaTimeZero()')
    .func(nil, 'void setNextDeltaTimeZero(bool nextDeltaTimeZero)')
    .func(nil, 'bool isPaused()')
    .func(nil, 'unsigned int getTotalFrames()')
    .func(nil, 'cocos2d::Director::Projection getProjection()')
    .func(nil, 'void setProjection(cocos2d::Director::Projection projection)')
    .func(nil, 'void setViewport()')
    .func(nil, 'bool isSendCleanupToScene()')
    .func(nil, '@addref(notificationNode ^) cocos2d::Node *getNotificationNode()')
    .func(nil, 'void setNotificationNode(@addref(notificationNode ^) cocos2d::Node *node)')
    .func(nil, 'const cocos2d::Size &getWinSize()')
    .func(nil, 'cocos2d::Size getWinSizeInPixels()')
    .func(nil, 'cocos2d::Size getVisibleSize()')
    .func(nil, 'cocos2d::Vec2 getVisibleOrigin()')
    .func(nil, 'cocos2d::Rect getSafeAreaRect()')
    .func(nil, 'cocos2d::Vec2 convertToGL(@pack const cocos2d::Vec2 &point)')
    .func(nil, 'cocos2d::Vec2 convertToUI(@pack const cocos2d::Vec2 &point)')
    .func(nil, 'float getZEye()')
    .func(nil, 'void runWithScene(@addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'void pushScene(@addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, '@delref(scenes ~) void popScene()')
    .func(nil, '@delref(scenes ~) void popToRootScene()')
    .func(nil, '@delref(scenes ~) void popToSceneStackLevel(int level)')
    .func(nil, '@delref(scenes ~) void replaceScene(@addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'void end()')
    .func(nil, 'void pause()')
    .func(nil, 'void resume()')
    .func(nil, 'void restart()')
    .func(nil, 'void stopAnimation()')
    .func(nil, 'void startAnimation()')
    .func(nil, 'void drawScene()')
    .func(nil, 'void purgeCachedData()')
    .func(nil, 'void setDefaultValues()')
    .func(nil, 'void setGLDefaultValues()')
    .func(nil, 'void setClearColor(const cocos2d::Color4F &clearColor)')
    .func(nil, 'void mainLoop()', 'void mainLoop(float dt)')
    .func(nil, 'void setContentScaleFactor(float scaleFactor)')
    .func(nil, 'float getContentScaleFactor()')
    .func(nil, '@addref(scheduler ^) cocos2d::Scheduler *getScheduler()')
    .func(nil, 'void setScheduler(@addref(scheduler ^) cocos2d::Scheduler *scheduler)')
    .func(nil, '@addref(actionManager ^) cocos2d::ActionManager *getActionManager()')
    .func(nil, 'void setActionManager(@addref(actionManager ^) cocos2d::ActionManager *actionManager)')
    .func(nil, '@addref(eventDispatcher ^) cocos2d::EventDispatcher *getEventDispatcher()')
    .func(nil, 'void setEventDispatcher(@addref(eventDispatcher ^) cocos2d::EventDispatcher *dispatcher)')
    .func(nil, '@addref(renderer ^) cocos2d::Renderer *getRenderer()')
    .func(nil, 'cocos2d::Console *getConsole()')
    .func(nil, 'float getDeltaTime()')
    .func(nil, 'float getFrameRate()')
    .func(nil, 'void pushMatrix(cocos2d::MATRIX_STACK_TYPE type)')
    .func(nil, 'void popMatrix(cocos2d::MATRIX_STACK_TYPE type)')
    .func(nil, 'void loadIdentityMatrix(cocos2d::MATRIX_STACK_TYPE type)')
    .func(nil, 'void loadMatrix(cocos2d::MATRIX_STACK_TYPE type, const cocos2d::Mat4 &mat)')
    .func(nil, 'void multiplyMatrix(cocos2d::MATRIX_STACK_TYPE type, const cocos2d::Mat4 &mat)')
    .func(nil, 'const cocos2d::Mat4 &getMatrix(cocos2d::MATRIX_STACK_TYPE type)')
    .func(nil, 'void resetMatrixStack()')
    .func(nil, 'bool isValid()')
    .var('EVENT_BEFORE_SET_NEXT_SCENE', 'static const char *EVENT_BEFORE_SET_NEXT_SCENE')
    .var('EVENT_AFTER_SET_NEXT_SCENE', 'static const char *EVENT_AFTER_SET_NEXT_SCENE')
    .var('EVENT_PROJECTION_CHANGED', 'static const char *EVENT_PROJECTION_CHANGED')
    .var('EVENT_BEFORE_UPDATE', 'static const char *EVENT_BEFORE_UPDATE')
    .var('EVENT_AFTER_UPDATE', 'static const char *EVENT_AFTER_UPDATE')
    .var('EVENT_RESET', 'static const char *EVENT_RESET')
    .var('EVENT_AFTER_VISIT', 'static const char *EVENT_AFTER_VISIT')
    .var('EVENT_AFTER_DRAW', 'static const char *EVENT_AFTER_DRAW')
    .var('EVENT_BEFORE_DRAW', 'static const char *EVENT_BEFORE_DRAW')
    .prop('instance', nil, nil)
    .prop('runningScene', nil, nil)
    .prop('animationInterval', nil, nil)
    .prop('displayStats', nil, nil)
    .prop('secondsPerFrame', nil, nil)
    .prop('openGLView', nil, nil)
    .prop('textureCache', nil, nil)
    .prop('nextDeltaTimeZero', nil, nil)
    .prop('paused', nil, nil)
    .prop('totalFrames', nil, nil)
    .prop('projection', nil, nil)
    .prop('sendCleanupToScene', nil, nil)
    .prop('notificationNode', nil, nil)
    .prop('winSize', nil, nil)
    .prop('winSizeInPixels', nil, nil)
    .prop('visibleSize', nil, nil)
    .prop('visibleOrigin', nil, nil)
    .prop('safeAreaRect', nil, nil)
    .prop('zEye', nil, nil)
    .prop('contentScaleFactor', nil, nil)
    .prop('scheduler', nil, nil)
    .prop('actionManager', nil, nil)
    .prop('eventDispatcher', nil, nil)
    .prop('renderer', nil, nil)
    .prop('console', nil, nil)
    .prop('deltaTime', nil, nil)
    .prop('frameRate', nil, nil)
    .prop('valid', nil, nil)
    .alias('end', 'exit')

typeconf 'cocos2d::ccSchedulerFunc'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::Scheduler'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk([[
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
    ]])
    .require(nil)
    .const('PRIORITY_SYSTEM', 'cocos2d::Scheduler::PRIORITY_SYSTEM', 'const int')
    .const('PRIORITY_NON_SYSTEM_MIN', 'cocos2d::Scheduler::PRIORITY_NON_SYSTEM_MIN', 'const int')
    .func('scheduleUpdate', [[
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
    .func(nil, 'Scheduler()')
    .func(nil, 'float getTimeScale()')
    .func(nil, 'void setTimeScale(float timeScale)')
    .func(nil, 'void update(float dt)')
    .func(nil, 'void unscheduleUpdate(void *target)')
    .func(nil, 'void unscheduleAllWithMinPriority(int minPriority)')
    .func(nil, 'bool isScheduled(const std::string &key, const void *target)')
    .func(nil, 'void pauseTarget(void *target)')
    .func(nil, 'void resumeTarget(void *target)')
    .func(nil, 'bool isTargetPaused(void *target)')
    .func(nil, 'std::set<void *> pauseAllTargets()')
    .func(nil, 'std::set<void *> pauseAllTargetsWithMinPriority(int minPriority)')
    .func(nil, 'void resumeTargets(const std::set<void *> &targetsToResume)')
    .func(nil, 'void removeAllFunctionsToBePerformedInCocosThread()')
    .callback {
        FUNCS =  {
            'void schedule(@local const cocos2d::ccSchedulerFunc &callback, void *target, float interval, unsigned int repeat, float delay, bool paused, const std::string &key)',
            'void schedule(@local const cocos2d::ccSchedulerFunc &callback, void *target, float interval, bool paused, const std::string &key)'
        },
        TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = 2,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void unschedule(const std::string &key, void *target)'
        },
        TAG_MAKER = 'makeScheduleCallbackTag(#1)',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        TAG_STORE = 2,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void unscheduleAllForTarget(void *target)'
        },
        TAG_MAKER = 'makeScheduleCallbackTag("")',
        TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
        TAG_STORE = 1,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void unscheduleAll()'
        },
        TAG_MAKER = 'makeScheduleCallbackTag("")',
        TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .prop('timeScale', nil, nil)

typeconf 'cocos2d::EventDispatcher'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk([[
        static int _cocos2d_EventDispatcher_addEventListenerWithFixedPriority(lua_State *L);

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
    ]])
    .require(nil)
    .func('addEventListener', [[
        {
            lua_settop(L, 2);
            olua_push_int(L, 1);
            return _cocos2d_EventDispatcher_addEventListenerWithFixedPriority(L);
        }
    ]])
    .func(nil, 'void addEventListenerWithSceneGraphPriority(@addref(listeners | 3) cocos2d::EventListener *listener, cocos2d::Node *node)')
    .func(nil, 'void addEventListenerWithFixedPriority(@addref(listeners |) cocos2d::EventListener *listener, int fixedPriority)')
    .func(nil, '@delref(listeners ~) void removeEventListener(@delref(listeners |) cocos2d::EventListener *listener)')
    .func(nil, '@delref(listeners ~) void removeEventListenersForType(cocos2d::EventListener::Type listenerType)')
    .func(nil, 'void removeEventListenersForTarget(cocos2d::Node *target, @optional bool recursive)')
    .func(nil, '@delref(listeners ~) void removeCustomEventListeners(const std::string &customEventName)')
    .func(nil, '@delref(listeners ~) void removeAllEventListeners()')
    .func(nil, 'void pauseEventListenersForTarget(cocos2d::Node *target, @optional bool recursive)')
    .func(nil, 'void resumeEventListenersForTarget(cocos2d::Node *target, @optional bool recursive)')
    .func(nil, 'void setPriority(cocos2d::EventListener *listener, int fixedPriority)')
    .func(nil, 'void setEnabled(bool isEnabled)')
    .func(nil, 'bool isEnabled()')
    .func(nil, 'void dispatchEvent(cocos2d::Event *event)')
    .func(nil, 'void dispatchCustomEvent(const std::string &eventName, @optional void *optionalUserData)')
    .func(nil, 'bool hasEventListener(const cocos2d::EventListener::ListenerID &listenerID)')
    .func(nil, 'EventDispatcher()')
    .callback {
        FUNCS =  {
            '@addref(listeners |) cocos2d::EventListenerCustom *addCustomEventListener(const std::string &eventName, @local const std::function<void (EventCustom *)> &callback)'
        },
        TAG_MAKER = '(#1)',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = "return",
        TAG_SCOPE = 'object',
    }
    .prop('enabled', nil, nil)
    .insert('removeEventListenersForTarget', {
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

typeconf 'cocos2d::EventListener::Type'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('UNKNOWN', 'cocos2d::EventListener::Type::UNKNOWN')
    .enum('TOUCH_ONE_BY_ONE', 'cocos2d::EventListener::Type::TOUCH_ONE_BY_ONE')
    .enum('TOUCH_ALL_AT_ONCE', 'cocos2d::EventListener::Type::TOUCH_ALL_AT_ONCE')
    .enum('KEYBOARD', 'cocos2d::EventListener::Type::KEYBOARD')
    .enum('MOUSE', 'cocos2d::EventListener::Type::MOUSE')
    .enum('ACCELERATION', 'cocos2d::EventListener::Type::ACCELERATION')
    .enum('FOCUS', 'cocos2d::EventListener::Type::FOCUS')
    .enum('GAME_CONTROLLER', 'cocos2d::EventListener::Type::GAME_CONTROLLER')
    .enum('CUSTOM', 'cocos2d::EventListener::Type::CUSTOM')

typeconf 'cocos2d::EventListener'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'bool checkAvailable()')
    .func(nil, 'cocos2d::EventListener *clone()')
    .func(nil, 'void setEnabled(bool enabled)')
    .func(nil, 'bool isEnabled()')
    .prop('available', 'bool checkAvailable()', nil)
    .prop('enabled', nil, nil)

typeconf 'cocos2d::EventListenerTouchOneByOne::ccTouchBeganCallback'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::EventListenerTouchOneByOne::ccTouchCallback'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::EventListenerTouchOneByOne'
    .supercls('cocos2d::EventListener')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('LISTENER_ID', 'cocos2d::EventListenerTouchOneByOne::LISTENER_ID', 'const std::string')
    .func(nil, 'static cocos2d::EventListenerTouchOneByOne *create()')
    .func(nil, 'void setSwallowTouches(bool needSwallow)')
    .func(nil, 'bool isSwallowTouches()')
    .func(nil, 'EventListenerTouchOneByOne()')
    .var('onTouchBegan', '@nullable @local cocos2d::EventListenerTouchOneByOne::ccTouchBeganCallback onTouchBegan')
    .var('onTouchMoved', '@nullable @local cocos2d::EventListenerTouchOneByOne::ccTouchCallback onTouchMoved')
    .var('onTouchEnded', '@nullable @local cocos2d::EventListenerTouchOneByOne::ccTouchCallback onTouchEnded')
    .var('onTouchCancelled', '@nullable @local cocos2d::EventListenerTouchOneByOne::ccTouchCallback onTouchCancelled')
    .prop('swallowTouches', nil, nil)

typeconf 'cocos2d::EventListenerTouchAllAtOnce::ccTouchesCallback'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::EventListenerTouchAllAtOnce'
    .supercls('cocos2d::EventListener')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('LISTENER_ID', 'cocos2d::EventListenerTouchAllAtOnce::LISTENER_ID', 'const std::string')
    .func(nil, 'static cocos2d::EventListenerTouchAllAtOnce *create()')
    .func(nil, 'EventListenerTouchAllAtOnce()')
    .var('onTouchesBegan', '@nullable @local cocos2d::EventListenerTouchAllAtOnce::ccTouchesCallback onTouchesBegan')
    .var('onTouchesMoved', '@nullable @local cocos2d::EventListenerTouchAllAtOnce::ccTouchesCallback onTouchesMoved')
    .var('onTouchesEnded', '@nullable @local cocos2d::EventListenerTouchAllAtOnce::ccTouchesCallback onTouchesEnded')
    .var('onTouchesCancelled', '@nullable @local cocos2d::EventListenerTouchAllAtOnce::ccTouchesCallback onTouchesCancelled')

typeconf 'cocos2d::EventListenerCustom'
    .supercls('cocos2d::EventListener')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'EventListenerCustom()')
    .callback {
        FUNCS =  {
            'static cocos2d::EventListenerCustom *create(const std::string &eventName, @local const std::function<void (EventCustom *)> &callback)'
        },
        TAG_MAKER = 'listener',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = "return",
        TAG_SCOPE = 'object',
    }

typeconf 'cocos2d::EventListenerKeyboard'
    .supercls('cocos2d::EventListener')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('LISTENER_ID', 'cocos2d::EventListenerKeyboard::LISTENER_ID', 'const std::string')
    .func(nil, 'static cocos2d::EventListenerKeyboard *create()')
    .func(nil, 'EventListenerKeyboard()')
    .var('onKeyPressed', '@nullable @local std::function<void (EventKeyboard::KeyCode, cocos2d::Event *)> onKeyPressed')
    .var('onKeyReleased', '@nullable @local std::function<void (EventKeyboard::KeyCode, cocos2d::Event *)> onKeyReleased')

typeconf 'cocos2d::EventListenerAcceleration'
    .supercls('cocos2d::EventListener')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('LISTENER_ID', 'cocos2d::EventListenerAcceleration::LISTENER_ID', 'const std::string')
    .func(nil, 'EventListenerAcceleration()')
    .callback {
        FUNCS =  {
            'static cocos2d::EventListenerAcceleration *create(@local const std::function<void (Acceleration *, Event *)> &callback)'
        },
        TAG_MAKER = 'listener',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = "return",
        TAG_SCOPE = 'object',
    }

typeconf 'cocos2d::EventListenerFocus'
    .supercls('cocos2d::EventListener')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('LISTENER_ID', 'cocos2d::EventListenerFocus::LISTENER_ID', 'const std::string')
    .func(nil, 'static cocos2d::EventListenerFocus *create()')
    .func(nil, 'EventListenerFocus()')
    .var('onFocusChanged', '@nullable @local std::function<void (ui::Widget *, ui::Widget *)> onFocusChanged')

typeconf 'cocos2d::EventListenerMouse'
    .supercls('cocos2d::EventListener')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('LISTENER_ID', 'cocos2d::EventListenerMouse::LISTENER_ID', 'const std::string')
    .func(nil, 'static cocos2d::EventListenerMouse *create()')
    .func(nil, 'EventListenerMouse()')
    .var('onMouseDown', '@nullable @local std::function<void (cocos2d::EventMouse *)> onMouseDown')
    .var('onMouseUp', '@nullable @local std::function<void (cocos2d::EventMouse *)> onMouseUp')
    .var('onMouseMove', '@nullable @local std::function<void (cocos2d::EventMouse *)> onMouseMove')
    .var('onMouseScroll', '@nullable @local std::function<void (cocos2d::EventMouse *)> onMouseScroll')

typeconf 'cocos2d::Event::Type'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('TOUCH', 'cocos2d::Event::Type::TOUCH')
    .enum('KEYBOARD', 'cocos2d::Event::Type::KEYBOARD')
    .enum('ACCELERATION', 'cocos2d::Event::Type::ACCELERATION')
    .enum('MOUSE', 'cocos2d::Event::Type::MOUSE')
    .enum('FOCUS', 'cocos2d::Event::Type::FOCUS')
    .enum('GAME_CONTROLLER', 'cocos2d::Event::Type::GAME_CONTROLLER')
    .enum('CUSTOM', 'cocos2d::Event::Type::CUSTOM')

typeconf 'cocos2d::Event'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'Event(cocos2d::Event::Type type)')
    .func(nil, 'cocos2d::Event::Type getType()')
    .func(nil, 'void stopPropagation()')
    .func(nil, 'bool isStopped()')
    .func(nil, 'cocos2d::Node *getCurrentTarget()')
    .prop('type', nil, nil)
    .prop('stopped', nil, nil)
    .prop('currentTarget', nil, nil)

typeconf 'cocos2d::EventCustom'
    .supercls('cocos2d::Event')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'EventCustom(const std::string &eventName)')
    .func(nil, 'void setUserData(void *data)')
    .func(nil, 'void *getUserData()')
    .func(nil, 'const std::string &getEventName()')
    .prop('userData', nil, nil)
    .prop('eventName', nil, nil)

typeconf 'cocos2d::EventListenerController'
    .supercls('cocos2d::EventListener')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('LISTENER_ID', 'cocos2d::EventListenerController::LISTENER_ID', 'const std::string')
    .func(nil, 'static cocos2d::EventListenerController *create()')
    .var('onConnected', '@nullable @local std::function<void (cocos2d::Controller *, cocos2d::Event *)> onConnected')
    .var('onDisconnected', '@nullable @local std::function<void (cocos2d::Controller *, cocos2d::Event *)> onDisconnected')
    .var('onKeyDown', '@nullable @local std::function<void (cocos2d::Controller *, int, cocos2d::Event *)> onKeyDown')
    .var('onKeyUp', '@nullable @local std::function<void (cocos2d::Controller *, int, cocos2d::Event *)> onKeyUp')
    .var('onKeyRepeat', '@nullable @local std::function<void (cocos2d::Controller *, int, cocos2d::Event *)> onKeyRepeat')
    .var('onAxisEvent', '@nullable @local std::function<void (cocos2d::Controller *, int, cocos2d::Event *)> onAxisEvent')

typeconf 'cocos2d::EventTouch::EventCode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('BEGAN', 'cocos2d::EventTouch::EventCode::BEGAN')
    .enum('MOVED', 'cocos2d::EventTouch::EventCode::MOVED')
    .enum('ENDED', 'cocos2d::EventTouch::EventCode::ENDED')
    .enum('CANCELLED', 'cocos2d::EventTouch::EventCode::CANCELLED')

typeconf 'cocos2d::EventTouch'
    .supercls('cocos2d::Event')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('MAX_TOUCHES', 'cocos2d::EventTouch::MAX_TOUCHES', 'const int')
    .func(nil, 'EventTouch()')
    .func(nil, 'cocos2d::EventTouch::EventCode getEventCode()')
    .func(nil, 'const std::vector<Touch *> &getTouches()')
    .func(nil, 'void setEventCode(cocos2d::EventTouch::EventCode eventCode)')
    .func(nil, 'void setTouches(const std::vector<Touch *> &touches)')
    .prop('eventCode', nil, nil)
    .prop('touches', nil, nil)

typeconf 'cocos2d::EventKeyboard'
    .supercls('cocos2d::Event')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'EventKeyboard(cocos2d::EventKeyboard::KeyCode keyCode, bool isPressed)')

typeconf 'cocos2d::EventAcceleration'
    .supercls('cocos2d::Event')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::EventFocus'
    .supercls('cocos2d::Event')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'EventFocus(cocos2d::ui::Widget *widgetLoseFocus, cocos2d::ui::Widget *widgetGetFocus)')

typeconf 'cocos2d::EventMouse::MouseEventType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('MOUSE_NONE', 'cocos2d::EventMouse::MouseEventType::MOUSE_NONE')
    .enum('MOUSE_DOWN', 'cocos2d::EventMouse::MouseEventType::MOUSE_DOWN')
    .enum('MOUSE_UP', 'cocos2d::EventMouse::MouseEventType::MOUSE_UP')
    .enum('MOUSE_MOVE', 'cocos2d::EventMouse::MouseEventType::MOUSE_MOVE')
    .enum('MOUSE_SCROLL', 'cocos2d::EventMouse::MouseEventType::MOUSE_SCROLL')

typeconf 'cocos2d::EventMouse::MouseButton'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('BUTTON_UNSET', 'cocos2d::EventMouse::MouseButton::BUTTON_UNSET')
    .enum('BUTTON_LEFT', 'cocos2d::EventMouse::MouseButton::BUTTON_LEFT')
    .enum('BUTTON_RIGHT', 'cocos2d::EventMouse::MouseButton::BUTTON_RIGHT')
    .enum('BUTTON_MIDDLE', 'cocos2d::EventMouse::MouseButton::BUTTON_MIDDLE')
    .enum('BUTTON_4', 'cocos2d::EventMouse::MouseButton::BUTTON_4')
    .enum('BUTTON_5', 'cocos2d::EventMouse::MouseButton::BUTTON_5')
    .enum('BUTTON_6', 'cocos2d::EventMouse::MouseButton::BUTTON_6')
    .enum('BUTTON_7', 'cocos2d::EventMouse::MouseButton::BUTTON_7')
    .enum('BUTTON_8', 'cocos2d::EventMouse::MouseButton::BUTTON_8')

typeconf 'cocos2d::EventMouse'
    .supercls('cocos2d::Event')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'EventMouse(cocos2d::EventMouse::MouseEventType mouseEventCode)')
    .func(nil, 'void setScrollData(float scrollX, float scrollY)')
    .func(nil, 'float getScrollX()')
    .func(nil, 'float getScrollY()')
    .func(nil, 'void setCursorPosition(float x, float y)')
    .func(nil, 'void setMouseButton(cocos2d::EventMouse::MouseButton button)')
    .func(nil, 'cocos2d::EventMouse::MouseButton getMouseButton()')
    .func(nil, 'float getCursorX()')
    .func(nil, 'float getCursorY()')
    .func(nil, 'cocos2d::Vec2 getLocation()')
    .func(nil, 'cocos2d::Vec2 getPreviousLocation()')
    .func(nil, 'cocos2d::Vec2 getStartLocation()')
    .func(nil, 'cocos2d::Vec2 getDelta()')
    .func(nil, 'cocos2d::Vec2 getLocationInView()')
    .func(nil, 'cocos2d::Vec2 getPreviousLocationInView()')
    .func(nil, 'cocos2d::Vec2 getStartLocationInView()')
    .prop('scrollX', nil, nil)
    .prop('scrollY', nil, nil)
    .prop('mouseButton', nil, nil)
    .prop('cursorX', nil, nil)
    .prop('cursorY', nil, nil)
    .prop('location', nil, nil)
    .prop('previousLocation', nil, nil)
    .prop('startLocation', nil, nil)
    .prop('delta', nil, nil)
    .prop('locationInView', nil, nil)
    .prop('previousLocationInView', nil, nil)
    .prop('startLocationInView', nil, nil)

typeconf 'cocos2d::EventKeyboard::KeyCode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('KEY_NONE', 'cocos2d::EventKeyboard::KeyCode::KEY_NONE')
    .enum('KEY_PAUSE', 'cocos2d::EventKeyboard::KeyCode::KEY_PAUSE')
    .enum('KEY_SCROLL_LOCK', 'cocos2d::EventKeyboard::KeyCode::KEY_SCROLL_LOCK')
    .enum('KEY_PRINT', 'cocos2d::EventKeyboard::KeyCode::KEY_PRINT')
    .enum('KEY_SYSREQ', 'cocos2d::EventKeyboard::KeyCode::KEY_SYSREQ')
    .enum('KEY_BREAK', 'cocos2d::EventKeyboard::KeyCode::KEY_BREAK')
    .enum('KEY_ESCAPE', 'cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE')
    .enum('KEY_BACK', 'cocos2d::EventKeyboard::KeyCode::KEY_BACK')
    .enum('KEY_BACKSPACE', 'cocos2d::EventKeyboard::KeyCode::KEY_BACKSPACE')
    .enum('KEY_TAB', 'cocos2d::EventKeyboard::KeyCode::KEY_TAB')
    .enum('KEY_BACK_TAB', 'cocos2d::EventKeyboard::KeyCode::KEY_BACK_TAB')
    .enum('KEY_RETURN', 'cocos2d::EventKeyboard::KeyCode::KEY_RETURN')
    .enum('KEY_CAPS_LOCK', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPS_LOCK')
    .enum('KEY_SHIFT', 'cocos2d::EventKeyboard::KeyCode::KEY_SHIFT')
    .enum('KEY_LEFT_SHIFT', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_SHIFT')
    .enum('KEY_RIGHT_SHIFT', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_SHIFT')
    .enum('KEY_CTRL', 'cocos2d::EventKeyboard::KeyCode::KEY_CTRL')
    .enum('KEY_LEFT_CTRL', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_CTRL')
    .enum('KEY_RIGHT_CTRL', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_CTRL')
    .enum('KEY_ALT', 'cocos2d::EventKeyboard::KeyCode::KEY_ALT')
    .enum('KEY_LEFT_ALT', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ALT')
    .enum('KEY_RIGHT_ALT', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ALT')
    .enum('KEY_MENU', 'cocos2d::EventKeyboard::KeyCode::KEY_MENU')
    .enum('KEY_HYPER', 'cocos2d::EventKeyboard::KeyCode::KEY_HYPER')
    .enum('KEY_INSERT', 'cocos2d::EventKeyboard::KeyCode::KEY_INSERT')
    .enum('KEY_HOME', 'cocos2d::EventKeyboard::KeyCode::KEY_HOME')
    .enum('KEY_PG_UP', 'cocos2d::EventKeyboard::KeyCode::KEY_PG_UP')
    .enum('KEY_DELETE', 'cocos2d::EventKeyboard::KeyCode::KEY_DELETE')
    .enum('KEY_END', 'cocos2d::EventKeyboard::KeyCode::KEY_END')
    .enum('KEY_PG_DOWN', 'cocos2d::EventKeyboard::KeyCode::KEY_PG_DOWN')
    .enum('KEY_LEFT_ARROW', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW')
    .enum('KEY_RIGHT_ARROW', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW')
    .enum('KEY_UP_ARROW', 'cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW')
    .enum('KEY_DOWN_ARROW', 'cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW')
    .enum('KEY_NUM_LOCK', 'cocos2d::EventKeyboard::KeyCode::KEY_NUM_LOCK')
    .enum('KEY_KP_PLUS', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_PLUS')
    .enum('KEY_KP_MINUS', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_MINUS')
    .enum('KEY_KP_MULTIPLY', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_MULTIPLY')
    .enum('KEY_KP_DIVIDE', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_DIVIDE')
    .enum('KEY_KP_ENTER', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_ENTER')
    .enum('KEY_KP_HOME', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_HOME')
    .enum('KEY_KP_UP', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_UP')
    .enum('KEY_KP_PG_UP', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_PG_UP')
    .enum('KEY_KP_LEFT', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_LEFT')
    .enum('KEY_KP_FIVE', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_FIVE')
    .enum('KEY_KP_RIGHT', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_RIGHT')
    .enum('KEY_KP_END', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_END')
    .enum('KEY_KP_DOWN', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_DOWN')
    .enum('KEY_KP_PG_DOWN', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_PG_DOWN')
    .enum('KEY_KP_INSERT', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_INSERT')
    .enum('KEY_KP_DELETE', 'cocos2d::EventKeyboard::KeyCode::KEY_KP_DELETE')
    .enum('KEY_F1', 'cocos2d::EventKeyboard::KeyCode::KEY_F1')
    .enum('KEY_F2', 'cocos2d::EventKeyboard::KeyCode::KEY_F2')
    .enum('KEY_F3', 'cocos2d::EventKeyboard::KeyCode::KEY_F3')
    .enum('KEY_F4', 'cocos2d::EventKeyboard::KeyCode::KEY_F4')
    .enum('KEY_F5', 'cocos2d::EventKeyboard::KeyCode::KEY_F5')
    .enum('KEY_F6', 'cocos2d::EventKeyboard::KeyCode::KEY_F6')
    .enum('KEY_F7', 'cocos2d::EventKeyboard::KeyCode::KEY_F7')
    .enum('KEY_F8', 'cocos2d::EventKeyboard::KeyCode::KEY_F8')
    .enum('KEY_F9', 'cocos2d::EventKeyboard::KeyCode::KEY_F9')
    .enum('KEY_F10', 'cocos2d::EventKeyboard::KeyCode::KEY_F10')
    .enum('KEY_F11', 'cocos2d::EventKeyboard::KeyCode::KEY_F11')
    .enum('KEY_F12', 'cocos2d::EventKeyboard::KeyCode::KEY_F12')
    .enum('KEY_SPACE', 'cocos2d::EventKeyboard::KeyCode::KEY_SPACE')
    .enum('KEY_EXCLAM', 'cocos2d::EventKeyboard::KeyCode::KEY_EXCLAM')
    .enum('KEY_QUOTE', 'cocos2d::EventKeyboard::KeyCode::KEY_QUOTE')
    .enum('KEY_NUMBER', 'cocos2d::EventKeyboard::KeyCode::KEY_NUMBER')
    .enum('KEY_DOLLAR', 'cocos2d::EventKeyboard::KeyCode::KEY_DOLLAR')
    .enum('KEY_PERCENT', 'cocos2d::EventKeyboard::KeyCode::KEY_PERCENT')
    .enum('KEY_CIRCUMFLEX', 'cocos2d::EventKeyboard::KeyCode::KEY_CIRCUMFLEX')
    .enum('KEY_AMPERSAND', 'cocos2d::EventKeyboard::KeyCode::KEY_AMPERSAND')
    .enum('KEY_APOSTROPHE', 'cocos2d::EventKeyboard::KeyCode::KEY_APOSTROPHE')
    .enum('KEY_LEFT_PARENTHESIS', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_PARENTHESIS')
    .enum('KEY_RIGHT_PARENTHESIS', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_PARENTHESIS')
    .enum('KEY_ASTERISK', 'cocos2d::EventKeyboard::KeyCode::KEY_ASTERISK')
    .enum('KEY_PLUS', 'cocos2d::EventKeyboard::KeyCode::KEY_PLUS')
    .enum('KEY_COMMA', 'cocos2d::EventKeyboard::KeyCode::KEY_COMMA')
    .enum('KEY_MINUS', 'cocos2d::EventKeyboard::KeyCode::KEY_MINUS')
    .enum('KEY_PERIOD', 'cocos2d::EventKeyboard::KeyCode::KEY_PERIOD')
    .enum('KEY_SLASH', 'cocos2d::EventKeyboard::KeyCode::KEY_SLASH')
    .enum('KEY_0', 'cocos2d::EventKeyboard::KeyCode::KEY_0')
    .enum('KEY_1', 'cocos2d::EventKeyboard::KeyCode::KEY_1')
    .enum('KEY_2', 'cocos2d::EventKeyboard::KeyCode::KEY_2')
    .enum('KEY_3', 'cocos2d::EventKeyboard::KeyCode::KEY_3')
    .enum('KEY_4', 'cocos2d::EventKeyboard::KeyCode::KEY_4')
    .enum('KEY_5', 'cocos2d::EventKeyboard::KeyCode::KEY_5')
    .enum('KEY_6', 'cocos2d::EventKeyboard::KeyCode::KEY_6')
    .enum('KEY_7', 'cocos2d::EventKeyboard::KeyCode::KEY_7')
    .enum('KEY_8', 'cocos2d::EventKeyboard::KeyCode::KEY_8')
    .enum('KEY_9', 'cocos2d::EventKeyboard::KeyCode::KEY_9')
    .enum('KEY_COLON', 'cocos2d::EventKeyboard::KeyCode::KEY_COLON')
    .enum('KEY_SEMICOLON', 'cocos2d::EventKeyboard::KeyCode::KEY_SEMICOLON')
    .enum('KEY_LESS_THAN', 'cocos2d::EventKeyboard::KeyCode::KEY_LESS_THAN')
    .enum('KEY_EQUAL', 'cocos2d::EventKeyboard::KeyCode::KEY_EQUAL')
    .enum('KEY_GREATER_THAN', 'cocos2d::EventKeyboard::KeyCode::KEY_GREATER_THAN')
    .enum('KEY_QUESTION', 'cocos2d::EventKeyboard::KeyCode::KEY_QUESTION')
    .enum('KEY_AT', 'cocos2d::EventKeyboard::KeyCode::KEY_AT')
    .enum('KEY_CAPITAL_A', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_A')
    .enum('KEY_CAPITAL_B', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_B')
    .enum('KEY_CAPITAL_C', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_C')
    .enum('KEY_CAPITAL_D', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_D')
    .enum('KEY_CAPITAL_E', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_E')
    .enum('KEY_CAPITAL_F', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_F')
    .enum('KEY_CAPITAL_G', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_G')
    .enum('KEY_CAPITAL_H', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_H')
    .enum('KEY_CAPITAL_I', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_I')
    .enum('KEY_CAPITAL_J', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_J')
    .enum('KEY_CAPITAL_K', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_K')
    .enum('KEY_CAPITAL_L', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_L')
    .enum('KEY_CAPITAL_M', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_M')
    .enum('KEY_CAPITAL_N', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_N')
    .enum('KEY_CAPITAL_O', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_O')
    .enum('KEY_CAPITAL_P', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_P')
    .enum('KEY_CAPITAL_Q', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_Q')
    .enum('KEY_CAPITAL_R', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_R')
    .enum('KEY_CAPITAL_S', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_S')
    .enum('KEY_CAPITAL_T', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_T')
    .enum('KEY_CAPITAL_U', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_U')
    .enum('KEY_CAPITAL_V', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_V')
    .enum('KEY_CAPITAL_W', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_W')
    .enum('KEY_CAPITAL_X', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_X')
    .enum('KEY_CAPITAL_Y', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_Y')
    .enum('KEY_CAPITAL_Z', 'cocos2d::EventKeyboard::KeyCode::KEY_CAPITAL_Z')
    .enum('KEY_LEFT_BRACKET', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_BRACKET')
    .enum('KEY_BACK_SLASH', 'cocos2d::EventKeyboard::KeyCode::KEY_BACK_SLASH')
    .enum('KEY_RIGHT_BRACKET', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_BRACKET')
    .enum('KEY_UNDERSCORE', 'cocos2d::EventKeyboard::KeyCode::KEY_UNDERSCORE')
    .enum('KEY_GRAVE', 'cocos2d::EventKeyboard::KeyCode::KEY_GRAVE')
    .enum('KEY_A', 'cocos2d::EventKeyboard::KeyCode::KEY_A')
    .enum('KEY_B', 'cocos2d::EventKeyboard::KeyCode::KEY_B')
    .enum('KEY_C', 'cocos2d::EventKeyboard::KeyCode::KEY_C')
    .enum('KEY_D', 'cocos2d::EventKeyboard::KeyCode::KEY_D')
    .enum('KEY_E', 'cocos2d::EventKeyboard::KeyCode::KEY_E')
    .enum('KEY_F', 'cocos2d::EventKeyboard::KeyCode::KEY_F')
    .enum('KEY_G', 'cocos2d::EventKeyboard::KeyCode::KEY_G')
    .enum('KEY_H', 'cocos2d::EventKeyboard::KeyCode::KEY_H')
    .enum('KEY_I', 'cocos2d::EventKeyboard::KeyCode::KEY_I')
    .enum('KEY_J', 'cocos2d::EventKeyboard::KeyCode::KEY_J')
    .enum('KEY_K', 'cocos2d::EventKeyboard::KeyCode::KEY_K')
    .enum('KEY_L', 'cocos2d::EventKeyboard::KeyCode::KEY_L')
    .enum('KEY_M', 'cocos2d::EventKeyboard::KeyCode::KEY_M')
    .enum('KEY_N', 'cocos2d::EventKeyboard::KeyCode::KEY_N')
    .enum('KEY_O', 'cocos2d::EventKeyboard::KeyCode::KEY_O')
    .enum('KEY_P', 'cocos2d::EventKeyboard::KeyCode::KEY_P')
    .enum('KEY_Q', 'cocos2d::EventKeyboard::KeyCode::KEY_Q')
    .enum('KEY_R', 'cocos2d::EventKeyboard::KeyCode::KEY_R')
    .enum('KEY_S', 'cocos2d::EventKeyboard::KeyCode::KEY_S')
    .enum('KEY_T', 'cocos2d::EventKeyboard::KeyCode::KEY_T')
    .enum('KEY_U', 'cocos2d::EventKeyboard::KeyCode::KEY_U')
    .enum('KEY_V', 'cocos2d::EventKeyboard::KeyCode::KEY_V')
    .enum('KEY_W', 'cocos2d::EventKeyboard::KeyCode::KEY_W')
    .enum('KEY_X', 'cocos2d::EventKeyboard::KeyCode::KEY_X')
    .enum('KEY_Y', 'cocos2d::EventKeyboard::KeyCode::KEY_Y')
    .enum('KEY_Z', 'cocos2d::EventKeyboard::KeyCode::KEY_Z')
    .enum('KEY_LEFT_BRACE', 'cocos2d::EventKeyboard::KeyCode::KEY_LEFT_BRACE')
    .enum('KEY_BAR', 'cocos2d::EventKeyboard::KeyCode::KEY_BAR')
    .enum('KEY_RIGHT_BRACE', 'cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_BRACE')
    .enum('KEY_TILDE', 'cocos2d::EventKeyboard::KeyCode::KEY_TILDE')
    .enum('KEY_EURO', 'cocos2d::EventKeyboard::KeyCode::KEY_EURO')
    .enum('KEY_POUND', 'cocos2d::EventKeyboard::KeyCode::KEY_POUND')
    .enum('KEY_YEN', 'cocos2d::EventKeyboard::KeyCode::KEY_YEN')
    .enum('KEY_MIDDLE_DOT', 'cocos2d::EventKeyboard::KeyCode::KEY_MIDDLE_DOT')
    .enum('KEY_SEARCH', 'cocos2d::EventKeyboard::KeyCode::KEY_SEARCH')
    .enum('KEY_DPAD_LEFT', 'cocos2d::EventKeyboard::KeyCode::KEY_DPAD_LEFT')
    .enum('KEY_DPAD_RIGHT', 'cocos2d::EventKeyboard::KeyCode::KEY_DPAD_RIGHT')
    .enum('KEY_DPAD_UP', 'cocos2d::EventKeyboard::KeyCode::KEY_DPAD_UP')
    .enum('KEY_DPAD_DOWN', 'cocos2d::EventKeyboard::KeyCode::KEY_DPAD_DOWN')
    .enum('KEY_DPAD_CENTER', 'cocos2d::EventKeyboard::KeyCode::KEY_DPAD_CENTER')
    .enum('KEY_ENTER', 'cocos2d::EventKeyboard::KeyCode::KEY_ENTER')
    .enum('KEY_PLAY', 'cocos2d::EventKeyboard::KeyCode::KEY_PLAY')

typeconf 'cocos2d::Touch::DispatchMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('ALL_AT_ONCE', 'cocos2d::Touch::DispatchMode::ALL_AT_ONCE')
    .enum('ONE_BY_ONE', 'cocos2d::Touch::DispatchMode::ONE_BY_ONE')

typeconf 'cocos2d::EventController::ControllerEventType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('CONNECTION', 'cocos2d::EventController::ControllerEventType::CONNECTION')
    .enum('BUTTON_STATUS_CHANGED', 'cocos2d::EventController::ControllerEventType::BUTTON_STATUS_CHANGED')
    .enum('AXIS_STATUS_CHANGED', 'cocos2d::EventController::ControllerEventType::AXIS_STATUS_CHANGED')

typeconf 'cocos2d::EventController'
    .supercls('cocos2d::Event')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'EventController(cocos2d::EventController::ControllerEventType type, cocos2d::Controller *controller, int keyCode)', 'EventController(cocos2d::EventController::ControllerEventType type, cocos2d::Controller *controller, bool isConnected)')
    .func(nil, 'cocos2d::EventController::ControllerEventType getControllerEventType()')
    .func(nil, 'cocos2d::Controller *getController()')
    .func(nil, 'int getKeyCode()')
    .func(nil, 'void setKeyCode(int keyCode)')
    .func(nil, 'void setConnectStatus(bool isConnected)')
    .func(nil, 'bool isConnected()')
    .prop('controllerEventType', nil, nil)
    .prop('controller', nil, nil)
    .prop('keyCode', nil, nil)
    .prop('connected', nil, nil)

typeconf 'cocos2d::Touch'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'Touch()')
    .func(nil, 'cocos2d::Vec2 getLocation()')
    .func(nil, 'cocos2d::Vec2 getPreviousLocation()')
    .func(nil, 'cocos2d::Vec2 getStartLocation()')
    .func(nil, 'cocos2d::Vec2 getDelta()')
    .func(nil, 'cocos2d::Vec2 getLocationInView()')
    .func(nil, 'cocos2d::Vec2 getPreviousLocationInView()')
    .func(nil, 'cocos2d::Vec2 getStartLocationInView()')
    .func(nil, 'void setTouchInfo(int id, float x, float y)', 'void setTouchInfo(int id, float x, float y, float force, float maxForce)')
    .func(nil, 'int getID()')
    .func(nil, 'float getCurrentForce()')
    .func(nil, 'float getMaxForce()')
    .prop('location', nil, nil)
    .prop('previousLocation', nil, nil)
    .prop('startLocation', nil, nil)
    .prop('delta', nil, nil)
    .prop('locationInView', nil, nil)
    .prop('previousLocationInView', nil, nil)
    .prop('startLocationInView', nil, nil)
    .prop('id', nil, nil)
    .prop('currentForce', nil, nil)
    .prop('maxForce', nil, nil)

typeconf 'cocos2d::Controller::Key'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('KEY_NONE', 'cocos2d::Controller::Key::KEY_NONE')
    .enum('JOYSTICK_LEFT_X', 'cocos2d::Controller::Key::JOYSTICK_LEFT_X')
    .enum('JOYSTICK_LEFT_Y', 'cocos2d::Controller::Key::JOYSTICK_LEFT_Y')
    .enum('JOYSTICK_RIGHT_X', 'cocos2d::Controller::Key::JOYSTICK_RIGHT_X')
    .enum('JOYSTICK_RIGHT_Y', 'cocos2d::Controller::Key::JOYSTICK_RIGHT_Y')
    .enum('BUTTON_A', 'cocos2d::Controller::Key::BUTTON_A')
    .enum('BUTTON_B', 'cocos2d::Controller::Key::BUTTON_B')
    .enum('BUTTON_C', 'cocos2d::Controller::Key::BUTTON_C')
    .enum('BUTTON_X', 'cocos2d::Controller::Key::BUTTON_X')
    .enum('BUTTON_Y', 'cocos2d::Controller::Key::BUTTON_Y')
    .enum('BUTTON_Z', 'cocos2d::Controller::Key::BUTTON_Z')
    .enum('BUTTON_DPAD_UP', 'cocos2d::Controller::Key::BUTTON_DPAD_UP')
    .enum('BUTTON_DPAD_DOWN', 'cocos2d::Controller::Key::BUTTON_DPAD_DOWN')
    .enum('BUTTON_DPAD_LEFT', 'cocos2d::Controller::Key::BUTTON_DPAD_LEFT')
    .enum('BUTTON_DPAD_RIGHT', 'cocos2d::Controller::Key::BUTTON_DPAD_RIGHT')
    .enum('BUTTON_DPAD_CENTER', 'cocos2d::Controller::Key::BUTTON_DPAD_CENTER')
    .enum('BUTTON_LEFT_SHOULDER', 'cocos2d::Controller::Key::BUTTON_LEFT_SHOULDER')
    .enum('BUTTON_RIGHT_SHOULDER', 'cocos2d::Controller::Key::BUTTON_RIGHT_SHOULDER')
    .enum('AXIS_LEFT_TRIGGER', 'cocos2d::Controller::Key::AXIS_LEFT_TRIGGER')
    .enum('AXIS_RIGHT_TRIGGER', 'cocos2d::Controller::Key::AXIS_RIGHT_TRIGGER')
    .enum('BUTTON_LEFT_THUMBSTICK', 'cocos2d::Controller::Key::BUTTON_LEFT_THUMBSTICK')
    .enum('BUTTON_RIGHT_THUMBSTICK', 'cocos2d::Controller::Key::BUTTON_RIGHT_THUMBSTICK')
    .enum('BUTTON_START', 'cocos2d::Controller::Key::BUTTON_START')
    .enum('BUTTON_SELECT', 'cocos2d::Controller::Key::BUTTON_SELECT')
    .enum('BUTTON_PAUSE', 'cocos2d::Controller::Key::BUTTON_PAUSE')
    .enum('KEY_MAX', 'cocos2d::Controller::Key::KEY_MAX')

typeconf 'cocos2d::Controller'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('TAG_UNSET', 'cocos2d::Controller::TAG_UNSET', 'const int')
    .func(nil, 'static const std::vector<Controller *> &getAllController()')
    .func(nil, 'static cocos2d::Controller *getControllerByTag(int tag)')
    .func(nil, 'static cocos2d::Controller *getControllerByDeviceId(int deviceId)')
    .func(nil, 'static void startDiscoveryController()')
    .func(nil, 'static void stopDiscoveryController()')
    .func(nil, 'const std::string &getDeviceName()')
    .func(nil, 'int getDeviceId()')
    .func(nil, 'bool isConnected()')
    .func(nil, 'const cocos2d::Controller::KeyStatus &getKeyStatus(int keyCode)')
    .func(nil, 'void setTag(int tag)')
    .func(nil, 'int getTag()')
    .prop('allController', nil, nil)
    .prop('deviceName', nil, nil)
    .prop('deviceId', nil, nil)
    .prop('connected', nil, nil)
    .prop('tag', nil, nil)

typeconf 'cocos2d::AudioProfile'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'AudioProfile()')
    .var('name', 'std::string name')
    .var('maxInstances', 'unsigned int maxInstances')
    .var('minDelay', 'double minDelay')

typeconf 'cocos2d::AudioEngine::AudioState'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('ERROR', 'cocos2d::AudioEngine::AudioState::ERROR')
    .enum('INITIALIZING', 'cocos2d::AudioEngine::AudioState::INITIALIZING')
    .enum('PLAYING', 'cocos2d::AudioEngine::AudioState::PLAYING')
    .enum('PAUSED', 'cocos2d::AudioEngine::AudioState::PAUSED')

typeconf 'cocos2d::AudioEngine'
    .supercls(nil)
    .reg_luatype(true)
    .chunk([[
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
    ]])
    .require(nil)
    .const('INVALID_AUDIO_ID', 'cocos2d::AudioEngine::INVALID_AUDIO_ID', 'const int')
    .const('TIME_UNKNOWN', 'cocos2d::AudioEngine::TIME_UNKNOWN', 'const float')
    .func(nil, 'static bool lazyInit()')
    .func(nil, 'static void end()')
    .func(nil, 'static cocos2d::AudioProfile *getDefaultProfile()')
    .func(nil, 'static int play2d(const std::string &filePath, @optional bool loop, @optional float volume, @optional const cocos2d::AudioProfile *profile)')
    .func(nil, 'static void setLoop(int audioID, bool loop)')
    .func(nil, 'static bool isLoop(int audioID)')
    .func(nil, 'static void setVolume(int audioID, float volume)')
    .func(nil, 'static float getVolume(int audioID)')
    .func(nil, 'static void pause(int audioID)')
    .func(nil, 'static void pauseAll()')
    .func(nil, 'static void resume(int audioID)')
    .func(nil, 'static void resumeAll()')
    .func(nil, 'static bool setCurrentTime(int audioID, float sec)')
    .func(nil, 'static float getCurrentTime(int audioID)')
    .func(nil, 'static float getDuration(int audioID)')
    .func(nil, 'static cocos2d::AudioEngine::AudioState getState(int audioID)')
    .func(nil, 'static int getMaxAudioInstance()')
    .func(nil, 'static bool setMaxAudioInstance(int maxInstances)')
    .func(nil, 'static void uncache(const std::string &filePath)')
    .func(nil, 'static cocos2d::AudioProfile *getProfile(int audioID)', 'static cocos2d::AudioProfile *getProfile(const std::string &profileName)')
    .func(nil, 'static int getPlayingAudioCount()')
    .func(nil, 'static void setEnabled(bool isEnabled)')
    .func(nil, 'static bool isEnabled()')
    .callback {
        FUNCS =  {
            'static void stop(int audioID)'
        },
        TAG_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'static void stopAll()'
        },
        TAG_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
        TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'static void uncacheAll()'
        },
        TAG_MAKER = 'makeAudioEngineFinishCallbackTag(-1)',
        TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'static void setFinishCallback(int audioID, @nullable @local const std::function<void (int, const std::string &)> &callback)'
        },
        TAG_MAKER = 'makeAudioEngineFinishCallbackTag(#1)',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'static void preload(const std::string &filePath)',
            'static void preload(const std::string &filePath, @local std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'preload',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .prop('defaultProfile', nil, nil)
    .prop('maxAudioInstance', nil, nil)
    .prop('playingAudioCount', nil, nil)
    .prop('enabled', nil, nil)
    .insert('uncache', {
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

typeconf 'cocos2d::ApplicationProtocol::Platform'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('OS_WINDOWS', 'cocos2d::ApplicationProtocol::Platform::OS_WINDOWS')
    .enum('OS_LINUX', 'cocos2d::ApplicationProtocol::Platform::OS_LINUX')
    .enum('OS_MAC', 'cocos2d::ApplicationProtocol::Platform::OS_MAC')
    .enum('OS_ANDROID', 'cocos2d::ApplicationProtocol::Platform::OS_ANDROID')
    .enum('OS_IPHONE', 'cocos2d::ApplicationProtocol::Platform::OS_IPHONE')
    .enum('OS_IPAD', 'cocos2d::ApplicationProtocol::Platform::OS_IPAD')

typeconf 'cocos2d::LanguageType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('ENGLISH', 'cocos2d::LanguageType::ENGLISH')
    .enum('CHINESE', 'cocos2d::LanguageType::CHINESE')
    .enum('FRENCH', 'cocos2d::LanguageType::FRENCH')
    .enum('ITALIAN', 'cocos2d::LanguageType::ITALIAN')
    .enum('GERMAN', 'cocos2d::LanguageType::GERMAN')
    .enum('SPANISH', 'cocos2d::LanguageType::SPANISH')
    .enum('DUTCH', 'cocos2d::LanguageType::DUTCH')
    .enum('RUSSIAN', 'cocos2d::LanguageType::RUSSIAN')
    .enum('KOREAN', 'cocos2d::LanguageType::KOREAN')
    .enum('JAPANESE', 'cocos2d::LanguageType::JAPANESE')
    .enum('HUNGARIAN', 'cocos2d::LanguageType::HUNGARIAN')
    .enum('PORTUGUESE', 'cocos2d::LanguageType::PORTUGUESE')
    .enum('ARABIC', 'cocos2d::LanguageType::ARABIC')
    .enum('NORWEGIAN', 'cocos2d::LanguageType::NORWEGIAN')
    .enum('POLISH', 'cocos2d::LanguageType::POLISH')
    .enum('TURKISH', 'cocos2d::LanguageType::TURKISH')
    .enum('UKRAINIAN', 'cocos2d::LanguageType::UKRAINIAN')
    .enum('ROMANIAN', 'cocos2d::LanguageType::ROMANIAN')
    .enum('BULGARIAN', 'cocos2d::LanguageType::BULGARIAN')
    .enum('BELARUSIAN', 'cocos2d::LanguageType::BELARUSIAN')

typeconf 'cocos2d::ApplicationProtocol'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'bool applicationDidFinishLaunching()')
    .func(nil, 'void applicationDidEnterBackground()')
    .func(nil, 'void applicationWillEnterForeground()')
    .func(nil, 'void setAnimationInterval(float interval)')
    .func(nil, 'void initGLContextAttrs()')
    .func(nil, 'cocos2d::LanguageType getCurrentLanguage()')
    .func(nil, 'const char *getCurrentLanguageCode()')
    .func(nil, 'cocos2d::ApplicationProtocol::Platform getTargetPlatform()')
    .func(nil, 'std::string getVersion()')
    .func(nil, 'bool openURL(const std::string &url)')
    .prop('currentLanguage', nil, nil)
    .prop('currentLanguageCode', nil, nil)
    .prop('targetPlatform', nil, nil)
    .prop('version', nil, nil)

typeconf 'cocos2d::Application'
    .supercls('cocos2d::ApplicationProtocol')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'int run()')
    .func(nil, 'static cocos2d::Application *getInstance()')
    .prop('instance', nil, nil)

typeconf 'cocos2d::Device'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static int getDPI()')
    .func(nil, 'static void setAccelerometerEnabled(bool isEnabled)')
    .func(nil, 'static void setAccelerometerInterval(float interval)')
    .func(nil, 'static void setKeepScreenOn(bool keepScreenOn)')
    .func(nil, 'static void vibrate(float duration)')
    .prop('dpi', nil, nil)

typeconf 'cocos2d::ResizableBuffer'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void resize(size_t size)')
    .func(nil, 'void *buffer()')

typeconf 'cocos2d::FileUtils::Status'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('OK', 'cocos2d::FileUtils::Status::OK')
    .enum('NotExists', 'cocos2d::FileUtils::Status::NotExists')
    .enum('OpenFailed', 'cocos2d::FileUtils::Status::OpenFailed')
    .enum('ReadFailed', 'cocos2d::FileUtils::Status::ReadFailed')
    .enum('NotInitialized', 'cocos2d::FileUtils::Status::NotInitialized')
    .enum('TooLarge', 'cocos2d::FileUtils::Status::TooLarge')
    .enum('ObtainSizeFailed', 'cocos2d::FileUtils::Status::ObtainSizeFailed')
    .enum('NotRegularFileType', 'cocos2d::FileUtils::Status::NotRegularFileType')

typeconf 'cocos2d::FileUtils'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func('getFileDataFromZip', [[
        {
            cocos2d::FileUtils *self = olua_toobj<cocos2d::FileUtils>(L, 1);
            std::string zipFilePath = olua_checkstring(L, 2);
            std::string filename = olua_checkstring(L, 3);
            ssize_t size = 0;
            unsigned char *data = self->getFileDataFromZip(zipFilePath, filename, &size);
            lua_pushlstring(L, (const char *)data, size);
            olua_push_int(L, (lua_Integer)size);

            return 2;
        }
    ]])
    .func(nil, 'static cocos2d::FileUtils *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'static void setDelegate(cocos2d::FileUtils *delegate)')
    .func(nil, 'void purgeCachedEntries()')
    .func(nil, 'cocos2d::FileUtils::Status getContents(const std::string &filename, cocos2d::ResizableBuffer *buffer)')
    .func(nil, 'std::string fullPathForFilename(const std::string &filename)')
    .func(nil, 'void loadFilenameLookupDictionaryFromFile(const std::string &filename)')
    .func(nil, 'void setFilenameLookupDictionary(const cocos2d::ValueMap &filenameLookupDict)')
    .func(nil, 'std::string fullPathFromRelativeFile(const std::string &filename, const std::string &relativeFile)')
    .func(nil, 'void setSearchResolutionsOrder(const std::vector<std::string> &searchResolutionsOrder)')
    .func(nil, 'void addSearchResolutionsOrder(const std::string &order, @optional const bool front)')
    .func(nil, 'const std::vector<std::string> getSearchResolutionsOrder()')
    .func(nil, 'void setSearchPaths(const std::vector<std::string> &searchPaths)')
    .func(nil, 'const std::string getDefaultResourceRootPath()')
    .func(nil, 'void setDefaultResourceRootPath(const std::string &path)')
    .func(nil, 'void addSearchPath(const std::string &path, @optional const bool front)')
    .func(nil, 'const std::vector<std::string> getSearchPaths()')
    .func(nil, 'const std::vector<std::string> getOriginalSearchPaths()')
    .func(nil, 'std::string getWritablePath()')
    .func(nil, 'void setWritablePath(const std::string &writablePath)')
    .func(nil, 'void setPopupNotify(bool notify)')
    .func(nil, 'bool isPopupNotify()')
    .func(nil, 'cocos2d::ValueMap getValueMapFromFile(const std::string &filename)')
    .func(nil, 'cocos2d::ValueMap getValueMapFromData(const char *filedata, int filesize)')
    .func(nil, 'bool writeToFile(const cocos2d::ValueMap &dict, const std::string &fullPath)')
    .func(nil, 'std::string getSuitableFOpen(const std::string &filenameUtf8)')
    .func(nil, 'cocos2d::ValueVector getValueVectorFromFile(const std::string &filename)')
    .func(nil, 'std::string getFileExtension(const std::string &filePath)')
    .func(nil, 'bool isAbsolutePath(const std::string &path)')
    .func(nil, 'std::vector<std::string> listFiles(const std::string &dirPath)')
    .func(nil, 'void listFilesRecursively(const std::string &dirPath, @out std::vector<std::string> *files)')
    .func(nil, 'const std::unordered_map<std::string, std::string> getFullPathCache()')
    .func(nil, 'std::string getNewFilename(const std::string &filename)')
    .callback {
        FUNCS =  {
            'std::string getStringFromFile(const std::string &filename)',
            'void getStringFromFile(const std::string &path, @local std::function<void (std::string)> callback)'
        },
        TAG_MAKER = 'StringFromFile',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'cocos2d::Data getDataFromFile(const std::string &filename)',
            'void getDataFromFile(const std::string &filename, @local std::function<void (cocos2d::Data)> callback)'
        },
        TAG_MAKER = 'DataFromFile',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'bool writeStringToFile(const std::string &dataStr, const std::string &fullPath)',
            'void writeStringToFile(std::string dataStr, const std::string &fullPath, @local std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'writeStringToFile',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'bool writeDataToFile(const cocos2d::Data &data, const std::string &fullPath)',
            'void writeDataToFile(cocos2d::Data data, const std::string &fullPath, @local std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'writeDataToFile',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'bool writeValueMapToFile(const cocos2d::ValueMap &dict, const std::string &fullPath)',
            'void writeValueMapToFile(cocos2d::ValueMap dict, const std::string &fullPath, @local std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'writeValueMapToFile',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'bool writeValueVectorToFile(const cocos2d::ValueVector &vecData, const std::string &fullPath)',
            'void writeValueVectorToFile(cocos2d::ValueVector vecData, const std::string &fullPath, @local std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'writeValueVectorToFile',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'bool isFileExist(const std::string &filename)',
            'void isFileExist(const std::string &filename, @local std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'isFileExist',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'bool isDirectoryExist(const std::string &dirPath)',
            'void isDirectoryExist(const std::string &fullPath, @local std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'isDirectoryExist',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'bool createDirectory(const std::string &dirPath)',
            'void createDirectory(const std::string &dirPath, @local std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'createDirectory',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'bool removeDirectory(const std::string &dirPath)',
            'void removeDirectory(const std::string &dirPath, @local std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'removeDirectory',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'bool removeFile(const std::string &filepath)',
            'void removeFile(const std::string &filepath, @local std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'removeFile',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
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
    .callback {
        FUNCS =  {
            'long getFileSize(const std::string &filepath)',
            'void getFileSize(const std::string &filepath, @local std::function<void (long)> callback)'
        },
        TAG_MAKER = 'FileSize',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'void listFilesAsync(const std::string &dirPath, @local std::function<void (std::vector<std::string>)> callback)'
        },
        TAG_MAKER = 'listFilesAsync',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'void listFilesRecursivelyAsync(const std::string &dirPath, @local std::function<void (std::vector<std::string>)> callback)'
        },
        TAG_MAKER = 'listFilesRecursivelyAsync',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .prop('instance', nil, nil)
    .prop('searchResolutionsOrder', nil, nil)
    .prop('defaultResourceRootPath', nil, nil)
    .prop('searchPaths', nil, nil)
    .prop('originalSearchPaths', nil, nil)
    .prop('writablePath', nil, nil)
    .prop('popupNotify', nil, nil)
    .prop('fullPathCache', nil, nil)

typeconf 'ResolutionPolicy'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('EXACT_FIT', 'ResolutionPolicy::EXACT_FIT')
    .enum('NO_BORDER', 'ResolutionPolicy::NO_BORDER')
    .enum('SHOW_ALL', 'ResolutionPolicy::SHOW_ALL')
    .enum('FIXED_HEIGHT', 'ResolutionPolicy::FIXED_HEIGHT')
    .enum('FIXED_WIDTH', 'ResolutionPolicy::FIXED_WIDTH')
    .enum('UNKNOWN', 'ResolutionPolicy::UNKNOWN')

typeconf 'cocos2d::GLView'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void end()')
    .func(nil, 'bool isOpenGLReady()')
    .func(nil, 'void swapBuffers()')
    .func(nil, 'void setIMEKeyboardState(bool open)')
    .func(nil, 'bool windowShouldClose()')
    .func(nil, 'static void setGLContextAttrs(GLContextAttrs &glContextAttrs)')
    .func(nil, 'static GLContextAttrs getGLContextAttrs()')
    .func(nil, 'void pollEvents()')
    .func(nil, 'cocos2d::Size getFrameSize()')
    .func(nil, 'void setFrameSize(float width, float height)')
    .func(nil, 'void setFrameZoomFactor(float )')
    .func(nil, 'float getFrameZoomFactor()')
    .func(nil, 'void setCursorVisible(bool )')
    .func(nil, 'int getRetinaFactor()')
    .func(nil, 'bool setContentScaleFactor(float )')
    .func(nil, 'float getContentScaleFactor()')
    .func(nil, 'bool isRetinaDisplay()')
    .func(nil, 'cocos2d::Size getVisibleSize()')
    .func(nil, 'cocos2d::Vec2 getVisibleOrigin()')
    .func(nil, 'cocos2d::Rect getVisibleRect()')
    .func(nil, 'cocos2d::Rect getSafeAreaRect()')
    .func(nil, 'void setDesignResolutionSize(float width, float height, ResolutionPolicy resolutionPolicy)')
    .func(nil, 'const cocos2d::Size &getDesignResolutionSize()')
    .func(nil, 'void setViewPortInPoints(float x, float y, float w, float h)')
    .func(nil, 'void setScissorInPoints(float x, float y, float w, float h)')
    .func(nil, 'bool isScissorEnabled()')
    .func(nil, 'cocos2d::Rect getScissorRect()')
    .func(nil, 'void setViewName(const std::string &viewname)')
    .func(nil, 'const std::string &getViewName()')
    .func(nil, 'void setIcon(const std::string &filename)', 'void setIcon(const std::vector<std::string> &filelist)')
    .func(nil, 'void setDefaultIcon()')
    .func(nil, 'const cocos2d::Rect &getViewPortRect()')
    .func(nil, 'std::vector<Touch *> getAllTouches()')
    .func(nil, 'float getScaleX()')
    .func(nil, 'float getScaleY()')
    .func(nil, 'ResolutionPolicy getResolutionPolicy()')
    .func(nil, 'void renderScene(cocos2d::Scene *scene, cocos2d::Renderer *renderer)')
    .prop('openGLReady', nil, nil)
    .prop('glContextAttrs', nil, nil)
    .prop('frameSize', nil, nil)
    .prop('frameZoomFactor', nil, nil)
    .prop('retinaFactor', nil, nil)
    .prop('contentScaleFactor', nil, nil)
    .prop('retinaDisplay', nil, nil)
    .prop('visibleSize', nil, nil)
    .prop('visibleOrigin', nil, nil)
    .prop('visibleRect', nil, nil)
    .prop('safeAreaRect', nil, nil)
    .prop('designResolutionSize', nil, nil)
    .prop('scissorEnabled', nil, nil)
    .prop('scissorRect', nil, nil)
    .prop('viewName', nil, nil)
    .prop('viewPortRect', nil, nil)
    .prop('allTouches', nil, nil)
    .prop('scaleX', nil, nil)
    .prop('scaleY', nil, nil)
    .prop('resolutionPolicy', nil, nil)

typeconf 'cocos2d::GLViewImpl'
    .supercls('cocos2d::GLView')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::Image::Format'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('JPG', 'cocos2d::Image::Format::JPG')
    .enum('PNG', 'cocos2d::Image::Format::PNG')
    .enum('WEBP', 'cocos2d::Image::Format::WEBP')
    .enum('PVR', 'cocos2d::Image::Format::PVR')
    .enum('ETC', 'cocos2d::Image::Format::ETC')
    .enum('S3TC', 'cocos2d::Image::Format::S3TC')
    .enum('ATITC', 'cocos2d::Image::Format::ATITC')
    .enum('TGA', 'cocos2d::Image::Format::TGA')
    .enum('RAW_DATA', 'cocos2d::Image::Format::RAW_DATA')
    .enum('UNKNOWN', 'cocos2d::Image::Format::UNKNOWN')

typeconf 'cocos2d::Image'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk([[
        NS_CC_BEGIN
        class LuaImage : public cocos2d::Image {
        public:
            static bool getPNGPremultipliedAlphaEnabled() { return PNG_PREMULTIPLIED_ALPHA_ENABLED; };
        };
        NS_CC_END
    ]])
    .require(nil)
    .func('getPNGPremultipliedAlphaEnabled', [[
        {
            lua_pushboolean(L, cocos2d::LuaImage::getPNGPremultipliedAlphaEnabled());
            return 1;
        }
    ]])
    .func(nil, 'Image()')
    .func(nil, 'static void setPNGPremultipliedAlphaEnabled(bool enabled)')
    .func(nil, 'static void setPVRImagesHavePremultipliedAlpha(bool haveAlphaPremultiplied)')
    .func(nil, 'bool initWithImageFile(const std::string &path)')
    .func(nil, 'bool initWithImageData(const unsigned char *data, ssize_t dataLen)')
    .func(nil, 'bool initWithRawData(const unsigned char *data, ssize_t dataLen, int width, int height, int bitsPerComponent, @optional bool preMulti)')
    .func(nil, 'unsigned char *getData()')
    .func(nil, 'ssize_t getDataLen()')
    .func(nil, 'cocos2d::Image::Format getFileType()')
    .func(nil, 'cocos2d::backend::PixelFormat getPixelFormat()')
    .func(nil, 'int getWidth()')
    .func(nil, 'int getHeight()')
    .func(nil, 'int getNumberOfMipmaps()')
    .func(nil, 'bool hasPremultipliedAlpha()')
    .func(nil, 'std::string getFilePath()')
    .func(nil, 'int getBitPerPixel()')
    .func(nil, 'bool hasAlpha()')
    .func(nil, 'bool isCompressed()')
    .func(nil, 'bool saveToFile(const std::string &filename, @optional bool isToRGB)')
    .func(nil, 'void premultiplyAlpha()')
    .func(nil, 'void reversePremultipliedAlpha()')
    .prop('data', nil, nil)
    .prop('dataLen', nil, nil)
    .prop('fileType', nil, nil)
    .prop('pixelFormat', nil, nil)
    .prop('width', nil, nil)
    .prop('height', nil, nil)
    .prop('numberOfMipmaps', nil, nil)
    .prop('filePath', nil, nil)
    .prop('bitPerPixel', nil, nil)
    .prop('compressed', nil, nil)

typeconf 'cocos2d::Properties::Type'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NONE', 'cocos2d::Properties::Type::NONE')
    .enum('STRING', 'cocos2d::Properties::Type::STRING')
    .enum('NUMBER', 'cocos2d::Properties::Type::NUMBER')
    .enum('VECTOR2', 'cocos2d::Properties::Type::VECTOR2')
    .enum('VECTOR3', 'cocos2d::Properties::Type::VECTOR3')
    .enum('VECTOR4', 'cocos2d::Properties::Type::VECTOR4')
    .enum('MATRIX', 'cocos2d::Properties::Type::MATRIX')

typeconf 'cocos2d::Properties'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Properties *createNonRefCounted(const std::string &url)')
    .func(nil, 'const char *getNextProperty()')
    .func(nil, 'cocos2d::Properties *getNextNamespace()')
    .func(nil, 'void rewind()')
    .func(nil, 'cocos2d::Properties *getNamespace(const char *id, @optional bool searchNames, @optional bool recurse)', 'const char *getNamespace()')
    .func(nil, 'const char *getId()')
    .func(nil, 'bool exists(const char *name)')
    .func(nil, 'cocos2d::Properties::Type getType(@optional const char *name)')
    .func(nil, 'const char *getString(@optional const char *name, @optional const char *defaultValue)')
    .func(nil, 'bool setString(const char *name, const char *value)')
    .func(nil, 'bool getBool(@optional const char *name, @optional bool defaultValue)')
    .func(nil, 'int getInt(@optional const char *name)')
    .func(nil, 'float getFloat(@optional const char *name)')
    .func(nil, 'long getLong(@optional const char *name)')
    .func(nil, 'bool getPath(const char *name, @out std::string *path)')
    .func(nil, 'const char *getVariable(const char *name, @optional const char *defaultValue)')
    .func(nil, 'void setVariable(const char *name, const char *value)')
    .prop('nextProperty', nil, nil)
    .prop('nextNamespace', nil, nil)
    .prop('id', nil, nil)

typeconf 'cocos2d::Material'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Material *createWithFilename(const std::string &path)')
    .func(nil, 'static cocos2d::Material *createWithProgramState(cocos2d::backend::ProgramState *programState)')
    .func(nil, 'static cocos2d::Material *createWithProperties(cocos2d::Properties *materialProperties)')
    .func(nil, 'void draw(cocos2d::MeshCommand *meshCommand, float globalZOrder, cocos2d::backend::Buffer *vertexBuffer, cocos2d::backend::Buffer *indexBuffer, cocos2d::CustomCommand::PrimitiveType primitive, cocos2d::CustomCommand::IndexFormat indexFormat, unsigned int indexCount, const cocos2d::Mat4 &modelView)')
    .func(nil, 'std::string getName()')
    .func(nil, 'void setName(const std::string &name)')
    .func(nil, 'cocos2d::Technique *getTechniqueByName(const std::string &name)')
    .func(nil, 'cocos2d::Technique *getTechniqueByIndex(ssize_t index)')
    .func(nil, 'cocos2d::Technique *getTechnique()')
    .func(nil, 'const Vector<cocos2d::Technique *> &getTechniques()')
    .func(nil, 'ssize_t getTechniqueCount()')
    .func(nil, 'void addTechnique(cocos2d::Technique *technique)')
    .func(nil, 'void setTechnique(const std::string &techniqueName)')
    .func(nil, 'cocos2d::Material *clone()')
    .func(nil, 'cocos2d::RenderState *getRenderState()')
    .prop('name', nil, nil)
    .prop('technique', nil, nil)
    .prop('techniques', nil, nil)
    .prop('techniqueCount', nil, nil)
    .prop('renderState', nil, nil)

typeconf 'cocos2d::Renderer'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('VBO_SIZE', 'cocos2d::Renderer::VBO_SIZE', 'const int')
    .const('INDEX_VBO_SIZE', 'cocos2d::Renderer::INDEX_VBO_SIZE', 'const int')
    .const('BATCH_TRIAGCOMMAND_RESERVED_SIZE', 'cocos2d::Renderer::BATCH_TRIAGCOMMAND_RESERVED_SIZE', 'const int')
    .const('MATERIAL_ID_DO_NOT_BATCH', 'cocos2d::Renderer::MATERIAL_ID_DO_NOT_BATCH', 'const int')
    .func(nil, 'Renderer()')
    .func(nil, 'void init()')
    .func(nil, 'void drawCommand(cocos2d::RenderCommand *command)')
    .func(nil, 'void addCommand(cocos2d::RenderCommand *command)', 'void addCommand(cocos2d::RenderCommand *command, int renderQueueID)')
    .func(nil, 'void pushGroup(int renderQueueID)')
    .func(nil, 'void popGroup()')
    .func(nil, 'int createRenderQueue()')
    .func(nil, 'void render()')
    .func(nil, 'void clean()')
    .func(nil, 'ssize_t getDrawnBatches()')
    .func(nil, 'void addDrawnBatches(ssize_t number)')
    .func(nil, 'ssize_t getDrawnVertices()')
    .func(nil, 'void addDrawnVertices(ssize_t number)')
    .func(nil, 'void clearDrawStats()')
    .func(nil, 'void setRenderTarget(cocos2d::RenderTargetFlag flags, cocos2d::Texture2D *colorAttachment, cocos2d::Texture2D *depthAttachment, cocos2d::Texture2D *stencilAttachment)')
    .func(nil, 'void clear(cocos2d::ClearFlag flags, const cocos2d::Color4F &color, float depth, unsigned int stencil, float globalOrder)')
    .func(nil, 'cocos2d::Texture2D *getColorAttachment()')
    .func(nil, 'cocos2d::Texture2D *getDepthAttachment()')
    .func(nil, 'cocos2d::Texture2D *getStencilAttachment()')
    .func(nil, 'const cocos2d::Color4F &getClearColor()')
    .func(nil, 'float getClearDepth()')
    .func(nil, 'unsigned int getClearStencil()')
    .func(nil, 'cocos2d::ClearFlag getClearFlag()')
    .func(nil, 'cocos2d::RenderTargetFlag getRenderTargetFlag()')
    .func(nil, 'void setDepthTest(bool value)')
    .func(nil, 'void setDepthWrite(bool value)')
    .func(nil, 'void setDepthCompareFunction(cocos2d::backend::CompareFunction func)')
    .func(nil, 'bool getDepthTest()')
    .func(nil, 'bool getDepthWrite()')
    .func(nil, 'cocos2d::backend::CompareFunction getDepthCompareFunction()')
    .func(nil, 'void setStencilTest(bool value)')
    .func(nil, 'void setStencilCompareFunction(cocos2d::backend::CompareFunction func, unsigned int ref, unsigned int readMask)')
    .func(nil, 'void setStencilOperation(cocos2d::backend::StencilOperation stencilFailureOp, cocos2d::backend::StencilOperation depthFailureOp, cocos2d::backend::StencilOperation stencilDepthPassOp)')
    .func(nil, 'void setStencilWriteMask(unsigned int mask)')
    .func(nil, 'bool getStencilTest()')
    .func(nil, 'cocos2d::backend::StencilOperation getStencilFailureOperation()')
    .func(nil, 'cocos2d::backend::StencilOperation getStencilPassDepthFailureOperation()')
    .func(nil, 'cocos2d::backend::StencilOperation getStencilDepthPassOperation()')
    .func(nil, 'cocos2d::backend::CompareFunction getStencilCompareFunction()')
    .func(nil, 'unsigned int getStencilReadMask()')
    .func(nil, 'unsigned int getStencilWriteMask()')
    .func(nil, 'unsigned int getStencilReferenceValue()')
    .func(nil, 'void setCullMode(cocos2d::CullMode mode)')
    .func(nil, 'cocos2d::CullMode getCullMode()')
    .func(nil, 'void setWinding(cocos2d::Winding winding)')
    .func(nil, 'cocos2d::Winding getWinding()')
    .func(nil, 'void setViewPort(int x, int y, unsigned int w, unsigned int h)')
    .func(nil, 'const cocos2d::Viewport &getViewport()')
    .func(nil, 'void setScissorTest(bool enabled)')
    .func(nil, 'void setScissorRect(float x, float y, float width, float height)')
    .func(nil, 'bool getScissorTest()')
    .func(nil, 'const cocos2d::ScissorRect &getScissorRect()')
    .func(nil, 'bool checkVisibility(const cocos2d::Mat4 &transform, const cocos2d::Size &size)')
    .prop('drawnBatches', nil, nil)
    .prop('drawnVertices', nil, nil)
    .prop('colorAttachment', nil, nil)
    .prop('depthAttachment', nil, nil)
    .prop('stencilAttachment', nil, nil)
    .prop('clearColor', nil, nil)
    .prop('clearDepth', nil, nil)
    .prop('clearStencil', nil, nil)
    .prop('clearFlag', nil, nil)
    .prop('renderTargetFlag', nil, nil)
    .prop('depthTest', nil, nil)
    .prop('depthWrite', nil, nil)
    .prop('depthCompareFunction', nil, nil)
    .prop('stencilTest', nil, nil)
    .prop('stencilFailureOperation', nil, nil)
    .prop('stencilPassDepthFailureOperation', nil, nil)
    .prop('stencilDepthPassOperation', nil, nil)
    .prop('stencilCompareFunction', nil, nil)
    .prop('stencilReadMask', nil, nil)
    .prop('stencilWriteMask', nil, nil)
    .prop('stencilReferenceValue', nil, nil)
    .prop('cullMode', nil, nil)
    .prop('winding', nil, nil)
    .prop('viewport', nil, nil)
    .prop('scissorTest', nil, nil)
    .prop('scissorRect', nil, nil)

typeconf 'cocos2d::RenderCommand::Type'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('UNKNOWN_COMMAND', 'cocos2d::RenderCommand::Type::UNKNOWN_COMMAND')
    .enum('QUAD_COMMAND', 'cocos2d::RenderCommand::Type::QUAD_COMMAND')
    .enum('CUSTOM_COMMAND', 'cocos2d::RenderCommand::Type::CUSTOM_COMMAND')
    .enum('GROUP_COMMAND', 'cocos2d::RenderCommand::Type::GROUP_COMMAND')
    .enum('MESH_COMMAND', 'cocos2d::RenderCommand::Type::MESH_COMMAND')
    .enum('TRIANGLES_COMMAND', 'cocos2d::RenderCommand::Type::TRIANGLES_COMMAND')
    .enum('CALLBACK_COMMAND', 'cocos2d::RenderCommand::Type::CALLBACK_COMMAND')
    .enum('CAPTURE_SCREEN_COMMAND', 'cocos2d::RenderCommand::Type::CAPTURE_SCREEN_COMMAND')

typeconf 'cocos2d::CustomCommand::DrawType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('ARRAY', 'cocos2d::CustomCommand::DrawType::ARRAY')
    .enum('ELEMENT', 'cocos2d::CustomCommand::DrawType::ELEMENT')

typeconf 'cocos2d::PipelineDescriptor'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .var('programState', '@optional cocos2d::backend::ProgramState *programState')
    .var('blendDescriptor', 'cocos2d::backend::BlendDescriptor blendDescriptor')

typeconf 'cocos2d::Technique'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::Pass'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::RenderState'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::RenderCommand'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void init(float globalZOrder, const cocos2d::Mat4 &modelViewTransform, unsigned int flags)')
    .func(nil, 'float getGlobalOrder()')
    .func(nil, 'cocos2d::RenderCommand::Type getType()')
    .func(nil, 'bool isTransparent()')
    .func(nil, 'void setTransparent(bool isTransparent)')
    .func(nil, 'bool isSkipBatching()')
    .func(nil, 'void setSkipBatching(bool value)')
    .func(nil, 'bool is3D()')
    .func(nil, 'void set3D(bool value)')
    .func(nil, 'float getDepth()')
    .func(nil, 'cocos2d::PipelineDescriptor &getPipelineDescriptor()')
    .func(nil, 'const cocos2d::Mat4 &getMV()')
    .prop('globalOrder', nil, nil)
    .prop('type', nil, nil)
    .prop('transparent', nil, nil)
    .prop('skipBatching', nil, nil)
    .prop('3D', nil, nil)
    .prop('depth', nil, nil)
    .prop('pipelineDescriptor', nil, nil)
    .prop('mv', nil, nil)

typeconf 'cocos2d::CustomCommand'
    .supercls('cocos2d::RenderCommand')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'CustomCommand()')
    .func(nil, '@using void init(float globalZOrder, const cocos2d::Mat4 &modelViewTransform, unsigned int flags)', 'void init(float globalZOrder)', 'void init(float globalZOrder, const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'void createVertexBuffer(std::size_t vertexSize, std::size_t capacity, cocos2d::CustomCommand::BufferUsage usage)')
    .func(nil, 'void createIndexBuffer(cocos2d::CustomCommand::IndexFormat format, std::size_t capacity, cocos2d::CustomCommand::BufferUsage usage)')
    .func(nil, 'void updateVertexBuffer(void *data, std::size_t length)', 'void updateVertexBuffer(void *data, std::size_t offset, std::size_t length)')
    .func(nil, 'void updateIndexBuffer(void *data, std::size_t length)', 'void updateIndexBuffer(void *data, std::size_t offset, std::size_t length)')
    .func(nil, 'std::size_t getVertexCapacity()')
    .func(nil, 'std::size_t getIndexCapacity()')
    .func(nil, 'void setDrawType(cocos2d::CustomCommand::DrawType drawType)')
    .func(nil, 'cocos2d::CustomCommand::DrawType getDrawType()')
    .func(nil, 'void setPrimitiveType(cocos2d::CustomCommand::PrimitiveType primitiveType)')
    .func(nil, 'cocos2d::CustomCommand::PrimitiveType getPrimitiveType()')
    .func(nil, 'void setVertexBuffer(cocos2d::backend::Buffer *vertexBuffer)')
    .func(nil, 'cocos2d::backend::Buffer *getVertexBuffer()')
    .func(nil, 'void setIndexBuffer(cocos2d::backend::Buffer *indexBuffer, cocos2d::CustomCommand::IndexFormat indexFormat)')
    .func(nil, 'cocos2d::backend::Buffer *getIndexBuffer()')
    .func(nil, 'void setVertexDrawInfo(std::size_t start, std::size_t count)')
    .func(nil, 'std::size_t getVertexDrawStart()')
    .func(nil, 'std::size_t getVertexDrawCount()')
    .func(nil, 'void setIndexDrawInfo(std::size_t start, std::size_t count)')
    .func(nil, 'std::size_t getIndexDrawOffset()')
    .func(nil, 'std::size_t getIndexDrawCount()')
    .func(nil, 'void setLineWidth(float lineWidth)')
    .func(nil, 'float getLineWidth()')
    .func(nil, 'cocos2d::CustomCommand::IndexFormat getIndexFormat()')
    .var('func', '@nullable @local std::function<void ()> func')
    .callback {
        FUNCS =  {
            'void setBeforeCallback(@local const std::function<void ()> &before)'
        },
        TAG_MAKER = 'BeforeCallback',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setAfterCallback(@local const std::function<void ()> &after)'
        },
        TAG_MAKER = 'AfterCallback',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            '@local const std::function<void ()> &getBeforeCallback()'
        },
        TAG_MAKER = 'BeforeCallback',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            '@local const std::function<void ()> &getAfterCallback()'
        },
        TAG_MAKER = 'AfterCallback',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .prop('vertexCapacity', nil, nil)
    .prop('indexCapacity', nil, nil)
    .prop('drawType', nil, nil)
    .prop('primitiveType', nil, nil)
    .prop('vertexBuffer', nil, nil)
    .prop('indexBuffer', nil, nil)
    .prop('vertexDrawStart', nil, nil)
    .prop('vertexDrawCount', nil, nil)
    .prop('indexDrawOffset', nil, nil)
    .prop('indexDrawCount', nil, nil)
    .prop('lineWidth', nil, nil)
    .prop('indexFormat', nil, nil)
    .prop('beforeCallback', nil, nil)
    .prop('afterCallback', nil, nil)

typeconf 'cocos2d::MeshCommand'
    .supercls('cocos2d::CustomCommand')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'MeshCommand()')
    .func(nil, '@using void init(float globalZOrder)', 'void init(float globalZOrder, const cocos2d::Mat4 &transform)')

typeconf 'cocos2d::TextureCache'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk([[
        static const std::string makeTextureCacheCallbackTag(const std::string &key)
        {
            return "addImageAsync." + key;
        }
    ]])
    .require(nil)
    .func(nil, 'static void setETC1AlphaFileSuffix(const std::string &suffix)')
    .func(nil, 'static std::string getETC1AlphaFileSuffix()')
    .func(nil, 'TextureCache()')
    .func(nil, 'std::string getDescription()')
    .func(nil, 'cocos2d::Texture2D *addImage(const std::string &filepath)', 'cocos2d::Texture2D *addImage(cocos2d::Image *image, const std::string &key)')
    .func(nil, 'cocos2d::Texture2D *getTextureForKey(const std::string &key)')
    .func(nil, 'bool reloadTexture(const std::string &fileName)')
    .func(nil, 'void removeAllTextures()')
    .func(nil, 'void removeUnusedTextures()')
    .func(nil, 'void removeTexture(cocos2d::Texture2D *texture)')
    .func(nil, 'void removeTextureForKey(const std::string &key)')
    .func(nil, 'std::string getCachedTextureInfo()')
    .func(nil, 'void waitForQuit()')
    .func(nil, 'std::string getTextureFilePath(cocos2d::Texture2D *texture)')
    .func(nil, 'void renameTextureWithKey(const std::string &srcName, const std::string &dstName)')
    .callback {
        FUNCS =  {
            'void addImageAsync(const std::string &filepath, const std::function<void (Texture2D *)> &callback)',
            'void addImageAsync(const std::string &path, const std::function<void (Texture2D *)> &callback, const std::string &callbackKey)'
        },
        TAG_MAKER = {'makeTextureCacheCallbackTag(#1)', 'makeTextureCacheCallbackTag(#-1)'},
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'void unbindImageAsync(const std::string &filename)'
        },
        TAG_MAKER = 'makeTextureCacheCallbackTag(#1)',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void unbindAllImageAsync()'
        },
        TAG_MAKER = 'makeTextureCacheCallbackTag("")',
        TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .prop('etC1AlphaFileSuffix', nil, nil)
    .prop('description', nil, nil)
    .prop('cachedTextureInfo', nil, nil)

typeconf 'cocos2d::Texture2D'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static void setDefaultAlphaPixelFormat(cocos2d::backend::PixelFormat format)')
    .func(nil, 'static cocos2d::backend::PixelFormat getDefaultAlphaPixelFormat()')
    .func(nil, 'Texture2D()')
    .func(nil, 'bool initWithData(const void *data, ssize_t dataLen, cocos2d::backend::PixelFormat pixelFormat, int pixelsWide, int pixelsHigh, const cocos2d::Size &contentSize, @optional bool preMultipliedAlpha)', 'bool initWithData(const void *data, ssize_t dataLen, cocos2d::backend::PixelFormat pixelFormat, cocos2d::backend::PixelFormat renderFormat, int pixelsWide, int pixelsHigh, const cocos2d::Size &contentSize, @optional bool preMultipliedAlpha)')
    .func(nil, 'bool updateWithData(void *data, int offsetX, int offsetY, int width, int height)')
    .func(nil, 'void drawAtPoint(const cocos2d::Vec2 &point, float globalZOrder)')
    .func(nil, 'void drawInRect(const cocos2d::Rect &rect, float globalZOrder)')
    .func(nil, 'bool initWithImage(cocos2d::Image *image)', 'bool initWithImage(cocos2d::Image *image, cocos2d::backend::PixelFormat format)')
    .func(nil, 'bool initWithString(const char *text, const std::string &fontName, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment, @optional bool enableWrap, @optional int overflow)')
    .func(nil, 'bool initWithBackendTexture(cocos2d::backend::TextureBackend *texture, @optional bool preMultipliedAlpha)')
    .func(nil, 'void setRenderTarget(bool renderTarget)')
    .func(nil, 'bool isRenderTarget()')
    .func(nil, 'void setTexParameters(const cocos2d::Texture2D::TexParams &params)')
    .func(nil, 'void generateMipmap()')
    .func(nil, 'void setAntiAliasTexParameters()')
    .func(nil, 'void setAliasTexParameters()')
    .func(nil, 'const char *getStringForFormat()')
    .func(nil, 'unsigned int getBitsPerPixelForFormat()', 'unsigned int getBitsPerPixelForFormat(cocos2d::backend::PixelFormat format)')
    .func(nil, 'const cocos2d::Size &getContentSizeInPixels()')
    .func(nil, 'bool hasPremultipliedAlpha()')
    .func(nil, 'bool hasMipmaps()')
    .func(nil, 'cocos2d::backend::PixelFormat getPixelFormat()')
    .func(nil, 'int getPixelsWide()')
    .func(nil, 'int getPixelsHigh()')
    .func(nil, 'cocos2d::backend::TextureBackend *getBackendTexture()')
    .func(nil, 'float getMaxS()')
    .func(nil, 'void setMaxS(float maxS)')
    .func(nil, 'float getMaxT()')
    .func(nil, 'void setMaxT(float maxT)')
    .func(nil, 'cocos2d::Size getContentSize()')
    .func(nil, 'std::string getPath()')
    .func(nil, 'void setAlphaTexture(cocos2d::Texture2D *alphaTexture)')
    .func(nil, 'cocos2d::Texture2D *getAlphaTexture()')
    .func(nil, 'bool getAlphaTextureName()')
    .func(nil, 'static const std::map<backend::PixelFormat, const PixelFormatInfo> &getPixelFormatInfoMap()')
    .prop('defaultAlphaPixelFormat', nil, nil)
    .prop('renderTarget', nil, nil)
    .prop('stringForFormat', nil, nil)
    .prop('contentSizeInPixels', nil, nil)
    .prop('pixelFormat', nil, nil)
    .prop('pixelsWide', nil, nil)
    .prop('pixelsHigh', nil, nil)
    .prop('backendTexture', nil, nil)
    .prop('maxS', nil, nil)
    .prop('maxT', nil, nil)
    .prop('contentSize', nil, nil)
    .prop('path', nil, nil)
    .prop('alphaTexture', nil, nil)
    .prop('alphaTextureName', nil, nil)
    .prop('pixelFormatInfoMap', nil, nil)

typeconf 'cocos2d::TextureCube'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TextureCube *create(const std::string &positive_x, const std::string &negative_x, const std::string &positive_y, const std::string &negative_y, const std::string &positive_z, const std::string &negative_z)')
    .func(nil, 'void setTexParameters(const cocos2d::Texture2D::TexParams &)')
    .func(nil, 'cocos2d::backend::TextureBackend *getBackendTexture()')
    .func(nil, 'bool reloadTexture()')
    .func(nil, 'TextureCube()')
    .prop('backendTexture', nil, nil)

typeconf 'cocos2d::TextureAtlas'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TextureAtlas *create(const std::string &file, ssize_t capacity)')
    .func(nil, 'static cocos2d::TextureAtlas *createWithTexture(cocos2d::Texture2D *texture, ssize_t capacity)')
    .func(nil, 'TextureAtlas()')
    .func(nil, 'bool initWithFile(const std::string &file, ssize_t capacity)')
    .func(nil, 'bool initWithTexture(cocos2d::Texture2D *texture, ssize_t capacity)')
    .func(nil, 'void insertQuadFromIndex(ssize_t fromIndex, ssize_t newIndex)')
    .func(nil, 'void removeQuadAtIndex(ssize_t index)')
    .func(nil, 'void removeQuadsAtIndex(ssize_t index, ssize_t amount)')
    .func(nil, 'void removeAllQuads()')
    .func(nil, 'bool resizeCapacity(ssize_t capacity)')
    .func(nil, 'void increaseTotalQuadsWith(ssize_t amount)')
    .func(nil, 'void moveQuadsFromIndex(ssize_t oldIndex, ssize_t amount, ssize_t newIndex)', 'void moveQuadsFromIndex(ssize_t index, ssize_t newIndex)')
    .func(nil, 'void fillWithEmptyQuadsFromIndex(ssize_t index, ssize_t amount)')
    .func(nil, 'bool isDirty()')
    .func(nil, 'void setDirty(bool bDirty)')
    .func(nil, 'std::string getDescription()')
    .func(nil, 'size_t getTotalQuads()')
    .func(nil, 'size_t getCapacity()')
    .func(nil, 'cocos2d::Texture2D *getTexture()')
    .func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
    .prop('dirty', nil, nil)
    .prop('description', nil, nil)
    .prop('totalQuads', nil, nil)
    .prop('capacity', nil, nil)
    .prop('texture', nil, nil)

typeconf 'cocos2d::network::WebSocket::ErrorCode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('TIME_OUT', 'cocos2d::network::WebSocket::ErrorCode::TIME_OUT')
    .enum('CONNECTION_FAILURE', 'cocos2d::network::WebSocket::ErrorCode::CONNECTION_FAILURE')
    .enum('UNKNOWN', 'cocos2d::network::WebSocket::ErrorCode::UNKNOWN')

typeconf 'cocos2d::network::WebSocket::State'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('CONNECTING', 'cocos2d::network::WebSocket::State::CONNECTING')
    .enum('OPEN', 'cocos2d::network::WebSocket::State::OPEN')
    .enum('CLOSING', 'cocos2d::network::WebSocket::State::CLOSING')
    .enum('CLOSED', 'cocos2d::network::WebSocket::State::CLOSED')

typeconf 'cocos2d::network::WebSocket::Delegate'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void onOpen(cocos2d::network::WebSocket *ws)')
    .func(nil, 'void onMessage(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::Data &data)')
    .func(nil, 'void onClose(cocos2d::network::WebSocket *ws)')
    .func(nil, 'void onError(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::ErrorCode &error)')

typeconf 'cocos2d::network::WebSocket'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func('init', [[
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
    .func(nil, 'static void closeAllConnections()')
    .func(nil, 'WebSocket()')
    .func(nil, 'void send(const std::string &message)', 'void send(const unsigned char *binaryMsg, unsigned int len)')
    .func(nil, 'void close()')
    .func(nil, 'void closeAsync()')
    .func(nil, 'cocos2d::network::WebSocket::State getReadyState()')
    .func(nil, 'const std::string &getUrl()')
    .func(nil, 'const std::string &getProtocol()')
    .prop('readyState', nil, nil)
    .prop('url', nil, nil)
    .prop('protocol', nil, nil)

typeconf 'cocos2d::LuaWebSocketDelegate'
    .supercls('cocos2d::network::WebSocket::Delegate')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'LuaWebSocketDelegate()')
    .var('onOpen', '@nullable @local std::function<void (network::WebSocket *)> onOpenCallback')
    .var('onMessage', '@nullable @local std::function<void (network::WebSocket *, const network::WebSocket::Data &)> onMessageCallback')
    .var('onClose', '@nullable @local std::function<void (network::WebSocket *)> onCloseCallback')
    .var('onError', '@nullable @local std::function<void (network::WebSocket *, const network::WebSocket::ErrorCode &)> onErrorCallback')

typeconf 'cocos2d::ActionManager'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'ActionManager()')
    .func(nil, 'void addAction(cocos2d::Action *action, cocos2d::Node *target, bool paused)')
    .func(nil, 'void removeAllActions()')
    .func(nil, 'void removeAllActionsFromTarget(cocos2d::Node *target)')
    .func(nil, 'void removeAction(cocos2d::Action *action)')
    .func(nil, 'void removeActionByTag(int tag, cocos2d::Node *target)')
    .func(nil, 'void removeAllActionsByTag(int tag, cocos2d::Node *target)')
    .func(nil, 'void removeActionsByFlags(unsigned int flags, cocos2d::Node *target)')
    .func(nil, 'cocos2d::Action *getActionByTag(int tag, const cocos2d::Node *target)')
    .func(nil, 'ssize_t getNumberOfRunningActionsInTarget(const cocos2d::Node *target)')
    .func(nil, 'ssize_t getNumberOfRunningActions()')
    .func(nil, 'size_t getNumberOfRunningActionsInTargetByTag(const cocos2d::Node *target, int tag)')
    .func(nil, 'void pauseTarget(cocos2d::Node *target)')
    .func(nil, 'void resumeTarget(cocos2d::Node *target)')
    .func(nil, 'Vector<cocos2d::Node *> pauseAllRunningActions()')
    .func(nil, 'void resumeTargets(const Vector<cocos2d::Node *> &targetsToResume)')
    .func(nil, 'void update(float dt)')
    .prop('numberOfRunningActions', nil, nil)

typeconf 'cocos2d::Component'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Component *create()')
    .func(nil, 'bool init()')
    .func(nil, 'bool isEnabled()')
    .func(nil, 'void setEnabled(bool enabled)')
    .func(nil, 'const std::string &getName()')
    .func(nil, 'void setName(const std::string &name)')
    .func(nil, 'cocos2d::Node *getOwner()')
    .func(nil, 'void setOwner(cocos2d::Node *owner)')
    .func(nil, 'void update(float delta)')
    .func(nil, 'bool serialize(void *r)')
    .func(nil, 'void onEnter()')
    .func(nil, 'void onExit()')
    .func(nil, 'void onAdd()')
    .func(nil, 'void onRemove()')
    .func(nil, 'Component()')
    .prop('enabled', nil, nil)
    .prop('name', nil, nil)
    .prop('owner', nil, nil)

typeconf 'cocos2d::LuaComponent'
    .supercls('cocos2d::Component')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::LuaComponent *create()')
    .func(nil, 'LuaComponent()')
    .var('onUpdate', '@nullable @local std::function<void (float)> onUpdateCallback')
    .var('onEnter', '@nullable @local std::function<void ()> onEnterCallback')
    .var('onExit', '@nullable @local std::function<void ()> onExitCallback')
    .var('onAdd', '@nullable @local std::function<void ()> onAddCallback')
    .var('onRemove', '@nullable @local std::function<void ()> onRemoveCallback')

typeconf 'cocos2d::Node'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk([[
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
    ]])
    .require(nil)
    .const('INVALID_TAG', 'cocos2d::Node::INVALID_TAG', 'const int')
    .func('__index', [[
        {
            auto self = olua_toobj<cocos2d::Node>(L, 1);
            if (olua_isstring(L, 2)) {
                cocos2d::Node *child = self->getChildByName(olua_tostring(L, 2));
                if (child) {
                    olua_pushobj<cocos2d::Node>(L, child);
                    olua_addref(L, 1, "children", -1, OLUA_MODE_MULTIPLE);
                    return 1;
                }
            }
            lua_settop(L, 2);
            olua_getvariable(L, 1);
            return 1;
        }
    ]])
    .func('getBounds', [[
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
    .func(nil, 'static cocos2d::Node *create()')
    .func(nil, 'static int getAttachedNodeCount()')
    .func(nil, 'std::string getDescription()')
    .func(nil, 'void setLocalZOrder(std::int32_t localZOrder)')
    .func(nil, 'void updateOrderOfArrival()')
    .func(nil, 'std::int32_t getLocalZOrder()')
    .func(nil, 'void setGlobalZOrder(float globalZOrder)')
    .func(nil, 'float getGlobalZOrder()')
    .func(nil, 'void setScaleX(float scaleX)')
    .func(nil, 'float getScaleX()')
    .func(nil, 'void setScaleY(float scaleY)')
    .func(nil, 'float getScaleY()')
    .func(nil, 'void setScaleZ(float scaleZ)')
    .func(nil, 'float getScaleZ()')
    .func(nil, 'void setScale(float scale)', 'void setScale(float scaleX, float scaleY)')
    .func(nil, 'float getScale()')
    .func(nil, 'void setPosition(const cocos2d::Vec2 &position)', 'void setPosition(float x, float y)')
    .func(nil, 'void setPositionNormalized(const cocos2d::Vec2 &position)')
    .func(nil, 'void setNormalizedPosition(const cocos2d::Vec2 &position)')
    .func(nil, 'const cocos2d::Vec2 &getPosition()')
    .func(nil, 'const cocos2d::Vec2 &getPositionNormalized()')
    .func(nil, 'const cocos2d::Vec2 &getNormalizedPosition()')
    .func(nil, 'void setPositionX(float x)')
    .func(nil, 'float getPositionX()')
    .func(nil, 'void setPositionY(float y)')
    .func(nil, 'float getPositionY()')
    .func(nil, 'void setPosition3D(const cocos2d::Vec3 &position)')
    .func(nil, 'cocos2d::Vec3 getPosition3D()')
    .func(nil, 'void setPositionZ(float positionZ)')
    .func(nil, 'float getPositionZ()')
    .func(nil, 'void setSkewX(float skewX)')
    .func(nil, 'float getSkewX()')
    .func(nil, 'void setSkewY(float skewY)')
    .func(nil, 'float getSkewY()')
    .func(nil, 'void setAnchorPoint(const cocos2d::Vec2 &anchorPoint)')
    .func(nil, 'const cocos2d::Vec2 &getAnchorPoint()')
    .func(nil, 'const cocos2d::Vec2 &getAnchorPointInPoints()')
    .func(nil, 'void setContentSize(const cocos2d::Size &contentSize)')
    .func(nil, 'const cocos2d::Size &getContentSize()')
    .func(nil, 'void setVisible(bool visible)')
    .func(nil, 'bool isVisible()')
    .func(nil, 'void setRotation(float rotation)')
    .func(nil, 'float getRotation()')
    .func(nil, 'void setRotation3D(const cocos2d::Vec3 &rotation)')
    .func(nil, 'cocos2d::Vec3 getRotation3D()')
    .func(nil, 'void setRotationQuat(const cocos2d::Quaternion &quat)')
    .func(nil, 'cocos2d::Quaternion getRotationQuat()')
    .func(nil, 'void setRotationSkewX(float rotationX)')
    .func(nil, 'float getRotationSkewX()')
    .func(nil, 'void setRotationSkewY(float rotationY)')
    .func(nil, 'float getRotationSkewY()')
    .func(nil, 'void setIgnoreAnchorPointForPosition(bool ignore)')
    .func(nil, 'bool isIgnoreAnchorPointForPosition()')
    .func(nil, 'void addChild(@addref(children |) cocos2d::Node *child)', 'void addChild(@addref(children |) cocos2d::Node *child, int localZOrder)', 'void addChild(@addref(children |) cocos2d::Node *child, int localZOrder, int tag)', 'void addChild(@addref(children |) cocos2d::Node *child, int localZOrder, const std::string &name)')
    .func(nil, '@addref(children |) cocos2d::Node *getChildByTag(int tag)')
    .func(nil, '@addref(children |) cocos2d::Node *getChildByName(const std::string &name)')
    .func(nil, '@addref(children |) Vector<cocos2d::Node *> &getChildren()')
    .func(nil, 'ssize_t getChildrenCount()')
    .func(nil, 'void setParent(cocos2d::Node *parent)')
    .func(nil, 'cocos2d::Node *getParent()')
    .func(nil, '@delref(children | parent) void removeFromParent()')
    .func(nil, '@delref(children | parent) void removeFromParentAndCleanup(bool cleanup)')
    .func(nil, 'void removeChild(@delref(children |) cocos2d::Node *child, @optional bool cleanup)')
    .func(nil, '@delref(children ~) void removeChildByTag(int tag, @optional bool cleanup)')
    .func(nil, '@delref(children ~) void removeChildByName(const std::string &name, @optional bool cleanup)')
    .func(nil, '@delref(children *) void removeAllChildren()')
    .func(nil, '@delref(children *) void removeAllChildrenWithCleanup(bool cleanup)')
    .func(nil, 'void reorderChild(cocos2d::Node *child, int localZOrder)')
    .func(nil, 'void sortAllChildren()')
    .func(nil, 'int getTag()')
    .func(nil, 'void setTag(int tag)')
    .func(nil, 'const std::string &getName()')
    .func(nil, 'void setName(const std::string &name)')
    .func(nil, 'void *getUserData()')
    .func(nil, 'void setUserData(void *userData)')
    .func(nil, 'cocos2d::Ref *getUserObject()')
    .func(nil, 'void setUserObject(cocos2d::Ref *userObject)')
    .func(nil, 'bool isRunning()')
    .func(nil, 'void onEnter()')
    .func(nil, 'void onEnterTransitionDidFinish()')
    .func(nil, 'void onExit()')
    .func(nil, 'void onExitTransitionDidStart()')
    .func(nil, 'void cleanup()')
    .func(nil, 'void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)', 'void draw()')
    .func(nil, 'void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags)', 'void visit()')
    .func(nil, 'cocos2d::Scene *getScene()')
    .func(nil, 'cocos2d::Rect getBoundingBox()')
    .func(nil, 'void setEventDispatcher(@addref(eventDispatcher ^) cocos2d::EventDispatcher *dispatcher)')
    .func(nil, '@addref(eventDispatcher ^) cocos2d::EventDispatcher *getEventDispatcher()')
    .func(nil, 'void setActionManager(@addref(actionManager ^) cocos2d::ActionManager *actionManager)')
    .func(nil, '@addref(actionManager ^) cocos2d::ActionManager *getActionManager()')
    .func(nil, '@delref(actions ~) cocos2d::Action *runAction(@addref(actions |) cocos2d::Action *action)')
    .func(nil, '@delref(actions ~) void stopAllActions()')
    .func(nil, '@delref(actions ~) void stopAction(cocos2d::Action *action)')
    .func(nil, '@delref(actions ~) void stopActionByTag(int tag)')
    .func(nil, '@delref(actions ~) void stopAllActionsByTag(int tag)')
    .func(nil, '@delref(actions ~) void stopActionsByFlags(unsigned int flags)')
    .func(nil, '@addref(actions |) cocos2d::Action *getActionByTag(int tag)')
    .func(nil, 'ssize_t getNumberOfRunningActions()')
    .func(nil, 'ssize_t getNumberOfRunningActionsByTag(int tag)')
    .func(nil, 'void setScheduler(@addref(scheduler ^) cocos2d::Scheduler *scheduler)')
    .func(nil, '@addref(scheduler ^) cocos2d::Scheduler *getScheduler()')
    .func(nil, 'bool isScheduled(const std::string &key)')
    .func(nil, 'void scheduleUpdate()')
    .func(nil, 'void scheduleUpdateWithPriority(int priority)')
    .func(nil, 'void unscheduleUpdate()')
    .func(nil, 'void resume()')
    .func(nil, 'void pause()')
    .func(nil, 'void update(float delta)')
    .func(nil, 'void updateTransform()')
    .func(nil, 'const cocos2d::Mat4 &getNodeToParentTransform()', 'cocos2d::Mat4 getNodeToParentTransform(cocos2d::Node *ancestor)')
    .func(nil, 'cocos2d::AffineTransform getNodeToParentAffineTransform()', 'cocos2d::AffineTransform getNodeToParentAffineTransform(cocos2d::Node *ancestor)')
    .func(nil, 'void setNodeToParentTransform(const cocos2d::Mat4 &transform)')
    .func(nil, 'const cocos2d::Mat4 &getParentToNodeTransform()')
    .func(nil, 'cocos2d::AffineTransform getParentToNodeAffineTransform()')
    .func(nil, 'cocos2d::Mat4 getNodeToWorldTransform()')
    .func(nil, 'cocos2d::AffineTransform getNodeToWorldAffineTransform()')
    .func(nil, 'cocos2d::Mat4 getWorldToNodeTransform()')
    .func(nil, 'cocos2d::AffineTransform getWorldToNodeAffineTransform()')
    .func(nil, 'cocos2d::Vec2 convertToNodeSpace(@pack const cocos2d::Vec2 &worldPoint)')
    .func(nil, 'cocos2d::Vec2 convertToWorldSpace(@pack const cocos2d::Vec2 &nodePoint)')
    .func(nil, 'cocos2d::Vec2 convertToNodeSpaceAR(@pack const cocos2d::Vec2 &worldPoint)')
    .func(nil, 'cocos2d::Vec2 convertToWorldSpaceAR(@pack const cocos2d::Vec2 &nodePoint)')
    .func(nil, 'cocos2d::Vec2 convertTouchToNodeSpace(cocos2d::Touch *touch)')
    .func(nil, 'cocos2d::Vec2 convertTouchToNodeSpaceAR(cocos2d::Touch *touch)')
    .func(nil, 'void setAdditionalTransform(const cocos2d::Mat4 &additionalTransform)', 'void setAdditionalTransform(const cocos2d::AffineTransform &additionalTransform)')
    .func(nil, '@addref(components |) cocos2d::Component *getComponent(const std::string &name)')
    .func(nil, 'bool addComponent(@addref(components |) cocos2d::Component *component)')
    .func(nil, '@delref(components ~) bool removeComponent(const std::string &name)', '@delref(components ~) bool removeComponent(cocos2d::Component *component)')
    .func(nil, '@delref(components *) void removeAllComponents()')
    .func(nil, 'uint8_t getOpacity()')
    .func(nil, 'uint8_t getDisplayedOpacity()')
    .func(nil, 'void setOpacity(uint8_t opacity)')
    .func(nil, 'void updateDisplayedOpacity(uint8_t parentOpacity)')
    .func(nil, 'bool isCascadeOpacityEnabled()')
    .func(nil, 'void setCascadeOpacityEnabled(bool cascadeOpacityEnabled)')
    .func(nil, 'const cocos2d::Color3B &getColor()')
    .func(nil, 'const cocos2d::Color3B &getDisplayedColor()')
    .func(nil, 'void setColor(const cocos2d::Color3B &color)')
    .func(nil, 'void updateDisplayedColor(const cocos2d::Color3B &parentColor)')
    .func(nil, 'bool isCascadeColorEnabled()')
    .func(nil, 'void setCascadeColorEnabled(bool cascadeColorEnabled)')
    .func(nil, 'void setOpacityModifyRGB(bool value)')
    .func(nil, 'bool isOpacityModifyRGB()')
    .func(nil, 'unsigned short getCameraMask()')
    .func(nil, 'void setCameraMask(unsigned short mask, @optional bool applyChildren)')
    .func(nil, 'void setProgramState(@addref(programState ^) cocos2d::backend::ProgramState *programState)')
    .func(nil, '@addref(programState ^) cocos2d::backend::ProgramState *getProgramState()')
    .func(nil, 'Node()')
    .func(nil, 'bool init()')
    .func(nil, 'void setPhysicsBody(@addref(physicsBody ^) cocos2d::PhysicsBody *physicsBody)')
    .func(nil, '@addref(physicsBody ^) cocos2d::PhysicsBody *getPhysicsBody()')
    .callback {
        FUNCS =  {
            'void setOnEnterCallback(@nullable @local const std::function<void ()> &callback)'
        },
        TAG_MAKER = 'OnEnterCallback',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            '@nullable @local const std::function<void ()> &getOnEnterCallback()'
        },
        TAG_MAKER = 'OnEnterCallback',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setOnExitCallback(@nullable @local const std::function<void ()> &callback)'
        },
        TAG_MAKER = 'OnExitCallback',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            '@nullable @local const std::function<void ()> &getOnExitCallback()'
        },
        TAG_MAKER = 'OnExitCallback',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setOnEnterTransitionDidFinishCallback(@nullable @local const std::function<void ()> &callback)'
        },
        TAG_MAKER = 'OnEnterTransitionDidFinishCallback',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            '@nullable @local const std::function<void ()> &getOnEnterTransitionDidFinishCallback()'
        },
        TAG_MAKER = 'OnEnterTransitionDidFinishCallback',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setOnExitTransitionDidStartCallback(@nullable @local const std::function<void ()> &callback)'
        },
        TAG_MAKER = 'OnExitTransitionDidStartCallback',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            '@nullable @local const std::function<void ()> &getOnExitTransitionDidStartCallback()'
        },
        TAG_MAKER = 'OnExitTransitionDidStartCallback',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void scheduleOnce(@local const std::function<void (float)> &callback, float delay, const std::string &key)'
        },
        TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
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
    .callback {
        FUNCS =  {
            'void unschedule(const std::string &key)'
        },
        TAG_MAKER = 'makeScheduleCallbackTag(#1)',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void unscheduleAllCallbacks()'
        },
        TAG_MAKER = 'makeScheduleCallbackTag("")',
        TAG_MODE = 'OLUA_TAG_SUBSTARTWITH',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void enumerateChildren(const std::string &name, @local std::function<bool (cocos2d::Node *)> callback)'
        },
        TAG_MAKER = 'enumerateChildren',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'function',
    }
    .prop('x', 'float getPositionX()', 'void setPositionX(float x)')
    .prop('y', 'float getPositionY()', 'void setPositionY(float y)')
    .prop('z', 'float getPositionZ()', 'void setPositionZ(float z)')
    .prop('anchorX', [[
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
    .prop('anchorY', [[
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
    .prop('width', [[
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
    .prop('height', [[
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
    .prop('alpha', [[
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
    .prop('attachedNodeCount', nil, nil)
    .prop('description', nil, nil)
    .prop('localZOrder', nil, nil)
    .prop('globalZOrder', nil, nil)
    .prop('scaleX', nil, nil)
    .prop('scaleY', nil, nil)
    .prop('scaleZ', nil, nil)
    .prop('scale', nil, nil)
    .prop('position', nil, nil)
    .prop('positionNormalized', nil, nil)
    .prop('normalizedPosition', nil, nil)
    .prop('positionX', nil, nil)
    .prop('positionY', nil, nil)
    .prop('position3D', nil, nil)
    .prop('positionZ', nil, nil)
    .prop('skewX', nil, nil)
    .prop('skewY', nil, nil)
    .prop('anchorPoint', nil, nil)
    .prop('anchorPointInPoints', nil, nil)
    .prop('contentSize', nil, nil)
    .prop('visible', nil, nil)
    .prop('rotation', nil, nil)
    .prop('rotation3D', nil, nil)
    .prop('rotationQuat', nil, nil)
    .prop('rotationSkewX', nil, nil)
    .prop('rotationSkewY', nil, nil)
    .prop('ignoreAnchorPointForPosition', nil, nil)
    .prop('children', nil, nil)
    .prop('childrenCount', nil, nil)
    .prop('parent', nil, nil)
    .prop('tag', nil, nil)
    .prop('name', nil, nil)
    .prop('userData', nil, nil)
    .prop('userObject', nil, nil)
    .prop('running', nil, nil)
    .prop('scene', nil, nil)
    .prop('boundingBox', nil, nil)
    .prop('eventDispatcher', nil, nil)
    .prop('actionManager', nil, nil)
    .prop('numberOfRunningActions', nil, nil)
    .prop('scheduler', nil, nil)
    .prop('parentToNodeTransform', nil, nil)
    .prop('parentToNodeAffineTransform', nil, nil)
    .prop('nodeToWorldTransform', nil, nil)
    .prop('nodeToWorldAffineTransform', nil, nil)
    .prop('worldToNodeTransform', nil, nil)
    .prop('worldToNodeAffineTransform', nil, nil)
    .prop('opacity', nil, nil)
    .prop('displayedOpacity', nil, nil)
    .prop('cascadeOpacityEnabled', nil, nil)
    .prop('color', nil, nil)
    .prop('displayedColor', nil, nil)
    .prop('cascadeColorEnabled', nil, nil)
    .prop('opacityModifyRGB', nil, nil)
    .prop('onEnterCallback', nil, nil)
    .prop('onExitCallback', nil, nil)
    .prop('onEnterTransitionDidFinishCallback', nil, nil)
    .prop('onExitTransitionDidStartCallback', nil, nil)
    .prop('cameraMask', nil, nil)
    .prop('programState', nil, nil)
    .prop('physicsBody', nil, nil)
    .insert('removeFromParent', {
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
    .insert('removeFromParentAndCleanup', {
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
    .insert('onEnter', {
        BEFORE = [[
            if (!self->getParent()) {
                luaL_error(L, "parent is nullptr");
            }
        ]],
        AFTER = nil,
        CALLBACK_BEFORE = nil,
        CALLBACK_AFTER = nil,
    })
    .insert('onExit', {
        BEFORE = [[
            if (!self->getParent()) {
                luaL_error(L, "parent is nullptr");
            }
        ]],
        AFTER = nil,
        CALLBACK_BEFORE = nil,
        CALLBACK_AFTER = nil,
    })

typeconf 'cocos2d::LuaTweenNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void updateTweenAction(float value, const std::string &key)')
    .callback {
        FUNCS =  {
            'static cocos2d::LuaTweenNode *create(@local const std::function<void (float, const std::string &)> &callback)'
        },
        TAG_MAKER = 'ActionTween',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = "return",
        TAG_SCOPE = 'object',
    }

typeconf 'cocos2d::AtlasNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::AtlasNode *create(const std::string &filename, int tileWidth, int tileHeight, int itemsToRender)')
    .func(nil, 'void updateAtlasValues()')
    .func(nil, 'cocos2d::Texture2D *getTexture()')
    .func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'void setTextureAtlas(cocos2d::TextureAtlas *textureAtlas)')
    .func(nil, 'cocos2d::TextureAtlas *getTextureAtlas()')
    .func(nil, 'void setQuadsToDraw(ssize_t quadsToDraw)')
    .func(nil, 'size_t getQuadsToDraw()')
    .func(nil, 'AtlasNode()')
    .func(nil, 'bool initWithTileFile(const std::string &tile, int tileWidth, int tileHeight, int itemsToRender)')
    .func(nil, 'bool initWithTexture(cocos2d::Texture2D *texture, int tileWidth, int tileHeight, int itemsToRender)')
    .prop('texture', nil, nil)
    .prop('blendFunc', nil, nil)
    .prop('textureAtlas', nil, nil)
    .prop('quadsToDraw', nil, nil)

typeconf 'cocos2d::sImageTGA'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .var('status', 'int status')
    .var('type', 'unsigned char type')
    .var('pixelDepth', 'unsigned char pixelDepth')
    .var('width', 'short width')
    .var('height', 'short height')
    .var('imageData', 'unsigned char *imageData')
    .var('flipped', 'int flipped')

typeconf 'cocos2d::TileMapAtlas'
    .supercls('cocos2d::AtlasNode')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TileMapAtlas *create(const std::string &tile, const std::string &mapFile, int tileWidth, int tileHeight)')
    .func(nil, 'TileMapAtlas()')
    .func(nil, 'bool initWithTileFile(const std::string &tile, const std::string &mapFile, int tileWidth, int tileHeight)')
    .func(nil, 'cocos2d::Color3B getTileAt(const cocos2d::Vec2 &position)')
    .func(nil, 'void setTile(const cocos2d::Color3B &tile, const cocos2d::Vec2 &position)')
    .func(nil, 'void releaseMap()')
    .func(nil, 'struct cocos2d::sImageTGA *getTGAInfo()')
    .func(nil, 'void setTGAInfo(struct cocos2d::sImageTGA *TGAInfo)')
    .prop('tgaInfo', nil, nil)

typeconf 'cocos2d::ClippingNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ClippingNode *create()', 'static cocos2d::ClippingNode *create(cocos2d::Node *stencil)')
    .func(nil, 'cocos2d::Node *getStencil()')
    .func(nil, 'void setStencil(cocos2d::Node *stencil)')
    .func(nil, 'bool hasContent()')
    .func(nil, 'float getAlphaThreshold()')
    .func(nil, 'void setAlphaThreshold(float alphaThreshold)')
    .func(nil, 'bool isInverted()')
    .func(nil, 'void setInverted(bool inverted)')
    .func(nil, 'ClippingNode()')
    .func(nil, '@using bool init()', 'bool init(cocos2d::Node *stencil)')
    .prop('stencil', nil, nil)
    .prop('alphaThreshold', nil, nil)
    .prop('inverted', nil, nil)

typeconf 'cocos2d::MotionStreak'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::MotionStreak *create(float timeToFade, float minSeg, float strokeWidth, const cocos2d::Color3B &strokeColor, const std::string &imagePath)', 'static cocos2d::MotionStreak *create(float timeToFade, float minSeg, float strokeWidth, const cocos2d::Color3B &strokeColor, cocos2d::Texture2D *texture)')
    .func(nil, 'cocos2d::Texture2D *getTexture()')
    .func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'void tintWithColor(const cocos2d::Color3B &colors)')
    .func(nil, 'void reset()')
    .func(nil, 'bool isFastMode()')
    .func(nil, 'void setFastMode(bool bFastMode)')
    .func(nil, 'float getStroke()')
    .func(nil, 'void setStroke(float stroke)')
    .func(nil, 'bool isStartingPositionInitialized()')
    .func(nil, 'void setStartingPositionInitialized(bool bStartingPositionInitialized)')
    .func(nil, 'MotionStreak()')
    .func(nil, 'bool initWithFade(float fade, float minSeg, float stroke, const cocos2d::Color3B &color, const std::string &path)', 'bool initWithFade(float fade, float minSeg, float stroke, const cocos2d::Color3B &color, cocos2d::Texture2D *texture)')
    .prop('texture', nil, nil)
    .prop('blendFunc', nil, nil)
    .prop('fastMode', nil, nil)
    .prop('stroke', nil, nil)
    .prop('startingPositionInitialized', nil, nil)

typeconf 'cocos2d::ProtectedNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ProtectedNode *create()')
    .func(nil, 'void addProtectedChild(@addref(protectedChildren |) cocos2d::Node *child)', 'void addProtectedChild(@addref(protectedChildren |) cocos2d::Node *child, int localZOrder)', 'void addProtectedChild(@addref(protectedChildren |) cocos2d::Node *child, int localZOrder, int tag)')
    .func(nil, '@addref(protectedChildren |) cocos2d::Node *getProtectedChildByTag(int tag)')
    .func(nil, 'void removeProtectedChild(@delref(protectedChildren |) cocos2d::Node *child, @optional bool cleanup)')
    .func(nil, '@delref(protectedChildren ~) void removeProtectedChildByTag(int tag, @optional bool cleanup)')
    .func(nil, '@delref(protectedChildren *) void removeAllProtectedChildren()')
    .func(nil, '@delref(protectedChildren *) void removeAllProtectedChildrenWithCleanup(bool cleanup)')
    .func(nil, 'void reorderProtectedChild(cocos2d::Node *child, int localZOrder)')
    .func(nil, 'void sortAllProtectedChildren()')
    .func(nil, 'void disableCascadeColor()')
    .func(nil, 'void disableCascadeOpacity()')
    .func(nil, 'ProtectedNode()')

typeconf 'cocos2d::DrawNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::DrawNode *create(@optional float defaultLineWidth)')
    .func(nil, 'void drawPoint(const cocos2d::Vec2 &point, const float pointSize, const cocos2d::Color4F &color)')
    .func(nil, 'void drawLine(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &destination, const cocos2d::Color4F &color)')
    .func(nil, 'void drawRect(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &destination, const cocos2d::Color4F &color)', 'void drawRect(const cocos2d::Vec2 &p1, const cocos2d::Vec2 &p2, const cocos2d::Vec2 &p3, const cocos2d::Vec2 &p4, const cocos2d::Color4F &color)')
    .func(nil, 'void drawCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, bool drawLineToCenter, float scaleX, float scaleY, const cocos2d::Color4F &color)', 'void drawCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, bool drawLineToCenter, const cocos2d::Color4F &color)')
    .func(nil, 'void drawQuadBezier(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &control, const cocos2d::Vec2 &destination, unsigned int segments, const cocos2d::Color4F &color)')
    .func(nil, 'void drawCubicBezier(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &control1, const cocos2d::Vec2 &control2, const cocos2d::Vec2 &destination, unsigned int segments, const cocos2d::Color4F &color)')
    .func(nil, 'void drawCardinalSpline(cocos2d::PointArray *config, float tension, unsigned int segments, const cocos2d::Color4F &color)')
    .func(nil, 'void drawCatmullRom(cocos2d::PointArray *points, unsigned int segments, const cocos2d::Color4F &color)')
    .func(nil, 'void drawDot(const cocos2d::Vec2 &pos, float radius, const cocos2d::Color4F &color)')
    .func(nil, 'void drawSolidRect(const cocos2d::Vec2 &origin, const cocos2d::Vec2 &destination, const cocos2d::Color4F &color)')
    .func(nil, 'void drawSolidCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, float scaleX, float scaleY, const cocos2d::Color4F &color)', 'void drawSolidCircle(const cocos2d::Vec2 &center, float radius, float angle, unsigned int segments, const cocos2d::Color4F &color)')
    .func(nil, 'void drawSegment(const cocos2d::Vec2 &from, const cocos2d::Vec2 &to, float radius, const cocos2d::Color4F &color)')
    .func(nil, 'void drawTriangle(const cocos2d::Vec2 &p1, const cocos2d::Vec2 &p2, const cocos2d::Vec2 &p3, const cocos2d::Color4F &color)')
    .func(nil, 'void clear()')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'void setLineWidth(float lineWidth)')
    .func(nil, 'float getLineWidth()')
    .func(nil, 'void setIsolated(bool isolated)')
    .func(nil, 'bool isIsolated()')
    .func(nil, 'DrawNode(@optional float lineWidth)')
    .prop('blendFunc', nil, nil)
    .prop('lineWidth', nil, nil)
    .prop('isolated', nil, nil)

typeconf 'cocos2d::ParallaxNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParallaxNode *create()')
    .func(nil, 'void addChild(@addref(chilren |) cocos2d::Node *child, int z, const cocos2d::Vec2 &parallaxRatio, const cocos2d::Vec2 &positionOffset)', '@using void addChild(@addref(chilren |) cocos2d::Node *child, int zOrder, int tag)', '@using void addChild(@addref(chilren |) cocos2d::Node *child, int zOrder, const std::string &name)', '@using void addChild(@addref(children |) cocos2d::Node *child)', '@using void addChild(@addref(children |) cocos2d::Node *child, int localZOrder)')
    .func(nil, 'ParallaxNode()')

typeconf 'cocos2d::TextHAlignment'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('LEFT', 'cocos2d::TextHAlignment::LEFT')
    .enum('CENTER', 'cocos2d::TextHAlignment::CENTER')
    .enum('RIGHT', 'cocos2d::TextHAlignment::RIGHT')

typeconf 'cocos2d::TextVAlignment'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('TOP', 'cocos2d::TextVAlignment::TOP')
    .enum('CENTER', 'cocos2d::TextVAlignment::CENTER')
    .enum('BOTTOM', 'cocos2d::TextVAlignment::BOTTOM')

typeconf 'cocos2d::GlyphCollection'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('DYNAMIC', 'cocos2d::GlyphCollection::DYNAMIC')
    .enum('NEHE', 'cocos2d::GlyphCollection::NEHE')
    .enum('ASCII', 'cocos2d::GlyphCollection::ASCII')
    .enum('CUSTOM', 'cocos2d::GlyphCollection::CUSTOM')

typeconf 'cocos2d::LabelEffect'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NORMAL', 'cocos2d::LabelEffect::NORMAL')
    .enum('OUTLINE', 'cocos2d::LabelEffect::OUTLINE')
    .enum('SHADOW', 'cocos2d::LabelEffect::SHADOW')
    .enum('GLOW', 'cocos2d::LabelEffect::GLOW')
    .enum('ITALICS', 'cocos2d::LabelEffect::ITALICS')
    .enum('BOLD', 'cocos2d::LabelEffect::BOLD')
    .enum('UNDERLINE', 'cocos2d::LabelEffect::UNDERLINE')
    .enum('STRIKETHROUGH', 'cocos2d::LabelEffect::STRIKETHROUGH')
    .enum('ALL', 'cocos2d::LabelEffect::ALL')

typeconf 'cocos2d::Label::LabelType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('TTF', 'cocos2d::Label::LabelType::TTF')
    .enum('BMFONT', 'cocos2d::Label::LabelType::BMFONT')
    .enum('CHARMAP', 'cocos2d::Label::LabelType::CHARMAP')
    .enum('STRING_TEXTURE', 'cocos2d::Label::LabelType::STRING_TEXTURE')

typeconf 'cocos2d::Label::Overflow'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NONE', 'cocos2d::Label::Overflow::NONE')
    .enum('CLAMP', 'cocos2d::Label::Overflow::CLAMP')
    .enum('SHRINK', 'cocos2d::Label::Overflow::SHRINK')
    .enum('RESIZE_HEIGHT', 'cocos2d::Label::Overflow::RESIZE_HEIGHT')

typeconf 'cocos2d::Label'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Label *create()')
    .func(nil, 'static cocos2d::Label *createWithSystemFont(const std::string &text, const std::string &font, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)')
    .func(nil, 'static cocos2d::Label *createWithTTF(const std::string &text, const std::string &fontFilePath, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)', 'static cocos2d::Label *createWithTTF(const cocos2d::TTFConfig &ttfConfig, const std::string &text, @optional cocos2d::TextHAlignment hAlignment, @optional int maxLineWidth)')
    .func(nil, 'static cocos2d::Label *createWithBMFont(const std::string &bmfontPath, const std::string &text, @optional const cocos2d::TextHAlignment &hAlignment, @optional int maxLineWidth)', 'static cocos2d::Label *createWithBMFont(const std::string &bmfontPath, const std::string &text, const cocos2d::TextHAlignment &hAlignment, int maxLineWidth, const cocos2d::Rect &imageRect, bool imageRotated)', 'static cocos2d::Label *createWithBMFont(const std::string &bmfontPath, const std::string &text, const cocos2d::TextHAlignment &hAlignment, int maxLineWidth, const std::string &subTextureKey)')
    .func(nil, 'static cocos2d::Label *createWithCharMap(const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)', 'static cocos2d::Label *createWithCharMap(cocos2d::Texture2D *texture, int itemWidth, int itemHeight, int startCharMap)', 'static cocos2d::Label *createWithCharMap(const std::string &plistFile)')
    .func(nil, 'bool setTTFConfig(const cocos2d::TTFConfig &ttfConfig)')
    .func(nil, 'const cocos2d::TTFConfig &getTTFConfig()')
    .func(nil, 'bool setBMFontFilePath(const std::string &bmfontFilePath, @optional float fontSize)', 'bool setBMFontFilePath(const std::string &bmfontFilePath, const cocos2d::Rect &imageRect, bool imageRotated, @optional float fontSize)', 'bool setBMFontFilePath(const std::string &bmfontFilePath, const std::string &subTextureKey, @optional float fontSize)')
    .func(nil, 'const std::string &getBMFontFilePath()')
    .func(nil, 'bool setCharMap(const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)', 'bool setCharMap(cocos2d::Texture2D *texture, int itemWidth, int itemHeight, int startCharMap)', 'bool setCharMap(const std::string &plistFile)')
    .func(nil, 'void setSystemFontName(const std::string &font)')
    .func(nil, 'const std::string &getSystemFontName()')
    .func(nil, 'void setSystemFontSize(float fontSize)')
    .func(nil, 'float getSystemFontSize()')
    .func(nil, 'void requestSystemFontRefresh()')
    .func(nil, 'void setString(const std::string &text)')
    .func(nil, 'const std::string &getString()')
    .func(nil, 'int getStringNumLines()')
    .func(nil, 'int getStringLength()')
    .func(nil, 'void setTextColor(const cocos2d::Color4B &color)')
    .func(nil, 'const cocos2d::Color4B &getTextColor()')
    .func(nil, 'void enableShadow(@optional const cocos2d::Color4B &shadowColor, @optional const cocos2d::Size &offset, @optional int blurRadius)')
    .func(nil, 'void enableOutline(const cocos2d::Color4B &outlineColor, @optional int outlineSize)')
    .func(nil, 'void enableGlow(const cocos2d::Color4B &glowColor)')
    .func(nil, 'void enableItalics()')
    .func(nil, 'void enableBold()')
    .func(nil, 'void enableUnderline()')
    .func(nil, 'void enableStrikethrough()')
    .func(nil, 'void disableEffect()', 'void disableEffect(cocos2d::LabelEffect effect)')
    .func(nil, 'bool isShadowEnabled()')
    .func(nil, 'cocos2d::Size getShadowOffset()')
    .func(nil, 'float getShadowBlurRadius()')
    .func(nil, 'cocos2d::Color4F getShadowColor()')
    .func(nil, 'float getOutlineSize()')
    .func(nil, 'cocos2d::LabelEffect getLabelEffectType()')
    .func(nil, 'cocos2d::Color4F getEffectColor()')
    .func(nil, 'void setAlignment(cocos2d::TextHAlignment hAlignment)', 'void setAlignment(cocos2d::TextHAlignment hAlignment, cocos2d::TextVAlignment vAlignment)')
    .func(nil, 'cocos2d::TextHAlignment getTextAlignment()')
    .func(nil, 'void setHorizontalAlignment(cocos2d::TextHAlignment hAlignment)')
    .func(nil, 'cocos2d::TextHAlignment getHorizontalAlignment()')
    .func(nil, 'void setVerticalAlignment(cocos2d::TextVAlignment vAlignment)')
    .func(nil, 'cocos2d::TextVAlignment getVerticalAlignment()')
    .func(nil, 'void setLineBreakWithoutSpace(bool breakWithoutSpace)')
    .func(nil, 'void setMaxLineWidth(float maxLineWidth)')
    .func(nil, 'float getMaxLineWidth()')
    .func(nil, 'void setBMFontSize(float fontSize)')
    .func(nil, 'float getBMFontSize()')
    .func(nil, 'void enableWrap(bool enable)')
    .func(nil, 'bool isWrapEnabled()')
    .func(nil, 'void setOverflow(cocos2d::Label::Overflow overflow)')
    .func(nil, 'cocos2d::Label::Overflow getOverflow()')
    .func(nil, 'void setWidth(float width)')
    .func(nil, 'float getWidth()')
    .func(nil, 'void setHeight(float height)')
    .func(nil, 'float getHeight()')
    .func(nil, 'void setDimensions(float width, float height)')
    .func(nil, 'const cocos2d::Size &getDimensions()')
    .func(nil, 'void updateContent()')
    .func(nil, 'cocos2d::Sprite *getLetter(int lettetIndex)')
    .func(nil, 'void setClipMarginEnabled(bool clipEnabled)')
    .func(nil, 'bool isClipMarginEnabled()')
    .func(nil, 'void setLineHeight(float height)')
    .func(nil, 'float getLineHeight()')
    .func(nil, 'void setLineSpacing(float height)')
    .func(nil, 'float getLineSpacing()')
    .func(nil, 'cocos2d::Label::LabelType getLabelType()')
    .func(nil, 'float getRenderingFontSize()')
    .func(nil, 'void setAdditionalKerning(float space)')
    .func(nil, 'float getAdditionalKerning()')
    .func(nil, 'cocos2d::FontAtlas *getFontAtlas()')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'Label(@optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)')
    .func(nil, 'bool initWithTTF(const std::string &text, const std::string &fontFilePath, float fontSize, @optional const cocos2d::Size &dimensions, @optional cocos2d::TextHAlignment hAlignment, @optional cocos2d::TextVAlignment vAlignment)', 'bool initWithTTF(const cocos2d::TTFConfig &ttfConfig, const std::string &text, @optional cocos2d::TextHAlignment hAlignment, @optional int maxLineWidth)')
    .prop('ttfConfig', nil, nil)
    .prop('bmFontFilePath', nil, nil)
    .prop('systemFontName', nil, nil)
    .prop('systemFontSize', nil, nil)
    .prop('string', nil, nil)
    .prop('stringNumLines', nil, nil)
    .prop('stringLength', nil, nil)
    .prop('textColor', nil, nil)
    .prop('shadowEnabled', nil, nil)
    .prop('shadowOffset', nil, nil)
    .prop('shadowBlurRadius', nil, nil)
    .prop('shadowColor', nil, nil)
    .prop('outlineSize', nil, nil)
    .prop('labelEffectType', nil, nil)
    .prop('effectColor', nil, nil)
    .prop('textAlignment', nil, nil)
    .prop('horizontalAlignment', nil, nil)
    .prop('verticalAlignment', nil, nil)
    .prop('maxLineWidth', nil, nil)
    .prop('bmFontSize', nil, nil)
    .prop('wrapEnabled', nil, nil)
    .prop('overflow', nil, nil)
    .prop('width', nil, nil)
    .prop('height', nil, nil)
    .prop('dimensions', nil, nil)
    .prop('clipMarginEnabled', nil, nil)
    .prop('lineHeight', nil, nil)
    .prop('lineSpacing', nil, nil)
    .prop('labelType', nil, nil)
    .prop('renderingFontSize', nil, nil)
    .prop('additionalKerning', nil, nil)
    .prop('fontAtlas', nil, nil)
    .prop('blendFunc', nil, nil)

typeconf 'cocos2d::LabelAtlas'
    .supercls('cocos2d::AtlasNode')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::LabelAtlas *create()', 'static cocos2d::LabelAtlas *create(const std::string &string, const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)', 'static cocos2d::LabelAtlas *create(const std::string &string, const std::string &fntFile)')
    .func(nil, 'bool initWithString(const std::string &string, const std::string &charMapFile, int itemWidth, int itemHeight, int startCharMap)', 'bool initWithString(const std::string &string, const std::string &fntFile)', 'bool initWithString(const std::string &string, cocos2d::Texture2D *texture, int itemWidth, int itemHeight, int startCharMap)')
    .func(nil, 'void setString(const std::string &label)')
    .func(nil, 'const std::string &getString()')
    .func(nil, 'LabelAtlas()')
    .prop('string', nil, nil)

typeconf 'cocos2d::FontAtlas'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('CacheTextureWidth', 'cocos2d::FontAtlas::CacheTextureWidth', 'const int')
    .const('CacheTextureHeight', 'cocos2d::FontAtlas::CacheTextureHeight', 'const int')
    .func(nil, 'void addTexture(cocos2d::Texture2D *texture, int slot)')
    .func(nil, 'float getLineHeight()')
    .func(nil, 'void setLineHeight(float newHeight)')
    .func(nil, 'std::string getFontName()')
    .func(nil, 'cocos2d::Texture2D *getTexture(int slot)')
    .func(nil, 'void listenRendererRecreated(cocos2d::EventCustom *event)')
    .func(nil, 'void purgeTexturesAtlas()')
    .func(nil, 'void setAntiAliasTexParameters()')
    .func(nil, 'void setAliasTexParameters()')
    .var('CMD_PURGE_FONTATLAS', 'static const char *CMD_PURGE_FONTATLAS')
    .var('CMD_RESET_FONTATLAS', 'static const char *CMD_RESET_FONTATLAS')
    .prop('lineHeight', nil, nil)
    .prop('fontName', nil, nil)

typeconf 'cocos2d::ClippingRectangleNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ClippingRectangleNode *create(const cocos2d::Rect &clippingRegion)', 'static cocos2d::ClippingRectangleNode *create()')
    .func(nil, 'const cocos2d::Rect &getClippingRegion()')
    .func(nil, 'void setClippingRegion(const cocos2d::Rect &clippingRegion)')
    .func(nil, 'bool isClippingEnabled()')
    .func(nil, 'void setClippingEnabled(bool enabled)')
    .prop('clippingRegion', nil, nil)
    .prop('clippingEnabled', nil, nil)

typeconf 'cocos2d::RenderTexture'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::RenderTexture *create(int w, int h, cocos2d::backend::PixelFormat format, cocos2d::backend::PixelFormat depthStencilFormat)', 'static cocos2d::RenderTexture *create(int w, int h, cocos2d::backend::PixelFormat format)', 'static cocos2d::RenderTexture *create(int w, int h)')
    .func(nil, 'void begin()')
    .func(nil, 'void beginWithClear(float r, float g, float b, float a)', 'void beginWithClear(float r, float g, float b, float a, float depthValue)', 'void beginWithClear(float r, float g, float b, float a, float depthValue, int stencilValue)')
    .func(nil, 'void end()')
    .func(nil, 'void clear(float r, float g, float b, float a)')
    .func(nil, 'void clearDepth(float depthValue)')
    .func(nil, 'void clearStencil(int stencilValue)')
    .func(nil, 'void listenToBackground(cocos2d::EventCustom *event)')
    .func(nil, 'void listenToForeground(cocos2d::EventCustom *event)')
    .func(nil, 'cocos2d::ClearFlag getClearFlags()')
    .func(nil, 'void setClearFlags(cocos2d::ClearFlag clearFlags)')
    .func(nil, 'const cocos2d::Color4F &getClearColor()')
    .func(nil, 'void setClearColor(const cocos2d::Color4F &clearColor)')
    .func(nil, 'float getClearDepth()')
    .func(nil, 'void setClearDepth(float clearDepth)')
    .func(nil, 'int getClearStencil()')
    .func(nil, 'void setClearStencil(int clearStencil)')
    .func(nil, 'bool isAutoDraw()')
    .func(nil, 'void setAutoDraw(bool isAutoDraw)')
    .func(nil, 'cocos2d::Sprite *getSprite()')
    .func(nil, 'void setSprite(cocos2d::Sprite *sprite)')
    .func(nil, 'void setKeepMatrix(bool keepMatrix)')
    .func(nil, 'void setVirtualViewport(const cocos2d::Vec2 &rtBegin, const cocos2d::Rect &fullRect, const cocos2d::Rect &fullViewport)')
    .func(nil, 'RenderTexture()')
    .func(nil, 'bool initWithWidthAndHeight(int w, int h, cocos2d::backend::PixelFormat format)', 'bool initWithWidthAndHeight(int w, int h, cocos2d::backend::PixelFormat format, cocos2d::backend::PixelFormat depthStencilFormat)')
    .callback {
        FUNCS =  {
            'bool saveToFile(const std::string &filename, @optional bool isRGBA, @optional std::function<void (cocos2d::RenderTexture *, const std::string &)> callback)',
            'bool saveToFile(const std::string &filename, cocos2d::Image::Format format, @optional bool isRGBA, @optional std::function<void (cocos2d::RenderTexture *, const std::string &)> callback)'
        },
        TAG_MAKER = 'saveToFile',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'bool saveToFileAsNonPMA(const std::string &filename, @optional bool isRGBA, @optional std::function<void (cocos2d::RenderTexture *, const std::string &)> callback)',
            'bool saveToFileAsNonPMA(const std::string &fileName, cocos2d::Image::Format format, bool isRGBA, std::function<void (cocos2d::RenderTexture *, const std::string &)> callback)'
        },
        TAG_MAKER = 'saveToFile',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'void newImage(std::function<void (cocos2d::Image *)> imageCallback, @optional bool flipImage)'
        },
        TAG_MAKER = 'newImage',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .prop('clearFlags', nil, nil)
    .prop('clearColor', nil, nil)
    .prop('clearDepth', nil, nil)
    .prop('clearStencil', nil, nil)
    .prop('autoDraw', nil, nil)
    .prop('sprite', nil, nil)
    .alias('begin', 'beginVisit')
    .alias('end', 'endVisit')

typeconf 'cocos2d::ProgressTimer::Type'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('RADIAL', 'cocos2d::ProgressTimer::Type::RADIAL')
    .enum('BAR', 'cocos2d::ProgressTimer::Type::BAR')

typeconf 'cocos2d::ProgressTimer'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ProgressTimer *create(cocos2d::Sprite *sp)')
    .func(nil, 'cocos2d::ProgressTimer::Type getType()')
    .func(nil, 'float getPercentage()')
    .func(nil, 'cocos2d::Sprite *getSprite()')
    .func(nil, 'void setPercentage(float percentage)')
    .func(nil, 'void setSprite(cocos2d::Sprite *sprite)')
    .func(nil, 'void setType(cocos2d::ProgressTimer::Type type)')
    .func(nil, 'bool isReverseDirection()')
    .func(nil, 'void setReverseDirection(bool value)')
    .func(nil, 'void setMidpoint(const cocos2d::Vec2 &point)')
    .func(nil, 'cocos2d::Vec2 getMidpoint()')
    .func(nil, 'void setBarChangeRate(const cocos2d::Vec2 &barChangeRate)')
    .func(nil, 'cocos2d::Vec2 getBarChangeRate()')
    .func(nil, 'ProgressTimer()')
    .func(nil, 'bool initWithSprite(cocos2d::Sprite *sp)')
    .prop('type', nil, nil)
    .prop('percentage', nil, nil)
    .prop('sprite', nil, nil)
    .prop('reverseDirection', nil, nil)
    .prop('midpoint', nil, nil)
    .prop('barChangeRate', nil, nil)

typeconf 'cocos2d::AnimationFrame'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::AnimationFrame *create(cocos2d::SpriteFrame *spriteFrame, float delayUnits, const cocos2d::ValueMap &userInfo)')
    .func(nil, 'cocos2d::SpriteFrame *getSpriteFrame()')
    .func(nil, 'void setSpriteFrame(cocos2d::SpriteFrame *frame)')
    .func(nil, 'float getDelayUnits()')
    .func(nil, 'void setDelayUnits(float delayUnits)')
    .func(nil, 'const cocos2d::ValueMap &getUserInfo()')
    .func(nil, 'void setUserInfo(const cocos2d::ValueMap &userInfo)')
    .func(nil, 'cocos2d::AnimationFrame *clone()')
    .func(nil, 'AnimationFrame()')
    .func(nil, 'bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame, float delayUnits, const cocos2d::ValueMap &userInfo)')
    .prop('spriteFrame', nil, nil)
    .prop('delayUnits', nil, nil)
    .prop('userInfo', nil, nil)

typeconf 'cocos2d::Animation'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Animation *create()', 'static cocos2d::Animation *create(const Vector<cocos2d::AnimationFrame *> &arrayOfAnimationFrameNames, float delayPerUnit, @optional unsigned int loops)')
    .func(nil, 'static cocos2d::Animation *createWithSpriteFrames(const Vector<cocos2d::SpriteFrame *> &arrayOfSpriteFrameNames, @optional float delay, @optional unsigned int loops)')
    .func(nil, 'void addSpriteFrame(cocos2d::SpriteFrame *frame)')
    .func(nil, 'void addSpriteFrameWithFile(const std::string &filename)')
    .func(nil, 'void addSpriteFrameWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect)')
    .func(nil, 'float getTotalDelayUnits()')
    .func(nil, 'void setDelayPerUnit(float delayPerUnit)')
    .func(nil, 'float getDelayPerUnit()')
    .func(nil, 'float getDuration()')
    .func(nil, 'const Vector<cocos2d::AnimationFrame *> &getFrames()')
    .func(nil, 'void setFrames(const Vector<cocos2d::AnimationFrame *> &frames)')
    .func(nil, 'bool getRestoreOriginalFrame()')
    .func(nil, 'void setRestoreOriginalFrame(bool restoreOriginalFrame)')
    .func(nil, 'unsigned int getLoops()')
    .func(nil, 'void setLoops(unsigned int loops)')
    .func(nil, 'cocos2d::Animation *clone()')
    .func(nil, 'Animation()')
    .func(nil, 'bool init()')
    .func(nil, 'bool initWithSpriteFrames(const Vector<cocos2d::SpriteFrame *> &arrayOfSpriteFrameNames, @optional float delay, @optional unsigned int loops)')
    .func(nil, 'bool initWithAnimationFrames(const Vector<cocos2d::AnimationFrame *> &arrayOfAnimationFrameNames, float delayPerUnit, unsigned int loops)')
    .prop('totalDelayUnits', nil, nil)
    .prop('delayPerUnit', nil, nil)
    .prop('duration', nil, nil)
    .prop('frames', nil, nil)
    .prop('restoreOriginalFrame', nil, nil)
    .prop('loops', nil, nil)

typeconf 'cocos2d::SpriteFrame'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::SpriteFrame *create(const std::string &filename, const cocos2d::Rect &rect)', 'static cocos2d::SpriteFrame *create(const std::string &filename, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)')
    .func(nil, 'static cocos2d::SpriteFrame *createWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect)', 'static cocos2d::SpriteFrame *createWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)')
    .func(nil, 'const cocos2d::Rect &getRectInPixels()')
    .func(nil, 'void setRectInPixels(const cocos2d::Rect &rectInPixels)')
    .func(nil, 'bool isRotated()')
    .func(nil, 'void setRotated(bool rotated)')
    .func(nil, 'const cocos2d::Rect &getRect()')
    .func(nil, 'void setRect(const cocos2d::Rect &rect)')
    .func(nil, 'const cocos2d::Rect &getCenterRect()')
    .func(nil, 'void setCenterRectInPixels(const cocos2d::Rect &centerRect)')
    .func(nil, 'bool hasCenterRect()')
    .func(nil, 'const cocos2d::Vec2 &getOffsetInPixels()')
    .func(nil, 'void setOffsetInPixels(const cocos2d::Vec2 &offsetInPixels)')
    .func(nil, 'const cocos2d::Size &getOriginalSizeInPixels()')
    .func(nil, 'void setOriginalSizeInPixels(const cocos2d::Size &sizeInPixels)')
    .func(nil, 'const cocos2d::Size &getOriginalSize()')
    .func(nil, 'void setOriginalSize(const cocos2d::Size &sizeInPixels)')
    .func(nil, 'cocos2d::Texture2D *getTexture()')
    .func(nil, 'void setTexture(cocos2d::Texture2D *pobTexture)')
    .func(nil, 'const cocos2d::Vec2 &getOffset()')
    .func(nil, 'void setOffset(const cocos2d::Vec2 &offsets)')
    .func(nil, 'const cocos2d::Vec2 &getAnchorPoint()')
    .func(nil, 'void setAnchorPoint(const cocos2d::Vec2 &anchorPoint)')
    .func(nil, 'bool hasAnchorPoint()')
    .func(nil, 'cocos2d::SpriteFrame *clone()')
    .func(nil, 'bool hasPolygonInfo()')
    .func(nil, 'SpriteFrame()')
    .func(nil, 'bool initWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect)', 'bool initWithTexture(cocos2d::Texture2D *pobTexture, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)')
    .func(nil, 'bool initWithTextureFilename(const std::string &filename, const cocos2d::Rect &rect)', 'bool initWithTextureFilename(const std::string &filename, const cocos2d::Rect &rect, bool rotated, const cocos2d::Vec2 &offset, const cocos2d::Size &originalSize)')
    .prop('rectInPixels', nil, nil)
    .prop('rotated', nil, nil)
    .prop('rect', nil, nil)
    .prop('centerRect', nil, nil)
    .prop('offsetInPixels', nil, nil)
    .prop('originalSizeInPixels', nil, nil)
    .prop('originalSize', nil, nil)
    .prop('texture', nil, nil)
    .prop('offset', nil, nil)
    .prop('anchorPoint', nil, nil)

typeconf 'cocos2d::Sprite'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('INDEX_NOT_INITIALIZED', 'cocos2d::Sprite::INDEX_NOT_INITIALIZED', 'const int')
    .func(nil, 'static cocos2d::Sprite *create()', 'static cocos2d::Sprite *create(const std::string &filename)', 'static cocos2d::Sprite *create(const std::string &filename, const cocos2d::Rect &rect)')
    .func(nil, 'static cocos2d::Sprite *createWithTexture(cocos2d::Texture2D *texture)', 'static cocos2d::Sprite *createWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect &rect, @optional bool rotated)')
    .func(nil, 'static cocos2d::Sprite *createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)')
    .func(nil, 'static cocos2d::Sprite *createWithSpriteFrameName(const std::string &spriteFrameName)')
    .func(nil, 'cocos2d::SpriteBatchNode *getBatchNode()')
    .func(nil, 'void setBatchNode(cocos2d::SpriteBatchNode *spriteBatchNode)')
    .func(nil, 'void setTexture(const std::string &filename)', 'void setTexture(cocos2d::Texture2D *texture)')
    .func(nil, 'cocos2d::Texture2D *getTexture()')
    .func(nil, 'void setTextureRect(const cocos2d::Rect &rect)', 'void setTextureRect(const cocos2d::Rect &rect, bool rotated, const cocos2d::Size &untrimmedSize)')
    .func(nil, 'void setVertexRect(const cocos2d::Rect &rect)')
    .func(nil, 'void setCenterRectNormalized(const cocos2d::Rect &rect)')
    .func(nil, 'cocos2d::Rect getCenterRectNormalized()')
    .func(nil, 'void setCenterRect(const cocos2d::Rect &rect)')
    .func(nil, 'cocos2d::Rect getCenterRect()')
    .func(nil, 'void setSpriteFrame(const std::string &spriteFrameName)', 'void setSpriteFrame(cocos2d::SpriteFrame *newFrame)')
    .func(nil, 'bool isFrameDisplayed(cocos2d::SpriteFrame *frame)')
    .func(nil, 'cocos2d::SpriteFrame *getSpriteFrame()')
    .func(nil, 'void setDisplayFrameWithAnimationName(const std::string &animationName, unsigned int frameIndex)')
    .func(nil, 'bool isDirty()')
    .func(nil, 'void setDirty(bool dirty)')
    .func(nil, 'bool isTextureRectRotated()')
    .func(nil, 'unsigned int getAtlasIndex()')
    .func(nil, 'void setAtlasIndex(unsigned int atlasIndex)')
    .func(nil, 'const cocos2d::Rect &getTextureRect()')
    .func(nil, 'cocos2d::TextureAtlas *getTextureAtlas()')
    .func(nil, 'void setTextureAtlas(cocos2d::TextureAtlas *textureAtlas)')
    .func(nil, 'const cocos2d::Vec2 &getOffsetPosition()')
    .func(nil, 'bool isFlippedX()')
    .func(nil, 'void setFlippedX(bool flippedX)')
    .func(nil, 'bool isFlippedY()')
    .func(nil, 'void setFlippedY(bool flippedY)')
    .func(nil, 'void setStretchEnabled(bool enabled)')
    .func(nil, 'bool isStretchEnabled()')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'int getResourceType()')
    .func(nil, 'const std::string &getResourceName()')
    .func(nil, 'Sprite()')
    .func(nil, 'bool initWithTexture(cocos2d::Texture2D *texture)', 'bool initWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect &rect)', 'bool initWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect &rect, bool rotated)')
    .func(nil, 'bool initWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame)')
    .func(nil, 'bool initWithSpriteFrameName(const std::string &spriteFrameName)')
    .func(nil, 'bool initWithFile(const std::string &filename)', 'bool initWithFile(const std::string &filename, const cocos2d::Rect &rect)')
    .func(nil, 'void setVertexLayout()')
    .func(nil, 'void updateShaders(const char *vert, const char *frag)')
    .prop('batchNode', nil, nil)
    .prop('texture', nil, nil)
    .prop('centerRectNormalized', nil, nil)
    .prop('centerRect', nil, nil)
    .prop('spriteFrame', nil, nil)
    .prop('dirty', nil, nil)
    .prop('textureRectRotated', nil, nil)
    .prop('atlasIndex', nil, nil)
    .prop('textureRect', nil, nil)
    .prop('textureAtlas', nil, nil)
    .prop('offsetPosition', nil, nil)
    .prop('flippedX', nil, nil)
    .prop('flippedY', nil, nil)
    .prop('stretchEnabled', nil, nil)
    .prop('blendFunc', nil, nil)
    .prop('resourceType', nil, nil)
    .prop('resourceName', nil, nil)

typeconf 'cocos2d::SpriteBatchNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::SpriteBatchNode *createWithTexture(cocos2d::Texture2D *tex, @optional ssize_t capacity)')
    .func(nil, 'static cocos2d::SpriteBatchNode *create(const std::string &fileImage, @optional ssize_t capacity)')
    .func(nil, 'cocos2d::TextureAtlas *getTextureAtlas()')
    .func(nil, 'void setTextureAtlas(cocos2d::TextureAtlas *textureAtlas)')
    .func(nil, 'const std::vector<Sprite *> &getDescendants()')
    .func(nil, 'void increaseAtlasCapacity()')
    .func(nil, 'void removeChildAtIndex(ssize_t index, bool doCleanup)')
    .func(nil, 'void appendChild(cocos2d::Sprite *sprite)')
    .func(nil, 'void removeSpriteFromAtlas(cocos2d::Sprite *sprite)')
    .func(nil, 'ssize_t rebuildIndexInOrder(cocos2d::Sprite *parent, ssize_t index)')
    .func(nil, 'ssize_t highestAtlasIndexInChild(cocos2d::Sprite *sprite)')
    .func(nil, 'ssize_t lowestAtlasIndexInChild(cocos2d::Sprite *sprite)')
    .func(nil, 'ssize_t atlasIndexForChild(cocos2d::Sprite *sprite, int z)')
    .func(nil, 'void reorderBatch(bool reorder)')
    .func(nil, 'cocos2d::Texture2D *getTexture()')
    .func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'void insertQuadFromSprite(cocos2d::Sprite *sprite, ssize_t index)')
    .func(nil, 'cocos2d::SpriteBatchNode *addSpriteWithoutQuad(cocos2d::Sprite *child, int z, int aTag)')
    .func(nil, 'void reserveCapacity(ssize_t newCapacity)')
    .func(nil, 'SpriteBatchNode()')
    .func(nil, 'bool initWithTexture(cocos2d::Texture2D *tex, @optional ssize_t capacity)')
    .func(nil, 'bool initWithFile(const std::string &fileImage, @optional ssize_t capacity)')
    .prop('textureAtlas', nil, nil)
    .prop('descendants', nil, nil)
    .prop('texture', nil, nil)
    .prop('blendFunc', nil, nil)

typeconf 'cocos2d::SpriteFrameCache'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::SpriteFrameCache *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'bool init()')
    .func(nil, 'void addSpriteFramesWithFile(const std::string &plist)', 'void addSpriteFramesWithFile(const std::string &plist, const std::string &textureFileName)', 'void addSpriteFramesWithFile(const std::string &plist, cocos2d::Texture2D *texture)')
    .func(nil, 'void addSpriteFramesWithFileContent(const std::string &plist_content, cocos2d::Texture2D *texture)')
    .func(nil, 'void addSpriteFrame(cocos2d::SpriteFrame *frame, const std::string &frameName)')
    .func(nil, 'bool isSpriteFramesWithFileLoaded(const std::string &plist)')
    .func(nil, 'void removeSpriteFrames()')
    .func(nil, 'void removeUnusedSpriteFrames()')
    .func(nil, 'void removeSpriteFrameByName(const std::string &name)')
    .func(nil, 'void removeSpriteFramesFromFile(const std::string &plist)')
    .func(nil, 'void removeSpriteFramesFromFileContent(const std::string &plist_content)')
    .func(nil, 'void removeSpriteFramesFromTexture(cocos2d::Texture2D *texture)')
    .func(nil, 'cocos2d::SpriteFrame *getSpriteFrameByName(const std::string &name)')
    .func(nil, 'bool reloadTexture(const std::string &plist)')
    .prop('instance', nil, nil)

typeconf 'cocos2d::AnimationCache'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'AnimationCache()')
    .func(nil, 'static cocos2d::AnimationCache *getInstance()')
    .func(nil, 'static void destroyInstance()')
    .func(nil, 'bool init()')
    .func(nil, 'void addAnimation(cocos2d::Animation *animation, const std::string &name)')
    .func(nil, 'void removeAnimation(const std::string &name)')
    .func(nil, 'cocos2d::Animation *getAnimation(const std::string &name)')
    .func(nil, 'void addAnimationsWithDictionary(const cocos2d::ValueMap &dictionary, const std::string &plist)')
    .func(nil, 'void addAnimationsWithFile(const std::string &plist)')
    .prop('instance', nil, nil)

typeconf 'cocos2d::Scene'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Scene *create()')
    .func(nil, 'static cocos2d::Scene *createWithSize(const cocos2d::Size &size)')
    .func(nil, 'const std::vector<Camera *> &getCameras()')
    .func(nil, 'cocos2d::Camera *getDefaultCamera()')
    .func(nil, 'const std::vector<BaseLight *> &getLights()')
    .func(nil, 'Scene()')
    .func(nil, 'bool initWithSize(const cocos2d::Size &size)')
    .func(nil, 'void setCameraOrderDirty()')
    .func(nil, 'void onProjectionChanged(cocos2d::EventCustom *event)')
    .func(nil, '@addref(physicsWorld ^) cocos2d::PhysicsWorld *getPhysicsWorld()')
    .func(nil, 'void setPhysics3DDebugCamera(cocos2d::Camera *camera)')
    .func(nil, 'static cocos2d::Scene *createWithPhysics()')
    .func(nil, 'bool initWithPhysics()')
    .func(nil, 'void setNavMeshDebugCamera(cocos2d::Camera *camera)')
    .func(nil, 'void stepPhysicsAndNavigation(float deltaTime)')
    .prop('cameras', nil, nil)
    .prop('defaultCamera', nil, nil)
    .prop('lights', nil, nil)
    .prop('physicsWorld', nil, nil)

typeconf 'cocos2d::Layer'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Layer *create()')
    .func(nil, 'bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)')
    .func(nil, 'void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)')
    .func(nil, 'void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)')
    .func(nil, 'void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event)')
    .func(nil, 'void onTouchesBegan(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)')
    .func(nil, 'void onTouchesMoved(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)')
    .func(nil, 'void onTouchesEnded(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)')
    .func(nil, 'void onTouchesCancelled(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)')
    .func(nil, 'void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *unused_event)')
    .func(nil, 'void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)')
    .func(nil, 'void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)')
    .func(nil, 'Layer()')

typeconf 'cocos2d::LayerColor'
    .supercls('cocos2d::Layer')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::LayerColor *create()', 'static cocos2d::LayerColor *create(const cocos2d::Color4B &color, float width, float height)', 'static cocos2d::LayerColor *create(const cocos2d::Color4B &color)')
    .func(nil, 'void changeWidth(float w)')
    .func(nil, 'void changeHeight(float h)')
    .func(nil, 'void changeWidthAndHeight(float w, float h)')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'LayerColor()')
    .func(nil, 'bool initWithColor(const cocos2d::Color4B &color, float width, float height)', 'bool initWithColor(const cocos2d::Color4B &color)')
    .prop('blendFunc', nil, nil)

typeconf 'cocos2d::LayerGradient'
    .supercls('cocos2d::LayerColor')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::LayerGradient *create()', 'static cocos2d::LayerGradient *create(const cocos2d::Color4B &start, const cocos2d::Color4B &end)', 'static cocos2d::LayerGradient *create(const cocos2d::Color4B &start, const cocos2d::Color4B &end, const cocos2d::Vec2 &v)')
    .func(nil, 'void setCompressedInterpolation(bool compressedInterpolation)')
    .func(nil, 'bool isCompressedInterpolation()')
    .func(nil, 'void setStartColor(const cocos2d::Color3B &startColor)')
    .func(nil, 'const cocos2d::Color3B &getStartColor()')
    .func(nil, 'void setEndColor(const cocos2d::Color3B &endColor)')
    .func(nil, 'const cocos2d::Color3B &getEndColor()')
    .func(nil, 'void setStartOpacity(uint8_t startOpacity)')
    .func(nil, 'uint8_t getStartOpacity()')
    .func(nil, 'void setEndOpacity(uint8_t endOpacity)')
    .func(nil, 'uint8_t getEndOpacity()')
    .func(nil, 'void setVector(const cocos2d::Vec2 &alongVector)')
    .func(nil, 'const cocos2d::Vec2 &getVector()')
    .func(nil, 'LayerGradient()')
    .func(nil, 'bool initWithColor(const cocos2d::Color4B &start, const cocos2d::Color4B &end)', 'bool initWithColor(const cocos2d::Color4B &start, const cocos2d::Color4B &end, const cocos2d::Vec2 &v)')
    .prop('compressedInterpolation', nil, nil)
    .prop('startColor', nil, nil)
    .prop('endColor', nil, nil)
    .prop('startOpacity', nil, nil)
    .prop('endOpacity', nil, nil)
    .prop('vector', nil, nil)

typeconf 'cocos2d::LayerRadialGradient'
    .supercls('cocos2d::Layer')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::LayerRadialGradient *create(const cocos2d::Color4B &startColor, const cocos2d::Color4B &endColor, float radius, const cocos2d::Vec2 &center, float expand)', 'static cocos2d::LayerRadialGradient *create()')
    .func(nil, 'void setStartOpacity(uint8_t opacity)')
    .func(nil, 'uint8_t getStartOpacity()')
    .func(nil, 'void setEndOpacity(uint8_t opacity)')
    .func(nil, 'uint8_t getEndOpacity()')
    .func(nil, 'void setRadius(float radius)')
    .func(nil, 'float getRadius()')
    .func(nil, 'void setCenter(const cocos2d::Vec2 &center)')
    .func(nil, 'cocos2d::Vec2 getCenter()')
    .func(nil, 'void setExpand(float expand)')
    .func(nil, 'float getExpand()')
    .func(nil, 'void setStartColor(const cocos2d::Color3B &color)', 'void setStartColor(const cocos2d::Color4B &color)')
    .func(nil, 'cocos2d::Color4B getStartColor()')
    .func(nil, 'cocos2d::Color3B getStartColor3B()')
    .func(nil, 'void setEndColor(const cocos2d::Color3B &color)', 'void setEndColor(const cocos2d::Color4B &color)')
    .func(nil, 'cocos2d::Color4B getEndColor()')
    .func(nil, 'cocos2d::Color3B getEndColor3B()')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'cocos2d::BlendFunc getBlendFunc()')
    .func(nil, 'LayerRadialGradient()')
    .func(nil, 'bool initWithColor(const cocos2d::Color4B &startColor, const cocos2d::Color4B &endColor, float radius, const cocos2d::Vec2 &center, float expand)')
    .prop('startOpacity', nil, nil)
    .prop('endOpacity', nil, nil)
    .prop('radius', nil, nil)
    .prop('center', nil, nil)
    .prop('expand', nil, nil)
    .prop('startColor', nil, nil)
    .prop('startColor3B', nil, nil)
    .prop('endColor', nil, nil)
    .prop('endColor3B', nil, nil)
    .prop('blendFunc', nil, nil)

typeconf 'cocos2d::LayerMultiplex'
    .supercls('cocos2d::Layer')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::LayerMultiplex *create()')
    .func(nil, 'static cocos2d::LayerMultiplex *createWithArray(const Vector<cocos2d::Layer *> &arrayOfLayers)')
    .func(nil, 'static cocos2d::LayerMultiplex *createWithLayer(cocos2d::Layer *layer)')
    .func(nil, 'void addLayer(cocos2d::Layer *layer)')
    .func(nil, 'void switchTo(int n)', 'void switchTo(int n, bool cleanup)')
    .func(nil, 'void switchToAndReleaseMe(int n)')
    .func(nil, 'LayerMultiplex()')
    .func(nil, 'bool initWithArray(const Vector<cocos2d::Layer *> &arrayOfLayers)')

typeconf 'cocos2d::TransitionScene::Orientation'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('LEFT_OVER', 'cocos2d::TransitionScene::Orientation::LEFT_OVER')
    .enum('RIGHT_OVER', 'cocos2d::TransitionScene::Orientation::RIGHT_OVER')
    .enum('UP_OVER', 'cocos2d::TransitionScene::Orientation::UP_OVER')
    .enum('DOWN_OVER', 'cocos2d::TransitionScene::Orientation::DOWN_OVER')

typeconf 'cocos2d::TransitionScene'
    .supercls('cocos2d::Scene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionScene *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'void finish()')
    .func(nil, 'void hideOutShowIn()')
    .func(nil, 'cocos2d::Scene *getInScene()')
    .func(nil, 'float getDuration()')
    .func(nil, 'TransitionScene()')
    .prop('inScene', nil, nil)
    .prop('duration', nil, nil)

typeconf 'cocos2d::TransitionSceneOriented'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionSceneOriented *create(float t, @addref(scenes |) cocos2d::Scene *scene, cocos2d::TransitionScene::Orientation orientation)')
    .func(nil, 'TransitionSceneOriented()')

typeconf 'cocos2d::TransitionRotoZoom'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionRotoZoom *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionRotoZoom()')

typeconf 'cocos2d::TransitionJumpZoom'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionJumpZoom *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionJumpZoom()')

typeconf 'cocos2d::TransitionMoveInL'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionMoveInL *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'cocos2d::ActionInterval *action()')
    .func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
    .func(nil, 'TransitionMoveInL()')

typeconf 'cocos2d::TransitionMoveInR'
    .supercls('cocos2d::TransitionMoveInL')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionMoveInR *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionMoveInR()')

typeconf 'cocos2d::TransitionMoveInT'
    .supercls('cocos2d::TransitionMoveInL')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionMoveInT *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionMoveInT()')

typeconf 'cocos2d::TransitionMoveInB'
    .supercls('cocos2d::TransitionMoveInL')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionMoveInB *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionMoveInB()')

typeconf 'cocos2d::TransitionSlideInL'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionSlideInL *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
    .func(nil, 'cocos2d::ActionInterval *action()')
    .func(nil, 'TransitionSlideInL()')

typeconf 'cocos2d::TransitionSlideInR'
    .supercls('cocos2d::TransitionSlideInL')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionSlideInR *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionSlideInR()')

typeconf 'cocos2d::TransitionSlideInB'
    .supercls('cocos2d::TransitionSlideInL')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionSlideInB *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionSlideInB()')

typeconf 'cocos2d::TransitionSlideInT'
    .supercls('cocos2d::TransitionSlideInL')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionSlideInT *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionSlideInT()')

typeconf 'cocos2d::TransitionShrinkGrow'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionShrinkGrow *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
    .func(nil, 'TransitionShrinkGrow()')

typeconf 'cocos2d::TransitionFlipX'
    .supercls('cocos2d::TransitionSceneOriented')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionFlipX *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionFlipX *create(float t, @addref(scenes |) cocos2d::Scene *s)')
    .func(nil, 'TransitionFlipX()')

typeconf 'cocos2d::TransitionFlipY'
    .supercls('cocos2d::TransitionSceneOriented')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionFlipY *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionFlipY *create(float t, @addref(scenes |) cocos2d::Scene *s)')
    .func(nil, 'TransitionFlipY()')

typeconf 'cocos2d::TransitionFlipAngular'
    .supercls('cocos2d::TransitionSceneOriented')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionFlipAngular *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionFlipAngular *create(float t, @addref(scenes |) cocos2d::Scene *s)')
    .func(nil, 'TransitionFlipAngular()')

typeconf 'cocos2d::TransitionZoomFlipX'
    .supercls('cocos2d::TransitionSceneOriented')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionZoomFlipX *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionZoomFlipX *create(float t, @addref(scenes |) cocos2d::Scene *s)')
    .func(nil, 'TransitionZoomFlipX()')

typeconf 'cocos2d::TransitionZoomFlipY'
    .supercls('cocos2d::TransitionSceneOriented')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionZoomFlipY *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionZoomFlipY *create(float t, @addref(scenes |) cocos2d::Scene *s)')
    .func(nil, 'TransitionZoomFlipY()')

typeconf 'cocos2d::TransitionZoomFlipAngular'
    .supercls('cocos2d::TransitionSceneOriented')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionZoomFlipAngular *create(float t, @addref(scenes |) cocos2d::Scene *s, cocos2d::TransitionScene::Orientation o)', 'static cocos2d::TransitionZoomFlipAngular *create(float t, @addref(scenes |) cocos2d::Scene *s)')
    .func(nil, 'TransitionZoomFlipAngular()')

typeconf 'cocos2d::TransitionFade'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionFade *create(float duration, @addref(scenes |) cocos2d::Scene *scene, const cocos2d::Color3B &color)', 'static cocos2d::TransitionFade *create(float duration, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionFade()')

typeconf 'cocos2d::TransitionCrossFade'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionCrossFade *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionCrossFade()')

typeconf 'cocos2d::TransitionTurnOffTiles'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionTurnOffTiles *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
    .func(nil, 'TransitionTurnOffTiles()')

typeconf 'cocos2d::TransitionSplitCols'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionSplitCols *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'cocos2d::ActionInterval *action()')
    .func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
    .func(nil, 'TransitionSplitCols()')

typeconf 'cocos2d::TransitionSplitRows'
    .supercls('cocos2d::TransitionSplitCols')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionSplitRows *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionSplitRows()')

typeconf 'cocos2d::TransitionFadeTR'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionFadeTR *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'cocos2d::ActionInterval *actionWithSize(const cocos2d::Size &size)')
    .func(nil, 'cocos2d::ActionInterval *easeActionWithAction(@addref(action ^) cocos2d::ActionInterval *action)')
    .func(nil, 'TransitionFadeTR()')

typeconf 'cocos2d::TransitionFadeBL'
    .supercls('cocos2d::TransitionFadeTR')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionFadeBL *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionFadeBL()')

typeconf 'cocos2d::TransitionFadeUp'
    .supercls('cocos2d::TransitionFadeTR')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionFadeUp *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionFadeUp()')

typeconf 'cocos2d::TransitionFadeDown'
    .supercls('cocos2d::TransitionFadeTR')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionFadeDown *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionFadeDown()')

typeconf 'cocos2d::TransitionPageTurn'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionPageTurn *create(float t, @addref(scenes |) cocos2d::Scene *scene, bool backwards)')
    .func(nil, 'cocos2d::ActionInterval *actionWithSize(const cocos2d::Size &vector)')
    .func(nil, 'TransitionPageTurn()')

typeconf 'cocos2d::TransitionProgress'
    .supercls('cocos2d::TransitionScene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionProgress *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionProgress()')

typeconf 'cocos2d::TransitionProgressRadialCCW'
    .supercls('cocos2d::TransitionProgress')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionProgressRadialCCW *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionProgressRadialCCW()')

typeconf 'cocos2d::TransitionProgressRadialCW'
    .supercls('cocos2d::TransitionProgress')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionProgressRadialCW *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionProgressRadialCW()')

typeconf 'cocos2d::TransitionProgressHorizontal'
    .supercls('cocos2d::TransitionProgress')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionProgressHorizontal *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionProgressHorizontal()')

typeconf 'cocos2d::TransitionProgressVertical'
    .supercls('cocos2d::TransitionProgress')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionProgressVertical *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionProgressVertical()')

typeconf 'cocos2d::TransitionProgressInOut'
    .supercls('cocos2d::TransitionProgress')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionProgressInOut *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionProgressInOut()')

typeconf 'cocos2d::TransitionProgressOutIn'
    .supercls('cocos2d::TransitionProgress')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TransitionProgressOutIn *create(float t, @addref(scenes |) cocos2d::Scene *scene)')
    .func(nil, 'TransitionProgressOutIn()')

typeconf 'cocos2d::TextFieldDelegate'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF *sender)')
    .func(nil, 'bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF *sender)')
    .func(nil, 'bool onTextFieldInsertText(cocos2d::TextFieldTTF *sender, const char *text, size_t nLen)')
    .func(nil, 'bool onTextFieldDeleteBackward(cocos2d::TextFieldTTF *sender, const char *delText, size_t nLen)')
    .func(nil, 'bool onVisit(cocos2d::TextFieldTTF *sender, cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags)')

typeconf 'cocos2d::TextFieldTTF'
    .supercls('cocos2d::Label')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'TextFieldTTF()')
    .func(nil, 'static cocos2d::TextFieldTTF *textFieldWithPlaceHolder(const std::string &placeholder, const cocos2d::Size &dimensions, cocos2d::TextHAlignment alignment, const std::string &fontName, float fontSize)', 'static cocos2d::TextFieldTTF *textFieldWithPlaceHolder(const std::string &placeholder, const std::string &fontName, float fontSize)')
    .func(nil, 'bool initWithPlaceHolder(const std::string &placeholder, const cocos2d::Size &dimensions, cocos2d::TextHAlignment alignment, const std::string &fontName, float fontSize)', 'bool initWithPlaceHolder(const std::string &placeholder, const std::string &fontName, float fontSize)')
    .func(nil, 'bool attachWithIME()')
    .func(nil, 'bool detachWithIME()')
    .func(nil, 'cocos2d::TextFieldDelegate *getDelegate()')
    .func(nil, 'void setDelegate(cocos2d::TextFieldDelegate *delegate)')
    .func(nil, 'std::size_t getCharCount()')
    .func(nil, 'const cocos2d::Color4B &getColorSpaceHolder()')
    .func(nil, 'void setColorSpaceHolder(const cocos2d::Color3B &color)', 'void setColorSpaceHolder(const cocos2d::Color4B &color)')
    .func(nil, 'void appendString(const std::string &text)')
    .func(nil, 'void setPlaceHolder(const std::string &text)')
    .func(nil, 'const std::string &getPlaceHolder()')
    .func(nil, 'void setSecureTextEntry(bool value)')
    .func(nil, 'void setPasswordTextStyle(const std::string &text)')
    .func(nil, 'const std::string &getPasswordTextStyle()')
    .func(nil, 'bool isSecureTextEntry()')
    .func(nil, 'void setCursorEnabled(bool enabled)')
    .func(nil, 'void setCursorChar(char cursor)')
    .func(nil, 'void setCursorPosition(std::size_t cursorPosition)')
    .func(nil, 'void setCursorFromPoint(const cocos2d::Vec2 &point, const cocos2d::Camera *camera)')
    .prop('delegate', nil, nil)
    .prop('charCount', nil, nil)
    .prop('colorSpaceHolder', nil, nil)
    .prop('placeHolder', nil, nil)
    .prop('passwordTextStyle', nil, nil)
    .prop('secureTextEntry', nil, nil)

typeconf 'cocos2d::LightType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('DIRECTIONAL', 'cocos2d::LightType::DIRECTIONAL')
    .enum('POINT', 'cocos2d::LightType::POINT')
    .enum('SPOT', 'cocos2d::LightType::SPOT')
    .enum('AMBIENT', 'cocos2d::LightType::AMBIENT')

typeconf 'cocos2d::LightFlag'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('LIGHT0', 'cocos2d::LightFlag::LIGHT0')
    .enum('LIGHT1', 'cocos2d::LightFlag::LIGHT1')
    .enum('LIGHT2', 'cocos2d::LightFlag::LIGHT2')
    .enum('LIGHT3', 'cocos2d::LightFlag::LIGHT3')
    .enum('LIGHT4', 'cocos2d::LightFlag::LIGHT4')
    .enum('LIGHT5', 'cocos2d::LightFlag::LIGHT5')
    .enum('LIGHT6', 'cocos2d::LightFlag::LIGHT6')
    .enum('LIGHT7', 'cocos2d::LightFlag::LIGHT7')
    .enum('LIGHT8', 'cocos2d::LightFlag::LIGHT8')
    .enum('LIGHT9', 'cocos2d::LightFlag::LIGHT9')
    .enum('LIGHT10', 'cocos2d::LightFlag::LIGHT10')
    .enum('LIGHT11', 'cocos2d::LightFlag::LIGHT11')
    .enum('LIGHT12', 'cocos2d::LightFlag::LIGHT12')
    .enum('LIGHT13', 'cocos2d::LightFlag::LIGHT13')
    .enum('LIGHT14', 'cocos2d::LightFlag::LIGHT14')
    .enum('LIGHT15', 'cocos2d::LightFlag::LIGHT15')

typeconf 'cocos2d::BaseLight'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'cocos2d::LightType getLightType()')
    .func(nil, 'float getIntensity()')
    .func(nil, 'void setIntensity(float intensity)')
    .func(nil, 'cocos2d::LightFlag getLightFlag()')
    .func(nil, 'void setLightFlag(cocos2d::LightFlag flag)')
    .func(nil, 'void setEnabled(bool enabled)')
    .func(nil, 'bool isEnabled()')
    .prop('lightType', nil, nil)
    .prop('intensity', nil, nil)
    .prop('lightFlag', nil, nil)
    .prop('enabled', nil, nil)

typeconf 'cocos2d::DirectionLight'
    .supercls('cocos2d::BaseLight')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::DirectionLight *create(const cocos2d::Vec3 &direction, const cocos2d::Color3B &color)')
    .func(nil, 'void setDirection(const cocos2d::Vec3 &dir)')
    .func(nil, 'cocos2d::Vec3 getDirection()')
    .func(nil, 'cocos2d::Vec3 getDirectionInWorld()')
    .func(nil, 'DirectionLight()')
    .prop('direction', nil, nil)
    .prop('directionInWorld', nil, nil)

typeconf 'cocos2d::PointLight'
    .supercls('cocos2d::BaseLight')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PointLight *create(const cocos2d::Vec3 &position, const cocos2d::Color3B &color, float range)')
    .func(nil, 'float getRange()')
    .func(nil, 'void setRange(float range)')
    .func(nil, 'PointLight()')
    .prop('range', nil, nil)

typeconf 'cocos2d::SpotLight'
    .supercls('cocos2d::BaseLight')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::SpotLight *create(const cocos2d::Vec3 &direction, const cocos2d::Vec3 &position, const cocos2d::Color3B &color, float innerAngle, float outerAngle, float range)')
    .func(nil, 'void setDirection(const cocos2d::Vec3 &dir)')
    .func(nil, 'cocos2d::Vec3 getDirection()')
    .func(nil, 'cocos2d::Vec3 getDirectionInWorld()')
    .func(nil, 'void setRange(float range)')
    .func(nil, 'float getRange()')
    .func(nil, 'void setInnerAngle(float angle)')
    .func(nil, 'float getInnerAngle()')
    .func(nil, 'float getCosInnerAngle()')
    .func(nil, 'void setOuterAngle(float outerAngle)')
    .func(nil, 'float getOuterAngle()')
    .func(nil, 'float getCosOuterAngle()')
    .func(nil, 'SpotLight()')
    .prop('direction', nil, nil)
    .prop('directionInWorld', nil, nil)
    .prop('range', nil, nil)
    .prop('innerAngle', nil, nil)
    .prop('cosInnerAngle', nil, nil)
    .prop('outerAngle', nil, nil)
    .prop('cosOuterAngle', nil, nil)

typeconf 'cocos2d::AmbientLight'
    .supercls('cocos2d::BaseLight')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::AmbientLight *create(const cocos2d::Color3B &color)')
    .func(nil, 'AmbientLight()')

typeconf 'cocos2d::CameraFlag'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('DEFAULT', 'cocos2d::CameraFlag::DEFAULT')
    .enum('USER1', 'cocos2d::CameraFlag::USER1')
    .enum('USER2', 'cocos2d::CameraFlag::USER2')
    .enum('USER3', 'cocos2d::CameraFlag::USER3')
    .enum('USER4', 'cocos2d::CameraFlag::USER4')
    .enum('USER5', 'cocos2d::CameraFlag::USER5')
    .enum('USER6', 'cocos2d::CameraFlag::USER6')
    .enum('USER7', 'cocos2d::CameraFlag::USER7')
    .enum('USER8', 'cocos2d::CameraFlag::USER8')

typeconf 'cocos2d::Camera::Type'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('PERSPECTIVE', 'cocos2d::Camera::Type::PERSPECTIVE')
    .enum('ORTHOGRAPHIC', 'cocos2d::Camera::Type::ORTHOGRAPHIC')

typeconf 'cocos2d::Camera'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Camera *createPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)')
    .func(nil, 'static cocos2d::Camera *createOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)')
    .func(nil, 'static cocos2d::Camera *create()')
    .func(nil, 'static const cocos2d::Camera *getVisitingCamera()')
    .func(nil, 'static const cocos2d::Viewport &getDefaultViewport()')
    .func(nil, 'static void setDefaultViewport(const cocos2d::Viewport &vp)')
    .func(nil, 'static cocos2d::Camera *getDefaultCamera()')
    .func(nil, 'cocos2d::Camera::Type getType()')
    .func(nil, 'cocos2d::CameraFlag getCameraFlag()')
    .func(nil, 'void setCameraFlag(cocos2d::CameraFlag flag)')
    .func(nil, 'void lookAt(const cocos2d::Vec3 &target, @optional const cocos2d::Vec3 &up)')
    .func(nil, 'const cocos2d::Mat4 &getProjectionMatrix()')
    .func(nil, 'const cocos2d::Mat4 &getViewMatrix()')
    .func(nil, 'const cocos2d::Mat4 &getViewProjectionMatrix()')
    .func(nil, 'cocos2d::Vec2 project(const cocos2d::Vec3 &src)')
    .func(nil, 'cocos2d::Vec2 projectGL(const cocos2d::Vec3 &src)')
    .func(nil, 'cocos2d::Vec3 unproject(const cocos2d::Vec3 &src)')
    .func(nil, 'cocos2d::Vec3 unprojectGL(const cocos2d::Vec3 &src)')
    .func(nil, 'float getDepthInView(const cocos2d::Mat4 &transform)')
    .func(nil, 'void setDepth(int8_t depth)')
    .func(nil, 'int8_t getDepth()')
    .func(nil, 'int getRenderOrder()')
    .func(nil, 'float getFarPlane()')
    .func(nil, 'float getNearPlane()')
    .func(nil, 'void clearBackground()')
    .func(nil, 'void apply()')
    .func(nil, 'bool isViewProjectionUpdated()')
    .func(nil, 'void setBackgroundBrush(cocos2d::CameraBackgroundBrush *clearBrush)')
    .func(nil, 'cocos2d::CameraBackgroundBrush *getBackgroundBrush()')
    .func(nil, 'bool isBrushValid()')
    .func(nil, 'Camera()')
    .func(nil, 'void setScene(cocos2d::Scene *scene)')
    .func(nil, 'void setAdditionalProjection(const cocos2d::Mat4 &mat)')
    .func(nil, 'bool initDefault()')
    .func(nil, 'bool initPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)')
    .func(nil, 'bool initOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)')
    .func(nil, 'void applyViewport()')
    .prop('visitingCamera', nil, nil)
    .prop('defaultViewport', nil, nil)
    .prop('defaultCamera', nil, nil)
    .prop('type', nil, nil)
    .prop('cameraFlag', nil, nil)
    .prop('projectionMatrix', nil, nil)
    .prop('viewMatrix', nil, nil)
    .prop('viewProjectionMatrix', nil, nil)
    .prop('depth', nil, nil)
    .prop('renderOrder', nil, nil)
    .prop('farPlane', nil, nil)
    .prop('nearPlane', nil, nil)
    .prop('viewProjectionUpdated', nil, nil)
    .prop('backgroundBrush', nil, nil)
    .prop('brushValid', nil, nil)

typeconf 'cocos2d::CameraBackgroundBrush::BrushType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NONE', 'cocos2d::CameraBackgroundBrush::BrushType::NONE')
    .enum('DEPTH', 'cocos2d::CameraBackgroundBrush::BrushType::DEPTH')
    .enum('COLOR', 'cocos2d::CameraBackgroundBrush::BrushType::COLOR')
    .enum('SKYBOX', 'cocos2d::CameraBackgroundBrush::BrushType::SKYBOX')

typeconf 'cocos2d::CameraBackgroundBrush'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'cocos2d::CameraBackgroundBrush::BrushType getBrushType()')
    .func(nil, 'static cocos2d::CameraBackgroundBrush *createNoneBrush()')
    .func(nil, 'static cocos2d::CameraBackgroundDepthBrush *createDepthBrush(@optional float depth)')
    .func(nil, 'static cocos2d::CameraBackgroundColorBrush *createColorBrush(const cocos2d::Color4F &color, float depth)')
    .func(nil, 'static cocos2d::CameraBackgroundSkyBoxBrush *createSkyboxBrush(const std::string &positive_x, const std::string &negative_x, const std::string &positive_y, const std::string &negative_y, const std::string &positive_z, const std::string &negative_z)')
    .func(nil, 'void drawBackground(cocos2d::Camera *)')
    .func(nil, 'bool isValid()')
    .func(nil, 'CameraBackgroundBrush()')
    .func(nil, 'bool init()')
    .prop('brushType', nil, nil)
    .prop('valid', nil, nil)

typeconf 'cocos2d::CameraBackgroundDepthBrush'
    .supercls('cocos2d::CameraBackgroundBrush')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::CameraBackgroundDepthBrush *create(float depth)')
    .func(nil, 'void setDepth(float depth)')
    .func(nil, 'CameraBackgroundDepthBrush()')

typeconf 'cocos2d::CameraBackgroundColorBrush'
    .supercls('cocos2d::CameraBackgroundDepthBrush')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::CameraBackgroundColorBrush *create(const cocos2d::Color4F &color, float depth)')
    .func(nil, 'void setColor(const cocos2d::Color4F &color)')
    .func(nil, 'CameraBackgroundColorBrush()')

typeconf 'cocos2d::CameraBackgroundSkyBoxBrush'
    .supercls('cocos2d::CameraBackgroundBrush')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::CameraBackgroundSkyBoxBrush *create(const std::string &positive_x, const std::string &negative_x, const std::string &positive_y, const std::string &negative_y, const std::string &positive_z, const std::string &negative_z)', 'static cocos2d::CameraBackgroundSkyBoxBrush *create()')
    .func(nil, 'void setTexture(cocos2d::TextureCube *texture)')
    .func(nil, 'bool isActived()')
    .func(nil, 'void setActived(bool actived)')
    .func(nil, 'void setTextureValid(bool valid)')
    .func(nil, 'CameraBackgroundSkyBoxBrush()')
    .prop('actived', nil, nil)

typeconf 'cocos2d::ParticleBatchNode'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleBatchNode *createWithTexture(cocos2d::Texture2D *tex, @optional int capacity)')
    .func(nil, 'static cocos2d::ParticleBatchNode *create(const std::string &fileImage, @optional int capacity)')
    .func(nil, 'void insertChild(cocos2d::ParticleSystem *system, int index)')
    .func(nil, 'void removeChildAtIndex(int index, bool doCleanup)')
    .func(nil, 'void disableParticle(int particleIndex)')
    .func(nil, 'cocos2d::TextureAtlas *getTextureAtlas()')
    .func(nil, 'void setTextureAtlas(cocos2d::TextureAtlas *atlas)')
    .func(nil, 'cocos2d::Texture2D *getTexture()')
    .func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'ParticleBatchNode()')
    .func(nil, 'bool initWithTexture(cocos2d::Texture2D *tex, int capacity)')
    .func(nil, 'bool initWithFile(const std::string &fileImage, int capacity)')
    .prop('textureAtlas', nil, nil)
    .prop('texture', nil, nil)
    .prop('blendFunc', nil, nil)

typeconf 'cocos2d::ParticleSystem::Mode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('GRAVITY', 'cocos2d::ParticleSystem::Mode::GRAVITY')
    .enum('RADIUS', 'cocos2d::ParticleSystem::Mode::RADIUS')

typeconf 'cocos2d::ParticleSystem::PositionType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('FREE', 'cocos2d::ParticleSystem::PositionType::FREE')
    .enum('RELATIVE', 'cocos2d::ParticleSystem::PositionType::RELATIVE')
    .enum('GROUPED', 'cocos2d::ParticleSystem::PositionType::GROUPED')

typeconf 'cocos2d::ParticleSystem'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleSystem *create(const std::string &plistFile)')
    .func(nil, 'static cocos2d::ParticleSystem *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'static Vector<cocos2d::ParticleSystem *> &getAllParticleSystems()')
    .func(nil, 'void addParticles(int count)')
    .func(nil, 'void stopSystem()')
    .func(nil, 'void resetSystem()')
    .func(nil, 'bool isFull()')
    .func(nil, 'void updateParticleQuads()')
    .func(nil, 'void postStep()')
    .func(nil, 'void updateWithNoTime()')
    .func(nil, 'bool isAutoRemoveOnFinish()')
    .func(nil, 'void setAutoRemoveOnFinish(bool var)')
    .func(nil, 'const cocos2d::Vec2 &getGravity()')
    .func(nil, 'void setGravity(const cocos2d::Vec2 &g)')
    .func(nil, 'float getSpeed()')
    .func(nil, 'void setSpeed(float speed)')
    .func(nil, 'float getSpeedVar()')
    .func(nil, 'void setSpeedVar(float speed)')
    .func(nil, 'float getTangentialAccel()')
    .func(nil, 'void setTangentialAccel(float t)')
    .func(nil, 'float getTangentialAccelVar()')
    .func(nil, 'void setTangentialAccelVar(float t)')
    .func(nil, 'float getRadialAccel()')
    .func(nil, 'void setRadialAccel(float t)')
    .func(nil, 'float getRadialAccelVar()')
    .func(nil, 'void setRadialAccelVar(float t)')
    .func(nil, 'bool getRotationIsDir()')
    .func(nil, 'void setRotationIsDir(bool t)')
    .func(nil, 'float getStartRadius()')
    .func(nil, 'void setStartRadius(float startRadius)')
    .func(nil, 'float getStartRadiusVar()')
    .func(nil, 'void setStartRadiusVar(float startRadiusVar)')
    .func(nil, 'float getEndRadius()')
    .func(nil, 'void setEndRadius(float endRadius)')
    .func(nil, 'float getEndRadiusVar()')
    .func(nil, 'void setEndRadiusVar(float endRadiusVar)')
    .func(nil, 'float getRotatePerSecond()')
    .func(nil, 'void setRotatePerSecond(float degrees)')
    .func(nil, 'float getRotatePerSecondVar()')
    .func(nil, 'void setRotatePerSecondVar(float degrees)')
    .func(nil, 'bool isActive()')
    .func(nil, 'bool isBlendAdditive()')
    .func(nil, 'void setBlendAdditive(bool value)')
    .func(nil, 'cocos2d::ParticleBatchNode *getBatchNode()')
    .func(nil, 'void setBatchNode(cocos2d::ParticleBatchNode *batchNode)')
    .func(nil, 'int getAtlasIndex()')
    .func(nil, 'void setAtlasIndex(int index)')
    .func(nil, 'unsigned int getParticleCount()')
    .func(nil, 'float getDuration()')
    .func(nil, 'void setDuration(float duration)')
    .func(nil, 'const cocos2d::Vec2 &getSourcePosition()')
    .func(nil, 'void setSourcePosition(const cocos2d::Vec2 &pos)')
    .func(nil, 'const cocos2d::Vec2 &getPosVar()')
    .func(nil, 'void setPosVar(const cocos2d::Vec2 &pos)')
    .func(nil, 'float getLife()')
    .func(nil, 'void setLife(float life)')
    .func(nil, 'float getLifeVar()')
    .func(nil, 'void setLifeVar(float lifeVar)')
    .func(nil, 'float getAngle()')
    .func(nil, 'void setAngle(float angle)')
    .func(nil, 'float getAngleVar()')
    .func(nil, 'void setAngleVar(float angleVar)')
    .func(nil, 'cocos2d::ParticleSystem::Mode getEmitterMode()')
    .func(nil, 'void setEmitterMode(cocos2d::ParticleSystem::Mode mode)')
    .func(nil, 'float getStartSize()')
    .func(nil, 'void setStartSize(float startSize)')
    .func(nil, 'float getStartSizeVar()')
    .func(nil, 'void setStartSizeVar(float sizeVar)')
    .func(nil, 'float getEndSize()')
    .func(nil, 'void setEndSize(float endSize)')
    .func(nil, 'float getEndSizeVar()')
    .func(nil, 'void setEndSizeVar(float sizeVar)')
    .func(nil, 'const cocos2d::Color4F &getStartColor()')
    .func(nil, 'void setStartColor(const cocos2d::Color4F &color)')
    .func(nil, 'const cocos2d::Color4F &getStartColorVar()')
    .func(nil, 'void setStartColorVar(const cocos2d::Color4F &color)')
    .func(nil, 'const cocos2d::Color4F &getEndColor()')
    .func(nil, 'void setEndColor(const cocos2d::Color4F &color)')
    .func(nil, 'const cocos2d::Color4F &getEndColorVar()')
    .func(nil, 'void setEndColorVar(const cocos2d::Color4F &color)')
    .func(nil, 'float getStartSpin()')
    .func(nil, 'void setStartSpin(float spin)')
    .func(nil, 'float getStartSpinVar()')
    .func(nil, 'void setStartSpinVar(float pinVar)')
    .func(nil, 'float getEndSpin()')
    .func(nil, 'void setEndSpin(float endSpin)')
    .func(nil, 'float getEndSpinVar()')
    .func(nil, 'void setEndSpinVar(float endSpinVar)')
    .func(nil, 'float getEmissionRate()')
    .func(nil, 'void setEmissionRate(float rate)')
    .func(nil, 'int getTotalParticles()')
    .func(nil, 'void setTotalParticles(int totalParticles)')
    .func(nil, 'cocos2d::ParticleSystem::PositionType getPositionType()')
    .func(nil, 'void setPositionType(cocos2d::ParticleSystem::PositionType type)')
    .func(nil, 'cocos2d::Texture2D *getTexture()')
    .func(nil, 'void setTexture(cocos2d::Texture2D *texture)')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'const std::string &getResourceFile()')
    .func(nil, 'void start()')
    .func(nil, 'void stop()')
    .func(nil, 'void setSourcePositionCompatible(bool sourcePositionCompatible)')
    .func(nil, 'bool isSourcePositionCompatible()')
    .func(nil, 'ParticleSystem()')
    .func(nil, 'bool initWithFile(const std::string &plistFile)')
    .func(nil, 'bool initWithDictionary(cocos2d::ValueMap &dictionary)', 'bool initWithDictionary(cocos2d::ValueMap &dictionary, const std::string &dirname)')
    .func(nil, 'bool initWithTotalParticles(int numberOfParticles)')
    .func(nil, 'bool isPaused()')
    .func(nil, 'void pauseEmissions()')
    .func(nil, 'void resumeEmissions()')
    .prop('allParticleSystems', nil, nil)
    .prop('full', nil, nil)
    .prop('autoRemoveOnFinish', nil, nil)
    .prop('gravity', nil, nil)
    .prop('speed', nil, nil)
    .prop('speedVar', nil, nil)
    .prop('tangentialAccel', nil, nil)
    .prop('tangentialAccelVar', nil, nil)
    .prop('radialAccel', nil, nil)
    .prop('radialAccelVar', nil, nil)
    .prop('rotationIsDir', nil, nil)
    .prop('startRadius', nil, nil)
    .prop('startRadiusVar', nil, nil)
    .prop('endRadius', nil, nil)
    .prop('endRadiusVar', nil, nil)
    .prop('rotatePerSecond', nil, nil)
    .prop('rotatePerSecondVar', nil, nil)
    .prop('active', nil, nil)
    .prop('blendAdditive', nil, nil)
    .prop('batchNode', nil, nil)
    .prop('atlasIndex', nil, nil)
    .prop('particleCount', nil, nil)
    .prop('duration', nil, nil)
    .prop('sourcePosition', nil, nil)
    .prop('posVar', nil, nil)
    .prop('life', nil, nil)
    .prop('lifeVar', nil, nil)
    .prop('angle', nil, nil)
    .prop('angleVar', nil, nil)
    .prop('emitterMode', nil, nil)
    .prop('startSize', nil, nil)
    .prop('startSizeVar', nil, nil)
    .prop('endSize', nil, nil)
    .prop('endSizeVar', nil, nil)
    .prop('startColor', nil, nil)
    .prop('startColorVar', nil, nil)
    .prop('endColor', nil, nil)
    .prop('endColorVar', nil, nil)
    .prop('startSpin', nil, nil)
    .prop('startSpinVar', nil, nil)
    .prop('endSpin', nil, nil)
    .prop('endSpinVar', nil, nil)
    .prop('emissionRate', nil, nil)
    .prop('totalParticles', nil, nil)
    .prop('positionType', nil, nil)
    .prop('texture', nil, nil)
    .prop('blendFunc', nil, nil)
    .prop('resourceFile', nil, nil)
    .prop('sourcePositionCompatible', nil, nil)
    .prop('paused', nil, nil)

typeconf 'cocos2d::ParticleSystemQuad'
    .supercls('cocos2d::ParticleSystem')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleSystemQuad *create()', 'static cocos2d::ParticleSystemQuad *create(const std::string &filename)', 'static cocos2d::ParticleSystemQuad *create(cocos2d::ValueMap &dictionary)')
    .func(nil, 'static cocos2d::ParticleSystemQuad *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'void setDisplayFrame(cocos2d::SpriteFrame *spriteFrame)')
    .func(nil, 'void setTextureWithRect(cocos2d::Texture2D *texture, const cocos2d::Rect &rect)')
    .func(nil, 'void listenRendererRecreated(cocos2d::EventCustom *event)')
    .func(nil, 'ParticleSystemQuad()')

typeconf 'cocos2d::ParticleExplosion'
    .supercls('cocos2d::ParticleSystemQuad')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleExplosion *create()')
    .func(nil, 'static cocos2d::ParticleExplosion *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'ParticleExplosion()')

typeconf 'cocos2d::ParticleFire'
    .supercls('cocos2d::ParticleSystemQuad')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleFire *create()')
    .func(nil, 'static cocos2d::ParticleFire *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'ParticleFire()')

typeconf 'cocos2d::ParticleFireworks'
    .supercls('cocos2d::ParticleSystemQuad')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleFireworks *create()')
    .func(nil, 'static cocos2d::ParticleFireworks *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'ParticleFireworks()')

typeconf 'cocos2d::ParticleFlower'
    .supercls('cocos2d::ParticleSystemQuad')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleFlower *create()')
    .func(nil, 'static cocos2d::ParticleFlower *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'ParticleFlower()')

typeconf 'cocos2d::ParticleGalaxy'
    .supercls('cocos2d::ParticleSystemQuad')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleGalaxy *create()')
    .func(nil, 'static cocos2d::ParticleGalaxy *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'ParticleGalaxy()')

typeconf 'cocos2d::ParticleMeteor'
    .supercls('cocos2d::ParticleSystemQuad')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleMeteor *create()')
    .func(nil, 'static cocos2d::ParticleMeteor *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'ParticleMeteor()')

typeconf 'cocos2d::ParticleRain'
    .supercls('cocos2d::ParticleSystemQuad')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleRain *create()')
    .func(nil, 'static cocos2d::ParticleRain *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'ParticleRain()')

typeconf 'cocos2d::ParticleSmoke'
    .supercls('cocos2d::ParticleSystemQuad')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleSmoke *create()')
    .func(nil, 'static cocos2d::ParticleSmoke *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'ParticleSmoke()')

typeconf 'cocos2d::ParticleSnow'
    .supercls('cocos2d::ParticleSystemQuad')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleSnow *create()')
    .func(nil, 'static cocos2d::ParticleSnow *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'ParticleSnow()')

typeconf 'cocos2d::ParticleSpiral'
    .supercls('cocos2d::ParticleSystemQuad')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleSpiral *create()')
    .func(nil, 'static cocos2d::ParticleSpiral *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'ParticleSpiral()')

typeconf 'cocos2d::ParticleSun'
    .supercls('cocos2d::ParticleSystemQuad')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ParticleSun *create()')
    .func(nil, 'static cocos2d::ParticleSun *createWithTotalParticles(int numberOfParticles)')
    .func(nil, 'ParticleSun()')

typeconf 'cocos2d::TMXTileFlags'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('kTMXTileHorizontalFlag', 'cocos2d::TMXTileFlags::kTMXTileHorizontalFlag')
    .enum('kTMXTileVerticalFlag', 'cocos2d::TMXTileFlags::kTMXTileVerticalFlag')
    .enum('kTMXTileDiagonalFlag', 'cocos2d::TMXTileFlags::kTMXTileDiagonalFlag')
    .enum('kTMXFlipedAll', 'cocos2d::TMXTileFlags::kTMXFlipedAll')
    .enum('kTMXFlippedMask', 'cocos2d::TMXTileFlags::kTMXFlippedMask')

typeconf 'cocos2d::TMXObjectGroup'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'TMXObjectGroup()')
    .func(nil, 'const std::string &getGroupName()')
    .func(nil, 'void setGroupName(const std::string &groupName)')
    .func(nil, 'cocos2d::Value getProperty(const std::string &propertyName)')
    .func(nil, 'cocos2d::ValueMap getObject(const std::string &objectName)')
    .func(nil, 'const cocos2d::Vec2 &getPositionOffset()')
    .func(nil, 'void setPositionOffset(const cocos2d::Vec2 &offset)')
    .func(nil, 'const cocos2d::ValueMap &getProperties()')
    .func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
    .func(nil, 'const cocos2d::ValueVector &getObjects()')
    .func(nil, 'void setObjects(const cocos2d::ValueVector &objects)')
    .prop('groupName', nil, nil)
    .prop('positionOffset', nil, nil)
    .prop('properties', nil, nil)
    .prop('objects', nil, nil)

typeconf 'cocos2d::TMXLayer'
    .supercls('cocos2d::SpriteBatchNode')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TMXLayer *create(cocos2d::TMXTilesetInfo *tilesetInfo, cocos2d::TMXLayerInfo *layerInfo, cocos2d::TMXMapInfo *mapInfo)')
    .func(nil, 'TMXLayer()')
    .func(nil, 'bool initWithTilesetInfo(cocos2d::TMXTilesetInfo *tilesetInfo, cocos2d::TMXLayerInfo *layerInfo, cocos2d::TMXMapInfo *mapInfo)')
    .func(nil, 'void releaseMap()')
    .func(nil, 'cocos2d::Sprite *getTileAt(const cocos2d::Vec2 &tileCoordinate)')
    .func(nil, 'uint32_t getTileGIDAt(const cocos2d::Vec2 &tileCoordinate, @out cocos2d::TMXTileFlags *flags)')
    .func(nil, 'void setTileGID(uint32_t gid, const cocos2d::Vec2 &tileCoordinate)', 'void setTileGID(uint32_t gid, const cocos2d::Vec2 &tileCoordinate, cocos2d::TMXTileFlags flags)')
    .func(nil, 'void removeTileAt(const cocos2d::Vec2 &tileCoordinate)')
    .func(nil, 'cocos2d::Vec2 getPositionAt(const cocos2d::Vec2 &tileCoordinate)')
    .func(nil, 'cocos2d::Value getProperty(const std::string &propertyName)')
    .func(nil, 'void setupTiles()')
    .func(nil, 'const std::string &getLayerName()')
    .func(nil, 'void setLayerName(const std::string &layerName)')
    .func(nil, 'const cocos2d::Size &getLayerSize()')
    .func(nil, 'void setLayerSize(const cocos2d::Size &size)')
    .func(nil, 'const cocos2d::Size &getMapTileSize()')
    .func(nil, 'void setMapTileSize(const cocos2d::Size &size)')
    .func(nil, 'cocos2d::TMXTilesetInfo *getTileSet()')
    .func(nil, 'void setTileSet(cocos2d::TMXTilesetInfo *info)')
    .func(nil, 'int getLayerOrientation()')
    .func(nil, 'void setLayerOrientation(int orientation)')
    .func(nil, 'const cocos2d::ValueMap &getProperties()')
    .func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
    .prop('layerName', nil, nil)
    .prop('layerSize', nil, nil)
    .prop('mapTileSize', nil, nil)
    .prop('tileSet', nil, nil)
    .prop('layerOrientation', nil, nil)
    .prop('properties', nil, nil)

typeconf 'cocos2d::TMXLayerInfo'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'TMXLayerInfo()')
    .func(nil, 'void setProperties(cocos2d::ValueMap properties)')
    .func(nil, 'cocos2d::ValueMap &getProperties()')
    .prop('properties', nil, nil)

typeconf 'cocos2d::TMXMapInfo'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TMXMapInfo *create(const std::string &tmxFile)')
    .func(nil, 'static cocos2d::TMXMapInfo *createWithXML(const std::string &tmxString, const std::string &resourcePath)')
    .func(nil, 'TMXMapInfo()')
    .func(nil, 'bool initWithTMXFile(const std::string &tmxFile)')
    .func(nil, 'bool initWithXML(const std::string &tmxString, const std::string &resourcePath)')
    .func(nil, 'bool parseXMLFile(const std::string &xmlFilename)')
    .func(nil, 'bool parseXMLString(const std::string &xmlString)')
    .func(nil, 'cocos2d::ValueMapIntKey &getTileProperties()')
    .func(nil, 'void setTileProperties(const cocos2d::ValueMapIntKey &tileProperties)')
    .func(nil, 'int getOrientation()')
    .func(nil, 'void setOrientation(int orientation)')
    .func(nil, 'int getStaggerAxis()')
    .func(nil, 'void setStaggerAxis(int staggerAxis)')
    .func(nil, 'int getStaggerIndex()')
    .func(nil, 'void setStaggerIndex(int staggerIndex)')
    .func(nil, 'int getHexSideLength()')
    .func(nil, 'void setHexSideLength(int hexSideLength)')
    .func(nil, 'const cocos2d::Size &getMapSize()')
    .func(nil, 'void setMapSize(const cocos2d::Size &mapSize)')
    .func(nil, 'const cocos2d::Size &getTileSize()')
    .func(nil, 'void setTileSize(const cocos2d::Size &tileSize)')
    .func(nil, 'const Vector<cocos2d::TMXLayerInfo *> &getLayers()')
    .func(nil, 'void setLayers(const Vector<cocos2d::TMXLayerInfo *> &layers)')
    .func(nil, 'const Vector<cocos2d::TMXTilesetInfo *> &getTilesets()')
    .func(nil, 'void setTilesets(const Vector<cocos2d::TMXTilesetInfo *> &tilesets)')
    .func(nil, 'const Vector<cocos2d::TMXObjectGroup *> &getObjectGroups()')
    .func(nil, 'void setObjectGroups(const Vector<cocos2d::TMXObjectGroup *> &groups)')
    .func(nil, 'int getParentElement()')
    .func(nil, 'void setParentElement(int element)')
    .func(nil, 'int getParentGID()')
    .func(nil, 'void setParentGID(int gid)')
    .func(nil, 'int getLayerAttribs()')
    .func(nil, 'void setLayerAttribs(int layerAttribs)')
    .func(nil, 'bool isStoringCharacters()')
    .func(nil, 'void setStoringCharacters(bool storingCharacters)')
    .func(nil, 'const cocos2d::ValueMap &getProperties()')
    .func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
    .func(nil, 'void endElement(void *ctx, const char *name)')
    .func(nil, 'void textHandler(void *ctx, const char *ch, size_t len)')
    .func(nil, 'const std::string &getCurrentString()')
    .func(nil, 'void setCurrentString(const std::string &currentString)')
    .func(nil, 'const std::string &getTMXFileName()')
    .func(nil, 'void setTMXFileName(const std::string &fileName)')
    .func(nil, 'const std::string &getExternalTilesetFileName()')
    .prop('tileProperties', nil, nil)
    .prop('orientation', nil, nil)
    .prop('staggerAxis', nil, nil)
    .prop('staggerIndex', nil, nil)
    .prop('hexSideLength', nil, nil)
    .prop('mapSize', nil, nil)
    .prop('tileSize', nil, nil)
    .prop('layers', nil, nil)
    .prop('tilesets', nil, nil)
    .prop('objectGroups', nil, nil)
    .prop('parentElement', nil, nil)
    .prop('parentGID', nil, nil)
    .prop('layerAttribs', nil, nil)
    .prop('storingCharacters', nil, nil)
    .prop('properties', nil, nil)
    .prop('currentString', nil, nil)
    .prop('tmxFileName', nil, nil)
    .prop('externalTilesetFileName', nil, nil)

typeconf 'cocos2d::TMXTilesetInfo'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'TMXTilesetInfo()')
    .func(nil, 'cocos2d::Rect getRectForGID(uint32_t gid)')

typeconf 'cocos2d::TMXTiledMap'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TMXTiledMap *create(const std::string &tmxFile)')
    .func(nil, 'static cocos2d::TMXTiledMap *createWithXML(const std::string &tmxString, const std::string &resourcePath)')
    .func(nil, 'cocos2d::TMXLayer *getLayer(const std::string &layerName)')
    .func(nil, 'cocos2d::TMXObjectGroup *getObjectGroup(const std::string &groupName)')
    .func(nil, 'cocos2d::Value getProperty(const std::string &propertyName)')
    .func(nil, 'cocos2d::Value getPropertiesForGID(int GID)')
    .func(nil, 'const cocos2d::Size &getMapSize()')
    .func(nil, 'void setMapSize(const cocos2d::Size &mapSize)')
    .func(nil, 'const cocos2d::Size &getTileSize()')
    .func(nil, 'void setTileSize(const cocos2d::Size &tileSize)')
    .func(nil, 'int getMapOrientation()')
    .func(nil, 'void setMapOrientation(int mapOrientation)')
    .func(nil, 'const Vector<cocos2d::TMXObjectGroup *> &getObjectGroups()')
    .func(nil, 'void setObjectGroups(const Vector<cocos2d::TMXObjectGroup *> &groups)')
    .func(nil, 'cocos2d::ValueMap &getProperties()')
    .func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
    .func(nil, 'int getLayerNum()')
    .func(nil, 'const std::string &getResourceFile()')
    .func(nil, 'TMXTiledMap()')
    .func(nil, 'bool initWithTMXFile(const std::string &tmxFile)')
    .func(nil, 'bool initWithXML(const std::string &tmxString, const std::string &resourcePath)')
    .prop('mapSize', nil, nil)
    .prop('tileSize', nil, nil)
    .prop('mapOrientation', nil, nil)
    .prop('objectGroups', nil, nil)
    .prop('properties', nil, nil)
    .prop('layerNum', nil, nil)
    .prop('resourceFile', nil, nil)

typeconf 'cocos2d::FastTMXTiledMap'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FastTMXTiledMap *create(const std::string &tmxFile)')
    .func(nil, 'static cocos2d::FastTMXTiledMap *createWithXML(const std::string &tmxString, const std::string &resourcePath)')
    .func(nil, 'cocos2d::FastTMXLayer *getLayer(const std::string &layerName)')
    .func(nil, 'cocos2d::TMXObjectGroup *getObjectGroup(const std::string &groupName)')
    .func(nil, 'cocos2d::Value getProperty(const std::string &propertyName)')
    .func(nil, 'cocos2d::Value getPropertiesForGID(int GID)')
    .func(nil, 'const cocos2d::Size &getMapSize()')
    .func(nil, 'void setMapSize(const cocos2d::Size &mapSize)')
    .func(nil, 'const cocos2d::Size &getTileSize()')
    .func(nil, 'void setTileSize(const cocos2d::Size &tileSize)')
    .func(nil, 'int getMapOrientation()')
    .func(nil, 'void setMapOrientation(int mapOrientation)')
    .func(nil, 'const Vector<cocos2d::TMXObjectGroup *> &getObjectGroups()')
    .func(nil, 'void setObjectGroups(const Vector<cocos2d::TMXObjectGroup *> &groups)')
    .func(nil, 'const cocos2d::ValueMap &getProperties()')
    .func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
    .prop('mapSize', nil, nil)
    .prop('tileSize', nil, nil)
    .prop('mapOrientation', nil, nil)
    .prop('objectGroups', nil, nil)
    .prop('properties', nil, nil)

typeconf 'cocos2d::FastTMXLayer'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('FAST_TMX_ORIENTATION_ORTHO', 'cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_ORTHO', 'const int')
    .const('FAST_TMX_ORIENTATION_HEX', 'cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_HEX', 'const int')
    .const('FAST_TMX_ORIENTATION_ISO', 'cocos2d::FastTMXLayer::FAST_TMX_ORIENTATION_ISO', 'const int')
    .func(nil, 'static cocos2d::FastTMXLayer *create(cocos2d::TMXTilesetInfo *tilesetInfo, cocos2d::TMXLayerInfo *layerInfo, cocos2d::TMXMapInfo *mapInfo)')
    .func(nil, 'FastTMXLayer()')
    .func(nil, 'int getTileGIDAt(const cocos2d::Vec2 &tileCoordinate, @out cocos2d::TMXTileFlags *flags)')
    .func(nil, 'void setTileGID(int gid, const cocos2d::Vec2 &tileCoordinate)', 'void setTileGID(int gid, const cocos2d::Vec2 &tileCoordinate, cocos2d::TMXTileFlags flags)')
    .func(nil, 'void removeTileAt(const cocos2d::Vec2 &tileCoordinate)')
    .func(nil, 'cocos2d::Vec2 getPositionAt(const cocos2d::Vec2 &tileCoordinate)')
    .func(nil, 'cocos2d::Value getProperty(const std::string &propertyName)')
    .func(nil, 'void setupTiles()')
    .func(nil, 'const std::string &getLayerName()')
    .func(nil, 'void setLayerName(const std::string &layerName)')
    .func(nil, 'const cocos2d::Size &getLayerSize()')
    .func(nil, 'void setLayerSize(const cocos2d::Size &size)')
    .func(nil, 'const cocos2d::Size &getMapTileSize()')
    .func(nil, 'void setMapTileSize(const cocos2d::Size &size)')
    .func(nil, 'cocos2d::TMXTilesetInfo *getTileSet()')
    .func(nil, 'void setTileSet(cocos2d::TMXTilesetInfo *info)')
    .func(nil, 'int getLayerOrientation()')
    .func(nil, 'void setLayerOrientation(int orientation)')
    .func(nil, 'const cocos2d::ValueMap &getProperties()')
    .func(nil, 'void setProperties(const cocos2d::ValueMap &properties)')
    .func(nil, 'cocos2d::Sprite *getTileAt(const cocos2d::Vec2 &tileCoordinate)')
    .func(nil, 'void setupTileSprite(cocos2d::Sprite *sprite, const cocos2d::Vec2 &pos, uint32_t gid)')
    .prop('layerName', nil, nil)
    .prop('layerSize', nil, nil)
    .prop('mapTileSize', nil, nil)
    .prop('tileSet', nil, nil)
    .prop('layerOrientation', nil, nil)
    .prop('properties', nil, nil)

typeconf 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NONE', 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NONE')
    .enum('NODE_TO_AGENT', 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NODE_TO_AGENT')
    .enum('AGENT_TO_NODE', 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::AGENT_TO_NODE')
    .enum('NODE_AND_NODE', 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag::NODE_AND_NODE')

typeconf 'cocos2d::NavMeshAgent'
    .supercls('cocos2d::Component')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::NavMeshAgent *create(const cocos2d::NavMeshAgentParam &param)')
    .func(nil, 'static const std::string &getNavMeshAgentComponentName()')
    .func(nil, 'void setRadius(float radius)')
    .func(nil, 'float getRadius()')
    .func(nil, 'void setHeight(float height)')
    .func(nil, 'float getHeight()')
    .func(nil, 'void setMaxAcceleration(float maxAcceleration)')
    .func(nil, 'float getMaxAcceleration()')
    .func(nil, 'void setMaxSpeed(float maxSpeed)')
    .func(nil, 'float getMaxSpeed()')
    .func(nil, 'void setSeparationWeight(float weight)')
    .func(nil, 'float getSeparationWeight()')
    .func(nil, 'void setObstacleAvoidanceType(unsigned char type)')
    .func(nil, 'unsigned char getObstacleAvoidanceType()')
    .func(nil, 'cocos2d::Vec3 getCurrentVelocity()')
    .func(nil, 'void pause()')
    .func(nil, 'void resume()')
    .func(nil, 'void stop()')
    .func(nil, 'void setOrientationRefAxes(const cocos2d::Vec3 &rotRefAxes)')
    .func(nil, 'void setAutoOrientation(bool isAuto)')
    .func(nil, 'void setAutoTraverseOffMeshLink(bool isAuto)')
    .func(nil, 'bool isOnOffMeshLink()')
    .func(nil, 'void completeOffMeshLink()')
    .func(nil, 'cocos2d::OffMeshLinkData getCurrentOffMeshLinkData()')
    .func(nil, 'void setUserData(void *data)')
    .func(nil, 'void *getUserData()')
    .func(nil, 'void setSyncFlag(const cocos2d::NavMeshAgent::NavMeshAgentSyncFlag &flag)')
    .func(nil, 'cocos2d::NavMeshAgent::NavMeshAgentSyncFlag getSyncFlag()')
    .func(nil, 'void syncToAgent()')
    .func(nil, 'void syncToNode()')
    .func(nil, 'cocos2d::Vec3 getVelocity()')
    .func(nil, 'NavMeshAgent()')
    .callback {
        FUNCS =  {
            'void move(const cocos2d::Vec3 &destination, @local @optional const std::function<void (cocos2d::NavMeshAgent *, float)> &callback)'
        },
        TAG_MAKER = 'move',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .prop('navMeshAgentComponentName', nil, nil)
    .prop('radius', nil, nil)
    .prop('height', nil, nil)
    .prop('maxAcceleration', nil, nil)
    .prop('maxSpeed', nil, nil)
    .prop('separationWeight', nil, nil)
    .prop('obstacleAvoidanceType', nil, nil)
    .prop('currentVelocity', nil, nil)
    .prop('onOffMeshLink', nil, nil)
    .prop('currentOffMeshLinkData', nil, nil)
    .prop('userData', nil, nil)
    .prop('syncFlag', nil, nil)
    .prop('velocity', nil, nil)

typeconf 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NONE', 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NONE')
    .enum('NODE_TO_OBSTACLE', 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NODE_TO_OBSTACLE')
    .enum('OBSTACLE_TO_NODE', 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::OBSTACLE_TO_NODE')
    .enum('NODE_AND_NODE', 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag::NODE_AND_NODE')

typeconf 'cocos2d::NavMeshObstacle'
    .supercls('cocos2d::Component')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::NavMeshObstacle *create(float radius, float height)')
    .func(nil, 'static const std::string &getNavMeshObstacleComponentName()')
    .func(nil, 'void setRadius(float radius)')
    .func(nil, 'float getRadius()')
    .func(nil, 'void setHeight(float height)')
    .func(nil, 'float getHeight()')
    .func(nil, 'void setSyncFlag(const cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag &flag)')
    .func(nil, 'cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag getSyncFlag()')
    .func(nil, 'void syncToObstacle()')
    .func(nil, 'void syncToNode()')
    .func(nil, 'NavMeshObstacle()')
    .func(nil, 'bool initWith(float radius, float height)')
    .prop('navMeshObstacleComponentName', nil, nil)
    .prop('radius', nil, nil)
    .prop('height', nil, nil)
    .prop('syncFlag', nil, nil)

typeconf 'cocos2d::NavMesh'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void update(float dt)')
    .func(nil, 'void debugDraw(cocos2d::Renderer *renderer)')
    .func(nil, 'void setDebugDrawEnable(bool enable)')
    .func(nil, 'bool isDebugDrawEnabled()')
    .func(nil, 'void addNavMeshAgent(cocos2d::NavMeshAgent *agent)')
    .func(nil, 'void removeNavMeshAgent(cocos2d::NavMeshAgent *agent)')
    .func(nil, 'void addNavMeshObstacle(cocos2d::NavMeshObstacle *obstacle)')
    .func(nil, 'void removeNavMeshObstacle(cocos2d::NavMeshObstacle *obstacle)')
    .func(nil, 'void findPath(const cocos2d::Vec3 &start, const cocos2d::Vec3 &end, std::vector<Vec3> &pathPoints)')
    .func(nil, 'NavMesh()')
    .prop('debugDrawEnabled', nil, nil)
