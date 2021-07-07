-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/apple-types.lua"

NAME = "apple"
PATH = "../../frameworks/plugins/apple"
HEADERS = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/xlua.h"
    #include "apple/Apple.h"
]]
CHUNK = nil


typeconf 'cclua::plugin::AppleAuth'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require([[cclua::runtime::registerFeature("apple.auth.ios", true);]])
    .ifdef('*', '#ifdef CCLUA_BUILD_APPLE_AUTH')
    .func(nil, 'static bool canMakeAuth()')
    .callback {
        FUNCS =  {
            'static void auth(@local const std::function<void (const cocos2d::ValueMap &)> &callback)'
        },
        TAG_MAKER = 'auth',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
