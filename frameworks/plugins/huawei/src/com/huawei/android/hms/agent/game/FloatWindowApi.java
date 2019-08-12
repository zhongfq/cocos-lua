package com.huawei.android.hms.agent.game;

import android.app.Activity;

import com.huawei.android.hms.agent.common.ActivityMgr;
import com.huawei.android.hms.agent.common.ApiClientMgr;
import com.huawei.android.hms.agent.common.EmptyConnectCallback;
import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.IActivityPauseCallback;
import com.huawei.android.hms.agent.common.IActivityResumeCallback;
import com.huawei.android.hms.agent.common.IClientConnectCallback;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.game.HuaweiGame;
import com.huawei.hms.support.api.game.ShowFloatWindowResult;

/**
 * 游戏浮标请求类
 * 游戏浮标接口只能以单实例访问，因为里面要保存是否要展示浮标的标识位
 */
public class FloatWindowApi implements IActivityResumeCallback, IActivityPauseCallback, IClientConnectCallback {

    /**
     * 单实例
     */
    public static final FloatWindowApi INST = new FloatWindowApi();

    /**
     * 是否开发者调用了展示游戏浮标
     */
    private boolean isShowFloatWindowCalled = false;

    /**
     * 当前浮标是否展示
     */
    private boolean isCurFloatShow = false;

    /**
     * HuaweiApiClient 连接结果回调
     *
     * @param rst    结果码
     * @param client HuaweiApiClient 实例
     */
    @Override
    public void onConnect(int rst, HuaweiApiClient client) {
        if (isCurFloatShow && client != null) {
            showFinal(true, null, client);
        }
    }

    private static class ShowFloatWindowCallBack implements ResultCallback<ShowFloatWindowResult>{
        @Override
        public void onResult(ShowFloatWindowResult result) {
            if (result == null) {
                HMSAgentLog.e("result is null");
                return;
            }

            Status status = result.getStatus();
            HMSAgentLog.d("show float end:status=" + status);
        }
    }

    /**
     * 私有构造方法
     */
    private FloatWindowApi(){
        // 注册onResume事件监听 如果自动处理在onResume显示；在onPause中隐藏， 则把下面代码打开
//        ActivityMgr.INST.registerActivitResumeEvent(this);
//        ActivityMgr.INST.registerActivitPauseEvent(this);
        ApiClientMgr.INST.registerClientConnect(this);
    }

    /**
     * 显示游戏浮标
     * @param activity 当前界面的activity
     */
    public void showFloatWindow(Activity activity) {
        HMSAgentLog.i("showFloatWindow");
        isShowFloatWindowCalled = true;
        showFinal(true, activity, ApiClientMgr.INST.getApiClient());
    }

    /**
     * 隐藏游戏浮标
     * @param activity 当前界面的activity
     */
    public void hideFloatWindow(Activity activity) {
        HMSAgentLog.i("hideFloatWindow");
        isShowFloatWindowCalled = false;
        showFinal(false, activity, ApiClientMgr.INST.getApiClient());
    }

    /**
     * 最终调用接口显示/隐藏浮标
     * @param show 是否显示浮标
     * @param activity 当前界面的activity
     * @param client HuaweiApiClient实例
     */
    private void showFinal(boolean show, Activity activity, HuaweiApiClient client) {

        // 保存当前浮标显示状态，以便出现异常浮标消失后，能够恢复
        isCurFloatShow = show;

        Activity curActivity = activity!=null ? activity : ActivityMgr.INST.getLastActivity();

        // 取得当前 activity 用于展示浮标
        if (curActivity == null) {
            HMSAgentLog.e("activity is null");
            return;
        }

        if (show) {
            if (client == null || !client.isConnected()) {
                HMSAgentLog.e("client is invalid");
                ApiClientMgr.INST.connect(new EmptyConnectCallback("try connect end when show float:"), false);
                return;
            }

            HMSAgentLog.d("show begin");
            PendingResult<ShowFloatWindowResult> pendingRst = HuaweiGame.HuaweiGameApi.showFloatWindow(client, curActivity);
            pendingRst.setResultCallback(new ShowFloatWindowCallBack());
        } else {
            HMSAgentLog.d("hide");
            HuaweiGame.HuaweiGameApi.hideFloatWindow(client, curActivity);
        }
    }

    /**
     * activity onResume 事件回调
     * @param activity 发生 onResume 事件的activity
     */
    @Override
    public void onActivityResume(Activity activity) {
        HMSAgentLog.d("autoShowFloatWindow:" + isShowFloatWindowCalled);
        if (isShowFloatWindowCalled) {
            showFinal(true, null, ApiClientMgr.INST.getApiClient());
        }
    }

    /**
     * Activity onPause回调
     *
     * @param activity 发生 onPause 事件的activity
     */
    @Override
    public void onActivityPause(Activity activity) {
        HMSAgentLog.d("autoShowFloatWindow:" + isShowFloatWindowCalled);
        showFinal(false, null, ApiClientMgr.INST.getApiClient());
    }
}
