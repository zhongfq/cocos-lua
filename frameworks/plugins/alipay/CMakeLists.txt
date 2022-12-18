cmake_minimum_required(VERSION 3.16)

set(LIBNAME plugin_alipay)

set(SOURCE
    lua_alipay.cpp
    alipay.cpp
)

set(HEADER
    lua_alipay.h
    alipay.h
)

list(APPEND SOURCE ${HEADER})

add_library(${LIBNAME} ${SOURCE})

target_include_directories(${LIBNAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(${LIBNAME} PRIVATE cclua)

if(ANDROID)
    target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_ALIPAY)
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${SOURCE})
