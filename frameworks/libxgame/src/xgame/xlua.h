#ifndef __XLUA_H__
#define __XLUA_H__

#define olua_mainthread()           xlua_cocosthread()
#define olua_startcmpunref(L, i, n) xlua_startcmpunref(L, i, n)
#define olua_endcmpunref(L, i, n)   xlua_endcmpunref(L, i, n)
#define olua_handlestatus(L, v, s)  xlua_handlestatus(L, v, s)

#include "xgame/xdef.h"
#include "lua.hpp"
#include "olua/olua.hpp"

#include "cocos2d.h"

lua_State *xlua_new();

lua_State *xlua_cocosthread();

int xlua_pcall(lua_State *L, int n, int r);
void xlua_call(lua_State *L, lua_CFunction func);
int xlua_dofile(lua_State *L, const char *filename);

int xlua_nonsupport(lua_State *L);

int xlua_ccobjgc(lua_State *L);

template <typename T> void xlua_handlestatus(lua_State *L, T* value, int status)
{
    if ((status == OLUA_OBJ_NEW || status == OLUA_OBJ_UPDATE) &&
        std::is_base_of<cocos2d::Ref, T>::value) {
        ((cocos2d::Ref *)value)->retain();
#ifdef COCOS2D_DEBUG
        if (!olua_isa(L, -1, "cc.Ref")) {
            luaL_error(L, "class '%s' not inherit from 'cc.Ref'", olua_getluatype(L, value, ""));
        }
#endif
        olua_addobjcount(L);
    }
}

void xlua_startcmpunref(lua_State *L, int idx, const char *refname);
void xlua_endcmpunref(lua_State *L, int idx, const char *refname);

#endif
