local downloader    = require "xgame.downloader"
local assetloader   = require "xgame.assetloader"
local filesystem    = require "xgame.filesystem"
local Manifest      = require "xgame.loader.Manifest"

local ASSETS_DIR = filesystem.dir.assets
local M = {
    remoteManifest = Manifest.new(ASSETS_DIR .. '/remote.manifest'),
    localManifest = Manifest.new(ASSETS_DIR .. '/local.manifest'),
    builtinManifest = Manifest.new('builtin.manifest'),
}

local function updateManifest(task)
    local remoteFile = M.remoteManifest.assets[task.url]
    if remoteFile then
        local asset = {
            date = remoteFile.date,
            md5 = remoteFile.md5,
            builtin = remoteFile.builtin,
        }
        M.localManifest:update(task.url, asset)
    end
end

function M.shouldDownload(task)
    local remoteFile = M.remoteManifest.assets[task.url]
    if remoteFile then
        local localFile = M.localManifest.assets[task.url]
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
        local remoteFile = M.remoteManifest.assets[task.url]
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
                url = M.remoteManifest.packageURL .. '/' .. task.url,
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

return M