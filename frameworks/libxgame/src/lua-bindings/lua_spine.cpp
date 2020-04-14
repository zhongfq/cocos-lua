//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua-bindings/lua_cocos2d_ui.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "cocos2d.h"
#include "spine/spine-cocos2dx.h"

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
    for (int i = 0; i < v.size(); i++) {
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
    size_t total = lua_rawlen(L, idx);
    v.ensureCapacity(total);
    for (int i = 1; i <= total; i++) {
        lua_rawgeti(L, idx, i);
        T* obj;
        olua_check_cppobj(L, -1, (void **)&obj, cls);
        v.add(obj);
        lua_pop(L, 1);
    }
}

static int luaopen_spine_EventType(lua_State *L)
{
    oluacls_class(L, "sp.EventType", nullptr);
    oluacls_const_integer(L, "EventType_Complete", (lua_Integer)spine::EventType::EventType_Complete);
    oluacls_const_integer(L, "EventType_Dispose", (lua_Integer)spine::EventType::EventType_Dispose);
    oluacls_const_integer(L, "EventType_End", (lua_Integer)spine::EventType::EventType_End);
    oluacls_const_integer(L, "EventType_Event", (lua_Integer)spine::EventType::EventType_Event);
    oluacls_const_integer(L, "EventType_Interrupt", (lua_Integer)spine::EventType::EventType_Interrupt);
    oluacls_const_integer(L, "EventType_Start", (lua_Integer)spine::EventType::EventType_Start);

    olua_registerluatype<spine::EventType>(L, "sp.EventType");

    return 1;
}

static int luaopen_spine_AttachmentType(lua_State *L)
{
    oluacls_class(L, "sp.AttachmentType", nullptr);
    oluacls_const_integer(L, "AttachmentType_Boundingbox", (lua_Integer)spine::AttachmentType::AttachmentType_Boundingbox);
    oluacls_const_integer(L, "AttachmentType_Clipping", (lua_Integer)spine::AttachmentType::AttachmentType_Clipping);
    oluacls_const_integer(L, "AttachmentType_Linkedmesh", (lua_Integer)spine::AttachmentType::AttachmentType_Linkedmesh);
    oluacls_const_integer(L, "AttachmentType_Mesh", (lua_Integer)spine::AttachmentType::AttachmentType_Mesh);
    oluacls_const_integer(L, "AttachmentType_Path", (lua_Integer)spine::AttachmentType::AttachmentType_Path);
    oluacls_const_integer(L, "AttachmentType_Point", (lua_Integer)spine::AttachmentType::AttachmentType_Point);
    oluacls_const_integer(L, "AttachmentType_Region", (lua_Integer)spine::AttachmentType::AttachmentType_Region);

    olua_registerluatype<spine::AttachmentType>(L, "sp.AttachmentType");

    return 1;
}

static int luaopen_spine_TransformMode(lua_State *L)
{
    oluacls_class(L, "sp.TransformMode", nullptr);
    oluacls_const_integer(L, "TransformMode_NoRotationOrReflection", (lua_Integer)spine::TransformMode::TransformMode_NoRotationOrReflection);
    oluacls_const_integer(L, "TransformMode_NoScale", (lua_Integer)spine::TransformMode::TransformMode_NoScale);
    oluacls_const_integer(L, "TransformMode_NoScaleOrReflection", (lua_Integer)spine::TransformMode::TransformMode_NoScaleOrReflection);
    oluacls_const_integer(L, "TransformMode_Normal", (lua_Integer)spine::TransformMode::TransformMode_Normal);
    oluacls_const_integer(L, "TransformMode_OnlyTranslation", (lua_Integer)spine::TransformMode::TransformMode_OnlyTranslation);

    olua_registerluatype<spine::TransformMode>(L, "sp.TransformMode");

    return 1;
}

static int luaopen_spine_BlendMode(lua_State *L)
{
    oluacls_class(L, "sp.BlendMode", nullptr);
    oluacls_const_integer(L, "BlendMode_Additive", (lua_Integer)spine::BlendMode::BlendMode_Additive);
    oluacls_const_integer(L, "BlendMode_Multiply", (lua_Integer)spine::BlendMode::BlendMode_Multiply);
    oluacls_const_integer(L, "BlendMode_Normal", (lua_Integer)spine::BlendMode::BlendMode_Normal);
    oluacls_const_integer(L, "BlendMode_Screen", (lua_Integer)spine::BlendMode::BlendMode_Screen);

    olua_registerluatype<spine::BlendMode>(L, "sp.BlendMode");

    return 1;
}

static int luaopen_spine_PositionMode(lua_State *L)
{
    oluacls_class(L, "sp.PositionMode", nullptr);
    oluacls_const_integer(L, "PositionMode_Fixed", (lua_Integer)spine::PositionMode::PositionMode_Fixed);
    oluacls_const_integer(L, "PositionMode_Percent", (lua_Integer)spine::PositionMode::PositionMode_Percent);

    olua_registerluatype<spine::PositionMode>(L, "sp.PositionMode");

    return 1;
}

static int luaopen_spine_SpacingMode(lua_State *L)
{
    oluacls_class(L, "sp.SpacingMode", nullptr);
    oluacls_const_integer(L, "SpacingMode_Fixed", (lua_Integer)spine::SpacingMode::SpacingMode_Fixed);
    oluacls_const_integer(L, "SpacingMode_Length", (lua_Integer)spine::SpacingMode::SpacingMode_Length);
    oluacls_const_integer(L, "SpacingMode_Percent", (lua_Integer)spine::SpacingMode::SpacingMode_Percent);

    olua_registerluatype<spine::SpacingMode>(L, "sp.SpacingMode");

    return 1;
}

static int luaopen_spine_RotateMode(lua_State *L)
{
    oluacls_class(L, "sp.RotateMode", nullptr);
    oluacls_const_integer(L, "RotateMode_Chain", (lua_Integer)spine::RotateMode::RotateMode_Chain);
    oluacls_const_integer(L, "RotateMode_ChainScale", (lua_Integer)spine::RotateMode::RotateMode_ChainScale);
    oluacls_const_integer(L, "RotateMode_Tangent", (lua_Integer)spine::RotateMode::RotateMode_Tangent);

    olua_registerluatype<spine::RotateMode>(L, "sp.RotateMode");

    return 1;
}

static int luaopen_spine_MixBlend(lua_State *L)
{
    oluacls_class(L, "sp.MixBlend", nullptr);
    oluacls_const_integer(L, "MixBlend_Add", (lua_Integer)spine::MixBlend::MixBlend_Add);
    oluacls_const_integer(L, "MixBlend_First", (lua_Integer)spine::MixBlend::MixBlend_First);
    oluacls_const_integer(L, "MixBlend_Replace", (lua_Integer)spine::MixBlend::MixBlend_Replace);
    oluacls_const_integer(L, "MixBlend_Setup", (lua_Integer)spine::MixBlend::MixBlend_Setup);

    olua_registerluatype<spine::MixBlend>(L, "sp.MixBlend");

    return 1;
}

static int _spine_SpineObject___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::SpineObject *)olua_toobj(L, 1, "sp.SpineObject");
    olua_push_cppobj(L, self, "sp.SpineObject");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_spine_SpineObject(lua_State *L)
{
    oluacls_class(L, "sp.SpineObject", nullptr);
    oluacls_func(L, "__move", _spine_SpineObject___move);

    olua_registerluatype<spine::SpineObject>(L, "sp.SpineObject");

    return 1;
}

static int _spine_Event___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Event *)olua_toobj(L, 1, "sp.Event");
    olua_push_cppobj(L, self, "sp.Event");

    olua_endinvoke(L);

    return 1;
}

static int _spine_Event_getBalance(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");

    // float getBalance()
    float ret = (float)self->getBalance();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getData(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");

    // const spine::EventData &getData()
    const spine::EventData &ret = (const spine::EventData &)self->getData();
    int num_ret = manual_olua_push_spine_EventData(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getFloatValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");

    // float getFloatValue()
    float ret = (float)self->getFloatValue();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getIntValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");

    // int getIntValue()
    int ret = (int)self->getIntValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getStringValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");

    // const spine::String &getStringValue()
    const spine::String &ret = (const spine::String &)self->getStringValue();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");

    // float getTime()
    float ret = (float)self->getTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_getVolume(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");

    // float getVolume()
    float ret = (float)self->getVolume();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Event_setBalance(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");
    olua_check_number(L, 2, &arg1);

    // void setBalance(float inValue)
    self->setBalance((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Event_setFloatValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");
    olua_check_number(L, 2, &arg1);

    // void setFloatValue(float inValue)
    self->setFloatValue((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Event_setIntValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;
    lua_Integer arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");
    olua_check_int(L, 2, &arg1);

    // void setIntValue(int inValue)
    self->setIntValue((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Event_setStringValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");
    manual_olua_check_spine_String(L, 2, &arg1);

    // void setStringValue(const spine::String &inValue)
    self->setStringValue(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Event_setVolume(lua_State *L)
{
    olua_startinvoke(L);

    spine::Event *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Event");
    olua_check_number(L, 2, &arg1);

    // void setVolume(float inValue)
    self->setVolume((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_Event(lua_State *L)
{
    oluacls_class(L, "sp.Event", "sp.SpineObject");
    oluacls_func(L, "__move", _spine_Event___move);
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

    olua_registerluatype<spine::Event>(L, "sp.Event");

    return 1;
}

static int _spine_EventData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::EventData *)olua_toobj(L, 1, "sp.EventData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::EventData *)olua_toobj(L, 1, "sp.EventData");
    olua_push_cppobj(L, self, "sp.EventData");

    olua_endinvoke(L);

    return 1;
}

static int _spine_EventData_getAudioPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");

    // const spine::String &getAudioPath()
    const spine::String &ret = (const spine::String &)self->getAudioPath();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getBalance(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");

    // float getBalance()
    float ret = (float)self->getBalance();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getFloatValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");

    // float getFloatValue()
    float ret = (float)self->getFloatValue();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getIntValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");

    // int getIntValue()
    int ret = (int)self->getIntValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");

    // const spine::String &getName()
    const spine::String &ret = (const spine::String &)self->getName();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getStringValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");

    // const spine::String &getStringValue()
    const spine::String &ret = (const spine::String &)self->getStringValue();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_getVolume(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");

    // float getVolume()
    float ret = (float)self->getVolume();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // EventData(const spine::String &name)
    spine::EventData *ret = (spine::EventData *)new spine::EventData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.EventData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventData_setAudioPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // void setAudioPath(const spine::String &inValue)
    self->setAudioPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventData_setBalance(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");
    olua_check_number(L, 2, &arg1);

    // void setBalance(float inValue)
    self->setBalance((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventData_setFloatValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");
    olua_check_number(L, 2, &arg1);

    // void setFloatValue(float inValue)
    self->setFloatValue((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventData_setIntValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    lua_Integer arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");
    olua_check_int(L, 2, &arg1);

    // void setIntValue(int inValue)
    self->setIntValue((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventData_setStringValue(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // void setStringValue(const spine::String &inValue)
    self->setStringValue(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventData_setVolume(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventData");
    olua_check_number(L, 2, &arg1);

    // void setVolume(float inValue)
    self->setVolume((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_EventData(lua_State *L)
{
    oluacls_class(L, "sp.EventData", "sp.SpineObject");
    oluacls_func(L, "__gc", _spine_EventData___gc);
    oluacls_func(L, "__move", _spine_EventData___move);
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

    olua_registerluatype<spine::EventData>(L, "sp.EventData");

    return 1;
}

static int _spine_Updatable___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Updatable *)olua_toobj(L, 1, "sp.Updatable");
    olua_push_cppobj(L, self, "sp.Updatable");

    olua_endinvoke(L);

    return 1;
}

static int _spine_Updatable_isActive(lua_State *L)
{
    olua_startinvoke(L);

    spine::Updatable *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Updatable");

    // bool isActive()
    bool ret = (bool)self->isActive();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Updatable_setActive(lua_State *L)
{
    olua_startinvoke(L);

    spine::Updatable *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Updatable");
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

    olua_to_cppobj(L, 1, (void **)&self, "sp.Updatable");

    // void update()
    self->update();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_Updatable(lua_State *L)
{
    oluacls_class(L, "sp.Updatable", "sp.SpineObject");
    oluacls_func(L, "__move", _spine_Updatable___move);
    oluacls_func(L, "isActive", _spine_Updatable_isActive);
    oluacls_func(L, "setActive", _spine_Updatable_setActive);
    oluacls_func(L, "update", _spine_Updatable_update);
    oluacls_prop(L, "active", _spine_Updatable_isActive, _spine_Updatable_setActive);

    olua_registerluatype<spine::Updatable>(L, "sp.Updatable");

    return 1;
}

static int _spine_AnimationState___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::AnimationState *)olua_toobj(L, 1, "sp.AnimationState");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::AnimationState *)olua_toobj(L, 1, "sp.AnimationState");
    olua_push_cppobj(L, self, "sp.AnimationState");

    olua_endinvoke(L);

    return 1;
}

static int _spine_AnimationState_addAnimation1(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** trackIndex */
    spine::String arg2;       /** animationName */
    bool arg3 = false;       /** loop */
    lua_Number arg4 = 0;       /** delay */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");
    olua_check_uint(L, 2, &arg1);
    manual_olua_check_spine_String(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // spine::TrackEntry *addAnimation(size_t trackIndex, const spine::String &animationName, bool loop, float delay)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->addAnimation((size_t)arg1, arg2, arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_addAnimation2(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** trackIndex */
    spine::Animation *arg2 = nullptr;       /** animation */
    bool arg3 = false;       /** loop */
    lua_Number arg4 = 0;       /** delay */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");
    olua_check_uint(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "sp.Animation");
    olua_check_bool(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // spine::TrackEntry *addAnimation(size_t trackIndex, spine::Animation *animation, bool loop, float delay)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->addAnimation((size_t)arg1, arg2, arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_addAnimation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 4) {
        if ((olua_is_uint(L, 2)) && (manual_olua_is_spine_String(L, 3)) && (olua_is_bool(L, 4)) && (olua_is_number(L, 5))) {
            // spine::TrackEntry *addAnimation(size_t trackIndex, const spine::String &animationName, bool loop, float delay)
            return _spine_AnimationState_addAnimation1(L);
        }

        // if ((olua_is_uint(L, 2)) && (olua_is_cppobj(L, 3, "sp.Animation")) && (olua_is_bool(L, 4)) && (olua_is_number(L, 5))) {
            // spine::TrackEntry *addAnimation(size_t trackIndex, spine::Animation *animation, bool loop, float delay)
            return _spine_AnimationState_addAnimation2(L);
        // }
    }

    luaL_error(L, "method 'spine::AnimationState::addAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_AnimationState_addEmptyAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** trackIndex */
    lua_Number arg2 = 0;       /** mixDuration */
    lua_Number arg3 = 0;       /** delay */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");
    olua_check_uint(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // spine::TrackEntry *addEmptyAnimation(size_t trackIndex, float mixDuration, float delay)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->addEmptyAnimation((size_t)arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_clearTrack(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** trackIndex */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");
    olua_check_uint(L, 2, &arg1);

    // void clearTrack(size_t trackIndex)
    self->clearTrack((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_clearTracks(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");

    // void clearTracks()
    self->clearTracks();

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_disableQueue(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");

    // void disableQueue()
    self->disableQueue();

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_enableQueue(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");

    // void enableQueue()
    self->enableQueue();

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_getCurrent(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** trackIndex */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");
    olua_check_uint(L, 2, &arg1);

    // spine::TrackEntry *getCurrent(size_t trackIndex)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->getCurrent((size_t)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_getData(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");

    // spine::AnimationStateData *getData()
    spine::AnimationStateData *ret = (spine::AnimationStateData *)self->getData();
    int num_ret = olua_push_cppobj(L, ret, "sp.AnimationStateData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_getTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");

    // float getTimeScale()
    float ret = (float)self->getTimeScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_getTracks(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");

    // Vector<spine::TrackEntry *> &getTracks()
    spine::Vector<spine::TrackEntry *> &ret = (spine::Vector<spine::TrackEntry *> &)self->getTracks();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *arg1 = nullptr;       /** data */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.AnimationStateData");

    // AnimationState(spine::AnimationStateData *data)
    spine::AnimationState *ret = (spine::AnimationState *)new spine::AnimationState(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.AnimationState");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_setAnimation1(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** trackIndex */
    spine::String arg2;       /** animationName */
    bool arg3 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");
    olua_check_uint(L, 2, &arg1);
    manual_olua_check_spine_String(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // spine::TrackEntry *setAnimation(size_t trackIndex, const spine::String &animationName, bool loop)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->setAnimation((size_t)arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_setAnimation2(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** trackIndex */
    spine::Animation *arg2 = nullptr;       /** animation */
    bool arg3 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");
    olua_check_uint(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "sp.Animation");
    olua_check_bool(L, 4, &arg3);

    // spine::TrackEntry *setAnimation(size_t trackIndex, spine::Animation *animation, bool loop)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->setAnimation((size_t)arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_setAnimation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        if ((olua_is_uint(L, 2)) && (manual_olua_is_spine_String(L, 3)) && (olua_is_bool(L, 4))) {
            // spine::TrackEntry *setAnimation(size_t trackIndex, const spine::String &animationName, bool loop)
            return _spine_AnimationState_setAnimation1(L);
        }

        // if ((olua_is_uint(L, 2)) && (olua_is_cppobj(L, 3, "sp.Animation")) && (olua_is_bool(L, 4))) {
            // spine::TrackEntry *setAnimation(size_t trackIndex, spine::Animation *animation, bool loop)
            return _spine_AnimationState_setAnimation2(L);
        // }
    }

    luaL_error(L, "method 'spine::AnimationState::setAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_AnimationState_setEmptyAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    lua_Unsigned arg1 = 0;       /** trackIndex */
    lua_Number arg2 = 0;       /** mixDuration */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");
    olua_check_uint(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // spine::TrackEntry *setEmptyAnimation(size_t trackIndex, float mixDuration)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->setEmptyAnimation((size_t)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationState_setEmptyAnimations(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    lua_Number arg1 = 0;       /** mixDuration */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");
    olua_check_number(L, 2, &arg1);

    // void setEmptyAnimations(float mixDuration)
    self->setEmptyAnimations((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_setListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    std::function<void(spine::AnimationState *, spine::EventType, spine::TrackEntry *, spine::Event *)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");

    void *callback_store_obj = (void *)self;
    std::string tag = "Listener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT](spine::AnimationState *arg1, spine::EventType arg2, spine::TrackEntry *arg3, spine::Event *arg4) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.AnimationState");
            olua_push_uint(L, (lua_Unsigned)arg2);
            olua_push_cppobj(L, arg3, "sp.TrackEntry");
            olua_push_cppobj(L, arg4, "sp.Event");

            olua_callback(L, callback_store_obj, func.c_str(), 4);

            lua_settop(L, top);
        }
    };

    // void setListener(std::function<void (AnimationState *, EventType, TrackEntry *, Event *)> listener)
    self->setListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_setTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");
    olua_check_number(L, 2, &arg1);

    // void setTimeScale(float inValue)
    self->setTimeScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationState_update(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationState *self = nullptr;
    lua_Number arg1 = 0;       /** delta */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationState");
    olua_check_number(L, 2, &arg1);

    // void update(float delta)
    self->update((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_AnimationState(lua_State *L)
{
    oluacls_class(L, "sp.AnimationState", "sp.SpineObject");
    oluacls_func(L, "__gc", _spine_AnimationState___gc);
    oluacls_func(L, "__move", _spine_AnimationState___move);
    oluacls_func(L, "addAnimation", _spine_AnimationState_addAnimation);
    oluacls_func(L, "addEmptyAnimation", _spine_AnimationState_addEmptyAnimation);
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

    olua_registerluatype<spine::AnimationState>(L, "sp.AnimationState");

    return 1;
}

static int _spine_AnimationStateData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::AnimationStateData *)olua_toobj(L, 1, "sp.AnimationStateData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationStateData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::AnimationStateData *)olua_toobj(L, 1, "sp.AnimationStateData");
    olua_push_cppobj(L, self, "sp.AnimationStateData");

    olua_endinvoke(L);

    return 1;
}

static int _spine_AnimationStateData_getDefaultMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationStateData");

    // float getDefaultMix()
    float ret = (float)self->getDefaultMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationStateData_getMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;
    spine::Animation *arg1 = nullptr;       /** from */
    spine::Animation *arg2 = nullptr;       /** to */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationStateData");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Animation");
    olua_check_cppobj(L, 3, (void **)&arg2, "sp.Animation");

    // float getMix(spine::Animation *from, spine::Animation *to)
    float ret = (float)self->getMix(arg1, arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationStateData_getSkeletonData(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationStateData");

    // spine::SkeletonData *getSkeletonData()
    spine::SkeletonData *ret = (spine::SkeletonData *)self->getSkeletonData();
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationStateData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.SkeletonData");

    // AnimationStateData(spine::SkeletonData *skeletonData)
    spine::AnimationStateData *ret = (spine::AnimationStateData *)new spine::AnimationStateData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.AnimationStateData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AnimationStateData_setDefaultMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationStateData");
    olua_check_number(L, 2, &arg1);

    // void setDefaultMix(float inValue)
    self->setDefaultMix((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationStateData_setMix1(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;
    spine::String arg1;       /** fromName */
    spine::String arg2;       /** toName */
    lua_Number arg3 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationStateData");
    manual_olua_check_spine_String(L, 2, &arg1);
    manual_olua_check_spine_String(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void setMix(const spine::String &fromName, const spine::String &toName, float duration)
    self->setMix(arg1, arg2, (float)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationStateData_setMix2(lua_State *L)
{
    olua_startinvoke(L);

    spine::AnimationStateData *self = nullptr;
    spine::Animation *arg1 = nullptr;       /** from */
    spine::Animation *arg2 = nullptr;       /** to */
    lua_Number arg3 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AnimationStateData");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Animation");
    olua_check_cppobj(L, 3, (void **)&arg2, "sp.Animation");
    olua_check_number(L, 4, &arg3);

    // void setMix(spine::Animation *from, spine::Animation *to, float duration)
    self->setMix(arg1, arg2, (float)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_AnimationStateData_setMix(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        if ((manual_olua_is_spine_String(L, 2)) && (manual_olua_is_spine_String(L, 3)) && (olua_is_number(L, 4))) {
            // void setMix(const spine::String &fromName, const spine::String &toName, float duration)
            return _spine_AnimationStateData_setMix1(L);
        }

        // if ((olua_is_cppobj(L, 2, "sp.Animation")) && (olua_is_cppobj(L, 3, "sp.Animation")) && (olua_is_number(L, 4))) {
            // void setMix(spine::Animation *from, spine::Animation *to, float duration)
            return _spine_AnimationStateData_setMix2(L);
        // }
    }

    luaL_error(L, "method 'spine::AnimationStateData::setMix' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_spine_AnimationStateData(lua_State *L)
{
    oluacls_class(L, "sp.AnimationStateData", "sp.SpineObject");
    oluacls_func(L, "__gc", _spine_AnimationStateData___gc);
    oluacls_func(L, "__move", _spine_AnimationStateData___move);
    oluacls_func(L, "getDefaultMix", _spine_AnimationStateData_getDefaultMix);
    oluacls_func(L, "getMix", _spine_AnimationStateData_getMix);
    oluacls_func(L, "getSkeletonData", _spine_AnimationStateData_getSkeletonData);
    oluacls_func(L, "new", _spine_AnimationStateData_new);
    oluacls_func(L, "setDefaultMix", _spine_AnimationStateData_setDefaultMix);
    oluacls_func(L, "setMix", _spine_AnimationStateData_setMix);
    oluacls_prop(L, "defaultMix", _spine_AnimationStateData_getDefaultMix, _spine_AnimationStateData_setDefaultMix);
    oluacls_prop(L, "skeletonData", _spine_AnimationStateData_getSkeletonData, nullptr);

    olua_registerluatype<spine::AnimationStateData>(L, "sp.AnimationStateData");

    return 1;
}

static int _spine_Animation___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Animation *)olua_toobj(L, 1, "sp.Animation");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_Animation___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Animation *)olua_toobj(L, 1, "sp.Animation");
    olua_push_cppobj(L, self, "sp.Animation");

    olua_endinvoke(L);

    return 1;
}

static int _spine_Animation_getDuration(lua_State *L)
{
    olua_startinvoke(L);

    spine::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Animation");

    // float getDuration()
    float ret = (float)self->getDuration();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Animation");

    // const spine::String &getName()
    const spine::String &ret = (const spine::String &)self->getName();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_getTimelines(lua_State *L)
{
    olua_startinvoke(L);

    spine::Animation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Animation");

    // Vector<spine::Timeline *> &getTimelines()
    spine::Vector<spine::Timeline *> &ret = (spine::Vector<spine::Timeline *> &)self->getTimelines();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.Timeline");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_hasTimeline(lua_State *L)
{
    olua_startinvoke(L);

    spine::Animation *self = nullptr;
    lua_Integer arg1 = 0;       /** id */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Animation");
    olua_check_int(L, 2, &arg1);

    // bool hasTimeline(int id)
    bool ret = (bool)self->hasTimeline((int)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */
    spine::Vector<spine::Timeline *> arg2;       /** timelines */
    lua_Number arg3 = 0;       /** duration */

    manual_olua_check_spine_String(L, 1, &arg1);
    manual_olua_check_spine_Vector(L, 2, arg2, "sp.Timeline");
    olua_check_number(L, 3, &arg3);

    // Animation(const spine::String &name, Vector<spine::Timeline *> &timelines, float duration)
    spine::Animation *ret = (spine::Animation *)new spine::Animation(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.Animation");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Animation_setDuration(lua_State *L)
{
    olua_startinvoke(L);

    spine::Animation *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Animation");
    olua_check_number(L, 2, &arg1);

    // void setDuration(float inValue)
    self->setDuration((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_Animation(lua_State *L)
{
    oluacls_class(L, "sp.Animation", "sp.SpineObject");
    oluacls_func(L, "__gc", _spine_Animation___gc);
    oluacls_func(L, "__move", _spine_Animation___move);
    oluacls_func(L, "getDuration", _spine_Animation_getDuration);
    oluacls_func(L, "getName", _spine_Animation_getName);
    oluacls_func(L, "getTimelines", _spine_Animation_getTimelines);
    oluacls_func(L, "hasTimeline", _spine_Animation_hasTimeline);
    oluacls_func(L, "new", _spine_Animation_new);
    oluacls_func(L, "setDuration", _spine_Animation_setDuration);
    oluacls_prop(L, "duration", _spine_Animation_getDuration, _spine_Animation_setDuration);
    oluacls_prop(L, "name", _spine_Animation_getName, nullptr);
    oluacls_prop(L, "timelines", _spine_Animation_getTimelines, nullptr);

    olua_registerluatype<spine::Animation>(L, "sp.Animation");

    return 1;
}

static int _spine_ConstraintData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::ConstraintData *)olua_toobj(L, 1, "sp.ConstraintData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_ConstraintData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::ConstraintData *)olua_toobj(L, 1, "sp.ConstraintData");
    olua_push_cppobj(L, self, "sp.ConstraintData");

    olua_endinvoke(L);

    return 1;
}

static int _spine_ConstraintData_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::ConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.ConstraintData");

    // const spine::String &getName()
    const spine::String &ret = (const spine::String &)self->getName();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ConstraintData_getOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::ConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.ConstraintData");

    // size_t getOrder()
    size_t ret = (size_t)self->getOrder();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ConstraintData_isSkinRequired(lua_State *L)
{
    olua_startinvoke(L);

    spine::ConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.ConstraintData");

    // bool isSkinRequired()
    bool ret = (bool)self->isSkinRequired();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ConstraintData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // ConstraintData(const spine::String &name)
    spine::ConstraintData *ret = (spine::ConstraintData *)new spine::ConstraintData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.ConstraintData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ConstraintData_setOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::ConstraintData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.ConstraintData");
    olua_check_uint(L, 2, &arg1);

    // void setOrder(size_t inValue)
    self->setOrder((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_ConstraintData_setSkinRequired(lua_State *L)
{
    olua_startinvoke(L);

    spine::ConstraintData *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.ConstraintData");
    olua_check_bool(L, 2, &arg1);

    // void setSkinRequired(bool inValue)
    self->setSkinRequired(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_ConstraintData(lua_State *L)
{
    oluacls_class(L, "sp.ConstraintData", "sp.SpineObject");
    oluacls_func(L, "__gc", _spine_ConstraintData___gc);
    oluacls_func(L, "__move", _spine_ConstraintData___move);
    oluacls_func(L, "getName", _spine_ConstraintData_getName);
    oluacls_func(L, "getOrder", _spine_ConstraintData_getOrder);
    oluacls_func(L, "isSkinRequired", _spine_ConstraintData_isSkinRequired);
    oluacls_func(L, "new", _spine_ConstraintData_new);
    oluacls_func(L, "setOrder", _spine_ConstraintData_setOrder);
    oluacls_func(L, "setSkinRequired", _spine_ConstraintData_setSkinRequired);
    oluacls_prop(L, "name", _spine_ConstraintData_getName, nullptr);
    oluacls_prop(L, "order", _spine_ConstraintData_getOrder, _spine_ConstraintData_setOrder);
    oluacls_prop(L, "skinRequired", _spine_ConstraintData_isSkinRequired, _spine_ConstraintData_setSkinRequired);

    olua_registerluatype<spine::ConstraintData>(L, "sp.ConstraintData");

    return 1;
}

static int _spine_IkConstraintData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::IkConstraintData *)olua_toobj(L, 1, "sp.IkConstraintData");
    olua_push_cppobj(L, self, "sp.IkConstraintData");

    olua_endinvoke(L);

    return 1;
}

static int _spine_IkConstraintData_getBendDirection(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");

    // int getBendDirection()
    int ret = (int)self->getBendDirection();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");

    // Vector<spine::BoneData *> &getBones()
    spine::Vector<spine::BoneData *> &ret = (spine::Vector<spine::BoneData *> &)self->getBones();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getCompress(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");

    // bool getCompress()
    bool ret = (bool)self->getCompress();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");

    // float getMix()
    float ret = (float)self->getMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getSoftness(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");

    // float getSoftness()
    float ret = (float)self->getSoftness();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getStretch(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");

    // bool getStretch()
    bool ret = (bool)self->getStretch();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");

    // spine::BoneData *getTarget()
    spine::BoneData *ret = (spine::BoneData *)self->getTarget();
    int num_ret = olua_push_cppobj(L, ret, "sp.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_getUniform(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");

    // bool getUniform()
    bool ret = (bool)self->getUniform();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // IkConstraintData(const spine::String &name)
    spine::IkConstraintData *ret = (spine::IkConstraintData *)new spine::IkConstraintData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.IkConstraintData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraintData_setBendDirection(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;
    lua_Integer arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");
    olua_check_int(L, 2, &arg1);

    // void setBendDirection(int inValue)
    self->setBendDirection((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraintData_setCompress(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");
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
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setMix(float inValue)
    self->setMix((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraintData_setSoftness(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setSoftness(float inValue)
    self->setSoftness((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraintData_setStretch(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraintData *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");
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

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.BoneData");

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

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraintData");
    olua_check_bool(L, 2, &arg1);

    // void setUniform(bool inValue)
    self->setUniform(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_IkConstraintData(lua_State *L)
{
    oluacls_class(L, "sp.IkConstraintData", "sp.ConstraintData");
    oluacls_func(L, "__move", _spine_IkConstraintData___move);
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

    olua_registerluatype<spine::IkConstraintData>(L, "sp.IkConstraintData");

    return 1;
}

static int _spine_BoneData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::BoneData *)olua_toobj(L, 1, "sp.BoneData");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::BoneData *)olua_toobj(L, 1, "sp.BoneData");
    olua_push_cppobj(L, self, "sp.BoneData");

    olua_endinvoke(L);

    return 1;
}

static int _spine_BoneData_getIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // int getIndex()
    int ret = (int)self->getIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // float getLength()
    float ret = (float)self->getLength();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // const spine::String &getName()
    const spine::String &ret = (const spine::String &)self->getName();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getParent(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // spine::BoneData *getParent()
    spine::BoneData *ret = (spine::BoneData *)self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "sp.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // float getRotation()
    float ret = (float)self->getRotation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // float getScaleX()
    float ret = (float)self->getScaleX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // float getScaleY()
    float ret = (float)self->getScaleY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // float getShearX()
    float ret = (float)self->getShearX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // float getShearY()
    float ret = (float)self->getShearY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getTransformMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // spine::TransformMode getTransformMode()
    spine::TransformMode ret = (spine::TransformMode)self->getTransformMode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // float getX()
    float ret = (float)self->getX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // float getY()
    float ret = (float)self->getY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_isSkinRequired(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");

    // bool isSkinRequired()
    bool ret = (bool)self->isSkinRequired();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_new1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** index */
    spine::String arg2;       /** name */
    spine::BoneData *arg3 = nullptr;       /** parent */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_spine_String(L, 2, &arg2);
    olua_check_cppobj(L, 3, (void **)&arg3, "sp.BoneData");

    // BoneData(int index, const spine::String &name, @optional spine::BoneData *parent)
    spine::BoneData *ret = (spine::BoneData *)new spine::BoneData((int)arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.BoneData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_new2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** index */
    spine::String arg2;       /** name */

    olua_check_int(L, 1, &arg1);
    manual_olua_check_spine_String(L, 2, &arg2);

    // BoneData(int index, const spine::String &name, @optional spine::BoneData *parent)
    spine::BoneData *ret = (spine::BoneData *)new spine::BoneData((int)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.BoneData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_BoneData_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_spine_String(L, 2))) {
            // BoneData(int index, const spine::String &name, @optional spine::BoneData *parent)
            return _spine_BoneData_new2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_int(L, 1)) && (manual_olua_is_spine_String(L, 2)) && (olua_is_cppobj(L, 3, "sp.BoneData"))) {
            // BoneData(int index, const spine::String &name, @optional spine::BoneData *parent)
            return _spine_BoneData_new1(L);
        // }
    }

    luaL_error(L, "method 'spine::BoneData::new' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_BoneData_setLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setLength(float inValue)
    self->setLength((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setRotation(float inValue)
    self->setRotation((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setScaleX(float inValue)
    self->setScaleX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setScaleY(float inValue)
    self->setScaleY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setShearX(float inValue)
    self->setShearX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setShearY(float inValue)
    self->setShearY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setSkinRequired(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");
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
    lua_Unsigned arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");
    olua_check_uint(L, 2, &arg1);

    // void setTransformMode(spine::TransformMode inValue)
    self->setTransformMode((spine::TransformMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoneData_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::BoneData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.BoneData");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_BoneData(lua_State *L)
{
    oluacls_class(L, "sp.BoneData", "sp.SpineObject");
    oluacls_func(L, "__gc", _spine_BoneData___gc);
    oluacls_func(L, "__move", _spine_BoneData___move);
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

    olua_registerluatype<spine::BoneData>(L, "sp.BoneData");

    return 1;
}

static int _spine_SlotData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::SlotData *)olua_toobj(L, 1, "sp.SlotData");
    olua_push_cppobj(L, self, "sp.SlotData");

    olua_endinvoke(L);

    return 1;
}

static int _spine_SlotData_getAttachmentName(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SlotData");

    // const spine::String &getAttachmentName()
    const spine::String &ret = (const spine::String &)self->getAttachmentName();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_getBlendMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SlotData");

    // spine::BlendMode getBlendMode()
    spine::BlendMode ret = (spine::BlendMode)self->getBlendMode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SlotData");

    // spine::Color &getColor()
    spine::Color &ret = (spine::Color &)self->getColor();
    int num_ret = manual_olua_push_spine_Color(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_getDarkColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SlotData");

    // spine::Color &getDarkColor()
    spine::Color &ret = (spine::Color &)self->getDarkColor();
    int num_ret = manual_olua_push_spine_Color(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_getIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SlotData");

    // int getIndex()
    int ret = (int)self->getIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SlotData");

    // const spine::String &getName()
    const spine::String &ret = (const spine::String &)self->getName();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_hasDarkColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SlotData");

    // bool hasDarkColor()
    bool ret = (bool)self->hasDarkColor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SlotData_setAttachmentName(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SlotData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // void setAttachmentName(const spine::String &inValue)
    self->setAttachmentName(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SlotData_setBlendMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SlotData");
    olua_check_uint(L, 2, &arg1);

    // void setBlendMode(spine::BlendMode inValue)
    self->setBlendMode((spine::BlendMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SlotData_setHasDarkColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::SlotData *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SlotData");
    olua_check_bool(L, 2, &arg1);

    // void setHasDarkColor(bool inValue)
    self->setHasDarkColor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_SlotData(lua_State *L)
{
    oluacls_class(L, "sp.SlotData", "sp.SpineObject");
    oluacls_func(L, "__move", _spine_SlotData___move);
    oluacls_func(L, "getAttachmentName", _spine_SlotData_getAttachmentName);
    oluacls_func(L, "getBlendMode", _spine_SlotData_getBlendMode);
    oluacls_func(L, "getColor", _spine_SlotData_getColor);
    oluacls_func(L, "getDarkColor", _spine_SlotData_getDarkColor);
    oluacls_func(L, "getIndex", _spine_SlotData_getIndex);
    oluacls_func(L, "getName", _spine_SlotData_getName);
    oluacls_func(L, "hasDarkColor", _spine_SlotData_hasDarkColor);
    oluacls_func(L, "setAttachmentName", _spine_SlotData_setAttachmentName);
    oluacls_func(L, "setBlendMode", _spine_SlotData_setBlendMode);
    oluacls_func(L, "setHasDarkColor", _spine_SlotData_setHasDarkColor);
    oluacls_prop(L, "attachmentName", _spine_SlotData_getAttachmentName, _spine_SlotData_setAttachmentName);
    oluacls_prop(L, "blendMode", _spine_SlotData_getBlendMode, _spine_SlotData_setBlendMode);
    oluacls_prop(L, "color", _spine_SlotData_getColor, nullptr);
    oluacls_prop(L, "darkColor", _spine_SlotData_getDarkColor, nullptr);
    oluacls_prop(L, "index", _spine_SlotData_getIndex, nullptr);
    oluacls_prop(L, "name", _spine_SlotData_getName, nullptr);

    olua_registerluatype<spine::SlotData>(L, "sp.SlotData");

    return 1;
}

static int _spine_IkConstraint___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::IkConstraint *)olua_toobj(L, 1, "sp.IkConstraint");
    olua_push_cppobj(L, self, "sp.IkConstraint");

    olua_endinvoke(L);

    return 1;
}

static int _spine_IkConstraint_apply(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");

    // void apply()
    self->apply();

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_getBendDirection(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");

    // int getBendDirection()
    int ret = (int)self->getBendDirection();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");

    // Vector<spine::Bone *> &getBones()
    spine::Vector<spine::Bone *> &ret = (spine::Vector<spine::Bone *> &)self->getBones();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getCompress(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");

    // bool getCompress()
    bool ret = (bool)self->getCompress();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");

    // float getMix()
    float ret = (float)self->getMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");

    // int getOrder()
    int ret = (int)self->getOrder();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getSoftness(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");

    // float getSoftness()
    float ret = (float)self->getSoftness();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getStretch(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");

    // bool getStretch()
    bool ret = (bool)self->getStretch();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");

    // spine::Bone *getTarget()
    spine::Bone *ret = (spine::Bone *)self->getTarget();
    int num_ret = olua_push_cppobj(L, ret, "sp.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_IkConstraint_setBendDirection(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;
    lua_Integer arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");
    olua_check_int(L, 2, &arg1);

    // void setBendDirection(int inValue)
    self->setBendDirection((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_setCompress(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");
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
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");
    olua_check_number(L, 2, &arg1);

    // void setMix(float inValue)
    self->setMix((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_setSoftness(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");
    olua_check_number(L, 2, &arg1);

    // void setSoftness(float inValue)
    self->setSoftness((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraint_setStretch(lua_State *L)
{
    olua_startinvoke(L);

    spine::IkConstraint *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");
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

    olua_to_cppobj(L, 1, (void **)&self, "sp.IkConstraint");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Bone");

    // void setTarget(spine::Bone *inValue)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_IkConstraint(lua_State *L)
{
    oluacls_class(L, "sp.IkConstraint", "sp.Updatable");
    oluacls_func(L, "__move", _spine_IkConstraint___move);
    oluacls_func(L, "apply", _spine_IkConstraint_apply);
    oluacls_func(L, "getBendDirection", _spine_IkConstraint_getBendDirection);
    oluacls_func(L, "getBones", _spine_IkConstraint_getBones);
    oluacls_func(L, "getCompress", _spine_IkConstraint_getCompress);
    oluacls_func(L, "getMix", _spine_IkConstraint_getMix);
    oluacls_func(L, "getOrder", _spine_IkConstraint_getOrder);
    oluacls_func(L, "getSoftness", _spine_IkConstraint_getSoftness);
    oluacls_func(L, "getStretch", _spine_IkConstraint_getStretch);
    oluacls_func(L, "getTarget", _spine_IkConstraint_getTarget);
    oluacls_func(L, "setBendDirection", _spine_IkConstraint_setBendDirection);
    oluacls_func(L, "setCompress", _spine_IkConstraint_setCompress);
    oluacls_func(L, "setMix", _spine_IkConstraint_setMix);
    oluacls_func(L, "setSoftness", _spine_IkConstraint_setSoftness);
    oluacls_func(L, "setStretch", _spine_IkConstraint_setStretch);
    oluacls_func(L, "setTarget", _spine_IkConstraint_setTarget);
    oluacls_prop(L, "bendDirection", _spine_IkConstraint_getBendDirection, _spine_IkConstraint_setBendDirection);
    oluacls_prop(L, "bones", _spine_IkConstraint_getBones, nullptr);
    oluacls_prop(L, "compress", _spine_IkConstraint_getCompress, _spine_IkConstraint_setCompress);
    oluacls_prop(L, "mix", _spine_IkConstraint_getMix, _spine_IkConstraint_setMix);
    oluacls_prop(L, "order", _spine_IkConstraint_getOrder, nullptr);
    oluacls_prop(L, "softness", _spine_IkConstraint_getSoftness, _spine_IkConstraint_setSoftness);
    oluacls_prop(L, "stretch", _spine_IkConstraint_getStretch, _spine_IkConstraint_setStretch);
    oluacls_prop(L, "target", _spine_IkConstraint_getTarget, _spine_IkConstraint_setTarget);

    olua_registerluatype<spine::IkConstraint>(L, "sp.IkConstraint");

    return 1;
}

static int _spine_TransformConstraint___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::TransformConstraint *)olua_toobj(L, 1, "sp.TransformConstraint");
    olua_push_cppobj(L, self, "sp.TransformConstraint");

    olua_endinvoke(L);

    return 1;
}

static int _spine_TransformConstraint_apply(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");

    // void apply()
    self->apply();

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraint_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");

    // Vector<spine::Bone *> &getBones()
    spine::Vector<spine::Bone *> &ret = (spine::Vector<spine::Bone *> &)self->getBones();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");

    // int getOrder()
    int ret = (int)self->getOrder();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getRotateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");

    // float getRotateMix()
    float ret = (float)self->getRotateMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getScaleMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");

    // float getScaleMix()
    float ret = (float)self->getScaleMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getShearMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");

    // float getShearMix()
    float ret = (float)self->getShearMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");

    // spine::Bone *getTarget()
    spine::Bone *ret = (spine::Bone *)self->getTarget();
    int num_ret = olua_push_cppobj(L, ret, "sp.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_getTranslateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");

    // float getTranslateMix()
    float ret = (float)self->getTranslateMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraint_setRotateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");
    olua_check_number(L, 2, &arg1);

    // void setRotateMix(float inValue)
    self->setRotateMix((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraint_setScaleMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");
    olua_check_number(L, 2, &arg1);

    // void setScaleMix(float inValue)
    self->setScaleMix((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraint_setShearMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");
    olua_check_number(L, 2, &arg1);

    // void setShearMix(float inValue)
    self->setShearMix((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraint_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    spine::Bone *arg1 = nullptr;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Bone");

    // void setTarget(spine::Bone *inValue)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraint_setTranslateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraint *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraint");
    olua_check_number(L, 2, &arg1);

    // void setTranslateMix(float inValue)
    self->setTranslateMix((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_TransformConstraint(lua_State *L)
{
    oluacls_class(L, "sp.TransformConstraint", "sp.Updatable");
    oluacls_func(L, "__move", _spine_TransformConstraint___move);
    oluacls_func(L, "apply", _spine_TransformConstraint_apply);
    oluacls_func(L, "getBones", _spine_TransformConstraint_getBones);
    oluacls_func(L, "getOrder", _spine_TransformConstraint_getOrder);
    oluacls_func(L, "getRotateMix", _spine_TransformConstraint_getRotateMix);
    oluacls_func(L, "getScaleMix", _spine_TransformConstraint_getScaleMix);
    oluacls_func(L, "getShearMix", _spine_TransformConstraint_getShearMix);
    oluacls_func(L, "getTarget", _spine_TransformConstraint_getTarget);
    oluacls_func(L, "getTranslateMix", _spine_TransformConstraint_getTranslateMix);
    oluacls_func(L, "setRotateMix", _spine_TransformConstraint_setRotateMix);
    oluacls_func(L, "setScaleMix", _spine_TransformConstraint_setScaleMix);
    oluacls_func(L, "setShearMix", _spine_TransformConstraint_setShearMix);
    oluacls_func(L, "setTarget", _spine_TransformConstraint_setTarget);
    oluacls_func(L, "setTranslateMix", _spine_TransformConstraint_setTranslateMix);
    oluacls_prop(L, "bones", _spine_TransformConstraint_getBones, nullptr);
    oluacls_prop(L, "order", _spine_TransformConstraint_getOrder, nullptr);
    oluacls_prop(L, "rotateMix", _spine_TransformConstraint_getRotateMix, _spine_TransformConstraint_setRotateMix);
    oluacls_prop(L, "scaleMix", _spine_TransformConstraint_getScaleMix, _spine_TransformConstraint_setScaleMix);
    oluacls_prop(L, "shearMix", _spine_TransformConstraint_getShearMix, _spine_TransformConstraint_setShearMix);
    oluacls_prop(L, "target", _spine_TransformConstraint_getTarget, _spine_TransformConstraint_setTarget);
    oluacls_prop(L, "translateMix", _spine_TransformConstraint_getTranslateMix, _spine_TransformConstraint_setTranslateMix);

    olua_registerluatype<spine::TransformConstraint>(L, "sp.TransformConstraint");

    return 1;
}

static int _spine_TransformConstraintData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::TransformConstraintData *)olua_toobj(L, 1, "sp.TransformConstraintData");
    olua_push_cppobj(L, self, "sp.TransformConstraintData");

    olua_endinvoke(L);

    return 1;
}

static int _spine_TransformConstraintData_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // Vector<spine::BoneData *> &getBones()
    spine::Vector<spine::BoneData *> &ret = (spine::Vector<spine::BoneData *> &)self->getBones();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // float getOffsetRotation()
    float ret = (float)self->getOffsetRotation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // float getOffsetScaleX()
    float ret = (float)self->getOffsetScaleX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // float getOffsetScaleY()
    float ret = (float)self->getOffsetScaleY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // float getOffsetShearY()
    float ret = (float)self->getOffsetShearY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetX(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // float getOffsetX()
    float ret = (float)self->getOffsetX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getOffsetY(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // float getOffsetY()
    float ret = (float)self->getOffsetY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getRotateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // float getRotateMix()
    float ret = (float)self->getRotateMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getScaleMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // float getScaleMix()
    float ret = (float)self->getScaleMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getShearMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // float getShearMix()
    float ret = (float)self->getShearMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // spine::BoneData *getTarget()
    spine::BoneData *ret = (spine::BoneData *)self->getTarget();
    int num_ret = olua_push_cppobj(L, ret, "sp.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_getTranslateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // float getTranslateMix()
    float ret = (float)self->getTranslateMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_isLocal(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // bool isLocal()
    bool ret = (bool)self->isLocal();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_isRelative(lua_State *L)
{
    olua_startinvoke(L);

    spine::TransformConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TransformConstraintData");

    // bool isRelative()
    bool ret = (bool)self->isRelative();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TransformConstraintData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // TransformConstraintData(const spine::String &name)
    spine::TransformConstraintData *ret = (spine::TransformConstraintData *)new spine::TransformConstraintData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.TransformConstraintData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_TransformConstraintData(lua_State *L)
{
    oluacls_class(L, "sp.TransformConstraintData", "sp.ConstraintData");
    oluacls_func(L, "__move", _spine_TransformConstraintData___move);
    oluacls_func(L, "getBones", _spine_TransformConstraintData_getBones);
    oluacls_func(L, "getOffsetRotation", _spine_TransformConstraintData_getOffsetRotation);
    oluacls_func(L, "getOffsetScaleX", _spine_TransformConstraintData_getOffsetScaleX);
    oluacls_func(L, "getOffsetScaleY", _spine_TransformConstraintData_getOffsetScaleY);
    oluacls_func(L, "getOffsetShearY", _spine_TransformConstraintData_getOffsetShearY);
    oluacls_func(L, "getOffsetX", _spine_TransformConstraintData_getOffsetX);
    oluacls_func(L, "getOffsetY", _spine_TransformConstraintData_getOffsetY);
    oluacls_func(L, "getRotateMix", _spine_TransformConstraintData_getRotateMix);
    oluacls_func(L, "getScaleMix", _spine_TransformConstraintData_getScaleMix);
    oluacls_func(L, "getShearMix", _spine_TransformConstraintData_getShearMix);
    oluacls_func(L, "getTarget", _spine_TransformConstraintData_getTarget);
    oluacls_func(L, "getTranslateMix", _spine_TransformConstraintData_getTranslateMix);
    oluacls_func(L, "isLocal", _spine_TransformConstraintData_isLocal);
    oluacls_func(L, "isRelative", _spine_TransformConstraintData_isRelative);
    oluacls_func(L, "new", _spine_TransformConstraintData_new);
    oluacls_prop(L, "bones", _spine_TransformConstraintData_getBones, nullptr);
    oluacls_prop(L, "local", _spine_TransformConstraintData_isLocal, nullptr);
    oluacls_prop(L, "offsetRotation", _spine_TransformConstraintData_getOffsetRotation, nullptr);
    oluacls_prop(L, "offsetScaleX", _spine_TransformConstraintData_getOffsetScaleX, nullptr);
    oluacls_prop(L, "offsetScaleY", _spine_TransformConstraintData_getOffsetScaleY, nullptr);
    oluacls_prop(L, "offsetShearY", _spine_TransformConstraintData_getOffsetShearY, nullptr);
    oluacls_prop(L, "offsetX", _spine_TransformConstraintData_getOffsetX, nullptr);
    oluacls_prop(L, "offsetY", _spine_TransformConstraintData_getOffsetY, nullptr);
    oluacls_prop(L, "relative", _spine_TransformConstraintData_isRelative, nullptr);
    oluacls_prop(L, "rotateMix", _spine_TransformConstraintData_getRotateMix, nullptr);
    oluacls_prop(L, "scaleMix", _spine_TransformConstraintData_getScaleMix, nullptr);
    oluacls_prop(L, "shearMix", _spine_TransformConstraintData_getShearMix, nullptr);
    oluacls_prop(L, "target", _spine_TransformConstraintData_getTarget, nullptr);
    oluacls_prop(L, "translateMix", _spine_TransformConstraintData_getTranslateMix, nullptr);

    olua_registerluatype<spine::TransformConstraintData>(L, "sp.TransformConstraintData");

    return 1;
}

static int _spine_PathConstraintData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::PathConstraintData *)olua_toobj(L, 1, "sp.PathConstraintData");
    olua_push_cppobj(L, self, "sp.PathConstraintData");

    olua_endinvoke(L);

    return 1;
}

static int _spine_PathConstraintData_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");

    // Vector<spine::BoneData *> &getBones()
    spine::Vector<spine::BoneData *> &ret = (spine::Vector<spine::BoneData *> &)self->getBones();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getOffsetRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");

    // float getOffsetRotation()
    float ret = (float)self->getOffsetRotation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");

    // float getPosition()
    float ret = (float)self->getPosition();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getPositionMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");

    // spine::PositionMode getPositionMode()
    spine::PositionMode ret = (spine::PositionMode)self->getPositionMode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getRotateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");

    // float getRotateMix()
    float ret = (float)self->getRotateMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getRotateMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");

    // spine::RotateMode getRotateMode()
    spine::RotateMode ret = (spine::RotateMode)self->getRotateMode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getSpacing(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");

    // float getSpacing()
    float ret = (float)self->getSpacing();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getSpacingMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");

    // spine::SpacingMode getSpacingMode()
    spine::SpacingMode ret = (spine::SpacingMode)self->getSpacingMode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");

    // spine::SlotData *getTarget()
    spine::SlotData *ret = (spine::SlotData *)self->getTarget();
    int num_ret = olua_push_cppobj(L, ret, "sp.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_getTranslateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");

    // float getTranslateMix()
    float ret = (float)self->getTranslateMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // PathConstraintData(const spine::String &name)
    spine::PathConstraintData *ret = (spine::PathConstraintData *)new spine::PathConstraintData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.PathConstraintData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraintData_setOffsetRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setOffsetRotation(float inValue)
    self->setOffsetRotation((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setPosition(float inValue)
    self->setPosition((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setPositionMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");
    olua_check_uint(L, 2, &arg1);

    // void setPositionMode(spine::PositionMode inValue)
    self->setPositionMode((spine::PositionMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setRotateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setRotateMix(float inValue)
    self->setRotateMix((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setRotateMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");
    olua_check_uint(L, 2, &arg1);

    // void setRotateMode(spine::RotateMode inValue)
    self->setRotateMode((spine::RotateMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setSpacing(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setSpacing(float inValue)
    self->setSpacing((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setSpacingMode(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    lua_Unsigned arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");
    olua_check_uint(L, 2, &arg1);

    // void setSpacingMode(spine::SpacingMode inValue)
    self->setSpacingMode((spine::SpacingMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    spine::SlotData *arg1 = nullptr;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.SlotData");

    // void setTarget(spine::SlotData *inValue)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintData_setTranslateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraintData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraintData");
    olua_check_number(L, 2, &arg1);

    // void setTranslateMix(float inValue)
    self->setTranslateMix((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_PathConstraintData(lua_State *L)
{
    oluacls_class(L, "sp.PathConstraintData", "sp.ConstraintData");
    oluacls_func(L, "__move", _spine_PathConstraintData___move);
    oluacls_func(L, "getBones", _spine_PathConstraintData_getBones);
    oluacls_func(L, "getOffsetRotation", _spine_PathConstraintData_getOffsetRotation);
    oluacls_func(L, "getPosition", _spine_PathConstraintData_getPosition);
    oluacls_func(L, "getPositionMode", _spine_PathConstraintData_getPositionMode);
    oluacls_func(L, "getRotateMix", _spine_PathConstraintData_getRotateMix);
    oluacls_func(L, "getRotateMode", _spine_PathConstraintData_getRotateMode);
    oluacls_func(L, "getSpacing", _spine_PathConstraintData_getSpacing);
    oluacls_func(L, "getSpacingMode", _spine_PathConstraintData_getSpacingMode);
    oluacls_func(L, "getTarget", _spine_PathConstraintData_getTarget);
    oluacls_func(L, "getTranslateMix", _spine_PathConstraintData_getTranslateMix);
    oluacls_func(L, "new", _spine_PathConstraintData_new);
    oluacls_func(L, "setOffsetRotation", _spine_PathConstraintData_setOffsetRotation);
    oluacls_func(L, "setPosition", _spine_PathConstraintData_setPosition);
    oluacls_func(L, "setPositionMode", _spine_PathConstraintData_setPositionMode);
    oluacls_func(L, "setRotateMix", _spine_PathConstraintData_setRotateMix);
    oluacls_func(L, "setRotateMode", _spine_PathConstraintData_setRotateMode);
    oluacls_func(L, "setSpacing", _spine_PathConstraintData_setSpacing);
    oluacls_func(L, "setSpacingMode", _spine_PathConstraintData_setSpacingMode);
    oluacls_func(L, "setTarget", _spine_PathConstraintData_setTarget);
    oluacls_func(L, "setTranslateMix", _spine_PathConstraintData_setTranslateMix);
    oluacls_prop(L, "bones", _spine_PathConstraintData_getBones, nullptr);
    oluacls_prop(L, "offsetRotation", _spine_PathConstraintData_getOffsetRotation, _spine_PathConstraintData_setOffsetRotation);
    oluacls_prop(L, "position", _spine_PathConstraintData_getPosition, _spine_PathConstraintData_setPosition);
    oluacls_prop(L, "positionMode", _spine_PathConstraintData_getPositionMode, _spine_PathConstraintData_setPositionMode);
    oluacls_prop(L, "rotateMix", _spine_PathConstraintData_getRotateMix, _spine_PathConstraintData_setRotateMix);
    oluacls_prop(L, "rotateMode", _spine_PathConstraintData_getRotateMode, _spine_PathConstraintData_setRotateMode);
    oluacls_prop(L, "spacing", _spine_PathConstraintData_getSpacing, _spine_PathConstraintData_setSpacing);
    oluacls_prop(L, "spacingMode", _spine_PathConstraintData_getSpacingMode, _spine_PathConstraintData_setSpacingMode);
    oluacls_prop(L, "target", _spine_PathConstraintData_getTarget, _spine_PathConstraintData_setTarget);
    oluacls_prop(L, "translateMix", _spine_PathConstraintData_getTranslateMix, _spine_PathConstraintData_setTranslateMix);

    olua_registerluatype<spine::PathConstraintData>(L, "sp.PathConstraintData");

    return 1;
}

static int _spine_SkeletonBounds___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::SkeletonBounds *)olua_toobj(L, 1, "sp.SkeletonBounds");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonBounds___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::SkeletonBounds *)olua_toobj(L, 1, "sp.SkeletonBounds");
    olua_push_cppobj(L, self, "sp.SkeletonBounds");

    olua_endinvoke(L);

    return 1;
}

static int _spine_SkeletonBounds_aabbcontainsPoint(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonBounds");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // bool aabbcontainsPoint(float x, float y)
    bool ret = (bool)self->aabbcontainsPoint((float)arg1, (float)arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_aabbintersectsSegment(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    lua_Number arg1 = 0;       /** x1 */
    lua_Number arg2 = 0;       /** y1 */
    lua_Number arg3 = 0;       /** x2 */
    lua_Number arg4 = 0;       /** y2 */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonBounds");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // bool aabbintersectsSegment(float x1, float y1, float x2, float y2)
    bool ret = (bool)self->aabbintersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_containsPoint1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    spine::Polygon *arg1 = nullptr;       /** polygon */
    lua_Number arg2 = 0;       /** x */
    lua_Number arg3 = 0;       /** y */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonBounds");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Polygon");
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // bool containsPoint(spine::Polygon *polygon, float x, float y)
    bool ret = (bool)self->containsPoint(arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_containsPoint2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonBounds");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // spine::BoundingBoxAttachment *containsPoint(float x, float y)
    spine::BoundingBoxAttachment *ret = (spine::BoundingBoxAttachment *)self->containsPoint((float)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.BoundingBoxAttachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_containsPoint(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // spine::BoundingBoxAttachment *containsPoint(float x, float y)
            return _spine_SkeletonBounds_containsPoint2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 2, "sp.Polygon")) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // bool containsPoint(spine::Polygon *polygon, float x, float y)
            return _spine_SkeletonBounds_containsPoint1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonBounds::containsPoint' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonBounds_getHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonBounds");

    // float getHeight()
    float ret = (float)self->getHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_getPolygon(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    spine::BoundingBoxAttachment *arg1 = nullptr;       /** attachment */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonBounds");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.BoundingBoxAttachment");

    // spine::Polygon *getPolygon(spine::BoundingBoxAttachment *attachment)
    spine::Polygon *ret = (spine::Polygon *)self->getPolygon(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.Polygon");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonBounds");

    // float getWidth()
    float ret = (float)self->getWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_intersectsSegment1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    lua_Number arg1 = 0;       /** x1 */
    lua_Number arg2 = 0;       /** y1 */
    lua_Number arg3 = 0;       /** x2 */
    lua_Number arg4 = 0;       /** y2 */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonBounds");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // spine::BoundingBoxAttachment *intersectsSegment(float x1, float y1, float x2, float y2)
    spine::BoundingBoxAttachment *ret = (spine::BoundingBoxAttachment *)self->intersectsSegment((float)arg1, (float)arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "sp.BoundingBoxAttachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonBounds_intersectsSegment2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonBounds *self = nullptr;
    spine::Polygon *arg1 = nullptr;       /** polygon */
    lua_Number arg2 = 0;       /** x1 */
    lua_Number arg3 = 0;       /** y1 */
    lua_Number arg4 = 0;       /** x2 */
    lua_Number arg5 = 0;       /** y2 */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonBounds");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Polygon");
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_number(L, 6, &arg5);

    // bool intersectsSegment(spine::Polygon *polygon, float x1, float y1, float x2, float y2)
    bool ret = (bool)self->intersectsSegment(arg1, (float)arg2, (float)arg3, (float)arg4, (float)arg5);
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
            return _spine_SkeletonBounds_intersectsSegment1(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_cppobj(L, 2, "sp.Polygon")) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_number(L, 6))) {
            // bool intersectsSegment(spine::Polygon *polygon, float x1, float y1, float x2, float y2)
            return _spine_SkeletonBounds_intersectsSegment2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonBounds::intersectsSegment' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonBounds_new(lua_State *L)
{
    olua_startinvoke(L);

    // SkeletonBounds()
    spine::SkeletonBounds *ret = (spine::SkeletonBounds *)new spine::SkeletonBounds();
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonBounds");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_SkeletonBounds(lua_State *L)
{
    oluacls_class(L, "sp.SkeletonBounds", "sp.SpineObject");
    oluacls_func(L, "__gc", _spine_SkeletonBounds___gc);
    oluacls_func(L, "__move", _spine_SkeletonBounds___move);
    oluacls_func(L, "aabbcontainsPoint", _spine_SkeletonBounds_aabbcontainsPoint);
    oluacls_func(L, "aabbintersectsSegment", _spine_SkeletonBounds_aabbintersectsSegment);
    oluacls_func(L, "containsPoint", _spine_SkeletonBounds_containsPoint);
    oluacls_func(L, "getHeight", _spine_SkeletonBounds_getHeight);
    oluacls_func(L, "getPolygon", _spine_SkeletonBounds_getPolygon);
    oluacls_func(L, "getWidth", _spine_SkeletonBounds_getWidth);
    oluacls_func(L, "intersectsSegment", _spine_SkeletonBounds_intersectsSegment);
    oluacls_func(L, "new", _spine_SkeletonBounds_new);
    oluacls_prop(L, "height", _spine_SkeletonBounds_getHeight, nullptr);
    oluacls_prop(L, "width", _spine_SkeletonBounds_getWidth, nullptr);

    olua_registerluatype<spine::SkeletonBounds>(L, "sp.SkeletonBounds");

    return 1;
}

static int _spine_SkeletonClipping___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::SkeletonClipping *)olua_toobj(L, 1, "sp.SkeletonClipping");
    olua_push_cppobj(L, self, "sp.SkeletonClipping");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_spine_SkeletonClipping(lua_State *L)
{
    oluacls_class(L, "sp.SkeletonClipping", "sp.SpineObject");
    oluacls_func(L, "__move", _spine_SkeletonClipping___move);

    olua_registerluatype<spine::SkeletonClipping>(L, "sp.SkeletonClipping");

    return 1;
}

static int _spine_Timeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Timeline *)olua_toobj(L, 1, "sp.Timeline");
    olua_push_cppobj(L, self, "sp.Timeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_Timeline_getPropertyId(lua_State *L)
{
    olua_startinvoke(L);

    spine::Timeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Timeline");

    // int getPropertyId()
    int ret = (int)self->getPropertyId();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_Timeline(lua_State *L)
{
    oluacls_class(L, "sp.Timeline", "sp.SpineObject");
    oluacls_func(L, "__move", _spine_Timeline___move);
    oluacls_func(L, "getPropertyId", _spine_Timeline_getPropertyId);
    oluacls_prop(L, "propertyId", _spine_Timeline_getPropertyId, nullptr);

    olua_registerluatype<spine::Timeline>(L, "sp.Timeline");

    return 1;
}

static int _spine_CurveTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::CurveTimeline *)olua_toobj(L, 1, "sp.CurveTimeline");
    olua_push_cppobj(L, self, "sp.CurveTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_CurveTimeline_getCurvePercent(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameIndex */
    lua_Number arg2 = 0;       /** percent */

    olua_to_cppobj(L, 1, (void **)&self, "sp.CurveTimeline");
    olua_check_uint(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // float getCurvePercent(size_t frameIndex, float percent)
    float ret = (float)self->getCurvePercent((size_t)arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_CurveTimeline_getCurveType(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "sp.CurveTimeline");
    olua_check_uint(L, 2, &arg1);

    // float getCurveType(size_t frameIndex)
    float ret = (float)self->getCurveType((size_t)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_CurveTimeline_getFrameCount(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.CurveTimeline");

    // size_t getFrameCount()
    size_t ret = (size_t)self->getFrameCount();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_CurveTimeline_setCurve(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameIndex */
    lua_Number arg2 = 0;       /** cx1 */
    lua_Number arg3 = 0;       /** cy1 */
    lua_Number arg4 = 0;       /** cx2 */
    lua_Number arg5 = 0;       /** cy2 */

    olua_to_cppobj(L, 1, (void **)&self, "sp.CurveTimeline");
    olua_check_uint(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_number(L, 6, &arg5);

    // void setCurve(size_t frameIndex, float cx1, float cy1, float cx2, float cy2)
    self->setCurve((size_t)arg1, (float)arg2, (float)arg3, (float)arg4, (float)arg5);

    olua_endinvoke(L);

    return 0;
}

static int _spine_CurveTimeline_setLinear(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "sp.CurveTimeline");
    olua_check_uint(L, 2, &arg1);

    // void setLinear(size_t frameIndex)
    self->setLinear((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_CurveTimeline_setStepped(lua_State *L)
{
    olua_startinvoke(L);

    spine::CurveTimeline *self = nullptr;
    lua_Unsigned arg1 = 0;       /** frameIndex */

    olua_to_cppobj(L, 1, (void **)&self, "sp.CurveTimeline");
    olua_check_uint(L, 2, &arg1);

    // void setStepped(size_t frameIndex)
    self->setStepped((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_CurveTimeline(lua_State *L)
{
    oluacls_class(L, "sp.CurveTimeline", "sp.Timeline");
    oluacls_func(L, "__move", _spine_CurveTimeline___move);
    oluacls_func(L, "getCurvePercent", _spine_CurveTimeline_getCurvePercent);
    oluacls_func(L, "getCurveType", _spine_CurveTimeline_getCurveType);
    oluacls_func(L, "getFrameCount", _spine_CurveTimeline_getFrameCount);
    oluacls_func(L, "setCurve", _spine_CurveTimeline_setCurve);
    oluacls_func(L, "setLinear", _spine_CurveTimeline_setLinear);
    oluacls_func(L, "setStepped", _spine_CurveTimeline_setStepped);
    oluacls_prop(L, "frameCount", _spine_CurveTimeline_getFrameCount, nullptr);

    olua_registerluatype<spine::CurveTimeline>(L, "sp.CurveTimeline");

    return 1;
}

static int _spine_AttachmentTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::AttachmentTimeline *)olua_toobj(L, 1, "sp.AttachmentTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_AttachmentTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::AttachmentTimeline *)olua_toobj(L, 1, "sp.AttachmentTimeline");
    olua_push_cppobj(L, self, "sp.AttachmentTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_AttachmentTimeline_getAttachmentNames(lua_State *L)
{
    olua_startinvoke(L);

    spine::AttachmentTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AttachmentTimeline");

    // const Vector<spine::String> &getAttachmentNames()
    const spine::Vector<spine::String> &ret = (const spine::Vector<spine::String> &)self->getAttachmentNames();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        manual_olua_push_spine_String(L, &((spine::Vector<spine::String> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AttachmentTimeline_getFrameCount(lua_State *L)
{
    olua_startinvoke(L);

    spine::AttachmentTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AttachmentTimeline");

    // size_t getFrameCount()
    size_t ret = (size_t)self->getFrameCount();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AttachmentTimeline_getFrames(lua_State *L)
{
    olua_startinvoke(L);

    spine::AttachmentTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AttachmentTimeline");

    // const Vector<float> &getFrames()
    const spine::Vector<float> &ret = (const spine::Vector<float> &)self->getFrames();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AttachmentTimeline_getSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::AttachmentTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.AttachmentTimeline");

    // size_t getSlotIndex()
    size_t ret = (size_t)self->getSlotIndex();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AttachmentTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // AttachmentTimeline(int frameCount)
    spine::AttachmentTimeline *ret = (spine::AttachmentTimeline *)new spine::AttachmentTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.AttachmentTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_AttachmentTimeline_setSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::AttachmentTimeline *self = nullptr;
    lua_Unsigned arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.AttachmentTimeline");
    olua_check_uint(L, 2, &arg1);

    // void setSlotIndex(size_t inValue)
    self->setSlotIndex((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_AttachmentTimeline(lua_State *L)
{
    oluacls_class(L, "sp.AttachmentTimeline", "sp.Timeline");
    oluacls_func(L, "__gc", _spine_AttachmentTimeline___gc);
    oluacls_func(L, "__move", _spine_AttachmentTimeline___move);
    oluacls_func(L, "getAttachmentNames", _spine_AttachmentTimeline_getAttachmentNames);
    oluacls_func(L, "getFrameCount", _spine_AttachmentTimeline_getFrameCount);
    oluacls_func(L, "getFrames", _spine_AttachmentTimeline_getFrames);
    oluacls_func(L, "getSlotIndex", _spine_AttachmentTimeline_getSlotIndex);
    oluacls_func(L, "new", _spine_AttachmentTimeline_new);
    oluacls_func(L, "setSlotIndex", _spine_AttachmentTimeline_setSlotIndex);
    oluacls_prop(L, "attachmentNames", _spine_AttachmentTimeline_getAttachmentNames, nullptr);
    oluacls_prop(L, "frameCount", _spine_AttachmentTimeline_getFrameCount, nullptr);
    oluacls_prop(L, "frames", _spine_AttachmentTimeline_getFrames, nullptr);
    oluacls_prop(L, "slotIndex", _spine_AttachmentTimeline_getSlotIndex, _spine_AttachmentTimeline_setSlotIndex);

    olua_registerluatype<spine::AttachmentTimeline>(L, "sp.AttachmentTimeline");

    return 1;
}

static int _spine_ColorTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::ColorTimeline *)olua_toobj(L, 1, "sp.ColorTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_ColorTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::ColorTimeline *)olua_toobj(L, 1, "sp.ColorTimeline");
    olua_push_cppobj(L, self, "sp.ColorTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_ColorTimeline_getFrames(lua_State *L)
{
    olua_startinvoke(L);

    spine::ColorTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.ColorTimeline");

    // Vector<float> &getFrames()
    spine::Vector<float> &ret = (spine::Vector<float> &)self->getFrames();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ColorTimeline_getSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ColorTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.ColorTimeline");

    // int getSlotIndex()
    int ret = (int)self->getSlotIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ColorTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // ColorTimeline(int frameCount)
    spine::ColorTimeline *ret = (spine::ColorTimeline *)new spine::ColorTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.ColorTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ColorTimeline_setSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::ColorTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.ColorTimeline");
    olua_check_int(L, 2, &arg1);

    // void setSlotIndex(int inValue)
    self->setSlotIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_ColorTimeline(lua_State *L)
{
    oluacls_class(L, "sp.ColorTimeline", "sp.CurveTimeline");
    oluacls_func(L, "__gc", _spine_ColorTimeline___gc);
    oluacls_func(L, "__move", _spine_ColorTimeline___move);
    oluacls_func(L, "getFrames", _spine_ColorTimeline_getFrames);
    oluacls_func(L, "getSlotIndex", _spine_ColorTimeline_getSlotIndex);
    oluacls_func(L, "new", _spine_ColorTimeline_new);
    oluacls_func(L, "setSlotIndex", _spine_ColorTimeline_setSlotIndex);
    oluacls_prop(L, "frames", _spine_ColorTimeline_getFrames, nullptr);
    oluacls_prop(L, "slotIndex", _spine_ColorTimeline_getSlotIndex, _spine_ColorTimeline_setSlotIndex);
    oluacls_const_integer(L, "ENTRIES", (lua_Integer)spine::ColorTimeline::ENTRIES);

    olua_registerluatype<spine::ColorTimeline>(L, "sp.ColorTimeline");

    return 1;
}

static int _spine_DeformTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::DeformTimeline *)olua_toobj(L, 1, "sp.DeformTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_DeformTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::DeformTimeline *)olua_toobj(L, 1, "sp.DeformTimeline");
    olua_push_cppobj(L, self, "sp.DeformTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_DeformTimeline_getAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::DeformTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.DeformTimeline");

    // spine::VertexAttachment *getAttachment()
    spine::VertexAttachment *ret = (spine::VertexAttachment *)self->getAttachment();
    int num_ret = olua_push_cppobj(L, ret, "sp.VertexAttachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_DeformTimeline_getFrames(lua_State *L)
{
    olua_startinvoke(L);

    spine::DeformTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.DeformTimeline");

    // Vector<float> &getFrames()
    spine::Vector<float> &ret = (spine::Vector<float> &)self->getFrames();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_DeformTimeline_getSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::DeformTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.DeformTimeline");

    // int getSlotIndex()
    int ret = (int)self->getSlotIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_DeformTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // DeformTimeline(int frameCount)
    spine::DeformTimeline *ret = (spine::DeformTimeline *)new spine::DeformTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.DeformTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_DeformTimeline_setAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::DeformTimeline *self = nullptr;
    spine::VertexAttachment *arg1 = nullptr;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.DeformTimeline");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.VertexAttachment");

    // void setAttachment(spine::VertexAttachment *inValue)
    self->setAttachment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_DeformTimeline_setSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::DeformTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.DeformTimeline");
    olua_check_int(L, 2, &arg1);

    // void setSlotIndex(int inValue)
    self->setSlotIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_DeformTimeline(lua_State *L)
{
    oluacls_class(L, "sp.DeformTimeline", "sp.CurveTimeline");
    oluacls_func(L, "__gc", _spine_DeformTimeline___gc);
    oluacls_func(L, "__move", _spine_DeformTimeline___move);
    oluacls_func(L, "getAttachment", _spine_DeformTimeline_getAttachment);
    oluacls_func(L, "getFrames", _spine_DeformTimeline_getFrames);
    oluacls_func(L, "getSlotIndex", _spine_DeformTimeline_getSlotIndex);
    oluacls_func(L, "new", _spine_DeformTimeline_new);
    oluacls_func(L, "setAttachment", _spine_DeformTimeline_setAttachment);
    oluacls_func(L, "setSlotIndex", _spine_DeformTimeline_setSlotIndex);
    oluacls_prop(L, "attachment", _spine_DeformTimeline_getAttachment, _spine_DeformTimeline_setAttachment);
    oluacls_prop(L, "frames", _spine_DeformTimeline_getFrames, nullptr);
    oluacls_prop(L, "slotIndex", _spine_DeformTimeline_getSlotIndex, _spine_DeformTimeline_setSlotIndex);

    olua_registerluatype<spine::DeformTimeline>(L, "sp.DeformTimeline");

    return 1;
}

static int _spine_DrawOrderTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::DrawOrderTimeline *)olua_toobj(L, 1, "sp.DrawOrderTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_DrawOrderTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::DrawOrderTimeline *)olua_toobj(L, 1, "sp.DrawOrderTimeline");
    olua_push_cppobj(L, self, "sp.DrawOrderTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_DrawOrderTimeline_getFrameCount(lua_State *L)
{
    olua_startinvoke(L);

    spine::DrawOrderTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.DrawOrderTimeline");

    // size_t getFrameCount()
    size_t ret = (size_t)self->getFrameCount();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_DrawOrderTimeline_getFrames(lua_State *L)
{
    olua_startinvoke(L);

    spine::DrawOrderTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.DrawOrderTimeline");

    // Vector<float> &getFrames()
    spine::Vector<float> &ret = (spine::Vector<float> &)self->getFrames();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_DrawOrderTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // DrawOrderTimeline(int frameCount)
    spine::DrawOrderTimeline *ret = (spine::DrawOrderTimeline *)new spine::DrawOrderTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.DrawOrderTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_DrawOrderTimeline(lua_State *L)
{
    oluacls_class(L, "sp.DrawOrderTimeline", "sp.Timeline");
    oluacls_func(L, "__gc", _spine_DrawOrderTimeline___gc);
    oluacls_func(L, "__move", _spine_DrawOrderTimeline___move);
    oluacls_func(L, "getFrameCount", _spine_DrawOrderTimeline_getFrameCount);
    oluacls_func(L, "getFrames", _spine_DrawOrderTimeline_getFrames);
    oluacls_func(L, "new", _spine_DrawOrderTimeline_new);
    oluacls_prop(L, "frameCount", _spine_DrawOrderTimeline_getFrameCount, nullptr);
    oluacls_prop(L, "frames", _spine_DrawOrderTimeline_getFrames, nullptr);

    olua_registerluatype<spine::DrawOrderTimeline>(L, "sp.DrawOrderTimeline");

    return 1;
}

static int _spine_EventTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::EventTimeline *)olua_toobj(L, 1, "sp.EventTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_EventTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::EventTimeline *)olua_toobj(L, 1, "sp.EventTimeline");
    olua_push_cppobj(L, self, "sp.EventTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_EventTimeline_getFrameCount(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventTimeline");

    // size_t getFrameCount()
    size_t ret = (size_t)self->getFrameCount();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventTimeline_getFrames(lua_State *L)
{
    olua_startinvoke(L);

    spine::EventTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.EventTimeline");

    // Vector<float> getFrames()
    spine::Vector<float> ret = (spine::Vector<float>)self->getFrames();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float>)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_EventTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // EventTimeline(int frameCount)
    spine::EventTimeline *ret = (spine::EventTimeline *)new spine::EventTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.EventTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_EventTimeline(lua_State *L)
{
    oluacls_class(L, "sp.EventTimeline", "sp.Timeline");
    oluacls_func(L, "__gc", _spine_EventTimeline___gc);
    oluacls_func(L, "__move", _spine_EventTimeline___move);
    oluacls_func(L, "getFrameCount", _spine_EventTimeline_getFrameCount);
    oluacls_func(L, "getFrames", _spine_EventTimeline_getFrames);
    oluacls_func(L, "new", _spine_EventTimeline_new);
    oluacls_prop(L, "frameCount", _spine_EventTimeline_getFrameCount, nullptr);
    oluacls_prop(L, "frames", _spine_EventTimeline_getFrames, nullptr);

    olua_registerluatype<spine::EventTimeline>(L, "sp.EventTimeline");

    return 1;
}

static int _spine_IkConstraintTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::IkConstraintTimeline *)olua_toobj(L, 1, "sp.IkConstraintTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_IkConstraintTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::IkConstraintTimeline *)olua_toobj(L, 1, "sp.IkConstraintTimeline");
    olua_push_cppobj(L, self, "sp.IkConstraintTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_IkConstraintTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // IkConstraintTimeline(int frameCount)
    spine::IkConstraintTimeline *ret = (spine::IkConstraintTimeline *)new spine::IkConstraintTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.IkConstraintTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_IkConstraintTimeline(lua_State *L)
{
    oluacls_class(L, "sp.IkConstraintTimeline", "sp.CurveTimeline");
    oluacls_func(L, "__gc", _spine_IkConstraintTimeline___gc);
    oluacls_func(L, "__move", _spine_IkConstraintTimeline___move);
    oluacls_func(L, "new", _spine_IkConstraintTimeline_new);
    oluacls_const_integer(L, "ENTRIES", (lua_Integer)spine::IkConstraintTimeline::ENTRIES);

    olua_registerluatype<spine::IkConstraintTimeline>(L, "sp.IkConstraintTimeline");

    return 1;
}

static int _spine_PathConstraintMixTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::PathConstraintMixTimeline *)olua_toobj(L, 1, "sp.PathConstraintMixTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintMixTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::PathConstraintMixTimeline *)olua_toobj(L, 1, "sp.PathConstraintMixTimeline");
    olua_push_cppobj(L, self, "sp.PathConstraintMixTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_PathConstraintMixTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // PathConstraintMixTimeline(int frameCount)
    spine::PathConstraintMixTimeline *ret = (spine::PathConstraintMixTimeline *)new spine::PathConstraintMixTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.PathConstraintMixTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_PathConstraintMixTimeline(lua_State *L)
{
    oluacls_class(L, "sp.PathConstraintMixTimeline", "sp.CurveTimeline");
    oluacls_func(L, "__gc", _spine_PathConstraintMixTimeline___gc);
    oluacls_func(L, "__move", _spine_PathConstraintMixTimeline___move);
    oluacls_func(L, "new", _spine_PathConstraintMixTimeline_new);
    oluacls_const_integer(L, "ENTRIES", (lua_Integer)spine::PathConstraintMixTimeline::ENTRIES);

    olua_registerluatype<spine::PathConstraintMixTimeline>(L, "sp.PathConstraintMixTimeline");

    return 1;
}

static int _spine_PathConstraintPositionTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::PathConstraintPositionTimeline *)olua_toobj(L, 1, "sp.PathConstraintPositionTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraintPositionTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::PathConstraintPositionTimeline *)olua_toobj(L, 1, "sp.PathConstraintPositionTimeline");
    olua_push_cppobj(L, self, "sp.PathConstraintPositionTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_PathConstraintPositionTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // PathConstraintPositionTimeline(int frameCount)
    spine::PathConstraintPositionTimeline *ret = (spine::PathConstraintPositionTimeline *)new spine::PathConstraintPositionTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.PathConstraintPositionTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_PathConstraintPositionTimeline(lua_State *L)
{
    oluacls_class(L, "sp.PathConstraintPositionTimeline", "sp.CurveTimeline");
    oluacls_func(L, "__gc", _spine_PathConstraintPositionTimeline___gc);
    oluacls_func(L, "__move", _spine_PathConstraintPositionTimeline___move);
    oluacls_func(L, "new", _spine_PathConstraintPositionTimeline_new);
    oluacls_const_integer(L, "ENTRIES", (lua_Integer)spine::PathConstraintPositionTimeline::ENTRIES);

    olua_registerluatype<spine::PathConstraintPositionTimeline>(L, "sp.PathConstraintPositionTimeline");

    return 1;
}

static int _spine_PathConstraintSpacingTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::PathConstraintSpacingTimeline *)olua_toobj(L, 1, "sp.PathConstraintSpacingTimeline");
    olua_push_cppobj(L, self, "sp.PathConstraintSpacingTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_PathConstraintSpacingTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // PathConstraintSpacingTimeline(int frameCount)
    spine::PathConstraintSpacingTimeline *ret = (spine::PathConstraintSpacingTimeline *)new spine::PathConstraintSpacingTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.PathConstraintSpacingTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_PathConstraintSpacingTimeline(lua_State *L)
{
    oluacls_class(L, "sp.PathConstraintSpacingTimeline", "sp.PathConstraintPositionTimeline");
    oluacls_func(L, "__move", _spine_PathConstraintSpacingTimeline___move);
    oluacls_func(L, "new", _spine_PathConstraintSpacingTimeline_new);

    olua_registerluatype<spine::PathConstraintSpacingTimeline>(L, "sp.PathConstraintSpacingTimeline");

    return 1;
}

static int _spine_TranslateTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::TranslateTimeline *)olua_toobj(L, 1, "sp.TranslateTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_TranslateTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::TranslateTimeline *)olua_toobj(L, 1, "sp.TranslateTimeline");
    olua_push_cppobj(L, self, "sp.TranslateTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_TranslateTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // TranslateTimeline(int frameCount)
    spine::TranslateTimeline *ret = (spine::TranslateTimeline *)new spine::TranslateTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.TranslateTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_TranslateTimeline(lua_State *L)
{
    oluacls_class(L, "sp.TranslateTimeline", "sp.CurveTimeline");
    oluacls_func(L, "__gc", _spine_TranslateTimeline___gc);
    oluacls_func(L, "__move", _spine_TranslateTimeline___move);
    oluacls_func(L, "new", _spine_TranslateTimeline_new);
    oluacls_const_integer(L, "ENTRIES", (lua_Integer)spine::TranslateTimeline::ENTRIES);

    olua_registerluatype<spine::TranslateTimeline>(L, "sp.TranslateTimeline");

    return 1;
}

static int _spine_ShearTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::ShearTimeline *)olua_toobj(L, 1, "sp.ShearTimeline");
    olua_push_cppobj(L, self, "sp.ShearTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_ShearTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // ShearTimeline(int frameCount)
    spine::ShearTimeline *ret = (spine::ShearTimeline *)new spine::ShearTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.ShearTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_ShearTimeline(lua_State *L)
{
    oluacls_class(L, "sp.ShearTimeline", "sp.TranslateTimeline");
    oluacls_func(L, "__move", _spine_ShearTimeline___move);
    oluacls_func(L, "new", _spine_ShearTimeline_new);

    olua_registerluatype<spine::ShearTimeline>(L, "sp.ShearTimeline");

    return 1;
}

static int _spine_TransformConstraintTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::TransformConstraintTimeline *)olua_toobj(L, 1, "sp.TransformConstraintTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_TransformConstraintTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::TransformConstraintTimeline *)olua_toobj(L, 1, "sp.TransformConstraintTimeline");
    olua_push_cppobj(L, self, "sp.TransformConstraintTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_TransformConstraintTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // TransformConstraintTimeline(int frameCount)
    spine::TransformConstraintTimeline *ret = (spine::TransformConstraintTimeline *)new spine::TransformConstraintTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.TransformConstraintTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_TransformConstraintTimeline(lua_State *L)
{
    oluacls_class(L, "sp.TransformConstraintTimeline", "sp.CurveTimeline");
    oluacls_func(L, "__gc", _spine_TransformConstraintTimeline___gc);
    oluacls_func(L, "__move", _spine_TransformConstraintTimeline___move);
    oluacls_func(L, "new", _spine_TransformConstraintTimeline_new);
    oluacls_const_integer(L, "ENTRIES", (lua_Integer)spine::TransformConstraintTimeline::ENTRIES);

    olua_registerluatype<spine::TransformConstraintTimeline>(L, "sp.TransformConstraintTimeline");

    return 1;
}

static int _spine_ScaleTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::ScaleTimeline *)olua_toobj(L, 1, "sp.ScaleTimeline");
    olua_push_cppobj(L, self, "sp.ScaleTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_ScaleTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // ScaleTimeline(int frameCount)
    spine::ScaleTimeline *ret = (spine::ScaleTimeline *)new spine::ScaleTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.ScaleTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_ScaleTimeline(lua_State *L)
{
    oluacls_class(L, "sp.ScaleTimeline", "sp.TranslateTimeline");
    oluacls_func(L, "__move", _spine_ScaleTimeline___move);
    oluacls_func(L, "new", _spine_ScaleTimeline_new);

    olua_registerluatype<spine::ScaleTimeline>(L, "sp.ScaleTimeline");

    return 1;
}

static int _spine_RotateTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::RotateTimeline *)olua_toobj(L, 1, "sp.RotateTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_RotateTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::RotateTimeline *)olua_toobj(L, 1, "sp.RotateTimeline");
    olua_push_cppobj(L, self, "sp.RotateTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_RotateTimeline_getBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RotateTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RotateTimeline");

    // int getBoneIndex()
    int ret = (int)self->getBoneIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RotateTimeline_getFrames(lua_State *L)
{
    olua_startinvoke(L);

    spine::RotateTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RotateTimeline");

    // Vector<float> &getFrames()
    spine::Vector<float> &ret = (spine::Vector<float> &)self->getFrames();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RotateTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // RotateTimeline(int frameCount)
    spine::RotateTimeline *ret = (spine::RotateTimeline *)new spine::RotateTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.RotateTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RotateTimeline_setBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::RotateTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RotateTimeline");
    olua_check_int(L, 2, &arg1);

    // void setBoneIndex(int inValue)
    self->setBoneIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_RotateTimeline(lua_State *L)
{
    oluacls_class(L, "sp.RotateTimeline", "sp.CurveTimeline");
    oluacls_func(L, "__gc", _spine_RotateTimeline___gc);
    oluacls_func(L, "__move", _spine_RotateTimeline___move);
    oluacls_func(L, "getBoneIndex", _spine_RotateTimeline_getBoneIndex);
    oluacls_func(L, "getFrames", _spine_RotateTimeline_getFrames);
    oluacls_func(L, "new", _spine_RotateTimeline_new);
    oluacls_func(L, "setBoneIndex", _spine_RotateTimeline_setBoneIndex);
    oluacls_prop(L, "boneIndex", _spine_RotateTimeline_getBoneIndex, _spine_RotateTimeline_setBoneIndex);
    oluacls_prop(L, "frames", _spine_RotateTimeline_getFrames, nullptr);
    oluacls_const_integer(L, "ENTRIES", (lua_Integer)spine::RotateTimeline::ENTRIES);

    olua_registerluatype<spine::RotateTimeline>(L, "sp.RotateTimeline");

    return 1;
}

static int _spine_TwoColorTimeline___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::TwoColorTimeline *)olua_toobj(L, 1, "sp.TwoColorTimeline");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_TwoColorTimeline___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::TwoColorTimeline *)olua_toobj(L, 1, "sp.TwoColorTimeline");
    olua_push_cppobj(L, self, "sp.TwoColorTimeline");

    olua_endinvoke(L);

    return 1;
}

static int _spine_TwoColorTimeline_getSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TwoColorTimeline *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TwoColorTimeline");

    // int getSlotIndex()
    int ret = (int)self->getSlotIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TwoColorTimeline_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frameCount */

    olua_check_int(L, 1, &arg1);

    // TwoColorTimeline(int frameCount)
    spine::TwoColorTimeline *ret = (spine::TwoColorTimeline *)new spine::TwoColorTimeline((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.TwoColorTimeline");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TwoColorTimeline_setSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TwoColorTimeline *self = nullptr;
    lua_Integer arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TwoColorTimeline");
    olua_check_int(L, 2, &arg1);

    // void setSlotIndex(int inValue)
    self->setSlotIndex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_TwoColorTimeline(lua_State *L)
{
    oluacls_class(L, "sp.TwoColorTimeline", "sp.CurveTimeline");
    oluacls_func(L, "__gc", _spine_TwoColorTimeline___gc);
    oluacls_func(L, "__move", _spine_TwoColorTimeline___move);
    oluacls_func(L, "getSlotIndex", _spine_TwoColorTimeline_getSlotIndex);
    oluacls_func(L, "new", _spine_TwoColorTimeline_new);
    oluacls_func(L, "setSlotIndex", _spine_TwoColorTimeline_setSlotIndex);
    oluacls_prop(L, "slotIndex", _spine_TwoColorTimeline_getSlotIndex, _spine_TwoColorTimeline_setSlotIndex);
    oluacls_const_integer(L, "ENTRIES", (lua_Integer)spine::TwoColorTimeline::ENTRIES);

    olua_registerluatype<spine::TwoColorTimeline>(L, "sp.TwoColorTimeline");

    return 1;
}

static int _spine_VertexEffect___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::VertexEffect *)olua_toobj(L, 1, "sp.VertexEffect");
    olua_push_cppobj(L, self, "sp.VertexEffect");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_spine_VertexEffect(lua_State *L)
{
    oluacls_class(L, "sp.VertexEffect", "sp.SpineObject");
    oluacls_func(L, "__move", _spine_VertexEffect___move);

    olua_registerluatype<spine::VertexEffect>(L, "sp.VertexEffect");

    return 1;
}

static int _spine_SwirlVertexEffect___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::SwirlVertexEffect *)olua_toobj(L, 1, "sp.SwirlVertexEffect");
    olua_push_cppobj(L, self, "sp.SwirlVertexEffect");

    olua_endinvoke(L);

    return 1;
}

static int _spine_SwirlVertexEffect_getAngle(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");

    // float getAngle()
    float ret = (float)self->getAngle();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SwirlVertexEffect_getCenterX(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");

    // float getCenterX()
    float ret = (float)self->getCenterX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SwirlVertexEffect_getCenterY(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");

    // float getCenterY()
    float ret = (float)self->getCenterY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SwirlVertexEffect_getRadius(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");

    // float getRadius()
    float ret = (float)self->getRadius();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SwirlVertexEffect_getWorldX(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");

    // float getWorldX()
    float ret = (float)self->getWorldX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SwirlVertexEffect_getWorldY(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");

    // float getWorldY()
    float ret = (float)self->getWorldY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SwirlVertexEffect_setAngle(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;
    lua_Number arg1 = 0;       /** angle */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");
    olua_check_number(L, 2, &arg1);

    // void setAngle(float angle)
    self->setAngle((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SwirlVertexEffect_setCenterX(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;
    lua_Number arg1 = 0;       /** centerX */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");
    olua_check_number(L, 2, &arg1);

    // void setCenterX(float centerX)
    self->setCenterX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SwirlVertexEffect_setCenterY(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;
    lua_Number arg1 = 0;       /** centerY */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");
    olua_check_number(L, 2, &arg1);

    // void setCenterY(float centerY)
    self->setCenterY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SwirlVertexEffect_setRadius(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;
    lua_Number arg1 = 0;       /** radius */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");
    olua_check_number(L, 2, &arg1);

    // void setRadius(float radius)
    self->setRadius((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SwirlVertexEffect_setWorldX(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;
    lua_Number arg1 = 0;       /** worldX */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");
    olua_check_number(L, 2, &arg1);

    // void setWorldX(float worldX)
    self->setWorldX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SwirlVertexEffect_setWorldY(lua_State *L)
{
    olua_startinvoke(L);

    spine::SwirlVertexEffect *self = nullptr;
    lua_Number arg1 = 0;       /** worldY */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SwirlVertexEffect");
    olua_check_number(L, 2, &arg1);

    // void setWorldY(float worldY)
    self->setWorldY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_SwirlVertexEffect(lua_State *L)
{
    oluacls_class(L, "sp.SwirlVertexEffect", "sp.VertexEffect");
    oluacls_func(L, "__move", _spine_SwirlVertexEffect___move);
    oluacls_func(L, "getAngle", _spine_SwirlVertexEffect_getAngle);
    oluacls_func(L, "getCenterX", _spine_SwirlVertexEffect_getCenterX);
    oluacls_func(L, "getCenterY", _spine_SwirlVertexEffect_getCenterY);
    oluacls_func(L, "getRadius", _spine_SwirlVertexEffect_getRadius);
    oluacls_func(L, "getWorldX", _spine_SwirlVertexEffect_getWorldX);
    oluacls_func(L, "getWorldY", _spine_SwirlVertexEffect_getWorldY);
    oluacls_func(L, "setAngle", _spine_SwirlVertexEffect_setAngle);
    oluacls_func(L, "setCenterX", _spine_SwirlVertexEffect_setCenterX);
    oluacls_func(L, "setCenterY", _spine_SwirlVertexEffect_setCenterY);
    oluacls_func(L, "setRadius", _spine_SwirlVertexEffect_setRadius);
    oluacls_func(L, "setWorldX", _spine_SwirlVertexEffect_setWorldX);
    oluacls_func(L, "setWorldY", _spine_SwirlVertexEffect_setWorldY);
    oluacls_prop(L, "angle", _spine_SwirlVertexEffect_getAngle, _spine_SwirlVertexEffect_setAngle);
    oluacls_prop(L, "centerX", _spine_SwirlVertexEffect_getCenterX, _spine_SwirlVertexEffect_setCenterX);
    oluacls_prop(L, "centerY", _spine_SwirlVertexEffect_getCenterY, _spine_SwirlVertexEffect_setCenterY);
    oluacls_prop(L, "radius", _spine_SwirlVertexEffect_getRadius, _spine_SwirlVertexEffect_setRadius);
    oluacls_prop(L, "worldX", _spine_SwirlVertexEffect_getWorldX, _spine_SwirlVertexEffect_setWorldX);
    oluacls_prop(L, "worldY", _spine_SwirlVertexEffect_getWorldY, _spine_SwirlVertexEffect_setWorldY);

    olua_registerluatype<spine::SwirlVertexEffect>(L, "sp.SwirlVertexEffect");

    return 1;
}

static int _spine_JitterVertexEffect___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::JitterVertexEffect *)olua_toobj(L, 1, "sp.JitterVertexEffect");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_JitterVertexEffect___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::JitterVertexEffect *)olua_toobj(L, 1, "sp.JitterVertexEffect");
    olua_push_cppobj(L, self, "sp.JitterVertexEffect");

    olua_endinvoke(L);

    return 1;
}

static int _spine_JitterVertexEffect_getJitterX(lua_State *L)
{
    olua_startinvoke(L);

    spine::JitterVertexEffect *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.JitterVertexEffect");

    // float getJitterX()
    float ret = (float)self->getJitterX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_JitterVertexEffect_getJitterY(lua_State *L)
{
    olua_startinvoke(L);

    spine::JitterVertexEffect *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.JitterVertexEffect");

    // float getJitterY()
    float ret = (float)self->getJitterY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_JitterVertexEffect_new(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** jitterX */
    lua_Number arg2 = 0;       /** jitterY */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // JitterVertexEffect(float jitterX, float jitterY)
    spine::JitterVertexEffect *ret = (spine::JitterVertexEffect *)new spine::JitterVertexEffect((float)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.JitterVertexEffect");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_JitterVertexEffect_setJitterX(lua_State *L)
{
    olua_startinvoke(L);

    spine::JitterVertexEffect *self = nullptr;
    lua_Number arg1 = 0;       /** jitterX */

    olua_to_cppobj(L, 1, (void **)&self, "sp.JitterVertexEffect");
    olua_check_number(L, 2, &arg1);

    // void setJitterX(float jitterX)
    self->setJitterX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_JitterVertexEffect_setJitterY(lua_State *L)
{
    olua_startinvoke(L);

    spine::JitterVertexEffect *self = nullptr;
    lua_Number arg1 = 0;       /** jitterY */

    olua_to_cppobj(L, 1, (void **)&self, "sp.JitterVertexEffect");
    olua_check_number(L, 2, &arg1);

    // void setJitterY(float jitterY)
    self->setJitterY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_JitterVertexEffect(lua_State *L)
{
    oluacls_class(L, "sp.JitterVertexEffect", "sp.VertexEffect");
    oluacls_func(L, "__gc", _spine_JitterVertexEffect___gc);
    oluacls_func(L, "__move", _spine_JitterVertexEffect___move);
    oluacls_func(L, "getJitterX", _spine_JitterVertexEffect_getJitterX);
    oluacls_func(L, "getJitterY", _spine_JitterVertexEffect_getJitterY);
    oluacls_func(L, "new", _spine_JitterVertexEffect_new);
    oluacls_func(L, "setJitterX", _spine_JitterVertexEffect_setJitterX);
    oluacls_func(L, "setJitterY", _spine_JitterVertexEffect_setJitterY);
    oluacls_prop(L, "jitterX", _spine_JitterVertexEffect_getJitterX, _spine_JitterVertexEffect_setJitterX);
    oluacls_prop(L, "jitterY", _spine_JitterVertexEffect_getJitterY, _spine_JitterVertexEffect_setJitterY);

    olua_registerluatype<spine::JitterVertexEffect>(L, "sp.JitterVertexEffect");

    return 1;
}

static int _spine_Polygon___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Polygon *)olua_toobj(L, 1, "sp.Polygon");
    olua_push_cppobj(L, self, "sp.Polygon");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_spine_Polygon(lua_State *L)
{
    oluacls_class(L, "sp.Polygon", "sp.SpineObject");
    oluacls_func(L, "__move", _spine_Polygon___move);

    olua_registerluatype<spine::Polygon>(L, "sp.Polygon");

    return 1;
}

static int _spine_Skin___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Skin *)olua_toobj(L, 1, "sp.Skin");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skin___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Skin *)olua_toobj(L, 1, "sp.Skin");
    olua_push_cppobj(L, self, "sp.Skin");

    olua_endinvoke(L);

    return 1;
}

static int _spine_Skin_addSkin(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;
    spine::Skin *arg1 = nullptr;       /** other */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skin");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Skin");

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

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skin");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Skin");

    // void copySkin(spine::Skin *other)
    self->copySkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skin_getAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;
    lua_Unsigned arg1 = 0;       /** slotIndex */
    spine::String arg2;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skin");
    olua_check_uint(L, 2, &arg1);
    manual_olua_check_spine_String(L, 3, &arg2);

    // spine::Attachment *getAttachment(size_t slotIndex, const spine::String &name)
    spine::Attachment *ret = (spine::Attachment *)self->getAttachment((size_t)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skin_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skin");

    // Vector<spine::BoneData *> &getBones()
    spine::Vector<spine::BoneData *> &ret = (spine::Vector<spine::BoneData *> &)self->getBones();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skin_getConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skin");

    // Vector<spine::ConstraintData *> &getConstraints()
    spine::Vector<spine::ConstraintData *> &ret = (spine::Vector<spine::ConstraintData *> &)self->getConstraints();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.ConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skin_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skin");

    // const spine::String &getName()
    const spine::String &ret = (const spine::String &)self->getName();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skin_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // Skin(const spine::String &name)
    spine::Skin *ret = (spine::Skin *)new spine::Skin(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.Skin");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skin_removeAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;
    lua_Unsigned arg1 = 0;       /** slotIndex */
    spine::String arg2;       /** name */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skin");
    olua_check_uint(L, 2, &arg1);
    manual_olua_check_spine_String(L, 3, &arg2);

    // void removeAttachment(size_t slotIndex, const spine::String &name)
    self->removeAttachment((size_t)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skin_setAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skin *self = nullptr;
    lua_Unsigned arg1 = 0;       /** slotIndex */
    spine::String arg2;       /** name */
    spine::Attachment *arg3 = nullptr;       /** attachment */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skin");
    olua_check_uint(L, 2, &arg1);
    manual_olua_check_spine_String(L, 3, &arg2);
    olua_check_cppobj(L, 4, (void **)&arg3, "sp.Attachment");

    // void setAttachment(size_t slotIndex, const spine::String &name, spine::Attachment *attachment)
    self->setAttachment((size_t)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_Skin(lua_State *L)
{
    oluacls_class(L, "sp.Skin", "sp.SpineObject");
    oluacls_func(L, "__gc", _spine_Skin___gc);
    oluacls_func(L, "__move", _spine_Skin___move);
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

    olua_registerluatype<spine::Skin>(L, "sp.Skin");

    return 1;
}

static int _spine_Atlas___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Atlas *)olua_toobj(L, 1, "sp.Atlas");
    olua_push_cppobj(L, self, "sp.Atlas");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_spine_Atlas(lua_State *L)
{
    oluacls_class(L, "sp.Atlas", "sp.SpineObject");
    oluacls_func(L, "__move", _spine_Atlas___move);

    olua_registerluatype<spine::Atlas>(L, "sp.Atlas");

    return 1;
}

static int _spine_Bone___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Bone *)olua_toobj(L, 1, "sp.Bone");
    olua_push_cppobj(L, self, "sp.Bone");

    olua_endinvoke(L);

    return 1;
}

static int _spine_Bone_getA(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getA()
    float ret = (float)self->getA();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getAScaleX()
    float ret = (float)self->getAScaleX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getAScaleY()
    float ret = (float)self->getAScaleY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getAShearX()
    float ret = (float)self->getAShearX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getAShearY()
    float ret = (float)self->getAShearY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getAX()
    float ret = (float)self->getAX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getAY()
    float ret = (float)self->getAY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getAppliedRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getAppliedRotation()
    float ret = (float)self->getAppliedRotation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getB(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getB()
    float ret = (float)self->getB();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getC(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getC()
    float ret = (float)self->getC();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getChildren(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // Vector<spine::Bone *> &getChildren()
    spine::Vector<spine::Bone *> &ret = (spine::Vector<spine::Bone *> &)self->getChildren();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getD(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getD()
    float ret = (float)self->getD();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getParent(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // spine::Bone *getParent()
    spine::Bone *ret = (spine::Bone *)self->getParent();
    int num_ret = olua_push_cppobj(L, ret, "sp.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getRotation()
    float ret = (float)self->getRotation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getScaleX()
    float ret = (float)self->getScaleX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getScaleY()
    float ret = (float)self->getScaleY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getShearX()
    float ret = (float)self->getShearX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getShearY()
    float ret = (float)self->getShearY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldRotationX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getWorldRotationX()
    float ret = (float)self->getWorldRotationX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldRotationY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getWorldRotationY()
    float ret = (float)self->getWorldRotationY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getWorldScaleX()
    float ret = (float)self->getWorldScaleX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getWorldScaleY()
    float ret = (float)self->getWorldScaleY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldToLocalRotationX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getWorldToLocalRotationX()
    float ret = (float)self->getWorldToLocalRotationX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldToLocalRotationY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getWorldToLocalRotationY()
    float ret = (float)self->getWorldToLocalRotationY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getWorldX()
    float ret = (float)self->getWorldX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getWorldY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getWorldY()
    float ret = (float)self->getWorldY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getX()
    float ret = (float)self->getX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // float getY()
    float ret = (float)self->getY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_isAppliedValid(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // bool isAppliedValid()
    bool ret = (bool)self->isAppliedValid();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_isYDown(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isYDown()
    bool ret = (bool)spine::Bone::isYDown();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_localToWorldRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** localRotation */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // float localToWorldRotation(float localRotation)
    float ret = (float)self->localToWorldRotation((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Bone_rotateWorld(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** degrees */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void rotateWorld(float degrees)
    self->rotateWorld((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setA(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setA(float inValue)
    self->setA((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAScaleX(float inValue)
    self->setAScaleX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAScaleY(float inValue)
    self->setAScaleY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAShearX(float inValue)
    self->setAShearX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAShearY(float inValue)
    self->setAShearY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAX(float inValue)
    self->setAX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAY(float inValue)
    self->setAY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAppliedRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setAppliedRotation(float inValue)
    self->setAppliedRotation((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setAppliedValid(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    bool arg1 = false;       /** valid */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_bool(L, 2, &arg1);

    // void setAppliedValid(bool valid)
    self->setAppliedValid(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setB(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setB(float inValue)
    self->setB((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setC(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setC(float inValue)
    self->setC((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setD(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setD(float inValue)
    self->setD((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setRotation(float inValue)
    self->setRotation((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setScaleX(float inValue)
    self->setScaleX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setScaleY(float inValue)
    self->setScaleY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setShearX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setShearX(float inValue)
    self->setShearX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setShearY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setShearY(float inValue)
    self->setShearY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // void setToSetupPose()
    self->setToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setWorldX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setWorldX(float inValue)
    self->setWorldX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setWorldY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setWorldY(float inValue)
    self->setWorldY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY((float)arg1);

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

static int _spine_Bone_updateWorldTransform1(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");

    // void updateWorldTransform()
    self->updateWorldTransform();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_updateWorldTransform2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** rotation */
    lua_Number arg4 = 0;       /** scaleX */
    lua_Number arg5 = 0;       /** scaleY */
    lua_Number arg6 = 0;       /** shearX */
    lua_Number arg7 = 0;       /** shearY */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_number(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_number(L, 8, &arg7);

    // void updateWorldTransform(float x, float y, float rotation, float scaleX, float scaleY, float shearX, float shearY)
    self->updateWorldTransform((float)arg1, (float)arg2, (float)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Bone_updateWorldTransform(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void updateWorldTransform()
        return _spine_Bone_updateWorldTransform1(L);
    }

    if (num_args == 7) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_number(L, 6)) && (olua_is_number(L, 7)) && (olua_is_number(L, 8))) {
            // void updateWorldTransform(float x, float y, float rotation, float scaleX, float scaleY, float shearX, float shearY)
            return _spine_Bone_updateWorldTransform2(L);
        // }
    }

    luaL_error(L, "method 'spine::Bone::updateWorldTransform' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_Bone_worldToLocalRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::Bone *self = nullptr;
    lua_Number arg1 = 0;       /** worldRotation */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Bone");
    olua_check_number(L, 2, &arg1);

    // float worldToLocalRotation(float worldRotation)
    float ret = (float)self->worldToLocalRotation((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_Bone(lua_State *L)
{
    oluacls_class(L, "sp.Bone", "sp.Updatable");
    oluacls_func(L, "__move", _spine_Bone___move);
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
    oluacls_func(L, "getParent", _spine_Bone_getParent);
    oluacls_func(L, "getRotation", _spine_Bone_getRotation);
    oluacls_func(L, "getScaleX", _spine_Bone_getScaleX);
    oluacls_func(L, "getScaleY", _spine_Bone_getScaleY);
    oluacls_func(L, "getShearX", _spine_Bone_getShearX);
    oluacls_func(L, "getShearY", _spine_Bone_getShearY);
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
    oluacls_func(L, "isAppliedValid", _spine_Bone_isAppliedValid);
    oluacls_func(L, "isYDown", _spine_Bone_isYDown);
    oluacls_func(L, "localToWorldRotation", _spine_Bone_localToWorldRotation);
    oluacls_func(L, "rotateWorld", _spine_Bone_rotateWorld);
    oluacls_func(L, "setA", _spine_Bone_setA);
    oluacls_func(L, "setAScaleX", _spine_Bone_setAScaleX);
    oluacls_func(L, "setAScaleY", _spine_Bone_setAScaleY);
    oluacls_func(L, "setAShearX", _spine_Bone_setAShearX);
    oluacls_func(L, "setAShearY", _spine_Bone_setAShearY);
    oluacls_func(L, "setAX", _spine_Bone_setAX);
    oluacls_func(L, "setAY", _spine_Bone_setAY);
    oluacls_func(L, "setAppliedRotation", _spine_Bone_setAppliedRotation);
    oluacls_func(L, "setAppliedValid", _spine_Bone_setAppliedValid);
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
    oluacls_prop(L, "appliedValid", _spine_Bone_isAppliedValid, _spine_Bone_setAppliedValid);
    oluacls_prop(L, "ax", _spine_Bone_getAX, _spine_Bone_setAX);
    oluacls_prop(L, "ay", _spine_Bone_getAY, _spine_Bone_setAY);
    oluacls_prop(L, "b", _spine_Bone_getB, _spine_Bone_setB);
    oluacls_prop(L, "c", _spine_Bone_getC, _spine_Bone_setC);
    oluacls_prop(L, "children", _spine_Bone_getChildren, nullptr);
    oluacls_prop(L, "d", _spine_Bone_getD, _spine_Bone_setD);
    oluacls_prop(L, "parent", _spine_Bone_getParent, nullptr);
    oluacls_prop(L, "rotation", _spine_Bone_getRotation, _spine_Bone_setRotation);
    oluacls_prop(L, "scaleX", _spine_Bone_getScaleX, _spine_Bone_setScaleX);
    oluacls_prop(L, "scaleY", _spine_Bone_getScaleY, _spine_Bone_setScaleY);
    oluacls_prop(L, "shearX", _spine_Bone_getShearX, _spine_Bone_setShearX);
    oluacls_prop(L, "shearY", _spine_Bone_getShearY, _spine_Bone_setShearY);
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

    olua_registerluatype<spine::Bone>(L, "sp.Bone");

    return 1;
}

static int _spine_Slot___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Slot *)olua_toobj(L, 1, "sp.Slot");
    olua_push_cppobj(L, self, "sp.Slot");

    olua_endinvoke(L);

    return 1;
}

static int _spine_Slot_getAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Slot");

    // spine::Attachment *getAttachment()
    spine::Attachment *ret = (spine::Attachment *)self->getAttachment();
    int num_ret = olua_push_cppobj(L, ret, "sp.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getAttachmentTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Slot");

    // float getAttachmentTime()
    float ret = (float)self->getAttachmentTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Slot");

    // spine::Color &getColor()
    spine::Color &ret = (spine::Color &)self->getColor();
    int num_ret = manual_olua_push_spine_Color(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getDarkColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Slot");

    // spine::Color &getDarkColor()
    spine::Color &ret = (spine::Color &)self->getDarkColor();
    int num_ret = manual_olua_push_spine_Color(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_getDeform(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Slot");

    // Vector<float> &getDeform()
    spine::Vector<float> &ret = (spine::Vector<float> &)self->getDeform();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_hasDarkColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Slot");

    // bool hasDarkColor()
    bool ret = (bool)self->hasDarkColor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Slot_setAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;
    spine::Attachment *arg1 = nullptr;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Slot");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Attachment");

    // void setAttachment(spine::Attachment *inValue)
    self->setAttachment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Slot_setAttachmentTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Slot");
    olua_check_number(L, 2, &arg1);

    // void setAttachmentTime(float inValue)
    self->setAttachmentTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Slot_setToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::Slot *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Slot");

    // void setToSetupPose()
    self->setToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_Slot(lua_State *L)
{
    oluacls_class(L, "sp.Slot", "sp.SpineObject");
    oluacls_func(L, "__move", _spine_Slot___move);
    oluacls_func(L, "getAttachment", _spine_Slot_getAttachment);
    oluacls_func(L, "getAttachmentTime", _spine_Slot_getAttachmentTime);
    oluacls_func(L, "getColor", _spine_Slot_getColor);
    oluacls_func(L, "getDarkColor", _spine_Slot_getDarkColor);
    oluacls_func(L, "getDeform", _spine_Slot_getDeform);
    oluacls_func(L, "hasDarkColor", _spine_Slot_hasDarkColor);
    oluacls_func(L, "setAttachment", _spine_Slot_setAttachment);
    oluacls_func(L, "setAttachmentTime", _spine_Slot_setAttachmentTime);
    oluacls_func(L, "setToSetupPose", _spine_Slot_setToSetupPose);
    oluacls_prop(L, "attachment", _spine_Slot_getAttachment, _spine_Slot_setAttachment);
    oluacls_prop(L, "attachmentTime", _spine_Slot_getAttachmentTime, _spine_Slot_setAttachmentTime);
    oluacls_prop(L, "color", _spine_Slot_getColor, nullptr);
    oluacls_prop(L, "darkColor", _spine_Slot_getDarkColor, nullptr);
    oluacls_prop(L, "deform", _spine_Slot_getDeform, nullptr);

    olua_registerluatype<spine::Slot>(L, "sp.Slot");

    return 1;
}

static int _spine_Attachment___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Attachment *)olua_toobj(L, 1, "sp.Attachment");
    olua_push_cppobj(L, self, "sp.Attachment");

    olua_endinvoke(L);

    return 1;
}

static int _spine_Attachment_copy(lua_State *L)
{
    olua_startinvoke(L);

    spine::Attachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Attachment");

    // spine::Attachment *copy()
    spine::Attachment *ret = (spine::Attachment *)self->copy();
    int num_ret = olua_push_cppobj(L, ret, "sp.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Attachment_dereference(lua_State *L)
{
    olua_startinvoke(L);

    spine::Attachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Attachment");

    // void dereference()
    self->dereference();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Attachment_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::Attachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Attachment");

    // const spine::String &getName()
    const spine::String &ret = (const spine::String &)self->getName();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Attachment_getRefCount(lua_State *L)
{
    olua_startinvoke(L);

    spine::Attachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Attachment");

    // int getRefCount()
    int ret = (int)self->getRefCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Attachment_reference(lua_State *L)
{
    olua_startinvoke(L);

    spine::Attachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Attachment");

    // void reference()
    self->reference();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_Attachment(lua_State *L)
{
    oluacls_class(L, "sp.Attachment", "sp.SpineObject");
    oluacls_func(L, "__move", _spine_Attachment___move);
    oluacls_func(L, "copy", _spine_Attachment_copy);
    oluacls_func(L, "dereference", _spine_Attachment_dereference);
    oluacls_func(L, "getName", _spine_Attachment_getName);
    oluacls_func(L, "getRefCount", _spine_Attachment_getRefCount);
    oluacls_func(L, "reference", _spine_Attachment_reference);
    oluacls_prop(L, "name", _spine_Attachment_getName, nullptr);
    oluacls_prop(L, "refCount", _spine_Attachment_getRefCount, nullptr);

    olua_registerluatype<spine::Attachment>(L, "sp.Attachment");

    return 1;
}

static int _spine_VertexAttachment___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::VertexAttachment *)olua_toobj(L, 1, "sp.VertexAttachment");
    olua_push_cppobj(L, self, "sp.VertexAttachment");

    olua_endinvoke(L);

    return 1;
}

static int _spine_VertexAttachment_copyTo(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    spine::VertexAttachment *arg1 = nullptr;       /** other */

    olua_to_cppobj(L, 1, (void **)&self, "sp.VertexAttachment");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.VertexAttachment");

    // void copyTo(spine::VertexAttachment *other)
    self->copyTo(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_VertexAttachment_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.VertexAttachment");

    // Vector<size_t> &getBones()
    spine::Vector<size_t> &ret = (spine::Vector<size_t> &)self->getBones();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_uint(L, (lua_Unsigned)((spine::Vector<size_t> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_VertexAttachment_getDeformAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.VertexAttachment");

    // spine::VertexAttachment *getDeformAttachment()
    spine::VertexAttachment *ret = (spine::VertexAttachment *)self->getDeformAttachment();
    int num_ret = olua_push_cppobj(L, ret, "sp.VertexAttachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_VertexAttachment_getId(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.VertexAttachment");

    // int getId()
    int ret = (int)self->getId();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_VertexAttachment_getVertices(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.VertexAttachment");

    // Vector<float> &getVertices()
    spine::Vector<float> &ret = (spine::Vector<float> &)self->getVertices();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_VertexAttachment_getWorldVerticesLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.VertexAttachment");

    // size_t getWorldVerticesLength()
    size_t ret = (size_t)self->getWorldVerticesLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_VertexAttachment_setDeformAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    spine::VertexAttachment *arg1 = nullptr;       /** attachment */

    olua_to_cppobj(L, 1, (void **)&self, "sp.VertexAttachment");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.VertexAttachment");

    // void setDeformAttachment(spine::VertexAttachment *attachment)
    self->setDeformAttachment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_VertexAttachment_setWorldVerticesLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::VertexAttachment *self = nullptr;
    lua_Unsigned arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.VertexAttachment");
    olua_check_uint(L, 2, &arg1);

    // void setWorldVerticesLength(size_t inValue)
    self->setWorldVerticesLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_VertexAttachment(lua_State *L)
{
    oluacls_class(L, "sp.VertexAttachment", "sp.Attachment");
    oluacls_func(L, "__move", _spine_VertexAttachment___move);
    oluacls_func(L, "copyTo", _spine_VertexAttachment_copyTo);
    oluacls_func(L, "getBones", _spine_VertexAttachment_getBones);
    oluacls_func(L, "getDeformAttachment", _spine_VertexAttachment_getDeformAttachment);
    oluacls_func(L, "getId", _spine_VertexAttachment_getId);
    oluacls_func(L, "getVertices", _spine_VertexAttachment_getVertices);
    oluacls_func(L, "getWorldVerticesLength", _spine_VertexAttachment_getWorldVerticesLength);
    oluacls_func(L, "setDeformAttachment", _spine_VertexAttachment_setDeformAttachment);
    oluacls_func(L, "setWorldVerticesLength", _spine_VertexAttachment_setWorldVerticesLength);
    oluacls_prop(L, "bones", _spine_VertexAttachment_getBones, nullptr);
    oluacls_prop(L, "deformAttachment", _spine_VertexAttachment_getDeformAttachment, _spine_VertexAttachment_setDeformAttachment);
    oluacls_prop(L, "id", _spine_VertexAttachment_getId, nullptr);
    oluacls_prop(L, "vertices", _spine_VertexAttachment_getVertices, nullptr);
    oluacls_prop(L, "worldVerticesLength", _spine_VertexAttachment_getWorldVerticesLength, _spine_VertexAttachment_setWorldVerticesLength);

    olua_registerluatype<spine::VertexAttachment>(L, "sp.VertexAttachment");

    return 1;
}

static int _spine_ClippingAttachment___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::ClippingAttachment *)olua_toobj(L, 1, "sp.ClippingAttachment");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_ClippingAttachment___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::ClippingAttachment *)olua_toobj(L, 1, "sp.ClippingAttachment");
    olua_push_cppobj(L, self, "sp.ClippingAttachment");

    olua_endinvoke(L);

    return 1;
}

static int _spine_ClippingAttachment_getEndSlot(lua_State *L)
{
    olua_startinvoke(L);

    spine::ClippingAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.ClippingAttachment");

    // spine::SlotData *getEndSlot()
    spine::SlotData *ret = (spine::SlotData *)self->getEndSlot();
    int num_ret = olua_push_cppobj(L, ret, "sp.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ClippingAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // ClippingAttachment(const spine::String &name)
    spine::ClippingAttachment *ret = (spine::ClippingAttachment *)new spine::ClippingAttachment(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.ClippingAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_ClippingAttachment_setEndSlot(lua_State *L)
{
    olua_startinvoke(L);

    spine::ClippingAttachment *self = nullptr;
    spine::SlotData *arg1 = nullptr;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.ClippingAttachment");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.SlotData");

    // void setEndSlot(spine::SlotData *inValue)
    self->setEndSlot(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_ClippingAttachment(lua_State *L)
{
    oluacls_class(L, "sp.ClippingAttachment", "sp.VertexAttachment");
    oluacls_func(L, "__gc", _spine_ClippingAttachment___gc);
    oluacls_func(L, "__move", _spine_ClippingAttachment___move);
    oluacls_func(L, "getEndSlot", _spine_ClippingAttachment_getEndSlot);
    oluacls_func(L, "new", _spine_ClippingAttachment_new);
    oluacls_func(L, "setEndSlot", _spine_ClippingAttachment_setEndSlot);
    oluacls_prop(L, "endSlot", _spine_ClippingAttachment_getEndSlot, _spine_ClippingAttachment_setEndSlot);

    olua_registerluatype<spine::ClippingAttachment>(L, "sp.ClippingAttachment");

    return 1;
}

static int _spine_BoundingBoxAttachment___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::BoundingBoxAttachment *)olua_toobj(L, 1, "sp.BoundingBoxAttachment");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_BoundingBoxAttachment___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::BoundingBoxAttachment *)olua_toobj(L, 1, "sp.BoundingBoxAttachment");
    olua_push_cppobj(L, self, "sp.BoundingBoxAttachment");

    olua_endinvoke(L);

    return 1;
}

static int _spine_BoundingBoxAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // BoundingBoxAttachment(const spine::String &name)
    spine::BoundingBoxAttachment *ret = (spine::BoundingBoxAttachment *)new spine::BoundingBoxAttachment(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.BoundingBoxAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_spine_BoundingBoxAttachment(lua_State *L)
{
    oluacls_class(L, "sp.BoundingBoxAttachment", "sp.VertexAttachment");
    oluacls_func(L, "__gc", _spine_BoundingBoxAttachment___gc);
    oluacls_func(L, "__move", _spine_BoundingBoxAttachment___move);
    oluacls_func(L, "new", _spine_BoundingBoxAttachment_new);

    olua_registerluatype<spine::BoundingBoxAttachment>(L, "sp.BoundingBoxAttachment");

    return 1;
}

static int _spine_MeshAttachment___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::MeshAttachment *)olua_toobj(L, 1, "sp.MeshAttachment");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::MeshAttachment *)olua_toobj(L, 1, "sp.MeshAttachment");
    olua_push_cppobj(L, self, "sp.MeshAttachment");

    olua_endinvoke(L);

    return 1;
}

static int _spine_MeshAttachment_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // spine::Color &getColor()
    spine::Color &ret = (spine::Color &)self->getColor();
    int num_ret = manual_olua_push_spine_Color(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getEdges(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // Vector<unsigned short> &getEdges()
    spine::Vector<unsigned short> &ret = (spine::Vector<unsigned short> &)self->getEdges();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_uint(L, (lua_Unsigned)((spine::Vector<unsigned short> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getHeight()
    float ret = (float)self->getHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getHullLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // int getHullLength()
    int ret = (int)self->getHullLength();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getParentMesh(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // spine::MeshAttachment *getParentMesh()
    spine::MeshAttachment *ret = (spine::MeshAttachment *)self->getParentMesh();
    int num_ret = olua_push_cppobj(L, ret, "sp.MeshAttachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // const spine::String &getPath()
    const spine::String &ret = (const spine::String &)self->getPath();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionDegrees(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // int getRegionDegrees()
    int ret = (int)self->getRegionDegrees();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getRegionHeight()
    float ret = (float)self->getRegionHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionOffsetX(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getRegionOffsetX()
    float ret = (float)self->getRegionOffsetX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionOffsetY(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getRegionOffsetY()
    float ret = (float)self->getRegionOffsetY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionOriginalHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getRegionOriginalHeight()
    float ret = (float)self->getRegionOriginalHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionOriginalWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getRegionOriginalWidth()
    float ret = (float)self->getRegionOriginalWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionRotate(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // bool getRegionRotate()
    bool ret = (bool)self->getRegionRotate();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionU(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getRegionU()
    float ret = (float)self->getRegionU();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionU2(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getRegionU2()
    float ret = (float)self->getRegionU2();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionUVs(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // Vector<float> &getRegionUVs()
    spine::Vector<float> &ret = (spine::Vector<float> &)self->getRegionUVs();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionV(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getRegionV()
    float ret = (float)self->getRegionV();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionV2(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getRegionV2()
    float ret = (float)self->getRegionV2();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getRegionWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getRegionWidth()
    float ret = (float)self->getRegionWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getTriangles(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // Vector<unsigned short> &getTriangles()
    spine::Vector<unsigned short> &ret = (spine::Vector<unsigned short> &)self->getTriangles();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_uint(L, (lua_Unsigned)((spine::Vector<unsigned short> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getUVs(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // Vector<float> &getUVs()
    spine::Vector<float> &ret = (spine::Vector<float> &)self->getUVs();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // float getWidth()
    float ret = (float)self->getWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // MeshAttachment(const spine::String &name)
    spine::MeshAttachment *ret = (spine::MeshAttachment *)new spine::MeshAttachment(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.MeshAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_newLinkedMesh(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // spine::MeshAttachment *newLinkedMesh()
    spine::MeshAttachment *ret = (spine::MeshAttachment *)self->newLinkedMesh();
    int num_ret = olua_push_cppobj(L, ret, "sp.MeshAttachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_MeshAttachment_setHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setHeight(float inValue)
    self->setHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setHullLength(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Integer arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_int(L, 2, &arg1);

    // void setHullLength(int inValue)
    self->setHullLength((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setParentMesh(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    spine::MeshAttachment *arg1 = nullptr;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.MeshAttachment");

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

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    manual_olua_check_spine_String(L, 2, &arg1);

    // void setPath(const spine::String &inValue)
    self->setPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionDegrees(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Integer arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_int(L, 2, &arg1);

    // void setRegionDegrees(int inValue)
    self->setRegionDegrees((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionHeight(float inValue)
    self->setRegionHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionOffsetX(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionOffsetX(float inValue)
    self->setRegionOffsetX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionOffsetY(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionOffsetY(float inValue)
    self->setRegionOffsetY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionOriginalHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionOriginalHeight(float inValue)
    self->setRegionOriginalHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionOriginalWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionOriginalWidth(float inValue)
    self->setRegionOriginalWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionRotate(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_bool(L, 2, &arg1);

    // void setRegionRotate(bool inValue)
    self->setRegionRotate(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionU(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionU(float inValue)
    self->setRegionU((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionU2(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionU2(float inValue)
    self->setRegionU2((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionV(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionV(float inValue)
    self->setRegionV((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionV2(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionV2(float inValue)
    self->setRegionV2((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setRegionWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionWidth(float inValue)
    self->setRegionWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_setWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");
    olua_check_number(L, 2, &arg1);

    // void setWidth(float inValue)
    self->setWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_MeshAttachment_updateUVs(lua_State *L)
{
    olua_startinvoke(L);

    spine::MeshAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.MeshAttachment");

    // void updateUVs()
    self->updateUVs();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_MeshAttachment(lua_State *L)
{
    oluacls_class(L, "sp.MeshAttachment", "sp.VertexAttachment");
    oluacls_func(L, "__gc", _spine_MeshAttachment___gc);
    oluacls_func(L, "__move", _spine_MeshAttachment___move);
    oluacls_func(L, "getColor", _spine_MeshAttachment_getColor);
    oluacls_func(L, "getEdges", _spine_MeshAttachment_getEdges);
    oluacls_func(L, "getHeight", _spine_MeshAttachment_getHeight);
    oluacls_func(L, "getHullLength", _spine_MeshAttachment_getHullLength);
    oluacls_func(L, "getParentMesh", _spine_MeshAttachment_getParentMesh);
    oluacls_func(L, "getPath", _spine_MeshAttachment_getPath);
    oluacls_func(L, "getRegionDegrees", _spine_MeshAttachment_getRegionDegrees);
    oluacls_func(L, "getRegionHeight", _spine_MeshAttachment_getRegionHeight);
    oluacls_func(L, "getRegionOffsetX", _spine_MeshAttachment_getRegionOffsetX);
    oluacls_func(L, "getRegionOffsetY", _spine_MeshAttachment_getRegionOffsetY);
    oluacls_func(L, "getRegionOriginalHeight", _spine_MeshAttachment_getRegionOriginalHeight);
    oluacls_func(L, "getRegionOriginalWidth", _spine_MeshAttachment_getRegionOriginalWidth);
    oluacls_func(L, "getRegionRotate", _spine_MeshAttachment_getRegionRotate);
    oluacls_func(L, "getRegionU", _spine_MeshAttachment_getRegionU);
    oluacls_func(L, "getRegionU2", _spine_MeshAttachment_getRegionU2);
    oluacls_func(L, "getRegionUVs", _spine_MeshAttachment_getRegionUVs);
    oluacls_func(L, "getRegionV", _spine_MeshAttachment_getRegionV);
    oluacls_func(L, "getRegionV2", _spine_MeshAttachment_getRegionV2);
    oluacls_func(L, "getRegionWidth", _spine_MeshAttachment_getRegionWidth);
    oluacls_func(L, "getTriangles", _spine_MeshAttachment_getTriangles);
    oluacls_func(L, "getUVs", _spine_MeshAttachment_getUVs);
    oluacls_func(L, "getWidth", _spine_MeshAttachment_getWidth);
    oluacls_func(L, "new", _spine_MeshAttachment_new);
    oluacls_func(L, "newLinkedMesh", _spine_MeshAttachment_newLinkedMesh);
    oluacls_func(L, "setHeight", _spine_MeshAttachment_setHeight);
    oluacls_func(L, "setHullLength", _spine_MeshAttachment_setHullLength);
    oluacls_func(L, "setParentMesh", _spine_MeshAttachment_setParentMesh);
    oluacls_func(L, "setPath", _spine_MeshAttachment_setPath);
    oluacls_func(L, "setRegionDegrees", _spine_MeshAttachment_setRegionDegrees);
    oluacls_func(L, "setRegionHeight", _spine_MeshAttachment_setRegionHeight);
    oluacls_func(L, "setRegionOffsetX", _spine_MeshAttachment_setRegionOffsetX);
    oluacls_func(L, "setRegionOffsetY", _spine_MeshAttachment_setRegionOffsetY);
    oluacls_func(L, "setRegionOriginalHeight", _spine_MeshAttachment_setRegionOriginalHeight);
    oluacls_func(L, "setRegionOriginalWidth", _spine_MeshAttachment_setRegionOriginalWidth);
    oluacls_func(L, "setRegionRotate", _spine_MeshAttachment_setRegionRotate);
    oluacls_func(L, "setRegionU", _spine_MeshAttachment_setRegionU);
    oluacls_func(L, "setRegionU2", _spine_MeshAttachment_setRegionU2);
    oluacls_func(L, "setRegionV", _spine_MeshAttachment_setRegionV);
    oluacls_func(L, "setRegionV2", _spine_MeshAttachment_setRegionV2);
    oluacls_func(L, "setRegionWidth", _spine_MeshAttachment_setRegionWidth);
    oluacls_func(L, "setWidth", _spine_MeshAttachment_setWidth);
    oluacls_func(L, "updateUVs", _spine_MeshAttachment_updateUVs);
    oluacls_prop(L, "color", _spine_MeshAttachment_getColor, nullptr);
    oluacls_prop(L, "edges", _spine_MeshAttachment_getEdges, nullptr);
    oluacls_prop(L, "height", _spine_MeshAttachment_getHeight, _spine_MeshAttachment_setHeight);
    oluacls_prop(L, "hullLength", _spine_MeshAttachment_getHullLength, _spine_MeshAttachment_setHullLength);
    oluacls_prop(L, "parentMesh", _spine_MeshAttachment_getParentMesh, _spine_MeshAttachment_setParentMesh);
    oluacls_prop(L, "path", _spine_MeshAttachment_getPath, _spine_MeshAttachment_setPath);
    oluacls_prop(L, "regionDegrees", _spine_MeshAttachment_getRegionDegrees, _spine_MeshAttachment_setRegionDegrees);
    oluacls_prop(L, "regionHeight", _spine_MeshAttachment_getRegionHeight, _spine_MeshAttachment_setRegionHeight);
    oluacls_prop(L, "regionOffsetX", _spine_MeshAttachment_getRegionOffsetX, _spine_MeshAttachment_setRegionOffsetX);
    oluacls_prop(L, "regionOffsetY", _spine_MeshAttachment_getRegionOffsetY, _spine_MeshAttachment_setRegionOffsetY);
    oluacls_prop(L, "regionOriginalHeight", _spine_MeshAttachment_getRegionOriginalHeight, _spine_MeshAttachment_setRegionOriginalHeight);
    oluacls_prop(L, "regionOriginalWidth", _spine_MeshAttachment_getRegionOriginalWidth, _spine_MeshAttachment_setRegionOriginalWidth);
    oluacls_prop(L, "regionRotate", _spine_MeshAttachment_getRegionRotate, _spine_MeshAttachment_setRegionRotate);
    oluacls_prop(L, "regionU", _spine_MeshAttachment_getRegionU, _spine_MeshAttachment_setRegionU);
    oluacls_prop(L, "regionU2", _spine_MeshAttachment_getRegionU2, _spine_MeshAttachment_setRegionU2);
    oluacls_prop(L, "regionUVs", _spine_MeshAttachment_getRegionUVs, nullptr);
    oluacls_prop(L, "regionV", _spine_MeshAttachment_getRegionV, _spine_MeshAttachment_setRegionV);
    oluacls_prop(L, "regionV2", _spine_MeshAttachment_getRegionV2, _spine_MeshAttachment_setRegionV2);
    oluacls_prop(L, "regionWidth", _spine_MeshAttachment_getRegionWidth, _spine_MeshAttachment_setRegionWidth);
    oluacls_prop(L, "triangles", _spine_MeshAttachment_getTriangles, nullptr);
    oluacls_prop(L, "uvs", _spine_MeshAttachment_getUVs, nullptr);
    oluacls_prop(L, "width", _spine_MeshAttachment_getWidth, _spine_MeshAttachment_setWidth);

    olua_registerluatype<spine::MeshAttachment>(L, "sp.MeshAttachment");

    return 1;
}

static int _spine_PathAttachment___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::PathAttachment *)olua_toobj(L, 1, "sp.PathAttachment");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathAttachment___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::PathAttachment *)olua_toobj(L, 1, "sp.PathAttachment");
    olua_push_cppobj(L, self, "sp.PathAttachment");

    olua_endinvoke(L);

    return 1;
}

static int _spine_PathAttachment_getLengths(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathAttachment");

    // Vector<float> &getLengths()
    spine::Vector<float> &ret = (spine::Vector<float> &)self->getLengths();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathAttachment_isClosed(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathAttachment");

    // bool isClosed()
    bool ret = (bool)self->isClosed();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathAttachment_isConstantSpeed(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathAttachment");

    // bool isConstantSpeed()
    bool ret = (bool)self->isConstantSpeed();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // PathAttachment(const spine::String &name)
    spine::PathAttachment *ret = (spine::PathAttachment *)new spine::PathAttachment(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.PathAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathAttachment_setClosed(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathAttachment *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathAttachment");
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

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathAttachment");
    olua_check_bool(L, 2, &arg1);

    // void setConstantSpeed(bool inValue)
    self->setConstantSpeed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_PathAttachment(lua_State *L)
{
    oluacls_class(L, "sp.PathAttachment", "sp.VertexAttachment");
    oluacls_func(L, "__gc", _spine_PathAttachment___gc);
    oluacls_func(L, "__move", _spine_PathAttachment___move);
    oluacls_func(L, "getLengths", _spine_PathAttachment_getLengths);
    oluacls_func(L, "isClosed", _spine_PathAttachment_isClosed);
    oluacls_func(L, "isConstantSpeed", _spine_PathAttachment_isConstantSpeed);
    oluacls_func(L, "new", _spine_PathAttachment_new);
    oluacls_func(L, "setClosed", _spine_PathAttachment_setClosed);
    oluacls_func(L, "setConstantSpeed", _spine_PathAttachment_setConstantSpeed);
    oluacls_prop(L, "closed", _spine_PathAttachment_isClosed, _spine_PathAttachment_setClosed);
    oluacls_prop(L, "constantSpeed", _spine_PathAttachment_isConstantSpeed, _spine_PathAttachment_setConstantSpeed);
    oluacls_prop(L, "lengths", _spine_PathAttachment_getLengths, nullptr);

    olua_registerluatype<spine::PathAttachment>(L, "sp.PathAttachment");

    return 1;
}

static int _spine_PathConstraint___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::PathConstraint *)olua_toobj(L, 1, "sp.PathConstraint");
    olua_push_cppobj(L, self, "sp.PathConstraint");

    olua_endinvoke(L);

    return 1;
}

static int _spine_PathConstraint_apply(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");

    // void apply()
    self->apply();

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraint_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");

    // Vector<spine::Bone *> &getBones()
    spine::Vector<spine::Bone *> &ret = (spine::Vector<spine::Bone *> &)self->getBones();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");

    // int getOrder()
    int ret = (int)self->getOrder();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");

    // float getPosition()
    float ret = (float)self->getPosition();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getRotateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");

    // float getRotateMix()
    float ret = (float)self->getRotateMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getSpacing(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");

    // float getSpacing()
    float ret = (float)self->getSpacing();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");

    // spine::Slot *getTarget()
    spine::Slot *ret = (spine::Slot *)self->getTarget();
    int num_ret = olua_push_cppobj(L, ret, "sp.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_getTranslateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");

    // float getTranslateMix()
    float ret = (float)self->getTranslateMix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PathConstraint_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");
    olua_check_number(L, 2, &arg1);

    // void setPosition(float inValue)
    self->setPosition((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraint_setRotateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");
    olua_check_number(L, 2, &arg1);

    // void setRotateMix(float inValue)
    self->setRotateMix((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraint_setSpacing(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");
    olua_check_number(L, 2, &arg1);

    // void setSpacing(float inValue)
    self->setSpacing((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraint_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;
    spine::Slot *arg1 = nullptr;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Slot");

    // void setTarget(spine::Slot *inValue)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PathConstraint_setTranslateMix(lua_State *L)
{
    olua_startinvoke(L);

    spine::PathConstraint *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PathConstraint");
    olua_check_number(L, 2, &arg1);

    // void setTranslateMix(float inValue)
    self->setTranslateMix((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_PathConstraint(lua_State *L)
{
    oluacls_class(L, "sp.PathConstraint", "sp.Updatable");
    oluacls_func(L, "__move", _spine_PathConstraint___move);
    oluacls_func(L, "apply", _spine_PathConstraint_apply);
    oluacls_func(L, "getBones", _spine_PathConstraint_getBones);
    oluacls_func(L, "getOrder", _spine_PathConstraint_getOrder);
    oluacls_func(L, "getPosition", _spine_PathConstraint_getPosition);
    oluacls_func(L, "getRotateMix", _spine_PathConstraint_getRotateMix);
    oluacls_func(L, "getSpacing", _spine_PathConstraint_getSpacing);
    oluacls_func(L, "getTarget", _spine_PathConstraint_getTarget);
    oluacls_func(L, "getTranslateMix", _spine_PathConstraint_getTranslateMix);
    oluacls_func(L, "setPosition", _spine_PathConstraint_setPosition);
    oluacls_func(L, "setRotateMix", _spine_PathConstraint_setRotateMix);
    oluacls_func(L, "setSpacing", _spine_PathConstraint_setSpacing);
    oluacls_func(L, "setTarget", _spine_PathConstraint_setTarget);
    oluacls_func(L, "setTranslateMix", _spine_PathConstraint_setTranslateMix);
    oluacls_prop(L, "bones", _spine_PathConstraint_getBones, nullptr);
    oluacls_prop(L, "order", _spine_PathConstraint_getOrder, nullptr);
    oluacls_prop(L, "position", _spine_PathConstraint_getPosition, _spine_PathConstraint_setPosition);
    oluacls_prop(L, "rotateMix", _spine_PathConstraint_getRotateMix, _spine_PathConstraint_setRotateMix);
    oluacls_prop(L, "spacing", _spine_PathConstraint_getSpacing, _spine_PathConstraint_setSpacing);
    oluacls_prop(L, "target", _spine_PathConstraint_getTarget, _spine_PathConstraint_setTarget);
    oluacls_prop(L, "translateMix", _spine_PathConstraint_getTranslateMix, _spine_PathConstraint_setTranslateMix);

    olua_registerluatype<spine::PathConstraint>(L, "sp.PathConstraint");

    return 1;
}

static int _spine_PointAttachment___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::PointAttachment *)olua_toobj(L, 1, "sp.PointAttachment");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_PointAttachment___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::PointAttachment *)olua_toobj(L, 1, "sp.PointAttachment");
    olua_push_cppobj(L, self, "sp.PointAttachment");

    olua_endinvoke(L);

    return 1;
}

static int _spine_PointAttachment_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PointAttachment");

    // float getRotation()
    float ret = (float)self->getRotation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PointAttachment_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PointAttachment");

    // float getX()
    float ret = (float)self->getX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PointAttachment_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.PointAttachment");

    // float getY()
    float ret = (float)self->getY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PointAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // PointAttachment(const spine::String &name)
    spine::PointAttachment *ret = (spine::PointAttachment *)new spine::PointAttachment(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.PointAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_PointAttachment_setRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PointAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRotation(float inValue)
    self->setRotation((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PointAttachment_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PointAttachment");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_PointAttachment_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::PointAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.PointAttachment");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_PointAttachment(lua_State *L)
{
    oluacls_class(L, "sp.PointAttachment", "sp.Attachment");
    oluacls_func(L, "__gc", _spine_PointAttachment___gc);
    oluacls_func(L, "__move", _spine_PointAttachment___move);
    oluacls_func(L, "getRotation", _spine_PointAttachment_getRotation);
    oluacls_func(L, "getX", _spine_PointAttachment_getX);
    oluacls_func(L, "getY", _spine_PointAttachment_getY);
    oluacls_func(L, "new", _spine_PointAttachment_new);
    oluacls_func(L, "setRotation", _spine_PointAttachment_setRotation);
    oluacls_func(L, "setX", _spine_PointAttachment_setX);
    oluacls_func(L, "setY", _spine_PointAttachment_setY);
    oluacls_prop(L, "rotation", _spine_PointAttachment_getRotation, _spine_PointAttachment_setRotation);
    oluacls_prop(L, "x", _spine_PointAttachment_getX, _spine_PointAttachment_setX);
    oluacls_prop(L, "y", _spine_PointAttachment_getY, _spine_PointAttachment_setY);

    olua_registerluatype<spine::PointAttachment>(L, "sp.PointAttachment");

    return 1;
}

static int _spine_RegionAttachment___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::RegionAttachment *)olua_toobj(L, 1, "sp.RegionAttachment");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::RegionAttachment *)olua_toobj(L, 1, "sp.RegionAttachment");
    olua_push_cppobj(L, self, "sp.RegionAttachment");

    olua_endinvoke(L);

    return 1;
}

static int _spine_RegionAttachment_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // spine::Color &getColor()
    spine::Color &ret = (spine::Color &)self->getColor();
    int num_ret = manual_olua_push_spine_Color(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getHeight()
    float ret = (float)self->getHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getOffset(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // Vector<float> &getOffset()
    spine::Vector<float> &ret = (spine::Vector<float> &)self->getOffset();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // const spine::String &getPath()
    const spine::String &ret = (const spine::String &)self->getPath();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getRegionHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getRegionHeight()
    float ret = (float)self->getRegionHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getRegionOffsetX(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getRegionOffsetX()
    float ret = (float)self->getRegionOffsetX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getRegionOffsetY(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getRegionOffsetY()
    float ret = (float)self->getRegionOffsetY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getRegionOriginalHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getRegionOriginalHeight()
    float ret = (float)self->getRegionOriginalHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getRegionOriginalWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getRegionOriginalWidth()
    float ret = (float)self->getRegionOriginalWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getRegionWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getRegionWidth()
    float ret = (float)self->getRegionWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getRotation()
    float ret = (float)self->getRotation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getScaleX()
    float ret = (float)self->getScaleX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getScaleY()
    float ret = (float)self->getScaleY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getUVs(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // Vector<float> &getUVs()
    spine::Vector<float> &ret = (spine::Vector<float> &)self->getUVs();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        olua_push_number(L, (lua_Number)((spine::Vector<float> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getWidth()
    float ret = (float)self->getWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getX()
    float ret = (float)self->getX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // float getY()
    float ret = (float)self->getY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::String arg1;       /** name */

    manual_olua_check_spine_String(L, 1, &arg1);

    // RegionAttachment(const spine::String &name)
    spine::RegionAttachment *ret = (spine::RegionAttachment *)new spine::RegionAttachment(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.RegionAttachment");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_RegionAttachment_setHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setHeight(float inValue)
    self->setHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    manual_olua_check_spine_String(L, 2, &arg1);

    // void setPath(const spine::String &inValue)
    self->setPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setRegionHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionHeight(float inValue)
    self->setRegionHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setRegionOffsetX(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionOffsetX(float inValue)
    self->setRegionOffsetX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setRegionOffsetY(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionOffsetY(float inValue)
    self->setRegionOffsetY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setRegionOriginalHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionOriginalHeight(float inValue)
    self->setRegionOriginalHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setRegionOriginalWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionOriginalWidth(float inValue)
    self->setRegionOriginalWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setRegionWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRegionWidth(float inValue)
    self->setRegionWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setRotation(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setRotation(float inValue)
    self->setRotation((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setScaleX(float inValue)
    self->setScaleX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setScaleY(float inValue)
    self->setScaleY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setUVs(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** u */
    lua_Number arg2 = 0;       /** v */
    lua_Number arg3 = 0;       /** u2 */
    lua_Number arg4 = 0;       /** v2 */
    bool arg5 = false;       /** rotate */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_bool(L, 6, &arg5);

    // void setUVs(float u, float v, float u2, float v2, bool rotate)
    self->setUVs((float)arg1, (float)arg2, (float)arg3, (float)arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setWidth(float inValue)
    self->setWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_RegionAttachment_updateOffset(lua_State *L)
{
    olua_startinvoke(L);

    spine::RegionAttachment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.RegionAttachment");

    // void updateOffset()
    self->updateOffset();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_RegionAttachment(lua_State *L)
{
    oluacls_class(L, "sp.RegionAttachment", "sp.Attachment");
    oluacls_func(L, "__gc", _spine_RegionAttachment___gc);
    oluacls_func(L, "__move", _spine_RegionAttachment___move);
    oluacls_func(L, "getColor", _spine_RegionAttachment_getColor);
    oluacls_func(L, "getHeight", _spine_RegionAttachment_getHeight);
    oluacls_func(L, "getOffset", _spine_RegionAttachment_getOffset);
    oluacls_func(L, "getPath", _spine_RegionAttachment_getPath);
    oluacls_func(L, "getRegionHeight", _spine_RegionAttachment_getRegionHeight);
    oluacls_func(L, "getRegionOffsetX", _spine_RegionAttachment_getRegionOffsetX);
    oluacls_func(L, "getRegionOffsetY", _spine_RegionAttachment_getRegionOffsetY);
    oluacls_func(L, "getRegionOriginalHeight", _spine_RegionAttachment_getRegionOriginalHeight);
    oluacls_func(L, "getRegionOriginalWidth", _spine_RegionAttachment_getRegionOriginalWidth);
    oluacls_func(L, "getRegionWidth", _spine_RegionAttachment_getRegionWidth);
    oluacls_func(L, "getRotation", _spine_RegionAttachment_getRotation);
    oluacls_func(L, "getScaleX", _spine_RegionAttachment_getScaleX);
    oluacls_func(L, "getScaleY", _spine_RegionAttachment_getScaleY);
    oluacls_func(L, "getUVs", _spine_RegionAttachment_getUVs);
    oluacls_func(L, "getWidth", _spine_RegionAttachment_getWidth);
    oluacls_func(L, "getX", _spine_RegionAttachment_getX);
    oluacls_func(L, "getY", _spine_RegionAttachment_getY);
    oluacls_func(L, "new", _spine_RegionAttachment_new);
    oluacls_func(L, "setHeight", _spine_RegionAttachment_setHeight);
    oluacls_func(L, "setPath", _spine_RegionAttachment_setPath);
    oluacls_func(L, "setRegionHeight", _spine_RegionAttachment_setRegionHeight);
    oluacls_func(L, "setRegionOffsetX", _spine_RegionAttachment_setRegionOffsetX);
    oluacls_func(L, "setRegionOffsetY", _spine_RegionAttachment_setRegionOffsetY);
    oluacls_func(L, "setRegionOriginalHeight", _spine_RegionAttachment_setRegionOriginalHeight);
    oluacls_func(L, "setRegionOriginalWidth", _spine_RegionAttachment_setRegionOriginalWidth);
    oluacls_func(L, "setRegionWidth", _spine_RegionAttachment_setRegionWidth);
    oluacls_func(L, "setRotation", _spine_RegionAttachment_setRotation);
    oluacls_func(L, "setScaleX", _spine_RegionAttachment_setScaleX);
    oluacls_func(L, "setScaleY", _spine_RegionAttachment_setScaleY);
    oluacls_func(L, "setUVs", _spine_RegionAttachment_setUVs);
    oluacls_func(L, "setWidth", _spine_RegionAttachment_setWidth);
    oluacls_func(L, "setX", _spine_RegionAttachment_setX);
    oluacls_func(L, "setY", _spine_RegionAttachment_setY);
    oluacls_func(L, "updateOffset", _spine_RegionAttachment_updateOffset);
    oluacls_prop(L, "color", _spine_RegionAttachment_getColor, nullptr);
    oluacls_prop(L, "height", _spine_RegionAttachment_getHeight, _spine_RegionAttachment_setHeight);
    oluacls_prop(L, "offset", _spine_RegionAttachment_getOffset, nullptr);
    oluacls_prop(L, "path", _spine_RegionAttachment_getPath, _spine_RegionAttachment_setPath);
    oluacls_prop(L, "regionHeight", _spine_RegionAttachment_getRegionHeight, _spine_RegionAttachment_setRegionHeight);
    oluacls_prop(L, "regionOffsetX", _spine_RegionAttachment_getRegionOffsetX, _spine_RegionAttachment_setRegionOffsetX);
    oluacls_prop(L, "regionOffsetY", _spine_RegionAttachment_getRegionOffsetY, _spine_RegionAttachment_setRegionOffsetY);
    oluacls_prop(L, "regionOriginalHeight", _spine_RegionAttachment_getRegionOriginalHeight, _spine_RegionAttachment_setRegionOriginalHeight);
    oluacls_prop(L, "regionOriginalWidth", _spine_RegionAttachment_getRegionOriginalWidth, _spine_RegionAttachment_setRegionOriginalWidth);
    oluacls_prop(L, "regionWidth", _spine_RegionAttachment_getRegionWidth, _spine_RegionAttachment_setRegionWidth);
    oluacls_prop(L, "rotation", _spine_RegionAttachment_getRotation, _spine_RegionAttachment_setRotation);
    oluacls_prop(L, "scaleX", _spine_RegionAttachment_getScaleX, _spine_RegionAttachment_setScaleX);
    oluacls_prop(L, "scaleY", _spine_RegionAttachment_getScaleY, _spine_RegionAttachment_setScaleY);
    oluacls_prop(L, "uvs", _spine_RegionAttachment_getUVs, _spine_RegionAttachment_setUVs);
    oluacls_prop(L, "width", _spine_RegionAttachment_getWidth, _spine_RegionAttachment_setWidth);
    oluacls_prop(L, "x", _spine_RegionAttachment_getX, _spine_RegionAttachment_setX);
    oluacls_prop(L, "y", _spine_RegionAttachment_getY, _spine_RegionAttachment_setY);

    olua_registerluatype<spine::RegionAttachment>(L, "sp.RegionAttachment");

    return 1;
}

static int _spine_TrackEntry___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::TrackEntry *)olua_toobj(L, 1, "sp.TrackEntry");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::TrackEntry *)olua_toobj(L, 1, "sp.TrackEntry");
    olua_push_cppobj(L, self, "sp.TrackEntry");

    olua_endinvoke(L);

    return 1;
}

static int _spine_TrackEntry_getAlpha(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getAlpha()
    float ret = (float)self->getAlpha();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // spine::Animation *getAnimation()
    spine::Animation *ret = (spine::Animation *)self->getAnimation();
    int num_ret = olua_push_cppobj(L, ret, "sp.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAnimationEnd(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getAnimationEnd()
    float ret = (float)self->getAnimationEnd();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAnimationLast(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getAnimationLast()
    float ret = (float)self->getAnimationLast();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAnimationStart(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getAnimationStart()
    float ret = (float)self->getAnimationStart();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAnimationTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getAnimationTime()
    float ret = (float)self->getAnimationTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getAttachmentThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getAttachmentThreshold()
    float ret = (float)self->getAttachmentThreshold();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getDelay(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getDelay()
    float ret = (float)self->getDelay();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getDrawOrderThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getDrawOrderThreshold()
    float ret = (float)self->getDrawOrderThreshold();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getEventThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getEventThreshold()
    float ret = (float)self->getEventThreshold();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getHoldPrevious(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // bool getHoldPrevious()
    bool ret = (bool)self->getHoldPrevious();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getLoop(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // bool getLoop()
    bool ret = (bool)self->getLoop();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getMixBlend(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // spine::MixBlend getMixBlend()
    spine::MixBlend ret = (spine::MixBlend)self->getMixBlend();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getMixDuration(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getMixDuration()
    float ret = (float)self->getMixDuration();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getMixTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getMixTime()
    float ret = (float)self->getMixTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getMixingFrom(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // spine::TrackEntry *getMixingFrom()
    spine::TrackEntry *ret = (spine::TrackEntry *)self->getMixingFrom();
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getMixingTo(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // spine::TrackEntry *getMixingTo()
    spine::TrackEntry *ret = (spine::TrackEntry *)self->getMixingTo();
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getNext(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // spine::TrackEntry *getNext()
    spine::TrackEntry *ret = (spine::TrackEntry *)self->getNext();
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getTimeScale()
    float ret = (float)self->getTimeScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getTrackEnd(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getTrackEnd()
    float ret = (float)self->getTrackEnd();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getTrackIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // int getTrackIndex()
    int ret = (int)self->getTrackIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_getTrackTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // float getTrackTime()
    float ret = (float)self->getTrackTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_isComplete(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // bool isComplete()
    bool ret = (bool)self->isComplete();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_new(lua_State *L)
{
    olua_startinvoke(L);

    // TrackEntry()
    spine::TrackEntry *ret = (spine::TrackEntry *)new spine::TrackEntry();
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_TrackEntry_resetRotationDirections(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    // void resetRotationDirections()
    self->resetRotationDirections();

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setAlpha(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setAlpha(float inValue)
    self->setAlpha((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setAnimationEnd(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setAnimationEnd(float inValue)
    self->setAnimationEnd((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setAnimationLast(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setAnimationLast(float inValue)
    self->setAnimationLast((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setAnimationStart(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setAnimationStart(float inValue)
    self->setAnimationStart((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setAttachmentThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setAttachmentThreshold(float inValue)
    self->setAttachmentThreshold((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setDelay(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setDelay(float inValue)
    self->setDelay((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setDrawOrderThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setDrawOrderThreshold(float inValue)
    self->setDrawOrderThreshold((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setEventThreshold(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setEventThreshold(float inValue)
    self->setEventThreshold((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setHoldPrevious(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
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
    std::function<void(spine::AnimationState *, spine::EventType, spine::TrackEntry *, spine::Event *)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");

    void *callback_store_obj = (void *)self;
    std::string tag = "Listener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT](spine::AnimationState *arg1, spine::EventType arg2, spine::TrackEntry *arg3, spine::Event *arg4) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.AnimationState");
            olua_push_uint(L, (lua_Unsigned)arg2);
            olua_push_cppobj(L, arg3, "sp.TrackEntry");
            olua_push_cppobj(L, arg4, "sp.Event");

            olua_callback(L, callback_store_obj, func.c_str(), 4);

            lua_settop(L, top);
        }
    };

    // void setListener(std::function<void (AnimationState *, EventType, TrackEntry *, Event *)> listener)
    self->setListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setLoop(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    bool arg1 = false;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
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
    lua_Unsigned arg1 = 0;       /** blend */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_uint(L, 2, &arg1);

    // void setMixBlend(spine::MixBlend blend)
    self->setMixBlend((spine::MixBlend)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setMixDuration(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setMixDuration(float inValue)
    self->setMixDuration((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setMixTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setMixTime(float inValue)
    self->setMixTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setTimeScale(float inValue)
    self->setTimeScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setTrackEnd(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setTrackEnd(float inValue)
    self->setTrackEnd((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_TrackEntry_setTrackTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::TrackEntry *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.TrackEntry");
    olua_check_number(L, 2, &arg1);

    // void setTrackTime(float inValue)
    self->setTrackTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_TrackEntry(lua_State *L)
{
    oluacls_class(L, "sp.TrackEntry", "sp.SpineObject");
    oluacls_func(L, "__gc", _spine_TrackEntry___gc);
    oluacls_func(L, "__move", _spine_TrackEntry___move);
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
    oluacls_func(L, "getTimeScale", _spine_TrackEntry_getTimeScale);
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
    oluacls_prop(L, "timeScale", _spine_TrackEntry_getTimeScale, _spine_TrackEntry_setTimeScale);
    oluacls_prop(L, "trackEnd", _spine_TrackEntry_getTrackEnd, _spine_TrackEntry_setTrackEnd);
    oluacls_prop(L, "trackIndex", _spine_TrackEntry_getTrackIndex, nullptr);
    oluacls_prop(L, "trackTime", _spine_TrackEntry_getTrackTime, _spine_TrackEntry_setTrackTime);

    olua_registerluatype<spine::TrackEntry>(L, "sp.TrackEntry");

    return 1;
}

static int _spine_SkeletonData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = olua_toobj<spine::SkeletonData>(L, 1);
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1) && self) {
        olua_setuserdata(L, 1, nullptr);

        lua_pushstring(L, ".skel.atlas");
        olua_getvariable(L, 1);
        auto atlas = olua_touserdata(L, -1, spine::Atlas *);
        delete atlas;

        lua_pushstring(L, ".skel.attachment_loader");
        olua_getvariable(L, 1);
        auto attachment_loader = olua_touserdata(L, -1, spine::Cocos2dAtlasAttachmentLoader *);
        delete attachment_loader;

        lua_pushstring(L, ".skel.texture_loader");
        olua_getvariable(L, 1);
        auto texture_loader = olua_touserdata(L, -1, spine::Cocos2dTextureLoader *);
        delete texture_loader;

        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::SkeletonData *)olua_toobj(L, 1, "sp.SkeletonData");
    olua_push_cppobj(L, self, "sp.SkeletonData");

    olua_endinvoke(L);

    return 1;
}

static int _spine_SkeletonData_findAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** animationName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::Animation *findAnimation(const spine::String &animationName)
    spine::Animation *ret = (spine::Animation *)self->findAnimation(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findBone(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::BoneData *findBone(const spine::String &boneName)
    spine::BoneData *ret = (spine::BoneData *)self->findBone(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // int findBoneIndex(const spine::String &boneName)
    int ret = (int)self->findBoneIndex(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findEvent(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** eventDataName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::EventData *findEvent(const spine::String &eventDataName)
    spine::EventData *ret = (spine::EventData *)self->findEvent(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.EventData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findIkConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::IkConstraintData *findIkConstraint(const spine::String &constraintName)
    spine::IkConstraintData *ret = (spine::IkConstraintData *)self->findIkConstraint(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.IkConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findPathConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::PathConstraintData *findPathConstraint(const spine::String &constraintName)
    spine::PathConstraintData *ret = (spine::PathConstraintData *)self->findPathConstraint(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.PathConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findPathConstraintIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** pathConstraintName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // int findPathConstraintIndex(const spine::String &pathConstraintName)
    int ret = (int)self->findPathConstraintIndex(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findSkin(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** skinName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::Skin *findSkin(const spine::String &skinName)
    spine::Skin *ret = (spine::Skin *)self->findSkin(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.Skin");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findSlot(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** slotName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::SlotData *findSlot(const spine::String &slotName)
    spine::SlotData *ret = (spine::SlotData *)self->findSlot(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** slotName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // int findSlotIndex(const spine::String &slotName)
    int ret = (int)self->findSlotIndex(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_findTransformConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::TransformConstraintData *findTransformConstraint(const spine::String &constraintName)
    spine::TransformConstraintData *ret = (spine::TransformConstraintData *)self->findTransformConstraint(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.TransformConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getAnimations(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // Vector<spine::Animation *> &getAnimations()
    spine::Vector<spine::Animation *> &ret = (spine::Vector<spine::Animation *> &)self->getAnimations();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getAudioPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // const spine::String &getAudioPath()
    const spine::String &ret = (const spine::String &)self->getAudioPath();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // Vector<spine::BoneData *> &getBones()
    spine::Vector<spine::BoneData *> &ret = (spine::Vector<spine::BoneData *> &)self->getBones();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.BoneData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getDefaultSkin(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // spine::Skin *getDefaultSkin()
    spine::Skin *ret = (spine::Skin *)self->getDefaultSkin();
    int num_ret = olua_push_cppobj(L, ret, "sp.Skin");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getEvents(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // Vector<spine::EventData *> &getEvents()
    spine::Vector<spine::EventData *> &ret = (spine::Vector<spine::EventData *> &)self->getEvents();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.EventData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getFps(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // float getFps()
    float ret = (float)self->getFps();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getHash(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // const spine::String &getHash()
    const spine::String &ret = (const spine::String &)self->getHash();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // float getHeight()
    float ret = (float)self->getHeight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getIkConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // Vector<spine::IkConstraintData *> &getIkConstraints()
    spine::Vector<spine::IkConstraintData *> &ret = (spine::Vector<spine::IkConstraintData *> &)self->getIkConstraints();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.IkConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getImagesPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // const spine::String &getImagesPath()
    const spine::String &ret = (const spine::String &)self->getImagesPath();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getName(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // const spine::String &getName()
    const spine::String &ret = (const spine::String &)self->getName();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getPathConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // Vector<spine::PathConstraintData *> &getPathConstraints()
    spine::Vector<spine::PathConstraintData *> &ret = (spine::Vector<spine::PathConstraintData *> &)self->getPathConstraints();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.PathConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getSkins(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // Vector<spine::Skin *> &getSkins()
    spine::Vector<spine::Skin *> &ret = (spine::Vector<spine::Skin *> &)self->getSkins();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.Skin");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getSlots(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // Vector<spine::SlotData *> &getSlots()
    spine::Vector<spine::SlotData *> &ret = (spine::Vector<spine::SlotData *> &)self->getSlots();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.SlotData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getTransformConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // Vector<spine::TransformConstraintData *> &getTransformConstraints()
    spine::Vector<spine::TransformConstraintData *> &ret = (spine::Vector<spine::TransformConstraintData *> &)self->getTransformConstraints();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.TransformConstraintData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getVersion(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // const spine::String &getVersion()
    const spine::String &ret = (const spine::String &)self->getVersion();
    int num_ret = manual_olua_push_spine_String(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // float getWidth()
    float ret = (float)self->getWidth();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // float getX()
    float ret = (float)self->getX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");

    // float getY()
    float ret = (float)self->getY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonData_new(lua_State *L)
{
    olua_startinvoke(L);

    const char *skel_path = olua_checkstring(L, 1);
    const char *atlas_path = olua_checkstring(L, 2);
    float scale = olua_optnumber(L, 3, 1);

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

    olua_push_obj(L, skel_data, "sp.SkeletonData");

    lua_pushstring(L, ".ownership");
    lua_pushboolean(L, true);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.texture_loader");
    olua_newuserdata(L, texture_loader, spine::Cocos2dTextureLoader *);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.attachment_loader");
    olua_newuserdata(L, attachment_loader, spine::Cocos2dAtlasAttachmentLoader *);
    olua_setvariable(L, -3);

    lua_pushstring(L, ".skel.atlas");
    olua_newuserdata(L, atlas, spine::Atlas *);
    olua_setvariable(L, -3);

    olua_endinvoke(L);

    return 1;
}

static int _spine_SkeletonData_setAudioPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Skin");

    // void setDefaultSkin(spine::Skin *inValue)
    self->setDefaultSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setFps(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    olua_check_number(L, 2, &arg1);

    // void setFps(float inValue)
    self->setFps((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setHash(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // void setHash(const spine::String &inValue)
    self->setHash(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setHeight(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    olua_check_number(L, 2, &arg1);

    // void setHeight(float inValue)
    self->setHeight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setImagesPath(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    spine::String arg1;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    manual_olua_check_spine_String(L, 2, &arg1);

    // void setVersion(const spine::String &inValue)
    self->setVersion(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setWidth(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    olua_check_number(L, 2, &arg1);

    // void setWidth(float inValue)
    self->setWidth((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonData_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonData");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_SkeletonData(lua_State *L)
{
    oluacls_class(L, "sp.SkeletonData", "sp.SpineObject");
    oluacls_func(L, "__gc", _spine_SkeletonData___gc);
    oluacls_func(L, "__move", _spine_SkeletonData___move);
    oluacls_func(L, "dispose", _spine_SkeletonData___gc);
    oluacls_func(L, "findAnimation", _spine_SkeletonData_findAnimation);
    oluacls_func(L, "findBone", _spine_SkeletonData_findBone);
    oluacls_func(L, "findBoneIndex", _spine_SkeletonData_findBoneIndex);
    oluacls_func(L, "findEvent", _spine_SkeletonData_findEvent);
    oluacls_func(L, "findIkConstraint", _spine_SkeletonData_findIkConstraint);
    oluacls_func(L, "findPathConstraint", _spine_SkeletonData_findPathConstraint);
    oluacls_func(L, "findPathConstraintIndex", _spine_SkeletonData_findPathConstraintIndex);
    oluacls_func(L, "findSkin", _spine_SkeletonData_findSkin);
    oluacls_func(L, "findSlot", _spine_SkeletonData_findSlot);
    oluacls_func(L, "findSlotIndex", _spine_SkeletonData_findSlotIndex);
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
    oluacls_func(L, "new", _spine_SkeletonData_new);
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

    olua_registerluatype<spine::SkeletonData>(L, "sp.SkeletonData");

    return 1;
}

static int _spine_Skeleton___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Skeleton *)olua_toobj(L, 1, "sp.Skeleton");
    lua_pushstring(L, ".ownership");
    olua_getvariable(L, 1);
    if (lua_toboolean(L, -1)) {
        olua_setuserdata(L, 1, nullptr);
        delete self;
    }

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::Skeleton *)olua_toobj(L, 1, "sp.Skeleton");
    olua_push_cppobj(L, self, "sp.Skeleton");

    olua_endinvoke(L);

    return 1;
}

static int _spine_Skeleton_findBone(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::Bone *findBone(const spine::String &boneName)
    spine::Bone *ret = (spine::Bone *)self->findBone(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_findBoneIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** boneName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    manual_olua_check_spine_String(L, 2, &arg1);

    // int findBoneIndex(const spine::String &boneName)
    int ret = (int)self->findBoneIndex(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_findIkConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::IkConstraint *findIkConstraint(const spine::String &constraintName)
    spine::IkConstraint *ret = (spine::IkConstraint *)self->findIkConstraint(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.IkConstraint");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_findPathConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::PathConstraint *findPathConstraint(const spine::String &constraintName)
    spine::PathConstraint *ret = (spine::PathConstraint *)self->findPathConstraint(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.PathConstraint");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_findSlot(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** slotName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::Slot *findSlot(const spine::String &slotName)
    spine::Slot *ret = (spine::Slot *)self->findSlot(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_findSlotIndex(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** slotName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    manual_olua_check_spine_String(L, 2, &arg1);

    // int findSlotIndex(const spine::String &slotName)
    int ret = (int)self->findSlotIndex(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_findTransformConstraint(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** constraintName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    manual_olua_check_spine_String(L, 2, &arg1);

    // spine::TransformConstraint *findTransformConstraint(const spine::String &constraintName)
    spine::TransformConstraint *ret = (spine::TransformConstraint *)self->findTransformConstraint(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.TransformConstraint");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getAttachment1(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** slotName */
    spine::String arg2;       /** attachmentName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    manual_olua_check_spine_String(L, 2, &arg1);
    manual_olua_check_spine_String(L, 3, &arg2);

    // spine::Attachment *getAttachment(const spine::String &slotName, const spine::String &attachmentName)
    spine::Attachment *ret = (spine::Attachment *)self->getAttachment(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getAttachment2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    lua_Integer arg1 = 0;       /** slotIndex */
    spine::String arg2;       /** attachmentName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    olua_check_int(L, 2, &arg1);
    manual_olua_check_spine_String(L, 3, &arg2);

    // spine::Attachment *getAttachment(int slotIndex, const spine::String &attachmentName)
    spine::Attachment *ret = (spine::Attachment *)self->getAttachment((int)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getAttachment(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        if ((manual_olua_is_spine_String(L, 2)) && (manual_olua_is_spine_String(L, 3))) {
            // spine::Attachment *getAttachment(const spine::String &slotName, const spine::String &attachmentName)
            return _spine_Skeleton_getAttachment1(L);
        }

        // if ((olua_is_int(L, 2)) && (manual_olua_is_spine_String(L, 3))) {
            // spine::Attachment *getAttachment(int slotIndex, const spine::String &attachmentName)
            return _spine_Skeleton_getAttachment2(L);
        // }
    }

    luaL_error(L, "method 'spine::Skeleton::getAttachment' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_Skeleton_getBones(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // Vector<spine::Bone *> &getBones()
    spine::Vector<spine::Bone *> &ret = (spine::Vector<spine::Bone *> &)self->getBones();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getColor(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // spine::Color &getColor()
    spine::Color &ret = (spine::Color &)self->getColor();
    int num_ret = manual_olua_push_spine_Color(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getData(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // spine::SkeletonData *getData()
    spine::SkeletonData *ret = (spine::SkeletonData *)self->getData();
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonData");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getDrawOrder(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // Vector<spine::Slot *> &getDrawOrder()
    spine::Vector<spine::Slot *> &ret = (spine::Vector<spine::Slot *> &)self->getDrawOrder();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getIkConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // Vector<spine::IkConstraint *> &getIkConstraints()
    spine::Vector<spine::IkConstraint *> &ret = (spine::Vector<spine::IkConstraint *> &)self->getIkConstraints();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.IkConstraint");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getPathConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // Vector<spine::PathConstraint *> &getPathConstraints()
    spine::Vector<spine::PathConstraint *> &ret = (spine::Vector<spine::PathConstraint *> &)self->getPathConstraints();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.PathConstraint");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getRootBone(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // spine::Bone *getRootBone()
    spine::Bone *ret = (spine::Bone *)self->getRootBone();
    int num_ret = olua_push_cppobj(L, ret, "sp.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // float getScaleX()
    float ret = (float)self->getScaleX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // float getScaleY()
    float ret = (float)self->getScaleY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getSkin(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // spine::Skin *getSkin()
    spine::Skin *ret = (spine::Skin *)self->getSkin();
    int num_ret = olua_push_cppobj(L, ret, "sp.Skin");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getSlots(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // Vector<spine::Slot *> &getSlots()
    spine::Vector<spine::Slot *> &ret = (spine::Vector<spine::Slot *> &)self->getSlots();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // float getTime()
    float ret = (float)self->getTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getTransformConstraints(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // Vector<spine::TransformConstraint *> &getTransformConstraints()
    spine::Vector<spine::TransformConstraint *> &ret = (spine::Vector<spine::TransformConstraint *> &)self->getTransformConstraints();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.TransformConstraint");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getUpdateCacheList(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // Vector<spine::Updatable *> &getUpdateCacheList()
    spine::Vector<spine::Updatable *> &ret = (spine::Vector<spine::Updatable *> &)self->getUpdateCacheList();
    int num_ret = manual_olua_push_spine_Vector(L, ret, "sp.Updatable");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // float getX()
    float ret = (float)self->getX();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_getY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // float getY()
    float ret = (float)self->getY();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_new(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.SkeletonData");

    // Skeleton(spine::SkeletonData *skeletonData)
    spine::Skeleton *ret = (spine::Skeleton *)new spine::Skeleton(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.Skeleton");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_Skeleton_printUpdateCache(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

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

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    manual_olua_check_spine_String(L, 2, &arg1);
    manual_olua_check_spine_String(L, 3, &arg2);

    // void setAttachment(const spine::String &slotName, const spine::String &attachmentName)
    self->setAttachment(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setBonesToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // void setBonesToSetupPose()
    self->setBonesToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void setPosition(float x, float y)
    self->setPosition((float)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setScaleX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    olua_check_number(L, 2, &arg1);

    // void setScaleX(float inValue)
    self->setScaleX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setScaleY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    olua_check_number(L, 2, &arg1);

    // void setScaleY(float inValue)
    self->setScaleY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setSkin1(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::String arg1;       /** skinName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    manual_olua_check_spine_String(L, 2, &arg1);

    // void setSkin(const spine::String &skinName)
    self->setSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setSkin2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    spine::Skin *arg1 = nullptr;       /** newSkin */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.Skin");

    // void setSkin(spine::Skin *newSkin)
    self->setSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setSkin(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((manual_olua_is_spine_String(L, 2))) {
            // void setSkin(const spine::String &skinName)
            return _spine_Skeleton_setSkin1(L);
        }

        // if ((olua_is_cppobj(L, 2, "sp.Skin"))) {
            // void setSkin(spine::Skin *newSkin)
            return _spine_Skeleton_setSkin2(L);
        // }
    }

    luaL_error(L, "method 'spine::Skeleton::setSkin' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_Skeleton_setSlotsToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // void setSlotsToSetupPose()
    self->setSlotsToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setTime(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    olua_check_number(L, 2, &arg1);

    // void setTime(float inValue)
    self->setTime((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // void setToSetupPose()
    self->setToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setX(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    olua_check_number(L, 2, &arg1);

    // void setX(float inValue)
    self->setX((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_setY(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    lua_Number arg1 = 0;       /** inValue */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    olua_check_number(L, 2, &arg1);

    // void setY(float inValue)
    self->setY((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_update(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;
    lua_Number arg1 = 0;       /** delta */

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");
    olua_check_number(L, 2, &arg1);

    // void update(float delta)
    self->update((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_updateCache(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // void updateCache()
    self->updateCache();

    olua_endinvoke(L);

    return 0;
}

static int _spine_Skeleton_updateWorldTransform(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.Skeleton");

    // void updateWorldTransform()
    self->updateWorldTransform();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_Skeleton(lua_State *L)
{
    oluacls_class(L, "sp.Skeleton", "sp.SpineObject");
    oluacls_func(L, "__gc", _spine_Skeleton___gc);
    oluacls_func(L, "__move", _spine_Skeleton___move);
    oluacls_func(L, "findBone", _spine_Skeleton_findBone);
    oluacls_func(L, "findBoneIndex", _spine_Skeleton_findBoneIndex);
    oluacls_func(L, "findIkConstraint", _spine_Skeleton_findIkConstraint);
    oluacls_func(L, "findPathConstraint", _spine_Skeleton_findPathConstraint);
    oluacls_func(L, "findSlot", _spine_Skeleton_findSlot);
    oluacls_func(L, "findSlotIndex", _spine_Skeleton_findSlotIndex);
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
    oluacls_func(L, "getTime", _spine_Skeleton_getTime);
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
    oluacls_func(L, "setTime", _spine_Skeleton_setTime);
    oluacls_func(L, "setToSetupPose", _spine_Skeleton_setToSetupPose);
    oluacls_func(L, "setX", _spine_Skeleton_setX);
    oluacls_func(L, "setY", _spine_Skeleton_setY);
    oluacls_func(L, "update", _spine_Skeleton_update);
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
    oluacls_prop(L, "time", _spine_Skeleton_getTime, _spine_Skeleton_setTime);
    oluacls_prop(L, "transformConstraints", _spine_Skeleton_getTransformConstraints, nullptr);
    oluacls_prop(L, "updateCacheList", _spine_Skeleton_getUpdateCacheList, nullptr);
    oluacls_prop(L, "x", _spine_Skeleton_getX, _spine_Skeleton_setX);
    oluacls_prop(L, "y", _spine_Skeleton_getY, _spine_Skeleton_setY);

    olua_registerluatype<spine::Skeleton>(L, "sp.Skeleton");

    return 1;
}

static int _spine_SkeletonRenderer___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::SkeletonRenderer *)olua_toobj(L, 1, "sp.SkeletonRenderer");
    olua_push_cppobj(L, self, "sp.SkeletonRenderer");

    olua_endinvoke(L);

    return 1;
}

static int _spine_SkeletonRenderer_create(lua_State *L)
{
    olua_startinvoke(L);

    // static spine::SkeletonRenderer *create()
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)spine::SkeletonRenderer::create();
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithData1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */
    bool arg2 = false;       /** ownsSkeletonData */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.SkeletonData");
    olua_check_bool(L, 2, &arg2);

    // static spine::SkeletonRenderer *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)spine::SkeletonRenderer::createWithData(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");

    // inject code after call
    olua_addref(L, -1, "skeletonData", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithData2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.SkeletonData");

    // static spine::SkeletonRenderer *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)spine::SkeletonRenderer::createWithData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");

    // inject code after call
    olua_addref(L, -1, "skeletonData", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "sp.SkeletonData"))) {
            // static spine::SkeletonRenderer *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_createWithData2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "sp.SkeletonData")) && (olua_is_bool(L, 2))) {
            // static spine::SkeletonRenderer *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_createWithData1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::createWithData' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_createWithFile1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */
    lua_Number arg3 = 0;       /** scale */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "sp.Atlas");
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)spine::SkeletonRenderer::createWithFile(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithFile2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */
    lua_Number arg3 = 0;       /** scale */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)spine::SkeletonRenderer::createWithFile(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithFile3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "sp.Atlas");

    // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)spine::SkeletonRenderer::createWithFile(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithFile4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)spine::SkeletonRenderer::createWithFile(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithFile(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_std_string(L, 1)) && (olua_is_cppobj(L, 2, "sp.Atlas"))) {
            // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_createWithFile3(L);
        }

        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_createWithFile4(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_std_string(L, 1)) && (olua_is_cppobj(L, 2, "sp.Atlas")) && (olua_is_number(L, 3))) {
            // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_createWithFile1(L);
        }

        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // static spine::SkeletonRenderer *createWithFile(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_createWithFile2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::createWithFile' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_createWithSkeleton1(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */
    bool arg3 = false;       /** ownsSkeletonData */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.Skeleton");
    olua_check_bool(L, 2, &arg2);
    olua_check_bool(L, 3, &arg3);

    // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)spine::SkeletonRenderer::createWithSkeleton(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithSkeleton2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.Skeleton");

    // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)spine::SkeletonRenderer::createWithSkeleton(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithSkeleton3(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.Skeleton");
    olua_check_bool(L, 2, &arg2);

    // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)spine::SkeletonRenderer::createWithSkeleton(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_createWithSkeleton(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "sp.Skeleton"))) {
            // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_createWithSkeleton2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "sp.Skeleton")) && (olua_is_bool(L, 2))) {
            // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_createWithSkeleton3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 1, "sp.Skeleton")) && (olua_is_bool(L, 2)) && (olua_is_bool(L, 3))) {
            // static spine::SkeletonRenderer *createWithSkeleton(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_createWithSkeleton1(L);
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

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    olua_check_std_string(L, 2, &arg1);

    // spine::Bone *findBone(const std::string &boneName)
    spine::Bone *ret = (spine::Bone *)self->findBone(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.Bone");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_findSlot(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** slotName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    olua_check_std_string(L, 2, &arg1);

    // spine::Slot *findSlot(const std::string &slotName)
    spine::Slot *ret = (spine::Slot *)self->findSlot(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.Slot");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getAttachment(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** slotName */
    std::string arg2;       /** attachmentName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // spine::Attachment *getAttachment(const std::string &slotName, const std::string &attachmentName)
    spine::Attachment *ret = (spine::Attachment *)self->getAttachment(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.Attachment");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getBlendFunc(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

    // const cocos2d::BlendFunc &getBlendFunc()
    const cocos2d::BlendFunc &ret = (const cocos2d::BlendFunc &)self->getBlendFunc();
    int num_ret = auto_olua_push_cocos2d_BlendFunc(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getDebugBonesEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

    // bool getDebugBonesEnabled()
    bool ret = (bool)self->getDebugBonesEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getDebugBoundingRectEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

    // bool getDebugBoundingRectEnabled()
    bool ret = (bool)self->getDebugBoundingRectEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getDebugMeshesEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

    // bool getDebugMeshesEnabled()
    bool ret = (bool)self->getDebugMeshesEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getDebugSlotsEnabled(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

    // bool getDebugSlotsEnabled()
    bool ret = (bool)self->getDebugSlotsEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getSkeleton(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

    // spine::Skeleton *getSkeleton()
    spine::Skeleton *ret = (spine::Skeleton *)self->getSkeleton();
    int num_ret = olua_push_cppobj(L, ret, "sp.Skeleton");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_getTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

    // float getTimeScale()
    float ret = (float)self->getTimeScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_initialize(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

    // void initialize()
    self->initialize();

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_isTwoColorTint(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

    // bool isTwoColorTint()
    bool ret = (bool)self->isTwoColorTint();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new1(lua_State *L)
{
    olua_startinvoke(L);

    // SkeletonRenderer()
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)new spine::SkeletonRenderer();
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new2(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */
    bool arg3 = false;       /** ownsSkeletonData */
    bool arg4 = false;       /** ownsAtlas */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.Skeleton");
    olua_check_bool(L, 2, &arg2);
    olua_check_bool(L, 3, &arg3);
    olua_check_bool(L, 4, &arg4);

    // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)new spine::SkeletonRenderer(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new3(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */
    bool arg2 = false;       /** ownsSkeletonData */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.SkeletonData");
    olua_check_bool(L, 2, &arg2);

    // SkeletonRenderer(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)new spine::SkeletonRenderer(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */
    lua_Number arg3 = 0;       /** scale */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "sp.Atlas");
    olua_check_number(L, 3, &arg3);

    // SkeletonRenderer(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)new spine::SkeletonRenderer(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */
    lua_Number arg3 = 0;       /** scale */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // SkeletonRenderer(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)new spine::SkeletonRenderer(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new6(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.Skeleton");

    // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)new spine::SkeletonRenderer(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new7(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.Skeleton");
    olua_check_bool(L, 2, &arg2);

    // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)new spine::SkeletonRenderer(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new8(lua_State *L)
{
    olua_startinvoke(L);

    spine::Skeleton *arg1 = nullptr;       /** skeleton */
    bool arg2 = false;       /** ownsSkeleton */
    bool arg3 = false;       /** ownsSkeletonData */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.Skeleton");
    olua_check_bool(L, 2, &arg2);
    olua_check_bool(L, 3, &arg3);

    // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)new spine::SkeletonRenderer(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new9(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.SkeletonData");

    // SkeletonRenderer(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)new spine::SkeletonRenderer(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new10(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "sp.Atlas");

    // SkeletonRenderer(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)new spine::SkeletonRenderer(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new11(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonDataFile */
    std::string arg2;       /** atlasFile */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // SkeletonRenderer(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonRenderer *ret = (spine::SkeletonRenderer *)new spine::SkeletonRenderer(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonRenderer");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // SkeletonRenderer()
        return _spine_SkeletonRenderer_new1(L);
    }

    if (num_args == 1) {
        if ((olua_is_cppobj(L, 1, "sp.Skeleton"))) {
            // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_new6(L);
        }

        // if ((olua_is_cppobj(L, 1, "sp.SkeletonData"))) {
            // SkeletonRenderer(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_new9(L);
        // }
    }

    if (num_args == 2) {
        if ((olua_is_cppobj(L, 1, "sp.SkeletonData")) && (olua_is_bool(L, 2))) {
            // SkeletonRenderer(spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonRenderer_new3(L);
        }

        if ((olua_is_std_string(L, 1)) && (olua_is_cppobj(L, 2, "sp.Atlas"))) {
            // SkeletonRenderer(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_new10(L);
        }

        if ((olua_is_cppobj(L, 1, "sp.Skeleton")) && (olua_is_bool(L, 2))) {
            // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_new7(L);
        }

        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // SkeletonRenderer(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_new11(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_std_string(L, 1)) && (olua_is_cppobj(L, 2, "sp.Atlas")) && (olua_is_number(L, 3))) {
            // SkeletonRenderer(const std::string &skeletonDataFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonRenderer_new4(L);
        }

        if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // SkeletonRenderer(const std::string &skeletonDataFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonRenderer_new5(L);
        }

        // if ((olua_is_cppobj(L, 1, "sp.Skeleton")) && (olua_is_bool(L, 2)) && (olua_is_bool(L, 3))) {
            // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_new8(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_cppobj(L, 1, "sp.Skeleton")) && (olua_is_bool(L, 2)) && (olua_is_bool(L, 3)) && (olua_is_bool(L, 4))) {
            // SkeletonRenderer(spine::Skeleton *skeleton, @optional bool ownsSkeleton, @optional bool ownsSkeletonData, @optional bool ownsAtlas)
            return _spine_SkeletonRenderer_new2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::new' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_setAttachment1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** slotName */
    std::string arg2;       /** attachmentName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // bool setAttachment(const std::string &slotName, const std::string &attachmentName)
    bool ret = (bool)self->setAttachment(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_setAttachment2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** slotName */
    const char *arg2 = nullptr;       /** attachmentName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    olua_check_std_string(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // bool setAttachment(const std::string &slotName, const char *attachmentName)
    bool ret = (bool)self->setAttachment(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonRenderer_setAttachment(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        if ((olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // bool setAttachment(const std::string &slotName, const std::string &attachmentName)
            return _spine_SkeletonRenderer_setAttachment1(L);
        }

        // if ((olua_is_std_string(L, 2)) && (olua_is_string(L, 3))) {
            // bool setAttachment(const std::string &slotName, const char *attachmentName)
            return _spine_SkeletonRenderer_setAttachment2(L);
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

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    auto_olua_check_cocos2d_BlendFunc(L, 2, &arg1);

    // void setBlendFunc(const cocos2d::BlendFunc &blendFunc)
    self->setBlendFunc(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setBonesToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

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

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
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

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
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

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
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

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    olua_check_bool(L, 2, &arg1);

    // void setDebugSlotsEnabled(bool enabled)
    self->setDebugSlotsEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setSkin1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    std::string arg1;       /** skinName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    olua_check_std_string(L, 2, &arg1);

    // void setSkin(const std::string &skinName)
    self->setSkin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setSkin2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    const char *arg1 = nullptr;       /** skinName */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
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
        if ((olua_is_std_string(L, 2))) {
            // void setSkin(const std::string &skinName)
            return _spine_SkeletonRenderer_setSkin1(L);
        }

        // if ((olua_is_string(L, 2))) {
            // void setSkin(const char *skinName)
            return _spine_SkeletonRenderer_setSkin2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonRenderer::setSkin' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonRenderer_setSlotsRange(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    lua_Integer arg1 = 0;       /** startSlotIndex */
    lua_Integer arg2 = 0;       /** endSlotIndex */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void setSlotsRange(int startSlotIndex, int endSlotIndex)
    self->setSlotsRange((int)arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setSlotsToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

    // void setSlotsToSetupPose()
    self->setSlotsToSetupPose();

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setTimeScale(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    lua_Number arg1 = 0;       /** scale */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    olua_check_number(L, 2, &arg1);

    // void setTimeScale(float scale)
    self->setTimeScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setToSetupPose(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

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

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    olua_check_bool(L, 2, &arg1);

    // void setTwoColorTint(bool enabled)
    self->setTwoColorTint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_setVertexEffect(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;
    spine::VertexEffect *arg1 = nullptr;       /** effect */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.VertexEffect");

    // void setVertexEffect(spine::VertexEffect *effect)
    self->setVertexEffect(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonRenderer_updateWorldTransform(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonRenderer *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonRenderer");

    // void updateWorldTransform()
    self->updateWorldTransform();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_SkeletonRenderer(lua_State *L)
{
    oluacls_class(L, "sp.SkeletonRenderer", "cc.Node");
    oluacls_func(L, "__move", _spine_SkeletonRenderer___move);
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
    oluacls_func(L, "setVertexEffect", _spine_SkeletonRenderer_setVertexEffect);
    oluacls_func(L, "updateWorldTransform", _spine_SkeletonRenderer_updateWorldTransform);
    oluacls_prop(L, "blendFunc", _spine_SkeletonRenderer_getBlendFunc, _spine_SkeletonRenderer_setBlendFunc);
    oluacls_prop(L, "debugBonesEnabled", _spine_SkeletonRenderer_getDebugBonesEnabled, _spine_SkeletonRenderer_setDebugBonesEnabled);
    oluacls_prop(L, "debugBoundingRectEnabled", _spine_SkeletonRenderer_getDebugBoundingRectEnabled, _spine_SkeletonRenderer_setDebugBoundingRectEnabled);
    oluacls_prop(L, "debugMeshesEnabled", _spine_SkeletonRenderer_getDebugMeshesEnabled, _spine_SkeletonRenderer_setDebugMeshesEnabled);
    oluacls_prop(L, "debugSlotsEnabled", _spine_SkeletonRenderer_getDebugSlotsEnabled, _spine_SkeletonRenderer_setDebugSlotsEnabled);
    oluacls_prop(L, "skeleton", _spine_SkeletonRenderer_getSkeleton, nullptr);
    oluacls_prop(L, "timeScale", _spine_SkeletonRenderer_getTimeScale, _spine_SkeletonRenderer_setTimeScale);
    oluacls_prop(L, "twoColorTint", _spine_SkeletonRenderer_isTwoColorTint, _spine_SkeletonRenderer_setTwoColorTint);

    olua_registerluatype<spine::SkeletonRenderer>(L, "sp.SkeletonRenderer");

    return 1;
}

static int _spine_SkeletonAnimation___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (spine::SkeletonAnimation *)olua_toobj(L, 1, "sp.SkeletonAnimation");
    olua_push_cppobj(L, self, "sp.SkeletonAnimation");

    olua_endinvoke(L);

    return 1;
}

static int _spine_SkeletonAnimation_addAnimation1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** trackIndex */
    std::string arg2;       /** name */
    bool arg3 = false;       /** loop */
    lua_Number arg4 = 0;       /** delay */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_int(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // @addref(trackEntries |) spine::TrackEntry *addAnimation(int trackIndex, const std::string &name, bool loop, @optional float delay)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->addAnimation((int)arg1, arg2, arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    // inject code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_addAnimation2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** trackIndex */
    std::string arg2;       /** name */
    bool arg3 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_int(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // @addref(trackEntries |) spine::TrackEntry *addAnimation(int trackIndex, const std::string &name, bool loop, @optional float delay)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->addAnimation((int)arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    // inject code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_addAnimation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_bool(L, 4))) {
            // @addref(trackEntries |) spine::TrackEntry *addAnimation(int trackIndex, const std::string &name, bool loop, @optional float delay)
            return _spine_SkeletonAnimation_addAnimation2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_int(L, 2)) && (olua_is_std_string(L, 3)) && (olua_is_bool(L, 4)) && (olua_is_number(L, 5))) {
            // @addref(trackEntries |) spine::TrackEntry *addAnimation(int trackIndex, const std::string &name, bool loop, @optional float delay)
            return _spine_SkeletonAnimation_addAnimation1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::addAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_addEmptyAnimation1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** trackIndex */
    lua_Number arg2 = 0;       /** mixDuration */
    lua_Number arg3 = 0;       /** delay */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_int(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // @addref(trackEntries |) spine::TrackEntry *addEmptyAnimation(int trackIndex, float mixDuration, @optional float delay)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->addEmptyAnimation((int)arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    // inject code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_addEmptyAnimation2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** trackIndex */
    lua_Number arg2 = 0;       /** mixDuration */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_int(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // @addref(trackEntries |) spine::TrackEntry *addEmptyAnimation(int trackIndex, float mixDuration, @optional float delay)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->addEmptyAnimation((int)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    // inject code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_addEmptyAnimation(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_int(L, 2)) && (olua_is_number(L, 3))) {
            // @addref(trackEntries |) spine::TrackEntry *addEmptyAnimation(int trackIndex, float mixDuration, @optional float delay)
            return _spine_SkeletonAnimation_addEmptyAnimation2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_int(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // @addref(trackEntries |) spine::TrackEntry *addEmptyAnimation(int trackIndex, float mixDuration, @optional float delay)
            return _spine_SkeletonAnimation_addEmptyAnimation1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::addEmptyAnimation' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_clearTrack1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** trackIndex */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_int(L, 2, &arg1);

    // void clearTrack(@optional int trackIndex)
    self->clearTrack((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_clearTrack2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

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
        return _spine_SkeletonAnimation_clearTrack2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // void clearTrack(@optional int trackIndex)
            return _spine_SkeletonAnimation_clearTrack1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::clearTrack' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_clearTracks(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

    // void clearTracks()
    self->clearTracks();

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_create(lua_State *L)
{
    olua_startinvoke(L);

    // static spine::SkeletonAnimation *create()
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)spine::SkeletonAnimation::create();
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithBinaryFile1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonBinaryFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */
    lua_Number arg3 = 0;       /** scale */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "sp.Atlas");
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)spine::SkeletonAnimation::createWithBinaryFile(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithBinaryFile2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonBinaryFile */
    std::string arg2;       /** atlasFile */
    lua_Number arg3 = 0;       /** scale */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)spine::SkeletonAnimation::createWithBinaryFile(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithBinaryFile3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonBinaryFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "sp.Atlas");

    // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)spine::SkeletonAnimation::createWithBinaryFile(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithBinaryFile4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonBinaryFile */
    std::string arg2;       /** atlasFile */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)spine::SkeletonAnimation::createWithBinaryFile(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithBinaryFile(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_std_string(L, 1)) && (olua_is_cppobj(L, 2, "sp.Atlas"))) {
            // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonAnimation_createWithBinaryFile3(L);
        }

        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonAnimation_createWithBinaryFile4(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_std_string(L, 1)) && (olua_is_cppobj(L, 2, "sp.Atlas")) && (olua_is_number(L, 3))) {
            // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonAnimation_createWithBinaryFile1(L);
        }

        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // static spine::SkeletonAnimation *createWithBinaryFile(const std::string &skeletonBinaryFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonAnimation_createWithBinaryFile2(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::createWithBinaryFile' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_createWithData1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */
    bool arg2 = false;       /** ownsSkeletonData */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.SkeletonData");
    olua_check_bool(L, 2, &arg2);

    // static spine::SkeletonAnimation *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)spine::SkeletonAnimation::createWithData(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");

    // inject code after call
    olua_addref(L, -1, "skeletonData", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithData2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonData *arg1 = nullptr;       /** skeletonData */

    olua_check_cppobj(L, 1, (void **)&arg1, "sp.SkeletonData");

    // static spine::SkeletonAnimation *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)spine::SkeletonAnimation::createWithData(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");

    // inject code after call
    olua_addref(L, -1, "skeletonData", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "sp.SkeletonData"))) {
            // static spine::SkeletonAnimation *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonAnimation_createWithData2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "sp.SkeletonData")) && (olua_is_bool(L, 2))) {
            // static spine::SkeletonAnimation *createWithData(@addref(skeletonData ^) spine::SkeletonData *skeletonData, @optional bool ownsSkeletonData)
            return _spine_SkeletonAnimation_createWithData1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::createWithData' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_createWithJsonFile1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonJsonFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */
    lua_Number arg3 = 0;       /** scale */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "sp.Atlas");
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)spine::SkeletonAnimation::createWithJsonFile(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithJsonFile2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonJsonFile */
    std::string arg2;       /** atlasFile */
    lua_Number arg3 = 0;       /** scale */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)spine::SkeletonAnimation::createWithJsonFile(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithJsonFile3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonJsonFile */
    spine::Atlas *arg2 = nullptr;       /** atlas */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "sp.Atlas");

    // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, spine::Atlas *atlas, @optional float scale)
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)spine::SkeletonAnimation::createWithJsonFile(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithJsonFile4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** skeletonJsonFile */
    std::string arg2;       /** atlasFile */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, const std::string &atlasFile, @optional float scale)
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)spine::SkeletonAnimation::createWithJsonFile(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_createWithJsonFile(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_std_string(L, 1)) && (olua_is_cppobj(L, 2, "sp.Atlas"))) {
            // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonAnimation_createWithJsonFile3(L);
        }

        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonAnimation_createWithJsonFile4(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_std_string(L, 1)) && (olua_is_cppobj(L, 2, "sp.Atlas")) && (olua_is_number(L, 3))) {
            // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, spine::Atlas *atlas, @optional float scale)
            return _spine_SkeletonAnimation_createWithJsonFile1(L);
        }

        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_number(L, 3))) {
            // static spine::SkeletonAnimation *createWithJsonFile(const std::string &skeletonJsonFile, const std::string &atlasFile, @optional float scale)
            return _spine_SkeletonAnimation_createWithJsonFile2(L);
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

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_std_string(L, 2, &arg1);

    // spine::Animation *findAnimation(const std::string &name)
    spine::Animation *ret = (spine::Animation *)self->findAnimation(arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_getCurrent1(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** trackIndex */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_int(L, 2, &arg1);

    // @addref(trackEntries |) spine::TrackEntry *getCurrent(@optional int trackIndex)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->getCurrent((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    // inject code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_getCurrent2(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

    // @addref(trackEntries |) spine::TrackEntry *getCurrent(@optional int trackIndex)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->getCurrent();
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    // inject code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_getCurrent(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // @addref(trackEntries |) spine::TrackEntry *getCurrent(@optional int trackIndex)
        return _spine_SkeletonAnimation_getCurrent2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_int(L, 2))) {
            // @addref(trackEntries |) spine::TrackEntry *getCurrent(@optional int trackIndex)
            return _spine_SkeletonAnimation_getCurrent1(L);
        // }
    }

    luaL_error(L, "method 'spine::SkeletonAnimation::getCurrent' not support '%d' arguments", num_args);

    return 0;
}

static int _spine_SkeletonAnimation_getState(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

    // @addref(state ^) spine::AnimationState *getState()
    spine::AnimationState *ret = (spine::AnimationState *)self->getState();
    int num_ret = olua_push_cppobj(L, ret, "sp.AnimationState");

    // inject code after call
    olua_addref(L, 1, "state", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_new(lua_State *L)
{
    olua_startinvoke(L);

    // SkeletonAnimation()
    spine::SkeletonAnimation *ret = (spine::SkeletonAnimation *)new spine::SkeletonAnimation();
    int num_ret = olua_push_cppobj(L, ret, "sp.SkeletonAnimation");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_onAnimationStateEvent(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    lua_Unsigned arg2 = 0;       /** type */
    spine::Event *arg3 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.TrackEntry");
    olua_check_uint(L, 3, &arg2);
    olua_check_cppobj(L, 4, (void **)&arg3, "sp.Event");

    // void onAnimationStateEvent(spine::TrackEntry *entry, spine::EventType type, spine::Event *event)
    self->onAnimationStateEvent(arg1, (spine::EventType)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_onTrackEntryEvent(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    lua_Unsigned arg2 = 0;       /** type */
    spine::Event *arg3 = nullptr;       /** event */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.TrackEntry");
    olua_check_uint(L, 3, &arg2);
    olua_check_cppobj(L, 4, (void **)&arg3, "sp.Event");

    // void onTrackEntryEvent(spine::TrackEntry *entry, spine::EventType type, spine::Event *event)
    self->onTrackEntryEvent(arg1, (spine::EventType)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** trackIndex */
    std::string arg2;       /** name */
    bool arg3 = false;       /** loop */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_int(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_bool(L, 4, &arg3);

    // @addref(trackEntries |) spine::TrackEntry *setAnimation(int trackIndex, const std::string &name, bool loop)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->setAnimation((int)arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    // inject code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_setAnimationStateData(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::AnimationStateData *arg1 = nullptr;       /** stateData */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.AnimationStateData");

    // void setAnimationStateData(spine::AnimationStateData *stateData)
    self->setAnimationStateData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setCompleteListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    std::function<void(spine::TrackEntry *)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

    void *callback_store_obj = (void *)self;
    std::string tag = "CompleteListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setCompleteListener(const std::function<void (TrackEntry *)> &listener)
    self->setCompleteListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setDisposeListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    std::function<void(spine::TrackEntry *)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

    void *callback_store_obj = (void *)self;
    std::string tag = "DisposeListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setDisposeListener(const std::function<void (TrackEntry *)> &listener)
    self->setDisposeListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setEmptyAnimation(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    lua_Integer arg1 = 0;       /** trackIndex */
    lua_Number arg2 = 0;       /** mixDuration */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_int(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // @addref(trackEntries |) spine::TrackEntry *setEmptyAnimation(int trackIndex, float mixDuration)
    spine::TrackEntry *ret = (spine::TrackEntry *)self->setEmptyAnimation((int)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "sp.TrackEntry");

    // inject code after call
    olua_addref(L, 1, "trackEntries", -1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _spine_SkeletonAnimation_setEmptyAnimations(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    lua_Number arg1 = 0;       /** mixDuration */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_number(L, 2, &arg1);

    // void setEmptyAnimations(float mixDuration)
    self->setEmptyAnimations((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setEndListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    std::function<void(spine::TrackEntry *)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

    void *callback_store_obj = (void *)self;
    std::string tag = "EndListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setEndListener(const std::function<void (TrackEntry *)> &listener)
    self->setEndListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setEventListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    std::function<void(spine::TrackEntry *, spine::Event *)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

    void *callback_store_obj = (void *)self;
    std::string tag = "EventListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT](spine::TrackEntry *arg1, spine::Event *arg2) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");
            olua_push_cppobj(L, arg2, "sp.Event");

            olua_callback(L, callback_store_obj, func.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void setEventListener(const std::function<void (TrackEntry *, Event *)> &listener)
    self->setEventListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setInterruptListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    std::function<void(spine::TrackEntry *)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

    void *callback_store_obj = (void *)self;
    std::string tag = "InterruptListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setInterruptListener(const std::function<void (TrackEntry *)> &listener)
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
    lua_Number arg3 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void setMix(const std::string &fromAnimation, const std::string &toAnimation, float duration)
    self->setMix(arg1, arg2, (float)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setPostUpdateWorldTransformsListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    std::function<void(spine::SkeletonAnimation *)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

    void *callback_store_obj = (void *)self;
    std::string tag = "PostUpdateWorldTransformsListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT](spine::SkeletonAnimation *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "sp.SkeletonAnimation");
            olua_disable_objpool(L);

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void setPostUpdateWorldTransformsListener(@local const std::function<void (SkeletonAnimation *)> &listener)
    self->setPostUpdateWorldTransformsListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setPreUpdateWorldTransformsListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    std::function<void(spine::SkeletonAnimation *)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

    void *callback_store_obj = (void *)self;
    std::string tag = "PreUpdateWorldTransformsListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT](spine::SkeletonAnimation *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, arg1, "sp.SkeletonAnimation");
            olua_disable_objpool(L);

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // void setPreUpdateWorldTransformsListener(@local const std::function<void (SkeletonAnimation *)> &listener)
    self->setPreUpdateWorldTransformsListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setStartListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    std::function<void(spine::TrackEntry *)> arg1;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");

    void *callback_store_obj = (void *)self;
    std::string tag = "StartListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setStartListener(const std::function<void (TrackEntry *)> &listener)
    self->setStartListener(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackCompleteListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    std::function<void(spine::TrackEntry *)> arg2;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.TrackEntry");

    void *callback_store_obj = (void *)self;
    std::string tag = "TrackCompleteListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 3, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg2 = [callback_store_obj, func, MT](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setTrackCompleteListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)
    self->setTrackCompleteListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackDisposeListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    std::function<void(spine::TrackEntry *)> arg2;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.TrackEntry");

    void *callback_store_obj = (void *)self;
    std::string tag = "TrackDisposeListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 3, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg2 = [callback_store_obj, func, MT](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setTrackDisposeListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)
    self->setTrackDisposeListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackEndListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    std::function<void(spine::TrackEntry *)> arg2;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.TrackEntry");

    void *callback_store_obj = (void *)self;
    std::string tag = "TrackEndListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 3, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg2 = [callback_store_obj, func, MT](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setTrackEndListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)
    self->setTrackEndListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackEventListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    std::function<void(spine::TrackEntry *, spine::Event *)> arg2;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.TrackEntry");

    void *callback_store_obj = (void *)self;
    std::string tag = "TrackEventListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 3, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg2 = [callback_store_obj, func, MT](spine::TrackEntry *arg1, spine::Event *arg2) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");
            olua_push_cppobj(L, arg2, "sp.Event");

            olua_callback(L, callback_store_obj, func.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // void setTrackEventListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *, Event *)> &listener)
    self->setTrackEventListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackInterruptListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    std::function<void(spine::TrackEntry *)> arg2;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.TrackEntry");

    void *callback_store_obj = (void *)self;
    std::string tag = "TrackInterruptListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 3, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg2 = [callback_store_obj, func, MT](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setTrackInterruptListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)
    self->setTrackInterruptListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setTrackStartListener(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    spine::TrackEntry *arg1 = nullptr;       /** entry */
    std::function<void(spine::TrackEntry *)> arg2;       /** listener */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_cppobj(L, 2, (void **)&arg1, "sp.TrackEntry");

    void *callback_store_obj = (void *)self;
    std::string tag = "TrackStartListener";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 3, OLUA_TAG_REPLACE);
    lua_State *MT = olua_mainthread();
    arg2 = [callback_store_obj, func, MT](spine::TrackEntry *arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_cppobj(L, arg1, "sp.TrackEntry");

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setTrackStartListener(spine::TrackEntry *entry, const std::function<void (TrackEntry *)> &listener)
    self->setTrackStartListener(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _spine_SkeletonAnimation_setUpdateOnlyIfVisible(lua_State *L)
{
    olua_startinvoke(L);

    spine::SkeletonAnimation *self = nullptr;
    bool arg1 = false;       /** status */

    olua_to_cppobj(L, 1, (void **)&self, "sp.SkeletonAnimation");
    olua_check_bool(L, 2, &arg1);

    // void setUpdateOnlyIfVisible(bool status)
    self->setUpdateOnlyIfVisible(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_spine_SkeletonAnimation(lua_State *L)
{
    oluacls_class(L, "sp.SkeletonAnimation", "sp.SkeletonRenderer");
    oluacls_func(L, "__move", _spine_SkeletonAnimation___move);
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

    olua_registerluatype<spine::SkeletonAnimation>(L, "sp.SkeletonAnimation");

    return 1;
}

int luaopen_spine(lua_State *L)
{
    olua_require(L, "sp.EventType", luaopen_spine_EventType);
    olua_require(L, "sp.AttachmentType", luaopen_spine_AttachmentType);
    olua_require(L, "sp.TransformMode", luaopen_spine_TransformMode);
    olua_require(L, "sp.BlendMode", luaopen_spine_BlendMode);
    olua_require(L, "sp.PositionMode", luaopen_spine_PositionMode);
    olua_require(L, "sp.SpacingMode", luaopen_spine_SpacingMode);
    olua_require(L, "sp.RotateMode", luaopen_spine_RotateMode);
    olua_require(L, "sp.MixBlend", luaopen_spine_MixBlend);
    olua_require(L, "sp.SpineObject", luaopen_spine_SpineObject);
    olua_require(L, "sp.Event", luaopen_spine_Event);
    olua_require(L, "sp.EventData", luaopen_spine_EventData);
    olua_require(L, "sp.Updatable", luaopen_spine_Updatable);
    olua_require(L, "sp.AnimationState", luaopen_spine_AnimationState);
    olua_require(L, "sp.AnimationStateData", luaopen_spine_AnimationStateData);
    olua_require(L, "sp.Animation", luaopen_spine_Animation);
    olua_require(L, "sp.ConstraintData", luaopen_spine_ConstraintData);
    olua_require(L, "sp.IkConstraintData", luaopen_spine_IkConstraintData);
    olua_require(L, "sp.BoneData", luaopen_spine_BoneData);
    olua_require(L, "sp.SlotData", luaopen_spine_SlotData);
    olua_require(L, "sp.IkConstraint", luaopen_spine_IkConstraint);
    olua_require(L, "sp.TransformConstraint", luaopen_spine_TransformConstraint);
    olua_require(L, "sp.TransformConstraintData", luaopen_spine_TransformConstraintData);
    olua_require(L, "sp.PathConstraintData", luaopen_spine_PathConstraintData);
    olua_require(L, "sp.SkeletonBounds", luaopen_spine_SkeletonBounds);
    olua_require(L, "sp.SkeletonClipping", luaopen_spine_SkeletonClipping);
    olua_require(L, "sp.Timeline", luaopen_spine_Timeline);
    olua_require(L, "sp.CurveTimeline", luaopen_spine_CurveTimeline);
    olua_require(L, "sp.AttachmentTimeline", luaopen_spine_AttachmentTimeline);
    olua_require(L, "sp.ColorTimeline", luaopen_spine_ColorTimeline);
    olua_require(L, "sp.DeformTimeline", luaopen_spine_DeformTimeline);
    olua_require(L, "sp.DrawOrderTimeline", luaopen_spine_DrawOrderTimeline);
    olua_require(L, "sp.EventTimeline", luaopen_spine_EventTimeline);
    olua_require(L, "sp.IkConstraintTimeline", luaopen_spine_IkConstraintTimeline);
    olua_require(L, "sp.PathConstraintMixTimeline", luaopen_spine_PathConstraintMixTimeline);
    olua_require(L, "sp.PathConstraintPositionTimeline", luaopen_spine_PathConstraintPositionTimeline);
    olua_require(L, "sp.PathConstraintSpacingTimeline", luaopen_spine_PathConstraintSpacingTimeline);
    olua_require(L, "sp.TranslateTimeline", luaopen_spine_TranslateTimeline);
    olua_require(L, "sp.ShearTimeline", luaopen_spine_ShearTimeline);
    olua_require(L, "sp.TransformConstraintTimeline", luaopen_spine_TransformConstraintTimeline);
    olua_require(L, "sp.ScaleTimeline", luaopen_spine_ScaleTimeline);
    olua_require(L, "sp.RotateTimeline", luaopen_spine_RotateTimeline);
    olua_require(L, "sp.TwoColorTimeline", luaopen_spine_TwoColorTimeline);
    olua_require(L, "sp.VertexEffect", luaopen_spine_VertexEffect);
    olua_require(L, "sp.SwirlVertexEffect", luaopen_spine_SwirlVertexEffect);
    olua_require(L, "sp.JitterVertexEffect", luaopen_spine_JitterVertexEffect);
    olua_require(L, "sp.Polygon", luaopen_spine_Polygon);
    olua_require(L, "sp.Skin", luaopen_spine_Skin);
    olua_require(L, "sp.Atlas", luaopen_spine_Atlas);
    olua_require(L, "sp.Bone", luaopen_spine_Bone);
    olua_require(L, "sp.Slot", luaopen_spine_Slot);
    olua_require(L, "sp.Attachment", luaopen_spine_Attachment);
    olua_require(L, "sp.VertexAttachment", luaopen_spine_VertexAttachment);
    olua_require(L, "sp.ClippingAttachment", luaopen_spine_ClippingAttachment);
    olua_require(L, "sp.BoundingBoxAttachment", luaopen_spine_BoundingBoxAttachment);
    olua_require(L, "sp.MeshAttachment", luaopen_spine_MeshAttachment);
    olua_require(L, "sp.PathAttachment", luaopen_spine_PathAttachment);
    olua_require(L, "sp.PathConstraint", luaopen_spine_PathConstraint);
    olua_require(L, "sp.PointAttachment", luaopen_spine_PointAttachment);
    olua_require(L, "sp.RegionAttachment", luaopen_spine_RegionAttachment);
    olua_require(L, "sp.TrackEntry", luaopen_spine_TrackEntry);
    olua_require(L, "sp.SkeletonData", luaopen_spine_SkeletonData);
    olua_require(L, "sp.Skeleton", luaopen_spine_Skeleton);
    olua_require(L, "sp.SkeletonRenderer", luaopen_spine_SkeletonRenderer);
    olua_require(L, "sp.SkeletonAnimation", luaopen_spine_SkeletonAnimation);
    return 0;
}
