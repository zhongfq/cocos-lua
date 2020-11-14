local class         = require "xgame.class"
local util          = require "xgame.util"
local http          = require "xgame.http"
local Event         = require "xgame.event.Event"
local PluginEvent   = require "xgame.event.PluginEvent"
local timer         = require "xgame.timer"
local runtime       = require "xgame.runtime"
local impl          = require "kernel.plugins.wechat"
local Dispatcher    = require "xgame.Dispatcher"
local openssl       = require "openssl"
local cjson         = require "cjson.safe"
local Director      = require "cc.Director"

local trace = util.trace("[wechat]")

local TAG_DEFERRED = "__wechat_deferred_event__"

local WXSUCCESS = 0 -- 成功
-- local WXERRCODE_COMMON = -1 -- 普通错误类型
local WXERRCODE_USER_CANCEL = -2 -- 用户点击取消并返回
-- local WXERRCODE_SENT_FAIL = -3 -- 发送失败
-- local WXERRCODE_AUTH_DENY = -4 -- 授权失败
-- local WXERRCODE_UNSUPPORT = -5 -- 微信不支持

local WECHAT_AUTH_ERR_OK = 0 --Auth成功
-- local WECHAT_AUTH_ERR_NORMALERR = -1 --普通错误
-- local WECHAT_AUTH_ERR_NETWORKERR = -2 --网络错误
-- local WECHAT_AUTH_ERR_GETQRCODEFAILED = -3 --获取二维码失败
local WECHAT_AUTH_ERR_CANCEL = -4    --用户取消授权
-- local WECHAT_AUTH_ERR_TIMEOUT = -5   --超时

local WeChat = class("WeChat", Dispatcher)

function WeChat:ctor()
    self.authScope = 'snsapi_userinfo'
    self.authState = ''
    self.deferredEvent = false
    self._appid = false
    self._appsecret = false
    self._scheme = false

    impl:setDispatcher(function (...)
        self:_didResponse(...)
    end)

    runtime.on(Event.OPEN_URL, function (url)
        if string.find(url, self._scheme) == 1 then
            timer.killDelay(TAG_DEFERRED)
            if string.find(url, '://pay/?') then
                -- wx4f5a7db510e75204://pay/?returnKey=(null)&ret=-2
                -- wx4f5a7db510e75204://pay/?returnKey=&ret=0
                local ret = string.match(url, 'ret=([0-9%-]+)')
                self:_didResponse("pay", cjson.encode({
                    errcode = tonumber(ret or -1),
                }))
            else
                impl:handleOpenURL(url)
            end
        end
    end)
end

function WeChat:init(appid, appsecret, universalLink)
    self._appid = assert(appid, 'no app id')
    self._appsecret = appsecret
    self._scheme = string.format("%s://", appid)
    impl:init(appid, universalLink)
end

function WeChat.Get:installed()
    return impl:isInstalled();
end

function WeChat:pay(order)
    assert(self.installed, "no wechat client")
    assert(self._appid, "no app id")
    assert(order.noncestr, "no noncestr")
    assert(order.partnerid, "no partner id")
    assert(order.prepayid, "no prepay id")
    assert(order.timestamp, "no timestamp")
    assert(order.sign, "no sign")

    if runtime.os == "ios" then
        self.deferredEvent = self.deferredEvent or PluginEvent.PAY_CANCEL
        runtime.on(Event.RUNTIME_RESUME, self._onResume, self)
    end

    impl:pay(self._appid, order.partnerid, order.prepayid, order.noncestr,
        order.timestamp, order.sign)
end

function WeChat:auth(ticket)
    assert(self._appid, "not init wechat")
    self.userInfo = false
    self.deferredEvent = self.deferredEvent or PluginEvent.AUTH_CANCEL

    if self.installed then
        assert(self.authScope, "no auth scope")
        assert(self.authState, "no auth state")
        impl:auth(self.authScope, self.authState)
    elseif ticket then
        self:_doAuthQRCode(ticket)
    else
        assert(self._appsecret, "no app secret")
        self:_requestTicket()
    end

    if runtime.os == 'ios' then
        runtime.on(Event.RUNTIME_RESUME, self._onResume, self)
    end
end

function WeChat:open(id, path, type)
    impl:open(assert(id), path or '', type or 0)
end

function WeChat:_requestTicket()
    local URL_ACCESS_TOKEN = "https://api.weixin.qq.com/cgi-bin/token" ..
        "?grant_type=client_credential&appid=%s&secret=%s"
    local URL_SDK_TICKET = "https://api.weixin.qq.com/cgi-bin/ticket/getticket" ..
        "?access_token=%s&type=2"
    http.block(function ()
        local url = string.format(URL_ACCESS_TOKEN, self._appid, self._appsecret)
        local status, result = http({url = url, responseType = 'JSON'})
        if status ~= 200 or not result.access_token then
            self:dispatch(PluginEvent.AUTH_FAILURE)
            return
        end

        url = string.format(URL_SDK_TICKET, result.access_token)
        status, result = http({url = url, responseType = 'JSON'})
        if status ~= 200 or result.errcode ~= 0 then
            self:dispatch(PluginEvent.AUTH_FAILURE)
        else
            self:_doAuthQRCode(result['ticket'])
        end
    end)
end

function WeChat:_doAuthQRCode(ticket)
    local timestamp = tostring(os.time())
    local noncestr = openssl.sha1(timestamp)
    local str = string.format("appid=%s", self._appid)
        .. string.format("&noncestr=%s", noncestr)
        .. string.format("&sdk_ticket=%s", ticket)
        .. string.format("&timestamp=%d", timestamp)
    local sign = openssl.sha1(str)
    impl:authQRCode(self._appid, noncestr, timestamp, self.authScope, sign, "")
end

function WeChat:_onResume()
    runtime.off(Event.RUNTIME_RESUME, self._onResume)
    
    if self.deferredEvent then
        timer.delayWithTag(0.5, TAG_DEFERRED, function ()
            if self.deferredEvent then
                self:dispatch(self.deferredEvent)
                self.deferredEvent = false
            end
        end)
    end
end

function WeChat:_didResponse(action, message)
    self.deferredEvent = false
    timer.killDelay(TAG_DEFERRED)

    trace("%s response: %s", action, message)
    local data = cjson.decode(message)
    if action == "auth" then
        if data.errcode == WXSUCCESS then
            self:_requestToken(data)
        elseif data.errcode == WXERRCODE_USER_CANCEL then
            self:dispatch(PluginEvent.AUTH_CANCEL)
        else
            self:dispatch(PluginEvent.AUTH_FAILURE)
        end
    elseif action == "authQrcode" then
        if data.path then
            local textureCache = Director.instance.textureCache
            textureCache:reloadTexture(data.path)
            local texture = textureCache:getTextureForKey(data.path)
            texture:setAliasTexParameters()
            self:dispatch(PluginEvent.GOT_QRCODE, data.path)
        elseif data.errcode == WECHAT_AUTH_ERR_OK then
            self:_requestToken(data)
        elseif data.errcode == WECHAT_AUTH_ERR_CANCEL then
            self:dispatch(PluginEvent.AUTH_CANCEL)
        else
            self:dispatch(PluginEvent.AUTH_FAILURE)
        end
    elseif action == "pay" then
        if data.errcode == WXSUCCESS then
            self:dispatch(PluginEvent.PAY_SUCCESS)
        elseif data.errcode == WXERRCODE_USER_CANCEL then
            self:dispatch(PluginEvent.PAY_CANCEL)
        else
            self:dispatch(PluginEvent.PAY_FAILURE)
        end
    end
end

function WeChat:_requestToken(data)
    if not self._appsecret then
        self:dispatch(PluginEvent.AUTH_SUCCESS, data)
        return
    end

    local URL_ACCESS_TOKEN = "https://api.weixin.qq.com/sns/oauth2/access_token" ..
        "?appid=%s&secret=%s&code=%s&grant_type=authorization_code"
    local URL_USERINFO = "https://api.weixin.qq.com/sns/userinfo" ..
        "?openid=%s&access_token=%s"

    http.block(function ()
        local url = string.format(URL_ACCESS_TOKEN, self._appid, self._appsecret, data.code)
        local status, result = http({url = url, responseType = 'JSON'})
        if status ~= 200 or not result.access_token then
            self:dispatch(PluginEvent.AUTH_FAILURE)
            return
        end

        url = string.format(URL_USERINFO, result.openid, result.access_token)
        status, result = http({url = url, responseType = 'JSON'})
        -- {"errcode":40001,"errmsg":"invalid credential, access_token is invalid or
        -- not latest, hints:[ req_id: BfnAOYFFE-K3Rv7 ]"}
        if status ~= 200 or not result or not result.unionid then
            self:dispatch(PluginEvent.AUTH_FAILURE)
        else
            self.userInfo = {
                avatar = result.headimgurl,
                uid = 'wxuid:' .. result.unionid,
                nickname = result.nickname,
                sex = result.sex,
            }
            self:dispatch(PluginEvent.AUTH_SUCCESS, self.userInfo)
        end
    end)
end

if runtime.os == "ios" then
    function impl:pay(appid, partnerid, prepayid, noncestr, timestamp, sign)
        local URL_PAY = "weixin://app/%s/pay/?nonceStr=%s&package=Sign%%3DWXPay" ..
            "&partnerId=%s&prepayId=%s&timeStamp=%d&sign=%s&signType=SHA1"
        local url = string.format(URL_PAY, appid, noncestr, partnerid, prepayid, timestamp, sign)
        runtime.openURL(url)
    end
elseif runtime.os == "android" then
    local luaj = require "xgame.luaj"
    local inst = luaj.new("kernel/plugins/wechat/WeChat")
    impl = {}

    function impl:setDispatcher(callback)
        impl.callback = callback
    end

    function impl:init(appid)
        inst.init(appid)
    end

    function impl:isInstalled()
        return inst.isInstalled()
    end

    function impl:pay(appid, partnerid, prepayid, noncestr, timestamp, sign)
        timestamp = string.format("%d", timestamp)
        inst.pay(partnerid, prepayid, noncestr, timestamp, 'Sign=WXPay', sign, function (...)
            impl.callback("pay", ...)
        end)
    end

    function impl:auth(scope, state)
        inst.auth(scope, state, function (...)
            impl.callback("auth", ...)
        end)
    end

    function impl:authQRCode(appid, noncestr, timestamp, scope, sign)
        inst.authQRCode(appid, scope, noncestr, timestamp, sign, function (...)
            impl.callback("authQrcode", ...)
        end)
    end

    function impl:share(message)
        inst.share(cjson.encode(message), function (...)
            impl.callback("share", ...)
        end)
    end

    function impl:open(id, path, type)
        inst.open(id, path, type, function (...)
            impl.callback("open", ...)
        end)
    end
end

return WeChat.new()