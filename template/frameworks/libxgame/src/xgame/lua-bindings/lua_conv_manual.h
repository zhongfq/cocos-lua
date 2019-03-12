#ifndef __LUA_CONV_MANUAL_H__
#define __LUA_CONV_MANUAL_H__

#include "xgame/xlua.h"
#include "lua.hpp"

#include "cocos2d.h"

int manual_luacv_push_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value);
void manual_luacv_check_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value);
void manual_luacv_opt_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value, const cocos2d::Rect &def);
void manual_luacv_pack_cocos2d_Rect(lua_State *L, int idx, cocos2d::Rect *value);
int manual_luacv_unpack_cocos2d_Rect(lua_State *L, const cocos2d::Rect *value);
bool manual_luacv_is_cocos2d_Rect(lua_State *L, int idx);
void manual_luacv_pack_cocos2d_ccBezierConfig(lua_State *L, int idx, cocos2d::ccBezierConfig *value);
void manual_luacv_check_cocos2d_Value(lua_State *L, int idx, cocos2d::Value *value);
int manual_luacv_push_cocos2d_Value(lua_State *L, const cocos2d::Value *value);
int manual_luacv_is_cocos2d_ValueVector(lua_State *L, int idx);
int manual_luacv_push_cocos2d_ValueVector(lua_State *L, const cocos2d::ValueVector *value);
void manual_luacv_check_cocos2d_ValueVector(lua_State *L, int idx, cocos2d::ValueVector *value);
int manual_luacv_push_cocos2d_ValueMapIntKey(lua_State *L, const cocos2d::ValueMapIntKey *value);
void manual_luacv_check_cocos2d_ValueMapIntKey(lua_State *L, int idx, cocos2d::ValueMapIntKey *value);
int manual_luacv_is_cocos2d_ValueMapIntKey(lua_State *L, int idx);
int manual_luacv_push_cocos2d_ValueMap(lua_State *L, const cocos2d::ValueMap *value);
void manual_luacv_check_cocos2d_ValueMap(lua_State *L, int idx, cocos2d::ValueMap *value);

#endif
