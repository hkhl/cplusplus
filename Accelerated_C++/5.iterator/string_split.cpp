/*************************************************************************
	> File Name: string.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 22时59分29秒
 ************************************************************************/

/*用getline读入一行赋值给将一个string 这个sring以空格分割若干分, 放在vecrot<string> 中*/
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<string> split_a(const string &s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while(i != s.size())
    {
        //忽略前端空白
        while(i != s.size() && isspace(s[i]))
            ++i;

        //找出下一个单词终结点
        string_size j = i;
        while(j != s.size() && !isspace(s[j]))
            ++j;

        //如果找到了一些非空白字符
        if(i != j)
        {
            //从i开始赋值s的j-i个字符
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}


int main()
{
    string str;
    //getline 读入一行  str也接收一行
    while(getline(cin, str))
    {
        vector<string> v = split_a(str);

        for(vector<string>::size_type i = 0; i != v.size(); i++)
        {
            cout << "\"" << v[i] << "\"" << endl;
        }
    }

    return 0;
}
