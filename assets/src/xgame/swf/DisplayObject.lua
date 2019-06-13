local class             = require "xgame.class"
local Event             = require "xgame.event.Event"
local Align           = require "xgame.ui.Align"
local UIObject          = require "xgame.ui.UIObject"
local ColorTransform    = require "xgame.swf.ColorTransform"

local DisplayObject = class("DisplayObject", UIObject)

function DisplayObject:ctor(cobj)
    self._color_transform = false
    self._stage = false
    self._rootnode = false
    self.name = cobj.name or ""
    self.horizontal_align = Align.NONE
    self.horizontal_center = 0
    self.left = 0
    self.right = 0
    self.vertical_align = Align.NONE
    self.vertical_center = 0
    self.top = 0
    self.bottom = 0
    self.cobj_type = "swf"
    rawset(self, "cobj", assert(cobj))
end

function DisplayObject.Get:initialized()
    return true
end

function DisplayObject:validate_display()
end

function DisplayObject.Get:rootnode()
    if not self._rootnode then
        self._rootnode = self.parent.rootnode
    end
    return self._rootnode
end

function DisplayObject:remove_self()
    if self.parent then
        self.parent:remove_child(self)
    end
end

function DisplayObject:set_scale(sx, sy)
    self.cobj:set_scale(sx, sy)
end

function DisplayObject:get_scale()
    return self.cobj:get_scale()
end

function DisplayObject:set_position(x, y)
    self.cobj:set_position(x, y)
end

function DisplayObject:get_position()
    return self.cobj:get_position()
end

function DisplayObject:set_shader(shader_type, shader)
    self.cobj:set_shader(shader_type, shader)
end

function DisplayObject:get_shader(shader_type)
    return self.cobj:get_shader(shader_type)
end

function DisplayObject:local_to_global(x, y)
    x, y = self.cobj:local_to_global(x, y)
    local rootnode = self.rootnode
    if rootnode and rootnode.cobj then
        x, y = rootnode.cobj:swf_to_world_space(x, y)
    end
    return x, y
end

function DisplayObject:global_to_local(x, y)
    local rootnode = self.rootnode
    if rootnode and rootnode.cobj then
        x, y = rootnode.cobj:world_to_swf_space(x, y)
    end
    return self.cobj:global_to_local(x, y)
end

function DisplayObject:get_bounds(target, ...)
    return self.cobj:get_bounds(target.cobj, ...)
end

function DisplayObject:run_action(action)
    return self.cobj:run_action(action)
end

function DisplayObject:stop_action(action)
   self.cobj:stop_action(action) 
end

function DisplayObject:stop_all_actions()
    self.cobj:stop_all_actions()
end

function DisplayObject:stop_action_by_tag(tag)
    self.cobj:stop_action_by_tag(tag)
end

function DisplayObject:stop_all_actions_by_tag(tag)
    self.cobj:stop_all_actions_by_tag(tag)
end

function DisplayObject:stop_actions_by_flags(flags)
    self.cobj:stop_actions_by_flags(flags)
end

function DisplayObject.Get:color_transform()
    if not self._color_transform then
        self._color_transform = ColorTransform.new(
            self.cobj:get_color_transform())
    end
    return self._color_transform
end

function DisplayObject.Set:color_transform(value)
    self._color_transform = value
    self.cobj:set_color_transform(value.mul_r, value.mul_g, value.mul_b,
        value.mul_a, value.add_r, value.add_g, value.add_b, value.add_a)
end

function DisplayObject.Get:scale_x() return self.cobj.scale_x end
function DisplayObject.Set:scale_x(value)
    self.cobj.scale_x = value
end

function DisplayObject.Get:scale_y() return self.cobj.scale_y end
function DisplayObject.Set:scale_y(value)
    self.cobj.scale_y = value
end

function DisplayObject.Get:x() return self.cobj.x end
function DisplayObject.Set:x(value)
    self.cobj.x = value
end

function DisplayObject.Get:y() return self.cobj.y end
function DisplayObject.Set:y(value)
    self.cobj.y = value
end

function DisplayObject.Get:rotation() return self.cobj.rotation end
function DisplayObject.Set:rotation(value)
    self.cobj.rotation = value
end

function DisplayObject.Get:alpha() return self.cobj.alpha end
function DisplayObject.Set:alpha(value)
    self.cobj.alpha = value
end

function DisplayObject.Get:visible() return self.cobj.visible end
function DisplayObject.Set:visible(value)
    self.cobj.visible = value
end

function DisplayObject.Get:parent() return self._parent end

function DisplayObject.Get:width() return self.cobj.width end

function DisplayObject.Get:height() return self.cobj.height end

function DisplayObject.Get:stage() return self._stage end
function DisplayObject:_set_stage(value)
    --remove form stage
    if not value and self._stage then
        local stage = self._stage
        if stage.focus == self then
            stage.focus = false
        end
        self:dispatch_event(Event.REMOVED_FORM_STAGE)
        stage:dispatch_event(Event.REMOVED_FORM_STAGE, self)
    end

    self._stage = value

    --add to stage
    if value then
        self:dispatch_event(Event.ADDED_TO_STAGE)
        value:dispatch_event(Event.ADDED_TO_STAGE, self)
    end
end

return DisplayObject
