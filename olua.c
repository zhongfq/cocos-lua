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
#define OLUA_POOL_TABLE ((void *)olua_objpool_push)
#define OLUA_REF_TABLE  ((void *)auxgetmappingtable)
#define OLUA_EXTRASPACE ((void *)lua_getextraspace)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

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
        olua_traceback(L, lua_tothread(L, 1), lua_tostring(L, 2), 0);
        lua_insert(L, 1);
    }
    olua_traceback(L, L, lua_tostring(L, 1), 1);
    printf("%s\n", lua_tostring(L, -1));
    return 0;
}

static int _metadata_gc(lua_State *L)
{
    olua_metadata_t *mt = olua_touserdata(L, 1, olua_metadata_t *);
    free(mt);
    return 0;
}

LUALIB_API lua_State *olua_newstate(olua_metadata_t *mt)
{
    lua_State *L = luaL_newstate();
    mt = mt != NULL ? mt : ((olua_metadata_t *)malloc(sizeof(*mt)));
    mt->objcount = 0;
    mt->sizepool = 0;
    mt->usingpool = false;
    *(olua_metadata_t **)lua_getextraspace(L) = mt;
    
    olua_newuserdata(L, mt, olua_metadata_t *);
    lua_pushvalue(L, 1);
    olua_rawsetp(L, LUA_REGISTRYINDEX, (void *)mt);
    lua_createtable(L, 0, 1);
    lua_pushcfunction(L, _metadata_gc);
    olua_rawsetf(L, -2, "__gc");
    lua_setmetatable(L, -2);
    
    return L;
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

LUALIB_API size_t olua_changeobjcount(lua_State *L, int add)
{
    olua_metadata_t *mt = olua_getmetadata(L, olua_metadata_t *);
    mt->objcount += add;
    return mt->objcount;
}

LUALIB_API void olua_preload(lua_State *L, const char *name, lua_CFunction func)
{
    olua_getsubtable(L, LUA_REGISTRYINDEX, LUA_PRELOAD_TABLE);  // L: preload
    lua_pushcfunction(L, func);                                 // L: preload func
    lua_setfield(L, -2, name);                                  // L: preload
    lua_pop(L, 1);                                              // L:
}

LUALIB_API int olua_geterrorfunc(lua_State *L)
{
    if (olua_getglobal(L, "__TRACEBACK__") != LUA_TFUNCTION) {
        lua_pop(L, 1);
        lua_pushcfunction(L, errfunc);
    }
    return lua_gettop(L);
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
    intptr_t p;
    if (lua_getmetatable(L, idx)) {
        if (olua_rawgetf(L, -1, "classname") == LUA_TSTRING) {
            tn = olua_tostring(L, -1);
        }
        lua_pop(L, 2); // pop mt and value
    }
    if (!tn) {
        tn = lua_typename(L, lua_type(L, idx));
    }
    if (olua_isuserdata(L, idx)) {
        p = (intptr_t)olua_touserdata(L, idx, void *);
    } else {
        p = (intptr_t)lua_topointer(L, idx);
    }
    return lua_pushfstring(L, "%s: %p", tn, p);
}

LUALIB_API bool olua_isa(lua_State *L, int idx, const char *cls)
{
    bool isa = false;
    int top = lua_gettop(L);
    if (lua_getmetatable(L, idx)) {
        if (olua_rawgetf(L, -1, CLS_ISA) == LUA_TTABLE) {
            olua_rawgetf(L, -1, cls);
            isa = olua_toboolean(L, -1);
        }
    }
    lua_settop(L, top);
    return isa;
}

static void auxgetobjtable(lua_State *L)
{
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_OBJ_TABLE) != LUA_TTABLE) {
        lua_pop(L, 1); // pop nil
        lua_newtable(L);
        lua_pushvalue(L, -1);
        lua_pushstring(L, "kv");
        lua_setfield(L, -2, "__mode");  // mt.__mode = 'kv'
        lua_setmetatable(L, -2);        // mt.metatable = mt
        lua_pushvalue(L, -1);
        olua_rawsetp(L, LUA_REGISTRYINDEX, OLUA_OBJ_TABLE);
    }
}

static inline bool isusingpool(lua_State *L)
{
    return olua_getmetadata(L, olua_metadata_t *)->usingpool;
}

static int olua_objpool_push(lua_State *L, void *obj, const char *cls)
{
    olua_metadata_t *mt = olua_getmetadata(L, olua_metadata_t *);
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_POOL_TABLE) != LUA_TTABLE) {
        lua_pop(L, 1);
        lua_createtable(L, 16, 0);
        lua_pushvalue(L, -1);
        olua_rawsetp(L, LUA_REGISTRYINDEX, OLUA_POOL_TABLE);
    }
    
    mt->sizepool++;
    
    if (olua_rawgeti(L, -1, mt->sizepool) != LUA_TUSERDATA) {
        lua_pop(L, 1);
        lua_newuserdata(L, sizeof(void *));
        lua_pushvalue(L, -1);
        olua_rawseti(L, -3, mt->sizepool);
    }
    
    *(void **)lua_touserdata(L, -1) = obj;
    olua_setmetatable(L, cls);
    
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
    
    auxgetobjtable(L);
    
    if (olua_rawgetp(L, -1, obj) == LUA_TNIL) {     // L: mapping obj?
        lua_pop(L, 1);                              // L: mapping
        
        if (isusingpool(L)) {
            lua_pop(L, 1);
            return olua_objpool_push(L, obj, cls);
        }
        
        olua_newuserdata(L, obj, void *);           // L: mapping obj
        olua_setmetatable(L, cls);                  // L: mapping obj
        lua_pushvalue(L, -1);                       // L: mapping obj obj
        olua_rawsetp(L, -3, obj);                   // L: mapping obj
        status = OLUA_OBJ_NEW;
        
        if (!lua_getmetatable(L, -1)) {
            luaL_error(L, "metatable not found: %s", cls);
        } else {
            lua_pop(L, 1);
        }
    }
    
    lua_remove(L, -2);                              // L: obj
    
    if (!strequal(cls, OLUA_VOIDCLS) && olua_testudata(L, -1, OLUA_VOIDCLS)) {
        olua_setmetatable(L, cls);
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
    if (olua_rawgetp(L, -1, obj) == LUA_TUSERDATA) {// L: objt obj
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
            luaL_error(L, "object '%s' live from gc", olua_typename(L, idx));
        }
    } else {
        luaL_error(L, "#%d argument error, expect: '%s', got '%s'", idx,
            cls, lua_typename(L, lua_type(L, idx)));
    }
    return NULL;
}

LUALIB_API void olua_enable_objpool(lua_State *L)
{
    olua_getmetadata(L, olua_metadata_t *)->usingpool = true;
}

LUALIB_API void olua_disable_objpool(lua_State *L)
{
    olua_getmetadata(L, olua_metadata_t *)->usingpool = false;
}

LUALIB_API size_t olua_push_objpool(lua_State *L)
{
    return olua_getmetadata(L, olua_metadata_t *)->sizepool;
}

LUALIB_API void olua_pop_objpool(lua_State *L, size_t level)
{
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_POOL_TABLE) == LUA_TTABLE) {
        olua_getmetadata(L, olua_metadata_t *)->sizepool = level;
        size_t len = lua_rawlen(L, -1);
        olua_assert(level < len);
        for (size_t i = level + 1; i <= len; i++) {
            olua_rawgeti(L, -1, (lua_Integer)i);
            void **ud = (void **)lua_touserdata(L, -1);
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
    static unsigned int ref = 0;
    
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

LUALIB_API void olua_removecallback(lua_State *L, void *obj, const char *tag, olua_callback_tag_t mode)
{
    if (!olua_getobj(L, obj)) {
        return;
    }
    
    auxgetusertable(L, -1);                             // L: obj ct
    if (mode == OLUA_CALLBACK_TAG_EQUAL) {
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
    int status = OLUA_CALLBACK_MISS;
    
    if (olua_getobj(L, obj)) {                              // L: arg...n obj
        auxgetusertable(L, -1);                             // L: arg...n obj uv
        if (olua_rawgetf(L, -1, func) == LUA_TFUNCTION) {   // L: arg...n obj uv callback
            lua_insert(L, top + 1);                         // L: callback arg...n obj uv
            lua_pop(L, 2);                                  // L: callback arg...n
            olua_geterrorfunc(L);                           // L: callback arg...n errfunc
            lua_insert(L, top + 1);                         // L: errfunc callback arg...n
            if (lua_pcall(L, argc, 1, top + 1) == LUA_OK) { // L: errfunc result
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
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_REF_TABLE) != LUA_TTABLE) {
        lua_pop(L, 1); // pop nil
        lua_newtable(L);
        lua_pushvalue(L, -1);
        olua_rawsetp(L, LUA_REGISTRYINDEX, OLUA_REF_TABLE);
    }
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
    if (olua_rawgeti(L, top + 1, ref) != LUA_TNIL) {
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
    olua_getsubtable(L, -2, field);         // L: uv refkey reftable
    lua_insert(L, -3);                      // L: reftable uv refkey
    lua_pop(L, 2);                          // L: reftable
}

LUALIB_API void olua_singleref(lua_State *L, int idx, const char *name, int obj)
{
    olua_assert(olua_isuserdata(L, idx));
    olua_assert(olua_isuserdata(L, obj) || olua_isnil(L, obj));
    obj = lua_absindex(L, obj);
    auxgetusertable(L, idx);                // L: uv
    auxpushrefkey(L, name);                 // L: uv refk
    lua_pushvalue(L, obj);                  // L: uv refk refv
    lua_rawset(L, -3);                      // L: uv      uv[refk] = refv
    lua_pop(L, 1);                          // L:
}

LUALIB_API void olua_singleunref(lua_State *L, int obj, const char *name)
{
    lua_pushnil(L);
    olua_singleref(L, obj, name, -1);
    lua_pop(L, 1);
}

static void auxmaprefvalue(lua_State *L, int idx, const char *name, int obj, bool ref)
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
        auxmaprefvalue(L, idx, name, obj, true);
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
        auxmaprefvalue(L, idx, name, obj, false);
    }
}

LUALIB_API void olua_mapwalkunref(lua_State *L, int idx, const char *name, lua_CFunction walk)
{
    olua_assert(olua_isuserdata(L, idx));
    idx = lua_absindex(L, idx);
    olua_getreftable(L, idx, name);         // L: t
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

LUALIB_API void olua_unrefall(lua_State *L, int idx, const char *name)
{
    olua_assert(olua_isuserdata(L, idx));
    auxgetusertable(L, idx);                // L: uv
    auxpushrefkey(L, name);                 // L: uv k
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
    type = olua_rawget(L, t);                   // L: v
    if (type == LUA_TNIL) {
        lua_pop(L, 1);                          // L:
        lua_pushvalue(L, kidx);                 // L: k
        type = olua_gettable(L, t);             // L: v
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
        if (olua_isuserdata(L, 1)) {
            lua_pushvalue(L, 1);                // L: t k v setter t
            lua_pushvalue(L, 3);                // L: t k v setter t v
            lua_call(L, 2, 0);                  // L: t k v
        } else {
            // static setter, accessed by class proxy
            lua_pushvalue(L, 3);                // L: t k v setter v
            lua_call(L, 1, 0);                  // L: t k v
        }
        return 0;
    }
    
    if (olua_istable(L, 1)) {
        lua_settop(L, 3);                       // L: t k v
        lua_pushvalue(L, 2);                    // L: t k v k
        lua_pushvalue(L, 3);                    // L: t k v k v
        lua_rawset(L, CLS_FUNCIDX);             // L: t k v
        
        if (ismetafunc(L, 2, NULL)) {
            lua_pushvalue(L, 2);                // L: t k v k
            lua_pushvalue(L, 3);                // L: t k v k v
            lua_rawset(L, CLS_CLSIDX);          // L: t k v
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
    olua_typename(L, 1);
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
        olua_rawsetf(L, -2, "__index");     // L: t super fv mt
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
    olua_rawsetf(L, idx, field);            // L: t     idx[field] = t
}

static void copysupermetafunc(lua_State *L, int idx, const char *supercls)
{
    if (!supercls) {
        return;
    }
    
    idx = lua_absindex(L, idx);             // L: mt
    olua_getmetatable(L, supercls);         // L: mt super
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
        if (olua_getmetatable(L, super) == LUA_TNIL) {
            luaL_error(L, "'%s' super class '%s' is not found", cls, super);
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
        copysupermetafunc(L, -1, super);

        lua_pushvalue(L, -1);                           // L: mt mt
        create_table(L, idx, CLS_ISA, super, true);     // L: mt mt .isa
        create_table(L, idx, CLS_FUNC, super, false);   // L: mt mt .isa .func
        create_table(L, idx, CLS_GET, super, false);    // L: mt mt .isa .func .get
        create_table(L, idx, CLS_SET, super, false);    // L: mt mt .isa .func .get .set
        olua_setfuncs(L, lib,  5);                      // L: mt
        
        lua_pushvalue(L, -1);
        oluacls_const(L, "class");                      // mt.class = mt
        lua_pushstring(L, cls);
        oluacls_const(L, "classname");                  // mt.classname = cls
        
        if (super) {
            olua_getmetatable(L, super);
            oluacls_const(L, "super");                  // mt.super = supermt
        }
        
        olua_rawgetf(L, idx, CLS_ISA);
        lua_pushstring(L, cls);
        lua_pushboolean(L, true);
        lua_rawset(L, -3);                              // mt[.isa][cls] = true
        lua_pop(L, 1);
        
        // for sotre static function callback
        auxgetobjtable(L);                              // L: mt objs
        lua_newuserdata(L, sizeof(void *));             // L: mt objs store
        lua_pushvalue(L, -1);                           // L: mt objs store store
        olua_rawsetf(L, -4, CLS_STORE);                 // L: mt objs store     mt[.store] = store
        olua_rawsetp(L, -2, lua_topointer(L, -1));      // L: mt objs           objs[store_ptr] = store
        lua_pop(L, 1);                                  // L: mt
    }
}

LUALIB_API void oluacls_createclassproxy(lua_State *L)
{
    lua_newtable(L);                        // L: cls p
    lua_createtable(L, 0, 2);               // L: cls p pmt
    lua_getfield(L, -3, "__index");         // L: cls p pmt __index
    olua_rawsetf(L, -2, "__index");         // L: cls p pmt
    lua_getfield(L, -3, "__newindex");      // L: cls p pmt __newindex
    olua_rawsetf(L, -2, "__newindex");      // L: cls p pmt
    lua_setmetatable(L, -2);                // L: cls p
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
    if (func && ismetafunc(L, 0, name)) {
        lua_pushcfunction(L, func);
        olua_rawsetf(L, -2, name);
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
    int type = olua_getfield(L, idx, field);
    lua_pop(L, 1);
    return type != LUA_TNIL;
}

static int _lwith(lua_State *L)
{
    lua_settop(L, 3);
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

static int _lisa(lua_State *L)
{
    lua_settop(L, 2);
    olua_isa(L, 1, olua_checkstring(L, 2));
    return 1;
}

LUALIB_API int luaopen_olua(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"with", _lwith},
        {"isa", _lisa},
        {NULL, NULL}
    };
    
    olua_newlib(L,lib);
    
    return 1;
}

#if LUA_VERSION_NUM == 501
LUALIB_API void *lua_getextraspace(lua_State *L)
{
    void *p;
    if (olua_rawgetp(L, LUA_REGISTRYINDEX, OLUA_EXTRASPACE) == LUA_TNIL)
    {
        lua_pop(L, 1);
        lua_newuserdata(L, sizeof(olua_metadata_t *));
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
        lua_setfenv(L, idx);
    }
}

LUALIB_API int lua_getuservalue(lua_State *L, int idx)
{
    lua_getfenv(L, idx);
    return lua_type(L, -1);
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
    for (; l->name != NULL; l++)
    {
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
