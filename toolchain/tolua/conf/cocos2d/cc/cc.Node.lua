local cls = class()
cls.CPPCLS = "cocos2d::Node"
cls.LUACLS = "cc.Node"
cls.SUPERCLS = "cc.Ref"
cls.prop('attachedNodeCount', 'static int getAttachedNodeCount()')
cls.prop('description', 'std::string getDescription()')
cls.prop('scheduler', 'Scheduler* getScheduler()', 'void setScheduler(Scheduler* scheduler)')
cls.func(nil, 'static cocos2d::Node *create()')
cls.func(nil, 'void addChild(cocos2d::Node * child)', 'void addChild(cocos2d::Node * child, int localZOrder)', 'void addChild(cocos2d::Node* child, int localZOrder, int tag)', 'void addChild(cocos2d::Node* child, int localZOrder, const std::string &name)')
cls.func(nil, 'cocos2d::Node *getChildByTag(int tag) const')
cls.func(nil, 'void removeFromParent()')
cls.func(nil, 'void removeFromParentAndCleanup(bool cleanup)')
cls.func(nil, 'void removeChild(cocos2d::Node* child, bool cleanup = true)')
cls.func(nil, 'void removeChildByTag(int tag, bool cleanup = true)')
cls.func(nil, 'void removeChildByName(const std::string &name, bool cleanup = true)')
cls.func(nil, 'void removeAllChildren()')
cls.func(nil, 'void removeAllChildrenWithCleanup(bool cleanup)')
cls.func(nil, 'void reorderChild(cocos2d::Node * child, int localZOrder)')
cls.func(nil, 'void sortAllChildren()')
cls.func(nil, 'void setPosition(pack const Vec2 &position)')
cls.func(nil, 'unpack const Vec2& getPosition()')
cls.func(nil, 'void scheduleUpdate(void)')
cls.func(nil, 'void unscheduleUpdate(void)')
cls.func(nil, 'void scheduleUpdateWithPriority(int priority)')
cls.func(nil, 'bool isScheduled(const std::string &key)')
cls.func('scheduleOnce', [[
{
    lua_settop(L, 4);

    cocos2d::Node *self = (cocos2d::Node *)tolua_toobj(L, 1, "cc.Node");
    lua_Number delay = luaL_checknumber(L, 3);
    std::string key = luaL_checkstring(L, 4);

    std::string field = "node.schedule." + key;
    field = tolua_setcallback(L, 1, field.c_str(), 2);
    self->scheduleOnce([field, self](float delta) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushnumber(L, delta);
        tolua_callback(L, self, field.c_str(), 1);
        if (tolua_getobj(L, self)) {
            tolua_removecallback(L, -1, field.c_str(), TOLUA_REMOVE_CALLBACK_EQUAL);
        }
        lua_settop(L, top);
    }, delay, key);

    return 0;
}]])
cls.func('schedule', [[
{
    int num_args = lua_gettop(L) - 1;
    
    lua_settop(L, 6);
    
    float interval = 0;
    unsigned int repeat = CC_REPEAT_FOREVER;
    float delay = 0;
    std::string key;
    
    cocos2d::Node *self = (cocos2d::Node *)tolua_toobj(L, 1, "cc.Node");
    
    if (num_args == 2) {
        key = luaL_checkstring(L, 3);
    } else if (num_args == 3) {
        interval = (float)luaL_checknumber(L, 3);
        key = luaL_checkstring(L, 4);
    } else if (num_args == 5) {
        interval = (float)luaL_checknumber(L, 3);
        repeat = (unsigned int)luaL_checkinteger(L, 4);
        delay = (float)luaL_checknumber(L, 5);
        key = luaL_checkstring(L, 6);
    } else {
         luaL_error(L, "method 'cocos2d::Node::schedule' not support '%d' arguments", num_args);
    }
    
    std::string field = "node.schedule." + key;
    field = tolua_setcallback(L, 1, field.c_str(), 2);
    self->schedule([field, self](float delta) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushnumber(L, delta);
        tolua_callback(L, self, field.c_str(), 1);
        lua_settop(L, top);
    }, interval, repeat, delay, key);
    
    return 0;
}]])
cls.func('unschedule', [[
{
    lua_settop(L, 2);
    
    cocos2d::Node *self = (cocos2d::Node *)tolua_toobj(L, 1, "cc.Node");
    std::string key = luaL_checkstring(L, 2);
    
    self->unschedule(key);
    tolua_removecallback(L, 1, key.c_str(), TOLUA_REMOVE_CALLBACK_ENDWITH);
    
    return 0;
}]])
cls.func('unscheduleAllCallbacks', [[
{
    lua_settop(L, 1);
    
    cocos2d::Node *self = (cocos2d::Node *)tolua_toobj(L, 1, "cc.Node");
    self->unscheduleAllCallbacks();
    
    std::string key = "node.schedule.";
    tolua_removecallback(L, 1, key.c_str(), TOLUA_REMOVE_CALLBACK_WILDCARD);
    
    return 0;
}]])

cls.func(nil, 'void resume(void)')
cls.func(nil, 'void pause(void)')
return cls