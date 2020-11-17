set(XGAME_HEADER
    src/xgame/AssetsBundle.h
    src/xgame/config.h
    src/xgame/downloader.h
    src/xgame/FileFinder.h
    src/xgame/filesystem-private.h
    src/xgame/filesystem.h
    src/xgame/preferences.h
    src/xgame/RootScene.h
    src/xgame/runtime-private.h
    src/xgame/runtime.h
    src/xgame/Socket.h
    src/xgame/timer.h
    src/xgame/window.h
    src/xgame/xlua.h
    src/xgame/XMLHttpRequest.h
)

set(XGAME_SRC
    src/xgame/AssetsBundle.cpp
    src/xgame/downloader.cpp
    src/xgame/FileFinder.cpp
    src/xgame/filesystem-private.cpp
    src/xgame/filesystem.cpp
    src/xgame/preferences.cpp
    src/xgame/RootScene.cpp
    src/xgame/runtime-private.cpp
    src/xgame/runtime.cpp
    src/xgame/Socket.cpp
    src/xgame/timer.cpp
    src/xgame/window.cpp
    src/xgame/xlua.cpp
    src/xgame/XMLHttpRequest.cpp
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
            src/xgame/filesystem-private-ios-mac.mm
            src/xgame/runtime-private-ios-mac.mm
        )
    elseif(MACOSX)
        list(APPEND XGAME_SRC
            src/xgame/filesystem-private-ios-mac.mm
            src/xgame/runtime-private-ios-mac.mm
        )
    endif()
endif()
