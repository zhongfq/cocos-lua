#ifndef __LUA_JAVABRIDGE_H__
#define __LUA_JAVABRIDGE_H__

#include "platform/CCPlatformMacros.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "xgame/xlua.h"
#include "platform/android/jni/JniHelper.h"

int luaopen_javabridge(lua_State *L);
int luaj_invoke(lua_State *L);
#endif

#endif
