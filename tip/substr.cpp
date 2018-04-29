/*************************************************************************
	> File Name: substr.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月28日 星期六 19时29分57秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


int main()
{


    //提取子串
    string str = "abcdef";

    string chr = str.substr(1, 4);

    cout << chr << endl;
    //bede

    return 0;
}
