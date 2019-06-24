local clang = require "clang"

do
    local format = string.format

    -- a more forgiving version of string.format, which applies
    -- tostring() to any value with a %s format.
    local function formatx (fmt,...)
        local args = {...}
        local i = 1
        for p in fmt:gmatch('%%.') do
            if p == '%s' and type(args[i]) ~= 'string' then
                args[i] = tostring(args[i])
            end
            i = i + 1
        end
        return format(fmt,unpack(args))
    end

    -- Note this goes further than the original, and will allow these cases:
    -- 1. a single value
    -- 2. a list of values
    getmetatable("").__mod = function(a, b)
        if b == nil then
            return a
        elseif type(b) == "table" then
            return formatx(a,unpack(b))
        else
            return formatx(a,b)
        end
    end
end

do
    local start = os.clock()
    local lastTime = start
    function SECTION(...)
        local now = os.clock()
        print(("[%6.3f/%6.3f]"):format(now-start, now-lastTime), ...)
        lastTime = now
    end
end

SECTION "Start"

---[[
local DBG = function() end
--[=[]]
local DBG = print
--]=]

do
    local cache = setmetatable({}, {__mode="k"})
    function getExtent(file, fromRow, fromCol, toRow, toCol)
        if not file then
            DBG(file, fromRow, fromCol, toRow, toCol)
            return ''
        end
        if toRow - fromRow > 3 then
            return ('%s: %d:%d - %d:%d'):format(file, fromRow, fromCol, toRow, toCol)
        end
        if not cache[file] then
            local f = assert(io.open(file))
            local t, n = {}, 0
            for l in f:lines() do
                n = n + 1
                t[n] = l
            end
            cache[file] = t
        end
        local lines = cache[file]
        if not (lines and lines[fromRow] and lines[toRow]) then
            DBG('!!! Missing lines '..fromRow..'-'..toRow..' in file '..file)
            return ''
        end
        if fromRow == toRow then
            return lines[fromRow]:sub(fromCol, toCol-1)
        else
            local res = {}
            for i=fromRow, toRow do
                if i==fromRow then
                    res[#res+1] = lines[i]:sub(fromCol)
                elseif i==toRow then
                    res[#res+1] = lines[i]:sub(1,toCol-1)
                else
                    res[#res+1] = lines[i]
                end
            end
            return table.concat(res, '\n')
        end
    end
end

function findChildrenByType(cursor, type)
    local children, n = {}, 0
    local function finder(cur)
        for i,c in ipairs(cur:children()) do
            if c and (c:kind() == type) then
                n = n + 1
                children[n] = c
            end
            finder(c)
        end
   end
   finder(cursor)
   return children
end

function translateType(cur, typ)
    if not typ then
        typ = cur:type()
    end

    local typeKind = tostring(typ)
    if typeKind == 'Typedef' or typeKind == 'Record' then
        return typ:declaration():name()
    elseif typeKind == 'Pointer' then
        return translateType(cur, typ:pointee()) .. '*'
    elseif typeKind == 'LValueReference' then
        return translateType(cur, typ:pointee()) .. '&'
    elseif typeKind == 'Unexposed' then
        local def = getExtent(cur:location())
        DBG('!Unexposed!', def)
        return def
    else
        return typeKind
    end
end



SECTION 'Creating index'
local index = clang.createIndex(false, true)

SECTION 'Creating translation unit'
print("### heloo")
---[[
 local tu = assert(index:parse('../../frameworks/cocos2d-x/cocos/ui/UIWidget.h', {
     "-I../..//frameworks/cocos2d-x/cocos",
     "-x",
     "-DCC_DLL=",
     "c++",
    }))
--[=[]]
 local tu = assert(index:load('precompiled.ast'))
--]=]

print("###", tu:cursor())

SECTION "Writing code.xml - raw AST"

local function trim(s)
 local from = s:match"^%s*()"
 local res = from > #s and "" or s:match(".*%S", from)
 return (res:gsub('&', '&amp;'):gsub('<', '&lt;'):gsub('>', '&gt;'):gsub('"', '&quot;'))
end

local xml = assert(io.open('code.xml', 'w'))
local function dumpXML(cur)
    local tag = cur:kind()
    local name = trim(cur:name())
    local attr = ' name="' .. name .. '"'
    local dname = trim(cur:displayName())
    if dname ~= name then
        attr = attr .. ' display="' .. dname .. '"'
    end
    attr = attr ..' text="' .. trim(getExtent(cur:location())) .. '"' 
    local children = cur:children()
    if #children == 0 then
        xml:write('<', tag, attr, ' />\n')
    else
        xml:write('<', tag, attr, ' >\n')
        for _,c in ipairs(children) do
            dumpXML(c)
        end
        xml:write('</',tag,'>\n')
    end
end
dumpXML(tu:cursor())

SECTION "Finished"