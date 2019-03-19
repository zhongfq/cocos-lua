local init = false
local function trace(str)
    str = string.gsub(str, 'CC_DLL ', '')
    str = string.gsub(str, 'CC_GUI_DLL ', '')
    local enum_cls
    print("local cls = class(M)")
    for line in string.gmatch(str, '[^\n\r]+') do
        if string.find(line, '^ *[/**]') or
            string.find(line, '^ *CC_DEPRECATED_ATTRIBUTE') or
            string.find(line, '^ */') or
            string.find(line, '^ *%*') then
            goto CONTINUE
        end
        if enum_cls then
            local s = string.gsub(line, '[{},;]', ' ')
            s = string.gsub(s, '^ *', '')
            s = string.gsub(s, ' *$', '')
            if #s > 0 then
                print('    ' .. s)
            end
            if string.find(line, '}') then
                enum_cls = nil
            end
            goto CONTINUE
        end
        local cls, super = string.match(line, 'enum +class *([^: ]+) *')
        if not cls then
            cls, super = string.match(line, 'class *([^: ]+) *: * public *([^ ,]+)')
        else
            enum_cls = cls
        end
        if not cls then
            cls = string.match(line, 'class *([^: ]+)')
        end
        if cls then
            if init then
                print("]]")
                print("")
                print("local cls = class(M)")
            end
            init = true
            print(string.format('cls.CPPCLS = "%s"', cls))
            print(string.format('cls.LUACLS = "%s"', cls))
            print(string.format('cls.SUPERCLS = "%s"', super))
            print("cls.funcs [[")
            goto CONTINUE
        end
        local func = string.match(line, '.+%(.*%)')
        if func then
            print(func)
        end

        ::CONTINUE::
    end
    print("]]")
end

trace [[
]]