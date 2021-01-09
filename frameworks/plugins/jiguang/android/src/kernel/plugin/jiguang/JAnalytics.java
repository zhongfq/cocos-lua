package kernel.plugin.jiguang;

import android.app.Activity;
import android.app.Application;
import android.util.Log;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import cn.jiguang.analytics.android.api.Account;
import cn.jiguang.analytics.android.api.AccountCallback;
import cn.jiguang.analytics.android.api.BrowseEvent;
import cn.jiguang.analytics.android.api.CalculateEvent;
import cn.jiguang.analytics.android.api.CountEvent;
import cn.jiguang.analytics.android.api.Currency;
import cn.jiguang.analytics.android.api.JAnalyticsInterface;
import cn.jiguang.analytics.android.api.LoginEvent;
import cn.jiguang.analytics.android.api.PurchaseEvent;
import cn.jiguang.analytics.android.api.RegisterEvent;
import kernel.AppContext;
import kernel.PluginManager;

public class JAnalytics {
    private static final String TAG = JAnalytics.class.getSimpleName();
    private static Application mContext;

    enum EventType {
        LOGIN, REGISTER, PURCHASE, BROWSE, COUNT, CALCULATE
    }

    static {
        PluginManager.registerPlugin(new PluginManager.Handler() {
            @Override
            public void onInit(Application app) {
                Log.i(TAG, "init janalytics");
                mContext = app;
                AppContext.registerFeature("janalytics", true);
            }

            @Override
            public void onStart(Activity context) {
            }
        });
    }

    public static void init(String appKey, String channel) {
        JAnalyticsInterface.init(mContext);
        JAnalyticsInterface.setChannel(mContext, channel);
    }

    public static void startTrackPage(String pageName) {
        JAnalyticsInterface.onPageStart(mContext, pageName);
    }

    public static void stopTrackPage(String pageName) {
        JAnalyticsInterface.onPageEnd(mContext, pageName);
    }

    private static Map<String, String> getJsonExtra(JSONObject obj)
    {
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

    public static void trackEvent(String type, String dataStr) {
        try {
            EventType eventType = EventType.valueOf(type);
            JSONObject data = new JSONObject(dataStr);
            switch (eventType) {
                case LOGIN: {
                    LoginEvent event = new LoginEvent();
                    event.setExtMap(getJsonExtra(data));
                    event.setLoginMethod(data.getString("method"));
                    event.setLoginSuccess(data.getBoolean("success"));
                    JAnalyticsInterface.onEvent(mContext, event);
                    break;
                }
                case REGISTER: {
                    RegisterEvent event = new RegisterEvent();
                    event.setExtMap(getJsonExtra(data));
                    event.setRegisterMethod(data.getString("method"));
                    event.setRegisterSuccess(data.getBoolean("success"));
                    JAnalyticsInterface.onEvent(mContext, event);
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
                    JAnalyticsInterface.onEvent(mContext, event);
                    break;
                }
                case BROWSE: {
                    BrowseEvent event = new BrowseEvent();
                    event.setExtMap(getJsonExtra(data));
                    event.setBrowseName(data.getString("name"));
                    event.setBrowseId(data.getString("id"));
                    event.setBrowseType(data.getString("type"));
                    event.setBrowseDuration((float) data.getDouble("duration"));
                    JAnalyticsInterface.onEvent(mContext, event);
                    break;
                }
                case COUNT: {
                    CountEvent event = new CountEvent();
                    event.setExtMap(getJsonExtra(data));
                    event.setEventId(data.getString("id"));
                    JAnalyticsInterface.onEvent(mContext, event);
                    break;
                }
                case CALCULATE: {
                    CalculateEvent event = new CalculateEvent();
                    event.setExtMap(getJsonExtra(data));
                    event.setEventId(data.getString("id"));
                    event.setEventValue(data.getDouble("value"));
                    JAnalyticsInterface.onEvent(mContext, event);
                    break;
                }
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }

    public static void identifyAccount(String dataStr) {
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
                        account.setExtraAttr(key, (Number)value);
                    } else {
                        account.setExtraAttr(key, data.getString(key));
                    }
                }
            }
            JAnalyticsInterface.identifyAccount(mContext, account, new AccountCallback() {
                @Override
                public void callback(int code, String msg) {
                    Log.d(TAG, "code = " + code  + " msg =" + msg);
                }
            });
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    public static void detachAccount() {
        JAnalyticsInterface.detachAccount(mContext, new AccountCallback() {
            @Override
            public void callback(int code, String msg) {
                Log.d(TAG, "code = " + code  + " msg =" + msg);
            }
        });
    }

    public static void setFrequency(int frequency) {
        JAnalyticsInterface.setAnalyticsReportPeriod(mContext, frequency);
    }

    public static void setDebug(boolean enable) {
        JAnalyticsInterface.setDebugMode(enable);
    }
}
