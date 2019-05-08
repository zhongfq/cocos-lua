#include "lua_iap.h"
#include "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <StoreKit/StoreKit.h>

@interface IAPStoreConnector : NSObject<SKPaymentTransactionObserver, SKRequestDelegate, SKProductsRequestDelegate>
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
    [dict setValue:transaction.payment.productIdentifier forKey:@"product_identifier"];
    [dict setValue:[NSNumber numberWithInteger:transaction.payment.quantity] forKey:@"product_quantity"];
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
        [dict setValue:transactionToDictionary(transaction.originalTransaction) forKey:@"original_transaction"];
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
        [dict setValue:p.priceLocale.localeIdentifier forKey:@"price_locale"];
        [dict setValue:p.price forKey:@"price"];
        [values addObject:dict];
    }
    
    return objectToJSONString(values);
}

@implementation IAPStoreConnector

- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray<SKPaymentTransaction *> *)transactions
{
    NSString *message = transactionsToString(transactions);
    NSString *event = nil;
    for(SKPaymentTransaction * transaction in transactions)
    {
        switch (transaction.transactionState)
        {
            case SKPaymentTransactionStatePurchased:
                event = @"purchase_transaction_success";
                break;
            case SKPaymentTransactionStateRestored:
                event = @"restore_transaction_success";
                break;
            case SKPaymentTransactionStateFailed:
                event = transaction.error.code == SKErrorPaymentCancelled ? @"purchase_transaction_cancel" : @"purchase_transaction_fail";
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
        [self dispatch:@"finish_transaction_success" withMessage:transactionsToString(transactions)];
    }
}

- (void)paymentQueue:(SKPaymentQueue *)queue restoreCompletedTransactionsFailedWithError:(NSError *)error
{
    @autoreleasepool {
        NSString *errstr = [[error localizedDescription] stringByAppendingFormat:@":%ld", (long)error.code];
        [self dispatch:@"restore_transaction_fail" withMessage:errstr];
    }
}

- (void)paymentQueueRestoreCompletedTransactionsFinished:(SKPaymentQueue *)queue
{
    [self dispatch:@"restore_transaction_complete" withMessage:@""];
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
        [self dispatch:@"product_details_success" withMessage:productsToString(response.products)];
        
        if (response.invalidProductIdentifiers.count > 0)
        {
            [self dispatch:@"product_details_invalid" withMessage:objectToJSONString(response.invalidProductIdentifiers)];
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
        [self dispatch:@"product_details_fail" withMessage:errstr];
    }
}

@end

#define LUA_CONNECTORHANDLE "IAPStoreConnector*"
#define toconnector(L) ((__bridge IAPStoreConnector *)(*(void **)luaL_checkudata(L, 1, LUA_CONNECTORHANDLE)))

static int gc(lua_State *L)
{
    IAPStoreConnector *connector = toconnector(L);
    CFBridgingRelease((__bridge CFTypeRef)connector);
    
    return 0;
}

static int set_callback(lua_State *L)
{
    IAPStoreConnector *connector = toconnector(L);
    [connector setCallback:luaext_reffunction(L, 2)];
    return 0;
}

static int can_make_payments(lua_State *L)
{
    @autoreleasepool {
        lua_pushboolean(L, [SKPaymentQueue canMakePayments]);
    }
    
    return 1;
}

static int request_products(lua_State *L)
{
    @autoreleasepool {
        IAPStoreConnector *connector = toconnector(L);
        NSString *idsstr = [NSString stringWithUTF8String:luaL_checkstring(L, 2)];
        NSMutableSet *ids = [NSMutableSet setWithArray:[idsstr componentsSeparatedByString:@","]];
        
        SKProductsRequest *req = [[SKProductsRequest alloc] initWithProductIdentifiers:ids];
        req.delegate = connector;
        [req start];
        
        xgame::runtime::log("request products: %s", [idsstr UTF8String]);
    }
    
    return 1;
}

static int purchase(lua_State *L)
{
    @autoreleasepool {
        IAPStoreConnector *connector = toconnector(L);
        NSString *pid = [NSString stringWithUTF8String:luaL_checkstring(L, 2)];
        NSNumber *quantify = [NSNumber numberWithInteger:(int)luaL_checkinteger(L, 3)];
        SKProduct *product = nil;
        
        if (connector.products != nil)
        {
            for (SKProduct *p in connector.products)
            {
                if ([p.productIdentifier isEqualToString:pid])
                {
                    product = p;
                    break;
                }
            }
        }
        
        if (product != nil)
        {
            xgame::runtime::log("purchase product: pid=%s quantity=%d", [pid UTF8String], (int)[quantify integerValue]);
            
            SKMutablePayment *payment = [SKMutablePayment paymentWithProduct:product];
            payment.quantity = MAX(1, [quantify integerValue]);
            [[SKPaymentQueue defaultQueue] addPayment:payment];
        }
        else
        {
            xgame::runtime::log("can't find product: %s", [pid UTF8String]);
        }
    }
    
    return 0;
}

static int finish_transaction(lua_State *L)
{
    @autoreleasepool {
        NSString *tid = [NSString stringWithUTF8String:luaL_checkstring(L, 2)];
        xgame::runtime::log("try to finish transaction: %s", [tid UTF8String]);
        for (SKPaymentTransaction *t in [SKPaymentQueue defaultQueue].transactions)
        {
            if ([t.transactionIdentifier isEqualToString:tid])
            {
                [[SKPaymentQueue defaultQueue] finishTransaction:t];
            }
            else if (t.originalTransaction && [t.originalTransaction.transactionIdentifier isEqualToString:tid])
            {
                [[SKPaymentQueue defaultQueue] finishTransaction:t.originalTransaction];
                [[SKPaymentQueue defaultQueue] finishTransaction:t];
            }
        }
    }
    
    return 0;
}

static int restore_completed_transactions(lua_State *L)
{
    @autoreleasepool {
        [[SKPaymentQueue defaultQueue] restoreCompletedTransactions];
    }
    
    return 0;
}

static int pending_transactions(lua_State *L)
{
    @autoreleasepool {
        NSMutableArray<SKPaymentTransaction *> *transactions = [[NSMutableArray alloc] init];
        for (SKPaymentTransaction *t in [SKPaymentQueue defaultQueue].transactions)
        {
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

static const luaL_Reg lib[] = {
    {"__gc", gc},
    {"set_callback", set_callback},
    {"can_make_payments", can_make_payments},
    {"request_products", request_products},
    {"purchase", purchase},
    {"finish_transaction", finish_transaction},
    {"restore_completed_transactions", restore_completed_transactions},
    {"pending_transactions", pending_transactions},
    {NULL, NULL},
};

int luaopen_iapstore_ios(lua_State *L)
{
    luaL_newmetatable(L, LUA_CONNECTORHANDLE);
    luaL_setfuncs(L, lib, 0);
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    
    IAPStoreConnector *connector = [[IAPStoreConnector alloc] init];
    [[SKPaymentQueue defaultQueue] addTransactionObserver:connector];
    *(void **)lua_newuserdata(L, sizeof(void *)) = (void *)CFBridgingRetain(connector);
    luaL_setmetatable(L, LUA_CONNECTORHANDLE);
    
    return 1;
}

#endif
