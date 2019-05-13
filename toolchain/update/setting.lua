local M = {}

M.BUILTIN = {}
M.BUILTIN.PUBLISH_PATH = "../.."
M.BUILTIN.BUILD_PATH = "../.."
M.BUILTIN.URL = "http://127.0.0.1/cocoslua"
M.BUILTIN.COMPILE = false

M.LOCAL = {}
M.LOCAL.PUBLISH_PATH = "../../wwwroot"
M.LOCAL.BUILD_PATH = "../../wwwroot/current"
M.LOCAL.URL = "http://127.0.0.1/cocoslua"
M.LOCAL.COMPILE = false

return M