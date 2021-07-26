loadfile('../lua/script/init.lua')('../lua')

local toolset = require "toolset"

local ASSETS = '../../assets'

for _, v in ipairs(toolset.list(ASSETS, '%.fui$')) do
    local dir, name = string.match(v, '(.*)/([^/]+)%.fui$')
    local files = {}
    for _, res in ipairs(toolset.list(ASSETS .. '/' .. dir, name .. '.*')) do
        if not string.find(res, '%.lua$') then
            res = dir .. '/' .. res
            files[#files + 1] = '"' .. res .. '"'
        end
    end
    table.sort(files)
    files = table.concat(files, ',\n')
    local path = toolset.format('${ASSETS}/${dir}/${name}.lua')
    local f = io.open(path, 'w')
    print('build fui: ' .. path)
    f:write(toolset.format([[
        -- AUTO BUILD, DON'T MODIFY!

        return {
            files = {
                ${files}
            }
        }
    ]]))
end