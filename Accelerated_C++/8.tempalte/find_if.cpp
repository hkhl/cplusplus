#include <iostream>
#include <vector>

using namespace std;

int handle(int num)
{
    if (num > 4) {
        return 1;
    }
    else {
        return 0;
    }
}

template <class In, class Predict>
In find_if(In begin, In end, const Predict p)
{
    /*
     *while (begin != end && p(*begin))
     *    ++begin;
     *return begin;
     */

    if (begin == end || p(*begin))
        return begin;
    begin++;
    return find_if(begin, end, p);

}

int main(int argc, char *argv[])
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(7);



    //find_if 找到第一个满足谓词的元素
    cout << *(find_if(v.begin(), v.end(), handle)) << endl;

    return 0;
}
