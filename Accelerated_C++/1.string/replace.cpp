/*************************************************************************
	> File Name: replace.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月05日 星期四 13时53分42秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


int main()
{
    string s = "7ok77777777";
    s.replace(1,2,"nternationalization");//从索引1开始的2个替换成后面的C_string
    s.erase(13);//从索引13开始往后全删除
    s.erase(7,5);//从索引7开始往后删5个
    cout << s << endl;
    return 0;
}
