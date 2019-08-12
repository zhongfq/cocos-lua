package com.huawei.android.hms.agent.game.handler;

/**
 * 游戏登录结果验签结果回调
 */
public interface ICheckLoginSignHandler {
    /**
     * 游戏登录结果验签结果回调
     * @param code 结果码，字符串类型，可能为null
     * @param resultDesc 结果描述
     * @param isCheckSuccess 是否验签成功
     */
    void onCheckResult(String code, String resultDesc, boolean isCheckSuccess);
}
