local cls = class()
cls.CPPCLS = "cocos2d::Scheduler"
cls.LUACLS = "cc.Scheduler"
cls.SUPERCLS = "cc.Ref"
cls.DEFCHUNK = [[
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
cls.prop('timeScale', 'float getTimeScale()', 'void setTimeScale(float timeScale)')
cls.func('new', new_ccobj(cls))
cls.func(nil, 'void update(float dt)')
cls.callback(nil, {
        TAG_MAKER = 'makeScheduleCallbackTag(#-1)',
        TAG_STORE = 2, -- 2th void *target
        ONLYONE = true,
    },
    'void schedule(const std::function<void(float)>& callback, void *target, float interval, bool paused, const std::string& key)',
    'void schedule(const std::function<void(float)>& callback, void *target, float interval, unsigned int repeat, float delay, bool paused, const std::string& key)'
)
cls.callback(nil, {
        TAG_MAKER = 'makeScheduleCallbackTag(#1)',
        TAG_STORE = 2, -- 2th void *target
        TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    },
    'void unschedule(const std::string& key, void *target)'
)
cls.callback(nil, {
        TAG_MAKER = 'makeScheduleCallbackTag("")',
        TAG_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
        TAG_STORE = 1, -- 1th void *target
    },
    'void unscheduleAllForTarget(void *target)'
)
cls.callback(nil, {
        TAG_MAKER = 'makeScheduleCallbackTag("")',
        TAG_MODE = 'OLUA_CALLBACK_TAG_WILDCARD',
    },
    'void unscheduleAll()'
)
cls.func('scheduleUpdate', [[
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
    
    luaL_error(L, "unsupport type: %s", olua_tostring(L, 2));

    return 0;
}]])
cls.funcs([[
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
]])

return cls