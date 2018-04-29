#include <iostream>
#include <sstream>
#include <string>
using namespace std;


//重点用到stringstream但是处理大量数据速度慢
//还可以用 sprintf sscanf

//字符转数字函数
int str2num(string s)
{
    int num;
    /*
     *stringstream ss;
     *ss << s;
     */

    stringstream ss(s);
    ss >> num;
    return num;
}


//数字转字符函数
string num2str(int num)
{
    stringstream ss;
    ss << num;

    return ss.str();
}



int main()
{
    string str = "123";
    int num = 1234;

    cout << str2num(str) << endl;

    cout << num2str(num) << endl;
}


