/*************************************************************************
	> File Name: sizeof.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月05日 星期四 13时31分33秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string strs = "hello111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";

    cout << sizeof(string) << endl;  //32
    cout << sizeof(strs) << endl;    //32
    cout << sizeof("hello") << endl; //6
    
    //sizeof 是string类的大小
    return 0;
}
