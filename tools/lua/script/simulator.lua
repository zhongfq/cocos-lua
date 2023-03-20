local lfs = require "lfs"

local pattern = {}

local dummy_str = '<dummy str>'

local function func_str()
    return "<proxy table>"
end

local function func_num ()
    return 1, 1, 1, 1
end

local function func ()
    return setmetatable({}, {
        __index = func,
        __tostring = func_str,
        __call = func
    })
end

local function REG(classname, impl)
    if classname:find('^[%^]') then
        pattern[classname] = true
    else
        package.preload[classname] = impl or func
    end
end

REG 'base64'
REG 'openssl'

REG 'cclua.photo'
REG 'cclua.downloader'
REG 'cclua.preferences'
REG 'cclua.microphone'
REG('cclua.window', function ()
    return setmetatable({
        getFrameSize = func_num,
        getDesignSize = func_num,
        getVisibleBounds = func_num,
    }, {__index = func})
end)
REG('cclua.runtime', function ()
    return setmetatable({
        on = false,
        once = false,
        off = false,
        dispatch = false,
        useMaxFrameRate = false,
        load = function (name)
            printf("module '%s' is not available", name)
            local module = setmetatable({}, {__index = function (_, f)
                return function ()
                    printf("function '%s.%s' not supported", name, f)
                end
            end})
            package.loaded[name] = module
            return module
        end
    }, {__index = func})
end)
REG('cclua.timer', function ()
    return setmetatable({
        new = false,
    }, {__index = func})
end)
REG('cclua.filesystem', function ()
    return setmetatable({
        dir = false,
        localPath = false,
        exist = function () end,
        sdCardDirectory = dummy_str,
        documentDirectory = dummy_str,
        cacheDirectory = dummy_str,
        tmpDirectory = dummy_str,
        writablePath = dummy_str,
    }, {__index = func})
end)

local _require = require

local function has_file(path)
    path = path:gsub('%.', '/')
    for v in string.gmatch(package.path, '[^;]+') do
        local f = v:gsub('%?', path)
        local attr = lfs.attributes(f)
        if attr and attr.mode == 'file' then
            return true
        end
    end
    return false
end

function require(path)
    if package.loaded[path] then
        return package.loaded[path]
    end

    if has_file(path) then
        return _require(path)
    end

    if not package.preload[path] then
        for v in pairs(pattern) do
            if string.find(path, v) then
                package.loaded[path] = setmetatable({}, getmetatable(func()))
                return require(path)
            end
        end
    end

    return _require(path)
end

REG '^olua%.'
REG '^cc%.'
REG '^ccb%.'
REG '^ccui%.'
REG '^fgui%.'
REG '^cclua%.'
REG '^swf%.'

return {
    REG = REG
}