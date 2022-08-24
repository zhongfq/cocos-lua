package cclua.plugin.wechat;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import com.tencent.mm.opensdk.modelbase.BaseReq;
import com.tencent.mm.opensdk.modelbase.BaseResp;
import com.tencent.mm.opensdk.openapi.IWXAPI;
import com.tencent.mm.opensdk.openapi.IWXAPIEventHandler;
import com.tencent.mm.opensdk.openapi.WXAPIFactory;

public class WeChatEntryActivity extends Activity implements IWXAPIEventHandler {
    private static final String TAG = WeChatEntryActivity.class.getName();

    private IWXAPI _api;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        _api = WXAPIFactory.createWXAPI(this, WeChat.APP_ID);
        _api.handleIntent(getIntent(), this);
    }

    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        setIntent(intent);
        _api.handleIntent(intent, this);
    }

    @Override
    public void onReq(BaseReq baseReq) {
    }

    @Override
    public void onResp(final BaseResp resp) {
        Log.d(TAG, "errCode = " + resp.errCode);
        WeChat.notifyRespose.onResponse(resp);
        finish();
    }
}
