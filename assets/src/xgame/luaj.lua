local luaj = require "kernel.luaj"

local cache = {}
local RET_TYPES = {'V', 'Ljava/lang/String;', 'I', 'Z', 'J', 'F', 'D'}
local M = {}

local function append(arr, ...)
    local len = select("#", ...)
    if len == 1 then
        for i, v in ipairs(arr) do
            arr[i] = v .. select(1, ...)
        end
        return arr
    else
        local newarr = {}
        for _, sign in ipairs({...}) do
            for _, v in ipairs(arr) do
                newarr[#newarr + 1] = v .. sign
            end
        end
        return newarr
    end
end

function M.invoke(cls, func, ...)
    local signature = cache[cls .. func]
    if not signature then
        local arr = {""}
        arr = append(arr, '(')
        for _, v in ipairs({...}) do
            local t = type(v)
            if t == "number" then
                arr = append(arr, 'I', 'J', 'F', 'D')
            elseif t == "boolean" then
                arr = append(arr, 'Z')
            elseif t == "function" then
                arr = append(arr, 'I')
            elseif t == "string" then
                arr = append(arr, "Ljava/lang/String;")
            else
                error(t)
            end
        end
        arr = append(arr, ')')

        for _, arg in ipairs(arr) do
            for _, ret in ipairs(RET_TYPES) do
                local testSign = arg .. ret
                if luaj.validate(cls, func, testSign) then
                    signature = testSign
                    cache[cls .. func] = signature
                    break
                end
            end

            if signature then
                break
            end
        end

        if not signature then
            error(string.format('function not found: %s#%s', cls, func))
        end
    end
    return luaj.invoke(cls, func, signature, ...)
end

function M.new(cls)
    return setmetatable({}, {
        __index = function (_, func)
            return function (...)
                return M.invoke(cls, func, ...)
            end
        end
    })
end

return M