local preferences   = require "kernel.preferences"

local M = {}
M.SERVERS = {
    www = {
        HOST            = "codetypes.com",
        PORT            = 9000,
        ROOT_URL        = "http://127.0.0.1/cocoslua",
        VERSION_URL     = "http://127.0.0.1/cocoslua/version",
    }
}

local function loadConf()
    local name = "www"
    name = preferences.getString('server.conf.name', name)
    M.use(M.SERVERS[name])
end

function M.use(info)
    info = info or M.SERVERS['www']
    M.HOST = assert(info.HOST, "HOST")
    M.PORT = assert(info.PORT, "PORT")
    M.ROOT_URL = assert(info.ROOT_URL, "ROOT_URL")
    M.VERSION_URL = assert(info.VERSION_URL, "VERSION_URL")
end

function M.reset()
    preferences.setString('server.conf.name', 'www')
    preferences:flush()
    loadConf()
end

loadConf()

return M