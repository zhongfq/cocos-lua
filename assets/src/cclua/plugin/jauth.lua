local util      = require "cclua.util"
local runtime   = require "cclua.runtime"

local jauth = runtime.load("cclua.plugin.jauth")
local jauth_getToken = assert(jauth.getToken, "getToken")
local jauth_preLogin = assert(jauth.preLogin, "preLogin")
local jauth_loginAuth = assert(jauth.loginAuth, "loginAuth")
local jauth_getSmsCode = assert(jauth.getSmsCode, "getSmsCode")

local getTokenCallback = nil
local preLoginCallback = nil
local loginAuthCallback = nil
local getSmsCodeCallback = nil

jauth.setDispatcher(function (event, data)
    print("jauth", event, util.dump(data))
    if event == "getToken" then
        if not getTokenCallback then
            print("jauth get token callback not set")
            return
        end
        if data.success then
            getTokenCallback("successful", data)
        else
            getTokenCallback("failed", data)
        end
        getTokenCallback = nil
    elseif event == "preLogin" then
        if not preLoginCallback then
            print("jauth pre login callback not set")
            return
        end
        if data.success then
            preLoginCallback("successful", data)
        else
            preLoginCallback("failed", data)
        end
        preLoginCallback = nil
    elseif event == "loginAuth" then
        if not loginAuthCallback then
            print("jauth login auth callback not set")
            return
        end
        if data.success then
            loginAuthCallback("successful", data)
        else
            loginAuthCallback("failed", data)
        end
        loginAuthCallback = nil
    elseif event == "getSmsCode" then
        if not getSmsCodeCallback then
            print("jauth get sms code callback not set")
            return
        end
        if data.success then
            getSmsCodeCallback("successful", data)
        else
            getSmsCodeCallback("failed", data)
        end
        getSmsCodeCallback = nil
    end
end)
jauth.setDispatcher = false

function jauth.getToken(timeout, callback)
    getTokenCallback = assert(callback)
    jauth_getToken(timeout)
end

function jauth.preLogin(timeout, callback)
    preLoginCallback = assert(callback)
    jauth_preLogin(timeout)
end

function jauth.loginAuth(timeout, callback)
    loginAuthCallback = assert(callback)
    jauth_loginAuth(timeout)
end

function jauth.getSmsCode(phonenum, signid, tempid, callback)
    getSmsCodeCallback = assert(callback)
    jauth_getSmsCode(phonenum, signid, tempid)
end

return jauth