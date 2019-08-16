package org.cocos2dx.hellolua;

import android.os.Bundle;

import kernel.AppContext;
import kernel.PluginManager;

public class AppEntry extends AppContext {
    private static final String TAG = AppEntry.class.getSimpleName();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        PluginManager.start(this);
    }
}
