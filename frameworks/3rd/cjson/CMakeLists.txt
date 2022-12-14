cmake_minimum_required(VERSION 3.16)

set(HEADER
    cJSON.h
    fpconv.h
    lua_cjson.h
    strbuf.h
)

set(SRC
    cJSON.c
    fpconv.c
    lua_cjson.c
    strbuf.c
)

list(APPEND SRC ${HEADER})

add_library(cjson ${SRC})

target_link_libraries(cjson PUBLIC lua)

target_include_directories(cjson
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${SRC})