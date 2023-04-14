cmake_minimum_required(VERSION 3.10)

project(lua-md5 C)

set(source ${CMAKE_CURRENT_SOURCE_DIR}/../../3rd/md5)

set(SRC
    ${source}/lua_md5.cpp
    ${source}/lua_md5.h
    ${source}/md5.c
    ${source}/md5.h
    ${source}/md5util.c
    ${source}/md5util.h
)

add_library(md5 MODULE ${SRC})
set_target_properties(md5 PROPERTIES PREFIX "")
target_include_directories(md5 PUBLIC ${LUA_INCLUDE})

if(APPLE)
    target_link_options(md5 PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(md5 liblua)
endif()