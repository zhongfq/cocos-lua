cmake_minimum_required(VERSION 3.16)

set(LIBNAME plugin_talkingdata)

set(SRC
  lua_talkingdata.cpp
  lua_talkingdata.h
  talkingdata.cpp
  talkingdata.h
)

if(IOS)
  list(APPEND SRC
    ios/TalkingDataSDK.h
    talkingdata.mm
  )
endif()

add_library(${LIBNAME} ${SRC})
target_include_directories(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(${LIBNAME} PRIVATE cclua)

if(IOS)
  target_link_libraries(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/libTalkingDataSDK.a)
endif()

if(APPLE)
    set_xcode_property(${LIBNAME} CLANG_ENABLE_OBJC_ARC "YES")
endif()

if(ANDROID OR IOS)
    target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_TALKINGDATA)
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})
