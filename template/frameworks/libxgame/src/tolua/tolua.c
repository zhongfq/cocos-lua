#include "tolua/tolua.h"

#define OBJ_REF_TABLE ((void *)toluacls_pushobj)

#define CLS_CLSIDX  (lua_upvalueindex(1))
#define CLS_ISAIDX  (lua_upvalueindex(2))
#define CLS_FUNCIDX (lua_upvalueindex(3))
#define CLS_GETIDX  (lua_upvalueindex(4))
#define CLS_SETIDX  (lua_upvalueindex(5))
#define CLS_ISA     ".isa"
#define CLS_FUNC    ".func"
#define CLS_GET     ".get"
#define CLS_SET     ".set"

LUALIB_API int tolua_rawgetfield(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    return lua_rawget(L, idx);
}

LUALIB_API void tolua_rawsetfield(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    lua_insert(L, -2);
    lua_rawset(L, idx);
}

static bool ismetafunc(lua_State *L, int idx, const char *func)
{
    static const char *const tm[] = {
        "__index", "__newindex",
        "__gc", "__mode", "__len", "__eq",
        "__add", "__sub", "__mul", "__mod", "__pow",
        "__div", "__idiv",
        "__band", "__bor", "__bxor", "__shl", "__shr",
        "__unm", "__bnot", "__lt", "__le",
        "__concat", "__call",
        NULL
    };
    
    if (!func && lua_type(L, idx) == LUA_TSTRING) {
        func = lua_tostring(L, idx);
    }
    
    if (func) {
        for (int i = 0;; ++i) {
            const char *name = tm[i];
            if (!name) {
                break;
            } else if (strcmp(name, func) == 0) {
                return true;
            }
        }
    }
    
    return false;
}


static int trycacheget(lua_State *L, int idx, int kidx)
{
#define NILVALUE ((void *)trycacheget)
    int type;
    idx = lua_absindex(L, idx);                 // L: t k
    type =lua_rawget(L, idx);                   // L: t v
    if (type != LUA_TNIL) {
        if (type == LUA_TLIGHTUSERDATA
            && lua_touserdata(L, -1) == NILVALUE) {
            lua_pop(L, 1);
            lua_pushnil(L);
            return LUA_TNIL;
        }
        return type;
    }
    
    lua_pop(L, 1);                              // L: t
    lua_pushvalue(L, kidx);                     // L: t k
    type = lua_gettable(L, idx);                // L: t v
    lua_pushvalue(L, kidx);                     // L: t v k
    if (type != LUA_TNIL) {
        lua_pushvalue(L, -2);                   // L: t v k v
    } else {
        lua_pushlightuserdata(L, NILVALUE);     // L: t v k v
    }
    lua_rawset(L, idx);                         // L: t v
    
    return type;
}

static int cls_index(lua_State *L)
{
    // try func
    lua_settop(L, 2);                           // L: t k
    lua_pushvalue(L, CLS_FUNCIDX);              // L: t k .func
    lua_pushvalue(L, 2);                        // L: t k .func k
    if (trycacheget(L, -2, 2) != LUA_TNIL) {    // L: t k .func v
        return 1;
    }
    
    // try getter
    lua_settop(L, 2);                           // L: t k
    lua_pushvalue(L, CLS_GETIDX);               // L: t k .get
    lua_pushvalue(L, 2);                        // L: t k .get k
    if (trycacheget(L, -2, 2) != LUA_TNIL) {    // L: t k .get getter
        lua_pushvalue(L, 1);                    // L: t k .get getter t
        lua_call(L, 1, 1);                      // L: t k .get ret
        return 1;
    }
    
    // not found
    lua_settop(L, 2);                           // L: t k
    lua_pushnil(L);                             // L: t k nil
    
    return 1;
}

static int cls_newindex(lua_State *L)
{
    // try setter
    lua_settop(L, 3);                           // L: t k v
    lua_pushvalue(L, CLS_SETIDX);               // L: t k v .set
    lua_pushvalue(L, -2);                       // L: t k v .set k
    if (trycacheget(L, -2, 2) != LUA_TNIL) {    // L: t k v .set setter
        lua_pushvalue(L, 1);                    // L: t k v .set setter t
        lua_pushvalue(L, 3);                    // L: t k v .set setter t v
        lua_call(L, 2, 0);                      // L: t k v .set
        return 0;
    }
    
    if (lua_istable(L, 1)) {
        lua_settop(L, 3);                       // L: t k v
        lua_pushvalue(L, CLS_FUNCIDX);          // L: t k v .func
        lua_pushvalue(L, 2);                    // L: t k v .func k
        lua_pushvalue(L, 3);                    // L: t k v .func k v
        lua_rawset(L, -3);                      // L: t k v .func
        lua_pop(L, 1);                          // L: t k v
        
        if (ismetafunc(L, 2, NULL)) {
            lua_pushvalue(L, CLS_CLSIDX);       // L: t k v class
            lua_pushvalue(L, 2);                // L: t k v class k
            lua_pushvalue(L, 3);                // L: t k v class k v
            lua_rawset(L, -3);                  // L: t k v class
            lua_pop(L, 1);
        }
        
        return 0;
    }
    
    luaL_error(L, "readonly property: %s", lua_tostring(L, 2));
    
    return 0;
}

static int cls_tostring(lua_State *L)
{
    intptr_t p = 0;
    if (lua_isuserdata(L, 1)) {
        p = (intptr_t)(*(void **)lua_touserdata(L, 1));
    } else {
        p = (intptr_t)lua_topointer(L, 1);
    }
    
    lua_pushfstring(L, "%s: %p", toluacls_typename(L, 1), p);
    
    return 1;
}

static void create_table(lua_State *L, int idx, const char *field, const char *supercls, bool copy)
{
    idx = lua_absindex(L, idx);
    
    lua_newtable(L);                        // L: t
    if (supercls) {
        luaL_getmetatable(L, supercls);     // L: t super
        tolua_rawgetfield(L, -1, field);    // L: t super fv
        lua_createtable(L, 0, 1);           // L: t super fv mt
        lua_pushvalue(L, -2);               // L: t super fv mt fv
        tolua_rawsetfield(L, -2, "__index");// L: t super fv mt
        lua_setmetatable(L, -4);            // L: t super fv
        
        if (copy) {
            lua_pushnil(L);                 // L: t super fv k
            while (lua_next(L, -2)) {       // L: t super fv k v
                lua_pushvalue(L, -2);       // L: t super fv k v k
                lua_insert(L, -2);          // L: t super fv k k v
                lua_rawset(L, -6);          // L: t super fv k
            }                               // L: t super fv
        }
        
        lua_pop(L, 2);                      // L: t
    }
    
    lua_pushvalue(L, -1);                   // L: t t
    tolua_rawsetfield(L, idx, field);       // L: t     idx[field] = t
}

static void copysupermetafunc(lua_State *L, int idx, const char *supercls)
{
    idx = lua_absindex(L, idx);             // L: mt
    if (supercls) {
        luaL_getmetatable(L, supercls);     // L: mt super
        lua_pushnil(L);                     // L: mt super k
        while (lua_next(L, -2)) {           // L: mt super k v
            if (ismetafunc(L, -2, NULL)) {
                lua_pushvalue(L, -2);       // L: mt super k v k
                lua_pushvalue(L, -2);       // L: mt super k v k v
                lua_rawset(L, idx);         // L: mt super k v
            }
            lua_pop(L, 1);                  // L: mt super k
        }                                   // L: mt super
        lua_pop(L, 1);                      // L: mt
    }
}

LUALIB_API const char *toluacls_typename(lua_State *L, int idx)
{
    const char *tn = NULL;
    if (lua_getmetatable(L, idx)) {
        if (tolua_rawgetfield(L, -1, "classname") == LUA_TSTRING) {
            tn = lua_tostring(L, -1);
        }
        lua_pop(L, 2); // pop mt and value
    }
    
    if (tn == NULL) {
        tn = lua_typename(L, lua_type(L, idx));
    }
    
    return tn;
}

LUALIB_API void toluacls_class(lua_State *L, const char *cls, const char *super)
{
    if (super != NULL) {
        if (luaL_getmetatable(L, super) == LUA_TNIL) {
            luaL_error(L, "super class not found: %s", super);
        }
        lua_pop(L, 1);
    }
    
    if (luaL_getmetatable(L, cls) == LUA_TNIL) {
        int idx = lua_gettop(L);
        lua_pop(L, 1);
        luaL_newmetatable(L, cls);                      // L: mt
        lua_pushvalue(L, -1);                           // L: mt mt
        copysupermetafunc(L, -1, super);
        
        create_table(L, idx, CLS_ISA, super, true);     // L: mt mt .isa
        create_table(L, idx, CLS_FUNC, super, false);   // L: mt mt .isa .func
        create_table(L, idx, CLS_GET, super, false);    // L: mt mt .isa .func .get
        create_table(L, idx, CLS_SET, super, false);    // L: mt mt .isa .func .get .set
        
        static const luaL_Reg lib[] = {
            {"__index", cls_index},
            {"__newindex", cls_newindex},
            {"__tostring", cls_tostring},
            {NULL, NULL}
        };
        luaL_setfuncs(L, lib,  5);                      // L: mt
        
        lua_pushvalue(L, -1);
        toluacls_const(L, "class");
        
        lua_pushstring(L, cls);
        toluacls_const(L, "classname");
        
        if (super) {
            luaL_getmetatable(L, super);
            toluacls_const(L, "super");
        }
        
        tolua_rawgetfield(L, idx, CLS_ISA);
        lua_pushstring(L, cls);
        lua_pushboolean(L, true);
        lua_rawset(L, -3);
        lua_pop(L, 1);
    }
}

LUALIB_API void toluacls_createclassproxy(lua_State *L)
{
    lua_newtable(L);                        // L: mt p
    lua_createtable(L, 0, 2);               // L: mt p pmt
    lua_getfield(L, -3, "__index");         // L: mt p pmt __index
    tolua_rawsetfield(L, -2, "__index");    // L: mt p pmt
    lua_getfield(L, -3, "__newindex");      // L: mt p pmt __newindex
    tolua_rawsetfield(L, -2, "__newindex"); // L: mt p pmt
    lua_setmetatable(L, -2);                // L: mt p
}

LUALIB_API void toluacls_property(lua_State *L, const char *field, lua_CFunction getter, lua_CFunction setter)
{
    if (getter) {
        tolua_rawgetfield(L, -1, CLS_GET);  // L: mt .get
        lua_pushcfunction(L, getter);       // L: mt .get getter
        tolua_rawsetfield(L, -2, field);    // L: mt .get            .get[field] = getter
        lua_pop(L, 1);                      // L: mt
    }
    
    if (setter) {
        tolua_rawgetfield(L, -1, CLS_SET);  // L: mt .set
        lua_pushcfunction(L, setter);       // L: mt .set setter
        tolua_rawsetfield(L, -2, field);    // L: mt .set            .set[field] = setter
        lua_pop(L, 1);                      // L: mt
    }
}

LUALIB_API void toluacls_setfunc(lua_State *L, const char *name, lua_CFunction func)
{
    if (func) {
        lua_pushcfunction(L, func);         // L: mt func
        tolua_rawgetfield(L, -2, CLS_FUNC); // L: mt func .func
        lua_pushvalue(L, -2);               // L: mt func .func func
        tolua_rawsetfield(L, -2, name);     // L: mt func .func            .func[name] = func
        lua_pop(L, 1);                      // L: mt func
        
        if (ismetafunc(L, 0, name)) {
            tolua_rawsetfield(L, -2, name);
        } else {
            lua_pop(L, 1);                  // L: mt
        }
    }
}

static int cls_index_const(lua_State *L)
{
    lua_pushvalue(L, lua_upvalueindex(1));
    return 1;
}

LUALIB_API void toluacls_const(lua_State *L, const char *field)
{
    lua_pushvalue(L, -1);                        // L: mt v v
    tolua_rawsetfield(L, -3, field);             // L: mt v
    
    lua_pushcclosure(L, cls_index_const, 1);     // L: mt getter
    tolua_rawgetfield(L, -2, CLS_GET);           // L: mt getter .get
    lua_insert(L, -2);                           // L: mt .get getter
    tolua_rawsetfield(L, -2, field);             // L: mt .get
    lua_pop(L, 1);                               // L: mt
}

LUALIB_API void toluacls_const_bool(lua_State *L, const char *field, bool value)
{
    lua_pushboolean(L, value);
    toluacls_const(L, field);
}

LUALIB_API void toluacls_const_number(lua_State *L, const char *field, lua_Number value)
{
    lua_pushnumber(L, value);
    toluacls_const(L, field);
}

LUALIB_API void toluacls_const_integer(lua_State *L, const char *field, lua_Integer value)
{
    lua_pushinteger(L, value);
    toluacls_const(L, field);
}

LUALIB_API void toluacls_const_string(lua_State *L, const char *field, const char *value)
{
    lua_pushstring(L, value);
    toluacls_const(L, field);
}

LUALIB_API bool toluacls_isa(lua_State *L, int idx, const char *cls)
{
    bool isa = false;
    int top = lua_gettop(L);
    if (lua_getmetatable(L, idx)) {
        if (tolua_rawgetfield(L, -1, CLS_ISA) == LUA_TTABLE) {
            tolua_rawgetfield(L, -1, cls);
            isa = lua_toboolean(L, -1);
        }
    }
    lua_settop(L, top);
    return isa;
}

LUALIB_API bool toluacls_pushobj(lua_State *L, void *obj, const char *cls)
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
        luaL_setmetatable(L, cls);                          // L: mapping obj
        lua_pushvalue(L, -1);                               // L: mapping obj obj
        lua_rawsetp(L, -3, obj);                            // L: mapping obj
        is_new = true;
        
        if (!lua_getmetatable(L, -1)) {
            luaL_error(L, "metatable not found: %s", cls);
        } else {
            lua_pop(L, 1);
        }
    }
    
#ifdef TOLUA_DEBUG
    luaL_checkudata(L, -1, cls);
#endif
    
    lua_remove(L, -2);                                      // L: obj
    
    return is_new;
}

LUALIB_API void *toluacls_checkobj(lua_State *L, int idx, const char *cls)
{
    if (toluacls_isa(L, idx, cls)) {
        if (lua_isuserdata(L, idx)) {
            void *obj = *(void **)lua_touserdata(L, idx);
            if (obj) {
                return obj;
            } else {
                luaL_error(L, "object live from gc");
            }
        } else {
            luaL_error(L, "#%d argument error, expect: '%s', got '%s'", idx,
                cls, lua_typename(L, lua_type(L, idx)));
        }
    } else {
        luaL_error(L, "#%d argument error, expect: '%s', got '%s'", idx,
            cls, toluacls_typename(L, idx));
    }
    return NULL;
}

LUALIB_API void *toluacls_toobj(lua_State *L, int idx, const char *cls)
{
    if (lua_isuserdata(L, idx)) {
        void *obj = *(void **)lua_touserdata(L, idx);
        if (obj) {
            return obj;
        } else {
            luaL_error(L, "object live from gc");
        }
    } else {
        luaL_error(L, "#%d argument error, expect: '%s', got '%s'", idx,
            cls, lua_typename(L, lua_type(L, idx)));
    }
    return NULL;
}

LUALIB_API int tolua_push_bool(lua_State *L, bool value)
{
    lua_pushboolean(L, value);
    return 1;
}

LUALIB_API void tolua_check_bool(lua_State *L, int idx, bool *value)
{
    luaL_checktype(L, idx, LUA_TBOOLEAN);
    *value = lua_toboolean(L, idx);
}

LUALIB_API void tolua_opt_bool(lua_State *L, int idx, bool *value, bool def)
{
    *value = lua_type(L, idx) <= LUA_TNIL ? def : lua_toboolean(L, idx) != 0;
}

LUALIB_API bool tolua_is_bool(lua_State *L, int idx)
{
    return lua_isboolean(L, idx);
}

LUALIB_API int tolua_push_string(lua_State *L, const char *value)
{
    lua_pushstring(L, value);
    return 1;
}

LUALIB_API void tolua_check_string(lua_State *L, int idx, const char **value)
{
    luaL_checktype(L, idx, LUA_TSTRING);
    *value = lua_tostring(L, idx);
}

LUALIB_API void tolua_opt_string(lua_State *L, int idx, const char **value, const char *def)
{
    *value = luaL_optstring(L, idx, def);
}

LUALIB_API bool tolua_is_string(lua_State *L, int idx)
{
    return lua_isstring(L, idx);
}

LUALIB_API int tolua_push_number(lua_State *L, lua_Number value)
{
    lua_pushnumber(L, value);
    return 1;
}

LUALIB_API void tolua_check_number(lua_State *L, int idx, lua_Number *value)
{
    *value = luaL_checknumber(L, idx);
}

LUALIB_API void tolua_opt_number(lua_State *L, int idx, lua_Number *value, lua_Number def)
{
    *value = luaL_optnumber(L, idx, def);
}

LUALIB_API bool tolua_is_number(lua_State *L, int idx)
{
    return lua_isnumber(L, idx);
}

LUALIB_API int tolua_push_int(lua_State *L, lua_Integer value)
{
    lua_pushinteger(L, value);
    return 1;
}

LUALIB_API void tolua_check_int(lua_State *L, int idx, lua_Integer *value)
{
    *value = luaL_checkinteger(L, idx);
}

LUALIB_API bool tolua_is_int(lua_State *L, int idx)
{
    return lua_isinteger(L, idx);
}

LUALIB_API void tolua_opt_int(lua_State *L, int idx, lua_Integer *value, lua_Integer def)
{
    *value = luaL_optinteger(L, idx, def);
}

LUALIB_API int tolua_push_uint(lua_State *L, lua_Unsigned value)
{
    return tolua_push_int(L, (lua_Integer)value);
}

LUALIB_API void tolua_check_uint(lua_State *L, int idx, lua_Unsigned *value)
{
    *value = (lua_Unsigned)luaL_checkinteger(L, idx);
}

LUALIB_API void tolua_opt_uint(lua_State *L, int idx, lua_Unsigned *value, lua_Unsigned def)
{
    *value = (lua_Unsigned)luaL_optinteger(L, idx, (lua_Integer)def);
}

LUALIB_API bool tolua_is_uint(lua_State *L, int idx)
{
    return lua_isinteger(L, idx);
}

LUALIB_API int tolua_push_obj(lua_State *L, void *obj, const char *cls)
{
    toluacls_pushobj(L, obj, cls);
    return 1;
}

LUALIB_API void tolua_check_obj(lua_State *L, int idx, void **value, const char *cls)
{
    *value = toluacls_checkobj(L, idx, cls);
}

LUALIB_API void tolua_to_obj(lua_State *L, int idx, void **value, const char *cls)
{
    *value = toluacls_toobj(L, idx, cls);
}

LUALIB_API bool tolua_is_obj(lua_State *L, int idx, const char *cls)
{
    return toluacls_isa(L, idx, cls);
}
