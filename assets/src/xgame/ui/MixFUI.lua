local class     = require "xgame.class"
local MixScene  = require "xgame.ui.MixScene"
local GRoot     = require "fui.GRoot"

local MixFUI = class("MixFUI", MixScene)

function MixFUI:ctor()
    self.rootfui = GRoot.create(self.cobj)
end

return MixFUI