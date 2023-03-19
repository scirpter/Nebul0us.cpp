#include "UdpClient.h"

#include <iostream>
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
    UdpClient::UdpClient(const std::string ip, const uint16_t port) : m_ip(ip), m_port(port)
    {
#ifdef _WIN32
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        {
            std::cerr << "WSAStartup failed." << std::endl;
            exit(1);
        }
#endif

        m_sock = static_cast<int>(socket(AF_INET, SOCK_DGRAM, 0));
        if (m_sock < 0)
        {
            std::cerr << "Socket creation failed." << std::endl;
            exit(1);
        }

        struct sockaddr_in myLocalAddr;
        memset(&myLocalAddr, 0, sizeof(myLocalAddr));
        myLocalAddr.sin_family = AF_INET;
        myLocalAddr.sin_port = htons(0);
        myLocalAddr.sin_addr.s_addr = htonl(INADDR_ANY);

        bind(
            m_sock,
            (struct sockaddr *)&myLocalAddr,
            sizeof(myLocalAddr));

        memset(&m_target_addr, 0, sizeof(m_target_addr));
        m_target_addr.sin_family = AF_INET;
        m_target_addr.sin_port = htons(m_port);
        inet_pton(AF_INET, m_ip.c_str(), &m_target_addr.sin_addr);
    }

    UdpClient::~UdpClient()
    {
#ifdef _WIN32
        WSACleanup();
#endif
#ifndef _WIN32
        close(sock);
#endif
    }

    void UdpClient::send(const char *data)
    {
        sendto(
            m_sock,
            data,
            static_cast<int>(strlen(data)),
            0,
            (struct sockaddr *)&m_target_addr,
            sizeof(m_target_addr));
    }

    void UdpClient::receiveLoop(void (*callback)(const char *))
    {
        char buffer[1024];
        int len = 0;
        while (true)
        {
            len = recvfrom(
                m_sock,
                buffer,
                1024,
                0,
                NULL,
                NULL);
            if (len > 0)
            {
                buffer[len] = '\0';
                callback(buffer);
            }
        }
    }
}