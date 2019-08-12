package com.huawei.android.hms.agent.pay;

import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackResultRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.pay.handler.GetOrderHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.entity.pay.OrderRequest;
import com.huawei.hms.support.api.pay.HuaweiPay;
import com.huawei.hms.support.api.pay.OrderResult;

/**
 * 查询订单请求
 */
public class GetPayOrderApi extends BaseApiAgent {

    /**
     * client 无效最大重试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 查询订单请求，请求体
     */
    private OrderRequest checkPayReq;

    /**
     * 查询订单请求回调接口
     */
    private GetOrderHandler handler;

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
            onCheckOrderResult(rst, null);
            return;
        }

        // 调用HMS-SDK getOrderDetail 接口
        PendingResult<OrderResult> checkPayResult = HuaweiPay.HuaweiPayApi.getOrderDetail(client, checkPayReq);
        checkPayResult.setResultCallback(new ResultCallback<OrderResult>() {
            @Override
            public void onResult(OrderResult result) {

                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onCheckOrderResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onCheckOrderResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
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
                    onCheckOrderResult(rstCode, result);
                }
            }
        });
    }

    private void onCheckOrderResult(int retCode, OrderResult checkPayResult){
        HMSAgentLog.i("getOrderDetail:callback=" + StrUtils.objDesc(handler) +" retCode=" + retCode + "  checkPayResult=" + StrUtils.objDesc(checkPayResult));
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<OrderResult>(handler, retCode, checkPayResult));
            handler = null;
        }

        checkPayReq = null;
        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 查询订单接口
     * @param request 查询订单请求体
     * @param handler 查询订单结果回调
     */
    public void getOrderDetail(OrderRequest request, GetOrderHandler handler) {
        HMSAgentLog.i("getOrderDetail:request=" + StrUtils.objDesc(request) + "  handler=" + StrUtils.objDesc(handler));
        this.checkPayReq = request;
        this.handler = handler;
        this.retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
