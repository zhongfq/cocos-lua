cmake_minimum_required(VERSION 3.16)

set(SPROTO_HEADER
    lsproto.h
    msvcint.h
    sproto.h
)
set(SPROTO_SRC
    lsproto.c
    sproto.c
)

list(APPEND SPROTO_SRC ${SPROTO_HEADER})

add_library(sproto ${SPROTO_SRC})

target_link_libraries(sproto PUBLIC lua)

target_include_directories(sproto
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${SPROTO_SRC})
