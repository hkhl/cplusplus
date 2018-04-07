/*************************************************************************
	> File Name: 缺省.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月06日 星期五 18时17分45秒
 ************************************************************************/

#include <iostream>
using namespace std;

void Foo(int x = 0, int y = 0); //yse 声明缺省
void Foo1(int x = 0, int y=0)   //yse 直接定义缺省
{
    y = 3;
}
void Foo2(int x, int y = 0);
//void Foo3(int x = 0, int y);  //no  从右向左
//void Foo3(int a = 0, int x, int y = 0);  //no  从右向左

int main1()
{
}
/*void Foo(int x = 0, int y = 0)   //声明缺省过了 ,再定义缺省 报错
{
}*/



//////////////////////////////////////////////////////////
//不合理的缺省导致二义性

void outpuf(int x);
void output(int x, float y = 0.0);

void output(int x)
{
    cout << "out put int" << x << endl;
}

void output(int x, float y)
{
    cout << "out put int" << x << "and float" << y << endl;
}

int main(void)
{
    int x = 1;
    float y = 1.1;
    //output(x);   //no  不知道调用哪一个函数
    output(x, y);  //yse
    
}
