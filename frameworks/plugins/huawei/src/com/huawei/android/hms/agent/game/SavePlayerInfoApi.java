package com.huawei.android.hms.agent.game;

import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackCodeRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.game.handler.SaveInfoHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.entity.game.GamePlayerInfo;
import com.huawei.hms.support.api.game.HuaweiGame;
import com.huawei.hms.support.api.game.SavePlayerInfoResult;

/**
 * 保存玩家信息类
 */
public class SavePlayerInfoApi extends BaseApiAgent {

    /**
     * client 无效时，最大重试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 要保存的玩家信息
     */
    private GamePlayerInfo playerInfo;

    /**
     * 保存玩家信息结果回调
     */
    private SaveInfoHandler handler;

    /**
     * 重试次数
     */
    private int retryTimes = MAX_RETRY_TIMES;

    @Override
    public void onConnect(int rst, HuaweiApiClient client) {

        HMSAgentLog.d("onConnect:" + rst);
        if (client == null || !ApiClientMgr.INST.isConnect(client)) {
            HMSAgentLog.e("client not connted");
            onSavePlayInfoResult(rst);
            return;
        }

        PendingResult<SavePlayerInfoResult> pendingRst = HuaweiGame.HuaweiGameApi.savePlayerInfo(client, playerInfo);
        pendingRst.setResultCallback(new ResultCallback<SavePlayerInfoResult>() {
            @Override
            public void onResult(SavePlayerInfoResult result) {

                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onSavePlayInfoResult(HMSAgent.AgentResultCode.RESULT_IS_NULL);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onSavePlayInfoResult(HMSAgent.AgentResultCode.STATUS_IS_NULL);
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
                    onSavePlayInfoResult(rstCode);
                }
            }
        });
    }

    private void onSavePlayInfoResult(int resultCode) {
        HMSAgentLog.i("savePlayerInfo:callback=" + StrUtils.objDesc(handler) +" retCode=" + resultCode);
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackCodeRunnable(handler, resultCode));
            handler = null;
        }

        playerInfo = null;
        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 对外接口保存玩家信息
     * @param playerInfo 玩家信息
     * @param handler 结果回调
     */
    public void savePlayerInfo(GamePlayerInfo playerInfo, final SaveInfoHandler handler){
        HMSAgentLog.i("savePlayerInfo:playerInfo=" + StrUtils.objDesc(playerInfo) + "   handler=" + StrUtils.objDesc(handler));
        this.playerInfo = playerInfo;
        this.handler = handler;
        this.retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
