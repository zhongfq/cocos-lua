#ifndef __CCLUA_PHOTO_H__
#define __CCLUA_PHOTO_H__

#include "cclua/plugin.h"

NS_CCLUA_BEGIN

class photo {
public:
    static void selectAvatar(const std::string &cachePath, int width, int height);
    static void takeAvatar(const std::string &cachePath,  int width, int height);
    static void select(const std::string &cachePath);

public:
    static void setDispatcher(const cclua::Callback &dispatcher)
    {
#ifdef CCLUA_OS_ANDROID
        olua_Ref func = runtime::ref(dispatcher);
        Jni::callStaticVoidMethod(JAVA_CLASS, "setDispatcher", func);
#else
        _dispatcher = dispatcher;
#endif
    }

    static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    {
        cclua::runtime::runLater([=]() {
            if (_dispatcher) {
                _dispatcher(event, cocos2d::Value(data));
            }
        });
    }

private:
    static cclua::Callback _dispatcher;
#ifdef CCLUA_OS_ANDROID
        static const char *JAVA_CLASS;
#endif
};

NS_CCLUA_END

#endif // __CCLUA_PHOTO_H__
