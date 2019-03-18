#ifndef __XLUA_H__
#define __XLUA_H__

#include "xgame/xdef.h"
#include "lua.hpp"
#include "olua/olua.hpp"

#include "cocos2d.h"

lua_State *xlua_new();

// #define OLUA_MAINTHREAD=xlua_cocosthread
lua_State *xlua_cocosthread();

int xlua_errorfunc(lua_State *L);
int xlua_pcall(lua_State *L, int n, int r);
void xlua_call(lua_State *L, lua_CFunction func);
int xlua_dofile(lua_State *L, const char *filename);

int xlua_ref(lua_State *L, int idx);
int xlua_reffunc(lua_State *L, int idx);
void xlua_unref(lua_State *L, int ref);
void xlua_getref(lua_State *L, int ref);

int xlua_ccobjgc(lua_State *L);

// #define OLUA_REPORT_PUSH_STATUS=xlua_report_push_status
template <typename T> void xlua_report_push_status(lua_State *L, T* value, int status)
{
    if ((status == OLUA_OBJ_NEW || status == OLUA_OBJ_UPDATE) &&
        std::is_base_of<cocos2d::Ref, T>::value) {
        ((cocos2d::Ref *)value)->retain();
        olua_addobjcount();
    }
}


#endif
