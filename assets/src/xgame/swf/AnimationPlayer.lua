local class         = require "xgame.class"
local LinkedList    = require "xgame.swf.LinkedList"
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
        anim:stopChain()
    end
    self._list:clear()
end

function AnimationPlayer:_obtainSession()
    self._session = self._session + 1
    return self._session
end

function AnimationPlayer:play(target, label, playOnce, times)
    assert(target, 'no target')
    assert(label, 'no label')
    local anim = Animation.new(self:_obtainSession(), target, label,
        playOnce, times)
    self._list:append(anim)
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

    if not self._running or list:empty() then
        return
    end

    -- update first
    for _, anim in pairs(list) do
        if anim.state ~= STATE_READY then
            anim:update()
        end
    end

    local function pushInfo(anim)
        local info = anim.debugInfo or {}
        info[#info + 1] = string.format("%s:%s", anim.name, anim.label)
        anim.debugInfo = info
    end

    -- try ready
    local again = true
    while again and not list:empty() do
        again = false
        for node, anim in pairs(list) do
            local anim_state = anim.state
            if anim_state == STATE_READY then
                again = true
                pushInfo(anim)
                anim:play()
            end

            if anim_state == STATE_DONE then
                again = true
                local nextAnim = anim.nextAnimation
                anim:dispose()
                anim.nextAnimation = nil

                if nextAnim and nextAnim.state == STATE_READY then
                    node.target = nextAnim
                    nextAnim.debugInfo = anim.debugInfo
                    pushInfo(nextAnim)
                    nextAnim:play()
                else
                    list:remove(node)
                end
            end
        end
    end
end

return AnimationPlayer
