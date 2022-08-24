//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_FAIRYGUI_H__
#define __AUTO_GEN_LUA_FAIRYGUI_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "FairyGUI.h"
#include "GLoader3D.h"
#include "tween/EaseManager.h"
#include "tween/GPath.h"
#include "display/FUISprite.h"
#include "utils/html/HtmlElement.h"
#include "utils/html/HtmlObject.h"
#include "utils/html/HtmlParser.h"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_fairygui(lua_State *L);
OLUA_END_DECLS

// fairygui::Margin
int olua_push_fairygui_Margin(lua_State *L, const fairygui::Margin *value);
void olua_check_fairygui_Margin(lua_State *L, int idx, fairygui::Margin *value);
bool olua_is_fairygui_Margin(lua_State *L, int idx);
void olua_pack_fairygui_Margin(lua_State *L, int idx, fairygui::Margin *value);
int olua_unpack_fairygui_Margin(lua_State *L, const fairygui::Margin *value);
bool olua_canpack_fairygui_Margin(lua_State *L, int idx);

// fairygui::HtmlParseOptions
int olua_push_fairygui_HtmlParseOptions(lua_State *L, const fairygui::HtmlParseOptions *value);
void olua_check_fairygui_HtmlParseOptions(lua_State *L, int idx, fairygui::HtmlParseOptions *value);
bool olua_is_fairygui_HtmlParseOptions(lua_State *L, int idx);
void olua_pack_fairygui_HtmlParseOptions(lua_State *L, int idx, fairygui::HtmlParseOptions *value);
int olua_unpack_fairygui_HtmlParseOptions(lua_State *L, const fairygui::HtmlParseOptions *value);
bool olua_canpack_fairygui_HtmlParseOptions(lua_State *L, int idx);

// fairygui::TweenValue
int olua_push_fairygui_TweenValue(lua_State *L, const fairygui::TweenValue *value);
void olua_check_fairygui_TweenValue(lua_State *L, int idx, fairygui::TweenValue *value);
bool olua_is_fairygui_TweenValue(lua_State *L, int idx);
void olua_pack_fairygui_TweenValue(lua_State *L, int idx, fairygui::TweenValue *value);
int olua_unpack_fairygui_TweenValue(lua_State *L, const fairygui::TweenValue *value);
bool olua_canpack_fairygui_TweenValue(lua_State *L, int idx);

#endif