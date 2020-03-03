local Array         = require "xgame.Array"
local Event         = require "xgame.event.Event"
local swf           = require "xgame.swf.swf"
local FLMovieClip   = require "xgame.swf.FLMovieClip"

local FLTab = swf.class("FLTab", FLMovieClip)

function FLTab:ctor()
    self._selectedIndex = 0
    self._options = Array.new()
    self.pages = Array.new()
    for i = 1, math.maxinteger do
        local option = self.ns['option' .. i]
        local page = self.ns['page' .. i]
        if option then
            assert(page, 'page' .. i .. ' not found')
            page.visible = false
            self.pages:pushBack(page)
            self._options:pushBack(option)
            option.selected = false
            option:addListener(Event.CHANGE, self._onChange, self)
            if i == 1 then
                self._selectedIndex = 1
                option.selected = true
                page.visible = true
            end
        else
            break
        end
    end
end

function FLTab:_onChange(target)
    self.selectedIndex = self._options:indexOf(target)
end

function FLTab.Get:selectedItem()
    return self._options[self._selectedIndex]
end

function FLTab.Get:selectedIndex() return self._selectedIndex end
function FLTab.Set:selectedIndex(value)
    local previous = self._selectedIndex
    if previous == value or value <= 0 or value > #self._options then
        return
    end
    if previous > 0 then
        self._options[previous].selected = false
        self._options[previous].touchable = true
        self.pages[previous].visible = false
    end

    self._selectedIndex = value
    self._options[value].selected = true
    self._options[value].touchable = false
    self.pages[value].visible = true
    self:dispatch(Event.CHANGE, self.pages[previous], self.pages[value])
end

return FLTab