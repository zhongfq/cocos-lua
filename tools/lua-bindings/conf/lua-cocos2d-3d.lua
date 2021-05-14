module 'cocos2d_3d'

path = '../../frameworks/libxgame/src/lua-bindings'

headers = [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "cocos2d.h"
#include "3d/CC3DProgramInfo.h"
]]

make_luacls = function (cppname)
    cppname = string.gsub(cppname, '^cocos2d::shaderinfos::', 'cc.')
    cppname = string.gsub(cppname, '^cocos2d::', 'cc.')
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end

include 'conf/exclude-type.lua'

exclude 'cocos2d::AABB'
exclude 'cocos2d::Material *'
exclude 'cocos2d::MeshIndexData *'
exclude 'cocos2d::NodeDatas'
exclude 'cocos2d::NodeDatas *'
exclude 'cocos2d::NodeData *'
exclude 'cocos2d::NodeData'

typeconv 'cocos2d::MeshVertexAttrib'

typeconf 'cocos2d::NTextureData::Usage'
typeconf 'cocos2d::shaderinfos::VertexKey'
typeconf 'cocos2d::shaderinfos::Uniformkey'

typeconf 'cocos2d::NTextureData'
-- typeconf 'cocos2d::NMaterialData'
typeconf 'cocos2d::Mesh'

typeconf 'cocos2d::MeshSkin'
    .exclude 'create'

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
    .exclude 'create'
