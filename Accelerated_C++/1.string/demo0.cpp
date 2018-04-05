/*************************************************************************
	> File Name: demo.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月30日 星期五 22时29分19秒
 ************************************************************************/

#include <iostream>
#include <string>


int main()
{
    {
        const std::string s = "a string";
        std::cout << s << std::endl;
        {
            const std::string s = "anoth";
            std::cout << s << std::endl;
        }//;
    }
}

