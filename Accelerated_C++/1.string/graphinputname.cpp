/*************************************************************************
	> File Name: graphinputname.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月30日 星期五 21时57分37秒
 ************************************************************************/

#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your first name: ";

    std::string name;        //默认初始化为空string
    std::cin >> name;

    //构造为门将要输出的信息
    const std::string greeting = "Hello," + name + "!";


    //build the second and fourth lines of the output
    const std::string spaces(greeting.size(), ' ');

    const std::string second = "* " + spaces + " *";

    //构建输出第一和第五行
    const std::string first(second.size(), '*');

    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout <<second << std::endl;
    std::cout << first << std::endl;

    return 0;
}
