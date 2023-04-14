cmake_minimum_required(VERSION 3.16)

set(LIBNAME plugin_apple)

set(SRC
  lua_apple.h
  lua_apple.cpp
)

if(APPLE)
  list(APPEND SRC apple.h apple.mm)
endif()

add_library(${LIBNAME} ${SRC})
target_include_directories(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(${LIBNAME} cclua)

if(IOS)
  find_library(AUTHENTICATION_SERVICES AuthenticationServices)
  target_link_libraries(${LIBNAME} ${AUTHENTICATION_SERVICES})
  find_library(STOREKIT_LIBRARY StoreKit)
  target_link_libraries(${LIBNAME} ${STOREKIT_LIBRARY})
endif()

if(APPLE)
  set_xcode_property(${LIBNAME} CLANG_ENABLE_OBJC_ARC "YES")
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})