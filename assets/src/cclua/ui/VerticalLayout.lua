local class         = require "cclua.class"
local Align         = require "cclua.ui.Align"
local LayoutBase    = require "cclua.ui.LayoutBase"

local VerticalLayout = class("VerticalLayout", LayoutBase)

function VerticalLayout:ctor()
    self.gap = 6
    self.contentHAlgin = Align.LEFT
    self.contentVAlign = Align.BOTTOM
end

function VerticalLayout:doLayout()
    if not self.target.stage then
        return
    end

    local rl, rr = self.target:getBounds(self.target)
    local totalPercent = 0
    local totalHeight = 0
    local num = 0

    for _, child in ipairs(self.target.children) do
        if not child.visible then
            goto continue
        end

        if child.percentHeight and child.percentHeight > 0 then
            totalPercent = totalPercent + child.percentHeight
        else
            totalHeight = totalHeight + child.height
        end

        if child.percentWidth and child.percentWidth > 0 then
            child.width = (rr - rl) * child.percentWidth / 100
        end

        ::continue::
    end

    local height = self.target.height - totalHeight - (num - 1) * self.gap
    if height > 0 then
        for _, child in ipairs(self.target.children) do
            if not child.visible then
                goto continue
            end

            if child.percentHeight and child.percentHeight > 0 then
                child.height = height * child.percentHeight / totalPercent
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
    if self.contentVAlign == Align.CENTER then
        pos = (self.target.height - height) / 2
    elseif self.contentVAlign == Align.TOP then
        pos = self.target.height - height
    end

    local children = self.target.children
    for i = #children, 1, -1 do
        local child = children[i]
        if not child.visible then
            goto continue
        end

        local cl, cr, ct, cb = child:getBounds(self.target)
        local x, y = child.x, child.y

        if self.contentHAlgin == Align.RIGHT then
            x = x + (rr - cr)
        elseif self.contentHAlgin == Align.CENTER then
            x = x + (rl + rr) / 2  - (cl + cr) / 2
        else
            x = x + (rl - cl)
        end

        y = y - cb + pos

        child.x = x
        child.y = y
        pos = pos + (ct - cb) + self.gap

        self:updateChildDisplay(child)

        ::continue::
    end
end

return VerticalLayout