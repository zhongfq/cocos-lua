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
cls.func('schedule', [[
{
    int num_args = lua_gettop(L) - 1;

    lua_settop(L, 8);

    void *target = nullptr;
    float interval = 0;
    unsigned int repeat = CC_REPEAT_FOREVER;
    float delay = 0;
    bool paused = false;
    std::string key;

    cocos2d::Scheduler *self = (cocos2d::Scheduler *)tolua_toobj(L, 1, "cc.Scheduler");
    
    target = xlua_checkobj(L, 3);
    interval = (float)luaL_checknumber(L, 4);

    if (num_args == 5) {
        paused = xlua_checkboolean(L, 5);
        key = lua_tostring(L, 6);
    } else if (num_args == 7) {
        repeat = (unsigned int)luaL_checkinteger(L, 5);
        delay = (float)luaL_checknumber(L, 6);
        paused = xlua_checkboolean(L, 7);
        key = lua_tostring(L, 8);
    } else {
        luaL_error(L, "method 'cocos2d::Node::schedule' not support '%d' arguments", num_args);
    }

    std::string tag = makeScheduleCallbackTag(target, key);
    tolua_removecallback(L, 1, tag.c_str(), TOLUA_CALLBACK_TAG_ENDWITH);
    std::string func = tolua_setcallback(L, 1, tag.c_str(), 2);
    self->unschedule(key, target);
    self->schedule([self, func](float delta) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushnumber(L, delta);
        tolua_callback(L, self, func.c_str(), 1);
        lua_settop(L, top);
    }, target, interval, repeat, delay, paused, key);

    return 0;
}]])
cls.func('unschedule', [[
{
    lua_settop(L, 3);

    cocos2d::Scheduler *self = nullptr;
    void *target = nullptr;
    std::string key;

    self = (cocos2d::Scheduler *)tolua_toobj(L, 1, "cc.Scheduler");
    tolua_check_std_string(L, 2, &key);
    target = xlua_checkobj(L, 3);

    std::string tag = makeScheduleCallbackTag(target, key);

    self->unschedule(key, target);
    tolua_removecallback(L, 1, tag.c_str(), TOLUA_CALLBACK_TAG_ENDWITH);

    return 0;
}]])
cls.func('unscheduleAllForTarget', [[
{
    lua_settop(L, 2);
    
    cocos2d::Scheduler *self = nullptr;
    void *target = nullptr;
    
    self = (cocos2d::Scheduler *)tolua_toobj(L, 1, "cc.Scheduler");
    target = xlua_checkobj(L, 2);
    
    std::string tag = makeScheduleCallbackTag(target, "");
    
    self->unscheduleAllForTarget(target);
    tolua_removecallback(L, 1, tag.c_str(), TOLUA_CALLBACK_TAG_WILDCARD);
    
    return 0;
}]])
cls.func('unscheduleAll', [[
{
    lua_settop(L, 1);
    
    cocos2d::Scheduler *self = (cocos2d::Scheduler *)tolua_toobj(L, 1, "cc.Scheduler");
    std::string tag = makeScheduleCallbackTag(nullptr, "");
    self->unscheduleAll();
    tolua_removecallback(L, 1, tag.c_str(), TOLUA_CALLBACK_TAG_WILDCARD);
    
    return 0;
}]])
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