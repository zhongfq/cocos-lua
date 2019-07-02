local class         = require "xgame.class"
local util          = require "xgame.util"
local timer         = require "xgame.timer"
local MixScene      = require "xgame.ui.MixScene"
local font          = require "xgame.font"

local ui = require "xgame.ui.ui"

ui.class("Component", require("xgame.ui.UILayer"))
ui.class('ScaleButton', require("xgame.ui.UILayer"))
ui.class("AnimPlayer", require("xgame.ui.UILayer"))

font.register {
    name = "方正准圆",
    path = "res/font/zhunyuan.ttf",
}

local UITest = class("UITest", MixScene)

function UITest:ctor()
    ui.new("login", self, self)
end

function UITest:onCreate()
    self.start_page.btn_account.parent:reszieToChildren(true)
    -- print('###', self.width, self.height, self.x, self.y)
    -- self.x = 500
    -- print('###', self.stage.x, self.stage.cobj.x)
    print('xxxx')
    -- xGame:delay(1, function ()
    --     self.cobj:setPosition(500, 0)
    --     print('helllo')
    -- end)
end

function UITest:open_login_page()
    print('open_login_page')
    self.start_page.visible = false
    self.login_page.visible = true

    print(self.login_page.account.children[2].horizontalAlign)
end

return UITest