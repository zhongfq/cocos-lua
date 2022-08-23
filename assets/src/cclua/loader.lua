local class         = require "cclua.class"
local util          = require "cclua.util"
local runtime       = require "cclua.runtime"
local filesystem    = require "cclua.filesystem"
local LoadTask      = require "cclua.LoadTask"
local plist         = require "cclua.plist"
local Event         = require "cclua.Event"
local Dispatcher    = require "cclua.Dispatcher"
local UIPackage     = require "fgui.UIPackage"

local EVENT_RESULT = "result"

local M = {loaders = {}}

local trace = util.trace('[loader]')
local cache = setmetatable({}, {__mode = 'v'})

local AssetObject = class('AssetObject', Dispatcher)

function AssetObject:ctor(uri)
    self.uri = uri
    self.path = filesystem.localPath(uri)
    self.status = 'unknown'
    self.type = string.lower(string.match(uri, '%.%w+$'))
    self.loader = M.loaders[self.type] or M.loader['*']
end

function AssetObject:startLoad()
    local task = LoadTask.new(self.uri)
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

function M.load(uri, callback)
    local assetRef = cache[uri]
    if not uri or #uri == 0 then
        error('uri is nil or empty')
    end
    assert(string.find(uri, '%.%w+$'), uri)
    if not assetRef then
        assetRef = AssetObject.new(uri)
        cache[uri] = assetRef
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

function M.unload(uri)
    local assetRef = cache[uri]
    if assetRef then
        assetRef:unload()
        cache[uri] = nil
    end
end

function M.reload(uri)
    local assetRef = cache[uri]
    if assetRef then
        assetRef:reload()
    end
end

local function trimPath(path)
    return filesystem.trimPath(path, 80)
end

-- default
M.register('*')

-- jpg & png
local ImageLoader = M.register('.jpg;.png')

function ImageLoader:reload()
    if runtime.textureCache:getTextureForKey(self.path) then
        runtime.textureCache:reloadTexture(self.path)
        trace('reload image: %s', trimPath(self.uri))
    end
end

function ImageLoader:unload()
    runtime.textureCache:removeTextureForKey(self.path)
    trace('unload image: %s', trimPath(self.uri))
end

-- .plist
local PlistLoader = M.register('.plist')

function PlistLoader:load()
    if not runtime.spriteFrameCache:isSpriteFramesWithFileLoaded(self.path) then
        local data = plist.parse(filesystem.read(self.path))
        self.imagePath = string.gsub(self.path, "[^/]+$", data.metadata.textureFileName)
        self.spriteFrames = data.frames

        runtime.spriteFrameCache:addSpriteFramesWithFile(self.path)
        trace("load plist: %s", trimPath(self.uri))
        for name in pairs(self.spriteFrames) do
            self.spriteFrames[name] = runtime.spriteFrameCache:getSpriteFrameByName(name)
        end
    end
end

function PlistLoader:unload()
    runtime.spriteFrameCache:removeSpriteFramesFromFile(self.path)
    runtime.textureCache:removeTextureForKey(self.imagePath)
    trace("unload plist: %s", trimPath(self.uri))
end

-- fgui
local FUILoader = M.register('.fui')

function FUILoader:load()
    local rawpath = string.gsub(self.path, '.fui$', '')
    local pkg = UIPackage.addPackage(rawpath)
    if not pkg then
        error("can't load '" .. self.uri .. "'")
    end
    trace('load fgui: %s', self.uri)
end

function FUILoader:unload()
    local rawpath = string.gsub(self.path, '.fui$', '')
    UIPackage.removePackage(rawpath)
    trace('unload fgui: %s', self.uri)
end

return M