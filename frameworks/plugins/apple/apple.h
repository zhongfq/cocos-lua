#ifndef __CCLUA_PLUGIN_APPLE_H__
#define __CCLUA_PLUGIN_APPLE_H__

#include "cclua/plugin.h"

NS_CCLUA_PLUGIN_BEGIN

class apple {
public:
    // auth
    static bool canMakeAuth();
    static void auth();
    
    // payment
    static bool canMakePayments();
    static void requestProducts(const std::set<std::string> &products);
    static void purchase(const std::string &product, uint32_t quantify = 1);
    static void finishTransaction(const std::string &tid);
    static void restoreTransactions(const std::string &appUsername = "");
    static cocos2d::ValueVector getPendingTransactions();
    
public:
    static void setDispatcher(const cclua::Callback &dispatcher)
    {
        _dispatcher = dispatcher;
    }
    
    static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    {
        cclua::runtime::runLater([=]() {
            if (_dispatcher) {
                _dispatcher(event, cocos2d::Value(data));
            }
        });
    }
    
private:
    static cclua::Callback _dispatcher;
};

NS_CCLUA_PLUGIN_END

#endif // __CCLUA_PLUGIN_APPLE_H__
