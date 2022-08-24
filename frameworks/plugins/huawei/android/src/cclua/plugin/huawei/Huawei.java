package cclua.plugin.huawei;

import android.app.Activity;
import android.content.IntentSender;
import android.util.Log;

import com.huawei.hms.api.HuaweiApiClient;
import com.huawei.hms.jos.JosApps;
import com.huawei.hms.jos.JosAppsClient;
import com.huawei.hms.support.api.client.PendingResult;
import com.huawei.hms.support.api.client.Status;
import com.huawei.hms.support.api.entity.hwid.HwIDConstant;
import com.huawei.hms.support.api.entity.pay.ProductPayRequest;
import com.huawei.hms.support.api.hwid.HuaweiId;
import com.huawei.hms.support.api.hwid.HuaweiIdApi;
import com.huawei.hms.support.api.hwid.HuaweiIdSignInOptions;
import com.huawei.hms.support.api.hwid.HuaweiIdStatusCodes;
import com.huawei.hms.support.api.hwid.SignInHuaweiId;
import com.huawei.hms.support.api.hwid.SignInResult;
import com.huawei.hms.support.api.pay.HuaweiPay;
import com.huawei.hms.support.api.pay.HuaweiPayApi;
import com.huawei.hms.support.api.pay.ProductPayResultInfo;

import java.util.HashMap;

import cclua.AppContext;
import cclua.LuaJ;

@SuppressWarnings("unused")
public class Huawei {
    static {
        AppContext.registerPlugin(context -> AppContext.registerFeature("cclua.plugin.huawei", true));
    }

    private static final String TAG = Huawei.class.getSimpleName();

    private static final int REQUEST_SIGN_IN_AUTH = 1001;
    private static final int REQUEST_CODE_PMSPAY = 3002;

    private static HuaweiApiClient sClient;
    private static long sCallback = 0;

    public static void setDispatcher(long callback) {
        sCallback = callback;
    }

    public static void init() {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            Log.i(TAG, "init huawei sdk");
            JosAppsClient appsClient = JosApps.getJosAppsClient(context, null);
            appsClient.init();

            HuaweiIdSignInOptions signInOptions = new HuaweiIdSignInOptions.Builder(
                    HuaweiIdSignInOptions.DEFAULT_SIGN_IN).build();
            sClient = new HuaweiApiClient.Builder(context)
                    .addApi(HuaweiId.SIGN_IN_API, signInOptions)
                    .addApi(HuaweiPay.PAY_API)
                    .addScope(HuaweiId.HUAEWEIID_BASE_SCOPE)
                    .addScope(new com.huawei.hms.support.api.entity.auth.Scope(
                            HwIDConstant.SCOPE.SCOPE_ACCOUNT_COUNTRY))
                    .addScope(HuaweiPay.SCOPE_IAP_QUERY_WALLETINFO)
                    .addConnectionCallbacks(new HuaweiApiClient.ConnectionCallbacks() {
                        @Override
                        public void onConnected() {
                            Log.i(TAG, "HuaweiApiClient connect success!");
                            sClient.checkUpdate(context, resultCode ->
                                    Log.i(TAG, "update result:" + resultCode));
                        }

                        @Override
                        public void onConnectionSuspended(int i) {
                            Log.i(TAG, "HuaweiApiClient Disconnected!");
                            sClient.connect(context);
                        }
                    })
                    .addOnConnectionFailedListener(connectionResult ->
                            Log.i(TAG, "HuaweiApiClient Connect Failed!  Error code：" +
                                    connectionResult.getErrorCode()))
                    .build();
            sClient.connect(context);
        });

    }

    public static void revokeAccess() {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            PendingResult<Status> pending = HuaweiId.HuaweiIdApi.revokeAccess(sClient);
            pending.setResultCallback(status -> Log.i(TAG, "revokeAccess status: " +
                    status.getStatusCode()));
        });
    }

    public static void logout() {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            PendingResult<Status> pending = HuaweiId.HuaweiIdApi.signOut(sClient);
            pending.setResultCallback(status -> Log.i(TAG, "signOut status: " +
                    status.getStatusCode()));
        });
    }

    public static void login() {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            PendingResult<SignInResult> pending = HuaweiId.HuaweiIdApi.signIn(context, sClient);
            pending.setResultCallback(result -> {
                if (result == null) {
                    handleSignInResult(null);
                    return;
                }

                if (result.isSuccess()) {
                    handleSignInResult(result);
                    return;
                }

                if (result.getStatus().getStatusCode() == HuaweiIdStatusCodes.SIGN_IN_AUTH
                        && result.getData() != null) {
                    context.setActivityResultCallback((requestCode, resultCode, data) -> {
                        if (requestCode != REQUEST_SIGN_IN_AUTH) {
                            return;
                        }
                        if (resultCode != Activity.RESULT_OK) {
                            handleSignInResult(null);
                            return;
                        }
                        HuaweiIdApi api = HuaweiId.HuaweiIdApi;
                        SignInResult signInResult = api.getHwIdSignInResultFromIntent(data);
                        handleSignInResult(signInResult);
                    });
                    context.startActivityForResult(result.getData(), REQUEST_SIGN_IN_AUTH);
                    return;
                }
                handleSignInResult(result);
            });
        });
    }

    private static void handleSignInResult(SignInResult result) {
        HashMap<String, Object> data = new HashMap<>();
        data.put("statusCode", -1);
        if (result != null) {
            data.put("statusCode", result.getStatus().getStatusCode());
            if (result.isSuccess()) {
                SignInHuaweiId account = result.getSignInHuaweiId();
                data.put("displayName", account.getDisplayName());
                data.put("openid", account.getOpenId());
                data.put("unionid", account.getUnionId());
                data.put("uid", account.getUid());
                data.put("photoURL", account.getPhotoUrl());
                data.put("accessToken", account.getAccessToken());
                data.put("countryCode", account.getCountryCode());
                data.put("gender", account.getGender());
            }
        }
        LuaJ.invoke(sCallback, "login", data);
    }

    public static void pay(String appid, String cpid, String cp, String orderNo, String pid,
                           String url, String serviceCatalog, String extReserved, String sign) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
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
            HuaweiPay.HuaweiPayApi.productPay(sClient, request).setResultCallback(result -> {
                context.setActivityResultCallback((requestCode, resultCode, data) -> {
                    if (requestCode != REQUEST_CODE_PMSPAY) {
                        return;
                    }
                    if (resultCode != Activity.RESULT_OK) {
                        LuaJ.invoke(sCallback, "pay");
                        return;
                    }
                    HuaweiPayApi api = HuaweiPay.HuaweiPayApi;
                    ProductPayResultInfo payResult = api.getProductPayResultFromIntent(data);
                    HashMap<String, Object> info = new HashMap<>();
                    if (payResult == null) {
                        info.put("returnCode", -1);
                    } else {
                        info.put("returnCode", payResult.getReturnCode());
                        info.put("country", payResult.getCountry());
                        info.put("currency", payResult.getCurrency());
                        info.put("errMsg", payResult.getErrMsg());
                        info.put("merchantId", payResult.getMerchantId());
                        info.put("microsAmount", payResult.getMicrosAmount());
                        info.put("orderID", payResult.getOrderID());
                        info.put("productNo", payResult.getProductNo());
                        info.put("requestId", payResult.getRequestId());
                        info.put("sign", payResult.getSign());
                        info.put("time", payResult.getTime());
                    }
                    LuaJ.invoke(sCallback, "pay", info);
                });
                try {
                    result.getStatus().startResolutionForResult(context, REQUEST_CODE_PMSPAY);
                } catch (IntentSender.SendIntentException e) {
                    LuaJ.invoke(sCallback, "pay");
                }
            });
        });
    }
}
