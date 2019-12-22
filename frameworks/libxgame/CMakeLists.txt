cmake_minimum_required(VERSION 3.6)

include(CocosBuildSet)

include(src/bugly/CMakeLists.txt)
include(src/cjson/CMakeLists.txt)
include(src/crypto/CMakeLists.txt)
include(src/lame/CMakeLists.txt)
include(src/lpeg/CMakeLists.txt)
include(src/lua-bindings/CMakeLists.txt)
include(src/lua/CMakeLists.txt)
include(src/luasocket/CMakeLists.txt)
include(src/olua/CMakeLists.txt)
include(src/pbc/CMakeLists.txt)
include(src/qrencode/CMakeLists.txt)
include(src/sproto/CMakeLists.txt)
include(src/xgame/CMakeLists.txt)

set(SRC
    ${BUGLY_SRC}
    ${CJSON_SRC}
    ${CRYPTO_SRC}
    ${LAME_SRC}
    ${LPEG_SRC}
    ${LUA_BINDINGS_SRC}
    ${LUA_SRC}
    ${LUASOCKET_SRC}
    ${OLUA_SRC}
    ${PBC_SRC}
    ${QRCODE_SRC}
    ${SPROTO_SRC}
    ${XGAME_SRC}
)

set(HEADER
    ${BUGLY_HEADER}
    ${CJSON_HEADER}
    ${CRYPTO_HEADER}
    ${LAME_HEADER}
    ${LPEG_HEADER}
    ${LUA_BINDINGS_HEADER}
    ${LUA_HEADER}
    ${LUASOCKET_HEADER}
    ${OLUA_HEADER}
    ${PBC_HEADER}
    ${QRCODE_HEADER}
    ${SPROTO_HEADER}
    ${XGAME_HEADER}
)

list(APPEND SRC ${HEADER})

add_library(xgame ${SRC})

target_compile_definitions(xgame PUBLIC STDC_HEADERS)
target_compile_definitions(xgame PRIVATE $<$<CONFIG:Debug>:OLUA_DEBUG>)

target_link_libraries(xgame fairygui cocos2d)

if (APPLE)
    set_xcode_property(xgame CLANG_ENABLE_OBJC_ARC "YES")
endif()

if (IOS)
    set_xcode_property(xgame TARGETED_DEVICE_FAMILY "1,2")
    set_xcode_property(xgame IPHONEOS_DEPLOYMENT_TARGET "9.0")

    add_subdirectory(src/bugly/ios)
    target_link_libraries(xgame bugly)

    find_library(PHOTOS_LIBRARY Photos)
    target_link_libraries(xgame ${PHOTOS_LIBRARY})
endif()

add_dependencies(xgame cocos2d)

target_include_directories(xgame
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/lua/src
)

if(XCODE OR VS)
    cocos_mark_code_files("xgame" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}/src")
endif()