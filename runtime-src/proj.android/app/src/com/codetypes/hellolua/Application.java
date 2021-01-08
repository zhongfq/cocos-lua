package com.codetypes.hellolua;

import android.util.Log;

import kernel.PluginManager;

public class Application extends android.app.Application {

    private static final String TAG = Application.class.getSimpleName();

    @Override
    public void onCreate() {
        super.onCreate();

        loadPlugin("kernel.plugin.wechat.WeChat");
        loadPlugin("kernel.plugin.huawei.Huawei");
        loadPlugin("kernel.plugin.vivo.Vivo");
        loadPlugin("kernel.plugin.oppo.Oppo");
        loadPlugin("kernel.plugin.alipay.Alipay");
        loadPlugin("kernel.plugin.talkingdata.TalkingData");

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
