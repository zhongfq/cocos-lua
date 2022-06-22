cmake_minimum_required(VERSION 3.6)

add_library(xgame "")

include(src/box2d/CMakeLists.txt)
include(src/cjson/CMakeLists.txt)
include(src/lua-bindings/CMakeLists.txt)
include(src/lua/CMakeLists.txt)
include(src/md5/CMakeLists.txt)
include(src/olua/CMakeLists.txt)
include(src/lfs/CMakeLists.txt)
include(src/cclua/CMakeLists.txt)
include(src/xxtea/CMakeLists.txt)

target_sources(xgame PRIVATE
    ${CCLUA_SRC}
    ${CJSON_SRC}
    ${LUA_BINDINGS_SRC}
    ${MD5_SRC}
    ${LUA_SRC}
    ${LFS_SRC}
    ${OLUA_SRC}
    ${XXTEA_SRC}

    ${CCLUA_HEADER}
    ${CJSON_HEADER}
    ${LUA_BINDINGS_HEADER}
    ${MD5_HEADER}
    ${LUA_HEADER}
    ${LFS_HEADER}
    ${OLUA_HEADER}
    ${XXTEA_HEADER}
)

if(CCLUA_BUILD_BUGLY)
    if(ANDROID OR IOS)
        include(src/bugly/CMakeLists.txt)
        target_sources(xgame PRIVATE ${BUGLY_HEADER} ${BUGLY_SRC})
        target_compile_definitions(xgame PUBLIC CCLUA_BUILD_BUGLY)
    else()
        set(CCLUA_BUILD_BUGLY OFF)
    endif()
    if(IOS)
        set(BUGLY_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/src/bugly/Bugly.framework")
        target_link_libraries(xgame ${BUGLY_LIBRARY})
    endif()
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

if(CCLUA_BUILD_BOX2D)
    target_link_libraries(xgame ext_box2d)
    target_sources(xgame PRIVATE ${BOX2D_SRC} ${BOX2D_HEADER})
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_BOX2D)
endif()

if(CCLUA_BUILD_COCOSSTUDIO)
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_COCOSSTUDIO)
endif()

if(CCLUA_BUILD_DRAGONBONES)
    target_link_libraries(xgame dragonbones)
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_DRAGONBONES)
endif()

target_link_libraries(xgame cocos2d)

target_compile_definitions(xgame PUBLIC STDC_HEADERS)
target_compile_definitions(xgame PUBLIC $<$<CONFIG:Debug>:OLUA_DEBUG>)
target_compile_definitions(xgame PUBLIC OLUA_USER_H="cclua/luauser.h")
target_compile_definitions(xgame PUBLIC CCLUA_VERSION="${CCLUA_VERSION}")

if(CCLUA_BUILD_SPINE)
    target_compile_definitions(xgame PUBLIC CCLUA_BUILD_SPINE)
endif()

# feature
if(CCLUA_FEATURE_MSAA)
    target_compile_definitions(xgame PUBLIC CCLUA_FEATURE_MSAA)
endif()

if(CCLUA_FEATURE_IDFA)
    find_library(APP_TRACKING_TRANSPARENCY_LIBRARY AppTrackingTransparency)
    target_link_libraries(xgame ${APP_TRACKING_TRANSPARENCY_LIBRARY})
    find_library(AD_SUPPORT_LIBRARY AdSupport)
    target_link_libraries(xgame ${AD_SUPPORT_LIBRARY})
    target_compile_definitions(xgame PUBLIC CCLUA_FEATURE_IDFA)
endif()

if(CCLUA_FEATURE_INTCOLOR)
    target_compile_definitions(xgame PUBLIC CCLUA_FEATURE_INTCOLOR)
endif()

if(APPLE)
    set_xcode_property(xgame CLANG_ENABLE_OBJC_ARC "YES")
    target_compile_options(xgame PUBLIC -Wno-nullability-completeness)
endif()

if (IOS)
    find_library(SC_LIBRARY SystemConfiguration)
    target_link_libraries(xgame ${SC_LIBRARY})
    
    find_library(METALKIT_LIBRARY MetalKit)
    target_link_libraries(xgame ${METALKIT_LIBRARY})

    find_library(PHOTOS_LIBRARY Photos)
    target_link_libraries(xgame ${PHOTOS_LIBRARY})
endif()

target_include_directories(xgame
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/lua
)

set_target_properties(xgame PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "cclua"
)

if(XCODE OR VS)
    cocos_mark_code_files("xgame" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}/src")
endif()
