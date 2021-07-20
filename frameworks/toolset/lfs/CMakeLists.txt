cmake_minimum_required(VERSION 3.10)

project(lua-lfs C)

set(source ${CMAKE_CURRENT_SOURCE_DIR}/../../libxgame/src/lfs)

set(SRC
    ${source}/lfs.c
    ${source}/lfs.h
)

add_library(lfs MODULE ${SRC})
set_target_properties(lfs PROPERTIES PREFIX "")
target_include_directories(lfs PUBLIC ${LUA_INCLUDE})

if(APPLE)
    target_link_options(lfs PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(lfs liblua)
endif()