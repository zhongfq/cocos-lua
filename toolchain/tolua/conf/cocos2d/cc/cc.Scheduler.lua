local cls = class()
cls.CPPCLS = "cocos2d::Scheduler"
cls.LUACLS = "cc.Scheduler"
cls.SUPERCLS = "cc.Ref"
cls.prop('timeScale', 'float getTimeScale()', 'void setTimeScale(float timeScale)')
cls.func('new', new_ccobj(cls))
cls.func(nil, 'void update(float dt)')
cls.func('schedule', [[
{
    int num_args = lua_gettop(L) - 1;

    lua_settop(L, 8);

    cocos2d::Ref *target = nullptr;
    float interval = 0;
    unsigned int repeat = CC_REPEAT_FOREVER;
    float delay = 0;
    bool paused = false;
    std::string key;

    cocos2d::Scheduler *self = (cocos2d::Scheduler *)tolua_toobj(L, 1, "cc.Scheduler");

    if (num_args == 5) {
        xluacv_check_ccobj(L, 3, (void **)&target, "cc.Ref");
        interval = (float)luaL_checknumber(L, 4);
        paused = xlua_checkboolean(L, 5);
        key = lua_tostring(L, 6);
    } else if (num_args == 8) {
        xluacv_check_ccobj(L, 3, (void **)&target, "cc.Ref");
        interval = (float)luaL_checknumber(L, 4);
        repeat = (unsigned int)luaL_checkinteger(L, 5);
        delay = (float)luaL_checknumber(L, 6);
        paused = xlua_checkboolean(L, 7);
        key = lua_tostring(L, 8);
    } else {
        luaL_error(L, "method 'cocos2d::Node::schedule' not support '%d' arguments", num_args);
    }

    std::string field = makeScheduleCallbackTag(key);
    field = tolua_setcallback(L, 1, field.c_str(), 2);
    self->schedule([field, self](float delta) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushnumber(L, delta);
        tolua_callback(L, self, field.c_str(), 1);
        lua_settop(L, top);
    }, target, interval, repeat, delay, paused, key);

    return 0;
}]])
cls.func('unschedule', [[
{
    lua_settop(L, 3);
    
    cocos2d::Scheduler *self = nullptr;
    cocos2d::Ref *target = nullptr;
    std::string key;
    
    self = (cocos2d::Scheduler *)tolua_toobj(L, 1, "cc.Scheduler");
    tolua_check_std_string(L, 2, &key);
    xluacv_check_ccobj(L, 3, (void **)&target, "cc.Ref");
    
    std::string field = makeScheduleCallbackTag(key);
    
    self->unschedule(key, target);
    tolua_removecallback(L, 1, field.c_str(), TOLUA_REMOVE_CALLBACK_EQUAL);
    
    return 0;
}]])
return cls