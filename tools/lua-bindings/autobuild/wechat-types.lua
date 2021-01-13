-- AUTO BUILD, DON'T MODIFY!

local olua = require "olua"
local typedef = olua.typedef

typedef {
    CPPCLS = 'cclua::plugin::WeChat::ShareType',
    LUACLS = 'cclua.plugin.WeChat.ShareType',
    DECLTYPE = "lua_Unsigned",
    CONV = 'olua_$$_uint',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'cclua::plugin::WeChat::ProgramType',
    LUACLS = 'cclua.plugin.WeChat.ProgramType',
    DECLTYPE = "lua_Unsigned",
    CONV = 'olua_$$_uint',
    NUM_VARS = nil,
}

typedef {
    CPPCLS = 'cclua::plugin::WeChat *',
    LUACLS = 'cclua.plugin.WeChat',
    DECLTYPE = nil,
    CONV = 'olua_$$_cppobj',
    NUM_VARS = nil,
}

