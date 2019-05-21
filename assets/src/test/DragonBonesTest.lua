local DBFactory = require "db.Factory"

local M = {}

function M.new()
    local Scene = require "cc.Scene"
    local scene = Scene.create()

    local factory = DBFactory.getFactory()
    factory:loadDragonBonesData("res/dragonbones/mecha_1002_101d_show/mecha_1002_101d_show_ske.json")
    factory:loadTextureAtlasData("res/dragonbones/mecha_1002_101d_show/mecha_1002_101d_show_tex.json")
    local armatureDisplay = factory:buildArmatureDisplay("mecha_1002_101d", "mecha_1002_101d_show")
    armatureDisplay:getAnimation():play("idle")
    armatureDisplay:setPosition(400, 200)

    scene:addChild(armatureDisplay)

    return scene
end
    
return M


