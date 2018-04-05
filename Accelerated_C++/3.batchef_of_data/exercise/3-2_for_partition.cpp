/*************************************************************************
	> File Name: 3-2_for_partition.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月03日 星期二 22时15分33秒
 ************************************************************************/
/*
 *把一个整数集合分为个数相等的4部分,第一部分含有的整数比其他个部分都大,
 *第二部分的值比剩下两部分大,以此类推
 *
 *编写程序, 并打印上述4部分
 * */
#include <iostream>
#include <algorithm>
#include <vector>
#define N 12
using namespace std;

int main()
{
    int x = 0;
    vector<int>v1;

    for(int i = 0; i < N; i++)
    {
        cin >> x;
        v1.push_back(x);
    }

    vector<int>::size_type size = v1.size();

    sort(v1.begin(), v1.end());
    for(int i = size-1; i >= 0; i--)
    {
        cout << v1[i] << " ";
        if((i) % 3 == 0)
            cout << endl;
    }

    return 0;
}


