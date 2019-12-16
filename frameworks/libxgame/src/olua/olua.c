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

#define CLS_CLSIDX  (lua_upvalueindex(1))
#define CLS_ISAIDX  (lua_upvalueindex(2))
#define CLS_FUNCIDX (lua_upvalueindex(3))
#define CLS_GETIDX  (lua_upvalueindex(4))
#define CLS_SETIDX  (lua_upvalueindex(5))
#define CLS_ISA     ".isa"
#define CLS_FUNC    ".func"
#define CLS_GET     ".get"
#define CLS_SET     ".set"
#define CLS_STORE   ".store" // static store for cls

#define OLUA_OBJ_TABLE  ((void *)olua_pushobj)
#define OLUA_POOL_TABLE ((void *)aux_pushlocalobj)
#define OLUA_REF_TABLE  ((void *)aux_getmappingtable)
#define OLUA_EXTRASPACE ((void *)lua_getextraspace)

#define strequal(s1, s2)        (strcmp((s1), (s2)) == 0)
#define strstartwith(s1, s2)    (strstr((s1), (s2)) == s1)
#define aux_pushrefkey(L, name) (lua_pushfstring(L, ".ref.%s", (name)))

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

static int l_vmstatus_gc(lua_State *L)
{
    olua_vmstatus_t *mt = olua_torawdata(L, 1, olua_vmstatus_t *);
    free(mt);
    return 0;
}

static olua_vmstatus_t *init_vmstatus(lua_State *L, olua_vmstatus_t *vms)
{
    vms = vms != NULL ? vms : ((olua_vmstatus_t *)malloc(sizeof(*vms)));
    vms->objcount = vms->poolsize = 0;
    vms->poolenabled = vms->debug = false;
    *(olua_vmstatus_t **)lua_getextraspace(L) = vms;
    olua_newrawdata(L, vms, olua_vmstatus_t *);     // L: md
    lua_createtable(L, 0, 1);                       // L: md  mt
    lua_pushcfunction(L, l_vmstatus_gc);            // L: md  mt  gcfunc
    olua_rawsetf(L, -2, "__gc");                    // L: md  mt         mt.__gc = gcfunc
    lua_setmetatable(L, -2);                        // L: md             md.metatable = mt
    olua_rawsetp(L, LUA_REGISTRYINDEX, (void *)vms);// L:                REGISTRY[vms] = md
    return vms;
}

LUALIB_API lua_State *olua_newstate(olua_vmstatus_t *vms)
{
    lua_State *L = luaL_newstate();
    init_vmstatus(L, vms);
    return L;
}

LUALIB_API olua_vmstatus_t *olua_vmstatus(lua_State *L)
{
    olua_vmstatus_t *vms = *(olua_vmstatus_t **)lua_getextraspace(L);
    return vms ? vms : init_vmstatus(L, NULL);
}

LUALIB_API lua_Integer olua_checkinteger(lua_State *L, int idx)
{
    luaL_checktype(L, idx, LUA_TNUMBER);
    return luaL_checkinteger(L, idx);
}

LUALIB_API lua_Number olua_checknumber(lua_State *L, int idx)
{
    luaL_checktype(L, idx, LUA_TNUMBER);
    return olua_tonumber(L, idx);
}

LUALIB_API const char *olua_checklstring(lua_State *L, int idx, size_t *len)
{
    luaL_checktype(L, idx, LUA_TSTRING);
    return olua_tolstring(L, idx, len);
}

LUALIB_API bool olua_checkboolean(lua_State *L, int idx)
{
    if (!(olua_isnoneornil(L, idx) || olua_isboolean(L, idx))) {
        luaL_checktype(L, idx, LUA_TBOOLEAN);
    }
    return olua_toboolean(L, idx);
}

LUALIB_API int olua_rawgetf(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    return olua_rawget(L, idx);
}

LUALIB_API void olua_rawsetf(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    lua_insert(L, -2);
    lua_rawset(L, idx);
}

LUALIB_API void olua_preload(lua_State *L, const char *name, lua_CFunction func)
{
    int top = lua_gettop(L);
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "preload");
    func(L);
    lua_setfield(L, -2, name);
    lua_settop(L, top);
}

LUALIB_API int olua_geterrorfunc(lua_State *L)
{
    if (olua_getglobal(L, "__TRACEBACK__") != LUA_TFUNCTION) {
        lua_pop(L, 1);
        lua_pushcfunction(L, errfunc);
    }
    return lua_gettop(L);
}

LUALIB_API int olua_pcall(lua_State *L, int nargs, int nresults)
{
    int status;
    int errfunc = lua_absindex(L, -(nargs + 1));
    olua_geterrorfunc(L);
    lua_insert(L, errfunc);
    status = lua_pcall(L, nargs, nresults, errfunc);
    lua_remove(L, errfunc);
    return status;
}

LUALIB_API int olua_pcallref(lua_State *L, int funcref, int nargs, int nresults)
{
    olua_getref(L, funcref);
    olua_assert(lua_isfunction(L, -1));
    lua_insert(L, -(nargs + 1));
    return olua_pcall(L, nargs, nresults);
}

LUALIB_API void olua_require(lua_State *L, const char *name, lua_CFunction func)
{
    int top = lua_gettop(L);
    olua_requiref(L, name, func, false);
    lua_settop(L, top);
}

LUALIB_API const char *olua_typename(lua_State *L, int idx)
{
    const char *tn = NULL;
    if (lua_isuserdata(L, idx) && lua_getmetatable(L, idx)) {
        if (olua_rawgetf(L, -1, "classname") == LUA_TSTRING) {
            tn = olua_tostring(L, -1);
        }
        lua_pop(L, 2); // pop mt and value
    }
    if (!tn) {
        tn = lua_typename(L, lua_type(L, idx));
    }
    return tn;
}

LUALIB_API bool olua_isa(lua_State *L, int idx, const char *cls)
{
    bool isa = false;
    int top = lua_gettop(L);
    if (lua_isuserdata(L, idx) && lua_getmetatable(L, idx)) {
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
    
    lua_remove(L, -2);
    olua_setrawdata(L, -1, obj);
}

LUALIB_API int olua_pushobj(lua_State *L, void *obj, const char *cls)
{
    int status = OLUA_EXIST;
    
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
            status = OLUA_EXIST;
        } else {
            olua_newrawdata(L, obj, void *);        // L: mt objtable ud
            lua_pushvalue(L, -1);                   // L: mt objtable ud ud
            olua_rawsetp(L, -3, obj);               // L: mt objtable ud     objtable[obj] = ud
            status = OLUA_NEW;
        }
        lua_pushvalue(L, -3);                       // L: mt objtable ud mt
        lua_setmetatable(L, -2);                    // L: mt objtable ud     ud.metatable = mt
    }
    
    if (!strequal(cls, OLUA_VOIDCLS) && olua_testudata(L, -1, OLUA_VOIDCLS)) {
        lua_pushvalue(L, -3);                       // L: mt objtable ud mt
        lua_setmetatable(L, -2);                    // L: mt objtable ud     ud.metatable = mt
        status = OLUA_NEW;
    }
    
    lua_insert(L, -3);
    lua_pop(L, 2);
    olua_assert(olua_isa(L, -1, cls));
    
    return status;
}

LUALIB_API bool olua_getobj(lua_State *L, void *obj)
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
        void *obj = olua_torawdata(L, idx, void *);
        if (obj) {
            return obj;
        } else {
            luaL_error(L, "object '%s' live from gc", olua_typename(L, idx));
        }
    } else {
        luaL_error(L, "#%d argument error, expect: '%s', got '%s'", idx,
            cls, olua_typename(L, idx));
    }
    return NULL;
}

LUALIB_API void *olua_checkobj(lua_State *L, int idx, const char *cls)
{
    return aux_toobj(L, idx, cls, true);
}

LUALIB_API void *olua_toobj(lua_State *L, int idx, const char *cls)
{
#if OLUA_DEBUG
    return aux_toobj(L, idx, cls, true);
#else
    return aux_toobj(L, idx, cls, false);
#endif
}

LUALIB_API const char *olua_objstring(lua_State *L, int idx)
{
    intptr_t p;
    const char *tn = olua_typename(L, idx);
    if (olua_isuserdata(L, idx)) {
        p = (intptr_t)olua_torawdata(L, idx, void *);
    } else {
        p = (intptr_t)lua_topointer(L, idx);
    }
    return lua_pushfstring(L, "%s: %p", tn, p);
}

LUALIB_API void olua_pop_objpool(lua_State *L, size_t level)
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

static bool test_tag_mode(lua_State *L, int idx, const char *tag, olua_tag_mode mode)
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

LUALIB_API const char *olua_setcallback(lua_State *L, void *obj, const char *tag, int func, olua_tag_mode mode)
{
    const char *cls = NULL;
    func = lua_absindex(L, func);
    luaL_checktype(L, func, LUA_TFUNCTION);
    
    if (!olua_getobj(L, obj)) {                         // L: obj
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

LUALIB_API void olua_getcallback(lua_State *L, void *obj, const char *tag, olua_tag_mode mode)
{
    if (!olua_getobj(L, obj)) {
        lua_pushnil(L);
        return;
    }
    
    aux_getusertable(L, -1);
    lua_remove(L, -2);
    
    if (mode == OLUA_TAG_WHOLE) {
        olua_rawgetf(L, -1, tag);                       // L: ct v
        lua_insert(L, -2);                              // L: v ct
        lua_pop(L, 1);                                  // L: v
    } else {
        lua_pushnil(L);                                 // L: ct k
        while (lua_next(L, -2)) {                       // L: ct k v
            if (test_tag_mode(L, -2, tag, mode)) {
                lua_insert(L, -3);                      // L: v ct k
                lua_pop(L, 2);                          // L: v
                return;
            }
            lua_pop(L, 1);
        }
        lua_pop(L, 1);                                  // L:
        lua_pushnil(L);                                 // L: nil
    }
}

LUALIB_API void olua_removecallback(lua_State *L, void *obj, const char *tag, olua_tag_mode mode)
{
    if (!olua_getobj(L, obj)) {
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

LUALIB_API int olua_callback(lua_State *L, void *obj, const char *func, int argc)
{
    int top = lua_gettop(L) - argc;
    int status = OLUA_MISS;
    
    if (olua_getobj(L, obj)) {                              // L: arg...n obj
        aux_getusertable(L, -1);                            // L: arg...n obj uv
        if (olua_rawgetf(L, -1, func) == LUA_TFUNCTION) {   // L: arg...n obj uv callback
            lua_insert(L, top + 1);                         // L: callback arg...n obj uv
            lua_pop(L, 2);                                  // L: callback arg...n
            olua_geterrorfunc(L);                           // L: callback arg...n errfunc
            lua_insert(L, top + 1);                         // L: errfunc callback arg...n
            if (lua_pcall(L, argc, 1, top + 1) == LUA_OK) { // L: errfunc result
                status = OLUA_OK;
            } else {
                status = OLUA_ERR;
            }
            lua_remove(L, -2);                              // L: result
        }
    }
    
    if (status != OLUA_OK) {
        if (status == OLUA_MISS) {
            olua_geterrorfunc(L);
            lua_pushfstring(L, "callback missed: %s", func);
            lua_pcall(L, 1, 0, 0);
        }
        lua_settop(L, top);
        lua_pushnil(L);
    }
    
    return status;
}

LUALIB_API void olua_getstore(lua_State *L, const char *cls)
{
    olua_getmetatable(L, cls);                  // L: cls
    olua_rawgetf(L, -1, CLS_STORE);             // L: cls store
    lua_remove(L, -2);                          // L: store
    olua_assert(olua_isuserdata(L, -1));
}

LUALIB_API void *olua_getstoreobj(lua_State *L, const char *cls)
{
    void *store_obj = NULL;
    olua_getstore(L, cls);
    store_obj = (void *)lua_topointer(L, -1);
    lua_pop(L, 1);
    return store_obj;
}

LUALIB_API int olua_getvariable(lua_State *L, int idx)
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

LUALIB_API void olua_setvariable(lua_State *L, int idx)
{
    olua_assert(olua_isuserdata(L, idx));
    aux_getusertable(L, idx);       // L: k v uv
    lua_insert(L, -3);              // L: uv k v
    lua_rawset(L, -3);              // L: uv          idx.uservalue[k] = v
    lua_pop(L, 1);                  // L:
}

static void aux_getmappingtable(lua_State *L)
{
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_REF_TABLE) != LUA_TTABLE) {
        lua_pop(L, 1);
        lua_newtable(L);
        lua_pushvalue(L, -1);
        olua_rawsetp(L, LUA_REGISTRYINDEX, OLUA_REF_TABLE);
    }
}

LUALIB_API int olua_ref(lua_State *L, int idx)
{
    static int ref = 0;
    if (!olua_isnil(L, idx)) {
        idx = lua_absindex(L, idx);
        aux_getmappingtable(L);     // L: mapping
        while (olua_rawgeti(L, -1, ++ref) != LUA_TNIL) {
            lua_pop(L, 1);
            ref = ref < 0 ? 0 : ref;
        }                           // L: mapping nil
        lua_pushvalue(L, idx);      // L: mapping nil value
        lua_rawseti(L, -3, ref);    // L: mapping nil       mapping[ref] = value
        lua_pop(L, 2);              // L:
        return ref;
    }
    return LUA_REFNIL;
}

LUALIB_API int olua_reffunc(lua_State *L, int idx)
{
    luaL_checktype(L, idx, LUA_TFUNCTION);
    return olua_ref(L, idx);
}

LUALIB_API void olua_unref(lua_State *L, int ref)
{
    aux_getmappingtable(L);         // L: mapping
    lua_pushnil(L);                 // L: mapping nil
    lua_rawseti(L, -2, ref);        // L: mapping       mapping[ref] = nil
    lua_pop(L, 1);                  // L:
}

LUALIB_API void olua_getref(lua_State *L, int ref)
{
    aux_getmappingtable(L);
    lua_rawgeti(L, -1, ref);
    lua_remove(L, -2);
}

LUALIB_API void olua_getreftable(lua_State *L, int idx, const char *name)
{
    olua_assert(olua_isuserdata(L, idx));
    aux_getusertable(L, idx);               // L: uv
    name = aux_pushrefkey(L, name);         // L: uv refkey
    olua_getsubtable(L, -2, name);          // L: uv refkey reftable
    lua_insert(L, -3);                      // L: reftable uv refkey
    lua_pop(L, 2);                          // L: reftable
}

LUALIB_API void olua_singleref(lua_State *L, int idx, const char *name, int obj)
{
    olua_assert(olua_isuserdata(L, idx));
    olua_assert(olua_isuserdata(L, obj) || olua_isnil(L, obj));
    obj = lua_absindex(L, obj);
    aux_getusertable(L, idx);               // L: uv
    aux_pushrefkey(L, name);                // L: uv refk
    lua_pushvalue(L, obj);                  // L: uv refk refv
    lua_rawset(L, -3);                      // L: uv      uv[refk] = refv
    lua_pop(L, 1);                          // L:
}

LUALIB_API void olua_singleunref(lua_State *L, int idx, const char *name)
{
    lua_pushnil(L);
    olua_singleref(L, idx, name, -1);
    lua_pop(L, 1);
}

static void aux_maprefobj(lua_State *L, int idx, const char *name, int obj, bool ref)
{
    olua_assert(olua_isuserdata(L, idx));
    olua_assert(olua_isuserdata(L, obj));
    olua_assert(!lua_rawequal(L, idx, obj));
    obj = lua_absindex(L, obj);
    olua_getreftable(L, idx, name);         // L: t
    lua_pushvalue(L, obj);                  // L: t v
    if (ref) {
        lua_pushboolean(L, true);           // L: t v true
    } else {
        lua_pushnil(L);                     // L: t v nil
    }
    lua_rawset(L, -3);                      // L: t
    lua_pop(L, 1);
}

LUALIB_API void olua_mapref(lua_State *L, int idx, const char *name, int obj)
{
    if (!olua_isnil(L, obj)) {
        aux_maprefobj(L, idx, name, obj, true);
    }
}

LUALIB_API void olua_maprefarray(lua_State *L, int idx, const char *name, int obj)
{
    olua_assert(olua_isuserdata(L, idx));
    olua_assert(olua_istable(L, obj));
    obj = lua_absindex(L, obj);
    olua_getreftable(L, idx, name);                 // L: t
    if (olua_istable(L, obj)) {
        lua_pushnil(L);                             // L: t k
        while (lua_next(L, obj)) {                  // L: t k v
            olua_assert(olua_isuserdata(L, -1));
            lua_pushboolean(L, true);               // L: t k v true
            lua_rawset(L, -4);                      // L: t k       t[v] = true
        }
    }
    lua_pop(L, 1);                                  // L:
}

LUALIB_API void olua_mapunref(lua_State *L, int idx, const char *name, int obj)
{
    if (!olua_isnil(L, obj)) {
        aux_maprefobj(L, idx, name, obj, false);
    }
}

LUALIB_API void olua_mapwalkunref(lua_State *L, int idx, const char *name, olua_WalkFunction walk)
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

LUALIB_API void olua_unrefall(lua_State *L, int idx, const char *name)
{
    olua_assert(olua_isuserdata(L, idx));
    aux_getusertable(L, idx);               // L: uv
    aux_pushrefkey(L, name);                // L: uv k
    lua_pushnil(L);                         // L: uv k nil
    lua_rawset(L, -3);                      // L: uv
    lua_pop(L, 1);                          // L:
}

static bool istagmethod(lua_State *L, int idx, const char *func)
{
    if (!func && olua_isstring(L, idx)) {
        func = olua_tostring(L, idx);
    }
    return func && strstr(func, "__") == func;
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

static int cls_tagmethod(lua_State *L)
{
    if (!lua_toboolean(L, lua_upvalueindex(2))) {
        lua_pushvalue(L, lua_upvalueindex(1));
        lua_insert(L, 1);
        lua_call(L, lua_gettop(L) - 1, LUA_MULTRET);
        return lua_gettop(L);
    } else if (olua_isuserdata(L, 1)) { // __gc and userdata
        olua_geterrorfunc(L);
        lua_insert(L, 1);
        lua_pushvalue(L, lua_upvalueindex(1));
        lua_insert(L, 2);
        lua_pcall(L, lua_gettop(L) - 2, LUA_MULTRET, 1);
        return lua_gettop(L) - 1;
    } else {
        // unnecessary call __gc on class table
        return 0;
    }
}

static void aux_settagmethod(lua_State *L, int idx)
{
    lua_pushvalue(L, idx);                      // L: n f t
    lua_insert(L, -3);                          // L: t n f
    if (!olua_isnoneornil(L, -1)) {
        luaL_checktype(L, -1, LUA_TFUNCTION);
        lua_pushboolean(L, strequal("__gc", lua_tostring(L, -2)));
        lua_pushcclosure(L, cls_tagmethod, 2);
    }
    olua_rawset(L, -3);                         // L: t
    lua_pop(L, 1);                              // L:
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
        if (olua_getvariable(L, 1) != LUA_TNIL) {
            return 1;
        }
    }
    
    lua_pushnil(L);
    
    return 1;
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
            // static setter, accessed from class proxy
            lua_pushvalue(L, 3);                // L: t k v setter v
            lua_call(L, 1, 0);                  // L: t k v
        }
        return 0;
    }
    
    if (olua_istable(L, 1)) {
        lua_pushvalue(L, 2);                    // L: t k v k
        lua_pushvalue(L, 3);                    // L: t k v k v
        lua_rawset(L, CLS_FUNCIDX);             // L: t k v
        
        if (istagmethod(L, 2, NULL)) {
            lua_pushvalue(L, 2);
            lua_pushvalue(L, 3);
            aux_settagmethod(L, CLS_CLSIDX);
        }
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

static void copytagmethod(lua_State *L, int idx, const char *supercls)
{
    if (!supercls) {
        return;
    }
    
    idx = lua_absindex(L, idx);             // L: mt
    olua_getmetatable(L, supercls);         // L: mt super
    lua_pushnil(L);                         // L: mt super k
    while (lua_next(L, -2)) {               // L: mt super k v
        if (istagmethod(L, -2, NULL)) {
            lua_pushvalue(L, -2);           // L: mt super k v k
            lua_pushvalue(L, -2);           // L: mt super k v k v
            lua_rawset(L, idx);             // L: mt super k v
        }
        lua_pop(L, 1);                      // L: mt super k
    }                                       // L: mt super
    lua_pop(L, 1);                          // L: mt
}

LUALIB_API void oluacls_class(lua_State *L, const char *cls, const char *super)
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
        
        int idx = lua_gettop(L);
        lua_pop(L, 1);
        luaL_newmetatable(L, cls);                      // L: mt
        copytagmethod(L, -1, super);
        
        lua_pushvalue(L, -1);                           // L: mt mt
        create_table(L, idx, CLS_ISA, super, true);     // L: mt mt .isa
        create_table(L, idx, CLS_FUNC, super, false);   // L: mt mt .isa .func
        create_table(L, idx, CLS_GET, super, false);    // L: mt mt .isa .func .get
        create_table(L, idx, CLS_SET, super, false);    // L: mt mt .isa .func .get .set
        olua_setfuncs(L, lib,  5);                      // L: mt
        
        lua_pushvalue(L, -1);
        oluacls_const(L, "class");                      // mt.class = mt
        oluacls_const_string(L, "classname", cls);      // mt.classname = cls
        oluacls_const_string(L, "classtype", "native");
        
        if (super) {
            olua_getmetatable(L, super);
            oluacls_const(L, "super");                  // mt.super = supermt
        }
        
        olua_rawgetf(L, idx, CLS_ISA);
        olua_setfieldboolean(L, -1, cls, true);         // mt[.isa][cls] = true
        lua_pop(L, 1);
        
        // create class store, for sotre static function callback
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
        olua_rawsetp(L, -2, lua_topointer(L, -1));      // L: mt store objs           objs[store_ptr] = store
        lua_pop(L, 2);                                  // L: mt
        
        // allow access static method or const variable from class table
        lua_pushvalue(L, -1);
        lua_setmetatable(L, -2);
    }
}

static int clsenum_index(lua_State *L)
{
    luaL_checktype(L, 1, LUA_TTABLE);
    if (lookupfunc(L, CLS_GETIDX, 2) != LUA_TNIL) {
        lua_pushvalue(L, 1);
        lua_call(L, 1, 1);
        return 1;
    }
    luaL_error(L, "index unknown field '%s'", olua_checkstring(L, 2));
    return 0;
}

LUALIB_API void oluacls_asenum(lua_State *L)
{
    int n = 0;
    int cls = lua_gettop(L);                    // L: cls
    olua_rawgetf(L, -1, "__index");             // L: cls idxfunc
    while (true) {
        if (!lua_getupvalue(L, cls + 1, ++n)) { // L: cls idxfunc uv ...n
            n--;
            break;
        }
    }
    lua_pushcclosure(L, clsenum_index, n);      // L: cls idxfunc idxenum
    olua_rawsetf(L, cls, "__index");            // L: cls idxfunc cls.__index = idxenum
    lua_settop(L, cls);                         // L: cls
}

static void aux_setfunc(lua_State *L, const char *t, const char *name, lua_CFunction func)
{
    if (func) {
        olua_rawgetf(L, -1, t);             // L: cls t
        lua_pushcfunction(L, func);         // L: cls t func
        olua_rawsetf(L, -2, name);          // L: cls t      t[name] = func
        lua_pop(L, 1);
    }
}

LUALIB_API void oluacls_prop(lua_State *L, const char *name, lua_CFunction getter, lua_CFunction setter)
{
    aux_setfunc(L, CLS_GET, name, getter);
    aux_setfunc(L, CLS_SET, name, setter);
}

LUALIB_API void oluacls_func(lua_State *L, const char *name, lua_CFunction func)
{
    aux_setfunc(L, CLS_FUNC, name, func);
    if (func && istagmethod(L, 0, name)) {
        lua_pushstring(L, name);
        lua_pushcfunction(L, func);
        aux_settagmethod(L, -3);
    }
}

static int cls_index_const(lua_State *L)
{
    lua_pushvalue(L, lua_upvalueindex(1));
    return 1;
}

LUALIB_API void oluacls_const(lua_State *L, const char *name)
{
    lua_pushvalue(L, -1);                       // L: cls v v
    olua_rawsetf(L, -3, name);                  // L: cls v
    lua_pushcclosure(L, cls_index_const, 1);    // L: cls getter
    olua_rawgetf(L, -2, CLS_GET);               // L: cls getter .get
    lua_insert(L, -2);                          // L: cls .get getter
    olua_rawsetf(L, -2, name);                  // L: cls .get
    lua_pop(L, 1);                              // L: cls
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

LUALIB_API const char *olua_checkfieldstring(lua_State *L, int idx, const char *field)
{
    const char *value;
    aux_checkfield(L, idx, field, LUA_TSTRING, false);
    value = olua_tostring(L, -1);
    lua_pop(L, 1);
    return value;
}

LUALIB_API lua_Number olua_checkfieldnumber(lua_State *L, int idx, const char *field)
{
    lua_Number value;
    aux_checkfield(L, idx, field, LUA_TNUMBER, false);
    value = olua_tonumber(L, -1);
    lua_pop(L, 1);
    return value;
}

LUALIB_API lua_Integer olua_checkfieldinteger(lua_State *L, int idx, const char *field)
{
    lua_Integer value;
    aux_checkfield(L, idx, field, LUA_TNUMBER, true);
    value = olua_tointeger(L, -1);
    lua_pop(L, 1);
    return value;
}

LUALIB_API bool olua_checkfieldboolean(lua_State *L, int idx, const char *field)
{
    bool value;
    aux_checkfield(L, idx, field, LUA_TBOOLEAN, false);
    value = olua_toboolean(L, -1);
    lua_pop(L, 1);
    return value;
}

LUALIB_API void olua_setfieldnumber(lua_State *L, int idx, const char *field, lua_Number value)
{
    idx = lua_absindex(L, idx);
    lua_pushnumber(L, value);
    lua_setfield(L, idx, field);
}

LUALIB_API void olua_setfieldinteger(lua_State *L, int idx, const char *field, lua_Integer value)
{
    idx = lua_absindex(L, idx);
    lua_pushinteger(L, value);
    lua_setfield(L, idx, field);
}

LUALIB_API void olua_setfieldstring(lua_State *L, int idx, const char *field, const char *value)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, value);
    lua_setfield(L, idx, field);
}

LUALIB_API void olua_setfieldboolean(lua_State *L, int idx, const char *field, bool value)
{
    idx = lua_absindex(L, idx);
    lua_pushboolean(L, value);
    lua_setfield(L, idx, field);
}

LUALIB_API const char *olua_optfieldstring(lua_State *L, int idx, const char *field, const char *def)
{
    lua_getfield(L, idx, field);
    def = olua_optstring(L, -1, def);
    lua_pop(L, 1);
    return def;
}

LUALIB_API lua_Number olua_optfieldnumber(lua_State *L, int idx, const char *field, lua_Number def)
{
    lua_getfield(L, idx, field);
    def = olua_optnumber(L, -1, def);
    lua_pop(L, 1);
    return def;
}

LUALIB_API lua_Integer olua_optfieldinteger(lua_State *L, int idx, const char *field, lua_Integer def)
{
    lua_getfield(L, idx, field);
    def = olua_optinteger(L, -1, def);
    lua_pop(L, 1);
    return def;
}

LUALIB_API bool olua_optfieldboolean(lua_State *L, int idx, const char *field, bool def)
{
    lua_getfield(L, idx, field);
    def = olua_optboolean(L, -1, def);
    lua_pop(L, 1);
    return def;
}

LUALIB_API bool olua_hasfield(lua_State *L, int idx, const char *field)
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
        lua_pop(L, 1);
        luaL_error(L, "metatable not found: %s", cls);
    }
    
    olua_geterrorfunc(L);               // L: obj cls func mt trackback
    lua_pushvalue(L, 3);                // L: obj cls func mt trackback func
    lua_pushvalue(L, 1);                // L: obj cls func mt trackback func obj
    lua_pcall(L, 1, 0, 5);              // L: obj cls func mt trackback
    lua_pop(L, 1);                      // L: obj cls func mt
    lua_setmetatable(L, 1);             // L: obj cls func
    
    return 0;
}

static int l_isa(lua_State *L)
{
    olua_isa(L, 1, olua_checkstring(L, 2));
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

static int l_topointer(lua_State *L)
{
    intptr_t p = (intptr_t)lua_topointer(L, 1);
    lua_pushinteger(L, (lua_Integer)p);
    return 1;
}

LUALIB_API int luaopen_olua(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"with", l_with},
        {"isa", l_isa},
        {"take", l_take},
        {"move", l_move},
        {"debug", l_debug},
        {"class", l_class},
        {"topointer", l_topointer},
        {NULL, NULL}
    };
    
    olua_newlib(L,lib);
    
    return 1;
}

#if LUA_VERSION_NUM == 501
LUALIB_API void *lua_getextraspace(lua_State *L)
{
    void *p;
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_EXTRASPACE) == LUA_TNIL) {
        lua_pop(L, 1);
        lua_newuserdata(L, sizeof(olua_vmstatus_t *));
        lua_pushvalue(L, -1);
        olua_rawsetp(L, LUA_REGISTRYINDEX, OLUA_EXTRASPACE);
    }
    p = lua_touserdata(L, -1);
    lua_pop(L, 1);
    return p;
}

LUALIB_API void lua_setuservalue(lua_State *L, int idx)
{
    if (lua_type(L, -1) != LUA_TNIL) {
        luaL_checktype(L, -1, LUA_TTABLE);
        lua_pushboolean(L, true);
        olua_rawsetp(L, -2, (void *)lua_getuservalue);
    } else {
        lua_pop(L, 1);
        lua_pushvalue(L, LUA_GLOBALSINDEX);
    }
    lua_setfenv(L, idx);
}

LUALIB_API int lua_getuservalue(lua_State *L, int idx)
{
    lua_getfenv(L, idx);
    if (olua_rawgetp(L, -1, (void *)lua_getuservalue) == LUA_TNIL) {
        lua_pop(L, 1);
        return LUA_TNIL;
    } else {
        lua_pop(L, 1);
        return lua_type(L, -1);
    }
}

LUALIB_API int lua_absindex(lua_State *L, int idx)
{
    return (idx > 0 || idx <= LUA_REGISTRYINDEX) ?
        idx : (idx + 1 + lua_gettop(L));
}

LUALIB_API int lua_isinteger(lua_State *L, int idx)
{
    if (olua_isnumber(L, idx)) {
        lua_Number n = lua_tonumber(L, idx);
        return n == (lua_Number)(floor(n));
    }
    return false;
}

LUALIB_API void olua_setfuncs(lua_State *L, const luaL_Reg *l, int nup)
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

LUALIB_API int olua_getsubtable(lua_State *L, int idx, const char *fname) {
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

LUALIB_API void olua_requiref(lua_State *L, const char *modname, lua_CFunction openf, int glb) {
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

LUALIB_API void *olua_testudata(lua_State *L, int ud, const char *tname) {
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

LUALIB_API void olua_traceback(lua_State *L, lua_State *L1, const char *msg, int level)
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

LUALIB_API void olua_rawsetp(lua_State *L, int idx, const void *p)
{
    idx = lua_absindex(L, idx);
    lua_pushlightuserdata(L, (void *)p);
    lua_insert(L, -2);
    olua_rawset(L, idx);
}

LUALIB_API int olua_rawgetp(lua_State *L, int idx, const void *p)
{
    idx = lua_absindex(L, idx);
    lua_pushlightuserdata(L, (void *)p);
    return olua_rawget(L, idx);
}
#endif
