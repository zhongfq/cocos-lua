#ifndef __XGAME_LUA_H__
#define __XGAME_LUA_H__

#include "cocos2d.h"
#include "xgame/luauser.h"
#include "xgame/runtime.h"
#include "olua/olua.hpp"

extern lua_State *xlua_invokingstate;

lua_State *xlua_new();
int xlua_dofile(lua_State *L, const char *filename);
int xlua_ccobjgc(lua_State *L);
int xlua_nonsupport(lua_State *L);

//
// implement olua api
//
#ifdef OLUA_HAVE_MAINTHREAD
lua_State *olua_mainthread(lua_State *L);
#endif

#ifdef OLUA_HAVE_CHECKHOSTTHREAD
#define olua_checkhostthread()  assert(xgame::runtime::isCocosThread() && "callback should run on cocos thread")
#endif

#ifdef OLUA_HAVE_TRACEINVOKING
#define olua_startinvoke(L)     (xlua_invokingstate = L)
#define olua_endinvoke(L)       (xlua_invokingstate = nullptr)
#endif

#ifdef OLUA_HAVE_CMPREF
void olua_startcmpref(lua_State *L, int idx, const char *refname);
void olua_endcmpref(lua_State *L, int idx, const char *refname);
#endif

#ifdef OLUA_HAVE_LUATYPE
void olua_registerluatype(lua_State *L, const char *type, const char *cls);
const char *olua_getluatype(lua_State *L, const char *type);
#endif

#ifdef OLUA_HAVE_POSTPUSH
template <typename T> void olua_postpush(lua_State *L, T* obj, int status)
{
    if (std::is_base_of<cocos2d::Ref, T>::value &&
            (status == OLUA_OBJ_NEW || status == OLUA_OBJ_UPDATE)) {
        ((cocos2d::Ref *)obj)->retain();
#ifdef COCOS2D_DEBUG
        if (!olua_isa<cocos2d::Ref>(L, -1)) {
            luaL_error(L, "class '%s' not inherit from 'cc.Ref'", olua_getluatype(L, obj, ""));
        }
#endif
    }
}
#endif

#ifdef OLUA_HAVE_POSTNEW
template <typename T> void olua_postnew(lua_State *L, T *obj)
{
    if (std::is_base_of<cocos2d::Ref, T>::value) {
        ((cocos2d::Ref *)obj)->autorelease();
    } else {
        olua_assert(obj == olua_toobj<T>(L, -1), "must be same object");
        olua_setownership(L, -1, OLUA_OWNERSHIP_VM);
    }
}
#endif

#endif
