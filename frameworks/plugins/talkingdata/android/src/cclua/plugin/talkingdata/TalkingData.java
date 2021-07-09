package cclua.plugin.talkingdata;

import android.app.Activity;
import android.app.Application;
import android.content.Context;

import com.tendcloud.tenddata.Order;
import com.tendcloud.tenddata.TCAgent;
import com.tendcloud.tenddata.TDProfile;
import com.tendcloud.tenddata.a;
import com.tendcloud.tenddata.ac;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import cclua.AppContext;
import cclua.PluginManager;

@SuppressWarnings("unused")
public class TalkingData {
    private static final String TAG = TalkingData.class.getName();

    static {
        PluginManager.registerPlugin(new PluginManager.Handler() {
            @Override
            public void onInit(Application app) {
                AppContext.registerFeature("talkingdata", true);
            }

            @Override
            public void onStart(Activity context) {
            }
        });
    }

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

    public static void setLogEnabled(final boolean value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.LOG_ON = value;
            }
        });
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

    public static void init(final String appkey, final String channel) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.init(context.getApplicationContext(), appkey, channel);
            }
        });
    }

    public static void onRegister(final String profileID, final int type, final String name) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onRegister(profileID, getType(type), name);
            }
        });
    }

    public static void onLogin(final String profileID, final int type, final String name) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onLogin(profileID, getType(type), name);
            }
        });
    }

    public static void setReportUncaughtExceptions(final boolean value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.setReportUncaughtExceptions(value);
            }
        });
    }

    public static void trackPageBegin(final String name) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onPageStart(context, name);
            }
        });
    }

    public static void trackPageEnd(final String name) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onPageEnd(context, name);
            }
        });
    }

    public static void trackEvent(final String event) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onEvent(context, event);
            }
        });
    }

    public static void trackEvent(final String event, final String label) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onEvent(context, event, label);
            }
        });
    }

    public static void trackEvent(final String event, final String label, final String kvstr) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onEvent(context, event, label, toMap(kvstr));
            }
        });
    }

    public static void trackEvent(final String event, final String label, final String kvstr, final double value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onEvent(context, event, label, toMap(kvstr), value);
            }
        });
    }

    public static void setGlobalKV(final String key, final boolean value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.setGlobalKV(key, value);
            }
        });
    }

    public static void setGlobalKV(final String key, final String value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.setGlobalKV(key, value);
            }
        });
    }

    public static void setGlobalKV(final String key, final long value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.setGlobalKV(key, value);
            }
        });
    }

    public static void setGlobalKV(final String key, final double value) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.setGlobalKV(key, value);
            }
        });
    }

    public static void removeGlobalKV(final String key) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.removeGlobalKV(key);
            }
        });
    }

    // order
    public static void placeOrder(final String orderId, final int amount, final String currencyType) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onPlaceOrder(orderId, amount, currencyType);
            }
        });
    }

    public static void payOrder(final String orderId, final int amount, final String currencyType, final String paymentType)
    {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onOrderPaySucc(orderId, amount, currencyType, paymentType);
            }
        });
    }

    public static void cancelOrder(final String orderId, final int amount, final String currencyType)
    {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onCancelOrder(orderId, amount, currencyType);
            }
        });
    }

    public static void viewItem(final String itemId, final String category, final String name, final int unitPrice)
    {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                TCAgent.onViewItem(itemId, category, name, unitPrice);
            }
        });
    }
}