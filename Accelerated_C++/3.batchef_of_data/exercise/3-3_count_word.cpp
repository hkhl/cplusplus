/*************************************************************************
	> File Name: 3-3_count_word.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月03日 星期二 23时28分59秒
 ************************************************************************/
/* 统计输入单词的次数 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*两个vector
* 或者map??*/
int main()
{    
    string str;
    vector<string> vs;
    vector<int> count;

    while(cin >> str)
    {
        vs.push_back(str);
    }

    vector<string>::size_type size = vs.size();

    for(int i = 0; i < size; i++)
    {
        
    }



    return 0;
}
