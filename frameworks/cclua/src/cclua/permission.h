#ifndef __CCLUA_PERMISSION_H__
#define __CCLUA_PERMISSION_H__

#include "runtime.h"

NS_CCLUA_BEGIN

class permission {
public:
    // status
    class status {
    public:
        static const std::string UNKNOWN;
        static const std::string NOT_DETERMINED;
        static const std::string AUTHORIZED;
        static const std::string LIMITED;
        static const std::string ALWAYS;
        static const std::string WHEN_IN_USE;
        static const std::string RESTRICTED;
        static const std::string DENIED;
    };
    
    // permission
    static const std::string MICROPHONE;
    static const std::string CAMERA;
    static const std::string PHOTO;
    static const std::string TRACKING;
    static const std::string CALENDAR;
    static const std::string CONTACTS;
    static const std::string LOCATION;
    static const std::string PHONE;
    static const std::string SENSORS;
    static const std::string SMS;
    static const std::string STORAGE;
    
    // android permission
    class android {
    public:
        static const std::string ACCEPT_HANDOVER;
        static const std::string ACCESS_CHECKIN_PROPERTIES;
        static const std::string ACCESS_COARSE_LOCATION;
        static const std::string ACCESS_FINE_LOCATION;
        static const std::string ACCESS_LOCATION_EXTRA_COMMANDS;
        static const std::string ACCESS_NETWORK_STATE;
        static const std::string ACCESS_NOTIFICATION_POLICY;
        static const std::string ACCESS_WIFI_STATE;
        static const std::string ACCOUNT_MANAGER;
        static const std::string ADD_VOICEMAIL;
        static const std::string ANSWER_PHONE_CALLS;
        static const std::string BATTERY_STATS;
        static const std::string BIND_ACCESSIBILITY_SERVICE;
        static const std::string BIND_APPWIDGET;
        static const std::string BIND_AUTOFILL_SERVICE;
        static const std::string BIND_CARRIER_MESSAGING_SERVICE;
        static const std::string BIND_CARRIER_SERVICES;
        static const std::string BIND_CHOOSER_TARGET_SERVICE;
        static const std::string BIND_CONDITION_PROVIDER_SERVICE;
        static const std::string BIND_DEVICE_ADMIN;
        static const std::string BIND_DREAM_SERVICE;
        static const std::string BIND_INCALL_SERVICE;
        static const std::string BIND_INPUT_METHOD;
        static const std::string BIND_MIDI_DEVICE_SERVICE;
        static const std::string BIND_NFC_SERVICE;
        static const std::string BIND_NOTIFICATION_LISTENER_SERVICE;
        static const std::string BIND_PRINT_SERVICE;
        static const std::string BIND_QUICK_SETTINGS_TILE;
        static const std::string BIND_REMOTEVIEWS;
        static const std::string BIND_SCREENING_SERVICE;
        static const std::string BIND_TELECOM_CONNECTION_SERVICE;
        static const std::string BIND_TEXT_SERVICE;
        static const std::string BIND_TV_INPUT;
        static const std::string BIND_VISUAL_VOICEMAIL_SERVICE;
        static const std::string BIND_VOICE_INTERACTION;
        static const std::string BIND_VPN_SERVICE;
        static const std::string BIND_VR_LISTENER_SERVICE;
        static const std::string BIND_WALLPAPER;
        static const std::string BLUETOOTH;
        static const std::string BLUETOOTH_ADMIN;
        static const std::string BLUETOOTH_PRIVILEGED;
        static const std::string BODY_SENSORS;
        static const std::string BROADCAST_PACKAGE_REMOVED;
        static const std::string BROADCAST_SMS;
        static const std::string BROADCAST_STICKY;
        static const std::string BROADCAST_WAP_PUSH;
        static const std::string CALL_PHONE;
        static const std::string CALL_PRIVILEGED;
        static const std::string CAMERA;
        static const std::string CAPTURE_AUDIO_OUTPUT;
        static const std::string CAPTURE_SECURE_VIDEO_OUTPUT;
        static const std::string CAPTURE_VIDEO_OUTPUT;
        static const std::string CHANGE_COMPONENT_ENABLED_STATE;
        static const std::string CHANGE_CONFIGURATION;
        static const std::string CHANGE_NETWORK_STATE;
        static const std::string CHANGE_WIFI_MULTICAST_STATE;
        static const std::string CHANGE_WIFI_STATE;
        static const std::string CLEAR_APP_CACHE;
        static const std::string CONTROL_LOCATION_UPDATES;
        static const std::string DELETE_CACHE_FILES;
        static const std::string DELETE_PACKAGES;
        static const std::string DIAGNOSTIC;
        static const std::string DISABLE_KEYGUARD;
        static const std::string DUMP;
        static const std::string EXPAND_STATUS_BAR;
        static const std::string FACTORY_TEST;
        static const std::string FOREGROUND_SERVICE;
        static const std::string GET_ACCOUNTS;
        static const std::string GET_ACCOUNTS_PRIVILEGED;
        static const std::string GET_PACKAGE_SIZE;
        static const std::string GET_TASKS;
        static const std::string GLOBAL_SEARCH;
        static const std::string INSTALL_LOCATION_PROVIDER;
        static const std::string INSTALL_PACKAGES;
        static const std::string INSTALL_SHORTCUT;
        static const std::string INSTANT_APP_FOREGROUND_SERVICE;
        static const std::string INTERNET;
        static const std::string KILL_BACKGROUND_PROCESSES;
        static const std::string LOCATION_HARDWARE;
        static const std::string MANAGE_DOCUMENTS;
        static const std::string MANAGE_OWN_CALLS;
        static const std::string MASTER_CLEAR;
        static const std::string MEDIA_CONTENT_CONTROL;
        static const std::string MODIFY_AUDIO_SETTINGS;
        static const std::string MODIFY_PHONE_STATE;
        static const std::string MOUNT_FORMAT_FILESYSTEMS;
        static const std::string MOUNT_UNMOUNT_FILESYSTEMS;
        static const std::string NFC;
        static const std::string NFC_TRANSACTION_EVENT;
        static const std::string PACKAGE_USAGE_STATS;
        static const std::string PERSISTENT_ACTIVITY;
        static const std::string PROCESS_OUTGOING_CALLS;
        static const std::string READ_CALENDAR;
        static const std::string READ_CALL_LOG;
        static const std::string READ_CONTACTS;
        static const std::string READ_EXTERNAL_STORAGE;
        static const std::string READ_FRAME_BUFFER;
        static const std::string READ_INPUT_STATE;
        static const std::string READ_LOGS;
        static const std::string READ_PHONE_NUMBERS;
        static const std::string READ_PHONE_STATE;
        static const std::string READ_SMS;
        static const std::string READ_SYNC_SETTINGS;
        static const std::string READ_SYNC_STATS;
        static const std::string READ_VOICEMAIL;
        static const std::string REBOOT;
        static const std::string RECEIVE_BOOT_COMPLETED;
        static const std::string RECEIVE_MMS;
        static const std::string RECEIVE_SMS;
        static const std::string RECEIVE_WAP_PUSH;
        static const std::string RECORD_AUDIO;
        static const std::string REORDER_TASKS;
        static const std::string REQUEST_COMPANION_RUN_IN_BACKGROUND;
        static const std::string REQUEST_COMPANION_USE_DATA_IN_BACKGROUND;
        static const std::string REQUEST_DELETE_PACKAGES;
        static const std::string REQUEST_IGNORE_BATTERY_OPTIMIZATIONS;
        static const std::string REQUEST_INSTALL_PACKAGES;
        static const std::string RESTART_PACKAGES;
        static const std::string SEND_RESPOND_VIA_MESSAGE;
        static const std::string SEND_SMS;
        static const std::string SET_ALARM;
        static const std::string SET_ALWAYS_FINISH;
        static const std::string SET_ANIMATION_SCALE;
        static const std::string SET_DEBUG_APP;
        static const std::string SET_PREFERRED_APPLICATIONS;
        static const std::string SET_PROCESS_LIMIT;
        static const std::string SET_TIME;
        static const std::string SET_TIME_ZONE;
        static const std::string SET_WALLPAPER;
        static const std::string SET_WALLPAPER_HINTS;
        static const std::string SIGNAL_PERSISTENT_PROCESSES;
        static const std::string STATUS_BAR;
        static const std::string SYSTEM_ALERT_WINDOW;
        static const std::string TRANSMIT_IR;
        static const std::string UNINSTALL_SHORTCUT;
        static const std::string UPDATE_DEVICE_STATS;
        static const std::string USE_BIOMETRIC;
        static const std::string USE_FINGERPRINT;
        static const std::string USE_SIP;
        static const std::string VIBRATE;
        static const std::string WAKE_LOCK;
        static const std::string WRITE_APN_SETTINGS;
        static const std::string WRITE_CALENDAR;
        static const std::string WRITE_CALL_LOG;
        static const std::string WRITE_CONTACTS;
        static const std::string WRITE_EXTERNAL_STORAGE;
        static const std::string WRITE_GSERVICES;
        static const std::string WRITE_SECURE_SETTINGS;
        static const std::string WRITE_SETTINGS;
        static const std::string WRITE_SYNC_SETTINGS;
        static const std::string WRITE_VOICEMAIL;
    };
};

NS_CCLUA_END

#endif
