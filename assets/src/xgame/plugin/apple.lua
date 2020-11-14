local class         = require "xgame.class"
local util          = require "xgame.util"
local PluginEvent   = require "xgame.event.PluginEvent"
local runtime       = require "xgame.runtime"
local Dispatcher    = require "xgame.Dispatcher"
local cjson         = require "cjson.safe"

local impl
local trace = util.trace("[apple]")

local ASAuthorizationErrorUnknown = 1000
local ASAuthorizationErrorCanceled = 1001
local ASAuthorizationErrorInvalidResponse = 1002
local ASAuthorizationErrorNotHandled = 1003
local ASAuthorizationErrorFailed = 1004

local Apple = class("Apple", Dispatcher)

function Apple:ctor()
    impl:setDispatcher(function (...)
        self:_didResponse(...)
    end)
end

function Apple:_didResponse(action, message)
    local data = cjson.decode(message)
    if action == 'auth' then
        if not data.errcode then
            self.userInfo = {
                uid = 'apuid:' .. data.user,
            }
            data.uid = 'apuid:' .. data.user
            self:dispatch(PluginEvent.AUTH_SUCCESS, data)
        elseif data.errcode == ASAuthorizationErrorCanceled then
            self:dispatch(PluginEvent.AUTH_CANCEL)
        else
            self:dispatch(PluginEvent.AUTH_FAILURE)
        end
    end
end

function Apple:canMakeAuth()
    return impl:canMakeAuth()
end

function Apple:auth()
    self.userInfo = false
    impl:auth()
end

if runtime.support('apple.ios') then
    impl = require "kernel.plugins.apple"
else
    impl = setmetatable({}, {__index = function (_, func)
        return function ()
            trace("function 'kernel.plugins.apple.%s' not supported", func)
        end
    end})
end

return Apple.new()