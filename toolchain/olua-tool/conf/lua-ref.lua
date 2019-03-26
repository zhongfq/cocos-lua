local _ENV = setmetatable({}, {__index = _ENV})

function mapref_return_value(REFNAME)
    return {
        AFTER = format_snippet [[
            olua_mapref(L, 1, "${REFNAME}", -1);
        ]]
    }
end

function mapref_arg_value(REFNAME)
    return {
        AFTER = format_snippet [[
            olua_mapref(L, 1, "${REFNAME}", 2);
        ]]
    }
end

function mapunef_by_compare(REFNAME)
    return {
        BEFORE = format_snippet [[
            xlua_startcmpunref(L, 1, "${REFNAME}");
        ]],
        AFTER = format_snippet [[
            xlua_endcmpunref(L, 1, "${REFNAME}");
        ]]
    }
end

function mapref_arg_value_and_mapunef_by_compare(REFNAME)
    return {
        BEFORE = format_snippet [[
            olua_mapref(L, 1, "${REFNAME}", 2);
            xlua_startcmpunref(L, 1, "${REFNAME}");
        ]],
        AFTER = format_snippet [[
            xlua_endcmpunref(L, 1, "${REFNAME}");
        ]]
    }
end

return _ENV