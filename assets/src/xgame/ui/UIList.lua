local class         = require "xgame.class"
local Align       = require "xgame.ui.Align"
local ListBase      = require "xgame.ui.ListBase"

local UIList = class("UIList", ListBase)

function UIList:ctor()
    self.layout.horizontal_gap = 0
    self.layout.vertical_gap = 0
end

return UIList
