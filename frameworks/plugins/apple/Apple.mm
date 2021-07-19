#import "Apple.h"
#import "cclua/plugin-ios.h"

#if defined(CCLUA_OS_IOS)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

#ifdef CCLUA_BUILD_APPLE_AUTH

#import <AuthenticationServices/AuthenticationServices.h>

@interface AppleDelegate : NSObject<ASAuthorizationControllerDelegate, ASAuthorizationControllerPresentationContextProviding>

@property AppleAuth::AuthCallback callback;

+ (instancetype) defaultDelegate;

- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithAuthorization:(ASAuthorization *)authorization API_AVAILABLE(ios(13.0));
- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithError:(NSError *)error API_AVAILABLE(ios(13.0));

- (ASPresentationAnchor)presentationAnchorForAuthorizationController:(ASAuthorizationController *)controller API_AVAILABLE(ios(13.0));
@end

@implementation AppleDelegate

+ (instancetype) defaultDelegate
{
    static AppleDelegate *inst = nil;
    if (inst == nil) {
        inst = [[AppleDelegate alloc] init];
    }
    return inst;
}

- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithAuthorization:(ASAuthorization *)authorization
{
     @autoreleasepool {
         cocos2d::ValueMap data;
         if ([authorization.provider isKindOfClass:[ASAuthorizationAppleIDProvider class]]) {
             ASAuthorizationAppleIDCredential *credential = authorization.credential;
             setValueMap(data, "user", toValue(credential.user));
             setValueMap(data, "state", toValue(credential.state));
             setValueMap(data, "email", toValue(credential.email));
             setValueMap(data, "identityToken", toValue(credential.identityToken));
             setValueMap(data, "authorizationCode", toValue(credential.authorizationCode));
             setValueMap(data, "nickname", toValue(credential.fullName ? credential.fullName.nickname : nil));
         } else if ([authorization.credential isKindOfClass:[ASAuthorizationPasswordProvider class]]) {
             ASPasswordCredential *credential = authorization.credential;
             setValueMap(data, "account", toValue(credential.user));
             setValueMap(data, "password", toValue(credential.password));
         }
         runtime::runOnCocosThread([=]() {
             if (self.callback) {
                 self.callback(data);
             }
         });
     }
}

- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithError:(NSError *)error
{
    @autoreleasepool {
        cclua::runtime::log("apple auth error: errcode=%d", (int)error.code);
        cocos2d::ValueMap data;
        data["errcode"] = cocos2d::Value((unsigned int)error.code);
        runtime::runOnCocosThread([=]() {
            if (self.callback) {
                self.callback(data);
            }
        });
    }
}

- (ASPresentationAnchor)presentationAnchorForAuthorizationController:(ASAuthorizationController *)controller
{
    return [[UIApplication sharedApplication] keyWindow];
}

@end

bool AppleAuth::canMakeAuth()
{
    if (@available(iOS 13.0, *)) {
        return true;
    } else {
        return false;
    }
}

void AppleAuth::auth(const AuthCallback &callback)
{
    @autoreleasepool {
        if (@available(iOS 13.0, *)) {
            AppleDelegate *delegate = [AppleDelegate defaultDelegate];
            ASAuthorizationAppleIDProvider *provider = [ASAuthorizationAppleIDProvider new];
            ASAuthorizationAppleIDRequest *request = [provider createRequest];
            [request setRequestedScopes:@[ASAuthorizationScopeFullName, ASAuthorizationScopeEmail]];
            ASAuthorizationController *controller = [[ASAuthorizationController alloc] initWithAuthorizationRequests:@[request]];
            controller.delegate = delegate;
            controller.presentationContextProvider = delegate;
            delegate.callback = callback;
            [controller performRequests];
        } else {
            CCASSERT(false, "not support");
        }
    }
}

#endif // CCLUA_BUILD_APPLE_AUTH

#ifdef CCLUA_BUILD_APPLE_IAP

#import <StoreKit/StoreKit.h>

Dispatcher AppleIAP::_dispatcher;

@interface AppleIAPDelegate : NSObject<SKPaymentTransactionObserver, SKRequestDelegate, SKProductsRequestDelegate>
@property(readwrite, strong, nonatomic) NSArray<SKProduct *> *products;

+ (instancetype) defaultDelegate;

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

static cocos2d::ValueMap toValueMap(SKPaymentTransaction *transaction)
{
    cocos2d::ValueMap dict;
    setValueMap(dict, "productIdentifier", toValue(transaction.payment.productIdentifier));
    setValueMap(dict, "productQuantity", cocos2d::Value((int)transaction.payment.quantity));
    setValueMap(dict, "identifier", toValue(transaction.transactionIdentifier));
    
    if (transaction.transactionState == SKPaymentTransactionStatePurchased ||
        transaction.transactionState == SKPaymentTransactionStateRestored) {
        setValueMap(dict, "date", cocos2d::Value((double)transaction.transactionDate.timeIntervalSince1970));
        NSURL *receiptURL = [[NSBundle mainBundle] appStoreReceiptURL];
        NSData *receipt = [NSData dataWithContentsOfURL:receiptURL];
        if (receipt) {
            cocos2d::ValueMap receiptDict;
            setValueMap(receiptDict, "receipt-data", toValue([receipt base64EncodedStringWithOptions:0]));
            setValueMap(dict, "receipt", cocos2d::Value(receiptDict));
        }
    }
    
    if(transaction.transactionState == SKPaymentTransactionStateFailed) {
        NSString *error = [[transaction.error localizedDescription] stringByAppendingFormat:@":%ld", (long)transaction.error.code];
        setValueMap(dict, "error", cocos2d::Value(error));
    }
    
    if(transaction.transactionState == SKPaymentTransactionStateRestored &&
       transaction.originalTransaction.transactionState != SKPaymentTransactionStatePurchasing) {
        cocos2d::ValueMap otdict = toValueMap(transaction.originalTransaction);
        setValueMap(dict, "originalTransaction", cocos2d::Value(otdict));
    }
    
    return dict;
}


static cocos2d::ValueVector toValueVector(NSArray<SKPaymentTransaction *> *transactions)
{
    cocos2d::ValueVector arr;
    for (SKPaymentTransaction *t in transactions) {
        arr.push_back(cocos2d::Value(toValueMap(t)));
    }
    return arr;
}

static cocos2d::ValueVector toValueVector(NSArray<SKProduct *> *products)
{
    cocos2d::ValueVector arr;
    for (SKProduct *p in products) {
        cocos2d::ValueMap dict;
        setValueMap(dict, "title", toValue(p.localizedTitle));
        setValueMap(dict, "description", toValue(p.localizedDescription));
        setValueMap(dict, "identifier", toValue(p.productIdentifier));
        setValueMap(dict, "priceLocale", toValue(p.priceLocale.localeIdentifier));
        setValueMap(dict, "price", cocos2d::Value(p.price.doubleValue));
        arr.push_back(cocos2d::Value(dict));
    }
    return arr;
}

@implementation AppleIAPDelegate

+ (id)defaultDelegate
{
    static AppleIAPDelegate *inst = nil;
    if (!inst) {
        inst = [[AppleIAPDelegate alloc] init];
    }
    return inst;
}

- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray<SKPaymentTransaction *> *)transactions
{
    cocos2d::ValueVector arr = toValueVector(transactions);
    const char *event = nullptr;
    for(SKPaymentTransaction * transaction in transactions) {
        switch (transaction.transactionState) {
            case SKPaymentTransactionStatePurchased:
                event = "purchaseTransactionSuccess";
                break;
            case SKPaymentTransactionStateRestored:
                event = "restoreTransactionSuccess";
                break;
            case SKPaymentTransactionStateFailed:
                [[SKPaymentQueue defaultQueue] finishTransaction:transaction];
                event = transaction.error.code == SKErrorPaymentCancelled ? "purchaseTransactionCancel" : "purchaseTransactionFail";
                break;
            default:
                break;
        }
        break;
    }
    if (event) {
        AppleIAP::dispatch(event, cocos2d::Value(arr));
    }
}

- (void)paymentQueue:(SKPaymentQueue *)queue removedTransactions:(NSArray<SKPaymentTransaction *> *)transactions
{
    @autoreleasepool {
        AppleIAP::dispatch("finishTransactionSuccess", cocos2d::Value(toValueVector(transactions)));
    }
}

- (void)paymentQueue:(SKPaymentQueue *)queue restoreCompletedTransactionsFailedWithError:(NSError *)error
{
    @autoreleasepool {
        NSString *errstr = [[error localizedDescription] stringByAppendingFormat:@":%ld", (long)error.code];
        AppleIAP::dispatch("restoreTransactionFail", toValue(errstr));
    }
}

- (void)paymentQueueRestoreCompletedTransactionsFinished:(SKPaymentQueue *)queue
{
    AppleIAP::dispatch("restoreTransactionComplete", cocos2d::Value::Null);
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
        AppleIAP::dispatch("productDetailsSuccess", cocos2d::Value(toValueVector(response.products)));
        
        if (response.invalidProductIdentifiers.count > 0)
        {
            AppleIAP::dispatch("productDetailsInvalid", toValue(response.invalidProductIdentifiers));
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
        AppleIAP::dispatch("productDetailsFail", toValue(errstr));
    }
}

@end

bool AppleIAP::canMakePayments()
{
    @autoreleasepool {
        return [SKPaymentQueue canMakePayments];
    }
}

void AppleIAP::requestProducts(const std::set<std::string> &products)
{
    @autoreleasepool {
        std::string pstr;
        NSMutableSet *ids = [[NSMutableSet alloc] init];
        for (auto itor : products) {
            pstr += itor + " ";
            [ids addObject: toNSString(itor)];
        }
        SKProductsRequest *req = [[SKProductsRequest alloc] initWithProductIdentifiers:ids];
        req.delegate = [AppleIAPDelegate defaultDelegate];
        [req start];
        cclua::runtime::log("request products: %s", pstr.c_str());
    }
}

void AppleIAP::purchase(const std::string &product, uint32_t quantify)
{
    @autoreleasepool {
        AppleIAPDelegate *delegate = [AppleIAPDelegate defaultDelegate];
        NSString *pid = toNSString(product);
        SKProduct *product = nil;
        
        
        if (delegate.products != nil) {
            for (SKProduct *p in delegate.products) {
                if ([p.productIdentifier isEqualToString:pid]) {
                    product = p;
                    break;
                }
            }
        }
        
        if (product != nil) {
            cclua::runtime::log("purchase product: pid=%s quantity=%d", [pid UTF8String], quantify);
            SKMutablePayment *payment = [SKMutablePayment paymentWithProduct:product];
            payment.quantity = MAX(1, quantify);
            [[SKPaymentQueue defaultQueue] addPayment:payment];
        } else {
            cclua::runtime::log("can't find product: %s", [pid UTF8String]);
        }
    }
}

void AppleIAP::finishTransaction(const std::string &tid)
{
    @autoreleasepool {
        NSString *identifier = toNSString(tid);
        cclua::runtime::log("try to finish transaction: %s", tid.c_str());
        for (SKPaymentTransaction *t in [SKPaymentQueue defaultQueue].transactions)
        {
            if ([t.transactionIdentifier isEqualToString:identifier]) {
                [[SKPaymentQueue defaultQueue] finishTransaction:t];
            } else if (t.originalTransaction && [t.originalTransaction.transactionIdentifier isEqualToString:identifier]) {
                [[SKPaymentQueue defaultQueue] finishTransaction:t.originalTransaction];
                [[SKPaymentQueue defaultQueue] finishTransaction:t];
            }
        }
    }
}

void AppleIAP::restoreCompletedTransactions()
{
    @autoreleasepool {
        [[SKPaymentQueue defaultQueue] restoreCompletedTransactions];
    }
}

cocos2d::ValueVector AppleIAP::getPendingTransactions()
{
    @autoreleasepool {
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
        return toValueVector(transactions);
    }
}

#endif // CCLUA_BUILD_APPLE_IAP

#endif // CCLUA_OS_IOS
