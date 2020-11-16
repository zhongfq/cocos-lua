local class         = require "xgame.class"
local util          = require "xgame.util"
local filesystem    = require "xgame.filesystem"
local LoadTask      = require "xgame.LoadTask"
local plist         = require "xgame.plist"
local Event         = require "xgame.event.Event"
local Dispatcher    = require "xgame.Dispatcher"
local UIPackage     = require "fgui.UIPackage"

local EVENT_RESULT = "result"

local M = {loaders = {}}

local textureCache = require("cc.Director").instance.textureCache
local spriteFrameCache = require("cc.SpriteFrameCache").instance
local trace = util.trace('[loader]')
local cache = setmetatable({}, {__mode = 'v'})

local AssetObject = class('AssetObject', Dispatcher)

function AssetObject:ctor(url)
    self.url = url
    self.path = filesystem.localCachePath(url)
    self.status = 'unknown'
    self.type = string.lower(string.match(url, '%.%w+$'))
    self.loader = M.loaders[self.type] or M.loader['*']
end

function AssetObject:startLoad()
    local task = LoadTask.new(self.url)
    self.status = 'loading'
    task:addListener(Event.COMPLETE, function ()
        if self.status == 'loading' then
            self.status = 'loadOk'
            self.loader.load(self)
        end
        self:dispatch(EVENT_RESULT)
    end)
    task:addListener(Event.IOERROR, function ()
        if self.status == 'loading' then
            self.status = 'loadNo'
        end
        self:dispatch(EVENT_RESULT)
    end)
    task:start()
end

function AssetObject:reload()
    self.loader.reload(self)
end

function AssetObject:unload()
    if self.status ~= 'unload' then
        self.status = 'unload'
        self.loader.unload(self)
    end
end

function AssetObject:__gc()
    self:unload()
end

function M.register(suffix)
    local loader = {
        load = function () end,
        reload = function () end,
        unload = function () end,
    }
    for name in string.gmatch(suffix, '[^; ]+') do
        M.loaders[name] = loader
    end
    return loader
end

function M.load(url, callback)
    local assetRef = cache[url]
    if not url or #url == 0 then
        error('url is nil or empty')
    end
    if not assetRef then
        assetRef = AssetObject.new(url)
        cache[url] = assetRef
    end
    if assetRef.status == 'loading' or assetRef.status == 'unknown' then
        assetRef:addListener(EVENT_RESULT, function ()
            assetRef:removeListener(EVENT_RESULT, util.callee())
            if callback then
                callback(assetRef.status == 'loadOk')
            end
        end)
    elseif callback then
        callback(assetRef.status == 'loadOk')
    end
    if assetRef.status == 'unknown' then
        assetRef:startLoad()
    end
    return assetRef
end

function M.unload(url)
    local assetRef = cache[url]
    if assetRef then
        assetRef:unload()
        cache[url] = nil
    end
end

function M.reload(url)
    local assetRef = cache[url]
    if assetRef then
        assetRef:reload()
    end
end

local function shortPath(path)
    return filesystem.shortPath(path, 80)
end

-- default
M.register('*')

-- jpg & png
local ImageLoader = M.register('.jpg;.png')

function ImageLoader:reload()
    if textureCache:getTextureForKey(self.path) then
        textureCache:reloadTexture(self.path)
        trace('reload image: %s', shortPath(self.url))
    end
end

function ImageLoader:unload()
    textureCache:removeTextureForKey(self.path)
    trace('unload image: %s', shortPath(self.url))
end

-- .plist
local PlistLoader = M.register('.plist')

function PlistLoader:load()
    if not spriteFrameCache:isSpriteFramesWithFileLoaded(self.path) then
        local data = plist.parse(filesystem.read(self.path))
        self.imagePath = string.gsub(self.path, "[^/]+$", data.metadata.textureFileName)
        self.spriteFrames = data.frames

        spriteFrameCache:addSpriteFramesWithFile(self.path)
        trace("load plist: %s", shortPath(self.url))
        for name in pairs(self.spriteFrames) do
            self.spriteFrames[name] = spriteFrameCache:getSpriteFrameByName(name)
        end
    end
end

function PlistLoader:unload()
    spriteFrameCache:removeSpriteFramesFromFile(self.path)
    textureCache:removeTextureForKey(self.imagePath)
    trace("unload plist: %s", shortPath(self.url))
end

-- fgui
local FUILoader = M.register('.fui')

function FUILoader:load()
    local rawpath = string.gsub(self.path, '.fui$', '')
    local pkg = UIPackage.addPackage(rawpath)
    if not pkg then
        error("can't load '" .. self.url .. "'")
    end
    trace('load fgui: %s', self.url)
end

function FUILoader:unload()
    local rawpath = string.gsub(self.path, '.fui$', '')
    UIPackage.removePackage(rawpath)
    trace('unload fgui: %s', self.url)
end

return M