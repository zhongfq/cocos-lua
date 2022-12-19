cmake_minimum_required(VERSION 3.16)

set(SRC
  lua_md5.cpp
  lua_md5.h
  md5util.c
  md5util.h
)

add_library(lmd5 ${SRC})
target_link_libraries(lmd5 PUBLIC md5 lua)
target_include_directories(lmd5 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})