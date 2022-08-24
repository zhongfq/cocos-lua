set(BUGLY_HEADER
    src/bugly/CrashReport.h
    src/bugly/lua_bugly.h
)

set(BUGLY_SRC
    src/bugly/CrashReport.cpp
    src/bugly/lua_bugly.cpp
)

if(APPLE)
    list(APPEND BUGLY_SRC
        src/bugly/CrashReport.mm
    )
endif()