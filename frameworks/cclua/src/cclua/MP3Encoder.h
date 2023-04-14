#ifndef __CCLUA_MP3ENCODER_H__
#define __CCLUA_MP3ENCODER_H__

#include "runtime.h"
#include "lame/lame.h"

#include <thread>
#include <atomic>

NS_CCLUA_BEGIN

class MP3Encoder : public cocos2d::Ref {
public:
    enum class VBRMode {
        OFF = vbr_off,
        MT = vbr_mt,
        RH = vbr_rh,
        ABR = vbr_abr,
        MTRH = vbr_mtrh,
        MAX_INDICATOR = vbr_max_indicator,
        DEFAULT = vbr_mtrh
    };

    enum class MPEGMode {
        STEREO = STEREO,
        JOINT_STEREO = JOINT_STEREO,
        DUAL_CHANNEL = DUAL_CHANNEL,
        MONO = MONO,
        NOT_SET = NOT_SET,
        MAX_INDICATOR = MAX_INDICATOR,
    };
    
public:
    MP3Encoder();
    virtual ~MP3Encoder();
    
    void start(const std::string &pcmPath, const std::string &mp3Path);
    void stop();
    
    void initParams();
    
    void setNumSamples(unsigned long value) { lame_set_num_samples(_lame, value); }
    unsigned long getNumSamples() { return lame_get_num_samples(_lame); }
    
    void setInSamplerate(int value) { lame_set_in_samplerate(_lame, value); }
    int getInSamplerate() { return lame_get_in_samplerate(_lame); }
    
    void setNumChannels(int value) { lame_set_num_channels(_lame, value); }
    int getNumChannels() { return lame_get_num_channels(_lame); }

    void setScale(float value) { lame_set_scale(_lame, value); }
    float getScale() { return lame_get_scale(_lame); }

    void setScaleLeft(float value) { lame_set_scale_left(_lame, value); };
    float getScaleLeft() { return lame_get_scale_left(_lame); }

    void setScaleRight(float value) { lame_set_scale_right(_lame, value); }
    float getScaleRight() { return lame_get_scale_right(_lame); }

    void setOutSamplerate(int value) { lame_set_out_samplerate(_lame, value); }
    int getOutSamplerate() { return lame_get_out_samplerate(_lame); }

    void setAnalysis(int value) { lame_set_analysis(_lame, value); }
    int getAnalysis() { return lame_get_analysis(_lame); }

    void setBWriteVbrTag(int value) { lame_set_bWriteVbrTag(_lame, value); }
    int getBWriteVbrTag() { return lame_get_bWriteVbrTag(_lame); }

    void setDecodeOnly(int value) { lame_set_decode_only(_lame, value); }
    int getDecodeOnly() { return lame_get_decode_only(_lame); }

    void setQuality(int value) { lame_set_quality(_lame, value); }
    int getQuality() { return lame_get_quality(_lame); }

    void setMode(MPEGMode value) { lame_set_mode(_lame, (MPEG_mode)value); }
    MPEGMode getMode() { return (MPEGMode)lame_get_mode(_lame); }
    
    void setForceMs(int value) { lame_set_force_ms(_lame, value); }
    int getForceMs() { return lame_get_force_ms(_lame); }

    void setFreeFormat(int value) { lame_set_free_format(_lame, value); }
    int getFreeFormat() { return lame_get_free_format(_lame); }

    void setFindReplayGain(int value) { lame_set_findReplayGain(_lame, value); }
    int getFindReplayGain() { return lame_get_findReplayGain(_lame); }

    void setDecodeOnTheFly(int value) { lame_set_decode_on_the_fly(_lame, value); }
    int getDecodeOnTheFly() { return lame_get_decode_on_the_fly(_lame); }

    void setNogapTotal(int value) { lame_set_nogap_total(_lame, value); }
    int getNogapTotal() { return lame_get_nogap_total(_lame); }

    void setNogapCurrentindex(int value) { lame_set_nogap_currentindex(_lame, value); }
    int getNogapCurrentindex() { return lame_get_nogap_currentindex(_lame); }

    void setBrate(int value) { lame_set_brate(_lame, value); }
    int getBrate() { return lame_get_brate(_lame); }

    void setCompressionRatio(float value) { lame_set_compression_ratio(_lame, value); }
    float getCompressionRatio() { return lame_get_compression_ratio(_lame); }

    void setPreset(int preset) { lame_set_preset(_lame, preset); }

    void setAsmOptimizations(int optim, int mode) { lame_set_asm_optimizations(_lame, optim, mode); }

    void setCopyright(int value) { lame_set_copyright(_lame, value); }
    int getCopyright() { return lame_get_copyright(_lame); }

    void setOriginal(int value) { lame_set_original(_lame, value); }
    int getOriginal() { return lame_get_original(_lame); }

    void setErrorProtection(int value) { lame_set_error_protection(_lame, value); }
    int getErrorProtection() { return lame_get_error_protection(_lame); }

    void setExtension(int value) { lame_set_extension(_lame, value); }
    int getExtension() { return lame_get_extension(_lame); }

    void setStrictISO(int value) { lame_set_strict_ISO(_lame, value); }
    int getStrictISO() { return lame_get_strict_ISO(_lame); }

    void setDisableReservoir(int value) { lame_set_disable_reservoir(_lame, value); }
    int getDisableReservoir() { return lame_get_disable_reservoir(_lame); }

    void setQuantComp(int value) { lame_set_quant_comp(_lame, value); }
    int getQuantComp() { return lame_get_quant_comp(_lame); }

    void setQuantCompShort(int value) { lame_set_quant_comp_short(_lame, value); }
    int getQuantCompShort() { return lame_get_quant_comp_short(_lame); }

    void setExperimentalX(int value) { lame_set_experimentalX(_lame, value); }
    int getExperimentalX() { return lame_get_experimentalX(_lame); }

    void setExperimentalY(int value) { lame_set_experimentalY(_lame, value); }
    int getExperimentalY() { return lame_get_experimentalY(_lame); }

    void setExperimentalZ(int value) { lame_set_experimentalZ(_lame, value); }
    int getExperimentalZ() { return lame_get_experimentalZ(_lame); }

    void setExpNspsytune(int value) { lame_set_exp_nspsytune(_lame, value); }
    int getExpNspsytune() { return lame_get_exp_nspsytune(_lame); }

    void setMsfix(double value) { lame_set_msfix(_lame, value); }
    float getMsfix() { return lame_get_msfix(_lame); }

    void setVBR(VBRMode value) { lame_set_VBR(_lame, (vbr_mode)value); }
    VBRMode getVBR() { return (VBRMode)lame_get_VBR(_lame); }

    void setVBRQ(int value) { lame_set_VBR_q(_lame, value); }
    int getVBRQ() { return lame_get_VBR_q(_lame); }

    void setVBRQuality(float value) { lame_set_VBR_quality(_lame, value); }
    float getVBRQuality() { return lame_get_VBR_quality(_lame); }

    void setVBRMeanBitrateKbps(int value) { lame_set_VBR_mean_bitrate_kbps(_lame, value); }
    int getVBRMeanBitrateKbps() { return lame_get_VBR_mean_bitrate_kbps(_lame); }

    void setVBRMinBitrateKbps(int value) { lame_set_VBR_min_bitrate_kbps(_lame, value); }
    int getVBRMinBitrateKbps() { return lame_get_VBR_min_bitrate_kbps(_lame); }

    void setVBRMaxBitrateKbps(int value) { lame_set_VBR_max_bitrate_kbps(_lame, value); }
    int getVBRMaxBitrateKbps() { return lame_get_VBR_max_bitrate_kbps(_lame); }

    void setVBRHardMin(int value) { lame_set_VBR_hard_min(_lame, value); }
    int getVBRHardMin() { return lame_get_VBR_hard_min(_lame); }

    void setLowpassfreq(int value) { lame_set_lowpassfreq(_lame, value); }
    int getLowpassfreq() { return lame_get_lowpassfreq(_lame); }

    void setLowpasswidth(int value) { lame_set_lowpasswidth(_lame, value); }
    int getLowpasswidth() { return lame_get_lowpasswidth(_lame); }

    void setHighpassfreq(int value) { lame_set_highpassfreq(_lame, value); }
    int getHighpassfreq() { return lame_get_highpassfreq(_lame); }

    void setHighpasswidth(int value) { lame_set_highpasswidth(_lame, value); }
    int getHighpasswidth() { return lame_get_highpasswidth(_lame); }

    void setATHonly(int value) { lame_set_ATHonly(_lame, value); }
    int getATHonly() { return lame_get_ATHonly(_lame); }

    void setATHshort(int value) { lame_set_ATHshort(_lame, value); }
    int getATHshort() { return lame_get_ATHshort(_lame); }

    void setNoATH(int value) { lame_set_noATH(_lame, value); }
    int getNoATH() { return lame_get_noATH(_lame); }

    void setATHtype(int value) { lame_set_ATHtype(_lame, value); }
    int getATHtype() { return lame_get_ATHtype(_lame); }

    void setATHlower(float value) { lame_set_ATHlower(_lame, value); }
    float getATHlower() { return lame_get_ATHlower(_lame); }

    void setAthaaType(int value) { lame_set_athaa_type(_lame, value); }
    int getAthaaType() { return lame_get_athaa_type(_lame); }

    void setAthaaSensitivity(float value) { lame_set_athaa_sensitivity(_lame, value); }
    float getAthaaSensitivity() { return lame_get_athaa_sensitivity(_lame); }

    void setAllowDiffShort(int value) { lame_set_allow_diff_short(_lame, value); }
    int getAllowDiffShort() { return lame_get_allow_diff_short(_lame); }

    void setUseTemporal(int value) { lame_set_useTemporal(_lame, value); }
    int getUseTemporal() { return lame_get_useTemporal(_lame); }

    void setInterChRatio(float value) { lame_set_interChRatio(_lame, value); }
    float getInterChRatio() { return lame_get_interChRatio(_lame); }

    void setNoShortBlocks(int value) { lame_set_no_short_blocks(_lame, value); }
    int getNoShortBlocks() { return lame_get_no_short_blocks(_lame); }

    void setForceShortBlocks(int value) { lame_set_force_short_blocks(_lame, value); }
    int getForceShortBlocks() { return lame_get_force_short_blocks(_lame); }

    void setEmphasis(int value) { lame_set_emphasis(_lame, value); }
    int getEmphasis() { return lame_get_emphasis(_lame); }

    int getVersion() { return lame_get_version(_lame); }

    int getEncoderDelay() { return lame_get_encoder_delay(_lame); }

    int getEncoderPadding() { return lame_get_encoder_padding(_lame); }

    int getFramesize() { return lame_get_framesize(_lame); }

    int getMfSamplesToEncode() { return lame_get_mf_samples_to_encode(_lame); }

    int getSizeMp3buffer() { return lame_get_size_mp3buffer(_lame); }

    int getFrameNum() { return lame_get_frameNum(_lame); }

    int getTotalframes() { return lame_get_totalframes(_lame); }

    int getRadioGain() { return lame_get_RadioGain(_lame); }

    int getAudiophileGain() { return lame_get_AudiophileGain(_lame); }

    float getPeakSample() { return lame_get_PeakSample(_lame); }

    int getNoclipGainChange() { return lame_get_noclipGainChange(_lame); }

    float getNoclipScale() { return lame_get_noclipScale(_lame); }

    const char *getLameVersion() { return get_lame_version(); }

    const char *getLameShortVersion() { return get_lame_short_version(); }

    const char *getLameVeryShortVersion() { return get_lame_very_short_version(); }

    const char *getPsyVersion() { return get_psy_version(); }

    const char *getLameUrl() { return get_lame_url(); }

    const char *getLameOsBitness() { return get_lame_os_bitness(); }
    
    void printConfig() { lame_print_config(_lame); }
    void printInternals() { lame_print_internals(_lame); }

private:
    void doConvert();
    
private:
    std::atomic<bool> _stopped;
    std::string _pcmPath;
    std::string _mp3Path;
    std::thread *_workThread = nullptr;
    lame_t _lame = nullptr;
};

NS_CCLUA_END

#endif
