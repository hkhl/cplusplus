#include <iostream>
#include <vector>
using namespace std;

bool is3(int x)
{
    if(x == 3)
        return true;
    return false;
}

template <class In, class Out, class Predicate>
Out remove_copy_if(In begin, In end, Out dest, Predicate p)
{
    while (begin != end)
    {
        if(!p(*begin))
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

    remove_copy_if(v.begin(), v.end(), back_inserter(newv), is3);

    for (int i = 0; i < newv.size(); i++) {
        cout << newv[i] << " ";
    }

    return 0;
}
