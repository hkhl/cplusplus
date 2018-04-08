/*************************************************************************
	> File Name: 3-3_count_word.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月03日 星期二 23时28分59秒
 ************************************************************************/
/* 统计输入单词的次数 */
#include <iostream>
#include <algorithm>
#include <map>
//g++ -std=c++11 dijkstra.cpp -o dijkstra

using namespace std;

//统计每个单词出现的个数
int main()
{    

    map<string, int> word_count;
    map<string, int>::iterator iter;
    map<string, int>::iterator begin = word_count.begin();
    map<string, int>::iterator end = word_count.end();

    string word;

    while(cin >> word)
    {
        ++word_count[word];
    }


    /*
    for(iter = begin; iter != end; iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
*/
    /*
    for(iter = word_count.begin(); iter != word_count.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    */

    
    for(const auto & wr : word_count)
    {
        cout << wr.first << " " << wr.second << endl;
    }

    /*
    string str = "ascdefg";
    for(const auto & ch : str)
    {
        cout << ch <<endl;
    }*/

    return 0;
}
