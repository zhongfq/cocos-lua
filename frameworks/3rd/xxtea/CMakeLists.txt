cmake_minimum_required(VERSION 3.16)

set(HEADER
  lua_xxtea.h
  xxtea.h
)

set(SRC
  lua_xxtea.c
  xxtea.c
)

list(APPEND SRC ${HEADER})

add_library(xxtea ${SRC})

target_link_libraries(xxtea PUBLIC lua)

target_include_directories(xxtea
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})