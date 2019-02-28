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
cls.func(nil, 'bool getBoolForKey(const char *key);', 'bool getBoolForKey(const char *key, bool defaultValue);')
cls.func(nil, 'int getIntegerForKey(const char *key);', 'int getIntegerForKey(const char *key, int defaultValue);')
cls.func(nil, 'float getFloatForKey(const char *key);', 'float getFloatForKey(const char *key, float defaultValue);')
cls.func(nil, 'double getDoubleForKey(const char *key);', 'double getDoubleForKey(const char *key, double defaultValue);')
cls.func(nil, 'std::string getStringForKey(const char *key);', 'std::string getStringForKey(const char *key, const std::string & defaultValue);')
cls.func(nil, 'void setBoolForKey(const char *key, bool value);')
cls.func(nil, 'void setIntegerForKey(const char *key, int value);')
cls.func(nil, 'void setFloatForKey(const char *key, float value);')
cls.func(nil, 'void setDoubleForKey(const char *key, double value);')
cls.func(nil, 'void setStringForKey(const char *key, const std::string & value);')
cls.func(nil, 'void flush();')
cls.func(nil, 'void deleteValueForKey(const char *key);')
cls.func(nil, 'static cocos2d::UserDefault *getInstance();')
cls.func(nil, 'static const std::string& getXMLFilePath();')
cls.func(nil, 'static bool isXMLFileExist();')

return M