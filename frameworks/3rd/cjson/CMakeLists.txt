cmake_minimum_required(VERSION 3.16)

set(SRC
  cJSON.c
  cJSON.h
  fpconv.c
  fpconv.h
  lua_cjson.c
  lua_cjson.h
  strbuf.c
  strbuf.h
)

add_library(cjson ${SRC})
target_link_libraries(cjson PUBLIC lua)
target_include_directories(cjson PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})
