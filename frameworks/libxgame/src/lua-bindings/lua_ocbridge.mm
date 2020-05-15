#import "lua_ocbridge.h"
#import <Foundation/Foundation.h>
#import <objc/runtime.h>

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC

#define is(T) (strcmp(type, @encode(T)) == 0)

/**
 * local luaoc = require "xgame.luaoc"
 * local util = require "xgame.util"
 * local LuaObjectCBridgeTest = luaoc.new('LuaObjectCBridgeTest')
 * print('addTwoNumbers', LuaObjectCBridgeTest.addTwoNumbers(function () end, 4))
 * print('print', LuaObjectCBridgeTest.print("print", {a=3, b='c'}))
 * print('testDict', util.dump(LuaObjectCBridgeTest.testDict(3, 3.4, {a = 5, b = 6, c = 'c'})))
 *
 */
@interface LuaObjectCBridgeTest : NSObject {
}
+ (void) hello;
+ (int) addTwoNumbers:(int)b other:(int)a;
+ (NSString *)print:(NSString *)str info:(NSDictionary *)dict;
+ (NSDictionary *)testDict:(NSNumber *)a b:(float)b info:(NSDictionary *)dict;
@end

@implementation LuaObjectCBridgeTest
+ (void) hello
{
    
}

+ (int) addTwoNumbers:(int) b other:(int) a
{
    return a + b;
}

+ (NSString *)print:(NSString *)str info:(NSDictionary *)dict
{
    return @"hello print";
}

+ (NSDictionary *)testDict:(NSNumber *)a b:(float)b info:(NSDictionary *)dict
{
    return dict;
}
@end

static void _push_value(lua_State *L, void *val)
{
    id value = (__bridge id)val;
    if (value == nil)
    {
        lua_pushnil(L);
    }
    else if ([value isKindOfClass:[NSNumber class]])
    {
        NSNumber *number = (NSNumber *)value;
        const char *type = [number objCType];
        if (is(BOOL))
        {
            lua_pushboolean(L, [number boolValue]);
        }
        else if (is(char))
        {
            lua_pushinteger(L, [number charValue]);
        }
        else if (is(unsigned char))
        {
            lua_pushinteger(L, [number unsignedCharValue]);
        }
        else if (is(short))
        {
            lua_pushinteger(L, [number shortValue]);
        }
        else if (is(unsigned short))
        {
            lua_pushinteger(L, [number unsignedShortValue]);
        }
        else if (is(int))
        {
            lua_pushinteger(L, [number intValue]);
        }
        else if (is(unsigned int))
        {
            lua_pushinteger(L, [number unsignedIntValue]);
        }
        else if (is(long))
        {
            lua_pushinteger(L, [number longValue]);
        }
        else if (is(unsigned long))
        {
            lua_pushinteger(L, [number unsignedLongValue]);
        }
        else if (is(long long))
        {
            lua_pushinteger(L, [number longLongValue]);
        }
        else if (is(unsigned long long))
        {
            lua_pushinteger(L, [number unsignedLongLongValue]);
        }
        else if (is(float))
        {
            lua_pushinteger(L, [number floatValue]);
        }
        else
        {
            lua_pushnumber(L, [number doubleValue]);
        }
    }
    else if ([value isKindOfClass:[NSString class]])
    {
        lua_pushstring(L, [(NSString *)value UTF8String]);
    }
    else if ([value isKindOfClass:[NSDictionary class]])
    {
        lua_newtable(L);
        
        for (id key in value)
        {
            const char *valueKey = [[NSString stringWithFormat:@"%@", key] UTF8String];
            lua_pushstring(L, valueKey);
            _push_value(L,  (__bridge void *)[value objectForKey:key]);
            lua_rawset(L, -3);
        }
    }
    else
    {
        lua_pushstring(L, [[NSString stringWithFormat:@"%@", value] UTF8String]);
    }
}

static void _table_to_dictionary(lua_State *L, NSMutableDictionary *dict, int idx){
    lua_pushnil(L);
    idx = lua_absindex(L, idx);
    while(lua_next(L, idx))
    {
        NSString *key2 = [NSString stringWithUTF8String:olua_tostring(L, -2)];
        switch (lua_type(L, -1))
        {
            case LUA_TNUMBER:
                if (olua_isinteger(L, -1)) {
                    [dict setObject:[NSNumber numberWithLongLong:olua_tointeger(L, -1)] forKey:key2];
                } else {
                    [dict setObject:[NSNumber numberWithDouble:olua_tonumber(L, -1)] forKey:key2];
                }
                break;
            case LUA_TBOOLEAN:
                [dict setObject:[NSNumber numberWithBool:olua_toboolean(L, -1)] forKey:key2];
                break;
            case LUA_TSTRING:
                [dict setObject:[NSString stringWithUTF8String:olua_tostring(L, -1)] forKey:key2];
                break;
            case LUA_TTABLE:
                NSMutableDictionary *newDict = [NSMutableDictionary dictionary];
                _table_to_dictionary(L, newDict, lua_absindex(L, -1));
                break;
        }
        lua_pop(L,1);
    }
}

static void _set_argument(lua_State *L, NSMethodSignature *methodSig, NSInvocation *invocation, int idx, int arg)
{
    const char *type = [methodSig getArgumentTypeAtIndex:arg];
    if (is(BOOL))
    {
        BOOL value = (BOOL)olua_checkboolean(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(char))
    {
        char value = (char)olua_checkinteger(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(unsigned char))
    {
        unsigned char value = (unsigned char)olua_checkinteger(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(short))
    {
        short value = (short)olua_checkinteger(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(unsigned short))
    {
        unsigned short value = (unsigned short)olua_checkinteger(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(int))
    {
        int value;
        if (olua_isfunction(L, idx)) {
            value = olua_reffunc(L, idx);
        } else {
            value = (int)olua_checkinteger(L, idx);
        }
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(unsigned int))
    {
        unsigned int value = (unsigned int)olua_checkinteger(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(long))
    {
        long value = (long)olua_checkinteger(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(unsigned long))
    {
        unsigned long value = (unsigned long)olua_checkinteger(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(long long))
    {
        long long value = (long long)olua_checkinteger(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(unsigned long long))
    {
        unsigned long long value = (unsigned long long)olua_checkinteger(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(float))
    {
        float value = (float)olua_checknumber(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(double))
    {
        double value = (double)olua_checknumber(L, idx);
        [invocation setArgument:&value atIndex:arg];
    }
    else if (is(NSObject *)) // NS Object
    {
        if (olua_istable(L, idx))
        {
            NSMutableDictionary *value = [NSMutableDictionary dictionary];
            _table_to_dictionary(L, value, idx);
            [invocation setArgument:&value atIndex:arg];
        }
        else if (olua_isnumber(L, idx))
        {
            NSNumber *value = [NSNumber numberWithDouble:olua_checknumber(L, idx)];
            [invocation setArgument:&value atIndex:arg];
        }
        else if (olua_isstring(L, idx))
        {
            NSString *value = [NSString stringWithUTF8String:olua_checkstring(L, idx)];
            [invocation setArgument:&value atIndex:arg];
        }
        else
        {
            luaL_error(L, "argment %d expected 'table|string|number', got '%s'",
                idx, olua_typename(L, idx));
        }
    }
    else
    {
        luaL_error(L, "not support type: %s", type);
    }
}

static SEL _find_selector(lua_State *L, Class cls, const char *method)
{
    unsigned int count;
    SEL selector = (SEL)0;
    NSString *prefix = [NSString stringWithUTF8String:method];
    Method *methods = class_copyMethodList(object_getClass(cls), &count);
    for (int i = 0; i < count; i++)
    {
        Method method = methods[i];
        selector = method_getName(method);
        NSString *name = NSStringFromSelector(selector);
        if ([name hasPrefix:prefix]) {
            break;
        } else {
            selector = (SEL)0;
        }
    }
    free(methods);
    return selector;
}

static int _invoke(lua_State *L)
{
    @autoreleasepool {
        int argc = lua_gettop(L) - 3;
        const char *cls = olua_checkstring(L, 1);
        const char *method = olua_checkstring(L, 2);
        
        Class targetClass = NSClassFromString([NSString stringWithUTF8String:cls]);
        if (!targetClass)
        {
            luaL_error(L, "class not found: %s", cls);
        }
        
        SEL methodSelector;
        if (olua_isnil(L, 3)) {
            methodSelector = _find_selector(L, targetClass, method);
        } else {
            methodSelector = NSSelectorFromString([NSString stringWithUTF8String:olua_checkstring(L, 3)]);
        }
        if (methodSelector == (SEL)0)
        {
            luaL_error(L, "method not found: %s.%s", cls, method);
        }
        
        NSMethodSignature *methodSig = [targetClass methodSignatureForSelector:(SEL)methodSelector];
        if (methodSig == nil)
        {
            luaL_error(L, "method not found: %s.%s", cls, method);
        }
        
        @try
        {
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSig];
            [invocation setTarget:targetClass];
            [invocation setSelector:methodSelector];
            
            if (argc > 0)
            {
                if (([methodSig numberOfArguments] - 2) != argc)
                {
                    luaL_error(L, "arguments count expected '%d', got '%d' for %s.%s",
                        (int)[methodSig numberOfArguments], argc, cls, method);
                }
                for (int i = 0; i < argc; i++) {
                    _set_argument(L, methodSig, invocation, i + 4, i + 2);
                }
            }
            
            [invocation invoke];
            
            lua_pushnil(L);
            
            if ([methodSig methodReturnLength] > 0)
            {
                const char *type = [methodSig methodReturnType];
                if (is(id))
                {
                    void *ret;
                    [invocation getReturnValue:&ret];
                    _push_value(L, ret);
                }
                else if (is(BOOL))
                {
                    BOOL ret;
                    [invocation getReturnValue:&ret];
                    lua_pushboolean(L, ret);
                }
                else if (is(char))
                {
                    char ret;
                    [invocation getReturnValue:&ret];
                    lua_pushinteger(L, ret);
                }
                else if (is(unsigned char))
                {
                    unsigned char ret;
                    [invocation getReturnValue:&ret];
                    lua_pushinteger(L, ret);
                }
                else if (is(short))
                {
                    short ret;
                    [invocation getReturnValue:&ret];
                    lua_pushinteger(L, ret);
                }
                else if (is(unsigned short))
                {
                    unsigned short ret;
                    [invocation getReturnValue:&ret];
                    lua_pushinteger(L, ret);
                }
                else if (is(int))
                {
                    int ret;
                    [invocation getReturnValue:&ret];
                    lua_pushinteger(L, ret);
                }
                else if (is(unsigned int))
                {
                    unsigned int ret;
                    [invocation getReturnValue:&ret];
                    lua_pushinteger(L, ret);
                }
                else if (is(long))
                {
                    long ret;
                    [invocation getReturnValue:&ret];
                    lua_pushinteger(L, ret);
                }
                else if (is(unsigned long))
                {
                    unsigned long ret;
                    [invocation getReturnValue:&ret];
                    lua_pushinteger(L, ret);
                }
                else if (is(long long))
                {
                    long long ret;
                    [invocation getReturnValue:&ret];
                    lua_pushinteger(L, ret);
                }
                else if (is(unsigned long long))
                {
                    unsigned long long ret;
                    [invocation getReturnValue:&ret];
                    lua_pushinteger(L, ret);
                }
                else if (is(float))
                {
                    float ret;
                    [invocation getReturnValue:&ret];
                    lua_pushnumber(L, ret);
                }
                else if (is(double))
                {
                    double ret;
                    [invocation getReturnValue:&ret];
                    lua_pushnumber(L, ret);
                }
                else
                {
                    luaL_error(L, "return type not support: %s", type);
                }
            }
            else
            {
                lua_pushnil(L);
            }
        }
        @catch (NSException *exception)
        {
            NSString *error = [NSString stringWithFormat: @"invoke error: %@", exception];
            luaL_error(L, [error UTF8String]);
        }
    }
    
    return 1;
}

static int _selectors(lua_State *L)
{
    @autoreleasepool {
        const char *cls = olua_checkstring(L, 1);
        
        Class targetClass = NSClassFromString([NSString stringWithUTF8String:cls]);
        if (!targetClass)
        {
            luaL_error(L, "class not found: %s", cls);
        }
        
        unsigned int count;
        Method *methods = class_copyMethodList(object_getClass(targetClass), &count);
        lua_createtable(L, 0, count);
        for (int i = 0; i < count; i++)
        {
            Method method = methods[i];
            SEL selector = method_getName(method);
            NSString *name = NSStringFromSelector(selector);
            const char *cname = [name UTF8String];
            const char *sep = strchr(cname, ':');
            if (sep)
            {
                lua_pushlstring(L, cname, sep - cname);
            }
            else
            {
                lua_pushstring(L, cname);
            }
            lua_pushstring(L, cname);
            lua_rawset(L, -3);
        }
        free(methods);
    }
    return 1;
}

int luaopen_ocbridge(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"invoke", _invoke},
        {"selectors", _selectors},
        {NULL, NULL}
    };
    
    luaL_newlib(L, lib);

    return 1;
}

#endif
