local util          = require "xgame.util"
local Director      = require "cc.Director"
local Scene         = require "cc.Scene"
local Sprite        = require "cc.Sprite"
local Layout        = require "ccui.Layout"
local filesystem    = require "xgame.filesystem"
local wechat        = require "xgame.plugin.wechat"
local PluginEvent   = require "xgame.plugin.PluginEvent"

local function new()
    local scene = Scene.create()

    local bg = Layout.create()
    bg.backGroundColorType = 1
    bg.backGroundColor = 0xFFFFFF
    bg.width = 1334
    bg.height = 750
    scene:addChild(bg)


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
        wechat:auth('ApLNZQ7OekfcASNpXguqxsbmIilixOWjl_1qFwRLOFRUeV2XiEwq-I5ErDpfB5G7rLLFNfrIzoFZ4KaPir0EnQ')
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
        print("wechat got qrcode1", path)
        print("wechat got qrcode2", filesystem.dir.sdcard .. '/tencent/MicroMsg/oauth_qrcode.png')
        local image = Sprite.create(path)
        image.x = 600
        image.y = 300
        scene:addChild(image)
    end)

    local image = Sprite.create(filesystem.dir.sdcard .. '/tencent/MicroMsg/oauth_qrcode.png')
    if image then
        image.x = 900
        image.y = 300
        scene:addChild(image)
    end
    
    return scene
end
    
return {new = new}