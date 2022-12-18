#include "cclua/jniutil.h"

NS_CCLUA_BEGIN

jstring Jni::convert(cocos2d::JniHelper::LocalRefMapType& localRefs, cocos2d::JniMethodInfo& t, const char* x) {
    jstring ret = cocos2d::StringUtils::newStringUTFJNI(t.env, x ? x : "");
    localRefs[t.env].push_back(ret);
    return ret;
}

jstring Jni::convert(cocos2d::JniHelper::LocalRefMapType& localRefs, cocos2d::JniMethodInfo& t, const std::string& x) {
    return convert(localRefs, t, x.c_str());
}

void Jni::deleteLocalRefs(JNIEnv* env, cocos2d::JniHelper::LocalRefMapType& localRefs)
{
    if (!env) {
        return;
    }

    for (const auto& ref : localRefs[env]) {
        env->DeleteLocalRef(ref);
    }
    localRefs[env].clear();
}

void Jni::reportError(const std::string& className, const std::string& methodName, const std::string& signature) {
    std::string error = "method not found: " + className + "#" + methodName + signature;
    if (!cc_assert_script_compatible(error.c_str())) {
        runtime::log(error.c_str());
    }
}

NS_CCLUA_END
