//
//  WXSpeechSynthesizer.h
//  WXVoiceSDK
//
//  Created by 宫亚东 on 13-12-24.
//  Copyright (c) 2013年 Tencent Research. All rights reserved.
//



/*!
 @header WXSpeechSynthesizer
 @abstract 微信语音合成单例类
 */

#import <Foundation/Foundation.h>

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
/** @brief  文本（或合成后的语音）过长 */
#define WXErrorOfTextOverlength     -403    //文本（或合成后的语音）过长

#endif

//语音合成
/** @brief  iOS没有用到的错误码 */
#define WXTTSErrorOfBreak           -401    //断点续传

/*其它错误
 //网络错误
 [-104,-100]网络底层错误
 [1,1000]系统错误码（通常也是由网络问题引起的）及[201, 505]HTTP错误码
 
 //服务错误
 [1000,++]服务器错误，
 */
//=============================================================


//----合成语音的格式
/** @brief  MP3，推荐使用的格式 */
#define SpeechFormatOfMP3 0     //MP3，推荐使用的格式
/** @brief  WAV，体积比较大 */
#define SpeechFormatOfWAV 1     //WAV，体积比较大
/** @brief  AMR，苹果不能直接播放的格式 */
#define SpeechFormatOfAMR 2     //AMR，苹果不能直接播放的格式


//--代理的回调方法----------------------------------------

/**
 *	@brief	语音合成回调代理的协议（任何一个回调都表示本次识别已经结束）
 */
@protocol WXVoiceTTSDelegate <NSObject>


/**
 *	@brief	在合成成功结束后，回调合成的语音数据
 *
 *	@param 	speechData 	合成后的语音数据
 *	@param 	speechFormat 	语音数据的格式
 */
- (void)WXVoiceTTSResultSpeechData:(NSData *)speechData speechFormat:(int)speechFormat;

/**
 *	@brief	出现错误时的回调方法
 *
 *	@param 	errorCode 	错误码请参见官方网站
 */
- (void)WXVoiceTTSMakeError:(NSInteger)errorCode;

/**
 *	@brief	已经取消合成，在手动调用的cancel，并完成取消后的回调
 */
- (void)WXVoiceTTSDidCancel;

@end

#import <Foundation/Foundation.h>

/**
 *	@brief	语音合成单例
 */
@interface WXVoiceTTS : NSObject

/**
 *	@brief	语音合成回调方法的代理
 */
@property (nonatomic,assign)id<WXVoiceTTSDelegate>delegate;

/**
 *	@brief	获取单例对象
 */
+ (instancetype)sharedWXVoiceTTS;

/**
 *	@brief	释放使用的资源及单例对象，下次使用时需重新获取单例对象并进行初始设置
 */
+ (void)releaseWXVoiceTTS;

/**
 *	@brief	在开始语音识别前，需要先设置APPID
 *
 *	@param 	appid 	微信公众平台的APPID
 */
- (void)setAppID:(NSString *)appid;

/**
 *	@brief	设置合成语音的格式，在下次语音合成时生效
 *
 *	@param 	speechFormat 	语音格式参数，默认为0，MP3格式，不建议修改
 */
- (void)setSpeechFormat:(int)speechFormat;

/**
 *	@brief	设置合成语音的音量，在下次语音合成时生效
 *
 *	@param 	volumn 	音量范围0-2
 */
- (void)setVolumn:(float)volumn;

/**
 *	@brief	开始合成语音，每次只能进行一次合成。
 *
 *	@param 	text 	要合成的文本
 *
 *	@return	YES 已开始；NO失败，失败信息见回调消息speechSynthesizerMakeError，如果上次识别没有结束而试图再次开始，返回值为NO且不会回调错误码
 */
- (BOOL)startWithText:(NSString *)text;

/**
 *	@brief	取消本次合成，需要等待回调消息speechSynthesizerDidCancel后，才能开始下次合成
 */
- (void)cancel;


@end
