package com.huawei.android.hms.agent.pay;

import android.app.Activity;
import android.content.Intent;
import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ActivityMgr;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseAgentActivity;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackResultRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.common.UIUtils;
import com.huawei.android.hms.agent.pay.handler.PayHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.entity.pay.PayReq;
import com.huawei.hms.support.api.entity.pay.PayStatusCodes;
import com.huawei.hms.support.api.pay.HuaweiPay;
import com.huawei.hms.support.api.pay.PayResult;
import com.huawei.hms.support.api.pay.PayResultInfo;

/**
 * 支付请求
 */
public final class PayApi extends BaseApiAgent {

    /**
     * 单实例
     */
    public static final PayApi INST = new PayApi();

    /**
     * client 无效最大尝试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 请求体
     */
    private PayReq payReq;

    /**
     * 支付结果回调
     */
    private PayHandler handler;

    /**
     * 当前剩余重试次数
     */
    private int retryTimes = MAX_RETRY_TIMES;

    /**
     * 待处理的支付
     */
    private Status statusForPay;

    /**
     * 私有构造方法
     */
    private PayApi(){}

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
            onPayEnd(rst, null);
            return;
        }

        // 调用HMS-SDK pay 接口
        PendingResult<PayResult> payResult = HuaweiPay.HuaweiPayApi.pay(client, payReq);
        payResult.setResultCallback(new ResultCallback<PayResult>() {
            @Override
            public void onResult(PayResult result) {

                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onPayEnd(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onPayEnd(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
                    return;
                }

                int rstCode = status.getStatusCode();
                HMSAgentLog.d("status=" + status);
                // 需要重试的错误码，并且可以重试
                if ((rstCode == CommonCode.ErrorCode.SESSION_INVALID
                        || rstCode == CommonCode.ErrorCode.CLIENT_API_INVALID) && retryTimes > 0) {
                    retryTimes--;
                    connect();
                } else if (rstCode == PayStatusCodes.PAY_STATE_SUCCESS) {

                    Activity curActivity = ActivityMgr.INST.getLastActivity();
                    if (curActivity == null) {
                        HMSAgentLog.e("activity is null");
                        onPayEnd(HMSAgent.AgentResultCode.NO_ACTIVITY_FOR_USE, null);
                        return;
                    }

                    if (statusForPay != null) {
                        HMSAgentLog.e("has already a pay to dispose");
                        onPayEnd(HMSAgent.AgentResultCode.REQUEST_REPEATED, null);
                        return;
                    }

                    //启动支付流程
                    try {
                        statusForPay = status;
                        Intent intent = new Intent(curActivity, HMSPayAgentActivity.class);
                        intent.putExtra(BaseAgentActivity.EXTRA_IS_FULLSCREEN, UIUtils.isActivityFullscreen(curActivity));
                        curActivity.startActivity(intent);
                    } catch (Exception e) {
                        HMSAgentLog.e("start HMSPayAgentActivity error:" + e.getMessage());
                        onPayEnd(HMSAgent.AgentResultCode.START_ACTIVITY_ERROR, null);
                    }
                }else {
                    onPayEnd(rstCode, null);
                }
            }
        });
    }

    /**
     * 获取待处理的支付，供 HMSPayAgentActivity 调用
     * @return 待处理的支付
     */
    Status getWaitPayStatus(){
        HMSAgentLog.d("getWaitPayStatus=" + StrUtils.objDesc(statusForPay));
        return statusForPay;
    }

    /**
     * 支付结果方法
     * @param rstCode 支付结果码
     * @param payInfo 支付结果信息
     */
    void onPayEnd(int rstCode, PayResultInfo payInfo) {
        HMSAgentLog.i("pay:callback=" + StrUtils.objDesc(handler) +" retCode=" + rstCode + "  payInfo=" + StrUtils.objDesc(payInfo));
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<PayResultInfo>(handler, rstCode, payInfo));
            handler = null;
        }
        statusForPay = null;
        payReq = null;
        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 支付接口
     * @param requ 支付请求类
     * @param handler 支付结果回调
     */
    public void pay(PayReq requ, final PayHandler handler) {
        HMSAgentLog.i("pay:requ=" + StrUtils.objDesc(requ) + "  handler=" + StrUtils.objDesc(handler));

        if (payReq != null) {
            HMSAgentLog.e("pay:has already a pay to dispose");
            if (handler != null) {
                new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<PayResultInfo>(handler, HMSAgent.AgentResultCode.REQUEST_REPEATED, null));
            }
            return;
        }

        this.payReq = requ;
        this.handler = handler;
        retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
