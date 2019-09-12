local M = {}

local shards = {
    {NAME = "shard.xgame", PATTERN = '^src/xgame/'},
    {NAME = "shard.main", PATTERN = ".*"},
}

M.BUILTIN = {
    PUBLISH_PATH = "..",
    BUILD_PATH = "../..",
    URL = "http://127.0.0.1/cocoslua",
    COMPILE = false,
}

M.LOCAL = {
    PUBLISH_PATH = "../../wwwroot",
    BUILD_PATH = "../../wwwroot/current",
    URL = "http://127.0.0.1/cocoslua",
    COMPILE = false,
    SHARDS = shards,
}

M.UPDATE = {
    PUBLISH_PATH = "../../wwwroot/v1",
    URL = "http://codetypes.com/cocos-lua/v1",
    BUILD_LINK = true,
    COMPILE = false,
    SHARDS = shards,
}

return M