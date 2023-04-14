# Based on original work by David Manura
# Copyright (C) 2007-2012 LuaDist.
# Copyright (C) 2013 Brian Sidebotham

# Redistribution and use of this file is allowed according to the terms of the
# MIT license.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.1.0)

project(openssl)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(OPENSSL_NO_DSO ON)

if(NOT DEFINED OPENSSL_SRC_DIR)
    set(OPENSSL_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
endif()

set(OPENSSL_BIN_DIR "${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_MODULE_PATH "${OPENSSL_SRC_DIR}/cmake")

# option(WITH_APPS "Build applications" ON)

# OpenSSL version detection imported from FindOpenSSL.cmake

file(STRINGS "${OPENSSL_SRC_DIR}/include/openssl/opensslv.h" openssl_version_str
    REGEX "^#[\t ]*define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x([0-9a-fA-F])+.*")

function(from_hex HEX DEC)
    string(TOUPPER "${HEX}" HEX)
    set(_res 0)
    string(LENGTH "${HEX}" _strlen)

    while (_strlen GREATER 0)
        math(EXPR _res "${_res} * 16")
        string(SUBSTRING "${HEX}" 0 1 NIBBLE)
        string(SUBSTRING "${HEX}" 1 -1 HEX)
        if (NIBBLE STREQUAL "A")
            math(EXPR _res "${_res} + 10")
        elseif (NIBBLE STREQUAL "B")
            math(EXPR _res "${_res} + 11")
        elseif (NIBBLE STREQUAL "C")
            math(EXPR _res "${_res} + 12")
        elseif (NIBBLE STREQUAL "D")
            math(EXPR _res "${_res} + 13")
        elseif (NIBBLE STREQUAL "E")
            math(EXPR _res "${_res} + 14")
        elseif (NIBBLE STREQUAL "F")
            math(EXPR _res "${_res} + 15")
        else()
            math(EXPR _res "${_res} + ${NIBBLE}")
        endif()

        string(LENGTH "${HEX}" _strlen)
    endwhile()

    set(${DEC} ${_res} PARENT_SCOPE)
endfunction()

string(REGEX REPLACE "^.*OPENSSL_VERSION_NUMBER[\t ]+0x([0-9a-fA-F])([0-9a-fA-F][0-9a-fA-F])([0-9a-fA-F][0-9a-fA-F])([0-9a-fA-F][0-9a-fA-F])([0-9a-fA-F]).*$"
    "\\1;\\2;\\3;\\4;\\5" OPENSSL_VERSION_LIST "${openssl_version_str}")
list(GET OPENSSL_VERSION_LIST 0 OPENSSL_VERSION_MAJOR)
list(GET OPENSSL_VERSION_LIST 1 OPENSSL_VERSION_MINOR)
from_hex("${OPENSSL_VERSION_MINOR}" OPENSSL_VERSION_MINOR)
list(GET OPENSSL_VERSION_LIST 2 OPENSSL_VERSION_FIX)
from_hex("${OPENSSL_VERSION_FIX}" OPENSSL_VERSION_FIX)
list(GET OPENSSL_VERSION_LIST 3 OPENSSL_VERSION_PATCH)

if(NOT OPENSSL_VERSION_PATCH STREQUAL "00")
    from_hex("${OPENSSL_VERSION_PATCH}" _tmp)
    # 96 is the ASCII code of 'a' minus 1
    math(EXPR OPENSSL_VERSION_PATCH_ASCII "${_tmp} + 96")
    unset(_tmp)
    string(ASCII "${OPENSSL_VERSION_PATCH_ASCII}" OPENSSL_VERSION_PATCH_STRING)
endif ()

set(OPENSSL_VERSION "${OPENSSL_VERSION_MAJOR}.${OPENSSL_VERSION_MINOR}.${OPENSSL_VERSION_FIX}${OPENSSL_VERSION_PATCH_STRING}")

message(STATUS "OpenSSL version ${OPENSSL_VERSION}")

set(VERSION_MAJOR ${OPENSSL_VERSION_MAJOR})
set(VERSION_MINOR ${OPENSSL_VERSION_MINOR})
set(VERSION_PATCH ${OPENSSL_VERSION_PATCH})

set(VERSION_STRING ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(LIB_VERSION ${VERSION_MAJOR}.${VERSION_MINOR})
set(LIB_SOVERSION ${VERSION_MAJOR}.${VERSION_MINOR})

include_directories(
    "${OPENSSL_SRC_DIR}"
    "${OPENSSL_SRC_DIR}/crypto"
    "${OPENSSL_SRC_DIR}/include")

include_directories(
    "${OPENSSL_BIN_DIR}"
    "${OPENSSL_BIN_DIR}/crypto"
    "${OPENSSL_BIN_DIR}/ssl"
    "${OPENSSL_BIN_DIR}/include")

add_definitions(-DOPENSSL_NO_ASM)
add_definitions(-DOPENSSL_NO_STATIC_ENGINE)
add_definitions("-DOPENSSLDIR=\"/usr/local/ssl\"")
add_definitions("-DENGINESDIR=\"/usr/local/engines-1.1\"")

if(OPENSSL_NO_DSO)
    set(DSO_SCHEME "NONE")
    add_definitions(-DDSO_NONE)
    add_definitions(-DOPENSSL_NO_DSO)
else()
    if(WIN32)
        set(DSO_SCHEME "WIN32")
        add_definitions(-DDSO_WIN32)
    else()
        set(DSO_SCHEME "DLFCN")
        add_definitions(-DDSO_DLFCN)
        add_definitions(-DHAVE_DLFCN_H)
    endif()
endif()

if(OPENSSL_NO_ASYNC)
    add_definitions(-DOPENSSL_NO_ASYNC)
endif()

if(OPENSSL_NO_ENGINE)
    add_definitions(-DOPENSSL_NO_ENGINE)
endif()

set(OPENSSL_RAND_SEED_LIST
    OPENSSL_RAND_SEED_NONE
    OPENSSL_RAND_SEED_OS
    OPENSSL_RAND_SEED_GETRANDOM
    OPENSSL_RAND_SEED_LIBRANDOM
    OPENSSL_RAND_SEED_DEVRANDOM
    OPENSSL_RAND_SEED_RDTSC
    OPENSSL_RAND_SEED_RDCPU
    OPENSSL_RAND_SEED_EGD)

if(NOT DEFINED OPENSSL_RAND_SEED_OS)
    set(OPENSSL_RAND_SEED_OS ON)
endif()

foreach(OPENSSL_RAND_SEED ${OPENSSL_RAND_SEED_LIST})
    if(${OPENSSL_RAND_SEED})
        add_definitions( -D${OPENSSL_RAND_SEED} )
    endif()
endforeach()

if(MSVC)
    include(MSVCRuntime)
    configure_msvc_runtime()
endif()

if(WIN32)
    set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
    set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
endif()

if(APPLE)
    set(CMAKE_MACOSX_RPATH ON)
    add_definitions(-DOPENSSL_SYSNAME_MACOSX)
endif()

if(WIN32 AND NOT CYGWIN)
    add_definitions(-DOPENSSL_SYSNAME_WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)

    if(BUILD_SHARED_LIBS)
        # avoid conflict: ocsp.h and wincrypt.h
        add_definitions(-D_WINDLL)
    endif()
endif()

if(MINGW)
    set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--export-all" )
endif()

include(CheckTypeSize)
check_type_size("long" LONG_INT)
check_type_size("long long" LONG_LONG_INT)
check_type_size("int" INT)
if(HAVE_LONG_INT AND (${LONG_INT} EQUAL 8))
    set(SIXTY_FOUR_BIT_LONG ON )
elseif(HAVE_LONG_LONG_INT AND (${LONG_LONG_INT} EQUAL 8))
    set(SIXTY_FOUR_BIT ON)
else()
    set(THIRTY_TWO_BIT ON)
endif()

if(WIN32 AND MINGW AND NOT CYGWIN)
    set(OPENSSL_EXPORT_VAR_AS_FUNCTION true)
endif()

add_subdirectory(crypto)
add_subdirectory(ssl)

target_include_directories(crypto
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto/ec/curve448
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto/ec/curve448/arch_32
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto/modes
    ${CMAKE_CURRENT_BINARY_DIR}/include/crypto
)

if(WITH_APPS)
    add_subdirectory(apps)
endif()

file(COPY "${OPENSSL_SRC_DIR}/include/internal" DESTINATION include)
file(COPY "${OPENSSL_SRC_DIR}/include/openssl" DESTINATION include)

configure_file("${OPENSSL_SRC_DIR}/opensslconf.h.cmake"
    "${OPENSSL_BIN_DIR}/include/openssl/opensslconf.h")

file(READ "${OPENSSL_SRC_DIR}/c_rehash.cmake" C_REHASH)
string(REPLACE "@OPENSSLDIR@" "${OPENSSLDIR}" C_REHASH "${C_REHASH}")
string(REPLACE "@CMAKE_INSTALL_PREFIX@" "${CMAKE_INSTALL_PREFIX}" C_REHASH "${C_REHASH}")
file(WRITE "${OPENSSL_BIN_DIR}/c_rehash" "${C_REHASH}")

install(DIRECTORY "${OPENSSL_BIN_DIR}/include/openssl" DESTINATION include)

install(FILES
    "${OPENSSL_BIN_DIR}/c_rehash"
    "${OPENSSL_SRC_DIR}/FAQ"
    "${OPENSSL_SRC_DIR}/LICENSE"
    "${OPENSSL_SRC_DIR}/README"
    "${OPENSSL_SRC_DIR}/README.ENGINE"
    DESTINATION "share/openssl")

install(DIRECTORY doc DESTINATION share)

# Generate the package target
set(CPACK_GENERATOR ZIP TGZ)
set(CPACK_PACKAGE_NAME "openssl-cmake")
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})

include(CPack)
