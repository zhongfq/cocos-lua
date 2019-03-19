local class_map = {}

local function check_gen_class_func(cls, fi, write, func_filter)
    local meta = assert(class_map[cls.LUACLS], cls.LUACLS)
    if meta and getmetatable(meta) then
        local supermeta = getmetatable(meta).__index
        for _, f in ipairs(fi) do
            if f.PROTOTYPE and rawget(meta, f.PROTOTYPE) and supermeta[f.PROTOTYPE] then
                print(string.format("super class already export the func: %s %s", cls.CPPCLS, f.PROTOTYPE))
            end
        end
    end
    gen_class_func(cls, fi, write, func_filter)
end

local function gen_class_funcs(cls, write)
    local clsmeta = cls.PROTOTYPES

    if cls.SUPERCLS then
        assert(class_map[cls.SUPERCLS], cls.CPPCLS .. '|' .. cls.SUPERCLS)
        clsmeta = setmetatable(clsmeta, {__index = class_map[cls.SUPERCLS]})
    end
    class_map[cls.LUACLS] = clsmeta

    local func_filter = {}
    for i, fi in ipairs(cls.FUNCS) do
        check_gen_class_func(cls, fi, write, func_filter)
    end

    for i, pi in ipairs(cls.PROPS) do
        if pi.GET then
            check_gen_class_func(cls, {pi.GET}, write, func_filter)
        end
        if pi.SET then
            check_gen_class_func(cls, {pi.SET}, write, func_filter)
        end
    end

    for i, ai in ipairs(cls.VARS) do
        check_gen_class_func(cls, {ai.GET}, write, func_filter)
        check_gen_class_func(cls, {ai.SET}, write, func_filter)
    end
end

local function gen_class_open(cls, write)
    local LUACLS = cls.LUACLS
    local CPPCLS = cls.CPPCLS
    local CPPCLS_PATH = class_path(cls)
    local SUPRECLS = stringfy(cls.SUPERCLS) or "nullptr"
    local FUNCS = {}
    local REG_LUATYPE = ''

    for i, fis in ipairs(cls.FUNCS) do
        local CPPFUNC = fis[1].CPPFUNC
        local LUAFUNC = fis[1].LUAFUNC
        FUNCS[#FUNCS + 1] = format_snippet([[
            oluacls_setfunc(L, "${LUAFUNC}", _${CPPCLS_PATH}_${CPPFUNC});
        ]])
    end

    for i, pi in ipairs(cls.PROPS) do
        local PROP_NAME = pi.PROP_NAME
        local FUNC_GET = "nullptr"
        local FUNC_SET = "nullptr"
        if pi.GET then
            FUNC_GET = string.format("_%s_%s", CPPCLS_PATH, pi.GET.CPPFUNC)
        end
        if pi.SET then
            FUNC_SET = string.format("_%s_%s", CPPCLS_PATH, pi.SET.CPPFUNC)
        end
        FUNCS[#FUNCS + 1] = format_snippet([[
            oluacls_property(L, "${PROP_NAME}", ${FUNC_GET}, ${FUNC_SET});
        ]])
    end

    for i, vi in ipairs(cls.VARS) do
        local VARNAME = vi.VARNAME
        local FUNC_GET = string.format("_%s_%s", CPPCLS_PATH, vi.GET.CPPFUNC)
        local FUNC_SET = string.format("_%s_%s", CPPCLS_PATH, vi.SET.CPPFUNC)
        FUNCS[#FUNCS + 1] = format_snippet([[
            oluacls_property(L, "${VARNAME}", ${FUNC_GET}, ${FUNC_SET});
        ]])
    end

    for i, ci in ipairs(cls.CONSTS) do
        local CONST_FUNC
        local CONST_VALUE = ci.CONST_VALUE
        local CONST_NAME = ci.CONST_NAME
        if ci.TYPE == "boolean" then
            CONST_FUNC = "oluacls_const_bool"
        elseif ci.TYPE == "integer" then
            CONST_FUNC = "oluacls_const_integer"
        elseif ci.TYPE == "float" then
            CONST_FUNC = "oluacls_const_number"
        elseif ci.TYPE == "string" then
            CONST_FUNC = "oluacls_const_string"
            CONST_VALUE = stringfy(CONST_VALUE)
        end
        FUNCS[#FUNCS + 1] = format_snippet([[
            ${CONST_FUNC}(L, "${CONST_NAME}", ${CONST_VALUE});
        ]])
    end

    for i, ei in ipairs(cls.ENUMS) do
        local ENUM_NAME = ei.ENUM_NAME
        local ENUM_VALUE = assert(ei.ENUM_VALUE, cls.CPPCLS)
        FUNCS[#FUNCS + 1] = format_snippet([[
            oluacls_const_integer(L, "${ENUM_NAME}", (lua_Integer)${ENUM_VALUE});
        ]])
    end

    FUNCS = table.concat(FUNCS, "\n")

    if cls.REG_LUATYPE then
        REG_LUATYPE = format_snippet([[
            olua_registerluatype<${CPPCLS}>(L, "${LUACLS}");
        ]])
    end

    write(format_snippet([[
        static int luaopen_${CPPCLS_PATH}(lua_State *L)
        {
            oluacls_class(L, "${LUACLS}", ${SUPRECLS});
            ${FUNCS}

            ${REG_LUATYPE}
            oluacls_createclassproxy(L);
            
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
    assert(not string.find(cls.LUACLS, ':_ '))
    gen_class_decl_val(cls, write)
    gen_class_funcs(cls, write)
    gen_class_open(cls, write)
end