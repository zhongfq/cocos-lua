local downloader    = require "kernel.downloader"
local FileState     = require "kernel.downloader.FileState"
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
    remoteManifest = Manifest.new(ASSETS_DIR .. '/remote.manifest'),
    localManifest = Manifest.new(ASSETS_DIR .. '/local.manifest'),
    builtinManifest = Manifest.new('builtin.manifest'),
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
                    downloader.load(task)
                end
            end
        end)
    end
end

local function notify(url, success)
    local __TRACEBACK__ = __TRACEBACK__
    local doneTasks = {}
    for task in pairs(loadTasks) do
        if task.url == url then
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
    assert(task.url, "no url")
    if not loadingList[task.url] then
        loadingList[task.url] = {
            attempts = 0,
            url = task.url,
            path = assert(task.path, task.url),
            md5 = task.md5,
        }
    end
    
    loadTasks[task] = true
    checkStart()
end

downloader.setDispatcher(function (task)
    local state = task.state
    task = loadingList[task.url]
    if not task then
        return
    elseif state == FileState.IOERROR or state == FileState.INVALID then
        task.attempts = task.attempts + 1
        if task.attempts >= MAX_ATTEMPTS then
            print('[NO] load: ' .. task.url)
            loadingList[task.url] = nil
            notify(task.url, false)
        else
            timer.delay(ATTEMPT_INTERVAL, function ()
                downloader.load(task)
            end)
        end
    else
        print('[OK] load: ' .. task.url)
        loadingList[task.url] = nil
        notify(task.url, true)
    end
end)

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
                local loader = require "xgame.loader"
                loader.reload(task.url)
                if remoteFile then
                    local asset = {
                        date = remoteFile.date,
                        md5 = remoteFile.md5,
                        builtin = remoteFile.builtin,
                    }
                    M.localManifest:update(task.url, asset)
                end
                task:loadSuccess()
            else
                task:loadError()
            end
        end
        if remoteFile then
            doLoad({
                path = task.path,
                md5 = remoteFile.md5,
                url = M.remoteManifest.packageURL .. '/' .. task.url,
                callback = callback,
            })
        else
            doLoad({
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