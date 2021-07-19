local M = {debug = false}

M.OS = io.popen('uname'):read("*l")
M.OS = (M.OS == 'Darwin') and 'osx' or (M.OS == 'Linux' and 'linux' or 'win32')

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

function M.format(expr, indent)
    expr = string.gsub(expr, '[\n\r]', '\n')
    expr = string.gsub(expr, '^[\n]*', '') -- trim head '\n'
    expr = string.gsub(expr, '[ \n]*$', '') -- trim tail '\n' or ' '

    local space = string.match(expr, '^[ ]*')
    indent = string.rep(' ', indent or 0)
    expr = string.gsub(expr, '^[ ]*', '')  -- trim head space
    expr = string.gsub(expr, '\n' .. space, '\n' .. indent)
    expr = indent .. expr
    
    local function eval(expr)
        return string.gsub(expr, "([ ]*)(${[%w_.]+})", function (indent, str)
            local key = string.match(str, "[%w_]+")
            local level = 1
            local filePath
            -- search caller file path
            while true do
                local info = debug.getinfo(level, 'S')
                if info then
                    if info.source == "=[C]" then
                        level = level + 1
                    else
                        filePath = filePath or info.source
                        if filePath ~= info.source then
                            break
                        else
                            level = level + 1
                        end
                    end
                else
                    break
                end
            end
            -- search in the functin local value
            local value = lookup(level + 1, key) or _G[key]
            for field in string.gmatch(string.match(str, "[%w_.]+"), '[^.]+') do
                if not value then
                    break
                end
                if field ~= key then
                    value = value[field]
                end
            end
            if value == nil then
                error("value not found for '" .. str .. "'")
            else
                -- indent the value if value has multiline
                if type(value) == 'table' and value.tostring then
                    value = value:tostring()
                end
                value = string.gsub(value, '[\n]*$', '')
                return indent .. string.gsub(tostring(value), '\n', '\n' .. indent)
            end
        end)
    end

    expr = eval(expr)
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

function M.realpath(path)
    path = M.format(path)
    if not (M.OS == 'osx' or M.OS == 'linux') then
        if path == '`pwd`' then
            return '.'
        else
            return path
        end
    else
        local file = io.popen('realpath ' .. path)
        local data = file:read("*l")
        file:close()
        return data
    end
end

function M.execute(cmd)
    cmd = M.format(cmd)
    if M.debug then
        print('execute: ' .. cmd)
    end
    os.execute(cmd)
end

function M.list(dir, pattern)
    local f = io.popen(string.format('cd %s && find -L . -name "%s"', dir, pattern or "*.*"))
    local arr = {}
    for path in string.gmatch(f:read("*a"), '[^\n\r]+') do
        path = string.gsub(path, '%./', '')
        if string.find(path, '[^./\\]+%.[^.]+$') then
            arr[#arr + 1] = path
        end
    end
    return arr
end

function M.read(path)
    local f = assert(io.open(path, 'r'), path)
    local data = f:read('*a')
    if M.debug then
        print('read:', path)
    end
    f:close()
    return data
end

function M.write(path, data)
    local f = assert(io.open(path, 'w'), path)
    if M.debug then
        print('write:', path)
    end
    f:write(data)
    f:close()
end

function M.replace(path, pattern, repl)
    local flag = M.DEBUG
    M.DEBUG = false
    path = M.format(path)
    repl = M.format(repl)
    local data = M.read(path)
    data = string.gsub(data, pattern, repl)
    M.write(path, data)
    M.DEBUG = flag
end

return M