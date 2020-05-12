local class         = require "xgame.class"
local util          = require "xgame.util"
local filesystem    = require "xgame.filesystem"
local plist         = require "xgame.plist"

local trace = util.trace("[asset]")
local assert = assert
local string = string

local textureCache = require("cc.Director").instance.textureCache
local spriteFrameCache = require("cc.SpriteFrameCache").instance

local AssetObject

local M = {}

local assets = setmetatable({}, {__mode = 'v'})
local viewAssets = setmetatable({}, {__mode = 'k'})
local viewWatches = setmetatable({}, {__mode = "k"})
local staticAssets = {}

local function shortPath(path)
    return filesystem.shortPath(path, 60)
end

local function getOrCreate(path)
    local obj = assets[path]
    if not obj then
        obj = AssetObject.new(path)
        assets[path] = obj
    end
    return obj
end

function M.setStatic(path)
    assert(path and #path > 0)
    trace("set static asset: %s", shortPath(path))
    staticAssets[path] = getOrCreate(path)
end

function M.watch(view)
    viewWatches[view] = true
end


function M.reload(paths)
    for path in pairs(paths) do
        local asset = assets[path]
        if asset then
            asset:reload()
        end
    end
end

function M.load(view, paths)
    local dict = {}
    for path in pairs(paths) do
        local asset = getOrCreate(path)
        asset:load()
        dict[path] = asset
    end

    if view then
        viewAssets[view] = dict
    end
end

function M.unload(view)
    if view then
        viewAssets[view] = nil
        viewWatches[view] = nil
    end
end

function M.loadAsync(view, paths, callback)
    assert(callback)
    paths = util.clone(paths)
    for path in pairs(paths) do
        local asset = getOrCreate(path)
        asset:loadAsync(function ()
            paths[path] = nil
            if not next(paths) then
                callback()
            end
        end)
    end
end

function M.loadSceneAssets(scene)
    local filter = {}

    local function doLoad(target)
        local dict = viewAssets[target]
        if dict then
            for path, asset in pairs(dict) do
                filter[path] = asset
                asset:load()
            end
        end
        if target.children then
            for _, child in ipairs(target.children) do
                doLoad(child)
            end
        end
    end

    doLoad(scene)

    for view in pairs(viewWatches) do
        doLoad(view)
    end

    for path, asset in pairs(assets) do
        if not(filter[path] or staticAssets[path]) then
            -- if no view refer the asset, asset gc method will call
            -- when lua gc happen
            asset:deleteTexture()
        end
    end
end

function M.dump(dumpStatic)
    local arr = {}
    for path, asset in pairs(assets) do
        if dumpStatic then
            arr[#arr + 1] = string.format("  %s[static=%s, active=%s]",
                shortPath(path),
                staticAssets[path] and true or false,
                asset:isActive())
        elseif not staticAssets[path] then
            arr[#arr + 1] = string.format("  %s[static=false, active=%s]",
                shortPath(path), asset:isActive())
        end
    end
    table.sort(arr)
    trace("alive assets:\n%s", table.concat(arr, "\n"))
end

--
-- AssetObject
--
AssetObject = class("AssetObject")

function AssetObject:ctor(path)
    self.path = path
    if string.find(path, ".plist$") then
        self._plist = path
        local data = plist.parse(filesystem.read(path))
        self._image = string.gsub(path, "[^/]+$", data.metadata.textureFileName)
        self._frames = data.frames
    else
        self._plist = false
        self._image = path
    end
end

function AssetObject:__gc()
    self:unload()
end

function AssetObject:load()
    if self._plist then
        if not spriteFrameCache:isSpriteFramesWithFileLoaded(self._plist) then
            trace("L => %s", shortPath(self._plist))
            spriteFrameCache:addSpriteFramesWithFile(self._plist)
            for name in pairs(self._frames) do
                self._frames[name] = spriteFrameCache:getSpriteFrameByName(name)
            end
        end
    end

    local texture = textureCache:getTextureForKey(self._image)
    if not texture then
        texture = textureCache:addImage(self._image)
        trace("L => %s", shortPath(self._image))
    elseif texture.name == 0 then
        trace("R => %s", shortPath(self._image))
        textureCache:reloadTexture(self._image)
    end
end

function AssetObject:loadAsync(callback)
    local texture = textureCache:getTextureForKey(self._image)
    assert(callback)
    if not texture then
        textureCache:addImageAsync(self._image, function (texture)
            if texture then
                trace("L => %s", shortPath(self._image))
                callback()
            else
                trace("not found: %s", shortPath(self._image))
            end
        end)
    else
        if texture.name == 0 then
            textureCache:reloadTexture(self._image)
            trace("R => %s", shortPath(self._image))
        end
        callback()
    end
end

function AssetObject:reload()
    textureCache:reloadTexture(self._image)
end

function AssetObject:unload()
    if self._plist then
        spriteFrameCache:removeSpriteFramesFromFile(self._plist)
    end
    textureCache:removeTextureForKey(self._image)
    trace("U => %s", shortPath(self.path))
end

function AssetObject:deleteTexture()
    local texture = textureCache:getTextureForKey(self._image)
    if texture and texture.name ~= 0 then
        -- texture:releaseGLTexture()
        -- trace("D => %s", shortPath(self._image))
    end
end

function AssetObject:isActive()
    local texture = textureCache:getTextureForKey(self._image)
    return (texture and texture.name ~= 0) and true or false
end

return M
