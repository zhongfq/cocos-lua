-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/spine-types.lua"

NAME = "spine"
PATH = "../../frameworks/libxgame/src/lua-bindings"
HEADERS = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/xlua.h"
    #include "cclua/runtime.h"
    #include "cocos2d.h"
    #include "spine/spine-cocos2dx.h"
]]
CHUNK = [[
    template <class T>
    void olua_insert_array(spine::Vector<T> *array, T value)
    {
        array->add(value);
    }

    template <class T>
    void olua_foreach_array(const spine::Vector<T> *array, const std::function<void(T)> &callback)
    {
        spine::Vector<T> *vararray = const_cast<spine::Vector<T> *>(array);
        for (int i = 0, n = (int)vararray->size(); i < n; i++) {
            callback((*vararray)[i]);
        }
    }

    template <class T>
    int olua_push_spine_Vector(lua_State *L, const spine::Vector<T> *array, const std::function<void(T)> &push) {
        return olua_push_array<T, spine::Vector>(L, array, push);
    }

    template <class T>
    void olua_check_spine_Vector(lua_State *L, int idx, spine::Vector<T> *array, const std::function<void(T *)> &check) {
        olua_check_array<T, spine::Vector>(L, idx, array, check);
    }

    bool olua_is_spine_String(lua_State *L, int idx)
    {
        return olua_isstring(L, idx);
    }

    int olua_push_spine_String(lua_State *L, const spine::String *value)
    {
        if (value && value->buffer()) {
            lua_pushlstring(L, value->buffer(), value->length());
        } else {
            lua_pushnil(L);
        }
        return 1;
    }

    void olua_check_spine_String(lua_State *L, int idx, spine::String *value)
    {
        if (!value) {
            luaL_error(L, "value is NULL");
        }
        *value = olua_checkstring(L, idx);
    }

    bool olua_is_spine_Color(lua_State *L, int idx)
    {
        return olua_isinteger(L, idx);
    }

    void olua_check_spine_Color(lua_State *L, int idx, spine::Color *value)
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

    int olua_push_spine_Color(lua_State *L, const spine::Color *value)
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

    int olua_push_spine_EventData(lua_State *L, const spine::EventData *value)
    {
        spine::EventData *data = const_cast<spine::EventData *>(value);
        lua_createtable(L, 0, 8);
        olua_setfieldinteger(L, -1, "intValue", data->getIntValue());
        olua_setfieldnumber(L, -1, "getVolume", data->getVolume());
        olua_setfieldnumber(L, -1, "getBalance", data->getBalance());
        olua_push_spine_String(L, &data->getName());
        olua_rawsetf(L, -2, "name");
        olua_push_spine_String(L, &data->getStringValue());
        olua_rawsetf(L, -2, "stringValue");
        olua_push_spine_String(L, &data->getAudioPath());
        olua_rawsetf(L, -2, "audioPath");
        return 1;
    }
]]


typeconf 'spine::EventType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('Start', 'spine::EventType::EventType_Start')
    .enum('Interrupt', 'spine::EventType::EventType_Interrupt')
    .enum('End', 'spine::EventType::EventType_End')
    .enum('Complete', 'spine::EventType::EventType_Complete')
    .enum('Dispose', 'spine::EventType::EventType_Dispose')
    .enum('Event', 'spine::EventType::EventType_Event')

typeconf 'spine::AttachmentType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('Region', 'spine::AttachmentType::AttachmentType_Region')
    .enum('Boundingbox', 'spine::AttachmentType::AttachmentType_Boundingbox')
    .enum('Mesh', 'spine::AttachmentType::AttachmentType_Mesh')
    .enum('Linkedmesh', 'spine::AttachmentType::AttachmentType_Linkedmesh')
    .enum('Path', 'spine::AttachmentType::AttachmentType_Path')
    .enum('Point', 'spine::AttachmentType::AttachmentType_Point')
    .enum('Clipping', 'spine::AttachmentType::AttachmentType_Clipping')

typeconf 'spine::TransformMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('Normal', 'spine::TransformMode::TransformMode_Normal')
    .enum('OnlyTranslation', 'spine::TransformMode::TransformMode_OnlyTranslation')
    .enum('NoRotationOrReflection', 'spine::TransformMode::TransformMode_NoRotationOrReflection')
    .enum('NoScale', 'spine::TransformMode::TransformMode_NoScale')
    .enum('NoScaleOrReflection', 'spine::TransformMode::TransformMode_NoScaleOrReflection')

typeconf 'spine::BlendMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('Normal', 'spine::BlendMode::BlendMode_Normal')
    .enum('Additive', 'spine::BlendMode::BlendMode_Additive')
    .enum('Multiply', 'spine::BlendMode::BlendMode_Multiply')
    .enum('Screen', 'spine::BlendMode::BlendMode_Screen')

typeconf 'spine::PositionMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('Fixed', 'spine::PositionMode::PositionMode_Fixed')
    .enum('Percent', 'spine::PositionMode::PositionMode_Percent')

typeconf 'spine::SpacingMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('Length', 'spine::SpacingMode::SpacingMode_Length')
    .enum('Fixed', 'spine::SpacingMode::SpacingMode_Fixed')
    .enum('Percent', 'spine::SpacingMode::SpacingMode_Percent')
    .enum('Proportional', 'spine::SpacingMode::SpacingMode_Proportional')

typeconf 'spine::RotateMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('Tangent', 'spine::RotateMode::RotateMode_Tangent')
    .enum('Chain', 'spine::RotateMode::RotateMode_Chain')
    .enum('ChainScale', 'spine::RotateMode::RotateMode_ChainScale')

typeconf 'spine::MixBlend'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('Setup', 'spine::MixBlend::MixBlend_Setup')
    .enum('First', 'spine::MixBlend::MixBlend_First')
    .enum('Replace', 'spine::MixBlend::MixBlend_Replace')
    .enum('Add', 'spine::MixBlend::MixBlend_Add')

typeconf 'spine::SpineObject'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::Event'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'const spine::EventData &getData()')
    .func(nil, 'float getTime()')
    .func(nil, 'int getIntValue()')
    .func(nil, 'void setIntValue(int inValue)')
    .func(nil, 'float getFloatValue()')
    .func(nil, 'void setFloatValue(float inValue)')
    .func(nil, 'const spine::String &getStringValue()')
    .func(nil, 'void setStringValue(const spine::String &inValue)')
    .func(nil, 'float getVolume()')
    .func(nil, 'void setVolume(float inValue)')
    .func(nil, 'float getBalance()')
    .func(nil, 'void setBalance(float inValue)')
    .prop('data', nil, nil)
    .prop('time', nil, nil)
    .prop('intValue', nil, nil)
    .prop('floatValue', nil, nil)
    .prop('stringValue', nil, nil)
    .prop('volume', nil, nil)
    .prop('balance', nil, nil)

typeconf 'spine::EventData'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'EventData(const spine::String &name)')
    .func(nil, 'const spine::String &getName()')
    .func(nil, 'int getIntValue()')
    .func(nil, 'void setIntValue(int inValue)')
    .func(nil, 'float getFloatValue()')
    .func(nil, 'void setFloatValue(float inValue)')
    .func(nil, 'const spine::String &getStringValue()')
    .func(nil, 'void setStringValue(const spine::String &inValue)')
    .func(nil, 'const spine::String &getAudioPath()')
    .func(nil, 'void setAudioPath(const spine::String &inValue)')
    .func(nil, 'float getVolume()')
    .func(nil, 'void setVolume(float inValue)')
    .func(nil, 'float getBalance()')
    .func(nil, 'void setBalance(float inValue)')
    .prop('name', nil, nil)
    .prop('intValue', nil, nil)
    .prop('floatValue', nil, nil)
    .prop('stringValue', nil, nil)
    .prop('audioPath', nil, nil)
    .prop('volume', nil, nil)
    .prop('balance', nil, nil)

typeconf 'spine::Updatable'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void update()')
    .func(nil, 'bool isActive()')
    .func(nil, 'void setActive(bool inValue)')
    .prop('active', nil, nil)

typeconf 'spine::AnimationStateListener'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::AnimationState'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'AnimationState(spine::AnimationStateData *data)')
    .func(nil, 'void update(float delta)')
    .func(nil, 'void clearTracks()')
    .func(nil, 'void clearTrack(size_t trackIndex)')
    .func(nil, 'spine::TrackEntry *setAnimation(size_t trackIndex, const spine::String &animationName, bool loop)', 'spine::TrackEntry *setAnimation(size_t trackIndex, spine::Animation *animation, bool loop)')
    .func(nil, 'spine::TrackEntry *addAnimation(size_t trackIndex, const spine::String &animationName, bool loop, float delay)', 'spine::TrackEntry *addAnimation(size_t trackIndex, spine::Animation *animation, bool loop, float delay)')
    .func(nil, 'spine::TrackEntry *setEmptyAnimation(size_t trackIndex, float mixDuration)')
    .func(nil, 'spine::TrackEntry *addEmptyAnimation(size_t trackIndex, float mixDuration, float delay)')
    .func(nil, 'void setEmptyAnimations(float mixDuration)')
    .func(nil, 'spine::TrackEntry *getCurrent(size_t trackIndex)')
    .func(nil, 'spine::AnimationStateData *getData()')
    .func(nil, 'Vector<spine::TrackEntry *> &getTracks()')
    .func(nil, 'float getTimeScale()')
    .func(nil, 'void setTimeScale(float inValue)')
    .func(nil, 'void disableQueue()')
    .func(nil, 'void enableQueue()')
    .callback {
        FUNCS =  {
            'void setListener(spine::AnimationStateListener listener)'
        },
        TAG_MAKER = 'Listener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .prop('data', nil, nil)
    .prop('tracks', nil, nil)
    .prop('timeScale', nil, nil)

typeconf 'spine::AnimationStateData'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'AnimationStateData(spine::SkeletonData *skeletonData)')
    .func(nil, 'spine::SkeletonData *getSkeletonData()')
    .func(nil, 'float getDefaultMix()')
    .func(nil, 'void setDefaultMix(float inValue)')
    .func(nil, 'void setMix(const spine::String &fromName, const spine::String &toName, float duration)', 'void setMix(spine::Animation *from, spine::Animation *to, float duration)')
    .func(nil, 'float getMix(spine::Animation *from, spine::Animation *to)')
    .prop('skeletonData', nil, nil)
    .prop('defaultMix', nil, nil)

typeconf 'spine::Animation'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'Animation(const spine::String &name, Vector<spine::Timeline *> &timelines, float duration)')
    .func(nil, 'const spine::String &getName()')
    .func(nil, 'Vector<spine::Timeline *> &getTimelines()')
    .func(nil, 'bool hasTimeline(Vector<spine::PropertyId> ids)')
    .func(nil, 'float getDuration()')
    .func(nil, 'void setDuration(float inValue)')
    .prop('name', nil, nil)
    .prop('timelines', nil, nil)
    .prop('duration', nil, nil)

typeconf 'spine::ConstraintData'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'ConstraintData(const spine::String &name)')
    .func(nil, 'const spine::String &getName()')
    .func(nil, 'size_t getOrder()')
    .func(nil, 'void setOrder(size_t inValue)')
    .func(nil, 'bool isSkinRequired()')
    .func(nil, 'void setSkinRequired(bool inValue)')
    .prop('name', nil, nil)
    .prop('order', nil, nil)
    .prop('skinRequired', nil, nil)

typeconf 'spine::IkConstraintData'
    .supercls('spine::ConstraintData')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'IkConstraintData(const spine::String &name)')
    .func(nil, 'Vector<spine::BoneData *> &getBones()')
    .func(nil, 'spine::BoneData *getTarget()')
    .func(nil, 'void setTarget(spine::BoneData *inValue)')
    .func(nil, 'int getBendDirection()')
    .func(nil, 'void setBendDirection(int inValue)')
    .func(nil, 'bool getCompress()')
    .func(nil, 'void setCompress(bool inValue)')
    .func(nil, 'bool getStretch()')
    .func(nil, 'void setStretch(bool inValue)')
    .func(nil, 'bool getUniform()')
    .func(nil, 'void setUniform(bool inValue)')
    .func(nil, 'float getMix()')
    .func(nil, 'void setMix(float inValue)')
    .func(nil, 'float getSoftness()')
    .func(nil, 'void setSoftness(float inValue)')
    .prop('bones', nil, nil)
    .prop('target', nil, nil)
    .prop('bendDirection', nil, nil)
    .prop('compress', nil, nil)
    .prop('stretch', nil, nil)
    .prop('uniform', nil, nil)
    .prop('mix', nil, nil)
    .prop('softness', nil, nil)

typeconf 'spine::BoneData'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'BoneData(int index, const spine::String &name, @optional spine::BoneData *parent)')
    .func(nil, 'int getIndex()')
    .func(nil, 'const spine::String &getName()')
    .func(nil, 'spine::BoneData *getParent()')
    .func(nil, 'float getLength()')
    .func(nil, 'void setLength(float inValue)')
    .func(nil, 'float getX()')
    .func(nil, 'void setX(float inValue)')
    .func(nil, 'float getY()')
    .func(nil, 'void setY(float inValue)')
    .func(nil, 'float getRotation()')
    .func(nil, 'void setRotation(float inValue)')
    .func(nil, 'float getScaleX()')
    .func(nil, 'void setScaleX(float inValue)')
    .func(nil, 'float getScaleY()')
    .func(nil, 'void setScaleY(float inValue)')
    .func(nil, 'float getShearX()')
    .func(nil, 'void setShearX(float inValue)')
    .func(nil, 'float getShearY()')
    .func(nil, 'void setShearY(float inValue)')
    .func(nil, 'spine::TransformMode getTransformMode()')
    .func(nil, 'void setTransformMode(spine::TransformMode inValue)')
    .func(nil, 'bool isSkinRequired()')
    .func(nil, 'void setSkinRequired(bool inValue)')
    .func(nil, 'spine::Color &getColor()')
    .prop('index', nil, nil)
    .prop('name', nil, nil)
    .prop('parent', nil, nil)
    .prop('length', nil, nil)
    .prop('x', nil, nil)
    .prop('y', nil, nil)
    .prop('rotation', nil, nil)
    .prop('scaleX', nil, nil)
    .prop('scaleY', nil, nil)
    .prop('shearX', nil, nil)
    .prop('shearY', nil, nil)
    .prop('transformMode', nil, nil)
    .prop('skinRequired', nil, nil)
    .prop('color', nil, nil)

typeconf 'spine::SlotData'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'int getIndex()')
    .func(nil, 'const spine::String &getName()')
    .func(nil, 'spine::Color &getColor()')
    .func(nil, 'spine::Color &getDarkColor()')
    .func(nil, 'bool hasDarkColor()')
    .func(nil, 'void setHasDarkColor(bool inValue)')
    .func(nil, 'const spine::String &getAttachmentName()')
    .func(nil, 'void setAttachmentName(const spine::String &inValue)')
    .func(nil, 'spine::BlendMode getBlendMode()')
    .func(nil, 'void setBlendMode(spine::BlendMode inValue)')
    .prop('index', nil, nil)
    .prop('name', nil, nil)
    .prop('color', nil, nil)
    .prop('darkColor', nil, nil)
    .prop('attachmentName', nil, nil)
    .prop('blendMode', nil, nil)

typeconf 'spine::IkConstraint'
    .supercls('spine::Updatable')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void apply()')
    .func(nil, 'int getOrder()')
    .func(nil, 'Vector<spine::Bone *> &getBones()')
    .func(nil, 'spine::Bone *getTarget()')
    .func(nil, 'void setTarget(spine::Bone *inValue)')
    .func(nil, 'int getBendDirection()')
    .func(nil, 'void setBendDirection(int inValue)')
    .func(nil, 'bool getCompress()')
    .func(nil, 'void setCompress(bool inValue)')
    .func(nil, 'bool getStretch()')
    .func(nil, 'void setStretch(bool inValue)')
    .func(nil, 'float getMix()')
    .func(nil, 'void setMix(float inValue)')
    .func(nil, 'float getSoftness()')
    .func(nil, 'void setSoftness(float inValue)')
    .prop('order', nil, nil)
    .prop('bones', nil, nil)
    .prop('target', nil, nil)
    .prop('bendDirection', nil, nil)
    .prop('compress', nil, nil)
    .prop('stretch', nil, nil)
    .prop('mix', nil, nil)
    .prop('softness', nil, nil)

typeconf 'spine::TransformConstraint'
    .supercls('spine::Updatable')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'int getOrder()')
    .func(nil, 'Vector<spine::Bone *> &getBones()')
    .func(nil, 'spine::Bone *getTarget()')
    .func(nil, 'void setTarget(spine::Bone *inValue)')
    .func(nil, 'float getMixRotate()')
    .func(nil, 'void setMixRotate(float inValue)')
    .func(nil, 'float getMixX()')
    .func(nil, 'void setMixX(float inValue)')
    .func(nil, 'float getMixY()')
    .func(nil, 'void setMixY(float inValue)')
    .func(nil, 'float getMixScaleX()')
    .func(nil, 'void setMixScaleX(float inValue)')
    .func(nil, 'float getMixScaleY()')
    .func(nil, 'void setMixScaleY(float inValue)')
    .func(nil, 'float getMixShearY()')
    .func(nil, 'void setMixShearY(float inValue)')
    .prop('order', nil, nil)
    .prop('bones', nil, nil)
    .prop('target', nil, nil)
    .prop('mixRotate', nil, nil)
    .prop('mixX', nil, nil)
    .prop('mixY', nil, nil)
    .prop('mixScaleX', nil, nil)
    .prop('mixScaleY', nil, nil)
    .prop('mixShearY', nil, nil)

typeconf 'spine::TransformConstraintData'
    .supercls('spine::ConstraintData')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'TransformConstraintData(const spine::String &name)')
    .func(nil, 'Vector<spine::BoneData *> &getBones()')
    .func(nil, 'spine::BoneData *getTarget()')
    .func(nil, 'float getMixRotate()')
    .func(nil, 'float getMixX()')
    .func(nil, 'float getMixY()')
    .func(nil, 'float getMixScaleX()')
    .func(nil, 'float getMixScaleY()')
    .func(nil, 'float getMixShearY()')
    .func(nil, 'float getOffsetRotation()')
    .func(nil, 'float getOffsetX()')
    .func(nil, 'float getOffsetY()')
    .func(nil, 'float getOffsetScaleX()')
    .func(nil, 'float getOffsetScaleY()')
    .func(nil, 'float getOffsetShearY()')
    .func(nil, 'bool isRelative()')
    .func(nil, 'bool isLocal()')
    .prop('bones', nil, nil)
    .prop('target', nil, nil)
    .prop('mixRotate', nil, nil)
    .prop('mixX', nil, nil)
    .prop('mixY', nil, nil)
    .prop('mixScaleX', nil, nil)
    .prop('mixScaleY', nil, nil)
    .prop('mixShearY', nil, nil)
    .prop('offsetRotation', nil, nil)
    .prop('offsetX', nil, nil)
    .prop('offsetY', nil, nil)
    .prop('offsetScaleX', nil, nil)
    .prop('offsetScaleY', nil, nil)
    .prop('offsetShearY', nil, nil)
    .prop('relative', nil, nil)
    .prop('local', nil, nil)

typeconf 'spine::PathConstraintData'
    .supercls('spine::ConstraintData')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'PathConstraintData(const spine::String &name)')
    .func(nil, 'Vector<spine::BoneData *> &getBones()')
    .func(nil, 'spine::SlotData *getTarget()')
    .func(nil, 'void setTarget(spine::SlotData *inValue)')
    .func(nil, 'spine::PositionMode getPositionMode()')
    .func(nil, 'void setPositionMode(spine::PositionMode inValue)')
    .func(nil, 'spine::SpacingMode getSpacingMode()')
    .func(nil, 'void setSpacingMode(spine::SpacingMode inValue)')
    .func(nil, 'spine::RotateMode getRotateMode()')
    .func(nil, 'void setRotateMode(spine::RotateMode inValue)')
    .func(nil, 'float getOffsetRotation()')
    .func(nil, 'void setOffsetRotation(float inValue)')
    .func(nil, 'float getPosition()')
    .func(nil, 'void setPosition(float inValue)')
    .func(nil, 'float getSpacing()')
    .func(nil, 'void setSpacing(float inValue)')
    .func(nil, 'float getMixRotate()')
    .func(nil, 'void setMixRotate(float inValue)')
    .func(nil, 'float getMixX()')
    .func(nil, 'void setMixX(float inValue)')
    .func(nil, 'float getMixY()')
    .func(nil, 'void setMixY(float inValue)')
    .prop('bones', nil, nil)
    .prop('target', nil, nil)
    .prop('positionMode', nil, nil)
    .prop('spacingMode', nil, nil)
    .prop('rotateMode', nil, nil)
    .prop('offsetRotation', nil, nil)
    .prop('position', nil, nil)
    .prop('spacing', nil, nil)
    .prop('mixRotate', nil, nil)
    .prop('mixX', nil, nil)
    .prop('mixY', nil, nil)

typeconf 'spine::SkeletonBounds'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'SkeletonBounds()')
    .func(nil, 'bool aabbcontainsPoint(float x, float y)')
    .func(nil, 'bool aabbintersectsSegment(float x1, float y1, float x2, float y2)')
    .func(nil, 'bool containsPoint(spine::Polygon *polygon, float x, float y)', 'spine::BoundingBoxAttachment *containsPoint(float x, float y)')
    .func(nil, 'spine::BoundingBoxAttachment *intersectsSegment(float x1, float y1, float x2, float y2)', 'bool intersectsSegment(spine::Polygon *polygon, float x1, float y1, float x2, float y2)')
    .func(nil, 'spine::Polygon *getPolygon(spine::BoundingBoxAttachment *attachment)')
    .func(nil, 'float getWidth()')
    .func(nil, 'float getHeight()')
    .prop('width', nil, nil)
    .prop('height', nil, nil)

typeconf 'spine::SkeletonClipping'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::Timeline'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'size_t getFrameEntries()')
    .func(nil, 'size_t getFrameCount()')
    .func(nil, 'Vector<float> &getFrames()')
    .func(nil, 'float getDuration()')
    .func(nil, 'Vector<spine::PropertyId> &getPropertyIds()')
    .prop('frameEntries', nil, nil)
    .prop('frameCount', nil, nil)
    .prop('frames', nil, nil)
    .prop('duration', nil, nil)
    .prop('propertyIds', nil, nil)

typeconf 'spine::CurveTimeline'
    .supercls('spine::Timeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void setLinear(size_t frame)')
    .func(nil, 'void setStepped(size_t frame)')
    .func(nil, 'void setBezier(size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2)')
    .func(nil, 'float getBezierValue(float time, size_t frame, size_t valueOffset, size_t i)')
    .func(nil, 'Vector<float> &getCurves()')
    .prop('curves', nil, nil)

typeconf 'spine::CurveTimeline1'
    .supercls('spine::CurveTimeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'float getCurveValue(float time)')

typeconf 'spine::CurveTimeline2'
    .supercls('spine::CurveTimeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'float getCurveValue(float time)')

typeconf 'spine::AttachmentTimeline'
    .supercls('spine::Timeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'AttachmentTimeline(size_t frameCount, int slotIndex)')
    .func(nil, 'Vector<spine::String> &getAttachmentNames()')
    .func(nil, 'int getSlotIndex()')
    .func(nil, 'void setSlotIndex(int inValue)')
    .prop('attachmentNames', nil, nil)
    .prop('slotIndex', nil, nil)

typeconf 'spine::RGBATimeline'
    .supercls('spine::CurveTimeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'RGBATimeline(size_t frameCount, size_t bezierCount, int slotIndex)')
    .func(nil, 'int getSlotIndex()')
    .func(nil, 'void setSlotIndex(int inValue)')
    .prop('slotIndex', nil, nil)

typeconf 'spine::RGBTimeline'
    .supercls('spine::CurveTimeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'RGBTimeline(size_t frameCount, size_t bezierCount, int slotIndex)')
    .func(nil, 'int getSlotIndex()')
    .func(nil, 'void setSlotIndex(int inValue)')
    .prop('slotIndex', nil, nil)

typeconf 'spine::AlphaTimeline'
    .supercls('spine::CurveTimeline1')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'AlphaTimeline(size_t frameCount, size_t bezierCount, int slotIndex)')
    .func(nil, 'int getSlotIndex()')
    .func(nil, 'void setSlotIndex(int inValue)')
    .prop('slotIndex', nil, nil)

typeconf 'spine::RGBA2Timeline'
    .supercls('spine::CurveTimeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'RGBA2Timeline(size_t frameCount, size_t bezierCount, int slotIndex)')
    .func(nil, 'int getSlotIndex()')
    .func(nil, 'void setSlotIndex(int inValue)')
    .prop('slotIndex', nil, nil)

typeconf 'spine::RGB2Timeline'
    .supercls('spine::CurveTimeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'RGB2Timeline(size_t frameCount, size_t bezierCount, int slotIndex)')
    .func(nil, 'int getSlotIndex()')
    .func(nil, 'void setSlotIndex(int inValue)')
    .prop('slotIndex', nil, nil)

typeconf 'spine::DeformTimeline'
    .supercls('spine::CurveTimeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'DeformTimeline(size_t frameCount, size_t bezierCount, int slotIndex, spine::VertexAttachment *attachment)')
    .func(nil, 'spine::VertexAttachment *getAttachment()')
    .func(nil, 'void setAttachment(spine::VertexAttachment *inValue)')
    .func(nil, 'float getCurvePercent(float time, int frame)')
    .func(nil, 'int getSlotIndex()')
    .func(nil, 'void setSlotIndex(int inValue)')
    .prop('attachment', nil, nil)
    .prop('slotIndex', nil, nil)

typeconf 'spine::DrawOrderTimeline'
    .supercls('spine::Timeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'DrawOrderTimeline(size_t frameCount)')

typeconf 'spine::EventTimeline'
    .supercls('spine::Timeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'EventTimeline(size_t frameCount)')

typeconf 'spine::IkConstraintTimeline'
    .supercls('spine::CurveTimeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'IkConstraintTimeline(size_t frameCount, size_t bezierCount, int ikConstraintIndex)')
    .func(nil, 'int getIkConstraintIndex()')
    .func(nil, 'void setIkConstraintIndex(int inValue)')
    .prop('ikConstraintIndex', nil, nil)

typeconf 'spine::PathConstraintMixTimeline'
    .supercls('spine::CurveTimeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'PathConstraintMixTimeline(size_t frameCount, size_t bezierCount, int pathConstraintIndex)')
    .func(nil, 'int getPathConstraintIndex()')
    .func(nil, 'void setPathConstraintIndex(int inValue)')
    .prop('pathConstraintIndex', nil, nil)

typeconf 'spine::PathConstraintPositionTimeline'
    .supercls('spine::CurveTimeline1')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('ENTRIES', 'spine::PathConstraintPositionTimeline::ENTRIES', 'const int')
    .func(nil, 'PathConstraintPositionTimeline(size_t frameCount, size_t bezierCount, int pathConstraintIndex)')
    .func(nil, 'int getPathConstraintIndex()')
    .func(nil, 'void setPathConstraintIndex(int inValue)')
    .prop('pathConstraintIndex', nil, nil)

typeconf 'spine::PathConstraintSpacingTimeline'
    .supercls('spine::CurveTimeline1')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'PathConstraintSpacingTimeline(size_t frameCount, size_t bezierCount, int pathConstraintIndex)')
    .func(nil, 'int getPathConstraintIndex()')
    .func(nil, 'void setPathConstraintIndex(int inValue)')
    .prop('pathConstraintIndex', nil, nil)

typeconf 'spine::TranslateTimeline'
    .supercls('spine::CurveTimeline2')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'TranslateTimeline(size_t frameCount, size_t bezierCount, int boneIndex)')
    .func(nil, 'int getBoneIndex()')
    .func(nil, 'void setBoneIndex(int inValue)')
    .prop('boneIndex', nil, nil)

typeconf 'spine::ShearTimeline'
    .supercls('spine::CurveTimeline2')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'ShearTimeline(size_t frameCount, size_t bezierCount, int boneIndex)')
    .func(nil, 'int getBoneIndex()')
    .func(nil, 'void setBoneIndex(int inValue)')
    .prop('boneIndex', nil, nil)

typeconf 'spine::TransformConstraintTimeline'
    .supercls('spine::CurveTimeline')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'TransformConstraintTimeline(size_t frameCount, size_t bezierCount, int transformConstraintIndex)')
    .func(nil, 'int getTransformConstraintIndex()')
    .func(nil, 'void setTransformConstraintIndex(int inValue)')
    .prop('transformConstraintIndex', nil, nil)

typeconf 'spine::ScaleTimeline'
    .supercls('spine::CurveTimeline2')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'ScaleTimeline(size_t frameCount, size_t bezierCount, int boneIndex)')
    .func(nil, 'int getBoneIndex()')
    .func(nil, 'void setBoneIndex(int inValue)')
    .prop('boneIndex', nil, nil)

typeconf 'spine::RotateTimeline'
    .supercls('spine::CurveTimeline1')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'RotateTimeline(size_t frameCount, size_t bezierCount, int boneIndex)')
    .func(nil, 'int getBoneIndex()')
    .func(nil, 'void setBoneIndex(int inValue)')
    .prop('boneIndex', nil, nil)

typeconf 'spine::VertexEffect'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::SwirlVertexEffect'
    .supercls('spine::VertexEffect')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void setCenterX(float centerX)')
    .func(nil, 'float getCenterX()')
    .func(nil, 'void setCenterY(float centerY)')
    .func(nil, 'float getCenterY()')
    .func(nil, 'void setRadius(float radius)')
    .func(nil, 'float getRadius()')
    .func(nil, 'void setAngle(float angle)')
    .func(nil, 'float getAngle()')
    .func(nil, 'void setWorldX(float worldX)')
    .func(nil, 'float getWorldX()')
    .func(nil, 'void setWorldY(float worldY)')
    .func(nil, 'float getWorldY()')
    .prop('centerX', nil, nil)
    .prop('centerY', nil, nil)
    .prop('radius', nil, nil)
    .prop('angle', nil, nil)
    .prop('worldX', nil, nil)
    .prop('worldY', nil, nil)

typeconf 'spine::JitterVertexEffect'
    .supercls('spine::VertexEffect')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'JitterVertexEffect(float jitterX, float jitterY)')
    .func(nil, 'void setJitterX(float jitterX)')
    .func(nil, 'float getJitterX()')
    .func(nil, 'void setJitterY(float jitterY)')
    .func(nil, 'float getJitterY()')
    .prop('jitterX', nil, nil)
    .prop('jitterY', nil, nil)

typeconf 'spine::Polygon'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::Skin'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'Skin(const spine::String &name)')
    .func(nil, 'void setAttachment(size_t slotIndex, const spine::String &name, spine::Attachment *attachment)')
    .func(nil, 'spine::Attachment *getAttachment(size_t slotIndex, const spine::String &name)')
    .func(nil, 'void removeAttachment(size_t slotIndex, const spine::String &name)')
    .func(nil, 'const spine::String &getName()')
    .func(nil, 'void addSkin(spine::Skin *other)')
    .func(nil, 'void copySkin(spine::Skin *other)')
    .func(nil, 'Vector<spine::BoneData *> &getBones()')
    .func(nil, 'Vector<spine::ConstraintData *> &getConstraints()')
    .prop('name', nil, nil)
    .prop('bones', nil, nil)
    .prop('constraints', nil, nil)

typeconf 'spine::Atlas'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::Bone'
    .supercls('spine::Updatable')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static void setYDown(bool inValue)')
    .func(nil, 'static bool isYDown()')
    .func(nil, 'void updateWorldTransform()', 'void updateWorldTransform(float x, float y, float rotation, float scaleX, float scaleY, float shearX, float shearY)')
    .func(nil, 'void setToSetupPose()')
    .func(nil, 'float worldToLocalRotation(float worldRotation)')
    .func(nil, 'float localToWorldRotation(float localRotation)')
    .func(nil, 'void rotateWorld(float degrees)')
    .func(nil, 'float getWorldToLocalRotationX()')
    .func(nil, 'float getWorldToLocalRotationY()')
    .func(nil, 'spine::Bone *getParent()')
    .func(nil, 'Vector<spine::Bone *> &getChildren()')
    .func(nil, 'float getX()')
    .func(nil, 'void setX(float inValue)')
    .func(nil, 'float getY()')
    .func(nil, 'void setY(float inValue)')
    .func(nil, 'float getRotation()')
    .func(nil, 'void setRotation(float inValue)')
    .func(nil, 'float getScaleX()')
    .func(nil, 'void setScaleX(float inValue)')
    .func(nil, 'float getScaleY()')
    .func(nil, 'void setScaleY(float inValue)')
    .func(nil, 'float getShearX()')
    .func(nil, 'void setShearX(float inValue)')
    .func(nil, 'float getShearY()')
    .func(nil, 'void setShearY(float inValue)')
    .func(nil, 'float getAppliedRotation()')
    .func(nil, 'void setAppliedRotation(float inValue)')
    .func(nil, 'float getAX()')
    .func(nil, 'void setAX(float inValue)')
    .func(nil, 'float getAY()')
    .func(nil, 'void setAY(float inValue)')
    .func(nil, 'float getAScaleX()')
    .func(nil, 'void setAScaleX(float inValue)')
    .func(nil, 'float getAScaleY()')
    .func(nil, 'void setAScaleY(float inValue)')
    .func(nil, 'float getAShearX()')
    .func(nil, 'void setAShearX(float inValue)')
    .func(nil, 'float getAShearY()')
    .func(nil, 'void setAShearY(float inValue)')
    .func(nil, 'float getA()')
    .func(nil, 'void setA(float inValue)')
    .func(nil, 'float getB()')
    .func(nil, 'void setB(float inValue)')
    .func(nil, 'float getC()')
    .func(nil, 'void setC(float inValue)')
    .func(nil, 'float getD()')
    .func(nil, 'void setD(float inValue)')
    .func(nil, 'float getWorldX()')
    .func(nil, 'void setWorldX(float inValue)')
    .func(nil, 'float getWorldY()')
    .func(nil, 'void setWorldY(float inValue)')
    .func(nil, 'float getWorldRotationX()')
    .func(nil, 'float getWorldRotationY()')
    .func(nil, 'float getWorldScaleX()')
    .func(nil, 'float getWorldScaleY()')
    .prop('yDown', nil, nil)
    .prop('worldToLocalRotationX', nil, nil)
    .prop('worldToLocalRotationY', nil, nil)
    .prop('parent', nil, nil)
    .prop('children', nil, nil)
    .prop('x', nil, nil)
    .prop('y', nil, nil)
    .prop('rotation', nil, nil)
    .prop('scaleX', nil, nil)
    .prop('scaleY', nil, nil)
    .prop('shearX', nil, nil)
    .prop('shearY', nil, nil)
    .prop('appliedRotation', nil, nil)
    .prop('ax', nil, nil)
    .prop('ay', nil, nil)
    .prop('aScaleX', nil, nil)
    .prop('aScaleY', nil, nil)
    .prop('aShearX', nil, nil)
    .prop('aShearY', nil, nil)
    .prop('a', nil, nil)
    .prop('b', nil, nil)
    .prop('c', nil, nil)
    .prop('d', nil, nil)
    .prop('worldX', nil, nil)
    .prop('worldY', nil, nil)
    .prop('worldRotationX', nil, nil)
    .prop('worldRotationY', nil, nil)
    .prop('worldScaleX', nil, nil)
    .prop('worldScaleY', nil, nil)

typeconf 'spine::Slot'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void setToSetupPose()')
    .func(nil, 'spine::Color &getColor()')
    .func(nil, 'spine::Color &getDarkColor()')
    .func(nil, 'bool hasDarkColor()')
    .func(nil, 'spine::Attachment *getAttachment()')
    .func(nil, 'void setAttachment(spine::Attachment *inValue)')
    .func(nil, 'int getAttachmentState()')
    .func(nil, 'void setAttachmentState(int state)')
    .func(nil, 'float getAttachmentTime()')
    .func(nil, 'void setAttachmentTime(float inValue)')
    .func(nil, 'Vector<float> &getDeform()')
    .prop('color', nil, nil)
    .prop('darkColor', nil, nil)
    .prop('attachment', nil, nil)
    .prop('attachmentState', nil, nil)
    .prop('attachmentTime', nil, nil)
    .prop('deform', nil, nil)

typeconf 'spine::Attachment'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'const spine::String &getName()')
    .func(nil, 'spine::Attachment *copy()')
    .func(nil, 'int getRefCount()')
    .func(nil, 'void reference()')
    .func(nil, 'void dereference()')
    .prop('name', nil, nil)
    .prop('refCount', nil, nil)

typeconf 'spine::VertexAttachment'
    .supercls('spine::Attachment')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'int getId()')
    .func(nil, 'Vector<size_t> &getBones()')
    .func(nil, 'Vector<float> &getVertices()')
    .func(nil, 'size_t getWorldVerticesLength()')
    .func(nil, 'void setWorldVerticesLength(size_t inValue)')
    .func(nil, 'spine::VertexAttachment *getDeformAttachment()')
    .func(nil, 'void setDeformAttachment(spine::VertexAttachment *attachment)')
    .func(nil, 'void copyTo(spine::VertexAttachment *other)')
    .prop('id', nil, nil)
    .prop('bones', nil, nil)
    .prop('vertices', nil, nil)
    .prop('worldVerticesLength', nil, nil)
    .prop('deformAttachment', nil, nil)

typeconf 'spine::ClippingAttachment'
    .supercls('spine::VertexAttachment')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'ClippingAttachment(const spine::String &name)')
    .func(nil, 'spine::SlotData *getEndSlot()')
    .func(nil, 'void setEndSlot(spine::SlotData *inValue)')
    .func(nil, 'spine::Color &getColor()')
    .prop('endSlot', nil, nil)
    .prop('color', nil, nil)

typeconf 'spine::BoundingBoxAttachment'
    .supercls('spine::VertexAttachment')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'BoundingBoxAttachment(const spine::String &name)')
    .func(nil, 'spine::Color &getColor()')
    .prop('color', nil, nil)

typeconf 'spine::MeshAttachment'
    .supercls('spine::VertexAttachment')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'MeshAttachment(const spine::String &name)')
    .func(nil, 'void updateUVs()')
    .func(nil, 'int getHullLength()')
    .func(nil, 'void setHullLength(int inValue)')
    .func(nil, 'Vector<float> &getRegionUVs()')
    .func(nil, 'Vector<float> &getUVs()')
    .func(nil, 'Vector<unsigned short> &getTriangles()')
    .func(nil, 'spine::Color &getColor()')
    .func(nil, 'const spine::String &getPath()')
    .func(nil, 'void setPath(const spine::String &inValue)')
    .func(nil, 'float getRegionU()')
    .func(nil, 'void setRegionU(float inValue)')
    .func(nil, 'float getRegionV()')
    .func(nil, 'void setRegionV(float inValue)')
    .func(nil, 'float getRegionU2()')
    .func(nil, 'void setRegionU2(float inValue)')
    .func(nil, 'float getRegionV2()')
    .func(nil, 'void setRegionV2(float inValue)')
    .func(nil, 'int getRegionDegrees()')
    .func(nil, 'void setRegionDegrees(int inValue)')
    .func(nil, 'float getRegionOffsetX()')
    .func(nil, 'void setRegionOffsetX(float inValue)')
    .func(nil, 'float getRegionOffsetY()')
    .func(nil, 'void setRegionOffsetY(float inValue)')
    .func(nil, 'float getRegionWidth()')
    .func(nil, 'void setRegionWidth(float inValue)')
    .func(nil, 'float getRegionHeight()')
    .func(nil, 'void setRegionHeight(float inValue)')
    .func(nil, 'float getRegionOriginalWidth()')
    .func(nil, 'void setRegionOriginalWidth(float inValue)')
    .func(nil, 'float getRegionOriginalHeight()')
    .func(nil, 'void setRegionOriginalHeight(float inValue)')
    .func(nil, 'spine::MeshAttachment *getParentMesh()')
    .func(nil, 'void setParentMesh(spine::MeshAttachment *inValue)')
    .func(nil, 'Vector<unsigned short> &getEdges()')
    .func(nil, 'float getWidth()')
    .func(nil, 'void setWidth(float inValue)')
    .func(nil, 'float getHeight()')
    .func(nil, 'void setHeight(float inValue)')
    .func(nil, 'spine::MeshAttachment *newLinkedMesh()')
    .prop('hullLength', nil, nil)
    .prop('regionUVs', nil, nil)
    .prop('uvs', nil, nil)
    .prop('triangles', nil, nil)
    .prop('color', nil, nil)
    .prop('path', nil, nil)
    .prop('regionU', nil, nil)
    .prop('regionV', nil, nil)
    .prop('regionU2', nil, nil)
    .prop('regionV2', nil, nil)
    .prop('regionDegrees', nil, nil)
    .prop('regionOffsetX', nil, nil)
    .prop('regionOffsetY', nil, nil)
    .prop('regionWidth', nil, nil)
    .prop('regionHeight', nil, nil)
    .prop('regionOriginalWidth', nil, nil)
    .prop('regionOriginalHeight', nil, nil)
    .prop('parentMesh', nil, nil)
    .prop('edges', nil, nil)
    .prop('width', nil, nil)
    .prop('height', nil, nil)

typeconf 'spine::PathAttachment'
    .supercls('spine::VertexAttachment')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'PathAttachment(const spine::String &name)')
    .func(nil, 'Vector<float> &getLengths()')
    .func(nil, 'bool isClosed()')
    .func(nil, 'void setClosed(bool inValue)')
    .func(nil, 'bool isConstantSpeed()')
    .func(nil, 'void setConstantSpeed(bool inValue)')
    .func(nil, 'spine::Color &getColor()')
    .prop('lengths', nil, nil)
    .prop('closed', nil, nil)
    .prop('constantSpeed', nil, nil)
    .prop('color', nil, nil)

typeconf 'spine::PathConstraint'
    .supercls('spine::Updatable')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void apply()')
    .func(nil, 'int getOrder()')
    .func(nil, 'float getPosition()')
    .func(nil, 'void setPosition(float inValue)')
    .func(nil, 'float getSpacing()')
    .func(nil, 'void setSpacing(float inValue)')
    .func(nil, 'float getMixRotate()')
    .func(nil, 'void setMixRotate(float inValue)')
    .func(nil, 'float getMixX()')
    .func(nil, 'void setMixX(float inValue)')
    .func(nil, 'float getMixY()')
    .func(nil, 'void setMixY(float inValue)')
    .func(nil, 'Vector<spine::Bone *> &getBones()')
    .func(nil, 'spine::Slot *getTarget()')
    .func(nil, 'void setTarget(spine::Slot *inValue)')
    .prop('order', nil, nil)
    .prop('position', nil, nil)
    .prop('spacing', nil, nil)
    .prop('mixRotate', nil, nil)
    .prop('mixX', nil, nil)
    .prop('mixY', nil, nil)
    .prop('bones', nil, nil)
    .prop('target', nil, nil)

typeconf 'spine::PointAttachment'
    .supercls('spine::Attachment')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'PointAttachment(const spine::String &name)')
    .func(nil, 'float getX()')
    .func(nil, 'void setX(float inValue)')
    .func(nil, 'float getY()')
    .func(nil, 'void setY(float inValue)')
    .func(nil, 'float getRotation()')
    .func(nil, 'void setRotation(float inValue)')
    .func(nil, 'spine::Color &getColor()')
    .prop('x', nil, nil)
    .prop('y', nil, nil)
    .prop('rotation', nil, nil)
    .prop('color', nil, nil)

typeconf 'spine::RegionAttachment'
    .supercls('spine::Attachment')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'RegionAttachment(const spine::String &name)')
    .func(nil, 'void updateOffset()')
    .func(nil, 'void setUVs(float u, float v, float u2, float v2, float degrees)')
    .func(nil, 'float getX()')
    .func(nil, 'void setX(float inValue)')
    .func(nil, 'float getY()')
    .func(nil, 'void setY(float inValue)')
    .func(nil, 'float getRotation()')
    .func(nil, 'void setRotation(float inValue)')
    .func(nil, 'float getScaleX()')
    .func(nil, 'void setScaleX(float inValue)')
    .func(nil, 'float getScaleY()')
    .func(nil, 'void setScaleY(float inValue)')
    .func(nil, 'float getWidth()')
    .func(nil, 'void setWidth(float inValue)')
    .func(nil, 'float getHeight()')
    .func(nil, 'void setHeight(float inValue)')
    .func(nil, 'spine::Color &getColor()')
    .func(nil, 'const spine::String &getPath()')
    .func(nil, 'void setPath(const spine::String &inValue)')
    .func(nil, 'float getRegionOffsetX()')
    .func(nil, 'void setRegionOffsetX(float inValue)')
    .func(nil, 'float getRegionOffsetY()')
    .func(nil, 'void setRegionOffsetY(float inValue)')
    .func(nil, 'float getRegionWidth()')
    .func(nil, 'void setRegionWidth(float inValue)')
    .func(nil, 'float getRegionHeight()')
    .func(nil, 'void setRegionHeight(float inValue)')
    .func(nil, 'float getRegionOriginalWidth()')
    .func(nil, 'void setRegionOriginalWidth(float inValue)')
    .func(nil, 'float getRegionOriginalHeight()')
    .func(nil, 'void setRegionOriginalHeight(float inValue)')
    .func(nil, 'Vector<float> &getOffset()')
    .func(nil, 'Vector<float> &getUVs()')
    .prop('x', nil, nil)
    .prop('y', nil, nil)
    .prop('rotation', nil, nil)
    .prop('scaleX', nil, nil)
    .prop('scaleY', nil, nil)
    .prop('width', nil, nil)
    .prop('height', nil, nil)
    .prop('color', nil, nil)
    .prop('path', nil, nil)
    .prop('regionOffsetX', nil, nil)
    .prop('regionOffsetY', nil, nil)
    .prop('regionWidth', nil, nil)
    .prop('regionHeight', nil, nil)
    .prop('regionOriginalWidth', nil, nil)
    .prop('regionOriginalHeight', nil, nil)
    .prop('offset', nil, nil)

typeconf 'spine::TrackEntry'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'TrackEntry()')
    .func(nil, 'int getTrackIndex()')
    .func(nil, 'spine::Animation *getAnimation()')
    .func(nil, 'spine::TrackEntry *getPrevious()')
    .func(nil, 'bool getLoop()')
    .func(nil, 'void setLoop(bool inValue)')
    .func(nil, 'bool getHoldPrevious()')
    .func(nil, 'void setHoldPrevious(bool inValue)')
    .func(nil, 'bool getReverse()')
    .func(nil, 'void setReverse(bool inValue)')
    .func(nil, 'float getDelay()')
    .func(nil, 'void setDelay(float inValue)')
    .func(nil, 'float getTrackTime()')
    .func(nil, 'void setTrackTime(float inValue)')
    .func(nil, 'float getTrackEnd()')
    .func(nil, 'void setTrackEnd(float inValue)')
    .func(nil, 'float getAnimationStart()')
    .func(nil, 'void setAnimationStart(float inValue)')
    .func(nil, 'float getAnimationEnd()')
    .func(nil, 'void setAnimationEnd(float inValue)')
    .func(nil, 'float getAnimationLast()')
    .func(nil, 'void setAnimationLast(float inValue)')
    .func(nil, 'float getAnimationTime()')
    .func(nil, 'float getTimeScale()')
    .func(nil, 'void setTimeScale(float inValue)')
    .func(nil, 'float getAlpha()')
    .func(nil, 'void setAlpha(float inValue)')
    .func(nil, 'float getEventThreshold()')
    .func(nil, 'void setEventThreshold(float inValue)')
    .func(nil, 'float getAttachmentThreshold()')
    .func(nil, 'void setAttachmentThreshold(float inValue)')
    .func(nil, 'float getDrawOrderThreshold()')
    .func(nil, 'void setDrawOrderThreshold(float inValue)')
    .func(nil, 'spine::TrackEntry *getNext()')
    .func(nil, 'bool isComplete()')
    .func(nil, 'float getMixTime()')
    .func(nil, 'void setMixTime(float inValue)')
    .func(nil, 'float getMixDuration()')
    .func(nil, 'void setMixDuration(float inValue)')
    .func(nil, 'spine::MixBlend getMixBlend()')
    .func(nil, 'void setMixBlend(spine::MixBlend blend)')
    .func(nil, 'spine::TrackEntry *getMixingFrom()')
    .func(nil, 'spine::TrackEntry *getMixingTo()')
    .func(nil, 'void resetRotationDirections()')
    .func(nil, 'float getTrackComplete()')
    .callback {
        FUNCS =  {
            'void setListener(spine::AnimationStateListener listener)'
        },
        TAG_MAKER = 'Listener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .prop('trackIndex', nil, nil)
    .prop('animation', nil, nil)
    .prop('previous', nil, nil)
    .prop('loop', nil, nil)
    .prop('holdPrevious', nil, nil)
    .prop('reverse', nil, nil)
    .prop('delay', nil, nil)
    .prop('trackTime', nil, nil)
    .prop('trackEnd', nil, nil)
    .prop('animationStart', nil, nil)
    .prop('animationEnd', nil, nil)
    .prop('animationLast', nil, nil)
    .prop('animationTime', nil, nil)
    .prop('timeScale', nil, nil)
    .prop('alpha', nil, nil)
    .prop('eventThreshold', nil, nil)
    .prop('attachmentThreshold', nil, nil)
    .prop('drawOrderThreshold', nil, nil)
    .prop('next', nil, nil)
    .prop('complete', nil, nil)
    .prop('mixTime', nil, nil)
    .prop('mixDuration', nil, nil)
    .prop('mixBlend', nil, nil)
    .prop('mixingFrom', nil, nil)
    .prop('mixingTo', nil, nil)
    .prop('trackComplete', nil, nil)

typeconf 'spine::SkeletonData'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func('__gc', [[
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
    .func('new', [[
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
    .func(nil, 'spine::BoneData *findBone(const spine::String &boneName)')
    .func(nil, 'spine::SlotData *findSlot(const spine::String &slotName)')
    .func(nil, 'spine::Skin *findSkin(const spine::String &skinName)')
    .func(nil, 'spine::EventData *findEvent(const spine::String &eventDataName)')
    .func(nil, 'spine::Animation *findAnimation(const spine::String &animationName)')
    .func(nil, 'spine::IkConstraintData *findIkConstraint(const spine::String &constraintName)')
    .func(nil, 'spine::TransformConstraintData *findTransformConstraint(const spine::String &constraintName)')
    .func(nil, 'spine::PathConstraintData *findPathConstraint(const spine::String &constraintName)')
    .func(nil, 'const spine::String &getName()')
    .func(nil, 'void setName(const spine::String &inValue)')
    .func(nil, 'Vector<spine::BoneData *> &getBones()')
    .func(nil, 'Vector<spine::SlotData *> &getSlots()')
    .func(nil, 'Vector<spine::Skin *> &getSkins()')
    .func(nil, 'spine::Skin *getDefaultSkin()')
    .func(nil, 'void setDefaultSkin(spine::Skin *inValue)')
    .func(nil, 'Vector<spine::EventData *> &getEvents()')
    .func(nil, 'Vector<spine::Animation *> &getAnimations()')
    .func(nil, 'Vector<spine::IkConstraintData *> &getIkConstraints()')
    .func(nil, 'Vector<spine::TransformConstraintData *> &getTransformConstraints()')
    .func(nil, 'Vector<spine::PathConstraintData *> &getPathConstraints()')
    .func(nil, 'float getX()')
    .func(nil, 'void setX(float inValue)')
    .func(nil, 'float getY()')
    .func(nil, 'void setY(float inValue)')
    .func(nil, 'float getWidth()')
    .func(nil, 'void setWidth(float inValue)')
    .func(nil, 'float getHeight()')
    .func(nil, 'void setHeight(float inValue)')
    .func(nil, 'const spine::String &getVersion()')
    .func(nil, 'void setVersion(const spine::String &inValue)')
    .func(nil, 'const spine::String &getHash()')
    .func(nil, 'void setHash(const spine::String &inValue)')
    .func(nil, 'const spine::String &getImagesPath()')
    .func(nil, 'void setImagesPath(const spine::String &inValue)')
    .func(nil, 'const spine::String &getAudioPath()')
    .func(nil, 'void setAudioPath(const spine::String &inValue)')
    .func(nil, 'float getFps()')
    .func(nil, 'void setFps(float inValue)')
    .prop('name', nil, nil)
    .prop('bones', nil, nil)
    .prop('slots', nil, nil)
    .prop('skins', nil, nil)
    .prop('defaultSkin', nil, nil)
    .prop('events', nil, nil)
    .prop('animations', nil, nil)
    .prop('ikConstraints', nil, nil)
    .prop('transformConstraints', nil, nil)
    .prop('pathConstraints', nil, nil)
    .prop('x', nil, nil)
    .prop('y', nil, nil)
    .prop('width', nil, nil)
    .prop('height', nil, nil)
    .prop('version', nil, nil)
    .prop('hash', nil, nil)
    .prop('imagesPath', nil, nil)
    .prop('audioPath', nil, nil)
    .prop('fps', nil, nil)
    .alias('__gc', 'dispose')

typeconf 'spine::Skeleton'
    .supercls('spine::SpineObject')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'Skeleton(spine::SkeletonData *skeletonData)')
    .func(nil, 'void updateCache()')
    .func(nil, 'void printUpdateCache()')
    .func(nil, 'void updateWorldTransform()', 'void updateWorldTransform(spine::Bone *parent)')
    .func(nil, 'void setToSetupPose()')
    .func(nil, 'void setBonesToSetupPose()')
    .func(nil, 'void setSlotsToSetupPose()')
    .func(nil, 'spine::Bone *findBone(const spine::String &boneName)')
    .func(nil, 'spine::Slot *findSlot(const spine::String &slotName)')
    .func(nil, 'void setSkin(const spine::String &skinName)', 'void setSkin(spine::Skin *newSkin)')
    .func(nil, 'spine::Attachment *getAttachment(const spine::String &slotName, const spine::String &attachmentName)', 'spine::Attachment *getAttachment(int slotIndex, const spine::String &attachmentName)')
    .func(nil, 'void setAttachment(const spine::String &slotName, const spine::String &attachmentName)')
    .func(nil, 'spine::IkConstraint *findIkConstraint(const spine::String &constraintName)')
    .func(nil, 'spine::TransformConstraint *findTransformConstraint(const spine::String &constraintName)')
    .func(nil, 'spine::PathConstraint *findPathConstraint(const spine::String &constraintName)')
    .func(nil, 'void update(float delta)')
    .func(nil, 'spine::Bone *getRootBone()')
    .func(nil, 'spine::SkeletonData *getData()')
    .func(nil, 'Vector<spine::Bone *> &getBones()')
    .func(nil, 'Vector<spine::Updatable *> &getUpdateCacheList()')
    .func(nil, 'Vector<spine::Slot *> &getSlots()')
    .func(nil, 'Vector<spine::Slot *> &getDrawOrder()')
    .func(nil, 'Vector<spine::IkConstraint *> &getIkConstraints()')
    .func(nil, 'Vector<spine::PathConstraint *> &getPathConstraints()')
    .func(nil, 'Vector<spine::TransformConstraint *> &getTransformConstraints()')
    .func(nil, 'spine::Skin *getSkin()')
    .func(nil, 'spine::Color &getColor()')
    .func(nil, 'float getTime()')
    .func(nil, 'void setTime(float inValue)')
    .func(nil, 'void setPosition(float x, float y)')
    .func(nil, 'float getX()')
    .func(nil, 'void setX(float inValue)')
    .func(nil, 'float getY()')
    .func(nil, 'void setY(float inValue)')
    .func(nil, 'float getScaleX()')
    .func(nil, 'void setScaleX(float inValue)')
    .func(nil, 'float getScaleY()')
    .func(nil, 'void setScaleY(float inValue)')
    .prop('rootBone', nil, nil)
    .prop('data', nil, nil)
    .prop('bones', nil, nil)
    .prop('updateCacheList', nil, nil)
    .prop('slots', nil, nil)
    .prop('drawOrder', nil, nil)
    .prop('ikConstraints', nil, nil)
    .prop('pathConstraints', nil, nil)
    .prop('transformConstraints', nil, nil)
    .prop('skin', nil, nil)
    .prop('color', nil, nil)
    .prop('time', nil, nil)
    .prop('x', nil, nil)
    .prop('y', nil, nil)
    .prop('scaleX', nil, nil)
    .prop('scaleY', nil, nil)

typeconf 'spine::SkeletonRenderer'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static spine::SkeletonRenderer *create()')
    .func(nil, 'static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)')
    .func(nil, 'static spine::SkeletonRenderer *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)')
    .func(nil, 'static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)', 'static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)')
    .func(nil, 'spine::Skeleton *getSkeleton()')
    .func(nil, 'void setTimeScale(float scale)')
    .func(nil, 'float getTimeScale()')
    .func(nil, 'void setDebugSlotsEnabled(bool enabled)')
    .func(nil, 'bool getDebugSlotsEnabled()')
    .func(nil, 'void setDebugBonesEnabled(bool enabled)')
    .func(nil, 'bool getDebugBonesEnabled()')
    .func(nil, 'void setDebugMeshesEnabled(bool enabled)')
    .func(nil, 'bool getDebugMeshesEnabled()')
    .func(nil, 'void setDebugBoundingRectEnabled(bool enabled)')
    .func(nil, 'bool getDebugBoundingRectEnabled()')
    .func(nil, 'void updateWorldTransform()')
    .func(nil, 'void setToSetupPose()')
    .func(nil, 'void setBonesToSetupPose()')
    .func(nil, 'void setSlotsToSetupPose()')
    .func(nil, 'spine::Bone *findBone(const std::string &boneName)')
    .func(nil, 'spine::Slot *findSlot(const std::string &slotName)')
    .func(nil, 'void setSkin(const std::string &skinName)', 'void setSkin(const char *skinName)')
    .func(nil, 'spine::Attachment *getAttachment(const std::string &slotName, const std::string &attachmentName)')
    .func(nil, 'bool setAttachment(const std::string &slotName, const std::string &attachmentName)', 'bool setAttachment(const std::string &slotName, const char *attachmentName)')
    .func(nil, 'void setTwoColorTint(bool enabled)')
    .func(nil, 'bool isTwoColorTint()')
    .func(nil, 'void setVertexEffect(spine::VertexEffect *effect)')
    .func(nil, 'void setSlotsRange(int startSlotIndex, int endSlotIndex)')
    .func(nil, 'void setBlendFunc(const cocos2d::BlendFunc &blendFunc)')
    .func(nil, 'const cocos2d::BlendFunc &getBlendFunc()')
    .func(nil, 'SkeletonRenderer()', 'SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)', 'SkeletonRenderer(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)', 'SkeletonRenderer(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)', 'SkeletonRenderer(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)')
    .func(nil, 'void initWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)')
    .func(nil, 'void initWithData(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)')
    .func(nil, 'void initWithJsonFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)', 'void initWithJsonFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)')
    .func(nil, 'void initWithBinaryFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)', 'void initWithBinaryFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)')
    .func(nil, 'void initialize()')
    .prop('skeleton', nil, nil)
    .prop('timeScale', nil, nil)
    .prop('debugSlotsEnabled', nil, nil)
    .prop('debugBonesEnabled', nil, nil)
    .prop('debugMeshesEnabled', nil, nil)
    .prop('debugBoundingRectEnabled', nil, nil)
    .prop('twoColorTint', nil, nil)
    .prop('blendFunc', nil, nil)

typeconf 'spine::StartListener'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::InterruptListener'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::EndListener'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::DisposeListener'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::CompleteListener'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::EventListener'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::UpdateWorldTransformsListener'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'spine::SkeletonAnimation'
    .supercls('spine::SkeletonRenderer')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static spine::SkeletonAnimation *create()')
    .func(nil, 'static spine::SkeletonAnimation *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)')
    .func(nil, 'static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, spine::Atlas *atlas, @optional float scale)', 'static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, const std::string &atlasFile, @optional float scale)')
    .func(nil, 'static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, spine::Atlas *atlas, @optional float scale)', 'static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, const std::string &atlasFile, @optional float scale)')
    .func(nil, 'void setAnimationStateData(spine::AnimationStateData *stateData)')
    .func(nil, 'void setMix(const std::string &fromAnimation, const std::string &toAnimation, float duration)')
    .func(nil, '@addref(trackEntries |) spine::TrackEntry *setAnimation(int trackIndex, const std::string &name, bool loop)')
    .func(nil, '@addref(trackEntries |) spine::TrackEntry *addAnimation(int trackIndex, const std::string &name, bool loop, @optional float delay)')
    .func(nil, '@addref(trackEntries |) spine::TrackEntry *setEmptyAnimation(int trackIndex, float mixDuration)')
    .func(nil, 'void setEmptyAnimations(float mixDuration)')
    .func(nil, '@addref(trackEntries |) spine::TrackEntry *addEmptyAnimation(int trackIndex, float mixDuration, @optional float delay)')
    .func(nil, 'spine::Animation *findAnimation(const std::string &name)')
    .func(nil, '@addref(trackEntries |) spine::TrackEntry *getCurrent(@optional int trackIndex)')
    .func(nil, 'void clearTracks()')
    .func(nil, 'void clearTrack(@optional int trackIndex)')
    .func(nil, 'void onAnimationStateEvent(spine::TrackEntry *entry, spine::EventType type, spine::Event *event)')
    .func(nil, 'void onTrackEntryEvent(spine::TrackEntry *entry, spine::EventType type, spine::Event *event)')
    .func(nil, '@addref(state ^) spine::AnimationState *getState()')
    .func(nil, 'void setUpdateOnlyIfVisible(bool status)')
    .func(nil, 'SkeletonAnimation()')
    .callback {
        FUNCS =  {
            'void setStartListener(const spine::StartListener &listener)'
        },
        TAG_MAKER = 'StartListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setInterruptListener(const spine::InterruptListener &listener)'
        },
        TAG_MAKER = 'InterruptListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setEndListener(const spine::EndListener &listener)'
        },
        TAG_MAKER = 'EndListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setDisposeListener(const spine::DisposeListener &listener)'
        },
        TAG_MAKER = 'DisposeListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setCompleteListener(const spine::CompleteListener &listener)'
        },
        TAG_MAKER = 'CompleteListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setEventListener(const spine::EventListener &listener)'
        },
        TAG_MAKER = 'EventListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setTrackStartListener(spine::TrackEntry *entry, const spine::StartListener &listener)'
        },
        TAG_MAKER = 'TrackStartListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setTrackInterruptListener(spine::TrackEntry *entry, const spine::InterruptListener &listener)'
        },
        TAG_MAKER = 'TrackInterruptListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setTrackEndListener(spine::TrackEntry *entry, const spine::EndListener &listener)'
        },
        TAG_MAKER = 'TrackEndListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setTrackDisposeListener(spine::TrackEntry *entry, const spine::DisposeListener &listener)'
        },
        TAG_MAKER = 'TrackDisposeListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setTrackCompleteListener(spine::TrackEntry *entry, const spine::CompleteListener &listener)'
        },
        TAG_MAKER = 'TrackCompleteListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setTrackEventListener(spine::TrackEntry *entry, const spine::EventListener &listener)'
        },
        TAG_MAKER = 'TrackEventListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setPreUpdateWorldTransformsListener(@localvar const spine::UpdateWorldTransformsListener &listener)'
        },
        TAG_MAKER = 'PreUpdateWorldTransformsListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'void setPostUpdateWorldTransformsListener(@localvar const spine::UpdateWorldTransformsListener &listener)'
        },
        TAG_MAKER = 'PostUpdateWorldTransformsListener',
        TAG_MODE = 'replace',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .prop('state', nil, nil)
