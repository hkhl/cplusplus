/*************************************************************************
	> File Name: 3-4max_min_len.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月04日 星期三 00时14分29秒
 ************************************************************************/

/*计算最长最短单词的长度*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
    int maxlen, minlen;
    string str;
    vector<string> vs;

    while(cin >> str)
    {
        vs.push_back(str);
    }

    vector<string>::size_type size = vs.size();

    maxlen = minlen =  vs[0].size();

    for(int i = 0; i < size; i++)
    {
        if(vs[i].size() > maxlen)
        {
            maxlen = vs[i].size();
        }
        if(vs[i].size() < minlen)
        {
            minlen = vs[i].size();
        }
    }
    cout << maxlen << endl << minlen << endl;
    
    return 0;
}
