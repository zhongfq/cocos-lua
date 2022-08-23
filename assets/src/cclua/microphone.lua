local util          = require "cclua.util"
local filesystem    = require "cclua.filesystem"
local runtime       = require "cclua.runtime"
local Lame          = require "cclua.Lame"
local VBRMode       = require "cclua.Lame.VBRMode"
local permission    = require "cclua.permission"

local microphone = runtime.load("cclua.microphone")

local microphone_start = assert(microphone.start, "start")
local microphone_stop = assert(microphone.stop, "stop")

local mp3Encoder = nil
local mp3Path = nil
local pcmPath = nil
local startCallback = nil

microphone.setDispatcher(function (event, data)
    print("microphone", event, util.dump(data))
    if event == "start" then
        if not startCallback then
            printf('microphone start callback not set')
            return
        end
        if data.status == "started" then
            mp3Encoder = Lame.new()
            mp3Encoder.inSamplerate = 44100
            mp3Encoder.numChannels = 2
            mp3Encoder.vbr = VBRMode.vbr_off
            mp3Encoder.brate = 32
            mp3Encoder:initParams()
            mp3Encoder:start(pcmPath, mp3Path)
        end
        startCallback(data.status, data)
    elseif event == 'stop' then
        mp3Path = nil
        pcmPath = nil
        if not startCallback then
            printf('microphone start callback not set')
            return
        end
        startCallback('stopped', data)
        startCallback = nil
    end
end)
microphone.setDispatcher = false

function microphone.start(path, callback)
    if microphone.running then
        print('microphone is running')
        return
    end

    local status = runtime.getPermission(permission.MICROPHONE)
    if status ~= permission.status.AUTHORIZED then
        errorf("no permission for '%s'", permission.MICROPHONE)
    end

    startCallback = assert(callback)
    mp3Path = path
    pcmPath = path .. '.pcm'
    filesystem.remove(mp3Path)
    filesystem.remove(pcmPath)
    microphone_start(pcmPath)
end

function microphone.stop()
    microphone_stop()
    if mp3Encoder then
        mp3Encoder:stop()
        mp3Encoder = nil
    end
    microphone.dispatch("stop", {path = mp3Path})
end

return microphone