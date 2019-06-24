local class     = require "xgame.class"
local Event     = require "xgame.event.Event"
local layouter  = require "xgame.ui.layouter"

local LayoutBase = class("LayoutBase")

function LayoutBase:ctor()
    self.target = false
end

function LayoutBase:notify(action, child)
    if action == "UPDATE" then
        layouter.addUpdate(self)
    end
end

function LayoutBase:update()
end

function LayoutBase:getBounds(target)
    local left, right, top, bottom
    for _, child in ipairs(self.target.children) do
        if not child.visible then
            goto continue
        end

        local cl, cr, ct, cb = child:getBounds(target)
        left = math.min(left or cl, cl)
        right = math.max(right or cr, cr)
        top = math.max(top or ct, ct)
        bottom = math.min(bottom or cb, cb)

        ::continue::
    end

    if not left then
        return 0, 0, 0, 0
    else
        return left, right, top, bottom
    end
end

function LayoutBase:doLayout()
end

function LayoutBase:updateChildDisplay(child)
    child:validateDisplay()

    if child.layout then
        child.layout:doLayout()
    end

    if not child._initialized then
        child._initialized = true
        child:dispatch(Event.CREATION_COMPLETE)
    end
end

return LayoutBase
