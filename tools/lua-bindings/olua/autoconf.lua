local clang = require "clang"

local M = {}

function M:parse(path)
    self.module = dofile(path)
    self.namespace = {}
    self.classConf = {}
    self.classes = {}
    self.typeref = {}

    self._fileLines = {}
    self._file = io.open(self.module.PARSER.BUILD .. '/' .. self.module.NAME .. '.lua', 'w')

    local headerPath = self.module.PARSER.BUILD .. '/autoconf.h'
    local header = io.open(headerPath, 'w')
    header:write('#ifndef __AUTOCONF_H__\n')
    header:write('#define __AUTOCONF_H__\n')
    header:write(string.format('#include "%s"\n', "gltypes.h"))
    for _, v in ipairs(self.module.PARSER.PATH) do
        header:write(string.format('#include "%s"\n', v))
    end
    header:write('#endif')
    header:close()

    local index = clang.createIndex(false, true)
    local args = self.module.PARSER.ARGS
    args[#args + 1] = '-I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1'
    args[#args + 1] = '-I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include'
    args[#args + 1] = '-Iheaders'
    args[#args + 1] = '-x'
    args[#args + 1] = 'c++'
    args[#args + 1] = '-std=c++11'

    for i, c in ipairs(self.module.CLASSES) do
        assert(not c.INDEX)
        c.INDEX = i
        self.classConf[c.NAME] = c
    end

    local tu = index:parse(headerPath, args)
    self:visit(tu:cursor())
    table.sort(self.classes, function (a, b)
        return a.CONF.INDEX < b.CONF.INDEX
    end)

    self:writeLine('local cls')
    self:writeLine('local M = {}')
    self:writeHeader()
    -- self:writeTypedef()
    self:writeClass()
    self:writeLine('return M')
end

function M:tableToKey(arr)
    local t = {}
    for _, v in ipairs(arr or {}) do
        t[v] = true
    end
    return t
end

function M:write(fmt, ...)
    self._file:write(string.format(fmt, ...))
end

function M:writeLine(fmt, ...)
    self:write(fmt, ...)
    self._file:write('\n')
end

function M:writeRaw(str)
    self._file:write(str)
end

function M:writeHeader()
    self:writeLine('M.NAME = "' .. self.module.NAME .. '"')
    self:writeLine('M.HEADER_PATH = "' .. self.module.HEADER_PATH .. '"')
    self:writeLine('M.SOURCE_PATH = "' .. self.module.SOURCE_PATH .. '"')
    self:writeLine('M.INCLUDES = [[')
    self:write(self.module.INCLUDES)
    self:writeLine(']]')
    if self.module.CHUNK then
        self:writeLine('M.CHUNK = [[')
        self:writeRaw(self.module.CHUNK)
        self:writeLine(']]')
    end
    self:writeLine('')
end

function M:writeTypedef()
    local classes = {}
    local enums = {}
    for _, cls in ipairs(self.classes) do
        if cls.KIND == 'Enum' then
            enums[#enums + 1] = cls.CPPCLS
        elseif cls.KIND == 'Class' then
            classes[#classes + 1] = cls.CPPCLS .. ' *'
        end
    end
    table.sort(classes)
    table.sort(enums)
    classes = table.concat(classes, '\n')
    enums = table.concat(enums, '\n')
    local LUACLS = self.module.LUACLS
    self:writeLine(format_snippet([==[
        REG_TYPE {
            TYPENAME = [[
                ${classes}
            ]],
            CONV_FUNC = "olua_$$_cppobj",
            LUACLS = ${LUACLS},
        }
    ]==]))
    self:writeLine('')
end

function M:writeClass()
    local dict = {}
    for _, cls in ipairs(self.classes) do
        dict[cls.CPPCLS] = cls
    end
    for cls in pairs(self.classConf) do
        if not dict[cls] then
            error("class '" .. cls .. "' not found")
        end
    end
    local function shouldExportFunc(supercls, fn)
        if supercls then
            local super = assert(dict[supercls], supercls)
            if super.INST_FUNCS[fn.PROTOTYPE] or super.CONF.EXCLUDE[fn.NAME] then
                return false
            else
                return shouldExportFunc(super.SUPERCLS, fn)
            end
        else
            return true
        end
    end
    self:writeLine('M.CLASSES = {}')
    self:writeLine('')
    for _, cls in ipairs(self.classes) do
        self:writeLine('cls = class(M.CLASSES)')
        self:writeLine('cls.CPPCLS = "' .. cls.CPPCLS .. '"')
        if cls.SUPERCLS then
            self:writeLine('cls.SUPERCLS = "' .. cls.SUPERCLS .. '"')
        end
        if cls.CONF.REG_LUATYPE == false then
            self:writeLine('cls.REG_LUATYPE = false')
        end
        if cls.CONF.CHUNK then
            self:writeLine('cls.CHUNK = [[')
            self:writeRaw(cls.CONF.CHUNK)
            self:writeLine(']]')
        end
        if cls.KIND == 'Enum' then
            self:writeLine('cls.enums [[')
            for _, value in ipairs(cls.ENUMS) do
                self:writeLine('    ' .. value)
            end
            self:writeLine(']]')
        else
            local props = {}
            local filter = {}
            local function tryAddProp(fn)
                if string.find(fn.NAME, '^get') or string.find(fn.NAME, '^is') then
                    local name = string.gsub(fn.NAME, '^%l+', '')
                    name = string.gsub(name, '^%u+', function (str)
                        if #str > 1 and #str ~= #name then
                            return str:sub(1, #str - 1):lower() .. str:sub(#str)
                        else
                            return str:lower()
                        end
                    end)
                    if not filter[name] then
                        filter[name] = true
                        if fn.ARGS == 0 then
                            props[#props + 1] = name
                        end
                    else
                        for i, v in ipairs(props) do
                            if v == name then
                                table.remove(props, i)
                                break
                            end
                        end
                    end
                end
            end
            assert(cls.KIND == 'Class', cls.KIND)
            self:writeLine('cls.funcs [[')
            for _, fn in ipairs(cls.FUNCS) do
                if shouldExportFunc(cls.SUPERCLS, fn) then
                    self:writeLine('    ' .. fn.FUNC)
                    tryAddProp(fn)
                end
            end
            for _, cb in ipairs(cls.CONF.CALLBACK) do
                if #cb.FUNCS == 1 and (string.match(cb.FUNCS[1], '%(%) *$')
                    or (string.match(cb.FUNCS[1], '%( *void *%) *$'))) then
                    tryAddProp({
                        NAME = cb.NAME,
                        ARGS = 0,
                    })
                end
            end
            self:writeLine(']]')
            for _, fn in ipairs(cls.VARS) do
                self:writeLine("cls.var('%s', [[%s]])", fn.NAME, fn.SNIPPET)
            end
            self:writeConfEnum(cls)
            self:writeConfFunc(cls)
            self:writeConfVar(cls)
            self:writeConfProp(cls)
            self:writeConfCallback(cls)
            self:writeConfBlock(cls)
            self:writeConfInject(cls)
            if #props > 0 then
                self:writeLine('cls.props [[')
                for _, v in ipairs(props) do
                    self:writeLine('    ' .. v)
                end
                self:writeLine(']]')
            end
        end
        self:writeLine('')
    end
end

function M:writeConfEnum(cls)
    for _, e in ipairs(cls.CONF.ENUM) do
        self:writeLine("cls.enum('%s', '%s')", e.NAME, e.VALUE)
    end
end

function M:writeConfFunc(cls)
    for _, fn in ipairs(cls.CONF.FUNC) do
        self:writeLine("cls.func('%s', [[%s]])", fn.FUNC, fn.SNIPPET)
    end
end

function M:writeConfVar(cls)
    for _, fn in ipairs(cls.CONF.VAR) do
        self:writeLine("cls.var('%s', [[%s]])", fn.NAME, fn.SNIPPET)
    end
end

function M:writeConfProp(cls)
    for _, p in ipairs(cls.CONF.PROP) do
        if string.find(p.GET, '{') then
            if p.SET then
                self:writeLine("cls.prop('%s', [[\n%s]], [[\n%s]])", p.NAME, p.GET, p.SET)
            else
                self:writeLine("cls.prop('%s', [[\n%s]])", p.NAME, p.GET)
            end
        else
            if p.SET then
                self:writeLine("cls.prop('%s', '%s', '%s')", p.NAME, p.GET, p.SET)
            else
                self:writeLine("cls.prop('%s', '%s')", p.NAME, p.GET)
            end
        end
    end
end

function M:writeConfCallback(cls)
    for _, v in ipairs(cls.CONF.CALLBACK) do
        self:writeLine('cls.callback {')
        self:writeLine('    FUNCS =  {')
        for _, fn in ipairs(v.FUNCS) do
            self:writeLine("        '%s',", fn)
        end
        assert(v.TAG_MAKER, 'no tag maker')
        assert(v.TAG_MODE, 'no tag mode')
        self:writeLine('    },')
        if type(v.TAG_MAKER) == 'string' then
            self:writeLine("    TAG_MAKER = '%s',", v.TAG_MAKER)
        else
            self:writeLine("    TAG_MAKER = {'%s'},", table.concat(v.TAG_MAKER, "', '"))
        end
        self:writeLine("    TAG_MODE = '%s',", v.TAG_MODE)
        if v.TAG_STORE then
            self:writeLine('    TAG_STORE = %s,', v.TAG_STORE)
        end
        if v.INIT_FUNC then
            self:writeLine("    INIT_FUNC = '%s',", v.INIT_FUNC)
        end
        self:writeLine("    CALLONCE = %s,", v.CALLONCE == true)
        self:writeLine("    REMOVE = %s,", v.REMOVE == true)
        self:writeLine('}')
    end
end

function M:writeConfBlock(cls)
    if cls.CONF.BLOCK then
        self:writeLine(cls.CONF.BLOCK)
    end
end

function M:writeConfInject(cls)
    for _, v in ipairs(cls.CONF.INJECT) do
        if type(v.NAMES) == 'string' then
            self:writeLine("cls.inject('%s', {", v.NAMES)
        else
            self:writeLine("cls.inject({'%s'}, {", table.concat(v.NAMES, "', '"))
        end
        if v.CODES.BEFORE then
            self:writeLine('    BEFORE = [[\n%s]],', v.CODES.BEFORE)
        end
        if v.CODES.AFTER then
            self:writeLine('    AFTER = [[\n%s]],', v.CODES.AFTER)
        end
        if v.CODES.CALLBACK_BEFORE then
            self:writeLine('    CALLBACK_BEFORE = [[\n%s]],', v.CODES.CALLBACK_BEFORE)
        end
        if v.CODES.CALLBACK_AFTER then
            self:writeLine('    CALLBACK_AFTER = [[\n%s]],', v.CODES.CALLBACK_AFTER)
        end
        self:writeLine('})')
    end
end

function M:toNamespace()
    return table.concat(self.namespace, '::')
end

function M:toClass(name)
    local ns = self:toNamespace()
    if #ns > 0 then
        return ns .. '::' .. name
    else
        return name
    end
end

function M:pushNamespace(ns)
    self.namespace[#self.namespace + 1] = ns
end

function M:popNamespace(ns)
    self.namespace[#self.namespace] = nil
end

function M:shouldExport(name)
    return self.classConf[self:toClass(name)]
end

function M:loadFile(path)
    if self._fileLines.path ~= path then
        self._fileLines = {}
        self._fileLines.path = path
        local f = io.open(path)
        for l in f:lines() do
            self._fileLines[#self._fileLines + 1] = l
        end
        f:close()
    end
    return self._fileLines
end

function M:createClass()
    local cls = {}
    self.classes[#self.classes + 1] = cls
    return cls
end

function M:trimClassname(name)
    name = string.gsub(name, '^class *', '')
    name = string.gsub(name, '^struct *', '')
    name = string.gsub(name, '^enum *', '')
    return name
end

function M:visitEnum(cur)
    local name = cur:name()
    local cls = self:createClass()
    local cppcls = self:toClass(name)
    local conf = self.classConf[cppcls]
    cls.CONF = conf
    cls.CPPCLS = cppcls
    cls.ENUMS = {}
    cls.KIND = 'Enum'
    for _, c in ipairs(cur:children()) do
        local kind = c:kind()
        assert(kind == 'EnumConstantDecl', kind)
        cls.ENUMS[#cls.ENUMS + 1] = c:name()
    end
end

local typeMap = {
    UInt = 'unsigned int',
    Int = 'int',
    Float = 'float',
    Void = 'void',
    Bool = 'bool',
    Double = 'double',
    Char_S = 'char',
    UChar = 'unsigned char'
}

function M:parseType(cur, children)
    local typename = ''
    for _, v in ipairs(children) do
        local kind = v:kind()
        if kind == 'NamespaceRef' then
            typename = v:name() .. '::'
        elseif kind == 'TypeRef' then
            typename = typename .. v:name()
            typename = self.typeref[typename] or typename
            break
        elseif kind ~= 'CXXOverrideAttr' then
            break
        end
    end
    typename = self:trimClassname(typename)

    local name = cur:name()
    if #typename > 0 then
        if name == 'Pointer' then
            return typename .. ' *'
        else
            return typename
        end
    else
        if name == 'Pointer' then
            name = cur:canonical():name()
            typename = assert(typeMap[name], name)
            return typename .. ' *'
        end
        return typeMap[name] or name
    end
end

function M:shouldExcludeType(cur, children)
    local type = self:parseType(cur, children)
    return self.module.EXCLUDE_TYPE[type]
end

function M:visitCXXMethod(cur)
    if cur:access() ~= 'public' and cur:kind() ~= 'FunctionDecl' then
        return
    end

    local prototype
    local path, startLine, startCol, endLine, endCol = cur:location()
    local lines = self:loadFile(path)
    for i = startLine, endLine do
        if i == startLine and i == endLine then
            prototype = lines[i]:sub(startCol, endCol)
        elseif i == startLine then
            prototype = lines[i]:sub(startCol)
        elseif i == endLine  then
            prototype = prototype .. lines[i]:sub(1, endCol)
        else
            prototype = prototype .. lines[i]
        end
    end

    local children = cur:children()
    if #children > 0 and children[1]:kind() == 'UnexposedAttr' then
        -- print('[ignore] ' .. prototype)
        return
    end

    local resultType = cur:resultType()
    -- print(prototype)
    if self:shouldExcludeType(resultType, cur:children()) then
        return
    end
    for _, arg in ipairs(cur:arguments()) do
        if self:shouldExcludeType(arg:type(), arg:children()) then
            return
        end
    end

    if not string.find(prototype, cur:name() .. ' *%(') then
        local arr = {}
        if cur:isStatic() then
            arr[#arr + 1] = 'static '
        end
        arr[#arr + 1] = self:parseType(cur:resultType(), cur:children())
        arr[#arr + 1] = cur:name()
        arr[#arr + 1] = '('
        for i, arg in ipairs(cur:arguments()) do
            local at = self:parseType(arg:type(), arg:children())
            if i > 1 then
                arr[#arr + 1] = ', '
            end
            arr[#arr + 1] = at .. ' ' .. arg:name()
        end
        arr[#arr + 1] = ')'
        prototype = table.concat(arr, '')
    end

    prototype = string.gsub(prototype, ' +', ' ')
    prototype = string.gsub(prototype, 'virtual *', '')
    prototype = string.gsub(prototype, '[^)]*$', '')
    prototype = string.gsub(prototype, '/%*.*%*/', '')
    return prototype
end

function M:visitFieldDecl(cur)
    if cur:access() ~= 'public' then
        return nil
    end

    local prototype
    local path, startLine, startCol, endLine, endCol = cur:location()
    local lines = self:loadFile(path)
    for i = startLine, endLine do
        if i == startLine and i == endLine then
            prototype = lines[i]:sub(startCol, endCol)
        elseif i == startLine then
            prototype = lines[i]:sub(startCol)
        elseif i == endLine  then
            prototype = prototype .. lines[i]:sub(1, endCol)
        else
            prototype = prototype .. lines[i]
        end
    end

    prototype = string.gsub(prototype, ' +', ' ')
    prototype = string.gsub(prototype, '[; ]*$', '')
    return {NAME = cur:name(), SNIPPET = prototype}
end

function M:injectAttr(prototype, fn, attr)
    local t = {}
    local _, e = string.find(prototype, fn)
    t[1] = prototype:sub(1, e + 1)
    for v in string.gmatch(prototype:sub(e + 2), '[^,]+') do
        t[#t + 1] = string.gsub(v, '^ *', '')
    end
    if attr.RET then
        t[1] = attr.RET .. ' ' .. t[1]
    end
    for i = 2, #t do
        local ARGN = 'ARG' .. (i - 1)
        if attr[ARGN] then
            t[i] = attr[ARGN] .. ' ' .. t[i]
        end
    end
    return t[1] .. table.concat(t, ', ', 2)
end

function M:visitClass(cur)
    local name = cur:name()
    local cls = self:createClass()
    local filter = {}
    local cppcls = self:toClass(name)
    local conf = self.classConf[cppcls]
    cls.CPPCLS = cppcls
    cls.CONF = conf
    cls.FUNCS = {}
    cls.VARS = {}
    cls.KIND = 'Class'
    cls.INST_FUNCS = {}
    
    self:pushNamespace(name)
    for _, c in ipairs(cur:children()) do
        local kind = c:kind()
        if kind == 'CXXBaseSpecifier' then
            if not cls.SUPERCLS then
                cls.SUPERCLS = self:trimClassname(c:name())
            end
        elseif kind == 'FunctionDecl' then
            local displayName = c:displayName()
            local fn = c:name()
            local attr = conf.ATTR[fn]
            local func = self:visitCXXMethod(c)
            if func then
                func = 'static ' .. func
                filter[displayName] = true
                if attr then
                    func = self:injectAttr(func, fn, attr)
                end
                if conf.TRIM then
                    func = conf.TRIM(fn, func)
                end
                cls.FUNCS[#cls.FUNCS + 1] = {
                    FUNC = func,
                    NAME = fn,
                    ARGS = #c:arguments(),
                    PROTOTYPE = displayName,
                }
            end
        elseif kind == 'CXXMethod' then
            local displayName = c:displayName()
            local fn = c:name()
            local attr = conf.ATTR[fn]
            if not filter[displayName] and
                not conf.EXCLUDE[fn] and
                not conf.EXCLUDE_PATTERN(fn, displayName) then
                if not c:isStatic() then
                    cls.INST_FUNCS[displayName] = cls.CPPCLS
                end
                local func = self:visitCXXMethod(c)
                if func then
                    filter[displayName] = true
                    if attr then
                        func = self:injectAttr(func, fn, attr)
                    end
                    if conf.TRIM then
                        func = conf.TRIM(fn, func)
                    end
                    cls.FUNCS[#cls.FUNCS + 1] = {
                        FUNC = func,
                        NAME = fn,
                        ARGS = #c:arguments(),
                        PROTOTYPE = displayName,
                    }
                end
            end
        elseif kind == 'EnumDecl' then
            self:visit(c)
        elseif kind == 'FieldDecl' then
            if not conf.EXCLUDE[c:name()] then
                cls.VARS[#cls.VARS + 1] = self:visitFieldDecl(c)
            end
        end
    end
    self:popNamespace()
end

function M:visit(cur)
    local kind = cur:kind()
    local name = cur:name()
    local children = cur:children()
    if kind == 'Namespace' then
        self:pushNamespace(name)
        if self.classConf[self:toNamespace()] then
            self:popNamespace()
            self:visitClass(cur)
        else
            for _, v in ipairs(self.module.NAMESPACES) do
                if self:toNamespace():find(v) then
                    for _, c in ipairs(children) do
                        self:visit(c)
                    end
                    break
                end
            end
            self:popNamespace()
        end
    elseif kind == 'ClassDecl' then
        if self:shouldExport(name) and #children > 0 then
            self:visitClass(cur)
        end
    elseif kind == 'EnumDecl' then
        if self:shouldExport(name) and #children > 0 then
            self:visitEnum(cur)
        end
    elseif kind == 'TypedefDecl' then
        self.typeref[name] = self:toClass(name)
    else
        for _, c in ipairs(children) do
            self:visit(c)
        end
    end
end

function autoconf(path)
    local inst = setmetatable({}, {__index = M})
    inst:parse(path)
end