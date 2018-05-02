#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



template <class In, class Out>
Out copyy(In begin, In end, Out dest)
{
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

int main(int argc, char *argv[])
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(6);
    v.push_back(3);

    vector<int> sc;

    copyy(v.begin(), v.end(), back_inserter(sc));


    for (vector<int> ::size_type i = 0; i < sc.size(); i++)
    {
            cout << sc[i] << " ";
    }
    return 0;
}
