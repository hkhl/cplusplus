#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//将[beg, end]范围内的x全部替换为y
template <class For, class X>
void replac(For beg, For end, const X& x, const X& y)
{
    while (beg != end)
    {
        if (*beg == x)
            *beg = y;
        ++beg;
    }
}

int main()
{
    string str = "aba ca a";

    replac(str.begin(), str.end(), 'a', 'c');

    cout << str << endl;
    return 0;
}
