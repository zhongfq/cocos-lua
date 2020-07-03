package com.codetypes.hellolua;

import android.util.Log;

import kernel.PluginManager;

public class Application extends android.app.Application {

    private static final String TAG = Application.class.getSimpleName();

    @Override
    public void onCreate() {
        super.onCreate();

        loadPlugin("kernel.plugins.wechat.WeChat");
        loadPlugin("kernel.plugins.huawei.Huawei");
        loadPlugin("kernel.plugins.vivo.Vivo");
        loadPlugin("kernel.plugins.oppo.Oppo");
        loadPlugin("kernel.plugins.alipay.Alipay");
        loadPlugin("kernel.plugins.talkingdata.TalkingData");

        PluginManager.init(this);
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
