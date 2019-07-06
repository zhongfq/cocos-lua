local OS = io.popen('uname'):read("*l")
OS = (OS == 'Darwin') and 'osx' or (OS == 'Linux' and 'linux' or 'win32')

if OS == 'osx' then
    package.cpath = "../usr/osx/lib/lua/?.so;" .. package.cpath
elseif OS == 'linux' then
    package.cpath = "../usr/linux/lib/lua/?.so;" .. package.cpath
else
    error('TODO')
end

require "olua.olua-core"
require "olua.olua-cls"
require "olua.olua-arg-type"
require "olua.olua-gen-header"
require "olua.olua-gen-source"
require "olua.olua-gen-class"
require "olua.olua-gen-class-func"
require "olua.olua-gen-callback"
require "olua.olua-gen-conv"

return