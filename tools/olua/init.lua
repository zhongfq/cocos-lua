local OS = io.popen('uname'):read("*l")
OS = (OS == 'Darwin') and 'osx' or (OS == 'Linux' and 'linux' or 'win32')

if OS == 'osx' then
    package.cpath = "lib/mac/?.so;" .. package.cpath
elseif OS == 'linux' then
    package.cpath = "lib/linux/?.so;" .. package.cpath
else
    error('TODO')
end

require "olua.olua-typecls"
require "olua.olua-basictype"
require "olua.olua-gen-header"
require "olua.olua-gen-source"
require "olua.olua-gen-class"
require "olua.olua-gen-class-func"
require "olua.olua-gen-callback"
require "olua.olua-gen-conv"

return require "olua.olua-io"