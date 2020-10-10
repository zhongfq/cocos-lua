-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/dragonbones-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "dragonbones"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "xgame/xlua.h"
    #include "cocos2d.h"
    #include "CCDragonBonesHeaders.h"
]]
M.CHUNK = ''

M.CONVS = {
    typeconv {
        CPPCLS = 'dragonBones::Rectangle',
        DEF = [[
            float x;
            float y;
            float width;
            float height;
        ]],
    },
}

M.CLASSES = {}

cls = typecls 'dragonBones::BinaryOffset'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('WeigthBoneCount', 'dragonBones::BinaryOffset::WeigthBoneCount')
cls.enum('WeigthFloatOffset', 'dragonBones::BinaryOffset::WeigthFloatOffset')
cls.enum('WeigthBoneIndices', 'dragonBones::BinaryOffset::WeigthBoneIndices')
cls.enum('MeshVertexCount', 'dragonBones::BinaryOffset::MeshVertexCount')
cls.enum('MeshTriangleCount', 'dragonBones::BinaryOffset::MeshTriangleCount')
cls.enum('MeshFloatOffset', 'dragonBones::BinaryOffset::MeshFloatOffset')
cls.enum('MeshWeightOffset', 'dragonBones::BinaryOffset::MeshWeightOffset')
cls.enum('MeshVertexIndices', 'dragonBones::BinaryOffset::MeshVertexIndices')
cls.enum('TimelineScale', 'dragonBones::BinaryOffset::TimelineScale')
cls.enum('TimelineOffset', 'dragonBones::BinaryOffset::TimelineOffset')
cls.enum('TimelineKeyFrameCount', 'dragonBones::BinaryOffset::TimelineKeyFrameCount')
cls.enum('TimelineFrameValueCount', 'dragonBones::BinaryOffset::TimelineFrameValueCount')
cls.enum('TimelineFrameValueOffset', 'dragonBones::BinaryOffset::TimelineFrameValueOffset')
cls.enum('TimelineFrameOffset', 'dragonBones::BinaryOffset::TimelineFrameOffset')
cls.enum('FramePosition', 'dragonBones::BinaryOffset::FramePosition')
cls.enum('FrameTweenType', 'dragonBones::BinaryOffset::FrameTweenType')
cls.enum('FrameTweenEasingOrCurveSampleCount', 'dragonBones::BinaryOffset::FrameTweenEasingOrCurveSampleCount')
cls.enum('FrameCurveSamples', 'dragonBones::BinaryOffset::FrameCurveSamples')
cls.enum('DeformVertexOffset', 'dragonBones::BinaryOffset::DeformVertexOffset')
cls.enum('DeformCount', 'dragonBones::BinaryOffset::DeformCount')
cls.enum('DeformValueCount', 'dragonBones::BinaryOffset::DeformValueCount')
cls.enum('DeformValueOffset', 'dragonBones::BinaryOffset::DeformValueOffset')
cls.enum('DeformFloatOffset', 'dragonBones::BinaryOffset::DeformFloatOffset')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ArmatureType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Armature', 'dragonBones::ArmatureType::Armature')
cls.enum('MovieClip', 'dragonBones::ArmatureType::MovieClip')
cls.enum('Stage', 'dragonBones::ArmatureType::Stage')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::OffsetMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('None', 'dragonBones::OffsetMode::None')
cls.enum('Additive', 'dragonBones::OffsetMode::Additive')
cls.enum('Override', 'dragonBones::OffsetMode::Override')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::DisplayType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Image', 'dragonBones::DisplayType::Image')
cls.enum('Armature', 'dragonBones::DisplayType::Armature')
cls.enum('Mesh', 'dragonBones::DisplayType::Mesh')
cls.enum('BoundingBox', 'dragonBones::DisplayType::BoundingBox')
cls.enum('Path', 'dragonBones::DisplayType::Path')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BoundingBoxType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Rectangle', 'dragonBones::BoundingBoxType::Rectangle')
cls.enum('Ellipse', 'dragonBones::BoundingBoxType::Ellipse')
cls.enum('Polygon', 'dragonBones::BoundingBoxType::Polygon')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ActionType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Play', 'dragonBones::ActionType::Play')
cls.enum('Frame', 'dragonBones::ActionType::Frame')
cls.enum('Sound', 'dragonBones::ActionType::Sound')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BlendMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Normal', 'dragonBones::BlendMode::Normal')
cls.enum('Add', 'dragonBones::BlendMode::Add')
cls.enum('Alpha', 'dragonBones::BlendMode::Alpha')
cls.enum('Darken', 'dragonBones::BlendMode::Darken')
cls.enum('Difference', 'dragonBones::BlendMode::Difference')
cls.enum('Erase', 'dragonBones::BlendMode::Erase')
cls.enum('HardLight', 'dragonBones::BlendMode::HardLight')
cls.enum('Invert', 'dragonBones::BlendMode::Invert')
cls.enum('Layer', 'dragonBones::BlendMode::Layer')
cls.enum('Lighten', 'dragonBones::BlendMode::Lighten')
cls.enum('Multiply', 'dragonBones::BlendMode::Multiply')
cls.enum('Overlay', 'dragonBones::BlendMode::Overlay')
cls.enum('Screen', 'dragonBones::BlendMode::Screen')
cls.enum('Subtract', 'dragonBones::BlendMode::Subtract')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TweenType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('None', 'dragonBones::TweenType::None')
cls.enum('Line', 'dragonBones::TweenType::Line')
cls.enum('Curve', 'dragonBones::TweenType::Curve')
cls.enum('QuadIn', 'dragonBones::TweenType::QuadIn')
cls.enum('QuadOut', 'dragonBones::TweenType::QuadOut')
cls.enum('QuadInOut', 'dragonBones::TweenType::QuadInOut')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TimelineType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Action', 'dragonBones::TimelineType::Action')
cls.enum('ZOrder', 'dragonBones::TimelineType::ZOrder')
cls.enum('BoneAll', 'dragonBones::TimelineType::BoneAll')
cls.enum('BoneTranslate', 'dragonBones::TimelineType::BoneTranslate')
cls.enum('BoneRotate', 'dragonBones::TimelineType::BoneRotate')
cls.enum('BoneScale', 'dragonBones::TimelineType::BoneScale')
cls.enum('SlotDisplay', 'dragonBones::TimelineType::SlotDisplay')
cls.enum('SlotColor', 'dragonBones::TimelineType::SlotColor')
cls.enum('SlotDeform', 'dragonBones::TimelineType::SlotDeform')
cls.enum('IKConstraint', 'dragonBones::TimelineType::IKConstraint')
cls.enum('AnimationTime', 'dragonBones::TimelineType::AnimationTime')
cls.enum('AnimationWeight', 'dragonBones::TimelineType::AnimationWeight')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::AnimationFadeOutMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('None', 'dragonBones::AnimationFadeOutMode::None')
cls.enum('SameLayer', 'dragonBones::AnimationFadeOutMode::SameLayer')
cls.enum('SameGroup', 'dragonBones::AnimationFadeOutMode::SameGroup')
cls.enum('SameLayerAndGroup', 'dragonBones::AnimationFadeOutMode::SameLayerAndGroup')
cls.enum('All', 'dragonBones::AnimationFadeOutMode::All')
cls.enum('Single', 'dragonBones::AnimationFadeOutMode::Single')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TextureFormat'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('DEFAULT', 'dragonBones::TextureFormat::DEFAULT')
cls.enum('RGBA8888', 'dragonBones::TextureFormat::RGBA8888')
cls.enum('BGRA8888', 'dragonBones::TextureFormat::BGRA8888')
cls.enum('RGBA4444', 'dragonBones::TextureFormat::RGBA4444')
cls.enum('RGB888', 'dragonBones::TextureFormat::RGB888')
cls.enum('RGB565', 'dragonBones::TextureFormat::RGB565')
cls.enum('RGBA5551', 'dragonBones::TextureFormat::RGBA5551')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BaseObject'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static void setMaxCount(std::size_t classTypeIndex, unsigned int maxCount)')
cls.func(nil, 'static void clearPool(@optional std::size_t classTypeIndex)')
cls.func(nil, 'std::size_t getClassTypeIndex()')
cls.func(nil, 'void returnToPool()')
cls.prop('classTypeIndex', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::EventObject'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'EventObject()')
cls.func(nil, 'static void actionDataToInstance(const dragonBones::ActionData *data, dragonBones::EventObject *instance, dragonBones::Armature *armature)')
cls.func(nil, 'dragonBones::Armature *getArmature()')
cls.func(nil, 'dragonBones::Bone *getBone()')
cls.func(nil, 'dragonBones::Slot *getSlot()')
cls.func(nil, 'dragonBones::AnimationState *getAnimationState()')
cls.func(nil, 'dragonBones::UserData *getData()')
cls.var('START', 'static const char *START')
cls.var('LOOP_COMPLETE', 'static const char *LOOP_COMPLETE')
cls.var('COMPLETE', 'static const char *COMPLETE')
cls.var('FADE_IN', 'static const char *FADE_IN')
cls.var('FADE_IN_COMPLETE', 'static const char *FADE_IN_COMPLETE')
cls.var('FADE_OUT', 'static const char *FADE_OUT')
cls.var('FADE_OUT_COMPLETE', 'static const char *FADE_OUT_COMPLETE')
cls.var('FRAME_EVENT', 'static const char *FRAME_EVENT')
cls.var('SOUND_EVENT', 'static const char *SOUND_EVENT')
cls.var('time', 'float time')
cls.var('type', 'std::string type')
cls.var('name', 'std::string name')
cls.var('armature', 'dragonBones::Armature *armature')
cls.var('bone', 'dragonBones::Bone *bone')
cls.var('slot', 'dragonBones::Slot *slot')
cls.var('animationState', 'dragonBones::AnimationState *animationState')
cls.var('actionData', 'const dragonBones::ActionData *actionData')
cls.var('data', 'dragonBones::UserData *data')
cls.prop('typeIndex', nil, nil)
cls.prop('armature', nil, nil)
cls.prop('bone', nil, nil)
cls.prop('slot', nil, nil)
cls.prop('animationState', nil, nil)
cls.prop('data', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TransformObject'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void updateGlobalTransform()')
cls.func(nil, 'dragonBones::Armature *getArmature()')
cls.var('userData', 'void *userData')
cls.prop('armature', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::Point'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Point()')
cls.func(nil, 'void clear()')
cls.func(nil, 'static dragonBones::Point *getHelpPointA()')
cls.func(nil, 'static dragonBones::Point *getHelpPointB()')
cls.func(nil, 'static dragonBones::Point *getHelpPointC()')
cls.func(nil, 'static dragonBones::Point *getHelpPointD()')
cls.var('x', 'float x')
cls.var('y', 'float y')
cls.prop('helpPointA', nil, nil)
cls.prop('helpPointB', nil, nil)
cls.prop('helpPointC', nil, nil)
cls.prop('helpPointD', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ConstraintData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'const dragonBones::BoneData *getTarget()')
cls.func(nil, 'void setTarget(const dragonBones::BoneData *value)')
cls.func(nil, 'const dragonBones::BoneData *getBone()')
cls.func(nil, 'void setBone(const dragonBones::BoneData *value)')
cls.func(nil, 'const dragonBones::BoneData *getRoot()')
cls.func(nil, 'void setRoot(const dragonBones::BoneData *value)')
cls.var('order', 'int order')
cls.var('name', 'std::string name')
cls.var('target', 'const dragonBones::BoneData *target')
cls.var('root', 'const dragonBones::BoneData *root')
cls.var('bone', 'const dragonBones::BoneData *bone')
cls.prop('target', nil, nil)
cls.prop('bone', nil, nil)
cls.prop('root', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::IKConstraintData'
cls.SUPERCLS = 'dragonBones::ConstraintData'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'IKConstraintData()')
cls.var('scaleEnabled', 'bool scaleEnabled')
cls.var('bendPositive', 'bool bendPositive')
cls.var('weight', 'float weight')
cls.prop('typeIndex', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TimelineData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'TimelineData()')
cls.func(nil, 'int getType()')
cls.func(nil, 'void setType(int value)')
cls.var('type', 'dragonBones::TimelineType type')
cls.var('offset', 'unsigned int offset')
cls.var('frameIndicesOffset', 'int frameIndicesOffset')
cls.prop('typeIndex', nil, nil)
cls.prop('type', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::IAnimatable'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void advanceTime(float passedTime)')
cls.func(nil, 'dragonBones::WorldClock *getClock()')
cls.func(nil, 'void setClock(dragonBones::WorldClock *value)')
cls.prop('clock', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::WorldClock'
cls.SUPERCLS = 'dragonBones::IAnimatable'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'WorldClock(@optional float timeValue)')
cls.func(nil, 'bool contains(const dragonBones::IAnimatable *value)')
cls.func(nil, 'void add(dragonBones::IAnimatable *value)')
cls.func(nil, 'void remove(dragonBones::IAnimatable *value)')
cls.func(nil, 'void clear()')
cls.func(nil, 'static dragonBones::WorldClock *getStaticClock()')
cls.var('time', 'float time')
cls.var('timeScale', 'float timeScale')
cls.prop('staticClock', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::Slot'
cls.SUPERCLS = 'dragonBones::TransformObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void init(const dragonBones::SlotData *slotData, dragonBones::Armature *armatureValue, void *rawDisplay, void *meshDisplay)')
cls.func(nil, 'void update(int cacheFrameIndex)')
cls.func(nil, 'void updateTransformAndMatrix()')
cls.func(nil, 'void replaceDisplayData(dragonBones::DisplayData *displayData, int displayIndex)')
cls.func(nil, 'bool containsPoint(float x, float y)')
cls.func(nil, 'int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)')
cls.func(nil, 'void invalidUpdate()')
cls.func(nil, 'bool getVisible()')
cls.func(nil, 'void setVisible(bool value)')
cls.func(nil, 'int getDisplayIndex()')
cls.func(nil, 'void setDisplayIndex(int value)')
cls.func(nil, 'const std::string &getName()')
cls.func(nil, 'const dragonBones::SlotData *getSlotData()')
cls.func(nil, 'dragonBones::BoundingBoxData *getBoundingBoxData()')
cls.func(nil, 'void *getRawDisplay()')
cls.func(nil, 'void *getMeshDisplay()')
cls.func(nil, 'void *getDisplay()')
cls.func(nil, 'void setDisplay(void *value, dragonBones::DisplayType displayType)')
cls.func(nil, 'dragonBones::Armature *getChildArmature()')
cls.func(nil, 'void setChildArmature(dragonBones::Armature *value)')
cls.func(nil, 'dragonBones::Bone *getParent()')
cls.var('displayController', 'std::string displayController')
cls.prop('visible', nil, nil)
cls.prop('displayIndex', nil, nil)
cls.prop('name', nil, nil)
cls.prop('slotData', nil, nil)
cls.prop('boundingBoxData', nil, nil)
cls.prop('rawDisplay', nil, nil)
cls.prop('meshDisplay', nil, nil)
cls.prop('display', nil, nil)
cls.prop('childArmature', nil, nil)
cls.prop('parent', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::Bone'
cls.SUPERCLS = 'dragonBones::TransformObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'Bone()')
cls.func(nil, 'void init(const dragonBones::BoneData *boneData, dragonBones::Armature *armatureValue)')
cls.func(nil, 'void update(int cacheFrameIndex)')
cls.func(nil, 'void updateByConstraint()')
cls.func(nil, 'void invalidUpdate()')
cls.func(nil, 'bool contains(const dragonBones::Bone *value)')
cls.func(nil, 'const dragonBones::BoneData *getBoneData()')
cls.func(nil, 'bool getVisible()')
cls.func(nil, 'void setVisible(bool value)')
cls.func(nil, 'const std::string &getName()')
cls.func(nil, 'dragonBones::Bone *getParent()')
cls.func(nil, 'int getOffsetMode()')
cls.func(nil, 'void setOffsetMode(int value)')
cls.var('offsetMode', 'dragonBones::OffsetMode offsetMode')
cls.prop('typeIndex', nil, nil)
cls.prop('boneData', nil, nil)
cls.prop('visible', nil, nil)
cls.prop('name', nil, nil)
cls.prop('parent', nil, nil)
cls.prop('offsetMode', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::DisplayData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'int getType()')
cls.func(nil, 'void setType(int value)')
cls.func(nil, 'dragonBones::SkinData *getParent()')
cls.func(nil, 'void setParent(dragonBones::SkinData *value)')
cls.var('type', 'dragonBones::DisplayType type')
cls.var('name', 'std::string name')
cls.var('path', 'std::string path')
cls.var('parent', 'dragonBones::SkinData *parent')
cls.prop('type', nil, nil)
cls.prop('parent', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ActionData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'ActionData()')
cls.func(nil, 'int getType()')
cls.func(nil, 'void setType(int value)')
cls.func(nil, 'const dragonBones::BoneData *getBone()')
cls.func(nil, 'void setBone(const dragonBones::BoneData *value)')
cls.func(nil, 'const dragonBones::SlotData *getSlot()')
cls.func(nil, 'void setSlot(const dragonBones::SlotData *value)')
cls.func(nil, 'const dragonBones::UserData *getData()')
cls.func(nil, 'void setData(dragonBones::UserData *value)')
cls.var('type', 'dragonBones::ActionType type')
cls.var('name', 'std::string name')
cls.var('bone', 'const dragonBones::BoneData *bone')
cls.var('slot', 'const dragonBones::SlotData *slot')
cls.var('data', 'dragonBones::UserData *data')
cls.prop('typeIndex', nil, nil)
cls.prop('type', nil, nil)
cls.prop('bone', nil, nil)
cls.prop('slot', nil, nil)
cls.prop('data', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::UserData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'UserData()')
cls.func(nil, 'void addInt(int value)')
cls.func(nil, 'void addFloat(float value)')
cls.func(nil, 'void addString(std::string value)')
cls.func(nil, 'int getInt(unsigned int index)')
cls.func(nil, 'float getFloat(unsigned int index)')
cls.func(nil, 'std::string getString(unsigned int index)')
cls.func(nil, 'const std::vector<int> &getInts()')
cls.func(nil, 'const std::vector<float> &getFloats()')
cls.func(nil, 'const std::vector<std::string> &getStrings()')
cls.var('ints', 'std::vector<int> ints')
cls.var('floats', 'std::vector<float> floats')
cls.var('strings', 'std::vector<std::string> strings')
cls.prop('typeIndex', nil, nil)
cls.prop('ints', nil, nil)
cls.prop('floats', nil, nil)
cls.prop('strings', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BoundingBoxData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'bool containsPoint(float pX, float pY)')
cls.func(nil, 'int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)')
cls.func(nil, 'int getType()')
cls.func(nil, 'void setType(int value)')
cls.var('type', 'dragonBones::BoundingBoxType type')
cls.var('color', 'unsigned int color')
cls.var('width', 'float width')
cls.var('height', 'float height')
cls.prop('type', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BoundingBoxDisplayData'
cls.SUPERCLS = 'dragonBones::DisplayData'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'BoundingBoxDisplayData()')
cls.func(nil, 'const dragonBones::BoundingBoxData *getBoundingBox()')
cls.func(nil, 'void setBoundingBox(dragonBones::BoundingBoxData *value)')
cls.var('boundingBox', 'dragonBones::BoundingBoxData *boundingBox')
cls.prop('typeIndex', nil, nil)
cls.prop('boundingBox', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::CanvasData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'CanvasData()')
cls.var('hasBackground', 'bool hasBackground')
cls.var('color', 'unsigned int color')
cls.var('aabb', 'dragonBones::Rectangle aabb')
cls.prop('typeIndex', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TextureAtlasData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'dragonBones::TextureData *createTexture()')
cls.func(nil, 'void addTexture(dragonBones::TextureData *value)')
cls.func(nil, 'dragonBones::TextureData *getTexture(const std::string &textureName)')
cls.var('autoSearch', 'bool autoSearch')
cls.var('format', 'dragonBones::TextureFormat format')
cls.var('width', 'unsigned int width')
cls.var('height', 'unsigned int height')
cls.var('scale', 'float scale')
cls.var('name', 'std::string name')
cls.var('imagePath', 'std::string imagePath')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::TextureData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'const dragonBones::TextureAtlasData *getParent()')
cls.func(nil, 'void setParent(dragonBones::TextureAtlasData *value)')
cls.var('rotated', 'bool rotated')
cls.var('name', 'std::string name')
cls.var('region', 'dragonBones::Rectangle region')
cls.var('parent', 'dragonBones::TextureAtlasData *parent')
cls.prop('parent', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::ArmatureData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'ArmatureData()')
cls.func(nil, 'void sortBones()')
cls.func(nil, 'void cacheFrames(unsigned int frameRate)')
cls.func(nil, 'void addBone(dragonBones::BoneData *value)')
cls.func(nil, 'void addSlot(dragonBones::SlotData *value)')
cls.func(nil, 'void addConstraint(dragonBones::ConstraintData *value)')
cls.func(nil, 'void addSkin(dragonBones::SkinData *value)')
cls.func(nil, 'void addAnimation(dragonBones::AnimationData *value)')
cls.func(nil, 'void addAction(dragonBones::ActionData *value, bool isDefault)')
cls.func(nil, 'dragonBones::BoneData *getBone(const std::string &boneName)')
cls.func(nil, 'dragonBones::SlotData *getSlot(const std::string &slotName)')
cls.func(nil, 'dragonBones::ConstraintData *getConstraint(const std::string &constraintName)')
cls.func(nil, 'dragonBones::SkinData *getSkin(const std::string &skinName)')
cls.func(nil, 'dragonBones::AnimationData *getAnimation(const std::string &animationName)')
cls.func(nil, 'int getType()')
cls.func(nil, 'void setType(int value)')
cls.func(nil, 'const std::vector<std::string> &getAnimationNames()')
cls.func(nil, 'const std::vector<BoneData *> &getSortedBones()')
cls.func(nil, 'const std::vector<SlotData *> &getSortedSlots()')
cls.func(nil, 'const std::vector<ActionData *> &getDefaultActions()')
cls.func(nil, 'const std::vector<ActionData *> &getActions()')
cls.func(nil, 'dragonBones::SkinData *getDefaultSkin()')
cls.func(nil, 'void setDefaultSkin(dragonBones::SkinData *value)')
cls.func(nil, 'dragonBones::AnimationData *getDefaultAnimation()')
cls.func(nil, 'void setDefaultAnimation(dragonBones::AnimationData *value)')
cls.func(nil, 'const dragonBones::UserData *getUserData()')
cls.func(nil, 'void setUserData(dragonBones::UserData *value)')
cls.func(nil, 'const dragonBones::DragonBonesData *getParent()')
cls.func(nil, 'void setParent(dragonBones::DragonBonesData *value)')
cls.var('type', 'dragonBones::ArmatureType type')
cls.var('frameRate', 'unsigned int frameRate')
cls.var('cacheFrameRate', 'unsigned int cacheFrameRate')
cls.var('scale', 'float scale')
cls.var('name', 'std::string name')
cls.var('aabb', 'dragonBones::Rectangle aabb')
cls.var('animationNames', 'std::vector<std::string> animationNames')
cls.var('sortedBones', 'std::vector<BoneData *> sortedBones')
cls.var('sortedSlots', 'std::vector<SlotData *> sortedSlots')
cls.var('defaultActions', 'std::vector<ActionData *> defaultActions')
cls.var('actions', 'std::vector<ActionData *> actions')
cls.var('defaultSkin', 'dragonBones::SkinData *defaultSkin')
cls.var('defaultAnimation', 'dragonBones::AnimationData *defaultAnimation')
cls.var('userData', 'dragonBones::UserData *userData')
cls.var('parent', 'dragonBones::DragonBonesData *parent')
cls.prop('typeIndex', nil, nil)
cls.prop('type', nil, nil)
cls.prop('animationNames', nil, nil)
cls.prop('sortedBones', nil, nil)
cls.prop('sortedSlots', nil, nil)
cls.prop('defaultActions', nil, nil)
cls.prop('actions', nil, nil)
cls.prop('defaultSkin', nil, nil)
cls.prop('defaultAnimation', nil, nil)
cls.prop('userData', nil, nil)
cls.prop('parent', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::SkinData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'SkinData()')
cls.func(nil, 'void addDisplay(const std::string &slotName, dragonBones::DisplayData *value)')
cls.func(nil, 'dragonBones::DisplayData *getDisplay(const std::string &slotName, const std::string &displayName)')
cls.var('name', 'std::string name')
cls.var('parent', 'dragonBones::ArmatureData *parent')
cls.prop('typeIndex', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BoneData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'BoneData()')
cls.func(nil, 'const dragonBones::UserData *getUserData()')
cls.func(nil, 'void setUserData(dragonBones::UserData *value)')
cls.func(nil, 'const dragonBones::BoneData *getParent()')
cls.func(nil, 'void setParent(dragonBones::BoneData *value)')
cls.var('inheritTranslation', 'bool inheritTranslation')
cls.var('inheritRotation', 'bool inheritRotation')
cls.var('inheritScale', 'bool inheritScale')
cls.var('inheritReflection', 'bool inheritReflection')
cls.var('length', 'float length')
cls.var('name', 'std::string name')
cls.var('userData', 'dragonBones::UserData *userData')
cls.var('parent', 'dragonBones::BoneData *parent')
cls.prop('typeIndex', nil, nil)
cls.prop('userData', nil, nil)
cls.prop('parent', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::SlotData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'SlotData()')
cls.func(nil, 'int getBlendMode()')
cls.func(nil, 'void setBlendMode(int value)')
cls.func(nil, 'const dragonBones::BoneData *getParent()')
cls.func(nil, 'void setParent(dragonBones::BoneData *value)')
cls.func(nil, 'const dragonBones::UserData *getUserData()')
cls.func(nil, 'void setUserData(dragonBones::UserData *value)')
cls.var('blendMode', 'dragonBones::BlendMode blendMode')
cls.var('displayIndex', 'int displayIndex')
cls.var('zOrder', 'int zOrder')
cls.var('name', 'std::string name')
cls.var('userData', 'dragonBones::UserData *userData')
cls.var('parent', 'dragonBones::BoneData *parent')
cls.prop('typeIndex', nil, nil)
cls.prop('blendMode', nil, nil)
cls.prop('parent', nil, nil)
cls.prop('userData', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::AnimationState'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'AnimationState()')
cls.func(nil, 'void init(dragonBones::Armature *armature, dragonBones::AnimationData *animationData, dragonBones::AnimationConfig *animationConfig)')
cls.func(nil, 'void advanceTime(float passedTime, float cacheFrameRate)')
cls.func(nil, 'void play()')
cls.func(nil, 'void stop()')
cls.func(nil, 'void fadeOut(float fadeOutTime, @optional bool pausePlayhead)')
cls.func(nil, 'bool containsBoneMask(const std::string &boneName)')
cls.func(nil, 'void addBoneMask(const std::string &boneName, @optional bool recursive)')
cls.func(nil, 'void removeBoneMask(const std::string &boneName, @optional bool recursive)')
cls.func(nil, 'void removeAllBoneMask()')
cls.func(nil, 'bool isFadeIn()')
cls.func(nil, 'bool isFadeOut()')
cls.func(nil, 'bool isFadeComplete()')
cls.func(nil, 'bool isPlaying()')
cls.func(nil, 'bool isCompleted()')
cls.func(nil, 'unsigned int getCurrentPlayTimes()')
cls.func(nil, 'float getTotalTime()')
cls.func(nil, 'float getCurrentTime()')
cls.func(nil, 'void setCurrentTime(float value)')
cls.func(nil, 'const std::string &getName()')
cls.func(nil, 'const dragonBones::AnimationData *getAnimationData()')
cls.var('actionEnabled', 'bool actionEnabled')
cls.var('additiveBlending', 'bool additiveBlending')
cls.var('displayControl', 'bool displayControl')
cls.var('resetToPose', 'bool resetToPose')
cls.var('playTimes', 'unsigned int playTimes')
cls.var('layer', 'unsigned int layer')
cls.var('timeScale', 'float timeScale')
cls.var('weight', 'float weight')
cls.var('autoFadeOutTime', 'float autoFadeOutTime')
cls.var('fadeTotalTime', 'float fadeTotalTime')
cls.var('name', 'std::string name')
cls.var('group', 'std::string group')
cls.prop('typeIndex', nil, nil)
cls.prop('fadeIn', nil, nil)
cls.prop('fadeOut', nil, nil)
cls.prop('fadeComplete', nil, nil)
cls.prop('playing', nil, nil)
cls.prop('completed', nil, nil)
cls.prop('currentPlayTimes', nil, nil)
cls.prop('totalTime', nil, nil)
cls.prop('currentTime', nil, nil)
cls.prop('name', nil, nil)
cls.prop('animationData', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::AnimationData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'AnimationData()')
cls.func(nil, 'void cacheFrames(unsigned int frameRate)')
cls.func(nil, 'void addBoneTimeline(dragonBones::BoneData *bone, dragonBones::TimelineData *value)')
cls.func(nil, 'void addSlotTimeline(dragonBones::SlotData *slot, dragonBones::TimelineData *value)')
cls.func(nil, 'void addConstraintTimeline(dragonBones::ConstraintData *constraint, dragonBones::TimelineData *value)')
cls.func(nil, 'dragonBones::TimelineData *getActionTimeline()')
cls.func(nil, 'void setActionTimeline(dragonBones::TimelineData *pactionTimeline)')
cls.func(nil, 'dragonBones::TimelineData *getZOrderTimeline()')
cls.func(nil, 'void setZOrderTimeline(dragonBones::TimelineData *value)')
cls.func(nil, 'dragonBones::ArmatureData *getParent()')
cls.func(nil, 'void setParent(dragonBones::ArmatureData *value)')
cls.var('frameIntOffset', 'unsigned int frameIntOffset')
cls.var('frameFloatOffset', 'unsigned int frameFloatOffset')
cls.var('frameOffset', 'unsigned int frameOffset')
cls.var('frameCount', 'unsigned int frameCount')
cls.var('playTimes', 'unsigned int playTimes')
cls.var('duration', 'float duration')
cls.var('scale', 'float scale')
cls.var('fadeInTime', 'float fadeInTime')
cls.var('cacheFrameRate', 'float cacheFrameRate')
cls.var('name', 'std::string name')
cls.var('cachedFrames', 'std::vector<bool> cachedFrames')
cls.var('actionTimeline', 'dragonBones::TimelineData *actionTimeline')
cls.var('zOrderTimeline', 'dragonBones::TimelineData *zOrderTimeline')
cls.var('parent', 'dragonBones::ArmatureData *parent')
cls.prop('typeIndex', nil, nil)
cls.prop('actionTimeline', nil, nil)
cls.prop('zOrderTimeline', nil, nil)
cls.prop('parent', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::AnimationConfig'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'AnimationConfig()')
cls.func(nil, 'void clear()')
cls.func(nil, 'void copyFrom(dragonBones::AnimationConfig *value)')
cls.func(nil, 'bool containsBoneMask(const std::string &boneName)')
cls.func(nil, 'void addBoneMask(dragonBones::Armature *armature, const std::string &boneName, bool recursive)')
cls.func(nil, 'void removeBoneMask(dragonBones::Armature *armature, const std::string &boneName, bool recursive)')
cls.func(nil, 'int getFadeOutMode()')
cls.func(nil, 'void setFadeOutMode(int value)')
cls.func(nil, 'int getFadeOutTweenType()')
cls.func(nil, 'void setFadeOutTweenType(int value)')
cls.func(nil, 'int getFadeInTweenType()')
cls.func(nil, 'void setFadeInTweenType(int value)')
cls.var('pauseFadeOut', 'bool pauseFadeOut')
cls.var('fadeOutMode', 'dragonBones::AnimationFadeOutMode fadeOutMode')
cls.var('fadeOutTweenType', 'dragonBones::TweenType fadeOutTweenType')
cls.var('fadeOutTime', 'float fadeOutTime')
cls.var('actionEnabled', 'bool actionEnabled')
cls.var('additiveBlending', 'bool additiveBlending')
cls.var('displayControl', 'bool displayControl')
cls.var('pauseFadeIn', 'bool pauseFadeIn')
cls.var('resetToPose', 'bool resetToPose')
cls.var('fadeInTweenType', 'dragonBones::TweenType fadeInTweenType')
cls.var('playTimes', 'int playTimes')
cls.var('layer', 'int layer')
cls.var('position', 'float position')
cls.var('duration', 'float duration')
cls.var('timeScale', 'float timeScale')
cls.var('weight', 'float weight')
cls.var('fadeInTime', 'float fadeInTime')
cls.var('autoFadeOutTime', 'float autoFadeOutTime')
cls.var('name', 'std::string name')
cls.var('animation', 'std::string animation')
cls.var('group', 'std::string group')
cls.var('boneMask', 'std::vector<std::string> boneMask')
cls.prop('typeIndex', nil, nil)
cls.prop('fadeOutMode', nil, nil)
cls.prop('fadeOutTweenType', nil, nil)
cls.prop('fadeInTweenType', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::DragonBonesData'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'DragonBonesData()')
cls.func(nil, 'void addArmature(dragonBones::ArmatureData *value)')
cls.func(nil, 'dragonBones::ArmatureData *getArmature(const std::string &armatureName)')
cls.func(nil, 'const std::vector<std::string> &getArmatureNames()')
cls.func(nil, 'const dragonBones::UserData *getUserData()')
cls.func(nil, 'void setUserData(dragonBones::UserData *value)')
cls.var('autoSearch', 'bool autoSearch')
cls.var('frameRate', 'unsigned int frameRate')
cls.var('version', 'std::string version')
cls.var('name', 'std::string name')
cls.var('frameIndices', 'std::vector<unsigned int> frameIndices')
cls.var('cachedFrames', 'std::vector<float> cachedFrames')
cls.var('armatureNames', 'std::vector<std::string> armatureNames')
cls.var('binary', 'const char *binary')
cls.var('userData', 'dragonBones::UserData *userData')
cls.prop('typeIndex', nil, nil)
cls.prop('armatureNames', nil, nil)
cls.prop('userData', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::BaseFactory'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name, @optional float scale)')
cls.func(nil, 'dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name, @optional float scale)')
cls.func(nil, 'dragonBones::DragonBonesData *getDragonBonesData(const std::string &name)')
cls.func(nil, 'void addDragonBonesData(dragonBones::DragonBonesData *data, @optional const std::string &name)')
cls.func(nil, 'void removeDragonBonesData(const std::string &name, @optional bool disposeData)')
cls.func(nil, 'void addTextureAtlasData(dragonBones::TextureAtlasData *data, @optional const std::string &name)')
cls.func(nil, 'void removeTextureAtlasData(const std::string &name, @optional bool disposeData)')
cls.func(nil, 'dragonBones::ArmatureData *getArmatureData(const std::string &name, @optional const std::string &dragonBonesName)')
cls.func(nil, 'void clear(@optional bool disposeData)')
cls.func(nil, 'dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)')
cls.func(nil, 'void replaceDisplay(dragonBones::Slot *slot, dragonBones::DisplayData *displayData, int displayIndex)')
cls.func(nil, 'bool replaceSlotDisplay(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, const std::string &displayName, dragonBones::Slot *slot, @optional int displayIndex)')
cls.func(nil, 'bool replaceSlotDisplayList(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, dragonBones::Slot *slot)')
cls.func(nil, 'bool replaceAnimation(dragonBones::Armature *armature, dragonBones::ArmatureData *armatureData, @optional bool isReplaceAll)')
cls.func(nil, 'dragonBones::WorldClock *getClock()')
cls.var('autoSearch', 'bool autoSearch')
cls.prop('clock', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::Armature'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'Armature()')
cls.func(nil, 'void dispose()')
cls.func(nil, 'void advanceTime(float passedTime)')
cls.func(nil, 'void invalidUpdate(@optional const std::string &boneName, @optional bool updateSlot)')
cls.func(nil, 'dragonBones::Slot *containsPoint(float x, float y)')
cls.func(nil, 'dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)')
cls.func(nil, 'dragonBones::Bone *getBone(const std::string &name)')
cls.func(nil, 'dragonBones::Bone *getBoneByDisplay(void *display)')
cls.func(nil, 'dragonBones::Slot *getSlot(const std::string &name)')
cls.func(nil, 'dragonBones::Slot *getSlotByDisplay(void *display)')
cls.func(nil, 'const std::vector<Bone *> &getBones()')
cls.func(nil, 'const std::vector<Slot *> &getSlots()')
cls.func(nil, 'bool getFlipX()')
cls.func(nil, 'void setFlipX(bool value)')
cls.func(nil, 'bool getFlipY()')
cls.func(nil, 'void setFlipY(bool value)')
cls.func(nil, 'unsigned int getCacheFrameRate()')
cls.func(nil, 'void setCacheFrameRate(unsigned int value)')
cls.func(nil, 'const std::string &getName()')
cls.func(nil, 'const dragonBones::ArmatureData *getArmatureData()')
cls.func(nil, 'dragonBones::Animation *getAnimation()')
cls.func(nil, 'void *getDisplay()')
cls.func(nil, 'void *getReplacedTexture()')
cls.func(nil, 'void setReplacedTexture(void *value)')
cls.func(nil, 'dragonBones::WorldClock *getClock()')
cls.func(nil, 'void setClock(dragonBones::WorldClock *value)')
cls.func(nil, 'dragonBones::Slot *getParent()')
cls.func(nil, 'dragonBones::IAnimatable *getAnimatable()')
cls.var('inheritAnimation', 'bool inheritAnimation')
cls.var('userData', 'void *userData')
cls.prop('typeIndex', nil, nil)
cls.prop('bones', nil, nil)
cls.prop('slots', nil, nil)
cls.prop('flipX', nil, nil)
cls.prop('flipY', nil, nil)
cls.prop('cacheFrameRate', nil, nil)
cls.prop('name', nil, nil)
cls.prop('armatureData', nil, nil)
cls.prop('animation', nil, nil)
cls.prop('display', nil, nil)
cls.prop('replacedTexture', nil, nil)
cls.prop('clock', nil, nil)
cls.prop('parent', nil, nil)
cls.prop('animatable', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::Animation'
cls.SUPERCLS = 'dragonBones::BaseObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static std::size_t getTypeIndex()')
cls.func(nil, 'Animation()')
cls.func(nil, 'void init(dragonBones::Armature *armature)')
cls.func(nil, 'void advanceTime(float passedTime)')
cls.func(nil, 'void reset()')
cls.func(nil, 'void stop(const std::string &animationName)')
cls.func(nil, 'dragonBones::AnimationState *playConfig(dragonBones::AnimationConfig *animationConfig)')
cls.func(nil, 'dragonBones::AnimationState *play(@optional const std::string &animationName, @optional int playTimes)')
cls.func(nil, 'dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)')
cls.func(nil, 'dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time, @optional int playTimes)')
cls.func(nil, 'dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame, @optional int playTimes)')
cls.func(nil, 'dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress, @optional int playTimes)')
cls.func(nil, 'dragonBones::AnimationState *gotoAndStopByTime(const std::string &animationName, @optional float time)')
cls.func(nil, 'dragonBones::AnimationState *gotoAndStopByFrame(const std::string &animationName, @optional unsigned int frame)')
cls.func(nil, 'dragonBones::AnimationState *gotoAndStopByProgress(const std::string &animationName, @optional float progress)')
cls.func(nil, 'dragonBones::AnimationState *getState(const std::string &animationName)')
cls.func(nil, 'bool hasAnimation(const std::string &animationName)')
cls.func(nil, 'const std::vector<AnimationState *> &getStates()')
cls.func(nil, 'bool isPlaying()')
cls.func(nil, 'bool isCompleted()')
cls.func(nil, 'const std::string &getLastAnimationName()')
cls.func(nil, 'const std::vector<std::string> &getAnimationNames()')
cls.func(nil, 'dragonBones::AnimationConfig *getAnimationConfig()')
cls.func(nil, 'dragonBones::AnimationState *getLastAnimationState()')
cls.var('timeScale', 'float timeScale')
cls.prop('typeIndex', nil, nil)
cls.prop('states', nil, nil)
cls.prop('playing', nil, nil)
cls.prop('completed', nil, nil)
cls.prop('lastAnimationName', nil, nil)
cls.prop('animationNames', nil, nil)
cls.prop('animationConfig', nil, nil)
cls.prop('lastAnimationState', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::CCFactory'
cls.SUPERCLS = 'dragonBones::BaseFactory'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static dragonBones::CCFactory *getFactory()')
cls.func(nil, 'CCFactory()')
cls.func(nil, 'dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name, @optional float scale)')
cls.func(nil, 'dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name, @optional float scale)')
cls.func(nil, 'dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)')
cls.func(nil, 'cocos2d::Sprite *getTextureDisplay(const std::string &textureName, @optional const std::string &dragonBonesName)')
cls.func(nil, 'dragonBones::CCArmatureDisplay *getSoundEventManager()')
cls.func(nil, 'static dragonBones::WorldClock *getClock()')
cls.prop('factory', nil, nil)
cls.prop('soundEventManager', nil, nil)
cls.prop('clock', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'dragonBones::CCArmatureDisplay'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static dragonBones::CCArmatureDisplay *create()')
cls.func(nil, 'CCArmatureDisplay()')
cls.func(nil, 'void dbInit(dragonBones::Armature *armature)')
cls.func(nil, 'void dbClear()')
cls.func(nil, 'void dbUpdate()')
cls.func(nil, 'void dispose(@optional bool disposeProxy)')
cls.func(nil, 'bool hasDBEventListener(const std::string &type)')
cls.func(nil, 'void dispatchDBEvent(const std::string &type, dragonBones::EventObject *value)')
cls.func(nil, 'dragonBones::Armature *getArmature()')
cls.func(nil, 'dragonBones::Animation *getAnimation()')
cls.var('debugDraw', 'bool debugDraw')
cls.callback {
    FUNCS =  {
        'void addDBEventListener(const std::string &type, @local const std::function<void (EventObject *)> &listener)'
    },
    TAG_MAKER = '(#1)',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void removeDBEventListener(const std::string &type, @nullable @local const std::function<void (EventObject *)> &listener)'
    },
    TAG_MAKER = '(#1)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('armature', nil, nil)
cls.prop('animation', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

return M
