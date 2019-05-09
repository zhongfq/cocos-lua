local timer         = require "kernel.timer"
local downloader    = require "kernel.downloader"

local assert = assert

local MAX_LOADING_FILES = 10
local MAX_ATTEMPTS = 3
local ATTEMPT_INTERVAL = 0.5
local TAG_CHECK_START = "__downloader_check_start__"

local loadQueue = {}
local loadTasks = {}

local function checkStart()
    local count = MAX_LOADING_FILES
    for _, task in pairs(loadQueue) do
        if task.attempts > 0 then
            count = count - 1
        end
    end
    
    for _, task in pairs(loadQueue) do
        if count < 0 then
            break
        end
        count = count - 1

        if task.attempts == 0 then
            task.attempts = 1
            downloader.load(task.url, task.path, task.md5)
        end
    end
end

local function deferCheckStart()
    timer.killDelay(TAG_CHECK_START)
    timer.delayWithTag(0.01, TAG_CHECK_START, checkStart)
end

local function load(task)
    assert(task.url, "no url")
    if not loadQueue[task.url] then
        loadQueue[task.url] = {
            attempts = 0,
            url = task.url,
            path = assert(task.path, task.url),
            md5 = task.md5,
        }
    end
    
    loadTasks[task] = true
    deferCheckStart()
end

local function notify(url, loaded)
    local doneTasks = {}
    for task in pairs(loadTasks) do
        if task.url == url then
            doneTasks[#doneTasks + 1] = task
        end
    end
    for _, task in ipairs(doneTasks) do
        loadTasks[task] = nil
        if task.callback then
            task.callback(loaded, task)
        end
    end
    deferCheckStart()
end

downloader.setDispatcher(function (url, path, state)
    if state == 'ioerror' or state == 'invalid' then
        local task = assert(loadQueue[url], url)
        task.attempts = task.attempts + 1
        if task.attempts >= MAX_ATTEMPTS then
            print('[NO] load: ' .. url)
            loadQueue[url] = nil
            notify(url, false)
        else
            timer.delay(ATTEMPT_INTERVAL, function ()
                downloader.load(task.url, task.path, task.md5)
            end)
        end
    else
        print('[OK] load: ' .. url)
        loadQueue[url] = nil
        notify(url, true)
    end
end)

return {load = load}