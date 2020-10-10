local olua = require "olua"
local autoconf = require "autoconf"
local M = autoconf.typemod 'cocos2d_3d'
local typeconf = M.typeconf
local typedef = M.typedef
local typeconv = M.typeconv

M.PATH = '../../frameworks/libxgame/src/lua-bindings'
M.INCLUDES = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "cocos2d.h"
#include "3d/CC3DProgramInfo.h"
]]
M.CHUNK = [[]]

M.EXCLUDE_TYPE = require 'conf.exclude-type'
M.EXCLUDE_TYPE 'cocos2d::AABB'
M.EXCLUDE_TYPE 'cocos2d::Material *'
M.EXCLUDE_TYPE 'cocos2d::MeshIndexData *'
M.EXCLUDE_TYPE 'cocos2d::NodeDatas'
M.EXCLUDE_TYPE 'cocos2d::NodeDatas *'
M.EXCLUDE_TYPE 'cocos2d::NodeData *'
M.EXCLUDE_TYPE 'cocos2d::NodeData'

M.MAKE_LUACLS = function (cppname)
    cppname = string.gsub(cppname, '^cocos2d::shaderinfos::', 'cc.')
    cppname = string.gsub(cppname, '^cocos2d::', 'cc.')
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

typeconv 'cocos2d::MeshVertexAttrib'

typeconf 'cocos2d::NTextureData::Usage'
typeconf 'cocos2d::shaderinfos::VertexKey'
typeconf 'cocos2d::shaderinfos::Uniformkey'

typeconf 'cocos2d::NTextureData'
-- typeconf 'cocos2d::NMaterialData'
typeconf 'cocos2d::Mesh'

typeconf 'cocos2d::MeshSkin'
    .EXCLUDE_FUNC 'create'

-- typeconf 'cocos2d::MeshIndexData'
-- typeconf 'cocos2d::MeshVertexData'
-- typeconf 'cocos2d::AnimationCurve'
typeconf 'cocos2d::BillBoard::Mode'
typeconf 'cocos2d::BillBoard'

typeconf 'cocos2d::Sprite3DMaterial::MaterialType'
typeconf 'cocos2d::Sprite3DMaterial'
typeconf 'cocos2d::Sprite3D'

typeconf 'cocos2d::AttachNode'
typeconf 'cocos2d::Bone3D'
typeconf 'cocos2d::Skeleton3D'
    .EXCLUDE_FUNC 'create'

return M