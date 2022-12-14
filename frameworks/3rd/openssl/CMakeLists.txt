cmake_minimum_required(VERSION 3.10)

include(include/CMakeLists.txt)
include(crypto/CMakeLists.txt)
include(ssl/CMakeLists.txt)

add_definitions(-DOPENSSL_NO_ASM)
add_definitions(-DOPENSSL_NO_STATIC_ENGINE)
set(OPENSSLDIR "${CMAKE_INSTALL_PREFIX}/ssl")
set(ENGINESDIR "${CMAKE_INSTALL_PREFIX}/engines")
add_definitions("-DOPENSSLDIR=\"${OPENSSLDIR}\"")
add_definitions("-DENGINESDIR=\"${ENGINESDIR}\"")

if(APPLE)
    set(CMAKE_MACOSX_RPATH ON)
    add_definitions(-DOPENSSL_SYSNAME_MACOSX)
endif()

if(WIN32 AND NOT CYGWIN)
    add_definitions(-DOPENSSL_SYSNAME_WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include(CheckIncludeFile)
CHECK_INCLUDE_FILE(fcntl.h CHK_DLFCN)
if(CHK_DLFCN)
    set(HAVE_DLFCN_H ON)
endif()

if(APPLE)
    set(DSO_DLFCN ON)
    set(DSO_EXTENSION ".dylib")
elseif(WIN32 AND NOT CYGWIN)
    set(DSO_WIN32 ON)
    set(DSO_EXTENSION ".dll")
elseif(CYGWIN)
    set(DSO_DLFCN ON)
    set(DSO_EXTENSION ".dll")
else()
    if(CHK_DLFCN)
        set(DSO_DLFCN ON)
    else()
        set(DSO_NONE ON)
    endif()
    set(DSO_EXTENSION ".so")
endif()

include(CheckTypeSize)
check_type_size("long" LONG_INT)
check_type_size("long long" LONG_LONG_INT)
check_type_size("int" INT)
if(HAVE_LONG_INT AND (${LONG_INT} EQUAL 8))
    set(SIXTY_FOUR_BIT_LONG ON)
elseif(HAVE_LONG_LONG_INT AND (${LONG_LONG_INT} EQUAL 8))
    set(SIXTY_FOUR_BIT ON)
else()
    set(THIRTY_TWO_BIT ON)
endif()

if(MSVC OR (WIN32 AND MINGW AND NOT CYGWIN))
    set(OPENSSL_EXPORT_VAR_AS_FUNCTION 1)
endif()

string(TIMESTAMP BUILDINF_DATE "%Y-%m-%d %H:%M:%S UTC" UTC)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto/buildinf.h.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/include/crypto/buildinf.h
)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/opensslconf.h.cmake 
    ${CMAKE_CURRENT_BINARY_DIR}/include/openssl/opensslconf.h
)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto/bn_conf.h.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/include/crypto/bn_conf.h
)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto/dso_conf.h.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/include/crypto/dso_conf.h
)

add_library(openssl ${OPENSSL_HEADERS} ${CRYPTO_HEADERS} ${CRYPTO_SOURCES} ${SSL_HEADERS} ${SSL_SOURCES})
target_include_directories(openssl
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto/ec/curve448
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto/ec/curve448/arch_32
    ${CMAKE_CURRENT_SOURCE_DIR}/crypto/modes
    ${CMAKE_CURRENT_BINARY_DIR}/include/crypto
)

if(APPLE)
    target_compile_options(openssl
      PRIVATE
        -Wno-shorten-64-to-32
        -Wno-comma
        -Wno-unreachable-code
)
endif()

source_group(
  TREE
    ${CMAKE_CURRENT_SOURCE_DIR}
  PREFIX
    ""
  FILES
    ${OPENSSL_HEADERS}
    ${CRYPTO_HEADERS}
    ${CRYPTO_SOURCES}
    ${SSL_HEADERS}
    ${SSL_SOURCES}
)
