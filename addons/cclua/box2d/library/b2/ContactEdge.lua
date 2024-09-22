---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.ContactEdge

---A contact edge is used to connect bodies and contacts together
---in a contact graph where each body is a node and each contact
---is an edge. A contact edge belongs to a doubly linked list
---maintained in each attached body. Each contact has two contact
---nodes, one for each attached body.
---@class b2.ContactEdge 
---@field other b2.Body
---@field contact b2.Contact
---@field prev b2.ContactEdge
---@field next b2.ContactEdge
local ContactEdge = {}

---@return any
function ContactEdge:__gc() end

return ContactEdge