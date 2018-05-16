#include <iostream>

using namespace std;
int g_var;
int *g_pointer;
static int g_static;

int main(){
    int l_var;
    int *l_pointer;
    static int l_static;

    cout<<g_var<<endl<<g_pointer<<endl<<g_static<<endl;
    cout<<l_var<<endl<<l_pointer<<endl<<l_static<<endl;
/*
 *0                   // 全局变量
 *0x0                 // 全局指针
 *0                   // 全局静态变量
 *32767               // 局部变量
 *0x7fff510cfa68      // 局部指针
 *0                   // 局部静态变量
 */
};

/*  c++style
 *int i(3);
 *int j = int(3);
 *int *p = new int(3);
 *int[] arr = new int[] {1, 2, 3};
 */

//所以函数体中的变量定义是这样的规则：

int i;                    // 不确定值
int j = int();            // 0
int *p = new int;         // 不确定值
int *q = new int();       // 0


/*
 *未初始化的和初始化为零的静态/全局变量编译器是同样对待的，
 *把它们存储在进程的BSS段（这是全零的一段内存空间）中。
 *所以它们会被”默认初始化”为零。
 */



//类的默认构造函数正确初始化方式
class A{
public:
   int v;
   A(): v(0);
};






//关于new的初始化问题
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
     1.   栈中的变量（函数体中的自动变量）和堆中的变量（动态内存）会保有不确定的值；
     2.   全局变量和静态变量（包括局部静态变量）会初始化为零。
