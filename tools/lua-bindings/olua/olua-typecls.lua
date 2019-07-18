local olua = require "olua.olua-io"

local typeinfo_map = {}
local class_map = {}

local format = olua.format

local message = ""

function olua.message(msg)
    message = msg
end

function olua.error(fmt, ...)
    print("parse => " .. message)
    error(string.format(fmt, ...))
end

function olua.assert(cond, fmt, ...)
    if not cond then
        olua.error(fmt or '', ...)
    end
    return cond
end

local function prettyTypename(tn)
    tn = string.gsub(tn, '^ *', '') -- trim head space
    tn = string.gsub(tn, ' *$', '') -- trim tail space
    tn = string.gsub(tn, ' +', ' ') -- remove needless space

    -- const type * * => const type **
    tn = string.gsub(tn, ' *%*', '*')
    tn = string.gsub(tn, '%*+', function (str) return " " .. str end)

    tn = string.gsub(tn, ' *&', '&')
    tn = string.gsub(tn, '%&+', function (str) return " " .. str end)

    return tn
end

local function rawTypename(tn)
    tn = string.gsub(tn, ' *&+', '')

    if typeinfo_map[tn] then
        return tn
    end

    local noconst = string.gsub(tn, 'const *', '')
    if typeinfo_map[noconst] then
        return noconst
    end
    
    return tn
end

local function tryNamespace(ns, tn)
    -- const Object * => const ns::Object *
    tn = string.gsub(tn, '[%w:_]+ *%**$', function (s)
        return ns .. '::' .. s
    end)
    tn = rawTypename(tn)
    return typeinfo_map[tn], tn
end

function olua.typeinfo(tn, cls, silence)
    local ti, subti, subtn -- for tn<T>

    tn = prettyTypename(tn)

    if string.find(tn, '<') then
        subtn = string.match(tn, '<(.*)>')
        subti, subtn = olua.typeinfo(subtn, cls, silence)
        tn = prettyTypename(string.gsub(tn, '<.*>', ''))
    end

    tn = rawTypename(tn)
    ti = typeinfo_map[tn]

    if ti then
        ti = setmetatable({SUBTYPE = subti}, {__index = ti})
        return ti, tn, subtn
    end

    -- search in class namespace
    if cls and cls.CPPCLS then
        local nsarr = {}
        for n in string.gmatch(cls.CPPCLS, '[^:]+') do
            nsarr[#nsarr + 1] = n
        end
        while #nsarr > 0 do
            local ns = table.concat(nsarr, "::")
            local ti1, tn1 = tryNamespace(ns, tn)
            if not ti1 then
                nsarr[#nsarr] = nil
            else
                ti = ti1
                tn = tn1
                ti = setmetatable({SUBTYPE = subti}, {__index = ti})
                return ti, tn, subtn
            end
        end
    end

    -- search in super class namespace
    if cls and cls.SUPERCLS then
        local super = class_map[cls.SUPERCLS]
        olua.assert(super, "the super class '%s' of '%s' is not found", cls.SUPERCLS, cls.CPPCLS)
        return olua.typeinfo(tn, super, silence)
    end

    if not ti and not silence then
        olua.error("type info not found: %s", tn)
    end
end

--[[
    function arg variable must declared with no const type

    eg: Object::call(const std::vector<A *> arg1)

    Object *self = nullptr;
    std::vector<int> arg1;
    olua_to_cppobj(L, 1, (void **)&self, "Object");
    olua_check_std_vector(L, 2, arg1, "A");
    self->call(arg1);
]]
local function toDecltype(cls, typename, isvariable)
    local reference = string.match(typename, '&+')
    local _, tn, subtn = olua.typeinfo(typename, cls)

    if subtn then
        tn = string.format('%s<%s>', tn, subtn)
        if isvariable then
            tn = string.gsub(tn, 'const *', '')
        end
    end

    if not isvariable and reference then
        tn = tn .. ' ' .. reference
    end

    return tn
end

--
-- parse type attribute and return the rest of string
-- eg: @unref(cmp children) void removeChild(@ref(map children) child)
-- reutrn: {UNREF={cmp, children}}, void removeChild(@ref(map children) child)
--
local function parseAttr(str)
    local attr = {}
    local static
    str = string.gsub(str, '^ *', '')
    while true do
        local name, value = string.match(str, '^@(%w+)%(([%w ]*)%)')
        if name then
            local arr = {}
            for v in string.gmatch(value, '[^ ]+') do
                arr[#arr + 1] = v
            end
            attr[string.upper(name)] = arr
            str = string.gsub(str, '^@%w+%([%w ]*%)', '')
        else
            name = string.match(str, '^@(%w+)')
            if name then
                attr[string.upper(name)] = {}
                str = string.gsub(str, '^@%w+', '')
            else
                break
            end
        end
    end
    str, static = string.gsub(str, '^ *static *', '')
    attr.STATIC = static > 0
    return attr, str
end

local function parseType(str)
    local attr, tn
    attr, str = parseAttr(str)
    -- str = std::function <void (float int)> &arg, ...
    tn = string.match(str, '^[%w_: ]+%b<>[ &*]*') -- parse template type
    if not tn then
        local from, to
        while true do
            from, to = string.find(str, ' *[%w_:]+[ &*]*', to)
            if not from then
                break
            end
            tn = prettyTypename(string.sub(str, from, to))
            if tn == 'signed' or tn == 'unsigned' then
                local substr = string.sub(str, to + 1)
                -- str = unsigned count = 1, ... ?
                if not (substr:find('^ *int *')
                    or substr:find('^ *short *')
                    or substr:find('^ *char *')) then
                    tn = string.sub(str, 1, to) .. ' int'
                    str = string.sub(str, to + 1)
                    return prettyTypename(tn), attr, str
                end
            end
            if tn ~= 'const' and tn ~= 'signed' and tn ~= 'unsigned' then
                tn = string.sub(str, 1, to)
                break
            end
        end
    end
    str = string.sub(str, #tn + 1)
    str = string.gsub(str, '^ *', '')
    return prettyTypename(tn), attr, str
end

local parseArgs

local function parseCallbackType(cls, tn, default)
    local rtn, rtattr
    local declstr = string.match(tn, '<(.*)>') -- match callback function prototype
    rtn, rtattr, declstr = parseType(declstr)
    declstr = string.gsub(declstr, '^[^(]+', '') -- match callback args

    local args = parseArgs(cls, declstr)
    local decltype = {}
    for _, ai in ipairs(args) do
        decltype[#decltype + 1] = ai.RAW_DECLTYPE
    end
    decltype = table.concat(decltype, ", ")
    decltype = string.format('std::function<%s(%s)>', toDecltype(cls, rtn, false), decltype)

    local RET = {}
    RET.TYPE = olua.typeinfo(rtn, cls)
    RET.NUM = RET.TYPE.CPPCLS == "void" and 0 or 1
    RET.DECLTYPE = toDecltype(cls, rtn, false)
    RET.ATTR = rtattr

    return {
        DEFAULT = default,
        ARGS = args,
        RET = RET,
        DECLTYPE = decltype,
    }
end

--[[
    arg struct: void func(@pack const std::vector<int> &points = value)
    {
        TYPE             -- type info
        DECLTYPE         -- decltype: std::vector<int>
        RAW_DECLTYPE     -- raw decltype: const std::vector<int> &
        DEFAULT          -- default value: value
        VARNAME          -- var name: points
        ATTR             -- attr: {PACK = true}
        CALLBACK = {     -- eg: std::function<void (float, const A *a)>
            DEFAULT      -- default value: nullptr or none
            ARGS         -- callback functions args: float, A *a
            RET          -- return type info: void type info
            DECLTYPE     -- std::function<void (float, const A *)>
        }
    }
]]
function parseArgs(cls, declstr)
    local args = {}
    local count = 0
    declstr = string.match(declstr, '%((.*)%)')
    olua.assert(declstr, 'malformed args string')

    while #declstr > 0 do
        local tn, attr, varname, default, _, to
        tn, attr, declstr = parseType(declstr)
        if tn == 'void' then
            return args, count
        end

        -- match: x = Point(0, 0), bool b, ...)
        _, to, varname, default = string.find(declstr, '^([^ ]+) *= *([%w_:]+%b())')

        -- match: x = 3, bool b, ...)
        if not varname then
            _, to, varname, default = string.find(declstr, '^([^ ]+) *= *([^ ,]*)')
        end

        -- match: x, bool b, ...)
        if not varname then
            _, to, varname = string.find(declstr, '^([^ ,]+)')
        end

        if varname then
            declstr = string.sub(declstr, to + 1)
        end

        declstr = string.gsub(declstr, '^[^,]*,? *', '') -- skip ','

        if default and not string.find(default, '^"') and string.find(default, '[():]') then
            -- match: Point(0, 2) => Point
            local dtn = string.match(default, '^([^(]+)%(')
            if not dtn then
                -- match: Point::Zero => Point
                dtn = string.match(default, '^(.*)::[%w_]+')
            end
            olua.assert(dtn, 'unknown default value format: %s', default)
            local dti = olua.typeinfo(dtn, cls, true) or olua.typeinfo(dtn .. ' *', cls)
            default = string.gsub(default, dtn, dti.CPPCLS)
        end

        -- is callback
        if string.find(tn, 'std::function<') then
            local callback = parseCallbackType(cls, tn, default)
            args[#args + 1] = {
                TYPE = setmetatable({
                    DECLTYPE = callback.DECLTYPE,
                }, {__index = olua.typeinfo('std::function', cls)}),
                DECLTYPE = callback.DECLTYPE,
                VARNAME = varname or '',
                ATTR = attr,
                CALLBACK = callback,
            }
        else
            args[#args + 1] = {
                TYPE = olua.typeinfo(tn, cls),
                DECLTYPE = toDecltype(cls, tn, true),
                RAW_DECLTYPE = toDecltype(cls, tn, false),
                DEFAULT = default,
                VARNAME = varname or '',
                ATTR = attr,
                CALLBACK = {},
            }
        end

        if attr.PACK then
            count = count + assert(args[#args].TYPE.VARS, args[#args].TYPE.CPPCLS)
        else
            count = count + 1
        end
    end

    return args, count
end

local function parseFunc(cls, name, ...)
    local function copy(t)
        return setmetatable({}, {__index = t})
    end
    local arr = {MAX_ARGS = 0}
    for _, declfunc in ipairs({...}) do
        local fi = {RET = {}}
        olua.message(declfunc)
        if string.find(declfunc, '{') then
            fi.LUAFUNC = assert(name)
            fi.CPPFUNC = name
            fi.CPPFUNC_SNIPPET = declfunc
            fi.DECLFUNC = '<function snippet>'
            fi.RET.NUM = 0
            fi.RET.TYPE = olua.typeinfo('void', cls)
            fi.RET.ATTR = {}
            fi.ARGS = {}
            fi.INJECT = {}
            fi.PROTOTYPE = false
            fi.MAX_ARGS = #fi.ARGS
        else
            local typename, attr, str = parseType(declfunc)
            fi.CPPFUNC = string.match(str, '[^ ()]+')
            fi.LUAFUNC = name or fi.CPPFUNC
            fi.STATIC = attr.STATIC
            fi.DECLFUNC = declfunc
            fi.INJECT = {}
            if string.find(typename, 'std::function<') then
                local callback = parseCallbackType(cls, typename, nil)
                fi.RET = {
                    TYPE = setmetatable({
                        DECLTYPE = callback.DECLTYPE,
                    }, {__index = olua.typeinfo('std::function', cls)}),
                    DECLTYPE = callback.DECLTYPE,
                    ATTR = attr,
                    NUM = 1,
                    CALLBACK = callback,
                }
            else
                fi.RET.TYPE = olua.typeinfo(typename, cls)
                fi.RET.NUM = fi.RET.TYPE.CPPCLS == "void" and 0 or 1
                fi.RET.DECLTYPE = toDecltype(cls, typename, false)
                fi.RET.ATTR = attr
            end
            fi.ARGS, fi.MAX_ARGS = parseArgs(cls, string.sub(str, #fi.CPPFUNC + 1))

            do -- generate function prototype: void func(int, A *, B *)
                local ARGS_DECL = {}
                local RET_DECL = fi.RET.SUBTYPE and fi.RET.DECLTYPE or fi.RET.TYPE.CPPCLS
                local CPPFUNC = fi.CPPFUNC
                local STATIC = fi.STATIC and "static " or ""
                for _, v in ipairs(fi.ARGS) do
                    ARGS_DECL[#ARGS_DECL + 1] = (v.TYPE.SUBTYPE or next(v.CALLBACK)) and v.DECLTYPE or v.TYPE.CPPCLS
                end
                ARGS_DECL = table.concat(ARGS_DECL, ", ")
                olua.nowarning(RET_DECL, CPPFUNC, STATIC)
                fi.PROTOTYPE = format([[
                    ${STATIC}${RET_DECL} ${CPPFUNC}(${ARGS_DECL})
                ]])
                cls.PROTOTYPES[fi.PROTOTYPE] = true
            end

            -- has @pack? gen one more func
            if fi.MAX_ARGS ~= #fi.ARGS then
                local packarg
                local fi2 = copy(fi)
                fi2.RET = copy(fi.RET)
                fi2.RET.ATTR = copy(fi.RET.ATTR)
                fi2.ARGS = {}
                fi2.DECLFUNC = string.gsub(fi.DECLFUNC, '@pack *', '')
                for i in ipairs(fi.ARGS) do
                    fi2.ARGS[i] = copy(fi.ARGS[i])
                    fi2.ARGS[i].ATTR = copy(fi.ARGS[i].ATTR)
                    if fi.ARGS[i].ATTR.PACK then
                        assert(not packarg, 'too many pack args')
                        packarg = fi.ARGS[i]
                        fi2.ARGS[i].ATTR.PACK = false
                        fi2.MAX_ARGS = fi2.MAX_ARGS + 1 - packarg.TYPE.VARS
                    end
                end
                assert(packarg, declfunc)
                if packarg.TYPE.CPPCLS == fi.RET.TYPE.CPPCLS then
                    fi2.RET.ATTR.UNPACK = fi.RET.ATTR.UNPACK or false
                    fi.RET.ATTR.UNPACK = true
                end
                arr[#arr + 1] = fi2
                fi2.INDEX = #arr
            end
        end
        assert(not string.find(fi.LUAFUNC, '[^_%w]+'), '"' .. fi.LUAFUNC .. '"')
        arr[#arr + 1] = fi
        arr.MAX_ARGS = math.max(arr.MAX_ARGS, fi.MAX_ARGS)
        fi.INDEX = #arr
    end

    return arr
end

local function toPropFuncName(cppfunc, prefix)
    return prefix .. string.gsub(cppfunc, '^%w', function (s)
        return string.upper(s)
    end)
end

local function parseProp(cls, name, declget, declset)
    local pi = {}
    pi.PROP_NAME = assert(name, 'no prop name')

    -- eg: name = url
    -- try getUrl and getURL
    -- try setUrl and setURL
    local name2 = string.gsub(name, '^%l+', function (s)
        return string.upper(s)
    end)

    local function test(f, name, op)
        name = toPropFuncName(name, op)
        if name == f.CPPFUNC or name == f.LUAFUNC then
            return true
        else
            -- getXXXXS => getXXXXs?
            name = name:sub(1, #name - 1) .. name:sub(#name):lower()
            return name == f.CPPFUNC or name == f.LUAFUNC
        end
    end

    if declget then
        pi.GET = declget and parseFunc(cls, name, declget)[1] or nil
    else
        for _, v in ipairs(cls.FUNCS) do
            for _, f in ipairs(v) do
                if test(f, name, 'get') or test(f, name, 'is') or
                    test(f, name2, 'get') or test(f, name2, 'is') then
                    olua.message(f.DECLFUNC)
                    olua.assert(#f.ARGS == 0, "function '%s::%s' has arguments", cls.CPPCLS, f.CPPFUNC)
                    pi.GET = f
                end
            end
        end
        assert(pi.GET, name)
    end

    if declset then
        pi.SET = declset and parseFunc(cls, name, declset)[1] or nil
    else
        for _, v in ipairs(cls.FUNCS) do
            for _, f in ipairs(v) do
                if test(f, name, 'set') or test(f, name2, 'set') then
                    pi.SET = f
                end
            end
        end
    end

    if not pi.GET.CPPFUNC_SNIPPET then
        assert(pi.GET.RET.NUM > 0, declget)
    elseif declget then
        pi.GET.CPPFUNC = 'get_' .. pi.GET.CPPFUNC
    end

    if pi.SET and pi.SET.CPPFUNC_SNIPPET and declset then
        pi.SET.CPPFUNC = 'set_' .. pi.SET.CPPFUNC
    end

    return pi
end

function olua.typecls(cppcls)
    local cls = {CPPCLS = cppcls}
    cls.FUNCS = {}
    cls.CONSTS = {}
    cls.ENUMS = {}
    cls.PROPS = {}
    cls.VARS = {}
    cls.PROTOTYPES = {}
    cls.REG_LUATYPE = true
    class_map[cls.CPPCLS] = cls

    function cls.func(name, ...)
        cls.FUNCS[#cls.FUNCS + 1] = parseFunc(cls, name, ...)
    end

    function cls.funcs(funcs)
        local arr = {}
        local dict = {}
        for declfunc in string.gmatch(funcs, '[^\n\r]+') do
            declfunc = string.gsub(declfunc, '^ *', '')
            declfunc = string.gsub(declfunc, ' *inline ', '')
            if #declfunc > 0 then
                if not string.find(declfunc, '^ *//') then
                    local _, str = parseAttr(declfunc)
                    _, _, str = parseType(str)        -- skip return type
                    local fn = string.match(str, '([^ ()]+) *%(')
                    local fns = dict[fn]
                    assert(fn, declfunc)
                    if not fns then
                        fns = {}
                        arr[#arr + 1] = fns
                        dict[fn] = fns
                    end
                    fns[#fns + 1] = string.gsub(declfunc, '^ *', '')
                end
            end
        end
        for _, v in ipairs(arr) do
            cls.func(nil, table.unpack(v))
        end
    end

    --[[
        {
            ...
            std::function<void (float)> argN = [storeobj, func](float v) {
                ...
                ${CALLBACK_BEFORE}
                olua_callback(L, ...)
                ${CALLBACK_AFTER}
            };
            ...
            ${BEFORE}
            self->callfunc(arg1, arg2, ....);
            ${AFTER}
            ...
        return 1;
        }
    ]]
    function cls.inject(cppfunc, codes)
        local funcs = type(cppfunc) == "string" and {cppfunc} or cppfunc
        local found
        local function formatCode(code)
            return code and format(code) or nil
        end
        local function applyInject(fi, testname)
            if fi and (fi.CPPFUNC == cppfunc or (testname and fi.LUAFUNC == cppfunc))then
                found = true
                olua.assert(not fi.INJECT.BEFORE, '%s::%s already has before injection', cls.CPPCLS, cppfunc)
                olua.assert(not fi.INJECT.AFTER, '%s::%s already has after injection', cls.CPPCLS, cppfunc)
                olua.assert(not fi.INJECT.CALLBACK_BEFORE, '%s::%s already has callback before injection', cls.CPPCLS, cppfunc)
                olua.assert(not fi.INJECT.CALLBACK_AFTER, '%s::%s already has callback after injection', cls.CPPCLS, cppfunc)
                fi.INJECT.BEFORE = formatCode(codes.BEFORE)
                fi.INJECT.AFTER = formatCode(codes.AFTER)
                fi.INJECT.CALLBACK_BEFORE = formatCode(codes.CALLBACK_BEFORE)
                fi.INJECT.CALLBACK_AFTER = formatCode(codes.CALLBACK_AFTER)
            end
        end

        for _, v in ipairs(funcs) do
            cppfunc = v
            for _, arr in ipairs(cls.FUNCS) do
                for _, fi in ipairs(arr) do
                    applyInject(fi)
                end
            end
            for _, pi in ipairs(cls.PROPS) do
                applyInject(pi.GET)
                applyInject(pi.SET)
            end
            for _, vi in ipairs(cls.VARS) do
                applyInject(vi.GET, true)
                applyInject(vi.SET, true)
            end
        end

        olua.assert(found, 'function not found: %s::%s', cls.CPPCLS, cppfunc)
    end

    function cls.alias(func, aliasname)
        local funcs = {}
        for _, arr in ipairs(cls.FUNCS) do
            for _, fi in ipairs(arr) do
                if fi.LUAFUNC == func then
                    funcs[#funcs + 1] = setmetatable({LUAFUNC = assert(aliasname)}, {__index = fi})
                end
            end
            if #funcs > 0 then
                cls.FUNCS[#cls.FUNCS + 1] = funcs
                return
            end
        end

        error('func not found: ' .. func)
    end

    --[[
        {
            TAG_MAKER    -- make callback key
            TAG_MODE     -- how to store or remove function
            TAG_STORE    -- where to store or remove function
            CALLONCE     -- remove function after called
            REMOVE       -- remove function
        }

        TAG: .callback#[id++]@tag

        userdata.uservalue {
            .callback#0@click = clickfunc1,
            .callback#1@click = clickfunc2,
            .callback#2@remove = removefunc,
        }

        remove all callback:
            {TAG_MAKER = "", TAG_MODE = "OLUA_CALLBACK_TAG_WILDCARD", REMOVE = true}

        remove click callback:
            {TAG_MAKER = "click", TAG_MODE = "OLUA_CALLBACK_TAG_ENDWITH", REMOVE = true}

        add new callback:
            {TAG_MAKER = 'click', TAG_MODE = "OLUA_CALLBACK_TAG_NEW"}

        replace previous callback:
            {TAG_MAKER = 'click', TAG_MODE = "OLUA_CALLBACK_TAG_REPLACE"}
    ]]
    function cls.callback(opt)
        cls.FUNCS[#cls.FUNCS + 1] = parseFunc(cls, nil, table.unpack(opt.FUNCS))
        for i, v in ipairs(cls.FUNCS[#cls.FUNCS]) do
            v.CALLBACK_OPT = opt
            v.CALLBACK_OPT = setmetatable({}, {__index = opt})
            if type(v.CALLBACK_OPT.TAG_MAKER) == 'table' then
                v.CALLBACK_OPT.TAG_MAKER = assert(v.CALLBACK_OPT.TAG_MAKER[i])
            end
            if type(v.CALLBACK_OPT.TAG_MODE) == 'table' then
                v.CALLBACK_OPT.TAG_MODE = assert(v.CALLBACK_OPT.TAG_MODE[i])
            end
        end
    end

    function cls.var(name, declstr)
        local readonly, static
        local rawstr = declstr
        declstr, readonly = string.gsub(declstr, '@readonly *', '')
        declstr = string.gsub(declstr, '[; ]*$', '')
        declstr, static = string.gsub(declstr, '^ *static *', '')

        olua.message(declstr)

        local ARGS = parseArgs(cls, '(' .. declstr .. ')')
        name = name or ARGS[1].VARNAME

        -- variable is callback?
        local CALLBACK_OPT_GET
        local CALLBACK_OPT_SET
        if ARGS[1].CALLBACK.ARGS then
            CALLBACK_OPT_SET = {
                TAG_MAKER = 'olua_makecallbacktag("' .. name .. '")',
                TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
            }
            CALLBACK_OPT_GET = {
                TAG_MAKER = 'olua_makecallbacktag("' .. name .. '")',
                TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
            }
        end

        -- make getter/setter function
        cls.VARS[#cls.VARS + 1] = {
            VARNAME = assert(name),
            GET = {
                LUAFUNC = name,
                CPPFUNC = 'get_' .. ARGS[1].VARNAME,
                VARNAME = ARGS[1].VARNAME,
                INJECT = {},
                DECLFUNC = rawstr,
                RET = {
                    NUM = 1,
                    TYPE = ARGS[1].TYPE,
                    DECLTYPE = ARGS[1].DECLTYPE,
                    ATTR = {},
                },
                STATIC = static > 0,
                VARIABLE = true,
                ARGS = {},
                INDEX = 0,
                CALLBACK_OPT = CALLBACK_OPT_GET,
            },
            SET = {
                LUAFUNC = name,
                CPPFUNC = 'set_' .. ARGS[1].VARNAME,
                VARNAME = ARGS[1].VARNAME,
                INJECT = {},
                STATIC = static > 0,
                DECLFUNC = rawstr,
                RET = {
                    NUM = 0,
                    TYPE = olua.typeinfo('void', cls),
                    ATTR = {},
                },
                VARIABLE = true,
                ARGS = ARGS,
                INDEX = 0,
                CALLBACK_OPT = CALLBACK_OPT_SET,
            },
        }

        if readonly > 0 then
            cls.VARS[#cls.VARS].SET = nil
        end
    end

    function cls.vars(vars)
        for declvar in string.gmatch(vars, '[^\n\r]+') do
            declvar = string.gsub(declvar, '^ *', '')
            if #declvar > 0 and not string.find(declvar, '^ *//') then
                cls.var(nil, declvar)
            end
        end
    end

    function cls.prop(name, get, set)
        assert(not string.find(name, '[^_%w]+'), name)
        cls.PROPS[#cls.PROPS + 1] = parseProp(cls, name, get, set)
    end

    function cls.props(props)
        for declprop in string.gmatch(props, '[^\n\r]+') do
            declprop = string.gsub(declprop, '^ *', '')
            if #declprop > 0 and not string.find(declprop, '^ *//') then
                cls.prop(string.match(declprop, '[%w_]+'))
            end
        end
    end

    function cls.const(name, value)
        local tv = type(value)
        assert(not string.find(name, '[^_%w]+'), name)
        assert(tv == "boolean" or tv == "number" or tv == "string", tv)
        cls.CONSTS[#cls.CONSTS + 1] = {
            CONST_NAME = assert(name),
            CONST_VALUE = value,
            CONST_TYPE = tv == "number" and (math.type(value)) or tv,
        }
    end

    function cls.enum(name, value, type)
        cls.ENUMS[#cls.ENUMS + 1] = {
            ENUM_NAME = name,
            ENUM_VALUE = value or (cls.CPPCLS .. '::' .. name),
            ENUM_TYPE = type,
        }
    end

    function cls.enums(enums)
        for declenum in string.gmatch(enums, '[^\n\r]+') do
            local name, value = string.match(declenum, '([^ ]+) *= *([^ ]+)')
            if not name then
                name = string.match(declenum, '[%w:_]+')
            elseif not string.find(value, cls.CPPCLS) then
                value = cls.CPPCLS .. '::' .. value
            end
            if name then
                cls.enum(name, value)
            end
        end
    end

    return cls
end

function olua.typecast(type, rawtype)
    if type.DECLTYPE ~= type.CPPCLS then
        return string.format("(%s)", rawtype and type.CPPCLS or type.DECLTYPE)
    else
        return ""
    end
end

function olua.pointercast(type)
    return olua.isvaluetype(type) and '' or '&'
end

function olua.toluacls(cppcls)
    local ti = typeinfo_map[cppcls .. ' *'] or typeinfo_map[cppcls]
    assert(ti, 'type not found: ' .. cppcls)
    return ti.LUACLS
end

function olua.topath(cppcls)
    return string.gsub(cppcls, '[.:]+', '_')
end

local valuetype = {
    ['bool'] = true,
    ['const char *'] = true,
    ['std::string'] = true,
    ['std::function'] = true,
    ['lua_Number'] = true,
    ['lua_Integer'] = true,
    ['lua_Unsigned'] = true,
}

-- enum has cpp cls, but declared as lua_Unsigned
function olua.isvaluetype(ti)
    return valuetype[ti.DECLTYPE]
end

function olua.convfunc(ti, fn)
    return string.gsub(ti.CONV_FUNC, '[$]+', fn)
end

function olua.typedef(typeinfo)
    for tn in string.gmatch(typeinfo.CPPCLS, '[^\n\r]+') do
        local ti = setmetatable({}, {__index = typeinfo})
        tn = prettyTypename(tn)
        ti.CPPCLS = tn
        ti.DECLTYPE = ti.DECLTYPE or tn
        typeinfo_map[tn] = ti
        typeinfo_map['const ' .. tn] = ti
    end
end

function olua.typeconv(ci)
    local func = "push|check|pack|unpack|opt|is"
    ci.PROPS = {}
    for str in string.gmatch(assert(ci.DEF, 'no DEF'), '[^\n\r]+') do
        olua.message(str)

        local tn, attr, varname, default
        attr, str = parseAttr(str)
        
        if str and #str > 0 then
            tn, attr, str = parseType(str)
            varname, default = string.match(str, '^([^ ]+) *= *([^ ,;]*)')
            if not varname then
                varname = string.match(str, '^ *[^ ,;]+')
            end
        end
        if tn then
            varname = prettyTypename(varname)
            ci.PROPS[#ci.PROPS + 1] = {
                TYPE = olua.typeinfo(tn),
                VARNAME = varname,
                LUANAME = string.gsub(varname, '^_*', ''),
                DEFAULT = default,
                ATTR = attr,
            }
        end
    end

    ci.FUNC = {IS = true}
    for f in string.gmatch(func, '[^|]+') do
        ci.FUNC[string.upper(f)] = true
    end

    local ti = typeinfo_map[ci.CPPCLS] or typeinfo_map[ci.CPPCLS .. ' *']
    olua.assert(ti, "class not found: %s", ci.CPPCLS)
    if ti.VARS and ti.VARS > 1 then
        ci.FUNC['ISPACK'] = true
    else
        ci.FUNC['UNPACK'] = nil
        ci.FUNC['PACK'] = nil
    end
    
    return ci
end

return olua