local shell = require "core.shell"
local setting = require "setting"
local buildManifest = require "buildManifest"

local conf = {
    DEBUG = false,
    NAME = 'LOCAL',
    VERSION = '1.0.0',
    PUBLIC_PATH = false,
}
setmetatable(conf, {__index = setting[conf.NAME]})

-- parse cmd line args
local args = {...}
while #args > 0 do
    local c = table.remove(args, 1)
    if c == '--debug' then
        conf.DEBUG = true
    elseif c == '--setting' then
        conf.NAME = assert(table.remove(args, 1), 'no setting name')
        assert(setting[conf.NAME], 'setting not found: ' .. conf.NAME)
        setmetatable(conf, {__index = setting[conf.NAME]})
    elseif c == '--public-path' then
        conf.PUBLIC_PATH = assert(table.remove(args, 1), 'no public path')
    end
end

if conf.COMPILE then
    local ASSETS_PATH = conf.ASSETS_PATH
    local NEW_ASSETS_PATH = 'build/assets'
    shell.unuse(ASSETS_PATH, NEW_ASSETS_PATH)
    shell.bash 'mkdir -p ${NEW_ASSETS_PATH}'
    shell.bash 'cp -rf ${ASSETS_PATH}/* ${NEW_ASSETS_PATH}'
    conf.ASSETS_PATH = NEW_ASSETS_PATH
end

conf.PROJECT_PATH = "xxxx"
conf.WORK_PATH = "xxxxxxxxxfasdf"
buildManifest(conf)

-- shell.bash 'rm -rf build'