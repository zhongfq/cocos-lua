local class         = require "xgame.class"
local MixFGUI       = require "xgame.ui.MixFGUI"
local UIPackage     = require "fgui.UIPackage"

local TestScene1 = class("TestScene1", MixFGUI)

function TestScene1:ctor()
    UIPackage.addPackage('res/ui/test')
    
    self.view = UIPackage.createObject('test', 'test-scene1')
    self.view:setSize(self.rootfgui.width, self.rootfgui.height)
    self.rootfgui:addChild(self.view)
end

function TestScene1:onCreate()
    self:schedule(1, function ()
        local label = self.view:resolve('timer')
        label.text = os.date()
        print('update scene1')
    end)
    self.view:resolve('goBtn'):addClickListener(function ()
        xGame:startScene('system.test.TestScene2')
    end)
end

function TestScene1:onDestroy()
    UIPackage.removePackage('res/ui/test')
    MixFGUI.onDestroy(self)
end

return TestScene1