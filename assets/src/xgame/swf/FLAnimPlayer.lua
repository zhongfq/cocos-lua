local class         = require "xgame.class"
local FLLinkedList  = require "xgame.swf.FLLinkedList"
local FLAnim        = require "xgame.swf.FLAnim"

local assert = assert
local string = string

local STATE_DONE = FLAnim.STATE_DONE
local STATE_READY = FLAnim.STATE_READY

local FLAnimPlayer = class("FLAnimPlayer")

function FLAnimPlayer:ctor()
    self._list = FLLinkedList.new()
    self._session = 0
    self._running = true
end

function FLAnimPlayer:clear()
    for _, anim in pairs(self._list) do
        anim:stopChain()
    end
    self._list:clear()
end

function FLAnimPlayer:_obtainSession()
    self._session = self._session + 1
    return self._session
end

function FLAnimPlayer:play(target, label, playOnce, times)
    assert(target, 'no target')
    assert(label, 'no label')
    local anim = FLAnim.new(self:_obtainSession(), target, label,
        playOnce, times)
    self._list:append(anim)
    return anim
end

function FLAnimPlayer:pause()
    if self._running then
        self._running = false
        for _, anim in pairs(self._list) do
            anim:pause()
        end
    end
end

function FLAnimPlayer:resume()
    if not self._running then
        self._running = true
        for _, anim in pairs(self._list) do
            anim:resume()
        end
    end
end

function FLAnimPlayer:update()
    local list = self._list

    if not self._running or list.empty then
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
    while again and not list.empty do
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
                local nextAnim = anim.nextAnim
                anim:dispose()
                anim.nextAnim = nil

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

return FLAnimPlayer
