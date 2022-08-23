return function (dir)
    assert(#dir > 0)
    local toolset = require "toolset"
    local list = {}
    local size = 0

    local CHUNK_META = 1
    local CHUNK_DATA = 2

    local data = io.open(dir .. "/assets.bundle", 'w+b')

    local function add_file(path)
        print('pack file: ' .. path)
        local f = assert(io.open(dir .. '/' .. path, 'rb'), path)
        list[#list + 1] = {
            path = path,
            size = f:seek('end'),
            position = nil,
        }
        f:close()
        -- kind(1)) + path(2 + #path) + data_pos(4)
        size = 1 + (2 + #path) + 4 + size
    end

    for _, path in ipairs(toolset.list(dir .. "/src")) do
        add_file('src/' .. path)
    end

    for _, path in ipairs(toolset.list(dir .. "/res")) do
        add_file('res/' .. path)
    end

    add_file('builtin.manifest')

    table.sort(list, function (a, b)
        return a.path < b.path
    end)

    for _, v in ipairs(list) do
        v.position = size
        -- kind(1)) + data(4 + v.size)
        size = 1 + 4 + v.size + size
    end

    -- write header
    for _, v in ipairs(list) do
        data:write(string.pack("<I1", CHUNK_META))
        data:write(string.pack("<s2", v.path))
        data:write(string.pack("<I4", v.position))
    end

    -- write data
    for _, v in ipairs(list) do
        local f = assert(io.open(dir .. '/' .. v.path, 'rb'))
        data:write(string.pack("<I1", CHUNK_DATA))
        data:write(string.pack("<s4", f:read('*a')))
        f:close()
    end
    toolset.rm "${dir}/builtin.manifest"
    toolset.rmdir "${dir}/src"
    toolset.rmdir "${dir}/res"
end