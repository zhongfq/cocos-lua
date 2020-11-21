-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/spine-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "spine"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "xgame/xlua.h"
    #include "cocos2d.h"
    #include "spine/spine-cocos2dx.h"
]]
M.CHUNK = [[
    bool manual_olua_is_spine_String(lua_State *L, int idx)
    {
        return olua_isstring(L, idx);
    }

    int manual_olua_push_spine_String(lua_State *L, const spine::String *value)
    {
        if (value && value->buffer()) {
            lua_pushlstring(L, value->buffer(), value->length());
        } else {
            lua_pushnil(L);
        }
        return 1;
    }

    void manual_olua_check_spine_String(lua_State *L, int idx, spine::String *value)
    {
        if (!value) {
            luaL_error(L, "value is NULL");
        }
        *value = olua_checkstring(L, idx);
    }

    bool manual_olua_is_spine_Color(lua_State *L, int idx)
    {
        return olua_isinteger(L, idx);
    }

    void manual_olua_check_spine_Color(lua_State *L, int idx, spine::Color *value)
    {
        if (!value) {
            luaL_error(L, "value is NULL");
        }
        uint32_t color = (uint32_t)olua_checkinteger(L, idx);
        value->r = ((uint8_t)(color >> 24 & 0xFF)) / 255.0f;
        value->g = ((uint8_t)(color >> 16 & 0xFF)) / 255.0f;
        value->b = ((uint8_t)(color >> 8 & 0xFF)) / 255.0f;
        value->a = ((uint8_t)(color & 0xFF)) / 255.0f;
    }

    int manual_olua_push_spine_Color(lua_State *L, const spine::Color *value)
    {
        uint32_t color = 0;
        if (value) {
            color |= (uint32_t)((uint8_t)(value->r * 255)) << 24;
            color |= (uint32_t)((uint8_t)(value->g * 255)) << 16;
            color |= (uint32_t)((uint8_t)(value->b * 255)) << 8;
            color |= (uint32_t)((uint8_t)(value->a * 255));
        }
        lua_pushinteger(L, color);
        return 1;
    }

    int manual_olua_push_spine_EventData(lua_State *L, const spine::EventData *value)
    {
        lua_createtable(L, 0, 8);
        olua_setfieldinteger(L, -1, "intValue", const_cast<spine::EventData *>(value)->getIntValue());
        olua_setfieldnumber(L, -1, "getVolume", const_cast<spine::EventData *>(value)->getVolume());
        olua_setfieldnumber(L, -1, "getBalance", const_cast<spine::EventData *>(value)->getBalance());
        manual_olua_push_spine_String(L, &value->getName());
        olua_rawsetf(L, -2, "name");
        manual_olua_push_spine_String(L, &const_cast<spine::EventData *>(value)->getStringValue());
        olua_rawsetf(L, -2, "stringValue");
        manual_olua_push_spine_String(L, &const_cast<spine::EventData *>(value)->getAudioPath());
        olua_rawsetf(L, -2, "audioPath");
        return 1;
    }

    template <typename T> int manual_olua_push_spine_Vector(lua_State *L, const spine::Vector<T*> &v, const char *cls)
    {
        lua_newtable(L);
        int count = 1;
        for (int i = 0; i < (int)v.size(); i++) {
            auto obj = ((spine::Vector<T*> &)v)[i];
            if (obj == nullptr) {
                continue;
            }
            olua_push_cppobj(L, obj, cls);
            lua_rawseti(L, -2, count++);
        }
        return 1;
    }

    template <typename T> void manual_olua_check_spine_Vector(lua_State *L, int idx, spine::Vector<T*> &v, const char *cls)
    {
        luaL_checktype(L, idx, LUA_TTABLE);
        int total = (int)lua_rawlen(L, idx);
        v.ensureCapacity((size_t)total);
        for (int i = 1; i <= total; i++) {
            lua_rawgeti(L, idx, i);
            T* obj;
            olua_check_cppobj(L, -1, (void **)&obj, cls);
            v.add(obj);
            lua_pop(L, 1);
        }
    }
]]

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'spine::EventType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Start', 'spine::EventType::EventType_Start')
cls.enum('Interrupt', 'spine::EventType::EventType_Interrupt')
cls.enum('End', 'spine::EventType::EventType_End')
cls.enum('Complete', 'spine::EventType::EventType_Complete')
cls.enum('Dispose', 'spine::EventType::EventType_Dispose')
cls.enum('Event', 'spine::EventType::EventType_Event')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::AttachmentType'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Region', 'spine::AttachmentType::AttachmentType_Region')
cls.enum('Boundingbox', 'spine::AttachmentType::AttachmentType_Boundingbox')
cls.enum('Mesh', 'spine::AttachmentType::AttachmentType_Mesh')
cls.enum('Linkedmesh', 'spine::AttachmentType::AttachmentType_Linkedmesh')
cls.enum('Path', 'spine::AttachmentType::AttachmentType_Path')
cls.enum('Point', 'spine::AttachmentType::AttachmentType_Point')
cls.enum('Clipping', 'spine::AttachmentType::AttachmentType_Clipping')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TransformMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Normal', 'spine::TransformMode::TransformMode_Normal')
cls.enum('OnlyTranslation', 'spine::TransformMode::TransformMode_OnlyTranslation')
cls.enum('NoRotationOrReflection', 'spine::TransformMode::TransformMode_NoRotationOrReflection')
cls.enum('NoScale', 'spine::TransformMode::TransformMode_NoScale')
cls.enum('NoScaleOrReflection', 'spine::TransformMode::TransformMode_NoScaleOrReflection')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::BlendMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Normal', 'spine::BlendMode::BlendMode_Normal')
cls.enum('Additive', 'spine::BlendMode::BlendMode_Additive')
cls.enum('Multiply', 'spine::BlendMode::BlendMode_Multiply')
cls.enum('Screen', 'spine::BlendMode::BlendMode_Screen')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PositionMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Fixed', 'spine::PositionMode::PositionMode_Fixed')
cls.enum('Percent', 'spine::PositionMode::PositionMode_Percent')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SpacingMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Length', 'spine::SpacingMode::SpacingMode_Length')
cls.enum('Fixed', 'spine::SpacingMode::SpacingMode_Fixed')
cls.enum('Percent', 'spine::SpacingMode::SpacingMode_Percent')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::RotateMode'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Tangent', 'spine::RotateMode::RotateMode_Tangent')
cls.enum('Chain', 'spine::RotateMode::RotateMode_Chain')
cls.enum('ChainScale', 'spine::RotateMode::RotateMode_ChainScale')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::MixBlend'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.enum('Setup', 'spine::MixBlend::MixBlend_Setup')
cls.enum('First', 'spine::MixBlend::MixBlend_First')
cls.enum('Replace', 'spine::MixBlend::MixBlend_Replace')
cls.enum('Add', 'spine::MixBlend::MixBlend_Add')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SpineObject'
cls.SUPERCLS = nil
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Event'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'const spine::EventData &getData()')
cls.func(nil, 'float getTime()')
cls.func(nil, 'int getIntValue()')
cls.func(nil, 'void setIntValue(int inValue)')
cls.func(nil, 'float getFloatValue()')
cls.func(nil, 'void setFloatValue(float inValue)')
cls.func(nil, 'const spine::String &getStringValue()')
cls.func(nil, 'void setStringValue(const spine::String &inValue)')
cls.func(nil, 'float getVolume()')
cls.func(nil, 'void setVolume(float inValue)')
cls.func(nil, 'float getBalance()')
cls.func(nil, 'void setBalance(float inValue)')
cls.prop('data', nil, nil)
cls.prop('time', nil, nil)
cls.prop('intValue', nil, nil)
cls.prop('floatValue', nil, nil)
cls.prop('stringValue', nil, nil)
cls.prop('volume', nil, nil)
cls.prop('balance', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::EventData'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'EventData(const spine::String &name)')
cls.func(nil, 'const spine::String &getName()')
cls.func(nil, 'int getIntValue()')
cls.func(nil, 'void setIntValue(int inValue)')
cls.func(nil, 'float getFloatValue()')
cls.func(nil, 'void setFloatValue(float inValue)')
cls.func(nil, 'const spine::String &getStringValue()')
cls.func(nil, 'void setStringValue(const spine::String &inValue)')
cls.func(nil, 'const spine::String &getAudioPath()')
cls.func(nil, 'void setAudioPath(const spine::String &inValue)')
cls.func(nil, 'float getVolume()')
cls.func(nil, 'void setVolume(float inValue)')
cls.func(nil, 'float getBalance()')
cls.func(nil, 'void setBalance(float inValue)')
cls.prop('name', nil, nil)
cls.prop('intValue', nil, nil)
cls.prop('floatValue', nil, nil)
cls.prop('stringValue', nil, nil)
cls.prop('audioPath', nil, nil)
cls.prop('volume', nil, nil)
cls.prop('balance', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Updatable'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void update()')
cls.func(nil, 'bool isActive()')
cls.func(nil, 'void setActive(bool inValue)')
cls.prop('active', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::AnimationState'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'AnimationState(spine::AnimationStateData *data)')
cls.func(nil, 'void update(float delta)')
cls.func(nil, 'void clearTracks()')
cls.func(nil, 'void clearTrack(size_t trackIndex)')
cls.func(nil, 'spine::TrackEntry *setAnimation(size_t trackIndex, const spine::String &animationName, bool loop)', 'spine::TrackEntry *setAnimation(size_t trackIndex, spine::Animation *animation, bool loop)')
cls.func(nil, 'spine::TrackEntry *addAnimation(size_t trackIndex, const spine::String &animationName, bool loop, float delay)', 'spine::TrackEntry *addAnimation(size_t trackIndex, spine::Animation *animation, bool loop, float delay)')
cls.func(nil, 'spine::TrackEntry *setEmptyAnimation(size_t trackIndex, float mixDuration)')
cls.func(nil, 'spine::TrackEntry *addEmptyAnimation(size_t trackIndex, float mixDuration, float delay)')
cls.func(nil, 'void setEmptyAnimations(float mixDuration)')
cls.func(nil, 'spine::TrackEntry *getCurrent(size_t trackIndex)')
cls.func(nil, 'spine::AnimationStateData *getData()')
cls.func(nil, 'Vector<spine::TrackEntry *> &getTracks()')
cls.func(nil, 'float getTimeScale()')
cls.func(nil, 'void setTimeScale(float inValue)')
cls.func(nil, 'void disableQueue()')
cls.func(nil, 'void enableQueue()')
cls.callback {
    FUNCS =  {
        'void setListener(std::function<void (AnimationState *, EventType, TrackEntry *, Event *)> listener)'
    },
    TAG_MAKER = 'Listener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('data', nil, nil)
cls.prop('tracks', nil, nil)
cls.prop('timeScale', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::AnimationStateData'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'AnimationStateData(spine::SkeletonData *skeletonData)')
cls.func(nil, 'spine::SkeletonData *getSkeletonData()')
cls.func(nil, 'float getDefaultMix()')
cls.func(nil, 'void setDefaultMix(float inValue)')
cls.func(nil, 'void setMix(const spine::String &fromName, const spine::String &toName, float duration)', 'void setMix(spine::Animation *from, spine::Animation *to, float duration)')
cls.func(nil, 'float getMix(spine::Animation *from, spine::Animation *to)')
cls.prop('skeletonData', nil, nil)
cls.prop('defaultMix', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Animation'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Animation(const spine::String &name, Vector<spine::Timeline *> &timelines, float duration)')
cls.func(nil, 'const spine::String &getName()')
cls.func(nil, 'Vector<spine::Timeline *> &getTimelines()')
cls.func(nil, 'bool hasTimeline(int id)')
cls.func(nil, 'float getDuration()')
cls.func(nil, 'void setDuration(float inValue)')
cls.prop('name', nil, nil)
cls.prop('timelines', nil, nil)
cls.prop('duration', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::ConstraintData'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'ConstraintData(const spine::String &name)')
cls.func(nil, 'const spine::String &getName()')
cls.func(nil, 'size_t getOrder()')
cls.func(nil, 'void setOrder(size_t inValue)')
cls.func(nil, 'bool isSkinRequired()')
cls.func(nil, 'void setSkinRequired(bool inValue)')
cls.prop('name', nil, nil)
cls.prop('order', nil, nil)
cls.prop('skinRequired', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::IkConstraintData'
cls.SUPERCLS = 'spine::ConstraintData'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'IkConstraintData(const spine::String &name)')
cls.func(nil, 'Vector<spine::BoneData *> &getBones()')
cls.func(nil, 'spine::BoneData *getTarget()')
cls.func(nil, 'void setTarget(spine::BoneData *inValue)')
cls.func(nil, 'int getBendDirection()')
cls.func(nil, 'void setBendDirection(int inValue)')
cls.func(nil, 'bool getCompress()')
cls.func(nil, 'void setCompress(bool inValue)')
cls.func(nil, 'bool getStretch()')
cls.func(nil, 'void setStretch(bool inValue)')
cls.func(nil, 'bool getUniform()')
cls.func(nil, 'void setUniform(bool inValue)')
cls.func(nil, 'float getMix()')
cls.func(nil, 'void setMix(float inValue)')
cls.func(nil, 'float getSoftness()')
cls.func(nil, 'void setSoftness(float inValue)')
cls.prop('bones', nil, nil)
cls.prop('target', nil, nil)
cls.prop('bendDirection', nil, nil)
cls.prop('compress', nil, nil)
cls.prop('stretch', nil, nil)
cls.prop('uniform', nil, nil)
cls.prop('mix', nil, nil)
cls.prop('softness', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::BoneData'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'BoneData(int index, const spine::String &name, @optional spine::BoneData *parent)')
cls.func(nil, 'int getIndex()')
cls.func(nil, 'const spine::String &getName()')
cls.func(nil, 'spine::BoneData *getParent()')
cls.func(nil, 'float getLength()')
cls.func(nil, 'void setLength(float inValue)')
cls.func(nil, 'float getX()')
cls.func(nil, 'void setX(float inValue)')
cls.func(nil, 'float getY()')
cls.func(nil, 'void setY(float inValue)')
cls.func(nil, 'float getRotation()')
cls.func(nil, 'void setRotation(float inValue)')
cls.func(nil, 'float getScaleX()')
cls.func(nil, 'void setScaleX(float inValue)')
cls.func(nil, 'float getScaleY()')
cls.func(nil, 'void setScaleY(float inValue)')
cls.func(nil, 'float getShearX()')
cls.func(nil, 'void setShearX(float inValue)')
cls.func(nil, 'float getShearY()')
cls.func(nil, 'void setShearY(float inValue)')
cls.func(nil, 'spine::TransformMode getTransformMode()')
cls.func(nil, 'void setTransformMode(spine::TransformMode inValue)')
cls.func(nil, 'bool isSkinRequired()')
cls.func(nil, 'void setSkinRequired(bool inValue)')
cls.prop('index', nil, nil)
cls.prop('name', nil, nil)
cls.prop('parent', nil, nil)
cls.prop('length', nil, nil)
cls.prop('x', nil, nil)
cls.prop('y', nil, nil)
cls.prop('rotation', nil, nil)
cls.prop('scaleX', nil, nil)
cls.prop('scaleY', nil, nil)
cls.prop('shearX', nil, nil)
cls.prop('shearY', nil, nil)
cls.prop('transformMode', nil, nil)
cls.prop('skinRequired', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SlotData'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'int getIndex()')
cls.func(nil, 'const spine::String &getName()')
cls.func(nil, 'spine::Color &getColor()')
cls.func(nil, 'spine::Color &getDarkColor()')
cls.func(nil, 'bool hasDarkColor()')
cls.func(nil, 'void setHasDarkColor(bool inValue)')
cls.func(nil, 'const spine::String &getAttachmentName()')
cls.func(nil, 'void setAttachmentName(const spine::String &inValue)')
cls.func(nil, 'spine::BlendMode getBlendMode()')
cls.func(nil, 'void setBlendMode(spine::BlendMode inValue)')
cls.prop('index', nil, nil)
cls.prop('name', nil, nil)
cls.prop('color', nil, nil)
cls.prop('darkColor', nil, nil)
cls.prop('attachmentName', nil, nil)
cls.prop('blendMode', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::IkConstraint'
cls.SUPERCLS = 'spine::Updatable'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void apply()')
cls.func(nil, 'int getOrder()')
cls.func(nil, 'Vector<spine::Bone *> &getBones()')
cls.func(nil, 'spine::Bone *getTarget()')
cls.func(nil, 'void setTarget(spine::Bone *inValue)')
cls.func(nil, 'int getBendDirection()')
cls.func(nil, 'void setBendDirection(int inValue)')
cls.func(nil, 'bool getCompress()')
cls.func(nil, 'void setCompress(bool inValue)')
cls.func(nil, 'bool getStretch()')
cls.func(nil, 'void setStretch(bool inValue)')
cls.func(nil, 'float getMix()')
cls.func(nil, 'void setMix(float inValue)')
cls.func(nil, 'float getSoftness()')
cls.func(nil, 'void setSoftness(float inValue)')
cls.prop('order', nil, nil)
cls.prop('bones', nil, nil)
cls.prop('target', nil, nil)
cls.prop('bendDirection', nil, nil)
cls.prop('compress', nil, nil)
cls.prop('stretch', nil, nil)
cls.prop('mix', nil, nil)
cls.prop('softness', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TransformConstraint'
cls.SUPERCLS = 'spine::Updatable'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void apply()')
cls.func(nil, 'int getOrder()')
cls.func(nil, 'Vector<spine::Bone *> &getBones()')
cls.func(nil, 'spine::Bone *getTarget()')
cls.func(nil, 'void setTarget(spine::Bone *inValue)')
cls.func(nil, 'float getRotateMix()')
cls.func(nil, 'void setRotateMix(float inValue)')
cls.func(nil, 'float getTranslateMix()')
cls.func(nil, 'void setTranslateMix(float inValue)')
cls.func(nil, 'float getScaleMix()')
cls.func(nil, 'void setScaleMix(float inValue)')
cls.func(nil, 'float getShearMix()')
cls.func(nil, 'void setShearMix(float inValue)')
cls.prop('order', nil, nil)
cls.prop('bones', nil, nil)
cls.prop('target', nil, nil)
cls.prop('rotateMix', nil, nil)
cls.prop('translateMix', nil, nil)
cls.prop('scaleMix', nil, nil)
cls.prop('shearMix', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TransformConstraintData'
cls.SUPERCLS = 'spine::ConstraintData'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'TransformConstraintData(const spine::String &name)')
cls.func(nil, 'Vector<spine::BoneData *> &getBones()')
cls.func(nil, 'spine::BoneData *getTarget()')
cls.func(nil, 'float getRotateMix()')
cls.func(nil, 'float getTranslateMix()')
cls.func(nil, 'float getScaleMix()')
cls.func(nil, 'float getShearMix()')
cls.func(nil, 'float getOffsetRotation()')
cls.func(nil, 'float getOffsetX()')
cls.func(nil, 'float getOffsetY()')
cls.func(nil, 'float getOffsetScaleX()')
cls.func(nil, 'float getOffsetScaleY()')
cls.func(nil, 'float getOffsetShearY()')
cls.func(nil, 'bool isRelative()')
cls.func(nil, 'bool isLocal()')
cls.prop('bones', nil, nil)
cls.prop('target', nil, nil)
cls.prop('rotateMix', nil, nil)
cls.prop('translateMix', nil, nil)
cls.prop('scaleMix', nil, nil)
cls.prop('shearMix', nil, nil)
cls.prop('offsetRotation', nil, nil)
cls.prop('offsetX', nil, nil)
cls.prop('offsetY', nil, nil)
cls.prop('offsetScaleX', nil, nil)
cls.prop('offsetScaleY', nil, nil)
cls.prop('offsetShearY', nil, nil)
cls.prop('relative', nil, nil)
cls.prop('local', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathConstraintData'
cls.SUPERCLS = 'spine::ConstraintData'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'PathConstraintData(const spine::String &name)')
cls.func(nil, 'Vector<spine::BoneData *> &getBones()')
cls.func(nil, 'spine::SlotData *getTarget()')
cls.func(nil, 'void setTarget(spine::SlotData *inValue)')
cls.func(nil, 'spine::PositionMode getPositionMode()')
cls.func(nil, 'void setPositionMode(spine::PositionMode inValue)')
cls.func(nil, 'spine::SpacingMode getSpacingMode()')
cls.func(nil, 'void setSpacingMode(spine::SpacingMode inValue)')
cls.func(nil, 'spine::RotateMode getRotateMode()')
cls.func(nil, 'void setRotateMode(spine::RotateMode inValue)')
cls.func(nil, 'float getOffsetRotation()')
cls.func(nil, 'void setOffsetRotation(float inValue)')
cls.func(nil, 'float getPosition()')
cls.func(nil, 'void setPosition(float inValue)')
cls.func(nil, 'float getSpacing()')
cls.func(nil, 'void setSpacing(float inValue)')
cls.func(nil, 'float getRotateMix()')
cls.func(nil, 'void setRotateMix(float inValue)')
cls.func(nil, 'float getTranslateMix()')
cls.func(nil, 'void setTranslateMix(float inValue)')
cls.prop('bones', nil, nil)
cls.prop('target', nil, nil)
cls.prop('positionMode', nil, nil)
cls.prop('spacingMode', nil, nil)
cls.prop('rotateMode', nil, nil)
cls.prop('offsetRotation', nil, nil)
cls.prop('position', nil, nil)
cls.prop('spacing', nil, nil)
cls.prop('rotateMix', nil, nil)
cls.prop('translateMix', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SkeletonBounds'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'SkeletonBounds()')
cls.func(nil, 'bool aabbcontainsPoint(float x, float y)')
cls.func(nil, 'bool aabbintersectsSegment(float x1, float y1, float x2, float y2)')
cls.func(nil, 'bool containsPoint(spine::Polygon *polygon, float x, float y)', 'spine::BoundingBoxAttachment *containsPoint(float x, float y)')
cls.func(nil, 'spine::BoundingBoxAttachment *intersectsSegment(float x1, float y1, float x2, float y2)', 'bool intersectsSegment(spine::Polygon *polygon, float x1, float y1, float x2, float y2)')
cls.func(nil, 'spine::Polygon *getPolygon(spine::BoundingBoxAttachment *attachment)')
cls.func(nil, 'float getWidth()')
cls.func(nil, 'float getHeight()')
cls.prop('width', nil, nil)
cls.prop('height', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SkeletonClipping'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Timeline'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'int getPropertyId()')
cls.prop('propertyId', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::CurveTimeline'
cls.SUPERCLS = 'spine::Timeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'size_t getFrameCount()')
cls.func(nil, 'void setLinear(size_t frameIndex)')
cls.func(nil, 'void setStepped(size_t frameIndex)')
cls.func(nil, 'void setCurve(size_t frameIndex, float cx1, float cy1, float cx2, float cy2)')
cls.func(nil, 'float getCurvePercent(size_t frameIndex, float percent)')
cls.func(nil, 'float getCurveType(size_t frameIndex)')
cls.prop('frameCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::AttachmentTimeline'
cls.SUPERCLS = 'spine::Timeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'AttachmentTimeline(int frameCount)')
cls.func(nil, 'size_t getSlotIndex()')
cls.func(nil, 'void setSlotIndex(size_t inValue)')
cls.func(nil, 'Vector<float> &getFrames()')
cls.func(nil, 'Vector<spine::String> &getAttachmentNames()')
cls.func(nil, 'size_t getFrameCount()')
cls.prop('slotIndex', nil, nil)
cls.prop('frames', nil, nil)
cls.prop('attachmentNames', nil, nil)
cls.prop('frameCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::ColorTimeline'
cls.SUPERCLS = 'spine::CurveTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('ENTRIES', 'spine::ColorTimeline::ENTRIES', 'const int')
cls.func(nil, 'ColorTimeline(int frameCount)')
cls.func(nil, 'int getSlotIndex()')
cls.func(nil, 'void setSlotIndex(int inValue)')
cls.func(nil, 'Vector<float> &getFrames()')
cls.prop('slotIndex', nil, nil)
cls.prop('frames', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::DeformTimeline'
cls.SUPERCLS = 'spine::CurveTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'DeformTimeline(int frameCount)')
cls.func(nil, 'int getSlotIndex()')
cls.func(nil, 'void setSlotIndex(int inValue)')
cls.func(nil, 'Vector<float> &getFrames()')
cls.func(nil, 'spine::VertexAttachment *getAttachment()')
cls.func(nil, 'void setAttachment(spine::VertexAttachment *inValue)')
cls.prop('slotIndex', nil, nil)
cls.prop('frames', nil, nil)
cls.prop('attachment', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::DrawOrderTimeline'
cls.SUPERCLS = 'spine::Timeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'DrawOrderTimeline(int frameCount)')
cls.func(nil, 'Vector<float> &getFrames()')
cls.func(nil, 'size_t getFrameCount()')
cls.prop('frames', nil, nil)
cls.prop('frameCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::EventTimeline'
cls.SUPERCLS = 'spine::Timeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'EventTimeline(int frameCount)')
cls.func(nil, 'Vector<float> getFrames()')
cls.func(nil, 'size_t getFrameCount()')
cls.prop('frames', nil, nil)
cls.prop('frameCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::IkConstraintTimeline'
cls.SUPERCLS = 'spine::CurveTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('ENTRIES', 'spine::IkConstraintTimeline::ENTRIES', 'const int')
cls.func(nil, 'IkConstraintTimeline(int frameCount)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathConstraintMixTimeline'
cls.SUPERCLS = 'spine::CurveTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('ENTRIES', 'spine::PathConstraintMixTimeline::ENTRIES', 'const int')
cls.func(nil, 'PathConstraintMixTimeline(int frameCount)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathConstraintPositionTimeline'
cls.SUPERCLS = 'spine::CurveTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('ENTRIES', 'spine::PathConstraintPositionTimeline::ENTRIES', 'const int')
cls.func(nil, 'PathConstraintPositionTimeline(int frameCount)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathConstraintSpacingTimeline'
cls.SUPERCLS = 'spine::PathConstraintPositionTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'PathConstraintSpacingTimeline(int frameCount)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TranslateTimeline'
cls.SUPERCLS = 'spine::CurveTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('ENTRIES', 'spine::TranslateTimeline::ENTRIES', 'const int')
cls.func(nil, 'TranslateTimeline(int frameCount)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::ShearTimeline'
cls.SUPERCLS = 'spine::TranslateTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'ShearTimeline(int frameCount)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TransformConstraintTimeline'
cls.SUPERCLS = 'spine::CurveTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('ENTRIES', 'spine::TransformConstraintTimeline::ENTRIES', 'const int')
cls.func(nil, 'TransformConstraintTimeline(int frameCount)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::ScaleTimeline'
cls.SUPERCLS = 'spine::TranslateTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'ScaleTimeline(int frameCount)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::RotateTimeline'
cls.SUPERCLS = 'spine::CurveTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('ENTRIES', 'spine::RotateTimeline::ENTRIES', 'const int')
cls.func(nil, 'RotateTimeline(int frameCount)')
cls.func(nil, 'int getBoneIndex()')
cls.func(nil, 'void setBoneIndex(int inValue)')
cls.func(nil, 'Vector<float> &getFrames()')
cls.prop('boneIndex', nil, nil)
cls.prop('frames', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TwoColorTimeline'
cls.SUPERCLS = 'spine::CurveTimeline'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('ENTRIES', 'spine::TwoColorTimeline::ENTRIES', 'const int')
cls.func(nil, 'TwoColorTimeline(int frameCount)')
cls.func(nil, 'int getSlotIndex()')
cls.func(nil, 'void setSlotIndex(int inValue)')
cls.prop('slotIndex', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::VertexEffect'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SwirlVertexEffect'
cls.SUPERCLS = 'spine::VertexEffect'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void setCenterX(float centerX)')
cls.func(nil, 'float getCenterX()')
cls.func(nil, 'void setCenterY(float centerY)')
cls.func(nil, 'float getCenterY()')
cls.func(nil, 'void setRadius(float radius)')
cls.func(nil, 'float getRadius()')
cls.func(nil, 'void setAngle(float angle)')
cls.func(nil, 'float getAngle()')
cls.func(nil, 'void setWorldX(float worldX)')
cls.func(nil, 'float getWorldX()')
cls.func(nil, 'void setWorldY(float worldY)')
cls.func(nil, 'float getWorldY()')
cls.prop('centerX', nil, nil)
cls.prop('centerY', nil, nil)
cls.prop('radius', nil, nil)
cls.prop('angle', nil, nil)
cls.prop('worldX', nil, nil)
cls.prop('worldY', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::JitterVertexEffect'
cls.SUPERCLS = 'spine::VertexEffect'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'JitterVertexEffect(float jitterX, float jitterY)')
cls.func(nil, 'void setJitterX(float jitterX)')
cls.func(nil, 'float getJitterX()')
cls.func(nil, 'void setJitterY(float jitterY)')
cls.func(nil, 'float getJitterY()')
cls.prop('jitterX', nil, nil)
cls.prop('jitterY', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Polygon'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Skin'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Skin(const spine::String &name)')
cls.func(nil, 'void setAttachment(size_t slotIndex, const spine::String &name, spine::Attachment *attachment)')
cls.func(nil, 'spine::Attachment *getAttachment(size_t slotIndex, const spine::String &name)')
cls.func(nil, 'void removeAttachment(size_t slotIndex, const spine::String &name)')
cls.func(nil, 'const spine::String &getName()')
cls.func(nil, 'void addSkin(spine::Skin *other)')
cls.func(nil, 'void copySkin(spine::Skin *other)')
cls.func(nil, 'Vector<spine::BoneData *> &getBones()')
cls.func(nil, 'Vector<spine::ConstraintData *> &getConstraints()')
cls.prop('name', nil, nil)
cls.prop('bones', nil, nil)
cls.prop('constraints', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Atlas'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Bone'
cls.SUPERCLS = 'spine::Updatable'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static void setYDown(bool inValue)')
cls.func(nil, 'static bool isYDown()')
cls.func(nil, 'void updateWorldTransform()', 'void updateWorldTransform(float x, float y, float rotation, float scaleX, float scaleY, float shearX, float shearY)')
cls.func(nil, 'void setToSetupPose()')
cls.func(nil, 'float worldToLocalRotation(float worldRotation)')
cls.func(nil, 'float localToWorldRotation(float localRotation)')
cls.func(nil, 'void rotateWorld(float degrees)')
cls.func(nil, 'float getWorldToLocalRotationX()')
cls.func(nil, 'float getWorldToLocalRotationY()')
cls.func(nil, 'spine::Bone *getParent()')
cls.func(nil, 'Vector<spine::Bone *> &getChildren()')
cls.func(nil, 'float getX()')
cls.func(nil, 'void setX(float inValue)')
cls.func(nil, 'float getY()')
cls.func(nil, 'void setY(float inValue)')
cls.func(nil, 'float getRotation()')
cls.func(nil, 'void setRotation(float inValue)')
cls.func(nil, 'float getScaleX()')
cls.func(nil, 'void setScaleX(float inValue)')
cls.func(nil, 'float getScaleY()')
cls.func(nil, 'void setScaleY(float inValue)')
cls.func(nil, 'float getShearX()')
cls.func(nil, 'void setShearX(float inValue)')
cls.func(nil, 'float getShearY()')
cls.func(nil, 'void setShearY(float inValue)')
cls.func(nil, 'float getAppliedRotation()')
cls.func(nil, 'void setAppliedRotation(float inValue)')
cls.func(nil, 'float getAX()')
cls.func(nil, 'void setAX(float inValue)')
cls.func(nil, 'float getAY()')
cls.func(nil, 'void setAY(float inValue)')
cls.func(nil, 'float getAScaleX()')
cls.func(nil, 'void setAScaleX(float inValue)')
cls.func(nil, 'float getAScaleY()')
cls.func(nil, 'void setAScaleY(float inValue)')
cls.func(nil, 'float getAShearX()')
cls.func(nil, 'void setAShearX(float inValue)')
cls.func(nil, 'float getAShearY()')
cls.func(nil, 'void setAShearY(float inValue)')
cls.func(nil, 'float getA()')
cls.func(nil, 'void setA(float inValue)')
cls.func(nil, 'float getB()')
cls.func(nil, 'void setB(float inValue)')
cls.func(nil, 'float getC()')
cls.func(nil, 'void setC(float inValue)')
cls.func(nil, 'float getD()')
cls.func(nil, 'void setD(float inValue)')
cls.func(nil, 'float getWorldX()')
cls.func(nil, 'void setWorldX(float inValue)')
cls.func(nil, 'float getWorldY()')
cls.func(nil, 'void setWorldY(float inValue)')
cls.func(nil, 'float getWorldRotationX()')
cls.func(nil, 'float getWorldRotationY()')
cls.func(nil, 'float getWorldScaleX()')
cls.func(nil, 'float getWorldScaleY()')
cls.func(nil, 'bool isAppliedValid()')
cls.func(nil, 'void setAppliedValid(bool valid)')
cls.prop('yDown', nil, nil)
cls.prop('worldToLocalRotationX', nil, nil)
cls.prop('worldToLocalRotationY', nil, nil)
cls.prop('parent', nil, nil)
cls.prop('children', nil, nil)
cls.prop('x', nil, nil)
cls.prop('y', nil, nil)
cls.prop('rotation', nil, nil)
cls.prop('scaleX', nil, nil)
cls.prop('scaleY', nil, nil)
cls.prop('shearX', nil, nil)
cls.prop('shearY', nil, nil)
cls.prop('appliedRotation', nil, nil)
cls.prop('ax', nil, nil)
cls.prop('ay', nil, nil)
cls.prop('aScaleX', nil, nil)
cls.prop('aScaleY', nil, nil)
cls.prop('aShearX', nil, nil)
cls.prop('aShearY', nil, nil)
cls.prop('a', nil, nil)
cls.prop('b', nil, nil)
cls.prop('c', nil, nil)
cls.prop('d', nil, nil)
cls.prop('worldX', nil, nil)
cls.prop('worldY', nil, nil)
cls.prop('worldRotationX', nil, nil)
cls.prop('worldRotationY', nil, nil)
cls.prop('worldScaleX', nil, nil)
cls.prop('worldScaleY', nil, nil)
cls.prop('appliedValid', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Slot'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void setToSetupPose()')
cls.func(nil, 'spine::Color &getColor()')
cls.func(nil, 'spine::Color &getDarkColor()')
cls.func(nil, 'bool hasDarkColor()')
cls.func(nil, 'spine::Attachment *getAttachment()')
cls.func(nil, 'void setAttachment(spine::Attachment *inValue)')
cls.func(nil, 'int getAttachmentState()')
cls.func(nil, 'void setAttachmentState(int state)')
cls.func(nil, 'float getAttachmentTime()')
cls.func(nil, 'void setAttachmentTime(float inValue)')
cls.func(nil, 'Vector<float> &getDeform()')
cls.prop('color', nil, nil)
cls.prop('darkColor', nil, nil)
cls.prop('attachment', nil, nil)
cls.prop('attachmentState', nil, nil)
cls.prop('attachmentTime', nil, nil)
cls.prop('deform', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Attachment'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'const spine::String &getName()')
cls.func(nil, 'spine::Attachment *copy()')
cls.func(nil, 'int getRefCount()')
cls.func(nil, 'void reference()')
cls.func(nil, 'void dereference()')
cls.prop('name', nil, nil)
cls.prop('refCount', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::VertexAttachment'
cls.SUPERCLS = 'spine::Attachment'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'int getId()')
cls.func(nil, 'Vector<size_t> &getBones()')
cls.func(nil, 'Vector<float> &getVertices()')
cls.func(nil, 'size_t getWorldVerticesLength()')
cls.func(nil, 'void setWorldVerticesLength(size_t inValue)')
cls.func(nil, 'spine::VertexAttachment *getDeformAttachment()')
cls.func(nil, 'void setDeformAttachment(spine::VertexAttachment *attachment)')
cls.func(nil, 'void copyTo(spine::VertexAttachment *other)')
cls.prop('id', nil, nil)
cls.prop('bones', nil, nil)
cls.prop('vertices', nil, nil)
cls.prop('worldVerticesLength', nil, nil)
cls.prop('deformAttachment', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::ClippingAttachment'
cls.SUPERCLS = 'spine::VertexAttachment'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'ClippingAttachment(const spine::String &name)')
cls.func(nil, 'spine::SlotData *getEndSlot()')
cls.func(nil, 'void setEndSlot(spine::SlotData *inValue)')
cls.prop('endSlot', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::BoundingBoxAttachment'
cls.SUPERCLS = 'spine::VertexAttachment'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'BoundingBoxAttachment(const spine::String &name)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::MeshAttachment'
cls.SUPERCLS = 'spine::VertexAttachment'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'MeshAttachment(const spine::String &name)')
cls.func(nil, 'void updateUVs()')
cls.func(nil, 'int getHullLength()')
cls.func(nil, 'void setHullLength(int inValue)')
cls.func(nil, 'Vector<float> &getRegionUVs()')
cls.func(nil, 'Vector<float> &getUVs()')
cls.func(nil, 'Vector<unsigned short> &getTriangles()')
cls.func(nil, 'spine::Color &getColor()')
cls.func(nil, 'const spine::String &getPath()')
cls.func(nil, 'void setPath(const spine::String &inValue)')
cls.func(nil, 'float getRegionU()')
cls.func(nil, 'void setRegionU(float inValue)')
cls.func(nil, 'float getRegionV()')
cls.func(nil, 'void setRegionV(float inValue)')
cls.func(nil, 'float getRegionU2()')
cls.func(nil, 'void setRegionU2(float inValue)')
cls.func(nil, 'float getRegionV2()')
cls.func(nil, 'void setRegionV2(float inValue)')
cls.func(nil, 'bool getRegionRotate()')
cls.func(nil, 'void setRegionRotate(bool inValue)')
cls.func(nil, 'int getRegionDegrees()')
cls.func(nil, 'void setRegionDegrees(int inValue)')
cls.func(nil, 'float getRegionOffsetX()')
cls.func(nil, 'void setRegionOffsetX(float inValue)')
cls.func(nil, 'float getRegionOffsetY()')
cls.func(nil, 'void setRegionOffsetY(float inValue)')
cls.func(nil, 'float getRegionWidth()')
cls.func(nil, 'void setRegionWidth(float inValue)')
cls.func(nil, 'float getRegionHeight()')
cls.func(nil, 'void setRegionHeight(float inValue)')
cls.func(nil, 'float getRegionOriginalWidth()')
cls.func(nil, 'void setRegionOriginalWidth(float inValue)')
cls.func(nil, 'float getRegionOriginalHeight()')
cls.func(nil, 'void setRegionOriginalHeight(float inValue)')
cls.func(nil, 'spine::MeshAttachment *getParentMesh()')
cls.func(nil, 'void setParentMesh(spine::MeshAttachment *inValue)')
cls.func(nil, 'Vector<unsigned short> &getEdges()')
cls.func(nil, 'float getWidth()')
cls.func(nil, 'void setWidth(float inValue)')
cls.func(nil, 'float getHeight()')
cls.func(nil, 'void setHeight(float inValue)')
cls.func(nil, 'spine::MeshAttachment *newLinkedMesh()')
cls.prop('hullLength', nil, nil)
cls.prop('regionUVs', nil, nil)
cls.prop('uvs', nil, nil)
cls.prop('triangles', nil, nil)
cls.prop('color', nil, nil)
cls.prop('path', nil, nil)
cls.prop('regionU', nil, nil)
cls.prop('regionV', nil, nil)
cls.prop('regionU2', nil, nil)
cls.prop('regionV2', nil, nil)
cls.prop('regionRotate', nil, nil)
cls.prop('regionDegrees', nil, nil)
cls.prop('regionOffsetX', nil, nil)
cls.prop('regionOffsetY', nil, nil)
cls.prop('regionWidth', nil, nil)
cls.prop('regionHeight', nil, nil)
cls.prop('regionOriginalWidth', nil, nil)
cls.prop('regionOriginalHeight', nil, nil)
cls.prop('parentMesh', nil, nil)
cls.prop('edges', nil, nil)
cls.prop('width', nil, nil)
cls.prop('height', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathAttachment'
cls.SUPERCLS = 'spine::VertexAttachment'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'PathAttachment(const spine::String &name)')
cls.func(nil, 'Vector<float> &getLengths()')
cls.func(nil, 'bool isClosed()')
cls.func(nil, 'void setClosed(bool inValue)')
cls.func(nil, 'bool isConstantSpeed()')
cls.func(nil, 'void setConstantSpeed(bool inValue)')
cls.prop('lengths', nil, nil)
cls.prop('closed', nil, nil)
cls.prop('constantSpeed', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PathConstraint'
cls.SUPERCLS = 'spine::Updatable'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void apply()')
cls.func(nil, 'int getOrder()')
cls.func(nil, 'float getPosition()')
cls.func(nil, 'void setPosition(float inValue)')
cls.func(nil, 'float getSpacing()')
cls.func(nil, 'void setSpacing(float inValue)')
cls.func(nil, 'float getRotateMix()')
cls.func(nil, 'void setRotateMix(float inValue)')
cls.func(nil, 'float getTranslateMix()')
cls.func(nil, 'void setTranslateMix(float inValue)')
cls.func(nil, 'Vector<spine::Bone *> &getBones()')
cls.func(nil, 'spine::Slot *getTarget()')
cls.func(nil, 'void setTarget(spine::Slot *inValue)')
cls.prop('order', nil, nil)
cls.prop('position', nil, nil)
cls.prop('spacing', nil, nil)
cls.prop('rotateMix', nil, nil)
cls.prop('translateMix', nil, nil)
cls.prop('bones', nil, nil)
cls.prop('target', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::PointAttachment'
cls.SUPERCLS = 'spine::Attachment'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'PointAttachment(const spine::String &name)')
cls.func(nil, 'float getX()')
cls.func(nil, 'void setX(float inValue)')
cls.func(nil, 'float getY()')
cls.func(nil, 'void setY(float inValue)')
cls.func(nil, 'float getRotation()')
cls.func(nil, 'void setRotation(float inValue)')
cls.prop('x', nil, nil)
cls.prop('y', nil, nil)
cls.prop('rotation', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::RegionAttachment'
cls.SUPERCLS = 'spine::Attachment'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'RegionAttachment(const spine::String &name)')
cls.func(nil, 'void updateOffset()')
cls.func(nil, 'void setUVs(float u, float v, float u2, float v2, bool rotate)')
cls.func(nil, 'float getX()')
cls.func(nil, 'void setX(float inValue)')
cls.func(nil, 'float getY()')
cls.func(nil, 'void setY(float inValue)')
cls.func(nil, 'float getRotation()')
cls.func(nil, 'void setRotation(float inValue)')
cls.func(nil, 'float getScaleX()')
cls.func(nil, 'void setScaleX(float inValue)')
cls.func(nil, 'float getScaleY()')
cls.func(nil, 'void setScaleY(float inValue)')
cls.func(nil, 'float getWidth()')
cls.func(nil, 'void setWidth(float inValue)')
cls.func(nil, 'float getHeight()')
cls.func(nil, 'void setHeight(float inValue)')
cls.func(nil, 'spine::Color &getColor()')
cls.func(nil, 'const spine::String &getPath()')
cls.func(nil, 'void setPath(const spine::String &inValue)')
cls.func(nil, 'float getRegionOffsetX()')
cls.func(nil, 'void setRegionOffsetX(float inValue)')
cls.func(nil, 'float getRegionOffsetY()')
cls.func(nil, 'void setRegionOffsetY(float inValue)')
cls.func(nil, 'float getRegionWidth()')
cls.func(nil, 'void setRegionWidth(float inValue)')
cls.func(nil, 'float getRegionHeight()')
cls.func(nil, 'void setRegionHeight(float inValue)')
cls.func(nil, 'float getRegionOriginalWidth()')
cls.func(nil, 'void setRegionOriginalWidth(float inValue)')
cls.func(nil, 'float getRegionOriginalHeight()')
cls.func(nil, 'void setRegionOriginalHeight(float inValue)')
cls.func(nil, 'Vector<float> &getOffset()')
cls.func(nil, 'Vector<float> &getUVs()')
cls.prop('x', nil, nil)
cls.prop('y', nil, nil)
cls.prop('rotation', nil, nil)
cls.prop('scaleX', nil, nil)
cls.prop('scaleY', nil, nil)
cls.prop('width', nil, nil)
cls.prop('height', nil, nil)
cls.prop('color', nil, nil)
cls.prop('path', nil, nil)
cls.prop('regionOffsetX', nil, nil)
cls.prop('regionOffsetY', nil, nil)
cls.prop('regionWidth', nil, nil)
cls.prop('regionHeight', nil, nil)
cls.prop('regionOriginalWidth', nil, nil)
cls.prop('regionOriginalHeight', nil, nil)
cls.prop('offset', nil, nil)
cls.prop('uvs', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::TrackEntry'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'TrackEntry()')
cls.func(nil, 'int getTrackIndex()')
cls.func(nil, 'spine::Animation *getAnimation()')
cls.func(nil, 'bool getLoop()')
cls.func(nil, 'void setLoop(bool inValue)')
cls.func(nil, 'bool getHoldPrevious()')
cls.func(nil, 'void setHoldPrevious(bool inValue)')
cls.func(nil, 'float getDelay()')
cls.func(nil, 'void setDelay(float inValue)')
cls.func(nil, 'float getTrackTime()')
cls.func(nil, 'void setTrackTime(float inValue)')
cls.func(nil, 'float getTrackEnd()')
cls.func(nil, 'void setTrackEnd(float inValue)')
cls.func(nil, 'float getAnimationStart()')
cls.func(nil, 'void setAnimationStart(float inValue)')
cls.func(nil, 'float getAnimationEnd()')
cls.func(nil, 'void setAnimationEnd(float inValue)')
cls.func(nil, 'float getAnimationLast()')
cls.func(nil, 'void setAnimationLast(float inValue)')
cls.func(nil, 'float getAnimationTime()')
cls.func(nil, 'float getTimeScale()')
cls.func(nil, 'void setTimeScale(float inValue)')
cls.func(nil, 'float getAlpha()')
cls.func(nil, 'void setAlpha(float inValue)')
cls.func(nil, 'float getEventThreshold()')
cls.func(nil, 'void setEventThreshold(float inValue)')
cls.func(nil, 'float getAttachmentThreshold()')
cls.func(nil, 'void setAttachmentThreshold(float inValue)')
cls.func(nil, 'float getDrawOrderThreshold()')
cls.func(nil, 'void setDrawOrderThreshold(float inValue)')
cls.func(nil, 'spine::TrackEntry *getNext()')
cls.func(nil, 'bool isComplete()')
cls.func(nil, 'float getMixTime()')
cls.func(nil, 'void setMixTime(float inValue)')
cls.func(nil, 'float getMixDuration()')
cls.func(nil, 'void setMixDuration(float inValue)')
cls.func(nil, 'spine::MixBlend getMixBlend()')
cls.func(nil, 'void setMixBlend(spine::MixBlend blend)')
cls.func(nil, 'spine::TrackEntry *getMixingFrom()')
cls.func(nil, 'spine::TrackEntry *getMixingTo()')
cls.func(nil, 'void resetRotationDirections()')
cls.callback {
    FUNCS =  {
        'void setListener(std::function<void (AnimationState *, EventType, TrackEntry *, Event *)> listener)'
    },
    TAG_MAKER = 'Listener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('trackIndex', nil, nil)
cls.prop('animation', nil, nil)
cls.prop('loop', nil, nil)
cls.prop('holdPrevious', nil, nil)
cls.prop('delay', nil, nil)
cls.prop('trackTime', nil, nil)
cls.prop('trackEnd', nil, nil)
cls.prop('animationStart', nil, nil)
cls.prop('animationEnd', nil, nil)
cls.prop('animationLast', nil, nil)
cls.prop('animationTime', nil, nil)
cls.prop('timeScale', nil, nil)
cls.prop('alpha', nil, nil)
cls.prop('eventThreshold', nil, nil)
cls.prop('attachmentThreshold', nil, nil)
cls.prop('drawOrderThreshold', nil, nil)
cls.prop('next', nil, nil)
cls.prop('complete', nil, nil)
cls.prop('mixTime', nil, nil)
cls.prop('mixDuration', nil, nil)
cls.prop('mixBlend', nil, nil)
cls.prop('mixingFrom', nil, nil)
cls.prop('mixingTo', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SkeletonData'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func('__gc', [[
    {
        auto self = olua_toobj<spine::SkeletonData>(L, 1);
        lua_pushstring(L, ".ownership");
        olua_getvariable(L, 1);
        if (lua_toboolean(L, -1) && self) {
            olua_setrawobj(L, 1, nullptr);

            lua_pushstring(L, ".skel.atlas");
            olua_getvariable(L, 1);
            auto atlas = (spine::Atlas *)olua_torawobj(L, -1);
            delete atlas;

            lua_pushstring(L, ".skel.attachment_loader");
            olua_getvariable(L, 1);
            auto attachment_loader = (spine::Cocos2dAtlasAttachmentLoader *)olua_torawobj(L, -1);
            delete attachment_loader;

            lua_pushstring(L, ".skel.texture_loader");
            olua_getvariable(L, 1);
            auto texture_loader = (spine::Cocos2dTextureLoader *)olua_torawobj(L, -1);
            delete texture_loader;

            delete self;
        }
        return 0;
    }
]])
cls.func('new', [[
    {
        const char *skel_path = olua_checkstring(L, 1);
        const char *atlas_path = olua_checkstring(L, 2);
        float scale = (float)olua_optnumber(L, 3, 1);

        auto texture_loader = new spine::Cocos2dTextureLoader();
        auto atlas = new spine::Atlas(atlas_path, texture_loader);
        spine::SkeletonData *skel_data = nullptr;
        auto attachment_loader = new spine::Cocos2dAtlasAttachmentLoader(atlas);

        if (strendwith(skel_path, ".skel")) {
            auto reader = new spine::SkeletonBinary(attachment_loader);
            reader->setScale(scale);
            skel_data = reader->readSkeletonDataFile(skel_path);
            delete reader;
        } else {
            auto reader = new spine::SkeletonJson(attachment_loader);
            reader->setScale(scale);
            skel_data = reader->readSkeletonDataFile(skel_path);
            delete reader;
        }

        if (!skel_data) {
            delete texture_loader;
            delete attachment_loader;
            delete atlas;
            luaL_error(L, "error reading skeleton file: %s", skel_path);
        }

        olua_pushobj<spine::SkeletonData>(L, skel_data);

        lua_pushstring(L, ".ownership");
        lua_pushboolean(L, true);
        olua_setvariable(L, -3);

        lua_pushstring(L, ".skel.texture_loader");
        olua_newrawobj(L, texture_loader);
        olua_setvariable(L, -3);

        lua_pushstring(L, ".skel.attachment_loader");
        olua_newrawobj(L, attachment_loader);
        olua_setvariable(L, -3);

        lua_pushstring(L, ".skel.atlas");
        olua_newrawobj(L, atlas);
        olua_setvariable(L, -3);

        return 1;
    }
]])
cls.func(nil, 'spine::BoneData *findBone(const spine::String &boneName)')
cls.func(nil, 'int findBoneIndex(const spine::String &boneName)')
cls.func(nil, 'spine::SlotData *findSlot(const spine::String &slotName)')
cls.func(nil, 'int findSlotIndex(const spine::String &slotName)')
cls.func(nil, 'spine::Skin *findSkin(const spine::String &skinName)')
cls.func(nil, 'spine::EventData *findEvent(const spine::String &eventDataName)')
cls.func(nil, 'spine::Animation *findAnimation(const spine::String &animationName)')
cls.func(nil, 'spine::IkConstraintData *findIkConstraint(const spine::String &constraintName)')
cls.func(nil, 'spine::TransformConstraintData *findTransformConstraint(const spine::String &constraintName)')
cls.func(nil, 'spine::PathConstraintData *findPathConstraint(const spine::String &constraintName)')
cls.func(nil, 'int findPathConstraintIndex(const spine::String &pathConstraintName)')
cls.func(nil, 'const spine::String &getName()')
cls.func(nil, 'void setName(const spine::String &inValue)')
cls.func(nil, 'Vector<spine::BoneData *> &getBones()')
cls.func(nil, 'Vector<spine::SlotData *> &getSlots()')
cls.func(nil, 'Vector<spine::Skin *> &getSkins()')
cls.func(nil, 'spine::Skin *getDefaultSkin()')
cls.func(nil, 'void setDefaultSkin(spine::Skin *inValue)')
cls.func(nil, 'Vector<spine::EventData *> &getEvents()')
cls.func(nil, 'Vector<spine::Animation *> &getAnimations()')
cls.func(nil, 'Vector<spine::IkConstraintData *> &getIkConstraints()')
cls.func(nil, 'Vector<spine::TransformConstraintData *> &getTransformConstraints()')
cls.func(nil, 'Vector<spine::PathConstraintData *> &getPathConstraints()')
cls.func(nil, 'float getX()')
cls.func(nil, 'void setX(float inValue)')
cls.func(nil, 'float getY()')
cls.func(nil, 'void setY(float inValue)')
cls.func(nil, 'float getWidth()')
cls.func(nil, 'void setWidth(float inValue)')
cls.func(nil, 'float getHeight()')
cls.func(nil, 'void setHeight(float inValue)')
cls.func(nil, 'const spine::String &getVersion()')
cls.func(nil, 'void setVersion(const spine::String &inValue)')
cls.func(nil, 'const spine::String &getHash()')
cls.func(nil, 'void setHash(const spine::String &inValue)')
cls.func(nil, 'const spine::String &getImagesPath()')
cls.func(nil, 'void setImagesPath(const spine::String &inValue)')
cls.func(nil, 'const spine::String &getAudioPath()')
cls.func(nil, 'void setAudioPath(const spine::String &inValue)')
cls.func(nil, 'float getFps()')
cls.func(nil, 'void setFps(float inValue)')
cls.prop('name', nil, nil)
cls.prop('bones', nil, nil)
cls.prop('slots', nil, nil)
cls.prop('skins', nil, nil)
cls.prop('defaultSkin', nil, nil)
cls.prop('events', nil, nil)
cls.prop('animations', nil, nil)
cls.prop('ikConstraints', nil, nil)
cls.prop('transformConstraints', nil, nil)
cls.prop('pathConstraints', nil, nil)
cls.prop('x', nil, nil)
cls.prop('y', nil, nil)
cls.prop('width', nil, nil)
cls.prop('height', nil, nil)
cls.prop('version', nil, nil)
cls.prop('hash', nil, nil)
cls.prop('imagesPath', nil, nil)
cls.prop('audioPath', nil, nil)
cls.prop('fps', nil, nil)
cls.alias('__gc', 'dispose')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::Skeleton'
cls.SUPERCLS = 'spine::SpineObject'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'Skeleton(spine::SkeletonData *skeletonData)')
cls.func(nil, 'void updateCache()')
cls.func(nil, 'void printUpdateCache()')
cls.func(nil, 'void updateWorldTransform()')
cls.func(nil, 'void setToSetupPose()')
cls.func(nil, 'void setBonesToSetupPose()')
cls.func(nil, 'void setSlotsToSetupPose()')
cls.func(nil, 'spine::Bone *findBone(const spine::String &boneName)')
cls.func(nil, 'int findBoneIndex(const spine::String &boneName)')
cls.func(nil, 'spine::Slot *findSlot(const spine::String &slotName)')
cls.func(nil, 'int findSlotIndex(const spine::String &slotName)')
cls.func(nil, 'void setSkin(const spine::String &skinName)', 'void setSkin(spine::Skin *newSkin)')
cls.func(nil, 'spine::Attachment *getAttachment(const spine::String &slotName, const spine::String &attachmentName)', 'spine::Attachment *getAttachment(int slotIndex, const spine::String &attachmentName)')
cls.func(nil, 'void setAttachment(const spine::String &slotName, const spine::String &attachmentName)')
cls.func(nil, 'spine::IkConstraint *findIkConstraint(const spine::String &constraintName)')
cls.func(nil, 'spine::TransformConstraint *findTransformConstraint(const spine::String &constraintName)')
cls.func(nil, 'spine::PathConstraint *findPathConstraint(const spine::String &constraintName)')
cls.func(nil, 'void update(float delta)')
cls.func(nil, 'spine::Bone *getRootBone()')
cls.func(nil, 'spine::SkeletonData *getData()')
cls.func(nil, 'Vector<spine::Bone *> &getBones()')
cls.func(nil, 'Vector<spine::Updatable *> &getUpdateCacheList()')
cls.func(nil, 'Vector<spine::Slot *> &getSlots()')
cls.func(nil, 'Vector<spine::Slot *> &getDrawOrder()')
cls.func(nil, 'Vector<spine::IkConstraint *> &getIkConstraints()')
cls.func(nil, 'Vector<spine::PathConstraint *> &getPathConstraints()')
cls.func(nil, 'Vector<spine::TransformConstraint *> &getTransformConstraints()')
cls.func(nil, 'spine::Skin *getSkin()')
cls.func(nil, 'spine::Color &getColor()')
cls.func(nil, 'float getTime()')
cls.func(nil, 'void setTime(float inValue)')
cls.func(nil, 'void setPosition(float x, float y)')
cls.func(nil, 'float getX()')
cls.func(nil, 'void setX(float inValue)')
cls.func(nil, 'float getY()')
cls.func(nil, 'void setY(float inValue)')
cls.func(nil, 'float getScaleX()')
cls.func(nil, 'void setScaleX(float inValue)')
cls.func(nil, 'float getScaleY()')
cls.func(nil, 'void setScaleY(float inValue)')
cls.prop('rootBone', nil, nil)
cls.prop('data', nil, nil)
cls.prop('bones', nil, nil)
cls.prop('updateCacheList', nil, nil)
cls.prop('slots', nil, nil)
cls.prop('drawOrder', nil, nil)
cls.prop('ikConstraints', nil, nil)
cls.prop('pathConstraints', nil, nil)
cls.prop('transformConstraints', nil, nil)
cls.prop('skin', nil, nil)
cls.prop('color', nil, nil)
cls.prop('time', nil, nil)
cls.prop('x', nil, nil)
cls.prop('y', nil, nil)
cls.prop('scaleX', nil, nil)
cls.prop('scaleY', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SkeletonRenderer'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static spine::SkeletonRenderer *create()')
cls.func(nil, 'static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)')
cls.func(nil, 'static spine::SkeletonRenderer *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)')
cls.func(nil, 'static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)', 'static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)')
cls.func(nil, 'spine::Skeleton *getSkeleton()')
cls.func(nil, 'void setTimeScale(float scale)')
cls.func(nil, 'float getTimeScale()')
cls.func(nil, 'void setDebugSlotsEnabled(bool enabled)')
cls.func(nil, 'bool getDebugSlotsEnabled()')
cls.func(nil, 'void setDebugBonesEnabled(bool enabled)')
cls.func(nil, 'bool getDebugBonesEnabled()')
cls.func(nil, 'void setDebugMeshesEnabled(bool enabled)')
cls.func(nil, 'bool getDebugMeshesEnabled()')
cls.func(nil, 'void setDebugBoundingRectEnabled(bool enabled)')
cls.func(nil, 'bool getDebugBoundingRectEnabled()')
cls.func(nil, 'void updateWorldTransform()')
cls.func(nil, 'void setToSetupPose()')
cls.func(nil, 'void setBonesToSetupPose()')
cls.func(nil, 'void setSlotsToSetupPose()')
cls.func(nil, 'spine::Bone *findBone(const std::string &boneName)')
cls.func(nil, 'spine::Slot *findSlot(const std::string &slotName)')
cls.func(nil, 'void setSkin(const std::string &skinName)', 'void setSkin(const char *skinName)')
cls.func(nil, 'spine::Attachment *getAttachment(const std::string &slotName, const std::string &attachmentName)')
cls.func(nil, 'bool setAttachment(const std::string &slotName, const std::string &attachmentName)', 'bool setAttachment(const std::string &slotName, const char *attachmentName)')
cls.func(nil, 'void setTwoColorTint(bool enabled)')
cls.func(nil, 'bool isTwoColorTint()')
cls.func(nil, 'void setVertexEffect(spine::VertexEffect *effect)')
cls.func(nil, 'void setSlotsRange(int startSlotIndex, int endSlotIndex)')
cls.func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
cls.func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
cls.func(nil, 'SkeletonRenderer()', 'SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)', 'SkeletonRenderer(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)', 'SkeletonRenderer(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)', 'SkeletonRenderer(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)')
cls.func(nil, 'void initialize()')
cls.prop('skeleton', nil, nil)
cls.prop('timeScale', nil, nil)
cls.prop('debugSlotsEnabled', nil, nil)
cls.prop('debugBonesEnabled', nil, nil)
cls.prop('debugMeshesEnabled', nil, nil)
cls.prop('debugBoundingRectEnabled', nil, nil)
cls.prop('twoColorTint', nil, nil)
cls.prop('blendFunc', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'spine::SkeletonAnimation'
cls.SUPERCLS = 'spine::SkeletonRenderer'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static spine::SkeletonAnimation *create()')
cls.func(nil, 'static spine::SkeletonAnimation *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)')
cls.func(nil, 'static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, spine::Atlas *atlas, @optional float scale)', 'static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, const std::string &atlasFile, @optional float scale)')
cls.func(nil, 'static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, spine::Atlas *atlas, @optional float scale)', 'static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, const std::string &atlasFile, @optional float scale)')
cls.func(nil, 'void setAnimationStateData(spine::AnimationStateData *stateData)')
cls.func(nil, 'void setMix(const std::string &fromAnimation, const std::string &toAnimation, float duration)')
cls.func(nil, '@addref(trackEntries |) spine::TrackEntry *setAnimation(int trackIndex, const std::string &name, bool loop)')
cls.func(nil, '@addref(trackEntries |) spine::TrackEntry *addAnimation(int trackIndex, const std::string &name, bool loop, @optional float delay)')
cls.func(nil, '@addref(trackEntries |) spine::TrackEntry *setEmptyAnimation(int trackIndex, float mixDuration)')
cls.func(nil, 'void setEmptyAnimations(float mixDuration)')
cls.func(nil, '@addref(trackEntries |) spine::TrackEntry *addEmptyAnimation(int trackIndex, float mixDuration, @optional float delay)')
cls.func(nil, 'spine::Animation *findAnimation(const std::string &name)')
cls.func(nil, '@addref(trackEntries |) spine::TrackEntry *getCurrent(@optional int trackIndex)')
cls.func(nil, 'void clearTracks()')
cls.func(nil, 'void clearTrack(@optional int trackIndex)')
cls.func(nil, 'void onAnimationStateEvent(spine::TrackEntry *entry, spine::EventType type, spine::Event *event)')
cls.func(nil, 'void onTrackEntryEvent(spine::TrackEntry *entry, spine::EventType type, spine::Event *event)')
cls.func(nil, '@addref(state ^) spine::AnimationState *getState()')
cls.func(nil, 'void setUpdateOnlyIfVisible(bool status)')
cls.func(nil, 'SkeletonAnimation()')
cls.callback {
    FUNCS =  {
        'void setStartListener(const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'StartListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setInterruptListener(const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'InterruptListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setEndListener(const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'EndListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setDisposeListener(const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'DisposeListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setCompleteListener(const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'CompleteListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setEventListener(const std::function<void (TrackEntry *, Event *)> &listener)'
    },
    TAG_MAKER = 'EventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackStartListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'TrackStartListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackInterruptListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'TrackInterruptListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackEndListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'TrackEndListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackDisposeListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'TrackDisposeListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackCompleteListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)'
    },
    TAG_MAKER = 'TrackCompleteListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setTrackEventListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *, Event *)> &listener)'
    },
    TAG_MAKER = 'TrackEventListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setPreUpdateWorldTransformsListener(@local const std::function<void (SkeletonAnimation *)> &listener)'
    },
    TAG_MAKER = 'PreUpdateWorldTransformsListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'void setPostUpdateWorldTransformsListener(@local const std::function<void (SkeletonAnimation *)> &listener)'
    },
    TAG_MAKER = 'PostUpdateWorldTransformsListener',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.prop('state', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

return M
