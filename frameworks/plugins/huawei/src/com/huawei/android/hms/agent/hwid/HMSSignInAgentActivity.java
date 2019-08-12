package com.huawei.android.hms.agent.hwid;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.BaseAgentActivity;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.hms.support.api.hwid.HuaweiId;
import com.huawei.hms.support.api.hwid.HuaweiIdStatusCodes;
import com.huawei.hms.support.api.hwid.SignInResult;

/**
 * 代理Activity，用于处理华为帐号登录的引导
 */
public class HMSSignInAgentActivity extends BaseAgentActivity {

    //启动参数，用来区分是调用的登录intent还是授权intent
    private static final int REQUEST_SIGN_IN_UNLOGIN = 1002;
    private static final int REQUEST_SIGN_IN_AUTH = 1003;
    private static final int REQUEST_SIGN_IN_CHECK_PASSWORD = 1005;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        SignInResult signInResult = SignInApi.INST.getSignInResult();
        if (signInResult != null) {
            try {
                Intent nxtIntent = signInResult.getData();
                int statusCode = signInResult.getStatus().getStatusCode();
                int nxtRequestCode = 0;
                if(statusCode == HuaweiIdStatusCodes.SIGN_IN_UNLOGIN){
                    HMSAgentLog.d("帐号未登录=========");
                    nxtRequestCode = REQUEST_SIGN_IN_UNLOGIN;
                } else if(statusCode == HuaweiIdStatusCodes.SIGN_IN_AUTH){
                    HMSAgentLog.d("帐号已登录，需要用户授权========");
                    nxtRequestCode = REQUEST_SIGN_IN_AUTH;
                } else if(statusCode == HuaweiIdStatusCodes.SIGN_IN_CHECK_PASSWORD){
                    HMSAgentLog.d("帐号需要验证密码========");
                    nxtRequestCode = REQUEST_SIGN_IN_CHECK_PASSWORD;
                } else {
                    //其他异常
                    HMSAgentLog.d("其他错误========"+statusCode);
                    SignInApi.INST.onSignInActivityResult(statusCode, null, false);
                    finish();
                    return;
                }

                HMSAgentLog.d("start signin ui:" + statusCode);
                startActivityForResult(nxtIntent, nxtRequestCode);
            } catch (Exception e) {
                HMSAgentLog.e("start activity error:" + e.getMessage());
                SignInApi.INST.onSignInActivityResult(HMSAgent.AgentResultCode.START_ACTIVITY_ERROR, null, false);
                finish();
            }
        } else {
            HMSAgentLog.e("signInResult to dispose is null");
            finish();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == REQUEST_SIGN_IN_UNLOGIN
                || requestCode == REQUEST_SIGN_IN_CHECK_PASSWORD) {
            //当返回值是-1的时候表明用户登录成功，需要CP再次调用signIn
            if(resultCode == Activity.RESULT_OK) {
                SignInApi.INST.onSignInActivityResult(resultCode, null, true);
            } else {
                SignInApi.INST.onSignInActivityResult(HMSAgent.AgentResultCode.ON_ACTIVITY_RESULT_ERROR, null, false);
            }

            finish();
        } else if (requestCode == REQUEST_SIGN_IN_AUTH) {
            //当返回值是-1的时候表明用户确认授权，
            if(resultCode == Activity.RESULT_OK) {
                HMSAgentLog.d("用户已经授权");
                SignInResult result = HuaweiId.HuaweiIdApi.getSignInResultFromIntent(data);

                if (result == null) {
                    SignInApi.INST.onSignInActivityResult(HMSAgent.AgentResultCode.RESULT_IS_NULL, null, false);
                } else if (result.isSuccess()) {
                    // 授权成功，result.getSignInHuaweiId()获取华为帐号信息
                    SignInApi.INST.onSignInActivityResult(result.getStatus().getStatusCode(), result.getSignInHuaweiId(), false);
                } else {
                    // 授权失败，result.getStatus()获取错误原因
                    HMSAgentLog.e("授权失败 失败原因:" + result.getStatus().toString());
                    SignInApi.INST.onSignInActivityResult(result.getStatus().getStatusCode(), null, false);
                }
            } else {
                //当resultCode 为0的时候表明用户未授权，则CP可以处理用户未授权事件
                HMSAgentLog.e("用户未授权");
                SignInApi.INST.onSignInActivityResult(HMSAgent.AgentResultCode.ON_ACTIVITY_RESULT_ERROR, null, false);
            }

            finish();
        }
    }
}
