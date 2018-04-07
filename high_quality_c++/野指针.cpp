/*************************************************************************
	> File Name: 野指针.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月06日 星期五 12时44分23秒
 ************************************************************************/

/*          野指针
 * 1. 指针没有被初始化
 * 2. 指针p被free或者delete后没有置为NULL
 * 3. 指针操作超越了变量的作用范围
 */


 //下面针对第三点的练习.
#include <iostream>
using namespace std;

class A
{
public:
    void Func(void);    
};

void A::Func(void)
{
    cout << "Func of class A" << endl;
}


void Test(void)
{
    A *p;
    {
        A a;
        p = &a;
    }
    p->Func(); //讲道理应该出错, a对象已经消失
}

int main()
{
    Test();


    int *p;
    {
        int s = 3;
        p  = &s;
    }
    //cout << s << endl; s已经不存在了
    *p = 10; //讲道理应该出错, 地址非法的
    cout << p << endl;
    cout << *p << endl;

    /*但是编译器不讲道理啊, 编译运行都是对了 */
    return 0;
}
