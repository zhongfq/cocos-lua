cmake_minimum_required(VERSION 3.16)

set(SRC
  lfs.h
  lfs.c
)

add_library(lfs ${SRC})
target_link_libraries(lfs PUBLIC lua)
target_include_directories(lfs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})