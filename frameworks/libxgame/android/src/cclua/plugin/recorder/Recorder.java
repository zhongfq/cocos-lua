package cclua.plugin.recorder;

import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.util.Log;

import org.cocos2dx.lib.Cocos2dxActivity;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import cclua.AppContext;
import cclua.LuaJ;

@SuppressWarnings("unused")
public class Recorder {
    public enum State {
        ERR_CREATE_FILE,
        ERR_PERMISSION,
        STARTED,
        STOPPED,
    }

    public interface StateListener {
        void onStateChanged(State state);
    }

    private static final int SAMPLE_RATE = 44100;
    private static final int AUDIO_ENCODING = AudioFormat.ENCODING_PCM_16BIT;
    private static final int AUDIO_CHANNEL = AudioFormat.CHANNEL_IN_MONO;

    private static final String TAG = Recorder.class.getSimpleName();

    private String _filename;
    private boolean _running = false;
    private StateListener _listener = null;

    private Recorder(String filename) {
        _filename = filename;
    }

    private void startRecording() {
        if (!_running) {
            _running = true;
            new Thread(new RecordTask()).start();
        }
    }

    private void stopRecording() {
        _running = false;
    }

    private void setStateListener(StateListener listener) {
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

    private static Recorder _record = null;

    public static boolean start(final String filename, final int callback) {
        if (_record != null) {
            Log.i(TAG, "only allow to run single instance");
            return false;
        }

        final AppContext context = (AppContext) Cocos2dxActivity.getContext();

        _record = new Recorder(filename);
        _record.setStateListener(new Recorder.StateListener() {
            @Override
            public void onStateChanged(final Recorder.State state) {
                if (state != Recorder.State.STARTED) {
                    _record = null;
                    LuaJ.invokeOnce(callback, state.name());
                } else {
                    LuaJ.invoke(callback, state.name());
                }
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
}