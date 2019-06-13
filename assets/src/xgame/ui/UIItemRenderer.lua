local class     = require "xgame.class"
local UILayer   = require "xgame.ui.UILayer"

local UIItemRenderer = class("UIItemRenderer", UILayer)

function UIItemRenderer:ctor()
end

function UIItemRenderer:update(data)
end

function UIItemRenderer.Get:data() return self._data end
function UIItemRenderer.Set:data(value)
    if self._data == value then
        return
    end
    self._data = value
    self:update(value)
end

return UIItemRenderer
