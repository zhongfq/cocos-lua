#import "apple.h"
#import "cclua/plugin-ios.h"

#if defined(CCLUA_OS_IOS)

#import <AuthenticationServices/AuthenticationServices.h>
#import <StoreKit/StoreKit.h>

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

Callback apple::_dispatcher;

static cocos2d::ValueMap toValueMap(SKPaymentTransaction *value)
{
    cocos2d::ValueMap transaction;
    setValueMap(transaction, "productIdentifier", toValue(value.payment.productIdentifier));
    setValueMap(transaction, "productQuantity", cocos2d::Value((uint64_t)value.payment.quantity));
    setValueMap(transaction, "identifier", toValue(value.transactionIdentifier));
    if (value.transactionState == SKPaymentTransactionStatePurchased ||
        value.transactionState == SKPaymentTransactionStateRestored) {
        setValueMap(transaction, "date", cocos2d::Value((double)value.transactionDate.timeIntervalSince1970));
        NSURL *receiptURL = [[NSBundle mainBundle] appStoreReceiptURL];
        NSData *receipt = [NSData dataWithContentsOfURL:receiptURL];
        if (receipt) {
            setValueMap(transaction, "receipt", toValue([receipt base64EncodedStringWithOptions:0]));
        }
        if (value.transactionState == SKPaymentTransactionStatePurchased) {
            setValueMap(transaction, "state", cocos2d::Value("purchased"));
        } else {
            setValueMap(transaction, "state", cocos2d::Value("restored"));
        }
    } else if (value.transactionState == SKPaymentTransactionStateFailed) {
        NSString *error = [[value.error localizedDescription] stringByAppendingFormat:@":%ld", (long)value.error.code];
        if (value.error.code == SKErrorPaymentCancelled) {
            setValueMap(transaction, "state", cocos2d::Value("canceled"));
        } else {
            setValueMap(transaction, "state", cocos2d::Value("failed"));
        }
    } else if (value.transactionState == SKPaymentTransactionStatePurchasing) {
        setValueMap(transaction, "state", cocos2d::Value("purchasing"));
    } else if (value.transactionState == SKPaymentTransactionStateDeferred) {
        setValueMap(transaction, "state", cocos2d::Value("deferred"));
    }
    
    if(value.transactionState == SKPaymentTransactionStateRestored &&
       value.originalTransaction.transactionState != SKPaymentTransactionStatePurchasing) {
        cocos2d::ValueMap otdict = toValueMap(value.originalTransaction);
        setValueMap(transaction, "originalTransaction", cocos2d::Value(otdict));
    }
    
    return transaction;
}


static cocos2d::ValueVector toValueVector(NSArray<SKPaymentTransaction *> *value)
{
    cocos2d::ValueVector arr;
    for (SKPaymentTransaction *t in value) {
        arr.push_back(cocos2d::Value(toValueMap(t)));
    }
    return arr;
}

static cocos2d::ValueVector toValueVector(NSArray<SKProduct *> *value)
{
    cocos2d::ValueVector arr;
    for (SKProduct *p in value) {
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

static cocos2d::ValueVector toValueVector(NSArray<NSString *> *value)
{
    cocos2d::ValueVector arr;
    for (NSString *s in value) {
        arr.push_back(toValue(s));
    }
    return arr;
}


@interface AppleDelegate : NSObject<ASAuthorizationControllerDelegate, ASAuthorizationControllerPresentationContextProviding, SKPaymentTransactionObserver, SKRequestDelegate, SKProductsRequestDelegate>

@property(readwrite, strong, nonatomic) NSArray<SKProduct *> *products;

+ (instancetype) defaultDelegate;

- (instancetype)init;
- (void)dealloc;

- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithAuthorization:(ASAuthorization *)authorization API_AVAILABLE(ios(13.0));
- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithError:(NSError *)error API_AVAILABLE(ios(13.0));

- (ASPresentationAnchor)presentationAnchorForAuthorizationController:(ASAuthorizationController *)controller API_AVAILABLE(ios(13.0));

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

@implementation AppleDelegate

+ (instancetype) defaultDelegate
{
    static AppleDelegate *inst = nil;
    if (inst == nil) {
        inst = [[AppleDelegate alloc] init];
    }
    return inst;
}

- (instancetype)init
{
    [[SKPaymentQueue defaultQueue] addTransactionObserver:self];
    return [super init];
}

- (void)dealloc
{
    [[SKPaymentQueue defaultQueue] removeTransactionObserver:self];
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
         apple::dispatch("auth", data);
     }
}

- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithError:(NSError *)error
{
    @autoreleasepool {
        cclua::runtime::log("apple auth error: errcode=%d", (int)error.code);
        cocos2d::ValueMap data;
        data["errcode"] = cocos2d::Value((uint64_t)error.code);
        apple::dispatch("auth", data);
    }
}

- (ASPresentationAnchor)presentationAnchorForAuthorizationController:(ASAuthorizationController *)controller
{
    return [[UIApplication sharedApplication] keyWindow];
}

- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray<SKPaymentTransaction *> *)transactions
{
    NSMutableArray<SKPaymentTransaction *> *purchaseArray = [NSMutableArray arrayWithCapacity: transactions.count];
    NSMutableArray<SKPaymentTransaction *> *restoreArray = [NSMutableArray arrayWithCapacity:transactions.count];
    for(SKPaymentTransaction *value in transactions) {
        if (value.transactionState == SKPaymentTransactionStateRestored) {
            [restoreArray addObject:value];
        } else if (value.transactionState != SKPaymentTransactionStatePurchasing) {
            [purchaseArray addObject:value];
        }
    }
    if (purchaseArray.count > 0) {
        cocos2d::ValueMap data;
        data["transactions"] = toValueVector(purchaseArray);
        data["state"] = "successful";
        apple::dispatch("purchase", data);
    }
    if (restoreArray.count > 0) {
        cocos2d::ValueMap data;
        data["transactions"] = toValueVector(restoreArray);
        data["state"] = "successful";
        apple::dispatch("restoreTransactions", data);
    }
}

- (void)paymentQueue:(SKPaymentQueue *)queue removedTransactions:(NSArray<SKPaymentTransaction *> *)transactions
{
    @autoreleasepool {
        cocos2d::ValueMap data;
        data["transactions"] = toValueVector(transactions);
        apple::dispatch("finishTransaction", data);
    }
}

- (void)paymentQueue:(SKPaymentQueue *)queue restoreCompletedTransactionsFailedWithError:(NSError *)error
{
    @autoreleasepool {
        NSString *errstr = [[error localizedDescription] stringByAppendingFormat:@":%ld", (long)error.code];
        cocos2d::ValueMap data;
        data["state"] = "failed";
        data["errcode"] = cocos2d::Value((uint64_t)error.code);
        data["error"] = toValue(errstr);
        apple::dispatch("restoreTransactions", data);
    }
}

- (void)paymentQueueRestoreCompletedTransactionsFinished:(SKPaymentQueue *)queue
{
    cocos2d::ValueMap data;
    data["state"] = "completed";
    apple::dispatch("restoreTransactions", data);
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
        
        if (response.products.count > 0) {
            cocos2d::ValueMap data;
            data["state"] = "successful";
            data["products"] = cocos2d::Value(toValueVector(response.products));
            apple::dispatch("requestProducts", data);
        }
        
        if (response.invalidProductIdentifiers.count > 0) {
            cocos2d::ValueMap data;
            data["state"] = "invalid";
            data["products"] = cocos2d::Value(toValueVector(response.invalidProductIdentifiers));
            apple::dispatch("requestProducts", data);
        }
    }
}

- (void)requestDidFinish:(SKRequest *)request
{
    cocos2d::ValueMap data;
    data["state"] = "finished";
    apple::dispatch("requestProducts", data);
}

- (void)request:(SKRequest *)request didFailWithError:(NSError *)error
{
    @autoreleasepool {
        NSString *errstr = [[error localizedDescription] stringByAppendingFormat:@":%ld", (long)error.code];
        cocos2d::ValueMap data;
        data["state"] = "failed";
        data["error"] = errstr;
        apple::dispatch("requestProducts", data);
    }
}

@end

bool apple::canMakeAuth()
{
    if (@available(iOS 13.0, *)) {
        return true;
    } else {
        return false;
    }
}

void apple::auth()
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
            [controller performRequests];
        } else {
            CCASSERT(false, "not support");
        }
    }
}

bool apple::canMakePayments()
{
    @autoreleasepool {
        return [SKPaymentQueue canMakePayments];
    }
}

void apple::requestProducts(const std::set<std::string> &products)
{
    @autoreleasepool {
        std::string pstr;
        NSMutableSet *ids = [[NSMutableSet alloc] init];
        for (auto itor : products) {
            pstr += itor + " ";
            [ids addObject: toNSString(itor)];
        }
        SKProductsRequest *req = [[SKProductsRequest alloc] initWithProductIdentifiers:ids];
        req.delegate = [AppleDelegate defaultDelegate];
        cclua::runtime::log("request products: %s", pstr.c_str());
        [req start];
    }
}

void apple::purchase(const std::string &product, uint32_t quantify)
{
    @autoreleasepool {
        AppleDelegate *delegate = [AppleDelegate defaultDelegate];
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

void apple::finishTransaction(const std::string &tid)
{
    @autoreleasepool {
        NSString *identifier = toNSString(tid);
        cclua::runtime::log("try to finish transaction: %s", tid.c_str());
        for (SKPaymentTransaction *t in [SKPaymentQueue defaultQueue].transactions) {
            if ([t.transactionIdentifier isEqualToString:identifier]) {
                [[SKPaymentQueue defaultQueue] finishTransaction:t];
            } else if (t.originalTransaction && [t.originalTransaction.transactionIdentifier isEqualToString:identifier]) {
                [[SKPaymentQueue defaultQueue] finishTransaction:t.originalTransaction];
                [[SKPaymentQueue defaultQueue] finishTransaction:t];
            }
        }
    }
}

void apple::restoreTransactions(const std::string &appUsername)
{
    @autoreleasepool {
        if (appUsername.size() > 0) {
            [[SKPaymentQueue defaultQueue] restoreCompletedTransactionsWithApplicationUsername:toNSString(appUsername)];
        } else {
            [[SKPaymentQueue defaultQueue] restoreCompletedTransactions];
        }
    }
}

cocos2d::ValueVector apple::getPendingTransactions()
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

#endif // CCLUA_OS_IOS
