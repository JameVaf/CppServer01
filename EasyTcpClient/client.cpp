#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <string>
#include "include/BaseFunction.hpp"
#include "include/BaseSetting.hpp"

int main()
{
#ifdef _WIN32
    WORD ver = MAKEWORD(2, 2);
    WSADATA dat;
    WSAStartup(ver, &dat);

#elif __unix__

#endif

    // socket
    SOCKET Sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (-1 == Sock)
    {
        error_message("socket() failed,套接字创建失败");
    }
    else
    {
        std::cout << "socket() success, 创建套接字成功!" << std::endl;
    }

    //connect
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(SERVER_PORT_);
    ret = connect(Sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if(-1 == ret)
    {
        error_message("connect() failed,连接服务器失败");
    }
    else{
        std::cout << "connect() success,连接服务器成功";
    }
    char buff[1024] = {0};
    recv(Sock, buff, 1024, 0);
    std::cout << buff << std::endl;

#ifdef _WIN32
    closesocket(Sock);
    WSACleanup();
#elif __unix__

#endif

    return 0;
}