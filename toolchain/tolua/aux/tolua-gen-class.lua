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
    local LUACLS = cls.LUACLS
    local CPPCLS_PATH = class_path(cls.CPPCLS)
    local SUPRECLS = stringfy(cls.SUPERCLS) or "nullptr"
    local FUNCS = {}

    for i, fis in ipairs(cls.FUNCS) do
        local CPPFUNC = fis[1].CPPFUNC
        local LUAFUNC = fis[1].LUAFUNC
        FUNCS[#FUNCS + 1] = format_snippet([[
            toluacls_setfunc(L, "${LUAFUNC}", _${CPPCLS_PATH}_${CPPFUNC});
        ]])
    end

    for i, pi in ipairs(cls.PROPS) do
        local PROP_NAME = pi.NAME
        local FUNC_GET = "nullptr"
        local FUNC_SET = "nullptr"
        if pi.GET then
            FUNC_GET = string.format("_%s_%s", CPPCLS_PATH, pi.GET.CPPFUNC)
        end
        if pi.SET then
            FUNC_SET = string.format("_%s_%s", CPPCLS_PATH, pi.SET.CPPFUNC)
        end
        FUNCS[#FUNCS + 1] = format_snippet([[
            toluacls_property(L, "${PROP_NAME}", ${FUNC_GET}, ${FUNC_SET});
        ]])
    end

    for i, ci in ipairs(cls.CONSTS) do
        local CONST_FUNC
        local CONST_VALUE = ci.VALUE
        local CONST_NAME = ci.NAME
        if ci.TYPE == "boolean" then
            CONST_FUNC = "toluacls_const_bool"
        elseif ci.TYPE == "integer" then
            CONST_FUNC = "toluacls_const_integer"
        elseif ci.TYPE == "float" then
            CONST_FUNC = "toluacls_const_number"
        elseif ci.TYPE == "string" then
            CONST_FUNC = "toluacls_const_string"
            CONST_VALUE = '"' .. CONST_VALUE .. '"'
        end
        FUNCS[#FUNCS + 1] = format_snippet([[
            ${CONST_FUNC}(L, "${CONST_NAME}", ${CONST_VALUE});
        ]])
    end

    FUNCS = table.concat(FUNCS, "\n")

    write(format_snippet([[
        static int luaopen_${CPPCLS_PATH}(lua_State *L)
        {
            toluacls_class(L, "${LUACLS", ${SUPRECLS});
            ${FUNCS}
            
            toluacls_createclassproxy(L);
            
            return 1;
        }
    ]]))
end

local function gen_class_decl_val(cls, write)
    if cls.DEFCHUNK then
        write(format_snippet(cls.DEFCHUNK))
        write('')
    end
end

function gen_class(module, cls, write)
    gen_class_decl_val(cls, write)
    gen_class_funcs(cls, write)
    gen_class_open(cls, write)
end