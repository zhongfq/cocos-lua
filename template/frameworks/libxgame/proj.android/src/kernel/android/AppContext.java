package kernel.android;

import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.util.Log;
import android.view.WindowManager;

import org.cocos2dx.lib.Cocos2dxActivity;

import java.util.HashMap;

public class AppContext extends Cocos2dxActivity {
    private static final String TAG = AppContext.class.getName();
    private ActivityResultCallback m_callback;
    private ActivityPermissionsResultCallback m_permissionCallback;

    private HashMap<String, Object> _args = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        createArgs(getIntent().getExtras());
        super.onCreate(savedInstanceState);
        super.setEnableVirtualButton(false);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
    }

    public void setActivityResultCallback(ActivityResultCallback callback) {
        m_callback = callback;
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (m_callback != null) {
            m_callback.onActivityResult(requestCode, resultCode, data);
            m_callback = null;
        }
    }

    public void setActivityPermissionResultCallback(ActivityPermissionsResultCallback callback) {
        m_permissionCallback = callback;
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (m_permissionCallback != null) {
            m_permissionCallback.onRequestPermissionsResult(requestCode, permissions, grantResults);
        }
    }

    @Override
    protected void onNewIntent(Intent intent) {
        createArgs(intent.getExtras());
        super.onNewIntent(intent);
    }

    private void createArgs(Bundle bundle) {
        if (bundle != null) {
            _args = new HashMap<>();
            for (String key : bundle.keySet())
            {
                Object value = bundle.get(key);
                if (value instanceof String ||
                        value instanceof Integer ||
                        value instanceof Number ||
                        value instanceof Boolean) {
                    _args.put(key, value);
                    Log.i(TAG, key + "=" + value);
                }
            }
        }
    }

    public HashMap<String, Object> getArgs() {
        HashMap<String, Object> args = _args;
        _args = null;
        return args;
    }
}