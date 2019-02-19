#import "xgame/AppContext-ios.h"
#import "xgame/AppRootViewController-ios.h"
#import "xgame/xruntime.h"

#import "cocos2d.h"

@implementation AppContext

@synthesize window;

#pragma mark -
#pragma mark Application lifecycle

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    cocos2d::Application *app = cocos2d::Application::getInstance();
    app->initGLContextAttrs();
    cocos2d::GLViewImpl::convertAttrs();

    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];

    _viewController = [[AppRootViewController alloc]init];
    [window setRootViewController:_viewController];
    [window makeKeyAndVisible];
    [window setMultipleTouchEnabled:YES];
    
    cocos2d::GLView *glview = cocos2d::GLViewImpl::createWithEAGLView((__bridge void *)_viewController.view);
    cocos2d::Director::getInstance()->setOpenGLView(glview);
    
    app->run();

    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application
{
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    ((xgame::RuntimeContext *)cocos2d::Application::getInstance())->applicationDidEnterBackground();
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    ((xgame::RuntimeContext *)cocos2d::Application::getInstance())->applicationWillEnterForeground();
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    ((xgame::RuntimeContext *)cocos2d::Application::getInstance())->applicationWillTerminate();
}


#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application
{
}

#if __has_feature(objc_arc)
#else
- (void)dealloc
{
    [window release];
    [_viewController release];
    [super dealloc];
}
#endif


@end
