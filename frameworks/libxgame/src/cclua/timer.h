#ifndef __CCLUA_TIMER_H__
#define __CCLUA_TIMER_H__

#include "cclua/runtime.h"

#include <string>
#include <functional>

NS_CCLUA_BEGIN

class timer {
public:
    static std::string createTag();
    static void delay(float time, const std::function<void ()> callback);
    static void delayWithTag(float time, const std::string &tag, std::function<void ()> callback);
    static void killDelay(const std::string &tag);
    static unsigned int schedule(float interval, const std::function<void (float)> callback);
    static void unschedule(unsigned int id);
private:
    static void schedule(float interval, unsigned int repeat, const std::string &tag, const std::function<void (float)> callback);
    static void unschedule(const std::string &tag);
    static const std::string createScheduleTag(unsigned int handler);
    static unsigned int createScheduleHandler();
};

NS_CCLUA_END

#endif
