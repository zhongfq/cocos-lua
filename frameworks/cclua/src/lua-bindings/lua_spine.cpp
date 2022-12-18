//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_spine.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_EventType(lua_State *L)
{
    oluacls_class<spine::EventType>(L, "spine.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Complete", (lua_Integer)spine::EventType::EventType_Complete);
    oluacls_enum(L, "Dispose", (lua_Integer)spine::EventType::EventType_Dispose);
    oluacls_enum(L, "End", (lua_Integer)spine::EventType::EventType_End);
    oluacls_enum(L, "Event", (lua_Integer)spine::EventType::EventType_Event);
    oluacls_enum(L, "Interrupt", (lua_Integer)spine::EventType::EventType_Interrupt);
    oluacls_enum(L, "Start", (lua_Integer)spine::EventType::EventType_Start);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_AttachmentType(lua_State *L)
{
    oluacls_class<spine::AttachmentType>(L, "spine.AttachmentType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Boundingbox", (lua_Integer)spine::AttachmentType::AttachmentType_Boundingbox);
    oluacls_enum(L, "Clipping", (lua_Integer)spine::AttachmentType::AttachmentType_Clipping);
    oluacls_enum(L, "Linkedmesh", (lua_Integer)spine::AttachmentType::AttachmentType_Linkedmesh);
    oluacls_enum(L, "Mesh", (lua_Integer)spine::AttachmentType::AttachmentType_Mesh);
    oluacls_enum(L, "Path", (lua_Integer)spine::AttachmentType::AttachmentType_Path);
    oluacls_enum(L, "Point", (lua_Integer)spine::AttachmentType::AttachmentType_Point);
    oluacls_enum(L, "Region", (lua_Integer)spine::AttachmentType::AttachmentType_Region);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_TransformMode(lua_State *L)
{
    oluacls_class<spine::TransformMode>(L, "spine.TransformMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "NoRotationOrReflection", (lua_Integer)spine::TransformMode::TransformMode_NoRotationOrReflection);
    oluacls_enum(L, "NoScale", (lua_Integer)spine::TransformMode::TransformMode_NoScale);
    oluacls_enum(L, "NoScaleOrReflection", (lua_Integer)spine::TransformMode::TransformMode_NoScaleOrReflection);
    oluacls_enum(L, "Normal", (lua_Integer)spine::TransformMode::TransformMode_Normal);
    oluacls_enum(L, "OnlyTranslation", (lua_Integer)spine::TransformMode::TransformMode_OnlyTranslation);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_BlendMode(lua_State *L)
{
    oluacls_class<spine::BlendMode>(L, "spine.BlendMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Additive", (lua_Integer)spine::BlendMode::BlendMode_Additive);
    oluacls_enum(L, "Multiply", (lua_Integer)spine::BlendMode::BlendMode_Multiply);
    oluacls_enum(L, "Normal", (lua_Integer)spine::BlendMode::BlendMode_Normal);
    oluacls_enum(L, "Screen", (lua_Integer)spine::BlendMode::BlendMode_Screen);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_PositionMode(lua_State *L)
{
    oluacls_class<spine::PositionMode>(L, "spine.PositionMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Fixed", (lua_Integer)spine::PositionMode::PositionMode_Fixed);
    oluacls_enum(L, "Percent", (lua_Integer)spine::PositionMode::PositionMode_Percent);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_SpacingMode(lua_State *L)
{
    oluacls_class<spine::SpacingMode>(L, "spine.SpacingMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Fixed", (lua_Integer)spine::SpacingMode::SpacingMode_Fixed);
    oluacls_enum(L, "Length", (lua_Integer)spine::SpacingMode::SpacingMode_Length);
    oluacls_enum(L, "Percent", (lua_Integer)spine::SpacingMode::SpacingMode_Percent);
    oluacls_enum(L, "Proportional", (lua_Integer)spine::SpacingMode::SpacingMode_Proportional);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_RotateMode(lua_State *L)
{
    oluacls_class<spine::RotateMode>(L, "spine.RotateMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Chain", (lua_Integer)spine::RotateMode::RotateMode_Chain);
    oluacls_enum(L, "ChainScale", (lua_Integer)spine::RotateMode::RotateMode_ChainScale);
    oluacls_enum(L, "Tangent", (lua_Integer)spine::RotateMode::RotateMode_Tangent);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_MixBlend(lua_State *L)
{
    oluacls_class<spine::MixBlend>(L, "spine.MixBlend");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Add", (lua_Integer)spine::MixBlend::MixBlend_Add);
    oluacls_enum(L, "First", (lua_Integer)spine::MixBlend::MixBlend_First);
    oluacls_enum(L, "Replace", (lua_Integer)spine::MixBlend::MixBlend_Replace);
    oluacls_enum(L, "Setup", (lua_Integer)spine::MixBlend::MixBlend_Setup);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_MixDirection(lua_State *L)
{
    oluacls_class<spine::MixDirection>(L, "spine.MixDirection");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "In", (lua_Integer)spine::MixDirection::MixDirection_In);
    oluacls_enum(L, "Out", (lua_Integer)spine::MixDirection::MixDirection_Out);

    return 1;
}
OLUA_END_DECLS

static int _spine_SpineObject___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::SpineObject *)olua_toobj(L, 1, "spine.SpineObject");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SpineObject___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::SpineObject *)olua_toobj(L, 1, "spine.SpineObject");
    olua_push_object(L, self, "spine.SpineObject");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_SpineObject(lua_State *L)
{
    oluacls_class<spine::SpineObject>(L, "spine.SpineObject");
    oluacls_func(L, "__gc", _spine_SpineObject___gc);
    oluacls_func(L, "__olua_move", _spine_SpineObject___olua_move);

    return 1;
}
OLUA_END_DECLS

static int _spine_Event_getBalance(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Event");

    // float getBalance()
    float ret = self->getBalance();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getData(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Event");

    // const spine::EventData &getData()
    const spine::EventData &ret = self->getData();
    int num_ret = olua_push_object(L, ret, "spine.EventData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getFloatValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Event");

    // float getFloatValue()
    float ret = self->getFloatValue();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getIntValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Event");

    // int getIntValue()
    int ret = self->getIntValue();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getStringValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Event");

    // const spine::String &getStringValue()
    const spine::String &ret = self->getStringValue();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Event");

    // float getTime()
    float ret = self->getTime();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getVolume(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Event");

    // float getVolume()
    float ret = self->getVolume();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_setBalance(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Event");
    olua_check_number(L, 2, &arg1);

    // void setBalance(float inValue)
    self->setBalance(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Event_setFloatValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Event");
    olua_check_number(L, 2, &arg1);

    // void setFloatValue(float inValue)
    self->setFloatValue(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Event_setIntValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Event");
    olua_check_integer(L, 2, &arg1);

    // void setIntValue(int inValue)
    self->setIntValue(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Event_setStringValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Event");
    olua_check_string(L, 2, &arg1);

    // void setStringValue(const spine::String &inValue)
    self->setStringValue(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Event_setVolume(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Event");
    olua_check_number(L, 2, &arg1);

    // void setVolume(float inValue)
    self->setVolume(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Event(lua_State *L)
{
    oluacls_class<spine::Event, spine::SpineObject>(L, "spine.Event");
    oluacls_func(L, "getBalance", _spine_Event_getBalance);
    oluacls_func(L, "getData", _spine_Event_getData);
    oluacls_func(L, "getFloatValue", _spine_Event_getFloatValue);
    oluacls_func(L, "getIntValue", _spine_Event_getIntValue);
    oluacls_func(L, "getStringValue", _spine_Event_getStringValue);
    oluacls_func(L, "getTime", _spine_Event_getTime);
    oluacls_func(L, "getVolume", _spine_Event_getVolume);
    oluacls_func(L, "setBalance", _spine_Event_setBalance);
    oluacls_func(L, "setFloatValue", _spine_Event_setFloatValue);
    oluacls_func(L, "setIntValue", _spine_Event_setIntValue);
    oluacls_func(L, "setStringValue", _spine_Event_setStringValue);
    oluacls_func(L, "setVolume", _spine_Event_setVolume);
    oluacls_prop(L, "balance", _spine_Event_getBalance, _spine_Event_setBalance);
    oluacls_prop(L, "data", _spine_Event_getData, nullptr);
    oluacls_prop(L, "floatValue", _spine_Event_getFloatValue, _spine_Event_setFloatValue);
    oluacls_prop(L, "intValue", _spine_Event_getIntValue, _spine_Event_setIntValue);
    oluacls_prop(L, "stringValue", _spine_Event_getStringValue, _spine_Event_setStringValue);
    oluacls_prop(L, "time", _spine_Event_getTime, nullptr);
    oluacls_prop(L, "volume", _spine_Event_getVolume, _spine_Event_setVolume);

    return 1;
}
OLUA_END_DECLS

static int _spine_EventData_getAudioPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.EventData");

    // const spine::String &getAudioPath()
    const spine::String &ret = self->getAudioPath();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getBalance(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.EventData");

    // float getBalance()
    float ret = self->getBalance();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getFloatValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.EventData");

    // float getFloatValue()
    float ret = self->getFloatValue();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getIntValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.EventData");

    // int getIntValue()
    int ret = self->getIntValue();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.EventData");

    // const spine::String &getName()
    const spine::String &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getStringValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.EventData");

    // const spine::String &getStringValue()
    const spine::String &ret = self->getStringValue();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getVolume(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.EventData");

    // float getVolume()
    float ret = self->getVolume();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // EventData(const spine::String &name)
    spine::EventData *ret = new spine::EventData(arg1);
    int num_ret = olua_push_object(L, ret, "spine.EventData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_setAudioPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_object(L, 1, &self, "spine.EventData");
    olua_check_string(L, 2, &arg1);

    // void setAudioPath(const spine::String &inValue)
    self->setAudioPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventData_setBalance(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.EventData");
    olua_check_number(L, 2, &arg1);

    // void setBalance(float inValue)
    self->setBalance(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventData_setFloatValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.EventData");
    olua_check_number(L, 2, &arg1);

    // void setFloatValue(float inValue)
    self->setFloatValue(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventData_setIntValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.EventData");
    olua_check_integer(L, 2, &arg1);

    // void setIntValue(int inValue)
    self->setIntValue(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventData_setStringValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_object(L, 1, &self, "spine.EventData");
    olua_check_string(L, 2, &arg1);

    // void setStringValue(const spine::String &inValue)
    self->setStringValue(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventData_setVolume(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.EventData");
    olua_check_number(L, 2, &arg1);

    // void setVolume(float inValue)
    self->setVolume(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_EventData(lua_State *L)
{
    oluacls_class<spine::EventData, spine::SpineObject>(L, "spine.EventData");
    oluacls_func(L, "getAudioPath", _spine_EventData_getAudioPath);
    oluacls_func(L, "getBalance", _spine_EventData_getBalance);
    oluacls_func(L, "getFloatValue", _spine_EventData_getFloatValue);
    oluacls_func(L, "getIntValue", _spine_EventData_getIntValue);
    oluacls_func(L, "getName", _spine_EventData_getName);
    oluacls_func(L, "getStringValue", _spine_EventData_getStringValue);
    oluacls_func(L, "getVolume", _spine_EventData_getVolume);
    oluacls_func(L, "new", _spine_EventData_new);
    oluacls_func(L, "setAudioPath", _spine_EventData_setAudioPath);
    oluacls_func(L, "setBalance", _spine_EventData_setBalance);
    oluacls_func(L, "setFloatValue", _spine_EventData_setFloatValue);
    oluacls_func(L, "setIntValue", _spine_EventData_setIntValue);
    oluacls_func(L, "setStringValue", _spine_EventData_setStringValue);
    oluacls_func(L, "setVolume", _spine_EventData_setVolume);
    oluacls_prop(L, "audioPath", _spine_EventData_getAudioPath, _spine_EventData_setAudioPath);
    oluacls_prop(L, "balance", _spine_EventData_getBalance, _spine_EventData_setBalance);
    oluacls_prop(L, "floatValue", _spine_EventData_getFloatValue, _spine_EventData_setFloatValue);
    oluacls_prop(L, "intValue", _spine_EventData_getIntValue, _spine_EventData_setIntValue);
    oluacls_prop(L, "name", _spine_EventData_getName, nullptr);
    oluacls_prop(L, "stringValue", _spine_EventData_getStringValue, _spine_EventData_setStringValue);
    oluacls_prop(L, "volume", _spine_EventData_getVolume, _spine_EventData_setVolume);

    return 1;
}
OLUA_END_DECLS

static int _spine_Updatable_isActive(lua_State *L)
{
    olua_startinvoke(L);

    spine::Updatable *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Updatable");

    // bool isActive()
    bool ret = self->isActive();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Updatable_setActive(lua_State *L)
{
    olua_startinvoke(L);

    spine::Updatable *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Updatable");
    olua_check_bool(L, 2, &arg1);

    // void setActive(bool inValue)
    self->setActive(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Updatable_update(lua_State *L)
{
    olua_startinvoke(L);

    spine::Updatable *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Updatable");

    // void update()
    self->update();

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Updatable(lua_State *L)
{
    oluacls_class<spine::Updatable, spine::SpineObject>(L, "spine.Updatable");
    oluacls_func(L, "isActive", _spine_Updatable_isActive);
    oluacls_func(L, "setActive", _spine_Updatable_setActive);
    oluacls_func(L, "update", _spine_Updatable_update);
    oluacls_prop(L, "active", _spine_Updatable_isActive, _spine_Updatable_setActive);

    return 1;
}
OLUA_END_DECLS

static int _spine_AnimationStateListener___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (spine::AnimationStateListener *)nullptr, "spine.AnimationStateListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_AnimationStateListener(lua_State *L)
{
    oluacls_class<spine::AnimationStateListener>(L, "spine.AnimationStateListener");
    oluacls_func(L, "__call", _spine_AnimationStateListener___call);

    return 1;
}
OLUA_END_DECLS

static int _spine_AnimationState_addAnimation$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    size_t arg1 = 0;       /** trackIndex */
    spine::String arg2;       /** animationName */
    bool arg3 = false;       /** loop */
    float arg4 = 0;       /** delay */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_integer(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // spine::TrackEntry *addAnimation(size_t trackIndex, const spine::String &animationName, bool loop, float delay)
    spine::TrackEntry *ret = self->addAnimation(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_addAnimation$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    size_t arg1 = 0;       /** trackIndex */
    spine::Animation *arg2 = nullptr;       /** animation */
    bool arg3 = false;       /** loop */
    float arg4 = 0;       /** delay */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_integer(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "spine.Animation");
    olua_check_bool(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // spine::TrackEntry *addAnimation(size_t trackIndex, spine::Animation *animation, bool loop, float delay)
    spine::TrackEntry *ret = self->addAnimation(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_addAnimation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 4) {
        if ((olua_is_integer(L, 2)) && (olua_is_string(L, 3)) && (olua_is_bool(L, 4)) && (olua_is_number(L, 5))) {
            // spine::TrackEntry *addAnimation(size_t trackIndex, const spine::String &animationName, bool loop, float delay)
            return _spine_AnimationState_addAnimation$1(L);
        }

        // if ((olua_is_integer(L, 2)) && (olua_is_object(L, 3, "spine.Animation")) && (olua_is_bool(L, 4)) && (olua_is_number(L, 5))) {
            // spine::TrackEntry *addAnimation(size_t trackIndex, spine::Animation *animation, bool loop, float delay)
            return _spine_AnimationState_addAnimation$2(L);
        // }
    }

    luaL_error(L, "method 'spine::AnimationState::addAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_AnimationState_addEmptyAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    size_t arg1 = 0;       /** trackIndex */
    float arg2 = 0;       /** mixDuration */
    float arg3 = 0;       /** delay */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_integer(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // spine::TrackEntry *addEmptyAnimation(size_t trackIndex, float mixDuration, float delay)
    spine::TrackEntry *ret = self->addEmptyAnimation(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_apply(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    spine::Skeleton *arg1 = nullptr;       /** skeleton */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_object(L, 2, &arg1, "spine.Skeleton");

    // bool apply(spine::Skeleton &skeleton)
    bool ret = self->apply(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_clearTrack(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    size_t arg1 = 0;       /** trackIndex */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_integer(L, 2, &arg1);

    // void clearTrack(size_t trackIndex)
    self->clearTrack(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_clearTracks(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AnimationState");

    // void clearTracks()
    self->clearTracks();

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_disableQueue(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AnimationState");

    // void disableQueue()
    self->disableQueue();

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_enableQueue(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AnimationState");

    // void enableQueue()
    self->enableQueue();

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_getCurrent(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    size_t arg1 = 0;       /** trackIndex */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_integer(L, 2, &arg1);

    // spine::TrackEntry *getCurrent(size_t trackIndex)
    spine::TrackEntry *ret = self->getCurrent(arg1);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_getData(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AnimationState");

    // spine::AnimationStateData *getData()
    spine::AnimationStateData *ret = self->getData();
    int num_ret = olua_push_object(L, ret, "spine.AnimationStateData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_getTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AnimationState");

    // float getTimeScale()
    float ret = self->getTimeScale();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_getTracks(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AnimationState");

    // spine::Vector<spine::TrackEntry *> &getTracks()
    spine::Vector<spine::TrackEntry *> &ret = self->getTracks();
    int num_ret = olua_push_vector<spine::TrackEntry *>(L, ret, [L](spine::TrackEntry *arg1) {
        olua_push_object(L, arg1, "spine.TrackEntry");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *arg1 = nullptr;       /** data */

    olua_check_object(L, 1, &arg1, "spine.AnimationStateData");

    // AnimationState(spine::AnimationStateData *data)
    spine::AnimationState *ret = new spine::AnimationState(arg1);
    int num_ret = olua_push_object(L, ret, "spine.AnimationState");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_setAnimation$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    size_t arg1 = 0;       /** trackIndex */
    spine::String arg2;       /** animationName */
    bool arg3 = false;       /** loop */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_integer(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // spine::TrackEntry *setAnimation(size_t trackIndex, const spine::String &animationName, bool loop)
    spine::TrackEntry *ret = self->setAnimation(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_setAnimation$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    size_t arg1 = 0;       /** trackIndex */
    spine::Animation *arg2 = nullptr;       /** animation */
    bool arg3 = false;       /** loop */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_integer(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "spine.Animation");
    olua_check_bool(L, 4, &arg3);

    // spine::TrackEntry *setAnimation(size_t trackIndex, spine::Animation *animation, bool loop)
    spine::TrackEntry *ret = self->setAnimation(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_setAnimation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        if ((olua_is_integer(L, 2)) && (olua_is_string(L, 3)) && (olua_is_bool(L, 4))) {
            // spine::TrackEntry *setAnimation(size_t trackIndex, const spine::String &animationName, bool loop)
            return _spine_AnimationState_setAnimation$1(L);
        }

        // if ((olua_is_integer(L, 2)) && (olua_is_object(L, 3, "spine.Animation")) && (olua_is_bool(L, 4))) {
            // spine::TrackEntry *setAnimation(size_t trackIndex, spine::Animation *animation, bool loop)
            return _spine_AnimationState_setAnimation$2(L);
        // }
    }

    luaL_error(L, "method 'spine::AnimationState::setAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_AnimationState_setEmptyAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    size_t arg1 = 0;       /** trackIndex */
    float arg2 = 0;       /** mixDuration */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_integer(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // spine::TrackEntry *setEmptyAnimation(size_t trackIndex, float mixDuration)
    spine::TrackEntry *ret = self->setEmptyAnimation(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_setEmptyAnimations(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    float arg1 = 0;       /** mixDuration */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_number(L, 2, &arg1);

    // void setEmptyAnimations(float mixDuration)
    self->setEmptyAnimations(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_setListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    spine::AnimationStateListener arg1;       /** listener */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_callback(L, 2, &arg1, "spine.AnimationStateListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "Listener";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](spine::AnimationState *arg1, spine::EventType arg2, spine::TrackEntry *arg3, spine::Event *arg4) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.AnimationState");
            olua_push_enum(L, arg2);
            olua_push_object(L, arg3, "spine.TrackEntry");
            olua_push_object(L, arg4, "spine.Event");

            olua_callback(L, cb_store, cb_name.c_str(), 4);

            lua_settop(L, top);
        }
    };

    // void setListener(spine::AnimationStateListener listener)
    self->setListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_setTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_number(L, 2, &arg1);

    // void setTimeScale(float inValue)
    self->setTimeScale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_update(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    float arg1 = 0;       /** delta */

    olua_to_object(L, 1, &self, "spine.AnimationState");
    olua_check_number(L, 2, &arg1);

    // void update(float delta)
    self->update(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_AnimationState(lua_State *L)
{
    oluacls_class<spine::AnimationState, spine::SpineObject>(L, "spine.AnimationState");
    oluacls_func(L, "addAnimation", _spine_AnimationState_addAnimation);
    oluacls_func(L, "addEmptyAnimation", _spine_AnimationState_addEmptyAnimation);
    oluacls_func(L, "apply", _spine_AnimationState_apply);
    oluacls_func(L, "clearTrack", _spine_AnimationState_clearTrack);
    oluacls_func(L, "clearTracks", _spine_AnimationState_clearTracks);
    oluacls_func(L, "disableQueue", _spine_AnimationState_disableQueue);
    oluacls_func(L, "enableQueue", _spine_AnimationState_enableQueue);
    oluacls_func(L, "getCurrent", _spine_AnimationState_getCurrent);
    oluacls_func(L, "getData", _spine_AnimationState_getData);
    oluacls_func(L, "getTimeScale", _spine_AnimationState_getTimeScale);
    oluacls_func(L, "getTracks", _spine_AnimationState_getTracks);
    oluacls_func(L, "new", _spine_AnimationState_new);
    oluacls_func(L, "setAnimation", _spine_AnimationState_setAnimation);
    oluacls_func(L, "setEmptyAnimation", _spine_AnimationState_setEmptyAnimation);
    oluacls_func(L, "setEmptyAnimations", _spine_AnimationState_setEmptyAnimations);
    oluacls_func(L, "setListener", _spine_AnimationState_setListener);
    oluacls_func(L, "setTimeScale", _spine_AnimationState_setTimeScale);
    oluacls_func(L, "update", _spine_AnimationState_update);
    oluacls_prop(L, "data", _spine_AnimationState_getData, nullptr);
    oluacls_prop(L, "timeScale", _spine_AnimationState_getTimeScale, _spine_AnimationState_setTimeScale);
    oluacls_prop(L, "tracks", _spine_AnimationState_getTracks, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _spine_AnimationStateData_clear(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AnimationStateData");

    // void clear()
    self->clear();

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationStateData_getDefaultMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AnimationStateData");

    // float getDefaultMix()
    float ret = self->getDefaultMix();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationStateData_getMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;
    spine::Animation *arg1 = nullptr;       /** from */
    spine::Animation *arg2 = nullptr;       /** to */

    olua_to_object(L, 1, &self, "spine.AnimationStateData");
    olua_check_object(L, 2, &arg1, "spine.Animation");
    olua_check_object(L, 3, &arg2, "spine.Animation");

    // float getMix(spine::Animation *from, spine::Animation *to)
    float ret = self->getMix(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationStateData_getSkeletonData(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AnimationStateData");

    // spine::SkeletonData *getSkeletonData()
    spine::SkeletonData *ret = self->getSkeletonData();
    int num_ret = olua_push_object(L, ret, "spine.SkeletonData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationStateData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */

    olua_check_object(L, 1, &arg1, "spine.SkeletonData");

    // AnimationStateData(spine::SkeletonData *skeletonData)
    spine::AnimationStateData *ret = new spine::AnimationStateData(arg1);
    int num_ret = olua_push_object(L, ret, "spine.AnimationStateData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationStateData_setDefaultMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.AnimationStateData");
    olua_check_number(L, 2, &arg1);

    // void setDefaultMix(float inValue)
    self->setDefaultMix(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationStateData_setMix$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;
    spine::String arg1;       /** fromName */
    spine::String arg2;       /** toName */
    float arg3 = 0;       /** duration */

    olua_to_object(L, 1, &self, "spine.AnimationStateData");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void setMix(const spine::String &fromName, const spine::String &toName, float duration)
    self->setMix(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationStateData_setMix$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;
    spine::Animation *arg1 = nullptr;       /** from */
    spine::Animation *arg2 = nullptr;       /** to */
    float arg3 = 0;       /** duration */

    olua_to_object(L, 1, &self, "spine.AnimationStateData");
    olua_check_object(L, 2, &arg1, "spine.Animation");
    olua_check_object(L, 3, &arg2, "spine.Animation");
    olua_check_number(L, 4, &arg3);

    // void setMix(spine::Animation *from, spine::Animation *to, float duration)
    self->setMix(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationStateData_setMix(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        if ((olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_number(L, 4))) {
            // void setMix(const spine::String &fromName, const spine::String &toName, float duration)
            return _spine_AnimationStateData_setMix$1(L);
        }

        // if ((olua_is_object(L, 2, "spine.Animation")) && (olua_is_object(L, 3, "spine.Animation")) && (olua_is_number(L, 4))) {
            // void setMix(spine::Animation *from, spine::Animation *to, float duration)
            return _spine_AnimationStateData_setMix$2(L);
        // }
    }

    luaL_error(L, "method 'spine::AnimationStateData::setMix' not support '%d' arguments", num_args);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_AnimationStateData(lua_State *L)
{
    oluacls_class<spine::AnimationStateData, spine::SpineObject>(L, "spine.AnimationStateData");
    oluacls_func(L, "clear", _spine_AnimationStateData_clear);
    oluacls_func(L, "getDefaultMix", _spine_AnimationStateData_getDefaultMix);
    oluacls_func(L, "getMix", _spine_AnimationStateData_getMix);
    oluacls_func(L, "getSkeletonData", _spine_AnimationStateData_getSkeletonData);
    oluacls_func(L, "new", _spine_AnimationStateData_new);
    oluacls_func(L, "setDefaultMix", _spine_AnimationStateData_setDefaultMix);
    oluacls_func(L, "setMix", _spine_AnimationStateData_setMix);
    oluacls_prop(L, "defaultMix", _spine_AnimationStateData_getDefaultMix, _spine_AnimationStateData_setDefaultMix);
    oluacls_prop(L, "skeletonData", _spine_AnimationStateData_getSkeletonData, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _spine_Animation_getDuration(lua_State *L)
{
    olua_startinvoke(L);

    spine::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Animation");

    // float getDuration()
    float ret = self->getDuration();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Animation");

    // const spine::String &getName()
    const spine::String &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_getTimelines(lua_State *L)
{
    olua_startinvoke(L);

    spine::Animation *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Animation");

    // spine::Vector<spine::Timeline *> &getTimelines()
    spine::Vector<spine::Timeline *> &ret = self->getTimelines();
    int num_ret = olua_push_vector<spine::Timeline *>(L, ret, [L](spine::Timeline *arg1) {
        olua_push_object(L, arg1, "spine.Timeline");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_hasTimeline(lua_State *L)
{
    olua_startinvoke(L);

    spine::Animation *self = nullptr;
    spine::Vector<spine::PropertyId> arg1;       /** ids */

    olua_to_object(L, 1, &self, "spine.Animation");
    olua_check_vector<spine::PropertyId>(L, 2, arg1, [L](spine::PropertyId *arg1) {
        olua_check_integer(L, -1, arg1);
    });

    // bool hasTimeline(spine::Vector<spine::PropertyId> ids)
    bool ret = self->hasTimeline(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */
    spine::Vector<spine::Timeline *> arg2;       /** timelines */
    float arg3 = 0;       /** duration */

    olua_check_string(L, 1, &arg1);
    olua_check_vector<spine::Timeline *>(L, 2, arg2, [L](spine::Timeline **arg1) {
        olua_check_object(L, -1, arg1, "spine.Timeline");
    });
    olua_check_number(L, 3, &arg3);

    // Animation(const spine::String &name, spine::Vector<spine::Timeline *> &timelines, float duration)
    spine::Animation *ret = new spine::Animation(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.Animation");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_search$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::Vector<float> arg1;       /** values */
    float arg2 = 0;       /** target */

    olua_check_vector<float>(L, 1, arg1, [L](float *arg1) {
        olua_check_number(L, -1, arg1);
    });
    olua_check_number(L, 2, &arg2);

    // static int search(spine::Vector<float> &values, float target)
    int ret = spine::Animation::search(arg1, arg2);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_search$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Vector<float> arg1;       /** values */
    float arg2 = 0;       /** target */
    int arg3 = 0;       /** step */

    olua_check_vector<float>(L, 1, arg1, [L](float *arg1) {
        olua_check_number(L, -1, arg1);
    });
    olua_check_number(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // static int search(spine::Vector<float> &values, float target, int step)
    int ret = spine::Animation::search(arg1, arg2, arg3);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_search(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_vector(L, 1)) && (olua_is_number(L, 2))) {
            // static int search(spine::Vector<float> &values, float target)
            return _spine_Animation_search$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_vector(L, 1)) && (olua_is_number(L, 2)) && (olua_is_integer(L, 3))) {
            // static int search(spine::Vector<float> &values, float target, int step)
            return _spine_Animation_search$2(L);
        // }
    }

    luaL_error(L, "method 'spine::Animation::search' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_Animation_setDuration(lua_State *L)
{
    olua_startinvoke(L);

    spine::Animation *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Animation");
    olua_check_number(L, 2, &arg1);

    // void setDuration(float inValue)
    self->setDuration(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Animation(lua_State *L)
{
    oluacls_class<spine::Animation, spine::SpineObject>(L, "spine.Animation");
    oluacls_func(L, "getDuration", _spine_Animation_getDuration);
    oluacls_func(L, "getName", _spine_Animation_getName);
    oluacls_func(L, "getTimelines", _spine_Animation_getTimelines);
    oluacls_func(L, "hasTimeline", _spine_Animation_hasTimeline);
    oluacls_func(L, "new", _spine_Animation_new);
    oluacls_func(L, "search", _spine_Animation_search);
    oluacls_func(L, "setDuration", _spine_Animation_setDuration);
    oluacls_prop(L, "duration", _spine_Animation_getDuration, _spine_Animation_setDuration);
    oluacls_prop(L, "name", _spine_Animation_getName, nullptr);
    oluacls_prop(L, "timelines", _spine_Animation_getTimelines, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _spine_Sequence_apply(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** slot */
    spine::Attachment *arg2 = nullptr;       /** attachment */

    olua_to_object(L, 1, &self, "spine.Sequence");
    olua_check_object(L, 2, &arg1, "spine.Slot");
    olua_check_object(L, 3, &arg2, "spine.Attachment");

    // void apply(spine::Slot *slot, spine::Attachment *attachment)
    self->apply(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Sequence_copy(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Sequence");

    // spine::Sequence *copy()
    spine::Sequence *ret = self->copy();
    int num_ret = olua_push_object(L, ret, "spine.Sequence");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Sequence_getDigits(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Sequence");

    // int getDigits()
    int ret = self->getDigits();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Sequence_getId(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Sequence");

    // int getId()
    int ret = self->getId();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Sequence_getPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;
    spine::String arg1;       /** basePath */
    int arg2 = 0;       /** index */

    olua_to_object(L, 1, &self, "spine.Sequence");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // spine::String getPath(const spine::String &basePath, int index)
    spine::String ret = self->getPath(arg1, arg2);
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Sequence_getRegions(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Sequence");

    // spine::Vector<spine::TextureRegion *> &getRegions()
    spine::Vector<spine::TextureRegion *> &ret = self->getRegions();
    int num_ret = olua_push_vector<spine::TextureRegion *>(L, ret, [L](spine::TextureRegion *arg1) {
        olua_push_object(L, arg1, "spine.TextureRegion");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Sequence_getSetupIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Sequence");

    // int getSetupIndex()
    int ret = self->getSetupIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Sequence_getStart(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Sequence");

    // int getStart()
    int ret = self->getStart();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Sequence_new(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** count */

    olua_check_integer(L, 1, &arg1);

    // Sequence(int count)
    spine::Sequence *ret = new spine::Sequence(arg1);
    int num_ret = olua_push_object(L, ret, "spine.Sequence");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Sequence_setDigits(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;
    int arg1 = 0;       /** digits */

    olua_to_object(L, 1, &self, "spine.Sequence");
    olua_check_integer(L, 2, &arg1);

    // void setDigits(int digits)
    self->setDigits(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Sequence_setId(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;
    int arg1 = 0;       /** id */

    olua_to_object(L, 1, &self, "spine.Sequence");
    olua_check_integer(L, 2, &arg1);

    // void setId(int id)
    self->setId(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Sequence_setSetupIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;
    int arg1 = 0;       /** setupIndex */

    olua_to_object(L, 1, &self, "spine.Sequence");
    olua_check_integer(L, 2, &arg1);

    // void setSetupIndex(int setupIndex)
    self->setSetupIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Sequence_setStart(lua_State *L)
{
    olua_startinvoke(L);

    spine::Sequence *self = nullptr;
    int arg1 = 0;       /** start */

    olua_to_object(L, 1, &self, "spine.Sequence");
    olua_check_integer(L, 2, &arg1);

    // void setStart(int start)
    self->setStart(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Sequence(lua_State *L)
{
    oluacls_class<spine::Sequence, spine::SpineObject>(L, "spine.Sequence");
    oluacls_func(L, "apply", _spine_Sequence_apply);
    oluacls_func(L, "copy", _spine_Sequence_copy);
    oluacls_func(L, "getDigits", _spine_Sequence_getDigits);
    oluacls_func(L, "getId", _spine_Sequence_getId);
    oluacls_func(L, "getPath", _spine_Sequence_getPath);
    oluacls_func(L, "getRegions", _spine_Sequence_getRegions);
    oluacls_func(L, "getSetupIndex", _spine_Sequence_getSetupIndex);
    oluacls_func(L, "getStart", _spine_Sequence_getStart);
    oluacls_func(L, "new", _spine_Sequence_new);
    oluacls_func(L, "setDigits", _spine_Sequence_setDigits);
    oluacls_func(L, "setId", _spine_Sequence_setId);
    oluacls_func(L, "setSetupIndex", _spine_Sequence_setSetupIndex);
    oluacls_func(L, "setStart", _spine_Sequence_setStart);
    oluacls_prop(L, "digits", _spine_Sequence_getDigits, _spine_Sequence_setDigits);
    oluacls_prop(L, "id", _spine_Sequence_getId, _spine_Sequence_setId);
    oluacls_prop(L, "regions", _spine_Sequence_getRegions, nullptr);
    oluacls_prop(L, "setupIndex", _spine_Sequence_getSetupIndex, _spine_Sequence_setSetupIndex);
    oluacls_prop(L, "start", _spine_Sequence_getStart, _spine_Sequence_setStart);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_SequenceMode(lua_State *L)
{
    oluacls_class<spine::SequenceMode>(L, "spine.SequenceMode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "hold", (lua_Integer)spine::SequenceMode::hold);
    oluacls_enum(L, "loop", (lua_Integer)spine::SequenceMode::loop);
    oluacls_enum(L, "loopReverse", (lua_Integer)spine::SequenceMode::loopReverse);
    oluacls_enum(L, "once", (lua_Integer)spine::SequenceMode::once);
    oluacls_enum(L, "onceReverse", (lua_Integer)spine::SequenceMode::onceReverse);
    oluacls_enum(L, "pingpong", (lua_Integer)spine::SequenceMode::pingpong);
    oluacls_enum(L, "pingpongReverse", (lua_Integer)spine::SequenceMode::pingpongReverse);

    return 1;
}
OLUA_END_DECLS

static int _spine_TextureRegion_new(lua_State *L)
{
    olua_startinvoke(L);

    // TextureRegion()
    spine::TextureRegion *ret = new spine::TextureRegion();
    int num_ret = olua_push_object(L, ret, "spine.TextureRegion");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_get_degrees(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // int degrees
    int ret = self->degrees;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_degrees(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    int arg1 = 0;       /** degrees */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_integer(L, 2, &arg1);

    // int degrees
    self->degrees = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _spine_TextureRegion_get_height(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // int height
    int ret = self->height;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_height(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    int arg1 = 0;       /** height */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_integer(L, 2, &arg1);

    // int height
    self->height = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _spine_TextureRegion_get_offsetX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // float offsetX
    float ret = self->offsetX;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_offsetX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    float arg1 = 0;       /** offsetX */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_number(L, 2, &arg1);

    // float offsetX
    self->offsetX = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _spine_TextureRegion_get_offsetY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // float offsetY
    float ret = self->offsetY;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_offsetY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    float arg1 = 0;       /** offsetY */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_number(L, 2, &arg1);

    // float offsetY
    self->offsetY = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _spine_TextureRegion_get_originalHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // int originalHeight
    int ret = self->originalHeight;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_originalHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    int arg1 = 0;       /** originalHeight */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_integer(L, 2, &arg1);

    // int originalHeight
    self->originalHeight = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _spine_TextureRegion_get_originalWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // int originalWidth
    int ret = self->originalWidth;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_originalWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    int arg1 = 0;       /** originalWidth */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_integer(L, 2, &arg1);

    // int originalWidth
    self->originalWidth = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _spine_TextureRegion_get_rendererObject(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // void *rendererObject
    void *ret = self->rendererObject;
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_rendererObject(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    void *arg1 = nullptr;       /** rendererObject */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_object(L, 2, &arg1, "void *");

    // void *rendererObject
    self->rendererObject = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _spine_TextureRegion_get_u(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // float u
    float ret = self->u;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_u(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    float arg1 = 0;       /** u */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_number(L, 2, &arg1);

    // float u
    self->u = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _spine_TextureRegion_get_u2(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // float u2
    float ret = self->u2;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_u2(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    float arg1 = 0;       /** u2 */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_number(L, 2, &arg1);

    // float u2
    self->u2 = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _spine_TextureRegion_get_v(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // float v
    float ret = self->v;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_v(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    float arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_number(L, 2, &arg1);

    // float v
    self->v = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _spine_TextureRegion_get_v2(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // float v2
    float ret = self->v2;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_v2(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    float arg1 = 0;       /** v2 */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_number(L, 2, &arg1);

    // float v2
    self->v2 = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _spine_TextureRegion_get_width(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TextureRegion");

    // int width
    int ret = self->width;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TextureRegion_set_width(lua_State *L)
{
    olua_startinvoke(L);

    spine::TextureRegion *self = nullptr;
    int arg1 = 0;       /** width */

    olua_to_object(L, 1, &self, "spine.TextureRegion");
    olua_check_integer(L, 2, &arg1);

    // int width
    self->width = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_TextureRegion(lua_State *L)
{
    oluacls_class<spine::TextureRegion, spine::SpineObject>(L, "spine.TextureRegion");
    oluacls_func(L, "new", _spine_TextureRegion_new);
    oluacls_prop(L, "degrees", _spine_TextureRegion_get_degrees, _spine_TextureRegion_set_degrees);
    oluacls_prop(L, "height", _spine_TextureRegion_get_height, _spine_TextureRegion_set_height);
    oluacls_prop(L, "offsetX", _spine_TextureRegion_get_offsetX, _spine_TextureRegion_set_offsetX);
    oluacls_prop(L, "offsetY", _spine_TextureRegion_get_offsetY, _spine_TextureRegion_set_offsetY);
    oluacls_prop(L, "originalHeight", _spine_TextureRegion_get_originalHeight, _spine_TextureRegion_set_originalHeight);
    oluacls_prop(L, "originalWidth", _spine_TextureRegion_get_originalWidth, _spine_TextureRegion_set_originalWidth);
    oluacls_prop(L, "rendererObject", _spine_TextureRegion_get_rendererObject, _spine_TextureRegion_set_rendererObject);
    oluacls_prop(L, "u", _spine_TextureRegion_get_u, _spine_TextureRegion_set_u);
    oluacls_prop(L, "u2", _spine_TextureRegion_get_u2, _spine_TextureRegion_set_u2);
    oluacls_prop(L, "v", _spine_TextureRegion_get_v, _spine_TextureRegion_set_v);
    oluacls_prop(L, "v2", _spine_TextureRegion_get_v2, _spine_TextureRegion_set_v2);
    oluacls_prop(L, "width", _spine_TextureRegion_get_width, _spine_TextureRegion_set_width);

    return 1;
}
OLUA_END_DECLS

static int _spine_ConstraintData_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::ConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.ConstraintData");

    // const spine::String &getName()
    const spine::String &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ConstraintData_getOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::ConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.ConstraintData");

    // size_t getOrder()
    size_t ret = self->getOrder();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ConstraintData_isSkinRequired(lua_State *L)
{
    olua_startinvoke(L);

    spine::ConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.ConstraintData");

    // bool isSkinRequired()
    bool ret = self->isSkinRequired();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ConstraintData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // ConstraintData(const spine::String &name)
    spine::ConstraintData *ret = new spine::ConstraintData(arg1);
    int num_ret = olua_push_object(L, ret, "spine.ConstraintData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ConstraintData_setOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::ConstraintData *self = nullptr;
    size_t arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.ConstraintData");
    olua_check_integer(L, 2, &arg1);

    // void setOrder(size_t inValue)
    self->setOrder(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_ConstraintData_setSkinRequired(lua_State *L)
{
    olua_startinvoke(L);

    spine::ConstraintData *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.ConstraintData");
    olua_check_bool(L, 2, &arg1);

    // void setSkinRequired(bool inValue)
    self->setSkinRequired(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_ConstraintData(lua_State *L)
{
    oluacls_class<spine::ConstraintData, spine::SpineObject>(L, "spine.ConstraintData");
    oluacls_func(L, "getName", _spine_ConstraintData_getName);
    oluacls_func(L, "getOrder", _spine_ConstraintData_getOrder);
    oluacls_func(L, "isSkinRequired", _spine_ConstraintData_isSkinRequired);
    oluacls_func(L, "new", _spine_ConstraintData_new);
    oluacls_func(L, "setOrder", _spine_ConstraintData_setOrder);
    oluacls_func(L, "setSkinRequired", _spine_ConstraintData_setSkinRequired);
    oluacls_prop(L, "name", _spine_ConstraintData_getName, nullptr);
    oluacls_prop(L, "order", _spine_ConstraintData_getOrder, _spine_ConstraintData_setOrder);
    oluacls_prop(L, "skinRequired", _spine_ConstraintData_isSkinRequired, _spine_ConstraintData_setSkinRequired);

    return 1;
}
OLUA_END_DECLS

static int _spine_IkConstraintData_getBendDirection(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraintData");

    // int getBendDirection()
    int ret = self->getBendDirection();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraintData");

    // spine::Vector<spine::BoneData *> &getBones()
    spine::Vector<spine::BoneData *> &ret = self->getBones();
    int num_ret = olua_push_vector<spine::BoneData *>(L, ret, [L](spine::BoneData *arg1) {
        olua_push_object(L, arg1, "spine.BoneData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getCompress(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraintData");

    // bool getCompress()
    bool ret = self->getCompress();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraintData");

    // float getMix()
    float ret = self->getMix();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getSoftness(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraintData");

    // float getSoftness()
    float ret = self->getSoftness();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getStretch(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraintData");

    // bool getStretch()
    bool ret = self->getStretch();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraintData");

    // spine::BoneData *getTarget()
    spine::BoneData *ret = self->getTarget();
    int num_ret = olua_push_object(L, ret, "spine.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getUniform(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraintData");

    // bool getUniform()
    bool ret = self->getUniform();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // IkConstraintData(const spine::String &name)
    spine::IkConstraintData *ret = new spine::IkConstraintData(arg1);
    int num_ret = olua_push_object(L, ret, "spine.IkConstraintData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_setBendDirection(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraintData");
    olua_check_integer(L, 2, &arg1);

    // void setBendDirection(int inValue)
    self->setBendDirection(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraintData_setCompress(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraintData");
    olua_check_bool(L, 2, &arg1);

    // void setCompress(bool inValue)
    self->setCompress(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraintData_setMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setMix(float inValue)
    self->setMix(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraintData_setSoftness(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setSoftness(float inValue)
    self->setSoftness(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraintData_setStretch(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraintData");
    olua_check_bool(L, 2, &arg1);

    // void setStretch(bool inValue)
    self->setStretch(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraintData_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;
    spine::BoneData *arg1 = nullptr;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraintData");
    olua_check_object(L, 2, &arg1, "spine.BoneData");

    // void setTarget(spine::BoneData *inValue)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraintData_setUniform(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraintData");
    olua_check_bool(L, 2, &arg1);

    // void setUniform(bool inValue)
    self->setUniform(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_IkConstraintData(lua_State *L)
{
    oluacls_class<spine::IkConstraintData, spine::ConstraintData>(L, "spine.IkConstraintData");
    oluacls_func(L, "getBendDirection", _spine_IkConstraintData_getBendDirection);
    oluacls_func(L, "getBones", _spine_IkConstraintData_getBones);
    oluacls_func(L, "getCompress", _spine_IkConstraintData_getCompress);
    oluacls_func(L, "getMix", _spine_IkConstraintData_getMix);
    oluacls_func(L, "getSoftness", _spine_IkConstraintData_getSoftness);
    oluacls_func(L, "getStretch", _spine_IkConstraintData_getStretch);
    oluacls_func(L, "getTarget", _spine_IkConstraintData_getTarget);
    oluacls_func(L, "getUniform", _spine_IkConstraintData_getUniform);
    oluacls_func(L, "new", _spine_IkConstraintData_new);
    oluacls_func(L, "setBendDirection", _spine_IkConstraintData_setBendDirection);
    oluacls_func(L, "setCompress", _spine_IkConstraintData_setCompress);
    oluacls_func(L, "setMix", _spine_IkConstraintData_setMix);
    oluacls_func(L, "setSoftness", _spine_IkConstraintData_setSoftness);
    oluacls_func(L, "setStretch", _spine_IkConstraintData_setStretch);
    oluacls_func(L, "setTarget", _spine_IkConstraintData_setTarget);
    oluacls_func(L, "setUniform", _spine_IkConstraintData_setUniform);
    oluacls_prop(L, "bendDirection", _spine_IkConstraintData_getBendDirection, _spine_IkConstraintData_setBendDirection);
    oluacls_prop(L, "bones", _spine_IkConstraintData_getBones, nullptr);
    oluacls_prop(L, "compress", _spine_IkConstraintData_getCompress, _spine_IkConstraintData_setCompress);
    oluacls_prop(L, "mix", _spine_IkConstraintData_getMix, _spine_IkConstraintData_setMix);
    oluacls_prop(L, "softness", _spine_IkConstraintData_getSoftness, _spine_IkConstraintData_setSoftness);
    oluacls_prop(L, "stretch", _spine_IkConstraintData_getStretch, _spine_IkConstraintData_setStretch);
    oluacls_prop(L, "target", _spine_IkConstraintData_getTarget, _spine_IkConstraintData_setTarget);
    oluacls_prop(L, "uniform", _spine_IkConstraintData_getUniform, _spine_IkConstraintData_setUniform);

    return 1;
}
OLUA_END_DECLS

static int _spine_BoneData_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // spine::Color &getColor()
    spine::Color &ret = self->getColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // int getIndex()
    int ret = self->getIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // float getLength()
    float ret = self->getLength();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // const spine::String &getName()
    const spine::String &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // spine::BoneData *getParent()
    spine::BoneData *ret = self->getParent();
    int num_ret = olua_push_object(L, ret, "spine.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // float getRotation()
    float ret = self->getRotation();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // float getScaleX()
    float ret = self->getScaleX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // float getScaleY()
    float ret = self->getScaleY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // float getShearX()
    float ret = self->getShearX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // float getShearY()
    float ret = self->getShearY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getTransformMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // spine::TransformMode getTransformMode()
    spine::TransformMode ret = self->getTransformMode();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // float getX()
    float ret = self->getX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // float getY()
    float ret = self->getY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_isSkinRequired(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoneData");

    // bool isSkinRequired()
    bool ret = self->isSkinRequired();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_new$1(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** index */
    spine::String arg2;       /** name */
    spine::BoneData *arg3 = nullptr;       /** parent */

    olua_check_integer(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "spine.BoneData");

    // BoneData(int index, const spine::String &name, @optional spine::BoneData *parent)
    spine::BoneData *ret = new spine::BoneData(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.BoneData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_new$2(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** index */
    spine::String arg2;       /** name */

    olua_check_integer(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // BoneData(int index, const spine::String &name, @optional spine::BoneData *parent)
    spine::BoneData *ret = new spine::BoneData(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.BoneData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_integer(L, 1)) && (olua_is_string(L, 2))) {
            // BoneData(int index, const spine::String &name, @optional spine::BoneData *parent)
            return _spine_BoneData_new$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_integer(L, 1)) && (olua_is_string(L, 2)) && (olua_is_object(L, 3, "spine.BoneData"))) {
            // BoneData(int index, const spine::String &name, @optional spine::BoneData *parent)
            return _spine_BoneData_new$1(L);
        // }
    }

    luaL_error(L, "method 'spine::BoneData::new' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_BoneData_setLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setLength(float inValue)
    self->setLength(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setRotation(float inValue)
    self->setRotation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setScaleX(float inValue)
    self->setScaleX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setScaleY(float inValue)
    self->setScaleY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setShearX(float inValue)
    self->setShearX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setShearY(float inValue)
    self->setShearY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setSkinRequired(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.BoneData");
    olua_check_bool(L, 2, &arg1);

    // void setSkinRequired(bool inValue)
    self->setSkinRequired(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setTransformMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    spine::TransformMode arg1 = (spine::TransformMode)0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.BoneData");
    olua_check_enum(L, 2, &arg1);

    // void setTransformMode(spine::TransformMode inValue)
    self->setTransformMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_BoneData(lua_State *L)
{
    oluacls_class<spine::BoneData, spine::SpineObject>(L, "spine.BoneData");
    oluacls_func(L, "getColor", _spine_BoneData_getColor);
    oluacls_func(L, "getIndex", _spine_BoneData_getIndex);
    oluacls_func(L, "getLength", _spine_BoneData_getLength);
    oluacls_func(L, "getName", _spine_BoneData_getName);
    oluacls_func(L, "getParent", _spine_BoneData_getParent);
    oluacls_func(L, "getRotation", _spine_BoneData_getRotation);
    oluacls_func(L, "getScaleX", _spine_BoneData_getScaleX);
    oluacls_func(L, "getScaleY", _spine_BoneData_getScaleY);
    oluacls_func(L, "getShearX", _spine_BoneData_getShearX);
    oluacls_func(L, "getShearY", _spine_BoneData_getShearY);
    oluacls_func(L, "getTransformMode", _spine_BoneData_getTransformMode);
    oluacls_func(L, "getX", _spine_BoneData_getX);
    oluacls_func(L, "getY", _spine_BoneData_getY);
    oluacls_func(L, "isSkinRequired", _spine_BoneData_isSkinRequired);
    oluacls_func(L, "new", _spine_BoneData_new);
    oluacls_func(L, "setLength", _spine_BoneData_setLength);
    oluacls_func(L, "setRotation", _spine_BoneData_setRotation);
    oluacls_func(L, "setScaleX", _spine_BoneData_setScaleX);
    oluacls_func(L, "setScaleY", _spine_BoneData_setScaleY);
    oluacls_func(L, "setShearX", _spine_BoneData_setShearX);
    oluacls_func(L, "setShearY", _spine_BoneData_setShearY);
    oluacls_func(L, "setSkinRequired", _spine_BoneData_setSkinRequired);
    oluacls_func(L, "setTransformMode", _spine_BoneData_setTransformMode);
    oluacls_func(L, "setX", _spine_BoneData_setX);
    oluacls_func(L, "setY", _spine_BoneData_setY);
    oluacls_prop(L, "color", _spine_BoneData_getColor, nullptr);
    oluacls_prop(L, "index", _spine_BoneData_getIndex, nullptr);
    oluacls_prop(L, "length", _spine_BoneData_getLength, _spine_BoneData_setLength);
    oluacls_prop(L, "name", _spine_BoneData_getName, nullptr);
    oluacls_prop(L, "parent", _spine_BoneData_getParent, nullptr);
    oluacls_prop(L, "rotation", _spine_BoneData_getRotation, _spine_BoneData_setRotation);
    oluacls_prop(L, "scaleX", _spine_BoneData_getScaleX, _spine_BoneData_setScaleX);
    oluacls_prop(L, "scaleY", _spine_BoneData_getScaleY, _spine_BoneData_setScaleY);
    oluacls_prop(L, "shearX", _spine_BoneData_getShearX, _spine_BoneData_setShearX);
    oluacls_prop(L, "shearY", _spine_BoneData_getShearY, _spine_BoneData_setShearY);
    oluacls_prop(L, "skinRequired", _spine_BoneData_isSkinRequired, _spine_BoneData_setSkinRequired);
    oluacls_prop(L, "transformMode", _spine_BoneData_getTransformMode, _spine_BoneData_setTransformMode);
    oluacls_prop(L, "x", _spine_BoneData_getX, _spine_BoneData_setX);
    oluacls_prop(L, "y", _spine_BoneData_getY, _spine_BoneData_setY);

    return 1;
}
OLUA_END_DECLS

static int _spine_SlotData_getAttachmentName(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SlotData");

    // const spine::String &getAttachmentName()
    const spine::String &ret = self->getAttachmentName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_getBlendMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SlotData");

    // spine::BlendMode getBlendMode()
    spine::BlendMode ret = self->getBlendMode();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_getBoneData(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SlotData");

    // spine::BoneData &getBoneData()
    spine::BoneData &ret = self->getBoneData();
    int num_ret = olua_push_object(L, &ret, "spine.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SlotData");

    // spine::Color &getColor()
    spine::Color &ret = self->getColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_getDarkColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SlotData");

    // spine::Color &getDarkColor()
    spine::Color &ret = self->getDarkColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_getIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SlotData");

    // int getIndex()
    int ret = self->getIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SlotData");

    // const spine::String &getName()
    const spine::String &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_hasDarkColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SlotData");

    // bool hasDarkColor()
    bool ret = self->hasDarkColor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_new(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** index */
    spine::String arg2;       /** name */
    spine::BoneData *arg3 = nullptr;       /** boneData */

    olua_check_integer(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "spine.BoneData");

    // SlotData(int index, const spine::String &name, spine::BoneData &boneData)
    spine::SlotData *ret = new spine::SlotData(arg1, arg2, *arg3);
    int num_ret = olua_push_object(L, ret, "spine.SlotData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_setAttachmentName(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SlotData");
    olua_check_string(L, 2, &arg1);

    // void setAttachmentName(const spine::String &inValue)
    self->setAttachmentName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SlotData_setBlendMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;
    spine::BlendMode arg1 = (spine::BlendMode)0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SlotData");
    olua_check_enum(L, 2, &arg1);

    // void setBlendMode(spine::BlendMode inValue)
    self->setBlendMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SlotData_setHasDarkColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SlotData");
    olua_check_bool(L, 2, &arg1);

    // void setHasDarkColor(bool inValue)
    self->setHasDarkColor(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_SlotData(lua_State *L)
{
    oluacls_class<spine::SlotData, spine::SpineObject>(L, "spine.SlotData");
    oluacls_func(L, "getAttachmentName", _spine_SlotData_getAttachmentName);
    oluacls_func(L, "getBlendMode", _spine_SlotData_getBlendMode);
    oluacls_func(L, "getBoneData", _spine_SlotData_getBoneData);
    oluacls_func(L, "getColor", _spine_SlotData_getColor);
    oluacls_func(L, "getDarkColor", _spine_SlotData_getDarkColor);
    oluacls_func(L, "getIndex", _spine_SlotData_getIndex);
    oluacls_func(L, "getName", _spine_SlotData_getName);
    oluacls_func(L, "hasDarkColor", _spine_SlotData_hasDarkColor);
    oluacls_func(L, "new", _spine_SlotData_new);
    oluacls_func(L, "setAttachmentName", _spine_SlotData_setAttachmentName);
    oluacls_func(L, "setBlendMode", _spine_SlotData_setBlendMode);
    oluacls_func(L, "setHasDarkColor", _spine_SlotData_setHasDarkColor);
    oluacls_prop(L, "attachmentName", _spine_SlotData_getAttachmentName, _spine_SlotData_setAttachmentName);
    oluacls_prop(L, "blendMode", _spine_SlotData_getBlendMode, _spine_SlotData_setBlendMode);
    oluacls_prop(L, "boneData", _spine_SlotData_getBoneData, nullptr);
    oluacls_prop(L, "color", _spine_SlotData_getColor, nullptr);
    oluacls_prop(L, "darkColor", _spine_SlotData_getDarkColor, nullptr);
    oluacls_prop(L, "index", _spine_SlotData_getIndex, nullptr);
    oluacls_prop(L, "name", _spine_SlotData_getName, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _spine_IkConstraint_apply$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *arg1 = nullptr;       /** bone */
    float arg2 = 0;       /** targetX */
    float arg3 = 0;       /** targetY */
    bool arg4 = false;       /** compress */
    bool arg5 = false;       /** stretch */
    bool arg6 = false;       /** uniform */
    float arg7 = 0;       /** alpha */

    olua_check_object(L, 1, &arg1, "spine.Bone");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_bool(L, 4, &arg4);
    olua_check_bool(L, 5, &arg5);
    olua_check_bool(L, 6, &arg6);
    olua_check_number(L, 7, &arg7);

    // static void apply(spine::Bone &bone, float targetX, float targetY, bool compress, bool stretch, bool uniform, float alpha)
    spine::IkConstraint::apply(*arg1, arg2, arg3, arg4, arg5, arg6, arg7);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_apply$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *arg1 = nullptr;       /** parent */
    spine::Bone *arg2 = nullptr;       /** child */
    float arg3 = 0;       /** targetX */
    float arg4 = 0;       /** targetY */
    int arg5 = 0;       /** bendDir */
    bool arg6 = false;       /** stretch */
    bool arg7 = false;       /** uniform */
    float arg8 = 0;       /** softness */
    float arg9 = 0;       /** alpha */

    olua_check_object(L, 1, &arg1, "spine.Bone");
    olua_check_object(L, 2, &arg2, "spine.Bone");
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_integer(L, 5, &arg5);
    olua_check_bool(L, 6, &arg6);
    olua_check_bool(L, 7, &arg7);
    olua_check_number(L, 8, &arg8);
    olua_check_number(L, 9, &arg9);

    // static void apply(spine::Bone &parent, spine::Bone &child, float targetX, float targetY, int bendDir, bool stretch, bool uniform, float softness, float alpha)
    spine::IkConstraint::apply(*arg1, *arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_apply$3(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraint");

    // void apply()
    self->apply();

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_apply(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // void apply()
        return _spine_IkConstraint_apply$3(L);
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "spine.Bone")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_bool(L, 4)) && (olua_is_bool(L, 5)) && (olua_is_bool(L, 6)) && (olua_is_number(L, 7))) {
            // static void apply(spine::Bone &bone, float targetX, float targetY, bool compress, bool stretch, bool uniform, float alpha)
            return _spine_IkConstraint_apply$1(L);
        // }
    }

    if (num_args == 9) {
        // if ((olua_is_object(L, 1, "spine.Bone")) && (olua_is_object(L, 2, "spine.Bone")) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_integer(L, 5)) && (olua_is_bool(L, 6)) && (olua_is_bool(L, 7)) && (olua_is_number(L, 8)) && (olua_is_number(L, 9))) {
            // static void apply(spine::Bone &parent, spine::Bone &child, float targetX, float targetY, int bendDir, bool stretch, bool uniform, float softness, float alpha)
            return _spine_IkConstraint_apply$2(L);
        // }
    }

    luaL_error(L, "method 'spine::IkConstraint::apply' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_IkConstraint_getBendDirection(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraint");

    // int getBendDirection()
    int ret = self->getBendDirection();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraint");

    // spine::Vector<spine::Bone *> &getBones()
    spine::Vector<spine::Bone *> &ret = self->getBones();
    int num_ret = olua_push_vector<spine::Bone *>(L, ret, [L](spine::Bone *arg1) {
        olua_push_object(L, arg1, "spine.Bone");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getCompress(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraint");

    // bool getCompress()
    bool ret = self->getCompress();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getData(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraint");

    // spine::IkConstraintData &getData()
    spine::IkConstraintData &ret = self->getData();
    int num_ret = olua_push_object(L, &ret, "spine.IkConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraint");

    // float getMix()
    float ret = self->getMix();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraint");

    // int getOrder()
    int ret = self->getOrder();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getSoftness(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraint");

    // float getSoftness()
    float ret = self->getSoftness();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getStretch(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraint");

    // bool getStretch()
    bool ret = self->getStretch();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraint");

    // spine::Bone *getTarget()
    spine::Bone *ret = self->getTarget();
    int num_ret = olua_push_object(L, ret, "spine.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *arg1 = nullptr;       /** data */
    spine::Skeleton *arg2 = nullptr;       /** skeleton */

    olua_check_object(L, 1, &arg1, "spine.IkConstraintData");
    olua_check_object(L, 2, &arg2, "spine.Skeleton");

    // IkConstraint(spine::IkConstraintData &data, spine::Skeleton &skeleton)
    spine::IkConstraint *ret = new spine::IkConstraint(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "spine.IkConstraint");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_setBendDirection(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraint");
    olua_check_integer(L, 2, &arg1);

    // void setBendDirection(int inValue)
    self->setBendDirection(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_setCompress(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraint");
    olua_check_bool(L, 2, &arg1);

    // void setCompress(bool inValue)
    self->setCompress(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_setMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraint");
    olua_check_number(L, 2, &arg1);

    // void setMix(float inValue)
    self->setMix(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_setSoftness(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraint");
    olua_check_number(L, 2, &arg1);

    // void setSoftness(float inValue)
    self->setSoftness(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_setStretch(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraint");
    olua_check_bool(L, 2, &arg1);

    // void setStretch(bool inValue)
    self->setStretch(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;
    spine::Bone *arg1 = nullptr;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraint");
    olua_check_object(L, 2, &arg1, "spine.Bone");

    // void setTarget(spine::Bone *inValue)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_IkConstraint(lua_State *L)
{
    oluacls_class<spine::IkConstraint, spine::Updatable>(L, "spine.IkConstraint");
    oluacls_func(L, "apply", _spine_IkConstraint_apply);
    oluacls_func(L, "getBendDirection", _spine_IkConstraint_getBendDirection);
    oluacls_func(L, "getBones", _spine_IkConstraint_getBones);
    oluacls_func(L, "getCompress", _spine_IkConstraint_getCompress);
    oluacls_func(L, "getData", _spine_IkConstraint_getData);
    oluacls_func(L, "getMix", _spine_IkConstraint_getMix);
    oluacls_func(L, "getOrder", _spine_IkConstraint_getOrder);
    oluacls_func(L, "getSoftness", _spine_IkConstraint_getSoftness);
    oluacls_func(L, "getStretch", _spine_IkConstraint_getStretch);
    oluacls_func(L, "getTarget", _spine_IkConstraint_getTarget);
    oluacls_func(L, "new", _spine_IkConstraint_new);
    oluacls_func(L, "setBendDirection", _spine_IkConstraint_setBendDirection);
    oluacls_func(L, "setCompress", _spine_IkConstraint_setCompress);
    oluacls_func(L, "setMix", _spine_IkConstraint_setMix);
    oluacls_func(L, "setSoftness", _spine_IkConstraint_setSoftness);
    oluacls_func(L, "setStretch", _spine_IkConstraint_setStretch);
    oluacls_func(L, "setTarget", _spine_IkConstraint_setTarget);
    oluacls_prop(L, "bendDirection", _spine_IkConstraint_getBendDirection, _spine_IkConstraint_setBendDirection);
    oluacls_prop(L, "bones", _spine_IkConstraint_getBones, nullptr);
    oluacls_prop(L, "compress", _spine_IkConstraint_getCompress, _spine_IkConstraint_setCompress);
    oluacls_prop(L, "data", _spine_IkConstraint_getData, nullptr);
    oluacls_prop(L, "mix", _spine_IkConstraint_getMix, _spine_IkConstraint_setMix);
    oluacls_prop(L, "order", _spine_IkConstraint_getOrder, nullptr);
    oluacls_prop(L, "softness", _spine_IkConstraint_getSoftness, _spine_IkConstraint_setSoftness);
    oluacls_prop(L, "stretch", _spine_IkConstraint_getStretch, _spine_IkConstraint_setStretch);
    oluacls_prop(L, "target", _spine_IkConstraint_getTarget, _spine_IkConstraint_setTarget);

    return 1;
}
OLUA_END_DECLS

static int _spine_TransformConstraint_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraint");

    // spine::Vector<spine::Bone *> &getBones()
    spine::Vector<spine::Bone *> &ret = self->getBones();
    int num_ret = olua_push_vector<spine::Bone *>(L, ret, [L](spine::Bone *arg1) {
        olua_push_object(L, arg1, "spine.Bone");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getData(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraint");

    // spine::TransformConstraintData &getData()
    spine::TransformConstraintData &ret = self->getData();
    int num_ret = olua_push_object(L, &ret, "spine.TransformConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getMixRotate(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraint");

    // float getMixRotate()
    float ret = self->getMixRotate();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getMixScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraint");

    // float getMixScaleX()
    float ret = self->getMixScaleX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getMixScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraint");

    // float getMixScaleY()
    float ret = self->getMixScaleY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getMixShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraint");

    // float getMixShearY()
    float ret = self->getMixShearY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getMixX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraint");

    // float getMixX()
    float ret = self->getMixX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getMixY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraint");

    // float getMixY()
    float ret = self->getMixY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraint");

    // int getOrder()
    int ret = self->getOrder();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraint");

    // spine::Bone *getTarget()
    spine::Bone *ret = self->getTarget();
    int num_ret = olua_push_object(L, ret, "spine.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *arg1 = nullptr;       /** data */
    spine::Skeleton *arg2 = nullptr;       /** skeleton */

    olua_check_object(L, 1, &arg1, "spine.TransformConstraintData");
    olua_check_object(L, 2, &arg2, "spine.Skeleton");

    // TransformConstraint(spine::TransformConstraintData &data, spine::Skeleton &skeleton)
    spine::TransformConstraint *ret = new spine::TransformConstraint(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "spine.TransformConstraint");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_setMixRotate(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TransformConstraint");
    olua_check_number(L, 2, &arg1);

    // void setMixRotate(float inValue)
    self->setMixRotate(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraint_setMixScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TransformConstraint");
    olua_check_number(L, 2, &arg1);

    // void setMixScaleX(float inValue)
    self->setMixScaleX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraint_setMixScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TransformConstraint");
    olua_check_number(L, 2, &arg1);

    // void setMixScaleY(float inValue)
    self->setMixScaleY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraint_setMixShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TransformConstraint");
    olua_check_number(L, 2, &arg1);

    // void setMixShearY(float inValue)
    self->setMixShearY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraint_setMixX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TransformConstraint");
    olua_check_number(L, 2, &arg1);

    // void setMixX(float inValue)
    self->setMixX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraint_setMixY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TransformConstraint");
    olua_check_number(L, 2, &arg1);

    // void setMixY(float inValue)
    self->setMixY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraint_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    spine::Bone *arg1 = nullptr;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TransformConstraint");
    olua_check_object(L, 2, &arg1, "spine.Bone");

    // void setTarget(spine::Bone *inValue)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_TransformConstraint(lua_State *L)
{
    oluacls_class<spine::TransformConstraint, spine::Updatable>(L, "spine.TransformConstraint");
    oluacls_func(L, "getBones", _spine_TransformConstraint_getBones);
    oluacls_func(L, "getData", _spine_TransformConstraint_getData);
    oluacls_func(L, "getMixRotate", _spine_TransformConstraint_getMixRotate);
    oluacls_func(L, "getMixScaleX", _spine_TransformConstraint_getMixScaleX);
    oluacls_func(L, "getMixScaleY", _spine_TransformConstraint_getMixScaleY);
    oluacls_func(L, "getMixShearY", _spine_TransformConstraint_getMixShearY);
    oluacls_func(L, "getMixX", _spine_TransformConstraint_getMixX);
    oluacls_func(L, "getMixY", _spine_TransformConstraint_getMixY);
    oluacls_func(L, "getOrder", _spine_TransformConstraint_getOrder);
    oluacls_func(L, "getTarget", _spine_TransformConstraint_getTarget);
    oluacls_func(L, "new", _spine_TransformConstraint_new);
    oluacls_func(L, "setMixRotate", _spine_TransformConstraint_setMixRotate);
    oluacls_func(L, "setMixScaleX", _spine_TransformConstraint_setMixScaleX);
    oluacls_func(L, "setMixScaleY", _spine_TransformConstraint_setMixScaleY);
    oluacls_func(L, "setMixShearY", _spine_TransformConstraint_setMixShearY);
    oluacls_func(L, "setMixX", _spine_TransformConstraint_setMixX);
    oluacls_func(L, "setMixY", _spine_TransformConstraint_setMixY);
    oluacls_func(L, "setTarget", _spine_TransformConstraint_setTarget);
    oluacls_prop(L, "bones", _spine_TransformConstraint_getBones, nullptr);
    oluacls_prop(L, "data", _spine_TransformConstraint_getData, nullptr);
    oluacls_prop(L, "mixRotate", _spine_TransformConstraint_getMixRotate, _spine_TransformConstraint_setMixRotate);
    oluacls_prop(L, "mixScaleX", _spine_TransformConstraint_getMixScaleX, _spine_TransformConstraint_setMixScaleX);
    oluacls_prop(L, "mixScaleY", _spine_TransformConstraint_getMixScaleY, _spine_TransformConstraint_setMixScaleY);
    oluacls_prop(L, "mixShearY", _spine_TransformConstraint_getMixShearY, _spine_TransformConstraint_setMixShearY);
    oluacls_prop(L, "mixX", _spine_TransformConstraint_getMixX, _spine_TransformConstraint_setMixX);
    oluacls_prop(L, "mixY", _spine_TransformConstraint_getMixY, _spine_TransformConstraint_setMixY);
    oluacls_prop(L, "order", _spine_TransformConstraint_getOrder, nullptr);
    oluacls_prop(L, "target", _spine_TransformConstraint_getTarget, _spine_TransformConstraint_setTarget);

    return 1;
}
OLUA_END_DECLS

static int _spine_TransformConstraintData_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // spine::Vector<spine::BoneData *> &getBones()
    spine::Vector<spine::BoneData *> &ret = self->getBones();
    int num_ret = olua_push_vector<spine::BoneData *>(L, ret, [L](spine::BoneData *arg1) {
        olua_push_object(L, arg1, "spine.BoneData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getMixRotate(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getMixRotate()
    float ret = self->getMixRotate();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getMixScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getMixScaleX()
    float ret = self->getMixScaleX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getMixScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getMixScaleY()
    float ret = self->getMixScaleY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getMixShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getMixShearY()
    float ret = self->getMixShearY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getMixX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getMixX()
    float ret = self->getMixX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getMixY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getMixY()
    float ret = self->getMixY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getOffsetRotation()
    float ret = self->getOffsetRotation();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getOffsetScaleX()
    float ret = self->getOffsetScaleX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getOffsetScaleY()
    float ret = self->getOffsetScaleY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getOffsetShearY()
    float ret = self->getOffsetShearY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getOffsetX()
    float ret = self->getOffsetX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // float getOffsetY()
    float ret = self->getOffsetY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // spine::BoneData *getTarget()
    spine::BoneData *ret = self->getTarget();
    int num_ret = olua_push_object(L, ret, "spine.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_isLocal(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // bool isLocal()
    bool ret = self->isLocal();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_isRelative(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintData");

    // bool isRelative()
    bool ret = self->isRelative();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // TransformConstraintData(const spine::String &name)
    spine::TransformConstraintData *ret = new spine::TransformConstraintData(arg1);
    int num_ret = olua_push_object(L, ret, "spine.TransformConstraintData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_TransformConstraintData(lua_State *L)
{
    oluacls_class<spine::TransformConstraintData, spine::ConstraintData>(L, "spine.TransformConstraintData");
    oluacls_func(L, "getBones", _spine_TransformConstraintData_getBones);
    oluacls_func(L, "getMixRotate", _spine_TransformConstraintData_getMixRotate);
    oluacls_func(L, "getMixScaleX", _spine_TransformConstraintData_getMixScaleX);
    oluacls_func(L, "getMixScaleY", _spine_TransformConstraintData_getMixScaleY);
    oluacls_func(L, "getMixShearY", _spine_TransformConstraintData_getMixShearY);
    oluacls_func(L, "getMixX", _spine_TransformConstraintData_getMixX);
    oluacls_func(L, "getMixY", _spine_TransformConstraintData_getMixY);
    oluacls_func(L, "getOffsetRotation", _spine_TransformConstraintData_getOffsetRotation);
    oluacls_func(L, "getOffsetScaleX", _spine_TransformConstraintData_getOffsetScaleX);
    oluacls_func(L, "getOffsetScaleY", _spine_TransformConstraintData_getOffsetScaleY);
    oluacls_func(L, "getOffsetShearY", _spine_TransformConstraintData_getOffsetShearY);
    oluacls_func(L, "getOffsetX", _spine_TransformConstraintData_getOffsetX);
    oluacls_func(L, "getOffsetY", _spine_TransformConstraintData_getOffsetY);
    oluacls_func(L, "getTarget", _spine_TransformConstraintData_getTarget);
    oluacls_func(L, "isLocal", _spine_TransformConstraintData_isLocal);
    oluacls_func(L, "isRelative", _spine_TransformConstraintData_isRelative);
    oluacls_func(L, "new", _spine_TransformConstraintData_new);
    oluacls_prop(L, "bones", _spine_TransformConstraintData_getBones, nullptr);
    oluacls_prop(L, "local", _spine_TransformConstraintData_isLocal, nullptr);
    oluacls_prop(L, "mixRotate", _spine_TransformConstraintData_getMixRotate, nullptr);
    oluacls_prop(L, "mixScaleX", _spine_TransformConstraintData_getMixScaleX, nullptr);
    oluacls_prop(L, "mixScaleY", _spine_TransformConstraintData_getMixScaleY, nullptr);
    oluacls_prop(L, "mixShearY", _spine_TransformConstraintData_getMixShearY, nullptr);
    oluacls_prop(L, "mixX", _spine_TransformConstraintData_getMixX, nullptr);
    oluacls_prop(L, "mixY", _spine_TransformConstraintData_getMixY, nullptr);
    oluacls_prop(L, "offsetRotation", _spine_TransformConstraintData_getOffsetRotation, nullptr);
    oluacls_prop(L, "offsetScaleX", _spine_TransformConstraintData_getOffsetScaleX, nullptr);
    oluacls_prop(L, "offsetScaleY", _spine_TransformConstraintData_getOffsetScaleY, nullptr);
    oluacls_prop(L, "offsetShearY", _spine_TransformConstraintData_getOffsetShearY, nullptr);
    oluacls_prop(L, "offsetX", _spine_TransformConstraintData_getOffsetX, nullptr);
    oluacls_prop(L, "offsetY", _spine_TransformConstraintData_getOffsetY, nullptr);
    oluacls_prop(L, "relative", _spine_TransformConstraintData_isRelative, nullptr);
    oluacls_prop(L, "target", _spine_TransformConstraintData_getTarget, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _spine_PathConstraintData_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintData");

    // spine::Vector<spine::BoneData *> &getBones()
    spine::Vector<spine::BoneData *> &ret = self->getBones();
    int num_ret = olua_push_vector<spine::BoneData *>(L, ret, [L](spine::BoneData *arg1) {
        olua_push_object(L, arg1, "spine.BoneData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getMixRotate(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintData");

    // float getMixRotate()
    float ret = self->getMixRotate();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getMixX(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintData");

    // float getMixX()
    float ret = self->getMixX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getMixY(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintData");

    // float getMixY()
    float ret = self->getMixY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getOffsetRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintData");

    // float getOffsetRotation()
    float ret = self->getOffsetRotation();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintData");

    // float getPosition()
    float ret = self->getPosition();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getPositionMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintData");

    // spine::PositionMode getPositionMode()
    spine::PositionMode ret = self->getPositionMode();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getRotateMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintData");

    // spine::RotateMode getRotateMode()
    spine::RotateMode ret = self->getRotateMode();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getSpacing(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintData");

    // float getSpacing()
    float ret = self->getSpacing();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getSpacingMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintData");

    // spine::SpacingMode getSpacingMode()
    spine::SpacingMode ret = self->getSpacingMode();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintData");

    // spine::SlotData *getTarget()
    spine::SlotData *ret = self->getTarget();
    int num_ret = olua_push_object(L, ret, "spine.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // PathConstraintData(const spine::String &name)
    spine::PathConstraintData *ret = new spine::PathConstraintData(arg1);
    int num_ret = olua_push_object(L, ret, "spine.PathConstraintData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_setMixRotate(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setMixRotate(float inValue)
    self->setMixRotate(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setMixX(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setMixX(float inValue)
    self->setMixX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setMixY(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setMixY(float inValue)
    self->setMixY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setOffsetRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setOffsetRotation(float inValue)
    self->setOffsetRotation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setPosition(float inValue)
    self->setPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setPositionMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    spine::PositionMode arg1 = (spine::PositionMode)0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintData");
    olua_check_enum(L, 2, &arg1);

    // void setPositionMode(spine::PositionMode inValue)
    self->setPositionMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setRotateMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    spine::RotateMode arg1 = (spine::RotateMode)0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintData");
    olua_check_enum(L, 2, &arg1);

    // void setRotateMode(spine::RotateMode inValue)
    self->setRotateMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setSpacing(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setSpacing(float inValue)
    self->setSpacing(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setSpacingMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    spine::SpacingMode arg1 = (spine::SpacingMode)0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintData");
    olua_check_enum(L, 2, &arg1);

    // void setSpacingMode(spine::SpacingMode inValue)
    self->setSpacingMode(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    spine::SlotData *arg1 = nullptr;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintData");
    olua_check_object(L, 2, &arg1, "spine.SlotData");

    // void setTarget(spine::SlotData *inValue)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_PathConstraintData(lua_State *L)
{
    oluacls_class<spine::PathConstraintData, spine::ConstraintData>(L, "spine.PathConstraintData");
    oluacls_func(L, "getBones", _spine_PathConstraintData_getBones);
    oluacls_func(L, "getMixRotate", _spine_PathConstraintData_getMixRotate);
    oluacls_func(L, "getMixX", _spine_PathConstraintData_getMixX);
    oluacls_func(L, "getMixY", _spine_PathConstraintData_getMixY);
    oluacls_func(L, "getOffsetRotation", _spine_PathConstraintData_getOffsetRotation);
    oluacls_func(L, "getPosition", _spine_PathConstraintData_getPosition);
    oluacls_func(L, "getPositionMode", _spine_PathConstraintData_getPositionMode);
    oluacls_func(L, "getRotateMode", _spine_PathConstraintData_getRotateMode);
    oluacls_func(L, "getSpacing", _spine_PathConstraintData_getSpacing);
    oluacls_func(L, "getSpacingMode", _spine_PathConstraintData_getSpacingMode);
    oluacls_func(L, "getTarget", _spine_PathConstraintData_getTarget);
    oluacls_func(L, "new", _spine_PathConstraintData_new);
    oluacls_func(L, "setMixRotate", _spine_PathConstraintData_setMixRotate);
    oluacls_func(L, "setMixX", _spine_PathConstraintData_setMixX);
    oluacls_func(L, "setMixY", _spine_PathConstraintData_setMixY);
    oluacls_func(L, "setOffsetRotation", _spine_PathConstraintData_setOffsetRotation);
    oluacls_func(L, "setPosition", _spine_PathConstraintData_setPosition);
    oluacls_func(L, "setPositionMode", _spine_PathConstraintData_setPositionMode);
    oluacls_func(L, "setRotateMode", _spine_PathConstraintData_setRotateMode);
    oluacls_func(L, "setSpacing", _spine_PathConstraintData_setSpacing);
    oluacls_func(L, "setSpacingMode", _spine_PathConstraintData_setSpacingMode);
    oluacls_func(L, "setTarget", _spine_PathConstraintData_setTarget);
    oluacls_prop(L, "bones", _spine_PathConstraintData_getBones, nullptr);
    oluacls_prop(L, "mixRotate", _spine_PathConstraintData_getMixRotate, _spine_PathConstraintData_setMixRotate);
    oluacls_prop(L, "mixX", _spine_PathConstraintData_getMixX, _spine_PathConstraintData_setMixX);
    oluacls_prop(L, "mixY", _spine_PathConstraintData_getMixY, _spine_PathConstraintData_setMixY);
    oluacls_prop(L, "offsetRotation", _spine_PathConstraintData_getOffsetRotation, _spine_PathConstraintData_setOffsetRotation);
    oluacls_prop(L, "position", _spine_PathConstraintData_getPosition, _spine_PathConstraintData_setPosition);
    oluacls_prop(L, "positionMode", _spine_PathConstraintData_getPositionMode, _spine_PathConstraintData_setPositionMode);
    oluacls_prop(L, "rotateMode", _spine_PathConstraintData_getRotateMode, _spine_PathConstraintData_setRotateMode);
    oluacls_prop(L, "spacing", _spine_PathConstraintData_getSpacing, _spine_PathConstraintData_setSpacing);
    oluacls_prop(L, "spacingMode", _spine_PathConstraintData_getSpacingMode, _spine_PathConstraintData_setSpacingMode);
    oluacls_prop(L, "target", _spine_PathConstraintData_getTarget, _spine_PathConstraintData_setTarget);

    return 1;
}
OLUA_END_DECLS

static int _spine_SkeletonBounds_aabbIntersectsSkeleton(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    spine::SkeletonBounds arg1;       /** bounds */

    olua_to_object(L, 1, &self, "spine.SkeletonBounds");
    olua_check_object(L, 2, &arg1, "spine.SkeletonBounds");

    // bool aabbIntersectsSkeleton(spine::SkeletonBounds bounds)
    bool ret = self->aabbIntersectsSkeleton(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_aabbcontainsPoint(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */

    olua_to_object(L, 1, &self, "spine.SkeletonBounds");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // bool aabbcontainsPoint(float x, float y)
    bool ret = self->aabbcontainsPoint(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_aabbintersectsSegment(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    float arg1 = 0;       /** x1 */
    float arg2 = 0;       /** y1 */
    float arg3 = 0;       /** x2 */
    float arg4 = 0;       /** y2 */

    olua_to_object(L, 1, &self, "spine.SkeletonBounds");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // bool aabbintersectsSegment(float x1, float y1, float x2, float y2)
    bool ret = self->aabbintersectsSegment(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_containsPoint$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    spine::Polygon *arg1 = nullptr;       /** polygon */
    float arg2 = 0;       /** x */
    float arg3 = 0;       /** y */

    olua_to_object(L, 1, &self, "spine.SkeletonBounds");
    olua_check_object(L, 2, &arg1, "spine.Polygon");
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // bool containsPoint(spine::Polygon *polygon, float x, float y)
    bool ret = self->containsPoint(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_containsPoint$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */

    olua_to_object(L, 1, &self, "spine.SkeletonBounds");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // spine::BoundingBoxAttachment *containsPoint(float x, float y)
    spine::BoundingBoxAttachment *ret = self->containsPoint(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.BoundingBoxAttachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_containsPoint(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // spine::BoundingBoxAttachment *containsPoint(float x, float y)
            return _spine_SkeletonBounds_containsPoint$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 2, "spine.Polygon")) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // bool containsPoint(spine::Polygon *polygon, float x, float y)
            return _spine_SkeletonBounds_containsPoint$1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonBounds::containsPoint' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonBounds_getHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonBounds");

    // float getHeight()
    float ret = self->getHeight();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_getPolygon(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    spine::BoundingBoxAttachment *arg1 = nullptr;       /** attachment */

    olua_to_object(L, 1, &self, "spine.SkeletonBounds");
    olua_check_object(L, 2, &arg1, "spine.BoundingBoxAttachment");

    // spine::Polygon *getPolygon(spine::BoundingBoxAttachment *attachment)
    spine::Polygon *ret = self->getPolygon(arg1);
    int num_ret = olua_push_object(L, ret, "spine.Polygon");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonBounds");

    // float getWidth()
    float ret = self->getWidth();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_intersectsSegment$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    float arg1 = 0;       /** x1 */
    float arg2 = 0;       /** y1 */
    float arg3 = 0;       /** x2 */
    float arg4 = 0;       /** y2 */

    olua_to_object(L, 1, &self, "spine.SkeletonBounds");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // spine::BoundingBoxAttachment *intersectsSegment(float x1, float y1, float x2, float y2)
    spine::BoundingBoxAttachment *ret = self->intersectsSegment(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "spine.BoundingBoxAttachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_intersectsSegment$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    spine::Polygon *arg1 = nullptr;       /** polygon */
    float arg2 = 0;       /** x1 */
    float arg3 = 0;       /** y1 */
    float arg4 = 0;       /** x2 */
    float arg5 = 0;       /** y2 */

    olua_to_object(L, 1, &self, "spine.SkeletonBounds");
    olua_check_object(L, 2, &arg1, "spine.Polygon");
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_number(L, 6, &arg5);

    // bool intersectsSegment(spine::Polygon *polygon, float x1, float y1, float x2, float y2)
    bool ret = self->intersectsSegment(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_intersectsSegment(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 4) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // spine::BoundingBoxAttachment *intersectsSegment(float x1, float y1, float x2, float y2)
            return _spine_SkeletonBounds_intersectsSegment$1(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 2, "spine.Polygon")) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_number(L, 6))) {
            // bool intersectsSegment(spine::Polygon *polygon, float x1, float y1, float x2, float y2)
            return _spine_SkeletonBounds_intersectsSegment$2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonBounds::intersectsSegment' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonBounds_new(lua_State *L)
{
    olua_startinvoke(L);

    // SkeletonBounds()
    spine::SkeletonBounds *ret = new spine::SkeletonBounds();
    int num_ret = olua_push_object(L, ret, "spine.SkeletonBounds");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_update(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** updateAabb */

    olua_to_object(L, 1, &self, "spine.SkeletonBounds");
    olua_check_object(L, 2, &arg1, "spine.Skeleton");
    olua_check_bool(L, 3, &arg2);

    // void update(spine::Skeleton &skeleton, bool updateAabb)
    self->update(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_SkeletonBounds(lua_State *L)
{
    oluacls_class<spine::SkeletonBounds, spine::SpineObject>(L, "spine.SkeletonBounds");
    oluacls_func(L, "aabbIntersectsSkeleton", _spine_SkeletonBounds_aabbIntersectsSkeleton);
    oluacls_func(L, "aabbcontainsPoint", _spine_SkeletonBounds_aabbcontainsPoint);
    oluacls_func(L, "aabbintersectsSegment", _spine_SkeletonBounds_aabbintersectsSegment);
    oluacls_func(L, "containsPoint", _spine_SkeletonBounds_containsPoint);
    oluacls_func(L, "getHeight", _spine_SkeletonBounds_getHeight);
    oluacls_func(L, "getPolygon", _spine_SkeletonBounds_getPolygon);
    oluacls_func(L, "getWidth", _spine_SkeletonBounds_getWidth);
    oluacls_func(L, "intersectsSegment", _spine_SkeletonBounds_intersectsSegment);
    oluacls_func(L, "new", _spine_SkeletonBounds_new);
    oluacls_func(L, "update", _spine_SkeletonBounds_update);
    oluacls_prop(L, "height", _spine_SkeletonBounds_getHeight, nullptr);
    oluacls_prop(L, "width", _spine_SkeletonBounds_getWidth, nullptr);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_SkeletonClipping(lua_State *L)
{
    oluacls_class<spine::SkeletonClipping, spine::SpineObject>(L, "spine.SkeletonClipping");

    return 1;
}
OLUA_END_DECLS

static int _spine_Timeline_getDuration(lua_State *L)
{
    olua_startinvoke(L);

    spine::Timeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Timeline");

    // float getDuration()
    float ret = self->getDuration();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Timeline_getFrameCount(lua_State *L)
{
    olua_startinvoke(L);

    spine::Timeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Timeline");

    // size_t getFrameCount()
    size_t ret = self->getFrameCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Timeline_getFrameEntries(lua_State *L)
{
    olua_startinvoke(L);

    spine::Timeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Timeline");

    // size_t getFrameEntries()
    size_t ret = self->getFrameEntries();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Timeline_getFrames(lua_State *L)
{
    olua_startinvoke(L);

    spine::Timeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Timeline");

    // spine::Vector<float> &getFrames()
    spine::Vector<float> &ret = self->getFrames();
    int num_ret = olua_push_vector<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Timeline_getPropertyIds(lua_State *L)
{
    olua_startinvoke(L);

    spine::Timeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Timeline");

    // spine::Vector<spine::PropertyId> &getPropertyIds()
    spine::Vector<spine::PropertyId> &ret = self->getPropertyIds();
    int num_ret = olua_push_vector<spine::PropertyId>(L, ret, [L](spine::PropertyId &arg1) {
        olua_push_integer(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Timeline(lua_State *L)
{
    oluacls_class<spine::Timeline, spine::SpineObject>(L, "spine.Timeline");
    oluacls_func(L, "getDuration", _spine_Timeline_getDuration);
    oluacls_func(L, "getFrameCount", _spine_Timeline_getFrameCount);
    oluacls_func(L, "getFrameEntries", _spine_Timeline_getFrameEntries);
    oluacls_func(L, "getFrames", _spine_Timeline_getFrames);
    oluacls_func(L, "getPropertyIds", _spine_Timeline_getPropertyIds);
    oluacls_prop(L, "duration", _spine_Timeline_getDuration, nullptr);
    oluacls_prop(L, "frameCount", _spine_Timeline_getFrameCount, nullptr);
    oluacls_prop(L, "frameEntries", _spine_Timeline_getFrameEntries, nullptr);
    oluacls_prop(L, "frames", _spine_Timeline_getFrames, nullptr);
    oluacls_prop(L, "propertyIds", _spine_Timeline_getPropertyIds, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _spine_CurveTimeline_getBezierValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline *self = nullptr;
    float arg1 = 0;       /** time */
    size_t arg2 = 0;       /** frame */
    size_t arg3 = 0;       /** valueOffset */
    size_t arg4 = 0;       /** i */

    olua_to_object(L, 1, &self, "spine.CurveTimeline");
    olua_check_number(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);

    // float getBezierValue(float time, size_t frame, size_t valueOffset, size_t i)
    float ret = self->getBezierValue(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_CurveTimeline_getCurves(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.CurveTimeline");

    // spine::Vector<float> &getCurves()
    spine::Vector<float> &ret = self->getCurves();
    int num_ret = olua_push_vector<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_CurveTimeline_setBezier(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline *self = nullptr;
    size_t arg1 = 0;       /** bezier */
    size_t arg2 = 0;       /** frame */
    float arg3 = 0;       /** value */
    float arg4 = 0;       /** time1 */
    float arg5 = 0;       /** value1 */
    float arg6 = 0;       /** cx1 */
    float arg7 = 0;       /** cy1 */
    float arg8 = 0;       /** cx2 */
    float arg9 = 0;       /** cy2 */
    float arg10 = 0;       /** time2 */
    float arg11 = 0;       /** value2 */

    olua_to_object(L, 1, &self, "spine.CurveTimeline");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_number(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_number(L, 8, &arg7);
    olua_check_number(L, 9, &arg8);
    olua_check_number(L, 10, &arg9);
    olua_check_number(L, 11, &arg10);
    olua_check_number(L, 12, &arg11);

    // void setBezier(size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2)
    self->setBezier(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);

    olua_endinvoke(L);

    return 0;
}

static int _spine_CurveTimeline_setLinear(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline *self = nullptr;
    size_t arg1 = 0;       /** frame */

    olua_to_object(L, 1, &self, "spine.CurveTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setLinear(size_t frame)
    self->setLinear(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_CurveTimeline_setStepped(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline *self = nullptr;
    size_t arg1 = 0;       /** frame */

    olua_to_object(L, 1, &self, "spine.CurveTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setStepped(size_t frame)
    self->setStepped(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_CurveTimeline(lua_State *L)
{
    oluacls_class<spine::CurveTimeline, spine::Timeline>(L, "spine.CurveTimeline");
    oluacls_func(L, "getBezierValue", _spine_CurveTimeline_getBezierValue);
    oluacls_func(L, "getCurves", _spine_CurveTimeline_getCurves);
    oluacls_func(L, "setBezier", _spine_CurveTimeline_setBezier);
    oluacls_func(L, "setLinear", _spine_CurveTimeline_setLinear);
    oluacls_func(L, "setStepped", _spine_CurveTimeline_setStepped);
    oluacls_prop(L, "curves", _spine_CurveTimeline_getCurves, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _spine_CurveTimeline1_getCurveValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline1 *self = nullptr;
    float arg1 = 0;       /** time */

    olua_to_object(L, 1, &self, "spine.CurveTimeline1");
    olua_check_number(L, 2, &arg1);

    // float getCurveValue(float time)
    float ret = self->getCurveValue(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_CurveTimeline1(lua_State *L)
{
    oluacls_class<spine::CurveTimeline1, spine::CurveTimeline>(L, "spine.CurveTimeline1");
    oluacls_func(L, "getCurveValue", _spine_CurveTimeline1_getCurveValue);

    return 1;
}
OLUA_END_DECLS

static int _spine_CurveTimeline2_getCurveValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline2 *self = nullptr;
    float arg1 = 0;       /** time */

    olua_to_object(L, 1, &self, "spine.CurveTimeline2");
    olua_check_number(L, 2, &arg1);

    // float getCurveValue(float time)
    float ret = self->getCurveValue(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_CurveTimeline2(lua_State *L)
{
    oluacls_class<spine::CurveTimeline2, spine::CurveTimeline>(L, "spine.CurveTimeline2");
    oluacls_func(L, "getCurveValue", _spine_CurveTimeline2_getCurveValue);

    return 1;
}
OLUA_END_DECLS

static int _spine_AttachmentTimeline_getAttachmentNames(lua_State *L)
{
    olua_startinvoke(L);

    spine::AttachmentTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AttachmentTimeline");

    // spine::Vector<spine::String> &getAttachmentNames()
    spine::Vector<spine::String> &ret = self->getAttachmentNames();
    int num_ret = olua_push_vector<spine::String>(L, ret, [L](spine::String &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AttachmentTimeline_getSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::AttachmentTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AttachmentTimeline");

    // int getSlotIndex()
    int ret = self->getSlotIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AttachmentTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    int arg2 = 0;       /** slotIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);

    // AttachmentTimeline(size_t frameCount, int slotIndex)
    spine::AttachmentTimeline *ret = new spine::AttachmentTimeline(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.AttachmentTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AttachmentTimeline_setSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::AttachmentTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.AttachmentTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setSlotIndex(int inValue)
    self->setSlotIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_AttachmentTimeline(lua_State *L)
{
    oluacls_class<spine::AttachmentTimeline, spine::Timeline>(L, "spine.AttachmentTimeline");
    oluacls_func(L, "getAttachmentNames", _spine_AttachmentTimeline_getAttachmentNames);
    oluacls_func(L, "getSlotIndex", _spine_AttachmentTimeline_getSlotIndex);
    oluacls_func(L, "new", _spine_AttachmentTimeline_new);
    oluacls_func(L, "setSlotIndex", _spine_AttachmentTimeline_setSlotIndex);
    oluacls_prop(L, "attachmentNames", _spine_AttachmentTimeline_getAttachmentNames, nullptr);
    oluacls_prop(L, "slotIndex", _spine_AttachmentTimeline_getSlotIndex, _spine_AttachmentTimeline_setSlotIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_RGBATimeline_getSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RGBATimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RGBATimeline");

    // int getSlotIndex()
    int ret = self->getSlotIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RGBATimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** slotIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // RGBATimeline(size_t frameCount, size_t bezierCount, int slotIndex)
    spine::RGBATimeline *ret = new spine::RGBATimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.RGBATimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RGBATimeline_setSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RGBATimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RGBATimeline");
    olua_check_integer(L, 2, &arg1);

    // void setSlotIndex(int inValue)
    self->setSlotIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_RGBATimeline(lua_State *L)
{
    oluacls_class<spine::RGBATimeline, spine::CurveTimeline>(L, "spine.RGBATimeline");
    oluacls_func(L, "getSlotIndex", _spine_RGBATimeline_getSlotIndex);
    oluacls_func(L, "new", _spine_RGBATimeline_new);
    oluacls_func(L, "setSlotIndex", _spine_RGBATimeline_setSlotIndex);
    oluacls_prop(L, "slotIndex", _spine_RGBATimeline_getSlotIndex, _spine_RGBATimeline_setSlotIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_RGBTimeline_getSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RGBTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RGBTimeline");

    // int getSlotIndex()
    int ret = self->getSlotIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RGBTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** slotIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // RGBTimeline(size_t frameCount, size_t bezierCount, int slotIndex)
    spine::RGBTimeline *ret = new spine::RGBTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.RGBTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RGBTimeline_setSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RGBTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RGBTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setSlotIndex(int inValue)
    self->setSlotIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_RGBTimeline(lua_State *L)
{
    oluacls_class<spine::RGBTimeline, spine::CurveTimeline>(L, "spine.RGBTimeline");
    oluacls_func(L, "getSlotIndex", _spine_RGBTimeline_getSlotIndex);
    oluacls_func(L, "new", _spine_RGBTimeline_new);
    oluacls_func(L, "setSlotIndex", _spine_RGBTimeline_setSlotIndex);
    oluacls_prop(L, "slotIndex", _spine_RGBTimeline_getSlotIndex, _spine_RGBTimeline_setSlotIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_AlphaTimeline_getSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::AlphaTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.AlphaTimeline");

    // int getSlotIndex()
    int ret = self->getSlotIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AlphaTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** slotIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // AlphaTimeline(size_t frameCount, size_t bezierCount, int slotIndex)
    spine::AlphaTimeline *ret = new spine::AlphaTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.AlphaTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AlphaTimeline_setSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::AlphaTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.AlphaTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setSlotIndex(int inValue)
    self->setSlotIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_AlphaTimeline(lua_State *L)
{
    oluacls_class<spine::AlphaTimeline, spine::CurveTimeline1>(L, "spine.AlphaTimeline");
    oluacls_func(L, "getSlotIndex", _spine_AlphaTimeline_getSlotIndex);
    oluacls_func(L, "new", _spine_AlphaTimeline_new);
    oluacls_func(L, "setSlotIndex", _spine_AlphaTimeline_setSlotIndex);
    oluacls_prop(L, "slotIndex", _spine_AlphaTimeline_getSlotIndex, _spine_AlphaTimeline_setSlotIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_RGBA2Timeline_getSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RGBA2Timeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RGBA2Timeline");

    // int getSlotIndex()
    int ret = self->getSlotIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RGBA2Timeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** slotIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // RGBA2Timeline(size_t frameCount, size_t bezierCount, int slotIndex)
    spine::RGBA2Timeline *ret = new spine::RGBA2Timeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.RGBA2Timeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RGBA2Timeline_setSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RGBA2Timeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RGBA2Timeline");
    olua_check_integer(L, 2, &arg1);

    // void setSlotIndex(int inValue)
    self->setSlotIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_RGBA2Timeline(lua_State *L)
{
    oluacls_class<spine::RGBA2Timeline, spine::CurveTimeline>(L, "spine.RGBA2Timeline");
    oluacls_func(L, "getSlotIndex", _spine_RGBA2Timeline_getSlotIndex);
    oluacls_func(L, "new", _spine_RGBA2Timeline_new);
    oluacls_func(L, "setSlotIndex", _spine_RGBA2Timeline_setSlotIndex);
    oluacls_prop(L, "slotIndex", _spine_RGBA2Timeline_getSlotIndex, _spine_RGBA2Timeline_setSlotIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_RGB2Timeline_getSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RGB2Timeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RGB2Timeline");

    // int getSlotIndex()
    int ret = self->getSlotIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RGB2Timeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** slotIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // RGB2Timeline(size_t frameCount, size_t bezierCount, int slotIndex)
    spine::RGB2Timeline *ret = new spine::RGB2Timeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.RGB2Timeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RGB2Timeline_setSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RGB2Timeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RGB2Timeline");
    olua_check_integer(L, 2, &arg1);

    // void setSlotIndex(int inValue)
    self->setSlotIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_RGB2Timeline(lua_State *L)
{
    oluacls_class<spine::RGB2Timeline, spine::CurveTimeline>(L, "spine.RGB2Timeline");
    oluacls_func(L, "getSlotIndex", _spine_RGB2Timeline_getSlotIndex);
    oluacls_func(L, "new", _spine_RGB2Timeline_new);
    oluacls_func(L, "setSlotIndex", _spine_RGB2Timeline_setSlotIndex);
    oluacls_prop(L, "slotIndex", _spine_RGB2Timeline_getSlotIndex, _spine_RGB2Timeline_setSlotIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_DeformTimeline_getAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::DeformTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.DeformTimeline");

    // spine::VertexAttachment *getAttachment()
    spine::VertexAttachment *ret = self->getAttachment();
    int num_ret = olua_push_object(L, ret, "spine.VertexAttachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_DeformTimeline_getCurvePercent(lua_State *L)
{
    olua_startinvoke(L);

    spine::DeformTimeline *self = nullptr;
    float arg1 = 0;       /** time */
    int arg2 = 0;       /** frame */

    olua_to_object(L, 1, &self, "spine.DeformTimeline");
    olua_check_number(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // float getCurvePercent(float time, int frame)
    float ret = self->getCurvePercent(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_DeformTimeline_getSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::DeformTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.DeformTimeline");

    // int getSlotIndex()
    int ret = self->getSlotIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_DeformTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** slotIndex */
    spine::VertexAttachment *arg4 = nullptr;       /** attachment */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "spine.VertexAttachment");

    // DeformTimeline(size_t frameCount, size_t bezierCount, int slotIndex, spine::VertexAttachment *attachment)
    spine::DeformTimeline *ret = new spine::DeformTimeline(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "spine.DeformTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_DeformTimeline_setAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::DeformTimeline *self = nullptr;
    spine::VertexAttachment *arg1 = nullptr;       /** inValue */

    olua_to_object(L, 1, &self, "spine.DeformTimeline");
    olua_check_object(L, 2, &arg1, "spine.VertexAttachment");

    // void setAttachment(spine::VertexAttachment *inValue)
    self->setAttachment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_DeformTimeline_setSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::DeformTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.DeformTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setSlotIndex(int inValue)
    self->setSlotIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_DeformTimeline(lua_State *L)
{
    oluacls_class<spine::DeformTimeline, spine::CurveTimeline>(L, "spine.DeformTimeline");
    oluacls_func(L, "getAttachment", _spine_DeformTimeline_getAttachment);
    oluacls_func(L, "getCurvePercent", _spine_DeformTimeline_getCurvePercent);
    oluacls_func(L, "getSlotIndex", _spine_DeformTimeline_getSlotIndex);
    oluacls_func(L, "new", _spine_DeformTimeline_new);
    oluacls_func(L, "setAttachment", _spine_DeformTimeline_setAttachment);
    oluacls_func(L, "setSlotIndex", _spine_DeformTimeline_setSlotIndex);
    oluacls_prop(L, "attachment", _spine_DeformTimeline_getAttachment, _spine_DeformTimeline_setAttachment);
    oluacls_prop(L, "slotIndex", _spine_DeformTimeline_getSlotIndex, _spine_DeformTimeline_setSlotIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_DrawOrderTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */

    olua_check_integer(L, 1, &arg1);

    // DrawOrderTimeline(size_t frameCount)
    spine::DrawOrderTimeline *ret = new spine::DrawOrderTimeline(arg1);
    int num_ret = olua_push_object(L, ret, "spine.DrawOrderTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_DrawOrderTimeline(lua_State *L)
{
    oluacls_class<spine::DrawOrderTimeline, spine::Timeline>(L, "spine.DrawOrderTimeline");
    oluacls_func(L, "new", _spine_DrawOrderTimeline_new);

    return 1;
}
OLUA_END_DECLS

static int _spine_EventTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */

    olua_check_integer(L, 1, &arg1);

    // EventTimeline(size_t frameCount)
    spine::EventTimeline *ret = new spine::EventTimeline(arg1);
    int num_ret = olua_push_object(L, ret, "spine.EventTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_EventTimeline(lua_State *L)
{
    oluacls_class<spine::EventTimeline, spine::Timeline>(L, "spine.EventTimeline");
    oluacls_func(L, "new", _spine_EventTimeline_new);

    return 1;
}
OLUA_END_DECLS

static int _spine_ScaleXTimeline_getBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ScaleXTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.ScaleXTimeline");

    // int getBoneIndex()
    int ret = self->getBoneIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ScaleXTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** boneIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // ScaleXTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
    spine::ScaleXTimeline *ret = new spine::ScaleXTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.ScaleXTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ScaleXTimeline_setBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ScaleXTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.ScaleXTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setBoneIndex(int inValue)
    self->setBoneIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_ScaleXTimeline(lua_State *L)
{
    oluacls_class<spine::ScaleXTimeline, spine::CurveTimeline1>(L, "spine.ScaleXTimeline");
    oluacls_func(L, "getBoneIndex", _spine_ScaleXTimeline_getBoneIndex);
    oluacls_func(L, "new", _spine_ScaleXTimeline_new);
    oluacls_func(L, "setBoneIndex", _spine_ScaleXTimeline_setBoneIndex);
    oluacls_prop(L, "boneIndex", _spine_ScaleXTimeline_getBoneIndex, _spine_ScaleXTimeline_setBoneIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_ScaleYTimeline_getBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ScaleYTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.ScaleYTimeline");

    // int getBoneIndex()
    int ret = self->getBoneIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ScaleYTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** boneIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // ScaleYTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
    spine::ScaleYTimeline *ret = new spine::ScaleYTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.ScaleYTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ScaleYTimeline_setBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ScaleYTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.ScaleYTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setBoneIndex(int inValue)
    self->setBoneIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_ScaleYTimeline(lua_State *L)
{
    oluacls_class<spine::ScaleYTimeline, spine::CurveTimeline1>(L, "spine.ScaleYTimeline");
    oluacls_func(L, "getBoneIndex", _spine_ScaleYTimeline_getBoneIndex);
    oluacls_func(L, "new", _spine_ScaleYTimeline_new);
    oluacls_func(L, "setBoneIndex", _spine_ScaleYTimeline_setBoneIndex);
    oluacls_prop(L, "boneIndex", _spine_ScaleYTimeline_getBoneIndex, _spine_ScaleYTimeline_setBoneIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_ShearXTimeline_getBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ShearXTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.ShearXTimeline");

    // int getBoneIndex()
    int ret = self->getBoneIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ShearXTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** boneIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // ShearXTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
    spine::ShearXTimeline *ret = new spine::ShearXTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.ShearXTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ShearXTimeline_setBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ShearXTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.ShearXTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setBoneIndex(int inValue)
    self->setBoneIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_ShearXTimeline(lua_State *L)
{
    oluacls_class<spine::ShearXTimeline, spine::CurveTimeline1>(L, "spine.ShearXTimeline");
    oluacls_func(L, "getBoneIndex", _spine_ShearXTimeline_getBoneIndex);
    oluacls_func(L, "new", _spine_ShearXTimeline_new);
    oluacls_func(L, "setBoneIndex", _spine_ShearXTimeline_setBoneIndex);
    oluacls_prop(L, "boneIndex", _spine_ShearXTimeline_getBoneIndex, _spine_ShearXTimeline_setBoneIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_ShearYTimeline_getBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ShearYTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.ShearYTimeline");

    // int getBoneIndex()
    int ret = self->getBoneIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ShearYTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** boneIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // ShearYTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
    spine::ShearYTimeline *ret = new spine::ShearYTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.ShearYTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ShearYTimeline_setBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ShearYTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.ShearYTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setBoneIndex(int inValue)
    self->setBoneIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_ShearYTimeline(lua_State *L)
{
    oluacls_class<spine::ShearYTimeline, spine::CurveTimeline1>(L, "spine.ShearYTimeline");
    oluacls_func(L, "getBoneIndex", _spine_ShearYTimeline_getBoneIndex);
    oluacls_func(L, "new", _spine_ShearYTimeline_new);
    oluacls_func(L, "setBoneIndex", _spine_ShearYTimeline_setBoneIndex);
    oluacls_prop(L, "boneIndex", _spine_ShearYTimeline_getBoneIndex, _spine_ShearYTimeline_setBoneIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_TranslateXTimeline_getBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TranslateXTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TranslateXTimeline");

    // int getBoneIndex()
    int ret = self->getBoneIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TranslateXTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** boneIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // TranslateXTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
    spine::TranslateXTimeline *ret = new spine::TranslateXTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.TranslateXTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TranslateXTimeline_setBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TranslateXTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TranslateXTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setBoneIndex(int inValue)
    self->setBoneIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_TranslateXTimeline(lua_State *L)
{
    oluacls_class<spine::TranslateXTimeline, spine::CurveTimeline1>(L, "spine.TranslateXTimeline");
    oluacls_func(L, "getBoneIndex", _spine_TranslateXTimeline_getBoneIndex);
    oluacls_func(L, "new", _spine_TranslateXTimeline_new);
    oluacls_func(L, "setBoneIndex", _spine_TranslateXTimeline_setBoneIndex);
    oluacls_prop(L, "boneIndex", _spine_TranslateXTimeline_getBoneIndex, _spine_TranslateXTimeline_setBoneIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_TranslateYTimeline_getBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TranslateYTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TranslateYTimeline");

    // int getBoneIndex()
    int ret = self->getBoneIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TranslateYTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** boneIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // TranslateYTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
    spine::TranslateYTimeline *ret = new spine::TranslateYTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.TranslateYTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TranslateYTimeline_setBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TranslateYTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TranslateYTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setBoneIndex(int inValue)
    self->setBoneIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_TranslateYTimeline(lua_State *L)
{
    oluacls_class<spine::TranslateYTimeline, spine::CurveTimeline1>(L, "spine.TranslateYTimeline");
    oluacls_func(L, "getBoneIndex", _spine_TranslateYTimeline_getBoneIndex);
    oluacls_func(L, "new", _spine_TranslateYTimeline_new);
    oluacls_func(L, "setBoneIndex", _spine_TranslateYTimeline_setBoneIndex);
    oluacls_prop(L, "boneIndex", _spine_TranslateYTimeline_getBoneIndex, _spine_TranslateYTimeline_setBoneIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_IkConstraintTimeline_getIkConstraintIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.IkConstraintTimeline");

    // int getIkConstraintIndex()
    int ret = self->getIkConstraintIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** ikConstraintIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // IkConstraintTimeline(size_t frameCount, size_t bezierCount, int ikConstraintIndex)
    spine::IkConstraintTimeline *ret = new spine::IkConstraintTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.IkConstraintTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintTimeline_setIkConstraintIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.IkConstraintTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setIkConstraintIndex(int inValue)
    self->setIkConstraintIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_IkConstraintTimeline(lua_State *L)
{
    oluacls_class<spine::IkConstraintTimeline, spine::CurveTimeline>(L, "spine.IkConstraintTimeline");
    oluacls_func(L, "getIkConstraintIndex", _spine_IkConstraintTimeline_getIkConstraintIndex);
    oluacls_func(L, "new", _spine_IkConstraintTimeline_new);
    oluacls_func(L, "setIkConstraintIndex", _spine_IkConstraintTimeline_setIkConstraintIndex);
    oluacls_prop(L, "ikConstraintIndex", _spine_IkConstraintTimeline_getIkConstraintIndex, _spine_IkConstraintTimeline_setIkConstraintIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_PathConstraintMixTimeline_getPathConstraintIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintMixTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintMixTimeline");

    // int getPathConstraintIndex()
    int ret = self->getPathConstraintIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintMixTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** pathConstraintIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // PathConstraintMixTimeline(size_t frameCount, size_t bezierCount, int pathConstraintIndex)
    spine::PathConstraintMixTimeline *ret = new spine::PathConstraintMixTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.PathConstraintMixTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintMixTimeline_setPathConstraintIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintMixTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintMixTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setPathConstraintIndex(int inValue)
    self->setPathConstraintIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_PathConstraintMixTimeline(lua_State *L)
{
    oluacls_class<spine::PathConstraintMixTimeline, spine::CurveTimeline>(L, "spine.PathConstraintMixTimeline");
    oluacls_func(L, "getPathConstraintIndex", _spine_PathConstraintMixTimeline_getPathConstraintIndex);
    oluacls_func(L, "new", _spine_PathConstraintMixTimeline_new);
    oluacls_func(L, "setPathConstraintIndex", _spine_PathConstraintMixTimeline_setPathConstraintIndex);
    oluacls_prop(L, "pathConstraintIndex", _spine_PathConstraintMixTimeline_getPathConstraintIndex, _spine_PathConstraintMixTimeline_setPathConstraintIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_PathConstraintPositionTimeline_getPathConstraintIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintPositionTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintPositionTimeline");

    // int getPathConstraintIndex()
    int ret = self->getPathConstraintIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintPositionTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** pathConstraintIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // PathConstraintPositionTimeline(size_t frameCount, size_t bezierCount, int pathConstraintIndex)
    spine::PathConstraintPositionTimeline *ret = new spine::PathConstraintPositionTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.PathConstraintPositionTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintPositionTimeline_setPathConstraintIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintPositionTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintPositionTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setPathConstraintIndex(int inValue)
    self->setPathConstraintIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_PathConstraintPositionTimeline(lua_State *L)
{
    oluacls_class<spine::PathConstraintPositionTimeline, spine::CurveTimeline1>(L, "spine.PathConstraintPositionTimeline");
    oluacls_func(L, "getPathConstraintIndex", _spine_PathConstraintPositionTimeline_getPathConstraintIndex);
    oluacls_func(L, "new", _spine_PathConstraintPositionTimeline_new);
    oluacls_func(L, "setPathConstraintIndex", _spine_PathConstraintPositionTimeline_setPathConstraintIndex);
    oluacls_prop(L, "pathConstraintIndex", _spine_PathConstraintPositionTimeline_getPathConstraintIndex, _spine_PathConstraintPositionTimeline_setPathConstraintIndex);
    oluacls_const(L, "ENTRIES", spine::PathConstraintPositionTimeline::ENTRIES);

    return 1;
}
OLUA_END_DECLS

static int _spine_PathConstraintSpacingTimeline_getPathConstraintIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintSpacingTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraintSpacingTimeline");

    // int getPathConstraintIndex()
    int ret = self->getPathConstraintIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintSpacingTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** pathConstraintIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // PathConstraintSpacingTimeline(size_t frameCount, size_t bezierCount, int pathConstraintIndex)
    spine::PathConstraintSpacingTimeline *ret = new spine::PathConstraintSpacingTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.PathConstraintSpacingTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintSpacingTimeline_setPathConstraintIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintSpacingTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraintSpacingTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setPathConstraintIndex(int inValue)
    self->setPathConstraintIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_PathConstraintSpacingTimeline(lua_State *L)
{
    oluacls_class<spine::PathConstraintSpacingTimeline, spine::CurveTimeline1>(L, "spine.PathConstraintSpacingTimeline");
    oluacls_func(L, "getPathConstraintIndex", _spine_PathConstraintSpacingTimeline_getPathConstraintIndex);
    oluacls_func(L, "new", _spine_PathConstraintSpacingTimeline_new);
    oluacls_func(L, "setPathConstraintIndex", _spine_PathConstraintSpacingTimeline_setPathConstraintIndex);
    oluacls_prop(L, "pathConstraintIndex", _spine_PathConstraintSpacingTimeline_getPathConstraintIndex, _spine_PathConstraintSpacingTimeline_setPathConstraintIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_TranslateTimeline_getBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TranslateTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TranslateTimeline");

    // int getBoneIndex()
    int ret = self->getBoneIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TranslateTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** boneIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // TranslateTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
    spine::TranslateTimeline *ret = new spine::TranslateTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.TranslateTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TranslateTimeline_setBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TranslateTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TranslateTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setBoneIndex(int inValue)
    self->setBoneIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_TranslateTimeline(lua_State *L)
{
    oluacls_class<spine::TranslateTimeline, spine::CurveTimeline2>(L, "spine.TranslateTimeline");
    oluacls_func(L, "getBoneIndex", _spine_TranslateTimeline_getBoneIndex);
    oluacls_func(L, "new", _spine_TranslateTimeline_new);
    oluacls_func(L, "setBoneIndex", _spine_TranslateTimeline_setBoneIndex);
    oluacls_prop(L, "boneIndex", _spine_TranslateTimeline_getBoneIndex, _spine_TranslateTimeline_setBoneIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_ShearTimeline_getBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ShearTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.ShearTimeline");

    // int getBoneIndex()
    int ret = self->getBoneIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ShearTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** boneIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // ShearTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
    spine::ShearTimeline *ret = new spine::ShearTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.ShearTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ShearTimeline_setBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ShearTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.ShearTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setBoneIndex(int inValue)
    self->setBoneIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_ShearTimeline(lua_State *L)
{
    oluacls_class<spine::ShearTimeline, spine::CurveTimeline2>(L, "spine.ShearTimeline");
    oluacls_func(L, "getBoneIndex", _spine_ShearTimeline_getBoneIndex);
    oluacls_func(L, "new", _spine_ShearTimeline_new);
    oluacls_func(L, "setBoneIndex", _spine_ShearTimeline_setBoneIndex);
    oluacls_prop(L, "boneIndex", _spine_ShearTimeline_getBoneIndex, _spine_ShearTimeline_setBoneIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_TransformConstraintTimeline_getTransformConstraintIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TransformConstraintTimeline");

    // int getTransformConstraintIndex()
    int ret = self->getTransformConstraintIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** transformConstraintIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // TransformConstraintTimeline(size_t frameCount, size_t bezierCount, int transformConstraintIndex)
    spine::TransformConstraintTimeline *ret = new spine::TransformConstraintTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.TransformConstraintTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintTimeline_setTransformConstraintIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TransformConstraintTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setTransformConstraintIndex(int inValue)
    self->setTransformConstraintIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_TransformConstraintTimeline(lua_State *L)
{
    oluacls_class<spine::TransformConstraintTimeline, spine::CurveTimeline>(L, "spine.TransformConstraintTimeline");
    oluacls_func(L, "getTransformConstraintIndex", _spine_TransformConstraintTimeline_getTransformConstraintIndex);
    oluacls_func(L, "new", _spine_TransformConstraintTimeline_new);
    oluacls_func(L, "setTransformConstraintIndex", _spine_TransformConstraintTimeline_setTransformConstraintIndex);
    oluacls_prop(L, "transformConstraintIndex", _spine_TransformConstraintTimeline_getTransformConstraintIndex, _spine_TransformConstraintTimeline_setTransformConstraintIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_ScaleTimeline_getBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ScaleTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.ScaleTimeline");

    // int getBoneIndex()
    int ret = self->getBoneIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ScaleTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** boneIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // ScaleTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
    spine::ScaleTimeline *ret = new spine::ScaleTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.ScaleTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ScaleTimeline_setBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ScaleTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.ScaleTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setBoneIndex(int inValue)
    self->setBoneIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_ScaleTimeline(lua_State *L)
{
    oluacls_class<spine::ScaleTimeline, spine::CurveTimeline2>(L, "spine.ScaleTimeline");
    oluacls_func(L, "getBoneIndex", _spine_ScaleTimeline_getBoneIndex);
    oluacls_func(L, "new", _spine_ScaleTimeline_new);
    oluacls_func(L, "setBoneIndex", _spine_ScaleTimeline_setBoneIndex);
    oluacls_prop(L, "boneIndex", _spine_ScaleTimeline_getBoneIndex, _spine_ScaleTimeline_setBoneIndex);

    return 1;
}
OLUA_END_DECLS

static int _spine_RotateTimeline_getBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RotateTimeline *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RotateTimeline");

    // int getBoneIndex()
    int ret = self->getBoneIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RotateTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** frameCount */
    size_t arg2 = 0;       /** bezierCount */
    int arg3 = 0;       /** boneIndex */

    olua_check_integer(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);

    // RotateTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
    spine::RotateTimeline *ret = new spine::RotateTimeline(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.RotateTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RotateTimeline_setBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RotateTimeline *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RotateTimeline");
    olua_check_integer(L, 2, &arg1);

    // void setBoneIndex(int inValue)
    self->setBoneIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_RotateTimeline(lua_State *L)
{
    oluacls_class<spine::RotateTimeline, spine::CurveTimeline1>(L, "spine.RotateTimeline");
    oluacls_func(L, "getBoneIndex", _spine_RotateTimeline_getBoneIndex);
    oluacls_func(L, "new", _spine_RotateTimeline_new);
    oluacls_func(L, "setBoneIndex", _spine_RotateTimeline_setBoneIndex);
    oluacls_prop(L, "boneIndex", _spine_RotateTimeline_getBoneIndex, _spine_RotateTimeline_setBoneIndex);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Polygon(lua_State *L)
{
    oluacls_class<spine::Polygon, spine::SpineObject>(L, "spine.Polygon");

    return 1;
}
OLUA_END_DECLS

static int _spine_Skin_addSkin(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;
    spine::Skin *arg1 = nullptr;       /** other */

    olua_to_object(L, 1, &self, "spine.Skin");
    olua_check_object(L, 2, &arg1, "spine.Skin");

    // void addSkin(spine::Skin *other)
    self->addSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skin_copySkin(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;
    spine::Skin *arg1 = nullptr;       /** other */

    olua_to_object(L, 1, &self, "spine.Skin");
    olua_check_object(L, 2, &arg1, "spine.Skin");

    // void copySkin(spine::Skin *other)
    self->copySkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skin_getAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;
    size_t arg1 = 0;       /** slotIndex */
    spine::String arg2;       /** name */

    olua_to_object(L, 1, &self, "spine.Skin");
    olua_check_integer(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // spine::Attachment *getAttachment(size_t slotIndex, const spine::String &name)
    spine::Attachment *ret = self->getAttachment(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skin_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skin");

    // spine::Vector<spine::BoneData *> &getBones()
    spine::Vector<spine::BoneData *> &ret = self->getBones();
    int num_ret = olua_push_vector<spine::BoneData *>(L, ret, [L](spine::BoneData *arg1) {
        olua_push_object(L, arg1, "spine.BoneData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skin_getConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skin");

    // spine::Vector<spine::ConstraintData *> &getConstraints()
    spine::Vector<spine::ConstraintData *> &ret = self->getConstraints();
    int num_ret = olua_push_vector<spine::ConstraintData *>(L, ret, [L](spine::ConstraintData *arg1) {
        olua_push_object(L, arg1, "spine.ConstraintData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skin_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skin");

    // const spine::String &getName()
    const spine::String &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skin_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // Skin(const spine::String &name)
    spine::Skin *ret = new spine::Skin(arg1);
    int num_ret = olua_push_object(L, ret, "spine.Skin");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skin_removeAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;
    size_t arg1 = 0;       /** slotIndex */
    spine::String arg2;       /** name */

    olua_to_object(L, 1, &self, "spine.Skin");
    olua_check_integer(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void removeAttachment(size_t slotIndex, const spine::String &name)
    self->removeAttachment(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skin_setAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;
    size_t arg1 = 0;       /** slotIndex */
    spine::String arg2;       /** name */
    spine::Attachment *arg3 = nullptr;       /** attachment */

    olua_to_object(L, 1, &self, "spine.Skin");
    olua_check_integer(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_object(L, 4, &arg3, "spine.Attachment");

    // void setAttachment(size_t slotIndex, const spine::String &name, spine::Attachment *attachment)
    self->setAttachment(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Skin(lua_State *L)
{
    oluacls_class<spine::Skin, spine::SpineObject>(L, "spine.Skin");
    oluacls_func(L, "addSkin", _spine_Skin_addSkin);
    oluacls_func(L, "copySkin", _spine_Skin_copySkin);
    oluacls_func(L, "getAttachment", _spine_Skin_getAttachment);
    oluacls_func(L, "getBones", _spine_Skin_getBones);
    oluacls_func(L, "getConstraints", _spine_Skin_getConstraints);
    oluacls_func(L, "getName", _spine_Skin_getName);
    oluacls_func(L, "new", _spine_Skin_new);
    oluacls_func(L, "removeAttachment", _spine_Skin_removeAttachment);
    oluacls_func(L, "setAttachment", _spine_Skin_setAttachment);
    oluacls_prop(L, "bones", _spine_Skin_getBones, nullptr);
    oluacls_prop(L, "constraints", _spine_Skin_getConstraints, nullptr);
    oluacls_prop(L, "name", _spine_Skin_getName, nullptr);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Atlas(lua_State *L)
{
    oluacls_class<spine::Atlas, spine::SpineObject>(L, "spine.Atlas");

    return 1;
}
OLUA_END_DECLS

static int _spine_Bone_getA(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getA()
    float ret = self->getA();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getAScaleX()
    float ret = self->getAScaleX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getAScaleY()
    float ret = self->getAScaleY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getAShearX()
    float ret = self->getAShearX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getAShearY()
    float ret = self->getAShearY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getAX()
    float ret = self->getAX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getAY()
    float ret = self->getAY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAppliedRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getAppliedRotation()
    float ret = self->getAppliedRotation();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getB(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getB()
    float ret = self->getB();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getC(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getC()
    float ret = self->getC();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getChildren(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // spine::Vector<spine::Bone *> &getChildren()
    spine::Vector<spine::Bone *> &ret = self->getChildren();
    int num_ret = olua_push_vector<spine::Bone *>(L, ret, [L](spine::Bone *arg1) {
        olua_push_object(L, arg1, "spine.Bone");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getD(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getD()
    float ret = self->getD();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getData(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // spine::BoneData &getData()
    spine::BoneData &ret = self->getData();
    int num_ret = olua_push_object(L, &ret, "spine.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getParent(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // spine::Bone *getParent()
    spine::Bone *ret = self->getParent();
    int num_ret = olua_push_object(L, ret, "spine.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getRotation()
    float ret = self->getRotation();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getScaleX()
    float ret = self->getScaleX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getScaleY()
    float ret = self->getScaleY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getShearX()
    float ret = self->getShearX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getShearY()
    float ret = self->getShearY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getSkeleton(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // spine::Skeleton &getSkeleton()
    spine::Skeleton &ret = self->getSkeleton();
    int num_ret = olua_push_object(L, &ret, "spine.Skeleton");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldRotationX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getWorldRotationX()
    float ret = self->getWorldRotationX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldRotationY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getWorldRotationY()
    float ret = self->getWorldRotationY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getWorldScaleX()
    float ret = self->getWorldScaleX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getWorldScaleY()
    float ret = self->getWorldScaleY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldToLocalRotationX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getWorldToLocalRotationX()
    float ret = self->getWorldToLocalRotationX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldToLocalRotationY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getWorldToLocalRotationY()
    float ret = self->getWorldToLocalRotationY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getWorldX()
    float ret = self->getWorldX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getWorldY()
    float ret = self->getWorldY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getX()
    float ret = self->getX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // float getY()
    float ret = self->getY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_isYDown(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isYDown()
    bool ret = spine::Bone::isYDown();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_localToWorldRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** localRotation */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // float localToWorldRotation(float localRotation)
    float ret = self->localToWorldRotation(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_new$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *arg1 = nullptr;       /** data */
    spine::Skeleton *arg2 = nullptr;       /** skeleton */
    spine::Bone *arg3 = nullptr;       /** parent */

    olua_check_object(L, 1, &arg1, "spine.BoneData");
    olua_check_object(L, 2, &arg2, "spine.Skeleton");
    olua_check_object(L, 3, &arg3, "spine.Bone");

    // Bone(spine::BoneData &data, spine::Skeleton &skeleton, @optional spine::Bone *parent)
    spine::Bone *ret = new spine::Bone(*arg1, *arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.Bone");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_new$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *arg1 = nullptr;       /** data */
    spine::Skeleton *arg2 = nullptr;       /** skeleton */

    olua_check_object(L, 1, &arg1, "spine.BoneData");
    olua_check_object(L, 2, &arg2, "spine.Skeleton");

    // Bone(spine::BoneData &data, spine::Skeleton &skeleton, @optional spine::Bone *parent)
    spine::Bone *ret = new spine::Bone(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "spine.Bone");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "spine.BoneData")) && (olua_is_object(L, 2, "spine.Skeleton"))) {
            // Bone(spine::BoneData &data, spine::Skeleton &skeleton, @optional spine::Bone *parent)
            return _spine_Bone_new$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "spine.BoneData")) && (olua_is_object(L, 2, "spine.Skeleton")) && (olua_is_object(L, 3, "spine.Bone"))) {
            // Bone(spine::BoneData &data, spine::Skeleton &skeleton, @optional spine::Bone *parent)
            return _spine_Bone_new$1(L);
        // }
    }

    luaL_error(L, "method 'spine::Bone::new' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_Bone_rotateWorld(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** degrees */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void rotateWorld(float degrees)
    self->rotateWorld(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setA(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setA(float inValue)
    self->setA(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAScaleX(float inValue)
    self->setAScaleX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAScaleY(float inValue)
    self->setAScaleY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAShearX(float inValue)
    self->setAShearX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAShearY(float inValue)
    self->setAShearY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAX(float inValue)
    self->setAX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAY(float inValue)
    self->setAY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAppliedRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAppliedRotation(float inValue)
    self->setAppliedRotation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setB(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setB(float inValue)
    self->setB(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setC(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setC(float inValue)
    self->setC(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setD(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setD(float inValue)
    self->setD(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setRotation(float inValue)
    self->setRotation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setScaleX(float inValue)
    self->setScaleX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setScaleY(float inValue)
    self->setScaleY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setShearX(float inValue)
    self->setShearX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setShearY(float inValue)
    self->setShearY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // void setToSetupPose()
    self->setToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setWorldX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setWorldX(float inValue)
    self->setWorldX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setWorldY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setWorldY(float inValue)
    self->setWorldY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setYDown(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** inValue */

    olua_check_bool(L, 1, &arg1);

    // static void setYDown(bool inValue)
    spine::Bone::setYDown(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_updateWorldTransform$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Bone");

    // void updateWorldTransform()
    self->updateWorldTransform();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_updateWorldTransform$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */
    float arg3 = 0;       /** rotation */
    float arg4 = 0;       /** scaleX */
    float arg5 = 0;       /** scaleY */
    float arg6 = 0;       /** shearX */
    float arg7 = 0;       /** shearY */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_number(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_number(L, 8, &arg7);

    // void updateWorldTransform(float x, float y, float rotation, float scaleX, float scaleY, float shearX, float shearY)
    self->updateWorldTransform(arg1, arg2, arg3, arg4, arg5, arg6, arg7);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_updateWorldTransform(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void updateWorldTransform()
        return _spine_Bone_updateWorldTransform$1(L);
    }

    if (num_args == 7) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_number(L, 6)) && (olua_is_number(L, 7)) && (olua_is_number(L, 8))) {
            // void updateWorldTransform(float x, float y, float rotation, float scaleX, float scaleY, float shearX, float shearY)
            return _spine_Bone_updateWorldTransform$2(L);
        // }
    }

    luaL_error(L, "method 'spine::Bone::updateWorldTransform' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_Bone_worldToLocalRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    float arg1 = 0;       /** worldRotation */

    olua_to_object(L, 1, &self, "spine.Bone");
    olua_check_number(L, 2, &arg1);

    // float worldToLocalRotation(float worldRotation)
    float ret = self->worldToLocalRotation(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Bone(lua_State *L)
{
    oluacls_class<spine::Bone, spine::Updatable>(L, "spine.Bone");
    oluacls_func(L, "getA", _spine_Bone_getA);
    oluacls_func(L, "getAScaleX", _spine_Bone_getAScaleX);
    oluacls_func(L, "getAScaleY", _spine_Bone_getAScaleY);
    oluacls_func(L, "getAShearX", _spine_Bone_getAShearX);
    oluacls_func(L, "getAShearY", _spine_Bone_getAShearY);
    oluacls_func(L, "getAX", _spine_Bone_getAX);
    oluacls_func(L, "getAY", _spine_Bone_getAY);
    oluacls_func(L, "getAppliedRotation", _spine_Bone_getAppliedRotation);
    oluacls_func(L, "getB", _spine_Bone_getB);
    oluacls_func(L, "getC", _spine_Bone_getC);
    oluacls_func(L, "getChildren", _spine_Bone_getChildren);
    oluacls_func(L, "getD", _spine_Bone_getD);
    oluacls_func(L, "getData", _spine_Bone_getData);
    oluacls_func(L, "getParent", _spine_Bone_getParent);
    oluacls_func(L, "getRotation", _spine_Bone_getRotation);
    oluacls_func(L, "getScaleX", _spine_Bone_getScaleX);
    oluacls_func(L, "getScaleY", _spine_Bone_getScaleY);
    oluacls_func(L, "getShearX", _spine_Bone_getShearX);
    oluacls_func(L, "getShearY", _spine_Bone_getShearY);
    oluacls_func(L, "getSkeleton", _spine_Bone_getSkeleton);
    oluacls_func(L, "getWorldRotationX", _spine_Bone_getWorldRotationX);
    oluacls_func(L, "getWorldRotationY", _spine_Bone_getWorldRotationY);
    oluacls_func(L, "getWorldScaleX", _spine_Bone_getWorldScaleX);
    oluacls_func(L, "getWorldScaleY", _spine_Bone_getWorldScaleY);
    oluacls_func(L, "getWorldToLocalRotationX", _spine_Bone_getWorldToLocalRotationX);
    oluacls_func(L, "getWorldToLocalRotationY", _spine_Bone_getWorldToLocalRotationY);
    oluacls_func(L, "getWorldX", _spine_Bone_getWorldX);
    oluacls_func(L, "getWorldY", _spine_Bone_getWorldY);
    oluacls_func(L, "getX", _spine_Bone_getX);
    oluacls_func(L, "getY", _spine_Bone_getY);
    oluacls_func(L, "isYDown", _spine_Bone_isYDown);
    oluacls_func(L, "localToWorldRotation", _spine_Bone_localToWorldRotation);
    oluacls_func(L, "new", _spine_Bone_new);
    oluacls_func(L, "rotateWorld", _spine_Bone_rotateWorld);
    oluacls_func(L, "setA", _spine_Bone_setA);
    oluacls_func(L, "setAScaleX", _spine_Bone_setAScaleX);
    oluacls_func(L, "setAScaleY", _spine_Bone_setAScaleY);
    oluacls_func(L, "setAShearX", _spine_Bone_setAShearX);
    oluacls_func(L, "setAShearY", _spine_Bone_setAShearY);
    oluacls_func(L, "setAX", _spine_Bone_setAX);
    oluacls_func(L, "setAY", _spine_Bone_setAY);
    oluacls_func(L, "setAppliedRotation", _spine_Bone_setAppliedRotation);
    oluacls_func(L, "setB", _spine_Bone_setB);
    oluacls_func(L, "setC", _spine_Bone_setC);
    oluacls_func(L, "setD", _spine_Bone_setD);
    oluacls_func(L, "setRotation", _spine_Bone_setRotation);
    oluacls_func(L, "setScaleX", _spine_Bone_setScaleX);
    oluacls_func(L, "setScaleY", _spine_Bone_setScaleY);
    oluacls_func(L, "setShearX", _spine_Bone_setShearX);
    oluacls_func(L, "setShearY", _spine_Bone_setShearY);
    oluacls_func(L, "setToSetupPose", _spine_Bone_setToSetupPose);
    oluacls_func(L, "setWorldX", _spine_Bone_setWorldX);
    oluacls_func(L, "setWorldY", _spine_Bone_setWorldY);
    oluacls_func(L, "setX", _spine_Bone_setX);
    oluacls_func(L, "setY", _spine_Bone_setY);
    oluacls_func(L, "setYDown", _spine_Bone_setYDown);
    oluacls_func(L, "updateWorldTransform", _spine_Bone_updateWorldTransform);
    oluacls_func(L, "worldToLocalRotation", _spine_Bone_worldToLocalRotation);
    oluacls_prop(L, "a", _spine_Bone_getA, _spine_Bone_setA);
    oluacls_prop(L, "aScaleX", _spine_Bone_getAScaleX, _spine_Bone_setAScaleX);
    oluacls_prop(L, "aScaleY", _spine_Bone_getAScaleY, _spine_Bone_setAScaleY);
    oluacls_prop(L, "aShearX", _spine_Bone_getAShearX, _spine_Bone_setAShearX);
    oluacls_prop(L, "aShearY", _spine_Bone_getAShearY, _spine_Bone_setAShearY);
    oluacls_prop(L, "appliedRotation", _spine_Bone_getAppliedRotation, _spine_Bone_setAppliedRotation);
    oluacls_prop(L, "ax", _spine_Bone_getAX, _spine_Bone_setAX);
    oluacls_prop(L, "ay", _spine_Bone_getAY, _spine_Bone_setAY);
    oluacls_prop(L, "b", _spine_Bone_getB, _spine_Bone_setB);
    oluacls_prop(L, "c", _spine_Bone_getC, _spine_Bone_setC);
    oluacls_prop(L, "children", _spine_Bone_getChildren, nullptr);
    oluacls_prop(L, "d", _spine_Bone_getD, _spine_Bone_setD);
    oluacls_prop(L, "data", _spine_Bone_getData, nullptr);
    oluacls_prop(L, "parent", _spine_Bone_getParent, nullptr);
    oluacls_prop(L, "rotation", _spine_Bone_getRotation, _spine_Bone_setRotation);
    oluacls_prop(L, "scaleX", _spine_Bone_getScaleX, _spine_Bone_setScaleX);
    oluacls_prop(L, "scaleY", _spine_Bone_getScaleY, _spine_Bone_setScaleY);
    oluacls_prop(L, "shearX", _spine_Bone_getShearX, _spine_Bone_setShearX);
    oluacls_prop(L, "shearY", _spine_Bone_getShearY, _spine_Bone_setShearY);
    oluacls_prop(L, "skeleton", _spine_Bone_getSkeleton, nullptr);
    oluacls_prop(L, "worldRotationX", _spine_Bone_getWorldRotationX, nullptr);
    oluacls_prop(L, "worldRotationY", _spine_Bone_getWorldRotationY, nullptr);
    oluacls_prop(L, "worldScaleX", _spine_Bone_getWorldScaleX, nullptr);
    oluacls_prop(L, "worldScaleY", _spine_Bone_getWorldScaleY, nullptr);
    oluacls_prop(L, "worldToLocalRotationX", _spine_Bone_getWorldToLocalRotationX, nullptr);
    oluacls_prop(L, "worldToLocalRotationY", _spine_Bone_getWorldToLocalRotationY, nullptr);
    oluacls_prop(L, "worldX", _spine_Bone_getWorldX, _spine_Bone_setWorldX);
    oluacls_prop(L, "worldY", _spine_Bone_getWorldY, _spine_Bone_setWorldY);
    oluacls_prop(L, "x", _spine_Bone_getX, _spine_Bone_setX);
    oluacls_prop(L, "y", _spine_Bone_getY, _spine_Bone_setY);
    oluacls_prop(L, "yDown", _spine_Bone_isYDown, _spine_Bone_setYDown);

    return 1;
}
OLUA_END_DECLS

static int _spine_Slot_getAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Slot");

    // spine::Attachment *getAttachment()
    spine::Attachment *ret = self->getAttachment();
    int num_ret = olua_push_object(L, ret, "spine.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getAttachmentState(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Slot");

    // int getAttachmentState()
    int ret = self->getAttachmentState();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getBone(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Slot");

    // spine::Bone &getBone()
    spine::Bone &ret = self->getBone();
    int num_ret = olua_push_object(L, &ret, "spine.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Slot");

    // spine::Color &getColor()
    spine::Color &ret = self->getColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getDarkColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Slot");

    // spine::Color &getDarkColor()
    spine::Color &ret = self->getDarkColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getData(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Slot");

    // spine::SlotData &getData()
    spine::SlotData &ret = self->getData();
    int num_ret = olua_push_object(L, &ret, "spine.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getDeform(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Slot");

    // spine::Vector<float> &getDeform()
    spine::Vector<float> &ret = self->getDeform();
    int num_ret = olua_push_vector<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getSequenceIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Slot");

    // int getSequenceIndex()
    int ret = self->getSequenceIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getSkeleton(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Slot");

    // spine::Skeleton &getSkeleton()
    spine::Skeleton &ret = self->getSkeleton();
    int num_ret = olua_push_object(L, &ret, "spine.Skeleton");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_hasDarkColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Slot");

    // bool hasDarkColor()
    bool ret = self->hasDarkColor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *arg1 = nullptr;       /** data */
    spine::Bone *arg2 = nullptr;       /** bone */

    olua_check_object(L, 1, &arg1, "spine.SlotData");
    olua_check_object(L, 2, &arg2, "spine.Bone");

    // Slot(spine::SlotData &data, spine::Bone &bone)
    spine::Slot *ret = new spine::Slot(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "spine.Slot");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_setAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;
    spine::Attachment *arg1 = nullptr;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Slot");
    olua_check_object(L, 2, &arg1, "spine.Attachment");

    // void setAttachment(spine::Attachment *inValue)
    self->setAttachment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Slot_setAttachmentState(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;
    int arg1 = 0;       /** state */

    olua_to_object(L, 1, &self, "spine.Slot");
    olua_check_integer(L, 2, &arg1);

    // void setAttachmentState(int state)
    self->setAttachmentState(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Slot_setSequenceIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;
    int arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "spine.Slot");
    olua_check_integer(L, 2, &arg1);

    // void setSequenceIndex(int index)
    self->setSequenceIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Slot_setToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Slot");

    // void setToSetupPose()
    self->setToSetupPose();

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Slot(lua_State *L)
{
    oluacls_class<spine::Slot, spine::SpineObject>(L, "spine.Slot");
    oluacls_func(L, "getAttachment", _spine_Slot_getAttachment);
    oluacls_func(L, "getAttachmentState", _spine_Slot_getAttachmentState);
    oluacls_func(L, "getBone", _spine_Slot_getBone);
    oluacls_func(L, "getColor", _spine_Slot_getColor);
    oluacls_func(L, "getDarkColor", _spine_Slot_getDarkColor);
    oluacls_func(L, "getData", _spine_Slot_getData);
    oluacls_func(L, "getDeform", _spine_Slot_getDeform);
    oluacls_func(L, "getSequenceIndex", _spine_Slot_getSequenceIndex);
    oluacls_func(L, "getSkeleton", _spine_Slot_getSkeleton);
    oluacls_func(L, "hasDarkColor", _spine_Slot_hasDarkColor);
    oluacls_func(L, "new", _spine_Slot_new);
    oluacls_func(L, "setAttachment", _spine_Slot_setAttachment);
    oluacls_func(L, "setAttachmentState", _spine_Slot_setAttachmentState);
    oluacls_func(L, "setSequenceIndex", _spine_Slot_setSequenceIndex);
    oluacls_func(L, "setToSetupPose", _spine_Slot_setToSetupPose);
    oluacls_prop(L, "attachment", _spine_Slot_getAttachment, _spine_Slot_setAttachment);
    oluacls_prop(L, "attachmentState", _spine_Slot_getAttachmentState, _spine_Slot_setAttachmentState);
    oluacls_prop(L, "bone", _spine_Slot_getBone, nullptr);
    oluacls_prop(L, "color", _spine_Slot_getColor, nullptr);
    oluacls_prop(L, "darkColor", _spine_Slot_getDarkColor, nullptr);
    oluacls_prop(L, "data", _spine_Slot_getData, nullptr);
    oluacls_prop(L, "deform", _spine_Slot_getDeform, nullptr);
    oluacls_prop(L, "sequenceIndex", _spine_Slot_getSequenceIndex, _spine_Slot_setSequenceIndex);
    oluacls_prop(L, "skeleton", _spine_Slot_getSkeleton, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _spine_Attachment_copy(lua_State *L)
{
    olua_startinvoke(L);

    spine::Attachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Attachment");

    // spine::Attachment *copy()
    spine::Attachment *ret = self->copy();
    int num_ret = olua_push_object(L, ret, "spine.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Attachment_dereference(lua_State *L)
{
    olua_startinvoke(L);

    spine::Attachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Attachment");

    // void dereference()
    self->dereference();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Attachment_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::Attachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Attachment");

    // const spine::String &getName()
    const spine::String &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Attachment_getRefCount(lua_State *L)
{
    olua_startinvoke(L);

    spine::Attachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Attachment");

    // int getRefCount()
    int ret = self->getRefCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Attachment_reference(lua_State *L)
{
    olua_startinvoke(L);

    spine::Attachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Attachment");

    // void reference()
    self->reference();

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Attachment(lua_State *L)
{
    oluacls_class<spine::Attachment, spine::SpineObject>(L, "spine.Attachment");
    oluacls_func(L, "copy", _spine_Attachment_copy);
    oluacls_func(L, "dereference", _spine_Attachment_dereference);
    oluacls_func(L, "getName", _spine_Attachment_getName);
    oluacls_func(L, "getRefCount", _spine_Attachment_getRefCount);
    oluacls_func(L, "reference", _spine_Attachment_reference);
    oluacls_prop(L, "name", _spine_Attachment_getName, nullptr);
    oluacls_prop(L, "refCount", _spine_Attachment_getRefCount, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _spine_VertexAttachment_computeWorldVertices$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** slot */
    float *arg2 = nullptr;       /** worldVertices */

    olua_to_object(L, 1, &self, "spine.VertexAttachment");
    olua_check_object(L, 2, &arg1, "spine.Slot");
    olua_check_array(L, 3, &arg2, "olua.float");

    // void computeWorldVertices(spine::Slot &slot, float *worldVertices)
    self->computeWorldVertices(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_VertexAttachment_computeWorldVertices$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** slot */
    spine::Vector<float> arg2;       /** worldVertices */

    olua_to_object(L, 1, &self, "spine.VertexAttachment");
    olua_check_object(L, 2, &arg1, "spine.Slot");
    olua_check_vector<float>(L, 3, arg2, [L](float *arg1) {
        olua_check_number(L, -1, arg1);
    });

    // void computeWorldVertices(spine::Slot &slot, spine::Vector<float> &worldVertices)
    self->computeWorldVertices(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_VertexAttachment_computeWorldVertices$3(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** slot */
    size_t arg2 = 0;       /** start */
    size_t arg3 = 0;       /** count */
    float *arg4 = nullptr;       /** worldVertices */
    size_t arg5 = 0;       /** offset */
    size_t arg6 = 0;       /** stride */

    olua_to_object(L, 1, &self, "spine.VertexAttachment");
    olua_check_object(L, 2, &arg1, "spine.Slot");
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_array(L, 5, &arg4, "olua.float");
    olua_check_integer(L, 6, &arg5);
    olua_check_integer(L, 7, &arg6);

    // void computeWorldVertices(spine::Slot &slot, size_t start, size_t count, float *worldVertices, size_t offset, @optional size_t stride)
    self->computeWorldVertices(*arg1, arg2, arg3, arg4, arg5, arg6);

    olua_endinvoke(L);

    return 0;
}

static int _spine_VertexAttachment_computeWorldVertices$4(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** slot */
    size_t arg2 = 0;       /** start */
    size_t arg3 = 0;       /** count */
    spine::Vector<float> arg4;       /** worldVertices */
    size_t arg5 = 0;       /** offset */
    size_t arg6 = 0;       /** stride */

    olua_to_object(L, 1, &self, "spine.VertexAttachment");
    olua_check_object(L, 2, &arg1, "spine.Slot");
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_vector<float>(L, 5, arg4, [L](float *arg1) {
        olua_check_number(L, -1, arg1);
    });
    olua_check_integer(L, 6, &arg5);
    olua_check_integer(L, 7, &arg6);

    // void computeWorldVertices(spine::Slot &slot, size_t start, size_t count, spine::Vector<float> &worldVertices, size_t offset, @optional size_t stride)
    self->computeWorldVertices(*arg1, arg2, arg3, arg4, arg5, arg6);

    olua_endinvoke(L);

    return 0;
}

static int _spine_VertexAttachment_computeWorldVertices$5(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** slot */
    size_t arg2 = 0;       /** start */
    size_t arg3 = 0;       /** count */
    float *arg4 = nullptr;       /** worldVertices */
    size_t arg5 = 0;       /** offset */

    olua_to_object(L, 1, &self, "spine.VertexAttachment");
    olua_check_object(L, 2, &arg1, "spine.Slot");
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_array(L, 5, &arg4, "olua.float");
    olua_check_integer(L, 6, &arg5);

    // void computeWorldVertices(spine::Slot &slot, size_t start, size_t count, float *worldVertices, size_t offset, @optional size_t stride)
    self->computeWorldVertices(*arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _spine_VertexAttachment_computeWorldVertices$6(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** slot */
    size_t arg2 = 0;       /** start */
    size_t arg3 = 0;       /** count */
    spine::Vector<float> arg4;       /** worldVertices */
    size_t arg5 = 0;       /** offset */

    olua_to_object(L, 1, &self, "spine.VertexAttachment");
    olua_check_object(L, 2, &arg1, "spine.Slot");
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);
    olua_check_vector<float>(L, 5, arg4, [L](float *arg1) {
        olua_check_number(L, -1, arg1);
    });
    olua_check_integer(L, 6, &arg5);

    // void computeWorldVertices(spine::Slot &slot, size_t start, size_t count, spine::Vector<float> &worldVertices, size_t offset, @optional size_t stride)
    self->computeWorldVertices(*arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _spine_VertexAttachment_computeWorldVertices(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        if ((olua_is_object(L, 2, "spine.Slot")) && (olua_is_array(L, 3, "olua.float"))) {
            // void computeWorldVertices(spine::Slot &slot, float *worldVertices)
            return _spine_VertexAttachment_computeWorldVertices$1(L);
        }

        // if ((olua_is_object(L, 2, "spine.Slot")) && (olua_is_vector(L, 3))) {
            // void computeWorldVertices(spine::Slot &slot, spine::Vector<float> &worldVertices)
            return _spine_VertexAttachment_computeWorldVertices$2(L);
        // }
    }

    if (num_args == 5) {
        if ((olua_is_object(L, 2, "spine.Slot")) && (olua_is_integer(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_array(L, 5, "olua.float")) && (olua_is_integer(L, 6))) {
            // void computeWorldVertices(spine::Slot &slot, size_t start, size_t count, float *worldVertices, size_t offset, @optional size_t stride)
            return _spine_VertexAttachment_computeWorldVertices$5(L);
        }

        // if ((olua_is_object(L, 2, "spine.Slot")) && (olua_is_integer(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_vector(L, 5)) && (olua_is_integer(L, 6))) {
            // void computeWorldVertices(spine::Slot &slot, size_t start, size_t count, spine::Vector<float> &worldVertices, size_t offset, @optional size_t stride)
            return _spine_VertexAttachment_computeWorldVertices$6(L);
        // }
    }

    if (num_args == 6) {
        if ((olua_is_object(L, 2, "spine.Slot")) && (olua_is_integer(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_array(L, 5, "olua.float")) && (olua_is_integer(L, 6)) && (olua_is_integer(L, 7))) {
            // void computeWorldVertices(spine::Slot &slot, size_t start, size_t count, float *worldVertices, size_t offset, @optional size_t stride)
            return _spine_VertexAttachment_computeWorldVertices$3(L);
        }

        // if ((olua_is_object(L, 2, "spine.Slot")) && (olua_is_integer(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_vector(L, 5)) && (olua_is_integer(L, 6)) && (olua_is_integer(L, 7))) {
            // void computeWorldVertices(spine::Slot &slot, size_t start, size_t count, spine::Vector<float> &worldVertices, size_t offset, @optional size_t stride)
            return _spine_VertexAttachment_computeWorldVertices$4(L);
        // }
    }

    luaL_error(L, "method 'spine::VertexAttachment::computeWorldVertices' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_VertexAttachment_copyTo(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    spine::VertexAttachment *arg1 = nullptr;       /** other */

    olua_to_object(L, 1, &self, "spine.VertexAttachment");
    olua_check_object(L, 2, &arg1, "spine.VertexAttachment");

    // void copyTo(spine::VertexAttachment *other)
    self->copyTo(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_VertexAttachment_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.VertexAttachment");

    // spine::Vector<size_t> &getBones()
    spine::Vector<size_t> &ret = self->getBones();
    int num_ret = olua_push_vector<size_t>(L, ret, [L](size_t &arg1) {
        olua_push_integer(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_VertexAttachment_getId(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.VertexAttachment");

    // int getId()
    int ret = self->getId();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_VertexAttachment_getTimelineAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.VertexAttachment");

    // spine::Attachment *getTimelineAttachment()
    spine::Attachment *ret = self->getTimelineAttachment();
    int num_ret = olua_push_object(L, ret, "spine.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_VertexAttachment_getVertices(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.VertexAttachment");

    // spine::Vector<float> &getVertices()
    spine::Vector<float> &ret = self->getVertices();
    int num_ret = olua_push_vector<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_VertexAttachment_getWorldVerticesLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.VertexAttachment");

    // size_t getWorldVerticesLength()
    size_t ret = self->getWorldVerticesLength();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_VertexAttachment_setTimelineAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    spine::Attachment *arg1 = nullptr;       /** attachment */

    olua_to_object(L, 1, &self, "spine.VertexAttachment");
    olua_check_object(L, 2, &arg1, "spine.Attachment");

    // void setTimelineAttachment(spine::Attachment *attachment)
    self->setTimelineAttachment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_VertexAttachment_setWorldVerticesLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    size_t arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.VertexAttachment");
    olua_check_integer(L, 2, &arg1);

    // void setWorldVerticesLength(size_t inValue)
    self->setWorldVerticesLength(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_VertexAttachment(lua_State *L)
{
    oluacls_class<spine::VertexAttachment, spine::Attachment>(L, "spine.VertexAttachment");
    oluacls_func(L, "computeWorldVertices", _spine_VertexAttachment_computeWorldVertices);
    oluacls_func(L, "copyTo", _spine_VertexAttachment_copyTo);
    oluacls_func(L, "getBones", _spine_VertexAttachment_getBones);
    oluacls_func(L, "getId", _spine_VertexAttachment_getId);
    oluacls_func(L, "getTimelineAttachment", _spine_VertexAttachment_getTimelineAttachment);
    oluacls_func(L, "getVertices", _spine_VertexAttachment_getVertices);
    oluacls_func(L, "getWorldVerticesLength", _spine_VertexAttachment_getWorldVerticesLength);
    oluacls_func(L, "setTimelineAttachment", _spine_VertexAttachment_setTimelineAttachment);
    oluacls_func(L, "setWorldVerticesLength", _spine_VertexAttachment_setWorldVerticesLength);
    oluacls_prop(L, "bones", _spine_VertexAttachment_getBones, nullptr);
    oluacls_prop(L, "id", _spine_VertexAttachment_getId, nullptr);
    oluacls_prop(L, "timelineAttachment", _spine_VertexAttachment_getTimelineAttachment, _spine_VertexAttachment_setTimelineAttachment);
    oluacls_prop(L, "vertices", _spine_VertexAttachment_getVertices, nullptr);
    oluacls_prop(L, "worldVerticesLength", _spine_VertexAttachment_getWorldVerticesLength, _spine_VertexAttachment_setWorldVerticesLength);

    return 1;
}
OLUA_END_DECLS

static int _spine_ClippingAttachment_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::ClippingAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.ClippingAttachment");

    // spine::Color &getColor()
    spine::Color &ret = self->getColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ClippingAttachment_getEndSlot(lua_State *L)
{
    olua_startinvoke(L);

    spine::ClippingAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.ClippingAttachment");

    // spine::SlotData *getEndSlot()
    spine::SlotData *ret = self->getEndSlot();
    int num_ret = olua_push_object(L, ret, "spine.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ClippingAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // ClippingAttachment(const spine::String &name)
    spine::ClippingAttachment *ret = new spine::ClippingAttachment(arg1);
    int num_ret = olua_push_object(L, ret, "spine.ClippingAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ClippingAttachment_setEndSlot(lua_State *L)
{
    olua_startinvoke(L);

    spine::ClippingAttachment *self = nullptr;
    spine::SlotData *arg1 = nullptr;       /** inValue */

    olua_to_object(L, 1, &self, "spine.ClippingAttachment");
    olua_check_object(L, 2, &arg1, "spine.SlotData");

    // void setEndSlot(spine::SlotData *inValue)
    self->setEndSlot(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_ClippingAttachment(lua_State *L)
{
    oluacls_class<spine::ClippingAttachment, spine::VertexAttachment>(L, "spine.ClippingAttachment");
    oluacls_func(L, "getColor", _spine_ClippingAttachment_getColor);
    oluacls_func(L, "getEndSlot", _spine_ClippingAttachment_getEndSlot);
    oluacls_func(L, "new", _spine_ClippingAttachment_new);
    oluacls_func(L, "setEndSlot", _spine_ClippingAttachment_setEndSlot);
    oluacls_prop(L, "color", _spine_ClippingAttachment_getColor, nullptr);
    oluacls_prop(L, "endSlot", _spine_ClippingAttachment_getEndSlot, _spine_ClippingAttachment_setEndSlot);

    return 1;
}
OLUA_END_DECLS

static int _spine_BoundingBoxAttachment_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoundingBoxAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.BoundingBoxAttachment");

    // spine::Color &getColor()
    spine::Color &ret = self->getColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoundingBoxAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // BoundingBoxAttachment(const spine::String &name)
    spine::BoundingBoxAttachment *ret = new spine::BoundingBoxAttachment(arg1);
    int num_ret = olua_push_object(L, ret, "spine.BoundingBoxAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_BoundingBoxAttachment(lua_State *L)
{
    oluacls_class<spine::BoundingBoxAttachment, spine::VertexAttachment>(L, "spine.BoundingBoxAttachment");
    oluacls_func(L, "getColor", _spine_BoundingBoxAttachment_getColor);
    oluacls_func(L, "new", _spine_BoundingBoxAttachment_new);
    oluacls_prop(L, "color", _spine_BoundingBoxAttachment_getColor, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _spine_MeshAttachment_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // spine::Color &getColor()
    spine::Color &ret = self->getColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getEdges(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // spine::Vector<unsigned short> &getEdges()
    spine::Vector<unsigned short> &ret = self->getEdges();
    int num_ret = olua_push_vector<unsigned short>(L, ret, [L](unsigned short &arg1) {
        olua_push_integer(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // float getHeight()
    float ret = self->getHeight();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getHullLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // int getHullLength()
    int ret = self->getHullLength();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getParentMesh(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // spine::MeshAttachment *getParentMesh()
    spine::MeshAttachment *ret = self->getParentMesh();
    int num_ret = olua_push_object(L, ret, "spine.MeshAttachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // const spine::String &getPath()
    const spine::String &ret = self->getPath();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegion(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // spine::TextureRegion *getRegion()
    spine::TextureRegion *ret = self->getRegion();
    int num_ret = olua_push_object(L, ret, "spine.TextureRegion");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionUVs(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // spine::Vector<float> &getRegionUVs()
    spine::Vector<float> &ret = self->getRegionUVs();
    int num_ret = olua_push_vector<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getSequence(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // spine::Sequence *getSequence()
    spine::Sequence *ret = self->getSequence();
    int num_ret = olua_push_object(L, ret, "spine.Sequence");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getTriangles(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // spine::Vector<unsigned short> &getTriangles()
    spine::Vector<unsigned short> &ret = self->getTriangles();
    int num_ret = olua_push_vector<unsigned short>(L, ret, [L](unsigned short &arg1) {
        olua_push_integer(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getUVs(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // spine::Vector<float> &getUVs()
    spine::Vector<float> &ret = self->getUVs();
    int num_ret = olua_push_vector<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // float getWidth()
    float ret = self->getWidth();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // MeshAttachment(const spine::String &name)
    spine::MeshAttachment *ret = new spine::MeshAttachment(arg1);
    int num_ret = olua_push_object(L, ret, "spine.MeshAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_newLinkedMesh(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // spine::MeshAttachment *newLinkedMesh()
    spine::MeshAttachment *ret = self->newLinkedMesh();
    int num_ret = olua_push_object(L, ret, "spine.MeshAttachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_setHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setHeight(float inValue)
    self->setHeight(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setHullLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    int arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.MeshAttachment");
    olua_check_integer(L, 2, &arg1);

    // void setHullLength(int inValue)
    self->setHullLength(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setParentMesh(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    spine::MeshAttachment *arg1 = nullptr;       /** inValue */

    olua_to_object(L, 1, &self, "spine.MeshAttachment");
    olua_check_object(L, 2, &arg1, "spine.MeshAttachment");

    // void setParentMesh(spine::MeshAttachment *inValue)
    self->setParentMesh(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_object(L, 1, &self, "spine.MeshAttachment");
    olua_check_string(L, 2, &arg1);

    // void setPath(const spine::String &inValue)
    self->setPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegion(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    spine::TextureRegion *arg1 = nullptr;       /** region */

    olua_to_object(L, 1, &self, "spine.MeshAttachment");
    olua_check_object(L, 2, &arg1, "spine.TextureRegion");

    // void setRegion(spine::TextureRegion *region)
    self->setRegion(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setSequence(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    spine::Sequence *arg1 = nullptr;       /** sequence */

    olua_to_object(L, 1, &self, "spine.MeshAttachment");
    olua_check_object(L, 2, &arg1, "spine.Sequence");

    // void setSequence(spine::Sequence *sequence)
    self->setSequence(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setWidth(float inValue)
    self->setWidth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_updateRegion(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.MeshAttachment");

    // void updateRegion()
    self->updateRegion();

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_MeshAttachment(lua_State *L)
{
    oluacls_class<spine::MeshAttachment, spine::VertexAttachment>(L, "spine.MeshAttachment");
    oluacls_func(L, "getColor", _spine_MeshAttachment_getColor);
    oluacls_func(L, "getEdges", _spine_MeshAttachment_getEdges);
    oluacls_func(L, "getHeight", _spine_MeshAttachment_getHeight);
    oluacls_func(L, "getHullLength", _spine_MeshAttachment_getHullLength);
    oluacls_func(L, "getParentMesh", _spine_MeshAttachment_getParentMesh);
    oluacls_func(L, "getPath", _spine_MeshAttachment_getPath);
    oluacls_func(L, "getRegion", _spine_MeshAttachment_getRegion);
    oluacls_func(L, "getRegionUVs", _spine_MeshAttachment_getRegionUVs);
    oluacls_func(L, "getSequence", _spine_MeshAttachment_getSequence);
    oluacls_func(L, "getTriangles", _spine_MeshAttachment_getTriangles);
    oluacls_func(L, "getUVs", _spine_MeshAttachment_getUVs);
    oluacls_func(L, "getWidth", _spine_MeshAttachment_getWidth);
    oluacls_func(L, "new", _spine_MeshAttachment_new);
    oluacls_func(L, "newLinkedMesh", _spine_MeshAttachment_newLinkedMesh);
    oluacls_func(L, "setHeight", _spine_MeshAttachment_setHeight);
    oluacls_func(L, "setHullLength", _spine_MeshAttachment_setHullLength);
    oluacls_func(L, "setParentMesh", _spine_MeshAttachment_setParentMesh);
    oluacls_func(L, "setPath", _spine_MeshAttachment_setPath);
    oluacls_func(L, "setRegion", _spine_MeshAttachment_setRegion);
    oluacls_func(L, "setSequence", _spine_MeshAttachment_setSequence);
    oluacls_func(L, "setWidth", _spine_MeshAttachment_setWidth);
    oluacls_func(L, "updateRegion", _spine_MeshAttachment_updateRegion);
    oluacls_prop(L, "color", _spine_MeshAttachment_getColor, nullptr);
    oluacls_prop(L, "edges", _spine_MeshAttachment_getEdges, nullptr);
    oluacls_prop(L, "height", _spine_MeshAttachment_getHeight, _spine_MeshAttachment_setHeight);
    oluacls_prop(L, "hullLength", _spine_MeshAttachment_getHullLength, _spine_MeshAttachment_setHullLength);
    oluacls_prop(L, "parentMesh", _spine_MeshAttachment_getParentMesh, _spine_MeshAttachment_setParentMesh);
    oluacls_prop(L, "path", _spine_MeshAttachment_getPath, _spine_MeshAttachment_setPath);
    oluacls_prop(L, "region", _spine_MeshAttachment_getRegion, _spine_MeshAttachment_setRegion);
    oluacls_prop(L, "regionUVs", _spine_MeshAttachment_getRegionUVs, nullptr);
    oluacls_prop(L, "sequence", _spine_MeshAttachment_getSequence, _spine_MeshAttachment_setSequence);
    oluacls_prop(L, "triangles", _spine_MeshAttachment_getTriangles, nullptr);
    oluacls_prop(L, "uvs", _spine_MeshAttachment_getUVs, nullptr);
    oluacls_prop(L, "width", _spine_MeshAttachment_getWidth, _spine_MeshAttachment_setWidth);

    return 1;
}
OLUA_END_DECLS

static int _spine_PathAttachment_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathAttachment");

    // spine::Color &getColor()
    spine::Color &ret = self->getColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathAttachment_getLengths(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathAttachment");

    // spine::Vector<float> &getLengths()
    spine::Vector<float> &ret = self->getLengths();
    int num_ret = olua_push_vector<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathAttachment_isClosed(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathAttachment");

    // bool isClosed()
    bool ret = self->isClosed();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathAttachment_isConstantSpeed(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathAttachment");

    // bool isConstantSpeed()
    bool ret = self->isConstantSpeed();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // PathAttachment(const spine::String &name)
    spine::PathAttachment *ret = new spine::PathAttachment(arg1);
    int num_ret = olua_push_object(L, ret, "spine.PathAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathAttachment_setClosed(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathAttachment *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathAttachment");
    olua_check_bool(L, 2, &arg1);

    // void setClosed(bool inValue)
    self->setClosed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathAttachment_setConstantSpeed(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathAttachment *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathAttachment");
    olua_check_bool(L, 2, &arg1);

    // void setConstantSpeed(bool inValue)
    self->setConstantSpeed(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_PathAttachment(lua_State *L)
{
    oluacls_class<spine::PathAttachment, spine::VertexAttachment>(L, "spine.PathAttachment");
    oluacls_func(L, "getColor", _spine_PathAttachment_getColor);
    oluacls_func(L, "getLengths", _spine_PathAttachment_getLengths);
    oluacls_func(L, "isClosed", _spine_PathAttachment_isClosed);
    oluacls_func(L, "isConstantSpeed", _spine_PathAttachment_isConstantSpeed);
    oluacls_func(L, "new", _spine_PathAttachment_new);
    oluacls_func(L, "setClosed", _spine_PathAttachment_setClosed);
    oluacls_func(L, "setConstantSpeed", _spine_PathAttachment_setConstantSpeed);
    oluacls_prop(L, "closed", _spine_PathAttachment_isClosed, _spine_PathAttachment_setClosed);
    oluacls_prop(L, "color", _spine_PathAttachment_getColor, nullptr);
    oluacls_prop(L, "constantSpeed", _spine_PathAttachment_isConstantSpeed, _spine_PathAttachment_setConstantSpeed);
    oluacls_prop(L, "lengths", _spine_PathAttachment_getLengths, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _spine_PathConstraint_apply(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraint");

    // void apply()
    self->apply();

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraint_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraint");

    // spine::Vector<spine::Bone *> &getBones()
    spine::Vector<spine::Bone *> &ret = self->getBones();
    int num_ret = olua_push_vector<spine::Bone *>(L, ret, [L](spine::Bone *arg1) {
        olua_push_object(L, arg1, "spine.Bone");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getData(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraint");

    // spine::PathConstraintData &getData()
    spine::PathConstraintData &ret = self->getData();
    int num_ret = olua_push_object(L, &ret, "spine.PathConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getMixRotate(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraint");

    // float getMixRotate()
    float ret = self->getMixRotate();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getMixX(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraint");

    // float getMixX()
    float ret = self->getMixX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getMixY(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraint");

    // float getMixY()
    float ret = self->getMixY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraint");

    // int getOrder()
    int ret = self->getOrder();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraint");

    // float getPosition()
    float ret = self->getPosition();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getSpacing(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraint");

    // float getSpacing()
    float ret = self->getSpacing();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PathConstraint");

    // spine::Slot *getTarget()
    spine::Slot *ret = self->getTarget();
    int num_ret = olua_push_object(L, ret, "spine.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *arg1 = nullptr;       /** data */
    spine::Skeleton *arg2 = nullptr;       /** skeleton */

    olua_check_object(L, 1, &arg1, "spine.PathConstraintData");
    olua_check_object(L, 2, &arg2, "spine.Skeleton");

    // PathConstraint(spine::PathConstraintData &data, spine::Skeleton &skeleton)
    spine::PathConstraint *ret = new spine::PathConstraint(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "spine.PathConstraint");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_setMixRotate(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraint");
    olua_check_number(L, 2, &arg1);

    // void setMixRotate(float inValue)
    self->setMixRotate(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraint_setMixX(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraint");
    olua_check_number(L, 2, &arg1);

    // void setMixX(float inValue)
    self->setMixX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraint_setMixY(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraint");
    olua_check_number(L, 2, &arg1);

    // void setMixY(float inValue)
    self->setMixY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraint_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraint");
    olua_check_number(L, 2, &arg1);

    // void setPosition(float inValue)
    self->setPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraint_setSpacing(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraint");
    olua_check_number(L, 2, &arg1);

    // void setSpacing(float inValue)
    self->setSpacing(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraint_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PathConstraint");
    olua_check_object(L, 2, &arg1, "spine.Slot");

    // void setTarget(spine::Slot *inValue)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_PathConstraint(lua_State *L)
{
    oluacls_class<spine::PathConstraint, spine::Updatable>(L, "spine.PathConstraint");
    oluacls_func(L, "apply", _spine_PathConstraint_apply);
    oluacls_func(L, "getBones", _spine_PathConstraint_getBones);
    oluacls_func(L, "getData", _spine_PathConstraint_getData);
    oluacls_func(L, "getMixRotate", _spine_PathConstraint_getMixRotate);
    oluacls_func(L, "getMixX", _spine_PathConstraint_getMixX);
    oluacls_func(L, "getMixY", _spine_PathConstraint_getMixY);
    oluacls_func(L, "getOrder", _spine_PathConstraint_getOrder);
    oluacls_func(L, "getPosition", _spine_PathConstraint_getPosition);
    oluacls_func(L, "getSpacing", _spine_PathConstraint_getSpacing);
    oluacls_func(L, "getTarget", _spine_PathConstraint_getTarget);
    oluacls_func(L, "new", _spine_PathConstraint_new);
    oluacls_func(L, "setMixRotate", _spine_PathConstraint_setMixRotate);
    oluacls_func(L, "setMixX", _spine_PathConstraint_setMixX);
    oluacls_func(L, "setMixY", _spine_PathConstraint_setMixY);
    oluacls_func(L, "setPosition", _spine_PathConstraint_setPosition);
    oluacls_func(L, "setSpacing", _spine_PathConstraint_setSpacing);
    oluacls_func(L, "setTarget", _spine_PathConstraint_setTarget);
    oluacls_prop(L, "bones", _spine_PathConstraint_getBones, nullptr);
    oluacls_prop(L, "data", _spine_PathConstraint_getData, nullptr);
    oluacls_prop(L, "mixRotate", _spine_PathConstraint_getMixRotate, _spine_PathConstraint_setMixRotate);
    oluacls_prop(L, "mixX", _spine_PathConstraint_getMixX, _spine_PathConstraint_setMixX);
    oluacls_prop(L, "mixY", _spine_PathConstraint_getMixY, _spine_PathConstraint_setMixY);
    oluacls_prop(L, "order", _spine_PathConstraint_getOrder, nullptr);
    oluacls_prop(L, "position", _spine_PathConstraint_getPosition, _spine_PathConstraint_setPosition);
    oluacls_prop(L, "spacing", _spine_PathConstraint_getSpacing, _spine_PathConstraint_setSpacing);
    oluacls_prop(L, "target", _spine_PathConstraint_getTarget, _spine_PathConstraint_setTarget);

    return 1;
}
OLUA_END_DECLS

static int _spine_PointAttachment_computeWorldPosition(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;
    spine::Bone *arg1 = nullptr;       /** bone */
    float *arg2 = nullptr;       /** ox */
    float *arg3 = nullptr;       /** oy */

    olua_to_object(L, 1, &self, "spine.PointAttachment");
    olua_check_object(L, 2, &arg1, "spine.Bone");
    olua_check_array(L, 3, &arg2, "olua.float");
    olua_check_array(L, 4, &arg3, "olua.float");

    // void computeWorldPosition(spine::Bone &bone, float &ox, float &oy)
    self->computeWorldPosition(*arg1, *arg2, *arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PointAttachment_computeWorldRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;
    spine::Bone *arg1 = nullptr;       /** bone */

    olua_to_object(L, 1, &self, "spine.PointAttachment");
    olua_check_object(L, 2, &arg1, "spine.Bone");

    // float computeWorldRotation(spine::Bone &bone)
    float ret = self->computeWorldRotation(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PointAttachment_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PointAttachment");

    // spine::Color &getColor()
    spine::Color &ret = self->getColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PointAttachment_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PointAttachment");

    // float getRotation()
    float ret = self->getRotation();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PointAttachment_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PointAttachment");

    // float getX()
    float ret = self->getX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PointAttachment_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.PointAttachment");

    // float getY()
    float ret = self->getY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PointAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // PointAttachment(const spine::String &name)
    spine::PointAttachment *ret = new spine::PointAttachment(arg1);
    int num_ret = olua_push_object(L, ret, "spine.PointAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PointAttachment_setRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PointAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRotation(float inValue)
    self->setRotation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PointAttachment_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PointAttachment");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PointAttachment_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.PointAttachment");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_PointAttachment(lua_State *L)
{
    oluacls_class<spine::PointAttachment, spine::Attachment>(L, "spine.PointAttachment");
    oluacls_func(L, "computeWorldPosition", _spine_PointAttachment_computeWorldPosition);
    oluacls_func(L, "computeWorldRotation", _spine_PointAttachment_computeWorldRotation);
    oluacls_func(L, "getColor", _spine_PointAttachment_getColor);
    oluacls_func(L, "getRotation", _spine_PointAttachment_getRotation);
    oluacls_func(L, "getX", _spine_PointAttachment_getX);
    oluacls_func(L, "getY", _spine_PointAttachment_getY);
    oluacls_func(L, "new", _spine_PointAttachment_new);
    oluacls_func(L, "setRotation", _spine_PointAttachment_setRotation);
    oluacls_func(L, "setX", _spine_PointAttachment_setX);
    oluacls_func(L, "setY", _spine_PointAttachment_setY);
    oluacls_prop(L, "color", _spine_PointAttachment_getColor, nullptr);
    oluacls_prop(L, "rotation", _spine_PointAttachment_getRotation, _spine_PointAttachment_setRotation);
    oluacls_prop(L, "x", _spine_PointAttachment_getX, _spine_PointAttachment_setX);
    oluacls_prop(L, "y", _spine_PointAttachment_getY, _spine_PointAttachment_setY);

    return 1;
}
OLUA_END_DECLS

static int _spine_RegionAttachment_computeWorldVertices$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** slot */
    float *arg2 = nullptr;       /** worldVertices */
    size_t arg3 = 0;       /** offset */
    size_t arg4 = 0;       /** stride */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_object(L, 2, &arg1, "spine.Slot");
    olua_check_array(L, 3, &arg2, "olua.float");
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);

    // void computeWorldVertices(spine::Slot &slot, float *worldVertices, size_t offset, @optional size_t stride)
    self->computeWorldVertices(*arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_computeWorldVertices$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** slot */
    spine::Vector<float> arg2;       /** worldVertices */
    size_t arg3 = 0;       /** offset */
    size_t arg4 = 0;       /** stride */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_object(L, 2, &arg1, "spine.Slot");
    olua_check_vector<float>(L, 3, arg2, [L](float *arg1) {
        olua_check_number(L, -1, arg1);
    });
    olua_check_integer(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);

    // void computeWorldVertices(spine::Slot &slot, spine::Vector<float> &worldVertices, size_t offset, @optional size_t stride)
    self->computeWorldVertices(*arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_computeWorldVertices$3(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** slot */
    float *arg2 = nullptr;       /** worldVertices */
    size_t arg3 = 0;       /** offset */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_object(L, 2, &arg1, "spine.Slot");
    olua_check_array(L, 3, &arg2, "olua.float");
    olua_check_integer(L, 4, &arg3);

    // void computeWorldVertices(spine::Slot &slot, float *worldVertices, size_t offset, @optional size_t stride)
    self->computeWorldVertices(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_computeWorldVertices$4(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** slot */
    spine::Vector<float> arg2;       /** worldVertices */
    size_t arg3 = 0;       /** offset */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_object(L, 2, &arg1, "spine.Slot");
    olua_check_vector<float>(L, 3, arg2, [L](float *arg1) {
        olua_check_number(L, -1, arg1);
    });
    olua_check_integer(L, 4, &arg3);

    // void computeWorldVertices(spine::Slot &slot, spine::Vector<float> &worldVertices, size_t offset, @optional size_t stride)
    self->computeWorldVertices(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_computeWorldVertices(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        if ((olua_is_object(L, 2, "spine.Slot")) && (olua_is_array(L, 3, "olua.float")) && (olua_is_integer(L, 4))) {
            // void computeWorldVertices(spine::Slot &slot, float *worldVertices, size_t offset, @optional size_t stride)
            return _spine_RegionAttachment_computeWorldVertices$3(L);
        }

        // if ((olua_is_object(L, 2, "spine.Slot")) && (olua_is_vector(L, 3)) && (olua_is_integer(L, 4))) {
            // void computeWorldVertices(spine::Slot &slot, spine::Vector<float> &worldVertices, size_t offset, @optional size_t stride)
            return _spine_RegionAttachment_computeWorldVertices$4(L);
        // }
    }

    if (num_args == 4) {
        if ((olua_is_object(L, 2, "spine.Slot")) && (olua_is_array(L, 3, "olua.float")) && (olua_is_integer(L, 4)) && (olua_is_integer(L, 5))) {
            // void computeWorldVertices(spine::Slot &slot, float *worldVertices, size_t offset, @optional size_t stride)
            return _spine_RegionAttachment_computeWorldVertices$1(L);
        }

        // if ((olua_is_object(L, 2, "spine.Slot")) && (olua_is_vector(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_integer(L, 5))) {
            // void computeWorldVertices(spine::Slot &slot, spine::Vector<float> &worldVertices, size_t offset, @optional size_t stride)
            return _spine_RegionAttachment_computeWorldVertices$2(L);
        // }
    }

    luaL_error(L, "method 'spine::RegionAttachment::computeWorldVertices' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_RegionAttachment_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // spine::Color &getColor()
    spine::Color &ret = self->getColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // float getHeight()
    float ret = self->getHeight();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getOffset(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // spine::Vector<float> &getOffset()
    spine::Vector<float> &ret = self->getOffset();
    int num_ret = olua_push_vector<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // const spine::String &getPath()
    const spine::String &ret = self->getPath();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getRegion(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // spine::TextureRegion *getRegion()
    spine::TextureRegion *ret = self->getRegion();
    int num_ret = olua_push_object(L, ret, "spine.TextureRegion");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // float getRotation()
    float ret = self->getRotation();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // float getScaleX()
    float ret = self->getScaleX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // float getScaleY()
    float ret = self->getScaleY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getSequence(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // spine::Sequence *getSequence()
    spine::Sequence *ret = self->getSequence();
    int num_ret = olua_push_object(L, ret, "spine.Sequence");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getUVs(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // spine::Vector<float> &getUVs()
    spine::Vector<float> &ret = self->getUVs();
    int num_ret = olua_push_vector<float>(L, ret, [L](float &arg1) {
        olua_push_number(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // float getWidth()
    float ret = self->getWidth();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // float getX()
    float ret = self->getX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // float getY()
    float ret = self->getY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    olua_check_string(L, 1, &arg1);

    // RegionAttachment(const spine::String &name)
    spine::RegionAttachment *ret = new spine::RegionAttachment(arg1);
    int num_ret = olua_push_object(L, ret, "spine.RegionAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_setHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setHeight(float inValue)
    self->setHeight(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_string(L, 2, &arg1);

    // void setPath(const spine::String &inValue)
    self->setPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setRegion(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    spine::TextureRegion *arg1 = nullptr;       /** region */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_object(L, 2, &arg1, "spine.TextureRegion");

    // void setRegion(spine::TextureRegion *region)
    self->setRegion(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRotation(float inValue)
    self->setRotation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setScaleX(float inValue)
    self->setScaleX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setScaleY(float inValue)
    self->setScaleY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setSequence(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    spine::Sequence *arg1 = nullptr;       /** sequence */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_object(L, 2, &arg1, "spine.Sequence");

    // void setSequence(spine::Sequence *sequence)
    self->setSequence(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setWidth(float inValue)
    self->setWidth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_updateRegion(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_object(L, 1, &self, "spine.RegionAttachment");

    // void updateRegion()
    self->updateRegion();

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_RegionAttachment(lua_State *L)
{
    oluacls_class<spine::RegionAttachment, spine::Attachment>(L, "spine.RegionAttachment");
    oluacls_func(L, "computeWorldVertices", _spine_RegionAttachment_computeWorldVertices);
    oluacls_func(L, "getColor", _spine_RegionAttachment_getColor);
    oluacls_func(L, "getHeight", _spine_RegionAttachment_getHeight);
    oluacls_func(L, "getOffset", _spine_RegionAttachment_getOffset);
    oluacls_func(L, "getPath", _spine_RegionAttachment_getPath);
    oluacls_func(L, "getRegion", _spine_RegionAttachment_getRegion);
    oluacls_func(L, "getRotation", _spine_RegionAttachment_getRotation);
    oluacls_func(L, "getScaleX", _spine_RegionAttachment_getScaleX);
    oluacls_func(L, "getScaleY", _spine_RegionAttachment_getScaleY);
    oluacls_func(L, "getSequence", _spine_RegionAttachment_getSequence);
    oluacls_func(L, "getUVs", _spine_RegionAttachment_getUVs);
    oluacls_func(L, "getWidth", _spine_RegionAttachment_getWidth);
    oluacls_func(L, "getX", _spine_RegionAttachment_getX);
    oluacls_func(L, "getY", _spine_RegionAttachment_getY);
    oluacls_func(L, "new", _spine_RegionAttachment_new);
    oluacls_func(L, "setHeight", _spine_RegionAttachment_setHeight);
    oluacls_func(L, "setPath", _spine_RegionAttachment_setPath);
    oluacls_func(L, "setRegion", _spine_RegionAttachment_setRegion);
    oluacls_func(L, "setRotation", _spine_RegionAttachment_setRotation);
    oluacls_func(L, "setScaleX", _spine_RegionAttachment_setScaleX);
    oluacls_func(L, "setScaleY", _spine_RegionAttachment_setScaleY);
    oluacls_func(L, "setSequence", _spine_RegionAttachment_setSequence);
    oluacls_func(L, "setWidth", _spine_RegionAttachment_setWidth);
    oluacls_func(L, "setX", _spine_RegionAttachment_setX);
    oluacls_func(L, "setY", _spine_RegionAttachment_setY);
    oluacls_func(L, "updateRegion", _spine_RegionAttachment_updateRegion);
    oluacls_prop(L, "color", _spine_RegionAttachment_getColor, nullptr);
    oluacls_prop(L, "height", _spine_RegionAttachment_getHeight, _spine_RegionAttachment_setHeight);
    oluacls_prop(L, "offset", _spine_RegionAttachment_getOffset, nullptr);
    oluacls_prop(L, "path", _spine_RegionAttachment_getPath, _spine_RegionAttachment_setPath);
    oluacls_prop(L, "region", _spine_RegionAttachment_getRegion, _spine_RegionAttachment_setRegion);
    oluacls_prop(L, "rotation", _spine_RegionAttachment_getRotation, _spine_RegionAttachment_setRotation);
    oluacls_prop(L, "scaleX", _spine_RegionAttachment_getScaleX, _spine_RegionAttachment_setScaleX);
    oluacls_prop(L, "scaleY", _spine_RegionAttachment_getScaleY, _spine_RegionAttachment_setScaleY);
    oluacls_prop(L, "sequence", _spine_RegionAttachment_getSequence, _spine_RegionAttachment_setSequence);
    oluacls_prop(L, "uvs", _spine_RegionAttachment_getUVs, nullptr);
    oluacls_prop(L, "width", _spine_RegionAttachment_getWidth, _spine_RegionAttachment_setWidth);
    oluacls_prop(L, "x", _spine_RegionAttachment_getX, _spine_RegionAttachment_setX);
    oluacls_prop(L, "y", _spine_RegionAttachment_getY, _spine_RegionAttachment_setY);

    return 1;
}
OLUA_END_DECLS

static int _spine_TrackEntry_getAlpha(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getAlpha()
    float ret = self->getAlpha();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // spine::Animation *getAnimation()
    spine::Animation *ret = self->getAnimation();
    int num_ret = olua_push_object(L, ret, "spine.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAnimationEnd(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getAnimationEnd()
    float ret = self->getAnimationEnd();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAnimationLast(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getAnimationLast()
    float ret = self->getAnimationLast();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAnimationStart(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getAnimationStart()
    float ret = self->getAnimationStart();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAnimationTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getAnimationTime()
    float ret = self->getAnimationTime();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAttachmentThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getAttachmentThreshold()
    float ret = self->getAttachmentThreshold();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getDelay(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getDelay()
    float ret = self->getDelay();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getDrawOrderThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getDrawOrderThreshold()
    float ret = self->getDrawOrderThreshold();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getEventThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getEventThreshold()
    float ret = self->getEventThreshold();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getHoldPrevious(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // bool getHoldPrevious()
    bool ret = self->getHoldPrevious();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getLoop(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // bool getLoop()
    bool ret = self->getLoop();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getMixBlend(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // spine::MixBlend getMixBlend()
    spine::MixBlend ret = self->getMixBlend();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getMixDuration(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getMixDuration()
    float ret = self->getMixDuration();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getMixTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getMixTime()
    float ret = self->getMixTime();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getMixingFrom(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // spine::TrackEntry *getMixingFrom()
    spine::TrackEntry *ret = self->getMixingFrom();
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getMixingTo(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // spine::TrackEntry *getMixingTo()
    spine::TrackEntry *ret = self->getMixingTo();
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getNext(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // spine::TrackEntry *getNext()
    spine::TrackEntry *ret = self->getNext();
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getPrevious(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // spine::TrackEntry *getPrevious()
    spine::TrackEntry *ret = self->getPrevious();
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getReverse(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // bool getReverse()
    bool ret = self->getReverse();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getShortestRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // bool getShortestRotation()
    bool ret = self->getShortestRotation();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getTimeScale()
    float ret = self->getTimeScale();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getTrackComplete(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getTrackComplete()
    float ret = self->getTrackComplete();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getTrackEnd(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getTrackEnd()
    float ret = self->getTrackEnd();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getTrackIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // int getTrackIndex()
    int ret = self->getTrackIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getTrackTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // float getTrackTime()
    float ret = self->getTrackTime();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_isComplete(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // bool isComplete()
    bool ret = self->isComplete();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_new(lua_State *L)
{
    olua_startinvoke(L);

    // TrackEntry()
    spine::TrackEntry *ret = new spine::TrackEntry();
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_resetRotationDirections(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_object(L, 1, &self, "spine.TrackEntry");

    // void resetRotationDirections()
    self->resetRotationDirections();

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setAlpha(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setAlpha(float inValue)
    self->setAlpha(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setAnimationEnd(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setAnimationEnd(float inValue)
    self->setAnimationEnd(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setAnimationLast(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setAnimationLast(float inValue)
    self->setAnimationLast(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setAnimationStart(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setAnimationStart(float inValue)
    self->setAnimationStart(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setAttachmentThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setAttachmentThreshold(float inValue)
    self->setAttachmentThreshold(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setDelay(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setDelay(float inValue)
    self->setDelay(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setDrawOrderThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setDrawOrderThreshold(float inValue)
    self->setDrawOrderThreshold(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setEventThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setEventThreshold(float inValue)
    self->setEventThreshold(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setHoldPrevious(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_bool(L, 2, &arg1);

    // void setHoldPrevious(bool inValue)
    self->setHoldPrevious(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    spine::AnimationStateListener arg1;       /** listener */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_callback(L, 2, &arg1, "spine.AnimationStateListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "Listener";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](spine::AnimationState *arg1, spine::EventType arg2, spine::TrackEntry *arg3, spine::Event *arg4) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.AnimationState");
            olua_push_enum(L, arg2);
            olua_push_object(L, arg3, "spine.TrackEntry");
            olua_push_object(L, arg4, "spine.Event");

            olua_callback(L, cb_store, cb_name.c_str(), 4);

            lua_settop(L, top);
        }
    };

    // void setListener(spine::AnimationStateListener listener)
    self->setListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setLoop(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_bool(L, 2, &arg1);

    // void setLoop(bool inValue)
    self->setLoop(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setMixBlend(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    spine::MixBlend arg1 = (spine::MixBlend)0;       /** blend */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_enum(L, 2, &arg1);

    // void setMixBlend(spine::MixBlend blend)
    self->setMixBlend(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setMixDuration(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setMixDuration(float inValue)
    self->setMixDuration(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setMixTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setMixTime(float inValue)
    self->setMixTime(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setReverse(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_bool(L, 2, &arg1);

    // void setReverse(bool inValue)
    self->setReverse(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setShortestRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_bool(L, 2, &arg1);

    // void setShortestRotation(bool inValue)
    self->setShortestRotation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setTimeScale(float inValue)
    self->setTimeScale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setTrackEnd(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setTrackEnd(float inValue)
    self->setTrackEnd(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setTrackTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setTrackTime(float inValue)
    self->setTrackTime(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_TrackEntry(lua_State *L)
{
    oluacls_class<spine::TrackEntry, spine::SpineObject>(L, "spine.TrackEntry");
    oluacls_func(L, "getAlpha", _spine_TrackEntry_getAlpha);
    oluacls_func(L, "getAnimation", _spine_TrackEntry_getAnimation);
    oluacls_func(L, "getAnimationEnd", _spine_TrackEntry_getAnimationEnd);
    oluacls_func(L, "getAnimationLast", _spine_TrackEntry_getAnimationLast);
    oluacls_func(L, "getAnimationStart", _spine_TrackEntry_getAnimationStart);
    oluacls_func(L, "getAnimationTime", _spine_TrackEntry_getAnimationTime);
    oluacls_func(L, "getAttachmentThreshold", _spine_TrackEntry_getAttachmentThreshold);
    oluacls_func(L, "getDelay", _spine_TrackEntry_getDelay);
    oluacls_func(L, "getDrawOrderThreshold", _spine_TrackEntry_getDrawOrderThreshold);
    oluacls_func(L, "getEventThreshold", _spine_TrackEntry_getEventThreshold);
    oluacls_func(L, "getHoldPrevious", _spine_TrackEntry_getHoldPrevious);
    oluacls_func(L, "getLoop", _spine_TrackEntry_getLoop);
    oluacls_func(L, "getMixBlend", _spine_TrackEntry_getMixBlend);
    oluacls_func(L, "getMixDuration", _spine_TrackEntry_getMixDuration);
    oluacls_func(L, "getMixTime", _spine_TrackEntry_getMixTime);
    oluacls_func(L, "getMixingFrom", _spine_TrackEntry_getMixingFrom);
    oluacls_func(L, "getMixingTo", _spine_TrackEntry_getMixingTo);
    oluacls_func(L, "getNext", _spine_TrackEntry_getNext);
    oluacls_func(L, "getPrevious", _spine_TrackEntry_getPrevious);
    oluacls_func(L, "getReverse", _spine_TrackEntry_getReverse);
    oluacls_func(L, "getShortestRotation", _spine_TrackEntry_getShortestRotation);
    oluacls_func(L, "getTimeScale", _spine_TrackEntry_getTimeScale);
    oluacls_func(L, "getTrackComplete", _spine_TrackEntry_getTrackComplete);
    oluacls_func(L, "getTrackEnd", _spine_TrackEntry_getTrackEnd);
    oluacls_func(L, "getTrackIndex", _spine_TrackEntry_getTrackIndex);
    oluacls_func(L, "getTrackTime", _spine_TrackEntry_getTrackTime);
    oluacls_func(L, "isComplete", _spine_TrackEntry_isComplete);
    oluacls_func(L, "new", _spine_TrackEntry_new);
    oluacls_func(L, "resetRotationDirections", _spine_TrackEntry_resetRotationDirections);
    oluacls_func(L, "setAlpha", _spine_TrackEntry_setAlpha);
    oluacls_func(L, "setAnimationEnd", _spine_TrackEntry_setAnimationEnd);
    oluacls_func(L, "setAnimationLast", _spine_TrackEntry_setAnimationLast);
    oluacls_func(L, "setAnimationStart", _spine_TrackEntry_setAnimationStart);
    oluacls_func(L, "setAttachmentThreshold", _spine_TrackEntry_setAttachmentThreshold);
    oluacls_func(L, "setDelay", _spine_TrackEntry_setDelay);
    oluacls_func(L, "setDrawOrderThreshold", _spine_TrackEntry_setDrawOrderThreshold);
    oluacls_func(L, "setEventThreshold", _spine_TrackEntry_setEventThreshold);
    oluacls_func(L, "setHoldPrevious", _spine_TrackEntry_setHoldPrevious);
    oluacls_func(L, "setListener", _spine_TrackEntry_setListener);
    oluacls_func(L, "setLoop", _spine_TrackEntry_setLoop);
    oluacls_func(L, "setMixBlend", _spine_TrackEntry_setMixBlend);
    oluacls_func(L, "setMixDuration", _spine_TrackEntry_setMixDuration);
    oluacls_func(L, "setMixTime", _spine_TrackEntry_setMixTime);
    oluacls_func(L, "setReverse", _spine_TrackEntry_setReverse);
    oluacls_func(L, "setShortestRotation", _spine_TrackEntry_setShortestRotation);
    oluacls_func(L, "setTimeScale", _spine_TrackEntry_setTimeScale);
    oluacls_func(L, "setTrackEnd", _spine_TrackEntry_setTrackEnd);
    oluacls_func(L, "setTrackTime", _spine_TrackEntry_setTrackTime);
    oluacls_prop(L, "alpha", _spine_TrackEntry_getAlpha, _spine_TrackEntry_setAlpha);
    oluacls_prop(L, "animation", _spine_TrackEntry_getAnimation, nullptr);
    oluacls_prop(L, "animationEnd", _spine_TrackEntry_getAnimationEnd, _spine_TrackEntry_setAnimationEnd);
    oluacls_prop(L, "animationLast", _spine_TrackEntry_getAnimationLast, _spine_TrackEntry_setAnimationLast);
    oluacls_prop(L, "animationStart", _spine_TrackEntry_getAnimationStart, _spine_TrackEntry_setAnimationStart);
    oluacls_prop(L, "animationTime", _spine_TrackEntry_getAnimationTime, nullptr);
    oluacls_prop(L, "attachmentThreshold", _spine_TrackEntry_getAttachmentThreshold, _spine_TrackEntry_setAttachmentThreshold);
    oluacls_prop(L, "complete", _spine_TrackEntry_isComplete, nullptr);
    oluacls_prop(L, "delay", _spine_TrackEntry_getDelay, _spine_TrackEntry_setDelay);
    oluacls_prop(L, "drawOrderThreshold", _spine_TrackEntry_getDrawOrderThreshold, _spine_TrackEntry_setDrawOrderThreshold);
    oluacls_prop(L, "eventThreshold", _spine_TrackEntry_getEventThreshold, _spine_TrackEntry_setEventThreshold);
    oluacls_prop(L, "holdPrevious", _spine_TrackEntry_getHoldPrevious, _spine_TrackEntry_setHoldPrevious);
    oluacls_prop(L, "loop", _spine_TrackEntry_getLoop, _spine_TrackEntry_setLoop);
    oluacls_prop(L, "mixBlend", _spine_TrackEntry_getMixBlend, _spine_TrackEntry_setMixBlend);
    oluacls_prop(L, "mixDuration", _spine_TrackEntry_getMixDuration, _spine_TrackEntry_setMixDuration);
    oluacls_prop(L, "mixTime", _spine_TrackEntry_getMixTime, _spine_TrackEntry_setMixTime);
    oluacls_prop(L, "mixingFrom", _spine_TrackEntry_getMixingFrom, nullptr);
    oluacls_prop(L, "mixingTo", _spine_TrackEntry_getMixingTo, nullptr);
    oluacls_prop(L, "next", _spine_TrackEntry_getNext, nullptr);
    oluacls_prop(L, "previous", _spine_TrackEntry_getPrevious, nullptr);
    oluacls_prop(L, "reverse", _spine_TrackEntry_getReverse, _spine_TrackEntry_setReverse);
    oluacls_prop(L, "shortestRotation", _spine_TrackEntry_getShortestRotation, _spine_TrackEntry_setShortestRotation);
    oluacls_prop(L, "timeScale", _spine_TrackEntry_getTimeScale, _spine_TrackEntry_setTimeScale);
    oluacls_prop(L, "trackComplete", _spine_TrackEntry_getTrackComplete, nullptr);
    oluacls_prop(L, "trackEnd", _spine_TrackEntry_getTrackEnd, _spine_TrackEntry_setTrackEnd);
    oluacls_prop(L, "trackIndex", _spine_TrackEntry_getTrackIndex, nullptr);
    oluacls_prop(L, "trackTime", _spine_TrackEntry_getTrackTime, _spine_TrackEntry_setTrackTime);

    return 1;
}
OLUA_END_DECLS

static int _spine_SkeletonData___gc(lua_State *L)
{
    olua_startinvoke(L);

    // @extend(spine::SkeletonDataExtend) static olua_Return __gc(lua_State *L)
    olua_Return ret = spine::SkeletonDataExtend::__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _spine_SkeletonData_create$1(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg2 = nullptr;       /** skelPath */
    const char *arg3 = nullptr;       /** atlasPath */
    float arg4 = 0;       /** scale */

    olua_check_string(L, 1, &arg2);
    olua_check_string(L, 2, &arg3);
    olua_check_number(L, 3, &arg4);

    // @extend(spine::SkeletonDataExtend) static olua_Return create(lua_State *L, const char *skelPath, const char *atlasPath, @optional float scale)
    olua_Return ret = spine::SkeletonDataExtend::create(L, arg2, arg3, arg4);

    olua_endinvoke(L);

    return (int)ret;
}

static int _spine_SkeletonData_create$2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg2 = nullptr;       /** skelPath */
    const char *arg3 = nullptr;       /** atlasPath */

    olua_check_string(L, 1, &arg2);
    olua_check_string(L, 2, &arg3);

    // @extend(spine::SkeletonDataExtend) static olua_Return create(lua_State *L, const char *skelPath, const char *atlasPath, @optional float scale)
    olua_Return ret = spine::SkeletonDataExtend::create(L, arg2, arg3);

    olua_endinvoke(L);

    return (int)ret;
}

static int _spine_SkeletonData_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // @extend(spine::SkeletonDataExtend) static olua_Return create(lua_State *L, const char *skelPath, const char *atlasPath, @optional float scale)
            return _spine_SkeletonData_create$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // @extend(spine::SkeletonDataExtend) static olua_Return create(lua_State *L, const char *skelPath, const char *atlasPath, @optional float scale)
            return _spine_SkeletonData_create$1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonData::create' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonData_findAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** animationName */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // spine::Animation *findAnimation(const spine::String &animationName)
    spine::Animation *ret = self->findAnimation(arg1);
    int num_ret = olua_push_object(L, ret, "spine.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findBone(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** boneName */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // spine::BoneData *findBone(const spine::String &boneName)
    spine::BoneData *ret = self->findBone(arg1);
    int num_ret = olua_push_object(L, ret, "spine.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findEvent(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** eventDataName */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // spine::EventData *findEvent(const spine::String &eventDataName)
    spine::EventData *ret = self->findEvent(arg1);
    int num_ret = olua_push_object(L, ret, "spine.EventData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findIkConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // spine::IkConstraintData *findIkConstraint(const spine::String &constraintName)
    spine::IkConstraintData *ret = self->findIkConstraint(arg1);
    int num_ret = olua_push_object(L, ret, "spine.IkConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findPathConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // spine::PathConstraintData *findPathConstraint(const spine::String &constraintName)
    spine::PathConstraintData *ret = self->findPathConstraint(arg1);
    int num_ret = olua_push_object(L, ret, "spine.PathConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findSkin(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** skinName */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // spine::Skin *findSkin(const spine::String &skinName)
    spine::Skin *ret = self->findSkin(arg1);
    int num_ret = olua_push_object(L, ret, "spine.Skin");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findSlot(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** slotName */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // spine::SlotData *findSlot(const spine::String &slotName)
    spine::SlotData *ret = self->findSlot(arg1);
    int num_ret = olua_push_object(L, ret, "spine.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findTransformConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // spine::TransformConstraintData *findTransformConstraint(const spine::String &constraintName)
    spine::TransformConstraintData *ret = self->findTransformConstraint(arg1);
    int num_ret = olua_push_object(L, ret, "spine.TransformConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getAnimations(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // spine::Vector<spine::Animation *> &getAnimations()
    spine::Vector<spine::Animation *> &ret = self->getAnimations();
    int num_ret = olua_push_vector<spine::Animation *>(L, ret, [L](spine::Animation *arg1) {
        olua_push_object(L, arg1, "spine.Animation");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getAudioPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // const spine::String &getAudioPath()
    const spine::String &ret = self->getAudioPath();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // spine::Vector<spine::BoneData *> &getBones()
    spine::Vector<spine::BoneData *> &ret = self->getBones();
    int num_ret = olua_push_vector<spine::BoneData *>(L, ret, [L](spine::BoneData *arg1) {
        olua_push_object(L, arg1, "spine.BoneData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getDefaultSkin(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // spine::Skin *getDefaultSkin()
    spine::Skin *ret = self->getDefaultSkin();
    int num_ret = olua_push_object(L, ret, "spine.Skin");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getEvents(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // spine::Vector<spine::EventData *> &getEvents()
    spine::Vector<spine::EventData *> &ret = self->getEvents();
    int num_ret = olua_push_vector<spine::EventData *>(L, ret, [L](spine::EventData *arg1) {
        olua_push_object(L, arg1, "spine.EventData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getFps(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // float getFps()
    float ret = self->getFps();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getHash(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // const spine::String &getHash()
    const spine::String &ret = self->getHash();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // float getHeight()
    float ret = self->getHeight();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getIkConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // spine::Vector<spine::IkConstraintData *> &getIkConstraints()
    spine::Vector<spine::IkConstraintData *> &ret = self->getIkConstraints();
    int num_ret = olua_push_vector<spine::IkConstraintData *>(L, ret, [L](spine::IkConstraintData *arg1) {
        olua_push_object(L, arg1, "spine.IkConstraintData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getImagesPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // const spine::String &getImagesPath()
    const spine::String &ret = self->getImagesPath();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // const spine::String &getName()
    const spine::String &ret = self->getName();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getPathConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // spine::Vector<spine::PathConstraintData *> &getPathConstraints()
    spine::Vector<spine::PathConstraintData *> &ret = self->getPathConstraints();
    int num_ret = olua_push_vector<spine::PathConstraintData *>(L, ret, [L](spine::PathConstraintData *arg1) {
        olua_push_object(L, arg1, "spine.PathConstraintData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getSkins(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // spine::Vector<spine::Skin *> &getSkins()
    spine::Vector<spine::Skin *> &ret = self->getSkins();
    int num_ret = olua_push_vector<spine::Skin *>(L, ret, [L](spine::Skin *arg1) {
        olua_push_object(L, arg1, "spine.Skin");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getSlots(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // spine::Vector<spine::SlotData *> &getSlots()
    spine::Vector<spine::SlotData *> &ret = self->getSlots();
    int num_ret = olua_push_vector<spine::SlotData *>(L, ret, [L](spine::SlotData *arg1) {
        olua_push_object(L, arg1, "spine.SlotData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getTransformConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // spine::Vector<spine::TransformConstraintData *> &getTransformConstraints()
    spine::Vector<spine::TransformConstraintData *> &ret = self->getTransformConstraints();
    int num_ret = olua_push_vector<spine::TransformConstraintData *>(L, ret, [L](spine::TransformConstraintData *arg1) {
        olua_push_object(L, arg1, "spine.TransformConstraintData");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getVersion(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // const spine::String &getVersion()
    const spine::String &ret = self->getVersion();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // float getWidth()
    float ret = self->getWidth();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // float getX()
    float ret = self->getX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonData");

    // float getY()
    float ret = self->getY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_setAudioPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // void setAudioPath(const spine::String &inValue)
    self->setAudioPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setDefaultSkin(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::Skin *arg1 = nullptr;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_object(L, 2, &arg1, "spine.Skin");

    // void setDefaultSkin(spine::Skin *inValue)
    self->setDefaultSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setFps(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_number(L, 2, &arg1);

    // void setFps(float inValue)
    self->setFps(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setHash(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // void setHash(const spine::String &inValue)
    self->setHash(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_number(L, 2, &arg1);

    // void setHeight(float inValue)
    self->setHeight(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setImagesPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // void setImagesPath(const spine::String &inValue)
    self->setImagesPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setName(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // void setName(const spine::String &inValue)
    self->setName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setVersion(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_string(L, 2, &arg1);

    // void setVersion(const spine::String &inValue)
    self->setVersion(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_number(L, 2, &arg1);

    // void setWidth(float inValue)
    self->setWidth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.SkeletonData");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_SkeletonData(lua_State *L)
{
    oluacls_class<spine::SkeletonData, spine::SpineObject>(L, "spine.SkeletonData");
    oluacls_func(L, "__gc", _spine_SkeletonData___gc);
    oluacls_func(L, "create", _spine_SkeletonData_create);
    oluacls_func(L, "dispose", _spine_SkeletonData___gc);
    oluacls_func(L, "findAnimation", _spine_SkeletonData_findAnimation);
    oluacls_func(L, "findBone", _spine_SkeletonData_findBone);
    oluacls_func(L, "findEvent", _spine_SkeletonData_findEvent);
    oluacls_func(L, "findIkConstraint", _spine_SkeletonData_findIkConstraint);
    oluacls_func(L, "findPathConstraint", _spine_SkeletonData_findPathConstraint);
    oluacls_func(L, "findSkin", _spine_SkeletonData_findSkin);
    oluacls_func(L, "findSlot", _spine_SkeletonData_findSlot);
    oluacls_func(L, "findTransformConstraint", _spine_SkeletonData_findTransformConstraint);
    oluacls_func(L, "getAnimations", _spine_SkeletonData_getAnimations);
    oluacls_func(L, "getAudioPath", _spine_SkeletonData_getAudioPath);
    oluacls_func(L, "getBones", _spine_SkeletonData_getBones);
    oluacls_func(L, "getDefaultSkin", _spine_SkeletonData_getDefaultSkin);
    oluacls_func(L, "getEvents", _spine_SkeletonData_getEvents);
    oluacls_func(L, "getFps", _spine_SkeletonData_getFps);
    oluacls_func(L, "getHash", _spine_SkeletonData_getHash);
    oluacls_func(L, "getHeight", _spine_SkeletonData_getHeight);
    oluacls_func(L, "getIkConstraints", _spine_SkeletonData_getIkConstraints);
    oluacls_func(L, "getImagesPath", _spine_SkeletonData_getImagesPath);
    oluacls_func(L, "getName", _spine_SkeletonData_getName);
    oluacls_func(L, "getPathConstraints", _spine_SkeletonData_getPathConstraints);
    oluacls_func(L, "getSkins", _spine_SkeletonData_getSkins);
    oluacls_func(L, "getSlots", _spine_SkeletonData_getSlots);
    oluacls_func(L, "getTransformConstraints", _spine_SkeletonData_getTransformConstraints);
    oluacls_func(L, "getVersion", _spine_SkeletonData_getVersion);
    oluacls_func(L, "getWidth", _spine_SkeletonData_getWidth);
    oluacls_func(L, "getX", _spine_SkeletonData_getX);
    oluacls_func(L, "getY", _spine_SkeletonData_getY);
    oluacls_func(L, "new", _spine_SkeletonData_create);
    oluacls_func(L, "setAudioPath", _spine_SkeletonData_setAudioPath);
    oluacls_func(L, "setDefaultSkin", _spine_SkeletonData_setDefaultSkin);
    oluacls_func(L, "setFps", _spine_SkeletonData_setFps);
    oluacls_func(L, "setHash", _spine_SkeletonData_setHash);
    oluacls_func(L, "setHeight", _spine_SkeletonData_setHeight);
    oluacls_func(L, "setImagesPath", _spine_SkeletonData_setImagesPath);
    oluacls_func(L, "setName", _spine_SkeletonData_setName);
    oluacls_func(L, "setVersion", _spine_SkeletonData_setVersion);
    oluacls_func(L, "setWidth", _spine_SkeletonData_setWidth);
    oluacls_func(L, "setX", _spine_SkeletonData_setX);
    oluacls_func(L, "setY", _spine_SkeletonData_setY);
    oluacls_prop(L, "animations", _spine_SkeletonData_getAnimations, nullptr);
    oluacls_prop(L, "audioPath", _spine_SkeletonData_getAudioPath, _spine_SkeletonData_setAudioPath);
    oluacls_prop(L, "bones", _spine_SkeletonData_getBones, nullptr);
    oluacls_prop(L, "defaultSkin", _spine_SkeletonData_getDefaultSkin, _spine_SkeletonData_setDefaultSkin);
    oluacls_prop(L, "events", _spine_SkeletonData_getEvents, nullptr);
    oluacls_prop(L, "fps", _spine_SkeletonData_getFps, _spine_SkeletonData_setFps);
    oluacls_prop(L, "hash", _spine_SkeletonData_getHash, _spine_SkeletonData_setHash);
    oluacls_prop(L, "height", _spine_SkeletonData_getHeight, _spine_SkeletonData_setHeight);
    oluacls_prop(L, "ikConstraints", _spine_SkeletonData_getIkConstraints, nullptr);
    oluacls_prop(L, "imagesPath", _spine_SkeletonData_getImagesPath, _spine_SkeletonData_setImagesPath);
    oluacls_prop(L, "name", _spine_SkeletonData_getName, _spine_SkeletonData_setName);
    oluacls_prop(L, "pathConstraints", _spine_SkeletonData_getPathConstraints, nullptr);
    oluacls_prop(L, "skins", _spine_SkeletonData_getSkins, nullptr);
    oluacls_prop(L, "slots", _spine_SkeletonData_getSlots, nullptr);
    oluacls_prop(L, "transformConstraints", _spine_SkeletonData_getTransformConstraints, nullptr);
    oluacls_prop(L, "version", _spine_SkeletonData_getVersion, _spine_SkeletonData_setVersion);
    oluacls_prop(L, "width", _spine_SkeletonData_getWidth, _spine_SkeletonData_setWidth);
    oluacls_prop(L, "x", _spine_SkeletonData_getX, _spine_SkeletonData_setX);
    oluacls_prop(L, "y", _spine_SkeletonData_getY, _spine_SkeletonData_setY);

    return 1;
}
OLUA_END_DECLS

static int _spine_Skeleton_findBone(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** boneName */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_string(L, 2, &arg1);

    // spine::Bone *findBone(const spine::String &boneName)
    spine::Bone *ret = self->findBone(arg1);
    int num_ret = olua_push_object(L, ret, "spine.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_findIkConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_string(L, 2, &arg1);

    // spine::IkConstraint *findIkConstraint(const spine::String &constraintName)
    spine::IkConstraint *ret = self->findIkConstraint(arg1);
    int num_ret = olua_push_object(L, ret, "spine.IkConstraint");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_findPathConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_string(L, 2, &arg1);

    // spine::PathConstraint *findPathConstraint(const spine::String &constraintName)
    spine::PathConstraint *ret = self->findPathConstraint(arg1);
    int num_ret = olua_push_object(L, ret, "spine.PathConstraint");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_findSlot(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** slotName */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_string(L, 2, &arg1);

    // spine::Slot *findSlot(const spine::String &slotName)
    spine::Slot *ret = self->findSlot(arg1);
    int num_ret = olua_push_object(L, ret, "spine.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_findTransformConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_string(L, 2, &arg1);

    // spine::TransformConstraint *findTransformConstraint(const spine::String &constraintName)
    spine::TransformConstraint *ret = self->findTransformConstraint(arg1);
    int num_ret = olua_push_object(L, ret, "spine.TransformConstraint");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getAttachment$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** slotName */
    spine::String arg2;       /** attachmentName */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // spine::Attachment *getAttachment(const spine::String &slotName, const spine::String &attachmentName)
    spine::Attachment *ret = self->getAttachment(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getAttachment$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    int arg1 = 0;       /** slotIndex */
    spine::String arg2;       /** attachmentName */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_integer(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // spine::Attachment *getAttachment(int slotIndex, const spine::String &attachmentName)
    spine::Attachment *ret = self->getAttachment(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getAttachment(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        if ((olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // spine::Attachment *getAttachment(const spine::String &slotName, const spine::String &attachmentName)
            return _spine_Skeleton_getAttachment$1(L);
        }

        // if ((olua_is_integer(L, 2)) && (olua_is_string(L, 3))) {
            // spine::Attachment *getAttachment(int slotIndex, const spine::String &attachmentName)
            return _spine_Skeleton_getAttachment$2(L);
        // }
    }

    luaL_error(L, "method 'spine::Skeleton::getAttachment' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_Skeleton_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // spine::Vector<spine::Bone *> &getBones()
    spine::Vector<spine::Bone *> &ret = self->getBones();
    int num_ret = olua_push_vector<spine::Bone *>(L, ret, [L](spine::Bone *arg1) {
        olua_push_object(L, arg1, "spine.Bone");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // spine::Color &getColor()
    spine::Color &ret = self->getColor();
    int num_ret = olua_push_spine_Color(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getData(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // spine::SkeletonData *getData()
    spine::SkeletonData *ret = self->getData();
    int num_ret = olua_push_object(L, ret, "spine.SkeletonData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getDrawOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // spine::Vector<spine::Slot *> &getDrawOrder()
    spine::Vector<spine::Slot *> &ret = self->getDrawOrder();
    int num_ret = olua_push_vector<spine::Slot *>(L, ret, [L](spine::Slot *arg1) {
        olua_push_object(L, arg1, "spine.Slot");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getIkConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // spine::Vector<spine::IkConstraint *> &getIkConstraints()
    spine::Vector<spine::IkConstraint *> &ret = self->getIkConstraints();
    int num_ret = olua_push_vector<spine::IkConstraint *>(L, ret, [L](spine::IkConstraint *arg1) {
        olua_push_object(L, arg1, "spine.IkConstraint");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getPathConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // spine::Vector<spine::PathConstraint *> &getPathConstraints()
    spine::Vector<spine::PathConstraint *> &ret = self->getPathConstraints();
    int num_ret = olua_push_vector<spine::PathConstraint *>(L, ret, [L](spine::PathConstraint *arg1) {
        olua_push_object(L, arg1, "spine.PathConstraint");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getRootBone(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // spine::Bone *getRootBone()
    spine::Bone *ret = self->getRootBone();
    int num_ret = olua_push_object(L, ret, "spine.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // float getScaleX()
    float ret = self->getScaleX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // float getScaleY()
    float ret = self->getScaleY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getSkin(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // spine::Skin *getSkin()
    spine::Skin *ret = self->getSkin();
    int num_ret = olua_push_object(L, ret, "spine.Skin");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getSlots(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // spine::Vector<spine::Slot *> &getSlots()
    spine::Vector<spine::Slot *> &ret = self->getSlots();
    int num_ret = olua_push_vector<spine::Slot *>(L, ret, [L](spine::Slot *arg1) {
        olua_push_object(L, arg1, "spine.Slot");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getTransformConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // spine::Vector<spine::TransformConstraint *> &getTransformConstraints()
    spine::Vector<spine::TransformConstraint *> &ret = self->getTransformConstraints();
    int num_ret = olua_push_vector<spine::TransformConstraint *>(L, ret, [L](spine::TransformConstraint *arg1) {
        olua_push_object(L, arg1, "spine.TransformConstraint");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getUpdateCacheList(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // spine::Vector<spine::Updatable *> &getUpdateCacheList()
    spine::Vector<spine::Updatable *> &ret = self->getUpdateCacheList();
    int num_ret = olua_push_vector<spine::Updatable *>(L, ret, [L](spine::Updatable *arg1) {
        olua_push_object(L, arg1, "spine.Updatable");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // float getX()
    float ret = self->getX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // float getY()
    float ret = self->getY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */

    olua_check_object(L, 1, &arg1, "spine.SkeletonData");

    // Skeleton(spine::SkeletonData *skeletonData)
    spine::Skeleton *ret = new spine::Skeleton(arg1);
    int num_ret = olua_push_object(L, ret, "spine.Skeleton");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_printUpdateCache(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // void printUpdateCache()
    self->printUpdateCache();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** slotName */
    spine::String arg2;       /** attachmentName */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void setAttachment(const spine::String &slotName, const spine::String &attachmentName)
    self->setAttachment(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setBonesToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // void setBonesToSetupPose()
    self->setBonesToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void setPosition(float x, float y)
    self->setPosition(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_number(L, 2, &arg1);

    // void setScaleX(float inValue)
    self->setScaleX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_number(L, 2, &arg1);

    // void setScaleY(float inValue)
    self->setScaleY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setSkin$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** skinName */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_string(L, 2, &arg1);

    // void setSkin(const spine::String &skinName)
    self->setSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setSkin$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::Skin *arg1 = nullptr;       /** newSkin */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_object(L, 2, &arg1, "spine.Skin");

    // void setSkin(spine::Skin *newSkin)
    self->setSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setSkin(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_string(L, 2))) {
            // void setSkin(const spine::String &skinName)
            return _spine_Skeleton_setSkin$1(L);
        }

        // if ((olua_is_object(L, 2, "spine.Skin"))) {
            // void setSkin(spine::Skin *newSkin)
            return _spine_Skeleton_setSkin$2(L);
        // }
    }

    luaL_error(L, "method 'spine::Skeleton::setSkin' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_Skeleton_setSlotsToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // void setSlotsToSetupPose()
    self->setSlotsToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // void setToSetupPose()
    self->setToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    float arg1 = 0;       /** inValue */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_updateCache(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // void updateCache()
    self->updateCache();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_updateWorldTransform$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_object(L, 1, &self, "spine.Skeleton");

    // void updateWorldTransform()
    self->updateWorldTransform();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_updateWorldTransform$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::Bone *arg1 = nullptr;       /** parent */

    olua_to_object(L, 1, &self, "spine.Skeleton");
    olua_check_object(L, 2, &arg1, "spine.Bone");

    // void updateWorldTransform(spine::Bone *parent)
    self->updateWorldTransform(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_updateWorldTransform(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void updateWorldTransform()
        return _spine_Skeleton_updateWorldTransform$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "spine.Bone"))) {
            // void updateWorldTransform(spine::Bone *parent)
            return _spine_Skeleton_updateWorldTransform$2(L);
        // }
    }

    luaL_error(L, "method 'spine::Skeleton::updateWorldTransform' not support '%d' arguments", num_args);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_Skeleton(lua_State *L)
{
    oluacls_class<spine::Skeleton, spine::SpineObject>(L, "spine.Skeleton");
    oluacls_func(L, "findBone", _spine_Skeleton_findBone);
    oluacls_func(L, "findIkConstraint", _spine_Skeleton_findIkConstraint);
    oluacls_func(L, "findPathConstraint", _spine_Skeleton_findPathConstraint);
    oluacls_func(L, "findSlot", _spine_Skeleton_findSlot);
    oluacls_func(L, "findTransformConstraint", _spine_Skeleton_findTransformConstraint);
    oluacls_func(L, "getAttachment", _spine_Skeleton_getAttachment);
    oluacls_func(L, "getBones", _spine_Skeleton_getBones);
    oluacls_func(L, "getColor", _spine_Skeleton_getColor);
    oluacls_func(L, "getData", _spine_Skeleton_getData);
    oluacls_func(L, "getDrawOrder", _spine_Skeleton_getDrawOrder);
    oluacls_func(L, "getIkConstraints", _spine_Skeleton_getIkConstraints);
    oluacls_func(L, "getPathConstraints", _spine_Skeleton_getPathConstraints);
    oluacls_func(L, "getRootBone", _spine_Skeleton_getRootBone);
    oluacls_func(L, "getScaleX", _spine_Skeleton_getScaleX);
    oluacls_func(L, "getScaleY", _spine_Skeleton_getScaleY);
    oluacls_func(L, "getSkin", _spine_Skeleton_getSkin);
    oluacls_func(L, "getSlots", _spine_Skeleton_getSlots);
    oluacls_func(L, "getTransformConstraints", _spine_Skeleton_getTransformConstraints);
    oluacls_func(L, "getUpdateCacheList", _spine_Skeleton_getUpdateCacheList);
    oluacls_func(L, "getX", _spine_Skeleton_getX);
    oluacls_func(L, "getY", _spine_Skeleton_getY);
    oluacls_func(L, "new", _spine_Skeleton_new);
    oluacls_func(L, "printUpdateCache", _spine_Skeleton_printUpdateCache);
    oluacls_func(L, "setAttachment", _spine_Skeleton_setAttachment);
    oluacls_func(L, "setBonesToSetupPose", _spine_Skeleton_setBonesToSetupPose);
    oluacls_func(L, "setPosition", _spine_Skeleton_setPosition);
    oluacls_func(L, "setScaleX", _spine_Skeleton_setScaleX);
    oluacls_func(L, "setScaleY", _spine_Skeleton_setScaleY);
    oluacls_func(L, "setSkin", _spine_Skeleton_setSkin);
    oluacls_func(L, "setSlotsToSetupPose", _spine_Skeleton_setSlotsToSetupPose);
    oluacls_func(L, "setToSetupPose", _spine_Skeleton_setToSetupPose);
    oluacls_func(L, "setX", _spine_Skeleton_setX);
    oluacls_func(L, "setY", _spine_Skeleton_setY);
    oluacls_func(L, "updateCache", _spine_Skeleton_updateCache);
    oluacls_func(L, "updateWorldTransform", _spine_Skeleton_updateWorldTransform);
    oluacls_prop(L, "bones", _spine_Skeleton_getBones, nullptr);
    oluacls_prop(L, "color", _spine_Skeleton_getColor, nullptr);
    oluacls_prop(L, "data", _spine_Skeleton_getData, nullptr);
    oluacls_prop(L, "drawOrder", _spine_Skeleton_getDrawOrder, nullptr);
    oluacls_prop(L, "ikConstraints", _spine_Skeleton_getIkConstraints, nullptr);
    oluacls_prop(L, "pathConstraints", _spine_Skeleton_getPathConstraints, nullptr);
    oluacls_prop(L, "rootBone", _spine_Skeleton_getRootBone, nullptr);
    oluacls_prop(L, "scaleX", _spine_Skeleton_getScaleX, _spine_Skeleton_setScaleX);
    oluacls_prop(L, "scaleY", _spine_Skeleton_getScaleY, _spine_Skeleton_setScaleY);
    oluacls_prop(L, "skin", _spine_Skeleton_getSkin, _spine_Skeleton_setSkin);
    oluacls_prop(L, "slots", _spine_Skeleton_getSlots, nullptr);
    oluacls_prop(L, "transformConstraints", _spine_Skeleton_getTransformConstraints, nullptr);
    oluacls_prop(L, "updateCacheList", _spine_Skeleton_getUpdateCacheList, nullptr);
    oluacls_prop(L, "x", _spine_Skeleton_getX, _spine_Skeleton_setX);
    oluacls_prop(L, "y", _spine_Skeleton_getY, _spine_Skeleton_setY);

    return 1;
}
OLUA_END_DECLS

static int _spine_SkeletonRenderer_as(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "cc.BlendProtocol")) {
            olua_pushobj_as<cocos2d::BlendProtocol>(L, 1, self, "as.cc.BlendProtocol");
            break;
        }

        luaL_error(L, "'spine::SkeletonRenderer' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _spine_SkeletonRenderer_create(lua_State *L)
{
    olua_startinvoke(L);

    // static spine::SkeletonRenderer *create()
    spine::SkeletonRenderer *ret = spine::SkeletonRenderer::create();
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithData$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */
    bool arg2 = false;       /** ownsSkeletonData */

    olua_check_object(L, 1, &arg1, "spine.SkeletonData");
    olua_check_bool(L, 2, &arg2);

    // static spine::SkeletonRenderer *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = spine::SkeletonRenderer::createWithData(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");

    // insert code after call
    olua_addref(L, -1, "skeletonData", 1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithData$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */

    olua_check_object(L, 1, &arg1, "spine.SkeletonData");

    // static spine::SkeletonRenderer *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = spine::SkeletonRenderer::createWithData(arg1);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");

    // insert code after call
    olua_addref(L, -1, "skeletonData", 1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "spine.SkeletonData"))) {
            // static spine::SkeletonRenderer *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_createWithData$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "spine.SkeletonData")) && (olua_is_bool(L, 2))) {
            // static spine::SkeletonRenderer *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_createWithData$1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::createWithData' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_createWithFile$1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */
    float arg3 = 0;       /** scale */

    olua_check_string(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "spine.Atlas");
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonRenderer *ret = spine::SkeletonRenderer::createWithFile(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithFile$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */
    float arg3 = 0;       /** scale */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonRenderer *ret = spine::SkeletonRenderer::createWithFile(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithFile$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */

    olua_check_string(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "spine.Atlas");

    // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonRenderer *ret = spine::SkeletonRenderer::createWithFile(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithFile$4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonRenderer *ret = spine::SkeletonRenderer::createWithFile(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithFile(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "spine.Atlas"))) {
            // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_createWithFile$3(L);
        }

        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_createWithFile$4(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "spine.Atlas")) && (olua_is_number(L, 3))) {
            // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_createWithFile$1(L);
        }

        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_createWithFile$2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::createWithFile' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_createWithSkeleton$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */
    bool arg3 = false;       /** ownsSkeletonData */

    olua_check_object(L, 1, &arg1, "spine.Skeleton");
    olua_check_bool(L, 2, &arg2);
    olua_check_bool(L, 3, &arg3);

    // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = spine::SkeletonRenderer::createWithSkeleton(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithSkeleton$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */

    olua_check_object(L, 1, &arg1, "spine.Skeleton");

    // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = spine::SkeletonRenderer::createWithSkeleton(arg1);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithSkeleton$3(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */

    olua_check_object(L, 1, &arg1, "spine.Skeleton");
    olua_check_bool(L, 2, &arg2);

    // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = spine::SkeletonRenderer::createWithSkeleton(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithSkeleton(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "spine.Skeleton"))) {
            // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_createWithSkeleton$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "spine.Skeleton")) && (olua_is_bool(L, 2))) {
            // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_createWithSkeleton$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "spine.Skeleton")) && (olua_is_bool(L, 2)) && (olua_is_bool(L, 3))) {
            // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_createWithSkeleton$1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::createWithSkeleton' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_findBone(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** boneName */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);

    // spine::Bone *findBone(const std::string &boneName)
    spine::Bone *ret = self->findBone(arg1);
    int num_ret = olua_push_object(L, ret, "spine.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_findSlot(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** slotName */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);

    // spine::Slot *findSlot(const std::string &slotName)
    spine::Slot *ret = self->findSlot(arg1);
    int num_ret = olua_push_object(L, ret, "spine.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** slotName */
    std::string arg2;       /** attachmentName */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // spine::Attachment *getAttachment(const std::string &slotName, const std::string &attachmentName)
    spine::Attachment *ret = self->getAttachment(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // const cocos2d::BlendFunc &getBlendFunc()
    const cocos2d::BlendFunc &ret = self->getBlendFunc();
    int num_ret = olua_push_object(L, ret, "cc.BlendFunc");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getDebugBonesEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // bool getDebugBonesEnabled()
    bool ret = self->getDebugBonesEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getDebugBoundingRectEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // bool getDebugBoundingRectEnabled()
    bool ret = self->getDebugBoundingRectEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getDebugMeshesEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // bool getDebugMeshesEnabled()
    bool ret = self->getDebugMeshesEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getDebugSlotsEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // bool getDebugSlotsEnabled()
    bool ret = self->getDebugSlotsEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getSkeleton(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // spine::Skeleton *getSkeleton()
    spine::Skeleton *ret = self->getSkeleton();
    int num_ret = olua_push_object(L, ret, "spine.Skeleton");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // float getTimeScale()
    float ret = self->getTimeScale();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_initWithBinaryFile$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */
    float arg3 = 0;       /** scale */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "spine.Atlas");
    olua_check_number(L, 4, &arg3);

    // void initWithBinaryFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    self->initWithBinaryFile(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithBinaryFile$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */
    float arg3 = 0;       /** scale */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void initWithBinaryFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    self->initWithBinaryFile(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithBinaryFile$3(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "spine.Atlas");

    // void initWithBinaryFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    self->initWithBinaryFile(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithBinaryFile$4(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void initWithBinaryFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    self->initWithBinaryFile(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithBinaryFile(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        if ((olua_is_string(L, 2)) && (olua_is_object(L, 3, "spine.Atlas"))) {
            // void initWithBinaryFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_initWithBinaryFile$3(L);
        }

        // if ((olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // void initWithBinaryFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_initWithBinaryFile$4(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_string(L, 2)) && (olua_is_object(L, 3, "spine.Atlas")) && (olua_is_number(L, 4))) {
            // void initWithBinaryFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_initWithBinaryFile$1(L);
        }

        // if ((olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_number(L, 4))) {
            // void initWithBinaryFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_initWithBinaryFile$2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::initWithBinaryFile' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_initWithData$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */
    bool arg2 = false;       /** ownsSkeletonData */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_object(L, 2, &arg1, "spine.SkeletonData");
    olua_check_bool(L, 3, &arg2);

    // void initWithData(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    self->initWithData(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithData$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_object(L, 2, &arg1, "spine.SkeletonData");

    // void initWithData(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    self->initWithData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithData(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "spine.SkeletonData"))) {
            // void initWithData(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_initWithData$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 2, "spine.SkeletonData")) && (olua_is_bool(L, 3))) {
            // void initWithData(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_initWithData$1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::initWithData' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_initWithJsonFile$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */
    float arg3 = 0;       /** scale */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "spine.Atlas");
    olua_check_number(L, 4, &arg3);

    // void initWithJsonFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    self->initWithJsonFile(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithJsonFile$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */
    float arg3 = 0;       /** scale */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void initWithJsonFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    self->initWithJsonFile(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithJsonFile$3(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "spine.Atlas");

    // void initWithJsonFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    self->initWithJsonFile(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithJsonFile$4(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void initWithJsonFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    self->initWithJsonFile(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithJsonFile(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        if ((olua_is_string(L, 2)) && (olua_is_object(L, 3, "spine.Atlas"))) {
            // void initWithJsonFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_initWithJsonFile$3(L);
        }

        // if ((olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // void initWithJsonFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_initWithJsonFile$4(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_string(L, 2)) && (olua_is_object(L, 3, "spine.Atlas")) && (olua_is_number(L, 4))) {
            // void initWithJsonFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_initWithJsonFile$1(L);
        }

        // if ((olua_is_string(L, 2)) && (olua_is_string(L, 3)) && (olua_is_number(L, 4))) {
            // void initWithJsonFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_initWithJsonFile$2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::initWithJsonFile' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_initWithSkeleton$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */
    bool arg3 = false;       /** ownsSkeletonData */
    bool arg4 = false;       /** ownsAtlas */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_object(L, 2, &arg1, "spine.Skeleton");
    olua_check_bool(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);
    olua_check_bool(L, 5, &arg4);

    // void initWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    self->initWithSkeleton(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithSkeleton$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    spine::Skeleton *arg1 = nullptr;       /** skeleton */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_object(L, 2, &arg1, "spine.Skeleton");

    // void initWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    self->initWithSkeleton(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithSkeleton$3(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_object(L, 2, &arg1, "spine.Skeleton");
    olua_check_bool(L, 3, &arg2);

    // void initWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    self->initWithSkeleton(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithSkeleton$4(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */
    bool arg3 = false;       /** ownsSkeletonData */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_object(L, 2, &arg1, "spine.Skeleton");
    olua_check_bool(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // void initWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    self->initWithSkeleton(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_initWithSkeleton(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "spine.Skeleton"))) {
            // void initWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_initWithSkeleton$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 2, "spine.Skeleton")) && (olua_is_bool(L, 3))) {
            // void initWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_initWithSkeleton$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 2, "spine.Skeleton")) && (olua_is_bool(L, 3)) && (olua_is_bool(L, 4))) {
            // void initWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_initWithSkeleton$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 2, "spine.Skeleton")) && (olua_is_bool(L, 3)) && (olua_is_bool(L, 4)) && (olua_is_bool(L, 5))) {
            // void initWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_initWithSkeleton$1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::initWithSkeleton' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_initialize(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // void initialize()
    self->initialize();

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_isTwoColorTint(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // bool isTwoColorTint()
    bool ret = self->isTwoColorTint();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // SkeletonRenderer()
    spine::SkeletonRenderer *ret = new spine::SkeletonRenderer();
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */
    bool arg3 = false;       /** ownsSkeletonData */
    bool arg4 = false;       /** ownsAtlas */

    olua_check_object(L, 1, &arg1, "spine.Skeleton");
    olua_check_bool(L, 2, &arg2);
    olua_check_bool(L, 3, &arg3);
    olua_check_bool(L, 4, &arg4);

    // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    spine::SkeletonRenderer *ret = new spine::SkeletonRenderer(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new$3(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */
    bool arg2 = false;       /** ownsSkeletonData */

    olua_check_object(L, 1, &arg1, "spine.SkeletonData");
    olua_check_bool(L, 2, &arg2);

    // SkeletonRenderer(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = new spine::SkeletonRenderer(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new$4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */
    float arg3 = 0;       /** scale */

    olua_check_string(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "spine.Atlas");
    olua_check_number(L, 3, &arg3);

    // SkeletonRenderer(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonRenderer *ret = new spine::SkeletonRenderer(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new$5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */
    float arg3 = 0;       /** scale */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // SkeletonRenderer(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonRenderer *ret = new spine::SkeletonRenderer(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new$6(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */

    olua_check_object(L, 1, &arg1, "spine.Skeleton");

    // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    spine::SkeletonRenderer *ret = new spine::SkeletonRenderer(arg1);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new$7(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */

    olua_check_object(L, 1, &arg1, "spine.Skeleton");
    olua_check_bool(L, 2, &arg2);

    // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    spine::SkeletonRenderer *ret = new spine::SkeletonRenderer(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new$8(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */
    bool arg3 = false;       /** ownsSkeletonData */

    olua_check_object(L, 1, &arg1, "spine.Skeleton");
    olua_check_bool(L, 2, &arg2);
    olua_check_bool(L, 3, &arg3);

    // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    spine::SkeletonRenderer *ret = new spine::SkeletonRenderer(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new$9(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */

    olua_check_object(L, 1, &arg1, "spine.SkeletonData");

    // SkeletonRenderer(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = new spine::SkeletonRenderer(arg1);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new$10(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */

    olua_check_string(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "spine.Atlas");

    // SkeletonRenderer(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonRenderer *ret = new spine::SkeletonRenderer(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new$11(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // SkeletonRenderer(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonRenderer *ret = new spine::SkeletonRenderer(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // SkeletonRenderer()
        return _spine_SkeletonRenderer_new$1(L);
    }

    if (num_args == 1) {
        if ((olua_is_object(L, 1, "spine.Skeleton"))) {
            // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_new$6(L);
        }

        // if ((olua_is_object(L, 1, "spine.SkeletonData"))) {
            // SkeletonRenderer(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_new$9(L);
        // }
    }

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "spine.SkeletonData")) && (olua_is_bool(L, 2))) {
            // SkeletonRenderer(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_new$3(L);
        }

        if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "spine.Atlas"))) {
            // SkeletonRenderer(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_new$10(L);
        }

        if ((olua_is_object(L, 1, "spine.Skeleton")) && (olua_is_bool(L, 2))) {
            // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_new$7(L);
        }

        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // SkeletonRenderer(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_new$11(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "spine.Atlas")) && (olua_is_number(L, 3))) {
            // SkeletonRenderer(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_new$4(L);
        }

        if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // SkeletonRenderer(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_new$5(L);
        }

        // if ((olua_is_object(L, 1, "spine.Skeleton")) && (olua_is_bool(L, 2)) && (olua_is_bool(L, 3))) {
            // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_new$8(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "spine.Skeleton")) && (olua_is_bool(L, 2)) && (olua_is_bool(L, 3)) && (olua_is_bool(L, 4))) {
            // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_new$2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::new' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_setAttachment$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** slotName */
    std::string arg2;       /** attachmentName */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // bool setAttachment(const std::string &slotName, const std::string &attachmentName)
    bool ret = self->setAttachment(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_setAttachment$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** slotName */
    const char *arg2 = nullptr;       /** attachmentName */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // bool setAttachment(const std::string &slotName, const char *attachmentName)
    bool ret = self->setAttachment(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_setAttachment(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        if ((olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // bool setAttachment(const std::string &slotName, const std::string &attachmentName)
            return _spine_SkeletonRenderer_setAttachment$1(L);
        }

        // if ((olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // bool setAttachment(const std::string &slotName, const char *attachmentName)
            return _spine_SkeletonRenderer_setAttachment$2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::setAttachment' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_setBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    cocos2d::BlendFunc arg1;       /** blendFunc */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_object(L, 2, &arg1, "cc.BlendFunc");

    // void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    self->setBlendFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setBonesToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // void setBonesToSetupPose()
    self->setBonesToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setDebugBonesEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_bool(L, 2, &arg1);

    // void setDebugBonesEnabled(bool enabled)
    self->setDebugBonesEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setDebugBoundingRectEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_bool(L, 2, &arg1);

    // void setDebugBoundingRectEnabled(bool enabled)
    self->setDebugBoundingRectEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setDebugMeshesEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_bool(L, 2, &arg1);

    // void setDebugMeshesEnabled(bool enabled)
    self->setDebugMeshesEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setDebugSlotsEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_bool(L, 2, &arg1);

    // void setDebugSlotsEnabled(bool enabled)
    self->setDebugSlotsEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setSkin$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** skinName */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);

    // void setSkin(const std::string &skinName)
    self->setSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setSkin$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    const char *arg1 = nullptr;       /** skinName */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_string(L, 2, &arg1);

    // void setSkin(const char *skinName)
    self->setSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setSkin(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_string(L, 2))) {
            // void setSkin(const std::string &skinName)
            return _spine_SkeletonRenderer_setSkin$1(L);
        }

        // if ((olua_is_string(L, 2))) {
            // void setSkin(const char *skinName)
            return _spine_SkeletonRenderer_setSkin$2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::setSkin' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_setSlotsRange(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    int arg1 = 0;       /** startSlotIndex */
    int arg2 = 0;       /** endSlotIndex */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setSlotsRange(int startSlotIndex, int endSlotIndex)
    self->setSlotsRange(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setSlotsToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // void setSlotsToSetupPose()
    self->setSlotsToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    float arg1 = 0;       /** scale */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_number(L, 2, &arg1);

    // void setTimeScale(float scale)
    self->setTimeScale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // void setToSetupPose()
    self->setToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setTwoColorTint(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");
    olua_check_bool(L, 2, &arg1);

    // void setTwoColorTint(bool enabled)
    self->setTwoColorTint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_updateWorldTransform(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonRenderer");

    // void updateWorldTransform()
    self->updateWorldTransform();

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_SkeletonRenderer(lua_State *L)
{
    oluacls_class<spine::SkeletonRenderer, cocos2d::Node>(L, "spine.SkeletonRenderer");
    oluacls_func(L, "as", _spine_SkeletonRenderer_as);
    oluacls_func(L, "create", _spine_SkeletonRenderer_create);
    oluacls_func(L, "createWithData", _spine_SkeletonRenderer_createWithData);
    oluacls_func(L, "createWithFile", _spine_SkeletonRenderer_createWithFile);
    oluacls_func(L, "createWithSkeleton", _spine_SkeletonRenderer_createWithSkeleton);
    oluacls_func(L, "findBone", _spine_SkeletonRenderer_findBone);
    oluacls_func(L, "findSlot", _spine_SkeletonRenderer_findSlot);
    oluacls_func(L, "getAttachment", _spine_SkeletonRenderer_getAttachment);
    oluacls_func(L, "getBlendFunc", _spine_SkeletonRenderer_getBlendFunc);
    oluacls_func(L, "getDebugBonesEnabled", _spine_SkeletonRenderer_getDebugBonesEnabled);
    oluacls_func(L, "getDebugBoundingRectEnabled", _spine_SkeletonRenderer_getDebugBoundingRectEnabled);
    oluacls_func(L, "getDebugMeshesEnabled", _spine_SkeletonRenderer_getDebugMeshesEnabled);
    oluacls_func(L, "getDebugSlotsEnabled", _spine_SkeletonRenderer_getDebugSlotsEnabled);
    oluacls_func(L, "getSkeleton", _spine_SkeletonRenderer_getSkeleton);
    oluacls_func(L, "getTimeScale", _spine_SkeletonRenderer_getTimeScale);
    oluacls_func(L, "initWithBinaryFile", _spine_SkeletonRenderer_initWithBinaryFile);
    oluacls_func(L, "initWithData", _spine_SkeletonRenderer_initWithData);
    oluacls_func(L, "initWithJsonFile", _spine_SkeletonRenderer_initWithJsonFile);
    oluacls_func(L, "initWithSkeleton", _spine_SkeletonRenderer_initWithSkeleton);
    oluacls_func(L, "initialize", _spine_SkeletonRenderer_initialize);
    oluacls_func(L, "isTwoColorTint", _spine_SkeletonRenderer_isTwoColorTint);
    oluacls_func(L, "new", _spine_SkeletonRenderer_new);
    oluacls_func(L, "setAttachment", _spine_SkeletonRenderer_setAttachment);
    oluacls_func(L, "setBlendFunc", _spine_SkeletonRenderer_setBlendFunc);
    oluacls_func(L, "setBonesToSetupPose", _spine_SkeletonRenderer_setBonesToSetupPose);
    oluacls_func(L, "setDebugBonesEnabled", _spine_SkeletonRenderer_setDebugBonesEnabled);
    oluacls_func(L, "setDebugBoundingRectEnabled", _spine_SkeletonRenderer_setDebugBoundingRectEnabled);
    oluacls_func(L, "setDebugMeshesEnabled", _spine_SkeletonRenderer_setDebugMeshesEnabled);
    oluacls_func(L, "setDebugSlotsEnabled", _spine_SkeletonRenderer_setDebugSlotsEnabled);
    oluacls_func(L, "setSkin", _spine_SkeletonRenderer_setSkin);
    oluacls_func(L, "setSlotsRange", _spine_SkeletonRenderer_setSlotsRange);
    oluacls_func(L, "setSlotsToSetupPose", _spine_SkeletonRenderer_setSlotsToSetupPose);
    oluacls_func(L, "setTimeScale", _spine_SkeletonRenderer_setTimeScale);
    oluacls_func(L, "setToSetupPose", _spine_SkeletonRenderer_setToSetupPose);
    oluacls_func(L, "setTwoColorTint", _spine_SkeletonRenderer_setTwoColorTint);
    oluacls_func(L, "updateWorldTransform", _spine_SkeletonRenderer_updateWorldTransform);
    oluacls_prop(L, "blendFunc", _spine_SkeletonRenderer_getBlendFunc, _spine_SkeletonRenderer_setBlendFunc);
    oluacls_prop(L, "debugBonesEnabled", _spine_SkeletonRenderer_getDebugBonesEnabled, _spine_SkeletonRenderer_setDebugBonesEnabled);
    oluacls_prop(L, "debugBoundingRectEnabled", _spine_SkeletonRenderer_getDebugBoundingRectEnabled, _spine_SkeletonRenderer_setDebugBoundingRectEnabled);
    oluacls_prop(L, "debugMeshesEnabled", _spine_SkeletonRenderer_getDebugMeshesEnabled, _spine_SkeletonRenderer_setDebugMeshesEnabled);
    oluacls_prop(L, "debugSlotsEnabled", _spine_SkeletonRenderer_getDebugSlotsEnabled, _spine_SkeletonRenderer_setDebugSlotsEnabled);
    oluacls_prop(L, "skeleton", _spine_SkeletonRenderer_getSkeleton, nullptr);
    oluacls_prop(L, "timeScale", _spine_SkeletonRenderer_getTimeScale, _spine_SkeletonRenderer_setTimeScale);
    oluacls_prop(L, "twoColorTint", _spine_SkeletonRenderer_isTwoColorTint, _spine_SkeletonRenderer_setTwoColorTint);

    return 1;
}
OLUA_END_DECLS

static int _spine_StartListener___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (spine::StartListener *)nullptr, "spine.StartListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_StartListener(lua_State *L)
{
    oluacls_class<spine::StartListener>(L, "spine.StartListener");
    oluacls_func(L, "__call", _spine_StartListener___call);

    return 1;
}
OLUA_END_DECLS

static int _spine_InterruptListener___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (spine::InterruptListener *)nullptr, "spine.InterruptListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_InterruptListener(lua_State *L)
{
    oluacls_class<spine::InterruptListener>(L, "spine.InterruptListener");
    oluacls_func(L, "__call", _spine_InterruptListener___call);

    return 1;
}
OLUA_END_DECLS

static int _spine_EndListener___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (spine::EndListener *)nullptr, "spine.EndListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_EndListener(lua_State *L)
{
    oluacls_class<spine::EndListener>(L, "spine.EndListener");
    oluacls_func(L, "__call", _spine_EndListener___call);

    return 1;
}
OLUA_END_DECLS

static int _spine_DisposeListener___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (spine::DisposeListener *)nullptr, "spine.DisposeListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_DisposeListener(lua_State *L)
{
    oluacls_class<spine::DisposeListener>(L, "spine.DisposeListener");
    oluacls_func(L, "__call", _spine_DisposeListener___call);

    return 1;
}
OLUA_END_DECLS

static int _spine_CompleteListener___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (spine::CompleteListener *)nullptr, "spine.CompleteListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_CompleteListener(lua_State *L)
{
    oluacls_class<spine::CompleteListener>(L, "spine.CompleteListener");
    oluacls_func(L, "__call", _spine_CompleteListener___call);

    return 1;
}
OLUA_END_DECLS

static int _spine_EventListener___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (spine::EventListener *)nullptr, "spine.EventListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_EventListener(lua_State *L)
{
    oluacls_class<spine::EventListener>(L, "spine.EventListener");
    oluacls_func(L, "__call", _spine_EventListener___call);

    return 1;
}
OLUA_END_DECLS

static int _spine_UpdateWorldTransformsListener___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (spine::UpdateWorldTransformsListener *)nullptr, "spine.UpdateWorldTransformsListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_UpdateWorldTransformsListener(lua_State *L)
{
    oluacls_class<spine::UpdateWorldTransformsListener>(L, "spine.UpdateWorldTransformsListener");
    oluacls_func(L, "__call", _spine_UpdateWorldTransformsListener___call);

    return 1;
}
OLUA_END_DECLS

static int _spine_SkeletonAnimation_addAnimation$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    int arg1 = 0;       /** trackIndex */
    std::string arg2;       /** name */
    bool arg3 = false;       /** loop */
    float arg4 = 0;       /** delay */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_integer(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // @addref(trackEntries |) spine::TrackEntry *addAnimation(int trackIndex, const std::string &name, bool loop, @optional float delay)
    spine::TrackEntry *ret = self->addAnimation(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    // insert code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_FLAG_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_addAnimation$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    int arg1 = 0;       /** trackIndex */
    std::string arg2;       /** name */
    bool arg3 = false;       /** loop */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_integer(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // @addref(trackEntries |) spine::TrackEntry *addAnimation(int trackIndex, const std::string &name, bool loop, @optional float delay)
    spine::TrackEntry *ret = self->addAnimation(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    // insert code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_FLAG_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_addAnimation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        // if ((olua_is_integer(L, 2)) && (olua_is_string(L, 3)) && (olua_is_bool(L, 4))) {
            // @addref(trackEntries |) spine::TrackEntry *addAnimation(int trackIndex, const std::string &name, bool loop, @optional float delay)
            return _spine_SkeletonAnimation_addAnimation$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_integer(L, 2)) && (olua_is_string(L, 3)) && (olua_is_bool(L, 4)) && (olua_is_number(L, 5))) {
            // @addref(trackEntries |) spine::TrackEntry *addAnimation(int trackIndex, const std::string &name, bool loop, @optional float delay)
            return _spine_SkeletonAnimation_addAnimation$1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::addAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_addEmptyAnimation$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    int arg1 = 0;       /** trackIndex */
    float arg2 = 0;       /** mixDuration */
    float arg3 = 0;       /** delay */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_integer(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // @addref(trackEntries |) spine::TrackEntry *addEmptyAnimation(int trackIndex, float mixDuration, @optional float delay)
    spine::TrackEntry *ret = self->addEmptyAnimation(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    // insert code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_FLAG_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_addEmptyAnimation$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    int arg1 = 0;       /** trackIndex */
    float arg2 = 0;       /** mixDuration */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_integer(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // @addref(trackEntries |) spine::TrackEntry *addEmptyAnimation(int trackIndex, float mixDuration, @optional float delay)
    spine::TrackEntry *ret = self->addEmptyAnimation(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    // insert code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_FLAG_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_addEmptyAnimation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_number(L, 3))) {
            // @addref(trackEntries |) spine::TrackEntry *addEmptyAnimation(int trackIndex, float mixDuration, @optional float delay)
            return _spine_SkeletonAnimation_addEmptyAnimation$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_integer(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // @addref(trackEntries |) spine::TrackEntry *addEmptyAnimation(int trackIndex, float mixDuration, @optional float delay)
            return _spine_SkeletonAnimation_addEmptyAnimation$1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::addEmptyAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_clearTrack$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    int arg1 = 0;       /** trackIndex */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_integer(L, 2, &arg1);

    // void clearTrack(@optional int trackIndex)
    self->clearTrack(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_clearTrack$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");

    // void clearTrack(@optional int trackIndex)
    self->clearTrack();

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_clearTrack(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void clearTrack(@optional int trackIndex)
        return _spine_SkeletonAnimation_clearTrack$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // void clearTrack(@optional int trackIndex)
            return _spine_SkeletonAnimation_clearTrack$1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::clearTrack' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_clearTracks(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");

    // void clearTracks()
    self->clearTracks();

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_create(lua_State *L)
{
    olua_startinvoke(L);

    // static spine::SkeletonAnimation *create()
    spine::SkeletonAnimation *ret = spine::SkeletonAnimation::create();
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithBinaryFile$1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonBinaryFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */
    float arg3 = 0;       /** scale */

    olua_check_string(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "spine.Atlas");
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonAnimation *ret = spine::SkeletonAnimation::createWithBinaryFile(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithBinaryFile$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonBinaryFile */
    std::string arg2;       /** atlasFile */
    float arg3 = 0;       /** scale */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonAnimation *ret = spine::SkeletonAnimation::createWithBinaryFile(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithBinaryFile$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonBinaryFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */

    olua_check_string(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "spine.Atlas");

    // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonAnimation *ret = spine::SkeletonAnimation::createWithBinaryFile(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithBinaryFile$4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonBinaryFile */
    std::string arg2;       /** atlasFile */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonAnimation *ret = spine::SkeletonAnimation::createWithBinaryFile(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithBinaryFile(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "spine.Atlas"))) {
            // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonAnimation_createWithBinaryFile$3(L);
        }

        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonAnimation_createWithBinaryFile$4(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "spine.Atlas")) && (olua_is_number(L, 3))) {
            // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonAnimation_createWithBinaryFile$1(L);
        }

        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonAnimation_createWithBinaryFile$2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::createWithBinaryFile' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_createWithData$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */
    bool arg2 = false;       /** ownsSkeletonData */

    olua_check_object(L, 1, &arg1, "spine.SkeletonData");
    olua_check_bool(L, 2, &arg2);

    // static spine::SkeletonAnimation *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonAnimation *ret = spine::SkeletonAnimation::createWithData(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");

    // insert code after call
    olua_addref(L, -1, "skeletonData", 1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithData$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */

    olua_check_object(L, 1, &arg1, "spine.SkeletonData");

    // static spine::SkeletonAnimation *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonAnimation *ret = spine::SkeletonAnimation::createWithData(arg1);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");

    // insert code after call
    olua_addref(L, -1, "skeletonData", 1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "spine.SkeletonData"))) {
            // static spine::SkeletonAnimation *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonAnimation_createWithData$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "spine.SkeletonData")) && (olua_is_bool(L, 2))) {
            // static spine::SkeletonAnimation *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonAnimation_createWithData$1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::createWithData' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_createWithJsonFile$1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonJsonFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */
    float arg3 = 0;       /** scale */

    olua_check_string(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "spine.Atlas");
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonAnimation *ret = spine::SkeletonAnimation::createWithJsonFile(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithJsonFile$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonJsonFile */
    std::string arg2;       /** atlasFile */
    float arg3 = 0;       /** scale */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonAnimation *ret = spine::SkeletonAnimation::createWithJsonFile(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithJsonFile$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonJsonFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */

    olua_check_string(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "spine.Atlas");

    // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonAnimation *ret = spine::SkeletonAnimation::createWithJsonFile(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithJsonFile$4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonJsonFile */
    std::string arg2;       /** atlasFile */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonAnimation *ret = spine::SkeletonAnimation::createWithJsonFile(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithJsonFile(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "spine.Atlas"))) {
            // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonAnimation_createWithJsonFile$3(L);
        }

        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonAnimation_createWithJsonFile$4(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "spine.Atlas")) && (olua_is_number(L, 3))) {
            // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonAnimation_createWithJsonFile$1(L);
        }

        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_number(L, 3))) {
            // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonAnimation_createWithJsonFile$2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::createWithJsonFile' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_findAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_string(L, 2, &arg1);

    // spine::Animation *findAnimation(const std::string &name)
    spine::Animation *ret = self->findAnimation(arg1);
    int num_ret = olua_push_object(L, ret, "spine.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_getCurrent$1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    int arg1 = 0;       /** trackIndex */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_integer(L, 2, &arg1);

    // @addref(trackEntries |) spine::TrackEntry *getCurrent(@optional int trackIndex)
    spine::TrackEntry *ret = self->getCurrent(arg1);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    // insert code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_FLAG_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_getCurrent$2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");

    // @addref(trackEntries |) spine::TrackEntry *getCurrent(@optional int trackIndex)
    spine::TrackEntry *ret = self->getCurrent();
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    // insert code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_FLAG_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_getCurrent(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @addref(trackEntries |) spine::TrackEntry *getCurrent(@optional int trackIndex)
        return _spine_SkeletonAnimation_getCurrent$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // @addref(trackEntries |) spine::TrackEntry *getCurrent(@optional int trackIndex)
            return _spine_SkeletonAnimation_getCurrent$1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::getCurrent' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_getState(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");

    // @addref(state ^) spine::AnimationState *getState()
    spine::AnimationState *ret = self->getState();
    int num_ret = olua_push_object(L, ret, "spine.AnimationState");

    // insert code after call
    olua_addref(L, 1, "state", -1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_new(lua_State *L)
{
    olua_startinvoke(L);

    // SkeletonAnimation()
    spine::SkeletonAnimation *ret = new spine::SkeletonAnimation();
    int num_ret = olua_push_object(L, ret, "spine.SkeletonAnimation");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_onAnimationStateEvent(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    spine::EventType arg2 = (spine::EventType)0;       /** type */
    spine::Event *arg3 = nullptr;       /** event */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_object(L, 2, &arg1, "spine.TrackEntry");
    olua_check_enum(L, 3, &arg2);
    olua_check_object(L, 4, &arg3, "spine.Event");

    // void onAnimationStateEvent(spine::TrackEntry *entry, spine::EventType type, spine::Event *event)
    self->onAnimationStateEvent(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_onTrackEntryEvent(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    spine::EventType arg2 = (spine::EventType)0;       /** type */
    spine::Event *arg3 = nullptr;       /** event */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_object(L, 2, &arg1, "spine.TrackEntry");
    olua_check_enum(L, 3, &arg2);
    olua_check_object(L, 4, &arg3, "spine.Event");

    // void onTrackEntryEvent(spine::TrackEntry *entry, spine::EventType type, spine::Event *event)
    self->onTrackEntryEvent(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    int arg1 = 0;       /** trackIndex */
    std::string arg2;       /** name */
    bool arg3 = false;       /** loop */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_integer(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // @addref(trackEntries |) spine::TrackEntry *setAnimation(int trackIndex, const std::string &name, bool loop)
    spine::TrackEntry *ret = self->setAnimation(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    // insert code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_FLAG_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_setAnimationStateData(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::AnimationStateData *arg1 = nullptr;       /** stateData */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_object(L, 2, &arg1, "spine.AnimationStateData");

    // void setAnimationStateData(spine::AnimationStateData *stateData)
    self->setAnimationStateData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setCompleteListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::CompleteListener arg1;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_callback(L, 2, &arg1, "spine.CompleteListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "CompleteListener";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setCompleteListener(const spine::CompleteListener &listener)
    self->setCompleteListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setDisposeListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::DisposeListener arg1;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_callback(L, 2, &arg1, "spine.DisposeListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "DisposeListener";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setDisposeListener(const spine::DisposeListener &listener)
    self->setDisposeListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setEmptyAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    int arg1 = 0;       /** trackIndex */
    float arg2 = 0;       /** mixDuration */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_integer(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // @addref(trackEntries |) spine::TrackEntry *setEmptyAnimation(int trackIndex, float mixDuration)
    spine::TrackEntry *ret = self->setEmptyAnimation(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "spine.TrackEntry");

    // insert code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_FLAG_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_setEmptyAnimations(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    float arg1 = 0;       /** mixDuration */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_number(L, 2, &arg1);

    // void setEmptyAnimations(float mixDuration)
    self->setEmptyAnimations(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setEndListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::EndListener arg1;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_callback(L, 2, &arg1, "spine.EndListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "EndListener";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setEndListener(const spine::EndListener &listener)
    self->setEndListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setEventListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::EventListener arg1;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_callback(L, 2, &arg1, "spine.EventListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "EventListener";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1, spine::Event *arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");
            olua_push_object(L, arg2, "spine.Event");

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void setEventListener(const spine::EventListener &listener)
    self->setEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setInterruptListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::InterruptListener arg1;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_callback(L, 2, &arg1, "spine.InterruptListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "InterruptListener";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setInterruptListener(const spine::InterruptListener &listener)
    self->setInterruptListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    std::string arg1;       /** fromAnimation */
    std::string arg2;       /** toAnimation */
    float arg3 = 0;       /** duration */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void setMix(const std::string &fromAnimation, const std::string &toAnimation, float duration)
    self->setMix(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setPostUpdateWorldTransformsListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::UpdateWorldTransformsListener arg1;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_callback(L, 2, &arg1, "spine.UpdateWorldTransformsListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "PostUpdateWorldTransformsListener";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](spine::SkeletonAnimation *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_object(L, arg1, "spine.SkeletonAnimation");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void setPostUpdateWorldTransformsListener(@localvar const spine::UpdateWorldTransformsListener &listener)
    self->setPostUpdateWorldTransformsListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setPreUpdateWorldTransformsListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::UpdateWorldTransformsListener arg1;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_callback(L, 2, &arg1, "spine.UpdateWorldTransformsListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "PreUpdateWorldTransformsListener";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](spine::SkeletonAnimation *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_object(L, arg1, "spine.SkeletonAnimation");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void setPreUpdateWorldTransformsListener(@localvar const spine::UpdateWorldTransformsListener &listener)
    self->setPreUpdateWorldTransformsListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setStartListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::StartListener arg1;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_callback(L, 2, &arg1, "spine.StartListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "StartListener";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setStartListener(const spine::StartListener &listener)
    self->setStartListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackCompleteListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    spine::CompleteListener arg2;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_object(L, 2, &arg1, "spine.TrackEntry");
    olua_check_callback(L, 3, &arg2, "spine.CompleteListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "TrackCompleteListener";
    std::string cb_name = olua_setcallback(L, cb_store,  3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setTrackCompleteListener(spine::TrackEntry *entry, const spine::CompleteListener &listener)
    self->setTrackCompleteListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackDisposeListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    spine::DisposeListener arg2;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_object(L, 2, &arg1, "spine.TrackEntry");
    olua_check_callback(L, 3, &arg2, "spine.DisposeListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "TrackDisposeListener";
    std::string cb_name = olua_setcallback(L, cb_store,  3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setTrackDisposeListener(spine::TrackEntry *entry, const spine::DisposeListener &listener)
    self->setTrackDisposeListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackEndListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    spine::EndListener arg2;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_object(L, 2, &arg1, "spine.TrackEntry");
    olua_check_callback(L, 3, &arg2, "spine.EndListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "TrackEndListener";
    std::string cb_name = olua_setcallback(L, cb_store,  3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setTrackEndListener(spine::TrackEntry *entry, const spine::EndListener &listener)
    self->setTrackEndListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackEventListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    spine::EventListener arg2;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_object(L, 2, &arg1, "spine.TrackEntry");
    olua_check_callback(L, 3, &arg2, "spine.EventListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "TrackEventListener";
    std::string cb_name = olua_setcallback(L, cb_store,  3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1, spine::Event *arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");
            olua_push_object(L, arg2, "spine.Event");

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void setTrackEventListener(spine::TrackEntry *entry, const spine::EventListener &listener)
    self->setTrackEventListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackInterruptListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    spine::InterruptListener arg2;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_object(L, 2, &arg1, "spine.TrackEntry");
    olua_check_callback(L, 3, &arg2, "spine.InterruptListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "TrackInterruptListener";
    std::string cb_name = olua_setcallback(L, cb_store,  3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setTrackInterruptListener(spine::TrackEntry *entry, const spine::InterruptListener &listener)
    self->setTrackInterruptListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackStartListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    spine::StartListener arg2;       /** listener */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_object(L, 2, &arg1, "spine.TrackEntry");
    olua_check_callback(L, 3, &arg2, "spine.StartListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "TrackStartListener";
    std::string cb_name = olua_setcallback(L, cb_store,  3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_object(L, arg1, "spine.TrackEntry");

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setTrackStartListener(spine::TrackEntry *entry, const spine::StartListener &listener)
    self->setTrackStartListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setUpdateOnlyIfVisible(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    bool arg1 = false;       /** status */

    olua_to_object(L, 1, &self, "spine.SkeletonAnimation");
    olua_check_bool(L, 2, &arg1);

    // void setUpdateOnlyIfVisible(bool status)
    self->setUpdateOnlyIfVisible(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine_SkeletonAnimation(lua_State *L)
{
    oluacls_class<spine::SkeletonAnimation, spine::SkeletonRenderer>(L, "spine.SkeletonAnimation");
    oluacls_func(L, "addAnimation", _spine_SkeletonAnimation_addAnimation);
    oluacls_func(L, "addEmptyAnimation", _spine_SkeletonAnimation_addEmptyAnimation);
    oluacls_func(L, "clearTrack", _spine_SkeletonAnimation_clearTrack);
    oluacls_func(L, "clearTracks", _spine_SkeletonAnimation_clearTracks);
    oluacls_func(L, "create", _spine_SkeletonAnimation_create);
    oluacls_func(L, "createWithBinaryFile", _spine_SkeletonAnimation_createWithBinaryFile);
    oluacls_func(L, "createWithData", _spine_SkeletonAnimation_createWithData);
    oluacls_func(L, "createWithJsonFile", _spine_SkeletonAnimation_createWithJsonFile);
    oluacls_func(L, "findAnimation", _spine_SkeletonAnimation_findAnimation);
    oluacls_func(L, "getCurrent", _spine_SkeletonAnimation_getCurrent);
    oluacls_func(L, "getState", _spine_SkeletonAnimation_getState);
    oluacls_func(L, "new", _spine_SkeletonAnimation_new);
    oluacls_func(L, "onAnimationStateEvent", _spine_SkeletonAnimation_onAnimationStateEvent);
    oluacls_func(L, "onTrackEntryEvent", _spine_SkeletonAnimation_onTrackEntryEvent);
    oluacls_func(L, "setAnimation", _spine_SkeletonAnimation_setAnimation);
    oluacls_func(L, "setAnimationStateData", _spine_SkeletonAnimation_setAnimationStateData);
    oluacls_func(L, "setCompleteListener", _spine_SkeletonAnimation_setCompleteListener);
    oluacls_func(L, "setDisposeListener", _spine_SkeletonAnimation_setDisposeListener);
    oluacls_func(L, "setEmptyAnimation", _spine_SkeletonAnimation_setEmptyAnimation);
    oluacls_func(L, "setEmptyAnimations", _spine_SkeletonAnimation_setEmptyAnimations);
    oluacls_func(L, "setEndListener", _spine_SkeletonAnimation_setEndListener);
    oluacls_func(L, "setEventListener", _spine_SkeletonAnimation_setEventListener);
    oluacls_func(L, "setInterruptListener", _spine_SkeletonAnimation_setInterruptListener);
    oluacls_func(L, "setMix", _spine_SkeletonAnimation_setMix);
    oluacls_func(L, "setPostUpdateWorldTransformsListener", _spine_SkeletonAnimation_setPostUpdateWorldTransformsListener);
    oluacls_func(L, "setPreUpdateWorldTransformsListener", _spine_SkeletonAnimation_setPreUpdateWorldTransformsListener);
    oluacls_func(L, "setStartListener", _spine_SkeletonAnimation_setStartListener);
    oluacls_func(L, "setTrackCompleteListener", _spine_SkeletonAnimation_setTrackCompleteListener);
    oluacls_func(L, "setTrackDisposeListener", _spine_SkeletonAnimation_setTrackDisposeListener);
    oluacls_func(L, "setTrackEndListener", _spine_SkeletonAnimation_setTrackEndListener);
    oluacls_func(L, "setTrackEventListener", _spine_SkeletonAnimation_setTrackEventListener);
    oluacls_func(L, "setTrackInterruptListener", _spine_SkeletonAnimation_setTrackInterruptListener);
    oluacls_func(L, "setTrackStartListener", _spine_SkeletonAnimation_setTrackStartListener);
    oluacls_func(L, "setUpdateOnlyIfVisible", _spine_SkeletonAnimation_setUpdateOnlyIfVisible);
    oluacls_prop(L, "state", _spine_SkeletonAnimation_getState, nullptr);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_spine(lua_State *L)
{
    olua_require(L, "spine.EventType", luaopen_spine_EventType);
    olua_require(L, "spine.AttachmentType", luaopen_spine_AttachmentType);
    olua_require(L, "spine.TransformMode", luaopen_spine_TransformMode);
    olua_require(L, "spine.BlendMode", luaopen_spine_BlendMode);
    olua_require(L, "spine.PositionMode", luaopen_spine_PositionMode);
    olua_require(L, "spine.SpacingMode", luaopen_spine_SpacingMode);
    olua_require(L, "spine.RotateMode", luaopen_spine_RotateMode);
    olua_require(L, "spine.MixBlend", luaopen_spine_MixBlend);
    olua_require(L, "spine.MixDirection", luaopen_spine_MixDirection);
    olua_require(L, "spine.SpineObject", luaopen_spine_SpineObject);
    olua_require(L, "spine.Event", luaopen_spine_Event);
    olua_require(L, "spine.EventData", luaopen_spine_EventData);
    olua_require(L, "spine.Updatable", luaopen_spine_Updatable);
    olua_require(L, "spine.AnimationStateListener", luaopen_spine_AnimationStateListener);
    olua_require(L, "spine.AnimationState", luaopen_spine_AnimationState);
    olua_require(L, "spine.AnimationStateData", luaopen_spine_AnimationStateData);
    olua_require(L, "spine.Animation", luaopen_spine_Animation);
    olua_require(L, "spine.Sequence", luaopen_spine_Sequence);
    olua_require(L, "spine.SequenceMode", luaopen_spine_SequenceMode);
    olua_require(L, "spine.TextureRegion", luaopen_spine_TextureRegion);
    olua_require(L, "spine.ConstraintData", luaopen_spine_ConstraintData);
    olua_require(L, "spine.IkConstraintData", luaopen_spine_IkConstraintData);
    olua_require(L, "spine.BoneData", luaopen_spine_BoneData);
    olua_require(L, "spine.SlotData", luaopen_spine_SlotData);
    olua_require(L, "spine.IkConstraint", luaopen_spine_IkConstraint);
    olua_require(L, "spine.TransformConstraint", luaopen_spine_TransformConstraint);
    olua_require(L, "spine.TransformConstraintData", luaopen_spine_TransformConstraintData);
    olua_require(L, "spine.PathConstraintData", luaopen_spine_PathConstraintData);
    olua_require(L, "spine.SkeletonBounds", luaopen_spine_SkeletonBounds);
    olua_require(L, "spine.SkeletonClipping", luaopen_spine_SkeletonClipping);
    olua_require(L, "spine.Timeline", luaopen_spine_Timeline);
    olua_require(L, "spine.CurveTimeline", luaopen_spine_CurveTimeline);
    olua_require(L, "spine.CurveTimeline1", luaopen_spine_CurveTimeline1);
    olua_require(L, "spine.CurveTimeline2", luaopen_spine_CurveTimeline2);
    olua_require(L, "spine.AttachmentTimeline", luaopen_spine_AttachmentTimeline);
    olua_require(L, "spine.RGBATimeline", luaopen_spine_RGBATimeline);
    olua_require(L, "spine.RGBTimeline", luaopen_spine_RGBTimeline);
    olua_require(L, "spine.AlphaTimeline", luaopen_spine_AlphaTimeline);
    olua_require(L, "spine.RGBA2Timeline", luaopen_spine_RGBA2Timeline);
    olua_require(L, "spine.RGB2Timeline", luaopen_spine_RGB2Timeline);
    olua_require(L, "spine.DeformTimeline", luaopen_spine_DeformTimeline);
    olua_require(L, "spine.DrawOrderTimeline", luaopen_spine_DrawOrderTimeline);
    olua_require(L, "spine.EventTimeline", luaopen_spine_EventTimeline);
    olua_require(L, "spine.ScaleXTimeline", luaopen_spine_ScaleXTimeline);
    olua_require(L, "spine.ScaleYTimeline", luaopen_spine_ScaleYTimeline);
    olua_require(L, "spine.ShearXTimeline", luaopen_spine_ShearXTimeline);
    olua_require(L, "spine.ShearYTimeline", luaopen_spine_ShearYTimeline);
    olua_require(L, "spine.TranslateXTimeline", luaopen_spine_TranslateXTimeline);
    olua_require(L, "spine.TranslateYTimeline", luaopen_spine_TranslateYTimeline);
    olua_require(L, "spine.IkConstraintTimeline", luaopen_spine_IkConstraintTimeline);
    olua_require(L, "spine.PathConstraintMixTimeline", luaopen_spine_PathConstraintMixTimeline);
    olua_require(L, "spine.PathConstraintPositionTimeline", luaopen_spine_PathConstraintPositionTimeline);
    olua_require(L, "spine.PathConstraintSpacingTimeline", luaopen_spine_PathConstraintSpacingTimeline);
    olua_require(L, "spine.TranslateTimeline", luaopen_spine_TranslateTimeline);
    olua_require(L, "spine.ShearTimeline", luaopen_spine_ShearTimeline);
    olua_require(L, "spine.TransformConstraintTimeline", luaopen_spine_TransformConstraintTimeline);
    olua_require(L, "spine.ScaleTimeline", luaopen_spine_ScaleTimeline);
    olua_require(L, "spine.RotateTimeline", luaopen_spine_RotateTimeline);
    olua_require(L, "spine.Polygon", luaopen_spine_Polygon);
    olua_require(L, "spine.Skin", luaopen_spine_Skin);
    olua_require(L, "spine.Atlas", luaopen_spine_Atlas);
    olua_require(L, "spine.Bone", luaopen_spine_Bone);
    olua_require(L, "spine.Slot", luaopen_spine_Slot);
    olua_require(L, "spine.Attachment", luaopen_spine_Attachment);
    olua_require(L, "spine.VertexAttachment", luaopen_spine_VertexAttachment);
    olua_require(L, "spine.ClippingAttachment", luaopen_spine_ClippingAttachment);
    olua_require(L, "spine.BoundingBoxAttachment", luaopen_spine_BoundingBoxAttachment);
    olua_require(L, "spine.MeshAttachment", luaopen_spine_MeshAttachment);
    olua_require(L, "spine.PathAttachment", luaopen_spine_PathAttachment);
    olua_require(L, "spine.PathConstraint", luaopen_spine_PathConstraint);
    olua_require(L, "spine.PointAttachment", luaopen_spine_PointAttachment);
    olua_require(L, "spine.RegionAttachment", luaopen_spine_RegionAttachment);
    olua_require(L, "spine.TrackEntry", luaopen_spine_TrackEntry);
    olua_require(L, "spine.SkeletonData", luaopen_spine_SkeletonData);
    olua_require(L, "spine.Skeleton", luaopen_spine_Skeleton);
    olua_require(L, "spine.SkeletonRenderer", luaopen_spine_SkeletonRenderer);
    olua_require(L, "spine.StartListener", luaopen_spine_StartListener);
    olua_require(L, "spine.InterruptListener", luaopen_spine_InterruptListener);
    olua_require(L, "spine.EndListener", luaopen_spine_EndListener);
    olua_require(L, "spine.DisposeListener", luaopen_spine_DisposeListener);
    olua_require(L, "spine.CompleteListener", luaopen_spine_CompleteListener);
    olua_require(L, "spine.EventListener", luaopen_spine_EventListener);
    olua_require(L, "spine.UpdateWorldTransformsListener", luaopen_spine_UpdateWorldTransformsListener);
    olua_require(L, "spine.SkeletonAnimation", luaopen_spine_SkeletonAnimation);

    cclua::runtime::registerFeature("spine", true);

    return 0;
}
OLUA_END_DECLS
