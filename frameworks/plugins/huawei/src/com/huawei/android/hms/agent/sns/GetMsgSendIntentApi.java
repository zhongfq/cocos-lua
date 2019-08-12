package com.huawei.android.hms.agent.sns;

import android.content.Intent;
import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackResultRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.sns.Handler.GetMsgSendIntentHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.entity.sns.SNSCode;
import com.huawei.hms.support.api.entity.sns.SnsMsg;
import com.huawei.hms.support.api.sns.HuaweiSns;
import com.huawei.hms.support.api.sns.IntentResult;

/**
 * 社交发送消息请求
 */
public class GetMsgSendIntentApi extends BaseApiAgent {

    /**
     * client 无效最大尝试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    private SnsMsg msg;
    private boolean needResult;
    private GetMsgSendIntentHandler handler;

    /**
     * 当前剩余重试次数
     */
    private int retryTimes = MAX_RETRY_TIMES;

    /**
     * HuaweiApiClient 连接结果回调
     *
     * @param rst    结果码
     * @param client HuaweiApiClient 实例
     */
    @Override
    public void onConnect(int rst, HuaweiApiClient client) {
        if (client == null || !ApiClientMgr.INST.isConnect(client)) {
            HMSAgentLog.e("client not connted");
            onSnsGetMsgIntentResult(rst, null);
            return;
        }

        PendingResult<IntentResult> sendMsgResult = HuaweiSns.HuaweiSnsApi.getMsgSendIntent(client, msg, needResult);
        sendMsgResult.setResultCallback(new ResultCallback<IntentResult>() {
            @Override
            public void onResult(IntentResult result) {
                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onSnsGetMsgIntentResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onSnsGetMsgIntentResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
                    return;
                }

                int rstCode = status.getStatusCode();
                HMSAgentLog.d("status=" + status);
                // 需要重试的错误码，并且可以重试
                if ((rstCode == CommonCode.ErrorCode.SESSION_INVALID
                        || rstCode == CommonCode.ErrorCode.CLIENT_API_INVALID) && retryTimes > 0) {
                    retryTimes--;
                    connect();
                } else if (rstCode == SNSCode.OK) {
                    //回调GetMsgIntent结果
                    Intent nxtIntent = result.getIntent();
                    if (nxtIntent == null) {
                        HMSAgentLog.e("nxtIntent is null");
                        onSnsGetMsgIntentResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                        return;
                    } else {
                        onSnsGetMsgIntentResult(rstCode, nxtIntent);
                        return;
                    }

                }else {
                    onSnsGetMsgIntentResult(rstCode, null);
                }
            }
        });
    }

    void onSnsGetMsgIntentResult(int rstCode, Intent intent) {
        HMSAgentLog.i("getMsgSendIntent:callback=" + StrUtils.objDesc(handler) +" retCode=" + rstCode);
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<Intent>(handler, rstCode, intent));
            handler = null;
        }
        msg = null;
        needResult = false;
        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 获取发送社交消息的intent
     * @param msg 要发送的消息体
     * @param needResult 在社交界面发送完图文消息是否自动跳转回调用者应用界面
     *       True：发完消息自动跳转回调用者界面
     *       False：发完消息停留在社交界面
     * @param handler 结果回调
     */
    public void getMsgSendIntent(SnsMsg msg, boolean needResult, GetMsgSendIntentHandler handler){
        HMSAgentLog.i("getMsgSendIntent:msg=" + StrUtils.objDesc(msg) + "  needResult=" + needResult + "  handler=" + StrUtils.objDesc(handler));
        this.msg = msg;
        this.needResult = needResult;
        this.handler = handler;
        retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
