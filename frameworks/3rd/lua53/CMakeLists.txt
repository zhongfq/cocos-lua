cmake_minimum_required(VERSION 3.16)

set(LUA_HEADER
    lapi.h
    lauxlib.h
    lcode.h
    lctype.h
    ldebug.h
    ldo.h
    lfunc.h
    lgc.h
    llex.h
    llimits.h
    lmem.h
    lobject.h
    lopcodes.h
    lparser.h
    lprefix.h
    lstate.h
    lstring.h
    ltable.h
    ltm.h
    lua.h
    luaconf.h
    lualib.h
    lundump.h
    lvm.h
    lzio.h
)

set(LUA_SRC
    lapi.c
    lauxlib.c
    lbaselib.c
    lbitlib.c
    lcode.c
    lcorolib.c
    lctype.c
    ldblib.c
    ldebug.c
    ldump.c
    lfunc.c
    lgc.c
    linit.c
    liolib.c
    llex.c
    lmathlib.c
    lmem.c
    loadlib.c
    lobject.c
    lopcodes.c
    loslib.c
    lparser.c
    lstate.c
    lstring.c
    lstrlib.c
    ltable.c
    ltablib.c
    ltm.c
    lundump.c
    lutf8lib.c
    lvm.c
    lzio.c
)

list(APPEND LUA_SRC ${LUA_HEADER})

add_library(lua ${LUA_SRC})

target_include_directories(lua
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_compile_definitions(lua PUBLIC $<$<CONFIG:Debug>:LUA_DEBUG>)

if(WINDOWS)
    target_compile_definitions(lua PRIVATE LUA_BUILD_AS_DLL)
elseif(MACOSX)
    target_compile_definitions(lua PUBLIC LUA_USE_MACOSX)
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${LUA_SRC})