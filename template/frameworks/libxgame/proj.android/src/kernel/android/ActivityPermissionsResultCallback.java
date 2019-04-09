package kernel.android;

public interface ActivityPermissionsResultCallback {
    void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults);
}
