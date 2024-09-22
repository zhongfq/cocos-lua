---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.interface.ContactListener

---Implement this class to get contact information. You can use these results for
---things like sounds and game logic. You can also get contact results by
---traversing the contact lists after the time step. However, you might miss
---some contacts because continuous physics leads to sub-stepping.
---Additionally you may receive multiple callbacks for the same contact in a
---single time step.
---You should strive to make your callbacks efficient because there may be
---many callbacks per time step.
---\warning You cannot create/destroy Box2D entities inside these callbacks.
---@class b2.interface.ContactListener 
local ContactListener = {}

---@return any
function ContactListener:__gc() end

return ContactListener