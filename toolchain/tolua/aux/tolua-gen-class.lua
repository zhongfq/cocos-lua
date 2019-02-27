local function gen_class_funcs(cls, write)
    for i, fi in ipairs(cls.FUNCS) do
        gen_class_func(cls, fi, write)
        write('')
    end
end

local function gen_class_open(cls, write)
    local template = [[
        static int luaopen_${CLASS_PATH}(lua_State *L)
        {
            xluacls_class(L, "${CLASSNAME", ${SUPRE_CLASSNAME});
            ${FUNCS}
            
            ${STATIC_CLASS}
            
            return 1;
        }
    ]]
    local CLASSNAME = cls.CLASS
    local CLASS_PATH = class_path(CLASSNAME)
    local SUPRE_CLASSNAME = stringfy(cls.SUPER) or "nullptr"
    local FUNCS = {}
    local STATIC_CLASS = ""

    for i, fi in ipairs(cls.FUNCS) do
        local FUNC = fi.FUNC
        local FUNC_NAME = fi.NAME
        FUNCS[i] = format_snippet([[
            xluacls_setfunc(L, "${FUNC_NAME}", _${CLASS_PATH}_${FUNC});
        ]])
    end

    if cls.STATIC then
        STATIC_CLASS = format_snippet([[
            lua_newtable(L);
            luaL_setmetatable(L, "${CLASSNAME}");
        ]])
    end

    FUNCS = table.concat(FUNCS, "\n")

    write(format_snippet(template))
end

function gen_class(module, cls, write)
    gen_class_funcs(cls, write)
    gen_class_open(cls, write)
end