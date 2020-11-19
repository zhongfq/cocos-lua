//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_dragonbones.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "cocos2d.h"
#include "CCDragonBonesHeaders.h"



int auto_olua_push_dragonBones_Rectangle(lua_State *L, const dragonBones::Rectangle *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_number(L, (lua_Number)value->x);
        olua_setfield(L, -2, "x");

        olua_push_number(L, (lua_Number)value->y);
        olua_setfield(L, -2, "y");

        olua_push_number(L, (lua_Number)value->width);
        olua_setfield(L, -2, "width");

        olua_push_number(L, (lua_Number)value->height);
        olua_setfield(L, -2, "height");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_dragonBones_Rectangle(lua_State *L, int idx, dragonBones::Rectangle *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** width */
    lua_Number arg4 = 0;       /** height */

    olua_getfield(L, idx, "x");
    olua_check_number(L, -1, &arg1);
    value->x = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "y");
    olua_check_number(L, -1, &arg2);
    value->y = (float)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "width");
    olua_check_number(L, -1, &arg3);
    value->width = (float)arg3;
    lua_pop(L, 1);

    olua_getfield(L, idx, "height");
    olua_check_number(L, -1, &arg4);
    value->height = (float)arg4;
    lua_pop(L, 1);
}

bool auto_olua_is_dragonBones_Rectangle(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "height") && olua_hasfield(L, idx, "width") && olua_hasfield(L, idx, "y") && olua_hasfield(L, idx, "x");
}

void auto_olua_pack_dragonBones_Rectangle(lua_State *L, int idx, dragonBones::Rectangle *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** width */
    lua_Number arg4 = 0;       /** height */

    olua_check_number(L, idx + 0, &arg1);
    value->x = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->y = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->width = (float)arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->height = (float)arg4;
}

int auto_olua_unpack_dragonBones_Rectangle(lua_State *L, const dragonBones::Rectangle *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->x);
        olua_push_number(L, (lua_Number)value->y);
        olua_push_number(L, (lua_Number)value->width);
        olua_push_number(L, (lua_Number)value->height);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_dragonBones_Rectangle(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3);
}

static int luaopen_dragonBones_BinaryOffset(lua_State *L)
{
    oluacls_class(L, "db.BinaryOffset", nullptr);
    oluacls_const_integer(L, "DeformCount", (lua_Integer)dragonBones::BinaryOffset::DeformCount);
    oluacls_const_integer(L, "DeformFloatOffset", (lua_Integer)dragonBones::BinaryOffset::DeformFloatOffset);
    oluacls_const_integer(L, "DeformValueCount", (lua_Integer)dragonBones::BinaryOffset::DeformValueCount);
    oluacls_const_integer(L, "DeformValueOffset", (lua_Integer)dragonBones::BinaryOffset::DeformValueOffset);
    oluacls_const_integer(L, "DeformVertexOffset", (lua_Integer)dragonBones::BinaryOffset::DeformVertexOffset);
    oluacls_const_integer(L, "FrameCurveSamples", (lua_Integer)dragonBones::BinaryOffset::FrameCurveSamples);
    oluacls_const_integer(L, "FramePosition", (lua_Integer)dragonBones::BinaryOffset::FramePosition);
    oluacls_const_integer(L, "FrameTweenEasingOrCurveSampleCount", (lua_Integer)dragonBones::BinaryOffset::FrameTweenEasingOrCurveSampleCount);
    oluacls_const_integer(L, "FrameTweenType", (lua_Integer)dragonBones::BinaryOffset::FrameTweenType);
    oluacls_const_integer(L, "MeshFloatOffset", (lua_Integer)dragonBones::BinaryOffset::MeshFloatOffset);
    oluacls_const_integer(L, "MeshTriangleCount", (lua_Integer)dragonBones::BinaryOffset::MeshTriangleCount);
    oluacls_const_integer(L, "MeshVertexCount", (lua_Integer)dragonBones::BinaryOffset::MeshVertexCount);
    oluacls_const_integer(L, "MeshVertexIndices", (lua_Integer)dragonBones::BinaryOffset::MeshVertexIndices);
    oluacls_const_integer(L, "MeshWeightOffset", (lua_Integer)dragonBones::BinaryOffset::MeshWeightOffset);
    oluacls_const_integer(L, "TimelineFrameOffset", (lua_Integer)dragonBones::BinaryOffset::TimelineFrameOffset);
    oluacls_const_integer(L, "TimelineFrameValueCount", (lua_Integer)dragonBones::BinaryOffset::TimelineFrameValueCount);
    oluacls_const_integer(L, "TimelineFrameValueOffset", (lua_Integer)dragonBones::BinaryOffset::TimelineFrameValueOffset);
    oluacls_const_integer(L, "TimelineKeyFrameCount", (lua_Integer)dragonBones::BinaryOffset::TimelineKeyFrameCount);
    oluacls_const_integer(L, "TimelineOffset", (lua_Integer)dragonBones::BinaryOffset::TimelineOffset);
    oluacls_const_integer(L, "TimelineScale", (lua_Integer)dragonBones::BinaryOffset::TimelineScale);
    oluacls_const_integer(L, "WeigthBoneCount", (lua_Integer)dragonBones::BinaryOffset::WeigthBoneCount);
    oluacls_const_integer(L, "WeigthBoneIndices", (lua_Integer)dragonBones::BinaryOffset::WeigthBoneIndices);
    oluacls_const_integer(L, "WeigthFloatOffset", (lua_Integer)dragonBones::BinaryOffset::WeigthFloatOffset);

    olua_registerluatype<dragonBones::BinaryOffset>(L, "db.BinaryOffset");

    return 1;
}

static int luaopen_dragonBones_ArmatureType(lua_State *L)
{
    oluacls_class(L, "db.ArmatureType", nullptr);
    oluacls_const_integer(L, "Armature", (lua_Integer)dragonBones::ArmatureType::Armature);
    oluacls_const_integer(L, "MovieClip", (lua_Integer)dragonBones::ArmatureType::MovieClip);
    oluacls_const_integer(L, "Stage", (lua_Integer)dragonBones::ArmatureType::Stage);

    olua_registerluatype<dragonBones::ArmatureType>(L, "db.ArmatureType");

    return 1;
}

static int luaopen_dragonBones_OffsetMode(lua_State *L)
{
    oluacls_class(L, "db.OffsetMode", nullptr);
    oluacls_const_integer(L, "Additive", (lua_Integer)dragonBones::OffsetMode::Additive);
    oluacls_const_integer(L, "None", (lua_Integer)dragonBones::OffsetMode::None);
    oluacls_const_integer(L, "Override", (lua_Integer)dragonBones::OffsetMode::Override);

    olua_registerluatype<dragonBones::OffsetMode>(L, "db.OffsetMode");

    return 1;
}

static int luaopen_dragonBones_DisplayType(lua_State *L)
{
    oluacls_class(L, "db.DisplayType", nullptr);
    oluacls_const_integer(L, "Armature", (lua_Integer)dragonBones::DisplayType::Armature);
    oluacls_const_integer(L, "BoundingBox", (lua_Integer)dragonBones::DisplayType::BoundingBox);
    oluacls_const_integer(L, "Image", (lua_Integer)dragonBones::DisplayType::Image);
    oluacls_const_integer(L, "Mesh", (lua_Integer)dragonBones::DisplayType::Mesh);
    oluacls_const_integer(L, "Path", (lua_Integer)dragonBones::DisplayType::Path);

    olua_registerluatype<dragonBones::DisplayType>(L, "db.DisplayType");

    return 1;
}

static int luaopen_dragonBones_BoundingBoxType(lua_State *L)
{
    oluacls_class(L, "db.BoundingBoxType", nullptr);
    oluacls_const_integer(L, "Ellipse", (lua_Integer)dragonBones::BoundingBoxType::Ellipse);
    oluacls_const_integer(L, "Polygon", (lua_Integer)dragonBones::BoundingBoxType::Polygon);
    oluacls_const_integer(L, "Rectangle", (lua_Integer)dragonBones::BoundingBoxType::Rectangle);

    olua_registerluatype<dragonBones::BoundingBoxType>(L, "db.BoundingBoxType");

    return 1;
}

static int luaopen_dragonBones_ActionType(lua_State *L)
{
    oluacls_class(L, "db.ActionType", nullptr);
    oluacls_const_integer(L, "Frame", (lua_Integer)dragonBones::ActionType::Frame);
    oluacls_const_integer(L, "Play", (lua_Integer)dragonBones::ActionType::Play);
    oluacls_const_integer(L, "Sound", (lua_Integer)dragonBones::ActionType::Sound);

    olua_registerluatype<dragonBones::ActionType>(L, "db.ActionType");

    return 1;
}

static int luaopen_dragonBones_BlendMode(lua_State *L)
{
    oluacls_class(L, "db.BlendMode", nullptr);
    oluacls_const_integer(L, "Add", (lua_Integer)dragonBones::BlendMode::Add);
    oluacls_const_integer(L, "Alpha", (lua_Integer)dragonBones::BlendMode::Alpha);
    oluacls_const_integer(L, "Darken", (lua_Integer)dragonBones::BlendMode::Darken);
    oluacls_const_integer(L, "Difference", (lua_Integer)dragonBones::BlendMode::Difference);
    oluacls_const_integer(L, "Erase", (lua_Integer)dragonBones::BlendMode::Erase);
    oluacls_const_integer(L, "HardLight", (lua_Integer)dragonBones::BlendMode::HardLight);
    oluacls_const_integer(L, "Invert", (lua_Integer)dragonBones::BlendMode::Invert);
    oluacls_const_integer(L, "Layer", (lua_Integer)dragonBones::BlendMode::Layer);
    oluacls_const_integer(L, "Lighten", (lua_Integer)dragonBones::BlendMode::Lighten);
    oluacls_const_integer(L, "Multiply", (lua_Integer)dragonBones::BlendMode::Multiply);
    oluacls_const_integer(L, "Normal", (lua_Integer)dragonBones::BlendMode::Normal);
    oluacls_const_integer(L, "Overlay", (lua_Integer)dragonBones::BlendMode::Overlay);
    oluacls_const_integer(L, "Screen", (lua_Integer)dragonBones::BlendMode::Screen);
    oluacls_const_integer(L, "Subtract", (lua_Integer)dragonBones::BlendMode::Subtract);

    olua_registerluatype<dragonBones::BlendMode>(L, "db.BlendMode");

    return 1;
}

static int luaopen_dragonBones_TweenType(lua_State *L)
{
    oluacls_class(L, "db.TweenType", nullptr);
    oluacls_const_integer(L, "Curve", (lua_Integer)dragonBones::TweenType::Curve);
    oluacls_const_integer(L, "Line", (lua_Integer)dragonBones::TweenType::Line);
    oluacls_const_integer(L, "None", (lua_Integer)dragonBones::TweenType::None);
    oluacls_const_integer(L, "QuadIn", (lua_Integer)dragonBones::TweenType::QuadIn);
    oluacls_const_integer(L, "QuadInOut", (lua_Integer)dragonBones::TweenType::QuadInOut);
    oluacls_const_integer(L, "QuadOut", (lua_Integer)dragonBones::TweenType::QuadOut);

    olua_registerluatype<dragonBones::TweenType>(L, "db.TweenType");

    return 1;
}

static int luaopen_dragonBones_TimelineType(lua_State *L)
{
    oluacls_class(L, "db.TimelineType", nullptr);
    oluacls_const_integer(L, "Action", (lua_Integer)dragonBones::TimelineType::Action);
    oluacls_const_integer(L, "AnimationTime", (lua_Integer)dragonBones::TimelineType::AnimationTime);
    oluacls_const_integer(L, "AnimationWeight", (lua_Integer)dragonBones::TimelineType::AnimationWeight);
    oluacls_const_integer(L, "BoneAll", (lua_Integer)dragonBones::TimelineType::BoneAll);
    oluacls_const_integer(L, "BoneRotate", (lua_Integer)dragonBones::TimelineType::BoneRotate);
    oluacls_const_integer(L, "BoneScale", (lua_Integer)dragonBones::TimelineType::BoneScale);
    oluacls_const_integer(L, "BoneTranslate", (lua_Integer)dragonBones::TimelineType::BoneTranslate);
    oluacls_const_integer(L, "IKConstraint", (lua_Integer)dragonBones::TimelineType::IKConstraint);
    oluacls_const_integer(L, "SlotColor", (lua_Integer)dragonBones::TimelineType::SlotColor);
    oluacls_const_integer(L, "SlotDeform", (lua_Integer)dragonBones::TimelineType::SlotDeform);
    oluacls_const_integer(L, "SlotDisplay", (lua_Integer)dragonBones::TimelineType::SlotDisplay);
    oluacls_const_integer(L, "ZOrder", (lua_Integer)dragonBones::TimelineType::ZOrder);

    olua_registerluatype<dragonBones::TimelineType>(L, "db.TimelineType");

    return 1;
}

static int luaopen_dragonBones_AnimationFadeOutMode(lua_State *L)
{
    oluacls_class(L, "db.AnimationFadeOutMode", nullptr);
    oluacls_const_integer(L, "All", (lua_Integer)dragonBones::AnimationFadeOutMode::All);
    oluacls_const_integer(L, "None", (lua_Integer)dragonBones::AnimationFadeOutMode::None);
    oluacls_const_integer(L, "SameGroup", (lua_Integer)dragonBones::AnimationFadeOutMode::SameGroup);
    oluacls_const_integer(L, "SameLayer", (lua_Integer)dragonBones::AnimationFadeOutMode::SameLayer);
    oluacls_const_integer(L, "SameLayerAndGroup", (lua_Integer)dragonBones::AnimationFadeOutMode::SameLayerAndGroup);
    oluacls_const_integer(L, "Single", (lua_Integer)dragonBones::AnimationFadeOutMode::Single);

    olua_registerluatype<dragonBones::AnimationFadeOutMode>(L, "db.AnimationFadeOutMode");

    return 1;
}

static int luaopen_dragonBones_TextureFormat(lua_State *L)
{
    oluacls_class(L, "db.TextureFormat", nullptr);
    oluacls_const_integer(L, "BGRA8888", (lua_Integer)dragonBones::TextureFormat::BGRA8888);
    oluacls_const_integer(L, "DEFAULT", (lua_Integer)dragonBones::TextureFormat::DEFAULT);
    oluacls_const_integer(L, "RGB565", (lua_Integer)dragonBones::TextureFormat::RGB565);
    oluacls_const_integer(L, "RGB888", (lua_Integer)dragonBones::TextureFormat::RGB888);
    oluacls_const_integer(L, "RGBA4444", (lua_Integer)dragonBones::TextureFormat::RGBA4444);
    oluacls_const_integer(L, "RGBA5551", (lua_Integer)dragonBones::TextureFormat::RGBA5551);
    oluacls_const_integer(L, "RGBA8888", (lua_Integer)dragonBones::TextureFormat::RGBA8888);

    olua_registerluatype<dragonBones::TextureFormat>(L, "db.TextureFormat");

    return 1;
}

static int _dragonBones_BaseObject___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::BaseObject *)olua_toobj(L, 1, "db.BaseObject");
    olua_push_cppobj(L, self, "db.BaseObject");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_BaseObject_clearPool1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** classTypeIndex */

    olua_check_uint(L, 1, &arg1);

    // static void clearPool(@optional std::size_t classTypeIndex)
    dragonBones::BaseObject::clearPool((std::size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseObject_clearPool2(lua_State *L)
{
    olua_startinvoke(L);

    // static void clearPool(@optional std::size_t classTypeIndex)
    dragonBones::BaseObject::clearPool();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseObject_clearPool(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static void clearPool(@optional std::size_t classTypeIndex)
        return _dragonBones_BaseObject_clearPool2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // static void clearPool(@optional std::size_t classTypeIndex)
            return _dragonBones_BaseObject_clearPool1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseObject::clearPool' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseObject_getClassTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseObject");

    // std::size_t getClassTypeIndex()
    std::size_t ret = self->getClassTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseObject_returnToPool(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseObject");

    // void returnToPool()
    self->returnToPool();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseObject_setMaxCount(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** classTypeIndex */
    lua_Unsigned arg2 = 0;       /** maxCount */

    olua_check_uint(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static void setMaxCount(std::size_t classTypeIndex, unsigned int maxCount)
    dragonBones::BaseObject::setMaxCount((std::size_t)arg1, (unsigned int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_BaseObject(lua_State *L)
{
    oluacls_class(L, "db.BaseObject", nullptr);
    oluacls_func(L, "__move", _dragonBones_BaseObject___move);
    oluacls_func(L, "clearPool", _dragonBones_BaseObject_clearPool);
    oluacls_func(L, "getClassTypeIndex", _dragonBones_BaseObject_getClassTypeIndex);
    oluacls_func(L, "returnToPool", _dragonBones_BaseObject_returnToPool);
    oluacls_func(L, "setMaxCount", _dragonBones_BaseObject_setMaxCount);
    oluacls_prop(L, "classTypeIndex", _dragonBones_BaseObject_getClassTypeIndex, nullptr);

    olua_registerluatype<dragonBones::BaseObject>(L, "db.BaseObject");

    return 1;
}

static int _dragonBones_EventObject___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::EventObject *)olua_toobj(L, 1, "db.EventObject");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::EventObject *)olua_toobj(L, 1, "db.EventObject");
    olua_push_cppobj(L, self, "db.EventObject");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_EventObject_actionDataToInstance(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *arg1 = nullptr;       /** data */
    dragonBones::EventObject *arg2 = nullptr;       /** instance */
    dragonBones::Armature *arg3 = nullptr;       /** armature */

    olua_check_cppobj(L, 1, (void **)&arg1, "db.ActionData");
    olua_check_cppobj(L, 2, (void **)&arg2, "db.EventObject");
    olua_check_cppobj(L, 3, (void **)&arg3, "db.Armature");

    // static void actionDataToInstance(const dragonBones::ActionData *data, dragonBones::EventObject *instance, dragonBones::Armature *armature)
    dragonBones::EventObject::actionDataToInstance(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_getAnimationState(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // dragonBones::AnimationState *getAnimationState()
    dragonBones::AnimationState *ret = self->getAnimationState();
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_getArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // dragonBones::Armature *getArmature()
    dragonBones::Armature *ret = self->getArmature();
    int num_ret = olua_push_cppobj(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_getBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // dragonBones::Bone *getBone()
    dragonBones::Bone *ret = self->getBone();
    int num_ret = olua_push_cppobj(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_getData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // dragonBones::UserData *getData()
    dragonBones::UserData *ret = self->getData();
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_getSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // dragonBones::Slot *getSlot()
    dragonBones::Slot *ret = self->getSlot();
    int num_ret = olua_push_cppobj(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::EventObject::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_new(lua_State *L)
{
    olua_startinvoke(L);

    // EventObject()
    dragonBones::EventObject *ret = new dragonBones::EventObject();
    int num_ret = olua_push_cppobj(L, ret, "db.EventObject");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_get_COMPLETE(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *COMPLETE
    const char *ret = dragonBones::EventObject::COMPLETE;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_COMPLETE(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** COMPLETE */

    olua_check_string(L, 1, &arg1);

    // static const char *COMPLETE
    dragonBones::EventObject::COMPLETE = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_FADE_IN(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *FADE_IN
    const char *ret = dragonBones::EventObject::FADE_IN;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_FADE_IN(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** FADE_IN */

    olua_check_string(L, 1, &arg1);

    // static const char *FADE_IN
    dragonBones::EventObject::FADE_IN = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_FADE_IN_COMPLETE(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *FADE_IN_COMPLETE
    const char *ret = dragonBones::EventObject::FADE_IN_COMPLETE;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_FADE_IN_COMPLETE(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** FADE_IN_COMPLETE */

    olua_check_string(L, 1, &arg1);

    // static const char *FADE_IN_COMPLETE
    dragonBones::EventObject::FADE_IN_COMPLETE = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_FADE_OUT(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *FADE_OUT
    const char *ret = dragonBones::EventObject::FADE_OUT;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_FADE_OUT(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** FADE_OUT */

    olua_check_string(L, 1, &arg1);

    // static const char *FADE_OUT
    dragonBones::EventObject::FADE_OUT = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_FADE_OUT_COMPLETE(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *FADE_OUT_COMPLETE
    const char *ret = dragonBones::EventObject::FADE_OUT_COMPLETE;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_FADE_OUT_COMPLETE(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** FADE_OUT_COMPLETE */

    olua_check_string(L, 1, &arg1);

    // static const char *FADE_OUT_COMPLETE
    dragonBones::EventObject::FADE_OUT_COMPLETE = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_FRAME_EVENT(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *FRAME_EVENT
    const char *ret = dragonBones::EventObject::FRAME_EVENT;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_FRAME_EVENT(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** FRAME_EVENT */

    olua_check_string(L, 1, &arg1);

    // static const char *FRAME_EVENT
    dragonBones::EventObject::FRAME_EVENT = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_LOOP_COMPLETE(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *LOOP_COMPLETE
    const char *ret = dragonBones::EventObject::LOOP_COMPLETE;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_LOOP_COMPLETE(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** LOOP_COMPLETE */

    olua_check_string(L, 1, &arg1);

    // static const char *LOOP_COMPLETE
    dragonBones::EventObject::LOOP_COMPLETE = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_SOUND_EVENT(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *SOUND_EVENT
    const char *ret = dragonBones::EventObject::SOUND_EVENT;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_SOUND_EVENT(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** SOUND_EVENT */

    olua_check_string(L, 1, &arg1);

    // static const char *SOUND_EVENT
    dragonBones::EventObject::SOUND_EVENT = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_START(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *START
    const char *ret = dragonBones::EventObject::START;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_START(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** START */

    olua_check_string(L, 1, &arg1);

    // static const char *START
    dragonBones::EventObject::START = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_actionData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // const dragonBones::ActionData *actionData
    const dragonBones::ActionData *ret = self->actionData;
    int num_ret = olua_push_cppobj(L, ret, "db.ActionData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_actionData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::ActionData *arg1 = nullptr;       /** actionData */

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.ActionData");

    // const dragonBones::ActionData *actionData
    self->actionData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_animationState(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // dragonBones::AnimationState *animationState
    dragonBones::AnimationState *ret = self->animationState;
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_animationState(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::AnimationState *arg1 = nullptr;       /** animationState */

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.AnimationState");

    // dragonBones::AnimationState *animationState
    self->animationState = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_armature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // dragonBones::Armature *armature
    dragonBones::Armature *ret = self->armature;
    int num_ret = olua_push_cppobj(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_armature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Armature");

    // dragonBones::Armature *armature
    self->armature = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_bone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // dragonBones::Bone *bone
    dragonBones::Bone *ret = self->bone;
    int num_ret = olua_push_cppobj(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_bone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::Bone *arg1 = nullptr;       /** bone */

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Bone");

    // dragonBones::Bone *bone
    self->bone = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_data(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // dragonBones::UserData *data
    dragonBones::UserData *ret = self->data;
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_data(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.UserData");

    // dragonBones::UserData *data
    self->data = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_slot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // dragonBones::Slot *slot
    dragonBones::Slot *ret = self->slot;
    int num_ret = olua_push_cppobj(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_slot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::Slot *arg1 = nullptr;       /** slot */

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Slot");

    // dragonBones::Slot *slot
    self->slot = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_time(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // float time
    float ret = self->time;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_time(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    lua_Number arg1 = 0;       /** time */

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");
    olua_check_number(L, 2, &arg1);

    // float time
    self->time = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_EventObject_get_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");

    // std::string type
    std::string ret = self->type;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_EventObject_set_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    std::string arg1;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "db.EventObject");
    olua_check_std_string(L, 2, &arg1);

    // std::string type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_EventObject(lua_State *L)
{
    oluacls_class(L, "db.EventObject", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_EventObject___gc);
    oluacls_func(L, "__move", _dragonBones_EventObject___move);
    oluacls_func(L, "actionDataToInstance", _dragonBones_EventObject_actionDataToInstance);
    oluacls_func(L, "getAnimationState", _dragonBones_EventObject_getAnimationState);
    oluacls_func(L, "getArmature", _dragonBones_EventObject_getArmature);
    oluacls_func(L, "getBone", _dragonBones_EventObject_getBone);
    oluacls_func(L, "getData", _dragonBones_EventObject_getData);
    oluacls_func(L, "getSlot", _dragonBones_EventObject_getSlot);
    oluacls_func(L, "getTypeIndex", _dragonBones_EventObject_getTypeIndex);
    oluacls_func(L, "new", _dragonBones_EventObject_new);
    oluacls_prop(L, "animationState", _dragonBones_EventObject_getAnimationState, nullptr);
    oluacls_prop(L, "armature", _dragonBones_EventObject_getArmature, nullptr);
    oluacls_prop(L, "bone", _dragonBones_EventObject_getBone, nullptr);
    oluacls_prop(L, "data", _dragonBones_EventObject_getData, nullptr);
    oluacls_prop(L, "slot", _dragonBones_EventObject_getSlot, nullptr);
    oluacls_prop(L, "typeIndex", _dragonBones_EventObject_getTypeIndex, nullptr);
    oluacls_prop(L, "COMPLETE", _dragonBones_EventObject_get_COMPLETE, _dragonBones_EventObject_set_COMPLETE);
    oluacls_prop(L, "FADE_IN", _dragonBones_EventObject_get_FADE_IN, _dragonBones_EventObject_set_FADE_IN);
    oluacls_prop(L, "FADE_IN_COMPLETE", _dragonBones_EventObject_get_FADE_IN_COMPLETE, _dragonBones_EventObject_set_FADE_IN_COMPLETE);
    oluacls_prop(L, "FADE_OUT", _dragonBones_EventObject_get_FADE_OUT, _dragonBones_EventObject_set_FADE_OUT);
    oluacls_prop(L, "FADE_OUT_COMPLETE", _dragonBones_EventObject_get_FADE_OUT_COMPLETE, _dragonBones_EventObject_set_FADE_OUT_COMPLETE);
    oluacls_prop(L, "FRAME_EVENT", _dragonBones_EventObject_get_FRAME_EVENT, _dragonBones_EventObject_set_FRAME_EVENT);
    oluacls_prop(L, "LOOP_COMPLETE", _dragonBones_EventObject_get_LOOP_COMPLETE, _dragonBones_EventObject_set_LOOP_COMPLETE);
    oluacls_prop(L, "SOUND_EVENT", _dragonBones_EventObject_get_SOUND_EVENT, _dragonBones_EventObject_set_SOUND_EVENT);
    oluacls_prop(L, "START", _dragonBones_EventObject_get_START, _dragonBones_EventObject_set_START);
    oluacls_prop(L, "actionData", _dragonBones_EventObject_get_actionData, _dragonBones_EventObject_set_actionData);
    oluacls_prop(L, "animationState", _dragonBones_EventObject_get_animationState, _dragonBones_EventObject_set_animationState);
    oluacls_prop(L, "armature", _dragonBones_EventObject_get_armature, _dragonBones_EventObject_set_armature);
    oluacls_prop(L, "bone", _dragonBones_EventObject_get_bone, _dragonBones_EventObject_set_bone);
    oluacls_prop(L, "data", _dragonBones_EventObject_get_data, _dragonBones_EventObject_set_data);
    oluacls_prop(L, "name", _dragonBones_EventObject_get_name, _dragonBones_EventObject_set_name);
    oluacls_prop(L, "slot", _dragonBones_EventObject_get_slot, _dragonBones_EventObject_set_slot);
    oluacls_prop(L, "time", _dragonBones_EventObject_get_time, _dragonBones_EventObject_set_time);
    oluacls_prop(L, "type", _dragonBones_EventObject_get_type, _dragonBones_EventObject_set_type);

    olua_registerluatype<dragonBones::EventObject>(L, "db.EventObject");

    return 1;
}

static int _dragonBones_TransformObject___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::TransformObject *)olua_toobj(L, 1, "db.TransformObject");
    olua_push_cppobj(L, self, "db.TransformObject");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_TransformObject_getArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TransformObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TransformObject");

    // dragonBones::Armature *getArmature()
    dragonBones::Armature *ret = self->getArmature();
    int num_ret = olua_push_cppobj(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TransformObject_updateGlobalTransform(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TransformObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TransformObject");

    // void updateGlobalTransform()
    self->updateGlobalTransform();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TransformObject_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TransformObject *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TransformObject");

    // void *userData
    void *ret = self->userData;
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TransformObject_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TransformObject *self = nullptr;
    void *arg1 = nullptr;       /** userData */

    olua_to_cppobj(L, 1, (void **)&self, "db.TransformObject");
    olua_check_obj(L, 2, (void **)&arg1, "void *");

    // void *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_TransformObject(lua_State *L)
{
    oluacls_class(L, "db.TransformObject", "db.BaseObject");
    oluacls_func(L, "__move", _dragonBones_TransformObject___move);
    oluacls_func(L, "getArmature", _dragonBones_TransformObject_getArmature);
    oluacls_func(L, "updateGlobalTransform", _dragonBones_TransformObject_updateGlobalTransform);
    oluacls_prop(L, "armature", _dragonBones_TransformObject_getArmature, nullptr);
    oluacls_prop(L, "userData", _dragonBones_TransformObject_get_userData, _dragonBones_TransformObject_set_userData);

    olua_registerluatype<dragonBones::TransformObject>(L, "db.TransformObject");

    return 1;
}

static int _dragonBones_Point___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::Point *)olua_toobj(L, 1, "db.Point");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Point___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::Point *)olua_toobj(L, 1, "db.Point");
    olua_push_cppobj(L, self, "db.Point");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_Point_clear(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Point");

    // void clear()
    self->clear();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Point_getHelpPointA(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point *getHelpPointA()
    dragonBones::Point *ret = dragonBones::Point::getHelpPointA();
    int num_ret = olua_push_cppobj(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Point_getHelpPointB(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point *getHelpPointB()
    dragonBones::Point *ret = dragonBones::Point::getHelpPointB();
    int num_ret = olua_push_cppobj(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Point_getHelpPointC(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point *getHelpPointC()
    dragonBones::Point *ret = dragonBones::Point::getHelpPointC();
    int num_ret = olua_push_cppobj(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Point_getHelpPointD(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point *getHelpPointD()
    dragonBones::Point *ret = dragonBones::Point::getHelpPointD();
    int num_ret = olua_push_cppobj(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Point_new(lua_State *L)
{
    olua_startinvoke(L);

    // Point()
    dragonBones::Point *ret = new dragonBones::Point();
    int num_ret = olua_push_cppobj(L, ret, "db.Point");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Point_get_x(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Point");

    // float x
    float ret = self->x;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Point_set_x(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *self = nullptr;
    lua_Number arg1 = 0;       /** x */

    olua_to_cppobj(L, 1, (void **)&self, "db.Point");
    olua_check_number(L, 2, &arg1);

    // float x
    self->x = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Point_get_y(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Point");

    // float y
    float ret = self->y;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Point_set_y(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *self = nullptr;
    lua_Number arg1 = 0;       /** y */

    olua_to_cppobj(L, 1, (void **)&self, "db.Point");
    olua_check_number(L, 2, &arg1);

    // float y
    self->y = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_Point(lua_State *L)
{
    oluacls_class(L, "db.Point", nullptr);
    oluacls_func(L, "__gc", _dragonBones_Point___gc);
    oluacls_func(L, "__move", _dragonBones_Point___move);
    oluacls_func(L, "clear", _dragonBones_Point_clear);
    oluacls_func(L, "getHelpPointA", _dragonBones_Point_getHelpPointA);
    oluacls_func(L, "getHelpPointB", _dragonBones_Point_getHelpPointB);
    oluacls_func(L, "getHelpPointC", _dragonBones_Point_getHelpPointC);
    oluacls_func(L, "getHelpPointD", _dragonBones_Point_getHelpPointD);
    oluacls_func(L, "new", _dragonBones_Point_new);
    oluacls_prop(L, "helpPointA", _dragonBones_Point_getHelpPointA, nullptr);
    oluacls_prop(L, "helpPointB", _dragonBones_Point_getHelpPointB, nullptr);
    oluacls_prop(L, "helpPointC", _dragonBones_Point_getHelpPointC, nullptr);
    oluacls_prop(L, "helpPointD", _dragonBones_Point_getHelpPointD, nullptr);
    oluacls_prop(L, "x", _dragonBones_Point_get_x, _dragonBones_Point_set_x);
    oluacls_prop(L, "y", _dragonBones_Point_get_y, _dragonBones_Point_set_y);

    olua_registerluatype<dragonBones::Point>(L, "db.Point");

    return 1;
}

static int _dragonBones_ConstraintData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::ConstraintData *)olua_toobj(L, 1, "db.ConstraintData");
    olua_push_cppobj(L, self, "db.ConstraintData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_ConstraintData_getBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");

    // const dragonBones::BoneData *getBone()
    const dragonBones::BoneData *ret = self->getBone();
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ConstraintData_getRoot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");

    // const dragonBones::BoneData *getRoot()
    const dragonBones::BoneData *ret = self->getRoot();
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ConstraintData_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");

    // const dragonBones::BoneData *getTarget()
    const dragonBones::BoneData *ret = self->getTarget();
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ConstraintData_setBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // void setBone(const dragonBones::BoneData *value)
    self->setBone(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ConstraintData_setRoot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // void setRoot(const dragonBones::BoneData *value)
    self->setRoot(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ConstraintData_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // void setTarget(const dragonBones::BoneData *value)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ConstraintData_get_bone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");

    // const dragonBones::BoneData *bone
    const dragonBones::BoneData *ret = self->bone;
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ConstraintData_set_bone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** bone */

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // const dragonBones::BoneData *bone
    self->bone = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ConstraintData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ConstraintData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ConstraintData_get_order(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");

    // int order
    int ret = self->order;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ConstraintData_set_order(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    lua_Integer arg1 = 0;       /** order */

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");
    olua_check_int(L, 2, &arg1);

    // int order
    self->order = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ConstraintData_get_root(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");

    // const dragonBones::BoneData *root
    const dragonBones::BoneData *ret = self->root;
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ConstraintData_set_root(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** root */

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // const dragonBones::BoneData *root
    self->root = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ConstraintData_get_target(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");

    // const dragonBones::BoneData *target
    const dragonBones::BoneData *ret = self->target;
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ConstraintData_set_target(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** target */

    olua_to_cppobj(L, 1, (void **)&self, "db.ConstraintData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // const dragonBones::BoneData *target
    self->target = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_ConstraintData(lua_State *L)
{
    oluacls_class(L, "db.ConstraintData", "db.BaseObject");
    oluacls_func(L, "__move", _dragonBones_ConstraintData___move);
    oluacls_func(L, "getBone", _dragonBones_ConstraintData_getBone);
    oluacls_func(L, "getRoot", _dragonBones_ConstraintData_getRoot);
    oluacls_func(L, "getTarget", _dragonBones_ConstraintData_getTarget);
    oluacls_func(L, "setBone", _dragonBones_ConstraintData_setBone);
    oluacls_func(L, "setRoot", _dragonBones_ConstraintData_setRoot);
    oluacls_func(L, "setTarget", _dragonBones_ConstraintData_setTarget);
    oluacls_prop(L, "bone", _dragonBones_ConstraintData_getBone, _dragonBones_ConstraintData_setBone);
    oluacls_prop(L, "root", _dragonBones_ConstraintData_getRoot, _dragonBones_ConstraintData_setRoot);
    oluacls_prop(L, "target", _dragonBones_ConstraintData_getTarget, _dragonBones_ConstraintData_setTarget);
    oluacls_prop(L, "bone", _dragonBones_ConstraintData_get_bone, _dragonBones_ConstraintData_set_bone);
    oluacls_prop(L, "name", _dragonBones_ConstraintData_get_name, _dragonBones_ConstraintData_set_name);
    oluacls_prop(L, "order", _dragonBones_ConstraintData_get_order, _dragonBones_ConstraintData_set_order);
    oluacls_prop(L, "root", _dragonBones_ConstraintData_get_root, _dragonBones_ConstraintData_set_root);
    oluacls_prop(L, "target", _dragonBones_ConstraintData_get_target, _dragonBones_ConstraintData_set_target);

    olua_registerluatype<dragonBones::ConstraintData>(L, "db.ConstraintData");

    return 1;
}

static int _dragonBones_IKConstraintData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::IKConstraintData *)olua_toobj(L, 1, "db.IKConstraintData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_IKConstraintData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::IKConstraintData *)olua_toobj(L, 1, "db.IKConstraintData");
    olua_push_cppobj(L, self, "db.IKConstraintData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_IKConstraintData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::IKConstraintData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_IKConstraintData_new(lua_State *L)
{
    olua_startinvoke(L);

    // IKConstraintData()
    dragonBones::IKConstraintData *ret = new dragonBones::IKConstraintData();
    int num_ret = olua_push_cppobj(L, ret, "db.IKConstraintData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_IKConstraintData_get_bendPositive(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.IKConstraintData");

    // bool bendPositive
    bool ret = self->bendPositive;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_IKConstraintData_set_bendPositive(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;
    bool arg1 = false;       /** bendPositive */

    olua_to_cppobj(L, 1, (void **)&self, "db.IKConstraintData");
    olua_check_bool(L, 2, &arg1);

    // bool bendPositive
    self->bendPositive = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_IKConstraintData_get_scaleEnabled(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.IKConstraintData");

    // bool scaleEnabled
    bool ret = self->scaleEnabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_IKConstraintData_set_scaleEnabled(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;
    bool arg1 = false;       /** scaleEnabled */

    olua_to_cppobj(L, 1, (void **)&self, "db.IKConstraintData");
    olua_check_bool(L, 2, &arg1);

    // bool scaleEnabled
    self->scaleEnabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_IKConstraintData_get_weight(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.IKConstraintData");

    // float weight
    float ret = self->weight;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_IKConstraintData_set_weight(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;
    lua_Number arg1 = 0;       /** weight */

    olua_to_cppobj(L, 1, (void **)&self, "db.IKConstraintData");
    olua_check_number(L, 2, &arg1);

    // float weight
    self->weight = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_IKConstraintData(lua_State *L)
{
    oluacls_class(L, "db.IKConstraintData", "db.ConstraintData");
    oluacls_func(L, "__gc", _dragonBones_IKConstraintData___gc);
    oluacls_func(L, "__move", _dragonBones_IKConstraintData___move);
    oluacls_func(L, "getTypeIndex", _dragonBones_IKConstraintData_getTypeIndex);
    oluacls_func(L, "new", _dragonBones_IKConstraintData_new);
    oluacls_prop(L, "typeIndex", _dragonBones_IKConstraintData_getTypeIndex, nullptr);
    oluacls_prop(L, "bendPositive", _dragonBones_IKConstraintData_get_bendPositive, _dragonBones_IKConstraintData_set_bendPositive);
    oluacls_prop(L, "scaleEnabled", _dragonBones_IKConstraintData_get_scaleEnabled, _dragonBones_IKConstraintData_set_scaleEnabled);
    oluacls_prop(L, "weight", _dragonBones_IKConstraintData_get_weight, _dragonBones_IKConstraintData_set_weight);

    olua_registerluatype<dragonBones::IKConstraintData>(L, "db.IKConstraintData");

    return 1;
}

static int _dragonBones_TimelineData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::TimelineData *)olua_toobj(L, 1, "db.TimelineData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TimelineData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::TimelineData *)olua_toobj(L, 1, "db.TimelineData");
    olua_push_cppobj(L, self, "db.TimelineData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_TimelineData_getType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TimelineData");

    // int getType()
    int ret = self->getType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TimelineData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::TimelineData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TimelineData_new(lua_State *L)
{
    olua_startinvoke(L);

    // TimelineData()
    dragonBones::TimelineData *ret = new dragonBones::TimelineData();
    int num_ret = olua_push_cppobj(L, ret, "db.TimelineData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TimelineData_setType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.TimelineData");
    olua_check_int(L, 2, &arg1);

    // void setType(int value)
    self->setType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TimelineData_get_frameIndicesOffset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TimelineData");

    // int frameIndicesOffset
    int ret = self->frameIndicesOffset;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TimelineData_set_frameIndicesOffset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;
    lua_Integer arg1 = 0;       /** frameIndicesOffset */

    olua_to_cppobj(L, 1, (void **)&self, "db.TimelineData");
    olua_check_int(L, 2, &arg1);

    // int frameIndicesOffset
    self->frameIndicesOffset = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TimelineData_get_offset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TimelineData");

    // unsigned int offset
    unsigned int ret = self->offset;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TimelineData_set_offset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** offset */

    olua_to_cppobj(L, 1, (void **)&self, "db.TimelineData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int offset
    self->offset = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TimelineData_get_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TimelineData");

    // dragonBones::TimelineType type
    dragonBones::TimelineType ret = self->type;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TimelineData_set_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "db.TimelineData");
    olua_check_uint(L, 2, &arg1);

    // dragonBones::TimelineType type
    self->type = (dragonBones::TimelineType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_TimelineData(lua_State *L)
{
    oluacls_class(L, "db.TimelineData", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_TimelineData___gc);
    oluacls_func(L, "__move", _dragonBones_TimelineData___move);
    oluacls_func(L, "getType", _dragonBones_TimelineData_getType);
    oluacls_func(L, "getTypeIndex", _dragonBones_TimelineData_getTypeIndex);
    oluacls_func(L, "new", _dragonBones_TimelineData_new);
    oluacls_func(L, "setType", _dragonBones_TimelineData_setType);
    oluacls_prop(L, "type", _dragonBones_TimelineData_getType, _dragonBones_TimelineData_setType);
    oluacls_prop(L, "typeIndex", _dragonBones_TimelineData_getTypeIndex, nullptr);
    oluacls_prop(L, "frameIndicesOffset", _dragonBones_TimelineData_get_frameIndicesOffset, _dragonBones_TimelineData_set_frameIndicesOffset);
    oluacls_prop(L, "offset", _dragonBones_TimelineData_get_offset, _dragonBones_TimelineData_set_offset);
    oluacls_prop(L, "type", _dragonBones_TimelineData_get_type, _dragonBones_TimelineData_set_type);

    olua_registerluatype<dragonBones::TimelineData>(L, "db.TimelineData");

    return 1;
}

static int _dragonBones_IAnimatable___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::IAnimatable *)olua_toobj(L, 1, "db.IAnimatable");
    olua_push_cppobj(L, self, "db.IAnimatable");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_IAnimatable_advanceTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IAnimatable *self = nullptr;
    lua_Number arg1 = 0;       /** passedTime */

    olua_to_cppobj(L, 1, (void **)&self, "db.IAnimatable");
    olua_check_number(L, 2, &arg1);

    // void advanceTime(float passedTime)
    self->advanceTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_IAnimatable_getClock(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IAnimatable *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.IAnimatable");

    // dragonBones::WorldClock *getClock()
    dragonBones::WorldClock *ret = self->getClock();
    int num_ret = olua_push_cppobj(L, ret, "db.WorldClock");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_IAnimatable_setClock(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IAnimatable *self = nullptr;
    dragonBones::WorldClock *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.IAnimatable");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.WorldClock");

    // void setClock(dragonBones::WorldClock *value)
    self->setClock(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_IAnimatable(lua_State *L)
{
    oluacls_class(L, "db.IAnimatable", nullptr);
    oluacls_func(L, "__move", _dragonBones_IAnimatable___move);
    oluacls_func(L, "advanceTime", _dragonBones_IAnimatable_advanceTime);
    oluacls_func(L, "getClock", _dragonBones_IAnimatable_getClock);
    oluacls_func(L, "setClock", _dragonBones_IAnimatable_setClock);
    oluacls_prop(L, "clock", _dragonBones_IAnimatable_getClock, _dragonBones_IAnimatable_setClock);

    olua_registerluatype<dragonBones::IAnimatable>(L, "db.IAnimatable");

    return 1;
}

static int _dragonBones_WorldClock___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::WorldClock *)olua_toobj(L, 1, "db.WorldClock");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_WorldClock___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::WorldClock *)olua_toobj(L, 1, "db.WorldClock");
    olua_push_cppobj(L, self, "db.WorldClock");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_WorldClock_add(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;
    dragonBones::IAnimatable *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.WorldClock");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.IAnimatable");

    // void add(dragonBones::IAnimatable *value)
    self->add(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_WorldClock_clear(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.WorldClock");

    // void clear()
    self->clear();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_WorldClock_contains(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;
    dragonBones::IAnimatable *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.WorldClock");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.IAnimatable");

    // bool contains(const dragonBones::IAnimatable *value)
    bool ret = self->contains(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_WorldClock_getStaticClock(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::WorldClock *getStaticClock()
    dragonBones::WorldClock *ret = dragonBones::WorldClock::getStaticClock();
    int num_ret = olua_push_cppobj(L, ret, "db.WorldClock");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_WorldClock_new1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** timeValue */

    olua_check_number(L, 1, &arg1);

    // WorldClock(@optional float timeValue)
    dragonBones::WorldClock *ret = new dragonBones::WorldClock((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.WorldClock");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_WorldClock_new2(lua_State *L)
{
    olua_startinvoke(L);

    // WorldClock(@optional float timeValue)
    dragonBones::WorldClock *ret = new dragonBones::WorldClock();
    int num_ret = olua_push_cppobj(L, ret, "db.WorldClock");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_WorldClock_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // WorldClock(@optional float timeValue)
        return _dragonBones_WorldClock_new2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_number(L, 1))) {
            // WorldClock(@optional float timeValue)
            return _dragonBones_WorldClock_new1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::WorldClock::new' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_WorldClock_remove(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;
    dragonBones::IAnimatable *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.WorldClock");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.IAnimatable");

    // void remove(dragonBones::IAnimatable *value)
    self->remove(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_WorldClock_get_time(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.WorldClock");

    // float time
    float ret = self->time;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_WorldClock_set_time(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;
    lua_Number arg1 = 0;       /** time */

    olua_to_cppobj(L, 1, (void **)&self, "db.WorldClock");
    olua_check_number(L, 2, &arg1);

    // float time
    self->time = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_WorldClock_get_timeScale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.WorldClock");

    // float timeScale
    float ret = self->timeScale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_WorldClock_set_timeScale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;
    lua_Number arg1 = 0;       /** timeScale */

    olua_to_cppobj(L, 1, (void **)&self, "db.WorldClock");
    olua_check_number(L, 2, &arg1);

    // float timeScale
    self->timeScale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_WorldClock(lua_State *L)
{
    oluacls_class(L, "db.WorldClock", "db.IAnimatable");
    oluacls_func(L, "__gc", _dragonBones_WorldClock___gc);
    oluacls_func(L, "__move", _dragonBones_WorldClock___move);
    oluacls_func(L, "add", _dragonBones_WorldClock_add);
    oluacls_func(L, "clear", _dragonBones_WorldClock_clear);
    oluacls_func(L, "contains", _dragonBones_WorldClock_contains);
    oluacls_func(L, "getStaticClock", _dragonBones_WorldClock_getStaticClock);
    oluacls_func(L, "new", _dragonBones_WorldClock_new);
    oluacls_func(L, "remove", _dragonBones_WorldClock_remove);
    oluacls_prop(L, "staticClock", _dragonBones_WorldClock_getStaticClock, nullptr);
    oluacls_prop(L, "time", _dragonBones_WorldClock_get_time, _dragonBones_WorldClock_set_time);
    oluacls_prop(L, "timeScale", _dragonBones_WorldClock_get_timeScale, _dragonBones_WorldClock_set_timeScale);

    olua_registerluatype<dragonBones::WorldClock>(L, "db.WorldClock");

    return 1;
}

static int _dragonBones_Slot___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::Slot *)olua_toobj(L, 1, "db.Slot");
    olua_push_cppobj(L, self, "db.Slot");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_Slot_containsPoint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // bool containsPoint(float x, float y)
    bool ret = self->containsPoint((float)arg1, (float)arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_getBoundingBoxData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // dragonBones::BoundingBoxData *getBoundingBoxData()
    dragonBones::BoundingBoxData *ret = self->getBoundingBoxData();
    int num_ret = olua_push_cppobj(L, ret, "db.BoundingBoxData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_getChildArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // dragonBones::Armature *getChildArmature()
    dragonBones::Armature *ret = self->getChildArmature();
    int num_ret = olua_push_cppobj(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_getDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // void *getDisplay()
    void *ret = self->getDisplay();
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_getDisplayIndex(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // int getDisplayIndex()
    int ret = self->getDisplayIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_getMeshDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // void *getMeshDisplay()
    void *ret = self->getMeshDisplay();
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_getName(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // const std::string &getName()
    const std::string &ret = self->getName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // dragonBones::Bone *getParent()
    dragonBones::Bone *ret = self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_getRawDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // void *getRawDisplay()
    void *ret = self->getRawDisplay();
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_getSlotData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // const dragonBones::SlotData *getSlotData()
    const dragonBones::SlotData *ret = self->getSlotData();
    int num_ret = olua_push_cppobj(L, ret, "db.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_getVisible(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // bool getVisible()
    bool ret = self->getVisible();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_init(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    dragonBones::SlotData *arg1 = nullptr;       /** slotData */
    dragonBones::Armature *arg2 = nullptr;       /** armatureValue */
    void *arg3 = nullptr;       /** rawDisplay */
    void *arg4 = nullptr;       /** meshDisplay */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.SlotData");
    olua_check_cppobj(L, 3, (void **)&arg2, "db.Armature");
    olua_check_obj(L, 4, (void **)&arg3, "void *");
    olua_check_obj(L, 5, (void **)&arg4, "void *");

    // void init(const dragonBones::SlotData *slotData, dragonBones::Armature *armatureValue, void *rawDisplay, void *meshDisplay)
    self->init(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Slot_intersectsSegment1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */
    dragonBones::Point *arg7 = nullptr;       /** normalRadians */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_cppobj(L, 6, (void **)&arg5, "db.Point");
    olua_check_cppobj(L, 7, (void **)&arg6, "db.Point");
    olua_check_cppobj(L, 8, (void **)&arg7, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    int ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4, arg5, arg6, arg7);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_intersectsSegment2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    int ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_intersectsSegment3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_cppobj(L, 6, (void **)&arg5, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    int ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4, arg5);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_intersectsSegment4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_cppobj(L, 6, (void **)&arg5, "db.Point");
    olua_check_cppobj(L, 7, (void **)&arg6, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    int ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4, arg5, arg6);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_intersectsSegment(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 4) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_Slot_intersectsSegment2(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_cppobj(L, 6, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_Slot_intersectsSegment3(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_cppobj(L, 6, "db.Point")) && (olua_is_cppobj(L, 7, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_Slot_intersectsSegment4(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_cppobj(L, 6, "db.Point")) && (olua_is_cppobj(L, 7, "db.Point")) && (olua_is_cppobj(L, 8, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_Slot_intersectsSegment1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Slot::intersectsSegment' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_Slot_invalidUpdate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // void invalidUpdate()
    self->invalidUpdate();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Slot_replaceDisplayData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    dragonBones::DisplayData *arg1 = nullptr;       /** displayData */
    lua_Integer arg2 = 0;       /** displayIndex */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.DisplayData");
    olua_check_int(L, 3, &arg2);

    // void replaceDisplayData(dragonBones::DisplayData *displayData, int displayIndex)
    self->replaceDisplayData(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Slot_setChildArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Armature");

    // void setChildArmature(dragonBones::Armature *value)
    self->setChildArmature(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Slot_setDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    void *arg1 = nullptr;       /** value */
    lua_Unsigned arg2 = 0;       /** displayType */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_obj(L, 2, (void **)&arg1, "void *");
    olua_check_uint(L, 3, &arg2);

    // void setDisplay(void *value, dragonBones::DisplayType displayType)
    self->setDisplay(arg1, (dragonBones::DisplayType)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Slot_setDisplayIndex(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_int(L, 2, &arg1);

    // void setDisplayIndex(int value)
    self->setDisplayIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Slot_setVisible(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_bool(L, 2, &arg1);

    // void setVisible(bool value)
    self->setVisible(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Slot_update(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    lua_Integer arg1 = 0;       /** cacheFrameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_int(L, 2, &arg1);

    // void update(int cacheFrameIndex)
    self->update((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Slot_updateTransformAndMatrix(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // void updateTransformAndMatrix()
    self->updateTransformAndMatrix();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Slot_get_displayController(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");

    // std::string displayController
    std::string ret = self->displayController;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Slot_set_displayController(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    std::string arg1;       /** displayController */

    olua_to_cppobj(L, 1, (void **)&self, "db.Slot");
    olua_check_std_string(L, 2, &arg1);

    // std::string displayController
    self->displayController = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_Slot(lua_State *L)
{
    oluacls_class(L, "db.Slot", "db.TransformObject");
    oluacls_func(L, "__move", _dragonBones_Slot___move);
    oluacls_func(L, "containsPoint", _dragonBones_Slot_containsPoint);
    oluacls_func(L, "getBoundingBoxData", _dragonBones_Slot_getBoundingBoxData);
    oluacls_func(L, "getChildArmature", _dragonBones_Slot_getChildArmature);
    oluacls_func(L, "getDisplay", _dragonBones_Slot_getDisplay);
    oluacls_func(L, "getDisplayIndex", _dragonBones_Slot_getDisplayIndex);
    oluacls_func(L, "getMeshDisplay", _dragonBones_Slot_getMeshDisplay);
    oluacls_func(L, "getName", _dragonBones_Slot_getName);
    oluacls_func(L, "getParent", _dragonBones_Slot_getParent);
    oluacls_func(L, "getRawDisplay", _dragonBones_Slot_getRawDisplay);
    oluacls_func(L, "getSlotData", _dragonBones_Slot_getSlotData);
    oluacls_func(L, "getVisible", _dragonBones_Slot_getVisible);
    oluacls_func(L, "init", _dragonBones_Slot_init);
    oluacls_func(L, "intersectsSegment", _dragonBones_Slot_intersectsSegment);
    oluacls_func(L, "invalidUpdate", _dragonBones_Slot_invalidUpdate);
    oluacls_func(L, "replaceDisplayData", _dragonBones_Slot_replaceDisplayData);
    oluacls_func(L, "setChildArmature", _dragonBones_Slot_setChildArmature);
    oluacls_func(L, "setDisplay", _dragonBones_Slot_setDisplay);
    oluacls_func(L, "setDisplayIndex", _dragonBones_Slot_setDisplayIndex);
    oluacls_func(L, "setVisible", _dragonBones_Slot_setVisible);
    oluacls_func(L, "update", _dragonBones_Slot_update);
    oluacls_func(L, "updateTransformAndMatrix", _dragonBones_Slot_updateTransformAndMatrix);
    oluacls_prop(L, "boundingBoxData", _dragonBones_Slot_getBoundingBoxData, nullptr);
    oluacls_prop(L, "childArmature", _dragonBones_Slot_getChildArmature, _dragonBones_Slot_setChildArmature);
    oluacls_prop(L, "display", _dragonBones_Slot_getDisplay, _dragonBones_Slot_setDisplay);
    oluacls_prop(L, "displayIndex", _dragonBones_Slot_getDisplayIndex, _dragonBones_Slot_setDisplayIndex);
    oluacls_prop(L, "meshDisplay", _dragonBones_Slot_getMeshDisplay, nullptr);
    oluacls_prop(L, "name", _dragonBones_Slot_getName, nullptr);
    oluacls_prop(L, "parent", _dragonBones_Slot_getParent, nullptr);
    oluacls_prop(L, "rawDisplay", _dragonBones_Slot_getRawDisplay, nullptr);
    oluacls_prop(L, "slotData", _dragonBones_Slot_getSlotData, nullptr);
    oluacls_prop(L, "visible", _dragonBones_Slot_getVisible, _dragonBones_Slot_setVisible);
    oluacls_prop(L, "displayController", _dragonBones_Slot_get_displayController, _dragonBones_Slot_set_displayController);

    olua_registerluatype<dragonBones::Slot>(L, "db.Slot");

    return 1;
}

static int _dragonBones_Bone___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::Bone *)olua_toobj(L, 1, "db.Bone");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Bone___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::Bone *)olua_toobj(L, 1, "db.Bone");
    olua_push_cppobj(L, self, "db.Bone");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_Bone_contains(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    dragonBones::Bone *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Bone");

    // bool contains(const dragonBones::Bone *value)
    bool ret = self->contains(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Bone_getBoneData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");

    // const dragonBones::BoneData *getBoneData()
    const dragonBones::BoneData *ret = self->getBoneData();
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Bone_getName(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");

    // const std::string &getName()
    const std::string &ret = self->getName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Bone_getOffsetMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");

    // int getOffsetMode()
    int ret = self->getOffsetMode();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Bone_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");

    // dragonBones::Bone *getParent()
    dragonBones::Bone *ret = self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Bone_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::Bone::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Bone_getVisible(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");

    // bool getVisible()
    bool ret = self->getVisible();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Bone_init(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** boneData */
    dragonBones::Armature *arg2 = nullptr;       /** armatureValue */

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");
    olua_check_cppobj(L, 3, (void **)&arg2, "db.Armature");

    // void init(const dragonBones::BoneData *boneData, dragonBones::Armature *armatureValue)
    self->init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Bone_invalidUpdate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");

    // void invalidUpdate()
    self->invalidUpdate();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Bone_new(lua_State *L)
{
    olua_startinvoke(L);

    // Bone()
    dragonBones::Bone *ret = new dragonBones::Bone();
    int num_ret = olua_push_cppobj(L, ret, "db.Bone");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Bone_setOffsetMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");
    olua_check_int(L, 2, &arg1);

    // void setOffsetMode(int value)
    self->setOffsetMode((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Bone_setVisible(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");
    olua_check_bool(L, 2, &arg1);

    // void setVisible(bool value)
    self->setVisible(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Bone_update(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    lua_Integer arg1 = 0;       /** cacheFrameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");
    olua_check_int(L, 2, &arg1);

    // void update(int cacheFrameIndex)
    self->update((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Bone_updateByConstraint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");

    // void updateByConstraint()
    self->updateByConstraint();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Bone_get_offsetMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");

    // dragonBones::OffsetMode offsetMode
    dragonBones::OffsetMode ret = self->offsetMode;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Bone_set_offsetMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    lua_Unsigned arg1 = 0;       /** offsetMode */

    olua_to_cppobj(L, 1, (void **)&self, "db.Bone");
    olua_check_uint(L, 2, &arg1);

    // dragonBones::OffsetMode offsetMode
    self->offsetMode = (dragonBones::OffsetMode)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_Bone(lua_State *L)
{
    oluacls_class(L, "db.Bone", "db.TransformObject");
    oluacls_func(L, "__gc", _dragonBones_Bone___gc);
    oluacls_func(L, "__move", _dragonBones_Bone___move);
    oluacls_func(L, "contains", _dragonBones_Bone_contains);
    oluacls_func(L, "getBoneData", _dragonBones_Bone_getBoneData);
    oluacls_func(L, "getName", _dragonBones_Bone_getName);
    oluacls_func(L, "getOffsetMode", _dragonBones_Bone_getOffsetMode);
    oluacls_func(L, "getParent", _dragonBones_Bone_getParent);
    oluacls_func(L, "getTypeIndex", _dragonBones_Bone_getTypeIndex);
    oluacls_func(L, "getVisible", _dragonBones_Bone_getVisible);
    oluacls_func(L, "init", _dragonBones_Bone_init);
    oluacls_func(L, "invalidUpdate", _dragonBones_Bone_invalidUpdate);
    oluacls_func(L, "new", _dragonBones_Bone_new);
    oluacls_func(L, "setOffsetMode", _dragonBones_Bone_setOffsetMode);
    oluacls_func(L, "setVisible", _dragonBones_Bone_setVisible);
    oluacls_func(L, "update", _dragonBones_Bone_update);
    oluacls_func(L, "updateByConstraint", _dragonBones_Bone_updateByConstraint);
    oluacls_prop(L, "boneData", _dragonBones_Bone_getBoneData, nullptr);
    oluacls_prop(L, "name", _dragonBones_Bone_getName, nullptr);
    oluacls_prop(L, "offsetMode", _dragonBones_Bone_getOffsetMode, _dragonBones_Bone_setOffsetMode);
    oluacls_prop(L, "parent", _dragonBones_Bone_getParent, nullptr);
    oluacls_prop(L, "typeIndex", _dragonBones_Bone_getTypeIndex, nullptr);
    oluacls_prop(L, "visible", _dragonBones_Bone_getVisible, _dragonBones_Bone_setVisible);
    oluacls_prop(L, "offsetMode", _dragonBones_Bone_get_offsetMode, _dragonBones_Bone_set_offsetMode);

    olua_registerluatype<dragonBones::Bone>(L, "db.Bone");

    return 1;
}

static int _dragonBones_DisplayData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::DisplayData *)olua_toobj(L, 1, "db.DisplayData");
    olua_push_cppobj(L, self, "db.DisplayData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_DisplayData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");

    // dragonBones::SkinData *getParent()
    dragonBones::SkinData *ret = self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "db.SkinData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DisplayData_getType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");

    // int getType()
    int ret = self->getType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DisplayData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    dragonBones::SkinData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.SkinData");

    // void setParent(dragonBones::SkinData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DisplayData_setType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");
    olua_check_int(L, 2, &arg1);

    // void setType(int value)
    self->setType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DisplayData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DisplayData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DisplayData_get_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");

    // dragonBones::SkinData *parent
    dragonBones::SkinData *ret = self->parent;
    int num_ret = olua_push_cppobj(L, ret, "db.SkinData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DisplayData_set_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    dragonBones::SkinData *arg1 = nullptr;       /** parent */

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.SkinData");

    // dragonBones::SkinData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DisplayData_get_path(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");

    // std::string path
    std::string ret = self->path;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DisplayData_set_path(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    std::string arg1;       /** path */

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");
    olua_check_std_string(L, 2, &arg1);

    // std::string path
    self->path = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DisplayData_get_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");

    // dragonBones::DisplayType type
    dragonBones::DisplayType ret = self->type;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DisplayData_set_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "db.DisplayData");
    olua_check_uint(L, 2, &arg1);

    // dragonBones::DisplayType type
    self->type = (dragonBones::DisplayType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_DisplayData(lua_State *L)
{
    oluacls_class(L, "db.DisplayData", "db.BaseObject");
    oluacls_func(L, "__move", _dragonBones_DisplayData___move);
    oluacls_func(L, "getParent", _dragonBones_DisplayData_getParent);
    oluacls_func(L, "getType", _dragonBones_DisplayData_getType);
    oluacls_func(L, "setParent", _dragonBones_DisplayData_setParent);
    oluacls_func(L, "setType", _dragonBones_DisplayData_setType);
    oluacls_prop(L, "parent", _dragonBones_DisplayData_getParent, _dragonBones_DisplayData_setParent);
    oluacls_prop(L, "type", _dragonBones_DisplayData_getType, _dragonBones_DisplayData_setType);
    oluacls_prop(L, "name", _dragonBones_DisplayData_get_name, _dragonBones_DisplayData_set_name);
    oluacls_prop(L, "parent", _dragonBones_DisplayData_get_parent, _dragonBones_DisplayData_set_parent);
    oluacls_prop(L, "path", _dragonBones_DisplayData_get_path, _dragonBones_DisplayData_set_path);
    oluacls_prop(L, "type", _dragonBones_DisplayData_get_type, _dragonBones_DisplayData_set_type);

    olua_registerluatype<dragonBones::DisplayData>(L, "db.DisplayData");

    return 1;
}

static int _dragonBones_ActionData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::ActionData *)olua_toobj(L, 1, "db.ActionData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ActionData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::ActionData *)olua_toobj(L, 1, "db.ActionData");
    olua_push_cppobj(L, self, "db.ActionData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_ActionData_getBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");

    // const dragonBones::BoneData *getBone()
    const dragonBones::BoneData *ret = self->getBone();
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ActionData_getData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");

    // const dragonBones::UserData *getData()
    const dragonBones::UserData *ret = self->getData();
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ActionData_getSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");

    // const dragonBones::SlotData *getSlot()
    const dragonBones::SlotData *ret = self->getSlot();
    int num_ret = olua_push_cppobj(L, ret, "db.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ActionData_getType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");

    // int getType()
    int ret = self->getType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ActionData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::ActionData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ActionData_new(lua_State *L)
{
    olua_startinvoke(L);

    // ActionData()
    dragonBones::ActionData *ret = new dragonBones::ActionData();
    int num_ret = olua_push_cppobj(L, ret, "db.ActionData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ActionData_setBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // void setBone(const dragonBones::BoneData *value)
    self->setBone(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ActionData_setData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.UserData");

    // void setData(dragonBones::UserData *value)
    self->setData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ActionData_setSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::SlotData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.SlotData");

    // void setSlot(const dragonBones::SlotData *value)
    self->setSlot(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ActionData_setType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");
    olua_check_int(L, 2, &arg1);

    // void setType(int value)
    self->setType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ActionData_get_bone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");

    // const dragonBones::BoneData *bone
    const dragonBones::BoneData *ret = self->bone;
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ActionData_set_bone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** bone */

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // const dragonBones::BoneData *bone
    self->bone = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ActionData_get_data(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");

    // dragonBones::UserData *data
    dragonBones::UserData *ret = self->data;
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ActionData_set_data(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.UserData");

    // dragonBones::UserData *data
    self->data = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ActionData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ActionData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ActionData_get_slot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");

    // const dragonBones::SlotData *slot
    const dragonBones::SlotData *ret = self->slot;
    int num_ret = olua_push_cppobj(L, ret, "db.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ActionData_set_slot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::SlotData *arg1 = nullptr;       /** slot */

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.SlotData");

    // const dragonBones::SlotData *slot
    self->slot = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ActionData_get_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");

    // dragonBones::ActionType type
    dragonBones::ActionType ret = self->type;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ActionData_set_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "db.ActionData");
    olua_check_uint(L, 2, &arg1);

    // dragonBones::ActionType type
    self->type = (dragonBones::ActionType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_ActionData(lua_State *L)
{
    oluacls_class(L, "db.ActionData", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_ActionData___gc);
    oluacls_func(L, "__move", _dragonBones_ActionData___move);
    oluacls_func(L, "getBone", _dragonBones_ActionData_getBone);
    oluacls_func(L, "getData", _dragonBones_ActionData_getData);
    oluacls_func(L, "getSlot", _dragonBones_ActionData_getSlot);
    oluacls_func(L, "getType", _dragonBones_ActionData_getType);
    oluacls_func(L, "getTypeIndex", _dragonBones_ActionData_getTypeIndex);
    oluacls_func(L, "new", _dragonBones_ActionData_new);
    oluacls_func(L, "setBone", _dragonBones_ActionData_setBone);
    oluacls_func(L, "setData", _dragonBones_ActionData_setData);
    oluacls_func(L, "setSlot", _dragonBones_ActionData_setSlot);
    oluacls_func(L, "setType", _dragonBones_ActionData_setType);
    oluacls_prop(L, "bone", _dragonBones_ActionData_getBone, _dragonBones_ActionData_setBone);
    oluacls_prop(L, "data", _dragonBones_ActionData_getData, _dragonBones_ActionData_setData);
    oluacls_prop(L, "slot", _dragonBones_ActionData_getSlot, _dragonBones_ActionData_setSlot);
    oluacls_prop(L, "type", _dragonBones_ActionData_getType, _dragonBones_ActionData_setType);
    oluacls_prop(L, "typeIndex", _dragonBones_ActionData_getTypeIndex, nullptr);
    oluacls_prop(L, "bone", _dragonBones_ActionData_get_bone, _dragonBones_ActionData_set_bone);
    oluacls_prop(L, "data", _dragonBones_ActionData_get_data, _dragonBones_ActionData_set_data);
    oluacls_prop(L, "name", _dragonBones_ActionData_get_name, _dragonBones_ActionData_set_name);
    oluacls_prop(L, "slot", _dragonBones_ActionData_get_slot, _dragonBones_ActionData_set_slot);
    oluacls_prop(L, "type", _dragonBones_ActionData_get_type, _dragonBones_ActionData_set_type);

    olua_registerluatype<dragonBones::ActionData>(L, "db.ActionData");

    return 1;
}

static int _dragonBones_UserData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::UserData *)olua_toobj(L, 1, "db.UserData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_UserData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::UserData *)olua_toobj(L, 1, "db.UserData");
    olua_push_cppobj(L, self, "db.UserData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_UserData_addFloat(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");
    olua_check_number(L, 2, &arg1);

    // void addFloat(float value)
    self->addFloat((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_UserData_addInt(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");
    olua_check_int(L, 2, &arg1);

    // void addInt(int value)
    self->addInt((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_UserData_addString(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    std::string arg1;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");
    olua_check_std_string(L, 2, &arg1);

    // void addString(std::string value)
    self->addString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_UserData_getFloat(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");
    olua_check_uint(L, 2, &arg1);

    // float getFloat(unsigned int index)
    float ret = self->getFloat((unsigned int)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_UserData_getFloats(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");

    // const std::vector<float> &getFloats()
    const std::vector<float> &ret = self->getFloats();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_UserData_getInt(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");
    olua_check_uint(L, 2, &arg1);

    // int getInt(unsigned int index)
    int ret = self->getInt((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_UserData_getInts(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");

    // const std::vector<int> &getInts()
    const std::vector<int> &ret = self->getInts();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_int(L, (lua_Integer)ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_UserData_getString(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");
    olua_check_uint(L, 2, &arg1);

    // std::string getString(unsigned int index)
    std::string ret = self->getString((unsigned int)arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_UserData_getStrings(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");

    // const std::vector<std::string> &getStrings()
    const std::vector<std::string> &ret = self->getStrings();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_std_string(L, ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_UserData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::UserData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_UserData_new(lua_State *L)
{
    olua_startinvoke(L);

    // UserData()
    dragonBones::UserData *ret = new dragonBones::UserData();
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_UserData_get_floats(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");

    // std::vector<float> floats
    std::vector<float> ret = self->floats;
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_UserData_set_floats(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    std::vector<float> arg1;       /** floats */

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");
    luaL_checktype(L, 2, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 2);
    arg1.reserve((size_t)arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        lua_Number obj;
        lua_rawgeti(L, 2, i);
        olua_check_number(L, -1, &obj);
        arg1.push_back((float)obj);
        lua_pop(L, 1);
    }

    // std::vector<float> floats
    self->floats = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_UserData_get_ints(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");

    // std::vector<int> ints
    std::vector<int> ret = self->ints;
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_int(L, (lua_Integer)ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_UserData_set_ints(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    std::vector<int> arg1;       /** ints */

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");
    luaL_checktype(L, 2, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 2);
    arg1.reserve((size_t)arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        lua_Integer obj;
        lua_rawgeti(L, 2, i);
        olua_check_int(L, -1, &obj);
        arg1.push_back((int)obj);
        lua_pop(L, 1);
    }

    // std::vector<int> ints
    self->ints = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_UserData_get_strings(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");

    // std::vector<std::string> strings
    std::vector<std::string> ret = self->strings;
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_std_string(L, ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_UserData_set_strings(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    std::vector<std::string> arg1;       /** strings */

    olua_to_cppobj(L, 1, (void **)&self, "db.UserData");
    luaL_checktype(L, 2, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 2);
    arg1.reserve((size_t)arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        std::string obj;
        lua_rawgeti(L, 2, i);
        olua_check_std_string(L, -1, &obj);
        arg1.push_back((std::string)obj);
        lua_pop(L, 1);
    }

    // std::vector<std::string> strings
    self->strings = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_UserData(lua_State *L)
{
    oluacls_class(L, "db.UserData", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_UserData___gc);
    oluacls_func(L, "__move", _dragonBones_UserData___move);
    oluacls_func(L, "addFloat", _dragonBones_UserData_addFloat);
    oluacls_func(L, "addInt", _dragonBones_UserData_addInt);
    oluacls_func(L, "addString", _dragonBones_UserData_addString);
    oluacls_func(L, "getFloat", _dragonBones_UserData_getFloat);
    oluacls_func(L, "getFloats", _dragonBones_UserData_getFloats);
    oluacls_func(L, "getInt", _dragonBones_UserData_getInt);
    oluacls_func(L, "getInts", _dragonBones_UserData_getInts);
    oluacls_func(L, "getString", _dragonBones_UserData_getString);
    oluacls_func(L, "getStrings", _dragonBones_UserData_getStrings);
    oluacls_func(L, "getTypeIndex", _dragonBones_UserData_getTypeIndex);
    oluacls_func(L, "new", _dragonBones_UserData_new);
    oluacls_prop(L, "floats", _dragonBones_UserData_getFloats, nullptr);
    oluacls_prop(L, "ints", _dragonBones_UserData_getInts, nullptr);
    oluacls_prop(L, "strings", _dragonBones_UserData_getStrings, nullptr);
    oluacls_prop(L, "typeIndex", _dragonBones_UserData_getTypeIndex, nullptr);
    oluacls_prop(L, "floats", _dragonBones_UserData_get_floats, _dragonBones_UserData_set_floats);
    oluacls_prop(L, "ints", _dragonBones_UserData_get_ints, _dragonBones_UserData_set_ints);
    oluacls_prop(L, "strings", _dragonBones_UserData_get_strings, _dragonBones_UserData_set_strings);

    olua_registerluatype<dragonBones::UserData>(L, "db.UserData");

    return 1;
}

static int _dragonBones_BoundingBoxData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::BoundingBoxData *)olua_toobj(L, 1, "db.BoundingBoxData");
    olua_push_cppobj(L, self, "db.BoundingBoxData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_BoundingBoxData_containsPoint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    lua_Number arg1 = 0;       /** pX */
    lua_Number arg2 = 0;       /** pY */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // bool containsPoint(float pX, float pY)
    bool ret = self->containsPoint((float)arg1, (float)arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxData_getType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");

    // int getType()
    int ret = self->getType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxData_intersectsSegment1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */
    dragonBones::Point *arg7 = nullptr;       /** normalRadians */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_cppobj(L, 6, (void **)&arg5, "db.Point");
    olua_check_cppobj(L, 7, (void **)&arg6, "db.Point");
    olua_check_cppobj(L, 8, (void **)&arg7, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    int ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4, arg5, arg6, arg7);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxData_intersectsSegment2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    int ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxData_intersectsSegment3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_cppobj(L, 6, (void **)&arg5, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    int ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4, arg5);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxData_intersectsSegment4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_cppobj(L, 6, (void **)&arg5, "db.Point");
    olua_check_cppobj(L, 7, (void **)&arg6, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    int ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4, arg5, arg6);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxData_intersectsSegment(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 4) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_BoundingBoxData_intersectsSegment2(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_cppobj(L, 6, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_BoundingBoxData_intersectsSegment3(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_cppobj(L, 6, "db.Point")) && (olua_is_cppobj(L, 7, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_BoundingBoxData_intersectsSegment4(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_cppobj(L, 6, "db.Point")) && (olua_is_cppobj(L, 7, "db.Point")) && (olua_is_cppobj(L, 8, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_BoundingBoxData_intersectsSegment1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoundingBoxData::intersectsSegment' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BoundingBoxData_setType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");
    olua_check_int(L, 2, &arg1);

    // void setType(int value)
    self->setType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoundingBoxData_get_color(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");

    // unsigned int color
    unsigned int ret = self->color;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxData_set_color(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int color
    self->color = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoundingBoxData_get_height(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");

    // float height
    float ret = self->height;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxData_set_height(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    lua_Number arg1 = 0;       /** height */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);

    // float height
    self->height = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoundingBoxData_get_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");

    // dragonBones::BoundingBoxType type
    dragonBones::BoundingBoxType ret = self->type;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxData_set_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");
    olua_check_uint(L, 2, &arg1);

    // dragonBones::BoundingBoxType type
    self->type = (dragonBones::BoundingBoxType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoundingBoxData_get_width(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");

    // float width
    float ret = self->width;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxData_set_width(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    lua_Number arg1 = 0;       /** width */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);

    // float width
    self->width = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_BoundingBoxData(lua_State *L)
{
    oluacls_class(L, "db.BoundingBoxData", "db.BaseObject");
    oluacls_func(L, "__move", _dragonBones_BoundingBoxData___move);
    oluacls_func(L, "containsPoint", _dragonBones_BoundingBoxData_containsPoint);
    oluacls_func(L, "getType", _dragonBones_BoundingBoxData_getType);
    oluacls_func(L, "intersectsSegment", _dragonBones_BoundingBoxData_intersectsSegment);
    oluacls_func(L, "setType", _dragonBones_BoundingBoxData_setType);
    oluacls_prop(L, "type", _dragonBones_BoundingBoxData_getType, _dragonBones_BoundingBoxData_setType);
    oluacls_prop(L, "color", _dragonBones_BoundingBoxData_get_color, _dragonBones_BoundingBoxData_set_color);
    oluacls_prop(L, "height", _dragonBones_BoundingBoxData_get_height, _dragonBones_BoundingBoxData_set_height);
    oluacls_prop(L, "type", _dragonBones_BoundingBoxData_get_type, _dragonBones_BoundingBoxData_set_type);
    oluacls_prop(L, "width", _dragonBones_BoundingBoxData_get_width, _dragonBones_BoundingBoxData_set_width);

    olua_registerluatype<dragonBones::BoundingBoxData>(L, "db.BoundingBoxData");

    return 1;
}

static int _dragonBones_BoundingBoxDisplayData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::BoundingBoxDisplayData *)olua_toobj(L, 1, "db.BoundingBoxDisplayData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoundingBoxDisplayData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::BoundingBoxDisplayData *)olua_toobj(L, 1, "db.BoundingBoxDisplayData");
    olua_push_cppobj(L, self, "db.BoundingBoxDisplayData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_BoundingBoxDisplayData_getBoundingBox(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxDisplayData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxDisplayData");

    // const dragonBones::BoundingBoxData *getBoundingBox()
    const dragonBones::BoundingBoxData *ret = self->getBoundingBox();
    int num_ret = olua_push_cppobj(L, ret, "db.BoundingBoxData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxDisplayData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::BoundingBoxDisplayData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxDisplayData_new(lua_State *L)
{
    olua_startinvoke(L);

    // BoundingBoxDisplayData()
    dragonBones::BoundingBoxDisplayData *ret = new dragonBones::BoundingBoxDisplayData();
    int num_ret = olua_push_cppobj(L, ret, "db.BoundingBoxDisplayData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxDisplayData_setBoundingBox(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxDisplayData *self = nullptr;
    dragonBones::BoundingBoxData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxDisplayData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoundingBoxData");

    // void setBoundingBox(dragonBones::BoundingBoxData *value)
    self->setBoundingBox(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoundingBoxDisplayData_get_boundingBox(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxDisplayData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxDisplayData");

    // dragonBones::BoundingBoxData *boundingBox
    dragonBones::BoundingBoxData *ret = self->boundingBox;
    int num_ret = olua_push_cppobj(L, ret, "db.BoundingBoxData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoundingBoxDisplayData_set_boundingBox(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxDisplayData *self = nullptr;
    dragonBones::BoundingBoxData *arg1 = nullptr;       /** boundingBox */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoundingBoxDisplayData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoundingBoxData");

    // dragonBones::BoundingBoxData *boundingBox
    self->boundingBox = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_BoundingBoxDisplayData(lua_State *L)
{
    oluacls_class(L, "db.BoundingBoxDisplayData", "db.DisplayData");
    oluacls_func(L, "__gc", _dragonBones_BoundingBoxDisplayData___gc);
    oluacls_func(L, "__move", _dragonBones_BoundingBoxDisplayData___move);
    oluacls_func(L, "getBoundingBox", _dragonBones_BoundingBoxDisplayData_getBoundingBox);
    oluacls_func(L, "getTypeIndex", _dragonBones_BoundingBoxDisplayData_getTypeIndex);
    oluacls_func(L, "new", _dragonBones_BoundingBoxDisplayData_new);
    oluacls_func(L, "setBoundingBox", _dragonBones_BoundingBoxDisplayData_setBoundingBox);
    oluacls_prop(L, "boundingBox", _dragonBones_BoundingBoxDisplayData_getBoundingBox, _dragonBones_BoundingBoxDisplayData_setBoundingBox);
    oluacls_prop(L, "typeIndex", _dragonBones_BoundingBoxDisplayData_getTypeIndex, nullptr);
    oluacls_prop(L, "boundingBox", _dragonBones_BoundingBoxDisplayData_get_boundingBox, _dragonBones_BoundingBoxDisplayData_set_boundingBox);

    olua_registerluatype<dragonBones::BoundingBoxDisplayData>(L, "db.BoundingBoxDisplayData");

    return 1;
}

static int _dragonBones_CanvasData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::CanvasData *)olua_toobj(L, 1, "db.CanvasData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CanvasData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::CanvasData *)olua_toobj(L, 1, "db.CanvasData");
    olua_push_cppobj(L, self, "db.CanvasData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_CanvasData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::CanvasData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CanvasData_new(lua_State *L)
{
    olua_startinvoke(L);

    // CanvasData()
    dragonBones::CanvasData *ret = new dragonBones::CanvasData();
    int num_ret = olua_push_cppobj(L, ret, "db.CanvasData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CanvasData_get_aabb(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.CanvasData");

    // dragonBones::Rectangle aabb
    dragonBones::Rectangle ret = self->aabb;
    int num_ret = auto_olua_push_dragonBones_Rectangle(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CanvasData_set_aabb(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;
    dragonBones::Rectangle arg1;       /** aabb */

    olua_to_cppobj(L, 1, (void **)&self, "db.CanvasData");
    auto_olua_check_dragonBones_Rectangle(L, 2, &arg1);

    // dragonBones::Rectangle aabb
    self->aabb = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CanvasData_get_color(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.CanvasData");

    // unsigned int color
    unsigned int ret = self->color;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CanvasData_set_color(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** color */

    olua_to_cppobj(L, 1, (void **)&self, "db.CanvasData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int color
    self->color = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CanvasData_get_hasBackground(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.CanvasData");

    // bool hasBackground
    bool ret = self->hasBackground;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CanvasData_set_hasBackground(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;
    bool arg1 = false;       /** hasBackground */

    olua_to_cppobj(L, 1, (void **)&self, "db.CanvasData");
    olua_check_bool(L, 2, &arg1);

    // bool hasBackground
    self->hasBackground = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_CanvasData(lua_State *L)
{
    oluacls_class(L, "db.CanvasData", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_CanvasData___gc);
    oluacls_func(L, "__move", _dragonBones_CanvasData___move);
    oluacls_func(L, "getTypeIndex", _dragonBones_CanvasData_getTypeIndex);
    oluacls_func(L, "new", _dragonBones_CanvasData_new);
    oluacls_prop(L, "typeIndex", _dragonBones_CanvasData_getTypeIndex, nullptr);
    oluacls_prop(L, "aabb", _dragonBones_CanvasData_get_aabb, _dragonBones_CanvasData_set_aabb);
    oluacls_prop(L, "color", _dragonBones_CanvasData_get_color, _dragonBones_CanvasData_set_color);
    oluacls_prop(L, "hasBackground", _dragonBones_CanvasData_get_hasBackground, _dragonBones_CanvasData_set_hasBackground);

    olua_registerluatype<dragonBones::CanvasData>(L, "db.CanvasData");

    return 1;
}

static int _dragonBones_TextureAtlasData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::TextureAtlasData *)olua_toobj(L, 1, "db.TextureAtlasData");
    olua_push_cppobj(L, self, "db.TextureAtlasData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_TextureAtlasData_addTexture(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    dragonBones::TextureData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.TextureData");

    // void addTexture(dragonBones::TextureData *value)
    self->addTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TextureAtlasData_createTexture(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");

    // dragonBones::TextureData *createTexture()
    dragonBones::TextureData *ret = self->createTexture();
    int num_ret = olua_push_cppobj(L, ret, "db.TextureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureAtlasData_getTexture(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    std::string arg1;       /** textureName */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::TextureData *getTexture(const std::string &textureName)
    dragonBones::TextureData *ret = self->getTexture(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.TextureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureAtlasData_get_autoSearch(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");

    // bool autoSearch
    bool ret = self->autoSearch;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureAtlasData_set_autoSearch(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    bool arg1 = false;       /** autoSearch */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");
    olua_check_bool(L, 2, &arg1);

    // bool autoSearch
    self->autoSearch = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TextureAtlasData_get_format(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");

    // dragonBones::TextureFormat format
    dragonBones::TextureFormat ret = self->format;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureAtlasData_set_format(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** format */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");
    olua_check_uint(L, 2, &arg1);

    // dragonBones::TextureFormat format
    self->format = (dragonBones::TextureFormat)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TextureAtlasData_get_height(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");

    // unsigned int height
    unsigned int ret = self->height;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureAtlasData_set_height(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** height */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int height
    self->height = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TextureAtlasData_get_imagePath(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");

    // std::string imagePath
    std::string ret = self->imagePath;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureAtlasData_set_imagePath(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    std::string arg1;       /** imagePath */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");
    olua_check_std_string(L, 2, &arg1);

    // std::string imagePath
    self->imagePath = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TextureAtlasData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureAtlasData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TextureAtlasData_get_scale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");

    // float scale
    float ret = self->scale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureAtlasData_set_scale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");
    olua_check_number(L, 2, &arg1);

    // float scale
    self->scale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TextureAtlasData_get_width(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");

    // unsigned int width
    unsigned int ret = self->width;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureAtlasData_set_width(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** width */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureAtlasData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int width
    self->width = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_TextureAtlasData(lua_State *L)
{
    oluacls_class(L, "db.TextureAtlasData", "db.BaseObject");
    oluacls_func(L, "__move", _dragonBones_TextureAtlasData___move);
    oluacls_func(L, "addTexture", _dragonBones_TextureAtlasData_addTexture);
    oluacls_func(L, "createTexture", _dragonBones_TextureAtlasData_createTexture);
    oluacls_func(L, "getTexture", _dragonBones_TextureAtlasData_getTexture);
    oluacls_prop(L, "autoSearch", _dragonBones_TextureAtlasData_get_autoSearch, _dragonBones_TextureAtlasData_set_autoSearch);
    oluacls_prop(L, "format", _dragonBones_TextureAtlasData_get_format, _dragonBones_TextureAtlasData_set_format);
    oluacls_prop(L, "height", _dragonBones_TextureAtlasData_get_height, _dragonBones_TextureAtlasData_set_height);
    oluacls_prop(L, "imagePath", _dragonBones_TextureAtlasData_get_imagePath, _dragonBones_TextureAtlasData_set_imagePath);
    oluacls_prop(L, "name", _dragonBones_TextureAtlasData_get_name, _dragonBones_TextureAtlasData_set_name);
    oluacls_prop(L, "scale", _dragonBones_TextureAtlasData_get_scale, _dragonBones_TextureAtlasData_set_scale);
    oluacls_prop(L, "width", _dragonBones_TextureAtlasData_get_width, _dragonBones_TextureAtlasData_set_width);

    olua_registerluatype<dragonBones::TextureAtlasData>(L, "db.TextureAtlasData");

    return 1;
}

static int _dragonBones_TextureData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::TextureData *)olua_toobj(L, 1, "db.TextureData");
    olua_push_cppobj(L, self, "db.TextureData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_TextureData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureData");

    // const dragonBones::TextureAtlasData *getParent()
    const dragonBones::TextureAtlasData *ret = self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    dragonBones::TextureAtlasData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.TextureAtlasData");

    // void setParent(dragonBones::TextureAtlasData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TextureData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TextureData_get_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureData");

    // dragonBones::TextureAtlasData *parent
    dragonBones::TextureAtlasData *ret = self->parent;
    int num_ret = olua_push_cppobj(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureData_set_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    dragonBones::TextureAtlasData *arg1 = nullptr;       /** parent */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.TextureAtlasData");

    // dragonBones::TextureAtlasData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TextureData_get_region(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureData");

    // dragonBones::Rectangle region
    dragonBones::Rectangle ret = self->region;
    int num_ret = auto_olua_push_dragonBones_Rectangle(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureData_set_region(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    dragonBones::Rectangle arg1;       /** region */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureData");
    auto_olua_check_dragonBones_Rectangle(L, 2, &arg1);

    // dragonBones::Rectangle region
    self->region = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_TextureData_get_rotated(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureData");

    // bool rotated
    bool ret = self->rotated;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_TextureData_set_rotated(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    bool arg1 = false;       /** rotated */

    olua_to_cppobj(L, 1, (void **)&self, "db.TextureData");
    olua_check_bool(L, 2, &arg1);

    // bool rotated
    self->rotated = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_TextureData(lua_State *L)
{
    oluacls_class(L, "db.TextureData", "db.BaseObject");
    oluacls_func(L, "__move", _dragonBones_TextureData___move);
    oluacls_func(L, "getParent", _dragonBones_TextureData_getParent);
    oluacls_func(L, "setParent", _dragonBones_TextureData_setParent);
    oluacls_prop(L, "parent", _dragonBones_TextureData_getParent, _dragonBones_TextureData_setParent);
    oluacls_prop(L, "name", _dragonBones_TextureData_get_name, _dragonBones_TextureData_set_name);
    oluacls_prop(L, "parent", _dragonBones_TextureData_get_parent, _dragonBones_TextureData_set_parent);
    oluacls_prop(L, "region", _dragonBones_TextureData_get_region, _dragonBones_TextureData_set_region);
    oluacls_prop(L, "rotated", _dragonBones_TextureData_get_rotated, _dragonBones_TextureData_set_rotated);

    olua_registerluatype<dragonBones::TextureData>(L, "db.TextureData");

    return 1;
}

static int _dragonBones_ArmatureData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::ArmatureData *)olua_toobj(L, 1, "db.ArmatureData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::ArmatureData *)olua_toobj(L, 1, "db.ArmatureData");
    olua_push_cppobj(L, self, "db.ArmatureData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_ArmatureData_addAction(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::ActionData *arg1 = nullptr;       /** value */
    bool arg2 = false;       /** isDefault */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.ActionData");
    olua_check_bool(L, 3, &arg2);

    // void addAction(dragonBones::ActionData *value, bool isDefault)
    self->addAction(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_addAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::AnimationData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.AnimationData");

    // void addAnimation(dragonBones::AnimationData *value)
    self->addAnimation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_addBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // void addBone(dragonBones::BoneData *value)
    self->addBone(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_addConstraint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::ConstraintData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.ConstraintData");

    // void addConstraint(dragonBones::ConstraintData *value)
    self->addConstraint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_addSkin(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::SkinData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.SkinData");

    // void addSkin(dragonBones::SkinData *value)
    self->addSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_addSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::SlotData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.SlotData");

    // void addSlot(dragonBones::SlotData *value)
    self->addSlot(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_cacheFrames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameRate */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_uint(L, 2, &arg1);

    // void cacheFrames(unsigned int frameRate)
    self->cacheFrames((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_getActions(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // const std::vector<ActionData *> &getActions()
    const std::vector<dragonBones::ActionData *> &ret = self->getActions();
    int num_ret = olua_push_std_vector(L, ret, "db.ActionData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::AnimationData *getAnimation(const std::string &animationName)
    dragonBones::AnimationData *ret = self->getAnimation(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getAnimationNames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // const std::vector<std::string> &getAnimationNames()
    const std::vector<std::string> &ret = self->getAnimationNames();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_std_string(L, ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::BoneData *getBone(const std::string &boneName)
    dragonBones::BoneData *ret = self->getBone(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getConstraint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** constraintName */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::ConstraintData *getConstraint(const std::string &constraintName)
    dragonBones::ConstraintData *ret = self->getConstraint(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.ConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getDefaultActions(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // const std::vector<ActionData *> &getDefaultActions()
    const std::vector<dragonBones::ActionData *> &ret = self->getDefaultActions();
    int num_ret = olua_push_std_vector(L, ret, "db.ActionData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getDefaultAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // dragonBones::AnimationData *getDefaultAnimation()
    dragonBones::AnimationData *ret = self->getDefaultAnimation();
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getDefaultSkin(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // dragonBones::SkinData *getDefaultSkin()
    dragonBones::SkinData *ret = self->getDefaultSkin();
    int num_ret = olua_push_cppobj(L, ret, "db.SkinData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // const dragonBones::DragonBonesData *getParent()
    const dragonBones::DragonBonesData *ret = self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getSkin(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** skinName */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::SkinData *getSkin(const std::string &skinName)
    dragonBones::SkinData *ret = self->getSkin(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.SkinData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** slotName */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::SlotData *getSlot(const std::string &slotName)
    dragonBones::SlotData *ret = self->getSlot(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getSortedBones(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // const std::vector<BoneData *> &getSortedBones()
    const std::vector<dragonBones::BoneData *> &ret = self->getSortedBones();
    int num_ret = olua_push_std_vector(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getSortedSlots(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // const std::vector<SlotData *> &getSortedSlots()
    const std::vector<dragonBones::SlotData *> &ret = self->getSortedSlots();
    int num_ret = olua_push_std_vector(L, ret, "db.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // int getType()
    int ret = self->getType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::ArmatureData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // const dragonBones::UserData *getUserData()
    const dragonBones::UserData *ret = self->getUserData();
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_new(lua_State *L)
{
    olua_startinvoke(L);

    // ArmatureData()
    dragonBones::ArmatureData *ret = new dragonBones::ArmatureData();
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_setDefaultAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::AnimationData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.AnimationData");

    // void setDefaultAnimation(dragonBones::AnimationData *value)
    self->setDefaultAnimation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_setDefaultSkin(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::SkinData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.SkinData");

    // void setDefaultSkin(dragonBones::SkinData *value)
    self->setDefaultSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::DragonBonesData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.DragonBonesData");

    // void setParent(dragonBones::DragonBonesData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_setType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_int(L, 2, &arg1);

    // void setType(int value)
    self->setType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_setUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.UserData");

    // void setUserData(dragonBones::UserData *value)
    self->setUserData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_sortBones(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // void sortBones()
    self->sortBones();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_aabb(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // dragonBones::Rectangle aabb
    dragonBones::Rectangle ret = self->aabb;
    int num_ret = auto_olua_push_dragonBones_Rectangle(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_aabb(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::Rectangle arg1;       /** aabb */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    auto_olua_check_dragonBones_Rectangle(L, 2, &arg1);

    // dragonBones::Rectangle aabb
    self->aabb = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_actions(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // std::vector<ActionData *> actions
    std::vector<dragonBones::ActionData *> ret = self->actions;
    int num_ret = olua_push_std_vector(L, ret, "db.ActionData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_actions(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::vector<dragonBones::ActionData *> arg1;       /** actions */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_std_vector(L, 2, arg1, "db.ActionData");

    // std::vector<ActionData *> actions
    self->actions = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_animationNames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // std::vector<std::string> animationNames
    std::vector<std::string> ret = self->animationNames;
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_std_string(L, ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_animationNames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::vector<std::string> arg1;       /** animationNames */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    luaL_checktype(L, 2, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 2);
    arg1.reserve((size_t)arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        std::string obj;
        lua_rawgeti(L, 2, i);
        olua_check_std_string(L, -1, &obj);
        arg1.push_back((std::string)obj);
        lua_pop(L, 1);
    }

    // std::vector<std::string> animationNames
    self->animationNames = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_cacheFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // unsigned int cacheFrameRate
    unsigned int ret = self->cacheFrameRate;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_cacheFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** cacheFrameRate */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int cacheFrameRate
    self->cacheFrameRate = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_defaultActions(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // std::vector<ActionData *> defaultActions
    std::vector<dragonBones::ActionData *> ret = self->defaultActions;
    int num_ret = olua_push_std_vector(L, ret, "db.ActionData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_defaultActions(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::vector<dragonBones::ActionData *> arg1;       /** defaultActions */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_std_vector(L, 2, arg1, "db.ActionData");

    // std::vector<ActionData *> defaultActions
    self->defaultActions = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_defaultAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // dragonBones::AnimationData *defaultAnimation
    dragonBones::AnimationData *ret = self->defaultAnimation;
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_defaultAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::AnimationData *arg1 = nullptr;       /** defaultAnimation */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.AnimationData");

    // dragonBones::AnimationData *defaultAnimation
    self->defaultAnimation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_defaultSkin(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // dragonBones::SkinData *defaultSkin
    dragonBones::SkinData *ret = self->defaultSkin;
    int num_ret = olua_push_cppobj(L, ret, "db.SkinData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_defaultSkin(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::SkinData *arg1 = nullptr;       /** defaultSkin */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.SkinData");

    // dragonBones::SkinData *defaultSkin
    self->defaultSkin = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_frameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // unsigned int frameRate
    unsigned int ret = self->frameRate;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_frameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameRate */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int frameRate
    self->frameRate = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // dragonBones::DragonBonesData *parent
    dragonBones::DragonBonesData *ret = self->parent;
    int num_ret = olua_push_cppobj(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::DragonBonesData *arg1 = nullptr;       /** parent */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.DragonBonesData");

    // dragonBones::DragonBonesData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_scale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // float scale
    float ret = self->scale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_scale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_number(L, 2, &arg1);

    // float scale
    self->scale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_sortedBones(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // std::vector<BoneData *> sortedBones
    std::vector<dragonBones::BoneData *> ret = self->sortedBones;
    int num_ret = olua_push_std_vector(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_sortedBones(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::vector<dragonBones::BoneData *> arg1;       /** sortedBones */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_std_vector(L, 2, arg1, "db.BoneData");

    // std::vector<BoneData *> sortedBones
    self->sortedBones = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_sortedSlots(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // std::vector<SlotData *> sortedSlots
    std::vector<dragonBones::SlotData *> ret = self->sortedSlots;
    int num_ret = olua_push_std_vector(L, ret, "db.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_sortedSlots(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::vector<dragonBones::SlotData *> arg1;       /** sortedSlots */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_std_vector(L, 2, arg1, "db.SlotData");

    // std::vector<SlotData *> sortedSlots
    self->sortedSlots = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // dragonBones::ArmatureType type
    dragonBones::ArmatureType ret = self->type;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_type(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_uint(L, 2, &arg1);

    // dragonBones::ArmatureType type
    self->type = (dragonBones::ArmatureType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_ArmatureData_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");

    // dragonBones::UserData *userData
    dragonBones::UserData *ret = self->userData;
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_ArmatureData_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** userData */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.UserData");

    // dragonBones::UserData *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_ArmatureData(lua_State *L)
{
    oluacls_class(L, "db.ArmatureData", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_ArmatureData___gc);
    oluacls_func(L, "__move", _dragonBones_ArmatureData___move);
    oluacls_func(L, "addAction", _dragonBones_ArmatureData_addAction);
    oluacls_func(L, "addAnimation", _dragonBones_ArmatureData_addAnimation);
    oluacls_func(L, "addBone", _dragonBones_ArmatureData_addBone);
    oluacls_func(L, "addConstraint", _dragonBones_ArmatureData_addConstraint);
    oluacls_func(L, "addSkin", _dragonBones_ArmatureData_addSkin);
    oluacls_func(L, "addSlot", _dragonBones_ArmatureData_addSlot);
    oluacls_func(L, "cacheFrames", _dragonBones_ArmatureData_cacheFrames);
    oluacls_func(L, "getActions", _dragonBones_ArmatureData_getActions);
    oluacls_func(L, "getAnimation", _dragonBones_ArmatureData_getAnimation);
    oluacls_func(L, "getAnimationNames", _dragonBones_ArmatureData_getAnimationNames);
    oluacls_func(L, "getBone", _dragonBones_ArmatureData_getBone);
    oluacls_func(L, "getConstraint", _dragonBones_ArmatureData_getConstraint);
    oluacls_func(L, "getDefaultActions", _dragonBones_ArmatureData_getDefaultActions);
    oluacls_func(L, "getDefaultAnimation", _dragonBones_ArmatureData_getDefaultAnimation);
    oluacls_func(L, "getDefaultSkin", _dragonBones_ArmatureData_getDefaultSkin);
    oluacls_func(L, "getParent", _dragonBones_ArmatureData_getParent);
    oluacls_func(L, "getSkin", _dragonBones_ArmatureData_getSkin);
    oluacls_func(L, "getSlot", _dragonBones_ArmatureData_getSlot);
    oluacls_func(L, "getSortedBones", _dragonBones_ArmatureData_getSortedBones);
    oluacls_func(L, "getSortedSlots", _dragonBones_ArmatureData_getSortedSlots);
    oluacls_func(L, "getType", _dragonBones_ArmatureData_getType);
    oluacls_func(L, "getTypeIndex", _dragonBones_ArmatureData_getTypeIndex);
    oluacls_func(L, "getUserData", _dragonBones_ArmatureData_getUserData);
    oluacls_func(L, "new", _dragonBones_ArmatureData_new);
    oluacls_func(L, "setDefaultAnimation", _dragonBones_ArmatureData_setDefaultAnimation);
    oluacls_func(L, "setDefaultSkin", _dragonBones_ArmatureData_setDefaultSkin);
    oluacls_func(L, "setParent", _dragonBones_ArmatureData_setParent);
    oluacls_func(L, "setType", _dragonBones_ArmatureData_setType);
    oluacls_func(L, "setUserData", _dragonBones_ArmatureData_setUserData);
    oluacls_func(L, "sortBones", _dragonBones_ArmatureData_sortBones);
    oluacls_prop(L, "actions", _dragonBones_ArmatureData_getActions, nullptr);
    oluacls_prop(L, "animationNames", _dragonBones_ArmatureData_getAnimationNames, nullptr);
    oluacls_prop(L, "defaultActions", _dragonBones_ArmatureData_getDefaultActions, nullptr);
    oluacls_prop(L, "defaultAnimation", _dragonBones_ArmatureData_getDefaultAnimation, _dragonBones_ArmatureData_setDefaultAnimation);
    oluacls_prop(L, "defaultSkin", _dragonBones_ArmatureData_getDefaultSkin, _dragonBones_ArmatureData_setDefaultSkin);
    oluacls_prop(L, "parent", _dragonBones_ArmatureData_getParent, _dragonBones_ArmatureData_setParent);
    oluacls_prop(L, "sortedBones", _dragonBones_ArmatureData_getSortedBones, nullptr);
    oluacls_prop(L, "sortedSlots", _dragonBones_ArmatureData_getSortedSlots, nullptr);
    oluacls_prop(L, "type", _dragonBones_ArmatureData_getType, _dragonBones_ArmatureData_setType);
    oluacls_prop(L, "typeIndex", _dragonBones_ArmatureData_getTypeIndex, nullptr);
    oluacls_prop(L, "userData", _dragonBones_ArmatureData_getUserData, _dragonBones_ArmatureData_setUserData);
    oluacls_prop(L, "aabb", _dragonBones_ArmatureData_get_aabb, _dragonBones_ArmatureData_set_aabb);
    oluacls_prop(L, "actions", _dragonBones_ArmatureData_get_actions, _dragonBones_ArmatureData_set_actions);
    oluacls_prop(L, "animationNames", _dragonBones_ArmatureData_get_animationNames, _dragonBones_ArmatureData_set_animationNames);
    oluacls_prop(L, "cacheFrameRate", _dragonBones_ArmatureData_get_cacheFrameRate, _dragonBones_ArmatureData_set_cacheFrameRate);
    oluacls_prop(L, "defaultActions", _dragonBones_ArmatureData_get_defaultActions, _dragonBones_ArmatureData_set_defaultActions);
    oluacls_prop(L, "defaultAnimation", _dragonBones_ArmatureData_get_defaultAnimation, _dragonBones_ArmatureData_set_defaultAnimation);
    oluacls_prop(L, "defaultSkin", _dragonBones_ArmatureData_get_defaultSkin, _dragonBones_ArmatureData_set_defaultSkin);
    oluacls_prop(L, "frameRate", _dragonBones_ArmatureData_get_frameRate, _dragonBones_ArmatureData_set_frameRate);
    oluacls_prop(L, "name", _dragonBones_ArmatureData_get_name, _dragonBones_ArmatureData_set_name);
    oluacls_prop(L, "parent", _dragonBones_ArmatureData_get_parent, _dragonBones_ArmatureData_set_parent);
    oluacls_prop(L, "scale", _dragonBones_ArmatureData_get_scale, _dragonBones_ArmatureData_set_scale);
    oluacls_prop(L, "sortedBones", _dragonBones_ArmatureData_get_sortedBones, _dragonBones_ArmatureData_set_sortedBones);
    oluacls_prop(L, "sortedSlots", _dragonBones_ArmatureData_get_sortedSlots, _dragonBones_ArmatureData_set_sortedSlots);
    oluacls_prop(L, "type", _dragonBones_ArmatureData_get_type, _dragonBones_ArmatureData_set_type);
    oluacls_prop(L, "userData", _dragonBones_ArmatureData_get_userData, _dragonBones_ArmatureData_set_userData);

    olua_registerluatype<dragonBones::ArmatureData>(L, "db.ArmatureData");

    return 1;
}

static int _dragonBones_SkinData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::SkinData *)olua_toobj(L, 1, "db.SkinData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SkinData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::SkinData *)olua_toobj(L, 1, "db.SkinData");
    olua_push_cppobj(L, self, "db.SkinData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_SkinData_addDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;
    std::string arg1;       /** slotName */
    dragonBones::DisplayData *arg2 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.SkinData");
    olua_check_std_string(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "db.DisplayData");

    // void addDisplay(const std::string &slotName, dragonBones::DisplayData *value)
    self->addDisplay(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SkinData_getDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;
    std::string arg1;       /** slotName */
    std::string arg2;       /** displayName */

    olua_to_cppobj(L, 1, (void **)&self, "db.SkinData");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // dragonBones::DisplayData *getDisplay(const std::string &slotName, const std::string &displayName)
    dragonBones::DisplayData *ret = self->getDisplay(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.DisplayData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SkinData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::SkinData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SkinData_new(lua_State *L)
{
    olua_startinvoke(L);

    // SkinData()
    dragonBones::SkinData *ret = new dragonBones::SkinData();
    int num_ret = olua_push_cppobj(L, ret, "db.SkinData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SkinData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.SkinData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SkinData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.SkinData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SkinData_get_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.SkinData");

    // dragonBones::ArmatureData *parent
    dragonBones::ArmatureData *ret = self->parent;
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SkinData_set_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;
    dragonBones::ArmatureData *arg1 = nullptr;       /** parent */

    olua_to_cppobj(L, 1, (void **)&self, "db.SkinData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.ArmatureData");

    // dragonBones::ArmatureData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_SkinData(lua_State *L)
{
    oluacls_class(L, "db.SkinData", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_SkinData___gc);
    oluacls_func(L, "__move", _dragonBones_SkinData___move);
    oluacls_func(L, "addDisplay", _dragonBones_SkinData_addDisplay);
    oluacls_func(L, "getDisplay", _dragonBones_SkinData_getDisplay);
    oluacls_func(L, "getTypeIndex", _dragonBones_SkinData_getTypeIndex);
    oluacls_func(L, "new", _dragonBones_SkinData_new);
    oluacls_prop(L, "typeIndex", _dragonBones_SkinData_getTypeIndex, nullptr);
    oluacls_prop(L, "name", _dragonBones_SkinData_get_name, _dragonBones_SkinData_set_name);
    oluacls_prop(L, "parent", _dragonBones_SkinData_get_parent, _dragonBones_SkinData_set_parent);

    olua_registerluatype<dragonBones::SkinData>(L, "db.SkinData");

    return 1;
}

static int _dragonBones_BoneData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::BoneData *)olua_toobj(L, 1, "db.BoneData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoneData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::BoneData *)olua_toobj(L, 1, "db.BoneData");
    olua_push_cppobj(L, self, "db.BoneData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_BoneData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");

    // const dragonBones::BoneData *getParent()
    const dragonBones::BoneData *ret = self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::BoneData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");

    // const dragonBones::UserData *getUserData()
    const dragonBones::UserData *ret = self->getUserData();
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_new(lua_State *L)
{
    olua_startinvoke(L);

    // BoneData()
    dragonBones::BoneData *ret = new dragonBones::BoneData();
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // void setParent(dragonBones::BoneData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoneData_setUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.UserData");

    // void setUserData(dragonBones::UserData *value)
    self->setUserData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoneData_get_inheritReflection(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");

    // bool inheritReflection
    bool ret = self->inheritReflection;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_set_inheritReflection(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    bool arg1 = false;       /** inheritReflection */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");
    olua_check_bool(L, 2, &arg1);

    // bool inheritReflection
    self->inheritReflection = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoneData_get_inheritRotation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");

    // bool inheritRotation
    bool ret = self->inheritRotation;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_set_inheritRotation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    bool arg1 = false;       /** inheritRotation */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");
    olua_check_bool(L, 2, &arg1);

    // bool inheritRotation
    self->inheritRotation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoneData_get_inheritScale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");

    // bool inheritScale
    bool ret = self->inheritScale;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_set_inheritScale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    bool arg1 = false;       /** inheritScale */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");
    olua_check_bool(L, 2, &arg1);

    // bool inheritScale
    self->inheritScale = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoneData_get_inheritTranslation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");

    // bool inheritTranslation
    bool ret = self->inheritTranslation;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_set_inheritTranslation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    bool arg1 = false;       /** inheritTranslation */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");
    olua_check_bool(L, 2, &arg1);

    // bool inheritTranslation
    self->inheritTranslation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoneData_get_length(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");

    // float length
    float ret = self->length;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_set_length(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    lua_Number arg1 = 0;       /** length */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");
    olua_check_number(L, 2, &arg1);

    // float length
    self->length = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoneData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoneData_get_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");

    // dragonBones::BoneData *parent
    dragonBones::BoneData *ret = self->parent;
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_set_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** parent */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // dragonBones::BoneData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BoneData_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");

    // dragonBones::UserData *userData
    dragonBones::UserData *ret = self->userData;
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BoneData_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** userData */

    olua_to_cppobj(L, 1, (void **)&self, "db.BoneData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.UserData");

    // dragonBones::UserData *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_BoneData(lua_State *L)
{
    oluacls_class(L, "db.BoneData", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_BoneData___gc);
    oluacls_func(L, "__move", _dragonBones_BoneData___move);
    oluacls_func(L, "getParent", _dragonBones_BoneData_getParent);
    oluacls_func(L, "getTypeIndex", _dragonBones_BoneData_getTypeIndex);
    oluacls_func(L, "getUserData", _dragonBones_BoneData_getUserData);
    oluacls_func(L, "new", _dragonBones_BoneData_new);
    oluacls_func(L, "setParent", _dragonBones_BoneData_setParent);
    oluacls_func(L, "setUserData", _dragonBones_BoneData_setUserData);
    oluacls_prop(L, "parent", _dragonBones_BoneData_getParent, _dragonBones_BoneData_setParent);
    oluacls_prop(L, "typeIndex", _dragonBones_BoneData_getTypeIndex, nullptr);
    oluacls_prop(L, "userData", _dragonBones_BoneData_getUserData, _dragonBones_BoneData_setUserData);
    oluacls_prop(L, "inheritReflection", _dragonBones_BoneData_get_inheritReflection, _dragonBones_BoneData_set_inheritReflection);
    oluacls_prop(L, "inheritRotation", _dragonBones_BoneData_get_inheritRotation, _dragonBones_BoneData_set_inheritRotation);
    oluacls_prop(L, "inheritScale", _dragonBones_BoneData_get_inheritScale, _dragonBones_BoneData_set_inheritScale);
    oluacls_prop(L, "inheritTranslation", _dragonBones_BoneData_get_inheritTranslation, _dragonBones_BoneData_set_inheritTranslation);
    oluacls_prop(L, "length", _dragonBones_BoneData_get_length, _dragonBones_BoneData_set_length);
    oluacls_prop(L, "name", _dragonBones_BoneData_get_name, _dragonBones_BoneData_set_name);
    oluacls_prop(L, "parent", _dragonBones_BoneData_get_parent, _dragonBones_BoneData_set_parent);
    oluacls_prop(L, "userData", _dragonBones_BoneData_get_userData, _dragonBones_BoneData_set_userData);

    olua_registerluatype<dragonBones::BoneData>(L, "db.BoneData");

    return 1;
}

static int _dragonBones_SlotData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::SlotData *)olua_toobj(L, 1, "db.SlotData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SlotData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::SlotData *)olua_toobj(L, 1, "db.SlotData");
    olua_push_cppobj(L, self, "db.SlotData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_SlotData_getBlendMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");

    // int getBlendMode()
    int ret = self->getBlendMode();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SlotData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");

    // const dragonBones::BoneData *getParent()
    const dragonBones::BoneData *ret = self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SlotData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::SlotData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SlotData_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");

    // const dragonBones::UserData *getUserData()
    const dragonBones::UserData *ret = self->getUserData();
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SlotData_new(lua_State *L)
{
    olua_startinvoke(L);

    // SlotData()
    dragonBones::SlotData *ret = new dragonBones::SlotData();
    int num_ret = olua_push_cppobj(L, ret, "db.SlotData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SlotData_setBlendMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");
    olua_check_int(L, 2, &arg1);

    // void setBlendMode(int value)
    self->setBlendMode((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SlotData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // void setParent(dragonBones::BoneData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SlotData_setUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.UserData");

    // void setUserData(dragonBones::UserData *value)
    self->setUserData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SlotData_get_blendMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");

    // dragonBones::BlendMode blendMode
    dragonBones::BlendMode ret = self->blendMode;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SlotData_set_blendMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** blendMode */

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");
    olua_check_uint(L, 2, &arg1);

    // dragonBones::BlendMode blendMode
    self->blendMode = (dragonBones::BlendMode)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SlotData_get_displayIndex(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");

    // int displayIndex
    int ret = self->displayIndex;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SlotData_set_displayIndex(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    lua_Integer arg1 = 0;       /** displayIndex */

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");
    olua_check_int(L, 2, &arg1);

    // int displayIndex
    self->displayIndex = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SlotData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SlotData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SlotData_get_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");

    // dragonBones::BoneData *parent
    dragonBones::BoneData *ret = self->parent;
    int num_ret = olua_push_cppobj(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SlotData_set_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** parent */

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");

    // dragonBones::BoneData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SlotData_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");

    // dragonBones::UserData *userData
    dragonBones::UserData *ret = self->userData;
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SlotData_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** userData */

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.UserData");

    // dragonBones::UserData *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_SlotData_get_zOrder(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");

    // int zOrder
    int ret = self->zOrder;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_SlotData_set_zOrder(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    lua_Integer arg1 = 0;       /** zOrder */

    olua_to_cppobj(L, 1, (void **)&self, "db.SlotData");
    olua_check_int(L, 2, &arg1);

    // int zOrder
    self->zOrder = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_SlotData(lua_State *L)
{
    oluacls_class(L, "db.SlotData", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_SlotData___gc);
    oluacls_func(L, "__move", _dragonBones_SlotData___move);
    oluacls_func(L, "getBlendMode", _dragonBones_SlotData_getBlendMode);
    oluacls_func(L, "getParent", _dragonBones_SlotData_getParent);
    oluacls_func(L, "getTypeIndex", _dragonBones_SlotData_getTypeIndex);
    oluacls_func(L, "getUserData", _dragonBones_SlotData_getUserData);
    oluacls_func(L, "new", _dragonBones_SlotData_new);
    oluacls_func(L, "setBlendMode", _dragonBones_SlotData_setBlendMode);
    oluacls_func(L, "setParent", _dragonBones_SlotData_setParent);
    oluacls_func(L, "setUserData", _dragonBones_SlotData_setUserData);
    oluacls_prop(L, "blendMode", _dragonBones_SlotData_getBlendMode, _dragonBones_SlotData_setBlendMode);
    oluacls_prop(L, "parent", _dragonBones_SlotData_getParent, _dragonBones_SlotData_setParent);
    oluacls_prop(L, "typeIndex", _dragonBones_SlotData_getTypeIndex, nullptr);
    oluacls_prop(L, "userData", _dragonBones_SlotData_getUserData, _dragonBones_SlotData_setUserData);
    oluacls_prop(L, "blendMode", _dragonBones_SlotData_get_blendMode, _dragonBones_SlotData_set_blendMode);
    oluacls_prop(L, "displayIndex", _dragonBones_SlotData_get_displayIndex, _dragonBones_SlotData_set_displayIndex);
    oluacls_prop(L, "name", _dragonBones_SlotData_get_name, _dragonBones_SlotData_set_name);
    oluacls_prop(L, "parent", _dragonBones_SlotData_get_parent, _dragonBones_SlotData_set_parent);
    oluacls_prop(L, "userData", _dragonBones_SlotData_get_userData, _dragonBones_SlotData_set_userData);
    oluacls_prop(L, "zOrder", _dragonBones_SlotData_get_zOrder, _dragonBones_SlotData_set_zOrder);

    olua_registerluatype<dragonBones::SlotData>(L, "db.SlotData");

    return 1;
}

static int _dragonBones_AnimationState___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::AnimationState *)olua_toobj(L, 1, "db.AnimationState");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::AnimationState *)olua_toobj(L, 1, "db.AnimationState");
    olua_push_cppobj(L, self, "db.AnimationState");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_AnimationState_addBoneMask1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** boneName */
    bool arg2 = false;       /** recursive */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void addBoneMask(const std::string &boneName, @optional bool recursive)
    self->addBoneMask(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_addBoneMask2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_std_string(L, 2, &arg1);

    // void addBoneMask(const std::string &boneName, @optional bool recursive)
    self->addBoneMask(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_addBoneMask(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void addBoneMask(const std::string &boneName, @optional bool recursive)
            return _dragonBones_AnimationState_addBoneMask2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void addBoneMask(const std::string &boneName, @optional bool recursive)
            return _dragonBones_AnimationState_addBoneMask1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::addBoneMask' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_AnimationState_advanceTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    lua_Number arg1 = 0;       /** passedTime */
    lua_Number arg2 = 0;       /** cacheFrameRate */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void advanceTime(float passedTime, float cacheFrameRate)
    self->advanceTime((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_containsBoneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_std_string(L, 2, &arg1);

    // bool containsBoneMask(const std::string &boneName)
    bool ret = self->containsBoneMask(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_fadeOut1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    lua_Number arg1 = 0;       /** fadeOutTime */
    bool arg2 = false;       /** pausePlayhead */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void fadeOut(float fadeOutTime, @optional bool pausePlayhead)
    self->fadeOut((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_fadeOut2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    lua_Number arg1 = 0;       /** fadeOutTime */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // void fadeOut(float fadeOutTime, @optional bool pausePlayhead)
    self->fadeOut((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_fadeOut(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_number(L, 2))) {
            // void fadeOut(float fadeOutTime, @optional bool pausePlayhead)
            return _dragonBones_AnimationState_fadeOut2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_bool(L, 3))) {
            // void fadeOut(float fadeOutTime, @optional bool pausePlayhead)
            return _dragonBones_AnimationState_fadeOut1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::fadeOut' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_AnimationState_getAnimationData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // const dragonBones::AnimationData *getAnimationData()
    const dragonBones::AnimationData *ret = self->getAnimationData();
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_getCurrentPlayTimes(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // unsigned int getCurrentPlayTimes()
    unsigned int ret = self->getCurrentPlayTimes();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_getCurrentTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // float getCurrentTime()
    float ret = self->getCurrentTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_getName(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // const std::string &getName()
    const std::string &ret = self->getName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_getTotalTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // float getTotalTime()
    float ret = self->getTotalTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::AnimationState::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_init(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    dragonBones::AnimationData *arg2 = nullptr;       /** animationData */
    dragonBones::AnimationConfig *arg3 = nullptr;       /** animationConfig */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Armature");
    olua_check_cppobj(L, 3, (void **)&arg2, "db.AnimationData");
    olua_check_cppobj(L, 4, (void **)&arg3, "db.AnimationConfig");

    // void init(dragonBones::Armature *armature, dragonBones::AnimationData *animationData, dragonBones::AnimationConfig *animationConfig)
    self->init(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_isCompleted(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // bool isCompleted()
    bool ret = self->isCompleted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_isFadeComplete(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // bool isFadeComplete()
    bool ret = self->isFadeComplete();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_isFadeIn(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // bool isFadeIn()
    bool ret = self->isFadeIn();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_isFadeOut(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // bool isFadeOut()
    bool ret = self->isFadeOut();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // bool isPlaying()
    bool ret = self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_new(lua_State *L)
{
    olua_startinvoke(L);

    // AnimationState()
    dragonBones::AnimationState *ret = new dragonBones::AnimationState();
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_play(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // void play()
    self->play();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_removeAllBoneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // void removeAllBoneMask()
    self->removeAllBoneMask();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_removeBoneMask1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** boneName */
    bool arg2 = false;       /** recursive */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void removeBoneMask(const std::string &boneName, @optional bool recursive)
    self->removeBoneMask(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_removeBoneMask2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_std_string(L, 2, &arg1);

    // void removeBoneMask(const std::string &boneName, @optional bool recursive)
    self->removeBoneMask(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_removeBoneMask(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void removeBoneMask(const std::string &boneName, @optional bool recursive)
            return _dragonBones_AnimationState_removeBoneMask2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void removeBoneMask(const std::string &boneName, @optional bool recursive)
            return _dragonBones_AnimationState_removeBoneMask1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::removeBoneMask' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_AnimationState_setCurrentTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // void setCurrentTime(float value)
    self->setCurrentTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_stop(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_actionEnabled(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // bool actionEnabled
    bool ret = self->actionEnabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_actionEnabled(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    bool arg1 = false;       /** actionEnabled */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_bool(L, 2, &arg1);

    // bool actionEnabled
    self->actionEnabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_additiveBlending(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // bool additiveBlending
    bool ret = self->additiveBlending;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_additiveBlending(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    bool arg1 = false;       /** additiveBlending */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_bool(L, 2, &arg1);

    // bool additiveBlending
    self->additiveBlending = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_autoFadeOutTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // float autoFadeOutTime
    float ret = self->autoFadeOutTime;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_autoFadeOutTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    lua_Number arg1 = 0;       /** autoFadeOutTime */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // float autoFadeOutTime
    self->autoFadeOutTime = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_displayControl(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // bool displayControl
    bool ret = self->displayControl;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_displayControl(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    bool arg1 = false;       /** displayControl */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_bool(L, 2, &arg1);

    // bool displayControl
    self->displayControl = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_fadeTotalTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // float fadeTotalTime
    float ret = self->fadeTotalTime;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_fadeTotalTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    lua_Number arg1 = 0;       /** fadeTotalTime */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // float fadeTotalTime
    self->fadeTotalTime = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_group(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // std::string group
    std::string ret = self->group;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_group(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** group */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_std_string(L, 2, &arg1);

    // std::string group
    self->group = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_layer(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // unsigned int layer
    unsigned int ret = self->layer;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_layer(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** layer */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_uint(L, 2, &arg1);

    // unsigned int layer
    self->layer = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_playTimes(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // unsigned int playTimes
    unsigned int ret = self->playTimes;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_playTimes(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** playTimes */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_uint(L, 2, &arg1);

    // unsigned int playTimes
    self->playTimes = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_resetToPose(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // bool resetToPose
    bool ret = self->resetToPose;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_resetToPose(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    bool arg1 = false;       /** resetToPose */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_bool(L, 2, &arg1);

    // bool resetToPose
    self->resetToPose = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_timeScale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // float timeScale
    float ret = self->timeScale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_timeScale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    lua_Number arg1 = 0;       /** timeScale */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // float timeScale
    self->timeScale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationState_get_weight(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");

    // float weight
    float ret = self->weight;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationState_set_weight(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    lua_Number arg1 = 0;       /** weight */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // float weight
    self->weight = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_AnimationState(lua_State *L)
{
    oluacls_class(L, "db.AnimationState", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_AnimationState___gc);
    oluacls_func(L, "__move", _dragonBones_AnimationState___move);
    oluacls_func(L, "addBoneMask", _dragonBones_AnimationState_addBoneMask);
    oluacls_func(L, "advanceTime", _dragonBones_AnimationState_advanceTime);
    oluacls_func(L, "containsBoneMask", _dragonBones_AnimationState_containsBoneMask);
    oluacls_func(L, "fadeOut", _dragonBones_AnimationState_fadeOut);
    oluacls_func(L, "getAnimationData", _dragonBones_AnimationState_getAnimationData);
    oluacls_func(L, "getCurrentPlayTimes", _dragonBones_AnimationState_getCurrentPlayTimes);
    oluacls_func(L, "getCurrentTime", _dragonBones_AnimationState_getCurrentTime);
    oluacls_func(L, "getName", _dragonBones_AnimationState_getName);
    oluacls_func(L, "getTotalTime", _dragonBones_AnimationState_getTotalTime);
    oluacls_func(L, "getTypeIndex", _dragonBones_AnimationState_getTypeIndex);
    oluacls_func(L, "init", _dragonBones_AnimationState_init);
    oluacls_func(L, "isCompleted", _dragonBones_AnimationState_isCompleted);
    oluacls_func(L, "isFadeComplete", _dragonBones_AnimationState_isFadeComplete);
    oluacls_func(L, "isFadeIn", _dragonBones_AnimationState_isFadeIn);
    oluacls_func(L, "isFadeOut", _dragonBones_AnimationState_isFadeOut);
    oluacls_func(L, "isPlaying", _dragonBones_AnimationState_isPlaying);
    oluacls_func(L, "new", _dragonBones_AnimationState_new);
    oluacls_func(L, "play", _dragonBones_AnimationState_play);
    oluacls_func(L, "removeAllBoneMask", _dragonBones_AnimationState_removeAllBoneMask);
    oluacls_func(L, "removeBoneMask", _dragonBones_AnimationState_removeBoneMask);
    oluacls_func(L, "setCurrentTime", _dragonBones_AnimationState_setCurrentTime);
    oluacls_func(L, "stop", _dragonBones_AnimationState_stop);
    oluacls_prop(L, "animationData", _dragonBones_AnimationState_getAnimationData, nullptr);
    oluacls_prop(L, "completed", _dragonBones_AnimationState_isCompleted, nullptr);
    oluacls_prop(L, "currentPlayTimes", _dragonBones_AnimationState_getCurrentPlayTimes, nullptr);
    oluacls_prop(L, "currentTime", _dragonBones_AnimationState_getCurrentTime, _dragonBones_AnimationState_setCurrentTime);
    oluacls_prop(L, "fadeComplete", _dragonBones_AnimationState_isFadeComplete, nullptr);
    oluacls_prop(L, "fadeIn", _dragonBones_AnimationState_isFadeIn, nullptr);
    oluacls_prop(L, "fadeOut", _dragonBones_AnimationState_isFadeOut, nullptr);
    oluacls_prop(L, "name", _dragonBones_AnimationState_getName, nullptr);
    oluacls_prop(L, "playing", _dragonBones_AnimationState_isPlaying, nullptr);
    oluacls_prop(L, "totalTime", _dragonBones_AnimationState_getTotalTime, nullptr);
    oluacls_prop(L, "typeIndex", _dragonBones_AnimationState_getTypeIndex, nullptr);
    oluacls_prop(L, "actionEnabled", _dragonBones_AnimationState_get_actionEnabled, _dragonBones_AnimationState_set_actionEnabled);
    oluacls_prop(L, "additiveBlending", _dragonBones_AnimationState_get_additiveBlending, _dragonBones_AnimationState_set_additiveBlending);
    oluacls_prop(L, "autoFadeOutTime", _dragonBones_AnimationState_get_autoFadeOutTime, _dragonBones_AnimationState_set_autoFadeOutTime);
    oluacls_prop(L, "displayControl", _dragonBones_AnimationState_get_displayControl, _dragonBones_AnimationState_set_displayControl);
    oluacls_prop(L, "fadeTotalTime", _dragonBones_AnimationState_get_fadeTotalTime, _dragonBones_AnimationState_set_fadeTotalTime);
    oluacls_prop(L, "group", _dragonBones_AnimationState_get_group, _dragonBones_AnimationState_set_group);
    oluacls_prop(L, "layer", _dragonBones_AnimationState_get_layer, _dragonBones_AnimationState_set_layer);
    oluacls_prop(L, "name", _dragonBones_AnimationState_get_name, _dragonBones_AnimationState_set_name);
    oluacls_prop(L, "playTimes", _dragonBones_AnimationState_get_playTimes, _dragonBones_AnimationState_set_playTimes);
    oluacls_prop(L, "resetToPose", _dragonBones_AnimationState_get_resetToPose, _dragonBones_AnimationState_set_resetToPose);
    oluacls_prop(L, "timeScale", _dragonBones_AnimationState_get_timeScale, _dragonBones_AnimationState_set_timeScale);
    oluacls_prop(L, "weight", _dragonBones_AnimationState_get_weight, _dragonBones_AnimationState_set_weight);

    olua_registerluatype<dragonBones::AnimationState>(L, "db.AnimationState");

    return 1;
}

static int _dragonBones_AnimationData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::AnimationData *)olua_toobj(L, 1, "db.AnimationData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::AnimationData *)olua_toobj(L, 1, "db.AnimationData");
    olua_push_cppobj(L, self, "db.AnimationData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_AnimationData_addBoneTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** bone */
    dragonBones::TimelineData *arg2 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.BoneData");
    olua_check_cppobj(L, 3, (void **)&arg2, "db.TimelineData");

    // void addBoneTimeline(dragonBones::BoneData *bone, dragonBones::TimelineData *value)
    self->addBoneTimeline(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_addConstraintTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::ConstraintData *arg1 = nullptr;       /** constraint */
    dragonBones::TimelineData *arg2 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.ConstraintData");
    olua_check_cppobj(L, 3, (void **)&arg2, "db.TimelineData");

    // void addConstraintTimeline(dragonBones::ConstraintData *constraint, dragonBones::TimelineData *value)
    self->addConstraintTimeline(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_addSlotTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::SlotData *arg1 = nullptr;       /** slot */
    dragonBones::TimelineData *arg2 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.SlotData");
    olua_check_cppobj(L, 3, (void **)&arg2, "db.TimelineData");

    // void addSlotTimeline(dragonBones::SlotData *slot, dragonBones::TimelineData *value)
    self->addSlotTimeline(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_cacheFrames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameRate */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_uint(L, 2, &arg1);

    // void cacheFrames(unsigned int frameRate)
    self->cacheFrames((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_getActionTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // dragonBones::TimelineData *getActionTimeline()
    dragonBones::TimelineData *ret = self->getActionTimeline();
    int num_ret = olua_push_cppobj(L, ret, "db.TimelineData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // dragonBones::ArmatureData *getParent()
    dragonBones::ArmatureData *ret = self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::AnimationData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_getZOrderTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // dragonBones::TimelineData *getZOrderTimeline()
    dragonBones::TimelineData *ret = self->getZOrderTimeline();
    int num_ret = olua_push_cppobj(L, ret, "db.TimelineData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_new(lua_State *L)
{
    olua_startinvoke(L);

    // AnimationData()
    dragonBones::AnimationData *ret = new dragonBones::AnimationData();
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_setActionTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::TimelineData *arg1 = nullptr;       /** pactionTimeline */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.TimelineData");

    // void setActionTimeline(dragonBones::TimelineData *pactionTimeline)
    self->setActionTimeline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::ArmatureData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.ArmatureData");

    // void setParent(dragonBones::ArmatureData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_setZOrderTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::TimelineData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.TimelineData");

    // void setZOrderTimeline(dragonBones::TimelineData *value)
    self->setZOrderTimeline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_actionTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // dragonBones::TimelineData *actionTimeline
    dragonBones::TimelineData *ret = self->actionTimeline;
    int num_ret = olua_push_cppobj(L, ret, "db.TimelineData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_actionTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::TimelineData *arg1 = nullptr;       /** actionTimeline */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.TimelineData");

    // dragonBones::TimelineData *actionTimeline
    self->actionTimeline = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_cacheFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // float cacheFrameRate
    float ret = self->cacheFrameRate;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_cacheFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    lua_Number arg1 = 0;       /** cacheFrameRate */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_number(L, 2, &arg1);

    // float cacheFrameRate
    self->cacheFrameRate = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_cachedFrames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // std::vector<bool> cachedFrames
    std::vector<bool> ret = self->cachedFrames;
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_bool(L, ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_cachedFrames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    std::vector<bool> arg1;       /** cachedFrames */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    luaL_checktype(L, 2, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 2);
    arg1.reserve((size_t)arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        bool obj;
        lua_rawgeti(L, 2, i);
        olua_check_bool(L, -1, &obj);
        arg1.push_back((bool)obj);
        lua_pop(L, 1);
    }

    // std::vector<bool> cachedFrames
    self->cachedFrames = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_duration(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // float duration
    float ret = self->duration;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_duration(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    lua_Number arg1 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_number(L, 2, &arg1);

    // float duration
    self->duration = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_fadeInTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // float fadeInTime
    float ret = self->fadeInTime;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_fadeInTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    lua_Number arg1 = 0;       /** fadeInTime */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_number(L, 2, &arg1);

    // float fadeInTime
    self->fadeInTime = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_frameCount(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // unsigned int frameCount
    unsigned int ret = self->frameCount;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_frameCount(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameCount */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int frameCount
    self->frameCount = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_frameFloatOffset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // unsigned int frameFloatOffset
    unsigned int ret = self->frameFloatOffset;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_frameFloatOffset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameFloatOffset */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int frameFloatOffset
    self->frameFloatOffset = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_frameIntOffset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // unsigned int frameIntOffset
    unsigned int ret = self->frameIntOffset;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_frameIntOffset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameIntOffset */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int frameIntOffset
    self->frameIntOffset = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_frameOffset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // unsigned int frameOffset
    unsigned int ret = self->frameOffset;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_frameOffset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameOffset */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int frameOffset
    self->frameOffset = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // dragonBones::ArmatureData *parent
    dragonBones::ArmatureData *ret = self->parent;
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_parent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::ArmatureData *arg1 = nullptr;       /** parent */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.ArmatureData");

    // dragonBones::ArmatureData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_playTimes(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // unsigned int playTimes
    unsigned int ret = self->playTimes;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_playTimes(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** playTimes */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int playTimes
    self->playTimes = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_scale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // float scale
    float ret = self->scale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_scale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_number(L, 2, &arg1);

    // float scale
    self->scale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationData_get_zOrderTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");

    // dragonBones::TimelineData *zOrderTimeline
    dragonBones::TimelineData *ret = self->zOrderTimeline;
    int num_ret = olua_push_cppobj(L, ret, "db.TimelineData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationData_set_zOrderTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::TimelineData *arg1 = nullptr;       /** zOrderTimeline */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.TimelineData");

    // dragonBones::TimelineData *zOrderTimeline
    self->zOrderTimeline = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_AnimationData(lua_State *L)
{
    oluacls_class(L, "db.AnimationData", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_AnimationData___gc);
    oluacls_func(L, "__move", _dragonBones_AnimationData___move);
    oluacls_func(L, "addBoneTimeline", _dragonBones_AnimationData_addBoneTimeline);
    oluacls_func(L, "addConstraintTimeline", _dragonBones_AnimationData_addConstraintTimeline);
    oluacls_func(L, "addSlotTimeline", _dragonBones_AnimationData_addSlotTimeline);
    oluacls_func(L, "cacheFrames", _dragonBones_AnimationData_cacheFrames);
    oluacls_func(L, "getActionTimeline", _dragonBones_AnimationData_getActionTimeline);
    oluacls_func(L, "getParent", _dragonBones_AnimationData_getParent);
    oluacls_func(L, "getTypeIndex", _dragonBones_AnimationData_getTypeIndex);
    oluacls_func(L, "getZOrderTimeline", _dragonBones_AnimationData_getZOrderTimeline);
    oluacls_func(L, "new", _dragonBones_AnimationData_new);
    oluacls_func(L, "setActionTimeline", _dragonBones_AnimationData_setActionTimeline);
    oluacls_func(L, "setParent", _dragonBones_AnimationData_setParent);
    oluacls_func(L, "setZOrderTimeline", _dragonBones_AnimationData_setZOrderTimeline);
    oluacls_prop(L, "actionTimeline", _dragonBones_AnimationData_getActionTimeline, _dragonBones_AnimationData_setActionTimeline);
    oluacls_prop(L, "parent", _dragonBones_AnimationData_getParent, _dragonBones_AnimationData_setParent);
    oluacls_prop(L, "typeIndex", _dragonBones_AnimationData_getTypeIndex, nullptr);
    oluacls_prop(L, "zOrderTimeline", _dragonBones_AnimationData_getZOrderTimeline, _dragonBones_AnimationData_setZOrderTimeline);
    oluacls_prop(L, "actionTimeline", _dragonBones_AnimationData_get_actionTimeline, _dragonBones_AnimationData_set_actionTimeline);
    oluacls_prop(L, "cacheFrameRate", _dragonBones_AnimationData_get_cacheFrameRate, _dragonBones_AnimationData_set_cacheFrameRate);
    oluacls_prop(L, "cachedFrames", _dragonBones_AnimationData_get_cachedFrames, _dragonBones_AnimationData_set_cachedFrames);
    oluacls_prop(L, "duration", _dragonBones_AnimationData_get_duration, _dragonBones_AnimationData_set_duration);
    oluacls_prop(L, "fadeInTime", _dragonBones_AnimationData_get_fadeInTime, _dragonBones_AnimationData_set_fadeInTime);
    oluacls_prop(L, "frameCount", _dragonBones_AnimationData_get_frameCount, _dragonBones_AnimationData_set_frameCount);
    oluacls_prop(L, "frameFloatOffset", _dragonBones_AnimationData_get_frameFloatOffset, _dragonBones_AnimationData_set_frameFloatOffset);
    oluacls_prop(L, "frameIntOffset", _dragonBones_AnimationData_get_frameIntOffset, _dragonBones_AnimationData_set_frameIntOffset);
    oluacls_prop(L, "frameOffset", _dragonBones_AnimationData_get_frameOffset, _dragonBones_AnimationData_set_frameOffset);
    oluacls_prop(L, "name", _dragonBones_AnimationData_get_name, _dragonBones_AnimationData_set_name);
    oluacls_prop(L, "parent", _dragonBones_AnimationData_get_parent, _dragonBones_AnimationData_set_parent);
    oluacls_prop(L, "playTimes", _dragonBones_AnimationData_get_playTimes, _dragonBones_AnimationData_set_playTimes);
    oluacls_prop(L, "scale", _dragonBones_AnimationData_get_scale, _dragonBones_AnimationData_set_scale);
    oluacls_prop(L, "zOrderTimeline", _dragonBones_AnimationData_get_zOrderTimeline, _dragonBones_AnimationData_set_zOrderTimeline);

    olua_registerluatype<dragonBones::AnimationData>(L, "db.AnimationData");

    return 1;
}

static int _dragonBones_AnimationConfig___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::AnimationConfig *)olua_toobj(L, 1, "db.AnimationConfig");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::AnimationConfig *)olua_toobj(L, 1, "db.AnimationConfig");
    olua_push_cppobj(L, self, "db.AnimationConfig");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_AnimationConfig_addBoneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    std::string arg2;       /** boneName */
    bool arg3 = false;       /** recursive */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Armature");
    olua_check_std_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void addBoneMask(dragonBones::Armature *armature, const std::string &boneName, bool recursive)
    self->addBoneMask(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_clear(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // void clear()
    self->clear();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_containsBoneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_std_string(L, 2, &arg1);

    // bool containsBoneMask(const std::string &boneName)
    bool ret = self->containsBoneMask(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_copyFrom(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    dragonBones::AnimationConfig *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.AnimationConfig");

    // void copyFrom(dragonBones::AnimationConfig *value)
    self->copyFrom(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_getFadeInTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // int getFadeInTweenType()
    int ret = self->getFadeInTweenType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_getFadeOutMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // int getFadeOutMode()
    int ret = self->getFadeOutMode();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_getFadeOutTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // int getFadeOutTweenType()
    int ret = self->getFadeOutTweenType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::AnimationConfig::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_new(lua_State *L)
{
    olua_startinvoke(L);

    // AnimationConfig()
    dragonBones::AnimationConfig *ret = new dragonBones::AnimationConfig();
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationConfig");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_removeBoneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    std::string arg2;       /** boneName */
    bool arg3 = false;       /** recursive */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Armature");
    olua_check_std_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void removeBoneMask(dragonBones::Armature *armature, const std::string &boneName, bool recursive)
    self->removeBoneMask(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_setFadeInTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_int(L, 2, &arg1);

    // void setFadeInTweenType(int value)
    self->setFadeInTweenType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_setFadeOutMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_int(L, 2, &arg1);

    // void setFadeOutMode(int value)
    self->setFadeOutMode((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_setFadeOutTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_int(L, 2, &arg1);

    // void setFadeOutTweenType(int value)
    self->setFadeOutTweenType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_actionEnabled(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // bool actionEnabled
    bool ret = self->actionEnabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_actionEnabled(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** actionEnabled */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool actionEnabled
    self->actionEnabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_additiveBlending(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // bool additiveBlending
    bool ret = self->additiveBlending;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_additiveBlending(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** additiveBlending */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool additiveBlending
    self->additiveBlending = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_animation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // std::string animation
    std::string ret = self->animation;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_animation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    std::string arg1;       /** animation */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_std_string(L, 2, &arg1);

    // std::string animation
    self->animation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_autoFadeOutTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // float autoFadeOutTime
    float ret = self->autoFadeOutTime;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_autoFadeOutTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Number arg1 = 0;       /** autoFadeOutTime */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float autoFadeOutTime
    self->autoFadeOutTime = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_boneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // std::vector<std::string> boneMask
    std::vector<std::string> ret = self->boneMask;
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_std_string(L, ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_boneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    std::vector<std::string> arg1;       /** boneMask */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    luaL_checktype(L, 2, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 2);
    arg1.reserve((size_t)arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        std::string obj;
        lua_rawgeti(L, 2, i);
        olua_check_std_string(L, -1, &obj);
        arg1.push_back((std::string)obj);
        lua_pop(L, 1);
    }

    // std::vector<std::string> boneMask
    self->boneMask = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_displayControl(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // bool displayControl
    bool ret = self->displayControl;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_displayControl(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** displayControl */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool displayControl
    self->displayControl = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_duration(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // float duration
    float ret = self->duration;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_duration(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Number arg1 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float duration
    self->duration = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_fadeInTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // float fadeInTime
    float ret = self->fadeInTime;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_fadeInTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Number arg1 = 0;       /** fadeInTime */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float fadeInTime
    self->fadeInTime = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_fadeInTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // dragonBones::TweenType fadeInTweenType
    dragonBones::TweenType ret = self->fadeInTweenType;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_fadeInTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Unsigned arg1 = 0;       /** fadeInTweenType */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_uint(L, 2, &arg1);

    // dragonBones::TweenType fadeInTweenType
    self->fadeInTweenType = (dragonBones::TweenType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_fadeOutMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // dragonBones::AnimationFadeOutMode fadeOutMode
    dragonBones::AnimationFadeOutMode ret = self->fadeOutMode;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_fadeOutMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Unsigned arg1 = 0;       /** fadeOutMode */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_uint(L, 2, &arg1);

    // dragonBones::AnimationFadeOutMode fadeOutMode
    self->fadeOutMode = (dragonBones::AnimationFadeOutMode)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_fadeOutTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // float fadeOutTime
    float ret = self->fadeOutTime;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_fadeOutTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Number arg1 = 0;       /** fadeOutTime */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float fadeOutTime
    self->fadeOutTime = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_fadeOutTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // dragonBones::TweenType fadeOutTweenType
    dragonBones::TweenType ret = self->fadeOutTweenType;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_fadeOutTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Unsigned arg1 = 0;       /** fadeOutTweenType */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_uint(L, 2, &arg1);

    // dragonBones::TweenType fadeOutTweenType
    self->fadeOutTweenType = (dragonBones::TweenType)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_group(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // std::string group
    std::string ret = self->group;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_group(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    std::string arg1;       /** group */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_std_string(L, 2, &arg1);

    // std::string group
    self->group = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_layer(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // int layer
    int ret = self->layer;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_layer(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Integer arg1 = 0;       /** layer */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_int(L, 2, &arg1);

    // int layer
    self->layer = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_pauseFadeIn(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // bool pauseFadeIn
    bool ret = self->pauseFadeIn;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_pauseFadeIn(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** pauseFadeIn */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool pauseFadeIn
    self->pauseFadeIn = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_pauseFadeOut(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // bool pauseFadeOut
    bool ret = self->pauseFadeOut;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_pauseFadeOut(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** pauseFadeOut */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool pauseFadeOut
    self->pauseFadeOut = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_playTimes(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // int playTimes
    int ret = self->playTimes;
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_playTimes(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Integer arg1 = 0;       /** playTimes */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_int(L, 2, &arg1);

    // int playTimes
    self->playTimes = (int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_position(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // float position
    float ret = self->position;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_position(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Number arg1 = 0;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float position
    self->position = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_resetToPose(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // bool resetToPose
    bool ret = self->resetToPose;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_resetToPose(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** resetToPose */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool resetToPose
    self->resetToPose = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_timeScale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // float timeScale
    float ret = self->timeScale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_timeScale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Number arg1 = 0;       /** timeScale */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float timeScale
    self->timeScale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_AnimationConfig_get_weight(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");

    // float weight
    float ret = self->weight;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_AnimationConfig_set_weight(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    lua_Number arg1 = 0;       /** weight */

    olua_to_cppobj(L, 1, (void **)&self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float weight
    self->weight = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_AnimationConfig(lua_State *L)
{
    oluacls_class(L, "db.AnimationConfig", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_AnimationConfig___gc);
    oluacls_func(L, "__move", _dragonBones_AnimationConfig___move);
    oluacls_func(L, "addBoneMask", _dragonBones_AnimationConfig_addBoneMask);
    oluacls_func(L, "clear", _dragonBones_AnimationConfig_clear);
    oluacls_func(L, "containsBoneMask", _dragonBones_AnimationConfig_containsBoneMask);
    oluacls_func(L, "copyFrom", _dragonBones_AnimationConfig_copyFrom);
    oluacls_func(L, "getFadeInTweenType", _dragonBones_AnimationConfig_getFadeInTweenType);
    oluacls_func(L, "getFadeOutMode", _dragonBones_AnimationConfig_getFadeOutMode);
    oluacls_func(L, "getFadeOutTweenType", _dragonBones_AnimationConfig_getFadeOutTweenType);
    oluacls_func(L, "getTypeIndex", _dragonBones_AnimationConfig_getTypeIndex);
    oluacls_func(L, "new", _dragonBones_AnimationConfig_new);
    oluacls_func(L, "removeBoneMask", _dragonBones_AnimationConfig_removeBoneMask);
    oluacls_func(L, "setFadeInTweenType", _dragonBones_AnimationConfig_setFadeInTweenType);
    oluacls_func(L, "setFadeOutMode", _dragonBones_AnimationConfig_setFadeOutMode);
    oluacls_func(L, "setFadeOutTweenType", _dragonBones_AnimationConfig_setFadeOutTweenType);
    oluacls_prop(L, "fadeInTweenType", _dragonBones_AnimationConfig_getFadeInTweenType, _dragonBones_AnimationConfig_setFadeInTweenType);
    oluacls_prop(L, "fadeOutMode", _dragonBones_AnimationConfig_getFadeOutMode, _dragonBones_AnimationConfig_setFadeOutMode);
    oluacls_prop(L, "fadeOutTweenType", _dragonBones_AnimationConfig_getFadeOutTweenType, _dragonBones_AnimationConfig_setFadeOutTweenType);
    oluacls_prop(L, "typeIndex", _dragonBones_AnimationConfig_getTypeIndex, nullptr);
    oluacls_prop(L, "actionEnabled", _dragonBones_AnimationConfig_get_actionEnabled, _dragonBones_AnimationConfig_set_actionEnabled);
    oluacls_prop(L, "additiveBlending", _dragonBones_AnimationConfig_get_additiveBlending, _dragonBones_AnimationConfig_set_additiveBlending);
    oluacls_prop(L, "animation", _dragonBones_AnimationConfig_get_animation, _dragonBones_AnimationConfig_set_animation);
    oluacls_prop(L, "autoFadeOutTime", _dragonBones_AnimationConfig_get_autoFadeOutTime, _dragonBones_AnimationConfig_set_autoFadeOutTime);
    oluacls_prop(L, "boneMask", _dragonBones_AnimationConfig_get_boneMask, _dragonBones_AnimationConfig_set_boneMask);
    oluacls_prop(L, "displayControl", _dragonBones_AnimationConfig_get_displayControl, _dragonBones_AnimationConfig_set_displayControl);
    oluacls_prop(L, "duration", _dragonBones_AnimationConfig_get_duration, _dragonBones_AnimationConfig_set_duration);
    oluacls_prop(L, "fadeInTime", _dragonBones_AnimationConfig_get_fadeInTime, _dragonBones_AnimationConfig_set_fadeInTime);
    oluacls_prop(L, "fadeInTweenType", _dragonBones_AnimationConfig_get_fadeInTweenType, _dragonBones_AnimationConfig_set_fadeInTweenType);
    oluacls_prop(L, "fadeOutMode", _dragonBones_AnimationConfig_get_fadeOutMode, _dragonBones_AnimationConfig_set_fadeOutMode);
    oluacls_prop(L, "fadeOutTime", _dragonBones_AnimationConfig_get_fadeOutTime, _dragonBones_AnimationConfig_set_fadeOutTime);
    oluacls_prop(L, "fadeOutTweenType", _dragonBones_AnimationConfig_get_fadeOutTweenType, _dragonBones_AnimationConfig_set_fadeOutTweenType);
    oluacls_prop(L, "group", _dragonBones_AnimationConfig_get_group, _dragonBones_AnimationConfig_set_group);
    oluacls_prop(L, "layer", _dragonBones_AnimationConfig_get_layer, _dragonBones_AnimationConfig_set_layer);
    oluacls_prop(L, "name", _dragonBones_AnimationConfig_get_name, _dragonBones_AnimationConfig_set_name);
    oluacls_prop(L, "pauseFadeIn", _dragonBones_AnimationConfig_get_pauseFadeIn, _dragonBones_AnimationConfig_set_pauseFadeIn);
    oluacls_prop(L, "pauseFadeOut", _dragonBones_AnimationConfig_get_pauseFadeOut, _dragonBones_AnimationConfig_set_pauseFadeOut);
    oluacls_prop(L, "playTimes", _dragonBones_AnimationConfig_get_playTimes, _dragonBones_AnimationConfig_set_playTimes);
    oluacls_prop(L, "position", _dragonBones_AnimationConfig_get_position, _dragonBones_AnimationConfig_set_position);
    oluacls_prop(L, "resetToPose", _dragonBones_AnimationConfig_get_resetToPose, _dragonBones_AnimationConfig_set_resetToPose);
    oluacls_prop(L, "timeScale", _dragonBones_AnimationConfig_get_timeScale, _dragonBones_AnimationConfig_set_timeScale);
    oluacls_prop(L, "weight", _dragonBones_AnimationConfig_get_weight, _dragonBones_AnimationConfig_set_weight);

    olua_registerluatype<dragonBones::AnimationConfig>(L, "db.AnimationConfig");

    return 1;
}

static int _dragonBones_DragonBonesData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::DragonBonesData *)olua_toobj(L, 1, "db.DragonBonesData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DragonBonesData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::DragonBonesData *)olua_toobj(L, 1, "db.DragonBonesData");
    olua_push_cppobj(L, self, "db.DragonBonesData");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_DragonBonesData_addArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    dragonBones::ArmatureData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.ArmatureData");

    // void addArmature(dragonBones::ArmatureData *value)
    self->addArmature(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DragonBonesData_getArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::string arg1;       /** armatureName */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::ArmatureData *getArmature(const std::string &armatureName)
    dragonBones::ArmatureData *ret = self->getArmature(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_getArmatureNames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");

    // const std::vector<std::string> &getArmatureNames()
    const std::vector<std::string> &ret = self->getArmatureNames();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_std_string(L, ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::DragonBonesData::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");

    // const dragonBones::UserData *getUserData()
    const dragonBones::UserData *ret = self->getUserData();
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_new(lua_State *L)
{
    olua_startinvoke(L);

    // DragonBonesData()
    dragonBones::DragonBonesData *ret = new dragonBones::DragonBonesData();
    int num_ret = olua_push_cppobj(L, ret, "db.DragonBonesData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_setUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.UserData");

    // void setUserData(dragonBones::UserData *value)
    self->setUserData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DragonBonesData_get_armatureNames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");

    // std::vector<std::string> armatureNames
    std::vector<std::string> ret = self->armatureNames;
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_std_string(L, ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_set_armatureNames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::vector<std::string> arg1;       /** armatureNames */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    luaL_checktype(L, 2, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 2);
    arg1.reserve((size_t)arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        std::string obj;
        lua_rawgeti(L, 2, i);
        olua_check_std_string(L, -1, &obj);
        arg1.push_back((std::string)obj);
        lua_pop(L, 1);
    }

    // std::vector<std::string> armatureNames
    self->armatureNames = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DragonBonesData_get_autoSearch(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");

    // bool autoSearch
    bool ret = self->autoSearch;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_set_autoSearch(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    bool arg1 = false;       /** autoSearch */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    olua_check_bool(L, 2, &arg1);

    // bool autoSearch
    self->autoSearch = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DragonBonesData_get_binary(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");

    // const char *binary
    const char *ret = self->binary;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_set_binary(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    const char *arg1 = nullptr;       /** binary */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    olua_check_string(L, 2, &arg1);

    // const char *binary
    self->binary = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DragonBonesData_get_cachedFrames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");

    // std::vector<float> cachedFrames
    std::vector<float> ret = self->cachedFrames;
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_set_cachedFrames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::vector<float> arg1;       /** cachedFrames */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    luaL_checktype(L, 2, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 2);
    arg1.reserve((size_t)arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        lua_Number obj;
        lua_rawgeti(L, 2, i);
        olua_check_number(L, -1, &obj);
        arg1.push_back((float)obj);
        lua_pop(L, 1);
    }

    // std::vector<float> cachedFrames
    self->cachedFrames = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DragonBonesData_get_frameIndices(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");

    // std::vector<unsigned int> frameIndices
    std::vector<unsigned int> ret = self->frameIndices;
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_uint(L, (lua_Unsigned)ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_set_frameIndices(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::vector<unsigned int> arg1;       /** frameIndices */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    luaL_checktype(L, 2, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 2);
    arg1.reserve((size_t)arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        lua_Unsigned obj;
        lua_rawgeti(L, 2, i);
        olua_check_uint(L, -1, &obj);
        arg1.push_back((unsigned int)obj);
        lua_pop(L, 1);
    }

    // std::vector<unsigned int> frameIndices
    self->frameIndices = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DragonBonesData_get_frameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");

    // unsigned int frameRate
    unsigned int ret = self->frameRate;
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_set_frameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameRate */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    olua_check_uint(L, 2, &arg1);

    // unsigned int frameRate
    self->frameRate = (unsigned int)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DragonBonesData_get_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_set_name(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    olua_check_std_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DragonBonesData_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");

    // dragonBones::UserData *userData
    dragonBones::UserData *ret = self->userData;
    int num_ret = olua_push_cppobj(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** userData */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.UserData");

    // dragonBones::UserData *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_DragonBonesData_get_version(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");

    // std::string version
    std::string ret = self->version;
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_DragonBonesData_set_version(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::string arg1;       /** version */

    olua_to_cppobj(L, 1, (void **)&self, "db.DragonBonesData");
    olua_check_std_string(L, 2, &arg1);

    // std::string version
    self->version = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_DragonBonesData(lua_State *L)
{
    oluacls_class(L, "db.DragonBonesData", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_DragonBonesData___gc);
    oluacls_func(L, "__move", _dragonBones_DragonBonesData___move);
    oluacls_func(L, "addArmature", _dragonBones_DragonBonesData_addArmature);
    oluacls_func(L, "getArmature", _dragonBones_DragonBonesData_getArmature);
    oluacls_func(L, "getArmatureNames", _dragonBones_DragonBonesData_getArmatureNames);
    oluacls_func(L, "getTypeIndex", _dragonBones_DragonBonesData_getTypeIndex);
    oluacls_func(L, "getUserData", _dragonBones_DragonBonesData_getUserData);
    oluacls_func(L, "new", _dragonBones_DragonBonesData_new);
    oluacls_func(L, "setUserData", _dragonBones_DragonBonesData_setUserData);
    oluacls_prop(L, "armatureNames", _dragonBones_DragonBonesData_getArmatureNames, nullptr);
    oluacls_prop(L, "typeIndex", _dragonBones_DragonBonesData_getTypeIndex, nullptr);
    oluacls_prop(L, "userData", _dragonBones_DragonBonesData_getUserData, _dragonBones_DragonBonesData_setUserData);
    oluacls_prop(L, "armatureNames", _dragonBones_DragonBonesData_get_armatureNames, _dragonBones_DragonBonesData_set_armatureNames);
    oluacls_prop(L, "autoSearch", _dragonBones_DragonBonesData_get_autoSearch, _dragonBones_DragonBonesData_set_autoSearch);
    oluacls_prop(L, "binary", _dragonBones_DragonBonesData_get_binary, _dragonBones_DragonBonesData_set_binary);
    oluacls_prop(L, "cachedFrames", _dragonBones_DragonBonesData_get_cachedFrames, _dragonBones_DragonBonesData_set_cachedFrames);
    oluacls_prop(L, "frameIndices", _dragonBones_DragonBonesData_get_frameIndices, _dragonBones_DragonBonesData_set_frameIndices);
    oluacls_prop(L, "frameRate", _dragonBones_DragonBonesData_get_frameRate, _dragonBones_DragonBonesData_set_frameRate);
    oluacls_prop(L, "name", _dragonBones_DragonBonesData_get_name, _dragonBones_DragonBonesData_set_name);
    oluacls_prop(L, "userData", _dragonBones_DragonBonesData_get_userData, _dragonBones_DragonBonesData_set_userData);
    oluacls_prop(L, "version", _dragonBones_DragonBonesData_get_version, _dragonBones_DragonBonesData_set_version);

    olua_registerluatype<dragonBones::DragonBonesData>(L, "db.DragonBonesData");

    return 1;
}

static int _dragonBones_BaseFactory___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::BaseFactory *)olua_toobj(L, 1, "db.BaseFactory");
    olua_push_cppobj(L, self, "db.BaseFactory");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_BaseFactory_addDragonBonesData1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::DragonBonesData *arg1 = nullptr;       /** data */
    std::string arg2;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.DragonBonesData");
    olua_check_std_string(L, 3, &arg2);

    // void addDragonBonesData(dragonBones::DragonBonesData *data, @optional const std::string &name)
    self->addDragonBonesData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseFactory_addDragonBonesData2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::DragonBonesData *arg1 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.DragonBonesData");

    // void addDragonBonesData(dragonBones::DragonBonesData *data, @optional const std::string &name)
    self->addDragonBonesData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseFactory_addDragonBonesData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "db.DragonBonesData"))) {
            // void addDragonBonesData(dragonBones::DragonBonesData *data, @optional const std::string &name)
            return _dragonBones_BaseFactory_addDragonBonesData2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "db.DragonBonesData")) && (olua_is_std_string(L, 3))) {
            // void addDragonBonesData(dragonBones::DragonBonesData *data, @optional const std::string &name)
            return _dragonBones_BaseFactory_addDragonBonesData1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::addDragonBonesData' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseFactory_addTextureAtlasData1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::TextureAtlasData *arg1 = nullptr;       /** data */
    std::string arg2;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.TextureAtlasData");
    olua_check_std_string(L, 3, &arg2);

    // void addTextureAtlasData(dragonBones::TextureAtlasData *data, @optional const std::string &name)
    self->addTextureAtlasData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseFactory_addTextureAtlasData2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::TextureAtlasData *arg1 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.TextureAtlasData");

    // void addTextureAtlasData(dragonBones::TextureAtlasData *data, @optional const std::string &name)
    self->addTextureAtlasData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseFactory_addTextureAtlasData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "db.TextureAtlasData"))) {
            // void addTextureAtlasData(dragonBones::TextureAtlasData *data, @optional const std::string &name)
            return _dragonBones_BaseFactory_addTextureAtlasData2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "db.TextureAtlasData")) && (olua_is_std_string(L, 3))) {
            // void addTextureAtlasData(dragonBones::TextureAtlasData *data, @optional const std::string &name)
            return _dragonBones_BaseFactory_addTextureAtlasData1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::addTextureAtlasData' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseFactory_buildArmature1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */
    std::string arg3;       /** skinName */
    std::string arg4;       /** textureAtlasName */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);

    // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    dragonBones::Armature *ret = self->buildArmature(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_buildArmature2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** armatureName */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    dragonBones::Armature *ret = self->buildArmature(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_buildArmature3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    dragonBones::Armature *ret = self->buildArmature(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_buildArmature4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */
    std::string arg3;       /** skinName */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);

    // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    dragonBones::Armature *ret = self->buildArmature(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_buildArmature(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
            return _dragonBones_BaseFactory_buildArmature2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
            return _dragonBones_BaseFactory_buildArmature3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4))) {
            // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
            return _dragonBones_BaseFactory_buildArmature4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5))) {
            // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
            return _dragonBones_BaseFactory_buildArmature1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::buildArmature' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseFactory_clear1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    bool arg1 = false;       /** disposeData */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_bool(L, 2, &arg1);

    // void clear(@optional bool disposeData)
    self->clear(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseFactory_clear2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");

    // void clear(@optional bool disposeData)
    self->clear();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseFactory_clear(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void clear(@optional bool disposeData)
        return _dragonBones_BaseFactory_clear2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void clear(@optional bool disposeData)
            return _dragonBones_BaseFactory_clear1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::clear' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseFactory_getArmatureData1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */
    std::string arg2;       /** dragonBonesName */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // dragonBones::ArmatureData *getArmatureData(const std::string &name, @optional const std::string &dragonBonesName)
    dragonBones::ArmatureData *ret = self->getArmatureData(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_getArmatureData2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::ArmatureData *getArmatureData(const std::string &name, @optional const std::string &dragonBonesName)
    dragonBones::ArmatureData *ret = self->getArmatureData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_getArmatureData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::ArmatureData *getArmatureData(const std::string &name, @optional const std::string &dragonBonesName)
            return _dragonBones_BaseFactory_getArmatureData2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // dragonBones::ArmatureData *getArmatureData(const std::string &name, @optional const std::string &dragonBonesName)
            return _dragonBones_BaseFactory_getArmatureData1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::getArmatureData' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseFactory_getClock(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");

    // dragonBones::WorldClock *getClock()
    dragonBones::WorldClock *ret = self->getClock();
    int num_ret = olua_push_cppobj(L, ret, "db.WorldClock");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_getDragonBonesData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::DragonBonesData *getDragonBonesData(const std::string &name)
    dragonBones::DragonBonesData *ret = self->getDragonBonesData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_parseDragonBonesData1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */
    std::string arg2;       /** name */
    lua_Number arg3 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name, @optional float scale)
    dragonBones::DragonBonesData *ret = self->parseDragonBonesData(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_parseDragonBonesData2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);

    // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name, @optional float scale)
    dragonBones::DragonBonesData *ret = self->parseDragonBonesData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_parseDragonBonesData3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */
    std::string arg2;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name, @optional float scale)
    dragonBones::DragonBonesData *ret = self->parseDragonBonesData(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_parseDragonBonesData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_string(L, 2))) {
            // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name, @optional float scale)
            return _dragonBones_BaseFactory_parseDragonBonesData2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name, @optional float scale)
            return _dragonBones_BaseFactory_parseDragonBonesData3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_number(L, 4))) {
            // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name, @optional float scale)
            return _dragonBones_BaseFactory_parseDragonBonesData1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::parseDragonBonesData' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseFactory_parseTextureAtlasData1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */
    void *arg2 = nullptr;       /** textureAtlas */
    std::string arg3;       /** name */
    lua_Number arg4 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_obj(L, 3, (void **)&arg2, "void *");
    olua_check_std_string(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name, @optional float scale)
    dragonBones::TextureAtlasData *ret = self->parseTextureAtlasData(arg1, arg2, arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_parseTextureAtlasData2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */
    void *arg2 = nullptr;       /** textureAtlas */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_obj(L, 3, (void **)&arg2, "void *");

    // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name, @optional float scale)
    dragonBones::TextureAtlasData *ret = self->parseTextureAtlasData(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_parseTextureAtlasData3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */
    void *arg2 = nullptr;       /** textureAtlas */
    std::string arg3;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_obj(L, 3, (void **)&arg2, "void *");
    olua_check_std_string(L, 4, &arg3);

    // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name, @optional float scale)
    dragonBones::TextureAtlasData *ret = self->parseTextureAtlasData(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_parseTextureAtlasData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_string(L, 2)) && (olua_is_obj(L, 3, "void *"))) {
            // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name, @optional float scale)
            return _dragonBones_BaseFactory_parseTextureAtlasData2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 2)) && (olua_is_obj(L, 3, "void *")) && (olua_is_std_string(L, 4))) {
            // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name, @optional float scale)
            return _dragonBones_BaseFactory_parseTextureAtlasData3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_string(L, 2)) && (olua_is_obj(L, 3, "void *")) && (olua_is_std_string(L, 4)) && (olua_is_number(L, 5))) {
            // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name, @optional float scale)
            return _dragonBones_BaseFactory_parseTextureAtlasData1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::parseTextureAtlasData' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseFactory_removeDragonBonesData1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */
    bool arg2 = false;       /** disposeData */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void removeDragonBonesData(const std::string &name, @optional bool disposeData)
    self->removeDragonBonesData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseFactory_removeDragonBonesData2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);

    // void removeDragonBonesData(const std::string &name, @optional bool disposeData)
    self->removeDragonBonesData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseFactory_removeDragonBonesData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void removeDragonBonesData(const std::string &name, @optional bool disposeData)
            return _dragonBones_BaseFactory_removeDragonBonesData2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void removeDragonBonesData(const std::string &name, @optional bool disposeData)
            return _dragonBones_BaseFactory_removeDragonBonesData1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::removeDragonBonesData' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseFactory_removeTextureAtlasData1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */
    bool arg2 = false;       /** disposeData */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void removeTextureAtlasData(const std::string &name, @optional bool disposeData)
    self->removeTextureAtlasData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseFactory_removeTextureAtlasData2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);

    // void removeTextureAtlasData(const std::string &name, @optional bool disposeData)
    self->removeTextureAtlasData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseFactory_removeTextureAtlasData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void removeTextureAtlasData(const std::string &name, @optional bool disposeData)
            return _dragonBones_BaseFactory_removeTextureAtlasData2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void removeTextureAtlasData(const std::string &name, @optional bool disposeData)
            return _dragonBones_BaseFactory_removeTextureAtlasData1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::removeTextureAtlasData' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseFactory_replaceAnimation1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    dragonBones::ArmatureData *arg2 = nullptr;       /** armatureData */
    bool arg3 = false;       /** isReplaceAll */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Armature");
    olua_check_cppobj(L, 3, (void **)&arg2, "db.ArmatureData");
    olua_check_bool(L, 4, &arg3);

    // bool replaceAnimation(dragonBones::Armature *armature, dragonBones::ArmatureData *armatureData, @optional bool isReplaceAll)
    bool ret = self->replaceAnimation(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_replaceAnimation2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    dragonBones::ArmatureData *arg2 = nullptr;       /** armatureData */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Armature");
    olua_check_cppobj(L, 3, (void **)&arg2, "db.ArmatureData");

    // bool replaceAnimation(dragonBones::Armature *armature, dragonBones::ArmatureData *armatureData, @optional bool isReplaceAll)
    bool ret = self->replaceAnimation(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_replaceAnimation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "db.Armature")) && (olua_is_cppobj(L, 3, "db.ArmatureData"))) {
            // bool replaceAnimation(dragonBones::Armature *armature, dragonBones::ArmatureData *armatureData, @optional bool isReplaceAll)
            return _dragonBones_BaseFactory_replaceAnimation2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 2, "db.Armature")) && (olua_is_cppobj(L, 3, "db.ArmatureData")) && (olua_is_bool(L, 4))) {
            // bool replaceAnimation(dragonBones::Armature *armature, dragonBones::ArmatureData *armatureData, @optional bool isReplaceAll)
            return _dragonBones_BaseFactory_replaceAnimation1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::replaceAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseFactory_replaceDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Slot *arg1 = nullptr;       /** slot */
    dragonBones::DisplayData *arg2 = nullptr;       /** displayData */
    lua_Integer arg3 = 0;       /** displayIndex */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Slot");
    olua_check_cppobj(L, 3, (void **)&arg2, "db.DisplayData");
    olua_check_int(L, 4, &arg3);

    // void replaceDisplay(dragonBones::Slot *slot, dragonBones::DisplayData *displayData, int displayIndex)
    self->replaceDisplay(arg1, arg2, (int)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_BaseFactory_replaceSlotDisplay1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** dragonBonesName */
    std::string arg2;       /** armatureName */
    std::string arg3;       /** slotName */
    std::string arg4;       /** displayName */
    dragonBones::Slot *arg5 = nullptr;       /** slot */
    lua_Integer arg6 = 0;       /** displayIndex */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_cppobj(L, 6, (void **)&arg5, "db.Slot");
    olua_check_int(L, 7, &arg6);

    // bool replaceSlotDisplay(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, const std::string &displayName, dragonBones::Slot *slot, @optional int displayIndex)
    bool ret = self->replaceSlotDisplay(arg1, arg2, arg3, arg4, arg5, (int)arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_replaceSlotDisplay2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** dragonBonesName */
    std::string arg2;       /** armatureName */
    std::string arg3;       /** slotName */
    std::string arg4;       /** displayName */
    dragonBones::Slot *arg5 = nullptr;       /** slot */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);
    olua_check_cppobj(L, 6, (void **)&arg5, "db.Slot");

    // bool replaceSlotDisplay(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, const std::string &displayName, dragonBones::Slot *slot, @optional int displayIndex)
    bool ret = self->replaceSlotDisplay(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_replaceSlotDisplay(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 5) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_cppobj(L, 6, "db.Slot"))) {
            // bool replaceSlotDisplay(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, const std::string &displayName, dragonBones::Slot *slot, @optional int displayIndex)
            return _dragonBones_BaseFactory_replaceSlotDisplay2(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5)) && (olua_is_cppobj(L, 6, "db.Slot")) && (olua_is_int(L, 7))) {
            // bool replaceSlotDisplay(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, const std::string &displayName, dragonBones::Slot *slot, @optional int displayIndex)
            return _dragonBones_BaseFactory_replaceSlotDisplay1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::replaceSlotDisplay' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_BaseFactory_replaceSlotDisplayList(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** dragonBonesName */
    std::string arg2;       /** armatureName */
    std::string arg3;       /** slotName */
    dragonBones::Slot *arg4 = nullptr;       /** slot */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_cppobj(L, 5, (void **)&arg4, "db.Slot");

    // bool replaceSlotDisplayList(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, dragonBones::Slot *slot)
    bool ret = self->replaceSlotDisplayList(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_get_autoSearch(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");

    // bool autoSearch
    bool ret = self->autoSearch;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_BaseFactory_set_autoSearch(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    bool arg1 = false;       /** autoSearch */

    olua_to_cppobj(L, 1, (void **)&self, "db.BaseFactory");
    olua_check_bool(L, 2, &arg1);

    // bool autoSearch
    self->autoSearch = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_BaseFactory(lua_State *L)
{
    oluacls_class(L, "db.BaseFactory", nullptr);
    oluacls_func(L, "__move", _dragonBones_BaseFactory___move);
    oluacls_func(L, "addDragonBonesData", _dragonBones_BaseFactory_addDragonBonesData);
    oluacls_func(L, "addTextureAtlasData", _dragonBones_BaseFactory_addTextureAtlasData);
    oluacls_func(L, "buildArmature", _dragonBones_BaseFactory_buildArmature);
    oluacls_func(L, "clear", _dragonBones_BaseFactory_clear);
    oluacls_func(L, "getArmatureData", _dragonBones_BaseFactory_getArmatureData);
    oluacls_func(L, "getClock", _dragonBones_BaseFactory_getClock);
    oluacls_func(L, "getDragonBonesData", _dragonBones_BaseFactory_getDragonBonesData);
    oluacls_func(L, "parseDragonBonesData", _dragonBones_BaseFactory_parseDragonBonesData);
    oluacls_func(L, "parseTextureAtlasData", _dragonBones_BaseFactory_parseTextureAtlasData);
    oluacls_func(L, "removeDragonBonesData", _dragonBones_BaseFactory_removeDragonBonesData);
    oluacls_func(L, "removeTextureAtlasData", _dragonBones_BaseFactory_removeTextureAtlasData);
    oluacls_func(L, "replaceAnimation", _dragonBones_BaseFactory_replaceAnimation);
    oluacls_func(L, "replaceDisplay", _dragonBones_BaseFactory_replaceDisplay);
    oluacls_func(L, "replaceSlotDisplay", _dragonBones_BaseFactory_replaceSlotDisplay);
    oluacls_func(L, "replaceSlotDisplayList", _dragonBones_BaseFactory_replaceSlotDisplayList);
    oluacls_prop(L, "clock", _dragonBones_BaseFactory_getClock, nullptr);
    oluacls_prop(L, "autoSearch", _dragonBones_BaseFactory_get_autoSearch, _dragonBones_BaseFactory_set_autoSearch);

    olua_registerluatype<dragonBones::BaseFactory>(L, "db.BaseFactory");

    return 1;
}

static int _dragonBones_Armature___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::Armature *)olua_toobj(L, 1, "db.Armature");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::Armature *)olua_toobj(L, 1, "db.Armature");
    olua_push_cppobj(L, self, "db.Armature");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_Armature_advanceTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    lua_Number arg1 = 0;       /** passedTime */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_number(L, 2, &arg1);

    // void advanceTime(float passedTime)
    self->advanceTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature_containsPoint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::Slot *containsPoint(float x, float y)
    dragonBones::Slot *ret = self->containsPoint((float)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_dispose(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // void dispose()
    self->dispose();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature_getAnimatable(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // dragonBones::IAnimatable *getAnimatable()
    dragonBones::IAnimatable *ret = self->getAnimatable();
    int num_ret = olua_push_cppobj(L, ret, "db.IAnimatable");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // dragonBones::Animation *getAnimation()
    dragonBones::Animation *ret = self->getAnimation();
    int num_ret = olua_push_cppobj(L, ret, "db.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getArmatureData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // const dragonBones::ArmatureData *getArmatureData()
    const dragonBones::ArmatureData *ret = self->getArmatureData();
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::Bone *getBone(const std::string &name)
    dragonBones::Bone *ret = self->getBone(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getBoneByDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    void *arg1 = nullptr;       /** display */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_obj(L, 2, (void **)&arg1, "void *");

    // dragonBones::Bone *getBoneByDisplay(void *display)
    dragonBones::Bone *ret = self->getBoneByDisplay(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getBones(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // const std::vector<Bone *> &getBones()
    const std::vector<dragonBones::Bone *> &ret = self->getBones();
    int num_ret = olua_push_std_vector(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getCacheFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // unsigned int getCacheFrameRate()
    unsigned int ret = self->getCacheFrameRate();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getClock(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // dragonBones::WorldClock *getClock()
    dragonBones::WorldClock *ret = self->getClock();
    int num_ret = olua_push_cppobj(L, ret, "db.WorldClock");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // void *getDisplay()
    void *ret = self->getDisplay();
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getFlipX(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // bool getFlipX()
    bool ret = self->getFlipX();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getFlipY(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // bool getFlipY()
    bool ret = self->getFlipY();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getName(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // const std::string &getName()
    const std::string &ret = self->getName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // dragonBones::Slot *getParent()
    dragonBones::Slot *ret = self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getReplacedTexture(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // void *getReplacedTexture()
    void *ret = self->getReplacedTexture();
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    std::string arg1;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::Slot *getSlot(const std::string &name)
    dragonBones::Slot *ret = self->getSlot(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getSlotByDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    void *arg1 = nullptr;       /** display */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_obj(L, 2, (void **)&arg1, "void *");

    // dragonBones::Slot *getSlotByDisplay(void *display)
    dragonBones::Slot *ret = self->getSlotByDisplay(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getSlots(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // const std::vector<Slot *> &getSlots()
    const std::vector<dragonBones::Slot *> &ret = self->getSlots();
    int num_ret = olua_push_std_vector(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::Armature::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_intersectsSegment1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */
    dragonBones::Point *arg7 = nullptr;       /** normalRadians */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_cppobj(L, 6, (void **)&arg5, "db.Point");
    olua_check_cppobj(L, 7, (void **)&arg6, "db.Point");
    olua_check_cppobj(L, 8, (void **)&arg7, "db.Point");

    // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    dragonBones::Slot *ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4, arg5, arg6, arg7);
    int num_ret = olua_push_cppobj(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_intersectsSegment2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    dragonBones::Slot *ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_intersectsSegment3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_cppobj(L, 6, (void **)&arg5, "db.Point");

    // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    dragonBones::Slot *ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4, arg5);
    int num_ret = olua_push_cppobj(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_intersectsSegment4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    lua_Number arg1 = 0;       /** xA */
    lua_Number arg2 = 0;       /** yA */
    lua_Number arg3 = 0;       /** xB */
    lua_Number arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_cppobj(L, 6, (void **)&arg5, "db.Point");
    olua_check_cppobj(L, 7, (void **)&arg6, "db.Point");

    // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    dragonBones::Slot *ret = self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4, arg5, arg6);
    int num_ret = olua_push_cppobj(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_intersectsSegment(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 4) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_Armature_intersectsSegment2(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_cppobj(L, 6, "db.Point"))) {
            // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_Armature_intersectsSegment3(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_cppobj(L, 6, "db.Point")) && (olua_is_cppobj(L, 7, "db.Point"))) {
            // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_Armature_intersectsSegment4(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_cppobj(L, 6, "db.Point")) && (olua_is_cppobj(L, 7, "db.Point")) && (olua_is_cppobj(L, 8, "db.Point"))) {
            // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _dragonBones_Armature_intersectsSegment1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Armature::intersectsSegment' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_Armature_invalidUpdate1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    std::string arg1;       /** boneName */
    bool arg2 = false;       /** updateSlot */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_std_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void invalidUpdate(@optional const std::string &boneName, @optional bool updateSlot)
    self->invalidUpdate(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature_invalidUpdate2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // void invalidUpdate(@optional const std::string &boneName, @optional bool updateSlot)
    self->invalidUpdate();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature_invalidUpdate3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_std_string(L, 2, &arg1);

    // void invalidUpdate(@optional const std::string &boneName, @optional bool updateSlot)
    self->invalidUpdate(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature_invalidUpdate(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void invalidUpdate(@optional const std::string &boneName, @optional bool updateSlot)
        return _dragonBones_Armature_invalidUpdate2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // void invalidUpdate(@optional const std::string &boneName, @optional bool updateSlot)
            return _dragonBones_Armature_invalidUpdate3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void invalidUpdate(@optional const std::string &boneName, @optional bool updateSlot)
            return _dragonBones_Armature_invalidUpdate1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Armature::invalidUpdate' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_Armature_new(lua_State *L)
{
    olua_startinvoke(L);

    // Armature()
    dragonBones::Armature *ret = new dragonBones::Armature();
    int num_ret = olua_push_cppobj(L, ret, "db.Armature");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_setCacheFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_uint(L, 2, &arg1);

    // void setCacheFrameRate(unsigned int value)
    self->setCacheFrameRate((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature_setClock(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    dragonBones::WorldClock *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.WorldClock");

    // void setClock(dragonBones::WorldClock *value)
    self->setClock(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature_setFlipX(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_bool(L, 2, &arg1);

    // void setFlipX(bool value)
    self->setFlipX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature_setFlipY(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_bool(L, 2, &arg1);

    // void setFlipY(bool value)
    self->setFlipY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature_setReplacedTexture(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    void *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_obj(L, 2, (void **)&arg1, "void *");

    // void setReplacedTexture(void *value)
    self->setReplacedTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature_get_inheritAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // bool inheritAnimation
    bool ret = self->inheritAnimation;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_set_inheritAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    bool arg1 = false;       /** inheritAnimation */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_bool(L, 2, &arg1);

    // bool inheritAnimation
    self->inheritAnimation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Armature_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");

    // void *userData
    void *ret = self->userData;
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Armature_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    void *arg1 = nullptr;       /** userData */

    olua_to_cppobj(L, 1, (void **)&self, "db.Armature");
    olua_check_obj(L, 2, (void **)&arg1, "void *");

    // void *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_Armature(lua_State *L)
{
    oluacls_class(L, "db.Armature", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_Armature___gc);
    oluacls_func(L, "__move", _dragonBones_Armature___move);
    oluacls_func(L, "advanceTime", _dragonBones_Armature_advanceTime);
    oluacls_func(L, "containsPoint", _dragonBones_Armature_containsPoint);
    oluacls_func(L, "dispose", _dragonBones_Armature_dispose);
    oluacls_func(L, "getAnimatable", _dragonBones_Armature_getAnimatable);
    oluacls_func(L, "getAnimation", _dragonBones_Armature_getAnimation);
    oluacls_func(L, "getArmatureData", _dragonBones_Armature_getArmatureData);
    oluacls_func(L, "getBone", _dragonBones_Armature_getBone);
    oluacls_func(L, "getBoneByDisplay", _dragonBones_Armature_getBoneByDisplay);
    oluacls_func(L, "getBones", _dragonBones_Armature_getBones);
    oluacls_func(L, "getCacheFrameRate", _dragonBones_Armature_getCacheFrameRate);
    oluacls_func(L, "getClock", _dragonBones_Armature_getClock);
    oluacls_func(L, "getDisplay", _dragonBones_Armature_getDisplay);
    oluacls_func(L, "getFlipX", _dragonBones_Armature_getFlipX);
    oluacls_func(L, "getFlipY", _dragonBones_Armature_getFlipY);
    oluacls_func(L, "getName", _dragonBones_Armature_getName);
    oluacls_func(L, "getParent", _dragonBones_Armature_getParent);
    oluacls_func(L, "getReplacedTexture", _dragonBones_Armature_getReplacedTexture);
    oluacls_func(L, "getSlot", _dragonBones_Armature_getSlot);
    oluacls_func(L, "getSlotByDisplay", _dragonBones_Armature_getSlotByDisplay);
    oluacls_func(L, "getSlots", _dragonBones_Armature_getSlots);
    oluacls_func(L, "getTypeIndex", _dragonBones_Armature_getTypeIndex);
    oluacls_func(L, "intersectsSegment", _dragonBones_Armature_intersectsSegment);
    oluacls_func(L, "invalidUpdate", _dragonBones_Armature_invalidUpdate);
    oluacls_func(L, "new", _dragonBones_Armature_new);
    oluacls_func(L, "setCacheFrameRate", _dragonBones_Armature_setCacheFrameRate);
    oluacls_func(L, "setClock", _dragonBones_Armature_setClock);
    oluacls_func(L, "setFlipX", _dragonBones_Armature_setFlipX);
    oluacls_func(L, "setFlipY", _dragonBones_Armature_setFlipY);
    oluacls_func(L, "setReplacedTexture", _dragonBones_Armature_setReplacedTexture);
    oluacls_prop(L, "animatable", _dragonBones_Armature_getAnimatable, nullptr);
    oluacls_prop(L, "animation", _dragonBones_Armature_getAnimation, nullptr);
    oluacls_prop(L, "armatureData", _dragonBones_Armature_getArmatureData, nullptr);
    oluacls_prop(L, "bones", _dragonBones_Armature_getBones, nullptr);
    oluacls_prop(L, "cacheFrameRate", _dragonBones_Armature_getCacheFrameRate, _dragonBones_Armature_setCacheFrameRate);
    oluacls_prop(L, "clock", _dragonBones_Armature_getClock, _dragonBones_Armature_setClock);
    oluacls_prop(L, "display", _dragonBones_Armature_getDisplay, nullptr);
    oluacls_prop(L, "flipX", _dragonBones_Armature_getFlipX, _dragonBones_Armature_setFlipX);
    oluacls_prop(L, "flipY", _dragonBones_Armature_getFlipY, _dragonBones_Armature_setFlipY);
    oluacls_prop(L, "name", _dragonBones_Armature_getName, nullptr);
    oluacls_prop(L, "parent", _dragonBones_Armature_getParent, nullptr);
    oluacls_prop(L, "replacedTexture", _dragonBones_Armature_getReplacedTexture, _dragonBones_Armature_setReplacedTexture);
    oluacls_prop(L, "slots", _dragonBones_Armature_getSlots, nullptr);
    oluacls_prop(L, "typeIndex", _dragonBones_Armature_getTypeIndex, nullptr);
    oluacls_prop(L, "inheritAnimation", _dragonBones_Armature_get_inheritAnimation, _dragonBones_Armature_set_inheritAnimation);
    oluacls_prop(L, "userData", _dragonBones_Armature_get_userData, _dragonBones_Armature_set_userData);

    olua_registerluatype<dragonBones::Armature>(L, "db.Armature");

    return 1;
}

static int _dragonBones_Animation___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::Animation *)olua_toobj(L, 1, "db.Animation");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Animation___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::Animation *)olua_toobj(L, 1, "db.Animation");
    olua_push_cppobj(L, self, "db.Animation");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_Animation_advanceTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    lua_Number arg1 = 0;       /** passedTime */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_number(L, 2, &arg1);

    // void advanceTime(float passedTime)
    self->advanceTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Animation_fadeIn1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Number arg2 = 0;       /** fadeInTime */
    lua_Integer arg3 = 0;       /** playTimes */
    lua_Integer arg4 = 0;       /** layer */
    std::string arg5;       /** group */
    lua_Unsigned arg6 = 0;       /** fadeOutMode */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);
    olua_check_uint(L, 7, &arg6);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
    dragonBones::AnimationState *ret = self->fadeIn(arg1, (float)arg2, (int)arg3, (int)arg4, arg5, (dragonBones::AnimationFadeOutMode)arg6);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_fadeIn2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
    dragonBones::AnimationState *ret = self->fadeIn(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_fadeIn3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Number arg2 = 0;       /** fadeInTime */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
    dragonBones::AnimationState *ret = self->fadeIn(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_fadeIn4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Number arg2 = 0;       /** fadeInTime */
    lua_Integer arg3 = 0;       /** playTimes */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
    dragonBones::AnimationState *ret = self->fadeIn(arg1, (float)arg2, (int)arg3);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_fadeIn5(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Number arg2 = 0;       /** fadeInTime */
    lua_Integer arg3 = 0;       /** playTimes */
    lua_Integer arg4 = 0;       /** layer */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
    dragonBones::AnimationState *ret = self->fadeIn(arg1, (float)arg2, (int)arg3, (int)arg4);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_fadeIn6(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Number arg2 = 0;       /** fadeInTime */
    lua_Integer arg3 = 0;       /** playTimes */
    lua_Integer arg4 = 0;       /** layer */
    std::string arg5;       /** group */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);
    olua_check_std_string(L, 6, &arg5);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
    dragonBones::AnimationState *ret = self->fadeIn(arg1, (float)arg2, (int)arg3, (int)arg4, arg5);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_fadeIn(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
            return _dragonBones_Animation_fadeIn2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
            return _dragonBones_Animation_fadeIn3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_int(L, 4))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
            return _dragonBones_Animation_fadeIn4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_int(L, 4)) && (olua_is_int(L, 5))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
            return _dragonBones_Animation_fadeIn5(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_int(L, 4)) && (olua_is_int(L, 5)) && (olua_is_std_string(L, 6))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
            return _dragonBones_Animation_fadeIn6(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_int(L, 4)) && (olua_is_int(L, 5)) && (olua_is_std_string(L, 6)) && (olua_is_uint(L, 7))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
            return _dragonBones_Animation_fadeIn1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::fadeIn' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_Animation_getAnimationConfig(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");

    // dragonBones::AnimationConfig *getAnimationConfig()
    dragonBones::AnimationConfig *ret = self->getAnimationConfig();
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationConfig");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_getAnimationNames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");

    // const std::vector<std::string> &getAnimationNames()
    const std::vector<std::string> &ret = self->getAnimationNames();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_std_string(L, ret[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_getLastAnimationName(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");

    // const std::string &getLastAnimationName()
    const std::string &ret = self->getLastAnimationName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_getLastAnimationState(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");

    // dragonBones::AnimationState *getLastAnimationState()
    dragonBones::AnimationState *ret = self->getLastAnimationState();
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_getState(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::AnimationState *getState(const std::string &animationName)
    dragonBones::AnimationState *ret = self->getState(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_getStates(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");

    // const std::vector<AnimationState *> &getStates()
    const std::vector<dragonBones::AnimationState *> &ret = self->getStates();
    int num_ret = olua_push_std_vector(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::Animation::getTypeIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndPlayByFrame1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Unsigned arg2 = 0;       /** frame */
    lua_Integer arg3 = 0;       /** playTimes */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByFrame(arg1, (unsigned int)arg2, (int)arg3);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndPlayByFrame2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByFrame(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndPlayByFrame3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Unsigned arg2 = 0;       /** frame */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByFrame(arg1, (unsigned int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndPlayByFrame(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame, @optional int playTimes)
            return _dragonBones_Animation_gotoAndPlayByFrame2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame, @optional int playTimes)
            return _dragonBones_Animation_gotoAndPlayByFrame3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_int(L, 4))) {
            // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame, @optional int playTimes)
            return _dragonBones_Animation_gotoAndPlayByFrame1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndPlayByFrame' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_Animation_gotoAndPlayByProgress1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Number arg2 = 0;       /** progress */
    lua_Integer arg3 = 0;       /** playTimes */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByProgress(arg1, (float)arg2, (int)arg3);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndPlayByProgress2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByProgress(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndPlayByProgress3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Number arg2 = 0;       /** progress */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByProgress(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndPlayByProgress(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress, @optional int playTimes)
            return _dragonBones_Animation_gotoAndPlayByProgress2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress, @optional int playTimes)
            return _dragonBones_Animation_gotoAndPlayByProgress3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_int(L, 4))) {
            // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress, @optional int playTimes)
            return _dragonBones_Animation_gotoAndPlayByProgress1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndPlayByProgress' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_Animation_gotoAndPlayByTime1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Number arg2 = 0;       /** time */
    lua_Integer arg3 = 0;       /** playTimes */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_int(L, 4, &arg3);

    // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByTime(arg1, (float)arg2, (int)arg3);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndPlayByTime2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByTime(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndPlayByTime3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Number arg2 = 0;       /** time */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByTime(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndPlayByTime(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time, @optional int playTimes)
            return _dragonBones_Animation_gotoAndPlayByTime2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time, @optional int playTimes)
            return _dragonBones_Animation_gotoAndPlayByTime3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_int(L, 4))) {
            // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time, @optional int playTimes)
            return _dragonBones_Animation_gotoAndPlayByTime1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndPlayByTime' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_Animation_gotoAndStopByFrame1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Unsigned arg2 = 0;       /** frame */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndStopByFrame(const std::string &animationName, @optional unsigned int frame)
    dragonBones::AnimationState *ret = self->gotoAndStopByFrame(arg1, (unsigned int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndStopByFrame2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndStopByFrame(const std::string &animationName, @optional unsigned int frame)
    dragonBones::AnimationState *ret = self->gotoAndStopByFrame(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndStopByFrame(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndStopByFrame(const std::string &animationName, @optional unsigned int frame)
            return _dragonBones_Animation_gotoAndStopByFrame2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // dragonBones::AnimationState *gotoAndStopByFrame(const std::string &animationName, @optional unsigned int frame)
            return _dragonBones_Animation_gotoAndStopByFrame1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndStopByFrame' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_Animation_gotoAndStopByProgress1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Number arg2 = 0;       /** progress */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndStopByProgress(const std::string &animationName, @optional float progress)
    dragonBones::AnimationState *ret = self->gotoAndStopByProgress(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndStopByProgress2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndStopByProgress(const std::string &animationName, @optional float progress)
    dragonBones::AnimationState *ret = self->gotoAndStopByProgress(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndStopByProgress(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndStopByProgress(const std::string &animationName, @optional float progress)
            return _dragonBones_Animation_gotoAndStopByProgress2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // dragonBones::AnimationState *gotoAndStopByProgress(const std::string &animationName, @optional float progress)
            return _dragonBones_Animation_gotoAndStopByProgress1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndStopByProgress' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_Animation_gotoAndStopByTime1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Number arg2 = 0;       /** time */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndStopByTime(const std::string &animationName, @optional float time)
    dragonBones::AnimationState *ret = self->gotoAndStopByTime(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndStopByTime2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndStopByTime(const std::string &animationName, @optional float time)
    dragonBones::AnimationState *ret = self->gotoAndStopByTime(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_gotoAndStopByTime(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndStopByTime(const std::string &animationName, @optional float time)
            return _dragonBones_Animation_gotoAndStopByTime2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // dragonBones::AnimationState *gotoAndStopByTime(const std::string &animationName, @optional float time)
            return _dragonBones_Animation_gotoAndStopByTime1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndStopByTime' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_Animation_hasAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);

    // bool hasAnimation(const std::string &animationName)
    bool ret = self->hasAnimation(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_init(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Armature");

    // void init(dragonBones::Armature *armature)
    self->init(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Animation_isCompleted(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");

    // bool isCompleted()
    bool ret = self->isCompleted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");

    // bool isPlaying()
    bool ret = self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_new(lua_State *L)
{
    olua_startinvoke(L);

    // Animation()
    dragonBones::Animation *ret = new dragonBones::Animation();
    int num_ret = olua_push_cppobj(L, ret, "db.Animation");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_play1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    lua_Integer arg2 = 0;       /** playTimes */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // dragonBones::AnimationState *play(@optional const std::string &animationName, @optional int playTimes)
    dragonBones::AnimationState *ret = self->play(arg1, (int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_play2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");

    // dragonBones::AnimationState *play(@optional const std::string &animationName, @optional int playTimes)
    dragonBones::AnimationState *ret = self->play();
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_play3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::AnimationState *play(@optional const std::string &animationName, @optional int playTimes)
    dragonBones::AnimationState *ret = self->play(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_play(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // dragonBones::AnimationState *play(@optional const std::string &animationName, @optional int playTimes)
        return _dragonBones_Animation_play2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::AnimationState *play(@optional const std::string &animationName, @optional int playTimes)
            return _dragonBones_Animation_play3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_int(L, 3))) {
            // dragonBones::AnimationState *play(@optional const std::string &animationName, @optional int playTimes)
            return _dragonBones_Animation_play1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::play' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_Animation_playConfig(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    dragonBones::AnimationConfig *arg1 = nullptr;       /** animationConfig */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.AnimationConfig");

    // dragonBones::AnimationState *playConfig(dragonBones::AnimationConfig *animationConfig)
    dragonBones::AnimationState *ret = self->playConfig(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_reset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");

    // void reset()
    self->reset();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Animation_stop(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_std_string(L, 2, &arg1);

    // void stop(const std::string &animationName)
    self->stop(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_Animation_get_timeScale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");

    // float timeScale
    float ret = self->timeScale;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_Animation_set_timeScale(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    lua_Number arg1 = 0;       /** timeScale */

    olua_to_cppobj(L, 1, (void **)&self, "db.Animation");
    olua_check_number(L, 2, &arg1);

    // float timeScale
    self->timeScale = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_Animation(lua_State *L)
{
    oluacls_class(L, "db.Animation", "db.BaseObject");
    oluacls_func(L, "__gc", _dragonBones_Animation___gc);
    oluacls_func(L, "__move", _dragonBones_Animation___move);
    oluacls_func(L, "advanceTime", _dragonBones_Animation_advanceTime);
    oluacls_func(L, "fadeIn", _dragonBones_Animation_fadeIn);
    oluacls_func(L, "getAnimationConfig", _dragonBones_Animation_getAnimationConfig);
    oluacls_func(L, "getAnimationNames", _dragonBones_Animation_getAnimationNames);
    oluacls_func(L, "getLastAnimationName", _dragonBones_Animation_getLastAnimationName);
    oluacls_func(L, "getLastAnimationState", _dragonBones_Animation_getLastAnimationState);
    oluacls_func(L, "getState", _dragonBones_Animation_getState);
    oluacls_func(L, "getStates", _dragonBones_Animation_getStates);
    oluacls_func(L, "getTypeIndex", _dragonBones_Animation_getTypeIndex);
    oluacls_func(L, "gotoAndPlayByFrame", _dragonBones_Animation_gotoAndPlayByFrame);
    oluacls_func(L, "gotoAndPlayByProgress", _dragonBones_Animation_gotoAndPlayByProgress);
    oluacls_func(L, "gotoAndPlayByTime", _dragonBones_Animation_gotoAndPlayByTime);
    oluacls_func(L, "gotoAndStopByFrame", _dragonBones_Animation_gotoAndStopByFrame);
    oluacls_func(L, "gotoAndStopByProgress", _dragonBones_Animation_gotoAndStopByProgress);
    oluacls_func(L, "gotoAndStopByTime", _dragonBones_Animation_gotoAndStopByTime);
    oluacls_func(L, "hasAnimation", _dragonBones_Animation_hasAnimation);
    oluacls_func(L, "init", _dragonBones_Animation_init);
    oluacls_func(L, "isCompleted", _dragonBones_Animation_isCompleted);
    oluacls_func(L, "isPlaying", _dragonBones_Animation_isPlaying);
    oluacls_func(L, "new", _dragonBones_Animation_new);
    oluacls_func(L, "play", _dragonBones_Animation_play);
    oluacls_func(L, "playConfig", _dragonBones_Animation_playConfig);
    oluacls_func(L, "reset", _dragonBones_Animation_reset);
    oluacls_func(L, "stop", _dragonBones_Animation_stop);
    oluacls_prop(L, "animationConfig", _dragonBones_Animation_getAnimationConfig, nullptr);
    oluacls_prop(L, "animationNames", _dragonBones_Animation_getAnimationNames, nullptr);
    oluacls_prop(L, "completed", _dragonBones_Animation_isCompleted, nullptr);
    oluacls_prop(L, "lastAnimationName", _dragonBones_Animation_getLastAnimationName, nullptr);
    oluacls_prop(L, "lastAnimationState", _dragonBones_Animation_getLastAnimationState, nullptr);
    oluacls_prop(L, "playing", _dragonBones_Animation_isPlaying, nullptr);
    oluacls_prop(L, "states", _dragonBones_Animation_getStates, nullptr);
    oluacls_prop(L, "typeIndex", _dragonBones_Animation_getTypeIndex, nullptr);
    oluacls_prop(L, "timeScale", _dragonBones_Animation_get_timeScale, _dragonBones_Animation_set_timeScale);

    olua_registerluatype<dragonBones::Animation>(L, "db.Animation");

    return 1;
}

static int _dragonBones_CCFactory___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::CCFactory *)olua_toobj(L, 1, "db.Factory");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setrawobj(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CCFactory___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::CCFactory *)olua_toobj(L, 1, "db.Factory");
    olua_push_cppobj(L, self, "db.Factory");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_CCFactory_buildArmatureDisplay1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */
    std::string arg3;       /** skinName */
    std::string arg4;       /** textureAtlasName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);
    olua_check_std_string(L, 5, &arg4);

    // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    dragonBones::CCArmatureDisplay *ret = self->buildArmatureDisplay(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_buildArmatureDisplay2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** armatureName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    dragonBones::CCArmatureDisplay *ret = self->buildArmatureDisplay(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_buildArmatureDisplay3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    dragonBones::CCArmatureDisplay *ret = self->buildArmatureDisplay(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_buildArmatureDisplay4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */
    std::string arg3;       /** skinName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_std_string(L, 4, &arg3);

    // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    dragonBones::CCArmatureDisplay *ret = self->buildArmatureDisplay(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_buildArmatureDisplay(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
            return _dragonBones_CCFactory_buildArmatureDisplay2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
            return _dragonBones_CCFactory_buildArmatureDisplay3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4))) {
            // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
            return _dragonBones_CCFactory_buildArmatureDisplay4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_std_string(L, 4)) && (olua_is_std_string(L, 5))) {
            // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
            return _dragonBones_CCFactory_buildArmatureDisplay1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CCFactory::buildArmatureDisplay' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_CCFactory_getClock(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::WorldClock *getClock()
    dragonBones::WorldClock *ret = dragonBones::CCFactory::getClock();
    int num_ret = olua_push_cppobj(L, ret, "db.WorldClock");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_getFactory(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::CCFactory *getFactory()
    dragonBones::CCFactory *ret = dragonBones::CCFactory::getFactory();
    int num_ret = olua_push_cppobj(L, ret, "db.Factory");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_getSoundEventManager(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");

    // dragonBones::CCArmatureDisplay *getSoundEventManager()
    dragonBones::CCArmatureDisplay *ret = self->getSoundEventManager();
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_getTextureDisplay1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** textureName */
    std::string arg2;       /** dragonBonesName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // cocos2d::Sprite *getTextureDisplay(const std::string &textureName, @optional const std::string &dragonBonesName)
    cocos2d::Sprite *ret = self->getTextureDisplay(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_getTextureDisplay2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** textureName */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);

    // cocos2d::Sprite *getTextureDisplay(const std::string &textureName, @optional const std::string &dragonBonesName)
    cocos2d::Sprite *ret = self->getTextureDisplay(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_getTextureDisplay(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // cocos2d::Sprite *getTextureDisplay(const std::string &textureName, @optional const std::string &dragonBonesName)
            return _dragonBones_CCFactory_getTextureDisplay2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // cocos2d::Sprite *getTextureDisplay(const std::string &textureName, @optional const std::string &dragonBonesName)
            return _dragonBones_CCFactory_getTextureDisplay1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CCFactory::getTextureDisplay' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_CCFactory_loadDragonBonesData1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */
    std::string arg2;       /** name */
    lua_Number arg3 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name, @optional float scale)
    dragonBones::DragonBonesData *ret = self->loadDragonBonesData(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_loadDragonBonesData2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name, @optional float scale)
    dragonBones::DragonBonesData *ret = self->loadDragonBonesData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_loadDragonBonesData3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */
    std::string arg2;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name, @optional float scale)
    dragonBones::DragonBonesData *ret = self->loadDragonBonesData(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_loadDragonBonesData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name, @optional float scale)
            return _dragonBones_CCFactory_loadDragonBonesData2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name, @optional float scale)
            return _dragonBones_CCFactory_loadDragonBonesData3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_number(L, 4))) {
            // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name, @optional float scale)
            return _dragonBones_CCFactory_loadDragonBonesData1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CCFactory::loadDragonBonesData' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_CCFactory_loadTextureAtlasData1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */
    std::string arg2;       /** name */
    lua_Number arg3 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name, @optional float scale)
    dragonBones::TextureAtlasData *ret = self->loadTextureAtlasData(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_loadTextureAtlasData2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);

    // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name, @optional float scale)
    dragonBones::TextureAtlasData *ret = self->loadTextureAtlasData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_loadTextureAtlasData3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */
    std::string arg2;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "db.Factory");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name, @optional float scale)
    dragonBones::TextureAtlasData *ret = self->loadTextureAtlasData(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCFactory_loadTextureAtlasData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 2))) {
            // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name, @optional float scale)
            return _dragonBones_CCFactory_loadTextureAtlasData2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name, @optional float scale)
            return _dragonBones_CCFactory_loadTextureAtlasData3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_number(L, 4))) {
            // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name, @optional float scale)
            return _dragonBones_CCFactory_loadTextureAtlasData1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CCFactory::loadTextureAtlasData' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_CCFactory_new(lua_State *L)
{
    olua_startinvoke(L);

    // CCFactory()
    dragonBones::CCFactory *ret = new dragonBones::CCFactory();
    int num_ret = olua_push_cppobj(L, ret, "db.Factory");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_dragonBones_CCFactory(lua_State *L)
{
    oluacls_class(L, "db.Factory", "db.BaseFactory");
    oluacls_func(L, "__gc", _dragonBones_CCFactory___gc);
    oluacls_func(L, "__move", _dragonBones_CCFactory___move);
    oluacls_func(L, "buildArmatureDisplay", _dragonBones_CCFactory_buildArmatureDisplay);
    oluacls_func(L, "getClock", _dragonBones_CCFactory_getClock);
    oluacls_func(L, "getFactory", _dragonBones_CCFactory_getFactory);
    oluacls_func(L, "getSoundEventManager", _dragonBones_CCFactory_getSoundEventManager);
    oluacls_func(L, "getTextureDisplay", _dragonBones_CCFactory_getTextureDisplay);
    oluacls_func(L, "loadDragonBonesData", _dragonBones_CCFactory_loadDragonBonesData);
    oluacls_func(L, "loadTextureAtlasData", _dragonBones_CCFactory_loadTextureAtlasData);
    oluacls_func(L, "new", _dragonBones_CCFactory_new);
    oluacls_prop(L, "clock", _dragonBones_CCFactory_getClock, nullptr);
    oluacls_prop(L, "factory", _dragonBones_CCFactory_getFactory, nullptr);
    oluacls_prop(L, "soundEventManager", _dragonBones_CCFactory_getSoundEventManager, nullptr);

    olua_registerluatype<dragonBones::CCFactory>(L, "db.Factory");

    return 1;
}

static int _dragonBones_CCArmatureDisplay___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::CCArmatureDisplay *)olua_toobj(L, 1, "db.ArmatureDisplay");
    olua_push_cppobj(L, self, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return 1;
}

static int _dragonBones_CCArmatureDisplay_addDBEventListener(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    std::string arg1;       /** type */
    std::function<void(dragonBones::EventObject *)> arg2;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");
    olua_check_std_string(L, 2, &arg1);

    void *cb_store = (void *)self;
    std::string cb_tag = (arg1);
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 3, OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](dragonBones::EventObject *arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "db.EventObject");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void addDBEventListener(const std::string &type, @local const std::function<void (EventObject *)> &listener)
    self->addDBEventListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CCArmatureDisplay_create(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::CCArmatureDisplay *create()
    dragonBones::CCArmatureDisplay *ret = dragonBones::CCArmatureDisplay::create();
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCArmatureDisplay_dbClear(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");

    // void dbClear()
    self->dbClear();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CCArmatureDisplay_dbInit(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");
    olua_check_cppobj(L, 2, (void **)&arg1, "db.Armature");

    // void dbInit(dragonBones::Armature *armature)
    self->dbInit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CCArmatureDisplay_dbUpdate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");

    // void dbUpdate()
    self->dbUpdate();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CCArmatureDisplay_dispatchDBEvent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    std::string arg1;       /** type */
    dragonBones::EventObject *arg2 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");
    olua_check_std_string(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "db.EventObject");

    // void dispatchDBEvent(const std::string &type, dragonBones::EventObject *value)
    self->dispatchDBEvent(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CCArmatureDisplay_dispose1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    bool arg1 = false;       /** disposeProxy */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");
    olua_check_bool(L, 2, &arg1);

    // void dispose(@optional bool disposeProxy)
    self->dispose(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CCArmatureDisplay_dispose2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");

    // void dispose(@optional bool disposeProxy)
    self->dispose();

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CCArmatureDisplay_dispose(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void dispose(@optional bool disposeProxy)
        return _dragonBones_CCArmatureDisplay_dispose2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void dispose(@optional bool disposeProxy)
            return _dragonBones_CCArmatureDisplay_dispose1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CCArmatureDisplay::dispose' not support '%d' arguments", num_args);

    return 0;
}

static int _dragonBones_CCArmatureDisplay_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");

    // dragonBones::Animation *getAnimation()
    dragonBones::Animation *ret = self->getAnimation();
    int num_ret = olua_push_cppobj(L, ret, "db.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCArmatureDisplay_getArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");

    // dragonBones::Armature *getArmature()
    dragonBones::Armature *ret = self->getArmature();
    int num_ret = olua_push_cppobj(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCArmatureDisplay_hasDBEventListener(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    std::string arg1;       /** type */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");
    olua_check_std_string(L, 2, &arg1);

    // bool hasDBEventListener(const std::string &type)
    bool ret = self->hasDBEventListener(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCArmatureDisplay_new(lua_State *L)
{
    olua_startinvoke(L);

    // CCArmatureDisplay()
    dragonBones::CCArmatureDisplay *ret = new dragonBones::CCArmatureDisplay();
    int num_ret = olua_push_cppobj(L, ret, "db.ArmatureDisplay");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCArmatureDisplay_removeDBEventListener(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    std::string arg1;       /** type */
    std::function<void(dragonBones::EventObject *)> arg2;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");
    olua_check_std_string(L, 2, &arg1);

    std::string cb_tag = (arg1);
    void *cb_store = (void *)self;
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // void removeDBEventListener(const std::string &type, @nullable @local const std::function<void (EventObject *)> &listener)
    self->removeDBEventListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _dragonBones_CCArmatureDisplay_get_debugDraw(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");

    // bool debugDraw
    bool ret = self->debugDraw;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _dragonBones_CCArmatureDisplay_set_debugDraw(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    bool arg1 = false;       /** debugDraw */

    olua_to_cppobj(L, 1, (void **)&self, "db.ArmatureDisplay");
    olua_check_bool(L, 2, &arg1);

    // bool debugDraw
    self->debugDraw = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_dragonBones_CCArmatureDisplay(lua_State *L)
{
    oluacls_class(L, "db.ArmatureDisplay", "cc.Node");
    oluacls_func(L, "__move", _dragonBones_CCArmatureDisplay___move);
    oluacls_func(L, "addDBEventListener", _dragonBones_CCArmatureDisplay_addDBEventListener);
    oluacls_func(L, "create", _dragonBones_CCArmatureDisplay_create);
    oluacls_func(L, "dbClear", _dragonBones_CCArmatureDisplay_dbClear);
    oluacls_func(L, "dbInit", _dragonBones_CCArmatureDisplay_dbInit);
    oluacls_func(L, "dbUpdate", _dragonBones_CCArmatureDisplay_dbUpdate);
    oluacls_func(L, "dispatchDBEvent", _dragonBones_CCArmatureDisplay_dispatchDBEvent);
    oluacls_func(L, "dispose", _dragonBones_CCArmatureDisplay_dispose);
    oluacls_func(L, "getAnimation", _dragonBones_CCArmatureDisplay_getAnimation);
    oluacls_func(L, "getArmature", _dragonBones_CCArmatureDisplay_getArmature);
    oluacls_func(L, "hasDBEventListener", _dragonBones_CCArmatureDisplay_hasDBEventListener);
    oluacls_func(L, "new", _dragonBones_CCArmatureDisplay_new);
    oluacls_func(L, "removeDBEventListener", _dragonBones_CCArmatureDisplay_removeDBEventListener);
    oluacls_prop(L, "animation", _dragonBones_CCArmatureDisplay_getAnimation, nullptr);
    oluacls_prop(L, "armature", _dragonBones_CCArmatureDisplay_getArmature, nullptr);
    oluacls_prop(L, "debugDraw", _dragonBones_CCArmatureDisplay_get_debugDraw, _dragonBones_CCArmatureDisplay_set_debugDraw);

    olua_registerluatype<dragonBones::CCArmatureDisplay>(L, "db.ArmatureDisplay");

    return 1;
}

int luaopen_dragonbones(lua_State *L)
{
    olua_require(L, "db.BinaryOffset", luaopen_dragonBones_BinaryOffset);
    olua_require(L, "db.ArmatureType", luaopen_dragonBones_ArmatureType);
    olua_require(L, "db.OffsetMode", luaopen_dragonBones_OffsetMode);
    olua_require(L, "db.DisplayType", luaopen_dragonBones_DisplayType);
    olua_require(L, "db.BoundingBoxType", luaopen_dragonBones_BoundingBoxType);
    olua_require(L, "db.ActionType", luaopen_dragonBones_ActionType);
    olua_require(L, "db.BlendMode", luaopen_dragonBones_BlendMode);
    olua_require(L, "db.TweenType", luaopen_dragonBones_TweenType);
    olua_require(L, "db.TimelineType", luaopen_dragonBones_TimelineType);
    olua_require(L, "db.AnimationFadeOutMode", luaopen_dragonBones_AnimationFadeOutMode);
    olua_require(L, "db.TextureFormat", luaopen_dragonBones_TextureFormat);
    olua_require(L, "db.BaseObject", luaopen_dragonBones_BaseObject);
    olua_require(L, "db.EventObject", luaopen_dragonBones_EventObject);
    olua_require(L, "db.TransformObject", luaopen_dragonBones_TransformObject);
    olua_require(L, "db.Point", luaopen_dragonBones_Point);
    olua_require(L, "db.ConstraintData", luaopen_dragonBones_ConstraintData);
    olua_require(L, "db.IKConstraintData", luaopen_dragonBones_IKConstraintData);
    olua_require(L, "db.TimelineData", luaopen_dragonBones_TimelineData);
    olua_require(L, "db.IAnimatable", luaopen_dragonBones_IAnimatable);
    olua_require(L, "db.WorldClock", luaopen_dragonBones_WorldClock);
    olua_require(L, "db.Slot", luaopen_dragonBones_Slot);
    olua_require(L, "db.Bone", luaopen_dragonBones_Bone);
    olua_require(L, "db.DisplayData", luaopen_dragonBones_DisplayData);
    olua_require(L, "db.ActionData", luaopen_dragonBones_ActionData);
    olua_require(L, "db.UserData", luaopen_dragonBones_UserData);
    olua_require(L, "db.BoundingBoxData", luaopen_dragonBones_BoundingBoxData);
    olua_require(L, "db.BoundingBoxDisplayData", luaopen_dragonBones_BoundingBoxDisplayData);
    olua_require(L, "db.CanvasData", luaopen_dragonBones_CanvasData);
    olua_require(L, "db.TextureAtlasData", luaopen_dragonBones_TextureAtlasData);
    olua_require(L, "db.TextureData", luaopen_dragonBones_TextureData);
    olua_require(L, "db.ArmatureData", luaopen_dragonBones_ArmatureData);
    olua_require(L, "db.SkinData", luaopen_dragonBones_SkinData);
    olua_require(L, "db.BoneData", luaopen_dragonBones_BoneData);
    olua_require(L, "db.SlotData", luaopen_dragonBones_SlotData);
    olua_require(L, "db.AnimationState", luaopen_dragonBones_AnimationState);
    olua_require(L, "db.AnimationData", luaopen_dragonBones_AnimationData);
    olua_require(L, "db.AnimationConfig", luaopen_dragonBones_AnimationConfig);
    olua_require(L, "db.DragonBonesData", luaopen_dragonBones_DragonBonesData);
    olua_require(L, "db.BaseFactory", luaopen_dragonBones_BaseFactory);
    olua_require(L, "db.Armature", luaopen_dragonBones_Armature);
    olua_require(L, "db.Animation", luaopen_dragonBones_Animation);
    olua_require(L, "db.Factory", luaopen_dragonBones_CCFactory);
    olua_require(L, "db.ArmatureDisplay", luaopen_dragonBones_CCArmatureDisplay);
    return 0;
}
