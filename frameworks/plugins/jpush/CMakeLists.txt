cmake_minimum_required(VERSION 3.16)

set(LIBNAME plugin_jpush)

set(SRC
  jpush.cpp
  jpush.h
  lua_jpush.cpp
  lua_jpush.h
)

if(IOS)
  list(APPEND SRC
    ios/JPushNotificationExtensionService.h
    ios/JPUSHService.h
    jpush.mm
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
    # ${CMAKE_CURRENT_SOURCE_DIR}/ios/jpush-extension-ios-1.1.2.a
    ${CMAKE_CURRENT_SOURCE_DIR}/ios/jpush-ios-4.8.1.a
  )
  if(NOT TARGET jcore)
    add_subdirectory(../jcore ${CMAKE_BINARY_DIR}/frameworks/plugins/jcore)
  endif()
  target_link_libraries(${LIBNAME} jcore)
endif()

if(ANDROID OR IOS)
  target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_JPUSH)
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})
