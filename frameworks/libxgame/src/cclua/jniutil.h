#ifndef __CCLUA_JNIUTIL_H__
#define __CCLUA_JNIUTIL_H__

#include "cclua/runtime.h"
#include "platform/android/jni/JniHelper.h"

NS_CCLUA_BEGIN

class Jni
{
public:
    template <typename... Ts> static void callStaticVoidMethod(const std::string &className, const std::string &methodName, Ts... xs) {
        cocos2d::JniMethodInfo t;
        std::string signature = "(" + std::string(getSignature(xs...)) + ")V";
        if (cocos2d::JniHelper::getStaticMethodInfo(t, className.c_str(), methodName.c_str(), signature.c_str())) {
            cocos2d::JniHelper::LocalRefMapType localRefs;
            t.env->CallStaticVoidMethod(t.classID, t.methodID, convert(localRefs, t, xs)...);
            t.env->DeleteLocalRef(t.classID);
            deleteLocalRefs(t.env, localRefs);
        } else {
            reportError(className, methodName, signature);
        }
    }

    template <typename... Ts> static bool callStaticBooleanMethod(const std::string &className, const std::string &methodName, Ts... xs) {
        jboolean jret = JNI_FALSE;
        cocos2d::JniMethodInfo t;
        std::string signature = "(" + std::string(getSignature(xs...)) + ")Z";
        if (cocos2d::JniHelper::getStaticMethodInfo(t, className.c_str(), methodName.c_str(), signature.c_str())) {
            cocos2d::JniHelper::LocalRefMapType localRefs;
            jret = t.env->CallStaticBooleanMethod(t.classID, t.methodID, convert(localRefs, t, xs)...);
            t.env->DeleteLocalRef(t.classID);
            deleteLocalRefs(t.env, localRefs);
        } else {
            reportError(className, methodName, signature);
        }
        return (jret == JNI_TRUE);
    }

    template <typename... Ts> static int callStaticIntMethod(const std::string &className, const std::string &methodName, Ts... xs) {
        jint ret = 0;
        cocos2d::JniMethodInfo t;
        std::string signature = "(" + std::string(getSignature(xs...)) + ")I";
        if (cocos2d::JniHelper::getStaticMethodInfo(t, className.c_str(), methodName.c_str(), signature.c_str())) {
            cocos2d::JniHelper::LocalRefMapType localRefs;
            ret = t.env->CallStaticIntMethod(t.classID, t.methodID, convert(localRefs, t, xs)...);
            t.env->DeleteLocalRef(t.classID);
            deleteLocalRefs(t.env, localRefs);
        } else {
            reportError(className, methodName, signature);
        }
        return ret;
    }

    template <typename... Ts> static float callStaticFloatMethod(const std::string &className, const std::string &methodName, Ts... xs) {
        jfloat ret = 0.0;
        cocos2d::JniMethodInfo t;
        std::string signature = "(" + std::string(getSignature(xs...)) + ")F";
        if (cocos2d::JniHelper::getStaticMethodInfo(t, className.c_str(), methodName.c_str(), signature.c_str())) {
            cocos2d::JniHelper::LocalRefMapType localRefs;
            ret = t.env->CallStaticFloatMethod(t.classID, t.methodID, convert(localRefs, t, xs)...);
            t.env->DeleteLocalRef(t.classID);
            deleteLocalRefs(t.env, localRefs);
        } else {
            reportError(className, methodName, signature);
        }
        return ret;
    }

    template <typename... Ts> static double callStaticDoubleMethod(const std::string &className, const std::string &methodName, Ts... xs) {
        jdouble ret = 0.0;
        cocos2d::JniMethodInfo t;
        std::string signature = "(" + std::string(getSignature(xs...)) + ")D";
        if (cocos2d::JniHelper::getStaticMethodInfo(t, className.c_str(), methodName.c_str(), signature.c_str())) {
            cocos2d::JniHelper::LocalRefMapType localRefs;
            ret = t.env->CallStaticDoubleMethod(t.classID, t.methodID, convert(localRefs, t, xs)...);
            t.env->DeleteLocalRef(t.classID);
            deleteLocalRefs(t.env, localRefs);
        } else {
            reportError(className, methodName, signature);
        }
        return ret;
    }

    template <typename... Ts> static std::string callStaticStringMethod(const std::string &className, const std::string &methodName, Ts... xs) {
        std::string ret;

        cocos2d::JniMethodInfo t;
        std::string signature = "(" + std::string(getSignature(xs...)) + ")Ljava/lang/String;";
        if (cocos2d::JniHelper::getStaticMethodInfo(t, className.c_str(), methodName.c_str(), signature.c_str())) {
            cocos2d::JniHelper::LocalRefMapType localRefs;
            jstring jret = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID, convert(localRefs, t, xs)...);
            ret = cocos2d::JniHelper::jstring2string(jret);
            t.env->DeleteLocalRef(t.classID);
            t.env->DeleteLocalRef(jret);
            deleteLocalRefs(t.env, localRefs);
        } else {
            reportError(className, methodName, signature);
        }
        return ret;
    }
private:
    static std::string getSignature() {
        return "";
    }

    static std::string getSignature(bool) {
        return "Z";
    }

    static std::string getSignature(char) {
        return "C";
    }

    static std::string getSignature(short) {
        return "S";
    }

    static std::string getSignature(int) {
        return "I";
    }

    static std::string getSignature(long) {
        return "J";
    }

    static std::string getSignature(float) {
        return "F";
    }

   static  std::string getSignature(double) {
        return "D";
    }

    static std::string getSignature(const char*) {
        return "Ljava/lang/String;";
    }

    static std::string getSignature(const std::string&) {
        return "Ljava/lang/String;";
    }

    template <typename T> static std::string getSignature(T x) {
        static_assert(sizeof(x) == 0, "Unsupported argument type");
        return "";
    }

    template <typename T, typename... Ts> static std::string getSignature(T x, Ts... xs) {
        return getSignature(x) + getSignature(xs...);
    }

    static jstring convert(cocos2d::JniHelper::LocalRefMapType &localRefs, cocos2d::JniMethodInfo &t, const char* x);

    static jstring convert(cocos2d::JniHelper::LocalRefMapType &localRefs, cocos2d::JniMethodInfo &t, const std::string &x);

    inline static jint convert(cocos2d::JniHelper::LocalRefMapType&, cocos2d::JniMethodInfo&, int32_t value) { return static_cast<jint>(value);}
    inline static jlong convert(cocos2d::JniHelper::LocalRefMapType&, cocos2d::JniMethodInfo&, int64_t value) { return static_cast<jlong>(value);}
    inline static jfloat convert(cocos2d::JniHelper::LocalRefMapType&, cocos2d::JniMethodInfo&, float   value) { return static_cast<jfloat>(value);}
    inline static jdouble convert(cocos2d::JniHelper::LocalRefMapType&, cocos2d::JniMethodInfo&, double  value) { return static_cast<jdouble>(value);}
    inline static jboolean convert(cocos2d::JniHelper::LocalRefMapType&, cocos2d::JniMethodInfo&, bool    value) { return static_cast<jboolean>(value);}
    inline static jbyte convert(cocos2d::JniHelper::LocalRefMapType&, cocos2d::JniMethodInfo&, int8_t  value) { return static_cast<jbyte>(value);}
    inline static jchar convert(cocos2d::JniHelper::LocalRefMapType&, cocos2d::JniMethodInfo&, uint8_t value) { return static_cast<jchar>(value);}
    inline static jshort convert(cocos2d::JniHelper::LocalRefMapType&, cocos2d::JniMethodInfo&, int16_t value) { return static_cast<jshort>(value);}

    template <typename T>
    static T convert(cocos2d::JniHelper::LocalRefMapType &localRefs, cocos2d::JniMethodInfo&, T x) {
        return x;
    }

    static void deleteLocalRefs(JNIEnv* env, cocos2d::JniHelper::LocalRefMapType &localRefs);

    static void reportError(const std::string &className, const std::string &methodName, const std::string &signature);
};

NS_CCLUA_END

#endif
