#pragma once

#include <cstdint>
#include <string>

#ifdef _WIN32
#define _WIN32_WINNT 0x0600
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

namespace net
{
    class UdpClient
    {
    public:
        UdpClient(const std::string ip, const uint16_t port);
        ~UdpClient();

        void send(const char *message);

        // take a function
        void receiveLoop(void (*callback)(const char *));

    private:
        const std::string m_ip;
        const uint16_t m_port;
        int m_sock;

        sockaddr_in m_target_addr;
    };
}