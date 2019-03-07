require "aux.tolua-aux"
require "aux.tolua-cls"
require "aux.tolua-arg-type"
require "aux.tolua-gen-header"
require "aux.tolua-gen-source"
require "aux.tolua-gen-class"
require "aux.tolua-gen-class-func"
require "aux.tolua-gen-callback"
require "aux.tolua-gen-conv"

PROJECT_ROOT = '../../'

function gen_module(module)
    gen_header(module)
    gen_source(module)
end

gen_conv(require("conf.lua-conv"))
gen_module(require("conf.cocos2d.lua-cocos2d"))
gen_module(require("conf.xgame.lua-xgame"))

-- require "conf.cocos2d.import-cocos2d-type"
-- local cls = class()
-- cls.CPPCLS = "cocos2d::TextureCache"
-- cls.LUACLS = "cc.TextureCache"
-- cls.SUPERCLS = "cc.Ref"
-- cls.callback(nil, 
--     {
--         MAKER = 'makeTextureCacheCallbackTag(#1)',
--         REMOVED = true,
--         REMOVED_MODE = 'TOLUA_REMOVE_CALLBACK_EQUAL',
--     }, 
--     'void addImageAsync(const std::string &filepath, const std::function<void(Texture2D*)>& callback)',
--     'void addImageAsync(const std::string &path, const std::function<void(Texture2D*)>& callback, const std::string& callbackKey)'
-- )