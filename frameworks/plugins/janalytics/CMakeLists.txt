cmake_minimum_required(VERSION 3.16)

set(LIBNAME plugin_janalytics)

set(SRC
  janalytics.cpp
  janalytics.h
  lua_janalytics.cpp
  lua_janalytics.h
)

if(IOS)
  list(APPEND SRC
    ios/JANALYTICSEventObject.h
    ios/JANALYTICSService.h
    janalytics.mm
  )
endif()

add_library(${LIBNAME} ${SRC})
target_include_directories(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(${LIBNAME} cclua)

if(APPLE)
  set_xcode_property(${LIBNAME} CLANG_ENABLE_OBJC_ARC "YES")
endif()

if(IOS)
  target_link_libraries(${LIBNAME} ${CMAKE_CURRENT_SOURCE_DIR}/ios/janalytics-ios-2.1.2.a)
  if(NOT TARGET jcore)
    add_subdirectory(../jcore ${CMAKE_BINARY_DIR}/frameworks/plugins/jcore)
  endif()
  target_link_libraries(${LIBNAME} jcore)
endif()

if(ANDROID OR IOS)
  target_compile_definitions(${LIBNAME} PUBLIC CCLUA_BUILD_JANALYTICS)
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})
