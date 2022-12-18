cmake_minimum_required(VERSION 3.6)

set(HEADER
    ioapi.h
    unzip.h
    ioapi_mem.h
    crypt.h
)

set(SRC
    ioapi.cpp
    unzip.cpp
    ioapi_mem.cpp
)

add_library(unzip ${HEADER} ${SRC})

target_include_directories(unzip PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(unzip zlib)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADER} ${SRC})
