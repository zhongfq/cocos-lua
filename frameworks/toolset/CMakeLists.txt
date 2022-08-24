cmake_minimum_required(VERSION 3.10)

project(toolset)

set(LUA "lua54" CACHE STRING "lua version to use, default is lua54")

if(WIN32)
    set(OS "windows")
elseif(APPLE)
    set(OS "macos")
else()
    set(OS "linux")
endif()

if(LUA STREQUAL "lua54")
    add_subdirectory(lua)
    get_filename_component(LUA_INCLUDE "../libxgame/src/lua"
        REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
elseif(LUA STREQUAL "lua53")
    add_subdirectory(lua53)
    get_filename_component(LUA_INCLUDE "../libxgame/src/lua53"
        REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
else()
    message(FATAL_ERROR "only support lua53 or lua54")
endif()

add_subdirectory(cjson)
add_subdirectory(lfs)
add_subdirectory(xxtea)
add_subdirectory(md5)

# install lua luac and lualib
get_filename_component(OUTPUT_DIR "../../tools/lua/${LUA}/${OS}"
    REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
install(TARGETS lua luac DESTINATION ${OUTPUT_DIR})
if(WIN32)
    install(TARGETS liblua DESTINATION ${OUTPUT_DIR})
endif()
install(TARGETS lfs DESTINATION ${OUTPUT_DIR})
install(TARGETS cjson DESTINATION ${OUTPUT_DIR})
install(TARGETS xxtea DESTINATION ${OUTPUT_DIR})
install(TARGETS md5 DESTINATION ${OUTPUT_DIR})