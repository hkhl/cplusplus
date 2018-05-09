#include <iostream>
#include <vector>
using namespace std;


template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    end = end-1;
    //while (begin < end)    //与初始化对称, 不可以用<=  如果用<= 当vector, 段错误
    while (begin != end)
    {
        //找找区间中点
        Ran mid = begin + (end - begin) / 2;  //防止溢出

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

    bool s = binary_search(v.begin(), v.end(), 1);
    cout << s << endl;
    s = binary_search(v.begin(), v.end(), 3);
    cout << s << endl;
    s = binary_search(v.begin(), v.end(), 5);
    cout << s << endl;

    s = binary_search(v.begin(), v.end(), 9);
    cout << s << endl;
    return 0;
}
