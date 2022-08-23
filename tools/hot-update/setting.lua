local M = {}

local shards = {
    {NAME = "shard.cclua", PATTERN = '^src/cclua/'},
    {NAME = "shard.main", PATTERN = ".*"},
}

M.BUILTIN = {
    NAME = 'BUILTIN',
    PUBLISH_PATH = "..",
    URL = "http://127.0.0.1/cclua",
    RUNTIME = '1.0.0',
    SIDE_BY_SIDE = false,
    COMPILE = false,
}

M.LOCAL = {
    NAME = 'LOCAL',
    PUBLISH_PATH = "../../wwwroot/dev",
    URL = "http://127.0.0.1/cclua",
    RUNTIME = '1.0.0',
    SIDE_BY_SIDE = false,
    BUILD_LINK = true,
    COMPILE = false,
    SHARDS = shards,
}

M.UPDATE = {
    NAME = 'UPDATE',
    PUBLISH_PATH = "../../wwwroot/v1",
    URL = "http://127.0.0.1/cclua",
    RUNTIME = '1.0.0',
    SIDE_BY_SIDE = true,
    BUILD_LINK = true,
    COMPILE = false,
    SHARDS = shards,
}

return M