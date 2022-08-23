-- runtime info
local runtime = require "cclua.runtime"
runtime.printFeatures()

-- add 3th directory
package.path = 'src/cclua/3rd/?.lua;' .. package.path

-- printf
do
    local _format = string.format
    local _print = print
    function printf(...)
        _print(_format(...))
    end
end

-- errorf
do
    local _format = string.format
    local _error = error
    function errorf(...)
        _error(_format(...))
    end
end

-- extern cclua
do
    local function import(name, path)
        local f, msg = loadfile(path)
        if not f then
            print('[NO] import ' .. path)
            error(msg)
        end
        local result = f()
        if package.loaded[name] ~= result then
            errorf("error loading module '%s' from '%s'", name, path)
        end
    end

    import('cclua.luaj', 'src/cclua/luaj.lua')
    import('cclua.luaoc', 'src/cclua/luaoc.lua')
    import('cclua.preferences', 'src/cclua/preferences.lua')
    import('cclua.timer', 'src/cclua/timer.lua')
    import('cclua.window', 'src/cclua/window.lua')
    import('cclua.runtime', 'src/cclua/runtime.lua')
    import('cclua.filesystem', 'src/cclua/filesystem.lua')
    import('cclua.downloader', 'src/cclua/downloader.lua')
    import('cclua.photo', 'src/cclua/photo.lua')
    import('cclua.microphone', 'src/cclua/microphone.lua')
    import('cclua.bugly', 'src/cclua/bugly.lua')

    -- plugin
    import('cclua.plugin.alipay', 'src/cclua/plugin/alipay.lua')
    import('cclua.plugin.apple', 'src/cclua/plugin/apple.lua')
    import('cclua.plugin.huawei', 'src/cclua/plugin/huawei.lua')
    import('cclua.plugin.janalytics', 'src/cclua/plugin/janalytics.lua')
    import('cclua.plugin.jauth', 'src/cclua/plugin/jauth.lua')
    import('cclua.plugin.jpush', 'src/cclua/plugin/jpush.lua')
    import('cclua.plugin.oppo', 'src/cclua/plugin/oppo.lua')
    import('cclua.plugin.talkingdata', 'src/cclua/plugin/talkingdata.lua')
    import('cclua.plugin.vivo', 'src/cclua/plugin/vivo.lua')
    import('cclua.plugin.wechat', 'src/cclua/plugin/wechat.lua')
end

require "cclua.cclua"