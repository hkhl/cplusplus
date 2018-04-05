/*************************************************************************
	> File Name: input.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月30日 星期五 21时44分11秒
 ************************************************************************/

#include <iostream>
#include <string>


int main()
{
    std::cout << "Please enter your first name: ";

    std::string name;        //默认初始化为空string
    std::cout << "\"" << name << "\"" << std::endl;
    std::cin >> name;

    std::cout << "Hello, " << name << "!" << std::endl;

    return 0;
}
