cmake_minimum_required(VERSION 3.16)

set(SRC
  lua_md5.cpp
  lua_md5.h
  md5.c
  md5.h
  md5util.c
  md5util.h
)

add_library(md5 ${SRC})
target_link_libraries(md5 PUBLIC lua)
target_include_directories(md5 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})