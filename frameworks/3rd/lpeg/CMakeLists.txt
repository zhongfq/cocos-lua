cmake_minimum_required(VERSION 3.16)

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

target_link_libraries(lpeg PUBLIC lua)

target_include_directories(lpeg
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${LPEG_SRC})
