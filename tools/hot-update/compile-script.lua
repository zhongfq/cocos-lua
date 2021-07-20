return function (path)
    assert(#path > 0)

    local shell = require "core.shell"
    local LUAC = ''

    if shell.OS == 'osx' then
        LUAC = "../lua/macos/lua54/luac"
    elseif shell.OS == 'linux' then
        LUAC = "../lua/linux/lua54/luac"
    else
        LUAC = "../lua/windows/lua54/luac"
    end

    LUAC = shell.realpath(LUAC)

    print('compile script: ' .. path)

    for _, f in ipairs(shell.list(path, "*.lua")) do
        assert(string.find(f, '^src/') or string.find(f, '^res/'), f)
        print('  luac: ' .. f)
        os.execute(shell.format('cd ${path} && ${LUAC} -o ${f} ${f}'))
    end
end