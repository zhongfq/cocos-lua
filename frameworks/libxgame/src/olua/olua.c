/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 codetypes@gmail.com
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

#define CLS_ISAIDX  (lua_upvalueindex(1))
#define CLS_FUNCIDX (lua_upvalueindex(2))
#define CLS_GETIDX  (lua_upvalueindex(3))
#define CLS_SETIDX  (lua_upvalueindex(4))
#define CLS_ISA     ".isa"
#define CLS_FUNC    ".func"
#define CLS_GET     ".get"
#define CLS_SET     ".set"
#define CLS_STORE   ".store" // static store for cls
#define CLS_AGENT   ".agent"

#define OLUA_OBJ_TABLE  ((void *)olua_pushobj)
#define OLUA_POOL_TABLE ((void *)aux_pushlocalobj)
#define OLUA_REF_TABLE  ((void *)aux_getreftable)
#define OLUA_VMSTATUS   ((void *)olua_vmstatus)

#define strequal(s1, s2)        (strcmp((s1), (s2)) == 0)
#define strstartwith(s1, s2)    (strstr((s1), (s2)) == s1)
#define aux_pushholdkey(L, n)   (lua_pushfstring(L, ".hold.%s", (n)))

static int errfunc(lua_State *L)
{
    if (olua_isthread(L, 1)) {
        olua_traceback(L, lua_tothread(L, 1), lua_tostring(L, 2), 0);
        lua_insert(L, 1);
    }
    olua_traceback(L, L, lua_tostring(L, 1), 1);
    printf("%s\n", lua_tostring(L, -1));
    return 0;
}

OLUA_API olua_vmstatus_t *olua_vmstatus(lua_State *L)
{
    olua_vmstatus_t *vms;
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_VMSTATUS) == LUA_TNIL) {
        lua_pop(L, 1);
        vms = (olua_vmstatus_t *)lua_newuserdata(L, sizeof(*vms));
        vms->debug = false;
        vms->poolenabled = false;
        vms->objcount = 0;
        vms->poolsize = 0;
        olua_rawsetp(L, LUA_REGISTRYINDEX, OLUA_VMSTATUS);
    } else {
        vms = (olua_vmstatus_t *)lua_touserdata(L, -1);
        lua_pop(L, 1);
    }
    return vms;
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
    if (!(olua_isnoneornil(L, idx) || olua_isboolean(L, idx))) {
        luaL_checktype(L, idx, LUA_TBOOLEAN);
    }
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
    lua_rawset(L, idx);
}

OLUA_API int olua_geterrorfunc(lua_State *L)
{
    if (olua_getglobal(L, "__TRACEBACK__") != LUA_TFUNCTION) {
        lua_pop(L, 1);
        lua_pushcfunction(L, errfunc);
    }
    return lua_gettop(L);
}

OLUA_API int olua_pcall(lua_State *L, int nargs, int nresults)
{
    int status;
    int errfunc = lua_absindex(L, -(nargs + 1));
    olua_geterrorfunc(L);
    lua_insert(L, errfunc);
    status = lua_pcall(L, nargs, nresults, errfunc);
    lua_remove(L, errfunc);
    return status;
}

OLUA_API int olua_pcallref(lua_State *L, int funcref, int nargs, int nresults)
{
    olua_getref(L, funcref);
    olua_assert(lua_isfunction(L, -1));
    lua_insert(L, -(nargs + 1));
    return olua_pcall(L, nargs, nresults);
}

OLUA_API void olua_require(lua_State *L, const char *name, lua_CFunction func)
{
    int top = lua_gettop(L);
    olua_requiref(L, name, func, false);
    lua_settop(L, top);
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
    if (olua_isuserdata(L, idx) && lua_getmetatable(L, idx)) {
        if (olua_rawgetf(L, -1, CLS_ISA) == LUA_TTABLE) {
            olua_rawgetf(L, -1, cls);
            isa = olua_toboolean(L, -1);
        }
    }
    lua_settop(L, top);
    return isa;
}

static void aux_getobjtable(lua_State *L)
{
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_OBJ_TABLE) != LUA_TTABLE) {
        lua_pop(L, 1);                              // pop nil
        lua_newtable(L);
        olua_setfieldstring(L, -1, "__mode", "v");  // mt.__mode = 'v'
        lua_pushvalue(L, -1);
        lua_setmetatable(L, -2);                    // mt.metatable = mt
        lua_pushvalue(L, -1);
        olua_rawsetp(L, LUA_REGISTRYINDEX, OLUA_OBJ_TABLE);
    }
}

static void aux_pushlocalobj(lua_State *L, void *obj)
{
    olua_vmstatus_t *mt = olua_vmstatus(L);
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_POOL_TABLE) != LUA_TTABLE) {
        lua_pop(L, 1);
        lua_createtable(L, 16, 0);
        lua_pushvalue(L, -1);
        olua_rawsetp(L, LUA_REGISTRYINDEX, OLUA_POOL_TABLE);
    }
    
    if (olua_rawgeti(L, -1, ++mt->poolsize) != LUA_TUSERDATA) {
        lua_pop(L, 1);
        lua_newuserdata(L, sizeof(void *));
        lua_pushvalue(L, -1);
        olua_rawseti(L, -3, mt->poolsize);
    }
    
    lua_remove(L, -2);  // rm pool table
    olua_setuserdata(L, -1, obj);
}

OLUA_API int olua_pushobj(lua_State *L, void *obj, const char *cls)
{
    int status = OLUA_OBJ_EXIST;
    
    if (!obj) {
        lua_pushnil(L);
        return status;
    }
    
    if (!cls || olua_getmetatable(L, cls) != LUA_TTABLE) {
        luaL_error(L, "class '%s' not found", cls ? cls : "NULL");
    }
    
    aux_getobjtable(L);                             // L: mt objtable
    
    if (olua_rawgetp(L, -1, obj) == LUA_TNIL) {     // L: mt objtable ud?
        lua_pop(L, 1);                              // L: mt objtable
        if (olua_vmstatus(L)->poolenabled) {
            aux_pushlocalobj(L, obj);
            status = OLUA_OBJ_EXIST;
        } else {
            olua_newuserdata(L, obj, void *);       // L: mt objtable ud
            lua_pushvalue(L, -1);                   // L: mt objtable ud ud
            olua_rawsetp(L, -3, obj);               // L: mt objtable ud     objtable[obj] = ud
            status = OLUA_OBJ_NEW;
        }
        lua_pushvalue(L, -3);                       // L: mt objtable ud mt
        lua_setmetatable(L, -2);                    // L: mt objtable ud     ud.metatable = mt
    } else if (!strequal(cls, OLUA_VOIDCLS)
            && olua_testudata(L, -1, OLUA_VOIDCLS)) {
        lua_pushvalue(L, -3);                       // L: mt objtable ud mt
        lua_setmetatable(L, -2);                    // L: mt objtable ud     ud.metatable = mt
        status = OLUA_OBJ_NEW;
    }
    
    lua_insert(L, -3);                              // L: ud mt objtable
    lua_pop(L, 2);                                  // L: ud
    
    return status;
}

OLUA_API bool olua_getuserdata(lua_State *L, void *obj)
{
    if (!obj) {
        return false;
    }
    aux_getobjtable(L);                             // L: objt
    if (olua_rawgetp(L, -1, obj) == LUA_TUSERDATA) {// L: objt obj
        lua_remove(L, -2);                          // L: obj
        return true;
    } else {
        lua_pop(L, 2);
        return false;
    }
}

static void *aux_toobj(lua_State *L, int idx, const char *cls, bool checked)
{
    if (olua_isuserdata(L, idx) && (!checked || olua_isa(L, idx, cls))) {
        void *obj = olua_touserdata(L, idx, void *);
        if (obj) {
            return obj;
        } else {
            luaL_error(L, "object '%s' survive from gc", olua_typename(L, idx));
        }
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
    intptr_t p;
    const char *tn = olua_typename(L, idx);
    if (olua_isuserdata(L, idx)) {
        p = (intptr_t)olua_touserdata(L, idx, void *);
    } else {
        p = (intptr_t)lua_topointer(L, idx);
    }
    return lua_pushfstring(L, "%s: %p", tn, p);
}

OLUA_API void olua_pop_objpool(lua_State *L, size_t level)
{
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_POOL_TABLE) == LUA_TTABLE) {
        size_t len = lua_rawlen(L, -1);
        olua_assert(level < len);
        olua_vmstatus(L)->poolsize = level;
        for (size_t i = level + 1; i <= len; i++) {
            olua_rawgeti(L, -1, (lua_Integer)i);
            void **ud = (void **)lua_touserdata(L, -1);
            lua_pushnil(L);
            lua_setmetatable(L, -2);
            lua_pushnil(L);
            lua_setuservalue(L, -2);
            lua_pop(L, 1);
            if (*ud != NULL) {
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
    if (lua_getuservalue(L, idx) != LUA_TTABLE) {
        olua_assert(olua_isnil(L, -1));
        lua_pop(L, 1);
        idx = lua_absindex(L, idx);
        lua_createtable(L, 0, 4);
        lua_pushvalue(L, -1);
        lua_setuservalue(L, idx);
    }
}

static bool test_tag_mode(lua_State *L, int idx, const char *tag, int mode)
{
    static const char *const names[] = {"new", "replace", "whole", "subequal", "substartwith"};
    if (olua_isstring(L, idx)) {
        const char *field = olua_tostring(L, idx);
        if ((field = strchr(field, '@')) != NULL) {
            ++field; // skip '@'
            if (mode == OLUA_TAG_SUBSTARTWITH) {
                return strstartwith(field, tag);
            } else if (mode == OLUA_TAG_SUBEQUAL || mode == OLUA_TAG_REPLACE) {
                return strequal(field, tag);
            } else {
                luaL_error(L, "unexpected tag mode '%s'", names[mode]);
            }
        }
    }
    return false;
}

OLUA_API const char *olua_setcallback(lua_State *L, void *obj, const char *tag, int func, int mode)
{
    const char *cls = NULL;
    func = lua_absindex(L, func);
    luaL_checktype(L, func, LUA_TFUNCTION);
    
    if (!olua_getuserdata(L, obj)) {                    // L: obj
        luaL_error(L, "obj userdata not found");
    } else {
        olua_getfield(L, -1, "classname");
        cls = olua_optstring(L, -1, "<NONAME>");
        lua_pop(L, 1);
    }
    
    aux_getusertable(L, -1);                            // L: obj ct
    lua_remove(L, -2);                                  // L: ct
    
    if (mode == OLUA_TAG_REPLACE) {
        lua_pushnil(L);                                 // L: ct k
        while (lua_next(L, -2)) {                       // L: ct k v
            if (test_tag_mode(L, -2, tag, mode)) {
                lua_pop(L, 1);                          // L: ct k
                break;
            }
            lua_pop(L, 1);                              // L: ck k
        }
    }
    
    if (!olua_isstring(L, -1)) {
        static unsigned int ref = 0;
        lua_pushfstring(L, ".callback#%d$%s@%s", ++ref, cls, tag);
    }
    
    lua_pushvalue(L, -1);                               // L: ct k k
    lua_pushvalue(L, func);                             // L: ct k k v
    lua_rawset(L, -4);                                  // L: ct k
    lua_remove(L, -2);                                  // L: k
    return olua_tostring(L, -1);
}

OLUA_API int olua_getcallback(lua_State *L, void *obj, const char *tag, int mode)
{
    if (!olua_getuserdata(L, obj)) {
        lua_pushnil(L);
        return LUA_TNIL;
    }
    
    aux_getusertable(L, -1);                            // L: obj ct
    
    if (mode == OLUA_TAG_WHOLE) {
        olua_rawgetf(L, -1, tag);                       // L: obj ct func
    } else {
        lua_pushnil(L);                                 // L: obj ct nil
        lua_pushnil(L);                                 // L: obj ct nil k
        while (lua_next(L, -3)) {                       // L: obj ct nil k func
            if (test_tag_mode(L, -2, tag, mode)) {
                lua_replace(L, -3);                     // L: obj ct func k
                lua_pop(L, 1);                          // L: obj ct func
                break;
            }
            lua_pop(L, 1);                              // L: obj ct nil k
        }                                               // L: obj ct nil|func
    }
    lua_insert(L, -3);                                  // L: nil|func obj ct
    lua_pop(L, 2);                                      // L: nil|func
    return lua_type(L, -1);
}

OLUA_API void olua_removecallback(lua_State *L, void *obj, const char *tag, int mode)
{
    if (!olua_getuserdata(L, obj)) {
        return;
    }
    
    aux_getusertable(L, -1);                            // L: obj ct
    if (mode == OLUA_TAG_WHOLE) {
        lua_pushnil(L);                                 // L: obj ct nil
        olua_rawsetf(L, -2, tag);                       // L: obj ct
    } else {
        lua_pushnil(L);                                 // L: obj ct k
        while (lua_next(L, -2)) {                       // L: obj ct k v
            if (test_tag_mode(L, -2, tag, mode)) {
                lua_pushvalue(L, -2);                   // L: obj ct k v k
                lua_pushnil(L);                         // L: obj ct k v k nil
                lua_rawset(L, -5);                      // L: obj ct k v
            }
            lua_pop(L, 1);                              // L: obj ct k
        }                                               // L: obj ct
    }
    lua_pop(L, 2);                                      // L:
}

OLUA_API int olua_callback(lua_State *L, void *obj, const char *func, int argc)
{
    int top = lua_gettop(L) - argc;
    int status = OLUA_CALL_MISS;
    
    if (olua_getcallback(L, obj, func, OLUA_TAG_WHOLE) == LUA_TFUNCTION) {
        lua_insert(L, top + 1);                         // L: callback arg...n
        olua_geterrorfunc(L);                           // L: callback arg...n errfunc
        lua_insert(L, top + 1);                         // L: errfunc callback arg...n
        if (lua_pcall(L, argc, 1, top + 1) == LUA_OK) { // L: errfunc result
            status = OLUA_CALL_OK;
        } else {
            status = OLUA_CALL_ERR;
        }
        lua_remove(L, -2);                              // L: result
    }

    if (status != OLUA_CALL_OK) {
        if (status == OLUA_CALL_MISS) {
            olua_geterrorfunc(L);
            lua_pushfstring(L, "callback missed: %s", func);
            lua_pcall(L, 1, 0, 0);
        }
        lua_settop(L, top);
        lua_pushnil(L);
    }
    
    return status;
}

OLUA_API void *olua_pushclassobj(lua_State *L, const char *cls)
{
    olua_getmetatable(L, cls);                  // L: cls
    olua_rawgetf(L, -1, CLS_STORE);             // L: cls store
    lua_remove(L, -2);                          // L: store
    olua_assert(olua_isuserdata(L, -1));
    return lua_touserdata(L, -1);
}

OLUA_API int olua_getvariable(lua_State *L, int idx)
{
    int type = LUA_TNIL;
    olua_assert(olua_isuserdata(L, idx));
    if (lua_getuservalue(L, idx) == LUA_TTABLE) {   // L: k uv
        lua_insert(L, -2);                          // L: uv k
        type = olua_rawget(L, -2);                  // L: uv v
        lua_remove(L, -2);                          // L: v
    } else {
        lua_pop(L, 2);                              // L:
        lua_pushnil(L);                             // L: nil
    }
    return type;
}

OLUA_API void olua_setvariable(lua_State *L, int idx)
{
    olua_assert(olua_isuserdata(L, idx));
    aux_getusertable(L, idx);       // L: k v uv
    lua_insert(L, -3);              // L: uv k v
    lua_rawset(L, -3);              // L: uv          idx.uservalue[k] = v
    lua_pop(L, 1);                  // L:
}

static void aux_getreftable(lua_State *L)
{
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_REF_TABLE) != LUA_TTABLE) {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_pushvalue(L, -1);
        olua_rawsetp(L, LUA_REGISTRYINDEX, OLUA_REF_TABLE);
    }
}

OLUA_API int olua_ref(lua_State *L, int idx)
{
    static int ref = 0;
    if (!olua_isnil(L, idx)) {
        idx = lua_absindex(L, idx);
        aux_getreftable(L);         // L: reft
        while (olua_rawgeti(L, -1, ++ref) != LUA_TNIL) {
            lua_pop(L, 1);
            ref = ref < 0 ? 0 : ref;
        }                           // L: reft nil
        lua_pushvalue(L, idx);      // L: reft nil value
        lua_rawseti(L, -3, ref);    // L: reft nil       reft[ref] = value
        lua_pop(L, 2);              // L:
        return ref;
    }
    return LUA_REFNIL;
}

OLUA_API int olua_reffunc(lua_State *L, int idx)
{
    luaL_checktype(L, idx, LUA_TFUNCTION);
    return olua_ref(L, idx);
}

OLUA_API void olua_unref(lua_State *L, int ref)
{
    aux_getreftable(L);             // L: reft
    lua_pushnil(L);                 // L: reft nil
    lua_rawseti(L, -2, ref);        // L: reft       reft[ref] = nil
    lua_pop(L, 1);                  // L:
}

OLUA_API void olua_getref(lua_State *L, int ref)
{
    aux_getreftable(L);
    lua_rawgeti(L, -1, ref);
    lua_remove(L, -2);
}

OLUA_API void olua_getreftable(lua_State *L, int idx, const char *name)
{
    olua_assert(olua_isuserdata(L, idx));
    aux_getusertable(L, idx);               // L: uv
    name = aux_pushholdkey(L, name);        // L: uv holdkey
    olua_getsubtable(L, -2, name);          // L: uv holdkey holdtable
    lua_insert(L, -3);                      // L: holdtable uv holdkey
    lua_pop(L, 2);                          // L: holdtable
}

static void aux_changeref(lua_State *L, int idx, const char *name, int obj, int flags)
{
    int top = lua_gettop(L);
    idx = lua_absindex(L, idx);
    obj = lua_absindex(L, obj);
    olua_assert(olua_isuserdata(L, idx));
    if (flags & OLUA_FLAG_REMOVE) {
        lua_pushnil(L);
    } else if (flags & OLUA_FLAG_EXCLUSIVE) {
        olua_assert(olua_isuserdata(L, obj) || olua_isnil(L, obj));
        lua_pushvalue(L, obj);
    } else {
        lua_pushboolean(L, true);
    }
    if (flags & OLUA_FLAG_EXCLUSIVE) {
        aux_getusertable(L, idx);               // L: uv
        aux_pushholdkey(L, name);               // L: uv name
        lua_pushvalue(L, top + 1);              // L: uv name obj|nil
        lua_rawset(L, -3);                      // L: uv            uv[name] = obj|nil
    } else if (flags & OLUA_FLAG_COEXIST) {
        olua_assert(olua_isuserdata(L, obj));
        olua_getreftable(L, idx, name);         // L: ht
        lua_pushvalue(L, obj);                  // L: ht obj
        lua_pushvalue(L, top + 1);              // L: ht obj true|nil
        lua_rawset(L, -3);                      // L: ht          ht[obj] = true|nil
    } else if (flags & OLUA_FLAG_ARRAY) {
        olua_assert(olua_istable(L, obj));
        olua_getreftable(L, idx, name);         // L: ht
        for (int i = 1; i <= (int)lua_rawlen(L, obj); i++) {
            lua_rawgeti(L, obj, i);             // L: ht v
            olua_assert(olua_isuserdata(L, -1));
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
    aux_changeref(L, idx, name, 0, OLUA_FLAG_EXCLUSIVE | OLUA_FLAG_REMOVE);
}

OLUA_API void olua_visitrefs(lua_State *L, int idx, const char *name, olua_DelRefVisitor walk)
{
    olua_assert(olua_isuserdata(L, idx));
    idx = lua_absindex(L, idx);
    olua_getreftable(L, idx, name);         // L: t
    lua_pushnil(L);                         // L: t k
    while (lua_next(L, -2)) {               // L: t k v
        int kidx = lua_gettop(L) - 1;
        if (walk(L, -2)) { // remove?
            lua_pushvalue(L, kidx);         // L: t k v k
            lua_pushnil(L);                 // L: t k v k nil
            lua_rawset(L, kidx - 1);        // L: t k v
        }
        lua_settop(L, kidx);                // L: t k
    }
    lua_pop(L, 1);
}

static int lookupfunc(lua_State *L, int t, int kidx)
{
#define NOTFOUND ((void *)lookupfunc)
    int type;
    olua_assert(t <= LUA_REGISTRYINDEX && kidx > 0);
    lua_pushvalue(L, kidx);                     // L: k
    type = olua_rawget(L, t);                   // L: v
    if (type == LUA_TNIL) {
        lua_pop(L, 1);                          // L:
        lua_pushvalue(L, kidx);                 // L: k
        type = olua_gettable(L, t);             // L: v
        lua_pushvalue(L, kidx);                 // L: v k
        if (type == LUA_TNIL) {
            lua_pushlightuserdata(L, NOTFOUND); // L: v k v
        } else {
            lua_pushvalue(L, -2);               // L: v k v
        }
        lua_rawset(L, t);                       // L: v
    }
    if (type == LUA_TLIGHTUSERDATA && lua_touserdata(L, -1) == NOTFOUND) {
        lua_pop(L, 1);
        lua_pushnil(L);
        type = LUA_TNIL;
    }
    return type;
}

static int cls_metamethod(lua_State *L)
{
    // 1: CLS_FUNC   2: name   3: isgc
    bool isgc = olua_toboolean(L, lua_upvalueindex(3));
    lua_pushvalue(L, lua_upvalueindex(2));
    if (lookupfunc(L, lua_upvalueindex(1), lua_gettop(L)) == LUA_TFUNCTION) {
        lua_replace(L, -2);
        lua_insert(L, 1);
        if (!isgc) {
            lua_call(L, lua_gettop(L) - 1, LUA_MULTRET);
            return lua_gettop(L);
        } else if (olua_isuserdata(L, 2)) {
            olua_geterrorfunc(L);
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
    if (lookupfunc(L, CLS_GETIDX, 2) != LUA_TNIL) {
        lua_pushvalue(L, 1);                        // L: t k getter t
        lua_call(L, 1, 1);                          // L: t k ret
        return 1;
    }
    
    // try func
    if (lookupfunc(L, CLS_FUNCIDX, 2) != LUA_TNIL) {
        return 1;
    }
    
    // try variable
    if (olua_isuserdata(L, 1)) {
        lua_pushvalue(L, 2);
        olua_getvariable(L, 1);
        return 1;
    }
    return 0;
}

static int cls_newindex(lua_State *L)
{
    // try setter
    if (lookupfunc(L, CLS_SETIDX, 2) != LUA_TNIL) {
        if (olua_isuserdata(L, 1)) {
            lua_pushvalue(L, 1);                // L: t k v setter t
            lua_pushvalue(L, 3);                // L: t k v setter t v
            lua_call(L, 2, 0);                  // L: t k v
        } else {
            // static setter, accessed from class agent
            lua_pushvalue(L, 3);                // L: t k v setter v
            lua_call(L, 1, 0);                  // L: t k v
        }
        return 0;
    }
    
    if (olua_istable(L, 1)) {
        lua_settop(L, 3);                       // L: t k v
        lua_rawset(L, CLS_FUNCIDX);             // L: t
        return 0;
    }
    
    if (lookupfunc(L, CLS_GETIDX, 2) != LUA_TNIL) {
        luaL_error(L, "readonly property: %s", olua_tostring(L, 2));
    }
    
    if (olua_isstring(L, 2)) {
        size_t len;
        const char *key = olua_tolstring(L, 2, &len);
        if (len > 0 && key[0] == '.') {
            luaL_error(L, "variable name '%s' start with '.' char", key);
        }
    }
    
    olua_assert(olua_isuserdata(L, 1));
    lua_settop(L, 3);
    olua_setvariable(L, 1);
    return 0;
}

static int cls_tostring(lua_State *L)
{
    olua_objstring(L, 1);
    return 1;
}

static void create_table(lua_State *L, int idx, const char *field, const char *supercls, bool copy)
{
    idx = lua_absindex(L, idx);
    lua_newtable(L);                        // L: t
    if (supercls) {
        olua_getmetatable(L, supercls);     // L: t super
        olua_rawgetf(L, -1, field);         // L: t super fv
        lua_createtable(L, 0, 1);           // L: t super fv mt
        lua_pushvalue(L, -2);               // L: t super fv mt fv
        olua_rawsetf(L, -2, "__index");     // L: t super fv mt     mt.__index = fv
        lua_setmetatable(L, -4);            // L: t super fv        t.metatable = mt
        
        if (copy) {
            lua_pushnil(L);                 // L: t super fv k
            while (lua_next(L, -2)) {       // L: t super fv k v
                lua_pushvalue(L, -2);       // L: t super fv k v k
                lua_insert(L, -2);          // L: t super fv k k v
                lua_rawset(L, -6);          // L: t super fv k     t[k] = v
            }                               // L: t super fv
        }
        
        lua_pop(L, 2);                      // L: t
    }
    
    lua_pushvalue(L, -1);                   // L: t t
    olua_rawsetf(L, idx, field);            // L: t     idx[field] = t
}

OLUA_API void oluacls_class(lua_State *L, const char *cls, const char *super)
{
    if (super != NULL) {
        if (olua_getmetatable(L, super) == LUA_TNIL) {
            luaL_error(L, "super class not found: %s => %s ", cls, super);
        }
        lua_pop(L, 1);
    } else if (!strequal(cls, OLUA_VOIDCLS)) {
        oluacls_class(L, OLUA_VOIDCLS, NULL);
        lua_pop(L, 1);
        super = OLUA_VOIDCLS;
    }
    
    if (olua_getmetatable(L, cls) == LUA_TNIL) {
        static const luaL_Reg lib[] = {
            {"__index", cls_index},
            {"__newindex", cls_newindex},
            {"__tostring", cls_tostring},
            {NULL, NULL}
        };
        static const char *events[] = {
          "__gc", "__len", "__eq",
          "__add", "__sub", "__mul", "__mod", "__pow",
          "__div", "__idiv",
          "__band", "__bor", "__bxor", "__shl", "__shr",
          "__unm", "__bnot", "__lt", "__le",
          "__concat", "__call", NULL
        };
        
        int idx = lua_gettop(L);
        lua_pop(L, 1);
        luaL_newmetatable(L, cls);                      // L: mt
        create_table(L, idx, CLS_ISA, super, true);     // L: mt .isa
        create_table(L, idx, CLS_FUNC, super, false);   // L: mt .isa .func
        create_table(L, idx, CLS_GET, super, false);    // L: mt .isa .func .get
        create_table(L, idx, CLS_SET, super, false);    // L: mt .isa .func .get .set
        olua_setfuncs(L, lib,  4);                      // L: mt
        
        // init meta method and isa
        olua_rawgetf(L, -1, CLS_FUNC);                  // L: mt .func
        for (const char **e = events; *e != NULL; e++) {
            lua_pushvalue(L, -1);                       // L: mt .func .func
            lua_pushstring(L, *e);                      // L: mt .func .func e
            lua_pushboolean(L, strequal(*e, "__gc"));   // L: mt .func .func e isgc
            lua_pushcclosure(L, cls_metamethod, 3);     // L: mt .func metamethod
            olua_rawsetf(L, -3, *e);                    // L: mt .func      mt[e] = metamethod
        }
        olua_rawgetf(L, idx, CLS_ISA);                  // L: mt .func .isa
        olua_setfieldboolean(L, -1, cls, true);         // L: mt .func .isa  mt[.isa][cls] = true
        lua_pop(L, 2);                                  // L: mt
        
        // create class store, for store static function callback
        lua_newuserdata(L, sizeof(void *));             // L: mt store
        lua_createtable(L, 0, 1);                       // L: mt store t
        lua_pushvalue(L, -1);                           // L: mt store t t
        olua_rawsetf(L, -2, "__index");                 // L: mt store t        t.__index = t
        olua_setfieldstring(L, -1, "classname", cls);   // L: mt store t        t.classname = cls
        lua_setmetatable(L, -2);                        // L: mt store          store.mt = t
        lua_pushvalue(L, -1);                           // L: mt store store
        olua_rawsetf(L, -3, CLS_STORE);                 // L: mt store          mt[.store] = store
        aux_getobjtable(L);                             // L: mt store objs
        lua_pushvalue(L, -2);                           // L: mt store objs store
        olua_rawsetp(L, -2, lua_touserdata(L, -1));     // L: mt store objs     objs[store_ptr] = store
        lua_pop(L, 2);                                  // L: mt
        
        // create class agent
        lua_createtable(L, 0, 0);                       // L: mt agent
        lua_pushvalue(L, -2);                           // L: mt agent mt
        lua_setmetatable(L, -2);                        // L: mt agent      agent.metatable = mt
        
        oluacls_const_value(L, "class", idx);           // mt.class = mt
        oluacls_const_string(L, "classname", cls);      // mt.classname = cls
        oluacls_const_string(L, "classtype", "native"); // mt.classtype = native
        if (super) {
            olua_getmetatable(L, super);
            olua_rawgetf(L, -1, CLS_AGENT);
            lua_replace(L, -2);
            oluacls_const(L, "super");                  // mt.super = super agent
        }
        
        olua_rawsetf(L, -2, CLS_AGENT);                 // L: mt        mt[agent] = agent
    }
    olua_rawgetf(L, -1, CLS_AGENT);
    lua_replace(L, -2);
}

static void aux_setfunc(lua_State *L, const char *t, const char *name, lua_CFunction func, int n)
{
    if (func) {                         // L: agent
        lua_pushcclosure(L, func, n);   // L: agent func
        lua_getmetatable(L, -2);        // L: agent func cls
        olua_rawgetf(L, -1, t);         // L: agent func cls .func
        lua_pushvalue(L, -3);           // L: agent func cls .func func
        olua_rawsetf(L, -2, name);      // L: agent func cls .func   .func[name] = func
        lua_pop(L, 3);                  // L: agent
    }
}

OLUA_API void oluacls_prop(lua_State *L, const char *name, lua_CFunction getter, lua_CFunction setter)
{
    aux_setfunc(L, CLS_GET, name, getter, 0);
    aux_setfunc(L, CLS_SET, name, setter, 0);
}

OLUA_API void oluacls_func(lua_State *L, const char *name, lua_CFunction func)
{
    aux_setfunc(L, CLS_FUNC, name, func, 0);
}

static int cls_index_const(lua_State *L)
{
    lua_pushvalue(L, lua_upvalueindex(1));
    return 1;
}

OLUA_API void oluacls_const(lua_State *L, const char *name)
{
    aux_setfunc(L, CLS_GET, name, cls_index_const, 1);
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
        msg = lua_pushfstring(L, "olua check '%s': %s expected, got %s", field, tname, typearg);
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
    if (!lua_getmetatable(L, 1)) {      // L: obj cls func mt
        lua_pushnil(L);                 // L: obj cls func nil
    }
    
    if (olua_getmetatable(L, cls) == LUA_TTABLE) {
        lua_setmetatable(L, 1);
    } else {
        luaL_error(L, "metatable not found: %s", cls);
    }
    
    lua_pushvalue(L, 3);                // L: obj cls func mt func
    lua_pushvalue(L, 1);                // L: obj cls func mt func obj
    lua_call(L, 1, 0);                  // L: obj cls func mt
    lua_setmetatable(L, 1);             // L: obj cls func
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
    olua_vmstatus(L)->debug = olua_checkboolean(L, 1);
    return 0;
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
    lua_pushinteger(L, (lua_Integer)(intptr_t)lua_topointer(L, 1));
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
    
    olua_newlib(L,lib);
    
    return 1;
}

#if LUA_VERSION_NUM == 501
#define HAVE_USERVALUE ((void *)lua_getuservalue)

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

OLUA_API void olua_setfuncs(lua_State *L, const luaL_Reg *l, int nup)
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

OLUA_API int olua_getsubtable(lua_State *L, int idx, const char *fname) {
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

OLUA_API void olua_requiref(lua_State *L, const char *modname, lua_CFunction openf, int glb) {
    olua_getsubtable(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
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

OLUA_API void *olua_testudata(lua_State *L, int ud, const char *tname) {
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

OLUA_API void olua_traceback(lua_State *L, lua_State *L1, const char *msg, int level)
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
