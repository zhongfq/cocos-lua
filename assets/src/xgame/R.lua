local M = {}
M.__index = M

function M.new()
    return setmetatable({assets = {}}, M)
end

function M:__pairs()
    return next, self.assets
end

function M:fromPath(path)
    assert(path, "no path")
    self.assets[path] = true
    return self
end

function M:fromSWF(path)
    path = string.gsub(path, "/", ".")
    path = string.gsub(path, "%.swf$", "")
    local data = require(path)
    for _, v in ipairs(data.files) do
        self.assets[v] = true
    end
    return self
end

function M:fromLayout(symbol)
    local ui = require "xgame.ui.ui"
    for _, path in ipairs(ui.getData(symbol).files) do
        self.assets[path] = true
    end
    return self
end

function M:fromFGUI(path)
    path = path:gsub('/', '.'):gsub('.fui$', '')
    local data = require(path)
    for _, v in ipairs(data.files) do
        self.assets[v] = true
    end
    return self
end

function M:fromDB(dbPath)
    error('TODO')
end

function M:fromRange(fmt, from, to)
    for i = from, to do
        self.assets[string.format(fmt, i)] = true
    end
    return self
end

function M:fromClass(cls, ...)
    if type(cls) == 'string' then
        cls = require(cls)
    end
    return self:merge(cls:assets(...))
end

function M:fromArray(arr, from, to)
    from = from or 1
    to = to or #arr
    for i = from, to do
        local path = arr[i]
        if path then
            self.assets[path] = true
        else
            break
        end
    end
    return self
end

function M:merge(other)
    for k, v in pairs(other) do
        self.assets[k] = v
    end
    return self
end

return M