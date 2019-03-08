#ifndef __XLUA_H__
#define __XLUA_H__

#include "xgame/xdef.h"
#include "lua.hpp"

#include "cocos2d.h"

lua_State *xlua_new();
lua_State *xlua_mainthread(lua_State *L);
lua_State *xlua_cocosthread();

void xlua_preload(lua_State *L, const char *name, lua_CFunction func);
void xlua_require(lua_State *L, const char *name, lua_CFunction func);
int xlua_errorfunc(lua_State *L);
int xlua_pcall(lua_State *L, int n, int r);
void xlua_call(lua_State *L, lua_CFunction func);
int xlua_dofile(lua_State *L, const char *filename);

int xlua_ref(lua_State *L, int idx);
int xlua_reffunc(lua_State *L, int idx);
void xlua_unref(lua_State *L, int ref);
void xlua_getref(lua_State *L, int ref);

bool xlua_optboolean(lua_State *L, int idx, bool def);
bool xlua_checkboolean(lua_State *L, int idx);
void *xlua_checkobj(lua_State *L, int idx);
void xlua_setnilfield(lua_State *L, const char *field);
int xlua_rawgetfield(lua_State *L, int idx, const char *field);
void xlua_rawsetfield(lua_State *L, int idx, const char *field);
void xlua_setfunc(lua_State *L, const char *field, lua_CFunction func);
const char *xlua_optfieldstring(lua_State *L, int idx, const char *field, const char *def);
bool xlua_optfieldboolean(lua_State *L, int idx, const char *field, bool def);
lua_Number xlua_optfieldnumber(lua_State *L, int idx, const char *field, lua_Number def);
lua_Integer xlua_optfieldinteger(lua_State *L, int idx, const char *field, lua_Integer def);
const char *xlua_checkfieldstring(lua_State *L, int idx, const char *field);
lua_Number xlua_checkfieldnumber(lua_State *L, int idx, const char *field);
lua_Integer xlua_checkfieldinteger(lua_State *L, int idx, const char *field);
bool xlua_checkfieldboolean(lua_State *L, int idx, const char *field);
void xlua_rawsetfieldnumber(lua_State *L, int idx, const char *field, lua_Number value);
void xlua_rawsetfieldinteger(lua_State *L, int idx, const char *field, lua_Integer value);
void xlua_rawsetfieldstring(lua_State *L, int idx, const char *field, const char *value);
void xlua_rawsetfieldboolean(lua_State *L, int idx, const char *field, bool value);

int xlua_ccobjgc(lua_State *L);

int xlua_refcount();
void xlua_addref();
void xlua_subref();

int xluacv_push_ccdata(lua_State *L, const cocos2d::Data &value);

void xluacv_check_obj(lua_State *L, int idx, void **value);
bool xluacv_is_obj(lua_State *L, int idx);

template <typename T> int xluacv_push_ccobj(lua_State *L, T* value, const char *cls)
{
    bool is_new = false;
    
    if (!value) {
        lua_pushnil(L);
    } else {
        is_new = tolua_pushobj(L, value, cls);
    }
    
    if (is_new && std::is_base_of<cocos2d::Ref, T>::value) {
        ((cocos2d::Ref *)value)->retain();
        xlua_addref();
    }
    
    return 1;
}

void xluacv_to_ccobj(lua_State *L, int idx, void **value, const char *cls);
void xluacv_check_ccobj(lua_State *L, int idx, void **value, const char *cls);
bool xluacv_is_ccobj(lua_State *L, int idx, const char *cls);

int xluacv_push_ccmat4(lua_State *L, const cocos2d::Mat4 &value);
void xluacv_check_ccmat4(lua_State *L, int idx, cocos2d::Mat4 *value);

// Vector
template <typename T> int xluacv_push_ccvector(lua_State *L, const cocos2d::Vector<T*> &v, const char *cls)
{
    lua_newtable(L);
    int i = 1;
    for (const auto obj : v) {
        if (obj == nullptr) {
            continue;
        }
        xluacv_push_ccobj(L, obj, cls);
        lua_rawseti(L, -2, i);
        i++;
    }
    return 1;
}

template <typename T> void xluacv_check_ccvector(lua_State *L, int idx, cocos2d::Vector<T*> &v, const char *cls)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    size_t total = lua_rawlen(L, idx);
    v.reserve(total);
    for (int i = 1; i <= total; i++) {
        lua_rawgeti(L, idx, i);
        T* obj;
        xluacv_check_ccobj(L, -1, (void **)&obj, cls);
        v.pushBack(obj);
        lua_pop(L, 1);
    }
}

#endif
