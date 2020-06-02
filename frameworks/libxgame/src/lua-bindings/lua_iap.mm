#include "lua_iap.h"
#include "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#import "xgame/PluginConnector.h"
#import <StoreKit/StoreKit.h>

@interface IAPConnector : PluginConnector<SKPaymentTransactionObserver, SKRequestDelegate, SKProductsRequestDelegate>
@property(readwrite, strong, nonatomic) NSArray<SKProduct *> *products;

// SKPaymentTransactionObserver
- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray<SKPaymentTransaction *> *)transactions;
- (void)paymentQueue:(SKPaymentQueue *)queue removedTransactions:(NSArray<SKPaymentTransaction *> *)transactions;
- (void)paymentQueue:(SKPaymentQueue *)queue restoreCompletedTransactionsFailedWithError:(NSError *)error;
- (void)paymentQueueRestoreCompletedTransactionsFinished:(SKPaymentQueue *)queue;
- (BOOL)paymentQueue:(SKPaymentQueue *)queue shouldAddStorePayment:(SKPayment *)payment forProduct:(SKProduct *)product;

// SKProductsRequestDelegate
- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response;

// SKRequestDelegate
- (void)requestDidFinish:(SKRequest *)request;
- (void)request:(SKRequest *)request didFailWithError:(NSError *)error;
@end

static NSString *objectToJSONString(NSObject *obj)
{
    NSData *data = [NSJSONSerialization dataWithJSONObject:obj options:0 error:nil];
    return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
}

static NSDictionary *transactionToDictionary(SKPaymentTransaction *transaction)
{
    NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
    [dict setValue:transaction.payment.productIdentifier forKey:@"productIdentifier"];
    [dict setValue:[NSNumber numberWithInteger:transaction.payment.quantity] forKey:@"productQuantity"];
    [dict setValue:transaction.transactionIdentifier forKey:@"identifier"];
    
    if (transaction.transactionState == SKPaymentTransactionStatePurchased ||
        transaction.transactionState == SKPaymentTransactionStateRestored)
    {
        [dict setValue:[NSNumber numberWithDouble:transaction.transactionDate.timeIntervalSince1970] forKey:@"date"];
        NSURL *receiptURL = [[NSBundle mainBundle] appStoreReceiptURL];
        NSData *receipt = [NSData dataWithContentsOfURL:receiptURL];
        if (receipt) {
            NSDictionary *requestContents = @{
                @"receipt-data": [receipt base64EncodedStringWithOptions:0]
            };
            [dict setValue:objectToJSONString(requestContents) forKey:@"receipt"];
        }
    }
    
    if(transaction.transactionState == SKPaymentTransactionStateFailed)
    {
        NSString *error = [[transaction.error localizedDescription] stringByAppendingFormat:@":%ld", (long)transaction.error.code];
        [dict setValue:error forKey:@"error"];
    }
    
    if(transaction.transactionState == SKPaymentTransactionStateRestored &&
       transaction.originalTransaction.transactionState != SKPaymentTransactionStatePurchasing)
    {
        [dict setValue:transactionToDictionary(transaction.originalTransaction) forKey:@"originalTransaction"];
    }
    
    return dict;
}


static NSString *transactionsToString(NSArray<SKPaymentTransaction *> *transactions)
{
    NSMutableArray<NSDictionary *> *values = [[NSMutableArray alloc] init];
    
    for (SKPaymentTransaction *t in transactions)
    {
        [values addObject:transactionToDictionary(t)];
    }
    
    return objectToJSONString(values);
}

static NSString *productsToString(NSArray<SKProduct *> *products)
{
    NSMutableArray<NSDictionary *> *values = [[NSMutableArray alloc] init];
    
    for (SKProduct *p in products)
    {
        NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
        [dict setValue:p.localizedTitle forKey:@"title"];
        [dict setValue:p.localizedDescription forKey:@"description"];
        [dict setValue:p.productIdentifier forKey:@"identifier"];
        [dict setValue:p.priceLocale.localeIdentifier forKey:@"priceLocale"];
        [dict setValue:p.price forKey:@"price"];
        [values addObject:dict];
    }
    
    return objectToJSONString(values);
}

@implementation IAPConnector

- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray<SKPaymentTransaction *> *)transactions
{
    NSString *message = transactionsToString(transactions);
    NSString *event = nil;
    for(SKPaymentTransaction * transaction in transactions)
    {
        switch (transaction.transactionState)
        {
            case SKPaymentTransactionStatePurchased:
                event = @"purchaseTransactionSuccess";
                break;
            case SKPaymentTransactionStateRestored:
                event = @"restoreTransactionSuccess";
                break;
            case SKPaymentTransactionStateFailed:
                [[SKPaymentQueue defaultQueue] finishTransaction:transaction];
                event = transaction.error.code == SKErrorPaymentCancelled ? @"purchaseTransactionCancel" : @"purchaseTransactionFail";
                break;
            default:
                break;
        }
        break;
    }
    
    if (event != nil)
        [self dispatch:event withMessage:message];
}

- (void)paymentQueue:(SKPaymentQueue *)queue removedTransactions:(NSArray<SKPaymentTransaction *> *)transactions
{
    @autoreleasepool {
        [self dispatch:@"finishTransactionSuccess" withMessage:transactionsToString(transactions)];
    }
}

- (void)paymentQueue:(SKPaymentQueue *)queue restoreCompletedTransactionsFailedWithError:(NSError *)error
{
    @autoreleasepool {
        NSString *errstr = [[error localizedDescription] stringByAppendingFormat:@":%ld", (long)error.code];
        [self dispatch:@"restoreTransactionFail" withMessage:errstr];
    }
}

- (void)paymentQueueRestoreCompletedTransactionsFinished:(SKPaymentQueue *)queue
{
    [self dispatch:@"restoreTransactionComplete" withMessage:@""];
}

- (BOOL)paymentQueue:(SKPaymentQueue *)queue shouldAddStorePayment:(SKPayment *)payment forProduct:(SKProduct *)product
{
    // TODO:
    return NO;
}

- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response
{
    @autoreleasepool {
        self.products = response.products;
        [self dispatch:@"productDetailsSuccess" withMessage:productsToString(response.products)];
        
        if (response.invalidProductIdentifiers.count > 0)
        {
            [self dispatch:@"productDetailsInvalid" withMessage:objectToJSONString(response.invalidProductIdentifiers)];
        }
    }
}

- (void)requestDidFinish:(SKRequest *)request
{
}

- (void)request:(SKRequest *)request didFailWithError:(NSError *)error
{
    @autoreleasepool {
        NSString *errstr = [[error localizedDescription] stringByAppendingFormat:@":%ld", (long)error.code];
        [self dispatch:@"productDetailsFail" withMessage:errstr];
    }
}

@end

#define CLASS_CONNECTOR "IAPConnector*"
#define olua_checkconnector(L, i) ((__bridge IAPConnector *)olua_checkobj(L, i, CLASS_CONNECTOR))
#define NSStringMake(str) (str == NULL ? nil : @(str))

static int l__gc(lua_State *L)
{
    @autoreleasepool {
        IAPConnector *connector = olua_checkconnector(L, 1);
        [[SKPaymentQueue defaultQueue] removeTransactionObserver:connector];
        CFBridgingRelease((__bridge CFTypeRef)connector);
    }
    
    return 0;
}

static int l_set_callback(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        IAPConnector *connector = olua_checkconnector(L, 1);
        void *cb_store = (__bridge void *)connector;
        std::string func = olua_setcallback(L, cb_store, "dispatcher", 2, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        connector.dispatcher = [cb_store, func, ctx] (const std::string &event, const std::string &data) {
            lua_State *L = olua_mainthread(NULL);
            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);
                lua_pushstring(L, event.c_str());
                lua_pushstring(L, data.c_str());
                olua_callback(L, cb_store, func.c_str(), 2);
                lua_settop(L, top);
            }
        };
    }
    
    return 0;
}

static int l_can_make_payments(lua_State *L)
{
    @autoreleasepool {
        lua_pushboolean(L, [SKPaymentQueue canMakePayments]);
    }
    
    return 1;
}

static int l_request_products(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        IAPConnector *connector = olua_checkconnector(L, 1);
        NSString *idsstr = [NSString stringWithUTF8String:luaL_checkstring(L, 2)];
        NSMutableSet *ids = [NSMutableSet setWithArray:[idsstr componentsSeparatedByString:@","]];
        SKProductsRequest *req = [[SKProductsRequest alloc] initWithProductIdentifiers:ids];
        req.delegate = connector;
        [req start];
        xgame::runtime::log("request products: %s", [idsstr UTF8String]);
    }
    
    return 1;
}

static int l_purchase(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 3);
        IAPConnector *connector = olua_checkconnector(L, 1);
        NSString *pid = [NSString stringWithUTF8String:luaL_checkstring(L, 2)];
        NSNumber *quantify = [NSNumber numberWithInteger:(int)luaL_checkinteger(L, 3)];
        SKProduct *product = nil;
        
        if (connector.products != nil) {
            for (SKProduct *p in connector.products) {
                if ([p.productIdentifier isEqualToString:pid]) {
                    product = p;
                    break;
                }
            }
        }
        
        if (product != nil) {
            xgame::runtime::log("purchase product: pid=%s quantity=%d", [pid UTF8String], (int)[quantify integerValue]);
            SKMutablePayment *payment = [SKMutablePayment paymentWithProduct:product];
            payment.quantity = MAX(1, [quantify integerValue]);
            [[SKPaymentQueue defaultQueue] addPayment:payment];
        } else {
            xgame::runtime::log("can't find product: %s", [pid UTF8String]);
        }
    }
    
    return 0;
}

static int l_finish_transaction(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        NSString *tid = [NSString stringWithUTF8String:luaL_checkstring(L, 2)];
        xgame::runtime::log("try to finish transaction: %s", [tid UTF8String]);
        for (SKPaymentTransaction *t in [SKPaymentQueue defaultQueue].transactions)
        {
            if ([t.transactionIdentifier isEqualToString:tid]) {
                [[SKPaymentQueue defaultQueue] finishTransaction:t];
            } else if (t.originalTransaction && [t.originalTransaction.transactionIdentifier isEqualToString:tid]) {
                [[SKPaymentQueue defaultQueue] finishTransaction:t.originalTransaction];
                [[SKPaymentQueue defaultQueue] finishTransaction:t];
            }
        }
    }
    
    return 0;
}

static int l_restore_completed_transactions(lua_State *L)
{
    @autoreleasepool {
        [[SKPaymentQueue defaultQueue] restoreCompletedTransactions];
    }
    
    return 0;
}

static int l_pending_transactions(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 1);
        NSMutableArray<SKPaymentTransaction *> *transactions = [[NSMutableArray alloc] init];
        for (SKPaymentTransaction *t in [SKPaymentQueue defaultQueue].transactions) {
            switch (t.transactionState) {
                case SKPaymentTransactionStatePurchased:
                case SKPaymentTransactionStateRestored:
                case SKPaymentTransactionStateDeferred:
                    [transactions addObject:t];
                    break;
                default:
                    [[SKPaymentQueue defaultQueue] finishTransaction:t];
                    break;
            }
        }
        
        NSString *str = transactionsToString(transactions);
        lua_pushstring(L, [str UTF8String]);
    }
    
    return 1;
}

int luaopen_iap(lua_State *L)
{
    oluacls_class(L, CLASS_CONNECTOR, nullptr);
    oluacls_func(L, "__gc", l__gc);
    oluacls_func(L, "setDispatcher", l_set_callback);
    oluacls_func(L, "canMakePayments", l_can_make_payments);
    oluacls_func(L, "requestProducts", l_request_products);
    oluacls_func(L, "purchase", l_purchase);
    oluacls_func(L, "finishTransaction", l_finish_transaction);
    oluacls_func(L, "restoreCompletedTransactions", l_restore_completed_transactions);
    oluacls_prop(L, "pendingTransactions", l_pending_transactions, nullptr);
    
    xgame::runtime::registerFeature("iap.ios", true);
    
    @autoreleasepool {
        IAPConnector *connector = [IAPConnector new];
        [[SKPaymentQueue defaultQueue] addTransactionObserver:connector];
        olua_push_obj(L, (void *)CFBridgingRetain(connector), CLASS_CONNECTOR);
    }
    
    return 1;
}

#endif
