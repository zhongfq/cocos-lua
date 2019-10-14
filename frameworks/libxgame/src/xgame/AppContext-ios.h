#import <UIKit/UIKit.h>

#import "Reachability.h"

@class AppRootViewController;

@interface AppContext : NSObject<UIApplicationDelegate> {
}

@property(nonatomic, readonly) AppRootViewController* viewController;
@property(readwrite, strong) Reachability* reachabe;

- (AppRootViewController *) createRootViewController;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
- (void)applicationWillResignActive:(UIApplication *)application;
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (void)applicationDidEnterBackground:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application;
- (void)applicationWillTerminate:(UIApplication *)application;
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application;
- (NSString *)getNetworkStatus;

-(void)handleInterruption:(NSNotification*)notification;

@end

