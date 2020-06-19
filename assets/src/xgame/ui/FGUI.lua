local class     = require "xgame.class"
local window    = require "xgame.window"
local Align     = require "xgame.ui.Align"
local UILayer   = require "xgame.ui.UILayer"
local FGUINode  = require "xgame.ui.FGUINode"

local FGUI = class('FGUI', UILayer)

function FGUI:ctor()
    self.contentLoader = self:addChild(FGUINode.new())
end

function FGUI.Get:rootfgui()
    return self.contentLoader.root
end

return FGUI