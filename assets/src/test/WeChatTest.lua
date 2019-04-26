local _ENV = setmetatable({}, {__index = _ENV})

local runtime       = require "kernel.runtime"
local timer         = require "kernel.timer"
local Director      = require "cc.Director"
local Scene         = require "cc.Scene"
local util          = require "util"

local Layout        = require "ccui.Layout"
local wechat        = require "kernel.plugins.wechat"

function new()
    local scene = Scene.create()

    local btn = Layout.create()
    btn.backGroundColorType = 1
    btn.backGroundColor = 0xFF0000
    btn.width = 200
    btn.height = 100
    btn.x = 300
    btn.y = 300
    btn.touchEnabled = true
    btn:addClickEventListener(function ()
        print("xxxx click")
        wechat:auth("snsapi_userinfo", "")
    end)

    runtime.setDispatcher(function (event, data)
        if event == 'openURL' then
            wechat:handleOpenURL(data)
        end
    end)

    -- 3cf49e483cfcba309309dbca90cfb662
    wechat:init('wx4f5a7db510e75204')
    wechat:setDispatcher(function (...)
        print("wechat", ...)
    end)

    scene:addChild(btn)
    
    return scene
end
    
return _ENV