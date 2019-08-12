package com.huawei.android.hms.agent.pay;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.BaseAgentActivity;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.StrUtils;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.pay.HuaweiPay;
import com.huawei.hms.support.api.pay.PayResultInfo;

/**
 * 代理Activity，用于弹出解决问题的引导
 */
public class HMSPayAgentActivity extends BaseAgentActivity {

    private static final int REQUEST_PAY = 2000;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        Status statusForPay = PayApi.INST.getWaitPayStatus();
        if (statusForPay != null) {
            try {
                HMSAgentLog.d("start pay:statusForPay=" + StrUtils.objDesc(statusForPay));
                statusForPay.startResolutionForResult(this, REQUEST_PAY);
            } catch (Exception e) {
                HMSAgentLog.e("start activity error:" + e.getMessage());
                PayApi.INST.onPayEnd(HMSAgent.AgentResultCode.START_ACTIVITY_ERROR, null);
                finish();
            }
        } else {
            HMSAgentLog.e("statusForPay is null");
            finish();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if(requestCode == REQUEST_PAY) {
            HMSAgentLog.d("resultCode=" + resultCode);
            if (resultCode == Activity.RESULT_OK) {
                //获取支付完成信息
                PayResultInfo payResultInfo = HuaweiPay.HuaweiPayApi.getPayResultInfoFromIntent(data);
                if (payResultInfo != null) {
                    PayApi.INST.onPayEnd(payResultInfo.getReturnCode(), payResultInfo);
                } else {
                    PayApi.INST.onPayEnd(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                }
            } else {
                PayApi.INST.onPayEnd(HMSAgent.AgentResultCode.ON_ACTIVITY_RESULT_ERROR, null);
            }

            finish();
        }
    }
}
