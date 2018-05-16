#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int *q = new int[10];   //只申请空间不初始化  相当于malloc
    int *p = new int[10](); //初始化为0


    for (int i = 0 ; i < 10; i++)
    {
        cout << p[0] << endl;
    }

    delete []q;
    delete []p;

    return 0;

}
对于内置数据类型元素的数组，必须使用()来显示指定程序执行初始化操作，否则程序不执行初始化操作：
int *pia = new int[10]; // 每个元素都没有初始化
int *pia2 = new int[10] ();  // 每个元素初始化为0


类类型元素的数组，则无论是否使用（），都会自动调用其默认构造函数来初始化：
string *psa = new string[10];  // 每个元素调用默认构造函数初始化
string *psa = new string[10]();  // 每个元素调用默认构造函数初始化


定义基本数据类型变量（单个值、数组）的同时可以指定初始值，如果未指定C++会去执行默认初始化(default-initialization)。 那么什么是”默认初始化”呢？
        栈中的变量（函数体中的自动变量）和堆中的变量（动态内存）会保有不确定的值；
        全局变量和静态变量（包括局部静态变量）会初始化为零。
