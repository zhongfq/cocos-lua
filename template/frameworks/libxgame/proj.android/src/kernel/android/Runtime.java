package kernel.android;

import android.Manifest;
import android.app.AlertDialog;
import android.content.ActivityNotFoundException;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.provider.Settings;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v4.content.FileProvider;
import android.util.Log;
import android.widget.Toast;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.io.Writer;
import java.util.HashMap;
import java.util.List;

public class Runtime {
    private static final String TAG = Runtime.class.getSimpleName();
    private static final int REQUEST_PERMISSION = 0xFF;

    @SuppressWarnings("unused")
    public static String getDeviceInfo() {
        return String.format("%s, %s, %s, %s", Build.DISPLAY,
                Build.VERSION.RELEASE, Build.VERSION.SDK_INT, Build.MODEL);
    }

    @SuppressWarnings("unused")
    public static void installAPK(final String path) {
        final AppContext context = (AppContext) Cocos2dxActivity.getContext();
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
            final AppContext context = (AppContext) Cocos2dxActivity.getContext();
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
            final AppContext context = (AppContext) Cocos2dxActivity.getContext();
            PackageManager pm = context.getPackageManager();
            PackageInfo pi = pm.getPackageInfo(context.getPackageName(),
                    PackageManager.GET_CONFIGURATIONS);
            return String.valueOf(pi.versionCode);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "0";
    }

    @SuppressWarnings({"unused", "SameParameterValue", "WeakerAccess"})
    public static String getMetaData(String name) {
        final Context context = Cocos2dxActivity.getContext().getApplicationContext();
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
        final AppContext context = (AppContext) Cocos2dxActivity.getContext();
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
        AppContext context = (AppContext) Cocos2dxActivity.getContext();
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
        AppContext context = (AppContext) Cocos2dxActivity.getContext();
        return context.getPackageName();
    }

    @SuppressWarnings("unused")
    public static String getStackTrace() {
        Writer result = new StringWriter();
        PrintWriter printWriter = new PrintWriter(result);
        new Throwable().printStackTrace(printWriter);
        return result.toString();
    }

    @SuppressWarnings("unused")
    public static boolean gotoMarket(String market, String packageName) {
        AppContext context = (AppContext) AppContext.getContext();
        try {
            if ("letv".equals(market)) {
                Intent intent = new Intent();
                intent.setClassName("com.letv.app.appstore", "com.letv.app.appstore.appmodule.details.DetailsActivity");
                intent.setAction("com.letv.app.appstore.appdetailactivity");
                intent.putExtra("packageName", packageName);
                context.startActivity(intent);
            } else if ("samsung".equals(market)) {
                Uri uri = Uri.parse("http://www.samsungapps.com/appquery/appDetail.as?appId=" + packageName);
                Intent goToMarket = new Intent();
                goToMarket.setClassName("com.sec.android.app.samsungapps", "com.sec.android.app.samsungapps.Main");
                goToMarket.setData(uri);
                context.startActivity(goToMarket);
            } else {
                Uri uri = Uri.parse("market://details?id=" + packageName);
                Intent intent = new Intent(Intent.ACTION_VIEW, uri);
                context.startActivity(intent);
            }

            return true;
        } catch (Exception e) {
            e.printStackTrace();
        }

        return false;
    }

    @SuppressWarnings("unused")
    public static boolean canOpenURL(String url) {
        AppContext context = (AppContext) AppContext.getContext();
        PackageManager pm = context.getPackageManager();
        Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
        ComponentName cn = intent.resolveActivity(pm);
        return cn != null;
    }

    @SuppressWarnings("unused")
    public static boolean openURL(String url) {
        if (canOpenURL(url)) {
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
                                LuaJavaBridge.invokeOnce(callback, "true");
                            }
                        })
                        .setNegativeButton(cancelLabel, new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                LuaJavaBridge.invokeOnce(callback, "false");
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
        SharedPreferences preferences = context.getSharedPreferences("permission", Context.MODE_PRIVATE);
        return preferences.getInt(permission, PERMISSION_STATUS_NOT_DETERMINED);
    }

    private static void writePermissionStatus(String permission, int status) {
        final AppContext context = (AppContext) AppContext.getContext();
        SharedPreferences preferences = context.getSharedPreferences("permission", Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = preferences.edit();
        editor.putInt(permission, status);
        editor.apply();
    }

    @SuppressWarnings("unused")
    public static int getSDKInt() {
        return Build.VERSION.SDK_INT;
    }

    @SuppressWarnings({"unused", "WeakerAccess"})
    public static void requestPermission(final String permission, final int callback) {
        final AppContext context = (AppContext) AppContext.getContext();
        if (ContextCompat.checkSelfPermission(context, permission) != PackageManager.PERMISSION_GRANTED) {
            int status = readPermissionStatus(permission);
            if (status != PERMISSION_STATUS_NOT_DETERMINED) {
                LuaJavaBridge.invokeOnce(callback, "nil");
            } else {
                context.setActivityPermissionResultCallback(new ActivityPermissionsResultCallback() {
                    @Override
                    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
                        if (requestCode == REQUEST_PERMISSION) {
                            context.setActivityPermissionResultCallback(null);
                            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                                writePermissionStatus(permission, PERMISSION_STATUS_AUTHORIZED);
                                LuaJavaBridge.invokeOnce(callback, "true");
                            } else {
                                writePermissionStatus(permission, PERMISSION_STATUS_DENIED);
                                LuaJavaBridge.invokeOnce(callback, "false");
                            }
                        }
                    }
                });
                ActivityCompat.requestPermissions(context, new String[]{permission}, REQUEST_PERMISSION);
            }
        } else {
            writePermissionStatus(permission, PERMISSION_STATUS_AUTHORIZED);
            LuaJavaBridge.invokeOnce(callback, "true");
        }
    }

    @SuppressWarnings("unused")
    public static void requestExternalStoragePermission(final int callback) {
        requestPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE, callback);
    }

    @SuppressWarnings("unused")
    public static void requestCameraPermission(final int callback) {
        requestPermission(Manifest.permission.CAMERA, callback);
    }

    @SuppressWarnings("unused")
    public static void openPermissionSetting() {
        String name = Build.MANUFACTURER;
        Log.i(TAG, "jumpPermissionPage --- name : " + name);
        switch (name) {
            case "HUAWEI":
                goHuaWeiMainager();
                break;
            case "vivo":
                goVivoMainager();
                break;
            case "OPPO":
                goOppoMainager();
                break;
            case "Coolpad":
                goCoolpadMainager();
                break;
            case "Meizu":
                goMeizuMainager();
                break;
            case "Xiaomi":
                goXiaoMiMainager();
                break;
            case "samsung":
                goSangXinMainager();
                break;
            case "Sony":
                goSonyMainager();
                break;
            case "LG":
                goLGMainager();
                break;
            default:
                goIntentSetting();
                break;
        }
    }

    private static void goLGMainager() {
        final AppContext context = (AppContext) AppContext.getContext();
        try {
            Intent intent = new Intent(context.getPackageName());
            ComponentName comp = new ComponentName("com.android.settings", "com.android.settings.Settings$AccessLockSummaryActivity");
            intent.setComponent(comp);
            context.startActivity(intent);
        } catch (Exception e) {
            Toast.makeText(context, "跳转失败", Toast.LENGTH_LONG).show();
            e.printStackTrace();
            goIntentSetting();
        }
    }

    private static void goSonyMainager() {
        final AppContext context = (AppContext) AppContext.getContext();
        try {
            Intent intent = new Intent(context.getPackageName());
            ComponentName comp = new ComponentName("com.sonymobile.cta", "com.sonymobile.cta.SomcCTAMainActivity");
            intent.setComponent(comp);
            context.startActivity(intent);
        } catch (Exception e) {
            Toast.makeText(context, "跳转失败", Toast.LENGTH_LONG).show();
            e.printStackTrace();
            goIntentSetting();
        }
    }

    private static void goHuaWeiMainager() {
        final AppContext context = (AppContext) AppContext.getContext();
        try {
            Intent intent = new Intent(context.getPackageName());
            intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            ComponentName comp = new ComponentName("com.huawei.systemmanager", "com.huawei.permissionmanager.ui.MainActivity");
            intent.setComponent(comp);
            context.startActivity(intent);
        } catch (Exception e) {
            Toast.makeText(context, "跳转失败", Toast.LENGTH_LONG).show();
            e.printStackTrace();
            goIntentSetting();
        }
    }

    private static String getMiuiVersion() {
        String propName = "ro.miui.ui.version.name";
        String line;
        BufferedReader input = null;
        try {
            Process p = java.lang.Runtime.getRuntime().exec("getprop " + propName);
            input = new BufferedReader(
                    new InputStreamReader(p.getInputStream()), 1024);
            line = input.readLine();
            input.close();
        } catch (IOException ex) {
            ex.printStackTrace();
            return null;
        } finally {
            try {
                if (input != null) {
                    input.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return line;
    }

    private static void goXiaoMiMainager() {
        final AppContext context = (AppContext) AppContext.getContext();
        String rom = getMiuiVersion();
        Intent intent = new Intent();
        if ("V6".equals(rom) || "V7".equals(rom)) {
            intent.setAction("miui.intent.action.APP_PERM_EDITOR");
            intent.setClassName("com.miui.securitycenter", "com.miui.permcenter.permissions.AppPermissionsEditorActivity");
            intent.putExtra("extra_pkgname", context.getPackageName());
            context.startActivity(intent);
        } else if ("V8".equals(rom) || "V9".equals(rom)) {
            intent.setAction("miui.intent.action.APP_PERM_EDITOR");
            intent.setClassName("com.miui.securitycenter", "com.miui.permcenter.permissions.PermissionsEditorActivity");
            intent.putExtra("extra_pkgname", context.getPackageName());
            context.startActivity(intent);
        } else {
            goIntentSetting();
        }
    }

    private static void goMeizuMainager() {
        final AppContext context = (AppContext) AppContext.getContext();
        try {
            Intent intent = new Intent("com.meizu.safe.security.SHOW_APPSEC");
            intent.addCategory(Intent.CATEGORY_DEFAULT);
            intent.putExtra("packageName", context.getPackageName());
            context.startActivity(intent);
        } catch (ActivityNotFoundException localActivityNotFoundException) {
            localActivityNotFoundException.printStackTrace();
            goIntentSetting();
        }
    }

    private static void goSangXinMainager() {
        //三星4.3可以直接跳转
        goIntentSetting();
    }

    private static void goIntentSetting() {
        final AppContext context = (AppContext) AppContext.getContext();
        Intent intent = new Intent(Settings.ACTION_APPLICATION_DETAILS_SETTINGS);
        Uri uri = Uri.fromParts("package", context.getPackageName(), null);
        intent.setData(uri);
        try {
            context.startActivity(intent);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void goOppoMainager() {
        doStartApplicationWithPackageName("com.coloros.safecenter");
    }

    /**
     * doStartApplicationWithPackageName("com.yulong.android.security:remote")
     * 和Intent open = getPackageManager().getLaunchIntentForPackage("com.yulong.android.security:remote");
     * startActivity(open);
     * 本质上没有什么区别，通过Intent open...打开比调用doStartApplicationWithPackageName方法更快，也是android本身提供的方法
     */
    private static void goCoolpadMainager() {
        doStartApplicationWithPackageName("com.yulong.android.security:remote");
      /*  Intent openQQ = getPackageManager().getLaunchIntentForPackage("com.yulong.android.security:remote");
        startActivity(openQQ);*/
    }

    private static void goVivoMainager() {
        doStartApplicationWithPackageName("com.bairenkeji.icaller");
    }

    private static void doStartApplicationWithPackageName(String packagename) {
        // 通过包名获取此APP详细信息，包括Activities、services、versioncode、name等等
        final AppContext context = (AppContext) AppContext.getContext();
        PackageInfo packageinfo = null;
        try {
            packageinfo = context.getPackageManager().getPackageInfo(packagename, 0);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        if (packageinfo == null) {
            return;
        }
        // 创建一个类别为CATEGORY_LAUNCHER的该包名的Intent
        Intent resolveIntent = new Intent(Intent.ACTION_MAIN, null);
        resolveIntent.addCategory(Intent.CATEGORY_LAUNCHER);
        resolveIntent.setPackage(packageinfo.packageName);
        // 通过getPackageManager()的queryIntentActivities方法遍历
        List<ResolveInfo> resolveinfoList = context.getPackageManager()
                .queryIntentActivities(resolveIntent, 0);
        Log.e("PermissionPageManager", "resolveinfoList" + resolveinfoList.size());
        ResolveInfo resolveinfo = resolveinfoList.iterator().next();
        if (resolveinfo != null) {
            // packageName参数2 = 参数 packname
            String packageName = resolveinfo.activityInfo.packageName;
            // 这个就是我们要找的该APP的LAUNCHER的Activity[组织形式：packageName参数2.mainActivityname]
            String className = resolveinfo.activityInfo.name;
            // LAUNCHER Intent
            Intent intent = new Intent(Intent.ACTION_MAIN);
            intent.addCategory(Intent.CATEGORY_LAUNCHER);
            // 设置ComponentName参数1:packageName参数2:MainActivity路径
            ComponentName cn = new ComponentName(packageName, className);
            intent.setComponent(cn);
            try {
                context.startActivity(intent);
            } catch (Exception e) {
                goIntentSetting();
                e.printStackTrace();
            }
        }
    }
}
