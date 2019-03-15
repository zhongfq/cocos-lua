#include "xgame/lua-bindings/lua_cocos2d_ref_chain.h"

#define CLS_FUNC    ".func"
#define CLS_GET     ".get"
#define CLS_SET     ".set"

#define NODE_CHILDREN   "children"
#define NODE_ACTIONS    "actions"
#define NODE_COMPONENTS "components"
#define DIRECTOR_SCENES "scenes"

#define KEEP_SELF   true

static void set_func(lua_State *L, const char *t, const char *fn, lua_CFunction func, const char *refname)
{
    CCASSERT(fn, "");
    CCASSERT(refname, "");
    olua_rawgetfield(L, -1, t);                         // L: t
    if (olua_rawgetfield(L, -1, fn) == LUA_TFUNCTION) { // L: t old_func
        lua_pushstring(L, refname);                     // L: t old_func name
        lua_pushcclosure(L, func, 2);                   // L: t new_func
        olua_rawsetfield(L, -2, fn);                    // L: t
        lua_pop(L, 1);                                  // L:
    } else {
        CCASSERT(false, "function not found'");
        lua_pop(L, 2);
    }
}

static void wrap_func(lua_State *L, const char *name, const char *refname, lua_CFunction func)
{
    set_func(L, CLS_FUNC, name, func, refname);
}

static void wrap_get(lua_State *L, const char *fn, const char *prop, lua_CFunction func)
{
    set_func(L, CLS_FUNC, fn, func, prop);
    set_func(L, CLS_GET, prop, func, prop);
}

//static void wrap_set(lua_State *L, const char *fn, const char *prop, lua_CFunction func)
//{
//    set_func(L, CLS_FUNC, fn, func, prop);
//    set_func(L, CLS_SET, prop, func, prop);
//}

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

static int mapref_return_value(lua_State *L)
{
    const char *name = olua_checkstring(L, lua_upvalueindex(2));
    call_real_function(L, KEEP_SELF);
    olua_mapref(L, 1, name, 2);
    lua_remove(L, 1);
    return lua_gettop(L);
}

static int mapref_argument_value(lua_State *L)
{
    const char *name = olua_checkstring(L, lua_upvalueindex(2));
    olua_mapref(L, 1, name, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

static int mapunref_argument_value(lua_State *L)
{
    const char *name = olua_checkstring(L, lua_upvalueindex(2));
    olua_mapunref(L, 1, name, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

static int mapunrefall(lua_State *L)
{
    const char *name = olua_checkstring(L, lua_upvalueindex(2));
    olua_unrefall(L, 1, name);
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
    wrap_func(L, "runWithScene", DIRECTOR_SCENES, wrap_cocos2d_Director_pushScene);
    wrap_func(L, "pushScene", DIRECTOR_SCENES, wrap_cocos2d_Director_pushScene);
    wrap_func(L, "popScene", DIRECTOR_SCENES, wrap_cocos2d_Director_popScene);
    wrap_func(L, "popToRootScene", DIRECTOR_SCENES, wrap_cocos2d_Director_popToRootScene);
    wrap_func(L, "popToSceneStackLevel", DIRECTOR_SCENES, wrap_cocos2d_Director_popToSceneStackLevel);
    wrap_func(L, "replaceScene", DIRECTOR_SCENES, wrap_cocos2d_Director_replaceScene);
    return 0;
}

//
// Node
//
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
    olua_unrefall(L, 1, NODE_ACTIONS);
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

// bool removeComponent(const std::string& name)
// bool removeComponent(Component *component)
static int wrap_cocos2d_Node_removeComponent(lua_State *L)
{
    if (olua_isstring(L, 2)) {
        std::string name = lua_tostring(L, 2);
        cocos2d::Node *self = (cocos2d::Node *)olua_checkobj(L, 1, "cc.Node");
        cocos2d::Component *obj = self->getComponent(name);
        if (olua_getobj(L, obj)) {
            olua_mapunref(L, 1, NODE_COMPONENTS, -1);
            lua_pop(L, 1);
        }
    } else {
         olua_mapunref(L, 1, NODE_COMPONENTS, 2);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

static int wrap_cocos2d_Node(lua_State *L)
{
    luaL_getmetatable(L, "cc.Node");
    CCASSERT(olua_istable(L, -1), "not found 'cc.Node'");
    // void addChild(Node * child)
    // void addChild(Node * child, int localZOrder)
    // void addChild(Node* child, int localZOrder, int tag)
    // void addChild(Node* child, int localZOrder, const std::string &name)
    wrap_func(L, "addChild", NODE_CHILDREN, mapref_argument_value);
    // Node *getChildByTag(int tag) const
    // Node *getChildByName(const std::string& name)
    wrap_func(L, "getChildByName", NODE_CHILDREN, mapref_return_value);
    wrap_func(L, "getChildByTag", NODE_CHILDREN, mapref_return_value);
    wrap_func(L, "removeFromParent", NODE_CHILDREN, wrap_cocos2d_Node_removeFromParent);
    wrap_func(L, "removeFromParentAndCleanup", NODE_CHILDREN, wrap_cocos2d_Node_removeFromParent);
    // void removeChild(Node* child, bool cleanup = true)
    wrap_func(L, "removeChild", NODE_CHILDREN, mapunref_argument_value);
    wrap_func(L, "removeChildByTag", NODE_CHILDREN, wrap_cocos2d_Node_removeChildByTag);
    wrap_func(L, "removeChildByName", NODE_CHILDREN, wrap_cocos2d_Node_removeChildByName);
    // void removeAllChildren()
    // void removeAllChildrenWithCleanup(bool cleanup)
    wrap_func(L, "removeAllChildren", NODE_CHILDREN, mapunrefall);
    wrap_func(L, "removeAllChildrenWithCleanup", NODE_CHILDREN, mapunrefall);
    wrap_func(L, "runAction", NODE_ACTIONS, wrap_cocos2d_Node_runAction);
    wrap_func(L, "stopAllActions", NODE_ACTIONS, wrap_cocos2d_Node_stopAllActions);
    wrap_func(L, "stopAction", NODE_ACTIONS, wrap_cocos2d_Node_stopAction);
    wrap_func(L, "stopActionByTag", NODE_ACTIONS, wrap_cocos2d_Node_stopAction);
    wrap_func(L, "stopAllActionsByTag", NODE_ACTIONS, wrap_cocos2d_Node_stopAction);
    wrap_func(L, "stopActionsByFlags", NODE_ACTIONS, wrap_cocos2d_Node_stopAction);
    wrap_func(L, "getActionByTag", NODE_ACTIONS, wrap_cocos2d_Node_getActionByTag);
    // Component* getComponent(const std::string& name)
    wrap_func(L, "getComponent", NODE_COMPONENTS, mapref_return_value);
    // bool addComponent(Component *component)
    wrap_func(L, "addComponent", NODE_COMPONENTS, mapref_argument_value);
    wrap_func(L, "removeComponent", NODE_COMPONENTS, wrap_cocos2d_Node_removeComponent);
    // void removeAllComponents()
    wrap_func(L, "removeAllComponents", NODE_COMPONENTS, mapunrefall);
    return 0;
}

LUALIB_API int luaopen_cocos2d_ref_chain(lua_State *L)
{
    xlua_call(L, wrap_cocos2d_Director);
    xlua_call(L, wrap_cocos2d_Node);
    
    olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance(), "cc.Director");
    lua_setfield(L, LUA_REGISTRYINDEX, "__cocos2d_ref_chain__");
    
    return 0;
}
