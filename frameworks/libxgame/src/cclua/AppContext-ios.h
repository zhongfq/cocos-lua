#import <UIKit/UIKit.h>

#import "Reachability.h"

@class AppRootViewController;

@interface AppContext : NSObject<UIApplicationDelegate> {
    NSMutableArray<id<UIApplicationDelegate>> *_delegates;
    NSDictionary * _launchOptions;
    BOOL _launchDone;
}

@property(nonatomic, readonly) AppRootViewController* viewController;
@property(readwrite, strong) Reachability* reachabe;
@property(readonly) BOOL isLaunchDone;

- (AppRootViewController *) createRootViewController;

- (void) addAppDelegate:(id<UIApplicationDelegate>) delegate;

- (NSString *)getNetworkStatus;

- (instancetype)init;
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
- (void)applicationWillResignActive:(UIApplication *)application;
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (void)applicationDidEnterBackground:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application;
- (void)applicationWillTerminate:(UIApplication *)application;
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application;

- (void)application:(UIApplication *)application
didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;

-(void)handleInterruption:(NSNotification*)notification;

@end

