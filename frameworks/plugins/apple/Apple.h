#ifndef __CCLUA_PLUGIN_APPLE_H__
#define __CCLUA_PLUGIN_APPLE_H__

#include "cclua/plugin.h"

#include <string>
#include <set>
#include <functional>
#include <unordered_map>

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)

NS_CCLUA_PLUGIN_BEGIN

class AppleAuth {
public:
    typedef std::function<void(const cocos2d::ValueMap &map)> AuthCallback;
    
    static bool canMakeAuth();
    static void auth(const AuthCallback &callback);
};

class AppleIAP {
public:
    static bool canMakePayments();
    static void requestProducts(const std::set<std::string> &products);
    static void purchase(const std::string &product, uint32_t quantify = 1);
    static void finishTransaction(const std::string &tid);
    static void restoreCompletedTransactions();
    static cocos2d::ValueVector getPendingTransactions();
    
    DISPATCHER_IMPL
};

NS_CCLUA_PLUGIN_END

#endif // CCLUA_OS_IOS

#endif // __CCLUA_PLUGIN_APPLE_H__
