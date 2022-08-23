local runtime       = require "cclua.runtime"
local util          = require "cclua.util"
local filesystem    = require "cclua.filesystem"
local permission    = require "cclua.permission"

local photo = runtime.load("cclua.photo")

local photo_selectAvatar = photo.selectAvatar
local photo_takeAvatar = photo.takeAvatar
local photo_select = photo.select

local selectAvatarCallback = nil
local takeAvatarCallback = nil
local selectCallback = nil

if runtime.os == "android" then
    photo.cachePath = filesystem.dir.externalCache .. "/cclua_photo_path.jpg"
else
    photo.cachePath = filesystem.dir.cache .. "/cclua_photo_path.jpg"
end

photo.setDispatcher(function (event, data)
    print("photo", event, util.dump(data))
    local function exec(callback)
        if data.status == 'complete' then
            callback('successful', data)
        elseif data.status == 'cancel' then
            callback('canceled', data)
        else
            callback('failed', data)
        end
    end
    if event == "selectAvatar" then
        if not selectAvatarCallback then
            print('photo select avatar callback not set')
            return
        end
        exec(selectAvatarCallback)
        selectAvatarCallback = nil
    elseif event == "takeAvatar" then
        if not takeAvatarCallback then
            print('photo take avatar callback not set')
            return
        end
        exec(takeAvatarCallback)
        takeAvatarCallback = nil
    elseif event == "select" then
        if not selectCallback then
            print('photo select callback not set')
            return
        end
        exec(selectCallback)
        selectCallback = nil
    end
end)
photo.setDispatcher = false

local function checkPermission(value)
    local status = runtime.getPermission(value)
    if status ~= permission.status.AUTHORIZED then
        errorf("no permission for '%s'", value)
    end
end

function photo.selectAvatar(width, height, callback)
    checkPermission(permission.PHOTO)
    selectAvatarCallback = assert(callback)
    photo_selectAvatar(photo.cachePath, width, height)
end

function photo.takeAvatar(width, height, callback)
    checkPermission(permission.CAMERA)
    takeAvatarCallback = assert(callback)
    photo_takeAvatar(photo.cachePath, width, height)
end

function photo.select(callback)
    checkPermission(permission.PHOTO)
    selectCallback = assert(callback)
    photo_select(photo.cachePath)
end

return photo