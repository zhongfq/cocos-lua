local shell     = require "core.shell"
local simulator = require "core.simulator"

-- local assetsPath = '../../assets'
-- do
return function (assetsPath)
    shell.addSearchPath(assetsPath .. '')
    shell.addSearchPath(assetsPath .. '/src')

    local assets = {}

    local function addPath(path, verbose)
        path = string.gsub(path, '//', '/')
        if string.find(path, "./", 1, true) == 1 then
            path = string.sub(path, 3)
        end
        if #path > 0 and (not assets[path] or verbose) then
            assets[path] = true
            print("  builtin assets: <= " .. path)
        end
    end

    local function sortAssets(assets)
        local arr = {}
        for path in pairs(assets) do
            arr[#arr + 1] = path
        end
        table.sort(arr)
        return arr
    end

    local function addFolder(dir, pattern)
        print(string.format("add folder: '%s' '%s'", dir, pattern))
        for _, path in ipairs(shell.list(assetsPath .. '/' .. dir, pattern)) do
            if #dir > 0 then
                addPath(dir .. '/' .. path)
            else
                addPath(path)
            end
        end
    end

    local function addClass(classname, ...)
        print(string.format('add class: %s', classname))
        local cls = require(classname)
        for _, path in pairs(sortAssets(cls:assets(...))) do
            addPath(path, true)
        end
    end

    addPath('builtin.assets')
    -- addFolder('', '*.lua')
    addFolder('res', '*')
    addFolder('src', '*')

    return assets
end