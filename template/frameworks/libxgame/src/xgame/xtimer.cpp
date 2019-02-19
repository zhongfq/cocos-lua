#include "xgame/xtimer.h"
#include "cocos2d.h"

NS_XGAME_BEGIN

USING_NS_CC;

void timer::schedule(float interval, const std::string &tag, const std::function<void (float)> callback)
{
    auto director = Director::getInstance();
    director->getScheduler()->schedule([=](float delta) {
        callback(delta);
    }, director, interval, false, tag);
}

void timer::unschedule(const std::string &tag)
{
    auto director = Director::getInstance();
    director->getScheduler()->unschedule(tag, director);
}

const std::string timer::createScheduleTag(unsigned int handler)
{
    char buf[128];
    snprintf(buf, sizeof(buf), "timer::schedule::%d", handler);
    return std::string(buf);
}

unsigned int timer::createScheduleHandler()
{
    static unsigned int ref = 0;
    return ++ref;
}

void timer::delayWithTag(float time, const std::string &tag, std::function<void ()> callback)
{
    timer::killDelay(tag);
    timer::schedule(time, tag, [=](float delta){
        timer::killDelay(tag);
        callback();
    });
}

void timer::killDelay(const std::string &tag)
{
    timer::unschedule(tag);
}

void timer::delay(float time, const std::function<void ()> callback)
{
    unsigned int handler = timer::createScheduleHandler();
    const std::string tag = timer::createScheduleTag(handler);
    timer::schedule(time, tag, [=](float delta){
        timer::killDelay(tag);
        callback();
    });
}

unsigned int timer::schedule(float interval, const std::function<void (float)> callback)
{
    unsigned int handler = timer::createScheduleHandler();
    const std::string tag = timer::createScheduleTag(handler);
    timer::schedule(fmax(0, interval), tag, callback);
    return handler;
}

void timer::unschedule(unsigned int handler)
{
    timer::unschedule(timer::createScheduleTag(handler));
}

NS_XGAME_END
