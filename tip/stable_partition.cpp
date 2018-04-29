#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//partition  根据谓词来划分区域
//stable 保持相对位置不变

int isnotzero(int num)
{
    if (num == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int main(int argc, char const* argv[])
{
    vector<int> v;
    vector<int> newv;

    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(-4);
    v.push_back(9);
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(0);
    v.push_back(4);


    //remove_copy(v.begin(), v.end(), back_inserter(newv), 0);

    //将满足谓词条件的都放在前面, 不满足的放在后面
    //stablepartition 保持相对位置不变
    stable_partition(v.begin(), v.end(), isnotzero);

    //partiton 不保持相对位置不变, 仅仅是划分为两个区域
    partition(v.begin(), v.end(), isnotzero);



    //partiton 返回值是位于第二个区域的第一个元素的迭代器
    for (vector<int>::iterator it = partition(v.begin(), v.end(), isnotzero); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    std::cout << std::endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
