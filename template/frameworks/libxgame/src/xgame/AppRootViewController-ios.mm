#import "xgame/AppRootViewController-ios.h"
#import "cocos2d.h"
#import "platform/ios/CCEAGLView-ios.h"

@implementation AppRootViewController

- (void)loadView
{
    GLContextAttrs attrs = cocos2d::GLView::getGLContextAttrs();
    CCEAGLView *eaglView = [CCEAGLView viewWithFrame: [UIScreen mainScreen].bounds
                                         pixelFormat: (__bridge NSString *)cocos2d::GLViewImpl::_pixelFormat
                                         depthFormat: cocos2d::GLViewImpl::_depthFormat
                                  preserveBackbuffer: NO
                                          sharegroup: nil
                                       multiSampling: attrs.multisamplingCount > 0 ? YES : NO
                                     numberOfSamples: attrs.multisamplingCount ];
    
    // Enable or disable multiple touches
    [eaglView setMultipleTouchEnabled:YES];
    
    // Set EAGLView as view of RootViewController
    self.view = eaglView;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
}

- (NSUInteger) supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskAllButUpsideDown;
}

- (BOOL) shouldAutorotate
{
    return YES;
}

- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator
{
    [super viewWillTransitionToSize:size withTransitionCoordinator:coordinator];
    
    auto glview = cocos2d::Director::getInstance()->getOpenGLView();
    
    if (glview)
    {
        CCEAGLView *eaglview = (__bridge CCEAGLView *)glview->getEAGLView();
        
        if (eaglview)
        {
            CGSize s = CGSizeMake([eaglview getWidth], [eaglview getHeight]);
            cocos2d::Application::getInstance()->applicationScreenSizeChanged((int) s.width, (int) s.height);
        }
    }
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}

- (BOOL)prefersHomeIndicatorAutoHidden
{
    return YES;
}

-(UIRectEdge)preferredScreenEdgesDeferringSystemGestures
{
    return UIRectEdgeBottom; 
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}


@end
