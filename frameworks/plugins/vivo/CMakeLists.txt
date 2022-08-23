cmake_minimum_required(VERSION 3.6)

set(LIBNAME plugin_vivo)

set(SOURCE
    lua_vivo.cpp
    vivo.cpp
)

set(HEADER
    lua_vivo.h
    vivo.h
)

list(APPEND SOURCE ${HEADER})

add_library(${LIBNAME} ${SOURCE})

target_include_directories(${LIBNAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(${LIBNAME} PRIVATE xgame)

if(ANDROID)
    target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_VIVO)
endif()

set_target_properties(${LIBNAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "cclua/plugins"
)

if(XCODE OR VS)
    cocos_mark_code_files(${LIBNAME} GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()