local bash = require "bash"

local ASSETS = '../../assets'

for _, v in ipairs(bash.list(ASSETS, '*.fui')) do
    local dir, name = string.match(v, '(.*)/([^/]+)%.fui$')
    local files = {}
    for _, res in ipairs(bash.list(ASSETS .. '/' .. dir, name .. '*')) do
        if not string.find(res, '%.lua$') then
            res = dir .. '/' .. res
            files[#files + 1] = '"' .. res .. '"'
        end
    end
    table.sort(files)
    files = table.concat(files, ',\n')
    local path = bash.format('${ASSETS}/${dir}/${name}.lua')
    local f = io.open(path, 'w')
    print('build fui: ' .. path)
    f:write(bash.format([[
        -- AUTO BUILD, DON'T MODIFY!

        return {
            files = {
                ${files}
            }
        }
    ]]))
end