local util      = require "cclua.util"
local Event     = require "cclua.Event"
local runtime   = require "cclua.runtime"

local WXSUCCESS = 0 -- 成功
-- local WXERRCODE_COMMON = -1 -- 普通错误类型
local WXERRCODE_USER_CANCEL = -2 -- 用户点击取消并返回
local WXERRCODE_SENT_FAIL = -3 -- 发送失败
-- local WXERRCODE_AUTH_DENY = -4 -- 授权失败
-- local WXERRCODE_UNSUPPORT = -5 -- 微信不支持

local WECHAT_AUTH_ERR_OK = 0 --Auth成功
-- local WECHAT_AUTH_ERR_NORMALERR = -1 --普通错误
-- local WECHAT_AUTH_ERR_NETWORKERR = -2 --网络错误
-- local WECHAT_AUTH_ERR_GETQRCODEFAILED = -3 --获取二维码失败
local WECHAT_AUTH_ERR_CANCEL = -4    --用户取消授权
-- local WECHAT_AUTH_ERR_TIMEOUT = -5   --超时

local wechat = runtime.load("cclua.plugin.wechat")
local wechat_auth = assert(wechat.auth, "auth")
local wechat_init = assert(wechat.init, "init")
local wechat_authQRCode = assert(wechat.authQRCode, "authQRCode")
local wechat_stopAuth = assert(wechat.stopAuth, "stopAuth")
local wechat_share = assert(wechat.share, "share")
local wechat_pay = wechat.pay

local authCallback = nil
local authQRCodeCallback = nil
local payCallback = nil
local shareCallback = nil

wechat.authScope = "snsapi_userinfo"
wechat.authState = ""
wechat.appid = false

wechat.setDispatcher(function (event, data)
    print("wechat", event, util.dump(data))
    if event == "auth" then
        if not authCallback then
            print("wechat auth callback not set")
            return
        end
        if data.errcode == WXSUCCESS then
            authCallback("successful", data)
        elseif data.errcode == WXERRCODE_USER_CANCEL then
            authCallback("canceled", data)
        else
            authCallback("failed", data)
        end
        authCallback = nil
    elseif event == "authQRCode" then
        if not authQRCodeCallback then
            print("wechat auth qrcode callback not set")
            return
        end
        if data.state == "AuthGotQrcode" then
            runtime.textureCache:reloadTexture(data.path)
            local texture = runtime.textureCache:getTextureForKey(data.path)
            texture:setAliasTexParameters()
            authQRCodeCallback("gotqrcode", data)
        elseif data.state == "QrcodeScanned" then
            authQRCodeCallback("scanned", data)
        elseif data.state == "AuthFinish" then
            if data.errcode == WECHAT_AUTH_ERR_OK then
                authQRCodeCallback("successful", data)
            elseif data.errcode == WECHAT_AUTH_ERR_CANCEL then
                authQRCodeCallback("canceled", data)
            else
                authQRCodeCallback("failed", data)
            end
            authQRCodeCallback = nil
        else
            error(event)
        end
    elseif event == "pay" then
        if not payCallback then
            print("wechat pay callback not set")
            return
        end
        if data.errcode == WXSUCCESS then
            payCallback("successful", data)
        elseif data.errcode == WXERRCODE_USER_CANCEL then
            payCallback("canceled", data)
        else
            payCallback("failed", data)
        end
        payCallback = nil
    elseif event == "share" then
        if not shareCallback then
            print("wechat share callback not set")
            return
        end
        if data.errcode == WXSUCCESS then
            shareCallback("successful", data)
        elseif data.errcode == WXERRCODE_USER_CANCEL then
            shareCallback("canceled", data)
        else
            shareCallback("failed", data)
        end
        shareCallback = nil
    end
end)
wechat.setDispatcher = false

function wechat.init(appid, universalLink)
    wechat.appid = assert(appid, "no app id")
    wechat.scheme = string.format("%s://", appid)
    wechat_init(appid, universalLink)
end

function wechat.auth(callback)
    authCallback = assert(callback)
    if wechat.installed then
        wechat_auth(wechat.authScope, wechat.authState)
    else
        wechat.dispatch("auth", {errcode = WXERRCODE_SENT_FAIL})
    end
end

function wechat.authQRCode(request, callback)
    authQRCodeCallback = assert(callback)
    wechat_authQRCode(wechat.appid, request.noncestr, request.timestamp, wechat.authScope, request.sign)
end

function wechat.stopAuth()
    authQRCodeCallback = nil
    authCallback = nil
    wechat_stopAuth()
end

function wechat.pay(order, callback)
    assert(wechat.installed, "no wechat client")
    payCallback = assert(callback)
    wechat_pay(
        assert(order.partnerid, "no partner id"),
        assert(order.prepayid, "no prepay id"),
        assert(order.noncestr, "no noncestr"),
        assert(order.timestamp, "no timestamp"),
        "Sign=WXPay",
        assert(order.sign, "no sign")
    )
end

function wechat.share(type, value, callback)
    shareCallback = assert(callback)
    wechat_share(type, value)
end

if runtime.os == 'ios' then
    wechat_pay = function (partnerid, prepayid, noncestr, timestamp, _, sign)
        local URL_PAY = "weixin://app/%s/pay/?nonceStr=%s&package=Sign%%3DWXPay" ..
            "&partnerId=%s&prepayId=%s&timeStamp=%d&sign=%s&signType=SHA1"
        local url = string.format(URL_PAY, wechat.appid, noncestr, partnerid, prepayid, timestamp, sign)
        runtime.openURL(url)
    end
    runtime.on(Event.OPEN_URL, function (url)
        local scheme = string.format("%s://", wechat.appid or '<unknown>')
        if string.find(url, scheme) == 1 then
            if string.find(url, '://pay/?') then
                -- wx4f5a7db510e75204://pay/?returnKey=(null)&ret=-2
                -- wx4f5a7db510e75204://pay/?returnKey=&ret=0
                local ret = string.match(url, 'ret=([0-9%-]+)')
                wechat.dispatch("pay", {errcode = tonumber(ret or -1)})
            end
        end
    end)
end

return wechat