//
// AUTO GENERATED, DO NOT MODIFY!
//
#include "lua_dragonbones.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "CCDragonBonesHeaders.h"

static int _olua_module_dragonbones(lua_State *L);

static int _olua_fun_dragonBones_Rectangle___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::Rectangle *)olua_toobj(L, 1, "db.Rectangle");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Rectangle_clear(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Rectangle *self = nullptr;

    olua_to_object(L, 1, &self, "db.Rectangle");

    // void clear()
    self->clear();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Rectangle_height$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Rectangle *self = nullptr;

    olua_to_object(L, 1, &self, "db.Rectangle");

    // float height
    float ret = self->height;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Rectangle_height$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Rectangle *self = nullptr;
    float arg1 = 0;       /** height */

    olua_to_object(L, 1, &self, "db.Rectangle");
    olua_check_number(L, 2, &arg1);

    // float height
    self->height = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Rectangle_height(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float height
        return _olua_fun_dragonBones_Rectangle_height$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Rectangle")) && (olua_is_number(L, 2))) {
            // float height
            return _olua_fun_dragonBones_Rectangle_height$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Rectangle::height' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Rectangle_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::Rectangle()
    dragonBones::Rectangle *ret = new dragonBones::Rectangle();
    int num_ret = olua_push_object(L, ret, "db.Rectangle");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Rectangle_width$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Rectangle *self = nullptr;

    olua_to_object(L, 1, &self, "db.Rectangle");

    // float width
    float ret = self->width;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Rectangle_width$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Rectangle *self = nullptr;
    float arg1 = 0;       /** width */

    olua_to_object(L, 1, &self, "db.Rectangle");
    olua_check_number(L, 2, &arg1);

    // float width
    self->width = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Rectangle_width(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float width
        return _olua_fun_dragonBones_Rectangle_width$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Rectangle")) && (olua_is_number(L, 2))) {
            // float width
            return _olua_fun_dragonBones_Rectangle_width$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Rectangle::width' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Rectangle_x$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Rectangle *self = nullptr;

    olua_to_object(L, 1, &self, "db.Rectangle");

    // float x
    float ret = self->x;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Rectangle_x$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Rectangle *self = nullptr;
    float arg1 = 0;       /** x */

    olua_to_object(L, 1, &self, "db.Rectangle");
    olua_check_number(L, 2, &arg1);

    // float x
    self->x = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Rectangle_x(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float x
        return _olua_fun_dragonBones_Rectangle_x$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Rectangle")) && (olua_is_number(L, 2))) {
            // float x
            return _olua_fun_dragonBones_Rectangle_x$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Rectangle::x' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Rectangle_y$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Rectangle *self = nullptr;

    olua_to_object(L, 1, &self, "db.Rectangle");

    // float y
    float ret = self->y;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Rectangle_y$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Rectangle *self = nullptr;
    float arg1 = 0;       /** y */

    olua_to_object(L, 1, &self, "db.Rectangle");
    olua_check_number(L, 2, &arg1);

    // float y
    self->y = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Rectangle_y(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float y
        return _olua_fun_dragonBones_Rectangle_y$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Rectangle")) && (olua_is_number(L, 2))) {
            // float y
            return _olua_fun_dragonBones_Rectangle_y$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Rectangle::y' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_Rectangle(lua_State *L)
{
    oluacls_class<dragonBones::Rectangle>(L, "db.Rectangle");
    oluacls_func(L, "__gc", _olua_fun_dragonBones_Rectangle___gc);
    oluacls_func(L, "clear", _olua_fun_dragonBones_Rectangle_clear);
    oluacls_func(L, "new", _olua_fun_dragonBones_Rectangle_new);
    oluacls_prop(L, "x", _olua_fun_dragonBones_Rectangle_x, _olua_fun_dragonBones_Rectangle_x);
    oluacls_prop(L, "y", _olua_fun_dragonBones_Rectangle_y, _olua_fun_dragonBones_Rectangle_y);
    oluacls_prop(L, "width", _olua_fun_dragonBones_Rectangle_width, _olua_fun_dragonBones_Rectangle_width);
    oluacls_prop(L, "height", _olua_fun_dragonBones_Rectangle_height, _olua_fun_dragonBones_Rectangle_height);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_Rectangle(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.Rectangle")) {
        luaL_error(L, "class not found: dragonBones::Rectangle");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_db_BinaryOffset(lua_State *L)
{
    oluacls_class<dragonBones::BinaryOffset>(L, "db.BinaryOffset");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "DeformCount", (lua_Integer)dragonBones::BinaryOffset::DeformCount);
    oluacls_enum(L, "DeformFloatOffset", (lua_Integer)dragonBones::BinaryOffset::DeformFloatOffset);
    oluacls_enum(L, "DeformValueCount", (lua_Integer)dragonBones::BinaryOffset::DeformValueCount);
    oluacls_enum(L, "DeformValueOffset", (lua_Integer)dragonBones::BinaryOffset::DeformValueOffset);
    oluacls_enum(L, "DeformVertexOffset", (lua_Integer)dragonBones::BinaryOffset::DeformVertexOffset);
    oluacls_enum(L, "FrameCurveSamples", (lua_Integer)dragonBones::BinaryOffset::FrameCurveSamples);
    oluacls_enum(L, "FramePosition", (lua_Integer)dragonBones::BinaryOffset::FramePosition);
    oluacls_enum(L, "FrameTweenEasingOrCurveSampleCount", (lua_Integer)dragonBones::BinaryOffset::FrameTweenEasingOrCurveSampleCount);
    oluacls_enum(L, "FrameTweenType", (lua_Integer)dragonBones::BinaryOffset::FrameTweenType);
    oluacls_enum(L, "MeshFloatOffset", (lua_Integer)dragonBones::BinaryOffset::MeshFloatOffset);
    oluacls_enum(L, "MeshTriangleCount", (lua_Integer)dragonBones::BinaryOffset::MeshTriangleCount);
    oluacls_enum(L, "MeshVertexCount", (lua_Integer)dragonBones::BinaryOffset::MeshVertexCount);
    oluacls_enum(L, "MeshVertexIndices", (lua_Integer)dragonBones::BinaryOffset::MeshVertexIndices);
    oluacls_enum(L, "MeshWeightOffset", (lua_Integer)dragonBones::BinaryOffset::MeshWeightOffset);
    oluacls_enum(L, "TimelineFrameOffset", (lua_Integer)dragonBones::BinaryOffset::TimelineFrameOffset);
    oluacls_enum(L, "TimelineFrameValueCount", (lua_Integer)dragonBones::BinaryOffset::TimelineFrameValueCount);
    oluacls_enum(L, "TimelineFrameValueOffset", (lua_Integer)dragonBones::BinaryOffset::TimelineFrameValueOffset);
    oluacls_enum(L, "TimelineKeyFrameCount", (lua_Integer)dragonBones::BinaryOffset::TimelineKeyFrameCount);
    oluacls_enum(L, "TimelineOffset", (lua_Integer)dragonBones::BinaryOffset::TimelineOffset);
    oluacls_enum(L, "TimelineScale", (lua_Integer)dragonBones::BinaryOffset::TimelineScale);
    oluacls_enum(L, "WeigthBoneCount", (lua_Integer)dragonBones::BinaryOffset::WeigthBoneCount);
    oluacls_enum(L, "WeigthBoneIndices", (lua_Integer)dragonBones::BinaryOffset::WeigthBoneIndices);
    oluacls_enum(L, "WeigthFloatOffset", (lua_Integer)dragonBones::BinaryOffset::WeigthFloatOffset);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_BinaryOffset(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.BinaryOffset")) {
        luaL_error(L, "class not found: dragonBones::BinaryOffset");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_db_ArmatureType(lua_State *L)
{
    oluacls_class<dragonBones::ArmatureType>(L, "db.ArmatureType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Armature", (lua_Integer)dragonBones::ArmatureType::Armature);
    oluacls_enum(L, "MovieClip", (lua_Integer)dragonBones::ArmatureType::MovieClip);
    oluacls_enum(L, "Stage", (lua_Integer)dragonBones::ArmatureType::Stage);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_ArmatureType(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.ArmatureType")) {
        luaL_error(L, "class not found: dragonBones::ArmatureType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_db_OffsetMode(lua_State *L)
{
    oluacls_class<dragonBones::OffsetMode>(L, "db.OffsetMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Additive", (lua_Integer)dragonBones::OffsetMode::Additive);
    oluacls_enum(L, "None", (lua_Integer)dragonBones::OffsetMode::None);
    oluacls_enum(L, "Override", (lua_Integer)dragonBones::OffsetMode::Override);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_OffsetMode(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.OffsetMode")) {
        luaL_error(L, "class not found: dragonBones::OffsetMode");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_db_DisplayType(lua_State *L)
{
    oluacls_class<dragonBones::DisplayType>(L, "db.DisplayType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Armature", (lua_Integer)dragonBones::DisplayType::Armature);
    oluacls_enum(L, "BoundingBox", (lua_Integer)dragonBones::DisplayType::BoundingBox);
    oluacls_enum(L, "Image", (lua_Integer)dragonBones::DisplayType::Image);
    oluacls_enum(L, "Mesh", (lua_Integer)dragonBones::DisplayType::Mesh);
    oluacls_enum(L, "Path", (lua_Integer)dragonBones::DisplayType::Path);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_DisplayType(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.DisplayType")) {
        luaL_error(L, "class not found: dragonBones::DisplayType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_db_BoundingBoxType(lua_State *L)
{
    oluacls_class<dragonBones::BoundingBoxType>(L, "db.BoundingBoxType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Ellipse", (lua_Integer)dragonBones::BoundingBoxType::Ellipse);
    oluacls_enum(L, "Polygon", (lua_Integer)dragonBones::BoundingBoxType::Polygon);
    oluacls_enum(L, "Rectangle", (lua_Integer)dragonBones::BoundingBoxType::Rectangle);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_BoundingBoxType(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.BoundingBoxType")) {
        luaL_error(L, "class not found: dragonBones::BoundingBoxType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_db_ActionType(lua_State *L)
{
    oluacls_class<dragonBones::ActionType>(L, "db.ActionType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Frame", (lua_Integer)dragonBones::ActionType::Frame);
    oluacls_enum(L, "Play", (lua_Integer)dragonBones::ActionType::Play);
    oluacls_enum(L, "Sound", (lua_Integer)dragonBones::ActionType::Sound);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_ActionType(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.ActionType")) {
        luaL_error(L, "class not found: dragonBones::ActionType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_db_BlendMode(lua_State *L)
{
    oluacls_class<dragonBones::BlendMode>(L, "db.BlendMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Add", (lua_Integer)dragonBones::BlendMode::Add);
    oluacls_enum(L, "Alpha", (lua_Integer)dragonBones::BlendMode::Alpha);
    oluacls_enum(L, "Darken", (lua_Integer)dragonBones::BlendMode::Darken);
    oluacls_enum(L, "Difference", (lua_Integer)dragonBones::BlendMode::Difference);
    oluacls_enum(L, "Erase", (lua_Integer)dragonBones::BlendMode::Erase);
    oluacls_enum(L, "HardLight", (lua_Integer)dragonBones::BlendMode::HardLight);
    oluacls_enum(L, "Invert", (lua_Integer)dragonBones::BlendMode::Invert);
    oluacls_enum(L, "Layer", (lua_Integer)dragonBones::BlendMode::Layer);
    oluacls_enum(L, "Lighten", (lua_Integer)dragonBones::BlendMode::Lighten);
    oluacls_enum(L, "Multiply", (lua_Integer)dragonBones::BlendMode::Multiply);
    oluacls_enum(L, "Normal", (lua_Integer)dragonBones::BlendMode::Normal);
    oluacls_enum(L, "Overlay", (lua_Integer)dragonBones::BlendMode::Overlay);
    oluacls_enum(L, "Screen", (lua_Integer)dragonBones::BlendMode::Screen);
    oluacls_enum(L, "Subtract", (lua_Integer)dragonBones::BlendMode::Subtract);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_BlendMode(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.BlendMode")) {
        luaL_error(L, "class not found: dragonBones::BlendMode");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_db_TweenType(lua_State *L)
{
    oluacls_class<dragonBones::TweenType>(L, "db.TweenType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Curve", (lua_Integer)dragonBones::TweenType::Curve);
    oluacls_enum(L, "Line", (lua_Integer)dragonBones::TweenType::Line);
    oluacls_enum(L, "None", (lua_Integer)dragonBones::TweenType::None);
    oluacls_enum(L, "QuadIn", (lua_Integer)dragonBones::TweenType::QuadIn);
    oluacls_enum(L, "QuadInOut", (lua_Integer)dragonBones::TweenType::QuadInOut);
    oluacls_enum(L, "QuadOut", (lua_Integer)dragonBones::TweenType::QuadOut);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_TweenType(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.TweenType")) {
        luaL_error(L, "class not found: dragonBones::TweenType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_db_TimelineType(lua_State *L)
{
    oluacls_class<dragonBones::TimelineType>(L, "db.TimelineType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Action", (lua_Integer)dragonBones::TimelineType::Action);
    oluacls_enum(L, "AnimationTime", (lua_Integer)dragonBones::TimelineType::AnimationTime);
    oluacls_enum(L, "AnimationWeight", (lua_Integer)dragonBones::TimelineType::AnimationWeight);
    oluacls_enum(L, "BoneAll", (lua_Integer)dragonBones::TimelineType::BoneAll);
    oluacls_enum(L, "BoneRotate", (lua_Integer)dragonBones::TimelineType::BoneRotate);
    oluacls_enum(L, "BoneScale", (lua_Integer)dragonBones::TimelineType::BoneScale);
    oluacls_enum(L, "BoneTranslate", (lua_Integer)dragonBones::TimelineType::BoneTranslate);
    oluacls_enum(L, "IKConstraint", (lua_Integer)dragonBones::TimelineType::IKConstraint);
    oluacls_enum(L, "SlotColor", (lua_Integer)dragonBones::TimelineType::SlotColor);
    oluacls_enum(L, "SlotDeform", (lua_Integer)dragonBones::TimelineType::SlotDeform);
    oluacls_enum(L, "SlotDisplay", (lua_Integer)dragonBones::TimelineType::SlotDisplay);
    oluacls_enum(L, "ZOrder", (lua_Integer)dragonBones::TimelineType::ZOrder);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_TimelineType(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.TimelineType")) {
        luaL_error(L, "class not found: dragonBones::TimelineType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_db_AnimationFadeOutMode(lua_State *L)
{
    oluacls_class<dragonBones::AnimationFadeOutMode>(L, "db.AnimationFadeOutMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "All", (lua_Integer)dragonBones::AnimationFadeOutMode::All);
    oluacls_enum(L, "None", (lua_Integer)dragonBones::AnimationFadeOutMode::None);
    oluacls_enum(L, "SameGroup", (lua_Integer)dragonBones::AnimationFadeOutMode::SameGroup);
    oluacls_enum(L, "SameLayer", (lua_Integer)dragonBones::AnimationFadeOutMode::SameLayer);
    oluacls_enum(L, "SameLayerAndGroup", (lua_Integer)dragonBones::AnimationFadeOutMode::SameLayerAndGroup);
    oluacls_enum(L, "Single", (lua_Integer)dragonBones::AnimationFadeOutMode::Single);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_AnimationFadeOutMode(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.AnimationFadeOutMode")) {
        luaL_error(L, "class not found: dragonBones::AnimationFadeOutMode");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_db_TextureFormat(lua_State *L)
{
    oluacls_class<dragonBones::TextureFormat>(L, "db.TextureFormat");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BGRA8888", (lua_Integer)dragonBones::TextureFormat::BGRA8888);
    oluacls_enum(L, "DEFAULT", (lua_Integer)dragonBones::TextureFormat::DEFAULT);
    oluacls_enum(L, "RGB565", (lua_Integer)dragonBones::TextureFormat::RGB565);
    oluacls_enum(L, "RGB888", (lua_Integer)dragonBones::TextureFormat::RGB888);
    oluacls_enum(L, "RGBA4444", (lua_Integer)dragonBones::TextureFormat::RGBA4444);
    oluacls_enum(L, "RGBA5551", (lua_Integer)dragonBones::TextureFormat::RGBA5551);
    oluacls_enum(L, "RGBA8888", (lua_Integer)dragonBones::TextureFormat::RGBA8888);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_TextureFormat(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.TextureFormat")) {
        luaL_error(L, "class not found: dragonBones::TextureFormat");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_DragonBones___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::DragonBones *)olua_toobj(L, 1, "db.DragonBones");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBones_advanceTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBones *self = nullptr;
    float arg1 = 0;       /** passedTime */

    olua_to_object(L, 1, &self, "db.DragonBones");
    olua_check_number(L, 2, &arg1);

    // void advanceTime(float passedTime)
    self->advanceTime(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBones_bufferEvent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBones *self = nullptr;
    dragonBones::EventObject *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.DragonBones");
    olua_check_object(L, 2, &arg1, "db.EventObject");

    // void bufferEvent(dragonBones::EventObject *value)
    self->bufferEvent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBones_bufferObject(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBones *self = nullptr;
    dragonBones::BaseObject *arg1 = nullptr;       /** object */

    olua_to_object(L, 1, &self, "db.DragonBones");
    olua_check_object(L, 2, &arg1, "db.BaseObject");

    // void bufferObject(dragonBones::BaseObject *object)
    self->bufferObject(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBones_debug$1(lua_State *L)
{
    olua_startinvoke(L);

    // static bool debug
    bool ret = dragonBones::DragonBones::debug;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBones_debug$2(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** debug */

    olua_check_bool(L, 1, &arg1);

    // static bool debug
    dragonBones::DragonBones::debug = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBones_debug(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static bool debug
        return _olua_fun_dragonBones_DragonBones_debug$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 1))) {
            // static bool debug
            return _olua_fun_dragonBones_DragonBones_debug$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBones::debug' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBones_debugDraw$1(lua_State *L)
{
    olua_startinvoke(L);

    // static bool debugDraw
    bool ret = dragonBones::DragonBones::debugDraw;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBones_debugDraw$2(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** debugDraw */

    olua_check_bool(L, 1, &arg1);

    // static bool debugDraw
    dragonBones::DragonBones::debugDraw = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBones_debugDraw(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static bool debugDraw
        return _olua_fun_dragonBones_DragonBones_debugDraw$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 1))) {
            // static bool debugDraw
            return _olua_fun_dragonBones_DragonBones_debugDraw$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBones::debugDraw' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBones_getClock(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBones *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBones");

    // dragonBones::WorldClock *getClock()
    dragonBones::WorldClock *ret = self->getClock();
    int num_ret = olua_push_object(L, ret, "db.WorldClock");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBones_getEventManager(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBones *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBones");

    // dragonBones::IEventDispatcher *getEventManager()
    dragonBones::IEventDispatcher *ret = self->getEventManager();
    int num_ret = olua_push_object(L, ret, "db.IEventDispatcher");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBones_new(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IEventDispatcher *arg1 = nullptr;       /** eventManager */

    olua_check_object(L, 1, &arg1, "db.IEventDispatcher");

    // dragonBones::DragonBones(dragonBones::IEventDispatcher *eventManager)
    dragonBones::DragonBones *ret = new dragonBones::DragonBones(arg1);
    int num_ret = olua_push_object(L, ret, "db.DragonBones");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBones_webAssembly$1(lua_State *L)
{
    olua_startinvoke(L);

    // static bool webAssembly
    bool ret = dragonBones::DragonBones::webAssembly;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBones_webAssembly$2(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** webAssembly */

    olua_check_bool(L, 1, &arg1);

    // static bool webAssembly
    dragonBones::DragonBones::webAssembly = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBones_webAssembly(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static bool webAssembly
        return _olua_fun_dragonBones_DragonBones_webAssembly$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 1))) {
            // static bool webAssembly
            return _olua_fun_dragonBones_DragonBones_webAssembly$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBones::webAssembly' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBones_yDown$1(lua_State *L)
{
    olua_startinvoke(L);

    // static bool yDown
    bool ret = dragonBones::DragonBones::yDown;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBones_yDown$2(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** yDown */

    olua_check_bool(L, 1, &arg1);

    // static bool yDown
    dragonBones::DragonBones::yDown = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBones_yDown(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static bool yDown
        return _olua_fun_dragonBones_DragonBones_yDown$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 1))) {
            // static bool yDown
            return _olua_fun_dragonBones_DragonBones_yDown$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBones::yDown' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_DragonBones(lua_State *L)
{
    oluacls_class<dragonBones::DragonBones>(L, "db.DragonBones");
    oluacls_func(L, "__gc", _olua_fun_dragonBones_DragonBones___gc);
    oluacls_func(L, "advanceTime", _olua_fun_dragonBones_DragonBones_advanceTime);
    oluacls_func(L, "bufferEvent", _olua_fun_dragonBones_DragonBones_bufferEvent);
    oluacls_func(L, "bufferObject", _olua_fun_dragonBones_DragonBones_bufferObject);
    oluacls_func(L, "getClock", _olua_fun_dragonBones_DragonBones_getClock);
    oluacls_func(L, "getEventManager", _olua_fun_dragonBones_DragonBones_getEventManager);
    oluacls_func(L, "new", _olua_fun_dragonBones_DragonBones_new);
    oluacls_prop(L, "clock", _olua_fun_dragonBones_DragonBones_getClock, nullptr);
    oluacls_prop(L, "eventManager", _olua_fun_dragonBones_DragonBones_getEventManager, nullptr);
    oluacls_prop(L, "yDown", _olua_fun_dragonBones_DragonBones_yDown, _olua_fun_dragonBones_DragonBones_yDown);
    oluacls_prop(L, "debug", _olua_fun_dragonBones_DragonBones_debug, _olua_fun_dragonBones_DragonBones_debug);
    oluacls_prop(L, "debugDraw", _olua_fun_dragonBones_DragonBones_debugDraw, _olua_fun_dragonBones_DragonBones_debugDraw);
    oluacls_prop(L, "webAssembly", _olua_fun_dragonBones_DragonBones_webAssembly, _olua_fun_dragonBones_DragonBones_webAssembly);
    oluacls_const(L, "VEISION", dragonBones::DragonBones::VEISION);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_DragonBones(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.DragonBones")) {
        luaL_error(L, "class not found: dragonBones::DragonBones");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_BaseObject___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::BaseObject *)olua_toobj(L, 1, "db.BaseObject");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseObject_clearPool$1(lua_State *L)
{
    olua_startinvoke(L);

    std::size_t arg1 = 0;       /** classTypeIndex */

    olua_check_integer(L, 1, &arg1);

    // static void clearPool(@optional std::size_t classTypeIndex)
    dragonBones::BaseObject::clearPool(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseObject_clearPool$2(lua_State *L)
{
    olua_startinvoke(L);

    // static void clearPool()
    dragonBones::BaseObject::clearPool();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseObject_clearPool(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static void clearPool()
        return _olua_fun_dragonBones_BaseObject_clearPool$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // static void clearPool(@optional std::size_t classTypeIndex)
            return _olua_fun_dragonBones_BaseObject_clearPool$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseObject::clearPool' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseObject_getClassTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.BaseObject");

    // std::size_t getClassTypeIndex()
    std::size_t ret = self->getClassTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseObject_hashCode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.BaseObject");

    // @readonly const unsigned int hashCode
    const unsigned int ret = self->hashCode;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseObject_returnToPool(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.BaseObject");

    // void returnToPool()
    self->returnToPool();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseObject_setMaxCount(lua_State *L)
{
    olua_startinvoke(L);

    std::size_t arg1 = 0;       /** classTypeIndex */
    unsigned int arg2 = 0;       /** maxCount */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);

    // static void setMaxCount(std::size_t classTypeIndex, unsigned int maxCount)
    dragonBones::BaseObject::setMaxCount(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_db_BaseObject(lua_State *L)
{
    oluacls_class<dragonBones::BaseObject>(L, "db.BaseObject");
    oluacls_func(L, "__gc", _olua_fun_dragonBones_BaseObject___gc);
    oluacls_func(L, "clearPool", _olua_fun_dragonBones_BaseObject_clearPool);
    oluacls_func(L, "getClassTypeIndex", _olua_fun_dragonBones_BaseObject_getClassTypeIndex);
    oluacls_func(L, "returnToPool", _olua_fun_dragonBones_BaseObject_returnToPool);
    oluacls_func(L, "setMaxCount", _olua_fun_dragonBones_BaseObject_setMaxCount);
    oluacls_prop(L, "classTypeIndex", _olua_fun_dragonBones_BaseObject_getClassTypeIndex, nullptr);
    oluacls_prop(L, "hashCode", _olua_fun_dragonBones_BaseObject_hashCode, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_BaseObject(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.BaseObject")) {
        luaL_error(L, "class not found: dragonBones::BaseObject");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_EventObject_COMPLETE$1(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *COMPLETE
    const char *ret = dragonBones::EventObject::COMPLETE;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_COMPLETE$2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** COMPLETE */

    olua_check_string(L, 1, &arg1);

    // static const char *COMPLETE
    dragonBones::EventObject::COMPLETE = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_COMPLETE(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static const char *COMPLETE
        return _olua_fun_dragonBones_EventObject_COMPLETE$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static const char *COMPLETE
            return _olua_fun_dragonBones_EventObject_COMPLETE$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::COMPLETE' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_FADE_IN$1(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *FADE_IN
    const char *ret = dragonBones::EventObject::FADE_IN;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_FADE_IN$2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** FADE_IN */

    olua_check_string(L, 1, &arg1);

    // static const char *FADE_IN
    dragonBones::EventObject::FADE_IN = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_FADE_IN(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static const char *FADE_IN
        return _olua_fun_dragonBones_EventObject_FADE_IN$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static const char *FADE_IN
            return _olua_fun_dragonBones_EventObject_FADE_IN$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::FADE_IN' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_FADE_IN_COMPLETE$1(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *FADE_IN_COMPLETE
    const char *ret = dragonBones::EventObject::FADE_IN_COMPLETE;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_FADE_IN_COMPLETE$2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** FADE_IN_COMPLETE */

    olua_check_string(L, 1, &arg1);

    // static const char *FADE_IN_COMPLETE
    dragonBones::EventObject::FADE_IN_COMPLETE = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_FADE_IN_COMPLETE(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static const char *FADE_IN_COMPLETE
        return _olua_fun_dragonBones_EventObject_FADE_IN_COMPLETE$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static const char *FADE_IN_COMPLETE
            return _olua_fun_dragonBones_EventObject_FADE_IN_COMPLETE$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::FADE_IN_COMPLETE' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_FADE_OUT$1(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *FADE_OUT
    const char *ret = dragonBones::EventObject::FADE_OUT;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_FADE_OUT$2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** FADE_OUT */

    olua_check_string(L, 1, &arg1);

    // static const char *FADE_OUT
    dragonBones::EventObject::FADE_OUT = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_FADE_OUT(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static const char *FADE_OUT
        return _olua_fun_dragonBones_EventObject_FADE_OUT$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static const char *FADE_OUT
            return _olua_fun_dragonBones_EventObject_FADE_OUT$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::FADE_OUT' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_FADE_OUT_COMPLETE$1(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *FADE_OUT_COMPLETE
    const char *ret = dragonBones::EventObject::FADE_OUT_COMPLETE;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_FADE_OUT_COMPLETE$2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** FADE_OUT_COMPLETE */

    olua_check_string(L, 1, &arg1);

    // static const char *FADE_OUT_COMPLETE
    dragonBones::EventObject::FADE_OUT_COMPLETE = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_FADE_OUT_COMPLETE(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static const char *FADE_OUT_COMPLETE
        return _olua_fun_dragonBones_EventObject_FADE_OUT_COMPLETE$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static const char *FADE_OUT_COMPLETE
            return _olua_fun_dragonBones_EventObject_FADE_OUT_COMPLETE$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::FADE_OUT_COMPLETE' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_FRAME_EVENT$1(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *FRAME_EVENT
    const char *ret = dragonBones::EventObject::FRAME_EVENT;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_FRAME_EVENT$2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** FRAME_EVENT */

    olua_check_string(L, 1, &arg1);

    // static const char *FRAME_EVENT
    dragonBones::EventObject::FRAME_EVENT = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_FRAME_EVENT(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static const char *FRAME_EVENT
        return _olua_fun_dragonBones_EventObject_FRAME_EVENT$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static const char *FRAME_EVENT
            return _olua_fun_dragonBones_EventObject_FRAME_EVENT$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::FRAME_EVENT' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_LOOP_COMPLETE$1(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *LOOP_COMPLETE
    const char *ret = dragonBones::EventObject::LOOP_COMPLETE;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_LOOP_COMPLETE$2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** LOOP_COMPLETE */

    olua_check_string(L, 1, &arg1);

    // static const char *LOOP_COMPLETE
    dragonBones::EventObject::LOOP_COMPLETE = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_LOOP_COMPLETE(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static const char *LOOP_COMPLETE
        return _olua_fun_dragonBones_EventObject_LOOP_COMPLETE$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static const char *LOOP_COMPLETE
            return _olua_fun_dragonBones_EventObject_LOOP_COMPLETE$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::LOOP_COMPLETE' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_SOUND_EVENT$1(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *SOUND_EVENT
    const char *ret = dragonBones::EventObject::SOUND_EVENT;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_SOUND_EVENT$2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** SOUND_EVENT */

    olua_check_string(L, 1, &arg1);

    // static const char *SOUND_EVENT
    dragonBones::EventObject::SOUND_EVENT = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_SOUND_EVENT(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static const char *SOUND_EVENT
        return _olua_fun_dragonBones_EventObject_SOUND_EVENT$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static const char *SOUND_EVENT
            return _olua_fun_dragonBones_EventObject_SOUND_EVENT$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::SOUND_EVENT' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_START$1(lua_State *L)
{
    olua_startinvoke(L);

    // static const char *START
    const char *ret = dragonBones::EventObject::START;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_START$2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** START */

    olua_check_string(L, 1, &arg1);

    // static const char *START
    dragonBones::EventObject::START = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_START(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static const char *START
        return _olua_fun_dragonBones_EventObject_START$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static const char *START
            return _olua_fun_dragonBones_EventObject_START$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::START' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_actionData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // const dragonBones::ActionData *actionData
    const dragonBones::ActionData *ret = self->actionData;
    int num_ret = olua_push_object(L, ret, "db.ActionData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_actionData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::ActionData *arg1 = nullptr;       /** actionData */

    olua_to_object(L, 1, &self, "db.EventObject");
    olua_check_object(L, 2, &arg1, "db.ActionData");

    // const dragonBones::ActionData *actionData
    self->actionData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_actionData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const dragonBones::ActionData *actionData
        return _olua_fun_dragonBones_EventObject_actionData$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.EventObject")) && (olua_is_object(L, 2, "db.ActionData"))) {
            // const dragonBones::ActionData *actionData
            return _olua_fun_dragonBones_EventObject_actionData$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::actionData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_actionDataToInstance(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *arg1 = nullptr;       /** data */
    dragonBones::EventObject *arg2 = nullptr;       /** instance */
    dragonBones::Armature *arg3 = nullptr;       /** armature */

    olua_check_object(L, 1, &arg1, "db.ActionData");
    olua_check_object(L, 2, &arg2, "db.EventObject");
    olua_check_object(L, 3, &arg3, "db.Armature");

    // static void actionDataToInstance(const dragonBones::ActionData *data, dragonBones::EventObject *instance, dragonBones::Armature *armature)
    dragonBones::EventObject::actionDataToInstance(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_animationState$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // dragonBones::AnimationState *animationState
    dragonBones::AnimationState *ret = self->animationState;
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_animationState$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::AnimationState *arg1 = nullptr;       /** animationState */

    olua_to_object(L, 1, &self, "db.EventObject");
    olua_check_object(L, 2, &arg1, "db.AnimationState");

    // dragonBones::AnimationState *animationState
    self->animationState = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_animationState(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::AnimationState *animationState
        return _olua_fun_dragonBones_EventObject_animationState$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.EventObject")) && (olua_is_object(L, 2, "db.AnimationState"))) {
            // dragonBones::AnimationState *animationState
            return _olua_fun_dragonBones_EventObject_animationState$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::animationState' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_armature$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // dragonBones::Armature *armature
    dragonBones::Armature *ret = self->armature;
    int num_ret = olua_push_object(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_armature$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */

    olua_to_object(L, 1, &self, "db.EventObject");
    olua_check_object(L, 2, &arg1, "db.Armature");

    // dragonBones::Armature *armature
    self->armature = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_armature(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::Armature *armature
        return _olua_fun_dragonBones_EventObject_armature$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.EventObject")) && (olua_is_object(L, 2, "db.Armature"))) {
            // dragonBones::Armature *armature
            return _olua_fun_dragonBones_EventObject_armature$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::armature' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_bone$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // dragonBones::Bone *bone
    dragonBones::Bone *ret = self->bone;
    int num_ret = olua_push_object(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_bone$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::Bone *arg1 = nullptr;       /** bone */

    olua_to_object(L, 1, &self, "db.EventObject");
    olua_check_object(L, 2, &arg1, "db.Bone");

    // dragonBones::Bone *bone
    self->bone = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_bone(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::Bone *bone
        return _olua_fun_dragonBones_EventObject_bone$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.EventObject")) && (olua_is_object(L, 2, "db.Bone"))) {
            // dragonBones::Bone *bone
            return _olua_fun_dragonBones_EventObject_bone$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::bone' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_data$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // dragonBones::UserData *data
    dragonBones::UserData *ret = self->data;
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_data$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "db.EventObject");
    olua_check_object(L, 2, &arg1, "db.UserData");

    // dragonBones::UserData *data
    self->data = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_data(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::UserData *data
        return _olua_fun_dragonBones_EventObject_data$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.EventObject")) && (olua_is_object(L, 2, "db.UserData"))) {
            // dragonBones::UserData *data
            return _olua_fun_dragonBones_EventObject_data$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::data' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_getAnimationState(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // dragonBones::AnimationState *getAnimationState()
    dragonBones::AnimationState *ret = self->getAnimationState();
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_getArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // dragonBones::Armature *getArmature()
    dragonBones::Armature *ret = self->getArmature();
    int num_ret = olua_push_object(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_getBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // dragonBones::Bone *getBone()
    dragonBones::Bone *ret = self->getBone();
    int num_ret = olua_push_object(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_getData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // dragonBones::UserData *getData()
    dragonBones::UserData *ret = self->getData();
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_getSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // dragonBones::Slot *getSlot()
    dragonBones::Slot *ret = self->getSlot();
    int num_ret = olua_push_object(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::EventObject::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.EventObject");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_EventObject_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.EventObject")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_EventObject_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::EventObject()
    dragonBones::EventObject *ret = new dragonBones::EventObject();
    int num_ret = olua_push_object(L, ret, "db.EventObject");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_slot$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // dragonBones::Slot *slot
    dragonBones::Slot *ret = self->slot;
    int num_ret = olua_push_object(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_slot$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    dragonBones::Slot *arg1 = nullptr;       /** slot */

    olua_to_object(L, 1, &self, "db.EventObject");
    olua_check_object(L, 2, &arg1, "db.Slot");

    // dragonBones::Slot *slot
    self->slot = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_slot(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::Slot *slot
        return _olua_fun_dragonBones_EventObject_slot$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.EventObject")) && (olua_is_object(L, 2, "db.Slot"))) {
            // dragonBones::Slot *slot
            return _olua_fun_dragonBones_EventObject_slot$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::slot' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_time$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // float time
    float ret = self->time;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_time$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    float arg1 = 0;       /** time */

    olua_to_object(L, 1, &self, "db.EventObject");
    olua_check_number(L, 2, &arg1);

    // float time
    self->time = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_time(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float time
        return _olua_fun_dragonBones_EventObject_time$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.EventObject")) && (olua_is_number(L, 2))) {
            // float time
            return _olua_fun_dragonBones_EventObject_time$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::time' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_type$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.EventObject");

    // std::string type
    std::string ret = self->type;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_EventObject_type$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::EventObject *self = nullptr;
    std::string arg1;       /** type */

    olua_to_object(L, 1, &self, "db.EventObject");
    olua_check_string(L, 2, &arg1);

    // std::string type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_EventObject_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string type
        return _olua_fun_dragonBones_EventObject_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.EventObject")) && (olua_is_string(L, 2))) {
            // std::string type
            return _olua_fun_dragonBones_EventObject_type$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::EventObject::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_EventObject(lua_State *L)
{
    oluacls_class<dragonBones::EventObject, dragonBones::BaseObject>(L, "db.EventObject");
    oluacls_func(L, "actionDataToInstance", _olua_fun_dragonBones_EventObject_actionDataToInstance);
    oluacls_func(L, "getAnimationState", _olua_fun_dragonBones_EventObject_getAnimationState);
    oluacls_func(L, "getArmature", _olua_fun_dragonBones_EventObject_getArmature);
    oluacls_func(L, "getBone", _olua_fun_dragonBones_EventObject_getBone);
    oluacls_func(L, "getData", _olua_fun_dragonBones_EventObject_getData);
    oluacls_func(L, "getSlot", _olua_fun_dragonBones_EventObject_getSlot);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_EventObject_getTypeIndex);
    oluacls_func(L, "new", _olua_fun_dragonBones_EventObject_new);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_EventObject_getTypeIndex, nullptr);
    oluacls_prop(L, "START", _olua_fun_dragonBones_EventObject_START, _olua_fun_dragonBones_EventObject_START);
    oluacls_prop(L, "LOOP_COMPLETE", _olua_fun_dragonBones_EventObject_LOOP_COMPLETE, _olua_fun_dragonBones_EventObject_LOOP_COMPLETE);
    oluacls_prop(L, "COMPLETE", _olua_fun_dragonBones_EventObject_COMPLETE, _olua_fun_dragonBones_EventObject_COMPLETE);
    oluacls_prop(L, "FADE_IN", _olua_fun_dragonBones_EventObject_FADE_IN, _olua_fun_dragonBones_EventObject_FADE_IN);
    oluacls_prop(L, "FADE_IN_COMPLETE", _olua_fun_dragonBones_EventObject_FADE_IN_COMPLETE, _olua_fun_dragonBones_EventObject_FADE_IN_COMPLETE);
    oluacls_prop(L, "FADE_OUT", _olua_fun_dragonBones_EventObject_FADE_OUT, _olua_fun_dragonBones_EventObject_FADE_OUT);
    oluacls_prop(L, "FADE_OUT_COMPLETE", _olua_fun_dragonBones_EventObject_FADE_OUT_COMPLETE, _olua_fun_dragonBones_EventObject_FADE_OUT_COMPLETE);
    oluacls_prop(L, "FRAME_EVENT", _olua_fun_dragonBones_EventObject_FRAME_EVENT, _olua_fun_dragonBones_EventObject_FRAME_EVENT);
    oluacls_prop(L, "SOUND_EVENT", _olua_fun_dragonBones_EventObject_SOUND_EVENT, _olua_fun_dragonBones_EventObject_SOUND_EVENT);
    oluacls_prop(L, "time", _olua_fun_dragonBones_EventObject_time, _olua_fun_dragonBones_EventObject_time);
    oluacls_prop(L, "type", _olua_fun_dragonBones_EventObject_type, _olua_fun_dragonBones_EventObject_type);
    oluacls_prop(L, "name", _olua_fun_dragonBones_EventObject_name, _olua_fun_dragonBones_EventObject_name);
    oluacls_prop(L, "armature", _olua_fun_dragonBones_EventObject_armature, _olua_fun_dragonBones_EventObject_armature);
    oluacls_prop(L, "bone", _olua_fun_dragonBones_EventObject_bone, _olua_fun_dragonBones_EventObject_bone);
    oluacls_prop(L, "slot", _olua_fun_dragonBones_EventObject_slot, _olua_fun_dragonBones_EventObject_slot);
    oluacls_prop(L, "animationState", _olua_fun_dragonBones_EventObject_animationState, _olua_fun_dragonBones_EventObject_animationState);
    oluacls_prop(L, "actionData", _olua_fun_dragonBones_EventObject_actionData, _olua_fun_dragonBones_EventObject_actionData);
    oluacls_prop(L, "data", _olua_fun_dragonBones_EventObject_data, _olua_fun_dragonBones_EventObject_data);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_EventObject(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.EventObject")) {
        luaL_error(L, "class not found: dragonBones::EventObject");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_TransformObject_getArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TransformObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.TransformObject");

    // dragonBones::Armature *getArmature()
    dragonBones::Armature *ret = self->getArmature();
    int num_ret = olua_push_object(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TransformObject_updateGlobalTransform(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TransformObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.TransformObject");

    // void updateGlobalTransform()
    self->updateGlobalTransform();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TransformObject_userData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TransformObject *self = nullptr;

    olua_to_object(L, 1, &self, "db.TransformObject");

    // void *userData
    void *ret = self->userData;
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TransformObject_userData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TransformObject *self = nullptr;
    void *arg1 = nullptr;       /** userData */

    olua_to_object(L, 1, &self, "db.TransformObject");
    olua_check_object(L, 2, &arg1, "void *");

    // void *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TransformObject_userData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // void *userData
        return _olua_fun_dragonBones_TransformObject_userData$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TransformObject")) && (olua_is_object(L, 2, "void *"))) {
            // void *userData
            return _olua_fun_dragonBones_TransformObject_userData$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TransformObject::userData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_TransformObject(lua_State *L)
{
    oluacls_class<dragonBones::TransformObject, dragonBones::BaseObject>(L, "db.TransformObject");
    oluacls_func(L, "getArmature", _olua_fun_dragonBones_TransformObject_getArmature);
    oluacls_func(L, "updateGlobalTransform", _olua_fun_dragonBones_TransformObject_updateGlobalTransform);
    oluacls_prop(L, "armature", _olua_fun_dragonBones_TransformObject_getArmature, nullptr);
    oluacls_prop(L, "userData", _olua_fun_dragonBones_TransformObject_userData, _olua_fun_dragonBones_TransformObject_userData);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_TransformObject(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.TransformObject")) {
        luaL_error(L, "class not found: dragonBones::TransformObject");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_Point___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::Point *)olua_toobj(L, 1, "db.Point");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Point_clear(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *self = nullptr;

    olua_to_object(L, 1, &self, "db.Point");

    // void clear()
    self->clear();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Point_getHelpPointA(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point *getHelpPointA()
    dragonBones::Point *ret = dragonBones::Point::getHelpPointA();
    int num_ret = olua_push_object(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Point_getHelpPointB(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point *getHelpPointB()
    dragonBones::Point *ret = dragonBones::Point::getHelpPointB();
    int num_ret = olua_push_object(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Point_getHelpPointC(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point *getHelpPointC()
    dragonBones::Point *ret = dragonBones::Point::getHelpPointC();
    int num_ret = olua_push_object(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Point_getHelpPointD(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point *getHelpPointD()
    dragonBones::Point *ret = dragonBones::Point::getHelpPointD();
    int num_ret = olua_push_object(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Point_helpPointA$1(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point helpPointA
    dragonBones::Point &ret = dragonBones::Point::helpPointA;
    int num_ret = olua_copy_object(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Point_helpPointA$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *arg1;       /** helpPointA */

    olua_check_object(L, 1, &arg1, "db.Point");

    // static dragonBones::Point helpPointA
    dragonBones::Point::helpPointA = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Point_helpPointA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static dragonBones::Point helpPointA
        return _olua_fun_dragonBones_Point_helpPointA$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "db.Point"))) {
            // static dragonBones::Point helpPointA
            return _olua_fun_dragonBones_Point_helpPointA$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Point::helpPointA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Point_helpPointB$1(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point helpPointB
    dragonBones::Point &ret = dragonBones::Point::helpPointB;
    int num_ret = olua_copy_object(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Point_helpPointB$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *arg1;       /** helpPointB */

    olua_check_object(L, 1, &arg1, "db.Point");

    // static dragonBones::Point helpPointB
    dragonBones::Point::helpPointB = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Point_helpPointB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static dragonBones::Point helpPointB
        return _olua_fun_dragonBones_Point_helpPointB$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "db.Point"))) {
            // static dragonBones::Point helpPointB
            return _olua_fun_dragonBones_Point_helpPointB$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Point::helpPointB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Point_helpPointC$1(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point helpPointC
    dragonBones::Point &ret = dragonBones::Point::helpPointC;
    int num_ret = olua_copy_object(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Point_helpPointC$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *arg1;       /** helpPointC */

    olua_check_object(L, 1, &arg1, "db.Point");

    // static dragonBones::Point helpPointC
    dragonBones::Point::helpPointC = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Point_helpPointC(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static dragonBones::Point helpPointC
        return _olua_fun_dragonBones_Point_helpPointC$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "db.Point"))) {
            // static dragonBones::Point helpPointC
            return _olua_fun_dragonBones_Point_helpPointC$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Point::helpPointC' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Point_helpPointD$1(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Point helpPointD
    dragonBones::Point &ret = dragonBones::Point::helpPointD;
    int num_ret = olua_copy_object(L, ret, "db.Point");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Point_helpPointD$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *arg1;       /** helpPointD */

    olua_check_object(L, 1, &arg1, "db.Point");

    // static dragonBones::Point helpPointD
    dragonBones::Point::helpPointD = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Point_helpPointD(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static dragonBones::Point helpPointD
        return _olua_fun_dragonBones_Point_helpPointD$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "db.Point"))) {
            // static dragonBones::Point helpPointD
            return _olua_fun_dragonBones_Point_helpPointD$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Point::helpPointD' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Point_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::Point()
    dragonBones::Point *ret = new dragonBones::Point();
    int num_ret = olua_push_object(L, ret, "db.Point");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Point_x$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *self = nullptr;

    olua_to_object(L, 1, &self, "db.Point");

    // float x
    float ret = self->x;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Point_x$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *self = nullptr;
    float arg1 = 0;       /** x */

    olua_to_object(L, 1, &self, "db.Point");
    olua_check_number(L, 2, &arg1);

    // float x
    self->x = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Point_x(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float x
        return _olua_fun_dragonBones_Point_x$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Point")) && (olua_is_number(L, 2))) {
            // float x
            return _olua_fun_dragonBones_Point_x$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Point::x' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Point_y$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *self = nullptr;

    olua_to_object(L, 1, &self, "db.Point");

    // float y
    float ret = self->y;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Point_y$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Point *self = nullptr;
    float arg1 = 0;       /** y */

    olua_to_object(L, 1, &self, "db.Point");
    olua_check_number(L, 2, &arg1);

    // float y
    self->y = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Point_y(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float y
        return _olua_fun_dragonBones_Point_y$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Point")) && (olua_is_number(L, 2))) {
            // float y
            return _olua_fun_dragonBones_Point_y$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Point::y' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_Point(lua_State *L)
{
    oluacls_class<dragonBones::Point>(L, "db.Point");
    oluacls_func(L, "__gc", _olua_fun_dragonBones_Point___gc);
    oluacls_func(L, "clear", _olua_fun_dragonBones_Point_clear);
    oluacls_func(L, "getHelpPointA", _olua_fun_dragonBones_Point_getHelpPointA);
    oluacls_func(L, "getHelpPointB", _olua_fun_dragonBones_Point_getHelpPointB);
    oluacls_func(L, "getHelpPointC", _olua_fun_dragonBones_Point_getHelpPointC);
    oluacls_func(L, "getHelpPointD", _olua_fun_dragonBones_Point_getHelpPointD);
    oluacls_func(L, "new", _olua_fun_dragonBones_Point_new);
    oluacls_prop(L, "helpPointA", _olua_fun_dragonBones_Point_helpPointA, _olua_fun_dragonBones_Point_helpPointA);
    oluacls_prop(L, "helpPointB", _olua_fun_dragonBones_Point_helpPointB, _olua_fun_dragonBones_Point_helpPointB);
    oluacls_prop(L, "helpPointC", _olua_fun_dragonBones_Point_helpPointC, _olua_fun_dragonBones_Point_helpPointC);
    oluacls_prop(L, "helpPointD", _olua_fun_dragonBones_Point_helpPointD, _olua_fun_dragonBones_Point_helpPointD);
    oluacls_prop(L, "x", _olua_fun_dragonBones_Point_x, _olua_fun_dragonBones_Point_x);
    oluacls_prop(L, "y", _olua_fun_dragonBones_Point_y, _olua_fun_dragonBones_Point_y);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_Point(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.Point")) {
        luaL_error(L, "class not found: dragonBones::Point");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_ConstraintData_bone$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ConstraintData");

    // const dragonBones::BoneData *bone
    const dragonBones::BoneData *ret = self->bone;
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ConstraintData_bone$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** bone */

    olua_to_object(L, 1, &self, "db.ConstraintData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // const dragonBones::BoneData *bone
    self->bone = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_bone(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const dragonBones::BoneData *bone
        return _olua_fun_dragonBones_ConstraintData_bone$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ConstraintData")) && (olua_is_object(L, 2, "db.BoneData"))) {
            // const dragonBones::BoneData *bone
            return _olua_fun_dragonBones_ConstraintData_bone$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ConstraintData::bone' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_getBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ConstraintData");

    // const dragonBones::BoneData *getBone()
    const dragonBones::BoneData *ret = self->getBone();
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ConstraintData_getRoot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ConstraintData");

    // const dragonBones::BoneData *getRoot()
    const dragonBones::BoneData *ret = self->getRoot();
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ConstraintData_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ConstraintData");

    // const dragonBones::BoneData *getTarget()
    const dragonBones::BoneData *ret = self->getTarget();
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ConstraintData_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ConstraintData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ConstraintData_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.ConstraintData");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_ConstraintData_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ConstraintData")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_ConstraintData_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ConstraintData::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_order$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ConstraintData");

    // int order
    int ret = self->order;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ConstraintData_order$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    int arg1 = 0;       /** order */

    olua_to_object(L, 1, &self, "db.ConstraintData");
    olua_check_integer(L, 2, &arg1);

    // int order
    self->order = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_order(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int order
        return _olua_fun_dragonBones_ConstraintData_order$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ConstraintData")) && (olua_is_integer(L, 2))) {
            // int order
            return _olua_fun_dragonBones_ConstraintData_order$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ConstraintData::order' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_root$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ConstraintData");

    // const dragonBones::BoneData *root
    const dragonBones::BoneData *ret = self->root;
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ConstraintData_root$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** root */

    olua_to_object(L, 1, &self, "db.ConstraintData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // const dragonBones::BoneData *root
    self->root = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_root(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const dragonBones::BoneData *root
        return _olua_fun_dragonBones_ConstraintData_root$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ConstraintData")) && (olua_is_object(L, 2, "db.BoneData"))) {
            // const dragonBones::BoneData *root
            return _olua_fun_dragonBones_ConstraintData_root$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ConstraintData::root' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_setBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ConstraintData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // void setBone(const dragonBones::BoneData *value)
    self->setBone(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_setRoot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ConstraintData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // void setRoot(const dragonBones::BoneData *value)
    self->setRoot(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ConstraintData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // void setTarget(const dragonBones::BoneData *value)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_target$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ConstraintData");

    // const dragonBones::BoneData *target
    const dragonBones::BoneData *ret = self->target;
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ConstraintData_target$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ConstraintData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** target */

    olua_to_object(L, 1, &self, "db.ConstraintData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // const dragonBones::BoneData *target
    self->target = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ConstraintData_target(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const dragonBones::BoneData *target
        return _olua_fun_dragonBones_ConstraintData_target$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ConstraintData")) && (olua_is_object(L, 2, "db.BoneData"))) {
            // const dragonBones::BoneData *target
            return _olua_fun_dragonBones_ConstraintData_target$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ConstraintData::target' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_ConstraintData(lua_State *L)
{
    oluacls_class<dragonBones::ConstraintData, dragonBones::BaseObject>(L, "db.ConstraintData");
    oluacls_func(L, "getBone", _olua_fun_dragonBones_ConstraintData_getBone);
    oluacls_func(L, "getRoot", _olua_fun_dragonBones_ConstraintData_getRoot);
    oluacls_func(L, "getTarget", _olua_fun_dragonBones_ConstraintData_getTarget);
    oluacls_func(L, "setBone", _olua_fun_dragonBones_ConstraintData_setBone);
    oluacls_func(L, "setRoot", _olua_fun_dragonBones_ConstraintData_setRoot);
    oluacls_func(L, "setTarget", _olua_fun_dragonBones_ConstraintData_setTarget);
    oluacls_prop(L, "order", _olua_fun_dragonBones_ConstraintData_order, _olua_fun_dragonBones_ConstraintData_order);
    oluacls_prop(L, "name", _olua_fun_dragonBones_ConstraintData_name, _olua_fun_dragonBones_ConstraintData_name);
    oluacls_prop(L, "target", _olua_fun_dragonBones_ConstraintData_target, _olua_fun_dragonBones_ConstraintData_target);
    oluacls_prop(L, "root", _olua_fun_dragonBones_ConstraintData_root, _olua_fun_dragonBones_ConstraintData_root);
    oluacls_prop(L, "bone", _olua_fun_dragonBones_ConstraintData_bone, _olua_fun_dragonBones_ConstraintData_bone);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_ConstraintData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.ConstraintData")) {
        luaL_error(L, "class not found: dragonBones::ConstraintData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_IKConstraintData_bendPositive$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "db.IKConstraintData");

    // bool bendPositive
    bool ret = self->bendPositive;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_IKConstraintData_bendPositive$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;
    bool arg1 = false;       /** bendPositive */

    olua_to_object(L, 1, &self, "db.IKConstraintData");
    olua_check_bool(L, 2, &arg1);

    // bool bendPositive
    self->bendPositive = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IKConstraintData_bendPositive(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool bendPositive
        return _olua_fun_dragonBones_IKConstraintData_bendPositive$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.IKConstraintData")) && (olua_is_bool(L, 2))) {
            // bool bendPositive
            return _olua_fun_dragonBones_IKConstraintData_bendPositive$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::IKConstraintData::bendPositive' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_IKConstraintData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::IKConstraintData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_IKConstraintData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::IKConstraintData()
    dragonBones::IKConstraintData *ret = new dragonBones::IKConstraintData();
    int num_ret = olua_push_object(L, ret, "db.IKConstraintData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_IKConstraintData_scaleEnabled$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "db.IKConstraintData");

    // bool scaleEnabled
    bool ret = self->scaleEnabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_IKConstraintData_scaleEnabled$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;
    bool arg1 = false;       /** scaleEnabled */

    olua_to_object(L, 1, &self, "db.IKConstraintData");
    olua_check_bool(L, 2, &arg1);

    // bool scaleEnabled
    self->scaleEnabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IKConstraintData_scaleEnabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool scaleEnabled
        return _olua_fun_dragonBones_IKConstraintData_scaleEnabled$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.IKConstraintData")) && (olua_is_bool(L, 2))) {
            // bool scaleEnabled
            return _olua_fun_dragonBones_IKConstraintData_scaleEnabled$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::IKConstraintData::scaleEnabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_IKConstraintData_weight$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "db.IKConstraintData");

    // float weight
    float ret = self->weight;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_IKConstraintData_weight$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IKConstraintData *self = nullptr;
    float arg1 = 0;       /** weight */

    olua_to_object(L, 1, &self, "db.IKConstraintData");
    olua_check_number(L, 2, &arg1);

    // float weight
    self->weight = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IKConstraintData_weight(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float weight
        return _olua_fun_dragonBones_IKConstraintData_weight$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.IKConstraintData")) && (olua_is_number(L, 2))) {
            // float weight
            return _olua_fun_dragonBones_IKConstraintData_weight$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::IKConstraintData::weight' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_IKConstraintData(lua_State *L)
{
    oluacls_class<dragonBones::IKConstraintData, dragonBones::ConstraintData>(L, "db.IKConstraintData");
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_IKConstraintData_getTypeIndex);
    oluacls_func(L, "new", _olua_fun_dragonBones_IKConstraintData_new);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_IKConstraintData_getTypeIndex, nullptr);
    oluacls_prop(L, "scaleEnabled", _olua_fun_dragonBones_IKConstraintData_scaleEnabled, _olua_fun_dragonBones_IKConstraintData_scaleEnabled);
    oluacls_prop(L, "bendPositive", _olua_fun_dragonBones_IKConstraintData_bendPositive, _olua_fun_dragonBones_IKConstraintData_bendPositive);
    oluacls_prop(L, "weight", _olua_fun_dragonBones_IKConstraintData_weight, _olua_fun_dragonBones_IKConstraintData_weight);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_IKConstraintData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.IKConstraintData")) {
        luaL_error(L, "class not found: dragonBones::IKConstraintData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_TimelineData_frameIndicesOffset$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TimelineData");

    // int frameIndicesOffset
    int ret = self->frameIndicesOffset;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TimelineData_frameIndicesOffset$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;
    int arg1 = 0;       /** frameIndicesOffset */

    olua_to_object(L, 1, &self, "db.TimelineData");
    olua_check_integer(L, 2, &arg1);

    // int frameIndicesOffset
    self->frameIndicesOffset = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TimelineData_frameIndicesOffset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int frameIndicesOffset
        return _olua_fun_dragonBones_TimelineData_frameIndicesOffset$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TimelineData")) && (olua_is_integer(L, 2))) {
            // int frameIndicesOffset
            return _olua_fun_dragonBones_TimelineData_frameIndicesOffset$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TimelineData::frameIndicesOffset' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TimelineData_getType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TimelineData");

    // int getType()
    int ret = self->getType();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TimelineData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::TimelineData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TimelineData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::TimelineData()
    dragonBones::TimelineData *ret = new dragonBones::TimelineData();
    int num_ret = olua_push_object(L, ret, "db.TimelineData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TimelineData_offset$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TimelineData");

    // unsigned int offset
    unsigned int ret = self->offset;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TimelineData_offset$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;
    unsigned int arg1 = 0;       /** offset */

    olua_to_object(L, 1, &self, "db.TimelineData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int offset
    self->offset = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TimelineData_offset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int offset
        return _olua_fun_dragonBones_TimelineData_offset$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TimelineData")) && (olua_is_integer(L, 2))) {
            // unsigned int offset
            return _olua_fun_dragonBones_TimelineData_offset$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TimelineData::offset' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TimelineData_setType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.TimelineData");
    olua_check_integer(L, 2, &arg1);

    // void setType(int value)
    self->setType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TimelineData_type$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TimelineData");

    // dragonBones::TimelineType type
    dragonBones::TimelineType ret = self->type;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TimelineData_type$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TimelineData *self = nullptr;
    dragonBones::TimelineType arg1 = (dragonBones::TimelineType)0;       /** type */

    olua_to_object(L, 1, &self, "db.TimelineData");
    olua_check_enum(L, 2, &arg1);

    // dragonBones::TimelineType type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TimelineData_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::TimelineType type
        return _olua_fun_dragonBones_TimelineData_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TimelineData")) && (olua_is_enum(L, 2))) {
            // dragonBones::TimelineType type
            return _olua_fun_dragonBones_TimelineData_type$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TimelineData::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_TimelineData(lua_State *L)
{
    oluacls_class<dragonBones::TimelineData, dragonBones::BaseObject>(L, "db.TimelineData");
    oluacls_func(L, "getType", _olua_fun_dragonBones_TimelineData_getType);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_TimelineData_getTypeIndex);
    oluacls_func(L, "new", _olua_fun_dragonBones_TimelineData_new);
    oluacls_func(L, "setType", _olua_fun_dragonBones_TimelineData_setType);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_TimelineData_getTypeIndex, nullptr);
    oluacls_prop(L, "type", _olua_fun_dragonBones_TimelineData_type, _olua_fun_dragonBones_TimelineData_type);
    oluacls_prop(L, "offset", _olua_fun_dragonBones_TimelineData_offset, _olua_fun_dragonBones_TimelineData_offset);
    oluacls_prop(L, "frameIndicesOffset", _olua_fun_dragonBones_TimelineData_frameIndicesOffset, _olua_fun_dragonBones_TimelineData_frameIndicesOffset);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_TimelineData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.TimelineData")) {
        luaL_error(L, "class not found: dragonBones::TimelineData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_IAnimatable___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::IAnimatable *)olua_toobj(L, 1, "db.IAnimatable");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IAnimatable_advanceTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IAnimatable *self = nullptr;
    float arg1 = 0;       /** passedTime */

    olua_to_object(L, 1, &self, "db.IAnimatable");
    olua_check_number(L, 2, &arg1);

    // void advanceTime(float passedTime)
    self->advanceTime(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IAnimatable_getClock(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IAnimatable *self = nullptr;

    olua_to_object(L, 1, &self, "db.IAnimatable");

    // dragonBones::WorldClock *getClock()
    dragonBones::WorldClock *ret = self->getClock();
    int num_ret = olua_push_object(L, ret, "db.WorldClock");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_IAnimatable_setClock(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IAnimatable *self = nullptr;
    dragonBones::WorldClock *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.IAnimatable");
    olua_check_object(L, 2, &arg1, "db.WorldClock");

    // void setClock(dragonBones::WorldClock *value)
    self->setClock(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_db_IAnimatable(lua_State *L)
{
    oluacls_class<dragonBones::IAnimatable>(L, "db.IAnimatable");
    oluacls_func(L, "__gc", _olua_fun_dragonBones_IAnimatable___gc);
    oluacls_func(L, "advanceTime", _olua_fun_dragonBones_IAnimatable_advanceTime);
    oluacls_func(L, "getClock", _olua_fun_dragonBones_IAnimatable_getClock);
    oluacls_func(L, "setClock", _olua_fun_dragonBones_IAnimatable_setClock);
    oluacls_prop(L, "clock", _olua_fun_dragonBones_IAnimatable_getClock, _olua_fun_dragonBones_IAnimatable_setClock);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_IAnimatable(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.IAnimatable")) {
        luaL_error(L, "class not found: dragonBones::IAnimatable");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_WorldClock_add(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;
    dragonBones::IAnimatable *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.WorldClock");
    olua_check_object(L, 2, &arg1, "db.IAnimatable");

    // void add(dragonBones::IAnimatable *value)
    self->add(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_WorldClock_clear(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;

    olua_to_object(L, 1, &self, "db.WorldClock");

    // void clear()
    self->clear();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_WorldClock_clock$1(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::WorldClock clock
    dragonBones::WorldClock &ret = dragonBones::WorldClock::clock;
    int num_ret = olua_copy_object(L, ret, "db.WorldClock");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_WorldClock_clock$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *arg1;       /** clock */

    olua_check_object(L, 1, &arg1, "db.WorldClock");

    // static dragonBones::WorldClock clock
    dragonBones::WorldClock::clock = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_WorldClock_clock(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static dragonBones::WorldClock clock
        return _olua_fun_dragonBones_WorldClock_clock$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "db.WorldClock"))) {
            // static dragonBones::WorldClock clock
            return _olua_fun_dragonBones_WorldClock_clock$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::WorldClock::clock' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_WorldClock_contains(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;
    dragonBones::IAnimatable *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.WorldClock");
    olua_check_object(L, 2, &arg1, "db.IAnimatable");

    // bool contains(const dragonBones::IAnimatable *value)
    bool ret = self->contains(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_WorldClock_getStaticClock(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::WorldClock *getStaticClock()
    dragonBones::WorldClock *ret = dragonBones::WorldClock::getStaticClock();
    int num_ret = olua_push_object(L, ret, "db.WorldClock");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_WorldClock_new$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** timeValue */

    olua_check_number(L, 1, &arg1);

    // dragonBones::WorldClock(@optional float timeValue)
    dragonBones::WorldClock *ret = new dragonBones::WorldClock(arg1);
    int num_ret = olua_push_object(L, ret, "db.WorldClock");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_WorldClock_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::WorldClock()
    dragonBones::WorldClock *ret = new dragonBones::WorldClock();
    int num_ret = olua_push_object(L, ret, "db.WorldClock");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_WorldClock_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // dragonBones::WorldClock()
        return _olua_fun_dragonBones_WorldClock_new$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_number(L, 1))) {
            // dragonBones::WorldClock(@optional float timeValue)
            return _olua_fun_dragonBones_WorldClock_new$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::WorldClock::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_WorldClock_remove(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;
    dragonBones::IAnimatable *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.WorldClock");
    olua_check_object(L, 2, &arg1, "db.IAnimatable");

    // void remove(dragonBones::IAnimatable *value)
    self->remove(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_WorldClock_time$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;

    olua_to_object(L, 1, &self, "db.WorldClock");

    // float time
    float ret = self->time;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_WorldClock_time$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;
    float arg1 = 0;       /** time */

    olua_to_object(L, 1, &self, "db.WorldClock");
    olua_check_number(L, 2, &arg1);

    // float time
    self->time = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_WorldClock_time(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float time
        return _olua_fun_dragonBones_WorldClock_time$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.WorldClock")) && (olua_is_number(L, 2))) {
            // float time
            return _olua_fun_dragonBones_WorldClock_time$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::WorldClock::time' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_WorldClock_timeScale$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;

    olua_to_object(L, 1, &self, "db.WorldClock");

    // float timeScale
    float ret = self->timeScale;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_WorldClock_timeScale$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::WorldClock *self = nullptr;
    float arg1 = 0;       /** timeScale */

    olua_to_object(L, 1, &self, "db.WorldClock");
    olua_check_number(L, 2, &arg1);

    // float timeScale
    self->timeScale = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_WorldClock_timeScale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float timeScale
        return _olua_fun_dragonBones_WorldClock_timeScale$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.WorldClock")) && (olua_is_number(L, 2))) {
            // float timeScale
            return _olua_fun_dragonBones_WorldClock_timeScale$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::WorldClock::timeScale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_WorldClock(lua_State *L)
{
    oluacls_class<dragonBones::WorldClock, dragonBones::IAnimatable>(L, "db.WorldClock");
    oluacls_func(L, "add", _olua_fun_dragonBones_WorldClock_add);
    oluacls_func(L, "clear", _olua_fun_dragonBones_WorldClock_clear);
    oluacls_func(L, "contains", _olua_fun_dragonBones_WorldClock_contains);
    oluacls_func(L, "getStaticClock", _olua_fun_dragonBones_WorldClock_getStaticClock);
    oluacls_func(L, "new", _olua_fun_dragonBones_WorldClock_new);
    oluacls_func(L, "remove", _olua_fun_dragonBones_WorldClock_remove);
    oluacls_prop(L, "staticClock", _olua_fun_dragonBones_WorldClock_getStaticClock, nullptr);
    oluacls_prop(L, "clock", _olua_fun_dragonBones_WorldClock_clock, _olua_fun_dragonBones_WorldClock_clock);
    oluacls_prop(L, "time", _olua_fun_dragonBones_WorldClock_time, _olua_fun_dragonBones_WorldClock_time);
    oluacls_prop(L, "timeScale", _olua_fun_dragonBones_WorldClock_timeScale, _olua_fun_dragonBones_WorldClock_timeScale);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_WorldClock(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.WorldClock")) {
        luaL_error(L, "class not found: dragonBones::WorldClock");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_Slot_containsPoint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // bool containsPoint(float x, float y)
    bool ret = self->containsPoint(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_displayController$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // std::string displayController
    std::string ret = self->displayController;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_displayController$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    std::string arg1;       /** displayController */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_string(L, 2, &arg1);

    // std::string displayController
    self->displayController = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Slot_displayController(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string displayController
        return _olua_fun_dragonBones_Slot_displayController$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Slot")) && (olua_is_string(L, 2))) {
            // std::string displayController
            return _olua_fun_dragonBones_Slot_displayController$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Slot::displayController' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Slot_getBoundingBoxData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // dragonBones::BoundingBoxData *getBoundingBoxData()
    dragonBones::BoundingBoxData *ret = self->getBoundingBoxData();
    int num_ret = olua_push_object(L, ret, "db.BoundingBoxData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_getChildArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // dragonBones::Armature *getChildArmature()
    dragonBones::Armature *ret = self->getChildArmature();
    int num_ret = olua_push_object(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_getDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // void *getDisplay()
    void *ret = self->getDisplay();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_getDisplayIndex(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // int getDisplayIndex()
    int ret = self->getDisplayIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_getMeshDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // void *getMeshDisplay()
    void *ret = self->getMeshDisplay();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_getName(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // const std::string &getName()
    const std::string &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // dragonBones::Bone *getParent()
    dragonBones::Bone *ret = self->getParent();
    int num_ret = olua_push_object(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_getRawDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // void *getRawDisplay()
    void *ret = self->getRawDisplay();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_getSlotData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // const dragonBones::SlotData *getSlotData()
    const dragonBones::SlotData *ret = self->getSlotData();
    int num_ret = olua_push_object(L, ret, "db.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_getVisible(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // bool getVisible()
    bool ret = self->getVisible();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_init(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    dragonBones::SlotData *arg1 = nullptr;       /** slotData */
    dragonBones::Armature *arg2 = nullptr;       /** armatureValue */
    void *arg3 = nullptr;       /** rawDisplay */
    void *arg4 = nullptr;       /** meshDisplay */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_object(L, 2, &arg1, "db.SlotData");
    olua_check_object(L, 3, &arg2, "db.Armature");
    olua_check_object(L, 4, &arg3, "void *");
    olua_check_object(L, 5, &arg4, "void *");

    // void init(const dragonBones::SlotData *slotData, dragonBones::Armature *armatureValue, void *rawDisplay, void *meshDisplay)
    self->init(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Slot_intersectsSegment$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */
    dragonBones::Point *arg7 = nullptr;       /** normalRadians */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "db.Point");
    olua_check_object(L, 7, &arg6, "db.Point");
    olua_check_object(L, 8, &arg7, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    int ret = self->intersectsSegment(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_intersectsSegment$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // int intersectsSegment(float xA, float yA, float xB, float yB)
    int ret = self->intersectsSegment(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_intersectsSegment$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA)
    int ret = self->intersectsSegment(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_intersectsSegment$4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "db.Point");
    olua_check_object(L, 7, &arg6, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB)
    int ret = self->intersectsSegment(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Slot_intersectsSegment(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "db.Slot")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB)
            return _olua_fun_dragonBones_Slot_intersectsSegment$2(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "db.Slot")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_object(L, 6, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA)
            return _olua_fun_dragonBones_Slot_intersectsSegment$3(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "db.Slot")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_object(L, 6, "db.Point")) && (olua_is_object(L, 7, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB)
            return _olua_fun_dragonBones_Slot_intersectsSegment$4(L);
        // }
    }

    if (num_args == 8) {
        // if ((olua_is_object(L, 1, "db.Slot")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_object(L, 6, "db.Point")) && (olua_is_object(L, 7, "db.Point")) && (olua_is_object(L, 8, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _olua_fun_dragonBones_Slot_intersectsSegment$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Slot::intersectsSegment' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Slot_invalidUpdate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // void invalidUpdate()
    self->invalidUpdate();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Slot_replaceDisplayData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    dragonBones::DisplayData *arg1 = nullptr;       /** displayData */
    int arg2 = 0;       /** displayIndex */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_object(L, 2, &arg1, "db.DisplayData");
    olua_check_integer(L, 3, &arg2);

    // void replaceDisplayData(dragonBones::DisplayData *displayData, int displayIndex)
    self->replaceDisplayData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Slot_setChildArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_object(L, 2, &arg1, "db.Armature");

    // void setChildArmature(dragonBones::Armature *value)
    self->setChildArmature(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Slot_setDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    void *arg1 = nullptr;       /** value */
    dragonBones::DisplayType arg2 = (dragonBones::DisplayType)0;       /** displayType */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_object(L, 2, &arg1, "void *");
    olua_check_enum(L, 3, &arg2);

    // void setDisplay(void *value, dragonBones::DisplayType displayType)
    self->setDisplay(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Slot_setDisplayIndex(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_integer(L, 2, &arg1);

    // void setDisplayIndex(int value)
    self->setDisplayIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Slot_setVisible(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_bool(L, 2, &arg1);

    // void setVisible(bool value)
    self->setVisible(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Slot_update(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;
    int arg1 = 0;       /** cacheFrameIndex */

    olua_to_object(L, 1, &self, "db.Slot");
    olua_check_integer(L, 2, &arg1);

    // void update(int cacheFrameIndex)
    self->update(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Slot_updateTransformAndMatrix(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "db.Slot");

    // void updateTransformAndMatrix()
    self->updateTransformAndMatrix();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_db_Slot(lua_State *L)
{
    oluacls_class<dragonBones::Slot, dragonBones::TransformObject>(L, "db.Slot");
    oluacls_func(L, "containsPoint", _olua_fun_dragonBones_Slot_containsPoint);
    oluacls_func(L, "getBoundingBoxData", _olua_fun_dragonBones_Slot_getBoundingBoxData);
    oluacls_func(L, "getChildArmature", _olua_fun_dragonBones_Slot_getChildArmature);
    oluacls_func(L, "getDisplay", _olua_fun_dragonBones_Slot_getDisplay);
    oluacls_func(L, "getDisplayIndex", _olua_fun_dragonBones_Slot_getDisplayIndex);
    oluacls_func(L, "getMeshDisplay", _olua_fun_dragonBones_Slot_getMeshDisplay);
    oluacls_func(L, "getName", _olua_fun_dragonBones_Slot_getName);
    oluacls_func(L, "getParent", _olua_fun_dragonBones_Slot_getParent);
    oluacls_func(L, "getRawDisplay", _olua_fun_dragonBones_Slot_getRawDisplay);
    oluacls_func(L, "getSlotData", _olua_fun_dragonBones_Slot_getSlotData);
    oluacls_func(L, "getVisible", _olua_fun_dragonBones_Slot_getVisible);
    oluacls_func(L, "init", _olua_fun_dragonBones_Slot_init);
    oluacls_func(L, "intersectsSegment", _olua_fun_dragonBones_Slot_intersectsSegment);
    oluacls_func(L, "invalidUpdate", _olua_fun_dragonBones_Slot_invalidUpdate);
    oluacls_func(L, "replaceDisplayData", _olua_fun_dragonBones_Slot_replaceDisplayData);
    oluacls_func(L, "setChildArmature", _olua_fun_dragonBones_Slot_setChildArmature);
    oluacls_func(L, "setDisplay", _olua_fun_dragonBones_Slot_setDisplay);
    oluacls_func(L, "setDisplayIndex", _olua_fun_dragonBones_Slot_setDisplayIndex);
    oluacls_func(L, "setVisible", _olua_fun_dragonBones_Slot_setVisible);
    oluacls_func(L, "update", _olua_fun_dragonBones_Slot_update);
    oluacls_func(L, "updateTransformAndMatrix", _olua_fun_dragonBones_Slot_updateTransformAndMatrix);
    oluacls_prop(L, "boundingBoxData", _olua_fun_dragonBones_Slot_getBoundingBoxData, nullptr);
    oluacls_prop(L, "childArmature", _olua_fun_dragonBones_Slot_getChildArmature, _olua_fun_dragonBones_Slot_setChildArmature);
    oluacls_prop(L, "displayIndex", _olua_fun_dragonBones_Slot_getDisplayIndex, _olua_fun_dragonBones_Slot_setDisplayIndex);
    oluacls_prop(L, "meshDisplay", _olua_fun_dragonBones_Slot_getMeshDisplay, nullptr);
    oluacls_prop(L, "name", _olua_fun_dragonBones_Slot_getName, nullptr);
    oluacls_prop(L, "parent", _olua_fun_dragonBones_Slot_getParent, nullptr);
    oluacls_prop(L, "rawDisplay", _olua_fun_dragonBones_Slot_getRawDisplay, nullptr);
    oluacls_prop(L, "slotData", _olua_fun_dragonBones_Slot_getSlotData, nullptr);
    oluacls_prop(L, "visible", _olua_fun_dragonBones_Slot_getVisible, _olua_fun_dragonBones_Slot_setVisible);
    oluacls_prop(L, "displayController", _olua_fun_dragonBones_Slot_displayController, _olua_fun_dragonBones_Slot_displayController);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_Slot(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.Slot")) {
        luaL_error(L, "class not found: dragonBones::Slot");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_Bone_contains(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    dragonBones::Bone *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.Bone");
    olua_check_object(L, 2, &arg1, "db.Bone");

    // bool contains(const dragonBones::Bone *value)
    bool ret = self->contains(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Bone_getBoneData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "db.Bone");

    // const dragonBones::BoneData *getBoneData()
    const dragonBones::BoneData *ret = self->getBoneData();
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Bone_getName(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "db.Bone");

    // const std::string &getName()
    const std::string &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Bone_getOffsetMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "db.Bone");

    // int getOffsetMode()
    int ret = self->getOffsetMode();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Bone_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "db.Bone");

    // dragonBones::Bone *getParent()
    dragonBones::Bone *ret = self->getParent();
    int num_ret = olua_push_object(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Bone_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::Bone::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Bone_getVisible(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "db.Bone");

    // bool getVisible()
    bool ret = self->getVisible();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Bone_init(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** boneData */
    dragonBones::Armature *arg2 = nullptr;       /** armatureValue */

    olua_to_object(L, 1, &self, "db.Bone");
    olua_check_object(L, 2, &arg1, "db.BoneData");
    olua_check_object(L, 3, &arg2, "db.Armature");

    // void init(const dragonBones::BoneData *boneData, dragonBones::Armature *armatureValue)
    self->init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Bone_invalidUpdate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "db.Bone");

    // void invalidUpdate()
    self->invalidUpdate();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Bone_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::Bone()
    dragonBones::Bone *ret = new dragonBones::Bone();
    int num_ret = olua_push_object(L, ret, "db.Bone");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Bone_offsetMode$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "db.Bone");

    // dragonBones::OffsetMode offsetMode
    dragonBones::OffsetMode ret = self->offsetMode;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Bone_offsetMode$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    dragonBones::OffsetMode arg1 = (dragonBones::OffsetMode)0;       /** offsetMode */

    olua_to_object(L, 1, &self, "db.Bone");
    olua_check_enum(L, 2, &arg1);

    // dragonBones::OffsetMode offsetMode
    self->offsetMode = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Bone_offsetMode(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::OffsetMode offsetMode
        return _olua_fun_dragonBones_Bone_offsetMode$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Bone")) && (olua_is_enum(L, 2))) {
            // dragonBones::OffsetMode offsetMode
            return _olua_fun_dragonBones_Bone_offsetMode$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Bone::offsetMode' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Bone_setOffsetMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.Bone");
    olua_check_integer(L, 2, &arg1);

    // void setOffsetMode(int value)
    self->setOffsetMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Bone_setVisible(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_object(L, 1, &self, "db.Bone");
    olua_check_bool(L, 2, &arg1);

    // void setVisible(bool value)
    self->setVisible(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Bone_update(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;
    int arg1 = 0;       /** cacheFrameIndex */

    olua_to_object(L, 1, &self, "db.Bone");
    olua_check_integer(L, 2, &arg1);

    // void update(int cacheFrameIndex)
    self->update(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Bone_updateByConstraint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "db.Bone");

    // void updateByConstraint()
    self->updateByConstraint();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_db_Bone(lua_State *L)
{
    oluacls_class<dragonBones::Bone, dragonBones::TransformObject>(L, "db.Bone");
    oluacls_func(L, "contains", _olua_fun_dragonBones_Bone_contains);
    oluacls_func(L, "getBoneData", _olua_fun_dragonBones_Bone_getBoneData);
    oluacls_func(L, "getName", _olua_fun_dragonBones_Bone_getName);
    oluacls_func(L, "getOffsetMode", _olua_fun_dragonBones_Bone_getOffsetMode);
    oluacls_func(L, "getParent", _olua_fun_dragonBones_Bone_getParent);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_Bone_getTypeIndex);
    oluacls_func(L, "getVisible", _olua_fun_dragonBones_Bone_getVisible);
    oluacls_func(L, "init", _olua_fun_dragonBones_Bone_init);
    oluacls_func(L, "invalidUpdate", _olua_fun_dragonBones_Bone_invalidUpdate);
    oluacls_func(L, "new", _olua_fun_dragonBones_Bone_new);
    oluacls_func(L, "setOffsetMode", _olua_fun_dragonBones_Bone_setOffsetMode);
    oluacls_func(L, "setVisible", _olua_fun_dragonBones_Bone_setVisible);
    oluacls_func(L, "update", _olua_fun_dragonBones_Bone_update);
    oluacls_func(L, "updateByConstraint", _olua_fun_dragonBones_Bone_updateByConstraint);
    oluacls_prop(L, "boneData", _olua_fun_dragonBones_Bone_getBoneData, nullptr);
    oluacls_prop(L, "name", _olua_fun_dragonBones_Bone_getName, nullptr);
    oluacls_prop(L, "parent", _olua_fun_dragonBones_Bone_getParent, nullptr);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_Bone_getTypeIndex, nullptr);
    oluacls_prop(L, "visible", _olua_fun_dragonBones_Bone_getVisible, _olua_fun_dragonBones_Bone_setVisible);
    oluacls_prop(L, "offsetMode", _olua_fun_dragonBones_Bone_offsetMode, _olua_fun_dragonBones_Bone_offsetMode);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_Bone(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.Bone")) {
        luaL_error(L, "class not found: dragonBones::Bone");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_DisplayData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DisplayData");

    // dragonBones::SkinData *getParent()
    dragonBones::SkinData *ret = self->getParent();
    int num_ret = olua_push_object(L, ret, "db.SkinData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DisplayData_getType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DisplayData");

    // int getType()
    int ret = self->getType();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DisplayData_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DisplayData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DisplayData_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.DisplayData");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DisplayData_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_DisplayData_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DisplayData")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_DisplayData_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DisplayData::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DisplayData_parent$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DisplayData");

    // dragonBones::SkinData *parent
    dragonBones::SkinData *ret = self->parent;
    int num_ret = olua_push_object(L, ret, "db.SkinData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DisplayData_parent$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    dragonBones::SkinData *arg1 = nullptr;       /** parent */

    olua_to_object(L, 1, &self, "db.DisplayData");
    olua_check_object(L, 2, &arg1, "db.SkinData");

    // dragonBones::SkinData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DisplayData_parent(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::SkinData *parent
        return _olua_fun_dragonBones_DisplayData_parent$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DisplayData")) && (olua_is_object(L, 2, "db.SkinData"))) {
            // dragonBones::SkinData *parent
            return _olua_fun_dragonBones_DisplayData_parent$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DisplayData::parent' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DisplayData_path$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DisplayData");

    // std::string path
    std::string ret = self->path;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DisplayData_path$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    std::string arg1;       /** path */

    olua_to_object(L, 1, &self, "db.DisplayData");
    olua_check_string(L, 2, &arg1);

    // std::string path
    self->path = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DisplayData_path(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string path
        return _olua_fun_dragonBones_DisplayData_path$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DisplayData")) && (olua_is_string(L, 2))) {
            // std::string path
            return _olua_fun_dragonBones_DisplayData_path$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DisplayData::path' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DisplayData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    dragonBones::SkinData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.DisplayData");
    olua_check_object(L, 2, &arg1, "db.SkinData");

    // void setParent(dragonBones::SkinData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DisplayData_setType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.DisplayData");
    olua_check_integer(L, 2, &arg1);

    // void setType(int value)
    self->setType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DisplayData_type$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DisplayData");

    // dragonBones::DisplayType type
    dragonBones::DisplayType ret = self->type;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DisplayData_type$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DisplayData *self = nullptr;
    dragonBones::DisplayType arg1 = (dragonBones::DisplayType)0;       /** type */

    olua_to_object(L, 1, &self, "db.DisplayData");
    olua_check_enum(L, 2, &arg1);

    // dragonBones::DisplayType type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DisplayData_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::DisplayType type
        return _olua_fun_dragonBones_DisplayData_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DisplayData")) && (olua_is_enum(L, 2))) {
            // dragonBones::DisplayType type
            return _olua_fun_dragonBones_DisplayData_type$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DisplayData::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_DisplayData(lua_State *L)
{
    oluacls_class<dragonBones::DisplayData, dragonBones::BaseObject>(L, "db.DisplayData");
    oluacls_func(L, "getParent", _olua_fun_dragonBones_DisplayData_getParent);
    oluacls_func(L, "getType", _olua_fun_dragonBones_DisplayData_getType);
    oluacls_func(L, "setParent", _olua_fun_dragonBones_DisplayData_setParent);
    oluacls_func(L, "setType", _olua_fun_dragonBones_DisplayData_setType);
    oluacls_prop(L, "type", _olua_fun_dragonBones_DisplayData_type, _olua_fun_dragonBones_DisplayData_type);
    oluacls_prop(L, "name", _olua_fun_dragonBones_DisplayData_name, _olua_fun_dragonBones_DisplayData_name);
    oluacls_prop(L, "path", _olua_fun_dragonBones_DisplayData_path, _olua_fun_dragonBones_DisplayData_path);
    oluacls_prop(L, "parent", _olua_fun_dragonBones_DisplayData_parent, _olua_fun_dragonBones_DisplayData_parent);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_DisplayData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.DisplayData")) {
        luaL_error(L, "class not found: dragonBones::DisplayData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_ActionData_bone$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ActionData");

    // const dragonBones::BoneData *bone
    const dragonBones::BoneData *ret = self->bone;
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ActionData_bone$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** bone */

    olua_to_object(L, 1, &self, "db.ActionData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // const dragonBones::BoneData *bone
    self->bone = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_bone(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const dragonBones::BoneData *bone
        return _olua_fun_dragonBones_ActionData_bone$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ActionData")) && (olua_is_object(L, 2, "db.BoneData"))) {
            // const dragonBones::BoneData *bone
            return _olua_fun_dragonBones_ActionData_bone$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ActionData::bone' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_data$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ActionData");

    // dragonBones::UserData *data
    dragonBones::UserData *ret = self->data;
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ActionData_data$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "db.ActionData");
    olua_check_object(L, 2, &arg1, "db.UserData");

    // dragonBones::UserData *data
    self->data = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_data(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::UserData *data
        return _olua_fun_dragonBones_ActionData_data$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ActionData")) && (olua_is_object(L, 2, "db.UserData"))) {
            // dragonBones::UserData *data
            return _olua_fun_dragonBones_ActionData_data$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ActionData::data' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_getBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ActionData");

    // const dragonBones::BoneData *getBone()
    const dragonBones::BoneData *ret = self->getBone();
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ActionData_getData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ActionData");

    // const dragonBones::UserData *getData()
    const dragonBones::UserData *ret = self->getData();
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ActionData_getSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ActionData");

    // const dragonBones::SlotData *getSlot()
    const dragonBones::SlotData *ret = self->getSlot();
    int num_ret = olua_push_object(L, ret, "db.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ActionData_getType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ActionData");

    // int getType()
    int ret = self->getType();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ActionData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::ActionData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ActionData_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ActionData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ActionData_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.ActionData");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_ActionData_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ActionData")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_ActionData_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ActionData::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::ActionData()
    dragonBones::ActionData *ret = new dragonBones::ActionData();
    int num_ret = olua_push_object(L, ret, "db.ActionData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ActionData_setBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ActionData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // void setBone(const dragonBones::BoneData *value)
    self->setBone(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_setData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ActionData");
    olua_check_object(L, 2, &arg1, "db.UserData");

    // void setData(dragonBones::UserData *value)
    self->setData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_setSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::SlotData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ActionData");
    olua_check_object(L, 2, &arg1, "db.SlotData");

    // void setSlot(const dragonBones::SlotData *value)
    self->setSlot(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_setType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.ActionData");
    olua_check_integer(L, 2, &arg1);

    // void setType(int value)
    self->setType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_slot$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ActionData");

    // const dragonBones::SlotData *slot
    const dragonBones::SlotData *ret = self->slot;
    int num_ret = olua_push_object(L, ret, "db.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ActionData_slot$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::SlotData *arg1 = nullptr;       /** slot */

    olua_to_object(L, 1, &self, "db.ActionData");
    olua_check_object(L, 2, &arg1, "db.SlotData");

    // const dragonBones::SlotData *slot
    self->slot = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_slot(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const dragonBones::SlotData *slot
        return _olua_fun_dragonBones_ActionData_slot$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ActionData")) && (olua_is_object(L, 2, "db.SlotData"))) {
            // const dragonBones::SlotData *slot
            return _olua_fun_dragonBones_ActionData_slot$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ActionData::slot' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_type$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ActionData");

    // dragonBones::ActionType type
    dragonBones::ActionType ret = self->type;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ActionData_type$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ActionData *self = nullptr;
    dragonBones::ActionType arg1 = (dragonBones::ActionType)0;       /** type */

    olua_to_object(L, 1, &self, "db.ActionData");
    olua_check_enum(L, 2, &arg1);

    // dragonBones::ActionType type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ActionData_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::ActionType type
        return _olua_fun_dragonBones_ActionData_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ActionData")) && (olua_is_enum(L, 2))) {
            // dragonBones::ActionType type
            return _olua_fun_dragonBones_ActionData_type$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ActionData::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_ActionData(lua_State *L)
{
    oluacls_class<dragonBones::ActionData, dragonBones::BaseObject>(L, "db.ActionData");
    oluacls_func(L, "getBone", _olua_fun_dragonBones_ActionData_getBone);
    oluacls_func(L, "getData", _olua_fun_dragonBones_ActionData_getData);
    oluacls_func(L, "getSlot", _olua_fun_dragonBones_ActionData_getSlot);
    oluacls_func(L, "getType", _olua_fun_dragonBones_ActionData_getType);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_ActionData_getTypeIndex);
    oluacls_func(L, "new", _olua_fun_dragonBones_ActionData_new);
    oluacls_func(L, "setBone", _olua_fun_dragonBones_ActionData_setBone);
    oluacls_func(L, "setData", _olua_fun_dragonBones_ActionData_setData);
    oluacls_func(L, "setSlot", _olua_fun_dragonBones_ActionData_setSlot);
    oluacls_func(L, "setType", _olua_fun_dragonBones_ActionData_setType);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_ActionData_getTypeIndex, nullptr);
    oluacls_prop(L, "type", _olua_fun_dragonBones_ActionData_type, _olua_fun_dragonBones_ActionData_type);
    oluacls_prop(L, "name", _olua_fun_dragonBones_ActionData_name, _olua_fun_dragonBones_ActionData_name);
    oluacls_prop(L, "bone", _olua_fun_dragonBones_ActionData_bone, _olua_fun_dragonBones_ActionData_bone);
    oluacls_prop(L, "slot", _olua_fun_dragonBones_ActionData_slot, _olua_fun_dragonBones_ActionData_slot);
    oluacls_prop(L, "data", _olua_fun_dragonBones_ActionData_data, _olua_fun_dragonBones_ActionData_data);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_ActionData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.ActionData")) {
        luaL_error(L, "class not found: dragonBones::ActionData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_UserData_addFloat(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    float arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.UserData");
    olua_check_number(L, 2, &arg1);

    // void addFloat(float value)
    self->addFloat(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_UserData_addInt(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.UserData");
    olua_check_integer(L, 2, &arg1);

    // void addInt(int value)
    self->addInt(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_UserData_addString(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    std::string arg1;       /** value */

    olua_to_object(L, 1, &self, "db.UserData");
    olua_check_string(L, 2, &arg1);

    // void addString(std::string value)
    self->addString(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_UserData_floats$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_object(L, 1, &self, "db.UserData");

    // std::vector<float> floats
    std::vector<float> &ret = self->floats;
    int num_ret = olua_push_array<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_UserData_floats$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    std::vector<float> arg1;       /** floats */

    olua_to_object(L, 1, &self, "db.UserData");
    olua_check_array<float>(L, 2, arg1, [L](float *arg1) {
        olua_check_number(L, -1, arg1);
    });

    // std::vector<float> floats
    self->floats = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_UserData_floats(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<float> floats
        return _olua_fun_dragonBones_UserData_floats$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.UserData")) && (olua_is_array(L, 2))) {
            // std::vector<float> floats
            return _olua_fun_dragonBones_UserData_floats$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::UserData::floats' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_UserData_getFloat(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    unsigned int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "db.UserData");
    olua_check_integer(L, 2, &arg1);

    // float getFloat(unsigned int index)
    float ret = self->getFloat(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_UserData_getFloats(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_object(L, 1, &self, "db.UserData");

    // const std::vector<float> &getFloats()
    const std::vector<float> &ret = self->getFloats();
    int num_ret = olua_push_array<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_UserData_getInt(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    unsigned int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "db.UserData");
    olua_check_integer(L, 2, &arg1);

    // int getInt(unsigned int index)
    int ret = self->getInt(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_UserData_getInts(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_object(L, 1, &self, "db.UserData");

    // const std::vector<int> &getInts()
    const std::vector<int> &ret = self->getInts();
    int num_ret = olua_push_array<int>(L, ret, [L](int &arg1) {
        olua_push_integer(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_UserData_getString(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    unsigned int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "db.UserData");
    olua_check_integer(L, 2, &arg1);

    // std::string getString(unsigned int index)
    std::string ret = self->getString(arg1);
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_UserData_getStrings(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_object(L, 1, &self, "db.UserData");

    // const std::vector<std::string> &getStrings()
    const std::vector<std::string> &ret = self->getStrings();
    int num_ret = olua_push_array<std::string>(L, ret, [L](std::string &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_UserData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::UserData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_UserData_ints$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_object(L, 1, &self, "db.UserData");

    // std::vector<int> ints
    std::vector<int> &ret = self->ints;
    int num_ret = olua_push_array<int>(L, ret, [L](int &arg1) {
        olua_push_integer(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_UserData_ints$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    std::vector<int> arg1;       /** ints */

    olua_to_object(L, 1, &self, "db.UserData");
    olua_check_array<int>(L, 2, arg1, [L](int *arg1) {
        olua_check_integer(L, -1, arg1);
    });

    // std::vector<int> ints
    self->ints = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_UserData_ints(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<int> ints
        return _olua_fun_dragonBones_UserData_ints$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.UserData")) && (olua_is_array(L, 2))) {
            // std::vector<int> ints
            return _olua_fun_dragonBones_UserData_ints$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::UserData::ints' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_UserData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::UserData()
    dragonBones::UserData *ret = new dragonBones::UserData();
    int num_ret = olua_push_object(L, ret, "db.UserData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_UserData_strings$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;

    olua_to_object(L, 1, &self, "db.UserData");

    // std::vector<std::string> strings
    std::vector<std::string> &ret = self->strings;
    int num_ret = olua_push_array<std::string>(L, ret, [L](std::string &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_UserData_strings$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::UserData *self = nullptr;
    std::vector<std::string> arg1;       /** strings */

    olua_to_object(L, 1, &self, "db.UserData");
    olua_check_array<std::string>(L, 2, arg1, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // std::vector<std::string> strings
    self->strings = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_UserData_strings(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<std::string> strings
        return _olua_fun_dragonBones_UserData_strings$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.UserData")) && (olua_is_array(L, 2))) {
            // std::vector<std::string> strings
            return _olua_fun_dragonBones_UserData_strings$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::UserData::strings' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_UserData(lua_State *L)
{
    oluacls_class<dragonBones::UserData, dragonBones::BaseObject>(L, "db.UserData");
    oluacls_func(L, "addFloat", _olua_fun_dragonBones_UserData_addFloat);
    oluacls_func(L, "addInt", _olua_fun_dragonBones_UserData_addInt);
    oluacls_func(L, "addString", _olua_fun_dragonBones_UserData_addString);
    oluacls_func(L, "getFloat", _olua_fun_dragonBones_UserData_getFloat);
    oluacls_func(L, "getFloats", _olua_fun_dragonBones_UserData_getFloats);
    oluacls_func(L, "getInt", _olua_fun_dragonBones_UserData_getInt);
    oluacls_func(L, "getInts", _olua_fun_dragonBones_UserData_getInts);
    oluacls_func(L, "getString", _olua_fun_dragonBones_UserData_getString);
    oluacls_func(L, "getStrings", _olua_fun_dragonBones_UserData_getStrings);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_UserData_getTypeIndex);
    oluacls_func(L, "new", _olua_fun_dragonBones_UserData_new);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_UserData_getTypeIndex, nullptr);
    oluacls_prop(L, "ints", _olua_fun_dragonBones_UserData_ints, _olua_fun_dragonBones_UserData_ints);
    oluacls_prop(L, "floats", _olua_fun_dragonBones_UserData_floats, _olua_fun_dragonBones_UserData_floats);
    oluacls_prop(L, "strings", _olua_fun_dragonBones_UserData_strings, _olua_fun_dragonBones_UserData_strings);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_UserData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.UserData")) {
        luaL_error(L, "class not found: dragonBones::UserData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_BoundingBoxData_color$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoundingBoxData");

    // unsigned int color
    unsigned int ret = self->color;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxData_color$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    unsigned int arg1 = 0;       /** color */

    olua_to_object(L, 1, &self, "db.BoundingBoxData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int color
    self->color = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoundingBoxData_color(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int color
        return _olua_fun_dragonBones_BoundingBoxData_color$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoundingBoxData")) && (olua_is_integer(L, 2))) {
            // unsigned int color
            return _olua_fun_dragonBones_BoundingBoxData_color$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoundingBoxData::color' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoundingBoxData_containsPoint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    float arg1 = 0;       /** pX */
    float arg2 = 0;       /** pY */

    olua_to_object(L, 1, &self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // bool containsPoint(float pX, float pY)
    bool ret = self->containsPoint(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxData_getType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoundingBoxData");

    // int getType()
    int ret = self->getType();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxData_height$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoundingBoxData");

    // float height
    float ret = self->height;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxData_height$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    float arg1 = 0;       /** height */

    olua_to_object(L, 1, &self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);

    // float height
    self->height = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoundingBoxData_height(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float height
        return _olua_fun_dragonBones_BoundingBoxData_height$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoundingBoxData")) && (olua_is_number(L, 2))) {
            // float height
            return _olua_fun_dragonBones_BoundingBoxData_height$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoundingBoxData::height' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoundingBoxData_intersectsSegment$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */
    dragonBones::Point *arg7 = nullptr;       /** normalRadians */

    olua_to_object(L, 1, &self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "db.Point");
    olua_check_object(L, 7, &arg6, "db.Point");
    olua_check_object(L, 8, &arg7, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    int ret = self->intersectsSegment(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxData_intersectsSegment$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */

    olua_to_object(L, 1, &self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // int intersectsSegment(float xA, float yA, float xB, float yB)
    int ret = self->intersectsSegment(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxData_intersectsSegment$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */

    olua_to_object(L, 1, &self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA)
    int ret = self->intersectsSegment(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxData_intersectsSegment$4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */

    olua_to_object(L, 1, &self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "db.Point");
    olua_check_object(L, 7, &arg6, "db.Point");

    // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB)
    int ret = self->intersectsSegment(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxData_intersectsSegment(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "db.BoundingBoxData")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB)
            return _olua_fun_dragonBones_BoundingBoxData_intersectsSegment$2(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "db.BoundingBoxData")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_object(L, 6, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA)
            return _olua_fun_dragonBones_BoundingBoxData_intersectsSegment$3(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "db.BoundingBoxData")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_object(L, 6, "db.Point")) && (olua_is_object(L, 7, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB)
            return _olua_fun_dragonBones_BoundingBoxData_intersectsSegment$4(L);
        // }
    }

    if (num_args == 8) {
        // if ((olua_is_object(L, 1, "db.BoundingBoxData")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_object(L, 6, "db.Point")) && (olua_is_object(L, 7, "db.Point")) && (olua_is_object(L, 8, "db.Point"))) {
            // int intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _olua_fun_dragonBones_BoundingBoxData_intersectsSegment$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoundingBoxData::intersectsSegment' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoundingBoxData_setType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.BoundingBoxData");
    olua_check_integer(L, 2, &arg1);

    // void setType(int value)
    self->setType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoundingBoxData_type$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoundingBoxData");

    // dragonBones::BoundingBoxType type
    dragonBones::BoundingBoxType ret = self->type;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxData_type$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    dragonBones::BoundingBoxType arg1 = (dragonBones::BoundingBoxType)0;       /** type */

    olua_to_object(L, 1, &self, "db.BoundingBoxData");
    olua_check_enum(L, 2, &arg1);

    // dragonBones::BoundingBoxType type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoundingBoxData_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::BoundingBoxType type
        return _olua_fun_dragonBones_BoundingBoxData_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoundingBoxData")) && (olua_is_enum(L, 2))) {
            // dragonBones::BoundingBoxType type
            return _olua_fun_dragonBones_BoundingBoxData_type$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoundingBoxData::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoundingBoxData_width$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoundingBoxData");

    // float width
    float ret = self->width;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxData_width$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxData *self = nullptr;
    float arg1 = 0;       /** width */

    olua_to_object(L, 1, &self, "db.BoundingBoxData");
    olua_check_number(L, 2, &arg1);

    // float width
    self->width = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoundingBoxData_width(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float width
        return _olua_fun_dragonBones_BoundingBoxData_width$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoundingBoxData")) && (olua_is_number(L, 2))) {
            // float width
            return _olua_fun_dragonBones_BoundingBoxData_width$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoundingBoxData::width' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_BoundingBoxData(lua_State *L)
{
    oluacls_class<dragonBones::BoundingBoxData, dragonBones::BaseObject>(L, "db.BoundingBoxData");
    oluacls_func(L, "containsPoint", _olua_fun_dragonBones_BoundingBoxData_containsPoint);
    oluacls_func(L, "getType", _olua_fun_dragonBones_BoundingBoxData_getType);
    oluacls_func(L, "intersectsSegment", _olua_fun_dragonBones_BoundingBoxData_intersectsSegment);
    oluacls_func(L, "setType", _olua_fun_dragonBones_BoundingBoxData_setType);
    oluacls_prop(L, "type", _olua_fun_dragonBones_BoundingBoxData_type, _olua_fun_dragonBones_BoundingBoxData_type);
    oluacls_prop(L, "color", _olua_fun_dragonBones_BoundingBoxData_color, _olua_fun_dragonBones_BoundingBoxData_color);
    oluacls_prop(L, "width", _olua_fun_dragonBones_BoundingBoxData_width, _olua_fun_dragonBones_BoundingBoxData_width);
    oluacls_prop(L, "height", _olua_fun_dragonBones_BoundingBoxData_height, _olua_fun_dragonBones_BoundingBoxData_height);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_BoundingBoxData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.BoundingBoxData")) {
        luaL_error(L, "class not found: dragonBones::BoundingBoxData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_BoundingBoxDisplayData_boundingBox$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxDisplayData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoundingBoxDisplayData");

    // dragonBones::BoundingBoxData *boundingBox
    dragonBones::BoundingBoxData *ret = self->boundingBox;
    int num_ret = olua_push_object(L, ret, "db.BoundingBoxData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxDisplayData_boundingBox$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxDisplayData *self = nullptr;
    dragonBones::BoundingBoxData *arg1 = nullptr;       /** boundingBox */

    olua_to_object(L, 1, &self, "db.BoundingBoxDisplayData");
    olua_check_object(L, 2, &arg1, "db.BoundingBoxData");

    // dragonBones::BoundingBoxData *boundingBox
    self->boundingBox = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoundingBoxDisplayData_boundingBox(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::BoundingBoxData *boundingBox
        return _olua_fun_dragonBones_BoundingBoxDisplayData_boundingBox$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoundingBoxDisplayData")) && (olua_is_object(L, 2, "db.BoundingBoxData"))) {
            // dragonBones::BoundingBoxData *boundingBox
            return _olua_fun_dragonBones_BoundingBoxDisplayData_boundingBox$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoundingBoxDisplayData::boundingBox' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoundingBoxDisplayData_getBoundingBox(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxDisplayData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoundingBoxDisplayData");

    // const dragonBones::BoundingBoxData *getBoundingBox()
    const dragonBones::BoundingBoxData *ret = self->getBoundingBox();
    int num_ret = olua_push_object(L, ret, "db.BoundingBoxData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxDisplayData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::BoundingBoxDisplayData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxDisplayData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::BoundingBoxDisplayData()
    dragonBones::BoundingBoxDisplayData *ret = new dragonBones::BoundingBoxDisplayData();
    int num_ret = olua_push_object(L, ret, "db.BoundingBoxDisplayData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoundingBoxDisplayData_setBoundingBox(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoundingBoxDisplayData *self = nullptr;
    dragonBones::BoundingBoxData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.BoundingBoxDisplayData");
    olua_check_object(L, 2, &arg1, "db.BoundingBoxData");

    // void setBoundingBox(dragonBones::BoundingBoxData *value)
    self->setBoundingBox(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_db_BoundingBoxDisplayData(lua_State *L)
{
    oluacls_class<dragonBones::BoundingBoxDisplayData, dragonBones::DisplayData>(L, "db.BoundingBoxDisplayData");
    oluacls_func(L, "getBoundingBox", _olua_fun_dragonBones_BoundingBoxDisplayData_getBoundingBox);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_BoundingBoxDisplayData_getTypeIndex);
    oluacls_func(L, "new", _olua_fun_dragonBones_BoundingBoxDisplayData_new);
    oluacls_func(L, "setBoundingBox", _olua_fun_dragonBones_BoundingBoxDisplayData_setBoundingBox);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_BoundingBoxDisplayData_getTypeIndex, nullptr);
    oluacls_prop(L, "boundingBox", _olua_fun_dragonBones_BoundingBoxDisplayData_boundingBox, _olua_fun_dragonBones_BoundingBoxDisplayData_boundingBox);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_BoundingBoxDisplayData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.BoundingBoxDisplayData")) {
        luaL_error(L, "class not found: dragonBones::BoundingBoxDisplayData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_CanvasData_aabb$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.CanvasData");

    // dragonBones::Rectangle aabb
    dragonBones::Rectangle &ret = self->aabb;
    int num_ret = olua_copy_object(L, ret, "db.Rectangle");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CanvasData_aabb$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;
    dragonBones::Rectangle *arg1;       /** aabb */

    olua_to_object(L, 1, &self, "db.CanvasData");
    olua_check_object(L, 2, &arg1, "db.Rectangle");

    // dragonBones::Rectangle aabb
    self->aabb = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_CanvasData_aabb(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::Rectangle aabb
        return _olua_fun_dragonBones_CanvasData_aabb$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.CanvasData")) && (olua_is_object(L, 2, "db.Rectangle"))) {
            // dragonBones::Rectangle aabb
            return _olua_fun_dragonBones_CanvasData_aabb$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CanvasData::aabb' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_CanvasData_color$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.CanvasData");

    // unsigned int color
    unsigned int ret = self->color;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CanvasData_color$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;
    unsigned int arg1 = 0;       /** color */

    olua_to_object(L, 1, &self, "db.CanvasData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int color
    self->color = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_CanvasData_color(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int color
        return _olua_fun_dragonBones_CanvasData_color$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.CanvasData")) && (olua_is_integer(L, 2))) {
            // unsigned int color
            return _olua_fun_dragonBones_CanvasData_color$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CanvasData::color' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_CanvasData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::CanvasData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CanvasData_hasBackground$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.CanvasData");

    // bool hasBackground
    bool ret = self->hasBackground;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CanvasData_hasBackground$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CanvasData *self = nullptr;
    bool arg1 = false;       /** hasBackground */

    olua_to_object(L, 1, &self, "db.CanvasData");
    olua_check_bool(L, 2, &arg1);

    // bool hasBackground
    self->hasBackground = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_CanvasData_hasBackground(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool hasBackground
        return _olua_fun_dragonBones_CanvasData_hasBackground$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.CanvasData")) && (olua_is_bool(L, 2))) {
            // bool hasBackground
            return _olua_fun_dragonBones_CanvasData_hasBackground$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CanvasData::hasBackground' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_CanvasData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::CanvasData()
    dragonBones::CanvasData *ret = new dragonBones::CanvasData();
    int num_ret = olua_push_object(L, ret, "db.CanvasData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_db_CanvasData(lua_State *L)
{
    oluacls_class<dragonBones::CanvasData, dragonBones::BaseObject>(L, "db.CanvasData");
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_CanvasData_getTypeIndex);
    oluacls_func(L, "new", _olua_fun_dragonBones_CanvasData_new);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_CanvasData_getTypeIndex, nullptr);
    oluacls_prop(L, "hasBackground", _olua_fun_dragonBones_CanvasData_hasBackground, _olua_fun_dragonBones_CanvasData_hasBackground);
    oluacls_prop(L, "color", _olua_fun_dragonBones_CanvasData_color, _olua_fun_dragonBones_CanvasData_color);
    oluacls_prop(L, "aabb", _olua_fun_dragonBones_CanvasData_aabb, _olua_fun_dragonBones_CanvasData_aabb);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_CanvasData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.CanvasData")) {
        luaL_error(L, "class not found: dragonBones::CanvasData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_TextureAtlasData_addTexture(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    dragonBones::TextureData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.TextureAtlasData");
    olua_check_object(L, 2, &arg1, "db.TextureData");

    // void addTexture(dragonBones::TextureData *value)
    self->addTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_autoSearch$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureAtlasData");

    // bool autoSearch
    bool ret = self->autoSearch;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureAtlasData_autoSearch$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    bool arg1 = false;       /** autoSearch */

    olua_to_object(L, 1, &self, "db.TextureAtlasData");
    olua_check_bool(L, 2, &arg1);

    // bool autoSearch
    self->autoSearch = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_autoSearch(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool autoSearch
        return _olua_fun_dragonBones_TextureAtlasData_autoSearch$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureAtlasData")) && (olua_is_bool(L, 2))) {
            // bool autoSearch
            return _olua_fun_dragonBones_TextureAtlasData_autoSearch$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureAtlasData::autoSearch' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_createTexture(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureAtlasData");

    // dragonBones::TextureData *createTexture()
    dragonBones::TextureData *ret = self->createTexture();
    int num_ret = olua_push_object(L, ret, "db.TextureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureAtlasData_format$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureAtlasData");

    // dragonBones::TextureFormat format
    dragonBones::TextureFormat ret = self->format;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureAtlasData_format$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    dragonBones::TextureFormat arg1 = (dragonBones::TextureFormat)0;       /** format */

    olua_to_object(L, 1, &self, "db.TextureAtlasData");
    olua_check_enum(L, 2, &arg1);

    // dragonBones::TextureFormat format
    self->format = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_format(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::TextureFormat format
        return _olua_fun_dragonBones_TextureAtlasData_format$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureAtlasData")) && (olua_is_enum(L, 2))) {
            // dragonBones::TextureFormat format
            return _olua_fun_dragonBones_TextureAtlasData_format$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureAtlasData::format' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_getTexture(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    std::string arg1;       /** textureName */

    olua_to_object(L, 1, &self, "db.TextureAtlasData");
    olua_check_string(L, 2, &arg1);

    // dragonBones::TextureData *getTexture(const std::string &textureName)
    dragonBones::TextureData *ret = self->getTexture(arg1);
    int num_ret = olua_push_object(L, ret, "db.TextureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureAtlasData_getTextures(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureAtlasData");

    // const std::map<std::string, dragonBones::TextureData *> &getTextures()
    const std::map<std::string, dragonBones::TextureData *> &ret = self->getTextures();
    int num_ret = olua_push_map<std::string, dragonBones::TextureData *>(L, ret, [L](std::string &arg1, dragonBones::TextureData *arg2) {
        olua_push_string(L, arg1);
        olua_push_object(L, arg2, "db.TextureData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureAtlasData_height$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureAtlasData");

    // unsigned int height
    unsigned int ret = self->height;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureAtlasData_height$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    unsigned int arg1 = 0;       /** height */

    olua_to_object(L, 1, &self, "db.TextureAtlasData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int height
    self->height = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_height(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int height
        return _olua_fun_dragonBones_TextureAtlasData_height$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureAtlasData")) && (olua_is_integer(L, 2))) {
            // unsigned int height
            return _olua_fun_dragonBones_TextureAtlasData_height$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureAtlasData::height' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_imagePath$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureAtlasData");

    // std::string imagePath
    std::string ret = self->imagePath;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureAtlasData_imagePath$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    std::string arg1;       /** imagePath */

    olua_to_object(L, 1, &self, "db.TextureAtlasData");
    olua_check_string(L, 2, &arg1);

    // std::string imagePath
    self->imagePath = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_imagePath(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string imagePath
        return _olua_fun_dragonBones_TextureAtlasData_imagePath$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureAtlasData")) && (olua_is_string(L, 2))) {
            // std::string imagePath
            return _olua_fun_dragonBones_TextureAtlasData_imagePath$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureAtlasData::imagePath' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureAtlasData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureAtlasData_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.TextureAtlasData");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_TextureAtlasData_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureAtlasData")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_TextureAtlasData_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureAtlasData::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_scale$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureAtlasData");

    // float scale
    float ret = self->scale;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureAtlasData_scale$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    float arg1 = 0;       /** scale */

    olua_to_object(L, 1, &self, "db.TextureAtlasData");
    olua_check_number(L, 2, &arg1);

    // float scale
    self->scale = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_scale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float scale
        return _olua_fun_dragonBones_TextureAtlasData_scale$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureAtlasData")) && (olua_is_number(L, 2))) {
            // float scale
            return _olua_fun_dragonBones_TextureAtlasData_scale$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureAtlasData::scale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_textures$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureAtlasData");

    // std::map<std::string, dragonBones::TextureData *> textures
    std::map<std::string, dragonBones::TextureData *> &ret = self->textures;
    int num_ret = olua_push_map<std::string, dragonBones::TextureData *>(L, ret, [L](std::string &arg1, dragonBones::TextureData *arg2) {
        olua_push_string(L, arg1);
        olua_push_object(L, arg2, "db.TextureData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureAtlasData_textures$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    std::map<std::string, dragonBones::TextureData *> arg1;       /** textures */

    olua_to_object(L, 1, &self, "db.TextureAtlasData");
    olua_check_map<std::string, dragonBones::TextureData *>(L, 2, arg1, [L](std::string *arg1, dragonBones::TextureData **arg2) {
        olua_check_string(L, -1, arg1);
        olua_check_object(L, -2, arg2, "db.TextureData");
    });

    // std::map<std::string, dragonBones::TextureData *> textures
    self->textures = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_textures(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::map<std::string, dragonBones::TextureData *> textures
        return _olua_fun_dragonBones_TextureAtlasData_textures$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureAtlasData")) && (olua_is_map(L, 2))) {
            // std::map<std::string, dragonBones::TextureData *> textures
            return _olua_fun_dragonBones_TextureAtlasData_textures$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureAtlasData::textures' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_width$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureAtlasData");

    // unsigned int width
    unsigned int ret = self->width;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureAtlasData_width$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureAtlasData *self = nullptr;
    unsigned int arg1 = 0;       /** width */

    olua_to_object(L, 1, &self, "db.TextureAtlasData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int width
    self->width = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureAtlasData_width(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int width
        return _olua_fun_dragonBones_TextureAtlasData_width$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureAtlasData")) && (olua_is_integer(L, 2))) {
            // unsigned int width
            return _olua_fun_dragonBones_TextureAtlasData_width$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureAtlasData::width' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_TextureAtlasData(lua_State *L)
{
    oluacls_class<dragonBones::TextureAtlasData, dragonBones::BaseObject>(L, "db.TextureAtlasData");
    oluacls_func(L, "addTexture", _olua_fun_dragonBones_TextureAtlasData_addTexture);
    oluacls_func(L, "createTexture", _olua_fun_dragonBones_TextureAtlasData_createTexture);
    oluacls_func(L, "getTexture", _olua_fun_dragonBones_TextureAtlasData_getTexture);
    oluacls_func(L, "getTextures", _olua_fun_dragonBones_TextureAtlasData_getTextures);
    oluacls_prop(L, "autoSearch", _olua_fun_dragonBones_TextureAtlasData_autoSearch, _olua_fun_dragonBones_TextureAtlasData_autoSearch);
    oluacls_prop(L, "format", _olua_fun_dragonBones_TextureAtlasData_format, _olua_fun_dragonBones_TextureAtlasData_format);
    oluacls_prop(L, "width", _olua_fun_dragonBones_TextureAtlasData_width, _olua_fun_dragonBones_TextureAtlasData_width);
    oluacls_prop(L, "height", _olua_fun_dragonBones_TextureAtlasData_height, _olua_fun_dragonBones_TextureAtlasData_height);
    oluacls_prop(L, "scale", _olua_fun_dragonBones_TextureAtlasData_scale, _olua_fun_dragonBones_TextureAtlasData_scale);
    oluacls_prop(L, "name", _olua_fun_dragonBones_TextureAtlasData_name, _olua_fun_dragonBones_TextureAtlasData_name);
    oluacls_prop(L, "imagePath", _olua_fun_dragonBones_TextureAtlasData_imagePath, _olua_fun_dragonBones_TextureAtlasData_imagePath);
    oluacls_prop(L, "textures", _olua_fun_dragonBones_TextureAtlasData_textures, _olua_fun_dragonBones_TextureAtlasData_textures);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_TextureAtlasData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.TextureAtlasData")) {
        luaL_error(L, "class not found: dragonBones::TextureAtlasData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_TextureData_createRectangle(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::Rectangle *createRectangle()
    dragonBones::Rectangle *ret = dragonBones::TextureData::createRectangle();
    int num_ret = olua_push_object(L, ret, "db.Rectangle");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureData_frame$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureData");

    // dragonBones::Rectangle *frame
    dragonBones::Rectangle *ret = self->frame;
    int num_ret = olua_push_object(L, ret, "db.Rectangle");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureData_frame$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    dragonBones::Rectangle *arg1 = nullptr;       /** frame */

    olua_to_object(L, 1, &self, "db.TextureData");
    olua_check_object(L, 2, &arg1, "db.Rectangle");

    // dragonBones::Rectangle *frame
    self->frame = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureData_frame(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::Rectangle *frame
        return _olua_fun_dragonBones_TextureData_frame$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureData")) && (olua_is_object(L, 2, "db.Rectangle"))) {
            // dragonBones::Rectangle *frame
            return _olua_fun_dragonBones_TextureData_frame$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureData::frame' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureData_getFrame(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureData");

    // const dragonBones::Rectangle *getFrame()
    const dragonBones::Rectangle *ret = self->getFrame();
    int num_ret = olua_push_object(L, ret, "db.Rectangle");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureData");

    // const dragonBones::TextureAtlasData *getParent()
    const dragonBones::TextureAtlasData *ret = self->getParent();
    int num_ret = olua_push_object(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureData_getRegion(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureData");

    // dragonBones::Rectangle *getRegion()
    dragonBones::Rectangle *ret = self->getRegion();
    int num_ret = olua_push_object(L, ret, "db.Rectangle");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureData_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureData_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.TextureData");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureData_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_TextureData_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureData")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_TextureData_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureData::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureData_parent$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureData");

    // dragonBones::TextureAtlasData *parent
    dragonBones::TextureAtlasData *ret = self->parent;
    int num_ret = olua_push_object(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureData_parent$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    dragonBones::TextureAtlasData *arg1 = nullptr;       /** parent */

    olua_to_object(L, 1, &self, "db.TextureData");
    olua_check_object(L, 2, &arg1, "db.TextureAtlasData");

    // dragonBones::TextureAtlasData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureData_parent(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::TextureAtlasData *parent
        return _olua_fun_dragonBones_TextureData_parent$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureData")) && (olua_is_object(L, 2, "db.TextureAtlasData"))) {
            // dragonBones::TextureAtlasData *parent
            return _olua_fun_dragonBones_TextureData_parent$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureData::parent' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureData_region$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureData");

    // dragonBones::Rectangle region
    dragonBones::Rectangle &ret = self->region;
    int num_ret = olua_copy_object(L, ret, "db.Rectangle");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureData_region$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    dragonBones::Rectangle *arg1;       /** region */

    olua_to_object(L, 1, &self, "db.TextureData");
    olua_check_object(L, 2, &arg1, "db.Rectangle");

    // dragonBones::Rectangle region
    self->region = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureData_region(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::Rectangle region
        return _olua_fun_dragonBones_TextureData_region$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureData")) && (olua_is_object(L, 2, "db.Rectangle"))) {
            // dragonBones::Rectangle region
            return _olua_fun_dragonBones_TextureData_region$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureData::region' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureData_rotated$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.TextureData");

    // bool rotated
    bool ret = self->rotated;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_TextureData_rotated$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    bool arg1 = false;       /** rotated */

    olua_to_object(L, 1, &self, "db.TextureData");
    olua_check_bool(L, 2, &arg1);

    // bool rotated
    self->rotated = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureData_rotated(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool rotated
        return _olua_fun_dragonBones_TextureData_rotated$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.TextureData")) && (olua_is_bool(L, 2))) {
            // bool rotated
            return _olua_fun_dragonBones_TextureData_rotated$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::TextureData::rotated' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_TextureData_setFrame(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    dragonBones::Rectangle *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.TextureData");
    olua_check_object(L, 2, &arg1, "db.Rectangle");

    // void setFrame(dragonBones::Rectangle *value)
    self->setFrame(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_TextureData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::TextureData *self = nullptr;
    dragonBones::TextureAtlasData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.TextureData");
    olua_check_object(L, 2, &arg1, "db.TextureAtlasData");

    // void setParent(dragonBones::TextureAtlasData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_db_TextureData(lua_State *L)
{
    oluacls_class<dragonBones::TextureData, dragonBones::BaseObject>(L, "db.TextureData");
    oluacls_func(L, "createRectangle", _olua_fun_dragonBones_TextureData_createRectangle);
    oluacls_func(L, "getFrame", _olua_fun_dragonBones_TextureData_getFrame);
    oluacls_func(L, "getParent", _olua_fun_dragonBones_TextureData_getParent);
    oluacls_func(L, "getRegion", _olua_fun_dragonBones_TextureData_getRegion);
    oluacls_func(L, "setFrame", _olua_fun_dragonBones_TextureData_setFrame);
    oluacls_func(L, "setParent", _olua_fun_dragonBones_TextureData_setParent);
    oluacls_prop(L, "rotated", _olua_fun_dragonBones_TextureData_rotated, _olua_fun_dragonBones_TextureData_rotated);
    oluacls_prop(L, "name", _olua_fun_dragonBones_TextureData_name, _olua_fun_dragonBones_TextureData_name);
    oluacls_prop(L, "region", _olua_fun_dragonBones_TextureData_region, _olua_fun_dragonBones_TextureData_region);
    oluacls_prop(L, "frame", _olua_fun_dragonBones_TextureData_frame, _olua_fun_dragonBones_TextureData_frame);
    oluacls_prop(L, "parent", _olua_fun_dragonBones_TextureData_parent, _olua_fun_dragonBones_TextureData_parent);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_TextureData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.TextureData")) {
        luaL_error(L, "class not found: dragonBones::TextureData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_ArmatureData_aabb$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // dragonBones::Rectangle aabb
    dragonBones::Rectangle &ret = self->aabb;
    int num_ret = olua_copy_object(L, ret, "db.Rectangle");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_aabb$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::Rectangle *arg1;       /** aabb */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.Rectangle");

    // dragonBones::Rectangle aabb
    self->aabb = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_aabb(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::Rectangle aabb
        return _olua_fun_dragonBones_ArmatureData_aabb$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_object(L, 2, "db.Rectangle"))) {
            // dragonBones::Rectangle aabb
            return _olua_fun_dragonBones_ArmatureData_aabb$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::aabb' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_actions$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // std::vector<dragonBones::ActionData *> actions
    std::vector<dragonBones::ActionData *> &ret = self->actions;
    int num_ret = olua_push_array<dragonBones::ActionData *>(L, ret, [L](dragonBones::ActionData *arg1) {
        olua_push_object(L, arg1, "db.ActionData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_actions$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::vector<dragonBones::ActionData *> arg1;       /** actions */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_array<dragonBones::ActionData *>(L, 2, arg1, [L](dragonBones::ActionData **arg1) {
        olua_check_object(L, -1, arg1, "db.ActionData");
    });

    // std::vector<dragonBones::ActionData *> actions
    self->actions = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_actions(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<dragonBones::ActionData *> actions
        return _olua_fun_dragonBones_ArmatureData_actions$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_array(L, 2))) {
            // std::vector<dragonBones::ActionData *> actions
            return _olua_fun_dragonBones_ArmatureData_actions$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::actions' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_addAction(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::ActionData *arg1 = nullptr;       /** value */
    bool arg2 = false;       /** isDefault */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.ActionData");
    olua_check_bool(L, 3, &arg2);

    // void addAction(dragonBones::ActionData *value, bool isDefault)
    self->addAction(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_addAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::AnimationData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.AnimationData");

    // void addAnimation(dragonBones::AnimationData *value)
    self->addAnimation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_addBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // void addBone(dragonBones::BoneData *value)
    self->addBone(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_addConstraint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::ConstraintData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.ConstraintData");

    // void addConstraint(dragonBones::ConstraintData *value)
    self->addConstraint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_addSkin(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::SkinData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.SkinData");

    // void addSkin(dragonBones::SkinData *value)
    self->addSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_addSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::SlotData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.SlotData");

    // void addSlot(dragonBones::SlotData *value)
    self->addSlot(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_animationNames$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // std::vector<std::string> animationNames
    std::vector<std::string> &ret = self->animationNames;
    int num_ret = olua_push_array<std::string>(L, ret, [L](std::string &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_animationNames$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::vector<std::string> arg1;       /** animationNames */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_array<std::string>(L, 2, arg1, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // std::vector<std::string> animationNames
    self->animationNames = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_animationNames(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<std::string> animationNames
        return _olua_fun_dragonBones_ArmatureData_animationNames$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_array(L, 2))) {
            // std::vector<std::string> animationNames
            return _olua_fun_dragonBones_ArmatureData_animationNames$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::animationNames' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_animations$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // std::map<std::string, dragonBones::AnimationData *> animations
    std::map<std::string, dragonBones::AnimationData *> &ret = self->animations;
    int num_ret = olua_push_map<std::string, dragonBones::AnimationData *>(L, ret, [L](std::string &arg1, dragonBones::AnimationData *arg2) {
        olua_push_string(L, arg1);
        olua_push_object(L, arg2, "db.AnimationData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_animations$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::map<std::string, dragonBones::AnimationData *> arg1;       /** animations */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_map<std::string, dragonBones::AnimationData *>(L, 2, arg1, [L](std::string *arg1, dragonBones::AnimationData **arg2) {
        olua_check_string(L, -1, arg1);
        olua_check_object(L, -2, arg2, "db.AnimationData");
    });

    // std::map<std::string, dragonBones::AnimationData *> animations
    self->animations = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_animations(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::map<std::string, dragonBones::AnimationData *> animations
        return _olua_fun_dragonBones_ArmatureData_animations$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_map(L, 2))) {
            // std::map<std::string, dragonBones::AnimationData *> animations
            return _olua_fun_dragonBones_ArmatureData_animations$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::animations' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_bones$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // std::map<std::string, dragonBones::BoneData *> bones
    std::map<std::string, dragonBones::BoneData *> &ret = self->bones;
    int num_ret = olua_push_map<std::string, dragonBones::BoneData *>(L, ret, [L](std::string &arg1, dragonBones::BoneData *arg2) {
        olua_push_string(L, arg1);
        olua_push_object(L, arg2, "db.BoneData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_bones$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::map<std::string, dragonBones::BoneData *> arg1;       /** bones */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_map<std::string, dragonBones::BoneData *>(L, 2, arg1, [L](std::string *arg1, dragonBones::BoneData **arg2) {
        olua_check_string(L, -1, arg1);
        olua_check_object(L, -2, arg2, "db.BoneData");
    });

    // std::map<std::string, dragonBones::BoneData *> bones
    self->bones = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_bones(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::map<std::string, dragonBones::BoneData *> bones
        return _olua_fun_dragonBones_ArmatureData_bones$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_map(L, 2))) {
            // std::map<std::string, dragonBones::BoneData *> bones
            return _olua_fun_dragonBones_ArmatureData_bones$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::bones' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_cacheFrameRate$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // unsigned int cacheFrameRate
    unsigned int ret = self->cacheFrameRate;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_cacheFrameRate$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    unsigned int arg1 = 0;       /** cacheFrameRate */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int cacheFrameRate
    self->cacheFrameRate = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_cacheFrameRate(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int cacheFrameRate
        return _olua_fun_dragonBones_ArmatureData_cacheFrameRate$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_integer(L, 2))) {
            // unsigned int cacheFrameRate
            return _olua_fun_dragonBones_ArmatureData_cacheFrameRate$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::cacheFrameRate' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_cacheFrames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    unsigned int arg1 = 0;       /** frameRate */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_integer(L, 2, &arg1);

    // void cacheFrames(unsigned int frameRate)
    self->cacheFrames(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_canvas$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // dragonBones::CanvasData *canvas
    dragonBones::CanvasData *ret = self->canvas;
    int num_ret = olua_push_object(L, ret, "db.CanvasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_canvas$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::CanvasData *arg1 = nullptr;       /** canvas */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.CanvasData");

    // dragonBones::CanvasData *canvas
    self->canvas = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_canvas(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::CanvasData *canvas
        return _olua_fun_dragonBones_ArmatureData_canvas$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_object(L, 2, "db.CanvasData"))) {
            // dragonBones::CanvasData *canvas
            return _olua_fun_dragonBones_ArmatureData_canvas$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::canvas' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_constraints$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // std::map<std::string, dragonBones::ConstraintData *> constraints
    std::map<std::string, dragonBones::ConstraintData *> &ret = self->constraints;
    int num_ret = olua_push_map<std::string, dragonBones::ConstraintData *>(L, ret, [L](std::string &arg1, dragonBones::ConstraintData *arg2) {
        olua_push_string(L, arg1);
        olua_push_object(L, arg2, "db.ConstraintData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_constraints$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::map<std::string, dragonBones::ConstraintData *> arg1;       /** constraints */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_map<std::string, dragonBones::ConstraintData *>(L, 2, arg1, [L](std::string *arg1, dragonBones::ConstraintData **arg2) {
        olua_check_string(L, -1, arg1);
        olua_check_object(L, -2, arg2, "db.ConstraintData");
    });

    // std::map<std::string, dragonBones::ConstraintData *> constraints
    self->constraints = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_constraints(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::map<std::string, dragonBones::ConstraintData *> constraints
        return _olua_fun_dragonBones_ArmatureData_constraints$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_map(L, 2))) {
            // std::map<std::string, dragonBones::ConstraintData *> constraints
            return _olua_fun_dragonBones_ArmatureData_constraints$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::constraints' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_defaultActions$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // std::vector<dragonBones::ActionData *> defaultActions
    std::vector<dragonBones::ActionData *> &ret = self->defaultActions;
    int num_ret = olua_push_array<dragonBones::ActionData *>(L, ret, [L](dragonBones::ActionData *arg1) {
        olua_push_object(L, arg1, "db.ActionData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_defaultActions$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::vector<dragonBones::ActionData *> arg1;       /** defaultActions */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_array<dragonBones::ActionData *>(L, 2, arg1, [L](dragonBones::ActionData **arg1) {
        olua_check_object(L, -1, arg1, "db.ActionData");
    });

    // std::vector<dragonBones::ActionData *> defaultActions
    self->defaultActions = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_defaultActions(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<dragonBones::ActionData *> defaultActions
        return _olua_fun_dragonBones_ArmatureData_defaultActions$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_array(L, 2))) {
            // std::vector<dragonBones::ActionData *> defaultActions
            return _olua_fun_dragonBones_ArmatureData_defaultActions$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::defaultActions' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_defaultAnimation$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // dragonBones::AnimationData *defaultAnimation
    dragonBones::AnimationData *ret = self->defaultAnimation;
    int num_ret = olua_push_object(L, ret, "db.AnimationData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_defaultAnimation$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::AnimationData *arg1 = nullptr;       /** defaultAnimation */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.AnimationData");

    // dragonBones::AnimationData *defaultAnimation
    self->defaultAnimation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_defaultAnimation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::AnimationData *defaultAnimation
        return _olua_fun_dragonBones_ArmatureData_defaultAnimation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_object(L, 2, "db.AnimationData"))) {
            // dragonBones::AnimationData *defaultAnimation
            return _olua_fun_dragonBones_ArmatureData_defaultAnimation$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::defaultAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_defaultSkin$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // dragonBones::SkinData *defaultSkin
    dragonBones::SkinData *ret = self->defaultSkin;
    int num_ret = olua_push_object(L, ret, "db.SkinData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_defaultSkin$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::SkinData *arg1 = nullptr;       /** defaultSkin */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.SkinData");

    // dragonBones::SkinData *defaultSkin
    self->defaultSkin = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_defaultSkin(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::SkinData *defaultSkin
        return _olua_fun_dragonBones_ArmatureData_defaultSkin$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_object(L, 2, "db.SkinData"))) {
            // dragonBones::SkinData *defaultSkin
            return _olua_fun_dragonBones_ArmatureData_defaultSkin$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::defaultSkin' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_frameRate$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // unsigned int frameRate
    unsigned int ret = self->frameRate;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_frameRate$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    unsigned int arg1 = 0;       /** frameRate */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int frameRate
    self->frameRate = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_frameRate(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int frameRate
        return _olua_fun_dragonBones_ArmatureData_frameRate$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_integer(L, 2))) {
            // unsigned int frameRate
            return _olua_fun_dragonBones_ArmatureData_frameRate$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::frameRate' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_getAABB(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // dragonBones::Rectangle *getAABB()
    dragonBones::Rectangle *ret = self->getAABB();
    int num_ret = olua_push_object(L, ret, "db.Rectangle");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getActions(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // const std::vector<dragonBones::ActionData *> &getActions()
    const std::vector<dragonBones::ActionData *> &ret = self->getActions();
    int num_ret = olua_push_array<dragonBones::ActionData *>(L, ret, [L](dragonBones::ActionData *arg1) {
        olua_push_object(L, arg1, "db.ActionData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_string(L, 2, &arg1);

    // dragonBones::AnimationData *getAnimation(const std::string &animationName)
    dragonBones::AnimationData *ret = self->getAnimation(arg1);
    int num_ret = olua_push_object(L, ret, "db.AnimationData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getAnimationNames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // const std::vector<std::string> &getAnimationNames()
    const std::vector<std::string> &ret = self->getAnimationNames();
    int num_ret = olua_push_array<std::string>(L, ret, [L](std::string &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_string(L, 2, &arg1);

    // dragonBones::BoneData *getBone(const std::string &boneName)
    dragonBones::BoneData *ret = self->getBone(arg1);
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getConstraint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** constraintName */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_string(L, 2, &arg1);

    // dragonBones::ConstraintData *getConstraint(const std::string &constraintName)
    dragonBones::ConstraintData *ret = self->getConstraint(arg1);
    int num_ret = olua_push_object(L, ret, "db.ConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getDefaultActions(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // const std::vector<dragonBones::ActionData *> &getDefaultActions()
    const std::vector<dragonBones::ActionData *> &ret = self->getDefaultActions();
    int num_ret = olua_push_array<dragonBones::ActionData *>(L, ret, [L](dragonBones::ActionData *arg1) {
        olua_push_object(L, arg1, "db.ActionData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getDefaultAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // dragonBones::AnimationData *getDefaultAnimation()
    dragonBones::AnimationData *ret = self->getDefaultAnimation();
    int num_ret = olua_push_object(L, ret, "db.AnimationData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getDefaultSkin(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // dragonBones::SkinData *getDefaultSkin()
    dragonBones::SkinData *ret = self->getDefaultSkin();
    int num_ret = olua_push_object(L, ret, "db.SkinData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // const dragonBones::DragonBonesData *getParent()
    const dragonBones::DragonBonesData *ret = self->getParent();
    int num_ret = olua_push_object(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getSkin(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** skinName */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_string(L, 2, &arg1);

    // dragonBones::SkinData *getSkin(const std::string &skinName)
    dragonBones::SkinData *ret = self->getSkin(arg1);
    int num_ret = olua_push_object(L, ret, "db.SkinData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** slotName */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_string(L, 2, &arg1);

    // dragonBones::SlotData *getSlot(const std::string &slotName)
    dragonBones::SlotData *ret = self->getSlot(arg1);
    int num_ret = olua_push_object(L, ret, "db.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getSortedBones(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // const std::vector<dragonBones::BoneData *> &getSortedBones()
    const std::vector<dragonBones::BoneData *> &ret = self->getSortedBones();
    int num_ret = olua_push_array<dragonBones::BoneData *>(L, ret, [L](dragonBones::BoneData *arg1) {
        olua_push_object(L, arg1, "db.BoneData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getSortedSlots(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // const std::vector<dragonBones::SlotData *> &getSortedSlots()
    const std::vector<dragonBones::SlotData *> &ret = self->getSortedSlots();
    int num_ret = olua_push_array<dragonBones::SlotData *>(L, ret, [L](dragonBones::SlotData *arg1) {
        olua_push_object(L, arg1, "db.SlotData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // int getType()
    int ret = self->getType();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::ArmatureData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // const dragonBones::UserData *getUserData()
    const dragonBones::UserData *ret = self->getUserData();
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_ArmatureData_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_ArmatureData_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::ArmatureData()
    dragonBones::ArmatureData *ret = new dragonBones::ArmatureData();
    int num_ret = olua_push_object(L, ret, "db.ArmatureData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_parent$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // dragonBones::DragonBonesData *parent
    dragonBones::DragonBonesData *ret = self->parent;
    int num_ret = olua_push_object(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_parent$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::DragonBonesData *arg1 = nullptr;       /** parent */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.DragonBonesData");

    // dragonBones::DragonBonesData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_parent(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::DragonBonesData *parent
        return _olua_fun_dragonBones_ArmatureData_parent$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_object(L, 2, "db.DragonBonesData"))) {
            // dragonBones::DragonBonesData *parent
            return _olua_fun_dragonBones_ArmatureData_parent$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::parent' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_scale$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // float scale
    float ret = self->scale;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_scale$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    float arg1 = 0;       /** scale */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_number(L, 2, &arg1);

    // float scale
    self->scale = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_scale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float scale
        return _olua_fun_dragonBones_ArmatureData_scale$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_number(L, 2))) {
            // float scale
            return _olua_fun_dragonBones_ArmatureData_scale$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::scale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_setDefaultAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::AnimationData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.AnimationData");

    // void setDefaultAnimation(dragonBones::AnimationData *value)
    self->setDefaultAnimation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_setDefaultSkin(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::SkinData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.SkinData");

    // void setDefaultSkin(dragonBones::SkinData *value)
    self->setDefaultSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::DragonBonesData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.DragonBonesData");

    // void setParent(dragonBones::DragonBonesData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_setType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_integer(L, 2, &arg1);

    // void setType(int value)
    self->setType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_setUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.UserData");

    // void setUserData(dragonBones::UserData *value)
    self->setUserData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_skins$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // std::map<std::string, dragonBones::SkinData *> skins
    std::map<std::string, dragonBones::SkinData *> &ret = self->skins;
    int num_ret = olua_push_map<std::string, dragonBones::SkinData *>(L, ret, [L](std::string &arg1, dragonBones::SkinData *arg2) {
        olua_push_string(L, arg1);
        olua_push_object(L, arg2, "db.SkinData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_skins$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::map<std::string, dragonBones::SkinData *> arg1;       /** skins */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_map<std::string, dragonBones::SkinData *>(L, 2, arg1, [L](std::string *arg1, dragonBones::SkinData **arg2) {
        olua_check_string(L, -1, arg1);
        olua_check_object(L, -2, arg2, "db.SkinData");
    });

    // std::map<std::string, dragonBones::SkinData *> skins
    self->skins = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_skins(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::map<std::string, dragonBones::SkinData *> skins
        return _olua_fun_dragonBones_ArmatureData_skins$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_map(L, 2))) {
            // std::map<std::string, dragonBones::SkinData *> skins
            return _olua_fun_dragonBones_ArmatureData_skins$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::skins' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_slots$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // std::map<std::string, dragonBones::SlotData *> slots
    std::map<std::string, dragonBones::SlotData *> &ret = self->slots;
    int num_ret = olua_push_map<std::string, dragonBones::SlotData *>(L, ret, [L](std::string &arg1, dragonBones::SlotData *arg2) {
        olua_push_string(L, arg1);
        olua_push_object(L, arg2, "db.SlotData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_slots$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::map<std::string, dragonBones::SlotData *> arg1;       /** slots */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_map<std::string, dragonBones::SlotData *>(L, 2, arg1, [L](std::string *arg1, dragonBones::SlotData **arg2) {
        olua_check_string(L, -1, arg1);
        olua_check_object(L, -2, arg2, "db.SlotData");
    });

    // std::map<std::string, dragonBones::SlotData *> slots
    self->slots = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_slots(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::map<std::string, dragonBones::SlotData *> slots
        return _olua_fun_dragonBones_ArmatureData_slots$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_map(L, 2))) {
            // std::map<std::string, dragonBones::SlotData *> slots
            return _olua_fun_dragonBones_ArmatureData_slots$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::slots' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_sortBones(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // void sortBones()
    self->sortBones();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_sortedBones$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // std::vector<dragonBones::BoneData *> sortedBones
    std::vector<dragonBones::BoneData *> &ret = self->sortedBones;
    int num_ret = olua_push_array<dragonBones::BoneData *>(L, ret, [L](dragonBones::BoneData *arg1) {
        olua_push_object(L, arg1, "db.BoneData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_sortedBones$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::vector<dragonBones::BoneData *> arg1;       /** sortedBones */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_array<dragonBones::BoneData *>(L, 2, arg1, [L](dragonBones::BoneData **arg1) {
        olua_check_object(L, -1, arg1, "db.BoneData");
    });

    // std::vector<dragonBones::BoneData *> sortedBones
    self->sortedBones = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_sortedBones(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<dragonBones::BoneData *> sortedBones
        return _olua_fun_dragonBones_ArmatureData_sortedBones$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_array(L, 2))) {
            // std::vector<dragonBones::BoneData *> sortedBones
            return _olua_fun_dragonBones_ArmatureData_sortedBones$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::sortedBones' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_sortedSlots$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // std::vector<dragonBones::SlotData *> sortedSlots
    std::vector<dragonBones::SlotData *> &ret = self->sortedSlots;
    int num_ret = olua_push_array<dragonBones::SlotData *>(L, ret, [L](dragonBones::SlotData *arg1) {
        olua_push_object(L, arg1, "db.SlotData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_sortedSlots$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    std::vector<dragonBones::SlotData *> arg1;       /** sortedSlots */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_array<dragonBones::SlotData *>(L, 2, arg1, [L](dragonBones::SlotData **arg1) {
        olua_check_object(L, -1, arg1, "db.SlotData");
    });

    // std::vector<dragonBones::SlotData *> sortedSlots
    self->sortedSlots = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_sortedSlots(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<dragonBones::SlotData *> sortedSlots
        return _olua_fun_dragonBones_ArmatureData_sortedSlots$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_array(L, 2))) {
            // std::vector<dragonBones::SlotData *> sortedSlots
            return _olua_fun_dragonBones_ArmatureData_sortedSlots$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::sortedSlots' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_type$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // dragonBones::ArmatureType type
    dragonBones::ArmatureType ret = self->type;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_type$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::ArmatureType arg1 = (dragonBones::ArmatureType)0;       /** type */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_enum(L, 2, &arg1);

    // dragonBones::ArmatureType type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::ArmatureType type
        return _olua_fun_dragonBones_ArmatureData_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_enum(L, 2))) {
            // dragonBones::ArmatureType type
            return _olua_fun_dragonBones_ArmatureData_type$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_userData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureData");

    // dragonBones::UserData *userData
    dragonBones::UserData *ret = self->userData;
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_ArmatureData_userData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::ArmatureData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** userData */

    olua_to_object(L, 1, &self, "db.ArmatureData");
    olua_check_object(L, 2, &arg1, "db.UserData");

    // dragonBones::UserData *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_ArmatureData_userData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::UserData *userData
        return _olua_fun_dragonBones_ArmatureData_userData$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureData")) && (olua_is_object(L, 2, "db.UserData"))) {
            // dragonBones::UserData *userData
            return _olua_fun_dragonBones_ArmatureData_userData$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::ArmatureData::userData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_ArmatureData(lua_State *L)
{
    oluacls_class<dragonBones::ArmatureData, dragonBones::BaseObject>(L, "db.ArmatureData");
    oluacls_func(L, "addAction", _olua_fun_dragonBones_ArmatureData_addAction);
    oluacls_func(L, "addAnimation", _olua_fun_dragonBones_ArmatureData_addAnimation);
    oluacls_func(L, "addBone", _olua_fun_dragonBones_ArmatureData_addBone);
    oluacls_func(L, "addConstraint", _olua_fun_dragonBones_ArmatureData_addConstraint);
    oluacls_func(L, "addSkin", _olua_fun_dragonBones_ArmatureData_addSkin);
    oluacls_func(L, "addSlot", _olua_fun_dragonBones_ArmatureData_addSlot);
    oluacls_func(L, "cacheFrames", _olua_fun_dragonBones_ArmatureData_cacheFrames);
    oluacls_func(L, "getAABB", _olua_fun_dragonBones_ArmatureData_getAABB);
    oluacls_func(L, "getActions", _olua_fun_dragonBones_ArmatureData_getActions);
    oluacls_func(L, "getAnimation", _olua_fun_dragonBones_ArmatureData_getAnimation);
    oluacls_func(L, "getAnimationNames", _olua_fun_dragonBones_ArmatureData_getAnimationNames);
    oluacls_func(L, "getBone", _olua_fun_dragonBones_ArmatureData_getBone);
    oluacls_func(L, "getConstraint", _olua_fun_dragonBones_ArmatureData_getConstraint);
    oluacls_func(L, "getDefaultActions", _olua_fun_dragonBones_ArmatureData_getDefaultActions);
    oluacls_func(L, "getDefaultAnimation", _olua_fun_dragonBones_ArmatureData_getDefaultAnimation);
    oluacls_func(L, "getDefaultSkin", _olua_fun_dragonBones_ArmatureData_getDefaultSkin);
    oluacls_func(L, "getParent", _olua_fun_dragonBones_ArmatureData_getParent);
    oluacls_func(L, "getSkin", _olua_fun_dragonBones_ArmatureData_getSkin);
    oluacls_func(L, "getSlot", _olua_fun_dragonBones_ArmatureData_getSlot);
    oluacls_func(L, "getSortedBones", _olua_fun_dragonBones_ArmatureData_getSortedBones);
    oluacls_func(L, "getSortedSlots", _olua_fun_dragonBones_ArmatureData_getSortedSlots);
    oluacls_func(L, "getType", _olua_fun_dragonBones_ArmatureData_getType);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_ArmatureData_getTypeIndex);
    oluacls_func(L, "getUserData", _olua_fun_dragonBones_ArmatureData_getUserData);
    oluacls_func(L, "new", _olua_fun_dragonBones_ArmatureData_new);
    oluacls_func(L, "setDefaultAnimation", _olua_fun_dragonBones_ArmatureData_setDefaultAnimation);
    oluacls_func(L, "setDefaultSkin", _olua_fun_dragonBones_ArmatureData_setDefaultSkin);
    oluacls_func(L, "setParent", _olua_fun_dragonBones_ArmatureData_setParent);
    oluacls_func(L, "setType", _olua_fun_dragonBones_ArmatureData_setType);
    oluacls_func(L, "setUserData", _olua_fun_dragonBones_ArmatureData_setUserData);
    oluacls_func(L, "sortBones", _olua_fun_dragonBones_ArmatureData_sortBones);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_ArmatureData_getTypeIndex, nullptr);
    oluacls_prop(L, "type", _olua_fun_dragonBones_ArmatureData_type, _olua_fun_dragonBones_ArmatureData_type);
    oluacls_prop(L, "frameRate", _olua_fun_dragonBones_ArmatureData_frameRate, _olua_fun_dragonBones_ArmatureData_frameRate);
    oluacls_prop(L, "cacheFrameRate", _olua_fun_dragonBones_ArmatureData_cacheFrameRate, _olua_fun_dragonBones_ArmatureData_cacheFrameRate);
    oluacls_prop(L, "scale", _olua_fun_dragonBones_ArmatureData_scale, _olua_fun_dragonBones_ArmatureData_scale);
    oluacls_prop(L, "name", _olua_fun_dragonBones_ArmatureData_name, _olua_fun_dragonBones_ArmatureData_name);
    oluacls_prop(L, "aabb", _olua_fun_dragonBones_ArmatureData_aabb, _olua_fun_dragonBones_ArmatureData_aabb);
    oluacls_prop(L, "animationNames", _olua_fun_dragonBones_ArmatureData_animationNames, _olua_fun_dragonBones_ArmatureData_animationNames);
    oluacls_prop(L, "sortedBones", _olua_fun_dragonBones_ArmatureData_sortedBones, _olua_fun_dragonBones_ArmatureData_sortedBones);
    oluacls_prop(L, "sortedSlots", _olua_fun_dragonBones_ArmatureData_sortedSlots, _olua_fun_dragonBones_ArmatureData_sortedSlots);
    oluacls_prop(L, "defaultActions", _olua_fun_dragonBones_ArmatureData_defaultActions, _olua_fun_dragonBones_ArmatureData_defaultActions);
    oluacls_prop(L, "actions", _olua_fun_dragonBones_ArmatureData_actions, _olua_fun_dragonBones_ArmatureData_actions);
    oluacls_prop(L, "bones", _olua_fun_dragonBones_ArmatureData_bones, _olua_fun_dragonBones_ArmatureData_bones);
    oluacls_prop(L, "slots", _olua_fun_dragonBones_ArmatureData_slots, _olua_fun_dragonBones_ArmatureData_slots);
    oluacls_prop(L, "constraints", _olua_fun_dragonBones_ArmatureData_constraints, _olua_fun_dragonBones_ArmatureData_constraints);
    oluacls_prop(L, "skins", _olua_fun_dragonBones_ArmatureData_skins, _olua_fun_dragonBones_ArmatureData_skins);
    oluacls_prop(L, "animations", _olua_fun_dragonBones_ArmatureData_animations, _olua_fun_dragonBones_ArmatureData_animations);
    oluacls_prop(L, "defaultSkin", _olua_fun_dragonBones_ArmatureData_defaultSkin, _olua_fun_dragonBones_ArmatureData_defaultSkin);
    oluacls_prop(L, "defaultAnimation", _olua_fun_dragonBones_ArmatureData_defaultAnimation, _olua_fun_dragonBones_ArmatureData_defaultAnimation);
    oluacls_prop(L, "canvas", _olua_fun_dragonBones_ArmatureData_canvas, _olua_fun_dragonBones_ArmatureData_canvas);
    oluacls_prop(L, "userData", _olua_fun_dragonBones_ArmatureData_userData, _olua_fun_dragonBones_ArmatureData_userData);
    oluacls_prop(L, "parent", _olua_fun_dragonBones_ArmatureData_parent, _olua_fun_dragonBones_ArmatureData_parent);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_ArmatureData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.ArmatureData")) {
        luaL_error(L, "class not found: dragonBones::ArmatureData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_SkinData_addDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;
    std::string arg1;       /** slotName */
    dragonBones::DisplayData *arg2 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.SkinData");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "db.DisplayData");

    // void addDisplay(const std::string &slotName, dragonBones::DisplayData *value)
    self->addDisplay(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SkinData_getDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;
    std::string arg1;       /** slotName */
    std::string arg2;       /** displayName */

    olua_to_object(L, 1, &self, "db.SkinData");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // dragonBones::DisplayData *getDisplay(const std::string &slotName, const std::string &displayName)
    dragonBones::DisplayData *ret = self->getDisplay(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.DisplayData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SkinData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::SkinData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SkinData_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;

    olua_to_object(L, 1, &self, "db.SkinData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SkinData_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.SkinData");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SkinData_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_SkinData_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.SkinData")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_SkinData_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::SkinData::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_SkinData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::SkinData()
    dragonBones::SkinData *ret = new dragonBones::SkinData();
    int num_ret = olua_push_object(L, ret, "db.SkinData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SkinData_parent$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;

    olua_to_object(L, 1, &self, "db.SkinData");

    // dragonBones::ArmatureData *parent
    dragonBones::ArmatureData *ret = self->parent;
    int num_ret = olua_push_object(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SkinData_parent$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SkinData *self = nullptr;
    dragonBones::ArmatureData *arg1 = nullptr;       /** parent */

    olua_to_object(L, 1, &self, "db.SkinData");
    olua_check_object(L, 2, &arg1, "db.ArmatureData");

    // dragonBones::ArmatureData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SkinData_parent(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::ArmatureData *parent
        return _olua_fun_dragonBones_SkinData_parent$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.SkinData")) && (olua_is_object(L, 2, "db.ArmatureData"))) {
            // dragonBones::ArmatureData *parent
            return _olua_fun_dragonBones_SkinData_parent$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::SkinData::parent' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_SkinData(lua_State *L)
{
    oluacls_class<dragonBones::SkinData, dragonBones::BaseObject>(L, "db.SkinData");
    oluacls_func(L, "addDisplay", _olua_fun_dragonBones_SkinData_addDisplay);
    oluacls_func(L, "getDisplay", _olua_fun_dragonBones_SkinData_getDisplay);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_SkinData_getTypeIndex);
    oluacls_func(L, "new", _olua_fun_dragonBones_SkinData_new);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_SkinData_getTypeIndex, nullptr);
    oluacls_prop(L, "name", _olua_fun_dragonBones_SkinData_name, _olua_fun_dragonBones_SkinData_name);
    oluacls_prop(L, "parent", _olua_fun_dragonBones_SkinData_parent, _olua_fun_dragonBones_SkinData_parent);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_SkinData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.SkinData")) {
        luaL_error(L, "class not found: dragonBones::SkinData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_BoneData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoneData");

    // const dragonBones::BoneData *getParent()
    const dragonBones::BoneData *ret = self->getParent();
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::BoneData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoneData");

    // const dragonBones::UserData *getUserData()
    const dragonBones::UserData *ret = self->getUserData();
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_inheritReflection$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoneData");

    // bool inheritReflection
    bool ret = self->inheritReflection;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_inheritReflection$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    bool arg1 = false;       /** inheritReflection */

    olua_to_object(L, 1, &self, "db.BoneData");
    olua_check_bool(L, 2, &arg1);

    // bool inheritReflection
    self->inheritReflection = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_inheritReflection(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool inheritReflection
        return _olua_fun_dragonBones_BoneData_inheritReflection$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoneData")) && (olua_is_bool(L, 2))) {
            // bool inheritReflection
            return _olua_fun_dragonBones_BoneData_inheritReflection$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoneData::inheritReflection' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_inheritRotation$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoneData");

    // bool inheritRotation
    bool ret = self->inheritRotation;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_inheritRotation$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    bool arg1 = false;       /** inheritRotation */

    olua_to_object(L, 1, &self, "db.BoneData");
    olua_check_bool(L, 2, &arg1);

    // bool inheritRotation
    self->inheritRotation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_inheritRotation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool inheritRotation
        return _olua_fun_dragonBones_BoneData_inheritRotation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoneData")) && (olua_is_bool(L, 2))) {
            // bool inheritRotation
            return _olua_fun_dragonBones_BoneData_inheritRotation$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoneData::inheritRotation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_inheritScale$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoneData");

    // bool inheritScale
    bool ret = self->inheritScale;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_inheritScale$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    bool arg1 = false;       /** inheritScale */

    olua_to_object(L, 1, &self, "db.BoneData");
    olua_check_bool(L, 2, &arg1);

    // bool inheritScale
    self->inheritScale = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_inheritScale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool inheritScale
        return _olua_fun_dragonBones_BoneData_inheritScale$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoneData")) && (olua_is_bool(L, 2))) {
            // bool inheritScale
            return _olua_fun_dragonBones_BoneData_inheritScale$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoneData::inheritScale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_inheritTranslation$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoneData");

    // bool inheritTranslation
    bool ret = self->inheritTranslation;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_inheritTranslation$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    bool arg1 = false;       /** inheritTranslation */

    olua_to_object(L, 1, &self, "db.BoneData");
    olua_check_bool(L, 2, &arg1);

    // bool inheritTranslation
    self->inheritTranslation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_inheritTranslation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool inheritTranslation
        return _olua_fun_dragonBones_BoneData_inheritTranslation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoneData")) && (olua_is_bool(L, 2))) {
            // bool inheritTranslation
            return _olua_fun_dragonBones_BoneData_inheritTranslation$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoneData::inheritTranslation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_length$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoneData");

    // float length
    float ret = self->length;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_length$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    float arg1 = 0;       /** length */

    olua_to_object(L, 1, &self, "db.BoneData");
    olua_check_number(L, 2, &arg1);

    // float length
    self->length = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_length(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float length
        return _olua_fun_dragonBones_BoneData_length$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoneData")) && (olua_is_number(L, 2))) {
            // float length
            return _olua_fun_dragonBones_BoneData_length$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoneData::length' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoneData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.BoneData");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_BoneData_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoneData")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_BoneData_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoneData::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::BoneData()
    dragonBones::BoneData *ret = new dragonBones::BoneData();
    int num_ret = olua_push_object(L, ret, "db.BoneData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_parent$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoneData");

    // dragonBones::BoneData *parent
    dragonBones::BoneData *ret = self->parent;
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_parent$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** parent */

    olua_to_object(L, 1, &self, "db.BoneData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // dragonBones::BoneData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_parent(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::BoneData *parent
        return _olua_fun_dragonBones_BoneData_parent$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoneData")) && (olua_is_object(L, 2, "db.BoneData"))) {
            // dragonBones::BoneData *parent
            return _olua_fun_dragonBones_BoneData_parent$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoneData::parent' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.BoneData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // void setParent(dragonBones::BoneData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_setUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.BoneData");
    olua_check_object(L, 2, &arg1, "db.UserData");

    // void setUserData(dragonBones::UserData *value)
    self->setUserData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_userData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "db.BoneData");

    // dragonBones::UserData *userData
    dragonBones::UserData *ret = self->userData;
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BoneData_userData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BoneData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** userData */

    olua_to_object(L, 1, &self, "db.BoneData");
    olua_check_object(L, 2, &arg1, "db.UserData");

    // dragonBones::UserData *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BoneData_userData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::UserData *userData
        return _olua_fun_dragonBones_BoneData_userData$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BoneData")) && (olua_is_object(L, 2, "db.UserData"))) {
            // dragonBones::UserData *userData
            return _olua_fun_dragonBones_BoneData_userData$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BoneData::userData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_BoneData(lua_State *L)
{
    oluacls_class<dragonBones::BoneData, dragonBones::BaseObject>(L, "db.BoneData");
    oluacls_func(L, "getParent", _olua_fun_dragonBones_BoneData_getParent);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_BoneData_getTypeIndex);
    oluacls_func(L, "getUserData", _olua_fun_dragonBones_BoneData_getUserData);
    oluacls_func(L, "new", _olua_fun_dragonBones_BoneData_new);
    oluacls_func(L, "setParent", _olua_fun_dragonBones_BoneData_setParent);
    oluacls_func(L, "setUserData", _olua_fun_dragonBones_BoneData_setUserData);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_BoneData_getTypeIndex, nullptr);
    oluacls_prop(L, "inheritTranslation", _olua_fun_dragonBones_BoneData_inheritTranslation, _olua_fun_dragonBones_BoneData_inheritTranslation);
    oluacls_prop(L, "inheritRotation", _olua_fun_dragonBones_BoneData_inheritRotation, _olua_fun_dragonBones_BoneData_inheritRotation);
    oluacls_prop(L, "inheritScale", _olua_fun_dragonBones_BoneData_inheritScale, _olua_fun_dragonBones_BoneData_inheritScale);
    oluacls_prop(L, "inheritReflection", _olua_fun_dragonBones_BoneData_inheritReflection, _olua_fun_dragonBones_BoneData_inheritReflection);
    oluacls_prop(L, "length", _olua_fun_dragonBones_BoneData_length, _olua_fun_dragonBones_BoneData_length);
    oluacls_prop(L, "name", _olua_fun_dragonBones_BoneData_name, _olua_fun_dragonBones_BoneData_name);
    oluacls_prop(L, "userData", _olua_fun_dragonBones_BoneData_userData, _olua_fun_dragonBones_BoneData_userData);
    oluacls_prop(L, "parent", _olua_fun_dragonBones_BoneData_parent, _olua_fun_dragonBones_BoneData_parent);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_BoneData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.BoneData")) {
        luaL_error(L, "class not found: dragonBones::BoneData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_SlotData_blendMode$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "db.SlotData");

    // dragonBones::BlendMode blendMode
    dragonBones::BlendMode ret = self->blendMode;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SlotData_blendMode$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    dragonBones::BlendMode arg1 = (dragonBones::BlendMode)0;       /** blendMode */

    olua_to_object(L, 1, &self, "db.SlotData");
    olua_check_enum(L, 2, &arg1);

    // dragonBones::BlendMode blendMode
    self->blendMode = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_blendMode(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::BlendMode blendMode
        return _olua_fun_dragonBones_SlotData_blendMode$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.SlotData")) && (olua_is_enum(L, 2))) {
            // dragonBones::BlendMode blendMode
            return _olua_fun_dragonBones_SlotData_blendMode$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::SlotData::blendMode' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_displayIndex$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "db.SlotData");

    // int displayIndex
    int ret = self->displayIndex;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SlotData_displayIndex$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    int arg1 = 0;       /** displayIndex */

    olua_to_object(L, 1, &self, "db.SlotData");
    olua_check_integer(L, 2, &arg1);

    // int displayIndex
    self->displayIndex = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_displayIndex(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int displayIndex
        return _olua_fun_dragonBones_SlotData_displayIndex$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.SlotData")) && (olua_is_integer(L, 2))) {
            // int displayIndex
            return _olua_fun_dragonBones_SlotData_displayIndex$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::SlotData::displayIndex' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_getBlendMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "db.SlotData");

    // int getBlendMode()
    int ret = self->getBlendMode();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SlotData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "db.SlotData");

    // const dragonBones::BoneData *getParent()
    const dragonBones::BoneData *ret = self->getParent();
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SlotData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::SlotData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SlotData_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "db.SlotData");

    // const dragonBones::UserData *getUserData()
    const dragonBones::UserData *ret = self->getUserData();
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SlotData_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "db.SlotData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SlotData_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.SlotData");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_SlotData_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.SlotData")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_SlotData_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::SlotData::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::SlotData()
    dragonBones::SlotData *ret = new dragonBones::SlotData();
    int num_ret = olua_push_object(L, ret, "db.SlotData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SlotData_parent$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "db.SlotData");

    // dragonBones::BoneData *parent
    dragonBones::BoneData *ret = self->parent;
    int num_ret = olua_push_object(L, ret, "db.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SlotData_parent$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** parent */

    olua_to_object(L, 1, &self, "db.SlotData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // dragonBones::BoneData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_parent(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::BoneData *parent
        return _olua_fun_dragonBones_SlotData_parent$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.SlotData")) && (olua_is_object(L, 2, "db.BoneData"))) {
            // dragonBones::BoneData *parent
            return _olua_fun_dragonBones_SlotData_parent$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::SlotData::parent' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_setBlendMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.SlotData");
    olua_check_integer(L, 2, &arg1);

    // void setBlendMode(int value)
    self->setBlendMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.SlotData");
    olua_check_object(L, 2, &arg1, "db.BoneData");

    // void setParent(dragonBones::BoneData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_setUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.SlotData");
    olua_check_object(L, 2, &arg1, "db.UserData");

    // void setUserData(dragonBones::UserData *value)
    self->setUserData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_userData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "db.SlotData");

    // dragonBones::UserData *userData
    dragonBones::UserData *ret = self->userData;
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SlotData_userData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** userData */

    olua_to_object(L, 1, &self, "db.SlotData");
    olua_check_object(L, 2, &arg1, "db.UserData");

    // dragonBones::UserData *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_userData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::UserData *userData
        return _olua_fun_dragonBones_SlotData_userData$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.SlotData")) && (olua_is_object(L, 2, "db.UserData"))) {
            // dragonBones::UserData *userData
            return _olua_fun_dragonBones_SlotData_userData$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::SlotData::userData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_zOrder$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "db.SlotData");

    // int zOrder
    int ret = self->zOrder;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_SlotData_zOrder$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::SlotData *self = nullptr;
    int arg1 = 0;       /** zOrder */

    olua_to_object(L, 1, &self, "db.SlotData");
    olua_check_integer(L, 2, &arg1);

    // int zOrder
    self->zOrder = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_SlotData_zOrder(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int zOrder
        return _olua_fun_dragonBones_SlotData_zOrder$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.SlotData")) && (olua_is_integer(L, 2))) {
            // int zOrder
            return _olua_fun_dragonBones_SlotData_zOrder$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::SlotData::zOrder' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_SlotData(lua_State *L)
{
    oluacls_class<dragonBones::SlotData, dragonBones::BaseObject>(L, "db.SlotData");
    oluacls_func(L, "getBlendMode", _olua_fun_dragonBones_SlotData_getBlendMode);
    oluacls_func(L, "getParent", _olua_fun_dragonBones_SlotData_getParent);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_SlotData_getTypeIndex);
    oluacls_func(L, "getUserData", _olua_fun_dragonBones_SlotData_getUserData);
    oluacls_func(L, "new", _olua_fun_dragonBones_SlotData_new);
    oluacls_func(L, "setBlendMode", _olua_fun_dragonBones_SlotData_setBlendMode);
    oluacls_func(L, "setParent", _olua_fun_dragonBones_SlotData_setParent);
    oluacls_func(L, "setUserData", _olua_fun_dragonBones_SlotData_setUserData);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_SlotData_getTypeIndex, nullptr);
    oluacls_prop(L, "blendMode", _olua_fun_dragonBones_SlotData_blendMode, _olua_fun_dragonBones_SlotData_blendMode);
    oluacls_prop(L, "displayIndex", _olua_fun_dragonBones_SlotData_displayIndex, _olua_fun_dragonBones_SlotData_displayIndex);
    oluacls_prop(L, "zOrder", _olua_fun_dragonBones_SlotData_zOrder, _olua_fun_dragonBones_SlotData_zOrder);
    oluacls_prop(L, "name", _olua_fun_dragonBones_SlotData_name, _olua_fun_dragonBones_SlotData_name);
    oluacls_prop(L, "userData", _olua_fun_dragonBones_SlotData_userData, _olua_fun_dragonBones_SlotData_userData);
    oluacls_prop(L, "parent", _olua_fun_dragonBones_SlotData_parent, _olua_fun_dragonBones_SlotData_parent);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_SlotData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.SlotData")) {
        luaL_error(L, "class not found: dragonBones::SlotData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_AnimationState_actionEnabled$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // bool actionEnabled
    bool ret = self->actionEnabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_actionEnabled$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    bool arg1 = false;       /** actionEnabled */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_bool(L, 2, &arg1);

    // bool actionEnabled
    self->actionEnabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_actionEnabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool actionEnabled
        return _olua_fun_dragonBones_AnimationState_actionEnabled$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_bool(L, 2))) {
            // bool actionEnabled
            return _olua_fun_dragonBones_AnimationState_actionEnabled$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::actionEnabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_addBoneMask$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** boneName */
    bool arg2 = false;       /** recursive */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void addBoneMask(const std::string &boneName, @optional bool recursive)
    self->addBoneMask(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_addBoneMask$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_string(L, 2, &arg1);

    // void addBoneMask(const std::string &boneName)
    self->addBoneMask(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_addBoneMask(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_string(L, 2))) {
            // void addBoneMask(const std::string &boneName)
            return _olua_fun_dragonBones_AnimationState_addBoneMask$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void addBoneMask(const std::string &boneName, @optional bool recursive)
            return _olua_fun_dragonBones_AnimationState_addBoneMask$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::addBoneMask' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_additiveBlending$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // bool additiveBlending
    bool ret = self->additiveBlending;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_additiveBlending$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    bool arg1 = false;       /** additiveBlending */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_bool(L, 2, &arg1);

    // bool additiveBlending
    self->additiveBlending = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_additiveBlending(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool additiveBlending
        return _olua_fun_dragonBones_AnimationState_additiveBlending$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_bool(L, 2))) {
            // bool additiveBlending
            return _olua_fun_dragonBones_AnimationState_additiveBlending$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::additiveBlending' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_advanceTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    float arg1 = 0;       /** passedTime */
    float arg2 = 0;       /** cacheFrameRate */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void advanceTime(float passedTime, float cacheFrameRate)
    self->advanceTime(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_autoFadeOutTime$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // float autoFadeOutTime
    float ret = self->autoFadeOutTime;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_autoFadeOutTime$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    float arg1 = 0;       /** autoFadeOutTime */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // float autoFadeOutTime
    self->autoFadeOutTime = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_autoFadeOutTime(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float autoFadeOutTime
        return _olua_fun_dragonBones_AnimationState_autoFadeOutTime$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_number(L, 2))) {
            // float autoFadeOutTime
            return _olua_fun_dragonBones_AnimationState_autoFadeOutTime$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::autoFadeOutTime' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_containsBoneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_string(L, 2, &arg1);

    // bool containsBoneMask(const std::string &boneName)
    bool ret = self->containsBoneMask(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_displayControl$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // bool displayControl
    bool ret = self->displayControl;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_displayControl$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    bool arg1 = false;       /** displayControl */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_bool(L, 2, &arg1);

    // bool displayControl
    self->displayControl = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_displayControl(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool displayControl
        return _olua_fun_dragonBones_AnimationState_displayControl$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_bool(L, 2))) {
            // bool displayControl
            return _olua_fun_dragonBones_AnimationState_displayControl$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::displayControl' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_fadeOut$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    float arg1 = 0;       /** fadeOutTime */
    bool arg2 = false;       /** pausePlayhead */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void fadeOut(float fadeOutTime, @optional bool pausePlayhead)
    self->fadeOut(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_fadeOut$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    float arg1 = 0;       /** fadeOutTime */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // void fadeOut(float fadeOutTime)
    self->fadeOut(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_fadeOut(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_number(L, 2))) {
            // void fadeOut(float fadeOutTime)
            return _olua_fun_dragonBones_AnimationState_fadeOut$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_number(L, 2)) && (olua_is_bool(L, 3))) {
            // void fadeOut(float fadeOutTime, @optional bool pausePlayhead)
            return _olua_fun_dragonBones_AnimationState_fadeOut$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::fadeOut' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_fadeTotalTime$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // float fadeTotalTime
    float ret = self->fadeTotalTime;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_fadeTotalTime$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    float arg1 = 0;       /** fadeTotalTime */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // float fadeTotalTime
    self->fadeTotalTime = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_fadeTotalTime(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float fadeTotalTime
        return _olua_fun_dragonBones_AnimationState_fadeTotalTime$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_number(L, 2))) {
            // float fadeTotalTime
            return _olua_fun_dragonBones_AnimationState_fadeTotalTime$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::fadeTotalTime' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_getAnimationData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // const dragonBones::AnimationData *getAnimationData()
    const dragonBones::AnimationData *ret = self->getAnimationData();
    int num_ret = olua_push_object(L, ret, "db.AnimationData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_getCurrentPlayTimes(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // unsigned int getCurrentPlayTimes()
    unsigned int ret = self->getCurrentPlayTimes();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_getCurrentTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // float getCurrentTime()
    float ret = self->getCurrentTime();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_getName(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // const std::string &getName()
    const std::string &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_getTotalTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // float getTotalTime()
    float ret = self->getTotalTime();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::AnimationState::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_group$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // std::string group
    std::string ret = self->group;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_group$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** group */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_string(L, 2, &arg1);

    // std::string group
    self->group = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_group(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string group
        return _olua_fun_dragonBones_AnimationState_group$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_string(L, 2))) {
            // std::string group
            return _olua_fun_dragonBones_AnimationState_group$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::group' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_init(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    dragonBones::AnimationData *arg2 = nullptr;       /** animationData */
    dragonBones::AnimationConfig *arg3 = nullptr;       /** animationConfig */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_object(L, 2, &arg1, "db.Armature");
    olua_check_object(L, 3, &arg2, "db.AnimationData");
    olua_check_object(L, 4, &arg3, "db.AnimationConfig");

    // void init(dragonBones::Armature *armature, dragonBones::AnimationData *animationData, dragonBones::AnimationConfig *animationConfig)
    self->init(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_isCompleted(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // bool isCompleted()
    bool ret = self->isCompleted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_isFadeComplete(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // bool isFadeComplete()
    bool ret = self->isFadeComplete();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_isFadeIn(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // bool isFadeIn()
    bool ret = self->isFadeIn();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_isFadeOut(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // bool isFadeOut()
    bool ret = self->isFadeOut();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // bool isPlaying()
    bool ret = self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_layer$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // unsigned int layer
    unsigned int ret = self->layer;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_layer$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    unsigned int arg1 = 0;       /** layer */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_integer(L, 2, &arg1);

    // unsigned int layer
    self->layer = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_layer(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int layer
        return _olua_fun_dragonBones_AnimationState_layer$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_integer(L, 2))) {
            // unsigned int layer
            return _olua_fun_dragonBones_AnimationState_layer$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::layer' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_AnimationState_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_AnimationState_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::AnimationState()
    dragonBones::AnimationState *ret = new dragonBones::AnimationState();
    int num_ret = olua_push_object(L, ret, "db.AnimationState");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_play(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // void play()
    self->play();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_playTimes$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // unsigned int playTimes
    unsigned int ret = self->playTimes;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_playTimes$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    unsigned int arg1 = 0;       /** playTimes */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_integer(L, 2, &arg1);

    // unsigned int playTimes
    self->playTimes = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_playTimes(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int playTimes
        return _olua_fun_dragonBones_AnimationState_playTimes$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_integer(L, 2))) {
            // unsigned int playTimes
            return _olua_fun_dragonBones_AnimationState_playTimes$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::playTimes' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_removeAllBoneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // void removeAllBoneMask()
    self->removeAllBoneMask();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_removeBoneMask$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** boneName */
    bool arg2 = false;       /** recursive */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void removeBoneMask(const std::string &boneName, @optional bool recursive)
    self->removeBoneMask(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_removeBoneMask$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_string(L, 2, &arg1);

    // void removeBoneMask(const std::string &boneName)
    self->removeBoneMask(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_removeBoneMask(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_string(L, 2))) {
            // void removeBoneMask(const std::string &boneName)
            return _olua_fun_dragonBones_AnimationState_removeBoneMask$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void removeBoneMask(const std::string &boneName, @optional bool recursive)
            return _olua_fun_dragonBones_AnimationState_removeBoneMask$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::removeBoneMask' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_resetToPose$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // bool resetToPose
    bool ret = self->resetToPose;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_resetToPose$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    bool arg1 = false;       /** resetToPose */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_bool(L, 2, &arg1);

    // bool resetToPose
    self->resetToPose = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_resetToPose(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool resetToPose
        return _olua_fun_dragonBones_AnimationState_resetToPose$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_bool(L, 2))) {
            // bool resetToPose
            return _olua_fun_dragonBones_AnimationState_resetToPose$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::resetToPose' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_setCurrentTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    float arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // void setCurrentTime(float value)
    self->setCurrentTime(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_stop(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_timeScale$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // float timeScale
    float ret = self->timeScale;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_timeScale$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    float arg1 = 0;       /** timeScale */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // float timeScale
    self->timeScale = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_timeScale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float timeScale
        return _olua_fun_dragonBones_AnimationState_timeScale$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_number(L, 2))) {
            // float timeScale
            return _olua_fun_dragonBones_AnimationState_timeScale$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::timeScale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_weight$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationState");

    // float weight
    float ret = self->weight;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationState_weight$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationState *self = nullptr;
    float arg1 = 0;       /** weight */

    olua_to_object(L, 1, &self, "db.AnimationState");
    olua_check_number(L, 2, &arg1);

    // float weight
    self->weight = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationState_weight(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float weight
        return _olua_fun_dragonBones_AnimationState_weight$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationState")) && (olua_is_number(L, 2))) {
            // float weight
            return _olua_fun_dragonBones_AnimationState_weight$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationState::weight' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_AnimationState(lua_State *L)
{
    oluacls_class<dragonBones::AnimationState, dragonBones::BaseObject>(L, "db.AnimationState");
    oluacls_func(L, "addBoneMask", _olua_fun_dragonBones_AnimationState_addBoneMask);
    oluacls_func(L, "advanceTime", _olua_fun_dragonBones_AnimationState_advanceTime);
    oluacls_func(L, "containsBoneMask", _olua_fun_dragonBones_AnimationState_containsBoneMask);
    oluacls_func(L, "fadeOut", _olua_fun_dragonBones_AnimationState_fadeOut);
    oluacls_func(L, "getAnimationData", _olua_fun_dragonBones_AnimationState_getAnimationData);
    oluacls_func(L, "getCurrentPlayTimes", _olua_fun_dragonBones_AnimationState_getCurrentPlayTimes);
    oluacls_func(L, "getCurrentTime", _olua_fun_dragonBones_AnimationState_getCurrentTime);
    oluacls_func(L, "getName", _olua_fun_dragonBones_AnimationState_getName);
    oluacls_func(L, "getTotalTime", _olua_fun_dragonBones_AnimationState_getTotalTime);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_AnimationState_getTypeIndex);
    oluacls_func(L, "init", _olua_fun_dragonBones_AnimationState_init);
    oluacls_func(L, "isCompleted", _olua_fun_dragonBones_AnimationState_isCompleted);
    oluacls_func(L, "isFadeComplete", _olua_fun_dragonBones_AnimationState_isFadeComplete);
    oluacls_func(L, "isFadeIn", _olua_fun_dragonBones_AnimationState_isFadeIn);
    oluacls_func(L, "isFadeOut", _olua_fun_dragonBones_AnimationState_isFadeOut);
    oluacls_func(L, "isPlaying", _olua_fun_dragonBones_AnimationState_isPlaying);
    oluacls_func(L, "new", _olua_fun_dragonBones_AnimationState_new);
    oluacls_func(L, "play", _olua_fun_dragonBones_AnimationState_play);
    oluacls_func(L, "removeAllBoneMask", _olua_fun_dragonBones_AnimationState_removeAllBoneMask);
    oluacls_func(L, "removeBoneMask", _olua_fun_dragonBones_AnimationState_removeBoneMask);
    oluacls_func(L, "setCurrentTime", _olua_fun_dragonBones_AnimationState_setCurrentTime);
    oluacls_func(L, "stop", _olua_fun_dragonBones_AnimationState_stop);
    oluacls_prop(L, "animationData", _olua_fun_dragonBones_AnimationState_getAnimationData, nullptr);
    oluacls_prop(L, "completed", _olua_fun_dragonBones_AnimationState_isCompleted, nullptr);
    oluacls_prop(L, "currentPlayTimes", _olua_fun_dragonBones_AnimationState_getCurrentPlayTimes, nullptr);
    oluacls_prop(L, "currentTime", _olua_fun_dragonBones_AnimationState_getCurrentTime, _olua_fun_dragonBones_AnimationState_setCurrentTime);
    oluacls_prop(L, "fadeComplete", _olua_fun_dragonBones_AnimationState_isFadeComplete, nullptr);
    oluacls_prop(L, "fadeIn", _olua_fun_dragonBones_AnimationState_isFadeIn, nullptr);
    oluacls_prop(L, "playing", _olua_fun_dragonBones_AnimationState_isPlaying, nullptr);
    oluacls_prop(L, "totalTime", _olua_fun_dragonBones_AnimationState_getTotalTime, nullptr);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_AnimationState_getTypeIndex, nullptr);
    oluacls_prop(L, "actionEnabled", _olua_fun_dragonBones_AnimationState_actionEnabled, _olua_fun_dragonBones_AnimationState_actionEnabled);
    oluacls_prop(L, "additiveBlending", _olua_fun_dragonBones_AnimationState_additiveBlending, _olua_fun_dragonBones_AnimationState_additiveBlending);
    oluacls_prop(L, "displayControl", _olua_fun_dragonBones_AnimationState_displayControl, _olua_fun_dragonBones_AnimationState_displayControl);
    oluacls_prop(L, "resetToPose", _olua_fun_dragonBones_AnimationState_resetToPose, _olua_fun_dragonBones_AnimationState_resetToPose);
    oluacls_prop(L, "playTimes", _olua_fun_dragonBones_AnimationState_playTimes, _olua_fun_dragonBones_AnimationState_playTimes);
    oluacls_prop(L, "layer", _olua_fun_dragonBones_AnimationState_layer, _olua_fun_dragonBones_AnimationState_layer);
    oluacls_prop(L, "timeScale", _olua_fun_dragonBones_AnimationState_timeScale, _olua_fun_dragonBones_AnimationState_timeScale);
    oluacls_prop(L, "weight", _olua_fun_dragonBones_AnimationState_weight, _olua_fun_dragonBones_AnimationState_weight);
    oluacls_prop(L, "autoFadeOutTime", _olua_fun_dragonBones_AnimationState_autoFadeOutTime, _olua_fun_dragonBones_AnimationState_autoFadeOutTime);
    oluacls_prop(L, "fadeTotalTime", _olua_fun_dragonBones_AnimationState_fadeTotalTime, _olua_fun_dragonBones_AnimationState_fadeTotalTime);
    oluacls_prop(L, "name", _olua_fun_dragonBones_AnimationState_name, _olua_fun_dragonBones_AnimationState_name);
    oluacls_prop(L, "group", _olua_fun_dragonBones_AnimationState_group, _olua_fun_dragonBones_AnimationState_group);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_AnimationState(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.AnimationState")) {
        luaL_error(L, "class not found: dragonBones::AnimationState");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_AnimationData_actionTimeline$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // dragonBones::TimelineData *actionTimeline
    dragonBones::TimelineData *ret = self->actionTimeline;
    int num_ret = olua_push_object(L, ret, "db.TimelineData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_actionTimeline$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::TimelineData *arg1 = nullptr;       /** actionTimeline */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_object(L, 2, &arg1, "db.TimelineData");

    // dragonBones::TimelineData *actionTimeline
    self->actionTimeline = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_actionTimeline(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::TimelineData *actionTimeline
        return _olua_fun_dragonBones_AnimationData_actionTimeline$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_object(L, 2, "db.TimelineData"))) {
            // dragonBones::TimelineData *actionTimeline
            return _olua_fun_dragonBones_AnimationData_actionTimeline$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::actionTimeline' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_addBoneTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::BoneData *arg1 = nullptr;       /** bone */
    dragonBones::TimelineData *arg2 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_object(L, 2, &arg1, "db.BoneData");
    olua_check_object(L, 3, &arg2, "db.TimelineData");

    // void addBoneTimeline(dragonBones::BoneData *bone, dragonBones::TimelineData *value)
    self->addBoneTimeline(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_addConstraintTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::ConstraintData *arg1 = nullptr;       /** constraint */
    dragonBones::TimelineData *arg2 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_object(L, 2, &arg1, "db.ConstraintData");
    olua_check_object(L, 3, &arg2, "db.TimelineData");

    // void addConstraintTimeline(dragonBones::ConstraintData *constraint, dragonBones::TimelineData *value)
    self->addConstraintTimeline(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_addSlotTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::SlotData *arg1 = nullptr;       /** slot */
    dragonBones::TimelineData *arg2 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_object(L, 2, &arg1, "db.SlotData");
    olua_check_object(L, 3, &arg2, "db.TimelineData");

    // void addSlotTimeline(dragonBones::SlotData *slot, dragonBones::TimelineData *value)
    self->addSlotTimeline(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_cacheFrameRate$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // float cacheFrameRate
    float ret = self->cacheFrameRate;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_cacheFrameRate$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    float arg1 = 0;       /** cacheFrameRate */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_number(L, 2, &arg1);

    // float cacheFrameRate
    self->cacheFrameRate = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_cacheFrameRate(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float cacheFrameRate
        return _olua_fun_dragonBones_AnimationData_cacheFrameRate$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_number(L, 2))) {
            // float cacheFrameRate
            return _olua_fun_dragonBones_AnimationData_cacheFrameRate$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::cacheFrameRate' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_cacheFrames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    unsigned int arg1 = 0;       /** frameRate */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_integer(L, 2, &arg1);

    // void cacheFrames(unsigned int frameRate)
    self->cacheFrames(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_cachedFrames$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // std::vector<bool> cachedFrames
    std::vector<bool> &ret = self->cachedFrames;
    int num_ret = olua_push_array<bool>(L, ret, [L](bool &arg1) {
        olua_push_bool(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_cachedFrames$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    std::vector<bool> arg1;       /** cachedFrames */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_array<bool>(L, 2, arg1, [L](bool *arg1) {
        olua_check_bool(L, -1, arg1);
    });

    // std::vector<bool> cachedFrames
    self->cachedFrames = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_cachedFrames(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<bool> cachedFrames
        return _olua_fun_dragonBones_AnimationData_cachedFrames$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_array(L, 2))) {
            // std::vector<bool> cachedFrames
            return _olua_fun_dragonBones_AnimationData_cachedFrames$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::cachedFrames' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_duration$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // float duration
    float ret = self->duration;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_duration$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    float arg1 = 0;       /** duration */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_number(L, 2, &arg1);

    // float duration
    self->duration = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_duration(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float duration
        return _olua_fun_dragonBones_AnimationData_duration$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_number(L, 2))) {
            // float duration
            return _olua_fun_dragonBones_AnimationData_duration$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::duration' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_fadeInTime$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // float fadeInTime
    float ret = self->fadeInTime;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_fadeInTime$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    float arg1 = 0;       /** fadeInTime */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_number(L, 2, &arg1);

    // float fadeInTime
    self->fadeInTime = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_fadeInTime(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float fadeInTime
        return _olua_fun_dragonBones_AnimationData_fadeInTime$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_number(L, 2))) {
            // float fadeInTime
            return _olua_fun_dragonBones_AnimationData_fadeInTime$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::fadeInTime' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_frameCount$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // unsigned int frameCount
    unsigned int ret = self->frameCount;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_frameCount$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    unsigned int arg1 = 0;       /** frameCount */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int frameCount
    self->frameCount = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_frameCount(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int frameCount
        return _olua_fun_dragonBones_AnimationData_frameCount$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_integer(L, 2))) {
            // unsigned int frameCount
            return _olua_fun_dragonBones_AnimationData_frameCount$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::frameCount' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_frameFloatOffset$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // unsigned int frameFloatOffset
    unsigned int ret = self->frameFloatOffset;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_frameFloatOffset$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    unsigned int arg1 = 0;       /** frameFloatOffset */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int frameFloatOffset
    self->frameFloatOffset = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_frameFloatOffset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int frameFloatOffset
        return _olua_fun_dragonBones_AnimationData_frameFloatOffset$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_integer(L, 2))) {
            // unsigned int frameFloatOffset
            return _olua_fun_dragonBones_AnimationData_frameFloatOffset$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::frameFloatOffset' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_frameIntOffset$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // unsigned int frameIntOffset
    unsigned int ret = self->frameIntOffset;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_frameIntOffset$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    unsigned int arg1 = 0;       /** frameIntOffset */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int frameIntOffset
    self->frameIntOffset = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_frameIntOffset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int frameIntOffset
        return _olua_fun_dragonBones_AnimationData_frameIntOffset$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_integer(L, 2))) {
            // unsigned int frameIntOffset
            return _olua_fun_dragonBones_AnimationData_frameIntOffset$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::frameIntOffset' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_frameOffset$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // unsigned int frameOffset
    unsigned int ret = self->frameOffset;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_frameOffset$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    unsigned int arg1 = 0;       /** frameOffset */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int frameOffset
    self->frameOffset = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_frameOffset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int frameOffset
        return _olua_fun_dragonBones_AnimationData_frameOffset$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_integer(L, 2))) {
            // unsigned int frameOffset
            return _olua_fun_dragonBones_AnimationData_frameOffset$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::frameOffset' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_getActionTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // dragonBones::TimelineData *getActionTimeline()
    dragonBones::TimelineData *ret = self->getActionTimeline();
    int num_ret = olua_push_object(L, ret, "db.TimelineData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // dragonBones::ArmatureData *getParent()
    dragonBones::ArmatureData *ret = self->getParent();
    int num_ret = olua_push_object(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::AnimationData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_getZOrderTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // dragonBones::TimelineData *getZOrderTimeline()
    dragonBones::TimelineData *ret = self->getZOrderTimeline();
    int num_ret = olua_push_object(L, ret, "db.TimelineData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_AnimationData_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_AnimationData_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::AnimationData()
    dragonBones::AnimationData *ret = new dragonBones::AnimationData();
    int num_ret = olua_push_object(L, ret, "db.AnimationData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_parent$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // dragonBones::ArmatureData *parent
    dragonBones::ArmatureData *ret = self->parent;
    int num_ret = olua_push_object(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_parent$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::ArmatureData *arg1 = nullptr;       /** parent */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_object(L, 2, &arg1, "db.ArmatureData");

    // dragonBones::ArmatureData *parent
    self->parent = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_parent(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::ArmatureData *parent
        return _olua_fun_dragonBones_AnimationData_parent$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_object(L, 2, "db.ArmatureData"))) {
            // dragonBones::ArmatureData *parent
            return _olua_fun_dragonBones_AnimationData_parent$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::parent' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_playTimes$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // unsigned int playTimes
    unsigned int ret = self->playTimes;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_playTimes$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    unsigned int arg1 = 0;       /** playTimes */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int playTimes
    self->playTimes = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_playTimes(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int playTimes
        return _olua_fun_dragonBones_AnimationData_playTimes$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_integer(L, 2))) {
            // unsigned int playTimes
            return _olua_fun_dragonBones_AnimationData_playTimes$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::playTimes' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_scale$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // float scale
    float ret = self->scale;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_scale$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    float arg1 = 0;       /** scale */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_number(L, 2, &arg1);

    // float scale
    self->scale = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_scale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float scale
        return _olua_fun_dragonBones_AnimationData_scale$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_number(L, 2))) {
            // float scale
            return _olua_fun_dragonBones_AnimationData_scale$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::scale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_setActionTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::TimelineData *arg1 = nullptr;       /** pactionTimeline */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_object(L, 2, &arg1, "db.TimelineData");

    // void setActionTimeline(dragonBones::TimelineData *pactionTimeline)
    self->setActionTimeline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_setParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::ArmatureData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_object(L, 2, &arg1, "db.ArmatureData");

    // void setParent(dragonBones::ArmatureData *value)
    self->setParent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_setZOrderTimeline(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::TimelineData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_object(L, 2, &arg1, "db.TimelineData");

    // void setZOrderTimeline(dragonBones::TimelineData *value)
    self->setZOrderTimeline(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_zOrderTimeline$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationData");

    // dragonBones::TimelineData *zOrderTimeline
    dragonBones::TimelineData *ret = self->zOrderTimeline;
    int num_ret = olua_push_object(L, ret, "db.TimelineData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationData_zOrderTimeline$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationData *self = nullptr;
    dragonBones::TimelineData *arg1 = nullptr;       /** zOrderTimeline */

    olua_to_object(L, 1, &self, "db.AnimationData");
    olua_check_object(L, 2, &arg1, "db.TimelineData");

    // dragonBones::TimelineData *zOrderTimeline
    self->zOrderTimeline = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationData_zOrderTimeline(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::TimelineData *zOrderTimeline
        return _olua_fun_dragonBones_AnimationData_zOrderTimeline$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationData")) && (olua_is_object(L, 2, "db.TimelineData"))) {
            // dragonBones::TimelineData *zOrderTimeline
            return _olua_fun_dragonBones_AnimationData_zOrderTimeline$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationData::zOrderTimeline' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_AnimationData(lua_State *L)
{
    oluacls_class<dragonBones::AnimationData, dragonBones::BaseObject>(L, "db.AnimationData");
    oluacls_func(L, "addBoneTimeline", _olua_fun_dragonBones_AnimationData_addBoneTimeline);
    oluacls_func(L, "addConstraintTimeline", _olua_fun_dragonBones_AnimationData_addConstraintTimeline);
    oluacls_func(L, "addSlotTimeline", _olua_fun_dragonBones_AnimationData_addSlotTimeline);
    oluacls_func(L, "cacheFrames", _olua_fun_dragonBones_AnimationData_cacheFrames);
    oluacls_func(L, "getActionTimeline", _olua_fun_dragonBones_AnimationData_getActionTimeline);
    oluacls_func(L, "getParent", _olua_fun_dragonBones_AnimationData_getParent);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_AnimationData_getTypeIndex);
    oluacls_func(L, "getZOrderTimeline", _olua_fun_dragonBones_AnimationData_getZOrderTimeline);
    oluacls_func(L, "new", _olua_fun_dragonBones_AnimationData_new);
    oluacls_func(L, "setActionTimeline", _olua_fun_dragonBones_AnimationData_setActionTimeline);
    oluacls_func(L, "setParent", _olua_fun_dragonBones_AnimationData_setParent);
    oluacls_func(L, "setZOrderTimeline", _olua_fun_dragonBones_AnimationData_setZOrderTimeline);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_AnimationData_getTypeIndex, nullptr);
    oluacls_prop(L, "frameIntOffset", _olua_fun_dragonBones_AnimationData_frameIntOffset, _olua_fun_dragonBones_AnimationData_frameIntOffset);
    oluacls_prop(L, "frameFloatOffset", _olua_fun_dragonBones_AnimationData_frameFloatOffset, _olua_fun_dragonBones_AnimationData_frameFloatOffset);
    oluacls_prop(L, "frameOffset", _olua_fun_dragonBones_AnimationData_frameOffset, _olua_fun_dragonBones_AnimationData_frameOffset);
    oluacls_prop(L, "frameCount", _olua_fun_dragonBones_AnimationData_frameCount, _olua_fun_dragonBones_AnimationData_frameCount);
    oluacls_prop(L, "playTimes", _olua_fun_dragonBones_AnimationData_playTimes, _olua_fun_dragonBones_AnimationData_playTimes);
    oluacls_prop(L, "duration", _olua_fun_dragonBones_AnimationData_duration, _olua_fun_dragonBones_AnimationData_duration);
    oluacls_prop(L, "scale", _olua_fun_dragonBones_AnimationData_scale, _olua_fun_dragonBones_AnimationData_scale);
    oluacls_prop(L, "fadeInTime", _olua_fun_dragonBones_AnimationData_fadeInTime, _olua_fun_dragonBones_AnimationData_fadeInTime);
    oluacls_prop(L, "cacheFrameRate", _olua_fun_dragonBones_AnimationData_cacheFrameRate, _olua_fun_dragonBones_AnimationData_cacheFrameRate);
    oluacls_prop(L, "name", _olua_fun_dragonBones_AnimationData_name, _olua_fun_dragonBones_AnimationData_name);
    oluacls_prop(L, "cachedFrames", _olua_fun_dragonBones_AnimationData_cachedFrames, _olua_fun_dragonBones_AnimationData_cachedFrames);
    oluacls_prop(L, "actionTimeline", _olua_fun_dragonBones_AnimationData_actionTimeline, _olua_fun_dragonBones_AnimationData_actionTimeline);
    oluacls_prop(L, "zOrderTimeline", _olua_fun_dragonBones_AnimationData_zOrderTimeline, _olua_fun_dragonBones_AnimationData_zOrderTimeline);
    oluacls_prop(L, "parent", _olua_fun_dragonBones_AnimationData_parent, _olua_fun_dragonBones_AnimationData_parent);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_AnimationData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.AnimationData")) {
        luaL_error(L, "class not found: dragonBones::AnimationData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_AnimationConfig_actionEnabled$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // bool actionEnabled
    bool ret = self->actionEnabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_actionEnabled$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** actionEnabled */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool actionEnabled
    self->actionEnabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_actionEnabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool actionEnabled
        return _olua_fun_dragonBones_AnimationConfig_actionEnabled$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_bool(L, 2))) {
            // bool actionEnabled
            return _olua_fun_dragonBones_AnimationConfig_actionEnabled$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::actionEnabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_addBoneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    std::string arg2;       /** boneName */
    bool arg3 = false;       /** recursive */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_object(L, 2, &arg1, "db.Armature");
    olua_check_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void addBoneMask(dragonBones::Armature *armature, const std::string &boneName, bool recursive)
    self->addBoneMask(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_additiveBlending$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // bool additiveBlending
    bool ret = self->additiveBlending;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_additiveBlending$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** additiveBlending */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool additiveBlending
    self->additiveBlending = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_additiveBlending(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool additiveBlending
        return _olua_fun_dragonBones_AnimationConfig_additiveBlending$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_bool(L, 2))) {
            // bool additiveBlending
            return _olua_fun_dragonBones_AnimationConfig_additiveBlending$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::additiveBlending' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_animation$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // std::string animation
    std::string ret = self->animation;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_animation$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    std::string arg1;       /** animation */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_string(L, 2, &arg1);

    // std::string animation
    self->animation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_animation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string animation
        return _olua_fun_dragonBones_AnimationConfig_animation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_string(L, 2))) {
            // std::string animation
            return _olua_fun_dragonBones_AnimationConfig_animation$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::animation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_autoFadeOutTime$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // float autoFadeOutTime
    float ret = self->autoFadeOutTime;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_autoFadeOutTime$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    float arg1 = 0;       /** autoFadeOutTime */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float autoFadeOutTime
    self->autoFadeOutTime = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_autoFadeOutTime(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float autoFadeOutTime
        return _olua_fun_dragonBones_AnimationConfig_autoFadeOutTime$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_number(L, 2))) {
            // float autoFadeOutTime
            return _olua_fun_dragonBones_AnimationConfig_autoFadeOutTime$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::autoFadeOutTime' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_boneMask$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // std::vector<std::string> boneMask
    std::vector<std::string> &ret = self->boneMask;
    int num_ret = olua_push_array<std::string>(L, ret, [L](std::string &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_boneMask$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    std::vector<std::string> arg1;       /** boneMask */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_array<std::string>(L, 2, arg1, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // std::vector<std::string> boneMask
    self->boneMask = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_boneMask(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<std::string> boneMask
        return _olua_fun_dragonBones_AnimationConfig_boneMask$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_array(L, 2))) {
            // std::vector<std::string> boneMask
            return _olua_fun_dragonBones_AnimationConfig_boneMask$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::boneMask' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_clear(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // void clear()
    self->clear();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_containsBoneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_string(L, 2, &arg1);

    // bool containsBoneMask(const std::string &boneName)
    bool ret = self->containsBoneMask(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_copyFrom(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    dragonBones::AnimationConfig *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_object(L, 2, &arg1, "db.AnimationConfig");

    // void copyFrom(dragonBones::AnimationConfig *value)
    self->copyFrom(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_displayControl$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // bool displayControl
    bool ret = self->displayControl;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_displayControl$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** displayControl */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool displayControl
    self->displayControl = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_displayControl(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool displayControl
        return _olua_fun_dragonBones_AnimationConfig_displayControl$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_bool(L, 2))) {
            // bool displayControl
            return _olua_fun_dragonBones_AnimationConfig_displayControl$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::displayControl' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_duration$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // float duration
    float ret = self->duration;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_duration$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    float arg1 = 0;       /** duration */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float duration
    self->duration = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_duration(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float duration
        return _olua_fun_dragonBones_AnimationConfig_duration$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_number(L, 2))) {
            // float duration
            return _olua_fun_dragonBones_AnimationConfig_duration$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::duration' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeInTime$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // float fadeInTime
    float ret = self->fadeInTime;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeInTime$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    float arg1 = 0;       /** fadeInTime */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float fadeInTime
    self->fadeInTime = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeInTime(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float fadeInTime
        return _olua_fun_dragonBones_AnimationConfig_fadeInTime$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_number(L, 2))) {
            // float fadeInTime
            return _olua_fun_dragonBones_AnimationConfig_fadeInTime$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::fadeInTime' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeInTweenType$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // dragonBones::TweenType fadeInTweenType
    dragonBones::TweenType ret = self->fadeInTweenType;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeInTweenType$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    dragonBones::TweenType arg1 = (dragonBones::TweenType)0;       /** fadeInTweenType */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_enum(L, 2, &arg1);

    // dragonBones::TweenType fadeInTweenType
    self->fadeInTweenType = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeInTweenType(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::TweenType fadeInTweenType
        return _olua_fun_dragonBones_AnimationConfig_fadeInTweenType$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_enum(L, 2))) {
            // dragonBones::TweenType fadeInTweenType
            return _olua_fun_dragonBones_AnimationConfig_fadeInTweenType$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::fadeInTweenType' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeOutMode$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // dragonBones::AnimationFadeOutMode fadeOutMode
    dragonBones::AnimationFadeOutMode ret = self->fadeOutMode;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeOutMode$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    dragonBones::AnimationFadeOutMode arg1 = (dragonBones::AnimationFadeOutMode)0;       /** fadeOutMode */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_enum(L, 2, &arg1);

    // dragonBones::AnimationFadeOutMode fadeOutMode
    self->fadeOutMode = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeOutMode(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::AnimationFadeOutMode fadeOutMode
        return _olua_fun_dragonBones_AnimationConfig_fadeOutMode$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_enum(L, 2))) {
            // dragonBones::AnimationFadeOutMode fadeOutMode
            return _olua_fun_dragonBones_AnimationConfig_fadeOutMode$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::fadeOutMode' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeOutTime$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // float fadeOutTime
    float ret = self->fadeOutTime;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeOutTime$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    float arg1 = 0;       /** fadeOutTime */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float fadeOutTime
    self->fadeOutTime = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeOutTime(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float fadeOutTime
        return _olua_fun_dragonBones_AnimationConfig_fadeOutTime$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_number(L, 2))) {
            // float fadeOutTime
            return _olua_fun_dragonBones_AnimationConfig_fadeOutTime$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::fadeOutTime' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeOutTweenType$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // dragonBones::TweenType fadeOutTweenType
    dragonBones::TweenType ret = self->fadeOutTweenType;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeOutTweenType$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    dragonBones::TweenType arg1 = (dragonBones::TweenType)0;       /** fadeOutTweenType */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_enum(L, 2, &arg1);

    // dragonBones::TweenType fadeOutTweenType
    self->fadeOutTweenType = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_fadeOutTweenType(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::TweenType fadeOutTweenType
        return _olua_fun_dragonBones_AnimationConfig_fadeOutTweenType$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_enum(L, 2))) {
            // dragonBones::TweenType fadeOutTweenType
            return _olua_fun_dragonBones_AnimationConfig_fadeOutTweenType$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::fadeOutTweenType' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_getFadeInTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // int getFadeInTweenType()
    int ret = self->getFadeInTweenType();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_getFadeOutMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // int getFadeOutMode()
    int ret = self->getFadeOutMode();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_getFadeOutTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // int getFadeOutTweenType()
    int ret = self->getFadeOutTweenType();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::AnimationConfig::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_group$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // std::string group
    std::string ret = self->group;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_group$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    std::string arg1;       /** group */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_string(L, 2, &arg1);

    // std::string group
    self->group = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_group(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string group
        return _olua_fun_dragonBones_AnimationConfig_group$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_string(L, 2))) {
            // std::string group
            return _olua_fun_dragonBones_AnimationConfig_group$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::group' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_layer$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // int layer
    int ret = self->layer;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_layer$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    int arg1 = 0;       /** layer */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_integer(L, 2, &arg1);

    // int layer
    self->layer = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_layer(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int layer
        return _olua_fun_dragonBones_AnimationConfig_layer$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_integer(L, 2))) {
            // int layer
            return _olua_fun_dragonBones_AnimationConfig_layer$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::layer' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_AnimationConfig_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_AnimationConfig_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::AnimationConfig()
    dragonBones::AnimationConfig *ret = new dragonBones::AnimationConfig();
    int num_ret = olua_push_object(L, ret, "db.AnimationConfig");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_pauseFadeIn$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // bool pauseFadeIn
    bool ret = self->pauseFadeIn;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_pauseFadeIn$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** pauseFadeIn */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool pauseFadeIn
    self->pauseFadeIn = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_pauseFadeIn(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool pauseFadeIn
        return _olua_fun_dragonBones_AnimationConfig_pauseFadeIn$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_bool(L, 2))) {
            // bool pauseFadeIn
            return _olua_fun_dragonBones_AnimationConfig_pauseFadeIn$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::pauseFadeIn' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_pauseFadeOut$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // bool pauseFadeOut
    bool ret = self->pauseFadeOut;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_pauseFadeOut$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** pauseFadeOut */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool pauseFadeOut
    self->pauseFadeOut = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_pauseFadeOut(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool pauseFadeOut
        return _olua_fun_dragonBones_AnimationConfig_pauseFadeOut$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_bool(L, 2))) {
            // bool pauseFadeOut
            return _olua_fun_dragonBones_AnimationConfig_pauseFadeOut$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::pauseFadeOut' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_playTimes$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // int playTimes
    int ret = self->playTimes;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_playTimes$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    int arg1 = 0;       /** playTimes */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_integer(L, 2, &arg1);

    // int playTimes
    self->playTimes = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_playTimes(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int playTimes
        return _olua_fun_dragonBones_AnimationConfig_playTimes$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_integer(L, 2))) {
            // int playTimes
            return _olua_fun_dragonBones_AnimationConfig_playTimes$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::playTimes' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_position$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // float position
    float ret = self->position;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_position$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    float arg1 = 0;       /** position */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float position
    self->position = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_position(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float position
        return _olua_fun_dragonBones_AnimationConfig_position$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_number(L, 2))) {
            // float position
            return _olua_fun_dragonBones_AnimationConfig_position$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::position' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_removeBoneMask(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    std::string arg2;       /** boneName */
    bool arg3 = false;       /** recursive */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_object(L, 2, &arg1, "db.Armature");
    olua_check_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void removeBoneMask(dragonBones::Armature *armature, const std::string &boneName, bool recursive)
    self->removeBoneMask(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_resetToPose$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // bool resetToPose
    bool ret = self->resetToPose;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_resetToPose$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    bool arg1 = false;       /** resetToPose */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_bool(L, 2, &arg1);

    // bool resetToPose
    self->resetToPose = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_resetToPose(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool resetToPose
        return _olua_fun_dragonBones_AnimationConfig_resetToPose$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_bool(L, 2))) {
            // bool resetToPose
            return _olua_fun_dragonBones_AnimationConfig_resetToPose$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::resetToPose' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_setFadeInTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_integer(L, 2, &arg1);

    // void setFadeInTweenType(int value)
    self->setFadeInTweenType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_setFadeOutMode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_integer(L, 2, &arg1);

    // void setFadeOutMode(int value)
    self->setFadeOutMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_setFadeOutTweenType(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_integer(L, 2, &arg1);

    // void setFadeOutTweenType(int value)
    self->setFadeOutTweenType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_timeScale$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // float timeScale
    float ret = self->timeScale;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_timeScale$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    float arg1 = 0;       /** timeScale */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float timeScale
    self->timeScale = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_timeScale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float timeScale
        return _olua_fun_dragonBones_AnimationConfig_timeScale$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_number(L, 2))) {
            // float timeScale
            return _olua_fun_dragonBones_AnimationConfig_timeScale$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::timeScale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_weight$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;

    olua_to_object(L, 1, &self, "db.AnimationConfig");

    // float weight
    float ret = self->weight;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_AnimationConfig_weight$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::AnimationConfig *self = nullptr;
    float arg1 = 0;       /** weight */

    olua_to_object(L, 1, &self, "db.AnimationConfig");
    olua_check_number(L, 2, &arg1);

    // float weight
    self->weight = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_AnimationConfig_weight(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float weight
        return _olua_fun_dragonBones_AnimationConfig_weight$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.AnimationConfig")) && (olua_is_number(L, 2))) {
            // float weight
            return _olua_fun_dragonBones_AnimationConfig_weight$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::AnimationConfig::weight' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_AnimationConfig(lua_State *L)
{
    oluacls_class<dragonBones::AnimationConfig, dragonBones::BaseObject>(L, "db.AnimationConfig");
    oluacls_func(L, "addBoneMask", _olua_fun_dragonBones_AnimationConfig_addBoneMask);
    oluacls_func(L, "clear", _olua_fun_dragonBones_AnimationConfig_clear);
    oluacls_func(L, "containsBoneMask", _olua_fun_dragonBones_AnimationConfig_containsBoneMask);
    oluacls_func(L, "copyFrom", _olua_fun_dragonBones_AnimationConfig_copyFrom);
    oluacls_func(L, "getFadeInTweenType", _olua_fun_dragonBones_AnimationConfig_getFadeInTweenType);
    oluacls_func(L, "getFadeOutMode", _olua_fun_dragonBones_AnimationConfig_getFadeOutMode);
    oluacls_func(L, "getFadeOutTweenType", _olua_fun_dragonBones_AnimationConfig_getFadeOutTweenType);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_AnimationConfig_getTypeIndex);
    oluacls_func(L, "new", _olua_fun_dragonBones_AnimationConfig_new);
    oluacls_func(L, "removeBoneMask", _olua_fun_dragonBones_AnimationConfig_removeBoneMask);
    oluacls_func(L, "setFadeInTweenType", _olua_fun_dragonBones_AnimationConfig_setFadeInTweenType);
    oluacls_func(L, "setFadeOutMode", _olua_fun_dragonBones_AnimationConfig_setFadeOutMode);
    oluacls_func(L, "setFadeOutTweenType", _olua_fun_dragonBones_AnimationConfig_setFadeOutTweenType);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_AnimationConfig_getTypeIndex, nullptr);
    oluacls_prop(L, "pauseFadeOut", _olua_fun_dragonBones_AnimationConfig_pauseFadeOut, _olua_fun_dragonBones_AnimationConfig_pauseFadeOut);
    oluacls_prop(L, "fadeOutMode", _olua_fun_dragonBones_AnimationConfig_fadeOutMode, _olua_fun_dragonBones_AnimationConfig_fadeOutMode);
    oluacls_prop(L, "fadeOutTweenType", _olua_fun_dragonBones_AnimationConfig_fadeOutTweenType, _olua_fun_dragonBones_AnimationConfig_fadeOutTweenType);
    oluacls_prop(L, "fadeOutTime", _olua_fun_dragonBones_AnimationConfig_fadeOutTime, _olua_fun_dragonBones_AnimationConfig_fadeOutTime);
    oluacls_prop(L, "actionEnabled", _olua_fun_dragonBones_AnimationConfig_actionEnabled, _olua_fun_dragonBones_AnimationConfig_actionEnabled);
    oluacls_prop(L, "additiveBlending", _olua_fun_dragonBones_AnimationConfig_additiveBlending, _olua_fun_dragonBones_AnimationConfig_additiveBlending);
    oluacls_prop(L, "displayControl", _olua_fun_dragonBones_AnimationConfig_displayControl, _olua_fun_dragonBones_AnimationConfig_displayControl);
    oluacls_prop(L, "pauseFadeIn", _olua_fun_dragonBones_AnimationConfig_pauseFadeIn, _olua_fun_dragonBones_AnimationConfig_pauseFadeIn);
    oluacls_prop(L, "resetToPose", _olua_fun_dragonBones_AnimationConfig_resetToPose, _olua_fun_dragonBones_AnimationConfig_resetToPose);
    oluacls_prop(L, "fadeInTweenType", _olua_fun_dragonBones_AnimationConfig_fadeInTweenType, _olua_fun_dragonBones_AnimationConfig_fadeInTweenType);
    oluacls_prop(L, "playTimes", _olua_fun_dragonBones_AnimationConfig_playTimes, _olua_fun_dragonBones_AnimationConfig_playTimes);
    oluacls_prop(L, "layer", _olua_fun_dragonBones_AnimationConfig_layer, _olua_fun_dragonBones_AnimationConfig_layer);
    oluacls_prop(L, "position", _olua_fun_dragonBones_AnimationConfig_position, _olua_fun_dragonBones_AnimationConfig_position);
    oluacls_prop(L, "duration", _olua_fun_dragonBones_AnimationConfig_duration, _olua_fun_dragonBones_AnimationConfig_duration);
    oluacls_prop(L, "timeScale", _olua_fun_dragonBones_AnimationConfig_timeScale, _olua_fun_dragonBones_AnimationConfig_timeScale);
    oluacls_prop(L, "weight", _olua_fun_dragonBones_AnimationConfig_weight, _olua_fun_dragonBones_AnimationConfig_weight);
    oluacls_prop(L, "fadeInTime", _olua_fun_dragonBones_AnimationConfig_fadeInTime, _olua_fun_dragonBones_AnimationConfig_fadeInTime);
    oluacls_prop(L, "autoFadeOutTime", _olua_fun_dragonBones_AnimationConfig_autoFadeOutTime, _olua_fun_dragonBones_AnimationConfig_autoFadeOutTime);
    oluacls_prop(L, "name", _olua_fun_dragonBones_AnimationConfig_name, _olua_fun_dragonBones_AnimationConfig_name);
    oluacls_prop(L, "animation", _olua_fun_dragonBones_AnimationConfig_animation, _olua_fun_dragonBones_AnimationConfig_animation);
    oluacls_prop(L, "group", _olua_fun_dragonBones_AnimationConfig_group, _olua_fun_dragonBones_AnimationConfig_group);
    oluacls_prop(L, "boneMask", _olua_fun_dragonBones_AnimationConfig_boneMask, _olua_fun_dragonBones_AnimationConfig_boneMask);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_AnimationConfig(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.AnimationConfig")) {
        luaL_error(L, "class not found: dragonBones::AnimationConfig");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_DragonBonesData_addArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    dragonBones::ArmatureData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_object(L, 2, &arg1, "db.ArmatureData");

    // void addArmature(dragonBones::ArmatureData *value)
    self->addArmature(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_armatureNames$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // std::vector<std::string> armatureNames
    std::vector<std::string> &ret = self->armatureNames;
    int num_ret = olua_push_array<std::string>(L, ret, [L](std::string &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_armatureNames$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::vector<std::string> arg1;       /** armatureNames */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_array<std::string>(L, 2, arg1, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // std::vector<std::string> armatureNames
    self->armatureNames = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_armatureNames(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<std::string> armatureNames
        return _olua_fun_dragonBones_DragonBonesData_armatureNames$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_array(L, 2))) {
            // std::vector<std::string> armatureNames
            return _olua_fun_dragonBones_DragonBonesData_armatureNames$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::armatureNames' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_armatures$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // std::map<std::string, dragonBones::ArmatureData *> armatures
    std::map<std::string, dragonBones::ArmatureData *> &ret = self->armatures;
    int num_ret = olua_push_map<std::string, dragonBones::ArmatureData *>(L, ret, [L](std::string &arg1, dragonBones::ArmatureData *arg2) {
        olua_push_string(L, arg1);
        olua_push_object(L, arg2, "db.ArmatureData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_armatures$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::map<std::string, dragonBones::ArmatureData *> arg1;       /** armatures */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_map<std::string, dragonBones::ArmatureData *>(L, 2, arg1, [L](std::string *arg1, dragonBones::ArmatureData **arg2) {
        olua_check_string(L, -1, arg1);
        olua_check_object(L, -2, arg2, "db.ArmatureData");
    });

    // std::map<std::string, dragonBones::ArmatureData *> armatures
    self->armatures = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_armatures(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::map<std::string, dragonBones::ArmatureData *> armatures
        return _olua_fun_dragonBones_DragonBonesData_armatures$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_map(L, 2))) {
            // std::map<std::string, dragonBones::ArmatureData *> armatures
            return _olua_fun_dragonBones_DragonBonesData_armatures$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::armatures' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_autoSearch$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // bool autoSearch
    bool ret = self->autoSearch;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_autoSearch$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    bool arg1 = false;       /** autoSearch */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_bool(L, 2, &arg1);

    // bool autoSearch
    self->autoSearch = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_autoSearch(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool autoSearch
        return _olua_fun_dragonBones_DragonBonesData_autoSearch$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_bool(L, 2))) {
            // bool autoSearch
            return _olua_fun_dragonBones_DragonBonesData_autoSearch$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::autoSearch' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_binary$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // const char *binary
    const char *ret = self->binary;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_binary$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    const char *arg1 = nullptr;       /** binary */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_string(L, 2, &arg1);

    // const char *binary
    self->binary = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_binary(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const char *binary
        return _olua_fun_dragonBones_DragonBonesData_binary$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_string(L, 2))) {
            // const char *binary
            return _olua_fun_dragonBones_DragonBonesData_binary$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::binary' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_cachedFrames$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // std::vector<float> cachedFrames
    std::vector<float> &ret = self->cachedFrames;
    int num_ret = olua_push_array<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_cachedFrames$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::vector<float> arg1;       /** cachedFrames */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_array<float>(L, 2, arg1, [L](float *arg1) {
        olua_check_number(L, -1, arg1);
    });

    // std::vector<float> cachedFrames
    self->cachedFrames = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_cachedFrames(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<float> cachedFrames
        return _olua_fun_dragonBones_DragonBonesData_cachedFrames$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_array(L, 2))) {
            // std::vector<float> cachedFrames
            return _olua_fun_dragonBones_DragonBonesData_cachedFrames$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::cachedFrames' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_floatArray$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // const float *floatArray
    const float *ret = self->floatArray;
    int num_ret = olua_push_pointer(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_floatArray$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    float *arg1 = nullptr;       /** floatArray */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_pointer(L, 2, &arg1, "olua.float");

    // const float *floatArray
    self->floatArray = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_floatArray(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const float *floatArray
        return _olua_fun_dragonBones_DragonBonesData_floatArray$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_pointer(L, 2, "olua.float"))) {
            // const float *floatArray
            return _olua_fun_dragonBones_DragonBonesData_floatArray$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::floatArray' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_frameArray$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // const int16_t *frameArray
    const int16_t *ret = self->frameArray;
    int num_ret = olua_push_pointer(L, ret, "olua.int16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_frameArray$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    int16_t *arg1 = nullptr;       /** frameArray */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_pointer(L, 2, &arg1, "olua.int16");

    // const int16_t *frameArray
    self->frameArray = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_frameArray(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const int16_t *frameArray
        return _olua_fun_dragonBones_DragonBonesData_frameArray$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_pointer(L, 2, "olua.int16"))) {
            // const int16_t *frameArray
            return _olua_fun_dragonBones_DragonBonesData_frameArray$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::frameArray' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_frameFloatArray$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // const float *frameFloatArray
    const float *ret = self->frameFloatArray;
    int num_ret = olua_push_pointer(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_frameFloatArray$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    float *arg1 = nullptr;       /** frameFloatArray */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_pointer(L, 2, &arg1, "olua.float");

    // const float *frameFloatArray
    self->frameFloatArray = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_frameFloatArray(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const float *frameFloatArray
        return _olua_fun_dragonBones_DragonBonesData_frameFloatArray$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_pointer(L, 2, "olua.float"))) {
            // const float *frameFloatArray
            return _olua_fun_dragonBones_DragonBonesData_frameFloatArray$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::frameFloatArray' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_frameIndices$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // std::vector<unsigned int> frameIndices
    std::vector<unsigned int> &ret = self->frameIndices;
    int num_ret = olua_push_array<unsigned int>(L, ret, [L](unsigned int &arg1) {
        olua_push_integer(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_frameIndices$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::vector<unsigned int> arg1;       /** frameIndices */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_array<unsigned int>(L, 2, arg1, [L](unsigned int *arg1) {
        olua_check_integer(L, -1, arg1);
    });

    // std::vector<unsigned int> frameIndices
    self->frameIndices = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_frameIndices(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<unsigned int> frameIndices
        return _olua_fun_dragonBones_DragonBonesData_frameIndices$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_array(L, 2))) {
            // std::vector<unsigned int> frameIndices
            return _olua_fun_dragonBones_DragonBonesData_frameIndices$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::frameIndices' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_frameIntArray$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // const int16_t *frameIntArray
    const int16_t *ret = self->frameIntArray;
    int num_ret = olua_push_pointer(L, ret, "olua.int16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_frameIntArray$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    int16_t *arg1 = nullptr;       /** frameIntArray */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_pointer(L, 2, &arg1, "olua.int16");

    // const int16_t *frameIntArray
    self->frameIntArray = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_frameIntArray(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const int16_t *frameIntArray
        return _olua_fun_dragonBones_DragonBonesData_frameIntArray$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_pointer(L, 2, "olua.int16"))) {
            // const int16_t *frameIntArray
            return _olua_fun_dragonBones_DragonBonesData_frameIntArray$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::frameIntArray' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_frameRate$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // unsigned int frameRate
    unsigned int ret = self->frameRate;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_frameRate$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    unsigned int arg1 = 0;       /** frameRate */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_integer(L, 2, &arg1);

    // unsigned int frameRate
    self->frameRate = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_frameRate(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int frameRate
        return _olua_fun_dragonBones_DragonBonesData_frameRate$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_integer(L, 2))) {
            // unsigned int frameRate
            return _olua_fun_dragonBones_DragonBonesData_frameRate$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::frameRate' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_getArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::string arg1;       /** armatureName */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_string(L, 2, &arg1);

    // dragonBones::ArmatureData *getArmature(const std::string &armatureName)
    dragonBones::ArmatureData *ret = self->getArmature(arg1);
    int num_ret = olua_push_object(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_getArmatureNames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // const std::vector<std::string> &getArmatureNames()
    const std::vector<std::string> &ret = self->getArmatureNames();
    int num_ret = olua_push_array<std::string>(L, ret, [L](std::string &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::DragonBonesData::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // const dragonBones::UserData *getUserData()
    const dragonBones::UserData *ret = self->getUserData();
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_intArray$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // const int16_t *intArray
    const int16_t *ret = self->intArray;
    int num_ret = olua_push_pointer(L, ret, "olua.int16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_intArray$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    int16_t *arg1 = nullptr;       /** intArray */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_pointer(L, 2, &arg1, "olua.int16");

    // const int16_t *intArray
    self->intArray = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_intArray(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const int16_t *intArray
        return _olua_fun_dragonBones_DragonBonesData_intArray$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_pointer(L, 2, "olua.int16"))) {
            // const int16_t *intArray
            return _olua_fun_dragonBones_DragonBonesData_intArray$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::intArray' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_name$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_name$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_dragonBones_DragonBonesData_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_dragonBones_DragonBonesData_name$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::DragonBonesData()
    dragonBones::DragonBonesData *ret = new dragonBones::DragonBonesData();
    int num_ret = olua_push_object(L, ret, "db.DragonBonesData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_setUserData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_object(L, 2, &arg1, "db.UserData");

    // void setUserData(dragonBones::UserData *value)
    self->setUserData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_timelineArray$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // const uint16_t *timelineArray
    const uint16_t *ret = self->timelineArray;
    int num_ret = olua_push_pointer(L, ret, "olua.uint16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_timelineArray$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    uint16_t *arg1 = nullptr;       /** timelineArray */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_pointer(L, 2, &arg1, "olua.uint16");

    // const uint16_t *timelineArray
    self->timelineArray = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_timelineArray(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const uint16_t *timelineArray
        return _olua_fun_dragonBones_DragonBonesData_timelineArray$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_pointer(L, 2, "olua.uint16"))) {
            // const uint16_t *timelineArray
            return _olua_fun_dragonBones_DragonBonesData_timelineArray$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::timelineArray' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_userData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // dragonBones::UserData *userData
    dragonBones::UserData *ret = self->userData;
    int num_ret = olua_push_object(L, ret, "db.UserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_userData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    dragonBones::UserData *arg1 = nullptr;       /** userData */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_object(L, 2, &arg1, "db.UserData");

    // dragonBones::UserData *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_userData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::UserData *userData
        return _olua_fun_dragonBones_DragonBonesData_userData$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_object(L, 2, "db.UserData"))) {
            // dragonBones::UserData *userData
            return _olua_fun_dragonBones_DragonBonesData_userData$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::userData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_version$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;

    olua_to_object(L, 1, &self, "db.DragonBonesData");

    // std::string version
    std::string ret = self->version;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_DragonBonesData_version$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::DragonBonesData *self = nullptr;
    std::string arg1;       /** version */

    olua_to_object(L, 1, &self, "db.DragonBonesData");
    olua_check_string(L, 2, &arg1);

    // std::string version
    self->version = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_DragonBonesData_version(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string version
        return _olua_fun_dragonBones_DragonBonesData_version$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.DragonBonesData")) && (olua_is_string(L, 2))) {
            // std::string version
            return _olua_fun_dragonBones_DragonBonesData_version$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::DragonBonesData::version' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_DragonBonesData(lua_State *L)
{
    oluacls_class<dragonBones::DragonBonesData, dragonBones::BaseObject>(L, "db.DragonBonesData");
    oluacls_func(L, "addArmature", _olua_fun_dragonBones_DragonBonesData_addArmature);
    oluacls_func(L, "getArmature", _olua_fun_dragonBones_DragonBonesData_getArmature);
    oluacls_func(L, "getArmatureNames", _olua_fun_dragonBones_DragonBonesData_getArmatureNames);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_DragonBonesData_getTypeIndex);
    oluacls_func(L, "getUserData", _olua_fun_dragonBones_DragonBonesData_getUserData);
    oluacls_func(L, "new", _olua_fun_dragonBones_DragonBonesData_new);
    oluacls_func(L, "setUserData", _olua_fun_dragonBones_DragonBonesData_setUserData);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_DragonBonesData_getTypeIndex, nullptr);
    oluacls_prop(L, "autoSearch", _olua_fun_dragonBones_DragonBonesData_autoSearch, _olua_fun_dragonBones_DragonBonesData_autoSearch);
    oluacls_prop(L, "frameRate", _olua_fun_dragonBones_DragonBonesData_frameRate, _olua_fun_dragonBones_DragonBonesData_frameRate);
    oluacls_prop(L, "version", _olua_fun_dragonBones_DragonBonesData_version, _olua_fun_dragonBones_DragonBonesData_version);
    oluacls_prop(L, "name", _olua_fun_dragonBones_DragonBonesData_name, _olua_fun_dragonBones_DragonBonesData_name);
    oluacls_prop(L, "frameIndices", _olua_fun_dragonBones_DragonBonesData_frameIndices, _olua_fun_dragonBones_DragonBonesData_frameIndices);
    oluacls_prop(L, "cachedFrames", _olua_fun_dragonBones_DragonBonesData_cachedFrames, _olua_fun_dragonBones_DragonBonesData_cachedFrames);
    oluacls_prop(L, "armatureNames", _olua_fun_dragonBones_DragonBonesData_armatureNames, _olua_fun_dragonBones_DragonBonesData_armatureNames);
    oluacls_prop(L, "armatures", _olua_fun_dragonBones_DragonBonesData_armatures, _olua_fun_dragonBones_DragonBonesData_armatures);
    oluacls_prop(L, "binary", _olua_fun_dragonBones_DragonBonesData_binary, _olua_fun_dragonBones_DragonBonesData_binary);
    oluacls_prop(L, "intArray", _olua_fun_dragonBones_DragonBonesData_intArray, _olua_fun_dragonBones_DragonBonesData_intArray);
    oluacls_prop(L, "floatArray", _olua_fun_dragonBones_DragonBonesData_floatArray, _olua_fun_dragonBones_DragonBonesData_floatArray);
    oluacls_prop(L, "frameIntArray", _olua_fun_dragonBones_DragonBonesData_frameIntArray, _olua_fun_dragonBones_DragonBonesData_frameIntArray);
    oluacls_prop(L, "frameFloatArray", _olua_fun_dragonBones_DragonBonesData_frameFloatArray, _olua_fun_dragonBones_DragonBonesData_frameFloatArray);
    oluacls_prop(L, "frameArray", _olua_fun_dragonBones_DragonBonesData_frameArray, _olua_fun_dragonBones_DragonBonesData_frameArray);
    oluacls_prop(L, "timelineArray", _olua_fun_dragonBones_DragonBonesData_timelineArray, _olua_fun_dragonBones_DragonBonesData_timelineArray);
    oluacls_prop(L, "userData", _olua_fun_dragonBones_DragonBonesData_userData, _olua_fun_dragonBones_DragonBonesData_userData);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_DragonBonesData(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.DragonBonesData")) {
        luaL_error(L, "class not found: dragonBones::DragonBonesData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_BaseFactory___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::BaseFactory *)olua_toobj(L, 1, "db.BaseFactory");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_addDragonBonesData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::DragonBonesData *arg1 = nullptr;       /** data */
    std::string arg2;       /** name */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.DragonBonesData");
    olua_check_string(L, 3, &arg2);

    // void addDragonBonesData(dragonBones::DragonBonesData *data, @optional const std::string &name)
    self->addDragonBonesData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_addDragonBonesData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::DragonBonesData *arg1 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.DragonBonesData");

    // void addDragonBonesData(dragonBones::DragonBonesData *data)
    self->addDragonBonesData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_addDragonBonesData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_object(L, 2, "db.DragonBonesData"))) {
            // void addDragonBonesData(dragonBones::DragonBonesData *data)
            return _olua_fun_dragonBones_BaseFactory_addDragonBonesData$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_object(L, 2, "db.DragonBonesData")) && (olua_is_string(L, 3))) {
            // void addDragonBonesData(dragonBones::DragonBonesData *data, @optional const std::string &name)
            return _olua_fun_dragonBones_BaseFactory_addDragonBonesData$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::addDragonBonesData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_addTextureAtlasData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::TextureAtlasData *arg1 = nullptr;       /** data */
    std::string arg2;       /** name */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.TextureAtlasData");
    olua_check_string(L, 3, &arg2);

    // void addTextureAtlasData(dragonBones::TextureAtlasData *data, @optional const std::string &name)
    self->addTextureAtlasData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_addTextureAtlasData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::TextureAtlasData *arg1 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.TextureAtlasData");

    // void addTextureAtlasData(dragonBones::TextureAtlasData *data)
    self->addTextureAtlasData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_addTextureAtlasData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_object(L, 2, "db.TextureAtlasData"))) {
            // void addTextureAtlasData(dragonBones::TextureAtlasData *data)
            return _olua_fun_dragonBones_BaseFactory_addTextureAtlasData$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_object(L, 2, "db.TextureAtlasData")) && (olua_is_string(L, 3))) {
            // void addTextureAtlasData(dragonBones::TextureAtlasData *data, @optional const std::string &name)
            return _olua_fun_dragonBones_BaseFactory_addTextureAtlasData$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::addTextureAtlasData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_autoSearch$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;

    olua_to_object(L, 1, &self, "db.BaseFactory");

    // bool autoSearch
    bool ret = self->autoSearch;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_autoSearch$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    bool arg1 = false;       /** autoSearch */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_bool(L, 2, &arg1);

    // bool autoSearch
    self->autoSearch = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_autoSearch(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool autoSearch
        return _olua_fun_dragonBones_BaseFactory_autoSearch$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_bool(L, 2))) {
            // bool autoSearch
            return _olua_fun_dragonBones_BaseFactory_autoSearch$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::autoSearch' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_buildArmature$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */
    std::string arg3;       /** skinName */
    std::string arg4;       /** textureAtlasName */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);

    // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    dragonBones::Armature *ret = self->buildArmature(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_buildArmature$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** armatureName */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);

    // dragonBones::Armature *buildArmature(const std::string &armatureName)
    dragonBones::Armature *ret = self->buildArmature(arg1);
    int num_ret = olua_push_object(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_buildArmature$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName)
    dragonBones::Armature *ret = self->buildArmature(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_buildArmature$4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */
    std::string arg3;       /** skinName */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);

    // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName)
    dragonBones::Armature *ret = self->buildArmature(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_buildArmature(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2))) {
            // dragonBones::Armature *buildArmature(const std::string &armatureName)
            return _olua_fun_dragonBones_BaseFactory_buildArmature$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName)
            return _olua_fun_dragonBones_BaseFactory_buildArmature$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4))) {
            // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName)
            return _olua_fun_dragonBones_BaseFactory_buildArmature$4(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5))) {
            // dragonBones::Armature *buildArmature(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
            return _olua_fun_dragonBones_BaseFactory_buildArmature$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::buildArmature' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_changeSkin$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    dragonBones::SkinData *arg2 = nullptr;       /** skin */
    std::vector<std::string> *arg3 = nullptr;       /** exclude */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.Armature");
    olua_check_object(L, 3, &arg2, "db.SkinData");
    olua_check_pointer(L, 4, &arg3, "cc.types.VectorString");

    // bool changeSkin(dragonBones::Armature *armature, dragonBones::SkinData *skin, @optional const std::vector<std::string> *exclude)
    bool ret = self->changeSkin(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_changeSkin$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    dragonBones::SkinData *arg2 = nullptr;       /** skin */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.Armature");
    olua_check_object(L, 3, &arg2, "db.SkinData");

    // bool changeSkin(dragonBones::Armature *armature, dragonBones::SkinData *skin)
    bool ret = self->changeSkin(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_changeSkin(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_object(L, 2, "db.Armature")) && (olua_is_object(L, 3, "db.SkinData"))) {
            // bool changeSkin(dragonBones::Armature *armature, dragonBones::SkinData *skin)
            return _olua_fun_dragonBones_BaseFactory_changeSkin$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_object(L, 2, "db.Armature")) && (olua_is_object(L, 3, "db.SkinData")) && (olua_is_pointer(L, 4, "cc.types.VectorString"))) {
            // bool changeSkin(dragonBones::Armature *armature, dragonBones::SkinData *skin, @optional const std::vector<std::string> *exclude)
            return _olua_fun_dragonBones_BaseFactory_changeSkin$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::changeSkin' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_clear$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    bool arg1 = false;       /** disposeData */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_bool(L, 2, &arg1);

    // void clear(@optional bool disposeData)
    self->clear(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_clear$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;

    olua_to_object(L, 1, &self, "db.BaseFactory");

    // void clear()
    self->clear();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_clear(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // void clear()
        return _olua_fun_dragonBones_BaseFactory_clear$2(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_bool(L, 2))) {
            // void clear(@optional bool disposeData)
            return _olua_fun_dragonBones_BaseFactory_clear$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::clear' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_getAllDragonBonesData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;

    olua_to_object(L, 1, &self, "db.BaseFactory");

    // const std::map<std::string, dragonBones::DragonBonesData *> &getAllDragonBonesData()
    const std::map<std::string, dragonBones::DragonBonesData *> &ret = self->getAllDragonBonesData();
    int num_ret = olua_push_map<std::string, dragonBones::DragonBonesData *>(L, ret, [L](std::string &arg1, dragonBones::DragonBonesData *arg2) {
        olua_push_string(L, arg1);
        olua_push_object(L, arg2, "db.DragonBonesData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_getArmatureData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */
    std::string arg2;       /** dragonBonesName */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // dragonBones::ArmatureData *getArmatureData(const std::string &name, @optional const std::string &dragonBonesName)
    dragonBones::ArmatureData *ret = self->getArmatureData(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_getArmatureData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);

    // dragonBones::ArmatureData *getArmatureData(const std::string &name)
    dragonBones::ArmatureData *ret = self->getArmatureData(arg1);
    int num_ret = olua_push_object(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_getArmatureData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2))) {
            // dragonBones::ArmatureData *getArmatureData(const std::string &name)
            return _olua_fun_dragonBones_BaseFactory_getArmatureData$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // dragonBones::ArmatureData *getArmatureData(const std::string &name, @optional const std::string &dragonBonesName)
            return _olua_fun_dragonBones_BaseFactory_getArmatureData$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::getArmatureData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_getClock(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;

    olua_to_object(L, 1, &self, "db.BaseFactory");

    // dragonBones::WorldClock *getClock()
    dragonBones::WorldClock *ret = self->getClock();
    int num_ret = olua_push_object(L, ret, "db.WorldClock");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_getDragonBonesData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);

    // dragonBones::DragonBonesData *getDragonBonesData(const std::string &name)
    dragonBones::DragonBonesData *ret = self->getDragonBonesData(arg1);
    int num_ret = olua_push_object(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_parseDragonBonesData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */
    std::string arg2;       /** name */
    float arg3 = 0;       /** scale */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name, @optional float scale)
    dragonBones::DragonBonesData *ret = self->parseDragonBonesData(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_parseDragonBonesData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);

    // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData)
    dragonBones::DragonBonesData *ret = self->parseDragonBonesData(arg1);
    int num_ret = olua_push_object(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_parseDragonBonesData$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */
    std::string arg2;       /** name */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name)
    dragonBones::DragonBonesData *ret = self->parseDragonBonesData(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_parseDragonBonesData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2))) {
            // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData)
            return _olua_fun_dragonBones_BaseFactory_parseDragonBonesData$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name)
            return _olua_fun_dragonBones_BaseFactory_parseDragonBonesData$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_number(L, 4))) {
            // dragonBones::DragonBonesData *parseDragonBonesData(const char *rawData, @optional const std::string &name, @optional float scale)
            return _olua_fun_dragonBones_BaseFactory_parseDragonBonesData$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::parseDragonBonesData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_parseTextureAtlasData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */
    void *arg2 = nullptr;       /** textureAtlas */
    std::string arg3;       /** name */
    float arg4 = 0;       /** scale */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "void *");
    olua_check_string(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name, @optional float scale)
    dragonBones::TextureAtlasData *ret = self->parseTextureAtlasData(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_parseTextureAtlasData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */
    void *arg2 = nullptr;       /** textureAtlas */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "void *");

    // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas)
    dragonBones::TextureAtlasData *ret = self->parseTextureAtlasData(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_parseTextureAtlasData$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    const char *arg1 = nullptr;       /** rawData */
    void *arg2 = nullptr;       /** textureAtlas */
    std::string arg3;       /** name */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "void *");
    olua_check_string(L, 4, &arg3);

    // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name)
    dragonBones::TextureAtlasData *ret = self->parseTextureAtlasData(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_parseTextureAtlasData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_object(L, 3, "void *"))) {
            // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas)
            return _olua_fun_dragonBones_BaseFactory_parseTextureAtlasData$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_object(L, 3, "void *")) && (olua_is_string(L, 4))) {
            // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name)
            return _olua_fun_dragonBones_BaseFactory_parseTextureAtlasData$3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_object(L, 3, "void *")) && (olua_is_string(L, 4)) && (olua_is_number(L, 5))) {
            // dragonBones::TextureAtlasData *parseTextureAtlasData(const char *rawData, void *textureAtlas, @optional const std::string &name, @optional float scale)
            return _olua_fun_dragonBones_BaseFactory_parseTextureAtlasData$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::parseTextureAtlasData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_removeDragonBonesData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */
    bool arg2 = false;       /** disposeData */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void removeDragonBonesData(const std::string &name, @optional bool disposeData)
    self->removeDragonBonesData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_removeDragonBonesData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);

    // void removeDragonBonesData(const std::string &name)
    self->removeDragonBonesData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_removeDragonBonesData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2))) {
            // void removeDragonBonesData(const std::string &name)
            return _olua_fun_dragonBones_BaseFactory_removeDragonBonesData$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void removeDragonBonesData(const std::string &name, @optional bool disposeData)
            return _olua_fun_dragonBones_BaseFactory_removeDragonBonesData$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::removeDragonBonesData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_removeTextureAtlasData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */
    bool arg2 = false;       /** disposeData */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void removeTextureAtlasData(const std::string &name, @optional bool disposeData)
    self->removeTextureAtlasData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_removeTextureAtlasData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);

    // void removeTextureAtlasData(const std::string &name)
    self->removeTextureAtlasData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_removeTextureAtlasData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2))) {
            // void removeTextureAtlasData(const std::string &name)
            return _olua_fun_dragonBones_BaseFactory_removeTextureAtlasData$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void removeTextureAtlasData(const std::string &name, @optional bool disposeData)
            return _olua_fun_dragonBones_BaseFactory_removeTextureAtlasData$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::removeTextureAtlasData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_replaceAnimation$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    dragonBones::ArmatureData *arg2 = nullptr;       /** armatureData */
    bool arg3 = false;       /** isReplaceAll */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.Armature");
    olua_check_object(L, 3, &arg2, "db.ArmatureData");
    olua_check_bool(L, 4, &arg3);

    // bool replaceAnimation(dragonBones::Armature *armature, dragonBones::ArmatureData *armatureData, @optional bool isReplaceAll)
    bool ret = self->replaceAnimation(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_replaceAnimation$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    dragonBones::ArmatureData *arg2 = nullptr;       /** armatureData */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.Armature");
    olua_check_object(L, 3, &arg2, "db.ArmatureData");

    // bool replaceAnimation(dragonBones::Armature *armature, dragonBones::ArmatureData *armatureData)
    bool ret = self->replaceAnimation(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_replaceAnimation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_object(L, 2, "db.Armature")) && (olua_is_object(L, 3, "db.ArmatureData"))) {
            // bool replaceAnimation(dragonBones::Armature *armature, dragonBones::ArmatureData *armatureData)
            return _olua_fun_dragonBones_BaseFactory_replaceAnimation$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_object(L, 2, "db.Armature")) && (olua_is_object(L, 3, "db.ArmatureData")) && (olua_is_bool(L, 4))) {
            // bool replaceAnimation(dragonBones::Armature *armature, dragonBones::ArmatureData *armatureData, @optional bool isReplaceAll)
            return _olua_fun_dragonBones_BaseFactory_replaceAnimation$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::replaceAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_replaceDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Slot *arg1 = nullptr;       /** slot */
    dragonBones::DisplayData *arg2 = nullptr;       /** displayData */
    int arg3 = 0;       /** displayIndex */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.Slot");
    olua_check_object(L, 3, &arg2, "db.DisplayData");
    olua_check_integer(L, 4, &arg3);

    // void replaceDisplay(dragonBones::Slot *slot, dragonBones::DisplayData *displayData, int displayIndex)
    self->replaceDisplay(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_replaceSkin$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    dragonBones::SkinData *arg2 = nullptr;       /** skin */
    bool arg3 = false;       /** isOverride */
    std::vector<std::string> *arg4 = nullptr;       /** exclude */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.Armature");
    olua_check_object(L, 3, &arg2, "db.SkinData");
    olua_check_bool(L, 4, &arg3);
    olua_check_pointer(L, 5, &arg4, "cc.types.VectorString");

    // bool replaceSkin(dragonBones::Armature *armature, dragonBones::SkinData *skin, @optional bool isOverride, @optional const std::vector<std::string> *exclude)
    bool ret = self->replaceSkin(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_replaceSkin$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    dragonBones::SkinData *arg2 = nullptr;       /** skin */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.Armature");
    olua_check_object(L, 3, &arg2, "db.SkinData");

    // bool replaceSkin(dragonBones::Armature *armature, dragonBones::SkinData *skin)
    bool ret = self->replaceSkin(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_replaceSkin$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */
    dragonBones::SkinData *arg2 = nullptr;       /** skin */
    bool arg3 = false;       /** isOverride */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_object(L, 2, &arg1, "db.Armature");
    olua_check_object(L, 3, &arg2, "db.SkinData");
    olua_check_bool(L, 4, &arg3);

    // bool replaceSkin(dragonBones::Armature *armature, dragonBones::SkinData *skin, @optional bool isOverride)
    bool ret = self->replaceSkin(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_replaceSkin(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_object(L, 2, "db.Armature")) && (olua_is_object(L, 3, "db.SkinData"))) {
            // bool replaceSkin(dragonBones::Armature *armature, dragonBones::SkinData *skin)
            return _olua_fun_dragonBones_BaseFactory_replaceSkin$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_object(L, 2, "db.Armature")) && (olua_is_object(L, 3, "db.SkinData")) && (olua_is_bool(L, 4))) {
            // bool replaceSkin(dragonBones::Armature *armature, dragonBones::SkinData *skin, @optional bool isOverride)
            return _olua_fun_dragonBones_BaseFactory_replaceSkin$3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_object(L, 2, "db.Armature")) && (olua_is_object(L, 3, "db.SkinData")) && (olua_is_bool(L, 4)) && (olua_is_pointer(L, 5, "cc.types.VectorString"))) {
            // bool replaceSkin(dragonBones::Armature *armature, dragonBones::SkinData *skin, @optional bool isOverride, @optional const std::vector<std::string> *exclude)
            return _olua_fun_dragonBones_BaseFactory_replaceSkin$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::replaceSkin' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_replaceSlotDisplay$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** dragonBonesName */
    std::string arg2;       /** armatureName */
    std::string arg3;       /** slotName */
    std::string arg4;       /** displayName */
    dragonBones::Slot *arg5 = nullptr;       /** slot */
    int arg6 = 0;       /** displayIndex */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "db.Slot");
    olua_check_integer(L, 7, &arg6);

    // bool replaceSlotDisplay(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, const std::string &displayName, dragonBones::Slot *slot, @optional int displayIndex)
    bool ret = self->replaceSlotDisplay(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_replaceSlotDisplay$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** dragonBonesName */
    std::string arg2;       /** armatureName */
    std::string arg3;       /** slotName */
    std::string arg4;       /** displayName */
    dragonBones::Slot *arg5 = nullptr;       /** slot */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "db.Slot");

    // bool replaceSlotDisplay(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, const std::string &displayName, dragonBones::Slot *slot)
    bool ret = self->replaceSlotDisplay(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_BaseFactory_replaceSlotDisplay(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_object(L, 6, "db.Slot"))) {
            // bool replaceSlotDisplay(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, const std::string &displayName, dragonBones::Slot *slot)
            return _olua_fun_dragonBones_BaseFactory_replaceSlotDisplay$2(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "db.BaseFactory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5)) && (olua_is_object(L, 6, "db.Slot")) && (olua_is_integer(L, 7))) {
            // bool replaceSlotDisplay(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, const std::string &displayName, dragonBones::Slot *slot, @optional int displayIndex)
            return _olua_fun_dragonBones_BaseFactory_replaceSlotDisplay$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::BaseFactory::replaceSlotDisplay' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_BaseFactory_replaceSlotDisplayList(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::BaseFactory *self = nullptr;
    std::string arg1;       /** dragonBonesName */
    std::string arg2;       /** armatureName */
    std::string arg3;       /** slotName */
    dragonBones::Slot *arg4 = nullptr;       /** slot */

    olua_to_object(L, 1, &self, "db.BaseFactory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "db.Slot");

    // bool replaceSlotDisplayList(const std::string &dragonBonesName, const std::string &armatureName, const std::string &slotName, dragonBones::Slot *slot)
    bool ret = self->replaceSlotDisplayList(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_db_BaseFactory(lua_State *L)
{
    oluacls_class<dragonBones::BaseFactory>(L, "db.BaseFactory");
    oluacls_func(L, "__gc", _olua_fun_dragonBones_BaseFactory___gc);
    oluacls_func(L, "addDragonBonesData", _olua_fun_dragonBones_BaseFactory_addDragonBonesData);
    oluacls_func(L, "addTextureAtlasData", _olua_fun_dragonBones_BaseFactory_addTextureAtlasData);
    oluacls_func(L, "buildArmature", _olua_fun_dragonBones_BaseFactory_buildArmature);
    oluacls_func(L, "changeSkin", _olua_fun_dragonBones_BaseFactory_changeSkin);
    oluacls_func(L, "clear", _olua_fun_dragonBones_BaseFactory_clear);
    oluacls_func(L, "getAllDragonBonesData", _olua_fun_dragonBones_BaseFactory_getAllDragonBonesData);
    oluacls_func(L, "getArmatureData", _olua_fun_dragonBones_BaseFactory_getArmatureData);
    oluacls_func(L, "getClock", _olua_fun_dragonBones_BaseFactory_getClock);
    oluacls_func(L, "getDragonBonesData", _olua_fun_dragonBones_BaseFactory_getDragonBonesData);
    oluacls_func(L, "parseDragonBonesData", _olua_fun_dragonBones_BaseFactory_parseDragonBonesData);
    oluacls_func(L, "parseTextureAtlasData", _olua_fun_dragonBones_BaseFactory_parseTextureAtlasData);
    oluacls_func(L, "removeDragonBonesData", _olua_fun_dragonBones_BaseFactory_removeDragonBonesData);
    oluacls_func(L, "removeTextureAtlasData", _olua_fun_dragonBones_BaseFactory_removeTextureAtlasData);
    oluacls_func(L, "replaceAnimation", _olua_fun_dragonBones_BaseFactory_replaceAnimation);
    oluacls_func(L, "replaceDisplay", _olua_fun_dragonBones_BaseFactory_replaceDisplay);
    oluacls_func(L, "replaceSkin", _olua_fun_dragonBones_BaseFactory_replaceSkin);
    oluacls_func(L, "replaceSlotDisplay", _olua_fun_dragonBones_BaseFactory_replaceSlotDisplay);
    oluacls_func(L, "replaceSlotDisplayList", _olua_fun_dragonBones_BaseFactory_replaceSlotDisplayList);
    oluacls_prop(L, "allDragonBonesData", _olua_fun_dragonBones_BaseFactory_getAllDragonBonesData, nullptr);
    oluacls_prop(L, "clock", _olua_fun_dragonBones_BaseFactory_getClock, nullptr);
    oluacls_prop(L, "autoSearch", _olua_fun_dragonBones_BaseFactory_autoSearch, _olua_fun_dragonBones_BaseFactory_autoSearch);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_BaseFactory(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.BaseFactory")) {
        luaL_error(L, "class not found: dragonBones::BaseFactory");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_Armature_as(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "db.BaseObject")) {
            olua_pushobj_as<dragonBones::BaseObject>(L, 1, self, "as.db.BaseObject");
            break;
        }

        luaL_error(L, "'dragonBones::Armature' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _olua_fun_dragonBones_Armature_clearPool$1(lua_State *L)
{
    olua_startinvoke(L);

    std::size_t arg1 = 0;       /** classTypeIndex */

    olua_check_integer(L, 1, &arg1);

    // @copyfrom(dragonBones::BaseObject) static void clearPool(@optional std::size_t classTypeIndex)
    dragonBones::Armature::clearPool(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_clearPool$2(lua_State *L)
{
    olua_startinvoke(L);

    // @copyfrom(dragonBones::BaseObject) static void clearPool()
    dragonBones::Armature::clearPool();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_clearPool(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @copyfrom(dragonBones::BaseObject) static void clearPool()
        return _olua_fun_dragonBones_Armature_clearPool$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @copyfrom(dragonBones::BaseObject) static void clearPool(@optional std::size_t classTypeIndex)
            return _olua_fun_dragonBones_Armature_clearPool$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Armature::clearPool' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Armature_containsPoint(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::Slot *containsPoint(float x, float y)
    dragonBones::Slot *ret = self->containsPoint(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_dispose(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // void dispose()
    self->dispose();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_getAnimatable(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // dragonBones::IAnimatable *getAnimatable()
    dragonBones::IAnimatable *ret = self->getAnimatable();
    int num_ret = olua_push_object(L, ret, "db.IAnimatable");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // dragonBones::Animation *getAnimation()
    dragonBones::Animation *ret = self->getAnimation();
    int num_ret = olua_push_object(L, ret, "db.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getArmatureData(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // const dragonBones::ArmatureData *getArmatureData()
    const dragonBones::ArmatureData *ret = self->getArmatureData();
    int num_ret = olua_push_object(L, ret, "db.ArmatureData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getBone(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_string(L, 2, &arg1);

    // dragonBones::Bone *getBone(const std::string &name)
    dragonBones::Bone *ret = self->getBone(arg1);
    int num_ret = olua_push_object(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getBoneByDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    void *arg1 = nullptr;       /** display */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_object(L, 2, &arg1, "void *");

    // dragonBones::Bone *getBoneByDisplay(void *display)
    dragonBones::Bone *ret = self->getBoneByDisplay(arg1);
    int num_ret = olua_push_object(L, ret, "db.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getBones(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // const std::vector<dragonBones::Bone *> &getBones()
    const std::vector<dragonBones::Bone *> &ret = self->getBones();
    int num_ret = olua_push_array<dragonBones::Bone *>(L, ret, [L](dragonBones::Bone *arg1) {
        olua_push_object(L, arg1, "db.Bone");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getCacheFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // unsigned int getCacheFrameRate()
    unsigned int ret = self->getCacheFrameRate();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getClassTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // std::size_t getClassTypeIndex()
    std::size_t ret = self->getClassTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // void *getDisplay()
    void *ret = self->getDisplay();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getEventDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // dragonBones::IEventDispatcher *getEventDispatcher()
    dragonBones::IEventDispatcher *ret = self->getEventDispatcher();
    int num_ret = olua_push_object(L, ret, "db.IEventDispatcher");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getFlipX(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // bool getFlipX()
    bool ret = self->getFlipX();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getFlipY(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // bool getFlipY()
    bool ret = self->getFlipY();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getName(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // const std::string &getName()
    const std::string &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getParent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // dragonBones::Slot *getParent()
    dragonBones::Slot *ret = self->getParent();
    int num_ret = olua_push_object(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getProxy(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // dragonBones::IArmatureProxy *getProxy()
    dragonBones::IArmatureProxy *ret = self->getProxy();
    int num_ret = olua_push_object(L, ret, "db.IArmatureProxy");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getReplacedTexture(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // void *getReplacedTexture()
    void *ret = self->getReplacedTexture();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getSlot(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_string(L, 2, &arg1);

    // dragonBones::Slot *getSlot(const std::string &name)
    dragonBones::Slot *ret = self->getSlot(arg1);
    int num_ret = olua_push_object(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getSlotByDisplay(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    void *arg1 = nullptr;       /** display */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_object(L, 2, &arg1, "void *");

    // dragonBones::Slot *getSlotByDisplay(void *display)
    dragonBones::Slot *ret = self->getSlotByDisplay(arg1);
    int num_ret = olua_push_object(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getSlots(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // const std::vector<dragonBones::Slot *> &getSlots()
    const std::vector<dragonBones::Slot *> &ret = self->getSlots();
    int num_ret = olua_push_array<dragonBones::Slot *>(L, ret, [L](dragonBones::Slot *arg1) {
        olua_push_object(L, arg1, "db.Slot");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::Armature::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_hashCode(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // @readonly @copyfrom(dragonBones::BaseObject) const unsigned int hashCode
    const unsigned int ret = self->hashCode;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_inheritAnimation$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // bool inheritAnimation
    bool ret = self->inheritAnimation;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_inheritAnimation$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    bool arg1 = false;       /** inheritAnimation */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_bool(L, 2, &arg1);

    // bool inheritAnimation
    self->inheritAnimation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_inheritAnimation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool inheritAnimation
        return _olua_fun_dragonBones_Armature_inheritAnimation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Armature")) && (olua_is_bool(L, 2))) {
            // bool inheritAnimation
            return _olua_fun_dragonBones_Armature_inheritAnimation$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Armature::inheritAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Armature_init(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    dragonBones::ArmatureData *arg1 = nullptr;       /** armatureData */
    dragonBones::IArmatureProxy *arg2 = nullptr;       /** proxy */
    void *arg3 = nullptr;       /** display */
    dragonBones::DragonBones *arg4 = nullptr;       /** dragonBones */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_object(L, 2, &arg1, "db.ArmatureData");
    olua_check_object(L, 3, &arg2, "db.IArmatureProxy");
    olua_check_object(L, 4, &arg3, "void *");
    olua_check_object(L, 5, &arg4, "db.DragonBones");

    // void init(dragonBones::ArmatureData *armatureData, dragonBones::IArmatureProxy *proxy, void *display, dragonBones::DragonBones *dragonBones)
    self->init(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_intersectsSegment$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */
    dragonBones::Point *arg7 = nullptr;       /** normalRadians */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "db.Point");
    olua_check_object(L, 7, &arg6, "db.Point");
    olua_check_object(L, 8, &arg7, "db.Point");

    // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
    dragonBones::Slot *ret = self->intersectsSegment(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    int num_ret = olua_push_object(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_intersectsSegment$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB)
    dragonBones::Slot *ret = self->intersectsSegment(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_intersectsSegment$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "db.Point");

    // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA)
    dragonBones::Slot *ret = self->intersectsSegment(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_object(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_intersectsSegment$4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    float arg1 = 0;       /** xA */
    float arg2 = 0;       /** yA */
    float arg3 = 0;       /** xB */
    float arg4 = 0;       /** yB */
    dragonBones::Point *arg5 = nullptr;       /** intersectionPointA */
    dragonBones::Point *arg6 = nullptr;       /** intersectionPointB */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "db.Point");
    olua_check_object(L, 7, &arg6, "db.Point");

    // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB)
    dragonBones::Slot *ret = self->intersectsSegment(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_object(L, ret, "db.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_intersectsSegment(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "db.Armature")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB)
            return _olua_fun_dragonBones_Armature_intersectsSegment$2(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "db.Armature")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_object(L, 6, "db.Point"))) {
            // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA)
            return _olua_fun_dragonBones_Armature_intersectsSegment$3(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "db.Armature")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_object(L, 6, "db.Point")) && (olua_is_object(L, 7, "db.Point"))) {
            // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB)
            return _olua_fun_dragonBones_Armature_intersectsSegment$4(L);
        // }
    }

    if (num_args == 8) {
        // if ((olua_is_object(L, 1, "db.Armature")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_object(L, 6, "db.Point")) && (olua_is_object(L, 7, "db.Point")) && (olua_is_object(L, 8, "db.Point"))) {
            // dragonBones::Slot *intersectsSegment(float xA, float yA, float xB, float yB, @optional dragonBones::Point *intersectionPointA, @optional dragonBones::Point *intersectionPointB, @optional dragonBones::Point *normalRadians)
            return _olua_fun_dragonBones_Armature_intersectsSegment$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Armature::intersectsSegment' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Armature_invalidUpdate$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    std::string arg1;       /** boneName */
    bool arg2 = false;       /** updateSlot */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_string(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void invalidUpdate(@optional const std::string &boneName, @optional bool updateSlot)
    self->invalidUpdate(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_invalidUpdate$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // void invalidUpdate()
    self->invalidUpdate();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_invalidUpdate$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_string(L, 2, &arg1);

    // void invalidUpdate(@optional const std::string &boneName)
    self->invalidUpdate(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_invalidUpdate(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // void invalidUpdate()
        return _olua_fun_dragonBones_Armature_invalidUpdate$2(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Armature")) && (olua_is_string(L, 2))) {
            // void invalidUpdate(@optional const std::string &boneName)
            return _olua_fun_dragonBones_Armature_invalidUpdate$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Armature")) && (olua_is_string(L, 2)) && (olua_is_bool(L, 3))) {
            // void invalidUpdate(@optional const std::string &boneName, @optional bool updateSlot)
            return _olua_fun_dragonBones_Armature_invalidUpdate$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Armature::invalidUpdate' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Armature_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::Armature()
    dragonBones::Armature *ret = new dragonBones::Armature();
    int num_ret = olua_push_object(L, ret, "db.Armature");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_returnToPool(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // @copyfrom(dragonBones::BaseObject) void returnToPool()
    self->returnToPool();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_setCacheFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    unsigned int arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_integer(L, 2, &arg1);

    // void setCacheFrameRate(unsigned int value)
    self->setCacheFrameRate(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_setFlipX(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_bool(L, 2, &arg1);

    // void setFlipX(bool value)
    self->setFlipX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_setFlipY(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_bool(L, 2, &arg1);

    // void setFlipY(bool value)
    self->setFlipY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_setMaxCount(lua_State *L)
{
    olua_startinvoke(L);

    std::size_t arg1 = 0;       /** classTypeIndex */
    unsigned int arg2 = 0;       /** maxCount */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);

    // @copyfrom(dragonBones::BaseObject) static void setMaxCount(std::size_t classTypeIndex, unsigned int maxCount)
    dragonBones::Armature::setMaxCount(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_setReplacedTexture(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    void *arg1 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_object(L, 2, &arg1, "void *");

    // void setReplacedTexture(void *value)
    self->setReplacedTexture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_userData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;

    olua_to_object(L, 1, &self, "db.Armature");

    // void *userData
    void *ret = self->userData;
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Armature_userData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Armature *self = nullptr;
    void *arg1 = nullptr;       /** userData */

    olua_to_object(L, 1, &self, "db.Armature");
    olua_check_object(L, 2, &arg1, "void *");

    // void *userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Armature_userData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // void *userData
        return _olua_fun_dragonBones_Armature_userData$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Armature")) && (olua_is_object(L, 2, "void *"))) {
            // void *userData
            return _olua_fun_dragonBones_Armature_userData$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Armature::userData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_Armature(lua_State *L)
{
    oluacls_class<dragonBones::Armature, dragonBones::IAnimatable>(L, "db.Armature");
    oluacls_func(L, "as", _olua_fun_dragonBones_Armature_as);
    oluacls_func(L, "clearPool", _olua_fun_dragonBones_Armature_clearPool);
    oluacls_func(L, "containsPoint", _olua_fun_dragonBones_Armature_containsPoint);
    oluacls_func(L, "dispose", _olua_fun_dragonBones_Armature_dispose);
    oluacls_func(L, "getAnimatable", _olua_fun_dragonBones_Armature_getAnimatable);
    oluacls_func(L, "getAnimation", _olua_fun_dragonBones_Armature_getAnimation);
    oluacls_func(L, "getArmatureData", _olua_fun_dragonBones_Armature_getArmatureData);
    oluacls_func(L, "getBone", _olua_fun_dragonBones_Armature_getBone);
    oluacls_func(L, "getBoneByDisplay", _olua_fun_dragonBones_Armature_getBoneByDisplay);
    oluacls_func(L, "getBones", _olua_fun_dragonBones_Armature_getBones);
    oluacls_func(L, "getCacheFrameRate", _olua_fun_dragonBones_Armature_getCacheFrameRate);
    oluacls_func(L, "getClassTypeIndex", _olua_fun_dragonBones_Armature_getClassTypeIndex);
    oluacls_func(L, "getDisplay", _olua_fun_dragonBones_Armature_getDisplay);
    oluacls_func(L, "getEventDispatcher", _olua_fun_dragonBones_Armature_getEventDispatcher);
    oluacls_func(L, "getFlipX", _olua_fun_dragonBones_Armature_getFlipX);
    oluacls_func(L, "getFlipY", _olua_fun_dragonBones_Armature_getFlipY);
    oluacls_func(L, "getName", _olua_fun_dragonBones_Armature_getName);
    oluacls_func(L, "getParent", _olua_fun_dragonBones_Armature_getParent);
    oluacls_func(L, "getProxy", _olua_fun_dragonBones_Armature_getProxy);
    oluacls_func(L, "getReplacedTexture", _olua_fun_dragonBones_Armature_getReplacedTexture);
    oluacls_func(L, "getSlot", _olua_fun_dragonBones_Armature_getSlot);
    oluacls_func(L, "getSlotByDisplay", _olua_fun_dragonBones_Armature_getSlotByDisplay);
    oluacls_func(L, "getSlots", _olua_fun_dragonBones_Armature_getSlots);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_Armature_getTypeIndex);
    oluacls_func(L, "init", _olua_fun_dragonBones_Armature_init);
    oluacls_func(L, "intersectsSegment", _olua_fun_dragonBones_Armature_intersectsSegment);
    oluacls_func(L, "invalidUpdate", _olua_fun_dragonBones_Armature_invalidUpdate);
    oluacls_func(L, "new", _olua_fun_dragonBones_Armature_new);
    oluacls_func(L, "returnToPool", _olua_fun_dragonBones_Armature_returnToPool);
    oluacls_func(L, "setCacheFrameRate", _olua_fun_dragonBones_Armature_setCacheFrameRate);
    oluacls_func(L, "setFlipX", _olua_fun_dragonBones_Armature_setFlipX);
    oluacls_func(L, "setFlipY", _olua_fun_dragonBones_Armature_setFlipY);
    oluacls_func(L, "setMaxCount", _olua_fun_dragonBones_Armature_setMaxCount);
    oluacls_func(L, "setReplacedTexture", _olua_fun_dragonBones_Armature_setReplacedTexture);
    oluacls_prop(L, "animatable", _olua_fun_dragonBones_Armature_getAnimatable, nullptr);
    oluacls_prop(L, "animation", _olua_fun_dragonBones_Armature_getAnimation, nullptr);
    oluacls_prop(L, "armatureData", _olua_fun_dragonBones_Armature_getArmatureData, nullptr);
    oluacls_prop(L, "bones", _olua_fun_dragonBones_Armature_getBones, nullptr);
    oluacls_prop(L, "cacheFrameRate", _olua_fun_dragonBones_Armature_getCacheFrameRate, _olua_fun_dragonBones_Armature_setCacheFrameRate);
    oluacls_prop(L, "classTypeIndex", _olua_fun_dragonBones_Armature_getClassTypeIndex, nullptr);
    oluacls_prop(L, "display", _olua_fun_dragonBones_Armature_getDisplay, nullptr);
    oluacls_prop(L, "eventDispatcher", _olua_fun_dragonBones_Armature_getEventDispatcher, nullptr);
    oluacls_prop(L, "flipX", _olua_fun_dragonBones_Armature_getFlipX, _olua_fun_dragonBones_Armature_setFlipX);
    oluacls_prop(L, "flipY", _olua_fun_dragonBones_Armature_getFlipY, _olua_fun_dragonBones_Armature_setFlipY);
    oluacls_prop(L, "name", _olua_fun_dragonBones_Armature_getName, nullptr);
    oluacls_prop(L, "parent", _olua_fun_dragonBones_Armature_getParent, nullptr);
    oluacls_prop(L, "proxy", _olua_fun_dragonBones_Armature_getProxy, nullptr);
    oluacls_prop(L, "replacedTexture", _olua_fun_dragonBones_Armature_getReplacedTexture, _olua_fun_dragonBones_Armature_setReplacedTexture);
    oluacls_prop(L, "slots", _olua_fun_dragonBones_Armature_getSlots, nullptr);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_Armature_getTypeIndex, nullptr);
    oluacls_prop(L, "inheritAnimation", _olua_fun_dragonBones_Armature_inheritAnimation, _olua_fun_dragonBones_Armature_inheritAnimation);
    oluacls_prop(L, "userData", _olua_fun_dragonBones_Armature_userData, _olua_fun_dragonBones_Armature_userData);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_Armature(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.Armature")) {
        luaL_error(L, "class not found: dragonBones::Armature");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_Animation_advanceTime(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    float arg1 = 0;       /** passedTime */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_number(L, 2, &arg1);

    // void advanceTime(float passedTime)
    self->advanceTime(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Animation_fadeIn$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    float arg2 = 0;       /** fadeInTime */
    int arg3 = 0;       /** playTimes */
    int arg4 = 0;       /** layer */
    std::string arg5;       /** group */
    dragonBones::AnimationFadeOutMode arg6 = (dragonBones::AnimationFadeOutMode)0;       /** fadeOutMode */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);
    olua_check_enum(L, 7, &arg6);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
    dragonBones::AnimationState *ret = self->fadeIn(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_fadeIn$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName)
    dragonBones::AnimationState *ret = self->fadeIn(arg1);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_fadeIn$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    float arg2 = 0;       /** fadeInTime */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime)
    dragonBones::AnimationState *ret = self->fadeIn(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_fadeIn$4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    float arg2 = 0;       /** fadeInTime */
    int arg3 = 0;       /** playTimes */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes)
    dragonBones::AnimationState *ret = self->fadeIn(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_fadeIn$5(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    float arg2 = 0;       /** fadeInTime */
    int arg3 = 0;       /** playTimes */
    int arg4 = 0;       /** layer */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer)
    dragonBones::AnimationState *ret = self->fadeIn(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_fadeIn$6(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    float arg2 = 0;       /** fadeInTime */
    int arg3 = 0;       /** playTimes */
    int arg4 = 0;       /** layer */
    std::string arg5;       /** group */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);
    olua_check_string(L, 6, &arg5);

    // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group)
    dragonBones::AnimationState *ret = self->fadeIn(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_fadeIn(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName)
            return _olua_fun_dragonBones_Animation_fadeIn$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime)
            return _olua_fun_dragonBones_Animation_fadeIn$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_integer(L, 4))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes)
            return _olua_fun_dragonBones_Animation_fadeIn$4(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_integer(L, 5))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer)
            return _olua_fun_dragonBones_Animation_fadeIn$5(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_integer(L, 5)) && (olua_is_string(L, 6))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group)
            return _olua_fun_dragonBones_Animation_fadeIn$6(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_integer(L, 5)) && (olua_is_string(L, 6)) && (olua_is_enum(L, 7))) {
            // dragonBones::AnimationState *fadeIn(const std::string &animationName, @optional float fadeInTime, @optional int playTimes, @optional int layer, @optional const std::string &group, @optional dragonBones::AnimationFadeOutMode fadeOutMode)
            return _olua_fun_dragonBones_Animation_fadeIn$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::fadeIn' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Animation_getAnimationConfig(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "db.Animation");

    // dragonBones::AnimationConfig *getAnimationConfig()
    dragonBones::AnimationConfig *ret = self->getAnimationConfig();
    int num_ret = olua_push_object(L, ret, "db.AnimationConfig");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_getAnimationNames(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "db.Animation");

    // const std::vector<std::string> &getAnimationNames()
    const std::vector<std::string> &ret = self->getAnimationNames();
    int num_ret = olua_push_array<std::string>(L, ret, [L](std::string &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_getAnimations(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "db.Animation");

    // const std::map<std::string, dragonBones::AnimationData *> &getAnimations()
    const std::map<std::string, dragonBones::AnimationData *> &ret = self->getAnimations();
    int num_ret = olua_push_map<std::string, dragonBones::AnimationData *>(L, ret, [L](std::string &arg1, dragonBones::AnimationData *arg2) {
        olua_push_string(L, arg1);
        olua_push_object(L, arg2, "db.AnimationData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_getLastAnimationName(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "db.Animation");

    // const std::string &getLastAnimationName()
    const std::string &ret = self->getLastAnimationName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_getLastAnimationState(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "db.Animation");

    // dragonBones::AnimationState *getLastAnimationState()
    dragonBones::AnimationState *ret = self->getLastAnimationState();
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_getState(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);

    // dragonBones::AnimationState *getState(const std::string &animationName)
    dragonBones::AnimationState *ret = self->getState(arg1);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_getStates(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "db.Animation");

    // const std::vector<dragonBones::AnimationState *> &getStates()
    const std::vector<dragonBones::AnimationState *> &ret = self->getStates();
    int num_ret = olua_push_array<dragonBones::AnimationState *>(L, ret, [L](dragonBones::AnimationState *arg1) {
        olua_push_object(L, arg1, "db.AnimationState");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_getTypeIndex(lua_State *L)
{
    olua_startinvoke(L);

    // static std::size_t getTypeIndex()
    std::size_t ret = dragonBones::Animation::getTypeIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByFrame$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    unsigned int arg2 = 0;       /** frame */
    int arg3 = 0;       /** playTimes */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);

    // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByFrame(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByFrame$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName)
    dragonBones::AnimationState *ret = self->gotoAndPlayByFrame(arg1);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByFrame$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    unsigned int arg2 = 0;       /** frame */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame)
    dragonBones::AnimationState *ret = self->gotoAndPlayByFrame(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByFrame(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName)
            return _olua_fun_dragonBones_Animation_gotoAndPlayByFrame$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_integer(L, 3))) {
            // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame)
            return _olua_fun_dragonBones_Animation_gotoAndPlayByFrame$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_integer(L, 4))) {
            // dragonBones::AnimationState *gotoAndPlayByFrame(const std::string &animationName, @optional unsigned int frame, @optional int playTimes)
            return _olua_fun_dragonBones_Animation_gotoAndPlayByFrame$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndPlayByFrame' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByProgress$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    float arg2 = 0;       /** progress */
    int arg3 = 0;       /** playTimes */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);

    // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByProgress(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByProgress$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName)
    dragonBones::AnimationState *ret = self->gotoAndPlayByProgress(arg1);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByProgress$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    float arg2 = 0;       /** progress */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress)
    dragonBones::AnimationState *ret = self->gotoAndPlayByProgress(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByProgress(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName)
            return _olua_fun_dragonBones_Animation_gotoAndPlayByProgress$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress)
            return _olua_fun_dragonBones_Animation_gotoAndPlayByProgress$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_integer(L, 4))) {
            // dragonBones::AnimationState *gotoAndPlayByProgress(const std::string &animationName, @optional float progress, @optional int playTimes)
            return _olua_fun_dragonBones_Animation_gotoAndPlayByProgress$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndPlayByProgress' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByTime$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    float arg2 = 0;       /** time */
    int arg3 = 0;       /** playTimes */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);

    // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time, @optional int playTimes)
    dragonBones::AnimationState *ret = self->gotoAndPlayByTime(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByTime$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName)
    dragonBones::AnimationState *ret = self->gotoAndPlayByTime(arg1);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByTime$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    float arg2 = 0;       /** time */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time)
    dragonBones::AnimationState *ret = self->gotoAndPlayByTime(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndPlayByTime(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName)
            return _olua_fun_dragonBones_Animation_gotoAndPlayByTime$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time)
            return _olua_fun_dragonBones_Animation_gotoAndPlayByTime$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_number(L, 3)) && (olua_is_integer(L, 4))) {
            // dragonBones::AnimationState *gotoAndPlayByTime(const std::string &animationName, @optional float time, @optional int playTimes)
            return _olua_fun_dragonBones_Animation_gotoAndPlayByTime$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndPlayByTime' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Animation_gotoAndStopByFrame$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    unsigned int arg2 = 0;       /** frame */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndStopByFrame(const std::string &animationName, @optional unsigned int frame)
    dragonBones::AnimationState *ret = self->gotoAndStopByFrame(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndStopByFrame$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndStopByFrame(const std::string &animationName)
    dragonBones::AnimationState *ret = self->gotoAndStopByFrame(arg1);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndStopByFrame(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndStopByFrame(const std::string &animationName)
            return _olua_fun_dragonBones_Animation_gotoAndStopByFrame$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_integer(L, 3))) {
            // dragonBones::AnimationState *gotoAndStopByFrame(const std::string &animationName, @optional unsigned int frame)
            return _olua_fun_dragonBones_Animation_gotoAndStopByFrame$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndStopByFrame' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Animation_gotoAndStopByProgress$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    float arg2 = 0;       /** progress */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndStopByProgress(const std::string &animationName, @optional float progress)
    dragonBones::AnimationState *ret = self->gotoAndStopByProgress(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndStopByProgress$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndStopByProgress(const std::string &animationName)
    dragonBones::AnimationState *ret = self->gotoAndStopByProgress(arg1);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndStopByProgress(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndStopByProgress(const std::string &animationName)
            return _olua_fun_dragonBones_Animation_gotoAndStopByProgress$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // dragonBones::AnimationState *gotoAndStopByProgress(const std::string &animationName, @optional float progress)
            return _olua_fun_dragonBones_Animation_gotoAndStopByProgress$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndStopByProgress' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Animation_gotoAndStopByTime$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    float arg2 = 0;       /** time */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // dragonBones::AnimationState *gotoAndStopByTime(const std::string &animationName, @optional float time)
    dragonBones::AnimationState *ret = self->gotoAndStopByTime(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndStopByTime$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);

    // dragonBones::AnimationState *gotoAndStopByTime(const std::string &animationName)
    dragonBones::AnimationState *ret = self->gotoAndStopByTime(arg1);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_gotoAndStopByTime(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2))) {
            // dragonBones::AnimationState *gotoAndStopByTime(const std::string &animationName)
            return _olua_fun_dragonBones_Animation_gotoAndStopByTime$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // dragonBones::AnimationState *gotoAndStopByTime(const std::string &animationName, @optional float time)
            return _olua_fun_dragonBones_Animation_gotoAndStopByTime$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::gotoAndStopByTime' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Animation_hasAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);

    // bool hasAnimation(const std::string &animationName)
    bool ret = self->hasAnimation(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_init(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_object(L, 2, &arg1, "db.Armature");

    // void init(dragonBones::Armature *armature)
    self->init(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Animation_isCompleted(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "db.Animation");

    // bool isCompleted()
    bool ret = self->isCompleted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_isPlaying(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "db.Animation");

    // bool isPlaying()
    bool ret = self->isPlaying();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::Animation()
    dragonBones::Animation *ret = new dragonBones::Animation();
    int num_ret = olua_push_object(L, ret, "db.Animation");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_play$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */
    int arg2 = 0;       /** playTimes */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // dragonBones::AnimationState *play(@optional const std::string &animationName, @optional int playTimes)
    dragonBones::AnimationState *ret = self->play(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_play$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "db.Animation");

    // dragonBones::AnimationState *play()
    dragonBones::AnimationState *ret = self->play();
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_play$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);

    // dragonBones::AnimationState *play(@optional const std::string &animationName)
    dragonBones::AnimationState *ret = self->play(arg1);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_play(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // dragonBones::AnimationState *play()
        return _olua_fun_dragonBones_Animation_play$2(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2))) {
            // dragonBones::AnimationState *play(@optional const std::string &animationName)
            return _olua_fun_dragonBones_Animation_play$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_string(L, 2)) && (olua_is_integer(L, 3))) {
            // dragonBones::AnimationState *play(@optional const std::string &animationName, @optional int playTimes)
            return _olua_fun_dragonBones_Animation_play$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::play' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_Animation_playConfig(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    dragonBones::AnimationConfig *arg1 = nullptr;       /** animationConfig */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_object(L, 2, &arg1, "db.AnimationConfig");

    // dragonBones::AnimationState *playConfig(dragonBones::AnimationConfig *animationConfig)
    dragonBones::AnimationState *ret = self->playConfig(arg1);
    int num_ret = olua_push_object(L, ret, "db.AnimationState");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_reset(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "db.Animation");

    // void reset()
    self->reset();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Animation_setAnimations(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::map<std::string, dragonBones::AnimationData *> arg1;       /** value */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_map<std::string, dragonBones::AnimationData *>(L, 2, arg1, [L](std::string *arg1, dragonBones::AnimationData **arg2) {
        olua_check_string(L, -1, arg1);
        olua_check_object(L, -2, arg2, "db.AnimationData");
    });

    // void setAnimations(const std::map<std::string, dragonBones::AnimationData *> &value)
    self->setAnimations(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Animation_stop(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    std::string arg1;       /** animationName */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_string(L, 2, &arg1);

    // void stop(const std::string &animationName)
    self->stop(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Animation_timeScale$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "db.Animation");

    // float timeScale
    float ret = self->timeScale;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_Animation_timeScale$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::Animation *self = nullptr;
    float arg1 = 0;       /** timeScale */

    olua_to_object(L, 1, &self, "db.Animation");
    olua_check_number(L, 2, &arg1);

    // float timeScale
    self->timeScale = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_Animation_timeScale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float timeScale
        return _olua_fun_dragonBones_Animation_timeScale$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Animation")) && (olua_is_number(L, 2))) {
            // float timeScale
            return _olua_fun_dragonBones_Animation_timeScale$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::Animation::timeScale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_db_Animation(lua_State *L)
{
    oluacls_class<dragonBones::Animation, dragonBones::BaseObject>(L, "db.Animation");
    oluacls_func(L, "advanceTime", _olua_fun_dragonBones_Animation_advanceTime);
    oluacls_func(L, "fadeIn", _olua_fun_dragonBones_Animation_fadeIn);
    oluacls_func(L, "getAnimationConfig", _olua_fun_dragonBones_Animation_getAnimationConfig);
    oluacls_func(L, "getAnimationNames", _olua_fun_dragonBones_Animation_getAnimationNames);
    oluacls_func(L, "getAnimations", _olua_fun_dragonBones_Animation_getAnimations);
    oluacls_func(L, "getLastAnimationName", _olua_fun_dragonBones_Animation_getLastAnimationName);
    oluacls_func(L, "getLastAnimationState", _olua_fun_dragonBones_Animation_getLastAnimationState);
    oluacls_func(L, "getState", _olua_fun_dragonBones_Animation_getState);
    oluacls_func(L, "getStates", _olua_fun_dragonBones_Animation_getStates);
    oluacls_func(L, "getTypeIndex", _olua_fun_dragonBones_Animation_getTypeIndex);
    oluacls_func(L, "gotoAndPlayByFrame", _olua_fun_dragonBones_Animation_gotoAndPlayByFrame);
    oluacls_func(L, "gotoAndPlayByProgress", _olua_fun_dragonBones_Animation_gotoAndPlayByProgress);
    oluacls_func(L, "gotoAndPlayByTime", _olua_fun_dragonBones_Animation_gotoAndPlayByTime);
    oluacls_func(L, "gotoAndStopByFrame", _olua_fun_dragonBones_Animation_gotoAndStopByFrame);
    oluacls_func(L, "gotoAndStopByProgress", _olua_fun_dragonBones_Animation_gotoAndStopByProgress);
    oluacls_func(L, "gotoAndStopByTime", _olua_fun_dragonBones_Animation_gotoAndStopByTime);
    oluacls_func(L, "hasAnimation", _olua_fun_dragonBones_Animation_hasAnimation);
    oluacls_func(L, "init", _olua_fun_dragonBones_Animation_init);
    oluacls_func(L, "isCompleted", _olua_fun_dragonBones_Animation_isCompleted);
    oluacls_func(L, "isPlaying", _olua_fun_dragonBones_Animation_isPlaying);
    oluacls_func(L, "new", _olua_fun_dragonBones_Animation_new);
    oluacls_func(L, "play", _olua_fun_dragonBones_Animation_play);
    oluacls_func(L, "playConfig", _olua_fun_dragonBones_Animation_playConfig);
    oluacls_func(L, "reset", _olua_fun_dragonBones_Animation_reset);
    oluacls_func(L, "setAnimations", _olua_fun_dragonBones_Animation_setAnimations);
    oluacls_func(L, "stop", _olua_fun_dragonBones_Animation_stop);
    oluacls_prop(L, "animationConfig", _olua_fun_dragonBones_Animation_getAnimationConfig, nullptr);
    oluacls_prop(L, "animationNames", _olua_fun_dragonBones_Animation_getAnimationNames, nullptr);
    oluacls_prop(L, "animations", _olua_fun_dragonBones_Animation_getAnimations, _olua_fun_dragonBones_Animation_setAnimations);
    oluacls_prop(L, "completed", _olua_fun_dragonBones_Animation_isCompleted, nullptr);
    oluacls_prop(L, "lastAnimationName", _olua_fun_dragonBones_Animation_getLastAnimationName, nullptr);
    oluacls_prop(L, "lastAnimationState", _olua_fun_dragonBones_Animation_getLastAnimationState, nullptr);
    oluacls_prop(L, "playing", _olua_fun_dragonBones_Animation_isPlaying, nullptr);
    oluacls_prop(L, "states", _olua_fun_dragonBones_Animation_getStates, nullptr);
    oluacls_prop(L, "typeIndex", _olua_fun_dragonBones_Animation_getTypeIndex, nullptr);
    oluacls_prop(L, "timeScale", _olua_fun_dragonBones_Animation_timeScale, _olua_fun_dragonBones_Animation_timeScale);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_Animation(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.Animation")) {
        luaL_error(L, "class not found: dragonBones::Animation");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_CCFactory_buildArmatureDisplay$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */
    std::string arg3;       /** skinName */
    std::string arg4;       /** textureAtlasName */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);
    olua_check_string(L, 5, &arg4);

    // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
    dragonBones::CCArmatureDisplay *ret = self->buildArmatureDisplay(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_buildArmatureDisplay$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** armatureName */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);

    // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName)
    dragonBones::CCArmatureDisplay *ret = self->buildArmatureDisplay(arg1);
    int num_ret = olua_push_object(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_buildArmatureDisplay$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName)
    dragonBones::CCArmatureDisplay *ret = self->buildArmatureDisplay(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_buildArmatureDisplay$4(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** armatureName */
    std::string arg2;       /** dragonBonesName */
    std::string arg3;       /** skinName */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_string(L, 4, &arg3);

    // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName)
    dragonBones::CCArmatureDisplay *ret = self->buildArmatureDisplay(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_buildArmatureDisplay(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2))) {
            // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName)
            return _olua_fun_dragonBones_CCFactory_buildArmatureDisplay$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName)
            return _olua_fun_dragonBones_CCFactory_buildArmatureDisplay$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4))) {
            // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName)
            return _olua_fun_dragonBones_CCFactory_buildArmatureDisplay$4(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_string(L, 4)) && (olua_is_string(L, 5))) {
            // dragonBones::CCArmatureDisplay *buildArmatureDisplay(const std::string &armatureName, @optional const std::string &dragonBonesName, @optional const std::string &skinName, @optional const std::string &textureAtlasName)
            return _olua_fun_dragonBones_CCFactory_buildArmatureDisplay$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CCFactory::buildArmatureDisplay' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_CCFactory_getClock(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::WorldClock *getClock()
    dragonBones::WorldClock *ret = dragonBones::CCFactory::getClock();
    int num_ret = olua_push_object(L, ret, "db.WorldClock");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_getFactory(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::CCFactory *getFactory()
    dragonBones::CCFactory *ret = dragonBones::CCFactory::getFactory();
    int num_ret = olua_push_object(L, ret, "db.Factory");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_getSoundEventManager(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;

    olua_to_object(L, 1, &self, "db.Factory");

    // dragonBones::CCArmatureDisplay *getSoundEventManager()
    dragonBones::CCArmatureDisplay *ret = self->getSoundEventManager();
    int num_ret = olua_push_object(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_getTextureDisplay$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** textureName */
    std::string arg2;       /** dragonBonesName */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // cocos2d::Sprite *getTextureDisplay(const std::string &textureName, @optional const std::string &dragonBonesName)
    cocos2d::Sprite *ret = self->getTextureDisplay(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_getTextureDisplay$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** textureName */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);

    // cocos2d::Sprite *getTextureDisplay(const std::string &textureName)
    cocos2d::Sprite *ret = self->getTextureDisplay(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_getTextureDisplay(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2))) {
            // cocos2d::Sprite *getTextureDisplay(const std::string &textureName)
            return _olua_fun_dragonBones_CCFactory_getTextureDisplay$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // cocos2d::Sprite *getTextureDisplay(const std::string &textureName, @optional const std::string &dragonBonesName)
            return _olua_fun_dragonBones_CCFactory_getTextureDisplay$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CCFactory::getTextureDisplay' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_CCFactory_loadDragonBonesData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */
    std::string arg2;       /** name */
    float arg3 = 0;       /** scale */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name, @optional float scale)
    dragonBones::DragonBonesData *ret = self->loadDragonBonesData(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_loadDragonBonesData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);

    // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath)
    dragonBones::DragonBonesData *ret = self->loadDragonBonesData(arg1);
    int num_ret = olua_push_object(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_loadDragonBonesData$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */
    std::string arg2;       /** name */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name)
    dragonBones::DragonBonesData *ret = self->loadDragonBonesData(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.DragonBonesData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_loadDragonBonesData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2))) {
            // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath)
            return _olua_fun_dragonBones_CCFactory_loadDragonBonesData$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name)
            return _olua_fun_dragonBones_CCFactory_loadDragonBonesData$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_number(L, 4))) {
            // dragonBones::DragonBonesData *loadDragonBonesData(const std::string &filePath, @optional const std::string &name, @optional float scale)
            return _olua_fun_dragonBones_CCFactory_loadDragonBonesData$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CCFactory::loadDragonBonesData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_CCFactory_loadTextureAtlasData$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */
    std::string arg2;       /** name */
    float arg3 = 0;       /** scale */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name, @optional float scale)
    dragonBones::TextureAtlasData *ret = self->loadTextureAtlasData(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_loadTextureAtlasData$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);

    // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath)
    dragonBones::TextureAtlasData *ret = self->loadTextureAtlasData(arg1);
    int num_ret = olua_push_object(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_loadTextureAtlasData$3(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCFactory *self = nullptr;
    std::string arg1;       /** filePath */
    std::string arg2;       /** name */

    olua_to_object(L, 1, &self, "db.Factory");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name)
    dragonBones::TextureAtlasData *ret = self->loadTextureAtlasData(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "db.TextureAtlasData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCFactory_loadTextureAtlasData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2))) {
            // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath)
            return _olua_fun_dragonBones_CCFactory_loadTextureAtlasData$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name)
            return _olua_fun_dragonBones_CCFactory_loadTextureAtlasData$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "db.Factory")) && (olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_number(L, 4))) {
            // dragonBones::TextureAtlasData *loadTextureAtlasData(const std::string &filePath, @optional const std::string &name, @optional float scale)
            return _olua_fun_dragonBones_CCFactory_loadTextureAtlasData$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CCFactory::loadTextureAtlasData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_CCFactory_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::CCFactory()
    dragonBones::CCFactory *ret = new dragonBones::CCFactory();
    int num_ret = olua_push_object(L, ret, "db.Factory");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_db_Factory(lua_State *L)
{
    oluacls_class<dragonBones::CCFactory, dragonBones::BaseFactory>(L, "db.Factory");
    oluacls_func(L, "buildArmatureDisplay", _olua_fun_dragonBones_CCFactory_buildArmatureDisplay);
    oluacls_func(L, "getClock", _olua_fun_dragonBones_CCFactory_getClock);
    oluacls_func(L, "getFactory", _olua_fun_dragonBones_CCFactory_getFactory);
    oluacls_func(L, "getSoundEventManager", _olua_fun_dragonBones_CCFactory_getSoundEventManager);
    oluacls_func(L, "getTextureDisplay", _olua_fun_dragonBones_CCFactory_getTextureDisplay);
    oluacls_func(L, "loadDragonBonesData", _olua_fun_dragonBones_CCFactory_loadDragonBonesData);
    oluacls_func(L, "loadTextureAtlasData", _olua_fun_dragonBones_CCFactory_loadTextureAtlasData);
    oluacls_func(L, "new", _olua_fun_dragonBones_CCFactory_new);
    oluacls_prop(L, "clock", _olua_fun_dragonBones_CCFactory_getClock, nullptr);
    oluacls_prop(L, "factory", _olua_fun_dragonBones_CCFactory_getFactory, nullptr);
    oluacls_prop(L, "soundEventManager", _olua_fun_dragonBones_CCFactory_getSoundEventManager, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_Factory(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.Factory")) {
        luaL_error(L, "class not found: dragonBones::CCFactory");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_IEventDispatcher___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (dragonBones::IEventDispatcher *)olua_toobj(L, 1, "db.IEventDispatcher");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IEventDispatcher_addDBEventListener(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IEventDispatcher *self = nullptr;
    std::string arg1;       /** type */
    std::function<void (dragonBones::EventObject *)> arg2;       /** listener */

    olua_to_object(L, 1, &self, "db.IEventDispatcher");
    olua_check_string(L, 2, &arg1);
    olua_check_callback(L, 3, &arg2, "std.function");

    void *cb_store = (void *)self;
    std::string cb_tag = "addDBEventListener";
    std::string cb_name = olua_setcallback(L, cb_store, 3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg2 = [cb_store, cb_name, cb_ctx /*, ML */](dragonBones::EventObject *cb_arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_object(L, cb_arg1, "db.EventObject");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void addDBEventListener(const std::string &type, const std::function<void (dragonBones::EventObject *)> &listener)
    self->addDBEventListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IEventDispatcher_dispatchDBEvent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IEventDispatcher *self = nullptr;
    std::string arg1;       /** type */
    dragonBones::EventObject *arg2 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.IEventDispatcher");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "db.EventObject");

    // void dispatchDBEvent(const std::string &type, dragonBones::EventObject *value)
    self->dispatchDBEvent(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IEventDispatcher_hasDBEventListener(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IEventDispatcher *self = nullptr;
    std::string arg1;       /** type */

    olua_to_object(L, 1, &self, "db.IEventDispatcher");
    olua_check_string(L, 2, &arg1);

    // bool hasDBEventListener(const std::string &type)
    bool ret = self->hasDBEventListener(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_IEventDispatcher_removeDBEventListener(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IEventDispatcher *self = nullptr;
    std::string arg1;       /** type */
    std::function<void (dragonBones::EventObject *)> arg2;       /** listener */

    olua_to_object(L, 1, &self, "db.IEventDispatcher");
    olua_check_string(L, 2, &arg1);
    olua_check_callback(L, 3, &arg2, "std.function");

    void *cb_store = (void *)self;
    std::string cb_tag = "removeDBEventListener";
    std::string cb_name = olua_setcallback(L, cb_store, 3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg2 = [cb_store, cb_name, cb_ctx /*, ML */](dragonBones::EventObject *cb_arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_object(L, cb_arg1, "db.EventObject");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void removeDBEventListener(const std::string &type, const std::function<void (dragonBones::EventObject *)> &listener)
    self->removeDBEventListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_db_IEventDispatcher(lua_State *L)
{
    oluacls_class<dragonBones::IEventDispatcher>(L, "db.IEventDispatcher");
    oluacls_func(L, "__gc", _olua_fun_dragonBones_IEventDispatcher___gc);
    oluacls_func(L, "addDBEventListener", _olua_fun_dragonBones_IEventDispatcher_addDBEventListener);
    oluacls_func(L, "dispatchDBEvent", _olua_fun_dragonBones_IEventDispatcher_dispatchDBEvent);
    oluacls_func(L, "hasDBEventListener", _olua_fun_dragonBones_IEventDispatcher_hasDBEventListener);
    oluacls_func(L, "removeDBEventListener", _olua_fun_dragonBones_IEventDispatcher_removeDBEventListener);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_IEventDispatcher(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.IEventDispatcher")) {
        luaL_error(L, "class not found: dragonBones::IEventDispatcher");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_IArmatureProxy_dbClear(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IArmatureProxy *self = nullptr;

    olua_to_object(L, 1, &self, "db.IArmatureProxy");

    // void dbClear()
    self->dbClear();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IArmatureProxy_dbInit(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IArmatureProxy *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */

    olua_to_object(L, 1, &self, "db.IArmatureProxy");
    olua_check_object(L, 2, &arg1, "db.Armature");

    // void dbInit(dragonBones::Armature *armature)
    self->dbInit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IArmatureProxy_dbUpdate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IArmatureProxy *self = nullptr;

    olua_to_object(L, 1, &self, "db.IArmatureProxy");

    // void dbUpdate()
    self->dbUpdate();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IArmatureProxy_dispose(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IArmatureProxy *self = nullptr;
    bool arg1 = false;       /** disposeProxy */

    olua_to_object(L, 1, &self, "db.IArmatureProxy");
    olua_check_bool(L, 2, &arg1);

    // void dispose(bool disposeProxy)
    self->dispose(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_IArmatureProxy_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IArmatureProxy *self = nullptr;

    olua_to_object(L, 1, &self, "db.IArmatureProxy");

    // dragonBones::Animation *getAnimation()
    dragonBones::Animation *ret = self->getAnimation();
    int num_ret = olua_push_object(L, ret, "db.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_IArmatureProxy_getArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::IArmatureProxy *self = nullptr;

    olua_to_object(L, 1, &self, "db.IArmatureProxy");

    // dragonBones::Armature *getArmature()
    dragonBones::Armature *ret = self->getArmature();
    int num_ret = olua_push_object(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_db_IArmatureProxy(lua_State *L)
{
    oluacls_class<dragonBones::IArmatureProxy, dragonBones::IEventDispatcher>(L, "db.IArmatureProxy");
    oluacls_func(L, "dbClear", _olua_fun_dragonBones_IArmatureProxy_dbClear);
    oluacls_func(L, "dbInit", _olua_fun_dragonBones_IArmatureProxy_dbInit);
    oluacls_func(L, "dbUpdate", _olua_fun_dragonBones_IArmatureProxy_dbUpdate);
    oluacls_func(L, "dispose", _olua_fun_dragonBones_IArmatureProxy_dispose);
    oluacls_func(L, "getAnimation", _olua_fun_dragonBones_IArmatureProxy_getAnimation);
    oluacls_func(L, "getArmature", _olua_fun_dragonBones_IArmatureProxy_getArmature);
    oluacls_prop(L, "animation", _olua_fun_dragonBones_IArmatureProxy_getAnimation, nullptr);
    oluacls_prop(L, "armature", _olua_fun_dragonBones_IArmatureProxy_getArmature, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_IArmatureProxy(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.IArmatureProxy")) {
        luaL_error(L, "class not found: dragonBones::IArmatureProxy");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_dragonBones_CCArmatureDisplay_addDBEventListener(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    std::string arg1;       /** type */
    std::function<void (dragonBones::EventObject *)> arg2;       /** listener */

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");
    olua_check_string(L, 2, &arg1);
    olua_check_callback(L, 3, &arg2, "std.function");

    void *cb_store = (void *)self;
    std::string cb_tag = (arg1);
    std::string cb_name = olua_setcallback(L, cb_store, 3, cb_tag.c_str(), OLUA_TAG_NEW);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg2 = [cb_store, cb_name, cb_ctx /*, ML */](dragonBones::EventObject *cb_arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_object(L, cb_arg1, "db.EventObject");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void addDBEventListener(const std::string &type, const std::function<void (dragonBones::EventObject *)> &listener)
    self->addDBEventListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_as(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "db.IArmatureProxy")) {
            olua_pushobj_as<dragonBones::IArmatureProxy>(L, 1, self, "as.db.IArmatureProxy");
            break;
        }
        if (olua_strequal(arg1, "db.IEventDispatcher")) {
            olua_pushobj_as<dragonBones::IEventDispatcher>(L, 1, self, "as.db.IEventDispatcher");
            break;
        }

        luaL_error(L, "'dragonBones::CCArmatureDisplay' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_create(lua_State *L)
{
    olua_startinvoke(L);

    // static dragonBones::CCArmatureDisplay *create()
    dragonBones::CCArmatureDisplay *ret = dragonBones::CCArmatureDisplay::create();
    int num_ret = olua_push_object(L, ret, "db.ArmatureDisplay");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_dbClear(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");

    // void dbClear()
    self->dbClear();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_dbInit(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    dragonBones::Armature *arg1 = nullptr;       /** armature */

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");
    olua_check_object(L, 2, &arg1, "db.Armature");

    // void dbInit(dragonBones::Armature *armature)
    self->dbInit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_dbUpdate(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");

    // void dbUpdate()
    self->dbUpdate();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_debugDraw$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");

    // bool debugDraw
    bool ret = self->debugDraw;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_debugDraw$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    bool arg1 = false;       /** debugDraw */

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");
    olua_check_bool(L, 2, &arg1);

    // bool debugDraw
    self->debugDraw = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_debugDraw(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool debugDraw
        return _olua_fun_dragonBones_CCArmatureDisplay_debugDraw$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureDisplay")) && (olua_is_bool(L, 2))) {
            // bool debugDraw
            return _olua_fun_dragonBones_CCArmatureDisplay_debugDraw$2(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CCArmatureDisplay::debugDraw' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_dispatchDBEvent(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    std::string arg1;       /** type */
    dragonBones::EventObject *arg2 = nullptr;       /** value */

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "db.EventObject");

    // void dispatchDBEvent(const std::string &type, dragonBones::EventObject *value)
    self->dispatchDBEvent(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_dispose$1(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    bool arg1 = false;       /** disposeProxy */

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");
    olua_check_bool(L, 2, &arg1);

    // void dispose(@optional bool disposeProxy)
    self->dispose(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_dispose$2(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");

    // void dispose()
    self->dispose();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_dispose(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // void dispose()
        return _olua_fun_dragonBones_CCArmatureDisplay_dispose$2(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "db.ArmatureDisplay")) && (olua_is_bool(L, 2))) {
            // void dispose(@optional bool disposeProxy)
            return _olua_fun_dragonBones_CCArmatureDisplay_dispose$1(L);
        // }
    }

    luaL_error(L, "method 'dragonBones::CCArmatureDisplay::dispose' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");

    // dragonBones::Animation *getAnimation()
    dragonBones::Animation *ret = self->getAnimation();
    int num_ret = olua_push_object(L, ret, "db.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_getArmature(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");

    // dragonBones::Armature *getArmature()
    dragonBones::Armature *ret = self->getArmature();
    int num_ret = olua_push_object(L, ret, "db.Armature");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_hasDBEventListener(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    std::string arg1;       /** type */

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");
    olua_check_string(L, 2, &arg1);

    // bool hasDBEventListener(const std::string &type)
    bool ret = self->hasDBEventListener(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_new(lua_State *L)
{
    olua_startinvoke(L);

    // dragonBones::CCArmatureDisplay()
    dragonBones::CCArmatureDisplay *ret = new dragonBones::CCArmatureDisplay();
    int num_ret = olua_push_object(L, ret, "db.ArmatureDisplay");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_dragonBones_CCArmatureDisplay_removeDBEventListener(lua_State *L)
{
    olua_startinvoke(L);

    dragonBones::CCArmatureDisplay *self = nullptr;
    std::string arg1;       /** type */
    std::function<void (dragonBones::EventObject *)> arg2;       /** listener */

    olua_to_object(L, 1, &self, "db.ArmatureDisplay");
    olua_check_string(L, 2, &arg1);
    if (!olua_isnoneornil(L, 3)) {
        olua_check_callback(L, 3, &arg2, "std.function");
    }

    std::string cb_tag = (arg1);
    void *cb_store = (void *)self;
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // void removeDBEventListener(const std::string &type, @nullable const std::function<void (dragonBones::EventObject *)> &listener)
    self->removeDBEventListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_db_ArmatureDisplay(lua_State *L)
{
    oluacls_class<dragonBones::CCArmatureDisplay, cocos2d::Node>(L, "db.ArmatureDisplay");
    oluacls_func(L, "addDBEventListener", _olua_fun_dragonBones_CCArmatureDisplay_addDBEventListener);
    oluacls_func(L, "as", _olua_fun_dragonBones_CCArmatureDisplay_as);
    oluacls_func(L, "create", _olua_fun_dragonBones_CCArmatureDisplay_create);
    oluacls_func(L, "dbClear", _olua_fun_dragonBones_CCArmatureDisplay_dbClear);
    oluacls_func(L, "dbInit", _olua_fun_dragonBones_CCArmatureDisplay_dbInit);
    oluacls_func(L, "dbUpdate", _olua_fun_dragonBones_CCArmatureDisplay_dbUpdate);
    oluacls_func(L, "dispatchDBEvent", _olua_fun_dragonBones_CCArmatureDisplay_dispatchDBEvent);
    oluacls_func(L, "dispose", _olua_fun_dragonBones_CCArmatureDisplay_dispose);
    oluacls_func(L, "getAnimation", _olua_fun_dragonBones_CCArmatureDisplay_getAnimation);
    oluacls_func(L, "getArmature", _olua_fun_dragonBones_CCArmatureDisplay_getArmature);
    oluacls_func(L, "hasDBEventListener", _olua_fun_dragonBones_CCArmatureDisplay_hasDBEventListener);
    oluacls_func(L, "new", _olua_fun_dragonBones_CCArmatureDisplay_new);
    oluacls_func(L, "removeDBEventListener", _olua_fun_dragonBones_CCArmatureDisplay_removeDBEventListener);
    oluacls_prop(L, "animation", _olua_fun_dragonBones_CCArmatureDisplay_getAnimation, nullptr);
    oluacls_prop(L, "armature", _olua_fun_dragonBones_CCArmatureDisplay_getArmature, nullptr);
    oluacls_prop(L, "debugDraw", _olua_fun_dragonBones_CCArmatureDisplay_debugDraw, _olua_fun_dragonBones_CCArmatureDisplay_debugDraw);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_db_ArmatureDisplay(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);
    if (!olua_getclass(L, "db.ArmatureDisplay")) {
        luaL_error(L, "class not found: dragonBones::CCArmatureDisplay");
    }
    return 1;
}
OLUA_END_DECLS

int _olua_module_dragonbones(lua_State *L)
{
    olua_require(L, "db.Rectangle", _olua_cls_db_Rectangle);
    olua_require(L, "db.BinaryOffset", _olua_cls_db_BinaryOffset);
    olua_require(L, "db.ArmatureType", _olua_cls_db_ArmatureType);
    olua_require(L, "db.OffsetMode", _olua_cls_db_OffsetMode);
    olua_require(L, "db.DisplayType", _olua_cls_db_DisplayType);
    olua_require(L, "db.BoundingBoxType", _olua_cls_db_BoundingBoxType);
    olua_require(L, "db.ActionType", _olua_cls_db_ActionType);
    olua_require(L, "db.BlendMode", _olua_cls_db_BlendMode);
    olua_require(L, "db.TweenType", _olua_cls_db_TweenType);
    olua_require(L, "db.TimelineType", _olua_cls_db_TimelineType);
    olua_require(L, "db.AnimationFadeOutMode", _olua_cls_db_AnimationFadeOutMode);
    olua_require(L, "db.TextureFormat", _olua_cls_db_TextureFormat);
    olua_require(L, "db.DragonBones", _olua_cls_db_DragonBones);
    olua_require(L, "db.BaseObject", _olua_cls_db_BaseObject);
    olua_require(L, "db.EventObject", _olua_cls_db_EventObject);
    olua_require(L, "db.TransformObject", _olua_cls_db_TransformObject);
    olua_require(L, "db.Point", _olua_cls_db_Point);
    olua_require(L, "db.ConstraintData", _olua_cls_db_ConstraintData);
    olua_require(L, "db.IKConstraintData", _olua_cls_db_IKConstraintData);
    olua_require(L, "db.TimelineData", _olua_cls_db_TimelineData);
    olua_require(L, "db.IAnimatable", _olua_cls_db_IAnimatable);
    olua_require(L, "db.WorldClock", _olua_cls_db_WorldClock);
    olua_require(L, "db.Slot", _olua_cls_db_Slot);
    olua_require(L, "db.Bone", _olua_cls_db_Bone);
    olua_require(L, "db.DisplayData", _olua_cls_db_DisplayData);
    olua_require(L, "db.ActionData", _olua_cls_db_ActionData);
    olua_require(L, "db.UserData", _olua_cls_db_UserData);
    olua_require(L, "db.BoundingBoxData", _olua_cls_db_BoundingBoxData);
    olua_require(L, "db.BoundingBoxDisplayData", _olua_cls_db_BoundingBoxDisplayData);
    olua_require(L, "db.CanvasData", _olua_cls_db_CanvasData);
    olua_require(L, "db.TextureAtlasData", _olua_cls_db_TextureAtlasData);
    olua_require(L, "db.TextureData", _olua_cls_db_TextureData);
    olua_require(L, "db.ArmatureData", _olua_cls_db_ArmatureData);
    olua_require(L, "db.SkinData", _olua_cls_db_SkinData);
    olua_require(L, "db.BoneData", _olua_cls_db_BoneData);
    olua_require(L, "db.SlotData", _olua_cls_db_SlotData);
    olua_require(L, "db.AnimationState", _olua_cls_db_AnimationState);
    olua_require(L, "db.AnimationData", _olua_cls_db_AnimationData);
    olua_require(L, "db.AnimationConfig", _olua_cls_db_AnimationConfig);
    olua_require(L, "db.DragonBonesData", _olua_cls_db_DragonBonesData);
    olua_require(L, "db.BaseFactory", _olua_cls_db_BaseFactory);
    olua_require(L, "db.Armature", _olua_cls_db_Armature);
    olua_require(L, "db.Animation", _olua_cls_db_Animation);
    olua_require(L, "db.Factory", _olua_cls_db_Factory);
    olua_require(L, "db.IEventDispatcher", _olua_cls_db_IEventDispatcher);
    olua_require(L, "db.IArmatureProxy", _olua_cls_db_IArmatureProxy);
    olua_require(L, "db.ArmatureDisplay", _olua_cls_db_ArmatureDisplay);

    cclua::runtime::registerFeature("dragonbones", true);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_dragonbones(lua_State *L)
{
    olua_require(L, "dragonbones",  _olua_module_dragonbones);

    return 0;
}
OLUA_END_DECLS
