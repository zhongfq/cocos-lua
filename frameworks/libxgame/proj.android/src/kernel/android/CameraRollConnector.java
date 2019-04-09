package kernel.android;

import android.content.Intent;

import org.cocos2dx.lib.Cocos2dxActivity;

@SuppressWarnings("unused")
public class CameraRollConnector {
    public static void selectImage(String cachePath, final int handler) {
        final AppContext context = (AppContext) Cocos2dxActivity.getContext();
        Intent intent = new Intent(context, CameraRoll.class);
        intent.putExtra("mode", CameraRoll.CameraRollMode.IMAGE);
        intent.putExtra("source", CameraRoll.CameraRollSource.PHOTO_LIBRARY);
        intent.putExtra("output", cachePath);

        CameraRoll.notifyResult = new CameraRoll.CameraRollCallback() {
            @Override
            public void onResult(final String message) {
                context.runOnGLThread(new Runnable() {
                    @Override
                    public void run() {
                        LuaJavaBridge.invokeOnce(handler, message);
                    }
                });
            }
        };

        context.startActivity(intent);
    }

    public static void selectAvatarFromCamera(String cachePath, int width, int height, final int handler) {
        final AppContext context = (AppContext) Cocos2dxActivity.getContext();
        final Intent intent = new Intent(context, CameraRoll.class);
        intent.putExtra("width", width);
        intent.putExtra("height", height);
        intent.putExtra("mode", CameraRoll.CameraRollMode.AVATAR);
        intent.putExtra("source", CameraRoll.CameraRollSource.CAMERA);
        intent.putExtra("output", cachePath);

        CameraRoll.notifyResult = new CameraRoll.CameraRollCallback() {
            @Override
            public void onResult(final String message) {
                context.runOnGLThread(new Runnable() {
                    @Override
                    public void run() {
                        LuaJavaBridge.invokeOnce(handler, message);
                    }
                });
            }
        };

        context.startActivity(intent);
    }

    public static void selectAvatarFromPhotoLibrary(String cachePath, int width, int height, final int handler) {
        final AppContext context = (AppContext) Cocos2dxActivity.getContext();
        final Intent intent = new Intent(context, CameraRoll.class);
        intent.putExtra("width", width);
        intent.putExtra("height", height);
        intent.putExtra("mode", CameraRoll.CameraRollMode.AVATAR);
        intent.putExtra("source", CameraRoll.CameraRollSource.PHOTO_LIBRARY);
        intent.putExtra("output", cachePath);

        CameraRoll.notifyResult = new CameraRoll.CameraRollCallback() {
            @Override
            public void onResult(final String message) {
                context.runOnGLThread(new Runnable() {
                    @Override
                    public void run() {
                        LuaJavaBridge.invokeOnce(handler, message);
                    }
                });
            }
        };
        context.startActivity(intent);
    }
}
