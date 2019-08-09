local olua = require "olua.olua-typecls"
local typedef = olua.typedef

typedef {
    CPPCLS = 'void',
    CONV = '<NONE>',
}

typedef {
    CPPCLS = [[
        void *
        GLvoid *
    ]],
    LUACLS = 'void *',
    CONV = 'olua_$$_obj',
}

typedef {
    CPPCLS = 'bool',
    CONV = 'olua_$$_bool',
}

typedef {
    CPPCLS = [[
        char *
        const char *
        unsigned char *
        const unsigned char *
        const GLchar *
    ]],
    DECLTYPE = 'const char *',
    CONV = 'olua_$$_string',
}

typedef {
    CPPCLS = 'std::string',
    CONV = 'olua_$$_std_string',
}

typedef {
    CPPCLS = 'std::function',
    CONV = 'olua_$$_std_function',
}

typedef {
    CPPCLS = [[
        std::unordered_map
        std::map
    ]],
    CONV = 'olua_$$_std_unordered_map',
    PUSH_VALUE = function (arg, name)
        local SUBTYPES = arg.TYPE.SUBTYPES
        local key = {TYPE = SUBTYPES[1], DECLTYPE = SUBTYPES[1].DECLTYPE, ATTR = {}}
        local value = {TYPE = SUBTYPES[2], DECLTYPE = SUBTYPES[2].DECLTYPE, ATTR = {}}
        local OUT = {PUSH_ARGS = olua.newarray()}
        olua.genpushexp(key, "entry.first", OUT)
        olua.genpushexp(value, "entry.second", OUT)
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
        olua.gendeclexp(key, "key", OUT)
        olua.gendeclexp(value, "value", OUT)
        olua.gencheckexp(key, 'key', -2, OUT)
        olua.gencheckexp(value, 'value', -1, OUT)
        local str = olua.format([[
            lua_pushnil(L);
            while (lua_next(L, ${i})) {
                ${OUT.DECL_ARGS}
                ${OUT.CHECK_ARGS}
                ${name}.insert(std::make_pair(key, value));
                lua_pop(L, 1);
            }
        ]])
        return str
    end,
}

typedef {
    CPPCLS = 'std::set',
    CONV = 'olua_$$_std_set',
    PUSH_VALUE = [[
        int ${ARG_NAME}_i = 1;
        lua_createtable(L, (int)${ARG_NAME}.size(), 0);
        for (auto it = ${ARG_NAME}.begin(); it != ${ARG_NAME}.end(); ++it) {
            ${SUBTYPE_PUSH_FUNC}(L, ${SUBTYPE_CAST}(*it));
            lua_rawseti(L, -2, ${ARG_NAME}_i++);
        }
    ]],
    CHECK_VALUE = [[
        size_t ${ARG_NAME}_total = lua_rawlen(L, ${ARGN});
        for (int i = 1; i <= ${ARG_NAME}_total; i++) {
            ${SUBTYPE.DECLTYPE} obj;
            lua_rawgeti(L, ${ARGN}, i);
            ${SUBTYPE_CHECK_FUNC}(L, -1, &obj);
            ${ARG_NAME}.insert(${SUBTYPE_CAST}obj);
            lua_pop(L, 1);
        }
    ]],
}

typedef {
    CPPCLS = 'std::vector',
    CONV = 'olua_$$_std_vector',
    PUSH_VALUE = [[
        int ${ARG_NAME}_size = (int)${ARG_NAME}.size();
        lua_createtable(L, ${ARG_NAME}_size, 0);
        for (int i = 0; i < ${ARG_NAME}_size; i++) {
            ${SUBTYPE_PUSH_FUNC}(L, ${SUBTYPE_CAST}((${TYPE_CAST})${ARG_NAME})[i]);
            lua_rawseti(L, -2, i + 1);
        }
    ]],
    CHECK_VALUE = [[
        size_t ${ARG_NAME}_total = lua_rawlen(L, ${ARGN});
        ${ARG_NAME}.reserve(${ARG_NAME}_total);
        for (int i = 1; i <= ${ARG_NAME}_total; i++) {
            ${SUBTYPE.DECLTYPE} obj;
            lua_rawgeti(L, ${ARGN}, i);
            ${SUBTYPE_CHECK_FUNC}(L, -1, &obj);
            ${ARG_NAME}.push_back(${SUBTYPE_CAST}obj);
            lua_pop(L, 1);
        }
    ]],
}

typedef {
    CPPCLS = [[
        float
        double
        GLfloat
    ]],
    DECLTYPE = 'lua_Number',
    CONV = 'olua_$$_number',
}

typedef {
    CPPCLS = [[
        char
        GLint
        GLshort
        GLsizei
        int
        long
        short
        ssize_t
        int8_t
        int16_t
        int32_t
        int64_t
        std::int32_t
        unsigned short
    ]],
    DECLTYPE = 'lua_Integer',
    CONV = 'olua_$$_int',
}

typedef {
    CPPCLS = [[
        GLboolean
        GLenum
        GLubyte
        GLuint
        size_t
        std::size_t
        std::string::size_type
        uint8_t
        uint16_t
        uint32_t
        uint64_t
        unsigned char
        unsigned int
        unsigned short
    ]],
    DECLTYPE = 'lua_Unsigned',
    CONV = 'olua_$$_uint',
}
