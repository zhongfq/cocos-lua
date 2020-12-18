print('hello path:', ...)

local builtinAssets = require "builtin-assets"
local buildManifest = require "build-manifest"
local compileScript = require "compile-script"

local BUILD_PATH = ...

if not BUILD_PATH or #BUILD_PATH == 0 then
    error('not specify build path')
end

local conf = {
    NAME = 'APP-BUILTIN',
    VERSION = "0.0.0",
    RUNTIME = "0.0.0",
    LATEST_MANIFEST = {assets = {}, version = '0.0.0'},
    BUILD_PATH = BUILD_PATH,
    ASSETS_PATH = BUILD_PATH,
    PUBLISH_PATH = BUILD_PATH,
    ASSETS_MANIFEST_PATH = BUILD_PATH .. '/builtin.manifest',
    COMPILE = true,
    URL = "builtin://",
}

builtinAssets = builtinAssets(conf.ASSETS_PATH)
conf.IS_BUILTIN = function (path)
    return builtinAssets[path]
end
conf.SHOULD_BUILD = function (path)
    if builtinAssets[path] then
        return true
    else
        print('remove => ' .. path)
        os.remove(BUILD_PATH .. '/' .. path)
    end
end

compileScript(BUILD_PATH)
buildManifest(conf)