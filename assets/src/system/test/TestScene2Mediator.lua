local class     = require "cclua.class"
local Mediator  = require "cclua.Mediator"

local TestScene2Mediator = class('TestScene2Mediator', Mediator)

function TestScene2Mediator:onCreate()
    local view = self.view.view
    self:schedule(1, function ()
        local label = view:resolve('timer')
        label.text = os.date()
        print('update scene2')
    end)
    view:resolve('backBtn'):addClickListener(function ()
        cclua.popScene()
    end)
end

return TestScene2Mediator