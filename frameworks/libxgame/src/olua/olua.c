/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2019-2022 codetypes@gmail.com
 *
 * https://github.com/zhongfq/olua
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "olua.h"

#define OLUA_CIDX_ISA   (lua_upvalueindex(1))
#define OLUA_CIDX_FUNC  (lua_upvalueindex(2))
#define OLUA_CIDX_GET   (lua_upvalueindex(3))
#define OLUA_CIDX_SET   (lua_upvalueindex(4))
#define OLUA_CIDX_USER  (lua_upvalueindex(5))
#define OLUA_CIDX_TOTAL 5

#define OLUA_CKEY_ISA       ".isa"
#define OLUA_CKEY_FUNC      ".func"
#define OLUA_CKEY_GET       ".get"
#define OLUA_CKEY_SET       ".set"
#define OLUA_CKEY_CLSOBJ    ".classobj"
#define OLUA_CKEY_CLASS     ".class"

#define OLUA_OWNERSHIP      ".olua.ownership"
#define OLUA_OBJSTUB        ".olua.objstub"
#define OLUA_OBJTABLE       ".olua.objtable"
#define OLUA_POOLTABLE      ".olua.pooltable"
#define OLUA_LUAREFTABLE    ".olua.luareftable"
#define OLUA_VMENV          ".olua.vmenv"

#define registry_rawgeti(L, f)  olua_rawgeti(L, LUA_REGISTRYINDEX, (f))
#define registry_rawgetf(L, f)  olua_rawgetf(L, LUA_REGISTRYINDEX, (f))
#define registry_rawsetf(L, f)  olua_rawsetf(L, LUA_REGISTRYINDEX, (f))

#define strequal(s1, s2)        (strcmp((s1), (s2)) == 0)
#define strstartwith(s1, s2)    (strstr((s1), (s2)) == s1)
#define aux_pushrefkey(L, n)    (lua_pushfstring(L, ".olua.ref.%s", (n)))
#define aux_pushcbkey(L, ...)   (lua_pushfstring(L, ".olua.cb#%s$%s@%s", __VA_ARGS__))

#define const_from_metaclass(L, k, metaclass) \
    olua_rawgetf(L, (metaclass), (k)); \
    oluacls_const(L, k)

typedef struct {
    int64_t ctxid;
    size_t objcount;
    size_t poolsize;
    int64_t refcount;
    bool poolenabled;
    bool debug;
} olua_VMEnv;

static inline int64_t obtainref(olua_VMEnv *env)
{
    return ++env->refcount <= 0 ? 1 : env->refcount;
}

static int errfunc(lua_State *L)
{
    if (olua_isthread(L, 1)) {
        luaL_traceback(L, lua_tothread(L, 1), lua_tostring(L, 2), 0);
        lua_insert(L, 1);
    }
    luaL_traceback(L, L, lua_tostring(L, 1), 1);
    printf("%s\n", lua_tostring(L, -1));
    return 0;
}

static olua_VMEnv *aux_getvmenv(lua_State *L)
{
    static int64_t s_ctxid = 0;
    
    olua_VMEnv *env;
    if (olua_unlikely(registry_rawgetf(L, OLUA_VMENV) != LUA_TUSERDATA)) {
        env = (olua_VMEnv *)lua_newuserdata(L, sizeof(*env));
        env->ctxid = ++s_ctxid;
        env->debug = false;
        env->poolenabled = false;
        env->poolsize = 0;
        env->objcount = 0;
        env->refcount = 0;
        registry_rawsetf(L, OLUA_VMENV);
#if LUA_VERSION_NUM == 501
        // detect main thread
        olua_getglobal(L, "coroutine");
        olua_getfield(L, -1, "running");
        lua_call(L, 0, 1);
        if (olua_isnil(L, -1)) {
            olua_initcompat(L);
        }
        lua_pop(L, 2); // pop coroutine table and return value

        if (registry_rawgeti(L, LUA_RIDX_MAINTHREAD) != LUA_TTHREAD) {
            luaL_error(L, "main thread not set");
        }
        if (registry_rawgeti(L, LUA_RIDX_GLOBALS) != LUA_TTABLE) {
            luaL_error(L, "global table not set");
        }
        if (!lua_rawequal(L, -1, LUA_GLOBALSINDEX)) {
            luaL_error(L, "global table not match");
        }
        lua_pop(L, 2);
#endif
    } else {
        env = (olua_VMEnv *)lua_touserdata(L, -1);
    }
    lua_pop(L, 1);
    return env;
}

OLUA_API size_t olua_objcount(lua_State *L)
{
    return aux_getvmenv(L)->objcount;
}

OLUA_API bool olua_isdebug(lua_State *L)
{
    return aux_getvmenv(L)->debug;
}

bool olua_isinteger(lua_State *L, int idx)
{
#if LUA_VERSION_NUM >= 503
    if (lua_isinteger(L, idx)) {
        return true;
    }
#endif
    if (olua_isnumber(L, idx)) {
        lua_Number n = lua_tonumber(L, idx);
        return n == (lua_Number)(floor(n));
    }
    return false;
}

OLUA_API lua_Integer olua_checkinteger(lua_State *L, int idx)
{
    luaL_checktype(L, idx, LUA_TNUMBER);
    return luaL_checkinteger(L, idx);
}

OLUA_API lua_Number olua_checknumber(lua_State *L, int idx)
{
    luaL_checktype(L, idx, LUA_TNUMBER);
    return olua_tonumber(L, idx);
}

OLUA_API const char *olua_checklstring(lua_State *L, int idx, size_t *len)
{
    luaL_checktype(L, idx, LUA_TSTRING);
    return olua_tolstring(L, idx, len);
}

OLUA_API bool olua_checkboolean(lua_State *L, int idx)
{
    luaL_checktype(L, idx, LUA_TBOOLEAN);
    return olua_toboolean(L, idx);
}

OLUA_API int olua_rawgetf(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    return olua_rawget(L, idx);
}

OLUA_API void olua_rawsetf(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    lua_insert(L, -2);
    olua_rawset(L, idx);
}

OLUA_API void olua_pusherrorfunc(lua_State *L)
{
    if (olua_unlikely(olua_getglobal(L, "__TRACEBACK__") != LUA_TFUNCTION)) {
        lua_pop(L, 1);
        lua_pushcfunction(L, errfunc);
    }
}

OLUA_API int olua_pcall(lua_State *L, int nargs, int nresults)
{
    int status;
    int errfunc = lua_absindex(L, -(nargs + 1));
    olua_pusherrorfunc(L);
    lua_insert(L, errfunc); // insert error handle at func position
    status = lua_pcall(L, nargs, nresults, errfunc);
    lua_remove(L, errfunc);
    return status;
}

OLUA_API void olua_require(lua_State *L, const char *name, lua_CFunction func)
{
    luaL_requiref(L, name, func, false);
    lua_pop(L, 1); // pop result
}

OLUA_API const char *olua_typename(lua_State *L, int idx)
{
    const char *tn = NULL;
    if (olua_isuserdata(L, idx) && lua_getmetatable(L, idx)) {
        if (olua_rawgetf(L, -1, "__name") == LUA_TSTRING) {
            tn = olua_tostring(L, -1);
        }
        lua_pop(L, 2); // pop mt and value
    }
    return tn ? tn : lua_typename(L, lua_type(L, idx));
}

OLUA_API bool olua_isa(lua_State *L, int idx, const char *cls)
{
    bool isa = false;
    int top = lua_gettop(L);
    if (olua_likely(olua_isuserdata(L, idx) && lua_getmetatable(L, idx))) {
        if (olua_likely(olua_rawgetf(L, -1, OLUA_CKEY_ISA) == LUA_TTABLE)) {
            olua_rawgetf(L, -1, cls);
            isa = olua_toboolean(L, -1);
        }
    }
    lua_settop(L, top);
    return isa;
}

static void aux_pushobjtable(lua_State *L)
{
    if (olua_unlikely(registry_rawgetf(L, OLUA_OBJTABLE) != LUA_TTABLE)) {
        lua_pop(L, 1);
        lua_newtable(L);
        olua_setfieldstring(L, -1, "__mode", "v"); // value weak table
        lua_pushvalue(L, -1);
        lua_setmetatable(L, -2);
        lua_pushvalue(L, -1);
        registry_rawsetf(L, OLUA_OBJTABLE);
    }
}

OLUA_API void *olua_newobjstub(lua_State *L, const char *cls)
{
    void *ptr;
    aux_pushobjtable(L);
    olua_newrawobj(L, NULL); // create obj stub
    ptr = (void *)lua_topointer(L, -1);
    lua_pushvalue(L, -1);
    olua_rawsetp(L, -3, ptr); // objtable[ptr] = stub
    lua_replace(L, -2); // pop objtable
    olua_setmetatable(L, cls);
    aux_getvmenv(L)->objcount++;
    return ptr;
}

OLUA_API int olua_pushobjstub(lua_State *L, void *obj, void *stub, const char *cls)
{
    int status = OLUA_OBJ_EXIST;
    aux_pushobjtable(L);
    if (olua_rawgetp(L, -1, obj) == LUA_TUSERDATA) {
        // ref stub in obj
        lua_pushstring(L, OLUA_OBJSTUB);
        olua_rawgetp(L, -3, stub);
        olua_setvariable(L, -3); // obj[.stub] = stub
        // stub point to obj
        lua_pushvalue(L, -1);
        olua_rawsetp(L, -3, stub); // objtable[stub] = obj
    } else if (olua_rawgetp(L, -2, stub) == LUA_TUSERDATA) {
        // L: nil stub
        lua_remove(L, -2); // remove nil
        olua_setmetatable(L, cls);
        olua_setrawobj(L, -1, obj);
        lua_pushvalue(L, -1);
        olua_rawsetp(L, -3, obj); // objtable[obj] = stub
        status = OLUA_OBJ_NEW;
    } else {
        luaL_error(L, "stub object not found for '%s'", cls);
    }
    lua_replace(L, -2);
    return status;
}

static void aux_pushlocalobj(lua_State *L, void *obj)
{
    olua_VMEnv *mt = aux_getvmenv(L);
    if (olua_unlikely(registry_rawgetf(L, OLUA_POOLTABLE) != LUA_TTABLE)) {
        lua_pop(L, 1);
        lua_createtable(L, 16, 0);
        lua_pushvalue(L, -1);
        registry_rawsetf(L, OLUA_POOLTABLE);
    }
    
    if (olua_unlikely(olua_rawgeti(L, -1, ++mt->poolsize) != LUA_TUSERDATA)) {
        lua_pop(L, 1);
        lua_newuserdata(L, sizeof(void *));
        lua_pushvalue(L, -1);
        olua_rawseti(L, -3, mt->poolsize);
    }
    
    lua_replace(L, -2);  // rm pool table
    olua_setrawobj(L, -1, obj);
}

OLUA_API int olua_pushobj(lua_State *L, void *obj, const char *cls)
{
    int status = OLUA_OBJ_EXIST;
    
    if (olua_unlikely(!obj)) {
        lua_pushnil(L);
        return status;
    }
    
    if (olua_unlikely(!cls || olua_getmetatable(L, cls) != LUA_TTABLE)) {
        luaL_error(L, "class metatable '%s' not found", cls ? cls : "NULL");
    }
    
    aux_pushobjtable(L);
    
    if (olua_likely(olua_rawgetp(L, -1, obj) == LUA_TNIL)) {
        olua_VMEnv *env = aux_getvmenv(L);
        lua_pop(L, 1);
        if (olua_unlikely(env->poolenabled)) {
            aux_pushlocalobj(L, obj);
            status = OLUA_OBJ_EXIST;
        } else {
            olua_newrawobj(L, obj);
            lua_pushvalue(L, -1);
            // L: metaclass objtable obj obj
            olua_rawsetp(L, -3, obj); // objtable[obj] = obj
            status = OLUA_OBJ_NEW;
            env->objcount++;
        }
        // L: metaclass objtable obj
        lua_pushvalue(L, -3);
        lua_setmetatable(L, -2); // obj.metatable = metaclass
    } else if (olua_unlikely(!strequal(cls, OLUA_VOIDCLS)
            && luaL_testudata(L, -1, OLUA_VOIDCLS))) {
        // L: metaclass objtable obj
        lua_pushvalue(L, -3);
        lua_setmetatable(L, -2); // obj.metatable = metaclass
        status = OLUA_OBJ_UPDATE;
    }
    lua_copy(L, -1, -3);
    // L: obj objtable obj
    lua_pop(L, 2);
    
    return status;
}

OLUA_API bool olua_getrawobj(lua_State *L, void *obj)
{
    if (!obj) {
        return false;
    }
    aux_pushobjtable(L);
    if (olua_rawgetp(L, -1, obj) == LUA_TUSERDATA) {
        lua_replace(L, -2);
        return true;
    } else {
        lua_pop(L, 2);
        return false;
    }
}

static void *aux_toobj(lua_State *L, int idx, const char *cls, bool checked)
{
    if (olua_likely(checked ? olua_isa(L, idx, cls) : olua_isuserdata(L, idx))) {
        void *obj = olua_torawobj(L, idx);
        if (olua_unlikely(!obj)) {
            luaL_error(L, "object '%s' survive from gc", olua_typename(L, idx));
        }
        return obj;
    } else {
        luaL_error(L, "#%d argument error, expect: '%s', got '%s'", idx,
            cls, olua_typename(L, idx));
    }
    return NULL;
}

OLUA_API void *olua_checkobj(lua_State *L, int idx, const char *cls)
{
    return aux_toobj(L, idx, cls, true);
}

OLUA_API void *olua_toobj(lua_State *L, int idx, const char *cls)
{
#if OLUA_DEBUG
    return aux_toobj(L, idx, cls, true);
#else
    return aux_toobj(L, idx, cls, false);
#endif
}

OLUA_API const char *olua_objstring(lua_State *L, int idx)
{
    const void *ud = lua_topointer(L, idx);
    const void *obj = ud;
    if (olua_isuserdata(L, idx)) {
        obj = olua_torawobj(L, idx);
    }
    if (aux_getvmenv(L)->debug) {
        return lua_pushfstring(L, "%s: %p(%p)", olua_typename(L, idx), obj, ud);
    } else {
        return lua_pushfstring(L, "%s: %p", olua_typename(L, idx), obj);
    }
}

OLUA_API int olua_indexerror(lua_State *L)
{
    const char *cls = olua_checkfieldstring(L, 1, "classname");
    const char *field = olua_tostring(L, 2);
    luaL_error(L, "index '%s.%s' error", cls, field);
    return 0;
}

OLUA_API int olua_newindexerror(lua_State *L)
{
    const char *cls = olua_checkfieldstring(L, 1, "classname");
    const char *field = olua_tostring(L, 2);
    luaL_error(L, "newindex '%s.%s' error", cls, field);
    return 0;
}

OLUA_API void olua_setownership(lua_State *L, int idx, int owner)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, OLUA_OWNERSHIP);
    lua_pushinteger(L, owner);
    olua_setvariable(L, idx); // obj[.olua.ownership] = owner
}

OLUA_API int olua_getownership(lua_State *L, int idx)
{
    int owner = OLUA_OWNERSHIP_NONE;
    idx = lua_absindex(L, idx);
    lua_pushstring(L, OLUA_OWNERSHIP);
    if (olua_getvariable(L, idx) == LUA_TNUMBER) {
        owner = (int)olua_tointeger(L, -1);
    }
    lua_pop(L, 1);
    return owner;
}

OLUA_API void olua_enable_objpool(lua_State *L)
{
    aux_getvmenv(L)->poolenabled = true;
}

OLUA_API void olua_disable_objpool(lua_State *L)
{
    aux_getvmenv(L)->poolenabled = false;
}

OLUA_API size_t olua_push_objpool(lua_State *L)
{
    return aux_getvmenv(L)->poolsize;
}

OLUA_API void olua_pop_objpool(lua_State *L, size_t position)
{
    if (olua_likely(registry_rawgetf(L, OLUA_POOLTABLE) == LUA_TTABLE)) {
        size_t len = (size_t)lua_rawlen(L, -1);
        olua_assert(position <= len, "invalid position");
        aux_getvmenv(L)->poolsize = position;
        for (size_t i = position + 1; i <= len; i++) {
            olua_rawgeti(L, -1, (lua_Integer)i);
            void **ud = (void **)lua_touserdata(L, -1);
            lua_pushnil(L);
            lua_setmetatable(L, -2);    // remove metatable
            lua_pushnil(L);
            lua_setuservalue(L, -2);    // remove user value
            lua_pop(L, 1);
            if (olua_likely(*ud != NULL)) {
                *ud = NULL;
            } else {
                break;
            }
        }
    }
    lua_pop(L, 1);
}

static void aux_getusertable(lua_State *L, int idx)
{
    if (olua_unlikely(lua_getuservalue(L, idx) != LUA_TTABLE)) {
        olua_assert(olua_isnil(L, -1), "expect nil");
        lua_pop(L, 1);
        idx = lua_absindex(L, idx);
        lua_createtable(L, 0, 4);
        lua_pushvalue(L, -1);
        lua_setuservalue(L, idx);
    }
}

static bool test_tag_mode(lua_State *L, int idx, const char *tag, int mode)
{
    if (olua_isstring(L, idx)) {
        const char *field = olua_tostring(L, idx);
        if ((field = strchr(field, '@')) != NULL) {
            ++field; // skip '@'
            if (mode == OLUA_TAG_STARTWITH) {
                return strstartwith(field, tag);
            } else if (mode == OLUA_TAG_EQUAL || mode == OLUA_TAG_REPLACE) {
                return strequal(field, tag);
            }
        }
    }
    return false;
}

OLUA_API const char *olua_setcallback(lua_State *L, void *obj, int func, const char *tag, int tagmode)
{
    const char *cb = NULL;
    func = lua_absindex(L, func);
    luaL_checktype(L, func, LUA_TFUNCTION);
    
    if (!olua_getrawobj(L, obj)) {
        luaL_error(L, "obj userdata not found");
    }
    
    aux_getusertable(L, -1);
    
    if (tagmode == OLUA_TAG_REPLACE) {
        lua_pushnil(L);
        while (lua_next(L, -2)) {
            // L: obj usertable k v
            if (test_tag_mode(L, -2, tag, tagmode)) {
                cb = olua_tostring(L, -2);
                lua_pop(L, 1);
                break;
            }
            lua_pop(L, 1);
        }
    }
    
    if (cb == NULL) {
        const char *cls = olua_checkfieldstring(L, -2, "classname");
        olua_VMEnv *env = aux_getvmenv(L);
        while (true) {
            char refstr[64];
            int64_t ref = obtainref(env);
            snprintf(refstr, sizeof(refstr), "%"PRId64, ref);
            cb = aux_pushcbkey(L, refstr, cls, tag);
            lua_pushvalue(L, -1);
            // L: obj usertable fn fn
            if (olua_rawget(L, -3) == LUA_TNIL) {
                lua_pop(L, 1);
                break;
            } else {
                lua_pop(L, 2);
            }
        }
    }
    lua_pushvalue(L, func);
    // L: obj usertable fn func
    lua_rawset(L, -3); // usertable[fn] = func
    // L: obj usertable
    lua_pop(L, 2);
    return cb;
}

OLUA_API int olua_getcallback(lua_State *L, void *obj, const char *tag, int tagmode)
{
    if (!olua_getrawobj(L, obj)) {
        lua_pushnil(L);
        return LUA_TNIL;
    }
    
    aux_getusertable(L, -1);
    
    if (tagmode == OLUA_TAG_WHOLE) {
        olua_rawgetf(L, -1, tag);
    } else {
        lua_pushnil(L);
        lua_pushnil(L);
        while (lua_next(L, -3)) {
            // L: obj usertable nil fn func
            if (test_tag_mode(L, -2, tag, tagmode)) {
                lua_replace(L, -3);
                lua_pop(L, 1);
                break;
            }
            lua_pop(L, 1);
        }
    }
    // L: obj usertable func
    lua_insert(L, -3);
    lua_pop(L, 2);
    return lua_type(L, -1);
}

OLUA_API void olua_removecallback(lua_State *L, void *obj, const char *tag, int tagmode)
{
    if (!olua_getrawobj(L, obj)) {
        return;
    }
    aux_getusertable(L, -1);
    if (tagmode == OLUA_TAG_WHOLE) {
        lua_pushnil(L);
        olua_rawsetf(L, -2, tag); // usertable[tag] = nil
    } else {
        lua_pushnil(L);
        while (lua_next(L, -2)) {
            if (test_tag_mode(L, -2, tag, tagmode)) {
                lua_pushvalue(L, -2);
                lua_pushnil(L);
                // L: obj usertable fn func fn nil
                lua_rawset(L, -5); // usertable[fn] = nil
            }
            // L: obj usertable fn fun
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 2); // pop obj usertable
}

OLUA_API int olua_callback(lua_State *L, void *obj, const char *func, int argc)
{
    int top = lua_gettop(L) - argc + 1;
    int status = LUA_ERRRUN;
    olua_pusherrorfunc(L);
    if (olua_getcallback(L, obj, func, OLUA_TAG_WHOLE) == LUA_TFUNCTION) {
        for (int i = 0; i < argc; i++) {
            // L: ...arg errfunc func ...arg
            lua_pushvalue(L, -(2 + argc));
        }
        status = lua_pcall(L, argc, 1, -(2 + argc));
    } else {
        lua_pop(L, 1);
        if (olua_getrawobj(L, obj)) {
            lua_pop(L, 1);
            lua_pushfstring(L, "callback missed: %s", func);
        } else {
            lua_pushfstring(L, "object missed: %s", func);
        }
        lua_pcall(L, 1, 0, 0); // call error func
    }
    if (status != LUA_OK) {
        lua_pushnil(L);
    }
    lua_replace(L, top);
    lua_settop(L, top);
    return status;
}

OLUA_API void *olua_pushclassobj(lua_State *L, const char *cls)
{
    olua_getmetatable(L, cls);
    olua_rawgetf(L, -1, OLUA_CKEY_CLSOBJ); // metaclass[.classobj]
    lua_replace(L, -2); // pop metaclass
    olua_assert(olua_isuserdata(L, -1), "expect userdata");
    return lua_touserdata(L, -1);
}

OLUA_API bool olua_getclass(lua_State *L, const char *cls)
{
    if (olua_getmetatable(L, cls) == LUA_TTABLE) {
        olua_rawgetf(L, -1, OLUA_CKEY_CLASS); // metaclass[.class]
        lua_replace(L, -2); // pop metaclass
        return true;
    } else {
        lua_pop(L, 1);
        return false;
    }
}

OLUA_API int olua_getvariable(lua_State *L, int idx)
{
    int type = LUA_TNIL;
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    if (lua_getuservalue(L, idx) == LUA_TTABLE) {
        lua_insert(L, -2);
        type = olua_gettable(L, -2); // uservalue[k]
        lua_replace(L, -2); // pop uservalue
    } else {
        lua_pop(L, 2); // pop k uservalue
        lua_pushnil(L);
    }
    return type;
}

OLUA_API void olua_setvariable(lua_State *L, int idx)
{
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    aux_getusertable(L, idx);
    lua_insert(L, -3);
    // L: obj uservalue k v
    olua_settable(L, -3); // uservalue[k] = v
    lua_pop(L, 1); // pop uservalue
}

static void aux_pushluareftable(lua_State *L)
{
    if (registry_rawgetf(L, OLUA_LUAREFTABLE) != LUA_TTABLE) {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_pushvalue(L, -1);
        registry_rawsetf(L, OLUA_LUAREFTABLE);
    }
}

OLUA_API olua_Ref olua_ref(lua_State *L, int idx, int type)
{
    if (type != LUA_TANY) {
        luaL_checktype(L, idx, type);
    }
    if (!olua_isnil(L, idx)) {
        olua_VMEnv *env = aux_getvmenv(L);
        int64_t ref = obtainref(env);
        idx = lua_absindex(L, idx);
        aux_pushluareftable(L);
        // find a valid ref slot
        while (olua_rawgeti(L, -1, ref) != LUA_TNIL) {
            lua_pop(L, 1);
            ref = obtainref(env);
        }
        lua_pushvalue(L, idx);
        lua_rawseti(L, -3, ref); // refable[ref] = value
        lua_pop(L, 2); // pop reftable nil
        return ref;
    }
    return LUA_REFNIL;
}

OLUA_API void olua_unref(lua_State *L, olua_Ref ref)
{
    aux_pushluareftable(L);
    lua_pushnil(L);
    lua_rawseti(L, -2, ref); // reftable[ref] = nil
    lua_pop(L, 1);
}

OLUA_API void olua_getref(lua_State *L, olua_Ref ref)
{
    aux_pushluareftable(L);
    lua_rawgeti(L, -1, ref);
    lua_replace(L, -2);
}

OLUA_API int olua_loadref(lua_State *L, int idx, const char *name)
{
    int type;
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    aux_getusertable(L, idx);
    aux_pushrefkey(L, name);
    type = olua_rawget(L, -2);
    lua_replace(L, -2); // replace usertable
    return type;
}

static void aux_getreftable(lua_State *L, int idx, const char *name)
{
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    aux_getusertable(L, idx);
    name = aux_pushrefkey(L, name);
    luaL_getsubtable(L, -2, name);
    // L: usertable name reftable
    lua_insert(L, -3);
    // L: reftable name usertable
    lua_pop(L, 2); // pop name usertable
}

static void aux_changeref(lua_State *L, int idx, const char *name, int obj, int flags)
{
    int top = lua_gettop(L);
    if (idx == OLUA_NOREFSTORE) {
        return;
    }
    idx = lua_absindex(L, idx);
    obj = lua_absindex(L, obj);
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    if (flags & OLUA_FLAG_REMOVE) {
        lua_pushnil(L);
    } else if (flags & OLUA_FLAG_SINGLE) {
        olua_assert(olua_isuserdata(L, obj) || olua_isnil(L, obj), "expect userdata or nil");
        lua_pushvalue(L, obj);
    } else {
        lua_pushboolean(L, true);
    }
    if (flags & OLUA_FLAG_SINGLE) {
        aux_getusertable(L, idx);
        aux_pushrefkey(L, name);
        lua_pushvalue(L, top + 1);
        // L: usertable name obj|nil
        lua_rawset(L, -3); // L: usertable[name] = obj|nil
    } else if (flags & OLUA_FLAG_MULTIPLE) {
        if (olua_isnil(L, obj)) {
            lua_settop(L, top);
            return;
        }
        if (flags & OLUA_FLAG_TABLE) {
            olua_assert(olua_istable(L, obj), "expect table");
            aux_getreftable(L, idx, name);
            lua_pushnil(L);
            while (lua_next(L, obj)) {
                if (olua_isuserdata(L, -2)) {
                    lua_pushvalue(L, -2);
                    lua_pushvalue(L, top + 1);
                    // L: reftable obj value obj true|nil
                    lua_rawset(L, -5); // L: reftable[obj] = true|nil
                }
                if (olua_isuserdata(L, -1)) {
                    lua_pushvalue(L, -1);
                    lua_pushvalue(L, top + 1);
                    // L: reftable name obj obj true|nil
                    lua_rawset(L, -5); // L: reftable[obj] = true|nil
                }
                lua_pop(L, 1);
            }
        } else {
            olua_assert(olua_isuserdata(L, obj), "expect userdata");
            aux_getreftable(L, idx, name);
            lua_pushvalue(L, obj);
            lua_pushvalue(L, top + 1);
            // L: reftable obj obj|nil
            lua_rawset(L, -3); // L: reftable[obj] = true|nil
        }
    }
    lua_settop(L, top);
}

OLUA_API void olua_addref(lua_State *L, int idx, const char *name, int obj, int flags)
{
    aux_changeref(L, idx, name, obj, flags);
}

OLUA_API void olua_delref(lua_State *L, int idx, const char *name, int obj, int flags)
{
    aux_changeref(L, idx, name, obj, flags | OLUA_FLAG_REMOVE);
}

OLUA_API void olua_delallrefs(lua_State *L, int idx, const char *name)
{
    aux_changeref(L, idx, name, 0, OLUA_FLAG_SINGLE | OLUA_FLAG_REMOVE);
}

OLUA_API void olua_visitrefs(lua_State *L, int idx, const char *name, olua_RefVisitor walk)
{
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    idx = lua_absindex(L, idx);
    if (olua_loadref(L, idx, name) == LUA_TTABLE) {
        lua_pushnil(L);
        while (lua_next(L, -2)) {
            int kidx = lua_gettop(L) - 1;
            if (walk(L, -2)) { // remove?
                lua_pushvalue(L, kidx);
                lua_pushnil(L);
                lua_rawset(L, kidx - 1);
            }
            lua_settop(L, kidx);
        }
    }
    lua_pop(L, 1);
}

static bool lookupfunc(lua_State *L, int t, int kidx)
{
    int type;
    olua_assert(t < LUA_REGISTRYINDEX && kidx > 0, "invalid index");
    lua_pushvalue(L, kidx);
    type = olua_rawget(L, t);
    if (olua_unlikely(type == LUA_TNIL)) {
        lua_pop(L, 1);
        lua_pushvalue(L, kidx);
        type = olua_gettable(L, t); // it will index super table
        if (olua_unlikely(type == LUA_TNIL)) {
            lua_copy(L, kidx, -1);
            lua_pushlightuserdata(L, NULL);
        } else {
            lua_pushvalue(L, kidx);
            lua_pushvalue(L, -2);
        }
        // type == LUA_TNIL   L: k NULL
        // type ~= LUA_TNIL   L: v k v
        lua_rawset(L, t); // cache in current table
    }
    if (type == LUA_TLIGHTUSERDATA && lua_touserdata(L, -1) == NULL) {
        lua_pop(L, 1);
        type = LUA_TNIL;
    }
    return type != LUA_TNIL;
}

static bool lookup_user_index_func(lua_State *L, const char *name)
{
    int type = lua_type(L, OLUA_CIDX_USER);
    if (type == LUA_TNIL) {
        lua_pushstring(L, name);
        if (lookupfunc(L, OLUA_CIDX_FUNC, lua_gettop(L))) {
            type = LUA_TFUNCTION;
        }
        lua_copy(L, -1, OLUA_CIDX_USER); // upvalue = func or name
        if (type == LUA_TFUNCTION) {
            lua_replace(L, -2); // remove name
        } else {
            lua_pop(L, 1); // remove name
        }
    } else if (type == LUA_TFUNCTION) {
        lua_pushvalue(L, OLUA_CIDX_USER);
    }
    return type == LUA_TFUNCTION;
}

static int cls_metamethod(lua_State *L)
{
    // 1: funcs   2: name   3: isgc
    bool isgc = olua_toboolean(L, lua_upvalueindex(3));
    lua_pushvalue(L, lua_upvalueindex(2));
    if (lookupfunc(L, lua_upvalueindex(1), lua_gettop(L))) {
        lua_replace(L, -2);
        lua_insert(L, 1);
        if (!isgc) {
            lua_call(L, lua_gettop(L) - 1, LUA_MULTRET);
            return lua_gettop(L);
        } else if (olua_isuserdata(L, 2)) {
            if (olua_getownership(L, 2) == OLUA_OWNERSHIP_ALIAS) {
                if (olua_isdebug(L)) {
                    printf("skip gc for alias object: %s\n", olua_objstring(L, 2));
                }
                return 0;
            }
            if (olua_isa(L, 2, OLUA_VOIDCLS)) {
                aux_getvmenv(L)->objcount--;
            }
            olua_pusherrorfunc(L);
            lua_insert(L, 1);
            lua_pcall(L, lua_gettop(L) - 2, LUA_MULTRET, 1);
            return lua_gettop(L) - 1;
        } else {
            // unnecessary call __gc on class table
            return 0;
        }
    } else if (!isgc) {
        luaL_error(L, "meta method '%s' not found for '%s'",
            olua_checkstring(L, lua_upvalueindex(2)), olua_objstring(L, 1));
    }
    return 0;
}

static int cls_index(lua_State *L)
{
    // try getter
    if (olua_likely(lookupfunc(L, OLUA_CIDX_GET, 2))) {
        lua_pushvalue(L, 1);
        lua_call(L, 1, 1);
        return 1;
    }
    
    // try func
    if (olua_likely(lookupfunc(L, OLUA_CIDX_FUNC, 2))) {
        return 1;
    }
    
    // try user index
    if (olua_unlikely(lookup_user_index_func(L, "__index"))) {
        // try user's index
        lua_pushvalue(L, 1);
        lua_pushvalue(L, 2);
        lua_call(L, 2, 1);
        return 1;
    }
    
    // try uservalue
    if (olua_likely(olua_isuserdata(L, 1))) {
        // try variable
        lua_pushvalue(L, 2);
        olua_getvariable(L, 1);
        return 1;
    }
    
    return 0;
}

static int cls_newindex(lua_State *L)
{
    int type = lua_type(L, 1);
    
    // try setter
    if (olua_likely(lookupfunc(L, OLUA_CIDX_SET, 2))) {
        if (olua_likely(type == LUA_TUSERDATA)) {
            lua_pushvalue(L, 1);
            lua_pushvalue(L, 3);
            lua_call(L, 2, 0);
        } else {
            // static setter, accessed from class
            lua_pushvalue(L, 3);
            lua_call(L, 1, 0);
        }
        return 0;
    }
    
    // store value in .func table
    if (olua_unlikely(type == LUA_TTABLE)) {
        lua_settop(L, 3);
        lua_rawset(L, OLUA_CIDX_FUNC);
        return 0;
    }
    
    // try user newindex
    if (olua_unlikely(lookup_user_index_func(L, "__newindex"))) {
        // try user's newindex
        lua_pushvalue(L, 1);
        lua_pushvalue(L, 2);
        lua_pushvalue(L, 3);
        lua_call(L, 3, 0);
        return 0;
    }
    
    // store value in uservalue
    if (olua_likely(type == LUA_TUSERDATA)) {
        // try variable
        lua_settop(L, 3);
        olua_setvariable(L, 1);
        return 0;
    }
    
    return 0;
}

static int cls_tostring(lua_State *L)
{
    olua_objstring(L, 1);
    return 1;
}

static int cls_eq(lua_State *L)
{
    return 0;
}

static int cls_readonly(lua_State *L)
{
    lua_pushvalue(L, lua_upvalueindex(1));
    luaL_error(L, "readonly property: %s", olua_tostring(L, -1));
    return 0;
}

static int cls_const(lua_State *L)
{
    lua_pushvalue(L, lua_upvalueindex(1));
    return 1;
}

static void index_super(lua_State *L, int metaclass, const char *field, int super)
{
    olua_assert(metaclass > 0 && super > 0, "invalid index");
    lua_newtable(L); // new table(.get|.set|.isa|.func)
    if (olua_istable(L, super)) {
        // setmetatable(table, {__index = super_table})
        olua_rawgetf(L, super, field);
        lua_createtable(L, 0, 1);
        lua_pushvalue(L, -2);
        olua_rawsetf(L, -2, "__index");
        lua_setmetatable(L, -3);
        if (strequal(field, OLUA_CKEY_ISA)) {
            // copy super .isa
            lua_pushnil(L);
            while (lua_next(L, -2)) {
                lua_pushvalue(L, -2);
                lua_insert(L, -2);
                // L: table super_table k k v
                lua_rawset(L, -5); // table[k] = v
            }
        }
        lua_pop(L, 1); // pop super_table
    }
    lua_pushvalue(L, -1);
    olua_rawsetf(L, metaclass, field); // metaclass[field] = table
}

OLUA_API void oluacls_class(lua_State *L, const char *cls, const char *supercls)
{
    int super = lua_gettop(L) + 1;
    if (!supercls && !strequal(cls, OLUA_VOIDCLS)) {
        supercls = OLUA_VOIDCLS;
    }
    if (!supercls) {
        lua_pushnil(L);
    } else if (olua_getmetatable(L, supercls) != LUA_TTABLE) {
        if (strequal(supercls, OLUA_VOIDCLS)) {
            luaL_requiref(L, "olua", luaopen_olua, 1); // init olua lib api
            oluacls_class(L, OLUA_VOIDCLS, NULL);
            oluacls_func(L, "__eq", cls_eq);
            oluacls_func(L, "__tostring", cls_tostring);
            lua_getmetatable(L, -1);
            // L: nil olua voidclass voidmeta
            lua_insert(L, -4);
            // L: voidmeta, nil olua voidclass
            lua_pop(L, 3); // pop nil, olua and class
        } else {
            luaL_error(L, "super class not found: %s => %s", cls, supercls);
        }
    }
    
    if (olua_getmetatable(L, cls) != LUA_TTABLE) {
        static const luaL_Reg lib[] = {
            {"__index", cls_index},
            {"__newindex", cls_newindex},
            {NULL, NULL}
        };
        static const char *events[] = {
            "__gc", "__len", "__eq", "__tostring",
            "__add", "__sub", "__mul", "__mod", "__pow",
            "__div", "__idiv",
            "__band", "__bor", "__bxor", "__shl", "__shr",
            "__unm", "__bnot", "__lt", "__le",
            "__concat", "__call", "__close", NULL
        };
        
        int metaclass = lua_gettop(L);
        lua_pop(L, 1);
        luaL_newmetatable(L, cls);
        index_super(L, metaclass, OLUA_CKEY_ISA, super);
        index_super(L, metaclass, OLUA_CKEY_FUNC, super);
        index_super(L, metaclass, OLUA_CKEY_GET, super);
        index_super(L, metaclass, OLUA_CKEY_SET, super);
        lua_pushnil(L);
        // L: metaclass .isa .func .get .set index|newindex
        luaL_setfuncs(L, lib,  OLUA_CIDX_TOTAL);
        
        // init meta method and isa
        olua_rawgetf(L, metaclass, OLUA_CKEY_FUNC);
        // L: metaclass .func
        for (const char **e = events; *e != NULL; e++) {
            lua_pushvalue(L, -1);
            lua_pushstring(L, *e);
            lua_pushboolean(L, strequal(*e, "__gc"));
            // set .func e isgc as cls_metamethod upvalue
            lua_pushcclosure(L, cls_metamethod, 3);
            // L: metaclass .func metamethod
            olua_rawsetf(L, -3, *e); // metaclass[e] = metamethod
        }
        olua_rawgetf(L, metaclass, OLUA_CKEY_ISA); // metaclass[.isa]
        // L: metaclass .func .isa
        olua_setfieldboolean(L, -1, cls, true); //.isa[cls] = true
        lua_pop(L, 2); // pop .func .isa
        
        // create class object, store static function callback
        aux_pushobjtable(L);
        lua_newuserdata(L, sizeof(void *)); // create clsobj
        lua_createtable(L, 0, 1);   // create metatable
        lua_pushvalue(L, -1);
        // L: metaclass objtable clsobj metatable metatable
        olua_rawsetf(L, -2, "__index"); // metatable.__index = metatable
        olua_setfieldstring(L, -1, "classname", cls);
        lua_setmetatable(L, -2); // clsobj.metatable = metatable
        lua_pushvalue(L, -1);
        // L: metaclass objtable clsobj clsobj
        olua_rawsetf(L, metaclass, OLUA_CKEY_CLSOBJ); // metaclass[.classobj] = clsobj
        olua_rawsetp(L, -2, lua_touserdata(L, -1)); // objtable[objptr] = clsobj
        lua_pop(L, 1); // pop objtable
        
        // create class
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, metaclass);
        // L: .metaclass class .metaclass
        lua_setmetatable(L, -2);  // class.metatable = metaclass
        oluacls_const_value(L, "class", -1); // class.class = class
        oluacls_const_string(L, "classname", cls); // class.classname = cls
        oluacls_const_string(L, "classtype", "native"); // class.classtype = native
        // const value from metaclass: class[k] = metaclass[k]
        const_from_metaclass(L, ".classobj", metaclass);
        const_from_metaclass(L, ".isa", metaclass);
        const_from_metaclass(L, ".func", metaclass);
        const_from_metaclass(L, ".get", metaclass);
        const_from_metaclass(L, ".set", metaclass);
        
        if (supercls) {
            olua_rawgetf(L, super, OLUA_CKEY_CLASS);
            oluacls_const(L, "super"); // class.super = super
        }
        olua_rawsetf(L, metaclass, OLUA_CKEY_CLASS); // metaclass.class = class
    }
    olua_rawgetf(L, -1, OLUA_CKEY_CLASS);
    lua_replace(L, super);
    lua_settop(L, super);
}

static void aux_setfunc(lua_State *L, const char *t, const char *name, lua_CFunction func, int n)
{
    olua_assert(func, "function can't be NULL");
    // L: class func metaclass table(.get|.set)
    lua_pushcclosure(L, func, n);
    lua_getmetatable(L, -2); // get metaclass
    olua_rawgetf(L, -1, t); // get table(.get|.set|.func)
    // L: class func metaclass table(.get|.set|.func) func
    lua_pushvalue(L, -3);
    olua_rawsetf(L, -2, name); // table[name] = func
    // L: class func metaclass table(.get|.set|.func)
    lua_pop(L, 3); // pop func metaclass table
}

OLUA_API void oluacls_prop(lua_State *L, const char *name, lua_CFunction getter, lua_CFunction setter)
{
    aux_setfunc(L, OLUA_CKEY_GET, name, getter, 0);
    if (setter) {
        aux_setfunc(L, OLUA_CKEY_SET, name, setter, 0);
    } else {
        lua_pushstring(L, name);
        aux_setfunc(L, OLUA_CKEY_SET, name, cls_readonly, 1);
    }
}

OLUA_API void oluacls_func(lua_State *L, const char *name, lua_CFunction func)
{
    aux_setfunc(L, OLUA_CKEY_FUNC, name, func, 0);
}

OLUA_API void oluacls_const(lua_State *L, const char *name)
{
    int t = lua_type(L, -1);
    if (t == LUA_TNIL || t == LUA_TNONE) {
        luaL_error(L, "const nil value(%s)", name);
    }
    aux_setfunc(L, OLUA_CKEY_GET, name, cls_const, 1);
    lua_pushstring(L, name);
    aux_setfunc(L, OLUA_CKEY_SET, name, cls_readonly, 1);
}

static void aux_checkfield(lua_State *L, int t, const char *field, int type, bool isinteger)
{
    int idx = lua_gettop(L) + 1;
    lua_getfield(L, t, field);
    
    if ((isinteger && !olua_isinteger(L, idx)) ||
        (!isinteger && lua_type(L, idx) != type)) {
        const char *msg, *typearg;
        const char *tname = lua_typename(L, type);
        if (isinteger) {
            tname = "integer";
        }
        if (luaL_getmetafield(L, idx, "__name") == LUA_TSTRING) {
            typearg = olua_tostring(L, -1);
        } else if (olua_islightuserdata(L, idx)) {
            typearg = "light userdata";
        } else {
            typearg = luaL_typename(L, idx);
        }
        msg = lua_pushfstring(L, "check '%s': %s expected, got %s", field, tname, typearg);
        luaL_argerror(L, t, msg);
    }
}

OLUA_API const char *olua_checkfieldstring(lua_State *L, int idx, const char *field)
{
    const char *value;
    aux_checkfield(L, idx, field, LUA_TSTRING, false);
    value = olua_tostring(L, -1);
    lua_pop(L, 1);
    return value;
}

OLUA_API lua_Number olua_checkfieldnumber(lua_State *L, int idx, const char *field)
{
    lua_Number value;
    aux_checkfield(L, idx, field, LUA_TNUMBER, false);
    value = olua_tonumber(L, -1);
    lua_pop(L, 1);
    return value;
}

OLUA_API lua_Integer olua_checkfieldinteger(lua_State *L, int idx, const char *field)
{
    lua_Integer value;
    aux_checkfield(L, idx, field, LUA_TNUMBER, true);
    value = olua_tointeger(L, -1);
    lua_pop(L, 1);
    return value;
}

OLUA_API bool olua_checkfieldboolean(lua_State *L, int idx, const char *field)
{
    bool value;
    aux_checkfield(L, idx, field, LUA_TBOOLEAN, false);
    value = olua_toboolean(L, -1);
    lua_pop(L, 1);
    return value;
}

OLUA_API void olua_setfieldnumber(lua_State *L, int idx, const char *field, lua_Number value)
{
    idx = lua_absindex(L, idx);
    lua_pushnumber(L, value);
    lua_setfield(L, idx, field);
}

OLUA_API void olua_setfieldinteger(lua_State *L, int idx, const char *field, lua_Integer value)
{
    idx = lua_absindex(L, idx);
    lua_pushinteger(L, value);
    lua_setfield(L, idx, field);
}

OLUA_API void olua_setfieldstring(lua_State *L, int idx, const char *field, const char *value)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, value);
    lua_setfield(L, idx, field);
}

OLUA_API void olua_setfieldboolean(lua_State *L, int idx, const char *field, bool value)
{
    idx = lua_absindex(L, idx);
    lua_pushboolean(L, value);
    lua_setfield(L, idx, field);
}

OLUA_API const char *olua_optfieldstring(lua_State *L, int idx, const char *field, const char *def)
{
    lua_getfield(L, idx, field);
    def = olua_optstring(L, -1, def);
    lua_pop(L, 1);
    return def;
}

OLUA_API lua_Number olua_optfieldnumber(lua_State *L, int idx, const char *field, lua_Number def)
{
    lua_getfield(L, idx, field);
    def = olua_optnumber(L, -1, def);
    lua_pop(L, 1);
    return def;
}

OLUA_API lua_Integer olua_optfieldinteger(lua_State *L, int idx, const char *field, lua_Integer def)
{
    lua_getfield(L, idx, field);
    def = olua_optinteger(L, -1, def);
    lua_pop(L, 1);
    return def;
}

OLUA_API bool olua_optfieldboolean(lua_State *L, int idx, const char *field, bool def)
{
    lua_getfield(L, idx, field);
    def = olua_optboolean(L, -1, def);
    lua_pop(L, 1);
    return def;
}

OLUA_API bool olua_hasfield(lua_State *L, int idx, const char *field)
{
    int type = olua_getfield(L, idx, field);
    lua_pop(L, 1);
    return type != LUA_TNIL;
}

static int l_with(lua_State *L)
{
    const char *cls;
    lua_settop(L, 3);
    luaL_checktype(L, 1, LUA_TUSERDATA);
    luaL_checktype(L, 3, LUA_TFUNCTION);
    cls = olua_checkstring(L, 2);
    if (!lua_getmetatable(L, 1)) { // backup metatable
        lua_pushnil(L);
    }
    if (olua_getmetatable(L, cls) == LUA_TTABLE) {
        lua_setmetatable(L, 1); // set new metatable
    } else {
        luaL_error(L, "metatable not found: %s", cls);
    }
    lua_pushvalue(L, 3); // push func
    lua_pushvalue(L, 1); // push obj
    // L: obj cls func metaclass func obj
    olua_pcall(L, 1, 0); // func(obj)
    lua_setmetatable(L, 1); // restore metatable
    return 0;
}

static int l_isa(lua_State *L)
{
    lua_pushboolean(L, olua_isa(L, 1, olua_checkstring(L, 2)));
    return 1;
}

static int l_take(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TUSERDATA);
    olua_setownership(L, 1, OLUA_OWNERSHIP_NONE);
    return 0;
}

static int l_move(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TUSERDATA);
    lua_getfield(L, 1, "__olua_move");
    if (!olua_isfunction(L, -1)) {
        luaL_error(L, "method '__olua_move' not found in '%s'", olua_objstring(L, 1));
    }
    lua_insert(L, 1);
    // maybe move object from object pool to the object table
    lua_call(L, lua_gettop(L) - 1, LUA_MULTRET);
    return lua_gettop(L);
}

static int l_debug(lua_State *L)
{
    if (olua_isnil(L, 1)) {
        lua_pushboolean(L, aux_getvmenv(L)->debug);
        return 1;
    } else {
        aux_getvmenv(L)->debug = olua_checkboolean(L, 1);
        return 0;
    }
}

static int l_iscfunc(lua_State *L)
{
    lua_pushboolean(L, lua_iscfunction(L, 1));
    return 1;
}

static int l_class(lua_State *L)
{
    const char *cls = olua_checkstring(L, 1);
    const char *super;
    if (olua_istable(L, 2)) {
        super = olua_checkfieldstring(L, 2, "classname");
    } else {
        super = olua_optstring(L, 2, OLUA_VOIDCLS);
    }
    oluacls_class(L, cls, super);
    return 1;
}

static int l_setmetatable(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TUSERDATA);
    if (olua_getmetatable(L, olua_checkstring(L, 2)) == LUA_TTABLE) {
        lua_setmetatable(L, 1);
    } else {
        luaL_error(L, "metatable '%s' not found", olua_checkstring(L, 2));
    }
    return 0;
}

static int l_getmetatable(lua_State *L)
{
    olua_getmetatable(L, olua_checkstring(L, 1));
    return 1;
}

static int l_topointer(lua_State *L)
{
    lua_pushinteger(L, (lua_Integer)(uintptr_t)lua_topointer(L, 1));
    return 1;
}

static int l_objpool(lua_State *L)
{
    const char *action = olua_checkstring(L, 1);
    if (strequal(action, "enable")) {
        olua_enable_objpool(L);
    } else if strequal(action, "disable") {
        olua_disable_objpool(L);
    } else if strequal(action, "push") {
        size_t position = olua_push_objpool(L);
        lua_pushnumber(L, (lua_Integer)position);
        return 1;
    } else if strequal(action, "pop") {
        size_t position = (size_t)olua_checkinteger(L, 2);
        olua_pop_objpool(L, position);
    } else {
        luaL_error(L, "unknown action '%s'", action);
    }
    return 0;
}

OLUA_API int luaopen_olua(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"with", l_with},
        {"isa", l_isa},
        {"take", l_take},
        {"move", l_move},
        {"debug", l_debug},
        {"class", l_class},
        {"iscfunc", l_iscfunc},
        {"setmetatable", l_setmetatable},
        {"getmetatable", l_getmetatable},
        {"topointer", l_topointer},
        {"objpool", l_objpool},
        {NULL, NULL}
    };
    
    luaL_newlib(L,lib);
    
    return 1;
}

#if LUA_VERSION_NUM == 501

OLUA_API void lua_copy(lua_State *L, int fromidx, int toidx)
{
    toidx = lua_absindex(L, toidx);
    lua_pushvalue(L, fromidx);
    lua_replace(L, toidx);
}

OLUA_API void lua_setuservalue(lua_State *L, int idx)
{
    if (lua_type(L, -1) != LUA_TNIL) {
        luaL_checktype(L, -1, LUA_TTABLE);
    } else {
        lua_pop(L, 1);
        lua_pushvalue(L, LUA_GLOBALSINDEX);
    }
    lua_setfenv(L, idx);
}

OLUA_API int lua_getuservalue(lua_State *L, int idx)
{
    lua_getfenv(L, idx);
    if (lua_rawequal(L, -1, LUA_GLOBALSINDEX)) {
        lua_pop(L, 1);
        lua_pushnil(L);
        return LUA_TNIL;
    } else {
        return lua_type(L, -1);
    }
}

OLUA_API int lua_absindex(lua_State *L, int idx)
{
    return (idx > 0 || idx <= LUA_REGISTRYINDEX) ?
        idx : (idx + 1 + lua_gettop(L));
}

OLUA_API void luaL_setfuncs(lua_State *L, const luaL_Reg *l, int nup)
{
    luaL_checkstack(L, nup, "too many upvalues");
    for (; l->name != NULL; l++) {
        for (int i = 0; i < nup; i++) {
            lua_pushvalue(L, -nup);
        }
        lua_pushcclosure(L, l->func, nup);
        lua_setfield(L, -(nup + 2), l->name);
    }
    lua_pop(L, nup);
}

OLUA_API int luaL_getsubtable(lua_State *L, int idx, const char *fname) {
    if (olua_getfield(L, idx, fname) == LUA_TTABLE) {
        return 1;
    } else {
        lua_pop(L, 1);
        idx = lua_absindex(L, idx);
        lua_newtable(L);
        lua_pushvalue(L, -1);
        lua_setfield(L, idx, fname);
        return 0;
    }
}

OLUA_API void luaL_requiref(lua_State *L, const char *modname, lua_CFunction openf, int glb) {
    luaL_getsubtable(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
    lua_getfield(L, -1, modname);
    if (!lua_toboolean(L, -1)) {
        lua_pop(L, 1);
        lua_pushcfunction(L, openf);
        lua_pushstring(L, modname);
        lua_call(L, 1, 1);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, modname);
    }
    lua_remove(L, -2);
    if (glb) {
        lua_pushvalue(L, -1);
        lua_setglobal(L, modname);
    }
}

OLUA_API void *luaL_testudata(lua_State *L, int ud, const char *tname) {
    void *p = lua_touserdata(L, ud);
    if (p != NULL) {
        if (lua_getmetatable(L, ud)) {
            olua_getmetatable(L, tname);
            if (!lua_rawequal(L, -1, -2)) {
                p = NULL;
            }
            lua_pop(L, 2);
            return p;
        }
    }
    return NULL;
}

OLUA_API void luaL_traceback(lua_State *L, lua_State *L1, const char *msg, int level)
{
    lua_getglobal(L, "debug");
    lua_getfield(L, -1, "traceback");
    lua_remove(L, -2);
    if (L != L1) {
        lua_pushthread(L1);
        lua_xmove(L1, L, 1);
    }
    lua_pushstring(L, msg ? msg : "");
    lua_pushinteger(L, L != L1 ? level : (level + 1));
    lua_pcall(L, L != L1 ? 3 : 2, 1, 0);
    if (msg == NULL) {
        msg = lua_tostring(L, -1);
        if (msg[0] == '\n') {
            lua_pushstring(L, msg + 1);
            lua_remove(L, -2);
        }
    }
}

OLUA_API void olua_initcompat(lua_State *L)
{
    lua_pushthread(L);
    lua_rawseti(L, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    lua_rawseti(L, LUA_REGISTRYINDEX, LUA_RIDX_GLOBALS);
}

OLUA_API void olua_rawsetp(lua_State *L, int idx, const void *p)
{
    idx = lua_absindex(L, idx);
    lua_pushlightuserdata(L, (void *)p);
    lua_insert(L, -2);
    olua_rawset(L, idx);
}

OLUA_API int olua_rawgetp(lua_State *L, int idx, const void *p)
{
    idx = lua_absindex(L, idx);
    lua_pushlightuserdata(L, (void *)p);
    return olua_rawget(L, idx);
}
#endif

#ifndef OLUA_HAVE_CONTEXT
OLUA_API olua_Context olua_context(lua_State *L)
{
    return (olua_Context)aux_getvmenv(L)->ctxid;
}

OLUA_API bool olua_contextequal(lua_State *L, olua_Context ctx)
{
    return L != NULL && olua_context(L) == ctx;
}
#endif

#ifndef OLUA_HAVE_MAINTHREAD
OLUA_API lua_State *olua_mainthread(lua_State *L)
{
    lua_State *mt = NULL;
    if (L) {
        olua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
        luaL_checktype(L, -1, LUA_TTHREAD);
        mt = lua_tothread(L, -1);
        lua_pop(L, 1);
    } else {
        olua_assert(L, "main thread not found");
    }
    return mt;
}
#endif

#ifndef OLUA_HAVE_LUATYPE
static void format_cpptype(char *buf, const char *cpptype)
{
    /**
     *  if cpptype is equal to cls, it will cause metatable miss.
     *     REGISTRY[cls] = class metatable
     *     REGISTRY[cpptype] = cls
     */
    olua_assert((strlen(cpptype) < (OLUA_MAX_CPPTYPE - 10)), "cpp type is too long");
    snprintf(buf, OLUA_MAX_CPPTYPE, "olua:%s", cpptype);
}

OLUA_API void olua_registerluatype(lua_State *L, const char *cpptype, const char *cls)
{
    char newtype[OLUA_MAX_CPPTYPE];
    format_cpptype(newtype, cpptype);
    lua_pushstring(L, newtype);
    lua_pushstring(L, cls);
    lua_rawset(L, LUA_REGISTRYINDEX);
}

OLUA_API const char *olua_getluatype(lua_State *L, const char *cpptype)
{
    char newtype[OLUA_MAX_CPPTYPE];
    format_cpptype(newtype, cpptype);
    return olua_optfieldstring(L, LUA_REGISTRYINDEX, newtype, NULL);
}
#endif

OLUA_API int olua_push_obj(lua_State *L, void *obj, const char *cls)
{
    olua_pushobj(L, obj, cls);
    return 1;
}

OLUA_API void olua_check_obj(lua_State *L, int idx, void **obj, const char *cls)
{
    *obj = olua_checkobj(L, idx, cls);
}

OLUA_API void olua_to_obj(lua_State *L, int idx, void **obj, const char *cls)
{
    *obj = olua_toobj(L, idx, cls);
}

OLUA_API bool olua_is_obj(lua_State *L, int idx, const char *cls)
{
    return olua_isa(L, idx, cls);
}

OLUA_API int olua_callback_wrapper(lua_State *L)
{
    lua_pushvalue(L, lua_upvalueindex(1));
    lua_insert(L, 1);
    lua_call(L, lua_gettop(L) - 1, LUA_MULTRET);
    return lua_gettop(L);
}

OLUA_API bool olua_is_callback(lua_State *L, int idx, const char *cls)
{
    bool is_wrapper = lua_tocfunction(L, idx) == olua_callback_wrapper;
    if (is_wrapper && lua_getupvalue(L, idx, 2)) {
        const char *cb_cls = lua_tostring(L, -1);
        lua_pop(L, 1);
        return cb_cls && strcmp(cb_cls, cls) == 0;
    }
    return olua_isfunction(L, idx);
}

OLUA_API int olua_push_callback(lua_State *L, const char *cls)
{
    if (!(olua_isfunction(L, -1) || olua_isnil(L, -1))) {
        luaL_error(L, "execpt 'function' or 'nil'");
    }
    if ((cls && strequal(cls, "std.function")) || olua_is_callback(L, -1, cls)) {
        lua_pushvalue(L, -1);
        return 1;
    } else {
        lua_pushvalue(L, -1);
        lua_pushstring(L, cls);
        lua_pushcclosure(L, olua_callback_wrapper, 2);
    }
    return 1;
}
