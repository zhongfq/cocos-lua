package cclua.plugin.alipay;

import com.alipay.sdk.app.PayTask;

import java.util.HashMap;

import cclua.AppContext;
import cclua.LuaJ;

@SuppressWarnings("unused")
public class Alipay {
    static {
        AppContext.registerPlugin(context -> AppContext.registerFeature("cclua.plugin.alipay", true));
    }

    private static final String TAG = Alipay.class.getSimpleName();
    private static long sCallback = 0;

    public static void setDispatcher(long callback) {
        sCallback = callback;
    }

    public static void pay(final String order) {
        new Thread(() -> {
            AppContext context = AppContext.getContext();
            PayTask payTask = new PayTask(context);
            final String resultstr = payTask.pay(order, true);
            AlipayResult result = new AlipayResult(resultstr);
            HashMap<String, Object> data = new HashMap<>();
            data.put("verify_status", false);
            data.put("result_status", result.resultStatus);
            data.put("result", result.result);
            data.put("memo", result.memo);
            LuaJ.invoke(sCallback, "pay", data);
        }).start();
    }
}
