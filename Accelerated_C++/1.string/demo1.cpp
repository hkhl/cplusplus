/*************************************************************************
	> File Name: demo1.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月30日 星期五 22时32分30秒
 ************************************************************************/

#include <iostream>
#include <string>

int main()
{
    {//1
        std::string s = "a string";
        {//2
            std::string x = s + ". really";
            std::cout << s << std::endl;
        }//3
        //std::cout << x << std::endl;   //error
    }//4

    //s 变量的作用与 1-4,  而x的作用域仅限2-3
    return 0;
}

