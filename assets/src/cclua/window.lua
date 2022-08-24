-- window.getVisibleBounds
-- window.getVisibleSize
-- window.getFrameSize
-- window.setFrameSize
-- window.getDesignSize
-- window.setDesignSize
-- window.convertToCameraSpace

local window = require("cclua.window")

function window.getFitScale()
    local width, height = window.getFrameSize()
    local dw, dh = window.getDesignSize()
    return math.max(width / dw, height / dh)
end

return window