package kernel.plugins.wechat;

import android.app.Activity;
import android.app.Application;
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

import org.cocos2dx.lib.Cocos2dxActivity;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedOutputStream;
import java.io.ByteArrayOutputStream;
import java.io.FileOutputStream;
import java.util.Date;

import kernel.AppContext;
import kernel.LuaJ;
import kernel.PluginManager;

@SuppressWarnings("unused")
public class WeChat {
    private static final String TAG = WeChat.class.getName();

    static {
        PluginManager.registerPlugin(new PluginManager.Handler() {
            @Override
            public void onInit(Application app) {
                Log.i(TAG, "init wechat sdk");
                AppContext.registerFeature("wechat", true);
            }

            @Override
            public void onStart(Activity context) {

            }
        });
    }

    static String APP_ID = "";
    static WeChatCallback notifyRespose;

    private static final int THUMB_SIZE = 150;

    private static final int TEXT = 1;
    private static final int PICTURE = 2;
    private static final int MUSIC = 3;
    private static final int VIDEO = 4;
    private static final int WEB = 5;

    private static WeChatCallback NULL_CALLBACK = new WeChatCallback() {
        @Override
        public void onResponse(BaseResp resp) {
        }
    };

    public static boolean isInstalled() {
        IWXAPI api = WXAPIFactory.createWXAPI(Cocos2dxActivity.getContext(), WeChat.APP_ID);
        return api.isWXAppInstalled();
    }

    public static void init(String appid) {
        WeChat.APP_ID = appid;

        Log.i(TAG, "init app id: " + WeChat.APP_ID);

        // register app id
        final IWXAPI wx = WXAPIFactory.createWXAPI(Cocos2dxActivity.getContext().getApplicationContext(), null);
        wx.registerApp(appid);
    }

    public static void auth(String scope, String state, final int handler) {
        AppContext context = (AppContext)Cocos2dxActivity.getContext();
        final SendAuth.Req req = new SendAuth.Req();
        req.scope = scope;
        req.state = state;

        WeChat.notifyRespose = new WeChatCallback() {
            @Override
            public void onResponse(BaseResp resp) {
                WeChat.notifyRespose = NULL_CALLBACK;
                if (resp.getType() == ConstantsAPI.COMMAND_SENDAUTH) {
                    SendAuth.Resp authResp = (SendAuth.Resp) resp;
                    try {
                        JSONObject data = new JSONObject();
                        data.put("errcode", authResp.errCode);
                        data.put("code", authResp.code);
                        data.put("state", authResp.state);
                        data.put("lang", authResp.lang);
                        data.put("country", authResp.country);
                        LuaJ.invokeOnce(handler, data.toString());
                    } catch (Exception e) {
                        e.printStackTrace();
                        LuaJ.invokeOnce(handler, "{\"errcode\":-1}");
                    }
                } else {
                    LuaJ.invokeOnce(handler, "{\"errcode\":-1}");
                }
            }
        };

        IWXAPI api = WXAPIFactory.createWXAPI(context, WeChat.APP_ID);
        api.sendReq(req);
    }

    public static void authQRCode(String appid, String scope, String noncestr, String timestamp, String signature, final int handler) {
        IDiffDevOAuth oauth = DiffDevOAuthFactory.getDiffDevOAuth();
        oauth.removeAllListeners();
        oauth.stopAuth();
        oauth.auth(appid, scope, noncestr, timestamp, signature, new OAuthListener() {
            @Override
            public void onAuthGotQrcode(String s, byte[] bytes) {
                try {
                    String path = AppContext.getDirectory("external.tmp") + "/wechat_auth_qrcode.jpg";

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

                    JSONObject data = new JSONObject();
                    data.put("errcode", OAuthErrCode.WechatAuth_Err_OK.getCode());
                    data.put("path", path);
                    LuaJ.invoke(handler, data.toString());
                } catch (Exception e) {
                    e.printStackTrace();
                    LuaJ.invoke(handler, "{\"errcode\":-4}");
                }
            }

            @Override
            public void onQrcodeScanned() {
            }

            @Override
            public void onAuthFinish(OAuthErrCode errCode, String code) {
                try {
                    JSONObject data = new JSONObject();
                    data.put("errcode", errCode.getCode());
                    data.put("code", code);
                    LuaJ.invokeOnce(handler, data.toString());
                } catch (Exception e) {
                    e.printStackTrace();
                    LuaJ.invokeOnce(handler, "{\"errcode\":-4}");
                }
            }
        });
    }

    public static void pay(String partnerId, String prepayId, String nonceStr, String timeStamp,
                           String packageValue, String sign, final int handler) {
        AppContext context = (AppContext)Cocos2dxActivity.getContext();
        final PayReq req = new PayReq();
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

        WeChat.notifyRespose = new WeChatCallback() {
            @Override
            public void onResponse(BaseResp baseResp) {
                WeChat.notifyRespose = NULL_CALLBACK;
                PayResp resp = (PayResp) baseResp;
                try {
                    JSONObject data = new JSONObject();
                    data.put("errcode", resp.errCode);
                    data.put("return_key", resp.returnKey);
                    LuaJ.invokeOnce(handler, data.toString());
                } catch (Exception e) {
                    e.printStackTrace();
                    LuaJ.invokeOnce(handler, "{\"errcode\":-1}");
                }
            }
        };

        IWXAPI api = WXAPIFactory.createWXAPI(context, WeChat.APP_ID);
        api.sendReq(req);
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

    public static void share(String objstr, final int callback)
    {
        AppContext context = (AppContext)Cocos2dxActivity.getContext();
        IWXAPI api = WXAPIFactory.createWXAPI(context, WeChat.APP_ID);

        WeChat.notifyRespose = new WeChatCallback() {
            @Override
            public void onResponse(BaseResp baseResp) {
                WeChat.notifyRespose = NULL_CALLBACK;
                try {
                    JSONObject data = new JSONObject();
                    data.put("errcode", baseResp.errCode);
                    LuaJ.invokeOnce(callback, data.toString());
                } catch (Exception e) {
                    e.printStackTrace();
                    LuaJ.invokeOnce(callback, "{\"errcode\":-1}");
                }
            }

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
                LuaJ.invokeOnce(callback, "{\"errcode\":-4}");
            }
        } catch (JSONException e) {
            e.printStackTrace();
            LuaJ.invokeOnce(callback, "{\"errcode\":-1}");
        }
    }

    public static void open(String id, String path, int type, final int callback)
    {
        AppContext context = (AppContext)Cocos2dxActivity.getContext();
        IWXAPI api = WXAPIFactory.createWXAPI(context, WeChat.APP_ID);

        WeChat.notifyRespose = new WeChatCallback() {
            @Override
            public void onResponse(BaseResp baseResp) {
                WeChat.notifyRespose = NULL_CALLBACK;
                try {
                    WXLaunchMiniProgram.Resp resp = (WXLaunchMiniProgram.Resp) baseResp;
                    JSONObject data = new JSONObject();
                    data.put("errcode", baseResp.errCode);
                    data.put("extraData", resp.extMsg);
                    LuaJ.invokeOnce(callback, data.toString());
                } catch (Exception e) {
                    e.printStackTrace();
                    LuaJ.invokeOnce(callback, "{\"errcode\":-1}");
                }
            }

        };


        WXLaunchMiniProgram.Req req = new WXLaunchMiniProgram.Req();
        req.userName = id;
        req.path = path;
        req.miniprogramType = type;
        api.sendReq(req);
    }

}
