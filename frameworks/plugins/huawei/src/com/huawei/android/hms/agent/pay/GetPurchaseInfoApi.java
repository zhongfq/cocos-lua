package com.huawei.android.hms.agent.pay;

import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackResultRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.pay.handler.GetPurchaseInfoHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.entity.pay.PurchaseInfoRequest;
import com.huawei.hms.support.api.pay.HuaweiPay;
import com.huawei.hms.support.api.pay.PurchaseInfoResult;

/**
 * 查询非消耗商品订单列表请求
 */
public class GetPurchaseInfoApi extends BaseApiAgent {

    /**
     * client 无效最大重试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 查询非消耗商品订单列表请求，请求体
     */
    private PurchaseInfoRequest purchaseInfoReq;

    /**
     * 查询请求回调接口
     */
    private GetPurchaseInfoHandler handler;

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
            onPurchaseInfoResult(rst, null);
            return;
        }

        // 调用HMS-SDK getOrderDetail 接口
        PendingResult<PurchaseInfoResult> purchaseInfoPenddingResult = HuaweiPay.HuaweiPayApi.getPurchaseInfo(client, purchaseInfoReq);
        purchaseInfoPenddingResult.setResultCallback(new ResultCallback<PurchaseInfoResult>() {
            @Override
            public void onResult(PurchaseInfoResult result) {

                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onPurchaseInfoResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onPurchaseInfoResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
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
                    onPurchaseInfoResult(rstCode, result);
                }
            }
        });
    }

    private void onPurchaseInfoResult(int retCode, PurchaseInfoResult purchaseInfoResult){
        HMSAgentLog.i("getPurchaseInfo:callback=" + StrUtils.objDesc(handler) +" retCode=" + retCode + "  checkPayResult=" + StrUtils.objDesc(purchaseInfoResult));
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<PurchaseInfoResult>(handler, retCode, purchaseInfoResult));
            handler = null;
        }

        purchaseInfoReq = null;
        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 查询非消耗商品订单列表接口
     * @param request 查询请求体
     * @param handler 查询结果回调
     */
    public void getPurchaseInfo(PurchaseInfoRequest request, GetPurchaseInfoHandler handler) {
        HMSAgentLog.i("getPurchaseInfo:request=" + StrUtils.objDesc(request) + "  handler=" + StrUtils.objDesc(handler));
        this.purchaseInfoReq = request;
        this.handler = handler;
        this.retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
