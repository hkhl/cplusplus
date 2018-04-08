/*************************************************************************
	> File Name: 4-5.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 11时18分25秒
 ************************************************************************/

/*编写函数从输入流读单词, 读到单词写入向量中, 理容这个函数编写程序类统计单词数目以及每一个单词出现的次数*/
#include <iostream>
#include <map>
using namespace std;


istream& read(istream &in, map<string, int> &word_count)
{
    if(in)
    {
        string str;
        while(in >> str)
        {
            ++word_count[str];
            in.clear();
        }
    }
    return in;
}

int main()
{
    map<string, int> word_count;
    string str;
    map<string, int>::iterator iter;



    read(cin, word_count);

    cout << "total : " << word_count.size() << endl;

    for(iter = word_count.begin(); iter != word_count.end(); iter++)
    {
        cout << iter->first << " " << iter->second <<endl;
    }




    return 0;
}

