#include "lua_lame.h"
#include "lame.h"

#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <mutex>
#include <string>

#define LUA_LAMEHANDLE "lame*"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#ifdef _WIN32
#define SLEEP(s) Sleep(s)
#else
#define SLEEP(s) usleep(1000 * s)
#endif

class lamewrapper {
public:
    lamewrapper()
    :_need_quit(false)
    ,_done(false)
    ,_work_thread(nullptr)
    {
        _lame = lame_init();
    }
    
    ~lamewrapper()
    {
        stop();
        lame_close(_lame);
    }
    
    bool start(const std::string &pcm_path, const std::string &mp3_path)
    {
        if (!_work_thread && !_done)
        {
            _pcm_path = pcm_path;
            _mp3_path = mp3_path;
            _work_thread = new std::thread(&lamewrapper::do_convert, this);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void cancel()
    {
        if (!_need_quit)
        {
            _need_quit = true;
            stop();
        }
    }
    
    void stop()
    {
        if (_work_thread)
        {
            _done = true;
            _work_thread->join();
            delete _work_thread;
            _work_thread = nullptr;
        }
    }
    
    lame_t lame()
    {
        return _lame;
    }

private:
    void do_convert()
    {
        FILE *pcm_file = fopen(_pcm_path.c_str(), "rb");
        FILE *mp3_file = fopen(_mp3_path.c_str(), "wb");
        
        int num_channels = lame_get_num_channels(_lame);
        
        int inbuf_size = 1024 * 8 * num_channels;
        int outbuf_size = (int)(1.25 * (inbuf_size / num_channels)) + 7200;
        
        short *inbuf = (short *)malloc(sizeof(short) * inbuf_size);
        unsigned char *outbuf = (unsigned char *)malloc(sizeof(unsigned char) * outbuf_size);
        
        bool skipped_header = false;
        
        while (!_need_quit)
        {
            // may be not create, try again
            if (!pcm_file)
                pcm_file = fopen(_pcm_path.c_str(), "rb");
            
            if (!pcm_file && _done)
                break;
            
            if (!mp3_file || !pcm_file)
            {
                SLEEP(10);
                continue;
            }
            
            long cur_pos = ftell(pcm_file);
            long start_pos = ftell(pcm_file);
            fseek(pcm_file, 0, SEEK_END);
            long end_pos = ftell(pcm_file);
            fseek(pcm_file, cur_pos, SEEK_SET);
            long len = end_pos - start_pos;
            
            if (!skipped_header)
            {
                // skip begin noise?
                if (len > 44 + num_channels * 20 * 1024)
                {
                    skipped_header = true;
                    fseek(pcm_file, 44 + num_channels * 20 * 1024, SEEK_SET);
                }
                else
                {
                    SLEEP(10);
                }
                continue;
            }
            
            if (len > (sizeof(short) * inbuf_size) || (_done && len > 0))
            {
                size_t num_read = fread(inbuf, sizeof(short) * num_channels, inbuf_size / num_channels, pcm_file);
                if (num_read > 0)
                {
                    size_t num_write = lame_encode_buffer_interleaved(_lame, inbuf, (int)num_read, outbuf, outbuf_size);
                    fwrite(outbuf, sizeof(unsigned char), num_write, mp3_file);
                }
            }
            else if (len == 0 && _done)
            {
                size_t num_write = lame_encode_flush(_lame, outbuf, outbuf_size);
                fwrite(outbuf, sizeof(unsigned char), num_write, mp3_file);
                break;
            }
            else
            {
                SLEEP(10);
            }
        }
        
        free(inbuf);
        free(outbuf);
        
        if (pcm_file)
            fclose(pcm_file);
        
        if (mp3_file)
        {
            fflush(mp3_file);
            fclose(mp3_file);
        }
    }
    
private:
    bool _need_quit;
    bool _done;
    std::string _pcm_path;
    std::string _mp3_path;
    std::thread *_work_thread;
    lame_t _lame;
};

#define tolamewrapper(L) ((*(lamewrapper **)luaL_checkudata(L, 1, LUA_LAMEHANDLE)))
#define tolame(L) (tolamewrapper(L)->lame())

static int _gc(lua_State *L)
{
    lamewrapper *wrapper = tolamewrapper(L);
    *(lamewrapper **)lua_touserdata(L, 1) = nullptr;
    delete wrapper;
    return 0;
}

static int _start(lua_State *L)
{
    lamewrapper *wrapper = tolamewrapper(L);
    wrapper->start(luaL_checkstring(L, 2), luaL_checkstring(L, 3));
    return 0;
}

static int _stop(lua_State *L)
{
    lamewrapper *wrapper = tolamewrapper(L);
    wrapper->stop();
    return 0;
}

static int _cancel(lua_State *L)
{
    lamewrapper *wrapper = tolamewrapper(L);
    wrapper->cancel();
    return 0;
}

static int _init(lua_State *L)
{
    *(lamewrapper **)lua_newuserdata(L, sizeof(lamewrapper *)) = new lamewrapper();
    luaL_setmetatable(L, LUA_LAMEHANDLE);
    
    return 1;
}

#define LAME_SET(OPTION, OP, TYPE)              \
static int _set_##OPTION(lua_State *L)          \
{                                               \
    lame_t lame = tolame(L);                    \
    lame_set_##OPTION(lame, (TYPE)OP(L, 2));    \
    return 0;                                   \
}

#define LAME_GET(OPTION, OP)                    \
static int _get_##OPTION(lua_State *L)          \
{                                               \
    lame_t lame = tolame(L);                    \
    OP(L, lame_get_##OPTION(lame));             \
    return 1;                                   \
}

#define LAME_OPTION(OPTION)                     \
"set_"#OPTION, _set_##OPTION},                  \
{"get_"#OPTION, _get_##OPTION

LAME_SET(in_samplerate, luaL_checkinteger, int);
LAME_GET(in_samplerate, lua_pushinteger);
LAME_SET(brate, luaL_checkinteger, int);
LAME_GET(brate, lua_pushinteger);
LAME_SET(quality, luaL_checkinteger, int);
LAME_GET(quality, lua_pushinteger);
LAME_SET(num_channels, luaL_checkinteger, int);
LAME_GET(num_channels, lua_pushinteger);
LAME_SET(VBR_mean_bitrate_kbps, luaL_checkinteger, int);
LAME_GET(VBR_mean_bitrate_kbps, lua_pushinteger);

static int _set_mode(lua_State *L)
{
    static const MPEG_mode modes[] = {STEREO, JOINT_STEREO,
        DUAL_CHANNEL, MONO, NOT_SET, MAX_INDICATOR};
    static const char *const modenames[] = {"STEREO", "JOINT_STEREO",
        "DUAL_CHANNEL", "MONO", "NOT_SET", "MAX_INDICATOR"};
    
    lame_t lame = tolame(L);
    int op = luaL_checkoption(L, 2, "NOT_SET", modenames);
    lame_set_mode(lame, modes[op]);
    return 0;
}
LAME_GET(mode, lua_pushinteger);

static int _set_VBR(lua_State *L)
{
    static const vbr_mode modes[] = {vbr_off, vbr_mt, vbr_rh, vbr_abr,
        vbr_mtrh, vbr_max_indicator, vbr_default};
    static const char *const mode_names[] = {"vbr_off", "vbr_mt", "vbr_rh",
        "vbr_abr", "vbr_mtrh", "vbr_max_indicator", "vbr_default", NULL};
    
    lame_t lame = tolame(L);
    int op = luaL_checkoption(L, 2, "vbr_abr", mode_names);
    lame_set_VBR(lame, modes[op]);
    return 0;
}
LAME_GET(VBR, lua_pushinteger);

static int _init_params(lua_State *L)
{
    lame_t lame = tolame(L);
    lame_init_params(lame);
    return 0;
}

int luaopen_lame(lua_State *L)
{
    oluacls_class(L, LUA_LAMEHANDLE, nullptr);
    oluacls_setfunc(L, "__gc", _gc);
    oluacls_setfunc(L, "start", _start);
    oluacls_setfunc(L, "stop", _stop);
    oluacls_setfunc(L, "cancel", _cancel);
    oluacls_setfunc(L, "init", _init);
    oluacls_setfunc(L, "new", _init);
    oluacls_setfunc(L, "init_params", _init_params);
    oluacls_property(L, "in_samplerate", _get_in_samplerate, _set_in_samplerate);
    oluacls_property(L, "num_channels", _get_num_channels, _set_num_channels);
    oluacls_property(L, "mode", _get_mode, _set_mode);
    oluacls_property(L, "quality", _get_quality, _set_quality);
    oluacls_property(L, "brate", _get_brate, _set_brate);
    oluacls_property(L, "vbr", _get_VBR, _set_VBR);
    oluacls_property(L, "vbr_mean_bitrate_kbps", _get_VBR_mean_bitrate_kbps, _set_VBR_mean_bitrate_kbps);
    
    oluacls_createclassproxy(L);
    
    return 1;
}
