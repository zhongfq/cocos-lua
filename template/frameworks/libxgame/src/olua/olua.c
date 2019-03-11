#include "olua/olua.h"

#define OBJ_REF_TABLE ((void *)olua_pushobj)

#define CLS_CLSIDX  (lua_upvalueindex(1))
#define CLS_ISAIDX  (lua_upvalueindex(2))
#define CLS_FUNCIDX (lua_upvalueindex(3))
#define CLS_GETIDX  (lua_upvalueindex(4))
#define CLS_SETIDX  (lua_upvalueindex(5))
#define CLS_ISA     ".isa"
#define CLS_FUNC    ".func"
#define CLS_GET     ".get"
#define CLS_SET     ".set"

#define VOIDCLS     "void *"

#define TRACEBACK (_traceback ? _traceback : dummy_traceback)

static lua_CFunction _traceback = NULL;

static inline bool strequal(const char *str1, const char *str2)
{
    return strcmp(str1, str2) == 0;
}

static inline bool strendwith(const char *src, const char *suffix)
{
    const char *pos = strstr(src, suffix);
    return !pos ? false : (src + strlen(src) == pos + strlen(suffix));
}

static int dummy_traceback(lua_State *L)
{
    return 0;
}

LUALIB_API int olua_rawgetfield(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    return lua_rawget(L, idx);
}

LUALIB_API void olua_rawsetfield(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    lua_insert(L, -2);
    lua_rawset(L, idx);
}

LUALIB_API void olua_seterrfunc(lua_CFunction errfunc)
{
    _traceback = errfunc;
}

LUALIB_API const char *olua_typename(lua_State *L, int idx)
{
    const char *tn = NULL;
    if (lua_getmetatable(L, idx)) {
        if (olua_rawgetfield(L, -1, "classname") == LUA_TSTRING) {
            tn = lua_tostring(L, -1);
        }
        lua_pop(L, 2); // pop mt and value
    }
    
    return tn ? tn : lua_typename(L, lua_type(L, idx));
}

LUALIB_API const char *olua_tostring(lua_State *L, int idx)
{
    if (lua_type(L, idx) == LUA_TUSERDATA) {
        intptr_t p = (intptr_t)(*(void **)lua_touserdata(L, idx));
        intptr_t p2 = (intptr_t)lua_topointer(L, idx);
        return lua_pushfstring(L, "%s: %p|%p", olua_typename(L, idx), p, p2);
    } else {
        intptr_t p = (intptr_t)lua_topointer(L, idx);
        return lua_pushfstring(L, "%s: %p", olua_typename(L, idx), p);
    }
}

LUALIB_API bool olua_isa(lua_State *L, int idx, const char *cls)
{
    bool isa = false;
    int top = lua_gettop(L);
    if (lua_getmetatable(L, idx)) {
        if (olua_rawgetfield(L, -1, CLS_ISA) == LUA_TTABLE) {
            olua_rawgetfield(L, -1, cls);
            isa = lua_toboolean(L, -1);
        }
    }
    lua_settop(L, top);
    return isa;
}

LUALIB_API int olua_pushobj(lua_State *L, void *obj, const char *cls)
{
    int status = OLUA_OBJ_EXIST;
    
    if (!obj) {
        lua_pushnil(L);
        return status;
    }
    
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
        lua_rawsetp(L, -3, obj); // mapping[obj] = uobj     // L: mapping obj
        status = OLUA_OBJ_NEW;
        
        if (!lua_getmetatable(L, -1)) {
            luaL_error(L, "metatable not found: %s", cls);
        } else {
            lua_pop(L, 1);
        }
    }
    
    if (!strequal(cls, VOIDCLS) && luaL_testudata(L, -1, VOIDCLS)) {
        luaL_setmetatable(L, cls);
        status = OLUA_OBJ_UPDATE;
    }
    
#ifdef OLUA_DEBUG
    olua_checkobj(L, -1, cls);
#endif
    
    lua_remove(L, -2);                                      // L: obj
    
    return status;
}

LUALIB_API bool olua_getobj(lua_State *L, void *obj)
{
    int top = lua_gettop(L);
    
    if (lua_rawgetp(L, LUA_REGISTRYINDEX, OBJ_REF_TABLE) == LUA_TTABLE) {
        if (lua_rawgetp(L, -1, obj) == LUA_TUSERDATA) {
            lua_insert(L, top + 1);
            lua_settop(L, top + 1);
            return true;
        }
    }
    
    lua_settop(L, top);
    
    return false;
}

static bool getuservalue(lua_State *L, int idx)
{
    idx = lua_absindex(L, idx);
    if (lua_getuservalue(L, idx) == LUA_TNIL) {
        lua_pop(L, 1);
        lua_createtable(L, 0, 4);
        lua_pushvalue(L, -1);
        lua_setuservalue(L, idx);
    }
#ifdef OLUA_DEBUG
    luaL_checktype(L, -1, LUA_TTABLE);
#endif
    
    return lua_istable(L, -1);
}

LUALIB_API const char *olua_setcallback(lua_State *L, void *obj, const char *tag, int func, olua_callback_tag_t mode)
{
    static int ref = 0;
    const char *field = NULL;
    
    func = lua_absindex(L, func);
    luaL_checktype(L, func, LUA_TFUNCTION);
    
    if (!olua_getobj(L, obj) ||
        !getuservalue(L, -1)) {                     // L: obj ct
        luaL_error(L, "obj userdata not found");
    }

    lua_remove(L, -2);                              // L: ct
    
    if (mode == OLUA_CALLBACK_TAG_REPLACE) {
        lua_pushnil(L);                             // L: ct k
        while (lua_next(L, -2)) {                   // L: ct k v
            if (lua_isstring(L, -2)) {
                const char *s = lua_tostring(L, -2);
                if (strendwith(s, tag)) {
                    field = s;
                    lua_pop(L, 1);                  // L: ct k
                    break;
                }
            }
            lua_pop(L, 1);                          // L: ck k
        }
    } else {
#ifdef OLUA_DEBUG
        if (mode != OLUA_CALLBACK_TAG_NEW) {
            luaL_error(L, "unsupport callback tag: %d", (int)mode);
        }
#endif
    }
    
    if (!field) {
        field = lua_pushfstring(L, "oluacallback#%d|%s", ++ref, tag);
    }
    
    lua_pushvalue(L, func);                         // L: ct k  v
    olua_rawsetfield(L, -3, field);                 // L: ct k
    lua_remove(L, -2);                              // L: k
    
    return lua_tostring(L, -1);
}

static bool shouldremovecallback(const char *field, const char *tag, olua_callback_tag_t mode)
{
    if (mode == OLUA_CALLBACK_TAG_WILDCARD) {
        return strstr(field, tag) != NULL;
    } else if (mode == OLUA_CALLBACK_TAG_ENDWITH) {
        return strendwith(field, tag);
    } else {
        return false;
    }
}

LUALIB_API void olua_removecallback(lua_State *L, void *obj, const char *tag, olua_callback_tag_t mode)
{
    int top = lua_gettop(L);
    if (olua_getobj(L, obj) && getuservalue(L, -1)) {
        if (mode == OLUA_CALLBACK_TAG_EQUAL) {
            lua_pushnil(L);                                 // L: ct nil
            olua_rawsetfield(L, -2, tag);                   // L: ct
        } else {
            lua_pushnil(L);                                 // L: ct k
            while (lua_next(L, -2)) {                       // L: ct k v
                if (lua_isstring(L, -2)) {
                    const char *field = lua_tostring(L, -2);
                    if (shouldremovecallback(field, tag, mode)) {
                        lua_pushvalue(L, -2);               // L: ct k v k
                        lua_pushnil(L);                     // L: ct k v k nil
                        lua_rawset(L, -5);                  // L: ct k v
                    }
                }
                lua_pop(L, 1);                              // L: ct k
            }
        }
    }
    lua_settop(L, top);
}

LUALIB_API bool olua_callback(lua_State *L, void *obj, const char *field, int n)
{
    int top = lua_gettop(L) - n;
    bool ret = false;
    
    if (olua_getobj(L, obj) && getuservalue(L, -1)) {           // L: arg...n obj ct
        if (olua_rawgetfield(L, -1, field) == LUA_TFUNCTION) {  // L: arg...n obj ct callback
            lua_insert(L, top + 1);                             // L: callback arg...n obj ct
            lua_pop(L, 2);                                      // L: callback arg...n
            
            lua_pushcfunction(L, TRACEBACK);                    // L: callback arg...n errfunc
            lua_insert(L, top + 1);                             // L: errfunc callback arg...n
            
            ret = lua_pcall(L, n, 1, top + 1) == LUA_OK;        // L: errfunc result
            lua_remove(L, -2);                                  // L: result
        }
    }
    
    if (!ret) {
        lua_settop(L, top);
        lua_pushnil(L);
    }
    
    return ret;
}

LUALIB_API int olua_getvariable(lua_State *L, int idx)
{
    int type = LUA_TNIL;
    getuservalue(L, idx);           // L: k uv
    lua_insert(L, -2);              // L: uv k
    type = lua_rawget(L, -2);       // L: uv v
    lua_remove(L, -2);              // L: v
    return type;
}

LUALIB_API void olua_setvariable(lua_State *L, int idx)
{
    getuservalue(L, idx);           // L: k v uv
    lua_insert(L, -3);              // L: uv k v
    lua_rawset(L, -3);              // L: uv          idx.uservalue[k] = v
    lua_pop(L, 1);                  // L:
}

LUALIB_API void *olua_checkobj(lua_State *L, int idx, const char *cls)
{
    if (olua_isa(L, idx, cls)) {
        if (lua_type(L, idx) == LUA_TUSERDATA) {
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
            cls, olua_typename(L, idx));
    }
    return NULL;
}

LUALIB_API void *olua_toobj(lua_State *L, int idx, const char *cls)
{
    if (lua_type(L, idx) == LUA_TUSERDATA) {
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

LUALIB_API void olua_callgc(lua_State *L, int idx)
{
    int top = lua_gettop(L);
    void *p = lua_type(L, idx) == LUA_TUSERDATA ? (*(void **)lua_touserdata(L, idx)) : NULL;
    idx = lua_absindex(L, idx);
    lua_pushcfunction(L, TRACEBACK);
    if (lua_getfield(L, idx, "__gc") == LUA_TFUNCTION) {
        lua_pushvalue(L, idx);
        lua_pcall(L, 1, 0, top + 1);
    }
    if (p && lua_rawgetp(L, LUA_REGISTRYINDEX, OBJ_REF_TABLE) == LUA_TTABLE) {
        lua_pushnil(L);
        lua_rawsetp(L, -2, p);
    }
    lua_settop(L, top);
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
            } else if (strequal(name, func)) {
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
    kidx = lua_absindex(L, kidx);
    idx = lua_absindex(L, idx);                 // L: t
    lua_pushvalue(L, kidx);                     // L: t k
    type = lua_rawget(L, idx);                  // L: t v
    
    if (type == LUA_TNIL) {
        lua_pop(L, 1);                          // L: t
        lua_pushvalue(L, kidx);                 // L: t k
        type = lua_gettable(L, idx);            // L: t v
        lua_pushvalue(L, kidx);                 // L: t v k
        if (type == LUA_TNIL) {
            lua_pushlightuserdata(L, NILVALUE); // L: t v k v
        } else {
            lua_pushvalue(L, -2);               // L: t v k v
        }
        lua_rawset(L, idx);                     // L: t v
    }
    
    if (type == LUA_TLIGHTUSERDATA && lua_touserdata(L, -1) == NILVALUE) {
        lua_pop(L, 1);
        lua_pushnil(L);
        type = LUA_TNIL;
    }
    
    return type;
}

static int cls_index(lua_State *L)
{
    // try getter
    lua_settop(L, 2);                           // L: t k
    lua_pushvalue(L, CLS_GETIDX);               // L: t k .get
    if (trycacheget(L, -1, 2) != LUA_TNIL) {    // L: t k .get getter
        lua_pushvalue(L, 1);                    // L: t k .get getter t
        lua_call(L, 1, 1);                      // L: t k .get ret
        return 1;
    }
    
    // try variable
    if (lua_type(L, 1) == LUA_TUSERDATA) {
        lua_settop(L, 2);
        lua_pushvalue(L, 2);
        if (olua_getvariable(L, 1) != LUA_TNIL) {
            return 1;
        }
    }
    
    // try func
    lua_settop(L, 2);                           // L: t k
    lua_pushvalue(L, CLS_FUNCIDX);              // L: t k .func
    if (trycacheget(L, -1, 2) != LUA_TNIL) {    // L: t k .func v
        return 1;
    }
    
    return 1;
}

static int cls_newindex(lua_State *L)
{
    // try setter
    lua_settop(L, 3);                           // L: t k v
    lua_pushvalue(L, CLS_SETIDX);               // L: t k v .set
    if (trycacheget(L, -1, 2) != LUA_TNIL) {    // L: t k v .set setter
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
    
    lua_settop(L, 3);                           // L: t k v
    lua_pushvalue(L, CLS_GETIDX);               // L: t k v .set
    if (trycacheget(L, -1, 2) != LUA_TNIL) {
        luaL_error(L, "readonly property: %s", lua_tostring(L, 2));
    }
    
    if (lua_type(L, 1) == LUA_TUSERDATA) {
        lua_settop(L, 3);
        olua_setvariable(L, 1);
    } else {
        luaL_checktype(L, 1, LUA_TUSERDATA);
    }
    
    return 0;
}

static int cls_tostring(lua_State *L)
{
    olua_tostring(L, 1);
    
    return 1;
}

static void create_table(lua_State *L, int idx, const char *field, const char *supercls, bool copy)
{
    idx = lua_absindex(L, idx);
    
    lua_newtable(L);                        // L: t
    if (supercls) {
        luaL_getmetatable(L, supercls);     // L: t super
        olua_rawgetfield(L, -1, field);     // L: t super fv
        lua_createtable(L, 0, 1);           // L: t super fv mt
        lua_pushvalue(L, -2);               // L: t super fv mt fv
        olua_rawsetfield(L, -2, "__index"); // L: t super fv mt
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
    olua_rawsetfield(L, idx, field);        // L: t     idx[field] = t
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

LUALIB_API void oluacls_class(lua_State *L, const char *cls, const char *super)
{
    if (super != NULL) {
        if (luaL_getmetatable(L, super) == LUA_TNIL) {
            luaL_error(L, "super class not found: %s", super);
        }
        lua_pop(L, 1);
    } else {
        if (!strequal(cls, VOIDCLS)) {
            oluacls_class(L, VOIDCLS, NULL);
            lua_pop(L, 1);
            super = VOIDCLS;
        }
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
        oluacls_const(L, "class");
        
        lua_pushstring(L, cls);
        oluacls_const(L, "classname");
        
        if (super) {
            luaL_getmetatable(L, super);
            oluacls_const(L, "super");
        }
        
        olua_rawgetfield(L, idx, CLS_ISA);
        lua_pushstring(L, cls);
        lua_pushboolean(L, true);
        lua_rawset(L, -3);
        lua_pop(L, 1);
    }
}

LUALIB_API void oluacls_createclassproxy(lua_State *L)
{
    lua_newtable(L);                        // L: mt p
    lua_createtable(L, 0, 2);               // L: mt p pmt
    lua_getfield(L, -3, "__index");         // L: mt p pmt __index
    olua_rawsetfield(L, -2, "__index");     // L: mt p pmt
    lua_getfield(L, -3, "__newindex");      // L: mt p pmt __newindex
    olua_rawsetfield(L, -2, "__newindex");  // L: mt p pmt
    lua_setmetatable(L, -2);                // L: mt p
}

LUALIB_API void oluacls_property(lua_State *L, const char *field, lua_CFunction getter, lua_CFunction setter)
{
    if (getter) {
        olua_rawgetfield(L, -1, CLS_GET);   // L: mt .get
        lua_pushcfunction(L, getter);       // L: mt .get getter
        olua_rawsetfield(L, -2, field);     // L: mt .get            .get[field] = getter
        lua_pop(L, 1);                      // L: mt
    }
    
    if (setter) {
        olua_rawgetfield(L, -1, CLS_SET);   // L: mt .set
        lua_pushcfunction(L, setter);       // L: mt .set setter
        olua_rawsetfield(L, -2, field);     // L: mt .set            .set[field] = setter
        lua_pop(L, 1);                      // L: mt
    }
}

LUALIB_API void oluacls_setfunc(lua_State *L, const char *name, lua_CFunction func)
{
    if (func) {
        lua_pushcfunction(L, func);         // L: mt func
        olua_rawgetfield(L, -2, CLS_FUNC);  // L: mt func .func
        lua_pushvalue(L, -2);               // L: mt func .func func
        olua_rawsetfield(L, -2, name);      // L: mt func .func            .func[name] = func
        lua_pop(L, 1);                      // L: mt func
        
        if (ismetafunc(L, 0, name)) {
            olua_rawsetfield(L, -2, name);
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

LUALIB_API void oluacls_const(lua_State *L, const char *field)
{
    lua_pushvalue(L, -1);                       // L: mt v v
    olua_rawsetfield(L, -3, field);             // L: mt v
    
    lua_pushcclosure(L, cls_index_const, 1);    // L: mt getter
    olua_rawgetfield(L, -2, CLS_GET);           // L: mt getter .get
    lua_insert(L, -2);                          // L: mt .get getter
    olua_rawsetfield(L, -2, field);             // L: mt .get
    lua_pop(L, 1);                              // L: mt
}

LUALIB_API int olua_push_bool(lua_State *L, bool value)
{
    lua_pushboolean(L, value);
    return 1;
}

LUALIB_API void olua_check_bool(lua_State *L, int idx, bool *value)
{
    luaL_checktype(L, idx, LUA_TBOOLEAN);
    *value = lua_toboolean(L, idx);
}

LUALIB_API void olua_opt_bool(lua_State *L, int idx, bool *value, bool def)
{
    *value = lua_type(L, idx) <= LUA_TNIL ? def : lua_toboolean(L, idx) != 0;
}

LUALIB_API int olua_push_string(lua_State *L, const char *value)
{
    lua_pushstring(L, value);
    return 1;
}

LUALIB_API void olua_check_string(lua_State *L, int idx, const char **value)
{
    *value = luaL_checkstring(L, idx);
}

LUALIB_API void olua_opt_string(lua_State *L, int idx, const char **value, const char *def)
{
    *value = luaL_optstring(L, idx, def);
}

LUALIB_API int olua_push_number(lua_State *L, lua_Number value)
{
    lua_pushnumber(L, value);
    return 1;
}

LUALIB_API void olua_check_number(lua_State *L, int idx, lua_Number *value)
{
    *value = luaL_checknumber(L, idx);
}

LUALIB_API void olua_opt_number(lua_State *L, int idx, lua_Number *value, lua_Number def)
{
    *value = luaL_optnumber(L, idx, def);
}

LUALIB_API int olua_push_int(lua_State *L, lua_Integer value)
{
    lua_pushinteger(L, value);
    return 1;
}

LUALIB_API void olua_check_int(lua_State *L, int idx, lua_Integer *value)
{
    *value = luaL_checkinteger(L, idx);
}

LUALIB_API void olua_opt_int(lua_State *L, int idx, lua_Integer *value, lua_Integer def)
{
    *value = luaL_optinteger(L, idx, def);
}

LUALIB_API int olua_push_uint(lua_State *L, lua_Unsigned value)
{
    return olua_push_int(L, (lua_Integer)value);
}

LUALIB_API void olua_check_uint(lua_State *L, int idx, lua_Unsigned *value)
{
    *value = (lua_Unsigned)luaL_checkinteger(L, idx);
}

LUALIB_API void olua_opt_uint(lua_State *L, int idx, lua_Unsigned *value, lua_Unsigned def)
{
    *value = (lua_Unsigned)luaL_optinteger(L, idx, (lua_Integer)def);
}

LUALIB_API int olua_push_obj(lua_State *L, void *obj, const char *cls)
{
    olua_pushobj(L, obj, cls);
    return 1;
}

LUALIB_API void olua_check_obj(lua_State *L, int idx, void **value, const char *cls)
{
    *value = olua_checkobj(L, idx, cls);
}

LUALIB_API void olua_to_obj(lua_State *L, int idx, void **value, const char *cls)
{
    *value = olua_toobj(L, idx, cls);
}

static void auxchecktype(lua_State *L, int idx, const char *field, int type, bool isinteger)
{
    if ((isinteger && !lua_isinteger(L, idx)) ||
        (!isinteger && lua_type(L, idx) != type)) {
        const char *msg;
        const char *typearg;
        const char *tname = lua_typename(L, type);
        if (isinteger) {
            tname = "integer";
        }
        if (luaL_getmetafield(L, idx, "__name") == LUA_TSTRING) {
            typearg = lua_tostring(L, -1);
        } else if (lua_type(L, idx) == LUA_TLIGHTUSERDATA) {
            typearg = "light userdata";
        } else {
            typearg = luaL_typename(L, idx);
        }
        msg = lua_pushfstring(L, "olua check '%s': %s expected, got %s", field, tname, typearg);
        luaL_argerror(L, idx, msg);
    }
}

LUALIB_API const char *olua_checkfieldstring(lua_State *L, int idx, const char *field)
{
    const char *value;
    idx = lua_absindex(L, idx);
    lua_getfield(L, idx, field);
    auxchecktype(L, -1, field, LUA_TSTRING, false);
    value = lua_tostring(L, -1);
    lua_pop(L, 1);
    return value;
}

LUALIB_API lua_Number olua_checkfieldnumber(lua_State *L, int idx, const char *field)
{
    lua_Number value;
    idx = lua_absindex(L, idx);
    lua_getfield(L, idx, field);
    auxchecktype(L, -1, field, LUA_TNUMBER, false);
    value = lua_tonumber(L, -1);
    lua_pop(L, 1);
    return value;
}

LUALIB_API lua_Integer olua_checkfieldinteger(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_getfield(L, idx, field);
    auxchecktype(L, -1, field, LUA_TNUMBER, true);
    lua_Integer value = lua_tointeger(L, -1);
    lua_pop(L, 1);
    return value;
}

LUALIB_API bool olua_checkfieldboolean(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_getfield(L, idx, field);
    auxchecktype(L, -1, field, LUA_TBOOLEAN, false);
    bool value = lua_toboolean(L, -1);
    lua_pop(L, 1);
    return value;
}

LUALIB_API void olua_rawsetfieldnumber(lua_State *L, int idx, const char *field, lua_Number value)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    lua_pushnumber(L, value);
    lua_rawset(L, idx);
}

LUALIB_API void olua_rawsetfieldinteger(lua_State *L, int idx, const char *field, lua_Integer value)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    lua_pushinteger(L, value);
    lua_rawset(L, idx);
}

LUALIB_API void olua_rawsetfieldstring(lua_State *L, int idx, const char *field, const char *value)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    lua_pushstring(L, value);
    lua_rawset(L, idx);
}

LUALIB_API void olua_rawsetfieldboolean(lua_State *L, int idx, const char *field, bool value)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    lua_pushboolean(L, value);
    lua_rawset(L, idx);
}
