local olua = require "typecls"

olua.typedef {
    CPPCLS = "cocos2d::Map",
    CONV = 'olua_$$_cocos2d_Map',
    PUSH_VALUE =  function (arg, name)
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
    end,
    CHECK_VALUE = function (arg, name, i)
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
    end,
}