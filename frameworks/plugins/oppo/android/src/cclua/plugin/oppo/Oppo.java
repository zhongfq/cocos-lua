package cclua.plugin.oppo;

import android.util.Log;

import com.nearme.game.sdk.GameCenterSDK;
import com.nearme.game.sdk.callback.SinglePayCallback;
import com.nearme.game.sdk.common.model.biz.PayInfo;
import com.nearme.game.sdk.common.util.AppUtil;
import com.nearme.platform.opensdk.pay.PayResponse;

import java.util.HashMap;

import cclua.AppContext;
import cclua.LuaJ;

@SuppressWarnings("unused")
public class Oppo {
    static {
        AppContext.registerPlugin(context -> AppContext.registerFeature("cclua.plugin.oppo", true));
    }

    private static final String TAG = Oppo.class.getSimpleName();
    private static long sCallback = 0;

    public static void setDispatcher(long callback) {
        sCallback = callback;
    }

    public static void init() {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            Log.i(TAG, "init oppo sdk");
            GameCenterSDK.init(AppContext.getMetaData("OPPO_APPID"), context);
        });
    }

    public static void pay(String orderNo, String attach, int price, String name, String desc,
                           String url) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            PayInfo payInfo = new PayInfo(orderNo, attach, price);
            payInfo.setProductName(name);
            payInfo.setProductDesc(desc);
            payInfo.setCallbackUrl(url);
            GameCenterSDK.getInstance().doSinglePay(context, payInfo, new SinglePayCallback() {
                @Override
                public void onCallCarrierPay(PayInfo payInfo, boolean b) {
                    Log.i(TAG, "onCallCarrierPay success");
                    HashMap<String, Object> data = new HashMap<>();
                    data.put("carrierPay", b);
                    data.put("amount", payInfo.getAmount());
                    data.put("attach", payInfo.getAttach());
                    data.put("currency", payInfo.getCurrency());
                    data.put("countryCode", payInfo.getCountryCode());
                    data.put("type", payInfo.getType());
                    data.put("callbackUrl", payInfo.getCallbackUrl());
                    data.put("order", payInfo.getOrder());
                    data.put("productDesc", payInfo.getProductDesc());
                    data.put("productName", payInfo.getProductName());
                    data.put("showCpSmsChannel", payInfo.getShowCpSmsChannel());
                    data.put("useCachedChannel", payInfo.getUseCachedChannel());
                    data.put("voucherCount", payInfo.getVoucherCount());
                    data.put("voucherId", payInfo.getVoucherId());
                    data.put("voucherType", payInfo.getVoucherType());
                    LuaJ.invoke(sCallback, "pay", data);
                }

                @Override
                public void onSuccess(String s) {
                    Log.i(TAG, "pay success");
                    HashMap<String, Object> data = new HashMap<>();
                    data.put("errcode", PayResponse.CODE_SUCCESS);
                    LuaJ.invoke(sCallback, "pay", data);
                }

                @Override
                public void onFailure(String s, final int i) {
                    HashMap<String, Object> data = new HashMap<>();
                    data.put("errcode", i);
                    LuaJ.invoke(sCallback, "pay", data);
                }
            });
        });
    }

    public static void exit() {
        final AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> GameCenterSDK.getInstance().onExit(context, () ->
                AppUtil.exitGameProcess(context)));
    }
}
