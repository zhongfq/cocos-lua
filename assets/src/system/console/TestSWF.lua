local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local filesystem    = require "xgame.filesystem"
local MixScene      = require "xgame.ui.MixScene"
local UIScroller    = require "xgame.ui.UIScroller"
local ui            = require "xgame.ui.ui"
local LoadTask      = require "xgame.loader.LoadTask"
local SWFNode       = require "xgame.swf.SWFNode"
local swf           = require "xgame.swf.swf"

local TestSWF = class('TestSWF', MixScene)

function TestSWF:ctor(path, callback)
    self.path = path
    self.callback = callback
end

function TestSWF:onDestroy()
    self.callback()
    MixScene.onDestroy(self)
end

function TestSWF:onCreate()
    filesystem.remove(filesystem.localCachePath(self.path))
    local task = LoadTask.new(self.path)
    task:addListener(Event.COMPLETE, function ()
        if self.stage then
            self:loadPath(filesystem.localCachePath(self.path))
        end
    end)
    task:start()
end

function TestSWF:loadPath(path)
    local view = UIScroller.new()
    local node = SWFNode.new()
    node.rootswf = swf.new(path)
    view.multiTouch = true
    view.clippingEnabled = false
    view.bounceEnabled = false
    view.scaleEnabled = true
    view.maxScale = 5
    view.minScale = 0.5
    view.width = self.width
    view.height = self.height
    view:addChild(node)
    view.scrollX = (view.width - node.rootswf.movieWidth) / 2
    self:addChild(view)

    node.rootswf.touchChildren = false
    node.rootswf.touchable = false
    node.width = node.rootswf.movieWidth
    node.height = node.rootswf.movieHeight
    node.touchable = true

    local count = 0
    self(view):onTouchDown(function (_, points)
        if count == 0 then
            node.rootswf:pause()
        end
        for _ in pairs(points) do
            count = count + 1
        end
    end)

    self(view):onTouchUp(function (_, points)
        for _ in pairs(points) do
            count = count - 1
        end
        if count == 0 then
            node.rootswf:resume()
        end
    end)

    local btnClose = self:addChild(self:createBtn('关闭', 0, 0))
    self(btnClose):onClick(function ()
        xGame:popScene()
    end)
    local btnHide = self:addChild(self:createBtn('辅助线', 125, 0))
    self(btnHide):onClick(function ()
        local shape = node.rootswf.children:back()
        shape.visible = not shape.visible
    end)
end

function TestSWF:createBtn(label, x, y)
    return ui.inflate {
        classname = "UILayer",
        horizontalOffset = x,
        horizontalAlign = "right",
        verticalOffset = y,
        verticalAlign = "top",
        width = 120,
        height = 50,
        touchable = true,
        touchChildren = false,
        colorType = 1,
        color = 0x999999,
        children = {
            {
                classname = "UITextField",
                x = 25,
                y = 10,
                text = label,
                color = 0x000000,
                fontSize = 25,
            },
        },
    }
end

return TestSWF