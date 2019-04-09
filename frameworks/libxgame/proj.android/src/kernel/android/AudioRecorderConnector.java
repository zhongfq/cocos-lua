package kernel.android;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.util.Log;

import org.cocos2dx.lib.Cocos2dxActivity;

public class AudioRecorderConnector {
    private static final String TAG = AudioRecorderConnector.class.getSimpleName();

    private static AudioRecorder _record = null;

    public static boolean start(final String filename, final int callback) {
        if (_record != null) {
            Log.i(TAG, "only allow to run single instance");
            return false;
        }

        final AppContext context = (AppContext) Cocos2dxActivity.getContext();

        _record = new AudioRecorder(filename);
        _record.setStateListener(new AudioRecorder.StateListener() {
            @Override
            public void onStateChanged(final AudioRecorder.State state) {
                context.runOnGLThread(new Runnable() {
                    @Override
                    public void run() {
                        LuaJavaBridge.invoke(callback, state.name());
                        if (state != AudioRecorder.State.STARTED) {
                            _record = null;
                            LuaJavaBridge.unref(callback);
                        }
                    }
                });
            }
        });
        _record.startRecording();

        return true;
    }

    public static void stop() {
        if (_record != null) {
            _record.stopRecording();
            _record = null;
        }
    }

    public static void requestPermission(final int callback) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                int buffSize = AudioRecord.getMinBufferSize(AudioRecorder.SAMPLE_RATE,
                        AudioRecorder.AUDIO_CHANNEL, AudioRecorder.AUDIO_ENCODING);
                AudioRecord recorder = new AudioRecord(MediaRecorder.AudioSource.MIC,
                        AudioRecorder.SAMPLE_RATE, AudioRecorder.AUDIO_CHANNEL,
                        AudioRecorder.AUDIO_ENCODING, buffSize);

                boolean canRecord = false;

                try {
                    recorder.startRecording();
                } catch (IllegalStateException e){
                    e.printStackTrace();
                }

                if (recorder.getRecordingState() == AudioRecord.RECORDSTATE_RECORDING) {
                    canRecord = true;
                }

                recorder.release();

                final String granted = canRecord ? "true" : "false";
                final AppContext context = (AppContext) Cocos2dxActivity.getContext();

                if (!canRecord)
                {
                    context.runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            AlertDialog.Builder builder = new AlertDialog.Builder(context);
                            builder.setMessage("没有权限使用访问您的麦克风！");
                            builder.setPositiveButton("知道了", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialog, int which) {
                                    context.runOnGLThread(new Runnable() {
                                        @Override
                                        public void run() {
                                            LuaJavaBridge.invokeOnce(callback, granted);
                                        }
                                    });
                                }
                            });
                            builder.setCancelable(false);
                            builder.show();
                        }
                    });
                }
                else
                {
                    context.runOnGLThread(new Runnable() {
                        @Override
                        public void run() {
                            LuaJavaBridge.invokeOnce(callback, granted);
                        }
                    });
                }
            }
        }).start();
    }
}
