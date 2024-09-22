---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.PixelFormat

---@type ccb.PixelFormat
local VALUE

---
---@enum ccb.PixelFormat
local PixelFormat = {
    ---! 8-bit textures used as masks
    A8 = 5,
    ---! 16-bit textures used as masks
    AI88 = 7,
    ---! ATITC-compressed texture: ATC_EXPLICIT_ALPHA
    ATC_EXPLICIT_ALPHA = 19,
    ---! ATITC-compressed texture: ATC_INTERPOLATED_ALPHA
    ATC_INTERPOLATED_ALPHA = 20,
    ---! ATITC-compressed texture: ATC_RGB
    ATC_RGB = 18,
    ---! auto detect the type
    AUTO = 0,
    ---! 32-bit texture: BGRA8888
    BGRA8888 = 1,
    D24S8 = 24,
    DEFAULT = 0,
    ---! ETC-compressed texture: ETC
    ETC = 14,
    ---! 8-bit intensity texture
    I8 = 6,
    MTL_ABGR4 = 23,
    ---! Default texture format: AUTO
    MTL_B5G6R5 = 21,
    MTL_BGR5A1 = 22,
    NONE = -1,
    ---! 2-bit PVRTC-compressed texture: PVRTC2
    PVRTC2 = 12,
    ---! 2-bit PVRTC-compressed texture: PVRTC2 (has alpha channel)
    PVRTC2A = 13,
    ---! 4-bit PVRTC-compressed texture: PVRTC4
    PVRTC4 = 10,
    ---! 4-bit PVRTC-compressed texture: PVRTC4 (has alpha channel)
    PVRTC4A = 11,
    ---! 16-bit texture without Alpha channel
    RGB565 = 4,
    ---! 16-bit textures: RGB5A1
    RGB5A1 = 9,
    ---! 24-bit texture: RGBA888
    RGB888 = 3,
    ---! 16-bit textures: RGBA4444
    RGBA4444 = 8,
    ---! 32-bit texture: RGBA8888
    RGBA8888 = 2,
    ---! S3TC-compressed texture: S3TC_Dxt1
    S3TC_DXT1 = 15,
    ---! S3TC-compressed texture: S3TC_Dxt3
    S3TC_DXT3 = 16,
    ---! S3TC-compressed texture: S3TC_Dxt5
    S3TC_DXT5 = 17,
}

return PixelFormat