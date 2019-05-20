--
-- $id: HorizontalLayout.lua O $
--

local class         = require "xgame.class"
local UIAlign       = require "xgame.display.UIAlign"
local LayoutManager = require "xgame.display.support.LayoutManager"
local LayoutBase    = require "xgame.display.support.LayoutBase"

local HorizontalLayout = class("HorizontalLayout", LayoutBase)

function HorizontalLayout:ctor()
    self.gap = 6
    self.content_h_align = UIAlign.LEFT
    self.content_v_align = UIAlign.BOTTOM
end

function HorizontalLayout:do_layout()
    LayoutManager:remove_update(self)

    if not self.target.stage then
        return
    end

    local rl, rr, rt, rb = self:get_relative_bounds()

    local total_percent = 0
    local total_width = 0
    local num = 0

    for _, child in ipairs(self.target.children) do
        if not child.visible then
            goto continue
        end

        if child.percent_width and child.percent_width > 0 then
            total_percent = total_percent + child.percent_width
        else
            total_width = total_width + child.width
        end

        if child.percent_height and child.percent_height > 0 then
            child.height = (rt - rb) * child.percent_height / 100
        end

        ::continue::
    end

    local width = self.target.width - total_width - (num - 1) * self.gap
    if width > 0 then
        for _, child in ipairs(self.target.children) do
            if not child.visible then
                goto continue
            end

            if child.percent_width and child.percent_width > 0 then
                child.width = width * child.percent_width / total_percent
            end

            ::continue::
        end
    end

    width = 0

    for _, child in ipairs(self.target.children) do
        if not child.visible then
            goto continue
        end

        width = width + child.width + self.gap
         ::continue::
    end

    width = width - self.gap

    local pos = 0
    if self.content_h_align == UIAlign.CENTER then
        pos = (self.target.width - width) / 2
    elseif self.content_h_align == UIAlign.RIGHT then
        pos = self.target.width - width
    end

    for _, child in ipairs(self.target.children) do
        if not child.visible then
            goto continue
        end

        local cl, cr, ct, cb = child:get_bounds(self.target)
        local x, y = child:get_position()

        if self.content_v_align == UIAlign.TOP then
            y = y + (rt - ct)
        elseif self.content_v_align == UIAlign.CENTER then
            y = y + (rt + rb) / 2 - (ct + cb) / 2
        else
            y = y + (rb - cb)
        end

        x = x - cl + pos

        child:set_position(x, y)
        pos = pos + (cr - cl) + self.gap

        self:update_child_display(child)

        ::continue::
    end
end

return HorizontalLayout
