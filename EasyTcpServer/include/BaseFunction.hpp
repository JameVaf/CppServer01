#ifndef __ERROR_MESSAGE_HPP__
#define __ERROR_MESSAGE_HPP__
#include <iostream>
#include <string>

// 显示错误消息
void error_message(const std::string& message)
{
    std::cout << "error is : " << message << std::endl;
}


#endif //__ERROR_MESSAGE_HPP__