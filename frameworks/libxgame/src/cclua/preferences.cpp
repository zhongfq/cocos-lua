#include "cclua/preferences.h"
#include "cclua/timer.h"
#include "cocos2d.h"

USING_NS_CC;

NS_CCLUA_BEGIN

bool preferences::getBoolean(const std::string &key, bool defaultValue)
{
    return UserDefault::getInstance()->getBoolForKey(key.c_str(), defaultValue);
}

void preferences::setBoolean(const std::string &key, bool value)
{
    UserDefault::getInstance()->setBoolForKey(key.c_str(), value);
    preferences::delayFlush();
}

float preferences::getFloat(const std::string &key, float defaultValue)
{
    return UserDefault::getInstance()->getFloatForKey(key.c_str(), defaultValue);
}

void preferences::setFloat(const std::string &key, float value)
{
    UserDefault::getInstance()->setFloatForKey(key.c_str(), value);
    preferences::delayFlush();
}

double preferences::getDouble(const std::string &key, double defaultValue)
{
    return UserDefault::getInstance()->getDoubleForKey(key.c_str(), defaultValue);
}

void preferences::setDouble(const std::string &key, double value)
{
    UserDefault::getInstance()->setDoubleForKey(key.c_str(), value);
    preferences::delayFlush();
}

int preferences::getInteger(const std::string &key, int defaultValue)
{
    return UserDefault::getInstance()->getIntegerForKey(key.c_str(), defaultValue);
}

void preferences::setInteger(const std::string &key, int value)
{
    UserDefault::getInstance()->setIntegerForKey(key.c_str(), value);
    preferences::delayFlush();
}

std::string preferences::getString(const std::string &key, const std::string &defaultValue)
{
    return UserDefault::getInstance()->getStringForKey(key.c_str(), defaultValue);
}

void preferences::setString(const std::string &key, const std::string &value)
{
    UserDefault::getInstance()->setStringForKey(key.c_str(), value);
    preferences::delayFlush();
}

void preferences::deleteKey(const std::string &key)
{
    UserDefault::getInstance()->deleteValueForKey(key.c_str());
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

NS_CCLUA_END
