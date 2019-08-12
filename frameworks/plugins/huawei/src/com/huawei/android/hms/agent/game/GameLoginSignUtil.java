package com.huawei.android.hms.agent.game;

import android.text.TextUtils;

import com.huawei.android.hms.agent.common.HMSAgentLog;
import com.huawei.android.hms.agent.common.ThreadUtil;
import com.huawei.android.hms.agent.game.checksignutil.RSAUtil;
import com.huawei.android.hms.agent.game.handler.ICheckLoginSignHandler;
import com.huawei.hms.support.api.entity.game.GameUserData;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.Closeable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * 游戏登录结果验签工具类，请在服务端实现，这里仅做参考
 * 验签过程需要使用到公钥、私钥。
 * 注意：私钥属于非常保密信息，为了避免泄露，请在服务端进行登录验签。具体实现可参考此类。
 */
public final class GameLoginSignUtil {

    private  static final String URL = "https://gss-cn.game.hicloud.com/gameservice/api/gbClientApi";
    /**
     * 默认HTTP超时，单位：milliseconds。
     */
    private static final int CONN_TIMEOUT = 30 * 1000;
    private static final int READ_TIMEOUT = 30 * 1000;

    /**
     * 私有构造方法
     */
    private GameLoginSignUtil() {
    }

    /**
     * 启动线程进行登录结果的验签，
     * 重要：此方法仅供单机应用使用。有自己服务器的应用，整个对登录结果的验签需要在开发者的服务器端进行，私钥要注意保存避免泄露
     * 此类的实现可以作为参考
     * @param appId 应用程序id，来源于华为开发者联盟上参数
     * @param cpId 开发者id，来源于开发者联盟
     * @param privateKey 私钥，来源于开发者联盟，非常重要的信息，注意保存避免泄露
     * @param publicKey 公钥，用来验签服务端返回的结果
     * @param userData 用户的登录结果数据
     * @param callback 验签结果回调
     */
    public static void checkLoginSign(final String appId, final String cpId, final String privateKey, final String publicKey, final GameUserData userData, final ICheckLoginSignHandler callback) {
        ThreadUtil.INST.excute(new Runnable() {
            @Override
            public void run() {
                doCheck(appId, cpId, privateKey, publicKey, userData, callback);
            }
        });
    }

    /**
     * 验签
     * @param appId 应用程序id，来源于华为开发者联盟上参数
     * @param cpId 开发者id，来源于开发者联盟
     * @param privateKey 私钥，来源于开发者联盟，非常重要的信息，注意保存避免泄露
     * @param publicKey 公钥，用来验签服务端返回的结果
     * @param userData 用户的登录结果数据
     * @param callback 验签结果回调
     */
    private static void doCheck(String appId, String cpId, String privateKey, String publicKey, GameUserData userData, ICheckLoginSignHandler callback) {
        // 创建body参数
        byte[] body = getRequestBody(appId, cpId, privateKey, userData);

        // 发送请求
        sendRequest(URL, body, publicKey, callback);
    }

    /**
     * 发送验签请求
     * @param url 请求url
     * @param body 请求body
     * @param publicKey 验签所使用的公钥
     * @param callback 验签结果回调
     */
    private static void sendRequest(String url, byte[] body, String publicKey, ICheckLoginSignHandler callback) {
        HttpURLConnection conn = null;

        OutputStream out = null;
        InputStream is = null;
        InputStreamReader isr = null;
        try {
            URL urlReq = new URL(url);
            conn = (HttpURLConnection)urlReq.openConnection();

            // 设置HttpURLConnection选项
            conn.setRequestMethod("POST");
            conn.setConnectTimeout(CONN_TIMEOUT);
            conn.setReadTimeout(READ_TIMEOUT);
            conn.setUseCaches(false);
            conn.setDoOutput(true);
            conn.setRequestProperty("Content-Type", "application/json");
            conn.setFixedLengthStreamingMode(body.length);

            // 写入body数据
            out = conn.getOutputStream();
            out.write(body);
            out.flush();

            int httpCode = conn.getResponseCode();
            if (httpCode == HttpURLConnection.HTTP_OK)
            {
                StringBuilder sb = new StringBuilder();
                char[] buffer = new char[512];
                is = conn.getInputStream();
                isr = new InputStreamReader(is, "UTF-8");
                int readLen = 0;
                while ((readLen = isr.read(buffer)) != -1) {
                    sb.append(buffer, 0, readLen);
                }

                // 资源释放
                close(out);
                out = null;
                close(is);
                is = null;
                close(isr);
                isr = null;

                // 调用子类解析函数
                String str = sb.toString();
                if (!TextUtils.isEmpty(str)) {
                    callbackResult(str, publicKey, callback);
                } else {
                    callback.onCheckResult(null, "response string is empty!", false);
                }
            } else {
                // 资源释放
                close(out);
                out = null;
                callback.onCheckResult(null, "http request code is " + httpCode, false);
            }
        }catch (Exception e) {
            // 资源释放
            close(out);
            close(is);
            close(isr);

            callback.onCheckResult(null, "http request exception:" + e.getMessage(), false);
        }
    }

    /**
     * 回调验签请求结果
     * @param str 验签请求结果字符串
     * @param pubKey 公钥
     * @param callback 回调
     */
    private static void callbackResult(String str, String pubKey, ICheckLoginSignHandler callback){
        JSONObject json = null;
        try {
            json = new JSONObject(str);
        } catch (JSONException e) {
            callback.onCheckResult(null, "json parse fail:" + e.getMessage(), false);
            return;
        }

        String rtnCode = json.optString("rtnCode");
        String errMsg = json.optString("errMsg");
        String ts = json.optString("ts");
        String rtnSign = json.optString("rtnSign");

        if("0".equals(rtnCode))
        {
            String nosign = "rtnCode=" + RSAUtil.urlEncode(rtnCode) + "&ts=" + RSAUtil.urlEncode(ts);
            boolean s = RSAUtil.doCheck(nosign, rtnSign, pubKey);
            callback.onCheckResult(rtnCode, "request success", s);
        } else {
            callback.onCheckResult(rtnCode, "request sign fail:" + errMsg, false);
        }
    }

    /**
     * 获取验签请求体
     * @param appId 应用程序id，来源于华为开发者联盟上参数
     * @param cpId 开发者id，来源于开发者联盟
     * @param privateKey 私钥，来源于开发者联盟，非常重要的信息，注意保存避免泄露
     * @param userData 用户的登录结果数据
     * @return 验签请求体
     */
    private static byte[] getRequestBody(String appId, String cpId, String privateKey, GameUserData userData) {
        Map<String,String> params = getParamMap(appId, cpId, userData);
        params.put("cpSign", RSAUtil.sign(getSignData(params), privateKey));

        StringBuilder strBody = new StringBuilder();
        Set<Map.Entry<String, String>> paramSet = params.entrySet();
        boolean isFirstParm = true;
        for (Map.Entry<String, String> param : paramSet) {
            if (param != null) {
                if (!TextUtils.isEmpty(param.getValue()))
                {
                    strBody.append(isFirstParm?"":"&").append(param.getKey()).append('=').append(RSAUtil.urlEncode(param.getValue()));
                    isFirstParm = false;
                }
            }
        }

        try
        {
            return strBody.toString().getBytes("UTF-8");
        }
        catch (UnsupportedEncodingException e)
        {
            return new byte[0];
        }
    }

    private static Map<String,String> getParamMap(String appId, String cpId, GameUserData userData) {
        Map<String,String> params = new HashMap<String,String>();
        params.put("appId", appId);
        params.put("cpId", cpId);
        params.put("playerId", userData.getPlayerId());
        params.put("playerLevel", String.valueOf(userData.getPlayerLevel()));
        params.put("playerSSign", userData.getGameAuthSign());
        params.put("ts", userData.getTs());
        params.put("method", "external.hms.gs.checkPlayerSign");
        return params;
    }

    private static String getSignData(Map<String, String> params) {
        StringBuffer content = new StringBuffer();

        List keys = new ArrayList(params.keySet());
        Collections.sort(keys);
        for (int i = 0; i < keys.size(); i++)
        {
            String key = (String)keys.get(i);
            String value = params.get(key);
            if (value != null) {
                content.append((i == 0 ? "" : "&") + key + "=" + RSAUtil.urlEncode(value));
            }
        }
        return content.toString();
    }

    private static void close(Closeable obj) {
        try {
            if (obj != null) {
                obj.close();
            }
        } catch (IOException e) {
            HMSAgentLog.e("close error");
        }
    }
}
