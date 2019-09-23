local class     = require "xgame.class"
local MixScene  = require "xgame.ui.MixScene"
local GRoot     = require "fgui.GRoot"

local MixFGUI = class("MixFGUI", MixScene)

function MixFGUI:ctor()
    self.rootfgui = GRoot.create(self.cobj)
    self.rootfgui:setSize(self.cobj.width, self.cobj.height)
end

return MixFGUI