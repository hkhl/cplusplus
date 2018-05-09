#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

//remove == remove_if        "删除" 满足条件的元素
    //将满足条件的"删除"掉. 将后续的数字放在前面被删除的位置  不改变容器大小


template <class In, class X>
In remove(In begin, In end, X x)
{
    In first_fail = begin;
    while (begin != end)
    {
        if (*begin != x)
            *first_fail++ = *begin;
        begin++;
    }
    return first_fail;
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
    v.push_back(3);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(4);

    //1 4 9 1 3 0 0 0 4 4
    //1 4 9 1 0 0 0 4 4 4
    remove(v.begin(), v.end(), 3);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}
