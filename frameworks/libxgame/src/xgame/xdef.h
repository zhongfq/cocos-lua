#ifndef __XDEF_H__
#define __XDEF_H__

#include "platform/CCPlatformConfig.h"

#include <string.h>
#include <stdio.h>

#include <stdint.h>

#define NS_XGAME_BEGIN  namespace xgame {
#define NS_XGAME_END    }
#define USING_NS_XGAME using namespace xgame
#define USING_NS_CC_EXP using namespace cocos2d::experimental

#define strequal(str1, str2)           (strcmp(str1, str2) == 0)
#define strnequal(str1, str2, len)     (strncmp(str1, str2, len) == 0)

#ifdef _WIN32
#define strcaseequal(str1, str2) (_stricmp(str1, str2) == 0)
#define strncaseequal(str1, str2, len) (_strnicmp(str1, str2) == 0)
#else
#define strcaseequal(str1, str2)       (strcasecmp(str1, str2) == 0)
#define strncaseequal(str1, str2, len) (strncasecmp(str1, str2) == 0)
#endif

#define BOOL_STR(b) ((b) ? "OK" : "NO")

#define CONF_ANTIALIAS_ENABLED  "conf.antialias.enabled"
#define CONF_ANTIALIAS_SAMPLES  "conf.antialias.samples"
#define CONF_APP_VERSION        "conf.version.app"
#define CONF_APP_BUILD          "conf.version.build"
#define CONF_MANIFEST_VERSION   "conf.version.manifest"
#define CONF_WINDOW_WIDTH       "conf.window.width"
#define CONF_WINDOW_HEIGHT      "conf.window.height"

#define JAVA_APPCONTEXT_CLASS   "kernel/AppContext"

inline bool strstartwith(const char *src, const char *prefix)
{
    const char *pos = strstr(src, prefix);
    return pos == src;
}

inline bool strendwith(const char *src, const char *suffix)
{
    const char *pos = strstr(src, suffix);
    return !pos ? false : (src + strlen(src) == pos + strlen(suffix));
}

#endif
