#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "xgame/xfilesystem.h"

#define OBJ_REF_TABLE ((void *)xluacls_internalpush)

#define XLUACLS_ISAIDX  1
#define XLUACLS_FUNCIDX 2
#define XLUACLS_GETIDX  3
#define XLUACLS_SETIDX  4
#define XLUACLS_ISA     ".isa"
#define XLUACLS_FUNC    ".func"
#define XLUACLS_GET     ".get"
#define XLUACLS_SET     ".set"

const char *xlua_typename(lua_State *L, int idx)
{
    const char *tn = nullptr;
    if (lua_getmetatable(L, idx)) {
        if (xlua_rawgetfield(L, -1, "classname") == LUA_TSTRING) {
            tn = lua_tostring(L, 1);
        }
        lua_pop(L, 2); // pop mt and value
    }
    
    if (tn == nullptr) {
        tn = lua_typename(L, lua_type(L, idx));
    }
    
    return tn;
}

void xluacls_pushfunc(lua_State *L, lua_CFunction func)
{
    if (func) {
        lua_pushcfunction(L, func);
    } else {
        lua_pushnil(L);
    }
}

static int xluacls_mt_index(lua_State *L)
{
    // try func
    lua_settop(L, 2);                                   // L: t k
    lua_pushvalue(L, lua_upvalueindex(XLUACLS_FUNCIDX));// L: t k .func
    lua_pushvalue(L, 2);                                // L: t k .func k
    if (lua_rawget(L, -2) != LUA_TNIL) {                // L: t k .func v
        return 1;
    }
    
    // try getter
    lua_settop(L, 2);                                   // L: t k
    lua_pushvalue(L, lua_upvalueindex(XLUACLS_GETIDX)); // L: t k .get
    lua_pushvalue(L, 2);                                // L: t k .get k
    if (lua_rawget(L, -2) != LUA_TNIL) {                // L: t k .get getter
        lua_pushvalue(L, 1);                            // L: t k .get getter t
        lua_pushvalue(L, 2);                            // L: t k .get getter t k
        lua_call(L, 2, 1);                              // L: t k .get ret
        return 1;
    }
    
    // not found
    lua_settop(L, 2);                                   // L: t k
    lua_pushnil(L);                                     // L: t k nil
    
    return 1;
}

static int xluacls_mt_newindex(lua_State *L)
{
    // try setter
    lua_settop(L, 3);                                   // L: t k v
    lua_pushvalue(L, lua_upvalueindex(XLUACLS_SETIDX)); // L: t k v .set
    lua_pushvalue(L, -2);                               // L: t k v .set k
    if (lua_rawget(L, -2) != LUA_TNIL) {                // L: t k v .set setter
        lua_pushvalue(L, 1);                            // L: t k v .set setter t
        lua_pushvalue(L, 2);                            // L: t k v .set setter t k
        lua_pushvalue(L, 3);                            // L: t k v .set setter t k v
        lua_call(L, 3, 0);                              // L: t k v .set
    }
    
    luaL_error(L, "readonly property: %s", lua_tostring(L, 2));
    
    return 1;
}

static int xluacls_mt_tostring(lua_State *L)
{
    intptr_t p = 0;
    if (lua_isuserdata(L, 1)) {
        p = (intptr_t)(*(void **)lua_touserdata(L, 1));
    } else {
        p = (intptr_t)lua_topointer(L, 1);
    }
    
    lua_pushfstring(L, "%s: %p", xlua_typename(L, 1), p);

    return 1;
}

static void xluacls_clonesupertable(lua_State *L, int idx, const char *field, const char *super)
{
    idx = lua_absindex(L, idx);
    
    lua_newtable(L);                            // L: t
    if (super) {
        luaL_getmetatable(L, super);            // L: t super
        xlua_rawgetfield(L, -1, field);         // L: t super fv
        lua_pushnil(L);                         // L: t super fv k
        while (lua_next(L, -2)) {               // L: t super fv k v
            lua_pushvalue(L, -2);               // L: t super fv k v k
            lua_insert(L, -2);                  // L: t super fv k k v
            lua_rawset(L, -6);                  // L: t super fv k
        }                                       // L: t super fv
        lua_pop(L, 2);                          // L: t
    }
    
    lua_pushvalue(L, -1);                        // L: t t
    xlua_rawsetfield(L, idx, field);             // L: t     idx[field] = t
}

void xluacls_class(lua_State *L, const char *classname, const char *super)
{
    if (super != nullptr) {
        if (luaL_getmetatable(L, super) == LUA_TNIL) {
            luaL_error(L, "super class not found: %s", super);
        }
        lua_pop(L, 1);
    }
    
    if (luaL_getmetatable(L, classname) == LUA_TNIL) {
        lua_pop(L, 1);
        luaL_newmetatable(L, classname);                    // L: mt
        int cls = lua_gettop(L);
        
        xluacls_clonesupertable(L, cls, XLUACLS_ISA, super); // L: mt .isa
        xluacls_clonesupertable(L, cls, XLUACLS_FUNC, super);// L: mt .isa .func
        xluacls_clonesupertable(L, cls, XLUACLS_GET, super); // L: mt .isa .func .get
        xluacls_clonesupertable(L, cls, XLUACLS_SET, super); // L: mt .isa .func .get .set

        static const luaL_Reg lib[] = {
            {"__index", xluacls_mt_index},
            {"__newindex", xluacls_mt_newindex},
            {"__tostring", xluacls_mt_tostring},
            {NULL, NULL}
        };
        luaL_setfuncs(L, lib,  4);                          // L: mt
        
        lua_pushvalue(L, -1);
        xluacls_const(L, "class");
        
        lua_pushstring(L, classname);
        xluacls_const(L, "classname");
        
        if (super) {
            luaL_getmetatable(L, super);
            xluacls_const(L, "super");
        }
        
        xlua_rawgetfield(L, cls, XLUACLS_ISA);
        lua_pushstring(L, classname);
        lua_pushboolean(L, true);
        lua_rawset(L, -3);
        lua_pop(L, 1);
    }
}

void xluacls_property(lua_State *L, const char *field, lua_CFunction getter, lua_CFunction setter)
{
    xlua_rawgetfield(L, -1, XLUACLS_GET);   // L: mt .get
    xluacls_pushfunc(L, getter);            // L: mt .get getter
    xlua_rawsetfield(L, -2, field);         // L: mt .get            .get[field] = getter
    lua_pop(L, 1);                          // L: mt
    
    xlua_rawgetfield(L, -1, XLUACLS_SET);   // L: mt .set
    xluacls_pushfunc(L, setter);            // L: mt .set setter
    xlua_rawsetfield(L, -2, field);         // L: mt .set            .set[field] = setter
    lua_pop(L, 1);                          // L: mt
}

void xluacls_setfunc(lua_State *L, const char *funcname, lua_CFunction func)
{
    xlua_rawgetfield(L, -1, XLUACLS_FUNC);  // L: mt .func
    xluacls_pushfunc(L, func);              // L: mt .func func
    xlua_rawsetfield(L, -2, funcname);      // L: mt .func            .func[funcname] = func
    lua_pop(L, 1);                          // L: mt
}

static int xluacls_constindex(lua_State *L)
{
    lua_pushvalue(L, lua_upvalueindex(1));
    return 1;
}

void xluacls_const(lua_State *L, const char *field)
{
    lua_pushvalue(L, -1);                       // L: mt v v
    xlua_rawsetfield(L, -3, field);             // L: mt v
    
    lua_pushcclosure(L, xluacls_constindex, 1); // L: mt getter
    xlua_rawgetfield(L, -2, XLUACLS_GET);       // L: mt getter .get
    lua_insert(L, -2);                          // L: mt .get getter
    xlua_rawsetfield(L, -2, field);             // L: mt .get
    lua_pop(L, 1);                              // L: mt
}

bool xluacls_isa(lua_State *L, int idx, const char *classname)
{
    int top = lua_gettop(L);
    bool is_a = false;
    if (lua_getmetatable(L, idx)) {
        if (xlua_rawgetfield(L, -1, XLUACLS_ISA) == LUA_TTABLE) {
            xlua_rawgetfield(L, -1, classname);
            is_a = lua_toboolean(L, -1);
        }
    }
    lua_settop(L, top);
    return is_a;
}

static bool xluacls_internalpush(lua_State *L, void *obj, const char *classname)
{
    bool is_new = false;
    
    if (lua_rawgetp(L, LUA_REGISTRYINDEX, OBJ_REF_TABLE) == LUA_TNIL) {
        lua_pop(L, 1); // pop nil
        lua_newtable(L);
        
        lua_pushvalue(L, -1);
        lua_pushstring(L, "v");
        lua_setfield(L, -2, "__mode");  // mt.__mode = 'kv'
        lua_setmetatable(L, -2);        // mt.metatable = mt
        
        lua_pushvalue(L, -1);
        lua_rawsetp(L, LUA_REGISTRYINDEX, OBJ_REF_TABLE);
    }
    
    if (lua_rawgetp(L, -1, obj) == LUA_TNIL) {              // L: mapping obj?
        lua_pop(L, 1);                                      // L: mapping
        *(void **)lua_newuserdata(L, sizeof(void *)) = obj; // L: mapping obj
        luaL_setmetatable(L, classname);                    // L: mapping obj
        lua_pushvalue(L, -1);                               // L: mapping obj obj
        lua_rawsetp(L, -3, obj);                            // L: mapping obj
        is_new = true;
    }
    
#ifdef COCOS2D_DEBUG
    luaL_checkudata(L, -1, classname);
#endif
    
    lua_remove(L, -2);                                      // L: obj
    
    return is_new;
}

void xluacls_pushobj(lua_State *L, void *obj, const char *classname)
{
    xluacls_internalpush(L, obj, classname);
}

void xluacls_pushccobj(lua_State *L, cocos2d::Ref *obj, const char *classname)
{
    if (xluacls_internalpush(L, obj, classname)) {
        obj->retain();
    }
}

int xluacls_ccobjgc(lua_State *L)
{
    cocos2d::Ref *obj = *(cocos2d::Ref **)lua_touserdata(L, 1);
    if (obj) {
        obj->release();
        *(void **)lua_touserdata(L, 1) = nullptr;
    }
    return 0;
}

void *xluacls_checkobj(lua_State *L, int idx, const char *classname)
{
    if (xluacls_isa(L, idx, classname)) {
        return *(void **)lua_touserdata(L, idx);
    } else {
        luaL_error(L, "#%d argument error, expect: '%s', got '%s'", idx,
            classname, xlua_typename(L, idx));
    }
    return nullptr;
}
