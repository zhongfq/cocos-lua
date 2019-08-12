package com.huawei.android.hms.agent.game;

import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackResultRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.game.handler.GetTemperatureHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.game.HuaweiGame;
import com.huawei.hms.support.api.game.TemperatureResult;

/**
 * 获取温度信息类
 */
public class GetTemperatureApi extends BaseApiAgent {

    /**
     * client 无效时，最大重试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 获取温度结果回调
     */
    private GetTemperatureHandler handler;

    /**
     * 重试次数
     */
    private int retryTimes = MAX_RETRY_TIMES;

    @Override
    public void onConnect(int rst, HuaweiApiClient client) {

        HMSAgentLog.d("onConnect:" + rst);
        if (client == null || !ApiClientMgr.INST.isConnect(client)) {
            HMSAgentLog.e("client not connted");
            onGetTemperatureResult(rst, null);
            return;
        }

        PendingResult<TemperatureResult> pendingRst = HuaweiGame.HuaweiGameApi.getTemperature(client);
        pendingRst.setResultCallback(new ResultCallback<TemperatureResult>() {
            @Override
            public void onResult(TemperatureResult result) {

                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onGetTemperatureResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onGetTemperatureResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
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
                    onGetTemperatureResult(rstCode, result);
                }
            }
        });
    }

    private void onGetTemperatureResult(int resultCode, TemperatureResult result) {
        HMSAgentLog.i("getTemperature:callback=" + StrUtils.objDesc(handler) +" retCode=" + resultCode + "  temperatureResult=" + StrUtils.objDesc(result));
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<TemperatureResult>(handler, resultCode, result));
            handler = null;
        }

        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 获取温度
     * @param handler 结果回调
     */
    public void getTemperature(final GetTemperatureHandler handler){
        HMSAgentLog.i("getTemperature: handler=" + StrUtils.objDesc(handler));
        this.handler = handler;
        this.retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
