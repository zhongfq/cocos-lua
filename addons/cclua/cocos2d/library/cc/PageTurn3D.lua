---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PageTurn3D

---This action simulates a page turn from the bottom right hand corner of the screen.
---
---\details It's not much use by itself but is used by the PageTurnTransition.
---Based on an original paper by L Hong et al.
---http://www.parc.com/publication/1638/turning-pages-of-3d-electronic-books.html
---
---\since v0.8.2
---@class cc.PageTurn3D : cc.Grid3DAction
local PageTurn3D = {}

---Create an action with duration, grid size.
---@param duration number # Specify the duration of the PageTurn3D action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@return cc.PageTurn3D # If the creation success, return a pointer of PageTurn3D action; otherwise, return nil.
function PageTurn3D.create(duration, gridSize) end

return PageTurn3D