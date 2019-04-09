cmake_minimum_required(VERSION 3.6)

project(xgame)

set(XGAME_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set(XGAME_SRC
    src/cjson/cJSON.c
    src/cjson/fpconv.c
    src/cjson/lua_cjson.c
    src/cjson/strbuf.c
    src/crypto/md5.c
    src/crypto/md5util.c
    src/crypto/xxtea.cpp
    src/lua/src/lapi.c
    src/lua/src/lauxlib.c
    src/lua/src/lbaselib.c
    src/lua/src/lbitlib.c
    src/lua/src/lcode.c
    src/lua/src/lcorolib.c
    src/lua/src/lctype.c
    src/lua/src/ldblib.c
    src/lua/src/ldebug.c
    src/lua/src/ldo.c
    src/lua/src/ldump.c
    src/lua/src/lfunc.c
    src/lua/src/lgc.c
    src/lua/src/linit.c
    src/lua/src/liolib.c
    src/lua/src/llex.c
    src/lua/src/lmathlib.c
    src/lua/src/lmem.c
    src/lua/src/loadlib.c
    src/lua/src/lobject.c
    src/lua/src/lopcodes.c
    src/lua/src/loslib.c
    src/lua/src/lparser.c
    src/lua/src/lstate.c
    src/lua/src/lstring.c
    src/lua/src/lstrlib.c
    src/lua/src/ltable.c
    src/lua/src/ltablib.c
    src/lua/src/ltm.c
    src/lua/src/lundump.c
    src/lua/src/lutf8lib.c
    src/lua/src/lvm.c
    src/lua/src/lzio.c
    src/olua/olua.c
    src/pbc/alloc.c
    src/pbc/array.c
    src/pbc/bootstrap.c
    src/pbc/context.c
    src/pbc/decode.c
    src/pbc/map.c
    src/pbc/packet.c
    src/pbc/pattern.c
    src/pbc/pbc-lua53.c
    src/pbc/proto.c
    src/pbc/register.c
    src/pbc/rmessage.c
    src/pbc/stringpool.c
    src/pbc/varint.c
    src/pbc/wmessage.c
    src/xgame/lua-bindings/lua_cocos2d.cpp
    src/xgame/lua-bindings/lua_cocos2d_ui.cpp
    src/xgame/lua-bindings/lua_conv.cpp
    src/xgame/lua-bindings/lua_conv_manual.cpp
    src/xgame/lua-bindings/lua_fairygui.cpp
    src/xgame/lua-bindings/lua_spine.cpp
    src/xgame/lua-bindings/lua_xgame.cpp
    src/xgame/lua-bindings/LuaComponent.cpp
    src/xgame/lua_crypto.cpp
    src/xgame/lua_javabridge.cpp
    src/xgame/lua_module.cpp
    src/xgame/lua_socket.cpp
    src/xgame/xdownloader.cpp
    src/xgame/xfilefinder.cpp
    src/xgame/xfilesystem-private-android.cpp
    src/xgame/xfilesystem.cpp
    src/xgame/xlua.cpp
    src/xgame/xpreferences.cpp
    src/xgame/xrootscene.cpp
    src/xgame/xruntime-private-android.cpp
    src/xgame/xruntime.cpp
    src/xgame/xsocket.cpp
    src/xgame/xtimer.cpp
    )

set(XGAME_HEADER
    src/cjson/cJSON.h
    src/cjson/fpconv.h
    src/cjson/lua_cjson.h
    src/cjson/strbuf.h
    src/crypto/md5.h
    src/crypto/md5util.h
    src/crypto/xxtea.h
    src/lua/src/lapi.h
    src/lua/src/lauxlib.h
    src/lua/src/lcode.h
    src/lua/src/lctype.h
    src/lua/src/ldebug.h
    src/lua/src/ldo.h
    src/lua/src/lfunc.h
    src/lua/src/lgc.h
    src/lua/src/llex.h
    src/lua/src/llimits.h
    src/lua/src/lmem.h
    src/lua/src/lobject.h
    src/lua/src/lopcodes.h
    src/lua/src/lparser.h
    src/lua/src/lprefix.h
    src/lua/src/lstate.h
    src/lua/src/lstring.h
    src/lua/src/ltable.h
    src/lua/src/ltm.h
    src/lua/src/lua.h
    src/lua/src/luaconf.h
    src/lua/src/lualib.h
    src/lua/src/lundump.h
    src/lua/src/lvm.h
    src/lua/src/lzio.h
    src/olua/olua.h
    src/pbc/alloc.h
    src/pbc/array.h
    src/pbc/bootstrap.h
    src/pbc/context.h
    src/pbc/descriptor.pbc.h
    src/pbc/map.h
    src/pbc/packet.h
    src/pbc/pattern.h
    src/pbc/pbc.h
    src/pbc/proto.h
    src/pbc/stringpool.h
    src/pbc/varint.h
    src/xgame/AppContext-ios.h
    src/xgame/AppRootViewController-ios.h
    src/xgame/lua-bindings/lua_cocos2d.h
    src/xgame/lua-bindings/lua_cocos2d_ui.h
    src/xgame/lua-bindings/lua_conv.h
    src/xgame/lua-bindings/lua_conv_manual.h
    src/xgame/lua-bindings/lua_fairygui.h
    src/xgame/lua-bindings/lua_spine.h
    src/xgame/lua-bindings/lua_xgame.h
    src/xgame/lua-bindings/LuaComponent.h
    src/xgame/lua_crypto.h
    src/xgame/lua_javabridge.h
    src/xgame/lua_module.h
    src/xgame/lua_socket.h
    src/xgame/xdef.h
    src/xgame/xdownloader.h
    src/xgame/xfilefinder.h
    src/xgame/xfilesystem-private.h
    src/xgame/xfilesystem.h
    src/xgame/xlua.h
    src/xgame/xpreferences.h
    src/xgame/xrootscene.h
    src/xgame/xruntime-private.h
    src/xgame/xruntime.h
    src/xgame/xsocket.h
    src/xgame/xtimer.h
	)

list(APPEND XGAME_SRC ${XGAME_HEADER})

add_library(xgame ${XGAME_SRC})

target_compile_definitions(xgame PUBLIC OLUA_REPORT_PUSH_STATUS=xlua_report_push_status)
target_compile_definitions(xgame PUBLIC OLUA_MAINTHREAD=xlua_cocosthread)
target_compile_definitions(xgame PUBLIC OLUA_STARTCMPUNREF=xlua_startcmpunref)
target_compile_definitions(xgame PUBLIC OLUA_ENDCMPUNREF=xlua_endcmpunref)
# TODO: RM
target_compile_definitions(xgame PUBLIC OLUA_DEBUG)

target_link_libraries(xgame 
	PRIVATE fairygui
	PRIVATE cocos2d
	)

add_dependencies(fairygui cocos2d)

target_include_directories(xgame
	PUBLIC ${XGAME_ROOT}/src
	PUBLIC ${XGAME_ROOT}/src/lua/src
	)
