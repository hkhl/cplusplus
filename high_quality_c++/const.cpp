/*************************************************************************
	> File Name: const.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月07日 星期六 09时34分28秒
 ************************************************************************/
/*
 * c++const 是真正的const, 不会被指针变量所改变
 * 而c语言可以 类似
 * const int a = 3;
 * int *p = (int *)&a;
 * *p = 5;
 * 打印会发现 *p = a = 5;
 *
 * 然而c++   *p=5  a还是等于3
 * 因为c++ const值记录在符号标,是真正的常量,
 * a的值不会发生改变
 *
 * 下面讲讲c++区别于c的const
*/

#include <iostream>
using namespace std;


class A
{
public:
    A(){cout << "construct" << endl;}
    A(const A &a){cout << "copy construct" << endl;}
    const A& operator=(const A &a){cout << "fuzhi=" << endl;}
    ~A(){cout << "~A" << endl;}
    
    
    /*const 引用*/
    //void test(const int &x); //写成这样提高效率?
    //完全没必要,写成下面这样就好,
    //虽然说是传引用, 但是int这种内部数据类型不存在构造析构过程,
    //复制也非常快, "值传递" 和 "引用传递"效率几乎一样
    void test(int x);        //goot
    void testA(A a);         //not good
    void testB(const A &a);  //good
};







void A::test(int x){}
void A::testA(A a){}
void A::testB(const A &a){}


/**************** 关于const 引用传值 传对象的问题****************/
int main2()
{
    A a;
    int x = 3;

    /*分别取消注释其中某一行代码看运行结果*/
    a.test(x);     //1次构咋, 1次析构
    //a.testA(a);    //1次构造, 1次拷贝构造, 两次析构 
    //a.testB(a);    //1次构造, 1次析构

    /*所以对与内部数据类型不需要const int &x
    * 对于对象,则最号传引用 const A &a 效率高
    */
    return 0;
}


/*************************const 返回值*************************/

/*虽然用了const  但是然并卵, 返回值是一份拷贝
const没有起到任何效果
同理不要把 A GetA(void)  写成 const A GetA(void) A为某个数据类型*/
const int funA(void)
{
    return 3;
}

/*返回指针用const, 表示指针的内容不能修改
只能用const 类型指针来接收返回值*/
const int * funp(void)
{
    return NULL;
}

int main1()
{
    int a = funA();         //ok  but not good
    const int b= funA();    //ok  but not good

    //int *pa = funp();     //bad  把const类型赋值给非const类型是不ok的
    const int *pb = funp();

    /*下面这个例子, 我们需要看赋值重载函数是否在const */
    //const A& operator=(const A &a){cout << "fuzhi=" << endl;}
    //没加const 下面两句都ok, 加了const (x = y) = z 不ok
    A x, y, z;
    x = y = z;
    //(x = y) = z;  //想一想为什么?
}


class B
{
public:
    /* const 成员函数 */
    int funA()
    {
        a = 3;      //ok
        //非const成员函数可以调用const成员函数
        cfunA();
        cfunB();
    }

    int cfunB()const {}
    int cfunA() const
    {
        //a = 3;   // bad  const成员函数不能修改数据成员
        //SIZE = 3;// bad  当然不ok  SIZE是const类型 不论哪里都不能变
        //funA();  // bad  不能调用非const成员函数
        cfunB();   // ok  调用的是const成员函数
    }
    B(int size):SIZE(size){}
private:
    int a;
    /*const 成员变量 
    *在类中声明变量为const类型，但是不可以初始化
    const常量的初始化必须在构造函数初始化列表中初始化，
    而不可以在构造函数函数体内初始化*/
    const int SIZE; 
};
/*                 const成员函数                    */
int main()
{
    //任何不会修改数据成员的函数都应该声明为const类型
    //如果const成员函数不慎修改了数据成员, 调用了其他非const成员函数
    //编译器将指出错误

    B b(1);
    b.cfunA();
    return 0;
}
