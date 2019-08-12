package com.huawei.android.hms.agent.game;

import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackResultRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.game.handler.GetCertificationIntentHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.game.CertificateIntentResult;
import com.huawei.hms.support.api.game.HuaweiGame;

/**
 * 获取玩家实名认证Intent api
 */
public class GetCertificationIntentApi extends BaseApiAgent {

    /**
     * client 无效时，最大重试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 获取实名intent 结果回调
     */
    private GetCertificationIntentHandler handler;

    /**
     * 重试次数
     */
    private int retryTimes = MAX_RETRY_TIMES;

    @Override
    public void onConnect(int rst, HuaweiApiClient client) {

        HMSAgentLog.d("onConnect:" + rst);
        if (client == null || !ApiClientMgr.INST.isConnect(client)) {
            HMSAgentLog.e("client not connted");
            onGetCertificationIntentResult(rst, null);
            return;
        }

        PendingResult<CertificateIntentResult> pendingRst = HuaweiGame.HuaweiGameApi.getPlayerCertificationIntent(client);
        pendingRst.setResultCallback(new ResultCallback<CertificateIntentResult>() {
            @Override
            public void onResult(CertificateIntentResult result) {

                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onGetCertificationIntentResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onGetCertificationIntentResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
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
                    onGetCertificationIntentResult(rstCode, result);
                }
            }
        });
    }

    private void onGetCertificationIntentResult(int resultCode, CertificateIntentResult result) {
        HMSAgentLog.i("getCertificationIntentResult:callback=" + StrUtils.objDesc(handler) +" retCode=" + resultCode + " getCertificationIntentResult=" + StrUtils.objDesc(result));
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<CertificateIntentResult>(handler, resultCode, result));
            handler = null;
        }

        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 获取实名认证intent
     * @param handler 结果回调
     */
    public void getCertificationIntent(final GetCertificationIntentHandler handler){
        HMSAgentLog.i("getCertificationIntent: handler=" + StrUtils.objDesc(handler));
        this.handler = handler;
        this.retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
