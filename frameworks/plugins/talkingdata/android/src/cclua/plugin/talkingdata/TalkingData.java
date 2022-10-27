package cclua.plugin.talkingdata;

import com.tendcloud.tenddata.TalkingDataGender;
import com.tendcloud.tenddata.TalkingDataProfile;
import com.tendcloud.tenddata.TalkingDataProfileType;
import com.tendcloud.tenddata.TalkingDataSDK;
import com.tendcloud.tenddata.TalkingDataSearch;

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

    public static String getDeviceId() {
        AppContext context = AppContext.getContext();
        return TalkingDataSDK.getDeviceId(context);
    }

    public static void setVerboseLogDisable() {
        TalkingDataSDK.setVerboseLogDisable();
    }

    public static void setConfigurationDisable(long options) {
        TalkingDataSDK.setConfigurationDisable((int) options);
    }

    public static void backgroundSessionEnabled() {
    }

    public static void init(String appkey, String channel, String custom) {
        AppContext context = AppContext.getContext();
        TalkingDataSDK.init(context, appkey, channel, custom);
    }

    public static void setVendorId(String vendorId, int type) {
    }

    public static void setLocation(double latitude, double longitude) {
    }

    public static void setExceptionReportEnabled(boolean value) {
        TalkingDataSDK.setReportUncaughtExceptions(value);
    }

    public static void setSignalReportEnabled(boolean value) {
    }

    public static void onPageBegin(String name) {
        AppContext context = AppContext.getContext();
        TalkingDataSDK.onPageBegin(context, name);
    }

    public static void onPageEnd(String name) {
        AppContext context = AppContext.getContext();
        TalkingDataSDK.onPageEnd(context, name);
    }

    public static void onReceiveDeepLink(String link) {
        TalkingDataSDK.onReceiveDeepLink(link);
    }

    private static TalkingDataProfile toProfile(String json) {
        TalkingDataProfile profile = TalkingDataProfile.createProfile();
        try {
            JSONObject data = new JSONObject(json);
            if (data.has("name")) {
                profile.setName(data.getString("name"));
            }
            if (data.has("age")) {
                profile.setAge(data.getInt("age"));
            }
            if (data.has("type")) {
                profile.setType(TalkingDataProfileType.valueOf(data.getString("type")));
            }
            if (data.has("gender")) {
                profile.setGender(TalkingDataGender.valueOf(data.getString("gender")));
            }
            if (data.has("property1")) {
                profile.setProperty1(data.get("property1"));
            }
            if (data.has("property2")) {
                profile.setProperty2(data.get("property2"));
            }
            if (data.has("property3")) {
                profile.setProperty3(data.get("property3"));
            }
            if (data.has("property4")) {
                profile.setProperty4(data.get("property4"));
            }
            if (data.has("property5")) {
                profile.setProperty5(data.get("property5"));
            }
            if (data.has("property6")) {
                profile.setProperty6(data.get("property6"));
            }
            if (data.has("property7")) {
                profile.setProperty7(data.get("property7"));
            }
            if (data.has("property8")) {
                profile.setProperty8(data.get("property8"));
            }
            if (data.has("property9")) {
                profile.setProperty9(data.get("property9"));
            }
            if (data.has("property10")) {
                profile.setProperty10(data.get("property10"));
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return profile;
    }

    public static void onRegister(String uid, String data, String invitationCode) {
        TalkingDataSDK.onRegister(uid, toProfile(data), invitationCode);
    }

    public static void onLogin(String uid, String data) {
        TalkingDataSDK.onLogin(uid, toProfile(data));
    }

    public static void onProfileUpdate(String data) {
        TalkingDataSDK.onProfileUpdate(toProfile(data));
    }

    public static void onCreateCard(String uid, String method, String content) {
        TalkingDataSDK.onCreateCard(uid, method, content);
    }

    public static void onFavorite(String category, String content) {
        TalkingDataSDK.onFavorite(category, content);
    }

    public static void onShare(String uid, String content) {
        TalkingDataSDK.onShare(uid, content);
    }

    public static void onPunch(String uid, String punchid) {
        TalkingDataSDK.onPunch(uid, punchid);
    }

    public static void onSearch(String json) {
        try {
            TalkingDataSearch search = TalkingDataSearch.createSearch();
            JSONObject data = new JSONObject(json);
            if (data.has("content")) {
                search.setCategory(data.getString("content"));
            }
            if (data.has("category")) {
                search.setContent(data.getString("category"));
            }
            TalkingDataSDK.onSearch(search);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    public static void onEvent(String event, double value, String json) {
        AppContext context = AppContext.getContext();
        TalkingDataSDK.onEvent(context, event, value, toMap(json));
    }

    public static void setGlobalKV(String key, String value) {
        TalkingDataSDK.setGlobalKV(key, value);
    }

    public static void setGlobalKV(String key, long value) {
        TalkingDataSDK.setGlobalKV(key, value);
    }

    public static void setGlobalKV(String key, double value) {
        TalkingDataSDK.setGlobalKV(key, value);
    }

    public static void removeGlobalKV(String key) {
        TalkingDataSDK.removeGlobalKV(key);
    }
}