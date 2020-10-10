-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/cocos2d-3d-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d_3d"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "xgame/xlua.h"
    #include "cocos2d.h"
    #include "3d/CC3DProgramInfo.h"
]]
M.CHUNK = ''

M.CONVS = {
    typeconv {
        CPPCLS = 'cocos2d::MeshVertexAttrib',
        DEF = [[
            cocos2d::backend::VertexFormat type;
            cocos2d::shaderinfos::VertexKey vertexAttrib;
        ]],
    },
}

M.CLASSES = {}

cls = typecls 'cocos2d::NTextureData::Usage'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Unknown', 'cocos2d::NTextureData::Usage::Unknown')
cls.enum('None', 'cocos2d::NTextureData::Usage::None')
cls.enum('Diffuse', 'cocos2d::NTextureData::Usage::Diffuse')
cls.enum('Emissive', 'cocos2d::NTextureData::Usage::Emissive')
cls.enum('Ambient', 'cocos2d::NTextureData::Usage::Ambient')
cls.enum('Specular', 'cocos2d::NTextureData::Usage::Specular')
cls.enum('Shininess', 'cocos2d::NTextureData::Usage::Shininess')
cls.enum('Normal', 'cocos2d::NTextureData::Usage::Normal')
cls.enum('Bump', 'cocos2d::NTextureData::Usage::Bump')
cls.enum('Transparency', 'cocos2d::NTextureData::Usage::Transparency')
cls.enum('Reflection', 'cocos2d::NTextureData::Usage::Reflection')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::shaderinfos::VertexKey'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('VERTEX_ATTRIB_POSITION', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_POSITION')
cls.enum('VERTEX_ATTRIB_COLOR', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_COLOR')
cls.enum('VERTEX_ATTRIB_TEX_COORD', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_TEX_COORD')
cls.enum('VERTEX_ATTRIB_TEX_COORD1', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_TEX_COORD1')
cls.enum('VERTEX_ATTRIB_TEX_COORD2', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_TEX_COORD2')
cls.enum('VERTEX_ATTRIB_TEX_COORD3', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_TEX_COORD3')
cls.enum('VERTEX_ATTRIB_NORMAL', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_NORMAL')
cls.enum('VERTEX_ATTRIB_BLEND_WEIGHT', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_BLEND_WEIGHT')
cls.enum('VERTEX_ATTRIB_BLEND_INDEX', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_BLEND_INDEX')
cls.enum('VERTEX_ATTRIB_TANGENT', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_TANGENT')
cls.enum('VERTEX_ATTRIB_BINORMAL', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_BINORMAL')
cls.enum('VERTEX_ATTRIB_MAX', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_MAX')
cls.enum('VERTEX_ATTRIB_TEX_COORDS', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_TEX_COORDS')
cls.enum('VERTEX_ATTRIB_ERROR', 'cocos2d::shaderinfos::VertexKey::VERTEX_ATTRIB_ERROR')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::shaderinfos::Uniformkey'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('UNIFORM_AMBIENT_COLOR', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_AMBIENT_COLOR')
cls.enum('UNIFORM_P_MATRIX', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_P_MATRIX')
cls.enum('UNIFORM_MULTIVIEW_P_MATRIX', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_MULTIVIEW_P_MATRIX')
cls.enum('UNIFORM_MV_MATRIX', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_MV_MATRIX')
cls.enum('UNIFORM_MVP_MATRIX', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_MVP_MATRIX')
cls.enum('UNIFORM_MULTIVIEW_MVP_MATRIX', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_MULTIVIEW_MVP_MATRIX')
cls.enum('UNIFORM_NORMAL_MATRIX', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_NORMAL_MATRIX')
cls.enum('UNIFORM_TIME', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_TIME')
cls.enum('UNIFORM_SIN_TIME', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_SIN_TIME')
cls.enum('UNIFORM_COS_TIME', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_COS_TIME')
cls.enum('UNIFORM_RANDOM01', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_RANDOM01')
cls.enum('UNIFORM_SAMPLER0', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_SAMPLER0')
cls.enum('UNIFORM_SAMPLER1', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_SAMPLER1')
cls.enum('UNIFORM_SAMPLER2', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_SAMPLER2')
cls.enum('UNIFORM_SAMPLER3', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_SAMPLER3')
cls.enum('UNIFORM_MAX', 'cocos2d::shaderinfos::Uniformkey::UNIFORM_MAX')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NTextureData'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.var('id', 'std::string id')
cls.var('filename', 'std::string filename')
cls.var('type', 'cocos2d::NTextureData::Usage type')
cls.var('wrapS', 'cocos2d::backend::SamplerAddressMode wrapS')
cls.var('wrapT', 'cocos2d::backend::SamplerAddressMode wrapT')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Mesh'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Mesh *create(const std::vector<float> &positions, const std::vector<float> &normals, const std::vector<float> &texs, const std::vector<unsigned short> &indices)', 'static cocos2d::Mesh *create(const std::vector<float> &vertices, int perVertexSizeInFloat, const std::vector<unsigned short> &indices, const std::vector<MeshVertexAttrib> &attribs)')
cls.func(nil, 'cocos2d::backend::Buffer *getVertexBuffer()')
cls.func(nil, 'bool hasVertexAttrib(cocos2d::shaderinfos::VertexKey attrib)')
cls.func(nil, 'ssize_t getMeshVertexAttribCount()')
cls.func(nil, 'const cocos2d::MeshVertexAttrib &getMeshVertexAttribute(int idx)')
cls.func(nil, 'int getVertexSizeInBytes()')
cls.func(nil, 'void setTexture(const std::string &texPath)', 'void setTexture(cocos2d::Texture2D *tex)', 'void setTexture(cocos2d::Texture2D *tex, cocos2d::NTextureData::Usage usage, @optional bool cacheFileName)', 'void setTexture(const std::string &texPath, cocos2d::NTextureData::Usage usage)')
cls.func(nil, 'cocos2d::Texture2D *getTexture()', 'cocos2d::Texture2D *getTexture(cocos2d::NTextureData::Usage usage)')
cls.func(nil, 'void setVisible(bool visible)')
cls.func(nil, 'bool isVisible()')
cls.func(nil, 'cocos2d::MeshSkin *getSkin()')
cls.func(nil, 'cocos2d::backend::ProgramState *getProgramState()')
cls.func(nil, 'const std::string &getName()')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'cocos2d::CustomCommand::PrimitiveType getPrimitiveType()')
cls.func(nil, 'ssize_t getIndexCount()')
cls.func(nil, 'cocos2d::CustomCommand::IndexFormat getIndexFormat()')
cls.func(nil, 'cocos2d::backend::Buffer *getIndexBuffer()')
cls.func(nil, 'void setProgramState(cocos2d::backend::ProgramState *programState)')
cls.func(nil, 'void draw(cocos2d::Renderer *renderer, float globalZ, const cocos2d::Mat4 &transform, uint32_t flags, unsigned int lightMask, const cocos2d::Vec4 &color, bool forceDepthWrite)')
cls.func(nil, 'void setSkin(cocos2d::MeshSkin *skin)')
cls.func(nil, 'void setName(const std::string &name)')
cls.func(nil, 'void calculateAABB()')
cls.func(nil, 'void setForce2DQueue(bool force2D)')
cls.func(nil, 'std::string getTextureFileName()')
cls.func(nil, 'Mesh()')
cls.prop('vertexBuffer', nil, nil)
cls.prop('meshVertexAttribCount', nil, nil)
cls.prop('vertexSizeInBytes', nil, nil)
cls.prop('visible', nil, nil)
cls.prop('skin', nil, nil)
cls.prop('programState', nil, nil)
cls.prop('name', nil, nil)
cls.prop('blendFunc', nil, nil)
cls.prop('primitiveType', nil, nil)
cls.prop('indexCount', nil, nil)
cls.prop('indexFormat', nil, nil)
cls.prop('indexBuffer', nil, nil)
cls.prop('textureFileName', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MeshSkin'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'ssize_t getBoneCount()')
cls.func(nil, 'cocos2d::Bone3D *getBoneByIndex(unsigned int index)')
cls.func(nil, 'cocos2d::Bone3D *getBoneByName(const std::string &id)')
cls.func(nil, 'int getBoneIndex(cocos2d::Bone3D *bone)')
cls.func(nil, 'ssize_t getMatrixPaletteSize()')
cls.func(nil, 'ssize_t getMatrixPaletteSizeInBytes()')
cls.func(nil, 'cocos2d::Bone3D *getRootBone()')
cls.func(nil, 'MeshSkin()')
cls.func(nil, 'void removeAllBones()')
cls.func(nil, 'void addSkinBone(cocos2d::Bone3D *bone)')
cls.func(nil, 'const cocos2d::Mat4 &getInvBindPose(const cocos2d::Bone3D *bone)')
cls.prop('boneCount', nil, nil)
cls.prop('matrixPaletteSize', nil, nil)
cls.prop('matrixPaletteSizeInBytes', nil, nil)
cls.prop('rootBone', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BillBoard::Mode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('VIEW_POINT_ORIENTED', 'cocos2d::BillBoard::Mode::VIEW_POINT_ORIENTED')
cls.enum('VIEW_PLANE_ORIENTED', 'cocos2d::BillBoard::Mode::VIEW_PLANE_ORIENTED')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BillBoard'
cls.SUPERCLS = 'cocos2d::Sprite'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::BillBoard *create(@optional cocos2d::BillBoard::Mode mode)', 'static cocos2d::BillBoard *create(const std::string &filename, @optional cocos2d::BillBoard::Mode mode)', 'static cocos2d::BillBoard *create(const std::string &filename, const cocos2d::Rect &rect, @optional cocos2d::BillBoard::Mode mode)')
cls.func(nil, 'static cocos2d::BillBoard *createWithTexture(cocos2d::Texture2D *texture, @optional cocos2d::BillBoard::Mode mode)')
cls.func(nil, 'void setMode(cocos2d::BillBoard::Mode mode)')
cls.func(nil, 'cocos2d::BillBoard::Mode getMode()')
cls.func(nil, 'BillBoard()')
cls.prop('mode', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Sprite3DMaterial::MaterialType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('UNLIT', 'cocos2d::Sprite3DMaterial::MaterialType::UNLIT')
cls.enum('UNLIT_NOTEX', 'cocos2d::Sprite3DMaterial::MaterialType::UNLIT_NOTEX')
cls.enum('VERTEX_LIT', 'cocos2d::Sprite3DMaterial::MaterialType::VERTEX_LIT')
cls.enum('DIFFUSE', 'cocos2d::Sprite3DMaterial::MaterialType::DIFFUSE')
cls.enum('DIFFUSE_NOTEX', 'cocos2d::Sprite3DMaterial::MaterialType::DIFFUSE_NOTEX')
cls.enum('BUMPED_DIFFUSE', 'cocos2d::Sprite3DMaterial::MaterialType::BUMPED_DIFFUSE')
cls.enum('CUSTOM', 'cocos2d::Sprite3DMaterial::MaterialType::CUSTOM')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Sprite3DMaterial'
cls.SUPERCLS = 'cocos2d::Material'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'cocos2d::Sprite3DMaterial::MaterialType getMaterialType()')
cls.func(nil, 'static cocos2d::Sprite3DMaterial *createBuiltInMaterial(cocos2d::Sprite3DMaterial::MaterialType type, bool skinned)', 'static void createBuiltInMaterial()')
cls.func(nil, 'static cocos2d::Sprite3DMaterial *createWithFilename(const std::string &path)')
cls.func(nil, 'static cocos2d::Sprite3DMaterial *createWithProgramState(cocos2d::backend::ProgramState *programState)')
cls.func(nil, 'void setTexture(cocos2d::Texture2D *tex, cocos2d::NTextureData::Usage usage)')
cls.func(nil, 'static void releaseBuiltInMaterial()')
cls.func(nil, 'static void releaseCachedMaterial()')
cls.prop('materialType', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Sprite3D'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Sprite3D *create()', 'static cocos2d::Sprite3D *create(const std::string &modelPath)', 'static cocos2d::Sprite3D *create(const std::string &modelPath, const std::string &texturePath)')
cls.func(nil, 'void setTexture(const std::string &texFile)', 'void setTexture(cocos2d::Texture2D *texture)')
cls.func(nil, 'cocos2d::Mesh *getMeshByIndex(int index)')
cls.func(nil, 'cocos2d::Mesh *getMeshByName(const std::string &name)')
cls.func(nil, 'std::vector<Mesh *> getMeshArrayByName(const std::string &name)')
cls.func(nil, 'cocos2d::Mesh *getMesh()')
cls.func(nil, 'ssize_t getMeshCount()')
cls.func(nil, 'cocos2d::Skeleton3D *getSkeleton()')
cls.func(nil, 'cocos2d::AttachNode *getAttachNode(const std::string &boneName)')
cls.func(nil, 'void removeAttachNode(const std::string &boneName)')
cls.func(nil, 'void removeAllAttachNode()')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'void setForceDepthWrite(bool value)')
cls.func(nil, 'bool isForceDepthWrite()')
cls.func(nil, 'void setCullFace(cocos2d::CullFaceSide side)')
cls.func(nil, 'void setCullFaceEnabled(bool enable)')
cls.func(nil, 'void setLightMask(unsigned int mask)')
cls.func(nil, 'unsigned int getLightMask()')
cls.func(nil, 'void setForce2DQueue(bool force2D)')
cls.func(nil, 'const Vector<cocos2d::Mesh *> &getMeshes()')
cls.func(nil, 'Sprite3D()')
cls.func(nil, 'bool initWithFile(const std::string &path)')
cls.func(nil, 'bool loadFromCache(const std::string &path)')
cls.func(nil, 'void genMaterial(@optional bool useLight)')
cls.func(nil, 'void addMesh(cocos2d::Mesh *mesh)')
cls.func(nil, 'void onAABBDirty()')
cls.func(nil, 'void afterAsyncLoad(void *param)')
cls.callback {
    FUNCS =  {
        'static void createAsync(const std::string &modelPath, @local const std::function<void (Sprite3D *, void *)> &callback, void *callbackparam)',
        'static void createAsync(const std::string &modelPath, const std::string &texturePath, @local const std::function<void (Sprite3D *, void *)> &callback, void *callbackparam)'
    },
    TAG_MAKER = 'createAsync',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('mesh', nil, nil)
cls.prop('meshCount', nil, nil)
cls.prop('skeleton', nil, nil)
cls.prop('blendFunc', nil, nil)
cls.prop('forceDepthWrite', nil, nil)
cls.prop('lightMask', nil, nil)
cls.prop('meshes', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AttachNode'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::AttachNode *create(cocos2d::Bone3D *attachBone)')
cls.func(nil, 'AttachNode()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Bone3D'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'const cocos2d::Mat4 &getInverseBindPose()')
cls.func(nil, 'void updateWorldMat()')
cls.func(nil, 'const cocos2d::Mat4 &getWorldMat()')
cls.func(nil, 'const std::string &getName()')
cls.func(nil, 'void clearBoneBlendState()')
cls.func(nil, 'static cocos2d::Bone3D *create(const std::string &id)')
cls.func(nil, 'void setInverseBindPose(const cocos2d::Mat4 &m)')
cls.func(nil, 'void setOriPose(const cocos2d::Mat4 &m)')
cls.func(nil, 'void resetPose()')
cls.func(nil, 'cocos2d::Bone3D *getParentBone()')
cls.func(nil, 'ssize_t getChildBoneCount()')
cls.func(nil, 'cocos2d::Bone3D *getChildBoneByIndex(int index)')
cls.func(nil, 'void addChildBone(cocos2d::Bone3D *bone)')
cls.func(nil, 'void removeChildBoneByIndex(int index)')
cls.func(nil, 'void removeChildBone(cocos2d::Bone3D *bone)')
cls.func(nil, 'void removeAllChildBone()')
cls.prop('inverseBindPose', nil, nil)
cls.prop('worldMat', nil, nil)
cls.prop('name', nil, nil)
cls.prop('parentBone', nil, nil)
cls.prop('childBoneCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Skeleton3D'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'ssize_t getBoneCount()')
cls.func(nil, 'cocos2d::Bone3D *getBoneByIndex(unsigned int index)')
cls.func(nil, 'cocos2d::Bone3D *getBoneByName(const std::string &id)')
cls.func(nil, 'ssize_t getRootCount()')
cls.func(nil, 'cocos2d::Bone3D *getRootBone(int index)')
cls.func(nil, 'int getBoneIndex(cocos2d::Bone3D *bone)')
cls.func(nil, 'void updateBoneMatrix()')
cls.func(nil, 'Skeleton3D()')
cls.func(nil, 'void removeAllBones()')
cls.func(nil, 'void addBone(cocos2d::Bone3D *bone)')
cls.prop('boneCount', nil, nil)
cls.prop('rootCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

return M
