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

    //socket
    SOCKET serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(-1 == serverSock)
    {
        error_message("socket() failed,套接字创建失败");
    }
    else
    {
        std::cout << "socket() success, 创建套接字成功!" << std::endl;
    }

    //bind
    struct sockaddr_in serverAddr = {};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT_);
    serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;
    ret = bind(serverSock,(sockaddr*)&serverAddr,sizeof(serverAddr) );
    if( -1 == ret)
    {
        error_message("bind() failed,服务器绑定套接字失败");
    }
    else
    {
        std::cout << "bind() success, 绑定套接字成功" << std::endl;
    }

    //listen
    ret = listen(serverSock, 5);
    if( -1 == ret)
    {
        error_message("listen() failed,监听服务器套接字失败");
    }
    else
    {
        std::cout << "listen() success,监听成功" << std::endl;
    }
    //accept
    sockaddr_in clientAddr = {};
    int addrLen = sizeof(clientAddr);

    SOCKET clientSock = accept(serverSock, (sockaddr *)&clientAddr, (int*)&addrLen);
    if(-1 == clientSock)
    {
        error_message("accept() failed,接受失败");
    }
    else
    {
        std::cout << "accept() success,成功接受到一个套接字" << std::endl;
        
    }
    char buff[1024] = "hello client,i'am server";
    send(clientSock, buff, strlen(buff) + 1, 0);
#ifdef _WIN32
    closesocket(serverSock);
    closesocket(clientSock);
    WSACleanup();
#elif __unix__

#endif


    return 0;
}