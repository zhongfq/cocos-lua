local class = require "xgame.class"

local FLPoint = class("FLPoint")

function FLPoint:ctor(x, y)
    if type(x) == "table" then
        self.x = assert(x.x)
        self.y = assert(x.y)
    else
        self.x = x or 0
        self.y = y or 0
    end
    assert(type(self.x) == "number")
    assert(type(self.y) == "number")
end

function FLPoint:__add(other)
    return FLPoint.new(self.x + other.x, self.y + other.y)
end

function FLPoint:__sub(other)
    return FLPoint.new(self.x - other.x, self.y - other.y)
end

function FLPoint:__mul(other)
    return FLPoint.new(self.x * other.x, self.y * other.y)
end

function FLPoint:__div(other)
    return FLPoint.new(self.x / other.x, self.y / other.y)
end

function FLPoint.Get:length()
    return math.sqrt(self.x * self.x + self.y * self.y)
end

function FLPoint:__tostring()
    return string.format("(x=%f, y=%f)", self.x, self.y)
end

return FLPoint
