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

/*
 *int i(3);
 *int j = int(3);
 *int *p = new int(3);
 *int[] arr = new int[] {1, 2, 3};
 */

/*
 *定义基本数据类型变量（单个值、数组）的同时可以指定初始值，如果未指定C++会去执行默认初始化(default-initialization)。 那么什么是”默认初始化”呢？
 *栈中的变量（函数体中的自动变量）和堆中的变量（动态内存）会保有不确定的值；
 *全局变量和静态变量（包括局部静态变量）会初始化为零。
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

