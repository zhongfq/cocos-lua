package kernel;

public class LuaJ {
    private static native void call(int func, String value, boolean once);

    public static native void registerFeature(String api, boolean enabled);
    public static native void dispatchEvent(String event, String args);

    public static void invokeOnce(final int func, final String value) {
        AppContext context = (AppContext) AppContext.getContext();
        context.runOnGLThread(new Runnable() {
            @Override
            public void run() {
                LuaJ.call(func, value, true);
            }
        });
    }

    public static void invoke(final int func, final String value)
    {
        AppContext context = (AppContext) AppContext.getContext();
        context.runOnGLThread(new Runnable() {
            @Override
            public void run() {
                LuaJ.call(func, value, false);
            }
        });
    }
}
