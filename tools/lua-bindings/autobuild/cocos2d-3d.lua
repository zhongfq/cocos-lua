-- AUTO BUILD, DON'T MODIFY!

require "autobuild.cocos2d-3d-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d_3d"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d_3d.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "cocos2d.h"
#include "3d/CC3DProgramInfo.h"
]]
M.CHUNK = [[

]]

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
cls.enums [[
    Unknown
    None
    Diffuse
    Emissive
    Ambient
    Specular
    Shininess
    Normal
    Bump
    Transparency
    Reflection
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::shaderinfos::VertexKey'
cls.enums [[
    VERTEX_ATTRIB_POSITION
    VERTEX_ATTRIB_COLOR
    VERTEX_ATTRIB_TEX_COORD
    VERTEX_ATTRIB_TEX_COORD1
    VERTEX_ATTRIB_TEX_COORD2
    VERTEX_ATTRIB_TEX_COORD3
    VERTEX_ATTRIB_NORMAL
    VERTEX_ATTRIB_BLEND_WEIGHT
    VERTEX_ATTRIB_BLEND_INDEX
    VERTEX_ATTRIB_TANGENT
    VERTEX_ATTRIB_BINORMAL
    VERTEX_ATTRIB_MAX
    VERTEX_ATTRIB_TEX_COORDS
    VERTEX_ATTRIB_ERROR
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::shaderinfos::Uniformkey'
cls.enums [[
    UNIFORM_AMBIENT_COLOR
    UNIFORM_P_MATRIX
    UNIFORM_MULTIVIEW_P_MATRIX
    UNIFORM_MV_MATRIX
    UNIFORM_MVP_MATRIX
    UNIFORM_MULTIVIEW_MVP_MATRIX
    UNIFORM_NORMAL_MATRIX
    UNIFORM_TIME
    UNIFORM_SIN_TIME
    UNIFORM_COS_TIME
    UNIFORM_RANDOM01
    UNIFORM_SAMPLER0
    UNIFORM_SAMPLER1
    UNIFORM_SAMPLER2
    UNIFORM_SAMPLER3
    UNIFORM_MAX
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NTextureData'
cls.funcs [[
]]
cls.var('id', [[std::string id]])
cls.var('filename', [[std::string filename]])
cls.var('type', [[cocos2d::NTextureData::Usage type]])
cls.var('wrapS', [[cocos2d::backend::SamplerAddressMode wrapS]])
cls.var('wrapT', [[cocos2d::backend::SamplerAddressMode wrapT]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Mesh'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::Mesh *create(const std::vector<float> &positions, const std::vector<float> &normals, const std::vector<float> &texs, const std::vector<unsigned short> &indices)
    static cocos2d::Mesh *create(const std::vector<float> &vertices, int perVertexSizeInFloat, const std::vector<unsigned short> &indices, const std::vector<MeshVertexAttrib> &attribs)
    cocos2d::backend::Buffer *getVertexBuffer()
    bool hasVertexAttrib(cocos2d::shaderinfos::VertexKey attrib)
    ssize_t getMeshVertexAttribCount()
    const cocos2d::MeshVertexAttrib &getMeshVertexAttribute(int idx)
    int getVertexSizeInBytes()
    void setTexture(const std::string &texPath)
    void setTexture(cocos2d::Texture2D *tex)
    void setTexture(cocos2d::Texture2D *tex, cocos2d::NTextureData::Usage usage, @optional bool cacheFileName)
    void setTexture(const std::string &texPath, cocos2d::NTextureData::Usage usage)
    cocos2d::Texture2D *getTexture()
    cocos2d::Texture2D *getTexture(cocos2d::NTextureData::Usage usage)
    void setVisible(bool visible)
    bool isVisible()
    cocos2d::MeshSkin *getSkin()
    cocos2d::backend::ProgramState *getProgramState()
    const std::string &getName()
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    const cocos2d::BlendFunc &getBlendFunc()
    cocos2d::CustomCommand::PrimitiveType getPrimitiveType()
    ssize_t getIndexCount()
    cocos2d::CustomCommand::IndexFormat getIndexFormat()
    cocos2d::backend::Buffer *getIndexBuffer()
    void setProgramState(cocos2d::backend::ProgramState *programState)
    void draw(cocos2d::Renderer *renderer, float globalZ, const cocos2d::Mat4 &transform, uint32_t flags, unsigned int lightMask, const cocos2d::Vec4 &color, bool forceDepthWrite)
    void setSkin(cocos2d::MeshSkin *skin)
    void setName(const std::string &name)
    void calculateAABB()
    void setForce2DQueue(bool force2D)
    std::string getTextureFileName()
    Mesh()
]]
cls.props [[
    vertexBuffer
    meshVertexAttribCount
    vertexSizeInBytes
    visible
    skin
    programState
    name
    blendFunc
    primitiveType
    indexCount
    indexFormat
    indexBuffer
    textureFileName
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MeshSkin'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    ssize_t getBoneCount()
    cocos2d::Bone3D *getBoneByIndex(unsigned int index)
    cocos2d::Bone3D *getBoneByName(const std::string &id)
    int getBoneIndex(cocos2d::Bone3D *bone)
    ssize_t getMatrixPaletteSize()
    ssize_t getMatrixPaletteSizeInBytes()
    cocos2d::Bone3D *getRootBone()
    MeshSkin()
    void removeAllBones()
    void addSkinBone(cocos2d::Bone3D *bone)
    const cocos2d::Mat4 &getInvBindPose(const cocos2d::Bone3D *bone)
]]
cls.props [[
    boneCount
    matrixPaletteSize
    matrixPaletteSizeInBytes
    rootBone
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BillBoard::Mode'
cls.enums [[
    VIEW_POINT_ORIENTED
    VIEW_PLANE_ORIENTED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BillBoard'
cls.SUPERCLS = "cocos2d::Sprite"
cls.funcs [[
    static cocos2d::BillBoard *create(@optional cocos2d::BillBoard::Mode mode)
    static cocos2d::BillBoard *create(const std::string &filename, @optional cocos2d::BillBoard::Mode mode)
    static cocos2d::BillBoard *create(const std::string &filename, const cocos2d::Rect &rect, @optional cocos2d::BillBoard::Mode mode)
    static cocos2d::BillBoard *createWithTexture(cocos2d::Texture2D *texture, @optional cocos2d::BillBoard::Mode mode)
    void setMode(cocos2d::BillBoard::Mode mode)
    cocos2d::BillBoard::Mode getMode()
    BillBoard()
]]
cls.props [[
    mode
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Sprite3DMaterial::MaterialType'
cls.enums [[
    UNLIT
    UNLIT_NOTEX
    VERTEX_LIT
    DIFFUSE
    DIFFUSE_NOTEX
    BUMPED_DIFFUSE
    CUSTOM
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Sprite3DMaterial'
cls.SUPERCLS = "cocos2d::Material"
cls.funcs [[
    cocos2d::Sprite3DMaterial::MaterialType getMaterialType()
    static cocos2d::Sprite3DMaterial *createBuiltInMaterial(cocos2d::Sprite3DMaterial::MaterialType type, bool skinned)
    static cocos2d::Sprite3DMaterial *createWithFilename(const std::string &path)
    static cocos2d::Sprite3DMaterial *createWithProgramState(cocos2d::backend::ProgramState *programState)
    void setTexture(cocos2d::Texture2D *tex, cocos2d::NTextureData::Usage usage)
    static void createBuiltInMaterial()
    static void releaseBuiltInMaterial()
    static void releaseCachedMaterial()
]]
cls.props [[
    materialType
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Sprite3D'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::Sprite3D *create()
    static cocos2d::Sprite3D *create(const std::string &modelPath)
    static cocos2d::Sprite3D *create(const std::string &modelPath, const std::string &texturePath)
    void setTexture(const std::string &texFile)
    void setTexture(cocos2d::Texture2D *texture)
    cocos2d::Mesh *getMeshByIndex(int index)
    cocos2d::Mesh *getMeshByName(const std::string &name)
    std::vector<Mesh *> getMeshArrayByName(const std::string &name)
    cocos2d::Mesh *getMesh()
    ssize_t getMeshCount()
    cocos2d::Skeleton3D *getSkeleton()
    cocos2d::AttachNode *getAttachNode(const std::string &boneName)
    void removeAttachNode(const std::string &boneName)
    void removeAllAttachNode()
    void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    const cocos2d::BlendFunc &getBlendFunc()
    void setForceDepthWrite(bool value)
    bool isForceDepthWrite()
    void setCullFace(cocos2d::CullFaceSide side)
    void setCullFaceEnabled(bool enable)
    void setLightMask(unsigned int mask)
    unsigned int getLightMask()
    void setForce2DQueue(bool force2D)
    const Vector<cocos2d::Mesh *> &getMeshes()
    Sprite3D()
    bool initWithFile(const std::string &path)
    bool loadFromCache(const std::string &path)
    void genMaterial(@optional bool useLight)
    void addMesh(cocos2d::Mesh *mesh)
    void onAABBDirty()
    void afterAsyncLoad(void *param)
]]
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
cls.props [[
    mesh
    meshCount
    skeleton
    blendFunc
    forceDepthWrite
    lightMask
    meshes
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AttachNode'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::AttachNode *create(cocos2d::Bone3D *attachBone)
    AttachNode()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Bone3D'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    const cocos2d::Mat4 &getInverseBindPose()
    void updateWorldMat()
    const cocos2d::Mat4 &getWorldMat()
    const std::string &getName()
    void clearBoneBlendState()
    static cocos2d::Bone3D *create(const std::string &id)
    void setInverseBindPose(const cocos2d::Mat4 &m)
    void setOriPose(const cocos2d::Mat4 &m)
    void resetPose()
    cocos2d::Bone3D *getParentBone()
    ssize_t getChildBoneCount()
    cocos2d::Bone3D *getChildBoneByIndex(int index)
    void addChildBone(cocos2d::Bone3D *bone)
    void removeChildBoneByIndex(int index)
    void removeChildBone(cocos2d::Bone3D *bone)
    void removeAllChildBone()
]]
cls.props [[
    inverseBindPose
    worldMat
    name
    parentBone
    childBoneCount
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Skeleton3D'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    ssize_t getBoneCount()
    cocos2d::Bone3D *getBoneByIndex(unsigned int index)
    cocos2d::Bone3D *getBoneByName(const std::string &id)
    ssize_t getRootCount()
    cocos2d::Bone3D *getRootBone(int index)
    int getBoneIndex(cocos2d::Bone3D *bone)
    void updateBoneMatrix()
    Skeleton3D()
    void removeAllBones()
    void addBone(cocos2d::Bone3D *bone)
]]
cls.props [[
    boneCount
    rootCount
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
