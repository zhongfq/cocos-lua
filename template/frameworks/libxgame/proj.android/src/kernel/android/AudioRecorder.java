package kernel.android;

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

public class AudioRecorder {
    public enum State {
        ERR_CREATE_FILE,
        ERR_PERMISSION,
        STARTED,
        STOPPED,
    }

    public interface StateListener {
        void onStateChanged(State state);
    }

    public static final int SAMPLE_RATE = 44100;
    public static final int AUDIO_ENCODING = AudioFormat.ENCODING_PCM_16BIT;
    public static final int AUDIO_CHANNEL = AudioFormat.CHANNEL_IN_MONO;

    private static final String TAG = AudioRecorder.class.getSimpleName();

    private String _filename;
    private boolean _running = false;
    private StateListener _listener = null;

    public AudioRecorder(String filename) {
        _filename = filename;
    }

    public void startRecording() {
        if (!_running) {
            _running = true;
            new Thread(new RecordTask()).start();
        }
    }

    public void stopRecording() {
        _running = false;
    }

    public void setStateListener(StateListener listener) {
        _listener = listener;
    }

    private class RecordTask implements Runnable {

        private DataOutputStream os = null;
        private AudioRecord audioRecord = null;

        private void close() {
            _running = false;
            if (os != null) {
                try {
                    os.flush();
                    os.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            if (audioRecord != null) {
                audioRecord.release();
            }
        }

        @Override
        public void run() {
            int buffSize = AudioRecord.getMinBufferSize(SAMPLE_RATE, AUDIO_CHANNEL, AUDIO_ENCODING);
            short[] buff = new short[buffSize / 2];
            File file = new File(_filename);

            try {
                os = new DataOutputStream(new BufferedOutputStream(new FileOutputStream(file)));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
                if (_listener != null) {
                    _listener.onStateChanged(State.ERR_CREATE_FILE);
                }
            }

            if (os == null) {
                close();
                return;
            }

            // dump pcm header
            for (int i = 0; i < 44; i++)
            {
                try {
                    os.write(0);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            audioRecord = new AudioRecord(MediaRecorder.AudioSource.MIC, SAMPLE_RATE,
                    AUDIO_CHANNEL, AUDIO_ENCODING, buffSize);

            if (audioRecord.getState() != AudioRecord.STATE_INITIALIZED) {
                Log.d(TAG, "can't not initialize audio record");
                close();
                if (_listener != null) {
                    _listener.onStateChanged(State.ERR_PERMISSION);
                }
                return;
            }

            audioRecord.startRecording();

            if (audioRecord.getRecordingState() != AudioRecord.RECORDSTATE_RECORDING) {
                Log.d(TAG, "permission deny");
                close();
                if (_listener != null) {
                    _listener.onStateChanged(State.ERR_PERMISSION);
                }
                return;
            }

            Log.d(TAG, "start record: " + file.getAbsolutePath());

            if (_listener != null) {
                _listener.onStateChanged(State.STARTED);
            }

            while (_running) {
                int len = audioRecord.read(buff, 0, buff.length);
                if (len > 0) {
                    try {
                        for (int i = 0; i < len; i++) {
                            os.write(buff[i] & 0xFF);
                            os.write(buff[i] >> 8 & 0xFF);

                            os.write(buff[i] & 0xFF);
                            os.write(buff[i] >> 8 & 0xFF);
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }

            close();

            if (_listener != null) {
                _listener.onStateChanged(State.STOPPED);
            }

            Log.d(TAG, "finish record");
        }
    }
}