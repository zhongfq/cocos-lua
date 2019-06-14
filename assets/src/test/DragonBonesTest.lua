local class     = require "xgame.class"
local UIScene   = require "xgame.ui.UIScene"
local DBFactory = require "db.Factory"

local DragonBonesTest = class('DragonBonesTest', UIScene)

function DragonBonesTest:ctor()
    local factory = DBFactory.getFactory()
    ---- hello
    -- factory:loadDragonBonesData("res/dragonbones/mecha_1002_101d_show/mecha_1002_101d_show_ske.json")
    -- factory:loadTextureAtlasData("res/dragonbones/mecha_1002_101d_show/mecha_1002_101d_show_tex.json")
    -- local armatureDisplay = factory:buildArmatureDisplay("mecha_1002_101d", "mecha_1002_101d_show")
    -- armatureDisplay:getAnimation():play("idle")
    -- armatureDisplay:setPosition(500, 200)
    -- scene:addChild(armatureDisplay)




    ---- dragonbones event
    -- factory:loadDragonBonesData("res/dragonbones/mecha_1004d/mecha_1004d_ske.json")
    -- factory:loadTextureAtlasData("res/dragonbones/mecha_1004d/mecha_1004d_tex.json")
    -- local armatureDisplay = factory:buildArmatureDisplay("mecha_1004d")
    -- armatureDisplay:getEventDispatcher():setEnabled(true)
    -- -- armatureDisplay:getEventDispatcher():addCustomEventListener("complete", function( event )
    -- --     olua.with(event:getUserData(), 'db.EventObject', function (obj)
    -- --         print(obj.animationState.name)
    -- --     end)
    -- -- end)
    -- armatureDisplay:addDBEventListener("complete", function( event )
    --     print( event.animationState.name )
    --     if event.animationState.name == "skill_03" then
    --         armatureDisplay:getAnimation():fadeIn("walk", 0.2)
    --     end
    -- end)
    -- armatureDisplay:getAnimation():play("skill_03")
    -- armatureDisplay:setPosition(500, 200)
    -- scene:addChild(armatureDisplay)




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
    -- local listener = EventListenerTouchOneByOne:create()
    -- local indexOf = function( tb, value )
    --     for i, v in ipairs( tb ) do
    --         if v == value then
    --             return i
    --         end
    --     end
    -- end
    -- listener.onTouchBegan = function( touch, event )
    --     local animationName = armatureDisplayD:getAnimation():getLastAnimationName()
    --     if animationName ~= "" then
    --         local animationNames = armatureDisplayD:getAnimation():getAnimationNames()
    --         local animationIndex = (indexOf(animationNames, animationName) + 1) % #animationNames
    --         if animationIndex == 0 then
    --             animationIndex = 1
    --         end
    --         armatureDisplayD:getAnimation():play(animationNames[animationIndex])
    --     else
    --         armatureDisplayD:getAnimation():play()
    --     end
    --     animationName = armatureDisplayD:getAnimation():getLastAnimationName()
    --     armatureDisplayA:getAnimation():play(animationName)
    --     armatureDisplayB:getAnimation():play(animationName)
    --     armatureDisplayC:getAnimation():play(animationName)
    -- end
    -- local eventDispatcher = scene:getEventDispatcher()
    -- eventDispatcher:addEventListenerWithSceneGraphPriority(listener, scene)




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
    -- armatureDisplay:addDBEventListener("complete", function( event )

    -- end)
    -- armatureDisplay:getAnimation():play("idle", 0)
    -- armatureDisplay:setPosition(400, 100)
    -- armatureDisplay:setScale(0.25)
    -- scene:addChild(armatureDisplay)

    -- for i, v in ipairs( suitConfigs[2] ) do
    --     local partArmatureData = factory:getArmatureData(v)
    --     factory:replaceSkin(armatureDisplay:getArmature(), partArmatureData.defaultSkin)
    -- end

    -- local replaceSuitParts = {}
    -- local replaceSuitIndex = 1
    -- local listener = EventListenerTouchOneByOne:create()
    -- listener.onTouchBegan = function( touch, event )
    --     if #replaceSuitParts == 0 then
    --         replaceSuitIndex = replaceSuitIndex + 1
    --         if replaceSuitIndex >= #suitConfigs then
    --             replaceSuitIndex = 1
    --         end
    --         for i, v in ipairs( suitConfigs[replaceSuitIndex] ) do
    --             table.insert( replaceSuitParts, v)
    --         end
    --     end
    --     local partIndex = math.random( 1, #replaceSuitParts)
    --     local partArmatureName = replaceSuitParts[partIndex]
    --     local partArmatureData = factory:getArmatureData(partArmatureName)
    --     factory:replaceSkin(armatureDisplay:getArmature(), partArmatureData.defaultSkin)
    --     for i = #replaceSuitParts, 1, -1 do
    --         if i <= partIndex then
    --             table.remove( replaceSuitParts, i )
    --         end
    --     end
    -- end
    -- local eventDispatcher = scene:getEventDispatcher()
    -- eventDispatcher:addEventListenerWithSceneGraphPriority(listener, scene)




    ---- replace slot display
    -- factory:loadDragonBonesData("res/dragonbones/mecha_1004d_show/mecha_1004d_show_ske.json")
    -- factory:loadTextureAtlasData("res/dragonbones/mecha_1004d_show/mecha_1004d_show_tex.json")
    -- factory:loadDragonBonesData("res/dragonbones/weapon_1004_show/weapon_1004_show_ske.json")
    -- factory:loadTextureAtlasData("res/dragonbones/weapon_1004_show/weapon_1004_show_tex.json")
    -- local armatureDisplay = factory:buildArmatureDisplay("mecha_1004d")
    -- armatureDisplay:getAnimation():play()
    -- armatureDisplay:setPosition(500, 200)
    -- scene:addChild(armatureDisplay)

    -- local rightWeaponIndex = 0
    -- local leftWeaponIndex = 0
    -- local weaponDisplayNames = {"weapon_1004_r", "weapon_1004b_r", "weapon_1004c_r", "weapon_1004d_r", "weapon_1004e_r"}
    -- local label
    -- local listener = EventListenerTouchOneByOne:create()
    -- listener.onTouchBegan = function( touch, event )
    --     local pos = touch:getLocation()
    --     local posX = pos.x
    --     if posX < 550 then
    --         rightWeaponIndex = rightWeaponIndex + 1
    --         rightWeaponIndex = rightWeaponIndex % #weaponDisplayNames
    --         if rightWeaponIndex == 0 then
    --             rightWeaponIndex = 1
    --         end
    --         local displayName = weaponDisplayNames[rightWeaponIndex]
    --         factory:replaceSlotDisplay("weapon_1004_show", "weapon", "weapon_r", displayName, armatureDisplay:getArmature():getSlot("weapon_hand_r"))
    --     elseif posX >= 550 and posX < 800 then
    --         leftWeaponIndex = leftWeaponIndex + 1
    --         leftWeaponIndex = leftWeaponIndex % 5
    --         if leftWeaponIndex == 0 then
    --             leftWeaponIndex = 1
    --         end
    --         armatureDisplay:getArmature():getSlot("weapon_hand_l"):setDisplayIndex(leftWeaponIndex)
    --     else
    --         local logoSlot = armatureDisplay:getArmature():getSlot("logo")
    --         if logoSlot:getDisplay() == label then
    --             logoSlot:setDisplay(logoSlot:getRawDisplay(), 0)
    --         else
    --             label = require( "cc.Label" ):create()
    --             label:setString("ReplaceSlot")
    --             logoSlot:setDisplay(label, 0)
    --         end
    --     end
    -- end
    -- local eventDispatcher = scene:getEventDispatcher()
    -- eventDispatcher:addEventListenerWithSceneGraphPriority(listener, scene)



    ---- boundingBox
    factory:loadDragonBonesData("res/dragonbones/mecha_2903/mecha_2903_ske.json")
    factory:loadTextureAtlasData("res/dragonbones/mecha_2903/mecha_2903_tex.json")
    factory:loadDragonBonesData("res/dragonbones/bounding_box_tester/bounding_box_tester_ske.json")
    factory:loadTextureAtlasData("res/dragonbones/bounding_box_tester/bounding_box_tester_tex.json")
    local armatureDisplay = factory:buildArmatureDisplay("mecha_2903d")
    local boundingBoxTester = factory:buildArmatureDisplay("tester")
    local targetA = boundingBoxTester:getArmature():getSlot("target_a"):getDisplay()
    local targetB = boundingBoxTester:getArmature():getSlot("target_b"):getDisplay()
    local line = boundingBoxTester:getArmature():getBone("line")
    local pointA = boundingBoxTester:getArmature():getBone("point_a")
    local pointB = boundingBoxTester:getArmature():getBone("point_b")
    armatureDisplay.debugDraw = true
    armatureDisplay:setPosition(500, 200)
    boundingBoxTester:setPosition(500, 100)
    line.offsetMode = 2
    pointA.offsetMode = 2
    pointB.offsetMode = 2
    armatureDisplay:getAnimation():play("walk")
    boundingBoxTester:getAnimation():play("0")
    self.cobj:addChild(armatureDisplay)
    self.cobj:addChild(boundingBoxTester)
end
    
return DragonBonesTest