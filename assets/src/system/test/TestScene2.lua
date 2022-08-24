local class     = require "cclua.class"
local UIScene   = require "cclua.ui.UIScene"
local UIPackage = require "fgui.UIPackage"
local GRoot     = require "fgui.GRoot"

local TestScene2 = class('TestScene2', UIScene)

function TestScene2:ctor()
    self.mediatorClass = require('system.test.TestScene2Mediator')

    self.rootfgui = GRoot.create(self.cobj)
    self.rootfgui:setSize(self.cobj.width, self.cobj.height)

    self.view = UIPackage.createObject('test', 'test-scene2')
    self.rootfgui:addChild(self.view)
end

return TestScene2