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
import com.huawei.android.hms.agent.sns.Handler.GetUiIntentHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.entity.sns.SNSCode;
import com.huawei.hms.support.api.sns.HuaweiSns;
import com.huawei.hms.support.api.sns.IntentResult;

/**
 * 社交拉起界面请求
 */
public class GetUiIntentApi extends BaseApiAgent {

    /**
     * client 无效最大尝试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    private int type;
    private long param;
    private GetUiIntentHandler handler;

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
            onSnsGetUiIntentResult(rst, null);
            return;
        }

        PendingResult<IntentResult> snsStartResult = HuaweiSns.HuaweiSnsApi.getUiIntent(client, type, param);
        snsStartResult.setResultCallback(new ResultCallback<IntentResult>() {
            @Override
            public void onResult(IntentResult result) {
                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onSnsGetUiIntentResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onSnsGetUiIntentResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
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
                    //回调GetUiIntent结果
                    Intent nxtIntent = result.getIntent();
                    if (nxtIntent == null) {
                        HMSAgentLog.e("nxtIntent is null");
                        onSnsGetUiIntentResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                        return;
                    } else {
                        onSnsGetUiIntentResult(rstCode, nxtIntent);
                        return;
                    }

                }else {
                    onSnsGetUiIntentResult(rstCode, null);
                }
            }
        });
    }

    void onSnsGetUiIntentResult(int rstCode, Intent intent) {
        HMSAgentLog.i("getUiIntent:callback=" + StrUtils.objDesc(handler) +" retCode=" + rstCode);
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<Intent>(handler, rstCode, intent));
            handler = null;
        }
        param = 0;
        type = 0;
        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 获取拉起社交界面的intent
     * @param type 指定打开哪个界面，取值参考{@link com.huawei.hms.support.api.entity.sns.Constants.UiIntentType}
     * @param param 附加的参数 <br>
     *            当{@code type}为 {@link com.huawei.hms.support.api.entity.sns.Constants.UiIntentType#UI_MSG},
     *            {@link com.huawei.hms.support.api.entity.sns.Constants.UiIntentType#UI_FRIEND},
     *            {@link com.huawei.hms.support.api.entity.sns.Constants.UiIntentType#UI_FAMILY_GROUP},
     *            {@link com.huawei.hms.support.api.entity.sns.Constants.UiIntentType#UI_COMMON_GROUP} 时忽略，可以传入任意值； <br>
     *            当{@code type}为
     *            {@link com.huawei.hms.support.api.entity.sns.Constants.UiIntentType#UI_FAMILY_GROUP_DETAIL},
     *            {@link com.huawei.hms.support.api.entity.sns.Constants.UiIntentType#UI_COMMON_GROUP_DETAIL},
     *            {@link com.huawei.hms.support.api.entity.sns.Constants.UiIntentType#UI_CHAT_GROUP} 时，需要传入群组的华为帐号ID； <br>
     *            当{@code type}为 {@link com.huawei.hms.support.api.entity.sns.Constants.UiIntentType#UI_USER_DETAIL},
     *            {@link com.huawei.hms.support.api.entity.sns.Constants.UiIntentType#UI_CHAT_FRIEND},
     *            {@link com.huawei.hms.support.api.entity.sns.Constants.UiIntentType#UI_CHAT_ASSIST} 时，需要传入用户的华为帐号ID。
     * @param handler 结果回调
     */
    public void getUiIntent(int type, long param, GetUiIntentHandler handler){
        HMSAgentLog.i("getUiIntent:type=" + type + "  param=" + param + "  handler=" + StrUtils.objDesc(handler));
        this.type = type;
        this.param = param;
        this.handler = handler;
        retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
