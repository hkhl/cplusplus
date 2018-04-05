/*************************************************************************
	> File Name: assign.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月05日 星期四 13时45分58秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
    
int main()
{

    string s = "qwerey";
    string str = "123456";

    s.assign(s, 1, 3);   //wer
    cout << s << endl;

    s.assign(str, 2, string::npos); //3456
    cout << s << endl;

    s.assign("nico", 5);  //n i c o \0
    cout << s << endl;

    s.assign(5, 'd'); //x x x x x
    cout << s << endl;
    return 0;
}
