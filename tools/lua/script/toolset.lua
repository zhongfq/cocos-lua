local lfs = require "lfs"
local cjson = require "cjson.safe"
local xxtea = require "xxtea"

local toolset = {}

local dir_stack = {}

require "simulator"

toolset.os = package.cpath:find('?.dll') and 'windows' or
    ((io.popen('uname'):read("*l"):find('Darwin')) and 'macos' or 'linux')

-------------------------------------------------------------------------------
-- lua search path
-------------------------------------------------------------------------------
function toolset.add_path(path)
    if not string.find(package.path, path, 1, true) then
        print("add search path: " .. path)
        package.path = path .. "/?.lua;" .. package.path
    end
end

-------------------------------------------------------------------------------
-- version
-------------------------------------------------------------------------------
function toolset.toversion(str)
    local v1, v2, v3 = string.match(str, "(%d+)%.(%d+)%.(%d+)")
    assert(v1, 'invalid version string: ' .. tostring(str))
    return tonumber(v1) * 1000000 + tonumber(v2) * 1000 + tonumber(v3)
end

function toolset.next_version(str)
    local v = toolset.toversion(str) + 1
    return string.format("%d.%d.%d", v // 1000000 % 1000, v // 1000 % 1000, v % 1000)
end

-------------------------------------------------------------------------------
-- io
-------------------------------------------------------------------------------
local function isdir(path)
    local attr = lfs.attributes(path)
    return attr and attr.mode == 'directory'
end

local function isfile(path)
    local attr = lfs.attributes(path)
    return attr and attr.mode == 'file'
end

function toolset.exist(path)
    path = toolset.format(path)
    return lfs.attributes(path)
end

function toolset.pwd()
    return lfs.currentdir()
end

function toolset.cd(dir)
    dir = toolset.format(dir)
    lfs.chdir(dir)
end

function toolset.pushdir(dir)
    dir = toolset.format(dir)
    dir_stack[#dir_stack + 1] = lfs.currentdir()
    lfs.chdir(dir)
end

function toolset.popdir()
    lfs.chdir(dir_stack[#dir_stack])
    dir_stack[#dir_stack] = nil
end

function toolset.link(old, new)
    old = toolset.format(old)
    new = toolset.format(new)
    if toolset.exist(new) then
        os.remove(new)
    end
    if toolset.os == 'windows' then
        local flag = isfile(old) and '' or '/D'
        -- mklink need administrator rights
        toolset.bash(string.format('mklink %s %s %s', flag,
            string.gsub(new, '/', '\\'),
            string.gsub(old, '/', '\\')))
    else
        toolset.bash(string.format('ln -sfn %s %s', old, new))
    end
end

function toolset.realpath(path)
    path = toolset.format(path)
    path = string.gsub(path, '\\', '/')
    if string.find(path, '^/') or string.find(path, ':') then
        return path
    end
    path = string.gsub(path, '^%./', '')
    path = lfs.currentdir() .. '/' .. path
    path = string.gsub(path, '//', '/')
    while true do
        local idx
        path, idx = string.gsub(path, '[^/]+/%.%./', '')
        if idx == 0 then
            break
        end
    end
    return path
end

local function domkdir(dir)
    dir = toolset.format(dir)
    dir = string.gsub(dir, '\\', '/')
    if toolset.os == 'windows' then
        os.execute(string.format('mkdir %s', dir))
    else
        os.execute(string.format('mkdir -p %s', dir))
    end
end

local function docp(from, to)
    if isfile(from) then
        if isdir(to) then
            local name = string.match(from, '[^/]+$')
            lfs.cp(from, to .. '/' .. name)
        else
            lfs.cp(from, to)
        end
    elseif isdir(from) and isdir(to) then
        local arr = toolset.list(from)
        for _, v in ipairs(arr) do
            local dir = string.gsub(v, '/?[^/]+$', '')
            dir = to .. (#dir > 0 and ('/' .. dir) or '')
            if not isdir(dir) then
                domkdir(dir)
            end
            lfs.cp(from .. '/' .. v, to .. '/' .. v)
        end
    elseif isdir(from) then
        error(string.format('file or directory not exist: %s', to))
    else
        error(string.format('file or directory not exist: %s', from))
    end
end

function toolset.cp(from, to)
    from = toolset.format(from)
    to = toolset.format(to)
    print(string.format('cp %s -> %s', from, to))
    from = toolset.realpath(from)
    to = toolset.realpath(to)
    docp(from, to)
end

function toolset.mkdir(dir)
    dir = toolset.format(dir)
    dir = string.gsub(dir, '\\', '/')
    print('mkdir ' .. dir)
    domkdir(dir)
end

local function dormdir(dir)
    for file in lfs.dir(dir) do
        local file_path = dir..'/'..file
        if file ~= "." and file ~= ".." then
            if lfs.attributes(file_path, 'mode') == 'file' then
                os.remove(file_path)
            elseif lfs.attributes(file_path, 'mode') == 'directory' then
                dormdir(file_path)
            end
        end
    end
    lfs.rmdir(dir)
end

function toolset.rmdir(dir)
    dir = toolset.format(dir)
    print('rmdir ' .. dir)
    if isdir(dir) then
        dormdir(dir)
    end
end

function toolset.rm(path)
    path = toolset.format(path)
    print('rm ' .. path)
    os.remove(path)
end

function toolset.read(path, defautl)
    path = toolset.format(path)
    if toolset.exist(path) then
        local file = io.open(path)
        local data = file:read("*a")
        file:close()
        return data
    elseif defautl then
        return defautl
    else
        error('no such file: ' .. tostring(path))
    end
end

function toolset.write(path, content)
    path = toolset.format(path)
    local file = io.open(path, "w")
    file:write(content)
    file:flush()
    file:close()
end

function toolset.read_metadata(path, conf)
    path = toolset.format(path)
    if toolset.exist(path) then
        local data = toolset.read(path)
        return cjson.decode(data) or cjson.decode(xxtea.decrypt(data,
            assert(conf.ENCRYPT_KEY, 'no encrypt key')))
    else
        return {assets = {}, version = '0.0.0'}
    end
end

function toolset.write_metadata(path, data, conf)
    path = toolset.format(path)
    if conf.ENCRYPT_METADATA then
        toolset.write(path, xxtea.encrypt(data,  assert(conf.ENCRYPT_KEY, 'no encrypt key')))
    else
        toolset.write(path, data)
    end
end

function toolset.list(basedir, pattern)
    local arr = {}
    local function list(dir, folder)
        folder = folder or ''
        for name in lfs.dir(dir) do
            if string.find(name, '^[^.]') then
                local attr = lfs.attributes(dir .. '/' .. name)
                if attr.mode == 'file' then
                    local path = folder .. name
                    if not pattern or string.find(path, pattern) then
                        arr[#arr + 1] = path
                    end
                elseif attr.mode == 'directory' then
                    list(dir .. '/' .. name, folder .. name .. '/')
                end
            end
        end
    end
    list(toolset.format(basedir))
    return arr
end

function toolset.bash(expr)
    expr = toolset.format(expr)
    for cmd in string.gmatch(expr, '[^\n\r]+') do
        print("bash: " .. cmd)
    end
    os.execute(expr)
end

-------------------------------------------------------------------------------
-- format args
-------------------------------------------------------------------------------
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

local function eval(line)
    return string.gsub(line, '${[%w_.?]+}', function (str)
        -- search caller file path
        local level = 1
        local path
        while true do
            local info = debug.getinfo(level, 'Sn')
            if info then
                if info.source == "=[C]" then
                    level = level + 1
                else
                    path = path or info.source
                    if path ~= info.source then
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
        local indent = string.match(line, ' *')
        local key = string.match(str, '[%w_]+')
        local opt = string.match(str, '%?+')
        local value = lookup(level + 1, key) or _G[key]
        for field in string.gmatch(string.match(str, "[%w_.]+"), '[^.]+') do
            if not value then
                break
            elseif field ~= key then
                value = value[field]
            end
        end

        if value == nil and not opt then
            error("value not found for '" .. str .. "'")
        end

        -- indent the value if value has multiline
        local prefix, posfix = '', ''
        if type(value) == 'table' then
            local mt = getmetatable(value)
            if mt and mt.__tostring then
                value = tostring(value)
            else
                error("no meta method '__tostring' for " .. str)
            end
        elseif value == nil then
            value = 'nil'
        elseif type(value) == 'string' then
            value = value:gsub('[\n]*$', '')
            if opt then
                value = toolset.trim(value)
                if string.find(value, '[\n\r]') then
                    value = '\n' .. value
                    prefix = '[['
                    posfix =  '\n' .. indent .. ']]'
                    indent = indent .. '    '
                elseif string.find(value, '[\'"]') then
                    value = '[[' .. value .. ']]'
                else
                    value = "'" .. value .. "'"
                end
            end
        else
            value = tostring(value)
        end

        return prefix .. string.gsub(value, '\n', '\n' .. indent) .. posfix
    end)
end

local function doeval(expr)
    local arr = {}
    local idx = 1
    while idx <= #expr do
        local from, to = string.find(expr, '[\n\r]', idx)
        if not from then
            from = #expr + 1
            to = from
        end
        arr[#arr + 1] = eval(string.sub(expr, idx, from - 1))
        idx = to + 1
    end
    return table.concat(arr, '\n')
end

function toolset.trim(expr, indent)
    if type(expr) == 'string' then
        expr = string.gsub(expr, '[\n\r]', '\n')
        expr = string.gsub(expr, '^[\n]*', '') -- trim head '\n'
        expr = string.gsub(expr, '[ \n]*$', '') -- trim tail '\n' or ' '

        local space = string.match(expr, '^[ ]*')
        indent = string.rep(' ', indent or 0)
        expr = string.gsub(expr, '^[ ]*', '')  -- trim head space
        expr = string.gsub(expr, '\n' .. space, '\n' .. indent)
        expr = indent .. expr
    end
    return expr
end

function toolset.format(expr, indent)
    expr = doeval(toolset.trim(expr, indent))

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

return toolset