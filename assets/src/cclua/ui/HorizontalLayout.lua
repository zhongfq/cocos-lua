local class         = require "cclua.class"
local Align         = require "cclua.ui.Align"
local LayoutBase    = require "cclua.ui.LayoutBase"

local HorizontalLayout = class("HorizontalLayout", LayoutBase)

function HorizontalLayout:ctor()
    self.gap = 6
    self.contentHAlign = Align.LEFT
    self.contentVAlign = Align.BOTTOM
end

function HorizontalLayout:doLayout()
    if not self.target.stage then
        return
    end

    local _, _, rt, rb = self.target:getBounds(self.target)
    local totalPercent = 0
    local totalWidth = 0
    local num = 0

    for _, child in ipairs(self.target.children) do
        if not child.visible then
            goto continue
        end

        if child.percentWidth and child.percentWidth > 0 then
            totalPercent = totalPercent + child.percentWidth
        else
            totalWidth = totalWidth + child.width
        end

        if child.percentHeight and child.percentHeight > 0 then
            child.height = (rt - rb) * child.percentHeight / 100
        end

        ::continue::
    end

    local width = self.target.width - totalWidth - (num - 1) * self.gap
    if width > 0 then
        for _, child in ipairs(self.target.children) do
            if not child.visible then
                goto continue
            end

            if child.percentWidth and child.percentWidth > 0 then
                child.width = width * child.percentWidth / totalPercent
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
    if self.contentHAlign == Align.CENTER then
        pos = (self.target.width - width) / 2
    elseif self.contentHAlign == Align.RIGHT then
        pos = self.target.width - width
    end

    for _, child in ipairs(self.target.children) do
        if not child.visible then
            goto continue
        end

        local cl, cr, ct, cb = child:getBounds(self.target)
        local x, y = child.x, child.y

        if self.contentVAlign == Align.TOP then
            y = y + (rt - ct)
        elseif self.contentVAlign == Align.CENTER then
            y = y + (rt + rb) / 2 - (ct + cb) / 2
        else
            y = y + (rb - cb)
        end

        x = x - cl + pos

        child.x = x
        child.y = y
        pos = pos + (cr - cl) + self.gap

        self:updateChildDisplay(child)

        ::continue::
    end
end

return HorizontalLayout