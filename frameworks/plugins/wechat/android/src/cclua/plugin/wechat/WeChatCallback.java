package cclua.plugin.wechat;

import com.tencent.mm.opensdk.modelbase.BaseResp;

public interface WeChatCallback {
    void onResponse(BaseResp resp);
}
