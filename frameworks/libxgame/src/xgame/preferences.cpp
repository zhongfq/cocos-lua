#include "xgame/preferences.h"
#include "xgame/timer.h"

#include "cocos2d.h"

USING_NS_CC;

NS_XGAME_BEGIN

bool preferences::getBoolean(const char *key, bool defaultValue)
{
    return UserDefault::getInstance()->getBoolForKey(key, defaultValue);
}

void preferences::setBoolean(const char *key, bool value)
{
    UserDefault::getInstance()->setBoolForKey(key, value);
    preferences::delayFlush();
}

float preferences::getFloat(const char *key, float defaultValue)
{
    return UserDefault::getInstance()->getFloatForKey(key, defaultValue);
}

void preferences::setFloat(const char *key, float value)
{
    UserDefault::getInstance()->setFloatForKey(key, value);
    preferences::delayFlush();
}

double preferences::getDouble(const char *key, double defaultValue)
{
    return UserDefault::getInstance()->getDoubleForKey(key, defaultValue);
}

void preferences::setDouble(const char *key, double value)
{
    UserDefault::getInstance()->setDoubleForKey(key, value);
    preferences::delayFlush();
}

int preferences::getInteger(const char *key, int defaultValue)
{
    return UserDefault::getInstance()->getIntegerForKey(key, defaultValue);
}

void preferences::setInteger(const char *key, int value)
{
    UserDefault::getInstance()->setIntegerForKey(key, value);
    preferences::delayFlush();
}

std::string preferences::getString(const char *key, const char *defaultValue)
{
    return UserDefault::getInstance()->getStringForKey(key, defaultValue);
}

void preferences::setString(const char *key, const char *value)
{
    UserDefault::getInstance()->setStringForKey(key, value);
    preferences::delayFlush();
}

void preferences::deleteKey(const char *key)
{
    UserDefault::getInstance()->deleteValueForKey(key);
}

void preferences::flush()
{
    UserDefault::getInstance()->flush();
}

void preferences::delayFlush()
{
#define TAG_FLUSH "preferences::delayFlush"
    timer::killDelay(TAG_FLUSH);
    timer::delayWithTag(0.001f, TAG_FLUSH, [](){ preferences::flush(); });
}

NS_XGAME_END
