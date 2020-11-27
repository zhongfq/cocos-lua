/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2019-2020 codetypes@gmail.com
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

#define OLUA_CIDX_ISA  (lua_upvalueindex(1))
#define OLUA_CIDX_FUNC (lua_upvalueindex(2))
#define OLUA_CIDX_GET  (lua_upvalueindex(3))
#define OLUA_CIDX_SET  (lua_upvalueindex(4))

#define OLUA_CKEY_ISA       ".isa"
#define OLUA_CKEY_FUNC      ".func"
#define OLUA_CKEY_GET       ".get"
#define OLUA_CKEY_SET       ".set"
#define OLUA_CKEY_CLSOBJ    ".classobj"
#define OLUA_CKEY_CLSAGENT  ".classagent"

#define OLUA_OBJTABLE       ((void *)(uintptr_t)aux_pushobjtable)
#define OLUA_POOLTABLE      ((void *)(uintptr_t)aux_pushlocalobj)
#define OLUA_MAPPINGTABLE   ((void *)(uintptr_t)aux_pushmappingtable)
#define OLUA_VMSTATUS       ((void *)(uintptr_t)aux_getvmstatus)

#define registry_rawgetp(L, p)  olua_rawgetp(L, LUA_REGISTRYINDEX, (p))
#define registry_rawsetp(L, p)  olua_rawsetp(L, LUA_REGISTRYINDEX, (p))

#define strequal(s1, s2)        (strcmp((s1), (s2)) == 0)
#define strstartwith(s1, s2)    (strstr((s1), (s2)) == s1)
#define aux_pushrefkey(L, n)    (lua_pushfstring(L, ".ref.%s", (n)))

typedef struct {
    lua_Integer ctxid;
    size_t objcount;
    size_t poolsize;
    int ref;
    bool poolenabled;
    bool debug;
} olua_vmstatus_t;

static inline void aux_checkref(olua_vmstatus_t *vms)
{
    if (vms->ref + 1 < 0) {
        vms->ref = 0;
    }
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

static olua_vmstatus_t *aux_getvmstatus(lua_State *L)
{
    olua_vmstatus_t *vms;
    if (olua_unlikely(registry_rawgetp(L, OLUA_VMSTATUS) != LUA_TUSERDATA)) {
        static lua_Integer s_ctxid = 0;
        vms = (olua_vmstatus_t *)lua_newuserdata(L, sizeof(*vms));
        vms->ctxid = ++s_ctxid;
        vms->debug = false;
        vms->poolenabled = false;
        vms->poolsize = 0;
        vms->objcount = 0;
        vms->ref = 0;
        registry_rawsetp(L, OLUA_VMSTATUS);
#if LUA_VERSION_NUM == 501
        olua_checkcompat(L);
#endif
    } else {
        vms = (olua_vmstatus_t *)lua_touserdata(L, -1);
    }
    lua_pop(L, 1);
    return vms;
}

OLUA_API size_t olua_modifyobjcount(lua_State *L, size_t n)
{
    return aux_getvmstatus(L)->objcount += n;
}

OLUA_API bool olua_isdebug(lua_State *L)
{
    return aux_getvmstatus(L)->debug;
}

#ifndef olua_mainthread
OLUA_API lua_State *olua_mainthread(lua_State *L)
{
    lua_State *mt = NULL;
    if (L) {
        olua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
        luaL_checktype(L, -1, LUA_TTHREAD);
        mt = lua_tothread(L, -1);
        lua_pop(L, 1);
    }
    return mt;
}
#endif

OLUA_API lua_Integer olua_context(lua_State *L)
{
    return aux_getvmstatus(L)->ctxid;
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
    lua_insert(L, errfunc);
    status = lua_pcall(L, nargs, nresults, errfunc);
    lua_remove(L, errfunc);
    return status;
}

OLUA_API int olua_pcallref(lua_State *L, int funcref, int nargs, int nresults)
{
    olua_getref(L, funcref);
    lua_insert(L, -(nargs + 1));
    return olua_pcall(L, nargs, nresults);
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
    if (olua_unlikely(registry_rawgetp(L, OLUA_OBJTABLE) != LUA_TTABLE)) {
        lua_pop(L, 1);
        lua_newtable(L);
        olua_setfieldstring(L, -1, "__mode", "v");
        lua_pushvalue(L, -1);
        lua_setmetatable(L, -2);
        lua_pushvalue(L, -1);
        registry_rawsetp(L, OLUA_OBJTABLE);
    }
}

OLUA_API void *olua_newobjstub(lua_State *L, const char *cls)
{
    void *ptr = NULL;
    aux_pushobjtable(L);                        // L: objtable
    olua_newrawobj(L, NULL);                    // L: objtable ud
    ptr = (void *)lua_topointer(L, -1);
    lua_pushvalue(L, -1);                       // L: objtable ud ud
    olua_rawsetp(L, -3, ptr);                   // L: objtable ud     objtable[ptr] = ud
    lua_replace(L, -2);                         // L: ud
    olua_setmetatable(L, cls);
    return ptr;
}

OLUA_API int olua_pushobjstub(lua_State *L, void *obj, void *stub, const char *cls)
{
    int status = OLUA_OBJ_EXIST;
    aux_pushobjtable(L);                        // L: objt
    if (olua_rawgetp(L, -1, obj) == LUA_TUSERDATA) {
        // ref stub in obj
        lua_pushstring(L, ".stub");             // L: objt ud .stub
        olua_rawgetp(L, -3, stub);              // L: objt ud .stub stub
        olua_setvariable(L, -3);                // L: objt ud   obj.uv[.stub] = stub
        // stub point to obj
        lua_pushvalue(L, -1);                   // L: objt ud ud
        olua_rawsetp(L, -3, stub);              // L: objt ud      objt[stub] = ud
    } else if (olua_rawgetp(L, -2, stub) == LUA_TUSERDATA) {
        lua_remove(L, -2);                      // remove nil
        olua_setmetatable(L, cls);
        olua_setrawobj(L, -1, obj);             // L: objt ud
        lua_pushvalue(L, -1);                   // L: objt ud ud
        olua_rawsetp(L, -3, obj);               // L: objt ud      objt[obj] = ud
        status = OLUA_OBJ_NEW;
    } else {
        luaL_error(L, "stub object not found for '%s'", cls);
    }
    lua_replace(L, -2);                         // L: obj
    return status;
}

static void aux_pushlocalobj(lua_State *L, void *obj)
{
    olua_vmstatus_t *mt = aux_getvmstatus(L);
    if (olua_unlikely(registry_rawgetp(L, OLUA_POOLTABLE) != LUA_TTABLE)) {
        lua_pop(L, 1);
        lua_createtable(L, 16, 0);
        lua_pushvalue(L, -1);
        registry_rawsetp(L, OLUA_POOLTABLE);
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
        luaL_error(L, "class '%s' not found", cls ? cls : "NULL");
    }
    
    aux_pushobjtable(L);                        // L: mt objtable
    
    if (olua_likely(olua_rawgetp(L, -1, obj) == LUA_TNIL)) {
        lua_pop(L, 1);                          // L: mt objtable
        if (olua_unlikely(aux_getvmstatus(L)->poolenabled)) {
            aux_pushlocalobj(L, obj);
            status = OLUA_OBJ_EXIST;
        } else {
            olua_newrawobj(L, obj);             // L: mt objtable ud
            lua_pushvalue(L, -1);               // L: mt objtable ud ud
            olua_rawsetp(L, -3, obj);           // L: mt objtable ud     objtable[obj] = ud
            status = OLUA_OBJ_NEW;
        }
        lua_pushvalue(L, -3);                   // L: mt objtable ud mt
        lua_setmetatable(L, -2);                // L: mt objtable ud     ud.metatable = mt
    } else if (olua_unlikely(!strequal(cls, OLUA_VOIDCLS)
            && luaL_testudata(L, -1, OLUA_VOIDCLS))) {
        lua_pushvalue(L, -3);                   // L: mt objtable ud mt
        lua_setmetatable(L, -2);                // L: mt objtable ud     ud.metatable = mt
        status = OLUA_OBJ_UPDATE;
    }
    
    lua_insert(L, -3);                          // L: ud mt objtable
    lua_pop(L, 2);                              // L: ud
    
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
    const void *p = olua_isuserdata(L, idx) ?
        olua_torawobj(L, idx) : lua_topointer(L, idx);
    return lua_pushfstring(L, "%s: %p", olua_typename(L, idx), p);
}

OLUA_API void olua_enable_objpool(lua_State *L)
{
    aux_getvmstatus(L)->poolenabled = true;
}

OLUA_API void olua_disable_objpool(lua_State *L)
{
    aux_getvmstatus(L)->poolenabled = false;
}

OLUA_API size_t olua_push_objpool(lua_State *L)
{
    return aux_getvmstatus(L)->poolsize;
}

OLUA_API void olua_pop_objpool(lua_State *L, size_t position)
{
    if (olua_likely(registry_rawgetp(L, OLUA_POOLTABLE) == LUA_TTABLE)) {
        size_t len = (size_t)lua_rawlen(L, -1);
        olua_assert(position < len, "invalid position");
        aux_getvmstatus(L)->poolsize = position;
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
            if (mode == OLUA_TAG_SUBSTARTWITH) {
                return strstartwith(field, tag);
            } else if (mode == OLUA_TAG_SUBEQUAL || mode == OLUA_TAG_REPLACE) {
                return strequal(field, tag);
            }
        }
    }
    return false;
}

OLUA_API const char *olua_setcallback(lua_State *L, void *obj, const char *tag, int fidx, int tagmode)
{
    const char *func = NULL;
    fidx = lua_absindex(L, fidx);
    luaL_checktype(L, fidx, LUA_TFUNCTION);
    
    if (!olua_getrawobj(L, obj)) {              // L: obj
        luaL_error(L, "obj userdata not found");
    }
    
    aux_getusertable(L, -1);                    // L: obj ut
    
    if (tagmode == OLUA_TAG_REPLACE) {
        lua_pushnil(L);                         // L: obj ut k
        while (lua_next(L, -2)) {               // L: obj ut k v
            if (test_tag_mode(L, -2, tag, tagmode)) {
                func = olua_tostring(L, -2);
                lua_pop(L, 1);                  // L: obj ut k
                break;
            }
            lua_pop(L, 1);                      // L: obj ut k
        }
    }
    
    if (func == NULL) {
        const char *cls = olua_checkfieldstring(L, -2, "classname");
        olua_vmstatus_t *vms = aux_getvmstatus(L);
        aux_checkref(vms);
        while (true) {
            lua_Integer ref = ++vms->ref;
            char refstr[64];
            sprintf(refstr, "%lld", (int64_t)ref); // lua5.1 not support %I
            func = lua_pushfstring(L, ".callback#%s$%s@%s", refstr, cls, tag);
            lua_pushvalue(L, -1);               // L: obj ut k k
            if (olua_rawget(L, -3) == LUA_TNIL) {
                lua_pop(L, 1);                  // L: obj ut k
                break;
            } else {
                aux_checkref(vms);
                lua_pop(L, 2);                  // L: obj ut
            }
        }
    }
    
    lua_pushvalue(L, fidx);                     // L: obj ut k v
    lua_rawset(L, -3);                          // L: obj ut
    lua_pop(L, 2);                              // L:
    return func;
}

OLUA_API int olua_getcallback(lua_State *L, void *obj, const char *tag, int tagmode)
{
    if (!olua_getrawobj(L, obj)) {
        lua_pushnil(L);
        return LUA_TNIL;
    }
    
    aux_getusertable(L, -1);                    // L: obj ct
    
    if (tagmode == OLUA_TAG_WHOLE) {
        olua_rawgetf(L, -1, tag);               // L: obj ct func
    } else {
        lua_pushnil(L);                         // L: obj ct nil
        lua_pushnil(L);                         // L: obj ct nil k
        while (lua_next(L, -3)) {               // L: obj ct nil k func
            if (test_tag_mode(L, -2, tag, tagmode)) {
                lua_replace(L, -3);             // L: obj ct func k
                lua_pop(L, 1);                  // L: obj ct func
                break;
            }
            lua_pop(L, 1);                      // L: obj ct nil k
        }                                       // L: obj ct nil|func
    }
    lua_insert(L, -3);                          // L: nil|func obj ct
    lua_pop(L, 2);                              // L: nil|func
    return lua_type(L, -1);
}

OLUA_API void olua_removecallback(lua_State *L, void *obj, const char *tag, int tagmode)
{
    if (!olua_getrawobj(L, obj)) {
        return;
    }
    
    aux_getusertable(L, -1);                    // L: obj ct
    if (tagmode == OLUA_TAG_WHOLE) {
        lua_pushnil(L);                         // L: obj ct nil
        olua_rawsetf(L, -2, tag);               // L: obj ct
    } else {
        lua_pushnil(L);                         // L: obj ct k
        while (lua_next(L, -2)) {               // L: obj ct k v
            if (test_tag_mode(L, -2, tag, tagmode)) {
                lua_pushvalue(L, -2);           // L: obj ct k v k
                lua_pushnil(L);                 // L: obj ct k v k nil
                lua_rawset(L, -5);              // L: obj ct k v
            }
            lua_pop(L, 1);                      // L: obj ct k
        }                                       // L: obj ct
    }
    lua_pop(L, 2);                              // L:
}

OLUA_API int olua_callback(lua_State *L, void *obj, const char *func, int argc)
{
    int top = lua_gettop(L) - argc + 1;
    int status = LUA_ERRRUN;
    olua_pusherrorfunc(L);                      // L: argc errfunc
    if (olua_getcallback(L, obj, func, OLUA_TAG_WHOLE) == LUA_TFUNCTION) {
        for (int i = 0; i < argc; i++) {
            lua_pushvalue(L, -(2 + argc));      // L: argc errfunc func argc
        }
        status = lua_pcall(L, argc, 1, -(2 + argc));
    } else {
        if (olua_getrawobj(L, obj)) {
            lua_pop(L, 1);
            lua_pushfstring(L, "callback missed: %s", func);
        } else {
            lua_pushfstring(L, "object missed: %s", func);
        }
        lua_pcall(L, 1, 0, 0);
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
    olua_getmetatable(L, cls);                  // L: cls
    olua_rawgetf(L, -1, OLUA_CKEY_CLSOBJ);      // L: cls classobj
    lua_replace(L, -2);                         // L: classobj
    olua_assert(olua_isuserdata(L, -1), "expect userdata");
    return lua_touserdata(L, -1);
}

OLUA_API int olua_getvariable(lua_State *L, int idx)
{
    int type = LUA_TNIL;
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    if (lua_getuservalue(L, idx) == LUA_TTABLE) {
        lua_insert(L, -2);                      // L: uv k
        type = olua_rawget(L, -2);              // L: uv v
        lua_replace(L, -2);                     // L: v
    } else {
        lua_pop(L, 2);                          // L:       pop uv and key
        lua_pushnil(L);                         // L: nil
    }
    return type;
}

OLUA_API void olua_setvariable(lua_State *L, int idx)
{
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    aux_getusertable(L, idx);                   // L: k v uv
    lua_insert(L, -3);                          // L: uv k v
    lua_rawset(L, -3);                          // L: uv    idx.uservalue[k] = v
    lua_pop(L, 1);                              // L:
}

static void aux_pushmappingtable(lua_State *L)
{
    if (registry_rawgetp(L, OLUA_MAPPINGTABLE) != LUA_TTABLE) {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_pushvalue(L, -1);
        registry_rawsetp(L, OLUA_MAPPINGTABLE);
    }
}

OLUA_API int olua_ref(lua_State *L, int idx)
{
    if (!olua_isnil(L, idx)) {
        olua_vmstatus_t *vms = aux_getvmstatus(L);
        idx = lua_absindex(L, idx);
        aux_pushmappingtable(L);                // L: reft
        aux_checkref(vms);
        while (olua_rawgeti(L, -1, ++vms->ref) != LUA_TNIL) {
            lua_pop(L, 1);
            aux_checkref(vms);
        }                                       // L: reft nil
        lua_pushvalue(L, idx);                  // L: reft nil value
        lua_rawseti(L, -3, vms->ref);           // L: reft nil       reft[ref] = value
        lua_pop(L, 2);                          // L:
        return vms->ref;
    }
    return LUA_REFNIL;
}

OLUA_API void olua_unref(lua_State *L, int ref)
{
    aux_pushmappingtable(L);                    // L: reft
    lua_pushnil(L);                             // L: reft nil
    lua_rawseti(L, -2, ref);                    // L: reft       reft[ref] = nil
    lua_pop(L, 1);                              // L:
}

OLUA_API void olua_getref(lua_State *L, int ref)
{
    aux_pushmappingtable(L);
    lua_rawgeti(L, -1, ref);
    lua_replace(L, -2);
}

OLUA_API void olua_getreftable(lua_State *L, int idx, const char *name)
{
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    aux_getusertable(L, idx);                   // L: uv
    name = aux_pushrefkey(L, name);             // L: uv holdkey
    luaL_getsubtable(L, -2, name);              // L: uv holdkey holdtable
    lua_insert(L, -3);                          // L: holdtable uv holdkey
    lua_pop(L, 2);                              // L: holdtable
}

static void aux_changeref(lua_State *L, int idx, const char *name, int obj, int flags)
{
    int top = lua_gettop(L);
    idx = lua_absindex(L, idx);
    obj = lua_absindex(L, obj);
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    if (flags & OLUA_FLAG_REMOVE) {
        lua_pushnil(L);
    } else if (flags & OLUA_MODE_SINGLE) {
        olua_assert(olua_isuserdata(L, obj) || olua_isnil(L, obj), "expect userdata or nil");
        lua_pushvalue(L, obj);
    } else {
        lua_pushboolean(L, true);
    }
    if (flags & OLUA_MODE_SINGLE) {
        aux_getusertable(L, idx);               // L: uv
        aux_pushrefkey(L, name);                // L: uv name
        lua_pushvalue(L, top + 1);              // L: uv name obj|nil
        lua_rawset(L, -3);                      // L: uv            uv[name] = obj|nil
    } else if (flags & OLUA_MODE_MULTIPLE) {
        if (olua_isnil(L, obj)) {
            lua_settop(L, top);
            return;
        }
        if (flags & OLUA_FLAG_ARRAY) {
            olua_assert(olua_istable(L, obj), "expect table");
            olua_getreftable(L, idx, name);     // L: ht
            for (int i = 1; i <= (int)lua_rawlen(L, obj); i++) {
                lua_rawgeti(L, obj, i);         // L: ht v
                olua_assert(olua_isuserdata(L, -1), "expect userdata");
                lua_pushvalue(L, top + 1);      // L: ht obj true|nil
                lua_rawset(L, -3);              // L: ht          ht[obj] = true|nil
            }
        } else {
            olua_assert(olua_isuserdata(L, obj), "expect userdata");
            olua_getreftable(L, idx, name);     // L: ht
            lua_pushvalue(L, obj);              // L: ht obj
            lua_pushvalue(L, top + 1);          // L: ht obj true|nil
            lua_rawset(L, -3);                  // L: ht          ht[obj] = true|nil
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
    aux_changeref(L, idx, name, 0, OLUA_MODE_SINGLE | OLUA_FLAG_REMOVE);
}

OLUA_API void olua_visitrefs(lua_State *L, int idx, const char *name, olua_DelRefVisitor walk)
{
    olua_assert(olua_isuserdata(L, idx), "expect userdata");
    idx = lua_absindex(L, idx);
    olua_getreftable(L, idx, name);             // L: t
    lua_pushnil(L);                             // L: t k
    while (lua_next(L, -2)) {                   // L: t k v
        int kidx = lua_gettop(L) - 1;
        if (walk(L, -2)) { // remove?
            lua_pushvalue(L, kidx);             // L: t k v k
            lua_pushnil(L);                     // L: t k v k nil
            lua_rawset(L, kidx - 1);            // L: t k v
        }
        lua_settop(L, kidx);                    // L: t k
    }
    lua_pop(L, 1);
}

static bool lookupfunc(lua_State *L, int t, int kidx)
{
#define NILOBJ ((void *)(uintptr_t)lookupfunc)
    int type;
    olua_assert(t < LUA_REGISTRYINDEX && kidx > 0, "invalid index");
    lua_pushvalue(L, kidx);                     // L: k
    type = olua_rawget(L, t);                   // L: v
    if (olua_unlikely(type == LUA_TNIL)) {
        lua_pop(L, 1);                          // L:
        lua_pushvalue(L, kidx);                 // L: k
        type = olua_gettable(L, t);             // L: v
        lua_pushvalue(L, kidx);                 // L: v k
        if (olua_unlikely(type == LUA_TNIL)) {
            // not found, set tombstone object
            lua_pushlightuserdata(L, NILOBJ);   // L: v k v
        } else {
            // cache in current table
            lua_pushvalue(L, -2);               // L: v k v
        }
        lua_rawset(L, t);                       // L: v
    }
    if (type == LUA_TLIGHTUSERDATA && lua_touserdata(L, -1) == NILOBJ) {
        lua_pop(L, 1);
        type = LUA_TNIL;
    }
    return type != LUA_TNIL;
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
            olua_pusherrorfunc(L);
            lua_insert(L, 1);
            lua_pcall(L, lua_gettop(L) - 2, LUA_MULTRET, 1);
            return lua_gettop(L) - 1;
        } else {
            // unnecessary call __gc on class agent table
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
    
    // try variable
    if (olua_likely(olua_isuserdata(L, 1))) {
        lua_pushvalue(L, 2);
        olua_getvariable(L, 1);
        return 1;
    }
    return 0;
}

static int cls_newindex(lua_State *L)
{
    // try setter
    if (olua_likely(lookupfunc(L, OLUA_CIDX_SET, 2))) {
        if (olua_likely(olua_isuserdata(L, 1))) {
            lua_pushvalue(L, 1);
            lua_pushvalue(L, 3);
            lua_call(L, 2, 0);
        } else {
            // static setter, accessed from class agent
            lua_pushvalue(L, 3);
            lua_call(L, 1, 0);
        }
        return 0;
    }
    
    // store value in .func table
    if (olua_unlikely(olua_istable(L, 1))) {
        lua_settop(L, 3);
        lua_rawset(L, OLUA_CIDX_FUNC);
        return 0;
    }
    
#ifdef OLUA_DEBUG
    if (olua_likely(olua_isstring(L, 2))) {
        size_t len;
        const char *key = olua_tolstring(L, 2, &len);
        if (olua_unlikely(len > 0 && key[0] == '.')) {
            luaL_error(L, "variable name '%s' start with '.' char", key);
        }
    }
#endif
    
    olua_assert(olua_isuserdata(L, 1), "expect userdata");
    lua_settop(L, 3);
    olua_setvariable(L, 1);
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

static void copy_super(lua_State *L, int idx, const char *field, int super)
{
    olua_assert(idx > 0 && super > 0, "invalid index");
    lua_newtable(L);                            // L: t
    if (olua_istable(L, super)) {
        olua_rawgetf(L, super, field);          // L: t fv
        lua_createtable(L, 0, 1);               // L: t fv mt
        lua_pushvalue(L, -2);                   // L: t fv mt fv
        olua_rawsetf(L, -2, "__index");         // L: t fv mt     mt.__index = fv
        lua_setmetatable(L, -3);                // L: t fv        t.metatable = mt
        if (strequal(field, OLUA_CKEY_ISA)) {
            lua_pushnil(L);                     // L: t fv k
            while (lua_next(L, -2)) {           // L: t fv k v
                lua_pushvalue(L, -2);           // L: t fv k v k
                lua_insert(L, -2);              // L: t fv k k v
                lua_rawset(L, -5);              // L: t fv k     t[k] = v
            }                                   // L: t fv
        }
        lua_pop(L, 1);                          // L: t
    }
    lua_pushvalue(L, -1);                       // L: t t
    olua_rawsetf(L, idx, field);                // L: t     idx[field] = t
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
            oluacls_class(L, OLUA_VOIDCLS, NULL);
            oluacls_func(L, "__eq", cls_eq);
            oluacls_func(L, "__tostring", cls_tostring);
            lua_getmetatable(L, -1);
            lua_insert(L, -3);
            lua_pop(L, 2);      // pop nil and class agent
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
          "__concat", "__call", NULL
        };
        
        int idx = lua_gettop(L);
        lua_pop(L, 1);
        luaL_newmetatable(L, cls);                      // L: mt
        copy_super(L, idx, OLUA_CKEY_ISA, super);       // L: mt .isa
        copy_super(L, idx, OLUA_CKEY_FUNC, super);      // L: mt .isa .func
        copy_super(L, idx, OLUA_CKEY_GET, super);       // L: mt .isa .func .get
        copy_super(L, idx, OLUA_CKEY_SET, super);       // L: mt .isa .func .get .set
        luaL_setfuncs(L, lib,  4);                      // L: mt
        
        // init meta method and isa
        olua_rawgetf(L, idx, OLUA_CKEY_FUNC);           // L: mt .func
        for (const char **e = events; *e != NULL; e++) {
            lua_pushvalue(L, -1);                       // L: mt .func .func
            lua_pushstring(L, *e);                      // L: mt .func .func e
            lua_pushboolean(L, strequal(*e, "__gc"));   // L: mt .func .func e isgc
            lua_pushcclosure(L, cls_metamethod, 3);     // L: mt .func metamethod
            olua_rawsetf(L, -3, *e);                    // L: mt .func      mt[e] = metamethod
        }
        olua_rawgetf(L, idx, OLUA_CKEY_ISA);            // L: mt .func .isa
        olua_setfieldboolean(L, -1, cls, true);         // L: mt .func .isa  mt[.isa][cls] = true
        lua_pop(L, 2);                                  // L: mt
        
        // create class object, store static function callback
        lua_newuserdata(L, sizeof(void *));             // L: mt clsobj
        lua_createtable(L, 0, 1);                       // L: mt clsobj t
        lua_pushvalue(L, -1);                           // L: mt clsobj t t
        olua_rawsetf(L, -2, "__index");                 // L: mt clsobj t        t.__index = t
        olua_setfieldstring(L, -1, "classname", cls);   // L: mt clsobj t        t.classname = cls
        lua_setmetatable(L, -2);                        // L: mt clsobj          clsobj.mt = t
        lua_pushvalue(L, -1);                           // L: mt clsobj clsobj
        olua_rawsetf(L, idx, OLUA_CKEY_CLSOBJ);         // L: mt clsobj          mt[.classobj] = clsobj
        aux_pushobjtable(L);                            // L: mt clsobj objs
        lua_pushvalue(L, -2);                           // L: mt clsobj objs clsobj
        olua_rawsetp(L, -2, lua_touserdata(L, -1));     // L: mt clsobj objs     objs[clsobj_ptr] = clsobj
        lua_pop(L, 2);                                  // L: mt
        
        // create class agent
        lua_createtable(L, 0, 0);                       // L: mt agent
        lua_pushvalue(L, idx);                          // L: mt agent mt
        lua_setmetatable(L, -2);                        // L: mt agent      agent.metatable = mt
        oluacls_const_value(L, "class", idx);           // L: mt agent      mt.class = mt
        oluacls_const_string(L, "classname", cls);      // L: mt agent      mt.classname = cls
        oluacls_const_string(L, "classtype", "native"); // L: mt agent      mt.classtype = native
        if (supercls) {
            olua_rawgetf(L, super, OLUA_CKEY_CLSAGENT); // L: mt agent super_agent
            oluacls_const(L, "super");                  // L: mt agent      agent.super = super_agent
        }
        olua_rawsetf(L, idx, OLUA_CKEY_CLSAGENT);       // L: mt        mt[.classagent] = agent
    }
    olua_rawgetf(L, -1, OLUA_CKEY_CLSAGENT);
    lua_replace(L, super);
    lua_settop(L, super);
}

static void aux_setfunc(lua_State *L, const char *t, const char *name, lua_CFunction func, int n)
{
    olua_assert(func, "function can't be NULL");
    lua_pushcclosure(L, func, n);               // L: agent func
    lua_getmetatable(L, -2);                    // L: agent func cls
    olua_rawgetf(L, -1, t);                     // L: agent func cls t
    lua_pushvalue(L, -3);                       // L: agent func cls t func
    olua_rawsetf(L, -2, name);                  // L: agent func cls t   t[name] = func
    lua_pop(L, 3);                              // L: agent
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
    aux_setfunc(L, OLUA_CKEY_GET, name, cls_const, 1);
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
        luaL_argerror(L, idx, msg);
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
    luaL_checktype(L, 1, LUA_TUSERDATA);
    luaL_checktype(L, 3, LUA_TFUNCTION);
    const char *cls = olua_checkstring(L, 2);
    if (!lua_getmetatable(L, 1)) {              // L: obj cls func mt
        lua_pushnil(L);                         // L: obj cls func nil
    }
    
    if (olua_getmetatable(L, cls) == LUA_TTABLE) {
        lua_setmetatable(L, 1);
    } else {
        luaL_error(L, "metatable not found: %s", cls);
    }
    
    lua_pushvalue(L, 3);                        // L: obj cls func mt func
    lua_pushvalue(L, 1);                        // L: obj cls func mt func obj
    olua_pcall(L, 1, 0);                        // L: obj cls func mt
    lua_setmetatable(L, 1);                     // L: obj cls func
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
    lua_pushstring(L, ".ownership");
    lua_pushnil(L);
    olua_setvariable(L, 1);
    return 0;
}

static int l_move(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TUSERDATA);
    lua_getfield(L, 1, "__move");
    if (!olua_isfunction(L, -1)) {
        luaL_error(L, "method '__move' not found in '%s'", olua_objstring(L, 1));
    }
    lua_insert(L, 1);
    lua_call(L, lua_gettop(L) - 1, LUA_MULTRET);
    return lua_gettop(L);
}

static int l_debug(lua_State *L)
{
    if (olua_isnil(L, 1)) {
        lua_pushboolean(L, aux_getvmstatus(L)->debug);
        return 1;
    } else {
        aux_getvmstatus(L)->debug = olua_checkboolean(L, 1);
        return 0;
    }
}

static int l_class(lua_State *L)
{
    const char *cls = olua_checkstring(L, 1);
    const char *super = olua_optstring(L, 2, OLUA_VOIDCLS);
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

OLUA_API int luaopen_olua(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"with", l_with},
        {"isa", l_isa},
        {"take", l_take},
        {"move", l_move},
        {"debug", l_debug},
        {"class", l_class},
        {"setmetatable", l_setmetatable},
        {"getmetatable", l_getmetatable},
        {"topointer", l_topointer},
        {NULL, NULL}
    };
    
    luaL_newlib(L,lib);
    
    return 1;
}

#if LUA_VERSION_NUM == 501
#define HAVE_USERVALUE ((void *)(uintptr_t)lua_getuservalue)

OLUA_API void lua_setuservalue(lua_State *L, int idx)
{
    if (lua_type(L, -1) != LUA_TNIL) {
        luaL_checktype(L, -1, LUA_TTABLE);
        lua_pushboolean(L, true);
        olua_rawsetp(L, -2, HAVE_USERVALUE);
    } else {
        lua_pop(L, 1);
        lua_pushvalue(L, LUA_GLOBALSINDEX);
    }
    lua_setfenv(L, idx);
}

OLUA_API int lua_getuservalue(lua_State *L, int idx)
{
    lua_getfenv(L, idx);
    if (olua_rawgetp(L, -1, HAVE_USERVALUE) == LUA_TNIL) {
        lua_remove(L, -2);
        return LUA_TNIL;
    } else {
        lua_pop(L, 1);
        return lua_type(L, -1);
    }
}

OLUA_API int lua_absindex(lua_State *L, int idx)
{
    return (idx > 0 || idx <= LUA_REGISTRYINDEX) ?
        idx : (idx + 1 + lua_gettop(L));
}

OLUA_API int lua_isinteger(lua_State *L, int idx)
{
    if (olua_isnumber(L, idx)) {
        lua_Number n = lua_tonumber(L, idx);
        return n == (lua_Number)(floor(n));
    }
    return false;
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

OLUA_API void olua_checkcompat(lua_State *L)
{
    int top = lua_gettop(L);
    lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
    if (lua_type(L, -1) != LUA_TTHREAD) {
        luaL_error(L, "main thread not set");
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_GLOBALS);
    if (lua_type(L, -1) != LUA_TTABLE) {
        luaL_error(L, "global table not set");
    }
    if (!lua_rawequal(L, -1, LUA_GLOBALSINDEX)) {
        luaL_error(L, "global table not match");
    }
    lua_settop(L, top);
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
