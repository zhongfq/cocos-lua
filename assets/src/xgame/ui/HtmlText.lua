local class = require "xgame.class"

local HtmlText = class("HtmlText")

function HtmlText:ctor()
    self._arr = {}
end

function HtmlText:append(value)
    self._arr[#self._arr + 1] = {
        text = value
    }
    return self
end

function HtmlText:with(attr, value)
    self._arr[#self._arr][attr] = value
    return self
end

function HtmlText:__tostring()
    local t = {}
    for _, obj in ipairs(self._arr) do
        if obj.text then
            t[#t + 1] = '<font'

            if obj.face then
                t[#t + 1] = ' face="' .. obj.face .. '"'
            end

            if obj.color then
                t[#t + 1] = ' color="' .. obj.color .. '"'
            end

            if obj.size then
                t[#t + 1] = ' size="' .. obj.size .. '"'
            end

            if obj.outline then
                t[#t + 1] = ' outline="' .. obj.outline .. '"'
            end

            if obj.shadow then
                t[#t + 1] = ' shadow="' .. obj.shadow .. '"'
            end

            t[#t + 1] = '>'
            t[#t + 1] = obj.text
            t[#t + 1] = '</font>'
        end
    end

    return table.concat(t, "")
end

function HtmlText:build()
    return self:__tostring()
end

return HtmlText