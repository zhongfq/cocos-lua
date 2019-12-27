package kernel.plugins.huawei;

import android.app.Activity;
import android.app.Application;
import android.content.Intent;
import android.content.IntentSender;
import android.util.Log;

import com.huawei.hms.api.CheckUpdatelistener;
import com.huawei.hms.api.ConnectionResult;
import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.jos.JosApps;
import com.huawei.hms.jos.JosAppsClient;
import com.huawei.hms.support.api.client.ResultCallback;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.hwid.HwIDConstant;
import com.huawei.hms.support.api.entity.pay.ProductPayRequest;
import com.huawei.hms.support.api.hwid.HuaweiId;
import com.huawei.hms.support.api.hwid.HuaweiIdSignInOptions;
import com.huawei.hms.support.api.hwid.HuaweiIdStatusCodes;
import com.huawei.hms.support.api.hwid.SignInHuaweiId;
import com.huawei.hms.support.api.hwid.SignInResult;
import com.huawei.hms.support.api.pay.HuaweiPay;
import com.huawei.hms.support.api.pay.PayResult;
import com.huawei.hms.support.api.pay.ProductPayResultInfo;

import org.json.JSONException;
import org.json.JSONObject;

import kernel.AppContext;
import kernel.LuaJ;
import kernel.PluginManager;

@SuppressWarnings("unused")
public class Huawei {
    private static final String TAG = Huawei.class.getSimpleName();

    private static final int REQUEST_SIGN_IN_AUTH = 1001;
    private static final int REQUEST_CODE_PMSPAY = 3002;

    private static HuaweiApiClient apiClient;

    static {
        PluginManager.registerPlugin(new PluginManager.Handler() {
            @Override
            public void onInit(final Application app) {
            }

            @Override
            public void onStart(final Activity context) {
                Log.i(TAG, "init huawei sdk");
                JosAppsClient appsClient = JosApps.getJosAppsClient(context, null);
                appsClient.init();

                HuaweiIdSignInOptions signInOptions = new HuaweiIdSignInOptions.Builder(HuaweiIdSignInOptions.DEFAULT_SIGN_IN).build();
                apiClient = new HuaweiApiClient.Builder(context)
                        .addApi(HuaweiId.SIGN_IN_API, signInOptions)
                        .addApi(HuaweiPay.PAY_API)
                        .addScope(HuaweiId.HUAEWEIID_BASE_SCOPE)
                        .addScope(new com.huawei.hms.support.api.entity.auth.Scope(HwIDConstant.SCOPE.SCOPE_ACCOUNT_COUNTRY))
                        .addScope(HuaweiPay.SCOPE_IAP_QUERY_WALLETINFO)
                        .addConnectionCallbacks(new HuaweiApiClient.ConnectionCallbacks() {
                            @Override
                            public void onConnected() {
                                Log.i(TAG, "HuaweiApiClient connect success!");
                                apiClient.checkUpdate(context, new CheckUpdatelistener() {
                                    @Override
                                    public void onResult(int resultCode) {
                                        Log.i(TAG, "update result:" + resultCode);
                                    }
                                });
                            }

                            @Override
                            public void onConnectionSuspended(int i) {
                                Log.i(TAG, "HuaweiApiClient Disconnected!");
                                apiClient.connect(context);
                            }
                        })
                        .addOnConnectionFailedListener(new HuaweiApiClient.OnConnectionFailedListener() {
                            @Override
                            public void onConnectionFailed(ConnectionResult connectionResult) {
                                Log.i(TAG, "HuaweiApiClient Connect Failed!  Error code：" + connectionResult.getErrorCode());
                            }
                        })
                        .build();
                apiClient.connect(context);
                AppContext.registerFeature("huawei", true);
            }
        });
    }

    public static void revokeAccess() {
        HuaweiId.HuaweiIdApi.revokeAccess(apiClient).setResultCallback(new ResultCallback<Status>() {
            @Override
            public void onResult(Status status) {
                Log.i(TAG, "revokeAccess status: " + status.getStatusCode());
            }
        });
    }

    public static void logout() {
        HuaweiId.HuaweiIdApi.signOut(apiClient).setResultCallback(new ResultCallback<Status>() {
            @Override
            public void onResult(Status status) {
                Log.i(TAG, "signOut status: " + status.getStatusCode());
            }
        });
    }

    public static void login(final int handler) {
        final AppContext context = (AppContext) AppContext.getContext();
        HuaweiId.HuaweiIdApi.signIn(context, apiClient).setResultCallback(new ResultCallback<SignInResult>() {
            @Override
            public void onResult(SignInResult result) {
                if (result == null) {
                    handleSignInResult(handler, null);
                    return;
                }

                if (result.isSuccess()) {
                    handleSignInResult(handler, result);
                    return;
                }

                if (result.getStatus().getStatusCode() == HuaweiIdStatusCodes.SIGN_IN_AUTH
                        && result.getData() != null) {
                    context.setActivityResultCallback(new AppContext.ActivityResultCallback() {
                        @Override
                        public void onActivityResult(int requestCode, int resultCode, Intent data) {
                            if (requestCode != REQUEST_SIGN_IN_AUTH) {
                                return;
                            }
                            if (resultCode != Activity.RESULT_OK) {
                                handleSignInResult(handler, null);
                                return;
                            }

                            SignInResult result = HuaweiId.HuaweiIdApi.getHwIdSignInResultFromIntent(data);
                            handleSignInResult(handler, result);
                        }
                    });
                    context.startActivityForResult(result.getData(), REQUEST_SIGN_IN_AUTH);
                    return;
                }

                handleSignInResult(handler, result);
            }
        });
    }

    private static void handleSignInResult(int handler, SignInResult result) {
        JSONObject info = new JSONObject();
        try {
            info.put("status", -1);
            if (result != null) {
                info.put("status", result.getStatus().getStatusCode());
                if (result.isSuccess()) {
                    SignInHuaweiId account = result.getSignInHuaweiId();
                    info.put("status", 0);
                    info.put("displayName", account.getDisplayName());
                    info.put("openid", account.getOpenId());
                    info.put("unionid", account.getUnionId());
                    info.put("uid", account.getUid());
                    info.put("photoURL", account.getPhotoUrl());
                    info.put("accessToken", account.getAccessToken());
                    info.put("countryCode", account.getCountryCode());
                    info.put("gender", account.getGender());
                }
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
        LuaJ.invokeOnce(handler, info.toString());
    }

    public static void pay(String appid, String cpid, String cp, String orderNo, String pid, String url,
                                  String serviceCatalog, String extReserved, String sign, final int handler) {
        final AppContext context = (AppContext) AppContext.getContext();
        ProductPayRequest request = new ProductPayRequest();
        request.applicationID = appid;
        request.merchantId = cpid;
        request.productNo = pid;
        request.requestId = orderNo;
        request.sdkChannel = 1;
        request.urlVer = "2";
        request.url = url;
        request.merchantName = cp;
        request.serviceCatalog = serviceCatalog;
        request.sign = sign;
        request.extReserved = extReserved;
        HuaweiPay.HuaweiPayApi.productPay(apiClient, request).setResultCallback(new ResultCallback<PayResult>() {
            @Override
            public void onResult(PayResult result) {
                try {
                    context.setActivityResultCallback(new AppContext.ActivityResultCallback() {
                        @Override
                        public void onActivityResult(int requestCode, int resultCode, Intent data) {
                            if (requestCode != REQUEST_CODE_PMSPAY) {
                                return;
                            }
                            if (resultCode != Activity.RESULT_OK) {
                                LuaJ.invokeOnce(handler, "{}");
                                return;
                            }
                            ProductPayResultInfo result = HuaweiPay.HuaweiPayApi.getProductPayResultFromIntent(data);
                            JSONObject info = new JSONObject();
                            try {
                                info.put("status", -1);
                                if (result != null) {
                                    info.put("status", result.getReturnCode());
                                }
                            } catch (JSONException e) {
                                e.printStackTrace();
                            }
                            LuaJ.invokeOnce(handler, info.toString());
                        }
                    });
                    result.getStatus().startResolutionForResult(context, REQUEST_CODE_PMSPAY);
                } catch (IntentSender.SendIntentException e) {
                    LuaJ.invokeOnce(handler, "{}");
                    e.printStackTrace();
                }
            }
        });
    }
}
