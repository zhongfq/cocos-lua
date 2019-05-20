--
-- $id: UIGrid.lua O $
--

local class         = require "xgame.class"
local UIAlign       = require "xgame.display.UIAlign"
local ListBase      = require "xgame.display.support.ListBase"

local UIGridLayout

local UIGrid = class("UIGrid", ListBase)

function UIGrid:ctor()
end

function UIGrid.Get:wrap_count() return self._layout.wrap_count end
function UIGrid.Set:wrap_count(value)
    value = math.max(1, value)
    if self._layout.wrap_count ~= value then
        self._layout.wrap_count = value
        self._layout:notify("UPDATE")
    end
end

function UIGrid.Get:horizontal_gap() return self._layout.horizontal_gap end
function UIGrid.Set:horizontal_gap(value)
    if self._layout.horizontal_gap ~= value then
        self._layout.horizontal_gap = value
        self._layout:notify("UPDATE")
    end
end

function UIGrid.Get:vertical_gap() return self._layout.vertical_gap end
function UIGrid.Set:vertical_gap(value)
    if self._layout.vertical_gap ~= value then
        self._layout.vertical_gap = value
        self._layout:notify("UPDATE")
    end
end

function UIGrid.Get:orientation() return self._layout.orientation end
function UIGrid.Set:orientation(value)
    if self._layout.orientation ~= value then
        self._layout.orientation = value
        self._layout:notify("UPDATE")
        self._scroll_impl.horizontal_enabled = value ~= UIAlign.VERTICAL
        self._scroll_impl.vertical_enabled = value == UIAlign.VERTICAL
    end
end

return UIGrid
