cmake_minimum_required(VERSION 3.6)

project(bugly)

add_library(bugly STATIC IMPORTED GLOBAL)

set_target_properties(bugly PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

set_target_properties(bugly PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/libbugly.a"
)