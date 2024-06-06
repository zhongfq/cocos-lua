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

#define OLUA_OBJSTUB        ".olua.objstub"
#define OLUA_OBJTABLE       ".olua.objtable"
#define OLUA_POOLTABLE      ".olua.pooltable"
#define OLUA_LUAREFTABLE    ".olua.luareftable"
#define OLUA_VMENV          ".olua.vmenv"
#define OLUA_REF_FMT        ".olua.ref.%s"

#define registry_rawgeti(L, f)  olua_rawgeti(L, LUA_REGISTRYINDEX, (f))
#define registry_rawgetf(L, f)  olua_rawgetf(L, LUA_REGISTRYINDEX, (f))
#define registry_rawsetf(L, f)  olua_rawsetf(L, LUA_REGISTRYINDEX, (f))

#define const_value(L, k, v)    (lua_pushvalue(L, (v)), oluacls_const(L, (k)))
#define const_string(L, k, v)   (olua_pushstring(L, (v)), oluacls_const(L, (k)))
#define const_from(L, k, mt)    (olua_rawgetf(L, (mt), (k)), oluacls_const(L, k))

#define OLUA_VMBUFF_SIZE 128
#define OLUA_FLAGBITS 32

typedef struct {
    int64_t ctxid;
    size_t poolsize;
    int64_t refcount;
    int64_t objcount;
    bool poolenabled;
    bool debug;
    char buff[OLUA_VMBUFF_SIZE];
} olua_VMEnv;

typedef struct {
    void *self;
    uint16_t flags;
    void *extra;
} olua_Object;

static int luaopen_olua(lua_State *L);
static int luaopen_enum(lua_State *L);
static int luaopen_voidp(lua_State *L);
static olua_Object *olua_toluaobj(lua_State *L, int idx);

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

char *tobitstr(uint16_t x, char buf[OLUA_FLAGBITS])
{
    int bits = sizeof(uint16_t) * 8;
    char *s = buf;
    *s++ = '0';
    *s++ = 'b';
    for (int i = bits - 1; i >= 0; i--) {
        *s++ = '0' + ((x >> i) & 1);
    }
    *s++ = 0;
    return buf;
}

static olua_VMEnv *olua_getvmenv(lua_State *L)
{
    static int64_t s_ctxid = 0;
    
    olua_VMEnv *env;
    if (olua_unlikely(registry_rawgetf(L, OLUA_VMENV) != LUA_TUSERDATA)) {
        env = (olua_VMEnv *)olua_newrawobj(L, NULL, sizeof(*env));
        env->ctxid = ++s_ctxid;
        env->debug = false;
        env->poolenabled = false;
        env->poolsize = 0;
        env->refcount = 0;
        env->objcount = 0;
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
        env = (olua_VMEnv *)olua_torawobj(L, -1);
    }
    lua_pop(L, 1);
    return env;
}

OLUA_API bool olua_isdebug(lua_State *L)
{
    return olua_getvmenv(L)->debug;
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

OLUA_API bool olua_checkbool(lua_State *L, int idx)
{
    luaL_checktype(L, idx, LUA_TBOOLEAN);
    return olua_tobool(L, idx);
}

OLUA_API int olua_rawgetf(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    olua_pushstring(L, field);
    return olua_rawget(L, idx);
}

OLUA_API void olua_rawsetf(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    olua_pushstring(L, field);
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

OLUA_API void olua_import(lua_State *L, lua_CFunction m)
{
    lua_pushcfunction(L, m);
    lua_call(L, 0, 0);
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
            isa = olua_tobool(L, -1);
        }
    }
    lua_settop(L, top);
    return isa;
}

static void olua_pushobjtable(lua_State *L)
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
    olua_VMEnv *env = olua_getvmenv(L);
    olua_pushobjtable(L);
    olua_newrawobj(L, NULL, 0); // create obj stub
    ptr = (void *)lua_topointer(L, -1);
    env->objcount++;
    lua_pushvalue(L, -1);
    olua_rawsetp(L, -3, ptr); // objtable[ptr] = stub
    lua_replace(L, -2); // pop objtable
    olua_setmetatable(L, cls);
    return ptr;
}

OLUA_API int olua_pushobjstub(lua_State *L, void *obj, void *stub, const char *cls)
{
    int status = OLUA_OBJ_EXIST;
    olua_pushobjtable(L);
    if (olua_rawgetp(L, -1, obj) == LUA_TUSERDATA) {
        // ref stub in obj
        olua_pushstring(L, OLUA_OBJSTUB);
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

static void olua_pushpooltable(lua_State *L)
{
    if (olua_unlikely(registry_rawgetf(L, OLUA_POOLTABLE) != LUA_TTABLE)) {
        lua_pop(L, 1);
        lua_createtable(L, 16, 0);
        lua_pushvalue(L, -1);
        registry_rawsetf(L, OLUA_POOLTABLE);
    }
}

static void olua_pushpoolobj(lua_State *L, void *obj)
{
    olua_Object *luaobj;
    olua_VMEnv *mt = olua_getvmenv(L);
    
    olua_pushpooltable(L);
    
    if (olua_unlikely(olua_rawgeti(L, -1, ++mt->poolsize) != LUA_TUSERDATA)) {
        lua_pop(L, 1);
        olua_newrawobj(L, NULL, 0);
        lua_pushvalue(L, -1);
        olua_rawseti(L, -3, mt->poolsize);
    }
    
    lua_replace(L, -2);  // rm pool table
    
    luaobj = olua_toluaobj(L, -1);
    luaobj->self = obj;
    luaobj->flags = OLUA_FLAG_SKIP_GC | OLUA_FLAG_IN_POOL;
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
        return status;
    }
    
    olua_pushobjtable(L);
    
    if (olua_likely(olua_rawgetp(L, -1, obj) == LUA_TNIL)) {
        olua_VMEnv *env = olua_getvmenv(L);
        lua_pop(L, 1);
        if (olua_isuserdata(L, -3) && olua_torawobj(L, -3) == obj) {
            lua_pushvalue(L, -3);
            // L: obj metaclass objtable obj
            lua_remove(L, -4);
        } else if (olua_unlikely(env->poolenabled)) {
            olua_pushpoolobj(L, obj);
            status = OLUA_OBJ_EXIST;
        } else {
            olua_newrawobj(L, obj, 0);
        }
        if (!olua_unlikely(env->poolenabled)) {
            lua_pushvalue(L, -1);
            // L: metaclass objtable obj obj
            olua_rawsetp(L, -3, obj); // objtable[obj] = obj
            env->objcount++;
            status = OLUA_OBJ_NEW;
        }
        // L: metaclass objtable obj
        lua_pushvalue(L, -3);
        lua_setmetatable(L, -2); // obj.metatable = metaclass
    } else if (olua_unlikely(!olua_strequal(cls, OLUA_VOIDCLS)
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

olua_Object *olua_toluaobj(lua_State *L, int idx)
{
#ifdef OLUA_DEBUG
    size_t len = lua_rawlen(L, idx);
    if (len < sizeof(olua_Object)) {
        luaL_error(L, "'%s: %p' is not a valid olua_Object",
            lua_typename(L, lua_type(L, idx)), lua_topointer(L, idx));
    }
#endif
    return (olua_Object *)lua_touserdata(L, idx);
}

OLUA_API void *olua_newrawobj(lua_State *L, void *obj, size_t extra)
{
    olua_Object *luaobj;
    void *ptr;
    lua_newuserdata(L, sizeof(olua_Object) + extra);
    luaobj = olua_toluaobj(L, -1);
    luaobj->flags = 0;
    ptr = extra > 0 ? ((char *)luaobj) + offsetof(olua_Object, extra) : NULL;
    luaobj->self = obj ? obj : ptr;
    return ptr;
}

OLUA_API void olua_setrawobj(lua_State *L, int idx, void *obj)
{
    olua_toluaobj(L, idx)->self = obj;
}

OLUA_API void *olua_torawobj(lua_State *L, int idx)
{
    return olua_toluaobj(L, idx)->self;
}

OLUA_API bool olua_getrawobj(lua_State *L, void *obj)
{
    if (!obj) {
        return false;
    }
    olua_pushobjtable(L);
    if (olua_rawgetp(L, -1, obj) == LUA_TUSERDATA) {
        lua_replace(L, -2);
        return true;
    } else {
        lua_pop(L, 2);
        return false;
    }
}

OLUA_API void olua_setobjflag(lua_State *L, int idx, int flag)
{
    olua_Object *luaobj = olua_toluaobj(L, idx);
    luaobj->flags |= flag;
}

OLUA_API bool olua_hasobjflag(lua_State *L, int idx, int flag)
{
    olua_Object *luaobj = olua_toluaobj(L, idx);
    return (luaobj->flags & flag) == flag;
}

static void *aux_toobj(lua_State *L, int idx, const char *cls, bool checked)
{
    if (olua_likely(checked ? olua_isa(L, idx, cls) : olua_isuserdata(L, idx))) {
        void *obj = olua_torawobj(L, idx);
        if (olua_unlikely(!obj)) {
            idx = lua_absindex(L, idx);
            olua_printobj(L, "access dead object", idx);
            luaL_error(L, "object '%s %p' survive from gc",
                olua_typename(L, idx), lua_topointer(L, idx));
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

OLUA_API void olua_delobj(lua_State *L, void *obj)
{
    if (!obj) {
        return;
    }
    olua_pushobjtable(L);
    if (olua_rawgetp(L, -1, obj) == LUA_TUSERDATA) {
        olua_setobjflag(L, -1, OLUA_FLAG_DEL);
        olua_setrawobj(L, -1, NULL);
    }
    lua_pushnil(L); // L: objtable ud nil
    olua_rawsetp(L, -3, obj);
    lua_pop(L, 2);
}

OLUA_API const char *olua_objstring(lua_State *L, int idx)
{
    olua_VMEnv *env = olua_getvmenv(L);
    const void *ud = lua_topointer(L, idx);
    const void *obj = ud;
    if (olua_isuserdata(L, idx)) {
        obj = olua_torawobj(L, idx);
    }
    snprintf(env->buff, OLUA_VMBUFF_SIZE, "%s: %p", olua_typename(L, idx), obj);
    return env->buff;
}

OLUA_API void olua_print(lua_State *L, const char *str)
{
    olua_getglobal(L, "print");
    olua_pushstring(L, str);
    lua_pcall(L, 1, 0, 0);
}

OLUA_API void olua_printobj(lua_State *L, const char *tag, int idx)
{
    char buf[256];
    char bitstr[OLUA_FLAGBITS];
    olua_Object *luaobj = olua_toluaobj(L, idx);
    olua_VMEnv *env = olua_getvmenv(L);
    snprintf(buf, sizeof(buf), "%s:%05"PRId64": %s {luaobj=%p,%s,%s}",
        tag,
        env->objcount,
        olua_objstring(L, idx),
        luaobj,
        luaobj->self ? olua_optfieldstring(L, idx, "name", "") : "",
        tobitstr(luaobj->flags, bitstr));
    olua_print(L, buf);
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

OLUA_API void olua_enable_objpool(lua_State *L)
{
    olua_getvmenv(L)->poolenabled = true;
}

OLUA_API void olua_disable_objpool(lua_State *L)
{
    olua_getvmenv(L)->poolenabled = false;
}

OLUA_API size_t olua_push_objpool(lua_State *L)
{
    return olua_getvmenv(L)->poolsize;
}

OLUA_API void olua_pop_objpool(lua_State *L, size_t position)
{
    if (olua_likely(registry_rawgetf(L, OLUA_POOLTABLE) == LUA_TTABLE)) {
        size_t len = (size_t)lua_rawlen(L, -1);
        olua_assert(position <= len, "invalid position");
        olua_getvmenv(L)->poolsize = position;
        for (size_t i = position + 1; i <= len; i++) {
            olua_rawgeti(L, -1, (lua_Integer)i);
            olua_Object *luaobj = olua_toluaobj(L, -1);
            lua_pushnil(L);
            lua_setmetatable(L, -2);    // remove metatable
            lua_pushnil(L);
            lua_setuservalue(L, -2);    // remove user value
            lua_pop(L, 1);
            if (olua_likely(luaobj->self != NULL)) {
                luaobj->self = NULL;
            } else {
                break;
            }
        }
    }
    lua_pop(L, 1);
}

static void olua_pushusertable(lua_State *L, int idx)
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
                return olua_strstartwith(field, tag);
            } else if (mode == OLUA_TAG_EQUAL || mode == OLUA_TAG_REPLACE) {
                return olua_strequal(field, tag);
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
        luaL_error(L, "obj userdata not found, it maybe in the obj pool!");
    }
    
    olua_pushusertable(L, -1);
    
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
        olua_VMEnv *env = olua_getvmenv(L);
        while (true) {
            char ref[64];
            snprintf(ref, sizeof(ref), "%"PRId64, obtainref(env));
            cb = lua_pushfstring(L, ".olua.cb#%s$%s@%s", ref, cls, tag);
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
    olua_rawset(L, -3); // usertable[fn] = func
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
    
    olua_pushusertable(L, -1);
    
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
    olua_pushusertable(L, -1);
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
                olua_rawset(L, -5); // usertable[fn] = nil
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
    return olua_torawobj(L, -1);
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
    olua_pushusertable(L, idx);
    lua_insert(L, -3);
    // L: obj uservalue k v
    olua_settable(L, -3); // uservalue[k] = v
    lua_pop(L, 1); // pop uservalue
}

static void olua_pushluareftable(lua_State *L)
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
        olua_VMEnv *env = olua_getvmenv(L);
        int64_t ref = obtainref(env);
        idx = lua_absindex(L, idx);
        olua_pushluareftable(L);
        // find a valid ref slot
        while (olua_rawgeti(L, -1, ref) != LUA_TNIL) {
            lua_pop(L, 1);
            ref = obtainref(env);
        }
        lua_pushvalue(L, idx);
        olua_rawseti(L, -3, ref); // refable[ref] = value
        lua_pop(L, 2); // pop reftable nil
        return ref;
    }
    return LUA_REFNIL;
}

OLUA_API void olua_unref(lua_State *L, olua_Ref ref)
{
    olua_pushluareftable(L);
    lua_pushnil(L);
    olua_rawseti(L, -2, ref); // reftable[ref] = nil
    lua_pop(L, 1);
}

OLUA_API void olua_getref(lua_State *L, olua_Ref ref)
{
    olua_pushluareftable(L);
    olua_rawgeti(L, -1, ref);
    lua_replace(L, -2);
}

OLUA_API int olua_loadref(lua_State *L, int idx, const char *name)
{
    int type;
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    olua_pushusertable(L, idx);
    lua_pushfstring(L, OLUA_REF_FMT, name);
    type = olua_rawget(L, -2);
    lua_replace(L, -2); // replace usertable
    return type;
}

static void olua_getreftable(lua_State *L, int idx, const char *name)
{
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    olua_pushusertable(L, idx);
    name = lua_pushfstring(L, OLUA_REF_FMT, name);;
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
    if (flags & OLUA_REF_REMOVE) {
        lua_pushnil(L);
    } else if (flags & OLUA_REF_ALONE) {
        olua_assert(olua_isuserdata(L, obj) || olua_isnil(L, obj), "expect userdata or nil");
        lua_pushvalue(L, obj);
    } else {
        olua_pushbool(L, true);
    }
    if (flags & OLUA_REF_ALONE) {
        olua_pushusertable(L, idx);
        lua_pushfstring(L, OLUA_REF_FMT, name);
        lua_pushvalue(L, top + 1);
        // L: usertable name obj|nil
        olua_rawset(L, -3); // L: usertable[name] = obj|nil
    } else if (flags & OLUA_REF_MULTI) {
        if (olua_isnil(L, obj)) {
            lua_settop(L, top);
            return;
        }
        if (flags & OLUA_REF_TABLE) {
            olua_assert(olua_istable(L, obj), "expect table");
            olua_getreftable(L, idx, name);
            lua_pushnil(L);
            while (lua_next(L, obj)) {
                if (olua_isuserdata(L, -2)) {
                    lua_pushvalue(L, -2);
                    lua_pushvalue(L, top + 1);
                    // L: reftable obj value obj true|nil
                    olua_rawset(L, -5); // L: reftable[obj] = true|nil
                }
                if (olua_isuserdata(L, -1)) {
                    lua_pushvalue(L, -1);
                    lua_pushvalue(L, top + 1);
                    // L: reftable name obj obj true|nil
                    olua_rawset(L, -5); // L: reftable[obj] = true|nil
                }
                lua_pop(L, 1);
            }
        } else {
            olua_assert(olua_isuserdata(L, obj), "expect userdata");
            olua_getreftable(L, idx, name);
            lua_pushvalue(L, obj);
            lua_pushvalue(L, top + 1);
            // L: reftable obj obj|nil
            olua_rawset(L, -3); // L: reftable[obj] = true|nil
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
    aux_changeref(L, idx, name, obj, flags | OLUA_REF_REMOVE);
}

OLUA_API void olua_delallrefs(lua_State *L, int idx, const char *name)
{
    aux_changeref(L, idx, name, 0, OLUA_REF_ALONE | OLUA_REF_REMOVE);
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
                olua_rawset(L, kidx - 1);
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
        olua_rawset(L, t); // cache in current table
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
        olua_pushstring(L, name);
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
    olua_VMEnv *env;
    olua_Object *luaobj;
    bool isgc = olua_tobool(L, lua_upvalueindex(3));
    lua_pushvalue(L, lua_upvalueindex(2));
    if (!lookupfunc(L, lua_upvalueindex(1), lua_gettop(L))) {
        if (!isgc) {
            luaL_error(L, "meta method '%s' not found for '%s'",
                olua_checkstring(L, lua_upvalueindex(2)), olua_objstring(L, 1));
        }
        return 0;
    }
    lua_replace(L, -2); // remove name
    lua_insert(L, 1);
    if (!isgc) {
        lua_call(L, lua_gettop(L) - 1, LUA_MULTRET);
        return lua_gettop(L);
    }
    if (!olua_isuserdata(L, 2)) {
        // unnecessary call __gc on class table
        return 0;
    }

    env = olua_getvmenv(L);
    env->objcount--;
    luaobj = olua_toluaobj(L, 2);

    if (luaobj->flags & (OLUA_FLAG_SKIP_GC | OLUA_FLAG_DEL)) {
        if (env->debug) {
            olua_printobj(L, "skip gc", 2);
        }
        return 0;
    } else {
        char buf[256];
        char bitstr[OLUA_FLAGBITS];
        size_t max_len = sizeof(buf);
        size_t len = 0;
        olua_setobjflag(L, 2, OLUA_FLAG_GC);
        if (env->debug) {
            const char *fmt = "lua gc:%05"PRId64": %s {luaobj=%p";
            len = snprintf(buf, max_len, fmt,
                env->objcount,
                olua_objstring(L, 2),
                luaobj
            );
            if (luaobj->self && len < max_len) {
                snprintf(buf + len, max_len - len, ",%s",
                    olua_optfieldstring(L, 2, "name", ""));
                len = strlen(buf);
            }
        }
        olua_pusherrorfunc(L);
        lua_insert(L, 1);
        lua_pcall(L, lua_gettop(L) - 2, LUA_MULTRET, 1);
        if (!luaobj->self) {
            luaobj->flags |= OLUA_FLAG_GC_DONE;
        }
        if (env->debug) {
            if (len < max_len) {
                snprintf(buf + len, max_len - len, ",%s}",
                    tobitstr(luaobj->flags, bitstr));
                len = strlen(buf);
            }
            olua_print(L, buf);
        }
        return lua_gettop(L) - 1;
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
        olua_rawset(L, OLUA_CIDX_FUNC);
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

static int cls_readonly(lua_State *L)
{
    const char *cls = olua_checkfieldstring(L, 1, "classname");
    lua_pushvalue(L, lua_upvalueindex(1));
    luaL_error(L, "readonly property '%s' for %s", olua_tostring(L, -1), cls);
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
        if (olua_strequal(field, OLUA_CKEY_ISA)) {
            // copy super .isa
            lua_pushnil(L);
            while (lua_next(L, -2)) {
                lua_pushvalue(L, -2);
                lua_insert(L, -2);
                // L: table super_table k k v
                olua_rawset(L, -5); // table[k] = v
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
    if (!supercls && !olua_strequal(cls, OLUA_VOIDCLS)) {
        supercls = OLUA_VOIDCLS;
    }
    if (!supercls) {
        lua_pushnil(L);
    } else if (olua_getmetatable(L, supercls) != LUA_TTABLE) {
        if (olua_strequal(supercls, OLUA_VOIDCLS)) {
            olua_require(L, "void *", luaopen_voidp);
            olua_require(L, "enum *", luaopen_enum);
            olua_require(L, "olua", luaopen_olua);
            olua_getmetatable(L, OLUA_VOIDCLS);
            lua_replace(L, -2);
            olua_debug_assert(lua_istable(L, -1), "class 'void *' not found");
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
            olua_pushstring(L, *e);
            olua_pushbool(L, olua_strequal(*e, "__gc"));
            // set .func e isgc as cls_metamethod upvalue
            lua_pushcclosure(L, cls_metamethod, 3);
            // L: metaclass .func metamethod
            olua_rawsetf(L, -3, *e); // metaclass[e] = metamethod
        }
        olua_rawgetf(L, metaclass, OLUA_CKEY_ISA); // metaclass[.isa]
        // L: metaclass .func .isa
        olua_setfieldbool(L, -1, cls, true); //.isa[cls] = true
        lua_pop(L, 2); // pop .func .isa
        
        // create class object, store static function callback
        olua_pushobjtable(L);
        olua_newrawobj(L, NULL, sizeof(void *)); // create clsobj
        lua_createtable(L, 0, 1);   // create metatable
        lua_pushvalue(L, -1);
        lua_pushfstring(L, "classobj(%s)", cls);
        olua_setfield(L, -2, "__name");
        // L: metaclass objtable clsobj metatable metatable
        olua_rawsetf(L, -2, "__index"); // metatable.__index = metatable
        olua_setfieldstring(L, -1, "classname", cls);
        lua_setmetatable(L, -2); // clsobj.metatable = metatable
        lua_pushvalue(L, -1);
        // L: metaclass objtable clsobj clsobj
        olua_rawsetf(L, metaclass, OLUA_CKEY_CLSOBJ); // metaclass[.classobj] = clsobj
        olua_rawsetp(L, -2, olua_torawobj(L, -1)); // objtable[objptr] = clsobj
        lua_pop(L, 1); // pop objtable
        
        // create class
        lua_createtable(L, 0, 0);
        lua_pushvalue(L, metaclass);
        // L: .metaclass class .metaclass
        lua_setmetatable(L, -2);  // class.metatable = metaclass
        const_value(L, "class", -1); // class.class = class
        const_string(L, "classname", cls); // class.classname = cls
        const_string(L, "classtype", "native"); // class.classtype = native
        // const value from metaclass: class[k] = metaclass[k]
        const_from(L, ".classobj", metaclass);
        const_from(L, ".isa", metaclass);
        const_from(L, ".func", metaclass);
        const_from(L, ".get", metaclass);
        const_from(L, ".set", metaclass);
        
        if (supercls) {
            olua_rawgetf(L, super, OLUA_CKEY_CLASS);
            oluacls_const(L, "super"); // class.super = super
        }
        olua_rawsetf(L, metaclass, OLUA_CKEY_CLASS); // metaclass.class = class
    } else {
        luaL_error(L, "class '%s' already created", cls);
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
        olua_pushstring(L, name);
        aux_setfunc(L, OLUA_CKEY_SET, name, cls_readonly, 1);
    }
}

OLUA_API void oluacls_func(lua_State *L, const char *name, lua_CFunction func)
{
    aux_setfunc(L, OLUA_CKEY_FUNC, name, func, 0);
}

OLUA_API void oluacls_enum(lua_State *L, const char *name, lua_Integer value)
{
    lua_pushlightuserdata(L, (void *)(intptr_t)value);
    oluacls_const(L, name);
}

OLUA_API void oluacls_const(lua_State *L, const char *name)
{
    int t = lua_type(L, -1);
    if (t == LUA_TNIL || t == LUA_TNONE) {
        luaL_error(L, "const nil value(%s)", name);
    }
    aux_setfunc(L, OLUA_CKEY_GET, name, cls_const, 1);
    olua_pushstring(L, name);
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

OLUA_API bool olua_checkfieldbool(lua_State *L, int idx, const char *field)
{
    bool value;
    aux_checkfield(L, idx, field, LUA_TBOOLEAN, false);
    value = olua_tobool(L, -1);
    lua_pop(L, 1);
    return value;
}

OLUA_API void olua_setfieldnumber(lua_State *L, int idx, const char *field, lua_Number value)
{
    idx = lua_absindex(L, idx);
    olua_pushnumber(L, value);
    olua_setfield(L, idx, field);
}

OLUA_API void olua_setfieldinteger(lua_State *L, int idx, const char *field, lua_Integer value)
{
    idx = lua_absindex(L, idx);
    olua_pushinteger(L, value);
    olua_setfield(L, idx, field);
}

OLUA_API void olua_setfieldstring(lua_State *L, int idx, const char *field, const char *value)
{
    idx = lua_absindex(L, idx);
    olua_pushstring(L, value);
    olua_setfield(L, idx, field);
}

OLUA_API void olua_setfieldfunc(lua_State *L, int idx, const char *field, lua_CFunction fn)
{
    idx = lua_absindex(L, idx);
    lua_pushcfunction(L, fn);
    olua_setfield(L, idx, field);
}

OLUA_API void olua_setfieldbool(lua_State *L, int idx, const char *field, bool value)
{
    idx = lua_absindex(L, idx);
    olua_pushbool(L, value);
    olua_setfield(L, idx, field);
}

OLUA_API const char *olua_optfieldstring(lua_State *L, int idx, const char *field, const char *def)
{
    olua_getfield(L, idx, field);
    def = olua_optstring(L, -1, def);
    lua_pop(L, 1);
    return def;
}

OLUA_API lua_Number olua_optfieldnumber(lua_State *L, int idx, const char *field, lua_Number def)
{
    olua_getfield(L, idx, field);
    def = olua_optnumber(L, -1, def);
    lua_pop(L, 1);
    return def;
}

OLUA_API lua_Integer olua_optfieldinteger(lua_State *L, int idx, const char *field, lua_Integer def)
{
    olua_getfield(L, idx, field);
    def = olua_optinteger(L, -1, def);
    lua_pop(L, 1);
    return def;
}

OLUA_API bool olua_optfieldbool(lua_State *L, int idx, const char *field, bool def)
{
    olua_getfield(L, idx, field);
    def = olua_optbool(L, -1, def);
    lua_pop(L, 1);
    return def;
}

OLUA_API bool olua_hasfield(lua_State *L, int idx, const char *field)
{
    int type = olua_getfield(L, idx, field);
    lua_pop(L, 1);
    return type != LUA_TNIL;
}

static int l_olua_with(lua_State *L)
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

static int l_olua_isa(lua_State *L)
{
    olua_pushbool(L, olua_isa(L, 1, olua_checkstring(L, 2)));
    return 1;
}

static int l_olua_take(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TUSERDATA);
    if (olua_hasobjflag(L, 1, OLUA_FLAG_IN_HEAP)) {
        olua_setobjflag(L, 1, OLUA_FLAG_SKIP_GC | OLUA_FLAG_TAKE);
    } else {
        olua_printobj(L, "take error", 1);
        luaL_error(L, "'%s' is not created from heap", olua_objstring(L, 1));
    }
    return 0;
}

static int l_olua_move(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TUSERDATA);
    olua_getfield(L, 1, "__olua_move");
    if (!olua_isfunction(L, -1)) {
        luaL_error(L, "method '__olua_move' not found in '%s'", olua_objstring(L, 1));
    }
    lua_insert(L, 1);
    // maybe move object from object pool to the object table
    lua_call(L, lua_gettop(L) - 1, LUA_MULTRET);
    return lua_gettop(L);
}

static int l_olua_debug(lua_State *L)
{
    if (olua_isnil(L, 1)) {
        olua_pushbool(L, olua_getvmenv(L)->debug);
        return 1;
    } else {
        olua_getvmenv(L)->debug = olua_checkbool(L, 1);
        return 0;
    }
}

static int l_olua_iscfunc(lua_State *L)
{
    olua_pushbool(L, lua_iscfunction(L, 1));
    return 1;
}

static int l_olua_class(lua_State *L)
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

static int l_olua_enum(lua_State *L)
{
    if (lua_isinteger(L, 1)) {
        lua_pushlightuserdata(L, (void *)(intptr_t)olua_tointeger(L, 1));
    } else if (lua_islightuserdata(L, 1)) {
        lua_pushinteger(L, (lua_Integer)(intptr_t)lua_touserdata(L, 1));
    } else {
        luaL_error(L, "expect integer or lightuserdata");
    }
    return 1;
}

static int l_olua_setmetatable(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TUSERDATA);
    if (olua_getmetatable(L, olua_checkstring(L, 2)) == LUA_TTABLE) {
        lua_setmetatable(L, 1);
    } else {
        luaL_error(L, "metatable '%s' not found", olua_checkstring(L, 2));
    }
    return 0;
}

static int l_lua_getmetatable(lua_State *L)
{
    olua_getmetatable(L, olua_checkstring(L, 1));
    return 1;
}

static int l_olua_topointer(lua_State *L)
{
    olua_pushinteger(L, (lua_Integer)(uintptr_t)lua_topointer(L, 1));
    return 1;
}

static int l_olua_objpool(lua_State *L)
{
    const char *action = olua_checkstring(L, 1);
    if (olua_strequal(action, "enable")) {
        olua_enable_objpool(L);
    } else if (olua_strequal(action, "disable")) {
        olua_disable_objpool(L);
    } else if (olua_strequal(action, "push")) {
        size_t position = olua_push_objpool(L);
        olua_pushinteger(L, (lua_Integer)position);
        return 1;
    } else if (olua_strequal(action, "pop")) {
        size_t position = (size_t)olua_checkinteger(L, 2);
        olua_pop_objpool(L, position);
    } else {
        luaL_error(L, "unknown action '%s'", action);
    }
    return 0;
}

static int l_olua_ref(lua_State *L)
{
    const char *action = olua_checkstring(L, 1);
    const char *name = olua_checkstring(L, 3);
    luaL_checktype(L, 2, LUA_TUSERDATA);
    if (olua_strequal(action, "load")) {
        olua_loadref(L, 2, name);
        return 1;
    } else if (olua_strequal(action, "add")) {
        olua_addref(L, 2, name, 4, (int)olua_checkinteger(L, 5));
    } else if (olua_strequal(action, "del")) {
        olua_delref(L, 2, name, 4, (int)olua_checkinteger(L, 5));
    } else if (olua_strequal(action, "delall")) {
        olua_delallrefs(L, 2, name);
    } else {
        luaL_error(L, "unknown action '%s'", action);
    }
    return 0;
}

static int l_olua_printobj(lua_State *L) 
{
    const char *tag = "luaobj";
    int idx = 1;
    if (olua_isstring(L, 1)) {
        tag = olua_checkstring(L, 1);
        idx = 2;
    }
    olua_checkobj(L, idx, OLUA_VOIDCLS);
    olua_printobj(L, tag, idx);
    return 0;
}

static int l_olua_uservalue(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TUSERDATA);
    olua_pushusertable(L, 1);
    return 1;
}

int luaopen_olua(lua_State *L)
{
    static luaL_Reg lib[] = {
        {"with", l_olua_with},
        {"isa", l_olua_isa},
        {"take", l_olua_take},
        {"move", l_olua_move},
        {"debug", l_olua_debug},
        {"class", l_olua_class},
        {"enum", l_olua_enum},
        {"iscfunc", l_olua_iscfunc},
        {"setmetatable", l_olua_setmetatable},
        {"getmetatable", l_lua_getmetatable},
        {"topointer", l_olua_topointer},
        {"objpool", l_olua_objpool},
        {"ref", l_olua_ref},
        {"printobj", l_olua_printobj},
        {"uservalue", l_olua_uservalue},
        {NULL, NULL}
    };
    luaL_newlib(L, lib);
    lua_pushvalue(L, -1);
    olua_setglobal(L, "olua");
    return 1;
}

static int l_voidp_stub(lua_State *L)
{
    return 0;
}

static int l_voidp_tostring(lua_State *L)
{
    olua_pushstring(L, olua_objstring(L, 1));
    return 1;
}

static int l_voidp_getname(lua_State *L)
{
    lua_pushstring(L, "name");
    olua_getvariable(L, 1);
    return 1;
}

static int l_voidp_setname(lua_State *L)
{
    lua_pushstring(L, "name");
    lua_insert(L, 2);
    olua_setvariable(L, 1);
    return 0;
}

int luaopen_voidp(lua_State *L)
{
    oluacls_class(L, OLUA_VOIDCLS, NULL);
    oluacls_func(L, "__gc", l_voidp_stub);
    oluacls_func(L, "__eq", l_voidp_stub);
    oluacls_func(L, "__tostring", l_voidp_tostring);
    oluacls_prop(L, "name", l_voidp_getname, l_voidp_setname);
    return 1;
}

static intptr_t aux_toenum(lua_State *L, int idx) {
    switch(lua_type(L, idx)) {
        case LUA_TLIGHTUSERDATA:
            return (intptr_t)lua_touserdata(L, idx);
        case LUA_TNUMBER:
            return (intptr_t)olua_checkinteger(L, idx);
        default:
            luaL_checktype(L, idx, LUA_TLIGHTUSERDATA);
            break;
    }
    return 0;
}

static int l_enum_tostring(lua_State *L)
{
    lua_pushfstring(L, "lightuserdata: %p", lua_topointer(L, 1));
    return 1;
}

static int l_enum_lt(lua_State *L)
{
    return aux_toenum(L, 1) < aux_toenum(L, 2);
}

static int l_enum_le(lua_State *L)
{
    return aux_toenum(L, 1) <= aux_toenum(L, 2);
}

int luaopen_enum(lua_State *L)
{
    lua_pushlightuserdata(L, NULL);
    luaL_newmetatable(L, "enum *");
    olua_setfieldfunc(L, -1, "__tostring", l_enum_tostring);
    olua_setfieldfunc(L, -1, "__lt", l_enum_lt);
    olua_setfieldfunc(L, -1, "__le", l_enum_le);
    lua_pushvalue(L, -1);
    lua_setmetatable(L, -3);
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
        olua_setfield(L, -(nup + 2), l->name);
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
        olua_setfield(L, idx, fname);
        return 0;
    }
}

OLUA_API void luaL_requiref(lua_State *L, const char *modname, lua_CFunction openf, int glb) {
    luaL_getsubtable(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
    olua_getfield(L, -1, modname);
    if (!lua_toboolean(L, -1)) {
        lua_pop(L, 1);
        lua_pushcfunction(L, openf);
        olua_pushstring(L, modname);
        lua_call(L, 1, 1);
        lua_pushvalue(L, -1);
        olua_setfield(L, -3, modname);
    }
    lua_remove(L, -2);
    if (glb) {
        lua_pushvalue(L, -1);
        olua_setglobal(L, modname);
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
    olua_getglobal(L, "debug");
    olua_getfield(L, -1, "traceback");
    lua_remove(L, -2);
    if (L != L1) {
        lua_pushthread(L1);
        lua_xmove(L1, L, 1);
    }
    olua_pushstring(L, msg ? msg : "");
    olua_pushinteger(L, L != L1 ? level : (level + 1));
    lua_pcall(L, L != L1 ? 3 : 2, 1, 0);
    if (msg == NULL) {
        msg = lua_tostring(L, -1);
        if (msg[0] == '\n') {
            olua_pushstring(L, msg + 1);
            lua_remove(L, -2);
        }
    }
}

OLUA_API void olua_initcompat(lua_State *L)
{
    lua_pushthread(L);
    olua_rawseti(L, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
    lua_pushvalue(L, LUA_GLOBALSINDEX);
    olua_rawseti(L, LUA_REGISTRYINDEX, LUA_RIDX_GLOBALS);
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
typedef int64_t olua_Context;

OLUA_API olua_Context olua_context(lua_State *L)
{
    return (olua_Context)olua_getvmenv(L)->ctxid;
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
    olua_pushstring(L, newtype);
    olua_pushstring(L, cls);
    olua_rawset(L, LUA_REGISTRYINDEX);
}

OLUA_API const char *olua_getluatype(lua_State *L, const char *cpptype)
{
    char newtype[OLUA_MAX_CPPTYPE];
    format_cpptype(newtype, cpptype);
    return olua_optfieldstring(L, LUA_REGISTRYINDEX, newtype, NULL);
}
#endif

static int olua_callback_wrapper(lua_State *L)
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
        return olua_strequal(cb_cls, cls);
    }
    return olua_isfunction(L, idx) && olua_strequal(cls, "std.function");
}

OLUA_API int olua_push_callback(lua_State *L, const char *cls)
{
    if (!(olua_isfunction(L, -1) || olua_isnil(L, -1))) {
        luaL_error(L, "expect 'function' or 'nil'");
    }
    if (olua_isnil(L, -1) || olua_is_callback(L, -1, cls)) {
        lua_pushvalue(L, -1);
        return 1;
    } else {
        lua_pushvalue(L, -1);
        olua_pushstring(L, cls);
        lua_pushcclosure(L, olua_callback_wrapper, 2);
    }
    return 1;
}
