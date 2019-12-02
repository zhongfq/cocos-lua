#include "xgame/xsocket.h"
#include "xgame/xruntime.h"

#ifdef _WIN32
#include <Ws2tcpip.h>
#else
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/tcp.h>
#endif

NS_XGAME_BEGIN

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif
    
#ifdef _WIN32
#define SLEEP(s) Sleep(s)
#else
#define SLEEP(s) usleep(1000 * s)
#endif
    
static int socket_create(int socket_family, int socket_type, int protocol)
{
    return (int)socket(socket_family, socket_type, protocol);
}
    
static int socket_setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen)
{
#ifdef _WIN32
    return setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (const char *)optval, optlen);
#else
    return setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, optval, optlen);
#endif
}

static int socket_connect(int s, const sockaddr *name, int namelen)
{
    return connect(s, name, namelen);
}
    
static int socket_read(int fd, void *buf, size_t count)
{
#ifdef _WIN32
    return (int)recv(fd, (char *)buf, count, 0);
#else
    return (int)read(fd, buf, count);
#endif
}
    
static int socket_write(int fd, const char *buf, size_t len)
{
#ifdef _WIN32
    return (int)send(fd, (char *)buf, len, 0);
#else
    return (int)write(fd, buf, len);
#endif
}

static void socket_close(int s)
{
#ifdef _WIN32
	closesocket((SOCKET)s);
#else
	close(s);
#endif
}

Socket::Socket()
    :_status(Status::INVALID)
    ,_need_quit(false)
    ,_fd(-1)
    ,_socket_thread(nullptr)
{
}

Socket::~Socket()
{
    if (_status == Status::CONNECTED) {
        socket_close(_fd);
    }

    // exit subthread
    _need_quit = true;
    _socket_thread->join();
    
    clear();
    
    delete _socket_thread;
}

bool Socket::init()
{
#ifdef _WIN32
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        xgame::runtime::log("windows init socket error");
    }
#endif
    
    _read_queue.head = nullptr;
    _read_queue.tail = nullptr;
    _read_queue.size = 0;
    
    _send_queue.head = nullptr;
    _send_queue.tail = nullptr;
    _send_queue.size = 0;
    
    _socket_thread = new std::thread(&Socket::start, this);

    return true;
}

void Socket::connect(const std::string& host, uint16_t port)
{
    if (_status == Status::CONNECTED || _status == Status::CONNECTING) {
        return;
    }
    
    clear();

    _host = host;
    _port = port;
    _status = Status::CONNECTING;

    std::thread connection(&Socket::start_conntect, this);
    connection.detach();
}

void Socket::close()
{
    if (_status == Status::CONNECTED) {
        _status = Status::INVALID;
        socket_close(_fd);
        _fd = -1;
    }
    
    clear();
}

void Socket::clear()
{
    buf_t *buf;
    
    std::lock_guard<std::mutex> lock_send(_send_mutex);
    buf = _send_queue.head;
    while (buf) {
        buf_t *tmp = buf->next;
        free(buf);
        buf = tmp;
    }
    _send_queue.head = _send_queue.tail = nullptr;
    _send_queue.size = 0;
    
    std::lock_guard<std::mutex> lock_read(_read_mutex);
    buf = _read_queue.head;
    while (buf) {
        buf_t *tmp = buf->next;
        free(buf);
        buf = tmp;
    }
    _read_queue.head = _read_queue.tail = nullptr;
    _read_queue.size = 0;

}

void Socket::start_conntect()
{
    bool ok = false;
    do {
        struct addrinfo *ai_list;
        static addrinfo hints;
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        
        char port_str[16];
        sprintf(port_str, "%d", _port);
        
        int error = getaddrinfo(_host.c_str(), port_str, &hints, &ai_list);
        if (error != 0)
            break;
        
        runtime::log("start connect: %s:%d", _host.c_str(), _port);
        
        for (struct addrinfo *current = ai_list; current != nullptr; current = current->ai_next)
        {
            _fd = socket_create(current->ai_family, current->ai_socktype, current->ai_protocol);
            if (_fd == -1) {
                continue;
            }
            
            int on = 1;
            socket_setsockopt(_fd, IPPROTO_TCP, TCP_NODELAY, (void *)&on, sizeof(on));
            ok = socket_connect(_fd, current->ai_addr, current->ai_addrlen) == 0;
            if (ok) {
                runtime::log("connect success: %s:%d", _host.c_str(), _port);
                break;
            }
        }
        
        freeaddrinfo(ai_list);
    } while (0);
    
    if (ok) {
        _status = Status::CONNECTED;
    } else {
        runtime::log("connect error: %s:%d", _host.c_str(), _port);
        _status = Status::IO_ERROR;
    }
}

void Socket::start()
{
    while (!_need_quit) {
        SLEEP(5);
        
        if (_status != Status::CONNECTED) {
            continue;
        }

        // read
        fd_set fdset;
        FD_ZERO(&fdset);
        FD_SET(_fd, &fdset);
        
        struct timeval time;
        time.tv_sec = 0;
        time.tv_usec = 0;

        int ret = select(_fd + 1, &fdset, NULL, NULL, &time);
        if (ret > 0) {
            uint8_t buf[4096];
            int ret = socket_read(_fd, buf, sizeof(buf));
            if (ret > 0) {
                _read_mutex.lock();
                push_buf(&_read_queue, buf, ret);
                _read_mutex.unlock();
            } else if (ret < 0 && (errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN)) {
                continue;
            } else {
                _status = Status::DISCONNECTED;
            }
        }
        else if (ret < 0 && (errno != EINTR || errno != EAGAIN)) {
            _status = Status::DISCONNECTED;
        }
        
        // send
        buf_t *buf = nullptr;
        
        _send_mutex.lock();
        if (_status == Status::CONNECTED &&
            _send_queue.head != nullptr &&
            _send_queue.head->offset == BUF_SIZE) {
            buf = pop_buf(&_send_queue);
            _send_queue.size -= buf->size;
        }
        _send_mutex.unlock();
        
        if (buf) {
            int num_sended = 0;
            while (true) {
                const char *data = (char *)(buf->data + num_sended);
                size_t len = (size_t)(buf->size - num_sended);
                int ret = socket_write(_fd, data, len);
                if (ret > 0) {
                    num_sended += ret;
                    if (num_sended >= buf->size) {
                        free(buf);
                        break;
                    }
                } else if (ret < 0 && (errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN)) {
                    SLEEP(1);
                    continue;
                } else {
                    free(buf);
                    _status = Status::DISCONNECTED;
                    break;
                }
            }
        }
    }
}

int Socket::bytes_available()
{
    std::lock_guard<std::mutex> lock(_read_mutex);
    return _read_queue.size;
}

void Socket::flush()
{
    std::lock_guard<std::mutex> lock(_send_mutex);
    buf_t *buf = _send_queue.head;
    while (buf) {
        buf_t *tmp = buf->next;
        buf->offset = BUF_SIZE;
        buf = tmp;
    }
}

bool Socket::read_ubyte(uint8_t *value)
{
    std::lock_guard<std::mutex> lock(_read_mutex);
    return pop_bytes(&_read_queue, value, 1);
}

void Socket::write_ubyte(uint8_t value)
{
    std::lock_guard<std::mutex> lock(_send_mutex);
    push_buf(&_send_queue, &value, 1);
}

bool Socket::read_ushort(uint16_t *value)
{
    std::lock_guard<std::mutex> lock(_read_mutex);
    uint8_t bytes[2];
    if (pop_bytes(&_read_queue, bytes, 2)) {
        *value = (uint16_t)bytes[0] << 8 | (uint16_t)bytes[1];
        return true;
    }
    
    return false;
}

void Socket::write_ushort(uint16_t value)
{
    std::lock_guard<std::mutex> lock(_send_mutex);
    uint8_t bytes[2];
    bytes[0] = (uint8_t)(value >> 8 & 0xFF);
    bytes[1] = (uint8_t)(value & 0xFF);
    push_buf(&_send_queue, bytes, 2);
}

bool Socket::read_uint(uint32_t *value)
{
    std::lock_guard<std::mutex> lock(_read_mutex);
    uint8_t bytes[4];
    if (pop_bytes(&_read_queue, bytes, 4)) {
        *value = (uint16_t)bytes[0] << 24 |
            (uint16_t)bytes[1] << 16 |
            (uint16_t)bytes[2] << 8 |
            (uint16_t)bytes[3];
        return true;
    }
    
    return false;
}

void Socket::write_uint(uint32_t value)
{
    std::lock_guard<std::mutex> lock(_send_mutex);
    uint8_t bytes[4];
    bytes[0] = (uint8_t)(value >> 24 & 0xFF);
    bytes[1] = (uint8_t)(value >> 16 & 0xFF);
    bytes[2] = (uint8_t)(value >> 8 & 0xFF);
    bytes[3] = (uint8_t)(value & 0xFF);
    push_buf(&_send_queue, bytes, 4);
}

bool Socket::read_uint64(uint64_t *value)
{
    std::lock_guard<std::mutex> lock(_read_mutex);
    uint8_t bytes[8];
    if (pop_bytes(&_read_queue, bytes, 8)) {
        *value = (uint64_t)bytes[0] << 56 |
            (uint64_t)bytes[1] << 48 |
            (uint64_t)bytes[2] << 40 |
            (uint64_t)bytes[3] << 32 |
            (uint64_t)bytes[4] << 24 |
            (uint64_t)bytes[5] << 16 |
            (uint64_t)bytes[6] << 8 |
            (uint64_t)bytes[7];
        return true;
    }
    return false;
}

void Socket::write_uint64(uint64_t value)
{
    std::lock_guard<std::mutex> lock(_send_mutex);
    uint8_t bytes[8];
    bytes[0] = (uint8_t)(value >> 56 & 0xFF);
    bytes[1] = (uint8_t)(value >> 48 & 0xFF);
    bytes[2] = (uint8_t)(value >> 40 & 0xFF);
    bytes[3] = (uint8_t)(value >> 32 & 0xFF);
    bytes[4] = (uint8_t)(value >> 24 & 0xFF);
    bytes[5] = (uint8_t)(value >> 16 & 0xFF);
    bytes[6] = (uint8_t)(value >> 8 & 0xFF);
    bytes[7] = (uint8_t)(value & 0xFF);
    push_buf(&_send_queue, bytes, 8);
}

bool Socket::read_float(float *value)
{
    union {
        uint32_t i;
        float f;
    } u;
    
    bool ok = read_uint(&u.i);
    
    if (ok) {
        *value = u.f;
    }
    
    return ok;
}

void Socket::write_float(float value)
{
    union {
        uint32_t i;
        float f;
    } u;
    
    u.f = value;
    write_uint(u.i);
}

bool Socket::read_double(double *value)
{
    union {
        uint64_t i;
        double d;
    } u;
    
    bool ok = read_uint64(&u.i);
    
    if (ok) {
        *value = u.d;
    }
    
    return ok;
}

void Socket::write_double(double value)
{
    union {
        uint64_t i;
        double d;
    } u;
    
    u.d = value;
    write_uint64(u.i);

}

bool Socket::read_bytes(uint8_t *data, int len)
{
    std::lock_guard<std::mutex> lock(_read_mutex);
    return pop_bytes(&_read_queue, data, len);
}

void Socket::write_bytes(const uint8_t *data, int len)
{
    std::lock_guard<std::mutex> lock(_send_mutex);
    push_buf(&_send_queue, data, len);
}

static buf_t *create_buf()
{
    buf_t *buf = (buf_t *)malloc(sizeof(*buf));
    buf->offset = 0;
    buf->size = 0;
    buf->next = nullptr;
    return buf;
}

bool Socket::pop_bytes(buf_queue_t *queue, uint8_t *data, int len)
{
    int count = 0;
    
    while (queue->size >= len && len > 0) {
        buf_t *buf = queue->head;
        int n = MIN(buf->size - buf->offset, len);
        memcpy(data + count, buf->data + buf->offset, n);
        queue->size -= n;
        len -= n;
        buf->offset += n;
        count += n;
        
        if (buf->size == BUF_SIZE && buf->offset == BUF_SIZE) {
            pop_buf(queue);
            free(buf);
        }
    }
    
    return len == 0;
}

buf_t *Socket::pop_buf(buf_queue_t *queue)
{
    buf_t *buf = queue->head;
    
    if (buf) {
        if (buf == queue->tail) {
            queue->head = queue->tail = nullptr;
        } else {
            queue->head = queue->head->next;
        }
    }
    
    return buf;
}

void Socket::push_buf(buf_queue_t *queue, const uint8_t *data, int len)
{
    while (len > 0) {
        if (queue->head == nullptr) {
            queue->head = create_buf();
            queue->tail = queue->head;
        }
        
        if (queue->tail->size >= BUF_SIZE) {
            queue->tail->next = create_buf();
            queue->tail = queue->tail->next;
        }
        
        int n = MIN(BUF_SIZE - queue->tail->size, len);
        memcpy(queue->tail->data + queue->tail->size, data, n);
        data += n;
        len -= n;
        queue->size += n;
        queue->tail->size += n;
    }
}

NS_XGAME_END
