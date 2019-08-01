local class         = require "xgame.class"
local util          = require "xgame.util"
local timer         = require "xgame.timer"
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
end

function UITest:onCreate()
    local arr = Array.new()
    arr:pushBack({name = "hello1"})
    arr:pushBack({name = "hello2"})
    arr:pushBack({name = "hello3"})
    arr:pushBack({name = "hello4"})
    arr:pushBack({name = "hello5"})
    arr:pushBack({name = "hello6"})
    self.shortcut_list.data = arr

    local data = Array.new()
    for i = 1, 100 do
        data:pushBack({name = 'list test hello ' .. i})
    end
    self.list.data = data
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
end

return UITest