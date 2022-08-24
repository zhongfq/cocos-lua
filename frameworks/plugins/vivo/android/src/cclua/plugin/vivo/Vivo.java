package cclua.plugin.vivo;

import android.util.Log;

import com.vivo.unionsdk.open.VivoConfigInfo;
import com.vivo.unionsdk.open.VivoPayInfo;
import com.vivo.unionsdk.open.VivoUnionSDK;

import java.util.HashMap;

import cclua.AppContext;
import cclua.LuaJ;

@SuppressWarnings("unused")
public class Vivo {
    static {
        AppContext.registerPlugin(context -> AppContext.registerFeature("cclua.plugin.vivo", true));
    }

    private static final String TAG = Vivo.class.getSimpleName();
    private static long sCallback = 0;

    public static void setDispatcher(long callback) {
        sCallback = callback;
    }

    public static void init() {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            Log.i(TAG, "init vivo sdk");
            VivoConfigInfo configInfo = new VivoConfigInfo();
            configInfo.setShowAssit(false);
            VivoUnionSDK.initSdk(context.getApplicationContext(),
                    AppContext.getMetaData("VIVO_APPID"), false, configInfo);
        });
    }

    public static void pay(String appid, String orderNo, String url, String price, String name,
                           String desc, String sign) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            VivoPayInfo payInfo = new VivoPayInfo.Builder()
                    .setAppId(appid)
                    .setCpOrderNo(orderNo)
                    .setNotifyUrl(url)
                    .setProductPrice(price)
                    .setProductName(name)
                    .setProductDes(desc)
                    .setVivoSignature(sign)
                    .setExtUid("")
                    .build();
            VivoUnionSDK.payV2(context, payInfo, (callbackKey, success, errorCode) -> {
                HashMap<String, Object> data = new HashMap<>();
                data.put("callbackKey", callbackKey);
                data.put("success", success);
                data.put("errorCode", errorCode);
                LuaJ.invoke(sCallback, "pay", data);
            });
        });
    }
}
