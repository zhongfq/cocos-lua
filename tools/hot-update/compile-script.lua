return function (path)
    assert(#path > 0)

    local shell = require "core.shell"
    local LUAC = ''

    if shell.OS == 'osx' then
        LUAC = "../bin/osx/luac"
    elseif shell.OS == 'linux' then
        LUAC = "../bin/linux/luac"
    else
        error('not support yet: ' .. shell.OS)
    end

    LUAC = shell.realpath(LUAC)

    print('compile script: ' .. path)

    for _, f in ipairs(shell.list(path, "*.lua")) do
        assert(string.find(f, '^src/') or string.find(f, '^res/'), f)
        print('  luac: ' .. f)
        os.execute(shell.format('cd ${path} && ${LUAC} -o ${f} ${f}'))
    end
end