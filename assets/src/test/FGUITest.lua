local class         = require "cclua.class"
local util          = require "cclua.util"
local timer         = require "cclua.timer"
local UIScene       = require "cclua.ui.UIScene"
local FGUINode      = require "cclua.ui.FGUINode"
local UIPackage     = require "fgui.UIPackage"
local GRoot         = require "fgui.GRoot"
local Window        = require "fgui.Window"
local GTween        = require "fgui.GTween"

local FGUITest = class("GUITest", UIScene)

function FGUITest:ctor()
    self.fgui = self:addChild(FGUINode.new())
    local root = self.fgui.root
    root.name = 'fguiTest'
    UIPackage.addPackage("res/fui/UI/Transition")
    UIPackage.addPackage("res/fui/UI/Bag")

    local window = Window.create()
    window.contentPane = UIPackage.createObject("Bag", "BagWin")
    -- window:center()
    window.modal = true
    local list = window.contentPane.list
    list.itemRenderer = function (index, obj)
        obj.icon = string.format('res/fui/icons/i%d.png', math.random(0, 9))
        obj.text = string.format('%d', math.random(1, 100))
    end
    list.virtual = true
    list.numItems = 20
    util.dumpUserValue(list)


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
            g5.value.text = tostring(tweener.value.x)
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
        timer.delay(0.1, function ()
            collectgarbage('collect')
        end)
    end

    view.btn0:addClickListener(function ()
        collectgarbage('collect')
        play(g1)
    end)
    view.btn1:addClickListener(function ()
        collectgarbage('collect')
        play(g2)
    end)
    view.btn2:addClickListener(function ()
        collectgarbage('collect')
        play(g3)
        cclua.popScene()
        timer.delay(4, function ()
            print('gc')
            collectgarbage('collect')
        end)
    end)

    view.btn3:addClickListener(function ()
        print("click btn3")
        window:show()
        util.dumpUserValue(root)
    end)

    view.btn4:addClickListener(function ()
        print("click btn4")
        local window = Window.create()
        window.contentPane = UIPackage.createObject("Bag", "BagWin")
        window:show()
        util.dumpUserValue(root)
    end)

    root:addChild(view)

    util.dumpUserValue(self.cobj, 'scene')
    util.dumpUserValue(root.displayObject, 'displayObject')
    util.dumpUserValue(root, 'root')
end
    
return FGUITest