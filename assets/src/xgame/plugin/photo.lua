local class         = require "xgame.class"
local util          = require "xgame.util"
local filesystem    = require "xgame.filesystem"
local runtime       = require "xgame.runtime"
local Dispatcher    = require "xgame.Dispatcher"
local Event         = require "xgame.event.Event"
local impl          = require "kernel.plugins.photo"

local trace = util.trace("[photo]")

local Photo = class('Photo', Dispatcher)

function Photo:ctor()
    if runtime.os == "android" then
        self._path =  filesystem.dir.externalCache .. '/select_photo.jpg'
    else
        self._path =  filesystem.dir.cache .. "/select_photo.jpg"
    end
    impl:setDispatcher(function (...)
        self:_didResponse(...)
    end)
end

function Photo:_didResponse(event, message)
    if event == "selectImage" then
        trace("%s: %s", event, message)
        if message == "complete" then
            self:dispatch(Event.COMPLETE, self._path)
        elseif message == "ioerror" then
            self:dispatch(Event.IOERROR)
        elseif message == "typeerror" then
            self:dispatch(Event.IOERROR)
        elseif message == "cancel" then
            self:dispatch(Event.CANCEL)
        end
    end
end

function Photo:selectAvatar(width, height)
    assert(type(width) == "number")
    assert(type(height) == "number")
    impl:requestPermission("PHOTO", function (granted)
        if granted then
            impl:selectAvatar(self._path, width, height)
        end
    end)
end

function Photo:takeAvatar(width, height)
    assert(type(width) == "number")
    assert(type(height) == "number")
    impl:requestPermission("CAMERA", function (granted)
        if granted then
            impl:takeAvatar(self._path, width, height)
        end
    end)
end

function Photo:select()
    impl:select(self._path)
end

if runtime.os == "android" then
    local luaj = require "xgame.luaj"
    local inst = luaj.new("kernel/plugins/photo/Photo")
    impl = {}

    function impl:setDispatcher(callback)
        impl.callback = callback
    end

    function impl:requestPermission(permission, callback)
        runtime.requestPermission('android.permission.CAMERA', function (status)
            if status == runtime.PermissionStatus.AUTHORIZED then
                callback(true)
            else
                local alertCallback = function (status)
                    if status then
                        runtime.openURL('app-settings')
                    else
                        callback(false)
                    end
                end
                runtime.alert(
                    '温馨提示',
                    '没有权限访问您的照相机或相册，请前往权限管理进行设置。',
                    '去设置',
                    '关闭', alertCallback)
            end
        end)
    end

    function impl:takeAvatar(path, width, height)
        inst.takeAvatar(path, width, height, function (...)
            self.callback('selectImage', ...)
        end)
    end

    function impl:selectAvatar(path, width, height)
        inst.selectAvatar(path, width, height, function (...)
            self.callback('selectImage', ...)
        end)
    end

    function impl:select(path)
        inst.select(path, function (...)
            self.callback('selectImage', ...)
        end)
    end
end

return Photo.new()