#ifndef __CCLUA_PLUGIN_IOS_H__
#define __CCLUA_PLUGIN_IOS_H__

#import "cclua/plugin.h"

#import <Foundation/Foundation.h>

NS_CCLUA_PLUGIN_BEGIN

static NSString *toNSString(const std::string &value)
{
    return [NSString stringWithUTF8String:value.c_str()];
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
