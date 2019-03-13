#include "xgame/lua-bindings/lua_cocos2d_ref_chain.h"

#define CLS_FUNC    ".func"
#define CLS_GET     ".get"
#define CLS_SET     ".set"

#define NODE_CHILDREN   ".children"
#define NODE_ACTIONS    ".actions"
#define DIRECTOR_SCENES ".scenes"

#define KEEP_SELF   true

static void set_func(lua_State *L, const char *t, const char *fn, lua_CFunction func, const char *refname)
{
    CCASSERT(fn, "");
    CCASSERT(refname, "");
    olua_rawgetfield(L, -1, t);                         // L: t
    if (olua_rawgetfield(L, -1, fn) == LUA_TFUNCTION) { // L: t old_func
        lua_pushfstring(L, ".%s", refname);             // L: t old_func name
        lua_pushcclosure(L, func, 2);                   // L: t new_func
        olua_rawsetfield(L, -2, fn);                    // L: t
        lua_pop(L, 1);                                  // L:
    } else {
        CCASSERT(false, "function not found'");
        lua_pop(L, 2);
    }
}

static void wrap_func(lua_State *L, const char *name, lua_CFunction func)
{
    set_func(L, CLS_FUNC, name, func, name);
}

static void wrap_get(lua_State *L, const char *fn, const char *prop, lua_CFunction func)
{
    set_func(L, CLS_FUNC, fn, func, prop);
    set_func(L, CLS_GET, prop, func, prop);
}

static void wrap_set(lua_State *L, const char *fn, const char *prop, lua_CFunction func)
{
    set_func(L, CLS_FUNC, fn, func, prop);
    set_func(L, CLS_SET, prop, func, prop);
}

static void call_real_function(lua_State *L, bool keepself)
{
    int args = lua_gettop(L);
    lua_pushvalue(L, lua_upvalueindex(1));      // L: arg1...argN func
    lua_insert(L, 1);                           // L: func arg1...argN
    if (keepself) {
        lua_pushvalue(L, 2);                    // L: func arg1...argN arg1
        lua_insert(L, 1);                       // L: arg1 func arg1...argN
    }
    lua_call(L, args, LUA_MULTRET);
}

static int wrap_ref_after_get(lua_State *L)
{
    const char *name = olua_checkstring(L, lua_upvalueindex(2));
    call_real_function(L, KEEP_SELF);
    olua_arrayref(L, 1, name, 2);
    lua_remove(L, 1);
    return lua_gettop(L);
}

static int wrap_ref_before_set(lua_State *L)
{
    const char *name = olua_checkstring(L, lua_upvalueindex(2));
    olua_arrayunref(L, 1, name, -1);
    olua_arrayref(L, 1, name, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

//
// Director
//
static int wrap_cocos2d_Director_getRunningScene(lua_State *L)
{
    call_real_function(L, KEEP_SELF);
    olua_arrayref(L, 1, DIRECTOR_SCENES, 2);
    lua_remove(L, 1);
    return lua_gettop(L);
}

// void runWithScene(Scene *scene)
// void pushScene(Scene *scene)
static int wrap_cocos2d_Director_pushScene(lua_State *L)
{
    olua_arrayref(L, 1, DIRECTOR_SCENES, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

// void popScene()
static int wrap_cocos2d_Director_popScene(lua_State *L)
{
    olua_arrayunref(L, 1, DIRECTOR_SCENES, -1);
    call_real_function(L, false);
    return lua_gettop(L);
}

// void popToRootScene()
static int wrap_cocos2d_Director_popToRootScene(lua_State *L)
{
    int len = (int)olua_arraylen(L, 1, DIRECTOR_SCENES);
    while (len > 1) {
        olua_arrayunref(L, 1, DIRECTOR_SCENES, len--);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

// void popToSceneStackLevel(int level)
static int wrap_cocos2d_Director_popToSceneStackLevel(lua_State *L)
{
    int level = (int)olua_checkinteger(L, 2);
    int len = (int)olua_arraylen(L, 1, DIRECTOR_SCENES);
    while (len > level) {
        olua_arrayunref(L, 1, DIRECTOR_SCENES, len--);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

// void replaceScene(Scene *scene)
static int wrap_cocos2d_Director_replaceScene(lua_State *L)
{
    olua_arrayunref(L, 1, DIRECTOR_SCENES, -1);
    olua_arrayref(L, 1, DIRECTOR_SCENES, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

static int wrap_cocos2d_Director(lua_State *L)
{
    luaL_getmetatable(L, "cc.Director");
    CCASSERT(olua_istable(L, -1), "not found 'cc.Director'");
    wrap_get(L, "getRunningScene", "runningScene", wrap_cocos2d_Director_getRunningScene);
    wrap_func(L, "runWithScene", wrap_cocos2d_Director_pushScene);
    wrap_func(L, "pushScene", wrap_cocos2d_Director_pushScene);
    wrap_func(L, "popScene", wrap_cocos2d_Director_popScene);
    wrap_func(L, "popToRootScene", wrap_cocos2d_Director_popToRootScene);
    wrap_func(L, "popToSceneStackLevel", wrap_cocos2d_Director_popToSceneStackLevel);
    wrap_func(L, "replaceScene", wrap_cocos2d_Director_replaceScene);
    
    wrap_get(L, "getTextureCache", "textureCache", wrap_ref_after_get);
    wrap_get(L, "getScheduler", "scheduler", wrap_ref_after_get);
    wrap_set(L, "setScheduler", "scheduler", wrap_ref_before_set);
    wrap_get(L, "getActionManager", "actionManager", wrap_ref_after_get);
    wrap_set(L, "setActionManager", "actionManager", wrap_ref_before_set);
    wrap_get(L, "getEventDispatcher", "eventDispatcher", wrap_ref_after_get);
    wrap_set(L, "setEventDispatcher", "eventDispatcher", wrap_ref_before_set);
    wrap_get(L, "getNotificationNode", "notificationNode", wrap_ref_after_get);
    wrap_set(L, "setNotificationNode", "notificationNode", wrap_ref_before_set);
    wrap_get(L, "getRenderer", "renderer", wrap_ref_after_get);
    return 0;
}

//
// Node
//
// void addChild(Node * child)
// void addChild(Node * child, int localZOrder)
// void addChild(Node* child, int localZOrder, int tag)
// void addChild(Node* child, int localZOrder, const std::string &name)
static int wrap_cocos2d_Node_addChild(lua_State *L)
{
    olua_mapref(L, 1, NODE_CHILDREN, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

// Node *getChildByTag(int tag) const
// Node *getChildByName(const std::string& name)
static int wrap_cocos2d_Node_getChild(lua_State *L)
{
    call_real_function(L, KEEP_SELF);
    olua_mapref(L, 1, NODE_CHILDREN, 2);
    lua_remove(L, 1);
    return lua_gettop(L);
}

// void removeFromParent()
// void removeFromParentAndCleanup(bool cleanup)
static int wrap_cocos2d_Node_removeFromParent(lua_State *L)
{
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Node *parent = self->getParent();
    if (olua_getobj(L, parent)) {
        olua_mapunref(L, -1, NODE_CHILDREN, 1);
        lua_pop(L, 1);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

// void removeChild(Node* child, bool cleanup = true)
static int wrap_cocos2d_Node_removeChild(lua_State *L)
{
    olua_mapunref(L, 1, NODE_CHILDREN, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

// void removeChildByTag(int tag, bool cleanup = true)
static int wrap_cocos2d_Node_removeChildByTag(lua_State *L)
{
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Node *child = self->getChildByTag((int)olua_checkinteger(L, 2));
    if (olua_getobj(L, child)) {
        olua_mapunref(L, 1, NODE_CHILDREN, -1);
        lua_pop(L, 1);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

// void removeChildByName(const std::string &name, bool cleanup = true)
static int wrap_cocos2d_Node_removeChildByName(lua_State *L)
{
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Node *child = self->getChildByName(olua_checkstring(L, 2));
    if (olua_getobj(L, child)) {
        olua_mapunref(L, 1, NODE_CHILDREN, -1);
        lua_pop(L, 1);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

// void removeAllChildren()
// void removeAllChildrenWithCleanup(bool cleanup)
static int wrap_cocos2d_Node_removeAllChildren(lua_State *L)
{
    olua_mapunrefall(L, 1, NODE_CHILDREN);
    call_real_function(L, false);
    return lua_gettop(L);
}

static int should_unref_action(lua_State *L)
{
    if (olua_isa(L, -2, "cc.Action")) {
        cocos2d::Action *act = olua_touserdata(L, -2, cocos2d::Action *);
        if (act && (!act->getTarget() || act->isDone() || act->getReferenceCount() == 1)) {
            return 1;
        }
    }
    return 0;
}

static void check_node_actions(lua_State *L)
{
    olua_mapwalkunref(L, 1, NODE_ACTIONS, should_unref_action);
}

// Action* runAction(Action* action)
static int wrap_cocos2d_Node_runAction(lua_State *L)
{
    check_node_actions(L);
    olua_mapref(L, 1, NODE_ACTIONS, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

// void stopAllActions()
static int wrap_cocos2d_Node_stopAllActions(lua_State *L)
{
    olua_mapunrefall(L, 1, NODE_ACTIONS);
    call_real_function(L, false);
    return lua_gettop(L);
}

// void stopAction(Action* action)
// void stopActionByTag(int tag)
// void stopAllActionsByTag(int tag)
// void stopActionsByFlags(unsigned int flags)
static int wrap_cocos2d_Node_stopAction(lua_State *L)
{
    call_real_function(L, KEEP_SELF);
    check_node_actions(L);
    lua_remove(L, 1);
    return lua_gettop(L);
}

// Action* getActionByTag(int tag)
static int wrap_cocos2d_Node_getActionByTag(lua_State *L)
{
    call_real_function(L, KEEP_SELF);
    olua_mapref(L, 1, NODE_ACTIONS, 2);
    lua_remove(L, 1);
    return lua_gettop(L);
}

static int wrap_cocos2d_Node(lua_State *L)
{
    luaL_getmetatable(L, "cc.Node");
    CCASSERT(olua_istable(L, -1), "not found 'cc.Node'");
    wrap_func(L, "addChild", wrap_cocos2d_Node_addChild);
    wrap_func(L, "getChildByName", wrap_cocos2d_Node_getChild);
    wrap_func(L, "getChildByTag", wrap_cocos2d_Node_getChild);
    wrap_func(L, "removeFromParent", wrap_cocos2d_Node_removeFromParent);
    wrap_func(L, "removeFromParentAndCleanup", wrap_cocos2d_Node_removeFromParent);
    wrap_func(L, "removeChild", wrap_cocos2d_Node_removeChild);
    wrap_func(L, "removeChildByTag", wrap_cocos2d_Node_removeChildByTag);
    wrap_func(L, "removeChildByName", wrap_cocos2d_Node_removeChildByName);
    wrap_func(L, "removeAllChildren", wrap_cocos2d_Node_removeAllChildren);
    wrap_func(L, "removeAllChildrenWithCleanup", wrap_cocos2d_Node_removeAllChildren);
    wrap_func(L, "runAction", wrap_cocos2d_Node_runAction);
    wrap_func(L, "stopAllActions", wrap_cocos2d_Node_stopAllActions);
    wrap_func(L, "stopAction", wrap_cocos2d_Node_stopAction);
    wrap_func(L, "stopActionByTag", wrap_cocos2d_Node_stopAction);
    wrap_func(L, "stopAllActionsByTag", wrap_cocos2d_Node_stopAction);
    wrap_func(L, "stopActionsByFlags", wrap_cocos2d_Node_stopAction);
    wrap_func(L, "getActionByTag", wrap_cocos2d_Node_getActionByTag);

    return 0;
}

LUALIB_API int luaopen_cocos2d_ref_chain(lua_State *L)
{
    xlua_call(L, wrap_cocos2d_Director);
    xlua_call(L, wrap_cocos2d_Node);
    
    luaL_getsubtable(L, LUA_REGISTRYINDEX, "__cocos2d_ref_chain__");
    olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance(), "cc.Director");
    lua_pushboolean(L, true);
    lua_rawset(L, -3);
    lua_pop(L, 1);
    
    return 0;
}
