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

    UIPackage.addPackage("res/fgui/UI/Bag")
    UIConfig.horizontalScrollBar = ""
    UIConfig.verticalScrollBar = ""

    local view = UIPackage.createObject('Bag', 'Main')
    root:addChild(view)

    timer.delay(0.1, function ()
        local window = Window.create()
        window.contentPane = UIPackage.createObject('Bag', 'BagWin')
        window:center()
        window.modal = true
        local list = window.contentPane:getChild("list")
        list:addEventListener(UIEventType.ClickItem, function (eventContext)
            print("click item:", eventContext)
            local item = eventContext.data
            window.contentPane:getChild("n11").icon = item.icon
            window.contentPane:getChild("n13").text = item.text
        end)
        -- list.itemRenderer = function (index, obj)
        --     obj.icon = string.format("res/fgui/icons/i%d.png", math.random(0, 9))
        --     obj.text = string.format("%d", math.random(1, 100))
        -- end
        -- list.numItems = 45

        view:getChild('bagBtn'):addClickListener(function (...)
            print("bagBtn click:", ...)
            window:show()
        end)

        local btn = view:getChild('bagBtn')
        GTween.to(btn.x, btn.x + 400, 2):setTarget(btn, TweenPropType.X)
        printUserValue(GTween.class['.store'])

        timer.delay(1.8, function ()
            GTween.to(btn.x, btn.x + 100, 1):setTarget(btn, TweenPropType.X)
            printUserValue(GTween.class['.store'])
        end)
        timer.delay(2.8, function ()
            GTween.to(btn.x, btn.x - 100, 1):setTarget(btn, TweenPropType.X)
            printUserValue(GTween.class['.store'])
        end)

        timer.delay(5, function ()
            UIPackage.removePackage('Bag')
            collectgarbage('collect')
        end)
    end)
    
    return scene
end
    
return _ENV