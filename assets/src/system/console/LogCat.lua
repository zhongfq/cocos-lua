local class         = require "cclua.class"
local Array         = require "cclua.Array"
local runtime       = require "cclua.runtime"
local Dispatcher    = require "cclua.Dispatcher"

local LogCat = class('LogCat', Dispatcher)

function LogCat:ctor(context)
    self.context = context
    self.logs = Array.new()
    self.maxIndex = 0

    self.list = context.view.fgui.panel.logList
    self.list.itemRenderer = function (idx, item)
        idx = idx + 1
        if item.customData == self.maxIndex and item.customData ~= idx then
            self.maxIndex = self.maxIndex - 1
        end
        item.content.text = self.logs[idx]
        item.customData = idx
        self.maxIndex = math.max(self.maxIndex, idx)
    end
    self.list.virtual = true

    local btnClear = context.view.fgui.panel.btnClear
    btnClear:addClickListener(function ()
        self.logs:clear()
        self.maxIndex = 0
        self.list.numItems = #self.logs
    end)

    local btnSend = context.view.fgui.panel.btnSend
    btnSend:addClickListener(function ()
        print('todo: handle cmd')
    end)
end

function LogCat:_readLog()
    if not self.logFile then
        self.logFile = io.open(runtime.logPath, "r")
    end
    if not self.logFile then
        return
    end
    local scrollToBottom = self.maxIndex == #self.logs
    for value in string.gmatch(self.logFile:read("*a"), "[^\n\r]+") do
        self.logs:pushBack(value)
    end
    self.list.numItems = #self.logs
    if scrollToBottom then
        self.list:scrollToView(#self.logs - 1)
    end
end

function LogCat:start()
    self.context:unschedule(self._updateHandler)
    self._updateHandler = self.context:schedule(0.2, function ()
        self:_readLog()
    end)
    self:_readLog()
end

function LogCat:stop()
    self.context:unschedule(self._updateHandler)
end

return LogCat