package com.huawei.android.hms.agent.pay;

import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackResultRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.pay.handler.GetProductDetailsHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.entity.pay.ProductDetailRequest;
import com.huawei.hms.support.api.pay.HuaweiPay;
import com.huawei.hms.support.api.pay.ProductDetailResult;

/**
 * 查询订单请求
 */
public class GetProductDetailsApi extends BaseApiAgent {

    /**
     * client 无效最大重试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 查询商品信息请求，请求体
     */
    private ProductDetailRequest productDetailReq;

    /**
     * 查询商品信息请求回调接口
     */
    private GetProductDetailsHandler handler;

    /**
     * 剩余重试次数
     */
    private int retryTimes = MAX_RETRY_TIMES;

    /**
     * Huawei Api Client 连接回调
     * @param rst 结果码
     * @param client HuaweiApiClient 实例
     */
    @Override
    public void onConnect(int rst, HuaweiApiClient client) {

        HMSAgentLog.d("onConnect:" + rst);

        if (client == null || !ApiClientMgr.INST.isConnect(client)) {
            HMSAgentLog.e("client not connted");
            onProductDetailResult(rst, null);
            return;
        }

        // 调用HMS-SDK getOrderDetail 接口
        PendingResult<ProductDetailResult> checkPayResult = HuaweiPay.HuaweiPayApi.getProductDetails(client, productDetailReq);
        checkPayResult.setResultCallback(new ResultCallback<ProductDetailResult>() {
            @Override
            public void onResult(ProductDetailResult result) {

                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onProductDetailResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onProductDetailResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
                    return;
                }

                int rstCode = status.getStatusCode();
                HMSAgentLog.d("status=" + status);
                // 需要重试的错误码，并且可以重试
                if ((rstCode == CommonCode.ErrorCode.SESSION_INVALID
                        || rstCode == CommonCode.ErrorCode.CLIENT_API_INVALID) && retryTimes > 0) {
                    retryTimes--;
                    connect();
                } else {
                    onProductDetailResult(rstCode, result);
                }
            }
        });
    }

    private void onProductDetailResult(int retCode, ProductDetailResult productDetailResult){
        HMSAgentLog.i("getOrderDetail:callback=" + StrUtils.objDesc(handler) +" retCode=" + retCode + "  productDetailResult=" + StrUtils.objDesc(productDetailResult));
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<ProductDetailResult>(handler, retCode, productDetailResult));
            handler = null;
        }

        productDetailReq = null;
        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 查询商品信息接口
     * @param request 查询商品信息请求体
     * @param handler 查询商品信息结果回调
     */
    public void getProductDetails(ProductDetailRequest request, GetProductDetailsHandler handler) {
        HMSAgentLog.i("getOrderDetail:request=" + StrUtils.objDesc(request) + "  handler=" + StrUtils.objDesc(handler));
        this.productDetailReq = request;
        this.handler = handler;
        this.retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
