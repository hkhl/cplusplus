#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
T maxx(const T& left, const T& right)
{
    return left > right ? left : right;
}


int main(int argc, char *argv[])
{
    //当传入的是一个int类型和一个double类型, 编译将产生错误
    //无法确定转换那一种类型
    cout <<  max(4.4, 3) << endl;


    return 0;
}
