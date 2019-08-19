-- AUTO BUILD, DON'T MODIFY!

local olua = require "olua"
local typedef = olua.typedef

olua.nowarning(typedef)

typedef {
    CPPCLS = 'xgame::Permission',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'kernel.Permission',
}

typedef {
    CPPCLS = 'xgame::PermissionStatus',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
    LUACLS = 'kernel.PermissionStatus',
}

typedef {
    CPPCLS = 'xgame::SceneNoCamera *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'kernel.SceneNoCamera',
}

typedef {
    CPPCLS = 'xgame::downloader *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'kernel.downloader',
}

typedef {
    CPPCLS = 'xgame::filesystem *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'kernel.filesystem',
}

typedef {
    CPPCLS = 'xgame::preferences *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'kernel.preferences',
}

typedef {
    CPPCLS = 'xgame::runtime *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'kernel.runtime',
}

typedef {
    CPPCLS = 'xgame::timer *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'kernel.timer',
}

typedef {
    CPPCLS = 'xgame::window *',
    CONV = 'olua_$$_cppobj',
    LUACLS = 'kernel.window',
}

