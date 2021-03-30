local typedef = (...).typedef

typedef {
    CPPCLS = 'cocos2d::Data',
    CONV = 'manual_olua_$$_cocos2d_Data',
}

typedef {
    CPPCLS = 'cocos2d::Rect',
    CONV = 'manual_olua_$$_cocos2d_Rect',
    NUM_VARS = 4,
}

typedef {
    CPPCLS = 'cocos2d::Mat4',
    CONV = 'manual_olua_$$_cocos2d_Mat4',
}

typedef {
    CPPCLS = 'cocos2d::Vector',
    CONV = 'manual_olua_$$_cocos2d_Vector',
}

typedef {
    CPPCLS = 'cocos2d::EventListener::ListenerID',
    DECLTYPE = 'std::string',
    CONV = 'olua_$$_std_string',
}

typedef {
    CPPCLS = 'cocos2d::Color3B',
    CONV = 'manual_olua_$$_cocos2d_Color3B',
}

typedef {
    CPPCLS = 'cocos2d::Color4B',
    CONV = 'manual_olua_$$_cocos2d_Color4B',
}

typedef {
    CPPCLS = 'cocos2d::Color4F',
    CONV = 'manual_olua_$$_cocos2d_Color4F',
}

typedef {
    CPPCLS = 'cocos2d::Value',
    CONV = 'manual_olua_$$_cocos2d_Value',
}

typedef {
    CPPCLS = 'cocos2d::ValueMap',
    CONV = 'manual_olua_$$_cocos2d_ValueMap',
}

typedef {
    CPPCLS = 'cocos2d::ValueMapIntKey',
    CONV = 'manual_olua_$$_cocos2d_ValueMapIntKey',
}

typedef {
    CPPCLS = 'cocos2d::ValueVector',
    CONV = 'manual_olua_$$_cocos2d_ValueVector',
}

typedef {
    CPPCLS = "cocos2d::Map",
    CONV = 'olua_$$_cocos2d_Map',
    PUSH_VALUE = [=[
        function (arg, name)
            local SUBTYPES = arg.TYPE.SUBTYPES
            local key = {TYPE = SUBTYPES[1], DECLTYPE = SUBTYPES[1].DECLTYPE, ATTR = {}}
            local value = {TYPE = SUBTYPES[2], DECLTYPE = SUBTYPES[2].DECLTYPE, ATTR = {}}
            local OUT = {PUSH_ARGS = olua.newarray()}
            olua.gen_push_exp(key, "entry.first", OUT)
            olua.gen_push_exp(value, "entry.second", OUT)
            local str = olua.format([[
                lua_createtable(L, 0, (int)${name}.size());
                for (auto &entry : ${name}) {
                    ${OUT.PUSH_ARGS}
                    lua_rawset(L, -3);
                }
            ]])
            return str
        end
    ]=],
    CHECK_VALUE = [=[
        function (arg, name, i)
            local SUBTYPES = arg.TYPE.SUBTYPES
            local key = {TYPE = SUBTYPES[1], DECLTYPE = SUBTYPES[1].DECLTYPE, ATTR = {}}
            local value = {TYPE = SUBTYPES[2], DECLTYPE = SUBTYPES[2].DECLTYPE, ATTR = {}}
            local OUT = {CHECK_ARGS = olua.newarray(), DECL_ARGS = olua.newarray()}
            olua.gen_decl_exp(key, "key", OUT)
            olua.gen_decl_exp(value, "value", OUT)
            olua.gen_check_exp(key, 'key', -2, OUT)
            olua.gen_check_exp(value, 'value', -1, OUT)
            local str = olua.format([[
                lua_pushnil(L);
                while (lua_next(L, ${i})) {
                    ${OUT.DECL_ARGS}
                    ${OUT.CHECK_ARGS}
                    ${name}.insert(key, value);
                    lua_pop(L, 1);
                }
            ]])
            return str
        end
    ]=],
}