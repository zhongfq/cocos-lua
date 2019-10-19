local olua = require "olua.olua-io"

local format = olua.format
local classmap = {}

local function hasGCMethod(cls)
    for _, v in ipairs(cls.FUNCS) do
        if v[1].LUAFUNC == '__gc' then
            return true
        end
    end

    if cls.SUPERCLS then
        return hasGCMethod(olua.classmap()[cls.SUPERCLS])
    end
end

local function checkGCMethod(cls)
    local hasConstructor = false
    for _, v in ipairs(cls.FUNCS) do
        if v[1].CONSTRUCTOR then
            hasConstructor = true
            break
        end
    end
    if hasConstructor then
        if not hasGCMethod(cls) then
            local fi = {}
            fi.LUAFUNC = '__gc'
            fi.CPPFUNC = '__gc'
            fi.CPPFUNC_SNIPPET = format [[
                {
                    lua_settop(L, 1);
                    auto self = olua_touserdata(L, 1, ${cls.CPPCLS} *);
                    lua_pushstring(L, ".ownership");
                    olua_getvariable(L, 1);
                    if (lua_toboolean(L, -1) && self) {
                        *(void **)lua_touserdata(L, 1) = nullptr;
                        delete self;
                    }
                    return 0;
                }
            ]]
            fi.DECLFUNC = '<function snippet>'
            fi.RET = {}
            fi.RET.NUM = 0
            fi.RET.TYPE = olua.typeinfo('void', cls)
            fi.RET.ATTR = {}
            fi.ARGS = {}
            fi.INJECT = {}
            fi.PROTOTYPE = false
            fi.INDEX = 1
            fi.MAX_ARGS = #fi.ARGS
            cls.FUNCS[#cls.FUNCS + 1] = {MAX_ARGS = fi.MAX_ARGS}
            cls.FUNCS[#cls.FUNCS][1] = fi
        end
    end
end

local function checkGenClassFunc(cls, fi, write, func_filter)
    local meta = assert(classmap[cls.LUACLS], cls.LUACLS)
    if meta and getmetatable(meta) then
        local supermeta = getmetatable(meta).__index
        for _, f in ipairs(fi) do
            if f.PROTOTYPE and rawget(meta, f.PROTOTYPE) and supermeta[f.PROTOTYPE] then
                print(string.format("super class already export the func: %s %s", cls.CPPCLS, f.PROTOTYPE))
            end
        end
    end
    olua.genClassFunc(cls, fi, write, func_filter)
end

local function genClassFuncs(cls, write)
    local clsmeta = cls.PROTOTYPES

    if cls.SUPERCLS then
        assert(classmap[cls.SUPERCLS], 'super class ' .. cls.SUPERCLS .. ' must exported befor ' .. cls.CPPCLS)
        clsmeta = setmetatable(clsmeta, {__index = classmap[cls.SUPERCLS]})
    end
    classmap[cls.LUACLS] = clsmeta
    classmap[cls.CPPCLS] = clsmeta

    local func_filter = {}
    table.sort(cls.FUNCS, function (a, b)
        return a[1].LUAFUNC < b[1].LUAFUNC
    end)
    for _, fi in ipairs(cls.FUNCS) do
        checkGenClassFunc(cls, fi, write, func_filter)
    end

    table.sort(cls.PROPS, function (a, b)
        return a.PROP_NAME < b.PROP_NAME
    end)
    for _, pi in ipairs(cls.PROPS) do
        if pi.GET then
            checkGenClassFunc(cls, {pi.GET}, write, func_filter)
        end
        if pi.SET then
            checkGenClassFunc(cls, {pi.SET}, write, func_filter)
        end
    end

    table.sort(cls.VARS, function (a, b)
        return a.VARNAME < b.VARNAME
    end)
    for _, ai in ipairs(cls.VARS) do
        checkGenClassFunc(cls, {ai.GET}, write, func_filter)
        if ai.SET then
            checkGenClassFunc(cls, {ai.SET}, write, func_filter)
        end
    end
end

local function genClassOpen(cls, write)
    local CPPCLS_PATH = olua.topath(cls.CPPCLS)
    local SUPRECLS = "nullptr"
    if cls.SUPERCLS then
        SUPRECLS = olua.stringfy(olua.toluacls(cls.SUPERCLS))
    end
    local FUNCS = {}
    local REG_LUATYPE = ''

    for _, fis in ipairs(cls.FUNCS) do
        local CPPFUNC = fis[1].CPPFUNC
        local LUAFUNC = fis[1].LUAFUNC
        olua.nowarning(CPPFUNC, LUAFUNC)
        FUNCS[#FUNCS + 1] = format([[
            oluacls_func(L, "${LUAFUNC}", _${CPPCLS_PATH}_${CPPFUNC});
        ]])
    end

    for _, pi in ipairs(cls.PROPS) do
        local FUNC_GET = "nullptr"
        local FUNC_SET = "nullptr"
        if pi.GET then
            FUNC_GET = string.format("_%s_%s", CPPCLS_PATH, pi.GET.CPPFUNC)
        end
        if pi.SET then
            FUNC_SET = string.format("_%s_%s", CPPCLS_PATH, pi.SET.CPPFUNC)
        end
        olua.nowarning(FUNC_GET, FUNC_SET)
        FUNCS[#FUNCS + 1] = format([[
            oluacls_prop(L, "${pi.PROP_NAME}", ${FUNC_GET}, ${FUNC_SET});
        ]])
    end

    for _, vi in ipairs(cls.VARS) do
        local FUNC_GET = string.format("_%s_%s", CPPCLS_PATH, vi.GET.CPPFUNC)
        local FUNC_SET = "nullptr"
        if vi.SET and vi.SET.CPPFUNC then
           FUNC_SET = string.format("_%s_%s", CPPCLS_PATH, vi.SET.CPPFUNC)
        end
        olua.nowarning(FUNC_GET, FUNC_SET)
        FUNCS[#FUNCS + 1] = format([[
            oluacls_prop(L, "${vi.VARNAME}", ${FUNC_GET}, ${FUNC_SET});
        ]])
    end

    table.sort(cls.CONSTS, function (a, b)
        return a.CONST_NAME < b.CONST_NAME
    end)
    for _, ci in ipairs(cls.CONSTS) do
        local CONST_FUNC
        local CONST_VALUE = ci.CONST_VALUE
        if ci.TYPE == "boolean" then
            CONST_FUNC = "oluacls_const_bool"
        elseif ci.TYPE == "integer" then
            CONST_FUNC = "oluacls_const_integer"
        elseif ci.TYPE == "float" then
            CONST_FUNC = "oluacls_const_number"
        elseif ci.TYPE == "string" then
            CONST_FUNC = "oluacls_const_string"
            CONST_VALUE = olua.stringfy(CONST_VALUE)
        end
        olua.nowarning(CONST_FUNC)
        FUNCS[#FUNCS + 1] = format([[
            ${CONST_FUNC}(L, "${ci.CONST_NAME}", ${CONST_VALUE});
        ]])
    end

    table.sort(cls.CONSTS, function (a, b)
        return a.ENUM_NAME < b.ENUM_NAME
    end)
    for _, ei in ipairs(cls.ENUMS) do
        olua.nowarning(ei)
        FUNCS[#FUNCS + 1] = format([[
            oluacls_const_integer(L, "${ei.ENUM_NAME}", (lua_Integer)${ei.ENUM_VALUE});
        ]])
    end

    FUNCS = table.concat(FUNCS, "\n")

    if cls.REG_LUATYPE then
        local ti = olua.typeinfo(cls.CPPCLS, nil, true) or olua.typeinfo(cls.CPPCLS .. ' *')
        if olua.isvaluetype(ti) then
            olua.assert(#cls.FUNCS == 0, cls.CPPCLS .. ' not a enum class')
            olua.assert(#cls.PROPS == 0, cls.CPPCLS .. ' not a enum class')
            REG_LUATYPE = format([[
                olua_registerluatype<${cls.CPPCLS}>(L, "${cls.LUACLS}");
                oluacls_asenum(L);
            ]])
        else
            REG_LUATYPE = format([[
                olua_registerluatype<${cls.CPPCLS}>(L, "${cls.LUACLS}");
            ]])
        end
    end

    olua.nowarning(REG_LUATYPE, SUPRECLS)
    write(format([[
        static int luaopen_${CPPCLS_PATH}(lua_State *L)
        {
            oluacls_class(L, "${cls.LUACLS}", ${SUPRECLS});
            ${FUNCS}

            ${REG_LUATYPE}
            oluacls_createclassproxy(L);
            
            return 1;
        }
    ]]))
end

local function genClassChunk(cls, write)
    if cls.CHUNK then
        write(format(cls.CHUNK))
        write('')
    end
end

function olua.genClass(module, cls, write)
    checkGCMethod(cls)
    genClassChunk(cls, write)
    genClassFuncs(cls, write)
    genClassOpen(cls, write)
end