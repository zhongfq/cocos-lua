local M = {}

local KEY = 'hello-key'

local shards = {
    {NAME = "shard.xgame", PATTERN = '^src/xgame/'},
    {NAME = "shard.main", PATTERN = ".*"},
}

M.BUILTIN = {
    NAME = 'BUILTIN',
    PUBLISH_PATH = "..",
    URL = "http://127.0.0.1/cclua",
    RUNTIME = '1.0.0',
    SIDE_BY_SIDE = false,
    COMPILE = false,
    ENCRYPT_METADATA = false,
    ENCRYPT_KEY = KEY,
}

M.LOCAL = {
    NAME = 'LOCAL',
    PUBLISH_PATH = "../../wwwroot/dev",
    URL = "http://192.168.0.80/cclua/dev",
    RUNTIME = '1.0.0',
    SIDE_BY_SIDE = false,
    BUILD_LINK = true,
    COMPILE = false,
    ENCRYPT_METADATA = false,
    ENCRYPT_KEY = KEY,
    SHARDS = shards,
}

M.UPDATE = {
    NAME = 'UPDATE',
    PUBLISH_PATH = "../../wwwroot/v1",
    URL = "http://192.168.0.80/cclua/v1",
    RUNTIME = '1.0.0',
    SIDE_BY_SIDE = true,
    BUILD_LINK = true,
    COMPILE = false,
    ENCRYPT_METADATA = false,
    ENCRYPT_KEY = KEY,
    SHARDS = shards,
}

return M