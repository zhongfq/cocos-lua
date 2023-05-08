cmake_minimum_required(VERSION 3.10)

project(lua-md5 C)

set(source ${CMAKE_CURRENT_SOURCE_DIR}/../../3rd)

set(SRC
    ${source}/lmd5/lua_md5.cpp
    ${source}/lmd5/lua_md5.h
    ${source}/lmd5/md5util.c
    ${source}/lmd5/md5util.h
    ${source}/md5/md5.c
    ${source}/md5/md5.h
)

add_library(md5 MODULE ${SRC})
set_target_properties(md5 PROPERTIES PREFIX "")
target_include_directories(md5 PUBLIC ${LUA_INCLUDE})
target_include_directories(md5 PUBLIC ${source})

if(APPLE)
    target_link_options(md5 PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(md5 liblua)
endif()