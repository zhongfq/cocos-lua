package com.huawei.android.hms.agent.game.handler;

import com.huawei.android.hms.agent.common.handler.ICallbackResult;
import com.huawei.hms.support.api.entity.game.GameUserData;

/**
 * 游戏登录结果回调接口
 */
public interface LoginHandler extends ICallbackResult<GameUserData> {

    /**
     * 登录帐号发生变化时回调
     */
    void onChange();
}
