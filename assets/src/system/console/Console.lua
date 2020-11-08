local class         = require "xgame.class"
local R             = require "xgame.R"
local Mediator      = require "xgame.Mediator"
local Event         = require "xgame.event.Event"
local FGUI          = require "xgame.ui.FGUI"
local ui            = require "xgame.ui.ui"
local runtime       = require "xgame.runtime"
local UIPackage     = require "fgui.UIPackage"
local UIEventType   = require "fgui.UIEventType"
local FileBrowser   = require "system.console.FileBrowser"
local LogCat        = require "system.console.LogCat"

local CONSOLE_RES = 'res/ui/console.fui'

local M = class("Console", Mediator)

function M:onCreate()
    Mediator.onCreate(self)

    local tabController = self.view.fgui:resolve('panel#tab')
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
    end)

    self.tab = {
        SWF = fileBrowser,
        LOG = logcat,
    }

    -- init toggle button
    local btnOpen = self.view:addChild(ui.inflate {
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
        local curr = self.tab[tabController.selectedPage]
        if self.view.fguiNode.visible then
            self.view.fguiNode.visible = false
            curr:stop()
        else
            self.view.fguiNode.visible = true
            curr:start()
        end
    end
    btnOpen.cobj.touchEnabled = true
    btnOpen.cobj:addClickEventListener(click)
    click() -- hide console panel
end

local UI = class('ConsoleUI', FGUI)

function UI:ctor()
    self.mediatorClass = M
    self:loadAssets(CONSOLE_RES)
    self:createUI("console", "main")
end

function UI:assets()
    return R.new()
        :fromFGUI(CONSOLE_RES)
end

return UI