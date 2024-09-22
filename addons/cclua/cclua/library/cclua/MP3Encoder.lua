---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.MP3Encoder

---
---@class cclua.MP3Encoder : cc.Ref
---@field allowDiffShort integer 
---@field analysis integer 
---@field atHlower number 
---@field atHonly integer 
---@field atHshort integer 
---@field atHtype integer 
---@field athaaSensitivity number 
---@field athaaType integer 
---@field audiophileGain integer 
---@field bWriteVbrTag integer 
---@field brate integer 
---@field compressionRatio number 
---@field copyright integer 
---@field decodeOnTheFly integer 
---@field decodeOnly integer 
---@field disableReservoir integer 
---@field emphasis integer 
---@field encoderDelay integer 
---@field encoderPadding integer 
---@field errorProtection integer 
---@field expNspsytune integer 
---@field experimentalX integer 
---@field experimentalY integer 
---@field experimentalZ integer 
---@field extension integer 
---@field findReplayGain integer 
---@field forceMs integer 
---@field forceShortBlocks integer 
---@field frameNum integer 
---@field framesize integer 
---@field freeFormat integer 
---@field highpassfreq integer 
---@field highpasswidth integer 
---@field inSamplerate integer 
---@field interChRatio number 
---@field lameOsBitness string 
---@field lameShortVersion string 
---@field lameUrl string 
---@field lameVersion string 
---@field lameVeryShortVersion string 
---@field lowpassfreq integer 
---@field lowpasswidth integer 
---@field mfSamplesToEncode integer 
---@field mode cclua.MP3Encoder.MPEGMode 
---@field msfix number 
---@field noATH integer 
---@field noShortBlocks integer 
---@field noclipGainChange integer 
---@field noclipScale number 
---@field nogapCurrentindex integer 
---@field nogapTotal integer 
---@field numChannels integer 
---@field numSamples integer 
---@field original integer 
---@field outSamplerate integer 
---@field peakSample number 
---@field psyVersion string 
---@field quality integer 
---@field quantComp integer 
---@field quantCompShort integer 
---@field radioGain integer 
---@field scale number 
---@field scaleLeft number 
---@field scaleRight number 
---@field sizeMp3buffer integer 
---@field strictISO integer 
---@field totalframes integer 
---@field useTemporal integer 
---@field vbr cclua.MP3Encoder.VBRMode 
---@field vbrHardMin integer 
---@field vbrMaxBitrateKbps integer 
---@field vbrMeanBitrateKbps integer 
---@field vbrMinBitrateKbps integer 
---@field vbrQuality number 
---@field vbrq integer 
---@field version integer 
local MP3Encoder = {}

---@return number
function MP3Encoder:getATHlower() end

---@return integer
function MP3Encoder:getATHonly() end

---@return integer
function MP3Encoder:getATHshort() end

---@return integer
function MP3Encoder:getATHtype() end

---@return integer
function MP3Encoder:getAllowDiffShort() end

---@return integer
function MP3Encoder:getAnalysis() end

---@return number
function MP3Encoder:getAthaaSensitivity() end

---@return integer
function MP3Encoder:getAthaaType() end

---@return integer
function MP3Encoder:getAudiophileGain() end

---@return integer
function MP3Encoder:getBWriteVbrTag() end

---@return integer
function MP3Encoder:getBrate() end

---@return number
function MP3Encoder:getCompressionRatio() end

---@return integer
function MP3Encoder:getCopyright() end

---@return integer
function MP3Encoder:getDecodeOnTheFly() end

---@return integer
function MP3Encoder:getDecodeOnly() end

---@return integer
function MP3Encoder:getDisableReservoir() end

---@return integer
function MP3Encoder:getEmphasis() end

---@return integer
function MP3Encoder:getEncoderDelay() end

---@return integer
function MP3Encoder:getEncoderPadding() end

---@return integer
function MP3Encoder:getErrorProtection() end

---@return integer
function MP3Encoder:getExpNspsytune() end

---@return integer
function MP3Encoder:getExperimentalX() end

---@return integer
function MP3Encoder:getExperimentalY() end

---@return integer
function MP3Encoder:getExperimentalZ() end

---@return integer
function MP3Encoder:getExtension() end

---@return integer
function MP3Encoder:getFindReplayGain() end

---@return integer
function MP3Encoder:getForceMs() end

---@return integer
function MP3Encoder:getForceShortBlocks() end

---@return integer
function MP3Encoder:getFrameNum() end

---@return integer
function MP3Encoder:getFramesize() end

---@return integer
function MP3Encoder:getFreeFormat() end

---@return integer
function MP3Encoder:getHighpassfreq() end

---@return integer
function MP3Encoder:getHighpasswidth() end

---@return integer
function MP3Encoder:getInSamplerate() end

---@return number
function MP3Encoder:getInterChRatio() end

---@return string
function MP3Encoder:getLameOsBitness() end

---@return string
function MP3Encoder:getLameShortVersion() end

---@return string
function MP3Encoder:getLameUrl() end

---@return string
function MP3Encoder:getLameVersion() end

---@return string
function MP3Encoder:getLameVeryShortVersion() end

---@return integer
function MP3Encoder:getLowpassfreq() end

---@return integer
function MP3Encoder:getLowpasswidth() end

---@return integer
function MP3Encoder:getMfSamplesToEncode() end

---@return cclua.MP3Encoder.MPEGMode
function MP3Encoder:getMode() end

---@return number
function MP3Encoder:getMsfix() end

---@return integer
function MP3Encoder:getNoATH() end

---@return integer
function MP3Encoder:getNoShortBlocks() end

---@return integer
function MP3Encoder:getNoclipGainChange() end

---@return number
function MP3Encoder:getNoclipScale() end

---@return integer
function MP3Encoder:getNogapCurrentindex() end

---@return integer
function MP3Encoder:getNogapTotal() end

---@return integer
function MP3Encoder:getNumChannels() end

---@return integer
function MP3Encoder:getNumSamples() end

---@return integer
function MP3Encoder:getOriginal() end

---@return integer
function MP3Encoder:getOutSamplerate() end

---@return number
function MP3Encoder:getPeakSample() end

---@return string
function MP3Encoder:getPsyVersion() end

---@return integer
function MP3Encoder:getQuality() end

---@return integer
function MP3Encoder:getQuantComp() end

---@return integer
function MP3Encoder:getQuantCompShort() end

---@return integer
function MP3Encoder:getRadioGain() end

---@return number
function MP3Encoder:getScale() end

---@return number
function MP3Encoder:getScaleLeft() end

---@return number
function MP3Encoder:getScaleRight() end

---@return integer
function MP3Encoder:getSizeMp3buffer() end

---@return integer
function MP3Encoder:getStrictISO() end

---@return integer
function MP3Encoder:getTotalframes() end

---@return integer
function MP3Encoder:getUseTemporal() end

---@return cclua.MP3Encoder.VBRMode
function MP3Encoder:getVBR() end

---@return integer
function MP3Encoder:getVBRHardMin() end

---@return integer
function MP3Encoder:getVBRMaxBitrateKbps() end

---@return integer
function MP3Encoder:getVBRMeanBitrateKbps() end

---@return integer
function MP3Encoder:getVBRMinBitrateKbps() end

---@return integer
function MP3Encoder:getVBRQ() end

---@return number
function MP3Encoder:getVBRQuality() end

---@return integer
function MP3Encoder:getVersion() end

function MP3Encoder:initParams() end

---@return cclua.MP3Encoder
function MP3Encoder.new() end

function MP3Encoder:printConfig() end

function MP3Encoder:printInternals() end

---@param value number
function MP3Encoder:setATHlower(value) end

---@param value integer
function MP3Encoder:setATHonly(value) end

---@param value integer
function MP3Encoder:setATHshort(value) end

---@param value integer
function MP3Encoder:setATHtype(value) end

---@param value integer
function MP3Encoder:setAllowDiffShort(value) end

---@param value integer
function MP3Encoder:setAnalysis(value) end

---@param optim integer
---@param mode integer
function MP3Encoder:setAsmOptimizations(optim, mode) end

---@param value number
function MP3Encoder:setAthaaSensitivity(value) end

---@param value integer
function MP3Encoder:setAthaaType(value) end

---@param value integer
function MP3Encoder:setBWriteVbrTag(value) end

---@param value integer
function MP3Encoder:setBrate(value) end

---@param value number
function MP3Encoder:setCompressionRatio(value) end

---@param value integer
function MP3Encoder:setCopyright(value) end

---@param value integer
function MP3Encoder:setDecodeOnTheFly(value) end

---@param value integer
function MP3Encoder:setDecodeOnly(value) end

---@param value integer
function MP3Encoder:setDisableReservoir(value) end

---@param value integer
function MP3Encoder:setEmphasis(value) end

---@param value integer
function MP3Encoder:setErrorProtection(value) end

---@param value integer
function MP3Encoder:setExpNspsytune(value) end

---@param value integer
function MP3Encoder:setExperimentalX(value) end

---@param value integer
function MP3Encoder:setExperimentalY(value) end

---@param value integer
function MP3Encoder:setExperimentalZ(value) end

---@param value integer
function MP3Encoder:setExtension(value) end

---@param value integer
function MP3Encoder:setFindReplayGain(value) end

---@param value integer
function MP3Encoder:setForceMs(value) end

---@param value integer
function MP3Encoder:setForceShortBlocks(value) end

---@param value integer
function MP3Encoder:setFreeFormat(value) end

---@param value integer
function MP3Encoder:setHighpassfreq(value) end

---@param value integer
function MP3Encoder:setHighpasswidth(value) end

---@param value integer
function MP3Encoder:setInSamplerate(value) end

---@param value number
function MP3Encoder:setInterChRatio(value) end

---@param value integer
function MP3Encoder:setLowpassfreq(value) end

---@param value integer
function MP3Encoder:setLowpasswidth(value) end

---@param value cclua.MP3Encoder.MPEGMode
function MP3Encoder:setMode(value) end

---@param value number
function MP3Encoder:setMsfix(value) end

---@param value integer
function MP3Encoder:setNoATH(value) end

---@param value integer
function MP3Encoder:setNoShortBlocks(value) end

---@param value integer
function MP3Encoder:setNogapCurrentindex(value) end

---@param value integer
function MP3Encoder:setNogapTotal(value) end

---@param value integer
function MP3Encoder:setNumChannels(value) end

---@param value integer
function MP3Encoder:setNumSamples(value) end

---@param value integer
function MP3Encoder:setOriginal(value) end

---@param value integer
function MP3Encoder:setOutSamplerate(value) end

---@param preset integer
function MP3Encoder:setPreset(preset) end

---@param value integer
function MP3Encoder:setQuality(value) end

---@param value integer
function MP3Encoder:setQuantComp(value) end

---@param value integer
function MP3Encoder:setQuantCompShort(value) end

---@param value number
function MP3Encoder:setScale(value) end

---@param value number
function MP3Encoder:setScaleLeft(value) end

---@param value number
function MP3Encoder:setScaleRight(value) end

---@param value integer
function MP3Encoder:setStrictISO(value) end

---@param value integer
function MP3Encoder:setUseTemporal(value) end

---@param value cclua.MP3Encoder.VBRMode
function MP3Encoder:setVBR(value) end

---@param value integer
function MP3Encoder:setVBRHardMin(value) end

---@param value integer
function MP3Encoder:setVBRMaxBitrateKbps(value) end

---@param value integer
function MP3Encoder:setVBRMeanBitrateKbps(value) end

---@param value integer
function MP3Encoder:setVBRMinBitrateKbps(value) end

---@param value integer
function MP3Encoder:setVBRQ(value) end

---@param value number
function MP3Encoder:setVBRQuality(value) end

---@param pcmPath string
---@param mp3Path string
function MP3Encoder:start(pcmPath, mp3Path) end

function MP3Encoder:stop() end

return MP3Encoder