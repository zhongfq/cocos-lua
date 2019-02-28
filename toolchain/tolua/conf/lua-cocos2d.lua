require "aux.tolua-cls"

local M = {}

M.NAME = "cocos2d"
M.HEADER_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_cocos2d.h"
M.SOURCE_PATH = "template/frameworks/libxgame/src/xgame/lua-bindings/lua_cocos2d.cpp"

M.INCLUDES = [[
#include "xgame/lua-bindings/lua_cocos2d.h"
#include "xgame/xlua.h"
#include "xgame/xlua-conv.h"
#include "cocos2d.h"
]]

M.CLASSES = {}

local cls = class(M)
cls.NATIVE = "cocos2d::UserDefault"
cls.CLASS = "cc.UserDefault"
cls.func(nil, "static cocos2d::UserDefault *getInstance()")
cls.func(nil, "bool getBoolForKey(const char *key)")
cls.func(nil, "std::string getStringForKey(const char* key)")

return M