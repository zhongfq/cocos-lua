package kernel.android.wechat;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.ViewGroup.LayoutParams;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.LinearLayout;

public class WeChatWebAuthActivity extends Activity {

    @SuppressLint("SetJavaScriptEnabled")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        LinearLayout layout = new LinearLayout(this);
        layout.setLayoutParams(new LayoutParams(LayoutParams.MATCH_PARENT,
                LayoutParams.MATCH_PARENT));
        layout.setOrientation(LinearLayout.VERTICAL);
        setContentView(layout);

        String url = getIntent().getStringExtra("url");

        final Intent result = new Intent();

        WebView web = new WebView(this);
        web.clearCache(true);
        web.getSettings().setJavaScriptEnabled(true);
        web.getSettings().setSupportZoom(true);
        web.setWebViewClient(new WebViewClient() {
            @Override
            public boolean shouldOverrideUrlLoading(WebView view, String url) {
                if (url.contains("code=")) {
                    result.putExtra("code", extract(url, "code="));
                    setResult(RESULT_OK, result);
                } else {
                    setResult(RESULT_CANCELED);
                }

                finish();

                return false;
            }
        });
        web.loadUrl(url);
        layout.addView(web);
    }

    private String extract(String str, String key) {
        int start = str.indexOf(key);
        if (start >= 0) {
            int end = str.indexOf("&", start + key.length());
            return str.substring(start + key.length(), end > 0 ? end : str.length());
        } else {
            return null;
        }
    }

    @Override
    public void onBackPressed() {
        setResult(RESULT_CANCELED);
        finish();
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }
}
