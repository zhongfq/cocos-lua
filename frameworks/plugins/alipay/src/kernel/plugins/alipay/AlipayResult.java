package kernel.plugins.alipay;

import android.text.TextUtils;

public class AlipayResult {
    public String resultStatus = "";
    public String result = "";
    public String memo = "";

    public AlipayResult(String rawResult) {
        if (TextUtils.isEmpty(rawResult)) {
            return;
        }

        String[] resultParams = rawResult.split(";");
        for (String resultParam : resultParams) {
            if (resultParam.startsWith("resultStatus={")) {
                resultStatus = trim(resultParam, "resultStatus={", "}");
            } else if (resultParam.startsWith("result={")) {
                result = trim(resultParam, "result={", "}");
            } else if (resultParam.startsWith("memo={")) {
                memo = trim(resultParam, "memo={", "}");
            }
        }
    }

    private String trim(String content, String prefix, String suffix) {
        return content.substring(content.indexOf(prefix) + prefix.length(),
                content.lastIndexOf(suffix));
    }
}
