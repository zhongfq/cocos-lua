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
    CONV = 'xluacv_$ACTION_bool',
}

REG_TYPE {
    NAME = 'char *',
    CONV = 'xluacv_$ACTION_string',
}

REG_TYPE {
    NAME = 'std::string',
    CONV = "xluacv_$ACTION_std_string",
}

REG_TYPE {
    NAME = 'float|double', 
    CONV = "xluacv_$ACTION_number",
}

REG_TYPE {
    NAME = 'int', 
    CONV = "xluacv_$ACTION_int"
}

REG_TYPE {
    NAME = 'unsigned int|size_t', 
    CONV = "xluacv_$ACTION_uint",
}