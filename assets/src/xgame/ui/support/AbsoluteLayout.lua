--
-- $id: AbsoluteLayout.lua O $
--

local class         = require "xgame.class"
local UIAlign       = require "xgame.display.UIAlign"
local LayoutBase    = require "xgame.display.support.LayoutBase"

local AbsoluteLayout = class("AbsoluteLayout", LayoutBase)

function AbsoluteLayout:do_layout()
    if self.target.stage then 
        for _, child in ipairs(self.target.children) do
            self:update_child_display(child)
        end
    end
end

function AbsoluteLayout:notify(action, child)
    if child.stage and action == "UPDATE" then
        self:update_child_display(child)
    end
end

function AbsoluteLayout:update_child_display(child)
    local rl, rr, rt, rb = self:get_relative_bounds()
    local width = rr - rl
    local height = rt - rb

    local percent = child.percent_width
    if percent and percent >= 0 then
        child.width = width * percent / 100
    end

    percent = child.percent_height
    if percent and percent >= 0 then
        child.height = height * percent / 100
    end

    if child.horizontal_align ~= UIAlign.NONE or 
        child.vertical_align ~= UIAlign.NONE then

        local cl, cr, ct, cb = child:get_bounds(self.target)
        local x, y = child:get_position()

        -- x align
        local align = child.horizontal_align
        if align == UIAlign.LEFT then
            x = x + (rl - cl) + child.left
        elseif align == UIAlign.CENTER then
            x = x + ((rl + rr) / 2  - (cl + cr) / 2) + child.horizontal_center
        elseif align == UIAlign.RIGHT then
            x = x + (rr - cr) - child.right
        end

        -- y align
        align = child.vertical_align
        if align == UIAlign.TOP then
            y = y + (rt - ct) - child.top
        elseif align == UIAlign.CENTER then
            y = y + (rt + rb) / 2 - (ct + cb) / 2 + child.vertical_center
        elseif align == UIAlign.BOTTOM then
            y = y + (rb - cb) + child.bottom
        end

        child:set_position(x, y)
    end

    LayoutBase.update_child_display(self, child)
end

return AbsoluteLayout
