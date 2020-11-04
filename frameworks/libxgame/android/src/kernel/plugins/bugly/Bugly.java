package kernel.plugins.bugly;

import android.app.Activity;
import android.util.Log;

import com.tencent.bugly.crashreport.BuglyLog;
import com.tencent.bugly.crashreport.CrashReport;
import com.tencent.bugly.crashreport.inner.InnerApi;

import kernel.AppContext;

@SuppressWarnings("unused")
public class Bugly {
    private static String _channel;
    private static String _version;

    public static void init(String appid, boolean debug) {
        CrashReport.UserStrategy strategy = new CrashReport.UserStrategy(AppContext.getContext());
        strategy.setAppChannel(_channel);
        strategy.setAppVersion(_version);
        strategy.setBuglyLogUpload(true);
        CrashReport.initCrashReport(AppContext.getContext(), appid, true, strategy);
    }

    public static void setTag(int tag) {
        CrashReport.setUserSceneTag(AppContext.getContext(), tag);
    }

    public static void setUserValue(String key, String value) {
        CrashReport.putUserData(AppContext.getContext(), key, value);
    }

    public static void setUid(String uid) {
        CrashReport.setUserId(AppContext.getContext(), uid);
    }

    public static void reportException(int category, String type, String msg, String traceback, boolean quit) {
        InnerApi.postCocos2dxCrashAsync(category, "CustomException", msg, traceback);
    }

    public static void setChannel(String channel) {
        _channel = channel;
    }

    public static void setVersion(String version) {
        _version = version;
    }

    public static void log(final int level, final String tag, final String msg) {
        // {Off = 0, Error = 1, Warning = 2, Info = 3, Debug = 4, Verbose = 5}
        switch(level) {
            case 1:
                BuglyLog.e(tag, msg);
                break;
            case 2:
                BuglyLog.w(tag, msg);
                break;
            case 3:
                BuglyLog.i(tag, msg);
                break;
            case 4:
                BuglyLog.d(tag, msg);
                break;
            case 5:
                BuglyLog.v(tag, msg);
                break;
        }
    }
}
