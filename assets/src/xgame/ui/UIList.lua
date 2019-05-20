--
-- $id: UIList.lua O $
--

local class         = require "xgame.class"
local UIAlign       = require "xgame.display.UIAlign"
local ListBase      = require "xgame.display.support.ListBase"

local UIList = class("UIList", ListBase)

function UIList:ctor()
    self.layout.horizontal_gap = 0
    self.layout.vertical_gap = 0
end

return UIList
