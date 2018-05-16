#include <iostream>
#include <vector>

//重载
using namespace std;


class test
{
int v;
public:
    test():v(0){}
    test(const int &a):v(a){}
    test(const test &t):v(t.v){}

    bool operator < (const test &t) const
    {
        return v < t.v;
    }

    //重载加号
    test operator +(const int & a)  //对象+int
    {
        test t;
        t.v = v + a;
        return t;
    }
    test operator +(const test & a)   //对象+对象
    {
        test t;
        t.v = v + a.v;
        return t;
    }
    /*
     *test& operator +(const int & a)
     *{
     *    this->v = this->v + a;
     *    return *this;
     *}
     */

    //重载==
    bool operator == (const test &t) const
    {
        return v == t.v;
    }

    //重载输入 >>  和  输出 <<
    friend inline ostream & operator << (ostream &os, test &t)
    {
        cout << "cass t(" << t.v << ")" << endl;
        return os;
    }

    friend inline istream & operator >> (istream &in, test &t)
    {
        cin >> t.v;
        return in;
    }

    //重载赋值号
    test& operator = (const test &t)
    {
        v = t.v;
        return *this;
    }
    void print()
    {
        cout << v << endl;
    }

};

int main()
{
    test s(5);
    s = s + 3;

    cin >> s;
    cout << s;
    s.print();
    return 0;
}
