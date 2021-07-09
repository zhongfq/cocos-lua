cmake_minimum_required(VERSION 3.6)

set(SQLITE3_HEADER
    lsqlite3.h
    sqlite3.h
)
set(SQLITE3_SRC
    lsqlite3.c
    sqlite3.c
)

list(APPEND SQLITE3_SRC ${SQLITE3_HEADER})

add_library(sqlite3 ${SQLITE3_SRC})

target_link_libraries(sqlite3 
	PRIVATE xgame
	PRIVATE cocos2d
)

if(APPLE)
    target_compile_options(sqlite3 PRIVATE -Wno-shorten-64-to-32)
    target_compile_options(sqlite3 PRIVATE -Wno-unreachable-code)
    target_compile_options(sqlite3 PRIVATE -Wno-comma)
    target_compile_options(sqlite3 PRIVATE "-Wno-#warnings")
endif()

target_include_directories(sqlite3
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

set_target_properties(sqlite3 PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Internal"
)

if(XCODE OR VS)
    cocos_mark_code_files("sqlite3" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()