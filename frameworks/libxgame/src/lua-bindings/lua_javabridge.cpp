

#include "lua_javabridge.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "base/ccUTF8.h"
#include "xgame/xruntime.h"

#include <stdlib.h>

using namespace cocos2d;

#define TYPE_VOID     0
#define TYPE_BOOL     1
#define TYPE_STRING   2
#define TYPE_INT      3
#define TYPE_LONG     4
#define TYPE_FLOAT    5
#define TYPE_DOUBLE   6

static const char *_token(const char *signature, int *arg_type)
{
    switch (*signature) {
        case 'I': {
            *arg_type = TYPE_INT;
            return ++signature;
        }
        case 'J': {
            *arg_type = TYPE_LONG;
            return ++signature;
        }
        case 'F': {
            *arg_type = TYPE_FLOAT;
            return ++signature;
        }
        case 'D': {
            *arg_type = TYPE_DOUBLE;
            return ++signature;
        }
        case 'Z': {
            *arg_type = TYPE_BOOL;
            return ++signature;
        }
        case 'V': {
            *arg_type = TYPE_VOID;
            return ++signature;
        }
        case 'L': {
            *arg_type = TYPE_STRING;
            const char *sep = strchr(signature, ';');
            if (sep == NULL)
                return NULL;
            
            if (strnequal("Ljava/lang/String;", signature, sep - signature + 1))
                return ++sep;
            
            return NULL;
        }
        default:
            return NULL;
    }
}

static int _parse(const char *signature, int *ret_type, int **arg_types)
{
    int count = 0;
    
    if (signature == NULL || *signature++ != '(')
        return -1;
    
    int capacity = 0;
    int *types = NULL;
    
    while (*signature != '\0' && *signature != ')') {
        int type = TYPE_VOID;
        signature = _token(signature, &type);
        
        if (signature == NULL || type == TYPE_VOID) {
            free(types);
            return -1;
        }
        
        if (count >= capacity) {
            capacity = capacity == 0 ?  4 : 2 * capacity;
            types = (int *)realloc(types, sizeof(int) * capacity);
        }
        
        types[count++] = type;
    }
    
    if (*signature++ != ')') {
        free(types);
        return -1;
    }

    signature = _token(signature, ret_type);
    if (signature == NULL || *signature != '\0') {
        free(types);
        return -1;
    }
    
    *arg_types = types;
    
    return count;
}

int luaj_invoke(lua_State *L)
{
    lua_checkstack(L, 3);

    const char *classname = luaL_checkstring(L, 1);
    const char *methodname = luaL_checkstring(L, 2);
    const char *signature = luaL_checkstring(L, 3);

    JniMethodInfo info;
    if (!JniHelper::getStaticMethodInfo(info, classname, methodname, signature)) {
        luaL_error(L, "method not found: %s#%s%s", classname, methodname, signature);
    }
    
    int ret_type = -1;
    int *arg_types = NULL;
    int count = _parse(signature, &ret_type, &arg_types);
    
    if (count < 0) {
        info.env->DeleteLocalRef(info.classID);
        luaL_error(L, "method sign error: %s#%s%s", classname, methodname, signature);
    }

    lua_settop(L, 3 + count);

    jvalue *args = NULL;
    if (count > 0)
    {
        args = (jvalue *)malloc(sizeof(jvalue) * count);
        for (int i = 0; i < count; i++) {
            switch (arg_types[i]) {
                case TYPE_BOOL: {
                    args[i].z = (jboolean)lua_toboolean(L, 4 + i);
                    break;
                }
                case TYPE_STRING: {
                    const char *value = luaL_checkstring(L, 4 + i);
                    args[i].l = StringUtils::newStringUTFJNI(info.env, value, NULL);
                    break;
                }
                case TYPE_INT: {
                    if (lua_isfunction(L, 4 + i)) {
                        args[i].i = (jint)xlua_reffunc(L, 4 + i);
                    } else {
                        args[i].i = (jint)luaL_checkinteger(L, 4 + i);
                    }
                    break;
                }
                case TYPE_LONG: {
                    args[i].j = (jlong)luaL_checkinteger(L, 4 + i);
                    break;
                }
                case TYPE_FLOAT: {
                    args[i].f = (jfloat)luaL_checknumber(L, 4 + i);
                    break;
                }
                case TYPE_DOUBLE: {
                    args[i].d = (jdouble)luaL_checknumber(L, 4 + i);
                    break;
                }
                default: {
                    // never run
                    info.env->DeleteLocalRef(info.classID);
                    xgame::runtime::log("[NO] java bridge call: %s#%s%s", classname, methodname, signature);
                    luaL_error(L, "method sign error: %s#%s%s", classname, methodname, signature);
                }
            } // switch
        } // for
    }

    switch (ret_type) {
        case TYPE_VOID: {
            info.env->CallStaticVoidMethodA(info.classID, info.methodID, args);
            break;
        }
        case TYPE_BOOL: {
            jboolean ret = info.env->CallStaticBooleanMethodA(info.classID, info.methodID, args);
            lua_pushboolean(L, (bool)ret);
            break;
        }
        case TYPE_STRING: {
            jstring ret = (jstring)info.env->CallStaticObjectMethodA(info.classID, info.methodID, args);
            std::string str = cocos2d::JniHelper::jstring2string(ret);
            lua_pushstring(L, str.c_str());
            break;
        }
        case TYPE_INT: {
            jint ret = info.env->CallStaticIntMethodA(info.classID, info.methodID, args);
            lua_pushinteger(L, (lua_Integer)ret);
            break;
        }
        case TYPE_LONG: {
            jlong ret = info.env->CallStaticLongMethodA(info.classID, info.methodID, args);
            lua_pushinteger(L, (lua_Integer)ret);
            break;
        }
        case TYPE_FLOAT: {
            jfloat ret = info.env->CallStaticFloatMethodA(info.classID, info.methodID, args);
            lua_pushnumber(L, (lua_Number)ret);
            break;
        }
        case TYPE_DOUBLE: {
            jdouble ret = info.env->CallStaticDoubleMethodA(info.classID, info.methodID, args);
            lua_pushnumber(L, (lua_Number)ret);
            break;
        }
        default: {
            free(args);
            info.env->DeleteLocalRef(info.classID);
            xgame::runtime::log("[NO] java bridge call: %s#%s%s", classname, methodname, signature);
            luaL_error(L, "unsupport return type: %s#%s%s", classname, methodname, signature);
        }
    }

    if (count > 0 && args != NULL) {
        for (int i = 0; i < count; i++) {
            if (arg_types[i] == TYPE_STRING) {
                info.env->DeleteLocalRef(args[i].l);
            }
        }
        free(args);
    }

    info.env->DeleteLocalRef(info.classID);
    free(arg_types);

    if (info.env->ExceptionCheck() == JNI_TRUE) {
        info.env->ExceptionDescribe();
        info.env->ExceptionClear();
        xgame::runtime::log("[NO] java bridge call: %s#%s%s", classname, methodname, signature);
        luaL_error(L, "java bridge call error: %s#%s%s", classname, methodname, signature);
    }

    xgame::runtime::log("[OK] java bridge call: %s#%s%s", classname, methodname, signature);

    return 1;
}

static int _validate(lua_State *L)
{
    lua_settop(L, 3);
    const char *classname = luaL_checkstring(L, 1);
    const char *methodname = luaL_checkstring(L, 2);
    const char *signature = luaL_checkstring(L, 3);

    JniMethodInfo info;
    if (JniHelper::getStaticMethodInfo(info, classname, methodname, signature)) {
        info.env->DeleteLocalRef(info.classID);
        lua_pushboolean(L, true);
    } else {
        lua_pushboolean(L, false);
    }
    return 1;
}

int luaopen_javabridge(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"invoke", luaj_invoke},
        {"validate", _validate},
        {NULL, NULL}
    };
    
    luaL_newlib(L, lib);
    
    return 1;
}

extern "C" {
JNIEXPORT void JNICALL Java_kernel_android_LuaJ_invoke
        (JNIEnv *env, jclass cls, jint func, jstring value) {
    CC_UNUSED_PARAM(env);
    CC_UNUSED_PARAM(cls);

    if (!xgame::runtime::isRestarting()) {
        std::string args = cocos2d::JniHelper::jstring2string(value);
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, func);
        if (!lua_isnil(L, -1)) {
            lua_pushstring(L, args.c_str());
            lua_pcall(L, 1, 0, top + 1);
        } else {
            xgame::runtime::log("attemp to call nil: %d %s", (int) func, args.c_str());
        }

        lua_settop(L, top);
    }
}

JNIEXPORT void JNICALL Java_kernel_android_LuaJ_unref
        (JNIEnv *env, jclass cls, jint func) {
    CC_UNUSED_PARAM(env);
    CC_UNUSED_PARAM(cls);

    lua_State *L = olua_mainthread();
    xlua_unref(L, func);
}

JNIEXPORT void JNICALL Java_kernel_android_LuaJ_registerFeature
        (JNIEnv *env, jclass cls, jstring japi, jboolean enabled) {
    CC_UNUSED_PARAM(env);
    CC_UNUSED_PARAM(cls);
    std::string api = cocos2d::JniHelper::jstring2string(japi);
    xgame::runtime::registerFeature(api, (bool)enabled);
}
}

#endif
