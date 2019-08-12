package com.huawei.android.hms.agent.game;

import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackCodeRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.game.handler.RegisterHardwareCapabilityHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.game.HardwareCapabilityResult;
import com.huawei.hms.support.api.game.HuaweiGame;

/**
 * 注册硬件信息类
 */
public class RegisterHardwareCapabilityApi extends BaseApiAgent {

    /**
     * client 无效时，最大重试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 注册硬件能力结果回调
     */
    private RegisterHardwareCapabilityHandler handler;

    /**
     * 重试次数
     */
    private int retryTimes = MAX_RETRY_TIMES;

    @Override
    public void onConnect(int rst, HuaweiApiClient client) {

        HMSAgentLog.d("onConnect:" + rst);
        if (client == null || !ApiClientMgr.INST.isConnect(client)) {
            HMSAgentLog.e("client not connted");
            onRegisterHardwareCapabilityResult(rst);
            return;
        }

        PendingResult<HardwareCapabilityResult> pendingRst = HuaweiGame.HuaweiGameApi.registerHardwareCapability(client);
        pendingRst.setResultCallback(new ResultCallback<HardwareCapabilityResult>() {
            @Override
            public void onResult(HardwareCapabilityResult result) {

                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onRegisterHardwareCapabilityResult(HMSAgent.AgentResultCode.RESULT_IS_NULL);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onRegisterHardwareCapabilityResult(HMSAgent.AgentResultCode.STATUS_IS_NULL);
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
                    onRegisterHardwareCapabilityResult(rstCode);
                }
            }
        });
    }

    private void onRegisterHardwareCapabilityResult(int resultCode) {
        HMSAgentLog.i("registerHardwareCapability:callback=" + StrUtils.objDesc(handler) +" retCode=" + resultCode);
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackCodeRunnable(handler, resultCode));
            handler = null;
        }

        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 注册硬件信息
     * @param handler 结果回调
     */
    public void registerHardwareCapability(final RegisterHardwareCapabilityHandler handler){
        HMSAgentLog.i("registerHardwareCapability: handler=" + StrUtils.objDesc(handler));
        this.handler = handler;
        this.retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
