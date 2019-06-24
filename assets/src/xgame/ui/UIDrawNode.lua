local class     = require "xgame.class"
local UIView    = require "xgame.ui.UIView"
local DrawNode  = require "kernel.DrawNode"

local UIDrawNode = class("UIDrawNode", UIView)

function UIDrawNode:ctor()
end

function UIDrawNode.Get:cobj()
    local cobj = DrawNode.create()
    rawset(self, "cobj", cobj)
    return cobj
end

function UIDrawNode:clear()
    self.cobj:clear()
end

function UIDrawNode:beginFill(texture)
    self.cobj:beginFill(texture)
end

--  y
--  +---------- u
--  |
--  |
--  |
--  |
--  +---------- x
--  v
--
--  drawTriangles({
--     {x = 0, y = 0, u = 0, v = 1},
--     {x = 0, y = h, u = 0, v = 0},
--     {x = w, y = 0, u = 1, v = 1},
--     {x = w, y = h, u = 1, v = 0},
--  }, {
--     0, 1, 2, 2, 1, 3
--  })
function UIDrawNode:drawTriangles(vertices, indices)
    self.cobj:drawTriangles(vertices, indices)
end

function UIDrawNode:endFill()
    self.cobj:endFill()
end

return UIDrawNode
