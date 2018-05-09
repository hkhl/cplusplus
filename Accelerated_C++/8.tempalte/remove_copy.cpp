#include <iostream>
#include <vector>
using namespace std;

template <class In, class Out, class X>
Out remove_copy(In begin, In end, Out dest, X x)
{
    while (begin != end)
    {
        if(*begin != x)
            *dest++ =*begin;
        begin++;
    }
    return dest;
}

int main()
{

    vector<int> v;
    vector<int> newv;

    v.push_back(3);
    v.push_back(1);
    v.push_back(-4);
    v.push_back(9);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(3);
    v.push_back(0);
    v.push_back(4);

    remove_copy(v.begin(), v.end(), back_inserter(newv), 3);

    for (int i = 0; i < newv.size(); i++) {
        cout << newv[i] << " ";
    }

    return 0;
}
