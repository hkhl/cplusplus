#include <iostream>
using namespace std;

//reverse 反转顺序
template <class B>
void reverse(B begin, B end)
{
    while (begin != end)
    {
        --end;
        if (begin != end)
            swap(*begin++, *end);
    }
}

int main()
{
    string str = "aba ca a";

    reverse(str.begin(), str.end());

    cout << str << endl;
    return 0;
}
