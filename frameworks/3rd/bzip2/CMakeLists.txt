cmake_minimum_required(VERSION 3.16)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/bzlib.h
  ${CMAKE_CURRENT_BINARY_DIR}/include/bzlib.h
  COPYONLY
)

set(PUBLIC_HEADER
  ${CMAKE_CURRENT_BINARY_DIR}/include/bzlib.h
)

set(LIB_SRCS
  blocksort.c
  bzlib.c
  compress.c
  crctable.c
  decompress.c
  huffman.c
  randtable.c
)

add_library(bz2 ${LIB_SRCS} ${PUBLIC_HEADER})
target_compile_definitions(bz2 PRIVATE _FILE_OFFSET_BITS=64)
target_include_directories(bz2 PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include)

if(APPLE)
  target_compile_options(bz2
    PRIVATE
      -Wno-shorten-64-to-32
  )
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${LIB_SRCS})
source_group(TREE ${CMAKE_CURRENT_BINARY_DIR}/include FILES ${PUBLIC_HEADER})