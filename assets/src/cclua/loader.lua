local class         = require "cclua.class"
local util          = require "cclua.util"
local runtime       = require "cclua.runtime"
local filesystem    = require "cclua.filesystem"
local LoadTask      = require "cclua.LoadTask"
local plist         = require "cclua.plist"
local Event         = require "cclua.Event"
local Dispatcher    = require "cclua.Dispatcher"

local EVENT_RESULT = "result"

local trace = util.trace('[loader]')
local loader = {}
local cache = setmetatable({}, {__mode = 'v'})

local STATUS_LOADING = "loading"
local STATUS_COMPLETED = "completed"
local STATUS_ERROR = "error"
local STATUS_READY = "ready"

local AssetRef = class('AssetRef', Dispatcher)

function AssetRef:ctor(uri)
    self.uri = uri
    self.path = filesystem.localPath(uri)
    self.status = STATUS_READY
    self.type = string.lower(string.match(uri, '%.%w+$'))
    self.loader = loader[self.type] or loader['*']
end

function AssetRef:startLoad()
    local task = LoadTask.new(self.uri)
    self.status = STATUS_LOADING
    task:addListener(Event.COMPLETE, function ()
        if self.status == STATUS_LOADING then
            self.status = STATUS_COMPLETED
            self.loader.load(self)
        end
        self:dispatch(EVENT_RESULT)
    end)
    task:addListener(Event.IOERROR, function ()
        if self.status == STATUS_LOADING then
            self.status = STATUS_ERROR
        end
        self:dispatch(EVENT_RESULT)
    end)
    task:start()
end

function AssetRef:reload()
    self.loader.reload(self)
end

function AssetRef:unload()
    if self.status ~= 'unload' then
        self.status = 'unload'
        self.loader.unload(self)
    end
end

function AssetRef:__gc()
    self:unload()
end

function loader.register(suffix)
    local entry = {
        load = function () end,
        reload = function () end,
        unload = function () end,
    }
    for name in string.gmatch(suffix, '[^; ]+') do
        loader[name] = entry
    end
    return entry
end

function loader.load(uri, callback)
    local assetRef = cache[uri]
    if not uri or #uri == 0 then
        error('uri is nil or empty')
    end
    assert(string.find(uri, '%.%w+$'), uri)
    if not assetRef then
        assetRef = AssetRef.new(uri)
        cache[uri] = assetRef
    end
    if assetRef.status == STATUS_LOADING or assetRef.status == STATUS_READY then
        assetRef:addListener(EVENT_RESULT, function ()
            assetRef:removeListener(EVENT_RESULT, util.callee())
            if callback then
                callback(assetRef.status == STATUS_COMPLETED)
            end
        end)
    elseif callback then
        callback(assetRef.status == STATUS_COMPLETED)
    end
    if assetRef.status == STATUS_READY then
        assetRef:startLoad()
    end
    return assetRef
end

function loader.unload(uri)
    local assetRef = cache[uri]
    if assetRef then
        assetRef:unload()
        cache[uri] = nil
    end
end

function loader.reload(uri)
    local assetRef = cache[uri]
    if assetRef then
        assetRef:reload()
    end
end

local function trimPath(path)
    return filesystem.trimPath(path, 80)
end

-- default
loader.register('*')

-- jpg & png
local ImageLoader = loader.register('.jpg;.png')

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
local PlistLoader = loader.register('.plist')

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
if runtime.hasFeature("fairygui") then
    local UIPackage = require "fgui.UIPackage"
    local FUILoader = loader.register('.fui')

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
end

return loader