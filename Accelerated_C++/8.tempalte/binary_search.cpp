#include <iostream>
#include <vector>
using namespace std;


template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end)
    {
        //找找区间中点
        Ran mid = begin + (end - begin) / 2;

        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        else
            return true;
    }
    return false;
}


int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(9);

    bool s = binary_search(v.begin(), v.end(), 0);
    cout << s << endl;

    return 0;
}


