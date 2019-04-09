cmake_minimum_required(VERSION 3.6)

project(xgame)

set(XGAME_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

include(src/cjson/CMakeLists.txt)
include(src/crypto/CMakeLists.txt)
include(src/lame/CMakeLists.txt)
include(src/lua/CMakeLists.txt)
include(src/olua/CMakeLists.txt)
include(src/pbc/CMakeLists.txt)
include(src/qrencode/CMakeLists.txt)
include(src/xgame/CMakeLists.txt)

set(SRC
    ${CJSON_SRC}
    ${CRYPTO_SRC}
    ${LAME_SRC}
    ${LUA_SRC}
    ${OLUA_SRC}
    ${PBC_SRC}
    ${QRCODE_SRC}
    ${XGAME_SRC}
)

set(HEADER
    ${CJSON_HEADER}
    ${CRYPTO_HEADER}
    ${LAME_HEADER}
    ${LUA_HEADER}
    ${OLUA_HEADER}
    ${PBC_HEADER}
    ${QRCODE_HEADER}
    ${XGAME_HEADER}
)

list(APPEND SRC ${HEADER})

add_library(xgame ${SRC})

target_compile_definitions(xgame PUBLIC STDC_HEADERS)
target_compile_definitions(xgame PUBLIC OLUA_HANDLESTATUS=xlua_handlestatus)
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
