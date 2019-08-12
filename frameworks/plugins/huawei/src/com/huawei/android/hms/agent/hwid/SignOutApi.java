package com.huawei.android.hms.agent.hwid;

import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackResultRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.hwid.handler.SignOutHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.hwid.HuaweiId;
import com.huawei.hms.support.api.hwid.SignOutResult;

/**
 * 帐号登录请求
 */
public class SignOutApi extends BaseApiAgent {

    /**
     * client 无效最大尝试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 登出结果回调
     */
    private SignOutHandler handler;

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
            onSignOutResult(rst, null);
            return;
        }

        PendingResult<SignOutResult> signOutResult = HuaweiId.HuaweiIdApi.signOut(client);
        signOutResult.setResultCallback(new ResultCallback<SignOutResult>() {
            @Override
            public void onResult(SignOutResult result) {
                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onSignOutResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onSignOutResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
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
                    onSignOutResult(rstCode, result);
                }
            }
        });
    }

    /**
     * 回调登出结果
     * @param rstCode 结果码
     * @param result 登出结果
     */
    void onSignOutResult(int rstCode, SignOutResult result) {
        HMSAgentLog.i("signOut:callback=" + StrUtils.objDesc(handler) +" retCode=" + rstCode);
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<SignOutResult>(handler, rstCode, result));
            handler = null;
        }
        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 帐号登出请求
     */
    public void signOut(SignOutHandler handler){
        HMSAgentLog.i("signOut:handler=" + StrUtils.objDesc(handler));
        this.handler = handler;
        retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
