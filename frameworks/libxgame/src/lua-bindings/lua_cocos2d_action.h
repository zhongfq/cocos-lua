//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_COCOS2D_ACTION_H__
#define __AUTO_GEN_LUA_COCOS2D_ACTION_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "cocos2d.h"
#include "cclua/xlua.h"

int luaopen_cocos2d_action(lua_State *L);

// cocos2d::ActionFloat::ActionFloatCallback
bool olua_is_cocos2d_ActionFloat_ActionFloatCallback(lua_State *L, int idx);
int olua_push_cocos2d_ActionFloat_ActionFloatCallback(lua_State *L, const cocos2d::ActionFloat::ActionFloatCallback *value);
void olua_check_cocos2d_ActionFloat_ActionFloatCallback(lua_State *L, int idx, cocos2d::ActionFloat::ActionFloatCallback *value);

#endif