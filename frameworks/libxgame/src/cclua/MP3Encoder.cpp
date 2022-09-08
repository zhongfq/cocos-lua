#include "MP3Encoder.h"

#include <chrono>

USING_NS_CCLUA;

MP3Encoder::MP3Encoder()
:_stopped(false)
,_workThread(nullptr)
,_lame(nullptr)
{
    _lame = lame_init();
}

MP3Encoder::~MP3Encoder()
{
    stop();
    lame_close(_lame);
}

void MP3Encoder::start(const std::string &pcmPath, const std::string &mp3Path)
{
    if (!_workThread && !_stopped) {
        _pcmPath = pcmPath;
        _mp3Path = mp3Path;
        _workThread = new std::thread(&MP3Encoder::doConvert, this);
    }
}

void MP3Encoder::stop()
{
    if (_workThread) {
        _stopped = true;
        _workThread->join();
        delete _workThread;
        _workThread = nullptr;
    }
}

void MP3Encoder::doConvert()
{
    FILE *pcmFile = NULL;
    FILE *mp3File = NULL;
    
    int numChannels = lame_get_num_channels(_lame);
    
    int inbufSize = 1024 * 8 * numChannels;
    int outbufSize = (int)(1.25 * (inbufSize / numChannels)) + 7200;
    
    short *inbuf = (short *)malloc(sizeof(short) * inbufSize);
    unsigned char *outbuf = (unsigned char *)malloc(sizeof(unsigned char) * outbufSize);
    
    bool skippedHeader = false;
    
    while (true) {
        // may be not create, try again
        if (!pcmFile) {
            pcmFile = fopen(_pcmPath.c_str(), "rb");
        }

        if (!mp3File) {
            mp3File = fopen(_mp3Path.c_str(), "wb");
        }
        
        if ((!pcmFile || !mp3File) && _stopped) {
            break;
        }
        
        if (!mp3File || !pcmFile) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        
        long startPos = ftell(pcmFile);
        fseek(pcmFile, 0, SEEK_END);
        long endPos = ftell(pcmFile);
        fseek(pcmFile, startPos, SEEK_SET);
        long len = endPos - startPos;
        
        if (!skippedHeader) {
            // skip begin noise?
            if (len > 44 + numChannels * 20 * 1024) {
                skippedHeader = true;
                fseek(pcmFile, 44 + numChannels * 20 * 1024, SEEK_SET);
            } else if (_stopped) {
                break;
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            continue;
        }
        
        if (len > (sizeof(short) * inbufSize) || (_stopped && len > 0)) {
            size_t numRead = fread(inbuf, sizeof(short) * numChannels, inbufSize / numChannels, pcmFile);
            if (numRead > 0) {
                size_t numWrite = lame_encode_buffer_interleaved(_lame, inbuf, (int)numRead, outbuf, outbufSize);
                fwrite(outbuf, sizeof(unsigned char), numWrite, mp3File);
            }
        } else if (len == 0 && _stopped) {
            size_t numWrite = lame_encode_flush(_lame, outbuf, outbufSize);
            fwrite(outbuf, sizeof(unsigned char), numWrite, mp3File);
            break;
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    
    free(inbuf);
    free(outbuf);
    
    if (pcmFile) {
        fclose(pcmFile);
    }
    
    if (mp3File) {
        fflush(mp3File);
        fclose(mp3File);
    }
}


void MP3Encoder::initParams()
{
    lame_init_params(_lame);
}
