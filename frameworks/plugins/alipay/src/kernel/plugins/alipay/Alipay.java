package kernel.plugins.alipay;

import android.app.Activity;
import android.app.Application;
import android.util.Log;

import com.alipay.sdk.app.PayTask;

import org.cocos2dx.lib.Cocos2dxActivity;

import kernel.AppContext;
import kernel.LuaJ;
import kernel.PluginManager;

@SuppressWarnings("unused")
public class Alipay {
    private static final String TAG = Alipay.class.getSimpleName();

    static {
        PluginManager.registerPlugin(new PluginManager.Handler() {
            @Override
            public void onInit(Application app) {
                Log.i(TAG, "init alipay sdk");
                AppContext.registerFeature("alipay", true);
            }

            @Override
            public void onStart(Activity context) {

            }
        });
    }

    public static void pay(final String order, final int handler) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                AppContext context = (AppContext) Cocos2dxActivity.getContext();
                PayTask payTask = new PayTask(context);
                final String resultstr = payTask.pay(order, true);

                AlipayResult result = new AlipayResult(resultstr);
                LuaJ.invokeOnce(handler, AlipayUtil.appendVerifyStatus(result, false));
            }
        }).start();
    }
}
