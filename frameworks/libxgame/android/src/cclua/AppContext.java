package cclua;

import static android.view.WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;

import android.app.AlertDialog;
import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.net.ConnectivityManager;
import android.net.Network;
import android.net.NetworkCapabilities;
import android.net.NetworkRequest;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.LocaleList;
import android.util.Log;
import android.view.Display;
import android.view.WindowManager;

import androidx.annotation.NonNull;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.core.content.FileProvider;

import org.cocos2dx.lib.Cocos2dxActivity;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;

public class AppContext extends Cocos2dxActivity {
    public interface ActivityResultCallback {
        void onActivityResult(int requestCode, int resultCode, Intent data);
    }

    public interface PermissionsResultCallback {
        void onRequestPermissionsResult(String permission, int result);
    }

    public interface Plugin {
        void onLoad(AppContext context);
    }

    private static final String TAG = AppContext.class.getName();
    private static final ArrayList<Plugin> sPlugins = new ArrayList<>();
    private static final HashMap<String, Boolean> sAPIs = new HashMap<>();
    private static AppContext sContext;
    private ActivityResultCallback mResultCallback;
    private PermissionsResultCallback mPermissionsResultCallback;

    public AppContext() {
        sContext = this;
    }

    public static AppContext getContext() {
        return sContext;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        super.setEnableVirtualButton(false);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            WindowManager.LayoutParams lp = getWindow().getAttributes();
            lp.layoutInDisplayCutoutMode = LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            getWindow().setAttributes(lp);
        }

        ConnectivityManager connectivityManager = getConnectivityService();
        connectivityManager.requestNetwork(new NetworkRequest.Builder().build(),
                new ConnectivityManager.NetworkCallback() {
                    @Override
                    public void onAvailable(Network network) {
                        super.onAvailable(network);
                        final String status = AppContext.getNetworkStatus();
                        LuaJ.dispatchEvent("networkChange", status);
                    }

                    @Override
                    public void onLost(Network network) {
                        super.onLost(network);
                        LuaJ.dispatchEvent("networkChange", "NONE");
                    }
                });
    }

    @SuppressWarnings("unused")
    public void setActivityResultCallback(ActivityResultCallback callback) {
        mResultCallback = callback;
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (mResultCallback != null) {
            mResultCallback.onActivityResult(requestCode, resultCode, data);
            mResultCallback = null;
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions,
                                           @NonNull int[] grantResults) {
        if (grantResults.length > 0 && permissions.length > 0) {
            mPermissionsResultCallback.onRequestPermissionsResult(permissions[0], grantResults[0]);
        } else {
            mPermissionsResultCallback.onRequestPermissionsResult(null, -2);
        }
    }

    @Override
    public void init() {
        loadPlugin();
        super.init();
    }

    public static void registerPlugin(Plugin plugin) {
        sPlugins.add(plugin);
    }

    private void loadPlugin() {
        try {
            ApplicationInfo ai = getPackageManager().getApplicationInfo(getPackageName(),
                    PackageManager.GET_META_DATA);
            for (String name : ai.metaData.keySet()) {
                if (name.startsWith("cclua.plugin.")) {
                    boolean found = true;
                    try {
                        Class.forName(name);
                    } catch (ClassNotFoundException e) {
                        found = false;
                    }
                    Log.i(TAG, "[" + (found ? "OK" : "NO") + "] load plugin: " + name);
                }
            }
            for (Plugin plugin : sPlugins) {
                plugin.onLoad(AppContext.getContext());
            }
        } catch (Throwable ignored) {
        }
    }

    //
    // api for lua
    //
    @SuppressWarnings("unused")
    public static void registerFeature(String api, boolean enabled) {
        api += ".android";
        sAPIs.put(api, enabled);
    }

    @SuppressWarnings({"unused"})
    public static void pullAllFeatures() {
        for (Map.Entry<String, Boolean> entry : sAPIs.entrySet()) {
            LuaJ.registerFeature(entry.getKey(), entry.getValue());
        }
    }

    @SuppressWarnings("unused")
    public static int getMaxFrameRate() {
        final AppContext context = AppContext.getContext();
        Display display = context.getWindowManager().getDefaultDisplay();
        return (int) display.getRefreshRate();
    }

    @SuppressWarnings("unused")
    public static void installAPK(final String path) {
        final AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            Log.i(TAG, "install: " + path);
            try {
                String[] args = {"chmod", "604", path};
                Runtime.getRuntime().exec(args);
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                File file = new File(path);
                Intent intent = new Intent(Intent.ACTION_VIEW);
                intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
                Uri contentUri = FileProvider.getUriForFile(context,
                        context.getPackageName() + ".fileprovider", file);
                Log.i(TAG, "install uri: " + contentUri.toString());
                intent.setDataAndType(contentUri, "application/vnd.android.package-archive");
                context.startActivity(intent);
            } catch (Throwable e) {
                e.printStackTrace();
            }
        });
    }

    private static ConnectivityManager getConnectivityService() {
        Object service = AppContext.getContext().getSystemService(Context.CONNECTIVITY_SERVICE);
        return (ConnectivityManager) service;
    }

    private static ClipboardManager getClipboardService() {
        Object service = AppContext.getContext().getSystemService(Context.CLIPBOARD_SERVICE);
        return (ClipboardManager) service;
    }

    public static String getNetworkStatus() {
        ConnectivityManager service = getConnectivityService();
        Network nw = service.getActiveNetwork();
        NetworkCapabilities actNw = nw != null ? service.getNetworkCapabilities(nw) : null;
        if (actNw != null) {
            if (actNw.hasTransport(NetworkCapabilities.TRANSPORT_WIFI)) {
                return "WIFI";
            } else if (actNw.hasTransport(NetworkCapabilities.TRANSPORT_CELLULAR)) {
                return "MOBILE";
            }
        }
        return "NONE";
    }

    public static String getPaste() {
        ClipboardManager service = getClipboardService();
        ClipData clipData = service.getPrimaryClip();
        if (clipData != null && clipData.getItemCount() > 0) {
            return String.valueOf(clipData.getItemAt(0).getText());
        } else {
            return "";
        }
    }

    public static void setPaste(String data) {
        ClipboardManager service = getClipboardService();
        ClipData clipData = ClipData.newPlainText("cocos", data);
        service.setPrimaryClip(clipData);
    }

    @SuppressWarnings("unused")
    public static int getSDKInt() {
        return Build.VERSION.SDK_INT;
    }

    @SuppressWarnings("unused")
    public static String getMetaData(String name) {
        final Context context = AppContext.getContext().getApplicationContext();
        try {
            ApplicationInfo ai = context.getPackageManager().getApplicationInfo(
                    context.getPackageName(), PackageManager.GET_META_DATA);
            Bundle bundle = ai.metaData;
            Object value = bundle.get(name);
            if (value != null) {
                return value.toString();
            } else {
                return "";
            }
        } catch (Throwable e) {
            return "";
        }
    }

    @SuppressWarnings("unused")
    public static String getDocumentDirectory() {
        return getDirectory("documents");
    }

    @SuppressWarnings("unused")
    public static String getCacheDirectory() {
        return getDirectory("cache");
    }

    @SuppressWarnings("unused")
    public static String getTmpDirectory() {
        return getDirectory("tmp");
    }

    @SuppressWarnings("unused")
    public static String getSDCardDirectory() {
        return Environment.getExternalStorageDirectory().getAbsolutePath();
    }

    public static String getDirectory(String type) {
        final AppContext context = AppContext.getContext();
        String path = context.getFilesDir().getAbsolutePath();

        if ("documents".equals(type)) {
            path = context.getFilesDir().getAbsolutePath() + "/Documents";
        } else if ("cache".equals(type) || "tmp".equals(type)) {
            path = context.getCacheDir().getAbsolutePath();
        } else if ("external.document".equals(type)) {
            File file = context.getExternalFilesDir(null);
            if (file != null) {
                path = file.getAbsolutePath() + "/Documents";
            }
        } else if ("external.cache".equals(type) || "external.tmp".equals(type)) {
            File file = context.getExternalCacheDir();
            if (file != null) {
                path = file.getAbsolutePath();
            }
        }

        return path;
    }

    @SuppressWarnings("unused")
    public static String getAppInfo(String kind) {
        AppContext context = AppContext.getContext();
        try {
            if ("packageName".equals(kind)) {
                return context.getPackageName();
            }
            if ("appName".equals(kind)) {
                PackageManager pm = context.getPackageManager();
                ApplicationInfo appInfo = pm.getApplicationInfo(context.getPackageName(),
                        PackageManager.GET_META_DATA);
                return appInfo.loadLabel(pm).toString();
            }
            if ("appVersion".equals(kind)) {
                PackageManager pm = context.getPackageManager();
                PackageInfo pi = pm.getPackageInfo(context.getPackageName(),
                        PackageManager.GET_CONFIGURATIONS);
                return pi.versionName;
            }
            if ("appBuild".equals(kind)) {
                PackageManager pm = context.getPackageManager();
                PackageInfo pi = pm.getPackageInfo(context.getPackageName(),
                        PackageManager.GET_CONFIGURATIONS);
                return String.valueOf(pi.versionCode);
            }
            if ("channel".equals(kind)) {
                return getMetaData("cclua.channel");
            }
            if ("language".equals(kind)) {
                Locale locale = LocaleList.getDefault().get(0);
                return locale.getLanguage() + "-" + locale.getCountry();
            }
            if ("deviceInfo".equals(kind)) {
                return String.format("%s, %s, %s, %s", Build.DISPLAY,
                        Build.VERSION.RELEASE, Build.VERSION.SDK_INT, Build.MODEL);
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        return "";
    }

    private static boolean canOpenApp(String packageName) {
        AppContext context = AppContext.getContext();
        final PackageManager packageManager = context.getPackageManager();
        List<PackageInfo> info = packageManager.getInstalledPackages(0);
        for (int i = 0; i < info.size(); i++) {
            if (info.get(i).packageName.equalsIgnoreCase(packageName))
                return true;
        }
        return false;
    }

    private static boolean openApp(String packageName) {
        AppContext context = AppContext.getContext();
        Intent intent = context.getPackageManager().getLaunchIntentForPackage(packageName);
        if (intent != null) {
            intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            context.startActivity(intent);
            return true;
        } else {
            return false;
        }
    }

    @SuppressWarnings("unused")
    public static boolean canOpenURL(String url) {
        if (!canOpenApp(url)) {
            AppContext context = AppContext.getContext();
            PackageManager pm = context.getPackageManager();
            Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
            ComponentName cn = intent.resolveActivity(pm);
            return cn != null;
        } else {
            return true;
        }
    }

    @SuppressWarnings("unused")
    public static boolean openURL(String url) {
        if (url.startsWith("app-settings")) {
            final AppContext context = AppContext.getContext();
            Intent intent = new Intent();
            intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            intent.setAction("android.settings.APPLICATION_DETAILS_SETTINGS");
            intent.setData(Uri.fromParts("package", context.getPackageName(), null));
            context.startActivity(intent);
            return true;
        } else if (canOpenApp(url)) {
            return openApp(url);
        } else if (canOpenURL(url)) {
            AppContext context = AppContext.getContext();
            Uri uri = Uri.parse(url);
            Intent intent = new Intent(Intent.ACTION_VIEW, uri);
            if (uri.getQueryParameter("packageName") != null) {
                intent.setPackage(uri.getQueryParameter("packageName"));
            }
            context.startActivity(intent);
            return true;
        } else {
            return false;
        }
    }

    @SuppressWarnings("unused")
    public static void alert(String title, String content, String confirmLabel, String cancelLabel,
                             long callback) {
        final AppContext context = AppContext.getContext();
        context.runOnUiThread(() ->
                new AlertDialog.Builder(context)
                        .setTitle(title)
                        .setMessage(content)
                        .setPositiveButton(confirmLabel, (dialogInterface, i) ->
                                LuaJ.invokeOnce(callback, "true"))
                        .setNegativeButton(cancelLabel, (dialogInterface, i) ->
                                LuaJ.invokeOnce(callback, "false"))
                        .setCancelable(false)
                        .show()
        );
    }

    //
    // request permission
    //
    static class Permission {
        static final String NOT_DETERMINED = "NOT_DETERMINED";
        @SuppressWarnings("unused")
        static final String RESTRICTED = "RESTRICTED";
        static final String DENIED = "DENIED";
        static final String AUTHORIZED = "AUTHORIZED";
    }

    @SuppressWarnings("unused")
    public static String getPermission(String permission) {
        AppContext context = AppContext.getContext();
        if (ContextCompat.checkSelfPermission(context, permission) == PackageManager.PERMISSION_GRANTED) {
            return Permission.AUTHORIZED;
        } else {
            SharedPreferences preferences = context.getSharedPreferences("permissions", Context.MODE_PRIVATE);
            String status = preferences.getString(permission, Permission.NOT_DETERMINED);
            if (Permission.NOT_DETERMINED.equals(status)) {
                return Permission.NOT_DETERMINED;
            } else {
                return Permission.DENIED;
            }
        }
    }

    @SuppressWarnings({"unused"})
    public static void requestPermission(String permission, long callback) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            SharedPreferences preferences = context.getSharedPreferences("permissions", Context.MODE_PRIVATE);
            final SharedPreferences.Editor editor = preferences.edit();
            if (ContextCompat.checkSelfPermission(context, permission) == PackageManager.PERMISSION_GRANTED) {
                editor.putString(permission, Permission.AUTHORIZED);
                editor.apply();
                LuaJ.invokeOnce(callback, Permission.AUTHORIZED);
            } else {
                context.mPermissionsResultCallback = (p, result) -> {
                    String status;
                    if (result == PackageManager.PERMISSION_GRANTED) {
                        status = Permission.AUTHORIZED;
                    } else if (result == PackageManager.PERMISSION_DENIED) {
                        status = Permission.DENIED;
                    } else {
                        // interrupted by other action
                        status = Permission.NOT_DETERMINED;
                    }
                    editor.putString(permission, status);
                    editor.apply();
                    LuaJ.invokeOnce(callback, status);
                };
                ActivityCompat.requestPermissions(context, new String[]{permission}, 0);
            }
        });
    }
}