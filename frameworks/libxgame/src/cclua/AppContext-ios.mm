#import "cclua/AppContext-ios.h"
#import "cclua/AppRootViewController-ios.h"
#import "cclua/runtime.h"
#import "cocos2d.h"

#import <AVFoundation/AVFoundation.h>

@implementation AppContext

@synthesize window;

#pragma mark -
#pragma mark Application lifecycle

- (AppRootViewController *) createRootViewController
{
    return [[AppRootViewController alloc] init];
}

- (void) addAppDelegate:(id<UIApplicationDelegate>) delegate
{
    if (![_delegates containsObject:delegate]) {
        [_delegates addObject:delegate];
        
        if (_launchDone) {
            [delegate application:[UIApplication sharedApplication] didFinishLaunchingWithOptions:_launchOptions];
        }
    }
}

- (instancetype)init
{
    _delegates = [[NSMutableArray alloc] init];
    _launchOptions = nil;
    _launchDone = NO;
    return [super init];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    cocos2d::Application *app = cocos2d::Application::getInstance();
    app->initGLContextAttrs();
    cocos2d::GLViewImpl::convertAttrs();

    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    
    [[UIApplication sharedApplication] setIdleTimerDisabled: YES];

    _viewController = [self createRootViewController];
    [window setRootViewController:_viewController];
    [window makeKeyAndVisible];
    [window setMultipleTouchEnabled:YES];
    
    //Launching the app with the arguments -NSAllowsDefaultLineBreakStrategy NO to force back to the old behavior.
    if ( [[UIDevice currentDevice].systemVersion floatValue] >= 13.0f)
    {
        [[NSUserDefaults standardUserDefaults] setBool:NO forKey:@"NSAllowsDefaultLineBreakStrategy"];
    }
    
    cocos2d::GLView *glview = cocos2d::GLViewImpl::createWithEAGLView((__bridge void *)_viewController.view);
    cocos2d::Director::getInstance()->setOpenGLView(glview);
    
    app->run();
    
    cclua::runtime::setAudioSessionCatalog([AVAudioSessionCategoryAmbient UTF8String]);
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleInterruption:) name:UIApplicationDidBecomeActiveNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleInterruption:) name:kReachabilityChangedNotification object:nil];
    
    self.reachabe = [Reachability reachabilityForInternetConnection];
    [self.reachabe startNotifier];
    
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(application:didFinishLaunchingWithOptions:)]) {
            [obj application:application didFinishLaunchingWithOptions:launchOptions];
        }
    }
    
    _launchDone = YES;
    _launchOptions = [NSDictionary dictionaryWithDictionary:launchOptions];

    return YES;
}

- (NSString *)getNetworkStatus
{
    NetworkStatus status = [self.reachabe currentReachabilityStatus];
    if (status == ReachableViaWiFi) {
        return @"WIFI";
    } else if (status == ReachableViaWWAN) {
        return @"MOBILE";
    } else {
        return @"NONE";
    }
}

-(void)handleInterruption:(NSNotification*)notification
{
    if ([notification.name isEqualToString:kReachabilityChangedNotification])
    {
        NetworkStatus status = [self.reachabe currentReachabilityStatus];
        if (status == NotReachable) {
            cclua::runtime::dispatchEvent("networkChange", "NONE");
        } else if (status == ReachableViaWiFi) {
            cclua::runtime::dispatchEvent("networkChange", "WIFI");
        } else if (status == ReachableViaWWAN) {
            cclua::runtime::dispatchEvent("networkChange", "MOBILE");
        }
    }
    else if ([notification.name isEqualToString:UIApplicationDidBecomeActiveNotification])
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            std::string catalog = cclua::runtime::getAudioSessionCatalog();
            
            if (catalog.size() > 0) {
                cclua::runtime::setAudioSessionCatalog(catalog);
            }
            if (cocos2d::Director::getInstance()->isPaused() && [UIApplication sharedApplication].applicationState == UIApplicationStateActive)
            {
                cclua::runtime::log("post notification 'AVAudioSessionInterruptionTypeEnded'");
                NSDictionary *info = @{AVAudioSessionInterruptionTypeKey:[NSNumber numberWithInteger:AVAudioSessionInterruptionTypeEnded]};
                [[NSNotificationCenter defaultCenter] postNotificationName:AVAudioSessionInterruptionNotification object:[AVAudioSession sharedInstance] userInfo:info];
            }
        });
    }
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
{
    cclua::runtime::handleOpenURL([[url absoluteString] UTF8String]);
    
    BOOL ret = NO;
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(application:openURL:options:)]) {
            ret = [obj application:application openURL:url options:options];
        }
    }
    
    return ret;
}

- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler
{
    BOOL ret = NO;
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(application:continueUserActivity:restorationHandler:)]) {
            ret = [obj application:application continueUserActivity:userActivity restorationHandler:restorationHandler];
        }
    }
    return ret;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(applicationWillResignActive:)]) {
            [obj applicationWillResignActive:application];
        }
    }
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(applicationDidBecomeActive:)]) {
            [obj applicationDidBecomeActive:application];
        }
    }
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(applicationDidEnterBackground:)]) {
            [obj applicationDidEnterBackground:application];
        }
    }
    ((cclua::RuntimeContext *)cocos2d::Application::getInstance())->applicationDidEnterBackground();
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(applicationWillEnterForeground:)]) {
            [obj applicationWillEnterForeground:application];
        }
    }
    ((cclua::RuntimeContext *)cocos2d::Application::getInstance())->applicationWillEnterForeground();
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(applicationWillTerminate:)]) {
            [obj applicationWillTerminate:application];
        }
    }
    ((cclua::RuntimeContext *)cocos2d::Application::getInstance())->applicationWillTerminate();
}

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application
{
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(applicationDidReceiveMemoryWarning:)]) {
            [obj applicationDidReceiveMemoryWarning:application];
        }
    }
    cclua::runtime::dispatchEvent("memoryWarning", "");
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(application:didRegisterForRemoteNotificationsWithDeviceToken:)]) {
            [obj application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
        }
    }
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
{
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(application:didFailToRegisterForRemoteNotificationsWithError:)]) {
            [obj application:application didFailToRegisterForRemoteNotificationsWithError:error];
        }
    }
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler
{
    for (id<UIApplicationDelegate> obj in _delegates) {
        if ([obj respondsToSelector:@selector(application:didReceiveRemoteNotification:fetchCompletionHandler:)]) {
            [obj application:application didReceiveRemoteNotification:userInfo fetchCompletionHandler:completionHandler];
        }
    }
}

@end
