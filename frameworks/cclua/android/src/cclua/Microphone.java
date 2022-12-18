package cclua;

import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.util.Log;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.HashMap;

@SuppressWarnings("unused")
public class Microphone {
    public interface StateListener {
        void onStateChanged(String status, String statusMessage);
    }

    private static final int SAMPLE_RATE = 44100;
    private static final int AUDIO_ENCODING = AudioFormat.ENCODING_PCM_16BIT;
    private static final int AUDIO_CHANNEL = AudioFormat.CHANNEL_IN_MONO;

    private static final String TAG = Microphone.class.getSimpleName();

    private final String mPath;
    private boolean mRunning = false;
    private StateListener mListener = null;

    private Microphone(String path) {
        mPath = path;
    }

    private void startRecording() {
        if (!mRunning) {
            mRunning = true;
            new Thread(new RecordTask()).start();
        }
    }

    private void stopRecording() {
        mRunning = false;
    }

    private void setStateListener(StateListener listener) {
        mListener = listener;
    }

    private class RecordTask implements Runnable {

        private DataOutputStream mDataStream = null;
        private AudioRecord mAudioRecord = null;

        private void close() {
            mRunning = false;
            if (mDataStream != null) {
                try {
                    mDataStream.flush();
                    mDataStream.close();
                    mDataStream = null;
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            if (mAudioRecord != null) {
                mAudioRecord.release();
                mAudioRecord = null;
            }
        }

        @Override
        public void run() {
            int buffSize = AudioRecord.getMinBufferSize(SAMPLE_RATE, AUDIO_CHANNEL, AUDIO_ENCODING);
            short[] buff = new short[buffSize / 2];
            File file = new File(mPath);

            try {
                mDataStream = new DataOutputStream(new BufferedOutputStream(new FileOutputStream(file)));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }

            if (mDataStream == null) {
                close();
                mListener.onStateChanged("ioerror", "write file error: " + mPath);
                return;
            }

            // dump pcm header
            for (int i = 0; i < 44; i++) {
                try {
                    mDataStream.write(0);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            mAudioRecord = new AudioRecord(MediaRecorder.AudioSource.MIC, SAMPLE_RATE,
                    AUDIO_CHANNEL, AUDIO_ENCODING, buffSize);

            if (mAudioRecord.getState() != AudioRecord.STATE_INITIALIZED) {
                close();
                mListener.onStateChanged("error", "init audio record error");
                return;
            }

            mAudioRecord.startRecording();

            if (mAudioRecord.getRecordingState() != AudioRecord.RECORDSTATE_RECORDING) {
                close();
                mListener.onStateChanged("error", "permission deny");
                return;
            }

            mListener.onStateChanged("started", "");

            while (mRunning) {
                int len = mAudioRecord.read(buff, 0, buff.length);
                if (len > 0) {
                    try {
                        for (int i = 0; i < len; i++) {
                            mDataStream.write(buff[i] & 0xFF);
                            mDataStream.write(buff[i] >> 8 & 0xFF);

                            mDataStream.write(buff[i] & 0xFF);
                            mDataStream.write(buff[i] >> 8 & 0xFF);
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }

            close();
        }
    }

    private static Microphone sMicrophone = null;
    private static long sCallback = 0;

    public static void setDispatcher(long callback) {
        sCallback = callback;
    }

    public static void start(String path) {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            if (sMicrophone != null) {
                Log.i(TAG, "only allow to run single instance");
                return;
            }

            sMicrophone = new Microphone(path);
            sMicrophone.setStateListener((status, statusMessage) -> {
                HashMap<String, Object> data = new HashMap<>();
                data.put("status", status);
                data.put("statusMessage", statusMessage);
                if (!"started".equals(status)) {
                    sMicrophone = null;
                }
                LuaJ.invoke(sCallback, "start", data);
            });
            sMicrophone.startRecording();
        });
    }

    public static void stop() {
        AppContext context = AppContext.getContext();
        context.runOnUiThread(() -> {
            if (sMicrophone != null) {
                sMicrophone.stopRecording();
                sMicrophone = null;
            }
        });
    }

    public static boolean isRunning() {
        return sMicrophone != null;
    }
}