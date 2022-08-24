-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/xgame-types.lua"

name = "xgame"
path = "../../frameworks/libxgame/src/lua-bindings"
headers = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/cclua.h"
]]
chunk = [[
    int olua_unpack_cclua_window_Bounds(lua_State *L, const cclua::window::Bounds *value)
    {
        if (value) {
            lua_pushnumber(L, (lua_Number)value->getMinX());
            lua_pushnumber(L, (lua_Number)value->getMaxX());
            lua_pushnumber(L, (lua_Number)value->getMaxY());
            lua_pushnumber(L, (lua_Number)value->getMinY());
        } else {
            lua_pushnumber(L, 0);
            lua_pushnumber(L, 0);
            lua_pushnumber(L, 0);
            lua_pushnumber(L, 0);
        }
        return 4;
    }
]]
luaopen = nil


typeconf 'cclua::Callback'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)

typeconf 'cclua::Lame::VBRMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('vbr_off', 'cclua::Lame::VBRMode::vbr_off')
    .enum('vbr_mt', 'cclua::Lame::VBRMode::vbr_mt')
    .enum('vbr_rh', 'cclua::Lame::VBRMode::vbr_rh')
    .enum('vbr_abr', 'cclua::Lame::VBRMode::vbr_abr')
    .enum('vbr_mtrh', 'cclua::Lame::VBRMode::vbr_mtrh')
    .enum('vbr_max_indicator', 'cclua::Lame::VBRMode::vbr_max_indicator')
    .enum('vbr_default', 'cclua::Lame::VBRMode::vbr_default')

typeconf 'cclua::Lame'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'Lame()')
    .func(nil, 'void start(const std::string &pcmPath, const std::string &mp3Path)')
    .func(nil, 'void stop()')
    .func(nil, 'void cancel()')
    .func(nil, 'void initParams()')
    .func(nil, 'void setNumSamples(unsigned long value)')
    .func(nil, 'unsigned long getNumSamples()')
    .func(nil, 'void setInSamplerate(int value)')
    .func(nil, 'int getInSamplerate()')
    .func(nil, 'void setNumChannels(int value)')
    .func(nil, 'int getNumChannels()')
    .func(nil, 'void setScale(float value)')
    .func(nil, 'float getScale()')
    .func(nil, 'void setScaleLeft(float value)')
    .func(nil, 'float getScaleLeft()')
    .func(nil, 'void setScaleRight(float value)')
    .func(nil, 'float getScaleRight()')
    .func(nil, 'void setOutSamplerate(int value)')
    .func(nil, 'int getOutSamplerate()')
    .func(nil, 'void setAnalysis(int value)')
    .func(nil, 'int getAnalysis()')
    .func(nil, 'void setBWriteVbrTag(int value)')
    .func(nil, 'int getBWriteVbrTag()')
    .func(nil, 'void setDecodeOnly(int value)')
    .func(nil, 'int getDecodeOnly()')
    .func(nil, 'void setQuality(int value)')
    .func(nil, 'int getQuality()')
    .func(nil, 'void setMode(cclua::Lame::MPEGMode value)')
    .func(nil, 'cclua::Lame::MPEGMode getMode()')
    .func(nil, 'void setForceMs(int value)')
    .func(nil, 'int getForceMs()')
    .func(nil, 'void setFreeFormat(int value)')
    .func(nil, 'int getFreeFormat()')
    .func(nil, 'void setFindReplayGain(int value)')
    .func(nil, 'int getFindReplayGain()')
    .func(nil, 'void setDecodeOnTheFly(int value)')
    .func(nil, 'int getDecodeOnTheFly()')
    .func(nil, 'void setNogapTotal(int value)')
    .func(nil, 'int getNogapTotal()')
    .func(nil, 'void setNogapCurrentindex(int value)')
    .func(nil, 'int getNogapCurrentindex()')
    .func(nil, 'void setBrate(int value)')
    .func(nil, 'int getBrate()')
    .func(nil, 'void setCompressionRatio(float value)')
    .func(nil, 'float getCompressionRatio()')
    .func(nil, 'void setPreset(int preset)')
    .func(nil, 'void setAsmOptimizations(int optim, int mode)')
    .func(nil, 'void setCopyright(int value)')
    .func(nil, 'int getCopyright()')
    .func(nil, 'void setOriginal(int value)')
    .func(nil, 'int getOriginal()')
    .func(nil, 'void setErrorProtection(int value)')
    .func(nil, 'int getErrorProtection()')
    .func(nil, 'void setExtension(int value)')
    .func(nil, 'int getExtension()')
    .func(nil, 'void setStrictISO(int value)')
    .func(nil, 'int getStrictISO()')
    .func(nil, 'void setDisableReservoir(int value)')
    .func(nil, 'int getDisableReservoir()')
    .func(nil, 'void setQuantComp(int value)')
    .func(nil, 'int getQuantComp()')
    .func(nil, 'void setQuantCompShort(int value)')
    .func(nil, 'int getQuantCompShort()')
    .func(nil, 'void setExperimentalX(int value)')
    .func(nil, 'int getExperimentalX()')
    .func(nil, 'void setExperimentalY(int value)')
    .func(nil, 'int getExperimentalY()')
    .func(nil, 'void setExperimentalZ(int value)')
    .func(nil, 'int getExperimentalZ()')
    .func(nil, 'void setExpNspsytune(int value)')
    .func(nil, 'int getExpNspsytune()')
    .func(nil, 'void setMsfix(double value)')
    .func(nil, 'float getMsfix()')
    .func(nil, 'void setVBR(cclua::Lame::VBRMode value)')
    .func(nil, 'cclua::Lame::VBRMode getVBR()')
    .func(nil, 'void setVBRQ(int value)')
    .func(nil, 'int getVBRQ()')
    .func(nil, 'void setVBRQuality(float value)')
    .func(nil, 'float getVBRQuality()')
    .func(nil, 'void setVBRMeanBitrateKbps(int value)')
    .func(nil, 'int getVBRMeanBitrateKbps()')
    .func(nil, 'void setVBRMinBitrateKbps(int value)')
    .func(nil, 'int getVBRMinBitrateKbps()')
    .func(nil, 'void setVBRMaxBitrateKbps(int value)')
    .func(nil, 'int getVBRMaxBitrateKbps()')
    .func(nil, 'void setVBRHardMin(int value)')
    .func(nil, 'int getVBRHardMin()')
    .func(nil, 'void setLowpassfreq(int value)')
    .func(nil, 'int getLowpassfreq()')
    .func(nil, 'void setLowpasswidth(int value)')
    .func(nil, 'int getLowpasswidth()')
    .func(nil, 'void setHighpassfreq(int value)')
    .func(nil, 'int getHighpassfreq()')
    .func(nil, 'void setHighpasswidth(int value)')
    .func(nil, 'int getHighpasswidth()')
    .func(nil, 'void setATHonly(int value)')
    .func(nil, 'int getATHonly()')
    .func(nil, 'void setATHshort(int value)')
    .func(nil, 'int getATHshort()')
    .func(nil, 'void setNoATH(int value)')
    .func(nil, 'int getNoATH()')
    .func(nil, 'void setATHtype(int value)')
    .func(nil, 'int getATHtype()')
    .func(nil, 'void setATHlower(float value)')
    .func(nil, 'float getATHlower()')
    .func(nil, 'void setAthaaType(int value)')
    .func(nil, 'int getAthaaType()')
    .func(nil, 'void setAthaaSensitivity(float value)')
    .func(nil, 'float getAthaaSensitivity()')
    .func(nil, 'void setAllowDiffShort(int value)')
    .func(nil, 'int getAllowDiffShort()')
    .func(nil, 'void setUseTemporal(int value)')
    .func(nil, 'int getUseTemporal()')
    .func(nil, 'void setInterChRatio(float value)')
    .func(nil, 'float getInterChRatio()')
    .func(nil, 'void setNoShortBlocks(int value)')
    .func(nil, 'int getNoShortBlocks()')
    .func(nil, 'void setForceShortBlocks(int value)')
    .func(nil, 'int getForceShortBlocks()')
    .func(nil, 'void setEmphasis(int value)')
    .func(nil, 'int getEmphasis()')
    .func(nil, 'int getVersion()')
    .func(nil, 'int getEncoderDelay()')
    .func(nil, 'int getEncoderPadding()')
    .func(nil, 'int getFramesize()')
    .func(nil, 'int getMfSamplesToEncode()')
    .func(nil, 'int getSizeMp3buffer()')
    .func(nil, 'int getFrameNum()')
    .func(nil, 'int getTotalframes()')
    .func(nil, 'int getRadioGain()')
    .func(nil, 'int getAudiophileGain()')
    .func(nil, 'float getPeakSample()')
    .func(nil, 'int getNoclipGainChange()')
    .func(nil, 'float getNoclipScale()')
    .func(nil, 'const char *getLameVersion()')
    .func(nil, 'const char *getLameShortVersion()')
    .func(nil, 'const char *getLameVeryShortVersion()')
    .func(nil, 'const char *getPsyVersion()')
    .func(nil, 'const char *getLameUrl()')
    .func(nil, 'const char *getLameOsBitness()')
    .func(nil, 'void printConfig()')
    .func(nil, 'void printInternals()')
    .prop('numSamples', nil, nil)
    .prop('inSamplerate', nil, nil)
    .prop('numChannels', nil, nil)
    .prop('scale', nil, nil)
    .prop('scaleLeft', nil, nil)
    .prop('scaleRight', nil, nil)
    .prop('outSamplerate', nil, nil)
    .prop('analysis', nil, nil)
    .prop('bWriteVbrTag', nil, nil)
    .prop('decodeOnly', nil, nil)
    .prop('quality', nil, nil)
    .prop('mode', nil, nil)
    .prop('forceMs', nil, nil)
    .prop('freeFormat', nil, nil)
    .prop('findReplayGain', nil, nil)
    .prop('decodeOnTheFly', nil, nil)
    .prop('nogapTotal', nil, nil)
    .prop('nogapCurrentindex', nil, nil)
    .prop('brate', nil, nil)
    .prop('compressionRatio', nil, nil)
    .prop('copyright', nil, nil)
    .prop('original', nil, nil)
    .prop('errorProtection', nil, nil)
    .prop('extension', nil, nil)
    .prop('strictISO', nil, nil)
    .prop('disableReservoir', nil, nil)
    .prop('quantComp', nil, nil)
    .prop('quantCompShort', nil, nil)
    .prop('experimentalX', nil, nil)
    .prop('experimentalY', nil, nil)
    .prop('experimentalZ', nil, nil)
    .prop('expNspsytune', nil, nil)
    .prop('msfix', nil, nil)
    .prop('vbr', nil, nil)
    .prop('vbrq', nil, nil)
    .prop('vbrQuality', nil, nil)
    .prop('vbrMeanBitrateKbps', nil, nil)
    .prop('vbrMinBitrateKbps', nil, nil)
    .prop('vbrMaxBitrateKbps', nil, nil)
    .prop('vbrHardMin', nil, nil)
    .prop('lowpassfreq', nil, nil)
    .prop('lowpasswidth', nil, nil)
    .prop('highpassfreq', nil, nil)
    .prop('highpasswidth', nil, nil)
    .prop('atHonly', nil, nil)
    .prop('atHshort', nil, nil)
    .prop('noATH', nil, nil)
    .prop('atHtype', nil, nil)
    .prop('atHlower', nil, nil)
    .prop('athaaType', nil, nil)
    .prop('athaaSensitivity', nil, nil)
    .prop('allowDiffShort', nil, nil)
    .prop('useTemporal', nil, nil)
    .prop('interChRatio', nil, nil)
    .prop('noShortBlocks', nil, nil)
    .prop('forceShortBlocks', nil, nil)
    .prop('emphasis', nil, nil)
    .prop('version', nil, nil)
    .prop('encoderDelay', nil, nil)
    .prop('encoderPadding', nil, nil)
    .prop('framesize', nil, nil)
    .prop('mfSamplesToEncode', nil, nil)
    .prop('sizeMp3buffer', nil, nil)
    .prop('frameNum', nil, nil)
    .prop('totalframes', nil, nil)
    .prop('radioGain', nil, nil)
    .prop('audiophileGain', nil, nil)
    .prop('peakSample', nil, nil)
    .prop('noclipGainChange', nil, nil)
    .prop('noclipScale', nil, nil)
    .prop('lameVersion', nil, nil)
    .prop('lameShortVersion', nil, nil)
    .prop('lameVeryShortVersion', nil, nil)
    .prop('psyVersion', nil, nil)
    .prop('lameUrl', nil, nil)
    .prop('lameOsBitness', nil, nil)

typeconf 'cclua::QRCode::ECLevel'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('QR_ECLEVEL_L', 'cclua::QRCode::ECLevel::QR_ECLEVEL_L')
    .enum('QR_ECLEVEL_M', 'cclua::QRCode::ECLevel::QR_ECLEVEL_M')
    .enum('QR_ECLEVEL_Q', 'cclua::QRCode::ECLevel::QR_ECLEVEL_Q')
    .enum('QR_ECLEVEL_H', 'cclua::QRCode::ECLevel::QR_ECLEVEL_H')

typeconf 'cclua::QRCode::EncodeMode'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .enum('QR_MODE_NUL', 'cclua::QRCode::EncodeMode::QR_MODE_NUL')
    .enum('QR_MODE_NUM', 'cclua::QRCode::EncodeMode::QR_MODE_NUM')
    .enum('QR_MODE_AN', 'cclua::QRCode::EncodeMode::QR_MODE_AN')
    .enum('QR_MODE_8', 'cclua::QRCode::EncodeMode::QR_MODE_8')
    .enum('QR_MODE_KANJI', 'cclua::QRCode::EncodeMode::QR_MODE_KANJI')
    .enum('QR_MODE_STRUCTURE', 'cclua::QRCode::EncodeMode::QR_MODE_STRUCTURE')

typeconf 'cclua::QRCode'
    .supercls('cocos2d::Sprite')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static cclua::QRCode *create(const std::string &code, @optional int version, @optional cclua::QRCode::ECLevel level, @optional cclua::QRCode::EncodeMode hint, @optional bool casesensitive)')

typeconf 'cclua::SceneNoCamera'
    .supercls('cocos2d::Scene')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static cclua::SceneNoCamera *create()')
    .func(nil, 'static cclua::SceneNoCamera *createWithSize(const cocos2d::Size &size)')
    .func(nil, 'static cclua::SceneNoCamera *createWithPhysics()')
    .func(nil, 'SceneNoCamera()')

typeconf 'cclua::permission::status'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .const('UNKNOWN', 'cclua::permission::status::UNKNOWN', 'const std::string')
    .const('NOT_DETERMINED', 'cclua::permission::status::NOT_DETERMINED', 'const std::string')
    .const('AUTHORIZED', 'cclua::permission::status::AUTHORIZED', 'const std::string')
    .const('LIMITED', 'cclua::permission::status::LIMITED', 'const std::string')
    .const('ALWAYS', 'cclua::permission::status::ALWAYS', 'const std::string')
    .const('WHEN_IN_USE', 'cclua::permission::status::WHEN_IN_USE', 'const std::string')
    .const('RESTRICTED', 'cclua::permission::status::RESTRICTED', 'const std::string')
    .const('DENIED', 'cclua::permission::status::DENIED', 'const std::string')

typeconf 'cclua::permission::android'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .const('ACCEPT_HANDOVER', 'cclua::permission::android::ACCEPT_HANDOVER', 'const std::string')
    .const('ACCESS_CHECKIN_PROPERTIES', 'cclua::permission::android::ACCESS_CHECKIN_PROPERTIES', 'const std::string')
    .const('ACCESS_COARSE_LOCATION', 'cclua::permission::android::ACCESS_COARSE_LOCATION', 'const std::string')
    .const('ACCESS_FINE_LOCATION', 'cclua::permission::android::ACCESS_FINE_LOCATION', 'const std::string')
    .const('ACCESS_LOCATION_EXTRA_COMMANDS', 'cclua::permission::android::ACCESS_LOCATION_EXTRA_COMMANDS', 'const std::string')
    .const('ACCESS_NETWORK_STATE', 'cclua::permission::android::ACCESS_NETWORK_STATE', 'const std::string')
    .const('ACCESS_NOTIFICATION_POLICY', 'cclua::permission::android::ACCESS_NOTIFICATION_POLICY', 'const std::string')
    .const('ACCESS_WIFI_STATE', 'cclua::permission::android::ACCESS_WIFI_STATE', 'const std::string')
    .const('ACCOUNT_MANAGER', 'cclua::permission::android::ACCOUNT_MANAGER', 'const std::string')
    .const('ADD_VOICEMAIL', 'cclua::permission::android::ADD_VOICEMAIL', 'const std::string')
    .const('ANSWER_PHONE_CALLS', 'cclua::permission::android::ANSWER_PHONE_CALLS', 'const std::string')
    .const('BATTERY_STATS', 'cclua::permission::android::BATTERY_STATS', 'const std::string')
    .const('BIND_ACCESSIBILITY_SERVICE', 'cclua::permission::android::BIND_ACCESSIBILITY_SERVICE', 'const std::string')
    .const('BIND_APPWIDGET', 'cclua::permission::android::BIND_APPWIDGET', 'const std::string')
    .const('BIND_AUTOFILL_SERVICE', 'cclua::permission::android::BIND_AUTOFILL_SERVICE', 'const std::string')
    .const('BIND_CARRIER_MESSAGING_SERVICE', 'cclua::permission::android::BIND_CARRIER_MESSAGING_SERVICE', 'const std::string')
    .const('BIND_CARRIER_SERVICES', 'cclua::permission::android::BIND_CARRIER_SERVICES', 'const std::string')
    .const('BIND_CHOOSER_TARGET_SERVICE', 'cclua::permission::android::BIND_CHOOSER_TARGET_SERVICE', 'const std::string')
    .const('BIND_CONDITION_PROVIDER_SERVICE', 'cclua::permission::android::BIND_CONDITION_PROVIDER_SERVICE', 'const std::string')
    .const('BIND_DEVICE_ADMIN', 'cclua::permission::android::BIND_DEVICE_ADMIN', 'const std::string')
    .const('BIND_DREAM_SERVICE', 'cclua::permission::android::BIND_DREAM_SERVICE', 'const std::string')
    .const('BIND_INCALL_SERVICE', 'cclua::permission::android::BIND_INCALL_SERVICE', 'const std::string')
    .const('BIND_INPUT_METHOD', 'cclua::permission::android::BIND_INPUT_METHOD', 'const std::string')
    .const('BIND_MIDI_DEVICE_SERVICE', 'cclua::permission::android::BIND_MIDI_DEVICE_SERVICE', 'const std::string')
    .const('BIND_NFC_SERVICE', 'cclua::permission::android::BIND_NFC_SERVICE', 'const std::string')
    .const('BIND_NOTIFICATION_LISTENER_SERVICE', 'cclua::permission::android::BIND_NOTIFICATION_LISTENER_SERVICE', 'const std::string')
    .const('BIND_PRINT_SERVICE', 'cclua::permission::android::BIND_PRINT_SERVICE', 'const std::string')
    .const('BIND_QUICK_SETTINGS_TILE', 'cclua::permission::android::BIND_QUICK_SETTINGS_TILE', 'const std::string')
    .const('BIND_REMOTEVIEWS', 'cclua::permission::android::BIND_REMOTEVIEWS', 'const std::string')
    .const('BIND_SCREENING_SERVICE', 'cclua::permission::android::BIND_SCREENING_SERVICE', 'const std::string')
    .const('BIND_TELECOM_CONNECTION_SERVICE', 'cclua::permission::android::BIND_TELECOM_CONNECTION_SERVICE', 'const std::string')
    .const('BIND_TEXT_SERVICE', 'cclua::permission::android::BIND_TEXT_SERVICE', 'const std::string')
    .const('BIND_TV_INPUT', 'cclua::permission::android::BIND_TV_INPUT', 'const std::string')
    .const('BIND_VISUAL_VOICEMAIL_SERVICE', 'cclua::permission::android::BIND_VISUAL_VOICEMAIL_SERVICE', 'const std::string')
    .const('BIND_VOICE_INTERACTION', 'cclua::permission::android::BIND_VOICE_INTERACTION', 'const std::string')
    .const('BIND_VPN_SERVICE', 'cclua::permission::android::BIND_VPN_SERVICE', 'const std::string')
    .const('BIND_VR_LISTENER_SERVICE', 'cclua::permission::android::BIND_VR_LISTENER_SERVICE', 'const std::string')
    .const('BIND_WALLPAPER', 'cclua::permission::android::BIND_WALLPAPER', 'const std::string')
    .const('BLUETOOTH', 'cclua::permission::android::BLUETOOTH', 'const std::string')
    .const('BLUETOOTH_ADMIN', 'cclua::permission::android::BLUETOOTH_ADMIN', 'const std::string')
    .const('BLUETOOTH_PRIVILEGED', 'cclua::permission::android::BLUETOOTH_PRIVILEGED', 'const std::string')
    .const('BODY_SENSORS', 'cclua::permission::android::BODY_SENSORS', 'const std::string')
    .const('BROADCAST_PACKAGE_REMOVED', 'cclua::permission::android::BROADCAST_PACKAGE_REMOVED', 'const std::string')
    .const('BROADCAST_SMS', 'cclua::permission::android::BROADCAST_SMS', 'const std::string')
    .const('BROADCAST_STICKY', 'cclua::permission::android::BROADCAST_STICKY', 'const std::string')
    .const('BROADCAST_WAP_PUSH', 'cclua::permission::android::BROADCAST_WAP_PUSH', 'const std::string')
    .const('CALL_PHONE', 'cclua::permission::android::CALL_PHONE', 'const std::string')
    .const('CALL_PRIVILEGED', 'cclua::permission::android::CALL_PRIVILEGED', 'const std::string')
    .const('CAMERA', 'cclua::permission::android::CAMERA', 'const std::string')
    .const('CAPTURE_AUDIO_OUTPUT', 'cclua::permission::android::CAPTURE_AUDIO_OUTPUT', 'const std::string')
    .const('CAPTURE_SECURE_VIDEO_OUTPUT', 'cclua::permission::android::CAPTURE_SECURE_VIDEO_OUTPUT', 'const std::string')
    .const('CAPTURE_VIDEO_OUTPUT', 'cclua::permission::android::CAPTURE_VIDEO_OUTPUT', 'const std::string')
    .const('CHANGE_COMPONENT_ENABLED_STATE', 'cclua::permission::android::CHANGE_COMPONENT_ENABLED_STATE', 'const std::string')
    .const('CHANGE_CONFIGURATION', 'cclua::permission::android::CHANGE_CONFIGURATION', 'const std::string')
    .const('CHANGE_NETWORK_STATE', 'cclua::permission::android::CHANGE_NETWORK_STATE', 'const std::string')
    .const('CHANGE_WIFI_MULTICAST_STATE', 'cclua::permission::android::CHANGE_WIFI_MULTICAST_STATE', 'const std::string')
    .const('CHANGE_WIFI_STATE', 'cclua::permission::android::CHANGE_WIFI_STATE', 'const std::string')
    .const('CLEAR_APP_CACHE', 'cclua::permission::android::CLEAR_APP_CACHE', 'const std::string')
    .const('CONTROL_LOCATION_UPDATES', 'cclua::permission::android::CONTROL_LOCATION_UPDATES', 'const std::string')
    .const('DELETE_CACHE_FILES', 'cclua::permission::android::DELETE_CACHE_FILES', 'const std::string')
    .const('DELETE_PACKAGES', 'cclua::permission::android::DELETE_PACKAGES', 'const std::string')
    .const('DIAGNOSTIC', 'cclua::permission::android::DIAGNOSTIC', 'const std::string')
    .const('DISABLE_KEYGUARD', 'cclua::permission::android::DISABLE_KEYGUARD', 'const std::string')
    .const('DUMP', 'cclua::permission::android::DUMP', 'const std::string')
    .const('EXPAND_STATUS_BAR', 'cclua::permission::android::EXPAND_STATUS_BAR', 'const std::string')
    .const('FACTORY_TEST', 'cclua::permission::android::FACTORY_TEST', 'const std::string')
    .const('FOREGROUND_SERVICE', 'cclua::permission::android::FOREGROUND_SERVICE', 'const std::string')
    .const('GET_ACCOUNTS', 'cclua::permission::android::GET_ACCOUNTS', 'const std::string')
    .const('GET_ACCOUNTS_PRIVILEGED', 'cclua::permission::android::GET_ACCOUNTS_PRIVILEGED', 'const std::string')
    .const('GET_PACKAGE_SIZE', 'cclua::permission::android::GET_PACKAGE_SIZE', 'const std::string')
    .const('GET_TASKS', 'cclua::permission::android::GET_TASKS', 'const std::string')
    .const('GLOBAL_SEARCH', 'cclua::permission::android::GLOBAL_SEARCH', 'const std::string')
    .const('INSTALL_LOCATION_PROVIDER', 'cclua::permission::android::INSTALL_LOCATION_PROVIDER', 'const std::string')
    .const('INSTALL_PACKAGES', 'cclua::permission::android::INSTALL_PACKAGES', 'const std::string')
    .const('INSTALL_SHORTCUT', 'cclua::permission::android::INSTALL_SHORTCUT', 'const std::string')
    .const('INSTANT_APP_FOREGROUND_SERVICE', 'cclua::permission::android::INSTANT_APP_FOREGROUND_SERVICE', 'const std::string')
    .const('INTERNET', 'cclua::permission::android::INTERNET', 'const std::string')
    .const('KILL_BACKGROUND_PROCESSES', 'cclua::permission::android::KILL_BACKGROUND_PROCESSES', 'const std::string')
    .const('LOCATION_HARDWARE', 'cclua::permission::android::LOCATION_HARDWARE', 'const std::string')
    .const('MANAGE_DOCUMENTS', 'cclua::permission::android::MANAGE_DOCUMENTS', 'const std::string')
    .const('MANAGE_OWN_CALLS', 'cclua::permission::android::MANAGE_OWN_CALLS', 'const std::string')
    .const('MASTER_CLEAR', 'cclua::permission::android::MASTER_CLEAR', 'const std::string')
    .const('MEDIA_CONTENT_CONTROL', 'cclua::permission::android::MEDIA_CONTENT_CONTROL', 'const std::string')
    .const('MODIFY_AUDIO_SETTINGS', 'cclua::permission::android::MODIFY_AUDIO_SETTINGS', 'const std::string')
    .const('MODIFY_PHONE_STATE', 'cclua::permission::android::MODIFY_PHONE_STATE', 'const std::string')
    .const('MOUNT_FORMAT_FILESYSTEMS', 'cclua::permission::android::MOUNT_FORMAT_FILESYSTEMS', 'const std::string')
    .const('MOUNT_UNMOUNT_FILESYSTEMS', 'cclua::permission::android::MOUNT_UNMOUNT_FILESYSTEMS', 'const std::string')
    .const('NFC', 'cclua::permission::android::NFC', 'const std::string')
    .const('NFC_TRANSACTION_EVENT', 'cclua::permission::android::NFC_TRANSACTION_EVENT', 'const std::string')
    .const('PACKAGE_USAGE_STATS', 'cclua::permission::android::PACKAGE_USAGE_STATS', 'const std::string')
    .const('PERSISTENT_ACTIVITY', 'cclua::permission::android::PERSISTENT_ACTIVITY', 'const std::string')
    .const('PROCESS_OUTGOING_CALLS', 'cclua::permission::android::PROCESS_OUTGOING_CALLS', 'const std::string')
    .const('READ_CALENDAR', 'cclua::permission::android::READ_CALENDAR', 'const std::string')
    .const('READ_CALL_LOG', 'cclua::permission::android::READ_CALL_LOG', 'const std::string')
    .const('READ_CONTACTS', 'cclua::permission::android::READ_CONTACTS', 'const std::string')
    .const('READ_EXTERNAL_STORAGE', 'cclua::permission::android::READ_EXTERNAL_STORAGE', 'const std::string')
    .const('READ_FRAME_BUFFER', 'cclua::permission::android::READ_FRAME_BUFFER', 'const std::string')
    .const('READ_INPUT_STATE', 'cclua::permission::android::READ_INPUT_STATE', 'const std::string')
    .const('READ_LOGS', 'cclua::permission::android::READ_LOGS', 'const std::string')
    .const('READ_PHONE_NUMBERS', 'cclua::permission::android::READ_PHONE_NUMBERS', 'const std::string')
    .const('READ_PHONE_STATE', 'cclua::permission::android::READ_PHONE_STATE', 'const std::string')
    .const('READ_SMS', 'cclua::permission::android::READ_SMS', 'const std::string')
    .const('READ_SYNC_SETTINGS', 'cclua::permission::android::READ_SYNC_SETTINGS', 'const std::string')
    .const('READ_SYNC_STATS', 'cclua::permission::android::READ_SYNC_STATS', 'const std::string')
    .const('READ_VOICEMAIL', 'cclua::permission::android::READ_VOICEMAIL', 'const std::string')
    .const('REBOOT', 'cclua::permission::android::REBOOT', 'const std::string')
    .const('RECEIVE_BOOT_COMPLETED', 'cclua::permission::android::RECEIVE_BOOT_COMPLETED', 'const std::string')
    .const('RECEIVE_MMS', 'cclua::permission::android::RECEIVE_MMS', 'const std::string')
    .const('RECEIVE_SMS', 'cclua::permission::android::RECEIVE_SMS', 'const std::string')
    .const('RECEIVE_WAP_PUSH', 'cclua::permission::android::RECEIVE_WAP_PUSH', 'const std::string')
    .const('RECORD_AUDIO', 'cclua::permission::android::RECORD_AUDIO', 'const std::string')
    .const('REORDER_TASKS', 'cclua::permission::android::REORDER_TASKS', 'const std::string')
    .const('REQUEST_COMPANION_RUN_IN_BACKGROUND', 'cclua::permission::android::REQUEST_COMPANION_RUN_IN_BACKGROUND', 'const std::string')
    .const('REQUEST_COMPANION_USE_DATA_IN_BACKGROUND', 'cclua::permission::android::REQUEST_COMPANION_USE_DATA_IN_BACKGROUND', 'const std::string')
    .const('REQUEST_DELETE_PACKAGES', 'cclua::permission::android::REQUEST_DELETE_PACKAGES', 'const std::string')
    .const('REQUEST_IGNORE_BATTERY_OPTIMIZATIONS', 'cclua::permission::android::REQUEST_IGNORE_BATTERY_OPTIMIZATIONS', 'const std::string')
    .const('REQUEST_INSTALL_PACKAGES', 'cclua::permission::android::REQUEST_INSTALL_PACKAGES', 'const std::string')
    .const('RESTART_PACKAGES', 'cclua::permission::android::RESTART_PACKAGES', 'const std::string')
    .const('SEND_RESPOND_VIA_MESSAGE', 'cclua::permission::android::SEND_RESPOND_VIA_MESSAGE', 'const std::string')
    .const('SEND_SMS', 'cclua::permission::android::SEND_SMS', 'const std::string')
    .const('SET_ALARM', 'cclua::permission::android::SET_ALARM', 'const std::string')
    .const('SET_ALWAYS_FINISH', 'cclua::permission::android::SET_ALWAYS_FINISH', 'const std::string')
    .const('SET_ANIMATION_SCALE', 'cclua::permission::android::SET_ANIMATION_SCALE', 'const std::string')
    .const('SET_DEBUG_APP', 'cclua::permission::android::SET_DEBUG_APP', 'const std::string')
    .const('SET_PREFERRED_APPLICATIONS', 'cclua::permission::android::SET_PREFERRED_APPLICATIONS', 'const std::string')
    .const('SET_PROCESS_LIMIT', 'cclua::permission::android::SET_PROCESS_LIMIT', 'const std::string')
    .const('SET_TIME', 'cclua::permission::android::SET_TIME', 'const std::string')
    .const('SET_TIME_ZONE', 'cclua::permission::android::SET_TIME_ZONE', 'const std::string')
    .const('SET_WALLPAPER', 'cclua::permission::android::SET_WALLPAPER', 'const std::string')
    .const('SET_WALLPAPER_HINTS', 'cclua::permission::android::SET_WALLPAPER_HINTS', 'const std::string')
    .const('SIGNAL_PERSISTENT_PROCESSES', 'cclua::permission::android::SIGNAL_PERSISTENT_PROCESSES', 'const std::string')
    .const('STATUS_BAR', 'cclua::permission::android::STATUS_BAR', 'const std::string')
    .const('SYSTEM_ALERT_WINDOW', 'cclua::permission::android::SYSTEM_ALERT_WINDOW', 'const std::string')
    .const('TRANSMIT_IR', 'cclua::permission::android::TRANSMIT_IR', 'const std::string')
    .const('UNINSTALL_SHORTCUT', 'cclua::permission::android::UNINSTALL_SHORTCUT', 'const std::string')
    .const('UPDATE_DEVICE_STATS', 'cclua::permission::android::UPDATE_DEVICE_STATS', 'const std::string')
    .const('USE_BIOMETRIC', 'cclua::permission::android::USE_BIOMETRIC', 'const std::string')
    .const('USE_FINGERPRINT', 'cclua::permission::android::USE_FINGERPRINT', 'const std::string')
    .const('USE_SIP', 'cclua::permission::android::USE_SIP', 'const std::string')
    .const('VIBRATE', 'cclua::permission::android::VIBRATE', 'const std::string')
    .const('WAKE_LOCK', 'cclua::permission::android::WAKE_LOCK', 'const std::string')
    .const('WRITE_APN_SETTINGS', 'cclua::permission::android::WRITE_APN_SETTINGS', 'const std::string')
    .const('WRITE_CALENDAR', 'cclua::permission::android::WRITE_CALENDAR', 'const std::string')
    .const('WRITE_CALL_LOG', 'cclua::permission::android::WRITE_CALL_LOG', 'const std::string')
    .const('WRITE_CONTACTS', 'cclua::permission::android::WRITE_CONTACTS', 'const std::string')
    .const('WRITE_EXTERNAL_STORAGE', 'cclua::permission::android::WRITE_EXTERNAL_STORAGE', 'const std::string')
    .const('WRITE_GSERVICES', 'cclua::permission::android::WRITE_GSERVICES', 'const std::string')
    .const('WRITE_SECURE_SETTINGS', 'cclua::permission::android::WRITE_SECURE_SETTINGS', 'const std::string')
    .const('WRITE_SETTINGS', 'cclua::permission::android::WRITE_SETTINGS', 'const std::string')
    .const('WRITE_SYNC_SETTINGS', 'cclua::permission::android::WRITE_SYNC_SETTINGS', 'const std::string')
    .const('WRITE_VOICEMAIL', 'cclua::permission::android::WRITE_VOICEMAIL', 'const std::string')

typeconf 'cclua::permission'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror('rw')
    .const('MICROPHONE', 'cclua::permission::MICROPHONE', 'const std::string')
    .const('CAMERA', 'cclua::permission::CAMERA', 'const std::string')
    .const('PHOTO', 'cclua::permission::PHOTO', 'const std::string')
    .const('TRACKING', 'cclua::permission::TRACKING', 'const std::string')
    .const('CALENDAR', 'cclua::permission::CALENDAR', 'const std::string')
    .const('CONTACTS', 'cclua::permission::CONTACTS', 'const std::string')
    .const('LOCATION', 'cclua::permission::LOCATION', 'const std::string')
    .const('PHONE', 'cclua::permission::PHONE', 'const std::string')
    .const('SENSORS', 'cclua::permission::SENSORS', 'const std::string')
    .const('SMS', 'cclua::permission::SMS', 'const std::string')
    .const('STORAGE', 'cclua::permission::STORAGE', 'const std::string')
    .prop('status', [[
        {
            lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
            lua_getfield(L, -1, "cclua.permission.status");
            return 1;
        }
    ]], nil)
    .prop('android', [[
        {
            lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
            lua_getfield(L, -1, "cclua.permission.android");
            return 1;
        }
    ]], nil)

typeconf 'cclua::runtime'
    .supercls(nil)
    .reg_luatype(true)
    .chunk([[
        static int _cclua_runtime_load_index_func(lua_State *L)
        {
            if (olua_isstring(L, lua_upvalueindex(2))) {
                const char *name = olua_tostring(L, lua_upvalueindex(1));
                const char *func = olua_tostring(L, lua_upvalueindex(2));
                cclua::runtime::log("function '%s.%s' not supported", name, func);
                return 0;
            } else {
                const char *func = olua_tostring(L, 2);
                lua_pushvalue(L, lua_upvalueindex(1));
                lua_pushstring(L, func);
                lua_pushcclosure(L, _cclua_runtime_load_index_func, 2);
                return 1;
            }
        }
    ]])
    .luaopen(nil)
    .indexerror(nil)
    .func('testCrash', [[
        {
            cclua::runtime::log("test native crash!!!!");
            char *prt = NULL;
            *prt = 0;
            return 0;
        }
    ]])
    .func('load', [[
        {
            const char *name = olua_checkstring(L, 1);
            if (cclua::runtime::hasFeature(name)) {
                lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
                if (olua_rawgetf(L, -1, name) == LUA_TTABLE) {
                    return 1;
                }
            }

            cclua::runtime::log("module '%s' is not available", name);
            lua_newtable(L);
            lua_newtable(L);
            lua_pushvalue(L, 1);
            lua_pushcclosure(L, _cclua_runtime_load_index_func, 1);
            olua_rawsetf(L, -2, "__index");
            lua_setmetatable(L, -2);
            lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
            lua_pushvalue(L, 1);
            lua_pushvalue(L, -3);
            lua_rawset(L, -3);
            lua_pop(L, 1);
            return 1;
        }
    ]])
    .func(nil, 'static void clearStorage()')
    .func(nil, 'static bool launch(const std::string &scriptPath)')
    .func(nil, 'static bool restart()')
    .func(nil, 'static bool isRestarting()')
    .func(nil, 'static bool isDebug()')
    .func(nil, 'static float getTime()')
    .func(nil, 'static void gc()')
    .func(nil, 'static std::string getVersion()')
    .func(nil, 'static uint64_t getCocosVersion()')
    .func(nil, 'static std::string getPackageName()')
    .func(nil, 'static std::string getAppName()')
    .func(nil, 'static std::string getAppVersion()')
    .func(nil, 'static std::string getAppBuild()')
    .func(nil, 'static std::string getChannel()')
    .func(nil, 'static std::string getOS()')
    .func(nil, 'static std::string getDeviceInfo()')
    .func(nil, 'static std::string getLanguage()')
    .func(nil, 'static std::string getManifestVersion()')
    .func(nil, 'static void setManifestVersion(const std::string &version)')
    .func(nil, 'static std::string getNetworkStatus()')
    .func(nil, 'static std::string getEnv(const std::string &key)')
    .func(nil, 'static void setEnv(const std::string &key, const std::string &value, @optional bool save)')
    .func(nil, 'static std::string getPaste()')
    .func(nil, 'static void setPaste(const std::string &text)')
    .func(nil, 'static cocos2d::Sprite *capture(cocos2d::Node *node, float width, float height, @optional float scale, @optional cocos2d::Texture2D::PixelFormat format, @optional GLuint depthStencilFormat)')
    .func(nil, 'static uint32_t getMaxFrameRate()')
    .func(nil, 'static uint32_t getFrameRate()')
    .func(nil, 'static void setFrameRate(uint32_t frameRate)')
    .func(nil, 'static std::string getPermission(const std::string &permission)')
    .func(nil, 'static void setAudioSessionCatalog(const std::string &catalog)')
    .func(nil, 'static std::string getAudioSessionCatalog()')
    .func(nil, 'static bool canOpenURL(const std::string &uri)')
    .func(nil, 'static void installAPK(const std::string &path)')
    .func(nil, 'static void setLogPath(const std::string &path)')
    .func(nil, 'static std::string getLogPath()')
    .func(nil, 'static void showLog()')
    .func(nil, 'static void setSampleCount(unsigned int samples)')
    .func(nil, 'static unsigned int getSampleCount()')
    .func(nil, 'static bool hasFeature(const std::string &api)')
    .func(nil, 'static void printFeatures()')
    .func(nil, 'static void disableReport()')
    .func(nil, '@addref(programCache ^ director) static cocos2d::GLProgramCache *getProgramCache()')
    .func(nil, '@addref(fileUtils ^ director) static cocos2d::FileUtils *getFileUtils()')
    .func(nil, '@addref(spriteFrameCache ^ director) static cocos2d::SpriteFrameCache *getSpriteFrameCache()')
    .func(nil, '@addref(textureCache ^ director) static cocos2d::TextureCache *getTextureCache()')
    .func(nil, '@addref(scheduler ^ director) static cocos2d::Scheduler *getScheduler()')
    .func(nil, '@addref(actionManager ^ director) static cocos2d::ActionManager *getActionManager()')
    .func(nil, '@addref(eventDispatcher ^ director) static cocos2d::EventDispatcher *getEventDispatcher()')
    .func(nil, 'static bool isDisplayStats()')
    .func(nil, 'static void setDisplayStats(bool displayStats)')
    .func(nil, '@addref(scenes | director) static cocos2d::Scene *getRunningScene()')
    .func(nil, 'static void pushScene(@addref(scenes | director) cocos2d::Scene *scene)')
    .func(nil, '@delref(scenes ~ director) static void replaceScene(@addref(scenes | director) cocos2d::Scene *scene)')
    .func(nil, '@delref(scenes ~ director) static void popScene()')
    .func(nil, '@delref(scenes ~ director) static void popToRootScene()')
    .func(nil, 'static void purgeCachedData()')
    .func(nil, 'static void exit()')
    .callback {
        funcs =  {
            'static void setDispatcher(@localvar const cclua::Callback &dispatcher)'
        },
        tag_maker = 'Dispatcher',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'static void openURL(const std::string &uri, @localvar @optional const std::function<void (bool)> callback)'
        },
        tag_maker = 'openURL',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void requestPermission(const std::string &permission, @localvar const std::function<void (const std::string &)> callback)'
        },
        tag_maker = 'requestPermission',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, @localvar const std::function<void (bool)> callback)'
        },
        tag_maker = 'alert',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .prop('restarting', nil, nil)
    .prop('debug', nil, nil)
    .prop('time', nil, nil)
    .prop('version', nil, nil)
    .prop('cocosVersion', nil, nil)
    .prop('packageName', nil, nil)
    .prop('appName', nil, nil)
    .prop('appVersion', nil, nil)
    .prop('appBuild', nil, nil)
    .prop('channel', nil, nil)
    .prop('os', nil, nil)
    .prop('deviceInfo', nil, nil)
    .prop('language', nil, nil)
    .prop('manifestVersion', nil, nil)
    .prop('networkStatus', nil, nil)
    .prop('paste', nil, nil)
    .prop('maxFrameRate', nil, nil)
    .prop('frameRate', nil, nil)
    .prop('audioSessionCatalog', nil, nil)
    .prop('logPath', nil, nil)
    .prop('sampleCount', nil, nil)
    .prop('programCache', nil, nil)
    .prop('fileUtils', nil, nil)
    .prop('spriteFrameCache', nil, nil)
    .prop('textureCache', nil, nil)
    .prop('scheduler', nil, nil)
    .prop('actionManager', nil, nil)
    .prop('eventDispatcher', nil, nil)
    .prop('displayStats', nil, nil)
    .prop('runningScene', nil, nil)
    .insert('getProgramCache', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getFileUtils', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getSpriteFrameCache', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getTextureCache', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getScheduler', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getActionManager', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getEventDispatcher', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getRunningScene', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('pushScene', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('replaceScene', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('popScene', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('popToRootScene', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })

typeconf 'cclua::filesystem'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static std::string getWritablePath()')
    .func(nil, 'static std::string getCacheDirectory()')
    .func(nil, 'static std::string getDocumentDirectory()')
    .func(nil, 'static std::string getTmpDirectory()')
    .func(nil, 'static std::string getBuiltinCacheDirectory()')
    .func(nil, 'static std::string getSDCardDirectory()')
    .func(nil, 'static void addSearchPath(const std::string &path, @optional bool front)')
    .func(nil, 'static std::string trimPath(const std::string &path, @optional size_t limit)')
    .func(nil, 'static std::string fullPath(const std::string &path)')
    .func(nil, 'static bool createDirectory(const std::string &path, @optional bool isFilePath)')
    .func(nil, 'static bool remove(const std::string &path)')
    .func(nil, 'static bool exist(const std::string &path)')
    .func(nil, 'static bool isFile(const std::string &path)')
    .func(nil, 'static bool isDirectory(const std::string &path)')
    .func(nil, 'static bool isAbsolutePath(const std::string &path)')
    .func(nil, 'static bool rename(const std::string &oldPath, const std::string &newPath)')
    .func(nil, 'static bool copy(const std::string &srcPath, const std::string &destPath)')
    .func(nil, 'static bool write(const std::string &path, const char *data, size_t len)', 'static bool write(const std::string &path, const cocos2d::Data &data)')
    .func(nil, 'static cocos2d::Data read(const std::string &path)')
    .func(nil, 'static bool unzip(const std::string &path, const std::string &dest)')
    .prop('writablePath', nil, nil)
    .prop('cacheDirectory', nil, nil)
    .prop('documentDirectory', nil, nil)
    .prop('tmpDirectory', nil, nil)
    .prop('builtinCacheDirectory', nil, nil)
    .prop('sdCardDirectory', nil, nil)

typeconf 'cclua::preferences'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static bool getBoolean(const std::string &key, @optional bool defaultValue)')
    .func(nil, 'static void setBoolean(const std::string &key, bool value)')
    .func(nil, 'static float getFloat(const std::string &key, @optional float defaultValue)')
    .func(nil, 'static void setFloat(const std::string &key, float value)')
    .func(nil, 'static double getDouble(const std::string &key, @optional double defaultValue)')
    .func(nil, 'static void setDouble(const std::string &key, double value)')
    .func(nil, 'static int getInteger(const std::string &key, @optional int defaultValue)')
    .func(nil, 'static void setInteger(const std::string &key, int value)')
    .func(nil, 'static std::string getString(const std::string &key, @optional const std::string &defaultValue)')
    .func(nil, 'static void setString(const std::string &key, const std::string &value)')
    .func(nil, 'static void deleteKey(const std::string &key)')
    .func(nil, 'static void flush()')

typeconf 'cclua::timer'
    .supercls(nil)
    .reg_luatype(true)
    .chunk([[#define makeTimerDelayTag(tag) ("delayTag." + tag)]])
    .luaopen(nil)
    .indexerror(nil)
    .func('schedule', [[
        {
            float interval = (float)olua_checknumber(L, 1);
            uint32_t callback = olua_funcref(L, 2);
            uint32_t id = cclua::timer::schedule(interval, [callback](float dt) {
                lua_State *L = olua_mainthread(NULL);
                if (L != NULL) {
                    int top = lua_gettop(L);
                    olua_pusherrorfunc(L);
                    olua_getref(L, callback);
                    if (lua_isfunction(L, -1)) {
                        lua_pushnumber(L, dt);
                        lua_pcall(L, 1, 0, top + 1);
                    }
                    lua_settop(L, top);
                }
            });
            lua_pushinteger(L, ((uint64_t)callback << 32) | (uint64_t)id);
            return 1;
        }
    ]])
    .func('unschedule', [[
        {
            uint64_t value = olua_checkinteger(L, 1);
            uint32_t callback = value >> 32;
            uint32_t id = value & 0xFFFFFFFF;
            olua_unref(L, callback);
            cclua::timer::unschedule(id);
            return 0;
        }
    ]])
    .func(nil, 'static std::string createTag()')
    .callback {
        funcs =  {
            'static void delayWithTag(float time, const std::string &tag, @localvar std::function<void ()> callback)'
        },
        tag_maker = 'makeTimerDelayTag(#2)',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void killDelay(const std::string &tag)'
        },
        tag_maker = 'makeTimerDelayTag(#1)',
        tag_mode = 'subequal',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'static void delay(float time, @localvar const std::function<void ()> callback)'
        },
        tag_maker = 'delay',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }

typeconf 'cclua::window'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, '@unpack static cclua::window::Bounds getVisibleBounds()')
    .func(nil, '@unpack static cocos2d::Size getVisibleSize()')
    .func(nil, '@unpack static cocos2d::Size getFrameSize()')
    .func(nil, 'static void setFrameSize(@pack const cocos2d::Size &size)')
    .func(nil, '@unpack static cocos2d::Size getDesignSize()')
    .func(nil, 'static void setDesignSize(@pack const cocos2d::Size &size, ResolutionPolicy resolutionPolicy)')
    .func(nil, 'static cocos2d::Vec2 convertToCameraSpace(@pack const cocos2d::Vec2 &position)')
    .prop('visibleBounds', nil, nil)
    .prop('visibleSize', nil, nil)
    .prop('frameSize', nil, nil)

typeconf 'cclua::downloader'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static void load(const std::string &uri, const std::string &path, @optional const std::string &md5)')
    .func(nil, 'static void init()')
    .func(nil, 'static void end()')
    .callback {
        funcs =  {
            'static void setDispatcher(@localvar const cclua::Callback &dispatcher)'
        },
        tag_maker = 'Dispatcher',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'static void setURIResolver(@localvar const std::function<std::string (const std::string &)> &resolver)'
        },
        tag_maker = 'URIResolver',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }

typeconf 'cclua::Container'
    .supercls('cocos2d::ui::Layout')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .indexerror(nil)
    .func(nil, 'static cclua::Container *create()')
    .func(nil, 'Container()')
    .func(nil, 'cocos2d::DrawNode *getClippingNode()')
    .func(nil, 'void setFilter(@nullable@addref(filter ^) cocos2d::Node *value)')
    .func(nil, '@addref(filter ^) cocos2d::Node *getFilter()')
    .prop('clippingNode', nil, nil)
    .prop('filter', nil, nil)

typeconf 'cclua::microphone'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("cclua.microphone", true);]])
    .indexerror(nil)
    .ifdef('*', '#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)')
    .func(nil, 'static void start(const std::string &path)')
    .func(nil, 'static void stop()')
    .func(nil, 'static bool isRunning()')
    .func(nil, 'static void dispatch(const std::string &event, const cocos2d::ValueMap &data)')
    .callback {
        funcs =  {
            'static void setDispatcher(@localvar const cclua::Callback &dispatcher)'
        },
        tag_maker = 'Dispatcher',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .prop('running', nil, nil)

typeconf 'cclua::photo'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen([[cclua::runtime::registerFeature("cclua.photo", true);]])
    .indexerror(nil)
    .ifdef('*', '#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)')
    .func(nil, 'static void dispatch(const std::string &event, const cocos2d::ValueMap &data)')
    .callback {
        funcs =  {
            'static void selectAvatar(const std::string &cachePath, int width, int height)'
        },
        tag_maker = 'select',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void takeAvatar(const std::string &cachePath, int width, int height)'
        },
        tag_maker = 'select',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void select(const std::string &cachePath)'
        },
        tag_maker = 'select',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void setDispatcher(@localvar const cclua::Callback &dispatcher)'
        },
        tag_maker = 'Dispatcher',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
