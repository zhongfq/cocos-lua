cmake_minimum_required(VERSION 3.6)

add_library(xgame "")

include(src/crypto/CMakeLists.txt)
include(src/cjson/CMakeLists.txt)
include(src/lua-bindings/CMakeLists.txt)
include(src/lua/CMakeLists.txt)
include(src/olua/CMakeLists.txt)
include(src/xgame/CMakeLists.txt)

target_sources(xgame PRIVATE
    ${CRYPTO_SRC}
    ${CJSON_SRC}
    ${LUA_BINDINGS_SRC}
    ${LUA_SRC}
    ${OLUA_SRC}
    ${XGAME_SRC}

    ${CRYPTO_HEADER}
    ${CJSON_HEADER}
    ${LUA_BINDINGS_HEADER}
    ${LUA_HEADER}
    ${OLUA_HEADER}
    ${XGAME_HEADER}
)

if(CCLUA_BUILD_BUGLY)
    if(ANDROID OR IOS)
        include(src/bugly/CMakeLists.txt)
        target_sources(xgame PRIVATE ${BUGLY_HEADER} ${BUGLY_SRC})
        target_compile_definitions(xgame PUBLIC CCLUA_BUILD_BUGLY)
    else()
        set(CCLUA_BUILD_BUGLY OFF)
    endif()
endif()

if(CCLUA_BUILD_LUASOCKET)
    include(src/luasocket/CMakeLists.txt)
    target_sources(xgame PRIVATE ${LUASOCKET_HEADER} ${LUASOCKET_SRC})
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_LUASOCKET)
endif()

if(CCLUA_BUILD_PBC)
    include(src/pbc/CMakeLists.txt)
    target_sources(xgame PRIVATE ${PBC_HEADER} ${PBC_SRC})
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_PBC)
endif()

if(CCLUA_BUILD_SPROTO)
    set(CCLUA_BUILD_LPEG ON)
    include(src/sproto/CMakeLists.txt)
    target_sources(xgame PRIVATE ${SPROTO_HEADER} ${SPROTO_SRC})
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_SPROTO)
endif()

if(CCLUA_BUILD_LPEG)
    include(src/lpeg/CMakeLists.txt)
    target_sources(xgame PRIVATE ${LPEG_HEADER} ${LPEG_SRC})
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_LPEG)
endif()

if(CCLUA_BUILD_LAME AND (IOS OR ANDROID))
    include(src/lame/CMakeLists.txt)
    target_sources(xgame PRIVATE ${LAME_SRC} ${LAME_HEADER})
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_LAME)
endif()

if(CCLUA_BUILD_QRCODE)
    include(src/qrencode/CMakeLists.txt)
    target_sources(xgame PRIVATE ${QRCODE_HEADER} ${QRCODE_SRC})
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_QRCODE)
endif()

if(CCLUA_BUILD_FAIRYGUI)
    target_link_libraries(xgame fairygui)
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_FAIRYGUI)
endif()

if(CCLUA_BUILD_DRAGONBONES)
    target_link_libraries(xgame dragonbones)
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_DRAGONBONES)
endif()

target_link_libraries(xgame cocos2d)

target_compile_definitions(xgame PUBLIC STDC_HEADERS)
target_compile_definitions(xgame PUBLIC $<$<CONFIG:Debug>:OLUA_DEBUG>)

if(CCLUA_BUILD_SPINE)
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_SPINE)
endif()

# feature
if(CCLUA_FEATURE_MSAA)
    target_compile_definitions(xgame PUBLIC CCLUA_FEATURE_MSAA)
endif()

if(CCLUA_FEATURE_IDFA)
    find_library(ADSUPPORT_LIBRARY AdSupport)
    target_link_libraries(xgame ${ADSUPPORT_LIBRARY})
    target_compile_definitions(xgame PUBLIC CCLUA_FEATURE_IDFA)
endif()

if (APPLE)
    set_xcode_property(xgame CLANG_ENABLE_OBJC_ARC "YES")
endif()

if (IOS)
    set_xcode_property(xgame TARGETED_DEVICE_FAMILY "1,2")
    set_xcode_property(xgame IPHONEOS_DEPLOYMENT_TARGET "9.0")

    if (CCLUA_BUILD_BUGLY)
        add_subdirectory(src/bugly/ios)
        target_link_libraries(xgame bugly)
    endif()

    find_library(SC_LIBRARY SystemConfiguration)
    target_link_libraries(xgame ${SC_LIBRARY})
    
    find_library(METALKIT_LIBRARY MetalKit)
    target_link_libraries(xgame ${METALKIT_LIBRARY})

    find_library(PHOTOS_LIBRARY Photos)
    target_link_libraries(xgame ${PHOTOS_LIBRARY})

    find_library(STOREKIT_LIBRARY StoreKit)
    target_link_libraries(xgame ${STOREKIT_LIBRARY})
endif()

add_dependencies(xgame cocos2d)

target_include_directories(xgame
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/lua
)

set_target_properties(xgame PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Internal"
)

if(XCODE OR VS)
    cocos_mark_code_files("xgame" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}/src")
endif()
