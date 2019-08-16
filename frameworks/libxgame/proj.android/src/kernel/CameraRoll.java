package kernel;

import android.app.Activity;
import android.content.Intent;
import android.content.res.Configuration;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.provider.MediaStore;
import android.support.v4.content.FileProvider;

import org.cocos2dx.lib.Cocos2dxActivity;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;

@SuppressWarnings("unused")
public class CameraRoll extends Activity {
    public interface CameraRollCallback {
        void onResult(String message);
    }

    public interface CameraRollSource {
        int PHOTO_LIBRARY = 0;
        int CAMERA = 1;
    }

    public interface CameraRollMode {
        int AVATAR = 0;
        int IMAGE = 1;
    }

    public static CameraRollCallback notifyResult = null;

    private static int REQUEST_PICTURE = 1;
    private static int REQUEST_CROP_PICTURE = 2;

    private File _output;
    private int _width;
    private int _height;
    private int _mode;
    private int _source;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        _output = new File(getIntent().getStringExtra("output"));
        _width = getIntent().getIntExtra("width", 200);
        _height = getIntent().getIntExtra("height", 200);
        _mode = getIntent().getIntExtra("mode", CameraRollMode.AVATAR);
        _source = getIntent().getIntExtra("source", CameraRollSource.PHOTO_LIBRARY);

        if (_source == CameraRollSource.PHOTO_LIBRARY) {
            Intent intent = new Intent(Intent.ACTION_PICK,
                    MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
            startActivityForResult(intent, REQUEST_PICTURE);
        } else {
            Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
                intent.putExtra(MediaStore.EXTRA_OUTPUT, getContentURI(_output));
                intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
                intent.addFlags(Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
            } else {
                intent.putExtra(MediaStore.EXTRA_OUTPUT, Uri.fromFile(_output));
            }
            startActivityForResult(intent, REQUEST_PICTURE);
        }
    }

    private Uri getContentURI(File path) {
        return FileProvider.getUriForFile(this, getPackageName() + ".fileprovider", path);
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (resultCode == RESULT_OK) {
            if (requestCode == REQUEST_PICTURE) {
                if (_mode == CameraRollMode.AVATAR) {
                    Intent intent = new Intent("com.android.camera.action.CROP");
                    if (_source == CameraRollSource.PHOTO_LIBRARY) {
                        intent.setDataAndType(data.getData(), "image/*");
                    } else if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
                        intent.setDataAndType(getContentURI(_output), "image/*");
                        intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
                        intent.addFlags(Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
                    } else {
                        intent.setDataAndType(Uri.fromFile(_output), "image/*");
                    }
                    intent.putExtra("crop", "true");
                    intent.putExtra("aspectX", 1);
                    intent.putExtra("aspectY", 1);
                    intent.putExtra("outputX", _width);
                    intent.putExtra("outputY", _height);
                    intent.putExtra("scale", true);
                    intent.putExtra("return-data", false);
                    intent.putExtra(MediaStore.EXTRA_OUTPUT, Uri.fromFile(_output));
                    startActivityForResult(intent, REQUEST_CROP_PICTURE);
                } else {
                    notifyResult.onResult("complete");
                    finish();
                }
            } else if (requestCode == REQUEST_CROP_PICTURE) {
                try {
                    Bitmap bitmap = BitmapFactory.decodeFile(_output.getAbsolutePath());
                    if (bitmap != null) {
                        BufferedOutputStream os = new BufferedOutputStream(new FileOutputStream(_output));
                        Matrix matrix = new Matrix();
                        matrix.postScale((float)_width / bitmap.getWidth(),
                                (float)_height / bitmap.getHeight());
                        Bitmap newBitmap = Bitmap.createBitmap(bitmap, 0, 0, bitmap.getWidth(), bitmap.getHeight(), matrix, false);
                        newBitmap.compress(Bitmap.CompressFormat.JPEG, 95, os);

                        bitmap.recycle();
                        newBitmap.recycle();

                        os.flush();
                        os.close();
                        notifyResult.onResult("complete");
                        finish();
                    } else {
                        notifyResult.onResult("unknown");
                        finish();
                    }
                } catch (Throwable e) {
                    notifyResult.onResult("io_error");
                    finish();
                }
            } else {
                notifyResult.onResult("io_error");
                finish();
            }
        } else {
            notifyResult.onResult("cancel");
            finish();
        }

    }

    public static void selectImage(String cachePath, final int handler) {
        final AppContext context = (AppContext) Cocos2dxActivity.getContext();
        Intent intent = new Intent(context, CameraRoll.class);
        intent.putExtra("mode", CameraRoll.CameraRollMode.IMAGE);
        intent.putExtra("source", CameraRoll.CameraRollSource.PHOTO_LIBRARY);
        intent.putExtra("output", cachePath);

        CameraRoll.notifyResult = new CameraRoll.CameraRollCallback() {
            @Override
            public void onResult(final String message) {
                LuaJ.invokeOnce(handler, message);
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
                LuaJ.invokeOnce(handler, message);
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
                LuaJ.invokeOnce(handler, message);
            }
        };
        context.startActivity(intent);
    }
}