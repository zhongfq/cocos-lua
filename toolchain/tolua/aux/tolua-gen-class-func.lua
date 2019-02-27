--[[
static int _runtime_doSomething(lua_State *L)
{
    arg1_type arg1 = xluacv_to_xxx(L, idx1);
    arg2_type arg1 = xluacv_to_xxx(L, idx2);
    argN_type argN = (argN_type)xluacv_to_object(L, idxN, classname)

    ret_type ret = xgame::runtime::doSomething(arg1, arg2, argN);
    xluacv_push_xxx(ret);

    return 1;
}
]]

function gen_class_func(cls, fi, write)
    local template = [[
        static int _${CLASS_PATH}_${FUNC}(lua_State *L)
        {
            ${LUA_SETTOP}
            ${ARGS_STATEMENT}
            ${RET_STATEMENT}${CALLER}${FUNC}(${ARGS});
            ${PUSH_RET}
            return ${NUM_RET};
        }
    ]]

    -- TODO: lua_settop(L, arg + 1)

    local CLASS_PATH = class_path(cls.CLASS)
    local FUNC = fi.FUNC
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
        ARGS_STATEMENT[#ARGS_STATEMENT + 1] = "//TODO: arg1"
    end

    for i, ai in ipairs(fi.ARGS) do
        idx = idx + 1
        ARGS[#ARGS + 1] = "arg" .. i

        local DECL_TYPE = ai.DECL_TYPE
        local TYPE = ai.TYPE.NAME
        local ARG_N = i
        local TO_ARG = ai.TYPE.TO
        local IDX = idx
        ARGS_STATEMENT[#ARGS_STATEMENT + 1] = format_snippet([[
            ${DECL_TYPE} arg${ARG_N} = (${TYPE})${TO_ARG}(L, ${IDX});
        ]])
    end

    LUA_SETTOP = string.format(LUA_SETTOP, TOTAL_ARGS)

    if fi.RETURN.NUM > 0 then
        RET_STATEMENT = string.format("%s ret = (%s)",
            fi.RETURN.DECL_TYPE, fi.RETURN.TYPE.NAME)
        PUSH_RET = string.format("%s(L, ret);", assert(fi.RETURN.TYPE.PUSH))
    end

    ARGS_STATEMENT = table.concat(ARGS_STATEMENT, "\n")
    ARGS = table.concat(ARGS, ", ")

    write(format_snippet(template))
end