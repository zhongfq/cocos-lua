local shell = require "core.shell"
local setting = require "setting"
local buildManifest = require "build-manifest"
local buildSharding = require "build-sharding"
local builtinAssets = require "builtin-assets"

local ARG_DEBUG = false
local ARG_NAME = 'LOCAL'
local ARG_VERSION = nil
local ARG_URL = nil
local ARG_RUNTIME = nil
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
    elseif c == '--runtime' then
        ARG_RUNTIME = assert(table.remove(args, 1), 'no runtime version')
    elseif c == '--url' then
        ARG_URL = assert(table.remove(args, 1), 'no url')
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
local needBuildLink = not shell.exist(ARG_PUBLISH_PATH .. '/current')
if ARG_NAME == 'BUILTIN' then
    latestManifestPath = setting[ARG_NAME].BUILD_PATH .. '/assets/builtin.manifest'
else
    latestManifestPath = ARG_PUBLISH_PATH .. '/current/assets.manifest'
end
local latestManifest = shell.readJson(latestManifestPath, {assets = {}, version = '0.0.0'})

-- calc current version
ARG_VERSION = ARG_VERSION or shell.nextversion(latestManifest.version)

-- create build conf
local OUTPUT_PATH
local conf = {
    DEBUG = ARG_DEBUG,
    NAME = ARG_NAME,
    VERSION = ARG_VERSION,
    RUNTIME = ARG_RUNTIME or setting[ARG_NAME].RUNTIME,
    LATEST_MANIFEST = latestManifest,
    SHARDS = setting[ARG_NAME].SHARDS,
    BUILD_PATH = setting[ARG_NAME].BUILD_PATH,
    COMPILE = setting[ARG_NAME].COMPILE,
    URL = (ARG_URL or setting[ARG_NAME].URL) .. '/' ..  ARG_VERSION,
    BUILD_LINK = setting[ARG_NAME].BUILD_LINK,
}

if not conf.BUILD_PATH or conf.COMPILE then
    shell.bash 'rm -rf build'
    shell.bash 'mkdir -p build/assets'
    shell.bash 'cp -rf ../../assets/* build/assets'
    conf.BUILD_PATH = 'build'
end

builtinAssets = builtinAssets(conf.BUILD_PATH .. '/assets')
conf.IS_BUILTIN = function (path) return builtinAssets[path] end
conf.ASSETS_MANIFEST_PATH = conf.BUILD_PATH .. '/assets.manifest'
conf.VERSION_MANIFEST_PATH = conf.BUILD_PATH .. '/version.manifest'
conf.PUBLISH_PATH = ARG_PUBLISH_PATH
OUTPUT_PATH = ARG_PUBLISH_PATH .. '/' .. conf.VERSION

if conf.NAME == 'BUILTIN' then
    conf.ASSETS_MANIFEST_PATH = conf.BUILD_PATH .. '/assets/builtin.manifest'
    conf.VERSION_MANIFEST_PATH = nil
    OUTPUT_PATH = conf.BUILD_PATH
    conf.SHOULD_BUILD = function (path)
        return builtinAssets[path]
    end
elseif conf.NAME == 'LOCAL' then
    conf.URL = setting[ARG_NAME].URL .. '/current'
    OUTPUT_PATH = ARG_PUBLISH_PATH .. '/current'
end

local hasUpdate = buildManifest(conf)

if hasUpdate then
    if conf.SHARDS then
        buildSharding(conf)
    end

    if conf.BUILD_PATH ~= OUTPUT_PATH then
        local BUILD_PATH = conf.BUILD_PATH
        print(string.format("publish assets: %s => %s ", BUILD_PATH, OUTPUT_PATH))
        shell.bash 'rm -rf ${OUTPUT_PATH}'
        shell.bash 'mkdir -p ${OUTPUT_PATH}'
        shell.bash 'cp -rf ${BUILD_PATH}/* ${OUTPUT_PATH}'
    end

    needBuildLink = needBuildLink or ARG_DEBUG
end

if conf.BUILD_LINK and needBuildLink then
    shell.bash [[
        cd ${ARG_PUBLISH_PATH}
        ln -sfn ${ARG_VERSION} current
        ln -sfn ${ARG_VERSION} current.ios
        ln -sfn ${ARG_VERSION} current.android
        ln -sfn current/version.manifest version
        ln -sfn current.ios/version.manifest version.ios
        ln -sfn current.android/version.manifest version.android
    ]]
end

if conf.NAME == 'BUILTIN' then
    local data = shell.read(conf.ASSETS_MANIFEST_PATH)
    data = string.gsub(data, '", "date":%d+', '", "date":' .. os.time())
    print('always update builtin manifest asset date')
    shell.write(conf.ASSETS_MANIFEST_PATH, data)
end

-- shell.bash 'rm -rf build'