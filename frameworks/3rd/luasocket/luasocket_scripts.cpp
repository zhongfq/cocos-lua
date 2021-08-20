
/* luasocket_scripts.cpp */

#include "luasocket_scripts.h"

/* ltn12 */
static const char *lua_m_ltn12 = R"~~~(
-----------------------------------------------------------------------------
-- LTN12 - Filters, sources, sinks and pumps.
-- LuaSocket toolkit.
-- Author: Diego Nehab
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
-- Declare module
-----------------------------------------------------------------------------
local string = require("string")
local table = require("table")
local unpack = unpack or table.unpack
local base = _G
local _M = {}
if module then -- heuristic for exporting a global package table
    ltn12 = _M
end
local filter,source,sink,pump = {},{},{},{}

_M.filter = filter
_M.source = source
_M.sink = sink
_M.pump = pump

local unpack = unpack or table.unpack
local select = base.select

-- 2048 seems to be better in windows...
_M.BLOCKSIZE = 2048
_M._VERSION = "LTN12 1.0.3"

-----------------------------------------------------------------------------
-- Filter stuff
-----------------------------------------------------------------------------
-- returns a high level filter that cycles a low-level filter
function filter.cycle(low, ctx, extra)
    base.assert(low)
    return function(chunk)
        local ret
        ret, ctx = low(ctx, chunk, extra)
        return ret
    end
end

-- chains a bunch of filters together
-- (thanks to Wim Couwenberg)
function filter.chain(...)
    local arg = {...}
    local n = base.select('#',...)
    local top, index = 1, 1
    local retry = ""
    return function(chunk)
        retry = chunk and retry
        while true do
            if index == top then
                chunk = arg[index](chunk)
                if chunk == "" or top == n then return chunk
                elseif chunk then index = index + 1
                else
                    top = top+1
                    index = top
                end
            else
                chunk = arg[index](chunk or "")
                if chunk == "" then
                    index = index - 1
                    chunk = retry
                elseif chunk then
                    if index == n then return chunk
                    else index = index + 1 end
                else base.error("filter returned inappropriate nil") end
            end
        end
    end
end

-----------------------------------------------------------------------------
-- Source stuff
-----------------------------------------------------------------------------
-- create an empty source
local function empty()
    return nil
end

function source.empty()
    return empty
end

-- returns a source that just outputs an error
function source.error(err)
    return function()
        return nil, err
    end
end

-- creates a file source
function source.file(handle, io_err)
    if handle then
        return function()
            local chunk = handle:read(_M.BLOCKSIZE)
            if not chunk then handle:close() end
            return chunk
        end
    else return source.error(io_err or "unable to open file") end
end

-- turns a fancy source into a simple source
function source.simplify(src)
    base.assert(src)
    return function()
        local chunk, err_or_new = src()
        src = err_or_new or src
        if not chunk then return nil, err_or_new
        else return chunk end
    end
end

-- creates string source
function source.string(s)
    if s then
        local i = 1
        return function()
            local chunk = string.sub(s, i, i+_M.BLOCKSIZE-1)
            i = i + _M.BLOCKSIZE
            if chunk ~= "" then return chunk
            else return nil end
        end
    else return source.empty() end
end

-- creates table source
function source.table(t)
    base.assert('table' == type(t))
    local i = 0
    return function()
        i = i + 1
        return t[i]
    end
end

-- creates rewindable source
function source.rewind(src)
    base.assert(src)
    local t = {}
    return function(chunk)
        if not chunk then
            chunk = table.remove(t)
            if not chunk then return src()
            else return chunk end
        else
            table.insert(t, chunk)
        end
    end
end

-- chains a source with one or several filter(s)
function source.chain(src, f, ...)
    if ... then f=filter.chain(f, ...) end
    base.assert(src and f)
    local last_in, last_out = "", ""
    local state = "feeding"
    local err
    return function()
        if not last_out then
            base.error('source is empty!', 2)
        end
        while true do
            if state == "feeding" then
                last_in, err = src()
                if err then return nil, err end
                last_out = f(last_in)
                if not last_out then
                    if last_in then
                        base.error('filter returned inappropriate nil')
                    else
                        return nil
                    end
                elseif last_out ~= "" then
                    state = "eating"
                    if last_in then last_in = "" end
                    return last_out
                end
            else
                last_out = f(last_in)
                if last_out == "" then
                    if last_in == "" then
                        state = "feeding"
                    else
                        base.error('filter returned ""')
                    end
                elseif not last_out then
                    if last_in then
                        base.error('filter returned inappropriate nil')
                    else
                        return nil
                    end
                else
                    return last_out
                end
            end
        end
    end
end

-- creates a source that produces contents of several sources, one after the
-- other, as if they were concatenated
-- (thanks to Wim Couwenberg)
function source.cat(...)
    local arg = {...}
    local src = table.remove(arg, 1)
    return function()
        while src do
            local chunk, err = src()
            if chunk then return chunk end
            if err then return nil, err end
            src = table.remove(arg, 1)
        end
    end
end

-----------------------------------------------------------------------------
-- Sink stuff
-----------------------------------------------------------------------------
-- creates a sink that stores into a table
function sink.table(t)
    t = t or {}
    local f = function(chunk, err)
        if chunk then table.insert(t, chunk) end
        return 1
    end
    return f, t
end

-- turns a fancy sink into a simple sink
function sink.simplify(snk)
    base.assert(snk)
    return function(chunk, err)
        local ret, err_or_new = snk(chunk, err)
        if not ret then return nil, err_or_new end
        snk = err_or_new or snk
        return 1
    end
end

-- creates a file sink
function sink.file(handle, io_err)
    if handle then
        return function(chunk, err)
            if not chunk then
                handle:close()
                return 1
            else return handle:write(chunk) end
        end
    else return sink.error(io_err or "unable to open file") end
end

-- creates a sink that discards data
local function null()
    return 1
end

function sink.null()
    return null
end

-- creates a sink that just returns an error
function sink.error(err)
    return function()
        return nil, err
    end
end

-- chains a sink with one or several filter(s)
function sink.chain(f, snk, ...)
    if ... then
        local args = { f, snk, ... }
        snk = table.remove(args, #args)
        f = filter.chain(unpack(args))
    end
    base.assert(f and snk)
    return function(chunk, err)
        if chunk ~= "" then
            local filtered = f(chunk)
            local done = chunk and ""
            while true do
                local ret, snkerr = snk(filtered, err)
                if not ret then return nil, snkerr end
                if filtered == done then return 1 end
                filtered = f(done)
            end
        else return 1 end
    end
end

-----------------------------------------------------------------------------
-- Pump stuff
-----------------------------------------------------------------------------
-- pumps one chunk from the source to the sink
function pump.step(src, snk)
    local chunk, src_err = src()
    local ret, snk_err = snk(chunk, src_err)
    if chunk and ret then return 1
    else return nil, src_err or snk_err end
end

-- pumps all data from a source to a sink, using a step function
function pump.all(src, snk, step)
    base.assert(src and snk)
    step = step or pump.step
    while true do
        local ret, err = step(src, snk)
        if not ret then
            if err then return nil, err
            else return 1 end
        end
    end
end

return _M
)~~~";

/* mime */
static const char *lua_m_mime = R"~~~(
-----------------------------------------------------------------------------
-- MIME support for the Lua language.
-- Author: Diego Nehab
-- Conforming to RFCs 2045-2049
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
-- Declare module and import dependencies
-----------------------------------------------------------------------------
local base = _G
local ltn12 = require("ltn12")
local mime = require("mime.core")
local string = require("string")
local _M = mime

-- encode, decode and wrap algorithm tables
local encodet, decodet, wrapt = {},{},{}

_M.encodet = encodet
_M.decodet = decodet
_M.wrapt   = wrapt  

-- creates a function that chooses a filter by name from a given table
local function choose(table)
    return function(name, opt1, opt2)
        if base.type(name) ~= "string" then
            name, opt1, opt2 = "default", name, opt1
        end
        local f = table[name or "nil"]
        if not f then 
            base.error("unknown key (" .. base.tostring(name) .. ")", 3)
        else return f(opt1, opt2) end
    end
end

-- define the encoding filters
encodet['base64'] = function()
    return ltn12.filter.cycle(_M.b64, "")
end

encodet['quoted-printable'] = function(mode)
    return ltn12.filter.cycle(_M.qp, "",
        (mode == "binary") and "=0D=0A" or "\r\n")
end

-- define the decoding filters
decodet['base64'] = function()
    return ltn12.filter.cycle(_M.unb64, "")
end

decodet['quoted-printable'] = function()
    return ltn12.filter.cycle(_M.unqp, "")
end

local function format(chunk)
    if chunk then
        if chunk == "" then return "''"
        else return string.len(chunk) end
    else return "nil" end
end

-- define the line-wrap filters
wrapt['text'] = function(length)
    length = length or 76
    return ltn12.filter.cycle(_M.wrp, length, length)
end
wrapt['base64'] = wrapt['text']
wrapt['default'] = wrapt['text']

wrapt['quoted-printable'] = function()
    return ltn12.filter.cycle(_M.qpwrp, 76, 76)
end

-- function that choose the encoding, decoding or wrap algorithm
_M.encode = choose(encodet)
_M.decode = choose(decodet)
_M.wrap = choose(wrapt)

-- define the end-of-line normalization filter
function _M.normalize(marker)
    return ltn12.filter.cycle(_M.eol, 0, marker)
end

-- high level stuffing filter
function _M.stuff()
    return ltn12.filter.cycle(_M.dot, 2)
end

return _M
)~~~";

/* socket.ftp */
static const char *lua_m_socket_ftp = R"~~~(
-----------------------------------------------------------------------------
-- FTP support for the Lua language
-- LuaSocket toolkit.
-- Author: Diego Nehab
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
-- Declare module and import dependencies
-----------------------------------------------------------------------------
local base = _G
local table = require("table")
local string = require("string")
local math = require("math")
local socket = require("socket")
local url = require("socket.url")
local tp = require("socket.tp")
local ltn12 = require("ltn12")
socket.ftp = {}
local _M = socket.ftp
-----------------------------------------------------------------------------
-- Program constants
-----------------------------------------------------------------------------
-- timeout in seconds before the program gives up on a connection
_M.TIMEOUT = 60
-- default port for ftp service
local PORT = 21
-- this is the default anonymous password. used when no password is
-- provided in url. should be changed to your e-mail.
_M.USER = "ftp"
_M.PASSWORD = "anonymous@anonymous.org"

-----------------------------------------------------------------------------
-- Low level FTP API
-----------------------------------------------------------------------------
local metat = { __index = {} }

function _M.open(server, port, create)
    local tp = socket.try(tp.connect(server, port or PORT, _M.TIMEOUT, create))
    local f = base.setmetatable({ tp = tp }, metat)
    -- make sure everything gets closed in an exception
    f.try = socket.newtry(function() f:close() end)
    return f
end

function metat.__index:portconnect()
    self.try(self.server:settimeout(_M.TIMEOUT))
    self.data = self.try(self.server:accept())
    self.try(self.data:settimeout(_M.TIMEOUT))
end

function metat.__index:pasvconnect()
    self.data = self.try(socket.tcp())
    self.try(self.data:settimeout(_M.TIMEOUT))
    self.try(self.data:connect(self.pasvt.address, self.pasvt.port))
end

function metat.__index:login(user, password)
    self.try(self.tp:command("user", user or _M.USER))
    local code, reply = self.try(self.tp:check{"2..", 331})
    if code == 331 then
        self.try(self.tp:command("pass", password or _M.PASSWORD))
        self.try(self.tp:check("2.."))
    end
    return 1
end

function metat.__index:pasv()
    self.try(self.tp:command("pasv"))
    local code, reply = self.try(self.tp:check("2.."))
    local pattern = "(%d+)%D(%d+)%D(%d+)%D(%d+)%D(%d+)%D(%d+)"
    local a, b, c, d, p1, p2 = socket.skip(2, string.find(reply, pattern))
    self.try(a and b and c and d and p1 and p2, reply)
    self.pasvt = {
        address = string.format("%d.%d.%d.%d", a, b, c, d),
        port = p1*256 + p2
    }
    if self.server then
        self.server:close()
        self.server = nil
    end
    return self.pasvt.address, self.pasvt.port
end

function metat.__index:epsv()
    self.try(self.tp:command("epsv"))
    local code, reply = self.try(self.tp:check("229"))
    local pattern = "%((.)(.-)%1(.-)%1(.-)%1%)"
    local d, prt, address, port = string.match(reply, pattern)
    self.try(port, "invalid epsv response")
    self.pasvt = {
        address = self.tp:getpeername(),
        port = port
    }
    if self.server then
        self.server:close()
        self.server = nil
    end
    return self.pasvt.address, self.pasvt.port
end


function metat.__index:port(address, port)
    self.pasvt = nil
    if not address then
        address, port = self.try(self.tp:getsockname())
        self.server = self.try(socket.bind(address, 0))
        address, port = self.try(self.server:getsockname())
        self.try(self.server:settimeout(_M.TIMEOUT))
    end
    local pl = math.mod(port, 256)
    local ph = (port - pl)/256
    local arg = string.gsub(string.format("%s,%d,%d", address, ph, pl), "%.", ",")
    self.try(self.tp:command("port", arg))
    self.try(self.tp:check("2.."))
    return 1
end

function metat.__index:eprt(family, address, port)
    self.pasvt = nil
    if not address then
        address, port = self.try(self.tp:getsockname())
        self.server = self.try(socket.bind(address, 0))
        address, port = self.try(self.server:getsockname())
        self.try(self.server:settimeout(_M.TIMEOUT))
    end
    local arg = string.format("|%s|%s|%d|", family, address, port)
    self.try(self.tp:command("eprt", arg))
    self.try(self.tp:check("2.."))
    return 1
end


function metat.__index:send(sendt)
    self.try(self.pasvt or self.server, "need port or pasv first")
    -- if there is a pasvt table, we already sent a PASV command
    -- we just get the data connection into self.data
    if self.pasvt then self:pasvconnect() end
    -- get the transfer argument and command
    local argument = sendt.argument or
        url.unescape(string.gsub(sendt.path or "", "^[/\\]", ""))
    if argument == "" then argument = nil end
    local command = sendt.command or "stor"
    -- send the transfer command and check the reply
    self.try(self.tp:command(command, argument))
    local code, reply = self.try(self.tp:check{"2..", "1.."})
    -- if there is not a pasvt table, then there is a server
    -- and we already sent a PORT command
    if not self.pasvt then self:portconnect() end
    -- get the sink, source and step for the transfer
    local step = sendt.step or ltn12.pump.step
    local readt = { self.tp }
    local checkstep = function(src, snk)
        -- check status in control connection while downloading
        local readyt = socket.select(readt, nil, 0)
        if readyt[tp] then code = self.try(self.tp:check("2..")) end
        return step(src, snk)
    end
    local sink = socket.sink("close-when-done", self.data)
    -- transfer all data and check error
    self.try(ltn12.pump.all(sendt.source, sink, checkstep))
    if string.find(code, "1..") then self.try(self.tp:check("2..")) end
    -- done with data connection
    self.data:close()
    -- find out how many bytes were sent
    local sent = socket.skip(1, self.data:getstats())
    self.data = nil
    return sent
end

function metat.__index:receive(recvt)
    self.try(self.pasvt or self.server, "need port or pasv first")
    if self.pasvt then self:pasvconnect() end
    local argument = recvt.argument or
        url.unescape(string.gsub(recvt.path or "", "^[/\\]", ""))
    if argument == "" then argument = nil end
    local command = recvt.command or "retr"
    self.try(self.tp:command(command, argument))
    local code,reply = self.try(self.tp:check{"1..", "2.."})
    if (code >= 200) and (code <= 299) then
        recvt.sink(reply)
        return 1
    end
    if not self.pasvt then self:portconnect() end
    local source = socket.source("until-closed", self.data)
    local step = recvt.step or ltn12.pump.step
    self.try(ltn12.pump.all(source, recvt.sink, step))
    if string.find(code, "1..") then self.try(self.tp:check("2..")) end
    self.data:close()
    self.data = nil
    return 1
end

function metat.__index:cwd(dir)
    self.try(self.tp:command("cwd", dir))
    self.try(self.tp:check(250))
    return 1
end

function metat.__index:type(type)
    self.try(self.tp:command("type", type))
    self.try(self.tp:check(200))
    return 1
end

function metat.__index:greet()
    local code = self.try(self.tp:check{"1..", "2.."})
    if string.find(code, "1..") then self.try(self.tp:check("2..")) end
    return 1
end

function metat.__index:quit()
    self.try(self.tp:command("quit"))
    self.try(self.tp:check("2.."))
    return 1
end

function metat.__index:close()
    if self.data then self.data:close() end
    if self.server then self.server:close() end
    return self.tp:close()
end

-----------------------------------------------------------------------------
-- High level FTP API
-----------------------------------------------------------------------------
local function override(t)
    if t.url then
        local u = url.parse(t.url)
        for i,v in base.pairs(t) do
            u[i] = v
        end
        return u
    else return t end
end

local function tput(putt)
    putt = override(putt)
    socket.try(putt.host, "missing hostname")
    local f = _M.open(putt.host, putt.port, putt.create)
    f:greet()
    f:login(putt.user, putt.password)
    if putt.type then f:type(putt.type) end
    f:epsv()
    local sent = f:send(putt)
    f:quit()
    f:close()
    return sent
end

local default = {
    path = "/",
    scheme = "ftp"
}

local function genericform(u)
    local t = socket.try(url.parse(u, default))
    socket.try(t.scheme == "ftp", "wrong scheme '" .. t.scheme .. "'")
    socket.try(t.host, "missing hostname")
    local pat = "^type=(.)$"
    if t.params then
        t.type = socket.skip(2, string.find(t.params, pat))
        socket.try(t.type == "a" or t.type == "i",
            "invalid type '" .. t.type .. "'")
    end
    return t
end

_M.genericform = genericform

local function sput(u, body)
    local putt = genericform(u)
    putt.source = ltn12.source.string(body)
    return tput(putt)
end

_M.put = socket.protect(function(putt, body)
    if base.type(putt) == "string" then return sput(putt, body)
    else return tput(putt) end
end)

local function tget(gett)
    gett = override(gett)
    socket.try(gett.host, "missing hostname")
    local f = _M.open(gett.host, gett.port, gett.create)
    f:greet()
    f:login(gett.user, gett.password)
    if gett.type then f:type(gett.type) end
    f:epsv()
    f:receive(gett)
    f:quit()
    return f:close()
end

local function sget(u)
    local gett = genericform(u)
    local t = {}
    gett.sink = ltn12.sink.table(t)
    tget(gett)
    return table.concat(t)
end

_M.command = socket.protect(function(cmdt)
    cmdt = override(cmdt)
    socket.try(cmdt.host, "missing hostname")
    socket.try(cmdt.command, "missing command")
    local f = _M.open(cmdt.host, cmdt.port, cmdt.create)
    f:greet()
    f:login(cmdt.user, cmdt.password)
    if type(cmdt.command) == "table" then
        local argument = cmdt.argument or {}
        local check = cmdt.check or {}
        for i,cmd in ipairs(cmdt.command) do
            f.try(f.tp:command(cmd, argument[i]))
            if check[i] then f.try(f.tp:check(check[i])) end
        end
    else
        f.try(f.tp:command(cmdt.command, cmdt.argument))
        if cmdt.check then f.try(f.tp:check(cmdt.check)) end
    end
    f:quit()
    return f:close()
end)

_M.get = socket.protect(function(gett)
    if base.type(gett) == "string" then return sget(gett)
    else return tget(gett) end
end)

return _M
)~~~";

/* socket.headers */
static const char *lua_m_socket_headers = R"~~~(
-----------------------------------------------------------------------------
-- Canonic header field capitalization
-- LuaSocket toolkit.
-- Author: Diego Nehab
-----------------------------------------------------------------------------
local socket = require("socket")
socket.headers = {}
local _M = socket.headers

_M.canonic = {
    ["accept"] = "Accept",
    ["accept-charset"] = "Accept-Charset",
    ["accept-encoding"] = "Accept-Encoding",
    ["accept-language"] = "Accept-Language",
    ["accept-ranges"] = "Accept-Ranges",
    ["action"] = "Action",
    ["alternate-recipient"] = "Alternate-Recipient",
    ["age"] = "Age",
    ["allow"] = "Allow",
    ["arrival-date"] = "Arrival-Date",
    ["authorization"] = "Authorization",
    ["bcc"] = "Bcc",
    ["cache-control"] = "Cache-Control",
    ["cc"] = "Cc",
    ["comments"] = "Comments",
    ["connection"] = "Connection",
    ["content-description"] = "Content-Description",
    ["content-disposition"] = "Content-Disposition",
    ["content-encoding"] = "Content-Encoding",
    ["content-id"] = "Content-ID",
    ["content-language"] = "Content-Language",
    ["content-length"] = "Content-Length",
    ["content-location"] = "Content-Location",
    ["content-md5"] = "Content-MD5",
    ["content-range"] = "Content-Range",
    ["content-transfer-encoding"] = "Content-Transfer-Encoding",
    ["content-type"] = "Content-Type",
    ["cookie"] = "Cookie",
    ["date"] = "Date",
    ["diagnostic-code"] = "Diagnostic-Code",
    ["dsn-gateway"] = "DSN-Gateway",
    ["etag"] = "ETag",
    ["expect"] = "Expect",
    ["expires"] = "Expires",
    ["final-log-id"] = "Final-Log-ID",
    ["final-recipient"] = "Final-Recipient",
    ["from"] = "From",
    ["host"] = "Host",
    ["if-match"] = "If-Match",
    ["if-modified-since"] = "If-Modified-Since",
    ["if-none-match"] = "If-None-Match",
    ["if-range"] = "If-Range",
    ["if-unmodified-since"] = "If-Unmodified-Since",
    ["in-reply-to"] = "In-Reply-To",
    ["keywords"] = "Keywords",
    ["last-attempt-date"] = "Last-Attempt-Date",
    ["last-modified"] = "Last-Modified",
    ["location"] = "Location",
    ["max-forwards"] = "Max-Forwards",
    ["message-id"] = "Message-ID",
    ["mime-version"] = "MIME-Version",
    ["original-envelope-id"] = "Original-Envelope-ID",
    ["original-recipient"] = "Original-Recipient",
    ["pragma"] = "Pragma",
    ["proxy-authenticate"] = "Proxy-Authenticate",
    ["proxy-authorization"] = "Proxy-Authorization",
    ["range"] = "Range",
    ["received"] = "Received",
    ["received-from-mta"] = "Received-From-MTA",
    ["references"] = "References",
    ["referer"] = "Referer",
    ["remote-mta"] = "Remote-MTA",
    ["reply-to"] = "Reply-To",
    ["reporting-mta"] = "Reporting-MTA",
    ["resent-bcc"] = "Resent-Bcc",
    ["resent-cc"] = "Resent-Cc",
    ["resent-date"] = "Resent-Date",
    ["resent-from"] = "Resent-From",
    ["resent-message-id"] = "Resent-Message-ID",
    ["resent-reply-to"] = "Resent-Reply-To",
    ["resent-sender"] = "Resent-Sender",
    ["resent-to"] = "Resent-To",
    ["retry-after"] = "Retry-After",
    ["return-path"] = "Return-Path",
    ["sender"] = "Sender",
    ["server"] = "Server",
    ["smtp-remote-recipient"] = "SMTP-Remote-Recipient",
    ["status"] = "Status",
    ["subject"] = "Subject",
    ["te"] = "TE",
    ["to"] = "To",
    ["trailer"] = "Trailer",
    ["transfer-encoding"] = "Transfer-Encoding",
    ["upgrade"] = "Upgrade",
    ["user-agent"] = "User-Agent",
    ["vary"] = "Vary",
    ["via"] = "Via",
    ["warning"] = "Warning",
    ["will-retry-until"] = "Will-Retry-Until",
    ["www-authenticate"] = "WWW-Authenticate",
    ["x-mailer"] = "X-Mailer",
}

return _M
)~~~";

/* socket.http */
static const char *lua_m_socket_http = R"~~~(
-----------------------------------------------------------------------------
-- HTTP/1.1 client support for the Lua language.
-- LuaSocket toolkit.
-- Author: Diego Nehab
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
-- Declare module and import dependencies
-------------------------------------------------------------------------------
local socket = require("socket")
local url = require("socket.url")
local ltn12 = require("ltn12")
local mime = require("mime")
local string = require("string")
local headers = require("socket.headers")
local base = _G
local table = require("table")
socket.http = {}
local _M = socket.http

-----------------------------------------------------------------------------
-- Program constants
-----------------------------------------------------------------------------
-- connection timeout in seconds
_M.TIMEOUT = 60
-- user agent field sent in request
_M.USERAGENT = socket._VERSION

-- supported schemes and their particulars
local SCHEMES = {
    http = {
        port = 80
        , create = function(t)
            return socket.tcp end }
    , https = {
        port = 443
        , create = function(t)
          local https = assert(
            require("ssl.https"), 'LuaSocket: LuaSec not found')
          local tcp = assert(
            https.tcp, 'LuaSocket: Function tcp() not available from LuaSec')
          return tcp(t) end }}

-- default scheme and port for document retrieval
local SCHEME = 'http'
local PORT = SCHEMES[SCHEME].port
-----------------------------------------------------------------------------
-- Reads MIME headers from a connection, unfolding where needed
-----------------------------------------------------------------------------
local function receiveheaders(sock, headers)
    local line, name, value, err
    headers = headers or {}
    -- get first line
    line, err = sock:receive()
    if err then return nil, err end
    -- headers go until a blank line is found
    while line ~= "" do
        -- get field-name and value
        name, value = socket.skip(2, string.find(line, "^(.-):%s*(.*)"))
        if not (name and value) then return nil, "malformed reponse headers" end
        name = string.lower(name)
        -- get next line (value might be folded)
        line, err  = sock:receive()
        if err then return nil, err end
        -- unfold any folded values
        while string.find(line, "^%s") do
            value = value .. line
            line = sock:receive()
            if err then return nil, err end
        end
        -- save pair in table
        if headers[name] then headers[name] = headers[name] .. ", " .. value
        else headers[name] = value end
    end
    return headers
end

-----------------------------------------------------------------------------
-- Extra sources and sinks
-----------------------------------------------------------------------------
socket.sourcet["http-chunked"] = function(sock, headers)
    return base.setmetatable({
        getfd = function() return sock:getfd() end,
        dirty = function() return sock:dirty() end
    }, {
        __call = function()
            -- get chunk size, skip extention
            local line, err = sock:receive()
            if err then return nil, err end
            local size = base.tonumber(string.gsub(line, ";.*", ""), 16)
            if not size then return nil, "invalid chunk size" end
            -- was it the last chunk?
            if size > 0 then
                -- if not, get chunk and skip terminating CRLF
                local chunk, err, part = sock:receive(size)
                if chunk then sock:receive() end
                return chunk, err
            else
                -- if it was, read trailers into headers table
                headers, err = receiveheaders(sock, headers)
                if not headers then return nil, err end
            end
        end
    })
end

socket.sinkt["http-chunked"] = function(sock)
    return base.setmetatable({
        getfd = function() return sock:getfd() end,
        dirty = function() return sock:dirty() end
    }, {
        __call = function(self, chunk, err)
            if not chunk then return sock:send("0\r\n\r\n") end
            local size = string.format("%X\r\n", string.len(chunk))
            return sock:send(size ..  chunk .. "\r\n")
        end
    })
end

-----------------------------------------------------------------------------
-- Low level HTTP API
-----------------------------------------------------------------------------
local metat = { __index = {} }

function _M.open(host, port, create)
    -- create socket with user connect function, or with default
    local c = socket.try(create())
    local h = base.setmetatable({ c = c }, metat)
    -- create finalized try
    h.try = socket.newtry(function() h:close() end)
    -- set timeout before connecting
    h.try(c:settimeout(_M.TIMEOUT))
    h.try(c:connect(host, port))
    -- here everything worked
    return h
end

function metat.__index:sendrequestline(method, uri)
    local reqline = string.format("%s %s HTTP/1.1\r\n", method or "GET", uri)
    return self.try(self.c:send(reqline))
end

function metat.__index:sendheaders(tosend)
    local canonic = headers.canonic
    local h = "\r\n"
    for f, v in base.pairs(tosend) do
        h = (canonic[f] or f) .. ": " .. v .. "\r\n" .. h
    end
    self.try(self.c:send(h))
    return 1
end

function metat.__index:sendbody(headers, source, step)
    source = source or ltn12.source.empty()
    step = step or ltn12.pump.step
    -- if we don't know the size in advance, send chunked and hope for the best
    local mode = "http-chunked"
    if headers["content-length"] then mode = "keep-open" end
    return self.try(ltn12.pump.all(source, socket.sink(mode, self.c), step))
end

function metat.__index:receivestatusline()
    local status,ec = self.try(self.c:receive(5))
    -- identify HTTP/0.9 responses, which do not contain a status line
    -- this is just a heuristic, but is what the RFC recommends
    if status ~= "HTTP/" then
        if ec == "timeout" then
            return 408
        end 
        return nil, status 
    end
    -- otherwise proceed reading a status line
    status = self.try(self.c:receive("*l", status))
    local code = socket.skip(2, string.find(status, "HTTP/%d*%.%d* (%d%d%d)"))
    return self.try(base.tonumber(code), status)
end

function metat.__index:receiveheaders()
    return self.try(receiveheaders(self.c))
end

function metat.__index:receivebody(headers, sink, step)
    sink = sink or ltn12.sink.null()
    step = step or ltn12.pump.step
    local length = base.tonumber(headers["content-length"])
    local t = headers["transfer-encoding"] -- shortcut
    local mode = "default" -- connection close
    if t and t ~= "identity" then mode = "http-chunked"
    elseif base.tonumber(headers["content-length"]) then mode = "by-length" end
    return self.try(ltn12.pump.all(socket.source(mode, self.c, length),
        sink, step))
end

function metat.__index:receive09body(status, sink, step)
    local source = ltn12.source.rewind(socket.source("until-closed", self.c))
    source(status)
    return self.try(ltn12.pump.all(source, sink, step))
end

function metat.__index:close()
    return self.c:close()
end

-----------------------------------------------------------------------------
-- High level HTTP API
-----------------------------------------------------------------------------
local function adjusturi(reqt)
    local u = reqt
    -- if there is a proxy, we need the full url. otherwise, just a part.
    if not reqt.proxy and not _M.PROXY then
        u = {
           path = socket.try(reqt.path, "invalid path 'nil'"),
           params = reqt.params,
           query = reqt.query,
           fragment = reqt.fragment
        }
    end
    return url.build(u)
end

local function adjustproxy(reqt)
    local proxy = reqt.proxy or _M.PROXY
    if proxy then
        proxy = url.parse(proxy)
        return proxy.host, proxy.port or 3128
    else
        return reqt.host, reqt.port
    end
end

local function adjustheaders(reqt)
    -- default headers
    local host = reqt.host
    local port = tostring(reqt.port)
    if port ~= tostring(SCHEMES[reqt.scheme].port) then
        host = host .. ':' .. port end
    local lower = {
        ["user-agent"] = _M.USERAGENT,
        ["host"] = host,
        ["connection"] = "close, TE",
        ["te"] = "trailers"
    }
    -- if we have authentication information, pass it along
    if reqt.user and reqt.password then
        lower["authorization"] =
            "Basic " ..  (mime.b64(reqt.user .. ":" ..
		url.unescape(reqt.password)))
    end
    -- if we have proxy authentication information, pass it along
    local proxy = reqt.proxy or _M.PROXY
    if proxy then
        proxy = url.parse(proxy)
        if proxy.user and proxy.password then
            lower["proxy-authorization"] =
                "Basic " ..  (mime.b64(proxy.user .. ":" .. proxy.password))
        end
    end
    -- override with user headers
    for i,v in base.pairs(reqt.headers or lower) do
        lower[string.lower(i)] = v
    end
    return lower
end

-- default url parts
local default = {
    path ="/"
    , scheme = "http"
}

local function adjustrequest(reqt)
    -- parse url if provided
    local nreqt = reqt.url and url.parse(reqt.url, default) or {}
    -- explicit components override url
    for i,v in base.pairs(reqt) do nreqt[i] = v end
    -- default to scheme particulars
    local schemedefs, host, port, method
        = SCHEMES[nreqt.scheme], nreqt.host, nreqt.port, nreqt.method
    if not nreqt.create then nreqt.create = schemedefs.create(nreqt) end
    if not (port and port ~= '') then nreqt.port = schemedefs.port end
    if not (method and method ~= '') then nreqt.method = 'GET' end
    if not (host and host ~= "") then
        socket.try(nil, "invalid host '" .. base.tostring(nreqt.host) .. "'")
    end
    -- compute uri if user hasn't overriden
    nreqt.uri = reqt.uri or adjusturi(nreqt)
    -- adjust headers in request
    nreqt.headers = adjustheaders(nreqt)
    -- ajust host and port if there is a proxy
    nreqt.host, nreqt.port = adjustproxy(nreqt)
    return nreqt
end

local function shouldredirect(reqt, code, headers)
    local location = headers.location
    if not location then return false end
    location = string.gsub(location, "%s", "")
    if location == "" then return false end
    local scheme = url.parse(location).scheme
    if scheme and (not SCHEMES[scheme]) then return false end
    -- avoid https downgrades
    if ('https' == reqt.scheme) and ('https' ~= scheme) then return false end
    return (reqt.redirect ~= false) and
           (code == 301 or code == 302 or code == 303 or code == 307) and
           (not reqt.method or reqt.method == "GET" or reqt.method == "HEAD")
        and ((false == reqt.maxredirects)
                or ((reqt.nredirects or 0)
                        < (reqt.maxredirects or 5)))
end

local function shouldreceivebody(reqt, code)
    if reqt.method == "HEAD" then return nil end
    if code == 204 or code == 304 then return nil end
    if code >= 100 and code < 200 then return nil end
    return 1
end

-- forward declarations
local trequest, tredirect

--[[local]] function tredirect(reqt, location)
    -- the RFC says the redirect URL has to be absolute, but some
    -- servers do not respect that
    local newurl = url.absolute(reqt.url, location)
    -- if switching schemes, reset port and create function
    if url.parse(newurl).scheme ~= reqt.scheme then
        reqt.port = nil
        reqt.create = nil end
    -- make new request
    local result, code, headers, status = trequest {
        url = newurl,
        source = reqt.source,
        sink = reqt.sink,
        headers = reqt.headers,
        proxy = reqt.proxy,
        maxredirects = reqt.maxredirects,
        nredirects = (reqt.nredirects or 0) + 1,
        create = reqt.create
    }
    -- pass location header back as a hint we redirected
    headers = headers or {}
    headers.location = headers.location or location
    return result, code, headers, status
end

--[[local]] function trequest(reqt)
    -- we loop until we get what we want, or
    -- until we are sure there is no way to get it
    local nreqt = adjustrequest(reqt)
    local h = _M.open(nreqt.host, nreqt.port, nreqt.create)
    -- send request line and headers
    h:sendrequestline(nreqt.method, nreqt.uri)
    h:sendheaders(nreqt.headers)
    -- if there is a body, send it
    if nreqt.source then
        h:sendbody(nreqt.headers, nreqt.source, nreqt.step)
    end
    local code, status = h:receivestatusline()
    -- if it is an HTTP/0.9 server, simply get the body and we are done
    if not code then
        h:receive09body(status, nreqt.sink, nreqt.step)
        return 1, 200
    elseif code == 408 then
        return 1, code
    end
    local headers
    -- ignore any 100-continue messages
    while code == 100 do
        headers = h:receiveheaders()
        code, status = h:receivestatusline()
    end
    headers = h:receiveheaders()
    -- at this point we should have a honest reply from the server
    -- we can't redirect if we already used the source, so we report the error
    if shouldredirect(nreqt, code, headers) and not nreqt.source then
        h:close()
        return tredirect(reqt, headers.location)
    end
    -- here we are finally done
    if shouldreceivebody(nreqt, code) then
        h:receivebody(headers, nreqt.sink, nreqt.step)
    end
    h:close()
    return 1, code, headers, status
end

-- turns an url and a body into a generic request
local function genericform(u, b)
    local t = {}
    local reqt = {
        url = u,
        sink = ltn12.sink.table(t),
        target = t
    }
    if b then
        reqt.source = ltn12.source.string(b)
        reqt.headers = {
            ["content-length"] = string.len(b),
            ["content-type"] = "application/x-www-form-urlencoded"
        }
        reqt.method = "POST"
    end
    return reqt
end

_M.genericform = genericform

local function srequest(u, b)
    local reqt = genericform(u, b)
    local _, code, headers, status = trequest(reqt)
    return table.concat(reqt.target), code, headers, status
end

_M.request = socket.protect(function(reqt, body)
    if base.type(reqt) == "string" then return srequest(reqt, body)
    else return trequest(reqt) end
end)

_M.schemes = SCHEMES
return _M
)~~~";

/* socket.mbox */
static const char *lua_m_socket_mbox = R"~~~(
local _M = {}

if module then
    mbox = _M
end 

function _M.split_message(message_s)
    local message = {}
    message_s = string.gsub(message_s, "\r\n", "\n")
    string.gsub(message_s, "^(.-\n)\n", function (h) message.headers = h end)
    string.gsub(message_s, "^.-\n\n(.*)", function (b) message.body = b end)
    if not message.body then
        string.gsub(message_s, "^\n(.*)", function (b) message.body = b end)
    end
    if not message.headers and not message.body then
        message.headers = message_s
    end
    return message.headers or "", message.body or ""
end

function _M.split_headers(headers_s)
    local headers = {}
    headers_s = string.gsub(headers_s, "\r\n", "\n")
    headers_s = string.gsub(headers_s, "\n[ ]+", " ")
    string.gsub("\n" .. headers_s, "\n([^\n]+)", function (h) table.insert(headers, h) end)
    return headers
end

function _M.parse_header(header_s)
    header_s = string.gsub(header_s, "\n[ ]+", " ")
    header_s = string.gsub(header_s, "\n+", "")
    local _, __, name, value = string.find(header_s, "([^%s:]-):%s*(.*)")
    return name, value
end

function _M.parse_headers(headers_s)
    local headers_t = _M.split_headers(headers_s)
    local headers = {}
    for i = 1, #headers_t do
        local name, value = _M.parse_header(headers_t[i])
        if name then
            name = string.lower(name)
            if headers[name] then
                headers[name] = headers[name] .. ", " .. value
            else headers[name] = value end
        end
    end
    return headers
end

function _M.parse_from(from)
    local _, __, name, address = string.find(from, "^%s*(.-)%s*%<(.-)%>")
    if not address then
        _, __, address = string.find(from, "%s*(.+)%s*")
    end
    name = name or ""
    address = address or ""
    if name == "" then name = address end
    name = string.gsub(name, '"', "")
    return name, address
end

function _M.split_mbox(mbox_s)
    local mbox = {}
    mbox_s = string.gsub(mbox_s, "\r\n", "\n") .."\n\nFrom \n"
    local nj, i, j = 1, 1, 1
    while 1 do
        i, nj = string.find(mbox_s, "\n\nFrom .-\n", j)
        if not i then break end
        local message = string.sub(mbox_s, j, i-1)
        table.insert(mbox, message)
        j = nj+1
    end
    return mbox
end

function _M.parse(mbox_s)
    local mbox = _M.split_mbox(mbox_s)
    for i = 1, #mbox do
        mbox[i] = _M.parse_message(mbox[i])
    end
    return mbox
end

function _M.parse_message(message_s)
    local message = {}
    message.headers, message.body = _M.split_message(message_s)
    message.headers = _M.parse_headers(message.headers)
    return message
end

return _M
)~~~";

/* socket.smtp */
static const char *lua_m_socket_smtp = R"~~~(
-----------------------------------------------------------------------------
-- SMTP client support for the Lua language.
-- LuaSocket toolkit.
-- Author: Diego Nehab
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
-- Declare module and import dependencies
-----------------------------------------------------------------------------
local base = _G
local coroutine = require("coroutine")
local string = require("string")
local math = require("math")
local os = require("os")
local socket = require("socket")
local tp = require("socket.tp")
local ltn12 = require("ltn12")
local headers = require("socket.headers")
local mime = require("mime")

socket.smtp = {}
local _M = socket.smtp

-----------------------------------------------------------------------------
-- Program constants
-----------------------------------------------------------------------------
-- timeout for connection
_M.TIMEOUT = 60
-- default server used to send e-mails
_M.SERVER = "localhost"
-- default port
_M.PORT = 25
-- domain used in HELO command and default sendmail
-- If we are under a CGI, try to get from environment
_M.DOMAIN = os.getenv("SERVER_NAME") or "localhost"
-- default time zone (means we don't know)
_M.ZONE = "-0000"

---------------------------------------------------------------------------
-- Low level SMTP API
-----------------------------------------------------------------------------
local metat = { __index = {} }

function metat.__index:greet(domain)
    self.try(self.tp:check("2.."))
    self.try(self.tp:command("EHLO", domain or _M.DOMAIN))
    return socket.skip(1, self.try(self.tp:check("2..")))
end

function metat.__index:mail(from)
    self.try(self.tp:command("MAIL", "FROM:" .. from))
    return self.try(self.tp:check("2.."))
end

function metat.__index:rcpt(to)
    self.try(self.tp:command("RCPT", "TO:" .. to))
    return self.try(self.tp:check("2.."))
end

function metat.__index:data(src, step)
    self.try(self.tp:command("DATA"))
    self.try(self.tp:check("3.."))
    self.try(self.tp:source(src, step))
    self.try(self.tp:send("\r\n.\r\n"))
    return self.try(self.tp:check("2.."))
end

function metat.__index:quit()
    self.try(self.tp:command("QUIT"))
    return self.try(self.tp:check("2.."))
end

function metat.__index:close()
    return self.tp:close()
end

function metat.__index:login(user, password)
    self.try(self.tp:command("AUTH", "LOGIN"))
    self.try(self.tp:check("3.."))
    self.try(self.tp:send(mime.b64(user) .. "\r\n"))
    self.try(self.tp:check("3.."))
    self.try(self.tp:send(mime.b64(password) .. "\r\n"))
    return self.try(self.tp:check("2.."))
end

function metat.__index:plain(user, password)
    local auth = "PLAIN " .. mime.b64("\0" .. user .. "\0" .. password)
    self.try(self.tp:command("AUTH", auth))
    return self.try(self.tp:check("2.."))
end

function metat.__index:auth(user, password, ext)
    if not user or not password then return 1 end
    if string.find(ext, "AUTH[^\n]+LOGIN") then
        return self:login(user, password)
    elseif string.find(ext, "AUTH[^\n]+PLAIN") then
        return self:plain(user, password)
    else
        self.try(nil, "authentication not supported")
    end
end

-- send message or throw an exception
function metat.__index:send(mailt)
    self:mail(mailt.from)
    if base.type(mailt.rcpt) == "table" then
        for i,v in base.ipairs(mailt.rcpt) do
            self:rcpt(v)
        end
    else
        self:rcpt(mailt.rcpt)
    end
    self:data(ltn12.source.chain(mailt.source, mime.stuff()), mailt.step)
end

function _M.open(server, port, create)
    local tp = socket.try(tp.connect(server or _M.SERVER, port or _M.PORT,
        _M.TIMEOUT, create))
    local s = base.setmetatable({tp = tp}, metat)
    -- make sure tp is closed if we get an exception
    s.try = socket.newtry(function()
        s:close()
    end)
    return s
end

-- convert headers to lowercase
local function lower_headers(headers)
    local lower = {}
    for i,v in base.pairs(headers or lower) do
        lower[string.lower(i)] = v
    end
    return lower
end

---------------------------------------------------------------------------
-- Multipart message source
-----------------------------------------------------------------------------
-- returns a hopefully unique mime boundary
local seqno = 0
local function newboundary()
    seqno = seqno + 1
    return string.format('%s%05d==%05u', os.date('%d%m%Y%H%M%S'),
        math.random(0, 99999), seqno)
end

-- send_message forward declaration
local send_message

-- yield the headers all at once, it's faster
local function send_headers(tosend)
    local canonic = headers.canonic
    local h = "\r\n"
    for f,v in base.pairs(tosend) do
        h = (canonic[f] or f) .. ': ' .. v .. "\r\n" .. h
    end
    coroutine.yield(h)
end

-- yield multipart message body from a multipart message table
local function send_multipart(mesgt)
    -- make sure we have our boundary and send headers
    local bd = newboundary()
    local headers = lower_headers(mesgt.headers or {})
    headers['content-type'] = headers['content-type'] or 'multipart/mixed'
    headers['content-type'] = headers['content-type'] ..
        '; boundary="' ..  bd .. '"'
    send_headers(headers)
    -- send preamble
    if mesgt.body.preamble then
        coroutine.yield(mesgt.body.preamble)
        coroutine.yield("\r\n")
    end
    -- send each part separated by a boundary
    for i, m in base.ipairs(mesgt.body) do
        coroutine.yield("\r\n--" .. bd .. "\r\n")
        send_message(m)
    end
    -- send last boundary
    coroutine.yield("\r\n--" .. bd .. "--\r\n\r\n")
    -- send epilogue
    if mesgt.body.epilogue then
        coroutine.yield(mesgt.body.epilogue)
        coroutine.yield("\r\n")
    end
end

-- yield message body from a source
local function send_source(mesgt)
    -- make sure we have a content-type
    local headers = lower_headers(mesgt.headers or {})
    headers['content-type'] = headers['content-type'] or
        'text/plain; charset="iso-8859-1"'
    send_headers(headers)
    -- send body from source
    while true do
        local chunk, err = mesgt.body()
        if err then coroutine.yield(nil, err)
        elseif chunk then coroutine.yield(chunk)
        else break end
    end
end

-- yield message body from a string
local function send_string(mesgt)
    -- make sure we have a content-type
    local headers = lower_headers(mesgt.headers or {})
    headers['content-type'] = headers['content-type'] or
        'text/plain; charset="iso-8859-1"'
    send_headers(headers)
    -- send body from string
    coroutine.yield(mesgt.body)
end

-- message source
function send_message(mesgt)
    if base.type(mesgt.body) == "table" then send_multipart(mesgt)
    elseif base.type(mesgt.body) == "function" then send_source(mesgt)
    else send_string(mesgt) end
end

-- set defaul headers
local function adjust_headers(mesgt)
    local lower = lower_headers(mesgt.headers)
    lower["date"] = lower["date"] or
        os.date("!%a, %d %b %Y %H:%M:%S ") .. (mesgt.zone or _M.ZONE)
    lower["x-mailer"] = lower["x-mailer"] or socket._VERSION
    -- this can't be overriden
    lower["mime-version"] = "1.0"
    return lower
end

function _M.message(mesgt)
    mesgt.headers = adjust_headers(mesgt)
    -- create and return message source
    local co = coroutine.create(function() send_message(mesgt) end)
    return function()
        local ret, a, b = coroutine.resume(co)
        if ret then return a, b
        else return nil, a end
    end
end

---------------------------------------------------------------------------
-- High level SMTP API
-----------------------------------------------------------------------------
_M.send = socket.protect(function(mailt)
    local s = _M.open(mailt.server, mailt.port, mailt.create)
    local ext = s:greet(mailt.domain)
    s:auth(mailt.user, mailt.password, ext)
    s:send(mailt)
    s:quit()
    return s:close()
end)

return _M
)~~~";

/* socket.tp */
static const char *lua_m_socket_tp = R"~~~(
-----------------------------------------------------------------------------
-- Unified SMTP/FTP subsystem
-- LuaSocket toolkit.
-- Author: Diego Nehab
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
-- Declare module and import dependencies
-----------------------------------------------------------------------------
local base = _G
local string = require("string")
local socket = require("socket")
local ltn12 = require("ltn12")

socket.tp = {}
local _M = socket.tp

-----------------------------------------------------------------------------
-- Program constants
-----------------------------------------------------------------------------
_M.TIMEOUT = 60

-----------------------------------------------------------------------------
-- Implementation
-----------------------------------------------------------------------------
-- gets server reply (works for SMTP and FTP)
local function get_reply(c)
    local code, current, sep
    local line, err = c:receive()
    local reply = line
    if err then return nil, err end
    code, sep = socket.skip(2, string.find(line, "^(%d%d%d)(.?)"))
    if not code then return nil, "invalid server reply" end
    if sep == "-" then -- reply is multiline
        repeat
            line, err = c:receive()
            if err then return nil, err end
            current, sep = socket.skip(2, string.find(line, "^(%d%d%d)(.?)"))
            reply = reply .. "\n" .. line
        -- reply ends with same code
        until code == current and sep == " "
    end
    return code, reply
end

-- metatable for sock object
local metat = { __index = {} }

function metat.__index:getpeername()
    return self.c:getpeername()
end

function metat.__index:getsockname()
    return self.c:getpeername()
end

function metat.__index:check(ok)
    local code, reply = get_reply(self.c)
    if not code then return nil, reply end
    if base.type(ok) ~= "function" then
        if base.type(ok) == "table" then
            for i, v in base.ipairs(ok) do
                if string.find(code, v) then
                    return base.tonumber(code), reply
                end
            end
            return nil, reply
        else
            if string.find(code, ok) then return base.tonumber(code), reply
            else return nil, reply end
        end
    else return ok(base.tonumber(code), reply) end
end

function metat.__index:command(cmd, arg)
    cmd = string.upper(cmd)
    if arg then
        return self.c:send(cmd .. " " .. arg.. "\r\n")
    else
        return self.c:send(cmd .. "\r\n")
    end
end

function metat.__index:sink(snk, pat)
    local chunk, err = self.c:receive(pat)
    return snk(chunk, err)
end

function metat.__index:send(data)
    return self.c:send(data)
end

function metat.__index:receive(pat)
    return self.c:receive(pat)
end

function metat.__index:getfd()
    return self.c:getfd()
end

function metat.__index:dirty()
    return self.c:dirty()
end

function metat.__index:getcontrol()
    return self.c
end

function metat.__index:source(source, step)
    local sink = socket.sink("keep-open", self.c)
    local ret, err = ltn12.pump.all(source, sink, step or ltn12.pump.step)
    return ret, err
end

-- closes the underlying c
function metat.__index:close()
    self.c:close()
    return 1
end

-- connect with server and return c object
function _M.connect(host, port, timeout, create)
    local c, e = (create or socket.tcp)()
    if not c then return nil, e end
    c:settimeout(timeout or _M.TIMEOUT)
    local r, e = c:connect(host, port)
    if not r then
        c:close()
        return nil, e
    end
    return base.setmetatable({c = c}, metat)
end

return _M
)~~~";

/* socket.url */
static const char *lua_m_socket_url = R"~~~(
-----------------------------------------------------------------------------
-- URI parsing, composition and relative URL resolution
-- LuaSocket toolkit.
-- Author: Diego Nehab
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
-- Declare module
-----------------------------------------------------------------------------
local string = require("string")
local base = _G
local table = require("table")
local socket = require("socket")

socket.url = {}
local _M = socket.url

-----------------------------------------------------------------------------
-- Module version
-----------------------------------------------------------------------------
_M._VERSION = "URL 1.0.3"

-----------------------------------------------------------------------------
-- Encodes a string into its escaped hexadecimal representation
-- Input
--   s: binary string to be encoded
-- Returns
--   escaped representation of string binary
-----------------------------------------------------------------------------
function _M.escape(s)
    return (string.gsub(s, "([^A-Za-z0-9_])", function(c)
        return string.format("%%%02x", string.byte(c))
    end))
end

-----------------------------------------------------------------------------
-- Protects a path segment, to prevent it from interfering with the
-- url parsing.
-- Input
--   s: binary string to be encoded
-- Returns
--   escaped representation of string binary
-----------------------------------------------------------------------------
local function make_set(t)
    local s = {}
    for i,v in base.ipairs(t) do
        s[t[i]] = 1
    end
    return s
end

-- these are allowed within a path segment, along with alphanum
-- other characters must be escaped
local segment_set = make_set {
    "-", "_", ".", "!", "~", "*", "'", "(",
    ")", ":", "@", "&", "=", "+", "$", ",",
}

local function protect_segment(s)
    return string.gsub(s, "([^A-Za-z0-9_])", function (c)
        if segment_set[c] then return c
        else return string.format("%%%02X", string.byte(c)) end
    end)
end

-----------------------------------------------------------------------------
-- Unencodes a escaped hexadecimal string into its binary representation
-- Input
--   s: escaped hexadecimal string to be unencoded
-- Returns
--   unescaped binary representation of escaped hexadecimal  binary
-----------------------------------------------------------------------------
function _M.unescape(s)
    return (string.gsub(s, "%%(%x%x)", function(hex)
        return string.char(base.tonumber(hex, 16))
    end))
end

-----------------------------------------------------------------------------
-- Removes '..' and '.' components appropriately from a path.
-- Input
--   path
-- Returns
--   dot-normalized path
local function remove_dot_components(path)
    local marker = string.char(1)
    repeat
        local was = path
        path = path:gsub('//', '/'..marker..'/', 1)
    until path == was
    repeat
        local was = path
        path = path:gsub('/%./', '/', 1)
    until path == was
    repeat
        local was = path
        path = path:gsub('[^/]+/%.%./([^/]+)', '%1', 1)
    until path == was
    path = path:gsub('[^/]+/%.%./*$', '')
    path = path:gsub('/%.%.$', '/')
    path = path:gsub('/%.$', '/')
    path = path:gsub('^/%.%./', '/')
    path = path:gsub(marker, '')
    return path
end

-----------------------------------------------------------------------------
-- Builds a path from a base path and a relative path
-- Input
--   base_path
--   relative_path
-- Returns
--   corresponding absolute path
-----------------------------------------------------------------------------
local function absolute_path(base_path, relative_path)
    if string.sub(relative_path, 1, 1) == "/" then
      return remove_dot_components(relative_path) end
    base_path = base_path:gsub("[^/]*$", "")
    if not base_path:find'/$' then base_path = base_path .. '/' end
    local path = base_path .. relative_path
    path = remove_dot_components(path)
    return path
end

-----------------------------------------------------------------------------
-- Parses a url and returns a table with all its parts according to RFC 2396
-- The following grammar describes the names given to the URL parts
-- <url> ::= <scheme>://<authority>/<path>;<params>?<query>#<fragment>
-- <authority> ::= <userinfo>@<host>:<port>
-- <userinfo> ::= <user>[:<password>]
-- <path> :: = {<segment>/}<segment>
-- Input
--   url: uniform resource locator of request
--   default: table with default values for each field
-- Returns
--   table with the following fields, where RFC naming conventions have
--   been preserved:
--     scheme, authority, userinfo, user, password, host, port,
--     path, params, query, fragment
-- Obs:
--   the leading '/' in {/<path>} is considered part of <path>
-----------------------------------------------------------------------------
function _M.parse(url, default)
    -- initialize default parameters
    local parsed = {}
    for i,v in base.pairs(default or parsed) do parsed[i] = v end
    -- empty url is parsed to nil
    if not url or url == "" then return nil, "invalid url" end
    -- remove whitespace
    -- url = string.gsub(url, "%s", "")
    -- get scheme
    url = string.gsub(url, "^([%w][%w%+%-%.]*)%:",
        function(s) parsed.scheme = s; return "" end)
    -- get authority
    url = string.gsub(url, "^//([^/]*)", function(n)
        parsed.authority = n
        return ""
    end)
    -- get fragment
    url = string.gsub(url, "#(.*)$", function(f)
        parsed.fragment = f
        return ""
    end)
    -- get query string
    url = string.gsub(url, "%?(.*)", function(q)
        parsed.query = q
        return ""
    end)
    -- get params
    url = string.gsub(url, "%;(.*)", function(p)
        parsed.params = p
        return ""
    end)
    -- path is whatever was left
    if url ~= "" then parsed.path = url end
    local authority = parsed.authority
    if not authority then return parsed end
    authority = string.gsub(authority,"^([^@]*)@",
        function(u) parsed.userinfo = u; return "" end)
    authority = string.gsub(authority, ":([^:%]]*)$",
        function(p) parsed.port = p; return "" end)
    if authority ~= "" then 
        -- IPv6?
        parsed.host = string.match(authority, "^%[(.+)%]$") or authority 
    end
    local userinfo = parsed.userinfo
    if not userinfo then return parsed end
    userinfo = string.gsub(userinfo, ":([^:]*)$",
        function(p) parsed.password = p; return "" end)
    parsed.user = userinfo
    return parsed
end

-----------------------------------------------------------------------------
-- Rebuilds a parsed URL from its components.
-- Components are protected if any reserved or unallowed characters are found
-- Input
--   parsed: parsed URL, as returned by parse
-- Returns
--   a stringing with the corresponding URL
-----------------------------------------------------------------------------
function _M.build(parsed)
    --local ppath = _M.parse_path(parsed.path or "")
    --local url = _M.build_path(ppath)
    local url = parsed.path or ""
    if parsed.params then url = url .. ";" .. parsed.params end
    if parsed.query then url = url .. "?" .. parsed.query end
    local authority = parsed.authority
    if parsed.host then
        authority = parsed.host
        if string.find(authority, ":") then -- IPv6?
            authority = "[" .. authority .. "]"
        end
        if parsed.port then authority = authority .. ":" .. base.tostring(parsed.port) end
        local userinfo = parsed.userinfo
        if parsed.user then
            userinfo = parsed.user
            if parsed.password then
                userinfo = userinfo .. ":" .. parsed.password
            end
        end
        if userinfo then authority = userinfo .. "@" .. authority end
    end
    if authority then url = "//" .. authority .. url end
    if parsed.scheme then url = parsed.scheme .. ":" .. url end
    if parsed.fragment then url = url .. "#" .. parsed.fragment end
    -- url = string.gsub(url, "%s", "")
    return url
end

-----------------------------------------------------------------------------
-- Builds a absolute URL from a base and a relative URL according to RFC 2396
-- Input
--   base_url
--   relative_url
-- Returns
--   corresponding absolute url
-----------------------------------------------------------------------------
function _M.absolute(base_url, relative_url)
    local base_parsed
    if base.type(base_url) == "table" then
        base_parsed = base_url
        base_url = _M.build(base_parsed)
    else
        base_parsed = _M.parse(base_url)
    end
    local result
    local relative_parsed = _M.parse(relative_url)
    if not base_parsed then
        result = relative_url
    elseif not relative_parsed then
        result = base_url
    elseif relative_parsed.scheme then
        result = relative_url
    else
        relative_parsed.scheme = base_parsed.scheme
        if not relative_parsed.authority then
            relative_parsed.authority = base_parsed.authority
            if not relative_parsed.path then
                relative_parsed.path = base_parsed.path
                if not relative_parsed.params then
                    relative_parsed.params = base_parsed.params
                    if not relative_parsed.query then
                        relative_parsed.query = base_parsed.query
                    end
                end
            else    
                relative_parsed.path = absolute_path(base_parsed.path or "",
                    relative_parsed.path)
            end
        end
        result = _M.build(relative_parsed)
    end
    return remove_dot_components(result)
end

-----------------------------------------------------------------------------
-- Breaks a path into its segments, unescaping the segments
-- Input
--   path
-- Returns
--   segment: a table with one entry per segment
-----------------------------------------------------------------------------
function _M.parse_path(path)
    local parsed = {}
    path = path or ""
    --path = string.gsub(path, "%s", "")
    string.gsub(path, "([^/]+)", function (s) table.insert(parsed, s) end)
    for i = 1, #parsed do
        parsed[i] = _M.unescape(parsed[i])
    end
    if string.sub(path, 1, 1) == "/" then parsed.is_absolute = 1 end
    if string.sub(path, -1, -1) == "/" then parsed.is_directory = 1 end
    return parsed
end

-----------------------------------------------------------------------------
-- Builds a path component from its segments, escaping protected characters.
-- Input
--   parsed: path segments
--   unsafe: if true, segments are not protected before path is built
-- Returns
--   path: corresponding path stringing
-----------------------------------------------------------------------------
function _M.build_path(parsed, unsafe)
    local path = ""
    local n = #parsed
    if unsafe then
        for i = 1, n-1 do
            path = path .. parsed[i]
            path = path .. "/"
        end
        if n > 0 then
            path = path .. parsed[n]
            if parsed.is_directory then path = path .. "/" end
        end
    else
        for i = 1, n-1 do
            path = path .. protect_segment(parsed[i])
            path = path .. "/"
        end
        if n > 0 then
            path = path .. protect_segment(parsed[n])
            if parsed.is_directory then path = path .. "/" end
        end
    end
    if parsed.is_absolute then path = "/" .. path end
    return path
end

return _M
)~~~";

/* socket */
static const char *lua_m_socket = R"~~~(
-----------------------------------------------------------------------------
-- LuaSocket helper module
-- Author: Diego Nehab
-----------------------------------------------------------------------------

-----------------------------------------------------------------------------
-- Declare module and import dependencies
-----------------------------------------------------------------------------
local base = _G
local string = require("string")
local math = require("math")
local socket = require("socket.core")

local _M = socket

-----------------------------------------------------------------------------
-- Exported auxiliar functions
-----------------------------------------------------------------------------
function _M.connect4(address, port, laddress, lport)
    return socket.connect(address, port, laddress, lport, "inet")
end

function _M.connect6(address, port, laddress, lport)
    return socket.connect(address, port, laddress, lport, "inet6")
end

function _M.bind(host, port, backlog)
    if host == "*" then host = "0.0.0.0" end
    local addrinfo, err = socket.dns.getaddrinfo(host);
    if not addrinfo then return nil, err end
    local sock, res
    err = "no info on address"
    for i, alt in base.ipairs(addrinfo) do
        if alt.family == "inet" then
            sock, err = socket.tcp4()
        else
            sock, err = socket.tcp6()
        end
        if not sock then return nil, err end
        sock:setoption("reuseaddr", true)
        res, err = sock:bind(alt.addr, port)
        if not res then
            sock:close()
        else
            res, err = sock:listen(backlog)
            if not res then
                sock:close()
            else
                return sock
            end
        end
    end
    return nil, err
end

_M.try = _M.newtry()

function _M.choose(table)
    return function(name, opt1, opt2)
        if base.type(name) ~= "string" then
            name, opt1, opt2 = "default", name, opt1
        end
        local f = table[name or "nil"]
        if not f then base.error("unknown key (".. base.tostring(name) ..")", 3)
        else return f(opt1, opt2) end
    end
end

-----------------------------------------------------------------------------
-- Socket sources and sinks, conforming to LTN12
-----------------------------------------------------------------------------
-- create namespaces inside LuaSocket namespace
local sourcet, sinkt = {}, {}
_M.sourcet = sourcet
_M.sinkt = sinkt

_M.BLOCKSIZE = 2048

sinkt["close-when-done"] = function(sock)
    return base.setmetatable({
        getfd = function() return sock:getfd() end,
        dirty = function() return sock:dirty() end
    }, {
        __call = function(self, chunk, err)
            if not chunk then
                sock:close()
                return 1
            else return sock:send(chunk) end
        end
    })
end

sinkt["keep-open"] = function(sock)
    return base.setmetatable({
        getfd = function() return sock:getfd() end,
        dirty = function() return sock:dirty() end
    }, {
        __call = function(self, chunk, err)
            if chunk then return sock:send(chunk)
            else return 1 end
        end
    })
end

sinkt["default"] = sinkt["keep-open"]

_M.sink = _M.choose(sinkt)

sourcet["by-length"] = function(sock, length)
    return base.setmetatable({
        getfd = function() return sock:getfd() end,
        dirty = function() return sock:dirty() end
    }, {
        __call = function()
            if length <= 0 then return nil end
            local size = math.min(socket.BLOCKSIZE, length)
            local chunk, err = sock:receive(size)
            if err then return nil, err end
            length = length - string.len(chunk)
            return chunk
        end
    })
end

sourcet["until-closed"] = function(sock)
    local done
    return base.setmetatable({
        getfd = function() return sock:getfd() end,
        dirty = function() return sock:dirty() end
    }, {
        __call = function()
            if done then return nil end
            local chunk, err, partial = sock:receive(socket.BLOCKSIZE)
            if not err then return chunk
            elseif err == "closed" then
                sock:close()
                done = 1
                return partial
            else return nil, err end
        end
    })
end


sourcet["default"] = sourcet["until-closed"]

_M.source = _M.choose(sourcet)

return _M
)~~~";



int luaopen_lua_m_ltn12(lua_State *L) {
    luaL_loadstring(L, lua_m_ltn12);
    return 1;
}


int luaopen_lua_m_mime(lua_State *L) {
    luaL_loadstring(L, lua_m_mime);
    return 1;
}


int luaopen_lua_m_socket_ftp(lua_State *L) {
    luaL_loadstring(L, lua_m_socket_ftp);
    return 1;
}


int luaopen_lua_m_socket_headers(lua_State *L) {
    luaL_loadstring(L, lua_m_socket_headers);
    return 1;
}


int luaopen_lua_m_socket_http(lua_State *L) {
    luaL_loadstring(L, lua_m_socket_http);
    return 1;
}


int luaopen_lua_m_socket_mbox(lua_State *L) {
    luaL_loadstring(L, lua_m_socket_mbox);
    return 1;
}


int luaopen_lua_m_socket_smtp(lua_State *L) {
    luaL_loadstring(L, lua_m_socket_smtp);
    return 1;
}


int luaopen_lua_m_socket_tp(lua_State *L) {
    luaL_loadstring(L, lua_m_socket_tp);
    return 1;
}


int luaopen_lua_m_socket_url(lua_State *L) {
    luaL_loadstring(L, lua_m_socket_url);
    return 1;
}


int luaopen_lua_m_socket(lua_State *L) {
    luaL_loadstring(L, lua_m_socket);
    return 1;
}


static luaL_Reg luasocket_scripts_modules[] = {
    {"ltn12", luaopen_lua_m_ltn12},
    {"mime", luaopen_lua_m_mime},
    {"socket.ftp", luaopen_lua_m_socket_ftp},
    {"socket.headers", luaopen_lua_m_socket_headers},
    {"socket.http", luaopen_lua_m_socket_http},
    {"socket.mbox", luaopen_lua_m_socket_mbox},
    {"socket.smtp", luaopen_lua_m_socket_smtp},
    {"socket.tp", luaopen_lua_m_socket_tp},
    {"socket.url", luaopen_lua_m_socket_url},
    {"socket", luaopen_lua_m_socket},
    {NULL, NULL}
};

int luaopen_luasocket_scripts(lua_State* L)
{
    luaL_Reg* lib = luasocket_scripts_modules;
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "preload");
    for (; lib->func; lib++)
    {
        lib->func(L);
        lua_setfield(L, -2, lib->name);
    }
    lua_pop(L, 2);
    return 0;
}
