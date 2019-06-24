local OS = io.popen('uname'):read("*l")
OS = (OS == 'Darwin') and 'osx' or (OS == 'Linux' and 'linux' or 'win32')

if OS == 'osx' then
    package.cpath = "../usr/osx/lib/lua/?.so;" .. package.cpath
elseif OS == 'linux' then
    package.cpath = "../usr/linux/lib/lua/?.so;" .. package.cpath
else
    error('TODO')
end

local clang = require "clang"

local index = clang.createIndex(false, true)

local tu = assert(index:parse('../../frameworks/cocos2d-x/cocos/2d/CCNode.h', {
    "-I../../frameworks/cocos2d-x/cocos",
    "-I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1",
    "-x",
    "c++",
    "-DCC_DLL=",
    "-std=c++11",
}))

local idt = 0

local function indent()
    idt = idt + 2
end

local function unindent()
    idt = idt - 2
end

local function trace(str)
    print(string.rep(' ', idt) .. str)
end

local function dumpXML(cur)
    trace(string.format("%s %s %s", cur:kind(), cur:name(), cur:displayName()))
    indent()
    for _,c in ipairs(cur:children()) do
        dumpXML(c)
    end
    unindent()
end

dumpXML(tu:cursor())