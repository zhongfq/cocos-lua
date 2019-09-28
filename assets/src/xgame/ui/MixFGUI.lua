local class     = require "xgame.class"
local MixScene  = require "xgame.ui.MixScene"
local FGUINode  = require "xgame.ui.FGUINode"

local MixFGUI = class("MixFGUI", MixScene)

function MixFGUI:ctor()
    self.contentLoader = self:addChild(FGUINode.new())
end

function MixFGUI.Get:rootfgui()
    return self.contentLoader.root
end

return MixFGUI