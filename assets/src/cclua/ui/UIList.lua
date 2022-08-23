local class         = require "cclua.class"
local ListBase      = require "cclua.ui.ListBase"

local UIList = class("UIList", ListBase)

function UIList:ctor()
    self.layout.horizontalGap = 0
    self.layout.verticalGap = 0
end

return UIList
