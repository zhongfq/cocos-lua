#/****************************************************************************
# Copyright (c) 2013-2014 cocos2d-x.org
# Copyright (c) 2015-2017 Chukong Technologies Inc.
#
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/

cmake_minimum_required(VERSION 3.6)

set(APP_NAME cocos-lua)

project(${APP_NAME})

option(CCLUA_BUILD_SPINE "Build with spine support" ON)
option(CCLUA_BUILD_PBC "Build with pbc support" ON)
option(CCLUA_BUILD_SPROTO "Build with sproto support" ON)
option(CCLUA_BUILD_LPEG "Build with lpeg support" ON) # if CCLUA_BUILD_SPROTO ON then lpeg auto set ON end
option(CCLUA_BUILD_BUGLY "Build with bugly support" ON)
option(CCLUA_BUILD_LUASOCKET "Build with lua_socket support" ON)
option(CCLUA_BUILD_LAME "Build with lame support" ON)
option(CCLUA_BUILD_QRCODE "Build with qrcode support" ON)
option(CCLUA_BUILD_FAIRYGUI "Build with fairygui support" ON)
option(CCLUA_BUILD_DRAGONBONES "Build with dragonbones support" ON)
option(CCLUA_BUILD_SWF "Build with swf support" OFF)
option(CCLUA_FEATURE_MSAA "Support MSAA" OFF)
option(CCLUA_FEATURE_IDFA "Support IDFA" OFF)

include(config.cmake)

if(XCODE)
    if(NOT DEFINED CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET)
        SET (CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET 9.0)
    endif()
endif()

add_definitions(-DCC_FILEUTILS_APPLE_ENABLE_OBJC=0)
add_definitions(-DCC_ENABLE_SCRIPT_BINDING=0)
add_definitions(-DCC_CONSTRUCTOR_ACCESS=public)

if(CCLUA_BUILD_SPINE)
    set(BUILD_EDITOR_SPINE ON)
    add_definitions(-DSPINE_USE_STD_FUNCTION)
else()
    set(BUILD_EDITOR_SPINE OFF)
endif()

if(NOT DEFINED BUILD_ENGINE_DONE) # to test cocos-lua into root project
    set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/frameworks/cocos2d-x)
    set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

    include(CocosBuildSet)
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)
endif()

# runtime-src
set(RUNTIME_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/runtime-src)

# record sources, headers, resources...
set(GAME_SOURCE)
set(GAME_HEADER)

set(GAME_RES_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/assets")

if(APPLE)
    file(GLOB folder_files "${GAME_RES_FOLDER}/*")
    foreach(file ${folder_files})
        if(NOT ${file} MATCHES ".DS_Store$")
            list(APPEND common_res_files ${file})
            set_source_files_properties(${file} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
            source_group("Resources" FILES ${file})
        endif()
    endforeach()
elseif(WINDOWS)
    cocos_mark_multi_resources(common_res_files RES_TO "Resources" FOLDERS ${GAME_RES_FOLDER})
endif()

# add cross-platforms source files and header files
list(APPEND GAME_SOURCE
     ${RUNTIME_SRC_ROOT}/Classes/AppDelegate.cpp
     )
list(APPEND GAME_HEADER
     ${RUNTIME_SRC_ROOT}/Classes/AppDelegate.h
     )

if(ANDROID)
    # change APP_NAME to the share library name for Android, it's value depend on AndroidManifest.xml
    set(APP_NAME cocoslua)
    list(APPEND GAME_SOURCE
         ${RUNTIME_SRC_ROOT}/proj.android/app/jni/hellocpp/main.cpp
         )
elseif(LINUX)
    list(APPEND GAME_SOURCE
         ${RUNTIME_SRC_ROOT}/proj.linux/main.cpp
         )
elseif(WINDOWS)
    list(APPEND GAME_HEADER
         ${RUNTIME_SRC_ROOT}/proj.win32/main.h
         ${RUNTIME_SRC_ROOT}/proj.win32/resource.h
         )
    list(APPEND GAME_SOURCE
         ${RUNTIME_SRC_ROOT}/proj.win32/main.cpp
         ${RUNTIME_SRC_ROOT}/proj.win32/game.rc
         ${common_res_files}
         )
elseif(APPLE)
    if(IOS)
        list(APPEND GAME_HEADER
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/AppController.h
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/RootViewController.h
             )
        set(APP_UI_RES
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/Info.plist
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/LaunchScreen.storyboard
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/LaunchScreenBackground.png
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/Images.xcassets
            )
        list(APPEND GAME_SOURCE
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/main.m
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/AppController.mm
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/RootViewController.mm
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/Prefix.pch
             ${APP_UI_RES}
             )
    elseif(MACOSX)
        set(APP_UI_RES
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/mac/Icon.icns
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/mac/Info.plist
            )
        list(APPEND GAME_SOURCE
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/mac/main.cpp
             ${RUNTIME_SRC_ROOT}/proj.ios_mac/mac/Prefix.pch
             ${APP_UI_RES}
             )
    endif()
    list(APPEND GAME_SOURCE ${common_res_files})
endif()

# mark app complie info and libs info
set(all_code_files
    ${GAME_HEADER}
    ${GAME_SOURCE}
    )
if(NOT ANDROID)
    add_executable(${APP_NAME} ${all_code_files})
else()
    add_library(${APP_NAME} SHARED ${all_code_files})
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos/platform/android ${ENGINE_BINARY_PATH}/cocos/platform)
    target_link_libraries(${APP_NAME} -Wl,--whole-archive cpp_android_spec -Wl,--no-whole-archive)
endif()

if(XCODE OR VS)
    cocos_mark_code_files(${APP_NAME} GROUPBASE ${RUNTIME_SRC_ROOT})
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/frameworks/libxgame)
target_link_libraries(${APP_NAME} xgame)

if(CCLUA_BUILD_FAIRYGUI)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/frameworks/libfairygui)
    target_link_libraries(${APP_NAME} fairygui)
endif()

if(CCLUA_BUILD_DRAGONBONES)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/frameworks/libdragonbones)
    target_link_libraries(${APP_NAME} dragonbones)
endif()

if(CCLUA_BUILD_SWF)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/frameworks/libswf)
    target_link_libraries(${APP_NAME} swf)
    target_compile_definitions(${APP_NAME} PUBLIC CCLUA_BUILD_SWF)
endif()

target_link_libraries(${APP_NAME} cocos2d)
target_include_directories(${APP_NAME}
    PRIVATE ${RUNTIME_SRC_ROOT}/Classes
    PRIVATE ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)

# suspend warnings
if(APPLE)
    target_compile_options(cocos2d PRIVATE -Wno-reorder)
    target_compile_options(cocos2d PRIVATE -Wno-deprecated-declarations)
    target_compile_options(cocos2d PRIVATE -Wno-shorten-64-to-32)
    if(CCLUA_BUILD_FAIRYGUI)
        target_compile_options(fairygui PRIVATE -Wno-reorder)
    endif()
    if(CCLUA_BUILD_DRAGONBONES)
        target_compile_options(dragonbones PRIVATE -Wno-shorten-64-to-32)
    endif()
endif()

# mark app resources
setup_cocos_app_config(${APP_NAME})
if(APPLE)
    set_target_properties(${APP_NAME} PROPERTIES RESOURCE "${APP_UI_RES}")

    if(MACOSX)
        set_xcode_property(${APP_NAME} INFOPLIST_FILE "${RUNTIME_SRC_ROOT}/proj.ios_mac/mac/Info.plist")
    elseif(IOS)
        set_xcode_property(${APP_NAME} INFOPLIST_FILE "${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/Info.plist")
        set_xcode_property(${APP_NAME} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
    endif()

    # For code-signing, set the DEVELOPMENT_TEAM:
    set_xcode_property(${APP_NAME} CLANG_ENABLE_OBJC_ARC "YES")
    set_xcode_property(${APP_NAME} SKIP_INSTALL "NO")
    set_xcode_property(${APP_NAME} INSTALL_PATH "$(LOCAL_APPS_DIR)")
    set_xcode_property(${APP_NAME} DEVELOPMENT_TEAM "${APPLE_DEVELOPMENT_TEAM}")
    set_xcode_property(${APP_NAME} PRODUCT_BUNDLE_IDENTIFIER "${APP_PACKAGE_NAME}")
    set_xcode_property(${APP_NAME} PRODUCT_NAME "${APP_PRODUCT_NAME}")
    set_xcode_property(${APP_NAME} CURRENT_PROJECT_VERSION "${APP_BUILD}")
    set_xcode_property(${APP_NAME} MARKETING_VERSION "${APP_VERSION}")
    set_xcode_property(${APP_NAME} TARGETED_DEVICE_FAMILY "1,2")
    set_xcode_property(${APP_NAME} IPHONEOS_DEPLOYMENT_TARGET "9.0")
elseif(WINDOWS)
    cocos_copy_target_dll(${APP_NAME})
endif()

if(LINUX OR WINDOWS)
    cocos_get_resource_path(APP_RES_DIR ${APP_NAME})
    cocos_copy_target_res(${APP_NAME} LINK_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
endif()