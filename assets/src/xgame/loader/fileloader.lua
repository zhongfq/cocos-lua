local downloader    = require "xgame.downloader"
local assetloader   = require "xgame.assetloader"
local filesystem    = require "xgame.filesystem"
local Manifest      = require "xgame.loader.Manifest"

local M = {}

local manifests = {}

local remoteAssets = {}
local localAssets = {}

function M._removeFileIfExist(path)
    if filesystem.exist(path) then
        filesystem.remove(path)
    end
end

local function updateManifest(task)
    local remoteAsset = remoteAssets[task.url]
    if remoteAsset then
        local asset = {
            date = remoteAsset.date,
            md5 = remoteAsset.md5,
            builtin = remoteAsset.builtin,
        }
        localAssets[task.url] = asset
        for _, m in ipairs(manifests) do
            if m.remoteManifest.assets[task.url] then
                m.localManifest:update(task.url, asset)
            end
        end
    end
end

local function shouldDownload(task)
    local remoteAsset = remoteAssets[task.url]
    if remoteAsset then
        local localAsset = localAssets[task.url]
        return (not filesystem.exist(task.path) and
                not filesystem.exist(task.url))
            or (not localAsset)
            or (localAsset.date < remoteAsset.date)
    elseif string.find(task.url, '^https?://') then
        return not filesystem.exist(task.path)
    else
        assert(filesystem.exist(task.url), task.url)
        return false
    end
end

function M.load(task)
    if shouldDownload(task) then
        local remoteAsset = remoteAssets[task.url]
        local function callback(success)
            if success then
                assetloader.reload({
                    [task.path] = true,
                    [task.url] = true
                })
                updateManifest(task)
                task:loadSuccess()
            else
                task:loadError()
            end
        end
        if remoteAsset then
            downloader.load({
                path = task.path,
                md5 = remoteAsset.md5,
                url = remoteAsset.url,
                callback = callback,
            })
        else
            downloader.load({
                url = task.url,
                path = task.path,
                callback = callback,
            })
        end
    else
        task:loadSuccess()
    end
end

function M.addModule(localManifestPath, remoteManifestPath)
    local m = {
        localManifest = Manifest.new(localManifestPath),
        remoteManifest = Manifest.new(remoteManifestPath),
    }

    for path, asset in pairs(m.localManifest.assets) do
        if not localAssets[path] then
            localAssets[path] = asset
        else
            print(string.format('ingore local path: %s', path))
        end
    end

    for path, asset in pairs(m.remoteManifest.assets) do
        if not remoteAssets[path] then
            assert(asset.url, path)
            remoteAssets[path] = asset
        else
            print(string.format('ingore remote path: %s', path))
        end
    end

    manifests[#manifests + 1] = m
end

return M