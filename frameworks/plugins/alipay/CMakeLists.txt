cmake_minimum_required(VERSION 3.16)

set(LIBNAME plugin_alipay)

set(SRC
  alipay.cpp
  alipay.h
  lua_alipay.cpp
  lua_alipay.h
)

add_library(${LIBNAME} ${SRC})
target_include_directories(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(${LIBNAME} PRIVATE cclua)

if(ANDROID)
  target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_ALIPAY)
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})
