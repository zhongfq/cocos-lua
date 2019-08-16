package org.cocos2dx.hellolua;

// import com.tendcloud.tenddata.TCAgent;

import android.util.Log;

import kernel.PluginManager;

public class Application extends android.app.Application {

    private static final String TAG = Application.class.getSimpleName();

    @Override
    public void onCreate() {
        super.onCreate();

        loadPlugin("kernel.plugins.huawei.Huawei");

        PluginManager.init(this);

        // TCAgent.LOG_ON = true;
        // TCAgent.init(this);
        // TCAgent.setReportUncaughtExceptions(false);
    }

    public void loadPlugin(String classname) {
        boolean found = true;
        try {
            Class.forName(classname);
        } catch (ClassNotFoundException e) {
            found = false;
        }
        Log.i(TAG, "[" + (found ? "OK" : "NO") + "] load plugin: " + classname);
    }
}
