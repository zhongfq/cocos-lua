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
    if(CCLUA_BUILD_JPUSH)
        list(APPEND HEADER
            ios/JPushNotificationExtensionService.h
            ios/JPUSHService.h
        )
    endif()
    if(CCLUA_BUILD_JAUTH)
        list(APPEND HEADER
            ios/JVERIFICATIONService.h
        )
    endif()
    if(CCLUA_BUILD_JANALYTICS)
        list(APPEND HEADER
            ios/JANALYTICSEventObject.h
            ios/JANALYTICSService.h
        )
    endif()
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

target_link_libraries(${LIBNAME} PRIVATE xgame cocos2d)

if(IOS)
    find_library(LIBRESOLV resolv)
    target_link_libraries(${LIBNAME}
        PUBLIC ${LIBRESOLV}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/jcore-noidfa-ios-2.4.0.a
    )
    if(CCLUA_BUILD_JPUSH)
        target_link_libraries(${LIBNAME}
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/jpush-ios-3.4.0.a
        )
    endif()
    if(CCLUA_BUILD_JAUTH)
        target_link_libraries(${LIBNAME}
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/jverification-ios-2.6.7.a
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/account_login_sdk_noui_core.framework
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/EAccountApiSDK.framework
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/ESOneKeyLogin.framework
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/OAuth.framework
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/TYRZUISDK.framework
        )
    endif()
    if(CCLUA_BUILD_JANALYTICS)
        target_link_libraries(${LIBNAME}
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ios/janalytics-ios-2.1.2.a
        )
    endif()
endif()

if(ANDROID OR IOS)
    if(CCLUA_BUILD_JPUSH)
        target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_JPUSH)
    endif()
    if(CCLUA_BUILD_JAUTH)
        target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_JAUTH)
    endif()
    if(CCLUA_BUILD_JANALYTICS)
        target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_JANALYTICS)
    endif()
endif()

set_target_properties(${LIBNAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "cclua/plugins"
)

if(XCODE OR VS)
    cocos_mark_code_files(${LIBNAME} GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()
