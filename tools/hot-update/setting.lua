local M = {}

local shards = {
    {NAME = "shard.xgame", PATTERN = '^src/xgame/'},
    {NAME = "shard.main", PATTERN = ".*"},
}

M.BUILTIN = {
    PUBLISH_PATH = "..",
    BUILD_PATH = "../..",
    RUNTIME = '1.0.0',
    URL = "http://127.0.0.1/cocoslua",
    COMPILE = false,
}

M.LOCAL = {
    PUBLISH_PATH = "../../wwwroot",
    BUILD_PATH = "../../wwwroot/current",
    URL = "http://192.168.0.80/harbor",
    RUNTIME = '1.0.0',
    COMPILE = false,
    SHARDS = shards,
}

M.UPDATE = {
    PUBLISH_PATH = "../../wwwroot/v1",
    URL = "http://kid-dev.xqw369.com/harbor/v1",
    RUNTIME = '1.0.0',
    BUILD_LINK = true,
    COMPILE = false,
    SHARDS = shards,
}

return M