-- AUTO BUILD, DON'T MODIFY!

local olua = require "olua"
local typedef = olua.typedef

typedef {
    CONV = 'manual_olua_$$_xgame_window_Bounds',
    CPPCLS = 'xgame::window::Bounds',
}

typedef {
    CPPCLS = 'xgame::downloader::FileTask',
    LUACLS = nil,
    DECLTYPE = nil,
    CONV = 'auto_olua_$$_xgame_downloader_FileTask',
    NUM_VARS = 4,
}

typedef {
    CPPCLS = 'xgame::SceneNoCamera *',
    LUACLS = 'kernel.SceneNoCamera',
    DECLTYPE = nil,
    CONV = 'olua_$$_cppobj',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'xgame::Permission',
    LUACLS = 'kernel.Permission',
    DECLTYPE = "lua_Unsigned",
    CONV = 'olua_$$_uint',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'xgame::PermissionStatus',
    LUACLS = 'kernel.PermissionStatus',
    DECLTYPE = "lua_Unsigned",
    CONV = 'olua_$$_uint',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'xgame::runtime *',
    LUACLS = 'kernel.runtime',
    DECLTYPE = nil,
    CONV = 'olua_$$_cppobj',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'xgame::filesystem *',
    LUACLS = 'kernel.filesystem',
    DECLTYPE = nil,
    CONV = 'olua_$$_cppobj',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'xgame::preferences *',
    LUACLS = 'kernel.preferences',
    DECLTYPE = nil,
    CONV = 'olua_$$_cppobj',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'xgame::timer *',
    LUACLS = 'kernel.timer',
    DECLTYPE = nil,
    CONV = 'olua_$$_cppobj',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'xgame::window *',
    LUACLS = 'kernel.window',
    DECLTYPE = nil,
    CONV = 'olua_$$_cppobj',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'xgame::downloader::FileState',
    LUACLS = 'kernel.downloader.FileState',
    DECLTYPE = "lua_Unsigned",
    CONV = 'olua_$$_uint',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'xgame::downloader *',
    LUACLS = 'kernel.downloader',
    DECLTYPE = nil,
    CONV = 'olua_$$_cppobj',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'xgame::MaskLayout *',
    LUACLS = 'kernel.MaskLayout',
    DECLTYPE = nil,
    CONV = 'olua_$$_cppobj',
    NUM_VARS = nil,
}

