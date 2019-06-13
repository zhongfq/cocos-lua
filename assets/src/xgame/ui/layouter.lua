local Event     = require "xgame.event.Event"
local runtime   = require "xgame.runtime"

local running = false
local layouts = {}

local function reset()
    local units = layouts
    layouts = setmetatable({}, {__mode = "k"})
    return units
end

local function update()
    local function doUpdate(times)
        if times > 0 and next(layouts) then
            local units = reset()
            for target in pairs(units) do
                target:update()
            end
            doUpdate(times - 1)
        end
        if not next(layouts) then
            running = false
            runtime.off(Event.RUNTIME_UPDATE, update)
        end
    end
    doUpdate(3)
end

local function addUpdate(target)
    assert(target.update, "no update function")
    if not running then
        running = true
        runtime.on(Event.RUNTIME_UPDATE, update)
    end
    layouts[target] = true
end

return {addUpdate = addUpdate}