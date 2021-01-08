#include "xgame/filesystem-private.h"
#include "xgame/filesystem.h"

#include "cocos2d.h"

USING_NS_CC;

NS_XGAME_BEGIN

#ifdef CCLUA_OS_ANDROID

const std::string __filesystem_getDocumentDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getDocumentDirectory");
    }
    
    return path;
}

const std::string __filesystem_getCacheDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getCacheDirectory");
    }
    
    return path;
}

const std::string __filesystem_getTmpDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getTmpDirectory");
    }
    
    return path;
}

const std::string __filesystem_getSDCardDirectory()
{
    static std::string path;
    
    if (path.size() == 0) {
        path = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getSDCardDirectory");
    }
    
    return path;
}

const std::string __filesystem_getDir(const std::string &type)
{
    return JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getDirectory", type);
}

#elif defined(CCLUA_OS_WIN32)

#define CC_MAX_PATH  512

static std::string StringWideCharToUtf8(const std::wstring &strWideChar)
{
    std::string ret;
    if (!strWideChar.empty()) {
        int nNum = WideCharToMultiByte(CP_UTF8, 0, strWideChar.c_str(), -1, nullptr, 0, nullptr, FALSE);
        if (nNum) {
            char* utf8String = new char[nNum + 1];
            utf8String[0] = 0;
            
            nNum = WideCharToMultiByte(CP_UTF8, 0, strWideChar.c_str(), -1, utf8String, nNum + 1, nullptr, FALSE);
            
            ret = utf8String;
            delete[] utf8String;
        } else {
            CCLOG("Wrong convert to Utf8 code:0x%x", GetLastError());
        }
    }
    
    return ret;
}

static inline std::string convertPathFormatToUnixStyle(const std::string &path)
{
    std::string ret = path;
    int len = ret.length();
    for (int i = 0; i < len; ++i) {
        if (ret[i] == '\\') {
            ret[i] = '/';
        }
    }
    return ret;
}

const std::string __filesystem_getAppDataDirectory()
{
    WCHAR app_path[CC_MAX_PATH + 1] = { 0 };
    ::GetModuleFileName(nullptr, app_path, CC_MAX_PATH + 1);
    std::string path = convertPathFormatToUnixStyle(StringWideCharToUtf8(app_path));
    return path.substr(0, path.find_last_of('/'));
}

const std::string __filesystem_getDocumentDirectory()
{
    return xgame::filesystem::getWritablePath() + "/Documents";
}

const std::string __filesystem_getCacheDirectory()
{
    return xgame::filesystem::getWritablePath() + "/Cache";
}

const std::string __filesystem_getTmpDirectory()
{
    return xgame::filesystem::getWritablePath() + "/Tmp";
}

#endif

NS_XGAME_END
