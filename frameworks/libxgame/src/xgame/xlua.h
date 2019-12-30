#ifndef __XLUA_H__
#define __XLUA_H__

#define olua_mainthread()               xlua_cocosthread()
#define olua_startcmpunhold(L, i, n)    xlua_startcmpunhold(L, i, n)
#define olua_endcmpunhold(L, i, n)      xlua_endcmpunhold(L, i, n)
#define olua_startinvoke(L)             xlua_startinvoke(L)
#define olua_endinvoke(L)               xlua_endinvoke(L)
#define olua_postpush(L, v, s)          xlua_postpush(L, v, s)
#define olua_postnew(L, obj)            xlua_postnew(L, obj)

#include "xgame/xdef.h"
#include "olua/olua.hpp"

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#define CCLUA_HAVE_WEBVIEW
#define CCLUA_HAVE_VIDEOPLAYER
#endif

lua_State *xlua_new();

lua_State *xlua_cocosthread();

int xlua_dofile(lua_State *L, const char *filename);

int xlua_nonsupport(lua_State *L);

int xlua_ccobjgc(lua_State *L);

template <typename T> void xlua_postpush(lua_State *L, T* obj, int status)
{
    if (std::is_base_of<cocos2d::Ref, T>::value && status == OLUA_NEW) {
        ((cocos2d::Ref *)obj)->retain();
#ifdef COCOS2D_DEBUG
        if (!olua_isa(L, -1, "cc.Ref")) {
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

void xlua_startinvoke(lua_State *L);
void xlua_endinvoke(lua_State *L);
void xlua_startcmpunhold(lua_State *L, int idx, const char *refname);
void xlua_endcmpunhold(lua_State *L, int idx, const char *refname);

#endif
