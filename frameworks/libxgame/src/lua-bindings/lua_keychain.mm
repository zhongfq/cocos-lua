#include "lua_keychain.h"

#ifdef CCLUA_OS_IOS

#import <Foundation/Foundation.h>
#import <Security/Security.h>

static NSMutableDictionary* _get_keychain_query(NSString *key)
{
    return [NSMutableDictionary dictionaryWithObjectsAndKeys:
            (id)kSecClassGenericPassword, (id)kSecClass,
            key, (id)kSecAttrService,
            key, (id)kSecAttrAccount,
            (id)kSecAttrAccessibleAfterFirstUnlock, (id)kSecAttrAccessible,
            nil];
}

static int _set_string(lua_State *L)
{
    @autoreleasepool {
        NSString *key = [NSString stringWithUTF8String:luaL_checkstring(L, 1)];
        NSString *value = [NSString stringWithUTF8String:luaL_checkstring(L, 2)];
        NSMutableDictionary *keychain_query = _get_keychain_query(key);
        SecItemDelete((CFDictionaryRef)keychain_query);
        [keychain_query setObject:[value dataUsingEncoding:NSUTF8StringEncoding] forKey:(id)kSecValueData];
        SecItemAdd((CFDictionaryRef)keychain_query, NULL);
    }
    return 0;
}


static int _get_string(lua_State *L)
{
    @autoreleasepool {
        NSString *key = [NSString stringWithUTF8String:luaL_checkstring(L, 1)];
        NSMutableDictionary *keychain_query = _get_keychain_query(key);
        [keychain_query setObject:(id)kCFBooleanTrue forKey:(id)kSecReturnData];
        [keychain_query setObject:(id)kSecMatchLimitOne forKey:(id)kSecMatchLimit];
        CFDataRef key_data = NULL;
        NSString *value = nil;
        if (SecItemCopyMatching((CFDictionaryRef)keychain_query, (CFTypeRef *)&key_data) == noErr) {
            value = [[NSString alloc] initWithData:(__bridge NSData *)key_data encoding:NSUTF8StringEncoding];
        }
        
        if (key_data) {
            CFRelease(key_data);
        }
        
        if (value) {
            lua_pushstring(L, [value UTF8String]);
        } else {
            lua_pushnil(L);
        }
    }
    return 1;
}

static int _delete_key(lua_State *L)
{
    @autoreleasepool {
        NSString *key = [NSString stringWithUTF8String:luaL_checkstring(L, 1)];
        NSMutableDictionary *keychain_query = _get_keychain_query(key);
        SecItemDelete((CFDictionaryRef)keychain_query);
    }
    return 1;
}

int luaopen_keychain(lua_State *L)
{
    static const luaL_Reg lib[] = {
        {"getString", _get_string},
        {"setString", _set_string},
        {"deleteKey", _delete_key},
        {NULL, NULL}
    };
    
    luaL_newlib(L, lib);
    
    return 1;
}

#endif
