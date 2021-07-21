if not package.loaded.init then
    package.loaded.init = true

    local path = assert(...)
    local osn = package.cpath:find('?.dll') and 'windows' or
        ((io.popen('uname'):read("*l"):find('Darwin')) and 'macos' or 'linux')

    -- c search path
    local version = string.match(_VERSION, '%d.%d'):gsub('%.', '')
    local suffix = osn == 'windows' and 'dll' or 'so'
    package.cpath = string.format('%s/lua%s/%s/?.%s', path, version, osn, suffix)
    print('lua cpath: ' .. package.cpath)

    -- lua search path
    package.path = path .. "/script/?.lua;./?.lua"
    print('lua path: ' .. package.path)
end