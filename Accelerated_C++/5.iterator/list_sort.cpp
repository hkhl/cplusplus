/*************************************************************************
	> File Name: list_sort.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 22时40分35秒
 ************************************************************************/

#include <iostream>
#include <list>
using namespace std;

//list 不支持索引

bool compare(const string &a, const string &b)
{
    return a < b;
}

int main()
{
    /*
    list<int> ls;
    ls.push_back(5);
    ls.push_back(3);
    ls.push_back(2);
    ls.push_back(1);
    ls.push_back(4);

    //cout << ls[0] << endl;   error

    //list 同 vector 排序不同
    //sort(vector.begin(), vector.end());

    ls.sort();  //排序数字. 不需要参数

    list<int>::iterator iter = ls.begin();
    for(; iter != ls.end(); iter++)
    {
       cout << *iter  << endl;
    }
*/



    list<string> lstring;
    lstring.push_back("dfg34d");
    lstring.push_back("asdasd");
    lstring.push_back("zxcassd");
    lstring.push_back("sdadasd");

    //cout << ls[0] << endl;   error

    //list 同 vector 排序不同
    //sort(vector.begin(), vector.end());

    lstring.sort(compare);  //排序数字. 不需要参数  ??compare 对否
    lstring.sort();    //不需要compare也可以排序

    list<string>::iterator siter = lstring.begin();
    for(; siter != lstring.end(); siter++)
    {
       cout << *siter  << endl;
    }

    return 0;
}
