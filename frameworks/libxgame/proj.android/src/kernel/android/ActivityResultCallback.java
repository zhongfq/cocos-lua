package kernel.android;

import android.content.Intent;

public interface ActivityResultCallback {
    void onActivityResult(int requestCode, int resultCode, Intent data);
}
