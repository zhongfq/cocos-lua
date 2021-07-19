#ifndef __CCLUA_PLUGIN_IOS_H__
#define __CCLUA_PLUGIN_IOS_H__

#import "cclua/plugin.h"

#import <Foundation/Foundation.h>

NS_CCLUA_PLUGIN_BEGIN

static NSString *toNSString(const std::string &value)
{
    return [NSString stringWithUTF8String:value.c_str()];
}

static NSString *toNSString(const cocos2d::Value &value)
{
    return toNSString(value.asString());
}

static cocos2d::Value toValue(NSString *value)
{
    return value ? cocos2d::Value([value UTF8String]) : cocos2d::Value::Null;
}

static cocos2d::Value toValue(NSArray<NSString *> *value)
{
    cocos2d::ValueVector arr;
    for (int i = 0; i < value.count; i++) {
        arr.push_back(cocos2d::Value(toValue([value objectAtIndex: i])));
    }
    return cocos2d::Value(arr);
}

static cocos2d::Value toValue(NSData *value)
{
    return value ? cocos2d::Value([[[NSString alloc] initWithData:value encoding:NSUTF8StringEncoding] UTF8String]) : cocos2d::Value::Null;
}

static void setValueMap(cocos2d::ValueMap &map, const std::string &key, const cocos2d::Value &value)
{
    if (value != cocos2d::Value::Null) {
        map[key] = value;
    }
}

static NSObject *toNSObject(const cocos2d::Value &value)
{
    switch(value.getType())
    {
        case cocos2d::Value::Type::INTEGER:
            return [NSNumber numberWithInt:value.asInt()];
        case cocos2d::Value::Type::UNSIGNED:
            return [NSNumber numberWithUnsignedInt:value.asUnsignedInt()];
        case cocos2d::Value::Type::FLOAT:
            return [NSNumber numberWithFloat:value.asFloat()];
        case cocos2d::Value::Type::DOUBLE:
            return [NSNumber numberWithDouble:value.asDouble()];
        case cocos2d::Value::Type::BOOLEAN:
            return [NSNumber numberWithBool:value.asBool()];
        case cocos2d::Value::Type::STRING:
            return [NSString stringWithUTF8String:value.asString().c_str()];
        default:
            return nil;
    }
}

static NSSet<NSString *> *toNSSetString(const std::set<std::string> &tags)
{
    NSMutableSet<NSString*> *set = [[NSMutableSet alloc] init];
    for (auto itor : tags) {
        [set addObject:toNSString(itor)];
    }
    return set;
}

NS_CCLUA_PLUGIN_END

#endif
