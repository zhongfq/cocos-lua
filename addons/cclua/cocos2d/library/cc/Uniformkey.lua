---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Uniformkey

---@type cc.Uniformkey
local VALUE

---
---@enum cc.Uniformkey
local Uniformkey = {
    ---Ambient color.
    UNIFORM_AMBIENT_COLOR = 0,
    ---cos(Time).
    UNIFORM_COS_TIME = 9,
    ---\}
    UNIFORM_MAX = 15,
    ---MultiView Model view projection matrix.
    UNIFORM_MULTIVIEW_MVP_MATRIX = 5,
    ---MultiView Projection matrix.
    UNIFORM_MULTIVIEW_P_MATRIX = 2,
    ---Model view projection matrix.
    UNIFORM_MVP_MATRIX = 4,
    ---Model view matrix.
    UNIFORM_MV_MATRIX = 3,
    ---Normal matrix.
    UNIFORM_NORMAL_MATRIX = 6,
    ---Projection matrix.
    UNIFORM_P_MATRIX = 1,
    ---Random number.
    UNIFORM_RANDOM01 = 10,
    ---\{
    ---Sampler 0-3, used for texture.
    UNIFORM_SAMPLER0 = 11,
    UNIFORM_SAMPLER1 = 12,
    UNIFORM_SAMPLER2 = 13,
    UNIFORM_SAMPLER3 = 14,
    ---sin(Time).
    UNIFORM_SIN_TIME = 8,
    ---Time.
    UNIFORM_TIME = 7,
}

return Uniformkey