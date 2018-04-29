#include <iostream>
#include <algorithm>

using namespace std;

//find   find_if    search

int handle(int num)
{
    if (num > 4) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(7);

    vector<int>::iterator it = v.begin();

    //find 查找失败返回 end()
    cout << *(find(v.begin(), v.end(), 9)) << endl;
    cout << *(v.end()-1) << endl;


    //find_if 找到第一个满足谓词的元素
    cout << *find_if(v.begin(), v.end(), handle) << endl;


    vector<int> vserc;
    vserc.push_back(5);
    vserc.push_back(7);

    //search  找到元素存在于vsearch中的元素
    cout << *search(v.begin(), v.end(), vserc.begin(), vserc.end()) << endl;
    return 0;
}
