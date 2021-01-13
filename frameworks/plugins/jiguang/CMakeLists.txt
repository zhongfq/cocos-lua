cmake_minimum_required(VERSION 3.6)

set(LIBNAME plugin_jiguang)

set(SRC
    JiGuang.cpp
    lua_jiguang.cpp
)

set(HEADER
    JiGuang.h
    lua_jiguang.h
)

if(IOS)
    list(APPEND HEADER
        ios/JANALYTICSEventObject.h
        ios/JANALYTICSService.h
        ios/JPushNotificationExtensionService.h
        ios/JPUSHService.h
    )
    list(APPEND SRC
        JiGuang.mm
    )
endif()

list(APPEND SRC ${HEADER})

add_library(${LIBNAME} ${SRC})

target_include_directories(${LIBNAME}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(${LIBNAME} PRIVATE xgame)

if(IOS)
    target_include_directories(${LIBNAME}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ios
    )
    find_library(LIBRESOLV resolv)
    target_link_libraries(${LIBNAME} 
        PUBLIC ${LIBRESOLV}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/jpush-ios-3.4.0.a
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/jcore-noidfa-ios-2.4.0.a
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/janalytics-ios-2.1.2.a
    )
endif()

if(ANDROID OR IOS)
    target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_JPUSH)
    target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_JANALYTICS)
endif()

set_target_properties(${LIBNAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Plugins"
)

if(XCODE OR VS)
    cocos_mark_code_files(${LIBNAME} GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()
