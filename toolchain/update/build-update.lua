local shell = require "core.shell"
local setting = require "setting"
local buildManifest = require "build-manifest"

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

-- try get version
if not ARG_VERSION then
    ARG_VERSION = shell.readJson(ARG_PUBLISH_PATH .. '/current/manifest', {version = '0.0.0'}).version
end
ARG_VERSION = shell.nextversion(ARG_VERSION)

local conf = {
    DEBUG = ARG_DEBUG,
    NAME = ARG_NAME,
    VERSION = ARG_VERSION,
    PUBLISH_PATH = ARG_PUBLISH_PATH,
    BUILD_PATH = setting[ARG_NAME].BUILD_PATH,
    COMPILE = setting[ARG_NAME].COMPILE,
    URL = setting[ARG_NAME].URL .. '/' .. (ARG_NAME == 'LOCAL' and 'current' or  ARG_VERSION),
}

if not conf.BUILD_PATH or conf.COMPILE then
    shell.bash 'rm -rf build'
    shell.bash 'mkdir -p build/assets'
    shell.bash 'cp -rf ../../assets/* build/assets'
    conf.BUILD_PATH = 'build'
end

buildManifest(conf)

-- shell.bash 'rm -rf build'