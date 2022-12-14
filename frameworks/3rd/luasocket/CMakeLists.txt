cmake_minimum_required(VERSION 3.16)

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
)
set(LUASOCKET_SRC
    auxiliar.c
    buffer.c
    compat.c
    except.c
    inet.c
    io.c
    luasocket_scripts.cpp
    luasocket.c
    mime.c
    options.c
    select.c
    tcp.c
    timeout.c
    udp.c
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
        unixdgram.h
        unixstream.h
    )
    list(APPEND LUASOCKET_SRC
        serial.c
        unix.c
        usocket.c
        unixdgram.c
        unixstream.c
    )
endif()

list(APPEND LUASOCKET_SRC ${LUASOCKET_HEADER})

add_library(luasocket ${LUASOCKET_SRC})

target_link_libraries(luasocket PUBLIC lua)

if(APPLE)
    target_compile_options(luasocket PRIVATE -Wno-shorten-64-to-32)
endif()

target_include_directories(luasocket
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${LUASOCKET_SRC})
