#include <iostream>
#include <vector>
using namespace std;

template <class In, class X>
X accumulate(In begin, In end, X x)
{
    X sum = x;
    while (begin != end)
    {
        sum += *begin;
        begin++;
    }
    return sum;
}

int main()
{

    vector<double> v;
    v.push_back(1.1);
    v.push_back(1.1);
    v.push_back(1.1);
    v.push_back(1.1);
    v.push_back(1.1);

    //从1.1 开始求和   答案6.6
    double sum = accumulate(v.begin(), v.end(), 1.1);

    cout << sum << endl;

    return 0;
}
