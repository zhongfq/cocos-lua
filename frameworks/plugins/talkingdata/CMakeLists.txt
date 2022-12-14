cmake_minimum_required(VERSION 3.16)

set(LIBNAME plugin_talkingdata)

set(SOURCE
    lua_talkingdata.cpp
    talkingdata.cpp
)

set(HEADER
    lua_talkingdata.h
    talkingdata.h
)

if(IOS)
    list(APPEND HEADER
        ios/TalkingDataSDK.h
    )
    list(APPEND SOURCE
        talkingdata.mm
    )
endif()

list(APPEND SOURCE ${HEADER})

add_library(${LIBNAME} ${SOURCE})

target_include_directories(${LIBNAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(${LIBNAME} PRIVATE xgame)

if(IOS)
    target_link_libraries(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/libTalkingDataSDK.a)
endif()

if(APPLE)
    set_xcode_property(${LIBNAME} CLANG_ENABLE_OBJC_ARC "YES")
endif()

if(ANDROID OR IOS)
    target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_TALKINGDATA)
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${SOURCE})
