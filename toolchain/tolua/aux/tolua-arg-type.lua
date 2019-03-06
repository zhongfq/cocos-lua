require "aux.tolua-cls"

REG_TYPE {
    TYPENAME = 'void',
    CONV_FUNC = "<NONE>",
}

REG_TYPE {
    TYPENAME = 'void *',
    CONV_FUNC = 'xluacv_$ACTION_obj',
}

REG_TYPE {
    TYPENAME = 'bool',
    CONV_FUNC = 'tolua_$ACTION_bool',
}

REG_TYPE {
    TYPENAME = 'const char *',
    CONV_FUNC = 'tolua_$ACTION_string',
}

REG_TYPE {
    TYPENAME = 'const unsigned char *|const GLchar *',
    DECL_TYPE = 'const char *',
    CONV_FUNC = 'tolua_$ACTION_string',
}

REG_TYPE {
    TYPENAME = 'std::string',
    INIT_VALUE = false,
    CONV_FUNC = "tolua_$ACTION_std_string",
}

REG_TYPE {
    TYPENAME = 'float|double|GLfloat',
    DECL_TYPE = 'lua_Number',
    CONV_FUNC = "tolua_$ACTION_number",
}

REG_TYPE {
    TYPENAME = 'int|ssize_t|GLint',
    DECL_TYPE = 'lua_Integer',
    CONV_FUNC = "tolua_$ACTION_int"
}

REG_TYPE {
    TYPENAME = 'unsigned int|size_t|GLuint',
    DECL_TYPE = 'lua_Unsigned',
    CONV_FUNC = "tolua_$ACTION_uint",
}
