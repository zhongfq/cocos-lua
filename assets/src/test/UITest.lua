local class         = require "xgame.class"
local util          = require "xgame.util"
local timer         = require "xgame.timer"
local runtime       = require "xgame.runtime"
local MixScene      = require "xgame.ui.MixScene"
local font          = require "xgame.font"
local Array         = require "xgame.Array"

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
    ui.new("console", self, self)
    self.scaleX = 0.9
    self.scaleY = 0.9
end

function UITest:onCreate()
    local arr = Array.new()
    for i = 1, 100 do
        arr:pushBack({name = 'hello ' .. i, index = math.random(1, 100)})
    end
    self.shortcut_list.data = arr

    local data = Array.new()
    for i = 1, 100 do
        data:pushBack({name = 'list test hello ' .. i, index = math.random(1, 100)})
    end
    self.list.data = data
end

local ii = 1000

function UITest:do_send()
    -- self.list.data:addAt({name = 'insert ' .. ii}, 15)
    -- ii = ii + 1
    -- self.shortcut_list.wrapCount = 4
    runtime.openURL('app-settings')
end

function UITest:open_shortcut()
    self.list.visible = not self.list.visible
    self.shortcut_list.visible = not self.shortcut_list.visible
end

local UIItemRenderer = require "xgame.ui.UIItemRenderer"

local ConsoleShortcut = ui.class('ConsoleShortcut', UIItemRenderer)

function ConsoleShortcut:update(data)
    self.label.text = data.name
end

local ConsoleFileListRenderer = ui.class("ConsoleFileListRenderer", UIItemRenderer)

function ConsoleFileListRenderer:update(data)
    self.label.text = data.name
end

return UITest