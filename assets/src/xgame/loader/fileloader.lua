local downloader    = require "xgame.downloader"
local assetloader   = require "xgame.assetloader"
local filesystem    = require "xgame.filesystem"
local Manifest      = require "xgame.loader.Manifest"

local M = {}
local manifests = {}
local remoteAssets = {}
local localAssets = {}

local function updateManifest(task)
    local remoteFile = remoteAssets[task.url]
    if remoteFile then
        local asset = {
            date = remoteFile.date,
            md5 = remoteFile.md5,
            builtin = remoteFile.builtin,
        }
        localAssets[task.url] = asset
        for _, m in ipairs(manifests) do
            if m.remoteManifest.assets[task.url] then
                m.localManifest:update(task.url, asset)
            end
        end
    end
end

function M.shouldDownload(task)
    local remoteFile = remoteAssets[task.url]
    if remoteFile then
        local localFile = localAssets[task.url]
        return (not filesystem.exist(task.path) and
                not filesystem.exist(task.url))
            or (not localFile)
            or (localFile.date < remoteFile.date)
    elseif string.find(task.url, '^https?://') then
        return not filesystem.exist(task.path)
    else
        assert(filesystem.exist(task.url), task.url)
        return false
    end
end

function M.load(task)
    if M.shouldDownload(task) then
        local remoteFile = remoteAssets[task.url]
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
        if remoteFile then
            downloader.load({
                path = task.path,
                md5 = remoteFile.md5,
                url = remoteFile.url,
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
            asset.url = m.remoteManifest.packageURL .. '/' .. path
            remoteAssets[path] = asset
        else
            print(string.format('ingore remote path: %s', path))
        end
    end

    manifests[#manifests + 1] = m
end

return M