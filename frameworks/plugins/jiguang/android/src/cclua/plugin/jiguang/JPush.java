package cclua.plugin.jiguang;

import android.app.Activity;
import android.app.Application;
import android.util.Log;

import org.json.JSONArray;
import org.json.JSONException;

import java.lang.reflect.Method;
import java.util.Set;
import java.util.TreeSet;

import cn.jpush.android.api.JPushInterface;
import cclua.AppContext;
import cclua.PluginManager;

@SuppressWarnings("unused")
public class JPush {
    private static final String TAG = JPush.class.getSimpleName();
    private static Application mContext;

    static {
        PluginManager.registerPlugin(new PluginManager.Handler() {
            @Override
            public void onInit(Application app) {
                Log.i(TAG, "init jpush");
                mContext = app;
                AppContext.registerFeature("jpush", true);
            }

            @Override
            public void onStart(Activity context) {
            }
        });
    }

    public static void init(String appKey, String channel) {
        JPushInterface.init(mContext);
        JPushInterface.setChannel(mContext, channel);
    }

    public static void setAlias(String alias) {
        JPushInterface.setAlias(mContext, 0, alias);
    }

    public static void deleteAlias() {
        JPushInterface.deleteAlias(mContext, 0);
    }

    private static Set<String> toSet(String value)
    {
        Set<String> tags = new TreeSet<>();
        try {
            JSONArray arr = new JSONArray(value);
            for (int i = 0; i < arr.length(); i++) {
                tags.add(arr.getString(i));
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return tags;
    }

    public static void addTags(String tags) {
        JPushInterface.addTags(mContext, 0, toSet(tags));
    }

    public static void setTags(String tags) {
        JPushInterface.setTags(mContext, 0, toSet(tags));
    }

    public static void deleteTags(String tags) {
        JPushInterface.deleteTags(mContext, 0, toSet(tags));
    }

    public static void cleanTags() {
        JPushInterface.cleanTags(mContext, 0);
    }

    public static void setDebugMode(boolean debug) {
        JPushInterface.setDebugMode(debug);
    }

    public static void setLogOFF() {
    }

    public static boolean isEnabled() {
        return JPushInterface.isNotificationEnabled(mContext) == 1;
    }

    public static void setBadge(int value) {
        JPushInterface.setBadgeNumber(mContext, value);
    }

    public static String getRegistrationID() {
        return JPushInterface.getRegistrationID(mContext);
    }

    public static void requestPermission() {
        try {
            // oppo
            Class<?> PushManager = Class.forName("com.heytap.mcssdk.PushManager");
            Object instance = PushManager.getMethod("getInstance").invoke(null);
            PushManager.getMethod("requestNotificationPermission").invoke(instance);
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }
}