local function gen_class_funcs(cls, write)
    for i, fi in ipairs(cls.FUNCS) do
        gen_class_func(cls, fi, write)
        write('')
    end

    for i, pi in ipairs(cls.PROPS) do
        if pi.GET then
            gen_class_func(cls, {pi.GET}, write)
            write('')
        end
        if pi.SET then
            gen_class_func(cls, {pi.SET}, write)
            write('')
        end
    end
end

local function gen_class_open(cls, write)
    local template = [[
        static int luaopen_${CLASS_PATH}(lua_State *L)
        {
            xluacls_class(L, "${CLASSNAME", ${SUPRE_CLASSNAME});
            ${FUNCS}
            
            lua_newtable(L);
            luaL_setmetatable(L, "${CLASSNAME}");
            
            return 1;
        }
    ]]
    local CLASSNAME = cls.CLASS
    local CLASS_PATH = class_path(CLASSNAME)
    local SUPRE_CLASSNAME = stringfy(cls.SUPER) or "nullptr"
    local FUNCS = {}

    for i, fis in ipairs(cls.FUNCS) do
        local FUNC = fis[1].FUNC
        local FUNC_NAME = fis[1].NAME
        FUNCS[#FUNCS + 1] = format_snippet([[
            xluacls_setfunc(L, "${FUNC_NAME}", _${CLASS_PATH}_${FUNC});
        ]])
    end

    for i, pi in ipairs(cls.PROPS) do
        local FUNC_NAME = pi.NAME
        local FUNC_GET = "nullptr"
        local FUNC_SET = "nullptr"
        if pi.GET then
            FUNC_GET = string.format("_%s_%s", CLASS_PATH, pi.GET.FUNC)
        end
        if pi.SET then
            FUNC_SET = string.format("_%s_%s", CLASS_PATH, pi.SET.FUNC)
        end
        FUNCS[#FUNCS + 1] = format_snippet([[
            xluacls_property(L, "${FUNC_NAME}", ${FUNC_GET}, ${FUNC_SET});
        ]])
    end

    for i, ci in ipairs(cls.CONSTS) do
        local CONST_FUNC
        local CONST_VALUE = ci.VALUE
        local CONST_NAME = ci.NAME
        if ci.TYPE == "boolean" then
            CONST_FUNC = "xluacls_const_bool"
        elseif ci.TYPE == "integer" then
            CONST_FUNC = "xluacls_const_integer"
        elseif ci.TYPE == "float" then
            CONST_FUNC = "xluacls_const_number"
        elseif ci.TYPE == "string" then
            CONST_FUNC = "xluacls_const_string"
            CONST_VALUE = '"' .. CONST_VALUE .. '"'
        end
        FUNCS[#FUNCS + 1] = format_snippet([[
            ${CONST_FUNC}(L, "${CONST_NAME}", ${CONST_VALUE});
        ]])
    end

    FUNCS = table.concat(FUNCS, "\n")

    write(format_snippet(template))
end

local function gen_class_decl_val(cls, write)
    if cls.DECL_VAR then
        write(format_snippet(cls.DECL_VAR))
        write('')
    end
end

function gen_class(module, cls, write)
    gen_class_decl_val(cls, write)
    gen_class_funcs(cls, write)
    gen_class_open(cls, write)
end