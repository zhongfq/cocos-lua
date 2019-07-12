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

set(RUNTIME_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/runtime-src)
set(FRAMEWORK_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/frameworks)
set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/frameworks/cocos2d-x)
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

add_definitions(-DCC_ENABLE_SCRIPT_BINDING=0)
add_definitions(-DCC_CONSTRUCTOR_ACCESS=public)
add_definitions(-DSPINE_USE_STD_FUNCTION)

add_definitions(-DOLUA_DEBUG) # TODO: RM

include(CocosBuildSet)
add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)

# record sources, headers, resources...
set(GAME_SOURCE)
set(GAME_HEADER)

set(GAME_RES_FOLDER
    "${CMAKE_CURRENT_SOURCE_DIR}/assets"
    )
if(APPLE OR WINDOWS)
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

add_subdirectory(${FRAMEWORK_ROOT_PATH}/libfairygui)
add_subdirectory(${FRAMEWORK_ROOT_PATH}/libdragonbones)
add_subdirectory(${FRAMEWORK_ROOT_PATH}/libxgame)
add_subdirectory(${FRAMEWORK_ROOT_PATH}/plugins)

target_link_libraries(${APP_NAME} cocos2d fairygui dragonbones xgame plugins)
target_include_directories(${APP_NAME}
    PRIVATE ${RUNTIME_SRC_ROOT}/Classes
)

# mark app resources
setup_cocos_app_config(${APP_NAME})
if(APPLE)
    set_target_properties(${APP_NAME} PROPERTIES RESOURCE "${APP_UI_RES}")
    if(MACOSX)
        set_target_properties(${APP_NAME} PROPERTIES
                              MACOSX_BUNDLE_INFO_PLIST "${RUNTIME_SRC_ROOT}/proj.ios_mac/mac/Info.plist"
                              )
    elseif(IOS)
        cocos_pak_xcode(${APP_NAME} INFO_PLIST "iOSBundleInfo.plist.in")
        set_xcode_property(${APP_NAME} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
    endif()
elseif(WINDOWS)
    cocos_copy_target_dll(${APP_NAME} COPY_TO ${APP_RES_DIR}/..)
endif()

if(LINUX OR WINDOWS)
    cocos_copy_res(COPY_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
endif()
