---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.Fixture

---A fixture is used to attach a shape to a body for collision detection. A fixture
---inherits its transform from its parent. Fixtures hold additional non-geometric data
---such as friction, collision filters, etc.
---Fixtures are created via b2Body::CreateFixture.
---\warning you cannot reuse fixtures.
---@class b2.Fixture 
---@field body b2.Body Get the parent body of this fixture. This is nullptr if the fixture is not attached. \return the parent body.
---@field density number Get the density of this fixture.
---@field filterData b2.Filter Get the contact filtering data.
---@field friction number Get the coefficient of friction.
---@field next b2.Fixture Get the next fixture in the parent body's fixture list. \return the next shape.
---@field restitution number Get the coefficient of restitution.
---@field restitutionThreshold number Get the restitution velocity threshold.
---@field sensor boolean Is this fixture a sensor (non-solid)? \return the true if the shape is a sensor.
---@field shape b2.Shape Get the child shape. You can modify the child shape, however you should not change the number of vertices because this will crash some collision caching mechanisms. Manipulating the shape may lead to non-physical behavior.
---@field type b2.Shape.Type Get the type of the child shape. You can use this to down cast to the concrete shape. \return the shape type.
---@field userData b2.FixtureUserData Get the user data that was assigned in the fixture definition. Use this to store your application specific data.
local Fixture = {}

---@return any
function Fixture:__gc() end

---Dump this fixture to the log file.
---@param bodyIndex integer
function Fixture:dump(bodyIndex) end

---Get the fixture's AABB. This AABB may be enlarge and/or stale.
---If you need a more accurate AABB, compute it using the shape and
---the body transform.
---@param childIndex integer
---@return b2.AABB
function Fixture:getAABB(childIndex) end

---Get the parent body of this fixture. This is nullptr if the fixture is not attached.
---@return b2.Body # the parent body.
function Fixture:getBody() end

---Get the density of this fixture.
---@return number
function Fixture:getDensity() end

---Get the contact filtering data.
---@return b2.Filter
function Fixture:getFilterData() end

---Get the coefficient of friction.
---@return number
function Fixture:getFriction() end

---Get the mass data for this fixture. The mass data is based on the density and
---the shape. The rotational inertia is about the shape's origin. This operation
---may be expensive.
---@param massData b2.MassData
function Fixture:getMassData(massData) end

---Get the next fixture in the parent body's fixture list.
---@return b2.Fixture # the next shape.
function Fixture:getNext() end

---Get the coefficient of restitution.
---@return number
function Fixture:getRestitution() end

---Get the restitution velocity threshold.
---@return number
function Fixture:getRestitutionThreshold() end

---Get the child shape. You can modify the child shape, however you should not change the
---number of vertices because this will crash some collision caching mechanisms.
---Manipulating the shape may lead to non-physical behavior.
---@return b2.Shape
function Fixture:getShape() end

---Get the type of the child shape. You can use this to down cast to the concrete shape.
---@return b2.Shape.Type # the shape type.
function Fixture:getType() end

---Get the user data that was assigned in the fixture definition. Use this to
---store your application specific data.
---@return b2.FixtureUserData
function Fixture:getUserData() end

---Is this fixture a sensor (non-solid)?
---@return boolean # the true if the shape is a sensor.
function Fixture:isSensor() end

---Cast a ray against this shape.
---@param output b2.RayCastOutput # the ray-cast results.
---@param input b2.RayCastInput # the ray-cast input parameters.
---@param childIndex integer # the child shape index (e.g. edge index)
---@return boolean
function Fixture:rayCast(output, input, childIndex) end

---Call this if you want to establish collision that was previously disabled by b2ContactFilter::ShouldCollide.
function Fixture:refilter() end

---Set the density of this fixture. This will _not_ automatically adjust the mass
---of the body. You must call b2Body::ResetMassData to update the body's mass.
---@param density number
function Fixture:setDensity(density) end

---Set the contact filtering data. This will not update contacts until the next time
---step when either parent body is active and awake.
---This automatically calls Refilter.
---@param filter b2.Filter
function Fixture:setFilterData(filter) end

---Set the coefficient of friction. This will _not_ change the friction of
---existing contacts.
---@param friction number
function Fixture:setFriction(friction) end

---Set the coefficient of restitution. This will _not_ change the restitution of
---existing contacts.
---@param restitution number
function Fixture:setRestitution(restitution) end

---Set the restitution threshold. This will _not_ change the restitution threshold of
---existing contacts.
---@param threshold number
function Fixture:setRestitutionThreshold(threshold) end

---Set if this fixture is a sensor.
---@param sensor boolean
function Fixture:setSensor(sensor) end

---Test a point for containment in this fixture.
---@param p b2.Vec2 # a point in world coordinates.
---@return boolean
function Fixture:testPoint(p) end

return Fixture