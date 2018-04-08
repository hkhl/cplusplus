/*************************************************************************
	> File Name: 4-7.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 20时38分54秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec(2); 
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    /* 2+4个空间大小,  前两个均为0 a[0] = a[1] = 0 a[2] = 1 */
    cout << vec.size() <<"   " << vec[0] << vec[1] << vec[2] <<  endl;
    return 0;
}
