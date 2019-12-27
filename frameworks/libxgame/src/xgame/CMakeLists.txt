set(XGAME_HEADER
    src/xgame/AssetsBundle.h
    src/xgame/xdef.h
    src/xgame/xdownloader.h
    src/xgame/xfilefinder.h
    src/xgame/xfilesystem-private.h
    src/xgame/xfilesystem.h
    src/xgame/xlua.h
    src/xgame/XMLHttpRequest.h
    src/xgame/xpreferences.h
    src/xgame/xrootscene.h
    src/xgame/xruntime-private.h
    src/xgame/xruntime.h
    src/xgame/xsocket.h
    src/xgame/xtimer.h
)

set(XGAME_SRC
    src/xgame/AssetsBundle.cpp
    src/xgame/xdownloader.cpp
    src/xgame/xfilefinder.cpp
    src/xgame/xfilesystem-private.cpp
    src/xgame/xfilesystem.cpp
    src/xgame/xlua.cpp
    src/xgame/XMLHttpRequest.cpp
    src/xgame/xpreferences.cpp
    src/xgame/xrootscene.cpp
    src/xgame/xruntime-private.cpp
    src/xgame/xruntime.cpp
    src/xgame/xsocket.cpp
    src/xgame/xtimer.cpp
)

if(APPLE)
    if(IOS)
        list(APPEND XGAME_HEADER
            src/xgame/AppContext-ios.h
            src/xgame/AppRootViewController-ios.h
            src/xgame/PluginConnector.h
            src/xgame/Reachability.h
        )
        list(APPEND XGAME_SRC
            src/xgame/AppContext-ios.mm
            src/xgame/AppRootViewController-ios.mm
            src/xgame/PluginConnector.mm
            src/xgame/Reachability.m
            src/xgame/xfilesystem-private-ios-mac.mm
            src/xgame/xruntime-private-ios-mac.mm
        )
    elseif(MACOSX)
        list(APPEND XGAME_SRC
            src/xgame/xfilesystem-private-ios-mac.mm
            src/xgame/xruntime-private-ios-mac.mm
        )
    endif()
endif()
