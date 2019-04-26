package kernel.android;

import android.app.AlertDialog;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.support.v4.content.FileProvider;
import android.util.Log;

import com.hjq.permissions.OnPermission;
import com.hjq.permissions.XXPermissions;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.io.Writer;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Runtime {
    private static final String TAG = Runtime.class.getSimpleName();

    private static HashMap<String, Boolean> _apis = new HashMap<>();

    @SuppressWarnings("unused")
    public static void registerFeature(String api, boolean enabled) {
        _apis.put(api, enabled);
    }

    @SuppressWarnings({"unused", "ConstantConditions"})
    public static void pullAllFeatures() {
        for (Map.Entry<String, Boolean> entry : _apis.entrySet()) {
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

    @SuppressWarnings({"unused", "SameParameterValue", "WeakerAccess"})
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

    private static String getDirectory(String type) {
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
    public static String getArgs() {
        AppContext context = (AppContext) AppContext.getContext();
        HashMap<String, Object> args = context.getArgs();
        JSONObject info = new JSONObject();
        if (args != null) {
            for (String key : args.keySet()) {
                try {
                    info.put(key, args.get(key));
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }
        }
        return info.toString();
    }

    @SuppressWarnings("unused")
    public static String getPackageName() {
        AppContext context = (AppContext) AppContext.getContext();
        return context.getPackageName();
    }

    @SuppressWarnings("unused")
    public static String getStackTrace() {
        Writer result = new StringWriter();
        PrintWriter printWriter = new PrintWriter(result);
        new Throwable().printStackTrace(printWriter);
        return result.toString();
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
        if (canOpenApp(url)) {
            return openApp(url);
        } else if (canOpenURL(url)) {
            AppContext context = (AppContext) AppContext.getContext();
            Uri uri = Uri.parse(url);
            Intent intent = new Intent(Intent.ACTION_VIEW, uri);
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

    // request permission
    private static final int PERMISSION_STATUS_NOT_DETERMINED = 0;
    private static final int PERMISSION_STATUS_DENIED = 1;
    private static final int PERMISSION_STATUS_AUTHORIZED = 2;

    private static int readPermissionStatus(String permission) {
        final AppContext context = (AppContext) AppContext.getContext();
        SharedPreferences preferences = context.getSharedPreferences("permissions", Context.MODE_PRIVATE);
        return preferences.getInt(permission, PERMISSION_STATUS_NOT_DETERMINED);
    }

    private static void writePermissionStatus(String permission, int status) {
        final AppContext context = (AppContext) AppContext.getContext();
        SharedPreferences preferences = context.getSharedPreferences("permissions", Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = preferences.edit();
        editor.putInt(permission, status);
        editor.apply();
    }

    @SuppressWarnings("unused")
    public static int getPermissionStatus(String permission) {
        final AppContext context = (AppContext) AppContext.getContext();
        if (XXPermissions.isHasPermission(context, permission)) {
            return PERMISSION_STATUS_AUTHORIZED;
        } else {
            return readPermissionStatus(permission);
        }
    }

    @SuppressWarnings({"unused", "WeakerAccess"})
    public static void requestPermission(final String permission, final int callback) {
        final AppContext context = (AppContext) AppContext.getContext();
        if (XXPermissions.isHasPermission(context, permission)) {
            writePermissionStatus(permission, PERMISSION_STATUS_AUTHORIZED);
            LuaJ.invokeOnce(callback, "GRANTED");
        } else {
            XXPermissions.with(context)
                    .permission(permission)
                    .request(new OnPermission() {
                        @Override
                        public void hasPermission(List<String> granted, boolean isAll) {
                            writePermissionStatus(permission, PERMISSION_STATUS_AUTHORIZED);
                            LuaJ.invokeOnce(callback, "GRANTED");
                        }

                        @Override
                        public void noPermission(List<String> denied, boolean quick) {
                            writePermissionStatus(permission, PERMISSION_STATUS_DENIED);
                            LuaJ.invokeOnce(callback, "DENIED");
                        }
                    });
        }
    }

    @SuppressWarnings("unused")
    public static void openPermissionSettings() {
        final AppContext context = (AppContext) AppContext.getContext();
        XXPermissions.gotoPermissionSettings(context);
    }
}
