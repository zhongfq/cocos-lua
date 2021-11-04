local downloader    = require "cclua.downloader"
local timer         = require "xgame.timer"
local filesystem    = require "xgame.filesystem"
local Manifest      = require "xgame.Manifest"

local assert = assert
local xpcall = xpcall

local MAX_LOADING_FILES = 10
local MAX_ATTEMPTS = 3
local ATTEMPT_INTERVAL = 0.5

local loadingList = {}
local loadTasks = {}
local started = false

local ASSETS_DIR = filesystem.dir.assets
local M = {
    remoteManifest = Manifest.new(ASSETS_DIR .. '/remote.metadata'),
    localManifest = Manifest.new(ASSETS_DIR .. '/local.metadata'),
    builtinManifest = Manifest.new('builtin.metadata'),
}

local function checkStart()
    if not started then
        started = true
        timer.delay(0.01, function ()
            started = false

            local count = MAX_LOADING_FILES
            for _, task in pairs(loadingList) do
                if task.attempts > 0 then
                    count = count - 1
                end
            end
            
            for _, task in pairs(loadingList) do
                if count < 0 then
                    break
                end
                count = count - 1

                if task.attempts == 0 then
                    task.attempts = 1
                    downloader.load(task.uri, task.path, task.md5 or '')
                end
            end
        end)
    end
end

local function notify(uri, success)
    local __TRACEBACK__ = __TRACEBACK__
    local doneTasks = {}
    for task in pairs(loadTasks) do
        if task.uri == uri then
            doneTasks[#doneTasks + 1] = task
        end
    end
    for _, task in ipairs(doneTasks) do
        loadTasks[task] = nil
        if task.callback then
            xpcall(task.callback, __TRACEBACK__, success, task)
        end
    end
    checkStart()
end

local function doLoad(task)
    assert(task.uri, "no uri")
    if not loadingList[task.uri] then
        loadingList[task.uri] = {
            attempts = 0,
            uri = task.uri,
            path = assert(task.path, task.uri),
            md5 = task.md5,
        }
    end
    
    loadTasks[task] = true
    checkStart()
end

downloader.setDispatcher(function (state, uri)
    local task = loadingList[uri]
    if not task then
        return
    elseif state == 'success' then
        print('[OK] load: ' .. uri)
        loadingList[uri] = nil
        notify(uri, true)
    else
        task.attempts = task.attempts + 1
        if task.attempts >= MAX_ATTEMPTS then
            print('[NO] load: ' .. task.uri)
            loadingList[task.uri] = nil
            notify(task.uri, false)
        else
            timer.delay(ATTEMPT_INTERVAL, function ()
                downloader.load(task.uri, task.path, task.md5 or '')
            end)
        end
    end
end)

function M.setURIResolver(resolver)
    downloader.setURIResolver(resolver)
end

function M.shouldDownload(target)
    local remoteFile = M.remoteManifest.assets[target.uri]
    if remoteFile then
        local localFile = M.localManifest.assets[target.uri]
        return (not filesystem.exist(target.path) and
                not filesystem.exist(target.uri))
            or (not localFile)
            or (localFile.date < remoteFile.date)
    elseif filesystem.isRemoteURI(target.uri) then
        return not filesystem.exist(target.path)
    else
        assert(filesystem.exist(target.uri), target.uri)
        return false
    end
end

function M.load(target)
    if M.shouldDownload(target) then
        local remoteFile = M.remoteManifest.assets[target.uri]
        local function callback(success)
            if success then
                local loader = require "xgame.loader"
                loader.reload(target.uri)
                if remoteFile then
                    local asset = {
                        date = remoteFile.date,
                        md5 = remoteFile.md5,
                        builtin = remoteFile.builtin,
                    }
                    M.localManifest:update(target.uri, asset)
                end
                target:loadSuccess()
            else
                target:loadError()
            end
        end

        local task = {
            path = target.path,
            uri = target.uri,
            callback = callback,
        }
        if remoteFile then
            task.md5 = remoteFile.md5
            task.uri = M.remoteManifest.packageURL .. '/' .. task.uri
        end
        doLoad(task)
    else
        target:loadSuccess()
    end
end

return M