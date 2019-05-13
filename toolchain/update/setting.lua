local M = {}

local modules = {
    {NAME = "xgame", PATTERN = '^src/xgame/'},
    {NAME = "main", PATTERN = ".*"},
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
    MODULES = modules,
}

return M