local M = {}

function __TRACEBACK__(message)
    print(debug.traceback(message))
end

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
    package.preload[classname] = impl or func
end

REG 'base64'
REG 'openssl'

REG 'cclua.luaj'
REG 'cclua.luaoc'
REG 'cclua.bugly'
REG 'cclua.Lame.VBRMode'
REG 'cclua.Lame.MPEGMode'
REG 'cclua.Lame'
REG 'cclua.photo'
REG 'cclua.downloader'
REG 'cclua.QRCode.ECLevel'
REG 'cclua.QRCode.EncodeMode'
REG 'cclua.QRCode'
REG 'cclua.permission'
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

REG 'cclua.Container'
REG 'cclua.SceneNoCamera'

REG 'cclua.plugin.alipay'
REG 'cclua.plugin.apple'
REG 'cclua.plugin.huawei'
REG 'cclua.plugin.janalytics'
REG 'cclua.plugin.jauth'
REG 'cclua.plugin.jpush'
REG 'cclua.plugin.oppo'
REG 'cclua.plugin.talkingdata'
REG 'cclua.plugin.vivo'
REG 'cclua.plugin.wechat'

local _require = require

function require(path)
    if not package.preload[path] and (
        string.find(path, 'cc.', 1, true) == 1 or
        string.find(path, 'ccb.', 1, true) == 1 or
        string.find(path, 'ccui.', 1, true) == 1 or
        string.find(path, 'fgui.', 1, true) == 1 or
        string.find(path, 'swf.', 1, true) == 1)
    then
        return setmetatable({}, getmetatable(func()))
    else
        return _require(path)
    end
end

return M