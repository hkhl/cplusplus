#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template <class In, class X> In findd(In begin, In end, const X& x)
{
    /*
     *while (begin != end && *begin != x)
     *    ++begin;
     *return begin;
     */

    if (begin == end || *begin == x)
        return begin;
    begin++;
    return find(begin, end, x);

}

int main(int argc, char *argv[])
{
    vector<int> s;
    s.push_back(1);
    s.push_back(3);
    s.push_back(3);
    s.push_back(5);
    s.push_back(6);
    s.push_back(7);

    vector<int>::iterator it;
    cout << *(find(s.begin(), s.end(),3));

    it = findd(s.begin(), s.end(), 5);

    if(it == s.end())
    {
        cout <<  "not find"  << endl;
    }
    else
    {
        cout << *it << endl;
    }




    return 0;
}
