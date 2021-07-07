local M = {}

local print = print
local string = string
local table = table
local xpcall = xpcall

function M.getUpValues(func)
    local u = {}
    local i = 0
    while true do
        i = i + 1
        local key, value = debug.getupvalue(func, i)
        if key then
            u[key] = value
        else
            break
        end
    end

    return u
end

function M.createTag(name)
    return setmetatable({}, {__tostring = function () return name end})
end

function M.callee()
    return debug.getinfo(2, "f").func
end

function M.hook(obj, method, callback)
    local fn = assert(obj[method], method)
    assert(callback)
    obj[method] = function (...)
        fn(...)
        callback(obj, select(2, ...))
    end
end

function M.hookOnce(obj, method, callback)
    local fn = assert(obj[method], method)
    assert(callback)
    obj[method] = function (...)
        fn(...)
        callback(obj, select(2, ...))
        obj[method] = fn
    end
end

function M.trace(prefix)
    return function(fmt, ...)
        xpcall(function (...)
            print(string.format("%s " .. fmt, prefix, ...))
        end, __TRACEBACK__, ...)
    end
end

function M.printf(...)
    return print(string.format(...))
end

function M.compareVersion(v1, v2)
    local function toIntVersion(v)
        local p1, p2, p3 = string.match(v, "(%d+)%.(%d+)%.(%d+)")
        if p1 then
            return p1 * 1000000 + p2 * 1000 + p3
        else
            return 0
        end
    end
    return toIntVersion(v1) - toIntVersion(v2)
end

function M.dump(root, ...)
    local tbl = {}
    local filter = {[root] = tostring(root)}
    for _, v in ipairs({...}) do
        filter[v] = tostring(v)
    end
    local function _dump(t, name, space)
        space = space .. "  "
        for k, v in pairs(t) do
            if filter[v] then
                table.insert(tbl, space .. tostring(k) .. " = " .. filter[v])
            elseif filter[v] or type(v) ~= "table" then
                table.insert(tbl, space .. tostring(k) .. " = " .. tostring(v))
            else
                filter[v] = name .. "." .. tostring(k)
                table.insert(tbl, space .. tostring(k) .. " = {")
                _dump(v, name .. "." .. tostring(k),  space)
                table.insert(tbl, space .. "}")
            end
        end
    end

    table.insert(tbl, "{")
    _dump(root, "", "")
    table.insert(tbl, "}")

    return table.concat(tbl, "\n")
end

function M.dumpUserValue(obj)
    print("uservalue(" .. tostring(obj) .. ') ' .. M.dump(debug.getuservalue(obj) or {}))
end

return M