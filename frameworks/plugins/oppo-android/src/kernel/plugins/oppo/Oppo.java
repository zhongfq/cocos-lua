package kernel.plugins.oppo;

import android.app.Activity;
import android.app.Application;
import android.util.Log;
import android.widget.Toast;

import com.nearme.game.sdk.GameCenterSDK;
import com.nearme.game.sdk.callback.ApiCallback;
import com.nearme.game.sdk.callback.GameExitCallback;
import com.nearme.game.sdk.callback.SinglePayCallback;
import com.nearme.game.sdk.common.model.biz.PayInfo;
import com.nearme.game.sdk.common.model.biz.ReqUserInfoParam;
import com.nearme.game.sdk.common.util.AppUtil;
import com.nearme.platform.opensdk.pay.PayResponse;

import org.json.JSONException;
import org.json.JSONObject;

import kernel.AppContext;
import kernel.LuaJ;
import kernel.PluginManager;

@SuppressWarnings("unused")
public class Oppo {
    private static final String TAG = Oppo.class.getSimpleName();

    static {
        PluginManager.registerPlugin(new PluginManager.Handler() {
            @Override
            public void onInit(Application app) {
                Log.i(TAG, "init oppo sdk");
                GameCenterSDK.init(AppContext.getMetaData("OPPO_APPID"), app);
                AppContext.registerFeature("oppo", true);
            }

            @Override
            public void onStart(Activity context) {
            }
        });
    }

    public static void pay(final String orderNo, final String attach, final int price, final String name, final String desc, final String url, final int handler) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                PayInfo payInfo = new PayInfo(orderNo, attach, price);
                payInfo.setProductName(name);
                payInfo.setProductDesc(desc);
                payInfo.setCallbackUrl(url);
                GameCenterSDK.getInstance().doSinglePay(context, payInfo, new SinglePayCallback() {
                    @Override
                    public void onCallCarrierPay(PayInfo payInfo, boolean b) {
                        Log.i(TAG, "onCallCarrierPay success");
                    }

                    @Override
                    public void onSuccess(String s) {
                        context.runOnGLThread(new Runnable() {
                            @Override
                            public void run() {
                                Log.i(TAG, "pay success");
                                LuaJ.invokeOnce(handler, "{\"status\": 0}");
                            }
                        });
                    }

                    @Override
                    public void onFailure(String s, final int i) {
                        context.runOnGLThread(new Runnable() {
                            @Override
                            public void run() {
                                if (i == PayResponse.CODE_CANCEL) {
                                    Log.i(TAG, "pay cancel");
                                    LuaJ.invokeOnce(handler, "{\"status\": 1}");
                                } else {
                                    Log.i(TAG, "pay fail");
                                    LuaJ.invokeOnce(handler, "{\"status\": 2}");
                                }
                            }
                        });
                    }
                });
            }
        });
    }

    private static void requestUserInfo(String token, String ssoid, final int handler) {
        final AppContext context = (AppContext) AppContext.getContext();
        GameCenterSDK.getInstance().doGetUserInfo(new ReqUserInfoParam(token, ssoid), new ApiCallback() {
            @Override
            public void onSuccess(final String s) {
                context.runOnGLThread(new Runnable() {
                    @Override
                    public void run() {
                        LuaJ.invokeOnce(handler, s);
                    }
                });
            }

            @Override
            public void onFailure(String s, int i) {
                authFailure(s, handler);
            }
        });
    }

    private static void authFailure(String err, final int handler) {
        final AppContext context = (AppContext) AppContext.getContext();
        Toast.makeText(context, err, Toast.LENGTH_SHORT).show();
        context.runOnGLThread(new Runnable() {
            @Override
            public void run() {
                LuaJ.invokeOnce(handler, "{\"status\": 2}");
            }
        });
    }

    public static void auth(final int handler) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                GameCenterSDK.getInstance().doLogin(context, new ApiCallback() {
                    @Override
                    public void onSuccess(String s) {
                        GameCenterSDK.getInstance().doGetTokenAndSsoid(new ApiCallback() {
                            @Override
                            public void onSuccess(String s) {
                                try {
                                    JSONObject json = new JSONObject(s);
                                    String token = json.getString("token");
                                    String ssoid = json.getString("ssoid");
                                    requestUserInfo(token, ssoid, handler);
                                } catch (JSONException e) {
                                    e.printStackTrace();
                                    authFailure("解析授权失败", handler);
                                }
                            }

                            @Override
                            public void onFailure(String s, int i) {
                                authFailure(s, handler);
                            }
                        });
                    }

                    @Override
                    public void onFailure(String s, int i) {
                        authFailure(s, handler);
                    }
                });
            }
        });
    }

    public static void exit() {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                GameCenterSDK.getInstance().onExit(context, new GameExitCallback() {
                    @Override
                    public void exitGame() {
                        AppUtil.exitGameProcess(context);
                    }
                });
            }
        });
    }
}
