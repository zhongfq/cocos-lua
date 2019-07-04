local OS = io.popen('uname'):read("*l")
OS = (OS == 'Darwin') and 'osx' or (OS == 'Linux' and 'linux' or 'win32')

if OS == 'osx' then
    package.cpath = "../usr/osx/lib/lua/?.so;" .. package.cpath
elseif OS == 'linux' then
    package.cpath = "../usr/linux/lib/lua/?.so;" .. package.cpath
else
    error('TODO')
end

function write(path, content)
    local file = io.open(path, 'r')
    if file then
        local flag = file:read("*a") == content
        file:close()
        if flag then
            print("up-to-date:", path)
            return
        end
    end

    print("write:", path)

    local file = io.open(path, "w")
    assert(file, path)
    file:write(content)
    file:flush()
    file:close()
end

function exist(path)
    local f = io.open(path, 'r')
    if f then
        f:close()
    end
    return f ~= nil
end

local function lookup(level, key)
    assert(key and #key > 0, key)

    local value

    for i = 1, 256 do
        local k, v = debug.getlocal(level, i)
        if k == key then
            value = v
        elseif not k then
            break
        end
    end

    if value then
        return value
    end

    local info1 = debug.getinfo(level, 'Sn')
    local info2 = debug.getinfo(level + 1, 'Sn')
    if info1.source == info2.source or
        info1.short_src == info2.short_src then
        return lookup(level + 1, key)
    end
end

function trimlastlf(expr)
    return string.gsub(expr, '[ \n]*$', '')
end

function format(expr, trim, drop_last_lf, indent)
    expr = string.gsub(expr, '[\n\r]', '\n')
    expr = string.gsub(expr, '^[\n\r]*', '')
    if trim then
        local space = string.match(expr, '^[ ]*')
        indent = string.rep(' ', indent or 0)
        expr = string.gsub(expr, '^[ ]*', '')
        expr = string.gsub(expr, '\n' .. space, '\n' .. indent)
        expr = indent .. expr
    end
    if drop_last_lf then
        expr = trimlastlf(expr)
    end
    local function eval(expr)
        return string.gsub(expr, "([ ]*)(${[%w_]+})", function (indent, str)
            local key = string.match(str, "[%w_]+")
            local level = 1
            local last_source
            while true do
                local info = debug.getinfo(level, 'S')
                if info then
                    if info.source == "=[C]" then
                        level = level + 1
                    else
                        last_source = last_source or info.source
                        if last_source ~= info.source then
                            break
                        else
                            level = level + 1
                        end
                    end
                else
                    break
                end
            end
            local value = lookup(level + 1, key) or _G[key]
            if value == nil then
                error("value not found for " .. key)
            else
                return indent .. string.gsub(tostring(value), '\n', '\n' .. indent)
            end
        end)
    end

    local expr = eval(expr)
    while true do
        local s, n = string.gsub(expr, '\n[ ]+\n', '\n\n')
        expr = s
        if n == 0 then
            break
        end
    end

    while true do
        local s, n = string.gsub(expr, '\n\n\n', '\n\n')
        expr = s
        if n == 0 then
            break
        end
    end

    expr = string.gsub(expr, '{\n\n', '{\n')
    expr = string.gsub(expr, '\n\n}', '\n}')
    
    return expr
end

function format_snippet(expr, indent)
    return format(expr, true, true, indent)
end