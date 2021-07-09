#include "plugin.h"

NS_CCLUA_PLUGIN_BEGIN

static void toJSONObject(cJSON *obj, cocos2d::ValueMap &map);

static void toJSONArray(cJSON *obj, cocos2d::ValueVector &arr)
{
    for (auto &value : arr) {
        switch(value.getType()) {
            case cocos2d::Value::Type::BOOLEAN: {
                cJSON_AddItemToArray(obj, cJSON_CreateBool(value.asBool()));
                break;
            }
            case cocos2d::Value::Type::STRING: {
                cJSON_AddItemToArray(obj, cJSON_CreateString(value.asString().c_str()));
                break;
            }
            case cocos2d::Value::Type::VECTOR: {
                cJSON *item = cJSON_CreateArray();
                toJSONArray(item, value.asValueVector());
                cJSON_AddItemToArray(obj, item);
                break;
            }
            case cocos2d::Value::Type::NONE: {
                cJSON_AddItemToArray(obj, cJSON_CreateNull());
                break;
            }
            case cocos2d::Value::Type::MAP: {
                cJSON *item = cJSON_CreateObject();
                toJSONObject(item, value.asValueMap());
                cJSON_AddItemToArray(obj, item);
                break;
            }
            case cocos2d::Value::Type::BYTE:
            case cocos2d::Value::Type::DOUBLE:
            case cocos2d::Value::Type::FLOAT:
            case cocos2d::Value::Type::INTEGER:
            case cocos2d::Value::Type::UNSIGNED: {
                cJSON_AddItemToArray(obj, cJSON_CreateNumber(value.asDouble()));
                break;
            }
            default:
                break;
        }
    }
}

static void toJSONObject(cJSON *obj, cocos2d::ValueMap &map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        const char *key = it->first.c_str();
        cocos2d::Value &value = it->second;
        switch(value.getType()) {
            case cocos2d::Value::Type::BOOLEAN: {
                cJSON_AddBoolToObject(obj, key, value.asBool());
                break;
            }
            case cocos2d::Value::Type::STRING: {
                cJSON_AddStringToObject(obj, key, value.asString().c_str());
                break;
            }
            case cocos2d::Value::Type::VECTOR: {
                cJSON *item = cJSON_CreateArray();
                toJSONArray(item, value.asValueVector());
                cJSON_AddItemToObject(obj, key, item);
                break;
            }
            case cocos2d::Value::Type::NONE: {
                cJSON_AddNullToObject(obj, key);
                break;
            }
            case cocos2d::Value::Type::MAP: {
                cJSON *item = cJSON_CreateObject();
                toJSONObject(item, value.asValueMap());
                cJSON_AddItemToObject(obj, key, item);
                break;
            }
            case cocos2d::Value::Type::BYTE:
            case cocos2d::Value::Type::DOUBLE:
            case cocos2d::Value::Type::FLOAT:
            case cocos2d::Value::Type::INTEGER:
            case cocos2d::Value::Type::UNSIGNED: {
                cJSON_AddNumberToObject(obj, key, value.asDouble());
                break;
            }
            default:
                break;
        }
    }
}

std::string toJSONString(const cocos2d::ValueMap &value)
{
    cJSON *obj = cJSON_CreateObject();
    toJSONObject(obj, const_cast<cocos2d::ValueMap &>(value));
    std::string result = cJSON_PrintUnformatted(obj);
    cJSON_Delete(obj);
    return result;
}

std::string toJSONString(const std::set<std::string> &tags)
{
    cJSON *arr = cJSON_CreateArray();
    for (auto iter : tags) {
        cJSON_AddItemToArray(arr, cJSON_CreateString(iter.c_str()));
    }
    std::string result = cJSON_PrintUnformatted(arr);
    cJSON_Delete(arr);
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
