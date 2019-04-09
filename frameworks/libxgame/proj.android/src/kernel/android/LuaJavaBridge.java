package kernel.android;

public class LuaJavaBridge {
    public static native void unref(int func);
    public static native void invoke(int func, String value);

    public static void invokeOnce(int func, String value)
    {
        LuaJavaBridge.invoke(func, value);
        LuaJavaBridge.unref(func);
    }
}
