package org.cocos2dx.hellolua;

// import com.tendcloud.tenddata.TCAgent;

public class Application extends android.app.Application {
    private static Application sApplication;

    @Override
    public void onCreate() {
        super.onCreate();

        sApplication = this;

        // TCAgent.LOG_ON = true;
        // TCAgent.init(this);
        // TCAgent.setReportUncaughtExceptions(false);
    }

    public static Application getContext() {
        return sApplication;
    }
}
