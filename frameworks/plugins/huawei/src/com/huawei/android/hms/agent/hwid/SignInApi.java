package com.huawei.android.hms.agent.hwid;

import android.app.Activity;
import android.content.Intent;
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
import com.huawei.hms.support.api.hwid.HuaweiIdStatusCodes;
import com.huawei.hms.support.api.hwid.SignInHuaweiId;
import com.huawei.hms.support.api.hwid.SignInResult;

/**
 * 帐号登录请求
 */
public final class SignInApi extends BaseApiAgent {

    public static final SignInApi INST = new SignInApi();

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
     * 待处理的signInResult
     */
    private SignInResult signInResultForDispose;

    /**
     * 私有构造方法
     */
    private SignInApi(){}

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
            onSignInResult(rst, null);
            return;
        }

        Activity curActivity = ActivityMgr.INST.getLastActivity();
        if (curActivity == null) {
            HMSAgentLog.e("activity is null");
            onSignInResult(HMSAgent.AgentResultCode.NO_ACTIVITY_FOR_USE, null);
            return;
        }
		
        PendingResult<SignInResult> signInResult = HuaweiId.HuaweiIdApi.signIn(curActivity, client);
        signInResult.setResultCallback(new ResultCallback<SignInResult>() {
            @Override
            public void onResult(SignInResult result) {
                disposeSignInResult(result);
            }
        });
    }

    /**
     * 处理signInResult回调
     * @param result 回调的signInResult实例
     */
    private void disposeSignInResult(SignInResult result) {
        if (result == null) {
            HMSAgentLog.e("result is null");
            onSignInResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
            return;
        }

        Status status = result.getStatus();
        if (status == null) {
            HMSAgentLog.e("status is null");
            onSignInResult(HMSAgent.AgentResultCode.STATUS_IS_NULL, null);
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
            disposeObtainedResult(result, rstCode);
        }
    }

    /**
     * 处理回调的result
     * @param result 回调的result
     * @param rstCode 业务结果码
     */
    private void disposeObtainedResult(SignInResult result, int rstCode) {
        if(result.isSuccess()){
            //可以获取帐号的 openid，昵称，头像 at信息
            SignInHuaweiId account = result.getSignInHuaweiId();
            onSignInResult(rstCode, account);
        } else {
            if(rstCode == HuaweiIdStatusCodes.SIGN_IN_UNLOGIN
                    || rstCode == HuaweiIdStatusCodes.SIGN_IN_AUTH
                    || rstCode == HuaweiIdStatusCodes.SIGN_IN_CHECK_PASSWORD){
                Activity curActivity = ActivityMgr.INST.getLastActivity();
                if (curActivity == null) {
                    HMSAgentLog.e("activity is null");
                    onSignInResult(HMSAgent.AgentResultCode.NO_ACTIVITY_FOR_USE, null);
                    return;
                }

                try {
                    signInResultForDispose = result;
                    Intent nxtIntent = new Intent(curActivity, HMSSignInAgentActivity.class);
                    curActivity.startActivity(nxtIntent);
                } catch (Exception e) {
                    HMSAgentLog.e("start HMSSignInAgentActivity error:" + e.getMessage());
                    onSignInResult(HMSAgent.AgentResultCode.START_ACTIVITY_ERROR, null);
                }
            } else {
                onSignInResult(rstCode, null);
            }
        }
    }

    /**
     * 获取待处理的signInResult，供 HMSSignInAgentActivity 调用
     * @return 待处理的signInResult
     */
    SignInResult getSignInResult(){
        HMSAgentLog.d("getSignInResult=" + StrUtils.objDesc(signInResultForDispose));
        return signInResultForDispose;
    }

    void onSignInActivityResult(int rstCode, SignInHuaweiId result, boolean needReSignIn) {
        if (needReSignIn) {
            connect();
        } else {
            onSignInResult(rstCode, result);
        }
    }

    /**
     * 回调登录结果
     * @param rstCode 结果码
     * @param result 登录结果
     */
    private void onSignInResult(int rstCode, SignInHuaweiId result) {
        HMSAgentLog.i("signIn:callback=" + StrUtils.objDesc(handler) +" retCode=" + rstCode);
        if (handler != null) {
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<SignInHuaweiId>(handler, rstCode, result));
            handler = null;
        }
        signInResultForDispose = null;
        retryTimes = MAX_RETRY_TIMES;
    }

    /**
     * 帐号登录请求
     * @param handler 登录结果回调
     */
    public void signIn(final SignInHandler handler){
        HMSAgentLog.i("signIn:handler=" + StrUtils.objDesc(handler));

        if (this.handler != null) {
            HMSAgentLog.e("signIn:has already a signIn to dispose");
            new Handler(Looper.getMainLooper()).post(new CallbackResultRunnable<SignInHuaweiId>(handler, HMSAgent.AgentResultCode.REQUEST_REPEATED, null));
            return;
        }

        this.handler = handler;
        retryTimes = MAX_RETRY_TIMES;
        connect();
    }
}
