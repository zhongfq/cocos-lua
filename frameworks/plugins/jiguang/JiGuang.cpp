#include "JiGuang.h"

#ifdef CCLUA_OS_ANDROID
#include "platform/android/jni/JniHelper.h"
#include "cjson/cJSON.h"

NS_XPLUGIN_BEGIN

#define JAVA_JPUSH_CLASS        "kernel/plugin/jiguang/JPush"
#define JAVA_JANALYTICS_CLASS   "kernel/plugin/jiguang/JAnalytics"

USING_NS_CC;

#ifdef CCLUA_BUILD_JPUSH

void JPush::init(const std::string &appKey, const std::string &channel)
{
    JniHelper::callStaticVoidMethod(JAVA_JPUSH_CLASS, "init", appKey, channel);
}

void JPush::setAlias(const std::string &alias)
{
    JniHelper::callStaticVoidMethod(JAVA_JPUSH_CLASS, "setAlias", alias);
}

void JPush::deleteAlias()
{
    JniHelper::callStaticVoidMethod(JAVA_JPUSH_CLASS, "deleteAlias");
}

static std::string toJsonString(const std::set<std::string> &tags)
{
    cJSON *arr = cJSON_CreateArray();
    for (auto iter : tags) {
        cJSON_AddItemToArray(arr, cJSON_CreateString(iter.c_str()));
    }
    std::string result = cJSON_PrintUnformatted(arr);
    runtime::log("[DEBUG] toJsonString: %s", result.c_str());
    cJSON_Delete(arr);
    return result;
}

void JPush::addTags(const std::set<std::string> &tags)
{
    JniHelper::callStaticVoidMethod(JAVA_JPUSH_CLASS, "addTags", toJsonString(tags));
}

void JPush::setTags(const std::set<std::string> &tags)
{
    JniHelper::callStaticVoidMethod(JAVA_JPUSH_CLASS, "setTags", toJsonString(tags));
}

void JPush::deleteTags(const std::set<std::string> &tags)
{
    JniHelper::callStaticVoidMethod(JAVA_JPUSH_CLASS, "deleteTags", toJsonString(tags));
}

void JPush::cleanTags()
{
    JniHelper::callStaticVoidMethod(JAVA_JPUSH_CLASS, "cleanTags");
}

void JPush::setDebug(bool enabled)
{
    JniHelper::callStaticVoidMethod(JAVA_JPUSH_CLASS, "setDebugMode", enabled);
}

void JPush::setLogOFF()
{
    JniHelper::callStaticVoidMethod(JAVA_JPUSH_CLASS, "setLogOFF");
}

void JPush::setBadge(int value)
{
    JniHelper::callStaticVoidMethod(JAVA_JPUSH_CLASS, "setBadge", value);
}

bool JPush::isEnabled()
{
    return JniHelper::callStaticBooleanMethod(JAVA_JPUSH_CLASS, "isEnabled");
}

void JPush::requestPermission()
{
    JniHelper::callStaticVoidMethod(JAVA_JPUSH_CLASS, "requestPermission");
}

std::string JPush::getRegistrationID()
{
    return JniHelper::callStaticStringMethod(JAVA_JPUSH_CLASS, "getRegistrationID");
}
#endif

#ifdef CCLUA_BUILD_JANALYTICS
void JAnalytics::init(const std::string &appKey, const std::string &channel)
{
    JniHelper::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "init", appKey, channel);
}

void JAnalytics::startTrackPage(const std::string &pageName)
{
    JniHelper::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "startTrackPage", pageName);
}

void JAnalytics::stopTrackPage(const std::string &pageName)
{
    JniHelper::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "stopTrackPage", pageName);
}

void JAnalytics::trackEvent(EventType type, cocos2d::ValueMap &value)
{
    cJSON *obj = cJSON_CreateObject();
    std::string event;
    switch (type) {
        case EventType::LOGIN: {
            event = "LOGIN";
            cJSON_AddStringToObject(obj, "method", value["method"].asString().c_str());
            cJSON_AddBoolToObject(obj, "success", value["success"].asBool());
            break;
        }
        case EventType::REGISTER: {
            event = "REGISTER";
            cJSON_AddStringToObject(obj, "method", value["method"].asString().c_str());
            cJSON_AddBoolToObject(obj, "success", value["success"].asBool());
            break;
        }
        case EventType::PURCHASE: {
            event = "PURCHASE";
            cJSON_AddNumberToObject(obj, "price", value["price"].asDouble());
            cJSON_AddBoolToObject(obj, "success", value["success"].asBool());
            cJSON_AddStringToObject(obj, "id", value["id"].asString().c_str());
            cJSON_AddStringToObject(obj, "name", value["name"].asString().c_str());
            cJSON_AddStringToObject(obj, "type", value["type"].asString().c_str());
            cJSON_AddStringToObject(obj, "currency", value["currency"].asString() == "CNY" ? "CNY" : "USD");
            cJSON_AddNumberToObject(obj, "quantity", value["quantity"].asDouble());
            break;
        }
        case EventType::BROWSE: {
            event = "BROWSE";
            cJSON_AddStringToObject(obj, "name", value["name"].asString().c_str());
            cJSON_AddStringToObject(obj, "id", value["id"].asString().c_str());
            cJSON_AddStringToObject(obj, "type", value["type"].asString().c_str());
            cJSON_AddNumberToObject(obj, "duration", value["duration"].asDouble());
            break;
        }
        case EventType::COUNT: {
            event = "COUNT";
            cJSON_AddStringToObject(obj, "id", value["id"].asString().c_str());
            break;
        }
        case EventType::CALCULATE: {
            event = "CALCULATE";
            cJSON_AddStringToObject(obj, "id", value["id"].asString().c_str());
            cJSON_AddNumberToObject(obj, "value", value["value"].asDouble());
            break;
        }
    }

    if (value["extra"].getType() == cocos2d::Value::Type::MAP) {
        cocos2d::ValueMap &map = value["extra"].asValueMap();
        cJSON *extra = cJSON_CreateObject();
        cJSON_AddItemToObject(obj, "extra", extra);
        for (auto it = map.begin(); it != map.end(); ++it) {
            cJSON_AddStringToObject(extra, it->first.c_str(), it->second.asString().c_str());
        }
    }

    cJSON_AddStringToObject(obj, "event", event.c_str());

    std::string info = cJSON_PrintUnformatted(obj);
    runtime::log("[DEBUG] info: %s", info.c_str());
    JniHelper::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "trackEvent", event, info);
    cJSON_Delete(obj);
}

void JAnalytics::identifyAccount(cocos2d::ValueMap &value)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "account", value["account"].asString().c_str());
    if (value.find("creationTime") != value.end()) {
        cJSON_AddNumberToObject(obj, "creationTime", value["creationTime"].asDouble());
    }
    if (value.find("sex") != value.end()) {
        cJSON_AddNumberToObject(obj, "sex", value["sex"].asInt());
    }
    if (value.find("birthday") != value.end()) {
        cJSON_AddStringToObject(obj, "birthday", value["birthday"].asString().c_str());
    }
    if (value.find("paid") != value.end()) {
        cJSON_AddNumberToObject(obj, "paid", value["paid"].asInt());
    }
    if (value.find("phone") != value.end()) {
        cJSON_AddStringToObject(obj, "phone", value["phone"].asString().c_str());
    }
    if (value.find("email") != value.end()) {
        cJSON_AddStringToObject(obj, "email", value["email"].asString().c_str());
    }
    if (value.find("name") != value.end()) {
        cJSON_AddStringToObject(obj, "name", value["name"].asString().c_str());
    }
    if (value.find("wechat") != value.end()) {
        cJSON_AddStringToObject(obj, "wechat", value["wechat"].asString().c_str());
    }
    if (value.find("qq") != value.end()) {
        cJSON_AddStringToObject(obj, "qq", value["qq"].asString().c_str());
    }
    if (value.find("weibo") != value.end()) {
        cJSON_AddStringToObject(obj, "weibo", value["weibo"].asString().c_str());
    }
    if (value["extras"].getType() == cocos2d::Value::Type::MAP) {
        cocos2d::ValueMap &map = value["extras"].asValueMap();
        cJSON *extras = cJSON_CreateObject();
        cJSON_AddItemToObject(obj, "extras", extras);
        for (auto it = map.begin(); it != map.end(); ++it) {
            switch (it->second.getType()) {
                case cocos2d::Value::Type::UNSIGNED:
                case cocos2d::Value::Type::INTEGER:
                case cocos2d::Value::Type::FLOAT:
                case cocos2d::Value::Type::DOUBLE:
                {
                    cJSON_AddNumberToObject(extras, it->first.c_str(), it->second.asDouble());
                    break;
                }
                case cocos2d::Value::Type::STRING:
                {
                    cJSON_AddStringToObject(extras, it->first.c_str(), it->second.asString().c_str());
                    break;
                }
                case cocos2d::Value::Type::NONE:
                {
                    cJSON_AddNullToObject(extras, it->first.c_str());
                    break;
                }
                default:
                    break;
            }
        }
    }
    std::string account = cJSON_PrintUnformatted(obj);
    runtime::log("[DEBUG] account: %s", account.c_str());
    JniHelper::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "identifyAccount", account);
    cJSON_Delete(obj);
}

void JAnalytics::detachAccount()
{
    JniHelper::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "detachAccount");
}

void JAnalytics::setFrequency(int frequency)
{
    JniHelper::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "setFrequency", frequency);
}

void JAnalytics::setDebug(bool enable)
{
    JniHelper::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "setDebug", enable);
}

#endif

NS_XPLUGIN_END

#endif
