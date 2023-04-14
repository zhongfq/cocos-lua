cmake_minimum_required(VERSION 3.16)

set(SRC
  lpcap.c
  lpcap.h
  lpcode.c
  lpcode.h
  lpprint.c
  lpprint.h
  lptree.c
  lptree.h
  lptypes.h
  lpvm.c
  lpvm.h
)

add_library(lpeg ${SRC})
target_link_libraries(lpeg PUBLIC lua)
target_include_directories(lpeg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})
