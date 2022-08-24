package cclua.plugin.jiguang;

import org.json.JSONArray;
import org.json.JSONException;

import java.util.Set;
import java.util.TreeSet;

import cclua.AppContext;
import cn.jpush.android.api.JPushInterface;

@SuppressWarnings("unused")
public class JPush {
    static {
        AppContext.registerPlugin(context -> {
            AppContext.registerFeature("cclua.plugin.jpush", true);
            testPushEnabled("jpush.oppo", "cn.jpush.android.service.PluginOppoPushService");
            testPushEnabled("jpush.vivo", "cn.jpush.android.service.PluginVivoMessageReceiver");
            testPushEnabled("jpush.xiaomi", "cn.jpush.android.service.PluginXiaomiPlatformsReceiver");
            testPushEnabled("jpush.huawei", "cn.jpush.android.service.PluginHuaweiPlatformsService");
        });
    }

    private static final String TAG = JPush.class.getSimpleName();

    private static void testPushEnabled(String api, String classname) {
        try {
            Class<?> PushManager = Class.forName(classname);
            AppContext.registerFeature(api, true);
        } catch (Throwable ignored) {
        }
    }

    public static void init(String appKey, String channel) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            JPushInterface.init(AppContext.getContext());
            JPushInterface.setChannel(AppContext.getContext(), channel);
        });
    }

    public static void setAlias(String alias) {
        JPushInterface.setAlias(AppContext.getContext(), 0, alias);
    }

    public static void deleteAlias() {
        JPushInterface.deleteAlias(AppContext.getContext(), 0);
    }

    private static Set<String> toSet(String value) {
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
        JPushInterface.addTags(AppContext.getContext(), 0, toSet(tags));
    }

    public static void setTags(String tags) {
        JPushInterface.setTags(AppContext.getContext(), 0, toSet(tags));
    }

    public static void deleteTags(String tags) {
        JPushInterface.deleteTags(AppContext.getContext(), 0, toSet(tags));
    }

    public static void cleanTags() {
        JPushInterface.cleanTags(AppContext.getContext(), 0);
    }

    public static void setDebugMode(boolean debug) {
        JPushInterface.setDebugMode(debug);
    }

    public static void setLogOFF() {
    }

    public static boolean isEnabled() {
        return JPushInterface.isNotificationEnabled(AppContext.getContext()) == 1;
    }

    public static void setBadge(int value) {
        JPushInterface.setBadgeNumber(AppContext.getContext(), value);
    }

    public static String getRegistrationID() {
        return JPushInterface.getRegistrationID(AppContext.getContext());
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