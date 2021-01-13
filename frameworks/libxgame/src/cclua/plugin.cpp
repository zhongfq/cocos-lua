#include "plugin.h"

NS_CCLUA_PLUGIN_BEGIN

std::string toJSONString(cocos2d::ValueMap &value)
{
    cJSON *obj = cJSON_CreateObject();

    std::string result = cJSON_PrintUnformatted(obj);
    cJSON_Delete(obj);
    return result;
}

static void parseJSONOArray(cJSON *obj, cocos2d::ValueVector &result);

static void parseJSONObject(cJSON *obj, cocos2d::ValueMap &result)
{
    cJSON *child = obj->child;
    while(child) {
        switch(child->type) {
            case cJSON_False: {
                result[child->string] = false;
                break;
            }
            case cJSON_True: {
                result[child->string] = true;
                break;
            }
            case cJSON_NULL: {
                result[child->string] = cocos2d::Value();
                break;
            }
            case cJSON_Number: {
                result[child->string] = child->valuedouble;
                break;
            }
            case cJSON_String: {
                result[child->string] = child->valuestring;
                break;
            }
            case cJSON_Array: {
                result[child->string] = cocos2d::ValueVector();
                parseJSONOArray(child, result[child->string].asValueVector());
                break;
            }
            case cJSON_Object: {
                result[child->string] = cocos2d::ValueMap();
                parseJSONObject(child, result[child->string].asValueMap());
                break;
            }
        }
        child = child->next;
    }
}

static void parseJSONOArray(cJSON *obj, cocos2d::ValueVector &result)
{
    int len = cJSON_GetArraySize(obj);
    for (int i = 0; i < len; i++) {
        cJSON *c = cJSON_GetArrayItem(obj, i);
        switch(c->type) {
            case cJSON_False: {
                result.push_back(cocos2d::Value(false));
                break;
            }
            case cJSON_True: {
                result.push_back(cocos2d::Value(true));
                break;
            }
            case cJSON_NULL: {
                result.push_back(cocos2d::Value());
                break;
            }
            case cJSON_Number: {
                result.push_back(cocos2d::Value(c->valuedouble));
                break;
            }
            case cJSON_String: {
                result.push_back(cocos2d::Value(c->valuestring));
                break;
            }
            case cJSON_Array: {
                result.push_back(cocos2d::Value(cocos2d::ValueVector()));
                parseJSONOArray(c, result[i].asValueVector());
                break;
            }
            case cJSON_Object: {
                result.push_back(cocos2d::Value(cocos2d::ValueMap()));
                parseJSONObject(c, result[i].asValueMap());
                break;
            }
        }
    }
}

void parseJSONString(const std::string &value, cocos2d::ValueMap &result)
{
    cJSON *obj = cJSON_Parse(value.c_str());
    if (!obj) {
        return;
    }
    parseJSONObject(obj, result);
    cJSON_Delete(obj);
}

NS_CCLUA_PLUGIN_END
