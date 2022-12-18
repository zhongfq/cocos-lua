cmake_minimum_required(VERSION 3.16)

set(LIBNAME plugin_wechat)

set(SOURCE
    lua_wechat.cpp
    wechat.cpp
)

set(HEADER
    lua_wechat.h
    wechat.h
)

if(IOS)
    list(APPEND HEADER
        ios/WechatAuthSDK.h
        ios/WXApi.h
        ios/WXApiObject.h
    )
    list(APPEND SOURCE
        wechat.mm
    )
endif()

list(APPEND SOURCE ${HEADER})

add_library(${LIBNAME} ${SOURCE})

target_include_directories(${LIBNAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(${LIBNAME} PRIVATE cclua cocos2d)

if(IOS)
    target_link_libraries(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/libWeChatSDK.a)
endif()

if(APPLE)
    set_xcode_property(${LIBNAME} CLANG_ENABLE_OBJC_ARC "YES")
endif()

if(ANDROID OR IOS)
    target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_WECHAT)
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${SOURCE})
