/*************************************************************************
	> File Name: 重载.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月06日 星期五 14时44分33秒
 ************************************************************************/
 /*只能通过参数类型重载, 不能通过函数返回值重载*/

#include <iostream>
using namespace std;
/*
int fun(int a)
{
    cout << "int" << endl;
}

void fun(int a)
{
    cout << "void" << endl;
}

int i = fun(3);
fun(3);
这样调用可以区分


假设调用者不关心返回值
fun(3);
那么究竟调用哪一个呢?

c++实现函数签名形式是  "函数名+参数类型"
所以不支持根据返回值重载

*/
/*
void Print(int a, int b)
{
    cout << "g _ print" << endl;
}
class A
{
public:
    void Print(int a)
    {
        cout << "A::print" << endl;
    }

    void test()
    {
        Print(1);
        //想调用全局print 必须加::
        //Print(1,2);  error
        ::Print(1, 2);
    }
};

int main()
{

    A a;
    a.test();

    A a;
    a.Print(3);  //调用A::Print 
    Print(3);    //调用全局print
    ::Print(2);  //调用全局print

    return 0;
}*/



void output(int x)
{
    cout << "int out" << endl;
}

void output(float x)
{
    cout << "float out" << endl;
}
int main()
{

    int x = 1;
    float y = 1.0;

    output(x); //int
    output(y); // float
    output(1); // int
    //output(0.5);      //产生二义性, 编译出错 会隐式类型转化
    return 0;
}
