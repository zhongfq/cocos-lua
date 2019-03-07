local cls = class()
cls.CPPCLS = "cocos2d::Scheduler"
cls.LUACLS = "cc.Scheduler"
cls.SUPERCLS = "cc.Ref"
cls.DEFCHUNK = [[
static const std::string makeScheduleCallbackTag(void *obj, const std::string &key)
{
    if (obj == nullptr) {
        return "schedule.";
    }
    
    char name[64];
    sprintf(name, "schedule.%p.", obj);
    return name + key;
}

template <typename T> bool doScheduleUpdate(lua_State *L, const char *cls)
{
    if (xluacv_is_ccobj(L, 2, cls)) {
        cocos2d::Scheduler *self = nullptr;
        lua_Integer arg2 = 0;
        bool arg3 = false;
        
        xluacv_to_ccobj(L, 1, (void **)&self, "cc.Scheduler");
        tolua_check_int(L, 3, &arg2);
        tolua_check_bool(L, 4, &arg3);
        
        T* arg1 = nullptr;
        xluacv_to_ccobj(L, 2, (void **)&arg1, cls);
        self->scheduleUpdate(arg1, (int)arg2, arg3);
        
        return true;
    }
    
    return false;
}]]
cls.prop('timeScale', 'float getTimeScale()', 'void setTimeScale(float timeScale)')
cls.func('new', new_ccobj(cls))
cls.func(nil, 'void update(float dt)')
cls.callback(nil, {
        MAKER = 'makeScheduleCallbackTag(#2, #-1)',
        STANDALONE = true,
    },
    'void schedule(const std::function<void(float)>& callback, void *target, float interval, bool paused, const std::string& key)',
    'void schedule(const std::function<void(float)>& callback, void *target, float interval, unsigned int repeat, float delay, bool paused, const std::string& key)'
)
cls.callback(nil, {
        MAKER = 'makeScheduleCallbackTag(#2, #1)',
        REMOVED_MODE = 'TOLUA_CALLBACK_TAG_ENDWITH',
    },
    'void unschedule(const std::string& key, void *target)'
)
cls.callback(nil, {
        MAKER = 'makeScheduleCallbackTag(#1, "")',
        REMOVED_MODE = 'TOLUA_CALLBACK_TAG_WILDCARD',
    },
    'void unscheduleAllForTarget(void *target)'
)
cls.callback(nil, {
        MAKER = 'makeScheduleCallbackTag(nullptr, "")',
        REMOVED_MODE = 'TOLUA_CALLBACK_TAG_WILDCARD',
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
    
    luaL_error(L, "unsupport type: %s", tolua_tostring(L, 2));

    return 0;
}]])
cls.func(nil, 'void unscheduleUpdate(void *target)')
cls.func(nil, 'void unscheduleAllWithMinPriority(int minPriority)')
cls.func(nil, 'bool isScheduled(const std::string& key, const void *target)')
cls.func(nil, 'void pauseTarget(void *target)')
cls.func(nil, 'void resumeTarget(void *target)')
cls.func(nil, 'bool isTargetPaused(void *target)')
return cls