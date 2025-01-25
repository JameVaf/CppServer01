#include <winsock2.h>
#include <windows.h>



int main()
{
#ifdef _WIN32
    WORD ver = MAKEWORD(2, 2);
    WSADATA dat;
    WSAStartup(ver, &dat);
    
#elif __unix__

#endif


#ifdef _WIN32
    WSACleanup();
#elif __unix__

#endif
    return 0;
}