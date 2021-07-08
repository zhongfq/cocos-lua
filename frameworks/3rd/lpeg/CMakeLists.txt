cmake_minimum_required(VERSION 3.6)

set(LPEG_HEADER
    lpcap.h
    lpcode.h
    lpprint.h
    lptree.h
    lptypes.h
    lpvm.h
)
set(LPEG_SRC
    lpcap.c
    lpcode.c
    lpprint.c
    lptree.c
    lpvm.c
)

list(APPEND LPEG_SRC ${LPEG_HEADER})

add_library(lpeg ${LPEG_SRC})

target_link_libraries(lpeg 
	PRIVATE xgame
	PRIVATE cocos2d
)

target_include_directories(lpeg
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

set_target_properties(lpeg PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Internal"
)

if(XCODE OR VS)
    cocos_mark_code_files("lpeg" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()