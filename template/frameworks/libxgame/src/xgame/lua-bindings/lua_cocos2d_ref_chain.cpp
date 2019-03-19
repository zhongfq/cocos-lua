#include "xgame/lua-bindings/lua_cocos2d_ref_chain.h"

#define CLS_FUNC    ".func"
#define CLS_GET     ".get"
#define CLS_SET     ".set"

#define NODE_PROTECTED_CHILDREN     "protectedChildren"
#define NODE_CHILDREN               "children"
#define NODE_ACTIONS                "actions"
#define NODE_COMPONENTS             "components"
#define DIRECTOR_SCENES             "scenes"

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
        CCASSERT(false && fn, "function not found'");
        lua_pop(L, 2);
    }
}

static void wrap_func(lua_State *L, const char *refname, const char *name, lua_CFunction func)
{
    set_func(L, CLS_FUNC, name, func, refname);
}

static void wrap_getf(lua_State *L, const char *refname, const char *prop, const char *fn, lua_CFunction func)
{
    set_func(L, CLS_FUNC, fn, func, refname);
    set_func(L, CLS_GET, prop, func, refname);
}

//static void wrap_set(lua_State *L, const char *fn, const char *prop, lua_CFunction func)
//{
//    set_func(L, CLS_FUNC, fn, func, refname);
//    set_func(L, CLS_SET, prop, func, refname);
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
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    call_real_function(L, KEEP_SELF);
    olua_mapref(L, 1, refname, 2);
    lua_remove(L, 1);
    return lua_gettop(L);
}

static int mapref_argument_value(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    olua_mapref(L, 1, refname, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

static int mapunref_argument_value(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    olua_mapunref(L, 1, refname, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

static int mapunrefall(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    olua_unrefall(L, 1, refname);
    call_real_function(L, false);
    return lua_gettop(L);
}

//
// Director
//
static int wrap_cocos2d_Director_getRunningScene(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    call_real_function(L, KEEP_SELF);
    olua_arrayref(L, 1, refname, 2);
    lua_remove(L, 1);
    return lua_gettop(L);
}

// void runWithScene(Scene *scene)
// void pushScene(Scene *scene)
static int wrap_cocos2d_Director_pushScene(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    olua_arrayref(L, 1, refname, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

// void popScene()
static int wrap_cocos2d_Director_popScene(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    olua_arrayunref(L, 1, refname, -1);
    call_real_function(L, false);
    return lua_gettop(L);
}

// void popToRootScene()
static int wrap_cocos2d_Director_popToRootScene(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    int len = (int)olua_arraylen(L, 1, refname);
    while (len > 1) {
        olua_arrayunref(L, 1, refname, len--);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

// void popToSceneStackLevel(int level)
static int wrap_cocos2d_Director_popToSceneStackLevel(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    int level = (int)olua_checkinteger(L, 2);
    int len = (int)olua_arraylen(L, 1, refname);
    while (len > level) {
        olua_arrayunref(L, 1, refname, len--);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

// void replaceScene(Scene *scene)
static int wrap_cocos2d_Director_replaceScene(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    olua_arrayunref(L, 1, refname, -1);
    olua_arrayref(L, 1, refname, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

static int wrap_cocos2d_Director(lua_State *L)
{
    luaL_getmetatable(L, "cc.Director");
    CCASSERT(olua_istable(L, -1), "not found 'cc.Director'");
    wrap_getf(L, DIRECTOR_SCENES, "runningScene", "getRunningScene", wrap_cocos2d_Director_getRunningScene);
    wrap_func(L, DIRECTOR_SCENES, "runWithScene", wrap_cocos2d_Director_pushScene);
    wrap_func(L, DIRECTOR_SCENES, "pushScene", wrap_cocos2d_Director_pushScene);
    wrap_func(L, DIRECTOR_SCENES, "popScene", wrap_cocos2d_Director_popScene);
    wrap_func(L, DIRECTOR_SCENES, "popToRootScene", wrap_cocos2d_Director_popToRootScene);
    wrap_func(L, DIRECTOR_SCENES, "popToSceneStackLevel", wrap_cocos2d_Director_popToSceneStackLevel);
    wrap_func(L, DIRECTOR_SCENES, "replaceScene", wrap_cocos2d_Director_replaceScene);
    return 0;
}

//
// Node
//
// void removeFromParent()
// void removeFromParentAndCleanup(bool cleanup)
static int wrap_cocos2d_Node_removeFromParent(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Node *parent = self->getParent();
    if (olua_getobj(L, parent)) {
        olua_mapunref(L, -1, refname, 1);
        lua_pop(L, 1);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

// void removeChildByTag(int tag, bool cleanup = true)
static int wrap_cocos2d_Node_removeChildByTag(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Node *child = self->getChildByTag((int)olua_checkinteger(L, 2));
    if (olua_getobj(L, child)) {
        olua_mapunref(L, 1, refname, -1);
        lua_pop(L, 1);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

// void removeChildByName(const std::string &name, bool cleanup = true)
static int wrap_cocos2d_Node_removeChildByName(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Node *child = self->getChildByName(olua_checkstring(L, 2));
    if (olua_getobj(L, child)) {
        olua_mapunref(L, 1, refname, -1);
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
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    olua_mapwalkunref(L, 1, refname, should_unref_action);
}

// Action* runAction(Action* action)
static int wrap_cocos2d_Node_runAction(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    check_node_actions(L);
    olua_mapref(L, 1, refname, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

// void stopAllActions()
static int wrap_cocos2d_Node_stopAllActions(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    olua_unrefall(L, 1, refname);
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
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    call_real_function(L, KEEP_SELF);
    olua_mapref(L, 1, refname, 2);
    lua_remove(L, 1);
    return lua_gettop(L);
}

// bool removeComponent(const std::string& name)
// bool removeComponent(Component *component)
static int wrap_cocos2d_Node_removeComponent(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    if (olua_isstring(L, 2)) {
        std::string name = lua_tostring(L, 2);
        cocos2d::Node *self = (cocos2d::Node *)olua_checkobj(L, 1, "cc.Node");
        cocos2d::Component *obj = self->getComponent(name);
        if (olua_getobj(L, obj)) {
            olua_mapunref(L, 1, refname, -1);
            lua_pop(L, 1);
        }
    } else {
         olua_mapunref(L, 1, refname, 2);
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
    wrap_func(L, NODE_CHILDREN, "addChild", mapref_argument_value);
    // Node *getChildByTag(int tag) const
    // Node *getChildByName(const std::string& name)
    wrap_func(L, NODE_CHILDREN, "getChildByName", mapref_return_value);
    wrap_func(L, NODE_CHILDREN, "getChildByTag", mapref_return_value);
    wrap_func(L, NODE_CHILDREN, "removeFromParent", wrap_cocos2d_Node_removeFromParent);
    wrap_func(L, NODE_CHILDREN, "removeFromParentAndCleanup", wrap_cocos2d_Node_removeFromParent);
    // void removeChild(Node* child, bool cleanup = true)
    wrap_func(L, NODE_CHILDREN, "removeChild", mapunref_argument_value);
    wrap_func(L, NODE_CHILDREN, "removeChildByTag", wrap_cocos2d_Node_removeChildByTag);
    wrap_func(L, NODE_CHILDREN, "removeChildByName", wrap_cocos2d_Node_removeChildByName);
    // void removeAllChildren()
    // void removeAllChildrenWithCleanup(bool cleanup)
    wrap_func(L, NODE_CHILDREN, "removeAllChildren", mapunrefall);
    wrap_func(L, NODE_CHILDREN, "removeAllChildrenWithCleanup", mapunrefall);
    
    wrap_func(L, NODE_ACTIONS, "runAction", wrap_cocos2d_Node_runAction);
    wrap_func(L, NODE_ACTIONS, "stopAllActions", wrap_cocos2d_Node_stopAllActions);
    wrap_func(L, NODE_ACTIONS, "stopAction", wrap_cocos2d_Node_stopAction);
    wrap_func(L, NODE_ACTIONS, "stopActionByTag", wrap_cocos2d_Node_stopAction);
    wrap_func(L, NODE_ACTIONS, "stopAllActionsByTag", wrap_cocos2d_Node_stopAction);
    wrap_func(L, NODE_ACTIONS, "stopActionsByFlags", wrap_cocos2d_Node_stopAction);
    wrap_func(L, NODE_ACTIONS, "getActionByTag", wrap_cocos2d_Node_getActionByTag);
    
    // Component* getComponent(const std::string& name)
    wrap_func(L, NODE_COMPONENTS, "getComponent", mapref_return_value);
    // bool addComponent(Component *component)
    wrap_func(L, NODE_COMPONENTS, "addComponent", mapref_argument_value);
    wrap_func(L, NODE_COMPONENTS, "removeComponent", wrap_cocos2d_Node_removeComponent);
    // void removeAllComponents()
    wrap_func(L, NODE_COMPONENTS, "removeAllComponents", mapunrefall);
    return 0;
}

static int wrap_cocos2d_ProtectedNode_removeProtectedChildByTag(lua_State *L)
{
    const char *refname = olua_checkstring(L, lua_upvalueindex(2));
    cocos2d::ProtectedNode *self = (cocos2d::ProtectedNode *)olua_toobj(L, 1, "cc.ProtectedNode");
    cocos2d::Node *child = self->getProtectedChildByTag((int)olua_checkinteger(L, 2));
    if (olua_getobj(L, child)) {
        olua_mapunref(L, 1, refname, -1);
        lua_pop(L, 1);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

static int wrap_cocos2d_ProtectedNode(lua_State *L)
{
    luaL_getmetatable(L, "cc.ProtectedNode");
    CCASSERT(olua_istable(L, -1), "not found 'cc.ProtectedNode'");
    // void addProtectedChild(Node * child)
    // void addProtectedChild(Node * child, int localZOrder)
    // void addProtectedChild(Node* child, int localZOrder, int tag)
    wrap_func(L, NODE_PROTECTED_CHILDREN, "addProtectedChild", mapref_argument_value);
    // Node *getProtectedChildByTag(int tag) const
    wrap_func(L, NODE_PROTECTED_CHILDREN, "getProtectedChildByTag", mapref_return_value);
    // void removeProtectedChild(Node* child, bool cleanup = true)
    wrap_func(L, NODE_PROTECTED_CHILDREN, "removeProtectedChild", mapunref_argument_value);
    wrap_func(L, NODE_PROTECTED_CHILDREN, "removeProtectedChildByTag", wrap_cocos2d_ProtectedNode_removeProtectedChildByTag);
    // void removeAllProtectedChildren()
    // void removeAllProtectedChildrenWithCleanup(bool cleanup)
    wrap_func(L, NODE_PROTECTED_CHILDREN, "removeAllProtectedChildren", mapunrefall);
    wrap_func(L, NODE_PROTECTED_CHILDREN, "removeAllProtectedChildrenWithCleanup", mapunrefall);
    return 0;
}

LUALIB_API int luaopen_cocos2d_ref_chain(lua_State *L)
{
    xlua_call(L, wrap_cocos2d_Director);
    xlua_call(L, wrap_cocos2d_Node);
    xlua_call(L, wrap_cocos2d_ProtectedNode);
    
    olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance(), "cc.Director");
    lua_setfield(L, LUA_REGISTRYINDEX, "__cocos2d_ref_chain__");
    
    return 0;
}
