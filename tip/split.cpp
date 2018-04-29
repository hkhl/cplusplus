/*************************************************************************
	> File Name: split.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月28日 星期六 20时39分20秒
 ************************************************************************/

/*字符串分割函数*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string &str)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();

    while(i != str.end())
    {
        i = find_if(i, str.end(), not_space);  //找到第一个不为空的位置

        iter j = find_if(i, str.end(), space); //找到字符串的结尾

        if(i != str.end())
        {
            ret.push_back(string(i, j));
        }
        i = j;
    }
    return ret;
}

int main()
{

    string str;
    getline(cin, str);

    vector<string> words = split(str);

    for(int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }


    return 0;
}

