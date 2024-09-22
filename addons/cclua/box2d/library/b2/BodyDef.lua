---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.BodyDef

---A body definition holds all the data needed to construct a rigid body.
---You can safely re-use body definitions. Shapes are added to a body after construction.
---@class b2.BodyDef 
---@field type b2.BodyType
---@field position b2.Vec2
---@field angle number
---@field linearVelocity b2.Vec2
---@field angularVelocity number
---@field linearDamping number
---@field angularDamping number
---@field allowSleep boolean
---@field awake boolean
---@field fixedRotation boolean
---@field bullet boolean
---@field enabled boolean
---@field userData b2.BodyUserData
---@field gravityScale number
local BodyDef = {}

---@return any
function BodyDef:__gc() end

---This constructor sets the body definition default values.
---@return b2.BodyDef
function BodyDef.new() end

return BodyDef