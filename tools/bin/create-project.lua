local bash = require "bash"

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

print('create project:', PROJECT_DIR)
bash.execute('cp -a ../../ ${PROJECT_DIR}')
bash.execute('rm -rf ${PROJECT_DIR}/.git')

do -- replace project name
    local function replace(path)
        path = PROJECT_DIR .. '/' .. path
        bash.execute("cat ${path} | sed 's/cocos-lua/${PROJECT_NAME}/g' > ${path}.bak")
        bash.execute("mv ${path}.bak ${path}")
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
        bash.execute("cat ${path} | sed 's/org.cocos2dx.hellolua/${PACKAGE_NAME}/g' > ${path}.bak")
        bash.execute("mv ${path}.bak ${path}")
    end
    replace('runtime-src/proj.win32/main.cpp')
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
    bash.execute('cp -rf ${PROJECT_DIR}/runtime-src/proj.android/app/src/org/cocos2dx/hellolua ${PROJECT_DIR}/tmp')
    bash.execute('rm -rf ${PROJECT_DIR}/runtime-src/proj.android/app/src/org')
    bash.execute('mkdir -p ${PROJECT_DIR}/runtime-src/proj.android/app/src/${PACKAGE_NAME_PATH}')
    bash.execute('cp -rf ${PROJECT_DIR}/tmp/* ${PROJECT_DIR}/runtime-src/proj.android/app/src/${PACKAGE_NAME_PATH}')
    bash.execute('rm -rf ${PROJECT_DIR}/tmp')
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
        bash.execute('mv ${path} ${newpath}')
    end

    rename('runtime-src/proj.ios_mac/cocos-lua.xcodeproj/xcshareddata/xcschemes/cocos-lua-mobile.xcscheme')
    rename('runtime-src/proj.ios_mac/cocos-lua.xcodeproj/xcshareddata/xcschemes/cocos-lua-desktop.xcscheme')
    rename('runtime-src/proj.ios_mac/cocos-lua.xcodeproj')
    rename('runtime-src/proj.win32/cocos-lua.vcxproj.user')
    rename('runtime-src/proj.win32/cocos-lua.sln')
    rename('runtime-src/proj.win32/cocos-lua.vcxproj.filters')
    rename('runtime-src/proj.win32/cocos-lua.vcxproj')
    rename('fgui/cocos-lua.fairy')
    rename('cocos-lua.code-workspace')
end