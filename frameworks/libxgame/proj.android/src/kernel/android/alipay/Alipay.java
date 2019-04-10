package kernel.android.alipay;

import com.alipay.sdk.app.PayTask;

import org.cocos2dx.lib.Cocos2dxActivity;

import kernel.android.AppContext;
import kernel.android.LuaJ;

public class Alipay {
    public static void pay(final String order, final int handler) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                AppContext context = (AppContext) Cocos2dxActivity.getContext();
                PayTask payTask = new PayTask(context);
                final String resultstr = payTask.pay(order);

                context.runOnGLThread(new Runnable() {
                    @Override
                    public void run() {
                        AlipayResult result = new AlipayResult(resultstr);
                        LuaJ.invokeOnce(handler, AlipayUtil.appendVerifyStatus(result, false));
                    }
                });
            }
        }).start();
    }
}
