require "olua.olua-cls"

typedef {
    CPPCLS = 'void',
    CONV_FUNC = '<NONE>',
}

typedef {
    CPPCLS = [[
        void *
        GLvoid *
    ]],
    LUACLS = 'void *',
    CONV_FUNC = 'olua_$$_obj',
}

typedef {
    CPPCLS = 'bool',
    CONV_FUNC = 'olua_$$_bool',
    VALUE_TYPE = true,
}

typedef {
    CPPCLS = 'const char *',
    CONV_FUNC = 'olua_$$_string',
    VALUE_TYPE = true,
}

typedef {
    CPPCLS = [[
        unsigned char *
        const unsigned char *
        const GLchar *
    ]],
    DECL_TYPE = 'const char *',
    CONV_FUNC = 'olua_$$_string',
    VALUE_TYPE = true,
}

typedef {
    CPPCLS = 'std::string',
    INIT_VALUE = false,
    CONV_FUNC = 'olua_$$_std_string',
    VALUE_TYPE = true,
}

typedef {
    CPPCLS = 'std::function',
    INIT_VALUE = 'nullptr',
    CONV_FUNC = 'olua_$$_std_function',
    VALUE_TYPE = true,
}

typedef {
    CPPCLS = 'std::set',
    INIT_VALUE = false,
    IS_ARRAY = true,
    CONV_FUNC = 'olua_$$_std_set',
}

typedef {
    CPPCLS = 'std::vector',
    INIT_VALUE = false,
    IS_ARRAY = true,
    CONV_FUNC = 'olua_$$_std_vector',
}

typedef {
    CPPCLS = [[
        float
        double
        GLfloat
    ]],
    DECL_TYPE = 'lua_Number',
    CONV_FUNC = 'olua_$$_number',
    VALUE_TYPE = true,
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
        std::int32_t
        unsigned short
    ]],
    DECL_TYPE = 'lua_Integer',
    CONV_FUNC = 'olua_$$_int',
    VALUE_TYPE = true,
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
        uint32_t
        uint64_t
        unsigned char
        unsigned int
        unsigned short
    ]],
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
    VALUE_TYPE = true,
}
