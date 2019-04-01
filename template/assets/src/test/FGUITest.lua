local _ENV = setmetatable({}, {__index = _ENV})

local runtime       = require "kernel.runtime"
local timer         = require "kernel.timer"
local Director      = require "cc.Director"
local Scene         = require "cc.Scene"
local UIPackage     = require "fgui.UIPackage"
local UIConfig      = require "fgui.UIConfig"
local GRoot         = require "fgui.GRoot"
local Window        = require "fgui.Window"
local UIEventType   = require "fgui.UIEventType"
local GTween        = require "fgui.GTween"
local TweenPropType = require "fgui.TweenPropType"

function new()
    local scene = Scene.create()
    local root = GRoot.create(scene)

    scene.root = root -- hold

    UIPackage.addPackage("res/fgui/UI/Transition")

    scene.onEnterCallback = function ()
        local startValue = 10000
        local endValue = startValue + math.random(1000, 10000)
        local view = UIPackage.createObject("Transition", "Main")
        local btnGroup = view:getChild("g0")
        local g1 = UIPackage.createObject("Transition", "BOSS")
        local g2 = UIPackage.createObject("Transition", "BOSS_SKILL")
        local g3 = UIPackage.createObject("Transition", "TRAP")
        local g4 = UIPackage.createObject("Transition", "GoodHit")
        local g5 = UIPackage.createObject("Transition", "PowerUp")
        g5:getTransition("t0"):setHook("play_num_now", function ()
            GTween.to(startValue, endValue, 0.3):onUpdate(function (tweener)
                g5:getChild("value").text = tostring(tweener.value.x)
            end)
        end)

        local function play(target)
            btnGroup.visible = false
            root:addChild(target)
            local t = target:getTransition('t0')
            t:play(function ()
                btnGroup.visible = true
                root:removeChild(target)
            end)
        end

        view:getChild("btn0"):addClickListener(function ()
            collectgarbage('collect')
            play(g1)
        end)
        view:getChild("btn1"):addClickListener(function ()
            collectgarbage('collect')
            play(g2)
        end)
        view:getChild("btn2"):addClickListener(function ()
            collectgarbage('collect')
            play(g3)
            root:removeChild(view)
            timer.delay(0.5, function ()
                print('gc')
                collectgarbage('collect')
            end)
        end)

        root:addChild(view)
    end
    
    return scene
end
    
return _ENV