/*************************************************************************
	> File Name: 4-7.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 20时47分19秒
 ************************************************************************/

/*求vector平均值*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, res = 0;
    vector<int>nums;

    while(cin >> n)
    {
        nums.push_back(n);
    }

    vector<int>::size_type size = nums.size();
    for(int i = 0; i < size; i++)
    {
        res += nums[i];
    }
    cout << res << " " << size << endl; 

    cout << "ave : " << res/size << endl;

    return 0;
}
