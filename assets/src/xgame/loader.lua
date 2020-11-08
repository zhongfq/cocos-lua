local class         = require "xgame.class"
local util          = require "xgame.util"
local filesystem    = require "xgame.filesystem"
local LoadTask      = require "xgame.LoadTask"
local plist         = require "xgame.plist"
local Event         = require "xgame.event.Event"
local Dispatcher    = require "xgame.event.Dispatcher"
local UIPackage     = require "fgui.UIPackage"

local EVENT_RESULT = "result"
local TYPE_FGUI = '.fui'
local TYPE_JPEG = '.jpg'
local TYPE_PNG = '.png'
local TYPE_PLIST = '.plist'

local M = {}

local textureCache = require("cc.Director").instance.textureCache
local spriteFrameCache = require("cc.SpriteFrameCache").instance
local trace = util.trace('[loader]')
local cache = setmetatable({}, {__mode = 'v'})

local AssetObject = class('AssetObject', Dispatcher)

function AssetObject:ctor(path)
    self.path = path
    self.status = 'unknown'
    self.type = string.lower(string.match(path, '%.%w+$'))
end

function AssetObject:startLoad()
    local task = LoadTask.new(self.path)
    self.status = 'loading'
    task:addListener(Event.COMPLETE, function ()
        self.status = 'loadOk'
        self:didLoad()
    end)
    task:addListener(Event.IOERROR, function ()
        self.status = 'loadNo'
        self:didLoad()
    end)
    task:start()
end

function AssetObject:loadFGUI()
    local rawpath = string.gsub(self.path, '.fui$', '')
    local pkg = UIPackage.addPackage(rawpath)
    if not pkg then
        error("can't load '" .. self.path .. "'")
    end
    trace('load fgui: %s', self.path)
end

function AssetObject:unloadFGUI()
    local rawpath = string.gsub(self.path, '.fui$', '')
    UIPackage.removePackage(rawpath)
    trace('unload fgui: %s', self.path)
end

function AssetObject:loadImage()
end

function AssetObject:reloadImage()
    local path = filesystem.localCachePath(self.path)
    if textureCache:getTextureForKey(path) then
        textureCache:reloadTexture(path)
        trace('reload image: %s', self.path)
    end
end

function AssetObject:unloadImage()
    local path = filesystem.localCachePath(self.path)
    textureCache:removeTextureForKey(path)
    trace('unload image: %s', self.path)
end

local function shortPath(path)
    return filesystem.shortPath(path, 60)
end

function AssetObject:loadPlist()
    if not spriteFrameCache:isSpriteFramesWithFileLoaded(self.path) then
        local data = plist.parse(filesystem.read(self.path))
        self.imagePath = string.gsub(self.path, "[^/]+$", data.metadata.textureFileName)
        self.spriteFrames = data.frames

        spriteFrameCache:addSpriteFramesWithFile(self.path)
        trace("load plist: %s", shortPath(self.path))
        for name in pairs(self.spriteFrames) do
            self.spriteFrames[name] = spriteFrameCache:getSpriteFrameByName(name)
        end
    end
end

function AssetObject:unloadPlist()
    spriteFrameCache:removeSpriteFramesFromFile(self.path)
    textureCache:removeTextureForKey(self.imagePath)
    trace("unload plist: %s", shortPath(self.path))
end

function AssetObject:didLoad()
    if self.status == 'loadOk' then
        if self.type == TYPE_FGUI then
            self:loadFGUI()
        elseif self.type == TYPE_JPEG or self.type == TYPE_PNG then
            self:loadImage()
        elseif type == TYPE_PLIST then
            self:loadPlist()
        end
    end
    self:dispatch(EVENT_RESULT)
end


function AssetObject:reload()
    if self.status == 'loadOk' then
        if self.type == TYPE_FGUI then
        elseif self.type == TYPE_JPEG or self.type == TYPE_PNG then
            self:reloadImage()
        elseif type == TYPE_PLIST then
        end
    end
end

function AssetObject:__gc()
    if self.type == TYPE_FGUI then
        self:unloadFGUI()
    elseif self.type == TYPE_JPEG or self.type == TYPE_PNG then
        self:unloadImage()
    elseif type == TYPE_PLIST then
        self:unloadPlist()
    end
end

function M.reload(url)
    local asset = cache[url]
    if asset then
        asset:reload()
    end
end

function M.load(url, callback)
    local asset = cache[url]
    if not asset then
        asset = AssetObject.new(url)
        cache[url] = asset
    end
    if asset.status == 'loading' or asset.status == 'unknown' then
        asset:addListener(EVENT_RESULT, function ()
            asset:removeListener(EVENT_RESULT, util.callee())
            if callback then
                callback(asset.status == 'loadOk')
            end
        end)
    elseif callback then
        callback(asset.status == 'loadOk')
    end
    if asset.status == 'unknown' then
        asset:startLoad()
    end
    return asset
end

return M