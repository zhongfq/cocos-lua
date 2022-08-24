#import "microphone.h"
#import "cclua/plugin-ios.h"
#import "cclua/filesystem.h"

#if defined(CCLUA_OS_IOS)

#import <AVFoundation/AVFoundation.h>

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

static bool _running = false;
Callback microphone::_dispatcher;

@interface RecorderDelegate : NSObject
@property(readwrite, strong, nonatomic) NSString *path;
@property(readwrite, strong, nonatomic) NSString *sessionCatalog;
@property(readwrite, strong, nonatomic) AVAudioRecorder *recorder;

+ (instancetype) defaultDelegate;

- (instancetype)init;
- (void)startRecording:(NSString *)path;
- (void)stopRecording;

@end

@implementation RecorderDelegate

+ (instancetype) defaultDelegate
{
    static RecorderDelegate *inst = nil;
    if (inst == nil) {
        inst = [[RecorderDelegate alloc] init];
    }
    return inst;
}

- (instancetype)init
{
    self.path = nil;
    self.recorder = nil;
    return [super init];
}

- (void)startRecording:(NSString *)path
{
    self.path = path;
    self.sessionCatalog = [NSString stringWithUTF8String:runtime::getAudioSessionCatalog().c_str()];
        
    NSError *error;
    AVAudioSession *session = [AVAudioSession sharedInstance];
    [session setCategory:AVAudioSessionCategoryRecord error:&error];
    [session setActive:YES error:nil];
    
    NSMutableDictionary *recordSetting = [[NSMutableDictionary alloc] init];
    [recordSetting setValue:[NSNumber numberWithInt:kAudioFormatLinearPCM] forKey:AVFormatIDKey];
    [recordSetting setValue:[NSNumber numberWithFloat:44100.0] forKey:AVSampleRateKey];
    [recordSetting setValue:[NSNumber numberWithInt: 2] forKey:AVNumberOfChannelsKey];
    [recordSetting setValue:[NSNumber numberWithInt:AVAudioQualityHigh] forKey:AVEncoderAudioQualityKey];

    self.recorder = [[AVAudioRecorder alloc] initWithURL:[NSURL fileURLWithPath:self.path] settings:recordSetting error:&error];
    
    if (self.recorder == nil) {
        cocos2d::ValueMap data;
        data["status"] = "ioerror";
        data["statusMessage"] = "write file error: " + std::string([path UTF8String]);
        microphone::dispatch("start", data);
    } else {
        [self.recorder prepareToRecord];
        [_recorder setMeteringEnabled:YES];
        [self.recorder record];
        _running = true;
        cocos2d::ValueMap data;
        data["status"] = "started";
        microphone::dispatch("start", data);
    }
}

- (void)stopRecording
{
    if (self.recorder != nil) {
        [self.recorder stop];
        self.recorder = nil;
        [[AVAudioSession sharedInstance] setCategory:self.sessionCatalog error:nil];
        runtime::setAudioSessionCatalog([self.sessionCatalog UTF8String]);
        _running = false;
    }
}

@end

void microphone::start(const std::string &path)
{
    @autoreleasepool {
        if (_running) {
            runtime::log("recorder is running");
            return;
        }
        [[RecorderDelegate defaultDelegate] startRecording:toNSString(path)];
    }
}

void microphone::stop()
{
    @autoreleasepool {
        [[RecorderDelegate defaultDelegate] stopRecording];
    }
}

bool microphone::isRunning()
{
    return _running;
}

#endif // CCLUA_OS_IOS
