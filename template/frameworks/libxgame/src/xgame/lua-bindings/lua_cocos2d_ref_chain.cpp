#include "xgame/lua-bindings/lua_cocos2d_ref_chain.h"

#define CLS_FUNC    ".func"
#define CLS_GET     ".get"
#define CLS_SET     ".set"

#define NODE_CHILDREN       ".children"
#define DIRECTOR_SCENES     ".scene"

static void set_func(lua_State *L, const char *name, lua_CFunction func, bool check)
{
    if (olua_rawgetfield(L, -1, name) == LUA_TFUNCTION) {   // L: t old_func
        lua_pushcclosure(L, func, 1);                       // L: t new_func
        olua_rawsetfield(L, -2, name);                      // L: t
    } else {
        CCASSERT(!check, "function not found'");
        lua_pop(L, 1);
    }
}

static void wrap_function(lua_State *L, const char *name, const char *prop, lua_CFunction func)
{
    olua_rawgetfield(L, -1, CLS_FUNC);
    set_func(L, name, func, true);
    lua_pop(L, 1);
    
    if (prop) {
        olua_rawgetfield(L, -1, CLS_GET);
        set_func(L, prop, func, false);
        lua_pop(L, 1);
        
        olua_rawgetfield(L, -1, CLS_SET);
        set_func(L, prop, func, false);
        lua_pop(L, 1);
    }
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

//
// Director
//
static int wrap_cocos2d_Director_getRunningScene(lua_State *L)
{
    call_real_function(L, true);
    olua_arrayref(L, 1, DIRECTOR_SCENES, 2);
    lua_remove(L, 1);
    return lua_gettop(L);
}

static int wrap_cocos2d_Director(lua_State *L)
{
    luaL_getmetatable(L, "cc.Director");
    CCASSERT(olua_istable(L, -1), "not found 'cc.Director'");
    wrap_function(L, "getRunningScene", "runningScene", wrap_cocos2d_Director_getRunningScene);
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
    call_real_function(L, true);
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
    }    call_real_function(L, false);
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

static int wrap_cocos2d_Node(lua_State *L)
{
    luaL_getmetatable(L, "cc.Node");
    CCASSERT(olua_istable(L, -1), "not found 'cc.Node'");
    wrap_function(L, "addChild", nullptr, wrap_cocos2d_Node_addChild);
    wrap_function(L, "getChildByName", nullptr, wrap_cocos2d_Node_getChild);
    wrap_function(L, "getChildByTag", nullptr, wrap_cocos2d_Node_getChild);
    wrap_function(L, "removeFromParent", nullptr, wrap_cocos2d_Node_removeFromParent);
    wrap_function(L, "removeFromParentAndCleanup", nullptr, wrap_cocos2d_Node_removeFromParent);
    wrap_function(L, "removeChild", nullptr, wrap_cocos2d_Node_removeChild);
    wrap_function(L, "removeChildByTag", nullptr, wrap_cocos2d_Node_removeChildByTag);
    wrap_function(L, "removeChildByName", nullptr, wrap_cocos2d_Node_removeChildByName);
    wrap_function(L, "removeAllChildren", nullptr, wrap_cocos2d_Node_removeAllChildren);
    wrap_function(L, "removeAllChildrenWithCleanup", nullptr, wrap_cocos2d_Node_removeAllChildren);
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
