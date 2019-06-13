local class         = require "xgame.class"
local Align         = require "xgame.ui.Align"
local LayoutBase    = require "xgame.ui.LayoutBase"

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

    local layoutParams = child.layoutParams
    local horizontalAlign = layoutParams.horizontalAlign
    local verticalAlign = layoutParams.verticalAlign
    if horizontalAlign ~= Align.NONE or verticalAlign ~= Align.NONE then
        local cl, cr, ct, cb = child:getBounds(self.target)
        local x, y = child.x, child.y

        -- x align
        if horizontalAlign == Align.LEFT then
            x = x + (rl - cl) + layoutParams.left
        elseif horizontalAlign == Align.CENTER then
            x = x + ((rl + rr) / 2  - (cl + cr) / 2) + layoutParams.horizontalCenter
        elseif horizontalAlign == Align.RIGHT then
            x = x + (rr - cr) - layoutParams.right
        end

        -- y align
        if verticalAlign == Align.TOP then
            y = y + (rt - ct) - layoutParams.top
        elseif verticalAlign == Align.CENTER then
            y = y + (rt + rb) / 2 - (ct + cb) / 2 + layoutParams.verticalCenter
        elseif verticalAlign == Align.BOTTOM then
            y = y + (rb - cb) + layoutParams.bottom
        end

        child.x = x
        child.y = y
    end

    LayoutBase.updateChildDisplay(self, child)
end

return AbsoluteLayout
