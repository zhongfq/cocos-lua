package kernel.plugins.bugly;

import android.app.Activity;
import com.tencent.bugly.crashreport.BuglyLog;
import com.tencent.bugly.crashreport.CrashReport;
import com.tencent.bugly.crashreport.inner.InnerApi;

import kernel.AppContext;

@SuppressWarnings("unused")
public class Bugly {
    private static String _channel;
    private static String _version;

    public static void initCrashReport(String appid, boolean debug) {
        CrashReport.UserStrategy strategy = new CrashReport.UserStrategy(AppContext.getContext());
        strategy.setAppChannel(_channel);
        strategy.setAppVersion(_version);
        CrashReport.initCrashReport(AppContext.getContext(), appid, debug, strategy);
    }

    public static void setTag(int tag) {
        CrashReport.setUserSceneTag(AppContext.getContext(), tag);
    }

    public static void addUserValue(String key, String value) {
        CrashReport.putUserData(AppContext.getContext(), key, value);
    }

    public static void removeUserValue(String key) {
        CrashReport.removeUserData(AppContext.getContext(), key);
    }

    public static void setUserId(String uid) {
        CrashReport.setUserId(AppContext.getContext(), uid);
    }

    public static void reportException(int category, String type, String msg, String traceback, boolean quit) {
        InnerApi.postCocos2dxCrashAsync(category, "CustomException", msg, traceback);
    }

    public static void setAppChannel(String channel) {
        _channel = channel;
    }

    public static void setAppVersion(String version) {
        _version = version;
    }

    public static void log(final int level, final String tag, final String msg) {
        ((Activity)AppContext.getContext()).runOnUiThread(new Runnable() {
            @Override
            public void run() {
                switch(level) {
                    case 0:
                        BuglyLog.v(tag, msg);
                        break;
                    case 1:
                        BuglyLog.d(tag, msg);
                        break;
                    case 2:
                        BuglyLog.i(tag, msg);
                        break;
                    case 3:
                        BuglyLog.w(tag, msg);
                        break;
                    case 4:
                        BuglyLog.e(tag, msg);
                        break;
                }
            }
        });
    }
}
