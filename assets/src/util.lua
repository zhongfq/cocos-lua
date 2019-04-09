local util = {}
local debug = debug
local setmetatable, getmetatable = setmetatable, getmetatable
local type, pairs, print, xpcall = type, pairs, print, xpcall
local math, string, os = math, string, os

function util.time()
    local sec = os.time() % (3600 * 24)
    local h = sec // 3600 + 8
    local m = sec % 3600 // 60
    local s = sec % 60
    return h, m, s
end

function util.getupvalues(func)
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

function util.callee()
    return debug.getinfo(2, "f").func
end

function util.print(fmt, ...)
    xpcall(function (...)
        if DEBUG == nil then
            local h, m, s = util.time()
            print(string.format("[%02d:%02d:%02d] " .. fmt, h, m, s, ...))
        else
            print(string.format(fmt, ...))
        end
    end, function (error)
        print(debug.traceback(error, 2))
    end, ...)
end

function util.dump(root, ...)
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

function util.printdump(root, ...)
    print(util.dump(root, ...))
end

return util
