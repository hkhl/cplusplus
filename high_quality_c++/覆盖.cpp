/*************************************************************************
	> File Name: 覆盖.cpp
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月06日 星期五 15时10分56秒
 ************************************************************************/
#include <iostream>
using namespace std;

class Base
{
public:
    void s(){cout << "base :: s" << endl;} //父类独有某个函数

    /*单继承的情况下:
    //父类和父子类都virtual 效果一样
    //仅仅子类virutal 相当于没有加virtual
    */

    virtual void g(int x){cout << "base :: g" << endl;} //父类virtual
    void h(int x){cout << "base :: h" << endl;}         //子类virtual
    virtual void v(int x){cout << "base :: v" << endl;} //父子类都virtual


    /*隐藏*/
    //1. 父子类同样的函数名, 但是参数不一样, 父类被隐藏.(与virtual无关)
    //2. 父子类同名同参函数, 但是父类没有virtual, 父类被隐藏
    //对于第二条 例如函数 f() 和 h()
    void hide(int x){cout << "base  hide" << endl;}
    void f(int x){cout << "base :: f" << endl;}

};

class Drived : public Base
{
public:

    void g(int x){cout << "drived :: f" << endl;}
    virtual void h(int x){cout << "drived :: f" << endl;}
    virtual void v(int x){cout << "drived :: v" << endl;}


    /*隐藏*/
    void hide(int x, int y){cout << "drive hide  " << endl;}
    void f(int x){cout << "drived :: f" << endl;} 
};


int main()
{
    Base *pb;
    Drived *pd;
    Drived d;

    //覆盖: 同名同参+父类加上virtual 基类的函数被子类覆盖掉
    //隐藏: 同名同参无(基类)virtual   同名不同参(virtual随意)

    //结果:  
    //重载看参数  
    //覆盖看实体对象类型
    //隐藏看指针类型
    pb = &d;
    pd = &d;

    pb->f(1);        //1. base   同名同参无virtual) 看指针
    pb->h(1);        //2. base   同上(基类无virtual) 
    pb->g(1);        //3. drive  覆盖 同名同参基类有virtual 看实体 
    pb->v(1);        //4. drive  同上
    pb->hide(1);     //5. base   同名不同参, 看指针

    pd->f(1);        // drive 隐藏  理由同1 看指针 是drive
    pd->h(1);        // drice 隐藏  同2
    pd->g(1);        // drive 同3   看实体
    pd->v(1);        // drive 同4
    pd->hide(1,1);   // drive 同5

    return 0;
}

int main6()
{
    Base b;
    Drived *p;
    //p = &b;       //报错, 子类指针怎么可以越俎代庖
    return 0;
}

int main11()
{
    Drived d;
    //自己调用自己当然都是drive咯
    d.s();       //ok   base  子类成员可以调用父类独有的函数名
    d.f(1);      // drive
    d.g(1);      // drive  
    d.h(1);      // drive  
    d.v(1);      // drive
    d.hide(1, 1);// drive
    //d.hide(1);  //error  调用格式正确 但是父类被隐藏无法调用

    /*同上 全是base*/
    Base b;
    b.f(1);
    b.g(1);
    b.h(1);
    b.v(1);
    b.hide(1);

    return 0;
}

