local class         = require "xgame.class"
local Event         = require "xgame.event.Event"
local MixFGUI       = require "xgame.ui.MixFGUI"
local ui            = require "xgame.ui.ui"
local runtime       = require "xgame.runtime"
local UIPackage     = require "fgui.UIPackage"
local UIEventType   = require "fgui.UIEventType"
local FileBrowser   = require "system.console.FileBrowser"
local LogCat        = require "system.console.LogCat"

local Console = class("Console", MixFGUI)

function Console:ctor()
end

function Console:onCreate()
    UIPackage.addPackage("res/ui/console")

    self.view = UIPackage.createObject("console", "main")
    self.view.width = self.width
    self.view.height = self.height
    self.rootfgui:addChild(self.view)
    self.rootfgui:setSize(self.width, self.height)

    local tabController = self.view:resolve('panel#tab')
    tabController:addEventListener(UIEventType.Changed, function ()
        local prev = self.tab[tabController.previousPage]
        local curr = self.tab[tabController.selectedPage]
        if prev then
            prev:stop()
        end
        if curr then
            curr:start()
        end
        runtime.gc()
    end)

    local logcat = LogCat.new(self)
    logcat:start()

    local fileBrowser = FileBrowser.new(self, 'https://codetypes.com/testswf/')
    fileBrowser:addListener(Event.SELECT, function (_, data)
        if string.find(data.url, '%.swf$') then
            self.visible = false
            self.contentLoader.visible = false
            xGame:startScene('system.console.TestSWF', data.url, function ()
                self.visible = true
                self.contentLoader.visible = true
            end)
        end
    end)

    self.tab = {
        SWF = fileBrowser,
        LOG = logcat,
    }

    -- init toggle button
    local btnOpen = self:addChild(ui.inflate {
        classname = "UILayer",
        horizontalAlign = "left",
        verticalAlign = "bottom",
        width = 80,
        height = 80,
        touchable = true,
        touchChildren = false,
        -- colorType = 1,
        -- color = 0x999999,
    })
    local function click ()
        if self.contentLoader.visible then
            self.contentLoader.visible = false
        else
            self.contentLoader.visible = true
        end
    end
    btnOpen.cobj.touchEnabled = true
    btnOpen.cobj:addClickEventListener(click)
    click() -- hide console panel
end

return Console