#ifndef __XLUA_CONV_H__
#define __XLUA_CONV_H__

#include "xgame/xdef.h"
#include "lua.hpp"

#include "cocos2d.h"

int xlua_ccobjgc(lua_State *L);
int xlua_ccobjcount(lua_State *L);

int xluacv_push_ccdata(lua_State *L, const cocos2d::Data &value);

int xluacv_push_ccobj(lua_State *L, cocos2d::Ref *obj, const char *cls);
void xluacv_to_ccobj(lua_State *L, int idx, void **value, const char *cls);
void xluacv_check_ccobj(lua_State *L, int idx, void **value, const char *cls);
bool xluacv_is_ccobj(lua_State *L, int idx, const char *cls);

// vec2
int xluacv_push_ccvec2(lua_State *L, const cocos2d::Vec2 &value);
void xluacv_check_ccvec2(lua_State *L, int idx, cocos2d::Vec2 *value);
void xluacv_pack_ccvec2(lua_State *L, int idx, cocos2d::Vec2 *value);
int xluacv_unpack_ccvec2(lua_State *L, const cocos2d::Vec2 &value);

#endif
