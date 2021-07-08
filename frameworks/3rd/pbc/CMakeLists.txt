cmake_minimum_required(VERSION 3.6)

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

target_link_libraries(pbc 
	PRIVATE xgame
	PRIVATE cocos2d
)

if(APPLE)
    target_compile_options(pbc PRIVATE -Wno-strict-prototypes)
endif()

target_include_directories(pbc
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

set_target_properties(pbc PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Internal"
)

if(XCODE OR VS)
    cocos_mark_code_files("pbc" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()