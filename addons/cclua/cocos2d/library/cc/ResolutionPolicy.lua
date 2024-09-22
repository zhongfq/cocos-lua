---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ResolutionPolicy

---@type cc.ResolutionPolicy
local VALUE

---
---@enum cc.ResolutionPolicy
local ResolutionPolicy = {
    ---The entire application is visible in the specified area without trying to preserve the original aspect ratio.
    ---Distortion can occur, and the application may appear stretched or compressed.
    EXACT_FIT = 0,
    ---The application takes the height of the design resolution size and modifies the width of the internal
    ---canvas so that it fits the aspect ratio of the device.
    ---No distortion will occur however you must make sure your application works on different
    ---aspect ratios.
    FIXED_HEIGHT = 3,
    ---The application takes the width of the design resolution size and modifies the height of the internal
    ---canvas so that it fits the aspect ratio of the device.
    ---No distortion will occur however you must make sure your application works on different
    ---aspect ratios.
    FIXED_WIDTH = 4,
    ---The entire application fills the specified area, without distortion but possibly with some cropping,
    ---while maintaining the original aspect ratio of the application.
    NO_BORDER = 1,
    ---The entire application is visible in the specified area without distortion while maintaining the original
    ---aspect ratio of the application. Borders can appear on two sides of the application.
    SHOW_ALL = 2,
    UNKNOWN = 5,
}

return ResolutionPolicy