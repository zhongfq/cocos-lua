function mapref_return_value(REFNAME, WHERE, isarr)
    WHERE = WHERE or 1
    if isarr then
        return {
            AFTER = format_snippet [[
                olua_maprefarray(L, ${WHERE}, "${REFNAME}", -1);
            ]]
        }
    else
        return {
            AFTER = format_snippet [[
                olua_mapref(L, ${WHERE}, "${REFNAME}", -1);
            ]]
        }
    end
end

function mapref_arg_value(REFNAME, WHERE, OBJ)
    WHERE = WHERE or 1
    OBJ = OBJ or 2
    return {
        AFTER = format_snippet [[
            olua_mapref(L, ${WHERE}, "${REFNAME}", ${OBJ});
        ]]
    }
end

function mapunref_arg_value(REFNAME, WHERE, OBJ)
    WHERE = WHERE or 1
    OBJ = OBJ or 2
    return {
        AFTER = format_snippet [[
            olua_mapunref(L, ${WHERE}, "${REFNAME}", ${OBJ});
        ]]
    }
end

function mapunref_all(REFNAME, WHERE)
    WHERE = WHERE or 1
    return {
        AFTER = format_snippet [[
            olua_unrefall(L, ${WHERE}, "${REFNAME}");
        ]]
    }
end

function mapunef_by_compare(REFNAME, WHERE)
    WHERE = WHERE or 1
    return {
        BEFORE = format_snippet [[
            xlua_startcmpunref(L, ${WHERE}, "${REFNAME}");
        ]],
        AFTER = format_snippet [[
            xlua_endcmpunref(L, ${WHERE}, "${REFNAME}");
        ]]
    }
end

function mapref_arg_value_and_mapunef_by_compare(REFNAME, WHERE, OBJ)
    WHERE = WHERE or 1
    OBJ = OBJ or 2
    return {
        BEFORE = format_snippet [[
            xlua_startcmpunref(L, ${WHERE}, "${REFNAME}");
        ]],
        AFTER = format_snippet [[
            xlua_endcmpunref(L, ${WHERE}, "${REFNAME}");
            olua_mapref(L, ${WHERE}, "${REFNAME}", ${OBJ});
        ]]
    }
end