cmake_minimum_required(VERSION 3.6)

set(LIBNAME plugin_talkingdata)

set(SOURCE
    lua_talkingdata.cpp
    TalkingData.cpp
)

set(HEADER
    lua_talkingdata.h
    TalkingData.h
)

if(IOS)
    list(APPEND HEADER
        ios/TalkingData.h
    )
    list(APPEND SOURCE
        TalkingData.mm
    )
endif()

list(APPEND SOURCE ${HEADER})

add_library(${LIBNAME} ${SOURCE})

target_include_directories(${LIBNAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(${LIBNAME} PRIVATE xgame)

if(IOS)
    target_link_libraries(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/libTalkingData.a)
endif()

if(ANDROID OR IOS)
    target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_TALKINGDATA)
endif()

set_target_properties(${LIBNAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Plugins"
)

if(XCODE OR VS)
    cocos_mark_code_files(${LIBNAME} GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()