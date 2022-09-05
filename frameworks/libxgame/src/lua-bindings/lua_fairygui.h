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
OLUA_LIB int olua_push_fairygui_Margin(lua_State *L, const fairygui::Margin *value);
OLUA_LIB void olua_check_fairygui_Margin(lua_State *L, int idx, fairygui::Margin *value);
OLUA_LIB bool olua_is_fairygui_Margin(lua_State *L, int idx);
OLUA_LIB void olua_pack_fairygui_Margin(lua_State *L, int idx, fairygui::Margin *value);
OLUA_LIB int olua_unpack_fairygui_Margin(lua_State *L, const fairygui::Margin *value);
OLUA_LIB bool olua_canpack_fairygui_Margin(lua_State *L, int idx);

// fairygui::HtmlParseOptions
OLUA_LIB int olua_push_fairygui_HtmlParseOptions(lua_State *L, const fairygui::HtmlParseOptions *value);
OLUA_LIB void olua_check_fairygui_HtmlParseOptions(lua_State *L, int idx, fairygui::HtmlParseOptions *value);
OLUA_LIB bool olua_is_fairygui_HtmlParseOptions(lua_State *L, int idx);
OLUA_LIB void olua_pack_fairygui_HtmlParseOptions(lua_State *L, int idx, fairygui::HtmlParseOptions *value);
OLUA_LIB int olua_unpack_fairygui_HtmlParseOptions(lua_State *L, const fairygui::HtmlParseOptions *value);
OLUA_LIB bool olua_canpack_fairygui_HtmlParseOptions(lua_State *L, int idx);

// fairygui::TweenValue
OLUA_LIB int olua_push_fairygui_TweenValue(lua_State *L, const fairygui::TweenValue *value);
OLUA_LIB void olua_check_fairygui_TweenValue(lua_State *L, int idx, fairygui::TweenValue *value);
OLUA_LIB bool olua_is_fairygui_TweenValue(lua_State *L, int idx);
OLUA_LIB void olua_pack_fairygui_TweenValue(lua_State *L, int idx, fairygui::TweenValue *value);
OLUA_LIB int olua_unpack_fairygui_TweenValue(lua_State *L, const fairygui::TweenValue *value);
OLUA_LIB bool olua_canpack_fairygui_TweenValue(lua_State *L, int idx);

#endif