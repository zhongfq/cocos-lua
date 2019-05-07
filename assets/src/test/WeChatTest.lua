local util          = require "xgame.util"
local Director      = require "cc.Director"
local Scene         = require "cc.Scene"
local Sprite        = require "cc.Sprite"
local Layout        = require "ccui.Layout"
local wechat        = require "xgame.plugins.wechat"
local PluginEvent   = require "xgame.plugins.PluginEvent"

local function new()
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
        wechat:auth()
    end)
    scene:addChild(btn)

    wechat:init('wx4f5a7db510e75204', "95dbbdde5aba7e11697ccc8939d161af")
    wechat:addListener(PluginEvent.AUTH_CANCEL, function ()
        print("wechat auth cancel")
    end)

    wechat:addListener(PluginEvent.AUTH_FAILURE, function ()
        print("wechat auth fail")
    end)

    wechat:addListener(PluginEvent.AUTH_SUCCESS, function (_, info)
        print("wechat auth success")
        util.dump(info)
    end)

    wechat:addListener(PluginEvent.GOT_QRCODE, function (_, path)
        print("wechat got qrcode", path)
        local image = Sprite.create(path)
        image.x = 600
        image.y = 300
        scene:addChild(image)
    end)
    
    return scene
end
    
return {new = new}