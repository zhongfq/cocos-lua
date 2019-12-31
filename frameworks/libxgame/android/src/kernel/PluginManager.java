package kernel;

import android.app.Activity;
import android.app.Application;

import java.util.ArrayList;

public class PluginManager {
    public interface Handler {
        void onInit(Application app);
        void onStart(Activity context);
    }

    private static ArrayList<Handler> _plugins = new ArrayList<>();

    public static void registerPlugin(Handler handler) {
        _plugins.add(handler);
    }

    public static void init(Application app) {
        for (Handler driver : _plugins) {
            driver.onInit(app);
        }
    }

    public static void start(Activity context) {
        for (Handler driver : _plugins) {
            driver.onStart(context);
        }
    }
}
