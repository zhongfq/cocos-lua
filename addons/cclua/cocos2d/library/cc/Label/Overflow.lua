---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Label.Overflow

---@type cc.Label.Overflow
local VALUE

---
---@enum cc.Label.Overflow
local Overflow = {
    ---In CLAMP mode, when label content goes out of the bounding box, it will be clipped.
    CLAMP = 1,
    NONE = 0,
    ---In RESIZE_HEIGHT mode, you can only change the width of label and the height is changed automatically.
    RESIZE_HEIGHT = 3,
    ---In SHRINK mode, the font size will change dynamically to adapt the content size.
    SHRINK = 2,
}

return Overflow