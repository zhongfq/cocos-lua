package kernel.plugins.alipay;

import org.json.JSONObject;

public class AlipayUtil {
    public static boolean verifyResult(AlipayResult result, String publicKey) {
        boolean ok = false;
        if (result.resultStatus.equals("9000")) {
            StringBuilder builder = new StringBuilder();
            String sign = null;
            String success = null;
            for (String value : result.result.split("&")) {
                if (value.startsWith("sign=")) {
                    sign = value.substring(("sign=\"").length(), value.length() - 1);
                } else if (!value.startsWith("sign_type=")) {
                    if (value.startsWith("success=")) {
                        success = value.substring(("success=\"").length(), value.length() - 1);
                    }

                    if (builder.length() > 0) {
                        builder.append("&");
                    }
                    builder.append(value);
                }
            }

            if (success != null && success.equals("true")) {
                ok = RSA.verify(builder.toString(), sign, publicKey);
            }
        }

        return ok;
    }

    public static String appendVerifyStatus(AlipayResult result, boolean verify) {
        JSONObject data = new JSONObject();
        try {
            data.put("verify_status", verify ? "true" : "false");
            data.put("result_status", result.resultStatus);
            data.put("result", result.result);
            data.put("memo", result.memo);
        } catch (Exception e) {
            e.printStackTrace();
        }

        return data.toString();
    }
}
