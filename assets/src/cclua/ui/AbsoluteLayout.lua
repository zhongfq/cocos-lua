local class         = require "cclua.class"
local Align         = require "cclua.ui.Align"
local LayoutBase    = require "cclua.ui.LayoutBase"

---@class AbsoluteLayout : LayoutBase
local AbsoluteLayout = class("AbsoluteLayout", LayoutBase)

function AbsoluteLayout:doLayout()
    if self.target.stage then
        for _, child in ipairs(self.target.children) do
            self:updateChildDisplay(child)
        end
    end
end

function AbsoluteLayout:notify(action, child)
    if child.stage and action == "UPDATE" then
        self:updateChildDisplay(child)
    end
end

function AbsoluteLayout:updateChildDisplay(child)
    local rl, rr, rt, rb = self.target:getBounds(self.target)
    local width = rr - rl
    local height = rt - rb

    local percent = child.percentWidth
    if percent and percent >= 0 then
        child.width = width * percent / 100
    end

    percent = child.percentHeight
    if percent and percent >= 0 then
        child.height = height * percent / 100
    end

    local horizontalAlign = child.horizontalAlign
    local verticalAlign = child.verticalAlign
    if horizontalAlign ~= Align.NONE or verticalAlign ~= Align.NONE then
        local cl, cr, ct, cb = child:getBounds(self.target)
        local x, y = child.x, child.y

        -- x align
        if horizontalAlign == Align.LEFT then
            x = x + (rl - cl) + child.horizontalOffset
        elseif horizontalAlign == Align.CENTER then
            x = x + ((rl + rr) / 2  - (cl + cr) / 2) + child.horizontalOffset
        elseif horizontalAlign == Align.RIGHT then
            x = x + (rr - cr) - child.horizontalOffset
        end

        -- y align
        if verticalAlign == Align.TOP then
            y = y + (rt - ct) - child.verticalOffset
        elseif verticalAlign == Align.CENTER then
            y = y + (rt + rb) / 2 - (ct + cb) / 2 + child.verticalOffset
        elseif verticalAlign == Align.BOTTOM then
            y = y + (rb - cb) + child.verticalOffset
        end

        child.x = x
        child.y = y
    end

    LayoutBase.updateChildDisplay(self, child)
end

return AbsoluteLayout
