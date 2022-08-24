local debugger_reLoadFile =nil
local debugger_xpcall = nil
local debugger_stackInfo = nil
local coro_debugger = nil
local debugger_require = require
local debugger_exeLuaString = nil
local checkSetVar = nil
local loadstring_ = nil
local debugger_sendMsg = nil
if (loadstring) then
    loadstring_ = loadstring
else
    loadstring_ = load
end
--只针对 luadebug 调试 jit版本不存在这个问题
local setfenv = setfenv
if (not setfenv) then
    setfenv =
        function(fn, env)
        local i = 1
        while true do
            local name = debug.getupvalue(fn, i)
            if name == "_ENV" then
                debug.upvaluejoin(
                    fn,
                    i,
                    (function()
                        return env
                    end),
                    1
                )
                break
            elseif not name then
                break
            end

            i = i + 1
        end
        return fn
    end
end
local ZZBase64 = {}
local LuaDebugTool_ = nil
if (LuaDebugTool) then
    LuaDebugTool_ = LuaDebugTool
elseif (CS and CS.LuaDebugTool) then
    LuaDebugTool_ = CS.LuaDebugTool
end
local LuaDebugTool = LuaDebugTool_
local loadstring = loadstring_
local getinfo = debug.getinfo
local function createSocket()
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

    if (not _M.connect) then
        function _M.connect(address, port, laddress, lport)
            local sock, err = socket.tcp()
            if not sock then
                return nil, err
            end
            if laddress then
                local res, err = sock:bind(laddress, lport, -1)
                if not res then
                    return nil, err
                end
            end
            local res, err = sock:connect(address, port)
            if not res then
                return nil, err
            end
            return sock
        end
    end
    function _M.bind(host, port, backlog)
        if host == "*" then
            host = "0.0.0.0"
        end
        local addrinfo, err = socket.dns.getaddrinfo(host)
        if not addrinfo then
            return nil, err
        end
        local sock, res
        err = "no info on address"
        for i, alt in base.ipairs(addrinfo) do
            if alt.family == "inet" then
                sock, err = socket.tcp4()
            else
                sock, err = socket.tcp6()
            end
            if not sock then
                return nil, err
            end
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
            if not f then
                base.error("unknown key (" .. base.tostring(name) .. ")", 3)
            else
                return f(opt1, opt2)
            end
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

    sinkt["close-when-done"] =
        function(sock)
        return base.setmetatable(
            {
                getfd = function()
                    return sock:getfd()
                end,
                dirty = function()
                    return sock:dirty()
                end
            },
            {
                __call = function(self, chunk, err)
                    if not chunk then
                        sock:close()
                        return 1
                    else
                        return sock:send(chunk)
                    end
                end
            }
        )
    end

    sinkt["keep-open"] =
        function(sock)
        return base.setmetatable(
            {
                getfd = function()
                    return sock:getfd()
                end,
                dirty = function()
                    return sock:dirty()
                end
            },
            {
                __call = function(self, chunk, err)
                    if chunk then
                        return sock:send(chunk)
                    else
                        return 1
                    end
                end
            }
        )
    end

    sinkt["default"] = sinkt["keep-open"]

    _M.sink = _M.choose(sinkt)

    sourcet["by-length"] =
        function(sock, length)
        return base.setmetatable(
            {
                getfd = function()
                    return sock:getfd()
                end,
                dirty = function()
                    return sock:dirty()
                end
            },
            {
                __call = function()
                    if length <= 0 then
                        return nil
                    end
                    local size = math.min(socket.BLOCKSIZE, length)
                    local chunk, err = sock:receive(size)
                    if err then
                        return nil, err
                    end
                    length = length - string.len(chunk)
                    return chunk
                end
            }
        )
    end

    sourcet["until-closed"] =
        function(sock)
        local done
        return base.setmetatable(
            {
                getfd = function()
                    return sock:getfd()
                end,
                dirty = function()
                    return sock:dirty()
                end
            },
            {
                __call = function()
                    if done then
                        return nil
                    end
                    local chunk, err, partial = sock:receive(socket.BLOCKSIZE)
                    if not err then
                        return chunk
                    elseif err == "closed" then
                        sock:close()
                        done = 1
                        return partial
                    else
                        return nil, err
                    end
                end
            }
        )
    end

    sourcet["default"] = sourcet["until-closed"]

    _M.source = _M.choose(sourcet)

    return _M
end

local function createJson()
    local math = require("math")
    local string = require("string")
    local table = require("table")
    local object = nil
    -----------------------------------------------------------------------------
    -- Module declaration
    -----------------------------------------------------------------------------
    local json = {} -- Public namespace
    local json_private = {} -- Private namespace

    -- Public constants
    json.EMPTY_ARRAY = {}
    json.EMPTY_OBJECT = {}
    -- Public functions

    -- Private functions
    local decode_scanArray
    local decode_scanComment
    local decode_scanConstant
    local decode_scanNumber
    local decode_scanObject
    local decode_scanString
    local decode_scanWhitespace
    local encodeString
    local isArray
    local isEncodable

    -----------------------------------------------------------------------------
    -- PUBLIC FUNCTIONS
    -----------------------------------------------------------------------------
    --- Encodes an arbitrary Lua object / variable.
    -- @param v The Lua object / variable to be JSON encoded.
    -- @return String containing the JSON encoding in internal Lua string format (i.e. not unicode)
    function json.encode(v)
        -- Handle nil values
        if v == nil then
            return "null"
        end

        local vtype = type(v)

        -- Handle strings
        if vtype == "string" then
            return '"' .. json_private.encodeString(v) .. '"' -- Need to handle encoding in string
        end

        -- Handle booleans
        if vtype == "number" or vtype == "boolean" then
            return tostring(v)
        end

        -- Handle tables
        if vtype == "table" then
            local rval = {}
            -- Consider arrays separately
            local bArray, maxCount = isArray(v)
            if bArray then
                for i = 1, maxCount do
                    table.insert(rval, json.encode(v[i]))
                end
            else -- An object, not an array
                for i, j in pairs(v) do
                    if isEncodable(i) and isEncodable(j) then
                        table.insert(rval, '"' .. json_private.encodeString(i) .. '":' .. json.encode(j))
                    end
                end
            end
            if bArray then
                return "[" .. table.concat(rval, ",") .. "]"
            else
                return "{" .. table.concat(rval, ",") .. "}"
            end
        end

        -- Handle null values
        if vtype == "function" and v == json.null then
            return "null"
        end

        assert(false, "encode attempt to encode unsupported type " .. vtype .. ":" .. tostring(v))
    end

    --- Decodes a JSON string and returns the decoded value as a Lua data structure / value.
    -- @param s The string to scan.
    -- @param [startPos] Optional starting position where the JSON string is located. Defaults to 1.
    -- @param Lua object, number The object that was scanned, as a Lua table / string / number / boolean or nil,
    -- and the position of the first character after
    -- the scanned JSON object.
    function json.decode(s, startPos)
        startPos = startPos and startPos or 1
        startPos = decode_scanWhitespace(s, startPos)
        assert(startPos <= string.len(s), "Unterminated JSON encoded object found at position in [" .. s .. "]")
        local curChar = string.sub(s, startPos, startPos)
        -- Object
        if curChar == "{" then
            return decode_scanObject(s, startPos)
        end
        -- Array
        if curChar == "[" then
            return decode_scanArray(s, startPos)
        end
        -- Number
        if string.find("+-0123456789.e", curChar, 1, true) then
            return decode_scanNumber(s, startPos)
        end
        -- String
        if curChar == '"' or curChar == [[']] then
            return decode_scanString(s, startPos)
        end
        if string.sub(s, startPos, startPos + 1) == "/*" then
            return json.decode(s, decode_scanComment(s, startPos))
        end
        -- Otherwise, it must be a constant
        return decode_scanConstant(s, startPos)
    end

    --- The null function allows one to specify a null value in an associative array (which is otherwise
    -- discarded if you set the value with 'nil' in Lua. Simply set t = { first=json.null }
    function json.null()
        return json.null -- so json.null() will also return null ;-)
    end
    -----------------------------------------------------------------------------
    -- Internal, PRIVATE functions.
    -- Following a Python-like convention, I have prefixed all these 'PRIVATE'
    -- functions with an underscore.
    -----------------------------------------------------------------------------
    --- Scans an array from JSON into a Lua object
    -- startPos begins at the start of the array.
    -- Returns the array and the next starting position
    -- @param s The string being scanned.
    -- @param startPos The starting position for the scan.
    -- @return table, int The scanned array as a table, and the position of the next character to scan.
    function decode_scanArray(s, startPos)
        local array = {} -- The return value
        local stringLen = string.len(s)
        assert(
            string.sub(s, startPos, startPos) == "[",
            "decode_scanArray called but array does not start at position " .. startPos .. " in string:\n" .. s
        )
        startPos = startPos + 1
        -- Infinite loop for array elements
        repeat
            startPos = decode_scanWhitespace(s, startPos)
            assert(startPos <= stringLen, "JSON String ended unexpectedly scanning array.")
            local curChar = string.sub(s, startPos, startPos)
            if (curChar == "]") then
                return array, startPos + 1
            end
            if (curChar == ",") then
                startPos = decode_scanWhitespace(s, startPos + 1)
            end
            assert(startPos <= stringLen, "JSON String ended unexpectedly scanning array.")
            object, startPos = json.decode(s, startPos)
            table.insert(array, object)
        until false
    end

    --- Scans a comment and discards the comment.
    -- Returns the position of the next character following the comment.
    -- @param string s The JSON string to scan.
    -- @param int startPos The starting position of the comment
    function decode_scanComment(s, startPos)
        assert(
            string.sub(s, startPos, startPos + 1) == "/*",
            "decode_scanComment called but comment does not start at position " .. startPos
        )
        local endPos = string.find(s, "*/", startPos + 2)
        assert(endPos ~= nil, "Unterminated comment in string at " .. startPos)
        return endPos + 2
    end

    --- Scans for given constants: true, false or null
    -- Returns the appropriate Lua type, and the position of the next character to read.
    -- @param s The string being scanned.
    -- @param startPos The position in the string at which to start scanning.
    -- @return object, int The object (true, false or nil) and the position at which the next character should be
    -- scanned.
    function decode_scanConstant(s, startPos)
        local consts = {["true"] = true, ["false"] = false, ["null"] = nil}
        local constNames = {"true", "false", "null"}

        for i, k in pairs(constNames) do
            if string.sub(s, startPos, startPos + string.len(k) - 1) == k then
                return consts[k], startPos + string.len(k)
            end
        end
        assert(nil, "Failed to scan constant from string " .. s .. " at starting position " .. startPos)
    end

    --- Scans a number from the JSON encoded string.
    -- (in fact, also is able to scan numeric +- eqns, which is not
    -- in the JSON spec.)
    -- Returns the number, and the position of the next character
    -- after the number.
    -- @param s The string being scanned.
    -- @param startPos The position at which to start scanning.
    -- @return number, int The extracted number and the position of the next character to scan.
    function decode_scanNumber(s, startPos)
        local endPos = startPos + 1
        local stringLen = string.len(s)
        local acceptableChars = "+-0123456789.e"
        while (string.find(acceptableChars, string.sub(s, endPos, endPos), 1, true) and endPos <= stringLen) do
            endPos = endPos + 1
        end
        local stringValue = "return " .. string.sub(s, startPos, endPos - 1)
        local stringEval = loadstring(stringValue)
        assert(
            stringEval,
            "Failed to scan number [ " .. stringValue .. "] in JSON string at position " .. startPos .. " : " .. endPos
        )
        return stringEval(), endPos
    end

    --- Scans a JSON object into a Lua object.
    -- startPos begins at the start of the object.
    -- Returns the object and the next starting position.
    -- @param s The string being scanned.
    -- @param startPos The starting position of the scan.
    -- @return table, int The scanned object as a table and the position of the next character to scan.
    function decode_scanObject(s, startPos)
        local object = {}
        local stringLen = string.len(s)
        local key, value
        assert(
            string.sub(s, startPos, startPos) == "{",
            "decode_scanObject called but object does not start at position " .. startPos .. " in string:\n" .. s
        )
        startPos = startPos + 1
        repeat
            startPos = decode_scanWhitespace(s, startPos)
            assert(startPos <= stringLen, "JSON string ended unexpectedly while scanning object.")
            local curChar = string.sub(s, startPos, startPos)
            if (curChar == "}") then
                return object, startPos + 1
            end
            if (curChar == ",") then
                startPos = decode_scanWhitespace(s, startPos + 1)
            end
            assert(startPos <= stringLen, "JSON string ended unexpectedly scanning object.")
            -- Scan the key
            key, startPos = json.decode(s, startPos)
            assert(startPos <= stringLen, "JSON string ended unexpectedly searching for value of key " .. key)
            startPos = decode_scanWhitespace(s, startPos)
            assert(startPos <= stringLen, "JSON string ended unexpectedly searching for value of key " .. key)
            assert(
                string.sub(s, startPos, startPos) == ":",
                "JSON object key-value assignment mal-formed at " .. startPos
            )
            startPos = decode_scanWhitespace(s, startPos + 1)
            assert(startPos <= stringLen, "JSON string ended unexpectedly searching for value of key " .. key)
            value, startPos = json.decode(s, startPos)
            object[key] = value
        until false -- infinite loop while key-value pairs are found
    end

    -- START SoniEx2
    -- Initialize some things used by decode_scanString
    -- You know, for efficiency
    local escapeSequences = {
        ["\\t"] = "\t",
        ["\\f"] = "\f",
        ["\\r"] = "\r",
        ["\\n"] = "\n",
        ["\\b"] = ""
    }
    setmetatable(
        escapeSequences,
        {
            __index = function(t, k)
                -- skip "\" aka strip escape
                return string.sub(k, 2)
            end
        }
    )
    -- END SoniEx2
    --- Scans a JSON string from the opening inverted comma or single quote to the
    -- end of the string.
    -- Returns the string extracted as a Lua string,
    -- and the position of the next non-string character
    -- (after the closing inverted comma or single quote).
    -- @param s The string being scanned.
    -- @param startPos The starting position of the scan.
    -- @return string, int The extracted string as a Lua string, and the next character to parse.
    function decode_scanString(s, startPos)
        assert(startPos, "decode_scanString(..) called without start position")
        local startChar = string.sub(s, startPos, startPos)
        -- START SoniEx2
        -- PS: I don't think single quotes are valid JSON
        assert(startChar == '"' or startChar == [[']], "decode_scanString called for a non-string")
        --assert(startPos, "String decoding failed: missing closing " .. startChar .. " for string at position " .. oldStart)
        local t = {}
        local i, j = startPos, startPos
        while string.find(s, startChar, j + 1) ~= j + 1 do
            local oldj = j
            i, j = string.find(s, "\\.", j + 1)
            local x, y = string.find(s, startChar, oldj + 1)
            if not i or x < i then
                i, j = x, y - 1
            end
            table.insert(t, string.sub(s, oldj + 1, i - 1))
            if string.sub(s, i, j) == "\\u" then
                local a = string.sub(s, j + 1, j + 4)
                j = j + 4
                local n = tonumber(a, 16)
                assert(n, "String decoding failed: bad Unicode escape " .. a .. " at position " .. i .. " : " .. j)
                -- math.floor(x/2^y) == lazy right shift
                -- a % 2^b == bitwise_and(a, (2^b)-1)
                -- 64 = 2^6
                -- 4096 = 2^12 (or 2^6 * 2^6)
                local x
                if n < 128 then
                    x = string.char(n % 128)
                elseif n < 2048 then
                    -- [110x xxxx] [10xx xxxx]
                    x = string.char(192 + (math.floor(n / 64) % 32), 128 + (n % 64))
                else
                    -- [1110 xxxx] [10xx xxxx] [10xx xxxx]
                    x = string.char(224 + (math.floor(n / 4096) % 16), 128 + (math.floor(n / 64) % 64), 128 + (n % 64))
                end
                table.insert(t, x)
            else
                table.insert(t, escapeSequences[string.sub(s, i, j)])
            end
        end
        table.insert(t, string.sub(j, j + 1))
        assert(
            string.find(s, startChar, j + 1),
            "String decoding failed: missing closing " ..
                startChar .. " at position " .. j .. "(for string at position " .. startPos .. ")"
        )
        return table.concat(t, ""), j + 2
        -- END SoniEx2
    end

    --- Scans a JSON string skipping all whitespace from the current start position.
    -- Returns the position of the first non-whitespace character, or nil if the whole end of string is reached.
    -- @param s The string being scanned
    -- @param startPos The starting position where we should begin removing whitespace.
    -- @return int The first position where non-whitespace was encountered, or string.len(s)+1 if the end of string
    -- was reached.
    function decode_scanWhitespace(s, startPos)
        local whitespace = " \n\r\t"
        local stringLen = string.len(s)
        while (string.find(whitespace, string.sub(s, startPos, startPos), 1, true) and startPos <= stringLen) do
            startPos = startPos + 1
        end
        return startPos
    end

    --- Encodes a string to be JSON-compatible.
    -- This just involves back-quoting inverted commas, back-quotes and newlines, I think ;-)
    -- @param s The string to return as a JSON encoded (i.e. backquoted string)
    -- @return The string appropriately escaped.
    local escapeList = {
        ['"'] = '\\"',
        ["\\"] = "\\\\",
        ["/"] = "\\/",
        [""] = "\\b",
        ["\f"] = "\\f",
        ["\n"] = "\\n",
        ["\r"] = "\\r",
        ["\t"] = "\\t"
    }

    function json_private.encodeString(s)
        local s = tostring(s)
        return s:gsub(
            ".",
            function(c)
                return escapeList[c]
            end
        ) -- SoniEx2: 5.0 compat
    end

    -- Determines whether the given Lua type is an array or a table / dictionary.
    -- We consider any table an array if it has indexes 1..n for its n items, and no
    -- other data in the table.
    -- I think this method is currently a little 'flaky', but can't think of a good way around it yet...
    -- @param t The table to evaluate as an array
    -- @return boolean, number True if the table can be represented as an array, false otherwise. If true,
    -- the second returned value is the maximum
    -- number of indexed elements in the array.
    function isArray(t)
        -- Next we count all the elements, ensuring that any non-indexed elements are not-encodable
        -- (with the possible exception of 'n')
        if (t == json.EMPTY_ARRAY) then
            return true, 0
        end
        if (t == json.EMPTY_OBJECT) then
            return false
        end

        local maxIndex = 0
        for k, v in pairs(t) do
            if (type(k) == "number" and math.floor(k) == k and 1 <= k) then -- k,v is an indexed pair
                if (not isEncodable(v)) then
                    return false
                end -- All array elements must be encodable
                maxIndex = math.max(maxIndex, k)
            else
                if (k == "n") then
                    if v ~= (t.n or #t) then
                        return false
                    end -- False if n does not hold the number of elements
                else -- Else of (k=='n')
                    if isEncodable(v) then
                        return false
                    end
                end -- End of (k~='n')
            end -- End of k,v not an indexed pair
        end -- End of loop across all pairs
        return true, maxIndex
    end

    --- Determines whether the given Lua object / table / variable can be JSON encoded. The only
    -- types that are JSON encodable are: string, boolean, number, nil, table and json.null.
    -- In this implementation, all other types are ignored.
    -- @param o The object to examine.
    -- @return boolean True if the object should be JSON encoded, false if it should be ignored.
    function isEncodable(o)
        local t = type(o)
        return (t == "string" or t == "boolean" or t == "number" or t == "nil" or t == "table") or
            (t == "function" and o == json.null)
    end

    return json
end
local debugger_print = print
local debug_server = nil
local breakInfoSocket = nil
local json = createJson()
local LuaDebugger = {
    fileMaps = {},
    Run = true,  --表示正常运行只检测断点
    StepIn = false,
    StepInLevel = 0,
    StepNext = false,
    StepNextLevel = 0,
    StepOut = false,
    breakInfos = {},
    runTimeType = nil,
    isHook = true,
    pathCachePaths = {},
    isProntToConsole = 1,
    isFoxGloryProject = false,
    isDebugPrint = true,
    hookType = "lrc",
    currentFileName = "",
    currentTempFunc = nil,
    --分割字符串缓存
    splitFilePaths = {},
    DebugLuaFie = "",
    version = "0.9.3",
    serVarLevel = 4
}
local debug_hook = nil
local _resume = coroutine.resume
coroutine.resume = function(co, ...)
    if (LuaDebugger.isHook) then
        if coroutine.status(co) ~= "dead" then
            debug.sethook(co, debug_hook, "lrc")
        end
    end
    return _resume(co, ...)
end
local oldXpcall = xpcall
xpcall = function(runFun,errFun,...)
    return oldXpcall(runFun,function(err)
        if(debugger_xpcall) then
            debugger_xpcall()
        end
        errFun(err)
    end,...)
end
LuaDebugger.event = {
    S2C_SetBreakPoints = 1,
    C2S_SetBreakPoints = 2,
    S2C_RUN = 3,
    C2S_HITBreakPoint = 4,
    S2C_ReqVar = 5,
    C2S_ReqVar = 6,
    --单步跳过请求
    S2C_NextRequest = 7,
    --单步跳过反馈
    C2S_NextResponse = 8,
    -- 单步跳过 结束 没有下一步
    C2S_NextResponseOver = 9,
    --单步跳入
    S2C_StepInRequest = 10,
    C2S_StepInResponse = 11,
    --单步跳出
    S2C_StepOutRequest = 12,
    --单步跳出返回
    C2S_StepOutResponse = 13,
    --打印
    C2S_LuaPrint = 14,
    S2C_LoadLuaScript = 16,
    C2S_SetSocketName = 17,
    C2S_LoadLuaScript = 18,
    C2S_DebugXpCall = 20,
    S2C_DebugClose = 21,
    S2C_SerVar = 24,
    C2S_SerVar = 25,
    S2C_ReLoadFile = 26,
    C2S_ReLoadFile = 27,
}
--@region print
function print(...)
    if (LuaDebugger.isProntToConsole == 1 or LuaDebugger.isProntToConsole == 3) then
        debugger_print(...)
    end
    if (LuaDebugger.isProntToConsole == 1 or LuaDebugger.isProntToConsole == 2) then
        if (debug_server) then
            local arg = {...} --这里的...和{}符号中间需要有空格号，否则会出错
            local str = ""
            if (#arg == 0) then
                arg = {"nil"}
            end
            for k, v in pairs(arg) do
                str = str .. tostring(v) .. "\t"
            end
            local sendMsg = {
                event = LuaDebugger.event.C2S_LuaPrint,
                data = {msg = ZZBase64.encode(str), type = 1}
            }
            local sendStr = json.encode(sendMsg)
            debug_server:send(sendStr .. "__debugger_k0204__")
        end
    end
end

function luaIdePrintWarn(...)
    if (LuaDebugger.isProntToConsole == 1 or LuaDebugger.isProntToConsole == 3) then
        debugger_print(...)
    end
    if (LuaDebugger.isProntToConsole == 1 or LuaDebugger.isProntToConsole == 2) then
        if (debug_server) then
            local arg = {...} --这里的...和{}符号中间需要有空格号，否则会出错
            local str = ""
            if (#arg == 0) then
                arg = {"nil"}
            end
            for k, v in pairs(arg) do
                str = str .. tostring(v) .. "\t"
            end
            local sendMsg = {
                event = LuaDebugger.event.C2S_LuaPrint,
                data = {msg = ZZBase64.encode(str), type = 2}
            }
            local sendStr = json.encode(sendMsg)
            debug_server:send(sendStr .. "__debugger_k0204__")
        end
    end
end
function luaIdePrintErr(...)
    if (LuaDebugger.isProntToConsole == 1 or LuaDebugger.isProntToConsole == 3) then
        debugger_print(...)
    end
    if (LuaDebugger.isProntToConsole == 1 or LuaDebugger.isProntToConsole == 2) then
        if (debug_server) then
            local arg = {...} --这里的...和{}符号中间需要有空格号，否则会出错
            local str = ""
            if (#arg == 0) then
                arg = {"nil"}
            end
            for k, v in pairs(arg) do
                str = str .. tostring(v) .. "\t"
            end
            local sendMsg = {
                event = LuaDebugger.event.C2S_LuaPrint,
                data = {msg = ZZBase64.encode(str), type = 3}
            }
            local sendStr = json.encode(sendMsg)
            debug_server:send(sendStr .. "__debugger_k0204__")
        end
    end
end
--@endregion

--@region 辅助方法
local function debugger_lastIndex(str, p)
    local startIndex = string.find(str, p, 1)
    while startIndex do
        local findstartIndex = string.find(str, p, startIndex + 1)
        if (not findstartIndex) then
            break
        else
            startIndex = findstartIndex
        end
    end
    return startIndex
end
local function debugger_convertParentDir(dir)
    local index, endindex = string.find(dir, "/%.%./")
    if (index) then
        local file1 = string.sub(dir, 1, index - 1)
        local startIndex = debugger_lastIndex(file1, "/")
        file1 = string.sub(file1, 1, startIndex - 1)
        local file2 = string.sub(dir, endindex)
        dir = file1 .. file2
        dir = debugger_convertParentDir(dir)
        return dir
    else
        return dir
    end
end

local function debugger_getFilePathInfo(file)
    local fileName = nil
    local dir = nil
    file = file:gsub("/.\\", "/")
    file = file:gsub("\\", "/")
    file = file:gsub("//", "/")
    

    if file:find("@") == 1 then
        file = file:sub(2)
    end
    local findex = file:find("%./")
    if (findex == 1) then
        file = file:sub(3)
    end

    file = debugger_convertParentDir(file)
    local fileLength = string.len(file)
    local suffixNames = {
        ".lua",
        ".txt.lua",
        ".txt",
        ".bytes"
    }
    table.sort(
        suffixNames,
        function(name1, name2)
            return string.len(name1) > string.len(name2)
        end
    )
    local suffixLengs = {}
    for i, suffixName in ipairs(suffixNames) do
        table.insert(suffixLengs, string.len(suffixName))
    end

    local fileLength = string.len(file)
    for i, suffix in ipairs(suffixNames) do
        local suffixName = string.sub(file, fileLength - suffixLengs[i] + 1)
        if (suffixName == suffix) then
            file = string.sub(file, 1, fileLength - suffixLengs[i])
            break
        end
    end
    local fileNameStartIndex = debugger_lastIndex(file, "/")
    if (fileNameStartIndex) then
        fileName = string.sub(file, fileNameStartIndex + 1)

        dir = string.sub(file, 1, fileNameStartIndex)
        file = dir .. fileName
    else
        fileNameStartIndex = debugger_lastIndex(file, "%.")
        if (not fileNameStartIndex) then
            fileName = file
            dir = ""
        else
            dir = string.sub(file, 1, fileNameStartIndex)
            dir = dir:gsub("%.", "/")
            fileName = string.sub(file, fileNameStartIndex + 1)
            file = dir .. fileName
        end
    end

    return file, dir, fileName
end

--@endregion



----=============================工具方法=============================================
--@region 工具方法


local function debugger_strSplit(input, delimiter)
    input = tostring(input)
    delimiter = tostring(delimiter)
    if (delimiter == "") then
        return false
    end
    local pos, arr = 0, {}
    -- for each divider found
    for st, sp in function()
        return string.find(input, delimiter, pos, true)
    end do
        table.insert(arr, string.sub(input, pos, st - 1))
        pos = sp + 1
    end
    table.insert(arr, string.sub(input, pos))
    return arr
end
local function debugger_strTrim(input)
    input = string.gsub(input, "^[ \t\n\r]+", "")
    return string.gsub(input, "[ \t\n\r]+$", "")
end
local function debugger_dump(value, desciption, nesting)
    if type(nesting) ~= "number" then
        nesting = 3
    end
    local lookupTable = {}
    local result = {}
    local function _v(v)
        if type(v) == "string" then
            v = '"' .. v .. '"'
        end
        return tostring(v)
    end
    local traceback = debugger_strSplit(debug.traceback("", 2), "\n")
    print("dump from: " .. debugger_strTrim(traceback[3]))
    local function _dump(value, desciption, indent, nest, keylen)
        desciption = desciption or "<var>"
        local spc = ""
        if type(keylen) == "number" then
            spc = string.rep(" ", keylen - string.len(_v(desciption)))
        end
        if type(value) ~= "table" then
            result[#result + 1] = string.format("%s%s%s = %s", indent, _v(desciption), spc, _v(value))
        elseif lookupTable[value] then
            result[#result + 1] = string.format("%s%s%s = *REF*", indent, desciption, spc)
        else
            lookupTable[value] = true
            if nest > nesting then
                result[#result + 1] = string.format("%s%s = *MAX NESTING*", indent, desciption)
            else
                result[#result + 1] = string.format("%s%s = {", indent, _v(desciption))
                local indent2 = indent .. "    "
                local keys = {}
                local keylen = 0
                local values = {}
                for k, v in pairs(value) do
                    keys[#keys + 1] = k
                    local vk = _v(k)
                    local vkl = string.len(vk)
                    if vkl > keylen then
                        keylen = vkl
                    end
                    values[k] = v
                end
                table.sort(
                    keys,
                    function(a, b)
                        if type(a) == "number" and type(b) == "number" then
                            return a < b
                        else
                            return tostring(a) < tostring(b)
                        end
                    end
                )
                for i, k in ipairs(keys) do
                    _dump(values[k], k, indent2, nest + 1, keylen)
                end
                result[#result + 1] = string.format("%s}", indent)
            end
        end
    end
    _dump(value, desciption, "- ", 1)
    for i, line in ipairs(result) do
        print(line)
    end
end
--@endregion
local function debugger_valueToString(v)
    local vtype = type(v) 
    local vstr = nil
    if (vtype == "userdata") then
        if (LuaDebugger.isFoxGloryProject) then
           
            return "userdata",vtype
        
        else
            return tostring(v), vtype
        end
    elseif (vtype == "table" or vtype == "function" or vtype == "boolean") then
        local value = vtype
        xpcall(function() 
            value = tostring(v)
        end,function()
            value = vtype
        end)
        return value, vtype
    elseif (vtype == "number" or vtype == "string" ) then
        return v, vtype
    else
        return tostring(v), vtype
    end
end
local function debugger_setVarInfo(name, value)
    local valueStr, valueType = debugger_valueToString(value)
    local nameStr,nameType = debugger_valueToString(name)
    if(valueStr == nil) then
        valueStr = valueType
    end
    local valueInfo = {
        name =nameStr,
        valueType = valueType,
        valueStr = ZZBase64.encode(valueStr)
    }

    return valueInfo
end

local function debugger_getvalue(f)
    local i = 1
    local locals = {}
    -- get locals
    while true do
        local name, value = debug.getlocal(f, i)
        if not name then
            break
        end
        if (name ~= "(*temporary)") then
            locals[name] = value
        end
        i = i + 1
    end
    local func = getinfo(f, "f").func
    i = 1
    local ups = {}
    while func do -- check for func as it may be nil for tail calls
        local name, value = debug.getupvalue(func, i)
        if not name then
            break
        end
        if (name == "_ENV") then
            ups["_ENV_"] = value
        else
            ups[name] = value
        end
        i = i + 1
    end

	return {locals = locals, ups = ups}
end
--获取堆栈
debugger_stackInfo =
    function(ignoreCount, event)
    local datas = {}
    local stack = {}
    local varInfos = {}
    local funcs = {}
    local index = 0
    for i = ignoreCount, 100 do
        local source = getinfo(i)
        local isadd = true
        if (i == ignoreCount) then
            local file = source.source
            if (file:find(LuaDebugger.DebugLuaFie)) then
                return
            end
            if (file == "=[C]") then
                isadd = false
            end
        end
        if not source then
            break
        end
        if (isadd) then
            local fullName, dir, fileName = debugger_getFilePathInfo(source.source)
            local info = {
                src = fullName,
                scoreName = source.name,
                currentline = source.currentline,
                linedefined = source.linedefined,
                what = source.what,
                nameWhat = source.namewhat
            }
            index = i
            local vars = debugger_getvalue(i + 1)
            table.insert(stack, info)
            table.insert(varInfos, vars)
            table.insert(funcs, source.func)
        end
        if source.what == "main" then
            break
        end
	end
	
    local stackInfo = {stack = stack, vars = varInfos, funcs = funcs}
    local data = {
        stack = stackInfo.stack,
        vars = stackInfo.vars,
        funcs = stackInfo.funcs,
        event = event,
		funcsLength = #stackInfo.funcs,
        upFunc = getinfo(ignoreCount - 3, "f").func
    }
    LuaDebugger.currentTempFunc = data.funcs[1]
    return data
end

--===========================点断信息==================================================
--根据不同的游戏引擎进行定时获取断点信息
--CCDirector:sharedDirector():getScheduler()
local debugger_setBreak = nil
local function debugger_receiveDebugBreakInfo()
    if (jit) then
        if (LuaDebugger.debugLuaType ~= "jit") then
            local msg = "当前luajit版本为: " .. jit.version .. " 请使用LuaDebugjit 进行调试!"
            print(msg)
        end
    end
    if (breakInfoSocket) then
        local msg, status = breakInfoSocket:receive()
        if(LuaDebugger.isLaunch and status == "closed") then 
                os.exit()
        end
        if (msg) then
            local netData = json.decode(msg)
            if netData.event == LuaDebugger.event.S2C_SetBreakPoints then
                debugger_setBreak(netData.data)
            elseif netData.event == LuaDebugger.event.S2C_LoadLuaScript then
				LuaDebugger.loadScriptBody = netData.data
                debugger_exeLuaString()
                debugger_sendMsg(breakInfoSocket,LuaDebugger.event.C2S_LoadLuaScript,LuaDebugger.loadScriptBody)
            elseif netData.event == LuaDebugger.event.S2C_ReLoadFile then
                LuaDebugger.reLoadFileBody = netData.data
                LuaDebugger.isReLoadFile = false
                LuaDebugger.reLoadFileBody.isReLoad =  debugger_reLoadFile(LuaDebugger.reLoadFileBody)
                print("重载结果:",LuaDebugger.reLoadFileBody.isReLoad)
                LuaDebugger.reLoadFileBody.script = nil
                debugger_sendMsg(
                    breakInfoSocket,
                    LuaDebugger.event.C2S_ReLoadFile,
                    {
                        stack = LuaDebugger.reLoadFileBody
                       
                    }
				)
			end
        end
    end
end
local function splitFilePath(path)
    if (LuaDebugger.splitFilePaths[path]) then
        return LuaDebugger.splitFilePaths[path]
    end
    local pos, arr = 0, {}
    -- for each divider found
    for st, sp in function()
        return string.find(path, "/", pos, true)
    end do
        local pathStr = string.sub(path, pos, st - 1)
        table.insert(arr, pathStr)
        pos = sp + 1
    end
    local pathStr = string.sub(path, pos)
    table.insert(arr, pathStr)
    LuaDebugger.splitFilePaths[path] = arr
    return arr
end
debugger_setBreak =
    function(datas)
    local breakInfos = LuaDebugger.breakInfos
    for i, data in ipairs(datas) do
        data.fileName = string.lower(data.fileName)
        data.serverPath = string.lower(data.serverPath)
        local breakInfo = breakInfos[data.fileName]
        if (not breakInfo) then
            breakInfos[data.fileName] = {}
            breakInfo = breakInfos[data.fileName]
        end
        if (not data.breakDatas or #data.breakDatas == 0) then
            breakInfo[data.serverPath] = nil
        else
            local fileBreakInfo = breakInfo[data.serverPath]
            if (not fileBreakInfo) then
                fileBreakInfo = {
                    pathNames = splitFilePath(data.serverPath),
                    --命中次數判斷計數器
                    hitCounts = {}
                }
                breakInfo[data.serverPath] = fileBreakInfo
            end
            local lineInfos = {}
            for li, breakData in ipairs(data.breakDatas) do
                lineInfos[breakData.line] = breakData
                if (breakData.hitCondition and breakData.hitCondition ~= "") then
                    breakData.hitCondition = tonumber(breakData.hitCondition)
                else
                    breakData.hitCondition = 0
                end
                if (not fileBreakInfo.hitCounts[breakData.line]) then
                    fileBreakInfo.hitCounts[breakData.line] = 0
                end
            end
            fileBreakInfo.lines = lineInfos
            --這裡添加命中次數判斷
            for line, count in pairs(fileBreakInfo.hitCounts) do
                if (not lineInfos[line]) then
                    fileBreakInfo.hitCounts[line] = nil
                end
            end
        end
        local count = 0
        for i, linesInfo in pairs(breakInfo) do
            count = count + 1
        end
        if (count == 0) then
            breakInfos[data.fileName] = nil
        end
    end
    --debugger_dump(breakInfos, "breakInfos", 6)
    --检查是否需要断点
    local isHook = false
    for k, v in pairs(breakInfos) do
        isHook = true
        break
    end

    --这样做的原因是为了最大限度的使手机调试更加流畅 注意这里会连续的进行n次
    if (isHook) then
        if (not LuaDebugger.isHook) then
            debug.sethook(debug_hook, "lrc")
        end
        LuaDebugger.isHook = true
    else
        if (LuaDebugger.isHook) then
            debug.sethook()
        end
        LuaDebugger.isHook = false
    end
end
local function debugger_checkFileIsBreak(fileName)
    return LuaDebugger.breakInfos[fileName]
end
--=====================================断点信息 end ----------------------------------------------
local controller_host = "192.168.1.102"
local controller_port = 7003
debugger_sendMsg = function(serverSocket, eventName, data)
    local sendMsg = {
        event = eventName,
        data = data
    }
    local sendStr = json.encode(sendMsg)
    serverSocket:send(sendStr .. "__debugger_k0204__")
end
function debugger_conditionStr(condition, vars, callBack)
    local function loadScript()
        local currentTabble = {}

        local locals = vars[1].locals
        local ups = vars[1].ups
        if (ups) then
            for k, v in pairs(ups) do
                currentTabble[k] = v
            end
        end

        if (locals) then
            for k, v in pairs(locals) do
                currentTabble[k] = v
            end
        end
        setmetatable(currentTabble, {__index = _G})
        local fun = loadstring("return " .. condition)
        setfenv(fun, currentTabble)
        return fun()
    end
    local status,
        msg =
        xpcall(
        loadScript,
        function(error)
            print(error)
        end
    )
    if (status and msg) then
        callBack()
    end
end
--执行lua字符串
debugger_exeLuaString = function()
      
    local function loadScript()
       
        local script = LuaDebugger.loadScriptBody.script
        if (LuaDebugger.loadScriptBody.isBreak) then
            local currentTabble = {_G = _G}
            local frameId = LuaDebugger.loadScriptBody.frameId
            frameId = frameId
            local func = LuaDebugger.currentDebuggerData.funcs[frameId]
            local vars = LuaDebugger.currentDebuggerData.vars[frameId]
            local locals = vars.locals
            local ups = vars.ups
            for k, v in pairs(ups) do
                currentTabble[k] = v
            end
            for k, v in pairs(locals) do
                currentTabble[k] = v
            end
            setmetatable(currentTabble, {__index = _G})
    
            local fun = loadstring(script)
            setfenv(fun, currentTabble)
            fun()
        else
            local fun = loadstring(script)
            fun()
        end
    end
    local status,
        msg =
        xpcall(
        loadScript,
        function(error)
            
            -- debugger_sendMsg(debug_server, LuaDebugger.event.C2S_LoadLuaScript, LuaDebugger.loadScriptBody)
        end
    )
	LuaDebugger.loadScriptBody.script = nil
    if (LuaDebugger.loadScriptBody.isBreak) then
		LuaDebugger.serVarLevel = LuaDebugger.serVarLevel+1
		LuaDebugger.currentDebuggerData = debugger_stackInfo(LuaDebugger.serVarLevel, LuaDebugger.event.C2S_HITBreakPoint)
		LuaDebugger.loadScriptBody.stack = LuaDebugger.currentDebuggerData.stack
	end
    LuaDebugger.loadScriptBody.complete = true
   
end
--@region 调试中修改变量值


--根据key 值在 value 查找
local function debugger_getTablekey(key,keyType,value)
    if(keyType == -1) then
        return key
    elseif(keyType == 1) then
        return tonumber(key)
    elseif(keyType == 2) then
        local valueKey = nil
        for k,v in pairs(value) do
            local nameType = type(k)
            if(nameType == "userdata" or nameType == "table") then
                if (not LuaDebugger.isFoxGloryProject) then
                    valueKey = tostring(k)
                    if(key == valueKey) then
                        return k
                    end
                    break
                end
            end
        end
       
    end
end

local function debugger_setVarValue(server, data)
    
    local newValue = nil
    local level = LuaDebugger.serVarLevel+LuaDebugger.setVarBody.frameId
    local firstKeyName = data.keys[1]
    --@region vars check
    local localValueChangeIndex = -1
    local upValueChangeIndex = -1
    local upValueFun = nil
    local oldValue = nil
    local i = 1
    local locals = {}
    -- get locals
    while true do
        local name, value = debug.getlocal(level, i)
        if not name then
            break
        end
        if(firstKeyName == name) then
            localValueChangeIndex = i
            oldValue = value
        end
        if (name ~= "(*temporary)") then
            locals[name] = value
        end
        i = i + 1
    end
    local func = getinfo(level, "f").func
    i = 1
    local ups = {}
    while func do -- check for func as it may be nil for tail calls
        local name, value = debug.getupvalue(func, i)
       
        if not name then
            break
        end
        if(localValueChangeIndex == -1 and firstKeyName == name) then
            upValueFun = func
            oldValue = value
            upValueChangeIndex = i
        end
        if (name == "_ENV") then
            ups["_ENV_"] = value
        else
            ups[name] = value
        end
        i = i + 1
    end
--@endregion
   local vars = {locals = locals, ups = ups}
  
    local function loadScript()
        local currentTabble = {}
        local locals = vars.locals
        local ups = vars.ups
        if (ups) then
            for k, v in pairs(ups) do
                currentTabble[k] = v
            end
        end

        if (locals) then
            for k, v in pairs(locals) do
                currentTabble[k] = v
            end
        end
        setmetatable(currentTabble, {__index = _G})
        local fun = loadstring("return " .. data.value)
        setfenv(fun, currentTabble)
        newValue = fun()
    end
    local status,
        msg =
        xpcall(
        loadScript,
        function(error)
            print(error, "============================")
        end
    )
  
    local i = 1
   
    -- local 查找并替换
    local keyLength = #data.keys
   
    if(keyLength == 1) then
        if(localValueChangeIndex ~= -1) then
            
            debug.setlocal(level, localValueChangeIndex, newValue)
        elseif(upValueFun ~= nil) then
            debug.setupvalue( upValueFun, upValueChangeIndex, newValue )
        else
            --全局变量查找
            if(_G[firstKeyName]) then
                _G[firstKeyName] = newValue
            end
        end
    else
        if(not oldValue) then
            if(_G[firstKeyName]) then
                oldValue = _G[firstKeyName]
            end
        end
        local tempValue = oldValue
        for i=2,keyLength-1 do
            if(tempValue) then
                oldValue = oldValue[debugger_getTablekey(data.keys[i],data.numberTypes[i],oldValue)]
            end
        end
        if(tempValue) then
            oldValue[debugger_getTablekey(data.keys[keyLength],data.numberTypes[keyLength],oldValue)] = newValue
        end
    end
	local varInfo = debugger_setVarInfo(data.varName, newValue)
    data.varInfo = varInfo
    LuaDebugger.serVarLevel = LuaDebugger.serVarLevel+1
    LuaDebugger.currentDebuggerData = debugger_stackInfo(LuaDebugger.serVarLevel, LuaDebugger.event.C2S_HITBreakPoint)
    
end
--@endregion




--调试修改变量值统一的 _resume
checkSetVar =
    function()
    if (LuaDebugger.isSetVar) then
        LuaDebugger.isSetVar = false 
        debugger_setVarValue(debug_server,LuaDebugger.setVarBody)
        LuaDebugger.serVarLevel = LuaDebugger.serVarLevel+1
        _resume(coro_debugger, LuaDebugger.setVarBody)
        xpcall(
            checkSetVar,
            function(error)
                print("设置变量", error)
            end
        )
    elseif(LuaDebugger.isLoadLuaScript) then
        LuaDebugger.isLoadLuaScript = false
        debugger_exeLuaString()
        LuaDebugger.serVarLevel = LuaDebugger.serVarLevel+1
		_resume(coro_debugger, LuaDebugger.reLoadFileBody)
        xpcall(
            checkSetVar,
            function(error)
                print("执行代码", error)
            end
		)
	elseif(LuaDebugger.isReLoadFile) then
        LuaDebugger.isReLoadFile = false
        LuaDebugger.reLoadFileBody.isReLoad =  debugger_reLoadFile(LuaDebugger.reLoadFileBody)
        print("重载结果:",LuaDebugger.reLoadFileBody.isReLoad)
        LuaDebugger.reLoadFileBody.script = nil
        LuaDebugger.serVarLevel = LuaDebugger.serVarLevel+1
        _resume(coro_debugger, LuaDebugger.reLoadFileBody)
        xpcall(
            checkSetVar,
            function(error)
                print("重新加载文件", error)
            end
        )
    end
end
  


local function getSource(source)
    source = string.lower(source)
    if (LuaDebugger.pathCachePaths[source]) then
        LuaDebugger.currentLineFile = LuaDebugger.pathCachePaths[source]
        return LuaDebugger.pathCachePaths[source]
    end

    local fullName, dir, fileName = debugger_getFilePathInfo(source)
    LuaDebugger.currentLineFile = fullName
    LuaDebugger.pathCachePaths[source] = fileName

    return fileName
end
local function debugger_GeVarInfoBytUserData(server, var)
    local fileds = LuaDebugTool.getUserDataInfo(var)

    local varInfos = {}
 

    --c# vars
    for i = 1, fileds.Count do
        local filed = fileds[i - 1]
        local valueInfo = {
            name = filed.name,
            valueType = filed.valueType,
            valueStr = ZZBase64.encode(filed.valueStr),
            isValue = filed.isValue,
            csharp = true
        }

        table.insert(varInfos, valueInfo)
    end
    return varInfos
end

local function debugger_getValueByScript(value, script)
    local val = nil
    local status,
        msg =
        xpcall(
        function()
            local fun = loadstring("return " .. script)
            setfenv(fun, value)
            val = fun()
        end,
        function(error)
            print(error, "====>")
            val = nil
        end
    )

    return val
end
local function debugger_getVarByKeys(value, keys, index)
    local str = ""
    local keyLength = #keys
    for i = index, keyLength do
        local key = keys[i]
        if (key == "[metatable]") then
        else
            if (i == index) then
                if (string.find(key, "%.")) then
                    if (str == "") then
                        i = index + 1
                        value = value[key]
                    end
                    if (i >= #keys) then
                        return index, value
                    end

                    return debugger_getVarByKeys(value, keys, i)
                else
                    str = key
                end
            else
                if (string.find(key, "%[")) then
                    str = str .. key
                elseif (type(key) == "string") then
                    if (string.find(key, "table:") or string.find(key, "userdata:") or string.find(key, "function:")) then
                        if (str ~= "") then
                            local vl = debugger_getValueByScript(value, str)
                            value = vl
                            if (value) then
                                for k, v in pairs(value) do
                                    local ktype = type(k)

                                    if (ktype == "userdata" or ktype == "table" or ktype == "function") then
                                        local keyName = debugger_valueToString(k)
                                        if (keyName == key) then
                                            value = v
                                            break
                                        end
                                    end
                                end
                            end
                            str = ""
                            if (i == keyLength) then
                                return #keys, value
                            else
                                return debugger_getVarByKeys(value, keys, i + 1)
                            end
                        else
                            str = str .. '["' .. key .. '"]'
                        end
                    else
                        str = str .. '["' .. key .. '"]'
                    end
                else
                    str = str .. "[" .. key .. "]"
                end
            end
        end
    end

    local v = debugger_getValueByScript(value, str)

    return #keys, v
end
--[[
    @desc: 查找c# 值
    author:k0204
    time:2018-04-07 21:32:31
    return
]]
local function debugger_getCSharpValue(value, searchIndex, keys)
    local key = keys[searchIndex]
    local val = LuaDebugTool.getCSharpValue(value, key)
    if (val) then
        --1最后一个 直接返回
        if (searchIndex == #keys) then
            return #keys, val
        else
            --2再次获得 如果没有找到那么 进行lua 层面查找
            local vindex, val1 = debugger_getCSharpValue(val, searchIndex + 1, keys)
            if (not val1) then
                --组建新的keys
                local tempKeys = {}
                for i = vindex, #keys do
                    table.insert(tempKeys, keys[i])
                end
                local vindx, val1 = debugger_searchVarByKeys(value, searckKeys, 1)
                return vindx, val1
            else
                return vindex, val1
            end
        end
    else
        --3最终这里返回  所以2 中 没有当val1 不为空的处理
        return searchIndex, val
    end
end
local function debugger_searchVarByKeys(value, keys, searckKeys)
    local index, val = debugger_getVarByKeys(value, searckKeys, 1)

    if (not LuaDebugTool or  not LuaDebugTool.getCSharpValue or type(LuaDebugTool.getCSharpValue) ~= "function") then
        return index, val
    end
    if (val) then
        if (index == #keys) then
            return index, val
        else
            local searchStr = ""
            --进行c# 值查找
            local keysLength = #keys
            local searchIndex = index + 1
            local sindex, val = debugger_getCSharpValue(val, searchIndex, keys)
            return sindex, val
        end
    else
        --进行递减
        local tempKeys = {}
        for i = 1, #searckKeys - 1 do
            table.insert(tempKeys, keys[i])
        end
        if (#tempKeys == 0) then
            return #keys, nil
        end
        return debugger_searchVarByKeys(value, keys, tempKeys)
    end
end
--[[
    @desc: 获取metatable 信息
    author:k0204
    time:2018-04-06 20:27:12
    return
]]
local function debugger_getmetatable(value, metatable, vinfos, server, variablesReference, debugSpeedIndex, metatables)
    for i, mtable in ipairs(metatables) do
        if (metatable == mtable) then
            return vinfos
        end
    end
    table.insert(metatables, metatable)
    for k, v in pairs(metatable) do
        local val = nil
        if (type(k) == "string") then
            xpcall(
                function()
                    val = value[k]
                end,
                function(error)
                    val = nil
                end
            )
            if (val == nil) then
                xpcall(
                    function()
                        if (string.find(k, "__")) then
                            val = v
                        end
                    end,
                    function(error)
                        val = nil
                    end
                )
            end
        end
        if (val) then
            local vinfo = debugger_setVarInfo(k, val)
            table.insert(vinfos, vinfo)
            if (#vinfos > 10) then
                debugger_sendMsg(
                    server,
                    LuaDebugger.event.C2S_ReqVar,
                    {
                        variablesReference = variablesReference,
                        debugSpeedIndex = debugSpeedIndex,
                        vars = vinfos,
                        isComplete = 0
                    }
                )
                vinfos = {}
            end
        end
    end
    local m = getmetatable(metatable)
    if (m) then
        return debugger_getmetatable(value, m, vinfos, server, variablesReference, debugSpeedIndex, metatables)
    else
        return vinfos
    end
end
local function debugger_sendTableField(luatable, vinfos, server, variablesReference, debugSpeedIndex, valueType)
    if (valueType == "userdata") then
        if (tolua and tolua.getpeer) then
            luatable = tolua.getpeer(luatable)
        else
            return vinfos
        end
    end
    if (luatable == nil) then
        return vinfos
    end
    for k, v in pairs(luatable) do
        local vinfo = debugger_setVarInfo(k, v)
        table.insert(vinfos, vinfo)
        if (#vinfos > 10) then
            debugger_sendMsg(
                server,
                LuaDebugger.event.C2S_ReqVar,
                {
                    variablesReference = variablesReference,
                    debugSpeedIndex = debugSpeedIndex,
                    vars = vinfos,
                    isComplete = 0
                }
            )
            vinfos = {}
        end
    end

    return vinfos
end
local function debugger_sendTableValues(value, server, variablesReference, debugSpeedIndex)
    local vinfos = {}
    local luatable = {}
    local valueType = type(value)
    local userDataInfos = {}
    local m = nil

    if (valueType == "userdata") then
        m = getmetatable(value)
       
        vinfos = debugger_sendTableField(value, vinfos, server, variablesReference, debugSpeedIndex, valueType)
      
        if (LuaDebugTool) then
            local varInfos = debugger_GeVarInfoBytUserData(server, value, variablesReference, debugSpeedIndex)

            for i, v in ipairs(varInfos) do
                if (v.valueType == "System.Byte[]" and value[v.name] and type(value[v.name]) == "string") then
                    local valueInfo = {
                        name = v.name,
                        valueType = "string",
                        valueStr = ZZBase64.encode(value[v.name])
                    }
                    table.insert(vinfos, valueInfo)
                else
                    table.insert(vinfos, v)
                end
                if (#vinfos > 10) then
                    debugger_sendMsg(
                        server,
                        LuaDebugger.event.C2S_ReqVar,
                        {
                            variablesReference = variablesReference,
                            debugSpeedIndex = debugSpeedIndex,
                            vars = vinfos,
                            isComplete = 0
                        }
                    )
                    vinfos = {}
                end
            end
           
        end
    else
        m = getmetatable(value)
        vinfos = debugger_sendTableField(value, vinfos, server, variablesReference, debugSpeedIndex, valueType)
    end

    if (m) then
        vinfos = debugger_getmetatable(value, m, vinfos, server, variablesReference, debugSpeedIndex, {})
    end
    debugger_sendMsg(
        server,
        LuaDebugger.event.C2S_ReqVar,
        {
            variablesReference = variablesReference,
            debugSpeedIndex = debugSpeedIndex,
            vars = vinfos,
            isComplete = 1
        }
    )
end

--获取lua 变量的方法
local function debugger_getBreakVar(body, server)
    local variablesReference = body.variablesReference
    local debugSpeedIndex = body.debugSpeedIndex
    local vinfos = {}
    local function exe()
        local frameId = body.frameId
        local type_ = body.type
        local keys = body.keys
        --找到对应的var
        local vars = nil
        if (type_ == 1) then
            vars = LuaDebugger.currentDebuggerData.vars[frameId + 1]
            vars = vars.locals
        elseif (type_ == 2) then
            vars = LuaDebugger.currentDebuggerData.vars[frameId + 1]
            vars = vars.ups
        elseif (type_ == 3) then
            vars = _G
        end
        if (#keys == 0) then
            debugger_sendTableValues(vars, server, variablesReference, debugSpeedIndex)
            return
        end
        local index, value = debugger_searchVarByKeys(vars, keys, keys)
        if (value) then
            local valueType = type(value)
            if (valueType == "table" or valueType == "userdata") then

                debugger_sendTableValues(value, server, variablesReference, debugSpeedIndex)
            else
                if (valueType == "function") then
                    value = tostring(value)
                end
                debugger_sendMsg(
                    server,
                    LuaDebugger.event.C2S_ReqVar,
                    {
                        variablesReference = variablesReference,
                        debugSpeedIndex = debugSpeedIndex,
                        vars = ZZBase64.encode(value),
                        isComplete = 1,
                        varType = valueType
                    }
                )
            end
        else
            debugger_sendMsg(
                server,
                LuaDebugger.event.C2S_ReqVar,
                {
                    variablesReference = variablesReference,
                    debugSpeedIndex = debugSpeedIndex,
                    vars = {},
                    isComplete = 1,
                    varType = "nil"
                }
            )
        end
    end
    xpcall(
        exe,
        function(error)
            -- print("获取变量错误 错误消息-----------------")
            -- print(error)
            -- print(debug.traceback("", 2))
            debugger_sendMsg(
                server,
                LuaDebugger.event.C2S_ReqVar,
                {
                    variablesReference = variablesReference,
                    debugSpeedIndex = debugSpeedIndex,
                    vars = {
                        {
                            name = "error",
                            valueType = "string",
                            valueStr = ZZBase64.encode("无法获取属性值:" .. error .. "->" .. debug.traceback("", 2)),
                            isValue = false
                        }
                    },
                    isComplete = 1
                }
            )
        end
    )
end
local function ResetDebugInfo()
    LuaDebugger.Run = false
    LuaDebugger.StepIn = false
    LuaDebugger.StepNext = false
    LuaDebugger.StepOut = false
    LuaDebugger.StepNextLevel = 0
end
local function debugger_loop(server)
    server = debug_server
    --命令
    local command
    local eval_env = {}
    local arg
    while true do
        local line, status = server:receive()
        if (status == "closed") then
        if(LuaDebugger.isLaunch) then
            os.exit()
        else
            debug.sethook()
            coroutine.yield()
        end
        end
        if (line) then
            local netData = json.decode(line)
            local event = netData.event
            local body = netData.data
            if (event == LuaDebugger.event.S2C_DebugClose) then
            if(LuaDebugger.isLaunch) then
                os.exit()
            else
                debug.sethook()
                coroutine.yield()
            end
               
            elseif event == LuaDebugger.event.S2C_SetBreakPoints then
                --设置断点信息
                local function setB()
                    debugger_setBreak(body)
                end
                xpcall(
                    setB,
                    function(error)
                        print(error)
                    end
                )
            elseif event == LuaDebugger.event.S2C_RUN then --开始运行
                LuaDebugger.runTimeType = body.runTimeType
                LuaDebugger.isProntToConsole = body.isProntToConsole
                LuaDebugger.isFoxGloryProject = body.isFoxGloryProject
                LuaDebugger.isLaunch = body.isLaunch
                ResetDebugInfo()
                LuaDebugger.Run = true
                local data = coroutine.yield()
                LuaDebugger.serVarLevel = 4
                LuaDebugger.currentDebuggerData = data
                debugger_sendMsg(
                    server,
                    data.event,
                    {
                        stack = data.stack
                    }
                )
            elseif event == LuaDebugger.event.S2C_ReqVar then -- 获取变量信息
                --请求数据信息
                debugger_getBreakVar(body, server)
            elseif event == LuaDebugger.event.S2C_NextRequest then -- 设置单步跳过
                ResetDebugInfo()
                LuaDebugger.StepNext = true
                LuaDebugger.StepNextLevel = 0
                --设置当前文件名和当前行数
                local data = coroutine.yield()
                LuaDebugger.serVarLevel = 4
                --重置调试信息
                LuaDebugger.currentDebuggerData = data
                debugger_sendMsg(
                    server,
                    data.event,
                    {
                        stack = data.stack
                    }
                )
            elseif (event == LuaDebugger.event.S2C_StepInRequest) then --单步跳入
                --单步跳入
                ResetDebugInfo()
                LuaDebugger.StepIn = true

                local data = coroutine.yield()
                LuaDebugger.serVarLevel = 4
                --重置调试信息
                LuaDebugger.currentDebuggerData = data
                debugger_sendMsg(
                    server,
                    data.event,
                    {
                        stack = data.stack,
                        eventType = data.eventType
                    }
                )
            elseif (event == LuaDebugger.event.S2C_StepOutRequest) then
                --单步跳出
                ResetDebugInfo()
                LuaDebugger.StepOut = true
                local data = coroutine.yield()
                LuaDebugger.serVarLevel = 4
                --重置调试信息
                LuaDebugger.currentDebuggerData = data
                debugger_sendMsg(
                    server,
                    data.event,
                    {
                        stack = data.stack,
                        eventType = data.eventType
                    }
                )
            elseif event == LuaDebugger.event.S2C_LoadLuaScript then
                LuaDebugger.loadScriptBody = body
                LuaDebugger.isLoadLuaScript = true
                local data = coroutine.yield()
                debugger_sendMsg(
                    server,
                    LuaDebugger.event.C2S_LoadLuaScript,
                    LuaDebugger.loadScriptBody
                )
            elseif event == LuaDebugger.event.S2C_SerVar then
                LuaDebugger.isSetVar = true
                LuaDebugger.setVarBody = body
                local data = coroutine.yield()
                debugger_sendMsg(
                    server,
                    LuaDebugger.event.C2S_SerVar,
                    {
                        stack = data,
                        eventType = data.eventType
                    }
				)
			elseif event == LuaDebugger.event.S2C_ReLoadFile then
                LuaDebugger.isReLoadFile = true
                LuaDebugger.reLoadFileBody = body
                local data = coroutine.yield()
                debugger_sendMsg(
                    server,
                    LuaDebugger.event.C2S_ReLoadFile,
                    {
                        stack = data,
                        eventType = data.eventType
                    }
                )
            end
        end
    end
end
coro_debugger = coroutine.create(debugger_loop)
debug_hook = function(event, line)

    if(not LuaDebugger.isHook) then
        return
    end
 
    if(LuaDebugger.Run) then
        if(event == "line") then
            local isCheck = false
            for k, breakInfo in pairs(LuaDebugger.breakInfos) do

                for bk, linesInfo in pairs(breakInfo) do

                    if(linesInfo.lines and linesInfo.lines[line]) then
                        isCheck = true
                        break
                    end
                end
                if(isCheck) then
						break
				end
            end

            if(not isCheck) then
                return
            end
        else
            LuaDebugger.currentFileName = nil
            LuaDebugger.currentTempFunc = nil
            return
        end
    end
    --跳出
    if (LuaDebugger.StepOut) then
        if (event == "line" or event == "call") then
            return
        end
        local tempFun = getinfo(2, "f").func

        if (LuaDebugger.currentDebuggerData.funcsLength == 1) then
            ResetDebugInfo()
            LuaDebugger.Run = true
        else
            if (LuaDebugger.currentDebuggerData.funcs[2] == tempFun) then
                local data = debugger_stackInfo(3, LuaDebugger.event.C2S_StepInResponse)
				--挂起等待调试器作出反应    
				          
                _resume(coro_debugger, data)
                checkSetVar()
            end
        end
        return
    end
    -- debugger_dump(LuaDebugger,"LuaDebugger")
    -- print(LuaDebugger.StepNextLevel,"LuaDebugger.StepNextLevel")
    local file = nil
    if (event == "call") then
        -- end
        -- if(not LuaDebugger.StepOut) then
        if (not LuaDebugger.Run) then
            LuaDebugger.StepNextLevel = LuaDebugger.StepNextLevel + 1
        end
        -- print("stepIn",LuaDebugger.StepNextLevel)

        local stepInfo = getinfo(2, "S")
        local source = stepInfo.source
        if (source:find(LuaDebugger.DebugLuaFie) or source == "=[C]") then
            return
        end

        file = getSource(source)
        LuaDebugger.currentFileName = file
    elseif (event == "return" or event == "tail return") then
        -- end
        -- if(not LuaDebugger.StepOut) then

        if (not LuaDebugger.Run) then
            LuaDebugger.StepNextLevel = LuaDebugger.StepNextLevel - 1
        end

        LuaDebugger.currentFileName = nil
    elseif (event == "line") then
        --@region 判断命中断点
        --判断命中断点
        --判断命中断点
        --判断命中断点
        --判断命中断点
        local isHit = false
        local stepInfo = nil
        if (not LuaDebugger.currentFileName) then
            stepInfo = getinfo(2, "S")
            local source = stepInfo.source
            if (source == "=[C]" or source:find(LuaDebugger.DebugLuaFie)) then
                return
            end
            file = getSource(source)
            LuaDebugger.currentFileName = file
        end
        file = LuaDebugger.currentFileName
        
        --判断断点
        local breakInfo = LuaDebugger.breakInfos[file]
        local breakData = nil
      
        if (breakInfo) then
          
            local ischeck = false
            for k, lineInfo in pairs(breakInfo) do
                local lines = lineInfo.lines
                if (lines and lines[line]) then
                    ischeck = true
                    break
                end
            end
         
            if (ischeck) then
                --并且在断点中
                -- local info = stepInfo
                -- if (not info) then
                --     print("info ---------------")
                --     info = getinfo(2)
                -- end
                local hitPathNames = splitFilePath(LuaDebugger.currentLineFile)
             
                local hitCounts = {}
                local debugHitCounts = nil

                for k, lineInfo in pairs(breakInfo) do
              
                    local lines = lineInfo.lines
                    local pathNames = lineInfo.pathNames
                    debugHitCounts = lineInfo.hitCounts
                    if (lines and lines[line]) then
                        breakData = lines[line]
                        --判断路径
                        hitCounts[k] = 0
                        local hitPathNamesCount = #hitPathNames
                        
                        local pathNamesCount = #pathNames
                        local checkCount = 0;
                     
                        while (true) do
                           
                            if (pathNames[pathNamesCount] ~= hitPathNames[hitPathNamesCount]) then
                                break
                            else
                                hitCounts[k] = hitCounts[k] + 1
                            end
                            pathNamesCount = pathNamesCount - 1
                            hitPathNamesCount = hitPathNamesCount - 1
                            checkCount = checkCount+1
                           
                            if (pathNamesCount <= 0 or hitPathNamesCount <= 0) then
                                break
                            end
                        end
                        if(checkCount>0) then
                            break;
                        end
                        if(checkCount==0) then
                            breakData = nil
                            -- break;
                        end
                    else
                        breakData = nil
                    end
                end
                if (breakData) then
                    local hitFieName = ""
                    local maxCount = 0
                    for k, v in pairs(hitCounts) do
                        if (v > maxCount) then
                            maxCount = v
                            hitFieName = k
                        end
                    end
                    local hitPathNamesLength = #hitPathNames
                    if (hitPathNamesLength == 1 or (hitPathNamesLength > 1 and maxCount > 1)) then
                        if (hitFieName ~= "") then
                            local hitCount = breakData.hitCondition
                            local clientHitCount = debugHitCounts[breakData.line]
                            clientHitCount = clientHitCount + 1
                            debugHitCounts[breakData.line] = clientHitCount

                            if (clientHitCount >= hitCount) then
                                isHit = true
                            end
                        end
                    end
                end
            end
        end
        --@endregion
        if (LuaDebugger.StepIn) then
            local data = debugger_stackInfo(3, LuaDebugger.event.C2S_NextResponse)
            --挂起等待调试器作出反应
            if (data) then
                LuaDebugger.currentTempFunc = data.funcs[1]

                _resume(coro_debugger, data)
                checkSetVar()
                return
            end
        end
        if (LuaDebugger.StepNext) then
            if (LuaDebugger.StepNextLevel <= 0) then
                local data = debugger_stackInfo(3, LuaDebugger.event.C2S_NextResponse)
                -- 挂起等待调试器作出反应
                if (data) then
					LuaDebugger.currentTempFunc = data.funcs[1]   
					                 
                    _resume(coro_debugger, data)
                    checkSetVar()
                    return
                end
            end
        end
        if (isHit) then
            local data = debugger_stackInfo(3, LuaDebugger.event.C2S_HITBreakPoint)
            if (breakData and breakData.condition) then
                debugger_conditionStr(
                    breakData.condition,
                    data.vars,
                    function()
                        _resume(coro_debugger, data)
                        checkSetVar()
                    end
                )
            else
                --挂起等待调试器作出反应
                _resume(coro_debugger, data)
                checkSetVar()
            end
        end
    end
end
debugger_xpcall = function()
    --调用 coro_debugger 并传入 参数
    local data = debugger_stackInfo(4, LuaDebugger.event.C2S_HITBreakPoint)
    if(data.stack and data.stack[1]) then
        data.stack[1].isXpCall = true    
    end
    --挂起等待调试器作出反应
    _resume(coro_debugger, data)
    checkSetVar()
end
--调试开始
local function start()
    local fullName, dirName, fileName = debugger_getFilePathInfo(getinfo(1).source)
    LuaDebugger.DebugLuaFie = fileName
    local socket = createSocket()
    print(controller_host)
    print(controller_port)

    local server = socket.connect(controller_host, controller_port)
    debug_server = server
    if server then
        --创建breakInfo socket
        socket = createSocket()
        breakInfoSocket = socket.connect(controller_host, controller_port)
        if (breakInfoSocket) then
            breakInfoSocket:settimeout(0)
            debugger_sendMsg(
                breakInfoSocket,
                LuaDebugger.event.C2S_SetSocketName,
                {
                    name = "breakPointSocket"
                }
            )
            debugger_sendMsg(
                server,
                LuaDebugger.event.C2S_SetSocketName,
                {
                    name = "mainSocket",
                    version = LuaDebugger.version
                }
            )
            xpcall(
                function()
                    debug.sethook(debug_hook, "lrc")
                end,
                function(error)
                    print("error:", error)
                end
            )
            if (jit) then
                if (LuaDebugger.debugLuaType ~= "jit") then
                    print("error======================================================")
                    local msg = "当前luajit版本为: " .. jit.version .. " 请使用LuaDebugjit 进行调试!"

                    print(msg)
                end
            end
            _resume(coro_debugger, server)          
        end
    end
end
function StartDebug(host, port,reLoad)
    if (not host) then
        print("error host nil")
    end
    if (not port) then
        print("error prot nil")
    end
    if (type(host) ~= "string") then
        print("error host not string")
    end
    if (type(port) ~= "number") then
        print("error host not number")
    end
    controller_host = host
    controller_port = port
    xpcall(
        start,
        function(error)
            -- body
            print(error)
        end
    )
    --代码重载
    if(isReLoad) then
        xpcall(function() 
            debugger_reLoadFile = require("luaideReLoadFile")
        end,function() 
            print("左侧luaide按钮->打开luaIde最新调试文件所在文件夹->luaideReLoadFile.lua->拷贝到项目中")
            print("具体使用方式请看luaideReLoadFile中文件注释")
            debugger_reLoadFile = function() print("未实现代码重载") end
        end)
    end
    local tempFun = function() end
    return debugger_receiveDebugBreakInfo, tempFun
end

--base64

local string = string

ZZBase64.__code = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/',
};
ZZBase64.__decode = {}
for k,v in pairs(ZZBase64.__code) do
    ZZBase64.__decode[string.byte(v,1)] = k - 1
end

function ZZBase64.encode(text)
    local len = string.len(text)
    local left = len % 3
    len = len - left
    local res = {}
    local index  = 1
    for i = 1, len, 3 do
        local a = string.byte(text, i )
        local b = string.byte(text, i + 1)
        local c = string.byte(text, i + 2)
        -- num = a<<16 + b<<8 + c
        local num = a * 65536 + b * 256 + c
        for j = 1, 4 do
            --tmp = num >> ((4 -j) * 6)
            local tmp = math.floor(num / (2 ^ ((4-j) * 6)))
            --curPos = tmp&0x3f
            local curPos = tmp % 64 + 1
            res[index] = ZZBase64.__code[curPos]
            index = index + 1
        end
    end

    if left == 1 then
        ZZBase64.__left1(res, index, text, len)
    elseif left == 2 then
        ZZBase64.__left2(res, index, text, len)
    end
    return table.concat(res)
end

function ZZBase64.__left2(res, index, text, len)
    local num1 = string.byte(text, len + 1)
    num1 = num1 * 1024 --lshift 10
    local num2 = string.byte(text, len + 2)
    num2 = num2 * 4 --lshift 2
    local num = num1 + num2

    local tmp1 = math.floor(num / 4096) --rShift 12
    local curPos = tmp1 % 64 + 1
    res[index] = ZZBase64.__code[curPos]

    local tmp2 = math.floor(num / 64)
    curPos = tmp2 % 64 + 1
    res[index + 1] = ZZBase64.__code[curPos]

    curPos = num % 64 + 1
    res[index + 2] = ZZBase64.__code[curPos]

    res[index + 3] = "="
end

function ZZBase64.__left1(res, index,text, len)
    local num = string.byte(text, len + 1)
    num = num * 16

    local tmp = math.floor(num / 64)
    local curPos = tmp % 64 + 1
    res[index ] = ZZBase64.__code[curPos]

    curPos = num % 64 + 1
    res[index + 1] = ZZBase64.__code[curPos]

    res[index + 2] = "="
    res[index + 3] = "="
end

function ZZBase64.decode(text)
    local len = string.len(text)
    local left = 0
    if string.sub(text, len - 1) == "==" then
        left = 2
        len = len - 4
    elseif string.sub(text, len) == "=" then
        left = 1
        len = len - 4
    end

    local res = {}
    local index = 1
    local decode = ZZBase64.__decode
    for i =1, len, 4 do
        local a = decode[string.byte(text,i    )] 
        local b = decode[string.byte(text,i + 1)] 
        local c = decode[string.byte(text,i + 2)] 
        local d = decode[string.byte(text,i + 3)]

        --num = a<<18 + b<<12 + c<<6 + d
        local num = a * 262144 + b * 4096 + c * 64 + d

        local e = string.char(num % 256)
        num = math.floor(num / 256)
        local f = string.char(num % 256)
        num = math.floor(num / 256)
        res[index ] = string.char(num % 256)
        res[index + 1] = f
        res[index + 2] = e
        index = index + 3
    end

    if left == 1 then
        ZZBase64.__decodeLeft1(res, index, text, len)
    elseif left == 2 then
        ZZBase64.__decodeLeft2(res, index, text, len)
    end
    return table.concat(res)
end

function ZZBase64.__decodeLeft1(res, index, text, len)
    local decode = ZZBase64.__decode
    local a = decode[string.byte(text, len + 1)]
    local b = decode[string.byte(text, len + 2)]
    local c = decode[string.byte(text, len + 3)]
    local num = a * 4096 + b * 64 + c

    local num1 = math.floor(num / 1024) % 256
    local num2 = math.floor(num / 4) % 256
    res[index] = string.char(num1)
    res[index + 1] = string.char(num2)
end

function ZZBase64.__decodeLeft2(res, index, text, len)
    local decode = ZZBase64.__decode
    local a = decode[string.byte(text, len + 1)]
    local b = decode[string.byte(text, len + 2)]
    local num = a * 64 + b
    num = math.floor(num / 16)
    res[index] = string.char(num)
end




return StartDebug
