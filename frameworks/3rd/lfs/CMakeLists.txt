cmake_minimum_required(VERSION 3.16)

set(SRC
    lfs.c
)
set(HEADER
    lfs.h
)

list(APPEND SRC ${HEADER})

add_library(lfs ${SRC})

target_link_libraries(lfs PUBLIC lua)

target_include_directories(lfs
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${SRC})