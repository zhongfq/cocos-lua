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

#define OBJ_REF_TABLE       ((void *)olua_pushobj)
#define STACKPOOL_ENABLED   ((void *)olua_enable_stackpool)
#define STACKPOOL_TABLE     ((void *)olua_stackpool_push)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

static int _count = 0;

static inline bool strequal(const char *str1, const char *str2)
{
    return strcmp(str1, str2) == 0;
}

static inline bool strendwith(const char *src, const char *suffix)
{
    const char *pos = strstr(src, suffix);
    return !pos ? false : (src + strlen(src) == pos + strlen(suffix));
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

LUALIB_API lua_Integer olua_checkinteger(lua_State *L, int idx)
{
    luaL_checktype(L, idx, LUA_TNUMBER);
    return olua_tointeger(L, idx);
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

LUALIB_API int olua_rawget(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    return lua_rawget(L, idx);
}

LUALIB_API void olua_rawset(lua_State *L, int idx, const char *field)
{
    idx = lua_absindex(L, idx);
    lua_pushstring(L, field);
    lua_insert(L, -2);
    lua_rawset(L, idx);
}

LUALIB_API int olua_changeobjcount(int add)
{
    _count += add;
    return _count;
}

LUALIB_API void olua_preload(lua_State *L, const char *name, lua_CFunction func)
{
    luaL_getsubtable(L, LUA_REGISTRYINDEX, LUA_PRELOAD_TABLE);  // L: preload
    lua_pushcfunction(L, func);                                 // L: preload func
    lua_setfield(L, -2, name);                                  // L: preload
    lua_pop(L, 1);                                              // L:
}

LUALIB_API int olua_geterrorfunc(lua_State *L)
{
    if (lua_getglobal(L, "__TRACEBACK__") != LUA_TFUNCTION) {
        lua_pop(L, 1);
        lua_pushcfunction(L, errfunc);
    }
    return lua_gettop(L);
}

LUALIB_API void olua_require(lua_State *L, const char *name, lua_CFunction func)
{
    int top = lua_gettop(L);
    luaL_requiref(L, name, func, false);
    lua_settop(L, top);
}

LUALIB_API const char *olua_typename(lua_State *L, int idx)
{
    const char *tn = NULL;
    if (lua_getmetatable(L, idx)) {
        if (olua_rawget(L, -1, "classname") == LUA_TSTRING) {
            tn = olua_tostring(L, -1);
        }
        lua_pop(L, 2); // pop mt and value
    }
    return tn ? tn : lua_typename(L, lua_type(L, idx));
}

LUALIB_API const char *olua_objtostring(lua_State *L, int idx)
{
    intptr_t p;
    if (olua_isuserdata(L, idx)) {
        p = (intptr_t)olua_touserdata(L, idx, void *);
    } else {
        p = (intptr_t)lua_topointer(L, idx);
    }
    return lua_pushfstring(L, "%s: %p", olua_typename(L, idx), p);
}

LUALIB_API bool olua_isa(lua_State *L, int idx, const char *cls)
{
    bool isa = false;
    int top = lua_gettop(L);
    if (lua_getmetatable(L, idx)) {
        if (olua_rawget(L, -1, CLS_ISA) == LUA_TTABLE) {
            olua_rawget(L, -1, cls);
            isa = olua_toboolean(L, -1);
        }
    }
    lua_settop(L, top);
    return isa;
}

static void auxgetobjtable(lua_State *L)
{
    if (lua_rawgetp(L, LUA_REGISTRYINDEX, OBJ_REF_TABLE) != LUA_TTABLE) {
        lua_pop(L, 1); // pop nil
        lua_newtable(L);
        lua_pushvalue(L, -1);
        lua_pushstring(L, "kv");
        lua_setfield(L, -2, "__mode");  // mt.__mode = 'kv'
        lua_setmetatable(L, -2);        // mt.metatable = mt
        lua_pushvalue(L, -1);
        lua_rawsetp(L, LUA_REGISTRYINDEX, OBJ_REF_TABLE);
    }
}

static inline bool isusingpool(lua_State *L)
{
    bool b;
    lua_rawgetp(L, LUA_REGISTRYINDEX, STACKPOOL_ENABLED);
    b = olua_toboolean(L, -1);
    lua_pop(L, 1);
    return b;
}

static int olua_stackpool_push(lua_State *L, void *obj, const char *cls)
{
    int level = 0;
    if (lua_rawgetp(L, LUA_REGISTRYINDEX, STACKPOOL_TABLE) != LUA_TTABLE) {
        lua_pop(L, 1);
        lua_createtable(L, 16, 0);
        lua_pushvalue(L, -1);
        lua_rawsetp(L, LUA_REGISTRYINDEX, STACKPOOL_TABLE);
    }
    
    lua_rawgeti(L, -1, 0);
    level = (int)olua_optinteger(L, -1, 0) + 1;
    lua_pop(L, 1);
    lua_pushinteger(L, level);
    lua_rawseti(L, -2, 0);
    
    if (lua_rawgeti(L, -1, level) != LUA_TUSERDATA) {
        lua_pop(L, 1);
        lua_newuserdata(L, sizeof(void *));
        lua_pushvalue(L, -1);
        lua_rawseti(L, -3, level);
    }
    
    *(void **)lua_touserdata(L, -1) = obj;
    luaL_setmetatable(L, cls);
    
    if (!lua_getmetatable(L, -1)) {
        luaL_error(L, "metatable not found: %s", cls);
    } else {
        lua_pop(L, 1);
    }
    
    lua_remove(L, -2);
    
    return OLUA_OBJ_EXIST;
}

LUALIB_API int olua_pushobj(lua_State *L, void *obj, const char *cls)
{
    int status = OLUA_OBJ_EXIST;
    
    if (!obj) {
        lua_pushnil(L);
        return status;
    }
    
    if (!cls) {
        luaL_error(L, "class is null");
    }
    
    if (isusingpool(L)) {
        return olua_stackpool_push(L, obj, cls);
    }
    
    auxgetobjtable(L);
    
    if (lua_rawgetp(L, -1, obj) == LUA_TNIL) {      // L: mapping obj?
        lua_pop(L, 1);                              // L: mapping
        olua_newuserdata(L, obj, void *);           // L: mapping obj
        luaL_setmetatable(L, cls);                  // L: mapping obj
        lua_pushvalue(L, -1);                       // L: mapping obj obj
        lua_rawsetp(L, -3, obj);                    // L: mapping obj
        status = OLUA_OBJ_NEW;
        
        if (!lua_getmetatable(L, -1)) {
            luaL_error(L, "metatable not found: %s", cls);
        } else {
            lua_pop(L, 1);
        }
    }
    
    lua_remove(L, -2);                              // L: obj
    
    if (!strequal(cls, OLUA_VOIDCLS) && luaL_testudata(L, -1, OLUA_VOIDCLS)) {
        luaL_setmetatable(L, cls);
        status = OLUA_OBJ_UPDATE;
    }
    
    olua_assert(olua_isa(L, -1, cls));
    
    return status;
}

LUALIB_API bool olua_getobj(lua_State *L, void *obj)
{
    if (!obj) {
        return false;
    }
    auxgetobjtable(L);                              // L: objt
    if (lua_rawgetp(L, -1, obj) == LUA_TUSERDATA) { // L: objt obj
        lua_remove(L, -2);                          // L: obj
        return true;
    } else {
        lua_pop(L, 2);
        return false;
    }
}

LUALIB_API void *olua_checkobj(lua_State *L, int idx, const char *cls)
{
    if (olua_isa(L, idx, cls)) {
        return olua_toobj(L, idx, cls);
    } else {
        luaL_error(L, "#%d argument error, expect: '%s', got '%s'", idx,
            cls, olua_typename(L, idx));
    }
    return NULL;
}

LUALIB_API void *olua_toobj(lua_State *L, int idx, const char *cls)
{
    if (olua_isuserdata(L, idx)) {
        olua_assert(olua_isa(L, idx, cls));
        void *obj = olua_touserdata(L, idx, void *);
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

LUALIB_API void olua_enable_stackpool(lua_State *L)
{
    lua_pushboolean(L, true);
    lua_rawsetp(L, LUA_REGISTRYINDEX, STACKPOOL_ENABLED);
}

LUALIB_API void olua_disable_stackpool(lua_State *L)
{
    lua_pushboolean(L, false);
    lua_rawsetp(L, LUA_REGISTRYINDEX, STACKPOOL_ENABLED);
}

LUALIB_API int olua_push_stackpool(lua_State *L)
{
    int level = 0;
    if (lua_rawgetp(L, LUA_REGISTRYINDEX, STACKPOOL_TABLE) == LUA_TTABLE) {
        lua_rawgeti(L, -1, 0);
        level = (int)olua_optinteger(L, -1, 0);
        lua_pop(L, 1);
    }
    lua_pop(L, 1);
    return level;
}

LUALIB_API void olua_pop_stackpool(lua_State *L, int level)
{
    if (lua_rawgetp(L, LUA_REGISTRYINDEX, STACKPOOL_TABLE) == LUA_TTABLE) {
        int len = (int)lua_rawlen(L, -1);
        olua_assert(level >= 0 && level < len);
        for (int i = level + 1; i <= len; i++) {
            lua_rawgeti(L, -1, i);
            void **ud = (void **)lua_touserdata(L, -1);
            lua_pop(L, 1);
            if (*ud != NULL) {
                *ud = NULL;
            } else {
                break;
            }
        }
        lua_pushinteger(L, level);
        lua_rawseti(L, -2, 0);
    }
    lua_pop(L, 1);
}

static void auxgetusertable(lua_State *L, int idx)
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

LUALIB_API const char *olua_setcallback(lua_State *L, void *obj, const char *tag, int func, olua_callback_tag_t mode)
{
    static int ref = 0;
    
    func = lua_absindex(L, func);
    luaL_checktype(L, func, LUA_TFUNCTION);
    
    if (!olua_getobj(L, obj)) {                         // L: obj
        luaL_error(L, "obj userdata not found");
    }
    
    auxgetusertable(L, -1);                             // L: obj ct
    lua_remove(L, -2);                                  // L: ct
    
    if (mode == OLUA_CALLBACK_TAG_REPLACE) {
        lua_pushnil(L);                                 // L: ct k
        while (lua_next(L, -2)) {                       // L: ct k v
            if (olua_isstring(L, -2) &&
                strendwith(olua_tostring(L, -2), tag)) {
                lua_pop(L, 1);                          // L: ct k
                break;
            }
            lua_pop(L, 1);                              // L: ck k
        }
    }
    
    if (!olua_isstring(L, -1)) {
        lua_pushfstring(L, ".callback#%d@%s", ++ref, tag);
    }
    
    lua_pushvalue(L, -1);                               // L: ct k k
    lua_pushvalue(L, func);                             // L: ct k k v
    lua_rawset(L, -4);                                  // L: ct k
    lua_remove(L, -2);                                  // L: k
    return olua_tostring(L, -1);
}

static bool test_tag_mode(lua_State *L, int idx, const char *tag, olua_callback_tag_t mode)
{
    const char *field = NULL;
    if (olua_isstring(L, idx)) {
        field = olua_tostring(L, idx);
        if (mode == OLUA_CALLBACK_TAG_WILDCARD) {
            return strstr(field, tag) != NULL;
        } else if (mode == OLUA_CALLBACK_TAG_ENDWITH) {
            return strendwith(field, tag);
        }
    }
    return false;
}

LUALIB_API void olua_getcallback(lua_State *L, void *obj, const char *tag, olua_callback_tag_t mode)
{
    if (!olua_getobj(L, obj)) {
        lua_pushnil(L);
        return;
    }
    
    auxgetusertable(L, -1);
    lua_remove(L, -2);
    
    if (mode == OLUA_CALLBACK_TAG_EQUAL) {
        olua_rawget(L, -1, tag);                        // L: ct v
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

LUALIB_API void olua_removecallback(lua_State *L, void *obj, const char *tag, olua_callback_tag_t mode)
{
    if (!olua_getobj(L, obj)) {
        return;
    }
    
    auxgetusertable(L, -1);                             // L: obj ct
    if (mode == OLUA_CALLBACK_TAG_EQUAL) {
        lua_pushnil(L);                                 // L: obj ct nil
        olua_rawset(L, -2, tag);                        // L: obj ct
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

LUALIB_API int olua_callback(lua_State *L, void *obj, const char *field, int n)
{
    int top = lua_gettop(L) - n;
    int status = OLUA_CALLBACK_MISS;
    
    if (olua_getobj(L, obj)) {                              // L: arg...n obj
        auxgetusertable(L, -1);                             // L: arg...n obj uv
        if (olua_rawget(L, -1, field) == LUA_TFUNCTION) {   // L: arg...n obj uv callback
            lua_insert(L, top + 1);                         // L: callback arg...n obj uv
            lua_pop(L, 2);                                  // L: callback arg...n
            olua_geterrorfunc(L);                           // L: callback arg...n errfunc
            lua_insert(L, top + 1);                         // L: errfunc callback arg...n
            if (lua_pcall(L, n, 1, top + 1) == LUA_OK) {    // L: errfunc result
                status = OLUA_CALLBACK_OK;
            } else {
                status = OLUA_CALLBACK_ERR;
            }
            lua_remove(L, -2);                              // L: result
        }
    }
    
    if (status != OLUA_CALLBACK_OK) {
        if (status == OLUA_CALLBACK_MISS) {
            olua_geterrorfunc(L);
            lua_pushfstring(L, "callback missed: %s", field);
            lua_pcall(L, 1, 0, 0);
        }
        lua_settop(L, top);
        lua_pushnil(L);
    }
    
    return status;
}

LUALIB_API void olua_getstore(lua_State *L, const char *cls)
{
    luaL_getmetatable(L, cls);                  // L: cls
    olua_rawget(L, -1, CLS_STORE);              // L: cls store
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
        type = lua_rawget(L, -2);                   // L: uv v
        lua_remove(L, -2);                          // L: v
    } else {
        lua_pop(L, 2);                              // L:
        lua_pushnil(L);                             // L: nilp
    }
    return type;
}

LUALIB_API void olua_setvariable(lua_State *L, int idx)
{
    olua_assert(olua_isuserdata(L, idx));
    auxgetusertable(L, idx);        // L: k v uv
    lua_insert(L, -3);              // L: uv k v
    lua_rawset(L, -3);              // L: uv          idx.uservalue[k] = v
    lua_pop(L, 1);                  // L:
}

static void auxgetmappingtable(lua_State *L)
{
    if (lua_rawgetp(L, LUA_REGISTRYINDEX, (void *)auxgetmappingtable) == LUA_TNIL) {
        lua_pop(L, 1); // pop nil
        lua_newtable(L);
        lua_pushvalue(L, -1);
        lua_rawsetp(L, LUA_REGISTRYINDEX, (void *)auxgetmappingtable);
    }
    luaL_checktype(L, -1, LUA_TTABLE);
}

LUALIB_API int olua_ref(lua_State *L, int idx)
{
    static int ref = 0;
    if (!olua_isnil(L, idx)) {
        ref++;
        idx = lua_absindex(L, idx);
        auxgetmappingtable(L);
        lua_pushvalue(L, idx);
        lua_rawseti(L, -2, ref);
        lua_pop(L, 1);
        return ref;
    }
    return LUA_REFNIL;
}

LUALIB_API int olua_reffunc(lua_State *L, int idx)
{
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TFUNCTION);
    return olua_ref(L, idx);
}

LUALIB_API void olua_unref(lua_State *L, int ref)
{
    int top = lua_gettop(L);
    auxgetmappingtable(L);
    if (lua_rawgeti(L, top + 1, ref) != LUA_TNIL) {
        lua_pushnil(L);
        lua_rawseti(L, top + 1, ref);
    }
    lua_settop(L, top);
}

LUALIB_API void olua_getref(lua_State *L, int ref)
{
    auxgetmappingtable(L);
    lua_rawgeti(L, -1, ref);
    lua_remove(L, -2);
}

static const char *auxpushrefkey(lua_State *L, const char *field)
{
    return lua_pushfstring(L, ".ref.%s", field);
}

LUALIB_API void olua_getreftable(lua_State *L, int obj, const char *field)
{
    olua_assert(olua_isuserdata(L, obj));
    auxgetusertable(L, obj);                // L: uv
    field = auxpushrefkey(L, field);        // L: uv refkey
    luaL_getsubtable(L, -2, field);         // L: uv refkey reftable
    lua_insert(L, -3);                      // L: reftable uv refkey
    lua_pop(L, 2);                          // L: reftable
}

LUALIB_API void olua_singleref(lua_State *L, int obj, const char *field, int vidx)
{
    olua_assert(olua_isuserdata(L, obj));
    olua_assert(olua_isuserdata(L, vidx) || olua_isnil(L, vidx));
    vidx = lua_absindex(L, vidx);
    auxgetusertable(L, obj);                // L: uv
    auxpushrefkey(L, field);                // L: uv refk
    lua_pushvalue(L, vidx);                 // L: uv refk refv
    lua_rawset(L, -3);                      // L: uv      uv[refk] = refv
    lua_pop(L, 1);                          // L:
}

LUALIB_API void olua_singleunref(lua_State *L, int obj, const char *field)
{
    lua_pushnil(L);
    olua_singleref(L, obj, field, -1);
    lua_pop(L, 1);
}

static void auxmaprefvalue(lua_State *L, int obj, const char *t, int vidx, bool ref)
{
    olua_assert(olua_isuserdata(L, obj));
    olua_assert(olua_isuserdata(L, vidx));
    olua_assert(!lua_rawequal(L, obj, vidx));
    vidx = lua_absindex(L, vidx);
    olua_getreftable(L, obj, t);            // L: t
    lua_pushvalue(L, vidx);                 // L: t v
    if (ref) {
        lua_pushboolean(L, true);           // L: t v true
    } else {
        lua_pushnil(L);                     // L: t v nil
    }
    lua_rawset(L, -3);                      // L: t
    lua_pop(L, 1);
}

LUALIB_API void olua_mapref(lua_State *L, int obj, const char *t, int vidx)
{
    if (!olua_isnil(L, vidx)) {
        auxmaprefvalue(L, obj, t, vidx, true);
    }
}

LUALIB_API void olua_maprefarray(lua_State *L, int obj, const char *t, int vidx)
{
    olua_assert(olua_isuserdata(L, obj));
    olua_assert(olua_istable(L, vidx));
    vidx = lua_absindex(L, vidx);
    olua_getreftable(L, obj, t);                    // L: t
    if (olua_istable(L, vidx)) {
        lua_pushnil(L);                             // L: t k
        while (lua_next(L, vidx)) {                 // L: t k v
            olua_assert(olua_isuserdata(L, -1));
            lua_pushboolean(L, true);               // L: t k v true
            lua_rawset(L, -4);                      // L: t k       t[v] = true
        }
    }
    lua_pop(L, 1);                                  // L:
}

LUALIB_API void olua_mapunref(lua_State *L, int obj, const char *t, int vidx)
{
    if (!olua_isnil(L, vidx)) {
        auxmaprefvalue(L, obj, t, vidx, false);
    }
}

LUALIB_API void olua_mapwalkunref(lua_State *L, int obj, const char *t, lua_CFunction walk)
{
    olua_assert(olua_isuserdata(L, obj));
    obj = lua_absindex(L, obj);
    olua_getreftable(L, obj, t);            // L: t
    lua_pushnil(L);                         // L: t k
    while (lua_next(L, -2)) {               // L: t k v
        if (walk(L)) { // remove?
            lua_pushvalue(L, -2);           // L: t k v k
            lua_pushnil(L);                 // L: t k v k nil
            lua_rawset(L, -5);              // L: t k v
        }
        lua_pop(L, 1);                      // L: t k
    }
    lua_pop(L, 1);
}

LUALIB_API void olua_unrefall(lua_State *L, int obj, const char *t)
{
    olua_assert(olua_isuserdata(L, obj));
    auxgetusertable(L, obj);                // L: uv
    auxpushrefkey(L, t);                    // L: uv k
    lua_pushnil(L);                         // L: uv k nil
    lua_rawset(L, -3);                      // L: uv
    lua_pop(L, 1);                          // L:
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
    
    if (!func && olua_isstring(L, idx)) {
        func = olua_tostring(L, idx);
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


static int trycacheget(lua_State *L, int t, int kidx)
{
#define NILVALUE ((void *)trycacheget)
    int type;
    olua_assert(t <= LUA_REGISTRYINDEX && kidx > 0);
    lua_pushvalue(L, kidx);                     // L: k
    type = lua_rawget(L, t);                    // L: v
    if (type == LUA_TNIL) {
        lua_pop(L, 1);                          // L:
        lua_pushvalue(L, kidx);                 // L: k
        type = lua_gettable(L, t);              // L: v
        lua_pushvalue(L, kidx);                 // L: v k
        if (type == LUA_TNIL) {
            lua_pushlightuserdata(L, NILVALUE); // L: v k v
        } else {
            lua_pushvalue(L, -2);               // L: v k v
        }
        lua_rawset(L, t);                       // L: v
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
    lua_settop(L, 2);
    if (trycacheget(L, CLS_GETIDX, 2) != LUA_TNIL) {
        lua_pushvalue(L, 1);                        // L: t k getter t
        lua_call(L, 1, 1);                          // L: t k ret
        return 1;
    }
    
    // try func
    lua_settop(L, 2);
    if (trycacheget(L, CLS_FUNCIDX, 2) != LUA_TNIL) {
        return 1;
    }
    
    // try variable
    if (olua_isuserdata(L, 1)) {
        lua_settop(L, 2);
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
    lua_settop(L, 3);
    if (trycacheget(L, CLS_SETIDX, 2) != LUA_TNIL) {
        lua_pushvalue(L, 1);                    // L: t k v setter t
        lua_pushvalue(L, 3);                    // L: t k v setter t v
        lua_call(L, 2, 0);                      // L: t k v
        return 0;
    }
    
    if (olua_istable(L, 1)) {
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
    
    lua_settop(L, 3);
    if (trycacheget(L, CLS_GETIDX, 2) != LUA_TNIL) {
        luaL_error(L, "readonly property: %s", olua_tostring(L, 2));
    }
    
    olua_assert(olua_isuserdata(L, 1));
    if (olua_isuserdata(L, 1)) {
        if (olua_isstring(L, 2)) {
            size_t len;
            const char *key = olua_tolstring(L, 2, &len);
            if (len > 0 && key[0] == '.') {
                luaL_error(L, "variable name can't start with '.' char");
            }
        }
        lua_settop(L, 3);
        olua_setvariable(L, 1);
    }
    
    return 0;
}

static int cls_tostring(lua_State *L)
{
    olua_objtostring(L, 1);
    
    return 1;
}

static void create_table(lua_State *L, int idx, const char *field, const char *supercls, bool copy)
{
    idx = lua_absindex(L, idx);
    
    lua_newtable(L);                        // L: t
    if (supercls) {
        luaL_getmetatable(L, supercls);     // L: t super
        olua_rawget(L, -1, field);          // L: t super fv
        lua_createtable(L, 0, 1);           // L: t super fv mt
        lua_pushvalue(L, -2);               // L: t super fv mt fv
        olua_rawset(L, -2, "__index");      // L: t super fv mt
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
    olua_rawset(L, idx, field);             // L: t     idx[field] = t
}

static void copysupermetafunc(lua_State *L, int idx, const char *supercls)
{
    if (!supercls) {
        return;
    }
    
    idx = lua_absindex(L, idx);             // L: mt
    luaL_getmetatable(L, supercls);         // L: mt super
    lua_pushnil(L);                         // L: mt super k
    while (lua_next(L, -2)) {               // L: mt super k v
        if (ismetafunc(L, -2, NULL)) {
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
        if (luaL_getmetatable(L, super) == LUA_TNIL) {
            luaL_error(L, "'%s' super class '%s' is not found", cls, super);
        }
        lua_pop(L, 1);
    } else if (!strequal(cls, OLUA_VOIDCLS)) {
        oluacls_class(L, OLUA_VOIDCLS, NULL);
        lua_pop(L, 1);
        super = OLUA_VOIDCLS;
    }
    
    if (luaL_getmetatable(L, cls) == LUA_TNIL) {
        static const luaL_Reg lib[] = {
            {"__index", cls_index},
            {"__newindex", cls_newindex},
            {"__tostring", cls_tostring},
            {NULL, NULL}
        };
        
        int idx = lua_gettop(L);
        lua_pop(L, 1);
        luaL_newmetatable(L, cls);                      // L: mt
        copysupermetafunc(L, -1, super);

        lua_pushvalue(L, -1);                           // L: mt mt
        create_table(L, idx, CLS_ISA, super, true);     // L: mt mt .isa
        create_table(L, idx, CLS_FUNC, super, false);   // L: mt mt .isa .func
        create_table(L, idx, CLS_GET, super, false);    // L: mt mt .isa .func .get
        create_table(L, idx, CLS_SET, super, false);    // L: mt mt .isa .func .get .set
        luaL_setfuncs(L, lib,  5);                      // L: mt
        
        lua_pushvalue(L, -1);
        oluacls_const(L, "class");                      // mt.class = mt
        lua_pushstring(L, cls);
        oluacls_const(L, "classname");                  // mt.classname = cls
        
        if (super) {
            luaL_getmetatable(L, super);
            oluacls_const(L, "super");                  // mt.super = supermt
        }
        
        olua_rawget(L, idx, CLS_ISA);
        lua_pushstring(L, cls);
        lua_pushboolean(L, true);
        lua_rawset(L, -3);                              // mt[.isa][cls] = true
        lua_pop(L, 1);
        
        // for sotre static function callback
        auxgetobjtable(L);                              // L: mt objs
        lua_newuserdata(L, sizeof(void *));             // L: mt objs store
        lua_pushvalue(L, -1);                           // L: mt objs store store
        olua_rawset(L, -4, CLS_STORE);                  // L: mt objs store     mt[.store] = store
        lua_rawsetp(L, -2, lua_topointer(L, -1));       // L: mt objs           objs[store_ptr] = store
        lua_pop(L, 1);                                  // L: mt
    }
}

LUALIB_API void oluacls_createclassproxy(lua_State *L)
{
    lua_newtable(L);                        // L: cls p
    lua_createtable(L, 0, 2);               // L: cls p pmt
    lua_getfield(L, -3, "__index");         // L: cls p pmt __index
    olua_rawset(L, -2, "__index");          // L: cls p pmt
    lua_getfield(L, -3, "__newindex");      // L: cls p pmt __newindex
    olua_rawset(L, -2, "__newindex");       // L: cls p pmt
    lua_setmetatable(L, -2);                // L: cls p
}

static void aux_setfunc(lua_State *L, const char *t, const char *field, lua_CFunction func)
{
    if (func) {
        olua_rawget(L, -1, t);              // L: cls t
        lua_pushcfunction(L, func);         // L: cls t func
        olua_rawset(L, -2, field);          // L: cls t      t[field] = func
        lua_pop(L, 1);
    }
}

LUALIB_API void oluacls_prop(lua_State *L, const char *field, lua_CFunction getter, lua_CFunction setter)
{
    aux_setfunc(L, CLS_GET, field, getter);
    aux_setfunc(L, CLS_SET, field, setter);
}

LUALIB_API void oluacls_func(lua_State *L, const char *name, lua_CFunction func)
{
    aux_setfunc(L, CLS_FUNC, name, func);
    if (func && ismetafunc(L, 0, name)) {
        lua_pushcfunction(L, func);
        olua_rawset(L, -2, name);
    }
}

static int cls_index_const(lua_State *L)
{
    lua_pushvalue(L, lua_upvalueindex(1));
    return 1;
}

LUALIB_API void oluacls_const(lua_State *L, const char *field)
{
    lua_pushvalue(L, -1);                       // L: cls v v
    olua_rawset(L, -3, field);                  // L: cls v
    lua_pushcclosure(L, cls_index_const, 1);    // L: cls getter
    olua_rawget(L, -2, CLS_GET);                // L: cls getter .get
    lua_insert(L, -2);                          // L: cls .get getter
    olua_rawset(L, -2, field);                  // L: cls .get
    lua_pop(L, 1);                              // L: cls
}

LUALIB_API int olua_push_bool(lua_State *L, bool value)
{
    lua_pushboolean(L, value);
    return 1;
}

LUALIB_API void olua_check_bool(lua_State *L, int idx, bool *value)
{
    *value = olua_checkboolean(L, idx);
}

LUALIB_API void olua_opt_bool(lua_State *L, int idx, bool *value, bool def)
{
    *value = olua_optboolean(L, idx, def);
}

LUALIB_API int olua_push_string(lua_State *L, const char *value)
{
    lua_pushstring(L, value);
    return 1;
}

LUALIB_API void olua_check_string(lua_State *L, int idx, const char **value)
{
    *value = olua_checkstring(L, idx);
}

LUALIB_API void olua_opt_string(lua_State *L, int idx, const char **value, const char *def)
{
    *value = olua_optstring(L, idx, def);
}

LUALIB_API int olua_push_number(lua_State *L, lua_Number value)
{
    lua_pushnumber(L, value);
    return 1;
}

LUALIB_API void olua_check_number(lua_State *L, int idx, lua_Number *value)
{
    *value = olua_checknumber(L, idx);
}

LUALIB_API void olua_opt_number(lua_State *L, int idx, lua_Number *value, lua_Number def)
{
    *value = olua_optnumber(L, idx, def);
}

LUALIB_API int olua_push_int(lua_State *L, lua_Integer value)
{
    lua_pushinteger(L, value);
    return 1;
}

LUALIB_API void olua_check_int(lua_State *L, int idx, lua_Integer *value)
{
    *value = olua_checkinteger(L, idx);
}

LUALIB_API void olua_opt_int(lua_State *L, int idx, lua_Integer *value, lua_Integer def)
{
    *value = olua_optinteger(L, idx, def);
}

LUALIB_API int olua_push_uint(lua_State *L, lua_Unsigned value)
{
    return olua_push_int(L, (lua_Integer)value);
}

LUALIB_API void olua_check_uint(lua_State *L, int idx, lua_Unsigned *value)
{
    *value = (lua_Unsigned)olua_checkinteger(L, idx);
}

LUALIB_API void olua_opt_uint(lua_State *L, int idx, lua_Unsigned *value, lua_Unsigned def)
{
    *value = (lua_Unsigned)olua_optinteger(L, idx, (lua_Integer)def);
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

LUALIB_API void olua_opt_obj(lua_State *L, int idx, void **value, const char *cls, void *def)
{
    if (olua_isnil(L, idx)) {
        *value = def;
    } else {
        olua_check_obj(L, idx, value, cls);
    }
}

LUALIB_API void olua_to_obj(lua_State *L, int idx, void **value, const char *cls)
{
    *value = olua_toobj(L, idx, cls);
}

static void auxchecktype(lua_State *L, int t, const char *field, int type, bool isinteger)
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
    auxchecktype(L, idx, field, LUA_TSTRING, false);
    value = olua_tostring(L, -1);
    lua_pop(L, 1);
    return value;
}

LUALIB_API lua_Number olua_checkfieldnumber(lua_State *L, int idx, const char *field)
{
    lua_Number value;
    auxchecktype(L, idx, field, LUA_TNUMBER, false);
    value = olua_tonumber(L, -1);
    lua_pop(L, 1);
    return value;
}

LUALIB_API lua_Integer olua_checkfieldinteger(lua_State *L, int idx, const char *field)
{
    lua_Integer value;
    auxchecktype(L, idx, field, LUA_TNUMBER, true);
    value = olua_tointeger(L, -1);
    lua_pop(L, 1);
    return value;
}

LUALIB_API bool olua_checkfieldboolean(lua_State *L, int idx, const char *field)
{
    bool value;
    auxchecktype(L, idx, field, LUA_TBOOLEAN, false);
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
    int type = lua_getfield(L, idx, field);
    lua_pop(L, 1);
    return type != LUA_TNIL;
}

static int _olua_with(lua_State *L)
{
    lua_settop(L, 3);
    luaL_checktype(L, 1, LUA_TUSERDATA);
    luaL_checktype(L, 3, LUA_TFUNCTION);
    const char *cls = olua_checkstring(L, 2);
    if (!lua_getmetatable(L, 1)) {      // L: obj cls func mt
        lua_pushnil(L);                 // L: obj cls func nil
    }
    
    if (luaL_getmetatable(L, cls) == LUA_TTABLE) {
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

LUALIB_API int luaopen_olua(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"with", _olua_with},
        {NULL, NULL}
    };
    
    luaL_newlib(L,lib);
    
    return 1;
}
