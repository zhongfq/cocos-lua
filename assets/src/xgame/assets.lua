local filesystem    = require "xgame.filesystem"
local LoadTask      = require "xgame.LoadTask"
local Event         = require "xgame.event.Event"
local UIPackage     = require "fgui.UIPackage"

local cache = setmetatable({}, {__mode = 'v'})

local M = {}

local function loadFGUI(path)
    local proxy = cache[path]
    if proxy then
        return proxy
    end

    local rawpath = string.gsub(path, '.fui$', '')
    local pkg = UIPackage.addPackage(rawpath)
    if not pkg then
        error("can't load '" .. path .. "'")
    end

    print('load fgui asset: ' .. path)

    proxy = setmetatable({}, {__gc = function ()
        print('unload fgui asset: ' .. path)
        UIPackage.removePackage(rawpath)
    end})
    cache[path] = proxy

    return proxy
end

function M.load(path, callback)
    if string.find(path, '^https?://') then
        local loader = LoadTask.new(path)
        loader:addListener(Event.COMPLETE, function ()
            callback(filesystem.localCachePath(path))
        end)
        loader:start()
    elseif string.find(path, '.fui$') then
        return loadFGUI(path)
    end
end

return M