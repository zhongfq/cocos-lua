local class = require "xgame.class"
local Mediator = require "xgame.Mediator"

local SWFMediator = class('SWFMediator', Mediator)

function SWFMediator:ctor(view)
end

function SWFMediator:_initMonitor()
    local name = string.format('__SWFMediator_%s__', tostring(self.view))
    local monitor = self:_createMonitor(name)
    monitor.onEnter()
    self.view.rootNode.cobj:addComponent(monitor)
end

function SWFMediator:onDestroy()
    local name = string.format('__SWFMediator_%s__', tostring(self.view))
    self.view.rootNode.cobj:removeComponent(name)
    Mediator.onDestroy(self)
end

return SWFMediator