#include "xgame/xlua.h"
#include "xgame/xruntime.h"
#include "xgame/xfilesystem.h"

#define OBJ_REF_TABLE ((void *)xluacls_internalpush)

#define CLS_CLSIDX  (lua_upvalueindex(1))
#define CLS_ISAIDX  (lua_upvalueindex(2))
#define CLS_FUNCIDX (lua_upvalueindex(3))
#define CLS_GETIDX  (lua_upvalueindex(4))
#define CLS_SETIDX  (lua_upvalueindex(5))
#define CLS_ISA     ".isa"
#define CLS_FUNC    ".func"
#define CLS_GET     ".get"
#define CLS_SET     ".set"

static int s_obj_count = 0;

const char *xlua_typename(lua_State *L, int idx)
{
    const char *tn = nullptr;
    if (lua_getmetatable(L, idx)) {
        if (xlua_rawgetfield(L, -1, "classname") == LUA_TSTRING) {
            tn = lua_tostring(L, -1);
        }
        lua_pop(L, 2); // pop mt and value
    }
    
    if (tn == nullptr) {
        tn = lua_typename(L, lua_type(L, idx));
    }
    
    return tn;
}

static void xluacls_pushfunc(lua_State *L, lua_CFunction func)
{
    if (func) {
        lua_pushcfunction(L, func);
    } else {
        lua_pushnil(L);
    }
}

static bool xluacls_ismetafunc(lua_State *L, int idx)
{
    static const char *const tm[] = {
        "__index", "__newindex",
        "__gc", "__mode", "__len", "__eq",
        "__add", "__sub", "__mul", "__mod", "__pow",
        "__div", "__idiv",
        "__band", "__bor", "__bxor", "__shl", "__shr",
        "__unm", "__bnot", "__lt", "__le",
        "__concat", "__call",
        nullptr
    };
    
    if (lua_type(L, idx) == LUA_TSTRING) {
        const char *func = lua_tostring(L, -2);
        for (int i = 0;; ++i) {
            const char *t = tm[i];
            if (t) {
                if (strequal(t, func)) {
                    return true;
                }
            } else {
                break;
            }
        }
    }
    
    return false;
}

static int xluacls_mt_index(lua_State *L)
{
    // try func
    lua_settop(L, 2);                       // L: t k
    lua_pushvalue(L, CLS_FUNCIDX);          // L: t k .func
    lua_pushvalue(L, 2);                    // L: t k .func k
    if (lua_rawget(L, -2) != LUA_TNIL) {    // L: t k .func v
        return 1;
    }
    
    // try getter
    lua_settop(L, 2);                       // L: t k
    lua_pushvalue(L, CLS_GETIDX);           // L: t k .get
    lua_pushvalue(L, 2);                    // L: t k .get k
    if (lua_rawget(L, -2) != LUA_TNIL) {    // L: t k .get getter
        lua_pushvalue(L, 1);                // L: t k .get getter t
        lua_call(L, 1, 1);                  // L: t k .get ret
        return 1;
    }
    
    // not found
    lua_settop(L, 2);                       // L: t k
    lua_pushnil(L);                         // L: t k nil
    
    return 1;
}

static int xluacls_mt_newindex(lua_State *L)
{
    // try setter
    lua_settop(L, 3);                       // L: t k v
    lua_pushvalue(L, CLS_SETIDX);           // L: t k v .set
    lua_pushvalue(L, -2);                   // L: t k v .set k
    if (lua_rawget(L, -2) != LUA_TNIL) {    // L: t k v .set setter
        lua_pushvalue(L, 1);                // L: t k v .set setter t
        lua_pushvalue(L, 3);                // L: t k v .set setter t v
        lua_call(L, 2, 0);                  // L: t k v .set
        return 0;
    }
    
    if (lua_istable(L, 1)) {
        lua_settop(L, 3);                   // L: t k v
        lua_pushvalue(L, CLS_FUNCIDX);      // L: t k v .func
        lua_pushvalue(L, 2);                // L: t k v .func k
        lua_pushvalue(L, 3);                // L: t k v .func k v
        lua_rawset(L, -3);                  // L: t k v .func
        lua_pop(L, 1);                      // L: t k v
        
        if (xluacls_ismetafunc(L, 2)) {
            lua_pushvalue(L, CLS_CLSIDX);   // L: t k v class
            lua_pushvalue(L, 2);            // L: t k v class k
            lua_pushvalue(L, 3);            // L: t k v class k v
            lua_rawset(L, -3);              // L: t k v class
            lua_pop(L, 1);
        }
        
        return 0;
    }
    
    luaL_error(L, "readonly property: %s", lua_tostring(L, 2));
    
    return 0;
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

static void xluacls_copysuperfield(lua_State *L, int idx, const char *field, const char *super)
{
    idx = lua_absindex(L, idx);
    
    lua_newtable(L);                        // L: t
    if (super) {
        luaL_getmetatable(L, super);        // L: t super
        xlua_rawgetfield(L, -1, field);     // L: t super fv
        lua_pushnil(L);                     // L: t super fv k
        while (lua_next(L, -2)) {           // L: t super fv k v
            lua_pushvalue(L, -2);           // L: t super fv k v k
            lua_insert(L, -2);              // L: t super fv k k v
            lua_rawset(L, -6);              // L: t super fv k
        }                                   // L: t super fv
        lua_pop(L, 2);                      // L: t
    }
    
    lua_pushvalue(L, -1);                   // L: t t
    xlua_rawsetfield(L, idx, field);        // L: t     idx[field] = t
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
        lua_pushvalue(L, -1);                               // L: mt mt
        
        xluacls_copysuperfield(L, cls, CLS_ISA, super);     // L: mt mt .isa
        xluacls_copysuperfield(L, cls, CLS_FUNC, super);    // L: mt mt .isa .func
        xluacls_copysuperfield(L, cls, CLS_GET, super);     // L: mt mt .isa .func .get
        xluacls_copysuperfield(L, cls, CLS_SET, super);     // L: mt mt .isa .func .get .set

        static const luaL_Reg lib[] = {
            {"__index", xluacls_mt_index},
            {"__newindex", xluacls_mt_newindex},
            {"__tostring", xluacls_mt_tostring},
            {NULL, NULL}
        };
        luaL_setfuncs(L, lib,  5);                          // L: mt
        
        lua_pushvalue(L, -1);
        xluacls_const(L, "class");
        
        lua_pushstring(L, classname);
        xluacls_const(L, "classname");
        
        if (super) {
            luaL_getmetatable(L, super);
            xluacls_const(L, "super");
        }
        
        xlua_rawgetfield(L, cls, CLS_ISA);
        lua_pushstring(L, classname);
        lua_pushboolean(L, true);
        lua_rawset(L, -3);
        lua_pop(L, 1);
    }
}

void xluacls_newclassproxy(lua_State *L)
{
    lua_newtable(L);                        // L: mt p
    lua_createtable(L, 0, 8);               // L: mt p mtp
    lua_getfield(L, -3, "__index");         // L: mt p mtp __index
    xlua_rawsetfield(L, -2, "__index");     // L: mt p mtp
    lua_getfield(L, -3, "__newindex");      // L: mt p mtp __newindex
    xlua_rawsetfield(L, -2, "__newindex");  // L: mt p mtp
    lua_setmetatable(L, -2);                // L: mt p
}

void xluacls_initmetafunc(lua_State *L)
{
    xlua_rawgetfield(L, -1, CLS_FUNC);          // L: mt .func
    lua_pushnil(L);                             // L: mt .func k
    while (lua_next(L, -2)) {                   // L: mt .func k v
        if (xluacls_ismetafunc(L, -2)) {
            lua_pushvalue(L, -2);               // L: mt .func k v k
            lua_pushvalue(L, -2);               // L: mt .func k v k v
            lua_rawset(L, -6);                  // L: mt .func k v
        }
        lua_pop(L, 1);                          // L: mt .func k
    }                                           // L: mt .func
    lua_pop(L, 1);                              // L: mt
}

void xluacls_property(lua_State *L, const char *field, lua_CFunction getter, lua_CFunction setter)
{
    xlua_rawgetfield(L, -1, CLS_GET);   // L: mt .get
    xluacls_pushfunc(L, getter);        // L: mt .get getter
    xlua_rawsetfield(L, -2, field);     // L: mt .get            .get[field] = getter
    lua_pop(L, 1);                      // L: mt
    
    xlua_rawgetfield(L, -1, CLS_SET);   // L: mt .set
    xluacls_pushfunc(L, setter);        // L: mt .set setter
    xlua_rawsetfield(L, -2, field);     // L: mt .set            .set[field] = setter
    lua_pop(L, 1);                      // L: mt
}

void xluacls_setfunc(lua_State *L, const char *funcname, lua_CFunction func)
{
    xlua_rawgetfield(L, -1, CLS_FUNC);  // L: mt .func
    xluacls_pushfunc(L, func);          // L: mt .func func
    xlua_rawsetfield(L, -2, funcname);  // L: mt .func            .func[funcname] = func
    lua_pop(L, 1);                      // L: mt
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
    xlua_rawgetfield(L, -2, CLS_GET);           // L: mt getter .get
    lua_insert(L, -2);                          // L: mt .get getter
    xlua_rawsetfield(L, -2, field);             // L: mt .get
    lua_pop(L, 1);                              // L: mt
}

void xluacls_const_bool(lua_State *L, const char *field, bool value)
{
    lua_pushboolean(L, value);
    xluacls_const(L, field);
}

void xluacls_const_number(lua_State *L, const char *field, lua_Number value)
{
    lua_pushnumber(L, value);
    xluacls_const(L, field);
}

void xluacls_const_integer(lua_State *L, const char *field, lua_Integer value)
{
    lua_pushinteger(L, value);
    xluacls_const(L, field);
}

void xluacls_const_string(lua_State *L, const char *field, const char *value)
{
    lua_pushstring(L, value);
    xluacls_const(L, field);
}

bool xluacls_isa(lua_State *L, int idx, const char *classname)
{
    int top = lua_gettop(L);
    bool isa = false;
    if (lua_getmetatable(L, idx)) {
        if (xlua_rawgetfield(L, -1, CLS_ISA) == LUA_TTABLE) {
            xlua_rawgetfield(L, -1, classname);
            isa = lua_toboolean(L, -1);
        }
    }
    lua_settop(L, top);
    return isa;
}

static bool xluacls_internalpush(lua_State *L, void *obj, const char *classname)
{
    bool is_new = false;
    
    if (lua_rawgetp(L, LUA_REGISTRYINDEX, OBJ_REF_TABLE) == LUA_TNIL) {
        lua_pop(L, 1); // pop nil
        lua_newtable(L);
        
        lua_pushvalue(L, -1);
        lua_pushstring(L, "kv");
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
        
        if (!lua_getmetatable(L, -1)) {
            luaL_error(L, "metatable not found: %s", classname);
        } else {
            lua_pop(L, 1);
        }
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
        s_obj_count++;
    }
}

int xluacls_ccobjgc(lua_State *L)
{
    cocos2d::Ref *obj = (cocos2d::Ref *)xluacls_checkobj(L, 1, "cc.Ref");
    if (obj) {
#ifdef COCOS2D_DEBUG
        int top = lua_gettop(L);
        xluacls_mt_tostring(L);
        const char *str = lua_tostring(L, -1);
        xgame::runtime::log("lua gc: obj=%s obj_ref_count=%d total_obj_count=%d",
            str, obj->getReferenceCount() - 1, s_obj_count - 1);
        lua_settop(L, top);
#endif
        obj->release();
        *(void **)lua_touserdata(L, 1) = nullptr;
        s_obj_count--;
    }
    return 0;
}


int xluacls_ccobjcount(lua_State *L)
{
    return s_obj_count;
}

void *xluacls_checkobj(lua_State *L, int idx, const char *classname)
{
    if (xluacls_isa(L, idx, classname)) {
        if (lua_isuserdata(L, idx)) {
            void *obj = *(void **)lua_touserdata(L, idx);
            if (obj) {
                return obj;
            } else {
                luaL_error(L, "object live from gc");
            }
        } else {
            luaL_error(L, "#%d argument error, expect: '%s', got '%s'", idx,
                classname, lua_typename(L, lua_type(L, idx)));
        }
    } else {
        luaL_error(L, "#%d argument error, expect: '%s', got '%s'", idx,
            classname, xlua_typename(L, idx));
    }
    return nullptr;
}
