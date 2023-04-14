cmake_minimum_required(VERSION 3.16)

set(LIBNAME plugin_jauth)

set(SRC
  jauth.cpp
  jauth.h
  lua_jauth.cpp
  lua_jauth.h
)

if(IOS)
  list(APPEND SRC
    ios/JVERIFICATIONService.h
    jauth.mm
  )
endif()

add_library(${LIBNAME} ${SRC})
target_include_directories(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(${LIBNAME} cclua)

if(APPLE)
  set_xcode_property(${LIBNAME} CLANG_ENABLE_OBJC_ARC "YES")
endif()

if(IOS)
  target_link_libraries(${LIBNAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/ios/account_login_sdk_noui_core.framework
    ${CMAKE_CURRENT_SOURCE_DIR}/ios/EAccountApiSDK.framework
    ${CMAKE_CURRENT_SOURCE_DIR}/ios/GTCaptcha4.framework
    ${CMAKE_CURRENT_SOURCE_DIR}/ios/QuickLogin.framework
    ${CMAKE_CURRENT_SOURCE_DIR}/ios/jverification-ios-2.9.4.a
    ${CMAKE_CURRENT_SOURCE_DIR}/ios/TYRZUISDK.framework
  )
  if(NOT TARGET jcore)
    add_subdirectory(../jcore ${CMAKE_BINARY_DIR}/frameworks/plugins/jcore)
  endif()
  target_link_libraries(${LIBNAME} jcore)
endif()

if(ANDROID OR IOS)
  target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_JAUTH)
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})
