local M = {}

function __TRACEBACK__(message)
    print(debug.traceback(message))
end

M.DUMMY_STR = '<dummy str>'
M.FUNC = function () return M.PROXY end
M.FUNC_STR = function () return "<proxy table>" end
M.FUNC_NUM = function () return 1, 1, 1, 1 end

M.PROXY = setmetatable({}, {
    __index = M.FUNC,
    __tostring = M.FUNC_STR,
    __call = M.FUNC,
})

local function REG(classname, impl)
    package.preload[classname] = impl or M.FUNC
end

REG 'base64'
REG 'cjson'
REG 'md5'

REG('kernel.runtime', function ()
    return setmetatable({
        on = false,
        off = false,
    }, {__index = M.FUNC})
end)
REG('kernel.timer', function ()
    return setmetatable({
        new = false,
    }, {__index = M.FUNC})
end)
REG('kernel.filesystem', function ()
    return setmetatable({
        dir = false,
        localCachePath = false,
        sdCardDirectory = M.DUMMY_STR,
        documentDirectory = M.DUMMY_STR,
        cacheDirectory = M.DUMMY_STR,
        tmpDirectory = M.DUMMY_STR,
        writablePath = M.DUMMY_STR,
    }, {__index = M.FUNC})
end)

local _require = require

function require(path)
    if not package.preload[path] and (
        string.find(path, 'cc.', 1, true) == 1 or
        string.find(path, 'ccb.', 1, true) == 1 or
        string.find(path, 'ccui.', 1, true) == 1 or
        string.find(path, 'fgui.', 1, true) == 1 or
        string.find(path, 'swf.', 1, true) == 1 or
        string.find(path, 'kernel.', 1, true) == 1) then
        return M.PROXY
    else
        return _require(path)
    end
end

return M