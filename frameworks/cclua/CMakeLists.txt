cmake_minimum_required(VERSION 3.16)

add_library(cclua "")

include(src/box2d/CMakeLists.txt)
include(src/cclua/CMakeLists.txt)
include(src/lame/CMakeLists.txt)
include(src/lua-bindings/CMakeLists.txt)
include(src/olua/CMakeLists.txt)
include(src/qrencode/CMakeLists.txt)

target_sources(cclua PRIVATE
    ${CCLUA_SRC}
    ${LUA_BINDINGS_SRC}
    ${LAME_SRC}
    ${OLUA_SRC}
    ${QRCODE_SRC}

    ${CCLUA_HEADER}
    ${LAME_HEADER}
    ${LUA_BINDINGS_HEADER}
    ${OLUA_HEADER}
    ${QRCODE_HEADER}
)

if(CCLUA_BUILD_BUGLY)
    if(ANDROID OR IOS)
        include(src/bugly/CMakeLists.txt)
        target_sources(cclua PRIVATE ${BUGLY_HEADER} ${BUGLY_SRC})
        target_compile_definitions(cclua PUBLIC CCLUA_BUILD_BUGLY)
    else()
        set(CCLUA_BUILD_BUGLY OFF)
    endif()
    if(IOS)
        set(BUGLY_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/src/bugly/Bugly.framework")
        target_link_libraries(cclua ${BUGLY_LIBRARY})
    endif()
endif()

if(CCLUA_BUILD_BOX2D)
    target_sources(cclua PRIVATE ${BOX2D_SRC} ${BOX2D_HEADER})
endif()

if(CCLUA_BUILD_COCOSSTUDIO)
    target_compile_definitions(cclua PUBLIC CCLUA_BUILD_COCOSSTUDIO)
endif()

target_link_libraries(cclua cocos2d lua cjson md5 xxtea lfs)

target_compile_definitions(cclua PUBLIC STDC_HEADERS)
target_compile_definitions(cclua PUBLIC $<$<CONFIG:Debug>:OLUA_DEBUG>)
target_compile_definitions(cclua PUBLIC OLUA_USER_H="cclua/luauser.h")
target_compile_definitions(cclua PUBLIC CCLUA_VERSION="${CCLUA_VERSION}")
target_compile_definitions(cclua PRIVATE HAVE_STDINT_H)

if(CCLUA_BUILD_SPINE)
    target_compile_definitions(cclua PUBLIC CCLUA_BUILD_SPINE)
endif()

# feature
if(CCLUA_FEATURE_MSAA)
    target_compile_definitions(cclua PUBLIC CCLUA_FEATURE_MSAA)
endif()

if(CCLUA_FEATURE_TRACKING)
    find_library(APP_TRACKING_TRANSPARENCY_LIBRARY AppTrackingTransparency)
    target_link_libraries(cclua ${APP_TRACKING_TRANSPARENCY_LIBRARY})
    find_library(AD_SUPPORT_LIBRARY AdSupport)
    target_link_libraries(cclua ${AD_SUPPORT_LIBRARY})
    target_compile_definitions(cclua PUBLIC CCLUA_FEATURE_TRACKING)
endif()

if(CCLUA_FEATURE_INTCOLOR)
    target_compile_definitions(cclua PUBLIC CCLUA_FEATURE_INTCOLOR)
endif()

if(APPLE)
    set_xcode_property(cclua CLANG_ENABLE_OBJC_ARC "YES")
    target_compile_options(cclua PUBLIC -Wno-nullability-completeness)
endif()

if (IOS)
    find_library(SC_LIBRARY SystemConfiguration)
    target_link_libraries(cclua ${SC_LIBRARY})
    
    find_library(METALKIT_LIBRARY MetalKit)
    target_link_libraries(cclua ${METALKIT_LIBRARY})

    find_library(PHOTOS_LIBRARY Photos)
    target_link_libraries(cclua ${PHOTOS_LIBRARY})
endif()

target_include_directories(cclua
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)

get_property(SRC TARGET cclua PROPERTY SOURCES)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src PREFIX "" FILES ${SRC})