package cclua.plugin.talkingdata;

import com.tendcloud.tenddata.TCAgent;
import com.tendcloud.tenddata.TDProfile;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import cclua.AppContext;

@SuppressWarnings("unused")
public class TalkingData {
    static {
        AppContext.registerPlugin(context -> AppContext.registerFeature("cclua.plugin.talkingdata", true));
    }

    private static final String TAG = TalkingData.class.getName();

    private static Map<String, Object> toMap(String jsonstr) {
        if (jsonstr == null || jsonstr.length() == 0)
            return null;

        try {
            Map<String, Object> map = new HashMap<>();
            JSONObject obj = new JSONObject(jsonstr);
            Iterator<String> itor = obj.keys();
            while (itor.hasNext()) {
                String key = itor.next();
                Object value = obj.get(key);
                map.put(key, value);
            }
            return map;
        } catch (JSONException e) {
            e.printStackTrace();
            return null;
        }
    }

    private static JSONObject toJson(String jsonstr) {
        try {
            return new JSONObject(jsonstr);
        } catch (JSONException e) {
            return null;
        }
    }

    public static void setLogEnabled(boolean value) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.LOG_ON = value);
    }

    private static TDProfile.ProfileType getType(int type) {
        if (type == 0)
            return TDProfile.ProfileType.ANONYMOUS;
        else if (type == 1)
            return TDProfile.ProfileType.REGISTERED;
        else if (type == 2)
            return TDProfile.ProfileType.SINA_WEIBO;
        else if (type == 3)
            return TDProfile.ProfileType.QQ;
        else if (type == 4)
            return TDProfile.ProfileType.QQ_WEIBO;
        else if (type == 5)
            return TDProfile.ProfileType.ND91;
        else if (type == 6)
            return TDProfile.ProfileType.WEIXIN;
        else if (type == 11)
            return TDProfile.ProfileType.TYPE1;
        else if (type == 12)
            return TDProfile.ProfileType.TYPE2;
        else if (type == 13)
            return TDProfile.ProfileType.TYPE3;
        else if (type == 14)
            return TDProfile.ProfileType.TYPE4;
        else if (type == 15)
            return TDProfile.ProfileType.TYPE5;
        else if (type == 16)
            return TDProfile.ProfileType.TYPE6;
        else if (type == 17)
            return TDProfile.ProfileType.TYPE7;
        else if (type == 18)
            return TDProfile.ProfileType.TYPE8;
        else if (type == 19)
            return TDProfile.ProfileType.TYPE9;
        else if (type == 20)
            return TDProfile.ProfileType.TYPE10;

        return TDProfile.ProfileType.ANONYMOUS;
    }

    public static void init(String appkey, String channel) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.init(context.getApplicationContext(), appkey, channel));
    }

    public static void onRegister(String profileID, int type, String name) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onRegister(profileID, getType(type), name));
    }

    public static void onLogin(String profileID, int type, String name) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onLogin(profileID, getType(type), name));
    }

    public static void setReportUncaughtExceptions(boolean value) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.setReportUncaughtExceptions(value));
    }

    public static void trackPageBegin(String name) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onPageStart(context, name));
    }

    public static void trackPageEnd(String name) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onPageEnd(context, name));
    }

    public static void trackEvent(String event) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onEvent(context, event));
    }

    public static void trackEvent(String event, String label) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onEvent(context, event, label));
    }

    public static void trackEvent(String event, String label, String kvstr) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onEvent(context, event, label, toMap(kvstr)));
    }

    public static void trackEvent(String event, String label, String kvstr, double value) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onEvent(context, event, label, toMap(kvstr), value));
    }

    public static void setGlobalKV(String key, boolean value) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.setGlobalKV(key, value));
    }

    public static void setGlobalKV(String key, String value) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.setGlobalKV(key, value));
    }

    public static void setGlobalKV(String key, long value) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.setGlobalKV(key, value));
    }

    public static void setGlobalKV(String key, double value) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.setGlobalKV(key, value));
    }

    public static void removeGlobalKV(String key) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.removeGlobalKV(key));
    }

    // order
    public static void placeOrder(String orderId, int amount, String currencyType) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onPlaceOrder(orderId, amount, currencyType));
    }

    public static void payOrder(String orderId, int amount, String currencyType, String paymentType) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onOrderPaySucc(orderId, amount, currencyType, paymentType));
    }

    public static void cancelOrder(String orderId, int amount, String currencyType) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onCancelOrder(orderId, amount, currencyType));
    }

    public static void viewItem(String itemId, String category, String name, int unitPrice) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> TCAgent.onViewItem(itemId, category, name, unitPrice));
    }
}