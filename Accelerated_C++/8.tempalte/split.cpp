
/*字符串分割函数模板*/
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

template <class Out>
void split(const string &str, Out os)
{
    typedef string::const_iterator iter;

    iter i = str.begin();

    while(i != str.end())
    {
        i = find_if(i, str.end(), not_space);  //找到第一个不为空的位置

        iter j = find_if(i, str.end(), space); //找到字符串的结尾

        if(i != str.end())
        {
            *os++ = string(i, j);
        }
        i = j;
    }
}

int main()
{
    string str;
    vector<string> ss;
    getline(cin, str);

    split(str, back_inserter(ss));

    for(int i = 0; i < ss.size(); i++)
    {
        cout << ss[i] << endl;
    }

    return 0;
}

