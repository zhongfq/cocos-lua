cmake_minimum_required(VERSION 3.10)

project(lua-xxtea C)

set(source ${CMAKE_CURRENT_SOURCE_DIR}/../../libxgame/src/xxtea)

set(SRC
    ${source}/xxtea.c
    ${source}/xxtea.h
    ${source}/lua_xxtea.h
    ${source}/lua_xxtea.c
)

add_library(xxtea MODULE ${SRC})
set_target_properties(xxtea PROPERTIES PREFIX "")
target_include_directories(xxtea PUBLIC ${LUA_INCLUDE})

if(APPLE)
    target_link_options(xxtea PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(xxtea liblua)
endif()