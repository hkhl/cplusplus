/*************************************************************************
	> File Name: streamsize_setprecision.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月03日 星期二 21时02分55秒
 ************************************************************************/

#include <iostream>
#include <ios>
//#include <iomainip>  //设置位数, 头文件错误? ...
using namespace std;


int main()
{

    streamsize prec = cout.precision();

    double x = 12.555;

    cout << x << endl;

    //cout << setprecision(3) << 123123.54645 << endl;
    //cout << setprecision(3) << "123123"
    return 0;
}
