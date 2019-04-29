local M = {}

local XMLHttpRequest    = require "cc.XMLHttpRequest"
local ResponseType      = require "cc.XMLHttpRequest.ResponseType"

local function createRequest(data)
    local xhr = cc.XMLHttpRequest.new()
    xhr.timeout = data.timeout or 0

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
        data.callback(xhr.status, xhr)
    end)

    return xhr
end

function M.request(req)
    assert(req.url)
    assert(req.callback)

    local xhr = createRequest(req)
    xhr:open(req.method or 'GET', req.url)
    xhr:send(req.data)
end

function M.call(args)
    local co, ismain = coroutine.running()
    assert(not ismain, 'http call not support in main thread')
    assert(not args.callback)
    args.callback = function (status, req)
        coroutine.resume(co, status, req.response)
    end
    M.request(args)
    return coroutine.yield()
end

local function doCall(_, args)
    return M.call(args)
end

function M.block(func)
    coroutine.resume(coroutine.create(func))
end

function M.decodeURI(s)
    s = string.gsub(s, '%%(%x%x)', function(h) 
        return string.char(tonumber(h, 16)) 
    end)
    s = string.gsub(s, '+', ' ')
    return s
end

function M.encodeURI(s)
    s = string.gsub(s, ' ', '+')
    s = string.gsub(s, "([^A-Za-z0-9!#$&'()*+,-./:;=?@_~])", function(c) 
        return string.format("%%%02X", string.byte(c)) 
    end)
    return s
end

function M.encodeURIComponent(s)
    s = string.gsub(s, "([^A-Za-z0-9!'()*-._~])", function(c) 
        return string.format("%%%02X", string.byte(c)) 
    end)
    return s
end

function M.decodeURIComponent(s)
    s = string.gsub(s, '%%(%x%x)', function(h) 
        return string.char(tonumber(h, 16)) 
    end)
    return s
end

return setmetatable(M, {__call = doCall})