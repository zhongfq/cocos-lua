local class         = require "xgame.class"
local util          = require "xgame.util"
local runtime       = require "xgame.runtime"
local Dispatcher    = require "xgame.Dispatcher"
local Event         = require "xgame.event.Event"
local PluginEvent   = require "xgame.event.PluginEvent"
local lame          = require 'kernel.lame'
local impl          = require "kernel.plugins.recorder"

local PermissionStatus = runtime.PermissionStatus
local Permission = runtime.Permission
local trace = util.trace("[recorder]")

local Recorder = class('Recorder', Dispatcher)

function Recorder:ctor()
    self._running = false
    self._mp3Encoder = false
    self._path = false
    impl:setDispatcher(function (...)
        self:_didResponse(...)
    end)
end

function Recorder:_didResponse(event, message)
    if event == 'state' then
        if message == 'ERR_CREATE_FILE' then
            trace("can't not write file: %s", self._path)
            self._running = false
            if self._mp3Encoder then
                self._mp3Encoder:cancel()
                self._mp3Encoder = false
            end
            self:dispatch(Event.IOERROR)
        elseif message == 'STARTED' then
            trace('start record: %s', self._path)
            self._mp3Encoder = lame.init()
            self._mp3Encoder.in_samplerate = 44100
            self._mp3Encoder.num_channels = 2
            self._mp3Encoder.vbr = "vbr_off"
            self._mp3Encoder.brate = 32
            self._mp3Encoder:init_params()
            self._mp3Encoder:start(self._path .. '.pcm', self._path)
            self:dispatch(PluginEvent.START_RECORD)
        elseif message == 'STOPPED' then
            trace('stop record: %s', self._path)
            self._running = false
            if self._mp3Encoder then
                self._mp3Encoder:cancel()
                self._mp3Encoder = false
            end
            self:dispatch(PluginEvent.STOP_RECORD)
        end
    end
end

function Recorder:start(path)
    if self._running then
        trace("audio recorder already running!")
        return
    end

    local status = runtime.getPermissionStatus(Permission.AUDIO)
    if status == PermissionStatus.DENIED or status == PermissionStatus.RESTRICTED then
        trace('audio permission denied')
        return
    end

    self._running = true

    impl:requestPermission(function (granted)
        if granted then
            self._path = path
            impl:start(path .. '.pcm')
        else
            self._running = false
        end
    end)
end

function Recorder:stop()
    if self._running then
        impl:stop()
    end
end

if runtime.os == "android" then
    local luaj = require "xgame.luaj"
    local inst = luaj.new("kernel.plugins.recorder.Recorder")
    impl = {}

    function impl:setDispatcher(callback)
        impl.callback = callback
    end

    function impl:requestPermission(callback)
        runtime.requestPermission('android.permission.RECORD_AUDIO', function (status)
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
                    '没有权限访问您的麦克风，请前往权限管理进行设置。',
                    '去设置',
                    '取消', alertCallback)
            end
        end)
    end

    function impl:start(path)
        inst.start(path, function (...)
            impl.callback('state', ...)
        end)
    end

    function impl:stop()
        inst.stop()
    end
end

return Recorder.new()