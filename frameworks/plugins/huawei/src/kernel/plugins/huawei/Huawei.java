package kernel.plugins.huawei;

import android.app.Application;
import android.util.Log;

import com.huawei.android.hms.agent.HMSAgent;
import com.huawei.android.hms.agent.common.handler.CheckUpdateHandler;
import com.huawei.android.hms.agent.common.handler.ConnectHandler;
import com.huawei.android.hms.agent.hwid.handler.SignInHandler;
import com.huawei.android.hms.agent.hwid.handler.SignOutHandler;
import com.huawei.android.hms.agent.pay.PaySignUtil;
import com.huawei.android.hms.agent.pay.handler.GetOrderHandler;
import com.huawei.android.hms.agent.pay.handler.GetPurchaseInfoHandler;
import com.huawei.android.hms.agent.pay.handler.ProductPayHandler;
import com.huawei.hms.support.api.entity.pay.OrderRequest;
import com.huawei.hms.support.api.entity.pay.ProductPayRequest;
import com.huawei.hms.support.api.entity.pay.PurchaseInfo;
import com.huawei.hms.support.api.entity.pay.PurchaseInfoRequest;
import com.huawei.hms.support.api.hwid.SignInHuaweiId;
import com.huawei.hms.support.api.hwid.SignOutResult;
import com.huawei.hms.support.api.pay.OrderResult;
import com.huawei.hms.support.api.pay.ProductPayResultInfo;
import com.huawei.hms.support.api.pay.PurchaseInfoResult;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import kernel.AppContext;
import kernel.LuaJ;

@SuppressWarnings("unused")
public class Huawei {
    private static final String TAG = Huawei.class.getSimpleName();

    public static void init(Application app) {
        HMSAgent.init(app);
        AppContext.registerFeature("huawei", true);
    }

    public static void onCreate() {
        final AppContext context = (AppContext) AppContext.getContext();
        HMSAgent.connect(context, new ConnectHandler() {
            @Override
            public void onConnect(int rst) {
                Log.i(TAG, "HMS connect end:" + rst);
                HMSAgent.checkUpdate(context, new CheckUpdateHandler() {
                    @Override
                    public void onResult(int rst) {
                        Log.i(TAG, "check app update rst:" + rst);
                    }
                });
            }
        });
    }

    public static void signIn(final int handler) {
        HMSAgent.Hwid.signIn(true, new SignInHandler() {
            @Override
            public void onResult(int rst, SignInHuaweiId result) {
                try {
                    JSONObject data = new JSONObject();
                    data.put("status", rst);
                    if (rst == HMSAgent.AgentResultCode.HMSAGENT_SUCCESS && result != null) {
                        data.put("displayName", result.getDisplayName());
                        data.put("openid", result.getOpenId());
                        data.put("unionid", result.getUnionId());
                        data.put("uid", result.getUid());
                        data.put("photoURL", result.getPhotoUrl());
                        data.put("accessToken", result.getAccessToken());
                        data.put("countryCode", result.getCountryCode());
                        data.put("gender", result.getGender());
                    }
                    LuaJ.invokeOnce(handler, data.toString());
                } catch (JSONException e) {
                    e.printStackTrace();
                    LuaJ.invokeOnce(handler, "{}");
                }
            }
        });
    }

    public static void signOut(final int handler) {
        HMSAgent.Hwid.signOut(new SignOutHandler() {
            @Override
            public void onResult(int rst, SignOutResult result) {
                try {
                    JSONObject data = new JSONObject();
                    data.put("status", rst);
                    LuaJ.invokeOnce(handler, data.toString());
                } catch (JSONException e) {
                    e.printStackTrace();
                    LuaJ.invokeOnce(handler, "{}");
                }
            }
        });
    }

    public static void productPay(String appid, String cpid, String cp, String orderNo, String pid, String url,
                                  String serviceCatalog, String extReserved, String sign, final int handler) {
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
        Log.i(TAG, PaySignUtil.getStringForSign(request));
        Log.i(TAG, sign + "=" + request.sign);
        HMSAgent.Pay.productPay(request, new ProductPayHandler() {
            @Override
            public void onResult(int rst, ProductPayResultInfo result) {
                try {
                    JSONObject data = new JSONObject();
                    data.put("status", rst);
                    LuaJ.invokeOnce(handler, data.toString());
                } catch (JSONException e) {
                    e.printStackTrace();
                    LuaJ.invokeOnce(handler, "{}");
                }
            }
        });
    }

    public static void getPurchaseInfo(String appid, String cpid, String pid, long ts, long pageNo,
                                       String sign, final int handler) {
        final PurchaseInfoRequest request = new PurchaseInfoRequest();
        request.appId = appid;
        request.merchantId = cpid;
        request.priceType = "3";
        request.productId = pid.length() == 0 ? null : pid;
        request.ts = ts;
        request.pageNo = pageNo;
        request.sign = sign;
        Log.i(TAG, PaySignUtil.getStringForSign(request));
        Log.i(TAG, sign + "=" + request.sign);
        HMSAgent.Pay.getPurchaseInfo(request, new GetPurchaseInfoHandler() {
            @Override
            public void onResult(int rst, PurchaseInfoResult result) {
                try {
                    JSONObject data = new JSONObject();
                    data.put("status", rst);
                    if (result != null) {
                        data.put("pageCount", result.getPageCount());
                        data.put("sign", result.getSign());
                        JSONArray list = new JSONArray();
                        data.put("list", list);
                        for (PurchaseInfo info : result.getPurchaseInfoList()) {
                            JSONObject o = new JSONObject();
                            o.put("orderNo", info.getRequestId());
                            o.put("cpid", info.getMerchantId());
                            o.put("pic", info.getProductId());
                            o.put("tradeTime", info.getTradeTime());
                            o.put("name", info.getAppId());
                            list.put(o);
                        }
                    }
                    LuaJ.invokeOnce(handler, data.toString());
                } catch (JSONException e) {
                    e.printStackTrace();
                    LuaJ.invokeOnce(handler, "{}");
                }
            }
        });
    }

    public static void getOrderDetail(String cpid, String orderNo, String time, String sign, final int handler) {
        final OrderRequest request = new OrderRequest();
        request.keyType = "1";
        request.merchantId = cpid;
        request.requestId = orderNo;
        request.time = time;
        request.sign = sign;
        HMSAgent.Pay.getOrderDetail(request, new GetOrderHandler() {
            @Override
            public void onResult(int rst, OrderResult result) {
                try {
                    JSONObject data = new JSONObject();
                    data.put("status", rst);
                    if (result != null) {
                        data.put("orderID", result.getOrderID());
                        data.put("orderStatus", result.getOrderStatus());
                        data.put("orderNo", result.getRequestId());
                        data.put("sign", result.getSign());
                        data.put("orderTime", result.getOrderTime());
                        data.put("tradeTime", result.getTradeTime());

                    }
                    LuaJ.invokeOnce(handler, data.toString());
                } catch (JSONException e) {
                    e.printStackTrace();
                    LuaJ.invokeOnce(handler, "{}");
                }
            }
        });
    }
}
