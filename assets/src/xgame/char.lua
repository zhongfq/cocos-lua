local utf8 = utf8
local string = string

local M = {}
M.__index = M

function M.new(str)
    return setmetatable({
        _str = str,
        _len = utf8.len(str),
    }, M)
end

function M:__len()
    return self._len
end

function M:__tostring()
    return self._str
end

function M:__concat(other)
    return M.new(self._str .. other._str)
end

function M:indexOf(ch, startFrom)
    startFrom = startFrom or 1
    for i = startFrom, self._len do
        if self:charAt(i) == ch then
            return i
        end
    end

    return 0 -- not found
end

function M:lastIndexOf(ch, backFrom)
    backFrom = backFrom or self._len
    for i = backFrom, 1, -1 do
        if self:charAt(i) == ch then
            return i
        end
    end

    return 0 -- not found
end

function M:split(delimiter)
    local str = self._str
    local arr = {}
    while true do
        local from, to = string.find(str, delimiter, 1, true)
        if from then
            arr[#arr + 1] = string.sub(str, 1, from - 1)
            str = string.sub(str, to + 1)
        else
            arr[#arr + 1] = str
            break
        end
    end
    return arr
end

function M:charAt(index)
    return utf8.char(utf8.codepoint(self._str, utf8.offset(self._str, index)))
end

function M:charCodeAt(index)
    return utf8.codepoint(self._str, utf8.offset(self._str, index))
end

function M:replace(p, repl)
    return M.new(string.gsub(self._str, p, {[p] = repl}, 1))
end

function M:replaceAll(p, repl)
    return M.new(string.gsub(self._str, p, {[p] = repl}))
end

function M:sub(startIndex, endIndex)
    startIndex = utf8.offset(self._str, startIndex)
    endIndex = utf8.offset(self._str, math.min(endIndex, self._len) + 1)
    return M.new(string.sub(self._str, startIndex, endIndex - 1))
end

return M