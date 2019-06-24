local shell     = require "core.shell"
local simulator = require "core.simulator"

-- local assetsPath = '../../assets'
-- do
return function (assetsPath)
    shell.addSearchPath(assetsPath .. '/src')

    local assets = {}

    local function addPath(path)
        path = string.gsub(path, '//', '/')
        if string.find(path, "./", 1, true) == 1 then
            path = string.sub(path, 3)
        end
        if #path > 0 and not assets[path] then
            assets[path] = true
            print("   builtin assets: <= " .. path)
            return true
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
        print(string.format('add folder: %s', dir))
        for _, path in ipairs(shell.list(assetsPath .. '/' .. dir, pattern)) do
            if #dir > 0 then
                addPath(dir .. '/' .. path)
            else
                addPath(path)
            end
        end
    end

    local function addClass(cls, ...)
        print(string.format('add class: %s', cls.classname))
        for _, path in pairs(sortAssets(cls:assets(...))) do
            if #path > 0 and not addPath(path) then
                print("   builtin assets: <= " .. path)
            end
        end
    end

    addFolder('', '*.lua')

    addFolder('res/dragonbones/mecha_1002_101d_show')
    -- addClass(require('test.DragonBonesTest'))

    return assets
end