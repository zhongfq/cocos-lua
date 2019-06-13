local class         = require "xgame.class"
local util          = require "xgame.util"
local LinkedList    = require "xgame.LinkedList"
local Animation     = require "xgame.swf.Animation"

local assert = assert
local string = string

local STATE_DONE = Animation.STATE_DONE
local STATE_READY = Animation.STATE_READY

local AnimationPlayer = class("AnimationPlayer")

function AnimationPlayer:ctor()
    self._list = LinkedList.new()
    self._session = 0
    self._running = true
end

function AnimationPlayer:clear()
    for _, anim in pairs(self._list) do
        anim:stop_chain()
    end
    self._list:clear()
end

function AnimationPlayer:_obtain_session()
    self._session = self._session + 1
    return self._session
end

function AnimationPlayer:play(target, label, stop_when_end, times)
    assert(target, 'no target')
    assert(label, 'no label')
    local anim = Animation.new(self:_obtain_session(), target, label,
        stop_when_end, times)
    self._list:append(self._list:create_node(anim))
    return anim
end

function AnimationPlayer:pause()
    if self._running then
        self._running = false
        for _, anim in pairs(self._list) do
            anim:pause()
        end
    end
end

function AnimationPlayer:resume()
    if not self._running then
        self._running = true
        for _, anim in pairs(self._list) do
            anim:resume()
        end
    end
end

function AnimationPlayer:update()
    local list = self._list

    if not self._running or list:is_empty() then
        return
    end

    -- update first
    for _, anim in pairs(list) do
        if anim.state ~= STATE_READY then
            anim:update()
        end
    end

    local function push_info(anim)
        local info = anim.debug_info or {}
        info[#info + 1] = string.format("%s:%s", anim.name, anim.label)
        anim.debug_info = info
    end

    -- try ready
    local again = true
    while again and not list:is_empty() do
        again = false
        for node, anim in pairs(list) do
            local anim_state = anim.state
            if anim_state == STATE_READY then
                again = true
                push_info(anim)
                anim:play()
            end

            if anim_state == STATE_DONE then
                again = true
                local next_anim = anim.next_animation
                anim:dispose()
                anim.next_animation = nil

                if next_anim and next_anim.state == STATE_READY then
                    node.target = next_anim
                    next_anim.debug_info = anim.debug_info
                    push_info(next_anim)
                    next_anim:play()
                else
                    list:remove(node)
                end
            end
        end
    end
end

return AnimationPlayer
