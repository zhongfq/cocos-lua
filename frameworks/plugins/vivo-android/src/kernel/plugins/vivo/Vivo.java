package kernel.plugins.vivo;

import android.app.Activity;
import android.app.Application;
import android.util.Log;

import com.vivo.unionsdk.open.VivoConfigInfo;
import com.vivo.unionsdk.open.VivoPayCallback;
import com.vivo.unionsdk.open.VivoPayInfo;
import com.vivo.unionsdk.open.VivoUnionSDK;

import org.json.JSONException;
import org.json.JSONObject;

import kernel.AppContext;
import kernel.LuaJ;
import kernel.PluginManager;

@SuppressWarnings("unused")
public class Vivo {
    private static final String TAG = Vivo.class.getSimpleName();

    static {
        PluginManager.registerPlugin(new PluginManager.Handler() {
            @Override
            public void onInit(Application app) {
                Log.i(TAG, "init vivo sdk");
                VivoConfigInfo configInfo = new VivoConfigInfo();
                configInfo.setShowAssit(false);
                VivoUnionSDK.initSdk(app, AppContext.getMetaData("VIVO_APPID"), false, configInfo);
                AppContext.registerFeature("vivo", true);
            }

            @Override
            public void onStart(Activity context) {
            }
        });
    }

    public static void pay(String appid, String orderNo, String url, String price, String name,
                           String desc, String sign, final int handler) {
        final AppContext context = (AppContext) AppContext.getContext();
        final VivoPayInfo payInfo = new VivoPayInfo.Builder()
                .setAppId(appid)
                .setCpOrderNo(orderNo)
                .setNotifyUrl(url)
                .setProductPrice(price)
                .setProductName(name)
                .setProductDes(desc)
                .setVivoSignature(sign)
                .setExtUid("")
                .build();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                VivoUnionSDK.payV2(context, payInfo, new VivoPayCallback() {
                    @Override
                    public void onVivoPayResult(final String callbackKey, final boolean success, final String errorCode) {
                        context.runOnGLThread(new Runnable() {
                            @Override
                            public void run() {
                                try {
                                    JSONObject obj = new JSONObject();
                                    obj.put("callbackKey", callbackKey);
                                    obj.put("success", success);
                                    obj.put("errorCode", errorCode);
                                    LuaJ.invokeOnce(handler, obj.toString());
                                } catch (JSONException e) {
                                    e.printStackTrace();
                                    LuaJ.invokeOnce(handler, "{}");
                                }
                            }
                        });
                    }
                });
            }
        });

    }
}
