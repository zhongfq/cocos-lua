local olua = require "olua"
local typedef = olua.typedef

typedef {
    CPPCLS = 'android_LogPriority',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::TMXTileFlags',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::Vect',
    DECLTYPE = 'cocos2d::Vect',
    CONV = 'auto_olua_$$_cocos2d_Vec2',
}

typedef {
    CPPCLS = 'cocos2d::ui::CheckBoxEventType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::ui::ListViewEventType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::ui::PageViewEventType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::ui::ScrollviewEventType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::ui::SliderEventType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::ui::TextFiledEventType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'cocos2d::ui::TouchEventType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'jobjectRefType',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'khronos_boolean_enum_t',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'log_id_t',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}

typedef {
    CPPCLS = 'olua_tag_mode',
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}