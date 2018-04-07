/*************************************************************************
	> File Name: 1.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月06日 星期五 13时16分44秒
 ************************************************************************/

/*lambda 可以使用这个达到嵌套函数的目的*/
/*g++ 嵌套函数*/
#include <iostream>
using namespace std;

void s()
{
    void x()
    {
        int r = 3;
    }
    x();
}

int main()
{
    void f();
}
