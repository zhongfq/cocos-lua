local class         = require "xgame.class"
local Array         = require "xgame.Array"
local http          = require "xgame.http"
local Event         = require "xgame.event.Event"
local Dispatcher    = require "xgame.Dispatcher"
local UIEventType   = require "fgui.UIEventType"

local FileBrowser = class('FileBrowser', Dispatcher)

function FileBrowser:ctor(context, url)
    self.context = context
    self.dirs = Array.new({})
    self.url = url

    self.list = context.view.fgui:resolve('panel.fileList')
    self.list:addEventListener(UIEventType.ClickItem, function (context)
        local data = context.data.customData
        if data.name == '../' then
            self.url = data.url
            self.dirs:pop()
            self.list.numItems = #self.dirs:back()
        elseif string.find(data.url, '/$') then
            self.url = data.url
            self.dirs:pushBack({})
            self:_doRequest()
        else
            self:dispatch(Event.SELECT, data)
        end
    end)
    self.list.itemRenderer = function (idx, item)
        local data = self.dirs:back()[idx + 1]
        item.customData = data
        item:getChild('title').text = data.name
        item:getChild('date').text = data.date
        item:getChild('size').text = data.size
    end
end

function FileBrowser:_doRequest()
    http.block(function ()
        local status, data = http {url = self.url}
        if status ~= 200 then
            return
        end

        local filter = {}
        for _, v in ipairs(self.dirs:back()) do
            if v.name ~= '../' then
                filter[v] = true
            end
        end

        local changed = not next(filter)
        local arr = Array.new()
        for line in string.gmatch(data, '[^\n\r]+') do
            local href, name, date, size = string.match(line,
                '<a href="(.*)">(.*)</a> *([%w%-]+ [%w:]+) +([%w%-]+)')
            if href then
                if not filter[name] then
                    changed = true
                else
                    filter[name] = nil
                end
                arr:pushBack({
                    url = self.url .. href,
                    name = name,
                    date = date,
                    size = size,
                })
            end
        end

        if #self.dirs > 1 then
            arr:pushFront({
                url = string.match(self.url, '(.+/)[^/]+/?$'),
                name = "../",
                date = "",
                size = "",
            })
        end

        if changed or next(filter) then
            self.dirs[#self.dirs] = arr
            self.list.numItems = #arr
        end
    end)
end

function FileBrowser:start()
    self.context:unschedule(self._updateHandler)
    self._updateHandler = self.context:schedule(4, function ()
        self:_doRequest()
    end)
    self:_doRequest()
end

function FileBrowser:stop()
    self.context:unschedule(self._updateHandler)
end

return FileBrowser