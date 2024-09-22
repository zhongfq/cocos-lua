---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Component

---
---@class cc.Component : cc.Ref
---@field enabled boolean 
---@field name string 
---@field owner cc.Node 
local Component = {}

---@return cc.Component
function Component.create() end

---@return string
function Component:getName() end

---@return cc.Node
function Component:getOwner() end

---@return boolean
function Component:init() end

---@return boolean
function Component:isEnabled() end

---\js ctor
---@return cc.Component
function Component.new() end

function Component:onAdd() end

function Component:onEnter() end

function Component:onExit() end

function Component:onRemove() end

---@param r any
---@return boolean
function Component:serialize(r) end

---@param enabled boolean
function Component:setEnabled(enabled) end

---@param name string
function Component:setName(name) end

---@param owner cc.Node
function Component:setOwner(owner) end

---@param delta number
function Component:update(delta) end

return Component