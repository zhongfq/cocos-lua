package cclua.plugin.wechat;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.util.Log;

import com.tencent.mm.opensdk.constants.ConstantsAPI;
import com.tencent.mm.opensdk.diffdev.DiffDevOAuthFactory;
import com.tencent.mm.opensdk.diffdev.IDiffDevOAuth;
import com.tencent.mm.opensdk.diffdev.OAuthErrCode;
import com.tencent.mm.opensdk.diffdev.OAuthListener;
import com.tencent.mm.opensdk.modelbase.BaseResp;
import com.tencent.mm.opensdk.modelbiz.WXLaunchMiniProgram;
import com.tencent.mm.opensdk.modelbiz.WXOpenCustomerServiceChat;
import com.tencent.mm.opensdk.modelmsg.SendAuth;
import com.tencent.mm.opensdk.modelmsg.SendMessageToWX;
import com.tencent.mm.opensdk.modelmsg.WXImageObject;
import com.tencent.mm.opensdk.modelmsg.WXMediaMessage;
import com.tencent.mm.opensdk.modelmsg.WXMusicObject;
import com.tencent.mm.opensdk.modelmsg.WXTextObject;
import com.tencent.mm.opensdk.modelmsg.WXVideoObject;
import com.tencent.mm.opensdk.modelmsg.WXWebpageObject;
import com.tencent.mm.opensdk.modelpay.PayReq;
import com.tencent.mm.opensdk.modelpay.PayResp;
import com.tencent.mm.opensdk.openapi.IWXAPI;
import com.tencent.mm.opensdk.openapi.WXAPIFactory;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedOutputStream;
import java.io.ByteArrayOutputStream;
import java.io.FileOutputStream;
import java.util.Date;
import java.util.HashMap;

import cclua.AppContext;
import cclua.LuaJ;

@SuppressWarnings("unused")
public class WeChat {
    static {
        AppContext.registerPlugin(context -> AppContext.registerFeature("cclua.plugin.wechat", true));
    }

    static String APP_ID = "";
    static WeChatCallback notifyRespose;

    private static final String TAG = WeChat.class.getName();
    private static final int THUMB_SIZE = 150;
    private static final int TEXT = 1;
    private static final int PICTURE = 2;
    private static final int MUSIC = 3;
    private static final int VIDEO = 4;
    private static final int WEB = 5;
    private static final WeChatCallback NULL_CALLBACK = resp -> {};
    private static long sCallback = 0;

    public static void setDispatcher(long callback) {
        sCallback = callback;
    }

    public static boolean isInstalled() {
        AppContext context = AppContext.getContext();
        IWXAPI api = WXAPIFactory.createWXAPI(context, WeChat.APP_ID);
        return api.isWXAppInstalled();
    }

    public static void init(String appid) {
        AppContext context = AppContext.getContext();
        WeChat.APP_ID = appid;
        context.runOnUiThread(() -> {
            Log.i(TAG, "init app id: " + WeChat.APP_ID);
            // register app id
            final IWXAPI wx = WXAPIFactory.createWXAPI(context, null);
            wx.registerApp(appid);
        });
    }

    public static void auth(String scope, String state) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            SendAuth.Req req = new SendAuth.Req();
            req.scope = scope;
            req.state = state;

            WeChat.notifyRespose = resp -> {
                WeChat.notifyRespose = NULL_CALLBACK;
                if (resp.getType() == ConstantsAPI.COMMAND_SENDAUTH) {
                    SendAuth.Resp authResp = (SendAuth.Resp) resp;
                    HashMap<String, Object> data = new HashMap<>();
                    data.put("errcode", authResp.errCode);
                    data.put("code", authResp.code);
                    data.put("state", authResp.state);
                    data.put("lang", authResp.lang);
                    data.put("country", authResp.country);
                    LuaJ.invoke(sCallback, "auth", data);
                }
            };

            IWXAPI api = WXAPIFactory.createWXAPI(context, WeChat.APP_ID);
            api.sendReq(req);
        });
    }

    public static void authQRCode(String appid, String scope, String noncestr, String timestamp,
                                  String signature) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            IDiffDevOAuth oauth = DiffDevOAuthFactory.getDiffDevOAuth();
            oauth.removeAllListeners();
            oauth.stopAuth();
            oauth.auth(appid, scope, noncestr, timestamp, signature, new OAuthListener() {
                @Override
                public void onAuthGotQrcode(String s, byte[] bytes) {
                    String path = AppContext.getDirectory("external.tmp") + "/wx_auth_qrcode.jpg";
                    if (bytes != null) {
                        try {
                            Bitmap bitmap = BitmapFactory.decodeByteArray(bytes, 0, bytes.length);
                            BufferedOutputStream os = new BufferedOutputStream(new FileOutputStream(path));
                            bitmap.compress(Bitmap.CompressFormat.JPEG, 95, os);
                            bitmap.recycle();
                            os.flush();
                            os.close();
                        } catch (Throwable e) {
                            e.printStackTrace();
                        }
                    } else {
                        path = s;
                    }

                    HashMap<String, Object> data = new HashMap<>();
                    data.put("state", "AuthGotQrcode");
                    data.put("path", path);
                    LuaJ.invoke(sCallback, "authQRCode", data);
                }

                @Override
                public void onQrcodeScanned() {
                    HashMap<String, Object> data = new HashMap<>();
                    data.put("state", "QrcodeScanned");
                    LuaJ.invoke(sCallback, "authQRCode", data);
                }

                @Override
                public void onAuthFinish(OAuthErrCode errCode, String code) {
                    WeChat.notifyRespose = NULL_CALLBACK;
                    HashMap<String, Object> data = new HashMap<>();
                    data.put("state", "AuthFinish");
                    data.put("errcode", errCode.getCode());
                    data.put("code", code);
                    LuaJ.invoke(sCallback, "authQRCode", data);
                }
            });
        });
    }

    public static void stopAuth() {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            WeChat.notifyRespose = NULL_CALLBACK;
            IDiffDevOAuth oauth = DiffDevOAuthFactory.getDiffDevOAuth();
            oauth.removeAllListeners();
            oauth.stopAuth();
        });
    }

    public static void pay(String partnerId, String prepayId, String nonceStr, String timeStamp,
                           String packageValue, String sign) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            PayReq req = new PayReq();
            req.appId = WeChat.APP_ID;
            req.partnerId = partnerId;
            req.prepayId = prepayId;
            req.nonceStr = nonceStr;
            req.timeStamp = timeStamp;
            req.packageValue = packageValue;
            req.sign = sign;

            Log.i(TAG, "pay: appId=" + req.appId + "&" +
                    "partnerId=" + req.partnerId + "&" +
                    "prepayId=" + req.prepayId + "&" +
                    "nonceStr=" + req.nonceStr + "&" +
                    "timeStamp=" + req.timeStamp + "&" +
                    "packageValue=" + req.packageValue + "&" +
                    "sign=" + req.sign);

            WeChat.notifyRespose = baseResp -> {
                WeChat.notifyRespose = NULL_CALLBACK;
                PayResp resp = (PayResp) baseResp;
                HashMap<String, Object> data = new HashMap<>();
                data.put("errcode", resp.errCode);
                data.put("return_key", resp.returnKey);
                LuaJ.invoke(sCallback, "pay", data);
            };

            IWXAPI api = WXAPIFactory.createWXAPI(context, WeChat.APP_ID);
            api.sendReq(req);
        });
    }

    private static final int IMAGE_SIZE = 32768;

    private static byte[] bmpToByteArray(final Bitmap bmp) {
        ByteArrayOutputStream output = new ByteArrayOutputStream();
        bmp.compress(Bitmap.CompressFormat.JPEG, 95, output);
        int options = 100;
        while (output.toByteArray().length > IMAGE_SIZE && options != 10) {
            output.reset();
            bmp.compress(Bitmap.CompressFormat.JPEG, options, output);
            options -= 10;
        }


        bmp.recycle();

        Log.d(TAG, "size: " + output.toByteArray().length);

        byte[] result = output.toByteArray();
        try {
            output.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        return result;
    }

    public static void share(String objstr) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            IWXAPI api = WXAPIFactory.createWXAPI(context, WeChat.APP_ID);

            WeChat.notifyRespose = baseResp -> {
                WeChat.notifyRespose = NULL_CALLBACK;
                HashMap<String, Object> data = new HashMap<>();
                data.put("errcode", baseResp.errCode);
                LuaJ.invoke(sCallback, "share", data);
            };

            try {
                JSONObject obj = new JSONObject(objstr);
                int type = obj.getInt("type");
                WXMediaMessage message = new WXMediaMessage();
                switch (type) {
                    case TEXT: {
                        WXTextObject text = new WXTextObject();
                        text.text = obj.getString("text");
                        message.mediaObject = text;
                        message.description = text.text;
                        break;
                    }
                    case PICTURE: {
                        message.thumbData = bmpToByteArray(Bitmap.createScaledBitmap(
                                BitmapFactory.decodeFile(obj.getString("thumb")),
                                THUMB_SIZE, THUMB_SIZE, true));
                        message.title = obj.getString("title");
                        message.description = obj.getString("description");

                        Bitmap bmp = BitmapFactory.decodeFile(obj.getString("url"));
                        message.mediaObject = new WXImageObject(bmp);
                        bmp.recycle();
                        break;
                    }
                    case MUSIC: {
                        message.thumbData = bmpToByteArray(Bitmap.createScaledBitmap(
                                BitmapFactory.decodeFile(obj.getString("thumb")),
                                THUMB_SIZE, THUMB_SIZE, true));
                        message.title = obj.getString("title");
                        message.description = obj.getString("description");

                        WXMusicObject wxobj = new WXMusicObject();
                        wxobj.musicUrl = obj.getString("url");
                        wxobj.musicDataUrl = obj.getString("data_url");
                        message.mediaObject = wxobj;
                        break;
                    }
                    case VIDEO: {
                        message.thumbData = bmpToByteArray(Bitmap.createScaledBitmap(
                                BitmapFactory.decodeFile(obj.getString("thumb")),
                                THUMB_SIZE, THUMB_SIZE, true));
                        message.title = obj.getString("title");
                        message.description = obj.getString("description");

                        WXVideoObject wxobj = new WXVideoObject();
                        wxobj.videoUrl = obj.getString("url");
                        message.mediaObject = wxobj;
                        break;
                    }
                    case WEB: {
                        message.thumbData = bmpToByteArray(Bitmap.createScaledBitmap(
                                BitmapFactory.decodeFile(obj.getString("thumb")),
                                THUMB_SIZE, THUMB_SIZE, true));
                        message.title = obj.getString("title");
                        message.description = obj.getString("description");

                        WXWebpageObject wxobj = new WXWebpageObject();
                        wxobj.webpageUrl = obj.getString("url");
                        message.mediaObject = wxobj;
                        break;
                    }
                }

                SendMessageToWX.Req req = new SendMessageToWX.Req();
                req.transaction = String.valueOf(new Date().getTime());
                req.message = message;
                req.scene = obj.getInt("scene");
                if (!api.sendReq(req)) {
                    HashMap<String, Object> data = new HashMap<>();
                    data.put("errcode", BaseResp.ErrCode.ERR_SENT_FAILED);
                    LuaJ.invoke(sCallback, "share", data);
                }
            } catch (JSONException e) {
                e.printStackTrace();
                HashMap<String, Object> data = new HashMap<>();
                data.put("errcode", BaseResp.ErrCode.ERR_COMM);
                LuaJ.invoke(sCallback, "share", data);            }
        });
    }

    public static void open(String id, String path, int type) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            IWXAPI api = WXAPIFactory.createWXAPI(context, WeChat.APP_ID);

            WeChat.notifyRespose = baseResp -> {
                WeChat.notifyRespose = NULL_CALLBACK;
                WXLaunchMiniProgram.Resp resp = (WXLaunchMiniProgram.Resp) baseResp;
                HashMap<String, Object> data = new HashMap<>();
                data.put("errcode", baseResp.errCode);
                data.put("extraData", resp.extMsg);
                LuaJ.invoke(sCallback, "open", data);
            };

            WXLaunchMiniProgram.Req req = new WXLaunchMiniProgram.Req();
            req.userName = id;
            req.path = path;
            req.miniprogramType = type;
            api.sendReq(req);
        });
    }

    public static void openCustomerService(String corpid, String url) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            IWXAPI api = WXAPIFactory.createWXAPI(context, WeChat.APP_ID);

            WeChat.notifyRespose = baseResp -> WeChat.notifyRespose = NULL_CALLBACK;

            WXOpenCustomerServiceChat.Req req = new WXOpenCustomerServiceChat.Req();
            req.corpId = corpid;
            req.url = url;
            api.sendReq(req);
        });
    }
}
