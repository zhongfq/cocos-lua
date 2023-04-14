package cclua;

import android.app.Activity;
import android.content.Intent;
import android.content.res.Configuration;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;

import androidx.core.content.FileProvider;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.util.HashMap;

@SuppressWarnings("unused")
public class Photo extends Activity {
    public interface SelectCallback {
        void onResult(String status, String statusMessage);
    }

    public interface PhotoSource {
        int PHOTO_LIBRARY = 0;
        int CAMERA = 1;
    }

    public interface PhotoMode {
        int AVATAR = 0;
        int IMAGE = 1;
    }

    public static SelectCallback notifyResult = null;

    private static final int REQUEST_PICTURE = 1;
    private static final int REQUEST_CROP_PICTURE = 2;

    private static long sCallback = 0;

    private File mOutput;
    private int mWidth;
    private int mHeight;
    private int mMode;
    private int mSource;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        mOutput = new File(getIntent().getStringExtra("output"));
        mWidth = getIntent().getIntExtra("width", 200);
        mHeight = getIntent().getIntExtra("height", 200);
        mMode = getIntent().getIntExtra("mode", PhotoMode.AVATAR);
        mSource = getIntent().getIntExtra("source", PhotoSource.PHOTO_LIBRARY);

        Intent intent;
        if (mSource == PhotoSource.PHOTO_LIBRARY) {
            intent = new Intent(Intent.ACTION_PICK,
                    MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
        } else {
            intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
            intent.putExtra(MediaStore.EXTRA_OUTPUT, getContentURI(mOutput));
            intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
            intent.addFlags(Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
        }
        startActivityForResult(intent, REQUEST_PICTURE);
    }

    private Uri getContentURI(File path) {
        String authority = getPackageName() + ".fileprovider";
        return FileProvider.getUriForFile(this, authority, path);
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (resultCode != RESULT_OK) {
            notifyResult.onResult("cancel", null);
            finish();
            return;
        }
        if (requestCode == REQUEST_PICTURE) {
            if (mMode == PhotoMode.AVATAR) {
                Intent intent = new Intent("com.android.camera.action.CROP");
                if (mSource == PhotoSource.PHOTO_LIBRARY) {
                    intent.setDataAndType(data.getData(), "image/*");
                } else {
                    intent.setDataAndType(getContentURI(mOutput), "image/*");
                    intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
                    intent.addFlags(Intent.FLAG_GRANT_WRITE_URI_PERMISSION);
                }
                intent.putExtra("crop", "true");
                intent.putExtra("aspectX", 1);
                intent.putExtra("aspectY", 1);
                intent.putExtra("outputX", mWidth);
                intent.putExtra("outputY", mHeight);
                intent.putExtra("scale", true);
                intent.putExtra("return-data", false);
                intent.putExtra(MediaStore.EXTRA_OUTPUT, Uri.fromFile(mOutput));
                startActivityForResult(intent, REQUEST_CROP_PICTURE);
            } else {
                notifyResult.onResult("complete", null);
                finish();
            }
        } else if (requestCode == REQUEST_CROP_PICTURE) {
            try {
                Bitmap bitmap = BitmapFactory.decodeFile(mOutput.getAbsolutePath());
                if (bitmap != null) {
                    BufferedOutputStream os = new BufferedOutputStream(new FileOutputStream(mOutput));
                    Matrix matrix = new Matrix();
                    matrix.postScale((float) mWidth / bitmap.getWidth(),
                            (float) mHeight / bitmap.getHeight());
                    Bitmap newBitmap = Bitmap.createBitmap(bitmap, 0, 0, bitmap.getWidth(), bitmap.getHeight(), matrix, false);
                    newBitmap.compress(Bitmap.CompressFormat.JPEG, 95, os);

                    bitmap.recycle();
                    newBitmap.recycle();

                    os.flush();
                    os.close();
                    notifyResult.onResult("complete", null);
                } else {
                    notifyResult.onResult("ioerror", "read image file error");
                }
                finish();
            } catch (Throwable e) {
                notifyResult.onResult("ioerror", "write image file error");
                finish();
            }
        } else {
            notifyResult.onResult("unknown", null);
            finish();
        }
    }

    public static void setDispatcher(long callback) {
        sCallback = callback;
    }

    public static void select(String cachePath) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            Intent intent = new Intent(context, Photo.class);
            intent.putExtra("mode", PhotoMode.IMAGE);
            intent.putExtra("source", PhotoSource.PHOTO_LIBRARY);
            intent.putExtra("output", cachePath);
            Photo.notifyResult = (status, statusMessage) -> {
                HashMap<String, Object> data = new HashMap<>();
                data.put("status", status);
                data.put("statusMessage", statusMessage);
                LuaJ.invoke(sCallback, "select", data);
            };
            context.startActivity(intent);
        });

    }

    public static void takeAvatar(String cachePath, int width, int height) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            Intent intent = new Intent(context, Photo.class);
            intent.putExtra("width", width);
            intent.putExtra("height", height);
            intent.putExtra("mode", PhotoMode.AVATAR);
            intent.putExtra("source", PhotoSource.CAMERA);
            intent.putExtra("output", cachePath);
            Photo.notifyResult = (status, statusMessage) -> {
                HashMap<String, Object> data = new HashMap<>();
                data.put("status", status);
                data.put("statusMessage", statusMessage);
                LuaJ.invoke(sCallback, "takeAvatar", data);
            };
            context.startActivity(intent);
        });
    }

    public static void selectAvatar(String cachePath, int width, int height) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            Intent intent = new Intent(context, Photo.class);
            intent.putExtra("width", width);
            intent.putExtra("height", height);
            intent.putExtra("mode", PhotoMode.AVATAR);
            intent.putExtra("source", PhotoSource.PHOTO_LIBRARY);
            intent.putExtra("output", cachePath);
            Photo.notifyResult = (status, statusMessage) -> {
                HashMap<String, Object> data = new HashMap<>();
                data.put("status", status);
                data.put("statusMessage", statusMessage);
                LuaJ.invoke(sCallback, "selectAvatar", data);
            };
            context.startActivity(intent);
        });
    }
}