loadfile('../lua/script/init.lua')('../lua')

local toolset = require "toolset"
local setting = require "setting"
local buildManifest = require "build-manifest"
local buildSharding = require "build-sharding"
local builtinAssets = require "builtin-assets"
local compileScript = require "compile-script"

local conf = setmetatable({}, {__index = setting.LOCAL})

-- parse cmd line args
local args = {...}
while #args > 0 do
    local c = table.remove(args, 1)
    if c == '--debug' then
        conf.DEBUG = true
    elseif c == '--setting' then
        local NAME = assert(table.remove(args, 1), 'no setting name')
        setmetatable(conf, {__index = assert(setting[NAME], 'setting not found: ' .. NAME)})
    elseif c == '--publish-path' then
        conf.PUBLISH_PATH = assert(table.remove(args, 1), 'no publish path')
    elseif c == '--runtime' then
        conf.RUNTIME = assert(table.remove(args, 1), 'no runtime version')
    elseif c == '--url' then
        conf.URL = assert(table.remove(args, 1), 'no url')
    elseif c == '--compile' then
        conf.COMPILE = true
    elseif c == '--version' then
        conf.VERSION = assert(table.remove(args, 1), 'no version')
    elseif c == '--encrypt-metadata' then
        conf.ENCRYPT_METADATA = true
    elseif c == '--encrypt-key' then
        conf.ENCRYPT_KEY = assert(table.remove(args, 1), 'no encrypt key')
    end
end

-- check publish directory
if not toolset.exist(conf.PUBLISH_PATH) then
    error('no such directory: ' .. assert(conf.PUBLISH_PATH))
end

-- build path
if not conf.SIDE_BY_SIDE then
    if conf.NAME == 'BUILTIN' then
        conf.BUILD_PATH = "../.."
    else
        conf.BUILD_PATH = conf.PUBLISH_PATH .. '/current'
        toolset.bash [[
            cd ${conf.PUBLISH_PATH}
            mkdir -p current && cd current
            ln -sfn ../../../assets assets
        ]]
    end
end

-- read latest manifest && calc current version
local latestManifestPath
local needBuildLink = not toolset.exist(conf.PUBLISH_PATH .. '/current')
if conf.NAME == 'BUILTIN' then
    latestManifestPath = '../../assets/builtin.metadata'
else
    latestManifestPath = conf.PUBLISH_PATH .. '/current/assets.metadata'
end
conf.LATEST_MANIFEST = toolset.read_metadata(latestManifestPath, conf)
conf.VERSION = conf.VERSION or toolset.next_version(conf.LATEST_MANIFEST.version)
conf.URL = conf.URL .. '/' .. (conf.SIDE_BY_SIDE and conf.VERSION or 'current')

if not conf.BUILD_PATH or conf.COMPILE then
    toolset.rmdir 'build'
    toolset.mkdir 'build/assets'
    toolset.cp('../../assets', 'build/assets')
    toolset.rm('build/assets/builtin.metadata')
    conf.BUILD_PATH = 'build'
end

conf.ASSETS_PATH = conf.BUILD_PATH .. '/assets'
builtinAssets = builtinAssets(conf.ASSETS_PATH)
conf.IS_BUILTIN = function (path) return builtinAssets[path] end
conf.ASSETS_MANIFEST_PATH = conf.BUILD_PATH .. '/assets.metadata'
conf.VERSION_MANIFEST_PATH = conf.BUILD_PATH .. '/version.metadata'

-- create build conf
local OUTPUT_PATH = conf.PUBLISH_PATH .. '/' .. (conf.SIDE_BY_SIDE and conf.VERSION or 'current')

if conf.NAME == 'BUILTIN' then
    conf.ASSETS_MANIFEST_PATH = conf.BUILD_PATH .. '/assets/builtin.metadata'
    conf.VERSION_MANIFEST_PATH = nil
    OUTPUT_PATH = conf.BUILD_PATH
    -- conf.SHOULD_BUILD = function (path)
    --     return builtinAssets[path]
    -- end
end

if conf.COMPILE then
    compileScript(conf.ASSETS_PATH)
end

local hasUpdate = buildManifest(conf)

if hasUpdate then
    if conf.SHARDS then
        buildSharding(conf)
    end

    if conf.BUILD_PATH ~= OUTPUT_PATH then
        local BUILD_PATH = conf.BUILD_PATH
        print(string.format("publish assets: %s => %s ", BUILD_PATH, OUTPUT_PATH))
        toolset.rmdir '${OUTPUT_PATH}'
        toolset.mkdir '${OUTPUT_PATH}'
        toolset.cp('${BUILD_PATH}', '${OUTPUT_PATH}')
    end

    needBuildLink = needBuildLink or conf.DEBUG
end

if conf.BUILD_LINK and needBuildLink then
    if conf.SIDE_BY_SIDE then
        toolset.bash [[
            cd ${conf.PUBLISH_PATH}
            ln -sfn ${conf.VERSION} current
            ln -sfn ${conf.VERSION} current.ios
            ln -sfn ${conf.VERSION} current.android
            ln -sfn current/version.metadata version
            ln -sfn current.ios/version.metadata version.ios
            ln -sfn current.android/version.metadata version.android
        ]]
    else
        toolset.bash [[
            cd ${conf.PUBLISH_PATH}
            ln -sfn current/version.metadata version
            ln -sfn current/version.metadata version.ios
            ln -sfn current/version.metadata version.android
        ]]
    end
end

if conf.NAME == 'BUILTIN' then
    local data = toolset.read(conf.ASSETS_MANIFEST_PATH)
    data = string.gsub(data, '", "date":%d+', '", "date":' .. os.time())
    print('always update builtin manifest asset date')
    toolset.write_metadata(conf.ASSETS_MANIFEST_PATH, data, conf)
end

-- toolset.bash 'rm -rf build'