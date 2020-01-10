cmake_minimum_required(VERSION 3.6)


include(src/crypto/CMakeLists.txt)
include(src/lua-bindings/CMakeLists.txt)
include(src/lua/CMakeLists.txt)
include(src/xgame/CMakeLists.txt)

set(SRC
    ${CRYPTO_SRC}
    ${LUA_BINDINGS_SRC}
    ${LUA_SRC}
    ${XGAME_SRC}
    src/olua/olua.c
)

set(HEADER
    ${CRYPTO_HEADER}
    ${LUA_BINDINGS_HEADER}
    ${LUA_HEADER}
    ${XGAME_HEADER}
    src/olua/olua.h
    src/olua/olua.hpp
)

if(BUILD_BUGLY)
    include(src/bugly/CMakeLists.txt)
    list(APPEND HEADER ${BUGLY_HEADER})
    list(APPEND SRC ${BUGLY_SRC})
    add_definitions(-DUSE_BUGLY)
endif()

if(BUILD_LUA_SOCKET)
    include(src/luasocket/CMakeLists.txt)
    list(APPEND HEADER ${LUASOCKET_HEADER})
    list(APPEND SRC ${LUASOCKET_SRC})
    add_definitions(-DUSE_LUA_SOCKET)
endif()

if(BUILD_CJSON)
    include(src/cjson/CMakeLists.txt)
    list(APPEND HEADER ${CJSON_HEADER})
    list(APPEND SRC ${CJSON_SRC})
    add_definitions(-DUSE_CJSON)
endif()

if(BUILD_PBC)
    include(src/pbc/CMakeLists.txt)
    list(APPEND HEADER ${PBC_HEADER})
    list(APPEND SRC ${PBC_SRC})
    add_definitions(-DUSE_PBC)
endif()

if(BUILD_SPROTO)
    include(src/sproto/CMakeLists.txt)
    list(APPEND HEADER ${SPROTO_HEADER})
    list(APPEND SRC ${SPROTO_SRC})
    set(BUILD_LPEG ON)
    add_definitions(-DUSE_SPROTO)
endif()

if(BUILD_LPEG)
    include(src/lpeg/CMakeLists.txt)
    list(APPEND HEADER ${LPEG_HEADER})
    list(APPEND SRC ${LPEG_SRC})
    add_definitions(-DUSE_LPEG)
endif()

if(BUILD_LAME)
    include(src/lame/CMakeLists.txt)
    add_definitions(-DUSE_LAME)
endif()

if(BUILD_QRCODE)
    include(src/qrencode/CMakeLists.txt)
    list(APPEND HEADER ${QRCODE_HEADER})
    list(APPEND SRC ${QRCODE_SRC})
    add_definitions(-DUSE_QRCODE)
endif()

if (IOS OR ANDROID)
    list(APPEND SRC ${LAME_SRC})
    list(APPEND HEADER ${LAME_HEADER})
endif()

list(APPEND SRC ${HEADER})

add_library(xgame ${SRC})

target_compile_definitions(xgame PUBLIC STDC_HEADERS)
target_compile_definitions(xgame PRIVATE $<$<CONFIG:Debug>:OLUA_DEBUG>)
target_compile_definitions(xgame PRIVATE CC_ASSERT_SCRIPT_COMPATIBLE_IMPL)

target_link_libraries(xgame fairygui dragonbones cocos2d)

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

    find_library(ADSUPPORT_LIBRARY AdSupport)
    target_link_libraries(xgame ${ADSUPPORT_LIBRARY})

    find_library(STOREKIT_LIBRARY StoreKit)
    target_link_libraries(xgame ${STOREKIT_LIBRARY})
endif()

add_dependencies(xgame cocos2d)

target_include_directories(xgame
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/lua/src
)

if(XCODE OR VS)
    cocos_mark_code_files("xgame" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}/src")
endif()