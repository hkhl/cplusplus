/*************************************************************************
	> File Name: 1.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 20时42分41秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int arr[10]={0};
    int (&ac)[10]=arr;
    ac[0] = 1;
    cout << arr[0] << endl;
}
