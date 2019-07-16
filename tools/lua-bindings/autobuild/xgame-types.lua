local olua = require "olua"
local typedef = olua.typedef

olua.nowarning(typedef)

typedef {
    CPPCLS = 'xgame::SceneNoCamera *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'kernel.SceneNoCamera',
}

typedef {
    CPPCLS = 'xgame::downloader *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'kernel.downloader',
}

typedef {
    CPPCLS = 'xgame::filesystem *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'kernel.filesystem',
}

typedef {
    CPPCLS = 'xgame::preferences *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'kernel.preferences',
}

typedef {
    CPPCLS = 'xgame::runtime *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'kernel.runtime',
}

typedef {
    CPPCLS = 'xgame::timer *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'kernel.timer',
}

typedef {
    CPPCLS = 'xgame::window *',
    CONV_FUNC = 'olua_$$_cppobj',
    LUACLS = 'kernel.window',
}

