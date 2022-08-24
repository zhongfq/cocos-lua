cmake_minimum_required(VERSION 3.6)

set(SPROTO_HEADER
    lsproto.h
    msvcint.h
    sproto.h
)
set(SPROTO_SRC
    lsproto.c
    sproto.c
)

list(APPEND SPROTO_SRC ${SPROTO_HEADER})

add_library(sproto ${SPROTO_SRC})

target_link_libraries(sproto 
	PRIVATE xgame
	PRIVATE cocos2d
)

target_include_directories(sproto
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

set_target_properties(sproto PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "cclua/3rd"
)

if(XCODE OR VS)
    cocos_mark_code_files("sproto" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()