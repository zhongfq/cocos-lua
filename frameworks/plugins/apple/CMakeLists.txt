cmake_minimum_required(VERSION 3.6)

set(LIBNAME plugin_apple)

set(SRC
    lua_apple.cpp
)

set(HEADER
    lua_apple.h
)

if(IOS)
    list(APPEND SRC Apple.mm)
    list(APPEND HEADER Apple.h)
endif()

list(APPEND SRC ${HEADER})

add_library(${LIBNAME} ${SRC})

target_include_directories(${LIBNAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(${LIBNAME} xgame cocos2d)

if(IOS)
    if(CCLUA_BUILD_APPLE_AUTH)
        find_library(AUTHENTICATION_SERVICES AuthenticationServices)
        target_link_libraries(${LIBNAME} ${AUTHENTICATION_SERVICES})
        target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_APPLE_AUTH)
    endif()
    if(CCLUA_BUILD_APPLE_IAP)
        find_library(STOREKIT_LIBRARY StoreKit)
        target_link_libraries(${LIBNAME} ${STOREKIT_LIBRARY})
        target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_APPLE_IAP)
    endif()
endif()

if(APPLE)
    set_xcode_property(${LIBNAME} CLANG_ENABLE_OBJC_ARC "YES")
endif()

set_target_properties(${LIBNAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "cclua/plugins"
)

if(XCODE OR VS)
    cocos_mark_code_files(${LIBNAME} GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()