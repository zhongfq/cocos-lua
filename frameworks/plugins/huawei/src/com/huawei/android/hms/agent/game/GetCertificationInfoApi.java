package com.huawei.android.hms.agent.game;

import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackResultRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.game.handler.GetCertificationInfoHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.game.HuaweiGame;
import com.huawei.hms.support.api.game.PlayerCertificationInfo;

/**
 * 获取玩家实名认证信息
 */
public class GetCertificationInfoApi extends BaseApiAgent {

    /**
     * client 无效时，最大重试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 获取实名信息结果回调
     */
    private GetCertificationInfoHandler handler;

    /**
     * 重试次数
     */
    private int retryTimes = MAX_RETRY_TIMES;

    @Override
    public void onConnect(int rst, HuaweiApiClient client) {

        HMSAgentLog.d("onConnect:" + rst);
        if (client == null || !ApiClientMgr.INST.isConnect(client)) {
            HMSAgentLog.e("client not connted");
            onGetCertificationInfoResult(rst, null);
            return;
        }

        PendingResult<PlayerCertificationInfo> pendingRst = HuaweiGame.HuaweiGameApi.getPlayerCertificationInfo(client);
        pendingRst.setResultCallback(new ResultCallback<PlayerCertificationInfo>() {
            @Override
            public void onResult(PlayerCertificationInfo result) {

                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onGetCertificationInfoResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onGetCertificationInfoResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
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
                    onGetCertificationInfoResult(rstCode, result);
                }
            }
        });
    }

    private void onGetCertificationInfoResult(int resultCode, PlayerCertificationInfo result) {
        HMSAgentLog.i("getCertificationInfoResult:callback=" + StrUtils.objDesc(handler) +" retCode=" + resultCode + " getCertificationInfoResult=" + StrUtils.objDesc(result));
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<PlayerCertificationInfo>(handler, resultCode, result));
            handler = null;
        }

        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 获取实名认证信息
     * @param handler 结果回调
     */
    public void getCertificationInfo(final GetCertificationInfoHandler handler){
        HMSAgentLog.i("getCertificationInfo: handler=" + StrUtils.objDesc(handler));
        this.handler = handler;
        this.retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
