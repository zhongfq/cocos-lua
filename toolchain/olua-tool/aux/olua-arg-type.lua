require "aux.olua-cls"

REG_TYPE {
    TYPENAME = 'void',
    CONV_FUNC = '<NONE>',
}

REG_TYPE {
    TYPENAME = [[
        void *
        GLvoid *
    ]],
    LUACLS = 'void *',
    CONV_FUNC = 'olua_$$_obj',
}

REG_TYPE {
    TYPENAME = 'bool',
    CONV_FUNC = 'olua_$$_bool',
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = 'const char *',
    CONV_FUNC = 'olua_$$_string',
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = [[
        const unsigned char *
        const GLchar *
    ]],
    DECL_TYPE = 'const char *',
    CONV_FUNC = 'olua_$$_string',
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = 'std::string',
    INIT_VALUE = false,
    CONV_FUNC = 'olua_$$_std_string',
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = 'std::function',
    INIT_VALUE = 'nullptr',
    CONV_FUNC = 'olua_$$_std_function',
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = 'std::set',
    INIT_VALUE = false,
    CONV_FUNC = 'olua_$$_std_set',
}

REG_TYPE {
    TYPENAME = 'std::vector',
    INIT_VALUE = false,
    IS_ARRAY = true,
    CONV_FUNC = 'olua_$$_std_vector',
}

REG_TYPE {
    TYPENAME = [[
        float
        double
        GLfloat
    ]],
    DECL_TYPE = 'lua_Number',
    CONV_FUNC = 'olua_$$_number',
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = [[
        char
        GLint
        GLshort
        GLsizei
        int
        long
        short
        ssize_t
        std::int32_t
        unsigned short
    ]],
    DECL_TYPE = 'lua_Integer',
    CONV_FUNC = 'olua_$$_int',
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = [[
        GLboolean
        GLenum
        GLubyte
        GLuint
        size_t
        std::size_t
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
