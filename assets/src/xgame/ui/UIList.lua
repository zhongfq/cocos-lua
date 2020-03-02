local class         = require "xgame.class"
local ListBase      = require "xgame.ui.ListBase"

local UIList = class("UIList", ListBase)

function UIList:ctor()
    self.layout.horizontalGap = 0
    self.layout.verticalGap = 0
end

return UIList
