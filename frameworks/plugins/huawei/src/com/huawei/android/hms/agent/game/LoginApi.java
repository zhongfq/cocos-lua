package com.huawei.android.hms.agent.game;

import android.app.Activity;
import android.os.Handler;
import android.os.Looper;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.ActivityMgr;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.BaseApiAgent;
import com.huawei.android.hms.agent.common.CallbackResultRunnable;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.android.hms.agent.game.handler.LoginHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.entity.game.GameUserData;
import com.huawei.hms.support.api.game.GameLoginHandler;
import com.huawei.hms.support.api.game.GameLoginResult;
import com.huawei.hms.support.api.game.HuaweiGame;


/**
 * 游戏登录请求类
 */
public class LoginApi extends BaseApiAgent {

    /**
     * client 无效时，最大重试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 登录请求回调
     */
    private LoginHandler handler;

    /**
     * 登录类型，0表示如果玩家未登录华为帐号或鉴权失败，SDK不会主动拉起帐号登录页面，适用于单机游戏的登录场景；</br>
     *           1表示如果玩家未登录华为帐号或鉴权失败，SDK会主动拉起帐号登录页面，适用于网游的登录场景和单机游戏支付前强制登录。</br>
     */
    private int forceLogin;

    /**
     * session 失效时重试次数
     */
    private int retryTimes = MAX_RETRY_TIMES;

    /**
     * HuaweiApiClient 连接结果回调
     * @param rst 结果码
     * @param client HuaweiApiClient 实例
     */
    @Override
    public void onConnect(int rst, HuaweiApiClient client) {

        HMSAgentLog.d("onConnect:" + rst);

        if (client == null || !ApiClientMgr.INST.isConnect(client)) {
            HMSAgentLog.e("client not connted");
            onLoginResult(rst, null);
            return;
        }

        Activity curActivity = ActivityMgr.INST.getLastActivity();
        if (curActivity == null) {
            HMSAgentLog.e("activity is null");
            onLoginResult(HMSAgent.AgentResultCode.NO_ACTIVITY_FOR_USE, null);
            return;
        }

        /**
         * 调用login接口，传入成功回调。 此回调仅在成功时回调。
         */
        HMSAgentLog.d("begin login by HMS-SDK");
        PendingResult<GameLoginResult> loginPending = HuaweiGame.HuaweiGameApi.login(client, curActivity, forceLogin, new GameLoginHandler(){

            @Override
            public void onResult(int retCode, GameUserData userData) {
                HMSAgentLog.d("onResult:retCode=" + retCode + "  userData=" + StrUtils.objDesc(userData));
                onLoginResult(retCode, userData);
            }

            @Override
            public void onChange() {
                HMSAgentLog.d("onChange");

                new Handler(Looper.getMainLooper()).post(new Runnable() {
                    @Override
                    public void run() {
                        if (handler != null) {
                            handler.onChange();
                        }
                    }
                });
            }
        });

        loginPending.setResultCallback(new ResultCallback<GameLoginResult>() {
            @Override
            public void onResult(GameLoginResult result) {

                if (result == null) {
                    HMSAgentLog.e("result is null");
                    onLoginResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                    return;
                }

                Status status = result.getStatus();
                if (status == null) {
                    HMSAgentLog.e("status is null");
                    onLoginResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
                    return;
                }

                int rstCode = status.getStatusCode();
                HMSAgentLog.d("status=" + status);

                if (!result.getStatus().isSuccess()) {
                    // 需要重试的错误码，并且可以重试
                    if ((rstCode == CommonCode.ErrorCode.SESSION_INVALID
                            || rstCode == CommonCode.ErrorCode.CLIENT_API_INVALID) && retryTimes > 0) {
                        retryTimes--;
                        connect();
                    } else {
                        onLoginResult(rstCode, null);
                    }
                } else {
                    // 经确认，成功的情况下会走上面handler里面的2个回调,
                    // 这边不需要任何处理
                }
            }
        });
    }

    private void onLoginResult(int retCode,GameUserData userData) {
        HMSAgentLog.i("login:callback=" + StrUtils.objDesc(handler) +" retCode=" + retCode + "   userData=" + StrUtils.objDesc(userData));
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<GameUserData>(handler, retCode, userData));
        }

        this.retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 游戏登录接口
     * @param handler 游戏登录结果回调
     * @param forceLogin 登录类型：
     *                     0表示如果玩家未登录华为帐号或鉴权失败，SDK不会主动拉起帐号登录页面，适用于单机游戏的登录场景；</br>
     *                     1表示如果玩家未登录华为帐号或鉴权失败，SDK会主动拉起帐号登录页面，适用于网游的登录场景和单机游戏支付前强制登录。</br>
     */
    public void login(final LoginHandler handler, int forceLogin) {
        HMSAgentLog.i("login:handler=" + StrUtils.objDesc(handler) + "  forceLogin=" + forceLogin);
        this.handler = handler;
        this.forceLogin = forceLogin;
        this.retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}