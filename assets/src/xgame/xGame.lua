local class     = require "xgame.class"
local Event     = require "xgame.Event"
local timer     = require "kernel.timer"
local runtime   = require "kernel.runtime"
local Director  = require "cc.Director"

xGame = class("xGame", require("xgame.EventDispatcher"))

function xGame:ctor()

    runtime.setDispatcher(function (event, args)
        self:dispatch(event, args)
    end)
end

xGame = xGame.new()