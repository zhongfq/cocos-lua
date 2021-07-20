return function (path)
    assert(#path > 0)

    local lfs = require "lfs"
    local toolset = require "toolset"
    local LUAC = ''

    if toolset.os == 'macos' then
        LUAC = "../lua/lua54/macos/luac"
    elseif toolset.os == 'linux' then
        LUAC = "../lua/lua54/linux/luac"
    else
        LUAC = "../lua/lua54/windows/luac"
    end

    LUAC = lfs.currentdir() .. '/' .. LUAC

    print('compile script: ' .. lfs.currentdir() .. '/' .. path)

    for _, f in ipairs(toolset.list(path, "%.lua$")) do
        assert(string.find(f, '^src/') or string.find(f, '^res/'), f)
        print('  luac: ' .. f)
        os.execute(toolset.format("cd ${path} && ${LUAC} -o ${f} ${f}"))
    end
end