set(LUA_BINDINGS_HEADER
    src/lua-bindings/lua_bindings.h
    src/lua-bindings/lua_cocos2d_3d.h
    src/lua-bindings/lua_cocos2d_action.h
    src/lua-bindings/lua_cocos2d_backend.h
    src/lua-bindings/lua_cocos2d_physics.h
    src/lua-bindings/lua_cocos2d_ui.h
    src/lua-bindings/lua_cocos2d.h
    src/lua-bindings/lua_conv_manual.h
    src/lua-bindings/lua_conv.h
    src/lua-bindings/lua_crypto.h
    src/lua-bindings/lua_iap.h
    src/lua-bindings/lua_javabridge.h
    src/lua-bindings/lua_keychain.h
    src/lua-bindings/lua_ocbridge.h
    src/lua-bindings/lua_photo.h
    src/lua-bindings/lua_recorder.h
    src/lua-bindings/lua_socket.h
    src/lua-bindings/lua_xgame.h
    src/lua-bindings/lua_xml_http_request.h
    src/lua-bindings/LuaCocosAdapter.h
)

set(LUA_BINDINGS_SRC
    src/lua-bindings/lua_bindings.cpp
    src/lua-bindings/lua_cocos2d_3d.cpp
    src/lua-bindings/lua_cocos2d_action.cpp
    src/lua-bindings/lua_cocos2d_backend.cpp
    src/lua-bindings/lua_cocos2d_physics.cpp
    src/lua-bindings/lua_cocos2d_ui.cpp
    src/lua-bindings/lua_cocos2d.cpp
    src/lua-bindings/lua_conv_manual.cpp
    src/lua-bindings/lua_conv.cpp
    src/lua-bindings/lua_crypto.cpp
    src/lua-bindings/lua_javabridge.cpp
    src/lua-bindings/lua_socket.cpp
    src/lua-bindings/lua_xgame.cpp
    src/lua-bindings/lua_xml_http_request.cpp
    src/lua-bindings/LuaCocosAdapter.cpp
)

if(CCLUA_BUILD_SPINE)
    list(APPEND LUA_BINDINGS_HEADER src/lua-bindings/lua_spine.h)
    list(APPEND LUA_BINDINGS_SRC src/lua-bindings/lua_spine.cpp)
endif()

if(CCLUA_BUILD_DRAGONBONES)
    list(APPEND LUA_BINDINGS_HEADER src/lua-bindings/lua_dragonbones.h)
    list(APPEND LUA_BINDINGS_SRC src/lua-bindings/lua_dragonbones.cpp)
endif()

if(CCLUA_BUILD_FAIRYGUI)
    list(APPEND LUA_BINDINGS_HEADER src/lua-bindings/lua_fairygui.h)
    list(APPEND LUA_BINDINGS_SRC src/lua-bindings/lua_fairygui.cpp)
endif()

if(APPLE)
    list(APPEND LUA_BINDINGS_SRC
        src/lua-bindings/lua_iap.mm
        src/lua-bindings/lua_keychain.mm
        src/lua-bindings/lua_ocbridge.mm
        src/lua-bindings/lua_photo.mm
        src/lua-bindings/lua_recorder.mm
    )
endif()