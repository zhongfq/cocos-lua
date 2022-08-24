package cclua.plugin.jiguang;

import android.util.Log;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import cclua.AppContext;
import cn.jiguang.analytics.android.api.Account;
import cn.jiguang.analytics.android.api.BrowseEvent;
import cn.jiguang.analytics.android.api.CalculateEvent;
import cn.jiguang.analytics.android.api.CountEvent;
import cn.jiguang.analytics.android.api.Currency;
import cn.jiguang.analytics.android.api.JAnalyticsInterface;
import cn.jiguang.analytics.android.api.LoginEvent;
import cn.jiguang.analytics.android.api.PurchaseEvent;
import cn.jiguang.analytics.android.api.RegisterEvent;

@SuppressWarnings("unused")
public class JAnalytics {
    static {
        AppContext.registerPlugin(context -> AppContext.registerFeature("cclua.plugin.janalytics", true));
    }

    private static final String TAG = JAnalytics.class.getSimpleName();

    public static final int LOGIN = 0;
    public static final int REGISTER = 1;
    public static final int PURCHASE = 2;
    public static final int BROWSE = 3;
    public static final int COUNT = 4;
    public static final int CALCULATE = 5;

    public static void init(String appKey, String channel) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            JAnalyticsInterface.init(context);
            JAnalyticsInterface.setChannel(context, channel);
        });

    }

    public static void startTrackPage(String pageName) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> JAnalyticsInterface.onPageStart(context, pageName));
    }

    public static void stopTrackPage(String pageName) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> JAnalyticsInterface.onPageEnd(context, pageName));
    }

    private static Map<String, String> getJsonExtra(JSONObject obj) {
        if (obj.has("extra") && !obj.isNull("extra")) {
            try {
                Map<String, String> map = new HashMap<>();
                JSONObject mapObj = obj.getJSONObject("extra");
                Iterator<String> iterator = mapObj.keys();
                while (iterator.hasNext()) {
                    String key = iterator.next();
                    map.put(key, mapObj.getString(key));
                }
                return map;
            } catch (JSONException ignored) {
            }
        }
        return null;
    }

    public static void trackEvent(int type, String dataStr) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            try {
                JSONObject data = new JSONObject(dataStr);
                switch (type) {
                    case LOGIN: {
                        LoginEvent event = new LoginEvent();
                        event.setExtMap(getJsonExtra(data));
                        event.setLoginMethod(data.getString("method"));
                        event.setLoginSuccess(data.getBoolean("success"));
                        JAnalyticsInterface.onEvent(context, event);
                        break;
                    }
                    case REGISTER: {
                        RegisterEvent event = new RegisterEvent();
                        event.setExtMap(getJsonExtra(data));
                        event.setRegisterMethod(data.getString("method"));
                        event.setRegisterSuccess(data.getBoolean("success"));
                        JAnalyticsInterface.onEvent(context, event);
                        break;
                    }
                    case PURCHASE: {
                        PurchaseEvent event = new PurchaseEvent();
                        event.setPurchasePrice(data.getDouble("price"));
                        event.setPurchaseSuccess(data.getBoolean("success"));
                        event.setPurchaseGoodsid(data.getString("id"));
                        event.setPurchaseGoodsname(data.getString("name"));
                        event.setPurchaseGoodstype(data.getString("type"));
                        event.setPurchaseCurrency(Currency.valueOf(data.getString("currency")));
                        event.setPurchaseGoodsCount(data.getInt("quantity"));
                        event.setExtMap(getJsonExtra(data));
                        JAnalyticsInterface.onEvent(context, event);
                        break;
                    }
                    case BROWSE: {
                        BrowseEvent event = new BrowseEvent();
                        event.setExtMap(getJsonExtra(data));
                        event.setBrowseName(data.getString("name"));
                        event.setBrowseId(data.getString("id"));
                        event.setBrowseType(data.getString("type"));
                        event.setBrowseDuration((float) data.getDouble("duration"));
                        JAnalyticsInterface.onEvent(context, event);
                        break;
                    }
                    case COUNT: {
                        CountEvent event = new CountEvent();
                        event.setExtMap(getJsonExtra(data));
                        event.setEventId(data.getString("id"));
                        JAnalyticsInterface.onEvent(context, event);
                        break;
                    }
                    case CALCULATE: {
                        CalculateEvent event = new CalculateEvent();
                        event.setExtMap(getJsonExtra(data));
                        event.setEventId(data.getString("id"));
                        event.setEventValue(data.getDouble("value"));
                        JAnalyticsInterface.onEvent(context, event);
                        break;
                    }
                }
            } catch (Throwable e) {
                e.printStackTrace();
            }
        });
    }

    public static void identifyAccount(String dataStr) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            try {
                JSONObject data = new JSONObject(dataStr);
                Account account = new Account(data.getString("account"));
                if (data.has("creationTime")) {
                    account.setCreationTime(data.getLong("creationTime"));
                }
                if (data.has("sex")) {
                    account.setSex(data.getInt("sex"));
                }
                if (data.has("birthday")) {
                    account.setBirthdate(data.getString("birthday"));
                }
                if (data.has("paid")) {
                    account.setPaid(data.getInt("paid"));
                }
                if (data.has("phone")) {
                    account.setPhone(data.getString("phone"));
                }
                if (data.has("email")) {
                    account.setEmail(data.getString("email"));
                }
                if (data.has("name")) {
                    account.setName(data.getString("name"));
                }
                if (data.has("wechat")) {
                    account.setName(data.getString("wechat"));
                }
                if (data.has("qq")) {
                    account.setName(data.getString("qq"));
                }
                if (data.has("weibo")) {
                    account.setName(data.getString("weibo"));
                }
                if (data.has("extras") && !data.isNull("extras")) {
                    JSONObject extras = data.getJSONObject("extras");
                    Iterator<String> iterator = extras.keys();
                    while (iterator.hasNext()) {
                        String key = iterator.next();
                        Object value = extras.get(key);
                        if (extras.isNull(key)) {
                            account.setExtraAttr(key, null);
                        } else if (value instanceof Number) {
                            account.setExtraAttr(key, (Number) value);
                        } else {
                            account.setExtraAttr(key, data.getString(key));
                        }
                    }
                }
                JAnalyticsInterface.identifyAccount(context, account, (code, msg) ->
                        Log.d(TAG, "code = " + code + " msg =" + msg));
            } catch (JSONException e) {
                e.printStackTrace();
            }
        });
    }

    public static void detachAccount() {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> JAnalyticsInterface.detachAccount(context, (code, msg) ->
                Log.d(TAG, "code = " + code + " msg =" + msg)));

    }

    public static void setFrequency(int frequency) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> JAnalyticsInterface.setAnalyticsReportPeriod(context, frequency));
    }

    public static void setDebug(boolean enable) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> JAnalyticsInterface.setDebugMode(enable));
    }
}
