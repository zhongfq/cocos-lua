require "aux.tolua-cls"

register_type {
    NAME = 'void',
    CONV = "<NONE>",
}

register_type {
    NAME = 'void *',
    CONV = '<TODO>',
}

register_type {
    NAME = 'bool',
    CONV = 'xluacv_$ACTION_bool',
}

register_type {
    NAME = 'char *',
    CONV = 'xluacv_$ACTION_string',
}

register_type {
    NAME = 'std::string',
    CONV = "xluacv_$ACTION_std_string",
}

register_type {
    NAME = 'float', 
    CONV = "xluacv_$ACTION_number",
}

register_type {
    NAME = 'double',
    CONV = "xluacv_$ACTION_number"
}

register_type {
    NAME = 'int', 
    CONV = "xluacv_$ACTION_int"
}

register_type {
    NAME = 'unsigned int', 
    CONV = "xluacv_$ACTION_uint",
}