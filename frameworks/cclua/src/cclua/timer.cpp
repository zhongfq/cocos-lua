#include "cclua/timer.h"

NS_CCLUA_BEGIN

USING_NS_CC;

void timer::schedule(float interval, unsigned int repeat, const std::string &tag, const std::function<void (float)> callback)
{
    auto scheduler = Director::getInstance()->getScheduler();
    scheduler->schedule(callback, scheduler, interval, repeat, 0, false, tag);
}

std::string timer::createTag()
{
    static unsigned int s_count = 0;
    char buf[128];
    std::string tag;
    auto scheduler = Director::getInstance()->getScheduler();
    while (true) {
        snprintf(buf, sizeof(buf), "timer.tag%d", ++s_count);
        tag = std::string(buf);
        if (!scheduler->isScheduled(tag, scheduler)) {
            break;
        }
    }
    return tag;
}

void timer::delayWithTag(float time, const std::string &tag, std::function<void ()> callback)
{
    timer::killDelay(tag);
    timer::schedule(time, 0, tag, [=](float delta) {
        callback();
    });
}

void timer::killDelay(const std::string &tag)
{
    timer::unschedule(tag);
}

void timer::delay(float time, const std::function<void ()> callback)
{
    const std::string tag = timer::createTag();
    timer::schedule(time, 0, tag, [=](float delta) {
        callback();
    });
}

void timer::schedule(float interval, const std::string &tag, const std::function<void (float)> callback)
{
    timer::schedule(fmax(0.0f, interval), CC_REPEAT_FOREVER, tag, callback);
}

void timer::unschedule(const std::string &tag)
{
    auto scheduler = Director::getInstance()->getScheduler();
    scheduler->unschedule(tag, scheduler);
}

NS_CCLUA_END
