local timer = require "cclua.timer"

local assert, select = assert, select
local xpcall, pairs = xpcall, pairs

assert(not timer.new)

local function createDelay()
    local timestamp = 0
    local head = false
    local tail = false
    local inst = {}

    function inst:clear()
        local entry = {time = math.maxinteger}
        entry.next = entry
        entry.prev = entry
        head = entry
        tail = entry
    end

    function inst:timeout(time, callback, ...) -- time(s)
        assert(callback)
        assert(time >= 0)

        if time == 0 then
            callback(...)
            return
        end

        local entry = {
            time = timestamp + time,
            callback = callback,
            args = select("#", ...) > 0 and {...} or nil,
            next = false,
            prev = false,
        }

        inst:append(entry)

        local handler = function()
            entry.callback = false
        end

        return handler
    end

    function inst:kill(handler)
        if handler then
            handler()
        end
    end

    function inst:append(entry)
        local prev = tail.prev
        if prev ~= head then
            while prev.time > entry.time do
                prev = prev.prev
            end
        end

        local next = prev.next
        entry.prev = prev
        entry.next = next
        prev.next = entry
        next.prev = entry
    end

    function inst:update(delta)
        local __TRACEBACK__ = __TRACEBACK__
        local current = head.next
        timestamp = timestamp + delta
        while timestamp >= current.time do
            local callback = current.callback
            if callback then
                if current.args then
                    xpcall(callback, __TRACEBACK__, table.unpack(current.args))
                else
                    xpcall(callback, __TRACEBACK__)
                end
            end
            current = current.next
        end

        if current ~= head.next then
            head.next = current
            current.prev = head
        end
    end

    inst:clear()

    return inst
end

local function createScheduler()
    local timestamp = 0
    local entries = {}
    local willAddedEntries = {}
    local dispatching = false
    local ref = 0
    local inst = {}

    function inst:schedule(interval, callback)
        assert(callback)
        assert(interval >= 0)

        local usingEntries = dispatching and willAddedEntries or entries

        ref = ref + 1
        usingEntries[ref] = {
            interval = interval,
            time = timestamp + interval,
            callback = callback,
        }

        return ref
    end

    function inst:unschedule(id)
        if id then
            if entries[id] then
                entries[id] = nil
            end
            willAddedEntries[id] = nil
        end
    end

    function inst:clear()
        entries = {}
        willAddedEntries = {}
    end

    function inst:update(delta)
        local __TRACEBACK__ = __TRACEBACK__
        timestamp = timestamp + delta
        dispatching = true
        for _, entry in pairs(entries) do
            local interval = entry.interval
            while timestamp >= entry.time do
                if interval == 0 then
                    entry.time = timestamp
                    xpcall(entry.callback, __TRACEBACK__, delta)
                    break
                else
                    entry.time = entry.time + interval
                    xpcall(entry.callback, __TRACEBACK__, interval)
                end
            end
        end
        for id, entry in pairs(willAddedEntries) do
            entries[id] = entry
            willAddedEntries[id] = nil
        end
        dispatching = false
    end

    return inst
end

function timer.new()
    local scheduler = createScheduler()
    local delay = createDelay()
    local handlers = {}

    local id = false
    local inst = {}

    function inst:update(delta)
        delay:update(delta)
        scheduler:update(delta)
    end

    local function internalDelay(time, tag, callback, ...)
        if time <= 0 then
            callback(...)
            return
        end

        if tag and handlers[tag] then
            print("[timer] kill previous call tagged with %s", tag)
            inst:killDelay(tag)
        end

        local handler = delay:timeout(time, function(...)
            handlers[tag] = nil
            callback(...)
        end, ...)

        tag = tag or handler

        handlers[tag] = handler
    end

    function inst:delay(time, callback, ...)
        internalDelay(time, nil, callback, ...)
    end

    function inst:delayWithTag(time, tag, callback, ...)
        assert(tag)
        internalDelay(time, tag, callback, ...)
    end

    function inst:killDelay(tag)
        assert(tag)
        local handler = handlers[tag]
        if handler then
            handlers[tag] = nil
            delay:kill(handler)
        end
    end

    function inst:killAll()
        for _, handler in pairs(handlers) do
            delay:kill(handler)
        end
        handlers = {}
    end

    function inst:schedule(...)
        return scheduler:schedule(...)
    end

    function inst:unschedule(...)
        scheduler:unschedule(...)
    end

    function inst:clear()
        handlers = {}
        delay:clear()
        scheduler:clear()
    end

    function inst:start()
        if not id then
            id = timer.schedule(0, function (dt)
                inst:update(dt)
            end)
        end
    end

    function inst:stop()
        if id then
            timer.unschedule(id)
            id = false
        end
    end

    return inst
end

return timer