package kernel;

import android.app.AlertDialog;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.net.ConnectivityManager;
import android.net.Network;
import android.net.NetworkInfo;
import android.net.NetworkRequest;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.LocaleList;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v4.content.FileProvider;
import android.util.Log;
import android.view.WindowManager;

import org.cocos2dx.lib.Cocos2dxActivity;

import java.io.File;
import java.io.IOException;
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

    private static final String TAG = AppContext.class.getName();
    private static HashMap<String, Boolean> mAPIs = new HashMap<>();

    private ActivityResultCallback mResultCallback;
    private PermissionsResultCallback mPermissionsResultCallback;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        super.setEnableVirtualButton(false);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            WindowManager.LayoutParams lp = getWindow().getAttributes();
            lp.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            getWindow().setAttributes(lp);
        }

        ConnectivityManager connectivityManager = (ConnectivityManager) getSystemService(Context.CONNECTIVITY_SERVICE);
        connectivityManager.requestNetwork(new NetworkRequest.Builder().build(),
                new ConnectivityManager.NetworkCallback() {
                    @Override
                    public void onAvailable(Network network) {
                        super.onAvailable(network);
                        runOnGLThread(new Runnable() {
                            @Override
                            public void run() {
                                final String status = AppContext.getNetworkStatus();
                                Log.i(TAG, status + " network available");
                                runOnGLThread(new Runnable() {
                                    @Override
                                    public void run() {
                                        LuaJ.dispatchEvent("networkChange", status);
                                    }
                                });
                            }
                        });
                    }

                    @Override
                    public void onLost(Network network){
                        super.onLost(network);
                        Log.i(TAG, "network is lost");
                        runOnGLThread(new Runnable() {
                            @Override
                            public void run() {
                                LuaJ.dispatchEvent("networkChange", "NONE");
                            }
                        });
                    }
                });
    }

    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
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
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        if (grantResults.length > 0 && permissions.length > 0) {
            mPermissionsResultCallback.onRequestPermissionsResult(permissions[0], grantResults[0]);
        } else {
            mPermissionsResultCallback.onRequestPermissionsResult(null, -2);
        }
    }

    //
    // api for lua
    //
    @SuppressWarnings("unused")
    public static void registerFeature(String api, boolean enabled) {
        api += ".android";
        mAPIs.put(api, enabled);
    }

    @SuppressWarnings({"unused"})
    public static void pullAllFeatures() {
        for (Map.Entry<String, Boolean> entry : mAPIs.entrySet()) {
            LuaJ.registerFeature(entry.getKey(), entry.getValue());
        }
    }

    @SuppressWarnings("unused")
    public static String getDeviceInfo() {
        return String.format("%s, %s, %s, %s", Build.DISPLAY,
                Build.VERSION.RELEASE, Build.VERSION.SDK_INT, Build.MODEL);
    }

    @SuppressWarnings("unused")
    public static void installAPK(final String path) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Log.i(TAG, "install: " + path);
                try {
                    String[] args = {"chmod", "604", path};
                    java.lang.Runtime.getRuntime().exec(args);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                try {
                    if (Build.VERSION.SDK_INT >= 24) {
                        File file = new File(path);
                        Intent intent = new Intent(Intent.ACTION_VIEW);
                        intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                        intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
                        Uri contentUri = FileProvider.getUriForFile(context, context.getPackageName() + ".fileprovider", file);
                        Log.i(TAG, "install uri: " + contentUri.toString());
                        intent.setDataAndType(contentUri, "application/vnd.android.package-archive");
                        context.startActivity(intent);
                    } else {
                        Intent intent = new Intent(Intent.ACTION_VIEW);
                        Uri uri = Uri.fromFile(new File(path));
                        intent.setDataAndType(uri, "application/vnd.android.package-archive");
                        intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                        context.startActivity(intent);
                    }
                } catch (Throwable e) {
                    e.printStackTrace();
                }
            }
        });
    }

    public static String getNetworkStatus() {
        ConnectivityManager cm = (ConnectivityManager) AppContext.getContext().getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo info = cm.getActiveNetworkInfo();
        if (info != null && info.isConnected()) {
            if (info.getType() == ConnectivityManager.TYPE_WIFI) {
                return "WIFI";
            } else {
                return "MOBILE";
            }
        } else {
            return "NONE";
        }
    }

    @SuppressWarnings("unused")
    public static String getVersion() {
        try {
            final AppContext context = (AppContext) AppContext.getContext();
            PackageManager pm = context.getPackageManager();
            PackageInfo pi = pm.getPackageInfo(context.getPackageName(),
                    PackageManager.GET_CONFIGURATIONS);
            return pi.versionName;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "0.0.0";
    }

    @SuppressWarnings("unused")
    public static String getVersionCode() {
        try {
            final AppContext context = (AppContext) AppContext.getContext();
            PackageManager pm = context.getPackageManager();
            PackageInfo pi = pm.getPackageInfo(context.getPackageName(),
                    PackageManager.GET_CONFIGURATIONS);
            return String.valueOf(pi.versionCode);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "0";
    }

    @SuppressWarnings("unused")
    public static int getSDKInt() {
        return Build.VERSION.SDK_INT;
    }

    @SuppressWarnings("unused")
    public static String getMetaData(String name) {
        final Context context = AppContext.getContext().getApplicationContext();
        try {
            ApplicationInfo ai = context.getPackageManager().getApplicationInfo(context.getPackageName(), PackageManager.GET_META_DATA);
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
    public static String getChannel() {
        return getMetaData("CHANNEL");
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
        final AppContext context = (AppContext) AppContext.getContext();
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
    public static String getPackage() {
        AppContext context = (AppContext) AppContext.getContext();
        return context.getPackageName();
    }

    @SuppressWarnings("unused")
    public static String getLanguage() {
        Locale locale;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
            locale = LocaleList.getDefault().get(0);
        } else {
            locale = Locale.getDefault();
        }

        return locale.getLanguage() + "-" + locale.getCountry();
    }

    private static boolean canOpenApp(String packageName) {
        AppContext context = (AppContext) AppContext.getContext();
        final PackageManager packageManager = context.getPackageManager();
        List<PackageInfo> info = packageManager.getInstalledPackages(0);
        for (int i = 0; i < info.size(); i++) {
            if (info.get(i).packageName.equalsIgnoreCase(packageName))
                return true;
        }
        return false;

    }

    private static boolean openApp(String packageName) {
        AppContext context = (AppContext) AppContext.getContext();
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
            AppContext context = (AppContext) AppContext.getContext();
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
            final AppContext context = (AppContext) AppContext.getContext();
            Intent localIntent = new Intent();
            localIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            localIntent.setAction("android.settings.APPLICATION_DETAILS_SETTINGS");
            localIntent.setData(Uri.fromParts("package", context.getPackageName(), null));
            context.startActivity(localIntent);
            return true;
        } else if (canOpenApp(url)) {
            return openApp(url);
        } else if (canOpenURL(url)) {
            AppContext context = (AppContext) AppContext.getContext();
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
    public static void alert(final String title, final String content, final String confirmLabel, final String cancelLabel, final int callback) {
        final AppContext context = (AppContext) AppContext.getContext();
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                new AlertDialog.Builder(context)
                        .setTitle(title)
                        .setMessage(content)
                        .setPositiveButton(confirmLabel, new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                LuaJ.invokeOnce(callback, "true");
                            }
                        })
                        .setNegativeButton(cancelLabel, new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                LuaJ.invokeOnce(callback, "false");
                            }
                        })
                        .setCancelable(false)
                        .show();
            }
        });
    }

    //
    // request permission
    //
    private enum PermissionStatus {
        NOT_DETERMINED,
        RESTRICTED,
        DENIED,
        AUTHORIZED,
    }

    @SuppressWarnings("unused")
    public static String getPermissionStatus(String permission) {
        final AppContext context = (AppContext) AppContext.getContext();
        if (ContextCompat.checkSelfPermission(context, permission) == PackageManager.PERMISSION_GRANTED) {
            return PermissionStatus.AUTHORIZED.name();
        } else {
            SharedPreferences preferences = context.getSharedPreferences("permissions", Context.MODE_PRIVATE);
            String status = preferences.getString(permission, PermissionStatus.NOT_DETERMINED.name());
            if (PermissionStatus.NOT_DETERMINED.name().equals(status)) {
                return PermissionStatus.NOT_DETERMINED.name();
            } else {
                return PermissionStatus.DENIED.name();
            }
        }
    }

    @SuppressWarnings({"unused"})
    public static void requestPermission(final String permission, final int callback) {
        final AppContext context = (AppContext) AppContext.getContext();
        SharedPreferences preferences = context.getSharedPreferences("permissions", Context.MODE_PRIVATE);
        final SharedPreferences.Editor editor = preferences.edit();
        if (ContextCompat.checkSelfPermission(context, permission) == PackageManager.PERMISSION_GRANTED) {
            editor.putString(permission, PermissionStatus.AUTHORIZED.name());
            editor.apply();
            LuaJ.invokeOnce(callback, PermissionStatus.AUTHORIZED.name());
        } else {
            context.mPermissionsResultCallback = new PermissionsResultCallback() {
                @Override
                public void onRequestPermissionsResult(String p, int result) {
                    PermissionStatus status;
                    if (result == PackageManager.PERMISSION_GRANTED) {
                        status = PermissionStatus.AUTHORIZED;
                    } else if (result == PackageManager.PERMISSION_DENIED) {
                        status = PermissionStatus.DENIED;
                    } else {
                        // interrupted by other action
                        status = PermissionStatus.NOT_DETERMINED;
                    }
                    editor.putString(permission, status.name());
                    editor.apply();
                    LuaJ.invokeOnce(callback, status.name());
                }
            };
            ActivityCompat.requestPermissions(context, new String[]{permission}, 0);
        }
    }
}