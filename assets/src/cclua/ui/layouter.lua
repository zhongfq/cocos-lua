local Event     = require "cclua.Event"
local runtime   = require "cclua.runtime"

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
            for layout in pairs(units) do
                layout:update()
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

local function addUpdate(layout)
    assert(layout.update, "no update function")
    if not running then
        running = true
        runtime.on(Event.RUNTIME_UPDATE, update)
    end
    layouts[layout] = true
end

return {addUpdate = addUpdate}