local function gen_snippet_func(cls, fi, write)
    local template = [[
        static int _${CLASS_PATH}_${FUNC}(lua_State *L)
        ${FUNC_SNIPPET}
    ]]
    local CLASS_PATH = class_path(cls.CLASS)
    local FUNC = fi.FUNC
    local FUNC_SNIPPET = fi.FUNC_SNIPPET
    write(format_snippet(template))
end

local function gen_one_func(cls, fi, write, funcidx)
    local template = [[
        static int _${CLASS_PATH}_${FUNC}${FUNC_INDEX}(lua_State *L)
        {
            ${LUA_SETTOP}
            ${ARGS_STATEMENT}
            ${RET_STATEMENT}${CALLER}${FUNC}(${ARGS});
            ${PUSH_RET}
            return ${NUM_RET};
        }
    ]]

    if fi.FUNC_SNIPPET then
        gen_snippet_func(cls, fi, write)
        return
    end

    local CLASS_PATH = class_path(cls.CLASS)
    local FUNC = fi.FUNC
    local FUNC_INDEX = funcidx or ""
    local NUM_RET = fi.RETURN.NUM
    local ARGS_STATEMENT = {}
    local LUA_SETTOP = "lua_settop(L, %d);"
    local RET_STATEMENT = ""
    local CALLER = "self->"
    local PUSH_RET = "";
    local ARGS = {}
    local idx = 0

    local TOTAL_ARGS = #fi.ARGS

    if fi.STATIC then
        CALLER = cls.NATIVE .. '::'
    else
        TOTAL_ARGS = TOTAL_ARGS + 1
        idx = idx + 1
        local ti = get_type_info(cls.NATIVE .. "*")
        local DECL_TYPE = cls.NATIVE
        local ARGS_CLASS = ti.CLASS
        local TO_ARG = ti.TO
        ARGS_STATEMENT[#ARGS_STATEMENT + 1] = format_snippet([[
            ${DECL_TYPE} *self = (${DECL_TYPE} *)${TO_ARG}(L, 1, "${ARGS_CLASS}");
        ]])
    end

    for i, ai in ipairs(fi.ARGS) do
        idx = idx + 1
        ARGS[#ARGS + 1] = "arg" .. i

        local DECL_TYPE = ai.DECL_TYPE
        local TYPE = ai.TYPE.NAME
        local ARG_N = i
        local SPACE = " "
        local TO_ARG = ai.TYPE.TO
        local IDX = idx

        if string.find(DECL_TYPE, '[ *&]$') then
            SPACE = ""
        end

        if ai.VALUE then
            TO_ARG = ai.TYPE.OPT
            local VALUE = ai.VALUE
            ARGS_STATEMENT[#ARGS_STATEMENT + 1] = format_snippet([[
                ${DECL_TYPE}${SPACE}arg${ARG_N} = (${DECL_TYPE})${TO_ARG}(L, ${IDX}, ${VALUE});
            ]])
        else
            ARGS_STATEMENT[#ARGS_STATEMENT + 1] = format_snippet([[
                ${DECL_TYPE}${SPACE}arg${ARG_N} = (${DECL_TYPE})${TO_ARG}(L, ${IDX});
            ]])
        end
    end

    LUA_SETTOP = string.format(LUA_SETTOP, TOTAL_ARGS)

    if fi.RETURN.NUM > 0 then
        local DECL_TYPE = fi.RETURN.DECL_TYPE
        local PUSH = assert(fi.RETURN.TYPE.PUSH, fi.NAME)
        RET_STATEMENT = format_snippet('${DECL_TYPE} ret = (${DECL_TYPE})')
        if fi.RETURN.TYPE.CLASS then
            local ARGS_CLASS = fi.RETURN.TYPE.CLASS
            PUSH_RET = format_snippet('${PUSH}(L, ret, "${ARGS_CLASS}");')
        else
            PUSH_RET = format_snippet('${PUSH}(L, ret);')
        end
    end

    ARGS_STATEMENT = table.concat(ARGS_STATEMENT, "\n")
    ARGS = table.concat(ARGS, ", ")

    write(format_snippet(template))
end

local function get_func_n(fis, n)
    local arr = {}
    for _, v in ipairs(fis) do
        if #v.ARGS == n then
            arr[#arr + 1] = v
        end
    end
    return arr
end

local function gen_test_and_call(cls, fns)
    local CALL_BLOCK = {}

    for fn, fi in ipairs(fns) do
        local FUNC_INDEX = fi.INDEX
        local FUNC = fi.FUNC
        local CLASS_PATH = class_path(cls.CLASS)

        if #fi.ARGS > 0 then
            local TEST_ARGS = {}
            for i, ai in ipairs(fi.ARGS) do
                local IDX = (fi.STATIC and 0 or 1) + i
                local ISA = ai.TYPE.IS
                if ai.CLASS then
                    local ARGS_CLASS = ai.CLASS
                    TEST_ARGS[#TEST_ARGS + 1] = format_snippet([[
                        ${ISA}(L, ${IDX}, "${ARGS_CLASS}")
                    ]])
                else
                    TEST_ARGS[#TEST_ARGS + 1] = format_snippet([[
                        ${ISA}(L, ${IDX})
                    ]])
                end
            end

            TEST_ARGS = table.concat(TEST_ARGS, " && ")

            if fn == #fns then
                CALL_BLOCK[#CALL_BLOCK + 1] = format_snippet([[
                    // if (${TEST_ARGS}) {
                        return _${CLASS_PATH}_${FUNC}${FUNC_INDEX}(L);
                    // }
                ]])
            else
                CALL_BLOCK[#CALL_BLOCK + 1] = format_snippet([[
                    if (${TEST_ARGS}) {
                        return _${CLASS_PATH}_${FUNC}${FUNC_INDEX}(L);
                    }
                ]])
            end
        else
            assert(#fns == 1)
            CALL_BLOCK[#CALL_BLOCK + 1] = format_snippet([[
                return _${CLASS_PATH}_${FUNC}${FUNC_INDEX}(L);
            ]])
        end
    end

    return table.concat(CALL_BLOCK, "\n\n")
end

function gen_multi_func(cls, fis, write)
    local template = [[
        static int _${CLASS_PATH}_${FUNC}(lua_State *L)
        {
            int num_args = lua_gettop(L)${HAS_OBJ};

            ${IF_BLOCK}

            luaL_error(L, "method '${NATIVE}::${FUNC}' not support '%d' arguments", num_args);

            return 0;
        }
    ]]

    local NUM_ARGS = fis.MAX_ARGS
    local NATIVE = cls.NATIVE
    local CLASS_PATH = class_path(cls.CLASS)
    local FUNC = fis[1].FUNC
    local HAS_OBJ = fis[1].STATIC and "" or " - 1"
    local IF_BLOCK = {}

    for _, fi in ipairs(fis) do
        gen_one_func(cls, fi, write, fi.INDEX)
        write('')
    end

    for i = 0, NUM_ARGS do
        local fns = get_func_n(fis, i)
        if #fns > 0 then
            local CUR_ARGS = i
            local TEST_AND_CALL = gen_test_and_call(cls, fns)
            IF_BLOCK[#IF_BLOCK + 1] = format_snippet([[
                if (num_args == ${CUR_ARGS}) {
                    ${TEST_AND_CALL}
                }
            ]])
        end
    end

    IF_BLOCK = table.concat(IF_BLOCK, "\n\n")
    write(format_snippet(template))
end

function gen_class_func(cls, fis, write)
    if #fis == 1 then
        gen_one_func(cls, fis[1], write)
    else
        gen_multi_func(cls, fis, write)
    end
end