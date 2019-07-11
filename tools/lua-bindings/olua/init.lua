local OS = io.popen('uname'):read("*l")
OS = (OS == 'Darwin') and 'osx' or (OS == 'Linux' and 'linux' or 'win32')

if OS == 'osx' then
    package.cpath = "../usr/osx/lib/lua/?.so;" .. package.cpath
elseif OS == 'linux' then
    package.cpath = "../usr/linux/lib/lua/?.so;" .. package.cpath
else
    error('TODO')
end

local olua = require "olua.core"

require "olua.typecls"
require "olua.basictype"
require "olua.olua-gen-header"
require "olua.olua-gen-source"
require "olua.olua-gen-class"
require "olua.olua-gen-class-func"
require "olua.olua-gen-callback"
require "olua.olua-gen-conv"

function olua.export(path)
    local module = dofile(path)
    if #module.CLASSES > 0 then
        gen_header(module)
        gen_source(module)
    elseif #module.CONVS > 0 then
        gen_conv(module)
    end
end

return olua