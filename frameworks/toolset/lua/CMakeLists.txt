cmake_minimum_required(VERSION 3.10)

project(lua)

set(source ${CMAKE_CURRENT_SOURCE_DIR}/../../3rd/lua)

set(LUASRC
    ${source}/lapi.c
    ${source}/lapi.h   
    ${source}/lauxlib.c
    ${source}/lauxlib.h
    ${source}/lbaselib.c
    ${source}/lcode.c
    ${source}/lcode.h  
    ${source}/lcorolib.c
    ${source}/lctype.c
    ${source}/lctype.h 
    ${source}/ldblib.c
    ${source}/ldebug.c
    ${source}/ldebug.h 
    ${source}/ldo.c
    ${source}/ldo.h    
    ${source}/ldump.c
    ${source}/lfunc.c
    ${source}/lfunc.h  
    ${source}/lgc.c
    ${source}/lgc.h    
    ${source}/linit.c
    ${source}/liolib.c
    ${source}/llex.c
    ${source}/llex.h   
    ${source}/llimits.h
    ${source}/lmathlib.c
    ${source}/lmem.c
    ${source}/lmem.h    
    ${source}/loadlib.c
    ${source}/lobject.c
    ${source}/lobject.h 
    ${source}/lopcodes.c
    ${source}/lopcodes.h
    ${source}/loslib.c
    ${source}/lparser.c
    ${source}/lparser.h 
    ${source}/lprefix.h 
    ${source}/lstate.c
    ${source}/lstate.h  
    ${source}/lstring.c
    ${source}/lstring.h 
    ${source}/lstrlib.c
    ${source}/ltable.c
    ${source}/ltable.h
    ${source}/ltablib.c
    ${source}/ltm.c
    ${source}/ltm.h
    ${source}/lua.h
    ${source}/luaconf.h
    ${source}/lualib.h
    ${source}/lundump.c
    ${source}/lundump.h
    ${source}/lutf8lib.c
    ${source}/lvm.c
    ${source}/lvm.h
    ${source}/lzio.c
    ${source}/lzio.h
)

if(WIN32)
    add_library(liblua SHARED ${LUASRC})
    target_compile_definitions(liblua PRIVATE LUA_BUILD_AS_DLL)
else()
    add_library(liblua STATIC ${LUASRC})
    target_link_libraries(liblua PUBLIC readline)
    if (NOT APPLE)
        target_link_libraries(liblua PUBLIC m dl -Wl,-E)
        target_compile_definitions(liblua PUBLIC LUA_USE_LINUX)
    else()
        target_compile_definitions(liblua PUBLIC LUA_USE_MACOSX)
    endif()
endif()

set_target_properties(liblua PROPERTIES OUTPUT_NAME lua)
target_include_directories(liblua PUBLIC ${source})

add_executable(lua ${source}/lua.c)
target_link_libraries(lua liblua)

if(WIN32)
    add_executable(luac ${LUASRC} ${source}/luac.c)
else()
    add_executable(luac ${source}/luac.c)
    target_link_libraries(luac liblua)
endif()