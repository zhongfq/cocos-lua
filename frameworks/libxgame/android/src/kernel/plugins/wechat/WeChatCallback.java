package kernel.plugins.wechat;

import com.tencent.mm.opensdk.modelbase.BaseResp;

public interface WeChatCallback {
    void onResponse(BaseResp resp);
}
