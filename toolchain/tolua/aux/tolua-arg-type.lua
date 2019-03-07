require "aux.tolua-cls"

REG_TYPE {
    TYPENAME = 'void',
    CONV_FUNC = "<NONE>",
}

REG_TYPE {
    TYPENAME = 'void *',
    CONV_FUNC = 'xluacv_$$_obj',
}

REG_TYPE {
    TYPENAME = 'bool',
    CONV_FUNC = 'tolua_$$_bool',
}

REG_TYPE {
    TYPENAME = 'const char *',
    CONV_FUNC = 'tolua_$$_string',
}

REG_TYPE {
    TYPENAME = 'const unsigned char *|const GLchar *',
    DECL_TYPE = 'const char *',
    CONV_FUNC = 'tolua_$$_string',
}

REG_TYPE {
    TYPENAME = 'std::string',
    INIT_VALUE = false,
    CONV_FUNC = "tolua_$$_std_string",
}

REG_TYPE {
    TYPENAME = 'float|double|GLfloat',
    DECL_TYPE = 'lua_Number',
    CONV_FUNC = "tolua_$$_number",
}

REG_TYPE {
    TYPENAME = 'int|ssize_t|GLint',
    DECL_TYPE = 'lua_Integer',
    CONV_FUNC = "tolua_$$_int"
}

REG_TYPE {
    TYPENAME = 'unsigned int|size_t|GLuint|GLenum',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = "tolua_$$_uint",
}
