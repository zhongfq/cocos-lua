//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_xgame.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/cclua.h"

static int _cclua_Callback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cclua::Callback *)nullptr, "cclua.Callback");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_Callback(lua_State *L)
{
    oluacls_class(L, "cclua.Callback", nullptr);
    oluacls_func(L, "__call", _cclua_Callback___call);

    olua_registerluatype<cclua::Callback>(L, "cclua.Callback");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_QRCode_ECLevel(lua_State *L)
{
    oluacls_class(L, "cclua.QRCode.ECLevel", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "QR_ECLEVEL_H", (lua_Integer)cclua::QRCode::ECLevel::QR_ECLEVEL_H);
    oluacls_const_integer(L, "QR_ECLEVEL_L", (lua_Integer)cclua::QRCode::ECLevel::QR_ECLEVEL_L);
    oluacls_const_integer(L, "QR_ECLEVEL_M", (lua_Integer)cclua::QRCode::ECLevel::QR_ECLEVEL_M);
    oluacls_const_integer(L, "QR_ECLEVEL_Q", (lua_Integer)cclua::QRCode::ECLevel::QR_ECLEVEL_Q);

    olua_registerluatype<cclua::QRCode::ECLevel>(L, "cclua.QRCode.ECLevel");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_QRCode_EncodeMode(lua_State *L)
{
    oluacls_class(L, "cclua.QRCode.EncodeMode", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "QR_MODE_8", (lua_Integer)cclua::QRCode::EncodeMode::QR_MODE_8);
    oluacls_const_integer(L, "QR_MODE_AN", (lua_Integer)cclua::QRCode::EncodeMode::QR_MODE_AN);
    oluacls_const_integer(L, "QR_MODE_KANJI", (lua_Integer)cclua::QRCode::EncodeMode::QR_MODE_KANJI);
    oluacls_const_integer(L, "QR_MODE_NUL", (lua_Integer)cclua::QRCode::EncodeMode::QR_MODE_NUL);
    oluacls_const_integer(L, "QR_MODE_NUM", (lua_Integer)cclua::QRCode::EncodeMode::QR_MODE_NUM);
    oluacls_const_integer(L, "QR_MODE_STRUCTURE", (lua_Integer)cclua::QRCode::EncodeMode::QR_MODE_STRUCTURE);

    olua_registerluatype<cclua::QRCode::EncodeMode>(L, "cclua.QRCode.EncodeMode");

    return 1;
}
OLUA_END_DECLS

static int _cclua_QRCode___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::QRCode *)olua_toobj(L, 1, "cclua.QRCode");
    olua_push_obj(L, self, "cclua.QRCode");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_QRCode_create1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** code */
    lua_Integer arg2 = 0;       /** version */
    lua_Unsigned arg3 = 0;       /** level */
    lua_Unsigned arg4 = 0;       /** hint */
    bool arg5 = false;       /** casesensitive */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_uint(L, 4, &arg4);
    olua_check_bool(L, 5, &arg5);

    // static cclua::QRCode *create(const std::string &code, @optional int version, @optional cclua::QRCode::ECLevel level, @optional cclua::QRCode::EncodeMode hint, @optional bool casesensitive)
    cclua::QRCode *ret = cclua::QRCode::create(arg1, (int)arg2, (cclua::QRCode::ECLevel)arg3, (cclua::QRCode::EncodeMode)arg4, arg5);
    int num_ret = olua_push_obj(L, ret, "cclua.QRCode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_QRCode_create2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** code */

    olua_check_std_string(L, 1, &arg1);

    // static cclua::QRCode *create(const std::string &code, @optional int version, @optional cclua::QRCode::ECLevel level, @optional cclua::QRCode::EncodeMode hint, @optional bool casesensitive)
    cclua::QRCode *ret = cclua::QRCode::create(arg1);
    int num_ret = olua_push_obj(L, ret, "cclua.QRCode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_QRCode_create3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** code */
    lua_Integer arg2 = 0;       /** version */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);

    // static cclua::QRCode *create(const std::string &code, @optional int version, @optional cclua::QRCode::ECLevel level, @optional cclua::QRCode::EncodeMode hint, @optional bool casesensitive)
    cclua::QRCode *ret = cclua::QRCode::create(arg1, (int)arg2);
    int num_ret = olua_push_obj(L, ret, "cclua.QRCode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_QRCode_create4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** code */
    lua_Integer arg2 = 0;       /** version */
    lua_Unsigned arg3 = 0;       /** level */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static cclua::QRCode *create(const std::string &code, @optional int version, @optional cclua::QRCode::ECLevel level, @optional cclua::QRCode::EncodeMode hint, @optional bool casesensitive)
    cclua::QRCode *ret = cclua::QRCode::create(arg1, (int)arg2, (cclua::QRCode::ECLevel)arg3);
    int num_ret = olua_push_obj(L, ret, "cclua.QRCode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_QRCode_create5(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** code */
    lua_Integer arg2 = 0;       /** version */
    lua_Unsigned arg3 = 0;       /** level */
    lua_Unsigned arg4 = 0;       /** hint */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_uint(L, 4, &arg4);

    // static cclua::QRCode *create(const std::string &code, @optional int version, @optional cclua::QRCode::ECLevel level, @optional cclua::QRCode::EncodeMode hint, @optional bool casesensitive)
    cclua::QRCode *ret = cclua::QRCode::create(arg1, (int)arg2, (cclua::QRCode::ECLevel)arg3, (cclua::QRCode::EncodeMode)arg4);
    int num_ret = olua_push_obj(L, ret, "cclua.QRCode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_QRCode_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static cclua::QRCode *create(const std::string &code, @optional int version, @optional cclua::QRCode::ECLevel level, @optional cclua::QRCode::EncodeMode hint, @optional bool casesensitive)
            return _cclua_QRCode_create2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_int(L, 2))) {
            // static cclua::QRCode *create(const std::string &code, @optional int version, @optional cclua::QRCode::ECLevel level, @optional cclua::QRCode::EncodeMode hint, @optional bool casesensitive)
            return _cclua_QRCode_create3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_int(L, 2)) && (olua_is_uint(L, 3))) {
            // static cclua::QRCode *create(const std::string &code, @optional int version, @optional cclua::QRCode::ECLevel level, @optional cclua::QRCode::EncodeMode hint, @optional bool casesensitive)
            return _cclua_QRCode_create4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_int(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // static cclua::QRCode *create(const std::string &code, @optional int version, @optional cclua::QRCode::ECLevel level, @optional cclua::QRCode::EncodeMode hint, @optional bool casesensitive)
            return _cclua_QRCode_create5(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_int(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_bool(L, 5))) {
            // static cclua::QRCode *create(const std::string &code, @optional int version, @optional cclua::QRCode::ECLevel level, @optional cclua::QRCode::EncodeMode hint, @optional bool casesensitive)
            return _cclua_QRCode_create1(L);
        // }
    }

    luaL_error(L, "method 'cclua::QRCode::create' not support '%d' arguments", num_args);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_QRCode(lua_State *L)
{
    oluacls_class(L, "cclua.QRCode", "cc.Sprite");
    oluacls_func(L, "__olua_move", _cclua_QRCode___olua_move);
    oluacls_func(L, "create", _cclua_QRCode_create);

    olua_registerluatype<cclua::QRCode>(L, "cclua.QRCode");

    return 1;
}
OLUA_END_DECLS

static int _cclua_SceneNoCamera___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::SceneNoCamera *)olua_toobj(L, 1, "cclua.SceneNoCamera");
    olua_push_obj(L, self, "cclua.SceneNoCamera");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_SceneNoCamera_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cclua::SceneNoCamera *create()
    cclua::SceneNoCamera *ret = cclua::SceneNoCamera::create();
    int num_ret = olua_push_obj(L, ret, "cclua.SceneNoCamera");

    olua_endinvoke(L);

    return num_ret;
}

#if (CC_USE_PHYSICS || (CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION))
static int _cclua_SceneNoCamera_createWithPhysics(lua_State *L)
{
    olua_startinvoke(L);

    // static cclua::SceneNoCamera *createWithPhysics()
    cclua::SceneNoCamera *ret = cclua::SceneNoCamera::createWithPhysics();
    int num_ret = olua_push_obj(L, ret, "cclua.SceneNoCamera");

    olua_endinvoke(L);

    return num_ret;
}
#endif

static int _cclua_SceneNoCamera_createWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    olua_check_cocos2d_Size(L, 1, &arg1);

    // static cclua::SceneNoCamera *createWithSize(const cocos2d::Size &size)
    cclua::SceneNoCamera *ret = cclua::SceneNoCamera::createWithSize(arg1);
    int num_ret = olua_push_obj(L, ret, "cclua.SceneNoCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_SceneNoCamera_new(lua_State *L)
{
    olua_startinvoke(L);

    // SceneNoCamera()
    cclua::SceneNoCamera *ret = new cclua::SceneNoCamera();
    int num_ret = olua_push_obj(L, ret, "cclua.SceneNoCamera");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_SceneNoCamera(lua_State *L)
{
    oluacls_class(L, "cclua.SceneNoCamera", "cc.Scene");
    oluacls_func(L, "__olua_move", _cclua_SceneNoCamera___olua_move);
    oluacls_func(L, "create", _cclua_SceneNoCamera_create);
#if (CC_USE_PHYSICS || (CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION))
    oluacls_func(L, "createWithPhysics", _cclua_SceneNoCamera_createWithPhysics);
#endif
    oluacls_func(L, "createWithSize", _cclua_SceneNoCamera_createWithSize);
    oluacls_func(L, "new", _cclua_SceneNoCamera_new);

    olua_registerluatype<cclua::SceneNoCamera>(L, "cclua.SceneNoCamera");

    return 1;
}
OLUA_END_DECLS

static int _cclua_permission_status___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::permission::status *)olua_toobj(L, 1, "cclua.permission.status");
    olua_push_obj(L, self, "cclua.permission.status");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_permission_status(lua_State *L)
{
    oluacls_class(L, "cclua.permission.status", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_func(L, "__olua_move", _cclua_permission_status___olua_move);
    oluacls_const_string(L, "ALWAYS", (const char *)cclua::permission::status::ALWAYS.c_str());
    oluacls_const_string(L, "AUTHORIZED", (const char *)cclua::permission::status::AUTHORIZED.c_str());
    oluacls_const_string(L, "DENIED", (const char *)cclua::permission::status::DENIED.c_str());
    oluacls_const_string(L, "LIMITED", (const char *)cclua::permission::status::LIMITED.c_str());
    oluacls_const_string(L, "NOT_DETERMINED", (const char *)cclua::permission::status::NOT_DETERMINED.c_str());
    oluacls_const_string(L, "RESTRICTED", (const char *)cclua::permission::status::RESTRICTED.c_str());
    oluacls_const_string(L, "UNKNOWN", (const char *)cclua::permission::status::UNKNOWN.c_str());
    oluacls_const_string(L, "WHEN_IN_USE", (const char *)cclua::permission::status::WHEN_IN_USE.c_str());

    olua_registerluatype<cclua::permission::status>(L, "cclua.permission.status");

    return 1;
}
OLUA_END_DECLS

static int _cclua_permission_android___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::permission::android *)olua_toobj(L, 1, "cclua.permission.android");
    olua_push_obj(L, self, "cclua.permission.android");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_permission_android(lua_State *L)
{
    oluacls_class(L, "cclua.permission.android", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_func(L, "__olua_move", _cclua_permission_android___olua_move);
    oluacls_const_string(L, "ACCEPT_HANDOVER", (const char *)cclua::permission::android::ACCEPT_HANDOVER.c_str());
    oluacls_const_string(L, "ACCESS_CHECKIN_PROPERTIES", (const char *)cclua::permission::android::ACCESS_CHECKIN_PROPERTIES.c_str());
    oluacls_const_string(L, "ACCESS_COARSE_LOCATION", (const char *)cclua::permission::android::ACCESS_COARSE_LOCATION.c_str());
    oluacls_const_string(L, "ACCESS_FINE_LOCATION", (const char *)cclua::permission::android::ACCESS_FINE_LOCATION.c_str());
    oluacls_const_string(L, "ACCESS_LOCATION_EXTRA_COMMANDS", (const char *)cclua::permission::android::ACCESS_LOCATION_EXTRA_COMMANDS.c_str());
    oluacls_const_string(L, "ACCESS_NETWORK_STATE", (const char *)cclua::permission::android::ACCESS_NETWORK_STATE.c_str());
    oluacls_const_string(L, "ACCESS_NOTIFICATION_POLICY", (const char *)cclua::permission::android::ACCESS_NOTIFICATION_POLICY.c_str());
    oluacls_const_string(L, "ACCESS_WIFI_STATE", (const char *)cclua::permission::android::ACCESS_WIFI_STATE.c_str());
    oluacls_const_string(L, "ACCOUNT_MANAGER", (const char *)cclua::permission::android::ACCOUNT_MANAGER.c_str());
    oluacls_const_string(L, "ADD_VOICEMAIL", (const char *)cclua::permission::android::ADD_VOICEMAIL.c_str());
    oluacls_const_string(L, "ANSWER_PHONE_CALLS", (const char *)cclua::permission::android::ANSWER_PHONE_CALLS.c_str());
    oluacls_const_string(L, "BATTERY_STATS", (const char *)cclua::permission::android::BATTERY_STATS.c_str());
    oluacls_const_string(L, "BIND_ACCESSIBILITY_SERVICE", (const char *)cclua::permission::android::BIND_ACCESSIBILITY_SERVICE.c_str());
    oluacls_const_string(L, "BIND_APPWIDGET", (const char *)cclua::permission::android::BIND_APPWIDGET.c_str());
    oluacls_const_string(L, "BIND_AUTOFILL_SERVICE", (const char *)cclua::permission::android::BIND_AUTOFILL_SERVICE.c_str());
    oluacls_const_string(L, "BIND_CARRIER_MESSAGING_SERVICE", (const char *)cclua::permission::android::BIND_CARRIER_MESSAGING_SERVICE.c_str());
    oluacls_const_string(L, "BIND_CARRIER_SERVICES", (const char *)cclua::permission::android::BIND_CARRIER_SERVICES.c_str());
    oluacls_const_string(L, "BIND_CHOOSER_TARGET_SERVICE", (const char *)cclua::permission::android::BIND_CHOOSER_TARGET_SERVICE.c_str());
    oluacls_const_string(L, "BIND_CONDITION_PROVIDER_SERVICE", (const char *)cclua::permission::android::BIND_CONDITION_PROVIDER_SERVICE.c_str());
    oluacls_const_string(L, "BIND_DEVICE_ADMIN", (const char *)cclua::permission::android::BIND_DEVICE_ADMIN.c_str());
    oluacls_const_string(L, "BIND_DREAM_SERVICE", (const char *)cclua::permission::android::BIND_DREAM_SERVICE.c_str());
    oluacls_const_string(L, "BIND_INCALL_SERVICE", (const char *)cclua::permission::android::BIND_INCALL_SERVICE.c_str());
    oluacls_const_string(L, "BIND_INPUT_METHOD", (const char *)cclua::permission::android::BIND_INPUT_METHOD.c_str());
    oluacls_const_string(L, "BIND_MIDI_DEVICE_SERVICE", (const char *)cclua::permission::android::BIND_MIDI_DEVICE_SERVICE.c_str());
    oluacls_const_string(L, "BIND_NFC_SERVICE", (const char *)cclua::permission::android::BIND_NFC_SERVICE.c_str());
    oluacls_const_string(L, "BIND_NOTIFICATION_LISTENER_SERVICE", (const char *)cclua::permission::android::BIND_NOTIFICATION_LISTENER_SERVICE.c_str());
    oluacls_const_string(L, "BIND_PRINT_SERVICE", (const char *)cclua::permission::android::BIND_PRINT_SERVICE.c_str());
    oluacls_const_string(L, "BIND_QUICK_SETTINGS_TILE", (const char *)cclua::permission::android::BIND_QUICK_SETTINGS_TILE.c_str());
    oluacls_const_string(L, "BIND_REMOTEVIEWS", (const char *)cclua::permission::android::BIND_REMOTEVIEWS.c_str());
    oluacls_const_string(L, "BIND_SCREENING_SERVICE", (const char *)cclua::permission::android::BIND_SCREENING_SERVICE.c_str());
    oluacls_const_string(L, "BIND_TELECOM_CONNECTION_SERVICE", (const char *)cclua::permission::android::BIND_TELECOM_CONNECTION_SERVICE.c_str());
    oluacls_const_string(L, "BIND_TEXT_SERVICE", (const char *)cclua::permission::android::BIND_TEXT_SERVICE.c_str());
    oluacls_const_string(L, "BIND_TV_INPUT", (const char *)cclua::permission::android::BIND_TV_INPUT.c_str());
    oluacls_const_string(L, "BIND_VISUAL_VOICEMAIL_SERVICE", (const char *)cclua::permission::android::BIND_VISUAL_VOICEMAIL_SERVICE.c_str());
    oluacls_const_string(L, "BIND_VOICE_INTERACTION", (const char *)cclua::permission::android::BIND_VOICE_INTERACTION.c_str());
    oluacls_const_string(L, "BIND_VPN_SERVICE", (const char *)cclua::permission::android::BIND_VPN_SERVICE.c_str());
    oluacls_const_string(L, "BIND_VR_LISTENER_SERVICE", (const char *)cclua::permission::android::BIND_VR_LISTENER_SERVICE.c_str());
    oluacls_const_string(L, "BIND_WALLPAPER", (const char *)cclua::permission::android::BIND_WALLPAPER.c_str());
    oluacls_const_string(L, "BLUETOOTH", (const char *)cclua::permission::android::BLUETOOTH.c_str());
    oluacls_const_string(L, "BLUETOOTH_ADMIN", (const char *)cclua::permission::android::BLUETOOTH_ADMIN.c_str());
    oluacls_const_string(L, "BLUETOOTH_PRIVILEGED", (const char *)cclua::permission::android::BLUETOOTH_PRIVILEGED.c_str());
    oluacls_const_string(L, "BODY_SENSORS", (const char *)cclua::permission::android::BODY_SENSORS.c_str());
    oluacls_const_string(L, "BROADCAST_PACKAGE_REMOVED", (const char *)cclua::permission::android::BROADCAST_PACKAGE_REMOVED.c_str());
    oluacls_const_string(L, "BROADCAST_SMS", (const char *)cclua::permission::android::BROADCAST_SMS.c_str());
    oluacls_const_string(L, "BROADCAST_STICKY", (const char *)cclua::permission::android::BROADCAST_STICKY.c_str());
    oluacls_const_string(L, "BROADCAST_WAP_PUSH", (const char *)cclua::permission::android::BROADCAST_WAP_PUSH.c_str());
    oluacls_const_string(L, "CALL_PHONE", (const char *)cclua::permission::android::CALL_PHONE.c_str());
    oluacls_const_string(L, "CALL_PRIVILEGED", (const char *)cclua::permission::android::CALL_PRIVILEGED.c_str());
    oluacls_const_string(L, "CAMERA", (const char *)cclua::permission::android::CAMERA.c_str());
    oluacls_const_string(L, "CAPTURE_AUDIO_OUTPUT", (const char *)cclua::permission::android::CAPTURE_AUDIO_OUTPUT.c_str());
    oluacls_const_string(L, "CAPTURE_SECURE_VIDEO_OUTPUT", (const char *)cclua::permission::android::CAPTURE_SECURE_VIDEO_OUTPUT.c_str());
    oluacls_const_string(L, "CAPTURE_VIDEO_OUTPUT", (const char *)cclua::permission::android::CAPTURE_VIDEO_OUTPUT.c_str());
    oluacls_const_string(L, "CHANGE_COMPONENT_ENABLED_STATE", (const char *)cclua::permission::android::CHANGE_COMPONENT_ENABLED_STATE.c_str());
    oluacls_const_string(L, "CHANGE_CONFIGURATION", (const char *)cclua::permission::android::CHANGE_CONFIGURATION.c_str());
    oluacls_const_string(L, "CHANGE_NETWORK_STATE", (const char *)cclua::permission::android::CHANGE_NETWORK_STATE.c_str());
    oluacls_const_string(L, "CHANGE_WIFI_MULTICAST_STATE", (const char *)cclua::permission::android::CHANGE_WIFI_MULTICAST_STATE.c_str());
    oluacls_const_string(L, "CHANGE_WIFI_STATE", (const char *)cclua::permission::android::CHANGE_WIFI_STATE.c_str());
    oluacls_const_string(L, "CLEAR_APP_CACHE", (const char *)cclua::permission::android::CLEAR_APP_CACHE.c_str());
    oluacls_const_string(L, "CONTROL_LOCATION_UPDATES", (const char *)cclua::permission::android::CONTROL_LOCATION_UPDATES.c_str());
    oluacls_const_string(L, "DELETE_CACHE_FILES", (const char *)cclua::permission::android::DELETE_CACHE_FILES.c_str());
    oluacls_const_string(L, "DELETE_PACKAGES", (const char *)cclua::permission::android::DELETE_PACKAGES.c_str());
    oluacls_const_string(L, "DIAGNOSTIC", (const char *)cclua::permission::android::DIAGNOSTIC.c_str());
    oluacls_const_string(L, "DISABLE_KEYGUARD", (const char *)cclua::permission::android::DISABLE_KEYGUARD.c_str());
    oluacls_const_string(L, "DUMP", (const char *)cclua::permission::android::DUMP.c_str());
    oluacls_const_string(L, "EXPAND_STATUS_BAR", (const char *)cclua::permission::android::EXPAND_STATUS_BAR.c_str());
    oluacls_const_string(L, "FACTORY_TEST", (const char *)cclua::permission::android::FACTORY_TEST.c_str());
    oluacls_const_string(L, "FOREGROUND_SERVICE", (const char *)cclua::permission::android::FOREGROUND_SERVICE.c_str());
    oluacls_const_string(L, "GET_ACCOUNTS", (const char *)cclua::permission::android::GET_ACCOUNTS.c_str());
    oluacls_const_string(L, "GET_ACCOUNTS_PRIVILEGED", (const char *)cclua::permission::android::GET_ACCOUNTS_PRIVILEGED.c_str());
    oluacls_const_string(L, "GET_PACKAGE_SIZE", (const char *)cclua::permission::android::GET_PACKAGE_SIZE.c_str());
    oluacls_const_string(L, "GET_TASKS", (const char *)cclua::permission::android::GET_TASKS.c_str());
    oluacls_const_string(L, "GLOBAL_SEARCH", (const char *)cclua::permission::android::GLOBAL_SEARCH.c_str());
    oluacls_const_string(L, "INSTALL_LOCATION_PROVIDER", (const char *)cclua::permission::android::INSTALL_LOCATION_PROVIDER.c_str());
    oluacls_const_string(L, "INSTALL_PACKAGES", (const char *)cclua::permission::android::INSTALL_PACKAGES.c_str());
    oluacls_const_string(L, "INSTALL_SHORTCUT", (const char *)cclua::permission::android::INSTALL_SHORTCUT.c_str());
    oluacls_const_string(L, "INSTANT_APP_FOREGROUND_SERVICE", (const char *)cclua::permission::android::INSTANT_APP_FOREGROUND_SERVICE.c_str());
    oluacls_const_string(L, "INTERNET", (const char *)cclua::permission::android::INTERNET.c_str());
    oluacls_const_string(L, "KILL_BACKGROUND_PROCESSES", (const char *)cclua::permission::android::KILL_BACKGROUND_PROCESSES.c_str());
    oluacls_const_string(L, "LOCATION_HARDWARE", (const char *)cclua::permission::android::LOCATION_HARDWARE.c_str());
    oluacls_const_string(L, "MANAGE_DOCUMENTS", (const char *)cclua::permission::android::MANAGE_DOCUMENTS.c_str());
    oluacls_const_string(L, "MANAGE_OWN_CALLS", (const char *)cclua::permission::android::MANAGE_OWN_CALLS.c_str());
    oluacls_const_string(L, "MASTER_CLEAR", (const char *)cclua::permission::android::MASTER_CLEAR.c_str());
    oluacls_const_string(L, "MEDIA_CONTENT_CONTROL", (const char *)cclua::permission::android::MEDIA_CONTENT_CONTROL.c_str());
    oluacls_const_string(L, "MODIFY_AUDIO_SETTINGS", (const char *)cclua::permission::android::MODIFY_AUDIO_SETTINGS.c_str());
    oluacls_const_string(L, "MODIFY_PHONE_STATE", (const char *)cclua::permission::android::MODIFY_PHONE_STATE.c_str());
    oluacls_const_string(L, "MOUNT_FORMAT_FILESYSTEMS", (const char *)cclua::permission::android::MOUNT_FORMAT_FILESYSTEMS.c_str());
    oluacls_const_string(L, "MOUNT_UNMOUNT_FILESYSTEMS", (const char *)cclua::permission::android::MOUNT_UNMOUNT_FILESYSTEMS.c_str());
    oluacls_const_string(L, "NFC", (const char *)cclua::permission::android::NFC.c_str());
    oluacls_const_string(L, "NFC_TRANSACTION_EVENT", (const char *)cclua::permission::android::NFC_TRANSACTION_EVENT.c_str());
    oluacls_const_string(L, "PACKAGE_USAGE_STATS", (const char *)cclua::permission::android::PACKAGE_USAGE_STATS.c_str());
    oluacls_const_string(L, "PERSISTENT_ACTIVITY", (const char *)cclua::permission::android::PERSISTENT_ACTIVITY.c_str());
    oluacls_const_string(L, "PROCESS_OUTGOING_CALLS", (const char *)cclua::permission::android::PROCESS_OUTGOING_CALLS.c_str());
    oluacls_const_string(L, "READ_CALENDAR", (const char *)cclua::permission::android::READ_CALENDAR.c_str());
    oluacls_const_string(L, "READ_CALL_LOG", (const char *)cclua::permission::android::READ_CALL_LOG.c_str());
    oluacls_const_string(L, "READ_CONTACTS", (const char *)cclua::permission::android::READ_CONTACTS.c_str());
    oluacls_const_string(L, "READ_EXTERNAL_STORAGE", (const char *)cclua::permission::android::READ_EXTERNAL_STORAGE.c_str());
    oluacls_const_string(L, "READ_FRAME_BUFFER", (const char *)cclua::permission::android::READ_FRAME_BUFFER.c_str());
    oluacls_const_string(L, "READ_INPUT_STATE", (const char *)cclua::permission::android::READ_INPUT_STATE.c_str());
    oluacls_const_string(L, "READ_LOGS", (const char *)cclua::permission::android::READ_LOGS.c_str());
    oluacls_const_string(L, "READ_PHONE_NUMBERS", (const char *)cclua::permission::android::READ_PHONE_NUMBERS.c_str());
    oluacls_const_string(L, "READ_PHONE_STATE", (const char *)cclua::permission::android::READ_PHONE_STATE.c_str());
    oluacls_const_string(L, "READ_SMS", (const char *)cclua::permission::android::READ_SMS.c_str());
    oluacls_const_string(L, "READ_SYNC_SETTINGS", (const char *)cclua::permission::android::READ_SYNC_SETTINGS.c_str());
    oluacls_const_string(L, "READ_SYNC_STATS", (const char *)cclua::permission::android::READ_SYNC_STATS.c_str());
    oluacls_const_string(L, "READ_VOICEMAIL", (const char *)cclua::permission::android::READ_VOICEMAIL.c_str());
    oluacls_const_string(L, "REBOOT", (const char *)cclua::permission::android::REBOOT.c_str());
    oluacls_const_string(L, "RECEIVE_BOOT_COMPLETED", (const char *)cclua::permission::android::RECEIVE_BOOT_COMPLETED.c_str());
    oluacls_const_string(L, "RECEIVE_MMS", (const char *)cclua::permission::android::RECEIVE_MMS.c_str());
    oluacls_const_string(L, "RECEIVE_SMS", (const char *)cclua::permission::android::RECEIVE_SMS.c_str());
    oluacls_const_string(L, "RECEIVE_WAP_PUSH", (const char *)cclua::permission::android::RECEIVE_WAP_PUSH.c_str());
    oluacls_const_string(L, "RECORD_AUDIO", (const char *)cclua::permission::android::RECORD_AUDIO.c_str());
    oluacls_const_string(L, "REORDER_TASKS", (const char *)cclua::permission::android::REORDER_TASKS.c_str());
    oluacls_const_string(L, "REQUEST_COMPANION_RUN_IN_BACKGROUND", (const char *)cclua::permission::android::REQUEST_COMPANION_RUN_IN_BACKGROUND.c_str());
    oluacls_const_string(L, "REQUEST_COMPANION_USE_DATA_IN_BACKGROUND", (const char *)cclua::permission::android::REQUEST_COMPANION_USE_DATA_IN_BACKGROUND.c_str());
    oluacls_const_string(L, "REQUEST_DELETE_PACKAGES", (const char *)cclua::permission::android::REQUEST_DELETE_PACKAGES.c_str());
    oluacls_const_string(L, "REQUEST_IGNORE_BATTERY_OPTIMIZATIONS", (const char *)cclua::permission::android::REQUEST_IGNORE_BATTERY_OPTIMIZATIONS.c_str());
    oluacls_const_string(L, "REQUEST_INSTALL_PACKAGES", (const char *)cclua::permission::android::REQUEST_INSTALL_PACKAGES.c_str());
    oluacls_const_string(L, "RESTART_PACKAGES", (const char *)cclua::permission::android::RESTART_PACKAGES.c_str());
    oluacls_const_string(L, "SEND_RESPOND_VIA_MESSAGE", (const char *)cclua::permission::android::SEND_RESPOND_VIA_MESSAGE.c_str());
    oluacls_const_string(L, "SEND_SMS", (const char *)cclua::permission::android::SEND_SMS.c_str());
    oluacls_const_string(L, "SET_ALARM", (const char *)cclua::permission::android::SET_ALARM.c_str());
    oluacls_const_string(L, "SET_ALWAYS_FINISH", (const char *)cclua::permission::android::SET_ALWAYS_FINISH.c_str());
    oluacls_const_string(L, "SET_ANIMATION_SCALE", (const char *)cclua::permission::android::SET_ANIMATION_SCALE.c_str());
    oluacls_const_string(L, "SET_DEBUG_APP", (const char *)cclua::permission::android::SET_DEBUG_APP.c_str());
    oluacls_const_string(L, "SET_PREFERRED_APPLICATIONS", (const char *)cclua::permission::android::SET_PREFERRED_APPLICATIONS.c_str());
    oluacls_const_string(L, "SET_PROCESS_LIMIT", (const char *)cclua::permission::android::SET_PROCESS_LIMIT.c_str());
    oluacls_const_string(L, "SET_TIME", (const char *)cclua::permission::android::SET_TIME.c_str());
    oluacls_const_string(L, "SET_TIME_ZONE", (const char *)cclua::permission::android::SET_TIME_ZONE.c_str());
    oluacls_const_string(L, "SET_WALLPAPER", (const char *)cclua::permission::android::SET_WALLPAPER.c_str());
    oluacls_const_string(L, "SET_WALLPAPER_HINTS", (const char *)cclua::permission::android::SET_WALLPAPER_HINTS.c_str());
    oluacls_const_string(L, "SIGNAL_PERSISTENT_PROCESSES", (const char *)cclua::permission::android::SIGNAL_PERSISTENT_PROCESSES.c_str());
    oluacls_const_string(L, "STATUS_BAR", (const char *)cclua::permission::android::STATUS_BAR.c_str());
    oluacls_const_string(L, "SYSTEM_ALERT_WINDOW", (const char *)cclua::permission::android::SYSTEM_ALERT_WINDOW.c_str());
    oluacls_const_string(L, "TRANSMIT_IR", (const char *)cclua::permission::android::TRANSMIT_IR.c_str());
    oluacls_const_string(L, "UNINSTALL_SHORTCUT", (const char *)cclua::permission::android::UNINSTALL_SHORTCUT.c_str());
    oluacls_const_string(L, "UPDATE_DEVICE_STATS", (const char *)cclua::permission::android::UPDATE_DEVICE_STATS.c_str());
    oluacls_const_string(L, "USE_BIOMETRIC", (const char *)cclua::permission::android::USE_BIOMETRIC.c_str());
    oluacls_const_string(L, "USE_FINGERPRINT", (const char *)cclua::permission::android::USE_FINGERPRINT.c_str());
    oluacls_const_string(L, "USE_SIP", (const char *)cclua::permission::android::USE_SIP.c_str());
    oluacls_const_string(L, "VIBRATE", (const char *)cclua::permission::android::VIBRATE.c_str());
    oluacls_const_string(L, "WAKE_LOCK", (const char *)cclua::permission::android::WAKE_LOCK.c_str());
    oluacls_const_string(L, "WRITE_APN_SETTINGS", (const char *)cclua::permission::android::WRITE_APN_SETTINGS.c_str());
    oluacls_const_string(L, "WRITE_CALENDAR", (const char *)cclua::permission::android::WRITE_CALENDAR.c_str());
    oluacls_const_string(L, "WRITE_CALL_LOG", (const char *)cclua::permission::android::WRITE_CALL_LOG.c_str());
    oluacls_const_string(L, "WRITE_CONTACTS", (const char *)cclua::permission::android::WRITE_CONTACTS.c_str());
    oluacls_const_string(L, "WRITE_EXTERNAL_STORAGE", (const char *)cclua::permission::android::WRITE_EXTERNAL_STORAGE.c_str());
    oluacls_const_string(L, "WRITE_GSERVICES", (const char *)cclua::permission::android::WRITE_GSERVICES.c_str());
    oluacls_const_string(L, "WRITE_SECURE_SETTINGS", (const char *)cclua::permission::android::WRITE_SECURE_SETTINGS.c_str());
    oluacls_const_string(L, "WRITE_SETTINGS", (const char *)cclua::permission::android::WRITE_SETTINGS.c_str());
    oluacls_const_string(L, "WRITE_SYNC_SETTINGS", (const char *)cclua::permission::android::WRITE_SYNC_SETTINGS.c_str());
    oluacls_const_string(L, "WRITE_VOICEMAIL", (const char *)cclua::permission::android::WRITE_VOICEMAIL.c_str());

    olua_registerluatype<cclua::permission::android>(L, "cclua.permission.android");

    return 1;
}
OLUA_END_DECLS

static int _cclua_permission___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::permission *)olua_toobj(L, 1, "cclua.permission");
    olua_push_obj(L, self, "cclua.permission");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_permission_get_android(lua_State *L)
{
    olua_startinvoke(L);

    lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
    lua_getfield(L, -1, olua_getluatype<cclua::permission::android>(L));

    olua_endinvoke(L);

    return 1;
}

static int _cclua_permission_get_status(lua_State *L)
{
    olua_startinvoke(L);

    lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
    lua_getfield(L, -1, olua_getluatype<cclua::permission::status>(L));

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_permission(lua_State *L)
{
    oluacls_class(L, "cclua.permission", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_func(L, "__olua_move", _cclua_permission___olua_move);
    oluacls_prop(L, "android", _cclua_permission_get_android, nullptr);
    oluacls_prop(L, "status", _cclua_permission_get_status, nullptr);
    oluacls_const_string(L, "CALENDAR", (const char *)cclua::permission::CALENDAR.c_str());
    oluacls_const_string(L, "CAMERA", (const char *)cclua::permission::CAMERA.c_str());
    oluacls_const_string(L, "CONTACTS", (const char *)cclua::permission::CONTACTS.c_str());
    oluacls_const_string(L, "LOCATION", (const char *)cclua::permission::LOCATION.c_str());
    oluacls_const_string(L, "MICROPHONE", (const char *)cclua::permission::MICROPHONE.c_str());
    oluacls_const_string(L, "PHONE", (const char *)cclua::permission::PHONE.c_str());
    oluacls_const_string(L, "PHOTO", (const char *)cclua::permission::PHOTO.c_str());
    oluacls_const_string(L, "SENSORS", (const char *)cclua::permission::SENSORS.c_str());
    oluacls_const_string(L, "SMS", (const char *)cclua::permission::SMS.c_str());
    oluacls_const_string(L, "STORAGE", (const char *)cclua::permission::STORAGE.c_str());
    oluacls_const_string(L, "TRACKING", (const char *)cclua::permission::TRACKING.c_str());

    olua_registerluatype<cclua::permission>(L, "cclua.permission");

    return 1;
}
OLUA_END_DECLS

static int _cclua_runtime___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::runtime *)olua_toobj(L, 1, "cclua.runtime");
    olua_push_obj(L, self, "cclua.runtime");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_runtime_alert(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** title */
    std::string arg2;       /** message */
    std::string arg3;       /** ok */
    std::string arg4;       /** no */
    std::function<void(bool)> arg5;       /** callback */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_callback(L, 5, &arg5, "std.function");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.runtime");
    std::string cb_tag = "alert";
    std::string cb_name = olua_setcallback(L, cb_store,  5, cb_tag.c_str(), OLUA_TAG_NEW);
    olua_Context cb_ctx = olua_context(L);
    arg5 = [cb_store, cb_name, cb_ctx](bool arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_bool(L, arg1);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, @localvar const std::function<void (bool)> &callback)
    cclua::runtime::alert(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_canOpenURL(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uri */

    olua_check_std_string(L, 1, &arg1);

    // static bool canOpenURL(const std::string &uri)
    bool ret = cclua::runtime::canOpenURL(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_capture1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */
    lua_Number arg2 = 0;       /** width */
    lua_Number arg3 = 0;       /** height */
    lua_Number arg4 = 0;       /** scale */
    lua_Unsigned arg5 = 0;       /** format */
    lua_Unsigned arg6 = 0;       /** depthStencilFormat */

    olua_check_obj(L, 1, &arg1, "cc.Node");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_uint(L, 5, &arg5);
    olua_check_uint(L, 6, &arg6);

    // static cocos2d::Sprite *capture(cocos2d::Node *node, float width, float height, @optional float scale, @optional cocos2d::Texture2D::PixelFormat format, @optional GLuint depthStencilFormat)
    cocos2d::Sprite *ret = cclua::runtime::capture(arg1, (float)arg2, (float)arg3, (float)arg4, (cocos2d::Texture2D::PixelFormat)arg5, (GLuint)arg6);
    int num_ret = olua_push_obj(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_capture2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */
    lua_Number arg2 = 0;       /** width */
    lua_Number arg3 = 0;       /** height */

    olua_check_obj(L, 1, &arg1, "cc.Node");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::Sprite *capture(cocos2d::Node *node, float width, float height, @optional float scale, @optional cocos2d::Texture2D::PixelFormat format, @optional GLuint depthStencilFormat)
    cocos2d::Sprite *ret = cclua::runtime::capture(arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_obj(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_capture3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */
    lua_Number arg2 = 0;       /** width */
    lua_Number arg3 = 0;       /** height */
    lua_Number arg4 = 0;       /** scale */

    olua_check_obj(L, 1, &arg1, "cc.Node");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::Sprite *capture(cocos2d::Node *node, float width, float height, @optional float scale, @optional cocos2d::Texture2D::PixelFormat format, @optional GLuint depthStencilFormat)
    cocos2d::Sprite *ret = cclua::runtime::capture(arg1, (float)arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_obj(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_capture4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */
    lua_Number arg2 = 0;       /** width */
    lua_Number arg3 = 0;       /** height */
    lua_Number arg4 = 0;       /** scale */
    lua_Unsigned arg5 = 0;       /** format */

    olua_check_obj(L, 1, &arg1, "cc.Node");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_uint(L, 5, &arg5);

    // static cocos2d::Sprite *capture(cocos2d::Node *node, float width, float height, @optional float scale, @optional cocos2d::Texture2D::PixelFormat format, @optional GLuint depthStencilFormat)
    cocos2d::Sprite *ret = cclua::runtime::capture(arg1, (float)arg2, (float)arg3, (float)arg4, (cocos2d::Texture2D::PixelFormat)arg5);
    int num_ret = olua_push_obj(L, ret, "cc.Sprite");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_capture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_obj(L, 1, "cc.Node")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::Sprite *capture(cocos2d::Node *node, float width, float height, @optional float scale, @optional cocos2d::Texture2D::PixelFormat format, @optional GLuint depthStencilFormat)
            return _cclua_runtime_capture2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 1, "cc.Node")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // static cocos2d::Sprite *capture(cocos2d::Node *node, float width, float height, @optional float scale, @optional cocos2d::Texture2D::PixelFormat format, @optional GLuint depthStencilFormat)
            return _cclua_runtime_capture3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_obj(L, 1, "cc.Node")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_uint(L, 5))) {
            // static cocos2d::Sprite *capture(cocos2d::Node *node, float width, float height, @optional float scale, @optional cocos2d::Texture2D::PixelFormat format, @optional GLuint depthStencilFormat)
            return _cclua_runtime_capture4(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_obj(L, 1, "cc.Node")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_uint(L, 5)) && (olua_is_uint(L, 6))) {
            // static cocos2d::Sprite *capture(cocos2d::Node *node, float width, float height, @optional float scale, @optional cocos2d::Texture2D::PixelFormat format, @optional GLuint depthStencilFormat)
            return _cclua_runtime_capture1(L);
        // }
    }

    luaL_error(L, "method 'cclua::runtime::capture' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_runtime_clearStorage(lua_State *L)
{
    olua_startinvoke(L);

    // static void clearStorage()
    cclua::runtime::clearStorage();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_disableReport(lua_State *L)
{
    olua_startinvoke(L);

    // static void disableReport()
    cclua::runtime::disableReport();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_exit(lua_State *L)
{
    olua_startinvoke(L);

    // static void exit()
    cclua::runtime::exit();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_gc(lua_State *L)
{
    olua_startinvoke(L);

    // static void gc()
    cclua::runtime::gc();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_getActionManager(lua_State *L)
{
    olua_startinvoke(L);

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);

    // @addref(^ ::pushdirector) static cocos2d::ActionManager *getActionManager()
    cocos2d::ActionManager *ret = cclua::runtime::getActionManager();
    int num_ret = olua_push_obj(L, ret, "cc.ActionManager");

    // insert code after call
    olua_addref(L, ref_store, "actionmanager", -1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getAppBuild(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getAppBuild()
    std::string ret = cclua::runtime::getAppBuild();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getAppName(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getAppName()
    std::string ret = cclua::runtime::getAppName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getAppVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getAppVersion()
    std::string ret = cclua::runtime::getAppVersion();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getAudioSessionCatalog(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getAudioSessionCatalog()
    std::string ret = cclua::runtime::getAudioSessionCatalog();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getChannel(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getChannel()
    std::string ret = cclua::runtime::getChannel();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getCocosVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static uint64_t getCocosVersion()
    uint64_t ret = cclua::runtime::getCocosVersion();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getDeviceInfo(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getDeviceInfo()
    std::string ret = cclua::runtime::getDeviceInfo();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getEnv(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */

    olua_check_std_string(L, 1, &arg1);

    // static std::string getEnv(const std::string &key)
    std::string ret = cclua::runtime::getEnv(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getEventDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);

    // @addref(^ ::pushdirector) static cocos2d::EventDispatcher *getEventDispatcher()
    cocos2d::EventDispatcher *ret = cclua::runtime::getEventDispatcher();
    int num_ret = olua_push_obj(L, ret, "cc.EventDispatcher");

    // insert code after call
    olua_addref(L, ref_store, "eventdispatcher", -1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getFileUtils(lua_State *L)
{
    olua_startinvoke(L);

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);

    // @addref(^ ::pushdirector) static cocos2d::FileUtils *getFileUtils()
    cocos2d::FileUtils *ret = cclua::runtime::getFileUtils();
    int num_ret = olua_push_obj(L, ret, "cc.FileUtils");

    // insert code after call
    olua_addref(L, ref_store, "fileutils", -1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    // static uint32_t getFrameRate()
    uint32_t ret = cclua::runtime::getFrameRate();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getLanguage(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getLanguage()
    std::string ret = cclua::runtime::getLanguage();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getLogPath(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getLogPath()
    std::string ret = cclua::runtime::getLogPath();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getManifestVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getManifestVersion()
    std::string ret = cclua::runtime::getManifestVersion();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getMaxFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    // static uint32_t getMaxFrameRate()
    uint32_t ret = cclua::runtime::getMaxFrameRate();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getNetworkStatus(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getNetworkStatus()
    std::string ret = cclua::runtime::getNetworkStatus();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getOS(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getOS()
    std::string ret = cclua::runtime::getOS();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getPackageName(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getPackageName()
    std::string ret = cclua::runtime::getPackageName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getPaste(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getPaste()
    std::string ret = cclua::runtime::getPaste();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getPermission(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** permission */

    olua_check_std_string(L, 1, &arg1);

    // static std::string getPermission(const std::string &permission)
    std::string ret = cclua::runtime::getPermission(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getProgramCache(lua_State *L)
{
    olua_startinvoke(L);

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);

    // @addref(^ ::pushdirector) static cocos2d::GLProgramCache *getProgramCache()
    cocos2d::GLProgramCache *ret = cclua::runtime::getProgramCache();
    int num_ret = olua_push_obj(L, ret, "cc.GLProgramCache");

    // insert code after call
    olua_addref(L, ref_store, "programcache", -1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getRunningScene(lua_State *L)
{
    olua_startinvoke(L);

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);

    // @addref(scenes | ::pushdirector) static cocos2d::Scene *getRunningScene()
    cocos2d::Scene *ret = cclua::runtime::getRunningScene();
    int num_ret = olua_push_obj(L, ret, "cc.Scene");

    // insert code after call
    olua_addref(L, ref_store, "scenes", -1, OLUA_FLAG_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getSampleCount(lua_State *L)
{
    olua_startinvoke(L);

    // static unsigned int getSampleCount()
    unsigned int ret = cclua::runtime::getSampleCount();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getScheduler(lua_State *L)
{
    olua_startinvoke(L);

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);

    // @addref(^ ::pushdirector) static cocos2d::Scheduler *getScheduler()
    cocos2d::Scheduler *ret = cclua::runtime::getScheduler();
    int num_ret = olua_push_obj(L, ret, "cc.Scheduler");

    // insert code after call
    olua_addref(L, ref_store, "scheduler", -1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getSpriteFrameCache(lua_State *L)
{
    olua_startinvoke(L);

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);

    // @addref(^ ::pushdirector) static cocos2d::SpriteFrameCache *getSpriteFrameCache()
    cocos2d::SpriteFrameCache *ret = cclua::runtime::getSpriteFrameCache();
    int num_ret = olua_push_obj(L, ret, "cc.SpriteFrameCache");

    // insert code after call
    olua_addref(L, ref_store, "spriteframecache", -1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getTextureCache(lua_State *L)
{
    olua_startinvoke(L);

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);

    // @addref(^ ::pushdirector) static cocos2d::TextureCache *getTextureCache()
    cocos2d::TextureCache *ret = cclua::runtime::getTextureCache();
    int num_ret = olua_push_obj(L, ret, "cc.TextureCache");

    // insert code after call
    olua_addref(L, ref_store, "texturecache", -1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getTime(lua_State *L)
{
    olua_startinvoke(L);

    // static float getTime()
    float ret = cclua::runtime::getTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getVersion()
    std::string ret = cclua::runtime::getVersion();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_hasFeature(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** api */

    olua_check_std_string(L, 1, &arg1);

    // static bool hasFeature(const std::string &api)
    bool ret = cclua::runtime::hasFeature(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_installAPK(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static void installAPK(const std::string &path)
    cclua::runtime::installAPK(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_isDebug(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isDebug()
    bool ret = cclua::runtime::isDebug();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_isDisplayStats(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isDisplayStats()
    bool ret = cclua::runtime::isDisplayStats();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_isRestarting(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isRestarting()
    bool ret = cclua::runtime::isRestarting();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_launch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** scriptPath */

    olua_check_std_string(L, 1, &arg1);

    // static bool launch(const std::string &scriptPath)
    bool ret = cclua::runtime::launch(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_load1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg2;       /** name */

    olua_check_std_string(L, 1, &arg2);

    // static olua_Return load(lua_State *L, const std::string &name)
    olua_Return ret = cclua::runtime::load(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _cclua_runtime_load2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg2;       /** name */
    std::string arg3;       /** feature */

    olua_check_std_string(L, 1, &arg2);
    olua_check_std_string(L, 2, &arg3);

    // static olua_Return load(lua_State *L, const std::string &name, const std::string &feature)
    olua_Return ret = cclua::runtime::load(L, arg2, arg3);

    olua_endinvoke(L);

    return (int)ret;
}

static int _cclua_runtime_load(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static olua_Return load(lua_State *L, const std::string &name)
            return _cclua_runtime_load1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static olua_Return load(lua_State *L, const std::string &name, const std::string &feature)
            return _cclua_runtime_load2(L);
        // }
    }

    luaL_error(L, "method 'cclua::runtime::load' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_runtime_openURL1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uri */
    std::function<void(bool)> arg2;       /** callback */

    olua_check_std_string(L, 1, &arg1);
    olua_check_callback(L, 2, &arg2, "std.function");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.runtime");
    std::string cb_tag = "openURL";
    std::string cb_name;
    if (olua_is_callback(L, 2, "std.function")) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_NEW);
        olua_Context cb_ctx = olua_context(L);
        arg2 = [cb_store, cb_name, cb_ctx](bool arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                olua_push_bool(L, arg1);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

                lua_settop(L, top);
            }
        };
    } else {
        arg2 = nullptr;
    }

    // static void openURL(const std::string &uri, @localvar @optional const std::function<void (bool)> callback)
    cclua::runtime::openURL(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_openURL2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uri */

    olua_check_std_string(L, 1, &arg1);

    // static void openURL(const std::string &uri, @localvar @optional const std::function<void (bool)> callback)
    cclua::runtime::openURL(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_openURL(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void openURL(const std::string &uri, @localvar @optional const std::function<void (bool)> callback)
            return _cclua_runtime_openURL2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_callback(L, 2, "std.function"))) {
            // static void openURL(const std::string &uri, @localvar @optional const std::function<void (bool)> callback)
            return _cclua_runtime_openURL1(L);
        // }
    }

    luaL_error(L, "method 'cclua::runtime::openURL' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_runtime_popScene(lua_State *L)
{
    olua_startinvoke(L);

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);
    olua_startcmpref(L, ref_store, "scenes");

    // @delref(scenes ~ ::pushdirector) static void popScene()
    cclua::runtime::popScene();

    // insert code after call
    olua_endcmpref(L, ref_store, "scenes");

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_popToRootScene(lua_State *L)
{
    olua_startinvoke(L);

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);
    olua_startcmpref(L, ref_store, "scenes");

    // @delref(scenes ~ ::pushdirector) static void popToRootScene()
    cclua::runtime::popToRootScene();

    // insert code after call
    olua_endcmpref(L, ref_store, "scenes");

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_printFeatures(lua_State *L)
{
    olua_startinvoke(L);

    // static void printFeatures()
    cclua::runtime::printFeatures();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_purgeCachedData(lua_State *L)
{
    olua_startinvoke(L);

    // static void purgeCachedData()
    cclua::runtime::purgeCachedData();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_pushScene(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Scene *arg1 = nullptr;       /** scene */

    olua_check_obj(L, 1, &arg1, "cc.Scene");

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);

    // static void pushScene(@addref(scenes | ::pushdirector) cocos2d::Scene *scene)
    cclua::runtime::pushScene(arg1);

    // insert code after call
    olua_addref(L, ref_store, "scenes", 1, OLUA_FLAG_MULTIPLE);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_replaceScene(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Scene *arg1 = nullptr;       /** scene */

    olua_check_obj(L, 1, &arg1, "cc.Scene");

    // insert code before call
    int ref_store = cclua::runtime::pushdirector(L);
    olua_startcmpref(L, ref_store, "scenes");

    // @delref(scenes ~ ::pushdirector) static void replaceScene(@addref(scenes | ::pushdirector) cocos2d::Scene *scene)
    cclua::runtime::replaceScene(arg1);

    // insert code after call
    olua_addref(L, ref_store, "scenes", 1, OLUA_FLAG_MULTIPLE);
    olua_endcmpref(L, ref_store, "scenes");

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_requestPermission(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** permission */
    std::function<void(const std::string &)> arg2;       /** callback */

    olua_check_std_string(L, 1, &arg1);
    olua_check_callback(L, 2, &arg2, "std.function");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.runtime");
    std::string cb_tag = "requestPermission";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_NEW);
    olua_Context cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](const std::string &arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_std_string(L, arg1);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void requestPermission(const std::string &permission, @localvar const std::function<void (const std::string &)> &callback)
    cclua::runtime::requestPermission(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_restart(lua_State *L)
{
    olua_startinvoke(L);

    // static bool restart()
    bool ret = cclua::runtime::restart();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_setAudioSessionCatalog(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** catalog */

    olua_check_std_string(L, 1, &arg1);

    // static void setAudioSessionCatalog(const std::string &catalog)
    cclua::runtime::setAudioSessionCatalog(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Callback arg1;       /** dispatcher */

    olua_check_callback(L, 1, &arg1, "cclua.Callback");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.runtime");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const std::string &arg1, const cocos2d::Value &arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_std_string(L, arg1);
            olua_push_cocos2d_Value(L, &arg2);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void setDispatcher(@localvar const cclua::Callback &dispatcher)
    cclua::runtime::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setDisplayStats(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** displayStats */

    olua_check_bool(L, 1, &arg1);

    // static void setDisplayStats(bool displayStats)
    cclua::runtime::setDisplayStats(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setEnv1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    std::string arg2;       /** value */
    bool arg3 = false;       /** save */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_bool(L, 3, &arg3);

    // static void setEnv(const std::string &key, const std::string &value, @optional bool save)
    cclua::runtime::setEnv(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setEnv2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    std::string arg2;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void setEnv(const std::string &key, const std::string &value, @optional bool save)
    cclua::runtime::setEnv(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setEnv(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static void setEnv(const std::string &key, const std::string &value, @optional bool save)
            return _cclua_runtime_setEnv2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_bool(L, 3))) {
            // static void setEnv(const std::string &key, const std::string &value, @optional bool save)
            return _cclua_runtime_setEnv1(L);
        // }
    }

    luaL_error(L, "method 'cclua::runtime::setEnv' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_runtime_setFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** frameRate */

    olua_check_uint(L, 1, &arg1);

    // static void setFrameRate(uint32_t frameRate)
    cclua::runtime::setFrameRate((uint32_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setLogPath(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static void setLogPath(const std::string &path)
    cclua::runtime::setLogPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setManifestVersion(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** version */

    olua_check_std_string(L, 1, &arg1);

    // static void setManifestVersion(const std::string &version)
    cclua::runtime::setManifestVersion(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setPaste(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** text */

    olua_check_std_string(L, 1, &arg1);

    // static void setPaste(const std::string &text)
    cclua::runtime::setPaste(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setSampleCount(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** samples */

    olua_check_uint(L, 1, &arg1);

    // static void setSampleCount(unsigned int samples)
    cclua::runtime::setSampleCount((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_showLog(lua_State *L)
{
    olua_startinvoke(L);

    // static void showLog()
    cclua::runtime::showLog();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_testCrash(lua_State *L)
{
    olua_startinvoke(L);

    // static void testCrash()
    cclua::runtime::testCrash();

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_runtime(lua_State *L)
{
    oluacls_class(L, "cclua.runtime", nullptr);
    oluacls_func(L, "__olua_move", _cclua_runtime___olua_move);
    oluacls_func(L, "alert", _cclua_runtime_alert);
    oluacls_func(L, "canOpenURL", _cclua_runtime_canOpenURL);
    oluacls_func(L, "capture", _cclua_runtime_capture);
    oluacls_func(L, "clearStorage", _cclua_runtime_clearStorage);
    oluacls_func(L, "disableReport", _cclua_runtime_disableReport);
    oluacls_func(L, "exit", _cclua_runtime_exit);
    oluacls_func(L, "gc", _cclua_runtime_gc);
    oluacls_func(L, "getActionManager", _cclua_runtime_getActionManager);
    oluacls_func(L, "getAppBuild", _cclua_runtime_getAppBuild);
    oluacls_func(L, "getAppName", _cclua_runtime_getAppName);
    oluacls_func(L, "getAppVersion", _cclua_runtime_getAppVersion);
    oluacls_func(L, "getAudioSessionCatalog", _cclua_runtime_getAudioSessionCatalog);
    oluacls_func(L, "getChannel", _cclua_runtime_getChannel);
    oluacls_func(L, "getCocosVersion", _cclua_runtime_getCocosVersion);
    oluacls_func(L, "getDeviceInfo", _cclua_runtime_getDeviceInfo);
    oluacls_func(L, "getEnv", _cclua_runtime_getEnv);
    oluacls_func(L, "getEventDispatcher", _cclua_runtime_getEventDispatcher);
    oluacls_func(L, "getFileUtils", _cclua_runtime_getFileUtils);
    oluacls_func(L, "getFrameRate", _cclua_runtime_getFrameRate);
    oluacls_func(L, "getLanguage", _cclua_runtime_getLanguage);
    oluacls_func(L, "getLogPath", _cclua_runtime_getLogPath);
    oluacls_func(L, "getManifestVersion", _cclua_runtime_getManifestVersion);
    oluacls_func(L, "getMaxFrameRate", _cclua_runtime_getMaxFrameRate);
    oluacls_func(L, "getNetworkStatus", _cclua_runtime_getNetworkStatus);
    oluacls_func(L, "getOS", _cclua_runtime_getOS);
    oluacls_func(L, "getPackageName", _cclua_runtime_getPackageName);
    oluacls_func(L, "getPaste", _cclua_runtime_getPaste);
    oluacls_func(L, "getPermission", _cclua_runtime_getPermission);
    oluacls_func(L, "getProgramCache", _cclua_runtime_getProgramCache);
    oluacls_func(L, "getRunningScene", _cclua_runtime_getRunningScene);
    oluacls_func(L, "getSampleCount", _cclua_runtime_getSampleCount);
    oluacls_func(L, "getScheduler", _cclua_runtime_getScheduler);
    oluacls_func(L, "getSpriteFrameCache", _cclua_runtime_getSpriteFrameCache);
    oluacls_func(L, "getTextureCache", _cclua_runtime_getTextureCache);
    oluacls_func(L, "getTime", _cclua_runtime_getTime);
    oluacls_func(L, "getVersion", _cclua_runtime_getVersion);
    oluacls_func(L, "hasFeature", _cclua_runtime_hasFeature);
    oluacls_func(L, "installAPK", _cclua_runtime_installAPK);
    oluacls_func(L, "isDebug", _cclua_runtime_isDebug);
    oluacls_func(L, "isDisplayStats", _cclua_runtime_isDisplayStats);
    oluacls_func(L, "isRestarting", _cclua_runtime_isRestarting);
    oluacls_func(L, "launch", _cclua_runtime_launch);
    oluacls_func(L, "load", _cclua_runtime_load);
    oluacls_func(L, "openURL", _cclua_runtime_openURL);
    oluacls_func(L, "popScene", _cclua_runtime_popScene);
    oluacls_func(L, "popToRootScene", _cclua_runtime_popToRootScene);
    oluacls_func(L, "printFeatures", _cclua_runtime_printFeatures);
    oluacls_func(L, "purgeCachedData", _cclua_runtime_purgeCachedData);
    oluacls_func(L, "pushScene", _cclua_runtime_pushScene);
    oluacls_func(L, "replaceScene", _cclua_runtime_replaceScene);
    oluacls_func(L, "requestPermission", _cclua_runtime_requestPermission);
    oluacls_func(L, "restart", _cclua_runtime_restart);
    oluacls_func(L, "setAudioSessionCatalog", _cclua_runtime_setAudioSessionCatalog);
    oluacls_func(L, "setDispatcher", _cclua_runtime_setDispatcher);
    oluacls_func(L, "setDisplayStats", _cclua_runtime_setDisplayStats);
    oluacls_func(L, "setEnv", _cclua_runtime_setEnv);
    oluacls_func(L, "setFrameRate", _cclua_runtime_setFrameRate);
    oluacls_func(L, "setLogPath", _cclua_runtime_setLogPath);
    oluacls_func(L, "setManifestVersion", _cclua_runtime_setManifestVersion);
    oluacls_func(L, "setPaste", _cclua_runtime_setPaste);
    oluacls_func(L, "setSampleCount", _cclua_runtime_setSampleCount);
    oluacls_func(L, "showLog", _cclua_runtime_showLog);
    oluacls_func(L, "testCrash", _cclua_runtime_testCrash);
    oluacls_prop(L, "actionManager", _cclua_runtime_getActionManager, nullptr);
    oluacls_prop(L, "appBuild", _cclua_runtime_getAppBuild, nullptr);
    oluacls_prop(L, "appName", _cclua_runtime_getAppName, nullptr);
    oluacls_prop(L, "appVersion", _cclua_runtime_getAppVersion, nullptr);
    oluacls_prop(L, "audioSessionCatalog", _cclua_runtime_getAudioSessionCatalog, _cclua_runtime_setAudioSessionCatalog);
    oluacls_prop(L, "channel", _cclua_runtime_getChannel, nullptr);
    oluacls_prop(L, "cocosVersion", _cclua_runtime_getCocosVersion, nullptr);
    oluacls_prop(L, "debug", _cclua_runtime_isDebug, nullptr);
    oluacls_prop(L, "deviceInfo", _cclua_runtime_getDeviceInfo, nullptr);
    oluacls_prop(L, "displayStats", _cclua_runtime_isDisplayStats, _cclua_runtime_setDisplayStats);
    oluacls_prop(L, "eventDispatcher", _cclua_runtime_getEventDispatcher, nullptr);
    oluacls_prop(L, "fileUtils", _cclua_runtime_getFileUtils, nullptr);
    oluacls_prop(L, "frameRate", _cclua_runtime_getFrameRate, _cclua_runtime_setFrameRate);
    oluacls_prop(L, "language", _cclua_runtime_getLanguage, nullptr);
    oluacls_prop(L, "logPath", _cclua_runtime_getLogPath, _cclua_runtime_setLogPath);
    oluacls_prop(L, "manifestVersion", _cclua_runtime_getManifestVersion, _cclua_runtime_setManifestVersion);
    oluacls_prop(L, "maxFrameRate", _cclua_runtime_getMaxFrameRate, nullptr);
    oluacls_prop(L, "networkStatus", _cclua_runtime_getNetworkStatus, nullptr);
    oluacls_prop(L, "os", _cclua_runtime_getOS, nullptr);
    oluacls_prop(L, "packageName", _cclua_runtime_getPackageName, nullptr);
    oluacls_prop(L, "paste", _cclua_runtime_getPaste, _cclua_runtime_setPaste);
    oluacls_prop(L, "programCache", _cclua_runtime_getProgramCache, nullptr);
    oluacls_prop(L, "restarting", _cclua_runtime_isRestarting, nullptr);
    oluacls_prop(L, "runningScene", _cclua_runtime_getRunningScene, nullptr);
    oluacls_prop(L, "sampleCount", _cclua_runtime_getSampleCount, _cclua_runtime_setSampleCount);
    oluacls_prop(L, "scheduler", _cclua_runtime_getScheduler, nullptr);
    oluacls_prop(L, "spriteFrameCache", _cclua_runtime_getSpriteFrameCache, nullptr);
    oluacls_prop(L, "textureCache", _cclua_runtime_getTextureCache, nullptr);
    oluacls_prop(L, "time", _cclua_runtime_getTime, nullptr);
    oluacls_prop(L, "version", _cclua_runtime_getVersion, nullptr);

    olua_registerluatype<cclua::runtime>(L, "cclua.runtime");

    return 1;
}
OLUA_END_DECLS

static int _cclua_filesystem___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::filesystem *)olua_toobj(L, 1, "cclua.filesystem");
    olua_push_obj(L, self, "cclua.filesystem");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_filesystem_addSearchPath1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    bool arg2 = false;       /** front */

    olua_check_std_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static void addSearchPath(const std::string &path, @optional bool front)
    cclua::filesystem::addSearchPath(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_filesystem_addSearchPath2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static void addSearchPath(const std::string &path, @optional bool front)
    cclua::filesystem::addSearchPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_filesystem_addSearchPath(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void addSearchPath(const std::string &path, @optional bool front)
            return _cclua_filesystem_addSearchPath2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_bool(L, 2))) {
            // static void addSearchPath(const std::string &path, @optional bool front)
            return _cclua_filesystem_addSearchPath1(L);
        // }
    }

    luaL_error(L, "method 'cclua::filesystem::addSearchPath' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_filesystem_copy(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** srcPath */
    std::string arg2;       /** destPath */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static bool copy(const std::string &srcPath, const std::string &destPath)
    bool ret = cclua::filesystem::copy(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_createDirectory1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    bool arg2 = false;       /** isFilePath */

    olua_check_std_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static bool createDirectory(const std::string &path, @optional bool isFilePath)
    bool ret = cclua::filesystem::createDirectory(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_createDirectory2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool createDirectory(const std::string &path, @optional bool isFilePath)
    bool ret = cclua::filesystem::createDirectory(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_createDirectory(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static bool createDirectory(const std::string &path, @optional bool isFilePath)
            return _cclua_filesystem_createDirectory2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_bool(L, 2))) {
            // static bool createDirectory(const std::string &path, @optional bool isFilePath)
            return _cclua_filesystem_createDirectory1(L);
        // }
    }

    luaL_error(L, "method 'cclua::filesystem::createDirectory' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_filesystem_exist(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool exist(const std::string &path)
    bool ret = cclua::filesystem::exist(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_fullPath(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static std::string fullPath(const std::string &path)
    std::string ret = cclua::filesystem::fullPath(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getBuiltinCacheDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getBuiltinCacheDirectory()
    std::string ret = cclua::filesystem::getBuiltinCacheDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getCacheDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getCacheDirectory()
    std::string ret = cclua::filesystem::getCacheDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getDocumentDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getDocumentDirectory()
    std::string ret = cclua::filesystem::getDocumentDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getSDCardDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getSDCardDirectory()
    std::string ret = cclua::filesystem::getSDCardDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getTmpDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getTmpDirectory()
    std::string ret = cclua::filesystem::getTmpDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getWritablePath(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getWritablePath()
    std::string ret = cclua::filesystem::getWritablePath();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_isAbsolutePath(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool isAbsolutePath(const std::string &path)
    bool ret = cclua::filesystem::isAbsolutePath(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_isDirectory(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool isDirectory(const std::string &path)
    bool ret = cclua::filesystem::isDirectory(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_isFile(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool isFile(const std::string &path)
    bool ret = cclua::filesystem::isFile(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_read(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::Data read(const std::string &path)
    cocos2d::Data ret = cclua::filesystem::read(arg1);
    int num_ret = olua_push_cocos2d_Data(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_remove(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool remove(const std::string &path)
    bool ret = cclua::filesystem::remove(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_rename(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** oldPath */
    std::string arg2;       /** newPath */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static bool rename(const std::string &oldPath, const std::string &newPath)
    bool ret = cclua::filesystem::rename(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_trimPath1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    lua_Unsigned arg2 = 0;       /** limit */

    olua_check_std_string(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static std::string trimPath(const std::string &path, @optional size_t limit)
    std::string ret = cclua::filesystem::trimPath(arg1, (size_t)arg2);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_trimPath2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static std::string trimPath(const std::string &path, @optional size_t limit)
    std::string ret = cclua::filesystem::trimPath(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_trimPath(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static std::string trimPath(const std::string &path, @optional size_t limit)
            return _cclua_filesystem_trimPath2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_uint(L, 2))) {
            // static std::string trimPath(const std::string &path, @optional size_t limit)
            return _cclua_filesystem_trimPath1(L);
        // }
    }

    luaL_error(L, "method 'cclua::filesystem::trimPath' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_filesystem_unzip(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    std::string arg2;       /** dest */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static bool unzip(const std::string &path, const std::string &dest)
    bool ret = cclua::filesystem::unzip(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_write1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    const char *arg2 = nullptr;       /** data */
    lua_Unsigned arg3 = 0;       /** len */

    olua_check_std_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static bool write(const std::string &path, const char *data, size_t len)
    bool ret = cclua::filesystem::write(arg1, arg2, (size_t)arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_write2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    cocos2d::Data arg2;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_Data(L, 2, &arg2);

    // static bool write(const std::string &path, const cocos2d::Data &data)
    bool ret = cclua::filesystem::write(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_write(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_cocos2d_Data(L, 2))) {
            // static bool write(const std::string &path, const cocos2d::Data &data)
            return _cclua_filesystem_write2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_uint(L, 3))) {
            // static bool write(const std::string &path, const char *data, size_t len)
            return _cclua_filesystem_write1(L);
        // }
    }

    luaL_error(L, "method 'cclua::filesystem::write' not support '%d' arguments", num_args);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_filesystem(lua_State *L)
{
    oluacls_class(L, "cclua.filesystem", nullptr);
    oluacls_func(L, "__olua_move", _cclua_filesystem___olua_move);
    oluacls_func(L, "addSearchPath", _cclua_filesystem_addSearchPath);
    oluacls_func(L, "copy", _cclua_filesystem_copy);
    oluacls_func(L, "createDirectory", _cclua_filesystem_createDirectory);
    oluacls_func(L, "exist", _cclua_filesystem_exist);
    oluacls_func(L, "fullPath", _cclua_filesystem_fullPath);
    oluacls_func(L, "getBuiltinCacheDirectory", _cclua_filesystem_getBuiltinCacheDirectory);
    oluacls_func(L, "getCacheDirectory", _cclua_filesystem_getCacheDirectory);
    oluacls_func(L, "getDocumentDirectory", _cclua_filesystem_getDocumentDirectory);
    oluacls_func(L, "getSDCardDirectory", _cclua_filesystem_getSDCardDirectory);
    oluacls_func(L, "getTmpDirectory", _cclua_filesystem_getTmpDirectory);
    oluacls_func(L, "getWritablePath", _cclua_filesystem_getWritablePath);
    oluacls_func(L, "isAbsolutePath", _cclua_filesystem_isAbsolutePath);
    oluacls_func(L, "isDirectory", _cclua_filesystem_isDirectory);
    oluacls_func(L, "isFile", _cclua_filesystem_isFile);
    oluacls_func(L, "read", _cclua_filesystem_read);
    oluacls_func(L, "remove", _cclua_filesystem_remove);
    oluacls_func(L, "rename", _cclua_filesystem_rename);
    oluacls_func(L, "trimPath", _cclua_filesystem_trimPath);
    oluacls_func(L, "unzip", _cclua_filesystem_unzip);
    oluacls_func(L, "write", _cclua_filesystem_write);
    oluacls_prop(L, "builtinCacheDirectory", _cclua_filesystem_getBuiltinCacheDirectory, nullptr);
    oluacls_prop(L, "cacheDirectory", _cclua_filesystem_getCacheDirectory, nullptr);
    oluacls_prop(L, "documentDirectory", _cclua_filesystem_getDocumentDirectory, nullptr);
    oluacls_prop(L, "sdCardDirectory", _cclua_filesystem_getSDCardDirectory, nullptr);
    oluacls_prop(L, "tmpDirectory", _cclua_filesystem_getTmpDirectory, nullptr);
    oluacls_prop(L, "writablePath", _cclua_filesystem_getWritablePath, nullptr);

    olua_registerluatype<cclua::filesystem>(L, "cclua.filesystem");

    return 1;
}
OLUA_END_DECLS

static int _cclua_preferences___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::preferences *)olua_toobj(L, 1, "cclua.preferences");
    olua_push_obj(L, self, "cclua.preferences");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_preferences_deleteKey(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */

    olua_check_std_string(L, 1, &arg1);

    // static void deleteKey(const std::string &key)
    cclua::preferences::deleteKey(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_flush(lua_State *L)
{
    olua_startinvoke(L);

    // static void flush()
    cclua::preferences::flush();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_getBoolean1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    bool arg2 = false;       /** defaultValue */

    olua_check_std_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static bool getBoolean(const std::string &key, @optional bool defaultValue)
    bool ret = cclua::preferences::getBoolean(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getBoolean2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */

    olua_check_std_string(L, 1, &arg1);

    // static bool getBoolean(const std::string &key, @optional bool defaultValue)
    bool ret = cclua::preferences::getBoolean(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getBoolean(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static bool getBoolean(const std::string &key, @optional bool defaultValue)
            return _cclua_preferences_getBoolean2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_bool(L, 2))) {
            // static bool getBoolean(const std::string &key, @optional bool defaultValue)
            return _cclua_preferences_getBoolean1(L);
        // }
    }

    luaL_error(L, "method 'cclua::preferences::getBoolean' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_preferences_getDouble1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    lua_Number arg2 = 0;       /** defaultValue */

    olua_check_std_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static double getDouble(const std::string &key, @optional double defaultValue)
    double ret = cclua::preferences::getDouble(arg1, (double)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getDouble2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */

    olua_check_std_string(L, 1, &arg1);

    // static double getDouble(const std::string &key, @optional double defaultValue)
    double ret = cclua::preferences::getDouble(arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getDouble(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static double getDouble(const std::string &key, @optional double defaultValue)
            return _cclua_preferences_getDouble2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_number(L, 2))) {
            // static double getDouble(const std::string &key, @optional double defaultValue)
            return _cclua_preferences_getDouble1(L);
        // }
    }

    luaL_error(L, "method 'cclua::preferences::getDouble' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_preferences_getFloat1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    lua_Number arg2 = 0;       /** defaultValue */

    olua_check_std_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float getFloat(const std::string &key, @optional float defaultValue)
    float ret = cclua::preferences::getFloat(arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getFloat2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */

    olua_check_std_string(L, 1, &arg1);

    // static float getFloat(const std::string &key, @optional float defaultValue)
    float ret = cclua::preferences::getFloat(arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getFloat(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static float getFloat(const std::string &key, @optional float defaultValue)
            return _cclua_preferences_getFloat2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_number(L, 2))) {
            // static float getFloat(const std::string &key, @optional float defaultValue)
            return _cclua_preferences_getFloat1(L);
        // }
    }

    luaL_error(L, "method 'cclua::preferences::getFloat' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_preferences_getInteger1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    lua_Integer arg2 = 0;       /** defaultValue */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);

    // static int getInteger(const std::string &key, @optional int defaultValue)
    int ret = cclua::preferences::getInteger(arg1, (int)arg2);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getInteger2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */

    olua_check_std_string(L, 1, &arg1);

    // static int getInteger(const std::string &key, @optional int defaultValue)
    int ret = cclua::preferences::getInteger(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getInteger(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static int getInteger(const std::string &key, @optional int defaultValue)
            return _cclua_preferences_getInteger2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_int(L, 2))) {
            // static int getInteger(const std::string &key, @optional int defaultValue)
            return _cclua_preferences_getInteger1(L);
        // }
    }

    luaL_error(L, "method 'cclua::preferences::getInteger' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_preferences_getString1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    std::string arg2;       /** defaultValue */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static std::string getString(const std::string &key, @optional const std::string &defaultValue)
    std::string ret = cclua::preferences::getString(arg1, arg2);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getString2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */

    olua_check_std_string(L, 1, &arg1);

    // static std::string getString(const std::string &key, @optional const std::string &defaultValue)
    std::string ret = cclua::preferences::getString(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getString(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static std::string getString(const std::string &key, @optional const std::string &defaultValue)
            return _cclua_preferences_getString2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static std::string getString(const std::string &key, @optional const std::string &defaultValue)
            return _cclua_preferences_getString1(L);
        // }
    }

    luaL_error(L, "method 'cclua::preferences::getString' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_preferences_setBoolean(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    bool arg2 = false;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static void setBoolean(const std::string &key, bool value)
    cclua::preferences::setBoolean(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_setDouble(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    lua_Number arg2 = 0;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static void setDouble(const std::string &key, double value)
    cclua::preferences::setDouble(arg1, (double)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_setFloat(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    lua_Number arg2 = 0;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static void setFloat(const std::string &key, float value)
    cclua::preferences::setFloat(arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_setInteger(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    lua_Integer arg2 = 0;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);

    // static void setInteger(const std::string &key, int value)
    cclua::preferences::setInteger(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_setString(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    std::string arg2;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void setString(const std::string &key, const std::string &value)
    cclua::preferences::setString(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_preferences(lua_State *L)
{
    oluacls_class(L, "cclua.preferences", nullptr);
    oluacls_func(L, "__olua_move", _cclua_preferences___olua_move);
    oluacls_func(L, "deleteKey", _cclua_preferences_deleteKey);
    oluacls_func(L, "flush", _cclua_preferences_flush);
    oluacls_func(L, "getBoolean", _cclua_preferences_getBoolean);
    oluacls_func(L, "getDouble", _cclua_preferences_getDouble);
    oluacls_func(L, "getFloat", _cclua_preferences_getFloat);
    oluacls_func(L, "getInteger", _cclua_preferences_getInteger);
    oluacls_func(L, "getString", _cclua_preferences_getString);
    oluacls_func(L, "setBoolean", _cclua_preferences_setBoolean);
    oluacls_func(L, "setDouble", _cclua_preferences_setDouble);
    oluacls_func(L, "setFloat", _cclua_preferences_setFloat);
    oluacls_func(L, "setInteger", _cclua_preferences_setInteger);
    oluacls_func(L, "setString", _cclua_preferences_setString);

    olua_registerluatype<cclua::preferences>(L, "cclua.preferences");

    return 1;
}
OLUA_END_DECLS

static int _cclua_timer___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::timer *)olua_toobj(L, 1, "cclua.timer");
    olua_push_obj(L, self, "cclua.timer");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_timer_createTag(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string createTag()
    std::string ret = cclua::timer::createTag();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_timer_delay(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    std::function<void()> arg2;       /** callback */

    olua_check_number(L, 1, &arg1);
    olua_check_callback(L, 2, &arg2, "std.function");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.timer");
    std::string cb_tag = "delay";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_NEW);
    olua_Context cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx]() {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);

            olua_callback(L, cb_store, cb_name.c_str(), 0);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void delay(float time, @localvar const std::function<void ()> callback)
    cclua::timer::delay((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_timer_delayWithTag(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    std::string arg2;       /** tag */
    std::function<void()> arg3;       /** callback */

    olua_check_number(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_callback(L, 3, &arg3, "std.function");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.timer");
    std::string cb_tag = (arg2);
    std::string cb_name = olua_setcallback(L, cb_store,  3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg3 = [cb_store, cb_name, cb_ctx]() {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);

            olua_callback(L, cb_store, cb_name.c_str(), 0);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void delayWithTag(float time, const std::string &tag, @localvar std::function<void ()> callback)
    cclua::timer::delayWithTag((float)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_timer_killDelay(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** tag */

    olua_check_std_string(L, 1, &arg1);

    std::string cb_tag = (arg1);
    void *cb_store = (void *)olua_pushclassobj(L, "cclua.timer");
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // static void killDelay(const std::string &tag)
    cclua::timer::killDelay(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_timer_schedule(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** interval */
    std::string arg2;       /** tag */
    std::function<void(float)> arg3;       /** callback */

    olua_check_number(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_callback(L, 3, &arg3, "std.function");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.timer");
    std::string cb_tag = (arg2);
    std::string cb_name = olua_setcallback(L, cb_store,  3, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg3 = [cb_store, cb_name, cb_ctx](float arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_number(L, (lua_Number)arg1);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // static void schedule(float interval, const std::string &tag, @localvar const std::function<void (float)> callback)
    cclua::timer::schedule((float)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_timer_unschedule(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** tag */

    olua_check_std_string(L, 1, &arg1);

    std::string cb_tag = (arg1);
    void *cb_store = (void *)olua_pushclassobj(L, "cclua.timer");
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // static void unschedule(const std::string &tag)
    cclua::timer::unschedule(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_timer(lua_State *L)
{
    oluacls_class(L, "cclua.timer", nullptr);
    oluacls_func(L, "__olua_move", _cclua_timer___olua_move);
    oluacls_func(L, "createTag", _cclua_timer_createTag);
    oluacls_func(L, "delay", _cclua_timer_delay);
    oluacls_func(L, "delayWithTag", _cclua_timer_delayWithTag);
    oluacls_func(L, "killDelay", _cclua_timer_killDelay);
    oluacls_func(L, "schedule", _cclua_timer_schedule);
    oluacls_func(L, "unschedule", _cclua_timer_unschedule);

    olua_registerluatype<cclua::timer>(L, "cclua.timer");

    return 1;
}
OLUA_END_DECLS

static int _cclua_window___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::window *)olua_toobj(L, 1, "cclua.window");
    olua_push_obj(L, self, "cclua.window");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_window_convertToCameraSpace1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** position */

    olua_check_cocos2d_Vec2(L, 1, &arg1);

    // static cocos2d::Vec2 convertToCameraSpace(const cocos2d::Vec2 &position)
    cocos2d::Vec2 ret = cclua::window::convertToCameraSpace(arg1);
    int num_ret = olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_convertToCameraSpace2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** position */

    olua_pack_cocos2d_Vec2(L, 1, &arg1);

    // static cocos2d::Vec2 convertToCameraSpace(@pack const cocos2d::Vec2 &position)
    cocos2d::Vec2 ret = cclua::window::convertToCameraSpace(arg1);
    int num_ret = olua_unpack_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_convertToCameraSpace(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cocos2d_Vec2(L, 1))) {
            // static cocos2d::Vec2 convertToCameraSpace(const cocos2d::Vec2 &position)
            return _cclua_window_convertToCameraSpace1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_canpack_cocos2d_Vec2(L, 1))) {
            // static cocos2d::Vec2 convertToCameraSpace(@pack const cocos2d::Vec2 &position)
            return _cclua_window_convertToCameraSpace2(L);
        // }
    }

    luaL_error(L, "method 'cclua::window::convertToCameraSpace' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_window_getDesignSize(lua_State *L)
{
    olua_startinvoke(L);

    // @unpack static cocos2d::Size getDesignSize()
    cocos2d::Size ret = cclua::window::getDesignSize();
    int num_ret = olua_unpack_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_getFrameSize(lua_State *L)
{
    olua_startinvoke(L);

    // @unpack static cocos2d::Size getFrameSize()
    cocos2d::Size ret = cclua::window::getFrameSize();
    int num_ret = olua_unpack_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_getVisibleBounds(lua_State *L)
{
    olua_startinvoke(L);

    // @unpack static cocos2d::Bounds getVisibleBounds()
    cocos2d::Bounds ret = cclua::window::getVisibleBounds();
    int num_ret = olua_unpack_cocos2d_Bounds(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_getVisibleSize(lua_State *L)
{
    olua_startinvoke(L);

    // @unpack static cocos2d::Size getVisibleSize()
    cocos2d::Size ret = cclua::window::getVisibleSize();
    int num_ret = olua_unpack_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_setDesignSize1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    lua_Unsigned arg2 = 0;       /** resolutionPolicy */

    olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static void setDesignSize(const cocos2d::Size &size, ResolutionPolicy resolutionPolicy)
    cclua::window::setDesignSize(arg1, (ResolutionPolicy)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_window_setDesignSize2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    lua_Unsigned arg2 = 0;       /** resolutionPolicy */

    olua_pack_cocos2d_Size(L, 1, &arg1);
    olua_check_uint(L, 3, &arg2);

    // static void setDesignSize(@pack const cocos2d::Size &size, ResolutionPolicy resolutionPolicy)
    cclua::window::setDesignSize(arg1, (ResolutionPolicy)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_window_setDesignSize(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_cocos2d_Size(L, 1)) && (olua_is_uint(L, 2))) {
            // static void setDesignSize(const cocos2d::Size &size, ResolutionPolicy resolutionPolicy)
            return _cclua_window_setDesignSize1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_canpack_cocos2d_Size(L, 1)) && (olua_is_uint(L, 3))) {
            // static void setDesignSize(@pack const cocos2d::Size &size, ResolutionPolicy resolutionPolicy)
            return _cclua_window_setDesignSize2(L);
        // }
    }

    luaL_error(L, "method 'cclua::window::setDesignSize' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_window_setFrameSize1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    olua_check_cocos2d_Size(L, 1, &arg1);

    // static void setFrameSize(const cocos2d::Size &size)
    cclua::window::setFrameSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_window_setFrameSize2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    olua_pack_cocos2d_Size(L, 1, &arg1);

    // static void setFrameSize(@pack const cocos2d::Size &size)
    cclua::window::setFrameSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_window_setFrameSize(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cocos2d_Size(L, 1))) {
            // static void setFrameSize(const cocos2d::Size &size)
            return _cclua_window_setFrameSize1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_canpack_cocos2d_Size(L, 1))) {
            // static void setFrameSize(@pack const cocos2d::Size &size)
            return _cclua_window_setFrameSize2(L);
        // }
    }

    luaL_error(L, "method 'cclua::window::setFrameSize' not support '%d' arguments", num_args);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_window(lua_State *L)
{
    oluacls_class(L, "cclua.window", nullptr);
    oluacls_func(L, "__olua_move", _cclua_window___olua_move);
    oluacls_func(L, "convertToCameraSpace", _cclua_window_convertToCameraSpace);
    oluacls_func(L, "getDesignSize", _cclua_window_getDesignSize);
    oluacls_func(L, "getFrameSize", _cclua_window_getFrameSize);
    oluacls_func(L, "getVisibleBounds", _cclua_window_getVisibleBounds);
    oluacls_func(L, "getVisibleSize", _cclua_window_getVisibleSize);
    oluacls_func(L, "setDesignSize", _cclua_window_setDesignSize);
    oluacls_func(L, "setFrameSize", _cclua_window_setFrameSize);
    oluacls_prop(L, "frameSize", _cclua_window_getFrameSize, _cclua_window_setFrameSize);
    oluacls_prop(L, "visibleBounds", _cclua_window_getVisibleBounds, nullptr);
    oluacls_prop(L, "visibleSize", _cclua_window_getVisibleSize, nullptr);

    olua_registerluatype<cclua::window>(L, "cclua.window");

    return 1;
}
OLUA_END_DECLS

static int _cclua_downloader___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::downloader *)olua_toobj(L, 1, "cclua.downloader");
    olua_push_obj(L, self, "cclua.downloader");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_downloader_end(lua_State *L)
{
    olua_startinvoke(L);

    // static void end()
    cclua::downloader::end();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_downloader_init(lua_State *L)
{
    olua_startinvoke(L);

    // static void init()
    cclua::downloader::init();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_downloader_load1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uri */
    std::string arg2;       /** path */
    std::string arg3;       /** md5 */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);

    // static void load(const std::string &uri, const std::string &path, @optional const std::string &md5)
    cclua::downloader::load(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_downloader_load2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uri */
    std::string arg2;       /** path */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void load(const std::string &uri, const std::string &path, @optional const std::string &md5)
    cclua::downloader::load(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_downloader_load(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static void load(const std::string &uri, const std::string &path, @optional const std::string &md5)
            return _cclua_downloader_load2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // static void load(const std::string &uri, const std::string &path, @optional const std::string &md5)
            return _cclua_downloader_load1(L);
        // }
    }

    luaL_error(L, "method 'cclua::downloader::load' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_downloader_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Callback arg1;       /** dispatcher */

    olua_check_callback(L, 1, &arg1, "cclua.Callback");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.downloader");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const std::string &arg1, const cocos2d::Value &arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_std_string(L, arg1);
            olua_push_cocos2d_Value(L, &arg2);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void setDispatcher(@localvar const cclua::Callback &dispatcher)
    cclua::downloader::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_downloader_setURIResolver(lua_State *L)
{
    olua_startinvoke(L);

    std::function<std::string(const std::string &)> arg1;       /** resolver */

    olua_check_callback(L, 1, &arg1, "std.function");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.downloader");
    std::string cb_tag = "URIResolver";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const std::string &arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();
        std::string ret;       
        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_std_string(L, arg1);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            if (olua_is_std_string(L, -1)) {
                olua_check_std_string(L, -1, &ret);
            }

            lua_settop(L, top);
        }
        return (std::string)ret;
    };

    // static void setURIResolver(@localvar const std::function<std::string (const std::string &)> &resolver)
    cclua::downloader::setURIResolver(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_downloader(lua_State *L)
{
    oluacls_class(L, "cclua.downloader", nullptr);
    oluacls_func(L, "__olua_move", _cclua_downloader___olua_move);
    oluacls_func(L, "end", _cclua_downloader_end);
    oluacls_func(L, "init", _cclua_downloader_init);
    oluacls_func(L, "load", _cclua_downloader_load);
    oluacls_func(L, "setDispatcher", _cclua_downloader_setDispatcher);
    oluacls_func(L, "setURIResolver", _cclua_downloader_setURIResolver);

    olua_registerluatype<cclua::downloader>(L, "cclua.downloader");

    return 1;
}
OLUA_END_DECLS

static int _cclua_Container___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::Container *)olua_toobj(L, 1, "cclua.Container");
    olua_push_obj(L, self, "cclua.Container");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_Container_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cclua::Container *create()
    cclua::Container *ret = cclua::Container::create();
    int num_ret = olua_push_obj(L, ret, "cclua.Container");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_Container_getClippingNode(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Container *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.Container");

    // cocos2d::DrawNode *getClippingNode()
    cocos2d::DrawNode *ret = self->getClippingNode();
    int num_ret = olua_push_obj(L, ret, "cc.DrawNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_Container_getFilter(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Container *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.Container");

    // @addref(^) cocos2d::Node *getFilter()
    cocos2d::Node *ret = self->getFilter();
    int num_ret = olua_push_obj(L, ret, "cc.Node");

    // insert code after call
    olua_addref(L, 1, "filter", -1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_Container_new(lua_State *L)
{
    olua_startinvoke(L);

    // Container()
    cclua::Container *ret = new cclua::Container();
    int num_ret = olua_push_obj(L, ret, "cclua.Container");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_Container_setFilter(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Container *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** value */

    olua_to_obj(L, 1, &self, "cclua.Container");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_obj(L, 2, &arg1, "cc.Node");
    }

    // void setFilter(@nullable @addref(^) cocos2d::Node *value)
    self->setFilter(arg1);

    // insert code after call
    olua_addref(L, 1, "filter", 2, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_Container(lua_State *L)
{
    oluacls_class(L, "cclua.Container", "ccui.Layout");
    oluacls_func(L, "__olua_move", _cclua_Container___olua_move);
    oluacls_func(L, "create", _cclua_Container_create);
    oluacls_func(L, "getClippingNode", _cclua_Container_getClippingNode);
    oluacls_func(L, "getFilter", _cclua_Container_getFilter);
    oluacls_func(L, "new", _cclua_Container_new);
    oluacls_func(L, "setFilter", _cclua_Container_setFilter);
    oluacls_prop(L, "clippingNode", _cclua_Container_getClippingNode, nullptr);
    oluacls_prop(L, "filter", _cclua_Container_getFilter, _cclua_Container_setFilter);

    olua_registerluatype<cclua::Container>(L, "cclua.Container");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_XMLHttpRequest_ResponseType(lua_State *L)
{
    oluacls_class(L, "cclua.XMLHttpRequest.ResponseType", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "ARRAY_BUFFER", (lua_Integer)cclua::XMLHttpRequest::ResponseType::ARRAY_BUFFER);
    oluacls_const_integer(L, "BLOB", (lua_Integer)cclua::XMLHttpRequest::ResponseType::BLOB);
    oluacls_const_integer(L, "DOCUMENT", (lua_Integer)cclua::XMLHttpRequest::ResponseType::DOCUMENT);
    oluacls_const_integer(L, "JSON", (lua_Integer)cclua::XMLHttpRequest::ResponseType::JSON);
    oluacls_const_integer(L, "STRING", (lua_Integer)cclua::XMLHttpRequest::ResponseType::STRING);

    olua_registerluatype<cclua::XMLHttpRequest::ResponseType>(L, "cclua.XMLHttpRequest.ResponseType");

    return 1;
}
OLUA_END_DECLS

static int _cclua_XMLHttpRequest___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::XMLHttpRequest *)olua_toobj(L, 1, "cclua.XMLHttpRequest");
    olua_push_obj(L, self, "cclua.XMLHttpRequest");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_XMLHttpRequest_abort(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // void abort()
    self->abort();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_XMLHttpRequest_getAllResponseHeaders(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // const std::unordered_map<std::string, std::string> &getAllResponseHeaders()
    const std::unordered_map<std::string, std::string> &ret = self->getAllResponseHeaders();
    int num_ret = olua_push_map<std::string, std::string>(L, &ret, [L](std::string &arg1, std::string &arg2) {
        olua_push_std_string(L, (std::string)arg1);
        olua_push_std_string(L, (std::string)arg2);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getDataSize(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // size_t getDataSize()
    size_t ret = self->getDataSize();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getDataStr(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // const std::string &getDataStr()
    const std::string &ret = self->getDataStr();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getErrorFlag(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // bool getErrorFlag()
    bool ret = self->getErrorFlag();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getReadyState(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // int getReadyState()
    int ret = self->getReadyState();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getResponse(lua_State *L)
{
    olua_startinvoke(L);

    // @extend(cclua::XMLHttpRequest::Extend) static olua_Return getResponse(lua_State *L)
    olua_Return ret = cclua::XMLHttpRequest::Extend::getResponse(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _cclua_XMLHttpRequest_getResponseHeader(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;
    std::string arg1;       /** name */

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");
    olua_check_std_string(L, 2, &arg1);

    // const char *getResponseHeader(const std::string &name)
    const char *ret = self->getResponseHeader(arg1);
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getResponseType(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // cclua::XMLHttpRequest::ResponseType getResponseType()
    cclua::XMLHttpRequest::ResponseType ret = self->getResponseType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getResponseURL(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // const std::string &getResponseURL()
    const std::string &ret = self->getResponseURL();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getStatus(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // int getStatus()
    int ret = self->getStatus();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getStatusText(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // const std::string &getStatusText()
    const std::string &ret = self->getStatusText();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getTimeout(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // unsigned int getTimeout()
    unsigned int ret = self->getTimeout();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getURL(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // const std::string &getURL()
    const std::string &ret = self->getURL();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_getWithCredentials(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // bool getWithCredentials()
    bool ret = self->getWithCredentials();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_isAborted(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // bool isAborted()
    bool ret = self->isAborted();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_new(lua_State *L)
{
    olua_startinvoke(L);

    // XMLHttpRequest()
    cclua::XMLHttpRequest *ret = new cclua::XMLHttpRequest();
    int num_ret = olua_push_obj(L, ret, "cclua.XMLHttpRequest");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_XMLHttpRequest_open(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;
    std::string arg1;       /** method */
    std::string arg2;       /** url */

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void open(const std::string &method, const std::string &url)
    self->open(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_XMLHttpRequest_send1(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;
    cocos2d::Data arg1;       /** data */

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");
    olua_check_cocos2d_Data(L, 2, &arg1);

    // void send(const cocos2d::Data &data)
    self->send(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_XMLHttpRequest_send2(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");

    // void send()
    self->send();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_XMLHttpRequest_send(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void send()
        return _cclua_XMLHttpRequest_send2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_cocos2d_Data(L, 2))) {
            // void send(const cocos2d::Data &data)
            return _cclua_XMLHttpRequest_send1(L);
        // }
    }

    luaL_error(L, "method 'cclua::XMLHttpRequest::send' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_XMLHttpRequest_setErrorFlag(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;
    bool arg1 = false;       /** errorFlag */

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");
    olua_check_bool(L, 2, &arg1);

    // void setErrorFlag(bool errorFlag)
    self->setErrorFlag(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_XMLHttpRequest_setRequestHeader(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;
    std::string arg1;       /** name */
    std::string arg2;       /** value */

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void setRequestHeader(const std::string &name, const std::string &value)
    self->setRequestHeader(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_XMLHttpRequest_setResponseCallback(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;
    std::function<void(int)> arg1;       /** handler */

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");
    olua_check_callback(L, 2, &arg1, "std.function");

    void *cb_store = (void *)self;
    std::string cb_tag = "ResponseCallback";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](int arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_int(L, (lua_Integer)arg1);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // void setResponseCallback(@localvar std::function<void (int)> handler)
    self->setResponseCallback(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_XMLHttpRequest_setResponseType(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");
    olua_check_uint(L, 2, &arg1);

    // void setResponseType(cclua::XMLHttpRequest::ResponseType value)
    self->setResponseType((cclua::XMLHttpRequest::ResponseType)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_XMLHttpRequest_setTimeout(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");
    olua_check_uint(L, 2, &arg1);

    // void setTimeout(unsigned int value)
    self->setTimeout((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_XMLHttpRequest_setWithCredentials(lua_State *L)
{
    olua_startinvoke(L);

    cclua::XMLHttpRequest *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_obj(L, 1, &self, "cclua.XMLHttpRequest");
    olua_check_bool(L, 2, &arg1);

    // void setWithCredentials(bool value)
    self->setWithCredentials(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_XMLHttpRequest(lua_State *L)
{
    oluacls_class(L, "cclua.XMLHttpRequest", "cc.Ref");
    oluacls_func(L, "__olua_move", _cclua_XMLHttpRequest___olua_move);
    oluacls_func(L, "abort", _cclua_XMLHttpRequest_abort);
    oluacls_func(L, "getAllResponseHeaders", _cclua_XMLHttpRequest_getAllResponseHeaders);
    oluacls_func(L, "getDataSize", _cclua_XMLHttpRequest_getDataSize);
    oluacls_func(L, "getDataStr", _cclua_XMLHttpRequest_getDataStr);
    oluacls_func(L, "getErrorFlag", _cclua_XMLHttpRequest_getErrorFlag);
    oluacls_func(L, "getReadyState", _cclua_XMLHttpRequest_getReadyState);
    oluacls_func(L, "getResponse", _cclua_XMLHttpRequest_getResponse);
    oluacls_func(L, "getResponseHeader", _cclua_XMLHttpRequest_getResponseHeader);
    oluacls_func(L, "getResponseType", _cclua_XMLHttpRequest_getResponseType);
    oluacls_func(L, "getResponseURL", _cclua_XMLHttpRequest_getResponseURL);
    oluacls_func(L, "getStatus", _cclua_XMLHttpRequest_getStatus);
    oluacls_func(L, "getStatusText", _cclua_XMLHttpRequest_getStatusText);
    oluacls_func(L, "getTimeout", _cclua_XMLHttpRequest_getTimeout);
    oluacls_func(L, "getURL", _cclua_XMLHttpRequest_getURL);
    oluacls_func(L, "getWithCredentials", _cclua_XMLHttpRequest_getWithCredentials);
    oluacls_func(L, "isAborted", _cclua_XMLHttpRequest_isAborted);
    oluacls_func(L, "new", _cclua_XMLHttpRequest_new);
    oluacls_func(L, "open", _cclua_XMLHttpRequest_open);
    oluacls_func(L, "send", _cclua_XMLHttpRequest_send);
    oluacls_func(L, "setErrorFlag", _cclua_XMLHttpRequest_setErrorFlag);
    oluacls_func(L, "setRequestHeader", _cclua_XMLHttpRequest_setRequestHeader);
    oluacls_func(L, "setResponseCallback", _cclua_XMLHttpRequest_setResponseCallback);
    oluacls_func(L, "setResponseType", _cclua_XMLHttpRequest_setResponseType);
    oluacls_func(L, "setTimeout", _cclua_XMLHttpRequest_setTimeout);
    oluacls_func(L, "setWithCredentials", _cclua_XMLHttpRequest_setWithCredentials);
    oluacls_prop(L, "aborted", _cclua_XMLHttpRequest_isAborted, nullptr);
    oluacls_prop(L, "allResponseHeaders", _cclua_XMLHttpRequest_getAllResponseHeaders, nullptr);
    oluacls_prop(L, "dataSize", _cclua_XMLHttpRequest_getDataSize, nullptr);
    oluacls_prop(L, "dataStr", _cclua_XMLHttpRequest_getDataStr, nullptr);
    oluacls_prop(L, "errorFlag", _cclua_XMLHttpRequest_getErrorFlag, _cclua_XMLHttpRequest_setErrorFlag);
    oluacls_prop(L, "readyState", _cclua_XMLHttpRequest_getReadyState, nullptr);
    oluacls_prop(L, "response", _cclua_XMLHttpRequest_getResponse, nullptr);
    oluacls_prop(L, "responseType", _cclua_XMLHttpRequest_getResponseType, _cclua_XMLHttpRequest_setResponseType);
    oluacls_prop(L, "responseURL", _cclua_XMLHttpRequest_getResponseURL, nullptr);
    oluacls_prop(L, "status", _cclua_XMLHttpRequest_getStatus, nullptr);
    oluacls_prop(L, "statusText", _cclua_XMLHttpRequest_getStatusText, nullptr);
    oluacls_prop(L, "timeout", _cclua_XMLHttpRequest_getTimeout, _cclua_XMLHttpRequest_setTimeout);
    oluacls_prop(L, "url", _cclua_XMLHttpRequest_getURL, nullptr);
    oluacls_prop(L, "withCredentials", _cclua_XMLHttpRequest_getWithCredentials, _cclua_XMLHttpRequest_setWithCredentials);
    oluacls_const_integer(L, "DONE", (lua_Unsigned)cclua::XMLHttpRequest::DONE);
    oluacls_const_integer(L, "HEADERS_RECEIVED", (lua_Unsigned)cclua::XMLHttpRequest::HEADERS_RECEIVED);
    oluacls_const_integer(L, "LOADING", (lua_Unsigned)cclua::XMLHttpRequest::LOADING);
    oluacls_const_integer(L, "OPENED", (lua_Unsigned)cclua::XMLHttpRequest::OPENED);
    oluacls_const_integer(L, "UNSENT", (lua_Unsigned)cclua::XMLHttpRequest::UNSENT);

    olua_registerluatype<cclua::XMLHttpRequest>(L, "cclua.XMLHttpRequest");

    return 1;
}
OLUA_END_DECLS

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_MP3Encoder_VBRMode(lua_State *L)
{
    oluacls_class(L, "cclua.MP3Encoder.VBRMode", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "ABR", (lua_Integer)cclua::MP3Encoder::VBRMode::ABR);
    oluacls_const_integer(L, "DEFAULT", (lua_Integer)cclua::MP3Encoder::VBRMode::DEFAULT);
    oluacls_const_integer(L, "MAX_INDICATOR", (lua_Integer)cclua::MP3Encoder::VBRMode::MAX_INDICATOR);
    oluacls_const_integer(L, "MT", (lua_Integer)cclua::MP3Encoder::VBRMode::MT);
    oluacls_const_integer(L, "MTRH", (lua_Integer)cclua::MP3Encoder::VBRMode::MTRH);
    oluacls_const_integer(L, "OFF", (lua_Integer)cclua::MP3Encoder::VBRMode::OFF);
    oluacls_const_integer(L, "RH", (lua_Integer)cclua::MP3Encoder::VBRMode::RH);

    olua_registerluatype<cclua::MP3Encoder::VBRMode>(L, "cclua.MP3Encoder.VBRMode");

    return 1;
}
OLUA_END_DECLS
#endif

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_MP3Encoder_MPEGMode(lua_State *L)
{
    oluacls_class(L, "cclua.MP3Encoder.MPEGMode", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "DUAL_CHANNEL", (lua_Integer)cclua::MP3Encoder::MPEGMode::DUAL_CHANNEL);
    oluacls_const_integer(L, "JOINT_STEREO", (lua_Integer)cclua::MP3Encoder::MPEGMode::JOINT_STEREO);
    oluacls_const_integer(L, "MAX_INDICATOR", (lua_Integer)cclua::MP3Encoder::MPEGMode::MAX_INDICATOR);
    oluacls_const_integer(L, "MONO", (lua_Integer)cclua::MP3Encoder::MPEGMode::MONO);
    oluacls_const_integer(L, "NOT_SET", (lua_Integer)cclua::MP3Encoder::MPEGMode::NOT_SET);
    oluacls_const_integer(L, "STEREO", (lua_Integer)cclua::MP3Encoder::MPEGMode::STEREO);

    olua_registerluatype<cclua::MP3Encoder::MPEGMode>(L, "cclua.MP3Encoder.MPEGMode");

    return 1;
}
OLUA_END_DECLS
#endif

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
static int _cclua_MP3Encoder___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::MP3Encoder *)olua_toobj(L, 1, "cclua.MP3Encoder");
    olua_push_obj(L, self, "cclua.MP3Encoder");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_MP3Encoder_getATHlower(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // float getATHlower()
    float ret = self->getATHlower();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getATHonly(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getATHonly()
    int ret = self->getATHonly();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getATHshort(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getATHshort()
    int ret = self->getATHshort();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getATHtype(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getATHtype()
    int ret = self->getATHtype();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getAllowDiffShort(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getAllowDiffShort()
    int ret = self->getAllowDiffShort();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getAnalysis(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getAnalysis()
    int ret = self->getAnalysis();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getAthaaSensitivity(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // float getAthaaSensitivity()
    float ret = self->getAthaaSensitivity();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getAthaaType(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getAthaaType()
    int ret = self->getAthaaType();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getAudiophileGain(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getAudiophileGain()
    int ret = self->getAudiophileGain();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getBWriteVbrTag(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getBWriteVbrTag()
    int ret = self->getBWriteVbrTag();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getBrate(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getBrate()
    int ret = self->getBrate();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getCompressionRatio(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // float getCompressionRatio()
    float ret = self->getCompressionRatio();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getCopyright(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getCopyright()
    int ret = self->getCopyright();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getDecodeOnTheFly(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getDecodeOnTheFly()
    int ret = self->getDecodeOnTheFly();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getDecodeOnly(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getDecodeOnly()
    int ret = self->getDecodeOnly();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getDisableReservoir(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getDisableReservoir()
    int ret = self->getDisableReservoir();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getEmphasis(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getEmphasis()
    int ret = self->getEmphasis();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getEncoderDelay(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getEncoderDelay()
    int ret = self->getEncoderDelay();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getEncoderPadding(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getEncoderPadding()
    int ret = self->getEncoderPadding();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getErrorProtection(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getErrorProtection()
    int ret = self->getErrorProtection();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getExpNspsytune(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getExpNspsytune()
    int ret = self->getExpNspsytune();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getExperimentalX(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getExperimentalX()
    int ret = self->getExperimentalX();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getExperimentalY(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getExperimentalY()
    int ret = self->getExperimentalY();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getExperimentalZ(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getExperimentalZ()
    int ret = self->getExperimentalZ();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getExtension(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getExtension()
    int ret = self->getExtension();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getFindReplayGain(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getFindReplayGain()
    int ret = self->getFindReplayGain();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getForceMs(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getForceMs()
    int ret = self->getForceMs();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getForceShortBlocks(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getForceShortBlocks()
    int ret = self->getForceShortBlocks();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getFrameNum(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getFrameNum()
    int ret = self->getFrameNum();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getFramesize(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getFramesize()
    int ret = self->getFramesize();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getFreeFormat(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getFreeFormat()
    int ret = self->getFreeFormat();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getHighpassfreq(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getHighpassfreq()
    int ret = self->getHighpassfreq();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getHighpasswidth(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getHighpasswidth()
    int ret = self->getHighpasswidth();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getInSamplerate(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getInSamplerate()
    int ret = self->getInSamplerate();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getInterChRatio(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // float getInterChRatio()
    float ret = self->getInterChRatio();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getLameOsBitness(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // const char *getLameOsBitness()
    const char *ret = self->getLameOsBitness();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getLameShortVersion(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // const char *getLameShortVersion()
    const char *ret = self->getLameShortVersion();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getLameUrl(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // const char *getLameUrl()
    const char *ret = self->getLameUrl();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getLameVersion(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // const char *getLameVersion()
    const char *ret = self->getLameVersion();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getLameVeryShortVersion(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // const char *getLameVeryShortVersion()
    const char *ret = self->getLameVeryShortVersion();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getLowpassfreq(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getLowpassfreq()
    int ret = self->getLowpassfreq();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getLowpasswidth(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getLowpasswidth()
    int ret = self->getLowpasswidth();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getMfSamplesToEncode(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getMfSamplesToEncode()
    int ret = self->getMfSamplesToEncode();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getMode(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // cclua::MP3Encoder::MPEGMode getMode()
    cclua::MP3Encoder::MPEGMode ret = self->getMode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getMsfix(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // float getMsfix()
    float ret = self->getMsfix();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getNoATH(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getNoATH()
    int ret = self->getNoATH();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getNoShortBlocks(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getNoShortBlocks()
    int ret = self->getNoShortBlocks();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getNoclipGainChange(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getNoclipGainChange()
    int ret = self->getNoclipGainChange();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getNoclipScale(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // float getNoclipScale()
    float ret = self->getNoclipScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getNogapCurrentindex(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getNogapCurrentindex()
    int ret = self->getNogapCurrentindex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getNogapTotal(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getNogapTotal()
    int ret = self->getNogapTotal();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getNumChannels(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getNumChannels()
    int ret = self->getNumChannels();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getNumSamples(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // unsigned long getNumSamples()
    unsigned long ret = self->getNumSamples();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getOriginal(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getOriginal()
    int ret = self->getOriginal();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getOutSamplerate(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getOutSamplerate()
    int ret = self->getOutSamplerate();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getPeakSample(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // float getPeakSample()
    float ret = self->getPeakSample();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getPsyVersion(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // const char *getPsyVersion()
    const char *ret = self->getPsyVersion();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getQuality(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getQuality()
    int ret = self->getQuality();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getQuantComp(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getQuantComp()
    int ret = self->getQuantComp();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getQuantCompShort(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getQuantCompShort()
    int ret = self->getQuantCompShort();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getRadioGain(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getRadioGain()
    int ret = self->getRadioGain();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getScale(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // float getScale()
    float ret = self->getScale();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getScaleLeft(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // float getScaleLeft()
    float ret = self->getScaleLeft();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getScaleRight(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // float getScaleRight()
    float ret = self->getScaleRight();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getSizeMp3buffer(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getSizeMp3buffer()
    int ret = self->getSizeMp3buffer();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getStrictISO(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getStrictISO()
    int ret = self->getStrictISO();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getTotalframes(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getTotalframes()
    int ret = self->getTotalframes();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getUseTemporal(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getUseTemporal()
    int ret = self->getUseTemporal();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getVBR(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // cclua::MP3Encoder::VBRMode getVBR()
    cclua::MP3Encoder::VBRMode ret = self->getVBR();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getVBRHardMin(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getVBRHardMin()
    int ret = self->getVBRHardMin();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getVBRMaxBitrateKbps(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getVBRMaxBitrateKbps()
    int ret = self->getVBRMaxBitrateKbps();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getVBRMeanBitrateKbps(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getVBRMeanBitrateKbps()
    int ret = self->getVBRMeanBitrateKbps();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getVBRMinBitrateKbps(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getVBRMinBitrateKbps()
    int ret = self->getVBRMinBitrateKbps();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getVBRQ(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getVBRQ()
    int ret = self->getVBRQ();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getVBRQuality(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // float getVBRQuality()
    float ret = self->getVBRQuality();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_getVersion(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // int getVersion()
    int ret = self->getVersion();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_initParams(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // void initParams()
    self->initParams();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_new(lua_State *L)
{
    olua_startinvoke(L);

    // MP3Encoder()
    cclua::MP3Encoder *ret = new cclua::MP3Encoder();
    int num_ret = olua_push_obj(L, ret, "cclua.MP3Encoder");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MP3Encoder_printConfig(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // void printConfig()
    self->printConfig();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_printInternals(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // void printInternals()
    self->printInternals();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setATHlower(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_number(L, 2, &arg1);

    // void setATHlower(float value)
    self->setATHlower((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setATHonly(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setATHonly(int value)
    self->setATHonly((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setATHshort(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setATHshort(int value)
    self->setATHshort((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setATHtype(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setATHtype(int value)
    self->setATHtype((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setAllowDiffShort(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setAllowDiffShort(int value)
    self->setAllowDiffShort((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setAnalysis(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setAnalysis(int value)
    self->setAnalysis((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setAsmOptimizations(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** optim */
    lua_Integer arg2 = 0;       /** mode */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void setAsmOptimizations(int optim, int mode)
    self->setAsmOptimizations((int)arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setAthaaSensitivity(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_number(L, 2, &arg1);

    // void setAthaaSensitivity(float value)
    self->setAthaaSensitivity((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setAthaaType(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setAthaaType(int value)
    self->setAthaaType((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setBWriteVbrTag(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setBWriteVbrTag(int value)
    self->setBWriteVbrTag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setBrate(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setBrate(int value)
    self->setBrate((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setCompressionRatio(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_number(L, 2, &arg1);

    // void setCompressionRatio(float value)
    self->setCompressionRatio((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setCopyright(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setCopyright(int value)
    self->setCopyright((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setDecodeOnTheFly(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setDecodeOnTheFly(int value)
    self->setDecodeOnTheFly((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setDecodeOnly(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setDecodeOnly(int value)
    self->setDecodeOnly((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setDisableReservoir(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setDisableReservoir(int value)
    self->setDisableReservoir((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setEmphasis(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setEmphasis(int value)
    self->setEmphasis((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setErrorProtection(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setErrorProtection(int value)
    self->setErrorProtection((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setExpNspsytune(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setExpNspsytune(int value)
    self->setExpNspsytune((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setExperimentalX(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setExperimentalX(int value)
    self->setExperimentalX((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setExperimentalY(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setExperimentalY(int value)
    self->setExperimentalY((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setExperimentalZ(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setExperimentalZ(int value)
    self->setExperimentalZ((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setExtension(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setExtension(int value)
    self->setExtension((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setFindReplayGain(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setFindReplayGain(int value)
    self->setFindReplayGain((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setForceMs(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setForceMs(int value)
    self->setForceMs((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setForceShortBlocks(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setForceShortBlocks(int value)
    self->setForceShortBlocks((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setFreeFormat(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setFreeFormat(int value)
    self->setFreeFormat((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setHighpassfreq(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setHighpassfreq(int value)
    self->setHighpassfreq((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setHighpasswidth(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setHighpasswidth(int value)
    self->setHighpasswidth((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setInSamplerate(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setInSamplerate(int value)
    self->setInSamplerate((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setInterChRatio(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_number(L, 2, &arg1);

    // void setInterChRatio(float value)
    self->setInterChRatio((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setLowpassfreq(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setLowpassfreq(int value)
    self->setLowpassfreq((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setLowpasswidth(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setLowpasswidth(int value)
    self->setLowpasswidth((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setMode(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_uint(L, 2, &arg1);

    // void setMode(cclua::MP3Encoder::MPEGMode value)
    self->setMode((cclua::MP3Encoder::MPEGMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setMsfix(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_number(L, 2, &arg1);

    // void setMsfix(double value)
    self->setMsfix((double)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setNoATH(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setNoATH(int value)
    self->setNoATH((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setNoShortBlocks(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setNoShortBlocks(int value)
    self->setNoShortBlocks((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setNogapCurrentindex(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setNogapCurrentindex(int value)
    self->setNogapCurrentindex((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setNogapTotal(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setNogapTotal(int value)
    self->setNogapTotal((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setNumChannels(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setNumChannels(int value)
    self->setNumChannels((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setNumSamples(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_uint(L, 2, &arg1);

    // void setNumSamples(unsigned long value)
    self->setNumSamples((unsigned long)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setOriginal(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setOriginal(int value)
    self->setOriginal((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setOutSamplerate(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setOutSamplerate(int value)
    self->setOutSamplerate((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setPreset(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** preset */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setPreset(int preset)
    self->setPreset((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setQuality(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setQuality(int value)
    self->setQuality((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setQuantComp(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setQuantComp(int value)
    self->setQuantComp((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setQuantCompShort(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setQuantCompShort(int value)
    self->setQuantCompShort((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setScale(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_number(L, 2, &arg1);

    // void setScale(float value)
    self->setScale((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setScaleLeft(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_number(L, 2, &arg1);

    // void setScaleLeft(float value)
    self->setScaleLeft((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setScaleRight(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_number(L, 2, &arg1);

    // void setScaleRight(float value)
    self->setScaleRight((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setStrictISO(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setStrictISO(int value)
    self->setStrictISO((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setUseTemporal(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setUseTemporal(int value)
    self->setUseTemporal((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setVBR(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Unsigned arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_uint(L, 2, &arg1);

    // void setVBR(cclua::MP3Encoder::VBRMode value)
    self->setVBR((cclua::MP3Encoder::VBRMode)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setVBRHardMin(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setVBRHardMin(int value)
    self->setVBRHardMin((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setVBRMaxBitrateKbps(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setVBRMaxBitrateKbps(int value)
    self->setVBRMaxBitrateKbps((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setVBRMeanBitrateKbps(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setVBRMeanBitrateKbps(int value)
    self->setVBRMeanBitrateKbps((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setVBRMinBitrateKbps(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setVBRMinBitrateKbps(int value)
    self->setVBRMinBitrateKbps((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setVBRQ(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Integer arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_int(L, 2, &arg1);

    // void setVBRQ(int value)
    self->setVBRQ((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_setVBRQuality(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    lua_Number arg1 = 0;       /** value */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_number(L, 2, &arg1);

    // void setVBRQuality(float value)
    self->setVBRQuality((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_start(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;
    std::string arg1;       /** pcmPath */
    std::string arg2;       /** mp3Path */

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");
    olua_check_std_string(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void start(const std::string &pcmPath, const std::string &mp3Path)
    self->start(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_MP3Encoder_stop(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MP3Encoder *self = nullptr;

    olua_to_obj(L, 1, &self, "cclua.MP3Encoder");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_MP3Encoder(lua_State *L)
{
    oluacls_class(L, "cclua.MP3Encoder", "cc.Ref");
    oluacls_func(L, "__olua_move", _cclua_MP3Encoder___olua_move);
    oluacls_func(L, "getATHlower", _cclua_MP3Encoder_getATHlower);
    oluacls_func(L, "getATHonly", _cclua_MP3Encoder_getATHonly);
    oluacls_func(L, "getATHshort", _cclua_MP3Encoder_getATHshort);
    oluacls_func(L, "getATHtype", _cclua_MP3Encoder_getATHtype);
    oluacls_func(L, "getAllowDiffShort", _cclua_MP3Encoder_getAllowDiffShort);
    oluacls_func(L, "getAnalysis", _cclua_MP3Encoder_getAnalysis);
    oluacls_func(L, "getAthaaSensitivity", _cclua_MP3Encoder_getAthaaSensitivity);
    oluacls_func(L, "getAthaaType", _cclua_MP3Encoder_getAthaaType);
    oluacls_func(L, "getAudiophileGain", _cclua_MP3Encoder_getAudiophileGain);
    oluacls_func(L, "getBWriteVbrTag", _cclua_MP3Encoder_getBWriteVbrTag);
    oluacls_func(L, "getBrate", _cclua_MP3Encoder_getBrate);
    oluacls_func(L, "getCompressionRatio", _cclua_MP3Encoder_getCompressionRatio);
    oluacls_func(L, "getCopyright", _cclua_MP3Encoder_getCopyright);
    oluacls_func(L, "getDecodeOnTheFly", _cclua_MP3Encoder_getDecodeOnTheFly);
    oluacls_func(L, "getDecodeOnly", _cclua_MP3Encoder_getDecodeOnly);
    oluacls_func(L, "getDisableReservoir", _cclua_MP3Encoder_getDisableReservoir);
    oluacls_func(L, "getEmphasis", _cclua_MP3Encoder_getEmphasis);
    oluacls_func(L, "getEncoderDelay", _cclua_MP3Encoder_getEncoderDelay);
    oluacls_func(L, "getEncoderPadding", _cclua_MP3Encoder_getEncoderPadding);
    oluacls_func(L, "getErrorProtection", _cclua_MP3Encoder_getErrorProtection);
    oluacls_func(L, "getExpNspsytune", _cclua_MP3Encoder_getExpNspsytune);
    oluacls_func(L, "getExperimentalX", _cclua_MP3Encoder_getExperimentalX);
    oluacls_func(L, "getExperimentalY", _cclua_MP3Encoder_getExperimentalY);
    oluacls_func(L, "getExperimentalZ", _cclua_MP3Encoder_getExperimentalZ);
    oluacls_func(L, "getExtension", _cclua_MP3Encoder_getExtension);
    oluacls_func(L, "getFindReplayGain", _cclua_MP3Encoder_getFindReplayGain);
    oluacls_func(L, "getForceMs", _cclua_MP3Encoder_getForceMs);
    oluacls_func(L, "getForceShortBlocks", _cclua_MP3Encoder_getForceShortBlocks);
    oluacls_func(L, "getFrameNum", _cclua_MP3Encoder_getFrameNum);
    oluacls_func(L, "getFramesize", _cclua_MP3Encoder_getFramesize);
    oluacls_func(L, "getFreeFormat", _cclua_MP3Encoder_getFreeFormat);
    oluacls_func(L, "getHighpassfreq", _cclua_MP3Encoder_getHighpassfreq);
    oluacls_func(L, "getHighpasswidth", _cclua_MP3Encoder_getHighpasswidth);
    oluacls_func(L, "getInSamplerate", _cclua_MP3Encoder_getInSamplerate);
    oluacls_func(L, "getInterChRatio", _cclua_MP3Encoder_getInterChRatio);
    oluacls_func(L, "getLameOsBitness", _cclua_MP3Encoder_getLameOsBitness);
    oluacls_func(L, "getLameShortVersion", _cclua_MP3Encoder_getLameShortVersion);
    oluacls_func(L, "getLameUrl", _cclua_MP3Encoder_getLameUrl);
    oluacls_func(L, "getLameVersion", _cclua_MP3Encoder_getLameVersion);
    oluacls_func(L, "getLameVeryShortVersion", _cclua_MP3Encoder_getLameVeryShortVersion);
    oluacls_func(L, "getLowpassfreq", _cclua_MP3Encoder_getLowpassfreq);
    oluacls_func(L, "getLowpasswidth", _cclua_MP3Encoder_getLowpasswidth);
    oluacls_func(L, "getMfSamplesToEncode", _cclua_MP3Encoder_getMfSamplesToEncode);
    oluacls_func(L, "getMode", _cclua_MP3Encoder_getMode);
    oluacls_func(L, "getMsfix", _cclua_MP3Encoder_getMsfix);
    oluacls_func(L, "getNoATH", _cclua_MP3Encoder_getNoATH);
    oluacls_func(L, "getNoShortBlocks", _cclua_MP3Encoder_getNoShortBlocks);
    oluacls_func(L, "getNoclipGainChange", _cclua_MP3Encoder_getNoclipGainChange);
    oluacls_func(L, "getNoclipScale", _cclua_MP3Encoder_getNoclipScale);
    oluacls_func(L, "getNogapCurrentindex", _cclua_MP3Encoder_getNogapCurrentindex);
    oluacls_func(L, "getNogapTotal", _cclua_MP3Encoder_getNogapTotal);
    oluacls_func(L, "getNumChannels", _cclua_MP3Encoder_getNumChannels);
    oluacls_func(L, "getNumSamples", _cclua_MP3Encoder_getNumSamples);
    oluacls_func(L, "getOriginal", _cclua_MP3Encoder_getOriginal);
    oluacls_func(L, "getOutSamplerate", _cclua_MP3Encoder_getOutSamplerate);
    oluacls_func(L, "getPeakSample", _cclua_MP3Encoder_getPeakSample);
    oluacls_func(L, "getPsyVersion", _cclua_MP3Encoder_getPsyVersion);
    oluacls_func(L, "getQuality", _cclua_MP3Encoder_getQuality);
    oluacls_func(L, "getQuantComp", _cclua_MP3Encoder_getQuantComp);
    oluacls_func(L, "getQuantCompShort", _cclua_MP3Encoder_getQuantCompShort);
    oluacls_func(L, "getRadioGain", _cclua_MP3Encoder_getRadioGain);
    oluacls_func(L, "getScale", _cclua_MP3Encoder_getScale);
    oluacls_func(L, "getScaleLeft", _cclua_MP3Encoder_getScaleLeft);
    oluacls_func(L, "getScaleRight", _cclua_MP3Encoder_getScaleRight);
    oluacls_func(L, "getSizeMp3buffer", _cclua_MP3Encoder_getSizeMp3buffer);
    oluacls_func(L, "getStrictISO", _cclua_MP3Encoder_getStrictISO);
    oluacls_func(L, "getTotalframes", _cclua_MP3Encoder_getTotalframes);
    oluacls_func(L, "getUseTemporal", _cclua_MP3Encoder_getUseTemporal);
    oluacls_func(L, "getVBR", _cclua_MP3Encoder_getVBR);
    oluacls_func(L, "getVBRHardMin", _cclua_MP3Encoder_getVBRHardMin);
    oluacls_func(L, "getVBRMaxBitrateKbps", _cclua_MP3Encoder_getVBRMaxBitrateKbps);
    oluacls_func(L, "getVBRMeanBitrateKbps", _cclua_MP3Encoder_getVBRMeanBitrateKbps);
    oluacls_func(L, "getVBRMinBitrateKbps", _cclua_MP3Encoder_getVBRMinBitrateKbps);
    oluacls_func(L, "getVBRQ", _cclua_MP3Encoder_getVBRQ);
    oluacls_func(L, "getVBRQuality", _cclua_MP3Encoder_getVBRQuality);
    oluacls_func(L, "getVersion", _cclua_MP3Encoder_getVersion);
    oluacls_func(L, "initParams", _cclua_MP3Encoder_initParams);
    oluacls_func(L, "new", _cclua_MP3Encoder_new);
    oluacls_func(L, "printConfig", _cclua_MP3Encoder_printConfig);
    oluacls_func(L, "printInternals", _cclua_MP3Encoder_printInternals);
    oluacls_func(L, "setATHlower", _cclua_MP3Encoder_setATHlower);
    oluacls_func(L, "setATHonly", _cclua_MP3Encoder_setATHonly);
    oluacls_func(L, "setATHshort", _cclua_MP3Encoder_setATHshort);
    oluacls_func(L, "setATHtype", _cclua_MP3Encoder_setATHtype);
    oluacls_func(L, "setAllowDiffShort", _cclua_MP3Encoder_setAllowDiffShort);
    oluacls_func(L, "setAnalysis", _cclua_MP3Encoder_setAnalysis);
    oluacls_func(L, "setAsmOptimizations", _cclua_MP3Encoder_setAsmOptimizations);
    oluacls_func(L, "setAthaaSensitivity", _cclua_MP3Encoder_setAthaaSensitivity);
    oluacls_func(L, "setAthaaType", _cclua_MP3Encoder_setAthaaType);
    oluacls_func(L, "setBWriteVbrTag", _cclua_MP3Encoder_setBWriteVbrTag);
    oluacls_func(L, "setBrate", _cclua_MP3Encoder_setBrate);
    oluacls_func(L, "setCompressionRatio", _cclua_MP3Encoder_setCompressionRatio);
    oluacls_func(L, "setCopyright", _cclua_MP3Encoder_setCopyright);
    oluacls_func(L, "setDecodeOnTheFly", _cclua_MP3Encoder_setDecodeOnTheFly);
    oluacls_func(L, "setDecodeOnly", _cclua_MP3Encoder_setDecodeOnly);
    oluacls_func(L, "setDisableReservoir", _cclua_MP3Encoder_setDisableReservoir);
    oluacls_func(L, "setEmphasis", _cclua_MP3Encoder_setEmphasis);
    oluacls_func(L, "setErrorProtection", _cclua_MP3Encoder_setErrorProtection);
    oluacls_func(L, "setExpNspsytune", _cclua_MP3Encoder_setExpNspsytune);
    oluacls_func(L, "setExperimentalX", _cclua_MP3Encoder_setExperimentalX);
    oluacls_func(L, "setExperimentalY", _cclua_MP3Encoder_setExperimentalY);
    oluacls_func(L, "setExperimentalZ", _cclua_MP3Encoder_setExperimentalZ);
    oluacls_func(L, "setExtension", _cclua_MP3Encoder_setExtension);
    oluacls_func(L, "setFindReplayGain", _cclua_MP3Encoder_setFindReplayGain);
    oluacls_func(L, "setForceMs", _cclua_MP3Encoder_setForceMs);
    oluacls_func(L, "setForceShortBlocks", _cclua_MP3Encoder_setForceShortBlocks);
    oluacls_func(L, "setFreeFormat", _cclua_MP3Encoder_setFreeFormat);
    oluacls_func(L, "setHighpassfreq", _cclua_MP3Encoder_setHighpassfreq);
    oluacls_func(L, "setHighpasswidth", _cclua_MP3Encoder_setHighpasswidth);
    oluacls_func(L, "setInSamplerate", _cclua_MP3Encoder_setInSamplerate);
    oluacls_func(L, "setInterChRatio", _cclua_MP3Encoder_setInterChRatio);
    oluacls_func(L, "setLowpassfreq", _cclua_MP3Encoder_setLowpassfreq);
    oluacls_func(L, "setLowpasswidth", _cclua_MP3Encoder_setLowpasswidth);
    oluacls_func(L, "setMode", _cclua_MP3Encoder_setMode);
    oluacls_func(L, "setMsfix", _cclua_MP3Encoder_setMsfix);
    oluacls_func(L, "setNoATH", _cclua_MP3Encoder_setNoATH);
    oluacls_func(L, "setNoShortBlocks", _cclua_MP3Encoder_setNoShortBlocks);
    oluacls_func(L, "setNogapCurrentindex", _cclua_MP3Encoder_setNogapCurrentindex);
    oluacls_func(L, "setNogapTotal", _cclua_MP3Encoder_setNogapTotal);
    oluacls_func(L, "setNumChannels", _cclua_MP3Encoder_setNumChannels);
    oluacls_func(L, "setNumSamples", _cclua_MP3Encoder_setNumSamples);
    oluacls_func(L, "setOriginal", _cclua_MP3Encoder_setOriginal);
    oluacls_func(L, "setOutSamplerate", _cclua_MP3Encoder_setOutSamplerate);
    oluacls_func(L, "setPreset", _cclua_MP3Encoder_setPreset);
    oluacls_func(L, "setQuality", _cclua_MP3Encoder_setQuality);
    oluacls_func(L, "setQuantComp", _cclua_MP3Encoder_setQuantComp);
    oluacls_func(L, "setQuantCompShort", _cclua_MP3Encoder_setQuantCompShort);
    oluacls_func(L, "setScale", _cclua_MP3Encoder_setScale);
    oluacls_func(L, "setScaleLeft", _cclua_MP3Encoder_setScaleLeft);
    oluacls_func(L, "setScaleRight", _cclua_MP3Encoder_setScaleRight);
    oluacls_func(L, "setStrictISO", _cclua_MP3Encoder_setStrictISO);
    oluacls_func(L, "setUseTemporal", _cclua_MP3Encoder_setUseTemporal);
    oluacls_func(L, "setVBR", _cclua_MP3Encoder_setVBR);
    oluacls_func(L, "setVBRHardMin", _cclua_MP3Encoder_setVBRHardMin);
    oluacls_func(L, "setVBRMaxBitrateKbps", _cclua_MP3Encoder_setVBRMaxBitrateKbps);
    oluacls_func(L, "setVBRMeanBitrateKbps", _cclua_MP3Encoder_setVBRMeanBitrateKbps);
    oluacls_func(L, "setVBRMinBitrateKbps", _cclua_MP3Encoder_setVBRMinBitrateKbps);
    oluacls_func(L, "setVBRQ", _cclua_MP3Encoder_setVBRQ);
    oluacls_func(L, "setVBRQuality", _cclua_MP3Encoder_setVBRQuality);
    oluacls_func(L, "start", _cclua_MP3Encoder_start);
    oluacls_func(L, "stop", _cclua_MP3Encoder_stop);
    oluacls_prop(L, "allowDiffShort", _cclua_MP3Encoder_getAllowDiffShort, _cclua_MP3Encoder_setAllowDiffShort);
    oluacls_prop(L, "analysis", _cclua_MP3Encoder_getAnalysis, _cclua_MP3Encoder_setAnalysis);
    oluacls_prop(L, "atHlower", _cclua_MP3Encoder_getATHlower, _cclua_MP3Encoder_setATHlower);
    oluacls_prop(L, "atHonly", _cclua_MP3Encoder_getATHonly, _cclua_MP3Encoder_setATHonly);
    oluacls_prop(L, "atHshort", _cclua_MP3Encoder_getATHshort, _cclua_MP3Encoder_setATHshort);
    oluacls_prop(L, "atHtype", _cclua_MP3Encoder_getATHtype, _cclua_MP3Encoder_setATHtype);
    oluacls_prop(L, "athaaSensitivity", _cclua_MP3Encoder_getAthaaSensitivity, _cclua_MP3Encoder_setAthaaSensitivity);
    oluacls_prop(L, "athaaType", _cclua_MP3Encoder_getAthaaType, _cclua_MP3Encoder_setAthaaType);
    oluacls_prop(L, "audiophileGain", _cclua_MP3Encoder_getAudiophileGain, nullptr);
    oluacls_prop(L, "bWriteVbrTag", _cclua_MP3Encoder_getBWriteVbrTag, _cclua_MP3Encoder_setBWriteVbrTag);
    oluacls_prop(L, "brate", _cclua_MP3Encoder_getBrate, _cclua_MP3Encoder_setBrate);
    oluacls_prop(L, "compressionRatio", _cclua_MP3Encoder_getCompressionRatio, _cclua_MP3Encoder_setCompressionRatio);
    oluacls_prop(L, "copyright", _cclua_MP3Encoder_getCopyright, _cclua_MP3Encoder_setCopyright);
    oluacls_prop(L, "decodeOnTheFly", _cclua_MP3Encoder_getDecodeOnTheFly, _cclua_MP3Encoder_setDecodeOnTheFly);
    oluacls_prop(L, "decodeOnly", _cclua_MP3Encoder_getDecodeOnly, _cclua_MP3Encoder_setDecodeOnly);
    oluacls_prop(L, "disableReservoir", _cclua_MP3Encoder_getDisableReservoir, _cclua_MP3Encoder_setDisableReservoir);
    oluacls_prop(L, "emphasis", _cclua_MP3Encoder_getEmphasis, _cclua_MP3Encoder_setEmphasis);
    oluacls_prop(L, "encoderDelay", _cclua_MP3Encoder_getEncoderDelay, nullptr);
    oluacls_prop(L, "encoderPadding", _cclua_MP3Encoder_getEncoderPadding, nullptr);
    oluacls_prop(L, "errorProtection", _cclua_MP3Encoder_getErrorProtection, _cclua_MP3Encoder_setErrorProtection);
    oluacls_prop(L, "expNspsytune", _cclua_MP3Encoder_getExpNspsytune, _cclua_MP3Encoder_setExpNspsytune);
    oluacls_prop(L, "experimentalX", _cclua_MP3Encoder_getExperimentalX, _cclua_MP3Encoder_setExperimentalX);
    oluacls_prop(L, "experimentalY", _cclua_MP3Encoder_getExperimentalY, _cclua_MP3Encoder_setExperimentalY);
    oluacls_prop(L, "experimentalZ", _cclua_MP3Encoder_getExperimentalZ, _cclua_MP3Encoder_setExperimentalZ);
    oluacls_prop(L, "extension", _cclua_MP3Encoder_getExtension, _cclua_MP3Encoder_setExtension);
    oluacls_prop(L, "findReplayGain", _cclua_MP3Encoder_getFindReplayGain, _cclua_MP3Encoder_setFindReplayGain);
    oluacls_prop(L, "forceMs", _cclua_MP3Encoder_getForceMs, _cclua_MP3Encoder_setForceMs);
    oluacls_prop(L, "forceShortBlocks", _cclua_MP3Encoder_getForceShortBlocks, _cclua_MP3Encoder_setForceShortBlocks);
    oluacls_prop(L, "frameNum", _cclua_MP3Encoder_getFrameNum, nullptr);
    oluacls_prop(L, "framesize", _cclua_MP3Encoder_getFramesize, nullptr);
    oluacls_prop(L, "freeFormat", _cclua_MP3Encoder_getFreeFormat, _cclua_MP3Encoder_setFreeFormat);
    oluacls_prop(L, "highpassfreq", _cclua_MP3Encoder_getHighpassfreq, _cclua_MP3Encoder_setHighpassfreq);
    oluacls_prop(L, "highpasswidth", _cclua_MP3Encoder_getHighpasswidth, _cclua_MP3Encoder_setHighpasswidth);
    oluacls_prop(L, "inSamplerate", _cclua_MP3Encoder_getInSamplerate, _cclua_MP3Encoder_setInSamplerate);
    oluacls_prop(L, "interChRatio", _cclua_MP3Encoder_getInterChRatio, _cclua_MP3Encoder_setInterChRatio);
    oluacls_prop(L, "lameOsBitness", _cclua_MP3Encoder_getLameOsBitness, nullptr);
    oluacls_prop(L, "lameShortVersion", _cclua_MP3Encoder_getLameShortVersion, nullptr);
    oluacls_prop(L, "lameUrl", _cclua_MP3Encoder_getLameUrl, nullptr);
    oluacls_prop(L, "lameVersion", _cclua_MP3Encoder_getLameVersion, nullptr);
    oluacls_prop(L, "lameVeryShortVersion", _cclua_MP3Encoder_getLameVeryShortVersion, nullptr);
    oluacls_prop(L, "lowpassfreq", _cclua_MP3Encoder_getLowpassfreq, _cclua_MP3Encoder_setLowpassfreq);
    oluacls_prop(L, "lowpasswidth", _cclua_MP3Encoder_getLowpasswidth, _cclua_MP3Encoder_setLowpasswidth);
    oluacls_prop(L, "mfSamplesToEncode", _cclua_MP3Encoder_getMfSamplesToEncode, nullptr);
    oluacls_prop(L, "mode", _cclua_MP3Encoder_getMode, _cclua_MP3Encoder_setMode);
    oluacls_prop(L, "msfix", _cclua_MP3Encoder_getMsfix, _cclua_MP3Encoder_setMsfix);
    oluacls_prop(L, "noATH", _cclua_MP3Encoder_getNoATH, _cclua_MP3Encoder_setNoATH);
    oluacls_prop(L, "noShortBlocks", _cclua_MP3Encoder_getNoShortBlocks, _cclua_MP3Encoder_setNoShortBlocks);
    oluacls_prop(L, "noclipGainChange", _cclua_MP3Encoder_getNoclipGainChange, nullptr);
    oluacls_prop(L, "noclipScale", _cclua_MP3Encoder_getNoclipScale, nullptr);
    oluacls_prop(L, "nogapCurrentindex", _cclua_MP3Encoder_getNogapCurrentindex, _cclua_MP3Encoder_setNogapCurrentindex);
    oluacls_prop(L, "nogapTotal", _cclua_MP3Encoder_getNogapTotal, _cclua_MP3Encoder_setNogapTotal);
    oluacls_prop(L, "numChannels", _cclua_MP3Encoder_getNumChannels, _cclua_MP3Encoder_setNumChannels);
    oluacls_prop(L, "numSamples", _cclua_MP3Encoder_getNumSamples, _cclua_MP3Encoder_setNumSamples);
    oluacls_prop(L, "original", _cclua_MP3Encoder_getOriginal, _cclua_MP3Encoder_setOriginal);
    oluacls_prop(L, "outSamplerate", _cclua_MP3Encoder_getOutSamplerate, _cclua_MP3Encoder_setOutSamplerate);
    oluacls_prop(L, "peakSample", _cclua_MP3Encoder_getPeakSample, nullptr);
    oluacls_prop(L, "psyVersion", _cclua_MP3Encoder_getPsyVersion, nullptr);
    oluacls_prop(L, "quality", _cclua_MP3Encoder_getQuality, _cclua_MP3Encoder_setQuality);
    oluacls_prop(L, "quantComp", _cclua_MP3Encoder_getQuantComp, _cclua_MP3Encoder_setQuantComp);
    oluacls_prop(L, "quantCompShort", _cclua_MP3Encoder_getQuantCompShort, _cclua_MP3Encoder_setQuantCompShort);
    oluacls_prop(L, "radioGain", _cclua_MP3Encoder_getRadioGain, nullptr);
    oluacls_prop(L, "scale", _cclua_MP3Encoder_getScale, _cclua_MP3Encoder_setScale);
    oluacls_prop(L, "scaleLeft", _cclua_MP3Encoder_getScaleLeft, _cclua_MP3Encoder_setScaleLeft);
    oluacls_prop(L, "scaleRight", _cclua_MP3Encoder_getScaleRight, _cclua_MP3Encoder_setScaleRight);
    oluacls_prop(L, "sizeMp3buffer", _cclua_MP3Encoder_getSizeMp3buffer, nullptr);
    oluacls_prop(L, "strictISO", _cclua_MP3Encoder_getStrictISO, _cclua_MP3Encoder_setStrictISO);
    oluacls_prop(L, "totalframes", _cclua_MP3Encoder_getTotalframes, nullptr);
    oluacls_prop(L, "useTemporal", _cclua_MP3Encoder_getUseTemporal, _cclua_MP3Encoder_setUseTemporal);
    oluacls_prop(L, "vbr", _cclua_MP3Encoder_getVBR, _cclua_MP3Encoder_setVBR);
    oluacls_prop(L, "vbrHardMin", _cclua_MP3Encoder_getVBRHardMin, _cclua_MP3Encoder_setVBRHardMin);
    oluacls_prop(L, "vbrMaxBitrateKbps", _cclua_MP3Encoder_getVBRMaxBitrateKbps, _cclua_MP3Encoder_setVBRMaxBitrateKbps);
    oluacls_prop(L, "vbrMeanBitrateKbps", _cclua_MP3Encoder_getVBRMeanBitrateKbps, _cclua_MP3Encoder_setVBRMeanBitrateKbps);
    oluacls_prop(L, "vbrMinBitrateKbps", _cclua_MP3Encoder_getVBRMinBitrateKbps, _cclua_MP3Encoder_setVBRMinBitrateKbps);
    oluacls_prop(L, "vbrQuality", _cclua_MP3Encoder_getVBRQuality, _cclua_MP3Encoder_setVBRQuality);
    oluacls_prop(L, "vbrq", _cclua_MP3Encoder_getVBRQ, _cclua_MP3Encoder_setVBRQ);
    oluacls_prop(L, "version", _cclua_MP3Encoder_getVersion, nullptr);

    olua_registerluatype<cclua::MP3Encoder>(L, "cclua.MP3Encoder");

    return 1;
}
OLUA_END_DECLS
#endif

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
static int _cclua_microphone___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::microphone *)olua_toobj(L, 1, "cclua.microphone");
    olua_push_obj(L, self, "cclua.microphone");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_microphone_dispatch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    cocos2d::ValueMap arg2;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    cclua::microphone::dispatch(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_microphone_isRunning(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isRunning()
    bool ret = cclua::microphone::isRunning();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_microphone_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Callback arg1;       /** dispatcher */

    olua_check_callback(L, 1, &arg1, "cclua.Callback");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.microphone");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const std::string &arg1, const cocos2d::Value &arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_std_string(L, arg1);
            olua_push_cocos2d_Value(L, &arg2);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void setDispatcher(@localvar const cclua::Callback &dispatcher)
    cclua::microphone::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_microphone_start(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static void start(const std::string &path)
    cclua::microphone::start(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_microphone_stop(lua_State *L)
{
    olua_startinvoke(L);

    // static void stop()
    cclua::microphone::stop();

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_microphone(lua_State *L)
{
    oluacls_class(L, "cclua.microphone", nullptr);
    oluacls_func(L, "__olua_move", _cclua_microphone___olua_move);
    oluacls_func(L, "dispatch", _cclua_microphone_dispatch);
    oluacls_func(L, "isRunning", _cclua_microphone_isRunning);
    oluacls_func(L, "setDispatcher", _cclua_microphone_setDispatcher);
    oluacls_func(L, "start", _cclua_microphone_start);
    oluacls_func(L, "stop", _cclua_microphone_stop);
    oluacls_prop(L, "running", _cclua_microphone_isRunning, nullptr);

    olua_registerluatype<cclua::microphone>(L, "cclua.microphone");
    cclua::runtime::registerFeature("cclua.microphone", true);

    return 1;
}
OLUA_END_DECLS
#endif

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
static int _cclua_photo___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::photo *)olua_toobj(L, 1, "cclua.photo");
    olua_push_obj(L, self, "cclua.photo");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_photo_dispatch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    cocos2d::ValueMap arg2;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    cclua::photo::dispatch(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_photo_select(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** cachePath */

    olua_check_std_string(L, 1, &arg1);

    // static void select(const std::string &cachePath)
    cclua::photo::select(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_photo_selectAvatar(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** cachePath */
    lua_Integer arg2 = 0;       /** width */
    lua_Integer arg3 = 0;       /** height */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);
    olua_check_int(L, 3, &arg3);

    // static void selectAvatar(const std::string &cachePath, int width, int height)
    cclua::photo::selectAvatar(arg1, (int)arg2, (int)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_photo_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Callback arg1;       /** dispatcher */

    olua_check_callback(L, 1, &arg1, "cclua.Callback");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.photo");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const std::string &arg1, const cocos2d::Value &arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_std_string(L, arg1);
            olua_push_cocos2d_Value(L, &arg2);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void setDispatcher(@localvar const cclua::Callback &dispatcher)
    cclua::photo::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_photo_takeAvatar(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** cachePath */
    lua_Integer arg2 = 0;       /** width */
    lua_Integer arg3 = 0;       /** height */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);
    olua_check_int(L, 3, &arg3);

    // static void takeAvatar(const std::string &cachePath, int width, int height)
    cclua::photo::takeAvatar(arg1, (int)arg2, (int)arg3);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_photo(lua_State *L)
{
    oluacls_class(L, "cclua.photo", nullptr);
    oluacls_func(L, "__olua_move", _cclua_photo___olua_move);
    oluacls_func(L, "dispatch", _cclua_photo_dispatch);
    oluacls_func(L, "select", _cclua_photo_select);
    oluacls_func(L, "selectAvatar", _cclua_photo_selectAvatar);
    oluacls_func(L, "setDispatcher", _cclua_photo_setDispatcher);
    oluacls_func(L, "takeAvatar", _cclua_photo_takeAvatar);

    olua_registerluatype<cclua::photo>(L, "cclua.photo");
    cclua::runtime::registerFeature("cclua.photo", true);

    return 1;
}
OLUA_END_DECLS
#endif

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_xgame(lua_State *L)
{
    olua_require(L, "cclua.Callback", luaopen_cclua_Callback);
    olua_require(L, "cclua.QRCode.ECLevel", luaopen_cclua_QRCode_ECLevel);
    olua_require(L, "cclua.QRCode.EncodeMode", luaopen_cclua_QRCode_EncodeMode);
    olua_require(L, "cclua.QRCode", luaopen_cclua_QRCode);
    olua_require(L, "cclua.SceneNoCamera", luaopen_cclua_SceneNoCamera);
    olua_require(L, "cclua.permission.status", luaopen_cclua_permission_status);
    olua_require(L, "cclua.permission.android", luaopen_cclua_permission_android);
    olua_require(L, "cclua.permission", luaopen_cclua_permission);
    olua_require(L, "cclua.runtime", luaopen_cclua_runtime);
    olua_require(L, "cclua.filesystem", luaopen_cclua_filesystem);
    olua_require(L, "cclua.preferences", luaopen_cclua_preferences);
    olua_require(L, "cclua.timer", luaopen_cclua_timer);
    olua_require(L, "cclua.window", luaopen_cclua_window);
    olua_require(L, "cclua.downloader", luaopen_cclua_downloader);
    olua_require(L, "cclua.Container", luaopen_cclua_Container);
    olua_require(L, "cclua.XMLHttpRequest.ResponseType", luaopen_cclua_XMLHttpRequest_ResponseType);
    olua_require(L, "cclua.XMLHttpRequest", luaopen_cclua_XMLHttpRequest);
#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
    olua_require(L, "cclua.MP3Encoder.VBRMode", luaopen_cclua_MP3Encoder_VBRMode);
    olua_require(L, "cclua.MP3Encoder.MPEGMode", luaopen_cclua_MP3Encoder_MPEGMode);
    olua_require(L, "cclua.MP3Encoder", luaopen_cclua_MP3Encoder);
    olua_require(L, "cclua.microphone", luaopen_cclua_microphone);
    olua_require(L, "cclua.photo", luaopen_cclua_photo);
#endif

    return 0;
}
OLUA_END_DECLS
