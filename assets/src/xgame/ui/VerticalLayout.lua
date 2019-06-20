local class         = require "xgame.class"
local Align         = require "xgame.ui.Align"
local LayoutManager = require "xgame.ui.LayoutManager"
local LayoutBase    = require "xgame.ui.LayoutBase"

local VerticalLayout = class("VerticalLayout", LayoutBase)

function VerticalLayout:ctor()
    self.gap = 6
    self.content_h_align = Align.LEFT
end

function VerticalLayout:do_layout()
    if not self.target.stage then
        return
    end

    local rl, rr, rt, rb = self:getRelativeBounds()

    local total_percent = 0
    local total_height = 0
    local num = 0

    for _, child in ipairs(self.target.children) do
        if not child.visible then
            goto continue
        end

        if child.percent_height and child.percent_height > 0 then
            total_percent = total_percent + child.percent_height
        else
            total_height = total_height + child.height
        end

        if child.percent_width and child.percent_width > 0 then
            child.width = (rr - rl) * child.percent_width / 100
        end

        ::continue::
    end

    local height = self.target.height - total_height - (num - 1) * self.gap
    if height > 0 then
        for _, child in ipairs(self.target.children) do
            if not child.visible then
                goto continue
            end

            if child.percent_height and child.percent_height > 0 then
                child.height = height * child.percent_height / total_percent
            end

            ::continue::
        end
    end

    height = 0

    for _, child in ipairs(self.target.children) do
        if not child.visible then
            goto continue
        end

        height = height + child.height + self.gap
         ::continue::
    end

    height = height - self.gap

    local pos = 0
    if self.content_v_align == Align.CENTER then
        pos = (self.target.height - height) / 2
    elseif self.content_v_align == Align.TOP then
        pos = self.target.height - height
    end

    local children = self.target.children
    for i = #children, 1, -1 do
        child = children[i]
        if not child.visible then
            goto continue
        end

        local cl, cr, ct, cb = child:get_bounds(self.target)
        local x, y = child:get_position()

        if self.content_h_align == Align.RIGHT then
            x = x + (rr - cr)
        elseif self.content_h_align == Align.CENTER then
            x = x + (rl + rr) / 2  - (cl + cr) / 2 
        else
            x = x + (rl - cl)
        end

        y = y - cb + pos

        child:set_position(x, y)
        pos = pos + (ct - cb) + self.gap

        self:update_child_display(child)

        ::continue::
    end
end

return VerticalLayout