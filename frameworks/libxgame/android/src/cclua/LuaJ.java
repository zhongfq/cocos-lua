package cclua;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Map;

public class LuaJ {
    private static native void call(long func, String event, String data, boolean once);

    public static native void registerFeature(String api, boolean enabled);

    public static native void dispatchEvent(String event, String args);

    private static String toJSONString(HashMap<String, Object> args) {
        JSONObject info = new JSONObject();
        for (Map.Entry<String, Object> entry : args.entrySet()) {
            String key = entry.getKey();
            Object value = entry.getValue();
            try {
                info.put(key, value);
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        return info.toString();
    }

    private static final HashMap<String, Object> NONE_VALUE = new HashMap<>();

    public static void invokeOnce(long func, String event, HashMap<String, Object> data) {
        LuaJ.call(func, event, toJSONString(data), true);
    }

    public static void invokeOnce(long func, String event) {
        LuaJ.invokeOnce(func, event, NONE_VALUE);
    }

    public static void invoke(long func, String event, HashMap<String, Object> value) {
        LuaJ.call(func, event, toJSONString(value), false);
    }

    public static void invoke(long func, String status) {
        LuaJ.invoke(func, status, NONE_VALUE);
    }
}
