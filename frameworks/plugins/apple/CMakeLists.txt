cmake_minimum_required(VERSION 3.16)

set(LIBNAME plugin_apple)

set(SRC
    lua_apple.cpp
)

set(HEADER
    lua_apple.h
)

if(APPLE)
    list(APPEND SRC apple.mm)
    list(APPEND HEADER apple.h)
endif()

list(APPEND SRC ${HEADER})

add_library(${LIBNAME} ${SRC})

target_include_directories(${LIBNAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(${LIBNAME} xgame cocos2d)

if(IOS)
    find_library(AUTHENTICATION_SERVICES AuthenticationServices)
    target_link_libraries(${LIBNAME} ${AUTHENTICATION_SERVICES})
    find_library(STOREKIT_LIBRARY StoreKit)
    target_link_libraries(${LIBNAME} ${STOREKIT_LIBRARY})
endif()

if(APPLE)
    set_xcode_property(${LIBNAME} CLANG_ENABLE_OBJC_ARC "YES")
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${SRC})