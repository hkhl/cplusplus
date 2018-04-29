#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(int argc, char const* argv[])
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


    //删除0
    remove_copy(v.begin(), v.end(), back_inserter(newv), 0);

    for (int i = 0; i < newv.size(); i++) {
        cout << newv[i] << " ";
    }

    std::cout << std::endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
