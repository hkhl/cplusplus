/*************************************************************************
	> File Name: insert.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月28日 星期六 19时33分25秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> a1, a2;

    a2.push_back(1);
    a2.push_back(2);
    a2.push_back(3);
    a2.push_back(4);
    a2.push_back(7);
    a2.push_back(6);
    a2.push_back(7);
    a2.push_back(6);
    a2.push_back(6);
    a2.push_back(6);
    a2.push_back(6);

    //a1.insert(a1.end(), a2.begin(), a2.end());
    copy(a2.begin(), a2.end(), back_inserter(a1));
    //copy(a2.begin(), a2.end(), a1.end()); 段错误

    for(auto a : a1)
    {
        cout << a << endl;
    }

    return 0;
}
