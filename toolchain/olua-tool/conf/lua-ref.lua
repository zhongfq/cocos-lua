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
        BEFORE = format_snippet [[
            olua_mapref(L, ${WHERE}, "${REFNAME}", ${OBJ});
        ]]
    }
end

function mapunref_arg_value(REFNAME, WHERE, OBJ)
    WHERE = WHERE or 1
    OBJ = OBJ or 2
    return {
        BEFORE = format_snippet [[
            olua_mapunref(L, ${WHERE}, "${REFNAME}", ${OBJ});
        ]]
    }
end

function mapunref_all(REFNAME, WHERE)
    WHERE = WHERE or 1
    return {
        BEFORE = format_snippet [[
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
            olua_mapref(L, ${WHERE}, "${REFNAME}", ${OBJ});
            xlua_startcmpunref(L, ${WHERE}, "${REFNAME}");
        ]],
        AFTER = format_snippet [[
            xlua_endcmpunref(L, ${WHERE}, "${REFNAME}");
        ]]
    }
end

function mapref_combo(...)
    local BEFORES = {}
    local AFTERS = {}
    for _, v in ipairs({...}) do
        if v.BEFORE then
            BEFORES[#BEFORES + 1] = v.BEFORE
        end
        if v.AFTER then
            AFTERS[#AFTERS + 1] = v.AFTER
        end
    end
    return {
        BEFORE = #BEFORES > 0 and table.concat(BEFORES, '\n') or nil,
        AFTER = #AFTERS > 0 and table.concat(AFTERS, '\n') or nil,
    }
end