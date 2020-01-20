#ifndef __XGAME_SOCKET_H__
#define __XGAME_SOCKET_H__

#include "xgame/config.h"

#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <stdint.h>

NS_XGAME_BEGIN

#define BUF_SIZE 512

typedef struct buf_t {
    struct buf_t *next;
    int offset;
    int size;
    uint8_t data[BUF_SIZE];
} buf_t;

typedef struct {
    int size;
    buf_t *head;
    buf_t *tail;
} buf_queue_t;

class Socket
{
public:
    enum Status
    {
        INVALID = 0,
        IO_ERROR,
        CONNECTING,
        CONNECTED,
        DISCONNECTED,
    };
public:
    Socket();
    virtual ~Socket();

    bool init();

    void connect(const std::string &host, uint16_t port);
    
    void close();
    void clear();
    
    Status get_status() { return _status; };
    
    int bytes_available();
    void flush();
    
    bool read_ubyte(uint8_t *value);
    void write_ubyte(uint8_t value);
    
    bool read_ushort(uint16_t *value);
    void write_ushort(uint16_t value);
    
    bool read_uint(uint32_t *value);
    void write_uint(uint32_t value);
    
    bool read_uint64(uint64_t *value);
    void write_uint64(uint64_t value);
    
    bool read_float(float *value);
    void write_float(float value);
    
    bool read_double(double *value);
    void write_double(double value);
    
    bool read_bytes(uint8_t *data, int len);
    void write_bytes(const uint8_t *data, int len);

private:
    bool pop_bytes(buf_queue_t *queue, uint8_t *data, int len);
    buf_t *pop_buf(buf_queue_t *queue);
    void push_buf(buf_queue_t *queue, const uint8_t *data, int len);
    
    void start();
    void start_conntect();
private:
    bool _need_quit;
    Status _status;
    int _fd;
    std::string _host;
    uint16_t _port;
    
    buf_queue_t _send_queue;
    buf_queue_t _read_queue;

    std::mutex _read_mutex;
    std::mutex _send_mutex;

    std::thread *_socket_thread;
};
    
NS_XGAME_END

#endif
