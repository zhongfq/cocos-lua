


//  兼容以前版本的文件名和类名
//  新用户请不要使用该文件，此文件后期会删除

#ifndef _WXSpeechSynthesizer_H_
#define _WXSpeechSynthesizer_H_

#define WXSpeechSynthesizer WXVoiceTTS
#define WXSpeechSynthesizerDelegate WXVoiceTTSDelegate
#define speechSynthesizerResultSpeechData WXVoiceTTSResultSpeechData
#define speechSynthesizerMakeError WXVoiceTTSMakeError
#define speechSynthesizerDidCancel WXVoiceTTSDidCancel

#define sharedSpeechSynthesizer sharedWXVoiceTTS
#define releaseSpeechSynthesizer releaseWXVoiceTTS 

#import "WXVoiceTTS.h"

#endif

