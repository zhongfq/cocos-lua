-- parse cmd line args
local PROJECT_NAME = "hello"
local PROJECT_DIR = '~'
local PACKAGE_NAME = 'org.cocos2dx.hello'
local args = {...}

local function printhelp()
    print('create-project:')
    print('    -d    project directory')
    print('    -n    project name')
    print('    -p    package name')
    print('')
    print('    create-project -n codetypes -d ~ -p com.codetypes.cocoslua')
end

if #args == 0 then
    printhelp()
    return
else
    while #args > 0 do
        local c = table.remove(args, 1)
        if c == '-n' then
            PROJECT_NAME = assert(table.remove(args, 1), 'no project name')
        elseif c == '-d' then
            PROJECT_DIR = assert(table.remove(args, 1), 'no project directory')
        elseif c == '-p' then
            PACKAGE_NAME = assert(table.remove(args, 1), 'no package name')
        elseif c == '-h' then
            printhelp()
            return
        end
    end
end

PROJECT_DIR = PROJECT_DIR .. '/' .. PROJECT_NAME

local function execute(fmt, ...)
    os.execute(string.format(fmt, ...))
end

print('create project:', PROJECT_DIR)
execute('cp -a ../../ %s', PROJECT_DIR)
execute('rm -rf %s/.git', PROJECT_DIR)

do -- replace project name
    local function replace(path)
        path = PROJECT_DIR .. '/' .. path
        execute("cat %s | sed 's/cocos-lua/%s/g' > %s.bak", path, PROJECT_NAME, path)
        execute("mv %s.bak %s", path, path)
    end

    replace('CMakeLists.txt')
    replace('runtime-src/Classes/AppDelegate.cpp')
    replace('runtime-src/proj.android/.gitignore')
    replace('runtime-src/proj.android/app/res/values/strings.xml')
    replace('runtime-src/proj.android/settings.gradle')
    replace('runtime-src/proj.ios_mac/.gitignore')
    replace('runtime-src/proj.ios_mac/cocos-lua.xcodeproj/project.pbxproj')
    replace('runtime-src/proj.ios_mac/cocos-lua.xcodeproj/xcshareddata/xcschemes/cocos-lua-desktop.xcscheme')
    replace('runtime-src/proj.ios_mac/cocos-lua.xcodeproj/xcshareddata/xcschemes/cocos-lua-mobile.xcscheme')
    replace('runtime-src/proj.win32/cocos-lua.sln')
end

do -- replace package name
    local function replace(path)
        path = PROJECT_DIR .. '/' .. path
        execute("cat %s | sed 's/org.cocos2dx.hellolua/%s/g' > %s.bak", path, PACKAGE_NAME, path)
        execute("mv %s.bak %s", path, path)
    end
    replace('frameworks/libxgame/src/xgame/xruntime-private.cpp')
    replace('runtime-src/proj.android/app/AndroidManifest.xml')
    replace('runtime-src/proj.android/app/build.gradle')
    replace('runtime-src/proj.android/app/src/org/cocos2dx/hellolua/wxapi/WXEntryActivity.java')
    replace('runtime-src/proj.android/app/src/org/cocos2dx/hellolua/wxapi/WXPayEntryActivity.java')
    replace('runtime-src/proj.android/app/src/org/cocos2dx/hellolua/AppEntry.java')
    replace('runtime-src/proj.android/app/src/org/cocos2dx/hellolua/Application.java')
    replace('runtime-src/proj.ios_mac/cocos-lua.xcodeproj/project.pbxproj')
end

do -- android files
    local PACKAGE_NAME_PATH = string.gsub(PACKAGE_NAME, '%.', '/')
    execute('cp -rf %s/runtime-src/proj.android/app/src/org/cocos2dx/hellolua %s/tmp', PROJECT_DIR, PROJECT_DIR)
    execute('rm -rf %s/runtime-src/proj.android/app/src/org', PROJECT_DIR)
    execute('mkdir -p %s/runtime-src/proj.android/app/src/%s', PROJECT_DIR, PACKAGE_NAME_PATH)
    execute('cp -rf %s/tmp/* %s/runtime-src/proj.android/app/src/%s', PROJECT_DIR, PROJECT_DIR, PACKAGE_NAME_PATH)
    execute('rm -rf %s/tmp', PROJECT_DIR)
end

do
    local function rename(path)
        local newname, newpath
        local dir, name = string.match(path, '(.+/)([^/]+)$')
        dir = dir or ''
        name = name or path
        newname = string.gsub(name, 'cocos%-lua', PROJECT_NAME)
        path = PROJECT_DIR .. '/' .. dir .. name
        newpath = PROJECT_DIR .. '/' .. dir .. newname
        execute('mv %s %s', path, newpath)
    end

    rename('runtime-src/proj.ios_mac/cocos-lua.xcodeproj/xcshareddata/xcschemes/cocos-lua-mobile.xcscheme')
    rename('runtime-src/proj.ios_mac/cocos-lua.xcodeproj/xcshareddata/xcschemes/cocos-lua-desktop.xcscheme')
    rename('runtime-src/proj.ios_mac/cocos-lua.xcodeproj')
    rename('runtime-src/proj.win32/cocos-lua.vcxproj.user')
    rename('runtime-src/proj.win32/cocos-lua.sln')
    rename('runtime-src/proj.win32/cocos-lua.vcxproj.filters')
    rename('runtime-src/proj.win32/cocos-lua.vcxproj')
    rename('cocos-lua.code-workspace')
end