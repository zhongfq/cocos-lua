cmake_minimum_required(VERSION 3.10)

project(lua-cjson C)

set(source ${CMAKE_CURRENT_SOURCE_DIR}/../../3rd/cjson)

set(SRC
    ${source}/fpconv.c
    ${source}/fpconv.h
    ${source}/lua_cjson.c
    ${source}/lua_cjson.h
    ${source}/strbuf.c
    ${source}/strbuf.h
)

add_library(cjson MODULE ${SRC})
set_target_properties(cjson PROPERTIES PREFIX "")
target_include_directories(cjson PUBLIC ${LUA_INCLUDE})

if(APPLE)
    target_link_options(cjson PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(cjson liblua)
endif()