#ifndef __XGAME_LUA_H__
#define __XGAME_LUA_H__

#include "xgame/config.h"
#include "cocos2d.h"
#include "lua.hpp"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#define CCLUA_HAVE_WEBVIEW
#define CCLUA_HAVE_VIDEOPLAYER
#endif

#define olua_mainthread(L)              xlua_mainthread(L)
#define olua_startcmpdelref(L, i, n)    xlua_startcmpdelref(L, (i), (n))
#define olua_endcmpdelref(L, i, n)      xlua_endcmpdelref(L, (i), (n))
#define olua_postpush(L, v, s)          xlua_postpush(L, (v), (s))
#define olua_postnew(L, obj)            xlua_postnew(L, (obj))
#define olua_startinvoke(L)             (xlua_invokingstate = L)
#define olua_endinvoke(L)               (xlua_invokingstate = nullptr)

#define oluai_registerluatype(L, t, c)  (xlua_registerluatype(L, (t), (c)))
#define oluai_getluatype(L, t)          (xlua_getluatype(L, (t)))

extern lua_State *xlua_invokingstate;

lua_State *xlua_new();
int xlua_dofile(lua_State *L, const char *filename);
int xlua_nonsupport(lua_State *L);
int xlua_ccobjgc(lua_State *L);

lua_State *xlua_mainthread(lua_State *L);
void xlua_startcmpdelref(lua_State *L, int idx, const char *refname);
void xlua_endcmpdelref(lua_State *L, int idx, const char *refname);

template <typename T> void xlua_postpush(lua_State *L, T* obj, int status);
template <typename T> void xlua_postnew(lua_State *L, T *obj);

void xlua_registerluatype(lua_State *L, const char *type, const char *cls);
const char *xlua_getluatype(lua_State *L, const char *type);


#include "olua/olua.hpp"

template <typename T> void xlua_postpush(lua_State *L, T* obj, int status)
{
    if (std::is_base_of<cocos2d::Ref, T>::value &&
            (status == OLUA_OBJ_NEW || status == OLUA_OBJ_UPDATE)) {
        ((cocos2d::Ref *)obj)->retain();
#ifdef COCOS2D_DEBUG
        if (!olua_isa<cocos2d::Ref>(L, -1)) {
            luaL_error(L, "class '%s' not inherit from 'cc.Ref'", olua_getluatype(L, obj, ""));
        }
#endif
        olua_addobjcount(L);
    }
}

template <typename T> void xlua_postnew(lua_State *L, T *obj)
{
    if (std::is_base_of<cocos2d::Ref, T>::value) {
        ((cocos2d::Ref *)obj)->autorelease();
    } else {
        CCASSERT(obj == olua_toobj<T>(L, -1), "must be same object");
        lua_pushstring(L, ".ownership");
        lua_pushboolean(L, true);
        olua_setvariable(L, -3);
    }
}

#endif
