require "aux.tolua-cls"

register_type('void')
register_type('void *')
register_type('bool')
register_type('std::string')
register_type('unsigned int', {PUSH = "xluacv_push_uint", TO = "xluacv_to_uint"})