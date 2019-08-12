package com.huawei.android.hms.agent.game;

import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.game.GameInfo;
import com.huawei.hms.support.api.game.HuaweiGame;

/**
 * 上传设备信息
 */
public class UpdateGameInfoApi {

    /**
     * 对外接口上传设备信息
     * @param gameInfo 设备信息
     */
    public long updateGameInfo(GameInfo gameInfo){
        HMSAgentLog.i("updateGameInfo:gameInfo=" + StrUtils.objDesc(gameInfo));

        HuaweiApiClient client = ApiClientMgr.INST.getApiClient();
        if (client == null || !ApiClientMgr.INST.isConnect(client)) {
            HMSAgentLog.e("client not connted");
            return CommonCode.ErrorCode.CLIENT_API_INVALID;
        }

        return HuaweiGame.HuaweiGameApi.updateGameInfo(client, gameInfo);
    }
}
