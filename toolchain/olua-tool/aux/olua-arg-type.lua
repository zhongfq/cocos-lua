require "aux.olua-cls"

REG_TYPE {
    TYPENAME = 'void',
    CONV_FUNC = '<NONE>',
}

REG_TYPE {
    TYPENAME = 'void *',
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
    TYPENAME = 'const unsigned char *|const GLchar *',
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
}

REG_TYPE {
    TYPENAME = 'std::set',
    INIT_VALUE = false,
    CONV_FUNC = 'olua_$$_std_set',
}

REG_TYPE {
    TYPENAME = 'std::vector',
    INIT_VALUE = false,
    CONV_FUNC = 'olua_$$_std_vector',
}

REG_TYPE {
    TYPENAME = 'float|double|GLfloat',
    DECL_TYPE = 'lua_Number',
    CONV_FUNC = 'olua_$$_number',
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = table.concat({
        'int',
        'ssize_t',
        'GLint',
        'GLshort',
    }, '|'),
    DECL_TYPE = 'lua_Integer',
    CONV_FUNC = 'olua_$$_int',
    VALUE_TYPE = true,
}

REG_TYPE {
    TYPENAME = table.concat({
        'unsigned int',
        'size_t',
        'GLuint',
        'GLenum',
        'GLubyte',
    }, '|'),
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = 'olua_$$_uint',
}
