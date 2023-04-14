cmake_minimum_required(VERSION 3.16)

set(PBC_HEADER
    alloc.h
    array.h
    bootstrap.h
    context.h
    descriptor.pbc.h
    map.h
    packet.h
    pattern.h
    pbc.h
    proto.h
    stringpool.h
    varint.h
)

set(PBC_SRC
    alloc.c
    array.c
    bootstrap.c
    context.c
    decode.c
    map.c
    packet.c
    pattern.c
    pbc-lua53.c
    proto.c
    register.c
    rmessage.c
    stringpool.c
    varint.c
    wmessage.c
)

list(APPEND PBC_SRC ${PBC_HEADER})

add_library(pbc ${PBC_SRC})

target_link_libraries(pbc PUBLIC lua)

if(APPLE)
    target_compile_options(pbc PRIVATE -Wno-strict-prototypes)
endif()

target_include_directories(pbc
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${PBC_SRC})
