//
//  WKCustomModel.h
//  QuickLogin
//
//  Created by bindx on 2020/10/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WKCustomModel : NSObject

#pragma mark -----------------------------授权页面----------------------------------

#pragma mark VC必传属性
/**当前VC,注意:要用一键登录这个值必传*/
@property (nonatomic,weak) UIViewController *currentVC;

#pragma mark 自定义控件
/**授权界面自定义控件View的Block*/
@property (nonatomic,copy) void(^authViewBlock)(UIView *customView, NSString *operatorType, CGRect numberFrame,CGRect loginBtnFrame, CGRect privacyFrame);

/**授权界面背景图片*/
@property (nonatomic,strong) UIImage *authPageBackgroundImage;

/**返回按钮图片*/
@property (nonatomic,strong) UIImage *backImg;

#pragma mark 登录按钮
/**登录按钮文本*/
@property (nonatomic,strong) NSAttributedString *logBtnText;

/**登录按钮Y偏移量*/
@property (nonatomic,strong) NSNumber * logBtnOffsetY;

/**登录按钮的左右边距 注意:按钮呈现的宽度在竖屏时必须大于屏幕的一半,横屏时必须大于屏幕的三分之一
 示例:@[@50,@70] 只能两个元素
 */
@property (nonatomic, strong) NSArray <NSNumber *> *logBtnOriginLR;

/**登录按钮高h 注意：必须大于40*/
@property (nonatomic, assign) CGFloat logBtnHeight;

/**1登录按钮背景图片添加到数组(顺序如下)
 @[激活状态的图片,失效状态的图片,高亮状态的图片]
*/
@property (nonatomic,strong) NSArray *logBtnImgs;
/**登录按钮高距离底部的高度*/
@property (nonatomic, strong) NSNumber *logBtnOffsetY_B;

#pragma mark 号码框设置
/**手机号码富文本属性 */
@property (nonatomic,strong) NSDictionary<NSAttributedStringKey,id> *numberTextAttributes;
/**号码栏X偏移量*/
@property (nonatomic,strong) NSNumber * numberOffsetX;
/**号码栏Y偏移量（基于底部）*/
@property (nonatomic,strong) NSNumber * numberOffsetY;
/**号码栏Y偏移量（基于底部）*/
@property (nonatomic,strong) NSNumber * numberOffsetY_B;

#pragma mark 隐私条款
/**隐私条款check框默认 是否显示 */
@property (nonatomic,assign) BOOL privacyShow;
/**复选框未选中时图片*/
@property (nonatomic,strong) UIImage *uncheckedImg;
/**复选框选中时图片*/
@property (nonatomic,strong) UIImage *checkedImg;
/**复选框大小（只能正方形）必须大于12*/
@property (nonatomic,strong) NSNumber *checkboxWH;
/**隐私条款（包括check框）的左右边距*/
@property (nonatomic, strong) NSArray <NSNumber *> *appPrivacyOriginLR;
/**隐私的内容模板：
 1、全句可自定义但必须保留"&&默认&&"字段表明SDK默认协议,否则设置不生效
 2、协议1和协议2的名称要与数组 str1 和 str2 ... 里的名称 一样
 3、必设置项（参考SDK的demo）
 appPrivacieDemo设置内容：登录并同意&&默认&&和&&百度协议&&、&&京东协议2&&登录并支持一键登录
 展示：   登录并同意中国移动条款协议和百度协议1、京东协议2登录并支持一键登录
 */
@property (nonatomic, copy) NSAttributedString *appPrivacyDemo;
/**隐私条款默认协议是否开启书名号
 */
@property (nonatomic, assign) BOOL privacySymbol;
/**隐私条款:数组（务必按顺序）要设置NSLinkAttributeName属性可以跳转协议
 对象举例：
 NSAttributedString *str1 = [[NSAttributedString alloc]initWithString:@"百度协议" attributes:@{NSLinkAttributeName:@"https://www.baidu.com"}];
 @[str1,,str2,str3,...]
 */
@property (nonatomic,strong) NSArray <NSAttributedString *> *appPrivacy;
/**隐私条款名称颜色（协议）统一设置
 */
@property (nonatomic,strong) UIColor *privacyColor;
/**隐私条款Y偏移量*/
@property (nonatomic,strong) NSNumber * privacyOffsetY;
/**隐私条款check框默认状态 默认:NO */
@property (nonatomic,assign) BOOL privacyState;
/**隐私条款Y偏移量(注:此属性为与屏幕底部的距离)*/
@property (nonatomic,strong) NSNumber *privacyOffsetY_B;
/**隐私协议点击回调(注:此属性用于自定义隐私协议页面)*/
@property (nonatomic,copy) void(^privacyClickBlock)(NSString *title, NSURL *url);

#pragma mark 窗口模式
/**窗口模式开关*/
@property (nonatomic,assign) BOOL authWindow;

/**自定义窗口弧度 默认是10*/
@property (nonatomic,assign) CGFloat cornerRadius;

/**自定义窗口宽-缩放系数(屏幕宽乘以系数) 默认是0.8*/
@property (nonatomic,assign) CGFloat scaleW;

/**自定义窗口高-缩放系数(屏幕高乘以系数) 默认是0.5*/
@property (nonatomic,assign) CGFloat scaleH;

@end

NS_ASSUME_NONNULL_END
