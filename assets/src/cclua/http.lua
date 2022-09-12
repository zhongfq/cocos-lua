local XMLHttpRequest    = require "cclua.XMLHttpRequest"
local ResponseType      = require "cclua.XMLHttpRequest.ResponseType"

local http = {
    _requests = {}
}

local function createRequest(data)
    local xhr = XMLHttpRequest.new()
    xhr.timeout = data.timeout or 10

    http._requests[xhr] = true

    if data.headers then
        for field, value in pairs(data.headers) do
            xhr:setRequestHeader(field, value)
        end
    end

    if data.responseType == 'JSON' then
        xhr.responseType = ResponseType.JSON
    elseif data.responseType == 'ARRAY_BUFFER' then
        xhr.responseType = ResponseType.ARRAY_BUFFER
    else
        xhr.responseType = ResponseType.STRING
    end

    xhr:setResponseCallback(function ()
        http._requests[xhr] = nil
        data.callback(xhr.status, xhr)
    end)

    return xhr
end

function http.request(req)
    assert(req.url)
    assert(req.callback)

    local xhr = createRequest(req)
    xhr:open(req.method or 'GET', req.url)
    if req.data then
        xhr:send(req.data)
    else
        xhr:send()
    end
end

function http.call(args)
    local co, ismain = coroutine.running()
    assert(not ismain, 'http call not support in main thread')
    assert(not args.callback)
    args.callback = function (status, req)
        coroutine.resume(co, status, req.response)
    end
    http.request(args)
    return coroutine.yield()
end

local function doCall(_, args)
    return http.call(args)
end

function http.block(func)
    coroutine.resume(coroutine.create(func))
end

function http.decodeURI(s)
    s = string.gsub(s, '%%(%x%x)', function(h)
        return string.char(tonumber(h, 16))
    end)
    s = string.gsub(s, '+', ' ')
    return s
end

function http.encodeURI(s)
    s = string.gsub(s, ' ', '+')
    s = string.gsub(s, "([^A-Za-z0-9!#$&'()*+,-./:;=?@_~])", function(c)
        return string.format("%%%02X", string.byte(c))
    end)
    return s
end

function http.encodeURIComponent(s)
    s = string.gsub(s, "([^A-Za-z0-9!'()*-._~])", function(c)
        return string.format("%%%02X", string.byte(c))
    end)
    return s
end

function http.decodeURIComponent(s)
    s = string.gsub(s, '%%(%x%x)', function(h)
        return string.char(tonumber(h, 16))
    end)
    return s
end

return setmetatable(http, {__call = doCall})