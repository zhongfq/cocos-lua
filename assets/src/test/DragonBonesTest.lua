local DBFactory = require "db.Factory"
local olua = require( "olua" )

local M = {}

function M.new()
    local Scene = require "cc.Scene"
    local scene = Scene.create()

    local factory = DBFactory.getFactory()
    ---- hello
    -- factory:loadDragonBonesData("res/dragonbones/mecha_1002_101d_show/mecha_1002_101d_show_ske.json")
    -- factory:loadTextureAtlasData("res/dragonbones/mecha_1002_101d_show/mecha_1002_101d_show_tex.json")
    -- local armatureDisplay = factory:buildArmatureDisplay("mecha_1002_101d", "mecha_1002_101d_show")
    -- armatureDisplay:getAnimation():play("idle")
    -- armatureDisplay:setPosition(500, 200)
    -- scene:addChild(armatureDisplay)

    ---- dragonbones event
    factory:loadDragonBonesData("res/dragonbones/mecha_1004d/mecha_1004d_ske.json")
    factory:loadTextureAtlasData("res/dragonbones/mecha_1004d/mecha_1004d_tex.json")
    local armatureDisplay = factory:buildArmatureDisplay("mecha_1004d")
    armatureDisplay:getEventDispatcher():setEnabled(true)
    armatureDisplay:getEventDispatcher():addCustomEventListener("complete", function( event )
        olua.with(event:getUserData(), 'db.EventObject', function (obj)
            print(obj.animationState.name)
        end)
    end)
    armatureDisplay:getAnimation():play("skill_03")
    armatureDisplay:setPosition(500, 200)
    scene:addChild(armatureDisplay)

    ---- replace animation
    -- factory:loadDragonBonesData("res/dragonbones/mecha_2903/mecha_2903_ske.json")
    -- factory:loadTextureAtlasData("res/dragonbones/mecha_2903/mecha_2903_tex.json")
    -- local armatureDisplayA = factory:buildArmatureDisplay("mecha_2903")
    -- local armatureDisplayB = factory:buildArmatureDisplay("mecha_2903b")
    -- local armatureDisplayC = factory:buildArmatureDisplay("mecha_2903c")
    -- local armatureDisplayD = factory:buildArmatureDisplay("mecha_2903d")
    -- local sourceArmatureData = factory:getArmatureData("mecha_2903d")
    -- factory:replaceAnimation(armatureDisplayA:getArmature(), sourceArmatureData)
    -- factory:replaceAnimation(armatureDisplayB:getArmature(), sourceArmatureData)
    -- factory:replaceAnimation(armatureDisplayC:getArmature(), sourceArmatureData)
    -- scene:addChild(armatureDisplayD)
    -- scene:addChild(armatureDisplayC)
    -- scene:addChild(armatureDisplayB)
    -- scene:addChild(armatureDisplayA)
    -- armatureDisplayA:setPosition(200, 200)
    -- armatureDisplayB:setPosition(450, 200)
    -- armatureDisplayC:setPosition(650, 200)
    -- armatureDisplayD:setPosition(900, 200)

    ---- replace skin
    -- local suitConfigs = {
    --     {
    --         "2010600a",
    --         "2010600a_1",
    --         "20208003",
    --         "20208003_1",
    --         "20208003_2",
    --         "20208003_3",
    --         "20405006",
    --         "20509005",
    --         "20703016",
    --         "20703016_1",
    --         "2080100c",
    --         "2080100e",
    --         "2080100e_1",
    --         "20803005",
    --         "2080500b",
    --         "2080500b_1"
    --     },
    --     {
    --         "20106010",
    --         "20106010_1",
    --         "20208006",
    --         "20208006_1",
    --         "20208006_2",
    --         "20208006_3",
    --         "2040600b",
    --         "2040600b_1",
    --         "20509007",
    --         "20703020",
    --         "20703020_1",
    --         "2080b003",
    --         "20801015"
    --     }
    -- }
    -- factory:loadDragonBonesData("res/dragonbones/you_xin/body/body_ske.json")
    -- factory:loadTextureAtlasData("res/dragonbones/you_xin/body/body_tex.json")
    
    -- for i, v in ipairs( suitConfigs ) do
    --     for j, partArmatureName in ipairs( v ) do
    --         local path = "res/dragonbones/you_xin/suit" .. i .. "/" .. partArmatureName .. "/" .. partArmatureName
    --         local jsonPath = path .. "_ske.json"
    --         local texPath = path .. "_tex.json"
    --         factory:loadDragonBonesData(jsonPath)
    --         factory:loadTextureAtlasData(texPath)
    --     end
    -- end

    -- local armatureDisplay = factory:buildArmatureDisplay("body")
    -- armatureDisplay:getEventDispatcher():setEnabled(true)
    -- armatureDisplay:getEventDispatcher():addCustomEventListener("complete", function( event )

    -- end)
    -- armatureDisplay:getAnimation():play("idle", 0)
    -- armatureDisplay:setPosition(500, 100)
    -- armatureDisplay:setScale(0.25)
    -- scene:addChild(armatureDisplay)

    -- for i, v in ipairs( suitConfigs[1] ) do
    --     local partArmatureData = factory:getArmatureData(v)
    --     factory:replaceSkin(armatureDisplay:getArmature(), partArmatureData.defaultSkin)
    -- end

    ---- replace slot display
    -- factory:loadDragonBonesData("res/dragonbones/mecha_1004d_show/mecha_1004d_show_ske.json")
    -- factory:loadTextureAtlasData("res/dragonbones/mecha_1004d_show/mecha_1004d_show_tex.json")
    -- factory:loadDragonBonesData("res/dragonbones/weapon_1004_show/weapon_1004_show_ske.json")
    -- factory:loadTextureAtlasData("res/dragonbones/weapon_1004_show/weapon_1004_show_tex.json")
    -- local armatureDisplay = factory:buildArmatureDisplay("mecha_1004d")
    -- armatureDisplay:getAnimation():play()
    -- armatureDisplay:setPosition(500, 200)
    -- scene:addChild(armatureDisplay)

    return scene
end
    
return M


