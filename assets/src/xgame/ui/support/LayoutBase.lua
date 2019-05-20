--
-- $id: LayoutBase.lua O $
--

local class         = require "xgame.class"
local Event         = require "xgame.Event"
local LayoutManager = require "xgame.display.support.LayoutManager"

local LayoutBase = class("LayoutBase")

function LayoutBase:ctor()
    self.target = false
end

function LayoutBase:notify(action, child)
    if action == "UPDATE" then
        LayoutManager:add_update(self)
    end
end

function LayoutBase:update()
    if self.target and self.target.cobj then
        self:do_layout()
    end
end

function LayoutBase:get_bounds(target)
    local left, right, top, bottom
    for _, child in ipairs(self.target.children) do
        if not child.visible then
            goto continue
        end

        local cl, cr, ct, cb = child:get_bounds(target)

        if not left then
            left = cl
            right = cr
            top = ct
            bottom = cb
        else
            left = math.min(left, cl)
            right = math.max(right, cr)
            top = math.max(top, ct)
            bottom = math.min(bottom, cb)
        end

        ::continue::
    end

    if not left then
        return 0, 0, 0, 0
    else
        return left, right, top, bottom
    end
end

function LayoutBase:do_layout()
end

function LayoutBase:update_child_display(child)
    if child.layout then
        child.layout:do_layout()
    end

    child:validate_display()

    if not child._initialized then
        child._initialized = true

        if child.on_creation_complete then
            child:on_creation_complete()
        end

        child:dispatch_event(Event.CREATION_COMPLETE)
    end
end

function LayoutBase:get_relative_bounds()
    local target = self.target
    if target == target.stage then
        return target.stage:get_bounds()
    else
        return 0, target.width, target.height, 0
    end
end

return LayoutBase
