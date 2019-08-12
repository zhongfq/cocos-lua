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
import com.huawei.hms.support.api.pay.ProductPayResultInfo;

/**
 * 代理Activity，用于弹出解决问题的引导
 */
public class HMSPMSPayAgentActivity extends BaseAgentActivity {

    private static final int REQUEST_PMSPAY = 3000;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        Status statusForPay = ProductPayApi.INST.getWaitPayStatus();
        if (statusForPay != null) {
            try {
                HMSAgentLog.d("start pay:statusForPay=" + StrUtils.objDesc(statusForPay));
                statusForPay.startResolutionForResult(this, REQUEST_PMSPAY);
            } catch (Exception e) {
                HMSAgentLog.e("start activity error:" + e.getMessage());
                ProductPayApi.INST.onPMSPayEnd(HMSAgent.AgentResultCode.START_ACTIVITY_ERROR, null);
                finish();
            }
        } else {
            HMSAgentLog.e("statusForPMSPay is null");
            finish();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if(requestCode == REQUEST_PMSPAY) {
            HMSAgentLog.d("resultCode=" + resultCode);
            if (resultCode == Activity.RESULT_OK) {
                //获取支付完成信息
                ProductPayResultInfo payResultInfo = HuaweiPay.HuaweiPayApi.getProductPayResultFromIntent(data);
                if (payResultInfo != null) {
                    ProductPayApi.INST.onPMSPayEnd(payResultInfo.getReturnCode(), payResultInfo);
                } else {
                    ProductPayApi.INST.onPMSPayEnd(HMSAgent.AgentResultCode.RESULT_IS_NULL, null);
                }
            } else {
                ProductPayApi.INST.onPMSPayEnd(HMSAgent.AgentResultCode.ON_ACTIVITY_RESULT_ERROR, null);
            }

            finish();
        }
    }
}
