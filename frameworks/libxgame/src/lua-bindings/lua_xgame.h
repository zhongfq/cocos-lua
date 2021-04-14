//
// AUTO BUILD, DON'T MODIFY!
//
#ifndef __AUTO_GEN_LUA_XGAME_H__
#define __AUTO_GEN_LUA_XGAME_H__

#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/filesystem.h"
#include "cclua/xlua.h"
#include "cclua/preferences.h"
#include "cclua/downloader.h"
#include "cclua/runtime.h"
#include "cclua/RootScene.h"
#include "cclua/timer.h"
#include "cclua/window.h"
#include "olua/olua.hpp"

int luaopen_xgame(lua_State *L);

// cclua::downloader::FileTask
int olua_push_cclua_downloader_FileTask(lua_State *L, const cclua::downloader::FileTask *value);
void olua_check_cclua_downloader_FileTask(lua_State *L, int idx, cclua::downloader::FileTask *value);
bool olua_is_cclua_downloader_FileTask(lua_State *L, int idx);
void olua_pack_cclua_downloader_FileTask(lua_State *L, int idx, cclua::downloader::FileTask *value);
int olua_unpack_cclua_downloader_FileTask(lua_State *L, const cclua::downloader::FileTask *value);
bool olua_ispack_cclua_downloader_FileTask(lua_State *L, int idx);

#endif