package cclua;

import android.util.Log;

public class App extends android.app.Application {

    private static final String TAG = App.class.getSimpleName();

    @Override
    public void onCreate() {
        super.onCreate();

		loadPlugin("cclua.plugin.wechat.WeChat");
        loadPlugin("cclua.plugin.huawei.Huawei");
        loadPlugin("cclua.plugin.vivo.Vivo");
        loadPlugin("cclua.plugin.oppo.Oppo");
        loadPlugin("cclua.plugin.alipay.Alipay");
        loadPlugin("cclua.plugin.talkingdata.TalkingData");
        loadPlugin("cclua.plugin.jiguang.JPush");
        loadPlugin("cclua.plugin.jiguang.JAuth");
        loadPlugin("cclua.plugin.jiguang.JAnalytics");

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
