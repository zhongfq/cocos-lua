local class         = require "xgame.class"
local util          = require "xgame.util"
local filesystem    = require "xgame.filesystem"
local plistparser   = require "xgame.plistparser"

local trace = util.trace("[asset]")
local assert = assert
local string = string

local TextureCache = cc.Director:getInstance():getTextureCache()
local SpriteFrameCache = cc.SpriteFrameCache:getInstance()

local AssetObject

local M = {}

local assets = setmetatable({}, {__mode = 'v'})
local view_assets = setmetatable({}, {__mode = 'k'})
local view_watches = setmetatable({}, {__mode = "k"})
local static_assets = {}

local function short_path(path)
    return filesystem.short_path(path, 60)
end

local function get_or_create(path)
    local obj = assets[path]
    if not obj then
        obj = AssetObject.new(path)
        assets[path] = obj
    end
    return obj
end

function M.set_static(path)
    assert(path and #path > 0)
    trace("set static asset: %s", short_path(path))
    static_assets[path] = get_or_create(path)
end

function M.watch(view)
    view_watches[view] = true
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
        local asset = get_or_create(path)
        asset:load()
        dict[path] = asset
    end

    if view then
        view_assets[view] = dict
    end
end

function M.unload(view)
    if view then
        view_assets[view] = nil
        view_watches[view] = nil
    end
end

function M.load_async(view, paths, callback)
    assert(callback)
    paths = util.clone(paths)
    for path in pairs(paths) do
        local asset = get_or_create(path)
        asset:load_async(function ()
            paths[path] = nil
            if not next(paths) then
                callback()
            end
        end)
    end
end

function M.load_scene(scene)
    local filter = {}

    local function do_load(target)
        local dict = view_assets[target]
        if dict then
            for path, asset in pairs(dict) do
                filter[path] = asset
                asset:load()
            end
        end
        if target.children then
            for _, child in ipairs(target.children) do
                do_load(child)
            end
        end
    end

    do_load(scene)

    for view in pairs(view_watches) do
        do_load(view)
    end

    for path, asset in pairs(assets) do
        if not(filter[path] or static_assets[path]) then
            -- if no view refer the asset, asset gc method will call
            -- when lua gc happen
            asset:delete_texture()
        end
    end
end

function M.dump(dump_static)
    local arr = {}
    for path, asset in pairs(assets) do
        if dump_static then
            arr[#arr + 1] = string.format("  %s[static=%s, active=%s]",
                short_path(path), 
                static_assets[path] and true or false,
                asset:is_active())
        elseif not static_assets[path] then
            arr[#arr + 1] = string.format("  %s[static=false, active=%s]", 
                short_path(path), asset:is_active())
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
        self._image = string.gsub(path, "[^/]+$", plistparser.parse(
            filesystem.read(path)).metadata.textureFileName)
    else
        self._plist = false
        self._image = path
    end

    TextureCache:retain()
    SpriteFrameCache:retain()
end

function AssetObject:__gc()
    xpcall(self.unload, __TRACEBACK__, self)
    TextureCache:release()
    SpriteFrameCache:release()
end

function AssetObject:load()
    if self._plist then
        if not SpriteFrameCache:isSpriteFramesWithFileLoaded(self._plist) then
            trace("L => %s", short_path(self._plist))
            SpriteFrameCache:addSpriteFrames(self._plist)

            -- TODO: hold sprite frames?
        end
    end

    local texture = TextureCache:getTextureForKey(self._image)
    if not texture then
        texture = TextureCache:addImage(self._image)
        trace("L => %s", short_path(self._image))
    elseif texture:getName() == 0 then
        trace("R => %s", short_path(self._image))
        TextureCache:reloadTexture(self._image)
    end
end

function AssetObject:load_async(callback)
    local texture = TextureCache:getTextureForKey(self._image)
    assert(callback)
    if not texture then
        TextureCache:addImageAsync(self._image, function (texture)
            if texture then
                trace("L => %s", short_path(self._image))
                callback()
            else
                trace("not found: %s", short_path(self._image))
            end
        end)
    else
        if texture:getName() == 0 then
            TextureCache:reloadTexture(self._image)
            trace("R => %s", short_path(self._image))
        end
        callback()
    end
end

function AssetObject:reload()
    -- TODO: plist reload?
    TextureCache:reloadTexture(self._image)
end

function AssetObject:unload()
    if self._plist then
        SpriteFrameCache:removeSpriteFramesFromFile(self._plist)
    end
    TextureCache:removeTextureForKey(self._image)
    trace("U => %s", short_path(self.path))
end

function AssetObject:delete_texture()
    local texture = TextureCache:getTextureForKey(self._image)
    if texture and texture:getName() ~= 0 then
        texture:releaseGLTexture()
        trace("D => %s", short_path(self._image))
    end
end

function AssetObject:is_active()
    local texture = TextureCache:getTextureForKey(self._image)
    return (texture and texture:getName() ~= 0) and true or false
end

return M
