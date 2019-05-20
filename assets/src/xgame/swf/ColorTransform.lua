--
-- $id: ColorTransform.lua O $
--

local class = require "xgame.class"

local ColorTransform = class("ColorTransform")

function ColorTransform:ctor(mul_r, mul_g, mul_b, mul_a, 
    add_r, add_g, add_b, add_a)
    self.mul_r = mul_r or 1
    self.mul_g = mul_g or 1
    self.mul_b = mul_b or 1
    self.mul_a = mul_a or 1
    self.add_r = add_r or 0
    self.add_g = add_g or 0
    self.add_b = add_b or 0
    self.add_a = add_a or 0
end

local function clamp(value)
    return math.max(0, math.min(255, value))
end

function ColorTransform:transform(color)
    local r = clamp((color >> 24 & 0xFF) * self.mul_r + self.add_r)
    local g = clamp((color >> 16 & 0xFF) * self.mul_g + self.add_g)
    local b = clamp((color >> 8 & 0xFF) * self.mul_b + self.add_b)
    local a = clamp((color >> 0 & 0xFF) * self.mul_a + self.add_a)
    return r << 24 | g << 16 | b << 8 | a
end

return ColorTransform
