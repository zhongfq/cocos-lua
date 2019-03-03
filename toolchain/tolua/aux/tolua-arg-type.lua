require "aux.tolua-cls"

REG_TYPE {
    NAME = 'void',
    CONV = "<NONE>",
}

REG_TYPE {
    NAME = 'void *',
    CONV = '<TODO>',
}

REG_TYPE {
    NAME = 'bool',
    CONV = 'tolua_$ACTION_bool',
}

REG_TYPE {
    NAME = 'const char *',
    CONV = 'tolua_$ACTION_string',
}

REG_TYPE {
    NAME = 'std::string',
    INIT = false,
    CONV = "tolua_$ACTION_std_string",
}

REG_TYPE {
    NAME = 'float|double',
    DECL = 'lua_Number',
    CONV = "tolua_$ACTION_number",
}

REG_TYPE {
    NAME = 'int',
    DECL = 'lua_Integer',
    CONV = "tolua_$ACTION_int"
}

REG_TYPE {
    NAME = 'unsigned int|size_t',
    DECL = 'lua_Unsigned',
    CONV = "tolua_$ACTION_uint",
}