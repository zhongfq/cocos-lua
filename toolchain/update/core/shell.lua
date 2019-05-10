local M = {}

M.OS = io.popen('uname'):read("*l")
M.OS = (M.OS == 'Darwin') and 'osx' or (M.OS == 'Linux' and 'linux' or 'win32')

package.path = "?.lua;" .. package.path

function M.unuse(...)
    -- avoid vs code lua check
end

function M.addSearchPath(path)
    if not string.find(package.path, path, 1, true) then
        print("add search path: " .. path)
        package.path = path .. "/?.lua;" .. package.path
    end
end

function M.addCSearchPath(path)
    if not string.find(package.cpath, path, 1, true) then
        print("add search path: " .. path)
        package.cpath = path .. "/?.so;" .. package.cpath
    end
end

function M.read(path)
    local file = io.open(path)
    assert(file, "file not found: " .. path)
    local data = file:read("*a")
    file:close()
    return data
end

function M.exist(path)
    if not path then
        return
    end

    local file = io.open(path)
    if file then
        file:close()
    end
    return file ~= nil
end

function M.command(fmt, ...)
    local ESC = "\033"
    local cmd = string.format(fmt, ...)
    local file = io.popen(string.format('%s && echo %s', cmd, ESC))
    local result = file:read("*a")
    file:close()

    local idx = string.find(result, ESC)
    if idx and idx + 1 == #result then
        return string.sub(result, 1, idx - 2) -- trim '\n' 'ESC'
    else
        error("exec cmd error: " .. cmd)
    end
end

function M.md5sum(file)
    if M.OS == "osx" then
        local result = M.command('md5 ' .. file)
        return assert(string.match(result, " = (%w+)"), result)
    else
        local result = M.command('md5sum ' .. file)
        return assert(string.match(result, "^(%w+)"), result)
    end
end

function M.realpath(path)
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

function M.list(dir)
    local f = io.popen(string.format('cd %s && find -L . -name "*.*"', dir))
    local arr = {}
    for path in string.gmatch(f:read("*a"), '[^\n\r]+') do
        path = string.gsub(path, '%./', '')
        if string.find(path, '[^./\\]+%.[^.]+$') then
            arr[#arr + 1] = path
        end
    end
    return arr
end

function M.write(path, content)
    local file = io.open(path, "w")
    file:write(content)
    file:flush()
    file:close()
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

function M.bash(expr, ...)
    if select('#', ...) > 0 then
        expr = string.format(expr, ...)
    end
    local function eval(expr)
        return string.gsub(expr, "([ ]*)(${?[%w_]+}?)", function (indent, str)
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
    
    os.execute(eval(expr))
end

return M