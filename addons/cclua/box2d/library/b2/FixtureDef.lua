---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.FixtureDef

---A fixture definition is used to create a fixture. This class defines an
---abstract fixture definition. You can reuse fixture definitions safely.
---@class b2.FixtureDef 
---@field shape b2.Shape
---@field userData b2.FixtureUserData
---@field friction number
---@field restitution number
---@field restitutionThreshold number
---@field density number
---@field isSensor boolean
---@field filter b2.Filter
local FixtureDef = {}

---@return any
function FixtureDef:__gc() end

---The constructor sets the default fixture definition values.
---@return b2.FixtureDef
function FixtureDef.new() end

return FixtureDef