local runtime = require "cclua.runtime"

local talkingdata = runtime.load("cclua.plugin.talkingdata")

local talkingdata_onRegister = assert(talkingdata.onRegister, "onRegister")
local talkingdata_onLogin = assert(talkingdata.onLogin, "onLogin")
local talkingdata_onProfileUpdate = assert(talkingdata.onProfileUpdate, "onProfileUpdate")

local typeMap = {
    ANONYMOUS = 0,
    REGISTERED = 1,
    SINA_WEIBO = 2,
    QQ = 3,
    QQ_WEIBO = 4,
    ND91 = 5,
    WEIXIN = 6,
    TYPE1 = 11,
    TYPE2 = 12,
    TYPE3 = 13,
    TYPE4 = 14,
    TYPE5 = 15,
    TYPE6 = 16,
    TYPE7 = 17,
    TYPE8 = 18,
    TYPE9 = 19,
    TYPE10 = 20,
}
local genderMap = {
    UNKNOWN = 0,
    MALE = 1,
    FEMALE = 2,
}

local function fixEnum(data)
    if runtime.os == 'ios' then
        if data.type then
            data.type = assert(typeMap[data.type])
        end
        if data.gender then
            data.gender = assert(genderMap[data.gender])
        end
    end
    return data
end

function talkingdata.onRegister(uid, data, invitationCode)
    talkingdata_onRegister(uid, fixEnum(data), invitationCode)
end

function talkingdata.onLogin(uid, data)
    talkingdata_onLogin(uid, fixEnum(data))
end

function talkingdata.onProfileUpdate(data)
    talkingdata_onProfileUpdate(fixEnum(data))
end

return talkingdata