package com.huawei.android.hms.agent.hwid;

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
import com.huawei.android.hms.agent.hwid.handler.SignInHandler;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.core.CommonCode;
import com.huawei.hms.support.api.hwid.HuaweiId;
import com.huawei.hms.support.api.hwid.SignInHuaweiId;
import com.huawei.hms.support.api.hwid.SignInResult;

/**
 * 帐号登录请求
 */
public final class CheckSignInApi extends BaseApiAgent {

    /**
     * client 无效最大尝试次数
     */
    private static final int MAX_RETRY_TIMES = 1;

    /**
     * 登录结果回调
     */
    private SignInHandler handler;

    /**
     * 当前剩余重试次数
     */
    private int retryTimes = MAX_RETRY_TIMES;

    /**
     * 私有构造方法
     */
    public CheckSignInApi(){}

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
            onCheckSignInResult(rst, null);
            return;
        }

        Activity curActivity = ActivityMgr.INST.getLastActivity();
        if (curActivity == null) {
            HMSAgentLog.e("activity is null");
            onCheckSignInResult(HMSAgent.AgentResultCode.NO_ACTIVITY_FOR_USE, null);
            return;
        }
		
        PendingResult<SignInResult> checkSignInResult = HuaweiId.HuaweiIdApi.signIn(curActivity, client);
        checkSignInResult.setResultCallback(new ResultCallback<SignInResult>() {
            @Override
            public void onResult(SignInResult result) {
                disposeCheckSignInResult(result);
            }
        });
    }

    /**
     * 处理signInResult回调
     * @param result 回调的signInResult实例
     */
    private void disposeCheckSignInResult(SignInResult result) {
        if (result == null) {
            HMSAgentLog.e("result is null");
            onCheckSignInResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
            return;
        }

        Status status = result.getStatus();
        if (status == null) {
            HMSAgentLog.e("status is null");
            onCheckSignInResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
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
            if(result.isSuccess()){
                //可以获取帐号的 openid，昵称，头像 at信息
                SignInHuaweiId account = result.getSignInHuaweiId();
                onCheckSignInResult(rstCode, account);
            } else {
                onCheckSignInResult(rstCode, null);
            }
        }
    }

    /**
     * 回调登录结果
     * @param rstCode 结果码
     * @param result 登录结果
     */
    private void onCheckSignInResult(int rstCode, SignInHuaweiId result) {
        HMSAgentLog.i("checkSignIn:callback=" + StrUtils.objDesc(handler) +" retCode=" + rstCode);
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<SignInHuaweiId>(handler, rstCode, result));
            handler = null;
        }
        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 帐号登录请求,非强制登录
     * @param handler 登录结果回调
     */
    public void checkSignIn(final SignInHandler handler){
        HMSAgentLog.i("checkSignIn:handler=" + StrUtils.objDesc(handler));

        if (this.handler != null) {
            HMSAgentLog.e("has already a signIn to dispose");
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<SignInHuaweiId>(handler, HMSAgent.AgentResultCode.REQUEST_REPEATED, null));
            return;
        }

        this.handler = handler;
        retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
