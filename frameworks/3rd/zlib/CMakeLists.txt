cmake_minimum_required(VERSION 3.10)

set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

project(zlib C)

set(VERSION "1.2.12")

option(ASM686 "Enable building i686 assembly implementation")
option(AMD64 "Enable building amd64 assembly implementation")

include(CheckTypeSize)

if(MSVC)
    set(CMAKE_DEBUG_POSTFIX "d")
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})
endif()

#============================================================================
# zlib
#============================================================================

set(ZLIB_PUBLIC_HDRS)

foreach(file zlib.h zconf.h)
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/${file}
        ${CMAKE_CURRENT_BINARY_DIR}/include/${file}
        COPYONLY
    )
    list(APPEND ZLIB_PUBLIC_HDRS ${CMAKE_CURRENT_BINARY_DIR}/include/${file})
endforeach()


set(ZLIB_PRIVATE_HDRS
    crc32.h
    deflate.h
    gzguts.h
    inffast.h
    inffixed.h
    inflate.h
    inftrees.h
    trees.h
    zutil.h
)
set(ZLIB_SRCS
    adler32.c
    compress.c
    crc32.c
    deflate.c
    gzclose.c
    gzlib.c
    gzread.c
    gzwrite.c
    inflate.c
    infback.c
    inftrees.c
    inffast.c
    trees.c
    uncompr.c
    zutil.c
)

add_library(zlib ${ZLIB_SRCS} ${ZLIB_PUBLIC_HDRS} ${ZLIB_PRIVATE_HDRS})
target_include_directories(zlib
  PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

check_type_size(off64_t OFF64_T)
if(HAVE_OFF64_T)
    target_compile_definitions(zlib PUBLIC _LARGEFILE64_SOURCE=1)
endif()

if(APPLE)
    target_compile_options(zlib
      PRIVATE
        -Wno-comma
        -Wno-shorten-64-to-32
        -Wno-strict-prototypes
    )
endif()
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ZLIB_SRCS} ${ZLIB_PRIVATE_HDRS})
source_group(TREE ${CMAKE_CURRENT_BINARY_DIR}/include FILES ${ZLIB_PUBLIC_HDRS})
