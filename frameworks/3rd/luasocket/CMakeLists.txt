cmake_minimum_required(VERSION 3.6)

set(LUASOCKET_HEADER
    auxiliar.h
    buffer.h
    compat.h
    except.h
    inet.h
    io.h
    luasocket_scripts.h
    luasocket.h
    mime.h
    options.h
    pierror.h
    select.h
    socket.h
    tcp.h
    timeout.h
    udp.h
    unixdgram.h
    unixstream.h
)
set(LUASOCKET_SRC
    auxiliar.c
    buffer.c
    compat.c
    except.c
    inet.c
    io.c
    luasocket_scripts.c
    luasocket.c
    mime.c
    options.c
    select.c
    tcp.c
    timeout.c
    udp.c
    unixdgram.c
    unixstream.c
)

if (WINDOWS)
    list(APPEND LUASOCKET_HEADER
        wsocket.h
    )
    list(APPEND LUASOCKET_SRC
        wsocket.c
    )
else()
    list(APPEND LUASOCKET_HEADER
        unix.h
        usocket.h
    )
    list(APPEND LUASOCKET_SRC
        serial.c
        unix.c
        usocket.c
    )
endif()

list(APPEND LUASOCKET_SRC ${LUASOCKET_HEADER})

add_library(luasocket ${LUASOCKET_SRC})

target_link_libraries(luasocket 
	PRIVATE xgame
	PRIVATE cocos2d
)

if(APPLE)
    target_compile_options(luasocket PRIVATE -Wno-shorten-64-to-32)
endif()

target_include_directories(luasocket
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

set_target_properties(luasocket PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Internal"
)

if(XCODE OR VS)
    cocos_mark_code_files("luasocket" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()