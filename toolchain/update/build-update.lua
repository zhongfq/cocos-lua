local shell = require "core.shell"
local setting = require "setting"
local buildManifest = require "build-manifest"
local buildModule = require "build-module"

local ARG_DEBUG = false
local ARG_NAME = 'LOCAL'
local ARG_VERSION = nil
local ARG_PUBLISH_PATH = nil

-- parse cmd line args
local args = {...}
while #args > 0 do
    local c = table.remove(args, 1)
    if c == '--debug' then
        ARG_DEBUG = true
    elseif c == '--setting' then
        ARG_NAME = assert(table.remove(args, 1), 'no setting name')
        assert(setting[ARG_NAME], 'setting not found: ' .. ARG_NAME)
    elseif c == '--publish-path' then
        ARG_PUBLISH_PATH = assert(table.remove(args, 1), 'no publish path')
    elseif c == '--version' then
        ARG_VERSION = assert(table.remove(args, 1), 'no version')
    end
end

-- check publish directory
ARG_PUBLISH_PATH = ARG_PUBLISH_PATH or setting[ARG_NAME].PUBLISH_PATH
if not shell.exist(ARG_PUBLISH_PATH) then
    error('no such directory: ' .. assert(ARG_PUBLISH_PATH))
end

-- read latest manifest
local latestManifestPath
if ARG_NAME == 'BUILTIN' then
    latestManifestPath = setting[ARG_NAME].BUILD_PATH .. '/assets/builtin.manifest'
else
    latestManifestPath = ARG_PUBLISH_PATH .. '/current/assets.manifest'
end
local latestManifest = shell.readJson(latestManifestPath, {assets = {}, version = '0.0.0'})

-- calc current version
ARG_VERSION = shell.nextversion(ARG_VERSION or latestManifest.version)

-- create build conf
local OUTPUT_PATH
local conf = {
    DEBUG = ARG_DEBUG,
    NAME = ARG_NAME,
    VERSION = ARG_VERSION,
    LATEST_MANIFEST = latestManifest,
    MODULES = setting[ARG_NAME].MODULES,
    BUILD_PATH = setting[ARG_NAME].BUILD_PATH,
    COMPILE = setting[ARG_NAME].COMPILE,
    URL = setting[ARG_NAME].URL .. '/' ..  ARG_VERSION,
}

if not conf.BUILD_PATH or conf.COMPILE then
    shell.bash 'rm -rf build'
    shell.bash 'mkdir -p build/assets'
    shell.bash 'cp -rf ../../assets/* build/assets'
    conf.BUILD_PATH = 'build'
end

conf.ASSETS_MANIFEST_PATH = conf.BUILD_PATH .. '/assets.manifest'
conf.VERSION_MANIFEST_PATH = conf.BUILD_PATH .. '/version.manifest'
conf.PUBLISH_PATH = ARG_PUBLISH_PATH
OUTPUT_PATH = ARG_PUBLISH_PATH .. '/' .. conf.VERSION

if conf.NAME == 'BUILTIN' then
    conf.ASSETS_MANIFEST_PATH = conf.BUILD_PATH .. '/assets/builtin.manifest'
    conf.VERSION_MANIFEST_PATH = nil
    OUTPUT_PATH = conf.BUILD_PATH
elseif conf.NAME == 'LOCAL' then
    conf.URL = setting[ARG_NAME].URL .. '/current'
    OUTPUT_PATH = ARG_PUBLISH_PATH .. '/current'
end

local hasUpdate = buildManifest(conf)

if hasUpdate then
    if conf.MODULES then
        buildModule(conf)
    end

    if conf.BUILD_PATH ~= OUTPUT_PATH then
        local BUILD_PATH = conf.BUILD_PATH
        print(string.format("publish assets: %s => %s ", BUILD_PATH, OUTPUT_PATH))
        shell.bash 'rm -rf ${OUTPUT_PATH}'
        shell.bash 'mkdir -p ${OUTPUT_PATH}'
        shell.bash 'cp -rf ${BUILD_PATH}/* ${OUTPUT_PATH}'
    end
end

-- shell.bash 'rm -rf build'