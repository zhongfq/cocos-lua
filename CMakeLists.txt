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

cmake_minimum_required(VERSION 3.16)

option(CCLUA_BUILD_SPINE "Build with spine support" ON)
option(CCLUA_BUILD_COCOSSTUDIO "Build with cocos studio support" OFF)
option(CCLUA_BUILD_PBC "Build with pbc support" ON)
option(CCLUA_BUILD_SPROTO "Build with sproto support" ON)
option(CCLUA_BUILD_LPEG "Build with lpeg support" ON) # if CCLUA_BUILD_SPROTO ON then lpeg auto set ON end
option(CCLUA_BUILD_BUGLY "Build with bugly support" ON)
option(CCLUA_BUILD_LUASOCKET "Build with lua_socket support" ON)
option(CCLUA_BUILD_SQLITE3 "Build with sqlite3 support" OFF)
option(CCLUA_BUILD_FAIRYGUI "Build with fairygui support" ON)
option(CCLUA_BUILD_DRAGONBONES "Build with dragonbones support" OFF)
option(CCLUA_BUILD_BOX2D "Build with box2d support" ON)
option(CCLUA_BUILD_SWF "Build with swf support" OFF)
option(CCLUA_BUILD_JPUSH "Build with jpush support" OFF)
option(CCLUA_BUILD_JAUTH "Build with jauth support" OFF)
option(CCLUA_BUILD_JANALYTICS "Build with janalytics support" OFF)
option(CCLUA_BUILD_TALKINGDATA "Build with talkingdata support" OFF)
option(CCLUA_BUILD_WECHAT "Build with wechat support" OFF)
option(CCLUA_BUILD_ALIPAY "Build with alipay support" OFF)
option(CCLUA_BUILD_HUAWEI "Build with huawei support" OFF)
option(CCLUA_BUILD_OPPO "Build with oppo support" OFF)
option(CCLUA_BUILD_VIVO "Build with vivo support" OFF)
option(CCLUA_FEATURE_MSAA "Support MSAA" OFF)
option(CCLUA_FEATURE_TRACKING "Support TRACKING" OFF)
option(CCLUA_FEATURE_INTCOLOR "Support integer color" ON)

include(config.cmake)

set(APP_NAME cocoslua)

project(${APP_PROJECT_NAME})

add_definitions(-DCC_FILEUTILS_APPLE_ENABLE_OBJC=0)
add_definitions(-DCC_ENABLE_SCRIPT_BINDING=0)
add_definitions(-DCC_CONSTRUCTOR_ACCESS=public)

if(CCLUA_BUILD_SPINE)
  set(BUILD_EDITOR_SPINE ON)
  add_definitions(-DSPINE_USE_STD_FUNCTION)
else()
  set(BUILD_EDITOR_SPINE OFF)
endif()

if(NOT DEFINED BUILD_ENGINE_DONE)
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
list(APPEND GAME_SOURCE ${RUNTIME_SRC_ROOT}/Classes/AppDelegate.cpp)
list(APPEND GAME_HEADER ${RUNTIME_SRC_ROOT}/Classes/AppDelegate.h)

if(ANDROID)
  # change APP_NAME to the share library name for Android, it's value depend on AndroidManifest.xml
  list(APPEND GAME_SOURCE ${RUNTIME_SRC_ROOT}/proj.android/app/jni/hellocpp/main.cpp)
elseif(LINUX)
  list(APPEND GAME_SOURCE ${RUNTIME_SRC_ROOT}/proj.linux/main.cpp)
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
    set(APP_UI_RES ${RUNTIME_SRC_ROOT}/proj.ios_mac/mac/Icon.icns)
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

target_compile_definitions(${APP_NAME} PUBLIC APP_NAME="${APP_NAME}")
target_compile_definitions(${APP_NAME} PUBLIC APP_PACKAGE_NAME="${APP_PACKAGE_NAME}")

target_link_libraries(${APP_NAME} cocos2d)
target_include_directories(${APP_NAME}
  PRIVATE
    ${RUNTIME_SRC_ROOT}/Classes
    ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)

function(add_module path)
  set(oneValue LINK_TO FOLDER)
  set(multiValue TARGETS ENABLEIF DEFINITIONS)
  set(enable OFF)
  set(keys ${oneValue} ${multiValue})
  cmake_parse_arguments("ARG" "" "${oneValue}" "${multiValue}" ${ARGN})
  string(REPLACE ";" " " ARG_DEFINITIONS "${ARG_DEFINITIONS}")
  foreach(opt ${ARG_ENABLEIF})
    if(${opt})
      set(enable ON)
    endif()
  endforeach()
  if(NOT DEFINED ARG_ENABLEIF OR enable)
    add_subdirectory(${path})
    message(STATUS "add module: ${path}")
    foreach(name ${ARG_TARGETS})
      if(DEFINED ARG_DEFINITIONS)
        target_compile_definitions(${name} PUBLIC ${ARG_DEFINITIONS})
      endif()
      if(DEFINED ARG_FOLDER)
        set_target_properties(${name} PROPERTIES FOLDER ${ARG_FOLDER})
      endif()
      target_link_libraries(${ARG_LINK_TO} ${name})
    endforeach()
  endif()
endfunction()

add_module(frameworks/cclua TARGETS cclua LINK_TO ${APP_NAME})
add_module(frameworks/libswf TARGETS swf LINK_TO ${APP_NAME} ENABLEIF CCLUA_BUILD_SWF DEFINITIONS CCLUA_BUILD_SWF)
add_module(frameworks/3rd/box2d TARGETS box2d LINK_TO cclua FOLDER "3rd" ENABLEIF CCLUA_BUILD_BOX2D DEFINITIONS CCLUA_BUILD_BOX2D)
add_module(frameworks/3rd/bzip2 TARGETS bz2 LINK_TO cclua FOLDER "3rd")
add_module(frameworks/3rd/cjson TARGETS cjson LINK_TO ${APP_NAME} FOLDER "3rd")
add_module(frameworks/3rd/dragonbones TARGETS dragonbones LINK_TO cclua FOLDER "3rd" ENABLEIF CCLUA_BUILD_DRAGONBONES DEFINITIONS CCLUA_BUILD_DRAGONBONES)
add_module(frameworks/3rd/fairygui TARGETS fairygui LINK_TO cclua FOLDER "3rd" ENABLEIF CCLUA_BUILD_FAIRYGUI DEFINITIONS CCLUA_BUILD_FAIRYGUI)
add_module(frameworks/3rd/glsl-optimizer TARGETS glsl_optimizer LINK_TO cocos2d FOLDER "3rd" ENABLEIF APPLE)
add_module(frameworks/3rd/freetype TARGETS freetype LINK_TO cocos2d FOLDER "3rd")
add_module(frameworks/3rd/jpeg TARGETS jpeg LINK_TO cocos2d FOLDER "3rd")
add_module(frameworks/3rd/lfs TARGETS lfs LINK_TO ${APP_NAME} FOLDER "3rd")
add_module(frameworks/3rd/lmd5 TARGETS lmd5 LINK_TO ${APP_NAME} FOLDER "3rd")
add_module(frameworks/3rd/lpeg TARGETS lpeg LINK_TO ${APP_NAME} FOLDER "3rd" ENABLEIF CCLUA_BUILD_LPEG DEFINITIONS CCLUA_BUILD_LPEG)
add_module(frameworks/3rd/lua TARGETS lua LINK_TO cclua FOLDER "3rd")
add_module(frameworks/3rd/luaopenssl TARGETS luaopenssl LINK_TO ${APP_NAME} FOLDER "3rd")
add_module(frameworks/3rd/luasocket TARGETS luasocket LINK_TO ${APP_NAME} FOLDER "3rd" ENABLEIF CCLUA_BUILD_LUASOCKET DEFINITIONS CCLUA_BUILD_LUASOCKET)
add_module(frameworks/3rd/md5 TARGETS md5 LINK_TO cocos2d FOLDER "3rd")
add_module(frameworks/3rd/pbc TARGETS pbc LINK_TO ${APP_NAME} FOLDER "3rd" ENABLEIF CCLUA_BUILD_PBC DEFINITIONS CCLUA_BUILD_PBC)
add_module(frameworks/3rd/png TARGETS png LINK_TO cocos2d FOLDER "3rd")
add_module(frameworks/3rd/sproto TARGETS sproto LINK_TO ${APP_NAME} FOLDER "3rd" ENABLEIF CCLUA_BUILD_SPROTO DEFINITIONS CCLUA_BUILD_SPROTO)
add_module(frameworks/3rd/sqlite3 TARGETS sqlite3 LINK_TO ${APP_NAME} FOLDER "3rd" ENABLEIF CCLUA_BUILD_SQLITE3 DEFINITIONS CCLUA_BUILD_SQLITE3)
add_module(frameworks/3rd/openssl TARGETS ssl crypto LINK_TO cocos2d FOLDER "3rd")
add_module(frameworks/3rd/unzip TARGETS unzip LINK_TO cocos2d FOLDER "3rd")
add_module(frameworks/3rd/xxtea TARGETS xxtea LINK_TO cocos2d FOLDER "3rd")
add_module(frameworks/3rd/zlib TARGETS zlib LINK_TO cocos2d FOLDER "3rd")
add_module(frameworks/plugins/alipay TARGETS plugin_alipay LINK_TO ${APP_NAME} FOLDER "Plugins" ENABLEIF CCLUA_BUILD_ALIPAY)
add_module(frameworks/plugins/apple TARGETS plugin_apple LINK_TO ${APP_NAME} FOLDER "Plugins" ENABLEIF APPLE)
add_module(frameworks/plugins/huawei TARGETS plugin_huawei LINK_TO ${APP_NAME} FOLDER "Plugins" ENABLEIF CCLUA_BUILD_HUAWEI)
add_module(frameworks/plugins/janalytics TARGETS plugin_janalytics LINK_TO ${APP_NAME} FOLDER "Plugins" ENABLEIF CCLUA_BUILD_JANALYTICS)
add_module(frameworks/plugins/jauth TARGETS plugin_jauth LINK_TO ${APP_NAME} FOLDER "Plugins" ENABLEIF CCLUA_BUILD_JAUTH)
add_module(frameworks/plugins/jpush TARGETS plugin_jpush LINK_TO ${APP_NAME} FOLDER "Plugins" ENABLEIF CCLUA_BUILD_JPUSH)
add_module(frameworks/plugins/oppo TARGETS plugin_oppo LINK_TO ${APP_NAME} FOLDER "Plugins" ENABLEIF CCLUA_BUILD_OPPO)
add_module(frameworks/plugins/talkingdata TARGETS plugin_talkingdata LINK_TO ${APP_NAME} FOLDER "Plugins" ENABLEIF CCLUA_BUILD_TALKINGDATA)
add_module(frameworks/plugins/vivo TARGETS plugin_vivo LINK_TO ${APP_NAME} FOLDER "Plugins" ENABLEIF CCLUA_BUILD_VIVO)
add_module(frameworks/plugins/wechat TARGETS plugin_wechat LINK_TO ${APP_NAME} FOLDER "Plugins" ENABLEIF CCLUA_BUILD_WECHAT)

# suspend warnings
if(APPLE)
  target_compile_options(cocos2d
    PRIVATE
      -Wno-reorder
      -Wno-deprecated-declarations
      -Wno-shorten-64-to-32
      -Wno-comma
  )
  if(CCLUA_BUILD_FAIRYGUI)
    target_compile_options(fairygui
      PRIVATE
        -Wno-reorder
        -Wno-shorten-64-to-32
    )
  endif()
  if(CCLUA_BUILD_DRAGONBONES)
    target_compile_options(dragonbones
      PRIVATE
        -Wno-shorten-64-to-32
    )
  endif()
  if(CCLUA_BUILD_BOX2D)
    target_compile_options(box2d
      PRIVATE
        -Wno-shorten-64-to-32
    )
  endif()
endif()

# link other flags
if(IOS)
  set_target_properties(${APP_NAME} PROPERTIES LINK_FLAGS -ObjC)
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
    set_xcode_property(${APP_NAME} CODE_SIGN_ENTITLEMENTS "${RUNTIME_SRC_ROOT}/proj.ios_mac/ios/app.entitlements")
    set(CMAKE_XCODE_ATTRIBUTE_ARCHS "arm64")
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
  # set_xcode_property(${APP_NAME} GCC_GENERATE_DEBUGGING_SYMBOLS "YES")
  # set_xcode_property(${APP_NAME} DEBUG_INFORMATION_FORMAT "DWARF")

  if(NOT DEFINED CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET)
    SET (CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET 11.0)
  endif()

  # warnings
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_WARN_BLOCK_CAPTURE_AUTORELEASING "YES")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_WARN_BOOL_CONVERSION "YES")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_WARN_COMMA "YES")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_WARN_CONSTANT_CONVERSION "YES")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_WARN_ENUM_CONVERSION "YES")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_WARN_INFINITE_RECURSION "YES")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_WARN_INT_CONVERSION "YES")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_WARN_NON_LITERAL_NULL_CONVERSION "YES")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_WARN_STRICT_PROTOTYPES "YES")
  set(CMAKE_XCODE_ATTRIBUTE_CLANG_WARN_UNREACHABLE_CODE "YES")
  set(CMAKE_XCODE_ATTRIBUTE_GCC_CLANG_WARN_EMPTY_BODY "YES")
  set(CMAKE_XCODE_ATTRIBUTE_GCC_WARN_64_TO_32_BIT_CONVERSION "YES")
  set(CMAKE_XCODE_ATTRIBUTE_GCC_WARN_ABOUT_RETURN_TYPE "YES_ERROR")
  set(CMAKE_XCODE_ATTRIBUTE_GCC_WARN_MISSING_PARENTHESES "YES")
  set(CMAKE_XCODE_ATTRIBUTE_GCC_WARN_UNINITIALIZED_AUTOS "YES")
elseif(WINDOWS)
  cocos_copy_target_dll(${APP_NAME})
endif()

if(LINUX OR WINDOWS)
  cocos_get_resource_path(APP_RES_DIR ${APP_NAME})
  cocos_copy_target_res(${APP_NAME} LINK_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
endif()

# TODO: remove
if(WINDOWS)
  get_target_property(rt_output ${APP_NAME} RUNTIME_OUTPUT_DIRECTORY)
  add_custom_command(TARGET ${APP_NAME} 
    POST_BUILD 
      COMMAND ${CMAKE_COMMAND} -E 
        copy_if_different 
          "${CMAKE_CURRENT_SOURCE_DIR}/frameworks/3rd/openssl/prebuilt/win32/libcrypto-1_1.dll"
          "${CMAKE_CURRENT_SOURCE_DIR}/frameworks/3rd/openssl/prebuilt/win32/libssl-1_1.dll"
          "${rt_output}/${CMAKE_CFG_INTDIR}"
        )
endif()
