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

int udpclient()
{
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed." << std::endl;
        return 1;
    }
#endif
    int sock; // NOTE: can not use SOCKET type because platform dependent
    sock = static_cast<int>(socket(AF_INET, SOCK_DGRAM, 0));

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(0);

    struct sockaddr_in clientAddr;
    memset(&clientAddr, 0, sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(8080);

    inet_pton(AF_INET, "", &serverAddr.sin_addr);
    inet_pton(AF_INET, "8.8.8.8", &clientAddr.sin_addr);

    std::string message = "Hello, server!";
    bind(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    sendto(
        sock,
        message.c_str(),
        static_cast<int>(message.length()),
        0,
        (struct sockaddr *)&clientAddr,
        sizeof(clientAddr));

#ifdef _WIN32
    WSACleanup();
#endif
#ifndef _WIN32
    close(sock);
#endif
    return 0;
}