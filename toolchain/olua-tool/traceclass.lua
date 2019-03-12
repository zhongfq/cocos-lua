local init = false
local function trace(str)
    str = string.gsub(str, 'CC_DLL ', '')
    print("local cls = class(M)")
    for line in string.gmatch(str, '[^\n\r]+') do
        local cls, super = string.match(line, 'class *([^: ]+) *: * public *([^ ,]+)')
        if cls then
            if init then
                print("]])")
                print("")
                print("local cls = class(M)")
            end
            init = true
            print(string.format('cls.CPPCLS = "%s"', cls))
            print(string.format('cls.LUACLS = "%s"', cls))
            print(string.format('cls.SUPERCLS = "%s"', super))
            print("cls.funcs([[")
            goto CONTINUE
        end
        local func = string.match(line, '.+%(.*%)')
        if func then
            print(func)
        end

        ::CONTINUE::
    end
    print("]])")
end

trace [[

]]