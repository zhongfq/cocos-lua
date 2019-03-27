#include "xgame/lua-bindings/lua_cocos2d_ref_chain.h"

#define CLS_FUNC    ".func"
#define CLS_GET     ".get"
#define CLS_SET     ".set"

#define NODE_PROTECTED_CHILDREN     "protectedChildren"
#define NODE_CHILDREN               "children"
#define NODE_ACTIONS                "actions"
#define NODE_COMPONENTS             "components"
#define DIRECTOR_SCENES             "scenes"
#define EVENTDISPATCHER_LISTENER    "listeners"

#define KEEP_SELF   true
#define REFNAME     (olua_checkstring(L, lua_upvalueindex(2)))

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
    call_real_function(L, KEEP_SELF);
    olua_mapref(L, 1, REFNAME, 2);
    lua_remove(L, 1);
    return lua_gettop(L);
}

static int mapref_argument_value(lua_State *L)
{
    olua_mapref(L, 1, REFNAME, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

static int mapunref_argument_value(lua_State *L)
{
    olua_mapunref(L, 1, REFNAME, 2);
    call_real_function(L, false);
    return lua_gettop(L);
}

static int mapunrefall(lua_State *L)
{
    olua_unrefall(L, 1, REFNAME);
    call_real_function(L, false);
    return lua_gettop(L);
}

static void record_reference_count(lua_State *L, int idx)
{
    olua_getreftable(L, idx, REFNAME);                      // L: t
    lua_pushnil(L);                                         // L: t k
    while (lua_next(L, -2)) {                               // L: t k v
        if (olua_isa(L, -2, "cc.Ref")) {
            cocos2d::Ref *obj = (cocos2d::Ref *)olua_toobj(L, -2, "cc.Ref");
            lua_pushvalue(L, -2);                           // L: t k v k
            lua_pushinteger(L, obj->getReferenceCount());   // L: t k v k refcount
            lua_rawset(L, -5);                              // L: t k v
        }
        lua_pop(L, 1);                                      // L: t k
    }                                                       // L: t
    lua_pop(L, 1);                                          // L:
}

static int should_unref_obj(lua_State *L)
{
    if (olua_isa(L, -2, "cc.Action")) {
        cocos2d::Action *obj = olua_touserdata(L, -2, cocos2d::Action *);
        if (obj) {
            unsigned int curr = obj->getReferenceCount();
            if (!obj->getTarget() || obj->isDone() || curr == 1) {
                return 1;
            } else if (olua_isinteger(L, -1)) {
                unsigned int last = (unsigned int)olua_tointeger(L, -1);
                if (curr < last) {
                    return 1;
                }
            }
        }
    } else if (olua_isa(L, -2, "cc.Ref")) {
        cocos2d::Ref *obj = (cocos2d::Ref *)olua_toobj(L, -2, "cc.Ref");
        if (obj && olua_isinteger(L, -1)) {
            unsigned int last = (unsigned int)olua_tointeger(L, -1);
            unsigned int curr = obj->getReferenceCount();
            if (curr < last || curr == 1) {
                return 1;
            }
        }
    }
    return 0;
}

static void check_reference_count(lua_State *L, int idx)
{
    olua_mapwalkunref(L, idx, REFNAME, should_unref_obj);
}

static int mapunef_by_compare(lua_State *L)
{
    record_reference_count(L, 1);
    call_real_function(L, KEEP_SELF);
    check_reference_count(L, 1);
    lua_remove(L, 1);
    return lua_gettop(L);
}

static int mapref_argument_value_and_mapunef_by_compare(lua_State *L)
{
    olua_mapref(L, 1, REFNAME, 2);
    record_reference_count(L, 1);
    call_real_function(L, KEEP_SELF);
    check_reference_count(L, 1);
    lua_remove(L, 1);
    return lua_gettop(L);
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
        olua_mapunref(L, -1, REFNAME, 1);
        lua_pop(L, 1);
    }
    call_real_function(L, false);
    return lua_gettop(L);
}

static int wrap_cocos2d_Node_removeChild(lua_State *L)
{
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Node *child = nullptr;
    if (olua_isinteger(L, 2)) {
        child = self->getChildByTag((int)olua_tointeger(L, 2));
    } else if (olua_isstring(L, 2)) {
        child = self->getChildByName(olua_tostring(L, 2));
    }
    if (child && olua_getobj(L, child)) {
        olua_mapunref(L, 1, REFNAME, -1);
        lua_pop(L, 1);
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
    // void removeChildByTag(int tag, bool cleanup = true)
    // void removeChildByName(const std::string &name, bool cleanup = true)
    wrap_func(L, NODE_CHILDREN, "removeChildByTag", wrap_cocos2d_Node_removeChild);
    wrap_func(L, NODE_CHILDREN, "removeChildByName", wrap_cocos2d_Node_removeChild);
    // void removeAllChildren()
    // void removeAllChildrenWithCleanup(bool cleanup)
    wrap_func(L, NODE_CHILDREN, "removeAllChildren", mapunrefall);
    wrap_func(L, NODE_CHILDREN, "removeAllChildrenWithCleanup", mapunrefall);
    
    // Action* runAction(Action* action)
    // void stopAllActions()
    // void stopAction(Action* action)
    // void stopActionByTag(int tag)
    // void stopAllActionsByTag(int tag)
    // void stopActionsByFlags(unsigned int flags)
    // Action* getActionByTag(int tag)
    wrap_func(L, NODE_ACTIONS, "runAction", mapref_argument_value_and_mapunef_by_compare);
    wrap_func(L, NODE_ACTIONS, "stopAllActions", mapunef_by_compare);
    wrap_func(L, NODE_ACTIONS, "stopAction", mapunef_by_compare);
    wrap_func(L, NODE_ACTIONS, "stopActionByTag", mapunef_by_compare);
    wrap_func(L, NODE_ACTIONS, "stopAllActionsByTag", mapunef_by_compare);
    wrap_func(L, NODE_ACTIONS, "stopActionsByFlags", mapunef_by_compare);
    wrap_func(L, NODE_ACTIONS, "getActionByTag", mapref_return_value);
    
    // Component* getComponent(const std::string& name)
    // bool addComponent(Component *component)
    // bool removeComponent(const std::string& name)
    // bool removeComponent(Component *component)
    // void removeAllComponents()
    wrap_func(L, NODE_COMPONENTS, "getComponent", mapref_return_value);
    wrap_func(L, NODE_COMPONENTS, "addComponent", mapref_argument_value);
    wrap_func(L, NODE_COMPONENTS, "removeComponent", mapunef_by_compare);
    wrap_func(L, NODE_COMPONENTS, "removeAllComponents", mapunrefall);
    return 0;
}

static int wrap_cocos2d_ProtectedNode_removeProtectedChildByTag(lua_State *L)
{
    cocos2d::ProtectedNode *self = (cocos2d::ProtectedNode *)olua_toobj(L, 1, "cc.ProtectedNode");
    cocos2d::Node *child = self->getProtectedChildByTag((int)olua_checkinteger(L, 2));
    if (olua_getobj(L, child)) {
        olua_mapunref(L, 1, REFNAME, -1);
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
    xlua_call(L, wrap_cocos2d_Node);
    xlua_call(L, wrap_cocos2d_ProtectedNode);
    
    olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance(), "cc.Director");
    lua_setfield(L, LUA_REGISTRYINDEX, "__cocos2d_ref_chain__");
    
    return 0;
}
