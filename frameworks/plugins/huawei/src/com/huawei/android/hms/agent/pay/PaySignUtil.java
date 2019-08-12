package com.huawei.android.hms.agent.pay;

import android.text.TextUtils;
import android.util.Base64;

import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.hms.support.api.entity.pay.HwPayConstant;
import com.huawei.hms.support.api.entity.pay.OrderRequest;
import com.huawei.hms.support.api.entity.pay.PayReq;
import com.huawei.hms.support.api.entity.pay.ProductPayRequest;
import com.huawei.hms.support.api.entity.pay.PurchaseInfo;
import com.huawei.hms.support.api.entity.pay.PurchaseInfoRequest;
import com.huawei.hms.support.api.pay.OrderResult;
import com.huawei.hms.support.api.pay.PayResultInfo;
import com.huawei.hms.support.api.pay.ProductPayResultInfo;
import com.huawei.hms.support.api.pay.PurchaseInfoResult;

import java.security.KeyFactory;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 支付签名工具类,
 * 签名和验签需要使用到私钥和公钥。
 * 对于私钥是非常保密的信息，强烈建议将私钥存储在服务端，由开发者的服务器对请求字符串进行签名。签名方法可以参考本类的实现。
 * 对于单机应用没有服务器支持的，可以直接使用此工具类的接口。私钥要注意加密保护，以确保私钥不会被泄露。
 */
public final class PaySignUtil {
    /**
     * 使用加密算法规则
     */
    private static final String SIGN_ALGORITHMS = "SHA256WithRSA";

    /**
     * 字符串编码
     */
    private static final String CHARSET = "UTF-8";

    private PaySignUtil() {
    }

    /**
     * 对于私钥是非常保密的信息，强烈建议将私钥存储在服务端。
     * 开发者首先调用getStringForSign获取待签名字符串，然后将待签名字符串发送到服务器，由开发者服务端对待签名字符串进行签名。
     * 签名方法可以参考rsaSign方法的实现。
     * @deprecated
     * @param request 要计算签名的请求
     * @param privKey 私钥
     * @return 生成的签名字符串
     */
    public static String calculateSignString(PayReq request, String privKey) {
        return rsaSign(getStringForSign(request), privKey);
    }

    /**
     * 对于私钥是非常保密的信息，强烈建议将私钥存储在服务端。
     * 开发者首先调用getStringForSign获取待签名字符串，然后将待签名字符串发送到服务器，由开发者服务端对待签名字符串进行签名。
     * 签名方法可以参考rsaSign方法的实现。
     * @deprecated
     * @param request 要计算签名的请求
     * @param privKey 私钥
     * @return 生成的签名字符串
     */
    public static String calculateSignString(OrderRequest request, String privKey) {
        return rsaSign(getStringForSign(request), privKey);
    }

    /**
     * 对于私钥是非常保密的信息，强烈建议将私钥存储在服务端。
     * 开发者首先调用getStringForSign获取待签名字符串，然后将待签名字符串发送到服务器，由开发者服务端对待签名字符串进行签名。
     * 签名方法可以参考rsaSign方法的实现。
     * @deprecated
     * @param request 要计算签名的请求
     * @param privKey 私钥
     * @return 生成的签名字符串
     */
    public static String calculateSignString(ProductPayRequest request, String privKey) {
        return rsaSign(getStringForSign(request), privKey);
    }

    /**
     * 对于私钥是非常保密的信息，强烈建议将私钥存储在服务端。
     * 开发者首先调用getStringForSign获取待签名字符串，然后将待签名字符串发送到服务器，由开发者服务端对待签名字符串进行签名。
     * 签名方法可以参考rsaSign方法的实现。
     * @deprecated
     * @param request 要计算签名的请求
     * @param privKey 私钥
     * @return 生成的签名字符串
     */
    public static String calculateSignString(PurchaseInfoRequest request, String privKey) {
        return rsaSign(getStringForSign(request), privKey);
    }

    /**
     * 计算支付请求的待签名字符串
     * 在服务端进行签名的cp，可以将此方法返回的字符串传给自己发服务端进行签名
     * @param request 支付请求
     */
    public static String getStringForSign(PayReq request) {

        Map<String, Object>  params = new HashMap<String, Object>();

        // 必选参数
        params.put(HwPayConstant.KEY_MERCHANTID, request.getMerchantId());
        params.put(HwPayConstant.KEY_APPLICATIONID, request.getApplicationID());
        params.put(HwPayConstant.KEY_PRODUCTNAME, request.getProductName());
        params.put(HwPayConstant.KEY_PRODUCTDESC, request.getProductDesc());
        params.put(HwPayConstant.KEY_REQUESTID, request.getRequestId());
        params.put(HwPayConstant.KEY_AMOUNT, request.getAmount());

        // 可选参数
        params.put(HwPayConstant.KEY_PARTNER_IDS, request.getPartnerIDs());
        params.put(HwPayConstant.KEY_CURRENCY, request.getCurrency());
        params.put(HwPayConstant.KEY_COUNTRY, request.getCountry());
        params.put(HwPayConstant.KEY_URL, request.getUrl());
        params.put(HwPayConstant.KEY_URLVER, request.getUrlVer());
        params.put(HwPayConstant.KEY_EXPIRETIME, request.getExpireTime());
        params.put(HwPayConstant.KEY_SDKCHANNEL, request.getSdkChannel());

        return getNoSign(params, false);
    }

    /**
     * 计算查询订单请求的待签名字符串
     * 在服务端进行签名的cp，可以将此方法返回的字符串传给自己发服务端进行签名
     * @param request 查询订单请求
     */
    public static String getStringForSign(OrderRequest request) {
        Map<String, Object> params = new HashMap<String, Object>();

        // 必选
        params.put("merchantId", request.getMerchantId());
        params.put("requestId", request.getRequestId());
        params.put("keyType", request.getKeyType());
        params.put("time", request.getTime());

        return getNoSign(params, false);
    }

    /**
     * 计算PMS支付请求的待签名字符串
     * 在服务端进行签名的cp，可以将此方法返回的字符串传给自己发服务端进行签名
     * @param request PMS支付请求
     */
    public static String getStringForSign(ProductPayRequest request) {
        Map<String, Object>  params = new HashMap<String, Object>();

        // 必选参数
        params.put(HwPayConstant.KEY_MERCHANTID, request.getMerchantId());
        params.put(HwPayConstant.KEY_APPLICATIONID, request.getApplicationID());
        params.put(HwPayConstant.KEY_PRODUCT_NO, request.getProductNo());
        params.put(HwPayConstant.KEY_REQUESTID, request.getRequestId());
        params.put(HwPayConstant.KEY_SDKCHANNEL, request.getSdkChannel());

        // 可选参数
        params.put(HwPayConstant.KEY_URL, request.getUrl());
        params.put(HwPayConstant.KEY_URLVER, request.getUrlVer());

        return getNoSign(params, false);
    }

    /**
     * 计算查询非消耗商品订单请求的待签名字符串
     * 在服务端进行签名的cp，可以将此方法返回的字符串传给自己发服务端进行签名
     * @param request 查询非消耗商品订单请求
     */
    public static String getStringForSign(PurchaseInfoRequest request) {
        Map<String, Object>  params = new HashMap<String, Object>();

        // 必选参数
        params.put("merchantId", request.getMerchantId());
        params.put("appId", request.getAppId());
        params.put("priceType", request.getPriceType());
        params.put("ts", request.getTs());

        // 可选参数
        params.put("productId", request.getProductId());
        params.put("pageNo", request.getPageNo());

        return getNoSign(params, false);
    }

    /**
     * 对支付结果的签名进行校验
     * @param rst 支付结果
     * @param pubKey 公钥
     * @return 是否校验通过
     */
    public static boolean checkSign(PayResultInfo rst, String pubKey) {

        if (rst == null || pubKey == null) {
            return false;
        }

        Map<String, Object> paramsa = new HashMap<String, Object>();

        // 必选参数
        paramsa.put("returnCode", rst.getReturnCode());
        paramsa.put("userName", rst.getUserName());
        paramsa.put("requestId", rst.getRequestId());
        paramsa.put("amount", rst.getAmount());
        paramsa.put("time", rst.getTime());

        // 可选参数
        paramsa.put("orderID", rst.getOrderID());
        paramsa.put("withholdID", rst.getWithholdID());
        paramsa.put("errMsg", rst.getErrMsg());

        String noSignStr = getNoSign(paramsa, false);
        return doCheck(noSignStr, rst.getSign(), pubKey);
    }

    /**
     * 对支付结果的签名进行校验
     * @param rst 支付结果
     * @param pubKey 公钥
     * @return 是否校验通过
     */
    public static boolean checkSign(ProductPayResultInfo rst, String pubKey) {

        if (rst == null || pubKey == null) {
            return false;
        }

        Map<String, Object> paramsa = new HashMap<String, Object>();

        // 必选参数
        paramsa.put("returnCode", rst.getReturnCode());
        paramsa.put("merchantId", rst.getMerchantId());
        paramsa.put("requestId", rst.getRequestId());
        paramsa.put("productNo", rst.getProductNo());
        paramsa.put("microsAmount", rst.getMicrosAmount());
        paramsa.put("currency", rst.getCurrency());
        paramsa.put("country", rst.getCountry());
        paramsa.put("time", rst.getTime());

        // 可选参数
        paramsa.put("orderID", rst.getOrderID());
        paramsa.put("errMsg", rst.getErrMsg());

        String noSignStr = getNoSign(paramsa, false);
        return doCheck(noSignStr, rst.getSign(), pubKey);
    }

    /**
     * 对查询订单结果签名进行校验
     * @param result 查询订单结果
     * @param pubKey 公钥
     * @return 是否校验通过
     */
    public static boolean checkSign(OrderResult result, String pubKey) {

        if (result == null || pubKey == null) {
            return false;
        }

        Map<String, Object> paramsa = new HashMap<String, Object>();
        //必选参数
        paramsa.put("returnCode", result.getReturnCode());
        paramsa.put("returnDesc", result.getReturnDesc());

        //可选参数
        paramsa.put("requestId", result.getRequestId());
        paramsa.put("orderID", result.getOrderID());
        paramsa.put("status", result.getOrderStatus());
        paramsa.put("orderTime", result.getOrderTime());
        paramsa.put("tradeTime", result.getTradeTime());

        String noSignStr = getNoSign(paramsa, false);
        return doCheck(noSignStr, result.getSign(), pubKey);
    }

    /**
     * 对查询非消耗商品结果的每一个订单签名进行校验
     * @param result 查询订单结果
     * @param pubKey 公钥
     * @return 是否校验通过
     */
    public static boolean checkSign(PurchaseInfoResult result, String pubKey) {

        if (result == null || pubKey == null) {
            return false;
        }

        StringBuilder sb = new StringBuilder();

        Map<String, Object> paramsa = new HashMap<String, Object>();
        paramsa.put("pageCount", result.getPageCount());
        paramsa.put("rtnCode", result.getRtnCode());
        sb.append(getNoSign(paramsa, false)).append('&');

        List<PurchaseInfo> purchaseInfos = result.getPurchaseInfoList();
        if (purchaseInfos != null) {
            for (PurchaseInfo info : purchaseInfos) {
                if (info != null) {
                    Map<String, Object> paramsaSub = new HashMap<String, Object>();
                    //必选参数
                    paramsaSub.put("requestId", info.getRequestId());
                    paramsaSub.put("merchantId", info.getMerchantId());
                    paramsaSub.put("appId", info.getAppId());
                    paramsaSub.put("productId", info.getProductId());
                    paramsaSub.put("tradeTime", info.getTradeTime());

                    sb.append(getNoSign(paramsaSub, false)).append('&');
                }
            }
        }

        if (sb.charAt(sb.length()-1) == '&') {
            sb.deleteCharAt(sb.length()-1);
        }

        return doCheck(sb.toString(), result.getSign(), pubKey);
    }

    /**
     * 根据参数map获取待签名字符串
     * @param params 待签名参数map
     * @param includeEmptyParam 是否包含值为空的参数：
     *                          与 HMS-SDK 支付能力交互的签名或验签，需要为false（不包含空参数）
     *                          由华为支付服务器回调给开发者的服务器的支付结果验签，需要为true（包含空参数）
     * @return 待签名字符串
     */
    private static String getNoSign(Map<String, Object> params, boolean includeEmptyParam) {
        //对参数按照key做升序排序，对map的所有value进行处理，转化成string类型
        //拼接成key=value&key=value&....格式的字符串
        StringBuilder content = new StringBuilder();

        // 按照key做排序
        List<String> keys = new ArrayList<String>(params.keySet());
        Collections.sort(keys);

        String value = null;
        Object object = null;
        boolean isFirstParm = true;
        for (int i = 0; i < keys.size(); i++) {
            String key = (String) keys.get(i);
            object = params.get(key);

            if (object == null) {
                value = "";
            }else if (object instanceof String) {
                value = (String) object;
            } else {
                value = String.valueOf(object);
            }

            if (includeEmptyParam || !TextUtils.isEmpty(value)) {
                content.append((isFirstParm ? "" : "&") + key + "=" + value);
                isFirstParm = false;
            } else {
                continue;
            }
        }

        //待签名的字符串
        return content.toString();
    }

    /**
     * 签名字符串（SHA256WithRSA）
     * @param content 待签名字符串
     * @param privateKey 私钥
     * @return 字符串的签名
     */
    public static String rsaSign(String content, String privateKey) {

        if (null == content || privateKey == null) {
            return null;
        }

        try {
            PKCS8EncodedKeySpec priPKCS8 = new PKCS8EncodedKeySpec(Base64.decode(privateKey, Base64.DEFAULT));
            KeyFactory keyf = KeyFactory.getInstance("RSA");
            PrivateKey priKey = keyf.generatePrivate(priPKCS8);
            java.security.Signature signature = java.security.Signature.getInstance(SIGN_ALGORITHMS);
            signature.initSign(priKey);
            signature.update(content.getBytes(CHARSET));
            byte[] signed = signature.sign();
            return Base64.encodeToString(signed, Base64.DEFAULT);
        } catch (Exception e) {
            //  这里是安全算法，为避免出现异常时泄露加密信息，这里不打印具体日志
            HMSAgentLog.e("rsaSign error");
        }

        return null;
    }

    /**
     * 校验签名信息
     * @param noSignStr 待校验未字符串
     * @param sign 签名字符串
     * @param publicKey 公钥
     * @return 是否校验通过
     */
    public static boolean doCheck(String noSignStr, String sign, String publicKey) {

        if (sign == null || noSignStr == null || publicKey == null) {
            return false;
        }

        try {
            KeyFactory keyFactory = KeyFactory.getInstance("RSA");
            byte[] encodedKey = Base64.decode(publicKey, Base64.DEFAULT);
            PublicKey pubKey = keyFactory.generatePublic(new X509EncodedKeySpec(encodedKey));

            java.security.Signature signature = java.security.Signature.getInstance(SIGN_ALGORITHMS);

            signature.initVerify(pubKey);
            signature.update(noSignStr.getBytes(CHARSET));

            return signature.verify(Base64.decode(sign, Base64.DEFAULT));
        } catch (Exception e) {
            //  这里是安全算法，为避免出现异常时泄露加密信息，这里不打印具体日志
            HMSAgentLog.e("doCheck error");
        }
        return false;
    }
}
