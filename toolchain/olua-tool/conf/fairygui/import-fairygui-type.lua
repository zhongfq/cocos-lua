local function make_luacls(cppname)
    cppname = string.gsub(cppname, '^fairygui::', 'fgui.')
    cppname = string.gsub(cppname, "[ *]*$", '')
    return cppname
end

local function make_auto_conv_func(cppname)
    cppname = string.gsub(cppname, '::', '_')
    cppname = string.gsub(cppname, '[ *]*$', '')
    return 'auto_luacv_$$_' .. cppname
end

local function make_manual_conv_func(cppname)
    cppname = string.gsub(cppname, '::', '_')
    cppname = string.gsub(cppname, '[ *]*$', '')
    return 'manual_luacv_$$_' .. cppname
end

REG_TYPE {
    TYPENAME = 'fairygui::EventTag',
    CONV_FUNC = 'manual_luacv_$$_fairygui_EventTag',
    INIT_VALUE = false,
}

REG_TYPE {
    TYPENAME = [[
    ]],
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = "olua_$$_uint",
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = [[
        fairygui::UIEventDispatcher *
        fairygui::EventContext *
    ]],
    CONV_FUNC = "olua_$$_cppobj",
    LUACLS = make_luacls,
}

REG_TYPE {
    TYPENAME = [[
    ]],
    CONV_FUNC = "olua_$$_obj",
    LUACLS = function (name)
        name = string.gsub(name, 'sp', 'sp.')
        name = string.gsub(name, '[ *]+', '')
        return name
    end,
}
