---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.ContactManager

---
---@class b2.ContactManager 
local ContactManager = {}

---@return any
function ContactManager:__gc() end

---@param proxyUserDataA any
---@param proxyUserDataB any
function ContactManager:addPair(proxyUserDataA, proxyUserDataB) end

function ContactManager:collide() end

---@param c b2.Contact
function ContactManager:destroy(c) end

function ContactManager:findNewContacts() end

---@return b2.ContactManager
function ContactManager.new() end

return ContactManager