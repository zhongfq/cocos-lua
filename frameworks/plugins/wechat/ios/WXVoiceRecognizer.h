//
//  WXVoiceSDK.h
//  WXVoiceSDK
//
//  Created by Liusong on 16-12-20.
//  Copyright (c) 2013年 Tencent Research. All rights reserved.
//



#import <Foundation/Foundation.h>

#ifndef _WXVoice_WXNetDelegate_NSObject_
#define _WXVoice_WXNetDelegate_NSObject_
#define TENCENT_INNER
/**
 *	@brief	当手动转发网络数据传送时，网络返回数据的协议
 */
@protocol WXNetDelegate<NSObject>

/**
 *	@brief	收到的网络数据从这里送入SDK，不管是取消还是网络出错，只要有- (BOOL)shouldSendData:(NSData *)data withUrlArgs:(NSString *)args delegate:(id<WXNetDelegate>)delegate;就一定要有返回
 *
 *	@param 	data 	传入从网络收到的数据
 */
- (void)didRecvData:(NSData *)data;


@end

#endif // ~_WXVoice_WXNetDelegate_NSObject_


//--------------------------------错误码------------------------
//公用
#ifndef __WX_Error_Code_Base__
#define __WX_Error_Code_Base__


/** @brief  没错误0 */
#define WXErrorOfSuccess            0       //没错误0
/** @brief	没有网络 */
#define WXErrorOfNoNetWork          -201    //没有网络
/** @brief	网络超时错误 */
#define WXErrorOfTimeOut            -202    //网络超时错误
/** @brief	配额用完 */
#define WXErrorOfQuotaExhaust       -203    //配额用完
/** @brief	AppId 不存在或失效 */
#define WXErrorOfAppIDError         -204    //AppId 不存在或失效
/** @brief  文本为空（在语音识别中指的是，Grammar文本） */
#define WXErrorOfTextNull           -402    //文本为空（在语音识别中指的是，Grammar文本）
/** @brief  文本过长 */
#define WXErrorOfTextOverlength     -403    //文本过长



//语音识别
/** @brief	没有说话(或音量过小) */
#define WXVoiceRecoErrorOfNoSound           -301    //没有说话(或音量过小)
/** @brief	语音过长 */
#define WXVoiceRecoErrorOfVoiceTooLarge     -302    //语音过长
/** @brief	录音出错 */
#define WXVoiceRecoErrorOfRecord            -303    //录音出错
/** @brief	麦克风被禁用 */
#define WXVoiceRecoErrorOfCannotUseMic      -304    //麦克风被禁用


/*其它错误
 //网络错误
 [-104,-100]网络底层错误
 [1,1000]系统错误码（通常也是由网络问题引起的）及[201, 505]HTTP错误码
 
 //服务错误
 [1000,++]服务器错误，
 */

//下面是兼容之前版本的错误码名称，
#define WXVoiceErrorOfSuccess       0
#define WXVoiceErrorOfNoNetWork     -201
#define WXVoiceErrorOfTimeOut       -202
#define WXVoiceErrorOfQuotaExhaust  -203
#define WXVoiceErrorOfAppIDError    -204
#define WXVoiceErrorOfNoSound       -301
#define WXVoiceErrorOfVoiceTooLarge -302
#define WXVoiceErrorOfRecord        -303
#define WXVoiceErrorOfCannotUseMic  -304
#define WXVoiceErrorOfSilence       -401

#endif

//=============================================================

@protocol WXRecorderDataDelegate <NSObject>

@optional

// data: 16bit 的单声道 pcm音频数据
// sampleRate: 采样率，取值为8000或者16000
// end: 是否为最后一块数据

//  在一次录音中可能会多次回调此函数，每次返回新的录音数据。一次录音中，每次返回的sampleRate都相同
- (void)recorderData:(NSData*)data withSampleRate:(int)sampleRate isEnd:(BOOL)end;

@end


typedef enum {
    GrammarTypeOfABNF = 0, /**< 语法识别 */
	GrammarTypeOfWordlist = 1 /**< 词表识别 */
}WXGrammarType;

//--返回结果的元素类型（返回结果是由此类型组成的NSArray）------

/**
 *	@brief	语音识别结果的数据模型
 */
@interface WXVoiceResult : NSObject
/**
 *	@brief	语音识别结果的文本内容
 */
@property (nonatomic,copy)NSString *text;
@property (nonatomic,assign)NSString *voice_id;
@property (nonatomic,assign)NSInteger startOffset;
@property (nonatomic,assign)NSInteger endOffset;

/**
 *	@brief	是否为最终结果，在流式识别的情况下，会有很多中间结果返回
 */
@property (nonatomic, assign)BOOL isEnd;

@end

//--代理的回调方法----------------------------------------

/**
 *	@brief	语音识别回调代理的协议
 */
@protocol WXVoiceDelegate <NSObject>

/**
 *	@brief	在识别结束后，回调识别到的结果
 *
 *	@param 	array 	识别结果的数组，元素类型为WXVoiceResult，现阶段数组内只有一个元素
 */
- (void)voiceInputResultArray:(NSArray *)array;

/**
 *	@brief	出现错误时的回调消息
 *
 *	@param 	errorCode 	错误码请参见官方网站
 */
- (void)voiceInputMakeError:(NSInteger)errorCode;

/**
 *	@brief	录音停止时的回调，此时不再接受新的语音，只是等待服务器返回识别结果
 */
- (void)voiceInputWaitForResult;

/**
 *	@brief	已经取消识别，在手动调用cancel并完成取消后的回调
 */
- (void)voiceInputDidCancel;

@optional

/**
 *	@brief	回调音量，wifi网络下约每秒回调25次，2g网络下次数减半
 *
 *	@param 	volumn 	音量大小，界限为0-30，通常音量范围在0-15之间
 */
- (void)voiceInputVolumn:(float)volumn;

@optional // for hand-send
/**
 *	@brief	是否要发送数据到网络
 *
 *	@param 	data 	数据
 *	@param 	args 	url上的get参数
 *	@param 	delegate    从网络收到的数据从这里传回
 *
 *	@return	如果手动发送，请返回 NO
 */
- (BOOL)shouldSendData:(NSData *)data withUrlArgs:(NSString *)args delegate:(id<WXNetDelegate>)delegate;

@optional // for debug
//查看网络返回的数据  主要用于调试
//优先使用第一个返回JSON字符串，第一个没实现方法，才会返回NSData，都不实现则都不返回
- (void)connectionResultJSonNSString:(NSString *)jsonStr;
- (void)connectionResultData:(NSData *)data;

@end

typedef enum{
  MANDARIN,
  CANTONESE
} LanguageType;

@class WXSpeechRecognizerConnection;
/**
 *	@brief	语音识别单例
 */
@interface WXVoiceRecognizer : NSObject 

/**
 *	@brief	语音识别回调消息的代理
 */
@property (nonatomic,assign)id<WXVoiceDelegate>delegate;

@property (nonatomic,assign)id<WXRecorderDataDelegate>recorderDataDelegate;

/**
 *	@brief	静音检查时间，开始录音，并检测到有语音产生后，超过此时间没有声音，则自动完成本次录音，默认1.5（秒）
 */
@property (nonatomic,assign)float silTime;

/**
 *	@brief	服务类型，默认10
 */
@property (nonatomic,assign)int domain;
/**
 *	@brief	获取单例对象。
 */
+ (instancetype)sharedWXVoice;

/**
 *	@brief	释放使用的资源及单例对象，下次使用时需重新获取单例对象并进行初始设置
 */
+ (void)releaseWXVoice;

/**
 *	@brief	在开始语音识别前，需要先设置APPID
 *
 *	@param 	appid 	微信公众平台的APPID
 */
- (void)setAppID:(NSString *)appid;


/**
 *	@brief	设置是否使用流式方式，默认不使用
 *
 */
- (void)setContinuousMode:(BOOL)cont;

/**
 *	@brief	设置语言，默认为MANDARIN
 *
 */
- (void)setLanguageType:(LanguageType)type;

/**
 *	@brief	开始一次语音识别。录音并进行识别，当长时间静默时（默认设置为：开始5秒仍没有说话，或者说话后1.5秒）录音会停止。
 *
 *	@return YES 开始进行识别；NO 开始失败，失败信息见回调消息voiceInputMakeError，如果上次识别没有结束而试图再次开始，返回值为NO且不会回调错误码
 */
- (BOOL)startOnce;
/**
 *	@brief	使用词表进行语音识别，是startOnce的重载
 *
 *	@param 	words 	符合词表或语法格式的字符串
 *	@param 	type 	类型是词表还是语法
 *
 *	@return YES 开始进行识别；NO 开始失败，失败信息见回调消息voiceInputMakeError，如果上次识别没有结束而试图再次开始，返回值为NO且不会回调错误码
 */
- (BOOL)startOnceWithGrammarString:(NSString *)words andType:(WXGrammarType)type;

/**
 *	@brief	结束本次录音，等待识别结果，调用此方法后，不再继续录音，只等待服务器返回当前已录音的识别结果
 */
- (void)finish;

/**
 *	@brief	取消本次识别，调用此方法开始取消本次识别，取消完成后会有回调消息voiceInputDidCancel
 */
- (void)cancel;


/**
 *	@brief	开始连续语音识别，由SDK持续录音并进行识别。当长时间静默时，识别一次；再次说话会继续识别，直到调用stopContinusMode；
 *
 *	@return YES 开始进行识别；NO 开始失败，失败信息见回调消息voiceInputMakeError，如果上次识别没有结束而试图再次开始，返回值为NO且不会回调错误码
 */
-(BOOL)startContinusMode;
-(BOOL)stopContinusMode;


/**
 *	@brief	开始连续语音识别。识别数据由调用者提供,调用Add16bitPCMData增加数据.调用结束可以设置isend=yes;
 *
 *	@return YES 开始进行识别；NO 开始失败，失败信息见回调消息voiceInputMakeError，如果上次识别没有结束而试图再次开始，返回值为NO且不会回调错误码
 */
- (BOOL)startWith16bitPCMData;
- (BOOL)Add16bitPCMData:(NSData *)data sampleRate:(int)sampleRate;
- (BOOL)Add16bitPCMData:(NSData *)data sampleRate:(int)sampleRate isEnd:(BOOL)isEnd;
- (void)finishWith16bitPCMData;

/**
 *	@brief	开始一次整句的语音识别。识别数据由调用者提供；
 *
 *	@return YES 开始进行识别；NO 开始失败，失败信息见回调消息voiceInputMakeError，如果上次识别没有结束而试图再次开始，返回值为NO且不会回调错误码
 */
- (BOOL)startOnceWith16bitPCMData:(NSData *)data sampleRate:(int)sampleRate;


//设置最多可以识别出多少种结果，默认15
//- (void)setMaxResultCount:(NSInteger)count;
// 设置识别类型，0无标点，1有标点，默认值0
- (void)setResultType:(NSInteger)type;

@end


@interface WXVoiceRecognizer (forQQMap)
//server或appUrl参数为nil则表示使用SDK默认设置
- (void)setServer:(NSString *)server andPort:(NSInteger)port;
- (void)setHostName:(NSString *)hostName;
- (void)setAppendUrlString:(NSString *)appUrl;//如：   @"/cgi-bin/voicereco"
- (void)setAppendUrlParameterString:(NSString *)parameterString;
@end

@interface WXVoiceRecognizer (forTest)
// 开启鉴权：内部SDK默认不开启；外发SDK默认开启
- (void)openAuth;
@end



