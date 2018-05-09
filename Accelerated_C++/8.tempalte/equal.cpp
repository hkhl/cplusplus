#include <iostream>
#include <algorithm>

using namespace std;


template <class A>
bool myequal(A begin, A end, A bbegin)
{
    while (begin != end)
    {
        if (*begin++ != *bbegin++)
            return false;
    }
    return true;
}

int main()
{
    string str1 = "s";
    string str2 = "as";

    cout << equal(str1.begin(), str1.end(), str2.begin());

    return 0;
}
