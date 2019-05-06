#include "xgame/xfilesystem.h"
#include "xgame/xfilesystem-private.h"
#include "xgame/xruntime.h"

#include "cocos2d.h"

USING_NS_XGAME;
USING_NS_CC;

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32

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
    return filesystem::getWritablePath() + "/Documents";
}

const std::string __filesystem_getCacheDirectory()
{
    return filesystem::getWritablePath() + "/Cache";
}

const std::string __filesystem_getTmpDirectory()
{
    return filesystem::getWritablePath() + "/Tmp";
}

const std::string __filesystem_getSDCardDirectory()
{
    runtime::log("filesystem::getSDCardDirectory only support android");
    return "/";
}

#endif