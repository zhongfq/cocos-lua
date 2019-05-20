--
-- $id: UIDrawNode.lua O $
--

local class     = require "xgame.class"
local UIView    = require "xgame.display.UIView"
local draw_node = require "kernel.draw_node"

local UIDrawNode = class("UIDrawNode", UIView)

function UIDrawNode:ctor()
end

function UIDrawNode.Get:cobj()
    local cobj = draw_node:create()
    rawset(self, "cobj", cobj)
    return cobj
end

function UIDrawNode:clear()
    self.cobj:clear()
end

function UIDrawNode:begin_fill(texture)
    self.cobj:begin_fill(texture)
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
--  draw_triangles({
--     {x = 0, y = 0, u = 0, v = 1},
--     {x = 0, y = h, u = 0, v = 0},
--     {x = w, y = 0, u = 1, v = 1},
--     {x = w, y = h, u = 1, v = 0},
--  }, {
--     0, 1, 2, 2, 1, 3
--  })
function UIDrawNode:draw_triangles(vertices, indices)
    self.cobj:draw_triangles(vertices, indices)
end

function UIDrawNode:end_fill()
    self.cobj:end_fill()
end

return UIDrawNode
