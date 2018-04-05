/*************************************************************************
	> File Name: valid.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月30日 星期五 22时21分51秒
 ************************************************************************/

#include <iostream>

int main()
{
    const std::string hello = "Hello";
    const std::string message0 = hello + ", world" + "!";
    const std::string message1 = hello + hello + ", world" + "!";
    const std::string message2 = hello + ", world" + "!" + "123";
    const std::string message3 = "hao a u" + hello + ", world" + "!";
    //const std::string message4 = "asdas" + "asdasd"; //error
    


    const std::string exclam = "!";
    //const std::string message = "hello" + ", world" + exclam; //同上error



    {
        const std::string s = "a string";
        std::cout << s <<std::endl;
    }

    {
        const std::string s = "another string";
        std::cout << s << std::endl;
    }
    return 0;
}
