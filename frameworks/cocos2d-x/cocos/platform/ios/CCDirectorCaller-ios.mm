/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "platform/CCPlatformConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#include <mach/mach_time.h>

#import "platform/ios/CCDirectorCaller-ios.h"

#import <Foundation/Foundation.h>
#import <OpenGLES/EAGL.h>

#import "base/CCDirector.h"
#import "platform/ios/CCEAGLView-ios.h"

static id s_sharedDirectorCaller;

@implementation CCDirectorCaller

@synthesize preferredFramesPerSecond;

+(id) sharedDirectorCaller
{
    if (s_sharedDirectorCaller == nil)
    {
        s_sharedDirectorCaller = [[CCDirectorCaller alloc] init];
    }
    
    return s_sharedDirectorCaller;
}

+(void) destroy
{
    [s_sharedDirectorCaller stopMainLoop];
    [s_sharedDirectorCaller release];
    s_sharedDirectorCaller = nil;
}


- (instancetype)init
{
    if (self = [super init])
    {
        isAppActive = [UIApplication sharedApplication].applicationState == UIApplicationStateActive;
        NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
        [nc addObserver:self selector:@selector(appDidBecomeActive) name:UIApplicationDidBecomeActiveNotification object:nil];
        [nc addObserver:self selector:@selector(appDidBecomeInactive) name:UIApplicationWillResignActiveNotification object:nil];
        
        self.preferredFramesPerSecond = 60;
        displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(doCaller:)];
        displayLink.preferredFramesPerSecond = self.preferredFramesPerSecond;
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    }
    return self;
}

-(void) dealloc
{
    [displayLink invalidate];
    [displayLink release];
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    [super dealloc];
}

- (void)appDidBecomeActive
{
    // initialize initLastDisplayTime, or the dt will be invalid when
    // - the app is lauched
    // - the app resumes from background
    [self initLastDisplayTime];

    isAppActive = YES;
}

- (void)appDidBecomeInactive
{
    isAppActive = NO;
}

-(void) startMainLoop
{
    displayLink.paused = false;
}

-(void) stopMainLoop
{
    displayLink.paused = true;
}

-(void) setAnimationInterval:(double)intervalNew
{
    self.preferredFramesPerSecond = (int)round((1.0 / intervalNew));
    displayLink.preferredFramesPerSecond = self.preferredFramesPerSecond;
}
                      
-(void) doCaller: (id) sender
{
    if (isAppActive) {
        cocos2d::Director* director = cocos2d::Director::getInstance();
        CFTimeInterval dt = ((CADisplayLink*)displayLink).timestamp - lastDisplayTime;
        lastDisplayTime = ((CADisplayLink*)displayLink).timestamp;
        director->mainLoop(dt);
    }
}

-(void)initLastDisplayTime
{
    struct mach_timebase_info timeBaseInfo;
    mach_timebase_info(&timeBaseInfo);
    CGFloat clockFrequency = (CGFloat)timeBaseInfo.denom / (CGFloat)timeBaseInfo.numer;
    clockFrequency *= 1000000000.0;
    // convert absolute time to seconds and should minus one frame time interval
    lastDisplayTime = (mach_absolute_time() / clockFrequency) - (1.0 / self.preferredFramesPerSecond);
}

//
-(void)setActive:(BOOL)isActive
{
    isAppActive = isActive;
}

@end

#endif // CC_TARGET_PLATFORM == CC_PLATFORM_IOS

