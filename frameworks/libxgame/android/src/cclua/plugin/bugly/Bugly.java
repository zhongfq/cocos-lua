package cclua.plugin.bugly;

import com.tencent.bugly.crashreport.BuglyLog;
import com.tencent.bugly.crashreport.CrashReport;
import com.tencent.bugly.crashreport.inner.InnerApi;

import cclua.AppContext;

@SuppressWarnings("unused")
public class Bugly {
    private static String sChannel;
    private static String sVersion;

    public static void init(String appid, boolean debug) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            CrashReport.UserStrategy strategy = new CrashReport.UserStrategy(context);
            strategy.setAppChannel(sChannel);
            strategy.setAppVersion(sVersion);
            strategy.setBuglyLogUpload(true);
            CrashReport.initCrashReport(AppContext.getContext(), appid, true, strategy);
        });
    }

    public static void setTag(int tag) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> CrashReport.setUserSceneTag(context, tag));
    }

    public static void setUserValue(String key, String value) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> CrashReport.putUserData(context, key, value));
    }

    public static void setUid(String uid) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> CrashReport.setUserId(context, uid));
    }

    public static void reportException(int category, String type, String msg, String traceback,
                                       boolean quit) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> InnerApi.postCocos2dxCrashAsync(category, "CustomException",
                msg, traceback));
    }

    public static void setChannel(String channel) {
        sChannel = channel;
    }

    public static void setVersion(String version) {
        sVersion = version;
    }

    public static void log(int level, String tag, String msg) {
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
