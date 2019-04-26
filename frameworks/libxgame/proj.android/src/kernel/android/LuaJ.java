package kernel.android;

public class LuaJ {
    public static native void unref(int func);

    public static native void invoke(int func, String value);

    public static native void registerFeature(String api, boolean enabled);

    public static void invokeOnce(int func, String value) {
        LuaJ.invoke(func, value);
        LuaJ.unref(func);
    }
}
