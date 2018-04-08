/*************************************************************************
	> File Name: 4-2.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月07日 星期六 21时15分19秒
 ************************************************************************/

/*1-100平方*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    vector<int> vec;
    vector<int> vec2;
    int max = 999;
    for(int i = 0; i < max; i++)
    {
        cout << i+1 << setw(max/100) <<(i+1)*(i+1) << endl;;
    }
    
    return 0;
}
