#pragma once

#if _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WinSock2.h>
#else
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <poll.h>
#include <unistd.h>
#include <fcntl.h>
#define SOCKET int
#endif

class XNetwork
{
private:
    SOCKET _socket;

    bool ValidateAddress(const char *address, sockaddr_in &_peerAddr);
public:
    XNetwork();
    virtual ~XNetwork();

    bool Initialize();
    bool Connect(const char *address);
    int Poll(struct pollfd *fd, unsigned int size, int timeout);
    int Write(char* buf, int len);
    int Read(char* buf, int len);
    void Close();

    bool IsConnected() { return _socket != -1; }
    SOCKET GetSocket() { return _socket; }
};

